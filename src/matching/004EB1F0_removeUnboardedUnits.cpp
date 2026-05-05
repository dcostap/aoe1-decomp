// 004EB1F0 TacticalAIGroup::removeUnboardedUnits(TribeTacticalAIModule*,TribeMainDecisionAIModule*)
// Source: taitacmd.cpp lines 396-418
// Attempt log:
// - Replaced stub with full scan/removal logic, commander updates, player vtable
//   +0xCC notification, and TribeTacticalAIModule::stopUnit call.
// - Exact match with countdown local (`remaining = 40`) and pointer do-while;
//   reloading `*p` before commander/stopUnit preserves the original memory reads.

#define VPAD1(n) virtual void vpad##n() {}
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)

class PlayerVTableCC {
public:
    VPAD32(0) VPAD16(32) VPAD2(48) VPAD1(50)
    virtual void cmdCC(int commander, int unit);
};

class RGE_Static_Object {
public:
    char gap_00[0x20];
    RGE_Static_Object* inside_obj;
};

class TribeMainDecisionAIModule {
public:
    char gap_000[0xF0];
    PlayerVTableCC* player;

    RGE_Static_Object* object(int id);
};

class TribeTacticalAIModule {
public:
    int stopUnit(int id, int priority);
};

class TacticalAIGroup {
public:
    char gap_00[0x1C];
    int unitsValue[40];
    int unitsOriginalHitPointsValue[40];
    int numberUnitsValue;
    int desiredNumberUnitsValue;
    int commanderValue;

    void setSpecificCommander(int commander, TribeMainDecisionAIModule* md);
    int removeUnboardedUnits(TribeTacticalAIModule* tactical, TribeMainDecisionAIModule* md);
};

int TacticalAIGroup::removeUnboardedUnits(TribeTacticalAIModule* tactical, TribeMainDecisionAIModule* md)
{
    int remaining;
    int* p;
    int unit;
    int commander;
    RGE_Static_Object* obj;

    remaining = 40;
    p = this->unitsValue;
    do {
        unit = *p;
        if (unit != -1) {
            obj = md->object(unit);
            if (obj == 0 || obj->inside_obj == 0) {
                unit = *p;
                commander = this->commanderValue;
                if (unit == commander) {
                    this->setSpecificCommander(-1, md);
                }
                else if (commander != -1) {
                    md->player->cmdCC(commander, unit);
                }
                tactical->stopUnit(*p, 100);
                *p = -1;
                p[40] = -1;
                this->numberUnitsValue = this->numberUnitsValue - 1;
            }
        }
        p = p + 1;
        remaining = remaining - 1;
    } while (remaining != 0);
    return 1;
}
