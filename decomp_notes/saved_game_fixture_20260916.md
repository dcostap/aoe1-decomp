# Saved-game fixture and original replay checks

## Inputs

The user supplied a saved game from a local installed game.
The repository copy is `config/harness/savegames/late_game_match.gmx`.
It has 875,400 bytes and SHA-256:

`fccd0ca0ccd98a6658a1eeb3b306c89afee3af9caf58ab518ee04eae434687f4`

The copy has the same bytes as the supplied file. Renaming did not change its contents.
`config/harness/savegames.json` pins the name, size, and hash.

Harness staging excludes the local runtime's whole `savegame` directory.
Each run receives private copies of the repository fixtures.
Normal original and rebuilt launches retain their local-save behavior.
New human profiles check the complete save set before game startup.
Their replay contracts include save names and hashes.

The v5 recorder permits loading saves and retains the serialized input scheduler.
Controlled replay uses v6, with the existing controlled-paint timing rules.
Frozen v1 through v4 scripts and permanent new-game recordings remain unchanged.
`tools/harness/human-v2-core.js` preserves the old core for v2 through v4.

## User recording

The recording completed with exit zero:

`build/runtime/human-20260915T235758336638Z/report.json`

Its unchanged repository copy is `config/harness/human-late-game-match.json`.
Recording SHA-256:

`07f2a4900af0f0c769224f1c9d5c9f561fce7d2aff16cdfdcaf300797f0fb5a6`

The recording contains 559 messages over 180,027 controlled milliseconds.
It reached `Game Screen` through `Load Saved Game Screen` and observed 335 world updates.
Its only starting save was `savegame/late_game_match.gmx`.
The recording report contains no errors.

This establishes that the pinned original loaded this fixture during the recorded session.
It does not establish general save compatibility or replay repeatability.

## First three original replays

Command:

```cmd
build\harness-env\Scripts\python.exe tools/harness/human_session.py --recording build/runtime/human-20260915T235758336638Z/recording.json --target original --runs 3 --observe --controlled --output build/runtime/late-game-match-original-repeat
```

The command completed with exit zero. All three sessions completed.
Batch report: `build/runtime/late-game-match-original-repeat/report.json`.

The strict comparison completed with exit one:

`build/runtime/late-game-match-original-repeat/repeatability.json`

All three pairs matched these observations:

- All 559 input messages and exact delivery boundaries.
- All captured state observation sequences and camera observations.
- Complete RNG streams of 15,991 records.
- All 3,898 sampled image hashes.
- Terminal turn 908, 343 world updates, and controlled time 194,827 milliseconds.
- Paint count 380.

The strict checker still failed every pair.
Every run contained 686 world entry/exit observations with `clock_counts: null`.
The selected `--observe` mode did not enable clock-call counters.
The checker requires those counters and reported incomplete world evidence.

This failure identifies missing evidence, not an observed difference between the three games.
Do not replace the failed result with a pass based on the equal fields.

## Follow-up with required counters

The follow-up command adds the existing `--combat` observer mode, which enables the required clock-call counters:

```cmd
build\harness-env\Scripts\python.exe tools/harness/human_session.py --recording config/harness/human-late-game-match.json --target original --runs 3 --observe --combat --controlled --output build/runtime/late-game-match-original-repeat-clock-counts
```

The follow-up completed with exit zero. All three sessions completed.
The strict comparison also completed with exit zero:

`build/runtime/late-game-match-original-repeat-clock-counts/repeatability.json`

All three pair comparisons passed. The checker found no missing required evidence.
All 559 messages, captured state sequences, clock counters, and terminal observations matched.
Complete RNG streams contained 15,991 records. All 3,898 sampled image hashes matched.
Each run ended at turn 908, with 343 world updates and controlled time 194,827 milliseconds.

This establishes observed repeatability for this saved-game case under the specified original executable and v6 profile.
It does not establish rebuilt-game parity or general saved-game compatibility.
Do not compare observations across these two different observer modes as an exact repeatability check.

## One rebuilt replay

The requested single rebuilt replay completed with exit zero and no capture errors.
Command:

```cmd
build\harness-env\Scripts\python.exe tools/harness/human_session.py --recording config/harness/human-late-game-match.json --target rebuilt --runs 1 --observe --combat --controlled --output build/runtime/late-game-match-rebuilt-once
```

Selected build:

`build/executable/user/20260915T234255221453Z/20260915T234255452378Z/empiresx.exe`

EXE SHA-256: `89b915577280d7dfe57ad5098a08195495d3ac33b8e1cc5cfc823b13881fdc8b`.

The strict comparison against the first qualified original completed with exit one:

`build/runtime/late-game-match-rebuilt-once/original-comparison.json`

Required evidence was present. The comparison found differences, not missing evidence.
All 559 message parameters, routes, idle turns, update counts, and target panels matched.
Camera values also matched. Input clock values, captured state, RNG records, and image hashes differed.

The first RNG record difference was index 1,593. Both values were 2,158, but their caller identities differed:

