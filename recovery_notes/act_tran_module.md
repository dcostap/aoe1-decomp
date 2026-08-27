# act_tran.cpp module recovery

## Context

- PDB source: `C:\\msdev\\work\\age1_x1\\act_tran.cpp`.
- Source order follows the address and line sequence from 00406D60 through
  00407420.
- The module has 10 normal owners and 1,629 normal bytes.
- The 00406D90 vector-deleting destructor is compiler generated.
- The module uses `config/flags/00406E50_set_state.rsp`.
  This response file keeps `/GX` for the original EH frame.

## Ownership

The normal owners are:

- 00406D60 `RGE_Action_Transport` constructor
- 00406DC0 `RGE_Action_Transport` constructor
- 00406E00 `first_in_stack` (accepted drift)
- 00406E50 `set_state`
- 00406F90 `update`
- 00407160 `stop`
- 00407170 `move_to`
- 004071A0 `work`
- 004072B0 `next_to_drop_off_terrain`
- 00407420 `targetZone`

The old grouped source had nine exact owners and one accepted-drift owner.
The migrated source keeps the same status order. The candidate has not run.

## Header and dependency closure

`include/act_tran.h` is the direct module header. It owns the
`RGE_Action_Transport` declaration. It uses the canonical `RGE_Action` base
surface from `include/action.h`.

`RGE_Action_Move_To` is owned by `act_move.cpp`. The direct header carries its
proven constructor and complete size surface because `set_state` allocates it.

`src/act_tran.cpp` includes these complete owner headers:

- `include/act_tran.h`
- `include/act_obj.h` for the action-object inheritance and fields
- `include/act_list.h` for action-list fields and methods
- `include/map.h` for map dimensions and terrain lookup
- `include/player.h` for player world and notification methods
- `include/task.h` for task terrain and move-sprite fields
- `include/world.h` for the world map field

The action-object include chain supplies the canonical `move_obj.h`,
`ani_obj.h`, `stat_obj.h`, and `m_s_obj.h` owner surfaces. No context header,
local class layout, context macro, source wrapper, or inline assembly remains
in the migrated module.

## Migration

The former `src/act_tran_tu.cpp` wrapper and its ten source-bank fragments were
replaced by the one compiler-facing owner `src/act_tran.cpp`. The definitions
remain in PDB source order.

The transport sentinel keeps the proven stored-dword test for `-1.0f`.
The notification order, terrain checks, and state transitions remain unchanged.

## Validation

The latest lead branch was merged before validation. It includes the cleaned
`m_an_obj.h` owner header from `873a50686`.

The candidate validator stopped during proposal checks. The live config still
points at the old wrapper and source-bank paths. No compiler ran.

The candidate proposal is `build/candidate_tus/act_tran.json`. It uses
`src/act_tran.cpp`, the `/GX` response file, nine exact owner claims, one
observed accepted-drift owner, and the generated destructor entry.
