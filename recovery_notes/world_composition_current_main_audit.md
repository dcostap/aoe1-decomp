# Current-main World composition audit

## Scope and evidence

This is an evidence note. It makes no exact-source claim for a natural World
translation unit. The audit uses the original PDB, the original executable,
`orig/ghidra_decomp/world.cpp.asm`, `inventory/pdb/function_source_map.csv`,
and the current canonical headers.

The branch was rebased on current `main` at `6c473fac7`. The post-rebase
checks below use this commit.

## Current composition

`plan_translation_unit.py` reports:

| PDB module | Normal owners | Matching | Accepted drift | Scratch | Registered exact |
| --- | ---: | ---: | ---: | ---: | ---: |
| `World.cpp` | 91 | 79 | 11 | 1 | 78 |
| `tworld.cpp` | 30 | 20 | 7 | 3 | 20 |

The active grouped entries are `world_complete` and `tworld_prefix` in
`config/translation_units.json`. They use `/O2 /Oy /GX` and register only the
matching owners. The wrappers include accepted-drift and scratch bodies as
unregistered observations. They also omit these nearby compiler-generated
companions:

- `00540A20`, the World scalar deleting destructor;
- `0052E020`, the TRIBE World scalar deleting destructor.

`00545C00 objectGroupOnTile` is the one matching World owner absent from
`world_complete`. Current `main` commit `62fc92839` changed this source to
the canonical map, tile, object-list, player, and master-object owners. Its
standalone check now reports `MATCH`, `0.0000%`. The owner still needs grouped
registration. The active `world_complete` wrapper includes this source while
it still includes `world_phase2_context.h`; a direct compile now fails with
class redefinition errors. The grouped entry is not a valid current check.

The current wrappers and owner bodies still use context headers:

- `src/world_cpp_phase2_tu.cpp` uses `src/world_phase2_context.h`;
- `src/tworld_phase2_tu.cpp` uses `src/tworld_phase2_context.h`;
- World owner bodies use `world_scenario_context.h` or
  `world_phase2_context.h`;
- TWorld owner bodies use `tworld_prefix_context.h` or local fallback classes.

These contexts are not canonical owners.

## Remaining blockers

### Owner and header composition

The current canonical core composes without contexts. A VC5 probe with
`world.h`, `world_info.h`, `map.h`, `player.h`, `tplayer.h`, `mst_play.h`,
`com_hand.h`, `effects.h`, `teffects.h`, `color.h`, `sound.h`, `victory.h`,
`tech.h`, `tworld.h`, `tribegam.h`, `rge_fio.h`,
`rge_base_game_global.h`, and `debuglog.h` compiled successfully.

The full World dependency set still has these owner blockers:

- `include/Command.h` copies `RGE_Map`, `RGE_Player`, `RGE_Game_World`,
  `TCommunications_Handler`, `TDebuggingLog`, and `RGE_Base_Game`. It also uses
  compatibility unions. It cannot join `world.h` as an owner-only header.
- `include/scenario.h` copies `RGE_Prog_Info` and `RGE_Base_Game`.
- `include/gameinfo.h` copies `RGE_Prog_Info` and `RGE_Base_Game`.
- `include/sprite.h` copies `RGE_Color_Table` and `RGE_Base_Game`. It conflicts
  with `include/color.h`.
- `include/Shape.h` copies `TShape` and `DClipInfo_List`. It conflicts with
  `include/sprite.h` and `include/Mouseptr.h`.
- `T_Scenario` has no owner-only header. `include/tscenaro.h` copies
  `RGE_Static_Object`, `RGE_Base_Game`, `RGE_Player`, and `RGE_Game_World`.
- `TRIBE_Map`, `TRIBE_Command`, and `TRIBE_Master_Player` have no owner-only
  headers. Their current source surfaces are context or local fallback classes.
- `TRIBE_Zone_High_Score_Info` has only context and local source definitions.
  `include/tworld.h` only forward-declares the record.
- `RGE_Prog_Info` has a canonical record in `include/main.h`, but the scenario
  and game-info headers still define competing classes.

The full canonical-header probe failed with VC5 redefinition errors in
`scenario.h`, `gameinfo.h`, `main.h`, `basegame.h`, and `Command.h`. A second
probe confirmed `sprite.h` versus `color.h`, and `Shape.h` versus `sprite.h`
and `Mouseptr.h`.

