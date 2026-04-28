"""Variant lab tool. Run `python tools/variant_lab.py --help` for syntax and usage details."""

from __future__ import annotations

import argparse
import concurrent.futures
import difflib
import hashlib
import itertools
import json
import os
import re
import shutil
import shlex
import struct
import subprocess
import sys
import time
from dataclasses import dataclass, field
from pathlib import Path
from typing import Iterable

from common import (
    CONFIG_DIR,
    REPO_ROOT,
    ensure_dir,
    format_hex,
    function_record_by_va,
    function_slug,
    load_toolchain,
    preferred_source_path,
    repo_path,
    tool_env,
)
from extract_obj_function import decode_bytes


# Variant labs are intentionally allowed to get large: sticky VC5 codegen-family
# problems are often cheaper to solve with broad structured sweeps than with
# hours of manual churn. Keep a high default cap so accidental million-variant
# explosions still fail early; pass --max-variants 0 to disable the cap.
DEFAULT_MAX_VARIANTS = 250_000

VARIANT_TEMPLATE_DIRS = [
    REPO_ROOT / "config" / "variant_templates",
    REPO_ROOT / "tools" / "variant_templates",
]
VARIANT_TEMPLATE_EXTENSIONS = (".vtpl", ".tpl", ".txt")


FLAG_PRESETS: dict[str, dict[str, str]] = {
    # Small, commonly useful VC5 classification sweep. These are appended after
    # config/flags/default.rsp, just like template @flagchoice content.
    "vc5-small": {
        "default": "",
        "gx": "/GX\n",
        "ow": "/Ow\n",
        "gx_ow": "/GX /Ow\n",
        "oi": "/Oi\n",
        "gx_oi": "/GX /Oi\n",
        "og": "/Og\n",
        "gx_og": "/GX /Og\n",
        "ot": "/Ot\n",
        "gx_ot": "/GX /Ot\n",
        "ob0": "/Ob0\n",
        "gx_ob0": "/GX /Ob0\n",
    },
    # Riskier/noisier options. Useful to classify basins, but a match under one
    # of these flags needs deliberate review before promotion.
    "vc5-risky": {
        "default": "",
        "gx": "/GX\n",
        "oa": "/Oa\n",
        "gx_oa": "/GX /Oa\n",
        "og_minus": "/Og-\n",
        "gx_og_minus": "/GX /Og-\n",
        "ot_minus": "/Ot-\n",
        "gx_ot_minus": "/GX /Ot-\n",
        "o1": "/O1\n",
        "gx_o1": "/GX /O1\n",
        "ox": "/Ox\n",
        "gx_ox": "/GX /Ox\n",
    },
    # Debug-info flags are intentionally separate: they can perturb codegen and
    # produce debug sections that are noisier for tooling.
    "vc5-debug-context": {
        "default": "",
        "zd": "/Zd\n",
        "zi": "/Zi /Fd{work_dir}\\vc.pdb\n",
        "z7": "/Z7\n",
    },
}


HELP_EPILOG = r"""
Template syntax
===============

variant_lab compiles a full C/C++ source template many times.  It never edits
src/scratch or src/matching.  Generated sources/objects/reports are written under
build/variant_lab/<slug>/<run-id>/.

Source choices
--------------

  @choice axis_name
  @case case_label
      source emitted when axis_name=case_label
  @case other_label
      alternate source
  @endchoice

Every distinct axis is expanded as a Cartesian product.  Reusing the same axis
name links choices together: one selected case is used at every block with that
axis name.  Repeated blocks may omit a case; omitted cases emit nothing for that
block.  This is useful for donor/TU context toggles.

Reusable template presets
-------------------------

Preset files live in config/variant_templates/ (preferred) or tools/variant_templates/.
They are ordinary text files with .vtpl/.tpl/.txt extensions that expand to normal
@choice/@flagchoice template text before parsing. Use them to encode reusable VC5
source-shape families and add more cases over time without editing this script.

Single-line preset:

  @template vc5_dummy_member_surface axis=member_ctx class=Path prefix=ctx

Block preset with user body slots:

  @template vc5_guard axis=gate cond="maxSizeValue < other.maxSizeValue"
  @slot body
      setMaxSize(other.maxSizeValue);
  @endslot
  @endtemplate

Preset arguments use key=value shell-style parsing, so quote expressions with spaces.
Inside preset files, use {{axis}}, {{class}}, {{prefix}}, etc. for arguments and
{{slot:body}} or {{slot:body|indent:4}} for slot content. Defaults include:
  prefix=<sanitized axis/name>, tmp=<prefix>_tmp, tmp2=<prefix>_tmp2,
  inverse=!(<cond>) when cond is supplied.

Compiler flag choices
---------------------

  @flagchoice flags_axis
  @case default
  @case debug_lines
  /Zd
  @case no_global_opt
  /Og-
  @endflagchoice

or equivalently:

  @flags flags_axis
  ...
  @endflags

Flag choices are removed from the generated source.  Selected flag case content
is written to a per-variant response file that is passed AFTER config/flags/default.rsp.
So every variant always starts from the project default flags and then appends the
selected additions/overrides.  For debug-info flags, variant_lab automatically
adds a unique /Fd path when needed to avoid parallel PDB collisions.

Common flag presets
-------------------

Use --flag-preset to append a named reusable flag axis without editing the template:

  --flag-preset vc5-small
  --flag-preset vc5-risky
  --flag-preset vc5-debug-context

Presets are explicit on purpose. They are classification tools, not promotion
policy. A match under non-default appended flags still needs normal review and
retesting/justification before a function is promoted.

Placeholders in flag cases
--------------------------

Flag case text can use these Python-style placeholders:

  {work_dir}    per-variant working directory
  {variant_id}  e.g. V000123
  {slug}        function slug
  {run_dir}     current lab run directory

Example:

  @flagchoice debug
  @case none
  @case zi
  /Zi /Fd{work_dir}\\vc.pdb
  @endflagchoice

Run examples
------------

  python tools/variant_lab.py --init --va 0051ACA0
  python tools/variant_lab.py --va 0051ACA0 --template build/temp/0051ACA0_get_help_info_lab.tpl.cpp
  python tools/variant_lab.py --va 0051ACA0 --template - < build/temp/template.tpl.cpp

For nontrivial labs, prefer writing a normal throwaway template file under
build/temp/ and editing that file. Avoid huge inline shell/Python strings; they
are error-prone and hard to inspect.

Output layout and tracing
-------------------------

Each run writes build/variant_lab/<slug>/<run-id>/ with:

  summary.txt                  human-readable report; start here
  manifest.json                machine-readable run metadata
  groups.tsv                   one row per unique emitted-code group
  variants.tsv                 one row per expanded variant with source/object/flags paths
  compile_errors.tsv           grouped compile/extract errors
  template_input.cpp           exact template used for the run
  work/V000000/source.cpp      exact generated source for variant V000000; contains a header comment pointing to summary/groups/variant companions
  work/V000000/<slug>.obj      object produced for that variant
  work/V000000/variant_flags.rsp
                               extra flags for that variant, if any
  groups/G0000/representative.cpp
                               generated source for representative variant of group G0000; contains a header comment pointing back to work/Vxxxxxx and TSV indexes
  groups/G0000/rebuilt.bin     representative rebuilt bytes
  groups/G0000/rebuilt.asm     representative rebuilt disassembly
  groups/G0000/diff.txt        original-vs-rebuilt asm diff, group metadata, and source/index paths
  matches/...                  exact-match generated sources, if any

To trace a group back to source: open summary.txt, pick a group id, inspect
 groups/Gxxxx/diff.txt and groups/Gxxxx/representative.cpp. For the exact
 variant row, use groups.tsv to find its representative Vxxxxxx, then inspect
 work/Vxxxxxx/source.cpp or the matching row in variants.tsv.

By default the tool uses max(1, cpu_count - 1) parallel compiler workers.
The default variant cap is high (250,000) because broad structured sweeps are a
normal late-stage convergence tool here. Use --max-variants N to lower it, or
--max-variants 0 to disable the cap for an intentional very large run.
"""


