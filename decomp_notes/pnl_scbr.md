# Pnl_scbr.cpp source recovery

## Module

- PDB source: `C:\msdev\work\age1_x1\Pnl_scbr.cpp`
- Source: `src/Pnl_scbr.cpp`
- Header: `include/Pnl_scbr.h`
- Owners: 19 normal functions in PDB source-line order.
- Generated entry: `0047A880`, scalar deleting destructor, excluded from source ownership.

The address sequence is `0047A700`, `0047A8A0`, `0047A8B0`, `0047A910`,
`0047AA80`, `0047AB20`, `0047AC10`, `0047AC30`, `0047AC70`, `0047ACC0`,
`0047AE40`, `0047AFD0`, `0047B3D0`, `0047B420`, `0047B4E0`, `0047B660`,
`0047B690`, `0047B8B0`, and `0047B970`.

PDB lines run from 66 through 836. The class owner is `TScrollBarPanel`.
The module header owns the reviewed `TPanel`, `TDrawArea`, `TShape`, and
`TScrollBarPanel` declarations. The class sizes are 0xF4 and 0x1C4 bytes.

## Context evidence

The PDB source path, line bands, and address sequence identify this module.
The constructor, setup, scrollbar event handlers, and drawing methods provide
exact anchors to the same `TScrollBarPanel` surface. The prior wrapper used
this header and produced the registered exact owners.

The requested Terra contract file was absent at
`build/source_reunification/terra_system/orchestrator_contract.md` in this
worktree. The generated packet at
`build/source_reunification/packet/Pnl_scbr_cpp/packet.{json,txt}` is present
and records the same 19 owners.

## Migration record

The old wrapper was `src/pnl_scbr_tu.cpp`. It included one owner fragment per
function. The new source owns all 19 function bodies in PDB order. It has one
module header and no owner includes, source-bank declarations, or context
macro. The old wrapper and 19 fragment files are removed after review.

The source keeps the period header context proved by the prior exact checks.
The two `<new.h>` include points remain in source order because they are part
of the tested compiler context, not an owner wrapper.

`0047AA80_calc_item_rects` now uses direct rectangle members. The old accepted
candidate used a volatile field read to control instruction scheduling. That
form was removed during migration. The output is expected to regress until
exact repair resumes on the final source tree.

## Baseline and regressions

`tools/validate_candidate_tu.py` passed the old wrapper proposal:

- 15 of 15 registered exact owners matched.
- The compiler-generated destructor matched through its weak fallback.
- The four observed owners remained nonexact.
- Observed strict differences were 137 bytes at `0047A910`, 34 bytes at
  `0047AA80`, 192 bytes at `0047AB20`, and 318 bytes at `0047AFD0`.
- All checked owners had zero relocation target mismatches.
- Only `0047AB20` had one boundary escape.

The candidate proposal is
`build/source_reunification/packet/Pnl_scbr_cpp/proposal.json`.
The report is under `build/candidate_tus/pnl_scbr/`.

A direct compile of `src/Pnl_scbr.cpp` passed. Its local comparison matched 15
normal owners and the generated destructor. The four nonexact owners remained
nonexact. A fresh registered translation-unit check is pending the orchestrator
ownership registration. The migration changes source ownership by design. It
does not change function behavior to hide a temporary exactness regression.

The direct comparison report is under
`build/candidate_tus/pnl_scbr_direct/`. It reports zero relocation target
mismatches for every owner and zero boundary escapes for every owner except
`0047AB20`, which retains one boundary escape.

The current direct-source strict differences are 137 bytes at `0047A910`,
139 bytes at `0047AA80` with a 141-byte rebuilt body, 192 bytes at `0047AB20`
with a 243-byte rebuilt body, and 318 bytes at `0047AFD0`. The `0047AA80`
change is the expected effect of removing the scheduling-only volatile read.

## Open blockers

- `0047A910` still has an early EBP and register-topology mismatch.
- `0047AFD0` still needs a source or compiler-context reconstruction.
- `0047AA80` and `0047AB20` are scratch pending final-source exact repair and
  review. `0047AA80` has 139 differing bytes and 55.26% instruction-shape
  similarity in the current natural source. `0047AB20` has 192 differing
  bytes and one boundary escape. Neither row is accepted-drift safe.
- The Terra orchestrator contract path is absent from this worktree.
