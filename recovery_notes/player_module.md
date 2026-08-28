# player.cpp direct composition hold

## Owner identity

`0046ED40` is `RGE_Player::logStatus(FILE*, int)`. The PDB assigns it to
`player.h:300`. Its body is `0046ED40-0046ED42`: `c2 08 00`.

The legacy Player wrapper reaches `RGE_Player` through
`src/player_tu_context.h` and `include/rge_player_context.h`. It does not parse
`include/player.h`.

A header-only trial put the empty body in `player.h` and removed the wrapper
fragment. The rebuilt Player object then had an undefined
`?logStatus@RGE_Player@@UAEXPAU_iobuf@@H@Z` COFF symbol. It did not emit the
three-byte PDB body. Restore the old wrapper state. Do not add a wrapper
fragment, guard lane, filler, or context declaration as a fix.

## Factory evidence

The standalone `00470C70` check is `MATCH`, `0.0000%`. Its master factory call
uses virtual slot `+0x18`.

The same body in the grouped Player candidate is not exact. It is 88/89. The
single difference uses slot `+0x1C`. Keep `00470C70` unregistered.

## Victory field type

`RGE_Player::victory_conditions` has canonical type
`RGE_Victory_Conditions*` at `+0x34`. The PDB dump records it at
`inventory/types/dumps/RGE_Player.txt:29` and `:97`. CodeView record type
`0x2861` in `build/age1_types.txt` gives the same base pointer type.
PDB maps `00471C90` and `00471D00` to `RGE_Player::load_victory` and
`RGE_Player::new_victory`. Both allocate the base Victory class.

PDB maps `0052ECF0 TRIBE_World::scenario_make_player` to `tworld.cpp`, lines
458-470. That owner constructs `TRIBE_Player` objects for Tribal world slots.
`TRIBE_Player` overrides the Victory methods to allocate the derived class.
TScenario casts each loaded base field only where it needs `add_tech`, the
Tribal-only method.

## Direct-source hold

The required path is one PDB-order Player source that consumes canonical
`include/player.h`. It must emit `logStatus` naturally and keep `00470C70` at
`+0x18` in the same object.

The current direct-source trial stops before code generation. The first owner
clusters are:

- World and master-player: `RGE_Game_World`, `RGE_Master_Player`.
- Object graph: `RGE_Object_List`, `RGE_Visible_Map`,
  `RGE_Doppleganger_Creator`, and `RGE_Static_Object`.
- Player AI, command, and CRT declaration surfaces.

Do not repair these through a Player-local layout or context carrier. Reopen
only after the canonical external owners compose with direct `player.cpp`.
Require the 89-owner grouped gate, generated and header rows, exact symbols,
boundaries, direct targets, relocations, and Player consumer fanout.
