# BaseGame source-module checkpoint

The PDB module is `C:\msdev\work\age1_x1\basegame.cpp`.

## Direct owners

`src/basegame.cpp` owns all 202 normal BaseGame bodies in PDB order.
The group uses `config/flags/0041BAA0_setup.rsp`.
No candidate source or context owns a BaseGame body.

## Provider evidence

`0041E7A0` is the process window callback.
The recovered source uses the natural `WNDPROC` ABI. Its emitted symbol is
`?rge_base_game_wnd_proc@@YGJPAXIIJ@Z`. A fresh focused audit returned
`MATCH`, `0.0000%`, with the correct owner, boundary, and relocations.

`0041B6A0` reads `RGE_Prog_Info::instance`.
`src/basegame.cpp` includes the canonical owner `include/main.h`.
`basegame.h` keeps only its forward declaration.

The constructor calls the BaseGame option setters.
Their PDB source rows are `004226B0` through `004228B0`.
`include/basegame.h` now publishes their exact parameter types.

## Scenario-header overload

The PDB declares the integer overload before the pointer overload.
The integer owner is `0041CE00`.
The pointer owner is `0041CE60`.
VC5 emits the pointer slot at `+0x34`.
It emits the integer slot at `+0x38`.

## Hold

`0041BAA0 RGE_Base_Game::setup`, lines 491-871, remains an accepted-drift hold.
It has no exact registration.

## Command calls

`004212E0` calls World vtable slot `+0xEC`.
The PDB owner is `00540D30 RGE_Game_World::pause(unsigned char)`.
The old `set_world_chat_flag` name was false.

`004212E0` calls Player vtable slot `+0xD4`.
The PDB owner is `00471A70 RGE_Player::command_resign(int, int)`.
Its decorated symbol is `?command_resign@RGE_Player@@UAEEHH@Z`.
It is a public virtual member at slot 53.

The RGE and TRIBE Player vtables both use that owner at slot `+0xD4`.
The PDB and CodeView evidence contain no `set_chat_flag` member.
Do not add that unsupported declaration to `include/player.h`.

The final `004212E0` self call uses BaseGame vtable slot `+0x104`.
The PDB maps it to `RGE_Base_Game::action_user_command(unsigned long,
unsigned long)`.
The base owner is `0041C740`.
The decorated symbol is `?action_user_command@RGE_Base_Game@@MAEHKK@Z`.
`TRIBE_Game` overrides the same slot at `00529A70`.
The old `default_handle_user_command` context name had no PDB support.

`0041EFF0` calls BaseGame virtual slot `+0x88` after its cleanup.
The PDB maps that slot to `setup_comm()`.
The old `reset_comm_tail` context name had no PDB support.

`00421110` calls BaseGame virtual slots `+0xFC` and `+0xBC`.
The PDB maps them to `action_mouse_move` and `handle_idle`.
The old `v_mouse_move` and `handle_mouse_click` context names had no PDB support.

`004219F0` calls BaseGame virtual slot `+0xEC`.
The PDB maps that slot to `handle_query_new_palette`.
The old `base_handle_palette_changed` context name had no PDB support.

`00422FD0` loads `scenario_info` at `+0x08` and tail-jumps to
`RGE_Scenario_File_Info::reload_scenarios`.
The call has no null check.
It does not call an `RGE_Game_Info` method.

## Complete composition gate

The current PDB plan has 202 normal owners.
`src/basegame.cpp` now owns all 202 bodies in PDB order.
It uses canonical provider headers.
It does not include a candidate context.

The final grouped audit reports 186 exact owners.
Each reports `MATCH` and `0.0000%`.

The remaining sixteen owners are nonexact.
They remain in the module source without a false exact claim.
`0041BAA0`, `0041E7D0`, `0041E920`, and `00421BF0` remain accepted drift.

`0041F560` remains verified logic.
The scratch owners are `0041C270`, `0041CCA0`, `0041CFD0`, `0041E700`,
`0041F9F0`, `0041FDE0`, `004206D0`, `00421110`, `00421FA0`, `00422960`,
and `00422B10`.

## Canonical field cleanup

`0041C270` now uses `TDrawSystem::ScreenWidth`.
It uses `RGE_Prog_Info::mouse_scroll_interval`.
The final module registers 186 exact owners.

The direct source now uses fields, literals, normal Win32 calls, and `delete`.
It has no raw data addresses, manual lifetime calls, local IAT wrappers, or
matching-history comments.

`include/game_globals.h` declares the shared BaseGame globals.
`src/game_globals.cpp` defines their typed storage.
The source no longer uses BaseGame address aliases.

`src/Chat.cpp` owns the `TChat` constructor and destructor.
BaseGame emits external calls to both Chat bodies.
The BaseGame source uses CRT and Win32 header declarations.

`RGE_Game_Options` is a nested `struct`.
The PDB symbol for the option setter uses the struct tag form.
This preserves the owner symbol for `00422130` and `00422260`.

