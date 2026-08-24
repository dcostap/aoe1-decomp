// ResourceItem::sortLarge()
// VA: 00412240 | airesitm.cpp:200-327
//
// ACCEPTED_DRIFT REVIEW (main-drift-00412240): The rebuilt function keeps the
// original size, frame, CFG, loop bounds, array accesses, swaps, and return.
// One SIB byte differs at the maximum-element compare.  Both encodings address
// sortedValue[max_idx].

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
