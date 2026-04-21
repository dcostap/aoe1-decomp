from __future__ import annotations

import argparse
import csv
import hashlib
import json
import re
import shutil
import subprocess
import sys
from dataclasses import dataclass
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parents[3]
TOOLS_DIR = REPO_ROOT / "tools"
if str(TOOLS_DIR) not in sys.path:
    sys.path.insert(0, str(TOOLS_DIR))

from coff import load_coff_section, mask_relocations  # noqa: E402
from common import (  # noqa: E402
    ensure_dir,
    format_hex,
    function_by_start,
    function_record_by_va,
    load_binaries,
    load_layout,
    load_pe_image,
    load_toolchain,
    repo_path,
    tool_env,
)
from extract_original_function import decode_bytes  # noqa: E402

TARGET_VA = 0x00446D10
LAB_SLUG = "00446D10_operator"
LAB_ROOT = REPO_ROOT / "build" / "labs" / LAB_SLUG
GENERATED_DIR = LAB_ROOT / "generated"
OBJ_DIR = LAB_ROOT / "obj"
ASM_DIR = LAB_ROOT / "asm"
REPORT_DIR = LAB_ROOT / "reports"
SUMMARY_JSON = REPORT_DIR / "summary.json"
SUMMARY_CSV = REPORT_DIR / "summary.csv"
SUMMARY_MD = REPORT_DIR / "summary.md"

COMMON_CLASS_DECL = """class DString {
public:
    char* stringValue;
    int lengthValue;
    int numWordsValue;
    int indexValue;
    int currentWordValue;

    DString();
    DString(const char* value);
    ~DString();
    char& operator[](int index);
    operator char*() const;
    int length(void) const;
    int numWords(void);
    int index(void) const;
    char* word(int wordIndex);
    char* nextWord(void);
};
"""

FAIL_COND = "index < 0 || this->lengthValue < index + 1"
SUCCESS_COND = "index >= 0 && this->lengthValue >= index + 1"
OFFSET_EXPRESSIONS: dict[str, str] = {
    "fail_ternary": f"({FAIL_COND}) ? 0 : index",
    "success_ternary": f"({SUCCESS_COND}) ? index : 0",
}
FINAL_EXPRESSION_TEMPLATES: dict[str, str] = {
    "array_member": "this->stringValue[{off}]",
    "array_commuted": "({off})[this->stringValue]",
    "ptradd_member": "*(this->stringValue + ({off}))",
    "ptradd_commuted": "*(({off}) + this->stringValue)",
    "ptradd_member_base0": "*(&this->stringValue[0] + ({off}))",
    "ptradd_commuted_base0": "*(({off}) + &this->stringValue[0])",
    "member_indirect_array": "(*(char**)(&this->stringValue))[({off})]",
    "member_indirect_ptradd": "*(*(char**)(&this->stringValue) + ({off}))",
    "member_indirect_ptradd_commuted": "*(({off}) + *(char**)(&this->stringValue))",
}

TARGETED_BASE_CARRIERS: dict[str, tuple[list[str], str]] = {
    "member_base": ([], "this->stringValue"),
    "local_base": (["char* base = this->stringValue;"], "base"),
    "const_base": (["char* const base = this->stringValue;"], "base"),
}
TARGETED_OFFSET_CARRIERS: dict[str, tuple[list[str], str]] = {
    "expr_fail_ternary": ([], f"({FAIL_COND}) ? 0 : index"),
    "local_off_fail_ternary": ([f"int off = ({FAIL_COND}) ? 0 : index;"], "off"),
    "local_off_if_else": ([f"int off;", f"if ({FAIL_COND})", "    off = 0;", "else", "    off = index;"], "off"),
    "local_off_copy_if": (["int off = index;", f"if ({FAIL_COND})", "    off = 0;"], "off"),
    "param_assign_if": ([f"if ({FAIL_COND})", "    index = 0;"], "index"),
}
TARGETED_FINAL_TEMPLATES: dict[str, str] = {
    "array": "{base}[{off}]",
    "array_commuted": "({off})[{base}]",
    "ptradd_member": "*({base} + ({off}))",
    "ptradd_commuted": "*(({off}) + {base})",
    "addrof_array": "*(&{base}[{off}])",
}
WRAPPER_STYLES: dict[str, list[str]] = {
    "direct_return": ["return {expr};"],
    "ref_temp": ["char& result = {expr};", "return result;"],
}


@dataclass(frozen=True)
class Variant:
    name: str
    category: str
    source: str
    note: str


@dataclass(frozen=True)
class OriginalTarget:
    record: dict[str, str]
    bytes: bytes
    asm_text: str


@dataclass(frozen=True)
class VariantResult:
    name: str
    category: str
    note: str
    compile_ok: bool
    source_path: str
    object_path: str | None
    size_bytes: int | None
    first_mismatch: int | None
    family: str
    asm_sha1: str | None
    entry_register: str | None
    has_mov_edx_eax: bool
    has_add_eax_mem: bool
    has_mov_eax_mem_add_eax_edx: bool
    jump_pattern: str | None
    masked_window: str | None
    asm_path: str | None
    stdout: str
    stderr: str


def first_mismatch_offset(left: bytes, right: bytes) -> int | None:
    limit = min(len(left), len(right))
    for index in range(limit):
        if left[index] != right[index]:
            return index
    if len(left) != len(right):
        return limit
    return None


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Compile and cluster many isolated VC5 source variants for 00446D10.")
    parser.add_argument("--variant", help="Regex filter applied to variant names.")
    parser.add_argument("--limit", type=int, help="Compile only the first N filtered variants.")
    parser.add_argument("--clean", action="store_true", help="Delete build/labs/00446D10_operator before running.")
    parser.add_argument("--keep-going", action="store_true", help="Continue after unexpected Python exceptions instead of aborting.")
    return parser.parse_args()


