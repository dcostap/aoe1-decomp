# aiinfmod.cpp source module

## PDB context

- PDB source: `C:\\msdev\\work\\age1_x1\\aiinfmod.cpp`.
- The module has two normal owners at lines 22-24 and 29.
- Both owners belong to `InformationAIModule`.
- The address sequence is `0040CD90`, then `0040CDE0`.
- The scalar deleting destructor at `0040CDC0` is compiler generated. It has
  no PDB source line and is not a normal source owner.
- The constructor calls `AIModule::AIModule` at `0040E2D0`. The destructor
  stores the derived vptr and tail-jumps to `AIModule::~AIModule` at `0040E360`.

## Source result

`src/aiinfmod.cpp` owns both handwritten functions in PDB order. It uses the
module header `include/aiinfmod.h`. It has no wrapper, source-fragment include,
context macro, fallback declaration, or inline assembly.

The header uses the canonical `AIModule` declaration and proves the
`InformationAIModule` size of `0xF0`. The constructor keeps the shipped
`"InfAI"`, `0x3ED`, and argument order. The empty destructor keeps the natural
derived-vptr store and base-destructor tail jump.

## Migration and validation

The old wrapper was `src/aiinfmod_tu.cpp`. It included the two matching source
fragments after selecting `include/aiinfmod_context.h`. The migrated source
removes that wrapper, both fragments, and the context header.

The registered translation unit uses `config/flags/default.rsp` and maps both
owners directly to `src/aiinfmod.cpp`. The generated scalar deleting
destructor remains an emitted compiler-generated entry between the two normal
owners.
