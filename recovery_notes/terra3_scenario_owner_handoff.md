# Terra 3 handoff: Scenario owners for Tworld

Version: 1  
Date: 2026-08-28  
Status: blocked; audit only

## Scope

This note records the Scenario owner boundary that Tworld needs. It does not
change Tworld, World, BaseGame, Scenario sources, or headers. It does not add a
local record, cast, alias, or substitute declaration.

The current Tworld candidate is split between
`src/tworld_phase2_tu.cpp` and `src/tworld_prefix_tu.cpp`. The registry still
names this work `tworld_prefix` at `config/translation_units.json:617-664`.
Do not treat that temporary wrapper or registry row as a canonical owner.

## Canonical owners

| Type | Binary evidence | Canonical repository owner |
| --- | --- | --- |
| `RGE_Scenario` | `inventory/classes/dumps/RGE_Scenario.txt:1-8` names `RGE_Scenario.h` and proves `0x1990` bytes. | Header `include/scenario.h`; source `src/scenario.cpp`; manifest `config/source_modules/scenario.json`. |
| `RGE_Scenario_Header` | `inventory/classes/dumps/RGE_Scenario_Header.txt:1-8` names `RGE_Scenario_Header.h` and proves `0x14` bytes. | Header `include/scenario.h`; source `src/scenario.cpp`. |
| `T_Scenario` | `inventory/classes/dumps/T_Scenario.txt:1-8` names `T_Scenario.h`, derives from `RGE_Scenario`, and proves `0x514C` bytes. | Header `include/tscenaro.h`; source `src/tscenaro.cpp`; manifest `config/source_modules/tscenaro.json`. |
| `TRIBE_Scenario_Header` | `inventory/classes/dumps/TRIBE_Scenario_Header.txt:1-8` names `TRIBE_Scenario_Header.h`, derives from `RGE_Scenario_Header`, and proves `0x1C` bytes. | Header `include/tscenaro.h`; source `src/tscenaro.cpp`. |

The PDB source map assigns the base Scenario bodies from `0048AB10` through
`0048CE40` to `scenario.cpp` (`inventory/pdb/function_source_map.csv:3296-3349`).
It assigns the derived Scenario bodies from `0052A990` through `0052C230` to
`tscenaro.cpp` (`inventory/pdb/function_source_map.csv:5427-5511`). The two
base virtual bodies at `0048B580` and `0048B590` have `scenario.h` source-line
ownership. Their current standalone fragments are not a second Scenario
layout owner.

`include/scenario.h` is the canonical base surface. It already consumes the
canonical `basegame.h`, `world.h`, `player.h`, `Picture.h`, and
`rge_base_game_global.h` surfaces. It keeps `RGE_Timeline` opaque because
`include/Timeline.h` still carries competing World and Player declarations.
That Timeline hold is separate. Do not reopen it as a Tworld workaround.

`include/tscenaro.h` is the intended derived owner, but the current header is
not composable. It redeclares `RGE_Scenario` at lines 123-176 and
`RGE_Scenario_Header` at lines 190-202. It also carries foreign
`RGE_Game_World`, `RGE_Static_Object`, `RGE_Timeline`, `RGE_Victory_Conditions`,
`RGE_Effects`, `TRIBE_Player`, `TRIBE_Player_Tech`, and `RGE_Base_Game`
declarations at lines 10-71 and 178-188. The current tree also has no
`#include "tplayer.h"`; the existing `tscenaro_module.md` describes a later
cleanup and does not describe this checkout.

## Required layout facts

The following facts are hard gates. They come from the inventory type dumps,
not from the temporary Tworld contexts.

### `RGE_Scenario`

- Size: `0x1990`.
- Virtual slots: `get_object_pointer` at `+0x00`, destructor at `+0x04`,
  `rehook` at `+0x08`, and `save` at `+0x0C`.
- `time_line` is at `+0x04`; `world` is at `+0x08`.
- `victory_conquest` is at `+0x0C`.
- `scenario_name` is at `+0x1010`.
- The complete inherited field order must remain intact. A `gap_04` shell is
  not an equivalent owner.

### `T_Scenario`

