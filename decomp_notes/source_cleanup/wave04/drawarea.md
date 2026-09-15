# `drawarea.cpp` cleanup report

## Delivery

- Module: `src/drawarea.cpp`
- Report: `decomp_notes/source_cleanup/wave04/drawarea.md`
- Branch: `cleanup/staging-20260915-202`
- Base commit: `c22ba4258c45b1178181e185d60a3b09a1add617`
- Source cleanup commit: `8f3614a40c104690b286f317826bf243819ef24d`
- Final source commit: `8f3614a40c104690b286f317826bf243819ef24d`
- Report commit: pending
- Changed files: `src/drawarea.cpp` and this report
- Registry: `config/functions/src/drawarea.cpp.json` (read only)

The source owns the `TDrawSystem` and `TDrawArea` procedures in PDB order.
The cleanup changes supported names, adds three sparse comments, and applies
readable wrapping. It does not change types, scopes, storage, statements,
calls, literals, or source order.

The report commit is separate from the source commit. Its hash is returned
with delivery because a report cannot contain its own final hash.

## Evidence inspected

Name, local, parameter, and register evidence comes from:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/function_source_map.csv`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/function_line_changes.csv`
- `build/pdb/drawarea_symbols.txt` (the extracted procedure summary)

The PDB object module is `Drawarea.obj`. The PDB source path is
`C:\msdev\work\age1_x1\Drawarea.cpp`. The procedure records cover
`00442680` through `004463B0`.

The original function evidence is under:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/`
- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/drawarea.cpp.asm`
- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/drawarea.cpp.decomp`

The layout evidence is:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/types/dumps/TDrawArea.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/types/dumps/DrawAreaNode.txt`
- `include/drawarea.h`
- `include/asm_draw.h`
- `include/color.h`
- `include/game_globals.h`

I also checked the pinned VC5 definitions in `DDRAW.H`, `WINGDI.H`,
`FCNTL.H`, and `SYS/STAT.H`. The source uses no resource ID lookup. The
original executable and resource files therefore supplied no resource name
change for this module.

## Procedure coverage

I inspected parameters, locals, function statics, and registers for all 62
PDB procedures. Every `TDrawSystem` member procedure and every `TDrawArea`
member procedure uses the PDB `this@ecx` register, except the static callback.
The callback has no register record. No PDB function-static record was changed.

The following procedures had no recoverable parameter or local rename. Their
existing names and declarations remain unchanged. PDB locals shown here were
already present in the source:

- `00442680 TDrawSystem::TDrawSystem`: no parameters or locals; `this@ecx`.
- `00442710 TDrawSystem::~TDrawSystem`: `ddbltfx`; `this@ecx`.
- `00442EF0 TDrawSystem::ClearPrimarySurface`: `ddbltfx`; `this@ecx`.
- `00442F30 TDrawSystem::CheckSurfaces`: `ddbltfx`, `ddsd`; `this@ecx`.
- `00443070 TDrawSystem::ClearRestored`: no stack records; `this@ecx`.
- `00443090 TDrawSystem::DeleteSurfaces`: no stack records; `this@ecx`.
- `004430F0 TDrawSystem::CreateSurfaces`: `wnd_rect`, `ddsd`, `ddbltfx`;
  `this@ecx`.
- `00443520 TDrawSystem::Paint`: `rect`, `src`, `dest`; `this@ecx`.
- `00443F10 TDrawArea::~TDrawArea`: no stack records; `this@ecx`.
- `00444110 TDrawArea::CheckSurface`: `ddbltfx`, `ddsd`; `this@ecx`.
- `00444990 TDrawArea::SetAccessOffsets`: no stack records; `this@ecx`.
- `00444B10 TDrawArea::SetInfo`: no stack records; `this@ecx`.
- `00444B40 TDrawArea::AlignedWidth`: no stack records; `this@ecx`.
- `00444B50 TDrawArea::SetClipRect(tagRECT*)`: `rect`; `this@ecx`.
- `00444D50 TDrawArea::Copy`: `ddrval` and `err` statics; `dest_rect2` and
  `src_rect2`; `this@ecx`.
- `004457E0 TDrawArea::SetPixel`: `x`, `y`, `color`; `this@ecx`.
- `004459A0 TDrawArea::DrawRect(long, long, long, long, uchar)`: `x1`, `y1`,
  `x2`, `y2`, `color`; `this@ecx`.
