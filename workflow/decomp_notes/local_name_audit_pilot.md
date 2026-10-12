# Local-name record pilot

See [the twelve-module trial](local_name_audit_trial.md) for the broader results and the refined result categories.

## Result

The compiler-record method detected all six known `loadBuildList` name errors.
It accepted the corrected records without changing game source.
This result supports a larger trial. It does not establish whole-project coverage.

The pilot used `tools/audit_local_name_records.py` and the configured `aibldmod` module.
It compiled the normal source recipe and the same recipe with `/Z7`.
Both objects passed the original function check for all 27 configured `matching` targets.
Thus, `/Z7` preserved the checked code, boundaries, owners, and supported direct targets in this module.

| Check | Result |
| --- | --- |
| Corrected source | 98 original variable records agreed; no name conflicts |
| Old-name control | 92 records agreed; exactly six name conflicts |
| Corrected `loadBuildList` | All 15 original records agreed |
| Code check | All 27 eligible functions matched in both builds |
| Extra source record | `BuildAIModule::save` local `end` remained unknown |
| Nonmatching function | `BuildAIModule::insertItem` was not checked |
| Tool tests | 19 passed; no skips |

The 98 original records contain 47 stack locals, 24 parameters, and 27 register records for `this`.
These counts do not include source variables that lack emitted debug records.

## Method

The tool reads the pinned original executable and PDB under:

`orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/`

The configured original copies have the same SHA256 hashes as these pinned files.

It uses fresh `cvdump -s` and `cvdump -t` output, not Ghidra variable labels.
It identifies rebuilt procedures through COFF code-offset relocations and registered owning symbols.
Display names alone cannot distinguish overloaded procedures.

The tool checks names only after both compiled objects pass the existing original function checker.
It compares names and resolved type names at the same stack offset or register.
Unique records without lexical blocks qualify for comparison.
The tool leaves reused names, reused locations, unresolved types, and missing records unknown.
It also leaves extra rebuilt records without an original location unknown.

The negative control uses only the source module from commit:

`558c580857bf74d5edab3a884870db2b51c2b449`

The tool writes that snapshot under `build/` and compiles it with current headers and the configured flags.
It does not check out that revision or change the natural source owner.

## Repeat the pilot

Run the tool's `--help` first. Select a new output directory for each run.
Use an installed `cvdump.exe` path for `--cvdump`.

```text
python tools/audit_local_name_records.py --help
python tools/audit_local_name_records.py --group aibldmod --cvdump C:/path/to/cvdump.exe --output-dir build/probes/local-name-current-RUN
python tools/audit_local_name_records.py --group aibldmod --debug-source-ref 558c580857bf74d5edab3a884870db2b51c2b449 --cvdump C:/path/to/cvdump.exe --output-dir build/probes/local-name-old-RUN
```

The corrected run returned `0`. The negative control returned the expected `1` for six name conflicts.
Exit `0` means no proved name conflict. It does not mean complete name coverage.

Each run records compiler commands, source hashes, flag hashes, and the compiler hash in `builds.json`.
It records original input hashes, object hashes, and the `cvdump` hash in `report.json`.

The tested dumper was Microsoft Debugging Information Dumper `14.00.23611`.
Its local path was:

`C:/Users/Darius/AppData/Local/pi-web-smart-fetch/github-cache/isledecomp/reccmp/reccmp/bin/cvdump.exe`

## Validation artifacts

- Corrected run: `build/probes/local-name-pilot/final-current/report.json` and `report.txt`.
- Negative control: `build/probes/local-name-pilot/final-old/report.json` and `report.txt`.
- Each run's `builds.json` records its compilation details.
- Tests: `build/probes/local-name-pilot/tests.xml`.

Test command:

```text
python -m pytest -q tests/test_local_name_records.py tests/test_pdb_scoped_symbols.py --junitxml=build/probes/local-name-pilot/tests.xml
```

The command returned `0`, with 19 passed tests and no skips.
Tests cover name swaps, uncertain records, register reuse, owning relocations, extra records, and the code gate.
No full executable build, linked audit, menu test, or gameplay test ran.

## Limits and next trial

This pilot supports only `S_BPREL32` and `S_REGISTER` variable records.
It refuses procedures with lexical blocks rather than guessing their scope mapping.
Resolved type-name agreement does not prove complete structure layouts or variable lifetimes.
Original debug records supply name evidence, not a behavior oracle.
The original executable remains the code and behavior reference.

The pilot checked one module with the `gx` flag profile.
Other flag profiles, frame forms, register locals, and scope records need further trials.
Next, check a small set of modules with different flag profiles and record forms.
Keep the audit read-only. Review conflicts before any source rename.