def ensure_lab_dirs(clean: bool) -> None:
    if clean and LAB_ROOT.exists():
        shutil.rmtree(LAB_ROOT)
    for path in (GENERATED_DIR, OBJ_DIR, ASM_DIR, REPORT_DIR):
        ensure_dir(path)


def load_original_target() -> OriginalTarget:
    binaries = load_binaries()
    exe = load_pe_image(repo_path(binaries["original_exe"]))
    layout = load_layout(repo_path(binaries["ghidra_layout"]))
    record = function_record_by_va(TARGET_VA)
    layout_function = function_by_start(layout, TARGET_VA)
    ranges: list[tuple[int, int]] = []
    for body_range in layout_function.get("body_ranges", []):
        start = int(body_range["start"], 16)
        end = int(body_range["end"], 16)
        ranges.append((start, end))
    if not ranges:
        size = int(record["size_bytes"])
        ranges = [(TARGET_VA, TARGET_VA + size - 1)]

    all_bytes = bytearray()
    all_lines: list[str] = []
    for start, end in ranges:
        code_bytes = exe.read_va_range(start, end)
        all_bytes.extend(code_bytes)
        all_lines.append(f"{format_hex(start)}-{format_hex(end)}")
        for line in decode_bytes(code_bytes, start):
            all_lines.append(f"  {line['address']}  {line['bytes']:<16}  {line['text']}")
        all_lines.append("")
    return OriginalTarget(record=record, bytes=bytes(all_bytes), asm_text="\n".join(all_lines).rstrip() + "\n")


def build_expression_matrix() -> list[Variant]:
    variants: list[Variant] = []
    for off_name, off_expr in OFFSET_EXPRESSIONS.items():
        for form_name, expr in FINAL_EXPRESSION_TEMPLATES.items():
            variants.append(
                Variant(
                    name=f"expr__{off_name}__{form_name}",
                    category="generated_expression_matrix",
                    source=COMMON_CLASS_DECL + "\n" + f"char& DString::operator[](int index) {{\n    return {expr.format(off=off_expr)};\n}}\n",
                    note=f"offset={off_name}; final={form_name}",
                )
            )
    return variants


def wrap_expression(wrapper_name: str, expression: str) -> list[str]:
    wrapped = []
    for line in WRAPPER_STYLES[wrapper_name]:
        wrapped.append(line.format(expr=expression))
    return wrapped


def build_targeted_matrix() -> list[Variant]:
    variants: list[Variant] = []
    for base_name, (base_lines, base_token) in TARGETED_BASE_CARRIERS.items():
        for off_name, (off_lines, off_token) in TARGETED_OFFSET_CARRIERS.items():
            for final_name, final_template in TARGETED_FINAL_TEMPLATES.items():
                expression = final_template.format(base=base_token, off=off_token)
                for wrapper_name in WRAPPER_STYLES:
                    body_lines: list[str] = []
                    body_lines.extend(base_lines)
                    body_lines.extend(off_lines)
                    body_lines.extend(wrap_expression(wrapper_name, expression))
                    indented = "\n".join(f"    {line}" for line in body_lines)
                    variants.append(
                        Variant(
                            name=f"targeted__{base_name}__{off_name}__{final_name}__{wrapper_name}",
                            category="targeted_carrier_matrix",
                            source=COMMON_CLASS_DECL + "\n" + f"char& DString::operator[](int index) {{\n{indented}\n}}\n",
                            note=(
                                f"base={base_name}; off={off_name}; final={final_name}; wrapper={wrapper_name}"
                            ),
                        )
                    )
    return variants


def build_control_flow_variants() -> list[Variant]:
    forms = {
        "array": ("this->stringValue[index]", "this->stringValue[0]"),
        "ptradd": ("*(index + this->stringValue)", "*(0 + this->stringValue)"),
    }
    templates: dict[str, tuple[list[str], str]] = {
        "combined_fail_returns": (
            [
                f"if ({FAIL_COND})",
                "    return {fail};",
                "return {success};",
            ],
            "combined fail check with direct returns",
        ),
        "combined_fail_goto_fail": (
            [
                f"if ({FAIL_COND})",
                "    goto fail;",
                "return {success};",
                "fail:",
                "return {fail};",
            ],
            "combined fail check with explicit fail label",
        ),
        "combined_fail_goto_success": (
            [
                f"if ({FAIL_COND})",
                "    return {fail};",
                "goto success;",
                "success:",
                "return {success};",
            ],
            "combined fail return plus explicit success label",
        ),
        "split_fail_returns": (
            [
                "if (index < 0)",
                "    return {fail};",
                "if (this->lengthValue < index + 1)",
                "    return {fail};",
                "return {success};",
            ],
            "split fail checks with direct returns",
        ),
        "split_fail_goto_fail": (
            [
                "if (index < 0)",
                "    goto fail;",
                "if (this->lengthValue < index + 1)",
                "    goto fail;",
                "return {success};",
                "fail:",
                "return {fail};",
            ],
            "split fail checks with shared fail label",
        ),
        "nested_success_returns": (
            [
                "if (index >= 0) {{",
                "    if (this->lengthValue >= index + 1)",
                "        return {success};",
                "}}",
                "return {fail};",
            ],
            "nested success checks with fail tail",
        ),
        "success_if_returns": (
            [
                f"if ({SUCCESS_COND})",
                "    return {success};",
                "return {fail};",
            ],
            "combined success check with fail tail",
        ),
        "success_if_goto_success": (
            [
                f"if ({SUCCESS_COND})",
                "    goto success;",
                "return {fail};",
                "success:",
                "return {success};",
            ],
            "combined success check with explicit success label",
        ),
        "bound_temp_split_returns": (
            [
                "if (index < 0)",
                "    return {fail};",
                "int bound = index + 1;",
                "if (this->lengthValue < bound)",
                "    return {fail};",
                "return {success};",
            ],
            "split fail checks with named bound temp",
        ),
        "bound_temp_split_goto_fail": (
            [
                "if (index < 0)",
                "    goto fail;",
                "int bound = index + 1;",
                "if (this->lengthValue < bound)",
                "    goto fail;",
                "return {success};",
                "fail:",
                "return {fail};",
            ],
            "split fail checks with named bound temp and fail label",
        ),
        "length_temp_split_returns": (
            [
                "if (index < 0)",
                "    return {fail};",
                "int length = this->lengthValue;",
                "if (length < index + 1)",
                "    return {fail};",
                "return {success};",
            ],
            "split fail checks with named length temp",
        ),
        "length_temp_split_goto_fail": (
            [
                "if (index < 0)",
                "    goto fail;",
                "int length = this->lengthValue;",
                "if (length < index + 1)",
                "    goto fail;",
                "return {success};",
                "fail:",
                "return {fail};",
            ],
            "split fail checks with named length temp and fail label",
        ),
    }

    variants: list[Variant] = []
    for form_name, (success_expr, fail_expr) in forms.items():
        for template_name, (template_lines, note) in templates.items():
            body_lines = [line.format(success=success_expr, fail=fail_expr) for line in template_lines]
            indented = "\n".join(f"    {line}" for line in body_lines)
            variants.append(
                Variant(
                    name=f"control__{template_name}__{form_name}",
                    category="control_flow_frontier",
                    source=COMMON_CLASS_DECL + "\n" + f"char& DString::operator[](int index) {{\n{indented}\n}}\n",
                    note=f"{note}; final={form_name}",
                )
            )
    return variants


