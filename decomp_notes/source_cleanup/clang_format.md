# C/C++ formatting

## Scope

Base commit: `3905fc41003bd86af5e984387e54d23318acf910`.

The pass selected 483 C/C++ files: 226 files in `src/` and 257 headers in `include/`.
Formatting changed 468 files. The other 15 files remained unchanged.
The root `.clang-format` stores the accepted settings.
No registry, compiler recipe, inventory, assembly source, original file, or runtime asset changed.

The user requested SM64's formatter settings, then selected these changes:

- Use 120 columns.
- Put pointer stars next to the type.
- Put wrapped arguments between separate opening and closing lines.
- Align consecutive macro definitions.
- Keep return types with function names when parameters wrap.

The starting configuration came from:
`https://github.com/n64decomp/sm64/blob/master/.clang-format`.
The installed formatter is clang-format 21.1.8.
Unspecified settings use that version's defaults.

The configuration also preserves VC5 syntax, declaration order, comment text, string literals, and macro bodies.
It uses C++03 syntax and disables using-declaration sorting, comment reflow, string splitting, and automatic namespace comments.
These restrictions prevent source changes outside the formatting assignment.

The follow-up sets `PenaltyReturnTypeOnItsOwnLine: 1000`.
This keeps a function's return type with its name when the complete declaration exceeds 120 columns.
The rule changed 47 files in the second formatting pass.

The constructor setting is `BreakConstructorInitializers: AfterColon`.
When parameters wrap, this keeps `) : Base(...)` together on the signature's closing line.
The final pass changed 98 files. All 98 were already part of the original 468 changed files.

## Protected assembly region

The unbraced `__asm int 3` statement in `src/Res_file.cpp` needs its physical instruction boundary.
The first candidate joined the following `MessageBoxA` call onto the assembly line.
A C++ token comparison alone did not detect this assembly-language change.
That candidate was not applied.

Two `clang-format off/on` comments protect the instruction and following call.
The original statements, instruction, scope, and fault order remain unchanged.
A separate check compares the assembly line and the following statement before and after formatting.
No new assembly instruction or wrapper was added.

## Preparation checks

The preparation saved source snapshots under `build/clang-format-120/before/`.
It stored formatted candidates under `build/clang-format-120/after/`.
The source remained unchanged until every candidate passed the guards.

All 483 files passed these checks:

- Equal preprocessing-token sequence after line splicing.
- Equal comment text and order, except the two reviewed assembly markers.
- Equal directive boundaries and function-like macro classification.
- Equal line-splice count and line-ending style.
- Equal assembly instruction boundaries.
- Unchanged source hashes during preparation.

The lexical checks are not a complete C++ semantic parser.
The compiler and object checks supply separate evidence.
The application required the recorded source and candidate hashes before it copied any formatted file.
The applied sources and configuration matched the prepared output.

The return-type adjustment was prepared and applied separately under `build/clang-format-120-adjust/`.
Its pass changed 47 files. It passed the same token, comment, directive, line-ending, assembly-boundary, and source-hash guards.

The user clarified that the colon and base type belong on the signature's closing line.
The final `AfterColon` setting was prepared and applied under `build/clang-format-120-signature-colon/`.
Its pass changed 98 files and passed the same guards.

Preparation report: `build/clang-format-120/manifest.json`.
Guarded formatter script: `build/clang-format-120/format_tree.py`.

## Validation

Reports: `build/validation/clang-format-120/`.

Both fresh compiler sweeps compiled all 225 configured modules and passed all 5013 exact claims.
Both sides also compiled the integration-only `src/game_globals.cpp` with its configured `default` profile.
All 226 C/C++ objects have equal non-debug content before and after formatting.
The comparison checks section bytes, sizes, flags, relocations, targets, and allocated symbol identities.
It excludes debug sections and timestamps. It normalizes private serial labels while retaining their sections and offsets.
It does not normalize external symbol names or ignore code and data bytes.

The post-format ownership audit verified all 5013 exact owners.
It found zero duplicate owners, owner mismatches, class/free mismatches, and repair items.
The source/registry check passed. `git diff --check` passed.
All 225 final input fingerprints and object hashes match the fresh compiler report.
The global-definition probe also checked its input fingerprint before and after compilation.
The applied-source guard confirms all 483 files still match the reviewed output.

The unchanged nonexact categories remain visible:
217 behavior-recovery observations, 140 accepted-drift observations, 44 grouped mismatches, and 12 boundary problems.
This pass adds no generated-code or program-data difference.

Commands:

```text
python -B tools/audit_translation_unit_functions.py --jobs 4 --output-dir build/validation/clang-format-120/before/functions
python -B build/clang-format-120/compile_globals.py --stage before
python -B tools/audit_translation_unit_functions.py --jobs 4 --output-dir build/validation/clang-format-120/after/functions
python -B build/clang-format-120/compile_globals.py --stage after
python -B build/object-state-cleanup/compare_objects.py --before build/validation/clang-format-120/before/functions/objects --after build/validation/clang-format-120/after/functions/objects --output build/validation/clang-format-120/object-comparison.json
python -B tools/audit_matching_owners.py --function-report build/validation/clang-format-120/after/functions/report.json --output build/validation/clang-format-120/owners.json --text-output build/validation/clang-format-120/owners.txt
python -B tools/validate_translation_units.py --no-build-checks
python -B build/game-setting-cleanup/check_final_inputs.py --report build/validation/clang-format-120/after/functions/report.json --output build/validation/clang-format-120/current-inputs.json
python -B build/clang-format-120/format_tree.py --check
git diff --check
```

After the return-type adjustment, the full compiler audit ran again to `build/validation/clang-format-120/final/functions/`.
The final signature-colon adjustment then changed formatting in 98 files.
After that final change, all 225 configured modules compiled and passed all 5013 exact claims again.
The final owner audit verified all 5013 owners, with zero mismatches and zero repair items.
All 225 final input fingerprints and object hashes match their report.
The integration-only global source compiled with the `default` profile.
The 226-object comparison report is `build/validation/clang-format-120/final-object-comparison.json`.
It reports zero content, relocation, and symbol differences.

No linked-image build or audit, automated test suite, menu suite, or gameplay suite ran.
This result proves unchanged compiled object content, not complete game correctness.

No commit has been created for this formatting pass.
