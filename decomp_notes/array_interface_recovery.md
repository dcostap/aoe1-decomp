# Array interface recovery

## Current integration review

Read `decomp_notes/array_integration_checkpoint.md` for the newer complete protected build.
It replaces the earlier build-blocker list and the 28-record diagnostic comparison below.
The first protected comparison records 46 changed owners. Integration review remains open.
The static-object caller repair is integrated in `e3c43d2ff`.

## Resumed work: 2026-09-09

Read `decomp_notes/session_handoff_array_storage.md` for current worktrees and validation records.
Two independent decision-module caller repairs were integrated in `172ea2295`.
The shared protected-array proposal remains isolated.

An out-of-class `contains` definition restores the exact 52-byte obstruction body without changing the method body.
The protected state is `a542e3dc18564e25d976c82c858929ee2f0dcd4cb1ded994c228ef7d9279e4ff`.
A diagnostic public-field build passes all 2544 matching targets across 90 modules.
All five earlier matching regressions disappear in that diagnostic state.
This result does not support public storage or approve the other changed owners.
The current-main comparison reports 28 changed owner records among 3584 emissions.

Eight movement count resets now use `zeroNumber()` in the protected proposal.
The reset-only control preserves all 103 movement owners.
Review found two existing `doMove` control-flow defects, recorded in its function note.
A separate repair remains isolated. Four other caller modules still need protected-access recovery.

## Scope

Base: `767991a0b6ca728d3f009431454ad822926d4945`.
The resize worktree holds the source proposals.
Main does not include these array proposals. Their registry entries remain unchanged.
The separate table-storage repair was integrated in `129e0f6a0`.
No game executable was run.

## Checked source repairs

| Target | Result | State |
| --- | --- | --- |
| `004EA280` victory condition | `MATCH`, `0.0000%`, 1,231 bytes | `resize-order-complete-strategy-interface` |
| `00413150` unit save | `MATCH`, `0.0000%`, 758 bytes | `resize-order-complete-unit-interface` |
| `00413A20` checked attacking-unit access | 125-byte match retained | `resize-order-public-unit-save` |
| `00413450` unit load | `MATCH`, `0.0000%`, 949 bytes | `resize-order-public-unit-load` |
| `00414E80` notify | `MATCH`, `0.0000%`, 177 bytes | `resize-order-public-unit-queries` |
| `00415B50` closest attacker | 328-byte match retained | `resize-order-public-unit-queries` |
| `004171F0` run away from attackers | 357-byte match retained | `resize-order-public-unit-queries` |

Each listed state passed its matching-neighbor checks.
These results apply to their recorded inputs, not every later header probe.

The strategy module uses only the public array interface.
A count getter inside its expanded victory loop failed.
The complete normal loop restored all original target bytes.

Unit load uses separate event scopes instead of a forced union.
Original PDB records support both event types and their shared stack address.
See the function notes for `00413450`.

The complete public operations in `004180C0 processNotify` change none of 117 emitted owner descriptions.
That comparison includes bytes, relocations, and referenced data.
The function still has 12 original differences.
It is not an approved original-behavior result.

The final count-only unit variants retain their control groups.
The separate normal-update variant changes a later phase group and was not selected.
Existing scratch mismatches and boundary warnings remain explicit.

## Complete closure

The fixed public-unit snapshot covers 90 modules and 3,584 emitted functions.
Its complete comparison identifies 82 changed owner records.
Five matching regressions remain:

- `00441E00 rehook`: memory-read order needs review.
- `0045A030 get_border_type`: prior bounded register proof still applies.
- `0046B5E0 obstruction`: the proved stack-overlap defect still applies.
- `004C6DA0 changeInfluenceMap`: x87 changes need review.
- `00533410 handle_points_high_attribute_amount`: prior bounded register proof still applies.

Proof revalidation compares complete owner descriptions against the previously checked inputs.
It also checks the preserved proof input hashes.
It does not approve other owners or integration.

Closure event: `84caebb823d72e890f4f174e4ffcfe51a7f2aab3aec14455658db9d3126112ae`.
Proof artifact: `build/resize-public-unit-proof-revalidation.json`.

## Later isolated probes

The path-system public interface changes `0046B6E0 findTilePath`.
Its differences include allocation, memory-read, and floating-point instruction order.
That owner remains unreviewed. Do not infer that either the control or proposal is correct.

Original PDB field list `0x1683` marks all four array storage fields protected.
The protected-storage probe removes the extra public label.
Other modules still access those fields, so that probe is not globally buildable.
It does not repair obstruction.

Scoped PDB records name subscript parameter `v`, resize parameter `s`, and contains/add/remove parameter `r`.
Restoring those names also leaves obstruction unchanged.
Current probe state: `resize-order-original-parameter-names`,
`e85056e2f3961de9b1206dbd024e84f9e5391538718b35f7f52012accb7a2691`.

The writable-table declaration lab also leaves obstruction at 54 bytes with 39 differences.
It does not approve a qualifier change.
The table storage defect needs its own review.
See `decomp_notes/obstruction_storage_repair.md`.

## Preservation

Complete source snapshots and hash manifests include:

- `decomp_notes/candidates/004E/004EA280_complete_public_unit_queries.patch`.
- `decomp_notes/candidates/004E/004EA280_complete_public_path_interface.patch`.
- `decomp_notes/candidates/004E/004EA280_complete_protected_storage_probe.patch`.
- `decomp_notes/candidates/004E/004EA280_complete_original_parameter_names.patch`.

The last snapshot includes the parameter-name probe.
Target states also preserve their own dependencies; they are not complete worktree snapshots.

Unit and strategy module checks also pass under the protected storage and original parameter names.
Run events: `327a169ecc6b908ccab5a8987bed6dc02c55b950a8e064ad2e51b4766c6b7169`
and `91898f704e31b0d6416fba53de941874d509191f5a932b11bfe764fbbba4e1d9`.

Event `73dc322a0cbed6602685736531641b840ae791a6d8f983b7f7694b33f17cf5d5` preserves the complete lab archives.
It includes the failed direct-count command variants, which were not applied.

## Integration limit

Do not integrate the shared array repair until every affected owner passes review.
Do not replace these defects with compiler controls, artificial storage, or weaker alias assumptions.
