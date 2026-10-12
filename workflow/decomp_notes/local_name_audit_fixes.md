# Applied local-name fixes

## Result

Applied all 49 approved original-name substitutions from the [eight-function review](local_name_audit_review.md).
The changes preserve declaration positions, types, scopes, expressions, operations, and call order.
They do not repair original game behavior.

Base commit: `ab15ce4964371ad31b3308680d25c01486d8cbea`.
Source commit: `126e11eb445ead001acd8fee3201c9f2ee0c5660`.

Changed source owners:

| Source | Functions | Original-name substitutions |
| --- | --- | ---: |
| `src/aiconmod.cpp` | `loadConstructionPlan` | 8 |
| `src/com_sync.cpp` | `DoChecksum` | 3 |
| `src/m_s_obj.cpp` | `RGE_Master_Static_Object::save` | 6 |
| `src/scr_mps.cpp` | `setupSinglePlayerPlayers` | 3 |
| `src/map.cpp` | `scenario_load`, `preclean_elevation`, `load_map`, `get_border_type` | 29 |

No header, registry, compiler recipe, inventory, or unrelated source changed.
Line counts and line endings remain unchanged in all five source files.
The review remains the mapping evidence; its “current name” columns describe the pre-edit source.

## New descriptive names

These names do not come from the original PDB:

- `loadConstructionPlan`: `unused_y` frees the live coordinate's recovered `y` spelling.
- `scenario_load`: `row_index` replaces the narrowed row alias and prevents a collision with recovered column `x`.
- `load_map`: both branch-local row counters use `row_index`; the old-format column uses `column_index`.
- `RGE_Master_Static_Object::save`: `attribute_flags`, `attribute_amounts`, and `attribute_types` replace misleading attribute-array aliases.
- `preclean_elevation`: `tile_height` replaces `tile_byte`, which contains a decoded height, not the packed byte.

The original `load_map` row-name assignment remains unresolved.
The two `row_index` declarations remain separate and retain their `long` types.
The old-format `column_index` does not claim the modern-format column's original stack record.

The construction buffers remain `char[60]` and `char[260]`, with the existing `+4` buffer expressions.
The scenario counters retain their stored widths and narrow coordinate views.
The border locals retain their declarations, fallback values, helper-call order, and border-shape priority.
No edit merges source variables because the compiler reuses their storage.

## Fresh validation

Artifacts: `build/validation/local-name-fixes/`.
All checks below ran after the complete naming edit. Each command returned zero.

### Configuration

`python tools/validate_translation_units.py --no-build-checks`

Passed. This checks source and registry configuration, not executable behavior.

### Original function checks

```text
python tools/audit_translation_unit_functions.py --group aiconmod --group com_sync --group m_s_obj --group scr_mps --group map --jobs 3 --output-dir build/validation/local-name-fixes/functions
```

All five modules compiled. All 132 exact targets passed, including all eight edited functions.
The edited functions have zero byte, relocation, and boundary differences, with supported owners and direct symbols.
The report contains 152 functions: 132 exact targets and 20 other configured entries.
The latter include five accepted-drift observations, twelve behavior-recovery observations, and three grouped mismatches.
Their pre-existing original-versus-rebuilt differences remain visible; the naming edit adds no object-content differences.

Report: `functions/report.json` and `functions/report.txt`.

```text
python tools/audit_matching_owners.py --function-report build/validation/local-name-fixes/functions/report.json --output build/validation/local-name-fixes/owners.json --text-output build/validation/local-name-fixes/owners.txt
```

The scoped owner check covers 132 normal functions. It reports no duplicate owners, owner mismatches, or repair items.
This is not a whole-project owner check.

### Pre-edit versus post-edit objects

The probe compiled Git source snapshots from the base commit and the changed natural source owners.
Both sides used the current headers and each module's configured VC5 flags.
It compiled each side with normal flags and again with `/Z7`.
It compared every non-debug section, including code, data, section flags, and positional bytes.
It also compared relocation positions, types, widths, target names, and non-debug symbol definitions.
It excluded debug sections, file records, and the COFF timestamp from executable-content equality.
It did not exclude code or program-data bytes.

All ten module/profile pairs passed. Input fingerprints remained unchanged during each comparison.
This also proves unchanged module content for functions outside the eight edited targets.

Probe: `build/validation/local-name-fixes/check_objects.py`.
Command: `python build/validation/local-name-fixes/check_objects.py --output-dir build/validation/local-name-fixes/object-comparison`.
Report: `object-comparison/report.json`; build inputs: `object-comparison/<module>/inputs.json`.

### Debug-name checks

Ran `tools/audit_local_name_records.py` for each of the five modules, without reusable objects.
Each run compiled fresh normal and `/Z7` objects, then checked both against the original executable.
Each run used these arguments:

```text
--group MODULE --cvdump C:/Users/Darius/AppData/Local/pi-web-smart-fetch/github-cache/isledecomp/reccmp/reccmp/bin/cvdump.exe --output-dir build/validation/local-name-fixes/names/MODULE
```

No conflict remains in any of the five modules.
None of the eight edited functions has a conflict or different-spelling finding.
Across all five modules, original variable records contain 522 confirmations, 103 unknowns, and 33 spelling differences.
The 33 spelling differences belong to other `map` functions and remain outside this edit.

The checker still leaves type differences, reused storage, and missing records unknown.
Fresh rebuilt records show recovered `name`, scenario `x` and `y`, and border `ter_bot_lft` at the reviewed locations.
Their existing type or storage limits remain unchanged; the automatic check does not certify these four mappings.
The direct instruction review supplies that mapping evidence.
Original names remain unavailable for unrecorded descriptive aliases and optimized-out declarations.

Reports: `names/<module>/report.json`, with fresh build manifests and scoped symbol dumps in the same directories.

### Selected tool tests

```text
python -m pytest -q tests/test_local_name_records.py tests/test_pdb_scoped_symbols.py --junitxml=build/validation/local-name-fixes/tests.xml
```

Passed: 24 tests, no skips.
`git diff --check` also passed before the source commit.

## Coverage limits

No whole-project function audit, full executable build, linked audit, full test suite, or gameplay suite ran.
Local checks retain unsupported storage-reference gaps. They do not prove linked storage ownership or full game behavior.
The naming fixes are complete within the reviewed scope; unresolved original names remain unresolved.
Buffer structure, type recovery, and wider spelling-difference review need separate assignments.