- Original: `stat_obj.cpp`, line 387.
- Rebuilt: `tplayer.cpp`, line 607.

The complete RNG counts were 15,991 and 15,541.
The first world observation difference appeared at update 23 on exit: RNG counts 1,604 and 1,602.
That observation still had equal clock values and clock-call counters.
The first input clock difference appeared at message index 222, with rebuilt time two milliseconds greater.
The first sampled image difference appeared at video time 9,600 milliseconds.
Video samples compare timestamps, not necessarily equal simulation boundaries.

Both runs ended at turn 908 with 343 updates.
Their controlled terminal times were 194,827 and 192,933 milliseconds.
Their terminal world times matched, but registration counters differed: 7,477 and 7,472.
These registration counters are not live-object counts.

The cause remains unresolved. One rebuilt run does not establish rebuilt repeatability.
Inspect the first RNG caller difference before attributing later clock and state differences to a specific function.

The comparison video is `build/runtime/late-game-match-rebuilt-once/original-rebuilt-diff.mp4`.
Its three columns show the original, rebuilt, and absolute decoded-video difference.
It aligns video timestamps without correcting timing differences. It holds the shorter video's final frame at the end.
Compression can affect the difference view. Use the recorded raw-image hashes for exact image checks.

### Follow-up observations

The user reported animation-frame timing differences near video time 25 seconds, followed by score-number differences.
These remain separate from the missing player-name defect in `reset_score_display`.

The first broad original trace records an object registration at RNG position 1,593:

- Turn 588, update counter 22 before the update returns, controlled time 23,779 milliseconds.
- Object ID -2,440, master ID 112, owner 5, state 2, and zero hit points.
- Position approximately `(120.9400253, 156.2959900, 0)`.

The `stat_obj.cpp:387` RNG call occurs in `RGE_Static_Object::recycle_in_to_game`, after player registration.
This gives a specific creation path to inspect for the first RNG difference.
It does not yet prove which creation the rebuilt game omitted or changed.
The rebuilt capture used combat observers and has no corresponding broad registration trace.

### Missing score name repaired

`reset_score_display` incorrectly reused the first sorted player's communication ID for the slow-player indicator.
The original uses a separate `low_fps_player` local. The source now does the same.
See [the function repair record](functions/0049/0049B080.md) for original offsets, preserved experiments, and validation.

The repaired build has SHA-256 `49fbdffbabea745ca3088cf1b9047c7cca6e46ece0ab3fad29b693b4f69d9176`.
One full replay completed at `build/runtime/late-game-match-score-label-repair/report.json`.
The rebuilt frame at 20 seconds now shows `You: 1047/1047`.
The first remaining raw-image sample difference moved from 9.60 seconds to 25.35 seconds.
All samples through 25.30 seconds match the original.
The first RNG difference remains record 1,593. The full replay comparison still fails.
This confirms the name repair without treating the later animation and score differences as resolved.

## Other validation and limits

The final focused Python harness tests passed: 207 tests, no failures.
Report: `build/validation/save-fixtures/final-tests.xml`.
The earlier 206-test run remains at `build/validation/save-fixtures/tests.xml`.
The private new-profile recording smoke check also completed with exit zero:
`build/runtime/save-fixtures-smoke-record/report.json`.

No fresh compiler, registry, linked-image, or whole-game validation ran for these harness changes.
The single rebuilt runtime check used the selected existing build above.
No new saved-game case was added to the standard parity suite.
The fixture and input sequence remain available for further tests.
Observer neutrality and complete hidden-state equality remain unproved.

## Conversion-state repair

Further traces identified the first missing object as a priest's conversion flare.
`TRIBE_Action_Convert::update` exchanged the handlers for states 4 and 11.
The original sends successful target movement to turning. The rebuilt sent it to idle.
The repair exchanges two case labels in `src/tact_cnv.cpp`.
See [the function record](functions/004C/004CE070.md) for table evidence, preserved experiments, and checks.

The repaired build has SHA-256 `ae978c1c90c3f052f43d81636f4d82d6931aa9473845d049053020717a43ac36`.
The complete replay preserved all 559 inputs. It matches all three qualified originals on RNG, clocks, and captured state.
All 15,991 RNG records now match. Terminal time is 194,827 milliseconds in both games.

Strict comparison still fails on images alone:
`build/runtime/late-game-match-conversion-state-repair/original-comparison.json`.
Images match through 186.30 seconds. The final 171 samples differ, starting at 186.35 seconds.
The selected chariot archer shows 59/106 versus 63/106 HP at 187 seconds.
The existing state observers do not cover every object's health. This remaining difference needs a separate investigation.

Updated video:
`build/runtime/late-game-match-conversion-state-repair/original-rebuilt-diff.mp4`.
Columns remain original, rebuilt, and absolute decoded-RGB difference. Video timestamps remain unchanged.

The build, both module audits, and 24 focused tests passed.
The image audit still has two failures in `0043E9E0` and 47,025 unknown checks, as before this repair.
No fresh whole-project function audit or standard gameplay suite ran for this repair.

