// 00416870 UnitAIModule::tradeWithObject(int, int)
// PDB: aiuaimod.cpp lines 3285-3304 (148 B, 62 asm)
// FLAGS: default
// MATCH: 0.0000% (148/148 bytes exact)
//
// Key insights:
// - tradeWithObject IS virtual (UAEH mangling), giving class a vtable pointer at +0x00
// - canTrade at vtable+0x178 = slot 94: need 94 filler virtual slots via __declspec(novtable)
// - Inverted condition: if(flag || action != 267) { if(canTrade==1) { ... } else return0; } else return0;
//   This forces VC5 to use shared return-0 epilogue instead of inline

#include "../../include/aiuaimod_context.h"

int UnitAIModule::tradeWithObject(int targetId, int flag)
{
    if (flag != 0 || this->currentActionValue != 0x267) {
        int r = this->objectValue->trade(targetId, flag);
        if (r == 1) {
            RGE_Static_Object* target =
                this->objectValue->owner->world->object(targetId);

            this->setCurrentAction(0x267);

            if (!target) {
                this->setCurrentTarget(targetId, -1, 0, 0, 0);
            } else {
                int grp = target->master_obj->object_group;
                this->setCurrentTarget(targetId, grp, target->world_x,
                                       target->world_y, target->world_z);
            }

            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}
