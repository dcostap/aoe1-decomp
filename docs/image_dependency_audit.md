# Static image dependency audit

This tool checks EXE files without running the game.
It checks referenced numeric values, known reference targets, and reviewed initial storage.

```text
python tools/audit_image_dependencies.py --help
python tools/audit_image_dependencies.py --build build/executable/RUN --output build/dependency-audit/RUN
```

The output directory must be new and under `build/`.
The tool checks the pinned original hash and the build's recorded EXE, map, object, and linker-log hashes.
Historical builds are permitted. Independent original symbols select linked functions, not current registry recipes.

## Results

- `pass`: the specific value or target check agrees.
- `fail`: the specific value or target check differs.
- `unknown`: the tool cannot prove the comparison.

`checks.csv` contains every check. `failures.csv` lists differences for review.
`summary.json` records input hashes, counts, and limits. `report.md` gives a short result.
`emissions.json` records linked emission evidence. `tables.csv` separates table checks and unknown table layouts.
Instruction offsets and operand sizes use decimal bytes. Addresses and stored bytes use hexadecimal.
Floating values supplement the exact stored bytes. They do not replace byte comparison.

The command returns one when a check fails. It returns zero when no supported check fails.
Unknown checks do not establish complete correctness, even with a zero exit code.
Invalid inputs stop the command without a completed report.

## Scope

The tool considers every function in the original function inventory.
The map must select one compiled object and function symbol.
The selected COFF span ends at the next function symbol or section end.
The tool checks linked bytes and resolves supported object relocations.
Unknown relocation destinations remain explicit. Their fields do not contribute byte-equality evidence.
Such emissions receive `bounded_emitted_span`, not `proved_emitted_span`.
Folded functions and unsupported owners remain unknown.
An emission can contain padding and local tables. Its end is not automatically the logical code end.

The comparison window must fit that emission.
Dependencies require aligned instruction windows after supported address-field removal.
Each removed reference still receives a target check. Unknown targets remain unknown.

Automatic literal checks cover absolute x87 floating reads from stored, read-only, non-code sections.
They compare the actual bytes at both operand addresses.
Other operand types need evidence that distinguishes numeric data from pointers.
Runtime-dependent addresses, including object fields, remain unknown.

The reviewed storage audit checks global initial bytes and explicit pointer fields.
This includes the version global, the group-property array, and the reviewed unit-AI virtual table.
It also checks 75 previously recovered strings, including terminating zero bytes.
The string loader checks recorded evidence against the original bytes before using each range.

The switch check supports adjacent `cmp index, maximum`, unsigned `ja`, and indexed `jmp` instructions.
It compares every target in the guarded table slice.
Targets must identify aligned instruction starts or independently named functions.
Other switch forms remain unknown. This does not prove every table entry or every route into the dispatch.
Unreviewed linked virtual tables receive explicit unknown results. Their sizes are not guessed.

Equal operand bytes do not prove shared storage identity or later runtime values.
Unaligned functions need separate instruction and behavior review.
This tool cannot diagnose the civilization field-selection bug automatically.
The checks do not replace gameplay replay.

## Normal function validation

`check_function.py` now reports instruction and numeric-dependency results separately.
It reads numeric values from the complete compiled object, not just the extracted instruction bytes.
A proved numeric difference changes the final result to `MISMATCH` and the command returns one.
Unknown dependencies remain visible. A local `MATCH` still does not prove linked globals or table contents.

Grouped translation-unit validation uses the same object-local check.
It preserves dependency details and rejects claimed exact functions with proved numeric differences.
The validation fingerprint includes the new checks, so old exact reports need fresh validation.

## Regression checks

`tests/test_image_dependencies.py` tests wrong literals, moved equal literals, changed calls, and wrong global initial values.
It also rejects writable literals, untyped loads, relocation content, and unaligned field accesses.

Two optional tests use hash-pinned preserved builds.
They check the historical minimap, map-point, and clearance constant defects.
The old build has nine failed reads across four functions. The repaired build removes those nine failures.
The tests skip these two cases if their local build files are unavailable.

`tests/test_image_dependency_repairs.py` checks the original numeric bytes and both repaired switch mappings.
Set `AOE_DEPENDENCY_BUILD` to a fresh build directory to check its linked data too.

```text
AOE_DEPENDENCY_BUILD=build/executable/RUN python -m pytest -q tests/test_image_dependency_repairs.py
```

This Bash command checks all eight constant reads, both case maps, and the nine historical numeric reads.
The case tests read actual tables and resolve direct drawing helpers independently.
They retain the unsigned guards, no-effect cases, and separate game-mode-one branch.
An absent or unaligned supported check cannot pass these tests.
The tests do not execute the game or prove rendering parity.
