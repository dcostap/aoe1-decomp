# act_move.cpp source-module recovery

## PDB ownership

PDB source: `C:\\msdev\\work\\age1_x1\\act_move.cpp`.
The module has nine normal owners and one nearby compiler-generated owner.
Normal source order runs from `00405510` through `00405BF0`.
`00405580` is the scalar deleting destructor emitted for
`RGE_Action_Move_To`; it has no source body.

`RGE_Action_Move_To` owns all nine normal functions. The compiler-facing
source is `src/act_move_tu.cpp`. The direct module declaration is
`include/act_move.h`.

Normal owners, in source and address order:

1. `00405510` `RGE_Action_Move_To(int, RGE_Action_Object*)` — matching.
2. `004055A0` `RGE_Action_Move_To(RGE_Action_Object*, float, float, float,
   float, RGE_Sprite*)` — matching.
3. `00405620` `RGE_Action_Move_To(RGE_Action_Object*, RGE_Static_Object*,
   float, RGE_Sprite*)` — matching.
4. `004056E0` `~RGE_Action_Move_To()` — matching.
5. `00405750` `save(int)` — matching.
6. `00405780` `first_in_stack(unsigned char)` — matching.
7. `004057E0` `set_state(unsigned char)` — matching.
8. `00405850` `update()` — accepted drift.
9. `00405BF0` `is_in_range()` — matching.

## Canonical dependency closure

The module header includes `include/action.h` for the base action owner and
`include/act_obj.h` for the action-object owner.
The source includes these complete owner surfaces:

- `include/act_move.h`: the derived action declaration and member `range`.
- `include/action.h`: `RGE_Action` fields, constructors, and virtual slots.
- `include/act_obj.h`: action-object fields and owner inheritance.
- `include/move_obj.h`: moving-object fields and movement methods.
- `include/ani_obj.h`: animated-object inheritance from the canonical chain.
- `include/stat_obj.h`: static-object fields and methods.
- `include/m_ac_obj.h`: action-master fields and moving-master inheritance.
- `include/m_s_obj.h`: master-static fields used by sprite and radius reads.
- `include/player.h`: the player `world` field.
- `include/world.h`: the world `object(int)` method.

`map.h` is not a direct dependency. The module only follows the `map` pointer
owned by `RGE_Game_World` indirectly through the complete world declaration.
`path.h`, `zone_map.h`, and `utmarray.h` arrive through the canonical movement
and static-object owners. No local class layout, context header, source-bank
include, wrapper macro, raw overlay, or manual vtable remains.

The canonical animated-object owner supplies the `rge_read` and `rge_write`
declarations. The source adds no public helper declaration. The original first
constructor's action-type store is expressed as a member assignment; the
compiler owns the derived vptr store.

## Structural move

The former source wrapper included one fragment per owner and selected
`include/act_move_context.h` with `ACT_MOVE_CANONICAL_TU`. The source now owns
all normal definitions in PDB order. The accepted-drift update remains in the
same source module. The generated deleting destructor remains source-free.

The candidate proposal is:

`build/candidate_tus/act_move_direct/proposal.json`

The lead must add the direct source-module manifest and then compile the
proposal. This captain did not run a compiler or validator.

## Open validation

The accepted-drift `00405850 update` retains its reviewed state. The lead must
check all nine normal boundaries, symbols, relocations, and direct call targets
from the direct source after module registration. The response file is
`config/flags/00405620_RGE_Action_Move_To.rsp`.
