# m_ac_obj.cpp source-module recovery

## Context

The PDB source is `C:\\msdev\\work\\age1_x1\\m_ac_obj.cpp`.
The compiler-facing owner is `src/m_ac_obj.cpp`.
The module has 19 normal owners and 2,208 normal bytes.
The normal owners remain in PDB source order:

- `0044F070`, `0044F0F0`, and `0044F160`: constructors
- `0044F1E0`, `0044F290`, and `0044F3C0`: `setup` overloads
- `0044F4D0`: destructor
- `0044F540`: `create_task_list`
- `0044F5A0`: `make_new_obj`
- `0044F670`: `make_new_master`
- `0044F6E0`: `get_task`
- `0044F710`: `getTaskByTaskID`
- `0044F760`: `copy_obj`
- `0044F7F0`, `0044F820`, and `0044F850`: attribute modifiers
- `0044F880`: `save`
- `0044F980` and `0044F9A0`: sound playback methods

The PDB also lists `0044F0D0` as a compiler-generated vector-deleting
destructor. It is not a normal source owner.

## Canonical source surface

The source uses canonical owner headers for the action object, player, world,
static object, sound, task list, and action-master dependencies.
It uses `include/rge_fio.h` for the period file-I/O declarations.
It has no local provider class or local file-I/O declaration.

The destructor uses ordinary `delete` on the task list. The text-file setup
loop uses the task-list index and keeps the signed `int` task-count conversion.
These forms remove the decompiler-only task pointer and preserve the original
VC5 output.

## Validation

The pinned VC5 candidate build uses
`config/flags/gx.rsp`.
The grouped candidate check reports 19/19 exact normal owners.
Every owner reports `Result: MATCH`, `0.0000%`, the expected owner symbol,
zero relocation mismatches, and zero boundary escapes.
