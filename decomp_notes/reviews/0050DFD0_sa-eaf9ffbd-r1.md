# Independent review: `0050DFD0` `sub`

- Workflow: matching with reviewers
- Reviewer: `sa-eaf9ffbd-r1`
- Worker: `sa-c2478cc8-r1-0050DFD0`
- Worktree: `C:/Projects/my_decomps/aoe1_queue_slot_3`
- Branch: `queue-slot-3`
- Base: `83453ed667838e626e6919dcbb763b0061c0162e`
- Translation unit: `src/Timeline.cpp` (`timeline`)
- Scope: baseline and direct-member-guard probe; no source change

## Disposition

- **Source integration: APPROVE no source change.** Keep the restored natural source.
- **Status: APPROVE no status change.** Keep `0050DFD0` in `scratch`.
- **Probe preservation: APPROVE.** Preserve the baseline and direct-member-guard states.
- **Exact or accepted-drift proposal: NONE.** The target remains a broad mismatch.
- **Review verdict: APPROVE evidence-only handoff.**

## Behavior

The original body is `0050DFD0-0050E033` and uses `__thiscall`.
The original reads `this->time_list` at `+0x8`.
It follows `RGE_Time_Entry::next` at `+0x2c`.
It compares each node with the `entry` parameter.

A null list returns without side effects.
A missing entry returns after the full `next` walk.
A found entry is unlinked through the predecessor link.
The unlink reads `p->next` before it stores the predecessor link.

For command `1`, the body scans the post-unlink list to null.
It passes that null result to the recursive `sub` call.
For other commands, it passes the original `entry` parameter.
The recursive call occurs before `free(p)`.
The count decrement occurs after `free(p)`.
The count write is a 16-bit decrement at `this+0xc`.

The restored source expresses these effects with typed `p`, `link`, and `temp2` locals.
Its loop and inner null return match the original control flow.
It does not use a fake helper, address, volatile read, or wrapper.

The source gives no runtime harness evidence for malformed lists, cycles, allocator faults,
exceptions, concurrent mutation, or unusual aliasing. Those paths remain untested.
The assembly proves the relevant memory and call order for the normal linked-list model.

## Source

The PDB and inventory agree on the owner and source span:

- PDB source: `Timeline.cpp`, lines `499-530`.
- Owner: `RGE_Timeline::sub`.
- `this`: `RGE_Timeline*` in `ecx`.
- `entry`: `RGE_Time_Entry*` at stack `+0x4`.
- `temp2`: `RGE_Time_Entry*` at stack `+0x8`.
- `next`: field offset `+0x2c`.
- `time_list`: field offset `+0x8`.

The baseline state is
`337a2d20281b39f16c9182dfa57ea82ee9ffaa75517589c3bdfab552e3fa0659`.
Its source hash is
`b79bcddb7d447dadd120bcf46938a7b371ce91f476205196e20d3b426aead91c`.
The current `src/Timeline.cpp` and `HEAD:src/Timeline.cpp` have this same hash.

The direct-member-guard state is
`aa2df8642c5e86b8fb3d66dc6e3801bffec290f0e5eaa75f86533a024e7c5402`.
Its source hash is
`33a5b32ac92f9b7339ab9f5532b8e71b1b825ae973bad0cabaa3061fdc444ee5`.
The frozen source changes only the outer guard:
`if (p != 0)` becomes `if (this->time_list != 0)`.

The direct-member probe is behavior-equivalent for the proven list walk.
It is a code-generation duplicate and does not retain the original duplicate test.
The worker correctly restored the baseline source before handoff.
The registry still records `0050DFD0` as `scratch`.
No source, header, flag, registry, inventory, test, or oracle path changed.

## Bytes

The baseline run event is
`ec616f47cbe78b72c9cdf233138c25f7cd533ad1bdf45af5eb8392e4844826f6`.
The baseline report event is
`6a7cd759fdf4f9b56f0a94cade03eb382846e36859a6eff565295602742ceeb0d`.
Its compiler-input fingerprint is
`a11adff27533a494c497ef35350c6df1f761183ce41d1407af1f8762c40c40be`.

