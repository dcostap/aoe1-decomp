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

struct VisibleUnitEntry {
    int object_id;              // +0x00
    unsigned char distance;     // +0x04
    unsigned char owner;        // +0x05
    unsigned char gap_06[2];
};

extern int DAT_0087d7c8[5];
extern VisibleUnitEntry* DAT_0087d7e0[5];
extern int numberDifferentPlayerObjectsVisible;

class RGE_Game_World;
class RGE_Player;
class RGE_Master_Static_Object;
class RGE_Static_Object;

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    RGE_Static_Object* object(int id);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    int id;                         // +0x04
    char gap_08[0x34];
    RGE_Game_World* world;          // +0x3C
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x0C];
    short id;                        // +0x10
    short gap_12;
    short object_group;              // +0x14
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();

    int id;                          // +0x04
    RGE_Master_Static_Object* master_obj; // +0x08
    RGE_Player* owner;               // +0x0C
    char gap_10[0x38];
    unsigned char object_state;      // +0x48
};

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual void save(int);
    virtual void load(int);
    virtual RGE_Player* owner();
    virtual int order(int, int, int, int, float, float, float, float, int, int, int);
    virtual int notify(int, int, int, long, long, long);
    virtual int notifyCommander(int, int, int, long, long, long);
    virtual int notifyCommander(void*);
    virtual void search();           // +0x20
    virtual int closestObject(int, int, int, int, int*);

    RGE_Static_Object* objectValue;  // +0x04
    char gap_08[0x2C];
};

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