- `00445A40 TDrawArea::DrawRect(tagRECT*, uchar)`: `rect`, `color`; `this@ecx`.
- `00445D20 TDrawArea::DrawBevel2`: `x1`, `y1`, `x2`, `y2`, `c1`, `c2`, `c3`,
  `c4`; `this@ecx`.
- `00445E40 TDrawArea::DrawBevel3`: `x1`, `y1`, `x2`, `y2`, `c1`, `c2`, `c3`,
  `c4`, `c5`, `c6`; `this@ecx`.
- `00445FE0 TDrawArea::DrawBevel21`: `x1`, `y1`, `x2`, `y2`, `c1`, `c2`,
  `c3`, `c4`; `this@ecx`.
- `004460C0 TDrawArea::DrawBevel32`: `x1`, `y1`, `x2`, `y2`, `c1`, `c2`, `c3`,
  `c4`, `c5`, `c6`; `this@ecx`.
- `00446230 TDrawArea::DrawShadowBox`: `x1`, `y1`, `x2`, `y2`; `this@ecx`.
- `00445840 TDrawArea::DrawLine`: `x1`, `y1`, `x2`, `y2`, and `color` already
  matched. PDB locals `yd` and `yl` use reused parameter stack offsets.

The renamed PDB records are below. The names preserve original spelling,
including mixed case. Each change updates only that identifier and its uses.

### `TDrawSystem`

- `004427A0 CheckAvailModes`: `param_1` -> `full_screen`.
- `00442860 CheckAvailModesCallback`: `mode_desc` -> `lpDDSurfaceDesc` and
  `context` -> `lpContext`.
- `004429C0 IsModeAvail`: `width` -> `wid_in`, `height` -> `hgt_in`, and
  `bpp` -> `color_bits`.
- `00442A90 Init`: `inst` -> `inst_in`, `wnd` -> `wnd_in`, `pal` -> `pal_in`,
  `draw_type` -> `type_in`, `screen_mode` -> `mode_in`, `width` -> `wid_in`,
  `height` -> `hgt_in`, and `flags` -> `flags_in`. PDB locals `ddsd`,
  `ddcaps`, `color_table`, and `ddbltfx` already matched.
- `00442DC0 SetDisplaySize`: `wid` -> `wid_in`, `hgt` -> `hgt_in`, and
  `bits` -> `color_bits`. PDB locals `ddbltfx`, `save_wid`, and `save_hgt`
  already matched.
- `004433F0 HandleSize`: `wparam` -> `wParam` and `lparam` -> `lParam`.
- `00443460 HandlePaletteChanged`: `wparam` -> `wParam` and `lparam` ->
  `lParam`.
- `00443490 HandleQueryNewPalette`: `param1` -> `hwnd`, `param2` -> `msg`,
  `param3` -> `wParam`, and `param4` -> `lParam`.
- `00443680 GetIsLostErrorNum`, `004436D0 GetRestoreErrorNum`,
  `00443780 GetSetDispModeErrorNum`, `00443840 GetLockErrorNum`,
  `004438F0 GetDCErrorNum`, `00443990 GetBlitErrorNum`,
  `00443AD0 GetCreateErrorNum`, and `00443C00 GetColorKeyErrorNum`:
  each `hr` or `error_num` parameter -> `ddrval`.
- `00443CB0 SetPalette`: `hPal` -> `pal_in`. PDB local `color_table` already
  matched.
- `00443D40 ModifyPalette`: `start` -> `start_entry`, `count` -> `num_entries`,
  and `entries` -> `pal_entries`.

### `TDrawArea`

- `00443DE0 TDrawArea`: `name` -> `SurfaceName` and `system_mem_only` ->
  `ForceSystemMem`.
- `00444040 Init`: `draw_system` -> `draw_system_in`, `width` -> `wid_in`,
  `height` -> `hgt_in`, `flags` -> `Extend`, and `is_primary` ->
  `isPrimary_in`.
- `00444270 Lock`: `name` -> `caller_name` and `waitFlag` -> `wait`.
- `00444300 Unlock`, `00444340 GetDc`, and `00444390 ReleaseDc`: `name` or
  `unused` -> `caller_name`.
