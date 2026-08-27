# act_entr.cpp direct-source checkpoint

## Scope

The PDB source is
`C:\\msdev\\work\\age1_x1\\act_entr.cpp`.

`src/act_entr.cpp` is the direct source for the five matching handwritten
owners. It uses `include/act_entr.h` and the canonical owner headers. It does
not use `include/act_entr_context.h`, a function-fragment include, or a local
carrier. The independent `00402740` reconstruction remains in
`src/scratch/00402740_update.cpp`.

The six PDB normal owners stay in source and address order:

1. `004023C0` `RGE_Action_Enter(int, RGE_Action_Object*)`;
2. `00402410` `RGE_Action_Enter(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*)`;
3. `004025F0` `RGE_Action_Enter::~RGE_Action_Enter()`;
4. `00402600` `RGE_Action_Enter::first_in_stack(unsigned char)`;
5. `00402610` `RGE_Action_Enter::set_state(unsigned char)`; and
6. `00402740` `RGE_Action_Enter::update()`.

`004023F0` is the compiler-generated scalar deleting destructor. It is not a
PDB normal owner and has no source body. The direct source defines the
non-deleting destructor at `004025F0`; VC5 also emits the generated deleting
destructor from that class.

## Canonical dependency closure

The direct source composes these reviewed owners:

- `include/act_entr.h` owns `RGE_Action_Enter`;
- `include/action.h` owns the complete `RGE_Action` base;
- `include/act_list.h` owns `RGE_Action_List`;
- `include/act_move.h` owns `RGE_Action_Move_To`;
- `include/act_obj.h` owns `RGE_Action_Object` and its inheritance chain;
- `include/player.h` owns `RGE_Player` and `computerPlayer`;
- `include/task.h` owns `RGE_Task` and its accessed fields;
- `include/world.h` owns `RGE_Game_World` and `object`/time fields; and
- `include/game_globals.h` owns the shared float constants.

The action-object chain supplies the canonical `RGE_Static_Object` surface.
The derived class has no fields, so `sizeof(RGE_Action_Enter) == 0x40`.

The Terra 3 audit and the canonical `include/stat_obj.h` place the float
`moveTo(float, float, float, float, int)` virtual at `+0x154`. This removes the
two-byte mismatch from the direct second constructor. No manual vtable or
foreign carrier is used.

## Candidate validation

Proposal: `build/candidate_tus/act_entr.json`.

The grouped candidate compiles `src/act_entr.cpp` with
`config/flags/00402410_RGE_Action_Enter.rsp`. It reports `MATCH` and `0.0000%`
for all five direct owners:

- `004023C0`: 40 bytes, zero difference;
- `00402410`: 477 bytes, zero difference;
- `004025F0`: 11 bytes, zero difference;
- `00402600`: 10 bytes, zero difference; and
- `00402610`: 254 bytes, zero difference.

The generated `004023F0` deleting destructor also reports `MATCH` with zero
difference. The candidate has zero relocation mismatches and zero boundary
escapes. The result passed again after direct ownership registration.

## Independent update status

`00402740` stays `scratch` in the source-module metadata and is not in the
direct-owner proposal. Its independent source remains unchanged. The last
recorded reconstruction result is a 663-byte mismatch and it still lacks the
binary `+0xD0` `enter_obj` call. Do not promote or register this owner.