@dataclass(frozen=True)
class CoffReloc:
    offset: int
    symbol_index: int
    reloc_type: int
    width: int


@dataclass(frozen=True)
class LoadedText:
    name: str
    data: bytes
    relocations: list[CoffReloc]


@dataclass
class ChoiceBlock:
    kind: str  # "source" or "flags"
    name: str
    cases: dict[str, str]
    index: int


@dataclass
class Axis:
    kind: str
    name: str
    labels: list[str] = field(default_factory=list)
    blocks: list[ChoiceBlock] = field(default_factory=list)

    def add_label(self, label: str) -> None:
        if label not in self.labels:
            self.labels.append(label)


@dataclass
class TemplatePlan:
    nodes: list[str | ChoiceBlock]
    axes: list[Axis]
    axis_by_key: dict[tuple[str, str], Axis]


@dataclass
class VariantSpec:
    index: int
    variant_id: str
    labels: dict[tuple[str, str], str]


@dataclass
class VariantResult:
    variant_id: str
    labels_text: str
    status: str
    returncode: int | None = None
    text_size: int | None = None
    compare_size: int | None = None
    relocations: int = 0
    first_mismatch: int | None = None
    exact: bool = False
    ret_count: int = 0
    last_ret_end: int | None = None
    extra_after_last_ret: int | None = None
    likely_context_tail: bool = False
    group_key: str | None = None
    error_key: str | None = None
    source_path: str | None = None
    obj_path: str | None = None
    flags_path: str | None = None
    stdout: str = ""
    stderr: str = ""
    error_text: str = ""


@dataclass
class GroupInfo:
    group_id: str
    key: str
    count: int = 0
    representative: VariantResult | None = None
    text_size: int | None = None
    compare_size: int | None = None
    relocations: int = 0
    first_mismatch: int | None = None
    exact: bool = False
    ret_count: int = 0
    last_ret_end: int | None = None
    extra_after_last_ret: int | None = None
    likely_context_tail: bool = False


@dataclass
class ErrorGroup:
    error_id: str
    key: str
    count: int = 0
    representative: VariantResult | None = None
    text: str = ""


class SafeFormatDict(dict):
    def __missing__(self, key: str) -> str:
        return "{" + key + "}"


def relocation_width(reloc_type: int) -> int:
    return {
        0x0006: 4,  # IMAGE_REL_I386_DIR32
        0x0007: 4,  # IMAGE_REL_I386_DIR32NB
        0x000A: 2,  # IMAGE_REL_I386_SECTION
        0x000B: 4,  # IMAGE_REL_I386_SECREL
        0x0014: 4,  # IMAGE_REL_I386_REL32
    }.get(reloc_type, 4)


def read_c_string(buf: bytes, off: int) -> str:
    end = buf.find(b"\0", off)
    if end < 0:
        end = len(buf)
    return buf[off:end].decode("ascii", "replace")


def resolve_section_name(raw_name: bytes, data: bytes, ptr_symtab: int, num_symbols: int) -> str:
    raw_name = raw_name.rstrip(b"\0")
    if not raw_name.startswith(b"/"):
        return raw_name.decode("ascii", "replace")

    try:
        str_off = int(raw_name[1:].decode("ascii"))
    except ValueError:
        return raw_name.decode("ascii", "replace")

    string_table_base = ptr_symtab + num_symbols * 18
    if string_table_base + 4 > len(data):
        return raw_name.decode("ascii", "replace")

    target = string_table_base + str_off
    if target >= len(data):
        return raw_name.decode("ascii", "replace")
    return read_c_string(data, target)


def load_text_from_obj(path: Path) -> LoadedText:
    data = path.read_bytes()
    if len(data) < 20:
        raise ValueError(f"{path} is too small for a COFF object")

    machine, num_sections, _timestamp, ptr_symtab, num_symbols, opt_size, _chars = struct.unpack_from(
        "<HHLLLHH", data, 0
    )
    if machine != 0x14C:
        raise ValueError(f"unsupported COFF machine 0x{machine:04X} in {path}")

    sec_base = 20 + opt_size
    sections: list[tuple[str, bytes, list[CoffReloc]]] = []
    for index in range(num_sections):
        off = sec_base + index * 40
        if off + 40 > len(data):
            raise ValueError(f"truncated section table in {path}")

        raw_name = data[off : off + 8]
        name = resolve_section_name(raw_name, data, ptr_symtab, num_symbols)
        (
            _virtual_size,
            _virtual_address,
            size_raw,
            ptr_raw,
            ptr_reloc,
            _ptr_linenum,
            num_reloc,
            _num_linenum,
            _sec_chars,
        ) = struct.unpack_from("<LLLLLLHHL", data, off + 8)

        if ptr_raw + size_raw > len(data):
            raise ValueError(f"truncated raw data for section {name!r} in {path}")
        section_bytes = data[ptr_raw : ptr_raw + size_raw] if size_raw and ptr_raw else b""

        relocs: list[CoffReloc] = []
        for reloc_index in range(num_reloc):
            reloc_off = ptr_reloc + reloc_index * 10
            if reloc_off + 10 > len(data):
                raise ValueError(f"truncated relocation table for section {name!r} in {path}")
            virtual_address, symbol_index, reloc_type = struct.unpack_from("<LLH", data, reloc_off)
            relocs.append(
                CoffReloc(
                    offset=virtual_address,
                    symbol_index=symbol_index,
                    reloc_type=reloc_type,
                    width=relocation_width(reloc_type),
                )
            )
        sections.append((name, section_bytes, relocs))

    def join_sections(selected: Iterable[tuple[str, bytes, list[CoffReloc]]]) -> LoadedText:
        chunks: list[bytes] = []
        relocs: list[CoffReloc] = []
        names: list[str] = []
        base = 0
        for name, chunk, chunk_relocs in selected:
            if not chunk:
                continue
            names.append(name)
            chunks.append(chunk)
            for reloc in chunk_relocs:
                relocs.append(
                    CoffReloc(
                        offset=base + reloc.offset,
                        symbol_index=reloc.symbol_index,
                        reloc_type=reloc.reloc_type,
                        width=reloc.width,
                    )
                )
            base += len(chunk)
        if not chunks:
            raise ValueError(f"selected sections are empty in {path}")
        return LoadedText("+".join(names), b"".join(chunks), relocs)

    text_sections = [section for section in sections if section[0] == ".text" or section[0].startswith(".text$")]
    nonempty_text = [section for section in text_sections if section[1]]
    if nonempty_text:
        return join_sections(nonempty_text)

    xtra = [section for section in sections if section[0] == ".xtra" and section[1]]
    if xtra:
        return join_sections(xtra)

    skip = {".drectve", ".debug$F", ".debug$T", ".debug$S", ".debug$P"}
    fallback = [section for section in sections if section[0] not in skip and section[1]]
    if fallback:
        return join_sections([fallback[0]])

    available = ", ".join(name for name, _chunk, _relocs in sections)
    raise ValueError(f"no usable code section in {path}; sections: {available}")


def mask_relocations(data: bytes, relocs: list[CoffReloc]) -> bytes:
    mutable = bytearray(data)
    for reloc in relocs:
        start = reloc.offset
        end = min(len(mutable), start + reloc.width)
        if 0 <= start < len(mutable):
            for i in range(start, end):
                mutable[i] = 0
    return bytes(mutable)


def first_mismatch(left: bytes, right: bytes) -> int | None:
    limit = min(len(left), len(right))
    for i in range(limit):
        if left[i] != right[i]:
            return i
    if len(left) != len(right):
        return limit
    return None


