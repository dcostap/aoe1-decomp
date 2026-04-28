// VA: 005040B0 TribePreditorUnitAIModule::processNotify
// taiuaimd.cpp:216-258
//
// Attempt log:
// v0: Initial implementation - RGE_Static_Object missing vtable caused wrong offsets, fcomp branch inverted
// v1: Added virtual to RGE_Static_Object, fixed fcomp branch to !(dist>range)

#include <cstdio>

class RGE_Static_Object;
class NotifyEvent;

extern void* actionFile;  // FILE* at 0x62C4CC
extern int fprintf(void*, const char*, ...);

// String constants at fixed RVAs in .rdata
extern const char str_taiuaimd_path[];    // at 0x588AE8
extern const char str_fmt_stopObject[];   // at 0x57F964

class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;  // +0x3C
};

class RGE_Master_Static_Object {
public:
    char gap_00[0x28];
    float range;  // +0x28
};

class RGE_Static_Object {
public:
    virtual void _dummy();  // force vtable pointer at +0x00

    int id;                              // +0x04
    RGE_Master_Static_Object* master_obj; // +0x08
    RGE_Player* owner;                   // +0x0C

    float distance_to_object(RGE_Static_Object* other);  // 004C5E50
};

class NotifyEvent {
public:
    char gap_00[8];  // +0x00 to +0x07
    int mType;       // +0x08
};

// UnitAIModule base class with virtual slots needed for vtable offsets
class UnitAIModule {
public:
    // vt[0]-vt[6]: padding (0x00-0x18)
    virtual void _v00(); virtual void _v01(); virtual void _v02();
    virtual void _v03(); virtual void _v04(); virtual void _v05();
    virtual void _v06();
    // vt[7]: offset +0x1C - processNotify-related virtual
    virtual void _vt07(void* event);
    // vt[8]-vt[21]: padding (0x20-0x54)
    virtual void _v08(); virtual void _v09(); virtual void _v10();
    virtual void _v11(); virtual void _v12(); virtual void _v13();
    virtual void _v14(); virtual void _v15(); virtual void _v16();
    virtual void _v17(); virtual void _v18(); virtual void _v19();
    virtual void _v20(); virtual void _v21();
    // vt[22]: offset +0x58 - stopObject
    virtual void stopObject(int a);
    // vt[23]: offset +0x5C - doAction
    virtual void doAction(int id, int flag);

    RGE_Static_Object* objectValue;  // +0x04

    void removeCurrentTarget();
    int processNotify(NotifyEvent* event, unsigned long param_2);
};

class TribePreditorUnitAIModule : public UnitAIModule {
public:
    char gap_08[0x2C];  // +0x08 to +0x33
    int field_34;        // +0x34

    int processNotify(NotifyEvent* event, unsigned long param_2);
};

int TribePreditorUnitAIModule::processNotify(NotifyEvent* event, unsigned long param_2) {
    if (*((int*)((char*)event + 8)) == 0x1FC) {
        RGE_Static_Object* obj = this->objectValue->owner->world->object(this->field_34);

        if (obj != 0) {
            float dist = this->objectValue->distance_to_object(obj);
            if (!(dist > this->objectValue->master_obj->range)) {
                this->doAction(this->field_34, 1);
                return 3;
            }
        }

        this->removeCurrentTarget();

        if (actionFile != 0) {
            int id;
            if (this->objectValue != 0) {
                id = this->objectValue->id;
            } else {
                id = -1;
            }
            fprintf(actionFile, str_fmt_stopObject, id, str_taiuaimd_path, 250);
        }

        this->stopObject(1);
        this->_vt07((void*)event);
    }

    return UnitAIModule::processNotify(event, param_2);
}
