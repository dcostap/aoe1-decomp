# Function notes: 004F4AA0 `taskUngroupedSoldiers`

## Recovered attempt history

<!-- recovered:7aad3a7295f4835da3a4 -->
### `d050eea3c` `src/taitacmd.cpp:6774-6781`

Mapping: `ambiguous`. next mapped function definition is taskUngroupedSoldiers at old line 6862.

```text
// 8: restored the period ManagedArray operator[] growth/copy surface and the typed informationAI subobject; this is the clean structural probe.
// Prior liveness probes: a count-first assignment changed the whole basin; a
// named element pointer and declaration reorder were codegen duplicates.
// [non-comment lines omitted during migration]
// rolled back. playUnits[51] preserves the binary's reserved leading output
// slot and 0x1A4 local window; exact 823-byte match.
```
<!-- end-recovered:7aad3a7295f4835da3a4 -->

<!-- recovered:c6b82a5db87d067f03f9 -->
### `6a2aef2e2` `src/taitacmd.cpp:5905-5910`

Mapping: `strong`. next mapped function definition is taskUngroupedSoldiers at old line 5990.

```text
// 6: first soldier loop also uses edi=i+1 and ebp as byte offset; original uses ebp as integer index and ebx as i+1/new max.
// 7: array growth/copy behavior and later call sequence are semantically represented, but local/register topology is still wrong.
// A side-effectful soldiers[i] capacity ensure followed by direct value access
// recovered the target's count/load/store interleave.
// unplayedSoldiers[51] fixed the frame but shifted the play-unit argument;
// Exact: default /O2 /Oy, 823/823 bytes, 22/22 calls, no custom flags or inline asm.
```
<!-- end-recovered:c6b82a5db87d067f03f9 -->

<!-- recovered:b1c35f304bdc435f71b7 -->
### `6a2aef2e2` `src/taitacmd.cpp:6053-6083`

Mapping: `strong`. comment lies after mapped function taskUngroupedSoldiers at old line 5990.

```text
//   (md at +0xF0, embedded informationAI at md+0xCEC, groups sentinel at
//   +0x9D4, and the ten ManagedArray<int> buckets) and the two ordered group
//   validating this call/order surface.
//   while(1) sentinel exits; this recovered the original loop-top null check.
//   water fully-explored gate.
//   loop tail instead of falling into action-10/11 checks.
//   and the trade fully-explored gate.
//   the outer loop; replaced the found-reset null-object return with next-group.
//   installed, as required by the executable's shared task tail.
//   is retained.
//   named canonical RGE/AIModule surfaces, corrected AIModule to 0xF0, and
//   declared the XYZPoint canPath overload before the integer overload.
//   branch already proves the fallback type and the original has no second
//   virtual type call there.
//   target-location tail; this matches the single original setTargetLocation
//   site without the 0x6C frame introduced by new target locals.
//   checks (the original does not jump to next_group after its task call).
//   tail for default/target/action-11 paths and skipped setAction for unknown
//   first-pass types.  This resolves the task/action/type/target-location call
//   count gaps while keeping frame 0x60.  The best validated source remains in
//   frame 0x60.  The remaining aggregate gap is one setAction and one setInUse
// - the executable has one physical setTargetLocation call site
//   for the resource/trade target setup.  Keep those coordinates as direct
//   arguments so VC5 can share the tail without extra float reloads.
// - LIKELY INTENT: the action-8 found reset is a separate task path.  Its
//   still run, but the executable uses a shared tail instead.
//   tactical ManagedArray field or call one of its methods. The array members
//   only establish later class offsets, which the current 16-byte layout
//   already models. No shared-header migration applies to this target.
//   2278 and 2203 bytes. Restored the clean 2070-byte source.
//   shape, 97.87% ordered calls, 2070 differing bytes. Result remains
```
<!-- end-recovered:b1c35f304bdc435f71b7 -->

