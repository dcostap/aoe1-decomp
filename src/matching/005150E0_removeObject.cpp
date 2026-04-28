// TRIBE_Player::removeObject
// VA: 005150E0
// tplayer.cpp:2003-2013
// MATCH: 0.0000% diff, 0 relocations masked

#include "../../include/game_globals.h"

class RGE_Static_Object {
public:
    char gap_00[4];
    int obj_id;            // +0x04
    void* master_obj;      // +0x08
};

class RGE_Player {
public:
    void removeObject(RGE_Static_Object* obj, int param_2, int param_3, void* param_4);
};

// Class with virtual method at vtable offset 0x44
class PlayerAI {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(void);
    virtual void vf24(void);
    virtual void vf28(void);
    virtual void vf2C(void);
    virtual void vf30(void);
    virtual void vf34(void);
    virtual void vf38(void);
    virtual void vf3C(void);
    virtual void vf40(void);
    virtual void removeObjectCallback(int obj_id);
};

class TRIBE_Player : public RGE_Player {
public:
    char gap_00[0x238];
    PlayerAI* playerAI;    // +0x238

    void removeObject(RGE_Static_Object* obj, int param_2, int param_3, void* param_4);
};

void TRIBE_Player::removeObject(RGE_Static_Object* obj, int param_2, int param_3, void* param_4) {
    RGE_Player::removeObject(obj, param_2, param_3, param_4);

    if (this->playerAI) {
        short grp = *(short*)((char*)obj->master_obj + 0x14);
        if (grp != 0x0B && obj->obj_id >= 0) {
            this->playerAI->removeObjectCallback(obj->obj_id);
        }
    }
}
