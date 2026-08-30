# Function notes: 004DDD40 `objectToAttackByGroup2`

Module notes: `decomp_notes/taiinfmd_module.md`.

## Recovered attempt history

<!-- recovered:5560f97bc042be4f0c30 -->
### `d050eea3c` `src/taiinfmd.cpp:3289-3289`

Mapping: `strong`. comment lies after mapped function objectToAttackByGroup2 at old line 3240.

```text
                                        // BINARY NOTE: slot +0xC4 receives ObjectMemory::id.
```
<!-- end-recovered:5560f97bc042be4f0c30 -->

<!-- recovered:2a6713b348a9584a6690 -->
### `d050eea3c` `src/taiinfmd.cpp:3352-3352`

Mapping: `ambiguous`. comment lies after mapped function objectToAttackByGroup2 at old line 3240.

```text
                                                // BINARY NOTE: VC5 evaluates these weights in this order.
```
<!-- end-recovered:2a6713b348a9584a6690 -->

<!-- recovered:eb39b968c9f8e494544a -->
### `target-session` `build/target_sessions/004DDD40_objectToAttackByGroup2.json:1-43`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=990; shape=70.57057057057057: Baseline current scratch reconstruction before new probes.
probe 2 abi; result=MISMATCH; diff=1002; shape=69.66966966966967: Hypothesis 2: vslot +0xC4 takes the candidate object ID, not an ObjectMemory pointer; original pushes [importantMemory+byteOffset].
probe 4 liveness; result=MISMATCH; diff=990; shape=70.57057057057057: Hypothesis 3: commanderObj is function-scope, as original stores it at a dedicated [esp+18] home immediately after md->object; move declaration above wonder/count guards. [same emitted code as probe 1]
probe 6 layout; result=MISMATCH; diff=834; shape=68.562874251497: Hypothesis 4: original keeps byteOffset as EBP and reloads importantObjectMemory+byteOffset for fields; remove the persistent ObjectMemory* memory alias.
probe 7 layout; result=MISMATCH; diff=920; shape=74.8502994011976: Hypothesis 5: original converts target world_x/world_y directly inside each arithmetic/visibility expression; remove named x/y temporaries to recover the observed x stack home and rereads.
probe 8 liveness; result=MISMATCH; diff=911; shape=74.8502994011976: Hypothesis 6: original initializes bestObject before the max-memory gate, then bestScore; reorder core result declarations to match the observed DDD BA/C0/C8 stores.
probe 9 liveness; result=MISMATCH; diff=911; shape=74.8502994011976: Hypothesis 7: original's byteOffset stays in EBP across the scan; test a period-supported register declaration on the byte cursor. [same emitted code as probe 8]
probe 10 liveness; result=MISMATCH; diff=911; shape=74.8502994011976: Hypothesis 8: the dword incremented at DE1C2 is the named loop counter; replace the unused timeTK float plus i pair with one int timeTK. [same emitted code as probe 9]
probe 11 liveness; result=MISMATCH; diff=911; shape=74.8502994011976: Hypothesis 9: bestObject has function scope and is initialized only after commander gates; test a wider result lifetime to recover the original return slot. [same emitted code as probe 10]
probe 12 control-flow; result=MISMATCH; diff=905; shape=75.67567567567568: Hypothesis 10: original's test ah,41h is the natural  predicate, not the reversed spelling ; test operand order.
probe 13 liveness; result=MISMATCH; diff=905; shape=75.67567567567568: Hypothesis 11: targetDistance is a declared local before the damage/time calls and then assigned after their zero guards, allowing VC5 to reuse the original damage home at [esp+20]. [same emitted code as probe 12]
probe 14 control-flow; result=MISMATCH; diff=903; shape=75.07507507507508: Hypothesis 12: source update order byteOffset then loop counter may reproduce the original scheduler's inc-counter/add-cursor order and register colors.
probe 15 liveness; result=MISMATCH; diff=903; shape=75.07507507507508: Hypothesis 13: byteOffset is declared with the loop locals after commander checks, not at function entry; test scope as a supported register/lifetime axis. [same emitted code as probe 14]
probe 16 abi; result=MISMATCH; diff=903; shape=75.37537537537537: Hypothesis 14: exact helper donors prove damageInflictedPerSecond and timeToBeKilled take (int* ids, int count, object), not (group, ids, object); correct both declarations and calls.
probe 17 abi; result=MISMATCH; diff=748; shape=75.97597597597597: Hypothesis 15: original vslot +0xC4 loads and pushes ObjectMemory::id from base+byteOffset, not the record pointer; test int objectId with the raw cursor source.
probe 18 liveness; result=MISMATCH; diff=1011; shape=77.74480712166172: Hypothesis 16: original hoists the candidate kills load before strategicNumber(0x53), as proved by DDF81-DDF8E; move killCount capture before the random branch.
probe 19 behavior; result=MISMATCH; diff=1005; shape=77.44807121661721: Hypothesis 17: Ghidra formula and x87 call order prove score = SN(0x50)*kills + SN(0x4d)/distance + SN(0xb8)*targetTime; swap the previously reversed 0x50/0xb8 weights.
probe 20 liveness; result=MISMATCH; diff=782; shape=75.67567567567568: Hypothesis 18: keep the proven score weight order but restore the natural killCount declaration after the random branch; isolate scheduling from the semantic weight correction.
probe 21 liveness; result=MISMATCH; diff=767; shape=74.33628318584071: Hypothesis 19: original evaluates strategic weights in three named assignments (0xb8, 0x4d, 0x50) before combining them; this preserves the oracle call order while keeping the decompiler-proven weight mapping.
probe 22 behavior; result=MISMATCH; diff=608; shape=76.27627627627628: Hypothesis 20: original source evaluates score terms as SN(0xb8)*targetTime, then SN(0x4d)/distance, then SN(0x50)*kills; direct expression order should preserve the original x87 schedule and call order.
probe 23 layout; result=MISMATCH; diff=913; shape=76.34730538922156: Hypothesis 21: original score uses fmul, not fimul, for kills; model the byte kills as a float local to recover the observed FPU conversion and [esp+48] multiplier.
probe 24 liveness; result=MISMATCH; diff=1007; shape=79.57957957957957: Hypothesis 22: the original converts kills before strategicNumber(0x53), matching DDF81/FILD/FSTP; move the float kills local before the random branch.
probe 26 control-flow; result=MISMATCH; diff=597; shape=76.87687687687688: Hypothesis 23: restore source update order counter then byte cursor because original emits INC index before ADD 0x24 cursor; test the binary-proven loop update order.
probe 27 liveness; result=MISMATCH; diff=597; shape=76.87687687687688: Hypothesis 24: the two coordinate-distance blocks reuse one dx/dy pair; original register reuse and no stack homes support shared locals across visibility and score distance. [same emitted code as probe 26]
probe 28 liveness; result=MISMATCH; diff=597; shape=76.87687687687688: Hypothesis 25: place byteOffset after result, score, and loop-counter declarations; old VC5 declaration ordering can select the EBP/EBX color basin. [same emitted code as probe 27]
probe 29 liveness; result=MISMATCH; diff=597; shape=76.87687687687688: Hypothesis 26: declare damage, hpOverDamage, time, targetTime, and targetDistance together before assignments; original helper FPU homes prove a shared VC5 lifetime basin. [same emitted code as probe 28]
probe 32 layout; result=MISMATCH; diff=597; shape=76.87687687687688: Policy rewrite: replace raw byte cursor with natural importantObjectMemory[timeTK] access and replace raw tactical offset with canonical md->tacticalAI ownership. Preserve helper ABI and object-id argument. [same emitted code as probe 31]
probe 33 liveness; result=MISMATCH; diff=992; shape=73.57357357357357: Natural typed hypothesis: bind ObjectMemory* memory = &importantObjectMemory[timeTK] once per iteration, then use typed fields. No raw cursor or raw tactical offset.
probe 37 liveness; result=MISMATCH; diff=597; shape=76.87687687687688: Hypothesis 1 this claim: split damage, hp-over-damage, time, target-time, and target-distance declarations at their natural guards so VC5 can reuse the original damage home for later target distance. [same emitted code as probe 36]
probe 39 liveness; result=MISMATCH; diff=597; shape=76.87687687687688: Hypothesis 2 this claim: declare the wonder result before bestObject, matching source evaluation order and testing whether VC5 moves the persistent return local into the oracle slot and keeps EBP as the early zero. [same emitted code as probe 37]
probe 41 control-flow; result=MISMATCH; diff=916; shape=77.77777777777777: Hypothesis 3 this claim: express the random branch as randomNumber > 0 with the zero fallback in else, matching the oracle test eax/jle random-body layout instead of the equivalent < 1 inverted form.
probe 43 abi; result=MISMATCH; diff=597; shape=76.87687687687688: Hypothesis 4 this claim: restore the polymorphic TribeInformationAIModule surface used by exact same-TU donors, with the reviewed vptr and md still at +0x100, to test whether class kind changes member codegen. [same emitted code as probe 39]
probe 44 liveness; result=MISMATCH; diff=597; shape=76.87687687687688: Hypothesis 5 this claim: remove the redundant bestAttackValue initializer because both random arms assign it and the oracle has no loop-entry store; test declaration-only liveness and stack-home allocation. [same emitted code as probe 43]
probe 46 behavior; result=MISMATCH; diff=1009; shape=80.18018018018019: Hypothesis 6 this claim: materialize the candidate kills as a float before strategicNumber(0x53), matching the oracle fild/fstp before the random branch and its final fmul score use.
probe 48 variant; result=MISMATCH; diff=1009; shape=80.18018018018019: variant lab build\variant_lab\004DDD40_objectToAttackByGroup2\20260822_152205: 4 variants, 4 invariant-eligible, 0 exact
probe 49 liveness; result=MISMATCH; diff=587; shape=77.47747747747748: Hypothesis 7 this claim: declare the inner scan cursor inside the positive remaining-count guard, matching the oracle zero/test before the ids load and its PDB line band.
probe 50 control-flow; result=MISMATCH; diff=579; shape=77.47747747747748: Hypothesis 8 this claim: test count directly and declare remaining inside the positive inner-scan arm, matching the oracle test-before remaining-home store and cursor setup.
probe 51 liveness; result=MISMATCH; diff=579; shape=77.47747747747748: Hypothesis 9 this claim: declare the inner cursor before remaining, matching the oracle pointer load followed by the remaining-home store and testing local-home allocation. [same emitted code as probe 50]
probe 52 behavior; result=MISMATCH; diff=597; shape=75.07507507507508: Hypothesis 10 this claim: combine the seven score terms into one left-to-right assignment, matching the oracle single PDB line 4403 and allowing VC5 to schedule literal pushes and receiver loads across calls.
probe 54 liveness; result=MISMATCH; diff=591; shape=76.57657657657657: Hypothesis 11 this claim: bind the first world-x conversion as objectX and reuse it for the distance and visible-map call, matching the oracle x result spill/reuse and testing the shifted return/priest homes.
probe 56 liveness; result=MISMATCH; diff=579; shape=77.47747747747748: Hypothesis 12 this claim: move targetDistance to function scope because oracle stack evidence assigns the reusable distance home before bestObject and reuses it for the scratch/clamp path. [same emitted code as probe 53]
probe 57 liveness; result=MISMATCH; diff=579; shape=77.47747747747748: Hypothesis 13 this claim: promote the damage, hp-over-damage, time, and target-time locals to function scope, matching the original Ghidra local inventory and testing cross-block stack-home allocation. [same emitted code as probe 56]
probe 59 liveness; result=MISMATCH; diff=579; shape=77.47747747747748: Hypothesis 14 this claim: promote commanderIsPriest to function scope, matching the original Ghidra local inventory and testing whether VC5 restores the bestObject/priest stack-home pair. [same emitted code as probe 57]
```
<!-- end-recovered:eb39b968c9f8e494544a -->

<!-- recovered:49f597f4e3c19bf88021 -->
### `fc4b000c6e8f` `src/scratch/004DDD40_objectToAttackByGroup2.cpp:1-39`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA 004DDD40 TribeInformationAIModule::objectToAttackByGroup2
// PDB source: taiinfmd.cpp:4253-4435
// Attempt log:
// 1: The prior scaffold had mismatched helper calls and broad code drift.
// 2: Rebuilt the typed ObjectMemory, object, visible-map, and unit-AI surfaces.
// 3: Exact donors prove both scoring helpers take (ids, count, object).
// 4: The +0xC4 unit-AI call takes the candidate ObjectMemory id, not its pointer.
// 5: The natural typed indexed array model is retained for important memories.
// 6: Direct coordinate conversions recover the repeated __ftol and visibility
//    sequence without volatile state or address macros.
// 7: The score comparison is `score > bestScore`; this emits the original
//    `test ah,41h` x87 predicate.
// 8: The score terms are evaluated as 0xb8*targetTime, 0x4d/distance, and
//    0x50*kills. The order follows the original strategic-number call sites.
// 9: Reused dx/dy across both coordinate blocks. The compiler output is
//    unchanged, which supports the ordinary shared-local model.
// 10: Best prior check was 1200 bytes, 332 instructions, and 597 differing
//     bytes. Calls aligned 31/31 and the frame was 0x40, but the result was not exact.
// 11: Restored canonical md->tacticalAI ownership and typed indexed memory
//     access. Emitted code stayed unchanged.
// 12: A typed per-iteration memory pointer was natural but lost 65 code bytes.
//     Restored the indexed form.
// 13: The original inner count scan tests count before loading ids or storing
//     remaining. Declaring both inside `if (count > 0)` recovers the test/store
//     block and improves the retained result to 579 differing bytes.
// 14: Tested the oracle random-branch polarity, early float kills conversion,
//     one score expression, and function-scope float locals. They were worse or
//     codegen duplicates and were restored.
// 15: Best current check is 1200 bytes, 332 instructions, and 579 differing
//     bytes. Calls align 31/31, frame is 0x40, and exact-block coverage is 28.53%.
// Remaining drift is mainly VC5 register and local-home allocation around the
// initial zero, coordinate scratch, and score locals.
// Main-agent audit: replaced the generated generated padding padding with the named
// UnitAIModule ABI surface through the binary-proven +0xC4 can_attack_mem
// override. No codegen-only volatility or inline assembly is retained.
// Structural probe: the original nonzero wonderToAttack branch returns its
// result; the zero return belongs only to the later null-commander paths.
// Continuation probe: moved hp-over-damage before timeToBeKilled to match the
// original FPU statement order; structure improved, bytes worsened.
```
<!-- end-recovered:49f597f4e3c19bf88021 -->
