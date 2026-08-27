# 004B38A0 `TRIBE_Screen_Sed_Open::action`

- PDB source: `scr_sedo.cpp`, lines 155 to 245.
- Source module: `src/scr_sedo.cpp`.
- Original size: 1003 bytes.
- Recovery state: accepted drift.

## Migration record

The action body moved from the accepted-drift bank into the complete
`scr_sedo.cpp` source module. The merge keeps the delete, open, panel-change,
cleanup, and return paths.

The former source kept the 1003-byte owner boundary and all 38 ordered calls.
The grouped module build reports a temporary mismatch during this structural
migration. This change did not tune bytes or reopen the accepted drift.
