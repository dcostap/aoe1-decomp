# Civilization ID names

## Change

Add fixed-value `CIVILIZATION_*` macros in `include/tribegam.h`.
Use explicit values for the 16 known civilizations.
These are new cleanup names, not recovered original enum names.

Replace civilization literals in these source files:

- `src/scr_mps.cpp`: civilization dropdown values.
- `src/tribegam.cpp`: civilization-name switch cases.
- `src/tplayer.cpp`: civilization-specific AI setup switch cases.
- `src/tact_cnv.cpp`: Macedonian conversion-resistance comparison.
- `src/tact_trd.cpp`: Palmyran trade comparison.
- `src/tpnl_obj.cpp`: Palmyran trade-display comparison.

This report is the only new file.
The user requested the existing `include/tribegam.h` as the declaration owner.
Trade and conversion source files now include that header directly.
Existing source formatting changes in `src/scr_mps.cpp` were retained.

## Mapping and evidence

| Game ID | Constant name | Existing string resource name |
| --- | --- | --- |
| 1 | `CIVILIZATION_EGYPTIAN` | `STRING_ID_CIVILIZATION_EGYPTIAN` |
| 2 | `CIVILIZATION_GREEK` | `STRING_ID_CIVILIZATION_GREEK` |
| 3 | `CIVILIZATION_BABYLONIAN` | `STRING_ID_CIVILIZATION_BABYLONIAN` |
| 4 | `CIVILIZATION_ASSYRIAN` | `STRING_ID_CIVILIZATION_ASSYRIAN` |
| 5 | `CIVILIZATION_MINOAN` | `STRING_ID_CIVILIZATION_MINOAN` |
| 6 | `CIVILIZATION_HITTITE` | `STRING_ID_CIVILIZATION_HITTITE` |
| 7 | `CIVILIZATION_PHOENICIAN` | `STRING_ID_CIVILIZATION_PHOENICIAN` |
| 8 | `CIVILIZATION_SUMERIAN` | `STRING_ID_CIVILIZATION_SUMERIAN` |
| 9 | `CIVILIZATION_PERSIAN` | `STRING_ID_CIVILIZATION_PERSIAN` |
| 10 | `CIVILIZATION_SHANG` | `STRING_ID_CIVILIZATION_SHANG` |
| 11 | `CIVILIZATION_YAMATO` | `STRING_ID_CIVILIZATION_YAMATO` |
| 12 | `CIVILIZATION_CHOSON` | `STRING_ID_CIVILIZATION_CHOSON` |
| 13 | `CIVILIZATION_ROMAN` | `STRING_ID_CIVILIZATION_ROMAN` |
| 14 | `CIVILIZATION_CARTHAGINIAN` | `STRING_ID_CIVILIZATION_CARTHAGINIAN` |
| 15 | `CIVILIZATION_PALMYRAN` | `STRING_ID_CIVILIZATION_PALMYRAN` |
| 16 | `CIVILIZATION_MACEDONIAN` | `STRING_ID_CIVILIZATION_MACEDONIAN` |

The setup dropdown and civilization-name switch independently contain this mapping.
The AI setup switch maps the same values to named civilization setup functions.

Supporting original instruction records are:

- `inventory/functions/0052/00522930_get_string2.txt`.
  The civilization switch calls the string lookup with the corresponding resource IDs.
- `inventory/functions/0051/00515E00_intelligentBuildListAndRulesSelection.txt`.
  The civilization switch calls `setupEgyptian` through `setupMacedonian`.

These records are reference evidence. The pinned original executable remains the behavior oracle.
This change does not add a new executable comparison.

Existing string-name evidence is in `decomp_notes/source_cleanup/wave04/tribegam.md`.
It distinguishes base-language text from expansion overrides.
No string resource names or values changed here.

## Types and scope

The macros expand to the original integer values.
Existing fields remain integers or bytes. Public function signatures remain unchanged.
No enum declaration, object, array, or new runtime lookup table remains.

