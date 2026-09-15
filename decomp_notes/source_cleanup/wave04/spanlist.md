# Source cleanup report: `spanlist.cpp`

## Delivery

- Module: `C:/Projects/my_decomps/aoe1_attempt3/src/spanlist.cpp`
- Report: `C:/Projects/my_decomps/aoe1_attempt3/decomp_notes/source_cleanup/wave04/spanlist.md`
- Branch: `cleanup/staging-20260915-205`
- Base commit: `c22ba4258c45b1178181e185d60a3b09a1add617`
- Source owner: `C:/Projects/my_decomps/aoe1_attempt3/src/spanlist.cpp`
- Header read only: `C:/Projects/my_decomps/aoe1_attempt3/include/spanlist.h`
- Source cleanup commit: `092cafdf58aa0e6be50e126a6a046b66ea29508e`
- Initial report commit: `44841477e550b0a1e07180a7945d42f9a752be83`
- Source correction commit: `324bf1c3c410408df64f3b65c1b3389ec37f9602`

Correction history:

- `092cafdf58aa0e6be50e126a6a046b66ea29508e`: initial identifier cleanup.
- `44841477e550b0a1e07180a7945d42f9a752be83`: initial cleanup report.
- `324bf1c3c410408df64f3b65c1b3389ec37f9602`: source correction. It moves
  existing opening braces to 1TBS positions and joins clearly short signatures.

This report covers all 29 normal PDB functions in the module. The cleanup only
recovers names and does not change behavior.

## Evidence

The name recovery uses
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`. The PDB source path
for every function is `C:\msdev\work\age1_x1\spanlist.cpp`. The PDB records include
procedure boundaries, stack symbols, and the `this` register in `ecx`.

The executable evidence packets were inspected for every function:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004BD5E0_TSpan_Node_List.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004BD640_TSpan_Node_List.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004BD690_SetNumZones.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004BD720_InitNewZone.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004BD790_GetNode.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004BD800_FreeNode.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004BD820_FreeThread.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004BD880_ReclaimAllNodes.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004BD8A0_ResetStats.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004BD8B0_TSpan_List_Manager.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004BD9A0_TSpan_List_Manager.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004BDA00_SetSpanRegions.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004BDA70_ResetAll.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004BDB00_AddSpan.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004BDEA0_AddShape.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004BDFA0_AddShape_Align.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004BE090_AddLine_Align.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004BE1F0_AddMiniList.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004BE240_SubtractMiniList.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004BE290_DeleteSpan.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004BE4B0_DeleteShape.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004BE5B0_PointVisible.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004BE5F0_Merge_n_Align.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004BE690_AlignamizeSpans.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004BE750_ScrollSpansHorizontally.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004BE850_ScrollSpansVertically.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004BE9E0_ValidateSpan.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004BEAD0_DecodeLine.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004BEB10_take_snapshot.txt`

The existing module note at
`C:/Projects/my_decomps/aoe1_attempt3/decomp_notes/spanlist.md` was read for matching and
accepted-drift context. The original executable remains the behavior oracle.

## Original-name recovery

All names in this table come from the procedure-scoped PDB records. Names not
listed in a procedure record remain unchanged.

| VA | Function | Recovered names applied |
| --- | --- | --- |
| `004BD5E0` | `TSpan_Node_List::TSpan_Node_List` | `InitialSize`, `GrowSize`, `szitem` |
| `004BD640` | `TSpan_Node_List::~TSpan_Node_List` | No stack names |
| `004BD690` | `SetNumZones` | `New_Size`, `Ptrs` |
| `004BD720` | `InitNewZone` | `Zone_Size` |
| `004BD790` | `GetNode` | No stack names |
| `004BD800` | `FreeNode` | `theNode` |
| `004BD820` | `FreeThread` | `HeadNode`, `TailNode` |
| `004BD880` | `ReclaimAllNodes` | No stack names |
| `004BD8A0` | `ResetStats` | No stack names |
| `004BD8B0` | `TSpan_List_Manager::TSpan_List_Manager` | `Surface_Width`, `Surface_Height` |
| `004BD9A0` | `TSpan_List_Manager::~TSpan_List_Manager` | No stack names |
| `004BDA00` | `SetSpanRegions` | `MinS`, `MinL`, `MaxS`, `MaxL` |
| `004BDA70` | `ResetAll` | No stack names |
| `004BDB00` | `AddSpan` | `LeftPx`, `RightPx`, `Line` |
| `004BDEA0` | `AddShape` | `theShape`, `shape_num`, `Xpos`, `Ypos`, `Mirror`, `X2` |
| `004BDFA0` | `AddShape_Align` | `Shape_Base`, `SI`, `Xpos`, `Ypos`, `Mirror`, `X2` |
| `004BE090` | `AddLine_Align` | `x1`, `y1`, `x2`, `y2` |
| `004BE1F0` | `AddMiniList` | `theList`, `Xpos`, `Ypos` |
| `004BE240` | `SubtractMiniList` | `theList`, `Xpos`, `Ypos` |
| `004BE290` | `DeleteSpan` | `LeftPx`, `RightPx`, `Line`, `L`, `R` |
| `004BE4B0` | `DeleteShape` | `theShape`, `shape_num`, `Xpos`, `Ypos`, `Mirror`, `X2` |
| `004BE5B0` | `PointVisible` | `x`, `Line` |
| `004BE5F0` | `Merge_n_Align` | `List1`, `List2` |
| `004BE690` | `AlignamizeSpans` | No stack names |
| `004BE750` | `ScrollSpansHorizontally` | `XOffset`, `ClipToCurrentRegion`, `y` |
| `004BE850` | `ScrollSpansVertically` | `YOffset`, `ClipToCurrentRegion`, `y1`, `y2`, `ClearStart` |
| `004BE9E0` | `ValidateSpan` | `Line`, `C` |
| `004BEAD0` | `DecodeLine` | `LineBuf`, `Line`, `fillC`, `MaxX` |
| `004BEB10` | `take_snapshot` | `filespec`, `index_no`, `render_area`, `scolor`, `SpanArray`, `colorArray`, `ArraySize` |

