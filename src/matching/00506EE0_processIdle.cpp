// VA: 00506EE0 TribeFishingShipUnitAIModule::processIdle
// PDB: taiuaimd.cpp:2281-2306, 250 bytes
// __thiscall: ecx=this, one stack parameter, ret 4
//
// Attempt log:
// The parked predecessor used raw function-pointer calls and got cdecl/fastcall
// stack plumbing instead of the observed virtual thiscall calls.  This candidate
// restores the natural UnitAIModule and RGE_Static_Object virtual surfaces, named
// coordinate locals, and the direct period-style movement expression.
// Baseline: 250 bytes, 53 differing bytes; all five calls, frame, and prefix
// structure aligned.
// Named x/y offset temporaries were codegen-neutral; explicit assignments added
// stack homes and eight bytes, so they were rolled back.
// Separate speed/factor locals moved the x87 schedule and widened the function;
// the scaled return local is retained.
// Binary-required arithmetic spelling: `0.0f - offset` preserves the original
// fchs/fadd tail, while unary minus or direct subtraction lowers to fsubr.  The
// simple zero-minus form is retained because it is the only exact natural form
// found and matches the observed arithmetic topology.
// Main-agent audit restored canonical destructor slots across the player,
// object, world, and AI virtual surfaces; emitted code remains exact.

#include <math.h>

extern float DAT_005758d8; // 7.0f

class RGE_Game_World;
class RGE_Static_Object;

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;
    int computerPlayer();
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    RGE_Static_Object* object(int id);
};

#define VPAD1(n) virtual void n() = 0;
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    VPAD16(object0)
    VPAD16(object16)
    VPAD16(object32)
    VPAD8(object48)
    VPAD4(object56)
    VPAD2(object60)
    virtual float maximumSpeed() = 0; // slot 0x3F

    char gap_04[0x08];
    RGE_Player* owner; // +0x0C
    char gap_10[0x28];
    float world_x;      // +0x38
    float world_y;      // +0x3C
    int facing;         // +0x40
};

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    VPAD8(ai1)
    VPAD4(ai9)
    VPAD2(ai13)
    VPAD1(ai15)
    virtual int findTarget(int, int, int, int, int); // slot 0x10
    VPAD16(ai17)
    VPAD4(ai33)
    VPAD2(ai37)
    virtual int moveTo(float, float, int, int); // slot 0x27

    RGE_Static_Object* objectValue; // +0x04
};

class TribeFishingShipUnitAIModule : public UnitAIModule {
public:
    int processIdle(int param_1);
};

int TribeFishingShipUnitAIModule::processIdle(int param_1)
{
    if (objectValue->owner->computerPlayer()) {
        int targetID = findTarget(-1, -1, -1, -1, 0);

        if (targetID != -1) {
            RGE_Static_Object* target = objectValue->owner->world->object(targetID);

            if (target != 0) {
                float speed = objectValue->maximumSpeed() * DAT_005758d8;
                float xDiff = target->world_x - objectValue->world_x;
                float yDiff = target->world_y - objectValue->world_y;
                float distance = (float)sqrt(xDiff * xDiff + yDiff * yDiff);

                moveTo((0.0f - ((xDiff / distance) * speed)) + objectValue->world_x,
                       (0.0f - ((yDiff / distance) * speed)) + objectValue->world_y,
                       objectValue->facing, 1);
                return 6;
            }
        }
    }

    return 5;
}
