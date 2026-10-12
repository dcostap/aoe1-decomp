# Controlled replay repeatability repair

V3 is not the final repair. The later full-suite run exposed another clock difference.
V4 controls dispatched paints. The full original/rebuilt suite now passes both preserved input cases.
Keep the successful initial V3 checks separate from its later failure.

## Change and scope

The user authorized repairs and experiments after the original-repeat investigation.
See [the preceding evidence](original_repeatability_20260915.md) for the differing 100-ms and 87-ms simulation steps.

V3 suppresses dispatched native `WM_TIMER` messages on the game thread.
This removes an uncontrolled source of idle calls with different clock effects.
The original game continues to update through its own idle paths.
No game function, simulation state, RNG result, or image is replaced to force agreement.

The stopping rule also needs a new definition because the clock history changes.
V3 requests its terminal Paint eight idle turns after the final recorded input.
This rule depends only on input metadata, not a reference run's simulation state.
The old duration remains in the fixture and capture metadata. Worker deadlines remain active.

V3 template SHA256:
`d4dbe3e19381be0af88827d80bb783027960b2d37bb2b43b430db869c9c14000`.

The original executable remains:
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.

The rebuilt executable remains:
`492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`.

## Contract distinction

The v1 recordings remain byte-for-byte unchanged:

- Accepted: `a320c5d68b8b6f2e49d5d9963e60bc3455c177deac2909d5795ab19e02510e4d`, 324 messages.
- Candidate: `60c04e651b19d144cd033ffcc5ed2bdff1bfe75629b036f493d8db497e4b832e`, 1,361 messages.

V3 uses their inputs under a new common control profile.
It does not claim to reproduce their historical v1 clock values or missing timer history.
All reports retain `same_policy_replay: false` and the exact source recording hash.
Historical input fidelity remains visible, including its clock differences.

Every new cross-run clock, state, RNG, and raw-image comparison remains exact.
No mask, tolerance, state alignment, or renamed RNG site conceals a difference.
The old same-policy suite remains available through `game.cmd test-parity --legacy`.
Replay without an upgrade flag also retains its original policy.

`--controlled` selects a declared v1-to-v3 or v2-to-v3 upgrade from the recording's actual policy.
New user recording still uses v2; v3 currently supports replay only.

## First experiment: candidate recording

Command:

```cmd
build\harness-env\Scripts\python.exe tools/harness/human_session.py --recording config/harness/human-candidate-20260915.json --target original --runs 2 --observe --combat --upgrade-v1-to-v3 --output build/runtime/repeatability-v3-no-timers-01
```

Both original runs completed. Their exact input clocks, world observations, actor observations, RNG, and raw RGB samples agree.
No intermediate v3 control-script revision was needed.

The first run suppressed 983 native timer messages.
Its terminal turn is 3,052; its terminal controlled time is 192,285 ms.
The different duration is an explicit effect of the new profile, not a reproduction of the old 180,127-ms boundary.

First comparison: `build/runtime/repeatability-v3-no-timers-01/full-comparison.json`.

## Repeated original and rebuilt checks

Three originals and three rebuilt executions completed for each recording.
Each case compares all 15 pairs, including all nine original/rebuilt pairs.
All 30 comparisons pass the exact observed-repeatability check.

| Observed field | Accepted inputs | Candidate inputs |
|---|---:|---:|
| Delivered inputs | 324 | 1,361 |
| Terminal idle turn | 622 | 3,052 |
| World updates | 332 | 463 |
| Terminal controlled time, ms | 64,877 | 192,285 |
| Complete RNG records | 1,224,968 | 3,611,285 |
| Raw RGB samples | 1,299 | 3,847 |
| Differing sample positions | 0 | 0 |
| World entry/exit observations | 664 | 926 |

Every pair also agrees on captured combat, attack-update, sprite, and available villager observations.
No villager-4969 observations exist for the candidate map; the report keeps that coverage count at zero.
Required world entry/exit observations and full RNG evidence are present for every run.
Equal RNG alone cannot satisfy the new gate.

Candidate original captures:

