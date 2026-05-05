// VA: 004F1390
// ManagedArray<int>::remove(int)
// PDB source: utmarray.h lines 120-133
// Size: 89 bytes (0x59), 40 asm lines
// Exact match: 0.0000%

// Key insights:
// - Search loop: `for (; i < max; ++i)` with direct array access
//   eliminates the loop peeling that do-while/while+pointer patterns trigger
// - Shift loop: `this->value[i] = this->value[i + 1]` uses post-increment,
//   generating the correct two-address `mov [edx+eax*4-4],esi` form
// - No outer guard: the for-loop condition handles count<=0 naturally

class ManagedArray_int {
public:
    int* value;             // +0
    int numberValue;        // +4
    int desiredNumberValue; // +8
    int maximumSizeValue;   // +0C

    int remove(int v);
};

int ManagedArray_int::remove(int v) {
    int i = 0;
    int max = this->maximumSizeValue;

    for (; i < max; ++i) {
        if (this->value[i] == v) break;
    }

    if (i >= max) return 0;

    --max;
    if (i < max) {
        do {
            this->value[i] = this->value[i + 1];
            ++i;
        } while (i < this->maximumSizeValue - 1);
    }

    int n = this->numberValue - 1;
    this->numberValue = n;
    if (n < 0) this->numberValue = 0;
    return 1;
}
