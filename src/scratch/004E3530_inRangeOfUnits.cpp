// 004E3530 TribeInformationAIModule::inRangeOfUnits
// taiinfmd.cpp:7745-7769, 271 bytes
//
// int __thiscall TribeInformationAIModule::inRangeOfUnits(int param_1, int param_2, int param_3, int param_4)
// ret 10h cleanup (4 stack params + this in ecx)
//
// Flow:
// 1. Iterate over important object memory array (36-byte stride at +0x114)
// 2. For each entry:
//    - If param_1 != -1 AND entry.owner != param_1 → skip
//    - If param_1 == -1: type-check entry.owner_byte via missionObj->vtable[0x18]
//    - Look up RGE_Static_Object* via this->md->object(unit_id)
//    - If obj == NULL or state > 2 → skip
//    - Compute distance: obj->distance_to_position((float)p2, (float)p3, obj->world_z)
//    - Get range from obj->vtable[0x10C]
//    - If param_4==0 and distance < obj->master_obj->los: range = obj->master_obj->los
//    - If distance <= range → return 1
// 3. Return 0
//
// === Attempt log ===
// 1: Struct layout fixed (added gap between md+0x100 and count+0x110)
//    Prologue: push ecx, push ebx, push ebp, push esi, mov esi ecx (this→esi vs orig edi)
//    Extra xor ebx,ebx (from i=0 local), push edi delayed
//    Same TU-context register cascade pattern as other taitacmd/taiinfmd functions
// BLOCKER: TU-context register allocation (esi vs edi for this, extra ebx init)

#include <stdlib.h>

struct MasterObj {
    char _pad0[0x26];
    short hp;      // +0x26
    float los;     // +0x28 - line of sight
};

struct RGE_StaticObj {
    void* vtbl;
    int id;
    MasterObj* master;     // +0x08
    void* owner;           // +0x0C
    char _pad10[0x40 - 0x10];
    int world_z;           // +0x40
    char _pad44[0x48 - 0x44];
    unsigned char obj_state; // +0x48

    float distance_to_position(float x, float y, float z);
};

class MainDecisionModule {
public:
    char _gap00[0xF0];
    void* missionObj;   // +0xF0

    RGE_StaticObj* object(int unit_id);
};

class TribeInformationModule {
public:
    char _gap00[0x100];
    MainDecisionModule* md;            // +0x100
    char _gap104[0x110 - 0x104];
    int count;                         // +0x110
    char* importantMemory;             // +0x114 - 36-byte stride array

    int inRangeOfUnits(int param_1, int param_2, int param_3, int param_4);
};

int TribeInformationModule::inRangeOfUnits(int param_1, int param_2, int param_3, int param_4)
{
    int byte_offset = 0;
    int i = 0;

    if (this->count <= 0)
        return 0;

    do {
        if (param_1 == -1)
            goto type_check;

        {
            unsigned char owner_byte = *(this->importantMemory + byte_offset + 0x0B);
            if (owner_byte != (unsigned char)param_1)
                goto next_iteration;
        }

        if (param_1 == -1)
            goto type_check;

        goto lookup_object;

type_check:
        {
            void* mission_obj = this->md->missionObj;
            unsigned char type_byte = *(this->importantMemory + byte_offset + 0x0B);
            int type_ok = ((int (*)(void*, unsigned char))((void**)(*(void**)mission_obj))[6])(mission_obj, type_byte);
            if (type_ok == 0)
                goto next_iteration;
        }

lookup_object:
        {
            int unit_id = *(int*)(this->importantMemory + byte_offset);
            RGE_StaticObj* obj = this->md->object(unit_id);
            if (obj == 0 || obj->obj_state > 2)
                goto next_iteration;

            float dist = obj->distance_to_position((float)param_2, (float)param_3, (float)obj->world_z);

            // obj->vtable[0x10C]() - slot 67: some range function
            float range = ((float (*)())((void**)(*(void**)obj))[67])();

            if (param_4 == 0) {
                if (dist < obj->master->los) {
                    range = obj->master->los;
                }
            }

            if (dist <= range)
                return 1;
        }

next_iteration:
        i++;
        byte_offset += 0x24;
    } while (i < this->count);

    return 0;
}