The direct-member run event is
`034bc6180a3365ae578aea4743179ab8e79fa7a9be4eed64286e713ff5f8cace`.
Its finding event is
`5cff0f17bac6720be1cd1acd7b531c5b6632e4f3f0113a4e20312bd4db6082fe`.
Its compiler-input fingerprint is
`dab8c8397db3d0e6377e3e34f448c0e3619eb623b0269487d612546c4ae11f45`.

Both states produce the same output hash:
`5ca29aec5c68e90c72544bfd29924901080aeadf8084456f6869f47e655bcd2c`.
Both checks report `MISMATCH`.
The original body is 100 bytes.
The rebuilt body is 94 meaningful bytes.
The strict difference is 99 bytes.
Shape similarity is 88.37%.
Exact-block coverage is 55.81%.
The original saves `esi, edi`.
The rebuilt body saves `ebx, esi, edi`.
The original has 43 instructions, seven conditional branches, and one jump.
The rebuilt body has 42 instructions, six conditional branches, and no jump.
Both frames are absent.

The owner symbol validates after normalization:
`sub` and `?sub@RGE_Timeline@@QAEXPAURGE_Time_Entry@@@Z`.
The call map has two equal direct calls.
The recursive call targets original `internal+0x0` at `+0x4d`.
The rebuilt call uses the decorated owner relocation at rebuilt `+0x46`.
The checker normalizes both to the same internal target.
The second call is `free` with cleanup `4` in both bodies.
There are zero wrong direct targets and zero relocation-target mismatches.
The two relocation fields are not safely maskable (`0/2`).
That mask result is separate from target identity and does not alter the mismatch result.

## Integration

The fresh one-job closure audit is
`build/sa-eaf9ffbd-r1-timeline-final/report.txt`.
Its group fingerprint is the baseline fingerprint.
It compiled one group with no compile errors.
It covers all 13 configured normal owners in `timeline`.
It reports 10 `MATCH` owners, two held accepted-drift observations,
and one grouped mismatch for `0050DFD0`.
All exact rows have zero relocation-target mismatches and zero boundary escapes.
The closure did not reveal a changed neighbor or a source regression.

The worker's audit at
`build/sa-c2478cc8-r1-timeline-final/report.txt` reports the same rows.
The fresh audit confirms the worker result with the restored source.
No candidate patch exists for this mismatch.

Preserve the two state manifests, their four run or finding events,
all referenced experiment objects, and this review artifact.
Do not promote the target or request accepted-drift status.
Require new source, ABI, period-build, or executable evidence before another probe.

## Validation

- `python tools/experiment_history.py show --va 0050DFD0`
- `python tools/experiment_history.py inspect sa-c2478cc8-r1-0050DFD0-baseline`
- `python tools/experiment_history.py inspect sa-c2478cc8-r1-0050DFD0-direct-member-guard`
- `python tools/experiment_history.py compare sa-c2478cc8-r1-0050DFD0-baseline sa-c2478cc8-r1-0050DFD0-direct-member-guard`
- `python tools/check_function.py --va 0050DFD0 --no-build --detail full --call-map-unmatched --stack-map --block-map-differences`
- `python tools/check_function.py --va 0050DFD0 --no-build --detail concise --call-map`
- `python tools/audit_translation_unit_functions.py --group timeline --jobs 1 --output-dir build/sa-eaf9ffbd-r1-timeline-final`
- Inspected `build/asm/orig_0050DFD0_sub.txt`.
- Inspected `build/dossiers/0050DFD0_sub.txt`.
- Inspected `inventory/pdb/scoped_symbols.json` and `inventory/functions/0050/0050DFD0_sub.txt`.
- Verified current source and baseline object hashes.
- Verified no active compiler process at review time.

The target checks exit `1` because the target is a recorded `MISMATCH`.
The closure audit exits `0` and reports the complete closure.