def detect_ret_ends(code: bytes) -> list[int]:
    """Return instruction end offsets, decoded enough for lab heuristics.

    This deliberately uses the already-available disassembler instead of a byte
    scan so immediates that happen to contain C2/C3 do not look like returns.
    It is heuristic metadata only; early returns are normal in real functions.
    """
    ret_ends: list[int] = []
    for line in decode_bytes(code, 0):
        text = line["text"].strip().lower()
        if text == "ret" or text.startswith("ret "):
            offset = int(line["address"], 16)
            ret_ends.append(offset + len(bytes.fromhex(line["bytes"])))
    return ret_ends


def stable_hash(data: bytes | str) -> str:
    if isinstance(data, str):
        data = data.encode("utf-8", "replace")
    return hashlib.sha256(data).hexdigest()[:16]


def parse_directive(line: str) -> tuple[str, str | None] | None:
    stripped = line.strip()
    if not stripped.startswith("@"):
        return None
    parts = stripped.split(None, 1)
    directive = parts[0]
    arg = parts[1].strip() if len(parts) > 1 else None
    return directive, arg


def parse_template(text: str) -> TemplatePlan:
    lines = text.splitlines(keepends=True)
    nodes: list[str | ChoiceBlock] = []
    axes_order: list[tuple[str, str]] = []
    axis_by_key: dict[tuple[str, str], Axis] = {}
    text_buf: list[str] = []
    block_index = 0
    i = 0

    def flush_text() -> None:
        nonlocal text_buf
        if text_buf:
            nodes.append("".join(text_buf))
            text_buf = []

    while i < len(lines):
        parsed = parse_directive(lines[i])
        if parsed is None or parsed[0] not in ("@choice", "@flagchoice", "@flags"):
            text_buf.append(lines[i])
            i += 1
            continue

        directive, arg = parsed
        if not arg:
            raise ValueError(f"{directive} requires an axis name on line {i + 1}")
        kind = "source" if directive == "@choice" else "flags"
        name = arg
        end_directives = {"@endchoice"} if kind == "source" else {"@endflagchoice", "@endflags"}

        flush_text()
        i += 1
        cases: dict[str, str] = {}
        current_label: str | None = None
        current_lines: list[str] = []

        def finish_case() -> None:
            nonlocal current_label, current_lines
            if current_label is not None:
                cases[current_label] = "".join(current_lines)
            current_label = None
            current_lines = []

        while i < len(lines):
            inner = parse_directive(lines[i])
            if inner is not None and inner[0] == "@case":
                if not inner[1]:
                    raise ValueError(f"@case requires a label on line {i + 1}")
                finish_case()
                current_label = inner[1]
                i += 1
                continue
            if inner is not None and inner[0] in end_directives:
                finish_case()
                i += 1
                break
            if inner is not None and inner[0] in ("@choice", "@flagchoice", "@flags"):
                raise ValueError(f"nested choices are not supported near line {i + 1}")
            if current_label is None:
                if lines[i].strip():
                    raise ValueError(f"content before first @case in {directive} {name!r} near line {i + 1}")
            else:
                current_lines.append(lines[i])
            i += 1
        else:
            raise ValueError(f"unterminated {directive} {name!r}")

        key = (kind, name)
        axis = axis_by_key.get(key)
        if axis is None:
            axis = Axis(kind=kind, name=name)
            axis_by_key[key] = axis
            axes_order.append(key)
        block = ChoiceBlock(kind=kind, name=name, cases=cases, index=block_index)
        block_index += 1
        axis.blocks.append(block)
        for label in cases.keys():
            axis.add_label(label)
        if kind == "source":
            nodes.append(block)
        # flag blocks are intentionally removed from generated source.

    flush_text()
    axes = [axis_by_key[key] for key in axes_order]
    for axis in axes:
        if not axis.labels:
            raise ValueError(f"axis {axis.name!r} has no @case labels")
    return TemplatePlan(nodes=nodes, axes=axes, axis_by_key=axis_by_key)


def label_text(spec: VariantSpec, axes: list[Axis]) -> str:
    parts: list[str] = []
    for axis in axes:
        label = spec.labels[(axis.kind, axis.name)]
        prefix = "flags." if axis.kind == "flags" else "src."
        parts.append(f"{prefix}{axis.name}={label}")
    return ";".join(parts)


def expand_source(plan: TemplatePlan, spec: VariantSpec) -> str:
    chunks: list[str] = []
    for node in plan.nodes:
        if isinstance(node, str):
            chunks.append(node)
        else:
            selected = spec.labels[(node.kind, node.name)]
            chunks.append(node.cases.get(selected, ""))
    return "".join(chunks)


def expand_flags(plan: TemplatePlan, spec: VariantSpec, fmt_values: dict[str, str]) -> str:
    chunks: list[str] = []
    for axis in plan.axes:
        if axis.kind != "flags":
            continue
        selected = spec.labels[(axis.kind, axis.name)]
        for block in axis.blocks:
            content = block.cases.get(selected, "")
            if content:
                chunks.append(content)
    text = "".join(chunks)
    if text:
        text = text.format_map(SafeFormatDict(fmt_values))
    # Avoid parallel PDB collisions for debug-info variants unless the template
    # explicitly supplied /Fd.
    if re.search(r"/(Zi|ZI|Zd)\b", text, flags=re.IGNORECASE) and not re.search(r"/Fd", text, flags=re.IGNORECASE):
        text += f"\n/Fd{fmt_values['work_dir']}\\vc.pdb\n"
    return text


def flag_preset_template(preset_names: list[str]) -> str:
    if not preset_names:
        return ""
    chunks: list[str] = []
    for preset_name in preset_names:
        cases = FLAG_PRESETS[preset_name]
        axis_name = f"preset_{preset_name.replace('-', '_')}"
        chunks.append(f"\n@flagchoice {axis_name}\n")
        for label, flags in cases.items():
            chunks.append(f"@case {label}\n")
            if flags:
                chunks.append(flags)
                if not flags.endswith("\n"):
                    chunks.append("\n")
        chunks.append("@endflagchoice\n")
    return "".join(chunks)


_IDENTIFIER_RE = re.compile(r"[^A-Za-z0-9_]+")
_SLOT_RE = re.compile(r"\{\{slot:([A-Za-z_][A-Za-z0-9_]*)(?:\|indent:(\d+))?\}\}")
_VALUE_RE = re.compile(r"\{\{([A-Za-z_][A-Za-z0-9_]*)\}\}")


def sanitize_identifier(text: str) -> str:
    cleaned = _IDENTIFIER_RE.sub("_", text).strip("_")
    if not cleaned:
        return "v"
    if cleaned[0].isdigit():
        cleaned = "v_" + cleaned
    return cleaned


def available_variant_templates() -> list[tuple[str, Path]]:
    found: dict[str, Path] = {}
    for directory in VARIANT_TEMPLATE_DIRS:
        if not directory.exists():
            continue
        for ext in VARIANT_TEMPLATE_EXTENSIONS:
            for path in sorted(directory.glob(f"*{ext}")):
                found.setdefault(path.stem, path)
    return sorted(found.items())


def find_variant_template_path(name: str) -> Path:
    raw = Path(name)
    candidates: list[Path] = []
    if raw.suffix:
        if raw.is_absolute():
            candidates.append(raw)
        else:
            candidates.append(REPO_ROOT / raw)
            for directory in VARIANT_TEMPLATE_DIRS:
                candidates.append(directory / raw)
    else:
        for directory in VARIANT_TEMPLATE_DIRS:
            for ext in VARIANT_TEMPLATE_EXTENSIONS:
                candidates.append(directory / f"{name}{ext}")
    for candidate in candidates:
        if candidate.exists():
            return candidate
    searched = ", ".join(str(candidate) for candidate in candidates)
    raise ValueError(f"unknown @template preset {name!r}; searched: {searched}")


