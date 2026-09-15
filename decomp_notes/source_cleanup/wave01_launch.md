# Cleanup wave 01 launch

Base commit: `ad338a7faf75ffdfff8fec846133b4aa8da3fa44`.
Batch: `batch-695a6292`.
Assignment: [module and header ownership](wave01_assignments.md).
Workflow: [hierarchical cleanup](../../docs/source_cleanup_owners.md).

| Owner | Managed agent | Integration slot | Worker slots | Modules |
| --- | --- | --- | --- | --- |
| 01 | sa-7ce9b027 | 01 | 04–11 | Eight action modules |
| 02 | sa-fb6be13a | 02 | 12–19 | Eight random-map modules |
| 03 | sa-a7396334 | 03 | 20–27 | Eight screen modules |

Owner model: `openai-codex-secondary/gpt-5.6-sol`, thinking `medium`.
Worker model: `openai-codex-secondary/gpt-5.6-luna`, thinking `xhigh`.
Each owner may start eight workers. This launch authorizes 24 source assignments, not an automatic refill beyond those modules.

All 27 worktrees started clean at the recorded base.
The first 20 staging worktrees were fast-forwarded. Seven additional sparse worktrees were created.
Existing pilot worktrees and commits remain preserved.

Root retains `include/resource_ids.h` and all unassigned headers.
Owners edit their assigned headers. Workers edit distinct source files and module reports.
Reading headers does not block independent changes. Required new definitions remain explicit integration dependencies.

Owners must review full worker diffs, request corrections, and integrate complete approved module commits in their own branches.
Root must inspect full group diffs before main integration.
No compiler checks, builds, matching checks, audits, tests, or games are authorized during this phase.
All results remain unvalidated against the preserved pre-cleanup compiler output until final validation.
