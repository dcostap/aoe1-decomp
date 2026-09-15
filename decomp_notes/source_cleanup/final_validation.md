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
| Fresh executable | `python tools/game.py build` | `bg-68` | Running. |

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
