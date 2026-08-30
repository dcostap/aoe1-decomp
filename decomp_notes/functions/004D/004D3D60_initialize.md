# Function notes: 004D3D60 `initialize`

Module notes: `decomp_notes/taibldmd_module.md`.

## Recovered attempt history

<!-- recovered:2444724e39b6fc5286e3 -->
### `target-session` `build/target_sessions/004D3D60_initialize.json:1-40`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=1076; shape=90.0375939849624: Baseline current natural reconstruction: establish exact metrics and call/block parity.
probe 2 control-flow; result=MISMATCH; diff=1079; shape=89.88764044943821: H1: Replace second resource scan do-while with natural nested while; original bottom reload and sentinel test imply top-level while topology.
probe 4 liveness; result=MISMATCH; diff=1076; shape=90.0375939849624: H2: Split counter declarations from assignments while preserving assignment order; tests declaration/initialization-site scheduling as a source cause for the first stack-slot mismatch. [same emitted code as probe 1]
probe 6 control-flow; result=MISMATCH; diff=1077; shape=89.70037453183521: H3: Remove the outer sentinel guard and use one top-tested while for the resource scan; tests whether the original compare/store/test topology comes from a single loop.
probe 8 liveness; result=MISMATCH; diff=1083; shape=88.34586466165413: H4: Reuse the dead transportCount local for strategic A0 and its gatherer multiplier; original stores A0 into the transport counter home and reloads that home in the percentage loop.
probe 10 liveness; result=MISMATCH; diff=1077; shape=90.22556390977444: H5: Swap transportCount and warshipCount declaration order; their baseline homes are crossed relative to the original (+24/+28 versus +28/+34), testing declaration-driven register/slot coloring.
probe 12 liveness; result=MISMATCH; diff=1075; shape=90.41353383458646: H6: Swap fishingBoatCount and dockCount declaration order; their baseline homes are crossed relative to the original (+34/+2C versus +2C/+24), testing declaration-driven slot assignment.
probe 13 liveness; result=MISMATCH; diff=1076; shape=90.6015037593985: H7: Combine the transport/warship and fishing/dock declaration swaps; tests whether both crossed home pairs can be corrected by one coherent declaration order.
probe 15 liveness; result=MISMATCH; diff=1075; shape=90.97744360902256: H8: Combine fishing/dock swap with totalPercentage/divisionSize swap; tests both observed crossed stack-home pairs without changing semantic assignment order.
probe 17 liveness; result=MISMATCH; diff=1075; shape=90.41353383458646: H9: Swap transportCount and dockCount declaration order; tests the exact remaining baseline pair whose desired homes are +28 and +24.
probe 19 liveness; result=MISMATCH; diff=1084; shape=88.7218045112782: H11: Keep a distinct requiredPop local for val9B+4 instead of reusing ironAgeIndex; Ghidra names the value separately and the loop bottom reloads it.
probe 21 control-flow; result=MISMATCH; diff=953; shape=89.8686679174484: H12: Use a do-while for the tool-age fill inside its positive remaining guard; tests whether VC5 preserves the original duplicate entry/backedge test.
probe 23 control-flow; result=MISMATCH; diff=1076; shape=90.0375939849624: H13: Express the tool-age fill as a for loop with the decrement in the increment clause; tests VC5 loop-rotation and duplicate-guard lowering against the original. [same emitted code as probe 4]
probe 25 control-flow; result=MISMATCH; diff=953; shape=89.8686679174484: H14: Keep the tool-age do-while basin but move remaining-- into the loop condition; tests exact VC5 decrement/test placement. [same emitted code as probe 21]
probe 26 variant; result=MISMATCH; diff=954; shape=90.43151969981238: H15: Combine the promising tool-age do-while basin with the best declaration-order permutation; tests whether loop topology and local coloring are compatible.
probe 27 variant; result=MISMATCH; diff=954; shape=90.43151969981238: H16: Combine the tool-age do-while with only the totalPercentage/divisionSize declaration swap; isolates that local-color axis from the fishing/dock swap.
probe 28 variant; result=MISMATCH; diff=956; shape=90.43151969981238: H17: Add the transport/warship declaration swap to the tool-age do-while and total/division order; tests the remaining high-pressure counter-color axis.
probe 30 variant; result=MISMATCH; diff=953; shape=89.8686679174484: H18: Reconfirm the natural tool-age do-while candidate after eliminating declaration-order side effects; preserve the best known basin for focused reduction. [same emitted code as probe 25]
probe 31 liveness; result=MISMATCH; diff=953; shape=89.8686679174484: H19: In the do-while tool-age basin, mark only step as register; original requires step/value/remaining colors unlike the natural do-loop lowering. [same emitted code as probe 30]
probe 32 liveness; result=MISMATCH; diff=953; shape=89.8686679174484: H20: Mark the tool-age value local register in the do-while basin; tests whether source register hints can recover the original ESI value color. [same emitted code as probe 31]
probe 33 liveness; result=MISMATCH; diff=953; shape=89.8686679174484: H21: Reverse local declaration order in the do-while tool fill and assign val after step selection; tests VC5 color assignment for original step EBX/value ESI/remaining EBP. [same emitted code as probe 32]
probe 34 liveness; result=MISMATCH; diff=953; shape=89.8686679174484: H22: Declare tool-age step before remaining and before its guard; tests whether original step register color comes from wider scope/liveness. [same emitted code as probe 33]
probe 35 context; result=MISMATCH; diff=953; shape=89.8686679174484: H23: Add the period-plausible stdlib header to the do-while candidate; tests translation-unit front-end context without changing source behavior.
probe 36 control-flow; result=MISMATCH; diff=1104; shape=91.16541353383458: H24: Express the do-while termination as --remaining != 0; original emits dec/jne, so this tests direct VC5 lowering of that backedge.
probe 40 control-flow; result=MISMATCH; diff=964; shape=89.70037453183521: H25: Move the resource-scan null test into a positive nested guard before the do-while; original stores divisionSize=0 before testing null and has only the sentinel bottom test.
probe 42 liveness; result=MISMATCH; diff=962; shape=90.2439024390244: H26: Reorder all scalar declarations to the proven Ghidra stack-home order (bronze/count/division/iron/total/dock/transport/fishing/tool/resource/warship); tests whether the complete local order, not pair swaps, controls VC5 slot coloring.
probe 44 liveness; result=MISMATCH; diff=968; shape=89.68105065666042: H27: Use the raw CodeView local-symbol order for the live scalar model (trireme/count, warshipUpgrade/division, transportUpgrade/total, warshipCount, transportCount, bronze, tool, fishing, dock, iron); tests source declaration order from PDB rather than decompiler stack listing.
probe 46 control-flow; result=MISMATCH; diff=964; shape=89.70037453183521: H28: Preserve the original initial null fault/exit order with a binary-supported goto after divisionSize=0; avoid the natural nested guard that moved the null test before the reset and the break form that added a bottom null test.
probe 49 control-flow; result=MISMATCH; diff=1104; shape=91.16541353383458: H29: Keep the original positive tool-age guard and body decrement, but use a natural != 0 do-while condition to test the observed DEC/JNZ backedge without changing fault order.
probe 51 liveness; result=MISMATCH; diff=953; shape=89.8686679174484: H30: Use a period-plausible register declaration for count because the original carries count in EBP through the first scan and transport/tool fills; test whether it recovers the source register color without fake volatility. [same emitted code as probe 48]
probe 53 liveness; result=MISMATCH; diff=954; shape=89.8686679174484: H31: Swap only the two -1 research locals count and warshipCount; the original holds count in EBP through the first scan and transport/tool fills, so this isolates that declaration-order axis from prior broad permutations.
probe 55 variant; result=MISMATCH; diff=953; shape=89.8686679174484: H32: Mirror the original for-loop declaration shape by declaring the build-list sentinel before item and testing sentinel/null in one natural loop condition; test pointer-local liveness while preserving initial null fault order.
probe 58 control-flow; result=MISMATCH; diff=1076; shape=90.0375939849624: H33: Restore the period nested while form for the tool-age fill to test whether VC5 preserves the original outer and inner remaining guards and dec/jne loop topology.
probe 60 control-flow; result=MISMATCH; diff=953; shape=89.8686679174484: H34: Use an explicit sentinel-failure label before the gatherer reset, then the natural do-while; this tests the original sentinel test, reset, null fault order, and bottom backedge without changing calls.
probe 61 control-flow; result=MISMATCH; diff=958; shape=87.05440900562851: H35 direct check: adding Ghidra-supported explicit inner positive remaining guard and !=0 tool do-while produced 1776 bytes, 531 instructions, diff 1104; worse. Restored.
probe 62 liveness; result=MISMATCH; diff=958; shape=87.05440900562851: H36 direct check: interleaving count/item declarations to mirror Ghidra local order produced 1781 bytes and diff 962; prologue OR/xor order worsened. Restored.
probe 63 control-flow; result=MISMATCH; diff=958; shape=87.05440900562851: H38 direct check: Ghidra-supported explicit resource-fill do-while produced 1783 bytes and diff 951, slightly closer but wrong topology and broad allocation drift; restored.
probe 64 liveness; result=MISMATCH; diff=958; shape=87.05440900562851: H39 direct check: retaining strategic 0x9B in a direct threshold expression instead of reusing ironAgeIndex produced 1785 bytes and diff 969; restored.
probe 65 liveness; result=MISMATCH; diff=958; shape=87.05440900562851: H42 direct check: scoped gathererIndex alias produced diff 958 and broad register drift; restored.
probe 68 baseline; result=MISMATCH; diff=953; shape=89.8686679174484: Fresh standalone baseline; source owner, calls, and boundary checked before TU repair.
```
<!-- end-recovered:2444724e39b6fc5286e3 -->

<!-- recovered:383f48fcc484d974da6d -->
### `b9010b22e1ea` `src/scratch/004D3D60_initialize.cpp:1-116`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// TribeBuildAIModule::initialize
// VA: 004D3D60, taibldmd.cpp:100-434
// __thiscall void initialize(void)
//
// FLAGS: /GX (required: original has a full SEH fs:[0] frame with a destructible
//        ResourceItem local; default /O2 /Oy emitted no EH prologue -> 92% diff)
//
// Attempt log:
// - baseline: natural reconstruction (nested category/type scan, then transport /
//   tool / fishing / research / bronze / gatherer fill blocks with division steps
//   and ResourceItem subobject). Diff 1643 (92.3%), frame 0x9C matches.
// - control-flow: resource-cost block now calls buildCategory() twice (==1, ==4)
//   instead of caching a `bc` temp, restoring the 9th direct buildCategory call
//   and 100%% ordered-call parity (61/61, gap 0). Diff 1638.
// - flags: added /GX. Original prologue has push -1 / handler / fs:[0] EH state; a
//   destructible ResourceItem(4) local makes VC5 emit it. Big win: strict diff
//   1082 (60.8%), shape 84.6%, exact-block 41%, size 1770/1780.
// - variant: reordered the 11 counter declarations to the original's stack-slot
//   order -> worse (1091); reverted to baseline natural order (store order = orig).
// - orchestrator behavior audit: strategicNumber(0x9B) is called unconditionally
//   after strategicNumber(0xA0) in the executable, even when A0 is zero; moved
//   that call before the A0 guard to preserve its side effects and call topology.
// - layout audit: BuildItem must be 0xB0 bytes (buildListLength at +0x1A0), not
//   0x74; added gap_74. Fixes the fishing-block buildListLength displacement
//   (reb was +0x164). shape 85.5 -> 89.3%, blocks 41.9 -> 61.7%.
// - behavior audit: original stores ironAgeIndex = val9B + 4 unconditionally
//   (before the valA0 != 0 test); moved the store out of the if. Original also
//   resets bronzeAgeIndex = 0 in the valA0 block preheader (missing reset would
//   leak the bronze-fill count into insertGathererPercentage); added it.
// - bronze insert: if/else with duplicated insert() calls (bp>1 ? bp-1 : 1)
//   restores the original branch-pushed argument shape (lea/push vs materialized
//   selector).
// - valA0 loop: if+do-while form (matches Ghidra reconstruction) restores the
//   original instruction count (532/532) and puts the bronzeAgeIndex=0 store
//   near its original block; diff 1076, size -7, shape 90.0%%.
// - tool-age double guard: the original keeps BOTH the `if (remaining > 0)`
//   guard (191) and the loop guard (199). The natural nested while merges them
//   into one test. A natural outer-guard/inner-do-while form restores the
//   second-test basin: diff 953, size 1781/1780, shape 89.87%, calls 61/61.
//   The do-while source remains the best clean candidate, but it is not exact.
// - register allocation: original keeps `count` (0x66) in EBP through the first
//   loop + transport fill; rebuilt keeps `warshipCount` (0x65) there instead.
//   This flips the 11 counter frame-slot assignment (rebuilt slots: divisionSize
//   <-> totalPercentage +18/+20; four-slot rotation +24..+34) and the A0-loop
//   ironAgeIndex register home. Declaration order, branch nesting, and chained
//   initializers were all probed; VC5's slot allocation is not source-order
//   driven here.
// - direct natural lifetime probes: split the early research-presence flags from
//   the later resource threshold and scoped counter. Both variants grew to 534
//   instructions and diff 1088, while the clean source stays at 532/1076; rolled
//   back. The first paired hunk still shows the same local-slot permutation.
// - Ghidra marks the three research-presence locals as bool; changing the int
//   flags to bool moved the entry allocation and worsened diff to 1587. Restored.
// - H24 tested `do { ... } while (--remaining != 0)`: VC5 chose a different
//   register basin and worsened diff to 1104. Keep the H12 `remaining--` form.
// - Ghidra also names a separate requiredPop local for strategic 0x9B + 4;
//   separating it from the reused ironAge flag worsened diff to 1084. Restored.
// - PDB CodeView confirms the original scalar homes: bronze +0x10, count +0x14,
//   division +0x18, iron +0x1C, total +0x20, dock +0x24, transport +0x28,
//   fishing +0x2C, tool +0x30, warship +0x34, and resourceCount +0x38.
//   It also records aliases triremeUpgrade/count, warshipUpgrade/divisionSize,
//   transportUpgrade/totalPercentage, and houseCount/requiredPop.
// - H25/H28 tested a positive nested null guard and a matching cleanup goto for
//   the resource scan. Both reached 1780 bytes and an exact late loop block but
//   worsened strict diff to 964; the clean do-while source remains 953.
// - H26/H27 tested complete declaration orders from Ghidra and raw CodeView.
//   Both worsened the entry allocation (962/968); restored H12.
//
// - Exact-finish H29 changed only the tool-age do-while test to `!= 0`; VC5
//   moved to 1104 bytes, so it was restored. H30 `register count` was a
//   duplicate 953-byte basin. H31 swapped only count/warshipCount and reached
//   954 bytes. H32 declared the sentinel before item and used one natural
//   sentinel/null condition; it was a duplicate 953-byte basin. All were
//   restored.
// - H35 mirrored Ghidra's second tool-age guard and !=0 backedge: 1776 bytes,
//   diff 1104. H36 interleaved declarations: diff 962 and a worse prologue.
// - H38 used an explicit resource-fill do-while: diff 951 but wrong topology
//   and broad allocation drift. H39 kept the 0x9B value live: diff 969.
// - H42 used a scoped gatherer index: diff 958. H35-H42 were restored.

// LEFT IN SCRATCH: semantically faithful natural reconstruction with correct
// class surface (/GX EH frame, 0xB0 BuildItem), 61/61 ordered calls, and the
// best observed diff (953; 53.51%). Remaining drift includes broad register
// and frame-slot allocation differences, a one-instruction size overrun, and
// the resource-scan loop topology. Landing exact allocation is not
// evidence-backed in this pass. Strong verified-logic-tier candidate for
// orchestrator semantic review.

// Fresh wave1 context gate:
// - PROVED PDB module: taibldmd.cpp, source band lines 100-434.
// - PROVED owner and order: TribeBuildAIModule::initialize at 004D3D60,
//   between the exact 004D3B20 owner and 004D4460 owner.
// - PROVED anchors: buildCategory/typeID at 004D3DD4-004D3EFD, strategic
//   calls at 004D3F2F-004D42DB, ResourceItem construction at 004D42FD and
//   destruction at 004D4436, and final resource calls at 004D43B4-004D4436.
// - PROVED fields: this+0xF0, this+0x15C, this+0x1A0, and this+0x5BC.
// - LIKELY source context: the real taibldmd.cpp class surface and /GX EH
//   path. The grouped flag row omits /GX, so the wrapper cannot reproduce
//   the standalone EH-aware basin.
// - UNKNOWN: the remaining counter-home permutation and loop topology cause.
// Final validation: grouped no-GX output remains 1649 bytes nonexact; clean
// source is retained and no unsupported codegen steering was added.
// [non-comment lines omitted during migration]
    // BINARY NOTE: the first word is the real virtual destructor pointer.
    // Use the period C++ surface instead of a raw vtable field.
```
<!-- end-recovered:383f48fcc484d974da6d -->
