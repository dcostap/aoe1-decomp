# Behavior recovery orchestrator

## Role

Use this workflow when the user selects behavior recovery.
One orchestrator manages workers, compares results, prepares candidates, and integrates approved source.
Do not add another orchestration layer or inherit the old matching-worker procedures.

Keep the system small: one workspace preparer, one result collector, and the existing managed subagent tools.
No new scheduler, database, or mandatory per-edit experiment system is needed.
`tools/behavior_recovery.py` implements preparation, workspace copies, collection, and candidate export.
The registry supports `new_verified_logic`. No existing function changes status automatically.

The worker instructions live in `agent_roles/behavior_recovery_worker.md`.
That document covers both reconstruction and review.
Do not copy this orchestrator document into worker workspaces.

## Assignment and launch

Assign one function per worker. Several workers may independently receive the same function.
Each worker gets its own fresh repository and session.
One wave groups attempts with the same prepared input and mode.
There is no required attempt count or wave count.

Before launch, obtain the user's exact provider/model IDs, thinking levels, concurrent agent limit, and compiler job setting.
The same model may serve both modes if the user selects it.
Do not infer these settings. Do not launch nested agents or enable TODO support without permission.

Keep each assignment short:

- attempt ID and mode: `reconstruct` or `review`;
- target VA, symbol, source path, and evidence paths;
- workspace and prepared baseline commit;
- compile command and compiler job setting; and
- any task-specific question or authorized compiler/SDK paths.

Launch through the managed subagent tool with the workspace as `cwd`.
Use fresh context and keep context-file discovery enabled.
Do not supply the parent transcript, old target implementation, prior conclusions, or other attempts.
Continue useful work while agents run. Use completion notices rather than repeated polling.

## Prepare the workspace

Use a fresh repository, not a Git worktree.
A worktree shares the original repository's history.
Create workspaces outside the main repository's directory tree.
Never strip files or history from the main repository or an existing worktree.

Pi loads context files from the current directory, ancestor directories, and the global agent directory.
A root `AGENTS.md` does not replace ancestor instructions.
Check the chosen location for inherited project instructions and report any conflict before launch.
Global user instructions can still apply.

Prepare each wave from a recorded, committed main revision:

1. Export an explicit allowed file set into a new directory.
2. Prepare the target for the selected mode.
3. Copy `behavior_recovery_worker.md` to the workspace root as `AGENTS.md`.
4. Check the source changes, evidence, and compiler setup.
5. Initialize Git and commit the prepared input.
6. Preserve that input before launching workers from independent copies.

Source, flags, and evidence come from the selected Git revision, not dirty working files.
The worker role and selected tools come from the orchestrator's current checkout.
The saved input records their exact bytes and hashes too.

Do not copy the main `AGENTS.md`, other role documents, or project-local Pi configuration.
Do not leave alternate context files that can replace or supplement the worker instructions.

### Included files

- Current source and headers, including required `third_party/` headers, except the target changes described below.
- Original executable and PDB evidence needed for static inspection.
- Existing inventory, including assembly, Ghidra output, symbols, types, and PDB line records.
- Required compiler configuration and build metadata.
- A hardcoded selection of useful tools and their imported dependencies.

Keep exported evidence unchanged. Do not regenerate it for an attempt.
Select tools that compile the owning translation unit, inspect instructions, and query PDB or ABI evidence.
Check their dependencies and data paths. Do not copy the whole tool directory for convenience.

Exclude old target notes, review ledgers, candidate patches, experiment archives, matching documents, and build caches.
Do not expose byte-score tools, variant labs, or status-management procedures to workers.
Remove copied references or embedded reconstruction notes that reveal the withheld target implementation.
Do not rewrite unrelated source or original evidence during preparation.

### Target modes

