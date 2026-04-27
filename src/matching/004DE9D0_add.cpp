// VA: 004DE9D0 add
// PDB source: utmarray.h
// ManagedArray<int>::add(int)

extern "C" void* __cdecl operator_new(unsigned long sz);
extern "C" void __cdecl operator_delete(void* p);

class ManagedArrayInt {
public:
    int* value;             // +0x00
    int numberValue;        // +0x04
    int gap_08;             // +0x08 (padding/other)
    int maximumSizeValue;   // +0x0C

    int add(int val);
};

int ManagedArrayInt::add(int val)
{
    int i;

    // Check for duplicates
    for (i = 0; i < numberValue; i++) {
        if (i >= maximumSizeValue)
            break;
        if (value[i] == val)
            return 0;
    }

    // Resize if no room
    if (numberValue > maximumSizeValue - 1) {
        int newSize = numberValue + 1;
        int* newArray = (int*)operator_new(newSize * sizeof(int));
        if (newArray) {
            int j;
            for (j = 0; j < maximumSizeValue; j++) {
                if (j >= newSize)
                    break;
                newArray[j] = value[j];
            }
            operator_delete(value);
            value = newArray;
            maximumSizeValue = newSize;
        }
    }

    // Append value
    value[numberValue] = val;
    numberValue++;
    return 1;
}