### ABI and field ownership

The current source uses context-only names that do not exist in the canonical
owners:

- `RGE_Player_Info`: `00542750_new_game.cpp` uses `player_num_minus1` and
  `victory`. `include/world_info.h` proves `player_num` and `map_type`.
- `RGE_Base_Game`: World save callers use `save_prog_info`. The canonical field
  is `prog_info` at the same proven slot. This is a field-owner error, not a
  harmless name choice.
- `RGE_Base_Game::get_campaign_info`: `00544090_load_scenario.cpp` passes
  pointers. The PDB and `include/basegame.h` prove three references.
- `RGE_Object_Node`: `00543A00_save_scenario.cpp` and
  `00545C00_objectGroupOnTile.cpp` use `object`. `include/obj_list.h` proves
  the field name `node`. The `00545C00` source is now repaired. The save
  scenario owner still uses the old name.
- `RGE_Player`: TWorld score and state sources use `victory` and `civ`.
  `include/player.h` proves `victory_conditions` and the canonical player
  field set. The current sources must not retain compatibility aliases.
- `RGE_Victory_Conditions`: context and local TWorld declarations return
  `int` from `get_victory_points_group`. `include/victory.h` and the PDB owner
  prove `long`.
- `RGE_Game_World::logStatus` is public in `include/world.h`. The PDB places
  it in the protected section. Restore that access in the owner surface.

### Direct-call identity

Relocations are masked in ordinary function checks. Current context exact
results therefore do not prove direct-call identity.

The World BaseGame audit proves these failures in the context surfaces:

- the four mode queries use non-const `QAE` forms instead of canonical const
  `QBE` forms;
- `add_to_timing` uses `int` instead of `unsigned long` and selects `...QAEXHH...`
  instead of `...QAEXHK...`;
- `get_campaign_info` uses pointer parameters instead of the reference ABI;
- TWorld context `get_string` overload order differs from the canonical vtable;
- TWorld context puts Tribe-only helpers on `RGE_Base_Game` and uses `int`
  for enum getters. Those helpers belong to `TRIBE_Game`.

The affected World call sites include `00542ED0`, `00542750`, `00543A00`, and
`00544090`. Affected TWorld call sites include `0052E0B0`, `0052EF30`,
`00530AE0`, and `00531350`.

TWorld source also needs the canonical direct owners for `TRIBE_Game`,
`RGE_Victory_Conditions`, `T_Scenario`, `TRIBE_Map`, `TRIBE_Command`, and
`TRIBE_Master_Player`. A local same-shaped declaration is not evidence of the
correct target.

### Global ownership

The only reviewed shared global entry for this area is `rge_base_game` in
`config/shared_abi_evidence.json`. Its canonical declaration is in
`include/rge_base_game_global.h` and its storage is `0062C574`.

Current blockers are:

- `00542750_new_game.cpp` replaces the reviewed `rge_base_game` extern with an
  absolute-address macro. It also uses absolute macros for `world_update_counter`,
  `computerPlayerSetup`, `debug_timeGetTime_cnt`, `debug_timeGetTime_time`,
  `all_cp`, `pathSystem`, and `aiPathSystem`.
- `src/tworld_phase2_context.h`, `0052E0B0_logStatus.cpp`,
  `00531350_send_zone_score_info.cpp`, and `0052EF30_new_game.cpp` use
  `TRIBE_Game* rge_base_game`. The reviewed global is `RGE_Base_Game*`.
- The World contexts are the only common declaration surface for
  `world_update_counter`, `computerPlayerSetup`, the debug flags and counters,
  `all_cp`, `visible_combats`, `logStatusOn`, `lastStatusLogTime`,
  `logStatusFile`, `DVlogf`, `VIS_UNIT_objectsValue`, and `MouseSystem`.
- The contexts also declare `version_101` through `version_111` and
  `save_game_version` without a canonical World global owner. `rge_write_error`
  has a canonical declaration in `include/rge_fio.h`. `DAT_00577a10` and
  `DAT_00577a14` have declarations and definitions in the generated global
  surface, but the World contexts still redeclare them.

The final World module needs one reviewed global declaration surface. It must
use the proven storage identity and type for each global. Do not replace this
work with absolute dereference macros or context declarations.

