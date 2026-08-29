# Final grouped compile debt

## Scope

The clean full grouped sweep requested 221 groups. It compiled 152 groups.
It found 69 compile failures before the final focused repairs.

The baseline evidence is in:

- `build/audits/full_grouped_clean2/report.json`
- `build/audits/full_grouped_clean2/failures_by_module.txt`

The failure record names each module and its first compiler diagnostic. It does
not copy the full generated report.

## Current root buckets

Two baseline failures are resolved:

- `tscenaro`: current main `4858419ce` added the missing `rge_base_game` provider.
- `Panel`: `164913da4` added the proven `TPanel` friend for `prog_active`.

The remaining debt has 67 baseline modules:

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
- **1 enum and access relation:** `scr_cams`.
- **1 type and global declaration:** `tact_art`.
- **2 debug_rand linkage conflicts:** `rmm_tdbc`, `tact_cnv`.
- **1 debug_srand and global declaration conflict:** `t_b_obj`.
- **1 RESFILE_load ABI mismatch:** `sounddrv`.
- **1 global redeclaration:** `Shape`.
- **1 debug_timeGetTime linkage conflict:** `scr_cred`.
- **1 communications-handler access relation:** `com_spd`.
- **1 missing members and access relation:** `dlg_help`.
- **1 WinAPI linkage declaration conflict:** `Res_file`.

## Focused proof

The rebased four-module gate passed for `dib`, `basegame_cpp`, `com_loby`, and
`Panel`. It reported 311 registered-owner matches.

The gate report is `build/audits/rebased_compile2/report.json`.
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
