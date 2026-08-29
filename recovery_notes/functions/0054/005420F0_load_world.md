# Recovery journal: 005420F0 `load_world`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/world.cpp`.
- PDB source: `C:\msdev\work\age1_x1\World.cpp`.
- Earlier recovery note: `recovery_notes/world_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:457eaaf00377f72f3987 -->
### `26f012a10f3d` `src/scratch/005420F0_load_world.cpp:1-47`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 005420F0 RGE_Game_World::load_world
// PDB source: World.cpp lines 1021-1107
//
// Attempt log:
// - The prior raw-offset candidate had the correct 31-call surface and was
//   615 bytes, but cross-member cursors made player_num/player_time_delta
//   ownership opaque and left the first structural drift after load_map.
// - This reconstruction names the serialized world fields and map/player
//   ownership while retaining the
//   original narrow read widths and +0x34/+0xF4 dispatch surfaces.
// - Typed virtual declarations moved the candidate from 247 differing bytes
//   to 45 and then the short player-count temporary plus positive version gate
//   reached an 8-byte, 99.07% shape candidate with all 31 calls aligned.
// - Remaining bytes are localized to VC5 scheduling: `test ax, ax` versus the
//   original `cmp ax, bp`, and the players-field store occurring three bytes
//   before the original flag-preserving store position. A short-index predicate
//   regressed the whole tail and was rolled back.
// - Paused after the bounded 10-hypothesis budget; no inline asm or raw
//   absolute-address macros are retained.
// - Main-agent audit removed the player-count pointer and file-parameter byte
//   reuse. Named count/save-state locals are the plausible serialization source;
//   prior stack-home proximity remains diagnostic only.
// - This pass recovered the later 614-byte/31-call basin, with a natural
//   direct player_num gate leaving only the two-byte `test ax,ax` versus
//   original `cmp ax,bp` hunk.  Player-index comparisons, narrow-index and
//   zero aliases, declaration/initialization movement, and explicit signed or
//   unsigned 16-bit predicates either duplicated that basin or worsened the
//   tail.  A seven-case focused gate lab found no exact emitted variant.
// - Final source keeps named member ownership rather than the diagnostic
//   short-count alias; remaining drift is a compiler comparison/register
//   scheduling basin with all calls, size, frame, CFG, and memory effects
//   aligned.
// - Tested the natural same-TU guard `i < player_num` with the live zero
//   player-loop index at the first allocation gate; VC5 widened the compare,
//   shifted the hunk earlier, and regressed to 244 differing bytes. Rolled back.
// - A separate short initial-index local, a union alias for the 16/32-bit loop
//   index, and a cached short count all reproduced the 2-byte test basin.
// - Reusing the cleared old_time field as the zero RHS widened the first load
//   and regressed to 247 bytes. Restored the natural direct player_num guard.
// - Comparing the first allocation gate against old_time's low word emitted a
//   memory compare and 229 differing bytes; restored the clean source.
// - Reloading old_time into the loop index after initialization changed the
//   zero-store schedule and reached 278 differing bytes; restored.
// - Corrected initializePathingSystem to its proven int return ABI; emitted
//   bytes stayed unchanged at the 2-byte cmp/test basin, so the ABI is kept.
// - Adding an explicit nonnegative loop-index conjunct regressed to 244 bytes;
//   reversing the direct comparison operands reproduced the 2-byte basin.
```
<!-- end-recovered:457eaaf00377f72f3987 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
