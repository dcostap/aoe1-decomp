# Hierarchical cleanup orchestration

This workflow replaces the pilot's transitive header locks and ten-worker total limit.
All other source-cleanup and unchanged-output requirements remain active.

## Capacity and models

- Root may run at most ten group owners. The initial assignment starts three.
- Owners use `openai-codex-secondary/gpt-5.6-sol`, thinking `medium`.
- Each owner may run up to eight source workers.
- Source workers use `openai-codex-secondary/gpt-5.6-luna`, thinking `xhigh`.
- Source workers cannot delegate. Owners cannot create additional owners.
- Stop refilling when review work accumulates. Do not expand beyond assigned modules without root approval.

## Editing ownership

Root assigns disjoint source groups and explicit header lists.
Each source worker owns one source file and its own report, in a separate worktree.
The group owner edits its listed headers in the group integration worktree.
Workers submit header requests with proposed declarations, mappings, and evidence. They do not edit headers.
A source worker may rename parameters independently of header parameter names when types and signatures remain unchanged.

Root retains all unassigned headers, including `include/resource_ids.h` and headers shared across groups without another explicit owner.
Reuse resource definitions already present. Submit new resource mappings instead of creating competing macros or headers.
Keep unresolved substitutions numeric until the root provides the shared definitions.
This does not stop unrelated cleanup or the worker's initial report and commit.

Reading a header is not an editing conflict. Do not block every transitive consumer.
Wait only when a particular source change requires a pending declaration.
Do not change layouts, ABI, types, macro values, or runtime behavior to make parallel changes fit.

## Owner review

Read all source-cleanup guides before assigning work. Give each worker exact paths, base, evidence paths, and scope.
No owner or worker may compile, build, run matching checks, audits, tests, or games in this phase.
Evidence extraction and full Git diff review are allowed. Run repository tools with `--help` before use.

Read every worker's complete diff and report, not just its summary.
Check systematic PDB recovery, original names, types, scope, constant meaning, formatting, and sparse useful comments.
Resume the same worker for corrections. Do not silently omit hunks or accept unfinished changes.
Integrate complete approved module commits into the group branch, preserving module identity.
Review header commits with the combined source changes before delivery.
Do not resolve conflicts by overwriting changes or silently choosing one side.

Record each module's worker ID, base, commits, header requests, review findings, corrections, and integration status in the group ledger.
Copy full hashes from Git. Record separate header commits and their affected modules.
Keep rejected commits and worktrees. Do not delete or reset evidence.

Root reviews the complete group diff before integration. Root can return the group for corrections.
A group report must identify outstanding cross-group requests and whether they block particular edits.
All integrated results remain reviewed but unvalidated until final checks against the preserved pre-cleanup build.

## Evidence and worktrees

Use shared original assets, PDB reference data, inventories, and preserved builds through absolute main-tree paths.
Do not copy large assets or builds into worker worktrees.
Do not edit another worktree, except that owners may fast-forward their explicitly assigned clean staging worktrees before launch.
Do not reset or update a worker's worktree while it is active.
Owners must use their own group integration worktree, not main.
Module report paths and header ownership remain exclusive even across different Git worktrees.
