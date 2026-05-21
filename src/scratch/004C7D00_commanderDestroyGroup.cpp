// 004C7D00 RGE_Static_Object::commanderDestroyGroup
// Source: stat_obj.cpp lines 4988-5005
// Attempt log:
// Probe 1: raw-offset ManagedArray growth and recursive destroy; wrong EBX/EBP roles and copy-loop shape.
// Probe 2: decompiler-shaped iVar locals and post-increment copy loop; worse, still EBP outer index.
// Probe 3: register-qualified outer index; no change.
// Probe 4: top-declared newMax before outer i to probe register coloring.
// Probe 5: unsigned outer index probe; only changes signed branches, still EBP outer index.
// Probe 6: temporary /O1 flag probe produced too-small 150B object; removed flag.
// Probe 7: operator_new/operator_delete helper names instead of C++ operators; no register-family change.
// Probe 8: /O2 without /Oy flag; no improvement.
// Probe 9: /Ob0 flag; no improvement.
// Probe 10: /G5 flag; no improvement.
// GIVEUP: best C source still chooses EBP for outer group index and EBX for newMax, while original uses EBX for outer index and EBP for newMax with delayed EBP save. This causes broad register/prologue and loop-body drift, not accepted-drift safe.

void* __cdecl operator_new(unsigned int);
void __cdecl operator_delete(void*);
class RGE_Game_World { public: void* object(int id); };
class RGE_Player { public: char gap_00[0x3C]; RGE_Game_World* world; };
class RGE_Static_Object {
public:
    char gap_00[0x04]; int id; char gap_08[0x04]; RGE_Player* owner;
    char gap_10[0x54]; int* group_value; int group_number; char gap_6C[0x04]; int group_max;
    int commanderDestroyGroup(); int destroyGroup();
};

int RGE_Static_Object::commanderDestroyGroup()
{
    int newMax;
    int i = 0;
    if (this->group_number > 0) {
        do {
            if (i > this->group_max - 1) {
                newMax = i + 1;
                int* newValue = (int*)operator_new(i * 4 + 4);
                if (newValue != 0) {
                    int j = 0;
                    if (this->group_max > 0) {
                        do {
                            if (j >= newMax)
                                break;
                            newValue[j] = this->group_value[j];
                            ++j;
                        } while (j < this->group_max);
                    }
                    operator_delete(this->group_value);
                    this->group_value = newValue;
                    this->group_max = newMax;
                }
            }
            RGE_Static_Object* obj = (RGE_Static_Object*)this->owner->world->object(this->group_value[i]);
            if (obj != 0 && obj->id != this->id)
                obj->destroyGroup();
            ++i;
        } while (i < this->group_number);
    }
    this->destroyGroup();
    return 1;
}
