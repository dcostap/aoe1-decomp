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
meaningful hypotheses as an initial planning checkpoint. It does not select the
worker's methods or indicate exhaustion. Improvise, change hypothesis classes,
and continue when additional experiments can teach you something.

## Procedure

1. Query the target's status, paths, notes, history, and lease.
2. If it is exact, validate and report it. Do not create another owner.
3. If it is paused, read its source attempt log and bounded session brief.
4. Start a target session.
5. Read the function packet and collect focused binary evidence.
6. Establish canonical field, array, class, global, and ABI ownership.
7. Write the simplest period-plausible reconstruction.
8. Record its first successful check as the baseline.
9. Use evidence to prioritize source, type, layout, control-flow, context, and
   flag hypotheses. Bounded exploratory tests are valid when their result will
   teach you something.
10. Keep the clean source model authoritative. Discard opaque metric-only forms.
11. Do not stop because early approaches fail or progress looks unlikely. End the
    pass only at exact completion, an external constraint, or its assignment
    boundary.
12. Finish the target using the exact or unresolved procedure below.

## Status and leases

Use `query_project_status.py` for live status, paths, notes, work history, target
selection, and lease-aware filtering.

Use `target_session.py` for briefings, claims, recorded checks, clean-source
checkpoints, pauses, and releases.

Open at most two or three complete packets while selecting. Skip selection when
the user assigns a VA. Prefer small, unleased, normal targets with a useful next
state. Review the source comment log before you reassign paused work.

## Evidence order

Start with these tools:

- `target_dossier.py`: compact binary evidence for the assigned function;
- `find_function_donors.py`: ranked exact donors with similar context;
- `query_abi.py`: reviewed and generated ABI provenance;
- `search_asm_donors.py`: exact source donors for one distinctive assembly block.

Dossiers and generated inventories contain hypotheses. Exact donor source gives
strong codegen evidence, but one local donor stub does not prove canonical ABI.
Reviewed reusable ABI entries live in `config\shared_abi_evidence.json`. Only the
main agent updates that file.

Use local declarations for uncertain one-function facts. Change shared headers
only when the assignment authorizes it and reusable binary evidence justifies it.

## Recorded checks

Use the integrated target-session check for the baseline and each meaningful
hypothesis. Record the hypothesis and what the emitted result means. A syntax
repair or unchanged rerun is not a new hypothesis. Restore and validation checks
do not consume the planning budget.

The baseline check pins the clean source. Move that pin only after evidence
improves the natural reconstruction.

Treat duplicate codegen as negative evidence. Do not keep probing the same basin.
Treat the checker's stage as the next emitted-code priority:

1. source model;
2. behavior and ordered calls;
3. ABI and layout;
4. frame, locals, and block structure;
5. exact codegen.

Equal call counts do not prove ordered call parity.

## Focused checker use

Use `check_function.py` for focused call, block, range, and stack diagnostics.
Read its report as evidence. A completed mismatch is not a tool failure.
Its mismatch class names the observed emitted-code pattern. It does not prove
equivalence, change status, or select the worker's method.

## Variant labs

Use `variant_lab.py` only after behavior, calls, cleanup, and layout are known.
Build deliberate source-level axes around one understood mismatch. Broad and
speculative sweeps are valid after the source model is understood. Do not retain
an opaque nonexact result only because it changes compiler output.

Associate a leased compile run with its target session. One lab run counts as one
variant hypothesis family. Review any exact result as source, reduce its context,
and validate it normally. Never auto-promote a lab result.

## Exact finish

1. Review source, flags, ownership, and policy compliance.
2. Run the authoritative function checker.
3. Require `Result: MATCH` and `0.0000%`.
4. Move, do not copy, the source into `src\matching`.
5. Validate again after the move.
6. Release the lease with a reason that records the exact result.

Add a compact `LESSONS.md` entry only for a reusable, non-obvious discovery.

## Unresolved finish

1. Restore the clean source when an experiment changed it.
2. Update the source attempt log with tested facts and the next needed evidence.
3. Run an unchanged final `validation` check.
4. Pin that documented final source as clean.
5. Pause the lease with a specific reason.

Do not keep an opaque nonexact variant only because it has better metrics. The
source attempt log is the durable notebook. Session files under `build\` are
local coordination state.

## Report

Report the target, outcome, probe count, checkpoints, current metrics, and changed
files. Include validation, open questions, and useful possible approaches. A
documented pause is a valid result.
