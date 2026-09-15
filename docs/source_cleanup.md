# Source-cleanup wave

Approved for the September 15 pilot. This document does not authorize additional worker launches by itself.

## Active launch contract

- Worker model: `openai-codex-secondary/gpt-5.6-luna`.
- Thinking level: `xhigh`.
- Later wave limit: ten active workers.
- Current pilot limit: one worker. Do not start the larger wave before pilot review and user direction.
- Each worker has a separate worktree and an explicit source/header assignment.
- Do not run builds, compiler checks, audits, or tests until the final validation stage.
- Evidence inspection, resource extraction, source fingerprinting, and Git diff review remain permitted preparation and review work.

## Goal

Make recovered source easier to read without changing original behavior.
Restore meaning where evidence supports it. Do not make uncertain code look more certain.
This wave must preserve generated machine code and program data, not merely observed behavior.
Preserve relocations and call targets. Debug names and line records can change.
The final comparison baseline is the pre-cleanup build, including its existing differences from the original executable.
Do not accept new generated-code differences as harmless drift.

The original executable remains the behavior oracle.
PDB records, original resources, existing declarations, and reviewed notes supply supporting evidence.
Follow the repository's source-ownership and source-recovery rules.

Read [source comments](source_comments.md) before adding comments.
Read [testing](testing.md) when planning or reporting final validation.

## Local references and restricted web use

Workers can read the installed toolchain from every worktree.
Use `config/toolchain.json` as the authority for toolchain paths.
The current include directories are:

- `C:/Program Files (x86)/DevStudio/VC/Include`
- `C:/Program Files (x86)/DevStudio/VC/MFC/Include`

The first directory includes CRT headers such as `FCNTL.H` and Windows headers such as `WINUSER.H`.
Read these definitions before replacing numeric API constants.
Use repository-local headers and original files for other dependencies when available.
Do not assume the installation contains every third-party SDK or library reference.

Web searches and queries are forbidden except for official SDK and library documentation or references.
Use that exception only for a concrete question that local references do not answer.
Limit searches to the relevant official publisher's documentation sites.
Do not search blogs, forums, answer sites, unofficial mirrors, or unrelated decompilation projects.

Record the official URL and applicable version when outside documentation supports a change.
Modern documentation can explain an API, but cannot prove its VC5-era definition or original game behavior.
Do not introduce a newer API or constant absent from the pinned headers.
If official documentation conflicts with the local version, preserve the local version and report the conflict.

## Wave model

Assign one worker to each natural source module in its own Git worktree.
Identify modules by their full registry/source path, not just a basename.
Set an active-worker limit and a disk budget before launch.
One assignment per module does not require every worktree and worker to run at once.
Each assignment must give:

- The worktree, branch, and base commit.
- The sole compiler-facing source owner.
- Any headers the worker may edit.
- The allowed cleanup scope and report location.
- Shared declarations already prepared for the wave.
- The exact model, thinking level, and worker instructions.

Workers must not launch nested agents or games.
They must not run compilers, matching tools, audits, or tests during this wave.
The user has chosen one final validation stage after integration.
Do not substitute default matching-workflow requirements for this explicit cleanup procedure.

Evidence inspection and Git diff review still occur during the work.
A worker may inspect relevant callers and shared evidence without changing those files.
Keep generated extraction results and experiments under `build/`.
Do not recursively copy original assets or build outputs into every worktree.

## Allowed cleanup

### 1. Recover original names and replace generated names

Inspect available procedure-scoped PDB records and original source evidence for every assigned function.
Compare parameter and local names with that evidence, including names that already look reasonable.
Recover supported original names wherever the current declarations can be mapped reliably.
This is required recovery work, not an optional step limited to obvious `param_*` placeholders.

Earlier recovery work can leave descriptive substitutes such as `panel` and `message` instead of original names.
For `TribeLoadSavedGameScreen::action`, the PDB establishes `fromPanel`, `actionIn`, `a1`, and `a2`.
Restore those names even though `panel` and `message` appear readable and `a1` and `a2` are terse.
Matching status does not establish original parameter or local names.

