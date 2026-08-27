# 004B3740 `TRIBE_Screen_Sed_Open::fillList`

- PDB source: `scr_sedo.cpp`, lines 116 to 149.
- Source module: `src/scr_sedo.cpp`.
- Original size: 352 bytes.
- Recovery state before migration: matching.

The function clears and sorts the list. It scans `.scn` files, then `.scx`
files. It removes the first four characters and the four-character suffix
before it appends each name.

The body moved from the matching bank into the complete `scr_sedo.cpp`
source module. The former standalone result matched 352 bytes. The current
focused check reports a four-byte mismatch from the natural `_finddata_t`
declaration in the migrated source. This migration does not tune that output.
