# RGE_Master_Player owner audit

## Result

The binary supports one `RGE_Master_Player` class. It has size `0x2C` (44 bytes).
It has no proven base class. Current main publishes the canonical owner in
`include/mst_play.h` and the direct source owner in `src/mst_play.cpp` through
`24bd5ad74`.

The type inventory names these fields:

| Field | Type | Offset |
| --- | --- | ---: |
| `name` | `char[20]` | `0x04` |
| `master_object_num` | `short` | `0x18` |
| `master_objects` | `RGE_Master_Static_Object**` | `0x1C` |
| `attribute_num` | `short` | `0x20` |
| `attributes` | `float*` | `0x24` |
| `culture` | `unsigned char` | `0x28` |
| `type` | `unsigned char` | `0x29` |
| `tribe_effect` | `short` | `0x2A` |

Evidence: `inventory/types/dumps/RGE_Master_Player.txt` and
`inventory/types/all_types_reference.h`. The class size also appears in
`inventory/classes/dumps/RGE_Master_Player.txt`.

## Virtual and non-virtual surface

The base vtable is at `0x00570C08`. Every proven member method is virtual.
There are no proven non-virtual member methods.

| Slot | Method | Code address |
| ---: | --- | ---: |
| `0` | deleting destructor wrapper | `0x004610A0` |
| `1` | `finish_init(int, RGE_Sprite**, RGE_Sound**)` | `0x004611D0` |
| `2` | `load_master_object(int, unsigned char, RGE_Sprite**, RGE_Sound**, short)` | `0x00461270` |
| `3` | `create_master_object_space(short)` | `0x00461530` |
| `4` | `load_object(FILE*, unsigned char, RGE_Sprite**, RGE_Sound**, short)` | `0x00461560` |
| `5` | `save(int)` | `0x00461840` |

The deleting wrapper calls the destructor body at `0x00461150`.
The vtable entries and targets are in `orig/aoe1_ghidra_assembly_listing.txt`.
The method signatures and slots are also in the class inventory.

## Constructors

Two constructors have direct PDB and binary owners:

| Constructor | Code address | PDB lines |
| --- | ---: | ---: |
| `RGE_Master_Player(FILE*)` | `0x00460FD0` | `mst_play.cpp:28-57` |
| `RGE_Master_Player(int)` | `0x004610C0` | `mst_play.cpp:62-76` |

The PDB-qualified symbols are:

- `??0RGE_Master_Player@@QAE@PAU_iobuf@@@Z`
- `??0RGE_Master_Player@@QAE@H@Z`

Generated class metadata also lists `RGE_Master_Player()`. No function map
row or binary owner proves that default constructor. Do not publish it as an
executable-backed constructor until donor source or symbol evidence confirms
it. This is the main open fact for a canonical owner header.

## PDB source ownership

The complete handwritten class surface belongs to `mst_play.cpp`:

- `0x00460FD0`: `RGE_Master_Player(FILE*)`, lines 28-57.
- `0x004610C0`: `RGE_Master_Player(int)`, lines 62-76.
- `0x00461150`: destructor body, lines 80-103.
- `0x004611D0`: `finish_init`, lines 107-128.
- `0x00461270`: `load_master_object`, lines 132-161.
- `0x00461530`: `create_master_object_space`, lines 166-171.
- `0x00461560`: `load_object`, lines 176-205.
- `0x00461840`: `save`, lines 210-234.

The direct `src/mst_play.cpp` source module owns the handwritten bodies in PDB
order. Its registration has eight exact rows. Address `0x004614D9` is a
reviewed padding-only switch-table artifact, not a class method or source
owner.

## World direct target identities

The following World call sites use this class surface:

| World call site | Operation | Proven target |
| ---: | --- | --- |
| `0x00540A59` | master-player slot `0` | base deleting wrapper `0x004610A0` |
| `0x00541281` | direct `FILE*` constructor | `0x00460FD0` |
| `0x0054140F` | master-player slot `3` | `0x00461530` |
| `0x0054146B` | master-player slot `4` | `0x00461560` |
| `0x005417B2` | direct `int` constructor | `0x004610C0` |
| `0x005417E2` | master-player slot `1` | `0x004611D0` |
| `0x005439A7` | master-player slot `5` | `0x00461840` |

Evidence: `orig/ghidra_decomp/world.cpp.asm`, with PDB owners
`World.cpp:226-254`, `World.cpp:528`, `World.cpp:568-601`,
`World.cpp:718-731`, and `World.cpp:2108-2152`.

`TRIBE_Master_Player` supplies the derived dispatch used by `tworld.cpp`.
Its vtable is at `0x00576800`:

- slot `0`: `0x005117E0`, derived deleting wrapper;
- slot `1`: inherited `0x004611D0`;
- slot `2`: override `0x00511830`;
- slot `3`: inherited `0x00461530`;
- slot `4`: override `0x00511990`;
- slot `5`: inherited `0x00461840`.

Its constructors call the base constructors at `0x005117C8` and `0x00511808`.
Its destructor tail-jumps to `0x00461150` at `0x00511826`.
Its fallback loaders call `0x00461270` at `0x00511873` and `0x00461560`
at `0x005119D4`.

## Current owner use

Use `include/mst_play.h` for every complete `RGE_Master_Player` consumer.
Forward declarations in `world.h`, `player.h`, and `game_types.h` remain safe.
The historic context and function-local declarations were recovery evidence;
they do not define the current owner.

Do not add a default constructor. It has generated donor metadata only. No
binary owner or PDB function row supports an executable-backed declaration.
