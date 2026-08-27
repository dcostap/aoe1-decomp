# act_entr.cpp owner-header checkpoint

## Scope

This checkpoint publishes only `include/act_entr.h` and this note. The held
`src/act_entr_tu.cpp` source is unchanged. The old
`include/act_entr_context.h` file is not restored or changed.

The header owns only `RGE_Action_Enter`. It includes canonical `action.h` for
its complete `RGE_Action` base. It forward declares `RGE_Action_Object`,
`RGE_Task`, and `RGE_Static_Object` for pointer parameters. It defines no Task,
Static Object, Moving Object, Action Object, Map, World, Player, or other
foreign layout.

## PDB, source-order, and virtual evidence

The PDB source is
`C:\\msdev\\work\\age1_x1\\act_entr.cpp`.

The normal owner sequence is:

- `004023C0` `RGE_Action_Enter(int, RGE_Action_Object*)`;
- `00402410` `RGE_Action_Enter(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*)`;
- `004025F0` `RGE_Action_Enter::~RGE_Action_Enter()`;
- `00402600` `RGE_Action_Enter::first_in_stack(unsigned char)`;
- `00402610` `RGE_Action_Enter::set_state(unsigned char)`; and
- `00402740` `RGE_Action_Enter::update()`.

`004023F0` is the compiler-generated scalar deleting destructor. It has no
source body in `act_entr.cpp`.

`inventory/types/dumps/RGE_Action_Enter.txt` records an empty class body with
base `RGE_Action`, zero fields, zero gaps, and size `0x40`. Canonical
`include/action.h` owns the complete `0x40`-byte base and its virtual order.
The derived class adds no fields, so natural VC5 alignment keeps
`sizeof(RGE_Action_Enter) == 0x40`.

The constructor and destructor symbols, the `first_in_stack` symbol, the
protected `set_state` symbol, and the `update` symbol prove the declared
virtual surface. The access split follows the recovered class declaration:
`first_in_stack` and `update` are public, while `set_state` is protected.

## Terra 1 tact_lst dependency

Terra 1 `tact_lst.cpp` waits for this owner header. Its
`TRIBE_Action_List::create_action` and `create_task_action` owners construct
`RGE_Action_Enter`, so the direct source must include `act_entr.h` when that
module is reunified. This checkpoint does not change `tact_lst` source or its
held context header.

## Minimal VC5 size probe

Probe source: `build/header_probes/act_entr_size.cpp`.

Command:

`CL.EXE @config/flags/default.rsp /Iinclude /Fobuild/header_probes/act_entr_size.obj build/header_probes/act_entr_size.cpp`

The probe asserts `sizeof(RGE_Action_Enter) == 0x40`.

Result:

- return code: `0`;
- compiler output: `act_entr_size.cpp`; and
- object SHA-256: `e3e7a93f76f8350f5e21a0a85d6e0bdfc33b1b51aca54bb6fd6e8c2f90c188a8`.

No source-module compile or function validator ran. The probe object and
source remain ignored build artifacts and are not part of the commit.
