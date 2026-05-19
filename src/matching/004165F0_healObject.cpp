// UnitAIModule::healObject — action wrapper
// VA: 004165F0
#include "../../include/game_globals.h"

class RGE_Static_Object;
class RGE_Game_World { public: RGE_Static_Object* object(int id); };
class Owner { public: char gap_00[0x3C]; RGE_Game_World* world; };
class MasterObj { public: char gap_00[0x14]; short object_group; };
class RGE_Static_Object {
public:
    char gap_00[8];
    MasterObj* master_obj;
    char gap_0C[0x38 - 0x0C];
    int world_x;
    int world_y;
    int world_z;
};
class UnitObject {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5C();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6C();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7C();
    virtual void v80(); virtual void v84(); virtual int v88(int targetId, int flag);
    char gap_04[8];
    Owner* owner;
};
class UnitAIModule {
public:
    char gap_00[4];
    UnitObject* objectValue;
    char gap_08[0x30 - 0x08];
    int currentActionValue;

    void setCurrentAction(int action);
    void setCurrentTarget(int id, int group, int x, int y, int z);
    int healObject(int targetId, int flag);
};

int UnitAIModule::healObject(int targetId, int flag)
{
    if (flag || this->currentActionValue != 0x25B) {
        UnitObject* unit = this->objectValue;
        if (unit->v88(targetId, flag) == 1) {
            RGE_Static_Object* target = this->objectValue->owner->world->object(targetId);
            this->setCurrentAction(0x25B);
            if (target == 0) {
                this->setCurrentTarget(targetId, -1, 0, 0, 0);
                return 1;
            }
            this->setCurrentTarget(targetId, target->master_obj->object_group, target->world_x, target->world_y, target->world_z);
            return 1;
        }
    }
    return 0;
}
