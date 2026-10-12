# Agent contract

This file holds the rules every agent follows in this repository.
Role-specific procedures live in `workflow/`.

On Windows, use forward slashes in Bash command paths. Unquoted backslashes can become escapes.

## Understand your role

The assigning prompt or task defines your role. If you are not sure, ask the user or the agent that spawned you.

Reusable role documents live in `workflow/agent_roles/`. Read the ones that clearly match your role.
Workflow guides live in `workflow/docs/`. For source-cleanup work, read
`workflow/docs/source_cleanup.md`, `workflow/docs/source_comments.md`, and `workflow/docs/resource_ids.md`.

## Correctness rules

- The project is function-first and evidence-first.
- The original executable, `orig/empiresx.exe`, is the behavior oracle.
- The PDB, Ghidra output, generated inventories, and comments are reference evidence, not oracles.
- Use the VC5 toolchain from `config/toolchain.json`. `$VC5_DIR` in it comes from the
  `VC5_DIR` environment variable, defaulting to `C:\Program Files (x86)\DevStudio`.
- Baseline compiler flags come from `config/flags/default.rsp`. Use the configured
  target or translation-unit response file when one exists.
- Exactness requires positional byte equality.
- Exactness also requires the original boundary, a provable owning symbol, and known direct call or tail-jump symbol identity.

Inline assembly is forbidden for real functions unless explicitly allowed.
This includes `__asm`, `_asm`, naked functions, and handwritten wrappers.

Padding-only pseudo-functions may use byte filler when the complete body has no
behavior, memory effect, call, or real control flow. Padding status must be
reviewed and listed in `config/padding_only_functions.txt`.

## Source-recovery standard

### Approved binary dependencies

Two original binary pieces are allowed in the executable build:

- the external compression library, scoped by `config/compression_binary.json`; and
- the connected drawing assembly engine, scoped by `config/drawing_binary.json`.

Build them as hash-checked, relocatable COFF objects.
This does not extend to ordinary game functions or other assembly regions.
Do not link duplicate drawing exports or split the engine's shared mutable state.
Binary preservation is not source recovery or proof of gameplay correctness.

Decompiler output describes effects. It is not a source template. Do not keep
raw cursor arithmetic, fake helpers, fake volatility, manual vtables, redundant
aliases, or forced scheduling without binary evidence.

An unusual source form can stay only when one of these applies:

- period source or exact donors support it;
- it produces an exact result without breaking these rules; or
- binary evidence proves behavior that a simpler form loses.

Preserve original bugs, narrow widths, overlap, aliasing, evaluation order, and
fault order when the executable proves them.

## Function status

Each normal function has one status in `config/functions/`:

- `matching`: byte-identical to the original;
- `accepted_drift`: same behavior, small reviewed compiler-output differences;
- `accepted_logic`: same behavior proved by review, code differs more;
- `nonmatching`: work in progress;
- `unresolved`: source exists, but no single compiler recipe can be proved.

Exact matching and accepted drift have equal value. Choose by source and behavior
evidence, not by a preference for zero byte differences.

## Corpus and source ownership

The corpus buckets are:

- `normal`: ordinary game functions;
- `padding_only`: non-behavioral byte-preservation entries;
- `compiler_generated`: compiler-emitted functions without standalone source bodies;
- `parent_owned_fragment`: blocks owned by a larger game function;
- `toolchain_supplied`: imports, CRT code, and compiler helpers;
- `asm_special`: named handwritten assembly;
- `asm_region`: assembly, codelet, or data-dispatch neighborhoods.

Repository roles:

- `inventory/`: generated reference material (local only); do not edit it;
- `include/`: reviewed shared declarations and layouts;
- `src/game_globals.cpp`: reviewed shared global definitions;
- natural `src/*.c` and `src/*.cpp` modules: compiler-facing handwritten owners;
- `config/functions/`: source, status, build recipe, and symbol registry;
- `workflow/decomp_notes/`: durable function and module notes;
- `workflow/logic_reviews/`: semantic-review ledgers from the older workflows;
- `workflow/vc5_lessons.md`: reusable VC5 matching knowledge.

The source tree uses final, original-like modules:

- one normal `.c` or `.cpp` file owns all handwritten functions in source order;
- normal headers own shared declarations;
- one registry file under `config/functions/` owns each natural source file;
- wrapper files, function fragments, and context-selection macros are forbidden.

Every normal function must appear once in the function registry.
A buildable function must have one symbol and one module flag profile.

A VA has one compiler-facing source owner. Never keep duplicate owners across
modules or headers. Edit only that natural owner.

## Repo conduct

Keep compiler outputs and experiments under `build/`. Do not write generated
artifacts into tracked source directories.

Do not change existing line endings without a functional reason.

Markdown files define policy and workflow, not command syntax. Before you use a
repository tool, run its `--help`. Treat that output as the command reference.

## Testing

Read `workflow/docs/testing.md` before planning validation or reporting project test results.
There is no universal test command. `python -m pytest -q tests` checks the tools only.
Report which stages ran. Keep failures, skips, unknowns, and untested areas visible.

## Evidence and communication

Separate facts from hypotheses. State the source of each important conclusion.
Do not call generated metadata a behavior oracle.

Record durable conclusions in the target source, the function note, or the review ledger.
Do not rely on ignored session files as the only record.

Add a lesson to `workflow/vc5_lessons.md` only after a non-obvious pattern is supported
by exact or strong repeated evidence. Keep function-specific history out of it.

When work stops, report the result, changed files, validation, open questions,
and useful possible approaches. A documented unresolved result is valid.
