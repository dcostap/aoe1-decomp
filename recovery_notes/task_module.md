# task.cpp source reunification

PDB source: `C:\\msdev\\work\\age1_x1\\task.cpp`.

The module owns six normal functions. Their source order follows the PDB line
bands: constructor `00508670` (26-57), destructor `005086F0` (62), `copy`
`00508700` (68-98), binary `load` `005087C0` (103-149), text `load`
`00508A20` (154-218), and `save` `00508BB0` (223-267).

## Evidence

- `plan_translation_unit.py --module task.cpp` listed six normal owners and
  1,876 normal bytes.
- Each prior matching source had a recorded `MATCH` result with zero
  positional differences and registered group `task_cpp` ownership.
- The original constructor writes the proven `RGE_Task` fields at offsets
  `0x00` through `0x48`. The complete object size is `0x4C` bytes.
- The natural source keeps the six definitions in PDB order. It replaces the
  wrapper and does not include C++ source fragments.
- `include/sprite.h` is the reviewed sprite module header. It proves named
  `RGE_Sprite::id` at `+0x72` and `RGE_Sound::id` at `+0x0C`.

The `save` body now includes `sprite.h` and reads those named fields. It no
longer uses raw cursor casts. The named accesses preserve the proven offsets.

## Source status

All six owners remain `matching`. No owner changed status during the move.
The lead must rerun the grouped check after it updates the registered source.

## Header dependency hold

`task.cpp` owns `RGE_Task` through `include/task.h`.
The task header uses natural compiler alignment for its `0x4C` layout.
It includes `<stdio.h>` for its public `FILE*` declaration.
It does not publish I/O declarations.

`src/task.cpp` includes canonical `rge_fio.h` for the C++ `rge_read` and
`rge_write` symbols. It also includes the reviewed sprite and sound owner
header.

`task_lst.cpp` now includes `task.h` and owns only `RGE_Task_List`.
It includes `rge_fio.h` directly for its I/O calls. Validate task, task-list,
and action consumers after this owner cleanup.

The grouped Task candidate now reports all six normal owners as `MATCH` with
`0.0000%` difference, zero relocation mismatches, and zero boundary escapes.
