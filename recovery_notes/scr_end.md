# scr_end.cpp source recovery

## Source context

- PDB source: `C:\msdev\work\age1_x1\scr_end.cpp`.
- Direct source: `src/scr_end.cpp`.
- Owner header: `include/scr_end.h`.
- Flags: `config/flags/004936D0_TribeEndScreen.rsp`.

The PDB owns three normal functions in this order:

- `004936D0` `TribeEndScreen::TribeEndScreen`, lines 34 to 116.
- `00493C00` `TribeEndScreen::~TribeEndScreen`, lines 121 to 126.
- `00493C90` `TribeEndScreen::action`, lines 132 to 143.

`00493BE0` is the compiler-generated scalar deleting destructor. It has no
source body.

## Canonical providers

`include/Pnl_scr.h` provides `TScreenPanel`. `include/panel.h` provides
`TPanel`, `TPanelSystem`, `panel_system`, and panel fields.

`include/pnl_pic.h`, `include/pnl_lst.h`, and `include/pnl_btn.h` provide the
three child panel types. `include/basegame.h` and
`include/rge_base_game_global.h` provide the Base Game surface and global.

The type record gives `TribeEndScreen` a `TScreenPanel` base, four child
fields, and size `0x488`. It gives `TribeAchievementsScreen` size `0x5F8` and
its complete field list.

`scr_ach.h` still has an older copied panel surface. It cannot share a source
unit with canonical panel headers. `scr_end.h` therefore has a narrow typed
construction declaration for `TribeAchievementsScreen`. It uses only PDB type
record fields and method declarations. It defines no method or manual vtable.

## Exact finish

The first direct source matched all normal bodies and the generated destructor.
It has no wrapper, context header, source fragment, raw field store, or
absolute string address.

The direct source uses `TDrawArea::Width`, `pnl_wid`, and `pnl_hgt`. These are
the canonical names for the proven offsets.

Raw integer arguments do not compile against canonical enum parameters. The
source keeps `PositionCentered`, `AlignCenter`, `DrawPicture`, and
`NotifyAction`.

`new TribeAchievementsScreen` matches without a local `operator_new`
declaration. The old declaration was not required.

## Validation

`python tools/validate_candidate_tu.py --proposal
build/candidate_tus/scr_end_natural/proposal.json` reports three normal
`MATCH` rows and one generated `MATCH` row. Every row has zero differing bytes,
no relocation-target mismatch, and no boundary escape.
