// attempt 1: direct ManagedArray<int>::remove with the exact element/count offsets from the packet
// second pass: tried a few natural loop spellings; the remaining gap moved into the prolog / saved-register basin
// target shape: linear search in value[0..maximumSizeValue), shift down on hit, decrement numberValue and clamp to 0
// paused here because the current mismatch is now prolog/register allocation rather than the element-shift behavior

typedef unsigned int uint;

class ManagedArray_int {
public:
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    int remove(int value);
};

int ManagedArray_int::remove(int value) {
    int index;
    int max;

    index = 0;
    max = this->maximumSizeValue;
    if (0 < max) {
        int* current = this->value;
        for (; index < max; ++index, ++current) {
            if (*current == value) {
                break;
            }
        }
    }

    if (max <= index) {
        return 0;
    }

    if (index < max - 1) {
        int* current = this->value;
        for (; index < this->maximumSizeValue - 1; ++index) {
            current[index] = current[index + 1];
        }
    }

    max = this->numberValue - 1;
    this->numberValue = max;
    if (max < 0) {
        this->numberValue = 0;
    }
    return 1;
}
