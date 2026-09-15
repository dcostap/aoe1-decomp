# Source cleanup final validation

## Source identity and preservation

All 225 modules completed cleanup integration at `b9835268320092cf08fbc6c5a07ac74166f15035`.
Commit `ad4fb35e6` records cleanup closure. The user authorized the following validation after that closure.
The preserved comparison build is `build/source-cleanup-20260915/preparation/baseline-build/`.
Do not overwrite that build or discard failed validation output.

## Started stages

## First automated test result

The full suite finished with five failures, 812 passes, and 31 passing subtests.
All five failures assert literal source text containing names changed by the reviewed cleanup.
Root inspected the current expressions: constants, operand order, pointer source, and mouse flags remain present.
Root updated only the expected names in three test files. Both minimap functions still receive separate checks.
No arithmetic assertion, forbidden-pointer assertion, or mouse flag check was removed.
Job `bg-78` reruns those three test files; full-suite rerun remains required after final repairs.
The focused rerun passed all 13 tests with exit 0. This does not replace the full-suite rerun.
The failed full-suite report remains at `build/source-cleanup-20260915/final-validation/tests-r2.xml`.

The second executable build passed: 226 sources compiled, one assembly source assembled, and the executable linked.
It reports zero unresolved symbols and zero link errors.
Fresh build: `build/executable/user/20260915T220344905797Z/20260915T220345159683Z`.
Prepared runtime: `build/runtime/rebuilt-20260915T220549867370Z`.
This establishes compilation and linking, not baseline equality or gameplay correctness.

- `bg-75`: linked dependency audit, output `build/source-cleanup-20260915/final-validation/dependencies-r2`.
- `bg-76`: full `pytest -q`, with `AOE_DEPENDENCY_BUILD` selecting that fresh build.
- Test XML: `build/source-cleanup-20260915/final-validation/tests-r2.xml`.

After all eight compilation repairs were integrated, root started fresh validation at `7f1921ab2`:

- `bg-73`: `python tools/game.py build`.
- `bg-74`: full function sweep with four jobs, output `build/source-cleanup-20260915/final-validation/functions-r2`.

The first failed build and function sweep remain preserved. Matching investigations continue separately.

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

## Player, panel, and playbook repair reviews

Root read the complete source and report diffs for three more repairs:

- `1953268e130706baed7571562121091b00f89d9c`: `tplayer` restores `gworld->tech`, preserving the constructor parameter binding.
- `ba4972d9c8bf7b7a0bf38fbf370a9c9c65f1cb44`: `Pnl_txt` removes the extra closing brace introduced before `else`.
- `d8b4ba8c98deb1082b494284e5e1e806114caffa`: `aipbook` restores distinct baseline loop names `iGroups` and `iPhases`.

These repairs add no new scopes, types, or storage. The brace repair restores the baseline structure.
Post-repair compilation remains pending. The initial source review did not detect these defects.

## Remaining compilation repair reviews

Root read the full source and report diffs for the remaining four failed modules:

- `c5643d7d6695277939871f4ea66dfd0146f0a337`: scenario load/save loops restore distinct baseline names.
- `cc6944dbd83e2404f648f293a41fcf2c7d74df8a`: editor `set_player` restores its complete baseline `v` binding.
- `07e1b741fbd7c60b18c7de222af7ad6f5d28decc`: AI lookup uses `gathererObj`; diplomacy loops restore `neutralPlayer` and `target`.

The repairs preserve declarations, scopes, types, and statement order. They do not establish successful compilation until rerun.

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

## Building terrain mismatch: preexisting finding

