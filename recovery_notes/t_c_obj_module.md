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

`build/candidate_tus/t_c_obj_cliff_abi/report.txt` compiles all 39 owners.
It verifies 13 direct exact owners. Each says `MATCH` and `0.0000%`.

The exact owners are `004CA0F0`, `004CA1A0`, `004CA210`, `004CA510`,
`004CA5F0`, `004CA740`, `004CA780`, `004CA790`, `004CA8C0`, `004CAA50`,
`004CB8D0`, `004CBD30`, and `004CC570`.

The current registry has 20 matching bodies, 17 scratch bodies, and two
accepted-drift bodies. The shared-worktree wave recovered
`004CB8B0 useSameZoneDropsite` with the natural explicit rejection branches.
Its focused and complete-module checks report `MATCH` and `0.0000%`.

## ABI repair after review

`RGE_Action_Object` keeps virtual `setTaskByTaskID` and `set_end_action`.
The original vtables place action helpers at `+0x200` through `+0x210`.

The command bodies delete the action list, then call `set_only_action`.
They also call `getTask`. The executable uses slots `+0x208` and `+0x210`.

The current inherited surface emits slots `+0x210` and `+0x218`.
Therefore `004CB060`, `004CB1B0`, `004CB300`, `004CB450`, `004CB5C0`,
and `004CB710` are scratch. They have no exact registration.

`UnitAIModule` has only the four-float and five-argument target setters.
It has no four-int target setter. These methods are nonvirtual.

## Cliff table

The PDB names `TRIBE_Cliff_Higher_Check_Table` at `00587258`.
Its type has 25 records of 32 bytes. `game_globals` owns the table.

`game_globals.cpp` preserves all 800 original bytes. The probe object has
the same 800 bytes. `higher_check_for_cliff` now uses this table directly.

The fresh direct-module audit is `build/candidate_tus/audit_t_c_obj_final`.
It demotes `004CBEF0 higher_than_target`. Its 641
rebuilt bytes differ from the 701-byte original by 656 bytes. The checker
reports a missing virtual slot `+0x248`, an extra slot `+0x270`, a smaller
frame, and broad block drift. `004CAC10 get_armor` remains accepted drift with
88 differing bytes and no relocation or boundary mismatch. The disambiguated
`004CC4C0 heal(float)` remains accepted drift with 9 differing bytes and no
relocation or boundary mismatch.
