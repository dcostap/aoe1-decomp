# Independent review: `00473D60` `TDialogPanel::setup`

- Workflow: matching with reviewers
- Reviewer: `sa-16fa8446-r1`
- Worker: `sa-38767c68-r1`
- Worktree: `C:/Projects/my_decomps/aoe1_queue_slot_4`
- Branch: `queue-slot-4`
- Base: `ca891e302d80ef004cc306df41d7ff95a75fa15c`
- Scope: `src/pnl_dlg.cpp`, scratch `00473D60 setup`

## Verdict

**Evidence-only retention: APPROVE.** Keep the natural source and keep the
registry status `scratch`. There is no exact result, source repair, or
accepted-drift proposal.

**Package notes: NEEDS_CORRECTION.** The worker's durable target note ends at
an older `scratch00473D60` period. It does not record the current `sa-...`
states, the qualified-member probe, or the failed qualified-width build. The
worker should append the current state and event IDs. No source rebuild is
needed for this correction.

## Reviewed inputs

Current assignment states and events:

- Baseline state `8a8e6cb320abd2f07308d83b916417795689b9fbc62f5daaeded51c51d743c31`,
  named `sa-38767c68-r1-00473D60-baseline`.
  Runs `0fb3f89b40d03072ad17ce6a40a0b2f677df0aa7cd32e5430960a58f5a47a9c8`
  and `8bdf354ff225a2f96de3d2fecbb546c0ce528210e303988f95328013d009dad9`.
- Qualified-member state `110352039ca2298bcf83ad104b355db3400082fccb3c0d443d6711736561d8e5`,
  named `sa-38767c68-r1-00473D60-qualified-member`.
  Run `c7f73c61d41e763c8292ea4903278bc7aded0aa7cd32e5430960a58f5a47a9c8`.
- Qualified-width state `58e25379701bf80a7bc33261838c8665066d193e1175470f40d07760b3be358a`,
  named `sa-38767c68-r1-00473D60-qualified-width`.
  Failed-build event `cb8e2def414b2ab6ca50a4f5682e6667787346d2b64a02759c01c7e6ae4ae4ed`.

The baseline compiler-input fingerprint is
`337850e4ea9eb1049dd355f3d96ef77b90bd99e211e8cb87e3987de7cbff5d77`. The
qualified-member fingerprint is
`33ff140c30c658f15206f4129ff3b337f69aa9831f06888c97236016e903b9d5`. The
failed qualified-width fingerprint is
`4155acd9bde5a357bdfeb23c8b1ca7714186136f4e62a377e88309ad7af966ed`.

The current source hash is
`21b9a197950c870665b34b63aa51ac2334b99a0d27218a3e9982dfb707931320`.
It matches the baseline manifest and `HEAD`. The reviewer verified the actual
file hash as
`21b9a197950c870665b34b63aa51ac2334b99a0d27218a3e9982dfb707931320`.

The older `scratch00473D60` branch was also reconciled. Its six
register-qualified probes all kept `MISMATCH`, 196 differing bytes, and the
same rebuilt output. Their states are `b043317c09c2fb3dd97d069926d0fc71a22555d8a31d36b58776eddacfb70049`,
`df33a62be90a8a9abb6529bf33c85ccb3038129067036bf72a660b879d3a195a`,
`77d45d9256f383bd22ca32462c1cdb08b61adcf4957049f112e453126a8bf575`,
`b3d5128aea4dda7ab4ef8997eaff10907970e2cb1960b44dc94f2c7da3692790`,
`1e1a6082db32b3922306e1a0ccb6ca688e7e300056f5bc107225789dea768b2a`, and
`45fc3260d28dc1b9ee7df933bf09eda64e2093ccc9d79603fcfad692fe8afe6c`.
Their run events are, respectively,
`e925395c1bec1b284248f8109acc8c6f25415233c41b644c6f1195b891743363`,
`b70426f8ba51d56c51fa2e308a73925e870c16fcbce0a1542a6030bd0de50c45`,
`ed8db8c673884fcfb4db8d26fca1a17ab2871caa20f3765bfc8e393f20a457bd`,
`3a1bb30e9247fd49fcc4eaaca12c6a018afbf7452381bc65e9a1565930ab7d9b`,
`f66b0ec44ba1fe12d5cae5c7e6068d0e596bbbc8401c29aa2901981e824ab663`, and
`bee7aee70170427271a6128293277ff846f98ba4076be61bc67130927c7578af`.
These are prior evidence, not new source proposals.

