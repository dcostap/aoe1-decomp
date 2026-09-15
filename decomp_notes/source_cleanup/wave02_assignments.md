# Cleanup wave 02 assignments

The user authorized nine more owners. This assignment covers 72 additional modules.
Owner 03 can finish its existing screen corrections while these nine owners work.
At most ten owners and eight source workers per owner may run concurrently.
No other total subagent limit applies. Do not refill beyond these assignments.

Use `docs/source_cleanup_owners.md` and all current cleanup guides.
Owners use `openai-codex-secondary/gpt-5.6-sol`, thinking `medium`.
Source workers use `openai-codex-secondary/gpt-5.6-luna`, thinking `xhigh`.
Owners may launch their eight source workers, but not additional owners. Workers cannot delegate.

## Worktrees and ownership

All slots are under `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/`.
Each branch is `cleanup/staging-20260915-NN`, where `NN` is its slot number.
The root launch record supplies the exact common base and managed owner IDs.

Each worker owns one listed source and `decomp_notes/source_cleanup/wave02/<module>.md` only.
Each owner edits its listed headers and `decomp_notes/source_cleanup/wave02/owner-NN.md` only, apart from integrating approved worker commits.
Root retains all unlisted headers, especially `include/resource_ids.h` and `include/game_globals.h`.
Reading a header does not lock its consumers. Only work needing a pending definition must wait.
Do not edit another worktree or update active worker trees.

## Owner 04: action and task support

Integration slot: **28**. Ledger: `wave02/owner-04.md`.

| Worker slot | Source | Header edited only by owner 04 |
| --- | --- | --- |
| 29 | src/act_list.cpp | include/act_list.h |
| 30 | src/act_move.cpp | include/act_move.h |
| 31 | src/action.cpp | include/action.h |
| 32 | src/task.cpp | include/task.h |
| 33 | src/task_lst.cpp | include/task_lst.h |
| 34 | src/tact_lst.cpp | include/tact_lst.h |
| 35 | src/taction.cpp | include/taction.h |
| 36 | src/ttsk_lst.cpp | include/ttsk_lst.h |

## Owner 05: Tribe actions

Integration slot: **37**. Ledger: `wave02/owner-05.md`.

| Worker slot | Source | Header edited only by owner 05 |
| --- | --- | --- |
| 38 | src/tact_art.cpp | include/tact_art.h |
| 39 | src/tact_bld.cpp | include/tact_bld.h |
| 40 | src/tact_cnv.cpp | include/tact_cnv.h |
| 41 | src/tact_dar.cpp | include/tact_dar.h |
| 42 | src/tact_hea.cpp | include/tact_hea.h |
| 43 | src/tact_hnt.cpp | include/tact_hnt.h |
| 44 | src/tact_mob.cpp | include/tact_mob.h |
| 45 | src/tact_rep.cpp | include/tact_rep.h |

## Owner 06: AI items and build modules

Integration slot: **46**. Ledger: `wave02/owner-06.md`.

| Worker slot | Source | Header edited only by owner 06 |
| --- | --- | --- |
| 47 | src/aibitm.cpp | include/aibitm.h |
| 48 | src/aiblditm.cpp | include/aiblditm.h |
| 49 | src/aibobj.cpp | include/aibobj.h |
| 50 | src/aiconitm.cpp | include/aiconitm.h |
| 51 | src/airesitm.cpp | include/airesitm.h |
| 52 | src/aitchitm.cpp | include/aitchitm.h |
| 53 | src/aibldmod.cpp | include/aibldmod.h |
| 54 | src/aiconmod.cpp | include/aiconmod.h |

## Owner 07: AI support modules

Integration slot: **55**. Ledger: `wave02/owner-07.md`.

| Worker slot | Source | Header edited only by owner 07 |
| --- | --- | --- |
| 56 | src/aidipmod.cpp | include/aidipmod.h |
| 57 | src/aiemomod.cpp | include/aiemomod.h |
| 58 | src/aiinfmod.cpp | include/aiinfmod.h |
| 59 | src/aimdmod.cpp | include/aimdmod.h |
| 60 | src/airchmod.cpp | include/airchmod.h |
| 61 | src/airesmod.cpp | include/airesmod.h |
| 62 | src/aistrmod.cpp | include/aistrmod.h |
| 63 | src/aitacmod.cpp | include/aitacmod.h |

## Owner 08: master objects

Integration slot: **64**. Ledger: `wave02/owner-08.md`.

