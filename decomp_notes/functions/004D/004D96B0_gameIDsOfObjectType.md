# Function notes: 004D96B0 `gameIDsOfObjectType`

Module notes: `decomp_notes/taiinfmd_module.md`.

## Recovered attempt history

<!-- recovered:896d92c062b3579ee97f -->
### `target-session` `build/target_sessions/004D96B0_gameIDsOfObjectType.json:1-56`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=24; shape=99.04761904761905: Revalidated existing clean typed reconstruction before revisit.
probe 2 liveness; result=MISMATCH; diff=24; shape=99.04761904761905: Removed final objectID temporary to test direct indexed output assignment against original final-store register order. [same emitted code as probe 1]
probe 3 variant; result=MISMATCH; diff=24; shape=99.04761904761905: Swapped same-player comparison operands to test VC5 evaluation and register order.
probe 4 liveness; result=MISMATCH; diff=24; shape=99.04761904761905: Named the -5 owner pointer only within its guard to test owner-load scheduling without persistent aliasing. [same emitted code as probe 2]
probe 5 abi; result=MISMATCH; diff=24; shape=99.04761904761905: Typed md aiPlayer as the proven TRIBE_Player derived class to test inherited virtual ABI and register allocation. [same emitted code as probe 4]
probe 8 abi; result=MISMATCH; diff=24; shape=99.04761904761905: Hypothesis 1: model proven polymorphic RGE_Static_Object and RGE_Master_Static_Object surfaces with id/master/owner offsets from all_types_ground_truth.h. [same emitted code as probe 7]
probe 10 layout; result=MISMATCH; diff=24; shape=99.04761904761905: Hypothesis 2: restore proven AIModule/InformationAIModule/MainDecisionAIModule inheritance and base sizes while preserving all target offsets. [same emitted code as probe 8]
probe 12 abi; result=MISMATCH; diff=25; shape=99.04761904761905: Hypothesis 3: use the reviewed RGE_Player relation ABI, unsigned char relation(long), while retaining vslot +0x18.
probe 14 liveness; result=MISMATCH; diff=24; shape=99.04761904761905: Hypothesis 4: name the live output ID array after growth, matching a plausible original pointer temporary for the final store. [same emitted code as probe 10]
probe 16 liveness; result=MISMATCH; diff=24; shape=99.04761904761905: Hypothesis 5: name the live output owner array for the final owner-ID store, matching plausible pointer temporaries. [same emitted code as probe 14]
probe 18 liveness; result=MISMATCH; diff=24; shape=99.04761904761905: Hypothesis 6: materialize the owner's proven short ID before the -5 comparison to test the observed 16-bit load schedule. [same emitted code as probe 16]
probe 20 liveness; result=MISMATCH; diff=24; shape=99.04761904761905: Hypothesis 7: materialize the AI player's proven short ID before the -5 comparison to test receiver-value lifetime. [same emitted code as probe 18]
probe 22 liveness; result=MISMATCH; diff=24; shape=99.04761904761905: Hypothesis 8: name the relation owner pointer only inside the -6 virtual-call guard to test argument/receiver load order. [same emitted code as probe 20]
probe 24 control-flow; result=MISMATCH; diff=24; shape=99.04761904761905: Hypothesis 9: express the -5 sentinel and same-owner test as one short-circuit predicate, a natural source form for the shared reject edge. [same emitted code as probe 22]
probe 26 control-flow; result=MISMATCH; diff=24; shape=99.04761904761905: Hypothesis 10: express the -6 sentinel and relation result as one short-circuit predicate for the shared reject edge. [same emitted code as probe 24]
probe 28 liveness; result=MISMATCH; diff=24; shape=99.04761904761905: Hypothesis 11: name the AI player receiver only for the -6 virtual call to test receiver liveness and vtable-load order. [same emitted code as probe 26]
probe 30 liveness; result=MISMATCH; diff=621; shape=88.78504672897196: Hypothesis 12: name the relation call result before the -6 reject test to test predicate-result liveness.
probe 32 abi; result=MISMATCH; diff=25; shape=99.04761904761905: Hypothesis 13: use an unsigned-char local for the relation result, matching the reviewed relation return width before the reject test. [same emitted code as probe 12]
probe 34 abi; result=MISMATCH; diff=24; shape=99.04761904761905: Hypothesis 14: explicitly widen the signed short owner ID to long at the reviewed relation(long) call boundary. [same emitted code as probe 28]
probe 36 control-flow; result=MISMATCH; diff=24; shape=99.04761904761905: Hypothesis 15: spell the -6 nonzero reject as negated equality to test VC5 predicate polarity without changing behavior. [same emitted code as probe 34]
probe 38 variant; result=MISMATCH; diff=24; shape=99.04761904761905: variant lab build\variant_lab\004D96B0_gameIDsOfObjectType\20260817_130719: 128 variants, 128 invariant-eligible, 0 exact
probe 39 variant; result=MISMATCH; diff=24; shape=99.04761904761905: variant lab build\variant_lab\004D96B0_gameIDsOfObjectType\20260817_130824: 8 variants, 8 invariant-eligible, 0 exact
probe 40 abi; result=MISMATCH; diff=24; shape=99.04761904761905: Hypothesis 16: model the proven polymorphic RGE_Game_World class size and vptr while retaining its direct object(int) call. [same emitted code as probe 36]
probe 42 layout; result=MISMATCH; diff=24; shape=99.04761904761905: Hypothesis 17: replace the player gap with the proven RGE_Player fields through world +0x3C and id +0x4A. [same emitted code as probe 40]
probe 44 layout; result=MISMATCH; diff=24; shape=99.04761904761905: Hypothesis 18/20: name the proven map, memory-count, and ObjectMemory fields between md and importantObjects instead of an opaque gap. [same emitted code as probe 42]
probe 48 liveness; result=MISMATCH; diff=24; shape=99.04761904761905: Hypothesis 1: make relation owner pointer and owner ID explicit statements inside the -6 branch to test whether VC5 preserves original owner-before-receiver load order. [same emitted code as probe 47]
probe 50 liveness; result=MISMATCH; diff=24; shape=99.04761904761905: Hypothesis 2: remove the objectID temporary and store the direct importantObjects indexed expression, testing whether the final ID-store register basin matches the executable. [same emitted code as probe 48]
probe 52 liveness; result=MISMATCH; diff=24; shape=99.04761904761905: Hypothesis 3: copy count into a short-lived outputIndex before the final ID assignment, testing whether the original count-load-before-array-read schedule is source-driven. [same emitted code as probe 50]
probe 54 control-flow; result=MISMATCH; diff=24; shape=99.04761904761905: Hypothesis 4: use an explicit comma sequencing of the owner-ID read before the relation call, testing the binary-proven owner-before-receiver fault order without changing call count. [same emitted code as probe 52]
probe 56 abi; result=MISMATCH; diff=26; shape=98.57142857142857: Hypothesis 5: declare the reviewed vslot relation argument as short rather than int, testing whether the proven narrow owner ID type controls VC5 register colors while preserving the same stack ABI.
probe 58 liveness; result=MISMATCH; diff=202; shape=96.22641509433963: Hypothesis 6: bind the current output ID buffer to a local pointer before the final store, testing whether direct *ids liveness selects the executable's final pointer and count schedule.
probe 60 control-flow; result=MISMATCH; diff=24; shape=99.04761904761905: Hypothesis 7: recover the decompiler-supported single conjunction with positive filter guards instead of separate goto rejects, testing whether the original predicate tree selects the localized register and evaluation order. [same emitted code as probe 54]
probe 62 liveness; result=MISMATCH; diff=24; shape=99.04761904761905: Hypothesis 8: bind the owner ID as a local reference before the relation call, testing whether address-taken field ownership forces the executable's owner-before-receiver order without a new memory operation. [same emitted code as probe 60]
probe 64 context; result=MISMATCH; diff=24; shape=99.04761904761905: Hypothesis 9: align source line directives with the original PDB filter bands (1513, 1518, 1522, 1527) to test whether VC5 debug-line grouping controls the residual schedule. [same emitted code as probe 62]
probe 66 variant; result=MISMATCH; diff=24; shape=99.04761904761905: variant lab build\variant_lab\004D96B0_gameIDsOfObjectType\20260822_142641: 16 variants, 16 invariant-eligible, 0 exact
probe 67 abi; result=MISMATCH; diff=24; shape=99.04761904761905: Hypothesis 10: make the relation argument's signed int promotion explicit, testing whether VC5's expression type rather than the field width controls the receiver and owner register colors. [same emitted code as probe 64]
probe 71 behavior; result=MISMATCH; diff=14; shape=99.52380952380952: Hypothesis 1: materialize the -6 relation argument from obj->owner->id before evaluating the aiPlayer receiver, to restore the original owner-before-aiPlayer fault order using a natural short local.
probe 72 liveness; result=MISMATCH; diff=14; shape=99.52380952380952: Hypothesis 2: keep both the owner ID and the aiPlayer receiver as branch-local typed locals in source order, testing whether VC5 preserves the executable's owner-before-aiPlayer load order without a fake barrier. [same emitted code as probe 71]
probe 73 behavior; result=MISMATCH; diff=14; shape=99.52380952380952: Hypothesis 3: bind obj->owner to a typed branch-local pointer before the -6 relation call, testing whether a real owner object lifetime restores the original owner-before-aiPlayer fault order without changing call count or predicate behavior. [same emitted code as probe 72]
probe 74 control-flow; result=MISMATCH; diff=14; shape=99.52380952380952: Hypothesis 4: use the natural short-circuit -6 predicate as one conjunction, testing whether VC5 chooses the executable's receiver/argument load basin while retaining the same exclusion edge. [same emitted code as probe 73]
probe 75 liveness; result=MISMATCH; diff=14; shape=99.52380952380952: Hypothesis 5: materialize the AI player ID as a branch-local short before the -5 owner comparison, testing whether the original AX value and owner-pointer register coloring recover naturally. [same emitted code as probe 74]
probe 76 liveness; result=MISMATCH; diff=14; shape=99.52380952380952: Hypothesis 6: retain both a typed owner pointer and a short owner ID through the -6 call, testing whether explicit argument materialization changes VC5 register allocation and fault order without adding calls. [same emitted code as probe 75]
probe 77 behavior; result=MISMATCH; diff=14; shape=99.52380952380952: Hypothesis 7: use a real comma-expression sequencing point to read obj->owner before the -6 receiver, while retaining the second owner-ID reread for the relation argument and no extra call. [same emitted code as probe 76]
probe 78 liveness; result=MISMATCH; diff=14; shape=99.52380952380952: Hypothesis 8: use a natural reference alias for the proven owner field in the -6 predicate, testing whether address-taken owner lifetime forces the original load/register topology. [same emitted code as probe 77]
probe 79 context; result=MISMATCH; diff=14; shape=99.52380952380952: Hypothesis 9: restore the period information-AI standard-header context used by the behavior-correct 004D9240 reconstruction, testing whether ambient VC5 declarations select the original register basin without changing the target CFG. [same emitted code as probe 78]
probe 80 control-flow; result=MISMATCH; diff=14; shape=99.52380952380952: Hypothesis 10: restore the decompiler-supported combined positive filter conjunction as a natural source form, testing whether VC5 preserves the target's shared reject CFG and special-filter register basin after final-store recovery. [same emitted code as probe 79]
probe 81 abi; result=MISMATCH; diff=14; shape=99.52380952380952: Hypothesis 11: use the exact same-TU RGE_Player virtual surface pattern as 004E1930 (six declaration-only virtual slots, no local destructor) while preserving relation at vslot +0x18 and all target fields. [same emitted code as probe 80]
probe 82 abi; result=MISMATCH; diff=14; shape=99.52380952380952: Hypothesis 12: use canonical direct id/master/owner member declarations from exact taiinfmd donors instead of unions, preserving all proven offsets and the relation vslot. [same emitted code as probe 81]
probe 83 abi; result=MISMATCH; diff=14; shape=99.52380952380952: Hypothesis 13: use the period long relation(long) declaration at the proven vslot, testing canonical ID width while preserving the observed sign extension, call target, and cleanup. [same emitted code as probe 82]
probe 84 control-flow; result=MISMATCH; diff=14; shape=99.52380952380952: Hypothesis 14: express each special exclusion as one short-circuit guard instead of nested ifs, testing a natural predicate CFG that may recover the original register basin while keeping both reject edges. [same emitted code as probe 83]
probe 86 baseline; result=MISMATCH; diff=14; shape=99.52380952380952: Fresh baseline: current clean natural reconstruction under reviewed information-AI context; confirms 691-byte boundary, 10 direct/virtual calls, and current 14-byte filter register drift. [same emitted code as probe 85]
probe 87 liveness; result=MISMATCH; diff=14; shape=99.52380952380952: Hypothesis 1: bind this->md and obj->owner->id as branch-local natural locals in the -5 filter, testing whether explicit md, owner, then aiPlayer lifetimes recover the executable register/read order without changing calls or behavior. [same emitted code as probe 86]
probe 88 liveness; result=MISMATCH; diff=52; shape=98.0952380952381: Hypothesis 2: bind this->md and obj->owner->id as natural locals in the -6 relation filter, testing explicit md, owner, then aiPlayer read order while preserving the virtual call and fault order.
probe 89 control-flow; result=MISMATCH; diff=14; shape=99.52380952380952: Hypothesis 3: collapse only the -5 nested exclusion into one natural short-circuit guard, isolating its source CFG effect while retaining the -6 nested relation guard and all output behavior. [same emitted code as probe 87]
probe 90 control-flow; result=MISMATCH; diff=14; shape=99.52380952380952: Hypothesis 4: recover the special-filter source as a natural for loop with continue, replacing the explicit next label while preserving one update and all reject paths. [same emitted code as probe 89]
probe 91 liveness; result=MISMATCH; diff=645; shape=25.714285714285715: Hypothesis 5: keep one natural aiPlayer pointer through world lookup and both special filters, testing whether the original player reread pattern is instead a reused local while preserving the known vslot and calls.
```
<!-- end-recovered:896d92c062b3579ee97f -->

<!-- recovered:ca82493c47f88520d736 -->
### `fc4b000c6e8f` `src/scratch/004D96B0_gameIDsOfObjectType.cpp:1-80`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004D96B0 TribeInformationAIModule::gameIDsOfObjectType
// Attempt log:
// try 1: direct behavioral reconstruction from decompiler/asm: scan importantObjects, filter by player/master, grow output arrays and important object vector as needed.
// try 2: helper-based ensureImportant compiled too small (624B vs 691B); inlined both growth sites like original.
// try 3: inlined importantObjects growth at top of each iteration, matching original operator new/delete copy loop family.
// try 4: inlined second importantObjects growth before writing accepted result.
// try 5: modeled output ids/owners allocation as two arrays sized maxCount*8, then doubled maxCount.
// try 6: modeled copy of old output arrays before freeing/replacing pointers.
// try 7: modeled special playerFilter -5 same-player exclusion.
// try 8: modeled special playerFilter -6 relation check via virtual call on current AI player.
// try 9: modeled ordinary player and object type filters using owner id and master id offsets.
// try 10: /GX probe no change; removed.
// try 11: /Od probe exact-size but wrong debug-basin codegen; removed.
// try 12: restored the same-TU RGE_Player virtual surface through vslot +0x14;
// relation is the +0x18 slot used by the original call.  The prior three-slot
// stub emitted an unrelated +0x0C virtual call and was not a valid ABI model.
// try 13: replaced the three-field array stub with the same-TU ManagedArray<int>
// surface.  This fixed maximumSizeValue at +0x124 and restored both inline
// growth blocks.  Direct md->aiPlayer->world ownership also removed an extra
// pointer hop.  The rebuilt body reached 319 differing bytes, then 24 bytes
// after removing the redundant positive-capacity copy guard.
// try 14: moved the loop-index initialization before the outer guard; exact
// size and all CFG/call counts now match.
// try 15: operand order, scoped aliases, combined relation predicate, and a
// final objectID local were neutral or worse.  The direct typed source is kept.
// try 16: a focused natural final-store lab kept the direct member spelling as
// the only size/frame/call-set eligible variant; pointer/reference/value-member
// forms changed the frame or broadened the mismatch.
// try 17: same-TU virtual class surfaces for the object, master, player, and
// main-decision types preserved offsets but emitted the same 24-byte drift.
// try 18: equivalent ids[0] indexing and post-increment output storage were
// neutral; restored the clean explicit count update.
// try 19: a typed ownerID local before the relation call was neutral; restored
// the direct owner-id argument and kept the clean source.
// revisit probes: direct final indexed assignment (without objectID), swapped
// -5 comparison operands, a scoped -5 owner alias, and a TRIBE_Player-derived
// aiPlayer type all stayed in the same 691-byte/24-byte-drift basin.  These
// variants did not improve the localized register/address mismatch.  Restored
// the pinned direct typed source; no policy-invalid form was retained.
// revisit-2: completed 20 additional evidence-led hypotheses.  Canonical
// object/master/world surfaces, AIModule inheritance, full player fields,
// named information fields, relation ABI/casts, sentinel predicate forms,
// scoped receiver/owner/ID/result locals, and output-array aliases either
// duplicated the basin or worsened size/CFG.  A 128-variant lab combining
// ambient TU declarations with four natural local/store axes produced one
// 691-byte group.  An eight-variant standard-header context lab also produced
// one 691-byte group.  No exact candidate or new source lead resulted.
// fresh pass: explicit relation owner locals, direct and aliased final stores,
// predicate conjunctions, PDB line directives, narrow relation ABI forms, and
// signed argument casts all duplicated the 691-byte/24-byte basin.  A sixteen-
// variant register-declaration lab also produced one unchanged code group.
// left in scratch: 24 localized register/address bytes remain in the -5/-6
// player filters and final ID store.  Size, frame, calls, CFG, and 89.52% of
// blocks are exact; the remaining drift is not accepted_drift-safe.
// Accepted-drift audit: the -6 filter reads aiPlayer before obj->owner in the
// rebuild, while the executable reads obj->owner first. The final store also
// dereferences *ids before it reads importantObjects[i], reversing the original
// order. These changes affect pointer faults and concurrent table replacement.
// Canonical taiinfmd group pass: paired post-increment output stores recovered
// the complete final-store block. Strict drift fell from 24 to 14 bytes, and
// exact-block coverage rose from 89.52% to 95.71%. The output pointer and
// importantObjects element now use the executable's fault order.
// Branch-local owner, player, owner-ID, register, partial-md, pointer-slot, and
// reference forms did not improve the two special player filters. Pointer-slot
// forms also added three bytes. The remaining -6 block still loads aiPlayer
// before obj->owner. This fault-order difference blocks accepted drift.
// Exact-finish continuation: retesting partial-md and shared-owner lifetimes
// after the final-store recovery produced broad 52-byte and 463-byte drift.
// An explicit short argument cast and the local player vslot-0 spelling were
// codegen-neutral. No natural form forced the required owner-before-aiPlayer
// read without adding code or changing other exact blocks. The 14-byte result
// remains the safe source.
// Exact-finish continuation: fresh checks of owner locals, receiver locals,
// comma sequencing, combined guards, period headers, donor virtual surfaces,
// direct member declarations, and long relation ABI all duplicated 691/14.
// The clean nested predicates and shared information-AI context are restored.

// The information arrays use the inline ManagedArray<int> surface from the
// same translation unit.  Its desired-size member is real, even though this
// function does not read it; maximumSizeValue is therefore at +0x0C.
```
<!-- end-recovered:ca82493c47f88520d736 -->
