# Recovery journal: 00428DA0 `EvaluateSystemMessage`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/com_hand.cpp`.
- PDB source: `C:\msdev\work\age1_x1\Com_hand.cpp`.
- Earlier recovery note: `recovery_notes/com_hand_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:b6c1f0fd875e5d51540f -->
### `target-session` `build/target_sessions/00428DA0_EvaluateSystemMessage.json:1-41`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=1969; shape=95.32846715328468: Baseline existing natural reconstruction: 2235-byte frame/call count exact, 78.59% exact-block, default falls inline and first CFG shift at dispatch.
probe 2 control-flow; result=MISMATCH; diff=1969; shape=95.32846715328468: Hypothesis 1: route switch default through a named end label, to prevent VC5 placing unknown handler inline after low dispatch.
probe 4 control-flow; result=MISMATCH; diff=1979; shape=54.32276657060519: Hypothesis 2: explicitly split the low <=0x21 chain from the high switch with goto labels; target original cmp/sub low dispatch and late default/add-delete blocks.
probe 6 control-flow; result=MISMATCH; diff=2012; shape=91.84861717612809: Hypothesis 3: natural outer low-range if (<0x22) containing low switch and else high switch, with shared late add/delete and unknown labels.
probe 7 control-flow; result=MISMATCH; diff=1983; shape=94.73684210526316: Hypothesis 4: preserve outer low/high split but use fall-through default blocks, explicit returns, and place unknown before shared add/delete to stop epilogue tail merge.
probe 8 control-flow; result=MISMATCH; diff=1981; shape=94.88304093567251: Hypothesis 5: spell low-range test as <=0x21 rather than <0x22 to recover original cmp 21 / ja high encoding.
probe 9 control-flow; result=MISMATCH; diff=1957; shape=95.46120058565154: Hypothesis 6: replace low switch with explicit nested if chain while retaining natural outer <=0x21/else high switch; eliminate VC5 low jump-table lowering.
probe 10 control-flow; result=MISMATCH; diff=1954; shape=76.42752562225476: Hypothesis 7 retry after syntax repair: low tests 3 then 5, with physically swapped natural blocks and outer high switch.
probe 12 control-flow; result=MISMATCH; diff=1957; shape=95.46120058565154: Hypothesis 8: restore best outer low/high split with 5-first low if-chain and shared fall-through unknown/add handlers. [same emitted code as probe 9]
probe 13 control-flow; result=MISMATCH; diff=1954; shape=76.42752562225476: Hypothesis 9 retry after syntax repair: explicit low dispatch labels before high switch, with handler order destroy/create preserved.
probe 14 control-flow; result=MISMATCH; diff=1969; shape=95.32846715328468: Hypothesis 10 retry after syntax repair: braced switch default with explicit return.
probe 15 control-flow; result=MISMATCH; diff=1994; shape=74.6705710102489: Hypothesis 11: order low tests 21/3/5/7 but inline case5 body before a forward create_player label; this should preserve exact dispatcher and original case5-then-case3 physical layout.
probe 16 control-flow; result=MISMATCH; diff=6; shape=98.97360703812316: Hypothesis 12: duplicate the identical case-7 and case-0x105 source bodies, testing whether VC5 tail-merges them while moving default out of the low-chain fallthrough.
probe 17 liveness; result=MISMATCH; diff=2; shape=99.41348973607037: Hypothesis 13: reverse the two independent options-to-handler assignments, testing VC5's reverse scheduling to recover original displacement byte order.
probe 18 liveness; result=MISMATCH; diff=1639; shape=99.26900584795321: Hypothesis 14: remove the p3=newid assignment, testing whether VC5 then uses the original parameter home at both remaining mismatch stores.
probe 19 liveness; result=MISMATCH; diff=2; shape=99.41348973607037: Hypothesis 15: assign p3 from a direct message-field reread instead of the named newid local, testing parameter-home selection without changing value.
probe 20 layout; result=MISMATCH; diff=2; shape=99.41348973607037: Hypothesis 16: narrow the local newid spelling from unsigned long to unsigned int, testing signedness/type-driven parameter-home allocation at the two remaining stores. [same emitted code as probe 19]
probe 21 abi; result=MISMATCH; diff=2; shape=99.41348973607037: Hypothesis 17: use p4, not p3, for the observed message ID reuse; p4's home is four bytes later and may explain both remaining stack displacement bytes. [same emitted code as probe 20]
probe 22 layout; result=MISMATCH; diff=2; shape=99.41348973607037: Hypothesis 18: declare the loop index before newid in CREATE, testing declaration order as the remaining parameter-home color axis. [same emitted code as probe 17]
probe 23 liveness; result=MISMATCH; diff=2; shape=99.41348973607037: Hypothesis 19: join newid declaration and first field load in an initializer, testing VC5 declaration/initialization-site effects on the two parameter-home offsets. [same emitted code as probe 22]
probe 24 liveness; result=MISMATCH; diff=2; shape=99.41348973607037: Hypothesis 20: feed the first NEW PLR log from the assigned p3 parameter instead of newid, testing whether the compiler binds the spill to the original parameter home. [same emitted code as probe 23]
probe 25 liveness; result=MISMATCH; diff=2; shape=99.41348973607037: Hypothesis 21: combine p3 and newid assignment in one right-associative statement, testing whether VC5 records the value in the later original parameter home. [same emitted code as probe 24]
probe 26 variant; result=MISMATCH; diff=2; shape=99.41348973607037: variant lab build\variant_lab\00428DA0_EvaluateSystemMessage\20260817_161109: 16 variants, 16 invariant-eligible, 0 exact
probe 27 control-flow; result=MISMATCH; diff=2; shape=99.41348973607037: Hypothesis 22: reverse source order of duplicate case 7 and case 0x105 bodies, testing shared-tail ordering as the remaining home-color control. [same emitted code as probe 26]
probe 28 context; result=MISMATCH; diff=2; shape=99.41348973607037: Hypothesis 23: add one unused same-width local in CREATE, testing whether VC5 reassigns the reused parameter home without changing semantics. [same emitted code as probe 21]
probe 29 liveness; result=MISMATCH; diff=2; shape=99.41348973607037: Hypothesis 24: bind p3 through a local reference alias, testing whether a named reference preserves the original parameter home while retaining natural value flow. [same emitted code as probe 28]
probe 30 liveness; result=MISMATCH; diff=2; shape=99.41348973607037: Hypothesis 25: store the stable newid local directly into dcoID while retaining the p3 alias assignment, testing whether this removes the second parameter-home spill. [same emitted code as probe 29]
probe 31 liveness; result=MISMATCH; diff=2; shape=99.41348973607037: Hypothesis 26: delay the i declaration until the player-slot scan, testing declaration scope/order as a home-color cause. [same emitted code as probe 27]
probe 32 liveness; result=MATCH; diff=0; shape=99.70674486803519: Hypothesis 27: load the message ID into p3 first, then copy p3 into newid, testing assignment order for the original parameter-home choice.
probe 33 liveness; result=MATCH; diff=0; shape=99.70674486803519: Exact-finish reversion A: move i back to its original early declaration while retaining the decisive p3-first/newid assignment. [same emitted code as probe 32]
probe 34 liveness; result=MISMATCH; diff=4; shape=99.26686217008798: Exact-finish reversion B: restore original assignment order while retaining p3-first and duplicate cases; expected to isolate the four options displacement bytes.
probe 35 control-flow; result=MISMATCH; diff=1969; shape=96.05839416058394: Exact-finish reversion C: collapse duplicate 7/0x105 bodies back to one shared labeled body, testing whether duplication is required for exact block layout.
probe 38 other; result=MATCH; diff=0; shape=99.70674486803519: Policy cleanup H1b: fix typed payload pointer arithmetic without changing the typed packet model.
probe 40 layout; result=MATCH; diff=0; shape=99.70674486803519: Policy cleanup H2: rename decompiler parameters and serial cursor, then use one typed DirectPlay packet union pointer instead of repeated casts.
probe 41 layout; result=MATCH; diff=0; shape=99.70674486803519: Policy cleanup H3: replace the decompiler gap-only handler overlay with the canonical TCommunications_Handler field ownership through PlayerOptions; fix TBuff to its proven 257-byte field and PlayerStopTurn to the canonical 10-entry array. [same emitted code as probe 40]
probe 42 layout; result=MATCH; diff=0; shape=99.70674486803519: Policy cleanup H4: replace the decompiler cross-member serial cursor and +15 access with canonical indexed PlayerHighSerialNumber and PlayerOptions.dcoID arrays.
probe 43 behavior; result=MATCH; diff=0; shape=99.70674486803519: Policy cleanup H5: replace DirectPlay message-type magic numbers with named constants from the repository DPLAY.H evidence.
probe 46 layout; result=MISMATCH; diff=497; shape=98.53372434017595: Payload cleanup H1: model the sender's fixed COMMPLAYEROPTIONS record and variable game_options trailer as a named COMM_SHARED_DATA structure; replace every receiver +0x1D0 access with sizeof(player_options) or the named trailer field.
probe 47 layout; result=MISMATCH; diff=497; shape=98.53372434017595: Payload cleanup H2: place the typed COMM_SHARED_DATA payload after the existing DirectPlay union, using sizeof(player_options) and the named game_options field. [same emitted code as probe 46]
probe 48 layout; result=MATCH; diff=0; shape=99.70674486803519: Payload cleanup H3: bind the DirectPlay data pointer to a typed COMM_SHARED_DATA union member, while retaining the exact fixed-record constants to isolate pointer typing from size-expression effects.
probe 49 layout; result=MATCH; diff=0; shape=99.70674486803519: Payload cleanup H4: replace all fixed shared-record byte constants with sizeof of the named COMM_SHARED_DATA::player_options field. [same emitted code as probe 48]
```
<!-- end-recovered:b6c1f0fd875e5d51540f -->

