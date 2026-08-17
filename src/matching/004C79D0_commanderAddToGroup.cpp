// VA: 004C79D0 RGE_Static_Object::commanderAddToGroup
// Source: stat_obj.cpp lines 4885-4923 (399 bytes)
//
// The binary uses groupMembers as a ManagedArray<int> at +0x64.  The world
// lookup returns a typed RGE_Static_Object pointer.  The local list stores
// existing member IDs, then the new ID, before createGroup rebuilds the group.
//
// Recovery notes:
// - The original has two inline ManagedArray operator[] growth paths.  Keep
//   both reads separate, even though they use the same loop index.
// - A separate typed unitObject and zero-based temp[25] list recover the
//   original 0x70 frame and local ownership.  The group reference keeps the
//   duplicate typed lookup in the original register basin.
// - Raw cursor, shifted-array, volatile, synthetic-padding, and parameter-home
//   variants were rejected by policy or by the emitted code.
// - Exact validation: 399 bytes, 9 ordered calls, frame 0x70, diff 0.

class RGE_Static_Object;

class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world; // +0x3C
};

class ManagedArray_int {
public:
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    int& operator[](int index) {
        if (index > this->maximumSizeValue - 1) {
            int new_size = index + 1;
            int* new_value = new int[new_size];
            if (new_value != 0) {
                for (int i = 0;
                     i < this->maximumSizeValue && i < new_size; i++) {
                    new_value[i] = this->value[i];
                }
                delete[] this->value;
                this->value = new_value;
                this->maximumSizeValue = new_size;
            }
        }
        return this->value[index];
    }
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int id;
    char gap_08[4];
    RGE_Player* owner; // +0x0C
    char gap_10[0x54];
    ManagedArray_int groupMembers; // +0x64

    int addToGroup(int id, float range);
    int createGroup(int* members, int count, int commanderId, float range);
    int commanderAddToGroup(int id, float range);
};

int RGE_Static_Object::commanderAddToGroup(int id, float range)
{
    RGE_Static_Object* unitObject = this->owner->world->object(id);
    int temp[25];
    ManagedArray_int& group = this->groupMembers;
    if (unitObject == 0) {
        return 0;
    }

    if (group.numberValue >= 25) {
        return 0;
    }

    int i = 0;
    if (group.numberValue > 0) {
        do {
            int member = group[i];
            temp[i] = member;
            if (member != this->id) {
                RGE_Static_Object* object =
                    this->owner->world->object(group[i]);
                if (object != 0) {
                    object->addToGroup(id, range);
                }
            }
            ++i;
        } while (i < group.numberValue);
    }

    temp[i] = id;
    this->addToGroup(id, range);
    unitObject->createGroup(temp, i + 1, this->id, range);
    return 1;
}
