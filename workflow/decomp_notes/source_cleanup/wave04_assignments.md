# Cleanup wave 04 assignments

The user authorized more owners for uncovered files.
This wave assigns the remaining 48 modules from the 225-module preparation inventory.
The earlier pilot and waves 01–03 cover the other 177 modules.
Preparation does not authorize exceeding ten active owners, including corrections.
Root can launch these owners while review continues under the current user authorization.

Owners use `openai-codex-secondary/gpt-5.6-sol`, medium thinking.
Workers use `openai-codex-secondary/gpt-5.6-luna`, xhigh thinking.
Each owner can run eight source workers. Workers cannot delegate.

## Exclusive assignments

Slots are under `build/source-cleanup-20260915/wave-worktrees/`.
Sources use the exact module spelling below with `.cpp`.
Workers edit only their source and `workflow/decomp_notes/source_cleanup/wave04/<module>.md`.
Owners edit their assigned headers and `workflow/decomp_notes/source_cleanup/wave04/owner-NN.md`.
Owners also integrate their approved worker commits without omitted changes.

| Owner | Group | Owner slot | Worker slots | Modules in worker order |
| --- | --- | --- | --- | --- |
| 23 | Drawing and sprite support | 199 | 200–207 | asp_list, asprite, drawarea, Mouseptr, Shape, spanlist, sprite, point |
| 24 | Paths and views | 208 | 209–216 | Path, pathsys, diam_map, view, vw_dimap, vw_main, tvw_dmap, tvw_main |
| 25 | Players and commands | 217 | 218–225 | player, tplayer, tmplayer, com_hand, com_obj, Command, tcommand, tobj_lst |
| 26 | Worlds and scenarios | 226 | 227–234 | world, tworld, scenario, tscenaro, sceninfo, campaign, rmm_tdbc, effects |
| 27 | Game core and victory | 235 | 236–243 | basegame, tribegam, main, getdxver, tech, teffects, victory, tvictory |
| 28 | Resources and timelines | 244 | 245–252 | Res_file, rge_fio, rge_tslc, t_histry, Timeline, tpnl_tml, tpnl_txl, trig |

Headers use `include/<module>.h`, with these exceptions:

- Owner 24 owns `include/path.h` for `Path.cpp`.
- Owner 24 owns `include/vw_main.h` once, for both `vw_main.cpp` and `tvw_main.cpp`.
- No `include/tvw_main.h` assignment exists.

Root retains every other header, especially `include/resource_ids.h` and `include/game_globals.h`.
Header readers do not block independent work. Send cross-group declaration requests to root.

## Required procedure

Read `AGENTS.md` and all cleanup, comments, resource, owner, and testing guides before work.
Inspect procedure-scoped PDB parameters, locals, and registers for every source function.
Use the original executable as the behavior oracle and the absolute main-root evidence paths.
Recover original names only with reliable declaration evidence. Do not force reused PDB homes into declarations.
Preserve types, scopes, storage, casts, explicit `this->`, evaluation order, calls, and original bugs.
No structural rewrites, assembly changes, binary-dependency changes, or source-owner changes are allowed.
Use 1TBS and readable wrapping without a fixed 80-column limit.

No compilation, builds, matching checks, audits, validation commands, tests, or games are permitted.
Evidence extraction and complete Git diff review are permitted. Read tool `--help` before use.
Preserve all logs, outputs, experiments, assets, worktrees, and history. Never delete incident evidence.
Do not copy original assets or preserved builds into worker trees.
Keep new extraction output under the worker's own `build/` directory.

Owners review complete worker diffs and reports. Resume the same workers for corrections.
Root reviews complete group diffs before main integration.
All cleanup remains unvalidated until the final comparison against the preserved pre-cleanup build.
Keep at least 40 GiB free during preparation. Never reset or reprepare active trees.
