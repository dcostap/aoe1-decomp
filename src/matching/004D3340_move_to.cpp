// 004D3340 TRIBE_Action_Trade::move_to
// Source: tact_trd.cpp lines 669-690
// Size: 125 bytes, no EH, ret 10h
//
// Attempt log:
// Probe 1: 6.4% — wrong vtable slots + wrong store order
// Probe 2: 6.4% — still wrong vtable slots (24 dummies → slots 24-26, need 21-23)
// Probe 3: fix to 20 dummies + fix null path source order to match PDB line map

#include "..\..\include\game_globals.h"

#ifndef TACT_TRD_SHARED_CONTEXT
class RGE_Static_Object;
class RGE_Player;

// RGE_Static_Object stub
class RGE_Static_Object {
public:
    char _gap_00[0x08];
    void* master_obj;       // +0x08
    RGE_Player* owner;      // +0x0C
    short id;               // +0x10
};

// Master object stub — id at +0x10, id2 at +0xE8
class RGE_Master_Object {
public:
    char _gap_00[0x10];
    short id;               // +0x10
    char _gap_12[0xD6];
    short id2;              // +0xE8
};

// RGE_Action with full vtable (0x20 bytes, ~24 virtual methods)
// Slot layout: ~0=vdt, 1-20=dummies, 21=vt21(+0x54), 22=vt22(+0x58), 23=set_state(+0x5C)
class RGE_Action {
public:
    unsigned short action_type;     // +0x04
    char _gap_06[0x02];             // +0x06-0x07
    void* action_obj;               // +0x08
    unsigned char state;            // +0x0C
    char _gap_0D[0x07];             // +0x0D-0x13
    void* target_ptr;               // +0x14
    char _gap_18[0x08];             // +0x18-0x1F

    virtual ~RGE_Action();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void vt21(int);
    virtual void vt22(void*);
    virtual void set_state(int);
};

// TRIBE_Action_Trade — 0x48 bytes
class TRIBE_Action_Trade : public RGE_Action {
public:
    float coord_x;                  // +0x20
    float coord_y;                  // +0x24
    float coord_z;                  // +0x28
    char _gap_2C[0x04];             // +0x2C-0x2F
    void* task;                     // +0x30
    char _gap_34[0x0C];             // +0x34-0x3F
    float pick_up_x;                // +0x40
    float pick_up_y;                // +0x44

    virtual ~TRIBE_Action_Trade();
    int move_to(RGE_Static_Object* obj, float x, float y, float z);
};
#endif

int TRIBE_Action_Trade::move_to(RGE_Static_Object* obj, float x, float y, float z)
{
    if (obj != 0) {
        if (obj->owner == ((RGE_Static_Object*)this->action_obj)->owner) {
            RGE_Master_Object* objM = (RGE_Master_Object*)obj->master_obj;
            RGE_Master_Object* actM = (RGE_Master_Object*)((RGE_Static_Object*)this->action_obj)->master_obj;
            if (objM->id == actM->id2) {
                if (obj == this->target_ptr && this->state == 8) {
                    return 1;
                }
                #ifdef TACT_TRD_SHARED_CONTEXT
                this->set_target_obj2(obj);
                #else
                this->vt22(obj);
                #endif
                this->set_state(8);
                return 1;
            }
        }
    }

    // Null path: store in field-offset order
    this->coord_x = x;
    this->coord_y = y;
    this->coord_z = z;
    #ifdef TACT_TRD_SHARED_CONTEXT
    this->set_target_obj(0);
    #else
    this->vt21(0);
    #endif
    this->set_state(0xB);
    return 1;
}
