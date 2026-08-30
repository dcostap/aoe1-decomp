# Function notes: 00476FA0 `char_action`

Module notes: `decomp_notes/Pnl_inp_module.md`.

## Recovered attempt history

<!-- recovered:2739759b5610ce950742 -->
### `b6e159352e2d` `src/scratch/00476FA0_char_action.cpp:1-18`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00476FA0 TInputPanel::char_action
// Attempt log:
// initial natural source from packet with MBCS helpers/IAT beep: compiles but emitted .text is 576 bytes vs expected 600, so no byte comparison.
// tried /GX to see if hidden EH/extra context was needed; unchanged 576-byte .text, removed flag.
// modeled MessageBeep as extern const stdcall function pointer to get IAT call surface.
// used real MBCS helper names _mbslen/_mbscmp/_mbschr for helper calls.
// modeled TInputPanel as virtual and bad_sound/get_text/insert_character members with packet offsets 0x198/0x19c/0x1a0/0x1ac.
// tried natural switch by input type with duplicated invalid return blocks; compiler still produces a shorter control-flow family.
// tried explicit invalid1/invalid2/invalid3 labels to preserve the three original bad-input tails; still short.
// corrected the initial signed guard to ch < 0x1B; this aligned the equality/guard prefix.
// explicit case 0 anchored the VC5 jump table at the original 0..8 range; case 7 remains an empty valid arm.
// restored TTextPanel ownership for get_text and the virtual-vptr-adjusted TInputPanel field offsets.
// restored the independent file-format dot rejection; this recovered the original +0137/+014F mbschr block.
// added MessageBeep fallbacks to all invalid tails; the natural compiler basin still merges percent/numeric play tails.
// final shared-beep goto experiment collapsed play call sites and was rolled back to the #9 codegen-best source.
// reversed percent _mbscmp operands so VC5 evaluates get_text first and pushes it before the literal, matching the original call order; diff improved 290 to 277.
// inlined typed error handling in each percent/numeric, file, and path arm; this restored the third play call, exact size, and diff 222.
// left in scratch: behavior and typed ownership are understood; remaining drift is structural, starting at the jump-table base and early block layout.
```
<!-- end-recovered:2739759b5610ce950742 -->
