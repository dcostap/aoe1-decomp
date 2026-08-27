# Tmap canonical owner gate

Status: HOLD. This note records the owner gates after rebase onto
`dc7820b95`. It does not repair source or foreign headers.

## PDB facts

- `TRIBE_Map` derives from `RGE_Map` and has size `0xB5F8`.
- `TRIBE_Map::rge_player` is `RGE_Player*` at `+0x8DD4`.
- `TRIBE_Map::rge_game_world` is `RGE_Game_World*` at `+0x8DD8`.
- `TRIBE_Map::cliff_master_table[256]` starts at `+0x8DF8`.
- The table element is `TRIBE_Master_Cliff_Info`, size `0x28`:
  `long id`, `long facet`, `long id2`, `long facet2`, `TRIBE_Cliff_Info info`,
  `float offset_x`, and `float offset_y`.
- `TRIBE_Cliff_Info::info` is `long info[4]`, size `0x10`.
- `RGE_Map::map_width` and `map_height` are PDB `long`. Any grouped Map
  owner that passes their addresses to `rge_write` uses `long*`, never `int*`.

## Tmap owner table

| Target | Current blocker | Exact next owner gate |
|---|---|---|
| `0050F7C0_map_generate` | Uses `field_8DD4` and `field_8DD8` as `void*`, with reversed source names. | Use the Tmap-owned `rge_player` and `rge_game_world` fields with the PDB pointer types. Keep the PDB store targets: world to `+0x8DD8`, player to `+0x8DD4`. |
| `0050F800_data_load_random_map` | Uses `TRIBE_Map::random_map_controller`. | Use inherited `RGE_Map::random_map`, typed `RGE_RMM_Database_Controller*`. Keep the foreign `TRIBE_RMM_Database_Controller(int)` constructor target. |
| `0050F860_load_random_map` | Uses a raw `random_map` carrier in the local class. | Use inherited `RGE_Map::random_map`. Keep the foreign `TRIBE_RMM_Database_Controller(char*, char*, char*, char*)` constructor target. |
| `0050F8D0_check_tile_for_forest_change` | Uses `tile->terrain`, `tile->object_list`, `node->object`, and `object->field_48`. | Use typed `RGE_Tile::terrain_type`, `tile->objects.list`, `RGE_Object_Node::node`, and the proven Static field `object_state`. |
| `0050FA90_change_terrain` | Treats terrain and border as packed carrier bytes. | Use typed `terrain_type`, `border_type`, and `border_shape`. Do not add a packed alias. |
| `0050FC40_do_terrain_brush` | Reads `+0x8DC0` by raw address and defines a `TRIBE_Map::set_terrain` stub. | Use inherited `RGE_Map::game_world` and direct `RGE_Map::set_terrain(RGE_Game_World*, short, short, unsigned char, int, int)`. The oracle target is `00459900`. |
| `0050FE90_setup_cliff_type` | Defines local `CliffMasterEntry` and writes `slot_info`. | Use Tmap-owned `TRIBE_Master_Cliff_Info` and write `info.info[0..3]`. Do not create `CliffMasterEntry`, unions, or padding. |
| `00510110_make_new_cliff` | Types the receiver as the foreign base World for the destructable call. | Keep foreign World headers unchanged. Type the call receiver as `TRIBE_World` so the direct target remains `TRIBE_World::check_destructables` at `0052EAC0`. |
| `005102A0_remove_cliff_edge`, `00510430_add_cliff_edge`, `00510960_delete_cliff` | Uses foreign Static coordinate names `y` and `z`. | Use the proven Static fields `world_y` and `world_z`, both `float`. Do not add coordinate aliases. |
| `005111A0_tribe_clean_terrain` | Uses `tile->terrain`. | Use typed `RGE_Tile::terrain_type`. |

## Virtual and direct-call proof

The unchanged foreign declarations provide these proven virtual slots:

- `RGE_Master_Static_Object::copy_obj` at `+0x04`.
- `RGE_Master_Static_Object::make_new_obj(RGE_Player*, float, float, float)` at
  `+0x18`.
- `RGE_Master_Static_Object::check_placement(...)` at `+0x20`.
- `RGE_Master_Static_Object::alignment(...)` at `+0x24`.
- `RGE_Static_Object::~RGE_Static_Object` at `+0x00`.
- `RGE_Static_Object::recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*,
  float, float, float)` at `+0x04`.
- `RGE_Static_Object::destroy_obj()` at `+0x68`.

The Tmap source must not use `can_place`, `place`, `delete_object`,
`node->object`, `first`, `object_list`, or `action_list` as replacement names.

## Composition gate

`src/tmap_tu.cpp` still selects `TMAP_GROUP_CONTEXT` and includes
`src/tmap_context_local.h`. That context and `include/tmap_context.h` are not
canonical owners. The next Tmap header must own `TRIBE_Map`,
`TRIBE_Master_Cliff_Info`, and `TRIBE_Cliff_Info`. It must consume, without
editing, the existing Map, World, Master Static, Static, Object List, Object
Node, and RMM declarations.
