# tact_dar.cpp source reunification

## Result

The source module now has one compiler-facing owner at `src/tact_dar.cpp`.
The source follows the PDB order. No compiler or validator ran in this pass.
The task forbade those checks.

The old context header copied the action, object, map, world, player, list, and
master layouts. The new module header uses the canonical owners instead. It does
not add fake virtual slots or foreign class copies.

## PDB order and statuses

The PDB source is `C:\\msdev\\work\\age1_x1\\tact_dar.cpp`.

| VA | PDB lines | owner | status |
| --- | ---: | --- | --- |
| `004CE530` | 32-37 | `TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact(int, RGE_Action_Object*)` | matching |
| `004CE5F0` | 42-48 | `TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*)` | matching |
| `004CE670` | 53-61 | `TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact(RGE_Action_Object*, RGE_Task*, float, float, float)` | matching |
| `004CE6D0` | 65-69 | `TRIBE_Action_Discovery_Artifact::save(int)` | matching |
| `004CE700` | 73-76 | `TRIBE_Action_Discovery_Artifact::first_in_stack(unsigned char)` | matching |
| `004CE720` | 80-92 | `TRIBE_Action_Discovery_Artifact::set_state(unsigned char)` | matching |
| `004CE740` | 96-121 | `TRIBE_Action_Discovery_Artifact::update()` | accepted_drift |
| `004CE7A0` | 125-165 | `TRIBE_Action_Discovery_Artifact::check_objects()` | matching |

`004CE5C0` is the compiler-generated vector deleting destructor. `004CE5E0`
is the compiler-generated destructor body. Neither is a handwritten source
owner.

## Canonical ownership

`include/tact_dar.h` includes these canonical owner headers:

- `action.h` for `RGE_Action` and its virtual order;
- `act_list.h` for `RGE_Action_List`;
- `act_obj.h` for `RGE_Action_Object`;
- `stat_obj.h` for `RGE_Static_Object`;
- `m_s_obj.h` for `RGE_Master_Static_Object`;
- `m_ac_obj.h` for `RGE_Master_Action_Object`;
- `move_obj.h` for the moving-object base;
- `map.h` for `RGE_Map` and `RGE_Tile`;
- `world.h` for `RGE_Game_World`;
- `obj_list.h` for `RGE_Object_List` and `RGE_Object_Node`;
- `player.h` for `RGE_Player`;
- `basegame.h` for `RGE_Base_Game`.

The module-owned `TRIBE_Action_Discovery_Artifact` declaration adds only its
`flags` pointer at `+0x40` and its own methods. The inherited data and virtual
slots come from `RGE_Action`.

The old `DiscoveryMaster`, `DiscoveryInfo`, and `DiscoverySizeInfo` structs
were not proven discovery classes. Their copied gaps only described canonical
pointer paths:

- `RGE_Action_Object::owner` at `+0x0C`;
- `RGE_Player::world` at `+0x3C`;
- `RGE_Game_World::player_num` at `+0x3C`;
- `RGE_Game_World::world_time_delta_seconds` at `+0x84`.

The source now uses those canonical members. The map scan uses
`RGE_Object_Node::node`, which is the canonical list-node member. No
 discovery-specific layout remains. This closes the conditional discovery
header gap without adding a layout shim.

`rge_read` and `rge_write` remain narrow local declarations for the imported C
file-I/O helpers. The three referenced constants remain narrow external global
declarations. They are not class or layout owners.

## Migration effects

The former `tact_dar_context.h` is removed. The former wrapper and eight source
bank bodies are removed. The eight definitions now live in `src/tact_dar.cpp`.
`config/source_modules/tact_dar.json` records all eight honest statuses.

No header gap remains for this source module. The accepted drift at `004CE740`
remains accepted drift. It was not promoted to matching without a fresh check.
