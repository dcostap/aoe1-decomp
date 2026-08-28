# scr_trb.cpp source-module recovery

## Context

- PDB source: `C:\\msdev\\work\\age1_x1\\scr_trb.cpp`.
- PDB source-order bands are 37-157, 162-172, 178-197, 202-233, and 238-261.
- The address sequence is `004B75A0`, `004B7DF0`, `004B7EE0`, `004B7F70`, and `004B8070`.
- The class owner is `TribeSelectTribeScreen`. The generated scalar-deleting destructor at `004B7DD0` has no normal source body.
- `include/scr_trb.h` owns only `TribeSelectTribeScreen` and uses the canonical `TScreenPanel` base.
- The constructor's concrete panel and game dependencies come from `Pnl_btn.h`, `pnl_lst.h`, `pnl_pic.h`, and `basegame.h`.
- Exact anchors are the constructor's `TScreenPanel` base call and panel setup calls, the destructor's panel deletes, the action call targets, the text virtual slots, and the fixed tribe-name string addresses.

## Dependency map

- `TribeSelectTribeScreen` owns `background`, `title`, `tribeText`, nine `tribeButton` entries, `okButton`, `cancelButton`, `screenText`, and `numLines`.
- `TPanel`, `TEasy_Panel`, and `TScreenPanel` come from the canonical panel chain. `TPicturePanel`, `TTextPanel`, and `TButtonPanel` come from their published owners.
- `RGE_Base_Game`, `RGE_Font`, `TDigital`, and the canonical `TPanelSystem` declaration provide the observed game and panel calls.
- The constructor calls `tribeName` and `fillTribeText`; `action` calls `fillTribeText`; the generated deleting destructor is compiler-owned.

## Migration

- The five bodies now live in `src/scr_trb.cpp` in PDB source order.
- `include/scr_trb.h` is the owner-only canonical declaration header.
- The old wrapper `src/scr_trb_tu.cpp` and five per-function source-bank files are obsolete after grouped proof.
- No context header remains for this module.
- The module manifest is `config/source_modules/scr_trb.json`.
- Matching status is unchanged for all five normal owners.

## Validation

- The plan packet reports five normal owners, 2,758 normal bytes, and five registered exact owners before migration.
- The grouped candidate uses `config/flags/004B75A0_TribeSelectTribeScreen.rsp` (`/nologo /c /O2 /Oy /GX`).
- Require `MATCH`, `0.0000%`, correct ownership, boundaries, relocations, and direct targets for all five owners.

## Open hold

- `action` uses the published `panel_system` declaration from `panel.h`, not a local fixed-address declaration.
- `tribeName` retains fixed addresses because the direct assembly names each target as the required static string (`s_Assyrian` through `s_No_Culture`). No canonical string declaration is available.
