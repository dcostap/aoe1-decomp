# 004B33D0 `TRIBE_Screen_Sed_Open::TRIBE_Screen_Sed_Open`

- PDB source: `scr_sedo.cpp`, lines 45 to 99.
- Source module: `src/scr_sedo.cpp`.
- Original size: 683 bytes.

## Migration record

The constructor body moved from its matching bank fragment into the complete
`scr_sedo.cpp` source module. The merge keeps the PDB order and the reviewed
panel layout from `include/scr_sedo.h`.

The former standalone source recorded a 683-byte exact result. The first
complete-module build reports a temporary grouped mismatch. This migration did
not change the body for byte tuning. Exact repair can resume on the final
source tree.
