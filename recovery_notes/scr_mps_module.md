# scr_mps.cpp source-module recovery

## Context

- PDB source: `C:\\msdev\\work\\age1_x1\\scr_mps.cpp`.
- PDB order is the address order from `004A00B0` through `004A63C0`.
- The module has 34 normal owners and three nearby compiler-generated deleting destructors.
- The class owners are `TribeMPSetupScreen`, `TRIBE_Screen_Wait`, and `TRIBE_Screen_Disconnect`.
- `include/scr_mps.h` owns the complete declaration surface. `include/scr_set_screen.h` remains the shared settings-screen declaration.
- The former wrapper used `SCR_MPS_TU_CONTEXT` to suppress local declarations. The migrated source has one compiler-facing owner and no context macro.

## Migration

- The 34 bodies now live in `src/scr_mps.cpp` in PDB source order.
- The old wrapper `src/scr_mps_tu.cpp` and all 34 source-bank fragments were removed.
- The obsolete unregistered `src/screen_disconnect_tu.cpp` wrapper was also removed; it included two owners now owned by this module.
- The old module context header `include/scr_mps_context.h` was replaced by `include/scr_mps.h`.
- `config/source_modules/scr_mps.json` records all 34 normal owners and this note.
- The registered exact owners remain the 29 owners that were exact before migration. The two scratch owners and three accepted-drift owners are not exact-owner claims.

## Evidence and validation

The plan packet reports 34 normal owners, 24,639 normal bytes, and 29 registered exact owners. The address sequence and PDB line ranges establish source order. The constructor and method declarations in `scr_mps.h` preserve the class and field layouts used by the prior grouped checks.

Migration is structural. The old grouped wrapper was the pre-migration validation baseline. The merged object audit compiled all 34 owners in one TU. All 29 registered owners still report `MATCH`, `0.0000%`, zero relocation mismatches, and zero boundary escapes.

The five unregistered owners remain observed, not exact claims. Their merged-TU results are: `004A00B0` 1,478 differing bytes; `004A16E0` 2,215 differing bytes with two relocation-target mismatches and two boundary escapes; `004A2060` 69 differing bytes; `004A27A0` 1 differing byte; and `004A2D50` 344 differing bytes with two relocation-target mismatches. These are recorded regressions or unresolved results, not hidden by source changes. Do not change recovered behavior to hide them.

## Open blockers

- The requested Terra contract file was absent from this worktree at `build/source_reunification/terra_system/orchestrator_contract.md`; an equivalent contract was read from the sibling Terra checkout.
- The two scratch owners (`004A00B0`, `004A16E0`) remain unresolved.
- The three accepted-drift owners retain their reviewed localized drift: `004A2060`, `004A27A0`, and `004A2D50`.
