# spanlist.cpp module migration

The module now owns all 29 normal PDB functions in source order.

Twenty-two functions remain exact owners. The composed grouped build reported
`MATCH` and zero byte drift for each exact owner.

The current nonexact results include:

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

The migration removes the source-bank fragments and the wrapper. `drawarea.h`
owns the shared span declarations. `spanlist.h` consumes the canonical
Drawarea and Shape headers. The composed fanout retained 48/48 Drawarea and
22/22 spanlist exact owners. Shape retained 10/11 checked owners;
`004BAAF0` remains scratch for its documented two-byte difference.