def build_micro_bridge_variants() -> list[Variant]:
    offset_variants: dict[str, str] = {
        "baseline_fail_ternary": f"({FAIL_COND}) ? 0 : index",
        "fail_len_le_index": "(index < 0 || this->lengthValue <= index) ? 0 : index",
        "nested_fail": "index < 0 ? 0 : (this->lengthValue < index + 1 ? 0 : index)",
        "nested_fail_rev": "(this->lengthValue < index + 1) ? 0 : (index < 0 ? 0 : index)",
        "nested_lt_length": "index < 0 ? 0 : (index < this->lengthValue ? index : 0)",
        "success_lt_length": "(index >= 0 && index < this->lengthValue) ? index : 0",
        "success_lt_length_rev": "(index < this->lengthValue && index >= 0) ? index : 0",
        "gt_minus1_lt_length": "((-1 < index) && (index < this->lengthValue)) ? index : 0",
        "length_minus_1": "(index < 0 || this->lengthValue - 1 < index) ? 0 : index",
        "index_plus1_gt_length": "(index < 0 || index + 1 > this->lengthValue) ? 0 : index",
        "unsigned_lt_length": "((unsigned)index < (unsigned)this->lengthValue) ? index : 0",
    }
    final_forms: dict[str, str] = {
        "array": "this->stringValue[{off}]",
        "ptradd": "*(this->stringValue + ({off}))",
    }

    variants: list[Variant] = []
    for off_name, off_expr in offset_variants.items():
        for final_name, final_expr in final_forms.items():
            expression = final_expr.format(off=off_expr)
            variants.append(
                Variant(
                    name=f"micro__{off_name}__{final_name}",
                    category="micro_bridge_frontier",
                    source=COMMON_CLASS_DECL + "\n" + f"char& DString::operator[](int index) {{\n    return {expression};\n}}\n",
                    note=f"offset={off_name}; final={final_name}",
                )
            )
    return variants


def build_bridge_killer_variants() -> list[Variant]:
    fail = f"({FAIL_COND})"
    success = f"({SUCCESS_COND})"
    variants: list[Variant] = []
    bodies = {
        "cond_lvalue_array_fail": (
            f"char& DString::operator[](int index) {{\n    return {fail} ? this->stringValue[0] : this->stringValue[index];\n}}\n",
            "conditional operator over array lvalues using fail condition",
        ),
        "cond_lvalue_array_success": (
            f"char& DString::operator[](int index) {{\n    return {success} ? this->stringValue[index] : this->stringValue[0];\n}}\n",
            "conditional operator over array lvalues using success condition",
        ),
        "cond_lvalue_commuted_fail": (
            f"char& DString::operator[](int index) {{\n    return {fail} ? 0[this->stringValue] : index[this->stringValue];\n}}\n",
            "conditional operator over commuted array lvalues",
        ),
        "cond_mixed_array_ptradd_fail": (
            f"char& DString::operator[](int index) {{\n    return {fail} ? this->stringValue[0] : *(this->stringValue + index);\n}}\n",
            "conditional lvalue with array fail arm and ptradd success arm",
        ),
        "cond_mixed_ptradd_array_fail": (
            f"char& DString::operator[](int index) {{\n    return {fail} ? *this->stringValue : this->stringValue[index];\n}}\n",
            "conditional lvalue with deref fail arm and array success arm",
        ),
        "cond_mixed_commuted_fail": (
            f"char& DString::operator[](int index) {{\n    return {fail} ? *this->stringValue : *(index + this->stringValue);\n}}\n",
            "conditional lvalue with deref fail arm and commuted ptradd success arm",
        ),
        "cond_addr_indexed": (
            f"char& DString::operator[](int index) {{\n    return *({fail} ? &this->stringValue[0] : &this->stringValue[index]);\n}}\n",
            "conditional over indexed addresses then one dereference",
        ),
        "cond_addr_base_or_indexed": (
            f"char& DString::operator[](int index) {{\n    return *({fail} ? this->stringValue : &this->stringValue[index]);\n}}\n",
            "conditional over base pointer vs indexed address then dereference",
        ),
        "cond_ptr_zero_index_then_index0": (
            f"char& DString::operator[](int index) {{\n    return ({fail} ? this->stringValue : &this->stringValue[index])[0];\n}}\n",
            "conditional pointer result consumed by final [0]",
        ),
        "cond_ptr_commuted_then_index0": (
            f"char& DString::operator[](int index) {{\n    return ({fail} ? &this->stringValue[0] : index + this->stringValue)[0];\n}}\n",
            "conditional pointer with explicit commuted success arm consumed by [0]",
        ),
        "addr_of_best_array": (
            f"char& DString::operator[](int index) {{\n    return *(&this->stringValue[{fail} ? 0 : index]);\n}}\n",
            "explicit address-of best array form",
        ),
        "ptr_temp_from_best_array_addr": (
            f"char& DString::operator[](int index) {{\n    char* p = &this->stringValue[{fail} ? 0 : index];\n    return *p;\n}}\n",
            "pointer temp from best array address",
        ),
        "ptr_temp_from_cond_ptr": (
            f"char& DString::operator[](int index) {{\n    char* p = {fail} ? this->stringValue : &this->stringValue[index];\n    return *p;\n}}\n",
            "pointer temp from conditional pointer",
        ),
        "ref_temp_from_cond_lvalue": (
            f"char& DString::operator[](int index) {{\n    char& r = {fail} ? this->stringValue[0] : this->stringValue[index];\n    return r;\n}}\n",
            "reference temp from conditional lvalue",
        ),
        "ref_temp_from_best_array": (
            f"char& DString::operator[](int index) {{\n    char& r = this->stringValue[{fail} ? 0 : index];\n    return r;\n}}\n",
            "reference temp from best array basin",
        ),
        "paren_cond_lvalue": (
            f"char& DString::operator[](int index) {{\n    return ({fail} ? this->stringValue[0] : this->stringValue[index]);\n}}\n",
            "parenthesized conditional lvalue array form",
        ),
    }
    for name, (body, note) in bodies.items():
        variants.append(Variant(name=f"bridge__{name}", category="bridge_killer_frontier", source=COMMON_CLASS_DECL + "\n" + body, note=note))
    return variants


