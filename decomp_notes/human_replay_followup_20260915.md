# Old and new recording checks

## Preserved inputs

The old regression input remains `config/harness/human-accepted-20260914.json`.
The new input is `config/harness/human-candidate-20260915.json`.
Its SHA256 is `60c04e651b19d144cd033ffcc5ed2bdff1bfe75629b036f493d8db497e4b832e`.
It contains 1,361 messages and lasts 180,127 controlled milliseconds.
The copy exactly matches `build/runtime/human-20260915T062602346252Z/recording.json`.
The source video remains in `build/runtime/original-20260915T062602349251Z/capture/video.mp4`.
This candidate does not replace the old regression input.
The user discarded the two preceding recording attempts. Do not use them for qualification.

## Old input without the full observer

Comparison: `build/runtime/old-recording-final-repairs-comparison/report.json`.
Original batch: `build/runtime/human-20260915T062938019792Z/report.json`.
Rebuilt batch: `build/runtime/human-20260915T063246873029Z/report.json`.
All six captures completed. All preserved the messages, game boundaries, and 36 camera values.
Exact clock boundaries differed, including between original runs.
The three cross-build comparisons differ at 118, 1, and 0 captured RGB positions.
The last two comparisons each contain 1,206 frames per side.
One matching video pair does not establish repeatability or complete game equivalence.
These default captures contain RNG prefixes, not complete RNG traces.

## New input failure

Original failed capture: `build/runtime/original-20260915T063556243828Z/capture/report.json`.
Rebuilt failed capture: `build/runtime/rebuilt-20260915T063726841987Z/capture/report.json`.
Both fail with `Recorded input window is missing or ambiguous`.
Both stop at turn 2,770, after 181 updates, with 1,110 received and 1,112 posted inputs.
Both report world time 17,719, 18,256 registrations, and camera position 52.5, 197.5.

Input indices 1,110 and 1,111 send Return key-down and character messages to the root window.
Index 1,112 sends Return key-up to the child `Edit` control with ID 1.
All three recorded inputs have the same turn and timestamp.
`pumpReplay` resolves every due route before earlier posted messages dispatch.
Thus it attempts the child route before dispatching the Return messages that precede it.
The same failure on the original prevents qualification of this replay as a game-code comparison.
An independent diagnostic review examines route creation, destruction, and nested dispatch.
Do not change the input or bypass its script identity check to conceal this failure.

## Old input with the full observer

Suite: `build/runtime/parity-20260915T064138765169Z/report.json`.
The report and all six human captures completed before the shell interruption was reported.
Each individual capture returned zero. Both human batch workers returned 120.
The outer worker exit cause remains unknown. Do not report clean worker completion.
The short scripted comparison passed. The human comparison failed.

The original RNG counts are 1,224,935, 1,224,935, and 1,224,978.
All rebuilt RNG counts are 1,224,937, with equal complete traces between those rebuilt runs.
The third original and every compared rebuilt run first diverge from the first original at RNG index 1,221,307.
Both sides return 13,910, but callers differ: `act_bird.cpp:76` versus `tplayer.cpp:607`.
The original also shows this caller-order difference between its own runs.
Cross-build RGB differences cover 984, 972, and 972 frame positions.
The observations do not identify a game-code cause or establish observer neutrality.
Keep clock, terminal, image, and RNG differences visible.

## Recovery after shell interruption

The user reported PowerShell crashes. No replay, game, or encoder process remained when checked.
The process tracker had reset. The diagnostic agent had stopped without a final answer.
The diagnostic agent resumed from its saved context.
The complete suite reports made a duplicate gameplay run unnecessary at that point.
The cause of the PowerShell crashes remains unknown.

## Versioned scheduler repair

V2 posts one message and retains its pending identity until the matching dispatch returns.
It then resolves the next route. Missing routes still fail; the scheduler adds no retry or clock adjustment.
The frozen V1 template retains SHA256 `6312fbd5ebb7d82dd91abe775e8c4c15c538743f276dba03ab61bbb8a1043db4`.
The old accepted input continues to select V1.
V2 uses SHA256 `1112a4ab54fef13f766d20da7fc1815b20f43aa844bbfdde23ce14eeabc862f4`.
Existing V1 input requires the explicit `--upgrade-v1-to-v2` diagnostic option to use V2.
That option verifies the full original contract and reports both identities without changing the recording.
Standard parity rejects upgraded captures. Generic comparisons label the different execution policy.

The first original diagnostic run completed all 1,361 inputs with no dropped messages.
Every input message and game boundary matches the recording. Clock boundaries still differ.
Report: `build/runtime/human-20260915T075924132214Z/report.json`.
Capture: `build/runtime/original-20260915T075924146229Z/capture/report.json`.
This demonstrates successful route handling, not same-policy or complete gameplay equivalence.
The full Python suite passed 762 tests and 31 subtests with the final linked-image fixture.
Test report: `build/scheduler-v2-full-tests.xml`.

