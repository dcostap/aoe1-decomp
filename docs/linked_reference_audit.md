# Linked-reference audit

## Purpose

Run `tools/audit_linked_references.py` after linking.
It checks actual EXE references against one shared owner map.
It does not use the function checker's per-function address substitutions.
It never edits game source, registry status, or the original executable.

## Run

```sh
python tools/audit_linked_references.py --help
python tools/audit_linked_references.py --build build/executable/20260907T011421160623Z --output build/linked_references/current.json
python tests/test_linked_references.py
```

The build directory must contain `empiresx.exe` and `empiresx.map` from the same build.
Reports must stay under `build/`.
Exit zero means no supported check failed. It does not mean complete coverage.
Exit one means at least one reference failed. Input errors also stop the command.

## Small model

The function registry supplies original entry addresses and reconstructed symbols.
The linker map supplies actual reconstructed addresses.
Reviewed data ranges live in `config/linked_reference_owners.json`.
Each range has an original start, size, reconstructed symbol, and evidence.
The rebuilt field address must equal the rebuilt owner address plus the original field offset.
Overlapping reviewed ranges produce unknown results rather than an arbitrary choice.

The first data range is the streaming RIFF structure. It directly tests the demonstrated storage defect.
This is deliberately not a complete data inventory.
Add ranges only after reviewing ownership and size. Do not derive them from the references being tested.
Do not use proximity, names alone, or previously accepted relocation substitutions as ownership proof.
A reviewed range is an audit assumption. Incorrect range evidence can still produce incorrect conclusions.

## Code alignment

The audit decodes the original function's recorded byte window and an equally sized rebuilt window.
It removes address fields from temporary comparison signatures, not from the reference checks.
All remaining bytes and reference positions must agree before the audit pairs references.
Otherwise the function reports unknown.

Supported references are direct external calls and jumps, absolute memory operands, and PE HIGHLOW address fields.
Absolute memory operands also work in fixed-base executables without PE relocation tables.
The audit does not treat an ordinary integer immediate as a pointer merely because it resembles an address.
Internal branches must retain their displacement bytes for the code windows to align.

This conservative alignment skips much nonmatching code. It does not generate failures simply because code differs.
The code window is not a proof of the rebuilt function boundary or whole-function equivalence.
Use the existing function checker for those separate checks.

## Results

- **Pass:** a paired reference reaches the mapped function or reviewed object offset.
- **Fail:** a paired reference reaches a different location.
- **Unknown:** code does not align, an owner is missing or ambiguous, or no supported reference exists.

JSON rows identify the function, reference offset, original target, rebuilt target, and expected owner where known.
Offsets identify the encoded address field relative to function entry.
Counts summarize report rows, not functions: reference rows and skipped-function rows are distinct.
The report includes executable, linker-map, function-map, and data-owner hashes.
Keep the build artifacts with the report when investigating a result.

## Workflow

1. Run the normal function and affected-module checks.
2. Build the executable.
3. Run this audit against that build.
4. Review new failures before integration.
5. Compare unknown coverage with the previous report. A failure disappearing into unknown is not a repair.
6. Run the executable and relevant regression tests.
7. Record reviewed findings and test results in versioned notes.

Existing failures remain visible. Do not silently approve or suppress them as baseline noise.
Do not change registry status automatically from this report.
Keep code matching, linked-reference checks, and runtime results separate.
Run `audit_global_initializers.py` separately for its supported initial-data checks.

## Limits

This version does not check computed addresses, virtual dispatch, complete pointer tables, or all initial data.
It cannot prove that file loading ran, that an object is valid, or that gameplay is correct.
Unknown functions and unknown data owners are explicit coverage gaps.
Function addresses come from current registry evidence; historical builds need compatible symbols and ownership.
Function-local statics and overlapping storage require reviewed owner evidence before adding ranges.

## Dogfood results

The audit ran on two existing linked builds. No game rebuild was needed for this tooling-only change.

- Broken streaming build: `20260907T005349864457Z`.
  Results: 4727 pass rows, 6178 unknown rows, two fail rows.
- Repaired build: `20260907T011421160623Z`.
  Results: 4728 pass rows, 6178 unknown rows, one fail row.

In the broken build, `00448B30` reads `005F9194` at encoded offset 26.
The reviewed RIFF member belongs at `005F915C`. The audit reports fail.
The repaired build reads `005F915C` and passes that check.
The function is not special-cased in the audit.

Both builds also fail the call check in `004C9710`, `TRIBE_Building_Object::copy_obj`, at encoded offset 40.
Original target `00430810` maps to `RGE_Combat_Object::copy_obj` at rebuilt `0042B430`.
The actual linked call reaches `004067D0`, `RGE_Action_Object::copy_obj`.
The source in `src/t_b_obj.cpp` also names the action-object method.
The registry currently labels the caller matching. This finding needs a separate source and behavior review.
No game source or status was changed by this audit task.

Reports: `build/linked_references/current.json` and `build/linked_references/broken_stream.json`.
Seven unit tests cover field offsets, split storage, unknown ranges, overlapping owners, and conservative code alignment.

### Building-copy repair

The later source repair restores the combat-object call in `004C9710`.
Build `20260907T014211022735Z` reports 4729 pass rows, 6178 unknown rows, and zero failures.
The formerly failing reference now passes. Unknown coverage is unchanged.
Report: `build/linked_references/building_copy_fixed.json`.
See `decomp_notes/functions/004C/004C9710.md` for source evidence and validation.