def build_compare_bound_variants() -> list[Variant]:
    bodies = {
        "baseline_fail_array": (
            f"char& DString::operator[](int index) {{\n    return this->stringValue[({FAIL_COND}) ? 0 : index];\n}}\n",
            "baseline fail-condition array form",
        ),
        "baseline_fail_ptradd": (
            f"char& DString::operator[](int index) {{\n    return *(this->stringValue + (({FAIL_COND}) ? 0 : index));\n}}\n",
            "baseline fail-condition ptradd form",
        ),
        "fail_plus1_left_array": (
            "char& DString::operator[](int index) {\n    return this->stringValue[(index < 0 || this->lengthValue < 1 + index) ? 0 : index];\n}\n",
            "fail form with `1 + index` instead of `index + 1`",
        ),
        "fail_gt_array": (
            "char& DString::operator[](int index) {\n    return this->stringValue[(index < 0 || index + 1 > this->lengthValue) ? 0 : index];\n}\n",
            "fail form with `index + 1 > length`",
        ),
        "fail_gt_left_array": (
            "char& DString::operator[](int index) {\n    return this->stringValue[(index < 0 || 1 + index > this->lengthValue) ? 0 : index];\n}\n",
            "fail form with `1 + index > length`",
        ),
        "fail_len_paren_array": (
            "char& DString::operator[](int index) {\n    return this->stringValue[(index < 0 || (this->lengthValue < (index + 1))) ? 0 : index];\n}\n",
            "fail form with extra parentheses around bound compare",
        ),
        "success_le_array": (
            "char& DString::operator[](int index) {\n    return this->stringValue[(index >= 0 && index + 1 <= this->lengthValue) ? index : 0];\n}\n",
            "success form with `index + 1 <= length`",
        ),
        "success_le_left_array": (
            "char& DString::operator[](int index) {\n    return this->stringValue[(index >= 0 && 1 + index <= this->lengthValue) ? index : 0];\n}\n",
            "success form with `1 + index <= length`",
        ),
        "success_ge_array": (
            "char& DString::operator[](int index) {\n    return this->stringValue[(index >= 0 && this->lengthValue >= index + 1) ? index : 0];\n}\n",
            "success form with `length >= index + 1`",
        ),
        "bound_temp_array": (
            "char& DString::operator[](int index) {\n    int bound = index + 1;\n    return this->stringValue[(index < 0 || this->lengthValue < bound) ? 0 : index];\n}\n",
            "named bound temp used in fail ternary",
        ),
        "bound_temp_left_array": (
            "char& DString::operator[](int index) {\n    int bound = 1 + index;\n    return this->stringValue[(index < 0 || this->lengthValue < bound) ? 0 : index];\n}\n",
            "named bound temp from `1 + index`",
        ),
        "length_temp_array": (
            "char& DString::operator[](int index) {\n    int length = this->lengthValue;\n    return this->stringValue[(index < 0 || length < index + 1) ? 0 : index];\n}\n",
            "named length temp used in fail ternary",
        ),
        "length_and_bound_temp_array": (
            "char& DString::operator[](int index) {\n    int length = this->lengthValue;\n    int bound = index + 1;\n    return this->stringValue[(index < 0 || length < bound) ? 0 : index];\n}\n",
            "named length and bound temps used in fail ternary",
        ),
        "bool_success_array": (
            "char& DString::operator[](int index) {\n    int ok = index >= 0 && index + 1 <= this->lengthValue;\n    return this->stringValue[ok ? index : 0];\n}\n",
            "boolean success flag feeding final ternary",
        ),
        "bool_not_fail_array": (
            f"char& DString::operator[](int index) {{\n    int ok = !({FAIL_COND});\n    return this->stringValue[ok ? index : 0];\n}}\n",
            "boolean `!fail` flag feeding final ternary",
        ),
        "cmp_length_lt_array": (
            "char& DString::operator[](int index) {\n    return this->stringValue[(index < 0 || !(index < this->lengthValue)) ? 0 : index];\n}\n",
            "negated `< length` success inside fail form",
        ),
        "cmp_length_le_minus1_array": (
            "char& DString::operator[](int index) {\n    return this->stringValue[(index < 0 || !(index <= this->lengthValue - 1)) ? 0 : index];\n}\n",
            "negated `index <= length - 1` success inside fail form",
        ),
        "paren_success_array": (
            "char& DString::operator[](int index) {\n    return this->stringValue[((index >= 0) && ((index + 1) <= this->lengthValue)) ? index : 0];\n}\n",
            "parenthesized success form with `index + 1 <= length`",
        ),
    }
    return [
        Variant(name=f"compare__{name}", category="compare_bound_frontier", source=COMMON_CLASS_DECL + "\n" + body, note=note)
        for name, (body, note) in bodies.items()
    ]


