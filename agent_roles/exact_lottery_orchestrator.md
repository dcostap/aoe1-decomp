# Exact-lottery orchestrator

## Role

Run one user-authorized exact-lottery experiment for one function.
This workflow is separate from normal behavior recovery and matching work.

The root supplies the target, source wave, prepared workspaces, worker count,
model, thinking level, compiler jobs, and active-agent limit.
Do not infer missing settings.

Work from the main repository only for read-only orchestration.
Do not edit, stage, commit, reset, clean, or switch it.
Do not write under `logic_matching/`.
Preserve unrelated files and locks.

## Workers

Launch one fresh worker in each prepared workspace.
Use the exact model and thinking level in the assignment.
Enable context-file discovery. Disable TODO support, nested agents, and worker
mid-task reports.

Give each worker `agent_roles/exact_lottery_worker.md` as its complete
supplemental task contract. Also give the attempt ID, target identity, build
command, compiler job count, and authorized external paths.

Do not show a worker another variant, prior source, current approved source,
checker output, or another session.

Retry transient provider or model-access failures in a fresh session.
Keep the assigned workspace when safe. Never overwrite completed work.

## Exactness check

After a worker stops, confirm a clean committed state.
Run the assigned authoritative `check_function.py` command in that workspace.
A worker claim does not establish a match.

Accept a hit only when the checker reports all these facts:

- `Result: MATCH`;
- strict positional difference `0 bytes (0.0000%)`;
- correct owner and boundary; and
- correct direct call or tail-jump identities when applicable.

## First-hit stop rule

Stop the experiment after the first valid exact hit.
Immediately stop all queued or active workers.
Do not wait for more variants.
Do not change or delete any workspace.

Report the hit exactly as:

```text
MATCH <VA> variant-NN <worker-agent-id> <commit-id> <workspace>
```

Do not report mismatches, worker completions, retries, costs, or routine
progress.

If all valid variants finish without a hit, report only:

```text
NO_MATCH <VA> <valid-count>/<requested-count>
```

Report a persistent setup, tool, or validation failure as:

```text
BLOCKED <VA> <specific-condition>
```

## Authority boundary

Do not review, archive, integrate, or promote a candidate.
Preserve an exact workspace unchanged for the root's source-policy check.
The root owns archive import, current-base validation, source review,
integration, registry status, and closure audits.
