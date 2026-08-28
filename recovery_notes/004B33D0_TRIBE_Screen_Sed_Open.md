# 004B33D0 `TRIBE_Screen_Sed_Open::TRIBE_Screen_Sed_Open`

- PDB source: `scr_sedo.cpp`, lines 45 to 99.
- Source module: `src/scr_sedo.cpp`.
- Original size: 683 bytes.

## Migration record

The constructor body moved from its matching bank fragment into the complete
`scr_sedo.cpp` source module. The merge keeps the PDB order and uses the
canonical panel and screen providers.

`TRIBE_Screen_Sed_Menu` now comes from its owner header,
`include/scr_sedm.h`. Do not restore a size-only byte-array declaration or
invent missing fields in this module.

The former standalone source recorded a 683-byte exact result. The focused
owner check still reports `MATCH` with 683 bytes after this migration. This
migration did not change the body for byte tuning.
