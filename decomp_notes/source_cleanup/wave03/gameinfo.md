# `gameinfo.cpp` cleanup report

## Module and commits

- Module: `src/gameinfo.cpp`
- Registry: `config/functions/src/gameinfo.cpp.json`
- Read-only header: `include/gameinfo.h`
- PDB source: `C:\\msdev\\work\\age1_x1\\gameinfo.cpp`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Final module commit: `a55c22b2b9d9bf9b05dbf16e33b02929bfef0565`
- The report is a follow-up commit on the final module commit. Its full hash is in the delivery record.
- Changed files:
  - `src/gameinfo.cpp`
  - `decomp_notes/source_cleanup/wave03/gameinfo.md`
- `include/gameinfo.h` was read but not changed. No other header was changed.

The registry selects 42 source functions from `0044C5A0` through `0044DA50`.
The registry marks all 42 functions `matching`. Those claims were not rechecked in this wave.

## Original-name recovery coverage

I inspected procedure-scoped parameters, locals, and registers for all 42 registry
functions in `inventory/pdb/scoped_symbols.json`. Every record has `this` in
`ecx`. The PDB records no procedure-local symbols for most functions. It records
`new_campaign_info` in `0044CEF0`, `version` in `0044D1A0`, and `file_info` and
`file_name` in `0044D470`. I did not force names onto reused or unrecorded storage.

The following table gives complete coverage. `none` means that the procedure
record has no named stack parameter or local beyond `this`.

| VA | Function | Recovered parameters | Recovered locals |
| --- | --- | --- | --- |
| `0044C5A0` | `RGE_Campaign_Info` load constructor | `infile`, `campaigns`, `campaign_num` | none |
| `0044C780` | `RGE_Campaign_Info` campaign constructor | `new_campaign` | none |
| `0044C870` | `~RGE_Campaign_Info` | none | none |
| `0044C8A0` | `RGE_Campaign_Info::save` | `outfile` | none |
| `0044C930` | `RGE_Campaign_Info::rehook_campaigns` | `campaigns`, `campaign_num` | none |
| `0044CA90` | `RGE_Campaign_Info::set_current_scenario` | `num` | none |
| `0044CAD0` | `RGE_Campaign_Info::verify_campaign_name` | `in_campaign_name` | none |
| `0044CB20` | `RGE_Campaign_Info::get_scenario_list` | `list`, `curr_scenario` | none |
| `0044CBB0` | `RGE_Campaign_Info::get_current_scenario` | none | none |
| `0044CBC0` | `RGE_Campaign_Info::notify_of_scenario_complete` | none | none |
| `0044CC20` | `RGE_Campaign_Info::open_scenario` | none | none |
| `0044CC40` | `RGE_Person_Info` load constructor | `infile`, `in_campaigns`, `in_campaign_num` | none |
| `0044CD40` | `RGE_Person_Info` name constructor | `in_name`, `in_campaigns`, `in_campaign_num` | none |
| `0044CDA0` | `~RGE_Person_Info` | none | none |
| `0044CE10` | `RGE_Person_Info::save` | `outfile` | none |
| `0044CE90` | `RGE_Person_Info::rehook_campaigns` | `in_campaigns`, `in_campaign_num` | none |
| `0044CEE0` | `RGE_Person_Info::get_name` | none | none |
| `0044CEF0` | `RGE_Person_Info::set_current_campaign` | `num` | `new_campaign_info` |
| `0044D050` | `RGE_Person_Info::get_current_campaign` | none | none |
| `0044D0C0` | `RGE_Person_Info::get_current_scenario` | none | none |
| `0044D0F0` | `RGE_Person_Info::set_current_scenario` | `num` | none |
| `0044D130` | `RGE_Person_Info::get_scenario_list` | `list`, `current_scenario` | none |
| `0044D160` | `RGE_Person_Info::notify_of_scenario_complete` | none | none |
| `0044D180` | `RGE_Person_Info::open_scenario` | none | none |
| `0044D1A0` | `RGE_Game_Info` constructor | `filename` | `version` |
| `0044D300` | `~RGE_Game_Info` | none | none |
| `0044D3B0` | `RGE_Game_Info::save` | `filename` | none |
| `0044D470` | `RGE_Game_Info::find_campaigns` | none | `file_info`, `file_name` |
| `0044D710` | `RGE_Game_Info::add_new_person` | `name` | none |
| `0044D7D0` | `RGE_Game_Info::set_current_person` | `num` | none |
| `0044D7F0` | `RGE_Game_Info::set_current_campaign` | `num` | none |
| `0044D820` | `RGE_Game_Info::set_current_scenario` | `num` | none |
| `0044D850` | `RGE_Game_Info::get_people_list` | `list`, `current_player` | none recorded |
| `0044D8C0` | `RGE_Game_Info::get_campaign_list` | `list`, `current_campaign` | none |
| `0044D940` | `RGE_Game_Info::get_scenario_list` | `list`, `current_scenario` | none |
| `0044D990` | `RGE_Game_Info::get_current_scenario` | none | none |
| `0044D9B0` | `RGE_Game_Info::get_current_campaign` | none | none |
| `0044D9D0` | `RGE_Game_Info::get_current_player` | none | none |
| `0044D9E0` | `RGE_Game_Info::get_current_player_name` | none | none |
| `0044DA00` | `RGE_Game_Info::notify_of_scenario_complete` | none | none |
| `0044DA30` | `RGE_Game_Info::open_scenario` | none | none |
| `0044DA50` | `RGE_Game_Info::remove_player` | `id` | none |

