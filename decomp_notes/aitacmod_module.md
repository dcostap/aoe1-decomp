# aitacmod.cpp source module

## PDB context

- PDB source: `C:\\msdev\\work\\age1_x1\\aitacmod.cpp`.
- The module has two normal owners. Their source lines run from 24 through 31.
- Both owners belong to `TacticalAIModule`, derived from `AIModule`.
- The address sequence is `00412B50`, then `00412BA0`.
- The class inventory and module context prove the `0xF0` object size.
- The scalar/vector deleting destructor at `00412B80` is compiler generated.
  It has no handwritten source owner.

## Source result

`src/aitacmod.cpp` is the direct compiler-facing owner for both normal
functions. It follows PDB order and uses the module header
`include/aitacmod.h`, which reuses the canonical `AIModule` declaration.

The constructor preserves the shipped `"TacAI"`, ID `0x3F1`, and argument
order. The empty virtual destructor uses the real derived and base class
surfaces. VC5 therefore emits the derived vptr store and the tail jump to
`AIModule::~AIModule`.

The old `src/aitacmod_tu.cpp` wrapper, two source-bank fragments, and
`include/aitacmod_context.h` are removed. No context macro, fallback
declaration, inline assembly, fake vtable, or duplicate owner remains.

## Exact anchors

- `00412B50` calls `AIModule::AIModule` and then stores the derived vptr.
- `00412BA0` stores the derived vptr and jumps to `AIModule::~AIModule`.
- The generated `00412B80` body calls the derived destructor and performs the
  compiler's delete path.

## Validation

The candidate proposal uses `config/flags/default.rsp` and checks both normal
owners plus the generated deleting destructor. It reports `MATCH` for all
three entries, zero byte differences, zero relocation-target mismatches, and
zero boundary escapes. The generated entry accepts the VC5 weak `_G` symbol
for the expected `_E` symbol.

The focused checks for `00412B50` and `00412BA0` both report `Result: MATCH`
and `0.0000%` positional difference. The registered translation-unit entry
maps both normal owners directly to `src/aitacmod.cpp` and records their
qualified symbols.
