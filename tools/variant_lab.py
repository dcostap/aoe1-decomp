"""Variant lab tool. Run `python tools/variant_lab.py --help` for syntax and usage details."""

from __future__ import annotations

import argparse
import concurrent.futures
import difflib
import hashlib
import json
import os
import re
import shutil
import shlex
import struct
import subprocess
import sys
import time
from collections import Counter
from dataclasses import dataclass, field, replace
from pathlib import Path
from typing import Iterable

from coff import find_function_symbol, function_symbol_section, load_coff_object
from common import (
    CONFIG_DIR,
    REPO_ROOT,
    edit_diff_metrics,
    ensure_dir,
    format_hex,
    function_record_by_va,
    function_slug,
    load_toolchain,
    positional_byte_diff_metrics,
    preferred_source_path,
    repo_path,
    tool_env,
)
from extract_obj_function import decode_bytes, extraction_extent
from function_diagnostics import (
    basic_blocks,
    block_alignment,
    call_fingerprint,
    decode_instructions,
    prologue_summary,
)
from target_session import current_metric_summary, record_probe, require_clean_baseline


# Variant labs are intentionally allowed to get large: sticky VC5 codegen-family
# problems are often cheaper to solve with broad structured sweeps than with
# hours of manual churn. Keep a high default cap so accidental million-variant
# explosions still fail early; pass --max-variants 0 to disable the cap.
DEFAULT_MAX_VARIANTS = 250_000
DEFAULT_AMBIENT_SAMPLES = 512
DEFAULT_COMPILE_TIMEOUT_SECONDS = 120.0

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
Variant lab template reference
==============================

variant_lab compiles a full C/C++ source template many times, compares each
emitted object against one original function, and groups variants by emitted
machine code. It never edits the natural source module. Generated files go to
build/variant_lab/<slug>/<run-id>/. Compile runs add the repository, include/,
src/, and legacy source-bank include roots.

Use it for late-stage VC5 source-shape/codegen-basin work after behavior is
mostly understood. Matches still need normal review, reduction, and local
check_function validation before promotion. Rankings measure emitted-code
proximity, not source quality. A leased `--session-owner` compile requires the
session's pinned clean-source checkpoint; generated variants never replace it.

Quick workflow
--------------

  python tools/variant_lab.py --init --va 0051ACA0
  # edit build/temp/<slug>_lab.tpl.cpp
  python tools/variant_lab.py --template build/temp/<slug>_lab.tpl.cpp --preview-variants 3
  # add --preview-full only when complete generated sources are really needed
  python tools/variant_lab.py --va 0051ACA0 --template build/temp/<slug>_lab.tpl.cpp --session-owner AgentName

Inspection commands (no compile; --va not required):

  python tools/variant_lab.py --list-templates
  python tools/variant_lab.py --template-help vc5_guard
  python tools/variant_lab.py --template build/temp/lab.tpl.cpp --expand-only
  python tools/variant_lab.py --template build/temp/lab.tpl.cpp --preview-variants 3
  python tools/variant_lab.py --template build/temp/lab.tpl.cpp --preview-variants 1 --preview-full
  python tools/variant_lab.py --template build/temp/lab.tpl.cpp --show-variant V000042

Source choices
--------------

  @choice axis_name
  @case case_label
      source emitted when axis_name=case_label
  @case other_label
      alternate source
  @endchoice

Active axes select one case. Reusing the same axis name links choices together;
if a later active block omits the selected label, that block emits nothing.
Duplicate @case labels in one block are rejected.

Ambient declaration sweeps
--------------------------

Insert a deterministic file-scope declaration-count axis at the directive site:

  @ambient_declarations ambient samples=512 seed=aoe1

Sample n0000 emits no declarations. Sample n0001 emits one declaration, and so
on. Every later sample retains the prior declarations. This tests whether VC5
code generation changes with ambient front-end declaration state. The directive
keeps the generated preamble's line count constant across samples. It is
diagnostic only. A matching generated preamble does not prove original source.

Optional `prefix=NAME` controls the neutral generated struct-name prefix. The
default sample count is 512. Place the directive after includes and before the
target function or its supporting declarations.

Localized splice templates
--------------------------

For giant functions, a template may contain only the region being varied. Two
unique marker lines in an unchanged full source delimit the replacement:

  python tools/variant_lab.py --va 004F21F0 --template build/temp/gate.tpl.cpp \
    --splice-base src/taitacmd.cpp \
    --splice-start "// LAB START gate" --splice-end "// LAB END gate"

The marker lines remain in the generated source; text between them is replaced by
the fragment before @choice expansion. Preview/show/expand modes support the same
options, so the full spliced source can be inspected before compiling.

Choices may be nested inside @case bodies. Nested axes are active only when their
parent case is selected, so this generates 3 variants, not 4:

  @choice outer
  @case a
      @choice inner
      @case x
      int x = 1;
      @case y
      int x = 2;
      @endchoice
  @case b
      int x = 3;
  @endchoice

Labels would be: src.outer=a;src.inner=x, src.outer=a;src.inner=y, src.outer=b.
Inactive nested axes are omitted from labels/reports.

Reusable @template presets
--------------------------

Preset files live in config/variant_templates/ (preferred) or tools/variant_templates/.
They are plain text .vtpl/.tpl/.txt files expanded to ordinary @choice/@flagchoice
text before parsing. Each preset starts with a short TEMPLATE comment explaining
why it exists; `--template-help NAME` prints that metadata. Add cases/files there
as reusable VC5 lessons appear.

Single-line preset:

  @template vc5_dummy_member_surface axis=member_ctx class=Path prefix=ctx

Block preset with user slot:

  @template vc5_guard axis=gate cond="maxSizeValue < other.maxSizeValue"
  @slot body
      setMaxSize(other.maxSizeValue);
  @endslot
  @endtemplate

Arguments use shell-style key=value parsing; quote expressions with spaces.
Inside preset files use {{axis}}, {{class}}, {{prefix}}, etc. for arguments and
{{slot:body}} for user slots. Slot filters may be chained:

  {{slot:body|trim|indent:4}}   filters: trim, lstrip, rstrip/chomp, indent:N

Useful default arguments supplied by the lab:

  prefix=<sanitized axis/name>, tmp=<prefix>_tmp, tmp2=<prefix>_tmp2,
  tmp3=<prefix>_tmp3, type=int, ptr=<prefix>_ptr, size=16, shift=4,
  ret=void, name=<prefix>_helper, params=void, index=i,
  inverse=!(<cond>) when cond=... is supplied.

Starter preset families:

  vc5_dummy_member_surface  dummy class member declarations / ctor/dtor/operator context
  vc5_update_expr           +=, x=x+y, temp update spellings
  vc5_guard                 guarded body forms, no-brace forms, inverted empty arms
  vc5_store_order2/3/4      permute independent statements/stores
  vc5_decl_init_order2      separate local declaration order from init order
  vc5_call_result_test      direct call-test vs named result locals / result width
  vc5_byte_select           condition-to-byte/value selection spellings
  vc5_pointer_local_use     direct access vs pointer local lifetime shapes
  vc5_loop_count            counted-loop spellings around a body slot
  vc5_loop_access_shape     index loop vs running-entry local variants
  vc5_alloc                 operator_new/new[], count temps, byte-size temps
  vc5_assign_temp           direct expression use versus named-temp lifetime variants
  vc5_bool_return           direct bool return vs explicit 0/1 branches/narrow temps
  vc5_vtable_pad_surface    neutral dummy virtual slots for vtable offset probes
  vc5_dtor_surface          destructor/class-surface declaration variants
  vc5_ctor_init_zero_surface ctor init-list vs body zeroing variants
  vc5_stack_array_shape     stack array size/layout variants
  vc5_helper_extract        helper/declaration surface experiments
  vc5_standard_headers      standard-header on/off axes

Compiler flag choices
---------------------

  @flagchoice flags_axis
  @case default
  @case debug_lines
  /Zd
  @endflagchoice

or equivalently @flags ... @endflags. Flag case text is removed from generated
C/C++ and written to per-variant variant_flags.rsp after config/flags/default.rsp.
Debug-info variants get a unique /Fd path when needed.

Flag case placeholders:

  {work_dir}  {variant_id}  {slug}  {run_dir}

Reusable flag axes:

  --flag-preset vc5-small
  --flag-preset vc5-risky
  --flag-preset vc5-debug-context

Flag presets are classification tools, not promotion policy. Non-default-flag
matches need normal review and justification.

Run controls
------------

  --max-variants N     refuse larger expanded labs (default 250000)
  --max-variants 0     disable the cap for an intentional huge run
  --no-dedupe-expanded compile identical expanded source/flag variants separately
  --focus-range A-B    score one inclusive original offset/VA band
  --require-size       reject leads with the wrong checker-effective function size
  --require-frame      require the original prologue frame size
  --require-call-set   require direct/virtual/indirect target counts and COFF symbol identity
  --session-owner NAME record one meaningful `variant` probe for the whole lab family
  --compile-timeout S stop one compiler job after S seconds; 0 disables the limit

Identical expanded source+flags are deduped before compile by default. Duplicate
work dirs contain dedup_alias.txt pointing to the representative object.
`--preview-variants` is compact by default (labels, sizes, and hashes only);
`--preview-full` opts into printing complete generated source.

Output and reports
------------------

Each compile run writes build/variant_lab/<slug>/<run-id>/ with:

  summary.txt            start here: counts, axes, sensitivity, top groups
  manifest.json          machine-readable run metadata
  variants.tsv           every expanded variant and artifact path
  groups.tsv             one row per unique emitted-code group
  axis_sensitivity.tsv   per-axis exact/mismatch/error counts by label
  compile_errors.tsv     grouped compile/extract failures
  template_input.cpp     original template
  effective_template_input.cpp / template_expansions.json when presets are used
  work/V000000/source.cpp, <slug>.obj, optional variant_flags.rsp
  groups/G0000/representative.cpp, rebuilt.bin, rebuilt.asm, diff.txt
  matches/...            copied exact-match generated sources, if any

summary.txt fields to know:

  Variants generated  all active label states after nested-choice pruning
  Compile jobs        unique source/flag expansions actually compiled
  Deduped variants    skipped duplicate compiles
  Axes                includes "from @template ..." provenance when known
  Exact-match axis sensitivity: label exact counts, e.g. if_cond(1/1)
  Top groups          exact=1 means group has an exact; exact_count=N counts them
  text_size           checker-effective function size, not the complete code section
  invariants_ok       requested size/frame/call-set gates all passed
  focus_diff          positional mismatches inside --focus-range only
  prefix_delta        first-mismatch movement versus the current checker baseline
  lost_blocks         baseline exact original blocks no longer exact in the variant

