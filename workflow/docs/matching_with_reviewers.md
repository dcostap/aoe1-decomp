# Matching with reviewers

## Selection and scope

This is an opt-in variation. The existing matching workflow remains the default.
Select it with the assignment marker `Workflow: matching with reviewers`.
A user request to use "matching with reviewers" selects this variation too.
Carry the marker into every orchestrator, matching worker, and reviewer assignment.
Do not switch an active assignment without an explicit instruction.

Read the normal role document, this document, and `workflow/docs/experiments.md`.
Reviewers also read `workflow/agent_roles/matching_reviewer.md`.
This variation changes review responsibility and handoff scheduling, not correctness standards or experimental authority.
Its routing rules replace the normal orchestrator's personal technical review and the root's repeated semantic review.
All other role rules still apply. Current user instructions take priority.

Matching and accepted drift are equally valid completed recoveries.
Do not schedule more byte tuning after an approved recovery without new evidence.

## Division of work

| Role | Responsibility |
| --- | --- |
| Orchestrator | Select available modules, route handoffs, resolve conflicts, and integrate approved work. |
| Matching worker | Inspect saved history, select technical questions, investigate, and preserve proposals and evidence. |
| Matching reviewer | Independently inspect actual inputs, source, semantics, validation, and affected owners. |

The orchestrator assigns a natural translation unit and its scratch owners using the registry, ownership, and recorded blockers.
It does not read every function's assembly to prepare the assignment.
The worker selects useful recovery questions from local evidence. The reviewer checks their conclusions and approach.
Do not require a separate planning approval before ordinary worker investigation.

The reviewer replaces routine technical review by the orchestrator; it does not add another identical review layer.
The orchestrator retains final integration authority and makes registry updates only after approval.
It delegates independent accepted-drift proof to the reviewer in this variation.

## Launch contract

Before launch, obtain the user's exact provider/model IDs and thinking levels for matching workers and reviewers.
Do not infer the reviewer selection from the worker, root, or previous runs.
Also establish concurrent worktree slots, reviewer/worker capacity, and separate tool job counts.
The user can select a combined agent limit, or separate worker and reviewer limits.
Count active reviewers in the agreed capacity; do not add unbounded reviewers above a worker limit.
Reserve capacity for review rather than filling every available place with replacement matching work.
Ask for missing settings. Do not enable TODO support unless the user permits it.

Use the current managed subagent tools. This document does not install a new launcher or automatic scheduler.
Assign the repository reviewer through its task and document path.
`matching_reviewer` is a repository role, not a built-in harness role identifier.

Each slot has one isolated worktree and a branch based on a known integration commit.
Only one matching worker or reviewer may operate in that slot at a time.
Other slots can proceed independently within the agreed limits.
Hierarchical orchestration remains optional and needs its own user authorization and launch contract.

## Assignment

Give the matching worker the normal assignment fields, plus:

- the workflow marker;
- worktree, branch, and pinned base commit;
- the path to this variation;
- the requirement to prepare a review package and stop editing; and
- the selected resource settings and user stop conditions.

Give the reviewer a fresh, independent session for the first review.
Use the same worktree as the stopped matching worker.
Supply the original assignment, worker handoff, saved input identities, changed paths, and evidence locations.
Do not supply only the worker's preferred conclusion.
The reviewer can inspect local source, executable evidence, history, tests, and complete affected closures.

## Completion and correction loop

1. Receive the matching worker's completion notification.
2. Confirm that it stopped editing and its compiler jobs finished.
3. Keep the slot reserved and launch its reviewer when capacity permits.
4. Receive the reviewer's verdict and confirm that it stopped.
5. Route corrections to the same matching worker when its context remains useful.
6. After corrections, resume the reviewer with the new package and its previous findings.
7. Integrate approved work, or preserve a blocked result and close the task.

Use completion notifications rather than repeated status polling.
The orchestrator routes reports through `subagent_send`; agents do not message each other automatically.
Forward the durable review path and findings. Do not reconstruct the technical argument in each routing message.
Do not run the worker and reviewer concurrently in the same worktree.
Do not start unrelated work in a slot awaiting review or correction.

The reviewer returns one verdict for each proposal:

- `APPROVE`: the specified source or status proposal has adequate evidence.
- `NEEDS_CORRECTION`: a concrete source, evidence, test, or reporting defect needs repair.
- `BLOCKED`: a stated unknown or conflict prevents approval with the available evidence.

These are review verdicts, not registry statuses. Approval can cover evidence preservation without approving source or promotion.
A task can contain approved and blocked proposals. Identify their dependencies before integrating a subset.
Do not keep cycling an unchanged objection. Record the missing evidence and a useful restart condition.
Do not impose arbitrary probe quotas or time limits.

## Review package

Use Behavior, Source, Bytes, and Integration for every proposal, including evidence-only results.
Include the normal worker handoff and:

- all new state and event IDs, including failed, invalid, and equal-output experiments;
- the base commit, selected final inputs, changed paths, and compiler-input fingerprints;
- complete affected-owner results and proposed registry changes;
- durable tests, test inputs, outputs, source patches, and coverage limits; and
- unresolved objections and functions not investigated.

Preserve evidence before changing inputs or handing off. A path under `build/` alone is not preservation.
The reviewer checks package completeness and actual input diffs, not the orchestrator.
Missing fields return to the worker without a new source investigation by the orchestrator.

## Integration without duplicate technical review

The orchestrator checks the verdict, its scope, changed-path list, input identities, and preservation decision.
It verifies that the selected patch and current inputs are the reviewed ones.
It preserves records, referenced objects, candidates, and reachable bases in reviewed Git history.
It stages only approved paths, applies approved registry decisions, and runs required integration checks.
Reuse valid closure evidence when its compiler-input fingerprints match. Rerun stale affected groups.
Run global validation after shared changes settle, not after each independent result.

A merge conflict or changed input can invalidate review approval.
Send changed source or behavior questions back to the reviewer; do not treat a successful rebuild as semantic approval.
An unchanged input with valid review does not require the orchestrator to repeat instruction-by-instruction analysis.
In hierarchical runs, the root follows this same rule for the reviewer's approved inputs.
The root still owns cross-worktree decisions and final validation.

Escalate ownership conflicts, policy questions, oracle issues, or unresolved technical disagreements.
The orchestrator investigates the specific escalation or asks the user; it does not silently waive a review objection.
Do not approve a result from the verdict word alone when its evidence or scope is missing.

Before slot reuse, stop both agents and builds, preserve all required evidence, and follow the normal cleanup rules.
Report completed recoveries, source repairs, rejected proposals, blockers, and integration checks separately.
Do not use test counts, experiment counts, or worker activity as substitutes for completed recoveries.
