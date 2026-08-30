# Orchestrator

## Role

The orchestrator manages matching workers in one worktree.
Follow `agent_roles/root_orchestrator.md` only when acting as the root orchestrator.

When a root orchestrator assigns this role:

- work only in the assigned worktree;
- use only the assigned translation-unit set;
- follow the assigned worker capacity and tool job settings;
- use the enabled TODO feature for worker-result review;
- report major blockers to the root orchestrator; and
- stop editing before the completed handoff.

The root assignment overrides this document only where it is explicit.

## Authority

The orchestrator owns:

- worker and translation-unit assignment;
- the continuous worker scheduler;
- the TODO review backlog;
- shared headers, globals, config, tools, and tests;
- worker-result review;
- status and accepted-drift decisions;
- staging and commits; and
- final repository validation.

Every worker result is a proposal. Verify it before integration.

## Continuous scheduler

The user or root assignment selects the active worker capacity. Keep that
capacity full while eligible translation units remain.

Active worker capacity and repository-tool job counts are separate settings.
Never copy the active worker capacity into each worker's `--jobs` value. Unless
the user selects nested tool parallelism, assign one tool job per worker. This
keeps the active worker capacity as the compiler concurrency bound.

Use the exact provider/model ID from `agent_roles/root_orchestrator.md` or the current user
instruction. The managed launcher does not accept a short model name.

One orchestrator controls assignments in one shared worktree. Independent
orchestrators use separate worktrees.

Assign one worker to one natural translation unit. Never assign two active
workers to the same translation unit.

An assignment contains:

- the translation-unit name and source path;
- all current scratch-function VAs in that translation unit;
- one unique worker ID;
- allowed source and function-note paths;
- the active worker capacity and separate per-tool job setting;
- one unique private experiment and audit directory; and
- the required final-response format.

Assign the stable worker ID before launch. Use a unique readable value such as
`luna-01-Timeline`. Formal batches allocate managed subagent IDs only after the
assignment exists. Use the assigned stable ID for target notebooks and worker
reports. Use the managed subagent ID for harness control and TODO intake.

The private directory does not replace repository-managed caches, target
notebooks, or standard diff paths. Repository tools protect those shared
artifacts with content identities and operating-system locks. Direct each
worker's ad hoc experiments and translation-unit audit into its private
directory.

Require the worker to read `agent_roles/matching_worker.md`.

The managed subagent list is the active-assignment record. Open TODO review
items identify completed translation units that are not yet eligible again.
Select new work from translation units absent from both sets.

Workers do not send progress reports. Managed completion delivers their final
response to the orchestrator.

## Completion intake

A completion event must not replace the orchestrator's current review task.
Perform only this intake work:

1. Confirm that the worker stopped editing.
2. Add one TODO verification item.
3. Include the worker ID, translation unit, outcome, and changed paths.
4. Start a replacement worker on another eligible translation unit.
5. Return to the first unchecked TODO item.

Batch TODO additions when several workers finish together. Do not review their
changes during intake.

An open TODO review item makes its translation unit ineligible for another
matching assignment.

## TODO review backlog

The enabled TODO list is the authoritative integration backlog. The first
unchecked item is current when it is ready. An item waiting only for a
background result is not ready.

Work only on that item. Mark it complete only after its result is integrated,
rejected, or converted into a specific follow-up task.

For a normal worker return:

1. Read the worker's final response.
2. Inspect the complete diff for its allowed paths.
3. Confirm that no unauthorized path changed.
4. Read all changed function bodies and notes.
5. Confirm that each changed file keeps its existing line-ending style.
6. Check source plausibility and executable behavior.
7. Select the smallest verification level that proves the result.
8. Reuse fresh worker artifacts when their input fingerprints match.
9. Accept, revise, or reject each change.
10. Review each accepted-drift proposal.
11. Update statuses only after proof.
12. Stage only reviewed paths.
13. Commit each logical result.
14. Mark the TODO item complete.

The scheduler can assign that translation unit again after TODO completion.

## Risk-based verification

For a note-only result, review only the added note text. Do not rebuild
unchanged source.

For an ordinary scratch improvement, run one target check. Reuse the worker's
translation-unit audit when its input fingerprint still matches.

For an exact proposal, review source plausibility and run one authoritative
target check. Rerun the translation-unit audit only when the worker artifact is
missing or stale.

For an accepted-drift proposal, perform the complete independent semantic
review. Prove memory effects, fault order, calls, cleanup, and control flow.

Each translation-unit audit report records `groups[].input_fingerprint`. A
matching fingerprint proves that source, headers, symbols, flags, toolchain,
and configured build inputs did not change.

