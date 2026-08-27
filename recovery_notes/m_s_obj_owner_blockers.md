# Master Static owner blockers

## Status

Master Static source remains held.

The earlier 20 matching rows used a context with copied foreign layouts. They
are historical evidence only. They do not support direct-source promotion.

The current branch-local probe uses the canonical Damage Sprite Info, string,
Player, World, and Static Object owners. It now stops at
`src/m_s_obj.cpp:486`: `RGE_Static_Object::copy_obj` does not take five
arguments. This is the next ABI gate.

Do not add an overload, cast, or adapter without PDB and direct-target proof.

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
owner. The Base Game global also needs one canonical declaration.

The later Armor/Weapon pointer assignment remains a source and ABI question.
It is not an include repair.

## Reopen order

1. Prove the five-argument `copy_obj` identity and direct target.
2. Let Terra 4 publish the complete clip method and type surface in `view.h`.
3. Resolve the source-private clip global owner.
4. Reconcile the Sprite and Base Game owner headers.
5. Compose the remaining canonical source dependencies.
6. Resolve the Armor/Weapon pointer assignment from PDB and direct evidence.
7. Run a fresh complete 23-owner candidate check.

Until then, the direct source has no current exact promotion evidence.
