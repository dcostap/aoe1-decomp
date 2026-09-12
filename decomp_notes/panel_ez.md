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

`004675C0 draw_background` remains accepted drift. The fresh check is 979
original bytes versus 977 rebuilt bytes, with 762 positional differences and
194 raw edit-cost bytes. The frame, 20-call sequence, CFG counts, owner symbol,
relocations, and boundary all match. The first structural difference is the
centered shadow-area block at `00467686` versus rebuilt `00467686`. The target
block has 32 instructions and 74 bytes. The rebuilt block has 31 instructions
and 72 bytes. The later centered picture block has the same two-byte shift.
The edit/resync comparison reports 825 equal bytes, 194 raw edit cost, 9.92%
bounded edit cost, and 84.27% similarity. Exact-block coverage is 80.45%, with
the longest aligned run at 158 instructions. The remaining differences are
register allocation and branch displacement within this two-byte shift.

The complete behavior trace was rechecked against the original assembly. The
function calls `draw_setup(0)`, then clears the panel clip only for the
`need_redraw == 2` alternate shadow path. It copies the shadow area at the
panel origin, centered position, or tiled positions. Invalid shadow positions
skip the copy and continue to bevel handling. Without a shadow area it selects
the alternate picture when available, and falls back to the primary picture.
It clears the panel clip when redraw is required or the picture is null. A null
picture then skips locking and drawing.

On a successful lock, `shape_minmax` writes four long locals. Position 1 draws
one centered shape and can draw a picture-sized shadow box. Position 2 draws
the shape from `(0, 0)` across the panel and can draw a panel-sized shadow box.
The default draws one shape at the panel origin and can draw a shape-sized
shadow box. The target uses signed division by two and short centered
coordinates. The natural source preserves this with `short` locals. It also
preserves the target loop tests, inclusive limits, output-pointer ranges,
shadow-table calls, and argument order.

The call map aligns all 20 calls. It pairs the three shadow copies at `+0xA6`,
`+0x106`, and `+0x120`, the three shape draws at `+0x1F6`, `+0x265`, and
`+0x307`, the three shadow-table calls at `+0x219`, `+0x29E`, and `+0x322`,
and the centered shadow box at `+0x33A`. Lock, unlock, bevel, setup, and finish
calls also retain their target order.

The lock succeeds before `shape_minmax` and every shape or shadow-table call.
The target does not unlock after a failed lock; the source preserves that
failure path and cleanup order. A successful picture path unlocks before bevel
handling.
The bevel path locks, draws the full panel rectangle with six color bytes, and
unlocks only after a successful lock. `draw_finish` always runs after the
bevel path. `draw_setup` sets the render clip before drawing and `draw_finish`
resets it. Clear uses `clip_rect`; draw and copy calls use the render area's
clip state. No explicit clipping or cleanup difference was found.

The target writes the vtable home at `[esp+0x2C]` before `draw_setup`, stores
the shadow height or selected picture in the same local homes as the source,
and passes four distinct long-local addresses to `shape_minmax`. The target's
centered shape path writes its y spill at `[esp+0x2C]` after six argument
pushes. The rebuilt path writes `[esp+0x20]` before those pushes. Both writes
resolve to the same entry-relative stack slot and occur before `shape_draw`.
No write reaches the return address or another output local.

Memory faults from `draw_setup`, `Clear`, `Lock`, `shape_minmax`, each draw,
shadow-table, shadow-box, bevel, unlock, and finish call retain their target
order. The centered blocks reorder only fixed-offset scalar reads from the
same live `this` object. They reorder no pointer dereference or side-effecting
call. The source therefore retains the target pointer-fault order and all
normal cleanup boundaries.

Natural variants tested in the private `variant_lab` runs changed centered
coordinate declaration order, arithmetic order, dimension type, and a named
picture-y local. All 392 compilable variants missed the target. The best group
remained 977 bytes with 187 edit-cost bytes; the named local added four or more
bytes and did not recover the target. No source change is retained.

The final one-job `panel_ez` closure audit compiled 76 normal functions. It
reported 74 matching results, held this accepted drift, and found no changed
matching neighbor. Existing scratch `00466A90 setup` remains a separate
grouped mismatch.

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
