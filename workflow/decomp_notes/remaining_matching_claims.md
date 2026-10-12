# Remaining matching claims

## ICInfo identity closure: 2026-09-13

Original call `00521B3A` has bytes `E8 65 96 02 00` and targets `0054B1A4`.
The target has bytes `FF 25 B4 A7 88 00` and jumps through IAT slot `0088A7B4`.
The original PE import directory assigns this slot to `MSVFW32.dll!ICInfo`.
The preserved original PDB public dump independently contains these records:

```text
S_PUB32: [0001:0014A1A4], Flags: 00000000, _ICInfo@12
S_PUB32: [0005:000007B4], Flags: 00000000, __imp__ICInfo@12
```

The original section bases map these records to the thunk and IAT slot above.
Add only `_ICInfo@12` at `0054B1A4`, with no aliases.
Existing EXE and PDB hash checks remain active.
This proves target identity, not the external DLL implementation.
See `audit_repair_20260913.md` for validation and preserved experiment records.

## Reference-gap closure: 2026-09-11

The `00405850` direct-target gap recorded below is now resolved.
Original PDB publics independently prove the complete `findPath` and `doMove` symbols.
The original REL32 calls reach those same entries.
The two reviewed identity records introduce no aliases or source changes.
Fresh target checks leave only the completed two-byte register drift, with zero unknown direct targets.
See `../logic_reviews/00405850.md` for input hashes, exact call addresses, preserved evidence, and remaining storage limits.
The historical linked-reference totals below are not refreshed by this focused review.

Base: `ef479e9e7`. All executable inspection is static. No game is run.

## Original target identities

### Behavior

The original EXE supplies 45 direct call destinations across 31 matching owners.
Original PDB public records independently name all 29 distinct destinations.
Each destination has exactly one public name. No rebuilt call supplies original identity.

Eighteen targets are import thunks. Each starts with `FF 25` and a four-byte IAT address.
Each IAT address belongs to the original import directory.
The original PDB also names that slot with the corresponding `__imp_` symbol.
This proves the thunk and import-slot connection, not the implementation of an external DLL.

### Source

The complete decorated names remain in `config/reviewed_reference_identities.json`.
The new records have no aliases. Existing EXE, PDB, and library hash checks remain active.
Earlier records retain their evidence in `target_evidence_pass.md` and `crt_reference_identity_review.md`.
The four game targets retain their classes, parameter types, and method kinds.
The two compiler helpers retain their complete callback signatures.
The compression symbols agree with the existing approved binary manifest; this review grants no new binary permission.

The original section table supplies each public record's VA.
The proof script reads the original REL32 bytes, adds the signed displacement, and checks the exact public name.
It also preserves the call bytes, caller offsets, target entry bytes, import names or ordinals, and IAT public names.
The public dump comes from `cvdump -p orig/age1_x1.pdb`, preserved in the prior target-pass archive.

### Bytes

The baseline state is `1ee3575fc93d6e7d8ed98709a0719f60f519a69f81b42b7d75d997a5eef01466`.
Its isolated run is `a8de7718e619bb85365a619154460d4adbf26032f597636cc45781bb997e584a`.
The baseline target has six differences. Its module has five unvalidated matching claims.
A main-worktree experiment run was refused; the baseline was then reproduced and checked in an isolated workspace.
No result from that refusal was treated as a compile or byte test.

### Integration

Retain the 29 independent identity records, subject to fresh checks.
No game source, compiler recipe, registry status, or exactness rule changes in this repair.
Unknown storage, initial values, and external behavior remain separate validation limits.
Further resize, RESENDER, and Tech findings will remain separate from this evidence-only repair.

## Final claim corrections

The fresh 225-module evidence audit resolves all 31 selected gaps.
It leaves two real protected-versus-public resize disagreements, not missing identity evidence.

| Owner | Failed call sites | Differing call-address bytes | Registry correction |
|---|---:|---:|---|
| `004EA280 setVictoryCondition` | 13 | 52 | matching to scratch |
| `004EF4E0 save` | 4 | 16 | matching to scratch |

Do not retain an unsupported matching label while its repair remains open.
These corrections do not repair either function or weaken the audit.
The checker still rejects the differing complete symbols. No protected/public alias is added.

The earlier array experiments remain preserved in `target_evidence_pass.md` and the associated candidate patches.
This pass tests ordinary rule additions, direct resize delegation, and an in-class add definition.
The caller trial has 1,210 differing bytes. Both delegation forms have 1,192.
None restores the original leading insertion code. Keep these source changes isolated.

Direct resize delegation retains the original post-allocation number reload at `004DEA46`.
The earlier subscript rewrite can cache the insertion index before allocation instead.
This distinction is a useful repair constraint, not proof that an allocation callback actually changes this array.
The original caller and full affected closure still need proof.
Do not use compiler pragmas, extra friends, or replacement wrappers to conceal that open boundary.

The final pass separately promotes the reviewed RESENDER constructor.
See `resender_repair.md` for the complete closure, rejected alternatives, and source review.
See `tech_stack_review.md` for the two literal repairs and the rejected stack-drift approval.

## Final validation

- All 225 audit modules compile. All 4,886 matching labels pass, including every prior passing claim.
- The registry has 4,886 matching, 287 accepted-drift, 16 verified-logic, and 237 scratch functions.
- One separate accepted-drift reference gap remains at `00405850`; it is not a pass.
- The executable build compiles 226 C/C++ sources and one assembly source, then links without unresolved symbols.
- All 6,953 function emissions agree between the audit objects and the executable objects.
- The complete game-globals object remains unchanged except for its COFF timestamp.
- Linked references: 6,873 pass, 5,276 unknown, zero failures. Unknowns do not prove linked storage or gameplay.
- All 133 header entries report `all_emissions_match`.
- All 414 tests and 31 subtests pass. Translation-unit, line-ending, and diff checks also pass.
- The first test run found a stale header-count assertion. The preserved second run checks the updated count.

The full owner comparison reports 37 changed records, including equal-score and constant-pool changes.
Four bodies change instructions: RESENDER, the existing command-order closure, and the two Tech comparisons.
The other records contain proved private-symbol renames or unchanged constant operands within the changed Tech pool.
The two detailed source reviews explain these differences and their limits.

Reports live under `build/claims-final/`.
The executable build is `build/executable/claims-final/20260908T182352017500Z`.
The complete candidate patch targets base `ef479e9e7` and contains both source repairs and all registry corrections.
The locked `build/claims-worktree` retains the rejected experiments. No source trial depends only on that workspace.
No game was run, and nothing was pushed.

## Preserved evidence

Archive: `build/claims_pass_evidence.tar.gz`, also stored as immutable object
`c1cd5327841b4a396bbadd8a6e5229b15d47b8ade162abd16f0c61ea038f9173`.
Its event is `7fcdb776bc1e9b12f69510a2c810557f95363cabbe6d387f95e44603a6e43fed`.
The final Tech finding is `70313687ca357927a35cd82b766ccd130ee6eab4d675d8f84983b0bcffc3d417`.
The archive contains 1,343 entries. Its final audit report matches the current report hash.

The preservation check verifies eighteen states, twenty-two events, 216 referenced objects, and seventy external input hashes.
All base commits remain reachable. Both final compiler contexts still match the tested source and configuration.
The immutable records separately retain the rejected Tech approval draft and every recorded source experiment.
