# Act_atak header checkpoint

## Scope

This checkpoint changes only `include/act_atak.h` and this note. The held
`src/act_atak.cpp` source is unchanged.

The header owns only `RGE_Action_Attack`. It includes `action.h`. It forward
declares the pointer types used by the class. It does not define Combat,
Master Combat, Move Action, Visible Map, or UnitAIModule.

## PDB and type evidence

The PDB source is
`C:\\msdev\\work\\age1_x1\\Act_atak.cpp`.

The class owner is `RGE_Action_Attack`. Its normal owner sequence is:

- `00401000` constructor from a file handle;
- `00401170` target constructor;
- `004012B0` coordinate constructor;
- `004013A0` destructor;
- `004013B0` `save`;
- `004014B0` `first_in_stack`;
- `00401540` `stop`;
- `00401550` `set_state`;
- `00401780` `update`;
- `00401AD0` `work`;
- `00401B30` `ready_to_attack`;
- `00401EC0` `do_attack`; and
- `00401F00` `copy_obj_sprites`.

`00401150` is the compiler-generated vector deleting destructor. It has no
source body.

`RGE_Action` owns the first `0x40` bytes and its virtual order. The derived
fields start at `+0x40`:

- `move_sprite` at `+0x40`;
- `fight_sprite` at `+0x44`;
- `wait_sprite` at `+0x48`;
- `range` at `+0x4C`;
- `min_range` at `+0x50`;
- `missile_id` at `+0x54`;
- `fire_missile_at_frame` at `+0x56`;
- `need_to_attack` at `+0x58`;
- `was_same_owner` at `+0x59`; and
- `indirect_fire_flag` at `+0x5A`.

The three byte fields end at `+0x5B`. VC5 aligns the complete class size to
`0x5C`, so the header has no explicit end-padding member.

The PDB virtual owners match the declarations for `save`, `first_in_stack`,
`update`, `stop`, `work`, `copy_obj_sprites`, and `set_state`. The constructors
match the observed parameter lists. The coordinate constructor has eleven
parameters after `this`: an action object, three coordinates, three sprites,
two ranges, and two shorts.

## Minimal VC5 probe

Probe source: `build/header_probes/act_atak_size.cpp`.

Command:

`CL.EXE @config/flags/default.rsp /Iinclude /Fobuild/header_probes/act_atak_size.obj build/header_probes/act_atak_size.cpp`

The probe contains this compile-time assertion:

`sizeof(RGE_Action_Attack) == 0x5C`

Result:

- return code: `0`;
- compiler output: `act_atak_size.cpp`; and
- object SHA-256: `fa4fe866df120e0d5deebe6da8fbc2c2a8cfa0b4c5f7ee921f5397d868aadb00`.

No source-module compile or function validator ran.
