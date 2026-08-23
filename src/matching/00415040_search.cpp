// VA: 00415040 UnitAIModule::search()
// aiuaimod.cpp
// attempt 2: direct branch-local GetVisibleUnits calls to avoid stack locals; rely on VC5 right-to-left argument setup/tail merging.

#define searchedThisUpdate (*(int*)0x592A4C)
#define numberVisibleObjects (*(int*)0x592A50)

#include "../../include/aiuaimod_context.h"

#define VisibleUnitManager (*(Visible_Unit_Manager**)0x87D800)

void UnitAIModule::search()
{
    RGE_Static_Object* obj;
    RGE_Master_Static_Object* master;
    int range;

    if (searchedThisUpdate == 1)
        return;

    searchedThisUpdate = 1;
    if (this->importantObjects == 0)
        return;

    if (this->currentOrderValue == 0x2BD && this->defendTargetValue != -1) {
        obj = this->lookupObject(this->defendTargetValue);
        if (obj != 0) {
            if (obj->unitAI() != 0) {
                numberVisibleObjects = VisibleUnitManager->GetVisibleUnits(
                    (int)obj->world_x,
                    (int)obj->world_y,
                    (int)obj->master_obj->range,
                    obj->owner->id,
                    this->importantObjects,
                    this->numberImportantObjects,
                    this->objectValue->owner->unitDiplomacy);
                return;
            }
        }
    }

    obj = this->objectValue;
    master = obj->master_obj;
    range = (int)master->range;
    if (master->id == 0x76)
        range += range;

    numberVisibleObjects = VisibleUnitManager->GetVisibleUnits(
        (int)obj->world_x,
        (int)obj->world_y,
        range,
        obj->owner->id,
        this->importantObjects,
        this->numberImportantObjects,
        obj->owner->unitDiplomacy);
}
