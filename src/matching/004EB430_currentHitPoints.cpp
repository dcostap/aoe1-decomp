// first pass: 40-entry scan over unit ids, skipping -1 slots and summing floored hit points
// if this is close but not exact, the remaining mismatch is likely just the loop counter / accumulator register basin

#ifndef TAITACMD_SHARED_CONTEXT
class RGE_Static_Object {
public:
    char gap_00[0x30];
    float hit_points;
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

    int currentHitPoints(TribeMainDecisionAIModule* module) const;
};
#endif

extern int __ftol();

int TacticalAIGroup::currentHitPoints(TribeMainDecisionAIModule* module) const {
    int total = 0;
    const int* unit = unitsValue;
    int remaining = 0x28;

    do {
        int unitId = *unit;
        if (unitId != -1) {
            RGE_Static_Object* object = module->object(unitId);
            if (object != 0) {
                total += (int)object->hit_points;
            }
        }
        ++unit;
    } while (--remaining != 0);

    return total;
}
