// VA: 004EAF20 id() (4 B)
// taitacmd.cpp:247-249
// Getter: returns this->idValue at +0xC

#include <stddef.h>

#ifndef TAITACMD_SHARED_CONTEXT
class Waypoint {
public:
    int x;
    int y;
};
#endif

#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    TacticalAIGroup* next; // +0x4
    TacticalAIGroup* prev; // +0x8
    int idValue; // +0xC
    int inUseValue; // +0x10
    int typeValue; // +0x14
    int subTypeValue; // +0x18
    int unitsValue[40]; // +0x1C
    int unitsOriginalHitPointsValue[40]; // +0xBC
    int numberUnitsValue; // +0x15C
    int desiredNumberUnitsValue; // +0x160
    int commanderValue; // +0x164
    int originalHitPointsValue; // +0x168
    int originalUnitNumberValue; // +0x16C
    Waypoint locationValue; // +0x170
    int actionValue; // +0x180
    int targetValue; // +0x184
    int targetTypeValue; // +0x188
    Waypoint targetLocationValue; // +0x18C
    Waypoint gatherLocationValue; // +0x19C
    Waypoint retreatLocationValue; // +0x1AC
    int priorityValue; // +0x1BC
    int waitCodeValue; // +0x1C0
    int assistGroupIDValue; // +0x1C4
    int assistGroupTypeValue; // +0x1C8
    unsigned long consecutiveIdleUnitCountValue; // +0x1CC
    int playNumberValue; // +0x1D0
    unsigned char numberAttackWaypointsValue; // +0x1D4
    unsigned char currentAttackWaypointValue; // +0x1D5
    unsigned char _pad_0[0x2]; // 0x1D6
    Waypoint attackWaypoints[15]; // +0x1D8
    unsigned char consecutiveGatherAttemptsValue; // +0x2C8
    unsigned char _pad_1[0x3]; // 0x2C9
    int numberObjectsToDestroyValue; // +0x2CC
    int objectsToDestroyValue[20]; // +0x2D0
    int objectsToDestroyOwnerValue; // +0x320
    int objectsToDestroyCommanderZoneValue; // +0x324
    unsigned long lastAttackRoundupTime; // +0x328
    unsigned long lastAddedUnitTimeValue; // +0x32C
};
#endif

int TacticalAIGroup::id() const
{
    return idValue;
}
