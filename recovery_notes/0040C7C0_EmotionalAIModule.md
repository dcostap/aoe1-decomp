# 0040C7C0 `EmotionalAIModule::EmotionalAIModule(void*, int)`

- PDB source: `aiemomod.cpp`, lines 23 to 33.
- Original size: 314 bytes.

## Recovery record

A base constructor, state loop, and string copies first gave 73.88% parity. The tested source missed the derived vtable write. The reviewed virtual surfaces on both `AIModule` and `EmotionalAIModule` give the required layout and generated vtable store.

The final module keeps the base constructor call, six state values, and six names in PDB source order.
