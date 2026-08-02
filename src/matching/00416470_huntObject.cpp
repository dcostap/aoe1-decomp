// VA: 00416470 huntObject (211B)
// aiuaimod.cpp:3134-3160
//
// Binary-supported source reconstruction:
// - objectValue is at +04 and currentActionValue at +30.
// - UnitAIModule::stopObject is virtual slot +58.
// - objectValue's can-hunt operation is virtual slot +164.
// - A successful lookup supplies target group and world coordinates to the
//   five-argument setCurrentTarget helper; a null lookup uses -1 and zeros.
//
// Attempt log:
// - Baseline: natural typed reconstruction reached the exact size/frame/call
//   surface; only the logging null-test block was laid out with the opposite
//   branch polarity.
// - Inverted the logging test to keep the non-null ID load in the fallthrough
//   block and the null -1 assignment in the late JE target. MATCH.

#include <stdio.h>

extern FILE* actionFile;

#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD64(n) VPAD16(n) VPAD16(n##_16) VPAD32(n##_32)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)

class RGE_Master_Static_Object {
public:
    char gap_00[0x14];
    short object_group;
};

class RGE_Static_Object;

class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
};

class RGE_Static_Object {
public:
    VPAD64(0)
    VPAD16(64)
    VPAD8(80)
    virtual void vpad88();
    virtual int canHunt(int targetId, int flag);

    int id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x38 - 0x10];
    int world_x;
    int world_y;
    int world_z;
};

class UnitAIModule {
public:
    VPAD16(0)
    VPAD4(16)
    VPAD2(20)
    virtual void stopObject(int flag);

    RGE_Static_Object* objectValue;
    char gap_08[0x30 - 0x08];
    int currentActionValue;

    void setCurrentAction(int action);
    void setCurrentTarget(int id, int group, int x, int y, int z);
    int huntObject(int param_1, int param_2);
};

int UnitAIModule::huntObject(int param_1, int param_2) {
    if (param_2 != 0 || this->currentActionValue != 0x265) {
        if (actionFile != 0) {
            long object_id;
            if (this->objectValue != 0) {
                object_id = this->objectValue->id;
            } else {
                object_id = -1;
            }
            fprintf(actionFile,
                    "#%d call stopObject %s %d\n",
                    object_id,
                    "C:\\msdev\\work\\age1_x1\\aiuaimod.cpp",
                    0xC48);
        }

        this->stopObject(1);
        if (this->objectValue->canHunt(param_1, param_2) == 1) {
            RGE_Static_Object* target =
                this->objectValue->owner->world->object(param_1);
            this->setCurrentAction(0x265);

            if (target == 0) {
                this->setCurrentTarget(param_1, -1, 0, 0, 0);
            } else {
                this->setCurrentTarget(param_1,
                                       (int)target->master_obj->object_group,
                                       target->world_x,
                                       target->world_y,
                                       target->world_z);
            }
            return 1;
        }
    }
    return 0;
}

#undef VPAD64
#undef VPAD32
#undef VPAD16
#undef VPAD8
#undef VPAD4
#undef VPAD2
#undef VPAD1
