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
