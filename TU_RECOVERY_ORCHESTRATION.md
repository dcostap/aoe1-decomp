# Translation-unit recovery status

The translation-unit recovery plan in this file is complete and retired.

The repository now uses natural PDB source modules. Each migrated compiland has
one compiler-facing `.c` or `.cpp` source owner. Canonical headers own shared
declarations and header-defined bodies.

Current status lives in:

- `config/source_modules/` for every natural module and function status;
- `config/translation_units.json` for registered exact grouped owners;
- `recovery_notes/translation_unit_closure_audit.md` for compiland closure;
- `recovery_notes/header_owned_standalone_audit.md` for header ownership; and
- `recovery_notes/functions/` for function matching history.

Current workflows are:

- `AGENTS.md` for repository policy;
- `docs/agentic_matching_workflow.md` for matching workers; and
- `docs/main_agent_workflow.md` for orchestration and integration.

Do not restore wrapper translation units, function-fragment includes, or
standalone owners for migrated functions.

Git history preserves the former recovery plan and its phase details.
