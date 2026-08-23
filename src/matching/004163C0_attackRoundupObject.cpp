// VA: 004163C0 UnitAIModule::attackRoundupObject
// aiuaimod.cpp
// Retry 2026-05-20 assigned pass in progress.

#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)
#define VPAD64(n) VPAD32(n) VPAD32(n##_32)

#include "../../include/aiuaimod_context.h"

// Beta uses four arguments at weaponRange and two at canPath.
class RGE_Static_Object_Roundup_Query {
public:
    VPAD64(0) VPAD2(64) VPAD1(66)
    virtual float weaponRange(int, int, int, int); // slot 67
    VPAD16(68)
    virtual int attack(int, int);                     // slot 84
    VPAD16(85)
    virtual int canPath(int, float);                  // slot 101
};

int UnitAIModule::attackRoundupObject(int targetId) {
    if (this->currentTargetValue != targetId) {
        RGE_Static_Object* target =
            this->objectValue->owner->world->object(targetId);
        if (target != 0) {
            if (this->canAttackUnit(target)) {
                if (this->currentActionValue != -1) {
                    if (!((RGE_Static_Object_Roundup_Query*)this->objectValue)
                             ->canPath(
                                 targetId,
                                 ((RGE_Static_Object_Roundup_Query*)this->objectValue)
                                     ->weaponRange(0, 0, -1, -1))) {
                        return 0;
                    }
                }
                if (((RGE_Static_Object_Roundup_Query*)this->objectValue)
                        ->attack(targetId, 1) == 1) {
                    this->setCurrentAction(0x258);
                    this->setCurrentTarget(targetId, target->world_x,
                                           target->world_y, target->world_z);
                    return 1;
                }
            }
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
