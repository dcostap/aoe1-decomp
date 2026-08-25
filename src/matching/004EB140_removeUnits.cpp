// 004EB140 TacticalAIGroup::removeUnits
// Source: taitacmd.cpp lines 365-372. 58 bytes. __thiscall, ret 4.
//
// MATCHED. Exact 58-byte match (77.6% → 0% in one pass).
// Fix: piVar1[-0x28] pointer trick fails because VC5 converts
// *piVar1++ = -1 into rep stosd, breaking paired writes. Clean
// indexed for loop produces matching lea+loop with two stores each iteration.

class TribeMainDecisionAIModule;

#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    int gap_00[7];           // +0x00 to +0x1B (vtable, prev/next links, id, inUse, type, subType)
    int unitsValue[40];      // +0x1C
    int unitsOriginalHitPointsValue[40];  // +0xBC
    int numberUnitsValue;    // +0x15C
    int gap_160[4];          // +0x160 to +0x16F
    int commanderValue;      // +0x170
    int gap_174[1];          // padding

    void setSpecificCommander(int value, TribeMainDecisionAIModule* md);
    void removeUnits(TribeMainDecisionAIModule* md);
};
#endif

void TacticalAIGroup::removeUnits(TribeMainDecisionAIModule* md) {
    setSpecificCommander(-1, md);
    numberUnitsValue = 0;
    for (int i = 0; i < 40; i++) {
        unitsValue[i] = -1;
        unitsOriginalHitPointsValue[i] = -1;
    }
}
