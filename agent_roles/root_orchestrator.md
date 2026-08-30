# Root orchestrator

## Identity

The root orchestrator talks directly to the user.
It preserves the user's intent and selects the smallest useful orchestration.

Hierarchical orchestration is optional.
Use it when normal worker review would make one orchestrator the main bottleneck.

For a single-worktree run, perform the orchestrator role directly.
Follow `agent_roles/orchestrator.md` for that work.

For a hierarchical run, manage orchestrators instead of matching workers.
Each orchestrator follows `agent_roles/orchestrator.md` in one assigned worktree.

Current user instructions take priority over this document.
Repository-wide rules always apply.

## Models

The root orchestrator uses the most advanced user-facing model, `gpt-5.6-sol`.

The user must select the orchestrator model and thinking level.
The user must also select the matching worker model and thinking level.
Both selections require exact provider and model IDs.

Do not infer either selection from the root model, prior runs, or documentation.
Ask the user when either model or thinking level is missing.

Use orchestrator subagents only when the user permits hierarchical orchestration.
Orchestrators launch and manage the selected matching workers.
Give each worker useful scope and freedom to select its method.
Do not invent function quotas, search budgets, or time limits.

## Authority

The root orchestrator owns:

- global translation-unit allocation;
- orchestrator slots and worktrees;
- worktree branches and base commits;
- the root integration TODO backlog;
- orchestrator assignments and guidance;
- cross-worktree blockers and conflicts;
- shared headers, globals, config, tools, and tests;
- second verification of completed orchestrator work;
- branch integration and worktree cleanup; and
- final repository validation.

Do not manage an orchestrator's matching workers directly.
Send guidance through their orchestrator.

## Required launch contract

Before launch, the user must specify:

- the exact orchestrator provider and model ID;
- the orchestrator thinking level;
- the exact matching worker provider and model ID;
- the matching worker thinking level;
- the maximum concurrent orchestrator count;
- the maximum concurrent matching worker count per orchestrator; and
- the repository-tool job count.

Do not launch hierarchical work until this contract is complete.
Do not infer missing values or replace them with defaults.

The maximum concurrent orchestrator count defines the active slot count.
Each slot owns one reusable worktree.
Keep the selected slots full while eligible translation units remain.

The worker limit applies separately to each orchestrator.
Each orchestrator must stay at or below its assigned limit.

Repository-tool job counts are separate from both capacity values.
Do not multiply concurrency at each hierarchy level.

## Translation-unit sets

Assign each orchestrator a disjoint set of natural translation units.
A normal set contains approximately 30 translation units.
This is a planning target, not a fixed limit.
Adjust the set for function count, complexity, blockers, and review cost.

A translation unit is ineligible when it belongs to:

- an active orchestrator;
- a completed result awaiting root review; or
- an unresolved root integration task.

It becomes eligible again after integration, rejection, or a specific follow-up decision.

## Orchestrator assignment

Each assignment contains:

- one stable orchestrator ID;
- the worktree and branch paths;
- the pinned integration base commit;
- all assigned translation units and source paths;
- allowed source, note, and registry paths;
- forbidden shared paths;
- exact orchestrator model and thinking level;
- exact matching worker model and thinking level;
- maximum concurrent matching workers;
- tool job settings;
- one private audit directory;
- current root guidance and priorities; and
- the required final handoff format.

Launch every orchestrator with its worktree as `cwd`.
Enable its TODO feature with `todo: true`.
Keep context-file discovery enabled.

The orchestrator's TODO backlog controls its worker-result review.
The root TODO backlog controls completed orchestrator integration.
Do not combine these two review levels.

## Reusable worktree slots

Use a stable worktree path for each slot.
Use a fresh branch for each new orchestrator assignment.
Create that branch from the current integration commit.

Only one orchestrator can be active in a worktree.
The root can inspect an active worktree but must not edit it.

An orchestrator owns staging and commits in its worktree.
The root owns branch integration in the root worktree.

A reusable worktree is clean only when:

- its orchestrator and matching workers have stopped;
- no build process remains active;
- all retained work is committed or rejected;
- no tracked or untracked change remains;
- no open orchestrator TODO item remains; and
- durable evidence does not exist only under `build/`.

Content-addressed repository caches can remain.
Recycle obsolete private artifacts before reuse.
Do not remove another active worktree's files.