- Base: `RGE_Scenario`.
- Size: `0x514C`; derived storage starts at `+0x1990`.
- `player_info[16]`: `+0x1990`, size `0x100`.
- `victory`: `+0x1A90`, size `0x18`.
- `sp_victory[16][12]`: `+0x1AA8`, size `0x2D00`.
- `Opponent[16]`: `+0x47A8`, size `0x400`.
- `AlliedVictory[16]`: `+0x4BA8`.
- `victory_all_flag`, `is_multi_player_flag`, and `which_player`: `+0x4BE8`,
  `+0x4BEC`, and `+0x4BF0`.
- `DisabledTechnology[16][20]`: `+0x4BF4`, size `0x500`.
- `ScenarioOptions[3]`: `+0x50F4`.
- `PlayerAge[16]`: `+0x5100`.
- `mp_victory_type`, `victory_score`, and `victory_time`: `+0x5140`,
  `+0x5144`, and `+0x5148`.
- It keeps the same four virtual slots as the base and has constructors for
  `(RGE_Game_World*)` and `(int, RGE_Game_World*)`.

### Scenario headers

- `RGE_Scenario_Header` size: `0x14`; `error_code`, `version`, `checksum`, and
  `description` are at `+0x04`, `+0x08`, `+0x0C`, and `+0x10`.
- Its virtual slots are `get_size` at `+0x00` and `save` at `+0x04`.
- `TRIBE_Scenario_Header` size: `0x1C`; `any_sp_victory` is at `+0x14` and
  `active_player_count` is at `+0x18`.

## Minimum Tworld-facing Scenario surface

The source-order packets identify the direct requirements:

- `0052E0B0_logStatus` reads `scenario_name` directly at `+0x1010`.
- `0052E590_scenario_init` and `0052E5F0_scenario_init` construct
  `T_Scenario` with the two canonical constructor signatures.
- `0052EF30_new_game` calls the inherited Scenario name and description
  methods, the victory setters, `Save_victory_conditions_into_players`,
  `GetMPVictory`, `GetVictoryScore`, `GetVictoryTime`,
  `Get_Multi_Artifacts`, `Get_Multi_Discoveries`, `Get_Multi_Ruins`, and
  `GetScenarioOption`.
- `00531350_send_zone_score_info` calls `Get_scenario_name`.

The complete derived owner must still publish all methods in the PDB-derived
owner. The minimum call list is not a reason to trim the `T_Scenario` layout or
its virtual slots.

`include/world.h:155` publishes the canonical `RGE_Game_World::scenario` field
as `RGE_Scenario*` at `+0x5C`. In contrast, the temporary
`include/tworld_prefix_context.h:157` publishes that same storage as
`T_Scenario*`. `src/tworld_phase2_context.h:597` uses `RGE_Scenario*` again.
This is a real owner conflict, not a harmless spelling difference. Resolve the
source-facing typed access from the canonical owner evidence without changing
the proven `+0x5C` storage and without adding a cast, alias, overlay, or second
field. Hold Tworld if the owner headers cannot express the calls cleanly.

## Foreign carriers that block Tworld

### Direct Tworld carriers

| Path | Carrier | Effect |
| --- | --- | --- |
| `src/tworld_phase2_context.h:96-129` | Partial `RGE_Scenario` and constructor-only `T_Scenario`. | It hides the complete base and derived owners. The partial base omits the complete `0x1990` layout and the derived type omits the `0x514C` layout and APIs. |
| `include/tworld_prefix_context.h:27,36,60-194` | Forward names plus a duplicate World layout with `T_Scenario* scenario`. | It conflicts with canonical `include/world.h` and cannot supply the derived method surface. |
| `src/matching/0052E0B0_logStatus.cpp:23-151` | Guarded local Scenario, World, Base Game, and Tworld declarations. | The guard only hides the copy in one phase-two build. It remains a foreign carrier and must not survive final source composition. |
| `src/matching/00531350_send_zone_score_info.cpp:561-604` | Guarded partial `RGE_Scenario` declaration. | It duplicates the base owner and supplies only `Get_scenario_name`. |
| `src/scratch/0052EF30_new_game.cpp:67-191` | Guarded local `RGE_Scenario` and `T_Scenario` APIs, plus other context shells. | It supplies the calls only in the prefix lane. The phase-two lane exposes the wrong base pointer and misses these methods. |
| `src/scratch/005303F0_check_game_state.cpp:45-149` | Guarded local `RGE_Scenario` and World declarations. | `005303F0` does not use Scenario. The unused carrier must not define the final Tworld ABI. |