def build_final_add_order_variants() -> list[Variant]:
    off = f"({FAIL_COND}) ? 0 : index"
    bodies = {
        "baseline_array": (
            f"char& DString::operator[](int index) {{\n    return this->stringValue[{off}];\n}}\n",
            "baseline best-basin array form",
        ),
        "baseline_ptradd": (
            f"char& DString::operator[](int index) {{\n    return *(this->stringValue + ({off}));\n}}\n",
            "baseline best-basin ptradd form",
        ),
        "array_plus_zero_left": (
            f"char& DString::operator[](int index) {{\n    return this->stringValue[0 + ({off})];\n}}\n",
            "array index with leading +0",
        ),
        "array_plus_zero_right": (
            f"char& DString::operator[](int index) {{\n    return this->stringValue[({off}) + 0];\n}}\n",
            "array index with trailing +0",
        ),
        "array_minus_zero": (
            f"char& DString::operator[](int index) {{\n    return this->stringValue[({off}) - 0];\n}}\n",
            "array index with -0",
        ),
        "array_plus_unary": (
            f"char& DString::operator[](int index) {{\n    return this->stringValue[+({off})];\n}}\n",
            "array index with unary plus",
        ),
        "array_cast_int": (
            f"char& DString::operator[](int index) {{\n    return this->stringValue[(int)({off})];\n}}\n",
            "array index with explicit int cast",
        ),
        "array_cast_long": (
            f"char& DString::operator[](int index) {{\n    return this->stringValue[(long)({off})];\n}}\n",
            "array index with explicit long cast",
        ),
        "ptradd_cast_base": (
            f"char& DString::operator[](int index) {{\n    return *((char*)this->stringValue + ({off}));\n}}\n",
            "ptradd with inline char* cast on base",
        ),
        "ptradd_cast_base_commuted": (
            f"char& DString::operator[](int index) {{\n    return *(({off}) + (char*)this->stringValue);\n}}\n",
            "commuted ptradd with inline char* cast on base",
        ),
        "ptradd_cast_off_int": (
            f"char& DString::operator[](int index) {{\n    return *(this->stringValue + (int)({off}));\n}}\n",
            "ptradd with explicit int cast on offset",
        ),
        "ptradd_cast_off_long": (
            f"char& DString::operator[](int index) {{\n    return *(this->stringValue + (long)({off}));\n}}\n",
            "ptradd with explicit long cast on offset",
        ),
        "addrof_array_zero_index": (
            f"char& DString::operator[](int index) {{\n    return (&this->stringValue[{off}])[0];\n}}\n",
            "address-of indexed element consumed with [0]",
        ),
        "addrof_base_zero_index": (
            f"char& DString::operator[](int index) {{\n    return (&this->stringValue[0])[({off})];\n}}\n",
            "base-zero pointer indexed by offset",
        ),
        "int_ptr_arith": (
            f"char& DString::operator[](int index) {{\n    return *(char*)((int)this->stringValue + ({off}));\n}}\n",
            "integer pointer arithmetic on base plus offset",
        ),
        "int_ptr_arith_commuted": (
            f"char& DString::operator[](int index) {{\n    return *(char*)(({off}) + (int)this->stringValue);\n}}\n",
            "commuted integer pointer arithmetic on base plus offset",
        ),
    }
    return [
        Variant(name=f"finaladd__{name}", category="final_add_order_frontier", source=COMMON_CLASS_DECL + "\n" + body, note=note)
        for name, (body, note) in bodies.items()
    ]


