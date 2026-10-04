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

## First-pass limits

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

## Follow-up: remaining civilization values

The follow-up starts from commit `4543b1f805e995f5def9ed26bb235faf7ce210c9`.
It changes these files:

- `include/tribegam.h`: Gaia ID, playable range, and playable count.
- `src/tribegam.cpp`: defaults, range bounds, random selection, and computer-name reset count.
- `src/tplayer.cpp`: zero-based AI comparisons and legacy civilization-string arithmetic.
- `src/scr_mps.cpp`: random selection, defaults, cached-selection sentinel, and shared-color offset.
- `src/scr_sed.cpp`: first playable civilization when cycling editor players.
- `src/scr_trb.cpp`: the information screen's independent button indices and count.
- `src/tworld.cpp`: Gaia's master-player index and civilization argument.
- This report: evidence, limits, and validation results.

All new names are cleanup names. No new header, enum declaration, function, or runtime table is added.

### Additional values and evidence

| Name or expression | Value | Evidence and role |
| --- | --- | --- |
| `CIVILIZATION_GAIA` | 0 | `TRIBE_World::setup_gaia` selects master player zero and passes zero as `m_player_id`. |
| `CIVILIZATION_FIRST` | 1 | The constructor and random selection start the playable range at Egyptian. |
| `CIVILIZATION_LAST` | 16 | The constructor wraps after Macedonian; new-game setup rejects larger civilization values. |
| `CIVILIZATION_COUNT` | 16 | Random selection uses modulus or multiplication by 16 for the playable range. |
| `CIVILIZATION_* - 1` | 0 through 15 | The AI first subtracts one from `master_player_id`. Named comparisons retain its eight selected values and order. |
| `MP_SETUP_SHARED_COLOR_OFFSET` | `0x32` | Ready player slots with equal colors copy civilization and team values with an added offset of 50. |
| `MP_SETUP_NO_CIVILIZATION_SELECTION` | 0 | `myCivilization` starts or resets to zero; `fillPlayers` ignores that cached selection at zero. |

Gaia uses the same master-player ID field as playable civilizations, but it is not part of their count.
Other zero values are not automatically Gaia IDs. Scenario defaults and player slots retain their existing meanings.

The information-screen order is independent of the game ID order:

| Button index | Local name | Existing text |
| --- | --- | --- |
| 0 | `TRIBE_INFO_ASSYRIAN` | `Assyrian` |
| 1 | `TRIBE_INFO_BABYLONIAN` | `Babylonian` |
| 2 | `TRIBE_INFO_EGYPTIAN` | `Egyptian` |
| 3 | `TRIBE_INFO_GREEK` | `Greek` |
| 4 | `TRIBE_INFO_HITTITE` | `Hittite` |
| 5 | `TRIBE_INFO_ISREALITE` | `Isrealite` |
| 6 | `TRIBE_INFO_MINOAN` | `Minoan` |
| 7 | `TRIBE_INFO_PHOENICIAN` | `Phoenician` |
| 8 | `TRIBE_INFO_SUMERIAN` | `Sumerian` |

`TRIBE_INFO_COUNT` remains 9. Existing text, including the spelling `Isrealite`, remains unchanged.
The screen's row-wrap tests remain numeric layout indices. They do not test game civilizations.

Supporting original instruction records are:

- `inventory/functions/0052/0052E920_setup_gaia.txt` for Gaia setup.
- `inventory/functions/004A/004A37D0_fillPlayers.txt` for the offset addition and removal.
  Instructions at `004A38C9` and `004A38E5` add `0x32` before the civilization and team setters.
- `inventory/functions/004B/004B8070_tribeName.txt` for the independent button-to-name mapping.
- `inventory/functions/004B/004B7F70_fillTribeText.txt` for the matching information-text mapping.
- `inventory/functions/0051/00515E00_intelligentBuildListAndRulesSelection.txt` for the AI's zero-based comparisons.

The AI log lookup's original base `0x27F6` equals `STRING_ID_CIVILIZATION_EGYPTIAN - 1`.
The named expression preserves this legacy arithmetic lookup.
It does not replace it with the expansion's separate name mapping.
The existing comments described a missing player-name range; the call uses civilization IDs instead.
The comments now describe the arithmetic lookup and the separate expansion IDs.
The first-pass resource evidence above establishes the named base and expansion resource values.

### Follow-up limits

Stored fields, public interfaces, comparison operators, expression order, and random-call counts remain unchanged.
The computer-name reset loop still covers indices 0 through 15. It does not expand to all 18 stored rows.
ID 17 and its empty label remain unnamed. No random-choice label is inferred from missing text.
One-based conversion expressions such as `i + 1` or `master_player_id - 1` remain where their role is already clear.
Data-loaded technology effects, visual culture IDs, player-slot numbers, and Boolean random-selection flags remain separate.
This is a source-wide review of the named civilization paths, not proof that every possible numeric alias was identified.

### Follow-up baseline

Before editing, all 225 current input fingerprints matched the first-pass final audit.
The check used `build_input_manifest` with each recorded source, flag profile, and the pinned toolchain.
No baseline fingerprint differed.
Thus, `build/validation/civilization-ids-macros-20261004-023233/functions/objects/` supplies the compiled pre-follow-up baseline.
Pre-edit copies of changed sources and `tribegam.h` are under `build/civilization-id-followup/before/`.

### Follow-up validation

The full function audit returned exit code 0.
All 225 modules compiled. All 5,013 exact claims passed among 5,426 normal functions.
The remaining 413 functions retain the first-pass categories and their existing coverage limits.

Report: `build/validation/civilization-ids-followup-20261004-024848/functions/report.json`.
Command: `python tools/audit_translation_unit_functions.py --jobs 4 --output-dir build/validation/civilization-ids-followup-20261004-024848/functions`.

The full before/after object comparison returned exit code 0.
All 225 objects retain identical non-debug section bytes, sizes, flags, relocation targets, and allocated symbol identities.
The comparison normalizes private compiler-label serial numbers by section and offset.
It excludes debug metadata and COFF timestamps. No object differs.
This includes unchanged header consumers and nonmatching function payloads, not only the six edited source modules.

Report: `build/validation/civilization-ids-followup-20261004-024848/object-comparison.json`.
Command: `python build/object-state-cleanup/compare_objects.py --before build/validation/civilization-ids-macros-20261004-023233/functions/objects --after build/validation/civilization-ids-followup-20261004-024848/functions/objects --output build/validation/civilization-ids-followup-20261004-024848/object-comparison.json`.

`git diff --check` passed. All eight changed files retain LF line endings.
No source or registry configuration, function status, stored type, or public signature changed.
No separate owner audit, linked executable, automated regression tests, or gameplay tests ran for this follow-up.
The object comparison establishes unchanged compiled payloads, not complete agreement with the original game.
