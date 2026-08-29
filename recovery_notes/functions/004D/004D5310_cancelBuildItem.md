# Recovery journal: 004D5310 `cancelBuildItem`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/taibldmd.cpp`.
- PDB source: `C:\msdev\work\age1_x1\taibldmd.cpp`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:cdf6e13fd2a0622f9b75 -->
### `target-session` `build/target_sessions/004D5310_cancelBuildItem.json:1-1`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MATCH; diff=0; shape=99.4186046511628: Fresh standalone baseline; source owner, calls, and boundary checked before TU repair.
```
<!-- end-recovered:cdf6e13fd2a0622f9b75 -->

<!-- recovered:7f814560395160a7a604 -->
### `6e2375c51785` `src/scratch/004D5310_cancelBuildItem.cpp:1-12`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 004D5310 TribeBuildAIModule::cancelBuildItem
// Attempt log:
// 1: natural implementation from packet/decompiler with local typed surfaces: broad mismatch; compiler used sub esp,10 and byte jump table, original uses push ecx one local and direct address jump table.
// 2: remove named float corner locals and use direct clearArea expressions to reduce frame pressure: prologue now matches through first call; mismatch starts at switch because VC5 chose byte dispatch table.
// 3: switch on action+1 to encourage direct address jump table like original: no change, VC5 still emits compact byte dispatch table because many cases collapse.
// 4: prologue/frame now matches after removing named float corner locals; first mismatch is switch/local store at 004D5333.
// 5: current source models detask, lot-status dispatch, object/isMoveable gates, construction lot vs fallback clearArea, construction remove, build-list update, removeLot, and wonder reset.
// 6: remaining early mismatch is not accepted-drift-safe: switch dispatch shape differs (original direct address jump table, rebuilt byte-index table) and cascades branch offsets/control layout.
// 7: FPU clearArea expression ordering is only approximate; original calls y/ySize/x/xSize twice in a specific sequence with push-placeholder temporaries.
// 8: removeLot tail uses __ftol on y then x and passes newLotStatus; current source likely matches behavior but has not reached exact arg/register staging.
// 9: virtual constructionAI calls are modeled as virtual slots +0x4C/+0x58 but exact class surface may still be incomplete.
// 10: left in scratch: broad mismatch remains after meaningful source-shape attempts; not accepted_drift-safe.
```
<!-- end-recovered:7f814560395160a7a604 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
