// 004ED0F0 TacticalAIGroup::firstIdleUnit(TribeMainDecisionAIModule*)
// Source: taitacmd.cpp lines 1657-1673
// Attempt log:
// - Replaced stub with Ghidra scan/removal logic and natural member-call surface.
// - Exact match: use a precondition `while (i < 40)` (not do-while/goto/break)
//   to keep VC5's loop fallthrough default-return block before the success
//   return block while preserving the original stack homes for this/base pointer.

#ifndef TAITACMD_SHARED_CONTEXT
class UnitAIModule {
public:
    int currentAction();
};
#endif
#ifndef TAITACMD_SHARED_CONTEXT
class RGE_Static_Object {
public:
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
    char gap_00[0x1C];
    int unitsValue[40];
    char gap_BC[0x164 - 0xBC];
    int commanderValue;

    int removeUnitByIndex(int index, TribeMainDecisionAIModule* md);
    int firstIdleUnit(TribeMainDecisionAIModule* md);
};
#endif
int TacticalAIGroup::firstIdleUnit(TribeMainDecisionAIModule* md)
{
    TacticalAIGroup* self;
    int* base;
    int* p;
    int i;
    int unit;
    RGE_Static_Object* obj;
    UnitAIModule* ai;

    self = this;
    p = this->unitsValue;
    i = 0;
    base = p;
    while (i < 40) {
        unit = *p;
        if (unit != -1) {
            obj = md->object(unit);
            if (obj == 0 || obj->unitAI() == 0) {
                self->removeUnitByIndex(i, md);
            }
            else {
                ai = obj->unitAI();
                if (ai->currentAction() == -1) {
                    return base[i];
                }
            }
        }
        i = i + 1;
        p = p + 1;
    }
    return -1;
}
