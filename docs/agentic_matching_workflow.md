# Matching worker workflow

Use this workflow for one assigned normal function.

## Scope

The assignment gives you:

- one function VA;
- one natural translation unit;
- one lease owner name;
- allowed source and function-note paths; and
- a unique build output directory.

One worker owns the translation unit at a time. Other workers can edit other
translation units in the same worktree.

Edit only the assigned function body and its function notes. Do not edit
another function in the source file.

Do not edit headers, global storage, config, tests, tools, shared notes, or
`LESSONS.md` unless the assignment permits it.

Do not stage or commit files. Do not use Git restore, reset, clean, or checkout.
Preserve all unrelated worktree changes.

Do not use web search. Use repository evidence and the original executable.

## Goal

Make useful matching progress with natural, period-plausible source.

A useful result can be:

- an exact match;
- a better binary-supported reconstruction;
- a proved ABI or source fact;
- a disproved hypothesis that prevents repeated work; or
- a complete accepted-drift proposal.

Do not decide `accepted_drift`. The main agent reviews that proposal.

Do not propose or select `verified_logic`. Leave a stuck function in `scratch`.

## Start

Run each tool with `--help` before its first use.

1. Check the target and translation-unit lease:

   ```text
   python tools/query_project_status.py --va <VA> --paths --notes --leases --work-history
   ```

2. Use the assigned session.

   If the coordinator preclaimed the active lease, do not start it again. Read
   the briefing instead:

   ```text
   python tools/target_session.py brief --va <VA>
   ```

   Otherwise, start the session:

   ```text
   python tools/target_session.py start --va <VA> --owner <OWNER>
   ```

   The command rejects another active lease in the same translation unit.

3. Read the function notes when they exist.
4. Read the function inventory packet and configured module note.
5. Search `LESSONS.md` only for terms that match the current blocker.
6. Inspect focused original assembly and relevant exact donors.
7. Record a fresh baseline:

   ```text
   python tools/target_session.py check --va <VA> --owner <OWNER> \
     --kind baseline --note "fresh natural translation-unit baseline"
   ```

   The baseline check pins the clean natural source automatically.

## Work

Recover the simplest source that explains executable behavior.

Establish ownership, types, fields, widths, calls, and control flow before
register or instruction scheduling work.

Test distinct hypotheses. A useful hypothesis changes one supported source,
ABI, layout, control-flow, lifetime, or compiler-context idea.

Record meaningful checks through `target_session.py check`. Do not count syntax
repairs, unchanged reruns, or renamed locals as new evidence.

If the target-session lock times out, do not loop, force, or delete the lock.
Keep the source safe, record the blocker, and report it to the main agent.

Use `tools/check_function.py --no-build` for extra read-only diagnostics after a
current check.

Use these evidence tools only when they answer a current question:

- `target_dossier.py` for focused binary facts;
- `find_function_donors.py` for ranked exact donors;
- `query_abi.py` for ABI provenance;
- `search_asm_donors.py` for a distinctive assembly block; and
- `variant_lab.py` for controlled late-stage source variants.

Generated metadata and decompiler text are reference evidence. They are not the
behavior oracle.

Keep only a better natural reconstruction. Do not retain aliases, fake helpers,
dummy declarations, volatility, raw offsets, or source tricks for metrics alone.
Use named fields and record sizes instead of numeric offsets or element strides.

## Function notes

Optional function notes use this path:

```text
decomp_notes/functions/<VA-prefix>/<slug>.md
```

Keep raw objects, diffs, and experiment files under `build/`.

Create or update notes only when you have durable evidence:

- baseline and final metrics;
- useful tested hypotheses;
- repeated code-generation results;
- rejected artificial forms;
- proved facts and open questions; and
- the next useful approaches.

Separate facts from hypotheses. Do not copy every compiler run into the notes.
Do not put attempt history in production source comments.

## Exact result

An exact result starts a short source review.

1. Save the exact checkpoint.
2. Remove incidental source changes one at a time.
3. Recheck each useful reduction.
4. Keep the smallest natural source that remains exact.
5. Run the final target check.
6. Require `MATCH`, `0.0000%`, correct owner, boundary, relocations, and direct targets.
7. Audit the assigned translation unit with a worker-specific output directory:

   ```text
   python tools/audit_translation_unit_functions.py --group <GROUP> --jobs 1 \
     --output-dir build/audits/workers/<OWNER>/<GROUP>
   ```

8. Confirm that every matching neighbor still matches.
9. Update the function notes when you learned something durable.
10. Release the session. Do not change status or commit.

## Improved scratch result

A nonexact source change can remain when it is natural, behavior-supported, and
clearly better than the baseline.

Do not stop after one mismatch or one codegen basin. Test materially different
natural forms for the main evidence-backed hypotheses. Stop after exactness, a
proved blocker, or reasonable natural-source exhaustion.

Run a final recorded check. Record the exact improvement and remaining blocker.
Pin the final clean source. Pause the session.

If no source improvement survives, restore the pinned clean source. Keep only
useful function notes.

## Accepted-drift proposal

Suggest accepted drift only for a small and localized code-generation difference.

The proposal must prove:

- the same behavior for all relevant inputs;
- the same calls, targets, arguments, and order;
- the same memory effects and cleanup;
- the same ABI, exceptions, faults, and fault order;
- no unexplained control-flow difference; and
- a narrow explained instruction, register, or encoding difference.

Broad drift, changed predicates, missing calls, wrong targets, or changed effects
remain `scratch`.

Record the complete proof in the function notes. Report it as a proposal. The
main agent makes the decision.

## Report

Report:

- target VA and translation unit;
- exact, improved, drift proposal, or unresolved outcome;
- baseline and final metrics;
- important evidence learned;
- changed files;
- validation commands and reports; and
- open questions and next approaches.

Do not commit. Stop editing the leased translation unit after the report.