For `reconstruct`, remove the target implementation before the first Git commit.
Remove its reconstruction comments and constructor initializer list when applicable.
Keep declarations as a starting model, not as proof that their types are correct.
Supply the reviewed definition's complete line range to `prepare`.
The tool replaces that range with `#error BEHAVIOR_RECOVERY_UNIMPLEMENTED_<VA>`.
Separate header declarations remain. A header-owned inline definition is removed as one region.
Compilation must fail until the worker supplies an implementation.
Verify the exact source region. Do not trust a blind text replacement.
The tool checks simple brace structure and the function name; it is not a C++ parser.
It rejects unsupported ranges rather than guessing.

For `review`, supply the complete selected candidate, including its supporting source and header changes.
Do not supply earlier reports, approval claims, or other attempts unless the assignment explicitly requests a focused follow-up.

Workers still see recovered callers, headers, and neighboring functions.
This is independent target reconstruction within shared source context, not complete freedom from prior assumptions.

### Build and access limits

Provide the pinned VC5 compiler recipe for the natural owning translation unit.
Do not substitute a standalone stub build as proof that the real source compiles.
Check the build setup without recovering or exposing the withheld target body.
The worker must compile the completed implementation before delivery, or report the exact blocker.
Preparation checks tool imports and runs the configured compiler without exposing the withheld body.
Reconstruction input must stop at its explicit `#error` marker. Review input must compile successfully.
The wave records compiler diagnostics, input hashes, and external prerequisites.
`build_function.py` compiles one translation unit per invocation. Agent capacity controls parallel invocations.

Permit only the declared compiler and SDK access outside the workspace.
Workers must not use the network or inspect the main repository, other workspaces, or past sessions.
These are instruction-based restrictions unless separate filesystem and network controls enforce them.
A fresh repository is not a security boundary. Do not claim otherwise.
Do not add a sandbox framework as part of this small workflow without separate agreement.
Use static executable evidence and compiler checks. Do not run original or rebuilt game executables.

## Preserve every result

Store durable results in the main repository under `logic_matching/<VA>/`.
Use UTC date and time in wave names. Add a suffix if a name already exists.
Never overwrite an earlier wave, attempt, candidate, or report.

```text
logic_matching/<VA>/
  wave-YYYYMMDD-HHMMSSZ/
    wave.json
    input.zip
    attempt-01/
      attempt.json
      changes.patch
      commits.patch
      report.md
      evidence/
  candidate-01/
    candidate.json
    changes.patch
    report.md
```

`input.zip` preserves one complete prepared file set per wave, without Git internals or build caches.
Share this archive across the wave; do not repeat it for each attempt.
Record its hash, main base, prepared commit, mode, target, compiler configuration, and parent candidate in `wave.json`.
`attempt.json` records the agent ID, exact model, thinking level, final commit, and completion or interruption state.
Record external compiler/SDK prerequisites and their identities. Do not imply the archive contains them.

Collect the complete final diff against the prepared baseline, including new files and binary changes, as `changes.patch`.
Preserve the worker's commit series after that baseline as `commits.patch`, including extended commit messages.
A final diff alone does not preserve intermediate committed attempts.
Copy the committed `report.md` and any cited validation outputs into the attempt directory.
Pass each cited output through `collect --evidence`; ignored build files are not otherwise included.
An unchanged review has an empty source diff but still has a report.

Workers may commit as needed. They need not commit every edit.
Preserve all delivered attempts, including failed builds, rejected source, and unresolved results.
If a worker stops unexpectedly, capture recoverable committed and dirty changes separately and mark the attempt incomplete.
Use `collect --incomplete`. It adds `dirty.patch` and `untracked.zip` when uncommitted work exists.
Do not treat an incomplete attempt as a normal clean delivery.

Check that the saved patch reconstructs the delivered files from the saved input.
Preserve cited evidence before workspace cleanup. Recycle disposable workspaces only after collection succeeds.

## Compare, combine, and review

Inspect every changed path, not only the target body.
Compare behavior, source choices, supporting changes, doubts, and compile results across attempts.
Common choices and repeated objections are useful leads, not proof.

