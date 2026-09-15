# `scr_cams.cpp` cleanup report

## Scope

This report covers `src/scr_cams.cpp` in wave 01.

The source owns these eight handwritten functions:

- `004909D0` `TRIBE_Screen_Campaign_Selection::TRIBE_Screen_Campaign_Selection`
- `00490E30` `TRIBE_Screen_Campaign_Selection::init_vars`
- `00490EA0` `TRIBE_Screen_Campaign_Selection::~TRIBE_Screen_Campaign_Selection`
- `00490F90` `TRIBE_Screen_Campaign_Selection::handle_idle`
- `00490FF0` `TRIBE_Screen_Campaign_Selection::action`
- `004911A0` `TRIBE_Screen_Campaign_Selection::fillCampaigns`
- `00491290` `TRIBE_Screen_Campaign_Selection::fillScenarios`
- `00491350` `TRIBE_Screen_Campaign_Selection::startGame`

`00490E10` remains the compiler-generated scalar deleting destructor.

The PDB source is `C:\msdev\work\age1_x1\scr_cams.cpp`.

## Changes

- Added the reviewed `resource_ids.h` include.
- Replaced the known OK and Cancel resource literals with named macros.
- Restored PDB parameter names in `action`.
- Restored the PDB name `currentCampaign` in `fillCampaigns`.
- Renamed the scenario pointer to `scenario_info`.
- Renamed `first_color` to `first_any_color`.
- Renamed `first_human` to `first_any_color_index`.
- Kept the repeated derived-game casts in `startGame`.
- Kept all call order, branches, values, and cleanup operations.

The source keeps canonical headers and natural C++ expressions.
It has no wrapper, copied context, raw address, or inline assembly.

## Resource evidence

`runtime/language.dll` has SHA-1:

`3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`

This file contains the campaign-screen strings for IDs `0x25FE`, `0x2B5D`,
and `0x2BCD` through `0x2BD4`.

`runtime/languagex.dll` and the original XPack `languagex.dll` have no matching
string-table entries for these IDs.

`TRIBE_Game::get_string` checks `StringTableX` first, then the base language
lookup. The existing literals therefore retain their runtime lookup behavior.

The existing `include/resource_ids.h` defines `IDS_BUTTON_OK` as `0x0FA1` and
`IDS_BUTTON_CANCEL` as `0x0FA2`. No campaign-specific resource macro was added.

## Header review

`include/scr_cams.h` already declares the correct class and method surface.
No header edit is proposed. The header remains unchanged.

## Validation

I inspected the final diff and ran `git diff --check`.

Builds, compiler checks, matching, audits, and tests were not run.
No game or resource runtime test was run.
