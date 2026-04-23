// tried the decompiler-shaped scan with a pointer walk and the exact early-out/return structure; build stayed at 64 bytes vs the expected 70
// tried adding a named return temp and then a break/return split; codegen still collapsed to the same short basin
// leaving in scratch because the blocker is still the object-size ceiling, not a proven behavior mismatch
class TacticalAIGroup {
public:
    void* vtable_ptr;
    TacticalAIGroup* next;
    TacticalAIGroup* prev;
    int idValue;
    int inUseValue;
    int typeValue;
    int subTypeValue;
    int unitsValue[40];

    int unit(int index);
};

int TacticalAIGroup::unit(int index) {
    int iVar1;
    int* piVar2;
    int iVar3;
    int value;

    iVar1 = 0;
    iVar3 = -1;
    piVar2 = this->unitsValue;
    while (true) {
        if (index + 1 <= iVar3) {
            return -1;
        }
        if (*piVar2 != -1) {
            iVar3 = iVar3 + 1;
        }
        if (iVar3 == index) {
            value = this->unitsValue[iVar1];
            return value;
        }
        iVar1 = iVar1 + 1;
        piVar2 = piVar2 + 1;
        if (0x27 < iVar1) {
            return -1;
        }
    }
}
