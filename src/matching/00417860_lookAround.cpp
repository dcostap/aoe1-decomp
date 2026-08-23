// VA: 00417860 UnitAIModule::lookAround
// PDB: aiuaimod.cpp lines 3949-3987
// Attempt: canonical visible-unit bucket scan; tuning against VC5 codegen.
// Exact: the terminal count/list globals are the last elements of the five-bucket
// VisibleUnitList_Size/VisibleUnitList arrays established by GetVisibleUnits; this
// method scans the two terminal buckets with the binary-proven byte offsets.

#include "../../include/game_globals.h"
#include "../../include/aiuaimod_context.h"

int __cdecl debug_rand(char* file, int line);

void UnitAIModule::lookAround()
{
    RGE_Game_World* world;
    int ownerID;

    this->search();

    int obj_id = this->objectValue->id;
    RGE_Player* owner = this->objectValue->owner;
    ownerID = owner->id;
    world = owner->world;

    for (int off = 0; off > -8; off -= 4) {
        for (int j = 0; j < *(int*)((char*)&DAT_0087d7d8 + off); ++j) {
            VisibleUnitEntry* entries = *(VisibleUnitEntry**)((char*)&DAT_0087d7f0 + off);
            RGE_Static_Object* obj = world->object(entries[j].object_id);
            if (obj != 0 && obj->object_state <= 2) {
                this->objectValue->owner->notify(obj_id, ownerID, 0x20D,
                                                 obj->id, 0, 0);
            }
        }
    }

    this->lookAroundTimerValue = 0;
    this->lookAroundTimeoutValue =
        debug_rand("C:\\msdev\\work\\age1_x1\\aiuaimod.cpp", 0xF92) % 1000 + 4000;
}
