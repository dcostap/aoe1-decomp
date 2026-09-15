# Cleanup wave 01 assignments

The user authorized three owners, with up to eight source workers each.
This assignment uses `docs/source_cleanup_owners.md` and the current source-cleanup guides.
The earlier coordination note's header locks and worker limit are historical, not this wave's rules.

All worktrees are under `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/`.
All owners use Sol/medium. All source workers use Luna/xhigh, with exact model IDs from the workflow.
Each source worker owns its listed source and `decomp_notes/source_cleanup/wave01/<module>.md` only.
Each owner edits its listed headers and `decomp_notes/source_cleanup/wave01/owner-0N.md` only, apart from integrating approved source commits.
Root retains all other headers, including `include/resource_ids.h`.

## Owner 01: actions

Integration worktree: `slot-01`. Group ledger: `decomp_notes/source_cleanup/wave01/owner-01.md`.

| Worker worktree | Source | Header edited only by owner 01 |
| --- | --- | --- |
| slot-04 | src/act_atak.cpp | include/act_atak.h |
| slot-05 | src/act_bird.cpp | include/act_bird.h |
| slot-06 | src/act_entr.cpp | include/act_entr.h |
| slot-07 | src/act_expl.cpp | include/act_expl.h |
| slot-08 | src/act_gath.cpp | include/act_gath.h |
| slot-09 | src/act_make.cpp | include/act_make.h |
| slot-10 | src/act_misl.cpp | include/act_misl.h |
| slot-11 | src/act_tran.cpp | include/act_tran.h |

## Owner 02: random maps

Integration worktree: `slot-02`. Group ledger: `decomp_notes/source_cleanup/wave01/owner-02.md`.

| Worker worktree | Source | Header edited only by owner 02 |
| --- | --- | --- |
| slot-12 | src/rmm_base.cpp | include/rmm_base.h |
| slot-13 | src/rmm_clif.cpp | include/rmm_clif.h |
| slot-14 | src/rmm_cntr.cpp | include/rmm_cntr.h |
| slot-15 | src/rmm_elev.cpp | include/rmm_elev.h |
| slot-16 | src/rmm_land.cpp | include/rmm_land.h |
| slot-17 | src/rmm_obj.cpp | include/rmm_obj.h |
| slot-18 | src/rmm_shal.cpp | include/rmm_shal.h |
| slot-19 | src/rmm_terr.cpp | include/rmm_terrain_generator.h |

## Owner 03: screens

Integration worktree: `slot-03`. Group ledger: `decomp_notes/source_cleanup/wave01/owner-03.md`.

| Worker worktree | Source | Header edited only by owner 03 |
| --- | --- | --- |
| slot-20 | src/scr_save.cpp | include/scr_save.h |
| slot-21 | src/scr_name.cpp | include/scr_name.h |
| slot-22 | src/scr_set.cpp | include/scr_set.h |
| slot-23 | src/scr_sing.cpp | include/scr_sing.h |
| slot-24 | src/scr_main.cpp | include/scr_main.h |
| slot-25 | src/scr_cam.cpp | include/scr_cam.h |
| slot-26 | src/scr_cams.cpp | include/scr_cams.h |
| slot-27 | src/scr_cj.cpp | include/scr_cj.h |

## Shared evidence

Main-tree root: `C:/Projects/my_decomps/aoe1_attempt3`.
Use this absolute root for files omitted by sparse checkout:

- `inventory/pdb/scoped_symbols.json`: procedure-scoped names and types. Inspect each assigned function, including register records.
- `inventory/functions/`: reference packets, selected through each source registry's VAs.
- `orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`: original behavior oracle.
- `runtime/language.dll` and `runtime/languagex.dll`: actual resource inputs; record hashes and lookup fallback.
- `orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`: different original expansion reference.
- `build/source-cleanup-20260915/preparation/baseline-build/`: preserved pre-cleanup build. Do not rebuild it.
- `build/source-cleanup-20260915/preparation/plan.json`: module inventory and historical include graph, not an editing lock.

Pinned SDK/CRT paths come from each checkout's `config/toolchain.json`.
No build, compiler check, matching, audit, test, or game runs during this wave.
The root launch record supplies the exact shared base commit and owner agent IDs.
