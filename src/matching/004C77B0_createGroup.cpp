// VA: 004C77B0 RGE_Static_Object::createGroup
// PDB source: stat_obj.cpp lines 4811-4835
//
// Initial reconstruction: create a fresh group-member list from the supplied
// object IDs, retaining valid IDs only and suppressing duplicates.
// Attempt log:
// - Capturing the outer list/count as current/remaining reproduced the original
//   parameter-home cursor updates and delayed-save prologue.
// - The un-nested dual-bound copy for-loop matched the same-TU addToGroup donor.
// - Reversing the final commander/range statements matched the original store
//   schedule; current build is an exact 255-byte match with default flags.
// Main-agent audit restored canonical object polymorphism and natural
// new[]/delete[] ownership; emitted code remains exact.

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
    virtual ~RGE_Static_Object();
    char gap_04[0x60];
    ManagedArray_int groupMembers;
    void* unitAIValue;
    int groupCommanderValue;
    int zoneMapIndex;
    float groupRangeValue;

    int createGroup(int* list, int count, int commander, float range);
};
#endif

int RGE_Static_Object::createGroup(int* list, int count, int commander, float range)
{
    if (list == 0 || count == 0) {
        return 0;
    }

    groupMembers.numberValue = 0;

    if (count > 0) {
        int* current = list;
        int remaining = count;
        do {
            int id = *current;
            if (id >= 0) {
                int number = groupMembers.numberValue;
                int i = 0;
                while (i < number) {
                    if (i >= groupMembers.maximumSizeValue) {
                        break;
                    }
                    if (groupMembers.value[i] == id) {
                        goto next;
                    }
                    i++;
                }

                if (number > groupMembers.maximumSizeValue - 1) {
                    int newMaximum = number + 1;
                    int* newValue = new int[newMaximum];
                    if (newValue != 0) {
                        i = 0;
                        for (; i < groupMembers.maximumSizeValue && i < newMaximum; i++) {
                            newValue[i] = groupMembers.value[i];
                        }
                        delete[] groupMembers.value;
                        groupMembers.value = newValue;
                        groupMembers.maximumSizeValue = newMaximum;
                    }
                }

                groupMembers.value[groupMembers.numberValue] = id;
                groupMembers.numberValue = groupMembers.numberValue + 1;
            }

        next:
            current = current + 1;
            remaining = remaining - 1;
        } while (remaining != 0);
    }

    groupCommanderValue = commander;
    groupRangeValue = range;
    return 1;
}
