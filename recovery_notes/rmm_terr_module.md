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

The module manifest records ten matching owners and the reviewed accepted-drift
owner `00488B90` (`check_terrain`). The old grouped registration had nine exact
owners. `count_map_tiles` and `check_terrain` were not registered in that
prefix group. This merge does not promote either owner.

## Check state

The migration preserves the reviewed function bodies and behavior. It does not
perform byte tuning during source-shape migration. The complete merged source
compiles with the pinned VC5 toolchain.

The ten matching owners check as `MATCH` with `0.0000%` positional difference
through the merged source. The accepted-drift `check_terrain` owner remains a
`MISMATCH`: the merged body emits 433 bytes against the 437-byte original, with
295 changed bytes. This is a source-shape context result, not a behavior change.

The translation-unit validator passes. The source-module and translation-unit
tests pass with 16 tests passed and two skipped.

The `check_terrain` note remains attached to this module because its two clipped
inclusive scans and terrain predicate order are reviewed, but its private local
homes still differ from the executable.