Create one or more candidates when useful. Use the same patch-and-report form as worker results.
Record the main base and parent attempts or candidates in `candidate.json`.
Explain selected choices and unresolved questions in `report.md`.
Candidate patches describe changes against their recorded main base, not against a blank worker target.
Select every required file with repeatable `candidate --path` arguments.
The tool records omitted supporting paths for review. It does not decide whether omission is safe.

To combine source choices, edit another private workspace, then collect it as an orchestrator attempt.
Use a review wave's prepared input when starting from an existing candidate.
Record additional contributing attempts with `candidate --parent` and explain the choices in the selection report.
Do not change an archived attempt or an active worker's workspace.

Worker patches start from prepared input. Do not blindly cherry-pick them onto main's existing implementation.
Prepare the integration change against main and include every required supporting change.
Do not extract only a body when its declarations, fields, or helpers also changed.

Send a selected candidate through a fresh review wave when useful.
Review workers may repair source, return an unchanged version, or report an unresolved problem.
Review a combined candidate itself. Approval of separate pieces does not approve their combination.

For a serious objection, require original instruction addresses, the disputed behavior, and a distinguishing input or path when possible.
Record assumptions that prevent resolution.
Repeated agreement or unchanged source does not prove equivalence.
Do not repeat unchanged review cycles without a specific question that can improve the decision.

The orchestrator resolves disagreements from evidence and records the reason.
Uncertainty about original spelling or harmless source structure need not block completion.
Do not turn unresolved material behavior differences into approval through a vote or a claim of stability.

## Integration and status

The orchestrator alone selects source for main and changes registry status.
Keep all alternative attempts even when only one candidate integrates.

Before promotion:

1. Review behavior coverage, source ownership, ABI, calls, memory effects, and relevant faults.
2. Resolve material objections or leave the result unpromoted with a clear explanation.
3. Compile the selected source in its real translation unit.
4. Run existing regression checks for every affected owner, including shared-header dependencies.
5. Investigate changed exact owners; do not reject supported repairs solely because bytes differ.
6. Check that the integrated inputs are the reviewed inputs. Recheck changes made during integration.
7. Preserve the final decision, validation, and links to the selected candidate.

Use `new_verified_logic` for completed recovery under this workflow.
Leave the existing `verified_logic` set unchanged. Do not bulk reclassify existing completed functions.
No worker vote, wave count, compilation result, or byte score alone earns this status.

Record the final semantic decision in the function's existing review ledger and link its archived candidate.
The registry remains the status authority. The archive preserves attempts and decisions, not a second live status database.

Start with one function through preparation, reconstruction, review, collection, and integration.
Expand to larger waves after that complete path works.

## Tool use

Run `python tools/behavior_recovery.py --help` and the selected subcommand's `--help` before use.
The tool does not launch agents, integrate source, or promote registry entries.

```text
python tools/behavior_recovery.py prepare --va VA --mode reconstruct --base BASE --start-line FIRST --end-line LAST --destination WORKSPACE
python tools/behavior_recovery.py workspace --wave WAVE --destination SECOND_WORKSPACE
python tools/behavior_recovery.py collect --wave WAVE --workspace WORKSPACE --attempt attempt-01 --agent-id AGENT --model PROVIDER/MODEL --thinking LEVEL --evidence BUILD_REPORT
python tools/behavior_recovery.py candidate --attempt ATTEMPT --name candidate-01 --path SOURCE --path HEADER --report SELECTION_REPORT
python tools/behavior_recovery.py prepare --va VA --mode review --base BASE --candidate CANDIDATE --destination REVIEW_WORKSPACE
```

The default archive root is `logic_matching/`. Use `--store build/behavior-tests` for tool tests.
Each workspace contains `assignment.json` with its target, evidence path, and compile command.
Existing destinations and archive names are rejected, not overwritten. Use `--wave-name` when a UTC name collides.
Read and inspect prepared source before launch, including nearby comments that could expose the withheld implementation.
After collection, inspect the archive and all supporting changes before candidate selection.