- `build/runtime/original-20260915T111018767511Z/capture/report.json`
- `build/runtime/original-20260915T111334199610Z/capture/report.json`
- `build/runtime/original-20260915T113043150750Z/capture/report.json`

Candidate rebuilt captures:

- `build/runtime/rebuilt-20260915T112029026210Z/capture/report.json`
- `build/runtime/rebuilt-20260915T112344392100Z/capture/report.json`
- `build/runtime/rebuilt-20260915T112659748153Z/capture/report.json`

Accepted original captures:

- `build/runtime/original-20260915T113358606567Z/capture/report.json`
- `build/runtime/original-20260915T113506436784Z/capture/report.json`
- `build/runtime/original-20260915T113614344284Z/capture/report.json`

Accepted rebuilt captures:

- `build/runtime/rebuilt-20260915T113722418723Z/capture/report.json`
- `build/runtime/rebuilt-20260915T113830620886Z/capture/report.json`
- `build/runtime/rebuilt-20260915T113938707484Z/capture/report.json`

Exact comparison reports:

- `build/runtime/repeatability-v3-rebuilt-01/all-six-comparison.json`
- `build/runtime/repeatability-v3-old-rebuilt/all-six-comparison.json`

The corresponding batch reports and videos remain in their original runtime directories.
The earlier v1/v2 failures and the preceding original-repeat experiments remain intact.

## Standard workflow

`game.cmd test-parity` now runs the short script and both v4 human-input cases.
Each case runs three originals and three rebuilt games.
The human cases require complete RNG and world entry/exit evidence and compare all captured state fields.
They also require correct input delivery and the declared terminal rule.
All 15 pairs per case must agree, including every raw RGB sample and every compared clock value.

The default report uses schema 2 and states the changed-profile scope.
The legacy same-policy recipe remains under `--legacy`.
`--check-fixtures` checks both unchanged permanent recordings without launching games.

`tools/harness/human_repeatability.py` provides the same exact pair checks for selected complete captures.
It returns failure for missing evidence or any checked difference.
It does not convert an empty state list or equal RNG prefix into a pass.

See [the testing guide](../docs/testing.md) and [human replay](../docs/human_replay.md).

## V3 full-suite failure and next experiment

The end-to-end V3 suite found a repeat difference in its accepted-original batch.
The first differing world entry is update index 1: one run has 68 extra debug-clock calls.
Both runs have the same idle-advance count, world state, and complete RNG trace.
Their first input-clock difference is input 67, at turn 292.

Captures: `original-20260915T114737001481Z` and `original-20260915T114845668373Z` beneath `build/runtime/`.
Evidence: `build/runtime/parity-v3-final-20260915/accepted-clock-difference/report.json`.
The short scripted case passed. The remaining V3 suite was stopped after this confirmed failure.
Its completed batches, logs, and partial captures remain intact; `interrupted.json` records the stop.
There is no successful end-to-end V3 suite result.

The V3 full regression run passed 791 tests and 31 subtests.
Report: `build/repeatability-v3-tests.xml`. Later changes need fresh validation.

The next hypothesis is uncontrolled queued paint delivery.
V4 suppresses queued root-window paints, acknowledges their dirty region, and sends a paint at each idle boundary.
Synchronous game-requested paints remain intact. V3 source and its hash remain unchanged.

## Remaining limits

V3 remains rejected. V4 passes the bounded cases below, not every possible game or input sequence.
It does not make the old v1/v2 timing reproducible from incomplete recordings.
Native blocking modal loops, saved-game loading, and all possible input sequences are not qualified.
A deadline failure in an unsupported case does not prove a game defect.

Observer neutrality and full hidden-state equality remain unproved.
The game executable did not change; static unknowns, untested gameplay, and source-recovery limits remain.

## V4 control and completed original checks

V4 template SHA256:
`17752944a9ed945df3a3d0e34bea6f7ac7aabbdcde68a6ae8ad0c65797c5e99e`.

