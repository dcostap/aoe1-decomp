// VA: 004C79D0 RGE_Static_Object::commanderAddToGroup
// Source: stat_obj.cpp lines 4885-4923 (399 bytes)
//
// Baseline kept the packet's proven ownership: groupMembers is the
// ManagedArray<int> at +0x64, owner->world resolves member IDs, and this
// method propagates the command before createGroup rebuilds the target group.
// The former file used raw cursor arithmetic.  This pass restores typed
// ManagedArray ownership and ordinary member indexing.
//
// Probe notes:
// - Typed ManagedArray operator[] preserved both observed growth paths and
//   improved edit/resync similarity from 56.89% to 81.70%.
// - A block or function-scope temp-base pointer was optimized away or moved
//   EBP into the parameter path; it did not reproduce the saved unitObj home.
// - temp[26] is the smallest behavior-safe array: slot zero stores the target
//   object and at most 25 member IDs follow it.  Larger arrays only steer the
//   frame and are not retained.
// - A natural member-list pointer, an outer count local, and block-scoped list
//   pointer all changed the stack basin without reproducing the saved unitObj
//   home.  A 27-entry temporary restored the 0x70 frame but shifted temp[0].
// - Reordered declarations and a typed unitObj/local_70 mirror worsened the
//   prologue or promoted EBP.  Restore the typed 26-entry source below.
// - This bounded retry used 6 meaningful probes.  Calls and CFG behavior remain
//   aligned; the remaining gap is VC5 local-slot and block scheduling drift.

void* __cdecl operator_new(unsigned int size);
void __cdecl operator_delete(void* ptr);

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
            int* new_value = (int*)operator_new(new_size * 4);
            if (new_value != 0) {
                for (int i = 0;
                     i < this->maximumSizeValue && i < new_size; i++) {
                    new_value[i] = this->value[i];
                }
                operator_delete(this->value);
                this->value = new_value;
                this->maximumSizeValue = new_size;
            }
        }
        return this->value[index];
    }
};

class RGE_Static_Object {
public:
    void* vptr;
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
    int temp[26];

    temp[0] = (int)this->owner->world->object(id);
    if (temp[0] == 0) {
        return 0;
    }

    if (this->groupMembers.numberValue >= 25) {
        return 0;
    }

    int i = 0;
    if (this->groupMembers.numberValue > 0) {
        do {
            temp[i + 1] = this->groupMembers[i];
            if (temp[i + 1] != this->id) {
                RGE_Static_Object* object =
                    this->owner->world->object(this->groupMembers[i]);
                if (object != 0) {
                    object->addToGroup(id, range);
                }
            }
            ++i;
        } while (i < this->groupMembers.numberValue);
    }

    temp[i + 1] = id;
    this->addToGroup(id, range);
    ((RGE_Static_Object*)temp[0])->createGroup(temp + 1, i + 1, this->id,
                                                range);
    return 1;
}
