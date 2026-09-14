# Full-TU audit repairs, 2026-09-13

Base commit: `44d296b30a9b2307b00c4b38f344bc3705dc4219`.
Original report: `build/final-verification-tu-after-link-fix/report.json`.
Experiment workspace: `build/audit-repair-worktree`.
No original files, inventory files, or exactness rules changed.

## Button draw modes

### Behavior

The original button factories pass these draw modes:

| Function | Original instruction | Required mode |
|---|---|---|
| `00468530` | `00468616 push 3` | Text |
| `00468760` | `004688E8 push 3` | Text fallback |
| `004689C0` | `00468AA8 push 2` | Picture during setup |
| `004689C0` | `00468B09 push 3` | Text fallback |

Each setup call pushes ten arguments. The fourth push supplies draw mode.
The preceding pushes supply action ID, notification mode, and sound.
The remaining pushes supply height, width, Y, X, parent, and drawing area.
The receiver comes from the output button pointer.

`004720A0` stores this argument in `drawTypeValue`.
`00472140` stores its sole argument in the same field.
Fresh checks of both callees report exact matches.
These differences therefore change stored button state, not only instruction layout.

The factory review covered scaling, allocation, failure branches, sound selection, text fallback, bevels, and color calls.
Scaling uses signed division before allocation. Allocation requests `0x2B8` bytes.
All three factories write the output pointer before checking allocation failure.
They preserve the original failure store at `this+0xD8` and return zero.
They do not delete the allocated button on setup failure.
The ordinary button uses font 10 when its font ID is negative.
Its color loop visits indices zero through eight, then updates state one.
The check box uses picture indices zero and two; the radio button uses four and six.
The text fallbacks retain space and X strings, font zero, and state one.

The toolbox and two screen constructors also pass picture mode where the original passes text mode.
Their baseline instruction bodies differ only at seven, one, and three immediate bytes, respectively.
The source review covered their allocation failures, setup arguments, text calls, and final child selection.
The toolbox retains six mode pointers in its 24-byte local array.
The tribe screen retains nine button pointers plus its OK button in its 40-byte tab array.
Both screen background buffers remain ten bytes. The longest selected background name requires eight bytes, including its terminator.
No runtime UI test has run.

### Source

`include/pnl_btn.h` defines `DrawPicture = 2` and `DrawText = 3`.
Commit `6eab0575e` exchanged the earlier values without updating these callers.
The repair changes caller enum names, not enum values or shared headers.
It retains each natural source owner and the configured compiler flags.

### Bytes

Factory baseline: `5a62bbf9e48f1f8438c0e30c630b54197853b15c62aaa9e6e4978d46502080d4`.
Factory repair: `5c29701a87179d7732d0862ebd8bb9754611bee8a833461b1f6876363334cd3c`.
The repair closure reports zero failed exact claims. All three factories match exactly.

| VA | Baseline differences | Repair state |
|---|---:|---|
| `004898D0` | 7 | `9e500c9da31ed4f825a53b657b694f6bf5c7b8feef099ce5fb717f0fc6d79b66` |
| `004936D0` | 1 | `9944a64c9aa203622396330e3dadbe7596979f6b33f717ac2e2f22d60053b13a` |
| `004B75A0` | 3 | `827f9b2369545806eb3c8574fd28b6364769aa649c6f3ab284b49e621f4fd316` |

All three constructor repairs also report exact matches and zero failed exact claims in their TU checks.
The experiment store preserves baseline inputs, changed inputs, checker output, and TU audit output.
Final integration validation passes as recorded below.

### Integration

The six supported caller repairs passed their complete TU checks and entered the main workspace.
Do not change unrelated draw-mode uses without original instruction evidence.
Local exactness does not prove linked storage, initial data, or gameplay behavior.

## Other findings

### Behavior

`0044F040` loads the two dimension fields in reverse order.
The remaining 39 bytes match. No calls or writes occur in this function.
An operand-exchange probe did not change its emitted bytes.
This does not establish fault-order equality for arbitrary invalid object pointers.

`00473D60` still differs by 196 bytes and emits 209 bytes instead of 211.
The seven call sites align. This alone does not prove all call arguments or behavior.
The current source body matches the later promotion commit's body.
Since that commit, `include/basegame.h` gained an editor-panel declaration and friendship.
That shared declaration change is a compiler-context hypothesis, not a proved cause.
Do not remove required shared declarations merely to recover a previous register schedule.

### Source

