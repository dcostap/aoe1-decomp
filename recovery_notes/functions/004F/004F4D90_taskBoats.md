# Recovery journal: 004F4D90 `taskBoats`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/taitacmd.cpp`.
- PDB source: `C:\msdev\work\age1_x1\taitacmd.cpp`.
- Earlier recovery note: `recovery_notes/taitacmd_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:8bfdbe1c12a70411336e -->
### `d050eea3c` `src/taitacmd.cpp:6875-6880`

Mapping: `ambiguous`. next mapped function definition is taskBoats at old line 6976.

```text
// findGatherPosition predicate are codegen-active. A named result changes
// [non-comment lines omitted during migration]
// contains predicate spelling, and the two local declaration orders tested in
// [non-comment lines omitted during migration]
// BINARY NOTE: contains checks membership before add. Inlined add performs its
```
<!-- end-recovered:8bfdbe1c12a70411336e -->

<!-- recovered:0d314d48cb669ced6bb9 -->
### `d050eea3c` `src/taitacmd.cpp:7368-7385`

Mapping: `ambiguous`. comment lies after mapped function taskBoats at old line 6976.

```text
// Attempt log (luna2-004F57C0):
// - Baseline with the exact donor operator[] surface: 2108B rebuilt, 1967
// [non-comment lines omitted during migration]
// - Final remaining drift is structural/local-topology: original frame 0x10
//   versus rebuilt 0x8, with the first mismatch at the prologue and one
//   late group-call alignment issue.  No accepted drift or inline asm.
// [non-comment lines omitted during migration]
// Attempt log (sa-82040434, 2026-08-06):
```
<!-- end-recovered:0d314d48cb669ced6bb9 -->

<!-- recovered:fff1b6f3f388580fd128 -->
### `d050eea3c` `src/taitacmd.cpp:7406-7428`

Mapping: `ambiguous`. comment lies after mapped function taskBoats at old line 6976.

```text
//   count and capacity to stack homes [esp+1Ch]/[esp+18h] (frame 0x10), then
// [non-comment lines omitted during migration]
//   template, whole-file register allocation) that the standalone checker
// [non-comment lines omitted during migration]
// - Main-agent audit replaced synthetic v00/v61/v76/v77 slot scaffolding with
```
<!-- end-recovered:fff1b6f3f388580fd128 -->

<!-- recovered:aa45b73ac609e0550409 -->
### `6a2aef2e2` `src/taitacmd.cpp:5992-6007`

Mapping: `strong`. next mapped function definition is taskBoats at old line 6061.

```text
//
// CodeView proves i at -0x1C, soldierObj at -0x14, centerPoint at -0x10,
// and gatherPoint at -0x08. The move destination uses gatherPoint.x and y.
//
// The protected ManagedArray layout requires the public number, operator[],
// contains, add, and remove methods. The outer for-loop and direct
// inlined add allocation and loses exactness. Direct member expressions, the
// reduction are incidental.
//
// contains checks membership before add. Inlined add performs its
// own duplicate scan. Both scans are present in the original executable.
//
// SHARED-CONTEXT NOTE: the tactical header's nested operator[] growth changes
// this body from 740 to 852 bytes. The canonical utmarray.h surface keeps the
// resize calls out of line and preserves the exact body. Using that surface in
// the shared wrapper regresses earlier exact anchors, so this owner stays out.
```
<!-- end-recovered:aa45b73ac609e0550409 -->

<!-- recovered:df2609f6d166c2ab8322 -->
### `6a2aef2e2` `src/taitacmd.cpp:6441-6513`

Mapping: `ambiguous`. comment lies after mapped function taskBoats at old line 6061.

```text
// Size: 2024 bytes. __thiscall. 62 calls.
//
// retained only at the packet-proven source sites that call 004147A0; the
// parent does not contain compiler-expanded allocation/copy/delete blocks.
//
//   strict diff; recovered the full 62-call family without parent-level grow
//   explicit resize/value sites, positive dropsite block order, and combined
//   task-array bounds.  This reduced the rebuilt body to 2052B and 1878B
//   strict diff with 95.99% shape.
// - Scoped the first civilians ManagedArray alias, used the binary-positive
//   x87 gate (`vf61() == 0.0`, double zero), and nested
//   `group(assistGroupID(), -1, -1, -1)` to preserve source call scheduling.
//   97.12% shape, 89.74% exact-block coverage, all 62 calls aligned.
//
// - AUDITED the checker's +06F2 "commander vs assistGroupID" direct-target
//   discrepancy: the two call targets are actually in the correct order at
//   (004F5F9A -> 004F5E65) returns to the null test at the top of the body,
//   with `or ebp,-1` in the preheader.  Changed `if {...} do {...} while` to
//   a plain `while (group != &this->groups)` with `int minusOne = -1` first in
//   the body.  This resolved the +06F2 artifact and added 8 exact blocks.
// - FIXED the dropsite-success block (line 6089): original keeps
//   `lea ebp,[esi+0D58h]` (unitsTasked alias) live across the resize call and
//   holds n in ecx across the scan; added `ManagedArray<int>* unitsTasked =
//   &this->unitsTaskedThisUpdate;` and read n/cap/value through it.  The
//   whole 6089 block (inline grow + membership scan + resize + append) is now
//   structurally byte-exact.
//   (12.45%), 98.88% shape, 95.03% exact-block coverage, all 62 calls aligned,
//   0 wrong direct targets.  Second scan + group walk byte-exact.
// - REMAINING STALL: the line-6068 first membership scan.  Original spills the
//   reloads them in the loop (`mov edx,[esp+1Ch]`, `cmp eax,[esp+18h]`); the
//   rebuilt substitutes them back to direct member reads ([esi+0D5Ch]/
//   [esi+0D64h]) and drops the frame to 0x8.  Tried ~12 families: while/for
//   +&&/break, locals vs direct-member vs mixed condition bounds, with/without
//   outer `if (n > 0)` guard, pointer and reference aliases, `register`/
//   `const` locals, n loaded before the resize call, full-class surface,
//   game_globals.h include context, and /O1//O2//Ox flag sets.  VC5
//   keep count/cap in registers or substitute member re-reads under register
//   pressure; no source form produces the stack-home spill).  The spill may
//   require the original full taitacmd.cpp TU context (real utmarray.h
//   build cannot reproduce.  Next lead: build a combined-TU or full-class
//   context that reproduces the original allocator pressure, or accept the
// - Also noted: two SIB base/index term swaps remain in the loop-body address
//   encodings (e.g. original `mov ebx,[ecx+edx]` vs rebuilt `mov ebx,[edx+ecx]`
//   at the second-scan civilianID load) - downstream register-color cascades
//   from the first-scan substitution, expected to resolve if the first scan
//   ever aligns.
//   the proven canonical RGE_Player/RGE_Static_Object virtual names and modeled
//   TacticalAIGroup as its real 0x330 object with a named +0x1D0 field. Calls,
//   layout, and behavior remain unchanged; one relocation byte aligned better.
//
// - Exact contains ownership recovers the original 0x10 frame and all four
//   first-scan homes. CodeView lists only i, so the bound homes are compiler
//   state from the inlined method. Exact add also replaces the second manual
//   scan without changing emitted code.
//   CFG, and block coverage. Six bytes differ in one first-scan comparison.
//   Only the transient EBX and EDX assignments are reversed.
// - Zero through twelve dummy predecessors do not change this result. The
//   exact same-TU playTaskSoldiers predecessor produces positional equality in
//   the context lab. Its declarations alone also produce equality.
// - Do not retain unused context declarations or a namespaced duplicate
//   predecessor. The next supported step needs genuine combined taitacmd.cpp
//
// - All six changed bytes are in the five instructions at +0xB3 through
//   +0xC0. The original uses EBX for the task-array value and EDX for the
//   civilian-array base. The rebuild exchanges these two registers.
// - Both versions load the same pointers, select the same indexed task value,
//   and compare it with the same civilian value. They set identical flags for
//   the branch at +0xC1. Calls, memory writes, predicates, and fault order do
//   not change.
// - On fallthrough, +0xC7 replaces EDX and +0xD0 replaces EBX. On the taken
//   path, the loop tail at +0x2C0 uses neither register. The next iteration
//   replaces EBX at +0x25 and EDX at +0x3C before use.
// - Exact playTaskSoldiers same-TU context emits the original register choice.
```
<!-- end-recovered:df2609f6d166c2ab8322 -->

<!-- recovered:f984939a63f15c8b92bb -->
### `target-session` `build/target_sessions/004F4D90_taskBoats.json:1-24`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 control-flow; result=MISMATCH; diff=2127; shape=88.77551020408163: Hypothesis 1: direct setAction calls in each type arm will preserve the original push-immediate common tail instead of materializing a newAction local.
probe 2 liveness; result=MISMATCH; diff=2155; shape=85.71428571428571: Hypothesis 2: resourceID is only the gameID return, resourceMode/exclusionCount start as the two pre-loop locals, and exclusionIndex initializes inside the explored loop; this should recover the original stack stores and homes.
probe 3 liveness; result=MISMATCH; diff=2127; shape=88.77551020408163: Hypothesis 3: reverse first-pass local declaration order while preserving the observed initialization and call order; VC5 declaration order may color ready into EDI and place gathered in the original stack home. [same emitted code as probe 1]
probe 4 control-flow; result=MISMATCH; diff=2117; shape=90.3061224489796: Hypothesis 4: write the second-pass fishing action-8 branch as positive numberWaterExplorers() > 1 first, matching the original fallthrough game-ID block and the jle jump to the commander block.
probe 5 control-flow; result=MISMATCH; diff=2123; shape=90.51282051282051: Hypothesis 5: the found action-8 reset path jumps to the shared task tail after setGatherLocation; the original has no direct task call or later action-10/11 fallthrough on that path.
probe 6 liveness; result=MISMATCH; diff=2117; shape=90.3061224489796: Hypothesis 6: make the first-pass readiness locals function-scope rather than block-scope; VC5 may preserve the original EDI/EBP colors and entry-relative gathered home across the surrounding second pass. [same emitted code as probe 4]
probe 7 behavior; result=MISMATCH; diff=2117; shape=90.3061224489796: Hypothesis 7: the trade action-8 fully-explored fallback passes the proven null trade pointer as task's final argument, matching the original push of EDI and preventing tail merge with the water fallback. [same emitted code as probe 6]
probe 8 control-flow; result=MISMATCH; diff=2070; shape=93.21382842509603: Hypothesis 8: express water and trade target locations as natural direct setTargetLocation calls, then share only the task tail; VC5 may tail-merge the two argument setup paths without spilling object coordinates through output locals.
probe 9 control-flow; result=MISMATCH; diff=2122; shape=93.08578745198463: Hypothesis 9: after the direct target-location rewrite, route the action-8 found reset through the shared task tail; this should align the original common task site and skip later action checks.
probe 10 control-flow; result=MISMATCH; diff=2091; shape=92.6923076923077: Hypothesis 10: keep the found action-8 task call direct but jump immediately to next_group afterward; this preserves its call while matching the original common-tail exit and avoids action-10/11 fallthrough.
probe 11 control-flow; result=MISMATCH; diff=2175; shape=90.22556390977444: Hypothesis 11: use literal task(...,0/1) calls at the target/default/action-11 exits instead of a busyOK variable and shared label; natural tail merging may recover the original immediate pushes without xor/mov materialization.
probe 12 liveness; result=MISMATCH; diff=2070; shape=93.21382842509603: Hypothesis 12: move the busyOK declaration after the first-pass locals; natural declaration order may return ready to EDI and number to EBP without changing call order. [same emitted code as probe 8]
probe 13 control-flow; result=MISMATCH; diff=2086; shape=93.23116219667943: Hypothesis 13: make only the action-11 successful trade retask a direct literal task(...,1) call; this may recover the original immediate busy flag while the zero-target/default paths retain their shared tail.
probe 14 liveness; result=MISMATCH; diff=2070; shape=93.21382842509603: Hypothesis 14: narrow outputX/outputY to the water resource branch and pathDistance to the trade branch; original stack evidence shows local-home reuse, while the outer named float trio creates rebuilt-only homes. [same emitted code as probe 12]
probe 15 control-flow; result=MISMATCH; diff=2070; shape=93.21382842509603: Hypothesis 15: let the trade canPath failure fall through the enclosing common next_group transfer instead of using an inner goto; the original has a distinct setAction call followed by the shared loop tail. [same emitted code as probe 14]
probe 16 control-flow; result=MISMATCH; diff=2110; shape=90.01280409731113: Hypothesis 16: invert the trade-object branch to positive trade != 0 first, matching the original jne into the path block and leaving the null fully-explored fallback as fallthrough.
probe 17 liveness; result=MISMATCH; diff=2070; shape=93.21382842509603: Hypothesis 17: materialize the objectToTradeWith result into a local before the null test, then pass that local to the null fallback task; VC5 may preserve the original EDI push and stop merging water/trade fallback tails. [same emitted code as probe 15]
probe 18 control-flow; result=MISMATCH; diff=2113; shape=91.04665825977301: Hypothesis 18: direct literal task(...,0) calls only on successful water/trade target installation may naturally merge with the action-11 shared task site while removing busyOK materialization from target tails.
probe 19 liveness; result=MISMATCH; diff=2070; shape=93.21382842509603: Hypothesis 19: declare the trade path-distance local after commander lookup, following the source's observed object-then-path setup order; VC5 may alter the stack home without changing calls. [same emitted code as probe 17]
probe 20 context; result=MISMATCH; diff=2070; shape=93.21382842509603: Hypothesis 20: add the period stdlib header as a translation-unit context axis; lessons report old VC5 headers can select a distinct codegen basin even without direct API use. [same emitted code as probe 19]
probe 23 control-flow; result=MISMATCH; diff=2122; shape=93.08578745198463: Hypothesis 1: route the action-8 found reset through the shared task tail, because original bytes remove the direct task site and feed the common task epilogue with final argument 0. [same emitted code as probe 9]
probe 25 control-flow; result=MISMATCH; diff=2070; shape=93.21382842509603: Hypothesis 2: give water and trade action-8 fallback task/setInUse arms explicit next-group exits, matching original distinct call sites and direct jumps to the loop tail instead of relying on one enclosing fallthrough. [same emitted code as probe 22]
probe 27 layout; result=MISMATCH; diff=2278; shape=92.5925925925926: Hypothesis 3: recover the decompiler/PDB-supported boolean readiness local instead of int; VC5 bool lowering may restore the original EDI ready value and initial local home.
probe 29 control-flow; result=MISMATCH; diff=2203; shape=91.21019108280255: Hypothesis 4: mirror the decompiler's positive-ready source CFG, with the setAction arms first and the task as an else-if fallback; the emitted block order may recover the original ready register/home.
```
<!-- end-recovered:f984939a63f15c8b92bb -->

