# vis_unit.cpp owner-header checkpoint

## Scope

- PDB source module: `C:\\msdev\\work\\age1_x1\\vis_unit.cpp`.
- Published header: `include/vis_unit.h`.
- Held source: `src/vis_unit_tu.cpp`.
- This checkpoint changes no source owner.
- The header has no context-header include.
- It has no Map, object, player, combat, world, UnitAI, or tile-list layout.

The header owns `VISIBLE_UNIT_REC`, `VISIBLE_UNIT_PTR`, and
`Visible_Unit_Manager`. It also owns the visible-resource record and manager.
The resource types are included because the PDB places their methods in the
same `vis_unit.cpp` source module.

## PDB evidence

`inventory/pdb/function_source_map.csv:5717-5729` and
`inventory/all_functions.csv:5717-5729` list 13 normal owners for this module.
The unit-manager owners are:

| VA | PDB lines | Owner | Size |
| --- | --- | --- | --- |
| `0053B5A0` | 49-88 | constructor | `0xC4` |
| `0053B670` | 91-125 | destructor | `0xB7` |
| `0053B730` | 129-168 | `Build_Distance_Table` | `0xAD` |
| `0053B7E0` | 172-258 | `Update_Unit_Info` | `0x1BD` |
| `0053B9A0` | 265-434 | `GetVisibleUnits` | `0x183` |

The resource-manager owners follow at lines 445-792:

- `0053BB30` and `0053BBE0`: the two constructors;
- `0053BD10`: destructor;
- `0053BD70`: `save`;
- `0053BE00`: `Process_New_Tiles`;
- `0053BED0`: `AddResource`;
- `0053BFD0`: `Remove_Resource`; and
- `0053C050`: `Get_Closest_Resource`.

The PDB-qualified signatures in `config/translation_units.json:7452-7460`
confirm the public method names and parameter types. The unit manager has the
five methods listed above. The resource manager has the eight owners listed
above.

The PDB-derived type dumps prove these natural layouts:

- `inventory/types/dumps/VISIBLE_UNIT_REC.txt:1-22`: size `0x08`; `object_id`
  at `+0x00`, then `distance`, `player`, `pos_x`, and `pos_y` at `+0x04` through
  `+0x07`.
- `inventory/types/dumps/VISIBLE_UNIT_PTR.txt:1-20`: size `0x08`;
  `unit_list` at `+0x00`, `list_size` at `+0x04`, and `used` at `+0x06`.
- `inventory/types/dumps/Visible_Unit_Manager.txt:1-23`: size `0x24`;
  `PlayerDataPtrs` at `+0x00`, `Return_Buffer[5]` at `+0x04`,
  `Player_Count` at `+0x18`, `Category_Count` at `+0x1C`, and
  `distanceTable` at `+0x20`.
- `inventory/types/dumps/VISIBLE_RESOURCE_REC.txt:1-22`: size `0x08`;
  `object_id` at `+0x00`, then `distance`, `zone`, `pos_x`, and `pos_y`.
- `inventory/types/dumps/Visible_Resource_Manager.txt:1-20`: size `0x14`;
  `VR_List`, `VR_ListSize`, `VR_ListUsed`, `owner`, and
  `num_visible_resource_lists` at `+0x00`, `+0x04`, `+0x08`, `+0x0C`, and
  `+0x10`.

## Exact source dependencies

`Process_New_Tiles` is the direct dependency anchor for Map. The original
listing at `orig/ghidra_decomp/vis_unit.cpp.asm:1268-1270` calls
`RGE_Tile_List::get_list_info`. The same owner then loads the player world at
`+0x3C`, the world map at `+0x28`, and `RGE_Map::map_row_offset` at `+0x8D8C`
(lines 1282-1284). The held source therefore needs the canonical Player,
World, Map, tile-list, tile, and object-list owners. It must not use the old
`RGE_World2` or a partial `RGE_Map` substitute from the held wrapper.
`vis_unit.h` keeps only the `RGE_Player` and `RGE_Tile_List` forward declarations
needed by its public pointer signatures.

The PDB does not show a direct `UnitAIModule` dependency in `vis_unit.cpp`.
The separate `aiuaimod.cpp` owners at `00415CA0` and `00415E50` consume the
visible-unit and visible-resource records. The original decompilation identifies
`VISIBLE_UNIT_REC` and `VISIBLE_RESOURCE_REC` in those methods
(`orig/ghidra_decomp/aiuaimod.cpp.decomp:2450-2556`). A future UnitAI source
must include the canonical visible-unit owner header and must not copy the
`VisibleUnitEntry` or partial manager substitutes currently present in
`include/aiuaimod.h`. This header does not define `UnitAIModule`.

## VC5 header probe

Probe source: `build/header_probes/vis_unit_size.cpp`.

Command:

`CL.EXE @config/flags/default.rsp /Iinclude /Fobuild/header_probes/vis_unit_size.obj build/header_probes/vis_unit_size.cpp`

Result:

- return code: `0`;
- compiler output: `vis_unit_size.cpp`; and
- object SHA-256: `08998bb4eab8dd5085057cfe2e4327ad85b3eea1cfb9c5a179570e66927a9a7a`.

The probe checked every published field offset and all five published object
sizes. It did not compile or validate `vis_unit.cpp`.

## Source hold

`src/vis_unit_tu.cpp` remains held. No source file, source-module metadata,
shared header, global definition, or exact registration changed. The next
step is to replace the wrapper support declarations with `vis_unit.h` only
after the canonical Map, World, Player, tile-list, and object owners are ready.
