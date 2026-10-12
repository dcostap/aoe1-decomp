# Replay capture checkpoints: 2026-09-14

## Result

Replay now compares named full game-client captures as a separate check.
It preserves typed state, input receipts, and complete RNG comparison.
No original output enters rebuilt execution.
The menu suite retains its gameplay guards.

The default checkpoints use world-update counts 1, 10, and 30.
Capture uses the first following Paint entry and records the actual update count.
The final checkpoint stops the game thread after capture.
The default qualification reached exactly 1, 10, and 30 in every run.
The final three-repair batch passes state, input, full RNG, and all three capture checks.
Each executable repeats across three runs.
Final report: `build/runtime/replay-20260914T181404882462Z/report.json`.

The three game-source repairs are:

- `src/rmm_dbct.cpp`: reset the prior-land scan to its fixed first record.
- `src/tworld.cpp`: restore the three-tile destructible search around buildings.
- `src/scr_game.cpp`: select text drawing for the five labeled game buttons.

All source repairs have isolated baseline and candidate records, plus exact-neighbor checks.
No registry status changes.
The final rebuilt EXE SHA256 is `3fc9498f4005f783bd337c47b6ebcb2bb7163e1efafcc078e4742b2f1687faf8`.
Build report:
`build/replay-repair-worktree/build/executable/replay-all-three-repairs/20260914T181201784781Z/report.json`.

## Earlier capture qualification

Report: `build/runtime/replay-20260914T175343654159Z/report.json`.
Three originals repeat, including all three images.
Three rebuilt games also repeat, including all three images.
The complete RNG traces agree across executables after the land-scan repair.
State comparison still finds object counter 5763 versus 5759.
All three cross-build images differ. Neither comparison hides the other.

The starting image shows an object difference near the town center.
The rebuilt image also lacks the original Diplomacy, Menu, S, and question-mark buttons.
These are visible findings, not yet source-level diagnoses.
The last image shows the same black world view in both runs after the scripted camera pan.
The interface difference remains visible there.

Cross-build image directory:
`build/runtime/replay-20260914T175343654159Z/captures/`.
Each checkpoint has original-left and rebuilt-right images plus a raw difference image.

Ten parallel originals also pass all state, input, RNG, and capture repeatability checks.
Ten parallel rebuilt games pass the same checks within their group.
The stress reports are:

- `build/runtime/replay-repeat-20260914T175616991461Z/report.json` (original).
- `build/runtime/replay-repeat-20260914T175707544151Z/report.json` (rebuilt).

## Object-counter investigation

Object-setup report: `build/runtime/replay-20260914T174336218478Z/report.json`.
The observed setup IDs and coordinates agree before the counter difference.
The counter difference alone does not prove missing objects.

Registration report: `build/runtime/replay-20260914T174748508733Z/report.json`.
The first registration ordering difference occurs at ordinal 5241.
The original stack includes `set_sleep_flag`, `destroy_obj`, and `TRIBE_World::check_destructables`.
It occurs during building setup and random-map object placement.
These stack names guide investigation; they do not prove the faulty source owner.
The first land-placement repair remains documented in `functions/0048/00483600.md`.

The original clearance constants are `+3.0` and `-3.0`, not the source's half-tile bounds.
Restoring the three-tile search makes state, input, and full RNG checks pass in three runs per executable.
Report: `build/runtime/replay-20260914T180858514831Z/report.json`.
All three capture checks still fail because the game buttons remain missing.
This directly qualifies capture detection after the existing checks pass.
See `functions/0052/0052EAC0.md` for the source and byte evidence.

## Capture-only defect

Original `00494678`, `0049472E`, and `0049479C` pass drawing mode 3, or `DrawText`.
The source used `DrawPicture`, or 2, at all three calls.
The first call configures three buttons; the other calls configure S and question-mark buttons.
Restoring text drawing makes every capture agree without changing state or RNG results.
See `functions/0049/00493D60.md` for the experiment records.

The final images appear under:
`build/runtime/replay-20260914T181404882462Z/captures/`.
The final checkpoint uses frame 61, beyond the forty auxiliary-frame limit.
Checkpoint capture therefore does not depend on that earlier diagnostic limit.

## Final validation

- Full Python suite: 574 tests and 31 subtests pass.
- Saved recording replay: three originals and three rebuilt games pass every check.
  Report: `build/runtime/replay-20260914T181616875851Z/report.json`.
- Final rebuilt stress group: ten parallel runs pass, including all captures.
  Report: `build/runtime/replay-repeat-20260914T181552137143Z/report.json`.
- The original ten-run capture stress group also passed; its executable and capture script remain unchanged.

An earlier full test run found a documentation policy failure in numeric `--jobs` examples.
The examples now use the command's default concurrency. The full suite then passed.
No test policy was weakened.

The 41-case menu suite passed after capture integration with the land-scan repair.
Report: `build/runtime/ui-main-menu-20260914T180209751098Z/report.json`.
The final three-repair menu rerun stopped when the disk filled up.
Its log is `build/runtime/ui-main-menu-20260914T181426499407Z.log`.
That run is incomplete, not a final menu-suite pass.
The gameplay replay and Python results above completed before that storage failure.

Use targeted tests during development and three runs per executable for normal repeatability checks.
Reserve larger parallel stress groups for a specific need, not routine validation.

## Coverage limits

Capture includes game surfaces and visible native edit controls, not desktop pixels or Windows window borders.
It does not inspect every world object or every simulation field.
Equal captures cannot prove hidden-state equivalence.
Old recordings retain their frozen scenarios. Script-contract changes can make old recordings incompatible.
No mismatching capture receives a tolerance, mask, or updated expected image.
Comparison uses exact RGB pixels and image dimensions. It does not compare unused palette entries.
