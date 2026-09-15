# `src/tscenaro.cpp` cleanup report

- Module: `src/tscenaro.cpp`
- Assigned report: `decomp_notes/source_cleanup/wave04/tscenaro.md`
- Base commit: `c22ba4258c45b1178181e185d60a3b09a1add617`
- Final source commit: `e896c380c3d7bbb45736022ccc5004250870896e`
- Delivery report commit: `93c60e96615042ecf88d2c55563892933cb1fb04`
- Changed files: `src/tscenaro.cpp`; this report
- Header owner: group owner 26 owns `include/tscenaro.h`.

## PDB coverage

The original procedure-scoped records were read from:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
- PDB source path: `C:\msdev\work\age1_x1\tscenaro.cpp`
- Original PDB: `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/age1_x1.pdb`
- Original PDB SHA256: `3acf0034af3aae3636c37746d3336d76f737855963fabf64e66b22e3c3e46e40`

All 82 procedures in `config/functions/src/tscenaro.cpp.json` have PDB coverage. `this` is the only register record for every procedure. The table lists every procedure and its recorded stack names. A dash means that the PDB has no stack parameter or local record.

| VA | Procedure | PDB stack names |
| --- | --- | --- |
| `0052A990` | `TRIBE_Scenario_Header::TRIBE_Scenario_Header` | `scenario_info` |
| `0052A9F0` | `TRIBE_Scenario_Header::TRIBE_Scenario_Header` | `infile` |
| `0052AA70` | `TRIBE_Scenario_Header::get_size` | — |
| `0052AA80` | `TRIBE_Scenario_Header::save` | `outfile` |
| `0052AAC0` | `T_Scenario::T_Scenario` | `w` |
| `0052AB90` | `T_Scenario::T_Scenario` | `infile`, `w`, `checksum` |
| `0052AF20` | `T_Scenario::save` | `outfile`, `checksum` local |
| `0052B080` | `T_Scenario::InitializePlayerValues` | — |
| `0052B100` | `T_Scenario::ClearDisabledTechnologies` | — |
| `0052B120` | `T_Scenario::InitializeAIInformation` | — |
| `0052B170` | `T_Scenario::Set_victory_all_flag` | `i` |
| `0052B190` | `T_Scenario::Get_victory_all_flag` | — |
| `0052B1A0` | `T_Scenario::SetMPVictory` | `i` |
| `0052B1C0` | `T_Scenario::GetMPVictory` | — |
| `0052B1D0` | `T_Scenario::SetVictoryScore` | `i` |
| `0052B1E0` | `T_Scenario::GetVictoryScore` | — |
| `0052B1F0` | `T_Scenario::SetVictoryTime` | `i` |
| `0052B200` | `T_Scenario::GetVictoryTime` | — |
| `0052B210` | `T_Scenario::SetSPWhich` | `i` |
| `0052B230` | `T_Scenario::GetSPWhich` | — |
| `0052B240` | `T_Scenario::InitializeVictoryValues` | — |
| `0052B280` | `T_Scenario::ClearSPVictoryCondition` | `which` |
| `0052B2B0` | `T_Scenario::InitializeFriendlinessValues` | — |
| `0052B2D0` | `T_Scenario::Set_player_attitude` | `which`, `opponent`, `attitude` |
| `0052B310` | `T_Scenario::Get_player_attitude` | `which`, `opponent` |
| `0052B340` | `T_Scenario::Set_player_Gold` | `which`, `g` |
| `0052B360` | `T_Scenario::Set_player_Wood` | `which`, `w` |
| `0052B380` | `T_Scenario::Set_player_Food` | `which`, `f` |
| `0052B3A0` | `T_Scenario::Set_player_Stone` | `which`, `s` |
| `0052B3C0` | `T_Scenario::Set_player_Info` | `which`, `i` |
| `0052B400` | `T_Scenario::Set_Multi_Conquest` | `c` |
| `0052B430` | `T_Scenario::Set_Multi_Ruins` | `r` |
| `0052B440` | `T_Scenario::Set_Multi_Artifacts` | `a` |
| `0052B450` | `T_Scenario::Set_Multi_Discoveries` | `d` |
| `0052B460` | `T_Scenario::Set_Multi_Exploration` | `e` |
| `0052B470` | `T_Scenario::Set_Multi_Gold` | `g` |
| `0052B480` | `T_Scenario::SetSPRectangle` | `VicID`, `x1`, `y1`, `x2`, `y2` |
| `0052B500` | `T_Scenario::SetSPObjectType` | `VicID`, `ObjType` |
| `0052B530` | `T_Scenario::SetSPPlayerID` | `VicID`, `PlayerID` |
| `0052B560` | `T_Scenario::SetSPAllFlag` | `VicID`, `AllFlag` |
| `0052B590` | `T_Scenario::SetSPAttribType` | `VicID`, `AttribType` |
| `0052B5C0` | `T_Scenario::SetSPVictoryType` | `VicID`, `VictoryType` |
| `0052B5F0` | `T_Scenario::SetSPObject` | `VicID`, `obj` |
| `0052B630` | `T_Scenario::SetSPDestObjectID` | `VicID`, `dest_obj` |
| `0052B670` | `T_Scenario::SetSPAmount` | `VicID`, `Amount` |
| `0052B6A0` | `T_Scenario::SetPlayerAlliedVictory` | `which`, `OnOff` |
| `0052B6C0` | `T_Scenario::SetDisabledTechnology` | `PlayerId`, `which`, `tf` |
| `0052B6E0` | `T_Scenario::SetScenarioOption` | `option`, `value` |
| `0052B700` | `T_Scenario::SetPlayerAge` | `which`, `val` |
| `0052B720` | `T_Scenario::Get_player_Gold` | `which` |
| `0052B740` | `T_Scenario::Get_player_Wood` | `which` |
| `0052B760` | `T_Scenario::Get_player_Food` | `which` |
| `0052B780` | `T_Scenario::Get_player_Stone` | `which` |
| `0052B7A0` | `T_Scenario::Get_player_Info` | `which` |
| `0052B7C0` | `T_Scenario::Get_Multi_Conquest` | — |
| `0052B7D0` | `T_Scenario::Get_Multi_Ruins` | — |
| `0052B7E0` | `T_Scenario::Get_Multi_Artifacts` | — |
| `0052B7F0` | `T_Scenario::Get_Multi_Discoveries` | — |
| `0052B800` | `T_Scenario::Get_Multi_Exploration` | — |
| `0052B810` | `T_Scenario::Get_Multi_Gold` | — |
| `0052B820` | `T_Scenario::GetSPRectangle` | `VicID`, `x1`, `y1`, `x2`, `y2` |
| `0052B8B0` | `T_Scenario::GetSPObjectType` | `VicID` |
| `0052B8E0` | `T_Scenario::GetSPPlayerID` | `VicID` |
| `0052B910` | `T_Scenario::GetSPAllFlag` | `VicID` |
| `0052B940` | `T_Scenario::GetSPAttribType` | `VicID` |
| `0052B970` | `T_Scenario::GetSPAmount` | `VicID` |
| `0052B9A0` | `T_Scenario::GetSPVictoryType` | `VicID` |
| `0052B9D0` | `T_Scenario::GetSPDestObjectID` | `VicID` |
| `0052BA00` | `T_Scenario::GetSPObject` | `VicID` |
| `0052BA30` | `T_Scenario::GetPlayerAlliedVictory` | `which` |
| `0052BA40` | `T_Scenario::GetDisabledTechnology` | `PlayerId`, `which` |
| `0052BA60` | `T_Scenario::GetScenarioOption` | `option` |
| `0052BA70` | `T_Scenario::GetPlayerAge` | `which` |
| `0052BA80` | `T_Scenario::update` | — |
| `0052BA90` | `T_Scenario::SaveAttributesIntoPlayers` | — |
| `0052BBC0` | `T_Scenario::Save_victory_conditions_into_players` | `SaveAttributes`, `j`, `i` |
| `0052C070` | `T_Scenario::rehook` | — |
| `0052C080` | `T_Scenario::get_object_pointer` | `obj_ID` |
| `0052C0A0` | `T_Scenario::get_object_ID` | `obj` |
| `0052C0B0` | `T_Scenario::WriteDisabledTechnologiesToMainSystem` | — |
| `0052C1E0` | `T_Scenario::any_sp_victory` | — |
| `0052C230` | `T_Scenario::set_player_tech` | `player` |