def parse_template_invocation(arg: str, line_no: int) -> tuple[str, dict[str, str]]:
    try:
        parts = shlex.split(arg, posix=True)
    except ValueError as exc:
        raise ValueError(f"invalid @template arguments on line {line_no}: {exc}") from exc
    if not parts:
        raise ValueError(f"@template requires a preset name on line {line_no}")
    name = parts[0]
    values: dict[str, str] = {}
    positionals: list[str] = []
    for part in parts[1:]:
        if "=" in part:
            key, value = part.split("=", 1)
            if not key:
                raise ValueError(f"empty @template argument key on line {line_no}")
            values[key] = value
        else:
            positionals.append(part)
    if positionals:
        values.setdefault("axis", positionals[0])
    if len(positionals) >= 2:
        values.setdefault("class", positionals[1])
    values.setdefault("template", name)
    basis = values.get("axis") or values.get("name") or name
    values.setdefault("prefix", sanitize_identifier(basis))
    values.setdefault("tmp", f"{values['prefix']}_tmp")
    values.setdefault("tmp2", f"{values['prefix']}_tmp2")
    values.setdefault("tmp3", f"{values['prefix']}_tmp3")
    values.setdefault("type", "int")
    values.setdefault("ptr", f"{values['prefix']}_ptr")
    values.setdefault("size", "16")
    values.setdefault("shift", "4")
    values.setdefault("ret", "void")
    values.setdefault("name", f"{values['prefix']}_helper")
    values.setdefault("params", "void")
    values.setdefault("index", "i")
    if "cond" in values:
        values.setdefault("inverse", f"!({values['cond']})")
    return name, values


def indent_slot_text(text: str, spaces: int) -> str:
    if spaces <= 0 or not text:
        return text
    prefix = " " * spaces
    lines = text.splitlines(keepends=True)
    return "".join((prefix + line if line.strip() else line) for line in lines)


def render_variant_template(name: str, values: dict[str, str], slots: dict[str, str], stack: tuple[str, ...]) -> tuple[str, dict]:
    if name in stack:
        chain = " -> ".join((*stack, name))
        raise ValueError(f"recursive @template expansion: {chain}")
    path = find_variant_template_path(name)
    text = path.read_text(encoding="utf-8")

    def replace_slot(match: re.Match[str]) -> str:
        slot_name = match.group(1)
        indent = int(match.group(2) or "0")
        slot_text = slots.get(slot_name, "")
        return indent_slot_text(slot_text, indent)

    expanded = _SLOT_RE.sub(replace_slot, text)

    def replace_value(match: re.Match[str]) -> str:
        key = match.group(1)
        if key not in values:
            raise ValueError(f"@template {name!r} requires argument {key!r} for {path}")
        return values[key]

    expanded = _VALUE_RE.sub(replace_value, expanded)
    record = {
        "name": name,
        "path": str(path),
        "values": values,
        "slots": sorted(slots.keys()),
    }
    return expanded, record


def expand_variant_templates(text: str, *, stack: tuple[str, ...] = ()) -> tuple[str, list[dict]]:
    """Expand @template preset directives into ordinary @choice template text."""
    if len(stack) > 20:
        raise ValueError("@template expansion exceeded maximum recursion depth")
    lines = text.splitlines(keepends=True)
    out: list[str] = []
    records: list[dict] = []
    i = 0
    while i < len(lines):
        parsed = parse_directive(lines[i])
        if parsed is None or parsed[0] != "@template":
            out.append(lines[i])
            i += 1
            continue

        directive, arg = parsed
        assert directive == "@template"
        if not arg:
            raise ValueError(f"@template requires a preset name on line {i + 1}")
        name, values = parse_template_invocation(arg, i + 1)
        slots: dict[str, str] = {}

        # A @template is block-style only when the next nonblank line is @slot.
        # Otherwise it is a single-line directive and consumes no following text.
        lookahead = i + 1
        while lookahead < len(lines) and not lines[lookahead].strip():
            lookahead += 1
        block_style = False
        if lookahead < len(lines):
            inner = parse_directive(lines[lookahead])
            block_style = inner is not None and inner[0] == "@slot"

        if not block_style:
            i += 1
        else:
            i += 1
            while i < len(lines):
                inner = parse_directive(lines[i])
                if inner is not None and inner[0] == "@endtemplate":
                    i += 1
                    break
                if inner is None or inner[0] != "@slot":
                    if lines[i].strip():
                        raise ValueError(f"content outside @slot in @template {name!r} near line {i + 1}")
                    i += 1
                    continue
                slot_name = inner[1]
                if not slot_name:
                    raise ValueError(f"@slot requires a name near line {i + 1}")
                i += 1
                slot_lines: list[str] = []
                while i < len(lines):
                    slot_end = parse_directive(lines[i])
                    if slot_end is not None and slot_end[0] == "@endslot":
                        i += 1
                        break
                    if slot_end is not None and slot_end[0] in ("@slot", "@endtemplate"):
                        raise ValueError(f"unterminated @slot {slot_name!r} in @template {name!r} near line {i + 1}")
                    slot_lines.append(lines[i])
                    i += 1
                else:
                    raise ValueError(f"unterminated @slot {slot_name!r} in @template {name!r}")
                slots[slot_name] = "".join(slot_lines)
            else:
                raise ValueError(f"unterminated block @template {name!r}")

        rendered, record = render_variant_template(name, values, slots, stack)
        nested, nested_records = expand_variant_templates(rendered, stack=(*stack, name))
        out.append(nested)
        records.append(record)
        records.extend(nested_records)
    return "".join(out), records


def make_specs(plan: TemplatePlan) -> list[VariantSpec]:
    axes = plan.axes
    label_lists = [axis.labels for axis in axes]
    specs: list[VariantSpec] = []
    for index, combo in enumerate(itertools.product(*label_lists)):
        labels = {(axis.kind, axis.name): label for axis, label in zip(axes, combo)}
        specs.append(VariantSpec(index=index, variant_id=f"V{index:06d}", labels=labels))
    return specs


