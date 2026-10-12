# dlg_menu.cpp source recovery

The PDB module is `C:\\msdev\\work\\age1_x1\\dlg_menu.cpp`. It owns three
normal `TribeMenuDialog` methods in this order:

1. `0043F340` constructor, lines 74-142, 838 bytes;
2. `0043F6B0` destructor, lines 148-153, 103 bytes; and
3. `0043F720` action, lines 159-326, 1,349 bytes.

The normal bodies total 2,290 bytes. The scalar deleting destructor at
`0043F690` is compiler generated. Its VC5 weak vector-destructor symbol is
`??_ETribeMenuDialog@@UAEPAXI@Z`.

## Context and ownership

The PDB source module, line bands, class ownership, address order, and exact
anchors are proved by the packet and original listing. The button setup,
count-down child deletion, and ordered action dispatch link each body to this
module.

`include/dlg_menu.h` owns only `TribeMenuDialog`. It uses the canonical
`pnl_dlg.h`, `Pnl_scr.h`, and `pnl_btn.h` providers. The source uses canonical
Panel, Base Game, Player, World, Scenario, and foreign screen owners. It has no
foreign class declaration, explicit layout, wrapper, fragment include, context
macro, manual vtable, or absolute address.

The source uses canonical `scr_save.h`, `scr_ach.h`, and `scr_vc.h` providers.
The canonical `dlg_conf.h` and `dlg_abt.h` providers supply the other dialog
owners. The source uses the real enum values and dialog-name string literals.

## Migration

`src/dlg_menu.cpp` contains all three normal bodies in PDB order. The old
`src/dlg_menu_tu.cpp` wrapper, `include/dlg_menu_context.h`, and three matching
fragments are removed. `config/functions/src/dlg_menu.cpp.json` records all
three functions and their status.

## Validation

The typed-array candidate compiles the direct source with
`config/flags/gx.rsp`. The constructor and destructor
remain semantically equivalent, but their source-safe array forms produce
broad codegen drift:

- `0043F340`: 776 differing bytes, 860 rebuilt bytes, and 2 boundary escapes;
- `0043F6B0`: 96 differing bytes, 121 rebuilt bytes, and 1 boundary escape;
- `0043F720`: `MATCH`, 1,349 bytes, zero relocations and boundary escapes.

The generated `0043F690` owner still reports `MATCH`, zero positional
difference, and zero relocations. The constructor and destructor are marked
`scratch`; the action remains `matching`.

The final source builds a local `TPanel* tab_order[11]` before calling
`set_tab_order`. Its destructor copies each `TButtonPanel*` to a typed
`TPanel*`, deletes through `delete_panel(&panel)`, and clears the button slot.
It uses no pointer-array type punning, C-style cast, or `goto`. The generated
`dlg_menu.i` listing is under ignored `build/`, not the repository root.

The final source keeps canonical enum and string types. It does not use the
integer or absolute-address forms from the earlier local matching fragments.
