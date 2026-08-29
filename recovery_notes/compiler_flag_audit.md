# Compiler flag metadata audit

Date: 2026-08-29

This note records the flag audit after the stale-flag cleanup wave. The audit
uses `tools/audit_translation_unit_flags.py`. It compares current grouped flags,
per-function response files, PDB source modules, and original EXE prologues.
It does not compare source bodies.

## Final audit result

Command:

```text
python tools/audit_translation_unit_flags.py --output build/audits/final_release_flag_audit.json
```

The command found 5,395 owners in 221 current groups and 241 proposed source
modules. It found 251 findings:

| Finding | Count | Classification |
| --- | ---: | --- |
| `incompatible_custom_overlay` | 138 | Proposed-module migration evidence. Keep the owner-specific files. |
| `target_named_tu_flags` | 98 | Naming warnings. Keep the existing grouped response files. |
| `mixed_frame_need` | 10 | Mixed original EBP and FPO evidence. Keep grouped flags. |
| `mixed_language` | 1 | Proposed-module language evidence. Do not change source language. |
| `frame_flag_conflict` | 4 | Current compiler warnings for `Path` and `map`. Keep grouped flags. |

The report has zero blocking issues and exits with status zero. Proposed-module
errors remain migration evidence. They do not block valid current groups.
The audit reports no stale per-function exception.

## Verified repairs

Only two small modules passed both grouped and direct-owner validation.

### `scr_end`

Commit: `e4fca3c91`

Removed these redundant per-function response files:

- `config/flags/00493C00_TribeEndScreen.rsp`
- `config/flags/00493C90_action.rsp`

The grouped response file remains `config/flags/004936D0_TribeEndScreen.rsp`.
All three registered owners passed standalone checks with `Result: MATCH` and
`0.0000%`:

- `004936D0`
- `00493C00`
- `00493C90`

Isolated grouped validation passed with the grouped COFF object and symbol
checks.

### `scr_load`

Commit: `7004fc4d3`

Removed this redundant per-function response file:

- `config/flags/0049E0A0_TribeLoadSavedGameScreen.rsp`

The grouped response file remains
`config/flags/0049DD40_TribeLoadSavedGameScreen.rsp`.
All four registered owners passed standalone checks with `Result: MATCH` and
`0.0000%`:

- `0049DD40`
- `0049E0A0`
- `0049E150`
- `0049E2B0`

Isolated grouped validation passed with the grouped COFF object and symbol
checks.

The old `0042F290` stale exception no longer exists. The final metadata cleanup
also removed these obsolete response files:

- `config/flags/00476D80_setup.rsp`
- `config/flags/00503600_saveTheTown.rsp`
- `config/flags/00512630_scenario_save.rsp`
- `config/flags/00519CA0_update.rsp`

## Unresolved `incompatible_custom_overlay`

These are proposed PDB source modules with two or three distinct individual
flag signatures. They do not prove that one module flag set is safe. Keep the
function-specific response files until a natural module has grouped validation
and a standalone `MATCH` for every affected owner.

The affected proposed modules are:

```text
ACT_GATH.cpp, ACT_misl.cpp, Act_atak.cpp, Chat.cpp, Dlg_msg.cpp,
Drawarea.cpp, Dsutil.c, Mouseptr.cpp, Panel_ez.cpp, Path.cpp,
Pnl_drop.cpp, Pnl_inp.cpp, Pnl_msg.cpp, Pnl_pic.cpp, Pnl_scbr.cpp,
Pnl_txt.cpp, Res_file.cpp, Scr_main.cpp, Scr_sels.cpp, Scr_sing.cpp,
Sound.cpp, World.cpp, act_bird.cpp, act_entr.cpp, act_expl.cpp,
act_list.cpp, act_move.cpp, act_obj.cpp, act_tran.cpp, action.cpp,
aibldmod.cpp, aiconmod.cpp, aidipmod.cpp, aiemomod.cpp, aimdmod.cpp,
aimodule.cpp, aipbook.cpp, airchmod.cpp, airesmod.cpp, aitchitm.cpp,
aiuaimod.cpp, ani_obj.cpp, asp_list.cpp, asprite.cpp, basegame.cpp,
com_addr.cpp, com_obj.cpp, com_spd.cpp, diam_map.cpp,
dlg_abt.cpp, dlg_conf.cpp, dlg_dip.cpp, dlg_help.cpp, dlg_smsg.cpp,
dpl_obj.cpp, dstring.cpp, gameinfo.cpp, m_ac_obj.cpp, m_an_obj.cpp,
m_co_obj.cpp, m_dg_obj.cpp, m_mi_obj.cpp, m_mo_obj.cpp, m_s_obj.cpp,
map.cpp, misl_obj.cpp, move_obj.cpp, mst_play.cpp, obj_list.cpp,
pathsys.cpp, player.cpp, pnl_dlg.cpp, pnl_edit.cpp, rmm_cntr.cpp,
rmm_dbct.cpp, rmm_tdbc.cpp, rpnl_tbx.cpp, rpnl_tim.cpp, scenario.cpp,
scr_ach.cpp, scr_cam.cpp, scr_cams.cpp, scr_cj.cpp, scr_cred.cpp, scr_end.cpp,
scr_game.cpp, scr_info.cpp, scr_load.cpp, scr_mp.cpp, scr_mps.cpp,
scr_sed.cpp, scr_sed2.cpp, scr_sedm.cpp, scr_sedo.cpp, scr_set.cpp,
scr_stms.cpp, scr_trb.cpp, scr_vc.cpp, spanlist.cpp, sprite.cpp,
stat_obj.cpp, t_b_obj.cpp, t_c_obj.cpp, t_tre_ob.cpp, tact_art.cpp,
tact_bld.cpp, tact_cnv.cpp, tact_dar.cpp, tact_hea.cpp, tact_hnt.cpp,
tact_lst.cpp, tact_trd.cpp, taibldmd.cpp, taiconmd.cpp, taiinfmd.cpp,
taimdmd.cpp, taistrmd.cpp, taitacmd.cpp, taiuaimd.cpp, taunt.cpp,
tcommand.cpp, tm_b_obj.cpp, tm_co_ob.cpp, tmap.cpp, tmplayer.cpp,
tplayer.cpp, tpnl_btn.cpp, tpnl_inv.cpp, tpnl_pop.cpp, tpnl_tim.cpp,
tpnl_tml.cpp, tpnl_txl.cpp, tribegam.cpp, tscenaro.cpp, tworld.cpp,
view.cpp, visible.cpp, zone_map.cpp
```