`0041CDA0` now uses canonical World and Scenario providers.
It reads `world->scenario` at `+0x5C`.
It calls the pointer `new_scenario_header` overload at `+0x34`.
It calls `RGE_Scenario_Header::save` at `+0x4`.
`delete header` emits the original direct destructor and operator-delete pair.

---

# Final grouped compile debt

## Scope

The clean full grouped sweep requested 221 groups. It compiled 152 groups.
It found 69 compile failures before the final focused repairs.

The baseline evidence is in:

- `build/audits/full_grouped_clean2/report.json`
- `build/audits/full_grouped_clean2/failures_by_module.txt`

The failure record names each module and its first compiler diagnostic. It does
not copy the full generated report.

## Current BaseGame access result

The proof started from `0aa947077`. The focused re-test covered all 57 modules
in the baseline access bucket. It compiled 55 modules. It left no
`RGE_Base_Game` access error in those modules.

The repair is in `include/basegame.h`. It adds one narrow friend for each
current source owner that reads a protected field through `rge_base_game`.
The owners are `RGE_Action_Gather`, `RGE_Campaign`, `RGE_Command`,
`RGE_Dialog_List`, `RGE_Diamond_Map_View`, `RGE_Game_Info`,
`RGE_Master_Static_Object`, `RGE_Panel_Time`, `RGE_Panel_Tool_Box`,
`RGE_Scenario_File_Info`, and `RGE_View`. It also adds the direct action
owners `TRIBE_Action_Build`, `TRIBE_Action_Hunt`, `TRIBE_Action_Make_Obj`,
`TRIBE_Action_Make_Tech`, and `TRIBE_Action_Wonder`.

The remaining owners are `TRIBE_Campaign_Editor_Screen`, `TRIBE_Command`,
`TRIBE_Combat_Object`, `TRIBE_Dialog_Name`, `TRIBE_Master_Building_Object`,
`TRIBE_Mission_Screen`, `TRIBE_Panel_Inven`, `TRIBE_Panel_Object`,
`TRIBE_Panel_Pop`, `TRIBE_Panel_Time`, `TRIBE_Screen_Campaign_Selection`,
`TRIBE_Screen_Game`, `TRIBE_Screen_Info`, `TRIBE_Screen_Main_Error`,
`TRIBE_Screen_Main_Menu`, `TRIBE_Screen_Name`, `TRIBE_Screen_Sed`,
`TRIBE_Screen_Sed_Menu`, `TRIBE_Screen_Sed_Open`,
`TRIBE_Screen_Status_Message`, `TribeAboutDialog`,
`TribeAchievementsScreen`, `TribeConfigDialog`, `TribeDiplomacyDialog`,
`TribeEndScreen`, `TribeLoadSavedGameScreen`, `TribeMenuDialog`,
`TribeSaveGameScreen`, `TribeSelectScenarioScreen`,
`TribeSelectTribeScreen`, `TribeSendMessageDialog`,
`TribeSendQuickMessageDialog`, `TribeSPMenuScreen`, `TChat`, `TEditPanel`,
`TEasy_Panel`, `TMessageDialog`, and `Time_Line_Panel`. It also adds the
direct `color_log` friend. Each relation is supported by direct source use
and its PDB source module.

The final audit is `build/audits/grouped_access2_final/report.json`. Its two
remaining compile errors are outside the BaseGame bucket. Main commit
`0cda8e171` fixes the stale `scr_cams` enum names.

The `scr_game` error identifies `TRIBE_Screen_Game` as the source owner. It
reads `TRIBE_Game::auto_exit_time` and `TRIBE_Game::show_object_id` through a
`TRIBE_Game*`. The narrow `TRIBE_Game` friend is now in
`include/tribegam.h`.

Root-D added `TRIBE_Credits_Screen` and `THelpDialog` to the same central
proof. Their direct uses are `draw_area`, `music_system`, and `save_paused`
in `scr_cred.cpp`, plus `prog_window` in `dlg_help.cpp`. The root-D compile
attempt found no remaining BaseGame access error. It still has independent
linkage, global-type, and missing-member errors.

The focused `scr_game` re-test now compiles the group with no compiler error.
The remaining rows are codegen and ownership results, not access failures.

The final sweep includes `scr_cred`, `dlg_help`, and `scr_game` in
`build/audits/grouped_access2_final_with_roots_d2/report.json`.
That sweep requested 59 groups and compiled 56. The three compile failures
are the stale `scr_cams` enum names on this older worktree, plus independent
`scr_cred` and `dlg_help` declaration debt. Main has the `scr_cams` repair.

## Current root buckets

Two baseline failures are resolved:

- `tscenaro`: current main `4858419ce` added the missing `rge_base_game` provider.
- `Panel`: `258b4a7d2` added the proven `TPanel` friend for `prog_active`.

