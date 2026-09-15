# Scenario source-cleanup report

## Scope and commits

- Module: `src/scenario.cpp`
- Registry: `config/functions/src/scenario.cpp.json`
- Header read only: `include/scenario.h`
- Base commit: `c22ba4258c45b1178181e185d60a3b09a1add617`
- Source commit: `cd138ad8ff071550dd4cc712602d6e902b0451e9`
- Report delivery commit: `22dd8c8762fe0b0539da53f7bdb55963e13de15e`
- Post-cleanup repair commit: recorded by Git after this report is committed
- Changed files in the source commit:
  - `src/scenario.cpp`
- Changed files in the report commit:
  - `decomp_notes/source_cleanup/wave04/scenario.md`

The source commit contains only the assigned source file. The report commit contains only this assigned report.

## Procedure evidence and coverage

I inspected the registry, the procedure-scoped PDB records, and the original packets.
The PDB source is `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
The PDB module is `.\\Release\\scenario.obj`.
The selected packets are under `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0048/`.

The registry selects 48 procedures. Each selected VA has a PDB record and an original packet.
The PDB also contains non-registry records for the scalar deleting destructor, `get_object_pointer`, and `rehook`.
Those records were not edited.

The selected VA coverage is:

```text
0048AB10, 0048ABB0, 0048AC70, 0048ACA0, 0048ACC0, 0048AD60, 0048AE10,
0048B5A0, 0048B6C0, 0048B910, 0048B950, 0048B960, 0048B9A0, 0048B9E0,
0048BA20, 0048BA60, 0048BAD0, 0048BB40, 0048BBB0, 0048BBC0, 0048BBE0,
0048BC00, 0048BC20, 0048BC60, 0048BC70, 0048BC80, 0048BC90, 0048BCA0,
0048BCB0, 0048BCC0, 0048BEC0, 0048C0D0, 0048C0E0, 0048C2F0, 0048C360,
0048C370, 0048C390, 0048C3B0, 0048C3D0, 0048C3E0, 0048CC20, 0048CC50,
0048CC80, 0048CCB0, 0048CCC0, 0048CCD0, 0048CD10, 0048CE40
```

## Recovered original names

I restored the PDB names for parameters and locals where the type, stack slot, and use gave a reliable mapping.
The original mixed spelling remains unchanged.

- Header procedures use the recovered names `scenario_info`, `infile`, `outfile`, `desc_size`, and `header_size`.
- Scenario constructors use `w`, `infile`, and `length`.
- Setters use `str`, `which_player`, `WithExtension`, `ver`, `which`, `t`, `c`, `val`, `which`, and `Name` as recorded by the PDB.
- File getters use `which_player`, `WithExtension`, `temp_path`, `none_str`, and `random_str`.
- `GetPlayerPosture`, player getters, `Set_conquest_victory`, `add_description`, `Set_message`, and `Get_message` use the PDB names `which`, `flag`, `new_text`, and `message`.
- `InitializeTextValues` retains the PDB names `default_string` and `none_string`.
- `save` uses the PDB names `outfile`, `temp_file_name`, `length`, and `file_name`.

I did not force the PDB `val` records in the load constructor or `save` into source declarations.
Those records have an `int` type and do not map safely to the existing `text` storage or `float* version` use.

I assigned these cleanup names where the PDB gave no safe source mapping:
`description_text`, `description_source`, `description_size`, `player_index`, `picture`, `slot`, `remaining`,
`new_picture`, `old_picture`, and `message_copy`.
These are cleanup names, not claims about original source spelling.
The loop declarations, types, scopes, storage, and statement order remain unchanged.

### Header declaration-name request for owner 26

Owner 26 should update `include/scenario.h` parameter names only.
Keep every type, parameter order, virtual slot, and ABI signature unchanged.
The requested declaration names are:

- `RGE_Scenario_Header(RGE_Scenario*)`: `scenario_info`.
- `RGE_Scenario_Header(int)`: `infile`.
- `RGE_Scenario_Header::save(int)`: `outfile`.
- `RGE_Scenario(RGE_Game_World*)`: `w`.
- `RGE_Scenario(int, RGE_Game_World*)`: `infile`, `w`.
- `RGE_Scenario::save(int)`: `outfile`.
- `Set_scenario_name`, `Set_description`, `Set_Cine_PreGame`, `Set_Cine_Victory`, `Set_Cine_Loss`, and `Set_Mission_Bmp`: `str`.
- `Set_BuildList`, `Set_CityPlan`, and `Set_player_AI`: `which_player`, `str`, `WithExtension`.
- `Set_Version`: `ver`.
- `Set_player_Type`: `which`, `t`.
- `Set_player_Civ`: `which`, `c`.
- `Set_player_Active`: `which`, `val`.
- `SetPlayerName`: `which`, `Name`.
- `Get_BuildList`, `Get_CityPlan`, and `Get_player_AI`: `which_player`, `WithExtension`.
- `GetPlayerPosture`, `GetPlayerName`, `Get_player_Type`, `Get_player_Civ`, and `Get_player_Active`: `which`.
- `Set_conquest_victory`: `flag`.
- `add_description`: `new_text`.
- `Set_message`: `str`, `message`.
- `Get_message`: `message`.

The non-registry protected `get_object_pointer` record also reliably gives `obj_ID`.
Owner 26 can rename its header parameter from `object_id` to `obj_ID` in the same declaration-only change.

## Post-cleanup VC5 repair

The fresh main-build report is `C:/Projects/my_decomps/aoe1_attempt3/build/executable/user/20260915T215425319815Z/20260915T215425568371Z/report.json`.
It records `src/scenario.cpp` as `compiled: false`.
VC5 reported `C2374: 'player_index' : redefinition; multiple initialization` at lines 255, 268, 691, 790, 797, and 813.
VC5 keeps a for-init variable in the enclosing function scope.

I compared the source with pre-cleanup commit `6d46835cdc6e31ba879a2e6e31415327a7c7e341`.
The load constructor now restores the distinct baseline names `n3`, `n4`, `n5`, and `n6`.
The `save` function now restores the distinct baseline names `a`, `b`, `c`, `d`, `e`, and `f`.
The repair changes only loop names and their uses.
It adds no scope, removes no declaration, and changes no type, storage, order, call, or behavior.
No new build or compiler run was made for this repair.

## Constants and comments

I read the pinned VC5 headers before replacing numeric SDK values.

- `C:/Program Files (x86)/DevStudio/VC/Include/FCNTL.H` proves the `_open` flags and permission masks.
  The three read-only binary opens now use `_O_BINARY` instead of `0x8000`.
  The three temporary-file opens now use `_O_BINARY | _O_CREAT | _O_TRUNC | _O_WRONLY` instead of `0x8301`.
  Their mode now uses `_S_IREAD | _S_IWRITE` instead of `0x180`.
- `SEEK_SET` and `SEEK_END` replace the proven `lseek` origin values `0` and `2`.
- `C:/Program Files (x86)/DevStudio/VC/Include/WINDEF.H` defines `MAX_PATH` as `260`.
  It replaces the proven `GetTempPathA` size `0x104`.

The source keeps the original resource lookups and lookup order.
It keeps the original `free(0)` call in `Set_message`; the original packet proves this no-op branch.
It also keeps the existing cross-field checks in `Get_CityPlan` and `Get_player_AI`.
No behavior repair or structural rewrite was made.

## Resource evidence and shared-file approval

`InitializeTextValues`, `Get_BuildList`, `Get_CityPlan`, and `Get_player_AI` call the virtual `rge_base_game->get_string` path.
The code passes bare DLL names to `LoadLibraryA`; the inspected file paths do not prove which file a running process loads.
The two staged runtime DLLs below are not called original files because their provenance is not proven here.
The XPack path below is part of the repo-local original corpus.

The resource inspection results are:

| DLL provenance | Exact absolute path | SHA256 | Language | `0x2775` | `0x277B` |
| --- | --- | --- | --- | --- | --- |
| Staged runtime file | `C:\Projects\my_decomps\aoe1_attempt3\runtime\language.dll` | `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5` | `0x0409` | Exact text `" <None> "` | Exact text `"Random"` |
| Staged runtime file | `C:\Projects\my_decomps\aoe1_attempt3\runtime\languagex.dll` | `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39` | No language entry for either requested ID | Missing; no empty slot | Missing; no empty slot |
| Repo-local original corpus XPack file | `C:\Projects\my_decomps\aoe1_attempt3\orig\original_full_game_files_rise_of_romes_beta_17_7_1998\XPack\languagex.dll` | `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2` | `0x0409` occurs in its RT_STRING rows; neither requested ID has an entry | Missing; no empty slot | Missing; no empty slot |

The two text entries have resource type `RT_STRING` and language `0x0409`.
The missing results mean that the requested IDs have no resource row.
They do not mean that a present row has empty text.

Root approved the shared resource names in commit `bf943f3339643ee5beca7dd74e98b4cb729e48d3`.
The broad `0x2775` None role uses the approved name `IDS_FILE_NONE`.
The `0x277B` AI-file Random role uses the approved name `IDS_AI_FILE_RANDOM`.
These are approved cleanup names, not recovered original macro names.

`RGE_Base_Game` sets the base DLL name to `language.dll` and loads it into `StringTable`.
Its `get_string` calls `LoadStringA(StringTable, ...)` and writes an empty buffer on failure.
`TRIBE_Game` defaults the override DLL name to `languagex.dll`.
Its `STRING=` command option can replace that name before it loads `StringTableX`.
`TRIBE_Game::get_string` calls `LoadStringA(StringTableX, ...)` first.
When that lookup fails, it calls `RGE_Base_Game::get_string`, which uses `StringTable` as the fallback.
Therefore the inspected languagex misses fall back to the base language lookup when the game override is active.

The IDs are used as follows:

- `0x2775` returns the padded `" <None> "` sentinel for scenario text and file names.
- `0x277B` returns `"Random"` as the default and file-name sentinel.

The source now includes `../include/resource_ids.h` and uses the approved names.
The source preserves the exact payloads, missing and empty distinction, staged-runtime provenance limit,
and languagex override with language.dll fallback.

## Possible generated-code effects

The changes rename parameters and locals, apply 1TBS formatting, add required CRT includes, and use SDK macros with the same values.
They preserve types, scopes, storage, casts, call targets, evaluation order, statement order, resource lookup order, and public signatures.
The repaired source was not compiled, so generated-code stability remains unverified.

## Validation and open items

The fresh main build report records the VC5 compile failure described above.
I did not run a compiler, build, matching check, audit, test, or game for this repair.

Open items:

- Root resource approval is recorded in `bf943f3339643ee5beca7dd74e98b4cb729e48d3`.
- The PDB `val` records remain unresolved because their recorded types do not map to the existing source declarations.
- Final executable comparison remains required after integration.
