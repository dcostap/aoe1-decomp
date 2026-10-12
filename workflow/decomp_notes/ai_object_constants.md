# AI, action, object-group, and resource constant cleanup

## Scope

The starting commit is `d3cf05c6c88d01ec2be9ec4a289bce818aa7bd2b`.
The starting source had no tracked changes.

The request started at `src/taimdmd.cpp:554`.
The cleanup follows shared values through their producers, consumers, and dispatch functions.
It changes 46 source modules and four existing headers.

All added constant names are descriptive cleanup names.
PDB records do not establish the original macro names.
No parameters, locals, classes, functions, or ABI symbols were renamed.

## Constant domains and evidence

The domains remain separate. Equal numbers do not establish equal meanings.

| Domain | Header | Supporting source evidence |
| --- | --- | --- |
| Unit AI actions, orders, and notifications | `include/stat_obj.h` | Object notification and unit-AI interfaces; `src/aiuaimod.cpp` and action producers. |
| Master-object groups | `include/m_s_obj.h` | The `object_group` field; `TRIBE_Combat_Object::initUnitAI()` and information-AI classification. |
| Task and action types | `include/action.h` | `RGE_Action::action_type`, action constructors, and action-list dispatch. |
| Resource IDs | `include/player.h` | The first four player attributes; inventory labels, scenario records, and status output. |

### Unit AI actions and orders

`UnitAIModule` action methods establish attack, defend, build, heal, convert, explore, gather, move, follow, hunt, transport, trade, and enter.
They also establish repair, unload, seek-and-destroy, and explore-and-destroy.
Each method records its action through `setCurrentAction()`.

`UnitAIModule::processOrder()` connects order values to those methods.
It also establishes stop, start-play, stop-play, wait, and attack-roundup.
The wait branch records action `0x274` and order `0x2D8`.

The `0x2D4` order uses movement and handles movement completion.
`TribeTacticalAIModule::groupGatherUnit()` supplies its target.
Its cleanup name is `UNIT_AI_ORDER_MOVE_TO_TARGET`, not a gather action.

`RGE_Player::command_stand_ground()` sends order `0x2D5`.
Attack and notification handlers retain that order's special handling.
Its cleanup name is `UNIT_AI_ORDER_STAND_GROUND`.

`TRIBE_Action_Make_Obj` notifications establish action `0x26B` as training.
`TRIBE_Action_Make_Tech` notifications establish action `0x26C` as research.
These also explain the building group returned by the requested decision-AI function.

The original assembly listing for `taimdmd.cpp` supports the numeric dispatch and returned groups.
The cleanup preserves its civilian-only explore branch and its default call.
It does not add boat handling.

### Notifications

Action failure paths send `0x1F9`.
Action completion paths send `0x1FA`.
Lost or invalid target paths send `0x1FB`.
Action producers send `0x202` to request another task.
Their unit-AI handlers consume the same values.

`RGE_Combat_Object::damage()` sends `0x1F4` to report an attacker.
Conversion also sends that event without applying damage.
Thus, its name is `UNIT_AI_NOTIFY_ATTACKED`, not a damage amount.

Several handlers also accept action IDs as notification values.
Those uses retain the action-domain names and values.
The cleanup does not assign speculative names to other notification values.

### Object groups

`TRIBE_Combat_Object::initUnitAI()` directly selects these AI classes:

| Value | Group |
| --- | --- |
| 1 | Artifact |
| 2 | Trade boat |
| 3 | Building |
| 4 | Civilian |
| 9 | Hunted animal |
| 10 | Predator |
| `0x12` | Priest |
| `0x14` | Transport boat |
| `0x15` | Fishing boat |

Information-AI building, wall, and boat checks also establish wall `0x1B` and war boat `0x16`.
Resource registration and influence-map branches establish tree `0x0F`, stone source 8, and gold source `0x20`.
Their resource indices agree with inventory and player-status labels.
Cliff checks in combat and view code establish group `0x22`.

