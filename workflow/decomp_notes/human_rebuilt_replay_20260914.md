# First rebuilt replay of the accepted human recording

## Inputs and executables

The user accepted the original replay visually before authorizing rebuilt comparison.
Recording: `build/runtime/human-20260914T193807898696Z/recording.json`.
It contains 324 received messages, including selection, movement, minimap interaction, and map-visibility cheat input.

Original replay batch: `build/runtime/human-user-replay-193807/report.json`.
Rebuilt replay batch: `build/runtime/human-user-rebuilt-193807/report.json`.
Each batch contains three fresh processes on private desktops.

The rebuilt executable contains the earlier land-scan, clearance, and button-drawing repairs.
Its SHA256 is `3fc9498f4005f783bd337c47b6ebcb2bb7163e1efafcc078e4742b2f1687faf8`.
This work did not change recovered game source or rebuild the executable.

The human replay driver now supports an explicit rebuilt target. Human recording remains original-only.
No JavaScript control policy changed for this comparison. The accepted recording's contract still passed unchanged.
No original state, RNG result, or drawing result entered the rebuilt process.

## Results

Comparison: `build/runtime/human-user-comparison-193807/report.json`.
All six processes completed. All 324 input messages reached equal idle counts, world-update counts, and panel names.
Clock values are not identical. The report retains those differences separately.

The following differences repeat in all three rebuilt processes:

| Observation | Original | Rebuilt |
| --- | --- | --- |
| First differing camera position | `(70.5, 120.5)` | `(69.5, 119.5)` |
| Terminal object count | 5778 | 5777 |
| Total RNG observations | 1,224,937 | 1,224,919 |
| Terminal world time | 32424 | 32454 |
| Terminal world-update count | 330 | 330 |

The first camera-value difference is camera observation index 16, after 106 world-update calls.
Both games report cursor position `(557, 436)` in the minimap area.
The corresponding clock values in the first runs are 23588 and 23667 milliseconds.
Twenty of the 36 camera-value observations differ across builds.
Camera-value sequences agree within each three-run executable group.

Terminal object counts, world times, and RNG totals also agree within each executable group.
These are repeatable cross-build observations, not yet separate proven source defects.
Timing differences or an earlier divergence can cause several later differences.

The first 10,000 RNG observations agree. The profile did not retain the remaining RNG values.
Therefore, it cannot identify the first RNG divergence or prove complete RNG equality.
The RNG total includes debug rand and srand observations.

Recorded video sample hashes differ across builds and also vary within each executable group.
Cross-build comparison found 982 or 983 differing sample positions out of about 1,203.
Within-original comparisons found 138 and 10 differences. Within-rebuilt comparisons found 120 and 125.
These counts use positional RGB hashes on the video timeline. They do not isolate code defects from presentation timing.
Raw source frames were not retained; the comparison uses the capture's pre-encode RGB hash records.

## Videos

Original replay: `build/runtime/original-20260914T193926918237Z/capture/video.mp4`.
Rebuilt replay: `build/runtime/rebuilt-20260914T194959584157Z/capture/video.mp4`.
Side by side: `build/runtime/human-user-comparison-193807/original-left-rebuilt-right.mp4`.
The original is on the left. The combined video ends with the shorter input video.

## Validation and next investigation

The driver retained executable, asset, graphics, registry, and instrumentation contract checks.
The rebuilt hook resolver uses verified registry identities and the validated linker map.
Focused tests passed: 110 tests, including target restrictions and video-grid reconstruction.

The next focused investigation should inspect the minimap-to-camera conversion at update 106.
The camera probe shows where the difference becomes observable, not which earlier instruction caused it.
Full RNG recording and intermediate object-count observations are needed to locate the other divergences.
Keep fresh original-repeat checks when adding observers. Do not attribute ordinary original variation to rebuilt source.

## Follow-up: confirmed minimap repair

The original constant at `0056F608` contains `00 00 00 BF`, which is float −0.5.
Both minimap scroll functions subtract that value. The old source instead subtracted positive 0.5.
The repair changes two expressions in `src/diam_map.cpp` to add positive 0.5.
Function notes `functions/0043/00438670.md` and `functions/0043/00438720.md` contain the binary and compiler evidence.
Both fresh function checks report MATCH with zero differing bytes.
The linked build also contains the correct negative-half constant. This check is separate from the local function checks.

Build: `build/executable/human-minimap-repair/20260914T201254980531Z/report.json`.
Executable SHA256: `bee558723e885f0b92bc926a0f2e54585cf6931eace58cbbaebe578a083cd286`.
All 226 source files compiled. Linking completed with no unresolved symbols or link errors.
The selected rebuilt executable now points to this build.
The previous pointer remains in `build/game/rebuilt-before-minimap-repair.json`. The previous executable remains unchanged.
Prior and repaired source states, compiler results, and candidate patches remain in the experiment store.

