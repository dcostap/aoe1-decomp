# rmm_terr.cpp module merge

- PDB source: `C:\\msdev\\work\\age1_x1\\rmm_terr.cpp`.
- Source: `src/rmm_terr.cpp`.
- Header: `include/rmm_terr.h`.
- Flags: `config/flags/default.rsp`.

## Transition

The module has 11 normal owners in PDB order from `004888E0` through
`00489030`.

The merged source owns all 11 bodies. It removes the wrapper, per-function
`.cpp` includes, fallback class declarations, and context-only source shape.
The header now has the natural module name `rmm_terr.h`.

The module manifest records nine matching owners. The former accepted-drift
owner `00488B90` (`check_terrain`) and former matching owner `00488E60`
(`count_map_tiles`) are now scratch. The old grouped registration had nine
exact owners. This merge does not promote either owner.

## Check state

The migration preserves the reviewed function bodies and behavior. It does not
perform byte tuning during source-shape migration. The complete merged source
compiles with the pinned VC5 toolchain.

The nine matching owners check as `MATCH` with `0.0000%` positional difference
through the merged source. The `check_terrain` owner remains a `MISMATCH`: the
merged body emits 433 bytes against the 437-byte original, with 295 changed
bytes. The `count_map_tiles` owner also mismatches by two bytes. These are
source-shape context results, not behavior changes.

The translation-unit validator passes. The source-module and translation-unit
tests pass with 16 tests passed and two skipped.

The `check_terrain` note remains attached to this module because its two clipped
inclusive scans and terrain predicate order are reviewed. It is now scratch.
The fresh grouped result in `build/audit_accepted_drift_final2/report.txt`
reports 433 rebuilt bytes against 437 original bytes
and 295 differing bytes. The frame, owner symbol, and boundaries match, but
the checker reports structural control-flow drift beyond a localized change.
