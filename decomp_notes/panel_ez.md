# Panel_ez.cpp owner composition

## Context

- PDB source: `C:\\msdev\\work\\age1_x1\\Panel_ez.cpp`.
- `TEasy_Panel` owns 76 normal bodies in PDB order.
- The source bands span lines 44 through 2013.
- `00466A70` is a generated scalar deleting destructor.

## Ownership

`include/panel_ez.h` owns only `TEasy_Panel`.
The source includes canonical panel, drawing, shape, color, control, mouse, and
dialog owners. No wrapper, context macro, copied foreign class, raw field
cursor, manual vtable, or inline assembly remains.

The PDB virtual order is retained. The button overloads are long then character.
The text overloads are integer, character-array, then character.

The two checkbox strings are module-local literals. Original data contains the
bytes for `" "` at `00580460` and `"X"` at `00583B74`.

## Validation

The natural direct source compiles after the BaseGame owner published its cursor
methods. Focused checks match `00466A20` and `0046A410` exactly.

Final grouped validation records explicit symbols for two overloaded selections.
`00467A70` selects `set_background(char *, long)`.
`00468530` selects the character-text `create_button` overload.

VC5 emits each overloaded virtual group in reverse declaration order. The
header now declares each group in reverse vtable order. This produces the
binary-proven slots without casts or call-site changes.

The numeric button wrapper at `00468490` now calls slot `+0xEC` and matches.
The integer text wrapper at `00468C20` now calls slot `+0x100` and matches.
The character and array overloads remain in their proven slots.

`004675C0 draw_background` remains accepted drift. Its fresh check differs by
756 positional bytes but only 169 raw edit-cost bytes. The frame, 20 calls,
CFG, owner symbol, relocations, and boundary all match. The low-severity
diagnostic identifies private center-coordinate scheduling, matching the
written behavior review. The natural body remains unchanged.

`00468000 set_popup_info_file` remains accepted drift. Its fresh grouped result
differs by two bytes with matching ownership, relocation, and boundary checks.
Exact repair resumes from this canonical source tree.
