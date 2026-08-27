# ani_obj.cpp source-module recovery

## Context and ownership

- PDB source: `C:\\msdev\\work\\age1_x1\\ani_obj.cpp`.
- The module owns 10 normal functions in PDB source order from lines 29 through
  160.
- The owner address sequence is `0041A150`, `0041A210`, `0041A280`, `0041A2C0`,
  `0041A310`, `0041A350`, `0041A3D0`, `0041A400`, `0041A410`, and `0041A430`.
- The nearby `0041A1E0` entry is a compiler-generated scalar deleting
  destructor. It has no handwritten source owner.

The module header owns only the `RGE_Animated_Object` surface. The source
privately includes the canonical Active Sprite List, Player, file-I/O, and
World owners. The executable proves the animated speed field at `+0x88` and
the static-object state and type fields at `+0x48` and `+0x4E`. The virtual
slots used by `update` are the sprite-list `is_animating` and `update` slots.

## Migration

- Merged all 10 source-bank bodies into `src/ani_obj.cpp` in PDB order.
- Replaced the wrapper and fallback declarations with `include/ani_obj.h`.
- Removed the context-selection macro and all source-bank `.cpp` includes.
- Removed the old wrapper, context header, and 10 matching fragments owned by
  this module.
- Kept the constructor EH shape, natural base construction, virtual calls, and
  source line ordering. The source uses no inline assembly, manual vptr stores,
  fake virtual slots, or codegen-only machinery.

## Status and validation

The manifest keeps all 10 normal owners as matching. The translation-unit
registry directly owns `src/ani_obj.cpp`. It registers all 10 normal owners.

The final grouped candidate result is in
`build/candidate_tus/ani_obj_natural_cast_cleanup/report.txt`. All 10 normal
owners report `MATCH` and `0.0000%`. They have correct owners, zero relocation
target mismatches, and zero boundary escapes. Generated `0041A1E0` also
reports `MATCH` at 30/30 bytes through the VC5 deleting-destructor fallback.

The generated destructor remains outside the normal manifest. The candidate
proposal checks it as a weak VC5 fallback when the compiler emits its generated
symbol.

## Cross-shard evidence

No shared declaration, global definition, compiler flag, or generated
inventory changed during this final include cleanup.
