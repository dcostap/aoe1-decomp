# Main-agent workflow

## Authority

The main agent owns:

- translation-unit leases and worker assignments;
- shared headers, globals, config, tools, and tests;
- review of every worker result;
- status changes and accepted-drift decisions;
- staging and commits; and
- final grouped and repository validation.

Every worker result is a proposal. Inspect the source and evidence before
integration.

## Shared-worktree model

Prevent concurrent writes to one natural translation unit in the same worktree.
Separate worktrees can use their own coordination plan.

The user or current orchestration defines each worker's task size and lifetime.
Do not impose a fixed function count or worker lifetime.

Workers use the coordinator worktree unless the assignment says otherwise.
They do not commit.

For each active worker, record:

- worker ID;
- function VA;
- translation-unit name and source path;
- allowed changed paths; and
- unique build output directory.

Do not assign another function from an actively leased translation unit.
`target_session.py start` enforces this rule.

Preclaim large waves without metric work:

```text
python tools/target_session.py start --preclaim --va <VA> --owner <OWNER> \
  --lease-hours <HOURS>
```

Tell each worker that its lease is active. The worker must use `brief`, not
`start`, for that preclaimed lease.

Do not edit or stage a worker's leased source while that worker is active.

## Worker assignment

Give the worker a compact task. Include:

- target VA and name;
- natural translation unit;
- lease owner ID;
- allowed source and function-note paths;
- known blocker or useful prior evidence;
- unique validation output directory; and
- the required final report.

Require the worker to read `docs/agentic_matching_workflow.md`.

Send the history required by the current orchestration.
Function notes remain the durable handoff.

Workers can choose their investigative methods. Do not set a hypothesis quota
or fixed stop count.

Do not accept an early stop after one mismatch or one codegen basin. Require
materially different natural forms for the main evidence-backed hypotheses.

Workers may seek:

- exact matches;
- better natural scratch source;
- proved source or ABI facts; and
- accepted-drift proposals.

Workers do not select `verified_logic`.

## Allowed worker changes

A normal matching worker may change only:

- its assigned function body in the natural source module; and
- its assigned function notes.

Authorize any other path explicitly.

Workers must not change headers, global storage, config, tools, tests, shared
notes, the Git index, or commits.

## Validation during work

The worker uses target checks for each meaningful hypothesis.

The current orchestration defines each worker's validation scope and job count.
Use a unique output directory under:

```text
build/audits/workers/<OWNER>/<GROUP>
```

Run repository-wide audits or full test suites only when the current
orchestration assigns that work.

Coordinated translation-unit access prevents source and compiler-object
collisions. Unique report directories prevent report collisions.

## Review a return

Review completed work read-only while other workers remain active. Do not move
`HEAD` or change shared files until the wave ends.

When a worker reports completion:

1. Tell the worker to stop editing the leased translation unit.
2. Inspect the complete diff for its allowed paths.
3. Confirm that no other path changed.
4. Read the final source and function notes.
5. Check source plausibility and behavior.
6. Rerun the authoritative target check.
7. Rerun focused grouped validation when source changed.
8. Accept, revise, or reject the source change.
9. Review any accepted-drift proposal.

After all workers in the wave stop:

10. Update a function status only after proof.
11. Make reviewed shared-header or tool repairs.
12. Stage only the reviewed paths.
13. Commit each logical result and clear any stale lease.

Other workers can continue in unrelated translation units during read-only
review. Defer shared edits and commits until they stop.

## Exact review

Require:

- `MATCH` and `0.0000%`;
- the correct owning symbol;
- no boundary escape;
- compatible relocations;
- correct direct call and tail targets;
- no matching-neighbor regression; and
- the smallest supported natural source.

Do not accept a match that depends on a wrapper, dummy declaration, fake ABI,
raw address, or compiler steering.

## Progress review

A nonexact change can be useful.

Accept it when:

- executable evidence supports the behavior;
- the source is simpler or more authentic;
- important structure or metrics improve;
- no correct call, effect, fault, or boundary is lost; and
- the function notes explain the improvement and remaining blocker.

If only the investigation improved, commit the function notes and reject the source
change.

## Accepted drift

Only the main agent can approve accepted drift.

Require a small, localized, proved equivalent difference. Review original and
rebuilt instructions, calls, effects, cleanup, ABI, exceptions, and fault order.

Reject broad drift, wrong targets, changed predicates, missing calls, changed
memory effects, or unexplained control flow.

Record the decision in the function notes and function registry.

## Verified logic

Verified logic is outside the normal matching-worker loop.

A stuck worker leaves the function in `scratch`. Do not ask matching workers to
propose semantic promotion.

Start semantic review only after a separate main-agent decision and a complete
review plan.

## Quiet integration checks

During active work, validate only changed targets and assigned groups.

At a quiet checkpoint, run the global owner audit, grouped translation-unit
audit, flag audit, and tests once.

Do not run duplicate global checks while workers compile functions.

## Worker trial review

For a shared-worktree trial, assess:

- path compliance;
- source and build-output conflicts;
- canonical owner selection;
- baseline and final check reliability;
- function-note quality;
- accepted-drift understanding;
- grouped-neighbor protection; and
- ease of independent review and staging.

Report workflow problems before scaling the fleet.