def build_context_variants() -> list[Variant]:
    best_body = f"char& DString::operator[](int index) {{\n    return this->stringValue[({FAIL_COND}) ? 0 : index];\n}}\n"
    variants: list[Variant] = []
    sources: dict[str, tuple[str, str]] = {
        "minimal_int_fields": (
            """class DString {
public:
    char* stringValue;
    int lengthValue;
    int numWordsValue;
    int indexValue;
    int currentWordValue;

    char& operator[](int index);
};

""" + best_body,
            "minimal int-field declaration with only operator[]",
        ),
        "full_decl_int_const": (
            """class DString {
public:
    char* stringValue;
    int lengthValue;
    int numWordsValue;
    int indexValue;
    int currentWordValue;

    DString();
    DString(const char* value);
    ~DString();
    char& operator[](int index);
    operator char*() const;
    int length(void) const;
    int index(void) const;
    int numWords(void);
    char* word(int wordIndex);
    char* nextWord(void);
};

""" + best_body,
            "full int-field declaration with const accessors and neighbors declared",
        ),
        "full_decl_long_const": (
            """class DString {
public:
    char* stringValue;
    long lengthValue;
    long numWordsValue;
    long indexValue;
    long currentWordValue;

    DString();
    DString(const char* value);
    ~DString();
    char& operator[](int index);
    operator char*() const;
    long length(void) const;
    long index(void) const;
    long numWords(void);
    char* word(int wordIndex);
    char* nextWord(void);
};

""" + best_body,
            "full long-field declaration with const accessors and neighbors declared",
        ),
        "full_decl_nonconst_accessors": (
            """class DString {
public:
    char* stringValue;
    int lengthValue;
    int numWordsValue;
    int indexValue;
    int currentWordValue;

    DString();
    DString(const char* value);
    ~DString();
    char& operator[](int index);
    operator char*();
    int length(void);
    int index(void);
    int numWords(void);
    char* word(int wordIndex);
    char* nextWord(void);
};

""" + best_body,
            "full int-field declaration with non-const accessors",
        ),
        "neighbor_defs_after": (
            """class DString {
public:
    char* stringValue;
    int lengthValue;
    int numWordsValue;
    int indexValue;
    int currentWordValue;

    DString();
    DString(const char* value);
    ~DString();
    char& operator[](int index);
    operator char*() const;
    int length(void) const;
    int index(void) const;
};

""" + best_body + """
DString::operator char*() const { return this->stringValue; }
int DString::length(void) const { return this->lengthValue; }
int DString::index(void) const { return this->indexValue; }
""",
            "full declaration plus neighboring accessor definitions after operator[]",
        ),
        "inline_neighbor_defs_in_class": (
            """class DString {
public:
    char* stringValue;
    int lengthValue;
    int numWordsValue;
    int indexValue;
    int currentWordValue;

    DString();
    DString(const char* value);
    ~DString();
    char& operator[](int index);
    operator char*() const { return this->stringValue; }
    int length(void) const { return this->lengthValue; }
    int index(void) const { return this->indexValue; }
};

""" + best_body,
            "neighboring accessors defined inline in class body",
        ),
        "method_order_neighbors_first": (
            """class DString {
public:
    char* stringValue;
    int lengthValue;
    int numWordsValue;
    int indexValue;
    int currentWordValue;

    operator char*() const;
    int length(void) const;
    int index(void) const;
    char& operator[](int index);
    DString();
    DString(const char* value);
    ~DString();
};

""" + best_body,
            "same full declaration but neighbors declared before operator[]",
        ),
        "operator_const_method": (
            """class DString {
public:
    char* stringValue;
    int lengthValue;
    int numWordsValue;
    int indexValue;
    int currentWordValue;

    char& operator[](int index) const;
};

char& DString::operator[](int index) const {
    return this->stringValue[(index < 0 || this->lengthValue < index + 1) ? 0 : index];
}
""",
            "operator[] declared const while still returning char&",
        ),
        "inline_body_in_class": (
            """class DString {
public:
    char* stringValue;
    int lengthValue;
    int numWordsValue;
    int indexValue;
    int currentWordValue;

    char& operator[](int index) {
        return this->stringValue[(index < 0 || this->lengthValue < index + 1) ? 0 : index];
    }
};
""",
            "operator[] defined inline in class body",
        ),
        "minimal_long_fields": (
            """class DString {
public:
    char* stringValue;
    long lengthValue;
    long numWordsValue;
    long indexValue;
    long currentWordValue;

    char& operator[](int index);
};

""" + best_body,
            "minimal long-field declaration with only operator[]",
        ),
        "full_decl_with_containss": (
            """class DString {
public:
    char* stringValue;
    int lengthValue;
    int numWordsValue;
    int indexValue;
    int currentWordValue;

    DString();
    DString(const char* value);
    ~DString();
    char& operator[](int index);
    operator char*() const;
    int length(void) const;
    int index(void) const;
    int contains(const char* value) const;
    int contains(DString value) const;
    int numWords(void);
    char* word(int wordIndex);
    char* nextWord(void);
    void uppercase(void);
    void lowercase(void);
    void change(char from, char to);
};

""" + best_body,
            "fuller dstring neighborhood declaration with extra method surface only",
        ),
        "full_decl_with_ctor_dtor_defs": (
            """class DString {
public:
    char* stringValue;
    int lengthValue;
    int numWordsValue;
    int indexValue;
    int currentWordValue;

    DString();
    DString(const char* value);
    ~DString();
    char& operator[](int index);
    operator char*() const;
    int length(void) const;
    int index(void) const;
};

""" + best_body + """
DString::DString() {}
DString::DString(const char* value) { (void)value; }
DString::~DString() {}
DString::operator char*() const { return this->stringValue; }
int DString::length(void) const { return this->lengthValue; }
int DString::index(void) const { return this->indexValue; }
""",
            "full declaration plus trivial ctor/dtor and accessor defs after operator[]",
        ),
    }
    for name, (source, note) in sources.items():
        variants.append(Variant(name=f"context__{name}", category="context_frontier", source=source, note=note))
    return variants


def build_handwritten_variants() -> list[Variant]:
    bodies = {
        "baseline_best_array": (
            "best_known",
            f"char& DString::operator[](int index) {{\n    return this->stringValue[({FAIL_COND}) ? 0 : index];\n}}\n",
            "current best-known near-match",
        ),
        "normalize_param_array": (
            "statement_family",
            f"char& DString::operator[](int index) {{\n    if ({FAIL_COND})\n        index = 0;\n    return this->stringValue[index];\n}}\n",
            "parameter normalization family",
        ),
        "normalize_param_ptradd": (
            "statement_family",
            f"char& DString::operator[](int index) {{\n    if ({FAIL_COND})\n        index = 0;\n    return *(index + this->stringValue);\n}}\n",
            "parameter normalization plus pointer-add",
        ),
        "local_off_array": (
            "statement_family",
            f"char& DString::operator[](int index) {{\n    int off = ({FAIL_COND}) ? 0 : index;\n    return this->stringValue[off];\n}}\n",
            "local merged offset plus array form",
        ),
        "local_off_ptradd": (
            "statement_family",
            f"char& DString::operator[](int index) {{\n    int off = ({FAIL_COND}) ? 0 : index;\n    return *(off + this->stringValue);\n}}\n",
            "local merged offset plus pointer-add",
        ),
        "pointer_ternary_both_add": (
            "pointer_selection_family",
            f"char& DString::operator[](int index) {{\n    return *(({FAIL_COND}) ? (this->stringValue + 0) : (this->stringValue + index));\n}}\n",
            "pointer-selection family with explicit add arms",
        ),
        "if_fail_return_zero_success_ptradd": (
            "pointer_selection_family",
            f"char& DString::operator[](int index) {{\n    if ({FAIL_COND})\n        return *(0 + this->stringValue);\n    return *(index + this->stringValue);\n}}\n",
            "branchy fail/success pointer-add family",
        ),
        "success_ternary_array": (
            "success_cond_family",
            f"char& DString::operator[](int index) {{\n    return this->stringValue[({SUCCESS_COND}) ? index : 0];\n}}\n",
            "success-condition variant of the best basin",
        ),
    }
    return [
        Variant(name=name, category=category, source=COMMON_CLASS_DECL + "\n" + body, note=note)
        for name, (category, body, note) in bodies.items()
    ]