## Final observed agreement after the damage repair

The remaining health difference came from `RGE_Combat_Object::calc_attack_modifier`.
The original returns the constant `1.0f`. The rebuilt read an unsupported global that contained zero.
The same arrow therefore removed five HP in the original, but only the minimum one HP in the rebuilt.
The repair returns `1.0f` and removes the global from `src/com_obj.cpp`.
See [the damage repair record](functions/0042/0042FC90.md) for probes, compiler checks, and affected neighbors.

Final build:
`build/executable/user/20260916T072045320101Z/20260916T072045549187Z`.
EXE SHA-256: `077510c454635f7b29cb3bfda740c2a853936c843e7a5e09ac7980958d76b98c`.

The final replay completed with exit zero:
`build/runtime/rebuilt-20260916T072231103495Z/capture/report.json`.
The strict comparison with all three qualified originals also completed with exit zero:
`build/runtime/late-game-match-both-gameplay-repairs/original-comparison.json`.
All six pairs passed. Required evidence was present in every pair.

The final rebuilt run matches:

- All 559 message parameters, routes, input boundaries, and target panels.
- All 15,991 RNG records and caller identities.
- All captured clock counters, state sequences, camera values, and terminal observations.
- All 3,898 raw RGB image sample hashes.
- Terminal turn 908, update count 343, and controlled time 194,827 milliseconds.

The encoded video hash also equals the original:
`7cbfb7f8d161166942014bd2397545d1d3b7815544c8ff978d947b1703647c63`.
The new comparison video is:
`build/runtime/late-game-match-both-gameplay-repairs/original-rebuilt-diff.mp4`.
Its columns show original, rebuilt, and decoded-RGB difference at unchanged timestamps.

Validation stages remain separate:

- Both gameplay repairs have preserved baseline and repair states with fresh module audits.
- Both target code checks pass. No exact neighbor lost its match.
- The final executable build passed.
- All 233 focused regression and harness tests passed without skips.
- The final image audit still fails two existing checks in `0043E9E0`; 47,024 checks remain unknown.
- No fresh whole-project function audit or standard gameplay suite ran.

Test report: `build/validation/late-game-drift/final-tests.xml`.
Image audit: `build/validation/late-game-drift/final-build-dependencies`.

At this checkpoint, only one final rebuilt replay had run. Rebuilt repeatability remained untested.
The later suite qualification below supersedes that limit for this recording.
This result establishes observed agreement for the pinned recording, not complete hidden-state equality or observer neutrality.

## Permanent suite integration and repeat qualification

`game.cmd test-parity` now includes `late-game-match` by default.
The suite runs three originals and three rebuilt games for this case and checks all 15 pairs.
It uses v6 control for this v5 recording. The two existing v1 recordings still use v4 control.
The recording and save hashes remain unchanged. No timing tolerance, image mask, or state alignment was added.
`--check-fixtures` now checks all three recordings and the saved-game inputs before any game starts.

Three fresh rebuilt runs completed against the selected repaired executable:

- `build/runtime/rebuilt-20260916T082233210934Z/capture/report.json`
- `build/runtime/rebuilt-20260916T082551800754Z/capture/report.json`
- `build/runtime/rebuilt-20260916T082910404262Z/capture/report.json`

Batch: `build/runtime/late-game-match-suite-qualification/report.json`.
The executable remains SHA-256 `077510c454635f7b29cb3bfda740c2a853936c843e7a5e09ac7980958d76b98c`.
No new game-source edit or executable build was needed for this suite change.

The suite's `controlled_result` compared these runs with the three previously qualified originals.
Those original captures came from `build/runtime/late-game-match-original-repeat-clock-counts/report.json`.
They were not rerun for this suite change.
All 15 pairs passed, including the three rebuilt-repeat pairs and all nine cross-build pairs.
Report: `build/validation/late-game-suite/qualification.json`.
This establishes observed repeatability and cross-build agreement for this recording under the pinned v6 profile.
General saved-game compatibility, complete hidden-state equality, and observer neutrality remain unproved.

All 258 focused regression and harness tests passed without skips.
Report: `build/validation/late-game-suite/final-tests.xml`.
Tests cover default inclusion, six saved-case runs, both control profiles, save preflight checks, and all-pair failure handling.
The fixture-only command also passed. `git diff --check` passed.
The complete 24-execution suite was not rerun. Existing-case dispatch was tested without starting those games.
The earlier image-audit failures and unknowns remain separate; this suite change did not rerun or resolve that audit.

### Why local code checks missed the defects

The conversion handler instructions matched, but their following switch-table mapping did not.
The damage multiplier load also matched, but its operand selected zero-filled storage instead of the original constant.
The broader image audit reported unsupported checks as unknown for these cases.
We relied too much on local code matches without proving their data dependencies.
The linked-data regressions now check these exact table meanings and the loaded float value.
They do not extend the general static checker to every unsupported switch or mutable data reference.
