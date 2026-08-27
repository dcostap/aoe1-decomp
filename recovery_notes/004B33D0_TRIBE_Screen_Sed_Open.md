# 004B33D0 `TRIBE_Screen_Sed_Open::TRIBE_Screen_Sed_Open`

- PDB source: `scr_sedo.cpp`, lines 45 to 99.
- Source module: `src/scr_sedo.cpp`.
- Original size: 683 bytes.

## Migration record

The constructor body moved from its matching bank fragment into the complete
`scr_sedo.cpp` source module. The merge keeps the PDB order and the reviewed
panel layout from `include/scr_sedo.h`.

The `TRIBE_Screen_Sed_Menu` use now has the recovered polymorphic declaration
with its `TScreenPanel` base and panel fields. The declaration is also used by
the `scr_sedm` module. A future `scr_sedm` header migration must move this
declaration to a shared header and remove the duplicate from
`include/scr_sedo.h`. Do not restore a size-only byte-array declaration or
invent missing fields in this module.

The former standalone source recorded a 683-byte exact result. The focused
owner check still reports `MATCH` with 683 bytes after this migration. This
migration did not change the body for byte tuning.