`produceWhenKilledBy()` connects hunted animals and predators to civilian killers.
The cleanup retains its conditions and return values.
It also retains information-AI resource omissions and existing bug comments.

### Task and action types

Action constructors assign each named type.
`RGE_Action_List` and `TRIBE_Action_List` select corresponding classes during loading and task dispatch.
Their action-name functions supply additional evidence.
`RGE_Action_List::get_action_name()` establishes type 20 as `RunAway`.

`RGE_Action_Object::work2()` translates task/action types into separate unit-AI actions and orders.
The cleanup names all established branches without combining these domains.

### Resource IDs

Inventory output and `TRIBE_Player::logStatus()` establish food 0, wood 1, stone 2, and gold 3.
Scenario save/load code uses the same attribute indices.
The cleanup preserves record order and four-byte transfers.

The gold fallback in object and technology cost code remains unchanged.
The existing local name `population` in `check_obj_cost()` remains unchanged.
Its misleading name does not change the established meaning of attribute 3.

## Output-preservation rules

Constants remain numeric macros with the original effective integer types.
All values fit `int` where the original literals had type `int`.
Existing long operands retain explicit long conversions.

No stored field, parameter type, layout, declaration scope, or evaluation order changed.
No statement, condition, switch arm, or function moved.
Original debug line numbers, counts, unrelated masks, and string contents remain unchanged.
`TRIBE_Command::do_command_make()` still records the original research action.
The cleanup does not repair that behavior.

The first attempt used four new constants-only headers.
Its fresh build introduced 554 differing executable bytes and two failed exact claims.
That attempt was rejected.

Moving definitions into existing headers restored all 225 successfully compiled module payloads in the second build.
The task-only module needed `include/action.h` for its shared action-type definitions.
The final build and whole-project audit include that dependency.

Private compiler label serial numbers can change with source tokens.
The object comparison checks their section, offset, type, and storage class instead.
It preserves named function identities and external relocation targets.
It compares complete non-debug section bytes, sizes, flags, and relocation records.
The executable comparison excludes the COFF header timestamp and seven resource-directory timestamps.
It does not mask instructions, program data, relocation operands, or address fields.

## Unresolved values and limits

Unnamed actions include `0x25E`, `0x25F`, `0x260`, and `0x268`.
Other unnamed notifications and master-object groups remain numeric.
Their roles need stronger evidence before they receive names.

The cleanup does not replace every integer in the game.
It does not assign names from numeric equality alone.
Some resource-index arrays and generic filters remain numeric pending a separate contextual review.

Static output equality proves preservation relative to this starting source.
It does not prove complete agreement with the original game.
Accepted differences and unresolved recovery work remain outside this naming-only change.

## Changed files

Headers:

- `include/action.h`
- `include/m_s_obj.h`
- `include/player.h`
- `include/stat_obj.h`

Source modules:

- `src/Command.cpp`
- `src/act_atak.cpp`
- `src/act_bird.cpp`
- `src/act_entr.cpp`
- `src/act_expl.cpp`
- `src/act_gath.cpp`
- `src/act_list.cpp`
- `src/act_make.cpp`
- `src/act_misl.cpp`
- `src/act_move.cpp`
- `src/act_obj.cpp`
- `src/act_tran.cpp`
- `src/aiuaimod.cpp`
- `src/com_obj.cpp`
- `src/dlg_dip.cpp`
- `src/player.cpp`
- `src/scr_sed.cpp`
- `src/t_b_obj.cpp`
- `src/t_c_obj.cpp`
- `src/tact_art.cpp`
- `src/tact_bld.cpp`
- `src/tact_cnv.cpp`
- `src/tact_dar.cpp`
- `src/tact_hea.cpp`
- `src/tact_hnt.cpp`
- `src/tact_lst.cpp`
- `src/tact_mob.cpp`
- `src/tact_rep.cpp`
- `src/tact_tek.cpp`
- `src/tact_trd.cpp`
- `src/tact_wnd.cpp`
- `src/taibldmd.cpp`
- `src/taiinfmd.cpp`
- `src/taimdmd.cpp`
- `src/taipbook.cpp`
- `src/taitacmd.cpp`
- `src/taiuaimd.cpp`
- `src/tcommand.cpp`
- `src/tech.cpp`
- `src/tmap.cpp`
- `src/tplayer.cpp`
- `src/tpnl_inv.cpp`
- `src/tpnl_obj.cpp`
- `src/ttsk_lst.cpp`
- `src/tworld.cpp`
- `src/vw_main.cpp`