<!-- recovered:a3f8047873294970f16b -->
### `b6e159352e2d` `src/scratch/00428DA0_EvaluateSystemMessage.cpp:1-45`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 00428DA0 TCommunications_Handler::EvaluateSystemMessage (Com_hand.cpp:2411-2771)
// __thiscall (unsigned long p1, char* p2, unsigned long p3, unsigned long p4) -> void, ret 10h
// DPLAY system-message dispatcher: switch on *(unsigned long*)p2 with low-value sub-chain
// (3/5/7) + byte-table jump dispatch for 0x31..0x109; default logs "COMM:Unknown".
//
// Attempt log:
// - Baseline: natural switch reconstruction; local class stub modeled on exact donors
//   00428B10 (DropDeadPlayer), 0042D2D0 (InitPlayerInformation), 0042EA10 (Kick),
//   00429A90 (SendIResignMsg). Size/frame/call-count matched from the start (2235/0xC/75).
// - case5 scan: single-variable `unsigned short i` loop produced 16-bit compares +
//   and-masking; original is 32-bit signed jg/jle with a cold `mov esi,eax; jmp` found
//   block. Fixed with the UpdatePlayerInformation (0042D120) idiom: separate `int p`/
//   `int high` induction locals + `unsigned int i` result, `i = p; goto found2`, and
//   `i = 0` at the join -> exact cold found-block topology. Result check is `i <= 0`
//   (unsigned jbe) per original bytes.
// - Switch expression: using a `msg` local kept the value in callee-saved edi; the
//   original reloads [ebx] after the Log call and keeps it in volatile ecx. Dropped
//   the local: Log arg + switch expr + default all use *(unsigned long*)p2 directly.
// - case3: goto-found empty-slot scan (Humanity[i]==0) matches the 32-bit guard/bottom;
//   InitPlayerInformation and GIP/GIP2 args re-read *(unsigned long*)(p2+8) per original.
//   `p3 = newid` models the observed param-slot reuse (original spills newid to the
//   param_3 slot; rebuilt picks the dead param_2 slot -> 4-byte displacement diff).
// - case0x102 serial loops: pointer-based (`unsigned int* p = &PlayerHighSerialNumber[1]`,
//   dcoID via *(p+15)) with `unsigned int i` + ser/p declared inside the guard; matches
//   the original 16-bit guard + 32-bit bottom compare + [edi+3Ch] access exactly.
// - Case order: physical handler order follows source order for the table cases
//   (0x109 early, 0x101/0x31 swapped, 0x107 before 0x104) - reordering to the original's
//   physical order improved edit diff 855->593 and block coverage to ~79%.
// - REMAINING GAP: VC5 places the default handler inline right after the sub-chain
//   (rebuilt `sub eax,2; je case7` + inline default) instead of at the function end
//   (original `jne near default; jmp case7`). Tried default-case, post-switch
//   fall-through, and case reordering - all emit the inline default (stable basin).
//   Several Log sites differ by 1 byte from `mov eax,[L]` (A1) vs `mov ecx,[L]` (8B 0D)
//   register choice. Best: 1969 pos diff (88.1%), edit 593 (13.3%), shape 95.3%,
//   exact-block 78.6%, calls 75/75.
// - Left in scratch: unresolved but structurally strong; next lead is steering the
//   default block to the end (block-layout probe) and matching the L-load register.
// - ABI probe: the original 00436610 target is the static class member
//   TDebuggingLog::Log(TDebuggingLog*, const char*, ...), not a free helper
//   or non-static member. The class tag produces the original PAV1 binding.
//   The corrected relocation is exact, but whole-function bytes are unchanged.
// - ABI probe: inventory marks CalculatePlayerRange and ClearRXTXForPlayer as
//   protected (IAEH/IAEX). Updated the local declarations; emitted bytes and
//   positional metrics are unchanged because the remaining call-map gaps are
//   caused by the shifted cold default block, not these relocation bindings.
```
<!-- end-recovered:a3f8047873294970f16b -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
