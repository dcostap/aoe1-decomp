# tvictory.cpp source reunification

## Context

- PDB source: `C:\\msdev\\work\\age1_x1\\tvictory.cpp`.
- Source lines run from 30 through 83.
- The module owns six normal functions in this address and source order:
  `0052C8F0`, `0052C920`, `0052C940`, `0052C950`, `0052C970`, and `0052C9B0`.
- All six owners belong to `TRIBE_Victory_Conditions`.
- The packet lists no nearby compiler-generated owner.

The constructor calls at `0052C8F0` and `0052C920` anchor the derived class to
its two base constructors. The destructor at `0052C940` restores the derived
vtable and tail-jumps to the base destructor. `0052C950` keeps the base handler
call and the local `handle_tech` call. `0052C970` reads the player technology
pointer at `+0x220` and calls `get_tech_state`. `0052C9B0` calls the base `add`
owner and stores command `0x64` and the requested technology count.

## Migration

`src/tvictory.cpp` now owns all six bodies in PDB order. `include/tvictory.h`
contains the module-local declaration surface. The old wrapper,
`include/tvictory_context.h`, and six source-bank fragments were removed. The
source has no owner `.cpp` includes, context macro, fallback declaration block,
manual vtable field, inline assembly, or raw address expression.

The source keeps the reviewed typed `RGE_Victory_Conditions` base, player layout,
technology-tree member, and virtual handler surface. The nonvirtual derived
QAE destructor declaration remains because the PDB owner is the nonvirtual
wrapper that restores the derived vtable before the base tail jump.

`config/source_modules/tvictory.json` records all six matching owners. The
registered translation-unit entry maps every owner directly to `src/tvictory.cpp`
and uses the `tvictory` module name.

## Validation

The one constrained candidate translation-unit check used:

`python tools/validate_candidate_tu.py --proposal build/candidate_tus/tvictory_migration.json --output-dir build/candidate_tus/tvictory_migration`

The direct source compiled all six normal owners. Every row reported `MATCH`
with zero byte differences, zero relocation target mismatches, and zero
boundary escapes. The candidate reported a fully exact module.

Three allowed cached focused checks used `--no-build --no-history` for
`0052C8F0`, `0052C950`, and `0052C9B0`. Each cache was missing or stale after
the direct source move. No focused rebuild ran.

## Open questions

The module uses the reviewed declarations in `include/victory_context.h` for the
shared victory ABI. Revisit that shared surface only with new cross-module
binary evidence.
