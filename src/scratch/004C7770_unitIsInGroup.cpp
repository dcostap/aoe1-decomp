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

// tried the straightforward count/max loop; VC5 kept changing the prolog register save order
// tried moving the array base into a local and reordering count/max loads; mismatch moved to the early base-load/register setup
// leaving this in scratch because the remaining drift is prolog/register-allocation only
int RGE_Static_Object::unitIsInGroup(int value) {
    int count = this->groupMembers.numberValue;
    int index = 0;
    int* members = this->groupMembers.value;
    int max = this->groupMembers.maximumSizeValue;

    if (count > 0) {
        while (index < max) {
            if (members[index] == value) {
                return 1;
            }
            ++index;
            if (index >= count) {
                return 0;
            }
        }
    }
    return 0;
}
