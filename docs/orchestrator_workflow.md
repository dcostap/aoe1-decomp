# Orchestrator workflow

## Authority

The orchestrator owns:

- worker assignment and translation-unit reservations;
- the continuous worker scheduler;
- the TODO review backlog;
- shared headers, globals, config, tools, and tests;
- worker-result review;
- status and accepted-drift decisions;
- staging and commits; and
- final repository validation.

Every worker result is a proposal. Verify it before integration.

## Continuous scheduler

The user selects the active worker capacity. Keep that capacity full while
eligible translation units remain.

Assign one worker to one natural translation unit. Never assign two active
workers to the same translation unit.

An assignment contains:

- the translation-unit name and source path;
- all current scratch-function VAs in that translation unit;
- one unique worker and lease owner ID;
- allowed source and function-note paths;
- one primary VA for the translation-unit reservation;
- the user-selected lease duration and resource settings;
- one unique build output directory; and
- the required final-response format.

Preclaim the primary VA before launch:

```text
python tools/target_session.py start --preclaim --va <PRIMARY_VA> \
  --owner <OWNER> --lease-hours <HOURS>
```

Require the worker to read `docs/agentic_matching_workflow.md`.

Workers do not send progress reports. Managed completion delivers their final
response to the orchestrator.

## Completion intake

A completion event must not replace the orchestrator's current review task.
Perform only this intake work:

1. Confirm that the worker stopped editing.
2. Confirm that its translation unit is held for review.
3. Add one TODO verification item.
4. Include the worker ID, translation unit, owner ID, outcome, and changed paths.
5. Start a replacement worker on another eligible translation unit.
6. Return to the first unchecked TODO item.

Batch TODO additions when several workers finish together. Do not review their
changes during intake.

A held translation unit is not eligible for another matching assignment. It
remains held until its TODO review completes.

If a worker exits before creating the hold, the orchestrator runs `hold-tu`
with its primary VA and owner ID during completion intake.

## TODO review backlog

The enabled TODO list is the authoritative integration backlog. The first
unchecked item is the orchestrator's current task.

Work only on that item. Mark it complete only after its result is integrated,
rejected, or converted into a specific follow-up task.

For a normal worker return:

1. Read the worker's final response.
2. Inspect the complete diff for its allowed paths.
3. Confirm that no unauthorized path changed.
4. Read all changed function bodies and notes.
5. Check source plausibility and executable behavior.
6. Rerun authoritative checks for retained changes.
7. Audit the translation unit and its matching neighbors.
8. Accept, revise, or reject each change.
9. Review each accepted-drift proposal.
10. Update statuses only after proof.
11. Stage only reviewed paths.
12. Commit each logical result.
13. Release the translation-unit reservation.
14. Mark the TODO item complete.

Release every session owned by the worker in that translation unit:

```text
python tools/target_session.py release-tu --va <PRIMARY_VA> --owner <OWNER> \
  --reason "orchestrator review complete"
```

The scheduler can assign that translation unit again after release.

## Worker continuation

Resume a completed worker when its existing context makes the current TODO item
faster or safer.

Good continuation tasks include:

- one missing validation;
- one focused source correction;
- clarification of reported evidence;
- cleanup within the same translation unit; or
- more work on its remaining scratch functions.

Keep the translation unit held while the continuation runs. The worker resumes
its target session with the same owner ID.

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

Return deferred targets to the eligible pool after the blocker is resolved.

## Allowed matching-worker changes

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
full test suite when the current orchestration requires them.

Do not duplicate global checks while workers compile functions.
