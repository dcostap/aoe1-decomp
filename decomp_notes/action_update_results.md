# Action update result names

## Scope

Baseline commit: `d87224c44d4e4cf592c650eb0ffc14d6edf7d21d`.

Name the byte results from `RGE_Action::update()` and its action overrides.
Use the same names in action-list results and their callers.
Keep `unsigned char`, `uchar`, and existing caller storage unchanged.

The names below are descriptive cleanup names, not recovered original macro names.
Define numeric macros in the existing `include/action.h` to preserve literal types and VC5 compiler context.

| Value | Name | Supported meaning |
| --- | --- | --- |
| 0 | `RGE_ACTION_UPDATE_CONTINUE` | Continue the action without a terminal result. |
| 1 | `RGE_ACTION_UPDATE_REMOVE` | Remove the action. An empty action list also returns this value. |
| 2 | `RGE_ACTION_UPDATE_COMPLETED` | Report completion. This value does not itself cause action-list removal. |
| 3 | `RGE_ACTION_UPDATE_FAILED` | Report action failure. |
| 4 | `RGE_ACTION_UPDATE_TARGET_INVALID` | Report an invalid target to the caller. |
| 5 | `RGE_ACTION_UPDATE_TARGET_LOST` | Report a lost target to a parent action. See the attack exception below. |

## Evidence and distinctions

The original executable supplies the behavior evidence. The local assembly listings expose its instructions.

- `orig/ghidra_decomp/act_atak.cpp.asm`, `RGE_Action_Attack::update`, starts at `00401780`.
  Missing or dying targets produce 5 at `004017F3`.
  Allied or contained targets produce 4 at `004018E6`.
  Failure produces 3 at `004018AA`. The ordinary continuing path clears `AL` at `004018B0`.
  The completion-animation path clears the target and selects 5 for a sub-action, otherwise 2, at `00401A77`.
  Therefore, `TARGET_LOST` does not always mean that the target disappeared outside the action.
- `orig/ghidra_decomp/act_list.cpp.asm`, `RGE_Action_List::update`, starts at `004044F0`.
  The empty list returns 1 at `004044FC`.
  The list compares its action result with 1 at `00404527` and removes that action at `0040452E`.
  It does not remove an action merely because its result is 2.
  `inside_obj_update()` uses the same removal result at `004044D1`.
- `orig/ghidra_decomp/act_move.cpp.asm`, `RGE_Action_Move_To::update`, starts at `00405850`.
  Reaching the target sends a completion notification and returns 2 at `0040595C`.
  A lost target produces 5 for a sub-action, otherwise a target-invalid notification and 4.
- Existing callers preserve distinct policies.
  `RGE_Action_Object::update()` removes on 3 or 1.
  `TRIBE_Building_Object::update_production_queue()` handles 3, 2, or 1.
  Training and research actions return 1 after completion, rather than changing their result to 2.

Action states, object-update results, and `heal()` results are separate numeric domains.
Their literals remain unchanged. Keep range checks, masks, subtraction, casts, and control flow unchanged.
The base `idle_update()` result remains numeric because callers discard that result.

## Changed files

Header: `include/action.h`.

Source owners:

- `src/act_atak.cpp`, `src/act_bird.cpp`, `src/act_entr.cpp`, `src/act_expl.cpp`
- `src/act_gath.cpp`, `src/act_list.cpp`, `src/act_make.cpp`, `src/act_misl.cpp`
- `src/act_move.cpp`, `src/act_obj.cpp`, `src/act_tran.cpp`, `src/action.cpp`
- `src/t_b_obj.cpp`, `src/tact_art.cpp`, `src/tact_bld.cpp`, `src/tact_cnv.cpp`
- `src/tact_dar.cpp`, `src/tact_hea.cpp`, `src/tact_hnt.cpp`, `src/tact_mob.cpp`
- `src/tact_rep.cpp`, `src/tact_tek.cpp`, `src/tact_trd.cpp`, `src/tact_wnd.cpp`

This report is `decomp_notes/action_update_results.md`.

## Validation

Report root: `build/action-result-cleanup/`.

The preserved baseline build is
`build/constant-cleanup-validation/validated-executable/20261004T151049994606Z/`.
Before editing, all 576 recorded baseline input hashes matched current inputs.
See `baseline-inputs.json`.

The cleanup replaces 351 literal uses across 24 source owners.
Expanding the six macros back to their numeric values restores every source file byte for byte.
See `source-scope.json`. The header adds only definitions and comments.

Final build:
`build/action-result-cleanup/executable/20261004T165543157287Z/`.
All 576 recorded compiler input hashes still match current files. See `final-inputs.json`.

| Check | Result | Report |
| --- | --- | --- |
| Executable build | All 226 C/C++ modules and one assembly module build and link. No unresolved symbols or link errors. | `build.log`, final build `report.json` |
| Object comparison | All 229 non-debug object payloads match, including section properties, symbol identities, and relocations. | `equivalence.json` |
| Executable comparison | Same size, instructions, data, and address fields. Only build timestamps differ. | `equivalence.json` |
| Function audit | All 225 groups compile. All 5,013 exact claims pass. | `functions/report.json` |
| Function comparison | All 5,426 observations remain identical, including results, differences, owners, direct-symbol findings, and policy findings. | `function-comparison.json` |
| Matching owners | No owner mismatches, duplicate source owners, class/free-function mismatches, or repair entries. | `owners.json`, `owners.txt` |
| Source checks | `git diff --check` passes. All 25 tracked source/header files preserve their line-ending style. | `source-scope.json`, `line-endings.json` |

Commands, from the repository root:

```text
python tools/build_executable.py --output-dir build/action-result-cleanup/executable
python tools/audit_translation_unit_functions.py --jobs 4 --output-dir build/action-result-cleanup/functions
python build/action-result-cleanup/compare_functions.py --baseline build/constant-cleanup-validation/validated-functions/report.json --cleaned build/action-result-cleanup/functions/report.json --output build/action-result-cleanup/function-comparison.json
python tools/audit_matching_owners.py --function-report build/action-result-cleanup/functions/report.json --output build/action-result-cleanup/owners.json --text-output build/action-result-cleanup/owners.txt
python build/constant-cleanup-compare.py --baseline build/constant-cleanup-validation/validated-executable/20261004T151049994606Z --cleaned build/action-result-cleanup/executable/20261004T165543157287Z --output build/action-result-cleanup/equivalence.json
git diff --check
```

These commands returned zero. The comparison excludes COFF debug sections and file/debug symbols.
Private compiler labels use section/offset identity; external and function symbol identities stay exact.
The executable comparison excludes only the COFF timestamp and seven resource-directory timestamp fields.

Final executable size: 1,559,552 bytes.
Final SHA256: `c6db4c1c6bd510eb366ce98b69fb8fdbaf663f1c9008b7cb86e4026051281c04`.
Both executables have this SHA256 after timestamp exclusions:
`397831695475942eeea14690e017608a342fff6e7231d4ba14f1fe8567f41b1d`.

Existing nonmatching results remain unchanged:
140 accepted-drift observations, 217 new-verified-logic observations, 44 grouped mismatches, and 12 boundary problems.
Existing source-policy findings also remain unchanged. No unresolved behavior or build claim was reclassified.
The runtime build selection remains unchanged.

Automated tests, linked dependency audits, menus, and gameplay are outside this request.
No runtime pass is claimed. Cleanup parity does not prove complete correctness against the original executable.
