// VA: 00415CA0 UnitAIModule::closestObject (420B)
// aiuaimod.cpp:2606-2741
//
// Attempt log:
// - Replaced the placeholder with the binary-supported visible-unit bucket
//   scan, per-player marker array, owner/object/type filters, closest-distance
//   selection, global visibility count, and optional output conversion.
// - Baseline uses named typed visible-unit records and the period UnitAIModule
//   search/evasive virtual surfaces; retain later probe notes after compiling.
// - Reusing objectsOfPlayer[0] as a saved-this alias reproduced the oracle's
//   0x30 frame, but main-agent audit rejected that parameter-home compiler
//   steering. The living source keeps direct this access and canonical player
//   marker ownership even though VC5 uses a less favorable frame basin.
// - Reversed closest-ID/distance assignment order, reused loop indices, and
//   tested typed DAT_0087d7c8/DAT_0087d7e0 table declarations; none changed the
//   remaining schedule. Absolute-address table macros and cached self/object
//   temporaries worsened the frame or block shape and were rolled back.
// - Main-agent normalization to a nine-entry, directly indexed player-marker
//   array unexpectedly recovered the final scheduling hunk: exact 420-byte
//   MATCH with the complete 3/3 ordered call sequence.

#include <math.h>
#include "../../include/game_globals.h"
#include "../../include/aiuaimod_context.h"

extern int DAT_0087d7c8[5];
extern VisibleUnitEntry* DAT_0087d7e0[5];
extern int numberDifferentPlayerObjectsVisible;

int UnitAIModule::closestObject(int param_1, int param_2, int param_3,
                                int param_4, int* param_5) {
    int objectsOfPlayer[9];
    this->search();

    int i;
    for (i = 0; i < 9; ++i)
        objectsOfPlayer[i] = 0;

    int closestObjectID = -1;
    float closestDistance = -1.0f;

    int category;
    for (category = 0; category <= 4; ++category) {
        i = 0;
        if (DAT_0087d7c8[category] > 0) {
            do {
                objectsOfPlayer[DAT_0087d7e0[category][i].owner] = 1;
                if (this->objectValue->id !=
                    DAT_0087d7e0[category][i].object_id) {
                    RGE_Static_Object* object =
                        this->objectValue->owner->world->object(
                            DAT_0087d7e0[category][i].object_id);
                    if (object != 0 && object->object_state < 7) {
                        if ((param_2 != 0 || category == 2 || category == 1) &&
                            (param_2 != 2 || category == 4) &&
                            (param_2 != 3 || category == 1) &&
                            (param_2 != 1 || category == 3) &&
                            (param_1 == -1 ||
                             object->master_obj->object_group == param_1) &&
                            (param_4 == -1 || object->master_obj->id == param_4) &&
                            (param_3 == -1 || object->object_state == param_3)) {
                            if (closestObjectID == -1 ||
                                (float)DAT_0087d7e0[category][i].distance < closestDistance) {
                                closestObjectID = DAT_0087d7e0[category][i].object_id;
                                closestDistance = (float)DAT_0087d7e0[category][i].distance;
                            }
                        }
                    }
                }
                ++i;
            } while (i < DAT_0087d7c8[category]);
        }
    }

    numberDifferentPlayerObjectsVisible = 0;
    for (i = 1; i < 9; ++i) {
        if (objectsOfPlayer[i] == 1)
            ++numberDifferentPlayerObjectsVisible;
    }

    if (param_5 != 0)
        *param_5 = (int)closestDistance;
    return closestObjectID;
}
