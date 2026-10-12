# act_move.cpp source-module recovery

## PDB ownership

PDB source: `C:\\msdev\\work\\age1_x1\\act_move.cpp`.
The module has nine normal owners and one nearby compiler-generated owner.
Normal source order runs from `00405510` through `00405BF0`.
`00405580` is the scalar deleting destructor emitted for
`RGE_Action_Move_To`; it has no source body.

`RGE_Action_Move_To` owns all nine normal functions. The compiler-facing
source is `src/act_move.cpp`. The direct module declaration is
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
8. `00405850` `update()` — scratch.
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

`rge_fio.h` supplies the `rge_read` and `rge_write` declarations.
`command_waypoint.h` publishes the proven three-byte `XYZBYTEPoint` record from
the shared Command owner. The direct source includes this narrow header, not
duplicate-heavy `Command.h`. `ManagedArray::zeroNumber()` is the canonical
owner method for the proven pathing-group count store.
`m_mo_obj.h` publishes the inherited `move_sprite` member. No local owner or
access workaround is needed. The original first constructor's action-type
store is expressed as a member assignment; the compiler owns the derived vptr
store.

## Structural move

The former source wrapper included one fragment per owner and selected
`include/act_move_context.h` with `ACT_MOVE_CANONICAL_TU`. The direct source
now owns all normal definitions in PDB order. The scratch update remains
in the same source module. The generated deleting destructor remains
source-free.

The candidate proposal is:

`build/candidate_tus/act_move_direct/proposal.json`

The function registry is `config/functions/src/act_move.cpp.json`.
Manual VC5 compilation of `src/act_move.cpp` succeeds with the module response
file.

## Direct candidate result

The direct source metadata is in `config/functions/src/act_move.cpp.json`.
The grouped candidate report was
`build/candidate_tus/act_move_direct/current_main_command_waypoint_rebased/report.txt`.

Against current `main` `ddd2ec833`, which includes the shared Static/Moving
ABI repair from `ad4b69dab`, the candidate compiled all eight exact owners and
the generated destructor. All eight exact owners match. The generated
destructor also matches. The `00405850 update` candidate has 212 changed bytes.
Its check has a
high-severity control-flow difference and one missing cold block. Every exact
and nonexact row has zero relocation mismatches and
zero boundary escapes. The generated destructor is `unverified` with zero
relocations and zero boundary escapes.

This current-main source and metadata chain removes the former wrapper,
context header, accepted-drift fragment, and eight matching fragments.
`config/functions/src/act_move.cpp.json` records the direct source metadata.
`command_waypoint.h` is the only shared-header addition in this chain.

The vslot repair follows the original PDB-backed vtable. The executable's
`RGE_Action_Object` table at `0056E420` places static setup at `+0x1D8` and
`+0x1DC`, then animated setup at `+0x1E8`, moving stop at `+0x1EC`, moving turn
at `+0x1F0`, and moving setup at `+0x1F4`. The PDB marks static
`waitingToMove`, `facetToNextWaypoint`, `actionState`, `getSpeed`, `getAngle`,
`underAttack`, and `numberUserDefinedWaypoints` as const. The canonical headers
now use those const qualifiers, reverse the static setup declarations for
VC5's adjacent-overload order, and place both moving setup declarations after
stop and turn. This removes the synthetic setup and const slots without a
local carrier or vtable workaround.

## Shared ABI fanout after main rebase

The branch is rebased onto current `main` at `ddd2ec833`, which includes
`ee088911a`, the full Action registration from `037871d95`, and the shared
Static/Moving ABI repair from `ad4b69dab`. The fanout reports are under
`build/candidate_tus/shared_abi_fanout`.

The broader fanout rows below were measured against `298cc2a47` and remain
historical. The current-main `act_move` result is recorded above.

The grouped `act_move` candidate has 8/8 exact owners matching and generated
`00405580` matching. Observed `00405850` differs by 212 bytes. Its current
check reports one missing cold CFG block, so it is scratch rather than
accepted drift. All rows have zero relocation mismatches and zero boundary
escapes. Every exact owner has owner status `match`.

The grouped `ani_obj` candidate has 10/10 exact owners matching and generated
`0041A1E0` matching. The Action candidate, including
`00407C10 get_state_name`, has 29/29 exact owners matching and generated
`004074A0` matching. This is 30/30 compiled rows. Every exact owner has owner
status `match`; the generated row is `unverified`. All rows have zero
relocation mismatches and zero boundary escapes. The grouped `act_obj` candidate
has 27/27 exact owners matching and generated `00405F70` matching. Its
observed rows remain nonexact: `00406470` (676 bytes), `00406860` (143),
`00406940` (2), `00406990` (2), `00406A70` (2), `00406B90` (1),
`00406BC0` (18), and `00406C10` (1). These rows have zero relocation
mismatches and zero boundary escapes, with owner status `match`.

The Act Enter exact-anchor candidate has 5/5 exact owners matching and
generated `004023F0` matching. Its observed `00402740` row differs by 663
bytes. It has zero relocation mismatches and zero boundary escapes.

The AIUA exact consumers pass their exact owners. `aiuaimod_complete_fresh`
has 9/9 exact matches. `aiuaimod_prefix` has 94/94 exact matches.
`taiuaimd_cpp_complete` has 20/20 exact matches and 15/15 generated matches.
`taiuaimd_preditor_prefix` has 6/6 exact matches and 2/2 generated matches.
`taiuaimd_soldier_segment` has 4/4 exact matches and one generated match.
The generated `00413070 UnitAIModule` row is not emitted by the current
novtable source and remains an isolated generated-row error in the first two
AIUA candidates. All other AIUA rows have zero relocation mismatches and zero
boundary escapes.

The grouped stat-object candidate is isolated at compile time because the
existing context includes missing `infmap.h`; it produced no comparison rows.
The grouped moving-object candidate remains isolated at compile time because
the existing direct source lacks several complete canonical dependencies,
including `RGE_Sprite`, `Path` helpers, and the moving setup base surface. No
owner, relocation, boundary, or generated result was produced for either
compile failure.
