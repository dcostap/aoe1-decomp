# scr_name.cpp source recovery

## Module

- PDB source: `C:\\msdev\\work\\age1_x1\\scr_name.cpp`.
- Source: `src/scr_name.cpp`.
- Header: `include/scr_name.h`.
- Flags: `config/flags/scr_name.rsp`.
- Normal owners: 11, in PDB source-line and address order.
- Generated entries: `004A66C0` vector deleting destructor and `004A6F40`
  scalar deleting destructor. They have no handwritten source owners.

## Context gate

- PDB source module: proved by `build/tu_plans/scr_name_cpp/packet.json`.
- Source lines and order: proved by the packet. The normal owners span lines
  50-440 in increasing address and source order.
- Owning classes: proved by PDB symbols as `TRIBE_Screen_Name` for
  `004A63D0` through `004A69B0`, and `TRIBE_Dialog_Name` for `004A6D50`
  through `004A71D0`.
- Address sequence: proved by the packet:
  `004A63D0`, `004A66E0`, `004A67C0`, `004A6800`, `004A68C0`, `004A6980`,
  `004A69B0`, `004A6D50`, `004A6F60`, `004A6FF0`, and `004A71D0`.
- Exact anchors: proved by the screen constructor, screen destructor, screen
  action, dialog destructor, dialog action, and the two generated destructors.
  The constructor and both actions use the `/GX` exception frame in the
  module response file.

## Migration

The old wrapper was `src/scr_name_tu.cpp`. It selected declarations with
`SCR_NAME_TU_CONTEXT` and included one source-bank fragment for each owner.
The new `src/scr_name.cpp` owns all 11 handwritten definitions in PDB order.
`include/scr_name.h` owns the module declaration and proven panel layouts.

The source has no wrapper, source-bank include, function-fragment include,
fallback declaration, context macro, fake virtual slot, raw vptr, inline
assembly, or codegen-only function. The two deleting destructors remain
compiler-generated. The module header retains the three-word tab window in
the dialog constructor because the original stack and register schedule prove
that shape.

The constructor string operands are natural literals. The original data bytes
identify `"Name Selection Screen"`, `"scr2"`, `"New Name Dialog"`,
`"Campaign Selection Screen"`, `"Single Player Menu"`, and `"YesNoDialog"`.
The source uses literals and has no raw address casts.

## Validation

The constrained candidate translation-unit proposal is
`build/candidate_tus/scr_name_natural/proposal.json`. Its report is
`build/candidate_tus/scr_name_natural/report.{json,txt}`.

- All 10 existing exact owners returned `MATCH` and `0.0000%`.
- Both generated deleting destructors returned `MATCH` and `0.0000%`.
- `004A6D50` remains an accepted-drift owner. It differs by 86 bytes,
  with zero relocation-target mismatches and zero boundary escapes.
- The candidate compiled the direct source module. It did not alter global
  translation-unit registration.

## Regressions and blockers

The migration has no new exact-owner regression. The accepted-drift
constructor retains its prior 86-byte difference. Its frame, calls, and
boundary remain stable.

The repository translation-unit registry still names the old wrapper and
source-bank paths. The coordinator must register `src/scr_name.cpp` as the
module source and direct owner for all 10 exact owners after integration. This
captain did not edit global ownership under the module assignment contract.

The requested orchestrator contract at
`build/source_reunification/terra_system/orchestrator_contract.md` is absent
from this checkout. The generated module packet is the available contract
record.
