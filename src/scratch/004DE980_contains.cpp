// VA: 004DE980 ManagedArray<int>::contains (70B)
// PDB source: utmarray.h lines 86-93
// tried direct-field looping, target/max locals, and goto-style outer-not-found shaping
// VC5 keeps collapsing this into a pointer-walk basin with only ESI/EDI saves and direct `[ecx]` compares, instead of the original saved-reg set (ebx/ebp/esi/edi), stack-param reload at [esp+14], and separate `value[i]`/`*param` loads into ebx/ebp

class ManagedArray_int {
public:
    int* value;
    int numberValue;
    int gap_08;
    int maximumSizeValue;

    int contains(int* value) const;
};

int ManagedArray_int::contains(int* value) const {
    int i;
    int max;
    int* target;

    i = 0;
    if (this->numberValue <= 0) {
    