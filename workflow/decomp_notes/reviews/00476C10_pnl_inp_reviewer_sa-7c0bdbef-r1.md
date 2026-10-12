# Independent review: 00476C10 `TInputPanel`

- Workflow: matching with reviewers
- Reviewer: `sa-7c0bdbef-r1`
- Worker: `sa-6d032af0`
- Worktree: `C:/Projects/my_decomps/aoe1_reviewer_wave_02`
- Branch: `reviewer-wave-02`
- Base: `2462da2ea92901acfdfba5d1ecc3cdc7e9043a9a`
- Scope: `src/Pnl_inp.cpp`, `TInputPanel::TInputPanel` at `00476C10`

## Reviewed inputs

The reviewed state is `c1dd3638a632e4b7415b38d5351fe5118ca2034e6b608705eba2bffc7ee18872`, named
`sa-6d032af0-r1-00476C10-baseline`. It has no parent and uses base
`2462da2ea92901acfdfba5d1ecc3cdc7e9043a9a`.

The state compiler-input fingerprint is
`3c2d023b4978b6480c4ba23176f1f95eefe734508897d351a120873bfa4dc23e`.
The state source hash for `src/Pnl_inp.cpp` is
`791be297337daee999b0d3afdc6b522d9bdfea83b26a25060042b595ff1bef6b`.
The current source hash is the same. The source, header, flags, and registry
scope has no diff from the base.

Reviewed events and preserved inputs are:

- target run `7ff966d5b3084eff505bf19850bbbf20e8a43aad2de83120ea541bd037455a26`;
- closure run `9ccd3f60d5a09e550609d197ec8a9fe30bce85acc285cebd268210c09455484c`;
- worker finding `c820ce068136cffc4fba435640b0ea2de82922fde49393db79f17bfcde95f629`;
- worker status correction `fcdf0d54498c3803b0afae6df92afc71f04443c1a66713f4434e3fe9f419e890`.

The exact candidate record is
`workflow/decomp_notes/candidates/0047/00476C10_experiment_c1dd3638a632_exact_candidate.patch`.
It contains the state and base identifiers only. The state has no source diff
against its base, so this is a valid metadata-only candidate record.

## Proposal: retain the exact constructor

**Verdict: APPROVE.**

### Behavior

The original body is `00476C10-00476CC4`, inclusive, with 181 bytes and 39
instructions. The source calls the `TTextPanel` base constructor, calls
`GetCaretBlinkTime`, and initializes the proven derived fields. It then writes
the inherited `handle_mouse_input`, `bevel_type`, `panel_type`, and
`horz_align` fields. The source uses the canonical `TInputPanel` layout and
`TTextPanel` base surface. It does not initialize `format_type`, matching the
absence of a store at `+0x19C` in the oracle.

The static oracle evidence supports the call and store order. No runtime
harness ran. There is no runtime-input coverage beyond the constructor's
implicit `this` input, and malformed object or exception behavior is not
separately tested. Exact positional output is the stronger available behavior
and code-generation evidence here.

### Source

The PDB packet binds the owner to `TInputPanel::TInputPanel` in
`Pnl_inp.cpp:36-41`. The scoped PDB record proves `this` in ECX and no
function-static or stack symbols. The living definition at `src/Pnl_inp.cpp:16`
is a natural C++ constructor with a typed base initializer, typed member
initializers, and typed inherited stores. It has no inline assembly, raw
address, fake helper, wrapper, or manual vtable.

`include/Pnl_inp.h` proves the derived size as `0x1B8` through its composed
`TTextPanel` base. The target dossier reports `TInputPanel` size `0x1B8` and
records the same owner, calls, and field layout. The source is plausible for
this exact constructor context.

### Bytes

The authoritative target check reports:

- result `MATCH`, strict positional diff `0` bytes, `0.0000%`;
- original/rebuilt size `181/181` and instructions `39/39`;
- original/rebuilt frame `none/none`, saved registers `ebx, esi`;
- calls `2/2`, both aligned with no gaps, replacements, or target-count gaps;
- one direct `TTextPanel::TTextPanel` call and one indirect
  `GetCaretBlinkTime` import call, both at matching offsets;
- owner match for `??0TInputPanel@@QAE@XZ` and normalized owner
  `TInputPanel`;
- original boundary `00476C10-00476CC4`, rebuilt meaningful size 181, and no
  boundary escape; and
- relocations `7/7` safely masked, all compatible, with no target mismatch.

The no-build check used cached output with the recorded fingerprint. The
recorded target and closure events report the same exact result and rebuilt
output hash `1e691d26aedf90da8913cdcb0e0ef648776d9cb5b6f78122bae6b224725301f0`.

