# Action ABI packet

## Scope

This packet defines only action-module dependencies. The executable and PDB are
the authority. Header bodies remain proposals until the owner accepts them.

## RGE_Static_Object

- Owner: `stat_obj.cpp`.
- Size: `0x88`. Source: `inventory/types/all_types.csv` and CodeView.
- Base fields: vptr `+0x00`, id `+0x04`, master `+0x08`, owner `+0x0C`.
- Sprite fields: sprite `+0x10`, old sprite `+0x14`, sprite list `+0x18`.
- Tile and list fields: tile `+0x1C`, inside object `+0x20`, objects `+0x24`.
- Position fields: hp `+0x30`, facet `+0x35`, selected `+0x36`.
- World coordinates are `+0x38`, `+0x3C`, and `+0x40`.
- Action fields: state `+0x48`, attribute type `+0x4C`, type `+0x4E`.
- Virtual order includes recycle, draw, update, save, destroy, command, work,
  target, action checksum, and waypoint checksum. See `act_obj.h` lines 141-316.
- Action callers need typed `get_command_master(RGE_Static_Object*, float,
  float, float)` and typed `get_target_obj()`.

## RGE_Moving_Object and RGE_Action_Object

- `RGE_Moving_Object` owner: `move_obj.cpp` and `include/move_obj.h`.
- `RGE_Action_Object` owner: `act_obj.cpp` and `include/act_obj.h`.
- `RGE_Moving_Object` size is `0x180`. Source: `inventory/types/all_types.csv`.
- `RGE_Action_Object` size is `0x194`. Source: the same inventory.
- The animated base size is `0x8C`. Its speed is at `+0x88`.
- The moving virtual order after the inherited surface is teleport, destructor,
  two protected setup overloads, stop_moving, waitingToMove, turn_towards,
  facetToNextWaypoint, setWaitingToMove, userDefinedWaypoint,
  addUserDefinedWaypoint, removeAllUserDefinedWaypoints,
  removeUserDefinedWaypoint, rotate, get_waypoint_checksum, findAvoidancePath,
  passableTile, maximumSpeed, two canPath overloads, canBidirectionPath,
  canPathWithObstructions, two canPathWithAdditionalPassability overloads,
  findFirstTerrainAlongExceptionPath, two canLinePath overloads, and two
  firstTileAlongLine overloads.
- The moving methods use `__thiscall`. Only getPath, waitingToMove, and
  facetToNextWaypoint are const.
- Action slot `work2(RGE_Static_Object*, float, float, float, uchar)` is `+0x1F8`.
- Action fields are waiting `+0x180`, actions `+0x184`, command flag `+0x188`,
  last action `+0x18C`, and last action state `+0x190`.
- Constructors are `00405C60` and `00405F90`. Both are `__thiscall` exact anchors.
- `00406C30 getTask` and `00406D30 get_action_checksum` are exact anchors.
- `00406470 work2` and `00406860 get_command_master` remain scratch.
- Moving-object exact anchors include `0045C450`, `0045C5C0`, `0045C970`,
  `0045CAA0`, `0045CE00`, `0045D140`, `0045D1F0`, `0045D620`, `0045F7F0`,
  `00460B70`, and `00460D60`.

## RGE_Task_List and RGE_Action_List

- `RGE_Task_List` owner evidence is `act_obj` review and original slots.
- Slots are create task `+0x00`, get target task `+0x04`, attack task `+0x08`,
  and check task `+0x0C`.
- `get_target_task` is virtual. It takes action object, static object, and three floats.
- `RGE_Action_List` has no virtual destructor.
- Its slots are create action `+0x00`, create task action `+0x04`, inside update
  `+0x08`, update `+0x0C`, action name `+0x10`, copy object `+0x14`, and
  copy sprites `+0x18`.
- `copy_obj` takes `RGE_Master_Action_Object*`. It is virtual.
- `RGE_Action::type()` is slot `+0x18`.
- `attack_response` is `+0x38`. `get_target_obj` is `+0x4C`.
- These slots use `__thiscall`. Pointer parameters retain their typed classes.

## Player surface used by actions

- Owner: `player.cpp`.
- `RGE_Player` size is `0x220`. Source: `player.h` size check and PDB.
- Master objects are `+0x24`. Object lists are `+0x28`.
- Victory conditions are `+0x34`. Visible map is `+0x38`.
- World is `+0x3C`. Doppleganger creator is `+0x40`.
- Player id is `+0x4A`. Visible-resource list is `+0x110`.
- Exact anchors include `0046E4B0 RGE_Player` and `0046EB00 ~RGE_Player`.
- `00471BF0 set_map_visible` is exact after the visible-map repair.

## Object-list surface

- Owner: `obj_list.cpp` and `include/obj_list.h`.
- `RGE_Object_List` size is `0x0C`. List is `+0x04`. Count is `+0x08`.
- `RGE_Object_Node` fields are node `+0x00`, next `+0x04`, prev `+0x08`,
  and centered `+0x0C`.
- `load(unsigned char, int, RGE_Game_World*)` is virtual slot zero.
- The list destructor is nonvirtual.
- Exact anchors are `00462EA0`, `00462F30`, `00463100`, `00463310`,
  `004634C0`, `00463640`, `004637C0`, and `00463930`.
- These owners are `__thiscall`. Their decorated symbols are in the obj-list TU.

## Consumer rule

Action headers must consume these owners. They must not define a second class
surface. Use the exact pointer, reference, `const`, and narrow-width forms.
