# Function notes: 004CBEF0 `higher_than_target`

Module notes: `decomp_notes/t_c_obj_module.md`.

## Recovered attempt history

<!-- recovered:eef60d0e5e9fef4a055a -->
### `target-session` `build/target_sessions/004CBEF0_higher_than_target.json:1-14`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=143; shape=96.7479674796748: Checked the existing typed period-plausible reconstruction before fresh probes; establish current exactness and mismatch stage.
probe 2 variant; result=MISMATCH; diff=143; shape=96.7479674796748: Tried Ghidra-supported offset-first operand order for secondary tile coordinates; tests whether original ADD lowering came from decompiler-visible Tile_Dy2 + iVar9 form. [same emitted code as probe 1]
probe 3 liveness; result=MISMATCH; diff=143; shape=96.7479674796748: Tried natural branch-local integer accumulators for secondary column and row, using compound assignment to test ADD lowering without changing behavior. [same emitted code as probe 2]
probe 5 liveness; result=MISMATCH; diff=143; shape=96.7479674796748: Tested const-qualified coordinate locals to reduce mutable liveness while preserving typed source and observed local values. [same emitted code as probe 3]
probe 7 variant; result=MISMATCH; diff=143; shape=96.7479674796748: variant lab build\variant_lab\004CBEF0_higher_than_target\20260817_130306: 6 variants, 0 invariant-eligible, 0 exact
probe 8 liveness; result=MISMATCH; diff=163; shape=92.6829268292683: Swapped the natural tile conversion declaration order to test the original two __ftol result colors and declaration-scope hypothesis.
probe 10 variant; result=MISMATCH; diff=163; shape=92.6829268292683: Named-surface lab: replaced generic virtual slot declarations with period method names from the original TRIBE_Combat_Object vtable. Six secondary-call variants all stayed one 705-byte group but lost early exact blocks and worsened diff 143 to 144; not retained.
probe 11 abi; result=MISMATCH; diff=232; shape=95.1219512195122: Tested the decompiler-supported boolean type for the 0/1 diagonal offset, while retaining the natural typed branch and helper calls.
probe 13 control-flow; result=MISMATCH; diff=184; shape=97.15447154471545: Replaced explicit helper result == 0 tests with natural logical negation; checks whether VC5 keeps the original nested call branch while changing secondary argument scheduling.
probe 15 control-flow; result=MISMATCH; diff=143; shape=96.7479674796748: Changed the natural counted do-loop to an equivalent for-loop with the observed pre-guard and countdown backedge, testing source loop-form influence. [same emitted code as probe 5]
probe 19 abi; result=MISMATCH; diff=143; shape=96.7479674796748: Replaced generic virtual slot macros with the binary-supported named TRIBE_Combat_Object vtable surface and real overload names; validates policy-compliant typed context. [same emitted code as probe 18]
probe 23 other; result=MISMATCH; diff=143; shape=96.7479674796748: Tested one-at-a-time branch-local secondary coordinates with offset-first compound assignments; checks whether natural VC5 emits the oracle stack-load plus ADD shape without fake volatility. [same emitted code as probe 22]
probe 25 context; result=MISMATCH; diff=143; shape=96.7479674796748: Moved higher_check_for_cliff from the combat base declaration to the authentic TRIBE_Combat_Object surface, as PDB ownership proves; tests whether owner context controls the ADD versus LEA basin. [same emitted code as probe 23]
probe 27 liveness; result=MISMATCH; diff=143; shape=96.7479674796748: Matched the original local naming/order surface from t_c_obj.cpp: Tile_Dy1, Tile_Dx1, Tile_Dy2, Tile_Dx2, local_8; tests whether authentic direction-local declaration order selects the oracle ADD destination. [same emitted code as probe 25]
```
<!-- end-recovered:eef60d0e5e9fef4a055a -->

<!-- recovered:e95103f080078cfe7fc1 -->
### `180055c75ff3` `src/scratch/004CBEF0_higher_than_target.cpp:1-36`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004CBEF0 TRIBE_Combat_Object::higher_than_target
// Attempt log:
// prior worker: raw offset/vtable reconstruction; same size but broad FPU,
// helper-ABI, and frame drift.
// clean reconstruction: restored the typed combat/static-object coordinates,
// the TRIBE vtable slot for higher_check_for_cliff, and the natural line-step
// source family shared by the movement line walkers.
// probe: this-z greater-than target-z restored the original x87 guard polarity.
// probe: declaring both absolute-step temporaries before their sign tests
// restored the original spill/reload basin, reducing the best result to 143
// differing bytes and a 4-byte size excess.
// probes: direction-plus-tile operand reversal and branch-local offset temps
// were emitted-code duplicates; one-shot direction mutation worsened broadly.
// probe: a natural short-circuit && guard for the sequential helper calls was
// an emitted-code duplicate; restored the nested source form.
// final best: retain the clean typed source and direct secondary-call offsets;
// remaining drift is localized to VC5 scheduling of the two secondary helper
// call argument additions and the resulting late tail displacement.
// fresh pass: coordinate temporaries, operand/order variants, aliases, and
// function-scope tile conversions all emitted the same 705-byte code.
// precomputing both neighbor pairs was worse: 0x50 frame and 723 bytes; restored.
// donor polymorphic static/player declarations were codegen-neutral; restored.
// fresh pass r2: period <stdlib.h> context and several natural neighbor-pair
// lifetime forms were codegen duplicates. Reusing tile coordinates for the
// secondary calls improved size and block coverage but worsened positional
// drift; restored. The remaining source/codegen gap is the oracle's stack-load
// plus ADD sequence versus VC5's equivalent LEA in the second and third calls.
// fresh pass r3: offset-first expressions, branch-local accumulators, const
// coordinate locals, and six structured secondary-call variants were all
// emitted-code duplicates. An incomplete named period virtual surface worsened
// one byte and lost early exact blocks; the corrected binary-supported named
// surface is an emitted-code duplicate. Swapping tile conversion declarations
// worsened the FPU basin by 20 bytes. A bool diagonal offset worsened size by 9 bytes.
// Logical-negation guards improved block coverage but widened the body by 5
// bytes. A natural for-loop was a codegen duplicate. Restored the pinned
// typed source; no policy-valid exact source found.
```
<!-- end-recovered:e95103f080078cfe7fc1 -->
