# Durable experiment branches

This is a working pilot, not a replacement for the function registry.
It extends the existing compiler-input manifest and checker workflow.
Every matching assignment must follow this workflow. Tool limitations do not make evidence preservation optional.

The existing matching workflow remains the default.
For `Workflow: matching with reviewers`, follow `workflow/docs/matching_with_reviewers.md` and `workflow/agent_roles/matching_reviewer.md` too.
The reviewer performs the technical review below; the orchestrator routes findings and retains final integration authority.
This changes who reviews the evidence, not what must be captured, proved, or preserved.

## Separate the questions

A state records exact inputs. A run records a check of those inputs.
A finding records evidence, an objection, or an open question.
None of these records selects a registry status.

Keep behavior evidence, source support, byte results, and closure effects separate.
A lower byte distance cannot justify wrong behavior.
An integration objection does not close every experiment derived from that state.

Do not merge different source states because they emit equal bytes.
When compiler context changes, retry useful natural reductions from the new state.
Preserve failed builds. Do not reuse old metrics after a failed build.

## Storage

The durable store is `workflow/decomp_notes/experiments/`:

- `states/` contains immutable state manifests with parent IDs.
- `events/` contains immutable results and findings.
- `objects/` contains deduplicated input and evidence bytes, addressed by SHA256.

Objects are archives, not compiler-facing source owners.
The store preserves line endings. Git attributes disable text conversion for hashed files.
Writes use atomic publication.
Names are convenient selectors; complete hashes are stable identities.
A name must identify one state. No score removes or hides a state.

The Git base supplies the original executable, inventory, and unchanged repository files.
Snapshots supply repository compiler inputs, the owning registry, and local tool/config changes, including new files.
External headers and compiler files remain installed prerequisites. Their hashes must match.
The tool never replaces an external file to force reproduction.

Keep the recorded base commits reachable in Git. The pilot does not package the toolchain or create Git bundles.
A clone without the base commit or matching external prerequisites cannot reproduce the state.
The pilot uses the existing dependency scanner, not an arbitrary build-system capture.
It refuses deleted source, header, tool, or config files instead of recording an incomplete restoration.

### Unsupported inputs

Do not bypass a capture refusal or claim reproduction without proof.
Preserve a complete patch, new input files, base commit, compiler recipe, and required evidence in a durable experiment directory.
Record the hypothesis, parent IDs, input and prerequisite hashes, and exact commands.
Record missing prerequisites and the capture failure. Report this as a tooling blocker in the handoff.
Do not replace the only recoverable inputs until the orchestrator confirms preservation.

## Commands

Run each tool with `--help` before use.
Commands below assume this repository is the shell working directory.

```text
python tools/experiment_history.py record --workspace WORKTREE --va VA --name NAME --parent PARENT --hypothesis TEXT --provenance TEXT
python tools/experiment_history.py run NAME --workspace WORKTREE --closure --jobs JOBS
python tools/experiment_history.py show --va VA
python tools/experiment_history.py compare LEFT RIGHT
python tools/experiment_history.py inspect NAME
python tools/target_session.py branches --va VA
```

Omit `--parent` for a root state. Repeat it when combining branches.
Record inputs before running the checker, including inputs expected to fail compilation.
A failed build remains a result without a byte score.
A zero tool exit means it saved a result, not that the source passed.
Read the saved checker and closure results before selecting further work.

`run` rebuilds the target and can audit the complete translation unit.
It checks input hashes and compiler context before and after execution.
Its summary displays exact-neighbor regressions even when the audit command succeeds.
Closure runs also preserve the object and per-owner output hashes.
`compare` reports changed compiled owners, including changes hidden by equal difference counts.
A target `MATCH` automatically exports a complete candidate patch under `workflow/decomp_notes/candidates/`.
It does not integrate the candidate or change status.

Append evidence with:

```text
python tools/experiment_history.py note NAME --kind finding --text TEXT --artifact FILE
```

