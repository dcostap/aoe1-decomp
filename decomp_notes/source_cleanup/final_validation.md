# Source cleanup final validation

## Source identity and preservation

All 225 modules completed cleanup integration at `b9835268320092cf08fbc6c5a07ac74166f15035`.
Commit `ad4fb35e6` records cleanup closure. The user authorized the following validation after that closure.
The preserved comparison build is `build/source-cleanup-20260915/preparation/baseline-build/`.
Do not overwrite that build or discard failed validation output.

## Started stages

| Stage | Command | Job | Result |
| --- | --- | --- | --- |
| Registry configuration | `python tools/validate_translation_units.py --no-build-checks` | `bg-66` | Passed, exit 0. Configuration only; no compilation or byte proof. |
| Whole-project function compilation and matching | `python tools/audit_translation_unit_functions.py --jobs 4 --output-dir build/source-cleanup-20260915/final-validation/functions` | `bg-67` | Finished with failures: 217 of 225 groups compiled; three matching regressions reported. |
| Fresh executable | `python tools/game.py build` | `bg-68` | Failed: 218 of 226 sources compiled; no linked executable. |

Both build stages started from the same integrated source state. No source change occurred between their starts.
The tools' help output was read before use.

## Remaining stages

- Read all compilation, matching, unknown, and repair results.
- Check matching ownership against the fresh function report.
- Compare executable code, data, relocations, and call targets with the preserved pre-cleanup build.
- Run linked dependency, reference, initializer, and header-emission checks against the fresh executable.
- Run all automated tests with the fresh dependency-build selection; report skipped tests.
- Run the full menu/UI and gameplay replay/parity suites against the same selected executable.
- Run applicable documented dependency probes and record broader gameplay coverage limits.

A passing registry check is not a build, matching, or gameplay result.
Record every failed, skipped, unknown, or unavailable check. Do not weaken checks or discard incident evidence.

## Terrain repair review

Root read the complete correction diff to `844478cc9dcbee7d76fe7fad87065aff3c26bd17`.
The source restores baseline parameter name `p2` and its two bound calculations.
The existing local `y` remains separate. No scope, declaration, type, or initialization changed.
This addresses C2082 by source review; successful recompilation remains unproved.

## First build failures

Preserved report: `build/executable/user/20260915T215425319815Z/20260915T215425568371Z/report.json`.
The build reports 205 unresolved symbols and 385 link errors after eight compilation failures.
Do not treat these as independent linker defects until the missing objects compile.

| Source | First error | Original owner |
| --- | --- | --- |
| `aipbook.cpp` | `j` redefinition, line 1142 | 13 |
| `Pnl_txt.cpp` | Syntax error at line 572, followed by a cascade | 17 |
| `rmm_terr.cpp` | Parameter `y` redefinition, line 313 | 02 |
| `scenario.cpp` | Repeated `player_index` declarations | 26 |
| `scr_sed.cpp` | Undeclared `v`, line 1514 | 21 |
| `taiinfmd.cpp` | Undeclared `gatherer`, line 1099 | 14 |
| `taimdmd.cpp` | `i` redefinition, line 440 | 14 |
| `tplayer.cpp` | `tech` not a member of `RGE_Game_World`, line 164 | 25 |

Root resumed the original owners and workers for minimal source repairs and report updates.
Restore baseline name bindings and distinct declarations. Do not add scopes to bypass VC5 declaration rules.
Root will review repairs and rerun validation. No failed output will be removed.
Runtime tests cannot validate this failed build. They await a fresh linked executable.

## First function sweep

The sweep includes 4,942 normal functions: 4,537 exact targets and 405 other configured functions.
Categories: 4,534 matching results, 178 accepted-drift observations, 162 new-verified-logic observations,
45 relocation problems, 13 boundary problems, seven grouped matches needing review, and three matching regressions.
Eight groups did not compile. Counts from compiled groups do not cover those missing functions.

The three reported regressions are:

- `flics`, `00449DF0 resolution`: three instruction bytes differ.
- `t_b_obj`, `004C9230 lay_down_impassable_terrain`: instruction bytes agree; referenced numeric bytes differ.
- `t_b_obj`, `004C9360 lay_down_passable_terrain`: instruction bytes agree; referenced numeric bytes differ.

All three rows record prior state `UNKNOWN`, not a prior exact pass.
Root resumed the original workers to compare the preserved baseline objects before attributing these differences to cleanup.
Do not relabel matching claims or weaken checks. Preserve both new and preexisting differences explicitly.
Job `bg-69` checks ownership against this fresh function report; compilation gaps remain part of its limits.
The ownership tool rejected that report with exit 1 because the grouped audit has compile errors.
Failure: `ValueError: .../functions/report.json: grouped audit has compile errors`.
No ownership result was established. Rerun ownership after repairs and a fresh complete function sweep.
Do not bypass this prerequisite or substitute stale per-function artifacts.
