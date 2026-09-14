# Reference and emission validation

Keep three results separate:

1. Local function instructions, boundaries, owner, and direct symbols.
2. Actual linked function and storage destinations.
3. Reviewed initial bytes and pointer fields.

Normal local and grouped checks also inspect supported numeric operands in the complete compiled object.
They report instruction agreement separately from dependency results. A proved constant difference blocks `MATCH`.
Unknown external storage still requires the linked checks in `image_dependency_audit.md`.

No current tool proves complete game behavior or complete storage coverage.

## Strict local direct targets

The local checker uses original FPO linkage names and reviewed symbol supplements.
It also accepts decorated PDB procedure names where available.
Qualified display names do not prove linkage identity.

The check keeps class names, overloads, argument decoration, and calling conventions.
Reviewed CRT aliases apply only at explicit target addresses in `config/reviewed_reference_identities.json`.
Original public records and pinned weak-external records support those aliases. Changed evidence hashes stop validation.
See `decomp_notes/crt_reference_identity_review.md`. No C++ name normalization is permitted.
Missing or conflicting original symbols produce explicit unknown results and prevent `MATCH`.
Nonzero direct-call relocation addends also require more evidence.
External transfers without COFF symbol relocations cannot establish exactness.

Unsupported storage relocations remain explicit coverage gaps in local reports.
Their address-byte comparison does not prove storage ownership or initial values.
Use the linked audits for those separate checks.

Translation-unit reports preserve detailed reference failures and unknowns.
Their exit status now fails when a claimed matching owner does not pass.
Expected scratch differences do not fail that exact-claim gate.
Reports include validation fingerprints and hashes of checked objects.
Do not reuse old reports after validation rules or original identity evidence change.

Direct-target diagnostics compare instructions at the same byte offset.
A shifted function can put unrelated calls at that offset.
Such a disagreement blocks positional exactness. It does not alone prove that source calls the wrong helper.
Inspect call context and control flow before changing a call.
Equal call counts or target sets do not prove equal behavior.

## Linked input identity

Fresh executable builds record hashes for the EXE, map, input objects, and verbose linker log.
They also record the function-registry fingerprint.
Linked audits reject changed artifacts and mismatched registry snapshots.
Object-emission audits also check recorded source input hashes against current files.

Older builds without these recorded hashes require a fresh build.
Do not add hashes afterward to make an unverified historical pair appear verified.

## Header and Tech emission audit

```text
python tools/audit_header_emissions.py --help
python tools/audit_header_emissions.py --build build/executable/RUN --output build/validation/header_emissions.json
```

This audits all header-owned functions and other unresolved entries through real compiled objects.
It does not compile headers alone or create source wrappers.
For each independently known original symbol, it finds and checks every emitted copy.
The map must identify one emitting object, or explicit linker records must prove the folded selection.

Results are:

- `all_emissions_match`: every found copy passes, and the linked selection is proved;
- `emission_differences`: the linked selection is proved, but at least one copy differs; or
- `unknown`: original identity, emission, or linked selection remains unproved.

Identical-code folding can make the map name an object that did not emit that symbol.
The tool reads explicit replacement chains from the hash-checked VC5 verbose log.
It checks both named object emissions, the final map selection, and the linked function bytes.
Folded byte proof currently requires relocation-free bodies. Unsupported cases remain unknown.
The report separates the original emitter from the physical symbol that the linker selected.
It never treats different source symbols as interchangeable aliases.
Missing or changed logs cannot supply folding proof. Address sharing or byte similarity alone is insufficient.
See `decomp_notes/header_linker_folding.md` for the controlled `/OPT:NOICF` probe.

The report preserves object hashes, source recipes, input fingerprints, and each comparison.
It does not change registry status or prove linked storage and initial data.

Header registry entries can now select an `emission_source` with one exact `symbol`.
The source remains owned by its header. Normal build and checker commands use the designated natural module.
The module audit includes each designated header entry once. The emission audit still checks all emitted copies.
Initial route integration sets these entries to scratch, not matching. Source and storage review remain separate.

## Reviewed storage and pointer tables

Run `audit_linked_references.py` against the same hash-recorded build.
See `docs/linked_reference_audit.md` for commands.

Reviewed ranges in `config/linked_reference_owners.json` establish owner starts and sizes.
`check_initial_bytes` permits initial-storage comparison for a reviewed layout.
`pointer_offsets` identifies four-byte pointer fields within that layout.
The tool compares remaining bytes directly and resolves each pointer through independent owners.
This supports reviewed virtual-table bounds without assuming every emitted table has the original size.

Unreviewed layouts and unknown pointer targets remain unknown.
Reports rank unknown target addresses by reference count and list their callers.
Use that list to choose the next shared ownership investigation.

Run `audit_global_initializers.py` separately for its broader named primitive-data checks.
Constructed objects, unreviewed layouts, startup effects, and computed addresses still need more evidence.
