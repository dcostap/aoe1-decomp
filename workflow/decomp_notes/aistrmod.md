# aistrmod.cpp source module

## Context

The PDB identifies `C:\\msdev\\work\\age1_x1\\aistrmod.cpp` as the owner of
two normal functions. Their source lines run from 22 through 29, and their
addresses preserve that order:

| VA | PDB lines | bytes | owner |
| --- | ---: | ---: | --- |
| `00412AF0` | 22-24 | 42 | `StrategyAIModule` constructor |
| `00412B40` | 29 | 11 | `StrategyAIModule` destructor |

The vector-deleting destructor at `00412B20` is compiler generated. It has no
handwritten source owner.

## Migration

`src/aistrmod.cpp` is the direct compiler-facing owner for both normal
functions. It follows PDB order and uses canonical `include/aimodule.h` for
the real `AIModule` declaration. The module header retains only the
`StrategyAIModule` declaration. The constructor passes the original name, ID,
parameter, and object to the base constructor.

The derived destructor uses the real virtual base surface. VC5 restores the
derived vptr and emits the tail jump to `AIModule::~AIModule`.

The old `src/aistrmod_tu.cpp` wrapper, two source-bank fragments, and
`include/aistrmod_context.h` are removed. No context macro, fallback
declaration, inline assembly, fake vtable, or duplicate owner remains.

## Validation

The focused candidate validation uses `config/flags/default.rsp` and compares
both normal owners plus the compiler-generated vector-deleting destructor.
The direct TU registry entry points to `src/aistrmod.cpp` and keeps the same
qualified normal symbols.
