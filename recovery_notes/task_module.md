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

## ABI request

This module needs no action declaration. It uses only opaque sprite and sound
pointers. It defines no `RGE_Action`, `RGE_Action_Object`, or task-list
substitute.

The action.cpp captain must publish the canonical action header. That header
should provide the proven action and action-object declarations used by
`action.cpp` and its consumers. It should include `task.h` for `RGE_Task`
rather than define another task class.

The current `include/action_context.h` is temporary codegen evidence. It
contains an incomplete `RGE_Task` and task-list surface. The task-list module
also has a local `RGE_Task` declaration in `include/task_lst.h`. Do not use
`include/act_list.h` as a canonical declaration. The coordinator should replace
these duplicate surfaces after the action header is available.

The task-list context also declares `rge_read` as returning `int`. This module
uses the binary-supported `void` declaration in `task.h`. The coordinator must
choose one shared declaration before headers are combined.

Affected modules are `action.cpp` and `task_lst.cpp`, plus consumers of their
current context headers. The proposed change is declaration-only. Validate the
fanout with the action, task-list, and task grouped checks, then run the normal
shard checkpoint. This request is non-blocking for task.cpp.
