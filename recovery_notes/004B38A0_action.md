# 004B38A0 `TRIBE_Screen_Sed_Open::action`

- PDB source: `scr_sedo.cpp`, lines 155 to 245.
- Source module: `src/scr_sedo.cpp`.
- Original size: 1003 bytes.
- Recovery state: scratch.

## Migration record

The action body moved from the accepted-drift bank into the complete
`scr_sedo.cpp` source module. The merge keeps the delete, open, panel-change,
cleanup, and return paths.

The natural-source pass removes the `OFSTRUCT` buffer overlay and `+4` stack
shaping. It uses independent arrays, direct list calls, and a typed game cast.
The natural body keeps all 38 ordered calls and its owner boundary. It rebuilds
to 997 bytes against the original 1003 bytes, with 569 differing bytes.

The candidate reports zero boundary escapes and zero relocation target
mismatches. The larger codegen drift remains scratch because a later behavior
review must check overflow and fault-order effects from the independent arrays.
