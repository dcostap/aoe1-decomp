// VA: 00405850 RGE_Action_Move_To::update
// PDB source: act_move.cpp
//
// Attempt log:
// - 1st pass: extern "C" free function -> 686/890 diff
// - 2nd pass: member function, extern function pointers -> 717/890 diff
// - 3rd pass: direct extern declarations

#include <stdlib.h>
#include <math.h>

extern "C" {
    void* RGE_Game_World_object(void* world, int id);
    int inRange(void*, void*, float);
    long __cdecl __ftol(double x);
    void RGE_Action_setTargetObj(void* action, int zero);
    void RGE_Action_setTargetObj2(void* action, int zero);
    void RGE_Action_setState(void* action, int new_state);
    void playVt(void* obj, int, int, int, int, int, int);
    void setGoal(void* mo, float x, float y, float speed);
    void setActionRange(void* mo, float range);
    void setTargetID(void* mo, int id);
    void setTargetRadius(void* mo, float r1, float r2);
    int findPath(void* mo);
    int doMove(void* mo);
    void setFinalWaypoint(void* mo);
    void setUserWaypoint(void* mo, char* buf, int zero);
    void clearTarget(void* mo, int zero);
}

class RGE_Action {
public:
    void* vtable;              // +0x00
    short action_type;         // +0x04
    char gap_06_07[2];        // +0x06
    void* obj;                 // +0x08
    unsigned char state;       // +0x0C
    char pad_0D_0F[3];        // +0x0D
    void* target_obj;          // +0x10
    void* target_obj2;         // +0x14
    int targetID;              // +0x18
    int target2ID;             // +0x1C
    float target_x;            // +0x20
    float target_y;            // +0x24
    float target_z;            // +0x28
    float timer;               // +0x2C
    void* task;                // +0x30
    void* sub_actions;         // +0x34
    void* sprite;              // +0x38
    unsigned char subActionValue;  // +0x3C
    char pad_3D_3F[3];        // +0x3D
    float range;               // +0x40

    RGE_Action(void* obj, int type);
    unsigned char update();
};

unsigned char RGE_Action::update()
{
    // targetID check
    if (this->targetID != -1) {
        void* gw = *(void**)(*(char**)((char*)this->obj + 0xC) + 0x3C);
        void* o = RGE_Game_World_object(gw, this->targetID);
        if (o == 0) {
            RGE_Action_setTargetObj(this, 0);
            goto LAB;
        }
    }

    // target2ID
    if (this->target2ID != -1) {
        void* gw = *(void**)(*(char**)((char*)this->obj + 0xC) + 0x3C);
        void* o = RGE_Game_World_object(gw, this->target2ID);
        if (o == 0)
            RGE_Action_setTargetObj2(this, 0);
    }

    // target state
    if (this->target_obj != 0 && *(unsigned char*)((char*)this->target_obj + 0x48) >= 7) {
        RGE_Action_setTargetObj(this, 0);
        goto LAB;
    }

    // state switch
    switch (this->state) {
        case 1: return 1;
        case 3: break;
        case 4: goto S4;
        case 13: goto SD;
        default: return 0;
    }

    // state 3
    if (this->target_obj != 0) {
        if (inRange(this->target_obj, this->target_obj, this->range)) {
            RGE_Action_setState(this, 1);
            if (this->subActionValue == 0) {
                playVt(this->obj, *(int*)((char*)this->obj + 4), *(int*)((char*)this->obj + 4), 0x1FA, 0x262, 0, 0);
            }
            clearTarget(this->obj, 0);
            *(int*)((char*)this->obj + 0x58) = 0;
            return 2;
        }
    }

    if (this->target_obj != 0) {
        this->target_x = *(float*)((char*)this->target_obj + 0x38);
        this->target_y = *(float*)((char*)this->target_obj + 0x3C);
        this->target_z = *(float*)((char*)this->target_obj + 0x40);
    }

    setGoal(this->obj, this->target_x, this->target_y, 1.0f);

    {
        char buf[3];
        buf[0] = (char)__ftol((double)this->target_x);
        buf[1] = (char)__ftol((double)this->target_y);
        buf[2] = (char)__ftol((double)this->target_z);

        if (*(unsigned char*)((char*)this->obj + 0x174) == 0) {
            setUserWaypoint(this->obj, buf, 0);
            setFinalWaypoint(this->obj);
        }
    }

    setActionRange(this->obj, this->range);

    if (this->target_obj != 0) {
        setTargetID(this->obj, *(int*)((char*)this->target_obj + 4));
        void* inner = *(void**)((char*)this->target_obj + 8);
        setTargetRadius(this->obj, *(float*)((char*)inner + 0x30), *(float*)((char*)inner + 0x34));
    } else {
        setTargetID(this->obj, -1);
        setTargetRadius(this->obj, 0.0f, 0.0f);
    }

    if (findPath(this->obj) == 0) {
        RGE_Action_setState(this, 4);
        return 0;
    }
    return 0;

S4:
    if (this->target_obj != 0) {
        float xd = this->target_x - *(float*)((char*)this->target_obj + 0x38);
        float yd = this->target_y - *(float*)((char*)this->target_obj + 0x3C);
        if (xd < -1.0f || xd > 1.0f || yd < -1.0f || yd > 1.0f)
            goto S4B;
    }

    if (doMove(this->obj) == 0) {
        RGE_Action_setState(this, 1);
        goto SD;
    }
    if (doMove(this->obj) == 2)
        goto S4C;
    return 0;

S4B:
    if (this->target_obj != 0) {
        float xd = this->target_x - *(float*)((char*)this->target_obj + 0x38);
        float yd = this->target_y - *(float*)((char*)this->target_obj + 0x3C);
        if (xd >= -1.0f && xd <= 1.0f && yd >= -1.0f && yd <= 1.0f)
            goto S4D;
    }
    if (doMove(this->obj) == 0) {
        RGE_Action_setState(this, 1);
        goto SD;
    }
    if (doMove(this->obj) != 2)
        return 0;

S4C:
    if (this->target_obj != 0) {
        float xd = this->target_x - *(float*)((char*)this->target_obj + 0x38);
        float yd = this->target_y - *(float*)((char*)this->target_obj + 0x3C);
        if (!(xd < -1.0f || xd > 1.0f || yd < -1.0f || yd > 1.0f))
            goto S4D;
    }
    goto SD2;

S4D:
    playVt(this->obj, *(int*)((char*)this->obj + 4), *(int*)((char*)this->obj + 4), 0x1FC, 0x262, 0, 0);
    RGE_Action_setState(this, 3);
    RGE_Action_setState(this, 3);
    return 0;

SD2:
SD:
    if (this->subActionValue == 0) {
        playVt(this->obj, *(int*)((char*)this->obj + 4), *(int*)((char*)this->obj + 4), 0x1F9, 0x262, 0, 0);
    }
    RGE_Action_setState(this, 1);
    return 3;

LAB:
    if (this->subActionValue == 1)
        return 5;
    playVt(this->obj, *(int*)((char*)this->obj + 4), *(int*)((char*)this->obj + 4), 0x1FB, 0x262, this->targetID, 0);
    return 4;
}
