# view.cpp source module

## Scope

- PDB source: `C:\\msdev\\work\\age1_x1\\view.cpp`.
- Source: `src/view.cpp`.
- Header: `include/view.h`.
- Flags: `config/flags/gx.rsp`.

The module has 79 normal owners. `src/view.cpp` keeps them in PDB source
order. It is their only compiler-facing source.

The compiler-generated deleting destructor at `00533740` is not a normal
owner. VC5 emits it from the constructor and destructor context.

## Type ownership

`view.h` owns the public View and DClip declarations. It also owns the shared
PDB pick records:

- `RGE_Pick_Info`, 0x14 bytes, view.cpp lines 3566-3575;
- `RGE_Pick_Obj_Info`, 0x0C bytes, view.cpp lines 3577-3585; and
- `extern RGE_Pick_Obj_Info Picked_Objects[]`.

`RGE_Main_View` consumes these records. It must not define another copy.
`Picked_Objects` remains an external declaration. This module does not define
its storage.

The tile-edge, queued-blit, selected-display, overlay-sprite, and short pick
list records stay private to `src/view.cpp`. No other public module needs their
complete definitions.

## Validation

`validate_candidate_tu.py` compiled the direct source on current main. The 47
registered owners report `MATCH`, `0.0000%`, correct ownership, boundaries,
and relocations.

The other 32 rows keep their existing scratch,
accepted-drift, or verified-logic status. This merge does not claim new
behavior for them.

The candidate records decorated names for the five overloaded rows. It has no
comparison errors.

Final grouped validation uses the emitted `struct RGE_Tile` symbol encoding for
`00539D90` and `00539EC0`. This encoding agrees with the canonical tile record.

Direct source compilation succeeds with the pinned VC5 compiler.

## Incomplete record tags

The full CodeView definitions for `RGE_Pick_Info` and `DClipInfo_Node` are
classes. Original function symbols encode pointers to these records with the
struct tag. The headers therefore use struct forward declarations and retain
the full class definitions. This matches both evidence sources.

The correction repairs original owner symbols at `005359E0`, `00538280`,
`00538420`, `0053B000`, `0053B220`, `0053B490`, and `0053B4B0`. It does not
change their emitted instructions.

## Natural-source audit

The direct source has no wrapper, fragment include, context macro, absolute
address, field-alias macro, alias union, `volatile`, or `register` form.

It uses the PDB field names for DClip, selected-display records, pick records,
tile object lists, and queued blits. It uses `TDrawArea::Wnd` for cursor
placement. File relocation work uses byte pointers only for the loaded tile
edge buffers.

The audit demoted `005381C0` to scratch. `Update_Render_Pointers` now uses
the canonical pixel buffer and pitch. Its direct candidate result is a
164-byte mismatch with one boundary escape. The remaining 47 exact rows still
report `MATCH`, `0.0000%`.

## Final source repair

The source uses C++ `new` and `delete` for View-owned objects. It keeps the
explicit `TPanel::~TPanel()` call. The original View destructor has two panel
destructor calls.

The source uses the CRT, I/O, and Windows headers. It has no local CRT, I/O,
Windows API, allocation, or deallocation declarations.

PDB records only the reference form of `get_border_edge_pictures`. The header
has only that form. `draw_tile` passes its four result variables as lvalues.
`set_player` uses `-9999.0f` for both cached view coordinates.

The final direct candidate retains all 47 exact `MATCH`, `0.0000%` rows. It
has no comparison errors, relocation errors, or boundary errors.

## Independent accepted-drift audit

The audit used the original executable listing and fresh current-main checks.
It did not reopen any exact owner. Natural bodies remain in `src/view.cpp`.

The audit demoted three broad or unsupported rows to `scratch`:

| VA | Evidence | Decision |
| --- | --- | --- |
| `00533AF0` | 799 original bytes, 781 rebuilt bytes, 645 strict differences, and a broad table and edge-map loop drift. The 14 calls align, but the whole pointer-rebase and edge-table body differs. | `scratch` |
| `00539510` | 413 original and rebuilt bytes, 52 strict differences, and 142 instructions on both sides. The decoder CFG and cases now align; the remaining bytes are an EAX/ECX register recolor and one relocated table. | `scratch` |
| `00535A80` | The rebuilt body has 495 bytes and 39 strict differences. The original calls virtual slots `+0xE0` and `+0xE4` at offsets `+0x157` and `+0x18F`. The rebuilt body calls `+0xF0` and `+0xF4`. This changes virtual targets for derived views. | `scratch` |

The following four rows retain `accepted_drift` because the evidence is local
and proves the same calls, bounds, writes, returns, and state effects:

