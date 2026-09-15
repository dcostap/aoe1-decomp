# `src/tact_art.cpp` cleanup report

## Delivery

- Module: `src/tact_art.cpp`
- Base commit from `git rev-parse`: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Initial source cleanup commit: `090e0786883cfbe4be0aee489a8b5e87dde3a9a2`
- Initial report commit: `6b01a8587e6fa0c46048417b5d49413a3fd6f904`
- Source correction commit: `42d0dd0c951809c8a7d8638d2b02ae194facc46a`
- Prior report correction commit: `1a38a2845d0a38ece118a96868a1fdfa74b9d67c`
- Source formatting commit: `0ac4143be02f2c3e71725d8cb6c1e5edd5fdacd7`
- Final source commit from `git rev-parse`: `0ac4143be02f2c3e71725d8cb6c1e5edd5fdacd7`
- Final source head before this report update: `0ac4143be02f2c3e71725d8cb6c1e5edd5fdacd7`
- Branch: `cleanup/staging-20260915-38`
- Changed files:
  - `src/tact_art.cpp`
  - `decomp_notes/source_cleanup/wave02/tact_art.md`
- Header read but not changed: `include/tact_art.h`

The source keeps the registry order for all 11 normal owners. The PDB source
module is `C:\\msdev\\work\\age1_x1\\tact_art.cpp`.

## Evidence

The source registry selected these procedure records:

- `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/tact_art.cpp.json`

The PDB scope records were read from:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`

The original function packets were read from:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004CCBA0_TRIBE_Action_Artifact.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004CCC00_TRIBE_Action_Artifact.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004CCC30_TRIBE_Action_Artifact.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004CCC70_first_in_stack.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004CCCB0_set_state.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004CCDF0_update.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004CCF30_check_ownership.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004CD120_stop.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004CD130_move_to.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004CD160_work.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004CD1A0_reset_owner.txt`

The original executable and preserved baseline were retained as reference inputs:

- Original PE: `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`
  - SHA256: `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`
- Baseline PE: `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/empiresx.exe`
  - SHA256: `492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`
- Runtime base language: `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`
  - SHA256: `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`
- Runtime expansion language: `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`
  - SHA256: `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`
- Original expansion language: `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`
  - SHA256: `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`

The packets confirm each original function boundary, source line span, and call
shape. The original executable remains the behavior oracle.

## Original-name recovery coverage

All 11 registry functions were inspected. Each procedure scope was checked for
its parameters, locals, and registers. Every procedure had the expected PDB
`this` register record in `ecx`.

| VA | Function | PDB names and source result |
| --- | --- | --- |
| `004CCBA0` | load constructor | Recovered `infile` and `obj_in`. |
| `004CCC00` | target constructor | Recovered `obj_in`, `task_in`, and `target_obj_in`. |
| `004CCC30` | position constructor | Recovered `obj_in`, `task_in`, `x`, `y`, and `z`. |
| `004CCC70` | `first_in_stack` | Recovered `first_time`. |
| `004CCCB0` | `set_state` | Existing `new_state` matches the PDB name. No named PDB local remains. |
| `004CCDF0` | `update` | No stack parameter or local names are present in the PDB. Existing descriptive locals remain. |
| `004CCF30` | `check_ownership` | Existing `map`, `map_x`, `map_y`, `player_num`, `player_list`, `x0`, and `y0` remain. The packet does not prove an `x1` declaration mapping. |
| `004CD120` | `stop` | No stack parameter or local names are present in the PDB. |
| `004CD130` | `move_to` | Recovered unused `obj_in`; `x`, `y`, and `z` already match the PDB. |
| `004CD160` | `work` | Recovered `obj_in`, `x`, `y`, and `z`. |
| `004CD1A0` | `reset_owner` | No stack parameter or local names are present in the PDB. |

The PDB has no named locals for `update`. The source keeps its existing
`val`, `obj`, `speed`, and `owner` names. The PDB has no named locals for the
new-object temporaries in `set_state`; the source keeps `move`.

In `check_ownership`, the packet warns that `x1` is unmapped and that its PDB
home has no XREFs. The lower-bound expression uses reused stack homes that are
later labeled `map`. Conversion order does not prove a declaration mapping.
The source therefore restores the baseline `map_x` spelling. The source keeps
`x0` because direct evidence exists at packet address `004CCF80`. The source
also keeps `map_y` and `y0`; their original spellings are unresolved. The
source keeps existing inferred names such as `obj`, `master`, `best_player`,
`unique_owner`, `player`, `node`, `entity`, `type`, `x`, and `y`. These are
cleanup names, not recovered original names.

No reused stack-slot mapping was forced for `x1`, `map_x`, or the unresolved
vertical bounds.
No type, scope, declaration order, or storage duration changed.

## Constants, resources, and comments

No numeric constant changed. No constant or enum was added. Existing state
values, action type `0x6B`, object-group values, and sentinel bits remain
literal because no shared declaration proves their effective type and meaning
for this module.

This module has no resource lookup. No resource ID was requested. The runtime
language files and original expansion language file were not queried for IDs.
No resource header request exists.

No source comment was added. The existing comment for the raw four-byte float
comparison remains. It records behavior shown by the original assembly and
does not claim a source-level intent.

## Code generation, type, layout, and symbol review

The source changes rename parameters. The correction restores `map_x` for the
uncertain lower bound. The formatting commit changes whitespace only. These
changes do not change types,
casts, declaration scope, statement order, control flow, calls, literals,
function boundaries, layout, relocations, or ABI symbols. The unused
`move_to` parameter keeps its original type and position. The `x1` change
was reverted because the packet does not prove its declaration mapping. The
`map_x` spelling keeps the baseline `short` declaration.

The formatting commit aligns continuation parameters in both multiline
constructors with the first parameter.

No inline assembly, wrapper, helper, or structural rewrite was added.

## Header request

Owner 05 controls `include/tact_art.h`. Please consider these declaration-name
changes. They do not change types or ABI signatures:

```cpp
TRIBE_Action_Artifact(int infile, RGE_Action_Object* obj_in);
TRIBE_Action_Artifact(RGE_Action_Object* obj_in, RGE_Task* task_in,
                      RGE_Static_Object* target_obj_in);
TRIBE_Action_Artifact(RGE_Action_Object* obj_in, RGE_Task* task_in,
                      float x, float y, float z);
virtual void first_in_stack(unsigned char first_time);
virtual void set_state(unsigned char new_state);
virtual int move_to(RGE_Static_Object* obj_in, float x, float y, float z);
virtual int work(RGE_Static_Object* obj_in, float x, float y, float z);
```

No root-owned header request exists. No shared resource request exists.

## Validation and open risks

`git diff --check` passed for the source and formatting corrections. The
complete cumulative diff was reviewed. The correction history is recorded
above.

The broad source shape and generated-name limits in `check_ownership` remain
outside this name cleanup. The vertical-bound original names are unresolved.

Compilation, matching, audits, and tests were not run. No build, compiler
check, game, or runtime harness was run.
