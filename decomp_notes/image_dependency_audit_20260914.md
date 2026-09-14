# Static dependency audit findings

## Inputs and method

The tool is `tools/audit_image_dependencies.py`.
It compares the original EXE with hash-checked linked builds without running either game.
Original symbols and the rebuilt linker map pair the function windows.
Aligned x87 instructions establish numeric memory operands and their read widths.
The tool reads the original and rebuilt operand storage separately. It does not substitute original values.

Original SHA256: `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
Current tested EXE SHA256: `75ea997f420d64395b314f25d0b3b6bf75bb121c5dc962ee41f8f425bf58278b`.
Current build: `build/executable/human-civ-effect-repair/20260914T215953270395Z`.
Report: `build/dependency-audit/validated-current/`.

The scan considers 7,990 inventory functions. It does not prove all rebuilt boundaries or complete image ownership.
Current results: 7,094 passing checks, eight failing checks, and 46,418 unknown checks.
These are dependency-check counts, not function counts.

## Historical qualification

Historical EXE SHA256: `95e46ebf03109684d589c24683974ac92607005756995f3835a04744f778b1a9`.
Build: `build/executable/user/20260914T155318269945Z/20260914T155318520959Z`.
Report: `build/dependency-audit/validated-before-repairs/`.

The checker detects nine previously repaired reads in four functions:

- `00438670`: two reads of positive half instead of negative half.
- `00438720`: two reads of positive half instead of negative half.
- `0045A6D0`: one read of positive half instead of negative one.
- `0052EAC0`: four reads of half-tile bounds instead of three-tile bounds.

Those nine failures disappear in the current tested EXE.
Optional regression tests check both pinned EXEs and require these per-function failure counts.
A synthetic reviewed-global test also detects the historical zero-version initializer defect.
It does not claim a replay of the unavailable original crashing build.

## Remaining constant differences

All three owners currently have `matching` registry status.
This records the registry state, not a new local matching validation.
The eight failed operand reads use these five distinct constant pairs:

| Function | Original storage | Original bytes | Rebuilt storage | Rebuilt bytes |
| --- | --- | --- | --- | --- |
| `00460EB0 rotate` | `00570B40` | `f1d4c853fb211940` | `00551E70` | `182d4454fb211940` |
| `00460EB0 rotate` | `00570B4C` | `db0fc9c0` | `00551E78` | `da0fc9c0` |
| `00460EB0 rotate` | `00570B50` | `db0fc940` | `00551E7C` | `da0fc940` |
| `0051F310 init_timeline` | `005770B4` | `abaaaa3d` | `005578B4` | `cdcccc3d` |
| `00545E00 addObject` | `00577A1C` | `cdcc8c3f` | `005581D8` | `0000c03f` |

### Rotation constants

The original double is `6.2831853`. The rebuilt double is `6.283185307179586`.
The original positive float is `6.2831854820251465`. The rebuilt float is `6.283185005187988`.
The negative floats differ in the same magnitude bits.
The reads occur at function offsets 11, 50, 73, 86, and 92, in decimal bytes.
`src/move_obj.cpp`, `RGE_Moving_Object::rotate`, contains the corresponding rebuilt literals.

### Timeline scale

The original float is approximately `0.0833333358`. The rebuilt float is approximately `0.1000000015`.
The multiplication occurs at function offset 431.
`src/tpnl_tml.cpp`, `Time_Line_Panel::init_timeline`, uses `0.1f` in the corresponding expression.

### Object storage growth

The original float is approximately `1.1000000238`. The rebuilt float is `1.5`.
The multiplication reads occur at function offsets 54 and 292.
`src/world.cpp`, `RGE_Game_World::addObject`, uses `1.5f` for both corresponding growth calculations.

## Next work and limits

Review each owner against the original instructions before source changes.
Preserve the exact original constant bytes, including rounding.
Validate affected compilation units and rerun this audit after any repair.
Use gameplay tests to measure visible effects. This static finding does not establish a specific runtime symptom.

No game source or function status changed during this audit.
The tool does not automatically diagnose the civilization field-selection defect.
Unaligned code, unknown targets, runtime field addresses, and unreviewed jump tables remain unknown.

## Validation integration follow-up

Normal function checks and grouped translation-unit checks now inspect object-local numeric operands.
The timeline check at `0051F310` reports instruction agreement and a failed numeric dependency.
Its final result is `MISMATCH`, with command exit code one.
The recorded constant bytes are `abaaaa3d` versus `cdcccc3d` at offset `0x1AF`.

The expanded linked audit verifies selected object hashes and emission ranges.
An emission can include local tables and padding. Its end is not automatically the logical instruction boundary.
Unresolved relocation destinations remain explicit in `bounded_emitted_span` records.
Those records do not claim complete relocated-byte equality.

Report: `build/dependency-audit/commit-current/`.
The tested EXE hash remains unchanged.

- 3,606 emissions have complete supported relocated-byte proof.
- 806 emissions have bounded spans with unresolved relocation destinations.
- 619 selected symbol pairs lack emission proof.
- All 136 reviewed initial-storage and pointer checks pass, including 75 recovered strings.
- 416 guarded switch entries pass. Five entries differ. Eleven switch sites remain unknown.
- 189 linked virtual tables lack reviewed bounds and remain unknown.

The stricter scan retains all eight constant differences and adds five switch-entry differences.
All five affected functions have `matching` registry status at this checkpoint.

### New switch findings

| Function | Table index | Original target | Rebuilt target | Expected aligned target |
| --- | ---: | --- | --- | --- |
| `00450D00 modify_percent` | 2 | `00450DE6` | `00444589` | `00444596` |
| `00450D00 modify_percent` | 3 | `00450DE6` | `00444589` | `00444596` |
| `004C2110 draw_front_frame` | 1 | `004C215F` | `004AE866` | `004AE84F` |
| `004C2110 draw_front_frame` | 2 | `004C2176` | `004AE84F` | `004AE866` |
| `004C2110 draw_front_frame` | 3 | `004C2176` | `004AE84F` | `004AE866` |

Original table addresses are `00450DEC` and `004C2190`.
Rebuilt table addresses are `0044459C` and `004AE880`.
The adjacent unsigned bounds checks establish the compared table slices.
Complete aligned instruction windows establish the expected internal target offsets.
The linker map and COFF objects establish the emitted owners.

Review these table differences before changing `src/m_co_obj.cpp` or `src/stat_obj.cpp`.
This audit records differing dispatch targets, not a measured gameplay symptom.
No source repair or registry change accompanies the validation integration.

## Commit validation

The full Python suite passed 716 tests and 31 subtests during implementation.
After the final edits, the focused validation suite passed 135 tests.
The live timeline check rejects the known wrong constant through the normal function-check command.
The linked audit returns one because its 13 dependency differences remain unresolved.
That return code is an audit finding, not a tool execution failure.
The staged whitespace check passes.
Unrelated registry edits and behavior-review files remain outside this change.

## Source repair follow-up

See `decomp_notes/image_dependency_repair_20260914.md` for the scoped repair and fresh validation.
The repair restores eight constant reads and five switch entries in five natural source owners.
The earlier build and all audit findings above remain unchanged as historical evidence.
