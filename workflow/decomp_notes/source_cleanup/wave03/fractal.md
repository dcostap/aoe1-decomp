# `src/fractal.cpp` cleanup report

## Delivery

- Module: `src/fractal.cpp`.
- Header owner: `include/fractal.h`. I did not edit this header.
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`.
- Final source commit: `6fc10af8df43c26609caa1e0a9a267f71c3043c1`.
- Source commit changed: `src/fractal.cpp`.
- The report is the second assigned-file commit after the source commit.
- No other project file was edited.

The source change restores procedure-scoped PDB names and applies 1TBS formatting. It does not change types, storage, statements, expressions, calls, literals, layouts, or ABI symbols.

## Evidence and coverage

I inspected the registry at `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/slot-143/config/functions/src/fractal.cpp.json` and every registry-selected packet under `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/`:

`0044AB90_SetDefaultValues.txt`, `0044AC50_PointMaker.txt`, `0044AC80_PointMaker.txt`, `0044ACB0_CreateMasks.txt`, `0044AF90_DeleteMasks.txt`, `0044AFE0_DrawMask.txt`, `0044B210_ClearArrays.txt`, `0044B270_DeleteArrays.txt`, `0044B2B0_MakeArrays.txt`, `0044B320_CreateShape.txt`, `0044B470_CreateShape.txt`, `0044B540_Branch.txt`, `0044B610_MakeFirstLink.txt`, `0044B760_MakeNewLink.txt`, `0044B950_MakeSatelliteLink.txt`, `0044BAA0_DrawPrimaryIntoProbabilityArray.txt`, `0044BB60_DrawCurrentBranchIntoProbArray.txt`, `0044BCD0_DrawCurrentSatelliteIntoProbArray.txt`, `0044BD80_AddingRect.txt`, `0044BF90_AddingCircle.txt`, `0044C1B0_CreateMapBasedOnProbabilityArray.txt`, `0044C200_SetPoint.txt`, `0044C220_SetMaxNumberOfBranches.txt`, `0044C230_SetChanceOfNextNode.txt`, `0044C240_SetNumberOfSatellites.txt`, `0044C250_SetSplitsPerBranch.txt`, `0044C260_SetWidthAndHeight.txt`, `0044C280_SetStartPositionRadius.txt`, `0044C290_SetBranchsRadius.txt`, `0044C2A0_SetSatelliteRadius.txt`, `0044C2B0_SetMaxNumberOfBranchLevels.txt`, `0044C2D0_SetSatelliteDistance.txt`, `0044C2E0_SetBranchDistance.txt`, `0044C2F0_SetMinimumNumberOfTiles.txt`, `0044C300_SetDrawToOneArray.txt`, `0044C310_SetBorderDepthPercentage.txt`, `0044C350_RetrieveMap.txt`, `0044C360_RetrieveProbMap.txt`, `0044C370_ErrorCheckingAndCorrection.txt`, `0044C4B0_PrepareLimits.txt`, and `0044C510_MapCleanUpEliminatingSinglesOnly.txt`.

The complete procedure-scoped record source was `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`. All 41 records identify `this` as `PointMaker*` in `ecx`.

The 17 procedures with no scoped stack symbols were inspected and left without forced local renames: `0044AB90 SetDefaultValues`, `0044AC50 PointMaker`, `0044AC80 ~PointMaker`, `0044AF90 DeleteMasks`, `0044B210 ClearArrays`, `0044B270 DeleteArrays`, `0044B2B0 MakeArrays`, `0044B320 CreateShape()`, `0044B610 MakeFirstLink`, `0044B760 MakeNewLink`, `0044B950 MakeSatelliteLink`, `0044C1B0 CreateMapBasedOnProbabilityArray`, `0044C300 SetDrawToOneArray`, `0044C350 RetrieveMap`, `0044C360 RetrieveProbMap`, `0044C370 ErrorCheckingAndCorrection`, and `0044C4B0 PrepareLimits`.

The scoped stack records for the other 24 procedures were:

- `0044ACB0 CreateMasks`: `ptr3:char[25]@-0x74`, `ptr2:char[16]@-0x84`, `ptr5:char[49]@-0x34`, `ptr4:char[36]@-0x58`.
- `0044AFE0 DrawMask`: `x:int@+0x4`, `y:int@+0x8`, `size:int@+0xc`, `len:int@-0x4`, `maskptr:char*@+0x8`, `w:int@+0xc`, `mapptr:int@-0x10`.
- `0044B470 CreateShape(int,int)`: `xt:int@+0x4`, `yt:int@+0x8`.
- `0044B540 Branch`: `which:const int@+0x4`.
- `0044BAA0 DrawPrimaryIntoProbabilityArray`: `i:int@-0xc`, `desty:int@-0x10`.
- `0044BB60 DrawCurrentBranchIntoProbArray`: `which:int@+0x4`, `i:int@-0x4`, `desty:int@-0x8`.
- `0044BCD0 DrawCurrentSatelliteIntoProbArray`: `which:int@+0x4`.
- `0044BD80 AddingRect`: `x1:int@+0x4`, `y1:int@+0x8`, `x2:int@+0xc`, `y2:int@+0x10`, `start:int@+0xc`, `top:int@+0x8`, `w:int@-0x4`.
- `0044BF90 AddingCircle`: `x1:int@+0x4`, `y1:int@+0x8`, `radius:int@+0xc`, `step:int@-0x4`, `curx:float@-0x1c`, `W:float@-0x10`, `lasty:float@-0x14`, `lastx:float@-0x18`, `x:float@-0x8`.
- `0044C200 SetPoint`: `x1:int@+0x4`, `y1:int@+0x8`.
- `0044C220`, `0044C230`, `0044C240`, `0044C250`, `0044C280`, `0044C290`, `0044C2A0`, `0044C2B0`, `0044C2D0`, `0044C2E0`, and `0044C2F0`: `num:int@+0x4`.
- `0044C260 SetWidthAndHeight`: `w:int@+0x4`, `h:int@+0x8`.
- `0044C310 SetBorderDepthPercentage`: `num:int@+0x4`.
- `0044C510 MapCleanUpEliminatingSinglesOnly`: `h:int@-0x4`, `w:int@-0x8`.

## Recovered names

All names below are recovered originals from the scoped PDB record. I did not add new descriptive names.

- `CreateShape(int,int)`: `param_1` -> `xt`; `param_2` -> `yt`.
- `Branch`: `point` -> `which`.
- `DrawPrimaryIntoProbabilityArray`: `ring` -> `i`; `bottom` -> `desty`.
- `DrawCurrentBranchIntoProbArray`: `ring` -> `i`; `max_y` -> `desty`.
- `DrawCurrentSatelliteIntoProbArray`: `point` -> `which`.
- `AddingRect`: parameters `left`, `top`, `right`, `bottom` -> `x1`, `y1`, `x2`, `y2`; locals `first`, `width`, and `opposite` -> `start`, `w`, and `top`.
- `AddingCircle`: `param_1`, `param_2`, and `param_3` -> `x1`, `y1`, and `radius`.
- `SetPoint`: `value_x` and `value_y` -> `x1` and `y1`.
- `SetMaxNumberOfBranches`, `SetChanceOfNextNode`, `SetNumberOfSatellites`, `SetSplitsPerBranch`, `SetStartPositionRadius`, `SetBranchsRadius`, `SetSatelliteRadius`, `SetMaxNumberOfBranchLevels`, `SetSatelliteDistance`, `SetBranchDistance`, `SetMinimumNumberOfTiles`, and `SetBorderDepthPercentage`: `value` -> `num`.
- `SetWidthAndHeight`: `width` and `height` -> `w` and `h`.
- `MapCleanUpEliminatingSinglesOnly`: `bottom` and `right` -> `h` and `w`.

The `AddingRect` PDB record reuses the `x2` and `y1` stack offsets for `start` and `top`. The exact packet data flow identifies these as the existing start index and opposite-row index. I changed names only. I did not change declaration storage or scope.

## Unresolved declaration mappings

The PDB has no reliable names for many optimized register locals. I left them unchanged. This includes unlisted locals in `MakeNewLink`, `MakeSatelliteLink`, `CreateShape()`, and `ErrorCheckingAndCorrection`. In `DrawMask`, `rows`, `destination`, `value`, `map`, `count`, `mask_offset`, and `mask` have no scoped PDB names. In `AddingRect`, `height`, `rows`, `count`, `map`, `add_value`, `add`, `cell`, `value`, and `other` have no scoped PDB names. I did not force these mappings.

## Constants, resources, comments, and risk

- No constants were added or replaced. Existing algorithm values, casts, widths, and literal spellings remain unchanged.
- I read the pinned VC5 CRT definitions in `C:/Program Files (x86)/DevStudio/VC/Include/STDLIB.H` and `STRING.H`. No SDK or CRT symbol applied to this module.
- This module has no resource lookup or resource ID use. No resource mapping is unresolved, and no resource extraction was needed.
- The two existing comments about the lower-y correction remain unchanged. The original `0044B760_MakeNewLink.txt` and `0044B950_MakeSatelliteLink.txt` assembly packets prove the shipped `dx` negation in the lower-y correction. I added no comments.
- The source change only renames parameters and locals and moves opening braces to 1TBS form. It does not change a type, layout, call target, evaluation order, literal, function boundary, symbol identity, or ABI.

## Shared requests and questions

Please ask the `include/fractal.h` owner to align declaration parameter names with the recovered PDB names. The requested declaration-only changes are:

- `CreateShape(int xt, int yt)`.
- `Branch(int which)`.
- `DrawCurrentBranchIntoProbArray(int which)`.
- `DrawCurrentSatelliteIntoProbArray(int which)`.
- `AddingRect(int x1, int y1, int x2, int y2)`.
- `AddingCircle(int x1, int y1, int radius)`.
- `SetPoint(int x1, int y1)`.
- The setter argument `num` for the setters listed above.
- `SetWidthAndHeight(int w, int h)`.

These requests do not change any interface type or ABI. No request targets `include/resource_ids.h` or another shared header. No unresolved question blocks this source commit.

## Reference hashes

- Original PDB: `C:/Projects/my_decomps/aoe1_attempt3/orig/age1_x1.pdb`, SHA256 `3acf0034af3aae3636c37746d3336d76f737855963fabf64e66b22e3c3e46e40`.
- Original executable: `C:/Projects/my_decomps/aoe1_attempt3/orig/empiresx.exe`, SHA256 `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
- Preserved pre-cleanup object: `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/fractal.obj`, SHA256 `68cb033602f9c2e429e1a9968b64a714522b83449dbf436eba224f13a2b59e02`.

## Correction history

- Owner review corrected the original executable citation to the repo-local path. The directly verified SHA256 is unchanged.

## Validation status

Compilation, matching, audits, tests, and game execution were not run, as required for this cleanup phase. I reviewed the complete Git diff and ran `git diff --check` only.
