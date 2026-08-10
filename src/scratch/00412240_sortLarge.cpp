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

class ResourceItem {
public:
    char gap_0[0x0C];
    int valueValue[8];
    int sortedValue[8];
    int sortedIndexValue[8];
    int numberValue;

    int sortLarge();
};

int ResourceItem::sortLarge()
{
    int i;

    for (i = 0; i < this->numberValue; i++) {
        this->sortedValue[i] = this->valueValue[i];
        this->sortedIndexValue[i] = i;
    }

    for (i = 0; i < this->numberValue; i++) {
        int max_idx = i;

        int j = i + 1;
        if (j < this->numberValue) {
            do {
                if (this->sortedValue[j] > this->sortedValue[max_idx]) {
                    max_idx = j;
                }
                ++j;
            } while (j < this->numberValue);
        }

        if (max_idx != i) {
            int tmp = this->sortedValue[i];
            this->sortedValue[i] = this->sortedValue[max_idx];
            this->sortedValue[max_idx] = tmp;

            tmp = this->sortedIndexValue[i];
            this->sortedIndexValue[i] = this->sortedIndexValue[max_idx];
            this->sortedIndexValue[max_idx] = tmp;
        }
    }

    return 1;
}
