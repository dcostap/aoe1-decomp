# Function notes: 004D10F0 `update`

Module notes: `decomp_notes/tact_mob_module.md`.

## Recovered attempt history

<!-- recovered:0d373afa492ff46f4615 -->
### `d050eea3c` `src/tact_mob.cpp:127-127`

Mapping: `strong`. next mapped function definition is update at old line 128.

```text
// VA 004D10E0; PDB tact_mob.cpp:120-123; matching.
```
<!-- end-recovered:0d373afa492ff46f4615 -->

<!-- recovered:50de96278e909a3e4bb9 -->
### `d050eea3c` `src/tact_mob.cpp:186-187`

Mapping: `strong`. comment lies after mapped function update at old line 128.

```text
// VA 004D12B0; PDB tact_mob.cpp:171-233; matching.
// BINARY NOTE: The retry loops use the shipped side-selection and radius
```
<!-- end-recovered:50de96278e909a3e4bb9 -->

<!-- recovered:49e5d7388a05da3cf214 -->
### `6e2375c51785` `src/scratch/004D10F0_update.cpp:1-13`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 004D10F0 TRIBE_Action_Make_Obj::update
// Attempt log:
// 1: Natural reconstruction from packet/decompiler with local typed layout and virtual slot fillers; compiled 400 bytes vs 446. Good prologue, but early state check used cmp/cmp not original dec/sub and rge_base_game quick_build offset was wrong.
// 2: Switch on state to match dec/sub dispatch; fix RGE_Base_Game quick_build layout and work-rate source order: prologue/dispatch and quick_build now match, still 416 vs 446 due call/source-shape differences.
// 3: Use cdecl raw debug-log slot to get caller cleanup like original; split work-rate expression: 432 bytes, still short.
// 4: Volatile obj/player after place_obj reached 446 bytes and produced a real diff, but worsened prologue to `sub esp,0Ch` and 89.9103% positional diff; rolled back.
// 5: `work_done += rate * factor` did not change size/family.
// 6: Named `factor` local for work-rate multiplier did not change size/family.
// 7: Delaying `obj` local until after needed-time load did not change size/family.
// 8: Kept cdecl debug-log and switch dispatch because they match important original traits; blocker is remaining source-shape/TU register scheduling in success/failure call blocks.
// 9: Temporary /Od flag probe did not change the 432-byte short .text family; removed flag.
// 10: Temporary /O2 without /Oy probe also stayed in 432-byte short .text family; removed flag.
// BLOCKER: current best has correct prologue/dispatch and quick_build offset but `check_function` cannot compare because rebuilt .text is 432 bytes vs configured/original 446. Need recover original's extra reload/call scheduling around player debug/cancel/success blocks without volatile prologue spill.
```
<!-- end-recovered:49e5d7388a05da3cf214 -->
