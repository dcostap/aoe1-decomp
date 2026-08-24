#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
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
#endif

int RGE_Static_Object::unitIsInGroup(int value) {
    int count = this->groupMembers.numberValue;
    int index = 0;

    if (count > 0) {
        for (; index < count; index++) {
            if (index >= this->groupMembers.maximumSizeValue) {
                goto not_found_shared;
            }
            if (this->groupMembers.value[index] == value) {
                return 1;
            }
        }
    }
    return 0;

not_found_shared:
    return 0;
}