The remaining debt had 67 baseline modules before the focused repairs below.
The focused repairs resolve the `tact_art` type/global conflict and the
`rmm_tdbc` linkage conflict. `scr_cams` still has only the BaseGame access
errors listed below.

- **56 BaseGame protected-field access:**
  `tpnl_tml`, `scr_end`, `scr_info`, `scr_cam`, `diam_map`, `scenario`,
  `m_s_obj`, `scr_sedo`, `tact_bld`, `tact_hnt`, `scr_load`, `view`, `tcommand`,
  `scr_game`, `scr_ach`, `scr_sed`, `tpnl_inv`, `chat`, `dlg_abt`, `Scr_sels`,
  `scr_vc_prefix`, `scr_stms`, `scr_sedm`, `colorlog`, `dlg_menu`, `rpnl_tim`,
  `tact_wnd`, `campaign`, `dlg_dip`, `scr_sing`, `dlg_smsg`, `tpnl_pop`,
  `tpnl_tim`, `tact_tek`, `dlg_conf`, `pnl_edit`, `scr_trb`,
  `t_c_obj_complete_fresh`, `panel_ez`, `rdlg_lst_cpp`, `ACT_GATH_cpp`,
  `tact_mob_cpp`, `sceninfo`, `dlg_msg`, `rpnl_tbx_cpp`, `tm_b_obj`, `scr_main`,
  `gameinfo`, `scr_save`, `pnl_msg`, `vw_dimap`, `tpnl_obj`, `map`, `scr_name`,
  `Command`, `world`.
- **BaseGame access, including `scr_cams`:** the 56 modules listed above plus
  `scr_cams`. Its enum errors are resolved, but its direct `RGE_Base_Game`
  field reads still need the access agent.
- **1 debug_rand linkage conflict:** `tact_cnv`.
- **1 debug_srand and global declaration conflict:** `t_b_obj`.
- **1 RESFILE_load ABI mismatch:** `sounddrv`.
- **1 global redeclaration:** `Shape`.
- **1 debug_timeGetTime linkage conflict:** `scr_cred`.
- **1 communications-handler access relation:** `com_spd`.
- **1 missing members and access relation:** `dlg_help`.
- **1 WinAPI linkage declaration conflict:** `Res_file`.

## Focused proof

### `scr_cams`, `tact_art`, and `rmm_tdbc`

`scr_cams` used stale `TRIBE_Game::VictoryType_Unknown`,
`ResourceLevel_Unknown`, and `Age_Unknown` names. The canonical enum members
are `VictoryDefault`, `DefaultResources`, and `DefaultAge`. After that repair,
the full source reaches only the protected `draw_area`, `input_enabled`, and
`player_game_info` reads in `RGE_Base_Game`. Do not edit `include/basegame.h`
in this module repair. The access agent owns that remaining relation.

`tact_art` now uses `RGE_Game_World::players[0]` for the `RGE_Player*`
ownership target. `master_players[0]` is an `RGE_Master_Player*` and cannot
feed `change_ownership`. The canonical global provider now declares and
defines `DAT_00574F10` as the `.rdata` value `1.0f` used by
`check_ownership`. The full 11-owner candidate compiled and reported `MATCH`
and `0.0000%` for every owner. Representative checks for `004CCBA0` and
`004CCF30` also reported `MATCH` and `0.0000%`.

`rmm_tdbc` now uses the canonical C++ `debug_rand` declaration supplied by
`basegame.h` through `tribegam.h`. Its local `extern "C"` declaration caused
the C2732 linkage conflict. The full 10-body candidate compiled with no
comparison errors. Its registered owner `004876C0` and four observed owners
reported `MATCH` and `0.0000%`; the other five observed owners retain their
documented nonexact states. The representative `004876C0` check reported
`MATCH` and `0.0000%`.

The final four-module gate passed compilation for `dib`, `basegame_cpp`,
`com_loby`, and `Panel`. A later focused rebuild restored the symbol-proven
`BITMAPINFO256` `struct` tag. `ClipDibBlt` and `GetDibDim` now match.

The canonical C++ linkage for `debug_srand` restores its original symbol and
exact body. `setup_main_window` remains accepted drift after the Timeline and
scenario integration. It has equal size, calls, and branch counts. Its 27
positional differences are a local register-map conflict.

The gate report is `build/audits/final_rebased_compile/report.json`.
Exact checks returned `MATCH` and `0.0000%` for owners `00439700`, `0041C7D0`,
`0041EE90`, and `00463BE0`.

PDB field access records are in `build/pdb_types.txt`. The original symbol and
source records are in `inventory/pdb` and `inventory/functions`.

## Safe next actions

1. Resolve one access relation at a time from PDB source ownership and binary use.
2. Add a friend only when the source module and protected field prove the relation.
3. Repair each linkage or ABI conflict at its canonical declaration.
4. Re-run the four-module gate after each shared-header repair.
5. Keep unresolved claims out of exact-owner promotion.
6. Materialize the pinned DirectPlay headers in sparse workspaces before builds.
