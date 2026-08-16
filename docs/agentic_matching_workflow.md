# Matching-worker workflow

Read this file only when assigned one ordinary function. `AGENTS.md` owns all
repository-wide rules. This file owns the matching procedure.

## Role limits

- Work on one assigned `normal` function.
- Claim it before editing.
- Do not force an active lease.
- Do not promote to `accepted_drift` or `verified_logic`.
- Do not commit.
- Keep one compiler-facing source owner.

A claim is one bounded pass, not the lifetime of the function. Use about 20
meaningful hypotheses as a planning limit. Stop earlier when evidence runs out.

## Procedure

1. Query the target's status, paths, notes, history, and lease.
2. If it is exact, validate and report it. Do not create another owner.
3. If it is paused, read its source attempt log and bounded session brief.
4. Start a target session.
5. Read the function packet and collect focused binary evidence.
6. Establish canonical field, array, class, global, and ABI ownership.
7. Write the simplest period-plausible reconstruction.
8. Record its first successful check as the baseline.
9. Test only evidence-backed source, type, layout, control-flow, context, or flag
   hypotheses.
10. Keep the clean source model authoritative. Discard opaque metric-only forms.
11. Stop when exact, blocked, or out of useful hypotheses.
12. Finish the target using the exact or unresolved procedure below.

## Status and lease commands

For an assigned target:

```bat
python tools\query_project_status.py --va <VA> --paths --notes --leases --work-history
python tools\target_session.py brief --va <VA>
python tools\target_session.py start --va <VA> --owner <owner> --budget 20
```

For target selection:

```bat
python tools\query_project_status.py --unclaimed --normal --no-blockers ^
  --unleased --smallest --triage --work-history --leases --limit 12
```

Open at most two or three complete packets while selecting. Skip selection when
the user assigns a VA.

## Evidence order

Start with these tools:

```bat
python tools\target_dossier.py --va <VA>
python tools\find_function_donors.py --va <VA> --limit 20
python tools\query_abi.py --va <VA>
```

Use focused queries when needed:

```bat
python tools\query_abi.py --symbol <name>
python tools\query_abi.py --class <name>
python tools\query_abi.py --global <name>
python tools\search_asm_donors.py --va <VA> --range +START-+END
```

Dossiers and generated inventories contain hypotheses. Exact donor source gives
strong codegen evidence, but one local donor stub does not prove canonical ABI.
Reviewed reusable ABI entries live in `config\shared_abi_evidence.json`. Only the
main agent updates that file.

Use local declarations for uncertain one-function facts. Change shared headers
only when reuse and binary evidence justify the change.

## Recorded checks

Use the integrated checker for the baseline and each meaningful hypothesis:

```bat
python tools\target_session.py check --va <VA> --owner <owner> ^
  --kind baseline --note "canonical ownership and natural source family" -- --detail concise

python tools\target_session.py check --va <VA> --owner <owner> ^
  --kind <kind> --note "hypothesis and observed meaning" -- --detail concise
```

Valid kinds are `baseline`, `behavior`, `abi`, `layout`, `control-flow`,
`liveness`, `context`, `flags`, `variant`, `restore`, `validation`, and `other`.
A syntax repair or unchanged rerun is not a new hypothesis. `restore` and
`validation` do not consume the planning budget.

The baseline check pins the clean source. Move that pin only after evidence
improves the natural reconstruction:

```bat
python tools\target_session.py pin-clean --va <VA> --owner <owner> --note "reason"
```

Treat duplicate codegen as negative evidence. Do not keep probing the same basin.
Treat the checker's stage as the next emitted-code priority:

1. source model;
2. behavior and ordered calls;
3. ABI and layout;
4. frame, locals, and block structure;
5. exact codegen.

Equal call counts do not prove ordered call parity.

## Focused checker use

```bat
python tools\check_function.py --va <VA> --detail concise
python tools\check_function.py --va <VA> --call-map-unmatched --map-limit 40
python tools\check_function.py --va <VA> --block-map-differences --map-limit 40
python tools\check_function.py --va <VA> --range orig:+START-+END
python tools\check_function.py --va <VA> --stack-map --no-build
```

Use `--no-build` only with a current fingerprinted artifact. A normal mismatch can
exit with status 1. Read the report instead of treating that status as a tool
failure. Use `python tools\check_function.py --help` for option syntax.

## Variant labs

Use `variant_lab.py` only after behavior, calls, cleanup, and layout are known.
Build deliberate source-level axes around one understood mismatch. Avoid blind
whole-function products and compiler-only tricks.

Pass `--session-owner <owner>` during a leased compile run. One lab run counts as
one `variant` hypothesis family. Review any exact result as source, reduce its
context, and validate it normally. Never auto-promote a lab result.

Use `python tools\variant_lab.py --help` for template syntax and commands.

## Exact finish

1. Review source, flags, ownership, and policy compliance.
2. Run `python tools\check_function.py --va <VA>`.
3. Require `Result: MATCH` and `0.0000%`.
4. Move, do not copy, the source into `src\matching`.
5. Validate again after the move.
6. Release the lease.

Add a compact `LESSONS.md` entry only for a reusable, non-obvious discovery.

## Unresolved finish

1. Restore the clean source when an experiment changed it.
2. Update the source attempt log with tested facts and the next needed evidence.
3. Run an unchanged final `validation` check.
4. Pin that documented final source as clean.
5. Pause the lease with a specific reason.

```bat
python tools\target_session.py restore-clean --va <VA> --owner <owner>
python tools\target_session.py check --va <VA> --owner <owner> ^
  --kind validation --note "final documented source" -- --detail concise
python tools\target_session.py pin-clean --va <VA> --owner <owner> --note "final source"
python tools\target_session.py pause --va <VA> --owner <owner> --reason "next evidence needed"
```

Do not keep an opaque nonexact variant only because it has better metrics. The
source attempt log is the durable notebook. Session files under `build\` are
local coordination state.

## Report

Report the target, outcome, probe count, checkpoints, current metrics, and changed
files. Include validation and the next evidence-backed lead. A documented pause
is a valid result.
