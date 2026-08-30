# tpnl_obj.cpp module recovery

- PDB source: `C:\\msdev\\work\\age1_x1\\tpnl_obj.cpp`.
- Source: `src/tpnl_obj.cpp`.
- Header: `include/tpnl_obj.h`.
- Flags: `config/flags/gx.rsp`.

## Context gate

- PDB source module: proved by
  `build/source_reunification/terra_system/tpnl_obj_cpp/tpnl_obj_cpp/packet.json`.
- Source lines and order: proved by the packet. The 13 normal owners span lines
  49-1265 in increasing address and source order.
- Owning class: proved by PDB symbols as `TRIBE_Panel_Object` for all owners.
- Address sequence: proved by the packet:
  `0051ADF0`, `0051B070`, `0051B110`, `0051B140`, `0051B160`, `0051B180`,
  `0051B190`, `0051BF90`, `0051C220`, `0051C3F0`, `0051CA10`, `0051CC80`,
  and `0051CC90`.
- Exact anchors: proved by the constructor, destructor, panel calls, shape
  calls, object virtual calls, GDI calls, and saved field offsets in the owner
  packets and original assembly. The constructor is the exact `/GX` anchor.
- Nearby generated owner: `0051B050` is the scalar deleting destructor. It is
  compiler generated and is not a handwritten owner.

## Migration

The module now has one source file and one module-local header. The source keeps
all 13 handwritten definitions in PDB order. It has no wrapper, source-bank
include, function-fragment include, fallback declaration, or context macro.
The header owns the period class. Reviewed provider headers own the object,
panel, API, base-game, and global declarations used by this module.

The old wrapper, context header, and 13 focused source files were removed after
the direct source compiled. `basegame.h` now owns the debug timer declaration.

Format strings and shape names are source literals. The original `.data` bytes
prove `0058B690` is `%d-%s\\0`, `0057F324` is `%s\\0`, and `005870AC` is
`%d/%d\\0`. The original `push` operands occur at `0051B56E`, `0051B58A`,
and `0051B5F1`.

## Validation and regressions

- Generated packet: `build/source_reunification/terra_system/tpnl_obj_cpp/tpnl_obj_cpp/packet.{json,txt}`.
- Candidate proposal: `build/candidate_tus/tpnl_obj.json`.
- Candidate validator: rejected direct-source owners because its pre-migration
  gate requires `src/matching` source-bank includes. It did not replace build
  evidence.
- Grouped audit: `build/observed_audit_spnl_tpnl_final/report.txt`.
- Grouped result: all 13 normal owners compiled. Nine registered owners remain
  exact. Four observed scratch owners remain nonexact.
- Direct checks after the move report `Result: MATCH` and `0.0000%` for
  `0051ADF0`, `0051B070`, `0051B110`, `0051B140`, `0051B160`, `0051B180`,
  `0051C220`, `0051CC80`, and `0051CC90`. Each check also reports
  the original boundary, owner symbol, direct targets, and relocations.
- `0051B190 draw`: grouped mismatch, 3053 positional bytes, owner and boundary
  match. A standalone check cannot select `draw` because the object contains
  four same-class symbols with `draw` in their names.
- `0051BF90 draw_score`: grouped mismatch, 627 positional bytes. The rebuilt
  body is 656 bytes versus 614 original bytes. It keeps the 0x94 frame and all
  17 ordered calls, but one boundary escape remains.
- `0051C3F0 handle_idle`: grouped mismatch, 1338 positional bytes. The rebuilt
  body is 1556 bytes versus 1568 original bytes. It keeps the 0x8C frame and 25
  calls, but the rebuilt virtual call uses vslot `+0x240`; the oracle uses
  `+0x244`.
- `git diff --check` passes.
- The constrained post-recovery grouped audit was run after literal replacement.
- It compiled all 13 owners. The nine registered owners remained exact.
- `draw`, `draw_score`, `handle_idle`, and `save_object_info` remain grouped
  mismatches. They retain `scratch` status.
- Repository-wide validation and source-module inventory jobs were stopped after
  their time budgets. They did not report results. No global audit was started
  after the budget change.

The grouped mismatches are migration regressions. They do not change the four
functions' `scratch` status. The nine exact owners keep `matching` status.

## Blockers

- The assigned
  `build/source_reunification/terra_system/orchestrator_contract.md` file is
  absent from this checkout. The generated module packet is the available
  contract evidence.
- `0051B190` needs a direct checker symbol override or a checker fix before a
  standalone exactness check can run. Its grouped audit is valid.
- `0051BF90` needs a natural frame and block-layout repair. Its current source
  is behavior-oriented but crosses the original boundary.
- `0051C3F0` needs the reviewed shared virtual surface for `get_pierce_armor`.
  A local cast would hide the cross-shard ABI issue and was not added.
- `0051CA10` is scratch. The canonical combat provider emits `get_armor` at
  virtual slot `+0x230`. The oracle uses `+0x22C`. The natural `0.0f` literal
  also removes the oracle `fsub` instruction. No local ABI view or unresolved
  global was added to hide this difference.