Owner 15 reports identical preserved-baseline and fresh object section payloads for both building terrain functions.
The original references approximately `0.01f`; the baseline source uses `10.0f` in four boundary calculations.
The proposed repair is preserved at `a3df10dbb731d5947f7f4c4ced4ac26dafcae09d` and is not integrated.
Root inspected its four operand replacements. They change baseline program behavior, unlike a cleanup repair.
Keep this finding separate from cleanup-induced drift and retain the unchanged baseline during comparison.
Root requested precise relocation and referenced-data evidence, since section-payload equality alone does not prove dependency equality.
The matching claims remain failed; no status was relabeled and no check was weakened.
Owner 15 supplied complete object evidence: baseline and fresh objects differ only at COFF timestamp bytes 4–5.
Baseline `baseline-build/t_b_obj.obj` SHA256: `f947d6502ab18511cc198bcd66e9220497daeba8aedf59147b8171d4675de4c1`.
Fresh `functions/objects/t_b_obj.obj` SHA256: `afe090cfc6825036f15a3eed846ee93f7ba72ead92237543f40039f58848d400`.
Both paths are relative to `build/source-cleanup-20260915/preparation/` and `build/source-cleanup-20260915/final-validation/`, respectively.
Target section hashes are `419b8bd99b9bb42dda1dc983843d7d165b89919c10ecc75f0744676d13ac96db` and `0e39196495add7321b3a34ce85fdb7beee4bbc72f8706d7be046c1029dcdb9ed`.
Both objects have identical relocations at offsets 64 and 98 to `$T37030`, section 32, offset 4.
That target contains `00002041` (`10.0f`) in both objects.
Original address `005749F0` contains `0ad7233c`, approximately `0.01f`.
Original references occur at `004C926E`, `004C9290`, `004C939E`, and `004C93C0`.
This evidence establishes that these two mismatches predate cleanup. The separate proposed repair remains uncompiled and unverified.

## AI learning storage repair

Root read the complete correction to `c35a112b7e8410b0dafa2a0609bc2b6686965145`.
Cleanup added a distinct `numMemoriesToLoad` local in `loadLearnInfo`, enlarging the frame from `0x34` to `0x38`.
The preserved baseline uses the existing `numToLoad` storage for both counts.
The repair removes only the added declaration and restores its three uses to `numToLoad`.
This is a cleanup-induced storage change, not a preexisting mismatch. Earlier source reviews failed to detect it.
Post-repair compilation and matching are required before calling the regression resolved.
Focused job `bg-80` passed: the module compiled and all 99 exact targets returned matching results.
The `loadLearnInfo` matching regression is resolved in this focused object check.
Other results remain: four boundary problems, four relocation problems, and one grouped match needing review.
Report: `build/source-cleanup-20260915/final-validation/taiinfmd-repair/report.json`.
A fresh full build, linked audit, and whole-project rerun still remain necessary.

## Flic resolution drift investigation

Owner 20 confirmed baseline bytes `0fbf41100fbf4912c1e0100bc1c3` versus fresh bytes `0fbf41120fbf4910c1e1000bc1c3`.
The compiled load order changed although the resolution expression retained its tokens.
The proposed operand-swap experiment is preserved at `e131991a70833bb256e1f20e6e5e5d972a152577` and is not integrated.
Root requested a cause-focused correction that retains baseline expression order, rather than an uncompiled scheduling workaround.
The worker will inspect baseline physical-line formatting and compiland changes before proposing the next repair.

## Fresh linked dependency failures

The second-build dependency audit reports 7,758 passes, two failures, and 47,025 unknowns.
Both failures are in `0043E9E0 THelpDialog::setup_help`, at relative instruction offsets 246 and 255.
The audit reports `width` and `xPosition` direct call targets in the opposite order from the original.
The preserved earlier dependency result had 7,760 passes and zero failures, with the same unknown count.
Root resumed Owner 10 and the original `dlg_help` worker to compare source forms and preserved objects.
Do not dismiss this as harmless arithmetic commutation: call order is part of the cleanup contract.
Report: `build/source-cleanup-20260915/final-validation/dependencies-r2/checks.csv`.
No linked-equivalence pass is established while these failures remain.

## Second function sweep

All 225 groups compiled. The sweep includes 5,426 normal functions and 4,965 exact targets.
It reports 4,961 matching results and four matching regressions.
Other categories: 208 accepted-drift observations, 177 new-verified-logic observations,
50 relocation problems, 18 boundary problems, and eight grouped matches needing review.

The earlier three failures remain. The newly compiled `taiinfmd` adds `004E1260 loadLearnInfo` as a matching failure.
That row also had prior state `UNKNOWN`. Root resumed the original worker for preserved-baseline comparison.
Job `bg-77` reruns ownership against this fully compiled report, with output `owners-r2.json` and `owners-r2.txt`.
The compilation failures are resolved in this run; matching and linked failures are not resolved.
Ownership job `bg-77` completed with exit 0 across 4,965 normal functions.
It found zero owner mismatches and zero class/free mismatches. Its repair queue still contains four entries.
This establishes the reported ownership checks, not matching equality or gameplay correctness.

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
