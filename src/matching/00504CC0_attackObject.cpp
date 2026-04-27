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

class RGE_Master_Static_Object {
public:
    char _gap_00[0x14];
    short object_group; // +0x14
};

class RGE_Static_Object {
public:
    char _gap_00[0x08];
    RGE_Master_Static_Object* master_obj; // +0x08
    class RGE_Player* owner;              // +0x0C
};

class RGE_Player {
public:
    char _gap_00[0x3C];
    class RGE_Game_World* world;          // +0x3C
};

class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
};

// Base class with 24 padding virtual + attackObject to push vtable slots
class UnitAIModule {
public:
    virtual void _pad00(); virtual void _pad01(); virtual void _pad02();
    virtual void _pad03(); virtual void _pad04(); virtual void _pad05();
    virtual void _pad06(); virtual void _pad07(); virtual void _pad08();
    virtual void _pad09(); virtual void _pad10(); virtual void _pad11();
    virtual void _pad12(); virtual void _pad13(); virtual void _pad14();
    virtual void _pad15(); virtual void _pad16(); virtual void _pad17();
    virtual void _pad18(); virtual void _pad19(); virtual void _pad20();
    virtual void _pad21(); virtual void _pad22(); virtual void _pad23();
    virtual int attackObject(int, int);   // vt[24]
    RGE_Static_Object* objectValue;       // +0x04
};

class TribeCivilianUnitAIModule : public UnitAIModule {
public:
    int attackObject(int, int);           // override vt[24]
    virtual int huntObject(int, int);     // vt[25]
};

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
