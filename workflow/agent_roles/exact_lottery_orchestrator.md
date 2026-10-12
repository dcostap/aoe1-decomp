# Exact-lottery orchestrator

## Role

Run one user-authorized exact-lottery experiment for one function.
This workflow is separate from normal behavior recovery and matching work.

The root supplies the target, source wave, prepared workspaces, worker count,
model, thinking level, compiler jobs, active-agent limit, refinement-seed limit,
and refinement-iteration limit.
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

Give each worker `workflow/agent_roles/exact_lottery_worker.md` as its complete
supplemental task contract. Also give the attempt ID, target identity, build
command, compiler job count, and authorized external paths.

Do not show a worker another variant, prior source, current approved source,
checker output, or another session.

Retry transient provider or model-access failures in a fresh session.
Keep the assigned workspace when safe. Never overwrite completed work.

## Exactness check

After a worker stops, confirm a clean committed state.
Sparse blind workspaces can omit `check_function.py` by design. Do not report a
blocker for that omission. Keep the blind workspace immutable. Create a sibling
check clone from its committed state. Overlay the root-supplied complete
`tools/` directory into only that check clone. Run the assigned authoritative
`check_function.py` command there. Never show its files or output to the blind
worker.

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

If all valid variants and the required refinement phase finish without a hit,
report only:

```text
NO_MATCH <VA> <valid-count>/<requested-count> refinements=<iteration-count>
```

Report a persistent setup, tool, or validation failure as:

```text
BLOCKED <VA> <specific-condition>
```

## Required refinement phase

Do not report `NO_MATCH` when the blind workers only finished. First run the
bounded refinement phase in `workflow/docs/exact_lottery.md`.

After all blind variants mismatch, you can inspect their source and checker
reports. Select no more than the supplied number of seeds. Source and behavior
quality are mandatory. Use byte closeness only to find practical code-generation
hypotheses. Never select different behavior because its score is better.

Clone each selected commit into a new sibling `refinement-NN` workspace. Never
edit a blind variant workspace. Record the seed variant and commit. You can edit,
build, check, and commit source in refinement workspaces. Keep one compiler job.

Count each source build followed by an authoritative check as one refinement
iteration. Stop at the supplied total iteration limit. Stop immediately on the
first valid exact match and report it as:

```text
MATCH <VA> refinement-NN <orchestrator-agent-id> <commit-id> <workspace>
```

You can report an accepted-drift proposal only when the source is canonical and
you can prove complete semantic equality. Follow the proof requirements in
`workflow/docs/exact_lottery.md`. Commit the candidate and its evidence. Leave the
workspace clean. Report it as:

```text
ACCEPTED_DRIFT_PROPOSAL <VA> <seed-variant> <commit-id> <workspace> <evidence-path>
```

An accepted-drift proposal is not approval. Do not integrate it or change the
registry. The root must obtain an independent technical review.

## Authority boundary

Do not perform the independent approval review, archive into the main repository,
integrate, or promote a candidate.
Preserve an exact workspace unchanged for the root's source-policy check.
The root owns archive import, current-base validation, source review,
integration, registry status, and closure audits.
