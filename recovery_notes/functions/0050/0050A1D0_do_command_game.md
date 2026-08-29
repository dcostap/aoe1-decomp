# Recovery journal: 0050A1D0 `do_command_game`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/tcommand.cpp`.
- PDB source: `C:\msdev\work\age1_x1\tcommand.cpp`.
- Earlier recovery note: `recovery_notes/tcommand_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:5e6da189071d352fe7e0 -->
### `b6e159352e2d` `src/scratch/0050A1D0_do_command_game.cpp:1-16`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0050A1D0 TRIBE_Command::do_command_game
// Source: tcommand.cpp lines 531-665
// Attempt log:
// 1: broad natural switch reconstruction from packet; models simple command cases and restart/new-game cleanup path approximately; compiles too small (640 vs 661).
// 2: tried /GX because original has SEH/EH prologue; no size/prologue change in this harness with the fake ctor surface, flag removed.
// 3-10: fake helper names, raw absolute globals, and an omitted status-message constructor left the call multiset and EH source model wrong; retained only as prior negative evidence.
// Current baseline: restored the binary-proven command mapping, named globals, real member/helper surfaces, and a natural TRIBE_Screen_Status_Message new-expression before codegen probes.
// 11: exact RGE/TRIBE/panel/communications names plus real virtual slots recovered all 30 ordered calls; /GX and the status-message constructor restored the 0x108 EH frame.
// 12: reordered switch cases to the original 5,0,1,8,2,4,6,7 source order and restored default; output is 661 B with 185 instructions, 30/30 calls, exact CFG, and 196 strict bytes.
// Current pause: remaining drift is dominated by standalone unresolved data/string relocations (extern globals and literals emit zero-address placeholders instead of original absolute data); raw absolute-address macros are disallowed by policy. A localized short-register difference remains in TRIBE_World::cheat.
// Main-agent audit removed the diagnostic +4 formatting-buffer window and restored
// compiler-owned polymorphic world ownership. The direct buffer is authoritative.
// 13: tested the repeated donor RGE_Base_Game* type for 0062C574 with explicit
// TRIBE_Game casts; the emitted code was a duplicate, so the direct TRIBE_Game*
// declaration was restored. Standalone compilation cannot bind this data symbol.
// 14: removed the unused status-pointer void-use; emitted code was unchanged, so the natural result lifetime is not the remaining drift.
```
<!-- end-recovered:5e6da189071d352fe7e0 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
