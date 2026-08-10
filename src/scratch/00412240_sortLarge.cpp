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

        int* current;
        int j = i + 1;
        if (j < this->numberValue) {
            current = this->sortedValue + i + 1;
            do {
                if (*current > this->sortedValue[max_idx]) {
                    max_idx = j;
                }
                ++j;
                ++current;
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
