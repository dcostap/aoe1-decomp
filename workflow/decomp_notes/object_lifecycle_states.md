# Object lifecycle state names

## Scope

`include/stat_obj.h` defines constants for the stored object lifecycle and related search filters.
These names describe the recovered behavior. They are not recovered original constant names.
PDB data does not establish whether the original source used literals, macros, or enum constants.

The cleanup replaces 283 numeric operands in 46 source files.
It also names one implicit zero check and updates one related bug comment.
It covers state assignments, comparisons, switch labels, scenario input checks, cached states, and object-search arguments.
Action states, game states, object groups, and search-enable flags remain separate.

## Values and evidence

The original executable is the behavior source.
The main instruction evidence is `RGE_Static_Object::update` at `004C3C70` and `RGE_Animated_Object::update` at `0041A350`.
Their extracted instructions are in `build/asm/orig_004C3C70_update.txt` and `build/asm/orig_0041A350_update.txt`.
Building setup and completion paths supply the construction-state meaning.

| Value | Constant suffix | Observed role |
| --- | --- | --- |
| -1 | `ANY` | An integer search filter that accepts any object state. It is not a stored lifecycle state. |
| 0 | `UNBUILT` | Building setup selects this state. Construction completion selects state 2. Transform also uses 0 before activation. |
| 2 | `ACTIVE` | Normal setup selects this state. Completed buildings use this state. |
| 3 | `DYING` | The object starts death processing. Animated objects select the death animation or proceed to state 5. |
| 4 | `DEATH_ANIMATION` | The object waits for its death animation to finish, then enters state 5. |
| 5 | `DEAD` | The death animation is complete or absent. Static update can retain resources, select state 6, or select state 7. |
| 6 | `UNDEAD` | Static update selects the undead sprite when the master has `undead_flag`. Worker-release logic also handles this state. |
| 7 | `PENDING_REMOVAL` | Static update advances this state to 8. Target checks commonly reject states at or above this value. |
| 8 | `READY_TO_REMOVE` | Static update returns removal or recycling results. Timeline and map checks also use this boundary. |

Value 1 remains unnamed. The inspected lifecycle paths do not establish its meaning.
The editor also uses state 7 while moving an object, then restores state 2.
Thus, the names describe the lifecycle meaning, not every temporary use of each value.

State 7 does not mean only that an object is dead.
States 3 through 6 can remain below the removal boundary.
`RGE_Static_Object::is_dying` also excludes state 6 from its dying-state result.
Do not replace existing ordered comparisons with a general alive/dead predicate.

## Storage and interface preservation

PDB layout evidence places `RGE_Static_Object::object_state` at offset `0x48` with one-byte storage.
The field remains `unsigned char`.
State setters and search interfaces retain their existing parameter types.
The header supplies numeric macros only. It does not replace stored fields or change function declarations.

The cleanup retains every comparison operator, switch fallthrough, and search-enable flag.
It retains redundant guards and existing scenario behavior.
Search calls with disabled state filters keep their unused zero arguments.
The unsigned `0xFFFFFFFF` filter uses an explicit unsigned conversion of `RGE_OBJECT_STATE_ANY`.
This preserves the original operand type before conversion to the function parameter type.

## Why these constants use macros

The first pass used a named enum in `stat_obj.h`.
The fresh audit found eight regressions among matching functions and one missing include.
The enum also changed code in functions whose source had not changed.
For example, `RGE_Map::get_border_type` kept the same operations but changed registers for two byte-field updates.

Moving the enum after the class did not remove those eight regressions.
An anonymous enum also retained them.
Those rejected reports remain in `after/`, `probe-enum-after-class/`, and `probe-anonymous-enum/` under the run directory.

Numeric macros expand to the original operands before compilation.
They avoid the added enum declarations while retaining named values at each use.
This is an output-preservation choice, not evidence of the original source form.

A new constants header still changed output in six matching functions.
That report remains in `final/functions/` under the run directory.
The selected form keeps the macros in the existing `stat_obj.h` header.
The diplomacy dialog includes this header directly because it uses an active-state search filter.

## Validation

The pre-cleanup baseline is commit `e71496459bb7416a203f67ed80273f7b1e3842d5`.
Reports remain under `build/object-state-cleanup/`.

| Check | Result | Report |
| --- | --- | --- |
| Registry configuration | Passed with `--no-build-checks`. This does not check compiled artifacts. | Tool output. |
| Pre-cleanup full function audit | Exit 0. All 225 groups compiled; 5,013 exact claims passed. | `before/functions/report.json` |
| Final full function audit | Exit 0. All 225 groups compiled; 5,013 exact claims passed. | `final-existing-header/functions/report.json` |
| Before/after object comparison | Exit 0. All 225 objects retain identical non-debug section bytes, sizes, flags, and relocation targets. | `object-comparison-final.json` |
| Final owner audit | Exit 0. No owner mismatches, class/free mismatches, or repair entries among 5,013 matching functions. | `final-existing-header/owners.json` |
| Source-scope check | Exit 0. Restoring the numeric operands and the reviewed zero check restores all 47 existing source/header files exactly. | `source-scope.json` |
| Whitespace and line endings | `git diff --check` and the line-ending check passed. | Tool output. |

The object comparison also checks owning symbols and external relocation symbol names.
It identifies private compiler labels by section and offset, not their generated serial numbers.
It excludes debug sections and COFF timestamps.
This establishes unchanged compiled payloads relative to the pre-cleanup source, not full agreement with the original game.

Both full audits include 5,426 normal functions.
The remaining 413 observations retain the same categories: 217 logic-approved, 140 accepted-drift, 44 mismatches, and 12 boundary problems.
Their existing limits remain. External linked storage and runtime behavior are not established by these checks.

No linked executable, automated regression tests, or gameplay tests have run for this cleanup.
The cleanup does not fix or reproduce the previously documented patch-readme bugs.
