# act_obj.cpp source-module recovery

- PDB source: `C:\\msdev\\work\\age1_x1\\act_obj.cpp`.
- Source: `src/act_obj.cpp`.
- Header: `include/act_obj.h`.
- Normal owners: 35, in PDB source order from `00405C60` through `00406D30`.
- Compiler-generated neighbor: `00405F70`, the scalar deleting destructor.
- Flags: `config/flags/act_obj.rsp` (`/O2 /Oy /GX`).

## Context and ownership

The PDB assigns all 35 normal owners to `act_obj.cpp`. The line bands run from
47-56 through 813-828. The class owner is `RGE_Action_Object`. The address
sequence is also increasing. The source keeps that order.

The reviewed `RGE_Action_Object` declaration inherits from
`RGE_Moving_Object`. Its proven fields start at `+0x180`: `waiting`, `actions`,
`command_flag`, `lastActionValue`, and `lastActionStateValue`.

The source order is:

1. `00405C60` and `00405F90`, the two constructors.
2. `00406010`, `00406080`, `004060A0`, `004060D0`, `00406120`, and `004061A0`.
3. `00406200`, `00406220`, `00406270`, `00406290`, `004062B0`, `004062C0`,
   `00406300`, and `00406430`.
4. `00406470`, `00406830`, `00406840`, `00406850`, and `00406860`.
5. `00406940`, `00406990`, `004069E0`, `00406A00`, `00406A30`, `00406A50`,
   and `00406A70`.
6. `00406B90`, `00406BC0`, `00406BF0`, `00406C10`, `00406C30`, `00406D00`,
   and `00406D30`.

`00405F70` is compiler generated. It has no source body. The source module
keeps the authentic virtual destructor that causes VC5 to emit it.

## Migration

The module has one direct source body. The wrapper, context header, and 35
source-bank fragments are removed. The source has no fallback class,
recovery macro, or codegen-only view.

The source uses reviewed Action, action-list, task-list, master, object,
player, World, Unit AI, and file I/O providers. Master action fields use a
local `static_cast<RGE_Master_Action_Object*>` only where needed. Task lookup
uses `RGE_Task_List::get_target_task`. It does not use `RGE_Master_Command`.

The full candidate is `build/candidate_tus/act_obj_direct/report.txt`. It
compiled with `config/flags/act_obj.rsp` and compared all 35 normal bodies.

- 25 normal owners match with zero relocation mismatches and no boundary
  escapes.
- `00405F70`, the scalar deleting destructor, matches.
- `00406BC0` and `00406C10` now match in the direct source.
- The report has zero comparison errors.

## Regressions and open work

The following owners are `scratch`:

- `004062C0` `do_command`: 34 differing bytes.
- `00406430` `work`: 34 differing bytes.
- `00406470` `work2`: 924 differing bytes, one relocation mismatch, and two
  boundary escapes.
- `00406860` `get_command_master`: 191 differing bytes.
- `00406940` `set_task`: one differing byte.
- `00406990` `setTaskByTaskID`: one differing byte.
- `00406A70` `update`: 110 differing bytes.
- `00406B90` `change_ownership`: one differing byte.
- `00406C30` `getTask`: 203 differing bytes and one boundary escape.
- `00406D30` `get_action_checksum`: 10 differing bytes and one boundary
  escape.

The direct source preserves all bodies. Exact repair can start from this source
tree. The module has no accepted-drift rows.
