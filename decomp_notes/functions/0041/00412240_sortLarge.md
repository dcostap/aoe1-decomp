# Function notes: 00412240 `sortLarge`

## Recovered attempt history

<!-- recovered:4beba2a8bb88a82fc2b1 -->
### `0fcd8bd9fa3c` `src/scratch/00412240_sortLarge.cpp:1-62`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00412240 sortLarge
// PDB source: airesitm.cpp
// Attempt log:
// - Baseline: restoring the proven ResourceItem member ABI and named arrays
//   matched the prologue, first copy loop, and swap/tail islands; remaining
//   drift is the inner selection-loop cursor setup and a 9-byte size deficit.
// - Try a named candidate pointer for the inner scan, matching the binary's
//   separate current-element cursor rather than indexing both operands.
// - Moving the cursor initialization inside the j-bound guard and spelling
//   `*current > sortedValue[max_idx]` recovered exact size/frame and all later
//   blocks; the remaining drift is the 7-byte cursor setup and one SIB byte.
// - Preincrement, sorted aliases, register/volatile qualifiers, raw offset
//   views, and pointer-local variants were tested; none improved the 14-byte
//   positional mismatch. Leave the natural cursor source in scratch.
// - Fresh pass: function-scope local promotion, exact leading ResourceItem
//   fields/polymorphic context, indexed cursor spellings, and a 16-case
//   candidate/max-expression lab all emitted the same 14-byte mismatch;
//   explicit outer-cursor and narrow alias forms regressed the structural basin.
// - Final clean source retained: mismatch is still limited to the 7-byte inner
//   cursor setup order plus the one SIB base/index byte at the maximum compare.
// - Normalization: removed the unused `pad` local that had preserved the old
//   0x10 frame only as compiler steering; the prior 200-byte/14-byte result
//   remains diagnostic history, not living source.
// - Fresh bounded pass: reversed pointer-add operands, added a per-iteration
//   maximum pointer/reference, reordered inner declarations, and ran a
//   20-case cursor-init/max-access lab; all retained the same 200-byte,
//   14-byte result (the lab formed one emitted-code group).
// - A guarded top-tested `for` regressed to 208 bytes/135 diff; an integer
//   byte-address cursor and reversed comparison operands regressed structurally
//   (200/14 after restore and 191/146 respectively). Declaration-order and
//   pointer-vs-int probes were nonproductive.
// - Fresh pass exhausted at 10 meaningful hypotheses; clean natural source
//   restored. Remaining evidence is still the setup order
//   `mov ebx,[esp+18] / lea ebp,[esi+4]` versus rebuilt cursor-first, plus
//   the SIB base/index byte at the maximum compare.
// - Fresh TU lane: the direct indexed candidate scan is a period-plausible
//   alternative to the named cursor; try the oracle's current-value-first
//   comparison while retaining the natural `j` induction.
// - The direct form matched every byte except the max-load SIB base/index;
//   a narrow named array alias changed the pointer/register basin and was
//   rolled back, so retain direct member ownership.
// - The direct-address spelling is now isolated to the one SIB byte; a
//   binary-backed explicit byte-offset max cursor changed frame/control flow,
//   so restore the simpler named-member expression.
// - Fresh lane result: direct indexed current-first source is 200 bytes with
//   exact size/frame/CFG and one mismatch (`3b6c0b` vs oracle `3b6c19` at the
//   max compare). Five max-address spellings formed one codegen group.
// - A narrow RHS alias regressed to 204/110 and the explicit byte-offset
//   cursor to 229/220 with a 0x1C frame; both were rolled back. An int-view
//   object-base spelling, four exact-offset leading type surfaces, and the
//   commuted subscript were codegen-neutral. Final clean source stays typed
//   and direct; remaining drift is only SIB base/index identity.
// - Focused SIB lab: fourteen direct/max-address spellings (parentheses,
//   pointer-add, raw-offset, int-view, and array-view forms) all emitted the
//   same 200-byte result with 3b6c0b at +0068; no source term-order variant
//   selected the oracle's 3b6c19 byte.
// - Declaration/initialization-order, index-width, pointer-arithmetic, and
//   arithmetic-address labs likewise left the 200-byte group unchanged (the
//   narrow index and function-style declaration outliers regressed structurally).
//   Canonical gap/field/virtual and full ResourceItem declaration surfaces were
//   also codegen-neutral. Keep the direct indexed source authoritative; the
//   remaining one-byte base/index choice is now an exhausted VC5 encoding axis.
```
<!-- end-recovered:4beba2a8bb88a82fc2b1 -->

## Earlier notes from `decomp_notes/functions/0041/00412240_sortLarge.md`

This section is historical. Use the status query for current state.

## 00412240 `ResourceItem::sortLarge`

- PDB source: `airesitm.cpp`, lines 200 to 327.
- Original size: 200 bytes.

The method copies active values into the sorted lanes. It then uses descending
selection sort. It swaps each value and its original index together.

A prior isolated build differed by one SIB byte at the maximum-value compare.
Both forms addressed `sortedValue[maxIndex]`. The grouped result later reported
an exact owner. The merged source keeps the direct typed selection sort. It does
not retain pointer or register-control forms.

### Current module result

The focused module check reports `MISMATCH`. Both bodies are 200 bytes. One
positional byte differs at offset 104. The mismatch is a register recolor:
the rebuilt body swaps the `EBX` and `ECX` roles for this compare form.

The natural direct typed selection sort remains the source body. This owner is
scratch and is not registered as an exact translation-unit owner.
