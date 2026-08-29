# Recovery journal: 0053F3D0 `mouse_right_up_action`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/vw_main.cpp`.
- PDB source: `C:\msdev\work\age1_x1\vw_main.cpp`.
- Earlier recovery note: `recovery_notes/vw_main_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:8d6ef34469bdb10c78bd -->
### `target-session` `build/target_sessions/0053F3D0_mouse_right_up_action.json:1-1`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 2 abi; result=MATCH; diff=0; shape=100.0: Grouped call-slot hypothesis: the shared RGE_Static_Object surface proves vslot +78 is rotate(long), not a later do_right_action slot. [same emitted code as probe 1]
```
<!-- end-recovered:8d6ef34469bdb10c78bd -->

<!-- recovered:150220b451fa31d2214a -->
### `b6e159352e2d` `src/scratch/0053F3D0_mouse_right_up_action.cpp:1-23`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0053F3D0 RGE_Main_View::mouse_right_up_action(long,long,int,int)
// PDB source: vw_main.cpp:1157-1274
//
// Attempt log:
// - baseline reconstruction: restored the RGE_Main_View mouse-action path
//   from the executable, using the canonical player/pick-info ownership and
//   the natural interface-style/game-mode branches.  The local list pointer
//   precedes the 20-byte pick record, matching the observed stack window.
// - control-flow probes: an inverted game_mode test places the command path
//   inline and the nonzero-mode cleanup after it, matching the original CFG;
//   the remaining compiler drift is the initial mode/failure-tail placement.
//   Several equivalent guard/label spellings were tested and rolled back or
//   left only where the late failure line ordering is binary-supported.
// - final bounded state: exact frame/size and 22-call set; 21/22 ordered call
//   sites align.  Remaining drift is a broad VC5 block-layout/register basin,
//   not a proven ownership or behavior discrepancy.
// - structural recovery: split the paused and mouse-action failures into two
//   natural early guards.  This restores the original failure color_log call,
//   all 22 ordered call sites, and the original 647-byte size.  Remaining
//   drift starts at the interface-style global load and the unselect tail.
// - liveness probe: removed the second mode local and used direct program-mode
//   member tests.  This sinks the shared load after the interface-style compare;
//   the result is 9 bytes different with the same size, frame, and call order.
```
<!-- end-recovered:150220b451fa31d2214a -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