<!-- recovered:9da9f3271ad38708534c -->
### `3789ccb1ae1e` `src/scratch/004F4D90_taskBoats.cpp:2-64`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 004F4D90 TribeTacticalAIModule::taskBoats
// Source: taitacmd.cpp lines 5570-6037
// Attempt log:
// - baseline reconstruction: restored the period tactical-AI ownership model
//   (md at +0xF0, embedded informationAI at md+0xCEC, groups sentinel at
//   +0x9D4, and the ten ManagedArray<int> buckets) and the two ordered group
//   passes from the binary.  The remaining work is codegen/layout tuning after
//   validating this call/order surface.
// - probe 2 control-flow: inverted the first ready/task arms and used explicit
//   while(1) sentinel exits; this recovered the original loop-top null check.
// - probe 3 behavior: restored the second commander() evaluation before the
//   water fully-explored gate.
// - probe 4 behavior: restored the no-target water fallback to setAction(1).
// - probe 5 control-flow: joined completed not-in-use branches at the outer
//   loop tail instead of falling into action-10/11 checks.
// - probe 6 behavior: kept separate commander() evaluations for trade lookup
//   and the trade fully-explored gate.
// - probe 7 control-flow: sent action-10 target-null and found-reset exits to
//   the outer loop; replaced the found-reset null-object return with next-group.
// - probe 8 behavior: restored task(...,1,0) after a valid water target is
//   installed, as required by the executable's shared task tail.
// - probe 9 diagnostic shared-coordinate tail: a goto with three new float
//   locals raised the frame to 0x6C and was restored; no codegen-only variant
//   is retained.
// - ABI/layout probes: replaced the rejected padded/vf virtual scaffolding with
//   named canonical RGE/AIModule surfaces, corrected AIModule to 0xF0, and
//   declared the XYZPoint canPath overload before the integer overload.
// - behavior probe: removed a repeated water type() test; the outer 0x6B
//   branch already proves the fallback type and the original has no second
//   virtual type call there.
// - layout probe: reused the existing water/trade float slots for a shared
//   target-location tail; this matches the single original setTargetLocation
//   site without the 0x6C frame introduced by new target locals.
// - control-flow probe: found-reset action 8 falls through into later action
//   checks (the original does not jump to next_group after its task call).
// - final control-flow probe: carried busyOK into the canonical shared task
//   tail for default/target/action-11 paths and skipped setAction for unknown
//   first-pass types.  This resolves the task/action/type/target-location call
//   count gaps while keeping frame 0x60.  The best validated source remains in
//   scratch: 2070 differing bytes, 93.21% shape, 97.87% ordered calls, and
//   frame 0x60.  The remaining aggregate gap is one setAction and one setInUse
//   call.  The residual drift is concentrated in local homes and shared tails.
// - probes 1-20: direct setAction arms, positive water-count layout, direct
//   target-location expressions, and branch-local float scopes improved the
//   natural source.  Literal task-tail rewrites, extra found-path gotos, and
//   header context changes were rejected by the checker.
// - BINARY NOTE: the executable has one physical setTargetLocation call site
//   for the resource/trade target setup.  Keep those coordinates as direct
//   arguments so VC5 can share the tail without extra float reloads.
// - LIKELY INTENT: the action-8 found reset is a separate task path.  Its
//   current natural source retains the direct task call while later checks can
//   still run, but the executable uses a shared tail instead.
// - ManagedArray recovery audit, 2026-08-19: this function does not access a
//   tactical ManagedArray field or call one of its methods. The array members
//   only establish later class offsets, which the current 16-byte layout
//   already models. No shared-header migration applies to this target.
// - claim probes, 2026-08-22: routing the action-8 found reset to the shared
//   task tail worsened the result to 2122 bytes; explicit fallback exits were
//   codegen-neutral; bool ready and positive-ready CFG variants worsened to
//   2278 and 2203 bytes. Restored the clean 2070-byte source.
// - final validation, 2026-08-22: 2598 rebuilt bytes, 0x60 frame, 93.21%
//   shape, 97.87% ordered calls, 2070 differing bytes. Result remains
//   MISMATCH. Missing physical calls are one setAction and one setInUse.
```
<!-- end-recovered:9da9f3271ad38708534c -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
