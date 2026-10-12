# Cleanup wave 03 assignments

The user authorized ten more owners when ready. This assignment reserves 80 additional modules.
Root launches owners from this queue as capacity permits. Preparation is not a launch.
Keep at most ten active owners, including correction runs. Each owner may run eight source workers.
Pause launches when completed work needs root review. Do not refill beyond these assignments.

Owners use `openai-codex-secondary/gpt-5.6-sol`, thinking `medium`.
Workers use `openai-codex-secondary/gpt-5.6-luna`, thinking `xhigh`.
Workers cannot delegate. Owners cannot create additional owners.
Use all current source-cleanup guides and `workflow/docs/source_cleanup_owners.md`.
No compiler, build, matching, audit, test, or game commands during cleanup.

## Ownership and slots

All slots are under `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/`.
Each branch is `cleanup/staging-20260915-NNN`, using the slot number.
The launch ledger records the common base and managed IDs when root starts each owner.

Each table row lists eight modules in worker-slot order. Sources are `src/<module>.cpp`, except `src/Dsutil.c`.
Workers own only their source and `workflow/decomp_notes/source_cleanup/wave03/<module>.md`.
Owners edit their listed module headers and `workflow/decomp_notes/source_cleanup/wave03/owner-NN.md` only, apart from integrating worker commits.

| Owner | Group | Integration slot | Worker slots | Modules in slot order |
| --- | --- | --- | --- | --- |
| 13 | AI core and build support | 109 | 110–117 | aimodule, aipbook, aiuaimod, aitrdmod, taibldmd, taiconmd, taicrule, taipbook |
| 14 | Tribe AI and game information | 118 | 119–126 | taiinfmd, taimdmd, tairesmd, taistrmd, taitacmd, taiuaimd, taunt, gameinfo |
| 15 | Active objects and remaining actions | 127 | 128–135 | act_obj, move_obj, stat_obj, t_b_obj, t_c_obj, tact_tek, tact_trd, tact_wnd |
| 16 | Maps and visibility | 136 | 137–144 | map, tmap, infmap, visible, vis_unit, zone_map, fractal, rmm_dbct |
| 17 | Core panels | 145 | 146–153 | Panel, Panel_ez, pnl_btn, Pnl_drop, pnl_edit, pnl_lst, Pnl_txt, Pnl_scbr |
| 18 | Panel and dialog support | 154 | 155–162 | pnl_dlg, Pnl_inp, Pnl_msg, Pnl_pic, Pnl_scr, pnl_sld, rdlg_lst, tdlg_lst |
| 19 | Tribe panels | 163 | 164–171 | rpnl_tbx, rpnl_tim, spnl_obj, tpnl_btn, tpnl_inv, tpnl_obj, tpnl_pop, tpnl_tim |
| 20 | Audio and image support | 172 | 173–180 | Cdaudio, music, Sound, Sounddrv, Dsutil, flics, Dib, Picture |
| 21 | Game and editor screens | 181 | 182–189 | scr_game, scr_sed, scr_sed2, scr_sedm, scr_sedo, Scr_sels, scr_vc, dlg_smsg |
| 22 | Text and file support | 190 | 191–198 | Chat, color, colorlog, debuglog, dstring, file_stf, mystring, registry |

For owners 13–16 and 19, each owned header is `include/<module>.h` with the exact listed spelling.
The remaining header lists below follow their module order:

- Owner 17: `include/panel.h`, `include/panel_ez.h`, `include/pnl_btn.h`, `include/pnl_drop.h`, `include/pnl_edit.h`, `include/pnl_lst.h`, `include/Pnl_txt.h`, `include/Pnl_scbr.h`.
- Owner 18: `include/pnl_dlg.h`, `include/Pnl_inp.h`, `include/pnl_msg.h`, `include/pnl_pic.h`, `include/Pnl_scr.h`, `include/pnl_sld.h`, `include/rdlg_lst.h`, `include/tdlg_lst.h`.
- Owner 20: `include/cdaudio.h`, `include/music.h`, `include/sound.h`, `include/sounddrv.h`, `include/dsutil.h`, `include/flics.h`, `include/dib.h`, `include/Picture.h`.
- Owner 21: `include/scr_game.h`, `include/scr_sed.h`, `include/scr_sed2.h`, `include/scr_sedm.h`, `include/scr_sedo.h`, `include/scr_sels.h`, `include/scr_vc.h`, `include/dlg_smsg.h`.
- Owner 22: `include/chat.h`, `include/color.h`, `include/colorlog.h`, `include/debuglog.h`, `include/dstring.h`, `include/file_stf.h`, `include/mystring.h`, `include/registry.h`.

Root retains every other header, including `include/resource_ids.h` and `include/game_globals.h`.
Read-only header use does not lock consumers. Only work needing a pending definition must wait.
Existing wave 01 and wave 02 assignments remain separate. Do not edit those owners' files.

## Evidence and review

Use absolute main-root paths for omitted evidence. Do not copy original assets or preserved compiler outputs into worker trees.
Inspect each function's `inventory/pdb/scoped_symbols.json` records and its registry-selected original packets.
The original executable remains the behavior oracle. Preserve the pinned toolchain and pre-cleanup output.

Keep original names when reliable declaration evidence supports them. Do not infer a name from reused stack labels alone.
Preserve casts, types, scopes, storage, calls, explicit `this->`, expression order, and original bugs.
Use 1TBS and avoid unnecessary wrapping. No structural rewrites or assembly changes are authorized.

Submit resource requests to root with per-ID provenance and lookup evidence.
Distinguish empty slots, missing blocks, and expansion overrides. Missing text does not block a proved-purpose name.
Keep extraction output in each worker's own `build/` directory. Preserve rejected work and correction history.

Owners read complete worker diffs and reports, resume the same workers for corrections, and integrate complete approved commits.
Root reads complete group diffs before integration. Copy full hashes directly from Git; do not reconstruct them.
All integrations remain reviewed and unvalidated until the final generated-output and runtime validation stage.

## Preparation limits

Reserve at least 40 GiB of free disk space. Stop preparation without deleting existing work if space falls below that limit.
Prepare only the 90 assigned worktrees. Do not modify active trees or remove historical artifacts.
