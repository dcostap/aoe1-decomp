# Worker Scoreboard

Last updated: 2026-04-18
Orchestrator: FrostTiger

## Scoring

- `+3` exact-match task completed and validated by orchestrator
- `+1` useful blocked report with clear evidence / validation
- `+1` needs-review result that still contains useful progress
- `-1` missed acknowledgement / unresponsive after direct follow-up
- `-2` misbehavior or ignoring explicit orchestration instructions

## Current task queue

| Worker | Current task | Status |
|---|---|---|
| HarborWave | — | worker offline; late invalid draft cleaned from `agent2` |
| KindTrail | — | worker offline; late non-matching draft cleaned from `agent3` |
| CobaltHarrier | CT-7: `0045E970_doTrivialMove` | exact size again, but the small prolog regressed to a larger frame |
| CalmTrail | CT-8: `004ABCD0_action` | active medium-sized `scr_sed.cpp` task in agent2; blocker is reproducing the frameless/float-heavy entry body before first compile |

## Tally

| Worker | Assigned | Matched | Blocked | Needs review | Misbehavior | Missed ack | Score | Last task | Last note |
|---|---:|---:|---:|---:|---:|---:|---:|---|---|
| HarborWave | 1 | 0 | 1 | 1 | 0 | 1 | 1 | HW-1 | Worker went offline; late draft in agent2 failed to compile under VC5 syntax/layout rules and was cleaned |
| KindTrail | 1 | 0 | 1 | 1 | 0 | 1 | 0 | KT-1 | Worker went offline; late draft in agent3 compiled but mismatched from offset 0 and was cleaned |
| CobaltHarrier | 2 | 1 | 1 | 1 | 0 | 1 | 3 | CH-1 | CH-1 stalled with an unchanged mismatching draft after repeated follow-ups; reservation released and agent3 reset clean |

## Notes

