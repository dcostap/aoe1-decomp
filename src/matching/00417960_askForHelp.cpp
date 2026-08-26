// VA: 00417960 UnitAIModule::askForHelp(int) (493B)
// aiuaimod.cpp:4005-4113
//
// Attempt log:
// - Replaced the placeholder with the binary-supported visible-unit bucket
//   scan.  The caller object is looked up first, then the five populated
//   visible-unit buckets are searched for nearby idle allied units.
// - The natural typed array form with repeated entry expressions reproduces
//   the 493-byte frame/size and all 15 ordered calls; a saved object-id local
//   collapsed the pointer/index schedule and was rolled back.
// - Binary evidence fixes the state guard at <= 2 and this routine's outer
//   scan at the two populated buckets (the emitted byte-offset loop compares
//   its cursor with 4).  The late scan and final dispatch blocks now align.
// - Fresh TU pass: declaring targetAI before the caller Y local reproduces the
//   unitAI call, Y load, and final push schedule. The mismatch falls to two
//   stack-displacement bytes at 00417AEA and 00417AFF.
// - An explicit cdecl slot-10c method ABI was tested because the original
//   post-call homes are 12 bytes higher. It worsened the structural match and
//   was rolled back. Keep the natural typed thiscall surface.
// - Direct callerObject->world_y arguments and a top-level uninitialized Y
//   local both duplicate the two-byte result. Keep direct typed member reads.
// - Main-agent audit corrected slot +0x10C to weaponRange() and moved the three
//   pending stack arguments into the complete eleven-argument order ABI.
// - Binary stack order confirms those pending values are 1, 0, and 0x32;
//   keeping weaponRange() argument-free and the complete order ABI matches.

#include "../../include/game_globals.h"
#include "../../include/aiuaimod_context.h"

extern float DAT_0056ebec;

void UnitAIModule::askForHelp(int caller)
{
    RGE_Static_Object* callerObject = this->lookupObject(caller);
    if (callerObject != 0) {
        this->search();

        int category = 0;
        do {
            int i = 0;
            if (((int*)&DAT_0087d7cc)[category] > 0) {
                do {
                    if (this->objectValue->id !=
                        ((VisibleUnitEntry**)&DAT_0087d7e4)[category][i].object_id) {
                        RGE_Static_Object* object =
                            this->lookupObject(
                                ((VisibleUnitEntry**)&DAT_0087d7e4)[category][i].object_id);
                        if (object != 0 && object->unitAI() != 0) {
                            RGE_Player* owner = object->owner;
                            if (owner != 0 && object->object_state <= 2) {
                                short group = object->master_obj->object_group;
                                if (group != 1 && group != 3 && group != 4 &&
                                    group != 0x15 && group != 0x12 &&
                                    group != 0x14 && group != 0x1b) {
                                    short ownerId = this->objectValue->owner->id;
                                    if (owner->id == ownerId || owner->isAlly(ownerId)) {
                                        if (this->objectValue->distance_to_object(object) <= 3.0f) {
                                            if (object->unitAI()->currentAction() == -1) {
                                                if (object->unitAI()->currentOrder() == -1) {
                                                    if (object->unitAI()->orderQueueSize() <= 0) {
                                                        UnitAIModule* targetAI = object->unitAI();
                                                        targetAI->order(
                                                            object->owner->id,
                                                            0x2bc,
                                                            caller,
                                                            callerObject->owner->id,
                                                            callerObject->world_x,
                                                            callerObject->world_y,
                                                            callerObject->world_y,
                                                            object->weaponRange(),
                                                            1,
                                                            0,
                                                            0x32);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    ++i;
                } while (i < ((int*)&DAT_0087d7cc)[category]);
            }
            ++category;
        } while (category <= 1);
    }
}
