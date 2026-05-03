// VA: 004EA860, TacticalAIGroup::TacticalAIGroup, 292 bytes
// Source: taitacmd.cpp lines 128-139
// MATCH: 292/292 bytes, 0% positional diff

typedef unsigned char uchar;
typedef unsigned long ulong;

struct Waypoint {
    int x, y, z;
    int unk;
};

class TacticalAIGroup {
public:
    void* vtable_ptr; // 0x00
    TacticalAIGroup* next; // 0x04
    TacticalAIGroup* prev; // 0x08
    int idValue; // 0x0C
    int inUseValue; // 0x10
    int typeValue; // 0x14
    int subTypeValue; // 0x18
    int unitsValue[40]; // 0x1C
    int unitsOriginalHitPointsValue[40]; // 0xBC
    int numberUnitsValue; // 0x15C
    int desiredNumberUnitsValue; // 0x160
    int commanderValue; // 0x164
    int originalHitPointsValue; // 0x168
    int originalUnitNumberValue; // 0x16C
    Waypoint locationValue; // 0x170
    int actionValue; // 0x180
    int targetValue; // 0x184
    int targetTypeValue; // 0x188
    Waypoint targetLocationValue; // 0x18C
    Waypoint gatherLocationValue; // 0x19C
    Waypoint retreatLocationValue; // 0x1AC
    int priorityValue; // 0x1BC
    int waitCodeValue; // 0x1C0
    int assistGroupIDValue; // 0x1C4
    int assistGroupTypeValue; // 0x1C8
    ulong consecutiveIdleUnitCountValue; // 0x1CC
    int playNumberValue; // 0x1D0
    uchar numberAttackWaypointsValue; // 0x1D4
    uchar currentAttackWaypointValue; // 0x1D5
    uchar _pad_0[2]; // 0x1D6
    Waypoint attackWaypoints[15]; // 0x1D8
    uchar consecutiveGatherAttemptsValue; // 0x2C8
    uchar _pad_1[3]; // 0x2C9
    int numberObjectsToDestroyValue; // 0x2CC
    int objectsToDestroyValue[20]; // 0x2D0
    int objectsToDestroyOwnerValue; // 0x320
    int objectsToDestroyCommanderZoneValue; // 0x324
    ulong lastAttackRoundupTime; // 0x328
    ulong lastAddedUnitTimeValue; // 0x32C

    void setTargetLocation(float x, float y, float z);
    void setGatherLocation(float x, float y, float z);
    void setRetreatLocation(float x, float y, float z);
    void setLocation(float x, float y, float z);

    TacticalAIGroup();
};

TacticalAIGroup::TacticalAIGroup()
{
    idValue = -1;
    inUseValue = 0;
    typeValue = -1;
    subTypeValue = -1;
    numberUnitsValue = 0;
    desiredNumberUnitsValue = 0;
    commanderValue = -1;
    originalHitPointsValue = -1;
    originalUnitNumberValue = -1;
    actionValue = 0;
    targetValue = -1;
    targetTypeValue = -1;
    priorityValue = 0;
    waitCodeValue = -1;
    assistGroupIDValue = -1;
    assistGroupTypeValue = -1;
    consecutiveIdleUnitCountValue = 0;
    playNumberValue = -1;
    numberAttackWaypointsValue = 0;
    currentAttackWaypointValue = 0;
    consecutiveGatherAttemptsValue = 0;
    numberObjectsToDestroyValue = 0;
    objectsToDestroyOwnerValue = -1;
    objectsToDestroyCommanderZoneValue = -1;
    lastAttackRoundupTime = 0;
    lastAddedUnitTimeValue = 0;

    vtable_ptr = (void*)0x5756D8;

    setTargetLocation(-1.0f, -1.0f, -1.0f);
    setGatherLocation(-1.0f, -1.0f, -1.0f);
    setRetreatLocation(-1.0f, -1.0f, -1.0f);
    setLocation(-1.0f, -1.0f, -1.0f);

    // Fill unitsValue and unitsOriginalHitPointsValue with -1
    { int i; for (i = 0; i < 40; i++) {
        unitsValue[i] = -1;
        unitsOriginalHitPointsValue[i] = -1;
    } }

    // Fill objectsToDestroyValue with -1
    { int i; for (i = 0; i < 20; i++)
        objectsToDestroyValue[i] = -1;
    }
}
