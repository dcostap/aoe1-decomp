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
- `agent_roles/` contains the root orchestrator, orchestrator, and matching worker role definitions.

A function note stores durable facts, failed approaches, and the next useful approach.
It does not store status or source ownership.
Attempt counts, cohort sizes, and resource budgets in notes describe historical runs.
They do not constrain later work.
Its path is `decomp_notes/functions/<VA-prefix>/<VA>.md`.
A module note uses `decomp_notes/<module>.md`.

## Function status

Use one of these values:

- `matching`: A fresh validation produces an exact match.
- `accepted_drift`: The reviewed source has accepted code generation drift.
- `verified_logic`: A semantic review approved the source.
- `scratch`: The natural source still needs matching work.
- `unresolved`: Source exists, but no build route is proved.

`unresolved` covers functions without one provable compiler recipe.

The registry path identifies the natural source file.
Each function entry stores its status and its symbol when a build exists.
For example, `config/functions/src/point.cpp.json` owns `src/point.cpp`.

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

Generated files belong under `build/`. You can remove that directory when no worker is active.

See `docs/project_reference.md` for the registry schema and command catalogue.