### Adjacent carriers

These files are not Tworld owners. They still block a clean transitive fanout
when a shared World candidate reaches them:

- `include/world_context.h:315` and `include/world_scenario_context.h:335`
  define partial `RGE_Scenario` shells.
- `src/world_phase2_context.h:362` defines another partial `RGE_Scenario`
  shell.
- `include/scr_sed.h:462`, `include/tplayer_context.h:244`, and
  `include/tpnl_obj.h:567` define consumer-specific Scenario copies.
- `src/basegame_candidate_context.h:72-86` defines reduced Scenario header and
  Scenario shells.
- `include/tscenaro.h:123-202` duplicates both canonical Scenario types.

Use forward declarations only where the consumer stores an opaque pointer.
Use the canonical owner header when the consumer reads a field, calls a method,
constructs an object, or deletes an object.

## Exact Terra 3 work order

1. **Take the derived owner.** Work from the current Terra 2 handoff tip. Keep
   `include/scenario.h` and `src/scenario.cpp` as the sole
   `RGE_Scenario`/`RGE_Scenario_Header` owners. Do not copy their bodies into
   `tscenaro.h`.
2. **Clean `tscenaro.h`.** Make it compose the canonical Scenario surface and
   retain only `T_Scenario`, `TRIBE_Scenario_Header`, and their own proven
   records. Remove the duplicate base Scenario and Scenario-header classes.
   Remove the foreign World, Static Object, Timeline, Victory, Effects, Player,
   Player-Tech, and Base Game carriers. Route each needed type to its reviewed
   owner. Do not use a local compatibility surface.
3. **Close the T_Scenario contract.** Preserve the `0x514C` size, the base
   virtual slots, all derived offsets, and both constructors. Ensure the
   inherited methods used by `0052EF30` and the base getter used by `00531350`
   are visible through the canonical inheritance. Record any unresolved typed
   `scenario` access as a hold. Do not fix it with a cast or alias.
4. **Check the Scenario source edge.** Keep the known `RGE_Timeline` composition
   hold separate. The Scenario source may consume a Timeline owner only after
   that owner removes its competing World and Player declarations. Do not
   restore the old Timeline shell in either Scenario header.
5. **Remove Tworld carriers.** In the later Tworld migration, replace
   `src/tworld_phase2_context.h` and `include/tworld_prefix_context.h` with the
   reviewed owner-header include graph. Remove the guarded local declaration
   blocks from the listed Tworld fragments. Remove `TWORLD_PHASE2_CONTEXT`; a
   preprocessor lane is not an ownership solution.
6. **Restore one Tworld source owner.** Merge the 30 PDB `tworld.cpp` normal
   owners in source order into `src/tworld.cpp`. Consume `include/tworld.h`,
   the clean Scenario headers, and other reviewed dependency owners. Retire the
   stale `tworld_prefix` registry row, then register the final source module.
7. **Run focused gates.** First prove no duplicate Scenario definitions in the
   final Tworld include graph. Then check the four direct Scenario consumers:
   `0052E0B0`, `0052E590`/`0052E5F0`, `0052EF30`, and `00531350`. A promotion
   requires fresh `MATCH`, `0.0000%`, correct ownership and boundaries,
   relocations, and direct targets. Keep existing accepted-drift and scratch
   statuses until fresh grouped evidence changes them.
8. **Only then fan out.** Recheck World, BaseGame, Player, Victory, Effects,
   Tech, and Timeline consumers in their owning translation units. Do not let a
   clean Scenario header claim that those other owners are complete.

## Handoff decision

Terra 3 owns the derived Scenario cleanup. Tworld remains blocked until
`include/tscenaro.h` composes the canonical `include/scenario.h` and the
Tworld source can use the required derived API without a duplicate carrier or
ABI substitute. This note is the versioned handoff record.