- New session started from a clean main tree and clean worker worktrees.
- Default policy remains exact-match-first with default flags first; use per-function `.rsp` only if default flags fail and report that explicitly.
- No further tasks are queued yet beyond the live assignments.
- CT-2 was assigned after the load_node vtable-slot evidence was confirmed from the class dump (slot 0x2C / vt[11]).
- CT-2 currently reports a first-byte prolog mismatch; the latest worker note says the rebuilt prolog begins with `64a1000000006aff6800000000508b44...` while the original begins `64a1000000006aff6876c95500508b44...`.
- CalmTrail later narrowed the rebuilt entry to `56 57 84 c0 8b f9 75 13 8b4c2408 64890d...`; one final micro-probe was requested before parking.
- The latest CT-2 probe moved the first mismatch deeper to offset 30, with original window `00000025ff0000005783e8008bf90f84` and rebuilt window `00000025ff000000565783e8008bf90f`.
- CT-2 was then deemed park-worthy as prolog/EH shape drift and the worker was instructed to move it into `src/almost_matched` with a structured header.
- CT-4 was paused after an offset-0 prolog drift report on `00404A40_first_in_stack` and then superseded by a medium-sized move_obj task.
- CT-3 was assigned to CobaltHarrier as a backup attempt on the animated-sprite constructor/EH scaffold while HW-1 remains parked.
- CobaltHarrier later confirmed CT-3 had not started, so agent3 was repurposed to CT-5 `004048C0_get_action_name` and then further superseded by CT-7 `0045E970_doTrivialMove`.
- CalmTrail’s CT-4 first validation showed offset-0 prolog drift, which is now archived as a blocked tiny-helper attempt.
- CalmTrail’s new CT-6 target is the medium-sized `0045DB90_doMove` task in agent2.
- CT-6 first validation showed offset-0 prolog drift: rebuilt `55 8B EC 83 EC 08 89 4D F8 6A 06 8B 45 F8 8B 10...` vs original `56 8B F1 6A 06 8B 06 FF 50 5C...`.
- CT-6 was later parked in `src/almost_matched/0045DB90_doMove.cpp` as low-risk prolog/source-shape drift.
- CT-8 is now assigned to CalmTrail on `004ABCD0_action` in the clean agent2 worktree.
- CobaltHarrier’s CT-7 minimal scaffold for `0045E970_doTrivialMove` compiled but was too small for diffing (`Configured function size 3704 exceeds .text section size 15`), so it needed a much larger source shape next.
- CT-7 later reached the target size exactly, and the first real diff shows a prolog/frame-shape mismatch at offset 3 (`55 8B EC 83 E4 F8 83 EC 2C 53 56...` vs `55 8B EC 81 EC 10 01 00 00...`).
- CobaltHarrier reported the remaining blocker as too many stack temps/locals forcing the oversized frame; the next probe should trim locals and preserve the saved-regs entry shape.
- CalmTrail confirmed CT-8 is running only in the reserved agent2 worktree and has not reached first compile yet.
- CobaltHarrier confirmed CT-7 remains in the reserved agent3 worktree and is not touching the main tree.
- CalmTrail confirmed CT-8 remains in the reserved agent2 worktree and is not touching the main tree.
- CobaltHarrier’s latest CT-7 blocker is still the prolog/frame shape at offset 3, with the rebuilt frame remaining too large (`81 EC 10 01 00 00...`).
- CobaltHarrier confirmed it is still working only in the reserved agent3 worktree and is trimming locals/temps to recover the smaller saved-regs prolog.
- The next CT-7 diff shrank the frame to `81 EC C4 00 00 00...`, but offset-3 prolog mismatch remains.
- CobaltHarrier clarified that the remaining CT-7 locals are scalar temporaries, with no address-taken locals or array-like stack objects in the active scaffold.
- A later CT-7 probe trimmed too far and undershot the size target: rebuilt size 3388 vs target 3704, so the next step is to add back body shape without restoring stack-heavy locals.
- The latest CT-7 blocker is the missing packet-shaped middle pathfinding block around `userDefinedWaypoints` / `findTilePath`; prolog shape is closer, but the body is still too short to diff.
- CT-7 has now recovered the packet-shaped pathfinding block and returned to exact target size (`3704` bytes), but the smaller prolog regressed to a larger frame again.
- Exact blocker evidence for CT-7: the rebuilt prolog is `55 8B EC 81 EC A4 00 00 00...` instead of the oracle’s small saved-regs entry `55 8B EC 83 E4 F8 83 EC 2C 53 56...`; the remaining issue is stack-frame inflation from named locals.
- CalmTrail’s CT-8 blocker is now the frameless/float-heavy entry body: original entry setup and early FPU/pathing cluster need to stay in packet order without extra stack frame or temps.
- HarborWave and KindTrail were both idled for this cycle after failing to acknowledge their assignments or repeated follow-ups; their worktrees were reset clean and the path reservations were released.
- Responsiveness re-checks were attempted before any fresh reassignment.
- HarborWave later went offline after leaving a late HW-1 draft in agent2; independent review showed it did not compile under the pinned VC5 toolchain (`__thiscall` global + `nullptr`/`this` misuse), so the worktree was reset clean.
- KindTrail later went offline after leaving a late KT-1 draft in agent3; independent review showed it compiled but mismatched from offset 0 with a full stack-frame/prolog shape, so the worktree was reset clean.
- CobaltHarrier later produced a corrected KT-1 in agent3; independent review confirmed an exact match under a justified per-function /O2 rsp, and the result was pulled into main and revalidated there before CH-1 was assigned.
- CH-1's first draft in agent3 compiles but mismatches from offset 0 with a full stack frame; feedback was sent to flatten the source toward the original frameless stack-driven shape.
- The CH-1 scratch file then remained unchanged across multiple monitor cycles, so a second status follow-up was sent asking for either a revised result or a concrete blocker.
- No CH-1 revision or status reply arrived after that warning, so the task was stopped for this cycle, the reservation was released, and agent3 was reset clean.
- A fresh responsiveness check is now pending before any reassignment to CobaltHarrier.