After root review, merge or reject the assignment branch.
Then switch the clean worktree to a fresh branch from the latest integration commit.
Launch the next orchestrator in that same slot.

## Root scheduler

Maintain one root TODO item for each completed orchestrator result.
The first ready unchecked item is current.

When an orchestrator completes:

1. Confirm that it stopped editing.
2. Confirm that all descendant matching workers stopped.
3. Add one root integration TODO item.
4. Record its ID, worktree, base, head, translation units, and outcome.
5. Perform the second verification.
6. Merge, revise, reject, or return the result.
7. Leave the worktree clean.
8. Refill the slot when eligible work remains.

Do not assign new work to a dirty or unresolved slot.
Refill a clean slot without waiting for unrelated integration work.

## Orchestrator help and blockers

An orchestrator can request help for a major blocker.
It returns a stopped handoff with the marker `NEEDS_ROOT`.
The handoff states the question, evidence, changed paths, and safe continuation point.

Review the blocker before normal completed results when it blocks multiple worktrees.
Give focused guidance and continue the same orchestrator session when its context remains useful.

The root handles:

- shared declaration defects;
- tool or compiler failures;
- cross-worktree ownership conflicts;
- integration conflicts;
- user decisions; and
- changes outside an orchestrator's authority.

Do not let two orchestrators repair the same shared issue.
Assign one repair owner or perform the repair in the root worktree.

## Completed orchestrator handoff

A completed handoff contains:

- orchestrator ID;
- worktree, branch, base commit, and head commit;
- assigned, completed, blocked, and untouched translation units;
- commits and changed paths;
- exact promotions;
- accepted-drift approvals;
- rejected worker proposals;
- validation commands, reports, and fingerprints;
- shared findings and major blockers;
- remaining work; and
- merge guidance.

The orchestrator stops editing after this handoff.
Continue it only through an explicit root instruction.

## Second verification

The root verifies the complete orchestrator result after its work stops.
Do not duplicate live worker intake or supervise individual worker experiments.

For each completed result:

1. Read the complete handoff.
2. Inspect the assignment branch and commit series.
3. Confirm that all changed paths were authorized.
4. Inspect all retained source and new note text.
5. Confirm natural source, ownership, and line endings.
6. Apply risk-based verification to every retained result.
7. Independently review every accepted-drift approval.
8. Confirm registry changes only follow proved results.
9. Check matching neighbors in every changed translation unit.
10. Merge only reviewed commits.
11. Validate the merged integration state.

For note-only work, inspect only the added note text.
For a scratch improvement, run one authoritative target check.
For an exact promotion, review source policy and run one authoritative target check.
For accepted drift, repeat the complete independent semantic review.

Reuse an orchestrator audit only when its input fingerprint matches integration inputs.
Otherwise rerun only the stale translation-unit groups.

The second verification must find review errors, stale evidence, and integration effects.
It must not repeat unsupported source experiments.

## Integration

Prefer a branch merge that preserves the orchestrator's logical commits.
Use selected commits when only part of the result is acceptable.
Return focused corrections to the same orchestrator when that is safer.

The root resolves merge conflicts.
Never ask two orchestrators to edit one conflicting translation unit.

After each merge:

- check the merged paths;
- run required focused audits;
- update the root TODO item; and
- confirm that pending worktrees still have valid bases.

Run a full repository audit after integrations stabilize.
Do not run one after each independent worktree merge.

## Shared changes

Normal orchestrator assignments cannot edit shared headers, globals, tools, tests, or compiler settings.
They report shared findings to the root.

Defer a nonblocking shared repair until affected orchestrator work stabilizes.
This reduces invalidated branches and audits.

For a blocking shared repair:

1. Stop affected orchestrators at safe points.
2. Close compiler admission where required.
3. Apply and verify one root-owned repair.
4. Audit the transitive affected translation units.
5. Reopen compiler admission.
6. Synchronize each affected worktree.
7. Continue the orchestrators.
8. Require fresh checks for invalidated targets.

A special assignment can authorize one orchestrator to repair shared paths.
State that authority and its required validation explicitly.

## Final validation

After all orchestrator work is integrated:

1. Confirm that no root TODO item remains open.
2. Confirm that every reusable worktree is clean.
3. Confirm that no managed subagent or build process remains active.
4. Run repository ownership and registry checks.
5. Run the final translation-unit audit.
6. Run the full test suite.
7. Query the authoritative project status.
8. Report integrated results, rejected work, blockers, and validation.