The cleanup also restores the PDB `X2` local name in each shape function. The
existing `right` declarations map to the computed right edge in the PDB code.
The `L` and `R` declarations in `DeleteSpan` map to the saved head and tail
pointers. The `C` declaration in `ValidateSpan` maps to the span count.

The PDB records also contain reused stack homes for `yd`, `xt`, and `yl` in
`AddLine_Align`, and for `ClearEnd`, `y1`, `y2`, and `ClearStart` in
`ScrollSpansVertically`. The existing declarations for `yd`, `xt`, `yl`, and
`ClearEnd` are not present in the source. The cleanup does not add declarations
or force a stack-home mapping. It only renames the existing `line`, `src_line`,
and `clear_first` declarations to the directly supported `y1`, `y2`, and
`ClearStart` names. `ClipToCurrentRegion` remains the existing parameter even
when the original code reuses its storage for the range end.

Unrecorded locals remain as existing descriptive names. This includes locals
such as `temp`, `info`, `outline`, `start`, `end`, `node`, `current`, `last`,
`y_delta`, and `count`. No declaration scope, type, initialization point, or
storage duration changed.

## Constants, resources, and comments

No numeric constant changed. No constant or enum was added. No resource lookup
exists in this module. No resource ID mapping is needed. The snapshot file
pattern remains unchanged. A non-blocking declaration-name request is listed
below.

No source comment was added. Existing code and this report provide enough
context for this name-only cleanup.

## Header request (non-blocking)

The declarations for `TSpan_Node_List` and `TSpan_List_Manager` are owner-owned
in `C:/Projects/my_decomps/aoe1_attempt3/include/drawarea.h`. Please update
declaration parameter names to match the PDB-backed definitions. Keep all types,
signatures, layouts, and ABI details unchanged.

For `TSpan_Node_List`, the requested names are:

- `TSpan_Node_List`: `InitialSize`, `GrowSize`, `szitem`
- `SetNumZones`: `New_Size`
- `InitNewZone`: `Zone_Size`
- `FreeNode`: `theNode`
- `FreeThread`: `HeadNode`, `TailNode`

For `TSpan_List_Manager`, the requested names are:

- `TSpan_List_Manager`: `Surface_Width`, `Surface_Height`
- `SetSpanRegions`: `MinS`, `MinL`, `MaxS`, `MaxL`
- `AddSpan`: `LeftPx`, `RightPx`, `Line`
- `AddShape`: `theShape`, `shape_num`, `Xpos`, `Ypos`, `Mirror`
- `AddShape_Align`: `Shape_Base`, `SI`, `Xpos`, `Ypos`, `Mirror`
- `AddLine_Align`: `x1`, `y1`, `x2`, `y2`
- `AddMiniList`: `theList`, `Xpos`, `Ypos`
- `SubtractMiniList`: `theList`, `Xpos`, `Ypos`
- `DeleteSpan`: `LeftPx`, `RightPx`, `Line`
- `DeleteShape`: `theShape`, `shape_num`, `Xpos`, `Ypos`, `Mirror`
- `PointVisible`: `x`, `Line`
- `Merge_n_Align`: `List1`, `List2`
- `ScrollSpansHorizontally`: `XOffset`, `ClipToCurrentRegion`
- `ScrollSpansVertically`: `YOffset`, `ClipToCurrentRegion`
- `ValidateSpan`: `Line`
- `DecodeLine`: `LineBuf`, `Line`, `fillC`, `MaxX`
- `take_snapshot`: `filespec`, `index_no`, `render_area`, `scolor`, `SpanArray`,
  `colorArray`, `ArraySize`

The PDB has no declaration-name records for the other methods. The declarations
in `C:/Projects/my_decomps/aoe1_attempt3/include/spanlist.h` have no declarations
to update for this request.

## Scope and preservation review

The initial source changes are identifier renames only. The correction changes
only opening-brace placement and definition-signature wrapping. Together they
preserve statement order, control flow, expressions, casts, calls, types,
declarations, storage, member access, function boundaries, ABI symbols,
relocations, and known accepted drift. No wrapper, helper, assembly, or header
change was made.

`DecodeLine` keeps its unused `MaxX` parameter. The cleanup does not add a bound
check or otherwise change its byte-update behavior. The nonexact functions
`AddSpan`, `AddShape`, `AddLine_Align`, `DecodeLine`, and `take_snapshot` retain
their existing bodies.

## Validation

Compilation, matching, audits, validation, tests, and runtime checks were not
run, as required by the wave instructions. Only evidence inspection and the
complete source diff review were performed before this correction.
