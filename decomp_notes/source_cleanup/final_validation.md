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
| Whole-project function compilation and matching | `python tools/audit_translation_unit_functions.py --jobs 4 --output-dir build/source-cleanup-20260915/final-validation/functions` | `bg-67` | Running. |
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
