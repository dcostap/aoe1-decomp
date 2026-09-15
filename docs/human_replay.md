# Record and replay human play on the original game

This experimental profile records received input and produces game-window videos.
Recording uses only the pinned original beta executable.
Replay uses the original by default. A separate command explicitly selects the rebuilt game.

## Record a short session

Run from the repository directory:

```cmd
game.cmd record-original --seconds 60
```

Recording starts at launch. This includes the menu inputs needed to start the match.
Select Single Player, then Random Map. Play in the game window.
Press **F10** to stop. The recorder reserves this key; the game does not receive it.
The normal window close button also saves the recording before the worker closes the game.

The time limit uses controlled time, not wall time. Loading and capture overhead can extend the wall duration.
The default limit is 60 controlled seconds. The maximum requested limit is 180 seconds.
An independent process deadline stops a stalled worker and its game and encoder processes.

Do not resize or move the game window. Do not switch applications during recording.
Use a new random-map game. Saved games, scenarios, and the editor remain blocked.
The profile blocks game network sockets and disables sound and music.

For the first human check, record camera movement, unit selection, a selection drag, movement orders, and gathering.
Keep that first session short. More gameplay coverage comes after input replay qualification.

The command prints paths for `recording.json`, `report.json`, and `video.mp4`.
Keep the whole recording directory and its referenced runtime capture directory.

## Permanent regression case

The accepted recording is now `config/harness/human-accepted-20260914.json`.
It preserves all 324 messages and the original file SHA256:
`a320c5d68b8b6f2e49d5d9963e60bc3455c177deac2909d5795ab19e02510e4d`.
The copy does not replace or change the historical recording.