Read the changed function-note section first. Read old experiment history only
when the new claim depends on it or conflicts with it.

Batch reviewed note-only results when one commit remains clear. Keep source
changes and status promotions in separate logical commits.

## Background validation

Start long, noninteractive integration audits in the background. Keep the
related TODO item open until the audit finishes.

Do not wait while independent ready TODO items remain. Set the next ready item
as current and continue review work.

Do not use a blocking wait only to watch progress. Use it when the result blocks
all safe work, or when no independent ready item remains.

Do not poll the process. Let its completion notice return the result. Never
start a duplicate audit because the first audit is quiet.

Freeze the shared change and its dependencies while its audit runs. Other
reviews can continue when they do not change those shared paths.

A later source change can invalidate one completed audit group. Audit that
translation unit again after the review. Do not repeat the full audit when a
focused rerun is sufficient.

When the background audit finishes, inspect its report. Resume its TODO item at
the next safe boundary. Fix failures before integration.

## Worker continuation

Resume a completed worker when its existing context makes the current TODO item
faster or safer.

Good continuation tasks include:

- one missing validation;
- one focused source correction;
- clarification of reported evidence;
- cleanup within the same translation unit; or
- more work on its remaining scratch functions.

Keep the TODO item open while the continuation runs. The worker resumes its
target notebooks with the same owner ID.

Start a new worker when the task needs different ownership, scope, model, or
shared-file authority.

## Shared findings

A matching worker reports a shared finding but never edits the shared path.
The final response identifies:

- the path and symbol;
- facts and hypotheses;
- executable, PDB, or exact-donor evidence;
- affected functions and translation units;
- the smallest proposed correction;
- required validation; and
- whether the finding blocked work.

Create or update a TODO item keyed by the shared path and symbol. Merge duplicate
findings into that item.

In a root-managed worktree, send accepted shared findings to the root
orchestrator. Do not edit shared paths unless the assignment grants authority.

Use one authorized repair owner for an accepted shared change. Close compiler
admission before editing shared source:

```text
python tools/compiler_gate.py close
```

The command blocks new compiler jobs and waits for admitted jobs to finish.
Workers remain active and can continue noncompiler investigation.

Apply and commit only the reviewed shared paths. Then reopen admission:

```text
python tools/compiler_gate.py open
```

Always reopen the gate after the source is coherent. Use `status` to inspect the
gate after an interrupted integration.

Notify affected active workers after the change. Require fresh checks for every
affected target. Header fingerprints force affected modules to rebuild.

Audit shared-header changes through their transitive dependency set:

```text
python tools/audit_translation_unit_functions.py \
  --affected-by include/example.h --jobs JOBS
```

Repeat `--affected-by` for more paths. The tool audits the union of dependent
translation units and records the selected groups in its report.

Do not run a full repository audit after each shared-header repair. Use one
after shared changes stabilize, after toolchain or compiler-flag changes, or
when dependency tracking cannot prove the affected set.

Return deferred targets to the eligible pool after the blocker is resolved.

## Allowed matching worker changes

A matching worker can change only:

- scratch function bodies in its assigned natural source file; and
- function notes for those scratch functions.

The worker cannot change headers, globals, config, tools, tests, shared notes,
status metadata, the Git index, or commits.

Authorize a different scope only through a separate assignment.

## Review standards

An exact result requires:

- `MATCH` and `0.0000%`;
- the correct owning symbol;
- correct boundaries and relocations;
- correct direct call and tail targets;
- no matching-neighbor regression; and
- the smallest supported natural source.

A nonexact improvement can remain when executable evidence supports it. It must
be more natural or structurally better than the prior source.

Reject wrappers, fake ABI, raw addresses, dummy declarations, fake volatility,
and other compiler-steering forms.

Only the orchestrator can approve accepted drift or start semantic review.
Workers leave unresolved functions in `scratch`.

## Repository checks

Run target and translation-unit checks during review. Run global audits and the
full test suite after the current shared changes stabilize.

Do not duplicate global checks while workers compile functions.

## Root handoff

Complete every ready worker-review TODO item before the root handoff.
Stop all matching workers and background processes.
Commit each accepted logical result.
Leave no tracked or untracked change.

The final handoff contains:

- orchestrator ID;
- worktree, branch, base commit, and head commit;
- assigned, completed, blocked, and untouched translation units;
- commits and changed paths;
- exact promotions and accepted-drift approvals;
- rejected worker proposals;
- validation commands, reports, and fingerprints;
- shared findings and major blockers;
- remaining work; and
- merge guidance.

Use `NEEDS_ROOT` when a major issue requires root guidance.
State the question, evidence, changed paths, and safe continuation point.
Stop editing after either handoff.
