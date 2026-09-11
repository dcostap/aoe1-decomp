# Project reference

This document describes the function registry and repository command tools.
Run a command with `--help` before you use it.

For the separate linked-reference audit, see [Linked-reference audit](linked_reference_audit.md).
It checks linked call and reviewed storage targets. Unknown coverage does not count as proof.
See [Reference validation](reference_validation.md) for strict target checks and unresolved emission audits.
See [Older-build tools](reference_builds.md) for hash-pinned counterpart searches and disassembly.

## Agent roles

Role definitions live under `agent_roles/`:

- `root_orchestrator.md` defines direct user interaction and optional hierarchical orchestration.
- `orchestrator.md` defines one-worktree matching worker management and review.
- `matching_worker.md` defines matching work for one natural translation unit.
- `matching_reviewer.md` defines independent technical review in the optional reviewer variation.
- `behavior_recovery_orchestrator.md` defines independent reconstruction waves and integration.
- `behavior_recovery_worker.md` becomes each behavior workspace's root `AGENTS.md`.

The existing matching workflow remains the default.
Select `Workflow: matching with reviewers` to use `docs/matching_with_reviewers.md`.
That document changes review routing, not correctness standards, registry schema, or command syntax.
It requires explicit reviewer model, thinking level, and capacity settings in addition to the matching worker contract.

The root orchestrator can run a normal orchestration directly.
For large work, it can manage user-selected reusable orchestrator worktree slots.
The user must supply both exact subagent models, both thinking levels, both concurrency limits, and tool jobs.

## Function registry

`config/functions/` contains one JSON file for each natural source owner.
The registry path mirrors the source path.

Examples:

- `config/functions/src/point.cpp.json` describes `src/point.cpp`.
- `config/functions/include/stat_obj.h.json` describes `include/stat_obj.h`.

Each normal function occurs in one registry file.
The registry does not store note paths.

A buildable source file has this form:

```json
{
  "schema": 1,
  "header": "include/example.h",
  "pdb_source_path": "C:\\msdev\\work\\age1_x1\\example.cpp",
  "build": {
    "flags": "gx"
  },
  "functions": {
    "00400000": {
      "status": "matching",
      "symbol": "?example@@YAHXZ"
    }
  }
}
```

### File fields

- `schema` selects the registry format. The current value is `1`.
- `header` names the main declaration header when one exists.
- `pdb_source_path` records the original PDB source path.
- `build.flags` selects one response file from `config/flags/`.
- `pdb_no_line_info` records that the PDB compiland has no line records.
- `pdb_module_stream_evidence` names supporting generated evidence when needed.
- `functions` maps each eight-digit VA to its function fields.

### Function fields

- `status` is `matching`, `accepted_drift`, `verified_logic`, `new_verified_logic`, `scratch`, or `unresolved`.
- `symbol` is the decorated object symbol for a configured build.
- `emission_source` selects a configured natural C/C++ module for a header-owned function.
  The header keeps source ownership. The selected module supplies its existing compiler profile and emitted object.
  Do not give the header a separate build or copy its body into the selected module.

`matching` and `accepted_drift` are both completed recovery results.
`matching` has positional byte equality. `accepted_drift` has canonical source
and a complete semantic review that proves equal behavior. Do not put accepted
drift back into matching work only because bytes differ.

A function without a proved build route has no `symbol` field.
Source, symbol, and compiler profile do not depend on matching status.

`new_verified_logic` records completed behavior recovery under the behavior-recovery workflow.
It requires a semantic review ledger and does not claim exact bytes.
The existing `verified_logic` set remains separate and unchanged.

### Compiler profiles

The profiles are:

- `default`
- `gx`
- `gx_no_fpo`
- `gx_directplay`
- `c_no_intrinsics`
- `ole32_directplay`
- `unoptimized`: the reviewed Tech `/Od` route

`config/toolchain.json` selects the pinned compiler and its environment.
The response files contain compiler arguments only.

## Daily commands