The V4 policy is `human-idle20-clock1-paced-v4-controlled-paint`.
Its declared upgrades are `v1-to-v4-controlled-paint-turn-stop-20260915` and `v2-to-v4-controlled-paint-turn-stop-20260915`.
`--controlled` selects the rule for the recording's actual policy.

V4 discards dispatched root-window `WM_PAINT` messages and validates their entire dirty region.
It does not preserve partial dirty regions for later delivery.
It sends a new synchronous paint after each eligible idle, including nested idles inside input handlers.
It prevents another injected paint while one is active. Direct synchronous game-requested paints remain intact.
The hook acts at `DispatchMessage`; it does not prove that every caller obtained its message from the queue.
This is an explicit discard-and-inject profile, not a reconstruction of historical Windows delivery.

The unchanged recordings supply messages, routes, ordering, turns, and panels.
Historical clock values and world-update counts remain visible, but are not expected outputs under this new profile.
Every corresponding fresh-run clock, update count, observed state field, RNG record, and raw RGB sample must agree exactly.

Three quiet originals used the accepted recording:

```cmd
build\harness-env\Scripts\python.exe tools/harness/human_session.py --recording config/harness/human-accepted-20260914.json --target original --runs 3 --observe --combat --upgrade-v1-to-v4 --output build/runtime/repeatability-v4-paint-01
```

Captures under `build/runtime/`:

- `original-20260915T120912363619Z/capture/report.json`
- `original-20260915T121028925494Z/capture/report.json`
- `original-20260915T121145545634Z/capture/report.json`

Three more originals added explicit timer/paint queue noise every 37 wall-time milliseconds:

```cmd
build\harness-env\Scripts\python.exe tools/harness/human_session.py --recording config/harness/human-accepted-20260914.json --target original --runs 3 --observe --combat --controlled --message-noise --output build/runtime/repeatability-v4-noise-01
```

Captures under `build/runtime/`:

- `original-20260915T123125264758Z/capture/report.json`
- `original-20260915T123241790023Z/capture/report.json`
- `original-20260915T123358469755Z/capture/report.json`

Noise v1 SHA256: `865d1ba012b400b8ffe63181c1efa3bf65de186042225334cd29dd12a3ea033f`.
Its source remains in `tools/harness/human-noise-v1.js`.
The runs posted 1,970, 1,970, and 1,969 message pairs.
Their reported suppressed paint counts are 1,968, 1,968, and 1,967.
These counts did not identify the injected messages individually. Review correctly found that evidence limit.

All 15 pairs among these six originals have exact matching outputs:

- 324 delivered inputs; terminal turn 622, world-update count 333, controlled time 73,571 ms.
- 1,224,986 full RNG records; 666 world entry/exit observations.
- 1,473 raw RGB samples with zero differing sample positions.
- 368 observed paint entries with usable 8-bit surfaces; this is not every paint request.
- Equal captured combat, attack-update, sprite, and villager observations.

Report: `build/runtime/repeatability-v4-noise-01/all-six-strengthened.json`.
This records a real output match. It predates the stricter marked-dispatch requirement below.
Do not describe it as verified marked-noise delivery.

## Stronger noise evidence

Noise v2 uses unique timer/paint markers and observes them after the suppression hooks.
It requires positive suppressed-dispatch receipts for both message types, not only positive posting counts.
The checker pins noise SHA256 `ed8657ee437720d2fbe04a5fde0bb89fb187bd9bf70a42a95968e84a1c403454`.
Markers use `wParam`; `lParam` stays zero so a missed timer filter cannot call an invalid timer procedure.
Its explicit `--noise-resistance` mode requires both quiet and perturbed captures.
Same-mode pairs still check repeatability within each group. No output check changes.

The standard suite rejects noise captures. Noise is a deliberate stimulus, not a read-only observer.
Marked-noise runtime checks now pass. The earlier noise v1 reports remain unchanged.

## Completed end-to-end V4 qualification

Command:

```cmd
build\harness-env\Scripts\python.exe tools/harness/parity_suite.py --output build/runtime/parity-v4-final-20260915
```

