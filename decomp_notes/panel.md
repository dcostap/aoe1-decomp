# `Panel.cpp` source migration

## Ownership

- PDB source: `C:\\msdev\\work\\age1_x1\\Panel.cpp`
- Source order follows the 117 normal owners from `$E1` through
  `TPanel::get_true_render_rect`.
- The scalar deleting destructor at `00464890` is compiler generated.
- All normal owners now have one compiler-facing source owner in
  `src/Panel.cpp`.

## Source model

- `include/panel.h` is the module header.
- The source uses direct function definitions in PDB order.
- The old wrapper, per-function source fragments, fallback class declarations,
  and context guard macros are removed.
- The Panel and PanelSystem layouts use named fields with measured offsets.
- The source keeps accepted-drift and scratch bodies in place. Their status is
  recorded in `config/functions/src/Panel.cpp.json`.

## Translation-unit context

- PDB module: `C:\\msdev\\work\\age1_x1\\Panel.cpp`.
- Source lines run from 31 through 2612, in ascending owner order.
- The owner sequence starts with the PanelSystem initializer, then PanelSystem
  methods, then TPanel constructors and methods.
- The class anchors are `TPanelSystem` at `00463BE0` and `TPanel` at `00464720`.
- The compiler-generated scalar deleting destructor at `00464890` is outside
  the normal owner set and remains unlisted in the source module.

## Current status

The migration is structural. It does not claim new exact results. Matching
owners keep their previous status until the registered grouped check runs on
the direct source. Accepted-drift owners remain localized and scratch owners
remain unresolved.

Known unresolved owners are:

- `00463BB0 $E1`
- `00464720 TPanel(char*)` (scratch after direct-module validation)
- `004648B0 TPanel()` (scratch after direct-module validation)
- `004642C0 get_palette` (accepted drift)
- `00464F20 set_overlapped_redraw` (accepted drift)
- `004653E0 wnd_proc`
- `00465820 handle_size`
- `00465A70 handle_paint` (accepted drift)
- `00465DC0 handle_mouse_move` (accepted drift)

The merged module does not emit the prior exact symbols for `00464150 setup`,
`004641B0 findPanelNode`, or `00464260 setCurrentPanel`. The direct entry and
module metadata now mark these owners as scratch. This preserves the natural
module source rather than retaining unsupported declaration machinery.

The direct module source was compiled as a syntax and layout check. Full
registered validation is required after this migration.

## Compile-blocker repair

`debug_timeGetTime` uses the canonical C++ declaration from `basegame.h`.
The full direct-module candidate build now compiles without diagnostics. Of
the 105 configured exact owners, 104 report `MATCH`, `0.0000%`, correct
ownership, relocations, and boundaries. `004666C0` remains a known three-byte
codegen mismatch; this repair does not change its source or status.
