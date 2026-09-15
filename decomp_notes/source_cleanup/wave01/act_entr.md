# `act_entr.cpp` cleanup report

## Scope and commits

- Module: `src/act_entr.cpp`
- Header read: `include/act_entr.h`
- Base commit: `ad338a7faf75ffdfff8fec846133b4aa8da3fa44`
- Source cleanup commit: `68033d452b2e3ee60d74d444bb4f66e9e16d1655`
- Report commit: `c63f5d9aba2f1b3525256b3137d9f16293fa8f37`
- Style correction commit: `492989668d2779d488659dfc9425d8fa3e8e55b7`
  (joins the three-parameter constructor definition and report declaration).
- Changed files: `src/act_entr.cpp` and this report.
- No registry or header file changed.

Evidence came from `inventory/pdb/scoped_symbols.json`, the six packets under
`inventory/functions/0040/`, the source header, and the existing act_entr notes.
The PDB source is `C:\\msdev\\work\\age1_x1\\act_entr.cpp`.

## Function-by-function name coverage

All six registry functions were inspected. Every PDB parameter and local record
was checked, including each register record. Each function has a PDB register
record named `this` in `ecx`.

- `004023C0` `RGE_Action_Enter(int, RGE_Action_Object*)`: restored `infile`
  and `obj_in` from PDB stack records at `+0x4` and `+0x8`. The implicit
  register name `this` was already present.
- `00402410` `RGE_Action_Enter(RGE_Action_Object*, RGE_Task*,
  RGE_Static_Object*)`: restored `obj_in`, `task_in`, and `target_obj_in`
  from PDB stack records at `+0x4`, `+0x8`, and `+0xc`. The PDB stack records
  also establish `start` at `-0x1c`, `rVal` at `-0x14`, and `dest` at
  `-0x24`. The source local previously named `result` is now `rVal`.
- `004025F0` `~RGE_Action_Enter()`: no source parameter or local records beyond
  the implicit register `this`; no name change was needed.
- `00402600` `first_in_stack(unsigned char)`: restored `first_time` from the
  PDB stack record at `+0x4`.
- `00402610` `set_state(unsigned char)`: restored `new_state` from the PDB
  stack record at `+0x4`.
- `00402740` `update()`: the PDB has no source parameters. It establishes
  `start` at `-0x10`, `rVal` at `-0x8`, and `dest` at `-0x18`. The nested
  `XYPoint` local previously named `result` is now `rVal`.

Recovered original spellings are `infile`, `obj_in`, `task_in`,
`target_obj_in`, `start`, `dest`, `rVal`, `first_time`, and `new_state`.
The PDB names retain their original mixed style. No name was normalized.

The PDB does not provide source records for `action`, `target_action`,
`move_to`, the sub-action `result`, or the `x` and `y` locals. These names were
left unchanged. The source does not force mappings for the compiler's SEH
records or reused register slots.

## Constants, resources, comments, and formatting

- No constants or resource IDs were added or changed.
- No resource lookup occurs in this module.
- No comment was added. The existing fall-through comment remains.
- Function braces now use 1TBS. No statement order, scope, type, cast, call,
  control flow, storage, or declaration point was changed.

## Concerns and requests

The edits change parameter and local spellings only, plus brace placement.
They do not intentionally change type, layout, code generation inputs, or
symbol identity. Validation was deferred, so generated code and debug-line
results remain unverified.

Header owner 01 request: update `include/act_entr.h` declaration names to match
PDB records without changing types or ABI:

```cpp
RGE_Action_Enter(int infile, RGE_Action_Object* obj_in);
RGE_Action_Enter(RGE_Action_Object* obj_in, RGE_Task* task_in, RGE_Static_Object* target_obj_in);
virtual void first_in_stack(unsigned char first_time);
virtual void set_state(unsigned char new_state);
```

No root-owned header or shared resource mapping request is pending.

Compilation, matching, audits, and tests were not run. Games were not run.