Most differences are `/GX` versus the default `/O2 /Oy` signature. Special
signatures also remain. They include C mode and disabled intrinsics in
`Dsutil.c`, `/Oy-` in `Res_file.cpp` and `visible.cpp`, and a three-way set in
`com_obj.cpp` and `taiinfmd.cpp`. These settings can affect EH, frame layout,
calling context, and exact bytes. Do not remove them from an ungrouped owner.

## Unresolved `target_named_tu_flags`

The 98 warnings identify current groups with more than one owner and a flags
path whose stem starts with one VA. These paths are grouped response files, not
proven function exceptions. They remain unchanged. The warning alone does not
justify deleting or renaming a response file.

Affected current groups:

```text
zone_map, tscenaro, act_move, tpnl_tml, scr_cams, taistrmd, scr_end,
scr_info, taiuaimd, scr_cam, tworld_cpp, scenario,
m_s_obj, act_atak, aiconmod_prefix, aiuaimod, tact_bld, tact_hnt,
scr_load, m_mo_obj, view, taitacmd, tcommand, tribegam_prefix, scr_game,
scr_ach, tpnl_inv, obj_list, act_misl, aipbook_prefix,
player, sound, move_obj, airchmod, chat, dlg_abt,
ani_obj, Scr_sels, com_addr, act_expl, scr_vc_prefix, scr_stms,
scr_sedm, pnl_pic, rpnl_tim, dlg_dip, dsutil, act_bird_cpp,
scr_sing, tpnl_txl, act_list, act_tran, aiemomod, dlg_smsg, dpl_obj,
mst_play, Path, tact_art, taunt, tpnl_btn, tpnl_pop, tpnl_tim, tact_dar,
rmm_tdbc, rmm_cntr, pnl_dlg, tmplayer, dstring, pathsys, tact_lst, pnl_edit,
scr_cred, rmm_dbct, scr_trb, tm_tre_o,
t_c_obj_complete_fresh, sprite_cpp, basegame_cpp, panel_ez,
tmap_cpp, m_ac_obj, com_spd, dlg_msg,
scr_mp_cpp, rpnl_tbx_cpp, act_entr_cpp, tm_b_obj, tact_hea, m_co_obj,
taibldmd, action, dlg_help, tact_trd, taimdmd, pnl_scbr, tact_rep,
misl_obj, taiinfmd
```

## Unresolved frame and language findings

`mixed_frame_need` affects these proposed modules:

```text
Path.cpp, Res_file.cpp, map.cpp, move_obj.cpp, pathsys.cpp,
tribegam.cpp, vis_unit.cpp, visible.cpp
```

The current `Path` and `map` groups also report `mixed_frame_need`.
Owner `0046ACE0` has an original EBP frame while `Path` requests `/Oy`.
The compiler can retain EBP when required. Keep the current grouped flags.
Do not split or add a function flag without grouped and direct checks.

`mixed_language` affects `player.h`. Eight owners have mixed `c` and `cpp` PDB
language evidence. This is structural evidence only. Do not change a body or
force a language flag to clear the warning.

## Reopening conditions

Reopen an unresolved overlay only after the natural source module has one
reviewed compiler owner. First prove the owner set and source order. Then run
grouped validation and a standalone exact check for every affected registered
owner. Keep any setting that changes EH, frame mode, language mode, intrinsics,
or exact output.
