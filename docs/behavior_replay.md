# Gameplay replay and state comparison

This experimental mode compares game behavior beyond pixels. It does not replace the menu capture suite.

## Standard gameplay parity suite

```cmd
game.cmd test-parity
```

Use this command for gameplay parity checks. It runs the short script and two controlled human-input cases.
Each case runs three fresh originals and three fresh rebuilt games: 18 executions in total.
The human cases use `config/harness/human-accepted-20260914.json` and `config/harness/human-candidate-20260915.json`.
Their 324 and 1,361 messages remain unchanged. The suite checks both pinned hashes before starting games.
The historical `source_report` path records provenance. Replay does not need that old report.
The human cases explicitly use v4 control, not the original v1 timing.
V4 suppresses native game-thread timer messages and controls queued root-window paints at idle boundaries.
Synchronous game-requested paints remain intact. Replay stops eight idle turns after the final recorded input.
The original executable supplies expected behavior under this shared control profile.
The reports preserve historical recording fidelity, including its different clock values and world-update counts.
The recorded messages, routes, turns, and target panels remain required.
They do not claim an exact reconstruction of missing v1 timer history.
The suite rejects an unexpected upgrade, missing control identity, or changed recording.

The human cases record full RNG streams, world entry/exit state, and focused actor observations.
They compare inputs, clocks, all captured state observations, terminal observations, RNG records, and raw RGB hashes.
Each human case checks all 15 pairs among its six runs, including all nine cross-build pairs.
Missing world observations or complete RNG evidence fail the check.
It retains every timing and frame difference. It does not align simulation states or apply tolerances.
Observer neutrality and complete hidden-state equivalence remain unproved.

Reports and videos remain under `build/runtime/`. The suite report uses `build/runtime/parity-*/report.json`.
Only exact equality of the checked observations returns zero. Missing evidence or observed differences return one.
A failure does not by itself prove a game-code defect. Original repeatability can also fail.
Both human cases still run when the short script finds differences.