The old-input comparison video is:
`build/runtime/old-recording-final-repairs-comparison/original-rebuilt-difference.mp4`.
It contains 1,206 frames at 20 FPS, with dimensions 1920 by 512.
The video uses the first reported pair, not the equal pair.
One black end frame marks the shorter rebuilt video. No existing game frame is masked or omitted.
Its difference panel compares decoded video pixels. Raw capture hashes remain the exact comparison evidence.

## Six completed candidate diagnostics

Batch root: `build/runtime/new-input-v2-full-20260915T080644Z/`.
All six captures and both batch workers returned zero.
The comparison completed as `explicit-v1-to-v2-upgrade-comparison`, not a same-policy replay.
All runs preserved the 1,361 messages and game input boundaries. Camera values also matched between compared runs.
Clock boundaries differed. RNG order, terminal observations, and video frames varied within each executable.

Original RNG counts: 3,611,267; 3,611,257; 3,611,244.
Rebuilt RNG counts: 3,611,267; 3,611,244; 3,611,252.
The three cross-build comparisons differ at 173, 1,928, and 1,988 RGB frame positions.
Each cross-build side has 3,608 frames. The first pair has equal terminal world observations.
Its first video difference occurs at 3,950 video milliseconds.

An exact field scan of the first pair checks all 3,611,267 RNG records.
Every returned value matches. Exactly one site identity differs, at index 3,609,993.
Both records return 7,893 at source line 2,862.
The original reports `aiuaimod.cpp`; the rebuilt reports `aiuaimod.c`.
The scan retains this discrepancy as a failure. It applies no filename alias.
Scan evidence: `rng-field-differences.json` and `inspect_rng_pairs.py` beneath the batch root.
An independent worker checks the corresponding source literal against the original callsite bytes.

The first-pair comparison video is `comparison/original-rebuilt-difference.mp4` beneath the batch root.
It shows original, repaired, and decoded RGB difference panels without dropping end frames.
No complete gameplay equivalence follows from these diagnostics.

The separate legacy replay also completed after freezing V1:
`build/runtime/human-20260915T080541397572Z/report.json`.

## Proven RNG logging literal repair

`UnitAIModule::closestUndiscoveredTile` owns the original range 00415F40 through 004161CB.
The original instruction at 0041601A pushes line 0xB2E.
The instruction at 0041601F pushes 0057F980, which stores `C:\msdev\work\age1_x1\aiuaimod.cpp`.
The call at 00416024 reaches `debug_rand` at 004230A0.
The rebuilt source omitted the final `pp`. The repair restores only that literal.
`debug_rand` calls `rand` at 004230A4 and saves its result before handling the logging arguments.
Thus this repair corrects logging identity, not the RNG calculation.

The first pair's numeric RNG files are byte-equal, but their site dictionaries differ.
Numeric file equality alone does not establish complete trace equality.
The exact site-aware comparison correctly rejected the old literal.
The regression test checks the original bytes and call identity without changing the comparator.
The fresh function check reports MATCH for all 652 bytes.
Linked-image and runtime validation of this final source change follow separately.

## Final linked and runtime validation

Final build: `build/executable/ai-rng-filename-repair/20260915T083203564911Z/`.
EXE SHA256: `492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`.
Only `src/aiuaimod.cpp` changed among the compiler input files compared with the preceding combined build.
The final map resolves the owner to 00411F60 and the checked argument sequence to 0041203A.
That sequence passes the corrected literal at 0055F4E4 and calls `debug_rand` at 0041E950.
Evidence: `build/linked-ai-rng-literal.json` and `build/check_linked_ai_rng_literal.py`.

The linked dependency audit reports 7,760 passes, zero failures, and 47,025 unknown checks.
Audit: `build/dependency-audit/ai-rng-filename-repair/`.
The full suite passed 764 tests and 31 subtests with that linked fixture.
Test report: `build/ai-rng-filename-tests.xml`.
The AI module audit reports matching results for all 107 exact validation targets.
It also reports three relocation problems among the other configured functions. Those remain unresolved.
Module audit: `build/ai-rng-filename-tu-audit/`.

All three fresh repaired captures completed and preserved the 1,361 messages and game boundaries.
Each exactly matches the first original run's complete 3,611,267-record RNG trace, including site identities.
Each also matches that original's camera values and terminal world observations.
Clock boundaries still differ. RGB differences cover 511, 1,100, and 242 frame positions.
The other two original runs differ in RNG order and counts, including before this source repair.
The full nine-pair matrix preserves those differences rather than selecting only matching pairs.

Repaired batch: `build/runtime/new-input-v2-filename-repaired/report.json`.
Comparison: `build/runtime/new-input-v2-filename-repaired-comparison/report.json`.
Matrix: `build/runtime/new-input-v2-filename-repaired-comparison/all-pairs.json`.
Final first-pair video: `build/runtime/new-input-v2-filename-repaired-comparison/original-rebuilt-difference.mp4`.
The earlier builds, comparisons, and videos remain intact.

These runs use an explicit scheduler upgrade. They do not establish same-policy or full gameplay equivalence.
Remaining work includes clock-call and presentation-order investigation, with separate original repeat controls.
Do not infer a new game-code repair from image differences alone.
