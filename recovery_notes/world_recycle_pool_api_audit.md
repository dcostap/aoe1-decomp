# World recycle-pool API audit

Status: read-only. This audit uses current `main` and the original PDB and
binary records. It does not edit World source or headers.

## Recovered API

PDB owner `00546180` is `World.cpp` lines 3841-3898:

```cpp
RGE_Static_Object* RGE_Game_World::recycle_object_in_to_game(unsigned char);
```

The decorated symbol confirms `__thiscall`, an `unsigned char` key, and an
`RGE_Static_Object*` return. The original body initializes a null result. An
unknown key returns that null result.

The unsigned-byte dispatch keys are:

| Key | Pool field | World offset |
| ---: | --- | ---: |
| `0x0A` | `reusable_static_objects` | `+0xD8` |
| `0x14` | `reusable_animated_objects` | `+0xDC` |
| `0x19` | `reusable_doppleganger_objects` | `+0xF0` |
| `0x1E` | `reusable_moving_objects` | `+0xE0` |
| `0x28` | `reusable_action_objects` | `+0xE4` |
| `0x32` | `reusable_combat_objects` | `+0xE8` |
| `0x3C` | `reusable_missile_objects` | `+0xEC` |

Each selected `RGE_Object_List` supplies `list`. The first node supplies
`node`, an `RGE_Static_Object*`. The body calls
`RGE_Object_List::remove_node(object, 0)` at direct target `00462F70`, then
returns the object. The first six cases return from their case body. The
`0x19` case falls through to the common return.

## Canonical owners

- `include/world.h` owns the `RGE_Game_World` method, seven pool pointers, and
  their typed fields.
- `include/obj_list.h` owns `RGE_Object_List::list`,
  `RGE_Object_Node::node`, and `remove_node`.
- `RGE_Static_Object` is only a pointer type here. Its full header is not
  needed by this body.

The current matching source already uses typed locals:
`RGE_Static_Object*`, `RGE_Object_List*`, and `RGE_Object_Node*`. Do not replace
these with raw offsets, pointer iteration, or an integer return.

## Source-private and global needs

No source-private declaration or global definition is needed. The switch and
its sparse selector data are compiler-generated read-only tables near
`0054627C` and `0054629C`; they are not source globals. Do not add a key array,
absolute-address macro, pool carrier, or context-local storage.

A natural owner can include `include/world.h` and `include/obj_list.h`. It needs
no `world_phase2_context.h`, duplicate class declaration, or new header. The
existing public declaration is sufficient. No production source or header was
changed for this audit.