| VA | Narrow evidence |
| --- | --- |
| `00533E10` | The one call, six conditions, loop bounds, object lookup, expiry test, and selected-byte updates match. The 7-byte overshoot contains only load/modify/store lowering for the selected byte. |
| `00533EC0` | The scan, reset-time subtraction, one call, field writes, and size increment match. `found` is true exactly when `slot` is non-null, so the extra final null test is redundant. |
| `00539030` | The function reads the same tile row, screen coordinates, tile type, and tile sizes. It writes the same three outputs and clears `tile_half_hgt`, `tile_half_wid`, and `elev_hgt` in the same order. |
| `0053B300` | The 103-byte bodies have the same 47 instructions and no calls. The only 2-byte hunk moves `mov edx,eax` across the bound branch. |

These four claims remain non-exact. New evidence must reopen them if it shows
a changed call, bound, write, return, target, or fault order.

## 2026-09-04 joint sprite context repair

On current main `48efa69ec`, the compact compound guard in `sprite_check`
improved that target to 413 bytes and 52 differences but changed exact
`get_tile_picture` to 241 bytes and 209 differences. The original nested guard
shape keeps the selector repair and restores `get_tile_picture` to 238 bytes,
`MATCH`, and `0.0000%` under `/GX`. The affected owners are `00539510` and
`00539AA0`; no shared header or flag change is needed.

## Wave20 reconciliation

The sequential wave20 audit promotes exact `00534500 set_player`. It removes
the stale `00539AA0 get_tile_picture` exact claim after a 120-byte mismatch and
one boundary escape. The module retains 47 matching, 26 scratch, four
accepted-drift, and two verified-logic owners. All 47 registered owners match.

## 2026-08-31 virtual-order repair

Original vtable `005775B8` places object `pick_through_fog` and `pick_weight`
at `+0xE0/+0xE4`. Scroll methods follow at `+0xE8` through `+0xF4`, and
`draw_multi_object_outline` uses `+0xF8`. The header now follows that order.

The full affected audit kept all 1,789 matching owners exact. It also made
`0053A0D0 start_scroll_view` and `0053A9C0 end_scroll_view` exact.

## Packed border context

Use `tile->border_type | (tile->border_shape << 4)` without an intermediate
byte cast. This keeps the packed semantics and preserves exact tile-picture
code generation.

## 2026-09-14 drift-007 re-review

The final command was:

```text
python tools/audit_translation_unit_functions.py --group view --jobs 1 --output-dir build/drift-007-view/audit-final
```

The audit compiled one translation unit with 79 normal owners. It checked 62
exact targets and found zero compile errors. The report lists 62 matching
results, 11 verified-logic observations, three accepted-drift observations,
two boundary problems, and one grouped match that needs review.

| VA | Behavior | Source | Bytes | Integration |
| --- | --- | --- | --- | --- |
| `00533AF0` | Static review found no behavior defect. Failed files and malformed tables remain untested. | Typed table source remains. Direct member indexing worsened codegen. | 802 vs 799 bytes; 167 differences. | Two boundary escapes overlap `00533E10`. Two file strings need linked-storage checks. Do not integrate. |
| `00533E10` | Static review found no behavior defect. Concurrent updates remain untested. | Source remains. Compound byte operations were a codegen duplicate. | 169 vs 162 bytes; 61 differences. | One boundary escape extends seven bytes. The debug-time string needs linked-storage validation. Do not integrate. |
| `00533EC0` | Found implies pointer assignment. The exact body preserves scan and publication order. | Source uses PDB-proven, uninitialized local `n`. | 163 vs 163 bytes; exact match. | Zero boundary escapes; relocation targets match. One debug-time string still needs linked-storage validation. Review for promotion. |
| `00535A80` | Static review found no behavior counterexample. Live gameplay was not tested. | Natural typed source remains. No new source lead was found. | 495 vs 495 bytes; 37 differences. | Zero boundary escapes. `Picked_Objects` storage remains unknown. Hold current drift status. |
| `00539510` | Static review found no behavior counterexample. Malformed SLP data was not tested. | Natural typed decoder remains. Earlier source probes found no exact form. | 413 vs 413 bytes; 52 differences. | Zero boundary escapes. Switch-table storage remains unknown. Hold current drift status. |
| `0053B300` | Static review found no behavior counterexample. Invalid list pointers were not tested. | Natural typed source remains. Moving a local worsened codegen. | 103 vs 103 bytes; 15 differences. | Zero boundary escapes or relocations. Hold current drift status. |

The audit reports `00533AF0` and `00533E10` as `boundary_problem`. It reports
`00533EC0` as an exact grouped match that needs promotion review. It reports
the other three targets as accepted-drift observations that remain closed.
These are audit results, not registry changes. No status, original, or
inventory file changed.

The registry still labels all six entries `accepted_drift`. This conflicts
with the prior independent audit's `scratch` notes for `00533AF0`,
`00535A80`, and `00539510`. This task did not change those labels. The full
reports are `build/drift-007-view/audit-final/report.txt`, `report.csv`, and
`report.json`. Function notes under `decomp_notes/functions/0053/` contain
original instruction ranges, state IDs, event IDs, and experiment report paths.
