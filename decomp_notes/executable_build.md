# Executable integration evidence

## Build result

Tested base: `f31347147`.

All 226 natural source files compile with the pinned VC5 toolchain.
The latest link still fails. No runnable reconstructed EXE exists.

| Build report directory | Unique unresolved symbols |
| --- | ---: |
| `build/executable/20260905T233749367429Z` | 454 |
| `build/executable/20260906T000550664449Z` | 442 |
| `build/executable/20260906T002338318252Z` | 418 |
| `build/executable/20260906T005357666823Z` | 333 |

The original EXE remains unchanged.
Its SHA-256 is `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.

The build extracts original resources and uses normal VC5 linking.
It does not use forced linking, dummy functions, or unproved symbol aliases.
It includes `game_globals.cpp` and `tech.cpp` through explicit integration profiles.
These profiles prove compilation, not original module recipes or function exactness.

## Retained declaration repairs

- `rge_read` and `rge_write` use the canonical C++ linkage.
- Two AI callers no longer declare a nonexistent `rge_write(const void*, ...)` overload.
- Eight `UnitAIModule` getters use the canonical `const` declarations.
- `vis_unit.cpp` references the existing lowercase global names.
- `IDirectPlay3` uses the SDK's `struct` tag in the shared forward declaration.
- Three DirectX GUID declarations use the SDK's C linkage.

`map.cpp` and `visible.cpp` retain narrow I/O declarations.
Including the full I/O header changed otherwise exact neighboring output.
The declarations now agree with the existing definitions without adding unsupported source.

The retained-declaration audit compiled all 224 configured modules.
All 4,747 then-matching functions remained exact.
Report: `build/audits/executable_retained_declarations/report.json`.

The build uses the unchanged period `dxguid.lib` for DirectX GUID data.
VC5 cannot read the preserved `dplayx.lib` short import objects.
VC5 LIB therefore rebuilds three ordinal imports from `config/dplayx.def`.
The original library remains unchanged.
See `third_party/directplay/README.md` for file hashes and provenance.

## Compiler-owned destructor recovery

Fourteen classes declared virtual destructors without providing definitions.
Their original destructors are compiler-generated tail jumps to their base destructors.
The repaired headers let the compiler generate the implicit destructors.

Ten generated bodies now pass `validate_candidate_tu.py` with `MATCH`, zero differing bytes, and valid ownership and direct targets:

| VA | Class |
| --- | --- |
| `00441A60` | `RGE_Doppleganger_Object` |
| `004CCB10` | `TRIBE_Tree_Object` |
| `004CCBF0` | `TRIBE_Action_Artifact` |
| `004D2700` | `TRIBE_Action_Trade` |
| `00509760` | `TRIBE_Command` |
| `0050F210` | `TRIBE_Master_Tree_Object` |
| `00519BC0` | `TRIBE_Gaia` |
| `00519E90` | `TRIBE_Panel_Button` |
| `00520E20` | `TRIBE_Panel_Text_Line` |
| `0052AB80` | `T_Scenario` |

Proposals and reports reside in `decomp_notes/executable_build_evidence/generated_destructors/`.
Each proposal uses the existing natural source and registry compiler profile.
The reports do not claim that the entire module is exact.
Their `full_module_exact` field covers only the proposal's selected generated functions.

Four implicit destructors inline into their scalar deleting destructors:

| Destructor VA | Class | Scalar deleting destructor VA |
| --- | --- | --- |
| `00404A00` | `RGE_Action_Make` | `004049E0` |
| `0050B490` | `TRIBE_Dialog_List` | `0050B470` |
| `0050D4A0` | `TRIBE_Effects` | `0050D480` |
| `0053D3A0` | `RGE_Diamond_Map_View` | `0053D380` |

The four standalone checks correctly report missing emitted symbols, not exact matches.
Each rebuilt scalar deleting destructor has 32 bytes.
Only its two four-byte call relocations differ before relocation resolution.
The first call now targets the base destructor directly.
The original call targets a child destructor whose complete body is a jump to that same base destructor.
The second call still targets `operator delete`.
The other bytes remain equal, including stack cleanup, flag testing, object return, and padding.

Removing the forwarding jump preserves calls to behavioral owners, stack effects, memory effects, exception handling, and memory-fault order.
No handwritten destructor or wrapper remains.
Do not restore a redundant declaration solely to force an emitted forwarding body.

`TRIBE_Effects::save` also had an unsupported override declaration.
The original virtual slot points directly to `RGE_Effects::save` at `004494B0`.
The class now inherits that method.

## Complete closure and accepted drift

The complete destructor audit compiled 224 modules and checked 5,260 configured functions.
It found one changed matching owner: `004421F0`, `add_doppleganger_check`.
The four differing bytes only exchange ECX and EDX in one pointer-comparison block.
The complete proof is `logic_reviews/004421F0.md`.
The registry records this completed recovery as accepted drift.
No further matching work is required without new evidence.

The ten exact destructor candidate paths each preserve the complete source patch from the tested base.
Each path has this form: `decomp_notes/candidates/<prefix>/<VA>_exact_candidate.patch`.
All ten patches include the same complete declaration-repair state.
The affected closure includes every configured module; only `004421F0` lost exact bytes.
The compressed report is `decomp_notes/executable_build_evidence/implicit_destructors_closure.json.gz`.

## Original virtual slots

`audit_vtables.py` locates original tables through exact constructor and destructor relocations.
The first report found 207 emitted tables, 206 original table addresses, and no conflicting emitted table definitions.
It does not infer original table bounds from the rebuilt table size.

Eight unsupported overrides now inherit the original methods:

| Declared class and method | Original method owner |
| --- | --- |
| `RGE_Combat_Object::new_sprite` | `RGE_Moving_Object`, `0045D080` |
| `RGE_Combat_Object::change_ownership` | `RGE_Action_Object`, `00406B90` |
| `RGE_View::is_inside` | `TPanel`, `004662E0` |
| `TRIBE_Action_Convert::stop` | `RGE_Action`, `004078F0` |
| `TRIBE_Action_Convert::move_to` | `RGE_Action`, `00407900` |
| `TRIBE_Master_Player::finish_init` | `RGE_Master_Player`, `004611D0` |
| `TRIBE_Master_Player::create_master_object_space` | `RGE_Master_Player`, `00461530` |
| `TRIBE_Master_Player::save` | `RGE_Master_Player`, `00461840` |

Two nonexistent base methods also extended every unit-AI virtual table incorrectly.
The original `UnitAIModule` table at `0056EAD8` ends with `processRetryableOrder` at offset 220.
The words at offsets 224 and 228 are floating-point data, not function addresses.
The priest table at `00575E28` instead contains its own heal and convert methods at those offsets.
Those methods are `00505B00` and `00505CC0`.
The base now has 56 slots. The priest retains 58 slots and its own two declarations.

The full closure found one new matching difference: two integer-subtraction bytes in `0053F6F0`.
Its completed proof is `logic_reviews/0053F6F0.md`.
The same repair makes the unchanged `004CD210` and `0053E340` bodies exact.
Both authoritative target checks report `MATCH` and `0.0000%` with valid ownership, boundaries, and direct targets.
Their complete current candidate patches retain the required deterministic names.
The previous allocation candidates remain under separate `_allocation_exact_candidate.patch` names.

Reports: `virtual_slots_before.json` and `virtual_slots_closure.json.gz` under the evidence directory.

## Recovered string data

Seventy-five missing character arrays now have their original bytes in `src/game_globals.cpp`.
Every current COFF reference to each selected array belongs to an exact audited function.
Every reference identifies the same original address after its relocation addend is removed.
The source declarations agree on array type and const qualification.
The selected missing symbols do not share original addresses with each other.

`string_definitions.json` records each original address, value, declaration, and complete reference set.
The compiler test checks every emitted array against the original bytes, including its terminating zero.
The test also requires one defined symbol for each array.
No caller body or shared header changes for this data recovery.

Do not initialize other strings only from their names.
For example, one exact `s_Game_Screen` reference points to `"Config Dialog"`, not `"Game Screen"`.
Other uses need separate review before a shared definition can be correct.
Some data names also identify the same original object and need one canonical owner.

## Allocation probes not integrated

Several callers reference nonexistent `operator_new`, `operator_delete`, or `operator_new_array` helpers.
Natural operator declarations and array allocation repairs were tested.
Some exact target results changed neighboring owners, including floating-point instruction order.
Those allocation source changes were removed. They are not integrated.

Preserved complete candidate patches:

- `decomp_notes/candidates/0048/00480080_exact_candidate.patch`
- `decomp_notes/candidates/004C/004CD210_allocation_exact_candidate.patch`
- `decomp_notes/candidates/0053/0053E340_allocation_exact_candidate.patch`
- `decomp_notes/candidates/0053/0053E340_natural_allocation_candidate.patch`
- `decomp_notes/candidates/004C/004CD210_minimal_operator_candidate.patch`

Closure reports include `executable_rge_io`, `executable_allocation`, `executable_natural_allocation`, and `executable_declarations` under `build/audits/`.
Compressed evidence resides in `decomp_notes/executable_build_evidence/`.
Investigate affected owners before reusing these candidates.
Do not assume that the candidate caused an existing source defect.

## Tests and remaining work

The first full pytest run reported 319 passes and five failures.
The failures concern one function-note status line, orchestration documentation text, 33 review filenames, and two stale registry-count expectations.
Those failures concern existing files outside the integration repairs.
They do not prove executable correctness or disprove the compiled function results.

The eleven executable, resource, data, and virtual-table tests pass.
Registry validation and `git diff --check` also pass.

Remaining work includes unresolved definitions, virtual-table consistency, static data, and the deferred assembly regions.
A successful link must precede startup, gameplay, save/load, audio, and multiplayer tests.
No runtime or near-original EXE-layout claim is made.