def collect_variants(pattern: str | None, limit: int | None) -> list[Variant]:
    variants = (
        build_handwritten_variants()
        + build_expression_matrix()
        + build_targeted_matrix()
        + build_control_flow_variants()
        + build_micro_bridge_variants()
        + build_bridge_killer_variants()
        + build_compare_bound_variants()
        + build_final_add_order_variants()
        + build_context_variants()
    )
    variants.sort(key=lambda item: item.name)
    if pattern:
        regex = re.compile(pattern)
        variants = [variant for variant in variants if regex.search(variant.name)]
    if limit is not None:
        variants = variants[:limit]
    return variants


def compile_variant(variant: Variant, original: OriginalTarget, toolchain: dict) -> VariantResult:
    source_path = GENERATED_DIR / f"{variant.name}.cpp"
    obj_path = OBJ_DIR / f"{variant.name}.obj"
    asm_path = ASM_DIR / f"{variant.name}.txt"
    meta_path = ASM_DIR / f"{variant.name}.json"
    source_path.write_text(variant.source, encoding="utf-8")

    cl_path = repo_path(toolchain["compiler"]["cl"])
    rsp_path = repo_path(toolchain["compiler"]["default_rsp"])
    command = [str(cl_path), f"@{rsp_path}", f"/Fo{obj_path}", str(source_path)]
    result = subprocess.run(command, capture_output=True, text=True, env=tool_env(toolchain))
    if result.returncode != 0 or not obj_path.exists():
        return VariantResult(
            name=variant.name,
            category=variant.category,
            note=variant.note,
            compile_ok=False,
            source_path=str(source_path),
            object_path=None,
            size_bytes=None,
            first_mismatch=None,
            family="compile_error",
            asm_sha1=None,
            entry_register=None,
            has_mov_edx_eax=False,
            has_add_eax_mem=False,
            has_mov_eax_mem_add_eax_edx=False,
            jump_pattern=None,
            masked_window=None,
            asm_path=None,
            stdout=result.stdout,
            stderr=result.stderr,
        )

    section = load_coff_section(obj_path, ".text")
    compare_bytes = section.data[: len(original.bytes)]
    masked_bytes = mask_relocations(compare_bytes, [reloc for reloc in section.relocations if reloc.offset < len(compare_bytes)])
    mismatch = first_mismatch_offset(original.bytes, masked_bytes)
    decoded = decode_bytes(compare_bytes, TARGET_VA)
    asm_lines = [f"{line['address']}  {line['bytes']:<16}  {line['text']}" for line in decoded]
    asm_text = "\n".join(asm_lines) + ("\n" if asm_lines else "")
    asm_path.write_text(asm_text, encoding="utf-8")
    asm_sha1 = hashlib.sha1(compare_bytes).hexdigest()[:12]
    meta_path.write_text(
        json.dumps(
            {
                "variant": variant.name,
                "category": variant.category,
                "note": variant.note,
                "source": str(source_path),
                "object": str(obj_path),
                "size_bytes": len(compare_bytes),
                "asm_sha1": asm_sha1,
                "relocations": [
                    {
                        "offset": reloc.offset,
                        "width": reloc.width,
                        "type": f"0x{reloc.reloc_type:04X}",
                    }
                    for reloc in section.relocations
                    if reloc.offset < len(compare_bytes)
                ],
            },
            indent=2,
        ),
        encoding="utf-8",
    )

    entry_register = None
    if asm_lines:
        first_line = asm_lines[0].lower()
        if "mov eax,[esp+4]" in first_line:
            entry_register = "eax"
        elif "mov edx,[esp+4]" in first_line:
            entry_register = "edx"

    has_mov_edx_eax = any("mov edx,eax" in line.lower() for line in asm_lines)
    has_add_eax_mem = any("add eax,[ecx]" in line.lower() for line in asm_lines)
    has_mov_eax_mem_add_eax_edx = False
    for index, line in enumerate(asm_lines[:-1]):
        if "mov eax,[ecx]" in line.lower() and "add eax,edx" in asm_lines[index + 1].lower():
            has_mov_eax_mem_add_eax_edx = True
            break

    jump_lines = [
        line
        for line in asm_lines
        if " jl " in line.lower() or " jge " in line.lower() or " jg " in line.lower() or " jle " in line.lower()
    ]
    jump_pattern = " | ".join(part.split("  ")[-1] for part in jump_lines[:3]) if jump_lines else None

    family = "other"
    if entry_register == "edx":
        family = "entry_edx_family"
    elif entry_register == "eax" and has_mov_edx_eax:
        family = "entry_eax_bridge_edx_family"
    elif entry_register == "eax" and has_add_eax_mem:
        family = "target_like_family"

    masked_window = None
    if mismatch is not None:
        start = max(0, mismatch - 8)
        end = min(len(original.bytes), mismatch + 8)
        masked_window = masked_bytes[start:end].hex()

    return VariantResult(
        name=variant.name,
        category=variant.category,
        note=variant.note,
        compile_ok=True,
        source_path=str(source_path),
        object_path=str(obj_path),
        size_bytes=len(compare_bytes),
        first_mismatch=mismatch,
        family=family,
        asm_sha1=asm_sha1,
        entry_register=entry_register,
        has_mov_edx_eax=has_mov_edx_eax,
        has_add_eax_mem=has_add_eax_mem,
        has_mov_eax_mem_add_eax_edx=has_mov_eax_mem_add_eax_edx,
        jump_pattern=jump_pattern,
        masked_window=masked_window,
        asm_path=str(asm_path),
        stdout=result.stdout,
        stderr=result.stderr,
    )


