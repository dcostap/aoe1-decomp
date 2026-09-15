# Source cleanup report: `src/tact_bld.cpp`

## Delivery

- Module: `src/tact_bld.cpp`
- Base commit from `git rev-parse`: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Final source commit from `git rev-parse`: `8043abb5cd11a955a90d4d6fcb66764ff22b0447`
- Branch: `cleanup/staging-20260915-39`
- Changed files: `src/tact_bld.cpp` and this report.
- Source registry: `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/tact_bld.cpp.json`
- Registry profile: `gx`
- Header read but not edited: `include/tact_bld.h`

The source registry assigns nine normal procedures to this module. The cleanup
keeps their source order, boundaries, calls, types, scopes, storage, and
statements. It changes PDB-proven parameter names, applies 1TBS formatting,
and removes stale source-evidence comments.

## Evidence

I read the complete cleanup guides and the assigned source and header. I
inspected every registry procedure in the scoped PDB record file:

`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`

The PDB source path is `C:\msdev\work\age1_x1\tact_bld.cpp`. Each assigned
procedure has a register record for `this` in `ecx`. The PDB function-static
list is empty for every assigned procedure. The stack records are listed in
the original-name table below.

I inspected these complete original inventory packets:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004CD1B0_TRIBE_Action_Build.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004CD210_TRIBE_Action_Build.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004CD2A0_TRIBE_Action_Build.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004CD2E0_first_in_stack.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004CD310_set_state.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004CD5E0_update.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004CD910_stop.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004CD920_move_to.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004CD960_work.txt`

The packets provide the original boundaries, assembly, PDB source line spans,
registers, and available source names. The original executable behavior
reference is:

`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`

The preserved pre-cleanup build for later comparison is:

`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/`

No resource lookup occurs in this module. I did not inspect
`C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll` or
`C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`, and no resource
ID evidence or extraction is required.

## Original-name recovery

The following names are recovered from procedure-scoped PDB stack records.
The `this` register is `ecx` for every row.

| VA | Function | PDB stack names and coverage |
| --- | --- | --- |
| `004CD1B0` | `TRIBE_Action_Build::TRIBE_Action_Build(int, RGE_Action_Object*)` | `infile`, `obj_in` |
| `004CD210` | `TRIBE_Action_Build::TRIBE_Action_Build(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*)` | `obj_in`, `task_in`, `target_obj_in` |
| `004CD2A0` | `TRIBE_Action_Build::TRIBE_Action_Build(RGE_Action_Object*, RGE_Task*, float, float, float)` | `obj_in`, `task_in`, `x`, `y`, `z` |
| `004CD2E0` | `first_in_stack` | `first_time` |
| `004CD310` | `set_state` | `new_state` |
| `004CD5E0` | `update` | local `work` |
| `004CD910` | `stop` | no stack names |
| `004CD920` | `move_to` | `obj_in`, `x`, `y`, `z` |
| `004CD960` | `work` | `obj_in`, `x`, `y`, `z` |

The source restores these PDB spellings:

- `id` became `infile`, and `object` became `obj_in` in the first
  constructor.
- `action_obj`, `task`, and `target` became `obj_in`, `task_in`, and
  `target_obj_in` in the target constructor.
- `file` and `task` became `obj_in` and `task_in` in the position constructor.
- `value` became `first_time` in `first_in_stack`.
- `param_1` became `new_state` in `set_state`.
- `obj` became `obj_in` in `move_to`.
- `target`, `param_2`, `param_3`, and `param_4` became `obj_in`, `x`, `y`,
  and `z` in `work`.
- `work` in `update` already matched the PDB local name.
- `x`, `y`, and `z` already matched the PDB names in the position constructor,
  `move_to`, and `work`.

The PDB packets also show compiler-generated EH stack homes such as `local_4`
and `local_c` in the original listings. They are not source declarations and
have no procedure-scoped source names in `scoped_symbols.json`; I did not map
them to source locals.

The PDB includes compiler-generated deleting and non-deleting destructor
records at `004CD1E0` and `004CD200`. They are not normal source registry
functions and were not edited.

## Inferred names and unresolved mappings

The PDB has no source-local record for `move_to` in `set_state`. The source
keeps the existing descriptive `move_to` pointer name.

The PDB has no source-local record for `target_owner` or `action` in `work`.
The source keeps these existing descriptive names. The existing identity
conjunct `target_owner == obj_in->owner` remains unchanged. It preserves the
observed owner-read order and is not a new semantic simplification.

No PDB parameter or named local from the table remains unresolved. The three
unrecorded source locals above are not claimed as recovered original names.
No reused stack-slot mapping was forced.

## Constants, resources, and comments

No numeric constant, enum, resource macro, type, or literal changed. Existing
state values, notification values, sentinels, casts, floating-point suffixes,
and the building ID comparison remain unchanged.

This module has no resource lookup. No resource ID was requested, renamed, or
added. No resource header request exists.

I added no source comment. I removed the incomplete constructor note and the
non-specific state note. Detailed evidence remains in this report. The source
now uses 1TBS function braces and avoids unnecessary signature wrapping.

## Code-generation, type, layout, and symbol review

The edits rename identifiers, change brace placement, adjust signature
presentation, and remove comments. They do not change parameter or local
types, declaration scope, storage duration, statement order, evaluation order,
control flow, calls, literals, function boundaries, relocations, or ABI
symbols. No helper, wrapper, layout change, assembly, or bug repair was added.

The module registry statuses remain unchanged: matching for
`004CD1B0`, `004CD210`, `004CD2A0`, `004CD2E0`, `004CD310`, `004CD910`,
`004CD920`, and `004CD960`; accepted drift for `004CD5E0`. This report does
not promote or demote any status.

Formatting and comment changes can alter debug line records. The final
compiler and executable checks remain deferred.

## Header requests

`include/tact_bld.h` was read and not edited. Owner 05 controls that header.
The owner may add these PDB-proven parameter names without changing types,
order, virtual slots, layout, or symbols:

```cpp
TRIBE_Action_Build(int infile, RGE_Action_Object* obj_in);
TRIBE_Action_Build(RGE_Action_Object* obj_in, RGE_Task* task_in,
                   RGE_Static_Object* target_obj_in);
TRIBE_Action_Build(RGE_Action_Object* obj_in, RGE_Task* task_in,
                   float x, float y, float z);
virtual void first_in_stack(unsigned char first_time);
virtual void set_state(unsigned char new_state);
virtual int move_to(RGE_Static_Object* obj_in, float x, float y, float z);
virtual int work(RGE_Static_Object* obj_in, float x, float y, float z);
```

No root-owned header or shared declaration request exists.

## Validation

I ran `git diff --check` and reviewed the complete source diff. I also ran the
required `--help` commands for the available evidence and audit tools before
inspection. Compilation, matching, audits, and tests were not run. No build,
compiler check, game, runtime harness, or audit command was run.
