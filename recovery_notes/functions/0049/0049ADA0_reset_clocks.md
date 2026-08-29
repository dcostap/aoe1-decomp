# Recovery journal: 0049ADA0 `reset_clocks`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/scr_game.cpp`.
- PDB source: `C:\msdev\work\age1_x1\scr_game.cpp`.
- Earlier recovery note: `recovery_notes/scr_game.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:b4f97c3122ba7a0d1811 -->
### `target-session` `build/target_sessions/0049ADA0_reset_clocks.json:1-17`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=6; shape=97.76536312849161: Revisit current typed reset_clocks source before natural ownership probes.
probe 2 control-flow; result=MISMATCH; diff=393; shape=97.26775956284153: Test natural while inner relation scans while preserving typed world/player ownership.
probe 3 layout; result=MISMATCH; diff=6; shape=97.76536312849161: Restore canonical typed TScreenPanel/TRIBE_Screen_Game ownership while retaining natural timing reset. [same emitted code as probe 1]
probe 4 abi; result=MISMATCH; diff=6; shape=97.76536312849161: Use the binary-backed polymorphic RGE_Player surface without changing typed reset behavior. [same emitted code as probe 3]
probe 5 layout; result=MISMATCH; diff=6; shape=97.76536312849161: Model proven TRIBE_Player ownership for the two timer fields at +840/+844. [same emitted code as probe 4]
probe 6 layout; result=MISMATCH; diff=6; shape=97.76536312849161: Expose the proven world map and typed player-array slots without changing reset timing codegen. [same emitted code as probe 5]
probe 8 control-flow; result=MISMATCH; diff=38; shape=96.64804469273743: Replace inner break with an else increment so only the non-match path advances; test whether VC5 emits the oracle's JL-body/JMP-exit backedge.
probe 10 control-flow; result=MISMATCH; diff=6; shape=97.76536312849161: Encode the inner scan as an explicit infinite loop with continue on other_player < player_id and break otherwise; target branch polarity matches this CFG if VC5 retains it. [same emitted code as probe 7]
probe 12 control-flow; result=MISMATCH; diff=6; shape=97.76536312849161: Use a for(;;) inner scan with explicit continue when other_player remains below player_id and break otherwise; test a non-do/while loop basin for the JL-body/JMP-exit frontier. [same emitted code as probe 10]
probe 14 control-flow; result=MISMATCH; diff=8; shape=97.76536312849161: Reverse the natural signed loop bound operands to player_id > other_player; test whether VC5 selects the oracle JL-body/JMP-exit encoding without changing control flow.
probe 16 control-flow; result=MISMATCH; diff=6; shape=97.76536312849161: Split the inner relation scan into an explicit match branch and non-match else with an update-side >= bound break; test whether source branch ownership yields the oracle orientation. [same emitted code as probe 12]
probe 18 layout; result=MISMATCH; diff=554; shape=74.86910994764398: Narrow both proven signed relation-scan counters to short while retaining int promotion at calls; test whether local width selects the oracle branch basin.
probe 20 control-flow; result=MISMATCH; diff=6; shape=97.76536312849161: Move the inner counter increment into the do/while condition (++other_player < player_id), a natural update-placement form that may choose the target backedge polarity. [same emitted code as probe 16]
probe 22 control-flow; result=MISMATCH; diff=507; shape=88.64864864864865: Set the relation flag first, then test countdown in a separate break statement; test whether VC5 preserves the target's direct flag-store exit and JL backedge.
probe 24 control-flow; result=MISMATCH; diff=6; shape=97.76536312849161: Expand the inner post-increment to other_player = other_player + 1; test an update-expression codegen basin for the target branch polarity. [same emitted code as probe 20]
probe 26 control-flow; result=MISMATCH; diff=6; shape=97.76536312849161: Use compound assignment other_player += 1 in both relation scans; verify update spelling does not control the six-byte branch frontier. [same emitted code as probe 24]
probe 29 layout; result=MISMATCH; diff=6; shape=97.76536312849161: Use the PDB-backed long countdown_timer and long* helper output parameter; test canonical signed 32-bit declaration and branch codegen.
```
<!-- end-recovered:b4f97c3122ba7a0d1811 -->

<!-- recovered:0b38041fc50909398598 -->
### `e8673544eb96` `src/scratch/0049ADA0_reset_clocks.cpp:1-44`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0049ADA0 reset_clocks (594B)
// scr_game.cpp:4192-4265
//
// Attempt log (sa-b5a80f3f-r1-match0049ADA0):
// - initial placeholder was unrelated to the executable; the first clean
//   reconstruction below follows the typed TRIBE_World/player ownership,
//   byte-offset player cursor, and clock-selection loops proved by the asm.
// - swapping the clock/player local declaration order, using post-increment
//   clock receivers, and splitting the allied guard aligned frame/size/CFG;
//   the clean source then differed only in the two inner-loop branch pairs
//   and the outer induction tail.
// - top-tested while/for forms, reversed bound operands, and explicit
//   infinite-loop break/continue spellings either broadened the drift or
//   emitted the same branch basin; the ordinary do/while remains the
//   period-plausible source.
// - reversing the ordinary outer updates to `++player_id; player_offset += 4`
//   recovered the target's pointer-store/world-count scheduling, leaving a
//   six-byte codegen gap: both inner scans use `jge exit; jmp body` instead of
//   the oracle's `jl body; jmp exit`.
// - zero-based/preincrement inner counters were rolled back (broad drift).
// - sharing countdown/relation locals across the outer iteration was a codegen duplicate; scoped locals remain the clearer period-plausible source.
// - moving each inner increment into the do/while condition was a codegen duplicate; the paired branch gap remains.
// - resumed after the host crash, restored the clean pinned source, and
//   reproduced the 594-byte/frame-0x10 validation. No new natural source lead
//   remains; the unresolved bytes are the two inner-loop branch pairs.
// - this session re-tested for-header, while, explicit continue/break, post-
//   increment, inverted-predicate, labeled-backedge, and <=-bound spellings;
//   all either broadened the function or canonicalized to the same six-byte
//   gap. The clean do/while source remains the best reconstruction.
// - this session reconfirmed the clean baseline, then tested scoped and
//   predeclared-counter for headers; both changed register ownership and
//   broadened the diff. A four-case loop-shape lab found no new invariant-
//   eligible codegen group.
// - a four-case predicate-shape lab (direct, negated-or, nested, and
//   positive-else) collapsed to the same six-byte branch gap. The final
//   predeclared-counter for probe was a duplicate of the scoped-for basin;
//   the clean do/while remains authoritative.
// - this revisit restored the canonical TScreenPanel/TRIBE_Screen_Game
//   ownership and the proven polymorphic RGE_Player/TRIBE_Player timing
//   fields. Codegen stayed unchanged at 594 bytes with the same six-byte
//   inner-loop branch gap.
// - natural while scans were retested for both relation loops. They added
//   eight bytes and broadened the diff, so the typed do/while reset remains
//   authoritative.
```
<!-- end-recovered:0b38041fc50909398598 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
