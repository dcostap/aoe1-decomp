# Independent review: 0047F5C0

- Workflow: matching with reviewers
- Reviewer run: `sa-89097f7d-r1`
- Worker run: `sa-aaf50b3f` (durable worker label: `luna-46-Res_file`)
- Worktree: `C:/Projects/my_decomps/aoe1_reviewer_refill_51`
- Branch: `reviewer-refill-51`
- Base: `8620a2ebb85246f78ad888d4ffef3d159dfc59eb`
- Scope: `src/Res_file.cpp`, `0047F5C0 RESFILE_build_res_file`

## Reviewed inputs

- State: `ac8f245faf9a177874649096db0ff15858f7895f83ed5018bbc06087383efcc5`
- State name: `at8620a2ebb-0047F5C0-baseline`
- Run event: `47eb5f52eff8b5ac540435386ebf645b6ee3060455e3e4d063c70e2ba3c5bb0f`
- Finding event: `9898d27ca4ac2135be1c6f80b23600affb87a066f75374754fc37318e93d5604`
- Compiler-input fingerprint: `b220dff87953797b0a26521f2b12f99f776582ccb3d8b6319160417988a364d6`
- State source hash: `98f9c9d0e34e866f5b031e31961e7c47d6d3e7dc725e1a3b9112ec7a928057b3`
- Current source hash: `98f9c9d0e34e866f5b031e31961e7c47d6d3e7dc725e1a3b9112ec7a928057b3`

## Behavior

The authoritative check reports the target as `MISMATCH`. It reports 35/35 ordered calls, zero call-site replacement or target-count differences, and 8/8 returns. The rebuilt control flow has 15 jumps versus 16 in the original. No runtime harness exists in this package, so malformed-input, failure-path, fault-order, and full semantic equivalence claims remain untested.

The source follows the original resource-list build and cleanup shape. Binary evidence in the target packet supports the three `char*` parameters, the PDB-named record types, and the call order. This is behavior support for retention, not an accepted-drift proof.

## Source

The state manifest covers `src/Res_file.cpp`, its header and shared headers, flags, registry, and toolchain. All recorded hashes match the current files. `git diff` is empty for the source, headers, flags, registry, and inventory scope. The current body is natural C++ and has no inline assembly, raw stack overlay, fake volatility, or wrapper owner.

The scoped PDB record for `0047F5C0` proves the owner, `__cdecl` type, three parameter homes, and named local types. Some PDB locals share stack homes by scope. This supports the existing declarations but does not prove a source declaration order that fixes the remaining code generation.

Source integration: **APPROVE retention with no source change**. No source promotion is proposed.

## Bytes

Fresh recorded check and independent cached-artifact check agree:

- Original/rebuilt size: `1669/1669`
- Frame: `0x4A4/0x4A4`
- Instructions: `554/554`
- Strict positional diff: `644` bytes, `38.5860%`, 49 spans
- Shape: `93.86%`
- Exact-block coverage: `63.18%`
- Owner symbol: match, `?RESFILE_build_res_file@@YAHPAD00@Z`
- Boundary: target boundary valid; grouped `boundary_escape_count=0`
- Relocations: 48/68 safely masked; grouped relocation target mismatches: 0

No exact proposal is approved because the result is `MISMATCH`, not `MATCH` with `0.0000%`. No accepted-drift proposal is made.

## Integration

Experiment preservation: **APPROVE**. Preserve state `ac8f245faf9a177874649096db0ff15858f7895f83ed5018bbc06087383efcc5`, both worker events, and their referenced objects. The finding event records the clean natural source and the target result.

Status decision: **APPROVE retaining `scratch`**. Do not promote `0047F5C0` to `matching`, `accepted_drift`, or `verified_logic`.

The grouped `res_file` audit covers all nine configured owners. It reports six matching neighbors, target `0047F5C0` at diff 644 with owner match and no boundary escape, pre-existing `0047EE90` boundary problem, and pre-existing `0047F320` one-byte mismatch. No changed source owner exists. The six exact neighbors are `0047F180`, `0047F230`, `0047F480`, `0047F580`, `0047F590`, and `0047FC50`.

Validation:

- `python tools/check_function.py --va 0047F5C0 --no-build --detail full --call-map --block-map --stack-map`
- `python tools/audit_translation_unit_functions.py --group Res_file --jobs 1 --output-dir build/audits/workers/at8620a2ebb/Res_file`
- `python tools/query_project_status.py --va 0047F5C0 --paths --notes --triage`
- `python tools/experiment_history.py show --va 0047F5C0`
- `python tools/experiment_history.py inspect at8620a2ebb-0047F5C0-baseline`

Durable evidence:

- `workflow/decomp_notes/experiments/states/ac8f245faf9a177874649096db0ff15858f7895f83ed5018bbc06087383efcc5.json`
- `workflow/decomp_notes/experiments/events/47eb5f52eff8b5ac540435386ebf645b6ee3060455e3e4d063c70e2ba3c5bb0f.json`
- `workflow/decomp_notes/experiments/events/9898d27ca4ac2135be1c6f80b23600affb87a066f75374754fc37318e93d5604.json`
- `workflow/decomp_notes/experiments/objects/c7/c7bf485f0ac885f8fd60c5c18828b075fa26c24e173a6a48b9dbc052e9601aa3`
- `build/diff/0047F5C0_RESFILE_build_res_file.txt`
- `build/audits/workers/at8620a2ebb/Res_file/report.txt`
- `inventory/functions/0047/0047F5C0_RESFILE_build_res_file.txt`
- `inventory/pdb/scoped_symbols.json`
- `workflow/decomp_notes/functions/0047/0047F5C0.md`
- `workflow/decomp_notes/res_file.md`

Untouched scratch functions in this review: none in scope. The grouped audit also observed `0047EE90` and `0047F320`, but this review did not modify or promote them.