- `004443D0 SetSize`: `width` -> `wid_in`, `height` -> `hgt_in`, and `flags` ->
  `ExtendSurface`.
- `00444680 Clear`: local `width` -> `wid`. The PDB records `wid` as an
  `int`; the existing source declaration remains `int`.
- `00444A60 SetFloatOffsets`: `x` -> `X_Delta` and `y` -> `Y_Delta`.
- `00444C30 SetClipRect(long, long, long, long)`: `left` -> `x1`, `top` ->
  `y1`, `right` -> `x2`, and `bottom` -> `y2`.
- `00445710 SetTrans`: `useTrans` -> `use_trans_in` and `transColor` ->
  `trans_color_in`.
- `00445780 SetOverlayTrans`: `useTrans` -> `use_trans_in` and `transColor` ->
  `trans_color_in`.
- `00445A60 DrawHorzLine` and `00445AF0 DrawVertLine`: `w` or `h` -> `len`.
- `00445B80 FillRect`: local `width` -> `rect_wid`. The existing `long`
  declaration remains unchanged; the PDB type record is not used to change it.
- `00445C70 DrawBevel`: local `h` -> `rect_hgt`.
- `00446220 SetShadowTable`: `table` -> `color_table_in`.
- `00446340 GetPalette` and `00446370 SetPalette`: `entries` -> `palette1`.
- `004463B0 take_snapshot`: `file_name` -> `filespec`, `snapshot_number` ->
  `index_no`, `file_header` -> `bmFH`, `info_header` -> `bmIH`,
  `bitmap_file` -> `BMPFile`, `bitmap_palette` -> `bmPAL`, `palette` ->
  `thePal`, and `bitmap_width` -> `bmWide`.

The source introduces no new inferred identifier. All changed names above are
PDB spellings. Existing names without a usable PDB record remain descriptive
source names.

## Unresolved mappings

`00445840 TDrawArea::DrawLine` has PDB locals `yd` and `yl`. Both records
reuse parameter stack offsets (`+0x8` and `+0xc`). The current natural source
uses separate `temp`, `x_length`, `y`, `y_length`, `y_step`, `error`, and
`run_start` declarations. The original stack reuse does not prove a safe
one-to-one mapping. I did not force these names into different declarations.

The PDB has no usable local record for the remaining descriptive temporaries,
including `mode_info`, `bpp`, `direct_draw`, `was_present`, `hr`, `node`,
`cur`, `surface_height`, `p`, `delta`, and the snapshot `bitmap_height`,
`row_width`, `attempts`, `existing_file`, `row`, and `output_file`. Their
existing types, declaration points, scopes, and storage remain unchanged.

The source keeps the current local `long rect_wid` in `FillRect`, despite the
PDB local type record displaying `int`. A name record does not prove permission
to change the source type. A type correction needs separate evidence and
validation.

The PDB reports every member receiver in `ecx`. The callback has no receiver
register. No source ABI name, class name, member name, function boundary, or
calling convention changed.

## Comments, constants, and resources

Three comments were added:

- `CheckAvailModesCallback`: return value `1` is the VC5 `DDENUMRET_OK` value
  used to continue DirectDraw mode enumeration. The value remains `1`.
- `SetAccessOffsets`: the observed `Pitch * 5` offset applies five extra rows
  before the visible rows on extended surfaces.
- `take_snapshot`: the reverse row loop writes a positive-height BMP from the
  bottom display row to the top.

No constant or resource ID was added or replaced. The source retains DirectDraw
flags, DirectDraw error values, Windows message values, file-open masks, BMP
format values, and the fixed snapshot format. No string ID, dialog ID, menu ID,
resource arithmetic, or resource lookup occurs in this module. No shared-file
or header change is requested.

## Code-generation review

The complete diff was reviewed after the source commit. The changes rename
identifiers, add comments, and adjust whitespace, wrapping, and brace layout.
They do not change executable expressions, declaration order, scopes, types,
storage duration, casts, calls, control flow, literals, fixed strings, class
layout, or global ownership. No inline assembly, wrapper, helper, or binary
library dependency was added.

The formatting changes can alter debug line records. No claim is made about
release instructions or program-data equality because compilation was deferred.

## Validation

Compilation, matching, audits, and tests were not run. No build, compiler
check, executable comparison, game, or runtime harness was run. The result is
reviewed but unvalidated.
