# Recovery journal: 0053A0D0 `start_scroll_view`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/view.cpp`.
- PDB source: `C:\msdev\work\age1_x1\view.cpp`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:fe5b3ccd2bc846bff9c7 -->
### `target-session` `build/target_sessions/0053A0D0_start_scroll_view.json:1-33`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=418; shape=84.71337579617834: Natural typed Pick_Info and named view fields from existing reconstruction; establish current source baseline.
probe 2 liveness; result=MISMATCH; diff=418; shape=84.71337579617834: Delay result initialization until the common path so the return value can reuse the dead action parameter home, matching the original dword zero store. [same emitted code as probe 1]
probe 4 behavior; result=MISMATCH; diff=418; shape=85.98726114649682: Use canonical Pick_Info x,y ownership in the final set_view_loc call; original push order computes y then x, which is natural right-to-left lowering for set_view_loc(x,y).
probe 5 control-flow; result=MISMATCH; diff=418; shape=85.98726114649682: Return the named zero result from both early failure guards instead of literals, testing whether VC5 preserves the original distinct failure exits and result home. [same emitted code as probe 4]
probe 6 abi; result=MISMATCH; diff=418; shape=85.98726114649682: Restore canonical TPanel ownership for the inherited virtual surface and direct capture_mouse call; RGE_View should inherit the first nine vslots and TPanel::capture_mouse.
probe 7 liveness; result=MISMATCH; diff=190; shape=84.71337579617834: Diagnostic only: make the result local volatile to test whether the original four-return/result-home topology comes from a required stack residence; do not retain without natural binary support.
probe 8 liveness; result=MISMATCH; diff=190; shape=84.71337579617834: Diagnostic only: retain action in a named local beside volatile result, testing the prior lead that action liveness can let VC5 reuse its parameter home for the result. [same emitted code as probe 7]
probe 10 abi; result=MISMATCH; diff=418; shape=85.98726114649682: Natural baseline after restoring canonical TPanel ownership and x,y Pick_Info coordinate order; verify direct capture ownership and tail lowering. [same emitted code as probe 6]
probe 11 liveness; result=MISMATCH; diff=418; shape=85.98726114649682: Test register-qualified action formal as a binary-supported probe for the original BL action lifetime across the early calls. [same emitted code as probe 10]
probe 12 liveness; result=MISMATCH; diff=418; shape=85.98726114649682: Swap natural local declaration order so result precedes the address-taken Pick_Info, testing the original action-home/result and saved-register allocation. [same emitted code as probe 11]
probe 13 liveness; result=MISMATCH; diff=415; shape=93.7888198757764: Diagnostic overlap probe: alias a volatile int result to the action parameter home, reflecting the observed dword zero overwrite at entry-relative +4 while preserving the saved action value.
probe 14 liveness; result=MISMATCH; diff=400; shape=81.98757763975155: Diagnostic overlap follow-up: preserve action in a saved byte local while the aliased result overwrites the action home, testing the exact BL-plus-dword-home topology.
probe 15 liveness; result=MISMATCH; diff=400; shape=81.98757763975155: Diagnostic only: register-qualify the saved action byte to avoid its extra stack home while preserving the alias-overwritten parameter value. [same emitted code as probe 14]
probe 16 liveness; result=MISMATCH; diff=419; shape=83.43949044585987: Diagnostic only: remove volatile from the action-home alias to test whether ordinary C++ aliasing preserves the dword result home without the extra stack frame.
probe 17 liveness; result=MISMATCH; diff=375; shape=89.171974522293: Diagnostic address-taken result probe: zero the named result through natural memset, testing whether a forced result home reproduces the original dword store without volatile or alias casts.
probe 18 context; result=MISMATCH; diff=418; shape=85.98726114649682: Test supported period header context alone: retain string.h while restoring natural result initialization, checking whether the header restores the original BL/parameter-home basin. [same emitted code as probe 12]
probe 21 baseline; result=MISMATCH; diff=418; shape=85.98726114649682: Revalidate pinned clean natural typed source before new probes; original saves action in BL, uses one typed 20-byte Pick_Info, and has four returns. [same emitted code as probe 20]
probe 22 liveness; result=MISMATCH; diff=418; shape=85.98726114649682: Natural delayed result assignment after action-specific branches; tests whether VC5 retains original parameter-home result store and four exits without opaque aliases. [same emitted code as probe 21]
probe 24 control-flow; result=MISMATCH; diff=418; shape=85.98726114649682: Natural named paint status returns the API result on the proven zero path; tests whether the original dedicated do_paint failure exit is source-level rather than a compiler artifact. [same emitted code as probe 22]
probe 26 control-flow; result=MISMATCH; diff=412; shape=72.61146496815287: Natural switch over the two action cases; tests whether compiler's sparse dispatch preserves the original saved-action comparison and separate exits.
probe 28 control-flow; result=MISMATCH; diff=418; shape=85.98726114649682: Restore original positive success CFG: pick and do_paint success arms fall through, while failures use separate natural return blocks. [same emitted code as probe 24]
probe 30 liveness; result=MISMATCH; diff=418; shape=85.98726114649682: Natural saved action local mirrors original BL lifetime across early pick/paint calls; no volatile or aliasing. [same emitted code as probe 28]
probe 32 abi; result=MISMATCH; diff=418; shape=85.98726114649682: Canonical ABI correction: declare RGE_View::start_scroll_view virtual, matching original PDB U-qualified symbol and reviewed class surfaces. [same emitted code as probe 30]
probe 33 abi; result=MISMATCH; diff=418; shape=85.98726114649682: Restore proven RGE_View virtual slot surface: pick_through_fog vt56, pick_weight vt57, start_scroll_view vt58, handle vt59, end vt60, do_paint vt61. [same emitted code as probe 32]
probe 34 abi; result=MISMATCH; diff=417; shape=85.98726114649682: Use the full same-TU TPanel ABI and typed base ownership, with RGE_View fields at canonical offsets; tests whether the narrow inherited surface caused the structural basin.
probe 35 abi; result=MISMATCH; diff=418; shape=85.98726114649682: Complete TPanel already owns slots 0-55; remove duplicate RGE_View dummies so pick_through_fog/start/handle/end/do_paint occupy proven slots 56-61. [same emitted code as probe 33]
probe 36 control-flow; result=MISMATCH; diff=418; shape=85.98726114649682: Natural direct Pick_Info coordinate expressions in set_selection_area; tests whether named col/row locals caused EBX versus original action-home reuse. [same emitted code as probe 35]
probe 38 liveness; result=MISMATCH; diff=418; shape=85.98726114649682: Natural delayed result declaration and assignment at the common path; tests the original parameter-home zero store without volatile. [same emitted code as probe 37]
probe 39 liveness; result=MISMATCH; diff=190; shape=84.71337579617834: Diagnostic volatile result under the canonical virtual ABI; measures whether the original four-return and parameter-home topology requires compiler-forbidden volatility. [same emitted code as probe 8]
probe 40 behavior; result=MISMATCH; diff=218; shape=80.89171974522293: Natural result state machine: initialize result to zero, set it to one in the success arm, and return it once; tests the original late result-home store and four returns without volatility.
probe 41 layout; result=MISMATCH; diff=218; shape=80.89171974522293: Natural declaration-order probe: place the state result before the 20-byte Pick_Info local, testing whether VC5 reuses the original parameter home without an extra frame. [same emitted code as probe 40]
probe 42 liveness; result=MATCH; diff=0; shape=100.0: Natural delayed result state: declare the result, zero it after action-specific branches, set one only in final success, and return it; tests source-level late lifetime.
probe 45 abi; result=MATCH; diff=0; shape=100.0: Module closure: virtual start_scroll_view declaration restores UAE symbol. [same emitted code as probe 44]
```
<!-- end-recovered:fe5b3ccd2bc846bff9c7 -->

<!-- recovered:fa7beda5c427c3d62ae9 -->
### `dcfcd3907d5a` `src/scratch/0053A0D0_start_scroll_view.cpp:1-40`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0053A0D0 RGE_View::start_scroll_view
// PDB: view.cpp:5854-5914
// Fresh reconstruction: the pick result is the period RGE_Pick_Info object;
// the view owns the mouse-down and scroll fields at their proven offsets.
// Prior worker notes remain useful evidence: the former volatile stub forced
// the right frame but did not reproduce the source-level register schedule.
//
// Attempt log (normal-53A0D0-r1):
// 1: natural typed Pick_Info and named view fields: 397 B, 16 calls, 4 fewer returns.
// 2: delayed result initialization: codegen duplicate.
// 3: reused the action parameter as the zero result: codegen duplicate.
// 4: volatile result restored four returns and reached 421 B; retained as diagnostic.
// 5: declaration-order change: codegen duplicate.
// 6: saved action local: codegen duplicate.
// 7: volatile action local: 425 B and worse block coverage; rolled back.
// 8: register-qualified action local: codegen duplicate; rolled back.
// 9: reused result for the first converted coordinate: 441 B, 335 strict diff.
// 10: reversed conversion order: 437 B, 338 strict diff; exact-codegen stage.
// Final: restored the clean natural source. Remaining lead is result-home and
// action-register scheduling. Diagnostic volatile forms are not retained.
// 11: use one saved action value for dispatch and scroll state; codegen was
// unchanged at 397 B / 418 strict-diff bytes, so the natural baseline remains.
// 12: direct final return instead of a synthetic result local; codegen was
// unchanged at 397 B / 418 strict-diff bytes, so the baseline was restored.
// 13: delayed result assignment remained a codegen duplicate.
// 14: volatile result plus saved action restored the target prologue, four
//     returns, and 437-byte size; result-home argument reload was one extra.
// 15: plain result removed that structure; rolled back.
// 16: hoisted col/row locals were a duplicate; rolled back.
// 17: plain col with volatile final result reached 421 B / 414 diff.
// 18: cached the volatile y conversion into plain col; reached 429 B / 66 diff.
// 19: a raw local read at +8 reached 437 B / 2 diff with exact calls,
//     returns, and all other bytes aligned. It has no proven field ownership.
// 20: named first view-y value was a codegen duplicate.
// 21: offset +4 collapsed the distinct late expression and regressed to 66.
// 22: alternate alias spelling also regressed to 66; restored the offset +8
//     diagnostic form as the best binary-supported reconstruction.
// 23: normalized the living source by removing codegen-only volatile/register
//     scheduling and the raw +8 read. Close scheduling evidence remains in
//     checkpoint probe-026.
```
<!-- end-recovered:fa7beda5c427c3d62ae9 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