def write_reports(results: list[VariantResult], original: OriginalTarget) -> None:
    summary_records = []
    for result in results:
        summary_records.append(
            {
                "name": result.name,
                "category": result.category,
                "note": result.note,
                "compile_ok": result.compile_ok,
                "first_mismatch": "" if result.first_mismatch is None else result.first_mismatch,
                "family": result.family,
                "asm_sha1": result.asm_sha1 or "",
                "entry_register": result.entry_register or "",
                "has_mov_edx_eax": result.has_mov_edx_eax,
                "has_add_eax_mem": result.has_add_eax_mem,
                "has_mov_eax_mem_add_eax_edx": result.has_mov_eax_mem_add_eax_edx,
                "jump_pattern": result.jump_pattern or "",
                "size_bytes": "" if result.size_bytes is None else result.size_bytes,
                "masked_window": result.masked_window or "",
                "source_path": result.source_path,
                "object_path": result.object_path or "",
                "asm_path": result.asm_path or "",
            }
        )

    with SUMMARY_CSV.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(handle, fieldnames=list(summary_records[0].keys()) if summary_records else ["name"])
        writer.writeheader()
        writer.writerows(summary_records)

    SUMMARY_JSON.write_text(
        json.dumps(
            {
                "target_va": format_hex(TARGET_VA),
                "original_size_bytes": len(original.bytes),
                "results": summary_records,
            },
            indent=2,
        ),
        encoding="utf-8",
    )

    sortable = [result for result in results if result.compile_ok]
    sortable.sort(key=lambda item: (item.first_mismatch is None, -(item.first_mismatch or -1), item.name))

    family_counts: dict[str, int] = {}
    for result in results:
        family_counts[result.family] = family_counts.get(result.family, 0) + 1

    signature_reps: dict[str, list[VariantResult]] = {}
    for result in sortable:
        if result.asm_sha1 is None:
            continue
        signature_reps.setdefault(result.asm_sha1, []).append(result)

    signature_rows = sorted(
        ((sha1, rows) for sha1, rows in signature_reps.items()),
        key=lambda item: (-len(item[1]), item[1][0].first_mismatch or -1, item[0]),
    )

    lines = [
        f"# VC5 micro-harness summary for {LAB_SLUG}",
        "",
        f"Target VA: `{format_hex(TARGET_VA)}`",
        f"Original size: `{len(original.bytes)}` bytes",
        f"Variants compiled: `{len(results)}`",
        "",
        "## Family counts",
        "",
    ]
    for family, count in sorted(family_counts.items()):
        lines.append(f"- `{family}`: {count}")
    lines.extend(["", "## Top exact code signatures", ""])
    for sha1, rows in signature_rows[:12]:
        rep = rows[0]
        lines.append(
            f"- `{sha1}` — count `{len(rows)}`, family `{rep.family}`, first mismatch "
            f"`{rep.first_mismatch if rep.first_mismatch is not None else 'n/a'}`, rep `{rep.name}`"
        )
    lines.extend(["", "## Best candidates", ""])
    for result in sortable[:16]:
        lines.append(
            f"- `{result.name}` — family `{result.family}`, first mismatch "
            f"`{result.first_mismatch if result.first_mismatch is not None else 'n/a'}`, note: {result.note}"
        )
    lines.extend(
        [
            "",
            "## Output locations",
            "",
            f"- sources: `{GENERATED_DIR}`",
            f"- objects: `{OBJ_DIR}`",
            f"- asm: `{ASM_DIR}`",
            f"- csv summary: `{SUMMARY_CSV}`",
            f"- json summary: `{SUMMARY_JSON}`",
        ]
    )
    SUMMARY_MD.write_text("\n".join(lines) + "\n", encoding="utf-8")


def print_console_summary(results: list[VariantResult]) -> None:
    sortable = [result for result in results if result.compile_ok]
    sortable.sort(key=lambda item: (item.first_mismatch is None, -(item.first_mismatch or -1), item.name))
    print(f"Compiled {len(results)} variants.")
    print("Top results:")
    for result in sortable[:12]:
        print(
            f"  {result.name:70} mismatch={result.first_mismatch!s:>3} "
            f"family={result.family:28} sha1={result.asm_sha1}"
        )


def main() -> None:
    args = parse_args()
    ensure_lab_dirs(clean=args.clean)
    original = load_original_target()
    toolchain = load_toolchain()
    variants = collect_variants(args.variant, args.limit)
    if not variants:
        raise SystemExit("No variants selected")

    results: list[VariantResult] = []
    for variant in variants:
        try:
            results.append(compile_variant(variant, original, toolchain))
        except Exception as exc:  # pragma: no cover - lab robustness over elegance
            if not args.keep_going:
                raise
            results.append(
                VariantResult(
                    name=variant.name,
                    category=variant.category,
                    note=f"{variant.note} (exception: {exc})",
                    compile_ok=False,
                    source_path=str(GENERATED_DIR / f"{variant.name}.cpp"),
                    object_path=None,
                    size_bytes=None,
                    first_mismatch=None,
                    family="exception",
                    asm_sha1=None,
                    entry_register=None,
                    has_mov_edx_eax=False,
                    has_add_eax_mem=False,
                    has_mov_eax_mem_add_eax_edx=False,
                    jump_pattern=None,
                    masked_window=None,
                    asm_path=None,
                    stdout="",
                    stderr=str(exc),
                )
            )

    write_reports(results, original)
    print_console_summary(results)
    print(f"Summary: {SUMMARY_MD}")


if __name__ == "__main__":
    main()
