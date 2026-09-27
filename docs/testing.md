# Project testing

The project has separate validation stages. It has no universal test command or combined pass result.
Use this guide as the entry point. Keep the stage reports together under a new `build/` directory.

Run commands from the repository root. Run each repository tool with `--help` before use.
The examples below use Windows Command Prompt syntax. Replace `RUN`, `BUILD`, and `JOBS` with actual values.
`BUILD` means the timestamped build directory containing the executable and its build report.

## 1. Check the registry and function claims

Check source and registry configuration without using old build artifacts:

```cmd
python tools/validate_translation_units.py --no-build-checks
```

This checks configuration, not compilation or byte equality.
Without `--no-build-checks`, the tool also checks available manifests and objects.
Its default directories are `build/manifests` and `build/obj`. Do not assume those files are fresh.
Use `--manifests-dir` and `--objects-dir` to select the intended artifacts.

Compile and compare all configured modules:

```cmd
python tools/audit_translation_unit_functions.py --jobs JOBS --output-dir build/validation/RUN/functions
```

Do not use `--group` or `--affected-by` for a whole-project check.
The command writes `report.json`, `report.csv`, `report.txt`, and repair queues.
It returns failure for compilation errors or failed `matching` claims.
Expected differences in nonmatching functions do not fail that exact-claim check.
Read the unknown results and coverage limits as well as the exit code.

Check ownership against that same fresh report:

```cmd
python tools/audit_matching_owners.py --function-report build/validation/RUN/functions/report.json --output build/validation/RUN/owners.json --text-output build/validation/RUN/owners.txt
```

This tool writes findings. It does not return failure merely because it finds owner mismatches.
Read its mismatch counts and repair queue. Do not treat exit zero as approval.

### What statuses mean

- `matching`: fresh checks must prove positional bytes, boundaries, ownership, and supported direct-target identity.
- `accepted_drift`: reviewed behavior agreement; byte differences are permitted.
- `verified_logic` and `new_verified_logic`: source approval from their respective review workflows, not byte equality.
- `scratch`: unfinished recovery work.
- `unresolved`: no proved build route; this remains a gap.

Compilation does not repeat a semantic review. Source changes can require a new review.
A registry count is not validation of its claims.
See [reference validation](reference_validation.md) for exactness limits and emission checks.

## 2. Build the executable

```cmd
game.cmd build
```

This compiles and links the current game sources with the pinned toolchain.
It also selects the rebuilt executable for later game commands.
Record its build directory and executable hash. Check `build/game/rebuilt.json` for the selected executable.
Do not change sources or select another build between validation stages.

Build success proves compilation and linking, not all function claims or game behavior.
See [executable builds](executable_build.md) for inputs, approved binary dependencies, and build reports.

## 3. Check the linked executable

```cmd
python tools/audit_image_dependencies.py --build BUILD --output build/validation/RUN/dependencies
```

The output directory must be new. The audit checks recorded artifact hashes.
It checks supported constants, reference targets, switch targets, and reviewed initial storage.
It returns failure for supported checks that differ. Unknown checks remain unknown even when it returns zero.

Additional tools cover distinct areas; the image audit is not a replacement for all of them:

- `audit_header_emissions.py`: header and unresolved function emissions, including supported linker folding evidence.
- `audit_linked_references.py`: reviewed linked owners and pointer fields.
- `audit_global_initializers.py`: broader named primitive-data checks.

Use the same build for these checks. Read their individual limits and reports.
See [reference validation](reference_validation.md), [linked reference checks](linked_reference_audit.md),
and [image dependency checks](image_dependency_audit.md).

## 4. Run automated code and tool tests

```cmd
set "AOE_DEPENDENCY_BUILD=BUILD"
python -m pytest -q --junitxml=build/validation/RUN/tests.xml
set "AOE_DEPENDENCY_BUILD="
```

The environment variable selects the fresh linked build for the relevant regression tests.
Without it, those tests skip. Other tests can also have prerequisites; inspect the skip results.
These tests cover tooling, harness logic, and specific regressions. They do not run the full game suites below.

## 5. Run menu and gameplay suites

Check that `build/game/rebuilt.json` still selects the executable checked above.
The game suites stage fresh runtimes; they do not automatically rebuild the source.
Run `game.cmd setup` first if the pinned graphics and instrumentation dependencies are not installed.

```cmd
game.cmd test-captures
game.cmd test-parity
game.cmd test-traces
```

The paced suites run with one worker. Parallel workers are disabled because
parallel paced runs showed drift. `--jobs` set to one is allowed. Any value above one fails
with a clear error before a game starts.

Each hidden worker owns its private desktop and output folder.
The parity suite also keeps nested replay, human, and native-feature captures
serial. The traced suite is the exception; see below.