The source changes replace generated or non-original declaration names as follows:

- `fd`, `camps`, and `cnum` now use the recorded `infile`, `campaigns`, and
  `campaign_num` names in both load paths where the PDB records them.
- `camp` now uses `new_campaign`.
- `fd` in both save functions now uses `outfile`.
- `list` and `count` in the campaign rehook path now use the recorded
  `campaigns` and `campaign_num` names.
- `param_1`, `campaign`, `current`, and the related list parameters now use the
  recorded `num`, `in_campaign_name`, `curr_scenario`, and list-result names.
- The person constructors and rehook function now use the recorded `in_`
  parameter spellings.
- `index` and `newlist` now use the recorded `num` and `new_campaign_info`.
- The game constructor and save function now use the recorded `filename` name;
  the constructor local `ver` now uses `version`.
- The game setter parameters now use the recorded `num` names.
- `out_list`, `out_current`, `current`, `param_1`, and `param_2` now use the
  recorded `list`, `current_player`, `current_campaign`, and `current_scenario`
  names.
- `person_index` now uses the recorded `id` name.

`0044D850` has no PDB local records. The former `iVar3` and `ppcVar1` names
were generated forms, so they now use invented snake_case-safe names `i` and
`new_list`. The existing `name` local remains because its use is clear and no
PDB evidence supports a different spelling. These three local mappings remain
unresolved as original source names.

## Source cleanup and evidence

- Kept the existing statements, declarations, scopes, types, casts, calls,
  literals, evaluation order, and storage arrangement.
- Made no structural rewrite, helper, layout change, ABI change, or symbol rename.
- Added no comments. No existing comments needed correction.
- Added no constants, enums, resource IDs, or macros.
- The module has no resource lookup. No resource extraction was needed.
- The source has no resource-ID mapping request. No resource DLL text, empty
  slot, missing block, language, or lookup path applies.
- Shared declaration requests: none. Root retains `include/resource_ids.h` and
  `include/game_globals.h`; the header owner retains `include/gameinfo.h`.

The registry-selected original function packets were inspected for all 42 VAs.
They are under `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/`.
Their SHA256 values are:

