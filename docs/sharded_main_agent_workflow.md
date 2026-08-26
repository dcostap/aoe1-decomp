# Sharded main-agent workflow

This workflow divides Phase 4 across isolated main agents.

Read `main_agent_workflow.md` and `agentic_matching_workflow.md` first.

## Roles

The coordinator owns global policy, shard assignment, shared changes, branch integration, and final validation.

Each shard lead owns one fixed TU set. The lead reviews worker output and commits accepted work.

Each TU captain owns one canonical TU at a time. Captains do not commit or edit global files.

## Isolation

Each shard uses one Git worktree and branch.

Use the assigned absolute worktree path for every file and command.

Never edit the coordinator worktree. Never edit another shard worktree.

The lead can edit these files in its worktree:

- Files listed in its assignment manifest
- Owned TU wrappers and local context files
- Owned entries in `config/translation_units.json`
- Shard-local audit files under `build/audits/tu_shards/<shard>/`

Report a required broad shared-file change to the coordinator. Continue independent work while the coordinator reviews it.

## Lead duties

The lead performs the same review work as the coordinator, but only for assigned TUs.

The lead must:

1. Start with the current source and a fresh grouped TU audit.
2. Read prior journals before it reassigns an investigated TU.
3. Keep at most ten workers active.
4. Assign one persistent captain per active TU.
5. Prevent file overlap between active captains.
6. Review every returned diff and exact-finish retrospective.
7. Reject local layout steering, fake dispatch, and grouped-only body forks.
8. Promote only fresh grouped exact results with valid ownership and boundaries.
9. Validate every affected registered owner before each commit.
10. Commit small reviewed clusters on the shard branch.
11. Keep accepted drift closed without new binary evidence.
12. Preserve unresolved evidence in the TU journal.

Do not wait for all workers before reviewing completed work. Apply local integration backpressure when returns accumulate.

## Worker duties

Use `openai-codex-secondary/gpt-5.6-luna` with `xhigh` thinking for every captain.

Give each captain the absolute shard worktree path and its complete TU packet.

Captains follow `agentic_matching_workflow.md`. They can report progress while they continue safe independent work.

Captains report only a blocker, major issue, reusable shared finding, or completed assignment.

## Escalation

Report these events to the coordinator immediately:

- A required file belongs to another shard.
- A shared ABI change can affect another shard.
- A registered owner regresses outside the active TU.
- Tool output conflicts with executable or PDB evidence.
- Repository policy blocks a binary-supported repair.
- Workload becomes materially unbalanced.

State facts, evidence, affected TUs, and the smallest requested coordinator action.

## Completion

Before shard completion:

1. Validate all assigned TUs that changed.
2. Confirm every pre-existing registered owner still matches.
3. Run focused policy and translation-unit tests.
4. Confirm a clean shard worktree.
5. Write `build/audits/tu_shards/<shard>/completion.json`.
6. Report branch name, commits, exact gains, holds, blockers, and validation paths.

The coordinator merges completed shard branches. The coordinator resolves cross-shard and central-file conflicts.