## Validation record

Post-rebase checks ran at `6c473fac7`:

- `0052DF60` reports `MATCH`, `0.0000%`, with a context-derived object. Its
  check masks 10 relocations. It is not a natural-owner claim.
- `00540750` had a context `MATCH` before `62fc92839`. No fresh check can run
  after that commit because the active World wrapper now fails to compile.
- `00545C00` reports `MATCH`, `0.0000%`, and 166 equal bytes. The source uses
  canonical typed owners, but the owner is not in `world_complete`.
- A direct VC5 compile of `src/world_cpp_phase2_tu.cpp` fails before code
  generation. The context redeclares `RGE_Game_World`, `RGE_Map`,
  `RGE_Player`, `RGE_Static_Object`, `RGE_Master_Static_Object`,
  `RGE_Object_List`, and `RGE_Tile_List` before the canonical
  `00545C00` includes. The source then cannot find canonical `map_row_offset`
  or `owner`. This confirms the active grouped wrapper is blocked.
- `00542BF0` reports 221 strict bytes. `0052EF30` reports 4,372 strict bytes
  and a call-surface difference.
- The grouped observed audit stopped before compile because
  `build/004AB300_dumpbin_fpo.txt` is missing. It is not a grouped validation
  result.

### Compiler and source-shape blockers

World accepted-drift owners still have these known compiler blockers:

- `005412B0`: entry save-register scheduling;
- `005414A0`, `00541B60`, `00541BC0`, `00541C20`, `00541C90`, `00541D00`, and
  `00542480`: VC5 `/GX` null/common-store no-op join branch;
- `005420F0`: equivalent `cmp ax,bp` versus `test ax,ax` gate;
- `00543E00` and `00544090`: late success and failure-tail layout.

TWorld accepted-drift owners still have these known compiler blockers:

- `0052E220`: EH and register scheduling;
- `0052E4C0`, `0052E530`, `0052E590`, `0052E5F0`, `0052E650`, and `0052E920`:
  VC5 `/GX` null/common-store no-op join branch.

The unresolved normal owners are:

- `00542BF0`: 221 strict bytes differ. Map and scenario source order remains
  unresolved.
- `0052EAC0`: 306 strict bytes differ. The first mismatch is the implicit-this
  home. The six calls and frame are aligned.
- `0052EF30`: 4,372 strict bytes differ. The call surface is not aligned.
  The candidate uses `__chkstk` where the oracle uses `__alloca_probe`, and it
  merges three conquest setter calls.
- `005303F0`: the current semantic checkpoint has 1,437 strict bytes differ.
  The victory guard and team-array homes remain unresolved.

These are source or compiler work items. They are not grounds for a context
exact claim.

## Source-resumption gates

Resume natural World source work only when all gates below pass:

1. Build one PDB-ordered World owner module. Remove context includes,
   `TWORLD_PHASE2_CONTEXT` selection, local fallback classes, and duplicate
   owner wrappers.
2. Publish owner-only surfaces for `RGE_Command`, `T_Scenario`, `TRIBE_Map`,
   `TRIBE_Command`, `TRIBE_Master_Player`, and the score record. Clean the
   foreign copies from scenario, game-info, sprite, Shape, and Command headers.
3. Consume `world_info.h`, `world.h`, `map.h`, `player.h`, `obj_list.h`,
   `stat_obj.h`, `m_s_obj.h`, `mst_play.h`, `com_hand.h`, `effects.h`,
   `victory.h`, `basegame.h`, `main.h`, and the other owner-only headers.
   Replace every context-only field and call spelling listed above.
4. Publish and use one reviewed global declaration surface. Keep
   `rge_base_game` as `RGE_Base_Game*` and retain direct storage identity.
5. Add `00545C00` to the candidate owner set after the context-free wrapper
   compiles. Record both generated deleting destructors. Do not register an
   owner from a folder name or a masked relocation result.
6. Run fresh grouped candidate validation and focused checks. Require
   `MATCH`, `0.0000%`, original boundaries, owning symbols, relocation identity,
   and direct-control target identity.
7. Keep accepted drift and scratch work out of exact registration until each
   owner passes its own source and semantic review.

No production source or header changed in this audit. The only durable change
is this evidence note.
