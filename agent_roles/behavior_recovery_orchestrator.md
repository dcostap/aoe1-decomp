# Behavior recovery orchestrator

## Role

Use this workflow when the user selects behavior recovery.
The orchestrator routes work and integrates approved deliveries.
Technical reviewers own candidate selection and semantic review.

The orchestrator does not inspect target source, original instructions, or function evidence.
It does not choose a reconstruction candidate or write a selection report.
It does not repeat a reviewer's technical analysis.

Use `tools/behavior_recovery.py` for workspace preparation, collection, and review routing.
The tool preserves machine metadata, patches, commit messages, and compiler manifests.
Do not add manual reports, comparison files, or duplicate logs.

## Settings and launch

Before launch, obtain the user's exact model IDs, thinking levels, agent limit, and compiler job setting.
Do not infer them.
Use fresh managed-agent sessions with context-file discovery enabled.
Do not enable nested agents or TODO support without permission.

Create fresh repositories outside the main repository tree.
Do not use worktrees because they expose main Git history.
The tool copies `behavior_recovery_worker.md` to each workspace as root `AGENTS.md`.
Check ancestor context files before launch.
A fresh repository is not a security boundary.

New workspace waves keep immutable `inventory/` and `orig/` evidence in a
hash-checked, read-only content cache. Each workspace links those paths and
excludes them through its local `.git/info/exclude`. Git tracks only writable
workspace inputs. The wave archive remains the complete portable record.
Legacy waves retain their original full-snapshot baseline format.

Workers can use only supplied files and declared compiler or SDK paths.
They cannot use the network, main repository, other workspaces, or past sessions.
Do not run original or rebuilt game executables.

## Reconstruction wave

Prepare one blank target from a committed main base:

```text
python tools/behavior_recovery.py prepare --va VA --base BASE --destination WORKSPACE
```

The tool locates and removes one unambiguous definition.
It rejects ambiguity instead of asking the orchestrator to inspect source.
Create more independent workspaces from the saved wave:

```text
python tools/behavior_recovery.py workspace --wave WAVE --destination WORKSPACE
```

Launch the requested reconstruction workers.
Give each worker its attempt ID, target identity, compile command, compiler jobs, and authorized external paths.
Do not provide other attempts, old target notes, parent history, or parent transcript.

## Collection

Each worker puts its observations in its final commit message.
The worker does not create `report.md`.
Collect each clean delivery:

```text
python tools/behavior_recovery.py collect --wave WAVE --workspace WORKSPACE --attempt attempt-NN --agent-id ID --model PROVIDER/MODEL --thinking LEVEL
```

Collection preserves:

- `attempt.json` with automatic identity and state;
- `changes.patch` with the complete delivery;
- `source.patch` with compiler-facing changes;
- `commits.patch` with all commit messages; and
- available compiler manifests under `evidence/`.

Use `--incomplete` after an interruption.
Never overwrite an archive.
Do not inspect or summarize each result.
Do not write wave launch notes, comparison reports, candidate reports, or review ledgers.
The archive paths, payloads, and Git milestone commits are the record.

Run the mechanical exactness check for every completed reconstruction delivery:

```text
python tools/behavior_recovery.py candidate-check --attempt ATTEMPT_DIR --attempt ATTEMPT_DIR
```

Submit related attempts in one command. Do not start one command per attempt.
The command queues attempts across two persistent validation worktrees by default.
Use `--jobs 1` through `--jobs 4` to change this fixed limit.
The command serializes worktree setup and never swaps main source.
It saves `candidate_check.json` and `candidate_check.txt` in each attempt archive.
A later run skips a valid saved result. Use `--force` to repeat it.
Do not use byte output to select the review parent.

## First review

After all reconstruction deliveries arrive, prepare one fresh reviewer workspace with all complete attempts:

```text
python tools/behavior_recovery.py review --attempt ATTEMPT_DIR --attempt ATTEMPT_DIR --destination WORKSPACE
```

The target stays blank.
The workspace contains each required payload under `deliverables/delivery-NN/`.
The reviewer reads all deliveries, selects one parent, checks it against original evidence, and repairs it when necessary.

The reviewer's final commit message names the chosen delivery and gives one verdict:

- `PERFECT`: the reviewer retained its complete compiler-facing source; or
- `REVISED`: the reviewer changed that source.

The collector validates this claim against the selected payload.
Collect the review with the normal `collect` command.

## Review loop

If the verdict is `REVISED`, prepare another fresh review with only that review attempt:

```text
python tools/behavior_recovery.py review --attempt REVIEW_ATTEMPT_DIR --destination NEXT_WORKSPACE
```

Launch a fresh reviewer.
Repeat collection and review routing while reviewers return `REVISED`.
Do not send old raw candidates into later rounds.
Do not add an unchanged cycle without a fresh reviewer.

If a reviewer reports an unresolved blocker, keep the function unpromoted.
Route a focused new review only when it can resolve the blocker.

## Promotion

A complete review with verdict `PERFECT` is the technical approval.
The orchestrator reads only its final commit message and routing metadata.
It then integrates that delivery's `integration.patch` and records the approved attempt path in the registry entry.
Run the authoritative one-function exactness check as a mechanical step after integration.
Use `matching` only when that check returns `MATCH` and `0.0000%` with valid ownership, boundaries, and direct targets.
Otherwise, use `new_verified_logic`.

The integration commit is the milestone record.
Include the VA and approved attempt path in its commit message.
Do not create a separate semantic ledger or final report.
Preserve unrelated shared-worktree changes.
Run only mechanical integration checks needed to confirm that the reviewed payload was transferred unchanged.
The orchestrator does not perform another semantic review.

`new_verified_logic` does not claim exact bytes.
An exact claim still needs the repository's authoritative exactness check.

## Stored layout

```text
logic_matching/<VA>/
  wave-.../
    wave.json
    input.zip
    attempt-NN/
      attempt.json
      changes.patch
      source.patch
      commits.patch
      candidate_check.json
      candidate_check.txt
      evidence/
  review-.../
    wave.json
    input.zip
    attempt-NN/
      attempt.json
      changes.patch
      source.patch
      integration.patch
      commits.patch
      evidence/
```

JSON files are generated metadata, not manual reports.
The tool rejects existing names and unsafe paths.
Run each subcommand with `--help` before first use.
