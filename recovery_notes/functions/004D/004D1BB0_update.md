# Recovery journal: 004D1BB0 `update`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/tact_rep.cpp`.
- PDB source: `C:\msdev\work\age1_x1\tact_rep.cpp`.
- Earlier recovery note: `recovery_notes/004D1BB0_update.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:98ce45aa2db2358cd1b5 -->
### `d050eea3c` `src/tact_rep.cpp:115-116`

Mapping: `ambiguous`. next mapped function definition is update at old line 203.

```text
// PDB lines 121-221; VA 004D18B0.
// Exact under the module's period /O2 /Oy /GX flags.
```
<!-- end-recovered:98ce45aa2db2358cd1b5 -->

<!-- recovered:59e4ba700738ee73922e -->
### `6a2aef2e2` `src/tact_rep.cpp:187-188`

Mapping: `strong`. comment lies after mapped function update at old line 185.

```text
// Its natural calls, size, frame, and state routing match, but VC5 colors
// the state-4 action-list vtable load in EAX instead of the shipped EDX.
```
<!-- end-recovered:59e4ba700738ee73922e -->

<!-- recovered:1625a99208686487d719 -->
### `target-session` `build/target_sessions/004D1BB0_update.json:1-50`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=35; shape=96.37462235649546: Current clean source reconstruction baseline before focused revisit; establish exactness and mismatch regions.
probe 2 variant; result=MISMATCH; diff=35; shape=96.37462235649546: Hypothesis 1: case-9 timer local preserves the decremented value for the threshold test, matching original compare-before-store order.
probe 4 variant; result=MISMATCH; diff=35; shape=96.37462235649546: Hypothesis 2: put the timer compound assignment inside the threshold predicate, matching the source temporary implied by original compare-before-store. [same emitted code as probe 1]
probe 6 liveness; result=MISMATCH; diff=35; shape=96.37462235649546: Hypothesis 3: make the decremented timer a function-scope local, testing whether its longer lifetime reproduces the original x87 compare-before-store schedule. [same emitted code as probe 2]
probe 8 control-flow; result=MISMATCH; diff=35; shape=96.37462235649546: Hypothesis 4: invert state-9 threshold to an early break guard; this may select the original fcom, field-store, then status-test sequence. [same emitted code as probe 4]
probe 10 context; result=MISMATCH; diff=27; shape=96.97885196374622: Hypothesis 5: source the state-9 zero threshold as a float literal, following tact_rep decompiler evidence and exact 004C3C70 fcom/fstp donor shape.
probe 11 variant; result=MISMATCH; diff=799; shape=91.23867069486406: Hypothesis 6: parenthesize world delta times master rate, testing whether x87 multiplication order follows the original task*world*master sequence.
probe 13 liveness; result=MISMATCH; diff=27; shape=96.97885196374622: Hypothesis 7: materialize the three-factor repair rate in a named local before heal, testing whether address-taken call setup restores original operand/push order.
probe 15 liveness; result=MISMATCH; diff=27; shape=96.97885196374622: Hypothesis 8: cache sub_actions in a case-4 local before update, testing whether a named receiver changes the second vtable register from EAX to original EDX. [same emitted code as probe 13]
probe 17 liveness; result=MISMATCH; diff=917; shape=80.20050125313283: Hypothesis 9: save the state-4 sub-action update byte in a local before dispatch, testing result liveness and vtable-register coloring.
probe 19 abi; result=MISMATCH; diff=27; shape=96.97885196374622: Hypothesis 10: widen the state-4 update result to int at switch input, testing ABI/result-width effects on the second virtual dispatch. [same emitted code as probe 15]
probe 21 liveness; result=MISMATCH; diff=220; shape=96.08433734939759: Hypothesis 11: reuse the decompiler-supported target pointer local across state-7 null, coordinates, distance, heal, and notification paths.
probe 23 liveness; result=MISMATCH; diff=27; shape=96.97885196374622: Hypothesis 12: load a short-lived heal receiver alias immediately before the rate call, testing receiver liveness without changing coordinate checks. [same emitted code as probe 19]
probe 25 context; result=MISMATCH; diff=35; shape=96.37462235649546: Hypothesis 13: use a TU-local const zero symbol for the timer threshold, testing donor-supported constant-pool context versus the plain literal.
probe 27 liveness; result=MISMATCH; diff=41; shape=96.37462235649546: Hypothesis 14: cache world time delta in a case-9 local before timer subtraction, testing source load lifetime and timer FPU scheduling.
probe 29 liveness; result=MISMATCH; diff=917; shape=80.20050125313283: Hypothesis 16: keep the case-4 update byte in a function-scope local, avoiding nested scope while extending result liveness across dispatch.
probe 31 abi; result=MISMATCH; diff=27; shape=96.97885196374622: Hypothesis 17: declare action-list update as int and narrow each switch input explicitly, testing return-width ABI while preserving observed byte masking.
probe 33 control-flow; result=MISMATCH; diff=27; shape=96.97885196374622: Hypothesis 18: make state-10 dispatch explicitly mask the action-list byte, following decompiler switch((value & 0xff)) and testing cross-arm register allocation. [same emitted code as probe 23]
probe 35 variant; result=MISMATCH; diff=27; shape=96.97885196374622: Hypothesis 19: expand timer compound assignment into an explicit field subtraction assignment, testing assignment lowering while retaining the literal zero threshold. [same emitted code as probe 10]
probe 37 control-flow; result=MISMATCH; diff=27; shape=96.97885196374622: Hypothesis 20: make the proven state-4-to-state-13 shared tail explicit with a local label, testing whether VC5 lays out the second jump-table arm with original EDX. [same emitted code as probe 31]
probe 40 liveness; result=MISMATCH; diff=16; shape=98.18731117824774: Hypothesis 21: fetch owner world delta and master work rate into separate locals before multiplying with task rate, mirroring original owner-first load order.
probe 41 liveness; result=MISMATCH; diff=799; shape=92.14501510574019: Hypothesis 22: fetch task work rate into a local before owner delta and master rate, testing whether x87 starts with the original task-rate load.
probe 44 liveness; result=MISMATCH; diff=479; shape=83.50785340314137: Hypothesis 24: build repair_rate by left-associative compound multiplication after owner/master locals, matching original task*world then master x87 order.
probe 46 liveness; result=MISMATCH; diff=16; shape=98.18731117824774: Hypothesis 25: name owner and master object pointers before fetching their rates, testing whether pointer lifetime recovers original task/world/master scheduling.
probe 48 liveness; result=MISMATCH; diff=16; shape=98.18731117824774: Hypothesis 26: reverse the first commutative source operands to world_delta * task_rate * master_rate, testing VC5's observed reverse scheduling against original fld task/fmul world/fmul master bytes. [same emitted code as probe 43]
probe 49 liveness; result=MISMATCH; diff=16; shape=98.18731117824774: Hypothesis 27: permute all three rate operands to master*world*task, testing whether VC5 reverses the source tree into original FPU order. [same emitted code as probe 48]
probe 51 liveness; result=MISMATCH; diff=479; shape=83.50785340314137: Hypothesis 28: mutate the existing world_delta local with task rate then master rate, testing natural accumulator codegen without a new repair-rate local.
probe 53 liveness; result=MISMATCH; diff=28; shape=96.97885196374622: Hypothesis 29: keep only master_rate as a local while leaving task/world direct, testing whether one cached factor gives original owner-first and FPU order.
probe 55 abi; result=MISMATCH; diff=16; shape=98.18731117824774: Hypothesis 30: use the exact donor spelling unsigned char update(void) for action-list ABI, testing declaration-form effects on state-4 vtable register selection.
probe 57 control-flow; result=MISMATCH; diff=680; shape=85.48812664907652: Hypothesis 31: express state-4 dispatch as switch((update() - 1)) with zero-based cases, mirroring the binary's explicit subtract lowering and testing vtable register coloring.
probe 59 liveness; result=MISMATCH; diff=16; shape=98.18731117824774: Hypothesis 32: move owner-world and master-rate locals to function scope, testing whether declaration lifetime changes repair-call FPU scheduling. [same emitted code as probe 49]
probe 64 liveness; result=MISMATCH; diff=799; shape=92.14501510574019: Hypothesis 33: materialize task->work_rate as a third local after owner-world and master-rate locals, testing whether VC5 preserves the original task-first x87 load without changing the pointer declaration order. [same emitted code as probe 41]
probe 66 context; result=MISMATCH; diff=798; shape=91.54078549848943: Hypothesis 34: mark the three proven work-rate/time fields volatile and restore the direct task*world*master expression, testing whether required source read order recovers the original x87 sequence.
probe 68 liveness; result=MISMATCH; diff=27; shape=96.97885196374622: Hypothesis 35: cache task, owner, and master object pointers, then use task*owner-world*master fields, testing whether a natural three-object graph reproduces the original field-load and x87 order.
probe 70 liveness; result=MISMATCH; diff=799; shape=92.14501510574019: Hypothesis 36: keep task work rate in a register-qualified local before the owner and master locals, testing whether an explicit period register hint preserves frame and original task-first x87 scheduling. [same emitted code as probe 64]
probe 72 abi; result=MISMATCH; diff=16; shape=98.18731117824774: Hypothesis 37: model the proven polymorphic RGE_Master_Action_Object inheritance surface with a vptr and adjusted padding at unchanged work_rate offset +E4, testing whether canonical type identity changes the rate basin.
probe 73 liveness; result=MISMATCH; diff=16; shape=98.18731117824774: Hypothesis 38: reverse the declaration order of the independent master-rate and world-delta locals while preserving task*world*master semantics, testing VC5 declaration/liveness scheduling. [same emitted code as probe 72]
probe 74 control-flow; result=MISMATCH; diff=69; shape=95.7703927492447: Hypothesis 39: place the immediate state-12 arm after the state-4 nested switch and before state-13, testing PDB-backed handler declaration order as a register-color axis.
probe 77 baseline; result=MISMATCH; diff=16; shape=98.18731117824774: Baseline: validate the pinned canonical reconstruction before grouped-source recovery. [same emitted code as probe 76]
probe 78 behavior; result=MISMATCH; diff=27; shape=96.97885196374622: Restore the direct task, owner-world, and master repair-rate expression to preserve fault order and concurrent member rereads.
probe 79 liveness; result=MISMATCH; diff=799; shape=91.23867069486406: Group the direct world and master factors while keeping all member reads direct; test whether VC5 retains task-first fault order.
probe 81 context; result=MISMATCH; diff=16; shape=98.18731117824774: Compile update against a dedicated tact_rep.cpp declaration surface in canonical master, object, world, player, and action order.
probe 82 liveness; result=MISMATCH; diff=2; shape=98.79154078549848: Use a direct left-associated repair-rate expression with an explicit float result for its first product; keep fault order and all owner reads direct.
probe 83 liveness; result=MISMATCH; diff=2; shape=98.79154078549848: Name the state-4 sub-action list inside its case before the virtual update; test its local receiver lifetime against the required EDX vtable load.
probe 84 liveness; result=MISMATCH; diff=2; shape=98.79154078549848: Use a period register hint on the short-lived state-4 action-list receiver; test the remaining vtable-register recolor without changing calls or ownership. [same emitted code as probe 83]
probe 86 liveness; result=MISMATCH; diff=2; shape=98.79154078549848: Natural reference alias for the state-4 action list; test real receiver-reference lowering for the original EDX vtable load without register hints or behavior changes.
probe 88 liveness; result=MISMATCH; diff=2; shape=98.79154078549848: Reverse the two real pointer declaration order without changing reads, calls, action flow, or x87 expressions; test whether VC5 local coloring naturally selects EDX at state 4. [same emitted code as probe 85]
probe 92 abi; result=MISMATCH; diff=2; shape=98.79154078549848: Added proven TRIBE_Action_Repair byte at +40 from exact sibling context; direct fresh checker stayed at 2 bytes and exact calls/boundary/owner.
probe 93 liveness; result=MISMATCH; diff=2; shape=98.79154078549848: Scoped the real state-13 target alias to its case; direct fresh checker stayed at 2 bytes and exact neighboring anchors.
probe 95 liveness; result=MISMATCH; diff=2; shape=98.79154078549848: Reuse the existing proven target pointer local for state-13 distance, preserving the target reread and fault order; test natural local reuse for the EDX color. [same emitted code as probe 94]
```
<!-- end-recovered:1625a99208686487d719 -->

