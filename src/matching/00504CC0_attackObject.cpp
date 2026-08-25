// VA: 00504CC0 | TribeCivilianUnitAIModule::attackObject(int,int) | taiuaimd.cpp:726-741 | 90 bytes
//
// Attempt log:
// [1] UnitAIModule had no virtual -> vtable offset wrong; 16-bit cmp; huntObject at vt[0].
// [2] Fixed vtable with virtual attackObject; cast to int for 32-bit cmp.
//     VC5 doesn't support __thiscall on function pointers.
// [3] Natural virtual huntObject call. All matches except huntObject at vt[1] not vt[25].
//     1 byte diff at offset 84: call [edx+04h] vs call [edx+64h].
// [4] Add 24 padding virtual functions to push huntObject to vt[25].

#include "../../include/game_types.h"

#ifndef TAIUAIMD_COMPLETE_TU
#include "../../include/taiuaimd_context.h"

class TribeCivilianUnitAIModule : public UnitAIModule {
public:
    virtual int attackObject(int, int);
    virtual int huntObject(int, int);
};
#endif

int TribeCivilianUnitAIModule::attackObject(int targetId, int param2) {
    RGE_Static_Object* obj = objectValue->owner->world->object(targetId);
    if (obj == 0) {
        return 0;
    }

    int group = (int)obj->master_obj->object_group;
    if (group == 9 || group == 10 || group == 15) {
        return this->huntObject(targetId, param2);
    }

    return UnitAIModule::attackObject(targetId, param2);
}
