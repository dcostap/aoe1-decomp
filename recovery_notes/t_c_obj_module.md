# `t_c_obj.cpp` source recovery

- PDB source: `C:\\msdev\\work\\age1_x1\\t_c_obj.cpp`.
- Source: `src/t_c_obj.cpp`.
- Header: `include/t_c_obj.h`.
- Normal owners: 39, from `004CA0F0` through `004CC5B0`.
- Generated neighbor: `004CA180`, the scalar deleting destructor.
- Flags: `config/flags/004CA0F0_TRIBE_Combat_Object.rsp`.

## Source ownership

`TRIBE_Combat_Object` derives from `RGE_Combat_Object`. It owns only
`own_master` at `+0x1C4`. Its size is `0x1C8`.

The direct source uses canonical Combat, Action, Master, Map, Player, and Unit
AI headers. It has no fragment includes or raw object carriers.

## Player repair handoff

`004CB450` and `004CC5B0` use `owner->master_objects[0x9C]`. The array has
base offset `+0x24`. Its element offset is `+0x270`. The element type is
`RGE_Master_Static_Object*`.

The code tests that element before it calls `transform`. `RGE_Player_Info` does
not take part in this path.

## Original defects

- `004CA210` reads `master->id` before it tests `master`.
- `004CC5B0` can use `repair_task` without initialization when its task list is
  empty.

The executable proves both behaviors. Keep them until contrary binary evidence
appears.

## Validation state

`build/candidate_tus/t_c_obj_natural_full/report.txt` compiles all 39 owners.
It verifies 19 direct exact owners. Each says `MATCH` and `0.0000%`.

The exact owners are `004CA0F0`, `004CA1A0`, `004CA210`, `004CA510`,
`004CA5F0`, `004CA740`, `004CA780`, `004CA790`, `004CA8C0`, `004CAA50`,
`004CB060`, `004CB1B0`, `004CB300`, `004CB450`, `004CB5C0`, `004CB710`,
`004CB8D0`, `004CBD30`, and `004CC570`.

The remaining 17 normal bodies are scratch. Three retain reviewed
accepted-drift status. Do not register either group as exact.
