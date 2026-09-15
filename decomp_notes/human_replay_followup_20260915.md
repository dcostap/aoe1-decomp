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
