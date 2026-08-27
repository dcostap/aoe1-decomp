# Stat and master header composition dependencies

## Published owner surfaces

`m_s_obj.h` owns only `RGE_Master_Static_Object`. It keeps the proven `0xB8`
record and virtual order. `stat_obj.h` owns only `RGE_Static_Object`, its
`0x88` record, and stat-owned check records.

`player.h` owns `RGE_Tile_List_Node` and `RGE_Tile_List`. The node is `0x08`.
Its fields are `col +0x00` and `row +0x04`. The list is `0x14`.

The list fields are list size `+0x00`, active count `+0x04`, new count `+0x08`,
collapse flag `+0x0C`, and list pointer `+0x10`. Exact `00471E90` is
`void get_list_info(RGE_Tile_List_Node*&, int&)`.

## Deferred owner surfaces

`com_obj.h` must later own `RGE_Combat_Object : RGE_Action_Object`, size `0x1C4`.
Its `VUR_Ptrs` field is `VISIBLE_UNIT_REC* [9]` at `+0x194`. The header must
forward-declare `VISIBLE_UNIT_REC`. It must not copy its record definition.

The combat header waits for canonical `RGE_Action_Object`. It cannot derive from
a forward declaration. The action owner header must publish that base first.

## Source dependency list

`m_s_obj.cpp` needs published surfaces for Sprite, Sound, Static Object, Player,
World, Map, Object List, Base Game, and Master Combat. It currently uses their
fields or member calls. Forward declarations cannot compile these source paths.

`stat_obj.cpp` needs Master Static, Player, World, Map, Sprite, Object List,
Active Sprite List, Drawarea, Zone Map, and Base Game surfaces. Map and Base
Game remain held. The source therefore stays blocked after the header-only split.

The published static virtual table uses the FPO and PDB types. In particular,
`canPathWithObstructions` takes `ManagedArray<int>&`; the `XYZPoint` path
overloads pass the point by value; the `XYPoint` line overloads use references;
and `findAvoidancePath` returns `Path*` and takes `XYZPoint&`. The old
`void*` placeholders are not owner declarations.

## Reopening condition

Replace source-local support declarations only when the listed owner headers are
published. Then validate the m_s, stat, m_an, m_mo, and m_dg groups together.
Keep `004512D0` scratch until its composed-header source matches.