Other finding kinds are `reported`, `integration-objection`, and `open-question`.
Repeat `--artifact` to preserve logs, tests, or source evidence.
Use `inspect` to obtain artifact hashes. The corresponding objects contain the complete saved bytes.
Use its `state_id` and `event_id` fields in handoffs. The internal `record_uuid` is not an event selector.
Do not edit a manifest to revise a conclusion. Append a correcting finding.

## Reproduction and branch switching

```text
python tools/experiment_history.py reproduce NAME --destination NEW_WORKTREE
python tools/experiment_history.py switch --from-state CURRENT --to-state NEXT --workspace WORKTREE
```

`reproduce` creates a detached Git worktree at the recorded base.
It restores saved repository inputs and verifies external prerequisites.
It refuses every existing destination, including the shared workspace.
It copies no build cache. Run validation after reproduction.

`switch` operates only in an isolated workspace.
The tool identifies linked worktrees through Git metadata, not through the location of its own script.
Workers can run the tool from their assigned linked worktree without creating another worktree.
It verifies the expected current state and refuses staged or unrelated changes.
The pilot requires the same Git base and repository input path set for switching.
Use a new reproduction workspace when either differs.
Switching does not reuse old validation as a fresh result.

Use one editor per experiment workspace. Do not edit inputs during a check.
The pilot does not coordinate arbitrary external editors or provide transactional multi-file switching.
An interrupted switch can leave mixed inputs. Verification will reject them; use a fresh reproduction workspace.

## Worker procedure

1. Inspect the saved branches before selecting a starting state.
2. Read their findings and specific integration objections.
3. Reproduce a useful state, rather than copying only its function body.
4. Make one supported change and record a child state before checking it.
5. Compare source, context, output, and closure effects with its parent.
6. Test interacting changes in combination when evidence supports that test.
7. Preserve the branch before switching away from it.
8. Integrate only after the normal source and closure review.

Unsupported source can remain archived as diagnostic evidence.
It cannot enter the game source merely because it matches.
A proved behavior repair remains useful even when its byte result gets worse.

Legacy `check_function.py` history remains available.
Metric-only history deletion is now disabled, including `--apply-prune`.
The pilot does not automatically import every old checkpoint or Pi transcript.

## Required handoff and review

Every worker handoff must use these four headings for each finding or proposal:

1. **Behavior:** Executable evidence, tests, counterexamples, and coverage limits. State what remains unknown.
2. **Source:** Evidence for ownership, types, layout, and natural source. Identify unsupported constructs and unresolved objections.
3. **Bytes:** Baseline, parent, and tested results, with state IDs and compiler context. Include failed builds and changed owners.
4. **Integration:** Proposed action, affected closure, validation, blockers, and useful next steps. The worker proposes; the orchestrator decides.

Use this report even when no source change remains. Write `not tested` or `unknown` instead of omitting a heading.
Link preserved states and evidence. Do not substitute a list of scores for the report.
Reviewers must compare the handoff with every new state and event in the worker store.
Request missing findings and correct invalid references before integration. Equal-output probes still need preservation decisions.
Read each state's input diff before accepting its behavior or source findings.
Check initialization, bounds, widths, aliases, and memory-access order. A hypothesis label does not prove what the edit does.
An accidental behavior change does not test the intended source-only hypothesis. Preserve it and correct the conclusion explicitly.

Review Behavior and Source before Bytes. Reject an unsafe change, not a score increase alone.
A better score cannot override contrary behavior evidence or a source-policy objection.
Equal scores or target bytes do not prove equal source, context, or neighbor behavior.
Record separate decisions for source integration and experiment preservation.
Explain each decision with evidence, not score alone. A rejected source change can leave useful experiments and findings.

Before worktree reuse, transfer new records, referenced objects, candidate patches, and fallback evidence into reviewed Git history.
Verify their hashes, parent references, and reachable base commits. Do not preserve only a summary or build-directory path.
Resolve conflicting state names without overwriting immutable records; use state IDs when names are ambiguous.
The integrator commits evidence even when it does not integrate the tested source.
Carry the four-part report and evidence-preservation decision through orchestrator and root handoffs.

## Pilot results

See `workflow/decomp_notes/experiments/README.md` for the tested states and current limitations.
