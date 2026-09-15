# Source-cleanup wave 02: `src/tact_lst.cpp`

## Scope and commits

- Worker slot: 34.
- Branch: `cleanup/staging-20260915-34`.
- Module: `src/tact_lst.cpp`.
- Header read: `include/tact_lst.h`.
- Header owner: owner 04. This worker did not edit the header.
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`.
- Source cleanup commit: `95cd0b9be0302bb0c36e8193aaff717017c91c8f`.
- Final report commit: this report commit. Git output provides its full hash in the final handoff.
- Changed files: `src/tact_lst.cpp` and this report.

The source registry is `config/functions/src/tact_lst.cpp.json`. It assigns four
functions with `gx` flags. The PDB source path is
`C:\\msdev\\work\\age1_x1\\tact_lst.cpp`.

Evidence came from `inventory/pdb/scoped_symbols.json`, the four packets under
`inventory/functions/004D/`, `include/tact_lst.h`, the canonical action headers,
and `include/task.h`. The original executable reference is
`orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`,
SHA-256 `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
I did not execute this file.

## Function-by-function PDB inspection

I inspected parameters, locals, and registers for all four registry functions.
Each function has a PDB register record named `this` in `ecx` with type
`TRIBE_Action_List*`. The PDB has no source-local records for these functions.

| VA and body range | Function | PDB parameter records and source result |
| --- | --- | --- |
| `004D0150-004D0168` | `TRIBE_Action_List::TRIBE_Action_List` | `obj_in`, `RGE_Action_Object*`, stack `+0x4`; restored from PDB. |
| `004D0170-004D0516` | `TRIBE_Action_List::create_action` | `infile`, `int`, stack `+0x4`, and `action_type`, `short`, stack `+0x8`; restored from PDB. |
| `004D05D0-004D0BA7` | `TRIBE_Action_List::create_task_action` | `task`, `RGE_Task*`, stack `+0x4`; `target_obj`, `RGE_Static_Object*`, stack `+0x8`; `target_x`, `target_y`, and `target_z`, `float`, stacks `+0xC`, `+0x10`, and `+0x14`; restored from PDB. |
| `004D0C50-004D0D27` | `TRIBE_Action_List::get_action_name` | `action_name`, `char*`, stack `+0x4`; restored from PDB. |

Recovered original spellings are `obj_in`, `infile`, `action_type`, `task`,
`target_obj`, `target_x`, `target_y`, `target_z`, `action_name`, and the
implicit `this`. The PDB names use their original spelling. I did not normalize
them.

The previous source names `object`, `param`, `type`, `target`, `x`, `y`, `z`,
and `dest` were replaced by the PDB names above. The existing local
`const char* name` in `get_action_name` has no scoped PDB record. It is a concise
descriptive name, so it remains unchanged. The compiler SEH slots shown as
`local_4` and `local_c` in the inventory assembly have no source PDB names.
I did not map or rename them. No parameter or local declaration was added,
removed, merged, or split.

## Constants, strings, comments, and formatting

The action-type values remain numeric. The original assembly jump tables and
constructor calls prove the dispatch set: `3`, `0x0C`, `0x65`, `0x66`, `0x67`,
`0x68`, `0x69`, `0x6A`, `0x6B`, `0x6C`, `0x6E`, `0x6F`, and `0x78`. The original
assembly also proves the repair constructor's immediate `1` at `004D040F`.
No reviewed header provides symbols with the same proven roles and values.
The literals remain unchanged.

`include/task.h` places `RGE_Task::action_type` at offset `+0x06`. The original
assembly reads `[task + 0x06]` at `004D05EE`. The existing comment about this
read remains accurate.

`get_action_name` copies the existing literals `None`, `Enter`, `Transport`,
`Build`, `MakeObject`, `MakeTech`, `Convert`, `Heal`, `Repair`, `Artifact`,
`DiscoveryArtifact`, `Hunt`, and `Trade`. These are direct action-name strings,
not resource IDs. No comment was added. Existing practical comments remain.
Function definitions now use 1TBS braces. No statement order, control flow,
expression, type, cast, call, literal, scope, storage, or declaration point
changed.

## Resource evidence

This module has no resource lookup and no resource ID. Therefore no per-ID text,
missing block, empty slot, language, lookup path, purpose, or proposed cleanup
name applies. No resource macro or resource declaration changed.

For provenance, the checked resource inputs have these hashes:

- `runtime/language.dll`: SHA-256 `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`.
- `runtime/languagex.dll`: SHA-256 `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`.
- `orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`:
  SHA-256 `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`.

No ID was passed to a resource extraction tool because the module contains no
resource lookup.

## Header requests and unresolved questions

Owner 04 may add the recovered parameter names to `include/tact_lst.h` without
changing types, order, or ABI:

```cpp
TRIBE_Action_List(RGE_Action_Object* obj_in);
virtual RGE_Action* create_action(int infile, short action_type);
virtual RGE_Action* create_task_action(RGE_Task* task,
                                        RGE_Static_Object* target_obj,
                                        float target_x, float target_y,
                                        float target_z);
virtual void get_action_name(char* action_name);
```

No root-owned header or shared resource-ID request is pending. Open questions
are limited to the missing PDB name for the existing local `name` and the
compiler-only SEH slots. This cleanup leaves both mappings unchanged.

## Code-generation risk and validation

The edits rename parameters and move function braces. Parameter names do not
change ABI symbols, types, storage, calls, or expressions. Brace movement can
change debug line records. No compiler-output, program-data, relocation, or
direct-target comparison was run.

Compilation, matching, audits, and tests were not run. Games were not run.
Only evidence inspection and complete Git diff review were performed.
