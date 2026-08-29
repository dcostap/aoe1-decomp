# Recovery journal: 00448A60 `ds_stream_pause`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/Dsutil.c`.
- PDB source: `C:\msdev\work\age1_x1\Dsutil.c`.
- Earlier recovery note: `recovery_notes/dsutil_module.md`.

## Translation-unit context

- PDB module: `Dsutil.c`; natural owner: `src/Dsutil.c`.
- Source order places `ds_stream_pause` after `ds_stream_volume` at `00448A60`.
- The body is an ordinary `__cdecl` stream helper with no frame or calls.
- Original body range is `00448A60-00448A6A` and is 11 bytes.
- Original sequence is `mov eax,1; mov [_stream_paused],eax; ret`.
- `TSound_Driver::pause_stream` tail-jumps to this function and returns its `EAX`.

## Current mismatch

- Baseline with `void ds_stream_pause(void)` was 11 bytes with a 6-byte strict
  difference. VC5 emitted `mov dword [_stream_paused],1; ret`.
- The baseline had no frame, no calls, matching owner and boundary, and one
  safely masked global relocation.
- The return value required by the tail-jump caller explains the original EAX
  value. This is a binary-supported source fact, not a codegen-only trick.
- Current source uses `int ds_stream_pause(void)`, stores `1`, and returns `1`.

## Recovered attempt history


<!-- recovered:d84993e308e93755bb0f -->
### `7adef504ea1e` `src/scratch/00448A60_ds_stream_pause.cpp:1-5`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00448A60 ds_stream_pause (11 B)
// PDB source: Dsutil.c
// Pauses the stream
// ACCEPTED_DRIFT: VC5 generates mov dword [addr],1 while original uses mov eax,1/mov [addr],eax.
// Both are functionally identical with equivalent address encoding after relocation.
```
<!-- end-recovered:d84993e308e93755bb0f -->

### `trial-dsutil` natural return reconstruction

- Fresh baseline checkpoint: `20260829T170220.556449Z-46dc5dbde2`.
- Tested local and expression forms. They retained the 6-byte mismatch.
- Changing the function return type to `int` and returning `1` produced the
  original three-instruction sequence.
- Final standalone check: `MATCH`, `0.0000%`; 11/11 bytes and 3/3
  instructions match. Frame, owner, boundary, calls, and relocation checks
  also match.
- Fresh grouped audit: `build/audits/workers/trial-dsutil/dsutil/report.txt`.
  All 25 registered owners match. This target is exact in the grouped object,
  with zero relocation and boundary differences.

## Rejected approaches

- An initialized or separately assigned local `paused` value did not preserve
  the original sequence. VC5 folded each form to an immediate global store.
- Constant, unary, pointer, ternary, condition, and switch expression forms
  were not retained because they did not explain the caller's return value.

## Open questions

- The original source declaration is not available. The caller and returned EAX
  prove that the natural function contract returns `1`.

## Next useful approaches

- Main agent should review this exact owner for promotion. The grouped audit
  keeps the seven unregistered or unresolved natural-module rows unchanged.

## Worker updates

- `trial-dsutil`: Recovered the missing integer return from the tail-jump caller.
  Standalone and grouped code are exact. The audit reports 25 registered owner
  matches, including this target.