def ensure_original(va_text: str, slug: str) -> Path:
    orig_bin = REPO_ROOT / "build" / "asm" / f"orig_{slug}.bin"
    if orig_bin.exists():
        return orig_bin
    result = subprocess.run(
        [sys.executable, str(REPO_ROOT / "tools" / "extract_original_function.py"), "--va", va_text],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    if result.returncode != 0:
        raise RuntimeError(result.stdout + result.stderr)
    if not orig_bin.exists():
        raise RuntimeError(f"extract_original_function.py did not create {orig_bin}")
    return orig_bin


def normalize_error(text: str, work_dir: Path, source_path: Path, obj_path: Path) -> str:
    normalized = text.replace(str(work_dir), "<work>")
    normalized = normalized.replace(str(source_path), "<source>")
    normalized = normalized.replace(str(obj_path), "<object>")
    normalized = re.sub(r"V\d{6}", "V<id>", normalized)
    normalized = re.sub(r"variant_lab[\\/][^\r\n ]+", "variant_lab/<run>", normalized)
    return normalized.strip()


def make_source_hint(*, run_dir: Path, variant_id: str, slug: str) -> str:
    return (
        "/*\n"
        " * Generated by tools/variant_lab.py.\n"
        f" * Variant: {variant_id}\n"
        f" * Run dir: {run_dir}\n"
        f" * This exact generated source is also indexed in: {run_dir / 'variants.tsv'}\n"
        f" * Variant companions: {run_dir / 'work' / variant_id / (slug + '.obj')} and optional variant_flags.rsp\n"
        f" * Unique asm groups and representative sources: {run_dir / 'groups.tsv'} and {run_dir / 'groups'}\n"
        f" * Human summary: {run_dir / 'summary.txt'}\n"
        " */\n\n"
    )


def make_group_source_hint(*, run_dir: Path, group_id: str, variant_id: str) -> str:
    return (
        "/*\n"
        " * Representative source copied by tools/variant_lab.py.\n"
        f" * Group: {group_id}\n"
        f" * Representative variant: {variant_id}\n"
        f" * Group companions: {run_dir / 'groups' / group_id / 'diff.txt'}, rebuilt.asm, rebuilt.bin\n"
        f" * Exact variant source/object: {run_dir / 'work' / variant_id}\n"
        f" * Group index: {run_dir / 'groups.tsv'}\n"
        f" * Variant index: {run_dir / 'variants.tsv'}\n"
        " */\n\n"
    )


def build_variant(
    spec: VariantSpec,
    plan: TemplatePlan,
    axes: list[Axis],
    run_dir: Path,
    work_root: Path,
    cl_path: Path,
    default_rsp: Path,
    toolchain: dict,
    original_bytes: bytes,
    expected_size: int,
    va: int,
    slug: str,
) -> VariantResult:
    labels = label_text(spec, axes)
    work_dir = work_root / spec.variant_id
    ensure_dir(work_dir)
    ensure_dir(work_dir / "tmp")
    source_path = work_dir / "source.cpp"
    obj_path = work_dir / f"{slug}.obj"
    flags_path = work_dir / "variant_flags.rsp"
    flags_path_text = ""

    fmt_values = {
        "work_dir": str(work_dir),
        "variant_id": spec.variant_id,
        "slug": slug,
        "run_dir": str(run_dir),
    }
    source = make_source_hint(run_dir=run_dir, variant_id=spec.variant_id, slug=slug) + expand_source(plan, spec)
    extra_flags = expand_flags(plan, spec, fmt_values)
    source_path.write_text(source, encoding="utf-8")
    if extra_flags.strip():
        flags_path.write_text(extra_flags, encoding="utf-8")
        flags_path_text = str(flags_path)

    command = [str(cl_path), f"@{default_rsp}"]
    if extra_flags.strip():
        command.append(f"@{flags_path}")
    command.extend([f"/Fo{obj_path}", str(source_path)])

    env = tool_env(toolchain)
    env["TEMP"] = str(work_dir / "tmp")
    env["TMP"] = str(work_dir / "tmp")

    try:
        proc = subprocess.run(command, cwd=REPO_ROOT, env=env, capture_output=True, text=True)
    except Exception as exc:  # pragma: no cover - defensive for lab robustness
        text = str(exc)
        return VariantResult(
            variant_id=spec.variant_id,
            labels_text=labels,
            status="tool_error",
            error_key=stable_hash(text),
            error_text=text,
            source_path=str(source_path),
            obj_path=str(obj_path),
            flags_path=flags_path_text,
        )

    combined_output = proc.stdout + proc.stderr
    if proc.returncode != 0 or not obj_path.exists():
        normalized = normalize_error(combined_output, work_dir, source_path, obj_path)
        return VariantResult(
            variant_id=spec.variant_id,
            labels_text=labels,
            status="compile_error",
            returncode=proc.returncode,
            error_key=stable_hash(normalized),
            error_text=normalized,
            source_path=str(source_path),
            obj_path=str(obj_path),
            flags_path=flags_path_text,
            stdout=proc.stdout,
            stderr=proc.stderr,
        )

    try:
        loaded = load_text_from_obj(obj_path)
    except Exception as exc:
        text = normalize_error(str(exc), work_dir, source_path, obj_path)
        return VariantResult(
            variant_id=spec.variant_id,
            labels_text=labels,
            status="extract_error",
            returncode=proc.returncode,
            error_key=stable_hash(text),
            error_text=text,
            source_path=str(source_path),
            obj_path=str(obj_path),
            flags_path=flags_path_text,
            stdout=proc.stdout,
            stderr=proc.stderr,
        )

    compare_bytes = loaded.data[:expected_size]
    compare_relocs = [reloc for reloc in loaded.relocations if reloc.offset < len(compare_bytes)]
    masked_rebuilt = mask_relocations(compare_bytes, compare_relocs)
    masked_original = bytearray(original_bytes[:expected_size])
    for reloc in compare_relocs:
        start = reloc.offset
        end = min(len(masked_original), start + reloc.width)
        if 0 <= start < len(masked_original):
            for i in range(start, end):
                masked_original[i] = 0
    masked_original_bytes = bytes(masked_original)

    mismatch = first_mismatch(masked_original_bytes, masked_rebuilt)
    exact = mismatch is None and len(compare_bytes) == expected_size
    status = "match" if exact else "mismatch"
    ret_ends = detect_ret_ends(loaded.data)
    last_ret_end = ret_ends[-1] if ret_ends else None
    extra_after_last_ret = (len(loaded.data) - last_ret_end) if last_ret_end is not None else None
    likely_context_tail = (
        last_ret_end is not None
        and last_ret_end < expected_size
        and len(loaded.data) > last_ret_end
    )

    masked_full_rebuilt = mask_relocations(loaded.data, loaded.relocations)
    group_material = b"\0".join(
        [
            str(len(loaded.data)).encode("ascii"),
            masked_full_rebuilt,
        ]
    )
    group_key = stable_hash(group_material)

    return VariantResult(
        variant_id=spec.variant_id,
        labels_text=labels,
        status=status,
        returncode=proc.returncode,
        text_size=len(loaded.data),
        compare_size=len(compare_bytes),
        relocations=len(compare_relocs),
        first_mismatch=mismatch,
        exact=exact,
        ret_count=len(ret_ends),
        last_ret_end=last_ret_end,
        extra_after_last_ret=extra_after_last_ret,
        likely_context_tail=likely_context_tail,
        group_key=group_key,
        source_path=str(source_path),
        obj_path=str(obj_path),
        flags_path=flags_path_text,
        stdout=proc.stdout,
        stderr=proc.stderr,
    )


def interesting_sort_key(group: GroupInfo, expected_size: int) -> tuple[int, int, int, int, int]:
    if group.exact:
        return (0, 0, 0, 0, -group.count)
    first = group.first_mismatch if group.first_mismatch is not None else -1
    text_size = group.text_size or 0
    # Prefer true exact-size groups first; long/short groups can have a useful
    # first-mismatch after truncation, but exact function size is usually a
    # stronger signal during matching work.
    exact_text_penalty = 0 if text_size == expected_size else 1
    size_distance = abs(text_size - expected_size)
    return (1, exact_text_penalty, size_distance, -first, -group.count)


def write_asm(path: Path, code: bytes, va: int) -> None:
    asm_lines = decode_bytes(code, va)
    path.write_text(
        "\n".join(f"{line['address']}  {line['bytes']:<16}  {line['text']}" for line in asm_lines) + "\n",
        encoding="utf-8",
    )


def write_group_artifacts(
    groups: list[GroupInfo],
    run_dir: Path,
    original_bytes: bytes,
    original_asm_path: Path,
    expected_size: int,
    va: int,
) -> None:
    groups_dir = run_dir / "groups"
    ensure_dir(groups_dir)
    original_asm_lines = []
    if original_asm_path.exists():
        original_asm_lines = original_asm_path.read_text(encoding="utf-8").splitlines()

    for group in groups:
        rep = group.representative
        if rep is None or not rep.obj_path:
            continue
        group_dir = groups_dir / group.group_id
        ensure_dir(group_dir)
        source_path = Path(rep.source_path or "")
        obj_path = Path(rep.obj_path)
        if source_path.exists():
            representative_text = source_path.read_text(encoding="utf-8", errors="replace")
            (group_dir / "representative.cpp").write_text(
                make_group_source_hint(run_dir=run_dir, group_id=group.group_id, variant_id=rep.variant_id)
                + representative_text,
                encoding="utf-8",
            )
        if rep.flags_path and Path(rep.flags_path).exists():
            shutil.copyfile(rep.flags_path, group_dir / "variant_flags.rsp")
        try:
            loaded = load_text_from_obj(obj_path)
        except Exception as exc:
            (group_dir / "extract_error.txt").write_text(str(exc), encoding="utf-8")
            continue
        compare_bytes = loaded.data[:expected_size]
        (group_dir / "rebuilt.bin").write_bytes(compare_bytes)
        write_asm(group_dir / "rebuilt.asm", compare_bytes, va)

        rebuilt_lines = (group_dir / "rebuilt.asm").read_text(encoding="utf-8").splitlines()
        diff_lines: list[str] = []
        diff_lines.append(f"Group: {group.group_id}")
        diff_lines.append(f"Count: {group.count}")
        diff_lines.append(f"Representative: {rep.variant_id}")
        diff_lines.append(f"Labels: {rep.labels_text}")
        diff_lines.append(f"Representative source: {group_dir / 'representative.cpp'}")
        diff_lines.append(f"Exact variant source: {rep.source_path}")
        diff_lines.append(f"Variant index: {run_dir / 'variants.tsv'}")
        diff_lines.append(f"Group index: {run_dir / 'groups.tsv'}")
        diff_lines.append(f"Text size: {rep.text_size}")
        diff_lines.append(f"Compared bytes: {rep.compare_size}")
        diff_lines.append(f"Relocations masked: {rep.relocations}")
        diff_lines.append(f"First mismatch: {rep.first_mismatch}")
        diff_lines.append(f"Return instructions: {rep.ret_count}")
        diff_lines.append(f"Last return end offset: {rep.last_ret_end}")
        diff_lines.append(f"Extra bytes after last return: {rep.extra_after_last_ret}")
        diff_lines.append(f"Likely appended-context tail before expected end: {int(rep.likely_context_tail)}")
        diff_lines.append("")
        if original_asm_lines:
            diff_lines.append("Asm diff:")
            diff_lines.extend(
                list(
                    difflib.unified_diff(
                        original_asm_lines,
                        rebuilt_lines,
                        fromfile=original_asm_path.name,
                        tofile="rebuilt.asm",
                        lineterm="",
                    )
                )[:240]
            )
        (group_dir / "diff.txt").write_text("\n".join(diff_lines) + "\n", encoding="utf-8")


def instruction_at_offset(lines: list[dict], offset: int, va: int) -> dict | None:
    for line in lines:
        start = int(line["address"], 16) - va
        end = start + len(bytes.fromhex(line["bytes"]))
        if start <= offset < end:
            return line
    return None


def group_mismatch_snippet(group: GroupInfo, original_bytes: bytes, expected_size: int, va: int) -> list[str]:
    rep = group.representative
    if rep is None or not rep.obj_path or rep.first_mismatch is None:
        return []
    obj_path = Path(rep.obj_path)
    if not obj_path.exists():
        return []
    try:
        loaded = load_text_from_obj(obj_path)
    except Exception as exc:
        return [f"        snippet unavailable: {exc}"]

    compare_bytes = loaded.data[:expected_size]
    compare_relocs = [reloc for reloc in loaded.relocations if reloc.offset < len(compare_bytes)]
    masked_rebuilt = mask_relocations(compare_bytes, compare_relocs)
    masked_original = bytearray(original_bytes[:expected_size])
    for reloc in compare_relocs:
        start = reloc.offset
        end = min(len(masked_original), start + reloc.width)
        if 0 <= start < len(masked_original):
            for i in range(start, end):
                masked_original[i] = 0
    masked_original_bytes = bytes(masked_original)

    mismatch = rep.first_mismatch
    window_start = max(0, mismatch - 8)
    window_end = min(max(len(masked_original_bytes), len(masked_rebuilt)), mismatch + 8)
    orig_window = masked_original_bytes[window_start:window_end].hex()
    rebuilt_window = masked_rebuilt[window_start:window_end].hex()

    original_lines = decode_bytes(original_bytes[: min(expected_size, len(original_bytes))], va)
    rebuilt_lines = decode_bytes(compare_bytes, va)
    orig_ins = instruction_at_offset(original_lines, mismatch, va)
    rebuilt_ins = instruction_at_offset(rebuilt_lines, mismatch, va)

    lines = [
        f"        mismatch window original: {orig_window}",
        f"        mismatch window rebuilt : {rebuilt_window}",
    ]
    if orig_ins is not None:
        lines.append(f"        orig asm: {orig_ins['address']}  {orig_ins['bytes']:<16}  {orig_ins['text']}")
    if rebuilt_ins is not None:
        lines.append(f"        reb  asm: {rebuilt_ins['address']}  {rebuilt_ins['bytes']:<16}  {rebuilt_ins['text']}")
    return lines


def write_reports(
    *,
    run_dir: Path,
    slug: str,
    va_text: str,
    specs: list[VariantSpec],
    axes: list[Axis],
    results: list[VariantResult],
    original_bytes: bytes,
    expected_size: int,
    started_at: float,
    template_expansions: list[dict] | None = None,
) -> None:
    group_map: dict[str, GroupInfo] = {}
    error_map: dict[str, ErrorGroup] = {}

    for result in results:
        if result.group_key:
            group = group_map.get(result.group_key)
            if group is None:
                group = GroupInfo(
                    group_id=f"G{len(group_map):04d}",
                    key=result.group_key,
                    representative=result,
                    text_size=result.text_size,
                    compare_size=result.compare_size,
                    relocations=result.relocations,
                    first_mismatch=result.first_mismatch,
                    exact=result.exact,
                    ret_count=result.ret_count,
                    last_ret_end=result.last_ret_end,
                    extra_after_last_ret=result.extra_after_last_ret,
                    likely_context_tail=result.likely_context_tail,
                )
                group_map[result.group_key] = group
            group.count += 1
            if result.exact and not group.exact:
                group.exact = True
                group.representative = result
        elif result.error_key:
            error = error_map.get(result.error_key)
            if error is None:
                error = ErrorGroup(
                    error_id=f"E{len(error_map):04d}",
                    key=result.error_key,
                    representative=result,
                    text=result.error_text,
                )
                error_map[result.error_key] = error
            error.count += 1

    groups = list(group_map.values())
    groups.sort(key=lambda group: interesting_sort_key(group, expected_size))
    for index, group in enumerate(groups):
        group.group_id = f"G{index:04d}"

    key_to_group_id = {group.key: group.group_id for group in groups}

    errors = list(error_map.values())
    errors.sort(key=lambda error: (-error.count, error.error_id))
    for index, error in enumerate(errors):
        error.error_id = f"E{index:04d}"
    key_to_error_id = {error.key: error.error_id for error in errors}

    # Variants TSV
    with (run_dir / "variants.tsv").open("w", encoding="utf-8", newline="") as f:
        f.write(
            "variant_id\tstatus\tgroup_id\terror_id\texact\ttext_size\tcompare_size\tfirst_mismatch\trelocations\tret_count\tlast_ret_end\textra_after_last_ret\tlikely_context_tail\tlabels\tsource\tobject\tflags\n"
        )
        for result in results:
            group_id = key_to_group_id.get(result.group_key or "", "")
            error_id = key_to_error_id.get(result.error_key or "", "")
            f.write(
                "\t".join(
                    [
                        result.variant_id,
                        result.status,
                        group_id,
                        error_id,
                        "1" if result.exact else "0",
                        "" if result.text_size is None else str(result.text_size),
                        "" if result.compare_size is None else str(result.compare_size),
                        "" if result.first_mismatch is None else str(result.first_mismatch),
                        str(result.relocations),
                        str(result.ret_count),
                        "" if result.last_ret_end is None else str(result.last_ret_end),
                        "" if result.extra_after_last_ret is None else str(result.extra_after_last_ret),
                        "1" if result.likely_context_tail else "0",
                        result.labels_text,
                        result.source_path or "",
                        result.obj_path or "",
                        result.flags_path or "",
                    ]
                )
                + "\n"
            )

    # Groups TSV and per-group variant lists.
    with (run_dir / "groups.tsv").open("w", encoding="utf-8", newline="") as f:
        f.write("group_id\tcount\texact\ttext_size\tcompare_size\tfirst_mismatch\trelocations\tret_count\tlast_ret_end\textra_after_last_ret\tlikely_context_tail\trepresentative\tlabels\thash\n")
        for group in groups:
            rep = group.representative
            f.write(
                "\t".join(
                    [
                        group.group_id,
                        str(group.count),
                        "1" if group.exact else "0",
                        "" if group.text_size is None else str(group.text_size),
                        "" if group.compare_size is None else str(group.compare_size),
                        "" if group.first_mismatch is None else str(group.first_mismatch),
                        str(group.relocations),
                        str(group.ret_count),
                        "" if group.last_ret_end is None else str(group.last_ret_end),
                        "" if group.extra_after_last_ret is None else str(group.extra_after_last_ret),
                        "1" if group.likely_context_tail else "0",
                        rep.variant_id if rep else "",
                        rep.labels_text if rep else "",
                        group.key,
                    ]
                )
                + "\n"
            )

    with (run_dir / "compile_errors.tsv").open("w", encoding="utf-8", newline="") as f:
        f.write("error_id\tcount\trepresentative\tlabels\terror\n")
        for error in errors:
            rep = error.representative
            one_line = error.text.replace("\r", " ").replace("\n", " | ")
            f.write(
                "\t".join(
                    [
                        error.error_id,
                        str(error.count),
                        rep.variant_id if rep else "",
                        rep.labels_text if rep else "",
                        one_line,
                    ]
                )
                + "\n"
            )

    # Copy matches explicitly.
    matches_dir = run_dir / "matches"
    exact_results = [result for result in results if result.exact]
    if exact_results:
        ensure_dir(matches_dir)
        for index, result in enumerate(exact_results):
            match_dir = matches_dir / f"match_{index:04d}_{result.variant_id}"
            ensure_dir(match_dir)
            if result.source_path and Path(result.source_path).exists():
                match_source = Path(result.source_path).read_text(encoding="utf-8", errors="replace")
                (match_dir / "source.cpp").write_text(
                    "/*\n"
                    " * Exact-match source copied by tools/variant_lab.py.\n"
                    f" * Match: match_{index:04d}_{result.variant_id}\n"
                    f" * Original variant source/object: {run_dir / 'work' / result.variant_id}\n"
                    f" * Variant index: {run_dir / 'variants.tsv'}\n"
                    f" * Summary: {run_dir / 'summary.txt'}\n"
                    " */\n\n"
                    + match_source,
                    encoding="utf-8",
                )
            if result.flags_path and Path(result.flags_path).exists():
                shutil.copyfile(result.flags_path, match_dir / "variant_flags.rsp")
            (match_dir / "labels.txt").write_text(result.labels_text + "\n", encoding="utf-8")

    original_asm_path = REPO_ROOT / "build" / "asm" / f"orig_{slug}.txt"
    write_group_artifacts(groups[:50], run_dir, original_bytes, original_asm_path, expected_size, int(va_text, 16))

    elapsed = time.time() - started_at
    compile_ok = sum(1 for result in results if result.status in ("match", "mismatch"))
    compile_errors = sum(1 for result in results if result.status == "compile_error")
    extract_errors = sum(1 for result in results if result.status == "extract_error")
    tool_errors = sum(1 for result in results if result.status == "tool_error")

    size_hist: dict[str, int] = {}
    for result in results:
        if result.text_size is not None:
            size_hist[str(result.text_size)] = size_hist.get(str(result.text_size), 0) + 1
    size_hist_items = sorted(size_hist.items(), key=lambda item: (int(item[0]), item[1]))

    summary: list[str] = []
    summary.append(f"Variant lab: {slug} ({va_text})")
    summary.append(f"Run dir: {run_dir}")
    summary.append(f"Elapsed: {elapsed:.2f}s")
    summary.append(f"Variants generated: {len(specs)}")
    summary.append(f"Compile OK: {compile_ok}")
    summary.append(f"Compile errors: {compile_errors}")
    summary.append(f"Extract errors: {extract_errors}")
    summary.append(f"Tool errors: {tool_errors}")
    summary.append(f"Unique asm groups: {len(groups)}")
    summary.append(f"Exact matches: {len(exact_results)}")
    preset_axes = [axis.name[len("preset_") :].replace("_", "-") for axis in axes if axis.kind == "flags" and axis.name.startswith("preset_")]
    if preset_axes:
        summary.append(f"Flag presets: {', '.join(preset_axes)}")
        summary.append("Note: preset flags are appended after default.rsp and are for classification; non-default-flag matches need normal review.")
    if template_expansions:
        summary.append("Template presets: " + ", ".join(record["name"] for record in template_expansions))
    summary.append("")
    summary.append("Axes:")
    for axis in axes:
        prefix = "flags" if axis.kind == "flags" else "source"
        summary.append(f"  {prefix}.{axis.name}: {', '.join(axis.labels)}")
    summary.append("")
    summary.append("Text-size histogram:")
    if size_hist_items:
        for size, count in size_hist_items:
            summary.append(f"  {size}: {count}")
    else:
        summary.append("  <none>")
    summary.append("")
    summary.append("Top groups:")
    for group in groups[:20]:
        rep = group.representative
        tail_note = " context-tail" if group.likely_context_tail else ""
        summary.append(
            f"  {group.group_id} count={group.count} exact={int(group.exact)} text_size={group.text_size} "
            f"compare_size={group.compare_size} first_mismatch={group.first_mismatch} reloc={group.relocations} "
            f"last_ret_end={group.last_ret_end} extra_after_ret={group.extra_after_last_ret}{tail_note}"
        )
        if rep:
            summary.append(f"        example: {rep.variant_id} {rep.labels_text}")
            summary.append(f"        artifacts: groups/{group.group_id}/")
            if group.first_mismatch is not None:
                summary.extend(group_mismatch_snippet(group, original_bytes, expected_size, int(va_text, 16)))

    deepest_groups = [group for group in groups if group.first_mismatch is not None]
    deepest_groups.sort(key=lambda group: (group.first_mismatch or -1, -(abs((group.text_size or 0) - expected_size))), reverse=True)
    if deepest_groups:
        summary.append("")
        summary.append("Deepest first mismatches:")
        for group in deepest_groups[:10]:
            rep = group.representative
            tail_note = " context-tail" if group.likely_context_tail else ""
            summary.append(
                f"  {group.group_id} count={group.count} text_size={group.text_size} first_mismatch={group.first_mismatch}"
                f" last_ret_end={group.last_ret_end}{tail_note}"
            )
            if rep:
                summary.append(f"        example: {rep.variant_id} {rep.labels_text}")
                summary.append(f"        artifacts: groups/{group.group_id}/")
                summary.extend(group_mismatch_snippet(group, original_bytes, expected_size, int(va_text, 16)))

    context_tail_groups = sum(1 for group in groups if group.likely_context_tail)
    if context_tail_groups:
        summary.append("")
        summary.append(
            f"Warning: {context_tail_groups} groups look like appended TU/context code begins before the expected target size; "
            "treat their text_size/late bytes carefully."
        )

    if errors:
        summary.append("")
        top_error = errors[0]
        error_total = compile_errors + extract_errors + tool_errors
        if error_total and top_error.count == error_total:
            rep = top_error.representative
            summary.append("LIKELY TEMPLATE STRUCTURE ERROR: all failed variants share the same error group.")
            summary.append(f"  Error group: {top_error.error_id}")
            summary.append(f"  Representative: {rep.variant_id if rep else ''}")
            if rep and rep.source_path:
                summary.append(f"  Representative source: {rep.source_path}")
            summary.append("  This usually means the generated C/C++ structure is wrong, not that one case is bad.")
        elif len(specs) and top_error.count / len(specs) >= 0.80:
            rep = top_error.representative
            summary.append("LIKELY TEMPLATE STRUCTURE ERROR: more than 80% of variants share one error group.")
            summary.append(f"  Error group: {top_error.error_id} count={top_error.count}/{len(specs)}")
            summary.append(f"  Representative: {rep.variant_id if rep else ''}")
            if rep and rep.source_path:
                summary.append(f"  Representative source: {rep.source_path}")
            summary.append("  Inspect this generated source before continuing the lab.")
        summary.append("")
        summary.append("Compile/extract error groups:")
        for error in errors[:10]:
            rep = error.representative
            text = error.text.replace("\r", " ").replace("\n", " | ")[:240]
            summary.append(f"  {error.error_id} count={error.count} example={rep.variant_id if rep else ''} {text}")

    (run_dir / "summary.txt").write_text("\n".join(summary) + "\n", encoding="utf-8")
    manifest = {
        "slug": slug,
        "va": va_text,
        "run_dir": str(run_dir),
        "elapsed_seconds": elapsed,
        "variants": len(specs),
        "compile_ok": compile_ok,
        "compile_errors": compile_errors,
        "extract_errors": extract_errors,
        "tool_errors": tool_errors,
        "unique_groups": len(groups),
        "exact_matches": len(exact_results),
        "flag_presets": [axis.name[len("preset_") :].replace("_", "-") for axis in axes if axis.kind == "flags" and axis.name.startswith("preset_")],
        "template_expansions": template_expansions or [],
        "axes": [
            {"kind": axis.kind, "name": axis.name, "labels": axis.labels, "blocks": len(axis.blocks)} for axis in axes
        ],
    }
    (run_dir / "manifest.json").write_text(json.dumps(manifest, indent=2), encoding="utf-8")

    print("\n".join(summary))


def parse_args(argv: list[str]) -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Blast through source/flag variants for one function and group emitted-code results.",
        epilog=HELP_EPILOG,
        formatter_class=argparse.RawDescriptionHelpFormatter,
    )
    parser.add_argument("--va", help="Function VA in hex, e.g. 0051ACA0")
    parser.add_argument("--template", help="Full-source template path, or '-' for stdin")
    parser.add_argument(
        "--flag-preset",
        action="append",
        choices=sorted(FLAG_PRESETS.keys()),
        default=[],
        help="Append a reusable flag-axis preset (repeatable). Available: " + ", ".join(sorted(FLAG_PRESETS.keys())),
    )
    parser.add_argument("--init", action="store_true", help="Create build/temp/<slug>_lab.tpl.cpp from the preferred source and exit")
    parser.add_argument(
        "--max-variants",
        type=int,
        default=DEFAULT_MAX_VARIANTS,
        help=f"Maximum expanded variants before refusing the run (default: {DEFAULT_MAX_VARIANTS}; 0 disables the cap).",
    )
    parser.add_argument("--list-templates", action="store_true", help="List reusable @template presets and exit")
    return parser.parse_args(argv)