## Evidence-only natural source

### Behavior

The original extraction is `00473D60-00473E32`, 211 bytes. The original
assembly proves this order:

1. If `parent_in` is non-null, call `width` and `height`.
2. Otherwise read `render_area_in->Width` and `render_area_in->Height`.
3. Call the `TEasy_Panel::setup` body at `00466A90`.
4. On failure, store `1` at `this+0xD8` and return `0`.
5. On success, call virtual slot `+0x10` (`set_color`), `set_z_order`,
   `setModalPanel`, and conditional `set_curr_child`.
6. Return `1`.

The dossier proves seven ordered calls, four saved registers, no frame, and a
single `this+0xD8` write. The PDB packet proves `this` as `TDialogPanel*` and
these six typed parameters: `TDrawArea*`, `TPanel*`, `long`, `long`,
`unsigned char`, and `int`. No local PDB records exist.

The natural source preserves the parent/null branch, dimension reads, centered
position arithmetic, base setup arguments, failure store, color-before-modal
order, and parent-child update. No runtime test exists. Null render-area
faults, malformed dimensions, callee faults, and exception paths remain
untested. The behavior conclusion is static executable evidence only.

### Source

The owner is the natural `TDialogPanel::setup` overload in
`src/pnl_dlg.cpp`. `include/pnl_dlg.h` declares the matching six-parameter
virtual overload and checks `TDialogPanel` size `0x490`. The source uses the
canonical `TEasy_Panel`, `TPanel`, and `TPanelSystem` declarations. It has no
wrapper, raw layout cursor, inline assembly, fake volatility, or forced
register machinery.

The qualified-member probe changed only `parent_in->width()` and
`parent_in->height()` to explicit `TPanel` qualification. `experiment_history
compare` reports no changed compiled owner and the same rebuilt output. The
qualified-width probe attempted `TPanel::width(parent_in)` and
`TPanel::height(parent_in)`. VC5 rejected both calls with C2660 because these
are non-static members. The failed input is preserved and is not evidence
against the intended natural hypothesis.

The six older register probes changed one parameter declaration at a time.
Each emitted the same target body and had no exact-neighbor regression. The
qualifiers are diagnostic experiments only and are not retained.

### Bytes

The final baseline run `8bdf354ff225a2f96de3d2fecbb546c0ce528210e303988f95328013d009dad9`
reports:

- `MISMATCH`, 196 differing bytes, `92.8910%`;
- original/rebuilt body size `211/209` bytes;
- original/rebuilt instructions `88/87`;
- shape similarity `86.36%` and exact-block coverage `35.23%`;
- frame `none/none`, with saved registers `ebx`, `ebp`, `esi`, and `edi`;
- seven of seven ordered calls aligned, with no site gaps, replacements, or
  target-count gaps;
- owner symbol `match`, no boundary escape, and no direct-target mismatch;
- CFG signals `3/3` conditional branches, `1/1` jumps, and `2/2` returns; and
- first strict mismatch at the entry load, with a two-byte effective size gap.

The qualified-member run has the same 209-byte rebuilt output hash and 196-byte
difference. Its closure has four matching owners and this one grouped
mismatch. The failed qualified-width run has no byte result because compilation
failed at source lines 60 and 61.

The authoritative no-build check was run with `--detail full`, call map, stack
map, block map, and the original range. It confirmed the target owner,
boundary, call identities, failure store, and metrics above. Exactness is not
claimed: the result is not `MATCH`, and the positional difference is broad.

### Integration

