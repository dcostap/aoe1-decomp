// 004ECE70 TacticalAIGroup::isTightGathered(TribeTacticalAIModule*,TribeMainDecisionAIModule*)
// Source: taitacmd.cpp lines 1535-1556
// Attempt log:
// - Replaced stub with full unit scan, stale-unit removal, distance clamp, and
//   tight-gather threshold check.
// - Exact match with precondition `while (i < 40)` and natural float clamp
//   `dist -= 2.0f; if (dist < 0.0f) dist = 0.0f; if (dist > 1.0) return 0;`.

class UnitAIModule {
public:
    int currentAction();
};

class RGE_Static_Object {
public:
    char gap_00[8];
    void* master_obj;

    UnitAIModule* unitAI();
    float distance_to_position(float x, float y, float z);
};

class TribeMainDecisionAIModule {
public:
    RGE_Static_Object* object(int id);
};

class TribeTacticalAIModule;

class TacticalAIGroup {
public:
    char gap_00[0x1C];
    int unitsValue[40];
    char gap_BC[0x19C - 0xBC];
    float gatherX;
    float gatherY;
    float gatherZ;

    int removeUnitByIndex(int index, TribeMainDecisionAIModule* md);
    int isTightGathered(TribeTacticalAIModule* tactical, TribeMainDecisionAIModule* md);
};

int TacticalAIGroup::isTightGathered(TribeTacticalAIModule* tactical, TribeMainDecisionAIModule* md)
{
    int i;
    int* p;
    int unit;
    RGE_Static_Object* obj;
    float dist;

    i = 0;
    p = this->unitsValue;
    while (i < 40) {
        unit = *p;
        if (unit != -1) {
            obj = md->object(unit);
            if (obj == 0 || obj->unitAI() == 0) {
                this->removeUnitByIndex(i, md);
            }
            else {
                dist = obj->distance_to_position(this->gatherX, this->gatherY, this->gatherZ);
                dist = dist - 2.0f;
                if (dist < 0.0f) {
                    dist = 0.0f;
                }
                if (dist > 1.0) {
                    return 0;
                }
            }
        }
        i = i + 1;
        p = p + 1;
    }
    return 1;
}
