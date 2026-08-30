# act_entr.cpp direct-source checkpoint

## Scope

The PDB source is
`C:\\msdev\\work\\age1_x1\\act_entr.cpp`.

`src/act_entr.cpp` is the compiler-facing owner for all six handwritten normal
functions. The functions stay in PDB address order:

1. `004023C0` `RGE_Action_Enter(int, RGE_Action_Object*)`;
2. `00402410` `RGE_Action_Enter(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*)`;
3. `004025F0` `RGE_Action_Enter::~RGE_Action_Enter()`;
4. `00402600` `RGE_Action_Enter::first_in_stack(unsigned char)`;
5. `00402610` `RGE_Action_Enter::set_state(unsigned char)`; and
6. `00402740` `RGE_Action_Enter::update()`.

`00402740` remains `scratch` and unregistered in
`config/source_modules/act_entr.json`. It has no separate source owner.
`src/scratch/00402740_update.cpp` was removed.

`004023F0` is the compiler-generated scalar deleting destructor. It is not a
PDB normal owner and has no source body.

## Canonical source and update reconstruction

The direct source uses the reviewed action, action-object, player, task, world,
and static-object declarations. `RGE_Action_Enter` has no fields beyond its
`RGE_Action` base, so its size remains `0x40`.

The update source uses typed `RGE_Static_Object*` targets and a
`static_cast<RGE_Action_Object*>` for the action-list lookup. It has no
attempt-log text, decompiler carrier declarations, or decompiler pointer casts.

Both proven state-4 and state-2 `enter_obj` call sites remain. They use the
inherited `RGE_Static_Object::enter_obj` virtual at vslot `+0xD0`. Both sites
continue to the shared entered tail, which emits the optional notification,
sets state `1`, and returns `2`.

The target-ID checks, target ownership check, state switch, path update, action
coordinate lookup, state changes, notifications, and return values remain in
source. The update remains scratch because its reconstruction is not exact.

The moved update candidate compiled as `?update@RGE_Action_Enter@@UAEEXZ`.
It is 1012 rebuilt bytes versus 954 original bytes, with 957 differing bytes
and one boundary escape. It remains an observed mismatch, not an exact claim.

## Exact-owner checkpoint

The five existing registered owners must remain exact in the authentic
`act_entr.cpp` translation unit:

- `004023C0`: `MATCH`, 40 bytes;
- `00402410`: `MATCH`, 477 bytes;
- `004025F0`: `MATCH`, 11 bytes;
- `00402600`: `MATCH`, 10 bytes; and
- `00402610`: `MATCH`, 254 bytes.

The generated deleting destructor at `004023F0` must also remain exact. The
update at `00402740` is an observed scratch owner only and is not registered.