| Worker slot | Source | Header edited only by owner 08 |
| --- | --- | --- |
| 65 | src/m_ac_obj.cpp | include/m_ac_obj.h |
| 66 | src/m_an_obj.cpp | include/m_an_obj.h |
| 67 | src/m_co_obj.cpp | include/m_co_obj.h |
| 68 | src/m_dg_obj.cpp | include/m_dg_obj.h |
| 69 | src/m_mi_obj.cpp | include/m_mi_obj.h |
| 70 | src/m_mo_obj.cpp | include/m_mo_obj.h |
| 71 | src/m_s_obj.cpp | include/m_s_obj.h |
| 72 | src/tm_b_obj.cpp | include/tm_b_obj.h |

## Owner 09: object support

Integration slot: **73**. Ledger: `wave02/owner-09.md`.

| Worker slot | Source | Header edited only by owner 09 |
| --- | --- | --- |
| 74 | src/ani_obj.cpp | include/ani_obj.h |
| 75 | src/dpl_obj.cpp | include/dpl_obj.h |
| 76 | src/misl_obj.cpp | include/misl_obj.h |
| 77 | src/mst_play.cpp | include/mst_play.h |
| 78 | src/obj_list.cpp | include/obj_list.h |
| 79 | src/t_tre_ob.cpp | include/t_tre_ob.h |
| 80 | src/tm_co_ob.cpp | include/tm_co_ob.h |
| 81 | src/tm_tre_o.cpp | include/tm_tre_o.h |

## Owner 10: dialogs

Integration slot: **82**. Ledger: `wave02/owner-10.md`.

| Worker slot | Source | Header edited only by owner 10 |
| --- | --- | --- |
| 83 | src/dlg_abt.cpp | include/dlg_abt.h |
| 84 | src/dlg_conf.cpp | include/dlg_conf.h |
| 85 | src/dlg_dip.cpp | include/dlg_dip.h |
| 86 | src/dlg_help.cpp | include/dlg_help.h |
| 87 | src/dlg_list.cpp | include/dlg_list.h |
| 88 | src/dlg_menu.cpp | include/dlg_menu.h |
| 89 | src/dlg_msg.cpp | include/dlg_msg.h |
| 90 | src/dlg_sedm.cpp | include/dlg_sedm.h |

## Owner 11: additional screens

Integration slot: **91**. Ledger: `wave02/owner-11.md`.

| Worker slot | Source | Header edited only by owner 11 |
| --- | --- | --- |
| 92 | src/scr_ach.cpp | include/scr_ach.h |
| 93 | src/scr_cred.cpp | include/scr_cred.h |
| 94 | src/scr_end.cpp | include/scr_end.h |
| 95 | src/scr_info.cpp | include/scr_info.h |
| 96 | src/scr_mp.cpp | include/scr_mp.h |
| 97 | src/scr_mps.cpp | include/scr_mps.h |
| 98 | src/scr_stms.cpp | include/scr_stms.h |
| 99 | src/scr_trb.cpp | include/scr_trb.h |

## Owner 12: communication support

Integration slot: **100**. Ledger: `wave02/owner-12.md`.

| Worker slot | Source | Header edited only by owner 12 |
| --- | --- | --- |
| 101 | src/com_addr.cpp | include/com_addr.h |
| 102 | src/com_err.cpp | include/com_err.h |
| 103 | src/com_loby.cpp | include/com_loby.h |
| 104 | src/com_q.cpp | include/com_q.h |
| 105 | src/com_serv.cpp | include/com_serv.h |
| 106 | src/com_sess.cpp | include/com_sess.h |
| 107 | src/com_spd.cpp | include/com_spd.h |
| 108 | src/com_sync.cpp | include/com_sync.h |

## Shared evidence and review limits

Use absolute main-root paths for evidence omitted by sparse checkout:

- `inventory/pdb/scoped_symbols.json`: inspect every assigned procedure's parameters, locals, and registers.
- `inventory/functions/`: select packets through the source registry.
- `orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`: original behavior oracle.
- `runtime/language.dll` and `runtime/languagex.dll`: current resource inputs.
- `orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`: original expansion reference.
- `build/source-cleanup-20260915/preparation/baseline-build/`: preserved pre-cleanup output; do not rebuild or change it.

Pinned CRT/SDK paths come from `config/toolchain.json`. Use local evidence first.
Keep extraction output in each worker's own `build/`. Record actual paths, hashes, and per-ID resource evidence.
Distinguish missing blocks, empty slots, and expansion overrides. Missing text does not prevent naming a proved role.

Preserve original name spelling and leave uncertain storage mappings unchanged.
Preserve casts, types, scopes, explicit `this->`, call targets, expression order, and literal semantics.
Use 1TBS. Do not introduce unnecessary wrapping on short calls or signatures.
Owner reviews must inspect full diffs and reports, not summaries alone.
Resume the same workers for corrections and retain all correction history.

No compilation, builds, matching, audits, tests, or games during this wave.
Root reviews complete group changes before integration. All integrations remain reviewed and unvalidated.
Final validation must compare against the preserved pre-cleanup output, including pre-existing differences from the original executable.