Original PDB names use mixed styles, sometimes within one function. Do not normalize them to camelCase or snake_case.
The load-screen constructor records `tabList`, `info_file`, and `from_panel` together.
`RGE_Map::get_point` records `screen_x`, `screen_y`, `x_offset`, and `y_offset`.
Preserve those spellings. Neither underscores nor terse names establish that an identifier is generated.

Match each record to its owning function, type, scope, and use; do not copy names from unrelated procedures.
Reused stack slots can make the declaration mapping uncertain. Report those cases instead of forcing a rename.
Recovering a name does not authorize copying a different buffer size, type, scope, or declaration arrangement.

Replace placeholders such as `param_1` and `local_6` when their meanings are established.
Other generated forms can include `iVar4`, `uVar2`, or `pcVar7`; the spelling alone is not proof.
Check the PDB and existing evidence before deciding that a name is generated.
A short or awkward name is not, by itself, a generated name.

Do not rename original developer names recovered from PDB records or original source.
If a placeholder has a known original name, restore that original name.
Otherwise, use a concise descriptive name supported by the function and its callers.
Use `snake_case` for parameter and local names we assign when no original name can be recovered.
This preference does not override recovered original spellings or authorize new variable declarations.
Record newly inferred names as cleanup names, not recovered original names.

Preserve scope, declarations, initialization points, types, and storage duration.
Do not combine variables because they appear to have the same purpose.
Decompiler temporaries can represent different lifetimes or register reuse.

Parameter names in an assigned declaration can follow the cleaned definition.
Do not change an unassigned shared header. Request its owner's change instead.
Do not rename public functions, classes, members, globals, or ABI symbols by preference.
Flag suspected generated shared names for coordinated review.

### 2. Add sparse practical comments

Use the separate comment guide.
Explain non-obvious behavior, important lifetimes, units, sentinels, and proven constraints.
Leave obvious code alone. Do not document every parameter or field.
Preserve original bugs. Explain them only where that explanation helps readers.

### 3. Replace unexplained values with established symbols

Search existing headers before adding a constant or enum.
Reuse an existing symbol only when its meaning and value match this use.
Numerical equality alone is not enough.

Suitable targets include:

- Panel styles and redraw modes with existing declarations.
- Windows messages and flags with verified VC5 SDK definitions.
- File-open flags and permission masks from the pinned CRT headers.
- Proven state values, sentinels, resource IDs, and format identifiers.

Keep the original value and effective type.
Check integer promotions, signedness, overload selection, and constant-expression requirements through source evidence.
Do not change enum storage, structure layout, calling conventions, or public signatures.

A macro, enum value, and typed constant are not interchangeable in every C++ expression.
Use a form supported by the pinned VC5 toolchain and the surrounding code.
Do not introduce `constexpr`, scoped enums, or modern language features.

Prefer the narrowest useful scope:

- Reuse an existing class or module declaration.
- Use a local name for a genuinely local meaning.
- Request a shared declaration when several modules need the same meaning.

Do not create a giant header of unrelated numbers.
Do not create names such as `VALUE_8309` or `UNKNOWN_FLAG_7` merely to hide literals.
Leave unknown values visible and report the unresolved meaning.

### 4. Make language and resource IDs readable

Use [resource ID guidance](resource_ids.md) for local string lookup and naming conventions.

Keep resource lookup calls. Do not replace them with English text.
Preserve localization, formatting tokens, hotkey characters, fallback behavior, buffer sizes, and lookup order.

Inspect the pinned original resource module and its call site before naming an ID.
Record the resource module, numeric ID, language, payload, and proposed meaning in the evidence report.
Record missing or empty payloads explicitly; do not require recovered text to name a proven role.
Trace the argument, lookup path, and relevant callers before declaring an ID's purpose unknown.
When that evidence establishes the resource type and purpose, use a descriptive name even if the text is unavailable.
Keep unknown text separate from unknown purpose. Do not invent either.
An ID belongs to a resource namespace. The same number in another DLL need not mean the same thing.

Reuse a proven original resource symbol when available.
When the original macro name is unavailable, a descriptive name can improve readability.
Mark it as a new cleanup name; do not claim that it came from the original developers.
PDB records generally do not recover preprocessor macro names.

A name such as `IDS_VIEW_TOWN_CENTER_HOTKEY` is a possible cleanup convention, not an established original symbol.
The value and resource meaning still need verification before use.
Do not blindly use string contents as identifier names.