This report is the only new file included in the cleanup commit.
Other untracked local-name audit files belong to separate work and remain unchanged.

## Validation

Reports remain under `build/constant-cleanup-validation/`.
The detached baseline worktree remains under `build/constant-cleanup-baseline/`.
Its baseline reports remain under its own `build/constant-cleanup-validation/` directory.
The commit includes only the cleanup source, headers, and this report.

The final selected executable is:

`build/constant-cleanup-validation/validated-executable/20261004T151049994606Z/empiresx.exe`

Its SHA256 is `a5a24273091b890b1abfa35db6971c41f7ecd671de5c57065514043c775507b0`.
The baseline executable SHA256 is `b444a7d47ba6c9bab66e0328e923e83c572c86350d7c7818bbca14813f0101f0`.
The executable size remains 1,559,552 bytes.
After excluding build timestamps, both hashes are `397831695475942eeea14690e017608a342fff6e7231d4ba14f1fe8567f41b1d`.

| Stage | Result | Report below the report root |
| --- | --- | --- |
| Registry configuration | Exit 0 with `--no-build-checks`. | `validated-registry.txt` |
| Baseline and final function audits | Exit 0 each. All 225 groups compiled; all 5,013 exact claims passed. | `validated-functions/report.json`; baseline worktree's `baseline-functions/report.json` |
| Function-result comparison | All 5,426 observations retain their results, differences, owners, and direct-symbol findings. | `function-comparison.txt` |
| Matching ownership | Exit 0. No owner mismatch, duplicate source owner, class/free mismatch, or repair entry. | `owners.json` |
| Fresh executable build | Exit 0. All 226 source modules and one assembly module compiled and linked. | `validated-executable/20261004T151049994606Z/report.json` |
| Cleanup output comparison | Exit 0. All 229 object payloads match. Executable content matches except build timestamps. | `validated-equivalence.json` |
| Linked image dependencies | Exit 0. 11,408 checks pass; 48,269 remain unknown. No supported failure. | `validated-dependencies/summary.json` |
| Header emissions | Exit 0. All 133 checked entries report `all_emissions_match`. | `header-emissions.json` |
| Linked references | Exit 0. 7,532 checks pass; 5,347 remain unknown. | `linked-references.json` |
| Global initializers | Exit 0. 124 exact initial values; one equal string value with different tail layout. | `global-initializers.json` |
| Original-image comparison | Report generated. Existing layout and content differences remain visible. | `original-image/summary.json` |
| Automated tests | Exit 0. 1,016 tests and 31 subtests pass; two optional historical-build tests skip. | `validated-tests.xml`; `validated-tests.log` |
| Whitespace and line endings | `git diff --check` and the line-ending check pass. | `validated-line-endings.txt` |

The global check leaves 107 entries for type/startup review and 59 unmapped entries.
It excludes one toolchain-state entry.
Those results do not establish complete data coverage.

The nonmatching function results remain unchanged:
140 accepted-drift observations, 217 new-verified-logic observations, 44 grouped mismatches, and 12 boundary problems.
Existing source-policy findings in `src/Res_file.cpp` also remain unchanged.
This cleanup does not approve or repair those separate findings.

The automated tests used `AOE_DEPENDENCY_BUILD` to select the final fresh executable build.
The skipped tests require unavailable optional preserved runtime builds.

The user limited final validation to output parity and matching status.
The runtime test process was stopped at the user's request.
No menu or gameplay pass is claimed.
Partial runtime logs remain in `menus.log` and, if created, `gameplay.log`.
