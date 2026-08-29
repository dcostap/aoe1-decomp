# Recovery journal: 004C9B10 `remove_from_production_queue`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/t_b_obj.cpp`.
- PDB source: `C:\msdev\work\age1_x1\t_b_obj.cpp`.
- Earlier recovery note: `recovery_notes/t_b_obj_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:b257186dae84ed72eabd -->
### `229902baf232` `src/scratch/004C9B10_remove_from_production_queue.cpp:1-50`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004C9B10 TRIBE_Building_Object::remove_from_production_queue(short, short)
// PDB source: t_b_obj.cpp lines 1047-1092 (355 bytes, 97 asm lines)
// Default flags
//
// __thiscall: this in ecx, 2 stack params (short master_id, short max_remove). ret 8 cleanup.
// Removes up to max_remove units of master_id from the production queue.
//
// Current reconstruction is intentionally kept in scratch.  The natural
// single-index form with top-declared locals recovers the original EBX index,
// EDI record stride, EBP reimbursement countdown, frame, calls, and most block
// bytes.  The remaining VC5 drift is the backward-search branch polarity and
// the source-level schedule of the game counter decrement; it is not a
// behavior or ownership uncertainty.
//
// Attempt log:
// - Replaced the two-index decompiler-shaped search with one named queue index
//   plus an int reimbursement count and copy index; this restored the original
//   saved-register coloring and substantially improved CFG/size parity.
// - Tried positive continuation, do/while, and labeled-search spellings for the
//   jge-back/jmp-final search topology; all were worse or introduced extra
//   blocks, so the ordinary while form remains the living source.
// - Recovered the proven RGE_Base_Game virtual surface and named counter field;
//   raw save_music_file pointer arithmetic was rejected as noncanonical.
// - Left unresolved: exact VC5 search branch layout and the separate global
//   load/LEA/decrement schedule.  The current source remains behaviorally typed
//   and period-plausible rather than retaining metric-only pointer scaffolding.
//
// Field layout (TRIBE_Building_Object):
//   owner_player               +0x0C (TRIBE_Player*)
//   production_queue            +0x1C8 (ProductionEntry*, 4-byte entries: {short id, short count})
//   <unknown 2-byte gap>       +0x1CC
//   production_queue_count      +0x1CE (short)
//   gap                        +0x1D0 (4 bytes to align pointer)
//   production_queue_actions    +0x1D4 (RGE_Action_List*)
//   production_queue_change_flag +0x1D8 (unsigned char)
//   production_queue_need_attr +0x1DA (short, -1 = none)
//
// Behavior:
//   1. if queue_count == 0, return
//   2. Search backwards from queue_count-1 for matching master_id
//   3. If found, reimburse up to max_remove units (clamped to unit_count)
//   4. Decrease unit_count by max_remove, increment change flag
//   5. If unit_count <= 0: decrement queue_count, shift entries left
//   6. If removed index 0 and need_attr != -1:
//      - If need_attr == 4: decrement the named game counter at +0xA34
//      - Set need_attr = -1
//      - Stop and delete production_queue_actions
//   7. Call the RGE_Base_Game notification slot with (0x7C, player_id, 0, 0, 0)
// Main-agent audit restored canonical polymorphic player/game/building ownership
// and retained the natural indexed queue search/copy.
```
<!-- end-recovered:b257186dae84ed72eabd -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
