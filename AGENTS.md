# Repository-wide agent contract

This file contains universal rules. Keep role-specific procedures in workflow documents.
## Understand your role

The assigning prompt or assigned task(s) define your role and instructions. If not sure, ask the user or the agent that spawned you.

There are extra reusable documents that contain specific instructions. Read the documents if clearly related to your role:
- For performing function matching, read `docs\agentic_matching_workflow.md`.
- If you were assigned a main agent, or you have tasks that involve: project orchestration, subagent orchestration, logic review, semantic review: read `docs\main_agent_workflow.md`.
- If the user is interacting and chatting with you directly, read `docs\user_agent.md`.

## Universal correctness rules

- The project is function-first and exact-match-first.
- The original executable is the behavior oracle.
- PDB, Ghidra, generated inventories, and comments are reference evidence.
- Use the repo-local original files under
  `orig\original_full_game_files_rise_of_romes_beta_17_7_1998`.
- Use the pinned VC5 host toolchain from `config\toolchain.json`.
- Baseline compiler flags come from `config\flags\default.rsp`. Use the configured target or translation-unit response file when one exists
- Exactness requires positional byte equality.
- Exactness also requires the original boundary, provable owning symbol, and known direct call or tail-jump symbol identity.
- Never infer exactness from folder placement, old metrics, or relocation masking.
- Validate standalone exact claims with `tools\check_function.py`.
- Validate grouped claims with the candidate or registered translation-unit checks.
- Require `MATCH`, `0.0000%`, correct ownership, boundaries, relocations, and direct targets.
- A valid exact result says `Result: MATCH` and `0.0000%`.

Inline assembly is forbidden for real functions unless explictly allowed.
This includes `__asm`, `_asm`, naked functions, and handwritten wrappers.

Padding-only pseudo-functions may use byte filler when the complete body has no
behavior, memory effect, call, or real control flow. Padding status must be
reviewed and listed in `config\padding_only_functions.txt`.

## Source-recovery standard

Recover the simplest binary-supported, period-plausible source first. Reconstruct
what the original developers probably wrote.

Establish canonical ownership before codegen tuning. Model proven fields, arrays,
bases, widths, offsets, vptrs, lifetimes, API structs, and virtual slots.

Decompiler output describes effects. It is not a source template. Do not retain
raw cursor arithmetic, fake helpers, fake volatility, manual vtables, redundant
aliases, or forced scheduling without binary evidence.

An unusual source form can remain only when one condition applies:

- period source or exact donors support it;
- it produces an exact result without violating policy; or
- binary evidence proves behavior that a simpler form loses.

Preserve original bugs, narrow widths, overlap, aliasing, evaluation order, and
fault order when the executable proves them.

## Corpus and source ownership

The corpus buckets are:

- `normal`: ordinary game functions;
- `padding_only`: non-behavioral byte-preservation entries;
- `compiler_generated`: compiler-emitted functions without standalone source bodies;
- `parent_owned_fragment`: blocks owned by a larger game function;
- `toolchain_supplied`: imports, CRT code, and compiler helpers;
- `asm_special`: named handwritten assembly;
- `asm_region`: assembly, codelet, or data-dispatch neighborhoods.

Do not create ordinary function sources for non-normal entries. Their reviewed,
self-documented manifests live under `config\`.

Repository source roles are:

- `inventory\`: generated reference material; do not edit it;
- `include\`: reviewed shared declarations and layouts;
- `src\game_globals.cpp`: reviewed shared global definitions;
- `src\scratch\`: unresolved normal functions;
- `src\accepted_drift\`: rare reviewed localized equivalent drift;
- `src\verified_logic\`: reviewed semantic reconstructions that are not exact;
- `src\matching\`: current exact functions;
- `logic_reviews\`: versioned semantic-review ledgers;
- `LESSONS.md`: reusable VC5 matching knowledge.

A VA has one compiler-facing source owner. Never keep duplicate owners across
source banks.

Do not reopen accepted drift without specific new evidence. Folder placement is
the current reviewed status.

## Shared-worktree conduct

Preserve unrelated changes. Never clean, reset, normalize, or overwrite another
participant's work.

Send untracked cleanup files and directories to the Windows Recycle Bin. Do not
use permanent filesystem deletion for cleanup. Tracked deletions stay recoverable
through Git.

Do not make broad shared-header changes for a local experiment. Report every
shared file that you change.

Keep compiler outputs and experiments under `build\`. Do not write generated
artifacts into tracked source directories.

Do not change existing line endings without a functional reason.

Pi runs shell commands through Bash. Use forward slashes in Bash command paths.
Unquoted Windows backslashes can become escapes.

Markdown files define policy and workflow, not command syntax. Before you use a
repository tool, run its `--help`. Treat that output as the command reference.

Use the harness `everything_search` tool for recursive path discovery. Use `rg`
for file content searches. Do not recursively enumerate the repository with
`find` when Everything can answer the query.

## Evidence and communication

Separate facts from hypotheses. State the source of each important conclusion.
Do not call generated metadata a behavior oracle.

Exact matching source is strong codegen evidence. A narrow exact local stub does
not automatically define canonical shared ABI.

Record durable target conclusions in the target source or its assigned ledger.
Do not rely on ignored session files as the only record.

Add a reusable lesson only after a non-obvious pattern is supported by exact or
strong repeated evidence. Keep function-specific history out of `LESSONS.md`.

When work stops, report the result, changed files, validation, open questions,
and useful possible approaches. A documented unresolved result is valid.