Use `game.cmd test-parity --legacy` to run the former same-policy v1 suite.
It retains its strict old timing checks and known repeatability failures. V1 recordings and templates remain unchanged.
Recording new user input still uses v2. Use `--controlled` when replaying it for repeatable controlled-input comparisons.
See [human replay](human_replay.md#controlled-input-replay-v4) for commands and limits.

`python -m pytest -q` checks the fixture and suite routing without starting games.
`game.cmd test-parity --check-fixtures` checks both permanent recordings without starting games.
The commands below are focused checks, not substitutes for the standard suite.

## Run a short replay

```cmd
game.cmd replay
```

The default script opens Single Player, selects Random Map, and starts the game.
It moves the cursor to the right edge after five world-update calls, then moves it back after fifteen.
The default process stops at the first Paint boundary after thirty world-update calls.
These calls are not necessarily thirty simulation ticks.

Each batch runs three fresh originals and three rebuilt games on a private desktop.
Use `--runs N` to increase the count per executable. The minimum is three.
The report checks original variation and rebuilt variation separately before classifying cross-build differences.
No original state or RNG result enters rebuilt execution. Both programs use the same input script and clock policy.
The existing menu suite still blocks gameplay. Replay permits only new-game startup; saved games and editor startup remain blocked.

The command prints a directory under `build/runtime/replay-*/`.
It returns zero only when both repeatability groups and the cross-build comparison pass.
Requested capture checks must pass too.
A known rebuilt difference returns one. An incomplete or non-repeatable run also returns one, with a separate report classification.

## Stress repeatability in parallel

```cmd
game.cmd replay-repeat --target original --runs 10
game.cmd replay-repeat --target rebuilt --runs 10
```

Each worker owns a separate runtime, private desktop, registry copy, and process job.
The driver prepares all runtimes before launching workers. It compares every capture with the first capture.
It checks typed observations, actual input delivery, and complete RNG recordings.
Use `--fixture` to supply a script or saved recording. Use `--jobs` to limit concurrent workers.
The current bounds are thirty runs and ten concurrent workers per command.
Starting and ending times in the report show worker overlap.
These batches test repeatability within one executable. The focused `replay` command checks both executables.
Use `test-parity` for the full gameplay suite, including the accepted human recording.

## Capture the full game window

The default replay captures the game client at updates 1, 10, and 30.
Each image includes the full game surface and visible native edit controls.
It excludes the Windows title bar, window borders, and desktop.
Capture uses the same private-desktop surface reader as the menu suite.

Add named checkpoints under `replay.captures`:

```json
"captures": [
  {"name":"game_started", "after_updates":1},
  {"name":"camera_pan", "after_updates":10},
  {"name":"final", "after_updates":30}
]
```

Capture occurs at the first Paint entry after the requested update count.
At this boundary, the game surface is ready for presentation.
The report records the actual update count and delivered-input count.
Both counts must agree between runs. Equal pixels at different boundaries do not pass.
Passing two requested boundaries before one Paint causes failure, not a merged checkpoint.
The final checkpoint must use the replay's terminal update count.
Without capture checkpoints, the process retains the earlier update-return stop behavior.

The report checks state, inputs, and RNG separately from captures.
Capture comparison runs even when state checks fail.
Missing images, changed image hashes, and invalid image dimensions fail the capture check.
Repeatability checks include every requested image for each executable.

Cross-build images appear under the batch's `captures/` directory.
Each checkpoint includes `side-by-side.png` and, for equal dimensions, `difference.png`.
The original appears on the left. The rebuilt game appears on the right.
The difference image shows raw channel differences without masks or tolerance.
Capture equality means exact RGB pixels and image dimensions, not equality of unused palette entries.

These images check visible results that selected memory fields can miss.
Equal images do not prove that hidden state agrees.
Both checks must pass; neither replaces the other.

## Replay a saved recording

```cmd
game.cmd replay --fixture build/runtime/replay-EXAMPLE/recording.json
```

Replace `replay-EXAMPLE` with the printed directory.
The recording contains the script, delivered-message receipts, and the starting contract. It contains no original game-state results.
Replay checks the contract and input delivery again. It does not restore old registry settings automatically.
The harness profile, assets, registry inputs, and graphics inputs must remain compatible.

This mode captures scripted inputs. A separate original-only profile now records human play and produces videos.
See [human recording and replay](human_replay.md) for its commands, input policy, and limits.

`--seconds 90` sets each process's wall-clock deadline. It does not set simulated game duration.

## What the mechanism compares

The reusable components are:

- A validated input script with named panels and update boundaries.
- Configured method-entry and method-return probes.
- Typed receiver fields and scalar stack arguments.
- Raw field bytes, including exact float representations.
- Complete debug RNG records and SHA256 prefixes at observation points.
- Input-message parameters and the update count when the game dispatches them.
- Full game-client images at requested Paint checkpoints.
- A first-difference report with both observations and native stack addresses.

The default schema lives in `config/harness/replay-random-smoke.json`.
It observes world setup, random-map generation, player setup, camera coordinates, and world updates.
It reads selected world counters and flags, not every world field or every object.

Example probe:

```json
{
  "name": "world_update",
  "module": "world",
  "va": "00542ED0",
  "phase": "both",
  "fields": {
    "world_time": [4, "u32"],
    "game_speed": [24, "f32"]
  }
}
```

`module` and `va` select a registry identity. The rebuilt linker map locates its corresponding symbol.
The capture verifies entry bytes against the selected executable before attaching.
This first schema supports IA-32 instance methods with the receiver in ECX.
`fields` offsets start at the receiver. `arguments` offsets start at the first stack argument, after the return address.
Supported types are `u8`, `i16`, `u16`, `i32`, `u32`, and `f32`.

Choose valid fields and object lifetimes from reviewed layout evidence. The reader does not infer either automatically.
It does not follow arbitrary pointers or match object graphs. Receiver addresses remain diagnostic and do not determine equality.
For multiple objects, include an identity field. The camera probe includes the player ID.

## Evidence files

- `scenario.json`: the frozen script used by every run.
- `recording.json`: scripted inputs, actual receipts, and starting contract.
- `report.json`: original-repeat result, cross-build result, first difference, and capture paths.
- Each capture's `report.json`: observations, input history, exceptions, module information, and errors.
- Each capture's `rng.bin`: complete eight-byte records, containing little-endian site ID and value.
- `rng_recording.sites` in the capture report: the site dictionary for that binary file.
- Each capture's `instrumentation.js`: the exact injected script.

RNG source paths use lowercase Windows separators for call-site identity. Site events retain the original spelling as `raw_file`.
No numeric field or RNG value receives this normalization.
The first RNG difference can identify a changed call site even when that event's numeric value is equal.
That alone does not prove a changed game result. Inspect the typed state differences too.

Native stacks can be incomplete under VC5 frame-pointer omission.
The comparison adds nearest known symbol names where available. These are diagnostic candidates, not proof of frame ownership.
A stack at detection time does not necessarily contain the earlier writer of a bad value.

## Scheduling and limits

Inputs enter through posted Windows messages and the game's normal message dispatch.
Mouse handling can call idle and advance the world outside the main loop.
Replay observes those idle returns too. It compares actual delivery counts instead of accepting late input silently.

The clock profile advances one millisecond per `debug_timeGetTime` call. It is an experimental policy, not recorded wall time.
The RNG runs normally. The harness records its results; it does not replace them.
Captures use isolated registry copies, fresh runtimes, and the existing test-only offline networking policy.

Limits include 1,000 update calls, 10,000 observations, ten million RNG records, and a 300-second process deadline.
Reaching an observation or RNG limit fails the replay. It cannot produce a truncated success.
Replay saves the first forty Paint surfaces as auxiliary evidence.
It also saves and compares every requested checkpoint, including checkpoints after that frame limit.
The default replay checks three images. The schema permits at most 32 checkpoints.

The stop boundary parks the owned game thread and then kills the process.
There is no interactive pause inspector, process restore, or automatic write tracing.
The separate human recorder supports a bounded set of received Windows input messages.
Selected fields can agree while unchecked state differs. Passing this profile does not prove full gameplay equivalence.

See `decomp_notes/behavior_replay_20260914.md` for qualification and the first observed setup difference.
See `decomp_notes/replay_capture_20260914.md` for capture qualification and the remaining differences.
