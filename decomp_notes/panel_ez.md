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

`004675C0 draw_background` now has an exact source candidate.
The reopened baseline was 979 bytes with 83 positional differences.
The target and candidate now match all 979 bytes, all 20 calls, the frame, owner, and boundary.
The source uses long `pic_x` and `pic_y` locals after signed-short conversion.
See `decomp_notes/functions/0046/004675C0.md` for the behavior review and saved states.

The final one-job `panel_ez` audit compiled 76 normal functions.
It found 74 exact matching results and no exact-neighbor regressions.
`00466A90 setup` remains an existing `new_verified_logic` mismatch at 1,031 bytes.
The audit report is `build/drift-061-Panel_ez/final-20260928/report.txt`.

`00468000 set_popup_info_file` is now an exact match. Moving the
`popup_info_id` assignment after the filename `if/else` matches the original PDB
line mapping and the exact `set_info_file` donor. The fresh target result is
85/85 bytes equal, and the one-job translation-unit closure reports no exact-
neighbor regressions.

## Nested format enums

The original `create_input` and `create_edit` symbols use nested `FormatType`
enums. A full class-visible repair makes both bodies exact.

VC5 cannot name either nested enum from an incomplete class. `panel_ez.h` now
includes the two owning class headers and uses each nested enum directly.

The integrated source makes `00469000` and `004691C0` exact. It also keeps
`00467380` exact in the current canonical context. Do not use a symbol alias,
copied class, context macro, or wrong integer owner.
