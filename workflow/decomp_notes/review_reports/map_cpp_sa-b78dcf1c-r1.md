# Review: `src/map.cpp` worker `sa-b78dcf1c`

Workflow: matching with reviewers.

Reviewer: current evidence review session.

Target: `00456170 postclean_elevation`.

Base: `f73f295fed1113d057c8f7dc68d719c273d38805`.

Compiler-input fingerprint: `85f1eb3ed6d2f744b00f1c9433562f0cefb8f1b560a9dd81177af505b46d467b`.

## Disposition

**NEEDS_CORRECTION** for the worker evidence package.

**APPROVE** no source integration. The worker retained no source change,
exact candidate, or accepted-drift proposal.

**APPROVE** the current registry decision. Keep `00456170` in `scratch`.

**NEEDS_CORRECTION** experiment preservation and handoff. The durable final
check is valid, but the package does not preserve all fresh variant probes and
has stale session and note references.

No source or configuration change is approved by this review.

## Behavior

The original function is 880 bytes, uses `__thiscall`, has no calls, and ends at
`004564DF`. The original assembly uses the `RGE_Map` row table, 24-byte tile
stride, and tile byte `+0x05`. The byte stores the three-bit elevation in bits
5 through 7.

PDB evidence identifies the formal homes as `+0x4 long x1`, `+0x8 long y1`,
`+0xC long x2`, `+0x10 long y2`, and `+0x14 unsigned char elevation_height`.
It identifies `-0x20 long index2`, `-0x1C long index1`, `-0x23 unsigned char
was_bad`, and short offsets at `-0xC`, `-0x10`, and `-0x8`. It identifies
`ecx` as `RGE_Map* this`. `query_abi.py` and the target dossier agree.

The source has no runtime test for malformed bounds, extreme values, tile
faults, or fault order. No accepted-drift behavior proof exists.

## Source

`src/map.cpp` is unchanged from `HEAD`. Its SHA-256 is
`2288ba0cc672a1b26ad706f2a4cfedd89fc82b182aa11e3d81fb3685f51cbd24`, which
matches state `4bd8e5ed0c9cdccbfcea710a35efb6dd9cd11653f0b5e22da2f97c6a5d788256`.
The target has no dependency calls. No target candidate exists under
`workflow/decomp_notes/candidates/0045/`.

The natural typed source is plausible. It has no wrapper, raw target address,
manual vtable, or inline assembly. The registry still records:

```text
00456170: scratch
```

The function note has no section for worker `sa-b78dcf1c` or the 2026-09-05
variant work. Its older section points to the absent path
`build/handoff/sa-c94ca0bf-map-reviewer-handoff.md`. The current worker handoff
path is also absent.

## Bytes

The authoritative state is
`4bd8e5ed0c9cdccbfcea710a35efb6dd9cd11653f0b5e22da2f97c6a5d788256`.
The authoritative final run is event
`f8adf11e95bbac90456542104bf5f965e70985b0b4bb8eaf08871219a3b55e68`.
The worker's variant finding is event
`360ea9108ac4f8c296e2b82f6100116d1d92b6553b67634ae54d48856fc3894e`.

The preserved check reports:

- original/rebuilt effective size: `880/871`;
- strict difference: `719` bytes (`81.7045%`);
- shape similarity: `72.85%`;
- exact-block coverage: `35.40%`;
- frame: `0x24/0x24`;
- calls: `0/0`;
- owner symbol: match;
- boundary escape: `0`;
- relocations: `0/0`; and
- result: `MISMATCH`.

Check object: `11d6b21dd2bc639656b57dcee0cf1ce5685656aa5b8e0d503a836521c4a92742`.
Closure report object: `93159d60ea300162ad4a52773476063c059f0a9c4f1d2b93fe3a2d66e547c909`.
Closure owner object: `47e7941abef5cac8120b9827933dd89f6a6e8ec750e96dbaa50639edd0bf45f1`.
Rebuilt target object: `8072311fa01c53fc6f3c54f95c3713833bbddbd3965da0fa017f98b5e42ff21c`.

The final closure compiled the `map` translation unit with 64 normal owners.
It reports 52 matching owners and 12 nonmatching owners: five grouped
mismatches, four accepted-drift observations, and three boundary problems.
The target row is `grouped_mismatch`, `matching_anywhere: false`, and
`recommended_action: assign_matching_worker`. No target source proposal or
status promotion is supported.

The final run event preserves four variant summaries:

- `20260905_225007`: `c9826d6d8fb6de10f888d35ab14ec4462b1f3af6880f637785af98a2c490c298`;
- `20260905_225305`: `00d67596d58d9710ffd731e7a39bc20391a878c1d070376755e0d8094cffb895`;
- `20260905_225536`: `a51f41cd0040271c5168f123f9f8dab6cd34c7b5b0bf175f47dfede10f699a24`; and
- `20260905_225659`: `3a39c74421e9c988a66537d649e14e0978bc56c915285a47db9afcba982b8129`.

Twelve variant run directories exist in `build/variant_lab/00456170_postclean_elevation/`.
The eight runs below are not referenced by a durable event or object:

