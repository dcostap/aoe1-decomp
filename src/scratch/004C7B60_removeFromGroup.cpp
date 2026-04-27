// quick-win attempt log:
// target is 004C7B60 RGE_Static_Object::removeFromGroup from stat_obj.cpp
// using the real ManagedArray<int> surface at +0x64/+0x68/+0x70 so the search/shift loop
// can stay on the same fields as the oracle.
// tried direct loop/shift spellings; current blocker is VC5 register allocation (extra saved reg)
// plus branch-layout drift around the found/not-found split, so leaving this paused in scratch.

class ManagedArray_int {
public:
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

class RGE_Static_Object {
public:
    char pad_00[0x64];
    ManagedArray_int groupMembers;
    char pad_74[0x4];
    int groupCommanderValue;

    int removeFromGroup(int param_1);
};

int RGE_Static_Object::removeFromGroup(int param_1) {
    int count = groupMembers.maximumSizeValue;
    int index = 0;
    int result = 0;

    if (count > 0) {
        while (index < count) {
            if (groupMembers.value[index] == param_1) {
                break;
            }
            ++index;
        }

        if (index < count) {
            --count;
            while (index < count) {
                groupMembers.value[index] = groupMembers.value[index + 1];
                ++index;
            }

            --groupMembers.numberValue;
            if (groupMembers.numberValue < 0) {
                groupMembers.numberValue = 0;
            }
            result = 1;
        }
    }

    if (groupMembers.numberValue <= 0) {
        groupCommanderValue = -1;
    }

    return result;
}
