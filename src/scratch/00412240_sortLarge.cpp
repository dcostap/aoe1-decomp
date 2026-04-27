// VA: 00412240 sortLarge
// PDB source: airesitm.cpp

class ResourceItem {
public:
    char gap_0[0x0C];
    int value[8];
    int sortedValue[8];
    int sortedIndexValue[8];
    int numberValue;
};

int sortLarge(ResourceItem* this_ptr)
{
    int i;
    int pad;  // extra local to match 16-byte stack frame

    for (i = 0; i < this_ptr->numberValue; i++) {
        this_ptr->sortedValue[i] = this_ptr->value[i];
        this_ptr->sortedIndexValue[i] = i;
    }

    for (i = 0; i < this_ptr->numberValue; i++) {
        int max_idx = i;

        int j;
        for (j = i + 1; j < this_ptr->numberValue; j++) {
            if (this_ptr->sortedValue[max_idx] < this_ptr->sortedValue[j]) {
                max_idx = j;
            }
        }

        if (max_idx != i) {
            int tmp = this_ptr->sortedValue[i];
            this_ptr->sortedValue[i] = this_ptr->sortedValue[max_idx];
            this_ptr->sortedValue[max_idx] = tmp;

            tmp = this_ptr->sortedIndexValue[i];
            this_ptr->sortedIndexValue[i] = this_ptr->sortedIndexValue[max_idx];
            this_ptr->sortedIndexValue[max_idx] = tmp;
        }
    }

    return 1;
}
