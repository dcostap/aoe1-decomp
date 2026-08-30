# Function notes: 004D9240 `gameIDOfResourceObject`

Module notes: `decomp_notes/taiinfmd_module.md`.

## Recovered attempt history

<!-- recovered:2049f9d324ffce582aba -->
### `target-session` `build/target_sessions/004D9240_gameIDOfResourceObject.json:1-69`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=967; shape=86.78678678678679: Baseline clean reconstruction: right frame and call set, but effective size is 55 bytes short and first prologue mismatch starts at +9.
probe 2 abi; result=MISMATCH; diff=967; shape=86.78678678678679: Hypothesis 1: model TribeInformationAIModule as the proven polymorphic owner with a virtual destructor and 0xEC pre-field gap, preserving md at +0x100; test whether this restores original ESI ownership/prologue. [same emitted code as probe 1]
probe 3 layout; result=MISMATCH; diff=967; shape=87.68768768768768: Hypothesis 2: correct RGE_Master_Static_Object proven offsets by adding the missing +0x12 padding, placing object_group at +0x14 while retaining id at +0x10.
probe 4 behavior; result=MISMATCH; diff=967; shape=87.98798798798799: Hypothesis 3: use the binary-proven towncenter gather-attempt divisor 0x96 (150), not the prior /75; original magic constant and decompiler both prove /150.
probe 5 liveness; result=MISMATCH; diff=967; shape=87.98798798798799: Hypothesis 4: make the resource cursor function-scope, matching original stack evidence for the loop cursor that survives the shared increment tail; keep selected best pointer separate. [same emitted code as probe 4]
probe 6 liveness; result=MISMATCH; diff=1013; shape=80.8259587020649: Hypothesis 5: represent the resource-list cursor as an explicit byte offset, then derive a typed ResourceMemory pointer each iteration; test the original stack cursor plus base-add lowering.
probe 7 liveness; result=MISMATCH; diff=983; shape=83.43373493975903: Hypothesis 6: cache resources[resType] in a typed resourceBase local so the cursor expression lowers as a separate base load plus add, matching original +008D/+0091.
probe 8 abi; result=MISMATCH; diff=967; shape=87.98798798798799: Hypothesis 7: model the proven md +0x1146C tacticalAI as a typed TribeMainDecisionAIModule member, replacing raw pointer casts while preserving direct call identity. [same emitted code as probe 5]
probe 9 abi; result=MISMATCH; diff=967; shape=87.98798798798799: Hypothesis 8: replace explicit vptr data fields with true polymorphic period class surfaces for RGE_Static_Object, RGE_Master_Static_Object, and Player, preserving all proven offsets. [same emitted code as probe 8]
probe 10 liveness; result=MISMATCH; diff=967; shape=87.98798798798799: Hypothesis 9: split cursor declaration from initialization and assign mem=0 inside the positive resource-count guard, matching original late +008B stack cursor initialization band. [same emitted code as probe 9]
probe 11 liveness; result=MISMATCH; diff=967; shape=87.98798798798799: Hypothesis 10: adopt the decompiler-proven local roles: bestObject is the moving cursor, bestValue is the selected ResourceMemory pointer, and fishingBoat is the best score; the prior source left bestValue unused and reversed these lifetimes. [same emitted code as probe 10]
probe 12 abi; result=MISMATCH; diff=967; shape=87.68768768768768: Hypothesis 11: restore the proven InformationAIModule base inheritance so TribeInformationAIModule's +0xF0 fields arise from a real polymorphic base, not a flat gap.
probe 13 liveness; result=MISMATCH; diff=967; shape=87.68768768768768: Hypothesis 12: apply register storage to the long-lived gatherer result, testing whether VC5 restores the original object/gatherer EDI color and frees EBP for the score. [same emitted code as probe 12]
probe 14 liveness; result=MISMATCH; diff=967; shape=87.68768768768768: Hypothesis 13: apply register storage to each candidate obj result, testing whether VC5 selects original EDI for object and EBP for score. [same emitted code as probe 13]
probe 15 behavior; result=MISMATCH; diff=967; shape=87.98798798798799: Hypothesis 14: restore strict amount threshold, proven by original x87 test ah,41 (reject <= threshold) versus prior ah,01 (reject < threshold).
probe 16 liveness; result=MISMATCH; diff=967; shape=87.98798798798799: Hypothesis 15: hoist all loop temporaries to function scope, matching the old MSVC top-level local style suggested by the decompiler variable table and source-era TU. [same emitted code as probe 15]
probe 17 liveness; result=MISMATCH; diff=967; shape=88.28828828828829: Hypothesis 16: move every local declaration to function scope before the first statement, with gathererObj declared alongside the late decompiler locals; old VC5 declaration order can control saved-register colors.
probe 18 liveness; result=MISMATCH; diff=967; shape=88.28828828828829: Hypothesis 17: place the long-lived gatherer declaration last among function locals, following the decompiler's late gathererObj slot and testing declaration-order register coloring. [same emitted code as probe 17]
probe 19 context; result=MISMATCH; diff=967; shape=88.28828828828829: Hypothesis 19: restore a period-supported math.h front-end context before declarations, testing whether VC5's standard header state selects the original register/codegen basin. [same emitted code as probe 18]
probe 20 context; result=MISMATCH; diff=967; shape=88.28828828828829: Hypothesis 20: restore the standard C library header combination used by adjacent same-TU code, testing front-end context effects from math.h plus stdlib.h plus string.h. [same emitted code as probe 19]
probe 21 abi; result=MISMATCH; diff=967; shape=88.28828828828829: Hypothesis 21: complete the canonical polymorphic owner surfaces by adding virtual destructors to TribeInformationAIModule and MainDecisionAIModule, preserving md/player offsets. [same emitted code as probe 20]
probe 22 abi; result=MISMATCH; diff=967; shape=88.28828828828829: Hypothesis 22: restore the period ManagedArray template/operator[] surface for farmsTaskedThisUpdate, using its proven bounded index access rather than a raw value-field expression. [same emitted code as probe 21]
probe 23 liveness; result=MISMATCH; diff=967; shape=88.28828828828829: Hypothesis 23: use a natural local reference alias to the moving ResourceMemory cursor, making its addressable lifetime explicit and testing whether VC5 emits the original stack cursor home. [same emitted code as probe 22]
probe 24 control-flow; result=MISMATCH; diff=982; shape=89.1566265060241: Hypothesis 24: express the resource scan as the original-style for header with i and cursor initialization/update in one statement, rather than a do/while tail.
probe 25 context; result=MISMATCH; diff=967; shape=88.28828828828829: Hypothesis 25: restore the complete same-TU AIModuleID -> AIModule -> InformationAIModule base surface from exact constructor/destructor donors, rather than an opaque 0xEC gap. [same emitted code as probe 23]
probe 26 liveness; result=MISMATCH; diff=967; shape=88.28828828828829: Hypothesis 26: request register storage for score, testing whether VC5 assigns it to the original EBP long-lived arithmetic register instead of a stack home. [same emitted code as probe 25]
probe 27 liveness; result=MISMATCH; diff=967; shape=88.28828828828829: Hypothesis 27: bind this to an explicit self pointer and use self for all member accesses/calls, testing whether VC5 allocates self in original ESI and score in EBP. [same emitted code as probe 26]
probe 29 liveness; result=MISMATCH; diff=967; shape=87.98798798798799: Hypothesis 28: remove the redundant late cursor zero inside the positive-count guard; h25 clean-source comparison shows the original only materializes cursor zero before the guard. [same emitted code as probe 28]
probe 30 context; result=MISMATCH; diff=967; shape=88.28828828828829: Hypothesis 29: retain the same-TU standard header context that produced the best 88.29% shape basin; this restores math/stdlib/string declarations before exact local type surfaces. [same emitted code as probe 27]
probe 32 abi; result=MISMATCH; diff=932; shape=93.13432835820896: Hypothesis 1: model the moving ResourceMemory cursor as the proven byte offset, with direct typed base-plus-offset accesses like exact updateResourceDropsites, rather than retaining a pointer cursor; tests original stack cursor and 0x14 tail topology.
probe 33 liveness; result=MISMATCH; diff=895; shape=94.6268656716418: Hypothesis 2: initialize the proven byte cursor only inside the positive resource-count arm, and initialize fishingBoat before bestValue; this tests the original +008B cursor-zero block and pre-loop store ordering.
probe 34 liveness; result=MISMATCH; diff=911; shape=95.7957957957958: Hypothesis 3: name the current resource ID across exclusion and object lookup, preserving resType in EBX; this tests the original EDI candidate-ID load and EBP score color instead of the prior EBX clobber.
probe 35 control-flow; result=MISMATCH; diff=896; shape=93.45238095238095: Hypothesis 4: express the exclusion scan as an explicit zero-init plus positive-count do/while, matching the original pretest and bottom compare; tests whether this preserves EBX resType and selects EDI for the candidate ID.
probe 36 liveness; result=MISMATCH; diff=911; shape=95.7957957957958: Hypothesis 5: keep the named current resource ID before the cursor and scan locals, testing declaration-order effects on preserving resType and assigning the ID to EDI. [same emitted code as probe 34]
probe 37 liveness; result=MISMATCH; diff=895; shape=94.6268656716418: Hypothesis 6: represent the current record's proven id as an int-pointer alias, following the decompiler's piVar15 pointer role; tests whether an address-carrying alias preserves the original EDX cursor and EDI id without a type-wide record pointer. [same emitted code as probe 33]
probe 38 liveness; result=MISMATCH; diff=895; shape=94.6268656716418: Hypothesis 7: copy resType into a function-scope resourceType local and use that local for all indexed accesses and predicates; tests whether a persistent typed index keeps EBX live for the original score EBP topology. [same emitted code as probe 37]
probe 39 liveness; result=MISMATCH; diff=903; shape=93.76854599406528: Hypothesis 8: scan exclusions through a moving pointer local, matching the original ECX pointer home and EAX index while leaving count as the parameter; tests whether this preserves resType EBX and candidate ID EDI.
probe 40 liveness; result=MISMATCH; diff=895; shape=94.6268656716418: Hypothesis 9: declare the long-lived score near the pre-loop selection locals, before the cursor, testing declaration order as a register-coloring cause for original EBP score and EBX resType. [same emitted code as probe 38]
probe 41 abi; result=MISMATCH; diff=989; shape=81.41592920353982: Hypothesis 10: introduce a natural current ResourceMemory pointer per iteration while retaining the byte cursor, testing whether the original EDX candidate pointer and EBX resType/EBP score topology arise from one typed record alias.
probe 42 liveness; result=MISMATCH; diff=904; shape=96.11940298507463: Hypothesis 11: use a combined exclusion-loop pointer/index initializer with pointer increment, testing the original post-guard ECX exclude pointer without adding a separate guard block.
probe 43 abi; result=MISMATCH; diff=636; shape=96.11940298507463: Hypothesis 12: type the exclusion flag as bool, following the decompiler's boolean role while retaining the pointer/index scan; tests whether VC5 selects the original EBP dword flag and EDI candidate ID.
probe 44 liveness; result=MISMATCH; diff=636; shape=96.11940298507463: Hypothesis 13: move score before cursor and exclusion locals within the bool/pointer source basin, testing declaration order for swapping the persistent resourceType EBP and score EBX colors. [same emitted code as probe 43]
probe 45 abi; result=MISMATCH; diff=925; shape=84.73053892215569: Hypothesis 14: retain the direct indexed exclusion loop but type only its flag as bool; tests whether the flag width alone recovers the original dword exclusion and score register basin.
probe 46 liveness; result=MISMATCH; diff=636; shape=96.11940298507463: Hypothesis 15: add a named resourceType copy within the bool/pointer basin and use it for all index operations; tests whether explicit long-lived index ownership swaps EBP resourceType to EBX and frees EBP for score. [same emitted code as probe 44]
probe 47 liveness; result=MISMATCH; diff=636; shape=96.11940298507463: Hypothesis 16: reverse the combined exclusion initializer to pointer-first, testing source evaluation order for the original ECX pointer and EAX index setup. [same emitted code as probe 46]
probe 48 liveness; result=MISMATCH; diff=636; shape=96.11940298507463: Hypothesis 17: separate excludePtr assignment from the loop initializer while keeping pointer increment, testing whether VC5 delays pointer setup after candidate ID and removes the three-byte size residue. [same emitted code as probe 47]
probe 49 liveness; result=MISMATCH; diff=606; shape=97.90419161676647: Hypothesis 18: bind the farm candidate object ID before the ManagedArray scan, matching the original post-count EDX load and memory compare topology; tests the largest remaining exact-block gap.
probe 50 abi; result=MISMATCH; diff=906; shape=97.90419161676647: Hypothesis 19: keep the proven pointer exclusion and objectId farm alias but restore an int exclusion flag, testing whether the original dword EBP flag and EBX score colors outweigh the bool basin's byte lowering.
probe 51 liveness; result=MISMATCH; diff=606; shape=97.90419161676647: Hypothesis 20: move score before bestObject in the bool/pointer/objectId basin, testing the final declaration-order axis for swapping score EBP and resourceType EBX. [same emitted code as probe 49]
probe 57 baseline; result=MISMATCH; diff=606; shape=97.90419161676647: Fresh baseline after resume: pinned byte-offset cursor source rebuilds 1131 bytes, diff 606, all 16 ordered calls aligned; exclusion loop remains first structural divergence. [same emitted code as probe 56]
probe 58 control-flow; result=MISMATCH; diff=920; shape=83.53293413173652: Use decompiler-supported zero-init plus positive-count do/while exclusion scan with block-local pointer, testing original EBP flag and EBX resource-type basin.
probe 60 control-flow; result=MISMATCH; diff=912; shape=85.3731343283582: Keep exclusion pointer initialization after the positive count guard, but use a natural top-tested while loop to test whether original register and block topology avoid the do/while frame expansion.
probe 62 abi; result=MISMATCH; diff=906; shape=97.90419161676647: Test dword exclusion flag with the otherwise pinned for-loop source, matching original EBP flag width while preserving byte-offset cursor and call surfaces. [same emitted code as probe 50]
probe 64 liveness; result=MISMATCH; diff=606; shape=97.90419161676647: Reverse score and bestObject declaration order from pinned basin, testing the original EBP score and EBX resource-type register coloring without changing predicates or calls. [same emitted code as probe 57]
probe 66 liveness; result=MISMATCH; diff=921; shape=83.23353293413173: Retry block-local exclusion index and pointer without declaration initializers, preserving valid C++ goto scope while testing original local lifetimes.
probe 68 liveness; result=MISMATCH; diff=938; shape=96.98795180722891: Name the current resource ID only for exclusion comparison while retaining a direct reread for object(), testing the original EDI candidate load and object fault order.
probe 70 liveness; result=MISMATCH; diff=606; shape=97.90419161676647: Use a short address-taken resource-id alias only for exclusion, reflecting the decompiler pointer role while preserving direct object() rereads. [same emitted code as probe 64]
probe 72 liveness; result=MISMATCH; diff=606; shape=97.90419161676647: Copy resType after gatherer setup and use the local through resource scans, predicates, loop bound, and dropsite update, testing late resource-index ownership against the original EBX basin. [same emitted code as probe 70]
probe 74 abi; result=MISMATCH; diff=606; shape=97.90419161676647: Apply period-plausible register hint to read-only resType, testing whether the original EBX resource index and EBP score colors are allocator-driven rather than structural. [same emitted code as probe 72]
probe 76 abi; result=MISMATCH; diff=606; shape=97.90419161676647: Apply period-plausible register hint to the long-lived score accumulator, testing evidence-supported EBP score coloring against the pinned source. [same emitted code as probe 74]
probe 78 control-flow; result=MISMATCH; diff=924; shape=85.88588588588588: Use direct exclude[j] indexing in the ordinary for scan, testing whether VC5 naturally delays the pointer load and matches the original exclusion CFG without a pointer local.
probe 80 liveness; result=MISMATCH; diff=906; shape=97.90419161676647: Use a dword exclusion flag declared before score, matching original CMP flag width and testing declaration-order register coloring for EBP flag and EBX resource index. [same emitted code as probe 62]
probe 82 control-flow; result=MISMATCH; diff=542; shape=97.30538922155688: Replace exclusion early goto with natural positive if (!excluded) body nesting, retaining every object reread, rejection edge, call, and next iteration target.
probe 83 control-flow; result=MISMATCH; diff=896; shape=97.30538922155688: Keep positive exclusion-body nesting but use a dword flag, testing whether the natural nested source retains original CMP flag form and closes the remaining EBX/EBP basin.
probe 85 liveness; result=MISMATCH; diff=542; shape=97.30538922155688: Retain positive exclusion-body nesting and reverse score/bestObject declarations, testing whether local order changes the still-opposite EBX score and EBP resource-index colors. [same emitted code as probe 82]
probe 87 liveness; result=MISMATCH; diff=542; shape=97.30538922155688: Keep natural positive exclusion nesting and split a late resourceType copy between predicates/update and direct array accesses, testing whether real dual ownership recovers EBX resource and EBP score without behavior drift. [same emitted code as probe 85]
probe 88 control-flow; result=MISMATCH; diff=542; shape=97.30538922155688: Nest the non-null object processing in an explicit else arm, matching the decompiler's positive object branch while preserving null marking, rereads, calls, and fault order. [same emitted code as probe 87]
probe 90 control-flow; result=MISMATCH; diff=927; shape=85.11904761904762: Combine positive exclusion-body nesting with an explicit excludeCount guard, testing decompiler-supported guard topology under the lower-pressure nested source basin.
probe 94 control-flow; result=MISMATCH; diff=905; shape=91.3946587537092: Natural exclusion reconstruction: int flag, zero index, positive-count do loop, candidate ID materialized before exclude pointer; preserves original exclusion predicates and fault order.
```
<!-- end-recovered:2049f9d324ffce582aba -->

<!-- recovered:d472b3345d9b0e1c7a78 -->
### `81b8cb0e6433` `src/scratch/004D9240_gameIDOfResourceObject.cpp:1-63`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA 004D9240 TribeInformationAIModule::gameIDOfResourceObject
// taiinfmd.cpp:1188-1484
// Attempt log:
// 1: Natural reconstruction from packet/decompiler, modeling ResourceMemory scan and scoring/filter logic.
// 2: Added output resource id initialization to -1 and mainDecision object(gathererId) lookup/null return.
// 3: Added currentZone and __ftol-style gatherer X/Y capture plus isBoat(gatherer) classification.
// 4: Added resource-list scan over arrays at +0x4D0/+0x4E0 and ResourceMemory stride 0x14 with dead/delay handling.
// 5: Added caller-supplied exclusion-list scan and missing-object dead marking/dropsite-update detection.
// 6: Added boat-vs-land class filters for classes 5/0x1F/0x21.
// 7: Added score calculation from squared tile distance, memory base field, age/amount divisors, numberGatherersWithTarget pressure, and best-score replacement.
// 8: Added special filters for animals/farms/buildings: towncenter/enemy attack checks, same-civ/state checks, important-id scan, per-resource gatherer thresholds, strategic-number/resource-count test.
// 9: Added gatherer lookupZone equality gate and final best-object result update: increment memory byte +6, write resource id, return memory id.
// 10: Fixed VC5 goto-crosses-initialization errors by hoisting loop locals.
// 11: Default /O2 /Oy exact-size build compares but is broad: 954 bytes / 84.4248% positional, first mismatch offset 9. Main early issue is register allocation/prologue: original keeps this in ESI and object in EDI; rebuilt keeps this in EBP and object in ESI, cascading through the function.
// 12: Probed /O2 /Oy /Ob0: identical broad mismatch; removed flag.
// 13: Probed /Od: exact size but wrong basin from offset 0 (91.5044% positional); removed flag.
// 14: Probed /O2 /Oy /Og-: exact size but wrong basin from offset 0 (91.5044% positional); removed flag.
// 15: Replaced the out-of-line tactical() wrapper with direct +0x1146C typed calls and bound the threshold to DAT_00575568; this removes six extra wrapper call sites and restores the original global identity, while retaining the clean reconstruction.
// 16: Restored canonical RGE_Static_Object/RGE_Master_Static_Object offsets and ResourceMemory/ManagedArray ownership names (compiler pointer, id, gatherValue, farmsTaskedThisUpdate); this is a source/layout reconstruction probe, not a raw-offset workaround.
// 17: Changed the gatherer gate to a positive outer guard with the shared -1 epilogue, matching the original far JE topology instead of an early negative return.
// 18: Corrected two binary-proven farm/strategic rejection edges to the shared next-resource path (004D9642/004D9646); removed the decompiler-only skip_restore label.
// GIVEUP: left in scratch. Behavior is broad but source/register topology is far from original; no accepted_drift because mismatch is broad and begins in prologue/register allocation.
// Main-agent audit: a donor-backed virtual-destructor replacement for the
// proven compiler pointer fields was tested and rolled back because it changed the early
// VC5 prologue/register basin. The typed compiler pointer fields remain explicit binary
// layout evidence in this unresolved scratch reconstruction.
// 19: Same-TU taiinf donors and ABI evidence show md->object returns a typed
// RGE_Static_Object*. Corrected that ownership surface and removed two casts;
// this is a direct typed-call probe, not a register-coloring adjustment.
// 20-29: Tested standard headers, full AIModule inheritance, polymorphic owner
// surfaces, top-level local declarations, cursor forms, and for/do loop forms.
// The best clean basin is 1075/1130 bytes, 88.29% shape, 51.51% exact blocks,
// with all 16 calls aligned. The first mismatch remains the prologue at +9.
// BINARY NOTE: master object_group is at +0x14; the +0x12 pad is required.
// BINARY NOTE: town-center gather attempts use signed division by 150.
// BINARY NOTE: the amount bonus uses a strict greater-than threshold.
// BINARY NOTE: the current source recovers the original ESI this and EDI
// candidate roles. Score and resource type still use opposite registers.
// 30: Recovered the original moving byte cursor with direct typed record
//   accesses. This restored ESI/EDI roles, the +008B cursor setup, and most
//   loop blocks. An exclusion pointer and bool flag improved the structural
//   basin. A named farm object ID restored the farm scan memory compare.
//   Best check: 1131/1130 bytes, 97.90% shape, 85.84% exact blocks, diff 606.
//   All 16 direct calls remain aligned. The remaining broad residue swaps
//   EBX score with EBP resource type and starts in the exclusion scan.
// UNRESOLVED: current source is natural but does not match the original
//   dword exclusion flag or the original EBX/EBP register roles.
// 31: Fresh exact-finish validation restored the pinned source at 1131/1130
// bytes, diff 606, with all 16 ordered calls aligned. A positive nested
// exclusion body reached diff 542 and exact size, but changed block shape and
// did not match the original CMP flag form. Guarded exclusion, dword flags,
// ID aliases, register hints, and resource-index copies regressed or emitted
// duplicate code. Keep the pinned source authoritative.
// UNRESOLVED: the exclusion scan still selects BL for its flag and EBP for the
// resource type, while the executable uses EBP and EBX. The first hunk is
// taiinfmd.cpp:1245-1251 and preserves the direct object reread after it.
// 32: Fresh natural probes of positive score/exclusion guards, scoped and
// reordered score locals, early resource-index aliases, register hints, and
// exclusion ID locals did not improve the pinned basin. Positive exclusion
// nesting reached diff 542 at exact size, but it changed the original block
// topology. The clean source is restored. The executable still proves the
// EBP exclusion flag, EBX resource index, direct object reread, and ordered
// special-filter calls.
```
<!-- end-recovered:d472b3345d9b0e1c7a78 -->