A completed compile run exits 0 only when an invariant-eligible exact match is
found. Exit 1 with populated reports is the normal "no exact variant" result,
not a compile/tool failure.

Trace a lead by opening summary.txt, then groups/Gxxxx/diff.txt and
representative.cpp; use variants.tsv for the exact Vxxxxxx row and artifacts.

Policy reminders
----------------

Prefer build/temp/*.tpl.cpp templates over huge inline shell strings. Broad
sweeps are for sticky late-stage convergence, not for replacing understanding.
Reduce any winning context to the smallest proven surface. Use neutral names for
codegen-only dummy declarations (dummy/codegen_dummy); do not invent semantics.
Inline asm remains forbidden except the repo's padding-only pseudo-function rule.
"""


@dataclass(frozen=True)
class CoffReloc:
    offset: int
    symbol_index: int
    reloc_type: int
    width: int
    symbol_name: str = ""


@dataclass(frozen=True)
class LoadedText:
    name: str
    data: bytes
    relocations: list[CoffReloc]


@dataclass
class ChoiceBlock:
    kind: str  # "source" or "flags"
    name: str
    cases: dict[str, list[object]]
    index: int


@dataclass
class AmbientDeclarationsBlock:
    name: str
    samples: int
    seed: str
    prefix: str
    labels: list[str]
    declarations: list[str]
    index: int


@dataclass
class Axis:
    kind: str
    name: str
    labels: list[str] = field(default_factory=list)
    blocks: list[object] = field(default_factory=list)

    def add_label(self, label: str) -> None:
        if label not in self.labels:
            self.labels.append(label)


@dataclass
class TemplatePlan:
    nodes: list[object]
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
    diff_bytes: int = 0
    diff_percent: float = 0.0
    diff_spans: int = 0
    edit_diff_bytes: int = 0
    edit_diff_percent: float = 0.0
    edit_insert_bytes: int = 0
    edit_delete_bytes: int = 0
    edit_replace_bytes: int = 0
    edit_equal_bytes: int = 0
    likely_shifted_alignment: bool = False
    ret_count: int = 0
    last_ret_end: int | None = None
    extra_after_last_ret: int | None = None
    likely_context_tail: bool = False
    focus_diff_bytes: int | None = None
    focus_diff_percent: float | None = None
    focus_first_mismatch: int | None = None
    frame_size: int | None = None
    call_set_matches: bool | None = None
    invariants_ok: bool = True
    invariant_failures: list[str] = field(default_factory=list)
    stable_prefix_delta: int | None = None
    exact_block_coverage_percent: float | None = None
    lost_baseline_exact_blocks: list[int] = field(default_factory=list)
    new_exact_blocks: list[int] = field(default_factory=list)
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
    exact_count: int = 0
    diff_bytes: int = 0
    diff_percent: float = 0.0
    diff_spans: int = 0
    edit_diff_bytes: int = 0
    edit_diff_percent: float = 0.0
    likely_shifted_alignment: bool = False
    ret_count: int = 0
    last_ret_end: int | None = None
    extra_after_last_ret: int | None = None
    likely_context_tail: bool = False
    focus_diff_bytes: int | None = None
    focus_diff_percent: float | None = None
    focus_first_mismatch: int | None = None
    invariants_ok: bool = True
    invariant_failures: list[str] = field(default_factory=list)
    stable_prefix_delta: int | None = None
    exact_block_coverage_percent: float | None = None
    lost_baseline_exact_blocks: list[int] = field(default_factory=list)
    new_exact_blocks: list[int] = field(default_factory=list)


@dataclass
class LabConstraints:
    focus_start: int | None = None
    focus_end: int | None = None
    require_size: bool = False
    require_frame: bool = False
    require_call_set: bool = False
    original_frame_size: int | None = None
    original_call_counts: dict[tuple[str, str], int] = field(default_factory=dict)
    baseline_first_mismatch: int | None = None
    baseline_exact_blocks: set[int] = field(default_factory=set)
    baseline_fresh: bool = False

    def enabled(self) -> bool:
        return bool(
            self.focus_start is not None
            or self.require_size
            or self.require_frame
            or self.require_call_set
        )


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
    string_table_base = ptr_symtab + num_symbols * 18

    def symbol_name(symbol_index: int) -> str:
        offset = ptr_symtab + symbol_index * 18
        if offset < 0 or offset + 18 > len(data):
            return ""
        raw = data[offset : offset + 8]
        if raw[:4] == b"\0\0\0\0":
            string_offset = struct.unpack_from("<L", raw, 4)[0]
            target = string_table_base + string_offset
            return read_c_string(data, target) if target < len(data) else ""
        return raw.split(b"\0", 1)[0].decode("ascii", "replace")

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
                    symbol_name=symbol_name(symbol_index),
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
                        symbol_name=reloc.symbol_name,
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


def load_variant_function_from_obj(path: Path) -> LoadedText:
    """Select the target function's COFF symbol section like the normal checker.

    The legacy text loader remains as a fallback for ad-hoc objects whose file
    name does not carry the normal ``<VA>_<name>`` slug.
    """
    match = re.match(r"^[0-9A-Fa-f]{8}_(.+)$", path.stem)
    if match is None:
        return load_text_from_obj(path)
    wanted_name = match.group(1).lower()
    try:
        obj = load_coff_object(path)
        symbol = find_function_symbol(
            obj, lambda candidate: wanted_name in candidate.name.lower()
        )
        if wanted_name not in symbol.name.lower():
            raise KeyError(f"target function symbol containing {wanted_name!r} not found")
        section = function_symbol_section(obj, symbol)
    except (KeyError, OSError, ValueError) as exc:
        raise ValueError(f"cannot select target function from {path}: {exc}") from exc
    return LoadedText(
        name=section.name,
        data=section.data,
        relocations=[
            CoffReloc(
                offset=relocation.offset,
                symbol_index=relocation.symbol_index,
                reloc_type=relocation.reloc_type,
                width=relocation.width,
                symbol_name=relocation.symbol_name,
            )
            for relocation in section.relocations
        ],
    )


def mask_relocations(data: bytes, relocs: list[CoffReloc]) -> bytes:
    mutable = bytearray(data)
    for reloc in relocs:
        start = reloc.offset
        end = min(len(mutable), start + reloc.width)
        if 0 <= start < len(mutable):
            for i in range(start, end):
                mutable[i] = 0
    return bytes(mutable)


def normalize_relocation_symbol_for_group(symbol_name: str) -> str:
    """Keep external identity while removing VC5's ambient local counters."""
    if re.fullmatch(r"\$L\d+", symbol_name):
        return "$L#"
    return re.sub(r"\$S\d+$", "$S#", symbol_name)


def first_mismatch(left: bytes, right: bytes) -> int | None:
    limit = min(len(left), len(right))
    for i in range(limit):
        if left[i] != right[i]:
            return i
    if len(left) != len(right):
        return limit
    return None


def parse_focus_range(text: str, va: int, expected_size: int) -> tuple[int, int]:
    if "-" not in text:
        raise ValueError("focus range must be START-END")
    start_text, end_text = text.split("-", 1)

    def endpoint(value: str) -> tuple[int, bool]:
        stripped = value.strip()
        is_offset = stripped.startswith("+")
        number = int(stripped[1:] if is_offset else stripped, 16)
        if not is_offset and number >= va:
            number -= va
        return number, is_offset

    start, _start_offset = endpoint(start_text)
    end_inclusive, _end_offset = endpoint(end_text)
    end = end_inclusive + 1
    if start < 0 or end <= start or end > expected_size:
        raise ValueError(f"focus range must fall inside +0000-+{expected_size - 1:04X}")
    return start, end


def relocation_dicts(relocations: list[CoffReloc], limit: int) -> list[dict[str, object]]:
    return [
        {
            "offset": reloc.offset,
            "width": reloc.width,
            "symbol_name": reloc.symbol_name,
        }
        for reloc in relocations
        if reloc.offset < limit
    ]


def call_counts_for_code(code: bytes, va: int, relocations: list[CoffReloc] | None = None) -> dict[tuple[str, str], int]:
    instructions = decode_instructions(code, va, relocation_dicts(relocations or [], len(code)))
    return dict(Counter((str(row["kind"]), str(row["target"])) for row in call_fingerprint(instructions, original=False)))


def variant_code_extent(
    data: bytes,
    expected_size: int,
    indirect_targets: list[int] | None = None,
) -> dict[str, object]:
    """Apply the normal checker's function-boundary policy to one lab object.

    VC5 may append unrelated generated context after the target body in the same
    code section. Unreachable context is not a size failure; entry-reachable code
    beyond the inventory boundary remains an overflow.
    """
    return extraction_extent(data, expected_size, indirect_targets)


def variant_indirect_targets(obj_path: Path, expected_size: int) -> list[int]:
    """Recover checker-equivalent same-section targets referenced past the boundary."""
    match = re.match(r"^[0-9A-Fa-f]{8}_(.+)$", obj_path.stem)
    if match is None:
        return []
    wanted_name = match.group(1).lower()
    try:
        obj = load_coff_object(obj_path)
        symbol = find_function_symbol(
            obj, lambda candidate: wanted_name in candidate.name.lower()
        )
        if wanted_name not in symbol.name.lower():
            return []
        section = function_symbol_section(obj, symbol)
    except (KeyError, OSError, ValueError):
        return []
    symbol_by_index = {candidate.index: candidate for candidate in obj.symbols}
    targets: list[int] = []
    for relocation in section.relocations:
        if relocation.offset < expected_size:
            continue
        target = symbol_by_index.get(relocation.symbol_index)
        if target is None or target.section_number != symbol.section_number:
            continue
        targets.append(target.value - symbol.value)
    return sorted(set(targets))


def evaluate_constraints(
    *,
    constraints: LabConstraints,
    text_size: int,
    expected_size: int,
    frame_size: int | None,
    call_counts: dict[tuple[str, str], int],
) -> list[str]:
    failures: list[str] = []
    if constraints.require_size and text_size != expected_size:
        failures.append(f"size {text_size} != {expected_size}")
    if constraints.require_frame and frame_size != constraints.original_frame_size:
        failures.append(f"frame {frame_size} != {constraints.original_frame_size}")
    if constraints.require_call_set and call_counts != constraints.original_call_counts:
        missing = constraints.original_call_counts.keys() - call_counts.keys()
        extra = call_counts.keys() - constraints.original_call_counts.keys()
        count_drift = sum(
            constraints.original_call_counts.get(key, 0) != call_counts.get(key, 0)
            for key in constraints.original_call_counts.keys() & call_counts.keys()
        )
        failures.append(
            f"call-set mismatch missing={len(missing)} extra={len(extra)} count_drift={count_drift}"
        )
    return failures


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


CHOICE_DIRECTIVES = ("@choice", "@flagchoice", "@flags")
END_DIRECTIVES = ("@endchoice", "@endflagchoice", "@endflags")


def parse_ambient_declarations(
    arg: str | None, line_no: int, block_index: int
) -> AmbientDeclarationsBlock:
    if not arg:
        raise ValueError(f"@ambient_declarations requires an axis name on line {line_no}")
    try:
        parts = shlex.split(arg, posix=True)
    except ValueError as exc:
        raise ValueError(f"invalid @ambient_declarations arguments on line {line_no}: {exc}") from exc
    if not parts or "=" in parts[0]:
        raise ValueError(f"@ambient_declarations requires an axis name on line {line_no}")
    axis = parts[0]
    values: dict[str, str] = {}
    for part in parts[1:]:
        if "=" not in part:
            raise ValueError(
                f"unexpected @ambient_declarations argument {part!r} on line {line_no}; use key=value"
            )
        key, value = part.split("=", 1)
        if key not in {"samples", "seed", "prefix"}:
            raise ValueError(f"unknown @ambient_declarations argument {key!r} on line {line_no}")
        values[key] = value
    try:
        samples = int(values.get("samples", str(DEFAULT_AMBIENT_SAMPLES)), 10)
    except ValueError as exc:
        raise ValueError(f"ambient sample count must be an integer on line {line_no}") from exc
    if samples < 1:
        raise ValueError(f"ambient sample count must be positive on line {line_no}")
    seed = values.get("seed", axis)
    prefix = sanitize_identifier(values.get("prefix", f"codegen_ambient_{axis}"))
    width = max(4, len(str(samples - 1)))
    labels = [f"n{index:0{width}d}" for index in range(samples)]
    declarations = []
    for index in range(samples - 1):
        digest = hashlib.sha256(f"{seed}:{index}".encode("utf-8")).hexdigest()[:10]
        declarations.append(f"struct {prefix}_{index:06d}_{digest};\n")
    return AmbientDeclarationsBlock(
        name=axis,
        samples=samples,
        seed=seed,
        prefix=prefix,
        labels=labels,
        declarations=declarations,
        index=block_index,
    )


def parse_template(text: str) -> TemplatePlan:
    """Parse a variant template, including choices nested inside cases.

    Nested choices are represented as a tree.  Enumeration later only walks the
    active branch, so an inner axis does not multiply variants when its enclosing
    case is not selected.
    """
    lines = text.splitlines(keepends=True)
    axes_order: list[tuple[str, str]] = []
    axis_by_key: dict[tuple[str, str], Axis] = {}
    block_index = 0

    def register_block(kind: str, name: str, cases: dict[str, list[object]]) -> ChoiceBlock:
        nonlocal block_index
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
        return block

    def parse_nodes(i: int, stop_directives: set[str]) -> tuple[list[object], int]:
        nonlocal block_index
        nodes: list[object] = []
        text_buf: list[str] = []

        def flush_text() -> None:
            nonlocal text_buf
            if text_buf:
                nodes.append("".join(text_buf))
                text_buf = []

        while i < len(lines):
            parsed = parse_directive(lines[i])
            if parsed is not None:
                directive, _arg = parsed
                if directive in stop_directives:
                    break
                if directive == "@case":
                    if "@case" in stop_directives:
                        break
                    raise ValueError(f"@case outside a choice near line {i + 1}")
                if directive in END_DIRECTIVES:
                    raise ValueError(f"unexpected {directive} near line {i + 1}")
                if directive in CHOICE_DIRECTIVES:
                    flush_text()
                    block, i = parse_choice(i)
                    nodes.append(block)
                    continue
                if directive == "@ambient_declarations":
                    flush_text()
                    block = parse_ambient_declarations(_arg, i + 1, block_index)
                    block_index += 1
                    key = ("source", block.name)
                    if key in axis_by_key:
                        raise ValueError(
                            f"ambient axis {block.name!r} is already defined near line {i + 1}"
                        )
                    axis = Axis(kind="source", name=block.name, labels=list(block.labels), blocks=[block])
                    axis_by_key[key] = axis
                    axes_order.append(key)
                    nodes.append(block)
                    i += 1
                    continue
            text_buf.append(lines[i])
            i += 1

        flush_text()
        return nodes, i

    def parse_choice(i: int) -> tuple[ChoiceBlock, int]:
        parsed = parse_directive(lines[i])
        if parsed is None or parsed[0] not in CHOICE_DIRECTIVES:
            raise ValueError(f"internal parser error near line {i + 1}")
        directive, arg = parsed
        if not arg:
            raise ValueError(f"{directive} requires an axis name on line {i + 1}")
        kind = "source" if directive == "@choice" else "flags"
        name = arg
        end_directives = {"@endchoice"} if kind == "source" else {"@endflagchoice", "@endflags"}
        block = register_block(kind, name, {})
        cases = block.cases
        i += 1

        while i < len(lines):
            parsed = parse_directive(lines[i])
            if parsed is not None and parsed[0] in end_directives:
                i += 1
                break
            if parsed is None or parsed[0] != "@case":
                if lines[i].strip():
                    raise ValueError(f"content before first @case in {directive} {name!r} near line {i + 1}")
                i += 1
                continue

            label = parsed[1]
            if not label:
                raise ValueError(f"@case requires a label on line {i + 1}")
            if label in cases:
                raise ValueError(f"duplicate @case label {label!r} in {directive} {name!r} near line {i + 1}")
            i += 1
            case_nodes, i = parse_nodes(i, stop_directives={"@case", *end_directives})
            cases[label] = case_nodes
            # Leave the stop directive unconsumed.  The loop above consumes either
            # the next @case or the matching end directive.
        else:
            raise ValueError(f"unterminated {directive} {name!r}")

        axis = axis_by_key[(kind, name)]
        for label in cases.keys():
            axis.add_label(label)
        return block, i

    nodes, i = parse_nodes(0, stop_directives=set())
    if i != len(lines):
        parsed = parse_directive(lines[i])
        directive = parsed[0] if parsed else lines[i].strip()
        raise ValueError(f"unexpected {directive} near line {i + 1}")

    axes = [axis_by_key[key] for key in axes_order]
    for axis in axes:
        if not axis.labels:
            raise ValueError(f"axis {axis.name!r} has no @case labels")
    return TemplatePlan(nodes=nodes, axes=axes, axis_by_key=axis_by_key)


def label_text(spec: VariantSpec, axes: list[Axis]) -> str:
    parts: list[str] = []
    for axis in axes:
        key = (axis.kind, axis.name)
        if key not in spec.labels:
            continue
        label = spec.labels[key]
        prefix = "flags." if axis.kind == "flags" else "src."
        parts.append(f"{prefix}{axis.name}={label}")
    return ";".join(parts)


def selected_case_nodes(block: ChoiceBlock, spec: VariantSpec) -> list[object]:
    selected = spec.labels.get((block.kind, block.name))
    if selected is None:
        return []
    return block.cases.get(selected, [])


def expand_source_nodes(nodes: list[object], spec: VariantSpec) -> str:
    chunks: list[str] = []
    for node in nodes:
        if isinstance(node, str):
            chunks.append(node)
        elif isinstance(node, ChoiceBlock):
            if node.kind == "source":
                chunks.append(expand_source_nodes(selected_case_nodes(node, spec), spec))
            # Flag blocks are intentionally removed from generated source, even
            # when nested inside a source case.
        elif isinstance(node, AmbientDeclarationsBlock):
            label = spec.labels.get(("source", node.name))
            if label is not None:
                count = int(label[1:], 10)
                chunks.append(
                    "".join(node.declarations[:count])
                    + "\n" * (len(node.declarations) - count)
                )
    return "".join(chunks)


def expand_source(plan: TemplatePlan, spec: VariantSpec) -> str:
    return expand_source_nodes(plan.nodes, spec)


def expand_flags_nodes(nodes: list[object], spec: VariantSpec, *, in_flag_case: bool) -> str:
    chunks: list[str] = []
    for node in nodes:
        if isinstance(node, str):
            if in_flag_case:
                chunks.append(node)
        elif isinstance(node, ChoiceBlock):
            if node.kind == "flags":
                chunks.append(expand_flags_nodes(selected_case_nodes(node, spec), spec, in_flag_case=True))
            else:
                # Walk selected source cases so nested flag choices are only
                # active under the chosen source branch.  Source text itself is
                # ignored while collecting flags.
                chunks.append(expand_flags_nodes(selected_case_nodes(node, spec), spec, in_flag_case=False))
        elif isinstance(node, AmbientDeclarationsBlock):
            continue
    return "".join(chunks)


def expand_flags(plan: TemplatePlan, spec: VariantSpec, fmt_values: dict[str, str]) -> str:
    text = expand_flags_nodes(plan.nodes, spec, in_flag_case=False)
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
_SLOT_RE = re.compile(r"\{\{slot:([A-Za-z_][A-Za-z0-9_]*)([^}]*)\}\}")
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


def print_variant_template_help(name: str) -> None:
    path = find_variant_template_path(name)
    print(f"Template: {path.stem}")
    print(f"Path: {path}")
    print("")
    print(path.read_text(encoding="utf-8"), end="")


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
    values.setdefault("entry", f"{values['prefix']}_entry")
    values.setdefault("entry_type", "char*")
    values.setdefault("step", "1")
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
        filter_text = match.group(2) or ""
        slot_text = slots.get(slot_name, "")
        for raw_filter in filter_text.split("|"):
            filter_name = raw_filter.strip()
            if not filter_name:
                continue
            if filter_name == "trim":
                slot_text = slot_text.strip()
            elif filter_name == "lstrip":
                slot_text = slot_text.lstrip()
            elif filter_name in ("rstrip", "chomp"):
                slot_text = slot_text.rstrip()
            elif filter_name.startswith("indent:"):
                try:
                    spaces = int(filter_name.split(":", 1)[1])
                except ValueError as exc:
                    raise ValueError(f"invalid indent filter {filter_name!r} in @template {name!r}") from exc
                slot_text = indent_slot_text(slot_text, spaces)
            else:
                raise ValueError(f"unknown slot filter {filter_name!r} in @template {name!r}")
        return slot_text

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


def enumerate_label_states(plan: TemplatePlan) -> list[dict[tuple[str, str], str]]:
    """Enumerate only choices reachable through active parent cases.

    A nested axis is not assigned at all when its containing case is inactive.
    Reused axis names remain linked: once an axis label has been chosen, every
    later active block with that same kind/name uses the same label, and omitted
    cases emit/activate nothing just like the historical flat parser.
    """

    def walk_nodes(nodes: list[object], state: dict[tuple[str, str], str]) -> list[dict[tuple[str, str], str]]:
        states = [state]
        for node in nodes:
            if isinstance(node, str):
                continue
            if isinstance(node, AmbientDeclarationsBlock):
                key = ("source", node.name)
                next_states = []
                for current in states:
                    if key in current:
                        next_states.append(current)
                    else:
                        for label in node.labels:
                            branched = dict(current)
                            branched[key] = label
                            next_states.append(branched)
                states = next_states
                continue
            if not isinstance(node, ChoiceBlock):
                continue
            key = (node.kind, node.name)
            axis = plan.axis_by_key[key]
            next_states: list[dict[tuple[str, str], str]] = []
            for current in states:
                if key in current:
                    selected = current[key]
                    next_states.extend(walk_nodes(node.cases.get(selected, []), current))
                else:
                    for label in axis.labels:
                        branched = dict(current)
                        branched[key] = label
                        next_states.extend(walk_nodes(node.cases.get(label, []), branched))
            states = next_states
        return states

    return walk_nodes(plan.nodes, {})


def make_specs(plan: TemplatePlan) -> list[VariantSpec]:
    specs: list[VariantSpec] = []
    for index, labels in enumerate(enumerate_label_states(plan)):
        specs.append(VariantSpec(index=index, variant_id=f"V{index:06d}", labels=labels))
    return specs


def preview_fmt_values() -> dict[str, str]:
    return {
        "work_dir": "<work_dir>",
        "variant_id": "<variant_id>",
        "slug": "<slug>",
        "run_dir": "<run_dir>",
    }


def select_spec(specs: list[VariantSpec], selector: str) -> VariantSpec:
    wanted = selector.strip()
    if wanted.upper().startswith("V"):
        wanted = "V" + wanted[1:].zfill(6)
        for spec in specs:
            if spec.variant_id == wanted:
                return spec
    else:
        try:
            index = int(wanted, 10)
        except ValueError as exc:
            raise ValueError(f"invalid variant selector {selector!r}; use an index or V000123") from exc
        if 0 <= index < len(specs):
            return specs[index]
    raise ValueError(f"variant {selector!r} is out of range for {len(specs)} variants")


def print_variant_preview(plan: TemplatePlan, specs: list[VariantSpec], selected_specs: list[VariantSpec]) -> None:
    print_variant_preview_with_mode(plan, specs, selected_specs, full_source=True)


def print_variant_preview_with_mode(
    plan: TemplatePlan,
    specs: list[VariantSpec],
    selected_specs: list[VariantSpec],
    *,
    full_source: bool,
) -> None:
    print(f"Expanded variants: {len(specs)}")
    for spec in selected_specs:
        fmt_values = preview_fmt_values()
        source = expand_source(plan, spec)
        flags = expand_flags(plan, spec, fmt_values)
        labels = label_text(spec, plan.axes)
        if not full_source:
            line_count = len(source.splitlines())
            flags_hash = stable_hash(flags) if flags else "-"
            print(
                f"{spec.variant_id}\t{labels}\tlines={line_count}\tbytes={len(source.encode('utf-8'))}"
                f"\tsource={stable_hash(source)}\tflags={flags_hash}"
            )
            continue
        print(f"\n===== {spec.variant_id} {labels} =====")
        if flags.strip():
            print("----- flags -----")
            print(flags.rstrip())
        print("----- source -----")
        print(source, end="" if source.endswith("\n") else "\n")


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


def variant_fmt_values(run_dir: Path, work_dir: Path, variant_id: str, slug: str) -> dict[str, str]:
    return {
        "work_dir": str(work_dir),
        "variant_id": variant_id,
        "slug": slug,
        "run_dir": str(run_dir),
    }


def variant_build_material(plan: TemplatePlan, spec: VariantSpec, run_dir: Path, work_root: Path, slug: str) -> tuple[str, str]:
    work_dir = work_root / spec.variant_id
    source_body = expand_source(plan, spec)
    extra_flags = expand_flags(plan, spec, variant_fmt_values(run_dir, work_dir, spec.variant_id, slug))
    return source_body, extra_flags


def variant_dedupe_key(source_body: str, extra_flags: str) -> str:
    return stable_hash(source_body + "\0" + extra_flags)


def write_dedup_alias_result(
    representative: VariantResult,
    spec: VariantSpec,
    plan: TemplatePlan,
    axes: list[Axis],
    run_dir: Path,
    work_root: Path,
    slug: str,
) -> VariantResult:
    work_dir = work_root / spec.variant_id
    ensure_dir(work_dir)
    ensure_dir(work_dir / "tmp")
    source_path = work_dir / "source.cpp"
    flags_path = work_dir / "variant_flags.rsp"
    source_body, extra_flags = variant_build_material(plan, spec, run_dir, work_root, slug)
    source_path.write_text(make_source_hint(run_dir=run_dir, variant_id=spec.variant_id, slug=slug) + source_body, encoding="utf-8")
    flags_path_text = ""
    if extra_flags.strip():
        flags_path.write_text(extra_flags, encoding="utf-8")
        flags_path_text = str(flags_path)
    (work_dir / "dedup_alias.txt").write_text(
        "This variant expanded to the same source/flags as another variant and was not compiled separately.\n"
        f"Representative variant: {representative.variant_id}\n"
        f"Representative object: {representative.obj_path or ''}\n",
        encoding="utf-8",
    )
    return replace(
        representative,
        variant_id=spec.variant_id,
        labels_text=label_text(spec, axes),
        source_path=str(source_path),
        flags_path=flags_path_text,
        stdout="",
        stderr="",
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
    constraints: LabConstraints,
    compile_timeout_seconds: float | None = DEFAULT_COMPILE_TIMEOUT_SECONDS,
    source_body: str | None = None,
    extra_flags: str | None = None,
) -> VariantResult:
    labels = label_text(spec, axes)
    work_dir = work_root / spec.variant_id
    ensure_dir(work_dir)
    ensure_dir(work_dir / "tmp")
    source_path = work_dir / "source.cpp"
    obj_path = work_dir / f"{slug}.obj"
    flags_path = work_dir / "variant_flags.rsp"
    flags_path_text = ""

    fmt_values = variant_fmt_values(run_dir, work_dir, spec.variant_id, slug)
    if source_body is None:
        source_body = expand_source(plan, spec)
    if extra_flags is None:
        extra_flags = expand_flags(plan, spec, fmt_values)
    source = make_source_hint(run_dir=run_dir, variant_id=spec.variant_id, slug=slug) + source_body
    source_path.write_text(source, encoding="utf-8")
    if extra_flags.strip():
        flags_path.write_text(extra_flags, encoding="utf-8")
        flags_path_text = str(flags_path)

    command = [str(cl_path), f"@{default_rsp}"]
    # Make copied repo sources/templates compile from variant work directories without
    # include-path surgery. This supports root-relative includes such as
    # "include/game_globals.h" and scratch/matching-relative includes such as
    # "../../include/game_globals.h" when a scratch file is copied into build/temp.
    include_roots = [
        REPO_ROOT,
        REPO_ROOT / "include",
        REPO_ROOT / "src" / "scratch",
        REPO_ROOT / "src" / "matching",
        REPO_ROOT / "src" / "accepted_drift",
        REPO_ROOT / "src" / "verified_logic",
    ]
    command.extend(f"/I{path}" for path in include_roots)
    if extra_flags.strip():
        command.append(f"@{flags_path}")
    command.extend([f"/Fo{obj_path}", str(source_path)])

    env = tool_env(toolchain)
    env["TEMP"] = str(work_dir / "tmp")
    env["TMP"] = str(work_dir / "tmp")

    try:
        proc = subprocess.run(
            command,
            cwd=REPO_ROOT,
            env=env,
            capture_output=True,
            text=True,
            timeout=compile_timeout_seconds,
        )
    except subprocess.TimeoutExpired:
        text = f"compiler timeout after {compile_timeout_seconds:g} second(s)"
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
        loaded = load_variant_function_from_obj(obj_path)
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

    extent = variant_code_extent(
        loaded.data,
        expected_size,
        variant_indirect_targets(obj_path, expected_size),
    )
    effective_size = int(extent["effective_size"])
    comparison_size = int(extent["comparison_size"])
    compare_bytes = loaded.data[:comparison_size]
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

    metrics = positional_byte_diff_metrics(masked_original_bytes, masked_rebuilt)
    mismatch_text = str(metrics["first_mismatch_offset"])
    mismatch = int(mismatch_text) if mismatch_text else None
    exact = (
        metrics["result"] == "MATCH"
        and effective_size == expected_size
        and not bool(extent["has_code_overflow"])
    )
    status = "match" if exact else "mismatch"

    focus_diff_bytes: int | None = None
    focus_diff_percent: float | None = None
    focus_first_mismatch: int | None = None
    if constraints.focus_start is not None and constraints.focus_end is not None:
        focus = positional_byte_diff_metrics(
            masked_original_bytes[constraints.focus_start : constraints.focus_end],
            masked_rebuilt[constraints.focus_start : constraints.focus_end],
        )
        focus_diff_bytes = int(focus["diff_bytes"])
        focus_diff_percent = float(focus["diff_percent"])
        focus_text = str(focus["first_mismatch_offset"])
        focus_first_mismatch = None if not focus_text else constraints.focus_start + int(focus_text)

    rebuilt_instructions = decode_instructions(
        compare_bytes, va, relocation_dicts(compare_relocs, len(compare_bytes))
    )
    rebuilt_frame = prologue_summary(rebuilt_instructions).get("frame_size")
    rebuilt_call_counts = dict(
        Counter(
            (str(row["kind"]), str(row["target"]))
            for row in call_fingerprint(rebuilt_instructions, original=False)
        )
    )
    invariant_failures = evaluate_constraints(
        constraints=constraints,
        text_size=effective_size,
        expected_size=expected_size,
        frame_size=None if rebuilt_frame is None else int(rebuilt_frame),
        call_counts=rebuilt_call_counts,
    )

    identity_relocs = [reloc for reloc in loaded.relocations if reloc.offset < comparison_size]
    masked_full_rebuilt = mask_relocations(compare_bytes, identity_relocs)
    group_material = b"\0".join(
        [
            str(effective_size).encode("ascii"),
            masked_full_rebuilt,
            "|".join(
                f"{reloc.offset}:{reloc.reloc_type}:{normalize_relocation_symbol_for_group(reloc.symbol_name)}"
                for reloc in identity_relocs
            ).encode("utf-8", "replace"),
        ]
    )
    group_key = stable_hash(group_material)

    return VariantResult(
        variant_id=spec.variant_id,
        labels_text=labels,
        status=status,
        returncode=proc.returncode,
        text_size=effective_size,
        compare_size=len(compare_bytes),
        relocations=len(compare_relocs),
        first_mismatch=mismatch,
        exact=exact,
        diff_bytes=int(metrics["diff_bytes"]),
        diff_percent=float(metrics["diff_percent"]),
        diff_spans=int(metrics["diff_spans"]),
        focus_diff_bytes=focus_diff_bytes,
        focus_diff_percent=focus_diff_percent,
        focus_first_mismatch=focus_first_mismatch,
        frame_size=None if rebuilt_frame is None else int(rebuilt_frame),
        call_set_matches=(rebuilt_call_counts == constraints.original_call_counts)
        if constraints.require_call_set
        else None,
        invariants_ok=not invariant_failures,
        invariant_failures=invariant_failures,
        group_key=group_key,
        source_path=str(source_path),
        obj_path=str(obj_path),
        flags_path=flags_path_text,
        stdout=proc.stdout,
        stderr=proc.stderr,
    )


def analyze_unique_groups(
    results: list[VariantResult],
    original_bytes: bytes,
    expected_size: int,
    va: int,
    constraints: LabConstraints,
) -> None:
    """Run expensive edit-diff/disassembly work once per emitted-code group."""
    groups: dict[str, list[VariantResult]] = {}
    for result in results:
        if result.group_key and result.obj_path:
            groups.setdefault(result.group_key, []).append(result)

    original_instructions = decode_instructions(original_bytes[:expected_size], va)
    original_calls = call_fingerprint(original_instructions, original=True)
    original_blocks = basic_blocks(original_instructions, original_calls)
    for members in groups.values():
        representative = members[0]
        loaded = load_variant_function_from_obj(Path(representative.obj_path or ""))
        extent = variant_code_extent(
            loaded.data,
            expected_size,
            variant_indirect_targets(Path(representative.obj_path or ""), expected_size),
        )
        compare_bytes = loaded.data[: int(extent["comparison_size"])]
        compare_relocs = [reloc for reloc in loaded.relocations if reloc.offset < len(compare_bytes)]
        masked_rebuilt = mask_relocations(compare_bytes, compare_relocs)
        masked_original = bytearray(original_bytes[:expected_size])
        for reloc in compare_relocs:
            start = reloc.offset
            end = min(len(masked_original), start + reloc.width)
            if 0 <= start < len(masked_original):
                for i in range(start, end):
                    masked_original[i] = 0

        edit = edit_diff_metrics(bytes(masked_original), masked_rebuilt)
        ret_ends = detect_ret_ends(loaded.data)
        last_ret_end = ret_ends[-1] if ret_ends else None
        extra_after_last_ret = (len(loaded.data) - last_ret_end) if last_ret_end is not None else None
        likely_context_tail = (
            last_ret_end is not None
            and last_ret_end < expected_size
            and len(loaded.data) > last_ret_end
        )
        rebuilt_instructions = decode_instructions(
            compare_bytes, va, relocation_dicts(compare_relocs, len(compare_bytes))
        )
        rebuilt_calls = call_fingerprint(rebuilt_instructions, original=False)
        rebuilt_blocks = basic_blocks(rebuilt_instructions, rebuilt_calls)
        block_map = block_alignment(original_blocks, rebuilt_blocks)
        exact_offsets = {
            int(row["original"]["offset"])
            for row in block_map.get("rows") or []
            if row.get("status") == "equal" and row.get("original") is not None
        }
        lost_exact = (
            sorted(constraints.baseline_exact_blocks - exact_offsets)
            if constraints.baseline_fresh
            else []
        )
        new_exact = (
            sorted(exact_offsets - constraints.baseline_exact_blocks)
            if constraints.baseline_fresh
            else []
        )
        stable_prefix_delta = (
            None
            if not constraints.baseline_fresh
            or constraints.baseline_first_mismatch is None
            or representative.first_mismatch is None
            else representative.first_mismatch - constraints.baseline_first_mismatch
        )

        for result in members:
            result.edit_diff_bytes = int(edit["edit_diff_bytes"])
            result.edit_diff_percent = float(edit["edit_diff_percent"])
            result.edit_insert_bytes = int(edit["edit_insert_bytes"])
            result.edit_delete_bytes = int(edit["edit_delete_bytes"])
            result.edit_replace_bytes = int(edit["edit_replace_bytes"])
            result.edit_equal_bytes = int(edit["edit_equal_bytes"])
            result.likely_shifted_alignment = bool(edit["likely_shifted_alignment"])
            result.ret_count = len(ret_ends)
            result.last_ret_end = last_ret_end
            result.extra_after_last_ret = extra_after_last_ret
            result.likely_context_tail = likely_context_tail
            result.stable_prefix_delta = stable_prefix_delta
            result.exact_block_coverage_percent = float(block_map.get("matched_coverage_percent") or 0.0)
            result.lost_baseline_exact_blocks = lost_exact
            result.new_exact_blocks = new_exact


def interesting_sort_key(group: GroupInfo, expected_size: int) -> tuple:
    if group.exact:
        return (0, 0, 0, 0, 0, -group.count)
    first = group.first_mismatch if group.first_mismatch is not None else -1
    text_size = group.text_size or 0
    # Prefer true exact-size groups first; long/short groups can have a useful
    # first-mismatch after truncation, but exact function size is usually a
    # stronger signal during matching work.
    exact_text_penalty = 0 if text_size == expected_size else 1
    size_distance = abs(text_size - expected_size)
    invariant_penalty = 0 if group.invariants_ok else 1
    focus_diff = group.focus_diff_bytes if group.focus_diff_bytes is not None else 1 << 30
    return (1, invariant_penalty, focus_diff, exact_text_penalty, size_distance, -first, -group.count)


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
            loaded = load_variant_function_from_obj(obj_path)
        except Exception as exc:
            (group_dir / "extract_error.txt").write_text(str(exc), encoding="utf-8")
            continue
        extent = variant_code_extent(
            loaded.data,
            expected_size,
            variant_indirect_targets(obj_path, expected_size),
        )
        compare_bytes = loaded.data[: int(extent["comparison_size"])]
        (group_dir / "rebuilt.bin").write_bytes(compare_bytes)
        write_asm(group_dir / "rebuilt.asm", compare_bytes, va)

        rebuilt_lines = (group_dir / "rebuilt.asm").read_text(encoding="utf-8").splitlines()
        diff_lines: list[str] = []
        diff_lines.append(f"Group: {group.group_id}")
        diff_lines.append(f"Count: {group.count}")
        diff_lines.append(f"Exact variants: {group.exact_count}")
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
        diff_lines.append(f"Positional diff bytes: {rep.diff_bytes}")
        diff_lines.append(f"Positional diff percent: {rep.diff_percent:.4f}")
        diff_lines.append(f"Invariants OK: {int(rep.invariants_ok)}")
        diff_lines.append(f"Invariant failures: {' | '.join(rep.invariant_failures) or '<none>'}")
        diff_lines.append(f"Frame size: {rep.frame_size}")
        diff_lines.append(f"Focus first mismatch: {rep.focus_first_mismatch}")
        diff_lines.append(f"Focus diff bytes: {rep.focus_diff_bytes}")
        diff_lines.append(f"Focus diff percent: {rep.focus_diff_percent}")
        diff_lines.append(f"Stable prefix delta vs current checker baseline: {rep.stable_prefix_delta}")
        diff_lines.append(f"Exact block coverage percent: {rep.exact_block_coverage_percent}")
        diff_lines.append(
            "Lost baseline exact blocks: "
            + (", ".join(f"+{value:04X}" for value in rep.lost_baseline_exact_blocks) or "<none>")
        )
        diff_lines.append(
            "New exact blocks: "
            + (", ".join(f"+{value:04X}" for value in rep.new_exact_blocks) or "<none>")
        )
        diff_lines.append(f"Edit diff bytes: {rep.edit_diff_bytes}")
        diff_lines.append(f"Edit diff percent: {rep.edit_diff_percent:.4f}")
        diff_lines.append(f"Likely shifted alignment: {int(rep.likely_shifted_alignment)}")
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
        loaded = load_variant_function_from_obj(obj_path)
    except Exception as exc:
        return [f"        snippet unavailable: {exc}"]

    extent = variant_code_extent(
        loaded.data,
        expected_size,
        variant_indirect_targets(obj_path, expected_size),
    )
    compare_bytes = loaded.data[: int(extent["comparison_size"])]
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


def axis_template_note(axis: Axis, template_expansions: list[dict] | None) -> str:
    if any(isinstance(block, AmbientDeclarationsBlock) for block in axis.blocks):
        return " from @ambient_declarations"
    if not template_expansions:
        return ""
    matches: list[str] = []
    for record in template_expansions:
        values = record.get("values", {})
        axis_arg = values.get("axis")
        if not axis_arg:
            continue
        if axis.name == axis_arg or axis.name.startswith(axis_arg + "_"):
            matches.append(record.get("name", "<template>"))
    if not matches:
        return ""
    unique = []
    for name in matches:
        if name not in unique:
            unique.append(name)
    return " from @template " + ",".join(unique)


def axis_labels_text(axis: Axis, limit: int = 24) -> str:
    labels = axis.labels
    if len(labels) <= limit:
        return ", ".join(labels)
    head = limit // 2
    tail = limit - head
    return ", ".join([*labels[:head], f"... +{len(labels) - limit}", *labels[-tail:]])


def write_axis_sensitivity(
    run_dir: Path,
    axes: list[Axis],
    specs: list[VariantSpec],
    results: list[VariantResult],
) -> list[str]:
    spec_by_id = {spec.variant_id: spec for spec in specs}
    rows: list[tuple[str, str, str, int, int, int, int]] = []
    summary_lines: list[str] = []

    for axis in axes:
        key = (axis.kind, axis.name)
        label_stats: dict[str, dict[str, int]] = {label: {"total": 0, "exact": 0, "errors": 0} for label in axis.labels}
        for result in results:
            spec = spec_by_id.get(result.variant_id)
            if spec is None or key not in spec.labels:
                continue
            label = spec.labels[key]
            stats = label_stats.setdefault(label, {"total": 0, "exact": 0, "errors": 0})
            stats["total"] += 1
            if result.exact and result.invariants_ok:
                stats["exact"] += 1
            if result.status not in ("match", "mismatch"):
                stats["errors"] += 1

        active_stats = [(label, stats) for label, stats in label_stats.items() if stats["total"]]
        if not active_stats:
            continue
        for label, stats in active_stats:
            total = stats["total"]
            exact = stats["exact"]
            errors = stats["errors"]
            rows.append((axis.kind, axis.name, label, total, exact, total - exact - errors, errors))

        matching = [f"{label}({stats['exact']}/{stats['total']})" for label, stats in active_stats if stats["exact"]]
        nonmatching = [f"{label}(0/{stats['total']})" for label, stats in active_stats if not stats["exact"]]
        if matching:
            prefix = "flags" if axis.kind == "flags" else "source"
            line = f"  {prefix}.{axis.name}: matching " + ", ".join(matching[:12])
            if len(matching) > 12:
                line += f", ... +{len(matching) - 12}"
            if nonmatching:
                line += "; nonmatching " + ", ".join(nonmatching[:12])
                if len(nonmatching) > 12:
                    line += f", ... +{len(nonmatching) - 12}"
            summary_lines.append(line)

    with (run_dir / "axis_sensitivity.tsv").open("w", encoding="utf-8", newline="") as f:
        f.write("axis_kind\taxis\tlabel\ttotal\texact\tmismatch\terror\n")
        for row in rows:
            f.write("\t".join(str(value) for value in row) + "\n")

    return summary_lines


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
    compile_jobs: int | None = None,
    deduped_variants: int = 0,
    workers: int | None = None,
    compile_timeout_seconds: float | None = DEFAULT_COMPILE_TIMEOUT_SECONDS,
    constraints: LabConstraints | None = None,
) -> None:
    constraints = constraints or LabConstraints()
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
                    exact=result.exact and result.invariants_ok,
                    diff_bytes=result.diff_bytes,
                    diff_percent=result.diff_percent,
                    diff_spans=result.diff_spans,
                    edit_diff_bytes=result.edit_diff_bytes,
                    edit_diff_percent=result.edit_diff_percent,
                    likely_shifted_alignment=result.likely_shifted_alignment,
                    ret_count=result.ret_count,
                    last_ret_end=result.last_ret_end,
                    extra_after_last_ret=result.extra_after_last_ret,
                    likely_context_tail=result.likely_context_tail,
                    focus_diff_bytes=result.focus_diff_bytes,
                    focus_diff_percent=result.focus_diff_percent,
                    focus_first_mismatch=result.focus_first_mismatch,
                    invariants_ok=result.invariants_ok,
                    invariant_failures=list(result.invariant_failures),
                    stable_prefix_delta=result.stable_prefix_delta,
                    exact_block_coverage_percent=result.exact_block_coverage_percent,
                    lost_baseline_exact_blocks=list(result.lost_baseline_exact_blocks),
                    new_exact_blocks=list(result.new_exact_blocks),
                )
                group_map[result.group_key] = group
            group.count += 1
            if result.exact and result.invariants_ok:
                group.exact_count += 1
            if result.exact and result.invariants_ok and not group.exact:
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
            "variant_id\tstatus\tgroup_id\terror_id\texact\tinvariants_ok\tinvariant_failures\ttext_size\tcompare_size\tframe_size\tfirst_mismatch\tstable_prefix_delta\tdiff_bytes\tdiff_percent\tfocus_first_mismatch\tfocus_diff_bytes\tfocus_diff_percent\texact_block_coverage_percent\tlost_baseline_exact_blocks\tnew_exact_blocks\tdiff_spans\tedit_diff_bytes\tedit_diff_percent\tedit_insert_bytes\tedit_delete_bytes\tedit_replace_bytes\tedit_equal_bytes\tlikely_shifted_alignment\trelocations\tret_count\tlast_ret_end\textra_after_last_ret\tlikely_context_tail\tlabels\tsource\tobject\tflags\n"
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
                        "1" if result.invariants_ok else "0",
                        " | ".join(result.invariant_failures),
                        "" if result.text_size is None else str(result.text_size),
                        "" if result.compare_size is None else str(result.compare_size),
                        "" if result.frame_size is None else str(result.frame_size),
                        "" if result.first_mismatch is None else str(result.first_mismatch),
                        "" if result.stable_prefix_delta is None else str(result.stable_prefix_delta),
                        str(result.diff_bytes),
                        f"{result.diff_percent:.4f}",
                        "" if result.focus_first_mismatch is None else str(result.focus_first_mismatch),
                        "" if result.focus_diff_bytes is None else str(result.focus_diff_bytes),
                        "" if result.focus_diff_percent is None else f"{result.focus_diff_percent:.4f}",
                        "" if result.exact_block_coverage_percent is None else f"{result.exact_block_coverage_percent:.4f}",
                        ",".join(str(value) for value in result.lost_baseline_exact_blocks),
                        ",".join(str(value) for value in result.new_exact_blocks),
                        str(result.diff_spans),
                        str(result.edit_diff_bytes),
                        f"{result.edit_diff_percent:.4f}",
                        str(result.edit_insert_bytes),
                        str(result.edit_delete_bytes),
                        str(result.edit_replace_bytes),
                        str(result.edit_equal_bytes),
                        "1" if result.likely_shifted_alignment else "0",
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
        f.write("group_id\tcount\texact\texact_count\tinvariants_ok\tinvariant_failures\ttext_size\tcompare_size\tfirst_mismatch\tstable_prefix_delta\tdiff_bytes\tdiff_percent\tfocus_first_mismatch\tfocus_diff_bytes\tfocus_diff_percent\texact_block_coverage_percent\tlost_baseline_exact_blocks\tnew_exact_blocks\tdiff_spans\tedit_diff_bytes\tedit_diff_percent\tlikely_shifted_alignment\trelocations\tret_count\tlast_ret_end\textra_after_last_ret\tlikely_context_tail\trepresentative\tlabels\thash\n")
        for group in groups:
            rep = group.representative
            f.write(
                "\t".join(
                    [
                        group.group_id,
                        str(group.count),
                        "1" if group.exact else "0",
                        str(group.exact_count),
                        "1" if group.invariants_ok else "0",
                        " | ".join(group.invariant_failures),
                        "" if group.text_size is None else str(group.text_size),
                        "" if group.compare_size is None else str(group.compare_size),
                        "" if group.first_mismatch is None else str(group.first_mismatch),
                        "" if group.stable_prefix_delta is None else str(group.stable_prefix_delta),
                        str(group.diff_bytes),
                        f"{group.diff_percent:.4f}",
                        "" if group.focus_first_mismatch is None else str(group.focus_first_mismatch),
                        "" if group.focus_diff_bytes is None else str(group.focus_diff_bytes),
                        "" if group.focus_diff_percent is None else f"{group.focus_diff_percent:.4f}",
                        "" if group.exact_block_coverage_percent is None else f"{group.exact_block_coverage_percent:.4f}",
                        ",".join(str(value) for value in group.lost_baseline_exact_blocks),
                        ",".join(str(value) for value in group.new_exact_blocks),
                        str(group.diff_spans),
                        str(group.edit_diff_bytes),
                        f"{group.edit_diff_percent:.4f}",
                        "1" if group.likely_shifted_alignment else "0",
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
    exact_results = [result for result in results if result.exact and result.invariants_ok]
    axis_sensitivity_lines = write_axis_sensitivity(run_dir, axes, specs, results)
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
    if compile_jobs is not None:
        summary.append(f"Compile jobs: {compile_jobs}")
    if deduped_variants:
        summary.append(f"Deduped variants: {deduped_variants}")
    if workers is not None:
        summary.append(f"Workers: {workers}")
    summary.append(
        "Compile timeout: "
        + ("disabled" if compile_timeout_seconds is None else f"{compile_timeout_seconds:g}s")
    )
    summary.append(f"Compile OK: {compile_ok}")
    summary.append(f"Compile errors: {compile_errors}")
    summary.append(f"Extract errors: {extract_errors}")
    summary.append(f"Tool errors: {tool_errors}")
    summary.append(f"Unique asm groups: {len(groups)}")
    summary.append(f"Exact matches: {len(exact_results)}")
    invariant_ok_count = sum(
        result.status in ("match", "mismatch") and result.invariants_ok for result in results
    )
    if constraints.enabled():
        summary.append(f"Invariant-eligible variants: {invariant_ok_count}/{compile_ok}")
        if constraints.focus_start is not None:
            summary.append(
                f"Focus range: +{constraints.focus_start:04X}-+{constraints.focus_end - 1:04X}"
            )
        required_names = [
            name
            for name, enabled in (
                ("size", constraints.require_size),
                ("frame", constraints.require_frame),
                ("call-set", constraints.require_call_set),
            )
            if enabled
        ]
        if required_names:
            summary.append("Required invariants: " + ", ".join(required_names))
        summary.append(
            "Checker baseline for prefix/block deltas: "
            + ("current" if constraints.baseline_fresh else "unavailable or stale")
        )
    preset_axes = [axis.name[len("preset_") :].replace("_", "-") for axis in axes if axis.kind == "flags" and axis.name.startswith("preset_")]
    if preset_axes:
        summary.append(f"Flag presets: {', '.join(preset_axes)}")
        summary.append("Note: preset flags are appended after default.rsp and are for classification; non-default-flag matches need normal review.")
    if template_expansions:
        summary.append("Template presets: " + ", ".join(record["name"] for record in template_expansions))
    ambient_blocks = [
        block
        for axis in axes
        for block in axis.blocks
        if isinstance(block, AmbientDeclarationsBlock)
    ]
    if ambient_blocks:
        summary.append(
            "Ambient declaration sweeps: "
            + ", ".join(
                f"{block.name}(samples={block.samples}, seed={block.seed}, prefix={block.prefix})"
                for block in ambient_blocks
            )
        )
        summary.append("Note: ambient preambles are compiler-context diagnostics, not recovered source evidence.")
    summary.append("")
    summary.append("Axes:")
    for axis in axes:
        prefix = "flags" if axis.kind == "flags" else "source"
        note = axis_template_note(axis, template_expansions)
        summary.append(f"  {prefix}.{axis.name}: {axis_labels_text(axis)}{note}")
    summary.append("")
    if axis_sensitivity_lines:
        summary.append("")
        summary.append("Exact-match axis sensitivity:")
        summary.extend(axis_sensitivity_lines[:30])
        if len(axis_sensitivity_lines) > 30:
            summary.append(f"  ... +{len(axis_sensitivity_lines) - 30} more axes; see axis_sensitivity.tsv")
    summary.append("")
    summary.append("Text-size histogram:")
    if size_hist_items:
        for size, count in size_hist_items:
            summary.append(f"  {size}: {count}")
    else:
        summary.append("  <none>")
    summary.append("")
    summary.append("Top emitted-code groups (ranking does not assess source plausibility):")
    for group in groups[:20]:
        rep = group.representative
        tail_note = " context-tail" if group.likely_context_tail else ""
        summary.append(
            f"  {group.group_id} count={group.count} exact={int(group.exact)} exact_count={group.exact_count} invariants_ok={int(group.invariants_ok)} text_size={group.text_size} "
            f"compare_size={group.compare_size} first_mismatch={group.first_mismatch} pos_diff={group.diff_bytes} "
            f"focus_diff={group.focus_diff_bytes} prefix_delta={group.stable_prefix_delta} "
            f"blocks={group.exact_block_coverage_percent} lost_blocks={len(group.lost_baseline_exact_blocks)} "
            f"edit_diff={group.edit_diff_bytes} shifted={int(group.likely_shifted_alignment)} reloc={group.relocations} "
            f"last_ret_end={group.last_ret_end} extra_after_ret={group.extra_after_last_ret}{tail_note}"
        )
        if rep:
            summary.append(f"        example: {rep.variant_id} {rep.labels_text}")
            summary.append(f"        artifacts: groups/{group.group_id}/")
            if group.first_mismatch is not None:
                summary.extend(group_mismatch_snippet(group, original_bytes, expected_size, int(va_text, 16)))

    edit_groups = [group for group in groups if group.first_mismatch is not None]
    edit_groups.sort(key=lambda group: (group.edit_diff_bytes, group.diff_bytes, group.first_mismatch or -1, group.group_id))
    if edit_groups:
        summary.append("")
        summary.append("Smallest resync edit diffs (diagnostic, not source quality):")
        for group in edit_groups[:10]:
            rep = group.representative
            summary.append(
                f"  {group.group_id} count={group.count} edit_diff={group.edit_diff_bytes} "
                f"pos_diff={group.diff_bytes} first_mismatch={group.first_mismatch} shifted={int(group.likely_shifted_alignment)}"
            )
            if rep:
                summary.append(f"        example: {rep.variant_id} {rep.labels_text}")
                summary.append(f"        artifacts: groups/{group.group_id}/")

    deepest_groups = [group for group in groups if group.first_mismatch is not None]
    deepest_groups.sort(key=lambda group: (group.first_mismatch or -1, -(abs((group.text_size or 0) - expected_size))), reverse=True)
    if deepest_groups:
        summary.append("")
        summary.append("Deepest first mismatches (diagnostic, not source quality):")
        for group in deepest_groups[:10]:
            rep = group.representative
            tail_note = " context-tail" if group.likely_context_tail else ""
            summary.append(
                f"  {group.group_id} count={group.count} text_size={group.text_size} first_mismatch={group.first_mismatch}"
                f" edit_diff={group.edit_diff_bytes} shifted={int(group.likely_shifted_alignment)} last_ret_end={group.last_ret_end}{tail_note}"
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
        "compile_jobs": compile_jobs,
        "deduped_variants": deduped_variants,
        "workers": workers,
        "compile_timeout_seconds": compile_timeout_seconds,
        "compile_ok": compile_ok,
        "compile_errors": compile_errors,
        "extract_errors": extract_errors,
        "tool_errors": tool_errors,
        "unique_groups": len(groups),
        "exact_matches": len(exact_results),
        "invariant_eligible": invariant_ok_count,
        "constraints": {
            "focus_start": constraints.focus_start,
            "focus_end": constraints.focus_end,
            "require_size": constraints.require_size,
            "require_frame": constraints.require_frame,
            "require_call_set": constraints.require_call_set,
            "original_frame_size": constraints.original_frame_size,
            "baseline_first_mismatch": constraints.baseline_first_mismatch,
            "baseline_exact_blocks": sorted(constraints.baseline_exact_blocks),
            "baseline_fresh": constraints.baseline_fresh,
            "original_call_counts": [
                {"kind": key[0], "target": key[1], "count": value}
                for key, value in sorted(constraints.original_call_counts.items())
            ],
        },
        "flag_presets": [axis.name[len("preset_") :].replace("_", "-") for axis in axes if axis.kind == "flags" and axis.name.startswith("preset_")],
        "ambient_declarations": [
            {
                "axis": block.name,
                "samples": block.samples,
                "seed": block.seed,
                "prefix": block.prefix,
            }
            for axis in axes
            for block in axis.blocks
            if isinstance(block, AmbientDeclarationsBlock)
        ],
        "template_expansions": template_expansions or [],
        "axes": [
            {
                "kind": axis.kind,
                "name": axis.name,
                "labels": axis.labels,
                "blocks": len(axis.blocks),
                "template_note": axis_template_note(axis, template_expansions).strip(),
            }
            for axis in axes
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
        "--splice-base",
        metavar="PATH",
        help="Treat --template as a localized replacement fragment spliced into this full source.",
    )
    parser.add_argument("--splice-start", metavar="MARKER", help="Unique line substring starting a localized splice region.")
    parser.add_argument("--splice-end", metavar="MARKER", help="Unique line substring ending a localized splice region.")
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
    parser.add_argument("--template-help", metavar="NAME", help="Print a reusable @template preset file and exit")
    parser.add_argument("--expand-only", action="store_true", help="Expand @template directives to @choice text and print the effective template; no --va required")
    parser.add_argument(
        "--preview-variants",
        type=int,
        metavar="N",
        help="Print a compact label/size/hash summary for the first N variants and exit; no compile.",
    )
    parser.add_argument(
        "--preview-full",
        action="store_true",
        help="With --preview-variants, also print each complete expanded source and flags.",
    )
    parser.add_argument("--show-variant", metavar="ID", help="Print one expanded variant by index or V000123 and exit; no compile")
    parser.add_argument("--no-dedupe-expanded", action="store_true", help="Disable pre-compile deduping of identical expanded source/flag variants")
    parser.add_argument(
        "--compile-timeout",
        type=float,
        default=DEFAULT_COMPILE_TIMEOUT_SECONDS,
        metavar="SECONDS",
        help=(
            "Stop one compiler job after this many seconds "
            f"(default: {DEFAULT_COMPILE_TIMEOUT_SECONDS:g}; 0 disables the limit)."
        ),
    )
    parser.add_argument(
        "--focus-range",
        metavar="START-END",
        help="Score one inclusive original offset/VA range, e.g. +0490-+04B0.",
    )
    parser.add_argument(
        "--require-size",
        action="store_true",
        help="Require the checker-equivalent effective function size (unreachable context tails ignored).",
    )
    parser.add_argument("--require-frame", action="store_true", help="Require the original prologue frame size.")
    parser.add_argument(
        "--require-call-set",
        action="store_true",
        help="Require exact direct/virtual/indirect call target counts, including COFF symbol identity.",
    )
    parser.add_argument(
        "--session-owner",
        metavar="OWNER",
        help="After a compile run, record the whole lab family as one meaningful variant probe for this active target session.",
    )
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


def splice_template(base_text: str, fragment_text: str, start_marker: str, end_marker: str) -> str:
    """Replace text between two unique marker lines while retaining the markers."""
    base_lines = base_text.splitlines(keepends=True)
    start_rows = [index for index, line in enumerate(base_lines) if start_marker in line]
    end_rows = [index for index, line in enumerate(base_lines) if end_marker in line]
    if len(start_rows) != 1:
        raise ValueError(f"splice start marker must match exactly one line; found {len(start_rows)}")
    if len(end_rows) != 1:
        raise ValueError(f"splice end marker must match exactly one line; found {len(end_rows)}")
    start, end = start_rows[0], end_rows[0]
    if end <= start:
        raise ValueError("splice end marker must occur after the start marker")
    fragment = fragment_text
    if fragment and not fragment.endswith(("\n", "\r")):
        fragment += "\n"
    return "".join(base_lines[: start + 1]) + fragment + "".join(base_lines[end:])


def main(argv: list[str] | None = None) -> int:
    if argv is None:
        argv = sys.argv[1:]
    if not argv:
        parse_args(["--help"])
        return 0
    args = parse_args(argv)
    if args.compile_timeout < 0:
        raise SystemExit("--compile-timeout must be zero or positive")
    splice_values = (args.splice_base, args.splice_start, args.splice_end)
    if any(splice_values) and not all(splice_values):
        raise SystemExit("--splice-base, --splice-start, and --splice-end must be supplied together")
    if args.list_templates:
        for name, path in available_variant_templates():
            print(f"{name}\t{path}")
        return 0
    if args.template_help:
        try:
            print_variant_template_help(args.template_help)
        except ValueError as exc:
            raise SystemExit(str(exc)) from exc
        return 0

    if args.init:
        if not args.va:
            raise SystemExit("--va is required with --init")
        va_text = format_hex(int(args.va, 16))
        init_template(va_text)
        return 0

    if not args.template:
        raise SystemExit("--template is required unless --init, --list-templates, or --template-help is used")

    if args.template == "-":
        template_text = sys.stdin.read()
        template_name = "stdin"
    else:
        template_path = repo_path(args.template)
        template_text = template_path.read_text(encoding="utf-8")
        template_name = str(template_path)

    splice_metadata = None
    if args.splice_base:
        base_path = repo_path(args.splice_base)
        try:
            template_text = splice_template(
                base_path.read_text(encoding="utf-8"),
                template_text,
                args.splice_start,
                args.splice_end,
            )
        except ValueError as exc:
            raise SystemExit(f"splice error: {exc}") from exc
        splice_metadata = {
            "base": str(base_path),
            "fragment": template_name,
            "start_marker": args.splice_start,
            "end_marker": args.splice_end,
        }
        template_name = f"splice {template_name} into {base_path}"

    preset_text = flag_preset_template(args.flag_preset)
    raw_effective_template_text = template_text + preset_text
    try:
        effective_template_text, template_expansions = expand_variant_templates(raw_effective_template_text)
    except ValueError as exc:
        raise SystemExit(f"template expansion error: {exc}") from exc

    if args.expand_only:
        print(effective_template_text, end="" if effective_template_text.endswith("\n") else "\n")
        return 0

    try:
        plan = parse_template(effective_template_text)
        specs = make_specs(plan)
    except ValueError as exc:
        raise SystemExit(f"template parse error: {exc}") from exc
    if not specs:
        raise SystemExit("no variants generated")
    if args.max_variants != 0 and len(specs) > args.max_variants:
        raise SystemExit(
            f"template expands to {len(specs)} variants, exceeding --max-variants {args.max_variants}. "
            "Raise the cap or pass --max-variants 0 for an intentional huge run."
        )

    if args.preview_variants is not None:
        if args.preview_variants < 0:
            raise SystemExit("--preview-variants must be nonnegative")
        print_variant_preview_with_mode(
            plan,
            specs,
            specs[: args.preview_variants],
            full_source=args.preview_full,
        )
        return 0
    if args.preview_full:
        raise SystemExit("--preview-full requires --preview-variants")
    if args.show_variant:
        try:
            spec = select_spec(specs, args.show_variant)
        except ValueError as exc:
            raise SystemExit(str(exc)) from exc
        print_variant_preview(plan, specs, [spec])
        return 0

    if not args.va:
        raise SystemExit("--va is required for compile runs; preview/expand modes do not need it")
    va_text = format_hex(int(args.va, 16))
    va = int(va_text, 16)
    record = function_record_by_va(va)
    slug = function_slug(record)
    expected_size = int(record["size_bytes"])
    if args.session_owner:
        try:
            clean = require_clean_baseline(record, args.session_owner)
        except (RuntimeError, ValueError) as exc:
            raise SystemExit(f"variant lab requires a pinned clean-source baseline: {exc}") from exc
        print(
            "Clean-source reference: "
            f"{str(clean.get('checkpoint_id') or '')[:18]} ({clean.get('note') or '-'})"
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
    original_instructions = decode_instructions(original_bytes, va)
    original_frame = prologue_summary(original_instructions).get("frame_size")
    original_calls = call_fingerprint(original_instructions, original=True)
    baseline_first_mismatch: int | None = None
    baseline_exact_blocks: set[int] = set()
    baseline_diff_path = REPO_ROOT / "build" / "diff" / f"{slug}.json"
    baseline_fresh = bool(current_metric_summary(record).get("artifact_fresh"))
    if baseline_fresh and baseline_diff_path.exists():
        try:
            baseline_payload = json.loads(baseline_diff_path.read_text(encoding="utf-8"))
            baseline_text = str(baseline_payload.get("first_mismatch_offset") or "")
            baseline_first_mismatch = int(baseline_text) if baseline_text else None
            baseline_exact_blocks = {
                int(row["original"]["offset"])
                for row in (baseline_payload.get("block_alignment") or {}).get("rows") or []
                if row.get("status") == "equal" and row.get("original") is not None
            }
        except (OSError, ValueError, TypeError):
            baseline_first_mismatch = None
            baseline_exact_blocks = set()
    focus_start: int | None = None
    focus_end: int | None = None
    if args.focus_range:
        try:
            focus_start, focus_end = parse_focus_range(args.focus_range, va, expected_size)
        except ValueError as exc:
            raise SystemExit(str(exc)) from exc
    constraints = LabConstraints(
        focus_start=focus_start,
        focus_end=focus_end,
        require_size=args.require_size,
        require_frame=args.require_frame,
        require_call_set=args.require_call_set,
        original_frame_size=None if original_frame is None else int(original_frame),
        original_call_counts=dict(
            Counter((str(row["kind"]), str(row["target"])) for row in original_calls)
        ),
        baseline_first_mismatch=baseline_first_mismatch,
        baseline_exact_blocks=baseline_exact_blocks,
        baseline_fresh=baseline_fresh,
    )

    timestamp = time.strftime("%Y%m%d_%H%M%S")
    run_dir = REPO_ROOT / "build" / "variant_lab" / slug / timestamp
    work_root = run_dir / "work"
    ensure_dir(work_root)
    (run_dir / "template_input.cpp").write_text(template_text, encoding="utf-8")
    if splice_metadata:
        (run_dir / "splice.json").write_text(json.dumps(splice_metadata, indent=2), encoding="utf-8")
    if preset_text:
        (run_dir / "flag_presets.tpl").write_text(preset_text, encoding="utf-8")
    if preset_text or template_expansions:
        (run_dir / "effective_template_input.cpp").write_text(effective_template_text, encoding="utf-8")
    if template_expansions:
        (run_dir / "template_expansions.json").write_text(json.dumps(template_expansions, indent=2), encoding="utf-8")

    specs_to_build = specs
    dedupe_children: dict[str, list[VariantSpec]] = {spec.variant_id: [spec] for spec in specs}
    if not args.no_dedupe_expanded:
        rep_by_key: dict[str, VariantSpec] = {}
        dedupe_children = {}
        for spec in specs:
            source_body, extra_flags = variant_build_material(plan, spec, run_dir, work_root, slug)
            key = variant_dedupe_key(source_body, extra_flags)
            rep = rep_by_key.get(key)
            if rep is None:
                rep_by_key[key] = spec
                dedupe_children[spec.variant_id] = [spec]
            else:
                dedupe_children[rep.variant_id].append(spec)
        specs_to_build = [children[0] for children in dedupe_children.values()]

    workers = max(1, (os.cpu_count() or 2) - 1)
    print(f"Variant lab for {slug} ({va_text})")
    print(f"Template: {template_name}")
    if args.flag_preset:
        print(f"Flag presets: {', '.join(args.flag_preset)}")
    if template_expansions:
        print("Template presets: " + ", ".join(record["name"] for record in template_expansions))
    print(f"Run dir: {run_dir}")
    print(f"Variants: {len(specs)}")
    print(f"Compile jobs: {len(specs_to_build)}")
    if len(specs_to_build) != len(specs):
        print(f"Deduped variants: {len(specs) - len(specs_to_build)}")
    print(f"Workers: {workers}")
    print(
        "Compile timeout: "
        + ("disabled" if args.compile_timeout == 0 else f"{args.compile_timeout:g}s")
    )
    print(f"Maximum in-flight jobs: {max(workers, workers * 2)}")
    if constraints.enabled():
        print(
            "Constraints: "
            f"focus={args.focus_range or '-'} size={int(args.require_size)} "
            f"frame={int(args.require_frame)} call_set={int(args.require_call_set)}"
        )

    started_at = time.time()
    built_results: list[VariantResult] = []
    with concurrent.futures.ThreadPoolExecutor(max_workers=workers) as executor:
        pending: dict[concurrent.futures.Future[VariantResult], VariantSpec] = {}
        spec_iter = iter(specs_to_build)
        in_flight_limit = max(workers, workers * 2)

        def submit(spec: VariantSpec) -> None:
            future = executor.submit(
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
                constraints,
                None if args.compile_timeout == 0 else args.compile_timeout,
            )
            pending[future] = spec

        def fill_pending() -> None:
            while len(pending) < in_flight_limit:
                try:
                    submit(next(spec_iter))
                except StopIteration:
                    break

        fill_pending()
        completed = 0
        total_jobs = len(specs_to_build)
        while pending:
            done, _not_done = concurrent.futures.wait(
                pending, return_when=concurrent.futures.FIRST_COMPLETED
            )
            for future in done:
                completed += 1
                spec = pending.pop(future)
                try:
                    built_results.append(future.result())
                except Exception as exc:  # pragma: no cover - defensive for lab robustness
                    text = str(exc)
                    built_results.append(
                        VariantResult(
                            variant_id=spec.variant_id,
                            labels_text=label_text(spec, plan.axes),
                            status="tool_error",
                            error_key=stable_hash(text),
                            error_text=text,
                        )
                    )
                if completed == total_jobs or completed % max(1, total_jobs // 20) == 0:
                    print(f"  completed {completed}/{total_jobs}")
            fill_pending()

    analyze_unique_groups(built_results, original_bytes, expected_size, va, constraints)

    result_by_variant = {result.variant_id: result for result in built_results}
    results: list[VariantResult] = []
    for rep_id, children in dedupe_children.items():
        representative = result_by_variant[rep_id]
        for child in children:
            if child.variant_id == rep_id:
                results.append(representative)
            else:
                results.append(write_dedup_alias_result(representative, child, plan, plan.axes, run_dir, work_root, slug))

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
        compile_jobs=len(specs_to_build),
        deduped_variants=len(specs) - len(specs_to_build),
        workers=workers,
        compile_timeout_seconds=None if args.compile_timeout == 0 else args.compile_timeout,
        constraints=constraints,
    )
    if args.session_owner:
        exact_count = sum(result.exact and result.invariants_ok for result in results)
        eligible_count = sum(result.invariants_ok for result in results)
        relative_run_dir = str(run_dir.relative_to(REPO_ROOT))
        try:
            session = record_probe(
                record,
                args.session_owner,
                "variant",
                (
                    f"variant lab {relative_run_dir}: {len(specs)} variants, "
                    f"{eligible_count} invariant-eligible, {exact_count} exact"
                ),
                evidence={
                    "kind": "variant_lab",
                    "run_dir": relative_run_dir,
                    "variants": len(specs),
                    "compile_jobs": len(specs_to_build),
                    "invariant_eligible": eligible_count,
                    "exact_matches": exact_count,
                },
                detect_output_duplicate=False,
            )
        except (RuntimeError, ValueError) as exc:
            raise SystemExit(
                f"Lab reports were written, but the variant probe could not be recorded: {exc}"
            ) from exc
        print(
            f"Recorded variant probe #{session['probes'][-1]['number']} "
            f"for target session owner {args.session_owner}."
        )
    return 0 if any(result.exact and result.invariants_ok for result in results) else 1


if __name__ == "__main__":
    raise SystemExit(main())