Preserve contiguous ranges and arithmetic lookups.
For `base_id + index`, establish the whole range before naming the base.
Do not expand such lookups into new switches or tables merely for appearance.
Keep data-driven fields such as `master->string_id` data-driven.

Assign one owner to shared resource-ID declarations.
Prepare an agreed mapping before the wave where practical. Workers request additions instead of defining competing shared names.
A declaration can serve a single resource domain; it need not collect unrelated game constants.

### 5. Choose useful literal notation

Hex remains useful for masks, packed values, addresses, and binary-format fields.
Decimal can make a count or original debug line number easier to read.
Do not convert every literal to one notation.

Preserve integer suffixes, widths, and signedness.
A decimal spelling can have a different type from the same hexadecimal value.
Do not round floating-point literals, change `f` suffixes, or replace exact bit patterns with approximate decimals.
Do not replace original debug line values with the current source line number.

Prefer a verified SDK symbol or format constant over an opaque FourCC number when the form preserves its meaning.
Do not introduce implementation-dependent multi-character literals as a shortcut.

### 6. Make local presentation clearer

Workers may freely adjust indentation, spacing, blank lines, wrapping, and brace placement throughout their assigned files.
Formatting does not require a nearby name change or evidence that the old style obstructs reading.
Use consistent indentation, preserve line endings, and follow the brace and wrapping rules below.
Do not reformat unassigned files or reorder source declarations or statements.

Allow moderately long lines. Do not wrap declarations or calls merely to meet an 80-column limit.
Keep short parameter lists on one line when they remain easy to read, including this declaration:

```cpp
virtual long action(TPanel* fromPanel, long actionIn, unsigned long a1, unsigned long a2);
```

The same rule applies to definitions. Keep this signature and its opening brace on one line:

```cpp
long TribeLoadSavedGameScreen::action(TPanel* fromPanel, long actionIn, unsigned long a1, unsigned long a2) {
```

Do not put each short parameter on a separate line.
Use **1TBS (One True Brace Style)**: opening braces share the line with function definitions, classes, structures, and control statements.
Use `} else {` and `} catch (...) {` when applicable.
Workers may move existing opening braces onto those lines throughout their assigned files.
Change brace placement only; do not add or remove braces, change scopes, or move statements.

Wrap when it improves readability, not just because a line crosses a fixed column count.
Join unnecessarily wrapped short declarations, calls, and expressions when the result remains easy to read.
These formatting changes are allowed even when the lines need no name or constant changes.
A module-wide formatting pass is allowed within the assigned files.
Preserve tokens, comments, preprocessor boundaries, and executable structure.
Do not change macro continuations, string contents, or the meaning of line comments through formatting.
Check for line-dependent macros such as `__LINE__`; formatting must still preserve generated code and program data.

Group or explain related code only without moving executable statements or changing declaration scope.
Preserve source order and the sole natural source owner.
Do not split functions into helper wrappers or create function fragments.

## Structural rewrites are outside this wave

Do not perform speculative structural cleanup while all executable checks are deferred.
An ugly expression is not evidence that it has no purpose.
For example, a narrowing cast can preserve truncation, and repeated reads can observe writes through another pointer.

Leave structural rewrite candidates unchanged and report them for separate work.
Even a behavior-equivalent rewrite can change compiler output.
Do not infer a new layout merely to remove pointer arithmetic.
The following changes are outside this naming, comments, and symbolic-constant wave:

- Replacing raw offset access with a newly inferred member layout.
- Removing casts, temporaries, duplicate-looking loads, or apparently dead code.
- Changing loops, switches, evaluation order, or short-circuit expressions.
- Replacing explicit lengths with `sizeof` without proving the original contract.
- Changing buffer allocation, ownership, lifetime, or string APIs.
- Replacing arrays with containers or extracting new helpers.
- Correcting original bugs or changing error handling.

Do not remove an unusual source form merely because it resembles decompiler output.
The repository requires evidence for retaining such forms, but removing them also needs a supported behavior argument.
Report suspected violations rather than silently changing their behavior in a naming pass.

Do not edit generated inventory, build recipes, function status, runtime assets, or validation expectations to make cleanup pass.
Do not change approved original binary dependencies or add inline assembly.

## Examples observed in the current tree

