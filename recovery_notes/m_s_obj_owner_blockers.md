# Master Static owner blockers

## Status

Master Static source remains held.

The earlier 20 matching rows used a context with copied foreign layouts. They
are historical evidence only. They do not support direct-source promotion.

The current branch-local probe uses the canonical Damage Sprite Info, string,
Player, World, Static Object, and Sound owners. It now stops at
`src/m_s_obj.cpp:719` on incomplete `RGE_Sprite`. Do not include `sprite.h`
until Terra 5 completes its current Base Game composition repair.

The former line-486 gate is resolved. The correct identity is
`?recycle_in_to_game@RGE_Static_Object@@UAEXPAVRGE_Master_Static_Object@@PAVRGE_Player@@MMM@Z`,
at virtual slot `+0x04`. It takes a master, a player, and three floats. The
original `00452FE0` listing pushes those five arguments and calls slot `+0x04`.
That slot targets `004C1420`. The former `copy_obj` reading was wrong because
`copy_obj` is the one-argument virtual at `+0x58`, not the called slot.

## Owner progress

`RGE_Damage_Sprite_Info` is published through its canonical owner. The clip
method and type surface remains held for the Terra 4 `view.h` owner. Its
source-private global ownership also remains unresolved. Do not publish
`SDI_List` or `SDI_Object_ID` in a public owner header. The direct source does
not yet consume a canonical clip header.

## Other owner gaps

The later source still needs compatible Sprite, Base Game, Map, Tile, Visible
Map, and Object Node composition. `sprite.h` no longer duplicates Sound. Its
remaining Base Game surface does not compose with the canonical Base Game
owner. Wait for Terra 5 to repair this scope before adding `sprite.h`. The Base
Game global also needs one canonical declaration.

The later Armor/Weapon pointer assignment remains a source and ABI question.
It is not an include repair.

## Reopen order

1. Let Terra 4 publish the complete clip method and type surface in `view.h`.
2. Resolve the source-private clip global owner.
3. Wait for the Terra 5 Sprite and Base Game composition repair.
4. Compose the remaining canonical source dependencies.
5. Resolve the Armor/Weapon pointer assignment from PDB and direct evidence.
6. Run a fresh complete 23-owner candidate check.

Until then, the direct source has no current exact promotion evidence.