<!-- recovered:8322b49d252ad8609dbd -->
### `target-session` `build/target_sessions/004F4AA0_taskUngroupedSoldiers.json:1-109`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=501; shape=83.83458646616542: Clean typed source baseline; establish behavior, calls, frame, and mismatch.
probe 2 behavior; result=MISMATCH; diff=493; shape=86.36363636363636: Replaced raw XYPoint/address and object-in-int hacks with typed soldierObj, direct XYPoint references, and natural coordinate reads; test canonical source model.
probe 3 liveness; result=MISMATCH; diff=493; shape=86.36363636363636: Swapped loop-local roles: one named outer i and inner j, matching decompiler's source-level outer-index hypothesis; test register lifetime and delayed EDI save. [same emitted code as probe 2]
probe 4 liveness; result=MISMATCH; diff=493; shape=86.36363636363636: Made the soldier object receiver branch-local; tests whether shorter pointer lifetime restores EBX outer index and delayed EDI save without ABI changes. [same emitted code as probe 3]
probe 5 liveness; result=MISMATCH; diff=497; shape=83.0827067669173: Changed the outer soldiers alias from reference to pointer, matching the decompiler's this_00 pointer ownership; test receiver lifetime and register colors.
probe 6 behavior; result=MISMATCH; diff=403; shape=74.8062015503876: Replaced the repeated soldiers[i] indexer with direct soldiers.value[i] after the proven capacity guard; test whether binary's direct load selects the natural source basin.
probe 7 context; result=MISMATCH; diff=497; shape=83.0827067669173: Replaced the local template with the exact same-TU donor's concrete ManagedArray_int surface; test whether template context drives register, frame, and inline-growth lowering.
probe 8 liveness; result=MISMATCH; diff=730; shape=84.46969696969697: Removed the soldiers reference alias and used direct typed member access throughout; tests whether original direct field ownership controls outer index and saved-register topology.
probe 9 behavior; result=MISMATCH; diff=497; shape=84.58646616541354: Restored the period-plausible XYPoint field assignments center.x=world_x and center.y=world_y; tests whether decompiler field labels hid a contiguous center aggregate.
probe 10 layout; result=MISMATCH; diff=497; shape=83.0827067669173: Restored function-scope soldierObj and the binary-supported split XYPoint assignments; this tests local-home ownership without raw address casts. [same emitted code as probe 5]
probe 11 liveness; result=MISMATCH; diff=511; shape=81.0077519379845: Named the soldier value before the first ungrouped scan, matching the original early load and its EDI lifetime; test whether source liveness selects EBX outer index and delayed EDI save.
probe 12 context; result=MISMATCH; diff=493; shape=86.36363636363636: Removed the currentTime temporary and used direct world_time expressions for guard and timestamp store; tests whether original preamble liveness is expression-driven. [same emitted code as probe 4]
probe 13 liveness; result=MISMATCH; diff=493; shape=86.36363636363636: Changed the branch-local ungrouped array alias from pointer to reference; tests whether direct member aliasing matches original EDI pointer lifetime. [same emitted code as probe 12]
probe 14 control-flow; result=MISMATCH; diff=669; shape=81.92307692307692: Changed both duplicate scans from guarded do/while to natural top-tested while loops; tests whether source loop form explains original branch topology.
probe 15 liveness; result=MISMATCH; diff=511; shape=81.0077519379845: Made soldier a function-scope local and assigned it before the first scan; tests a longer ordinary value lifetime against the original EDI soldier register. [same emitted code as probe 11]
probe 16 abi; result=MISMATCH; diff=493; shape=86.36363636363636: Replaced the static-object virtual destructor with an explicit vptr field while preserving proven world_x/world_y offsets; context-only ABI-surface test. [same emitted code as probe 13]
probe 17 context; result=MISMATCH; diff=493; shape=86.36363636363636: Added the period donor's math.h alongside stdlib.h; tests supported translation-unit header state for VC5 register and block scheduling. [same emitted code as probe 16]
probe 18 behavior; result=MISMATCH; diff=1094; shape=46.01063829787234: Replaced explicit soldier capacity guards with natural ManagedArray operator[] accesses at each observed read; tests whether inline indexer growth is the source of all five resize sites.
probe 19 layout; result=MISMATCH; diff=493; shape=86.36363636363636: Swapped the two typed XYPoint declaration order while retaining direct references; tests stack-home assignment against original local addresses. [same emitted code as probe 17]
probe 20 layout; result=MISMATCH; diff=511; shape=81.0077519379845: Moved soldier to a function-scope local declared before the outer index, but assigned at the original post-guard site; tests declaration order as a supported VC5 home-allocation cause. [same emitted code as probe 15]
probe 21 behavior; result=MISMATCH; diff=493; shape=86.36363636363636: Used the binary-decompiler-supported moveUnit coordinate shape: gatherPoint.y plus the observed uninitialized local_4; tests preserved fault/order and stack-home evidence.
probe 23 liveness; result=MISMATCH; diff=493; shape=86.36363636363636: Hypothesis 1: mark the outer soldier index register. Original keeps it in EBX and delays the EDI save until the positive soldier arm; rebuilt assigns the same source index to EDI at entry.
probe 25 context; result=MISMATCH; diff=493; shape=86.36363636363636: Hypothesis 2: zero through twelve dummy predecessors and exact playTaskSoldiers, taskIdleSoldiers, active, and active-plus-play predecessors emit identical target bytes. TU context does not change the early EDI save or register coloring.
probe 26 liveness; result=MISMATCH; diff=493; shape=86.36363636363636: Hypothesis 3: make soldier function-scope but assign it only at the original second-scan point. Earlier probes assigned it before the first scan; this isolates lexical register coloring without extending its value lifetime. [same emitted code as probe 22]
probe 28 control-flow; result=MISMATCH; diff=770; shape=72.22222222222223: Hypothesis 4: express the grouped-unit removal argument as soldiers[i]. The exact ManagedArray operator[] and remove donors naturally inline the observed resize guard and removal body at 004F4B57.
probe 30 liveness; result=MISMATCH; diff=497; shape=83.0827067669173: Hypothesis 5: use a soldiers pointer alias throughout while retaining the corrected binary-supported coordinates. This retests alias opacity without the earlier coordinate confound and can prevent first-scan hoisting.
probe 32 control-flow; result=MISMATCH; diff=669; shape=83.84615384615384: Hypothesis 6: use exact-donor for-loops for both ungrouped membership scans. Original tests count before entry, maximum at the top, and count at the backedge without the rebuilt pointer-walk blocks.
probe 34 control-flow; result=MISMATCH; diff=230; shape=91.18773946360153: Hypothesis 7: change only the first ungrouped membership scan to the exact-donor for-loop. This isolates the original 004F4C18 scan without changing second-scan local lifetime or insertion code.
probe 35 liveness; result=MISMATCH; diff=482; shape=84.15094339622641: Hypothesis 8: initialize the second-scan index before loading soldier and ungroupedCount. Original 004F4CA9-004F4CB5 zeroes EAX before both loads and tests count after the soldier load.
probe 36 layout; result=MISMATCH; diff=230; shape=91.18773946360153: Hypothesis 9: with the first for-loop register basin retained, declare gatherPoint before centerPoint. The rebuilt pre-EDI stores use entry homes -4 and -16; original requires center.y at -16 and gather.x at -12. [same emitted code as probe 34]
probe 37 layout; result=MISMATCH; diff=230; shape=91.18773946360153: Hypothesis 10: declare local_4 before gatherPoint and centerPoint. Original physical order is center at -0x14, gather at -0x0C, and local_4 at -4; VC5 allocates these declaration groups in reverse. [same emitted code as probe 36]
probe 38 layout; result=MISMATCH; diff=231; shape=91.18773946360153: Hypothesis 11: model the proven contiguous center, gather, and trailing int homes as one local aggregate. Its 20-byte field order exactly matches original entry homes -0x14 through -4 while both point addresses escape.
probe 39 control-flow; result=MISMATCH; diff=669; shape=83.84615384615384: Hypothesis 12: use a distinct block-scope for-loop index for the second membership scan. This keeps the exact first-scan j lifetime while testing original count-before-entry and indexed second-scan code. [same emitted code as probe 32]
probe 40 control-flow; result=MISMATCH; diff=669; shape=83.07692307692308: Hypothesis 13: change only the second membership scan to a top-tested while. This preserves the exact first for-loop basin and tests the original count gate without a separate source if/do region.
probe 41 liveness; result=MISMATCH; diff=230; shape=91.18773946360153: Hypothesis 14: use direct ungroupedSoldiers.value[j] only in the second scan body. The rebuilt alias expression becomes a pointer induction; original reloads the base and uses indexed addressing each iteration. [same emitted code as probe 37]
probe 42 control-flow; result=MISMATCH; diff=230; shape=91.18773946360153: Hypothesis 15: spell the second do-loop as an explicit infinite loop with maximum and bottom count breaks. This preserves current scopes while matching original top maximum and bottom count terminators directly. [same emitted code as probe 41]
probe 43 layout; result=MISMATCH; diff=230; shape=91.18773946360153: Hypothesis 16: place local_4 between centerPoint and gatherPoint in declaration order. This tests the remaining natural local-order family against the original contiguous -0x14 through -4 homes. [same emitted code as probe 42]
probe 44 control-flow; result=MISMATCH; diff=222; shape=93.48659003831418: Hypothesis 17: spell all capacity predicates with the index/count on the left. The checker reports five exact compare-operand swaps paired with reversed branches across these guards.
probe 45 liveness; result=MISMATCH; diff=478; shape=86.79245283018868: Hypothesis 18: initialize the shared second-scan index before entering the soldier/count scope. This requests original XOR-before-load order without placing the assignment between scoped declarations.
probe 46 liveness; result=MISMATCH; diff=222; shape=93.48659003831418: Hypothesis 19: name the second-scan value pointer inside the loop body. Original reloads [EDI] each iteration, then uses [base+EAX*4]; rebuilt strength-reduces the direct expression to a pointer induction. [same emitted code as probe 44]
probe 47 liveness; result=MISMATCH; diff=478; shape=86.79245283018868: Hypothesis 20: declare second-scan soldier/count first, then sequence j=0, soldier load, and count load in the positive predicate. This requests original instruction order without moving an initialized declaration across scopes. [same emitted code as probe 45]
probe 49 layout; result=MISMATCH; diff=220; shape=95.78544061302682: Apply original CodeView local evidence: function-scope soldierObj, centerPoint at the two world-coordinate stores, gatherPoint as the finder output, and both gather fields in moveUnit. Remove the unsupported uninitialized local.
probe 50 liveness; result=MISMATCH; diff=220; shape=95.78544061302682: Use separate loop-local indices. The original CodeView function symbols omit j, and the two membership scans can have independent lexical index lifetimes. [same emitted code as probe 49]
probe 51 liveness; result=MISMATCH; diff=478; shape=86.0377358490566: Initialize the second scan index before loading the cached soldier and count. This is the exact source order suggested by original XOR, soldier load, then count load at +20B..+210, now with PDB-correct point homes.
probe 52 control-flow; result=MISMATCH; diff=668; shape=85.76923076923077: Use a loop-local count-bounded for-loop for the second scan, matching the first scan source family while retaining the cached count required by the following append.
probe 53 liveness; result=MISMATCH; diff=220; shape=95.78544061302682: Keep the cached soldier for append, but spell the second-scan comparison with soldiers.value[i]. Original reloads outer i inside each scan iteration even though EDX already holds the same soldier value. [same emitted code as probe 50]
probe 54 liveness; result=MISMATCH; diff=706; shape=81.85328185328186: Remove the synthetic cached-soldier source local. Let VC5 hoist soldiers[i] from the second scan, then reuse the direct soldier value for append. The original PDB has no soldier integer local.
probe 55 liveness; result=MISMATCH; diff=817; shape=77.70270270270271: Keep the cached soldier for append, but use soldiers[i] in the second-scan comparison. This tests whether the source-level outer-index use explains the original per-iteration EBX restore.
probe 56 variant; result=MISMATCH; diff=805; shape=74.91525423728814: Use guarded ManagedArray operator[] in the second scan. The preceding maximum-size test makes resize unreachable, but the inline source form can retain original indexed addressing.
probe 57 control-flow; result=MISMATCH; diff=668; shape=85.76923076923077: Model the second scan and append as inlined ManagedArray::add(soldier). Exact donor 004D7070 uses the same count-bounded indexed scan; the original found path skips append but continues to findGatherPosition, which matches an ignored add return. [same emitted code as probe 52]
probe 58 liveness; result=MISMATCH; diff=668; shape=85.76923076923077: Pass soldiers[i] directly to the inlined add. The original CodeView symbols omit a soldier integer local, while the add parameter naturally owns EDX and its spill across resize. [same emitted code as probe 57]
probe 59 control-flow; result=MISMATCH; diff=343; shape=95.40229885057471: Combine the inlined add donor with the original prechecked do-loop spelling for the first membership scan. The two inlined loop shapes jointly control VC5 function-wide register allocation.
probe 60 control-flow; result=MISMATCH; diff=668; shape=85.76923076923077: Model the first scan as inlined ManagedArray::contains(const T&), paired with inlined add. The reference parameter explains the original per-iteration reload of soldiers.value[i], and these are the period ManagedArray surfaces used by nearby exact donors. [same emitted code as probe 58]
probe 62 control-flow; result=MISMATCH; diff=668; shape=85.76923076923077: Use a top-tested while for the first scan while retaining inlined add. This keeps the header shared by entry and backedge and can prevent VC5 from folding the initial maximum comparison. [same emitted code as probe 60]
probe 63 control-flow; result=MISMATCH; diff=343; shape=95.40229885057471: Place the first-scan increment in the do-loop condition. This natural form keeps the prechecked-do allocation basin but can retain the maximum test as the shared loop header. [same emitted code as probe 61]
probe 64 control-flow; result=MISMATCH; diff=343; shape=95.40229885057471: Model the first scan as an inlined prechecked-do implementation of ManagedArray::contains(const T&). This retains the allocation basin while testing the likely class-level source ownership. [same emitted code as probe 63]
probe 67 control-flow; result=MISMATCH; diff=343; shape=95.40229885057471: Use the exact 004DE980 contains body for the second duplicate scan, then spell the observed resize and append explicitly. Keep the prechecked first scan that preserves the original function-wide register basin. [same emitted code as probe 66]
probe 68 liveness; result=MISMATCH; diff=668; shape=85.76923076923077: Use the exact 004DE980 contains body for both duplicate scans. Its wanted/current source locals are the untested donor feature that can affect inlined function-wide register allocation. [same emitted code as probe 62]
probe 69 liveness; result=MISMATCH; diff=668; shape=85.76923076923077: Store the first exact-donor contains result in a named register local and test it against one. This tests the likely source sequence while retaining the inlined early-return scan. [same emitted code as probe 68]
probe 70 liveness; result=MISMATCH; diff=343; shape=95.40229885057471: Keep the prechecked first loop that preserves the original register basin, but use the exact contains donor's wanted/current temporaries inside it. [same emitted code as probe 67]
probe 71 liveness; result=MISMATCH; diff=668; shape=85.76923076923077: Combine the original best function-scope first-scan index with the exact contains donor and explicit second append. Prior loop-local tests were duplicates only under the old second-scan source model. [same emitted code as probe 69]
probe 72 control-flow; result=MISMATCH; diff=343; shape=95.40229885057471: Keep the prechecked-do allocation basin but spell its maximum guard as a positive nested arm. This can retain indexed addressing without converting the loop to for/while form. [same emitted code as probe 70]
probe 73 liveness; result=MISMATCH; diff=668; shape=85.76923076923077: Keep both indexed scans, but return soldierObj to its natural positive-arm scope. CodeView proves its stack home, not function scope; this lifetime can restore the original 0x1C allocation basin. [same emitted code as probe 71]
probe 75 context; result=MISMATCH; diff=668; shape=85.76923076923077: Define the exact contains donor out of class, as a header template definition, and use it for both scans. This tests whether VC5's inline function queue and scheduling differ from an in-class body. [same emitted code as probe 73]
probe 76 context; result=MISMATCH; diff=668; shape=85.76923076923077: Define both operator[] and contains out of class in header order. These two inline templates own the adjacent original scans and can change VC5's internal inline-function queue. [same emitted code as probe 75]
probe 77 liveness; result=MISMATCH; diff=668; shape=85.76923076923077: Use the single PDB-proven soldierObj local for both the initial type-109 object and each soldier object. CodeView records no separate initial object pointer, so this is the stronger original lifetime model. [same emitted code as probe 76]
probe 78 liveness; result=MISMATCH; diff=668; shape=85.76923076923077: Name the prior task timestamp after currentTime. The canonical two-contains form differs first by swapping this and lastTaskTime between EBX and EBP; this source local can resolve that allocator tie. [same emitted code as probe 77]
probe 79 control-flow; result=MISMATCH; diff=672; shape=85.38461538461539: Use a natural count-bounded for-loop for the outer soldier scan with both exact contains expansions. This tests whether the outer induction source restores EBX and delayed EDI allocation.
probe 80 control-flow; result=MISMATCH; diff=672; shape=85.38461538461539: Use a natural outer for-loop continue instead of the synthetic next_soldier label. No PDB label supports that source goto, and continue can change VC5's loop liveness and shrink-wrapping. [same emitted code as probe 79]
probe 81 control-flow; result=MISMATCH; diff=672; shape=85.38461538461539: Nest the soldier work under contains(...) == 0 instead of using continue or a synthetic label. This is the simplest natural source for the original found-to-loop-tail branch. [same emitted code as probe 80]
probe 82 liveness; result=MISMATCH; diff=667; shape=84.67432950191571: Remove the unrecorded cached soldier local from the second exact contains call and append. Let operator[] and the direct value expression supply the same value with a shorter source lifetime.
probe 83 control-flow; result=MISMATCH; diff=744; shape=85.5595667870036: Let soldiers[i] own the resize block immediately before the first contains scan. The original line-5551 guard directly precedes that argument, so the explicit guard plus raw value access is likely a split decompiler model.
probe 84 liveness; result=MISMATCH; diff=692; shape=83.83458646616542: Use a natural found flag around the first count-bounded for-loop. VC5 can fold the flag to the original direct loop-tail branch while its source lifetime may retain the 0x1C allocation basin.
probe 86 context; result=MISMATCH; diff=668; shape=85.76923076923077: Compile one same-template ManagedArray<int>::contains predecessor before the canonical two-contains target. Earlier context labs used separate wrapped class definitions and did not instantiate this exact template first. [same emitted code as probe 78]
probe 88 abi; result=MISMATCH; diff=413; shape=79.06976744186046: Use the reconstructed PDB-proven ManagedArray API. Replace impossible protected field and resize access with number, operator[], contains, add, and remove.
probe 89 liveness; result=MISMATCH; diff=575; shape=78.68217054263566: Remove the unsupported cached soldier local. Pass soldiers[i] separately to contains and add, preserving both original operator[] evaluations and their growth paths.
probe 90 liveness; result=MISMATCH; diff=575; shape=78.68217054263566: Bind only the add argument to the reference returned by soldiers[i]. This separates the second operator[] expansion from the nested add expression without adding storage. [same emitted code as probe 89]
probe 91 liveness; result=MISMATCH; diff=575; shape=78.68217054263566: Keep one local ManagedArray reference for soldiers while using only public methods. This mirrors the original persistent ESI array base and can change nested operator[] inlining. [same emitted code as probe 90]
probe 92 flags; result=MISMATCH; diff=575; shape=78.68217054263566: Raise VC5 inline depth for the target. Test whether the missing nested resize expansion is depth-limited rather than source-structure limited. [same emitted code as probe 91]
probe 93 context; result=MISMATCH; diff=575; shape=78.68217054263566: Mark resize explicitly inline in the reconstructed header. Test whether VC5 assigns stronger nested-inline priority than the implicit in-class form. [same emitted code as probe 92]
probe 94 control-flow; result=MISMATCH; diff=610; shape=97.6923076923077: Use the natural count-bounded outer for-loop through number(). Test whether its induction lifetime restores EBX and changes the second nested operator[] decision.
probe 95 liveness; result=MISMATCH; diff=198; shape=98.45559845559846: Declare the soldiers reference inside the natural for-loop body. Keep the initial count test on this->soldiers so VC5 can delay the ESI array-base LEA until after the guard.
probe 96 context; result=MISMATCH; diff=198; shape=98.45559845559846: Use the exact add donor's direct duplicate scan instead of composing add through contains. Both forms match standalone add, but the donor form can recover the inlined EBX clobber and reloads. [same emitted code as probe 95]
probe 97 liveness; result=MISMATCH; diff=198; shape=98.45559845559846: Give add the same exact-donor current and wanted temporaries as contains. Test whether their inlined lifetime keeps the count in ECX and selects EBX for the duplicate-scan base. [same emitted code as probe 96]
probe 98 liveness; result=MISMATCH; diff=198; shape=98.45559845559846: Cache add's initial numberValue as the duplicate-scan bound. The original inlined add preserves ECX across the scan, while the rebuild reloads that member after using ECX as the value base. [same emitted code as probe 97]
probe 99 control-flow; result=MISMATCH; diff=198; shape=98.45559845559846: Spell add's exact standalone duplicate scan as an initialized while-loop. Test whether the inlined update placement preserves the count register and forces the original outer-index reload. [same emitted code as probe 98]
probe 100 liveness; result=MISMATCH; diff=198; shape=98.45559845559846: Give add's short-lived current value the period register hint. Test whether VC5 assigns its inlined array-base path to EBX while preserving exact standalone add. [same emitted code as probe 99]
probe 101 liveness; result=MISMATCH; diff=377; shape=98.08429118773947: Name the ungroupedSoldiers reference across contains and add. This models the original persistent EDI owner and can alter the register choice inside the second inlined scan.
probe 102 liveness; result=MISMATCH; diff=673; shape=85.44061302681992: Bind the first soldiers[i] result by reference before naming ungroupedSoldiers. This delays the EDI owner LEA until after operator[] growth while retaining its lifetime through add.
probe 103 liveness; result=MISMATCH; diff=198; shape=98.45559845559846: Scope the ungroupedSoldiers reference to the contains-miss arm before add. Preserve the exact first contains setup while extending the EDI owner only across the second inline scan. [same emitted code as probe 100]
probe 104 liveness; result=MISMATCH; diff=198; shape=98.45559845559846: Carry add's cached count from its duplicate scan into the capacity check and resize argument. This source dependency matches the original preserved ECX value across those blocks. [same emitted code as probe 103]
probe 105 liveness; result=MISMATCH; diff=198; shape=98.45559845559846: Apply the period register hint to the outer index. Test whether VC5 permits add's inlined scan to reuse EBX and restore it from the proven i stack home. [same emitted code as probe 104]
probe 106 control-flow; result=MISMATCH; diff=198; shape=98.45559845559846: Use the natural logical-negation contains guard instead of comparison with zero. Test whether its source predicate changes the inline add allocation without changing the exact first scan. [same emitted code as probe 105]
probe 107 liveness; result=MISMATCH; diff=198; shape=98.45559845559846: Mark add's cached count as register. Test whether VC5 preserves it across the duplicate scan and allocates the transient value base to EBX. [same emitted code as probe 106]
probe 108 liveness; result=MISMATCH; diff=198; shape=98.45559845559846: Declare the findGatherPosition result before the inlined add and assign it afterward. Test whether this natural declaration lifetime changes the second scan's transient register choice. [same emitted code as probe 107]
probe 109 liveness; result=MISMATCH; diff=198; shape=98.45559845559846: Name add's value pointer inside each duplicate-scan iteration. This keeps standalone add exact while giving the inlined transient base explicit ownership that can select EBX. [same emitted code as probe 108]
probe 110 liveness; result=MISMATCH; diff=198; shape=98.45559845559846: Apply the period register hint to add's iteration-local value pointer. Test whether VC5 selects EBX for this exact standalone transient base. [same emitted code as probe 109]
probe 111 context; result=MISMATCH; diff=198; shape=98.45559845559846: Compile the full public-API target after zero through twelve dummy predecessors and exact play, idle, and active predecessors. All 17 masked target sections are identical; ordinary preceding TU context does not select EBX in add. [same emitted code as probe 110]
probe 112 liveness; result=MISMATCH; diff=41; shape=98.44961240310077: Diagnostic only: cache add's maximum capacity. The structured lab found exact target size and a 41-byte positional score, although this source breaks the exact standalone add donor.
probe 113 liveness; result=MISMATCH; diff=41; shape=98.44961240310077: With the diagnostic exact-prefix add basin, restore PDB symbol order: i, soldierObj, centerPoint, gatherPoint. Remove the index register hint and test the remaining argument register map. [same emitted code as probe 112]
probe 114 liveness; result=MISMATCH; diff=41; shape=98.44961240310077: Remove optimized aliases and keep findGatherPosition directly in its success predicate. Test whether natural nested argument evaluation restores the remaining original EDX, EAX, and ECX schedule. [same emitted code as probe 113]
probe 115 liveness; result=MISMATCH; diff=41; shape=98.44961240310077: Name the four nonliteral gather-call arguments in the original emitted load order. Test whether their short scopes recover the EDX, EAX, ECX rotation after the exact add prefix. [same emitted code as probe 114]
probe 117 variant; result=MATCH; diff=0; shape=100.0: Exact walkback: replace logical negation with comparison against zero. [same emitted code as probe 116]
probe 118 variant; result=MATCH; diff=0; shape=100.0: Exact walkback: remove the body-scoped soldiers reference and use direct member expressions. [same emitted code as probe 117]
probe 119 variant; result=MATCH; diff=0; shape=100.0: Exact walkback: restore the prior centerPoint-before-soldierObj declaration order. [same emitted code as probe 118]
probe 120 variant; result=MISMATCH; diff=198; shape=98.45559845559846: Exact walkback: restore the named findGatherPosition result local before its comparison. [same emitted code as probe 111]
probe 121 variant; result=MISMATCH; diff=570; shape=78.68217054263566: Exact walkback: replace the outer for-loop with its prior prechecked do-loop form.
probe 122 variant; result=MATCH; diff=0; shape=100.0: Exact walkback: remove the optimized group pointer local and test groupUnitIsIn directly. [same emitted code as probe 119]
probe 123 variant; result=MATCH; diff=0; shape=100.0: Exact walkback: compose add through contains instead of retaining the direct exact-donor duplicate loop. [same emitted code as probe 122]
```
<!-- end-recovered:8322b49d252ad8609dbd -->

<!-- recovered:766602517a77575d80fb -->
### `54ff204f4a08` `src/scratch/004F4AA0_taskUngroupedSoldiers.cpp:1-73`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// Attempt log for 004F4AA0 TribeTacticalAIModule::taskUngroupedSoldiers
// Prior worker notes: a raw-offset scaffold rebuilt 736B vs 740B but used the
// wrong array ownership, object/finder shims, and manual removal/growth shape.
// The current reconstruction restores the same-TU typed ManagedArray surface,
// soldiers at +0x114, ungroupedSoldiers at +0x124, and informationAI at +0xCEC.
//
// Original CodeView symbols prove these stack locals: i at -0x1C, soldierObj
// at -0x14, centerPoint at -0x10, and gatherPoint at -0x08. The two final
// integer loads are gatherPoint.x and gatherPoint.y. They are not an
// uninitialized local.
//
// Claim sa-209e8cdc (21 meaningful hypotheses):
// - Probe 1 established a 760B raw-cast baseline with all 15 calls.
// - Probes 2-4 restored typed soldier objects and XYPoint references. They
//   reached the best 754B basin: 493 strict-diff bytes, 86.36% shape, 1C frame.
// - Probe 5 changed the soldiers alias to a pointer. It reached 757B and was
//   worse. Probe 6 used direct soldiers.value access and lost two allocations.
// - Probe 7 used a concrete ManagedArray_int. It stayed at the 757B basin.
// - Probe 8 used direct this->soldiers access. It reached 776B and drifted.
// - Probes 9-10 tested standard XYPoint fields and local object scope. They
//   stayed at the 757B basin. Probe 11 moved soldier loading before the scan.
//   It reached 751B but lost the original control-flow shape.
// - Probes 12-13 tested direct world_time spelling and an ungrouped reference.
//   Both were codegen duplicates of the best basin.
// - Probe 14 changed both scans to while loops. It reached 744B but changed
//   the frame to 20h and lost exact block islands.
// - Probe 15 repeated the soldier lifetime test with a function-scope local.
//   It stayed at the 751B basin. Probe 16 replaced one known class surface
//   with an explicit vptr. It was a codegen duplicate and was rejected by
//   policy. Probe 17 added math.h. It was a duplicate.
// - Probe 18 used operator[] for every soldier read. It reached 1229B and
//   added five allocation pairs. The observed resize call set requires the
//   explicit capacity touches in this source.
// - Probes 19-20 tested XYPoint declaration order and soldier declaration
//   order. They were duplicates or returned to the 751B basin.
// - Probe 21 used the then-assumed uninitialized local. Later CodeView evidence
//   disproved that interpretation.
//
// Main-agent pass, 2026-08-18:
// - Translation-unit tests with zero through twelve dummy predecessors and
//   exact idle/play/active predecessors emitted identical target bytes.
// - Replacing only the first ungrouped membership do-loop with the exact-donor
//   for-loop recovered the original EBX outer index and delayed EDI save. It
//   reduced the strict diff from 493 to 230 bytes.
// - Index-left capacity predicates recovered five original cmp/branch forms.
//   The best natural source is now 747/740 bytes, 15/15 ordered calls, exact
//   0x1C frame, 93.49% shape, 77.91% exact blocks, and 222 differing bytes.
// - At that point, the remaining seven-byte region was the second membership
//   scan. VC5 turned
//   its natural cached-count do-loop into a pointer induction with one extra
//   conditional block. For/while, explicit-break, scope, pointer, and source
//   order variants either duplicate this basin or damage the frame and early
//   register allocation. Point/local declaration permutations are duplicates.
//
// CodeView and ManagedArray pass, 2026-08-18:
// - Restoring normal centerPoint and gatherPoint ownership made every block
//   outside the second membership scan exact in the 747-byte basin.
// - Exact donor 004DE980 proves the second indexed scan as an inlined
//   ManagedArray::contains operation. The source then calls resize and appends
//   explicitly. Exact add donor 004DE9D0 allocates directly, so add is not the
//   source owner of this block.
// - The exact contains body and explicit append emit the same 343-byte
//   frontier as the earlier add model. Size, frame, saved registers, and calls
//   are exact.
// - Using the exact contains body for the first scan recovers that local CFG,
//   but changes the frame to 0x20 and the function-wide register assignment.
//   Dummy and real predecessor context emits identical target code.
// - Out-of-class template definitions, exact donor temporaries, timestamp and
//   object lifetimes, outer for/continue forms, and positive guard nesting do
//   not resolve that allocation tradeoff. They are duplicates or regressions.
//   A same-template contains predecessor also leaves target code unchanged.
// BLOCKER: preserve the PDB-proven point homes and second contains/append
// model. Recover the first scan without changing the register allocation.
```
<!-- end-recovered:766602517a77575d80fb -->
