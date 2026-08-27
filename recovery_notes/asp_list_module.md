# asp_list.cpp source-reunification note

## Context

- PDB source module: `C:\\msdev\\work\\age1_x1\\asp_list.cpp`.
- The module owns 23 normal `RGE_Active_Sprite_List` functions.
- PDB lines run from 23 through 390 in source order.
- Linked normal owners run from `0041A640` through `0041ACF0`.
- The nearby `0041A660` entry is the compiler-generated vector-deleting destructor.
- `0041A6F0` is the protected `load_node` owner. Its PDB symbol is `?load_node@RGE_Active_Sprite_List@@MAEEHEPAPAVRGE_Sprite@@@Z`.
- The exact owner anchors are `0041A640`, `0041A680`, `0041A690`, `0041A6F0`, `0041A820`, `0041A860`, `0041A8B0`, `0041A8F0`, `0041A9B0`, `0041AA20`, `0041AA50`, `0041AAA0`, `0041AAE0`, `0041AB20`, `0041AB60`, `0041AB90`, `0041ABC0`, `0041AC00`, `0041AC30`, `0041AC70`, `0041ACC0`, and `0041ACF0`.

The module now has one compiler-facing source owner, `src/asp_list.cpp`, and one module-owned declaration header, `include/asp_list.h`. The old wrapper, context header, and source-bank fragments are removed.

## Status

Twenty-two owners remain matching. Their prior standalone checks reported `MATCH`, `0.0000%`, correct boundaries, relocations, and direct targets. `0041A910 add_sprite` remains `verified_logic`.

`add_sprite` is behavior-complete and retains the reviewed typed list insertion source. Its clean source emits 158 bytes with 36 positional differences and 26 edit differences. The first mismatch is at offset `+26` (`0041A936`). Probes tested cursor forms, declaration order, aliases, allocation forms, virtual surfaces, and compiler flags. The remaining drift is a broad VC5 register and liveness basin: the rebuilt source folds `this` into `ESI = &list` and uses `EDI` for the new node, while the original preserves `ESI = this` and uses `EDI` for the pointer-to-pointer cursor. The difference spans traversal, duplicate counting, allocation, insertion, and the return path. It is not accepted-drift safe.

The normal source keeps the original duplicate-count behavior and insertion order. It does not use byte forcing, inline assembly, synthetic padding, manual vptr writes, or codegen-only wrappers.

## Cross-shard evidence

No shared header, ABI registry, global definition, compiler flag, generated inventory, or other module changed. The module-owned header uses the PDB-backed `RGE_Active_Sprite_List`, `RGE_Active_Sprite`, `RGE_Active_Animated_Sprite`, and node layouts already used by the prior wrapper. No cross-shard declaration request is open.
