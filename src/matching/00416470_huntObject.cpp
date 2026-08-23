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

#include "../../include/aiuaimod_context.h"

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
        if (this->objectValue->hunt(param_1, param_2) == 1) {
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
