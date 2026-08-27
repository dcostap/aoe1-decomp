# rmm_dbct.cpp source module

The natural source is `src/rmm_dbct.cpp`. It owns all 12 PDB owners in source
order. It includes canonical world.h, map.h, obj_list.h, and rmm_base.h.

The direct candidate validates eight exact owners. Each reports `MATCH` with
`0.0000%` difference. They are `00483020`, `00483200`, `004832E0`,
`00483430`, `00483540`, `004835A0`, `00484160`, and `00484320`.

`00482B70`, `00483600`, and `00483A20` remain scratch. Their current direct
differences are 790, 544, and 1554 bytes. The first and third have two
boundary escapes. `00484470` remains accepted drift with a 15-byte difference.

## Scratch history

`00482B70` keeps the typed map-record reconstruction. It has 28 ordered calls
and a `0x34` frame. The unresolved basin is EBX and ESI register coloring.

`00483600` keeps the typed retry loop. It has the target size, `0x30` frame,
and 16 ordered calls. The unresolved basin is saved-register and local-home
placement.

`00483A20` keeps typed land records and cursor-based team grouping. It has a
`0x190` frame and three ordered calls. The target uses a different saved-this
home and local-array topology.

`00484470` stays accepted drift. The complete module context now differs by
15 bytes. Do not restore its earlier isolated exact claim.

The source has no local RGE_Map, RGE_Game_World, RGE_Object_List, fake vtable,
assembly, or function-fragment include.

## Evidence

- `inventory/functions/0048/00482B70_RGE_RMM_Database_Controller.txt`
- `inventory/functions/0048/00483020_RGE_RMM_Database_Controller.txt`
- `inventory/functions/0048/00484470_add_elevation_module.txt`
- `inventory/types/dumps/RGE_RMM_Database_Controller.txt`

## Owner header

`include/rmm_dbct.h` now owns the complete controller and its database record
types. It includes only canonical `rmm_base.h`; Map, World, ObjectList, Tile,
Stack, and vtable declarations remain in their owning headers. Record padding
uses natural alignment, and the controller has one `RGE_Map_Data map_info`
member.

The amended VC5 layout probe compiled with `config/flags/default.rsp` and
reported:

| item | value |
| --- | --- |
| `sizeof(RGE_RMM_Database_Controller)` | `0x4F5C` |
| `world` | `+0x30` |
| `map_type` | `+0x34` |
| `number_of_players` | `+0x38` |
| `land_info` | `+0x3C` |
| `terrain_info` | `+0x1474` |
| `object_info` | `+0x270C` |
| `elevation_info` | `+0x3FD4` |
| `map_info` | `+0x4F54` |

The probe also confirmed the `0x2C` land entry, `0x48` map entry,
`0x1438` land info, `0x1298` terrain info, `0x18C8` object info, and
`0xF80` elevation info sizes.