The maxValue probe changed only multiplication operand order and was rejected.
The original natural source remains unchanged.
Dialog source remains unchanged. Its unsupported exact claim changed to `scratch`.
The maxValue exact claim also changed to `scratch`; neither status change repairs behavior.

### Bytes

MaxValue baseline: `f4a6fbf0bdecbd3c71baf1ece876e6b6d884a10b66cb157b56712a3533390299`.
Rejected operand probe: `dfb5c091166851543fa4119e31eca6d303b86a933e48c5a4b0e1948e97cb4d49`.
Both emit 41 bytes with two differences.
Sequential-load probe `3c6031bc0388943c8f3286422cedea847bb50e5c60373c49f7f28b3b2729e010` gives the same result.
Preserve both rejected probes. Do not retain their source edits.
Dialog baseline: `a52e2046a590ab316cf885f76af60f5dcc09d51d89891a710916775e5f7ef14a`.
Its fresh isolated TU check confirms the reported mismatch.
Initial experiment runs in the main workspace were refused before checking.
The isolated workspace runs supply the recorded validation results.

### Integration

The 18 boundary reports and 49 relocation reports remain open.
They are not unresolved linker symbols.
All 18 boundary entries already have `accepted_drift` status; none makes an exact claim.
The relocation entries comprise three accepted-drift, forty new-verified-logic, and six scratch functions.
This pass does not reopen their existing behavior approvals solely to improve byte scores.
Review their recorded behavior evidence before selecting further source repairs.
The eight grouped exact entries already have `accepted_drift` registry status.
Do not describe them as eight unreviewed source recoveries based only on this audit category.
Exact promotion and current behavior-review scope need separate checks.

The `00521790` reference gap concerned `_ICInfo@12` at function offset `0x3AA`.
The independent evidence repair below closes that gap without changing code or exactness rules.

## Accessor call order

### Behavior

`004754C0` tests mouse capture, the list hit, and then the scroll-bar hit.
The list-hit branch sends mouse-up to the button, then mouse-down to the list.
The scroll-bar branch does the same, but uses the list's rightmost X coordinate.
Original `00475565` calls width. Original `00475578` then calls X position.
Both branches preserve button number one, Y, control, and shift arguments.
The fallback calls `TPanel::handle_mouse_move` with the original four arguments.
The repair uses separate statements for width and X position. It preserves the original call sequence.

`0051FD90` calls Y position at `0051FF4E`, then height at `0051FF57`.
The current build reverses these two calls. All other baseline instructions match.
The complete original body retains two event loops, icon dispatch, text dispatch, and drawing-resource cleanup.
The source retains those branches and effects. The second text call measures its string before the two getters.
A temporary-length and bottom-coordinate probe preserves that order but substantially changes emitted code.
No runtime mouse or timeline tests ran.

### Source

Reversing addition operands alone did not change either function's emitted call order.
Separate statements repair the dropdown without helper functions or shared changes.
Reject the larger timeline probe and retain its original source.
The timeline's old accepted-drift ledger remains historical evidence.
This pass does not supply a new complete fault-order approval for the current compiler inputs.
Correct its unsupported `matching` claim to `scratch`.

### Bytes

| VA | State | Differences |
|---|---|---:|
| `004754C0` | `dcd46ec8ccfe740189cbfa50cf252b5b2bb1af8a70ea99be1492b042ff52576f` | 8 |
| `004754C0` | `0bfe21a4f4c51b6ec011af0e95ee6b944210bc9a1483afee2e317aec2b0fd154` | 8 |
| `004754C0` | `9be40847db5bad4ba2c1667cab304a094407d80bfeb520fd3cf9b3f57107417d` | 0 |
| `0051FD90` | `ab131f8e8d03268355a3a4887f2b2ca0202dcd48d27e358a6d7ae8a8c1daa40e` | 8 |
| `0051FD90` | `9d4948021086aaeaaf55a276b130bf36157d336489a92004e7d14be6c7a3646a` | 8 |
| `0051FD90` | `1498d1ae8c4e59822709ef3c53a678ff4a84360813f3e86f9763ac8a92001b00` | 712 |

The exact dropdown closure has zero failed exact claims.
The final two states also capture the independent ICInfo identity addition.
That addition does not change compiler inputs for these functions.

### Integration

Integrate only the dropdown source repair. Preserve all rejected probes in the experiment store.
The timeline status correction is not a behavior repair or an accepted-drift approval.

## ICInfo target identity

