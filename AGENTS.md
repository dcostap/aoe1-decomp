# Repository-wide agent contract

Pi runs shell commands through Bash. Use forward slashes in Bash command paths.
Unquoted Windows backslashes can become escapes.

This file contains universal rules. Keep role-specific procedures in workflow documents.
## Understand your role

The assigning prompt or assigned task(s) define your role and instructions. If not sure, ask the user or the agent that spawned you.

There are extra reusable documents that contain specific instructions. Read the documents if clearly related to your role. They are in `agent_roles`.

## Universal correctness rules

- The project is function-first and evidence-first.
- The original executable is the behavior oracle.
- PDB, Ghidra, generated inventories, and comments are reference evidence.
- Use the repo-local original files under
  `orig\original_full_game_files_rise_of_romes_beta_17_7_1998`.
- Use the pinned VC5 host toolchain from `config\toolchain.json`.
- Baseline compiler flags come from `config\flags\default.rsp`. Use the configured
  target or translation-unit response file when one exists.
- Exactness requires positional byte equality.
- Exactness also requires the original boundary, provable owning symbol, and known direct call or tail-jump symbol identity.

Inline assembly is forbidden for real functions unless explicitly allowed.
This includes `__asm`, `_asm`, naked functions, and handwritten wrappers.

Padding-only pseudo-functions may use byte filler when the complete body has no
behavior, memory effect, call, or real control flow. Padding status must be
reviewed and listed in `config\padding_only_functions.txt`.

## Source-recovery standard

### Approved binary dependencies

The user permits two original binary dependencies for executable integration:

- the external compression library, scoped by `config/compression_binary.json`; and
- the connected drawing assembly engine, scoped by `config/drawing_binary.json`.

Build these dependencies as hash-checked, relocatable COFF objects.
This permission does not extend to ordinary game functions or other assembly regions.
Retain recovered drawing assembly and its probes for future source recovery.
Do not link duplicate drawing exports or split the engine's shared mutable state.
Binary preservation is not complete source recovery or proof of gameplay correctness.

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

Repository source roles are:

- `inventory\`: generated reference material; do not edit it;
- `include\`: reviewed shared declarations and layouts;
- `src\game_globals.cpp`: reviewed shared global definitions;
- natural `src\*.c` and `src\*.cpp` modules: compiler-facing handwritten owners;
- `config\functions\`: source, status, build recipe, and symbol registry;
- `decomp_notes\`: durable function and module notes;
- `logic_reviews\`: versioned semantic-review ledgers;
- `LESSONS.md`: reusable VC5 matching knowledge.

The source tree uses final, original-like modules:

- one normal `.c` or `.cpp` file owns all handwritten functions in source order;
- normal headers own shared declarations;
- one registry file under `config/functions/` owns each natural source file;
- wrapper files, function fragments, and context-selection macros are forbidden.

`unresolved` means source exists, but one compiler recipe cannot be proved.
Header-owned functions and PDB modules without procedure records can use it.

Every normal function must appear once in the function registry.
A buildable function must have one symbol and one module flag profile.

A VA has one compiler-facing source owner. Never keep duplicate owners across
modules or headers. Edit only that natural owner.

Exact matching and accepted drift have equal value. Choose by source and behavior
evidence, not by a preference for zero byte differences.

## Repo conduct

Keep compiler outputs and experiments under `build\`. Do not write generated
artifacts into tracked source directories.

Do not change existing line endings without a functional reason.

Markdown files define policy and workflow, not command syntax. Before you use a
repository tool, run its `--help`. Treat that output as the command reference.

Use the harness `everything_search` tool for recursive path discovery. Use `rg`
for file content searches. Do not recursively enumerate the repository with
`find` when Everything can answer the query.

## Evidence and communication

Separate facts from hypotheses. State the source of each important conclusion.
Do not call generated metadata a behavior oracle.

Record durable target conclusions in the target source or its assigned ledger.
Do not rely on ignored session files as the only record.

Add a reusable lesson only after a non-obvious pattern is supported by exact or
strong repeated evidence. Keep function-specific history out of `LESSONS.md`.

When work stops, report the result, changed files, validation, open questions,
and useful possible approaches. A documented unresolved result is valid.
