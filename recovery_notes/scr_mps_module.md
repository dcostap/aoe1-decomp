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
- The registered exact owners remain the natural owners that still match after
  provider cleanup. The scratch and accepted-drift owners are not exact-owner
  claims.

## Evidence and validation

The plan packet reports 34 normal owners and 24,639 normal bytes. The natural
provider candidate registers 24 exact owners. The address sequence and PDB line
ranges establish source order.

Migration is structural. The old grouped wrapper was the pre-migration validation baseline. The natural provider candidate compiles all 34 owners in one TU. The 24 registered owners report `MATCH`, `0.0000%`, zero relocation mismatches, and zero boundary escapes.

The ten unregistered owners remain observed, not exact claims. Natural cleanup
changed the five former exact owners as follows: `004A1300` 853 bytes,
`004A2910` 38 bytes, `004A4190` 2 bytes, `004A6050` 106 bytes, and `004A6290`
43 bytes. The existing scratch and accepted-drift results remain recorded.
Do not change recovered behavior to hide these results.

## Natural source cleanup

The compiler-facing source keeps typed fields, literals, canonical calls, and
ordinary `new` and `delete` expressions. It has no pointer-offset overlay,
manual deallocation, absolute string address, source-shape tuning log, or stack
home reconstruction note. The removed tuning history remains in the earlier
recovery records and is not part of the source contract.

## Format literals

The original image proves every former `CSTR` value. At `00584610`, the bytes are `25 64 00`, or `"%d"`. At `00586114`, they are `"%s%s.scn"`. At `00586838` and `00586840`, they are `"%s.scn"` and `"%s.scx"`. At `00586C0C`, `00586C18`, and `00586C20`, the bytes decode to `"%s 2 - 8"`, `"%s %d"`, and `"%s %d - %d"`. The module now uses these natural literals at each former use.

## Open blockers

- The requested Terra contract file was absent from this worktree at `build/source_reunification/terra_system/orchestrator_contract.md`; an equivalent contract was read from the sibling Terra checkout.
- The two scratch owners (`004A00B0`, `004A16E0`) remain unresolved.
- The three accepted-drift owners retain their reviewed localized drift: `004A2060`, `004A27A0`, and `004A2D50`.
