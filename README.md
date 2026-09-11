# Age of Empires 1 decompilation

This project recovers the 1998-07-17 Rise of Rome beta source.

## Source tree

- `src/` contains natural translation units.
- `include/` contains shared declarations and inline functions.
- `config/functions/` is the formal registry for every normal function.
- `config/flags/` contains the six canonical VC5 compiler profiles.
- `inventory/` contains generated reference data. Do not edit it.
- `decomp_notes/` contains durable function and module notes.
- `logic_reviews/` contains semantic-review ledgers at `logic_reviews/<VA>.md`.
- `logic_matching/` preserves behavior-recovery waves, attempts, and candidates.
- `runtime/` contains the local complete game runtime. It is ignored except for its README.
- `agent_roles/` contains matching and behavior-recovery role definitions.

A function note stores durable facts, failed approaches, and the next useful approach.
It does not store status or source ownership.
Attempt counts, cohort sizes, and resource budgets in notes describe historical runs.
They do not constrain later work.
Its path is `decomp_notes/functions/<VA-prefix>/<VA>.md`.
A module note uses `decomp_notes/<module>.md`.

## Function status

Use one of these values:

- `matching`: A fresh validation produces an exact match.
- `accepted_drift`: Semantic review proves the canonical source behavior is
  equal. This is a completed result, not matching debt.
- `verified_logic`: A semantic review approved the source.
- `new_verified_logic`: The behavior-recovery workflow completed and reviewed the source. The old `verified_logic` set stays separate.
- `scratch`: The natural source still needs matching work.
- `unresolved`: Source exists, but no build route is proved.

`unresolved` covers functions without one provable compiler recipe.

Do not tune an `accepted_drift` function only to remove insignificant byte
differences. Reopen it when new behavior, ownership, type, period-source, or
simplification evidence can improve the source model.

The registry path identifies the natural source file.
Each function entry stores its status and its symbol when a build exists.
For example, `config/functions/src/point.cpp.json` owns `src/point.cpp`.

## Matching workflows

The existing matching workflow remains the default: the orchestrator reviews worker proposals.
Select the optional variation with `Workflow: matching with reviewers`.
In that mode, the worker investigates, an independent reviewer checks the stopped worktree, and the orchestrator routes and integrates results.
The orchestrator does not prepare every technical question or repeat valid reviewer analysis.
See `docs/matching_with_reviewers.md` and `agent_roles/matching_reviewer.md` for the launch contract and procedures.
Both workflows require `docs/experiments.md` and the same correctness standards.

## Behavior recovery

This separate, opt-in workflow gives each worker a fresh repository and one target function.
Workers reconstruct a blank target or review a supplied candidate without old matching notes or history.
One orchestrator preserves attempts, selects candidates, reviews behavior, and integrates results.
See `agent_roles/behavior_recovery_orchestrator.md` for the workflow and tool use.
Copy `agent_roles/behavior_recovery_worker.md` into each prepared workspace as its root `AGENTS.md`.
Run `python tools/behavior_recovery.py --help` for preparation and collection commands.

## Common commands

Show the current project state:

```text
python tools/query_project_status.py --summary --normal
```

Select ordinary matching work:

```text
python tools/query_project_status.py --scratch --normal --smallest --limit <LIMIT>
```

Inspect one function:

```text
python tools/query_project_status.py --va 0047A3A0 --paths --notes --work-history
```

Check one function:

```text
python tools/check_function.py --va 0047A3A0
```

Compile and audit all configured translation units:

```text
python tools/audit_translation_unit_functions.py --jobs <JOBS> --output-dir build/audits/current
```

Run the tests:

```text
python -m pytest -q
```

Compile all current game sources and attempt an executable link:

```text
python tools/build_executable.py --help
python tools/build_executable.py
```

The executable links. This does not prove complete source recovery or game behavior.
See `docs/executable_build.md` for inputs, reports, and remaining requirements.
See `docs/reference_validation.md` for linked checks and unresolved emission audits.
See `docs/reference_builds.md` for older-build searches and named disassembly.

Prepare a runtime copy for a rebuilt executable:

```text
python tools/prepare_runtime.py --exe build/executable/<run>/empiresx.exe --output build/runtime/installed_beta/rebuilt
```

The tool uses the root-local `runtime/` folder by default.

Generated files belong under `build/`. You can remove that directory when no worker is active.

See `docs/project_reference.md` for the registry schema and command catalogue.
