# 00412310 `ResourceAIModule::ResourceAIModule`

- PDB source: `airesmod.cpp`, lines 26 to 44.
- Flags: `config/flags/airesmod.rsp`.
- Original size: 325 bytes.

## Recovery record

The old fragment used `__declspec(novtable)` and a direct vtable write. Those forms shaped code generation.

The normal module uses the declared virtual destructor. VC5 now owns the derived vtable store.

This source migration removes the recovery-only vtable write. The normal module has a 13-byte exact difference.
