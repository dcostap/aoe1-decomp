// 004EACA0 TacticalAIGroup::save(int fd)
// Source: taitacmd.cpp lines 204-242
// Serializes the TacticalAIGroup save fields through rge_write (004802C0).
// Returns 1 on success.
//
// Attempt log:
// Probe 1: clean partial-layout serializer with an indexed pair loop — 330
//   differing bytes; the helper relocation and register/loop shape were wrong.
// Probe 2: changed the helper surface from write_data to the imported
//   rge_write symbol — 210 differing bytes; all 34 call targets aligned.
// Probe 3: restored the vtable/next/prev prefix from the exact same-TU
//   TacticalAIGroup constructor donor — 188 differing bytes and correct main
//   member offsets.
// Probe 4: added the proven two-byte padding after the serialized byte flags
//   — 180 differing bytes; the attack-waypoint and trailing offsets aligned.
// Probe 5: replaced the indexed loop with the binary-backed companion cursor
//   and 40-count do/while — exact 636/636 bytes.

#include "..\..\include\game_globals.h"

extern "C" void __cdecl rge_write(int fd, void* data, int size); // 004802C0

struct Waypoint {
    int x;
    int y;
    int z;
    int unk;
};

// TacticalAIGroup layout (partial, only serialized fields)
class TacticalAIGroup {
public:
    void* vtable_ptr;          // +0x00
    TacticalAIGroup* next;     // +0x04
    TacticalAIGroup* prev;     // +0x08
    int idValue;                         // +0x0C
    int inUseValue;                      // +0x10
    int typeValue;                       // +0x14
    int subTypeValue;                    // +0x18
    int unitsValue[40];                  // +0x1C
    int unitsOriginalHitPointsValue[40];// +0xBC
    int numberUnitsValue;                // +0x15C
    int desiredNumberUnitsValue;         // +0x160
    int commanderValue;                  // +0x164
    int originalHitPointsValue;          // +0x168
    int originalUnitNumberValue;         // +0x16C
    Waypoint locationValue;              // +0x170
    int actionValue;                     // +0x180
    int targetValue;                     // +0x184
    int targetTypeValue;                 // +0x188
    Waypoint targetLocationValue;        // +0x18C
    Waypoint gatherLocationValue;        // +0x19C
    Waypoint retreatLocationValue;       // +0x1AC
    int priorityValue;                   // +0x1BC
    int waitCodeValue;                   // +0x1C0
    int assistGroupIDValue;              // +0x1C4
    int assistGroupTypeValue;            // +0x1C8
    unsigned long consecutiveIdleUnitCountValue; // +0x1CC
    int playNumberValue;                 // +0x1D0
    unsigned char numberAttackWaypointsValue; // +0x1D4
    unsigned char currentAttackWaypointValue; // +0x1D5
    unsigned char data_1D6[2]; // +0x1D6 (padding)
    Waypoint attackWaypoints[15];        // +0x1D8
    unsigned char consecutiveGatherAttemptsValue; // +0x2C8
    unsigned char data_2C9[3];           // +0x2C9 (padding)
    int numberObjectsToDestroyValue;     // +0x2CC
    int objectsToDestroyValue[20];       // +0x2D0
    int objectsToDestroyOwnerValue;      // +0x320
    int objectsToDestroyCommanderZoneValue; // +0x324
    unsigned long lastAttackRoundupTime; // +0x328
    unsigned long lastAddedUnitTimeValue;// +0x32C

    int save(int fd);
};

int TacticalAIGroup::save(int fd)
{
    rge_write(fd, &this->idValue, 4);
    rge_write(fd, &this->inUseValue, 4);

    // Write unitsValue and unitsOriginalHitPointsValue in paired entries.
    int* ptr = this->unitsOriginalHitPointsValue;
    int count = 40;
    do {
        rge_write(fd, ptr - 40, 4);
        rge_write(fd, ptr, 4);
        ++ptr;
    } while (--count != 0);

    rge_write(fd, &this->numberUnitsValue, 4);
    rge_write(fd, &this->desiredNumberUnitsValue, 4);
    rge_write(fd, &this->commanderValue, 4);
    rge_write(fd, &this->originalHitPointsValue, 4);
    rge_write(fd, &this->originalUnitNumberValue, 4);
    rge_write(fd, &this->locationValue, 0x10);
    rge_write(fd, &this->actionValue, 4);
    rge_write(fd, &this->targetValue, 4);
    rge_write(fd, &this->targetTypeValue, 4);
    rge_write(fd, &this->targetLocationValue, 0x10);
    rge_write(fd, &this->gatherLocationValue, 0x10);
    rge_write(fd, &this->retreatLocationValue, 0x10);
    rge_write(fd, &this->priorityValue, 4);
    rge_write(fd, &this->waitCodeValue, 4);
    rge_write(fd, &this->assistGroupIDValue, 4);
    rge_write(fd, &this->assistGroupTypeValue, 4);
    rge_write(fd, &this->typeValue, 4);
    rge_write(fd, &this->subTypeValue, 4);
    rge_write(fd, &this->consecutiveIdleUnitCountValue, 4);
    rge_write(fd, &this->numberAttackWaypointsValue, 1);
    rge_write(fd, &this->currentAttackWaypointValue, 1);
    rge_write(fd, &this->attackWaypoints, 0xF0);
    rge_write(fd, &this->playNumberValue, 4);
    rge_write(fd, &this->consecutiveGatherAttemptsValue, 1);
    rge_write(fd, &this->numberObjectsToDestroyValue, 4);
    rge_write(fd, &this->objectsToDestroyValue, 0x50);
    rge_write(fd, &this->objectsToDestroyOwnerValue, 4);
    rge_write(fd, &this->objectsToDestroyCommanderZoneValue, 4);
    rge_write(fd, &this->lastAttackRoundupTime, 4);
    rge_write(fd, &this->lastAddedUnitTimeValue, 4);

    return 1;
}
