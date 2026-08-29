# Retired sharded workflow

The isolated shard and worktree workflow is no longer active.

Matching workers now share the coordinator worktree. One worker leases one
natural translation unit and works on one function at a time.

Use:

- `docs/agentic_matching_workflow.md` for worker behavior; and
- `docs/main_agent_workflow.md` for orchestration and review.

Git history preserves the former sharded workflow.