**Source decision: APPROVE unchanged.** No source or header change is
supported. **Status decision: APPROVE existing `scratch`.** Do not promote to
`matching`, `accepted_drift`, or `verified_logic`.

**Preservation decision: APPROVE.** Preserve all three current states and
all four current events, their referenced objects, the two successful closure
reports, and the failed-build artifact. Preserve the older six register-probe
states as prior evidence.

The current natural translation-unit closure is
`build/experiment_runs/9bd174eb340f4183b82c2f74ea62bc75/closure/report.json`.
It compiled all five `pnl_dlg` owners with no compile errors: four `MATCH`
owners (`00473C10`, `00473C80`, `00473E40`, `00473EC0`) and this one grouped
mismatch. The qualified-member closure is
`build/experiment_runs/aa9e3670cb354b66b75b0ad102c76ceb/closure/report.json`;
it gives the same four-neighbor result. No exact neighbor regressed.

The current source is restored. The latest baseline run follows both probes,
and `git diff --exit-code -- src/pnl_dlg.cpp include/pnl_dlg.h include/panel.h
include/panel_ez.h config/functions/src/pnl_dlg.cpp.json config/flags/gx.rsp`
returns zero. No separate final-clean state exists, so the baseline hash and
latest rerun are the restoration proof.

## Note correction request

`workflow/decomp_notes/functions/0047/00473D60.md` currently ends at its older
Work period 12. Append a current period that records the three current state
IDs, four current event IDs, all three compiler fingerprints, the qualified-
member equal-output result, the qualified-width C2660 failure, the final
baseline metrics, the two closure report paths, and the source restoration.
Replace build-only references that are no longer present with durable state and
event IDs. Do not change the source, header, flags, registry, inventory, or
tests.

## Validation

- `python tools/target_dossier.py --va 00473D60 --json-only`, then inspected
  `build/dossiers/00473D60_setup.json`.
- `python tools/check_function.py --va 00473D60 --no-build --detail full
  --call-map --stack-map --block-map-differences`.
- `python tools/check_function.py --va 00473D60 --no-build --detail concise
  --range orig:00473D60-00473E32`.
- `python tools/experiment_history.py show --va 00473D60` and `inspect` for
  each current state.
- `python tools/experiment_history.py compare` for baseline versus both
  qualified probes and for all six older register probes.
- Inspected `build/asm/orig_00473D60_setup.txt`.
- Inspected both current closure reports and the failed-build check artifact.
- `sha256sum src/pnl_dlg.cpp` and `git diff --check`.

No reviewer edit changed source, headers, flags, registry, inventory, tests,
or the behavior oracle.

## R2 follow-up

The worker appended Work period 13 to
`workflow/decomp_notes/functions/0047/00473D60.md`. The note now records the current
baseline, qualified-member, and failed qualified-width states; their compiler
fingerprints; all current run events; the failed C2660 build; both closure
reports; final metrics; and source restoration.

The event references are correct. The reviewer finding event ID is
`324dfeb458a6f3bc7cbf61aa29eb9de520edf2d19ccecf60dbfb75e178138052`.
The correcting artifact event ID is
`6e33577f0449c9f4899589d9c5de5adac98c6c8adcea4bb04c57d96fddd9146c`.
`experiment_history.py inspect` confirms these IDs. Their internal record
UUIDs are different and are not used in the note.

The refreshed target check remains `MISMATCH`, 196 differing bytes, 209/211
bytes, 86.36% shape, seven of seven calls aligned, owner match, and no
boundary escape. The qualified-member comparison remains byte-identical to
the baseline with no changed compiled owner. The qualified-width state remains
a preserved C2660 build failure. Both closures report four exact owners and
one grouped target mismatch.

`git diff --check` passes. Protected paths have no diff: source, headers,
flags, registry, inventory, and tests are unchanged. Only the target note and
durable review or experiment records are changed.

R2 final disposition: **APPROVE** evidence-only retention, existing `scratch`
status, experiment preservation, closure, and updated notes. No source change,
status change, or rebuild is required.