```text
20260905_224724  4 variants, 2 compile errors, size 871, diff 719
20260905_224857  4 variants, 0 errors, size 871, diff 719
20260905_225211  1 variant,  size 889, diff 789
20260905_225354  1 variant,  size 871, diff 719
20260905_225731  1 variant,  size 872, diff 815
20260905_225859  1 variant,  size 873, diff 788
20260905_225949  1 variant,  size 881, diff 856
20260905_230024  1 variant,  size 871, diff 719
```

The missing list includes a failed compile and equal-output runs. The worker's
finding text summarizes these probes, but a summary sentence does not preserve
the tested inputs. The run manifests, templates, and source variants are also
not attached to the durable finding.

The event's preserved diff object is valid at hash
`4fab9fe1d287d05b6ebbb3f17e287288be36fd6d82394c224ab773b571711be9`. The live
`build/diff/00456170_postclean_elevation.json` now has hash
`054c060324baa30358058dbcc47edcb41935ec28ef318c7fccdc08e8be911245` because
its `iteration_delta` is `null` instead of the preserved empty delta object.
Use the durable object, not the overwritten build path, as the event evidence.

## Integration

No source, header, flag, registry, test, inventory, oracle, or candidate file
changed. Current source restoration is verified by the clean source hash and
empty Git diff. The target remains scratch. No source or status integration is
approved.

The target-session file
`build/target_sessions/00456170_postclean_elevation.json` is stale. It has
`probes: []`, an empty metric summary, an empty clean baseline, and only the
20:39:58Z start event. It does not describe the durable 20:59Z final run or the
variant lab work. The brief has the same stale zero-probe fields.

Requested corrections:

1. Create the worker handoff with the four required headings and the state,
   event, compiler fingerprint, closure, and changed-path identities.
2. Preserve the eight missing variant summaries and the corresponding frozen
   templates, manifests, and failed-build inputs. Include equal-output and
   failed probes. Use durable objects, not build-directory paths alone.
3. Add the worker's final metrics, probe summary, and no-change conclusion to
   `workflow/decomp_notes/functions/0045/00456170.md`. Replace the absent handoff link
   with durable state and event references.
4. Mark the target-session and brief fields as stale, or refresh them through
   the normal target-session workflow. Do not replace the authoritative event
   result with empty session data.
5. Cite the preserved diff object hash, not the current overwritten
   `build/diff` file, until the path is regenerated and captured.

No new compiler probe is required for these reporting and preservation fixes.
Restart review after the package correction. Keep the target in `scratch`.

## Validation

Commands and results used in this review:

```text
python tools/query_abi.py --va 00456170 --include-nonexact --json
  PDB homes and declaration candidate agree with the dossier.

python tools/target_dossier.py --help
python tools/query_abi.py --help
python tools/variant_lab.py --help
python tools/experiment_history.py --help
python tools/experiment_history.py note --help
  Command interfaces checked before review use.

git diff -- src/map.cpp include/map.h config/functions/src/map.cpp.json
  No output.

sha256sum src/map.cpp
  2288ba0cc672a1b26ad706f2a4cfedd89fc82b182aa11e3d81fb3685f51cbd24

sha256sum of final check, closure, owners, target object, and durable diff object
  Matches the hashes recorded by event `f8adf11e...`.
```

This review does not claim runtime behavior equivalence. It records an
evidence-only disposition for the worker package.

## R2 recheck

Worker `sa-b78dcf1c-map` supplied the requested evidence-only correction.
Correction events `34a14ac3acc91584869ea562d576400b71a5b857686b47010f4317d4ca1367ec`
and `b195fcaf5cd0b77e6d9f5fde77e93b0369c651acb96df2ba20a7b71b8068de45`
record the handoff, note, stale metadata, and final diff references. The
second event points to the current handoff and note objects.

The current handoff is present at
`build/handoff/sa-b78dcf1c-map-reviewer-handoff.md`. It has Behavior, Source,
Bytes, and Integration sections. Its SHA-256 is
`8e1c8fe56a08e4497d10c92c5fad2d89c71f679c40b735dd08f671b7df701bd0`.

The current function note has the new evidence-correction section. Its
SHA-256 is
`5c955c5f6dea280687183ad7022eff50fd65e6333e1035a8332ccd94780e9412`.
The old absent handoff reference is corrected to the current handoff path.

Event `072d5fc266f358230064fc378eee38b3794c50c426c3490d1d06f778495143cf`
preserves all eight previously missing runs. It lists 114 artifact objects.
All 114 object files exist, and each object's SHA-256 matches its object name.
The event covers the failed compile, equal-output variants, templates,
manifests, source inputs, result tables, diffs, assembly, objects, binaries,
and summaries. The handoff table reconciles all eight run IDs and metrics.

The target session now marks itself `STALE` and names the authoritative state,
run event, and variant event. The brief and target-session index carry the
same stale labels and event identities. This is correct because the notebook
still has empty probe fields; the durable records are authoritative.

The final diff reference is corrected to the preserved object
`4fab9fe1d287d05b6ebbb3f17e287288be36fd6d82394c224ab773b571711be9`.
The final target result and closure remain unchanged: `MISMATCH`, 719 strict
differences, and 52 matching owners out of 64 compiled owners. No source,
configuration, registry, or status change is present.

**R2 verdict: APPROVE the evidence-only correction.** This approval does not
approve source integration or status promotion. Keep `00456170` in `scratch`.
Preserve the correction events, 114 variant objects, handoff, note, and stale
metadata records before worktree reuse. No new compiler probe is required.
