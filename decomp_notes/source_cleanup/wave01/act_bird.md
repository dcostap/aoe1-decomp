# `act_bird.cpp` source-cleanup report

## Commits and scope

- Module: `src/act_bird.cpp`
- Base commit: `ad338a7faf75ffdfff8fec846133b4aa8da3fa44`
- Final source commit: `376683569b6e697dea37c675f785e5febf10ba19`.
- Correction commit: `8dd0da75c00c027506dcf0291d908223369e3dd5`.
- Prior report commit: `b9f13d6b5325d41315426e2f4cb3554fd3d108af`.
- Changed files: `src/act_bird.cpp`; this report.
- Header request only: `include/act_bird.h` remains unchanged.
- Registry: `config/functions/src/act_bird.cpp.json`, build flags `gx`.
- Assigned registry functions: `00401FE0`, `00402040`, `00402080`, `004020C0`, and `00402180`.

Evidence uses the shared `inventory/pdb/scoped_symbols.json` and the five matching
function packets under `inventory/functions/0040/`. The original executable used
as the behavior oracle has SHA-256
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.

## Original-name recovery

All five assigned source functions were inspected. PDB register records name
`this` as `RGE_Action_Bird*` in `ecx` for every function.

- `00401FE0`, first constructor: restored `infile` and `obj_in` from PDB
  stack records at `+0x4` and `+0x8`. The packet gives `int` and
  `RGE_Action_Object*` types. The caller packet for `create_action` calls this
  constructor with the file argument and owning action object.
- `00402040`, task constructor: restored `obj_in`, `task_in`, `x`, `y`, and
  `z` from PDB stack records at `+0x4`, `+0x8`, `+0xc`, `+0x10`, and `+0x14`.
  The PDB gives the two pointer types and three `float` types. The caller
  packet for `create_task_action` passes the object, task, and three coordinates.
- `00402080`, `first_in_stack`: restored `first_time` from the PDB unsigned
  char stack record at `+0x4`.
- `004020C0`, `set_state`: restored `new_state` from the PDB unsigned char
  stack record at `+0x4`.
- `00402180`, `update`: PDB has only the `this` register record and no stack
  parameter or local records. Its source signature remains parameterless.

The source changes only identifier spellings and the permitted signature wrap.
They do not change types, declarations, scopes, storage, order, expressions, or
calls.

## Locals and unresolved mappings

The source already used concise descriptive names for locals: `obj`, `sprite`,
`map`, and `move_to`. These names have no corresponding PDB local records and
were not presented as recovered originals. `bird_update_zero` is an existing
source-level name; the PDB has no function-static record for it. No invented
local name was added.

The `00402180` Ghidra packet shows `local_4`, `local_c`, and `local_10`, plus
register temporaries. `local_10` is reused for both random-coordinate integer
conversion and the allocation result. PDB data does not provide source names
for these slots, so the source does not force a mapping. The exception-chain
slots remain compiler/decompiler artifacts outside the source declarations.

The module also has generated functions at `00402010` and `00402030`. The PDB
records `__flags` and `this` for the scalar deleting destructor at `00402010`,
and `this` only for the destructor at `00402030`. They have no standalone
source bodies in this module and were not edited.

## Constants, resources, and comments

No new constant, resource ID, or comment was added. This module has no resource
lookup. Existing state values `3`, `4`, and `6`, action type `10`, and random
call-site values `0x44`, `0x4C`, `0x84`, and `0x85` remain unchanged. The
`004020C0` and `00402180` packets show the original integer arithmetic and the
aligned double-zero comparison at original address `0056E138`; the existing
`bird_update_zero` declaration preserves that source form.

## Header request

The owner of `include/act_bird.h` may add the PDB-proven parameter names without
changing the public types or ABI:

```cpp
RGE_Action_Bird(int infile, RGE_Action_Object* obj_in);
RGE_Action_Bird(RGE_Action_Object* obj_in, RGE_Task* task_in, float x, float y, float z);
virtual void first_in_stack(unsigned char first_time);
virtual void set_state(unsigned char new_state);
```

The current unnamed declarations are valid and do not block this source cleanup.
No resource-ID or shared-header request is open.

## Risk and validation

The edits do not affect types, layout, symbol identity, calls, relocations, or
runtime data by source inspection. Compilation, matching, audits, and tests were
not run, as required for this cleanup wave.
