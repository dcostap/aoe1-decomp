# Recovery journal: 0043C2B0 `action`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/dlg_conf.cpp`.
- PDB source: `C:\msdev\work\age1_x1\dlg_conf.cpp`.
- Earlier recovery note: `recovery_notes/dlg_conf_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:2b3a02cab41869420d8e -->
### `d050eea3c` `src/dlg_conf.cpp:439-440`

Mapping: `strong`. comment lies after mapped function action at old line 437.

```text
// dlg_conf.cpp:377-647.
// The action remains scratch.  Keep the shipped branch and call ordering.
```
<!-- end-recovered:2b3a02cab41869420d8e -->

<!-- recovered:09c890756caf58dbea4d -->
### `target-session` `build/target_sessions/0043C2B0_action.json:1-32`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=1493; shape=81.91721132897604: Restored the missing reviewed rge_base_game extern include so the committed source can compile; establish clean metrics.
probe 2 abi; result=MISMATCH; diff=1493; shape=81.91721132897604: Hypothesis 1: remove register qualifiers from event and param_3; test whether ordinary parameter allocation restores original EBP/EDI entry homes. [same emitted code as probe 1]
probe 3 liveness; result=MISMATCH; diff=1493; shape=81.91721132897604: Hypothesis 2: preload param_3 into an explicit action_value local and use it in the scroll-slider writes; test whether VC5 reproduces the original entry param_3 read/home.
probe 4 control-flow; result=MISMATCH; diff=1583; shape=82.57080610021787: Hypothesis 3: split the combined OK-panel/event guard into nested guards; test whether original VC5 preserves event in EDI and the original early block topology.
probe 5 context; result=MISMATCH; diff=1493; shape=81.91721132897604: Hypothesis 4: remove the broad generated game_globals include while retaining the reviewed rge extern; test whether same-TU header state is the structural blocker.
probe 6 control-flow; result=MISMATCH; diff=1569; shape=86.6943866943867: Hypothesis 5: anchor the shared slider call before the scroll/cancel dispatch with an explicit non-slider jump; test whether VC5 restores original C7CB call placement and ordered calls.
probe 7 behavior; result=MISMATCH; diff=1606; shape=85.48387096774194: Hypothesis 6: duplicate the shared slider set_volume source expression in music and sound arms; test whether VC5 tail-merges naturally without explicit non-slider jumps.
probe 8 control-flow; result=MISMATCH; diff=1569; shape=86.6943866943867: Hypothesis 7: place the shared slider label inside the sound-slider arm, so the music arm jumps into the original common arithmetic/call tail without an explicit non-slider bypass.
probe 9 control-flow; result=MISMATCH; diff=1493; shape=81.91721132897604: Hypothesis 8: nest each speed-button event test instead of a combined &&; test whether VC5 stops tail-merging the three original mov edi return blocks.
probe 10 layout; result=MISMATCH; diff=1493; shape=81.91721132897604: Hypothesis 9: restore the exact same-TU TPanel object size (0xF4) and derived gap boundary from the matching destructor donor while preserving all proven offsets. [same emitted code as probe 2]
probe 11 behavior; result=MISMATCH; diff=1493; shape=81.91721132897604: Hypothesis 10: use literal 1 for the cancel-path singlePlayerGame comparison, matching the original cmp eax,1 rather than carrying event into that branch. [same emitted code as probe 10]
probe 12 abi; result=MISMATCH; diff=1493; shape=81.91721132897604: Hypothesis 11: mark panel as a register parameter, matching the original entry EAX use and testing whether VC5 preserves panel across the dispatch. [same emitted code as probe 11]
probe 13 behavior; result=MISMATCH; diff=1570; shape=75.51020408163265: Hypothesis 12: make the proven null-panel edge explicit to base_action; the prior wrapper let VC5 place null flow at the uninitialized slider tail instead of original C80D.
probe 14 behavior; result=MISMATCH; diff=1607; shape=84.44444444444444: Hypothesis 13: use a direct null-panel base action return instead of an explicit goto and compound block; test correct null behavior with less register-pressure drift.
probe 15 behavior; result=MISMATCH; diff=1570; shape=75.51020408163265: Hypothesis 14: use the explicit null-to-base_action goto without an extra compound scope; isolate whether the prior EBX drift came from scope rather than the behavior edge. [same emitted code as probe 13]
probe 16 behavior; result=MISMATCH; diff=1615; shape=81.72043010752688: Hypothesis 15: guard the compiler-placed slider tail against panel==0 and redirect to base_action; preserve clean main layout while repairing the wrapper's proven null behavior.
probe 17 control-flow; result=MISMATCH; diff=1494; shape=79.73856209150327: Hypothesis 16: reverse all panel/member equality operands; original uses direct cmp eax,[esi+field] while the prior source forced member loads into ECX.
probe 18 control-flow; result=MISMATCH; diff=1493; shape=81.91721132897604: Hypothesis 17: reverse only the initial OK-panel comparison to target the original direct cmp eax,[esi+544] without perturbing later dispatch comparisons.
probe 19 control-flow; result=MISMATCH; diff=1493; shape=81.69934640522875: Hypothesis 18: reverse only the cancel-button comparison as a focused direct-memory compare test, after the initial OK comparison showed a one-byte gain.
probe 20 control-flow; result=MISMATCH; diff=1493; shape=81.48148148148148: Hypothesis 19: reverse only sizeButton[0] equality to test whether the original size dispatch's direct memory compare is source-order sensitive.
probe 23 behavior; result=MISMATCH; diff=1494; shape=81.91721132897604: Hypothesis 1: use event, not param_3, for interface_style fallback; original overwrites EBP from event before the single-player and style stores, while current source kept param_3 live.
probe 25 control-flow; result=MISMATCH; diff=1493; shape=81.91721132897604: Hypothesis 2: reverse only the initial OK-button equality so VC5 can emit the original direct cmp eax,[esi+544] instead of a member preload. [same emitted code as probe 18]
probe 27 control-flow; result=MISMATCH; diff=1607; shape=84.44444444444444: Hypothesis 3: use a natural early null-panel return to feed the proven base-action path and force the entry parameter reads before dispatch. [same emitted code as probe 14]
probe 29 control-flow; result=MISMATCH; diff=1570; shape=75.51020408163265: Hypothesis 4: restore the binary-proven null-panel goto to base_action while keeping the current natural class and field model; positive-wrapper fallthrough currently reaches an uninitialized slider tail. [same emitted code as probe 15]
probe 31 liveness; result=MISMATCH; diff=1494; shape=81.91721132897604: Hypothesis 5: preserve the binary's event value as the shared 1-valued source operand for the interface, rollover, path, registry, and track calls; original keeps EDI/event in EBP instead of rematerializing literals. [same emitted code as probe 23]
probe 33 abi; result=MISMATCH; diff=1493; shape=81.91721132897604: Hypothesis 6: mark the panel parameter register-qualified to test whether the original entry EAX and early panel comparison require a register-facing parameter declaration. [same emitted code as probe 22]
probe 35 behavior; result=MISMATCH; diff=1570; shape=75.51020408163265: Hypothesis 7: preserve the current positive wrapper but add the missing null fallthrough to base_action before the slider tail; this fixes the proven null fault without a new guard or class alias. [same emitted code as probe 29]
probe 37 control-flow; result=MISMATCH; diff=1570; shape=75.51020408163265: Hypothesis 8: place the base_action label before the slider tail so null falls through naturally while slider branches still jump over it; this models the proven shared base edge without an explicit guard.
probe 39 behavior; result=MISMATCH; diff=1502; shape=80.82788671023965: Hypothesis 9: route null music/sound slider systems to the shared destroyPanel tail; original C74B/C754/C7B8 all branch to 0043C91A, while clean source incorrectly returns directly.
probe 41 control-flow; result=MISMATCH; diff=1509; shape=81.06382978723404: Hypothesis 1: express the proven null-panel base-action edge as an early null guard, then keep the dispatch body unwrapped; the original loads event and param_3 before the guard.
probe 43 abi; result=MISMATCH; diff=1502; shape=80.82788671023965: Hypothesis 2: remove explicit register qualifiers from event and param_3; original parameter homes may come from natural VC5 liveness rather than source register hints.
probe 44 behavior; result=MISMATCH; diff=1570; shape=75.51020408163265: Final behavior reconstruction: direct slider null returns preserve jumps to 0043C91A; cancel singlePlayerGame uses shipped literal 1; base_action is the natural null and scroll fallback before slider tail. Metrics remain structural, not exact.
```
<!-- end-recovered:09c890756caf58dbea4d -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