Run `game.cmd test-parity` for the standard gameplay parity suite.
This command always includes the accepted recording. It needs no recording path.
See [the suite contract](behavior_replay.md#standard-gameplay-parity-suite) for checks and failure rules.

The first standard run completed on 2026-09-14:
`build/runtime/parity-20260914T230838502031Z/report.json`.
The short script passed. All six human runs preserved the 324 messages and their game boundaries.
The human comparison failed. Clock and RGB differences remain visible, including differences between original runs.
Two rebuilt runs matched the complete original RNG stream of 1,224,935 records.
The other rebuilt run first differed at RNG index 1,221,307: equal value 13910, but different callers.
It ended after 329 updates; the original ended after 330.
These observations do not establish the cause or prove a game-code defect.
The suite returned one. It did not treat completed captures as a parity pass.

## Replay the recording

Use the printed recording path:

```cmd
game.cmd replay-original build/runtime/human-EXAMPLE/recording.json
```

This runs three fresh originals, sequentially, on private desktops. It does not switch your desktop.
Each run produces its own game-window video. Open the printed `video.mp4` files in your video player.

For a targeted development check, use one run:

```cmd
game.cmd replay-original build/runtime/human-EXAMPLE/recording.json --runs 1
```

One run cannot establish repeatability.

## Compare with the rebuilt game

After accepting the original replay, run the same recording on the selected rebuilt executable:

```cmd
game.cmd replay-rebuilt build/runtime/human-EXAMPLE/recording.json
```

This runs three fresh rebuilt processes. It keeps the recorded inputs, clock policy, and starting-contract checks.
The harness validates the rebuilt executable and linker map before resolving its corresponding function hooks.
It does not insert original game state, RNG results, or rendered output into rebuilt execution.
The accepted recording does not need to change when selecting the other executable.

`tools/harness/human_compare.py` compares complete three-run original and rebuilt batch reports.
Use its `--help` output for command syntax.
It checks within-executable variation before reporting cross-build input, camera, counter, RNG-prefix, and video differences.

Use this explicit diagnostic for an existing v1 recording that needs the serialized scheduler:

```cmd
game.cmd replay-original config/harness/human-candidate-20260915.json --runs 1 --upgrade-v1-to-v2
```

The command first checks the complete v1 starting contract against the frozen v1 control template.
It then uses the v2 scheduler without changing the recording.
The report records both policies, both template hashes, the upgrade rule, and the recording hash.
It also records `same_policy_replay` as false.
The standard parity suite rejects upgraded captures.
The generic human comparison labels them as an explicit v1-to-v2 upgrade comparison.

The default profile saves only the first 10,000 RNG observations, plus the total count.
An equal prefix is not a complete RNG match. The comparison reports this limit explicitly.
Video comparison uses recorded pre-encode RGB hashes, with no pixel tolerance or masks.
Equal video timestamps are not necessarily equal simulation boundaries.
The comparison's `complete` flag means all comparisons ran, not that the executables matched.

## Optional read-only diagnostics

`human_session.py --observe` adds full debug RNG tracing and focused state observations during replay.
Add `--rng-only` to omit the additional state hooks. Neither option can record a new human session.
Alternatively, add `--combat` for the focused civilization-effect investigation. It cannot accompany `--rng-only`.
This mode targets the accepted recording's attack updates, sprite changes, and villager 4969.
It also records clock-advance counts. Its observation ranges appear in the report's `observer-ready` event.
Use the tool's `--help` output for the complete command syntax.

These diagnostics remain experimental and disabled by default.
The first original checks changed clock values and RNG totals, although input boundaries and camera positions stayed equal.
They did not establish observer neutrality. Do not use those runs alone to prove another game-code defect.
See `decomp_notes/human_rebuilt_replay_20260914.md` for the preserved checks.
See `decomp_notes/human_rng_investigation_20260914.md` for the later timing and civilization-effect findings.
Use `rng_investigate.py --help` for diagnostic comparisons. The tool requires equal observer scripts and modes.

The optional script does not change recorded inputs or replay controls. It does not replace game outputs.
The report records separate control-script, observer-script, and full injected-script hashes.
Observer overhead can still change execution timing under the current clock policy.

`rng.bin` stores each observed debug RNG result or seed as two little-endian 32-bit values: site ID and value.
`rng_recording.sites` resolves each site ID. The report includes the file hash and record count.
The collector checks the terminal RNG counter against the complete file.
The ten-million-record limit stops the run rather than publishing a complete truncated trace.
The comparison checks complete RNG files when both reports contain them.

State diagnostics record registration and removal, world counters, minimap picks, and camera arguments.
Object snapshots contain ID, master ID, owner, position, hit points, and state at the observed call.
They do not trace every object change or prove complete object lifetime coverage.
Each event records its RNG position, update count, input position, and clock value.
The collector checks event counts and sequence numbers.

The historical terminal `objects` field reads the world's registration counter, not a complete live-object inventory.
Do not infer a missing live object from that counter alone.

## Read the result

The report separates these results:

- `complete`: all requested sessions reached their terminal boundary and produced videos.
- `input_sequence_preserved`: replay received the same message parameters and owned-window routes.
- `recording_fidelity`: timing, update-count, and panel differences from your original session.
- `input_repeatable`: repeated replays received inputs at equal recorded boundaries. One run reports `null`.
- `game_boundaries_repeatable`: idle counts, world-update counts, and panels agree, even when clock values differ.
- `dropped_unrequested_messages`: additional queued input messages blocked during replay.

`complete` does not mean exact replay or equivalent hidden game state.
An equal message sequence can remain useful when its timing differs from the recording.
Review those timing differences and the videos before accepting the scenario.
The current smoke test repeats game input boundaries, but controlled clock values still differ between some runs.
See `decomp_notes/human_replay_20260914.md` for the measured limits. This is not exact replay qualification.

Receipts identify `DispatchMessage` entry, not proof that the handler completed its intended action.
The videos provide an independent visible check. This profile does not yet compare complete object or AI state.

## Clock and input policy

The clock starts at 1000 milliseconds.
It advances 20 milliseconds at each main-loop idle return and one millisecond per debug-clock call.
The harness paces that clock against wall time. Slow execution does not skip controlled time.
Idle advancement prevents the clock from stopping in static menus.
New recordings use the serialized v2 policy.
A normal replay uses its recorded policy. Neither replaces RNG values or restores original game state.

Recording captures queued mouse movement, button transitions, double-clicks, keyboard transitions, and character messages.
Both modes derive game cursor and key polling from received messages, not unrelated desktop input.
Cursor polling uses the pinned graphics wrapper's logical game coordinates, not desktop coordinates.
This normalized polling model does not reproduce every Windows keyboard-state feature.

The v2 scheduler keeps one recorded message in flight.
It resolves the next window after the exact prior `DispatchMessage` call returns.
This permits a prior handler to create, destroy, or replace a native child control.
It does not retry a missing or ambiguous route.

The accepted 2026-09-14 recording keeps its frozen v1 grouped scheduler and exact template hash.
This compatibility path keeps its existing message ordering.

Input can run in a nested modal message loop.
The v2 scheduler releases input after the matching nested dispatch returns.
An unrelated nested dispatch or A/W forwarding call cannot release it.
The recording does not store dispatch depth, so replay does not prove equal modal-loop nesting.
A handler can enter a modal loop that needs another recorded input before that handler returns.
V2 withholds that input while the handler remains pending. Such a replay can stall and fail its deadline.
Do not treat this unsupported case as a game-code defect.

Replay schedules messages at recorded idle-return boundaries, including nested idle calls during mouse handling.
The normal game loop dispatches them through Windows. The harness checks receipts without calling game command functions directly.
Replay suppresses automatic character translation because the recording already contains character messages.

Native input targets must have an unambiguous owned-window identity.
Unsupported input messages, including wheel and extra mouse-button messages, stop this first version.
Input records have explicit size, count, route, and time limits. Limit failures cannot produce a complete recording.

The starting contract checks assets, graphics configuration, registry inputs, instrumentation, and the original executable.
New-game replay checks exclude `.gmx` and `.gam` files beneath `savegame`.
Adding, removing, or changing these unused saves does not block replay. All other asset checks remain.
Recording files and full asset manifests remain unchanged for reference.
An incompatible contract stops replay before the game resumes. The harness does not silently update the contract.
An explicit v1-to-v2 upgrade retains the recorded contract and reports the different executed policy.

## Video files

The encoder streams H264 MP4 at 20 frames per controlled second. FFmpeg must be available on `PATH`.
It does not create a large directory of frame images.

Capture reads the game surface and composites visible owned native controls through memory bitmaps.
It never reads the desktop. Videos exclude window borders, title bars, audio, and blinking native text carets.

Video time starts at the first captured Paint boundary.
The capture report records this offset as `video_origin_time_ms` against the input timeline.
The encoder repeats the previous image across capture gaps. It preserves the final image at the next frame boundary.
H264 video is a viewing artifact, not an exact-pixel equality oracle.

Each runtime capture directory contains:

- `video.mp4`: the viewable recording or replay.
- `video.json`: video timing, dimensions, frame counts, and file hash.
- `video-frames.jsonl`: source-frame timestamps and hashes.
- `video.log`: the encoder command and diagnostics.
- `report.json`: input receipts, terminal observations, isolation checks, errors, and video metadata.
- `instrumentation.js`: the exact injected script.

The private automated smoke mode tests the recording machinery. It is not a substitute for your human acceptance recording.
