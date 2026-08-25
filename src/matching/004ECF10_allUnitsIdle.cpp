// 004ECF10 TacticalAIGroup::allUnitsIdle(TribeMainDecisionAIModule*,int)
// Source: taitacmd.cpp lines 1561-1588
// Attempt log:
// - Replaced stub with full scan, stale-unit removal, master object/type/action
//   special cases, and current-order idle rejection.
// - Exact match with stored `self` local and explicit `goto next` for the
//   ignore-build special case, preserving the original shared loop tail.

#ifndef TAITACMD_SHARED_CONTEXT
class UnitAIModule {
public:
    int currentOrder();
    int currentAction();
};
#endif

#ifndef TAITACMD_SHARED_CONTEXT
class MasterObject {
public:
    char gap_00[0x10];
    short id;
};
#endif

#ifndef TAITACMD_SHARED_CONTEXT
class RGE_Static_Object {
public:
    char gap_00[8];
    MasterObject* master_obj;

    UnitAIModule* unitAI();
};
#endif

#ifndef TAITACMD_SHARED_CONTEXT
class TribeMainDecisionAIModule {
public:
    RGE_Static_Object* object(int id);
};
#endif

#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    char gap_00[0x14];
    int typeValue;
    char gap_18[4];
    int unitsValue[40];

    int removeUnitByIndex(int index, TribeMainDecisionAIModule* md);
    int allUnitsIdle(TribeMainDecisionAIModule* md, int ignoreBuild);
};
#endif

int TacticalAIGroup::allUnitsIdle(TribeMainDecisionAIModule* md, int ignoreBuild)
{
    TacticalAIGroup* self;
    int i;
    int* p;
    int unit;
    RGE_Static_Object* obj;
    UnitAIModule* ai;

    self = this;
    i = 0;
    p = this->unitsValue;
    while (i < 40) {
        unit = *p;
        if (unit != -1) {
            obj = md->object(unit);
            if (obj == 0 || obj->unitAI() == 0) {
                self->removeUnitByIndex(i, md);
            }
            else if (obj->master_obj->id != 0x7D) {
                if (ignoreBuild == 1) {
                    ai = obj->unitAI();
                    if (ai->currentAction() == 600) {
                        if (self->typeValue == 100 || self->typeValue == 0x67) {
                            goto next;
                        }
                    }
                }
                ai = obj->unitAI();
                if (ai->currentAction() != -1) {
                    ai = obj->unitAI();
                    if (ai->currentOrder() != 0x2BD) {
                        return 0;
                    }
                }
            }
        }
next:
        i = i + 1;
        p = p + 1;
    }
    return 1;
}
