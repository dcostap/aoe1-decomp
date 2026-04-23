// first pass: walk the array until maximumSizeValue, returning 1 on the first equal element and 0 otherwise
// tried direct-field looping, loop-local caching, and decompiler-shaped early exits; the remaining mismatch moved around the prolog/register basin

class ManagedArray_int {
public:
    int* value;
    int numberValue;
    int gap_08;
    int maximumSizeValue;

    int contains(int* value) const;
};

int ManagedArray_int::contains(int* value) const {
    int i = 0;
    int* values = this->value;
    int target = *value;

    if (this->numberValue > 0) {
        while (i < this->maximumSizeValue) {
            if (values[i] == target) {
                return 1;
            }
            i++;
            if (this->numberValue <= i) {
                return 0;
            }
        }
    }
    return 0;
}