- `0044C5A0_RGE_Campaign_Info.txt` `abadb3af4c5d0d6bbe437b82bb94f97ae20387dab9e2a1094947e7b7ea5abd82`
- `0044C780_RGE_Campaign_Info.txt` `cf247b56e03cbbfd7979f736a906ee2fd940fd72f877f0adf09430178e453862`
- `0044C870_RGE_Campaign_Info.txt` `c6b32d94176f6815ae2b2b6aa2b9753ee7456336cca9ed85af9d364f0661e45b`
- `0044C8A0_save.txt` `892081a2c3d539a6ab1acb73a7a7876df2eaac46cd8c747fdbbfe949447cf606`
- `0044C930_rehook_campaigns.txt` `3796e9287a901dd5fb3c9aacfabb811df02ac6e8903c6c7684e0d8e5fc91ba3b`
- `0044CA90_set_current_scenario.txt` `5534feb1171578f5c152812f9b77b7355110d51eeff0352addfc6fe1d0cc997b`
- `0044CAD0_verify_campaign_name.txt` `afb50b68b4c73cb2f14f44ecc6be2717a447e6d0fa78808d74c020c54bf97eb4`
- `0044CB20_get_scenario_list.txt` `a0ddae41e8164f0c51cfff2ea8f87f3fa27a3bff318a20b77d0407f08e562708`
- `0044CBB0_get_current_scenario.txt` `0a49ffa1f225931df20fa9b1095ffdb2ad20582e0bff451967dc35d7cadbe75f`
- `0044CBC0_notify_of_scenario_complete.txt` `6dfe15b551477134a393640a25fa9a4ff9f77b2bf579b53f4b542b2dc03a0f1d`
- `0044CC20_open_scenario.txt` `788f903f1f9a23ea4dd627299217360a66a4fa38e4e24df00c146d2870a74fc7`
- `0044CC40_RGE_Person_Info.txt` `f7781c5a390fcb1068a114ab418639f85e6fe3b38214b4672870d6ffd989a359`
- `0044CD40_RGE_Person_Info.txt` `1849ff8447bdca82c9cc270083aa42ea2bef1e76611966d374e1a0e180d0209a`
- `0044CDA0_RGE_Person_Info.txt` `cfe3767e2addcdcefef330c96d994cad3cbe232d5fea69d741b6a0b792b67838`
- `0044CE10_save.txt` `58f1f1e943cecba4531f3f12c7ee782b2c68567fc705472d74d25a20c453373a`
- `0044CE90_rehook_campaigns.txt` `874fbd6621bbad71827823ca3a11d78108884b5c801e9c6f58b5c04d208bb221`
- `0044CEE0_get_name.txt` `98dba8ebc9b2fce0cb362b423f2c73fe883e22654dddcdc8af9167d2c83ec0b2`
- `0044CEF0_set_current_campaign.txt` `5c1122373dedcf71c3bf3ce902ab6cc9cef4df21e4f9e12fadaeb7ba71fe28d8`
- `0044D050_get_current_campaign.txt` `98653743578ace7610eed68be907b0ad826991b2d72e85ed31e7223b51142c00`
- `0044D0C0_get_current_scenario.txt` `3cf759bf3d17626abb7150e1793127b0dc21a059a304298557d4e01f67a59346`
- `0044D0F0_set_current_scenario.txt` `d5e78785e6ff0dfc75485ebaaad25757fa2b8835e0e292ca485668a94bc54685`
- `0044D130_get_scenario_list.txt` `28a443aa273e88b54fea3b5f8fc3fcb57356367cdce1ff1a1af69f66482ccdba`
- `0044D160_notify_of_scenario_complete.txt` `c480289c3f4e6c0962572dd208408d35f45beeaa0f13209a902b774fb6600e72`
- `0044D180_open_scenario.txt` `e17b71c0e3e68078b66c463aa172b0f0464775be245d1ce1ef956b112182ceed`
- `0044D1A0_RGE_Game_Info.txt` `90ef61a29a1ddf57f6134891b9d6ad2e5f4cbfe546644cbf9efb41944e013055`
- `0044D300_RGE_Game_Info.txt` `e2f0b678c60f59724d2f1b5743a5bd569762b21fcb4e413edcf81d356efb9a6e`
- `0044D3B0_save.txt` `ff06e34891a89219100939b57ac4c57fd94b8b506061bf16625386f71159d7dc`
- `0044D470_find_campaigns.txt` `4e483cc24e3c82144ff0223560a5ab30bfcb1f27e14c512c98b371831bb0769f`
- `0044D710_add_new_person.txt` `acfb9c9a79b3e7cccbce167aa4c1deadbf4abc48087a92b99b44f7405de3b2c5`
- `0044D7D0_set_current_person.txt` `3782f5266d30f23f3bc473b93086b8e93d82281c3b2bcef3a33ec18b6818a13e`
- `0044D7F0_set_current_campaign.txt` `9a1e72c861e31df73d49e4dfcf440d9708ad3f1d86040ed3a46e11730f52d497`
- `0044D820_set_current_scenario.txt` `b8dfdc4e6c607712573a54771d3ab28e20a2bbc2189459136c5a6b783b9d0b97`
- `0044D850_get_people_list.txt` `1e3bb8821087e5c5dce2e69f965904d25c7303d3ccaa1f2b501634b397aad214`
- `0044D8C0_get_campaign_list.txt` `d8c192b94ba64e4fd21f6da316c5405721aec4e479a6057173537e975121592d`
- `0044D940_get_scenario_list.txt` `a5d532dfbfbaa641d3ed5e2cee1fca8429fd6cd514280204f1bcf2bf95c5e3c1`
- `0044D990_get_current_scenario.txt` `6da2f2ebe9fedec69d8eda1d7fe1135c9b37427372a1a7cf81724a7418f11591`
- `0044D9B0_get_current_campaign.txt` `658b84213bd482d4bfaa5864d292240315b3152857750f5993145da6026de606`
- `0044D9D0_get_current_player.txt` `0912e9a25fc19ae4bcc4f2bec81250c8ec6c917a9b2f1e47d9c0ea7cc703d16f`
- `0044D9E0_get_current_player_name.txt` `d77694de27bc4395b5bfa4db2563e28923a08f138c13ad13885d7acdfac9835b`
- `0044DA00_notify_of_scenario_complete.txt` `f98d89cdba12c4ede6ca30571ceb0ad2a96144d229d55ebd5bb3df7266c53fc0`
- `0044DA30_open_scenario.txt` `9346e8a2341c2cacdabbcdf52c942152c5b052f53fac1d45a0622b05db1ba6b0`
- `0044DA50_remove_player.txt` `93cced7680cf2225b2133a1408767cd2bceed282acd6a35c4560dd53fb9f9ff4`

Other evidence hashes:

- PDB scoped-symbol index: `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json` — `adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.
- Registry: `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/gameinfo.cpp.json` — `389d8cc75acce8259c0477a890b977768062cc2931a09a9f6a7e8a2e7746371e`.
- Original executable: `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe` — `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
- Runtime base language DLL: `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll` — `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`.
- Runtime expansion language DLL: `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll` — `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`.
- Preserved baseline object: `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/gameinfo.obj` — `2fd2e29f62bd2318f1dd5b0c94b6add6c635db50b8dc39bfb1d66990aeab8997`.

The PDB records and function packets support parameter and local names only.
They do not prove that the invented `i` and `new_list` names were original source
spellings. The source keeps all unresolved local and declaration mappings that
lack reliable evidence.

## Code-generation and ownership risks

Only identifier spellings changed. No type, cast, scope, storage duration,
object layout, call target, relocation, ABI symbol, literal, or statement changed.
The source still uses the existing `gameinfo.h` declarations. Debug names and line
records can change. Generated-code equality remains unvalidated.

## Validation limits

I reviewed the complete Git diff and ran `git diff --check`.
Compilation, matching, audits, and tests were not run.
No build, compiler check, game, runtime, or validation command was run.
