# wave02 tact_hea.cpp cleanup report

## Scope and commits

- Worker: managed run `sa-897d5059-r1`, slot 42, owner 05.
- Module: `src/tact_hea.cpp`.
- PDB source: `C:\\msdev\\work\\age1_x1\\tact_hea.cpp`.
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`.
- Final module source commit: `1f308253f8f735dbc8a533d47d50aba9e4837db4`.
- Changed files:
  - `src/tact_hea.cpp`
  - `decomp_notes/source_cleanup/wave02/tact_hea.md`
- `include/tact_hea.h` was read but not changed.

The source registry at
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/slot-42/config/functions/src/tact_hea.cpp.json`
assigns this module seven normal owners in address order. The registry gives
all seven `matching` status and build flags `gx`. This cleanup changes names
only. It does not change those registry claims.

## Original-name recovery coverage

The scoped PDB evidence is
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
The selected function packets are under
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/`.
Every source-owned procedure has one `this` register symbol in `ecx` with type
`TRIBE_Action_Heal*`. No source-owned procedure has a function-static symbol.

| VA | Procedure | PDB parameters and locals | Source cleanup |
| --- | --- | --- | --- |
| `004CE930` | `TRIBE_Action_Heal::TRIBE_Action_Heal` | `infile: int`, `obj_in: RGE_Action_Object*` | Recovered `id` as `infile`; recovered `object` as `obj_in`. |
| `004CE990` | `TRIBE_Action_Heal::TRIBE_Action_Heal` | `obj_in: RGE_Action_Object*`, `task_in: RGE_Task*`, `target_obj_in: RGE_Static_Object*` | Recovered `obj` as `obj_in`, `task` as `task_in`, and `target` as `target_obj_in`. |
| `004CEA10` | `TRIBE_Action_Heal::TRIBE_Action_Heal` | `obj_in: RGE_Action_Object*`, `task_in: RGE_Task*`, `x: float`, `y: float`, `z: float` | Recovered `obj` as `obj_in` and `task` as `task_in`. Existing `x`, `y`, and `z` already matched. |
| `004CEA50` | `TRIBE_Action_Heal::first_in_stack` | `first_time: unsigned char` | Recovered the unnamed parameter as `first_time`. |
| `004CEA90` | `TRIBE_Action_Heal::set_state` | `new_state: unsigned char` | Recovered `state` as `new_state` for the parameter and switch expression. The member `this->state` remains unchanged. |
| `004CECF0` | `TRIBE_Action_Heal::update` | local `work: float` at stack offset `-0x4` | Existing local `work` matched. No parameter exists. |
| `004CF030` | `TRIBE_Action_Heal::work` | `obj_in: RGE_Static_Object*`, `x: float`, `y: float`, `z: float` | Recovered `target` as `obj_in` and the three unnamed parameters as `x`, `y`, and `z`. |

The compiler-generated scalar deleting destructor at `004CE960` is not a
source owner. Its PDB record has `__flags: unsigned int` and `this` in `ecx`;
no source declaration was changed.

The PDB has no scoped names for the existing local `kind` in
`first_in_stack`, the `move_to` temporaries, the `distance` local, the
`result` local, or the `state` local in `work`. I left these mappings unchanged.
No reused stack-slot mapping required a forced rename. No invented names were
added. All changed names are recovered PDB spellings.

## Behavioral and symbolic evidence

The seven selected packets record the same owner class, calling convention,
source path, address order, and parameter types as the current definitions.
Their original assembly shows the renamed parameters at the same stack
positions. The current source preserves the constructor calls, target field
loads, state transitions, sub-action calls, notification IDs, floating-point
literals, explicit casts, declaration order, and return values.

No new constants or resource IDs were added. No resource extraction was
needed. Existing numeric state values, notification values, and `DAT_005750e0`
and `DAT_005750e8` declarations remain unchanged. No noteworthy source
comment was added or removed.

No new shared declaration is requested from owner 05. In particular, there is
no request for `include/tact_hea.h`, `include/resource_ids.h`, or another
header.

## Risk and unresolved items

The edits change parameter and one local identifier spelling only. They do not
change types, scopes, storage, class layout, ABI symbols, call targets,
expressions, literals, or evaluation order. The unused recovered parameters
`first_time`, `x`, `y`, and `z` remain unused, as they were before cleanup.

The two previously documented non-exact body owners, `004CEA90` and
`004CECF0`, remain source owners with no status promotion. Their source
structure and canonical dependencies were not rewritten.

The following evidence was not needed for this name-only cleanup and was not
inspected: original executable
`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`,
current resources `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`
and `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`, expansion
reference
`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`,
and preserved baseline
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/`.

Compilation, matching, audits, and tests were not run. No compiler, build,
matching, audit, test, or game command was run. Git diff review and
`git diff --check` were run.
