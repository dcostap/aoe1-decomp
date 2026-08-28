# player.cpp direct composition

## Ownership

`src/player.cpp` owns the complete Player module.
It contains all 117 normal `player.cpp` PDB owners in source order.
It also emits `0046ED40 RGE_Player::logStatus(FILE*, int)`.

The PDB maps `0046ED40` to `player.h:300`.
The original `player.cpp` compiland emits its three-byte body.
Keep that definition before the `player.cpp` owner sequence.
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

The canonical full source compiled with `config/flags/0046E4B0_RGE_Player.rsp`.
The resulting object matched all 106 registered exact owners.
Each result was `MATCH` and `0.0000%`.

The accepted-drift rows have these byte differences.
`0046E770`: 18. `0046FF90`: 13. `004706B0`: 3.
`00470CB0`: 8. `00471C90`: 24 and two boundary escapes.

The scratch rows have these byte differences.
`0046F420`: 252. `00471550`: 4 and one relocation mismatch.
`00471760`: 43 and two boundary escapes. `004718C0`: 1.
`00471940`: 1. `00471AA0`: 1.

The removed wrapper and its context had no remaining consumers.