These are cleanup candidates, not completed semantic identifications:

- `src/world.cpp` contains `param_*`, `local_6`, and `rge_open` masks such as `0x8000` and `0x8309`.
- `src/tribegam.cpp` passes packed numeric codec identifiers to `ICInfo`.
- `src/scr_game.cpp` uses string IDs such as `0x103f` and the range `i + 0x1040` for hotkeys.
- `src/basegame.cpp` uses a shared `g_string_buffer` in `get_string(long)`.
- `src/tpnl_tml.cpp` has long placeholder parameter lists and casts that need different levels of caution.
- Existing headers already define panel, button, game-option, and communication enums.

Verify each use. Do not assume a known constant explains every occurrence of the same number.

## Shared-file ownership

Each tracked file needs one editing owner during the wave.
A source module's worker does not automatically own every header it includes.
Header ownership must be explicit, even when the header has a similar name.

A worker can own a TU together with one or more headers.
Do not run cleanup workers for dependent TUs while that worker changes their shared header.
Account for transitive includes, not only direct includes.
If a worker discovers an unplanned shared-header change, stop that change and ask the orchestrator to adjust assignments.

Review and integrate the header owner's full change before launching the dependent workers.
Create their worktrees from the updated integration commit so they see the agreed declarations.
This scheduling rule avoids collisions without requiring a separate worker for every header.

Workers must not edit another worktree or the main integration tree.
Read shared original evidence without modifying it.
Send cross-module requests with the required declaration, evidence, and affected call sites.
The orchestrator routes them to the assigned owner.

Do not resolve header conflicts by creating duplicate local types or alternative layouts.
Do not silently overwrite another worker's changes during integration.

## Worker delivery

Review the complete diff before reporting completion.
Copy base and final commit hashes directly from Git output. Do not reconstruct or abbreviate the required full hashes.
Commit only assigned changes and the assigned durable report.
Use small coherent commits if several cleanup categories are involved.
Do not squash unrelated module work together.

The report must include:

1. Module path, base commit, final commit, and every changed file.
2. Original-name recovery coverage, renamed parameters and locals, supporting evidence, and unresolved declaration mappings.
3. Evidence for new constants, resource IDs, and noteworthy comments.
4. Which names are recovered originals and which are new descriptive names.
5. Any change that could affect types, code generation, layout, or symbol identity.
6. Shared-file requests and unresolved questions.
7. An explicit statement: compilation, matching, audits, and tests were not run.

Do not claim byte equality, semantic approval, or successful validation from visual review alone.
A valid result can leave uncertain code unchanged, or make no source changes.
Do not manufacture edits to justify an assignment.

## Orchestrator review and integration

Inspect each worker's full Git diff against its assigned base and read its report.
Check scope, evidence, original-name preservation, constant types, comment density, and shared-file ownership.

Resume the same worker for corrections when its context remains useful.
Inspect the new diff after each correction. Do not accept the report without inspecting the code.

Integrate the full approved module changes as an identifiable commit or commit sequence.
Do not silently omit reported edits through partial hunk selection.
If a change is not acceptable, return it for correction before integration.
If shared changes conflict, coordinate a resolution with their owner and review it again.

Keep a module-to-commit ledger. Mark integrated work as unvalidated until the final stage passes.
Keep the pre-wave base and module commits so failures can be traced or reversed without losing other modules.

## Final validation

After all module work and integration finish, run the applicable stages in [testing](testing.md).
This includes source/registry checks, function matching and ownership, a fresh build, linked audits, automated tests, menus, and gameplay.
Record the selected executable and each result separately.
Also compare generated code, program data, relocations, and call targets against the preserved pre-cleanup build.
Separate debug metadata and build timestamps from executable content; raw whole-file hashes alone cannot make that distinction.
Existing original-versus-rebuilt mismatches must not conceal changes introduced by this wave.

Investigate every new compile error, matching regression, or runtime difference.
Do not relabel a mismatch or weaken a test to finish the cleanup.
Use the module ledger to send precise corrections to the relevant worker.
Rerun affected validation after corrections and report any stages not repeated.

Deferring checks saves repeated work, but can produce a larger final repair queue.
A reviewed merge is not a validated result. The wave ends only after its final results and remaining limits are recorded.
