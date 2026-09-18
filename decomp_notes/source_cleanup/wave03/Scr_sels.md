# Source-cleanup handoff: `src/Scr_sels.cpp`

## Delivery

- Module: `src/Scr_sels.cpp`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Source cleanup commit: `f4c24344757acbb864d7deef11aad91759946e4a`
- Scenario-ID follow-up commit: `43d87a91f0eb0b1d8070c7df1b588880bbd26d56`
- Final report commit: `a9c6d6d4ff638a2b6f0fe45965619f571e9759ca`
- Branch: `cleanup/staging-20260915-187`
- Changed files:
  - `src/Scr_sels.cpp`
  - `decomp_notes/source_cleanup/wave03/Scr_sels.md`

This worker preserved the existing worktree and history. No reset or history rewrite was used.

## Scope and evidence

The source owns these ten registered functions:

- `004B3C90` `TribeSelectScenarioScreen::TribeSelectScenarioScreen`
- `004B4120` `init_vars`
- `004B4190` `~TribeSelectScenarioScreen`
- `004B4280` `handle_idle`
- `004B42E0` `action`
- `004B44F0` `fillScenarios`
- `004B4720` `fillMissionText`
- `004B4770` `getSettings`
- `004B47D0` `sendSettings`
- `004B4810` `activatePanels`

The PDB source is `C:\msdev\work\age1_x1\Scr_sels.cpp`.
I inspected the complete source-cleanup, comment, resource-ID, testing, and wave-assignment guides.
I inspected the ten function packets under `inventory/functions/004B/`.
I inspected `inventory/pdb/scoped_symbols.json` and the existing function notes.

The original function packets record `this` in ECX for all ten functions.
The original executable remains the behavior oracle. No executable was run.

## Original-name recovery

The source now uses the names supported by the procedure-scoped PDB.
These are recovered original names, not new style choices.

| VA | PDB records | Source result |
| --- | --- | --- |
| `004B3C90` constructor | No stack records | No rename. `setup_file`, `draw_area`, and `multiplayer` remain inferred names. |
| `004B4120` `init_vars` | No stack records | No rename. |
| `004B4190` destructor | No stack records | No rename. |
| `004B4280` `handle_idle` | No stack records | No rename. |
| `004B42E0` `action` | `fromPanel` at `+0x4`, `actionIn` at `+0x8`, `a1` at `+0xc`, and `a2` at `+0x10` | Replaced `panel`, `event`, `p3`, and `p4` in the definition, tests, fallback call, and uses. Types and order stayed unchanged. |
| `004B44F0` `fillScenarios` | `i`, `scenario_file`, `scenario_info_file`, `player_str`, and `file_name` | All five source names already match the PDB. `name`, `len`, `id`, `hdr`, and `players` have no safe PDB mapping and remain inferred. |
| `004B4720` `fillMissionText` | No stack records | `line` remains an inferred name. |
| `004B4770` `getSettings` | No stack records | `scenarioName` and `line` remain inferred names. |
| `004B47D0` `sendSettings` | No stack records | No rename. |
| `004B4810` `activatePanels` | `tabList` at `-0x10`, type `TPanel*[16 bytes]` | The source already uses recovered `tabList`. Its four entries and storage remain unchanged. |

The PDB provides no safe mapping for the other local declarations.
I did not force names from reused stack slots or decompiler labels.
No public function, class, member, global, type, storage, layout, calling convention, or ABI symbol changed.

The source keeps all other descriptive names as inferred cleanup names.
It does not claim those names as original developer names.

## Resource IDs

The source now includes the root-owned `include/resource_ids.h`.
It reuses these existing reviewed cleanup names:

| Macro | Value | Source use | Text result |
| --- | --- | --- | --- |
| `STRING_ID_BUTTON_OK` | `0x0FA1` | OK button caption | `OK` |
| `STRING_ID_BUTTON_CANCEL` | `0x0FA2` | Cancel button caption | `Cancel` |
| `STRING_ID_BUTTON_CLOSE` | `0x03EA` | Close button caption | `X` |
| `STRING_ID_HELP_OK` | `0x7531` | OK button help ID | Missing in checked files |
| `STRING_ID_HELP_CANCEL` | `0x7532` | Cancel button help ID | Missing in checked files |

These macros are existing shared names.
They are not claimed as original macro names.
The source did not add a competing definition.

The mission scrollbar also receives numeric ID `0x7532`.
I left this occurrence numeric because this call targets a scrollbar, not a Cancel button.
The numeric equality does not prove that `STRING_ID_HELP_CANCEL` describes this use.
The original value and call stay unchanged.

## Root-approved scenario IDs

The worker evidence established the roles and text shown below.
At that time, no shared name existed in this worktree.

