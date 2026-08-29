# spanlist.cpp module migration

The module now owns all 29 normal PDB functions in source order.

Twenty-three functions are exact owners. The composed grouped build reported
`MATCH` and zero byte drift for each exact owner.

The current nonexact results include:

- `004BDEA0 AddShape`: current source-bank result needs a typed selected-shape
  walk. The migration keeps its accepted source shape.
- `004BE090 AddLine_Align`: scratch after the fresh grouped build reported 184
  differing bytes and one boundary escape.
  The five AddSpan calls and loop behavior remain aligned.
- `004BE1F0 AddMiniList`: scratch. The old source swapped its span fields.
  The repaired source uses Y_delta as the sentinel and calls AddSpan with
  X_start, X_end, and Y_delta in that order.
- `004BEAD0 DecodeLine`: 12 differing bytes in the focused grouped build.
  The node walk, byte updates, and count behavior remain aligned.
- `004BEB10 take_snapshot`: scratch after the fresh grouped build reported 351
  differing bytes. Its calls and frame match, but its return and block shape
  do not.
  The file, palette, scanline, overlay, and cleanup behavior remain aligned.

The final grouped reconciliation promotes `004BE4B0 DeleteShape`. It reports
`MATCH`, `0.0000%`, with valid ownership, boundaries, and relocations.

`004BDB00 AddSpan` remains scratch. The current source is a natural typed
reconstruction. The focused grouped build reports 589 differing bytes and a
922-byte rebuild against the 916-byte original.

The migration removes the source-bank fragments and the wrapper. `drawarea.h`
owns the shared span declarations. `spanlist.h` consumes the canonical
Drawarea and Shape headers. The composed fanout retained 48/48 Drawarea and
23/23 spanlist exact owners. Shape retained 10/11 checked owners;
`004BAAF0` remains scratch for its documented two-byte difference.

The fresh grouped audit is `build/audit_accepted_drift_final2/report.txt`. It confirms
that `004BE090` has the owning symbol but escapes its original boundary, so it
is not accepted drift. It also confirms that `004BEB10` has 14 aligned calls and
no relocation or boundary mismatch, but its 351-byte difference includes a
return and block-shape change. `004BDEA0 AddShape` and `004BEAD0 DecodeLine`
remain accepted drift. The final reconciliation supersedes the earlier
`004BE4B0` drift result.
