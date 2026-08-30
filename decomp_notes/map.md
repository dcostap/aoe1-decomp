# map.cpp reconstruction

`src/map.cpp` is the natural source for `C:\msdev\work\age1_x1\map.cpp`.
It contains all 64 normal functions in PDB order.

The vector-deleting destructor at `00455080` is compiler-generated.

The module uses `include/map.h` and the canonical Map dependencies.
It has no source wrapper, context-selection header, copied class, or Tile alias.

## `RGE_Tile` layout

CodeView records prove this packed layout:

```cpp
unsigned char terrain_type : 5;
unsigned char height       : 3;
unsigned char border_type  : 4;
unsigned char border_shape : 4;
```

The first two fields share byte `+0x05`.
The last two fields share byte `+0x06`.
The complete structure size is `0x18`.

The CodeView records use `T_UCHAR` for all four fields.
They prove each field width, bit position, name, and byte offset.

| Field | CodeView record | Bits | Byte |
| --- | --- | ---: | ---: |
| `terrain_type` | `0x28AD` | 0-4 | `+0x05` |
| `height` | `0x28AE` | 5-7 | `+0x05` |
| `border_type` | `0x28AF` | 0-3 | `+0x06` |
| `border_shape` | `0x28B0` | 4-7 | `+0x06` |

`last_drawn_as` starts at `+0x07`.
`objects` starts at `+0x0C`.

Original instructions confirm the layout:

- `get_terrain` masks byte `+0x05` with `0x1F`.
- `get_elev` shifts byte `+0x05` right by five.
- `get_border` masks byte `+0x06` with `0x0F`.
- `save_map` shifts byte `+0x06` right by four.
- `set_elev` preserves the low five bits of byte `+0x05`.

A pinned VC5 probe emitted the same CodeView records and field operations.
A signed `char` control emitted different types and different shift behavior.

No union, accessor mask, explicit padding, or raw offset is necessary.

## Historical migration validation

A pinned VC5 module build compiled all 64 normal functions.
The migration candidate used `build/map_natural_candidate.json`.

The migration exposed a source-composition change in `00457510`.
It also exposed overloaded-symbol lookup failures in the old audit route.
These results described the migration checkpoint, not current function status.

Use the function registry and fresh checks for current status.

## Compile repair

`debug_rand` and `debug_srand` use the canonical C++ declarations from
`include/basegame.h`.

The old `old_map_cutoff` label had no owner.
`load_map` uses the canonical `DAT_005706a8` object at `005706A8`.

The stale `map_context.h` and `map_tile_context.h` headers had no Map consumer.
The RMM terrain header now includes the canonical `include/map.h` declaration.