Targeted unchanged-profile check: `build/runtime/human-minimap-repaired-check-01/report.json`.
Its capture is `build/runtime/rebuilt-20260914T202531220819Z/capture/report.json`.
Against the earlier original replay, all 36 camera positions now match.
All 324 input messages retain the same game boundaries. The largest input clock difference is 25 milliseconds.
The terminal world time and registration counter match: 32424 and 5778.
The repaired RNG total is 1,224,971, against 1,224,937 in that earlier original replay.
This establishes the camera repair, not complete RNG or gameplay equivalence.

The accepted recording remains unchanged.
Its SHA256 is `a320c5d68b8b6f2e49d5d9963e60bc3455c177deac2909d5795ab19e02510e4d`.

## Counter interpretation

The earlier table labels offset `world+140` as an object count.
This field is `numberObjectsValue`, which counts registrations. It is not a complete live-object inventory.
The original `addObject` increments it. The original `removeObject`, at `00545FD0`, clears slots without decrementing it.
Therefore, a difference of one in this field does not itself prove one missing live object.
The new diagnostic records use the name `registrations`. Historical reports remain unchanged.

## Optional observers: qualification not established

`human_observe.js` adds read-only diagnostics without changing the accepted recording or control scripts.
The default replay does not load it. The collector records its separate hash and the complete injected-script hash.
Full RNG tracing preserves every observed result and seed. It never supplies RNG values to either game.
Optional state hooks record registration/removal snapshots, world counters, minimap picks, and camera arguments.
Event batching reduces message overhead. Limits and terminal count checks reject incomplete traces.
The comparison tool can validate and compare complete RNG files, including differences beyond the legacy 10,000-record prefix.

The following original checks did not reproduce the earlier original terminal observations.
They all retained equal input game boundaries, all 36 camera positions, and registration counter 5778.
The baseline RNG count was 1,224,937, with world time 32424 and 330 updates.

| Check | RNG count | World time | Updates | Largest input clock difference |
| --- | ---: | ---: | ---: | ---: |
| Full observer, per-event sends | 1,224,966 | 32343 | 329 | 320 ms |
| Full observer, batched sends | 1,224,935 | 32457 | 330 | 127 ms |
| RNG-only observer | 1,224,978 | 32441 | 330 | 71 ms |

Preserved batch reports, in the same order:

- `build/runtime/human-observed-original-check-01/report.json`
- `build/runtime/human-observed-original-check-02/report.json`
- `build/runtime/human-observed-original-rng-check-02/report.json`

Their runtime directories are `original-20260914T201326240745Z`, `original-20260914T202231757682Z`, and `original-20260914T203046163105Z`.
Each contains the full trace, video, exact injected script, and hashes.
The earlier RNG-only setup failure also remains in `build/runtime/human-observed-original-rng-check-01/report.json`.
It failed before game startup because the optional script used the wrong configuration variable. That defect is fixed.

These runs do not qualify the observers for attributing a later RNG difference to game source.
Observer overhead and ordinary replay timing variation remain possible causes.
A later fresh default-profile original batch also reached a different terminal boundary from the older baseline.
Do not hide these timing differences or change the accepted inputs to force agreement.
The minimap repair does not depend on these unqualified diagnostic traces.

## Three-run check after the minimap repair

Original batch: `build/runtime/human-minimap-original-qualified/report.json`.
Rebuilt batch: `build/runtime/human-minimap-rebuilt-qualified/report.json`.
Comparison: `build/runtime/human-minimap-comparison/report.json`.
Both batches contain three fresh processes. Neither batch loads the optional observers.

All 324 inputs retain equal game boundaries. All 36 camera positions match across builds and within each group.
Both groups end at 331 updates, world time 32524, and registration counter 5778.
The original RNG total is 1,224,951 in all three runs. The rebuilt total is 1,224,987 in all three runs.
The first 10,000 RNG records match. The remaining 36-count difference is not yet a proven source defect.
Cross-build input clock differences reach 21 milliseconds. Within-original differences reach 40 milliseconds; within-rebuilt differences reach 20 milliseconds.
These timing results remain visible in the comparison report.

The build input manifests differ from the preceding three-repair executable only at `src/diam_map.cpp`.
The new original group differs from the older baseline even without optional observers: it performs one extra terminal update.
Therefore, comparisons must keep the terminal boundary separate from the shared input boundaries.

