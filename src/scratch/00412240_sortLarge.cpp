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
