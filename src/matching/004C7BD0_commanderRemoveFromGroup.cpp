// VA: 004C7BD0 RGE_Static_Object::commanderRemoveFromGroup
// Source: stat_obj.cpp lines 4944-4967
//
// Attempt log:
// - Baseline reconstruction follows the same-TU commanderDestroyGroup array
//   growth idiom and keeps the reciprocal group-member removal inline.
// - Added the proven four-byte gap between groupMembers and the commander
//   value; this corrected the +78 commander field without changing the array
//   layout.
// - Replaced the reciprocal search do/while with the donor's while(1) form,
//   breaking on found or exhausted; this restored the original CFG and exact
//   268-byte output.
// - Main-agent audit restored canonical object/player/world polymorphism and
//   natural new[]/delete[] ownership; emitted code remains exact.

#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class RGE_Static_Object;

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    RGE_Static_Object* object(int id);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;
};

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
    int id;
    char gap_08[0x04];
    RGE_Player* owner;
    char gap_10[0x54];
    ManagedArray_int groupMembers;
    char gap_74[0x04];
    int groupCommanderValue;

    int commanderDestroyGroup();
    int removeFromGroup(int id);
    int commanderRemoveFromGroup(int id);
};
#endif

int RGE_Static_Object::commanderRemoveFromGroup(int id)
{
    if (id == this->id && this->id == this->groupCommanderValue) {
        return this->commanderDestroyGroup();
    }

    int i = 0;
    if (this->groupMembers.numberValue > 0) {
        do {
            if (i > this->groupMembers.maximumSizeValue - 1) {
                int newMax = i + 1;
                int* newValue = new int[newMax];
                if (newValue != 0) {
                    int j = 0;
                    if (this->groupMembers.maximumSizeValue > 0) {
                        do {
                            if (j < newMax) {
                                ++j;
                                newValue[j - 1] = this->groupMembers.value[j - 1];
                            } else {
                                break;
                            }
                        } while (j < this->groupMembers.maximumSizeValue);
                    }
                    delete[] this->groupMembers.value;
                    this->groupMembers.value = newValue;
                    this->groupMembers.maximumSizeValue = newMax;
                }
            }

            RGE_Static_Object* object = this->owner->world->object(this->groupMembers.value[i]);
            if (object != 0 && object->id != this->id) {
                int max = object->groupMembers.maximumSizeValue;
                int j = 0;
                if (max > 0) {
                    int* p = object->groupMembers.value;
                    while (1) {
                        if (*p == id) {
                            break;
                        }
                        ++j;
                        ++p;
                        if (j < max) {
                            continue;
                        }
                        break;
                    }
                }

                if (j < max) {
                    if (j < max - 1) {
                        do {
                            object->groupMembers.value[j] = object->groupMembers.value[j + 1];
                            ++j;
                        } while (j < object->groupMembers.maximumSizeValue - 1);
                    }

                    int newCount = object->groupMembers.numberValue - 1;
                    object->groupMembers.numberValue = newCount;
                    if (newCount < 0) {
                        object->groupMembers.numberValue = 0;
                    }
                }
            }

            ++i;
        } while (i < this->groupMembers.numberValue);
    }

    this->removeFromGroup(id);
    return 1;
}