Video: `build/runtime/human-minimap-comparison/original-rebuilt-difference.mp4`.
It contains 1,205 frames over 60.25 seconds at 1920×512 pixels.
The three game images retain all 640×480 pixels. A separate 32-pixel header names the panels.
The difference uses decoded RGB values, not YUV component differences. Matching RGB values produce black before video encoding.
Its SHA256 is `bf51e019b4e38aef06dd2cff27c8dcd69d186bf786a5e592a0e9a6288dd117ca`.
An incorrect initial YUV render remains as `original-rebuilt-yuv-difference-rejected.mp4` in the same directory.
The sample `at-25-seconds.png` exposes a remaining selection-outline and health-bar displacement.
This led to the next independent binary check.

## Follow-up: map-point constant repair

`RGE_Map::get_point`, at `0045A6D0`, subtracts the float at original address `005706EC`.
Those bytes are `00 00 80 BF`, or −1.0. The recovered source incorrectly subtracted positive 0.5.
The repair changes one expression in `src/map.cpp` to add positive 1.0.
It retains the remaining operation order, integer conversion, Y origin, and final subtraction of 16.
This helper supplies both the selection outline and the health bar.
The original binary establishes the defect independently of replay timing.
See `functions/0045/0045A6D0.md` for the instruction-level evidence.

Build: `build/executable/human-map-point-repair/20260914T204731173448Z/report.json`.
Executable SHA256: `b1f6197038f049e731a8df6dd394b65d1de6fbe1a9d7cbac3bf369d65dab9546`.
All 226 source files compile and linking succeeds without unresolved symbols.
The linked function starts at `0044D8A0` and subtracts the float at `005519E0`.
The linked bytes are also `00 00 80 BF`, confirming the repaired data value.
The selected rebuilt executable now uses this build.
The preceding selection remains in `build/game/rebuilt-before-map-point-repair.json`.

The exported experiment patches include earlier human-harness edits as well as the game repair.
Integration-objection records warn against applying those patches as current harness updates.
The actual reviewed game changes remain three expressions in two natural source files.

## Final three-run check

Rebuilt batch: `build/runtime/human-map-point-rebuilt-qualified/report.json`.
Comparison: `build/runtime/human-map-point-comparison/report.json`.
This comparison retains the preceding three fresh originals. Their executable, inputs, assets, and control profile did not change.
It uses three new rebuilt processes without optional observers.

All 324 messages retain equal game boundaries. All 36 camera positions match in every comparison.
The registration counter remains 5778 in every run.
The first two rebuilt runs stop at 330 updates and world time 32424. Their RNG total is 1,224,971.
The third stops at 331 updates and world time 32524. Its RNG total is 1,224,987.
The three original runs stop at 331 updates and world time 32524, with RNG total 1,224,951.
Thus, matching terminal boundaries still leave 36 additional rebuilt RNG observations.
Do not compare differing terminal boundaries as if they covered identical execution.
Cross-build input clock differences reach 41 milliseconds. The report retains each difference.

The first two rebuilt videos have identical sampled RGB hashes. The third differs at 125 sampled positions.
Cross-build sampled hashes differ at 518, 518, and 444 positions, respectively.
These are video-time comparisons, not simulation-aligned defect counts.
The comparison still reports incomplete RNG coverage for the default profile and does not claim full gameplay equivalence.

Final video: `build/runtime/human-map-point-comparison/original-rebuilt-difference.mp4`.
It uses the first original and first rebuilt runs, without selecting a better-matching run.
It ends with the shorter video: 1,203 frames, 60.15 seconds, 1920×512 pixels.
The sample `at-25-seconds.png` shows the corrected selection outline and health bar.
The difference panel uses decoded RGB values. The header does not cover game pixels.
Video SHA256: `405a41280b5b3b2953ed6a8b652c0f94c1912fc853c2ba3ccab0209481c52e71`.
The preceding videos and rejected render remain unchanged.

The compiler input manifests differ from the earlier three-repair build only at `src/diam_map.cpp` and `src/map.cpp`.
All three repaired functions pass fresh byte checks. Their linked constants also match the original values.

## Remaining work

Full RNG equivalence remains unresolved. Optional tracing has not passed original observer-neutrality checks.
First reduce tracing overhead and compare RNG positions at shared recorded boundaries, not only the variable terminal boundary.
A small native trace buffer is one possible approach. It must still pass original checks before supporting source conclusions.
Do not change the accepted recording or inject original values into rebuilt execution.

The repeated constant errors also justify a focused extension to the existing storage-reference checks.
Compare original literal bytes with compiler or linked storage before treating a local MATCH as complete data validation.
Keep that tooling work separate from any further game-source repair.

## Final validation

`python -m pytest tests -q`: 678 tests and 31 subtests passed.
The suite includes pinned-original constant checks, source regression checks, observer batching, and complete RNG comparison checks.
The optional JavaScript passes `node --check`. `git diff --check` passes.
All new experiment content objects passed SHA256 filename checks.
No commit was made during this follow-up. The source, diagnostics, tests, and evidence remain available for review.