### Integration

Retain the current source unchanged. No accepted-drift proposal is needed.
The exact candidate and all state, event, and referenced objects should be
preserved. No source, header, flag, registry, inventory, or test edit is
required for this proposal.

## Closure and status review

**Closure verdict: APPROVE.**

The recorded `pnl_inp` closure uses the same compiler-input fingerprint and
compiles all 22 configured owners. It reports 20 `MATCH` owners, the existing
9-byte accepted-drift observation at `00477AF0`, and the existing 1076-byte
scratch mismatch at `00477220`. The target is `MATCH` in the closure. No
changed neighbor, boundary escape, or relocation target mismatch is present.

**Registry status verdict: APPROVE existing `matching`.**

`config/functions/src/Pnl_inp.cpp.json` at the recorded base and in the current
worktree lists `00476C10` as `status: matching` with symbol
`??0TInputPanel@@QAE@XZ`. The assignment and the module note use stale `scratch`
wording. The exact result does not need a registry promotion. The worker's
correction event correctly identified this discrepancy, but the durable target
note still says that the target remains scratch and may need promotion.

## Durable note correction

**Verdict: NEEDS_CORRECTION for note wording only.**

The target note must not state that `00476C10` remains scratch or that it needs
promotion. The registry already records `matching`. Replace that wording with
an explicit statement that the exact source is retained at existing registry
status `matching` and that no status change is needed.

The module note also has a stale exactness list. It says there are 17 matching
and five scratch owners, and lists `00476C10`, `00476FA0`, `00477AF0`, and
`00477E90` as scratch. The current registry and closure instead show 20
matching owners, one accepted-drift owner (`00477AF0`), and one scratch owner
(`00477220`). Correct the module note in a note-only follow-up. Do not rebuild
or change source, headers, flags, registry, inventory, or tests for this
correction.

## Final disposition

- Exact constructor source: **APPROVE unchanged**.
- Registry status `matching`: **APPROVE existing status**.
- Candidate and experiment preservation: **APPROVE**.
- Closure: **APPROVE**.
- Target and module note wording: **NEEDS_CORRECTION**.
- Overall package: **NEEDS_CORRECTION** until the stale scratch wording is
  corrected. A rebuild is not required.

Validation performed:

- `python tools/experiment_history.py inspect c1dd3638a632e4b7415b38d5351fe5118ca2034e6b608705eba2bffc7ee18872`
- `python tools/check_function.py --va 00476C10 --no-build --detail full --call-map-unmatched --stack-map --block-map-differences`
- `python tools/check_function.py --va 00476C10 --no-build --detail concise --call-map --no-history`
- `python tools/query_project_status.py --va 00476C10 --paths --notes --triage`
- `python tools/query_abi.py --va 00476C10 --json`
- `python tools/find_function_donors.py --va 00476C10 --limit 20 --include-accepted-drift --json`
- recorded closure report at
  `build/experiment_runs/de56239b280e4f03ae1111d837f762b0/closure/report.json`
- `git diff --exit-code 2462da2ea -- src/Pnl_inp.cpp include/Pnl_inp.h config/functions/src/Pnl_inp.cpp.json config/flags/gx.rsp`

No reviewer edits touched source, headers, flags, registry, inventory, tests,
or the behavior oracle.

## R2 follow-up

Worker correction event
`af2930ca04c07345188629a88fe2c6c1fb02ff1cab49ac2643204951ad0ce8c1` records
the note-only correction. Its artifacts hash to the current target note
(`43810da57aa087728283a86941885d53fc1ff4d3f632b0a02d4708d4039d4afb`) and
module note (`1e9142fb2d7e3038d563c522be43d00b1ecfba55331547eaebc929a0bd323592`).
The target note now says that the registry records `00476C10` as `matching`.
The module note now reports 20 matching owners, one accepted-drift owner, and
one scratch owner.

Worker event
`df3c01560248ad8f282a8491eafd078a0a2fd3deafb746c59d4962db1e18214c` correctly
replaces the placeholder event reference in the earlier correction finding.
The immutable earlier event is preserved, and the correcting finding gives
the valid event ID. This is the required append-only correction.

The registry still lists `00476C10` as `matching` with symbol
`??0TInputPanel@@QAE@XZ`. The only current worktree changes are the two note
files and preserved review or experiment records. No source, header, flags,
registry, inventory, test, or status file changed.

The target and closure results remain valid because the approved compiler
inputs and state are unchanged. No rebuild is required.

R2 final disposition: **APPROVE**. The exact source, existing `matching`
status, candidate, closure, experiment records, and corrected notes are all
ready for integration.
