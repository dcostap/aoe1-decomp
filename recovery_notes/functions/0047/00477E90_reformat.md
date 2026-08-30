# Recovery journal: 00477E90 `reformat`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/Pnl_inp.cpp`.
- PDB source: `C:\msdev\work\age1_x1\Pnl_inp.cpp`.
- Earlier recovery note: `recovery_notes/Pnl_inp_module.md`.

## Translation-unit context

The PDB module is `Pnl_inp.cpp`, and the owning class is `TInputPanel`.
The function is in source order after `paste` and before `calc_input_pos`.
The original body is `00477E90-00477EEA` (91 bytes). It saves `top_line`
from `+0xFC` in `BX` and `cur_line` from `+0x100` in `DI`, calls the
inherited `TTextPanel::set_text` with `input_buffer`, clamps both saved
positions against `num_lines`, calls `TTextPanel::scroll`, and calls the
virtual redraw slot at `+0x20`.

## Current result

The fresh baseline used an explicit `(unsigned char)top` cast for the second
`scroll` argument. It emitted 96 bytes and 33 instructions. The first
structural difference was at `+0x42`, where the cast caused zeroing and
byte-wise construction of the stack argument.

The current natural source emits 91 bytes and 31 instructions. It has no
frame, saves `ebx`, `esi`, and `edi`, matches the original boundary, and has
three aligned calls. All 91 bytes match positionally. The two relocations are
safe, and the owner symbol is `?reformat@TInputPanel@@IAEXXZ`.

## Recovered attempt history


<!-- recovered:d90bf041e4af9126b42b -->
### `bf81de068f12` `src/scratch/00477E90_reformat.cpp:1-6`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// attempt 1: natural save/clamp/scroll shape from the asm
// result: close, but the saved short register assignment landed swapped
// attempt 2: swap the local birth/order so old_cur stays with the first clamp and old_top with scroll
// attempt 3: restore the original save order after the vtable/layout fix; that should put the saved shorts back in the right registers
// attempt 4: try a single saved line-count temp so both clamps share the same compare source
// still stuck: only the saved-short register assignment is swapped; the branch/body shape is otherwise aligned
```
<!-- end-recovered:d90bf041e4af9126b42b -->

## Rejected approaches

The historical standalone probe used raw layout overlays and duplicate class
declarations. It is prohibited by the current ownership policy. No such form
is retained. The explicit unsigned-char cast is also rejected because it
creates a larger, non-matching call hunk without binary support.

## Open questions

An earlier target-session lock timed out during a variant check. This review
completed a fresh validation check and confirmed that the source remains safe.
The final release attempt also timed out, so the lease remains active for
coordinator repair. No open source question remains; the coordinator controls
promotion and lease cleanup.

## Next useful approaches

Keep the natural `short` argument to `scroll`. If the grouped audit reports a
neighbor regression, inspect only the changed owner and restore the pinned
translation-unit source before testing another natural form.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.

### wave21-pnl-inp — 2026-08-29

Removed the explicit unsigned-char cast from the second `scroll` argument in
`src/Pnl_inp.cpp`. A fresh direct rebuild changed the baseline from 96 bytes,
33 instructions, and 28 differing bytes to `MATCH`, 91 bytes, 31
instructions, and `0.0000%`. The natural source now reproduces the original
register and stack argument shape without overlays or compiler tricks.

The worker audit was written to
`build/audits/workers/wave21-pnl-inp/Pnl_inp/report.txt`. It reports this
target as `review_for_promotion` with `MATCH`; 16 other registered owners
also match. It reports unrelated grouped regressions at `00476C10`,
`00476FA0`, `00477AF0`, and `00478010`, plus the existing `00477220`
mismatch. The target change itself does not cause a grouped mismatch.

### wave21-pnl-inp review — 2026-08-29

Reviewed the prior source edit and retained its only source change. The natural
`short` argument to `scroll` is binary-supported and produces the original
call-argument shape. No overlay, duplicate declaration, raw address, or
compiler steering remains.

Focused validation used the `wave21-final` checkpoint. It reports `MATCH` with
91/91 bytes, `0.0000%`, the correct `TInputPanel::reformat` owner, the original
boundary, and no boundary escape. All three calls align. The direct targets are
`TTextPanel::set_text` and `TTextPanel::scroll`; the third call uses virtual
slot `+0x20`. Both relocations are safe.

The worker audit ran with:

`python tools/audit_translation_unit_observed.py --group Pnl_inp --jobs 1 --output-dir build/audits/workers/wave21-pnl-inp/Pnl_inp`

The target remains `MATCH` with zero byte differences, zero relocation target
mismatches, and zero boundary escapes. Sixteen registered owners also match.
The audit reports unrelated issues at `00476C10`, `00476FA0`, `00477220`,
`00477AF0`, and `00478010`. The source remains scratch until promotion review.
