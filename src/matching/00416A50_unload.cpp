// 00416A50 UnitAIModule::unload
// aiuaimod.cpp lines 3364-3381
#include "../../include/game_globals.h"

class MasterObj { public: char gap_00[0x14]; short object_group; };
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
    virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8C();
    virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9C();
    virtual void vA0(); virtual void vA4(); virtual void vA8(); virtual void vAC();
    virtual void vB0(); virtual void vB4(); virtual void vB8(); virtual void vBC();
    virtual void vC0(); virtual void vC4(); virtual void vC8(); virtual void vCC();
    virtual void vD0(); virtual void vD4(); virtual void vD8(); virtual void vDC();
    virtual void vE0(); virtual void vE4(); virtual void vE8(); virtual void vEC();
    virtual void vF0(); virtual void vF4(); virtual void vF8(); virtual void vFC();
    virtual void v100(); virtual void v104(); virtual void v108(); virtual void v10C();
    virtual void v110(); virtual void v114(); virtual void v118(); virtual void v11C();
    virtual void v120(); virtual void v124(); virtual void v128(); virtual void v12C();
    virtual void v130(); virtual void v134(); virtual void v138(); virtual void v13C();
    virtual void v140(); virtual void v144(); virtual void v148(); virtual void v14C();
    virtual void v150(); virtual void v154(); virtual void v158(); virtual void v15C();
    virtual void v160(); virtual void v164(); virtual void v168(); virtual void v16C();
    virtual void v170(); virtual void v174(); virtual void v178(); virtual void v17C();
    virtual void v180(); virtual int v184(int id, float x, float y, int z);
    int id;                 // +0x04
    MasterObj* master_obj;  // +0x08
    char gap_0C[0x38 - 0x0C];
    int world_x;            // +0x38
    int world_y;            // +0x3C
    int world_z;            // +0x40
};

class UnitAIModule {
public:
    char gap_00[4];
    UnitObject* objectValue;
    char gap_08[0x30 - 0x08];
    int currentActionValue;

    void setCurrentAction(int action);
    void setCurrentTarget(int id, int group, int x, int y, int z);
    int unload(int id, float x, float y);
};

int UnitAIModule::unload(int id, float x, float y)
{
    if (id || this->currentActionValue == -1) {
        UnitObject* obj = this->objectValue;
        if (obj->v184(id, x, y, obj->world_z) == 1) {
            UnitObject* target = this->objectValue;
            this->setCurrentAction(0x26D);
            if (target == 0) {
                this->setCurrentTarget(this->objectValue->id, -1, 0, 0, 0);
                return 1;
            }
            this->setCurrentTarget(this->objectValue->id, target->master_obj->object_group, target->world_x, target->world_y, target->world_z);
            return 1;
        }
    }
    return 0;
}