Root approved the payload-backed mappings in commit
`f5b7d6668f785b97811119493bea0e04403d1d10`.
I read the approved `include/resource_ids.h` from the root owner's worktree:

`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/slot-181/include/resource_ids.h`

This follow-up uses the exact approved macro names.
The root-owned header remains unedited in this worker worktree.
It must be integrated with the approved root commit.

| ID | Approved cleanup name | Proven source role | Language payload |
| --- | --- | --- | --- |
| `0x25FA` | `STRING_ID_SCENARIO_SELECTION_TITLE` | Screen title passed to `create_text` | `Scenarios` |
| `0x25FD` | `STRING_ID_SCENARIO_LIST_LOADING` | Initial text passed to the scenario list | `Loading list of scenarios...` |
| `0x25FE` | `STRING_ID_SCENARIO_LIST_TITLE` | Scenario-list title passed to `create_text` | `Select Scenario` |
| `0x25FF` | `STRING_ID_SCENARIO_PLAYERS_TITLE` | Player-count column title | `Players` |
| `0x2600` | `STRING_ID_SCENARIO_INSTRUCTIONS_TITLE` | Mission-text title | `Scenario Instructions` |

The names above are new cleanup names.
They are not recovered original macro names.
The existing `STRING_ID_SCENARIOS_TITLE` name belongs to value `0x2BC7`, so it cannot name `0x25FA`.

## Resource provenance

The extraction tool read PE bytes only.
It did not load or execute a DLL.
The extraction outputs are under the worker build directory:

- `build/resource-strings/scr-sels-runtime-language.json`
- `build/resource-strings/scr-sels-runtime-languagex.json`
- `build/resource-strings/scr-sels-original-languagex.json`
- `build/resource-strings/scr-sels-runtime-help.json`
- `build/resource-strings/scr-sels-runtime-languagex-help.json`
- `build/resource-strings/scr-sels-original-languagex-help.json`

The checked base runtime file is `runtime/language.dll`.

- SHA-256: `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`
- Resource type: `RT_STRING`
- Language: `0x0409` (`1033`)
- It contains all five approved scenario IDs and the `0x03EA`, `0x0FA1`, and `0x0FA2` entries.
- It does not contain `0x7531` or `0x7532`.

The checked runtime expansion file is `runtime/languagex.dll`.

- SHA-256: `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`
- Resource type: `RT_STRING`
- The five approved scenario IDs and both help IDs are missing.

The pinned original expansion reference is `orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`.

- SHA-256: `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`
- Resource type: `RT_STRING`
- The five approved scenario IDs and both help IDs are missing.

`RGE_Base_Game` sets the base DLL name to `language.dll` and loads it into `StringTable`.
`TRIBE_Game::get_string` checks `StringTableX` first, then uses the base lookup.
The checked runtime expansion therefore falls back to the checked runtime base for the approved scenario IDs.
The help text remains missing in all checked files.

These staged runtime-base and expansion statuses are worker evidence.
Root approval changed only the source names, not the resource files or their findings.

The original function packet also records the same `language.dll` payloads at the five constructor call sites.
The packet records `0x7531` and `0x7532` as help IDs.

## Source changes

- Added the existing shared resource-ID header include.
- Replaced proven button and help literals with existing shared names.
- Replaced `0x25FA`, `0x25FD`, `0x25FE`, `0x25FF`, and `0x2600` with the root-approved scenario macros.
- Recovered the four `action` parameter names from the PDB.
- Applied 1TBS to the constructor and `fillScenarios` definitions.
- Kept the `action` signature and opening brace on one line.
- Preserved source order, control flow, calls, casts, literal values, buffer sizes, and lookup order.
- Added no source comments. The module needs no sparse comment for a new behavior fact.

The changes to resource expressions preserve the original numeric values.
The name changes do not change types or storage.
Formatting can change debug line records.
The new include and macro expansions can also change line mapping.
No generated code, program data, relocation, call-target, or symbol-identity claim is made without final validation.

## Shared-file requests and unresolved questions

The owner of `include/scr_sels.h` should review this declaration-name change:

```cpp
virtual long action(TPanel* fromPanel, long actionIn, unsigned long a1, unsigned long a2);
```

This worker did not edit that unassigned header.
The declaration types and order already match the source definition.

Root approved the five scenario mappings in
`f5b7d6668f785b97811119493bea0e04403d1d10`.
The integration must use that root-owned header commit.
Do not add duplicate names for `0x25FA` through `0x2600`.

The purpose of the `0x7532` mission-scrollbar help assignment remains unresolved.
The source preserves it as numeric.
The PDB has no safe mappings for the inferred locals listed above.

## Validation

I reviewed the complete source diff and ran `git diff --check`.

Compilation, matching, audits, tests, and games were **NOT run**.
No compiler or build command was invoked.
Generated-output equality remains unvalidated.
