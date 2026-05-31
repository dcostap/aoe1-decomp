// VA: 00415040 UnitAIModule::search()
// aiuaimod.cpp
// attempt 2: direct branch-local GetVisibleUnits calls to avoid stack locals; rely on VC5 right-to-left argument setup/tail merging.

#define searchedThisUpdate (*(int*)0x592A4C)
#define numberVisibleObjects (*(int*)0x592A50)

class UnitAIModule;
class Visible_Unit_Manager;

#define VisibleUnitManager (*(Visible_Unit_Manager**)0x87D800)

class RGE_Master_Static_Object {
public:
    char gap_00[0x10];
    short id;                 // +0x10
    char gap_12[0x28 - 0x12];
    float range;              // +0x28
};

class RGE_Player {
public:
    virtual void p00();
    char gap_04[0x4A - 0x04];
    short id;                 // +0x4A
    char gap_4C[0x88 - 0x4C];
    int unitDiplomacy[1];     // +0x88
};

class RGE_Static_Object {
public:
    virtual void v00();
    int id;                              // +0x04
    RGE_Master_Static_Object* master_obj; // +0x08
    RGE_Player* owner;                   // +0x0C
    char gap_10[0x38 - 0x10];
    float world_x;                       // +0x38
    float world_y;                       // +0x3C

    UnitAIModule* unitAI();
};

class Visible_Unit_Manager {
public:
    int GetVisibleUnits(int x, int y, int range, int owner_id, int* objects, int count, int* diplomacy);
};

class UnitAIModule {
public:
    virtual void search();
    RGE_Static_Object* objectValue;       // +0x04
    char gap_08[0x28 - 0x08];
    int currentOrderValue;                // +0x28
    char gap_2C[0x4C - 0x2C];
    int defendTargetValue;                // +0x4C
    char gap_50[0x124 - 0x50];
    int* importantObjects;                // +0x124
    int numberImportantObjects;           // +0x128

    RGE_Static_Object* lookupObject(int id);
};

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
