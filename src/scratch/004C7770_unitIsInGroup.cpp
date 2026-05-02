class ManagedArray_int {
public:
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

class RGE_Static_Object {
public:
    char gap_00[0x64];
    ManagedArray_int groupMembers;

    int unitIsInGroup(int value);
};

// tried straightforward count/max loop forms and direct-member variants; VC5 kept collapsing
// to a different family that omits the early `push ebx` and adds an extra `test max,max`
// before entering the scan. Best shape keeps the main compare/load body close but still differs
// in prolog/save order and in using jge/jmp structure instead of the original top-tested loop.
int RGE_Static_Object::unitIsInGroup(int value) {
    int count = this->groupMembers.numberValue;
    int index = 0;

    if (count > 0) {
        while (1) {
            if (index >= this->groupMembers.maximumSizeValue) {
                break;
            }
            if (this->groupMembers.value[index] == value) {
                return 1;
            }
            index++;
            if (index < count) {
                continue;
            }
            return 0;
        }
    }
    return 0;
}
