# Gameplay replay and state comparison

This experimental mode compares game behavior beyond pixels. It does not replace the menu capture suite.

## Run a short replay

```cmd
game.cmd replay
```

The default script opens Single Player, selects Random Map, and starts the game.
It moves the cursor to the right edge after five world-update calls, then moves it back after fifteen.
The process stops after thirty world-update calls. These calls are not necessarily thirty simulation ticks.

Each batch runs three fresh originals and three rebuilt games on a private desktop.
Use `--runs N` to increase the count per executable. The minimum is three.
The report checks original variation and rebuilt variation separately before classifying cross-build differences.
No original state or RNG result enters rebuilt execution. Both programs use the same input script and clock policy.
The existing menu suite still blocks gameplay. Replay permits only new-game startup; saved games and editor startup remain blocked.

The command prints a directory under `build/runtime/replay-*/`.
It returns zero only when both original repeat and cross-build comparisons pass.
A known rebuilt difference returns one. An incomplete or non-repeatable run also returns one, with a separate report classification.

## Stress repeatability in parallel

```cmd
game.cmd replay-repeat --target original --runs 10 --jobs 10
game.cmd replay-repeat --target rebuilt --runs 10 --jobs 10
```

Each worker owns a separate runtime, private desktop, registry copy, and process job.
The driver prepares all runtimes before launching workers. It compares every capture with the first capture.
It checks typed observations, actual input delivery, and complete RNG recordings.
Use `--fixture` to supply a script or saved recording. Use `--jobs` to limit concurrent workers.
The current bounds are thirty runs and ten concurrent workers per command.
Starting and ending times in the report show worker overlap.
These batches test repeatability within one executable. The normal replay command checks both executables and compares them.

## Replay a saved recording

```cmd
game.cmd replay --fixture build/runtime/replay-EXAMPLE/recording.json
```

Replace `replay-EXAMPLE` with the printed directory.
The recording contains the script, delivered-message receipts, and the starting contract. It contains no original game-state results.
Replay checks the contract and input delivery again. It does not restore old registry settings automatically.
The harness profile, assets, registry inputs, and graphics inputs must remain compatible.

This first recorder captures scripted inputs. It is not a recorder for arbitrary human play.

`--seconds 90` sets each process's wall-clock deadline. It does not set simulated game duration.

## What the mechanism compares

The reusable components are:

- A validated input script with named panels and update boundaries.
- Configured method-entry and method-return probes.
- Typed receiver fields and scalar stack arguments.
- Raw field bytes, including exact float representations.
- Complete debug RNG records and SHA256 prefixes at observation points.
- Input-message parameters and the update count when the game dispatches them.
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

- `scenario.json`: the frozen script used by all three runs.
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
Replay saves only the first forty Paint surfaces as auxiliary evidence. It does not compare gameplay pixels in this mode.

The current stop boundary parks the owned game thread and then kills the process.
There is no interactive pause inspector, process restore, automatic write tracing, or general input recorder yet.
Selected fields can agree while unchecked state differs. Passing this profile does not prove full gameplay equivalence.

See `decomp_notes/behavior_replay_20260914.md` for qualification and the first observed setup difference.
