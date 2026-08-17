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

## Required effort

Do honest, sustained work on the assigned function. Do not stop after a few
failed probes or after you identify a likely compiler-codegen blocker.

Before an unresolved pause, try at least ten meaningful, evidence-led
hypotheses. Ten is a minimum, not a stop target. Continue while useful leads
remain. A normal pass should still use about 20 meaningful hypotheses as its
first planning checkpoint.

Each hypothesis must test a distinct idea about source structure, types, layout,
control flow, lifetimes, translation-unit context, or another supported cause.
Compile it, measure it, and record what the result proves. Do not inflate the
count with syntax repairs, unchanged reruns, cosmetic edits, renamed locals, or
unsupported register guesses.

Use the available evidence. Search exact donors and nearby functions. Inspect the
relevant assembly ranges. Run a structured variant lab when controlled source
axes can test the blocker. Try a different hypothesis class when one class keeps
producing the same codegen basin.

You can stop before ten hypotheses only for one of these reasons:

- the function matches exactly;
- a real external constraint prevents more work; or
- the user or main agent directly tells you to stop.

Low confidence, slow progress, a likely register-coloring issue, or a likely
compiler-context issue is not an external constraint. Documented failure is a
valid result only after this effort standard is met.

An exact result ends open-ended hypothesis search. It does not end the
assignment. Complete the exact-finish retrospective before you report.

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
    pass only at exact completion, a real external constraint, or after the
    required effort and useful evidence-led approaches are exhausted.
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

The first exact result starts the finish process. Do not report immediately.

1. Save and label the first exact checkpoint.
2. Compare it with the last clean nonexact source. List every meaningful source,
   declaration, flag, and context change in the exact transition.
3. Walk those changes back. Revert one independent change at a time and check
   whether the function stays exact.
4. When changes interact, test small grouped reversions. Use bounded delta
   reduction instead of assuming that every change was necessary.
5. Remove incidental aliases, scopes, declarations, context, flags, and control
   forms. Prefer the smallest natural, period-plausible source that stays exact.
6. Do not retain a strange form only because it survived reduction. Apply the
   source-recovery and ownership rules before you accept it.
7. Review source, flags, ownership, and policy compliance.
8. Run the authoritative function checker. Require `Result: MATCH` and
   `0.0000%` on the reduced source.
9. Update the source recovery notes. Record the decisive change, tested
   reversions, required changes, incidental changes, and inseparable groups.
   State evidence separately from explanations that remain hypotheses.
   Mark each proved original defect as `ORIGINAL BUG:`. State the executable
   evidence, observable effect, and why a natural-looking correction is wrong.
10. Do a final source-comment pass. Add short comments only at key blocks where
    they explain intent, non-obvious ownership, required ordering, or strange
    shipped behavior. Use these labels when they help:
    - `BINARY NOTE:` for an unusual fact proved by executable evidence;
    - `ORIGINAL BUG:` for a proved shipped defect;
    - `LIKELY INTENT:` for a useful interpretation that evidence does not prove.
    Do not narrate obvious statements. Do not present a suspected copy mistake
    or developer motive as fact.
11. Pin the reduced exact source and release the lease with the exact result.
    Leave the status move and commit to the main agent.

Report any reusable, non-obvious lesson candidate to the main agent. Do not add
it to `LESSONS.md` without shared-file authorization. A first exact occurrence
can suggest a lesson. Repeated exact or strong donor evidence must support the
reusable claim.

## Unresolved finish

Before this finish, confirm that you met the required-effort rules. Do not use
this procedure as an early exit after a small number of probes.

1. Restore the clean source when an experiment changed it.
2. Update the source attempt log with tested facts and the next needed evidence.
3. Run an unchanged final `validation` check.
4. Pin that documented final source as clean.
5. Pause the lease with a specific reason.

For unresolved source, keep uncertain explanations in the attempt log. Add an
inline code comment only when current evidence establishes a durable source fact.

Do not keep an opaque nonexact variant only because it has better metrics. The
source attempt log is the durable notebook. Session files under `build\` are
local coordination state.

## Report

Report the target, outcome, probe count, checkpoints, current metrics, and changed
files. Include validation, open questions, and useful possible approaches. A
documented pause is a valid result. For an exact result, also report the
walkback tests and why the retained source is the smallest supported form.
