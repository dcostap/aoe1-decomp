# Matching worker workflow

Use this workflow for one assigned natural translation unit.

## Assignment

The assignment gives you:

- one natural translation unit and source path;
- all current scratch-function VAs in that translation unit;
- one orchestrator-assigned stable worker ID;
- allowed source and function-note paths;
- active-worker capacity and a separate per-tool job setting; and
- one unique private experiment and audit directory.

You are the only active matching worker for that translation unit.

You can edit:

- scratch function bodies in the assigned natural source file; and
- their function notes.

Do not edit matching, accepted-drift, verified-logic, or unresolved function
bodies. Matching functions are regression anchors.

Do not edit headers, globals, config, tools, tests, shared notes, status metadata,
`LESSONS.md`, the Git index, or commits.

Do not use Git restore, reset, clean, checkout, stage, or commit. Preserve all
unrelated worktree changes.

## Objective

Improve the scratch functions in the assigned translation unit.

Any supported improvement is useful. Examples include:

- one or more exact matches;
- more natural binary-supported source;
- better objective comparison results;
- a proved ABI, layout, ownership, or source fact;
- a disproved hypothesis that prevents repeated work; or
- a complete accepted-drift proposal.

Do not select `accepted_drift` or `verified_logic`. The orchestrator makes those
decisions.

There is no fixed function or hypothesis quota. Do not give up after one failed
idea or one code-generation basin.

Continue useful work while reasonable evidence-backed approaches remain. Stop
when the assignment has received enough useful work or a major issue blocks safe
progress.

## Start

Run each repository tool with `--help` before its first use.

Before work on each function:

1. Query its current status, paths, notes, and history.
2. Start or resume its target session with the assigned owner ID.
3. Read its function note and inventory packet.
4. Read the configured module note when present.
5. Inspect focused executable evidence and relevant exact donors.
6. Record a fresh baseline check.

Example:

```text
python tools/target_session.py start --va <VA> --owner <WORKER_ID>
python tools/target_session.py check --va <VA> --owner <WORKER_ID> \
  --kind baseline --note "fresh natural translation-unit baseline"
```

The baseline check pins the clean reconstruction.

## Work

Recover the simplest period-plausible source that explains executable behavior.

Establish ownership, types, fields, widths, calls, and control flow before
instruction-scheduling work.

Use `target_session.py check` for meaningful hypotheses. A useful hypothesis
changes one supported source, ABI, layout, control-flow, lifetime, or compiler
context idea.

Do not count syntax repairs, unchanged reruns, or renamed locals as evidence.

Use focused tools only when they answer a current question:

- `target_dossier.py` for focused executable facts;
- `find_function_donors.py` for ranked exact donors;
- `query_abi.py` for ABI evidence;
- `search_asm_donors.py` for a distinctive assembly block;
- `variant_lab.py` for controlled source variants; and
- `check_function.py --no-build` for extra read-only diagnostics.

Use resource values from the assignment. Do not copy active-worker capacity
into `--jobs`. Do not invent local limits.

Keep only better natural source. Remove aliases, fake helpers, dummy declarations,
fake volatility, raw offsets, and metric-only source tricks.

Put ad hoc experiments and translation-unit audit output in your private
directory. Leave repository-managed caches, target notebooks, and standard
diff paths at their tool-defined locations.

A change to one scratch function must not regress another function in the
translation unit.

## Function notes

Function notes use:

```text
decomp_notes/functions/<VA-prefix>/<VA>.md
```

Record durable evidence only:

- baseline and final metrics;
- useful tested hypotheses;
- repeated code-generation results;
- rejected artificial forms;
- proved facts and open questions; and
- useful next approaches.

Separate facts from hypotheses. Keep raw objects, diffs, and experiments under
`build/`.

## Exact and improved results

For an exact result:

1. Save the exact checkpoint.
2. Remove incidental changes one at a time.
3. Recheck each useful reduction.
4. Keep the smallest natural exact source.
5. Run a final target check.
6. Confirm ownership, boundaries, relocations, and direct targets.

A nonexact change can remain when it is natural, behavior-supported, and clearly
better than its baseline.

Run a final recorded check for every retained change. Restore the pinned clean
source when an experiment does not improve it.

## Accepted-drift proposals

You can suggest accepted drift for a small localized code-generation difference.
The proposal must prove:

- equal behavior for all relevant inputs;
- equal calls, targets, arguments, and order;
- equal memory effects and cleanup;
- equal ABI, exceptions, faults, and fault order;
- no unexplained control-flow difference; and
- a narrow explained instruction, register, or encoding difference.

Record the proof in the function note. The orchestrator accepts or rejects the
proposal.

## Major issues

Stop when a major issue prevents safe progress. Examples include:

- a proved shared-header or global declaration defect;
- wrong canonical ownership that requires shared changes;
- a tool correctness failure;
- source corruption or an unauthorized conflicting edit; or
- executable evidence that invalidates the assigned source model.

Do not repair shared paths. Preserve safe source and record the evidence.

## Final validation

Before the final response:

1. Run a final check for every retained function change.
2. Audit the assigned translation unit with the assigned job count.
3. Confirm that matching neighbors still match.
4. Update function notes with durable evidence.
5. Review your changed paths.

If a major issue prevents a validation command, state that fact in the final
response. Stop editing before the final response.

## Final response

Send no intermediate progress reports. Do not use a report tool.

Your final response must contain:

- translation unit and worker ID;
- scratch functions inspected;
- functions changed;
- baseline and final results for each retained change;
- exact and accepted-drift proposals;
- changed files;
- validation commands and reports;
- major blockers and shared findings;
- untouched scratch functions; and
- useful next steps.

For a shared finding, include the path, symbol, facts, hypotheses, evidence,
affected translation units, smallest proposed repair, and required validation.

After the final response, remain stopped unless the orchestrator continues your
session.
