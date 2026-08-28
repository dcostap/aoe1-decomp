# scr_name.cpp source composition

## PDB plan

The packet for `C:\\msdev\\work\\age1_x1\\scr_name.cpp` identifies 11
normal owners in source order:

`004A63D0`, `004A66E0`, `004A67C0`, `004A6800`, `004A68C0`, `004A6980`,
`004A69B0`, `004A6D50`, `004A6F60`, `004A6FF0`, and `004A71D0`.

The source-line bands are 50-96, 102-114, 120-130, 136-163, 169-197,
204-219, 225-322, 329-361, 367-373, 379-423, and 429-440. The screen owns
the first seven bodies. The dialog owns the last four bodies. `004A66C0` and
`004A6F40` are compiler-generated deleting destructors.

The constructor, screen action, dialog constructor, dialog action, and both
generated destructors are exact anchors. The module uses
`config/flags/scr_name.rsp` with `/O2 /Oy /GX`.

## Canonical ownership

`include/scr_name.h` owns only `TRIBE_Screen_Name` and `TRIBE_Dialog_Name`.
It consumes the canonical `Pnl_scr.h` and `pnl_dlg.h` bases. It no longer
redeclares `TPanel`, `TEasy_Panel`, `TScreenPanel`, `TDialogPanel`,
`RGE_Game_Info`, or `RGE_Base_Game`. It has no copied foreign screen layout.
The owner-only `include/scr_cams.h` surface supplies the complete campaign
selection type needed by the two natural allocation expressions.

`src/scr_name.cpp` privately includes the canonical panel, screen, child-panel,
game-info, Base Game, global, campaign-selection, and single-player screen
providers. It uses the canonical `error_code`, `sorted`, and
`TPanel::PositionRightTop` fields and enum. Cleanup uses natural `delete`
expressions for derived-panel fields. The source keeps all 11 handwritten
bodies in PDB order. It has no wrapper, fragment
include, context macro, fallback declaration, raw vptr, inline assembly, raw
address, or private-symbol alias.

## Status and validation

Eight normal owners remain `matching`. The two destructors and
`004A6D50 TRIBE_Dialog_Name` are honest `accepted_drift` owners. The
source-module manifest records these statuses.

The grouped provider candidate is
`build/candidate_tus/scr_name_natural_delete_cleanup3/report.json`. It compiled the canonical
source and reports `MATCH` and `0.0000%` for all eight matching owners. The two
compiler-generated deleting destructors also report `MATCH` and `0.0000%`, with
zero boundary errors. The two natural-delete destructors report accepted drift
with matching ownership and zero relocation errors. The accepted-drift
constructor remains an 86-byte mismatch with matching ownership and zero
relocation and boundary errors.

The candidate proposal is `build/scr_name_natural_proposal.json`. It does not
change global translation-unit registration. The direct source is registered
with the accepted-drift constructor and destructors.

## Consumer handoff

The campaign-selection consumer now includes `scr_name.h` without a copied
hierarchy. Its complete natural source uses the canonical Panel, screen,
Base Game, game-info, campaign, game, communications, and scenario providers.
The direct consumer validation is recorded in
`recovery_notes/scr_cams_module.md`.
