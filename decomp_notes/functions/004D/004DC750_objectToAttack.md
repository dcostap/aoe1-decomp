# Function notes: 004DC750 `objectToAttack`

Module notes: `decomp_notes/taiinfmd_module.md`.

## Recovered attempt history

<!-- recovered:aa21e2855996e3a43275 -->
### `target-session` `build/target_sessions/004DC750_objectToAttack.json:1-30`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=1423; shape=78.41726618705036: Existing clean reconstruction baseline before new hypotheses; source log reports prior best size 1977 and register-basin mismatch.
probe 2 liveness; result=MISMATCH; diff=1423; shape=78.41726618705036: Hypothesis 1: declare loop byte offset i before dCRating, because original keeps offset in EBP and dCRating home at +54 while current offset is EBX and dCRating home differs. [same emitted code as probe 1]
probe 3 liveness; result=MISMATCH; diff=1423; shape=78.41726618705036: Hypothesis 2: move the loop offset declaration to function scope before unit acquisition, testing whether earlier declaration scope gives the original EBP offset and EBX unit register colors. [same emitted code as probe 2]
probe 4 layout; result=MISMATCH; diff=1433; shape=81.32854578096948: Hypothesis 3: introduce a typed per-iteration ObjectMemory* record for owner/id access, testing whether canonical record ownership recovers the original offset-register basin.
probe 5 liveness; result=MISMATCH; diff=1423; shape=78.41726618705036: Hypothesis 4: promote candidate to function scope, supported by original storing candidate at [esp+44] and reloading it after several guards; the current branch-local pointer lives at a different home. [same emitted code as probe 3]
probe 6 liveness; result=MISMATCH; diff=1700; shape=79.3536804308797: Hypothesis 5: reorder function-scope locals to the Ghidra-decompiled declaration sequence, including offset before unit and candidate before loop temporaries; original stack allocation and register colors imply this declaration history. Unused placeholders mirror unmapped decompiler declarations but are diagnostic only.
probe 7 liveness; result=MISMATCH; diff=1423; shape=78.41726618705036: Hypothesis 6: move numberNonSiegeTargets declaration to function entry while keeping its pre-limit initialization, because original decompiler declaration order places this local late and its home is +64 rather than the rebuilt +54. [same emitted code as probe 5]
probe 8 behavior; result=MISMATCH; diff=1742; shape=76.57657657657657: Hypothesis 7: model rangeRating as bool, supported by the decompiler's bVar4=false/true source type and binary's 0/1 semantics, to test width-driven register allocation.
probe 9 context; result=MISMATCH; diff=1423; shape=83.63309352517986: Hypothesis 9: bind proven DAT_00575580 (0.0f) and DAT_00575584 (100.0f) globals for floating comparisons/scales, because original uses relocations at those VAs while literal source emitted compiler temporary symbols.
probe 10 context; result=MISMATCH; diff=1423; shape=77.15827338129496: Hypothesis 10: bind proven DAT_0057556c (-1.0f) for the final float comparisons, because original uses absolute rdata references at 004DCE71/82 while literal source emitted temporary constants.
probe 11 liveness; result=MISMATCH; diff=1423; shape=83.63309352517986: Hypothesis 11: promote unit to function scope before wonderToAttack, matching the decompiler's top-level unit declaration and testing whether it changes unit versus loop-offset callee-saved coloring. [same emitted code as probe 9]
probe 12 liveness; result=MISMATCH; diff=1423; shape=83.63309352517986: Hypothesis 12: promote best result pointer to function scope, matching original top-level timeToBeKilled/best-object lifetime and testing whether it holds a callee-saved register across the scan. [same emitted code as probe 11]
probe 13 liveness; result=MISMATCH; diff=1423; shape=83.63309352517986: Hypothesis 13: promote specialRating3 declaration to function scope before the scan, matching the decompiler's top-level declaration and testing its long-lived best-score home. [same emitted code as probe 12]
probe 14 liveness; result=MISMATCH; diff=1423; shape=83.63309352517986: Hypothesis 14: promote unitZone declaration to function scope, matching original decompiler order and testing the observed byte-home mismatch at entry-relative +1B versus rebuilt +17. [same emitted code as probe 13]
probe 15 liveness; result=MISMATCH; diff=1423; shape=83.63309352517986: Hypothesis 15: promote rangeRating declaration to function scope, following original decompiler local order and testing its stack home and zero-register lifetime. [same emitted code as probe 14]
probe 16 liveness; result=MISMATCH; diff=1423; shape=82.73381294964028: Hypothesis 16: carry a named zero local through the early integer flag stores, testing whether original EBP is a dedicated zero value that seeds unit/offset coloring.
probe 17 context; result=MISMATCH; diff=1423; shape=83.63309352517986: Hypothesis 17: replace remaining range/rate zero float literals with the proven DAT_00575580 symbol, matching original fcomp relocations at 004DCB49 and 004DCB7C.
probe 18 context; result=MISMATCH; diff=1423; shape=83.63309352517986: Hypothesis 18: mark the proven read-only DAT_00575580/84 globals const, matching their original .rdata ownership and testing whether VC5 chooses the same constant relocation basin.
probe 19 layout; result=MISMATCH; diff=1656; shape=79.20433996383363: Hypothesis 19: use one typed currentRecord pointer for the candidate record across distance, ratings, type tests, attackAttempts, and best assignment; original decomp shows a reloaded important-memory cursor and later record-pointer reuse.
probe 20 context; result=MISMATCH; diff=1716; shape=77.21518987341773: Hypothesis 20: add period <stdlib.h> TU context, testing a supported old-MSVC header-basin cause after source/ABI axes plateaued.
probe 24 control-flow; result=MISMATCH; diff=1686; shape=82.76481149012567: Hypothesis 1: place the loop offset initialization inside an explicit positive maxImportantObjectMemory guard, while retaining a for-loop for continue semantics. Original stores offset zero only after the positive-count test at 004DC845; clean source initialized it before that test.
probe 26 liveness; result=MISMATCH; diff=1423; shape=83.63309352517986: Hypothesis 2: mark the long-lived attacked-unit pointer as a register local, testing whether a period-plausible register declaration selects the original EBX unit / EBP cursor coloring. The executable carries unit across many calls and keeps it in EBX. [same emitted code as probe 23]
probe 28 liveness; result=MISMATCH; diff=1423; shape=83.63309352517986: Hypothesis 3: reorder the long-lived declarations toward the original Ghidra/PDB variable sequence (unitZone, unit, best, specialRating3, candidate, rangeRating), without changing scopes or behavior. The original register basin keeps unit in EBX and cursor/zero in EBP; prior clean source declares candidate first. [same emitted code as probe 26]
probe 30 control-flow; result=MISMATCH; diff=1416; shape=83.99280575539568: Hypothesis 4: use a positive-count do/while with one explicit loop_continue label for all skip paths. The original has offset zero initialized after the max-count guard and every skip branch joins 004DCECB before dCRating++/offset+=0x24; this tests that binary-backed shared-tail shape without a duplicate top test.
probe 32 liveness; result=MISMATCH; diff=1815; shape=81.93202146690518: Hypothesis 5: name the early unitAI result, matching the decompiler's pUVar8 lifetime and making the null-check result explicit. This tests whether a real call-result local changes the unit/cursor register interference without adding behavior.
probe 34 liveness; result=MISMATCH; diff=1416; shape=83.99280575539568: Hypothesis 6: keep the loop offset variable at function scope, as the decompiler lists iStack_84 among top-level locals, but assign it only after the positive max-count guard inside a labeled do/while. This combines original offset-init placement with the observed top-level local lifetime. [same emitted code as probe 30]
probe 36 liveness; result=MISMATCH; diff=1423; shape=83.63309352517986: Hypothesis 7: keep the attacked unit as the first long-lived object local and make candidate a per-owner-block declaration at its assignment. The Ghidra output lists unit before tempObj; this tests candidate lifetime and stack-home reuse against the original candidate home at [esp+44]. [same emitted code as probe 28]
probe 38 liveness; result=MISMATCH; diff=1423; shape=83.63309352517986: Hypothesis 8: mark the loop byte-offset local as register, testing the source-level declaration closest to the original EBP-carried cursor. The original uses EBP for offset through all loop address expressions and the bottom add. [same emitted code as probe 36]
probe 40 abi; result=MISMATCH; diff=1423; shape=83.63309352517986: Hypothesis 9: use the reviewed same-TU reference ABI for findObjectMemoryLimits, matching exact donor 004DFD60. Reference and pointer calls have the same machine ABI, but VC5 alias and local-home treatment can affect the unit/cursor register basin.
probe 42 layout; result=MISMATCH; diff=1423; shape=83.99280575539568: Hypothesis 10: model the reviewed TribeInformationAIModule polymorphic base surface with a virtual destructor and a 0xFC pre-md gap, preserving proven md offset +0x100. Exact same-TU donors use this class layout; the real surface could alter compiler type/liveness treatment.
```
<!-- end-recovered:aa21e2855996e3a43275 -->

<!-- recovered:1d02acddfb19bcbcbcd0 -->
### `20f3c7d6f341` `src/scratch/004DC750_objectToAttack.cpp:1-70`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 004DC750 TribeInformationAIModule::objectToAttack (taiinfmd.cpp:3458-3765, 1977 bytes)
// Clean canonical reconstruction from packet asm + PDB line bands.
//
// Attempt log:
// - baseline: clean reconstruction. Every offset/condition verified against original asm:
//   * loop predicate reloads each CANDIDATE's master_obj->object_group/master_id (per-iteration
//     `mov eax,[esi+8]` in both guards), never the attacked unit's group.
//   * oLimits is the struct-return value of findObjectMemoryLimits(player, objnum, &randomRating,
//     &id); the hidden return slot lands at &oLimits (no post-call copy in original).
//   * timeToKill = 100 (integer 0x64 store, "1.4013e-43" in Ghidra is just float rendering of 100);
//     hpRating/distanceRating/bestAttackValue/unitIsPriest defaults are 100.
//   * final rating override is `rating = 1` when ((bestObject > boatWeapon && boatWeapon != -1.0f)
//     || bestObject == -1.0f) -- branch topology verified against original.
//   * slot 49 (0xC4) on unitAI() dispatch is mostDangerousEnemy per derived UnitAIModule vtable;
//     local declaration uses int arg (caller passes record->id); exact donor 00415A10 declares
//     float* outThreat -- local stub only, slot/arity identical.
// - probe 2: split into TWO distance blocks (candidate coords for the visibility check, unit coords
//   for the distance); guards as positive `if (a == 0 && ... && x > 0) continue;` (matches original
//   test/jg); numberNonSiegeTargets as store-0/conditional-1. Frame 0x88, 44/44 calls aligned.
// - probe 3: raw-offset record accesses (donor 004E4680 idiom) so the original's per-iteration
//   importantObjectMemory reload and inline base derivation are reproduced instead of a spilled
//   record pointer + hoisted member load.
//
// orch-w1 session probes (for-loop era, best 1423 diff / 78.42% shape / size 1977 exact):
// - KEY: converted the loop from do-while (body-bottom dCRating++; i += 0x24) to a for-loop with
//   increments in the header. In VC5 a do-while `continue` jumps to the condition and SKIPS
//   body-bottom increment statements (rebuilt infinite-looped on skip paths); the original's
//   continue paths all jump to the bottom increment+test block (004DCECB), which is for-loop
//   continue semantics. This fixed the loop rotation: size 1983->1977 exact, exact-blocks
//   29.48%->39.24%, shape 76.22%->78.42%, and removed the split test-block/extra jmp.
// - rangeRating rewritten as if/else with the zero store in both arms; VC5 hoists the 0 store
//   between the last cmp and the jne, matching original `cmp ax,0Bh; mov [esp+24h],ebp; jne`.
// - loop init forms (for-init i=0 vs separate int i=0, i declared before/after unitZone) and
//   loop-form variants were swept via variant_lab; all dedupe to the same emitted code.
// - REMAINING (next lead): the whole function's register roles are swapped vs original:
//   original keeps unit in EBX and the zero/loop-offset in EBP (xor ebp,ebp at 004DC763 is the
//   dedicated zero that later becomes the record byte-offset); rebuilt puts unit in EBP and the
//   offset/zero in EBX. Local slot layout also shifts (i at [esp+14h] orig vs [esp+18h] reb,
//   dCRating [esp+54h] vs [esp+4Ch], unitZone [esp+1Bh] vs [esp+17h]). This is a register-
//   allocation/liveness basin issue, not a structural or call-set one: calls 44/44 aligned,
//   frame 0x88/0x88, CFG signals matched, first strict mismatch at +0014 (xor ebp vs xor ebx).
//
// Current pass (20 meaningful probes):
// - Declaration scopes, bool width, loop forms, typed record aliases, zero locals, and
//   header context did not recover the original EBX/EBP roles. Behavior and 44 calls stay aligned.
// - The clean source binds proven rdata constants DAT_00575580 (0.0f) and DAT_00575584
//   (100.0f). This keeps 1977 bytes but improves shape 78.42% -> 83.63%, exact-block
//   coverage 39.24% -> 41.23%, and raw cost 817 -> 535.
// - Candidate, unit, result, and flag declarations are function-scope and codegen-duplicate
//   with the prior form. A typed current-record alias and <stdlib.h> context were rejected.
// - Final validation: 1977 bytes, frame 0x88, 44/44 calls, diff 1423 (71.9777%), shape
//   83.63%, exact-block coverage 41.23%. The remaining first mismatch is +0014.
//
// Follow-up pass sa-a5d67d64-r1:
// - Hypothesis 1 put offset initialization inside a positive max-count guard. It added 14
//   bytes and a duplicate loop test: diff 1686, size 1991. Restored.
// - Hypotheses 2, 3, 7, and 8 tested register declarations, declaration order, candidate
//   scope, and loop-index register status. They were codegen duplicates or regressed by 7
//   bytes. Restored.
// - Hypothesis 4 used the binary-backed shared increment tail with a labeled do/while. It
//   reached diff 1416 and shape 83.99%, but resynchronization and exact-block coverage were
//   worse than the clean for-loop. Hypothesis 6 kept the offset local at function scope and
//   produced the same code. The clean for-loop remains authoritative.
// - Hypothesis 5 named the early unitAI result. It added 14 bytes and was restored.
// - Hypothesis 9 used the reviewed reference ABI for findObjectMemoryLimits. It was a
//   codegen duplicate and was restored to the pointer spelling.
// - Hypothesis 10 added the reviewed polymorphic TribeInformationAIModule surface while
//   preserving md at +0x100. It did not improve positional diff and was restored.
// - Final follow-up source is restored to the pinned clean reconstruction: 1977 bytes,
//   frame 0x88, 44/44 calls, diff 1423, shape 83.63%, first mismatch +0014.
```
<!-- end-recovered:1d02acddfb19bcbcbcd0 -->