- `behavior_recovery.py` prepares behavior workspaces and preserves attempts and integration candidates.
- `query_project_status.py` queries status, paths, notes, and history.
- `target_session.py` manages function notebooks and translation-unit reservations.
- `experiment_history.py` preserves durable experiment branches and reproduces their compiler inputs.
  Read `docs/experiments.md` for the pilot workflow.
  `target_session.py branches --va VA` shows the saved states and findings.
- `compiler_gate.py` protects live shared-source integration from compiler jobs.
- `check_function.py` performs the authoritative one-function comparison.
- `audit_translation_unit_functions.py` compiles and checks configured source files.
- `validate_translation_units.py` validates configured natural-source builds.
- `build_executable.py` compiles all current game sources and attempts an executable link.
- `probe_masm.py` tests pinned modern MASM objects with VC5 LINK, including C++ member calls and MMX.
- `probe_compression_binary.py` tests the preserved compression dependency against native round trips, zlib, and original game data.
- `audit_link_symbols.py` finds possible declaration conflicts in a failed executable build.

See `docs/executable_build.md` for executable inputs, reports, and completion requirements.

Use `--group` for explicit translation units. Use repeatable `--affected-by`
paths for the transitive dependency union of shared-source changes:

```text
python tools/audit_translation_unit_functions.py \
  --affected-by include/panel_ez.h \
  --affected-by include/pnl_dlg.h \
  --jobs JOBS
```

The JSON report records the affected paths, selected groups, matching
dependencies, and each group's complete input fingerprint.

## Project audits

- `audit_matching_owners.py` checks PDB ownership for matching functions.
- `audit_translation_unit_flags.py` checks compiler profiles against evidence.
- `audit_translation_unit_symbols.py` checks symbols in compiled objects.
- `validate_candidate_tu.py` validates a proposed source build.
- `validate_utmarray.py` checks the `ManagedArray<int>` reconstruction.
- `probe_toolchain.py` checks deterministic compiler output.

## Investigation commands

- `target_dossier.py` collects focused evidence for one function.
- `find_function_donors.py` ranks exact source donors.
- `query_abi.py` queries ABI evidence.
- `search_asm_donors.py` searches for assembly patterns.
- `variant_lab.py` compares controlled source variants.
- `vc5_ir_capture.py` captures VC5 compiler-stage output.

Function packets, `target_dossier.py`, and `query_abi.py` include procedure-scoped
PDB symbols. These records identify function statics, stack symbols, register
symbols, names, types, storage addresses, and owning procedures. Positive PDB
ownership evidence is strong. A missing record does not prove that no source
variable existed.

The generated index is `inventory/pdb/scoped_symbols.json`. It binds
`S_LDATA32`, `S_BPREL32`, and `S_REGISTER` records to their lexical procedure.

Read `PdbScopedSymbols` before you infer locals or shared globals from assembly.
The global inventory marks indexed function-static addresses and suppresses
shared declarations for them. Regenerate the index with:

```text
python tools/generate_pdb_scoped_symbol_reference.py --cvdump <cvdump.exe>
```

Resource limits come from the user or the current orchestration.
Tools do not select worker counts, job counts, timeouts, or search budgets.
Parallel commands require an explicit `--jobs` value.
Optional result limits and timeouts default to unlimited or disabled.

Build artifacts use content fingerprints and per-module operating-system locks.
Concurrent users reuse completed work for the same module.
Donor and assembly-search indexes also use shared locked caches under `build/`.

## Low-level comparison commands

- `build_function.py` builds one configured function.
- `diff_function.py` compares original and rebuilt output.
- `extract_original_function.py` extracts original bytes and assembly.
- `extract_obj_function.py` extracts one function from a COFF object.

## Inventory and metadata generators

These commands regenerate reference data, reports, or reviewed manifests:

- `generate_master_inventory.py`
- `generate_function_packets.py`
- `generate_function_registry_inventory.py`
- `generate_class_interface_reference.py`
- `generate_global_reference.py`
- `generate_type_reference.py`
- `generate_pdb_source_reference.py`
- `generate_pdb_module_stream_reference.py`
- `generate_pdb_scoped_symbol_reference.py`
- `generate_toolchain_supplied_manifest.py`

Do not edit generated inventory files by hand.
Put temporary reports and compiler output under `build/`.