### Behavior

The original call at `00521B3A` contains `E8 65 96 02 00` and reaches `0054B1A4`.
That thunk contains `FF 25 B4 A7 88 00` and jumps through `0088A7B4`.
The original PE import directory identifies `MSVFW32.dll!ICInfo` at that slot.
Original PDB publics independently name `_ICInfo@12` and `__imp__ICInfo@12` at those locations.
Section one starts at `00401000`; section five starts at `0088A000`.
The PDB offsets are `0014A1A4` and `000007B4`, respectively.
See `remaining_matching_claims.md` for the public records.
This proves the external target, not its DLL implementation.

### Source

Add one target to `config/reviewed_reference_identities.json`, with no aliases.
Keep existing original EXE and PDB hash checks.
Do not change `TRIBE_Game::setup` or promote its registry status without its separate review.

### Bytes

Baseline: `a471efa96f2dd2bfc68e5effaa79897356b4c81d5510cc5c9f318fe5fc64eb81`.
Identity repair: `2fbbaae8f09950b79bea3f5067785bc82769befe1f68b48129afc205565498cb`.
The function changes from three differing bytes and one unknown target to an exact match.
The compiled output hash stays unchanged. Only independently supported reference validation changes.
The complete game TU check reports zero failed exact claims.

### Integration

Retain the identity record and its evidence. Add a test for the exact name, wrong names, and original call bytes.
The focused reference-tooling suite passes all 24 tests.
Full audit, tests, and executable build pass as recorded below.

## Validation commands

```text
python tools/audit_translation_unit_functions.py --jobs 12 --output-dir build/final-verification-tu-audit-repairs
python -m pytest tests -q
python tools/build_executable.py --output-dir build/executable/audit-repairs
python tools/query_project_status.py --summary --normal
git diff --check
```

The initial unrestricted pytest run was stopped. The replacement selects the repository's complete `tests` directory, excluding experiment worktrees.
Changed tracked files retain LF line endings. The diff whitespace check passes.
Current status query reports 4,965 matching, 237 accepted-drift, 213 new-verified-logic, and 11 scratch functions.
It reports no conflicts, unresolved entries, or unclaimed entries.

## Final results

- All 225 TU groups compile. All 4,965 current exact claims pass. The audit exits zero.
- Seven of the original ten entries now match exactly after source repairs.
- The other three retain their original differences and now have `scratch` status.
- `00521790` now passes exact reference validation. Its registry status remains `new_verified_logic`.
- The full report comparison finds no other changed byte counts or source statuses.
- The matching-owner audit finds zero owner mismatches, class/free mismatches, or queued repairs.
- All 469 tests and 31 subtests pass.
- All 226 C/C++ sources and the assembly source build. The executable links with zero unresolved symbols and zero link errors.
- No runtime game or UI test ran. The executable remains experimental.

Final report: `build/final-verification-tu-audit-repairs/report.json`.
Owner report: `build/final-verification-tu-audit-repairs/owners.json`.
Executable build: `build/executable/audit-repairs/20260913T231355891392Z/report.json`.

The 18 boundary entries remain unchanged.
Relocation reports increase from 49 to 50 because timeline drawing moves from a failed exact claim into that category.
This is reclassification of its existing two getter-target differences, not a new emitted-code defect.
Grouped mismatches increase from two to four because maxValue and dialog setup now have scratch status.
The eight grouped matches needing review remain unchanged.

### Changed source and configuration

- `src/Panel_ez.cpp`: three factory draw-mode repairs.
- `src/Pnl_drop.cpp`: original getter call sequence.
- `src/rpnl_tbx.cpp`, `src/scr_end.cpp`, `src/scr_trb.cpp`: text button draw modes.
- Three function registries: remove unsupported exact claims for maxValue, dialog setup, and timeline drawing.
- `config/reviewed_reference_identities.json`: independently proved ICInfo thunk identity.
- `tests/test_reference_tooling.py`: target-name and original-call regression test.

Function notes, this report, reference evidence, and the experiment store preserve the decisions and rejected trials.
No changes were committed. The stopped experiment worktree remains available under `build/audit-repair-worktree`.

### Remaining work

The dialog still needs supported source or compiler-context recovery.
MaxValue and timeline drawing need exact repair or a current complete accepted-drift review.
The existing boundary and relocation reports need their own function-level evidence reviews before further source changes.
Do not treat the successful exact-claim gate as proof that every function matches or gameplay is correct.