Dropdown calls still select `append_line(long, long)`.
The first argument remains a numeric string resource ID.
The second argument converts the integer constant to `long`.
Switch labels retain their values. Byte comparisons still use small integer values.

The change retains localization, lookup order, save fields, and network fields.
It does not rename parameters, locals, members, or functions.

## Unchanged questions

- Dropdown game ID `17` has no verified civilization name. Keep the existing literal and comment.
- Do not infer a random-choice name from the empty resource slot alone.
- Zero has context-specific uses. It is not assigned a civilization name here.
- Some AI code uses `master_player_id - 1`. Those values are indices, not these one-based IDs.
- Editor dropdowns attach zero to each entry and use line indices. They remain unchanged.
- Civilization counts, random-selection arithmetic, and setup remapping offsets remain unchanged.

## Review and validation

The complete source diff was reviewed. `git diff --check` passed.
The six source files and `include/tribegam.h` retain LF line endings.
Pre-edit source copies are under `build/civilization-id-cleanup/before/src/`.
Those copies are preparation artifacts, not a compiled baseline.

### Rejected enum version

The first version used a shared enum. The user then requested its placement in `include/tribegam.h`.
The full function audit compiled all 225 modules but returned exit code 1.
It reported 5,012 passing exact claims and one failed exact claim.
`TRIBE_Player::objectCostByType` at `00514590` differed in two bytes, despite its unchanged source body.

Report: `build/validation/civilization-ids-20261004-022558/functions/report.json`.
Command: `python tools/audit_translation_unit_functions.py --jobs 4 --output-dir build/validation/civilization-ids-20261004-022558/functions`.

An isolated VC5 build of the pre-cleanup `tplayer.cpp` matched the original function exactly.
Its function section differed from the enum version; its relocation records remained equal.
The baseline source and `tribegam.h` matched their Git HEAD blobs before this cleanup.

This confirms that the enum version introduced the exact-match regression.
Fixed-value macros avoid the added enum declarations.
The same VC5 constraint is documented in `LESSONS.md` and `decomp_notes/object_lifecycle_states.md`.

Baseline objects for the six changed source modules are under `build/civilization-id-cleanup/before/objects/`.
They use the pinned VC5 compiler and each module's configured `gx.rsp` flags.
The isolated headers retain the pre-cleanup `tribegam.h`; DirectPlay headers supply the required relative includes.

### Final macro version

The repeated full function audit returned exit code 0.
All 225 modules compiled. All 5,013 exact claims passed among 5,426 normal functions.
The remaining 413 observations include 217 logic-approved functions, 140 accepted-drift functions, 44 mismatches, and 12 boundary problems.
Those categories do not establish full original-game agreement.

Report: `build/validation/civilization-ids-macros-20261004-023233/functions/report.json`.
Command: `python tools/audit_translation_unit_functions.py --jobs 4 --output-dir build/validation/civilization-ids-macros-20261004-023233/functions`.

The six changed source modules retain identical non-debug object payloads against their isolated pre-cleanup builds.
The comparison checks section bytes, sizes, flags, relocation targets, and allocated symbol identities.
It normalizes private compiler-label serial numbers by section and offset.
It excludes debug metadata and COFF timestamps.
The comparison returned exit code 0 with zero differing objects.

Report: `build/validation/civilization-ids-macros-20261004-023233/object-comparison.json`.
Command: `python build/object-state-cleanup/compare_objects.py --before build/civilization-id-cleanup/before/objects --after build/civilization-id-cleanup/after/objects --output build/validation/civilization-ids-macros-20261004-023233/object-comparison.json`.

This object comparison covers six changed source modules, not all consumers of `tribegam.h`.
The full function audit covers all configured modules, but not every nonmatching function's pre-cleanup payload.
No separate owner audit, linked executable, automated regression tests, or gameplay tests have run.
Follow `docs/testing.md` for the separate validation stages and their coverage limits.
