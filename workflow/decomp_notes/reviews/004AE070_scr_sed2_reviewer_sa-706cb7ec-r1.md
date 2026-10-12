# Review: 004AE070 `save_victory_cond_in_scenario`

- Workflow: matching with reviewers
- Reviewer: `sa-706cb7ec-r1`
- Worker: `sa-af750f5e`
- Translation unit: `src/scr_sed2.cpp`
- Base: `50d91f7663a6d776d9fd09b4b9991a00ddd127ce`
- Scope: evidence only. No source, header, flag, registry, inventory, test, or status change.

## Verdict

- Evidence preservation: **APPROVE**.
- Source integration: **NO SOURCE PROPOSAL**.
- Status promotion: **NONE**. Keep `004AE070` as `scratch`.
- Exact proposal: **NONE**.
- Accepted drift: **NONE**.
- Current source is restored. It matches `HEAD` and the baseline state.

## Behavior

The dossier identifies one protected PDB owner in `scr_sed2.cpp`, lines 476-631, for body `004AE070-004AE5CE`. It records an `int VictoryType` at entry-relative `-0x4`. It records `long` locals `x1`, `y1`, `x2`, and `y2` at `-0x14`, `-0x10`, `-0xc`, and `-0x8`.

The failed integer probe is valid evidence of an unsupported type change. Its compiler output is preserved at `workflow/decomp_notes/experiments/objects/00/00d61c64148fd5068ad2207d035e083edf17b7da28a2bcfc0c182d6c8aa3fcac` and reports C2664: `get_selection_area` parameter 4 cannot convert from `int` to `long &`. State `6008f2f2354babd7e9a0946387509aa302822db0b062347044c3b80439e063e7` and run event `f43698f4132df55ef576787fc8cd2860cff15c28833fe763d1dca73fbcebc267` preserve the failed build.

The long follow-up compiled, but its source is not a valid behavior model. It calls `get_selection_area(y1, x2, y2, VictoryType, 1)` and stores those shifted outputs into `px1` through `py2`. The original assembly passes the four distinct homes for `x1`, `y1`, `x2`, and `y2`. Equal output bytes do not prove equal behavior. State `62802ff55dbc3110784369b653b1eb4e569636ebce740031f8ad743fb7c2d345` and event `6e16769dca4144f9005968341762641a5621e5df5be5179fef9358b6292647ed` preserve this diagnostic only.

The original call sequence also writes the dropdown `get_line` result to the `-0x4` home before the switch dispatch. Therefore PDB name `VictoryType` supports the integer switch local, not a fourth selection-area output. The long probe's equal bytes are an incidental stack-home/codegen result.

No runtime behavior test was run. The probe coverage is compiler and binary evidence only.

## Source

The baseline source uses the natural call and coordinate model:

```cpp
long x1, y1, x2, y2;
this->main_view->get_selection_area(x1, y1, x2, y2, 1);
this->px1 = (float)x1;
this->py1 = (float)y1;
this->px2 = (float)x2;
this->py2 = (float)y2;
```

The current file hash is `5e2081ca4282edf0f961bf85f9c155de8dadbe2f11ce4291b4eecd5f058aa2c5`. It matches `HEAD` and baseline state `c788392073fc064eacb52411591f0d173adbc20eb1202bc4d3ae600197e73731`. No compiler-facing source change remains.

The PDB and original stack evidence support the existing long coordinate types. They do not support replacing `y2` with `VictoryType`. The worker correctly restored the natural coordinate source and recorded that no source claim remains.

## Bytes

The baseline state uses compiler fingerprint `55ba86c01ff62b360c40469b3a9d51b97bd81b4b9a08c8680c6cf2d196699c5d`. Fresh baseline events `650904e16d043d150192d8eaf2f987751ca58564fbfa0be928b22ef2845794fc` and `fe03dede03dad7e2976107699d899359095ef451834e8aee94f7e1006f9c7566` report:

- `MISMATCH`
- 1,375 compared bytes; rebuilt size +0
- frame `0x14`; saved registers `ebx`, `ebp`, `esi`, `edi`
- 771 differing bytes, 56.0727%
- 418 original instructions, 417 rebuilt
- 55 original calls, 53 rebuilt
- owner symbol match
- boundary escape count 0
- two unmasked relocation target mismatches

The long state uses fingerprint `4f99986dd381258237828ac56cc8a2986f22204be3a4a8153664265a8edcc1f6`. Its fresh run event `1851d4ffd606f0e5e8e026ba5e1e19c862e3b3811efff3dc451b3c0f83dbff2f` reports the same 1,375-byte body, 771 differing bytes, and 53/55 calls. The preserved finding event `6e16769dca4144f9005968341762641a5621e5df5be5179fef9358b6292647ed` states that the rebuilt body equals the baseline body. This is byte evidence only, not a source or behavior approval.

The remaining call-surface difference is concrete. Original case 6 and case 9 each contain their own `SetSPVictoryType` and `SetSPObject` calls. Rebuilt case 6 and case 9 jump into one shared setter tail. The fresh baseline check reports missing calls near `+030E` and `+0324`, plus direct-target mismatches at `+051A` and `+0535` after alignment. This supports the worker's tail-merge blocker description. It does not support accepted drift because call count, control flow, and broad positional bytes differ.

`experiment_history.py compare` lists six changed compiled owners: `004ADD60`, `004AE070`, `004AE620`, `004AE9D0`, `004AEE10`, and `004AF6C0`. Their code hashes are unchanged. Their relocation/object hashes differ, but the long closure still reports the same 18 exact neighbors and no exact-neighbor regression. Preserve this closure result rather than treating the equal target bytes as a source approval.

## Integration

The baseline closure event `650904e16d043d150192d8eaf2f987751ca58564fbfa0be928b22ef2845794fc` covers the `scr_sed2` group with 19 functions: 18 `MATCH` functions and only `004AE070` nonmatching. It reports no compile errors. The long closure uses event `1851d4ffd606f0e5e8e026ba5e1e19c862e3b3811efff3dc451b3c0f83dbff2f` and has the same 18/1 result with no exact-neighbor regression. The closure fingerprints are preserved in objects `c48408163e566bb14a760a6b6db59950461af25865a0c4308552fca95a04849d` and `6b768927b03fe753f3427f58fe30366cc9e67146e55fdfde8336c580cfa0a337`.

The authoritative no-build check was rerun for the restored source:

```text
python tools/check_function.py --va 004AE070 --no-build --call-map-unmatched --stack-map --block-map-differences
```

It reproduced `MISMATCH`, 771 bytes, 1,375-byte size, `0x14` frame, 53/55 calls, owner match, and no boundary escape. The current source has no tracked diff.

Preserve all three states and their failed/equal-output events. Do not integrate the coordinate probes. Do not promote the target. A future attempt needs new source-context evidence for the separate case-6/case-9 tails and the original local-home permutation.