## Changes and evidence

- Recovered every recorded original parameter name in the source definition and body.
- Recovered the `checksum` stack name in the file-loading constructor. The PDB records it at `+0xc`; the source uses that slot for each checksum read.
- Recovered `j` and `i` in `Save_victory_conditions_into_players` from the PDB records at `-0x8` and `-0x10`. They match the outer player row and inner victory-condition loops.
- Preserved source locals that have no PDB name record. These include `old_version`, `player`, `world`, `condition`, and their loop or temporary variables. No stack-slot mapping was forced for those names.
- The recovered names include terse and mixed styles exactly as recorded. No new descriptive names were added.
- Moved three definition braces to 1TBS: `InitializePlayerValues`, `WriteDisabledTechnologiesToMainSystem`, and `set_player_tech`.
- Preserved declarations, types, scopes, storage, casts, statement order, calls, literals, and existing behavior comments.

The existing comments remain useful and unchanged:

- The `Save_victory_conditions_into_players` comment records that the shipped record walk is anchored at `AttribType`. The decompiler evidence at `0052BBC0` shows the same anchor.
- The `WriteDisabledTechnologiesToMainSystem` comment records that the shipped loop reads the low byte of each typed field. The decompiler evidence at `0052C0B0` shows the explicit `uchar` reads.

## Constants and resources

This module has no resource-ID lookup. No DLL resource was inspected, and no resource mapping is needed. No constants or shared resource declarations changed. The numeric version markers, file sizes, technology IDs, and victory values remain unchanged.

## Requests, risks, and validation limits

- Header request to owner 26: add the PDB parameter names from the complete table
  to the matching declarations in `include/tscenaro.h`. This is a
  declaration-name-only request. Keep all types, order, storage, and interfaces
  unchanged.
- Unresolved mapping: compiler locals without PDB records remain unchanged. Their original source spellings cannot be proved from the available procedure-scoped inventory.
- Type, code-generation, layout, and symbol-identity risk: parameter and local renames do not change types, storage, ABI signatures, layouts, or mangled symbols. Brace movement is presentation-only. The source was not compiled in this phase.
- Compilation, matching, audits, and tests were not run. No validation or byte-equality claim is made.
