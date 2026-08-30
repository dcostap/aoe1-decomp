# Pnl_drop.cpp source module

- PDB source: `C:\\msdev\\work\\age1_x1\\Pnl_drop.cpp`.
- Source: `src/Pnl_drop.cpp`.
- Header: `include/pnl_drop.h`.
- Manifest: `config/functions/src/Pnl_drop.cpp.json`.

## Source ownership

The source owns 40 normal PDB owners in source order:

`00473ED0`, `00473F50`, `00473FD0`, `00474340`, `00474350`, `00474400`,
`00474420`, `00474450`, `004744A0`, `00474550`, `004745E0`, `00474600`,
`00474630`, `00474670`, `00474820`, `00474880`, `00475110`, `00475130`,
`00475150`, `00475160`, `004751C0`, `004751E0`, `00475210`, `00475230`,
`00475250`, `004752A0`, `004752D0`, `00475300`, `00475330`, `00475360`,
`00475380`, `004753A0`, `004753C0`, `004753E0`, `00475400`, `00475420`,
`00475440`, `00475460`, `00475470`, `004754C0`.

The source owns `TDropDownPanel` and `TDropDownButtonPanel`. The scalar
and vector deleting destructors at `00473F30` and `00475490` are compiler
generated. They are not normal source owners.

The manifest keeps 37 matching owners, two scratch owners, and one
accepted-drift owner:

- Scratch: `00473FD0` (`setup`) and `00474880` (`set_mode`).
- Accepted drift: `004754C0` (`TDropDownButtonPanel::handle_mouse_move`).
- Matching: the other 37 normal owners.

## Header composition

`include/pnl_drop.h` now includes the canonical `panel.h`, `drawarea.h`,
`Shape.h`, `pnl_lst.h`, and the `pnl_btn.h` owner. It declares only the two
PDB-owned Pnl_drop classes. It declares no panel, draw-area, shape, button,
list, scrollbar, Windows, or vtable copy. The source includes the canonical
`Pnl_scbr.h` owner for the complete scrollbar surface used by its allocation
and method calls.

`TDropDownPanel` uses the canonical `TPanel`, `TTextPanel`, and `TListPanel`
surfaces. `TDropDownButtonPanel` uses the canonical `TButtonPanel` surface.
The header keeps `TScrollBarPanel` forward-only because Pnl_drop exposes only a
pointer. Its implementation includes the complete owner header.

The source now names canonical nested enums for text alignment, panel
positioning, and redraw modes. These changes do not change their values or
the source behavior.
The unnamed `s_` declaration moved to `src/Pnl_drop.cpp` because it is not a
Pnl_drop class or record.

## Canonical dependency completion

`pnl_btn.h` and `Pnl_scbr.h` now publish canonical owner declarations. The
Pnl_drop source uses those owners directly. No copied layout or fallback
declaration remains in this module.

## Canonical dependency fanout

`pnl_lst.h` is already repaired. It owns `TTextPanel` and `TListPanel`, and it
consumes `panel.h`, `drawarea.h`, and `Shape.h`. Pnl_drop uses those surfaces
for list allocation, text updates, line helpers, and list layout.

The Pnl_drop classes have pointer fanout in `include/panel_ez.h`,
`include/pnl_dlg.h`, the dialog headers, and the screen headers. Their source
consumers include `Panel_ez.cpp`, `Pnl_scr.cpp`, `dlg_abt.cpp`, `dlg_dip.cpp`,
`dlg_smsg.cpp`, `scr_cam.cpp`, `scr_cams.cpp`, `scr_game.cpp`, `scr_mps.cpp`,
`scr_save.cpp`, `scr_sed.cpp`, `scr_sed2.cpp`, and `scr_set.cpp`. Those headers
remain outside this module task.

## Validation

The grouped candidate command was:

`python tools/validate_candidate_tu.py --proposal build/candidate_tus/pnl_drop_wrapper/proposal.json`

The candidate compiled. Both compiler-generated deleting destructors matched.
Thirty-six of 37 exact owners matched. `004751E0` differed by one byte. The
known scratch owners differed by 162 bytes (`00473FD0`) and 875 bytes
(`00474880`); the latter had one boundary escape. The accepted-drift owner
`004754C0` differed by 15 bytes. All reported relocation target mismatches were
zero.

The remaining exact-owner difference is a temporary translation-unit context
regression after canonical dependency composition. Keep the natural source and
recheck it after the dependent panel owners settle.
