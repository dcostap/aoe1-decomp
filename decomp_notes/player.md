# player.cpp direct composition

## Ownership

`src/player.cpp` owns the complete Player module.
It contains all 117 normal `player.cpp` PDB owners in source order.
The header-owned `RGE_Player::logStatus(FILE*, int)` body is included by this
module and emits its original symbol.

The PDB maps `0046ED40` to `player.h:300`.
The original `player.cpp` compiland emits its three-byte body.
Keep the header definition before the `player.cpp` owner sequence.
The direct object matches `0046ED40` at `0.0000%`.

`0046E750` remains compiler-generated.
It is not a handwritten source body.

## Canonical provider pass

The direct source uses canonical Player, World, Command, object, victory, visibility, and AI headers.
It does not include `player_tu_context.h` or `rge_player_context.h`.

The prior Player context used false field and method names.
The direct source now uses these proven calls:

- `RGE_Game_World::commands` at `+0x58`.
- `UnitAIModule::order` at virtual slot `+0x10`.
- `RGE_Command::command_add_waypoint(int, int, XYZBYTEPoint*, int)`.
- `RGE_Command::command_give_attribute(int, int, int, float)` at virtual slot `+0x0C`.
- `RGE_Static_Object::addUserDefinedWaypoint(XYZBYTEPoint*, int)`.
- `RGE_Object_List::update` at Player `+0x30`.
- `RGE_Doppleganger_Creator::perform_doppleganger_checks` at Player `+0x40`.
- `RGE_Visible_Map::set_all` at Player `+0x38`.

The Player source has no local class layouts or raw field offsets.

## Direct validation

The canonical full source compiled with `config/flags/gx.rsp`.
The resulting object matched all 106 registered exact owners.
Each result was `MATCH` and `0.0000%`.

The earlier grouped summary listed `0046E770`: 18 and `004706B0`: 3.
`00470CB0`: 8. It listed `0046FF90` as 13, but that was an effective-size
shortfall, not a positional byte difference. See the checksum re-review below.

The scratch rows have these byte differences.
`0046F420`: 252. `00471550`: 4 and one relocation mismatch.
`00471760`: 43 and two boundary escapes. `004718C0`: 1.
`00471940`: 1. `00471AA0`: 1.

## Selection-count source repair

The command methods use one natural `short count` output local.
They pass that local to `get_selected_objects_to_command` without casts.

This repair covers `command_make_move`, `command_make_work`, and `command_make_do`.
It also covers `command_stop`, `command_formation`, and `command_stand_ground`.

The full 117-body candidate still matches all 106 registered exact owners.
The remaining eleven rows keep their recorded status and mismatch data.

The removed wrapper and its context had no remaining consumers.

## Header-owner closure

The seven standalone header probes from the source bank are deleted. Their
bodies now live in `include/player.h` in PDB order, including the proved
return defaults. The direct Player candidate emits `0046ED40` as
`?logStatus@RGE_Player@@UAEXPAU_iobuf@@H@Z` and reports `MATCH`, `0.0000%`,
with no relocation mismatch or boundary escape.

The same candidate keeps 104 of 105 registered owners exact. `004705A0`
`set_color_table` changes by 20 bytes and one boundary escape after the
header body closure. Its register-color change is recorded as a structural
migration regression. Twenty natural variants emitted the same 28-byte basin.
The original is 27 bytes. The owner is now scratch and is not registered as
exact. The direct natural source remains unchanged.

## Checksum re-review — 0046FF90

The old `13` entry was the effective-size shortfall, not the positional byte
difference. A fresh baseline at state
`8844a4cd2923d3d5ee7a0395cbf56dc3419d5d33791b0e569b31364271f9e052` emitted
264 bytes against 277 and reported 213 strict differences.

The retained source repair restores the period source order, `int` attribute
countdown, and signed-short attribute test. State
`bbaa19d45a4065295a273e3e0751bbc62ef2e2ceba9abfe66af4b03b41237eb0` emits
268 bytes and reports 180 strict differences. It has the correct owner, five
aligned calls, four conditional branches, one return, and no boundary escape.

The checksum arithmetic and field ownership follow the executable. The
attribute loop truncates each float through `__ftol`. The object loop adds
state, held amount, master ID, waypoint checksum, and action checksum. It
rereads `list->node` after the waypoint call for position and action data.
The position sum stores a single-precision value after each object. The final
checksum packs the signed prefix, object count, object checksum, and attribute
checksum in base 256.

The result is blocked from accepted-drift proof. The original reads
`object_state` before the held-amount load and conversion. VC5 emits the
retained source with the float load and `__ftol` first. The original also uses
a `0x18` frame, stores the loop-carried object checksum at `[esp+20h]`, and
stores the prefix at `[esp+24h]`. The rebuilt body uses a `0x14` frame, keeps
the object checksum in `EBP`, and uses `[esp+20h]` for the prefix. These are
different stack writes and fault order. No exact source form is known.

The final closure event is
`32c9f7b9d0c466136fb742cbe340a0521ade2cb7fb728379df08e51627df5e31`. It
compiled all 125 Player owners. All 120 exact owners stayed exact, with no
exact-neighbor regressions. The registry status remains unchanged.