def init_template(va_text: str) -> Path:
    va = int(va_text, 16)
    record = function_record_by_va(va)
    slug = function_slug(record)
    source = preferred_source_path(record)
    if not source.exists():
        raise SystemExit(f"preferred source does not exist: {source}")
    out_dir = REPO_ROOT / "build" / "temp"
    ensure_dir(out_dir)
    out_path = out_dir / f"{slug}_lab.tpl.cpp"
    if out_path.exists():
        raise SystemExit(f"template already exists: {out_path}")
    shutil.copyfile(source, out_path)
    print(f"Wrote {out_path}")
    return out_path


def main(argv: list[str] | None = None) -> int:
    if argv is None:
        argv = sys.argv[1:]
    if not argv:
        parse_args(["--help"])
        return 0
    args = parse_args(argv)
    if args.list_templates:
        for name, path in available_variant_templates():
            print(f"{name}\t{path}")
        return 0
    if not args.va:
        raise SystemExit("--va is required unless --list-templates is used")
    va_text = format_hex(int(args.va, 16))

    if args.init:
        init_template(va_text)
        return 0
    if not args.template:
        raise SystemExit("--template is required unless --init is used")

    va = int(va_text, 16)
    record = function_record_by_va(va)
    slug = function_slug(record)
    expected_size = int(record["size_bytes"])

    if args.template == "-":
        template_text = sys.stdin.read()
        template_name = "stdin"
    else:
        template_path = repo_path(args.template)
        template_text = template_path.read_text(encoding="utf-8")
        template_name = str(template_path)

    preset_text = flag_preset_template(args.flag_preset)
    raw_effective_template_text = template_text + preset_text
    try:
        effective_template_text, template_expansions = expand_variant_templates(raw_effective_template_text)
    except ValueError as exc:
        raise SystemExit(f"template expansion error: {exc}") from exc

    plan = parse_template(effective_template_text)
    specs = make_specs(plan)
    if not specs:
        raise SystemExit("no variants generated")
    if args.max_variants != 0 and len(specs) > args.max_variants:
        raise SystemExit(
            f"template expands to {len(specs)} variants, exceeding --max-variants {args.max_variants}. "
            "Raise the cap or pass --max-variants 0 for an intentional huge run."
        )

    toolchain = load_toolchain()
    cl_path = repo_path(toolchain["compiler"]["cl"])
    default_rsp = CONFIG_DIR / "flags" / "default.rsp"
    if not default_rsp.exists():
        default_rsp = repo_path(toolchain["compiler"]["default_rsp"])

    orig_bin = ensure_original(va_text, slug)
    original_bytes = orig_bin.read_bytes()
    if len(original_bytes) != expected_size:
        raise SystemExit(f"original byte size {len(original_bytes)} does not match expected {expected_size}")

    timestamp = time.strftime("%Y%m%d_%H%M%S")
    run_dir = REPO_ROOT / "build" / "variant_lab" / slug / timestamp
    work_root = run_dir / "work"
    ensure_dir(work_root)
    (run_dir / "template_input.cpp").write_text(template_text, encoding="utf-8")
    if preset_text:
        (run_dir / "flag_presets.tpl").write_text(preset_text, encoding="utf-8")
    if preset_text or template_expansions:
        (run_dir / "effective_template_input.cpp").write_text(effective_template_text, encoding="utf-8")
    if template_expansions:
        (run_dir / "template_expansions.json").write_text(json.dumps(template_expansions, indent=2), encoding="utf-8")

    workers = max(1, (os.cpu_count() or 2) - 1)
    print(f"Variant lab for {slug} ({va_text})")
    print(f"Template: {template_name}")
    if args.flag_preset:
        print(f"Flag presets: {', '.join(args.flag_preset)}")
    if template_expansions:
        print("Template presets: " + ", ".join(record["name"] for record in template_expansions))
    print(f"Run dir: {run_dir}")
    print(f"Variants: {len(specs)}")
    print(f"Workers: {workers}")

    started_at = time.time()
    results: list[VariantResult] = []
    with concurrent.futures.ThreadPoolExecutor(max_workers=workers) as executor:
        future_to_spec = {
            executor.submit(
                build_variant,
                spec,
                plan,
                plan.axes,
                run_dir,
                work_root,
                cl_path,
                default_rsp,
                toolchain,
                original_bytes,
                expected_size,
                va,
                slug,
            ): spec
            for spec in specs
        }
        completed = 0
        for future in concurrent.futures.as_completed(future_to_spec):
            completed += 1
            try:
                results.append(future.result())
            except Exception as exc:  # pragma: no cover - defensive for lab robustness
                spec = future_to_spec[future]
                text = str(exc)
                results.append(
                    VariantResult(
                        variant_id=spec.variant_id,
                        labels_text=label_text(spec, plan.axes),
                        status="tool_error",
                        error_key=stable_hash(text),
                        error_text=text,
                    )
                )
            if completed == len(specs) or completed % max(1, len(specs) // 20) == 0:
                print(f"  completed {completed}/{len(specs)}")

    results.sort(key=lambda result: result.variant_id)
    write_reports(
        run_dir=run_dir,
        slug=slug,
        va_text=va_text,
        specs=specs,
        axes=plan.axes,
        results=results,
        original_bytes=original_bytes,
        expected_size=expected_size,
        started_at=started_at,
        template_expansions=template_expansions,
    )
    return 0 if any(result.exact for result in results) else 1


if __name__ == "__main__":
    raise SystemExit(main())
