# spanlist.cpp module migration

The module now owns all 29 normal PDB functions in source order.

Twenty-three functions remain exact owners. The focused grouped build before
migration reported `MATCH` and zero byte drift for each exact owner.

Five functions remain accepted drift. Their current focused results are:

- `004BDEA0 AddShape`: current source-bank result needs a typed selected-shape
  walk. The migration keeps its accepted source shape.
- `004BE090 AddLine_Align`: 184 differing bytes in the focused grouped build.
  The five AddSpan calls and loop behavior remain aligned.
- `004BE1F0 AddMiniList`: scratch. The old source swapped its span fields.
  The repaired source uses Y_delta as the sentinel and calls AddSpan with
  X_start, X_end, and Y_delta in that order.
- `004BEAD0 DecodeLine`: 12 differing bytes in the focused grouped build.
  The node walk, byte updates, and count behavior remain aligned.
- `004BEB10 take_snapshot`: 351 differing bytes in the focused grouped build.
  The file, palette, scanline, overlay, and cleanup behavior remain aligned.

The natural module build adds a temporary three-byte register-color drift to
`004BE4B0 DeleteShape`. Its size, control flow, calls, and all other bytes
remain aligned. It stays accepted drift. The prior exact-owner claim is removed.

`004BDB00 AddSpan` remains scratch. The current source is a natural typed
reconstruction. The focused grouped build reports 589 differing bytes and a
922-byte rebuild against the 916-byte original.

The migration removes the source-bank fragments and the wrapper. The public
header owns span declarations only. Shape and Drawarea views stay private.
