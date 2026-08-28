# `t_c_obj.cpp` provider inventory

PDB source: `C:\\msdev\\work\\age1_x1\\t_c_obj.cpp`.
The module has 39 normal owners in source order from `004CA0F0` through
`004CC5B0`. The direct-source destination is `TRIBE_Combat_Object`.

This inventory uses the original code, CodeView type dumps, current canonical
headers, and focused dossiers for `004CA300`, `004CA5F0`, `004CA8C0`,
`004CAAA0`, `004CB8D0`, and `004CC5B0`.

## Canonical providers ready for direct use

| Access group | Canonical owner | Evidence |
| --- | --- | --- |
| object ID, master, owner, sprite, holder, state, health, selection, coordinates, held attribute, type, and Unit AI pointer | `RGE_Static_Object` in `stat_obj.h` | CodeView `RGE_Static_Object`; direct accesses in all focused dossiers |
| actions, command state, and task lookup | `RGE_Action_Object` in `act_obj.h` | CodeView class and `t_c_obj.cpp` calls to `actions`, `set_only_action`, and `getTask` |
| combat VUR records, attack timer, and capture flag | `RGE_Combat_Object` in `com_obj.h` | CodeView: `VUR_Ptrs +0x194`, `Unified_Map_Value +0x1B8`, `attack_timer +0x1BC`, `capture_flag +0x1C0`; `004CA8C0` reads `+0x194` |
| owned-master flag | `TRIBE_Combat_Object` in `t_c_obj.h` | CodeView: `own_master +0x1C4`; `004CA300` writes `+0x1C4` |
| static master IDs, group, placement, radii, health, and action task list | `RGE_Master_Static_Object` in `m_s_obj.h` | PDB layout and direct calls in setup, artifact placement, area attack, and repair |
| combat master armor and weapon records | `RGE_Master_Combat_Object` in `m_co_obj.h` | `004CAC10` reads `base_armor +0x100`, `armor_num +0x102`, and `armor +0x104`; `004CAAA0` reads `weapon_num +0x108` and `weapon +0x10C` |
| tribal master build inventory and original pierce armor | `TRIBE_Master_Combat_Object` in `tm_co_ob.h` | CodeView: tail fields `+0x148` through `+0x160` |
| action list operations | `RGE_Action_List` in `act_list.h` | Existing canonical constructor, add, delete, get-action, get-task, and work methods |
| map tiles and object links | `RGE_Map`, `RGE_Tile`, `RGE_Object_List`, `RGE_Object_Node` in `map.h` and `obj_list.h` | PDB layouts and the cliff, artifact, and area-attack paths |
| quick-build flag | `RGE_Base_Game::quick_build` in `basegame.h` | `004CAAA0` reads `rge_base_game +0x9A8`; exact `004CAAA0_do_attack.cpp` uses the member |

## Unit AI provider work

`UnitAIModule` belongs to `unit_ai_module.h`. `004CA8C0` directly calls
`UnitAIModule::purgeNotifyQueue(unsigned long)` with `world_time`. The header
now declares that proven arity.

The following PDB provider classes are empty `UnitAIModule` derivatives of size
`0x134`: Artifact, Civilian, Priest, Hunted Animal, Elephant, Lion, Preditor,
Fishing Ship, Trade Ship, Transport Ship, Tower, Building, and Soldier. Their
constructors take `RGE_Static_Object*` and `int`. `tribe_unit_ai.h` owns these
provider declarations. `t_c_obj.cpp` can include it privately.

No Unit AI field or layout is copied into `t_c_obj.h`.

## Terra 5 Player handoff

Do not edit Player headers in Terra 6.

| Required access | Candidate owner | Type and offset | Access evidence | State |
| --- | --- | --- | --- | --- |
| player ID, master-object array, world, attributes, selection, add/remove object, and unselect | `RGE_Player` | `short id +0x4A`; `RGE_Master_Static_Object** master_objects +0x24`; `RGE_Game_World* world +0x3C`; `float* attributes +0x50` | CodeView `RGE_Player`; setup, ownership, artifact, and repair paths | Already published in `player.h` |
| tribe resource cost checks and payments | `TRIBE_Player` | `check_obj_cost(short, short*, float, int)` and `pay_obj_cost(short, float, int)` | heal and canRepair source paths; current `tplayer.h` | Already published in `tplayer.h` |
| action pointer formerly written as `owner->info->field_270` | Player provider, exact owner unknown | Old local carrier claimed `RGE_Player_Info*` then `void* +0x270`; CodeView disproves that type: `RGE_Player_Info +0x270` is `long player_id_hash[9]` | historical raw source line 689; repair path `004CB450` | Do not publish. Terra 5 must identify the actual Player-owned pointer and its target type before a natural repair body can use it. |

## Unresolved canonical owners

The old direct attempt uses `field_08`, `field_44`, `field_48`, `field_4C`,
`object_info`, `context`, `sub`, `owner_data`, and raw offsets. These are not
canonical declarations. The focused assembly instead proves many were aliases
for inherited `master_obj`, `owner`, `id`, or virtual calls. The remaining
uses need per-function reconstruction. Do not add a carrier or padding object.

The `004CAAA0` assembly is a model example. It proves direct use of
`master_obj`, `owner`, the base-game quick-build member, Master Combat weapon
fields, `notify`, `area_attack`, and `damage`. It does not prove an
`object_info` field on `TRIBE_Combat_Object`.