<!-- recovered:cf532264f0ac4fdba900 -->
### `499fa05c03af` `src/scratch/004D1BB0_update.cpp:1-56`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004D1BB0 TRIBE_Action_Repair::update
// Attempt log:
// baseline: reconstructed the inherited action fields, object/world/player ownership,
// nested state/sub-action dispatch, and repair-distance paths from tact_rep.cpp evidence.
// ABI probe: replaced decompiler-shaped object_delta/command shims with the period
// RGE_Static_Object distance_to_object/heal/notify, RGE_Action_Object turn_towards,
// RGE_Player isAlly, and RGE_Base_Game notification surfaces; calls became 29/29.
// control-flow probe: corrected the state table to the binary's source-order handlers
// 10, 12, 4, 13, 6, 7, 9, 1, 11; state 4 shares the state-13 distance tail.
// liveness probe: retained the nested target recheck, one heal result for both ==1/==2
// tests, global-before-threshold FPU comparisons, and direct three-factor repair rate.
// duplicate probes: state-4 goto versus ordinary inner-switch fall-through and a
// scoped sub-action pointer/result local emitted the same or a worse basin; rolled back.
// final best: a named state-13 target alias restores the original target/object load
// order and leaves 35 positional bytes (96.37% shape, exact call/size/frame parity).
// timer assignment-in-condition probe: the natural x87 source form emitted the
// same bytes as the separate decrement statement; restored the cleaner form.
// focused follow-up: reversed the timer predicate, tested state-4 case-group order,
// compound-case scope, and an int sub-action result; the first worsened size, the
// latter three were codegen duplicates or broad negative results and were restored.
// ABI-width cast and a nine-variant state-4/timer lab produced no EDX vtable match;
// the direct typed form remains the clean source reconstruction.
// revisit pass: replacing the state-9 DAT_00575278 reference with the proven zero
// literal recovered the original fcom/fstp order and reduced the masked diff 35->27.
// Owner-first world_delta and master_rate locals recovered 12 of the 14 repair-rate
// drift bytes and reduced the diff 27->16. More than 30 distinct follow-up probes
// covered timer scope/predicate forms, state-4 dispatch forms, ABI spellings, and
// rate-local layouts; no further source form changed the best emitted code.
// remaining localized drift: state-4 vtable-register coloring (two bytes) and
// repair-rate FPU operand/push scheduling (14 bytes); all 19 relocations are masked.
// left in scratch after the sustained revisit; no inline asm or custom flags.
// Type/layout revisit: the ground-truth master-action hierarchy is polymorphic;
// restoring a local vptr surface at unchanged work_rate offset +E4 emitted the
// same 16-byte result. Reversed local declaration order and handler order were
// also tested; the former duplicated codegen and the latter worsened call order.
// Accepted-drift audit: do not promote the repair-rate hunk. The executable
// reads task->work_rate before owner->world and its time delta. The rebuild
// dereferences owner->world first and reverses the first x87 multiply operands.
// This changes pointer-fault order, concurrent rereads, and NaN payload behavior
// before the value is passed to the virtual heal call.
// TU context audit: same-module tact_rep.cpp owners were tested in address order.
// No tested authentic nearest-one or cumulative multi-owner prefix compiled
// with this standalone class surface. No context change is validated.
// Direct left-product float grouping restored the executable's task, world,
// then master x87 order without caching any owner field. It reduced drift to
// the two state-4 vtable-register bytes. A canonical tact_rep declaration
// surface and grouped prior functions did not change those bytes.
// Exact-finish pass (sa-e60ccc0c): fresh probes kept 29 ordered calls, 828-byte
// size, three saved registers, and the rebuilt update owner symbol.
// A reference receiver for state 4, reversed pointer declarations, and a
// case-scoped state-13 target alias all emitted the same two-byte drift.
// Reusing the proven check-target local for state 13 also emitted the same drift.
// The proven derived byte at +40 also emitted the same two-byte drift.
// Restore the clean source after each probe. Do not use register hints.
// The remaining bytes are the state-4 action-list vtable load: EDX is original;
// EAX is rebuilt. No natural source change found in this pass selects EDX.
```
<!-- end-recovered:cf532264f0ac4fdba900 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
