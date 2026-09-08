# Session handoff: array recovery and table storage

## Main result

Commit `129e0f6a0` restores writable obstruction tables.
It changes only two game source files, two test files, and the storage review note.
No array or command candidate was integrated.
No registry status was promoted in this continuation.
No game executable was run. No subagents or network services were used. Nothing was pushed.

Main validation passed:

- Authoritative `0046B5E0`: `MATCH`, `0.0000%`, 52 bytes.
- All 16 matching path-system targets.
- All 31 emitted path-system owner descriptions agree with the tested isolated state.
- Twenty-four focused tests and the translation-unit registry check.
- Line-ending and diff checks.

The isolated storage build compiled 226 sources and linked without errors or unresolved symbols.
It passed 415 tests, 31 subtests, and 133 header checks.
Linked references retained 6,873 passes and 5,276 unknowns, with no failures reported.
Unknowns remain unknown.

The first full pytest run exposed two tests that required the incorrect `const` definitions.
The repair corrects those expectations and adds a fresh compiled-object permission check.
The global-object proof covers startup code, CRT entries, remaining storage, relocations, and adjusted symbols.
Only the two intended four-byte table moves remain.

Read `decomp_notes/obstruction_storage_repair.md` for the complete bounded proof and validation events.
Event `4d70700425a61000cb6ef369c51e1e788ee658f5fc4bef147cd0fe3c96a23c85` preserves both linked proof images and maps.

## Recovery results kept isolated

Natural array helpers and complete caller loops produced or retained these checked results:

| Function | Bytes |
| --- | ---: |
| `004EA280 setVictoryCondition` | 1,231 |
| `004EF4E0` tactical save | 3,230 |
| `004E3C90 dropsitesWithinRequiredDistance` | 509 |
| `004F1090 removeObject` | 765 |
| `004E9DA0` strategy save | 902 |
| `004E9820` strategy update | 1,391 |
| `00413150` unit save | 758 |
| `00413450` unit load | 949 |
| `004351B0 duplicate_check_command_stop` | 89 |

Smaller unit access and query functions also retain their matches.
The unit-load repair removes the forced event union through PDB-supported local scopes.
The complete public `processNotify` repair changes none of 117 emitted owner descriptions.
Its 12 original differences remain unresolved.

Strategy and unit AI now use the public array interface.
Both pass their matching-neighbor checks under protected storage and original parameter names.
The original PDB marks all four array storage fields protected.
Other callers still require recovery before that header can build globally.

Read `decomp_notes/array_interface_recovery.md` for state and run IDs.
Read `LESSONS.md` and `decomp_notes/array_recovery_lessons.md` for the supported patterns and limits.

## Blockers

The last globally buildable array snapshot covered 90 modules and 3,584 emitted functions.
It identified 82 changed owner records and five matching regressions:

- `00441E00 rehook`: memory-read order remains unresolved.
- `0045A030 get_border_type`: a bounded register proof applies to the checked inputs.
- `0046B5E0 obstruction`: changed register saves have a proved stack-overlap defect.
- `004C6DA0 changeInfluenceMap`: x87 changes remain unresolved.
- `00533410 handle_points_high_attribute_amount`: a bounded register proof applies to the checked inputs.

Do not confuse the obstruction stack defect with the separate table-permission defect fixed on main.
The later public path-system probe also changes scratch `0046B6E0 findTilePath`.
Its allocation, memory-read, and floating-point changes need review against the original, not approval by baseline comparison.
Other changed scratch, accepted-drift, helper, and referenced-data records also need review.

The command Y-conversion repair remains open.
The isolated incoming-int form fixes conversion order but has a proved EBP-width stack-overlap defect.
Do not integrate that file wholesale.
Read `decomp_notes/command_order_repair.md` and `logic_reviews/00435110.md`.

Tech remains deferred: `0050C730`, `0050CA9E`, `0050CC25`, and `0050CE68`.
Do not reinstate unconditional stack-permutation equivalence.

## Preserved worktrees

All three worktrees remain locked at base `767991a0b` with their tested edits intact:

- `build/resize-order-worktree`: eight edited source/header files; protected storage; incomplete global buildability.
- `build/command-order-worktree`: the rejected incoming-int candidate.
- `build/storage-order-worktree`: the now-integrated storage proposal and regression tests.

Do not reset, clean, or reuse these worktrees.
The latest complete resize patch is:
`decomp_notes/candidates/004E/004EA280_complete_original_parameter_names.patch`.
Its adjacent JSON file records the source hashes.
The matching header state is `e85056e2f3961de9b1206dbd024e84f9e5391538718b35f7f52012accb7a2691`.

Target experiment states preserve compiler dependencies, not every edited caller.
Use complete patches as well as target states.
The manifest format correction preserves all original CRLF files in event
`565df285f013db06896f2727efd8cd90c7029a41f64753059406f9fb1a7e63ee`.
Only their line endings changed; patch bytes and manifest data did not.

## Resume order

1. Read these notes and the preserved candidates before changing source.
2. Carry the committed table repair into future array probes without overwriting their other edits.
3. Record new combined inputs. Do not reuse old audit fingerprints or old qualified table references.
4. Continue public-interface caller recovery through small, evidence-backed variant sets.
5. Resolve the unsafe obstruction emission and remaining closure questions.
6. Audit every affected owner and referenced-data record before array integration.
7. Return to command conversion order, then the four Tech functions.

The separate scratch and accepted-drift questions remain explicit.
Preservation is approved; source integration is not approved for those candidates.