The short scripted case and both human-input cases passed. All five worker commands returned zero.
The suite completed 18 fresh executions: three originals and three rebuilt games per case.
Each human case passed all 15 pairs, including every original/rebuilt combination.

| Exact observed field | Accepted inputs | Candidate inputs |
|---|---:|---:|
| Inputs delivered | 324 | 1,361 |
| Terminal turn | 622 | 3,052 |
| World updates | 333 | 464 |
| Terminal controlled time, ms | 73,571 | 201,430 |
| Full RNG records | 1,224,986 | 3,611,319 |
| Raw RGB samples | 1,473 | 4,030 |
| Differing raw sample positions | 0 | 0 |
| Valid-surface paint entries | 368 | 541 |

Report: `build/runtime/parity-v4-final-20260915/report.json`.
A current-gate recheck also verified the executable files for all 18 captures against both pinned hashes above.
Recheck: `build/runtime/parity-v4-final-20260915/pinned-build-recheck.json`.
Its helper remains at `build/verify_v4_suite.py`.

Original | repaired | decoded RGB difference videos:

- `build/runtime/parity-v4-final-20260915/accepted-video/original-rebuilt-difference.mp4`
- `build/runtime/parity-v4-final-20260915/candidate-video/original-rebuilt-difference.mp4`

Both videos retain every frame. The raw pre-encode hashes remain the exact image evidence.
Visual checks at accepted time 50 seconds and candidate time 160 seconds show game content and black difference panels.
These two visual checks do not replace the complete raw-hash comparisons.

The final regression run passed 817 tests and 31 subtests, with the pinned dependency build selected.
Report: `build/repeatability-v4-reviewed-tests.xml`.
The preceding 816-test pass remains at `build/repeatability-v4-final-tests.xml`.

An earlier regression attempt used a test module loaded before a concurrent noise-marker edit.
It failed one VM assertion; 814 tests and 31 subtests passed.
That mixed-source attempt remains at `build/repeatability-v4-tests.xml`. It is not a game failure or a final test result.

No game source, executable, accepted recording, or earlier policy template changed in this repair.
No fresh whole-project compiler, ownership, linked-data, or full menu sweep ran for these harness-only changes.
The earlier static unknowns and unsupported gameplay areas remain open.

## Completed marked-noise check and review

Three fresh original runs used `--controlled --message-noise --observe --combat` with the accepted recording.
Batch: `build/runtime/repeatability-v4-marked-noise-02/report.json`.

| Capture under `build/runtime/` | Posted pairs | Marked timer receipts | Marked paint receipts |
|---|---:|---:|---:|
| `original-20260915T131111424425Z/capture/report.json` | 1,968 | 1,963 | 1,963 |
| `original-20260915T131228157040Z/capture/report.json` | 1,967 | 1,962 | 1,962 |
| `original-20260915T131345059786Z/capture/report.json` | 1,967 | 1,962 | 1,962 |

All receipts observe marked messages after suppression to `WM_NULL`.
Unprocessed end-of-session messages do not count as suppression evidence.

These captures and the standard suite's three quiet accepted-original captures pass all 15 exact pair checks.
Quiet captures: `original-20260915T124247019602Z`, `original-20260915T124403555267Z`, and `original-20260915T124520333584Z`.
Each path ends in `/capture/report.json` beneath `build/runtime/`.
Their clocks, world observations, actor observations, full RNG, valid-surface paint counts, and raw RGB samples agree.
Report: `build/runtime/repeatability-v4-marked-noise-02/all-six-comparison.json`.

The read-only reviewer `sa-6cdaa4f9` reviewed the control and comparison changes through seven runs.
The review found report labels, missing V2 tests, V3 routing, historical-fidelity assumptions, and insufficient noise evidence.
The final changes address those findings and preserve the earlier failures.
Final narrow review `sa-6cdaa4f9-r7` reports `correct` with no blocking findings.
The reviewer did not launch games or run the regression suite. Runtime and test results above come from this work.

This repair fixes the demonstrated observed-repeatability failure under the declared V4 profile for both tested input cases.
It does not recover missing historical scheduling or establish complete gameplay equivalence.
