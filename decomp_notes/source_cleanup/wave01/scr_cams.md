# `scr_cams.cpp` source-cleanup report

## Delivery and Git history

Module: `src/scr_cams.cpp`

Base commit:

`ad338a7faf75ffdfff8fec846133b4aa8da3fa44`

Final-before-correction commit:

`7100dba106396fd1574ee33e78143a9e12f6deee`

Commits in this module before correction:

- `7100dba106396fd1574ee33e78143a9e12f6deee` — Clean up scr_cams source

The correction commit contains this report and the source name-formatting correction.
Its full hash is reported with the final delivery.

Changed files:

- `src/scr_cams.cpp`
- `decomp_notes/source_cleanup/wave01/scr_cams.md`

`include/scr_cams.h` was not edited.

## Scope

The source owns eight handwritten functions in PDB order:

- `004909D0` `TRIBE_Screen_Campaign_Selection::TRIBE_Screen_Campaign_Selection`
- `00490E30` `TRIBE_Screen_Campaign_Selection::init_vars`
- `00490EA0` `TRIBE_Screen_Campaign_Selection::~TRIBE_Screen_Campaign_Selection`
- `00490F90` `TRIBE_Screen_Campaign_Selection::handle_idle`
- `00490FF0` `TRIBE_Screen_Campaign_Selection::action`
- `004911A0` `TRIBE_Screen_Campaign_Selection::fillCampaigns`
- `00491290` `TRIBE_Screen_Campaign_Selection::fillScenarios`
- `00491350` `TRIBE_Screen_Campaign_Selection::startGame`

`00490E10` is the compiler-generated scalar deleting destructor.
It is outside the eight handwritten bodies.

The PDB source is `C:\msdev\work\age1_x1\scr_cams.cpp`.

## Systematic PDB coverage

The procedure-scoped PDB record gives `this` in ECX for every listed function.
Its type is `TRIBE_Screen_Campaign_Selection*`.
The table lists every recorded parameter and local for each body.

| VA and function | PDB parameters | PDB locals | Register record |
| --- | --- | --- | --- |
| `004909D0` constructor | none | `tabList`, stack `-0x20`, `TPanel*[20 bytes]` | `this`, ECX |
| `00490E30` `init_vars` | none | none | `this`, ECX |
| `00490EA0` destructor | none | none | `this`, ECX |
| `00490F90` `handle_idle` | none | none | `this`, ECX |
| `00490FF0` `action` | `fromPanel` `+0x4` `TPanel*`; `actionIn` `+0x8` `long`; `a1` `+0xc` `unsigned long`; `a2` `+0x10` `unsigned long` | none | `this`, ECX |
| `004911A0` `fillCampaigns` | none | `campaigns`, stack `-0x8`, `char**`; `currentCampaign`, stack `-0x4`, `long` | `this`, ECX |
| `00491290` `fillScenarios` | none | `scenarios`, stack `-0x8`, `char**`; `currentScenario`, stack `-0x4`, `long` | `this`, ECX |
| `00491350` `startGame` | none | PDB lists `scenario_info`, stack `-0xc`, `T_Scenario*`; PDB lists `first_any_color`, stack `-0x8`, `int` | `this`, ECX |

The PDB has no records for the other `startGame` temporaries.
This includes the player count, loop variables, and saved color index.

The `startGame` packet warns that `scenario_info` should be unmapped.
Its Ghidra output also shows reused machine locals and conflicting labels.
The listed PDB stack and type records do not prove source declarations.
The cleanup does not force a PDB stack-slot mapping.

## Names

Recovered from procedure scope and storage:

- `this` for all eight functions.
- `tabList` in the constructor.
- `fromPanel`, `actionIn`, `a1`, and `a2` in `action`.
- `campaigns` and `currentCampaign` in `fillCampaigns`.
- `scenarios` and `currentScenario` in `fillScenarios`.

The `startGame` mapping was rejected.
The packet warns that `scenario_info` should be unmapped.
Its stack and machine-local evidence do not prove the three attempted names.
The source therefore retains the baseline names `scen`, `first_human`, and
`first_color`.
Their original status is not claimed.

The rejected names were `scenario_info`, `first_any_color`, and
`first_any_color_index`.
The last name was also less precise than the first human scenario-player
index. No uncertain naming churn remains in `startGame`.

Other locals, such as `player_count`, `color`, `count`, `num`, `line`, `ok`,
`i`, `j`, `p`, and `q`, are descriptive source names.
They are not claimed as PDB recoveries.

## Source changes

The source keeps the approved resource macro substitutions:

- `0x0FA1` uses existing `IDS_BUTTON_OK`.
- `0x0FA2` uses existing `IDS_BUTTON_CANCEL`.

The source includes the existing shared `resource_ids.h`.
No new resource macro was added.

The correction applies 1TBS to the assigned source file.
It joins short definitions and the `action` signature where readable.
The round-two correction restores the three baseline `startGame` names.
It changes no statements, scopes, types, or storage.

No wrapper, copied context, raw address, raw vptr, fallback declaration, or
inline assembly was added.

## Resource evidence

`runtime/language.dll` has SHA256:

`3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`

This resource contains campaign-screen strings for IDs `0x25FE`, `0x2B5D`,
and `0x2BCD` through `0x2BD4`.

`runtime/languagex.dll` and the original XPack `languagex.dll` have no matching
string-table entries for these IDs.

`TRIBE_Game::get_string` checks `StringTableX` first, then the base language
lookup. The existing literal lookups therefore keep their fallback order.

## Output risk

The macro values equal the original literals.
The name changes do not change types, storage, calls, or control flow.
The correction changes formatting only.
The header remains unchanged, so layout and ABI declarations remain unchanged.

No generated-output claim is made without compilation and matching.
Formatting can affect line records, but this file has no `__LINE__` use.

## Shared requests and unresolved questions

The owner of `include/scr_cams.h` should apply this declaration-name request:

```cpp
virtual long action(TPanel* fromPanel, long actionIn, unsigned long a1, unsigned long a2);
```

The request is supported by the `00490FF0` procedure-scoped PDB record.
This worker did not edit the header.

No resource-header request is needed. The existing OK and Cancel macros suffice.

The original local names and stack mapping in `startGame` remain unresolved.
The baseline names remain in place without recovered-original claims.

## Validation

I inspected the complete new diff and ran `git diff --check`.

**Compilation, matching, audits, and tests were not run.**

No game or resource runtime test was run.