`test-traces` replays each deterministic-trace recording once on the original and
once on the rebuilt executable, in parallel. `--jobs N` sets the process count; the
default is half the logical CPUs. Traced replay feeds every recorded clock value and
message-pump result back to the game, so wall time and CPU load cannot change game
state. The recording session is the oracle. Each run must reproduce its RNG trace
hash and count, per-update RNG checkpoints, update and input counts, world time and
object count, and camera. Both runs must consume the same trace prefix and write the
same files. Every file the game writes (saves, scenarios, anything else) must match
the recording session byte for byte. A mismatch reports the first differing world update, and for RNG the
first differing record with its source line. Heap allocations are zero-filled on
both sides; allocation counts are reported but do not gate the result. Traced runs
capture only the terminal frame. `test-parity` includes the traced suite as one worker.
Traces are personal data in the gitignored `local/harness/` folder, not in git.
Without local traces, `test-traces` prints `SKIPPED` and `test-parity` reports the
traces worker as skipped. A skip is not a gameplay pass.
See [traced recordings](human_replay.md#exact-fast-replay-from-a-traced-recording).

`test-captures` runs the menu/UI suite. `--list` only lists cases; `--case` selects a subset.
Automated runs use a fixed registry profile and default to 640x480.
Use `--resolution WIDTHxHEIGHT` to run the same fixture at another supported resolution.
See [the runtime harness](runtime_harness.md) for its setup, reports, and coverage.

`test-parity` runs the short new-game script, three paced human gameplay cases, the responsive editor case,
the traced suite, and native-feature captures.
The paced human recordings contain 324, 1,361, and 559 messages.
Each human case runs three originals and three rebuilt games.
Each human case checks all 15 pairs, including within-executable and cross-executable comparisons.
It compares inputs, clocks, all captured state observations, terminal observations, complete RNG records, and raw RGB hashes.
Missing world entry/exit observations or complete RNG evidence fail the check.
The editor case instead checks exact input boundaries, camera receipts, RNG prefix and count, and raw RGB hashes.
It has no world observer or complete RNG trace.
Human capture reports also list changed save files. Chain cases compare their exact
file hashes between repeated originals and the rebuilt executable.
Reports and videos remain under `build/runtime/`.

`game.cmd test-parity --check-fixtures` checks all permanent recording hashes and required save hashes without running games.
It is not a gameplay pass.
The new-game cases use explicit v4 control. The saved-game case uses v6 control with its strict save contract.
Both profiles suppress native timer messages and control queued paint delivery.
They use an input-relative terminal turn and preserve synchronous game-requested paints.
They compare new executions under the same profile, not historical v1 clocks or world-update counts.
The recorded messages, routes, turns, and target panels remain required.
The recordings remain unchanged. Reports keep their historical timing differences visible.
The untraced `late-game-match-2` and `new-game-15mins-in` recordings are kept locally but are not suite cases.
Paced replay of their dense mouse input would take hours. Re-record them with traces.
See the [save fixture notes](../config/harness/savegames/README.md).
Use `game.cmd test-parity --legacy` for the old same-policy v1 suite and its known repeatability failures.
An unexpected control profile still fails validation. No state alignment, pixel masks, or timing tolerances apply.

Harness runs stage only repository save fixtures pinned by `config/harness/savegames.json`.
They exclude the local runtime's `savegame` directory. Each run uses private fixture copies.
Strict human replays stage exactly the saves pinned by each recording contract.
The common pool includes the committed `late_game_match.gmx` and the local-only
`late_game_match_2.gmx` and `new_game_15mins_in.gmx` from `local/harness/savegames/`.
Its recorded input case passed three original repeat comparisons under v6 with the required observers.
See [the saved-game check record](../decomp_notes/saved_game_fixture_20260916.md).
The first rebuilt replay failed on RNG, clock, state, and image differences.
After the score-name, conversion-state, and attack-multiplier repairs, three rebuilt runs matched the three qualified originals.
All 559 inputs, 15,991 RNG records, captured clocks and state, and 3,898 image samples matched.
All 15 pair checks passed in `build/validation/late-game-suite/qualification.json`.
This qualification used fresh rebuilt runs and the earlier qualified original captures, not a fresh complete suite run.
General saved-game coverage remains unproved.

See [gameplay replay](behavior_replay.md) and [human recording/replay](human_replay.md).

## Report the result honestly

There is no automatic combined result. Record each stage's command, inputs, exit code, and report path.
Keep failures, skipped checks, unknowns, and untested areas visible.
Do not replace missing stages with older reports without clearly stating their age and source identity.

A runtime difference is not automatically a rebuilt-game defect. Original repeats can differ too.
Matching observed results does not prove complete hidden-state equality or observer neutrality.
These suites do not establish complete multiplayer, audio, cinematic, or whole-game correctness.

The latest documented work is not an all-green whole-project validation.
See [the September 15 follow-up](../decomp_notes/human_replay_followup_20260915.md) for build and replay evidence.
That work includes remaining clock and image differences and static unknowns.
A focused module audit is not a fresh whole-project function audit.

The [original-repeat investigation](../decomp_notes/original_repeatability_20260915.md) proves a replay timing limitation.
Equal input/update counters can produce different simulation time. Even equal complete RNG traces can accompany different positions.
The [repair record](../decomp_notes/replay_control_repair_20260915.md) includes the rejected v3 experiment and v4 checks.
The completed v4 suite passed both preserved input cases and the short script on the pinned executable pair.
Its report is `build/runtime/parity-v4-final-20260915/report.json`.
This is bounded controlled-input evidence, not a fresh all-green whole-project result.
