// Authentic taitacmd.cpp translation unit.
// Definitions follow the original PDB source order.
#include "../include/taitacmd.h"
#include "../include/game_globals.h"
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

// ---------------------------------------------------------------------------
// PDB source owner: 004EA860_TacticalAIGroup.cpp
// ---------------------------------------------------------------------------
// VA: 004EA860, TacticalAIGroup::TacticalAIGroup, 292 bytes
// Source: taitacmd.cpp lines 128-139
// MATCH: 292/292 bytes, 0% positional diff



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

// ---------------------------------------------------------------------------
// PDB source owner: 004EA9B0_TacticalAIGroup.cpp
// ---------------------------------------------------------------------------

TacticalAIGroup::~TacticalAIGroup() {}

// ---------------------------------------------------------------------------
// PDB source owner: 004EA9C0_load.cpp
// ---------------------------------------------------------------------------
// 004EA9C0 TacticalAIGroup::load(int fd)
// Source: taitacmd.cpp lines 150-199
// Deserializes struct fields with version-conditional reads
// Load has 4 float comparisons for backward compat: conditional field reads
//
// Attempt log:
// Prior attempt: 624/721 bytes â€” missing conditional reads.
// Baseline: 720/721 bytes, but used a placeholder read_data symbol and an incomplete layout/loop shape.
// Probe 1: restored the proven rge_read relocation from the same-TU save donor; calls aligned.
// Probe 2: restored the TacticalAIGroup vtable/next/prev prefix; proven member offsets aligned.
// Probe 3: restored the two-byte waypoint and three-byte post-byte padding from the exact save layout.
// Probe 4: mirrored the exact same-TU save donor's companion pointer and 40-count do/while; exact.


extern "C" void __cdecl rge_read(int fd, void* data, int size); // 00480080

extern float DAT_0058ebcc;
extern float DAT_005756e0;
extern float DAT_005756e4;
extern float DAT_005756e8;
extern float DAT_005756ec;


int TacticalAIGroup::load(int fd)
{
    rge_read(fd, &this->idValue, 4);
    rge_read(fd, &this->inUseValue, 4);

    int* ptr = this->unitsOriginalHitPointsValue;
    int count = 40;
    do {
        rge_read(fd, ptr - 40, 4);
        rge_read(fd, ptr, 4);
        ++ptr;
    } while (--count != 0);

    rge_read(fd, &this->numberUnitsValue, 4);
    rge_read(fd, &this->desiredNumberUnitsValue, 4);
    rge_read(fd, &this->commanderValue, 4);
    rge_read(fd, &this->originalHitPointsValue, 4);
    rge_read(fd, &this->originalUnitNumberValue, 4);
    rge_read(fd, &this->locationValue, 0x10);
    rge_read(fd, &this->actionValue, 4);
    rge_read(fd, &this->targetValue, 4);
    rge_read(fd, &this->targetTypeValue, 4);
    rge_read(fd, &this->targetLocationValue, 0x10);
    rge_read(fd, &this->gatherLocationValue, 0x10);
    rge_read(fd, &this->retreatLocationValue, 0x10);
    rge_read(fd, &this->priorityValue, 4);
    rge_read(fd, &this->waitCodeValue, 4);
    rge_read(fd, &this->assistGroupIDValue, 4);
    rge_read(fd, &this->assistGroupTypeValue, 4);
    rge_read(fd, &this->typeValue, 4);
    rge_read(fd, &this->subTypeValue, 4);
    rge_read(fd, &this->consecutiveIdleUnitCountValue, 4);
    rge_read(fd, &this->numberAttackWaypointsValue, 1);
    rge_read(fd, &this->currentAttackWaypointValue, 1);
    rge_read(fd, &this->attackWaypoints, 0xF0);
    rge_read(fd, &this->playNumberValue, 4);

    // Version detection: conditional field reads based on float version comparison
    // Asm pattern: fld [58EBCCh]; fcomp [5756E0h]; test ah,1; jne â†’ if (ver < threshold)
    if (DAT_0058ebcc >= DAT_005756e0) {
        rge_read(fd, &this->consecutiveGatherAttemptsValue, 1);
    } else {
        this->consecutiveGatherAttemptsValue = 0;
    }

    if (DAT_0058ebcc >= DAT_005756e4) {
        rge_read(fd, &this->numberObjectsToDestroyValue, 4);
        rge_read(fd, &this->objectsToDestroyValue, 0x50);
        rge_read(fd, &this->objectsToDestroyOwnerValue, 4);
        rge_read(fd, &this->objectsToDestroyCommanderZoneValue, 4);
    }

    if (DAT_0058ebcc >= DAT_005756e8) {
        rge_read(fd, &this->lastAttackRoundupTime, 4);
    }

    if (DAT_0058ebcc >= DAT_005756ec) {
        rge_read(fd, &this->lastAddedUnitTimeValue, 4);
    }

    return 1;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004EACA0_save.cpp
// ---------------------------------------------------------------------------
// 004EACA0 TacticalAIGroup::save(int fd)
// Source: taitacmd.cpp lines 204-242
// Serializes the TacticalAIGroup save fields through rge_write (004802C0).
// Returns 1 on success.
//
// Attempt log:
// Probe 1: clean partial-layout serializer with an indexed pair loop â€” 330
//   differing bytes; the helper relocation and register/loop shape were wrong.
// Probe 2: changed the helper surface from write_data to the imported
//   rge_write symbol â€” 210 differing bytes; all 34 call targets aligned.
// Probe 3: restored the vtable/next/prev prefix from the exact same-TU
//   TacticalAIGroup constructor donor â€” 188 differing bytes and correct main
//   member offsets.
// Probe 4: added the proven two-byte padding after the serialized byte flags
//   â€” 180 differing bytes; the attack-waypoint and trailing offsets aligned.
// Probe 5: replaced the indexed loop with the binary-backed companion cursor
//   and 40-count do/while â€” exact 636/636 bytes.


extern "C" void __cdecl rge_write(int fd, void* data, int size); // 004802C0


// TacticalAIGroup layout (partial, only serialized fields)

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

// ---------------------------------------------------------------------------
// PDB source owner: 004EAF20_id.cpp
// ---------------------------------------------------------------------------
// VA: 004EAF20 id() (4 B)
// taitacmd.cpp:247-249
// Getter: returns this->idValue at +0xC




int TacticalAIGroup::id() const
{
    return idValue;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004EAF30_setID.cpp
// ---------------------------------------------------------------------------
void TacticalAIGroup::setID(int val) { this->idValue = val; }

// ---------------------------------------------------------------------------
// PDB source owner: 004EAF40_inUse.cpp
// ---------------------------------------------------------------------------
int TacticalAIGroup::inUse() const { return this->inUseValue; }

// ---------------------------------------------------------------------------
// PDB source owner: 004EAF50_setInUse.cpp
// ---------------------------------------------------------------------------
void TacticalAIGroup::setInUse(int val) { this->inUseValue = val; }

// ---------------------------------------------------------------------------
// PDB source owner: 004EAF60_type.cpp
// ---------------------------------------------------------------------------
int TacticalAIGroup::type() const { return this->typeValue; }

// ---------------------------------------------------------------------------
// PDB source owner: 004EAF70_setType.cpp
// ---------------------------------------------------------------------------
void TacticalAIGroup::setType(int val) { this->typeValue = val; }

// ---------------------------------------------------------------------------
// PDB source owner: 004EAF80_subType.cpp
// ---------------------------------------------------------------------------
int TacticalAIGroup::subType() const { return this->subTypeValue; }

// ---------------------------------------------------------------------------
// PDB source owner: 004EAF90_setSubType.cpp
// ---------------------------------------------------------------------------
void TacticalAIGroup::setSubType(int val) { this->subTypeValue = val; }

// ---------------------------------------------------------------------------
// PDB source owner: 004EAFA0_addUnit.cpp
// ---------------------------------------------------------------------------
// 004EAFA0 TacticalAIGroup::addUnit(int,TribeMainDecisionAIModule*)
// Source: taitacmd.cpp lines 303-319
// Attempt log:
// - Replaced old one-slot stub with full Ghidra logic and the canonical
//   RGE_Player command surface.
// - Using `while (i < 40)` for the scan (not do-while) prevents
//   VC5 from peeling/preloading the first array element and matches the original
//   push-edi, xor-index, memory-cmp loop top.
// - The old `md->player->list->next` spelling was a reduced-context type view.
//   PDB fields name RGE_Player +0x3C as `world`, and RGE_Game_World +0x04 as
//   `world_time`. The original load is [player+3C], then [world+4]. Use that
//   real field meaning as `md->player->world->world_time`.





int TacticalAIGroup::addUnit(int unit, TribeMainDecisionAIModule* md)
{
    int i;
    volatile int* p;

    i = 0;
    p = this->unitsValue;
    while (i < 40) {
        if (*p == -1) {
            this->unitsValue[i] = unit;
            this->unitsOriginalHitPointsValue[i] = -1;
            this->numberUnitsValue = this->numberUnitsValue + 1;
            if (this->commanderValue != -1) {
                md->player->command_add_to_group(this->commanderValue, unit, 4.0f);
            }
            this->lastAddedUnitTimeValue = md->player->world->world_time;
            return 1;
        }
        i = i + 1;
        p = p + 1;
    }
    return 0;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004EB030_removeUnit.cpp
// ---------------------------------------------------------------------------
// 004EB030 TacticalAIGroup::removeUnit(int,TribeMainDecisionAIModule*)
// Source: taitacmd.cpp lines 324-341
// Attempt log:
// - Replaced old one-field stub with full Ghidra logic and the canonical
//   RGE_Player command surface.
// - Exact match: use an explicit pointer plus `while (i < 40)` scan. This keeps
//   the parameter load before saved-register pushes and emits the original
//   memory compare at the loop top instead of a peeled first-element load.




int TacticalAIGroup::removeUnit(int unit, TribeMainDecisionAIModule* md)
{
    int commander;
    int i;
    int* p;

    i = 0;
    p = this->unitsValue;
    while (i < 40) {
        if (*p == unit) {
            commander = this->commanderValue;
            if (unit == commander) {
                this->setSpecificCommander(-1, md);
            }
            else if (commander != -1) {
                md->player->command_remove_from_group(commander, unit);
            }
            this->unitsValue[i] = -1;
            this->unitsOriginalHitPointsValue[i] = -1;
            this->numberUnitsValue = this->numberUnitsValue - 1;
            return 1;
        }
        i = i + 1;
        p = p + 1;
    }
    return 0;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004EB0C0_removeUnitByIndex.cpp
// ---------------------------------------------------------------------------
// 004EB0C0 TacticalAIGroup::removeUnitByIndex(int,TribeMainDecisionAIModule*)
// Source: taitacmd.cpp lines 347-360
// Attempt log:
// - Replaced stub with Ghidra logic and dummy-virtual vtable +0xCC dispatch.




int TacticalAIGroup::removeUnitByIndex(int index, TribeMainDecisionAIModule* md)
{
    int unit;
    int commander;

    if (index >= 0 && index < 40) {
        unit = this->unitsValue[index];
        commander = this->commanderValue;
        if (unit == commander) {
            this->setSpecificCommander(-1, md);
        }
        else if (commander != -1) {
            md->player->command_remove_from_group(commander, unit);
        }
        this->unitsValue[index] = -1;
        this->unitsOriginalHitPointsValue[index] = -1;
        this->numberUnitsValue = this->numberUnitsValue - 1;
        return 1;
    }
    return 0;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004EB140_removeUnits.cpp
// ---------------------------------------------------------------------------
// 004EB140 TacticalAIGroup::removeUnits
// Source: taitacmd.cpp lines 365-372. 58 bytes. __thiscall, ret 4.
//
// MATCHED. Exact 58-byte match (77.6% â†’ 0% in one pass).
// Fix: piVar1[-0x28] pointer trick fails because VC5 converts
// *piVar1++ = -1 into rep stosd, breaking paired writes. Clean
// indexed for loop produces matching lea+loop with two stores each iteration.



void TacticalAIGroup::removeUnits(TribeMainDecisionAIModule* md) {
    setSpecificCommander(-1, md);
    numberUnitsValue = 0;
    for (int i = 0; i < 40; i++) {
        unitsValue[i] = -1;
        unitsOriginalHitPointsValue[i] = -1;
    }
}

// ---------------------------------------------------------------------------
// PDB source owner: 004EB180_removeExtraUnits.cpp
// ---------------------------------------------------------------------------
// 004EB180 TacticalAIGroup::removeExtraUnits(TribeMainDecisionAIModule*)
// Source: taitacmd.cpp lines 377-390
// Attempt log:
// - Replaced stub with Ghidra logic and real C++ member/direct-call surface.



int TacticalAIGroup::removeExtraUnits(TribeMainDecisionAIModule* md)
{
    int number;
    int desired;
    int i;
    int* unit;

    number = this->numberUnitsValue;
    desired = this->desiredNumberUnitsValue;
    if (number > desired && number > 0) {
        i = 0;
        if (desired < number) {
            unit = this->unitsValue;
            while (1) {
                if (i >= 40) {
                    return 1;
                }
                if (*unit != -1) {
                    this->removeUnitByIndex(i, md);
                }
                i = i + 1;
                unit = unit + 1;
                if (this->desiredNumberUnitsValue < this->numberUnitsValue) {
                    continue;
                }
                break;
            }
        }
        return 1;
    }
    return 0;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004EB1F0_removeUnboardedUnits.cpp
// ---------------------------------------------------------------------------
// 004EB1F0 TacticalAIGroup::removeUnboardedUnits(TribeTacticalAIModule*,TribeMainDecisionAIModule*)
// Source: taitacmd.cpp lines 396-418
// Attempt log:
// - Replaced stub with full scan/removal logic, commander updates, player vtable
//   +0xCC notification, and TribeTacticalAIModule::stopUnit call through the
//   canonical RGE_Player surface.
// - Exact match with countdown local (`remaining = 40`) and pointer do-while;
//   reloading `*p` before commander/stopUnit preserves the original memory reads.






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
                    md->player->command_remove_from_group(commander, unit);
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

// ---------------------------------------------------------------------------
// PDB source owner: 004EB290_containsUnit.cpp
// ---------------------------------------------------------------------------

int TacticalAIGroup::containsUnit(int unitId) {
    for (int i = 0; i < 0x28; ++i) {
        if (this->unitsValue[i] == unitId) {
            return 1;
        }
    }
    return 0;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004EB2C0_numberUnits.cpp
// ---------------------------------------------------------------------------
int TacticalAIGroup::numberUnits() { return this->numberUnitsValue; }

// ---------------------------------------------------------------------------
// PDB source owner: 004EB2D0_unit.cpp
// ---------------------------------------------------------------------------

int TacticalAIGroup::unit(int index) {
    int i = 0;
    int used = -1;
    int limit = index + 1;
    int* units = this->unitsValue;

    while (i < 0x28) {
        if (used >= limit) {
            goto too_far;
        }
        if (*units != -1) {
            used++;
        }
        if (used == index) {
            return this->unitsValue[i];
        }
        i++;
        units++;
    }
    return -1;

too_far:
    return -1;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004EB320_unitOriginalHitPoints.cpp
// ---------------------------------------------------------------------------
// VA: 004EB320 TacticalAIGroup::unitOriginalHitPoints (72 B)
// Scans unitsValue array for the unit_index-th valid entry, returns corresponding HP
// Note: uses single i=-1 counter matching original asm topology


int TacticalAIGroup::unitOriginalHitPoints(int unit_index) {
    int idx = 0;
    int i = -1;
    int limit = unit_index + 1;

    for (; idx < 40; idx++) {
        if (i >= limit)
            return -1;
        if (this->unitsValue[idx] != -1)
            i++;
        if (i == unit_index)
            return this->unitsOriginalHitPointsValue[idx];
    }
    return -1;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004EB370_desiredNumberUnits.cpp
// ---------------------------------------------------------------------------
int TacticalAIGroup::desiredNumberUnits() const { return this->desiredNumberUnitsValue; }

// ---------------------------------------------------------------------------
// PDB source owner: 004EB380_setDesiredNumberUnits.cpp
// ---------------------------------------------------------------------------
void TacticalAIGroup::setDesiredNumberUnits(int val) { this->desiredNumberUnitsValue = val; }

// ---------------------------------------------------------------------------
// PDB source owner: 004EB390_commander.cpp
// ---------------------------------------------------------------------------
int TacticalAIGroup::commander() const { return this->commanderValue; }

// ---------------------------------------------------------------------------
// PDB source owner: 004EB3A0_setSpecificCommander.cpp
// ---------------------------------------------------------------------------
// 004EB3A0 TacticalAIGroup::setSpecificCommander(int,TribeMainDecisionAIModule*)
// Source: taitacmd.cpp lines 490-509
// Attempt log:
// - Replaced stub with full commander clear/set and member-list notification.
// - Exact match: initializing the live count before materializing the source
//   pointer (`count = 0; src = ...`) makes VC5 allocate count to EDI and reuse
//   ESI for the countdown, matching the original loop.




void TacticalAIGroup::setSpecificCommander(int commander, TribeMainDecisionAIModule* md)
{
    int temp[40];
    int* src;
    int* dst;
    int remaining;
    int count;
    int unit;

    if (this->commanderValue != -1) {
        md->player->command_destroy_group(this->commanderValue);
    }
    this->commanderValue = commander;
    if (commander != -1) {
        count = 0;
        src = this->unitsValue;
        dst = temp;
        for (remaining = 40; remaining != 0; remaining = remaining - 1) {
            unit = *src;
            *dst = unit;
            if (unit != -1) {
                count = count + 1;
                dst = dst + 1;
            }
            src = src + 1;
        }
        md->player->command_create_group(commander, temp, count, 4.0f);
    }
}

// ---------------------------------------------------------------------------
// PDB source owner: 004EB430_currentHitPoints.cpp
// ---------------------------------------------------------------------------
// first pass: 40-entry scan over unit ids, skipping -1 slots and summing floored hit points
// if this is close but not exact, the remaining mismatch is likely just the loop counter / accumulator register basin




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

// ---------------------------------------------------------------------------
// PDB source owner: 004EB470_originalHitPoints.cpp
// ---------------------------------------------------------------------------
int TacticalAIGroup::originalHitPoints() const { return this->originalHitPointsValue; }

// ---------------------------------------------------------------------------
// PDB source owner: 004EB480_setOriginalHitPoints.cpp
// ---------------------------------------------------------------------------
void TacticalAIGroup::setOriginalHitPoints(int val) { this->originalHitPointsValue = val; }

// ---------------------------------------------------------------------------
// PDB source owner: 004EB490_originalUnitNumber.cpp
// ---------------------------------------------------------------------------
int TacticalAIGroup::originalUnitNumber() const { return this->originalUnitNumberValue; }

// ---------------------------------------------------------------------------
// PDB source owner: 004EB4A0_setOriginalUnitNumber.cpp
// ---------------------------------------------------------------------------
void TacticalAIGroup::setOriginalUnitNumber(int val) { this->originalUnitNumberValue = val; }

// ---------------------------------------------------------------------------
// PDB source owner: 004EB4B0_location.cpp
// ---------------------------------------------------------------------------
const Waypoint & TacticalAIGroup::location() const { return this->locationValue; }

// ---------------------------------------------------------------------------
// PDB source owner: 004EB4C0_setLocation.cpp
// ---------------------------------------------------------------------------

void TacticalAIGroup::setLocation(float a, float b, float c) {
    this->locationValue.x = a;
    this->locationValue.y = b;
    this->locationValue.z = c;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004EB4F0_action.cpp
// ---------------------------------------------------------------------------
int TacticalAIGroup::action() const { return this->actionValue; }

// ---------------------------------------------------------------------------
// PDB source owner: 004EB500_setAction.cpp
// ---------------------------------------------------------------------------
void TacticalAIGroup::setAction(int val) { this->actionValue = val; }

// ---------------------------------------------------------------------------
// PDB source owner: 004EB510_target.cpp
// ---------------------------------------------------------------------------
int TacticalAIGroup::target() const { return this->targetValue; }

// ---------------------------------------------------------------------------
// PDB source owner: 004EB520_setTarget.cpp
// ---------------------------------------------------------------------------
void TacticalAIGroup::setTarget(int val) { this->targetValue = val; }

// ---------------------------------------------------------------------------
// PDB source owner: 004EB530_targetType.cpp
// ---------------------------------------------------------------------------
int TacticalAIGroup::targetType() const { return this->targetTypeValue; }

// ---------------------------------------------------------------------------
// PDB source owner: 004EB540_setTargetType.cpp
// ---------------------------------------------------------------------------
void TacticalAIGroup::setTargetType(int val) { this->targetTypeValue = val; }

// ---------------------------------------------------------------------------
// PDB source owner: 004EB550_targetLocation.cpp
// ---------------------------------------------------------------------------
const Waypoint & TacticalAIGroup::targetLocation() const { return this->targetLocationValue; }

// ---------------------------------------------------------------------------
// PDB source owner: 004EB560_setAllLocations.cpp
// ---------------------------------------------------------------------------
// From taitacmd.cpp
// The location fields are Waypoint float members in the canonical class.
// This preserves direct float stores in the grouped wrapper.
// Final grouped audit: MATCH, 0.0000%, 93/93 bytes.


void TacticalAIGroup::setAllLocations(float p1, float p2, float p3) {
    this->locationValue.x = p1;
    this->locationValue.y = p2;
    this->locationValue.z = p3;
    this->gatherLocationValue.x = p1;
    this->gatherLocationValue.y = p2;
    this->gatherLocationValue.z = p3;
    this->retreatLocationValue.x = p1;
    this->retreatLocationValue.y = p2;
    this->retreatLocationValue.z = p3;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004EB5C0_setTargetLocation.cpp
// ---------------------------------------------------------------------------

void TacticalAIGroup::setTargetLocation(float a, float b, float c) {
    this->targetLocationValue.x = a;
    this->targetLocationValue.y = b;
    this->targetLocationValue.z = c;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004EB5F0_gatherLocation.cpp
// ---------------------------------------------------------------------------
const Waypoint & TacticalAIGroup::gatherLocation() const { return this->gatherLocationValue; }

// ---------------------------------------------------------------------------
// PDB source owner: 004EB600_setGatherLocation.cpp
// ---------------------------------------------------------------------------

void TacticalAIGroup::setGatherLocation(float a, float b, float c) {
    this->gatherLocationValue.x = a;
    this->gatherLocationValue.y = b;
    this->gatherLocationValue.z = c;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004EB630_retreatLocation.cpp
// ---------------------------------------------------------------------------
const Waypoint & TacticalAIGroup::retreatLocation() const { return this->retreatLocationValue; }

// ---------------------------------------------------------------------------
// PDB source owner: 004EB640_setRetreatLocation.cpp
// ---------------------------------------------------------------------------

void TacticalAIGroup::setRetreatLocation(float a, float b, float c) {
    this->retreatLocationValue.x = a;
    this->retreatLocationValue.y = b;
    this->retreatLocationValue.z = c;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004EB670_priority.cpp
// ---------------------------------------------------------------------------
int TacticalAIGroup::priority() const { return this->priorityValue; }

// ---------------------------------------------------------------------------
// PDB source owner: 004EB680_setPriority.cpp
// ---------------------------------------------------------------------------
void TacticalAIGroup::setPriority(int val) { this->priorityValue = val; }

// ---------------------------------------------------------------------------
// PDB source owner: 004EB690_waitCode.cpp
// ---------------------------------------------------------------------------
int TacticalAIGroup::waitCode() const { return this->waitCodeValue; }

// ---------------------------------------------------------------------------
// PDB source owner: 004EB6A0_setWaitCode.cpp
// ---------------------------------------------------------------------------
void TacticalAIGroup::setWaitCode(int val) { this->waitCodeValue = val; }

// ---------------------------------------------------------------------------
// PDB source owner: 004EB6B0_assistGroupID.cpp
// ---------------------------------------------------------------------------
int TacticalAIGroup::assistGroupID() const { return this->assistGroupIDValue; }

// ---------------------------------------------------------------------------
// PDB source owner: 004EB6C0_setAssistGroupID.cpp
// ---------------------------------------------------------------------------
void TacticalAIGroup::setAssistGroupID(int val) { this->assistGroupIDValue = val; }

// ---------------------------------------------------------------------------
// PDB source owner: 004EB6D0_assistGroupType.cpp
// ---------------------------------------------------------------------------
int TacticalAIGroup::assistGroupType() const { return this->assistGroupTypeValue; }

// ---------------------------------------------------------------------------
// PDB source owner: 004EB6E0_setAssistGroupType.cpp
// ---------------------------------------------------------------------------
void TacticalAIGroup::setAssistGroupType(int val) { this->assistGroupTypeValue = val; }

// ---------------------------------------------------------------------------
// PDB source owner: 004EB6F0_task.cpp
// ---------------------------------------------------------------------------
// 004EB6F0 TacticalAIGroup::task(TribeTacticalAIModule*, TribeMainDecisionAIModule*, int, int, int)
// Source: taitacmd.cpp lines 735-1481
// First pass from packet/original asm plus Ghidra as a behavior guide; deliberately naturalized loops/call surfaces.
// Attempt log:
// - initial skeleton: modeled proven TacticalAIGroup layout from inventory/types and original asm; kept direct predicate calls and simple 40-slot scans.
// - check_function 2026-04-29: first scaffold compiled but .text was 2832 bytes vs original 5679, too skeletal for byte diff extraction.
// - expanded duplicated natural case bodies/log calls for water/explorer/defend/roundup paths; corrected master_obj->los to +0x28.
// - current check_function: MISMATCH, 4384/5679 positional bytes (77.1967%), first mismatch offset 6.
// - current prologue drift: rebuilt frame is 0x20 and uses EBX for taskID / EBP=-1; original frame is 0x1c and keeps taskID in EBP with EBX zero. Next pass should reduce artificial locals/dead grouped-case code rather than adding more bloat.
// - probe A removed impossible taskID==20 block from case 2/21: kept; eliminated rebuilt EBP=-1 materialization, now immediate cmp -1, but frame/taskID register unchanged.
// - split gather case 9/14: no prologue improvement; kept as less taskID-live source, but behavior/log detail remains approximate.
// - moved broad function-scope locals into case scopes and simplified case 5/6/12/19 dead grouped tests: no frame change; slight positional improvement.
// - inlined floored_hp helper to direct (int)obj->hp because original uses local fld/__ftol not a source helper call; kept though prologue unchanged.
// - current check_function after probes: MISMATCH, 4353/5679 positional bytes (76.6508%), first mismatch offset 6; prologue still frame 0x20 and taskID in EBX.
// - shared original-like locals oHP/distance/min/max added and equivalent hp/distance/XY temps folded into them: no prologue/frame change.
// - removing unused local_4 after shared-local probe also no frame change; frame remains 0x20, so extra slot is not the byte temp alone.
// - reduced remaining taskID liveness in case 2/21 by deleting impossible taskID==20 checks in the body; positional diff improved to 4326/5679 (76.1754%) but prologue unchanged.
// - case0/1 parameter-slot reuse probe: using taskID as totalHP and busyOK as loop index was kept; rebuilt now writes the expected parameter-slot family (shifted by the extra 4-byte frame), but frame/prologue still unchanged.
// - case0/1 unitp[40] store probe kept because it matches original [unitp+0xA0] store and removes rebuilt unitsOriginal pointer temp, though positional diff worsened locally (current 4344/5679).
// - broad zero-local and register unitp probes did not move EBX/taskID or frame; rolled back.
// - temporary deletion of playNumber allocation block did not change 0x20 frame; rolled back, so extra frame slot is not just play-list locals.
// - split case 21 from case 2 to remove taskID use in body gave only tiny positional improvement and no prologue change; current source keeps split but behavior remains approximate.
// - direct owner->id in taskAttacker calls kept; original asm directly loads owner id, no null-owner ternary.
// - case5/6/12/19 HP-only group also converted to taskID/busyOK parameter-slot reuse plus unitp[40], matching original HP-summing topology; prologue unchanged.
// - current check_function: MISMATCH, 4326/5679 positional bytes (76.1754%), first mismatch offset 6; still frame 0x20 vs original 0x1c.
// - moved min/max from shared top-level locals into attack-memory block: frame fixed to original 0x1c and first mismatch moved from offset 6 to 8; kept.
// - broad zero-local probe after frame fix still did not make EBX the zero register; rolled back.
// - converted cases 8/10/11/7/4 to the same taskID/busyOK parameter-slot HP/index reuse and unitp[40] topology; positional diff improved to 4273/5679 (75.2421%), prologue still uses EBX for taskID instead of original EBP.
// - current check_function: MISMATCH, 4273/5679 positional bytes (75.2421%), first mismatch offset 8; frame now matches 0x1c.
// - top-level unitp and taskSlot/address-taken taskID probes did not move EBX/EBP; rolled back.
// - converted cases 8/10/11/7/4 to parameter-slot HP/index reuse; kept, improved positional diff to current 4273 bytes.
// - tried same parameter-slot conversion for case20 but worsened to 4282 bytes and did not affect prologue; rolled back.
// - added binary-observed attack-opening log/play-number checks to case 2 and 21 from original/decomp; kept because it improves behavioral surface and edit-resync equality even though positional diff is essentially unchanged (4274 bytes).
// - recombining case 2/21 as the original source likely did shrank .text below original (5664 vs 5679 before adding other missing details), so rolled back for now; clue says split is not source-faithful but remaining body is still under-modeled.
// - adding full attack-memory waypoint min/max refinement caused a pressure cliff (frame 0x24, first mismatch offset 6); rolled back until the surrounding attack block has the right topology.
// - allocation-failure log in playNumber attack path is binary-observed but perturbed early layout and worsened positional diff to 4308; rolled back for now as a pressure/layout clue.
// - recombined gather case 9/14 per original source shape; kept because behavior/call count is closer and positional diff improved versus the logged attack-open baseline (current 4287/5679), though edit-resync worsened.
// - task-local alias for switch variable produced identical bytes; rolled back, so EBX-vs-EBP prologue drift is not fixed by a simple local copy.
// - current check_function: MISMATCH, 4287/5679 positional bytes (75.4886%), first mismatch offset 8; frame remains correct 0x1c but taskID still in EBX instead of original EBP, and EBX zeroing is still missing.
// - top-level explicit zero local reused through common zero stores produced identical bytes; rolled back.
// - fixed case 2/21 busy gate to match original/decomp: only a 600 action with non-0x1b target type skips, not every non-idle action; behavior kept despite local positional worsening.
// - fixed playNumber path in case 2/21 so individual tasking is skipped while accumulating HP/list for taskPlay; kept, improves positional diff to 4268/5679.
// - retested recombining case 2/21 after playNumber fix: .text shrank drastically (5184 vs 5679), still too under-modeled for a shared source block; rolled back.
// - current check_function: MISMATCH, 4268/5679 positional bytes (75.1541%), first mismatch offset 8.
// - physical case-order probe (moving 7/8 before 20 etc. to match PDB/original block order) improved edit-resync but worsened positional and caused the no-commander return to be outlined; rolled back to current source order for now.
// - binary-proven MainDecision surface kept: player is at +0xF0, informationAI at +0xCEC, time is md->player->world->world_time, and player id comes from md->player->id; this worsens current positional diff but fixes real offsets used in attack/roundup paths.
// - changed gather zone local to int so uchar currentZone/lookupZone returns are masked to 0xff like original; kept as width/topology evidence even though register allocation remains swapped.
// - commander test variants with explicit goto/unsigned + 1: unsigned + 1 restored inline no-commander layout and improved the MD-surface diff to 4293 bytes but generated LEA/TEST instead of original CMP -1; rolled back to natural equality.
// - Investigator byte-zero probe follow-up: zero locals/assignments and (unsigned char)busyOK after busyOK=0 still optimized to an immediate zero or ECX/EBP zero; no EBX zero.
// - direct reset from busyOK (`consecutiveGatherAttemptsValue=(unsigned char)busyOK`) is behaviorally wrong but important evidence: it makes taskID live in EBP and emits `mov [esi+2C8h],bl`/EBP switch, while preserving busyOK in EBX and perturbing the first log argument loads. This suggests the missing lever is not the byte store alone, but creating an EBX byte-capable zero rather than an EBX busyOK.
// - variants using `busyOK-busyOK`, char/uchar zero locals, and zero reused in case initializers either folded to immediate zero or used CL; rolled back.
// - natural case0/1 rewrite with totalHP/i/unitID locals and array indexing instead of parameter-slot/pointer reuse improved positional diff to 4328 but worsened edit-resync equality and did not move the EBX-taskID/EBP-zero prologue; rolled back because original asm's case0 stack-slot/pointer topology is closer to the current parameter-reuse form.
// - current check_function after MD/zone surface fix: MISMATCH, 4342/5679 positional bytes (76.4571%), first mismatch offset 8; prologue still taskID in EBX instead of original EBP and now zero in EBP, so the remaining blocker is whole-function register pressure/topology.
// - explicit fallthrough label did not force original short JNE; restored source-like early no-commander return.
// - case0 declaration-order probe (unitp before obj) produced identical bytes; kept as harmless source-order evidence.
// - assignment-expression/volatile HP accumulation probes in case0/1 did not change scheduling; rolled back to source-like store then add.
// - commander local probe produced identical bytes; kept because it matches decompiler/source pTVar11 but does not fix EBX/EBP allocation.
// - PDB line-map pass: sharing all tails with a resultValue local improved positional only slightly but caused frame 0x20; rolled back result local, kept return-1 shared tail shape.
// - PDB physical order probe: moved case 7/debug_rand block after retreat case 3 to match line map around 938 before later attack cases.
// - PDB physical order probe: moved explorer case 8 after case 7 before attack cases to follow early line-map blocks.
// - PDB physical-order/diff probes plateaued; user requested a full faithful fact-based rewrite pass ignoring local diff. Reordered switch to decompiler/PDB source order: 0/1, shared 2/21, 3, 4, 5/6/12/19, 7, 8, 9/14, 10, 11, 20.
// - local inline/goto firstTime tails for case0/1 perturbed block order badly; rolled back to shared tail despite missing local compare.
// - PDB lines 801/828 show lookupZone gets ftol(y) pushed before ftol(x), meaning source args are (x,y); fixed gather lookups from decompiler-reversed (y,x).
// - PDB/source line-map recombine of attack cases 2/21 shrank .text to 5152/5168, but kept per user request as source-faithful; now filling missing logic instead of optimizing diff.
// - PDB line 877/decomp show gather distance is truncated to int before clamp/priority, not kept as float; changed gather block to int distance topology.
// - faithful rewrite pass: restored decomp-observed retreat logs, attack-memory setup log, case4 split strategic-number branches, and roundup waited-enough/target-location logs rather than chasing local byte diff.
// - faithful rewrite pass: case20 now uses unitp[40] HP topology and includes the pre-subtype unit log plus defender-branch log from decomp.
// - faithful rewrite pass: shared attack case now also writes HP through unitp[40], matching decomp's piVar10[0x28] topology.
// - faithful rewrite pass: case20 busy gate now re-calls currentAction like decomp instead of only testing the saved logged action.
// - faithful rewrite pass: grouped HP/tasking busy logs restored to unit+action varargs; original asm shows the second currentAction result is logged.
// - faithful rewrite pass: shared attack currentAction log restored to pass the action value for the binary-observed CurrentAction %d log.
// - faithful rewrite pass: attack-memory waypoint refinement corrected to compare/replace x bounds with previous waypoint x and y bounds with previous waypoint y per decomp.
// - faithful rewrite pass: case20 currentAction log restored to pass the action value for the binary-observed CurrentAction %d log.
// - faithful rewrite pass: commander/non-commander water/explorer branch logs adjusted to original asm where visible; case7/case10/case11 defender logs carry unit id.
// - faithful rewrite pass: case20 busy log no longer consumes a third currentAction as a vararg; decomp logs the unit id only on busy skip.
// - faithful rewrite pass: placed default before case20 to mirror decompiler/source switch order.
// - faithful rewrite pass: case20 defender-branch log corrected to original unit+target varargs before taskDefender.
// - local_4-only top-y byte probe still caused frame 0x20; rolled back to direct max.y cast while keeping explicit info pointer.
// - restored an explicit informationAI pointer inside attack-memory setup; original asm carries this_00/EBX through mapBound/storeAttackMemory, while avoiding the byte-local pressure cliff.
// - faithful rewrite pass: shared attack body now uses source-like `if (playNumberValue == -1)` wrapper instead of early continue.
// - waypoint-count byte materialization matches decomp but is not kept in source because it created a frame-size pressure cliff; direct expression preserves behavior.
// - pressure/fidelity pass: removed artificial priority local in important-leader defender branch; constant 99 is source-equivalent and may reduce frame pressure.
// - faithful rewrite pass: play-list construction uses source/decomp-like pointer plus countdown loop and shift-size allocation like decomp.
// - pressure/fidelity pass: direct attack-open lastAttackRoundupTime assignment is source-equivalent and reduces artificial local pressure.
// - faithful rewrite pass: roundup current-time local compacted code and was less source-faithful to decomp's reload; rolled back.
// - faithful rewrite pass: owner ids passed to taskAttacker explicitly cast through int like decomp's owner->id use.
// - attack-memory store now materializes player/target owner bytes before the call, matching original byte-load surface.
// - faithful rewrite pass: case20 playNumber handling restored to decomp/original: log and return 0 immediately, unlike attack case taskPlay path.
// - faithful rewrite pass: attack-task logs now mirror original pushes: subtype log includes unit+subtype, target-null log includes unit+target, target log includes unit+target; leader-defender/direct-task logs use no extra unit arg.
// - faithful rewrite pass: gather invalid/out-of-zone path directly removeUnitByIndex; original failure block has no logGroupDebug.
// - introduced distinct mutable log-string placeholders for most logGroupDebug call sites; original source used distinct messages, and this prevents VC5 from merging unrelated log/return blocks.
// - relocation-symbol audit after string split: logs/object/remove/taskDefender/strategic match; re-expanded attack cached-ai calls to align unitAI/currentAction topology.
// - explicit case0/1 firstTime tail probe: exact size restored to 5679 and positional diff improved slightly to 4026/5679; rebuilt now emits the local compare/early return shape, but the shared store-return tail still lands at 004ECC82 instead of original 004ECC06.
// - split attack-family firstTime tail from the generic post-switch store tail (cases 2/21 and 20 now jump to a zero-waypoints tail): slight improvement to 4019/5679 and cleaner original-like separate return families, but the generic store-return tail is still physically too late.
// - corrected return-family facts from original asm: case 0/1, case 8, and case 11 use the store+return-0 tail; case 5/6/12/19 actually join the return-1 store tail despite decompiler noise. This is source-fact cleanup first, though current positional diff is 4056/5679.
// - tried a shared `return_zero_tail_dispatch` to mimic the original local compare/jump shape, but it moved a huge block earlier and worsened to 4071/5679; rolled back.
// - focused variant_lab on only the case0/1 post-loop tail (`build/variant_lab/004EB6F0_task/20260430_105809`): 8 spellings collapsed to 2 asm groups. Best group is the existing store-then-test family (4067/5679, first mismatch 313); split-branch forms all worsened to a context-tail group (4070/5679, first mismatch 110).
// - changed case7 from local firstTime store/return to the shared return-1 tail (`if(firstTime!=1)return 1; goto store_return_one;`): improved positional diff to 4040/5679, though first mismatch moved back to offset 110. Kept as the current best global result.
// - probed case10 indexed loop form, case11 pointer loop form, and store tail label ordering: all compiled to the same 4040/5679 asm family, so these local loop spelling axes are currently saturated.
// - tried making case4 use a local firstTime store/return instead of the shared return-1 tail: worsened to 4072/5679 with first mismatch 313, so rolled back to shared tail.
// - probed default-case local temps to force original-like `idValue` load before vararg pushes; VC5 emitted identical code, rolled back to natural direct log call.
// - corrected case20 tail from zero-waypoint store tail to ordinary store_return_one; original case20 tail stores HP/unit only (zero-waypoint tail belongs earlier attack-family case). Improved 4040 -> 4038.
// - also probed case20 non-firstTime as return 0 to match original branch-to-zero-return shape; kept because behavior/asm tail is closer though total diff remained 4038.
// - tried removing cached case20 UnitAIModule* and using direct obj->unitAI() calls; worsened to 4039, rolled back to cached ai.
// - corrected more firstTime return-family facts from original branch targets: cases 0/1, 4, 7, 8, 10, 11, 2/21, and 20 branch to the common return-one epilogue when firstTime != 1, while firstTime==1 stores original HP/unit and returns 1. Only the grouped HP-only case branches to the zero epilogue/store-return-zero family.
// - probed case5/6/12/19 store-return-zero despite decompiler text; worsened to 4054, confirming original asm's `eax=1` tail. Rolled back.
// - moved gather case 9/14 physically after case0/1 to match original block order (004EB845 immediately follows case0 tail); kept, improved positional 4030->3989 and edit equal 1743->2355.
// - corrected case0/1 firstTime tail after re-reading original asm: firstTime!=1 branches to shared zero epilogue; firstTime==1 stores original HP/unit and returns 1. This improved positional 4003->3966 and edit equality 2994->3442.
// - late shared-zero tail probes: both case11/grouped together improved edit equality but worsened positional; grouped-only worsened both versus case0-zero baseline, so grouped tail rolled back.
// - split store tail with case0 prewriting originalHitPoints shrank .text to 5664 and is wrong; rolled back.
// - physical placement of store_return_one label before case20 compiled to identical bytes; rolled back to keep source cleaner.
// - case0 via oHP-carried store tail improved positional 3966->3945 and emits original local load/store sequence but inlines the tail; kept as a lead.
// - second use of oHP store tail from case20 improved edit equality but worsened positional 3945->4044; rolled back.
// - case7 shared zero-tail goto improved edit equality but worsened positional 3945->4032; rolled back.
// - case8 shared zero-tail goto produced identical bytes; kept as shared-tail source intent.
// - case4 shared zero-tail goto improved edit equality but worsened positional 3945->4010; rolled back.
// - case4 through oHP store tail worsened positional/edit alone; rolled back.
// - focused mini-lab over case4/case7/case10 shared-zero/oHP tails (18 combos): current remains best positional (3945). Best edit combo was c4ohp+c7zero+c10zero at positional 4049/edit 3025; closest default jump was c4ohp+c7zero+c10ohp (rebuilt ja 0x159a vs original 0x159e) but positional worsened to 4103, so not kept.
// - rechecked closest-jump combo separately; it keeps case0 as a jump to a much earlier store tail (004ECA83), explaining better default distance but worse positional layout.
// - moving store_return_one_from_oHP label before case20 compiled identically; busyOK-carried variant for the case0 accumulator also compiled identically. Later case8 truthful tail made direct case0 store_return_one sufficient, so the oHP-carried case0 tail was removed.
// - xref audit: original jumps to store_return_one tail at 004ECC06 from case0 and case8 only; original case4/7/10/11/group tails go to other local/shared tails or zero epilogue. This explains why adding oHP tail users from those cases worsened positional.
// - case8 oHP zero-tail variant compiled identically; current case8 shared-zero + store_return_zero source kept.
// - probing case8 firstTime==1 as store_return_one after xref audit shrank .text to 5648; rolled back despite original tail xref, indicating surrounding case8 source/body still under-modeled or case mapping needs care.
// - case8 pointer-loop/parameter-slot topology from decomp/original (param_1 accumulator, param_3 index, piVar10 pointer) compiled identically with store_return_zero; kept as source-faithful.
// - converted case4 to the same pointer-loop/unitp[40] topology as original/decomp; source-fidelity probe changed only a tiny local byte set while keeping .text 5648.
// - converted case10 to pointer-loop/unitp[40] topology as original/decomp; testing source-fidelity over size.
// - case4 oHP-tail after pointer conversion inflated .text to 5696 and inlined a local store tail rather than matching original 004ECA6B shared tail; rolled back.
// - after case8 was changed to the truthful store_return_one tail, case0 no longer needs the oHP-carried tail: direct `goto store_return_one` emits the desired shared-tail jump sequence. Simplified case0 accordingly.
// - added separate store_return_one_mid for case4/case10, matching original second shared store tail family at 004ECA6B distinct from case0/case8 tail 004ECC06. It worsens current byte metrics and grows .text to 5728, but is a source-fact correction under the new fidelity-first pass.
// - routed case11 non-firstTime through shared zero tail and firstTime path through store_return_one_mid; edit equality improved substantially (2736->3693) while keeping .text 5728, so kept as the next fidelity/layout lead.
// - routed grouped HP-only case5/6/12/19 through shared zero tail/store_return_one_mid; edit diff improved further (3135->3278? lower than prior baseline but edit equal 3687 slightly below case11-only 3693) and this aligns with tail-family direction, so kept for now under fidelity-first pass.
// - original audit correction: the physical block after 004ECA87 (case11 strings) joins the late store tail at 004ECC06, while the following HP-only block stores then returns 0 at 004ECCE2..004ECCF4. Re-routed case11 to store_return_one and grouped case5/6/12/19 to store_return_zero despite metric risk; metrics improved markedly.
// - checked case0/1 inUse store: original loads eax=1 for firstTime compare but stores ebx(0) to [esi+10] at 004EB833, so kept inUseValue=0; local one-temp compare spelling emitted identical code and was rolled back.
// - probed case7 into store_return_one_mid/shared zero; worsened edit equality (3687->3410) and shrank .text to 5696, so rolled back. Case7 likely has a separate/local tail family.
// - converted case20 roundup loop to pointer-loop/busyOK topology with explicit case20_next label; byte metrics nearly unchanged (edit equal 3669 vs 3687) but source shape now matches the other HP loops and decomp better, so kept.
// - probed routing case20 to mid tail under 004EC8D9 hypothesis; metrics worsened badly (edit equal 3773->3335), and 004EC8D9 more likely belongs to case4/case10 family, so rolled case20 back to late store_return_one.
// - tried converting shared attack case2/21 to pointer-loop/busyOK topology; edit equality worsened (3687->3611) and source needed awkward gotos across declarations, so rolled back for now.
// - per xref audit, changed case8 firstTime==1 to store_return_one despite shrinking .text to 5648; size is less important than truthful tail ownership while filling missing logic. This now emits case0/case8 jumps to the shared store tail.
// - changed gather attempt increment from !=0xff to <0xff; kept, matches original CMP/JAE spelling and improves edit equal by one byte.
// - named `one` in case0 firstTime compare produced identical bytes; rolled back.
// - restored gather nearDist/gatherDist to float topology; original asm stores strategicNumber via fild/fstp and keeps distance as float, not int truncation.
// - gather nearDist declaration at case scope swapped gi/nearDist slots ([esp+10]/[esp+30]) and produced identical total diff; rolled back to inner declaration.
// - gather null commander object as explicit goto return_zero_tail produced identical bytes; kept as source documentation of original shared-zero intent.
// - reuse of outer `distance` as gather nearDist moved the loop index to [esp+10] and produced identical total diff; rolled back to preserve original-like loop index slot.
// - gather compare spelling `gatherDist >= nearDist` kept; improves edit equality by one byte and matches original FPU load/test polarity better.
// - probing declaration order `gi; nearDist; unitp` to see if nearDist/loop-index stack slots swap toward original.
// - physical switch-order probe moving attack case 2/21 after case20 worsened positional 4020->4034 and edit equality 2473->2043; rolled back.
// - physical switch-order probe moving retreat case3 before attack case2/21 kept positional 4020 but worsened edit equality 2473->1748; rolled back.
// - physical switch-order probe moving case20 before attack improved positional 4020->3996 but worsened edit equality; kept temporarily as original-label-order lead.
// - physical switch-order probe moving grouped HP-only case5/6/12/19 near end improved positional 3996->3991; kept temporarily.
// - probing full original label order: move cases 3,7,8 before case20.
// - confirmed original jump table order directly from empiresx.exe: 0/1, 9/14, 3, 7, 8, 20, 2/21, 4, 10, 11, 5/6/12/19, default; current physical source order follows it.
// - current validation: MISMATCH, 3884/5679 positional bytes (68.3923%), edit equal 3773, first mismatch offset 313; first 313 bytes are exact.
// - case0 tail variants with duplicate firstTime tests, one/ft locals, volatile firstTime, and explicit taskID reload all compiled to the same cmp-eax-imm/store-before-compare family or worsened.
// - changing case0/8/11 non-firstTime paths to literal return-one is binary/behavior plausible from original epilogue xrefs, but VC5 inlined a local store/return tail near case0 and worsened first mismatch to offset 110; rolled back to preserve current best layout.
// - behavior-fix pass: original branches to 004ECD15 return-one (no xor) for the non-firstTime paths of cases 0/1, 4, 7, 8, 10, 11, 2/21, and 20; updated these from the older zero-tail approximation. Metrics worsen, but this restores the binary-observed return value.
// - case0/1 now uses source-like `break` to a common post-switch firstTime store. This reproduces the original compare/mov-one/cmp/store scheduling for that local tail, though the compiler still places the common tail too early versus original.
// - current validation after behavior/tail fixes: MISMATCH, 4062/5679 positional bytes (71.5267%), edit equal 2922, first mismatch offset 110; local case0 tail bytes now match through the compare/store sequence, but jump-table/default displacement and common-tail placement drift remain.
// - tested making case4/7/8/10/11 individually or collectively `break` to the post-switch store tail: VC5 either inlined the common return near case0 or shrank .text to 5648, all worse; rolled back except case0's source-like break.
// - combined source-like break for case4/case10/case11 plus an explicit case0 non-firstTime return-one guard improves both metrics (4014 positional, 3502 edit equal); kept temporarily.
// - restored case4 to the local `store_return_one_mid` tail too: original has the case4/case10 store/return tail before the next case, and breaking case4 made case10/case11/default blocks too early.
// - re-audited original case20 tail: 004EC189 jumps to return-one on firstTime!=1, but firstTime==1 loads the HP total then joins the zero-waypoint tail at 004EC6FA. Restored case20 to `store_return_one_zero_waypoints` despite a metric regression.
// - current validation after case20 correction: MISMATCH, 4062/5679 positional bytes (71.5267%), edit equal 2567, first mismatch offset 110.
// - restored case10 to its local `store_return_one_mid` tail: original has an inline store/return tail immediately before case11, so breaking case10 to the post-switch tail made all later blocks ~45 bytes early.
// - moved case20 HP-total assignment after the firstTime check to mirror original scheduling (`cmp firstTime,1; mov inUse,1; jne return; load total; join zero-waypoint tail`). This worsens positional slightly but fixes a real local ordering fact.
// - applied the same delayed HP-total assignment to attack case2/21; this is a real original tail fact and improves current metrics to 4013 positional / 3398 edit equal.
// - storedHP temp probes for case7/case8 firstTime tails compiled identically; rolled back.
// - case4/case10 tail audit: original case4 falls through to a firstTime check then jumps to the mid store tail at 004ECA6B; original case10 owns the same mid tail immediately before case11. Restored both to `store_return_one_mid`; current metrics are 4056 positional / 3357 edit equal, first mismatch 110.
// - removing the explicit case10 goto and letting it fall through to `store_return_one_mid` compiled identically; VC5 still moved the mid store tail after case11.
// - tried forcing case4's mid store tail inline with explicit assignments/returns; VC5 still merged it to the later shared tail or worsened layout, so kept the shared label.
// - tried case11 accumulator/index as separate locals and as reused `tactical` parameter slot with a saved tactical pointer; both worsened and did not recover the original case11 stack-slot topology. Restored the simpler taskID/busyOK form.
// - tried routing case11 to store_return_one instead of the post-switch break; this badly worsened edit equality, confirming the source-like break remains the better shape for now.
// - revisited case11 parameter-slot reuse more directly: original uses [esp+30] (incoming tactical parameter slot) as the HP accumulator while preserving the tactical pointer in a register. Kept a local saved tactical pointer plus tactical-as-accumulator form because it improves positional diff substantially and brings the switch default target closer (rebuilt displacement 0x157c vs original 0x159e), even though EBX/EDI coloring is still wrong and needs a later pass.
// - tried the same [esp+30] tactical-parameter-slot accumulator in case4/case10. Direct local store/return improved positional bytes but moved the switch default before later case bodies (rebuilt displacement 0x13ed), contradicting the original jump-table order, so rolled it back to the shared `store_return_one_mid` shape.
// - probed case11 using `taskID` as the loop index to force [esp+38] instead of [esp+40]; stack slot matched that local original clue but positional worsened by one byte with no edit gain, so left the index in `busyOK` for now.
// - rewrote gather case 9/14 from one combined `u && ai && zone` condition into explicit bad-object removal plus `else if (zone == ...)`. Positional worsened slightly but edit equality jumped 2716->3657, confirming this is the closer resync/source shape for the first real post-displacement hunk.
// - inverted gather distance source to `if (gatherDist < nearDist) stop else group` so the stop/currentOrder path is inline and the group path is the taken branch, matching original block polarity around the FPU compare.
// - changed gather zone mismatch to an explicit `!= zone` removal arm; this recovered the original `je`-to-valid-body branch family and improved positional diff 3911->3494 with exact equality through the gather loop compare hunk.
// - case3 retreat FPU/log audit: spelling the range gate as `distance < los*1/3` with the no-move log first recovered the original `fxch; fcompp` sequence; correcting that log's vararg from master object to unit id improved positional diff to 2869.
// - moved case7 accumulator zero before debug_rand to match the observed line order; slight improvement to 2848 bytes, but stack slots still differ (`roll`/accumulator/index are [30]/[38]/[40] rebuilt vs [18]/[30]/[38] original).
// - converted case7 to reuse the incoming tactical parameter slot as the HP accumulator (with a saved tactical pointer), matching original [esp+30] accumulator and [esp+38] index topology. Positional worsened to 3288 but edit equality improved to 3940 and the first switch displacement moved much closer (0x1599 vs original 0x159e). Kept as a layout/fidelity lead; remaining local drift is EB P/EDI coloring (saved tactical in EBP, unit pointer in EDI) vs original tactical in EDI, unit pointer in EBP, plus roll still at [esp+40] instead of original [esp+18].
// - register keyword and a far label for the case7 tactical-accumulator tail compiled identically; kept no keyword and source label only where useful.
// - tactical-parameter-slot accumulator variant plus raw `*(int*)&tactical` call-surface probe worsened (3340 positional/3719 edit equal) and risked wrong call receiver; rolled back to the better positional case7 shape. A top-level rollScratch and unitp/tt declaration-order/register probes compiled identically.
// - resumed narrow pass: packet asm shows case4 distance stays as an FPU value into calculatePriority; removed the unsupported int truncation. Calls now have exact aggregate target counts, with 3298 positional bytes and 105 bytes of extra code; left as best typed reconstruction.
// - final unresolved pass: removing the unused attack-case UnitAIModule cache removed one extra unitAI call and reached 2884 bytes, but direct case20 re-fetches are required by the original call sequence.
// - final unresolved pass: direct target-null logging has no unit or target varargs; the successful roundup-target log has both unit and target IDs. This restored exact call cleanup and produced a 5679-byte rebuild with 3067 positional differences.
// - final unresolved pass: case11 uses a saved tactical receiver and a natural integer HP total. This is clearer than pointer arithmetic and keeps the original 207-call surface.
// - final unresolved pass: case10 keeps an explicit non-firstTime return-one. It improves exact block coverage without changing size or call counts.
// - final unresolved pass: 20 meaningful hypotheses tested. Current clean result is MISMATCH, 3067/5679 positional bytes, 5679-byte text, 0x1C frame, 99.52% call alignment, and 82.78% resync similarity. Remaining drift is block order, relocation-safe switch-table placement, and register/local topology.
// - focused second pass: 20 additional natural tail-order and local-topology hypotheses tested against the PDB bands and same-TU donors. Tail inversions, case-tail routing, function-scope XYPoint homes, parameter-home reuse, declaration order, and donor return types did not produce an exact result. All emitted-code changes were rejected; the pinned baseline remains.
// - third pass: binary assembly showed the case20 Getting-ready log pushes unit and subtype; adding the subtype fixed a real vararg behavior and reduced positional diff to 2569/5679.
// - third pass: positive non-null target and positive play-number guards match the original fallthrough polarity. The play guard reduced the result to 2549/5679, with 100% ordered call alignment and 61.12% exact-block coverage.
// - third pass: negative target guard, local declaration order, direct case4 distance assignment, and a corrected do/while scan were tested. The first three were duplicate or neutral; the do/while variant was rejected for size and call drift. Current source is the pinned 2549-byte result.


extern int __ftol();
extern int debug_rand(char*, int);
void* operator new(unsigned int);
void operator delete(void*);

static char s_file[] = "C:\\msdev\\work\\age1_x1\\taitacmd.cpp";
static char s0[] = "";
static char s_no_commander[] = "";
static char s_attack_play_alloc_fail[] = "";
static char s_unknown_task[] = "";
static char s_log_00[] = "";
static char s_log_01[] = "";
static char s_log_02[] = "";
static char s_log_03[] = "";
static char s_log_04[] = "";
static char s_log_05[] = "";
static char s_log_06[] = "";
static char s_log_07[] = "";
static char s_log_08[] = "";
static char s_log_09[] = "";
static char s_log_10[] = "";
static char s_log_11[] = "";
static char s_log_12[] = "";
static char s_log_13[] = "";
static char s_log_14[] = "";
static char s_log_15[] = "";
static char s_log_16[] = "";
static char s_log_17[] = "";
static char s_log_18[] = "";
static char s_log_19[] = "";
static char s_log_20[] = "";
static char s_log_21[] = "";
static char s_log_22[] = "";
static char s_log_23[] = "";
static char s_log_24[] = "";
static char s_log_25[] = "";
static char s_log_26[] = "";
static char s_log_27[] = "";
static char s_log_28[] = "";
static char s_log_29[] = "";
static char s_log_30[] = "";
static char s_log_31[] = "";
static char s_log_32[] = "";
static char s_log_33[] = "";
static char s_log_34[] = "";
static char s_log_35[] = "";
static char s_log_36[] = "";
static char s_log_37[] = "";
static char s_log_38[] = "";
static char s_log_39[] = "";
static char s_log_40[] = "";
static char s_log_41[] = "";
static char s_log_42[] = "";
static char s_log_43[] = "";
static char s_log_44[] = "";
static char s_log_45[] = "";
static char s_log_46[] = "";
static char s_log_47[] = "";
static char s_log_48[] = "";
static char s_log_49[] = "";
static char s_log_50[] = "";
static char s_log_51[] = "";
static char s_log_52[] = "";
static char s_log_53[] = "";
static char s_log_54[] = "";
static char s_log_55[] = "";
static char s_log_56[] = "";
static char s_log_57[] = "";
static char s_log_58[] = "";
static char s_log_59[] = "";
static char s_log_60[] = "";
static char s_log_61[] = "";
static char s_log_62[] = "";
static char s_log_63[] = "";
static char s_log_64[] = "";
static char s_log_65[] = "";
static char s_log_66[] = "";
static char s_log_67[] = "";
static char s_log_68[] = "";
static char s_log_69[] = "";
static char s_log_70[] = "";
static char s_log_71[] = "";
static char s_log_72[] = "";
static char s_log_73[] = "";
static char s_log_74[] = "";
static char s_log_75[] = "";
static char s_log_76[] = "";
static char s_log_77[] = "";
static char s_log_78[] = "";
static char s_log_79[] = "";
static char s_log_80[] = "";
static char s_log_81[] = "";
static char s_log_82[] = "";
static char s_log_83[] = "";
static char s_log_84[] = "";
static char s_log_85[] = "";
static char s_log_86[] = "";
static char s_log_87[] = "";
static char s_log_88[] = "";
static char s_log_89[] = "";


int TacticalAIGroup::task(TribeTacticalAIModule* tactical, TribeMainDecisionAIModule* md, int taskID, int firstTime, int busyOK)
{
    TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_00, taskID, firstTime, busyOK);

    int commander = commanderValue;
    if (commander == -1) {
        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_no_commander);
        return 0;
    }

    if (taskID != 9 && taskID != 14)
        consecutiveGatherAttemptsValue = 0;

    int oHP;
    float distance;
    switch (taskID) {
    case 0:
    case 1: {
        int i;
        RGE_Static_Object* obj;
        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_01);
        taskID = 0;
        for (i = 0; i < 40; ++i) {
            if (unitsValue[i] != -1) {
                TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_02, unitsValue[i]);
                obj = md->object(unitsValue[i]);
                if (obj == 0 || obj->unitAI() == 0) {
                    TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_03, unitsValue[i]);
                    removeUnitByIndex(i, md);
                } else {
                    taskID += (unitsOriginalHitPointsValue[i] = (int)obj->hp);
                    tactical->stopUnit(unitsValue[i], 100);
                }
            }
        }
        inUseValue = 0;
        if (firstTime != 1)
            goto return_one_tail;
        break;
    }


    case 9:
    case 14: {
        if (consecutiveGatherAttemptsValue < 0xff) consecutiveGatherAttemptsValue++;
        RGE_Static_Object* gatherObj = md->object(commanderValue);
        if (gatherObj == 0) goto return_zero_tail;
        int zone = gatherObj->currentZone();
        if (zone != gatherObj->lookupZone((int)gatherLocationValue.x, (int)gatherLocationValue.y))
            setGatherLocation(gatherObj->world_x, gatherObj->world_y, gatherObj->world_z);
        int gi;
        float nearDist;
        int* unitp;
        for (gi = 0, unitp = unitsValue; gi < 40; ++gi, ++unitp) {
            if (*unitp == -1) continue;
            RGE_Static_Object* u = md->object(*unitp);
            if (u == 0 || u->unitAI() == 0) {
                removeUnitByIndex(gi, md);
            } else if (gatherObj->lookupZone((int)u->world_x, (int)u->world_y) != zone) {
                removeUnitByIndex(gi, md);
            } else {
                if (busyOK == 0 && u->unitAI()->currentAction() != -1 && u->unitAI()->currentAction() != 0x266)
                    continue;
                if (taskID == 14)
                    nearDist = 0.0f;
                else
                    nearDist = (float)tactical->strategicNumber(0x29);
                float gatherDist = u->distance_to_position(gatherLocationValue.x, gatherLocationValue.y, gatherLocationValue.z) - 1.0f;
                if (gatherDist < 0.0f) gatherDist = 0.0f;
                if (gatherDist < nearDist) {
                    if (u->unitAI()->currentOrder() != -1)
                        tactical->stopUnit(*unitp, 100);
                } else {
                    tactical->groupGatherUnit(*unitp, commanderValue, gatherLocationValue.x, gatherLocationValue.y, gatherLocationValue.z, nearDist, tactical->calculatePriority(gatherDist));
                }
            }
        }
        return 1;
    }






    case 3: {
        int i;
        int* unitp;
        RGE_Static_Object* obj;
        float distance;
        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_19);
        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_20, retreatLocationValue.x, retreatLocationValue.y);
        for (i = 0, unitp = unitsValue; i < 40; ++i, ++unitp) {
            if (*unitp == -1) continue;
            TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_21, *unitp);
            obj = md->object(*unitp);
            if (obj == 0 || obj->unitAI() == 0) {
                TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_22, *unitp);
                removeUnitByIndex(i, md);
                continue;
            }
            distance = obj->distance_to_position(retreatLocationValue.x, retreatLocationValue.y, retreatLocationValue.z) - 1.0f;
            if (distance < 0.0f) distance = 0.0f;
            if (distance < obj->master_obj->los * 0.33333334f) {
                TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_24, *unitp);
            } else {
                TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_23, *unitp);
                tactical->moveUnit(*unitp, retreatLocationValue.x, retreatLocationValue.y, 100);
            }
        }
        return 1;
    }




    case 7: {
        int* unitp;
        RGE_Static_Object* obj;
        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_32);
        taskID = 0;
        int roll = debug_rand(s_file, 0x3af) % 100;
        busyOK = 0;
        unitp = unitsValue;
        do {
            if (*unitp != -1) {
                TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_33, *unitp);
                obj = md->object(*unitp);
                if (obj == 0 || obj->unitAI() == 0) {
                    TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_34, *unitp);
                    removeUnitByIndex(busyOK, md);
                } else {
                    oHP = ((int)obj->hp);
                    unitp[40] = oHP;
                    taskID += oHP;
                    if (busyOK == 0 && obj->unitAI()->currentAction() != -1) {
                        int busyAction = obj->unitAI()->currentAction();
                        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_35, *unitp, busyAction);
                    } else if (*unitp == commanderValue) {
                        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_36, *unitp);
                        tactical->taskExplorer(*unitp, 0);
                    } else if (roll < tactical->strategicNumber(200)) {
                        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_37, *unitp);
                        tactical->taskDefender(*unitp, commanderValue, obj->master_obj->los * 0.5f, 99);
                    } else {
                        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_38, *unitp);
                        tactical->taskExplorer(*unitp, 0);
                    }
                }
            }
            ++unitp;
            ++busyOK;
        } while (busyOK < 40);
        inUseValue = 1;
        if (firstTime != 1)
            goto return_one_tail;
        goto store_return_one;
    }




    case 8: {
        int* unitp;
        RGE_Static_Object* obj;
        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_39);
        taskID = 0;
        busyOK = 0;
        unitp = unitsValue;
        do {
            if (*unitp != -1) {
                TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_40, *unitp);
                obj = md->object(*unitp);
                if (obj == 0 || obj->unitAI() == 0) {
                    TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_41, *unitp);
                    removeUnitByIndex(busyOK, md);
                } else {
                    oHP = ((int)obj->hp);
                    unitp[40] = oHP;
                    taskID += oHP;
                    if (busyOK == 0 && obj->unitAI()->currentAction() != -1) {
                        int busyAction = obj->unitAI()->currentAction();
                        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_42, *unitp, busyAction);
                    } else {
                        tactical->taskExplorer(*unitp, 0);
                    }
                }
            }
            ++unitp;
            ++busyOK;
        } while (busyOK < 40);
        inUseValue = 1;
        if (firstTime != 1)
            goto return_one_tail;
        goto store_return_one;
    }






    case 20: {
        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_55, targetValue);
        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_56, targetLocationValue.x, targetLocationValue.y);
        int waited = (int)(md->player->world->world_time - lastAttackRoundupTime) / 1000;
        if (waited < 10) { TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_57, waited); return 0; }
        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_58, waited);
        lastAttackRoundupTime = md->player->world->world_time;
        if (playNumberValue != -1) {
            TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_59);
            return 0;
        }
        int stored20 = 0;
        busyOK = 0;
        int* unitp;
        RGE_Static_Object* obj;
        unitp = unitsValue;
        do {
            if (*unitp != -1) {
                TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_60, *unitp);
                obj = md->object(*unitp);
                if (obj == 0 || obj->unitAI() == 0) {
                    TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_61, *unitp);
                    removeUnitByIndex(busyOK, md);
                } else {
                    TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_62, obj->unitAI()->currentAction());
                    oHP = ((int)obj->hp); unitp[40] = oHP; stored20 += oHP;
                    if (busyOK == 0 && obj->unitAI()->currentAction() != -1) {
                        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_63, *unitp);
                } else {
                    TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_64, *unitp, subTypeValue);
                    if (subTypeValue == 0 || subTypeValue == 4) {
                            TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_65, *unitp, targetValue);
                            tactical->taskDefender(*unitp, targetValue, 2.0f, 100);
                        } else {
                            RGE_Static_Object* targ20 = md->object(targetValue);
                            if (targ20 != 0) {
                                TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_67, *unitp, targetValue);
                                tactical->taskAttacker(*unitp, targetLocationValue.x, targetLocationValue.y, targetValue, (int)targ20->owner->id, attackWaypoints, numberAttackWaypointsValue, commanderValue, 1);
                            } else {
                                // BINARY NOTE: the shipped null-target log has no unit or target arguments.
                                TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_66);
                            }
                        }
                    }
                }
            }
case20_next:
            ++unitp;
            ++busyOK;
        } while (busyOK < 40);
        inUseValue = 1;
        if (firstTime != 1)
            goto return_one_tail;
        taskID = stored20;
        goto store_return_one_zero_waypoints;
    }



    case 2:
    case 21: {
        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_04, targetValue);
        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_05, targetLocationValue.x, targetLocationValue.y);
        if (playNumberValue != -1)
            TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_07, playNumberValue);
        else
            TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_06);
        lastAttackRoundupTime = md->player->world->world_time;
        int stored = 0;
        int madeMemory = 1;
        int i;
        int* unitp;
        RGE_Static_Object* obj;
        for (i = 0, unitp = unitsValue; i < 40; ++i, ++unitp) {
            if (*unitp == -1) continue;
            TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_08, *unitp);
            obj = md->object(*unitp);
            if (obj == 0 || obj->unitAI() == 0) {
                TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_09, *unitp);
                removeUnitByIndex(i, md);
                continue;
            }
            // BINARY NOTE: the null-test unitAI call is not cached for this read.
            int action = obj->unitAI()->currentAction();
            TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_10, action);
            oHP = ((int)obj->hp); unitp[40] = oHP; stored += oHP;
            if (playNumberValue == -1) {
            if (busyOK == 0) {
                if (obj->unitAI()->currentAction() == 600 && obj->unitAI()->currentTargetType() != 0x1b) {
                    TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_11, *unitp);
                    continue;
                }
            }
            TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_12, *unitp, subTypeValue);
            if (subTypeValue == 0 || subTypeValue == 4) {
                TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_13, *unitp);
                tactical->taskDefender(*unitp, targetValue, 2.0f, 100);
            } else {
                RGE_Static_Object* targ = md->object(targetValue);
                if (targ != 0) {
                    if (madeMemory) {
                        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_15);
                        XYPoint min;
                        XYPoint max;
                        TribeInformationAIModule* info = &md->informationAI;
                        min.x = (int)targ->world_x - 7;
                        min.y = (int)targ->world_y - 7;
                        info->mapBound(&min);
                        max.x = (int)targ->world_x + 7;
                        max.y = (int)targ->world_y + 7;
                        info->mapBound(&max);
                        if (numberAttackWaypointsValue > 1) {
                            Waypoint* prev = &attackWaypoints[numberAttackWaypointsValue - 2];
                            if ((float)min.x <= prev->x)
                                max.x = (int)prev->x;
                            else
                                min.x = (int)prev->x;
                            if ((float)min.y <= prev->y)
                                max.y = (int)prev->y;
                            else
                                min.y = (int)prev->y;
                        }
                        info->storeAttackMemory(0, (unsigned char)min.x, (unsigned char)min.y, (unsigned char)max.x, (unsigned char)max.y,
                            (unsigned char)md->player->id, (unsigned char)targ->owner->id, 0, 0,
                            md->player->world->world_time, -1);
                        tactical->resetAttackSeparationTime(); madeMemory = 0;
                    }
                    TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_16, *unitp, targetValue);
                    if (*unitp == commanderValue || tactical->importantGroupLeader(commanderValue) == 0 || tactical->strategicNumber(0x79) == 0) {
                        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_17);
                        if (taskID == 21)
                            tactical->moveUnit(*unitp, targetLocationValue.x, targetLocationValue.y, 100);
                        else
                            tactical->taskAttacker(*unitp, targetLocationValue.x, targetLocationValue.y, targetValue, (int)targ->owner->id, attackWaypoints, numberAttackWaypointsValue, commanderValue, 0);
                    } else {
                        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_18);
                        int range = tactical->strategicNumber(0x83);
                        tactical->taskDefender(*unitp, commanderValue, (float)range, 99);
                    }
                } else {
                    TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_14);
                }
            }
            }
        }
        if (playNumberValue != -1) {
            int* list = (int*)operator new(numberUnitsValue << 2);
            if (list == 0) {
                TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_attack_play_alloc_fail);
                return 0;
            }
            int* scan = unitsValue;
            int count = 40;
            int* out = list;
            do {
                if (*scan != -1) *out++ = *scan;
                ++scan;
                --count;
            } while (count != 0);
            tactical->taskPlay(commanderValue, list, numberUnitsValue, targetValue, playNumberValue, attackWaypoints, numberAttackWaypointsValue);
            operator delete(list);
            return 0;
        }
        inUseValue = 1;
        if (firstTime != 1)
            goto return_one_tail;
        taskID = stored;
        goto store_return_one_zero_waypoints;
    }


    case 4: {
        int* unitp;
        RGE_Static_Object* obj;
        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_25, targetValue, targetLocationValue.x, targetLocationValue.y);
        taskID = 0;
        busyOK = 0;
        unitp = unitsValue;
        do {
            if (*unitp != -1) {
                TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_26, *unitp);
                obj = md->object(*unitp);
                if (obj == 0 || obj->unitAI() == 0) {
                    TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_27, *unitp);
                    removeUnitByIndex(busyOK, md);
                } else {
                    oHP = ((int)obj->hp);
                    unitp[40] = oHP;
                    taskID += oHP;
                    if (busyOK == 0 && obj->unitAI()->currentAction() != -1) {
                        int busyAction = obj->unitAI()->currentAction();
                        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_28, *unitp, busyAction);
                    } else {
                        int pri;
                        distance = 0.0f;
                        {
                            distance = obj->distance_to_position(targetLocationValue.x, targetLocationValue.y, targetLocationValue.z);
                        }
                        pri = tactical->calculatePriority(distance);
                        if (targetTypeValue == 0x6d) {
                            int sn = tactical->strategicNumber(0x16);
                            tactical->taskDefender(*unitp, targetValue, (float)sn, pri);
                        } else {
                            int sn = tactical->strategicNumber(0x39);
                            tactical->taskDefender(*unitp, targetValue, (float)sn, pri);
                        }
                    }
                }
            }
            ++unitp;
            ++busyOK;
        } while (busyOK < 40);
        inUseValue = 1;
        if (firstTime != 1)
            goto return_one_tail;
        goto store_return_one_mid;
    }





    case 10: {
        int* unitp;
        RGE_Static_Object* obj;
        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_43);
        taskID = 0;
        busyOK = 0;
        unitp = unitsValue;
        do {
            if (*unitp != -1) {
                TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_44, *unitp);
                obj = md->object(*unitp);
                if (obj == 0 || obj->unitAI() == 0) {
                    TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_45, *unitp);
                    removeUnitByIndex(busyOK, md);
                } else {
                    oHP = ((int)obj->hp);
                    unitp[40] = oHP;
                    taskID += oHP;
                    if (busyOK == 0 && obj->unitAI()->currentAction() != -1) {
                        int busyAction = obj->unitAI()->currentAction();
                        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_46, *unitp, busyAction);
                    } else if (*unitp == commanderValue) {
                        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_47, *unitp);
                        tactical->taskWaterFisher(*unitp, targetValue, targetLocationValue.x, targetLocationValue.y);
                    } else {
                        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_48, *unitp);
                        tactical->taskDefender(*unitp, commanderValue, obj->master_obj->los * 0.5f, 99);
                    }
                }
            }
            ++unitp;
            ++busyOK;
        } while (busyOK < 40);
        inUseValue = 1;
        if (firstTime != 1)
            return 1;
        goto store_return_one_mid;
    }

store_return_one_mid:
    originalHitPointsValue = taskID;
    originalUnitNumberValue = numberUnitsValue;
    return 1;

    case 11: {
        int* unitp;
        RGE_Static_Object* obj;
        TribeTacticalAIModule* tt = tactical;
        int total = 0;
        TribeTacticalAIModule::logGroupDebug(tt, idValue, s_log_49);
        busyOK = 0;
        unitp = unitsValue;
        do {
            if (*unitp != -1) {
                TribeTacticalAIModule::logGroupDebug(tt, idValue, s_log_50, *unitp);
                obj = md->object(*unitp);
                if (obj == 0 || obj->unitAI() == 0) {
                    TribeTacticalAIModule::logGroupDebug(tt, idValue, s_log_51, *unitp);
                    removeUnitByIndex(busyOK, md);
                } else {
                    oHP = ((int)obj->hp);
                    unitp[40] = oHP;
                    total += oHP;
                    if (busyOK == 0 && obj->unitAI()->currentAction() != -1) {
                        int busyAction = obj->unitAI()->currentAction();
                        TribeTacticalAIModule::logGroupDebug(tt, idValue, s_log_52, *unitp, busyAction);
                    } else if (*unitp == commanderValue) {
                        TribeTacticalAIModule::logGroupDebug(tt, idValue, s_log_53, *unitp);
                        tt->taskWaterTrader(*unitp, targetValue);
                    } else {
                        TribeTacticalAIModule::logGroupDebug(tt, idValue, s_log_54, *unitp);
                        tt->taskDefender(*unitp, commanderValue, obj->master_obj->los * 0.5f, 99);
                    }
                }
            }
            ++unitp;
            ++busyOK;
        } while (busyOK < 40);
        inUseValue = 1;
        if (firstTime != 1)
            goto return_one_tail;
        originalHitPointsValue = total;
        originalUnitNumberValue = numberUnitsValue;
        return 1;
    }



    case 5:
    case 6:
    case 12:
    case 19: {
        int* unitp;
        RGE_Static_Object* obj;
        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_29);
        taskID = 0;
        busyOK = 0;
        unitp = unitsValue;
        do {
            if (*unitp != -1) {
                TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_30, *unitp);
                obj = md->object(*unitp);
                if (obj == 0 || obj->unitAI() == 0) {
                    TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_31, *unitp);
                    removeUnitByIndex(busyOK, md);
                } else {
                    oHP = ((int)obj->hp);
                    unitp[40] = oHP;
                    taskID += oHP;
                }
            }
            ++unitp;
            ++busyOK;
        } while (busyOK < 40);
        inUseValue = 1;
        if (firstTime != 1)
            goto return_zero_tail;
        goto store_return_zero;
    }





    default:
        goto unknown_task_tail;


    }

    if (firstTime == 1) {
        originalHitPointsValue = taskID;
        originalUnitNumberValue = numberUnitsValue;
    }
    return 1;

return_one_tail:
    return 1;

return_zero_tail:
    return 0;




store_return_one:
    originalHitPointsValue = taskID;
    originalUnitNumberValue = numberUnitsValue;
    return 1;

store_return_zero:
    originalHitPointsValue = taskID;
    originalUnitNumberValue = numberUnitsValue;
    return 0;

unknown_task_tail:
    TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_unknown_task, taskID);
    goto return_zero_tail;


store_return_one_zero_waypoints:
    originalHitPointsValue = taskID;
    originalUnitNumberValue = numberUnitsValue;
    numberAttackWaypointsValue = 0;
    return 1;

}

// ---------------------------------------------------------------------------
// PDB source owner: 004ECD80_isGathered.cpp
// ---------------------------------------------------------------------------
// 004ECD80 TacticalAIGroup::isGathered(TribeTacticalAIModule*, TribeMainDecisionAIModule*)
// Source: taitacmd.cpp lines 1487-1529
// Size: 232 bytes
// NC: no custom flags (default /O2 /Oy)
//
// Status: MATCHED â€” canonical sibling-mirror reconstruction
//
// Attempt log:
// Probe 1 (prior worker): clean for loop â€” 64.7% positional, 208 bytes
// Probe 2 (prior): do-while + pointer arith â€” same
// Probe 3 (prior): *(int*)&dist=0 for zero â€” same
// Probe 4 (prior): var declaration order â€” same
// Probe 5 (prior): dist > (float)n comparison â€” same
// Probe 6 (prior): separate branches for strategicNumber â€” same, improved [esp+1Ch] usage
// Probe 7 (prior): temp float nf var â€” same
// Probe 8 (prior): goto structure â€” same
// Probe 9 (prior claim, baseline): canonical mirror of exact sibling isTightGathered
//   (004ECE70): while (i < 40) loop, `if (obj == 0 || obj->unitAI() == 0) { remove; }
//   else { body }` so the rare remove path is laid out late, natural float fields
//   gatherX/Y/Z (float, matching the sibling donor), literals -1.0f / 0.0f /
//   strategic threshold. Sibling used literals, not extern const symbols, and VC5
//   merged the constants into the shared .data slots (5756F0/5756F4).
//   Result: 207 bytes (-25), edit diff 15.68% (was 32.27% on the goto version),
//   exact-block coverage 78.48%; block order now matches original exactly
//   (remove block late, increment, return 1, return 0).
// Probe 10 (prior claim): swapped compare spelling on the integer-threshold form;
//   byte-identical output, so that form did not alter VC5's FPU fold.
//
// Probe 11 (this claim): added donor-backed `TribeTacticalAIModule` storage
//   (`gap_00[0x194]` and `strategicNumbers[226]`); no codegen change.
// Probe 12 (this claim): made the threshold a float and converted each
//   branch-local strategicNumber result; both calls stayed duplicated and the
//   output reached 232 bytes with 70 differing bytes.
// Probe 13 (this claim): spelled the final predicate as `dist > n`; with the
//   branch-local float conversion this selects the original `fld`/`fcomp` /
//   `test ah,41h` sequence and produces an exact 232-byte match.
// Main-agent audit restored the canonical polymorphic RGE_Static_Object and
// TacticalAIGroup ownership surfaces; emitted code remains exact.
//
// Key facts (from original asm + exact sibling donor):
// - TacticalAIGroup: typeValue(+0x14), unitsValue[40](+0x1C, 40 slots),
//   gatherX/Y/Z at +0x19C/1A0/1A4 (float fields per sibling donor).
// - mod1(TribeTacticalAIModule*)=[esp+1Ch], mod2(MainDecisionAIModule*)=[esp+20h]
// - dist at [esp+10h], n at [esp+14h] (original local order)
// - Constants: [5756F4h]=1.0f, [5756F0h]=0.0f (shared float pool)
// - Object call: mod2->object(unitID) = 0040D760h
// - unitAI: obj->unitAI() = 004C7420h
// - distance_to_position(float,float,float) thiscall ret 0Ch = 004C5F00h
// - strategicNumber: mod1->strategicNumber(0x17/0x29) = 004F6210h
// - removeUnitByIndex(idx, mod2) thiscall = 004EB0C0h
//





int TacticalAIGroup::isGathered(TribeTacticalAIModule* tactical, TribeMainDecisionAIModule* md)
{
    int i;
    int* p;
    int unit;
    RGE_Static_Object* obj;
    float dist;
    float n;

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
                dist = obj->distance_to_position(this->gatherLocationValue.x, this->gatherLocationValue.y, this->gatherLocationValue.z);
                dist = dist - 1.0f;
                if (dist < 0.0f) {
                    dist = 0.0f;
                }
                if (this->typeValue == 0x6D)
                    n = (float)tactical->strategicNumber(0x17);
                else
                    n = (float)tactical->strategicNumber(0x29);
                if (dist > n) {
                    return 0;
                }
            }
        }
        i = i + 1;
        p = p + 1;
    }
    return 1;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004ECE70_isTightGathered.cpp
// ---------------------------------------------------------------------------
// 004ECE70 TacticalAIGroup::isTightGathered(TribeTacticalAIModule*,TribeMainDecisionAIModule*)
// Source: taitacmd.cpp lines 1535-1556
// Attempt log:
// - Replaced stub with full unit scan, stale-unit removal, distance clamp, and
//   tight-gather threshold check.
// - Exact match with precondition `while (i < 40)` and natural float clamp
//   `dist -= 2.0f; if (dist < 0.0f) dist = 0.0f; if (dist > 1.0) return 0;`.






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
                dist = obj->distance_to_position(this->gatherLocationValue.x, this->gatherLocationValue.y, this->gatherLocationValue.z);
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

// ---------------------------------------------------------------------------
// PDB source owner: 004ECF10_allUnitsIdle.cpp
// ---------------------------------------------------------------------------
// 004ECF10 TacticalAIGroup::allUnitsIdle(TribeMainDecisionAIModule*,int)
// Source: taitacmd.cpp lines 1561-1588
// Attempt log:
// - Replaced stub with full scan, stale-unit removal, master object/type/action
//   special cases, and current-order idle rejection.
// - Exact match with stored `self` local and explicit `goto next` for the
//   ignore-build special case, preserving the original shared loop tail.






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

// ---------------------------------------------------------------------------
// PDB source owner: 004ECFE0_consecutiveIdleUnitCount.cpp
// ---------------------------------------------------------------------------
unsigned long TacticalAIGroup::consecutiveIdleUnitCount() const { return this->consecutiveIdleUnitCountValue; }

// ---------------------------------------------------------------------------
// PDB source owner: 004ECFF0_setConsecutiveIdleUnitCount.cpp
// ---------------------------------------------------------------------------
void TacticalAIGroup::setConsecutiveIdleUnitCount(unsigned long val) { this->consecutiveIdleUnitCountValue = val; }

// ---------------------------------------------------------------------------
// PDB source owner: 004ED000_incrementConsecutiveIdleUnitCount.cpp
// ---------------------------------------------------------------------------

void TacticalAIGroup::incrementConsecutiveIdleUnitCount(unsigned long value) {
    this->consecutiveIdleUnitCountValue += value;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004ED020_numberAttackWaypoints.cpp
// ---------------------------------------------------------------------------
unsigned char TacticalAIGroup::numberAttackWaypoints() const { return this->numberAttackWaypointsValue; }

// ---------------------------------------------------------------------------
// PDB source owner: 004ED030_currentAttackWaypoint.cpp
// ---------------------------------------------------------------------------
unsigned char TacticalAIGroup::currentAttackWaypoint() const { return this->currentAttackWaypointValue; }

// ---------------------------------------------------------------------------
// PDB source owner: 004ED040_setCurrentAttackWaypoint.cpp
// ---------------------------------------------------------------------------
// BINARY NOTE: PDB ownership is TacticalAIGroup; the fields are at +0x1D4 and +0x1D5.

void TacticalAIGroup::setCurrentAttackWaypoint(unsigned char wp)
{
    if (wp < this->numberAttackWaypointsValue)
        this->currentAttackWaypointValue = wp;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004ED060_addAttackWaypoint.cpp
// ---------------------------------------------------------------------------
// Function: TacticalAIGroup::addAttackWaypoint
// VA: 004ED060
// Source: taitacmd.cpp lines 1636-1643
// Attempt log:
// - Replaced old cdecl stub with a real C++ member function.  Member functions
//   naturally use ECX=this and ret 8 in VC5; no explicit __thiscall keyword is
//   needed or allowed.


void TacticalAIGroup::addAttackWaypoint(float x, float y)
{
    if (this->numberAttackWaypointsValue < 14) {
        this->attackWaypoints[this->numberAttackWaypointsValue].x = x;
        this->attackWaypoints[this->numberAttackWaypointsValue].y = y;
        this->attackWaypoints[this->numberAttackWaypointsValue].z = 1.0f;
        this->numberAttackWaypointsValue = this->numberAttackWaypointsValue + 1;
    }
}

// ---------------------------------------------------------------------------
// PDB source owner: 004ED0C0_attackWaypoint.cpp
// ---------------------------------------------------------------------------
Waypoint* TacticalAIGroup::attackWaypoint(unsigned char index) {
    if (index < this->numberAttackWaypointsValue)
        return this->attackWaypoints + index;
    return 0;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004ED0F0_firstIdleUnit.cpp
// ---------------------------------------------------------------------------
// 004ED0F0 TacticalAIGroup::firstIdleUnit(TribeMainDecisionAIModule*)
// Source: taitacmd.cpp lines 1657-1673
// Attempt log:
// - Replaced stub with Ghidra scan/removal logic and natural member-call surface.
// - Exact match: use a precondition `while (i < 40)` (not do-while/goto/break)
//   to keep VC5's loop fallthrough default-return block before the success
//   return block while preserving the original stack homes for this/base pointer.

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

// ---------------------------------------------------------------------------
// PDB source owner: 004ED170_objectToDestroy.cpp
// ---------------------------------------------------------------------------
int TacticalAIGroup::objectToDestroy(int index) {
    if (index < 0 || index >= 20) return -1;
    return this->objectsToDestroyValue[index];
}

// ---------------------------------------------------------------------------
// PDB source owner: 004ED190_addObjectToDestroy.cpp
// ---------------------------------------------------------------------------
int TacticalAIGroup::addObjectToDestroy(int objectId) {
    if (this->numberObjectsToDestroyValue < 0x13) {
        this->objectsToDestroyValue[this->numberObjectsToDestroyValue] = objectId;
        this->numberObjectsToDestroyValue = this->numberObjectsToDestroyValue + 1;
        return 1;
    }
    return 0;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004ED1C0_TribeTacticalAIModule.cpp
// ---------------------------------------------------------------------------
// 004ED1C0 TribeTacticalAIModule::TribeTacticalAIModule(void*,int)
// Source: taitacmd.cpp lines 1736-1773
// Ghidra-body compileable baseline for the non-loading constructor; kept close
// to the related 004ED4F0 load-constructor surface.
// FLAGS: /GX for the original EH-framed constructor.
// Attempt log:
// - 2026-05-04: copied the Ghidra heuristic body and adjusted the local type
//   surface to compile.  PlacementState/AttackState use the real active offsets
//   (+0x114/+0x28), matching type dumps and the original +0xF60/+0xFD4 stores.
// - A volatile local EH-state probe emitted the state stores but still no FS:[0]
//   registration prefix, leaving the .text section shorter than the original;
//   rolled back so check_function can compare the raw-body baseline.
// - A volatile pointer makes the six-store distribution loop match the original
//   compact loop, but with the EH prefix still missing the section is too short
//   for check_function extraction; keep the comparable non-volatile baseline.
// - Current comparable baseline: compiles, 68.93% positional / 29.41% edit;
//   most remaining structural gap is the missing VC5 C++ EH registration prefix.
// - 2026-08-11: ABI/layout evidence confirms TacticalAIModule inheritance and
//   virtual destructor surfaces for the module, Group, and ResourceItem.  A
//   novtable-derived typed base restores the original FS:[0] EH prefix,
//   base-constructor call, and 0x100C layout; raw group/resource storage is
//   retained because the oracle places their explicit constructor calls after
//   the preceding scalar zeroing rather than at automatic member-init entry.
// - 2026-08-11: a volatile distribution cursor reaches the exact 782-byte
//   size and compact six-store loop, but changes the prologue/register basin;
//   removed from the living source as codegen-only evidence.  The remaining
//   mismatch is structural ordering/state placement around the group call and
//   the later distribution loop.
// - 2026-08-13: tested typed group/resource members with ordered initializer
//   lifetimes.  VC5 moved both calls into member initialization and removed
//   many zero stores, producing 505-510 bytes and worse CFG shape; rolled back.
// - 2026-08-13: tested placement construction in raw storage with compiler
//   vptr emission.  VC5 emitted the derived vptr at entry and produced 849
//   bytes; rolled back because the original stores its vptr after resource
//   setup.
// - 2026-08-13: corrected +0xD88 to the proven resourceMapping field and used
//   a natural indexed initialization for mapping, distributions, differences,
//   and build counts.  VC5 now emits the compact six-store loop and 782 bytes;
//   keep this readable source.  The remaining structural gap is the early
//   Group receiver LEA and delayed EH-state store near the first field zero.
// - 2026-08-17: revisited the first hunk with 20 distinct probes.  Direct,
//   scoped, reordered, reference, split, and late group-pointer forms did not
//   change the 782-byte code.  Moving the group call earlier reduced the byte
//   diff to 649, but changed the call and store order, so it is not valid.
//   Explicit vptr layouts, a typed group-link prefix, standard headers, and
//   base novtable context did not change the baseline.  Removing derived
//   novtable emitted an early vptr store and was rejected.  The clean baseline
//   remains 692 bytes different, with three ordered calls and exact size.
// Previous baseline blocker: the executable sets EH state zero immediately
// after the base call and state 0x0A before the group constructor. The raw
// reconstruction delayed the zero state until that call and moved the
// ResourceItem argument before five member stores.
// - 2026-08-22: modeled all ManagedIntArray fields as nontrivial members with
//   zeroing constructors and a real delete-and-zero destructor. Modeled the
//   inline group and resource objects as typed members. An ordered initializer
//   list now covers every member through neededResources(4), matching the
//   original EH transitions, zero-store order, and late constructor calls.
//   The exact check is 782/782 bytes, 3/3 calls, and 100% block coverage.
// - Exact-finish reversion: removing the ManagedIntArray destructor changed
//   the result to 639 differing bytes. Replacing the natural destructor body
//   with an empty body stayed exact, so the cleanup body is codegen-neutral in
//   this target. Kept the real delete-and-zero body for canonical semantics.
// - Exact-finish reversion: changing operator_delete to the canonical C++
//   global operator delete stayed exact and is retained.
// - Exact-finish context reductions: removing the unused operator_new
//   declaration and the unused TribeMainDecisionAIModule forward declaration
//   both stayed exact. Neither declaration is retained.
// - Main review rejected the first exact variant because it used novtable and
//   a raw vptr store. The normal virtual class moved the vptr 33 bytes.
// - Final exact recovery: move all scalar initialization after neededResources
//   into the member initializer list. VC5 now completes those initializers and
//   writes the derived vptr at the executable's original point. This keeps
//   compiler ownership and needs no raw vptr access or novtable attribute.
// - Exact-finish reduction: moving attackEnabledValue, nextCivilianToTaskValue,
//   or updateAreaAverageTotal back into the body produced 33, 26, and 7 byte
//   mismatches. The ordered post-ResourceItem initializer group is required.


TribeTacticalAIModule::TribeTacticalAIModule(void* param_1, int param_2)
    : TacticalAIModule(param_1, param_2),
      md(0),
      civilians(),
      civilianExplorers(),
      soldiers(),
      ungroupedSoldiers(),
      boats(),
      warBoats(),
      fishingBoats(),
      tradeBoats(),
      transportBoats(),
      artifacts(),
      numberGatherersValue(0),
      desiredNumberGatherersValue(0),
      groups(),
      groupIDValue(0),
      numberGroupsValue(0),
      lastGroupAttackTime(0),
      lastGroupRebalanceTime(0),
      lastAttackResponseTime(0),
      lastBoatAttackResponseTime(0),
      lastScalingUpdateValue(0),
      numberBuildUpdatesSkipped(0),
      randomizedAttackSeparationTime(0),
      playersToAttack(),
      playersToDefend(),
      workingArea(),
      unitsTaskedThisUpdate(),
      neededResources(4),
      attackEnabledValue(0),
      updateArea(0),
      firstNeededResourceUpdateDone(0),
      wonderInProgressValue(0),
      wonderBuiltValue(0),
      nextCivilianToTaskValue(-1),
      nextIdleSoldierGroupToTaskValue(-1),
      nextActiveSoldierGroupToTaskValue(-1),
      builtFirstStoragePit(0),
      builtFirstGranary(0),
      lastBuildTime(0),
      lastAttackResponseBuildInsertionTime(0),
      lastCoopTributeDemandTime(0),
      lastCoopTributeGiftTime(0),
      lastCoopAttackDemandTime(0),
      zoomingToNextAge(0),
      lastUngroupedSoldierTaskTime(0),
      lastUpdateAreaTimeValue(-1),
      averageUpdateAreaTimeValue(-1),
      updateAreaAverageCount(0),
      updateAreaAverageTotal(0)
{
    int* piVar1;
    int iVar2;

    for (iVar2 = 0; iVar2 != 4; iVar2 = iVar2 + 1) {
        this->resourceMappingValue[iVar2] = -1;
        this->desiredGathererDistribution[iVar2] = 0;
        this->actualGathererDistribution[iVar2] = 0;
        this->resourceDifferenceValue[iVar2] = 0;
        this->numberStoragePitsBuilt[iVar2] = 0;
        this->numberGranariesBuilt[iVar2] = 0;
    }

    piVar1 = this->sn;
    for (iVar2 = 0xe2; iVar2 != 0; iVar2 = iVar2 - 1) {
        *piVar1 = -1;
        piVar1 = piVar1 + 1;
    }
    piVar1 = this->hitsByPlayer;
    for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 - 1) {
        *piVar1 = 0;
        piVar1 = piVar1 + 1;
    }
    piVar1 = &this->gatherers[0].data1;
    iVar2 = 0x32;
    do {
        ((UnitData*)(piVar1 - 1))->id = -1;
        *piVar1 = -1;
        piVar1[1] = -1;
        piVar1[2] = -1;
        piVar1[3] = -1;
        piVar1 = piVar1 + 6;
        iVar2 = iVar2 - 1;
    } while (iVar2 != 0);
    this->groups.next = &this->groups;
    this->groups.prev = &this->groups;
    this->placementStateValue.active = 0;
    this->attackStateValue.active = 0;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004ED4F0_TribeTacticalAIModule.cpp
// ---------------------------------------------------------------------------
// 004ED4F0 TribeTacticalAIModule::TribeTacticalAIModule(int,int)
// Source: taitacmd.cpp lines 1803-2027
// Ghidra-body compileable baseline. Not exact yet; intended as a fuller journey
// starting point than a hand-summarized skeleton.
// Attempt log:
// - 2026-05-04: replaced the earlier partial skeleton with the full Ghidra
//   approximated body (lines 1803-2027), adjusted just enough to compile as C++:
//   EH scaffolding removed, base/member ctors expressed via initializer list,
//   vtable store uses *(int*)this = 0x575788, and groups.next/prev modeled.
// - FLAGS: /GX retained for original EH-framed constructor
//   (config/flags/004ED4F0_TribeTacticalAIModule.rsp).
// - 2026-05-04 continued: original constructs groups/neededResources inside
//   the body after many stores, not in initializer-list order.  Switched those
//   members to raw storage and call their constructors manually in-body.
// - Stack-frame note: packet uses a 0x24 byte local area.  The Ghidra locals only
//   induced 0x20; a volatile padding local did not change VC5's allocation, so
//   this remains tied to the missing EH registration/state slot.
// - Switched the TacticalAIModule base to raw storage plus an explicit in-body
//   constructor call.  This better matches the original's source order (save this
//   in ESI, push file/player args, then call base ctor) and avoids C++'s forced
//   base-initializer scheduling.
// - Tried wrapping the body in __try/__finally to force FS:[0] setup.  It did
//   produce an EH-looking prologue, but with an EBP frame and much worse edit diff
//   (~103%), so rolled back.  A declared-but-undefined FakeDtor guard also did
//   not produce the original C++ EH registration sequence and slightly worsened
//   diff, so it is removed.  The dead `eh_state` local from Ghidra likewise had
//   no benefit after removing the guard, so it is gone.  The first 0x100 bytes are mostly aligned after
//   ignoring the missing 21-byte EH prefix; a local issue remains that VC5 hoists
//   ResourceItem's `push 4` before the final +0xD50..+0xD64 zero stores.
// - Marked ManagedIntArray::value volatile: this prevents VC5 from turning the
//   duplicate-scan loop into a single incrementing pointer walk.  The rebuilt
//   loop now reloads the array base for indexed comparisons, much closer to the
//   original `[base+eax*4]` family.  Marking numberValue and desiredNumberValue
//   volatile too (but not maximumSizeValue) improves the repeated list loader
//   substantially; current best is ~85.19% positional / ~60.77% edit.
// - Flag probes /O2 /GX, /O2 /Oy- /GX, /O1 /Oy /GX, and /O1 /GX produced the
//   same metrics; this is source/type/EH-context work, not a simple flag issue.
// - Rewriting equivalent bounds checks with the induction variable on the left
//   (`i >= max`, `i >= newMax`) is a small edit-diff win for all inlined list
//   loaders.
// - Comparing against the saved temp local (`local_28`) instead of the raw read
//   buffer (`local_2c`) is a larger win and better expresses the original's
//   store-to-local after each read.  Removing the no-op FakeDtor guard gave a
//   good baseline (~84.79% positional / ~57.98% edit).
// - Variant not kept: modeling full virtual inheritance/interface like smaller
//   matched AI ctors improves edit diff (~56.44%) but emits an early automatic
//   vptr store/zero after the base ctor and still no EH prefix; it contradicts
//   the packet where the TribeTacticalAIModule vptr is written much later at
//   004ED741.  Raw class + manual vptr remains the better positional baseline.
// - Variant not kept: making groups/neededResources real typed members with
//   destructors improved edit diff to ~66.93%, but forced their constructors to
//   run before the base ctor and before all zeroing, contradicting original order.
//   Keep raw storage as the behavioral/scheduling baseline unless a TU-context
//   trick can recover EH without auto-member construction.
// - Fixed one Ghidra-local artifact in the compileable body: old gatherer reads
//   now use tempUD.data4/data5 instead of uninitialized stack aliases. Duplicate
//   checks use the raw read buffer (`local_2c`) as in Ghidra/original asm; using
//   the saved add temp/local id instead produced the same current metrics.
//   Current validation after layout/FPU/list-predicate fixes: compiles cleanly,
//   84.95% positional / 55.95% edit.
// - Probe not kept: removing volatile from numberValue/desiredNumberValue worsened
//   the loader family (edit diff ~58.98%), so the earlier volatile surface stays.
// - Probe not kept: an explicit volatile `eh_state` local with byte writes at
//   the Ghidra EH-state transitions worsened edit diff (~58.84%) and still did
//   not recover the real FS:[0] registration prefix; rolled back.
// - Probe not kept: making maximumSizeValue volatile only slightly helped
//   positional diff but badly worsened edit diff (~68.91%), so max stays plain.
// - Corrected PlacementState/AttackState active offsets from type dumps and
//   changed the legacy-version clearing loops to raw dword zeroing.  This fixes
//   real field offsets (+0xF60/+0xFD4) and improves edit diff to ~56.54%.
// - Version gates use float literals for original dword FPU constants.  For
//   `constant <= save_game_version` gates, spelling as `!(save_game_version < C)`
//   preserves the original `test ah,1` branch family; direct `C <= save` emitted
//   `test ah,41h` and worsened the diff.  The 6.2/7.04 old-layout gates also
//   need the negated form to keep the read block before the zero-fill block.
// - Rewriting ManagedArray grow checks as `count > max - 1` instead of
//   `max + -1 < count` preserves the original jle-skip compare family and trims
//   edit diff slightly.
// - Natural-lifetime probe: made TacticalAIModule, TacticalAIGroup, and
//   ResourceItem typed bases/members, and moved their construction to the
//   initializer list. Removed the manual derived-vptr store. This is retained
//   as the one constructor-order test for the current session.
// - Kept the typed TacticalAIModule base but restored raw placement storage for
//   group/resource objects. This retained compiler EH setup, removed automatic
//   lifetime reordering, and improved the structural diff to 5325 bytes.
// - A novtable derived-class context removed the compiler's early vptr store,
//   but moved the first mismatch and worsened the structural diff. Rolled back.
// - Tested moving lastGroupRebalanceTime initialization after the explicit
//   Group constructor; it worsened the diff by 5 bytes and was rolled back.
// - Declaring the proven derived virtual destructor preserved the clean metrics
//   and improved one local alignment, but did not change the structural basin.
// - Removing the decompiler tempUD self-assignment shortened the function but
//   worsened the structural diff; restored the prior source.
// - 2026-08-17 claim pass: ran 22 distinct source, ABI, liveness, control-flow,
//   and flag probes. No probe reached exactness. The clean baseline remains
//   5325 differing bytes (90.9945%), 84.93% shape, 0x24 frame, and 104/104
//   ordered calls. The main blocker is the derived vptr store at +0x2F and the
//   missing original EH-state store at [esp+0x3C].
// - Evidence: __declspec(novtable), flattened placement construction, alternate
//   loop forms, scalar/pointer volatility axes, unsuffixed/direct version gates,
//   and /O1, /Oy- flag variants all remained nonexact. Restore the clean source
//   before further work. Next lead: recover VC5's original constructor EH state
//   and delayed derived-vptr scheduling without manual assembly.
// - 2026-08-22 claim pass: modeled ManagedIntArray as a natural zeroing,
//   delete-and-zero member; modeled groups and neededResources as their proven
//   inline objects. Declaration-order construction improved the clean diff from
//   5325 to 5186 bytes and moved the first mismatch from the prologue to the
//   late inline-object/vptr transition. The retained fields are nonvolatile;
//   volatile probes were metric-only and were removed.


extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void __cdecl operator_delete(void* p);
extern float save_game_version;

TribeTacticalAIModule::TribeTacticalAIModule(int param_1, int param_2)
    : TacticalAIModule(0, param_1),
      md(0),
      civilians(),
      civilianExplorers(),
      soldiers(),
      ungroupedSoldiers(),
      boats(),
      warBoats(),
      fishingBoats(),
      tradeBoats(),
      transportBoats(),
      artifacts(),
      lastGroupRebalanceTime(0),
      playersToAttack(),
      playersToDefend(),
      workingArea(),
      unitsTaskedThisUpdate(),
      neededResources(4)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  TacticalAIGroup *pTVar5;
  int iVar6;
  int i;
  int tempInt;
  int file;
  int local_2c;
  int local_28;
  OldUnitData tempUD;
  int oldData3;
  int oldTarget;

  tempUD.id = (int)this;
  TacticalAIGroup *group = &this->groups;
  this->groups.next = group;
  this->groups.prev = group;
  this->attackEnabledValue = 0;
  this->updateArea = 0;
  this->firstNeededResourceUpdateDone = 0;
  this->wonderInProgressValue = 0;
  this->wonderBuiltValue = 0;
  this->nextCivilianToTaskValue = -1;
  this->nextIdleSoldierGroupToTaskValue = -1;
  this->nextActiveSoldierGroupToTaskValue = -1;
  this->builtFirstStoragePit = 0;
  this->builtFirstGranary = 0;
  this->lastBuildTime = 0;
  this->lastAttackResponseBuildInsertionTime = 0;
  this->lastCoopTributeDemandTime = 0;
  this->lastCoopTributeGiftTime = 0;
  this->lastCoopAttackDemandTime = 0;
  this->zoomingToNextAge = 0;
  this->lastUngroupedSoldierTaskTime = 0;
  this->lastUpdateAreaTimeValue = -1;
  this->averageUpdateAreaTimeValue = -1;
  this->updateAreaAverageCount = 0;
  this->updateAreaAverageTotal = 0;
  file = param_2;
  rge_read(file,&param_1,4);
  tempInt = 0;
  if (0 < param_1) {
    do {
      rge_read(file,&local_2c,4);
      iVar6 = (this->civilians).numberValue;
      iVar1 = 0;
      local_28 = local_2c;
      if (0 < iVar6) {
        do {
          if (iVar1 >= (this->civilians).maximumSizeValue) break;
          if ((this->civilians).value[iVar1] == local_2c) goto LAB_004ed829;
          iVar1 = iVar1 + 1;
        } while (iVar1 < iVar6);
      }
      if (iVar6 > (this->civilians).maximumSizeValue - 1) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar1 = 0;
          if (0 < (this->civilians).maximumSizeValue) {
            do {
              if (iVar1 >= iVar6) break;
              iVar3 = iVar1 + 1;
              piVar2[iVar1] = (this->civilians).value[iVar1];
              iVar1 = iVar3;
            } while (iVar3 < (this->civilians).maximumSizeValue);
          }
          operator_delete((this->civilians).value);
          (this->civilians).value = piVar2;
          (this->civilians).maximumSizeValue = iVar6;
        }
      }
      (this->civilians).value[(this->civilians).numberValue] = local_28;
      (this->civilians).numberValue = (this->civilians).numberValue + 1;
LAB_004ed829:
      tempInt = tempInt + 1;
      iVar6 = param_2;
    } while (tempInt < param_1);
  }
  rge_read(file,&param_1,4);
  tempInt = 0;
  if (0 < param_1) {
    do {
      rge_read(file,&local_2c,4);
      iVar6 = (this->civilianExplorers).numberValue;
      iVar1 = 0;
      local_28 = local_2c;
      if (0 < iVar6) {
        do {
          if (iVar1 >= (this->civilianExplorers).maximumSizeValue) break;
          if ((this->civilianExplorers).value[iVar1] == local_2c) goto LAB_004ed92c;
          iVar1 = iVar1 + 1;
        } while (iVar1 < iVar6);
      }
      if (iVar6 > (this->civilianExplorers).maximumSizeValue - 1) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar1 = 0;
          if (0 < (this->civilianExplorers).maximumSizeValue) {
            do {
              if (iVar1 >= iVar6) break;
              iVar3 = iVar1 + 1;
              piVar2[iVar1] = (this->civilianExplorers).value[iVar1];
              iVar1 = iVar3;
            } while (iVar3 < (this->civilianExplorers).maximumSizeValue);
          }
          operator_delete((this->civilianExplorers).value);
          (this->civilianExplorers).value = piVar2;
          (this->civilianExplorers).maximumSizeValue = iVar6;
        }
      }
      (this->civilianExplorers).value[(this->civilianExplorers).numberValue] = local_28;
      (this->civilianExplorers).numberValue = (this->civilianExplorers).numberValue + 1;
LAB_004ed92c:
      tempInt = tempInt + 1;
      iVar6 = param_2;
    } while (tempInt < param_1);
  }
  rge_read(file,&this->numberGatherersValue,4);
  rge_read(file,&this->desiredNumberGatherersValue,4);
  if (save_game_version < 7.19f) {
    piVar2 = &this->gatherers[0].data1;
    iVar6 = 0x32;
    if (save_game_version < 7.17f) {
      do {
        // BINARY NOTE: The shipped old-format read starts at data1 and uses
        // the adjacent oldData3 local as its fourth dword.
        rge_read(file,&tempUD.data1,0x10);
        ((UnitData *)(piVar2 + -1))->id = tempUD.data1;
        *piVar2 = tempUD.data2;
        piVar2[1] = tempUD.data3;
        piVar2[2] = oldData3;
        piVar2[3] = -1;
        piVar2[4] = 0;
        piVar2 = piVar2 + 6;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    else {
      do {
        // BINARY NOTE: This newer old-format read also uses oldTarget.
        rge_read(file,&tempUD.data1,0x14);
        ((UnitData *)(piVar2 + -1))->id = tempUD.data1;
        *piVar2 = tempUD.data2;
        piVar2[1] = tempUD.data3;
        piVar2[2] = oldData3;
        piVar2[3] = oldTarget;
        piVar2[4] = 0;
        piVar2 = piVar2 + 6;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
  }
  else {
                    /* language.dll match for 0x4b0: "Ready" */
    rge_read(file,this->gatherers,0x4b0);
  }
  rge_read(file,&param_1,4);
  tempInt = 0;
  if (0 < param_1) {
    do {
      rge_read(file,&local_2c,4);
      iVar6 = (this->soldiers).numberValue;
      iVar1 = 0;
      local_28 = local_2c;
      if (0 < iVar6) {
        do {
          if (iVar1 >= (this->soldiers).maximumSizeValue) break;
          if ((this->soldiers).value[iVar1] == local_2c) goto LAB_004edb26;
          iVar1 = iVar1 + 1;
        } while (iVar1 < iVar6);
      }
      if (iVar6 > (this->soldiers).maximumSizeValue - 1) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar1 = 0;
          if (0 < (this->soldiers).maximumSizeValue) {
            do {
              if (iVar1 >= iVar6) break;
              iVar3 = iVar1 + 1;
              piVar2[iVar1] = (this->soldiers).value[iVar1];
              iVar1 = iVar3;
            } while (iVar3 < (this->soldiers).maximumSizeValue);
          }
          operator_delete((this->soldiers).value);
          (this->soldiers).value = piVar2;
          (this->soldiers).maximumSizeValue = iVar6;
        }
      }
      (this->soldiers).value[(this->soldiers).numberValue] = local_28;
      (this->soldiers).numberValue = (this->soldiers).numberValue + 1;
LAB_004edb26:
      tempInt = tempInt + 1;
    } while (tempInt < param_1);
  }
  if (!(save_game_version < 2.3f)) {
    rge_read(file,&param_1,4);
    tempInt = 0;
    if (0 < param_1) {
      do {
        rge_read(file,&local_2c,4);
        iVar6 = (this->ungroupedSoldiers).numberValue;
        iVar1 = 0;
        local_28 = local_2c;
        if (0 < iVar6) {
          do {
            if (iVar1 >= (this->ungroupedSoldiers).maximumSizeValue) break;
            if ((this->ungroupedSoldiers).value[iVar1] == local_2c) goto LAB_004edc44;
            iVar1 = iVar1 + 1;
          } while (iVar1 < iVar6);
        }
        if (iVar6 > (this->ungroupedSoldiers).maximumSizeValue - 1) {
          iVar6 = iVar6 + 1;
          piVar2 = (int *)operator_new(iVar6 * 4);
          if (piVar2 != (int *)0x0) {
            iVar1 = 0;
            if (0 < (this->ungroupedSoldiers).maximumSizeValue) {
              do {
                if (iVar1 >= iVar6) break;
                iVar3 = iVar1 + 1;
                piVar2[iVar1] = (this->ungroupedSoldiers).value[iVar1];
                iVar1 = iVar3;
              } while (iVar3 < (this->ungroupedSoldiers).maximumSizeValue);
            }
            operator_delete((this->ungroupedSoldiers).value);
            (this->ungroupedSoldiers).value = piVar2;
            (this->ungroupedSoldiers).maximumSizeValue = iVar6;
          }
        }
        (this->ungroupedSoldiers).value[(this->ungroupedSoldiers).numberValue] = local_28;
        (this->ungroupedSoldiers).numberValue = (this->ungroupedSoldiers).numberValue + 1;
LAB_004edc44:
        tempInt = tempInt + 1;
      } while (tempInt < param_1);
    }
  }
  rge_read(file,&param_1,4);
  tempInt = 0;
  if (0 < param_1) {
    do {
      rge_read(file,&local_2c,4);
      iVar6 = (this->boats).numberValue;
      iVar1 = 0;
      local_28 = local_2c;
      if (0 < iVar6) {
        do {
          if (iVar1 >= (this->boats).maximumSizeValue) break;
          if ((this->boats).value[iVar1] == local_2c) goto LAB_004edd4b;
          iVar1 = iVar1 + 1;
        } while (iVar1 < iVar6);
      }
      if (iVar6 > (this->boats).maximumSizeValue - 1) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar1 = 0;
          if (0 < (this->boats).maximumSizeValue) {
            do {
              if (iVar1 >= iVar6) break;
              iVar3 = iVar1 + 1;
              piVar2[iVar1] = (this->boats).value[iVar1];
              iVar1 = iVar3;
            } while (iVar3 < (this->boats).maximumSizeValue);
          }
          operator_delete((this->boats).value);
          (this->boats).value = piVar2;
          (this->boats).maximumSizeValue = iVar6;
        }
      }
      (this->boats).value[(this->boats).numberValue] = local_28;
      (this->boats).numberValue = (this->boats).numberValue + 1;
LAB_004edd4b:
      tempInt = tempInt + 1;
    } while (tempInt < param_1);
  }
  rge_read(file,&param_1,4);
  tempInt = 0;
  if (0 < param_1) {
    do {
      rge_read(file,&local_2c,4);
      iVar1 = local_2c;
      iVar6 = (this->warBoats).numberValue;
      iVar3 = 0;
      if (0 < iVar6) {
        do {
          if (iVar3 >= (this->warBoats).maximumSizeValue) break;
          if ((this->warBoats).value[iVar3] == local_2c) goto LAB_004ede4c;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar6);
      }
      if (iVar6 > (this->warBoats).maximumSizeValue - 1) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar3 = 0;
          if (0 < (this->warBoats).maximumSizeValue) {
            do {
              if (iVar6 <= iVar3) break;
              iVar4 = iVar3 + 1;
              piVar2[iVar3] = (this->warBoats).value[iVar3];
              iVar3 = iVar4;
            } while (iVar4 < (this->warBoats).maximumSizeValue);
          }
          operator_delete((this->warBoats).value);
          (this->warBoats).value = piVar2;
          (this->warBoats).maximumSizeValue = iVar6;
        }
      }
      (this->warBoats).value[(this->warBoats).numberValue] = iVar1;
      (this->warBoats).numberValue = (this->warBoats).numberValue + 1;
LAB_004ede4c:
      tempInt = tempInt + 1;
    } while (tempInt < param_1);
  }
  rge_read(file,&param_1,4);
  tempInt = 0;
  if (0 < param_1) {
    do {
      rge_read(file,&local_2c,4);
      iVar1 = local_2c;
      iVar6 = (this->fishingBoats).numberValue;
      iVar3 = 0;
      if (0 < iVar6) {
        do {
          if (iVar3 >= (this->fishingBoats).maximumSizeValue) break;
          if ((this->fishingBoats).value[iVar3] == local_2c) goto LAB_004edf51;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar6);
      }
      if (iVar6 > (this->fishingBoats).maximumSizeValue - 1) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar3 = 0;
          if (0 < (this->fishingBoats).maximumSizeValue) {
            do {
              if (iVar6 <= iVar3) break;
              iVar4 = iVar3 + 1;
              piVar2[iVar3] = (this->fishingBoats).value[iVar3];
              iVar3 = iVar4;
            } while (iVar4 < (this->fishingBoats).maximumSizeValue);
          }
          operator_delete((this->fishingBoats).value);
          (this->fishingBoats).value = piVar2;
          (this->fishingBoats).maximumSizeValue = iVar6;
        }
      }
      (this->fishingBoats).value[(this->fishingBoats).numberValue] = iVar1;
      (this->fishingBoats).numberValue = (this->fishingBoats).numberValue + 1;
LAB_004edf51:
      tempInt = tempInt + 1;
    } while (tempInt < param_1);
  }
  rge_read(file,&param_1,4);
  tempInt = 0;
  if (0 < param_1) {
    do {
      rge_read(file,&local_2c,4);
      iVar1 = local_2c;
      iVar6 = (this->tradeBoats).numberValue;
      iVar3 = 0;
      if (0 < iVar6) {
        do {
          if (iVar3 >= (this->tradeBoats).maximumSizeValue) break;
          if ((this->tradeBoats).value[iVar3] == local_2c) goto LAB_004ee056;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar6);
      }
      if (iVar6 > (this->tradeBoats).maximumSizeValue - 1) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar3 = 0;
          if (0 < (this->tradeBoats).maximumSizeValue) {
            do {
              if (iVar6 <= iVar3) break;
              iVar4 = iVar3 + 1;
              piVar2[iVar3] = (this->tradeBoats).value[iVar3];
              iVar3 = iVar4;
            } while (iVar4 < (this->tradeBoats).maximumSizeValue);
          }
          operator_delete((this->tradeBoats).value);
          (this->tradeBoats).value = piVar2;
          (this->tradeBoats).maximumSizeValue = iVar6;
        }
      }
      (this->tradeBoats).value[(this->tradeBoats).numberValue] = iVar1;
      (this->tradeBoats).numberValue = (this->tradeBoats).numberValue + 1;
LAB_004ee056:
      tempInt = tempInt + 1;
    } while (tempInt < param_1);
  }
  rge_read(file,&param_1,4);
  tempInt = 0;
  if (0 < param_1) {
    do {
      rge_read(file,&local_2c,4);
      iVar1 = local_2c;
      iVar6 = (this->transportBoats).numberValue;
      iVar3 = 0;
      if (0 < iVar6) {
        do {
          if (iVar3 >= (this->transportBoats).maximumSizeValue) break;
          if ((this->transportBoats).value[iVar3] == local_2c) goto LAB_004ee15b;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar6);
      }
      if (iVar6 > (this->transportBoats).maximumSizeValue - 1) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar3 = 0;
          if (0 < (this->transportBoats).maximumSizeValue) {
            do {
              if (iVar6 <= iVar3) break;
              iVar4 = iVar3 + 1;
              piVar2[iVar3] = (this->transportBoats).value[iVar3];
              iVar3 = iVar4;
            } while (iVar4 < (this->transportBoats).maximumSizeValue);
          }
          operator_delete((this->transportBoats).value);
          (this->transportBoats).value = piVar2;
          (this->transportBoats).maximumSizeValue = iVar6;
        }
      }
      (this->transportBoats).value[(this->transportBoats).numberValue] = iVar1;
      (this->transportBoats).numberValue = (this->transportBoats).numberValue + 1;
LAB_004ee15b:
      tempInt = tempInt + 1;
    } while (tempInt < param_1);
  }
  if (!(save_game_version < 1.4f)) {
    rge_read(file,&param_1,4);
    tempInt = 0;
    if (0 < param_1) {
      do {
        rge_read(file,&local_2c,4);
        iVar1 = local_2c;
        iVar6 = (this->artifacts).numberValue;
        iVar3 = 0;
        if (0 < iVar6) {
          do {
            if (iVar3 >= (this->artifacts).maximumSizeValue) break;
            if ((this->artifacts).value[iVar3] == local_2c) goto LAB_004ee277;
            iVar3 = iVar3 + 1;
          } while (iVar3 < iVar6);
        }
        if (iVar6 > (this->artifacts).maximumSizeValue - 1) {
          iVar6 = iVar6 + 1;
          piVar2 = (int *)operator_new(iVar6 * 4);
          if (piVar2 != (int *)0x0) {
            iVar3 = 0;
            if (0 < (this->artifacts).maximumSizeValue) {
              do {
                if (iVar6 <= iVar3) break;
                iVar4 = iVar3 + 1;
                piVar2[iVar3] = (this->artifacts).value[iVar3];
                iVar3 = iVar4;
              } while (iVar4 < (this->artifacts).maximumSizeValue);
            }
            operator_delete((this->artifacts).value);
            (this->artifacts).value = piVar2;
            (this->artifacts).maximumSizeValue = iVar6;
          }
        }
        (this->artifacts).value[(this->artifacts).numberValue] = iVar1;
        (this->artifacts).numberValue = (this->artifacts).numberValue + 1;
LAB_004ee277:
        tempInt = tempInt + 1;
      } while (tempInt < param_1);
    }
  }
  iVar6 = param_2;
  rge_read(file,&param_1,4);
  iVar1 = 0;
  if (0 < param_1) {
    piVar2 = this->sn;
    do {
      rge_read(file,piVar2,4);
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar1 < param_1);
  }
  rge_read(file,&param_1,4);
  tempInt = 0;
  if (0 < param_1) {
    do {
      rge_read(file,&local_2c,4);
      iVar1 = local_2c;
      iVar6 = (this->playersToAttack).numberValue;
      iVar3 = 0;
      if (0 < iVar6) {
        do {
          if (iVar3 >= (this->playersToAttack).maximumSizeValue) break;
          if ((this->playersToAttack).value[iVar3] == local_2c) goto LAB_004ee3b4;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar6);
      }
      if (iVar6 > (this->playersToAttack).maximumSizeValue - 1) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar3 = 0;
          if (0 < (this->playersToAttack).maximumSizeValue) {
            do {
              if (iVar6 <= iVar3) break;
              iVar4 = iVar3 + 1;
              piVar2[iVar3] = (this->playersToAttack).value[iVar3];
              iVar3 = iVar4;
            } while (iVar4 < (this->playersToAttack).maximumSizeValue);
          }
          operator_delete((this->playersToAttack).value);
          (this->playersToAttack).value = piVar2;
          (this->playersToAttack).maximumSizeValue = iVar6;
        }
      }
      (this->playersToAttack).value[(this->playersToAttack).numberValue] = iVar1;
      (this->playersToAttack).numberValue = (this->playersToAttack).numberValue + 1;
LAB_004ee3b4:
      tempInt = tempInt + 1;
    } while (tempInt < param_1);
  }
  rge_read(file,&param_1,4);
  tempInt = 0;
  if (0 < param_1) {
    do {
      rge_read(file,&local_2c,4);
      iVar1 = local_2c;
      iVar6 = (this->playersToDefend).numberValue;
      iVar3 = 0;
      if (0 < iVar6) {
        do {
          if (iVar3 >= (this->playersToDefend).maximumSizeValue) break;
          if ((this->playersToDefend).value[iVar3] == local_2c) goto LAB_004ee4b9;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar6);
      }
      if (iVar6 > (this->playersToDefend).maximumSizeValue - 1) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar3 = 0;
          if (0 < (this->playersToDefend).maximumSizeValue) {
            do {
              if (iVar6 <= iVar3) break;
              iVar4 = iVar3 + 1;
              piVar2[iVar3] = (this->playersToDefend).value[iVar3];
              iVar3 = iVar4;
            } while (iVar4 < (this->playersToDefend).maximumSizeValue);
          }
          operator_delete((this->playersToDefend).value);
          (this->playersToDefend).value = piVar2;
          (this->playersToDefend).maximumSizeValue = iVar6;
        }
      }
      (this->playersToDefend).value[(this->playersToDefend).numberValue] = iVar1;
      (this->playersToDefend).numberValue = (this->playersToDefend).numberValue + 1;
LAB_004ee4b9:
      tempInt = tempInt + 1;
    } while (tempInt < param_1);
  }
  rge_read(file,&param_1,4);
  tempInt = 0;
  if (0 < param_1) {
    do {
      rge_read(file,&local_2c,4);
      iVar1 = local_2c;
      iVar6 = (this->workingArea).numberValue;
      iVar3 = 0;
      if (0 < iVar6) {
        do {
          if (iVar3 >= (this->workingArea).maximumSizeValue) break;
          if ((this->workingArea).value[iVar3] == local_2c) goto LAB_004ee5be;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar6);
      }
      if (iVar6 > (this->workingArea).maximumSizeValue - 1) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar3 = 0;
          if (0 < (this->workingArea).maximumSizeValue) {
            do {
              if (iVar6 <= iVar3) break;
              iVar4 = iVar3 + 1;
              piVar2[iVar3] = (this->workingArea).value[iVar3];
              iVar3 = iVar4;
            } while (iVar4 < (this->workingArea).maximumSizeValue);
          }
          operator_delete((this->workingArea).value);
          (this->workingArea).value = piVar2;
          (this->workingArea).maximumSizeValue = iVar6;
        }
      }
      (this->workingArea).value[(this->workingArea).numberValue] = iVar1;
      (this->workingArea).numberValue = (this->workingArea).numberValue + 1;
LAB_004ee5be:
      tempInt = tempInt + 1;
    } while (tempInt < param_1);
  }
  rge_read(file,&param_1,4);
  tempInt = 0;
  if (0 < param_1) {
    do {
      rge_read(file,&local_2c,4);
      iVar1 = local_2c;
      iVar6 = (this->unitsTaskedThisUpdate).numberValue;
      iVar3 = 0;
      if (0 < iVar6) {
        do {
          if (iVar3 >= (this->unitsTaskedThisUpdate).maximumSizeValue) break;
          if ((this->unitsTaskedThisUpdate).value[iVar3] == local_2c) goto LAB_004ee6c3;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar6);
      }
      if (iVar6 > (this->unitsTaskedThisUpdate).maximumSizeValue - 1) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar3 = 0;
          if (0 < (this->unitsTaskedThisUpdate).maximumSizeValue) {
            do {
              if (iVar6 <= iVar3) break;
              iVar4 = iVar3 + 1;
              piVar2[iVar3] = (this->unitsTaskedThisUpdate).value[iVar3];
              iVar3 = iVar4;
            } while (iVar4 < (this->unitsTaskedThisUpdate).maximumSizeValue);
          }
          operator_delete((this->unitsTaskedThisUpdate).value);
          (this->unitsTaskedThisUpdate).value = piVar2;
          (this->unitsTaskedThisUpdate).maximumSizeValue = iVar6;
        }
      }
      (this->unitsTaskedThisUpdate).value[(this->unitsTaskedThisUpdate).numberValue] = iVar1;
      (this->unitsTaskedThisUpdate).numberValue = (this->unitsTaskedThisUpdate).numberValue + 1;
LAB_004ee6c3:
      tempInt = tempInt + 1;
    } while (tempInt < param_1);
  }
  iVar6 = param_2;
  piVar2 = this->actualGathererDistribution;
  iVar1 = 4;
  do {
    rge_read(file,piVar2,4);
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  piVar2 = this->desiredGathererDistribution;
  iVar1 = 4;
  do {
    rge_read(file,piVar2,4);
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  piVar2 = this->neededResourceValue;
  iVar1 = 4;
  do {
    rge_read(file,piVar2,4);
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  piVar2 = this->resourceDifferenceValue;
  iVar1 = 4;
  do {
    rge_read(file,piVar2,4);
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  piVar2 = this->numberStoragePitsBuilt;
  iVar1 = 4;
  do {
    rge_read(file,piVar2,4);
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  piVar2 = this->numberGranariesBuilt;
  iVar1 = 4;
  do {
    rge_read(file,piVar2,4);
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  iVar1 = 0;
  do {
    rge_read(file,&local_2c,4);
    this->neededResources.setValue(iVar1, local_2c);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 4);
  rge_read(file,&this->groupIDValue,4);
  piVar2 = &this->numberGroupsValue;
  rge_read(file,piVar2,4);
  iVar1 = 0;
  if (0 < *piVar2) {
    do {
      pTVar5 = this->createGroup(0);
      if (pTVar5 != (TacticalAIGroup *)0x0) {
        TacticalAIGroup::load(pTVar5,file);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *piVar2);
  }
  rge_read(file,&this->lastGroupAttackTime,4);
  if (!(save_game_version < 2.4f)) {
    rge_read(file,&this->lastGroupRebalanceTime,4);
  }
  rge_read(file,&this->lastAttackResponseTime,4);
  rge_read(file,&this->lastBoatAttackResponseTime,4);
  rge_read(file,&this->lastScalingUpdateValue,4);
  rge_read(file,&this->numberBuildUpdatesSkipped,4);
  rge_read(file,&this->randomizedAttackSeparationTime,4);
  if (!(save_game_version < 2.2f)) {
    rge_read(file,&this->attackEnabledValue,4);
  }
  rge_read(file,&this->updateArea,4);
  if (!(save_game_version < 6.1f)) {
    rge_read(file,&this->wonderInProgressValue,4);
    rge_read(file,&this->wonderBuiltValue,4);
  }
  if (!(save_game_version < 6.2f)) {
    rge_read(file,&this->placementStateValue,0x130);
  }
  else {
    piVar2 = (int *)&this->placementStateValue;
    for (iVar1 = 0x4c; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar2 = 0;
      piVar2 = piVar2 + 1;
    }
  }
  (this->placementStateValue).active = 0;
  if (!(save_game_version < 6.3f)) {
    rge_read(file,&this->nextCivilianToTaskValue,4);
  }
  if (!(save_game_version < 6.4f)) {
    rge_read(file,&this->nextIdleSoldierGroupToTaskValue,4);
    rge_read(file,&this->nextActiveSoldierGroupToTaskValue,4);
  }
  if (!(save_game_version < 6.9f)) {
    rge_read(file,&this->builtFirstStoragePit,4);
    rge_read(file,&this->builtFirstGranary,4);
  }
  if (!(save_game_version < 6.95f)) {
    rge_read(file,&this->lastBuildTime,4);
    rge_read(file,&this->lastAttackResponseBuildInsertionTime,4);
    rge_read(file,&this->lastCoopTributeDemandTime,4);
  }
  if (!(save_game_version < 7.18f)) {
    rge_read(file,&this->lastCoopTributeGiftTime,4);
  }
  if (!(save_game_version < 6.96f)) {
    rge_read(file,&this->zoomingToNextAge,4);
  }
  if (!(save_game_version < 6.98f)) {
    rge_read(file,&this->lastCoopAttackDemandTime,4);
  }
  if (!(save_game_version < 6.993f)) {
    rge_read(file,&this->lastUngroupedSoldierTaskTime,4);
  }
  if (!(save_game_version < 7.04f)) {
    rge_read(file,&this->attackStateValue,0x2c);
  }
  else {
    piVar2 = (int *)&this->attackStateValue;
    for (iVar1 = 0xb; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar2 = 0;
      piVar2 = piVar2 + 1;
    }
  }
  (this->attackStateValue).active = 0;
  if (save_game_version < 7.15f) {
    piVar2 = this->hitsByPlayer;
    for (iVar6 = 9; iVar6 != 0; iVar6 = iVar6 + -1) {
      *piVar2 = 0;
      piVar2 = piVar2 + 1;
    }
  }
  else {
    rge_read(file,this->hitsByPlayer,0x24);
  }
}

// ---------------------------------------------------------------------------
// PDB source owner: 004EEB40_TribeTacticalAIModule.cpp
// ---------------------------------------------------------------------------
// 004EEB40 TribeTacticalAIModule::~TribeTacticalAIModule
// Source: taitacmd.cpp lines 2032-2034
// Baseline: typed class/member reconstruction from the binary-backed layout.
// The destructor body removes all groups; the remaining cleanup is the normal
// reverse-order destruction of the nontrivial members and base class.
//
// Attempt log:
// - Replaced the raw offset/helper scaffold with the period-typed class surface
//   and natural member destruction order. First baseline check pending.
// - Typed all members from the binary-backed 0x100C layout. The first check
//   had 14 unresolved ManagedArray destructor calls and was 419 bytes short.
// - Kept civilians as the out-of-line ManagedArray<int> member at 00408D20;
//   modeled the other 13 identical four-word records with an inline
//   storage-record destructor so VC5 emits the observed scalar delete/zero
//   sequence and EH-state stores. This moved to exact size/CFG/call shape.
// - Changed operator delete to the period C++ global declaration; this
//   restored the 13 EH-state stores and reduced the remaining drift to one
//   relocation identity (4 bytes).
// - Added the decorated 00408D20 ManagedArray<int> identity to
//   config/original_symbol_overrides.txt; the rebuilt function is now exact.
// - Same-template inline destruction for all 14 members emitted one extra
//   cleanup block (788 bytes); volatile qualification was a codegen duplicate.
//   Restored the typed exact candidate. The storage-record distinction is
//   retained only because the executable proves the one out-of-line call and
//   the 13 inlined scalar cleanups.


TribeTacticalAIModule::~TribeTacticalAIModule()
{
    this->removeAllGroups(-1);
}

// ---------------------------------------------------------------------------
// PDB source owner: 004EEE40_updateAreaName.cpp
// ---------------------------------------------------------------------------
// 004EEE40 TribeTacticalAIModule::updateAreaName()
// Source: taitacmd.cpp lines 2039-2065
// Attempt log:
// - Replaced stub with full switch table of status string addresses.
// - Exact match with an unsigned switch input, producing the original `ja`
//   bounds check and jump table.


char* TribeTacticalAIModule::updateAreaName()
{
    switch (this->updateArea) {
    case 0: return (char*)0x0058839C;
    case 1: return (char*)0x0058838C;
    case 2: return (char*)0x00588380;
    case 3: return (char*)0x0058836C;
    case 4: return (char*)0x0058835C;
    case 5: return (char*)0x00588350;
    case 6: return (char*)0x00588340;
    case 7: return (char*)0x00588330;
    case 8: return (char*)0x00588324;
    case 9: return (char*)0x00588318;
    case 10: return (char*)0x00588308;
    case 11: return (char*)0x005882FC;
    case 12: return (char*)0x005882F4;
    case 13: return (char*)0x005882E4;
    case 14: return (char*)0x005882D8;
    case 15: return (char*)0x005882CC;
    case 16: return (char*)0x005882C0;
    case 17: return (char*)0x0058762C;
    case 18: return (char*)0x005882B4;
    case 19: return (char*)0x005882A8;
    case 20: return (char*)0x00588298;
    case 21: return (char*)0x00588284;
    default: return (char*)0x0057F54C;
    }
}

// ---------------------------------------------------------------------------
// PDB source owner: 004EEF40_update.cpp
// ---------------------------------------------------------------------------
// VA: 004EEF40 TribeTacticalAIModule::update
// PDB source: taitacmd.cpp:2070-2264
// Attempt log:
// - The prior scratch candidate used raw offset helpers and wrong diplomacy
//   member names. It was 677 bytes short and had 18/22 calls.
// - Rebuilt the source around the binary-proven TribeTacticalAIModule member
//   layout, ManagedArray records, strategic-number indices, and typed world /
//   diplomacy ownership. This is the clean typed baseline for the function.
// - The target's first pair clamp compares sn[0x10] > sn[0x1A] directly;
//   replaced the temporary-based spelling with that source-level predicate.
// - Corrected the farms-tasked record to the information-module ManagedArray
//   at +0xF0, placing numberValue at md+0xDE0.
// - Corrected enableAttack to the target's __thiscall member ABI and made the
//   tick/1000 guard unsigned, restoring the target magic-multiply sequence.
// - Restored the duplicate-aware ManagedArray::add donor surface for all
//   player-list insertions. This recovered the original scan and growth CFG.
// - Removed the cached md receiver. Direct this->md reloads recover 1421-byte
//   size, 0x8 frame, 22 ordered calls, and 98.19% instruction shape.
// - Corrected id ownership to RGE_Player +0x4A, with world +0x3C and
//   player_num +0x3C. The source now has 969 differing bytes and 107 edit
//   bytes. Remaining drift is localized to the farms reset reload and benign
//   register/block scheduling. No exact match; leave the clean typed source.
// - Update r2 probes: player/world/tick locals, a function-wide md receiver,
//   a post-reset player receiver, timestamp temporary, unsigned tick type,
//   and an information-subobject pointer were codegen duplicates or worse.
//   A defend-array reference also worsened structure. Restored the clean
//   typed source; no evidence-backed lead remains for this claim.
// - Claim probes 1-22 tested short md/player/world/tick aliases, declaration
//   scope, references, real MainDecision and world class surfaces, virtual
//   update ownership, the canonical world_time spelling, diplomacy layout,
//   and an inline world-time accessor. Aliases and declaration surfaces were
//   duplicate codegen. A world local and a function-wide md local were worse.
// - The Ghidra listing confirms a temporary md receiver in the first timing
//   block, but the typed scoped alias is codegen-neutral under VC5. The first
//   clean mismatch remains the lastScalingUpdate register permutation at
//   +0x121, followed by the missing six-byte md reload before the farms reset.
// - The clean baseline remains 1421 bytes, 0x8 frame, 22/22 ordered calls,
//   98.19% shape, 969 positional diff bytes, and 107 edit bytes. No exact
//   source was found. Restore this baseline before pause.
// Accepted-drift review: the rebuild keeps an already-loaded md pointer for
// the farms reset; the executable reloads md. No call occurs between capture
// and use. Later, the rebuild reads md before clearing playersToDefend, while
// the executable clears first; both dereference md after the clear. No call
// crosses this scheduling change. All 22 calls and ManagedArray effects match.
// - Exact finish in the registered taitacmd.cpp context kept shared resize
//   out of line to protect 004F13F0. A local inline growth body restores the
//   target's three operator_new/operator_delete pairs without a helper call.
//   The zeroNumber calls preserve the md reread and player publication order.
// - Walkback of the local growth body restores three direct resize calls and
//   a 1266-byte drift. Fresh reduced validation matches all 1421 bytes, 22
//   ordered calls, the PDB-qualified owner, and every original basic block.


// BINARY NOTE: These three target insertions inline growth and emit direct
// operator_new/operator_delete calls. The shared add method emits resize.
static inline int addTacticalPlayer(ManagedArray<int>& array, int valueToAdd)
{
    int i;
    int* newValue;
    int newSize;

    for (i = 0; i < array.numberValue; i++) {
        if (i >= array.maximumSizeValue) break;
        if (array.value[i] == valueToAdd) return 0;
    }
    if (array.numberValue > array.maximumSizeValue - 1) {
        newSize = array.numberValue + 1;
        newValue = (int*)operator_new(newSize * sizeof(int));
        if (newValue != 0) {
            for (i = 0; i < array.maximumSizeValue; i++) {
                if (i >= newSize) break;
                newValue[i] = array.value[i];
            }
            operator_delete(array.value);
            array.value = newValue;
            array.maximumSizeValue = newSize;
        }
    }
    array.value[array.numberValue] = valueToAdd;
    array.numberValue = array.numberValue + 1;
    return 1;
}

int TribeTacticalAIModule::update(int)
{
    if ((unsigned int)(this->md->player->world->world_time -
                       this->lastScalingUpdateValue) >
        (unsigned int)(this->sn[0x63] * 60000)) {
        this->sn[0x1A] += this->sn[0x5E];
        if (this->sn[0x1A] < 0) {
            this->sn[0x1A] = 0;
        }

        this->sn[0x10] += this->sn[0x5D];
        if (this->sn[0x10] < 0) {
            this->sn[0x10] = 0;
        }

        int value;
        if (this->sn[0x10] > this->sn[0x1A]) {
            this->sn[0x10] = this->sn[0x1A];
        }
        value = this->sn[0x1A];
        if (value < this->sn[0x10]) {
            this->sn[0x1A] = this->sn[0x10];
        }

        value = this->sn[0x1E] << 1;
        this->sn[0x1E] = value;
        if (value < 0) {
            this->sn[0x1E] = 0;
        }
        if (100 < this->sn[0x1E]) {
            this->sn[0x1E] = 100;
        }

        value = this->sn[0x1F] << 1;
        this->sn[0x1F] = value;
        if (value < 0) {
            this->sn[0x1F] = 0;
        }
        if (100 < this->sn[0x1F]) {
            this->sn[0x1F] = 100;
        }

        value = this->sn[0x5B] << 1;
        this->sn[0x5B] = value;
        if (value < 0) {
            this->sn[0x5B] = 0;
        }
        if (100 < this->sn[0x5B]) {
            this->sn[0x5B] = 100;
        }

        this->lastScalingUpdateValue = this->md->player->world->world_time;
    }

    // BINARY NOTE: This period array method preserves the md reread below.
    this->unitsTaskedThisUpdate.zeroNumber();
    this->md->informationAI.farmsTaskedThisUpdate.numberValue = 0;

    if ((unsigned int)this->md->player->world->world_time / 1000U >=
        (unsigned int)this->sn[0x68]) {
        this->enableAttack(2);
    }

    int mostHatedPlayer = this->md->diplomacyAI.mostHated(
        this->sn[0x7C], this->sn[0x80], this->sn[0xBC], this->sn[0xC3]);
    int mostLikedPlayer = this->md->diplomacyAI.mostLiked(
        this->sn[0x7C], this->sn[0x80]);

    this->playersToAttack.numberValue = 0;
    addTacticalPlayer(this->playersToAttack, mostHatedPlayer);

    this->playersToDefend.zeroNumber();
    addTacticalPlayer(this->playersToDefend, this->md->player->id);

    if (mostHatedPlayer != mostLikedPlayer) {
        addTacticalPlayer(this->playersToDefend, mostLikedPlayer);
    }

diplomacy:
    {
        int player = 1;
        if (1 < this->md->player->world->player_num) {
            do {
        if (player != this->md->player->id) {
                    if (player == mostHatedPlayer) {
                        if (this->md->diplomacyAI.isEnemy(player) == 0 &&
                            this->md->diplomacyAI.isChangeable(player) != 0 &&
                            this->md->diplomacyAI.stance(player, 0) > 0x4A) {
                            this->md->diplomacyAI.setRelation(player, 3);
                        }
                    } else if (player == mostLikedPlayer) {
                        if (this->md->diplomacyAI.isAlly(player) == 0 &&
                            this->md->diplomacyAI.isChangeable(player) != 0 &&
                            this->md->diplomacyAI.stance(player, 2) > 0x4A) {
                            this->md->diplomacyAI.setRelation(player, 0);
                        }
                    } else {
                        int stance = this->md->diplomacyAI.stance(player, 2);
                        if (stance > this->sn[0x1D] &&
                            this->md->diplomacyAI.isChangeable(player) != 0) {
                            if (this->md->diplomacyAI.isAlly(player) == 0) {
                                this->md->diplomacyAI.setRelation(player, 0);
                            }
                        } else if (this->md->diplomacyAI.isNeutral(player) == 0 &&
                                   this->md->diplomacyAI.isChangeable(player) != 0) {
                            this->md->diplomacyAI.setRelation(player, 1);
                        }
                    }
                }
                player++;
            } while (player < this->md->player->world->player_num);
        }
    }

    this->doSomething();
    this->unitsTaskedThisUpdate.numberValue = 0;
    return 1;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004EF4D0_setMainDecisionAI.cpp
// ---------------------------------------------------------------------------
void TribeTacticalAIModule::setMainDecisionAI(TribeMainDecisionAIModule* val) { this->md = val; }

// ---------------------------------------------------------------------------
// PDB source owner: 004EF4E0_save.cpp
// ---------------------------------------------------------------------------
// VA: 004EF4E0 TribeTacticalAIModule::save
// PDB: taitacmd.cpp:2276-2426
//
// Canonical serialization order recovered from the executable:
// four resize-backed task arrays, scalar/gatherer data, six legacy arrays
// with their inline grow-on-read bodies, the fixed strategic-number table,
// four more grow-on-read arrays, distributions/resource values, the group
// sentinel list, and the remaining tactical state.
//
// Attempt log:
// - Baseline: named binary-proven tactical fields/arrays and ordered writes;
//   3347B, 94/94 calls, 0x8 frame, 91.13% shape.
// - Scoped loop/grow locals alone were codegen-neutral; a named `newMax` on
//   the first manual grow removed the artificial frame and improved size.
// - Guarded ManagedArray aliases for the four resize-backed arrays recovered
//   the original shared array-base accesses.
// - Reused the matched ManagedArray donor's `newMax` plus bounded `for` copy
//   form across all ten manual growth blocks. Current: 3230B, 94/94 calls,
//   0x0 frame, 99.41% shape, 822 positional bytes / 187 edit bytes.
// - Moving the fixed `sn[226]` write-pointer assignment inside its positive
//   count guard reproduced the original test-before-`lea` block order.
// - Original tail serialization writes `zoomingToNextAge` before the adjacent
//   `lastCoopAttackDemandTime` field. Swapping those natural statements gives
//   an exact 3230B / 94-call match.
// - The canonical inline resize body stays visible for same-TU update. Four
//   early save resize sites remain out of line, as the executable requires.

void __cdecl rge_write(int file, void* data, int size);
void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* ptr);


int TribeTacticalAIModule::save(int file)
{
    int tempInt;

    {
    int i;
    tempInt = this->civilians.numberValue;
    rge_write(file, &tempInt, 4);
    i = 0;
    if (this->civilians.numberValue > 0) {
        ManagedArray_int& arr = this->civilians;
        do {
            if (i > arr.maximumSizeValue - 1) {
                arr.resize(i + 1);
            }
            tempInt = arr.value[i];
            rge_write(file, &tempInt, 4);
            i++;
        } while (i < this->civilians.numberValue);
    }
    }

    {
    int i;
    tempInt = this->civilianExplorers.numberValue;
    rge_write(file, &tempInt, 4);
    i = 0;
    if (this->civilianExplorers.numberValue > 0) {
        ManagedArray_int& arr = this->civilianExplorers;
        do {
            if (i > arr.maximumSizeValue - 1) {
                arr.resize(i + 1);
            }
            tempInt = arr.value[i];
            rge_write(file, &tempInt, 4);
            i++;
        } while (i < this->civilianExplorers.numberValue);
    }
    }

    rge_write(file, &this->numberGatherersValue, 4);
    rge_write(file, &this->desiredNumberGatherersValue, 4);
    rge_write(file, this->gatherers, 0x4B0);

    {
    int i;
    tempInt = this->soldiers.numberValue;
    rge_write(file, &tempInt, 4);
    i = 0;
    if (this->soldiers.numberValue > 0) {
        ManagedArray_int& arr = this->soldiers;
        do {
            if (i > arr.maximumSizeValue - 1) {
                arr.resize(i + 1);
            }
            tempInt = arr.value[i];
            rge_write(file, &tempInt, 4);
            i++;
        } while (i < this->soldiers.numberValue);
    }
    }

    {
    int i;
    tempInt = this->ungroupedSoldiers.numberValue;
    rge_write(file, &tempInt, 4);
    i = 0;
    if (this->ungroupedSoldiers.numberValue > 0) {
        ManagedArray_int& arr = this->ungroupedSoldiers;
        do {
            if (i > arr.maximumSizeValue - 1) {
                arr.resize(i + 1);
            }
            tempInt = arr.value[i];
            rge_write(file, &tempInt, 4);
            i++;
        } while (i < this->ungroupedSoldiers.numberValue);
    }
    }

    {
    int k;
    tempInt = this->boats.numberValue;
    rge_write(file, &tempInt, 4);
    k = 0;
    if (this->boats.numberValue > 0) {
        do {
            if (k > this->boats.maximumSizeValue - 1) {
                int newMax;
                int* newValue;
                int j;
                newMax = k + 1;
                newValue = (int*)operator new(k * 4 + 4);
                if (newValue != 0) {
                    j = 0;
                    for (; j < this->boats.maximumSizeValue && j < newMax; j++) {
                        int* oldValue = this->boats.value;
                        newValue[j] = oldValue[j];
                    }
                    operator delete(this->boats.value);
                    this->boats.value = newValue;
                    this->boats.maximumSizeValue = newMax;
                }
            }
            tempInt = this->boats.value[k];
            rge_write(file, &tempInt, 4);
            k++;
        } while (k < this->boats.numberValue);
    }
    }

    {
    int k;
    tempInt = this->warBoats.numberValue;
    rge_write(file, &tempInt, 4);
    k = 0;
    if (this->warBoats.numberValue > 0) {
        do {
            if (k > this->warBoats.maximumSizeValue - 1) {
                int newMax;
                int* newValue;
                int j;
                newMax = k + 1;
                newValue = (int*)operator new(k * 4 + 4);
                if (newValue != 0) {
                    j = 0;
                    for (; j < this->warBoats.maximumSizeValue && j < newMax; j++) {
                        int* oldValue = this->warBoats.value;
                        newValue[j] = oldValue[j];
                    }
                    operator delete(this->warBoats.value);
                    this->warBoats.value = newValue;
                    this->warBoats.maximumSizeValue = newMax;
                }
            }
            tempInt = this->warBoats.value[k];
            rge_write(file, &tempInt, 4);
            k++;
        } while (k < this->warBoats.numberValue);
    }
    }

    {
    int k;
    tempInt = this->fishingBoats.numberValue;
    rge_write(file, &tempInt, 4);
    k = 0;
    if (this->fishingBoats.numberValue > 0) {
        do {
            if (k > this->fishingBoats.maximumSizeValue - 1) {
                int newMax;
                int* newValue;
                int j;
                newMax = k + 1;
                newValue = (int*)operator new(k * 4 + 4);
                if (newValue != 0) {
                    j = 0;
                    for (; j < this->fishingBoats.maximumSizeValue && j < newMax; j++) {
                        int* oldValue = this->fishingBoats.value;
                        newValue[j] = oldValue[j];
                    }
                    operator delete(this->fishingBoats.value);
                    this->fishingBoats.value = newValue;
                    this->fishingBoats.maximumSizeValue = newMax;
                }
            }
            tempInt = this->fishingBoats.value[k];
            rge_write(file, &tempInt, 4);
            k++;
        } while (k < this->fishingBoats.numberValue);
    }
    }

    {
    int k;
    tempInt = this->tradeBoats.numberValue;
    rge_write(file, &tempInt, 4);
    k = 0;
    if (this->tradeBoats.numberValue > 0) {
        do {
            if (k > this->tradeBoats.maximumSizeValue - 1) {
                int newMax;
                int* newValue;
                int j;
                newMax = k + 1;
                newValue = (int*)operator new(k * 4 + 4);
                if (newValue != 0) {
                    j = 0;
                    for (; j < this->tradeBoats.maximumSizeValue && j < newMax; j++) {
                        int* oldValue = this->tradeBoats.value;
                        newValue[j] = oldValue[j];
                    }
                    operator delete(this->tradeBoats.value);
                    this->tradeBoats.value = newValue;
                    this->tradeBoats.maximumSizeValue = newMax;
                }
            }
            tempInt = this->tradeBoats.value[k];
            rge_write(file, &tempInt, 4);
            k++;
        } while (k < this->tradeBoats.numberValue);
    }
    }

    {
    int k;
    tempInt = this->transportBoats.numberValue;
    rge_write(file, &tempInt, 4);
    k = 0;
    if (this->transportBoats.numberValue > 0) {
        do {
            if (k > this->transportBoats.maximumSizeValue - 1) {
                int newMax;
                int* newValue;
                int j;
                newMax = k + 1;
                newValue = (int*)operator new(k * 4 + 4);
                if (newValue != 0) {
                    j = 0;
                    for (; j < this->transportBoats.maximumSizeValue && j < newMax; j++) {
                        int* oldValue = this->transportBoats.value;
                        newValue[j] = oldValue[j];
                    }
                    operator delete(this->transportBoats.value);
                    this->transportBoats.value = newValue;
                    this->transportBoats.maximumSizeValue = newMax;
                }
            }
            tempInt = this->transportBoats.value[k];
            rge_write(file, &tempInt, 4);
            k++;
        } while (k < this->transportBoats.numberValue);
    }
    }

    {
    int k;
    tempInt = this->artifacts.numberValue;
    rge_write(file, &tempInt, 4);
    k = 0;
    if (this->artifacts.numberValue > 0) {
        do {
            if (k > this->artifacts.maximumSizeValue - 1) {
                int newMax;
                int* newValue;
                int j;
                newMax = k + 1;
                newValue = (int*)operator new(k * 4 + 4);
                if (newValue != 0) {
                    j = 0;
                    for (; j < this->artifacts.maximumSizeValue && j < newMax; j++) {
                        int* oldValue = this->artifacts.value;
                        newValue[j] = oldValue[j];
                    }
                    operator delete(this->artifacts.value);
                    this->artifacts.value = newValue;
                    this->artifacts.maximumSizeValue = newMax;
                }
            }
            tempInt = this->artifacts.value[k];
            rge_write(file, &tempInt, 4);
            k++;
        } while (k < this->artifacts.numberValue);
    }
    }

    int* writePtr;
    int writeCount;
    {
    tempInt = 0xE2;
    rge_write(file, &tempInt, 4);
    writeCount = 0;
    if (writeCount < tempInt) {
        writePtr = this->sn;
        do {
            rge_write(file, writePtr, 4);
            writeCount++;
            writePtr++;
        } while (writeCount < tempInt);
    }
    }

    {
    int k;
    tempInt = this->playersToAttack.numberValue;
    rge_write(file, &tempInt, 4);
    k = 0;
    if (this->playersToAttack.numberValue > 0) {
        do {
            if (k > this->playersToAttack.maximumSizeValue - 1) {
                int newMax;
                int* newValue;
                int j;
                newMax = k + 1;
                newValue = (int*)operator new(k * 4 + 4);
                if (newValue != 0) {
                    j = 0;
                    for (; j < this->playersToAttack.maximumSizeValue && j < newMax; j++) {
                        int* oldValue = this->playersToAttack.value;
                        newValue[j] = oldValue[j];
                    }
                    operator delete(this->playersToAttack.value);
                    this->playersToAttack.value = newValue;
                    this->playersToAttack.maximumSizeValue = newMax;
                }
            }
            tempInt = this->playersToAttack.value[k];
            rge_write(file, &tempInt, 4);
            k++;
        } while (k < this->playersToAttack.numberValue);
    }
    }

    {
    int k;
    tempInt = this->playersToDefend.numberValue;
    rge_write(file, &tempInt, 4);
    k = 0;
    if (this->playersToDefend.numberValue > 0) {
        do {
            if (k > this->playersToDefend.maximumSizeValue - 1) {
                int newMax;
                int* newValue;
                int j;
                newMax = k + 1;
                newValue = (int*)operator new(k * 4 + 4);
                if (newValue != 0) {
                    j = 0;
                    for (; j < this->playersToDefend.maximumSizeValue && j < newMax; j++) {
                        int* oldValue = this->playersToDefend.value;
                        newValue[j] = oldValue[j];
                    }
                    operator delete(this->playersToDefend.value);
                    this->playersToDefend.value = newValue;
                    this->playersToDefend.maximumSizeValue = newMax;
                }
            }
            tempInt = this->playersToDefend.value[k];
            rge_write(file, &tempInt, 4);
            k++;
        } while (k < this->playersToDefend.numberValue);
    }
    }

    {
    int k;
    tempInt = this->workingArea.numberValue;
    rge_write(file, &tempInt, 4);
    k = 0;
    if (this->workingArea.numberValue > 0) {
        do {
            if (k > this->workingArea.maximumSizeValue - 1) {
                int newMax;
                int* newValue;
                int j;
                newMax = k + 1;
                newValue = (int*)operator new(k * 4 + 4);
                if (newValue != 0) {
                    j = 0;
                    for (; j < this->workingArea.maximumSizeValue && j < newMax; j++) {
                        int* oldValue = this->workingArea.value;
                        newValue[j] = oldValue[j];
                    }
                    operator delete(this->workingArea.value);
                    this->workingArea.value = newValue;
                    this->workingArea.maximumSizeValue = newMax;
                }
            }
            tempInt = this->workingArea.value[k];
            rge_write(file, &tempInt, 4);
            k++;
        } while (k < this->workingArea.numberValue);
    }
    }

    {
    int k;
    tempInt = this->unitsTaskedThisUpdate.numberValue;
    rge_write(file, &tempInt, 4);
    k = 0;
    if (this->unitsTaskedThisUpdate.numberValue > 0) {
        do {
            if (k > this->unitsTaskedThisUpdate.maximumSizeValue - 1) {
                int newMax;
                int* newValue;
                int j;
                newMax = k + 1;
                newValue = (int*)operator new(k * 4 + 4);
                if (newValue != 0) {
                    j = 0;
                    for (; j < this->unitsTaskedThisUpdate.maximumSizeValue && j < newMax; j++) {
                        int* oldValue = this->unitsTaskedThisUpdate.value;
                        newValue[j] = oldValue[j];
                    }
                    operator delete(this->unitsTaskedThisUpdate.value);
                    this->unitsTaskedThisUpdate.value = newValue;
                    this->unitsTaskedThisUpdate.maximumSizeValue = newMax;
                }
            }
            tempInt = this->unitsTaskedThisUpdate.value[k];
            rge_write(file, &tempInt, 4);
            k++;
        } while (k < this->unitsTaskedThisUpdate.numberValue);
    }
    }

    writePtr = this->actualGathererDistribution;
    writeCount = 4;
    do {
        rge_write(file, writePtr, 4);
        writePtr++;
        writeCount--;
    } while (writeCount != 0);

    writePtr = this->desiredGathererDistribution;
    writeCount = 4;
    do {
        rge_write(file, writePtr, 4);
        writePtr++;
        writeCount--;
    } while (writeCount != 0);

    writePtr = this->neededResourceValue;
    writeCount = 4;
    do {
        rge_write(file, writePtr, 4);
        writePtr++;
        writeCount--;
    } while (writeCount != 0);

    writePtr = this->resourceDifferenceValue;
    writeCount = 4;
    do {
        rge_write(file, writePtr, 4);
        writePtr++;
        writeCount--;
    } while (writeCount != 0);

    writePtr = this->numberStoragePitsBuilt;
    writeCount = 4;
    do {
        rge_write(file, writePtr, 4);
        writePtr++;
        writeCount--;
    } while (writeCount != 0);

    writePtr = this->numberGranariesBuilt;
    writeCount = 4;
    do {
        rge_write(file, writePtr, 4);
        writePtr++;
        writeCount--;
    } while (writeCount != 0);

    {
    int i;
    i = 0;
    do {
        tempInt = this->neededResources.value(i);
        rge_write(file, &tempInt, 4);
        i++;
    } while (i < 4);
    }

    rge_write(file, &this->groupIDValue, 4);
    rge_write(file, &this->numberGroupsValue, 4);

    TacticalAIGroup* group;
    group = this->groups.next;
    while (group != &this->groups && group != 0) {
        group->save(file);
        group = group->next;
    }

    rge_write(file, &this->lastGroupAttackTime, 4);
    rge_write(file, &this->lastGroupRebalanceTime, 4);
    rge_write(file, &this->lastAttackResponseTime, 4);
    rge_write(file, &this->lastBoatAttackResponseTime, 4);
    rge_write(file, &this->lastScalingUpdateValue, 4);
    rge_write(file, &this->numberBuildUpdatesSkipped, 4);
    rge_write(file, &this->randomizedAttackSeparationTime, 4);
    rge_write(file, &this->attackEnabledValue, 4);
    rge_write(file, &this->updateArea, 4);
    rge_write(file, &this->wonderInProgressValue, 4);
    rge_write(file, &this->wonderBuiltValue, 4);
    rge_write(file, &this->placementStateValue, 0x130);
    rge_write(file, &this->nextCivilianToTaskValue, 4);
    rge_write(file, &this->nextIdleSoldierGroupToTaskValue, 4);
    rge_write(file, &this->nextActiveSoldierGroupToTaskValue, 4);
    rge_write(file, &this->builtFirstStoragePit, 4);
    rge_write(file, &this->builtFirstGranary, 4);
    rge_write(file, &this->lastBuildTime, 4);
    rge_write(file, &this->lastAttackResponseBuildInsertionTime, 4);
    rge_write(file, &this->lastCoopTributeDemandTime, 4);
    rge_write(file, &this->lastCoopTributeGiftTime, 4);
    rge_write(file, &this->zoomingToNextAge, 4);
    rge_write(file, &this->lastCoopAttackDemandTime, 4);
    rge_write(file, &this->lastUngroupedSoldierTaskTime, 4);
    rge_write(file, &this->attackStateValue, 0x2C);
    rge_write(file, this->hitsByPlayer, 0x24);

    return 1;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F0180_logGroupDebug.cpp
// ---------------------------------------------------------------------------
void __cdecl TribeTacticalAIModule::logGroupDebug(int, char*, ...) {}

// ---------------------------------------------------------------------------
// PDB source owner: 004F0190_doSomething.cpp
// ---------------------------------------------------------------------------
// 004F0190 TribeTacticalAIModule::doSomething
// Canonical baseline: named tactical-AI arrays/modules, natural switch dispatch,
// and the period source's shared update-area timing tails.
//
// Attempt log:
// - baseline: canonical md/module ownership and natural dense switch; frame 0x128,
//   73/78 calls, 83.23% shape, 182 bytes short.
// - restored case 0x15's unskip/timing/select-next terminal path and direct
//   updateBuildAIWithObjects call; size and call count became exact (2514/78).
// - branch-local mostDamaged calls recovered the binary's push/jump dispatch;
//   current best remained structurally aligned through the tactical cases.
// - direct buildListLength call predicates recovered three test-eax blocks.
// - fixed common timing average to the executable's fixed /20 division; case 0x15
//   retains its separate total/count division.
// - declaration/name and goto/break normalization were codegen-neutral; retained
//   the natural source reconstruction rather than compiler-only CFG scaffolding.
// - final bounded result: 420 positional bytes / 92.62% shape, 78 calls, frame
//   0x128, first mismatch remains the initial timing local home and late timing
//   tail/block placement. Left in scratch after the 10-hypothesis budget.
// - follow-up: out-of-line case-21 labels, switch default/case order, timing
//   declaration permutations, and declaration initialization were codegen
//   duplicates; the direct world-time guard widened the body by 102 bytes.
//   Explicit common-tail labels widened it by 94 bytes. Restored the clean
//   natural source; the structural blocker remains unchanged.
// - Restored virtual ownership and the named build-file format string. The
//   raw vtable fields and absolute string address were diagnostic surfaces.
// - Fresh pass: extern-C timer linkage, timer declaration/assignment order,
//   switch-label order, scoped timer locals, explicit loop breaks, and several
//   coordinate assignment orders were duplicate or worse.
// - The PDB-backed case-19 resource scan is best written as a for-loop with
//   cursor updates in its increment clause. This restores the original JL
//   backedge and improves the clean result to 417 differing bytes, 92.92%
//   shape, 78/78 calls, and 0x128 frame.
// - The registered context now exposes a narrow nonvirtual TribeBuildAIModule
//   surface for exact anchors. A local inherited virtual view restores the
//   original +0x44 loadBuildList call without changing shared declarations.
//   Fresh output is 2514 bytes, 78 calls, frame 0x128, and 348 differing bytes.
// - CVDump proves four stack locals and their names. They are startTime at
//   -0x11C, availableTime at -0x120, incUpdateArea at -0x128, and
//   updateAreaStartTime at -0x124.
// - CVDump also proves three branch-local XYPoint variables named position.
//   Their homes are -0x108, -0x118, and -0x110. These scopes restore all three
//   x87 conversion blocks without fake aliases.
// - Direct member timing updates restore the four timing homes and the complete
//   common timing block. Local elapsed, total, and count values were decompiler
//   artifacts.
// - The executable casts the unsigned world-time delta to signed int before
//   division. This source keeps unsigned wrap, then applies signed division and
//   the signed <= 5 test.
// - The signed age block and direct timing source restore the internal case-21
//   blocks. The remaining mismatch is the late block order and boundary.
// - Gotos, shared returns, loop forms, timer scopes, switch order, missing
//   default, nested calls, duplicate exits, 512 ambient contexts, and supported
//   flag axes did not recover that order.
// BLOCKER: The executable puts the 0xBC9 finish block before cold case 21.
// VC5 puts case 21 first, adds a loop jump, and places the finish block last.
// With the required signed age source, the rebuilt reachable boundary is 98
// bytes too large because it also includes the following switch table.

static const char s_build_file_format[] = "%s.bld";


int TribeTacticalAIModule::doSomething()
{
    unsigned long startTime;
    unsigned long availableTime;
    int incUpdateArea;
    unsigned long updateAreaStartTime;
    unsigned long currentTime;
    char tempName[256];

    availableTime = this->md->player->world->availableComputerPlayerUpdateTime;
    startTime = debug_timeGetTime((char*)0x5880C0, 0x99C);

    if (availableTime > 0) {
        do {
            updateAreaStartTime = debug_timeGetTime((char*)0x5880C0, 0x99F);
            incUpdateArea = 1;

            switch (this->updateArea) {
            case 0:
                this->setupSoldierGroups();
                break;

            case 1:
                if (this->civilians.numberValue > 0) {
                    if (this->firstNeededResourceUpdateDone == 0) {
                        this->firstNeededResourceUpdateDone = 1;
                        this->updateNeededResources();
                    }
                    this->evaluateCivilianDistribution();
                }
                break;

            case 2:
                this->taskCivilians(startTime, availableTime);
                if (this->nextCivilianToTaskValue != -1) {
                    incUpdateArea = 0;
                }
                break;

            case 3:
                if (this->boats.numberValue > 0) {
                    this->setupBoatGroups();
                }
                break;

            case 4:
                if (this->boats.numberValue > 0) {
                    this->fillBoatGroups();
                }
                break;

            case 5:
                if (this->boats.numberValue > 0) {
                    this->taskBoats();
                }
                break;

            case 6:
                if (this->boats.numberValue > 0 || this->soldiers.numberValue > 0) {
                    this->fillSoldierGroups();
                }
                break;

            case 7:
                if (this->boats.numberValue > 0 ||
                    this->soldiers.numberValue > 0 ||
                    this->artifacts.numberValue > 0) {
                    this->taskIdleSoldiers(startTime, availableTime);
                    if (this->nextIdleSoldierGroupToTaskValue != -1) {
                        incUpdateArea = 0;
                    }
                }
                break;

            case 8:
                if (this->boats.numberValue > 0 ||
                    this->soldiers.numberValue > 0 ||
                    this->artifacts.numberValue > 0) {
                    this->taskActiveSoldiers(startTime, availableTime);
                    if (this->nextActiveSoldierGroupToTaskValue != -1) {
                        incUpdateArea = 0;
                    }
                }
                break;

            case 9:
                if (this->soldiers.numberValue > 0) {
                    this->playTaskSoldiers(startTime, availableTime);
                }
                break;

            case 10: {
                RGE_Static_Object* object =
                    this->md->object(-1, 0x6D, -1, -1, -1, -1, -1, -1, -1, -1);
                if (object != 0) {
                    int distance = this->md->informationAI.withinXTilesOfObject(
                        object, 0x14, 0x4F, 0xC7, 0x45, 0x116);
                    if (distance != -1) {
                        this->saveTheTown(distance);
                    }
                }
                break;
            }

            case 11: {
                this->numberBuildUpdatesSkipped++;
                if (this->md->buildAI.buildListLength() > 0 &&
                    this->numberBuildUpdatesSkipped >= this->sn[0x65]) {
                    BuildItem* item = this->md->buildAI.nextBuildableItem(1);
                    if (item != 0) {
                        this->taskResearch(item);
                    }
                }
                break;
            }

            case 12: {
                if (this->md->player->attributes[0x0B] <
                    this->md->player->attributes[0x20]) {
                    if (this->md->buildAI.buildListLength() > 0 &&
                        this->numberBuildUpdatesSkipped >= this->sn[0x65]) {
                        BuildItem* item = this->md->buildAI.nextBuildableItem(2);
                        if (item != 0) {
                            this->taskTrain(item);
                        }
                    }
                }
                break;
            }

            case 13: {
                if (this->md->buildAI.buildListLength() > 0 &&
                    this->numberBuildUpdatesSkipped >= this->sn[0x65]) {
                    BuildItem* item = this->md->buildAI.nextBuildableItem(3);
                    if (item != 0) {
                        sprintf(tempName, s_build_file_format, item->name());
                        this->md->buildAI.loadBuildList(
                            tempName, this->md->aiPlayer);
                        this->md->updateBuildAIWithObjects();
                        this->updateNeededResources();
                    }
                    this->numberBuildUpdatesSkipped = 0;
                }
                break;
            }

            case 14: {
                if (this->initialExplorationSatisfied() != 0) {
                    if (this->md->numberObjectsWithAction(0x25A) < this->sn[4] ||
                        this->wonderInProgressValue != 0 ||
                        this->wonderBuiltValue != 0) {
                        RGE_Static_Object* object =
                            this->md->object(-1, -1, -1, -1, -1, -1, -1, -1, 0, -1);
                        if (object != 0) {
                            RGE_Static_Object* wonder = this->md->object(
                                -1, -1, -1, 0x25A, -1, object->id, -1, -1, -1, -1);
                            if (this->wonderInProgressValue != 0 || wonder == 0) {
                                // BINARY NOTE: PDB gives each branch its own position home.
                                XYPoint position;
                                position.x = (int)object->world_x;
                                position.y = (int)object->world_y;
                                int id = this->civilian(&position, 1, 0x2BE, 0x2CE, 0x2BC, 0);
                                if (id != -1) {
                                    if (this->taskBuilder(id, object) == 1) {
                                        this->lastBuildTime =
                                            this->md->player->world->world_time;
                                    }
                                }
                            }
                        }
                    }
                }
                break;
            }

            case 15: {
                if (this->initialExplorationSatisfied() != 0) {
                    if (this->md->numberObjectsWithAction(0x25A) < this->sn[4] ||
                        this->wonderInProgressValue != 0 ||
                        this->wonderBuiltValue != 0) {
                        RGE_Static_Object* object;
                        if (this->wonderBuiltValue == 1) {
                            object = this->md->mostDamaged(3, 0x114);
                        } else {
                            object = this->md->mostDamaged(3, -1);
                        }
                        if (object != 0 && object->object_state == 2) {
                            RGE_Static_Object* existing = this->md->object(
                                -1, -1, -1, 0x26A, -1, object->id, -1, -1, -1, -1);
                            if (existing == 0) {
                                XYPoint position;
                                position.x = (int)object->world_x;
                                position.y = (int)object->world_y;
                                int id = this->civilian(&position, 1, 0x2BE, 0x2CE, 0x2BC, 0);
                                if (id != -1) {
                                    this->taskRepairer(id, object);
                                }
                            }
                        }
                    }
                }
                break;
            }

            case 16: {
                if (this->initialExplorationSatisfied() != 0) {
                    if (this->md->numberObjectsWithAction(0x25A) < this->sn[4] ||
                        this->wonderInProgressValue != 0 ||
                        this->wonderBuiltValue != 0) {
                        RGE_Static_Object* object = this->md->mostDamaged(0x1B, -1);
                        if (object != 0 && object->object_state == 2) {
                            RGE_Static_Object* existing = this->md->object(
                                -1, -1, -1, 0x26A, -1, object->id, -1, -1, -1, -1);
                            if (existing == 0) {
                                XYPoint position;
                                position.x = (int)object->world_x;
                                position.y = (int)object->world_y;
                                int id = this->civilian(&position, 1, 0x2BE, 0x2CE, 0x2BC, 0);
                                if (id != -1) {
                                    this->taskRepairer(id, object);
                                }
                            }
                        }
                    }
                }
                break;
            }

            case 17: {
                if (this->initialExplorationSatisfied() != 0) {
                    if ((this->md->numberObjectsWithAction(0x25A) < this->sn[4] ||
                         this->wonderInProgressValue != 0 ||
                         this->wonderBuiltValue != 0) &&
                        this->wonderInProgressValue == 0) {
                        BuildItem* item = this->md->buildAI.nextBuildableItem(0);
                        if (item != 0 &&
                            this->taskBuilder(-1, item, 0, startTime) == 1) {
                            this->lastBuildTime =
                                this->md->player->world->world_time;
                        }
                    }
                }
                break;
            }

            case 18: {
                if (this->placementStateValue.active == 1) {
                    ConstructionItem* construction =
                        this->md->constructionAI.placeStructure(
                            this->placementStateValue.buildItem,
                            this->placementStateValue.builderID,
                            this->placementStateValue,
                            startTime);
                    if (construction != 0) {
                        if (this->taskBuilder(this->placementStateValue.builderID,
                                              this->placementStateValue.buildItem,
                                              construction, startTime) == 1) {
                            this->lastBuildTime =
                                this->md->player->world->world_time;
                        }
                    }
                    if (this->placementStateValue.active == 1) {
                        incUpdateArea = 0;
                    }
                }
                break;
            }

            case 19: {
                this->evaluateOpenTasks();
                int i = 0;
                int* difference = this->resourceDifferenceValue;
                for (; i < 4; ++i, ++difference) {
                    if (*difference > 0 &&
                        this->md->resourceAI.resource(i) + *difference < 0) {
                        this->updateNeededResources();
                        break;
                    }
                }
                this->checkForCoopTributeDemand();
                this->checkForCoopTributeGift();
                this->checkForASAPAgeResearch();
                this->checkTradeBoats();
                this->checkStaleAttackGroups();
                break;
            }

            case 20: {
                int resource = this->md->informationAI.closestDropsiteResID(0);
                RGE_Static_Object* object = this->md->object(resource);
                if (object == 0) {
                    this->md->informationAI.updateResourceDropsites(0);
                }
                break;
            }

            case 21:
                this->evaluateBuildListInsertions();
                // BINARY NOTE: Wrap as unsigned, then use signed age division.
                if (5 < (int)(this->md->player->world->world_time -
                              this->lastBuildTime) / 60000) {
                    this->md->buildAI.unskipBuildList(this->builtFirstStoragePit,
                                                       this->builtFirstGranary);
                    this->lastBuildTime = this->md->player->world->world_time;
                }

                currentTime = debug_timeGetTime((char*)0x5880C0, 0xB92);
                this->md->player->world->useComputerPlayerUpdateTime(
                    currentTime - startTime);

                this->lastUpdateAreaTimeValue =
                    currentTime - updateAreaStartTime;
                this->updateAreaAverageTotal += this->lastUpdateAreaTimeValue;
                this->updateAreaAverageCount++;
                if (this->updateAreaAverageCount >= 20) {
                    this->averageUpdateAreaTimeValue =
                        this->updateAreaAverageTotal /
                        this->updateAreaAverageCount;
                    this->updateAreaAverageTotal = 0;
                    this->updateAreaAverageCount = 0;
                }

                this->updateArea = 0;
                this->md->player->world->selectNextComputerPlayer(3);
                return 1;

            default:
                break;
            }

            currentTime = debug_timeGetTime((char*)0x5880C0, 0xBAA);
            this->lastUpdateAreaTimeValue =
                currentTime - updateAreaStartTime;
            this->updateAreaAverageTotal += this->lastUpdateAreaTimeValue;
            this->updateAreaAverageCount++;
            if (this->updateAreaAverageCount >= 20) {
                this->averageUpdateAreaTimeValue =
                    this->updateAreaAverageTotal / 20;
                this->updateAreaAverageTotal = 0;
                this->updateAreaAverageCount = 0;
            }

            if (incUpdateArea != 0) {
                this->updateArea++;
            }
        } while (currentTime - startTime < availableTime);
    }

    currentTime = debug_timeGetTime((char*)0x5880C0, 0xBC9);
    this->md->player->world->useComputerPlayerUpdateTime(currentTime - startTime);
    return 1;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F0BC0_clearArea.cpp
// ---------------------------------------------------------------------------
// VA: 004F0BC0 TribeTacticalAIModule::clearArea (397 B)
// PDB source: taitacmd.cpp:3031-3093
// __thiscall, int clearArea(int, float, float, float, float)
//
// Attempt log:
// - Replaced the old raw helper scaffold with the period-typed object,
//   tactical-module, and passableTile surfaces. The binary selects the best
//   passable point around the four supplied area corners, then calls moveUnit.
// - Reordered the point and distance declarations to reproduce the original
//   stack homes; frame and call structure then aligned.
// - Reversed corner assignment order as a control-flow probe; it worsened the
//   switch and FPU layout, so it was restored.
// - Ordered switch arms by the original emitted block order. This produced an
//   exact match with the default VC5 flags.


int TribeTacticalAIModule::clearArea(int object_id, float x1, float y1,
                                     float x2, float y2)
{
    if (this->busyWithAction(object_id, -1) == 1) {
        RGE_Static_Object* object = this->md->object(object_id);
        if (object != 0) {
            float newX = -1.0f;
            float newY = -1.0f;
            float bestDistance = -1.0f;
            float tempX = -1.0f;
            float tempY = -1.0f;

            for (int i = 0; i < 8; i++) {
                switch (i) {
                case 0:
                    tempX = x1 - 2.0f;
                    tempY = y1 - 2.0f;
                    break;
                case 2:
                    tempX = x2 + 2.0f;
                    break;
                case 4:
                    tempY = y2 + 2.0f;
                    break;
                case 1:
                case 5:
                    tempX = (x2 + x1) * 0.5f;
                    break;
                case 6:
                    tempX = x1 - 2.0f;
                    break;
                case 3:
                case 7:
                    tempY = (y2 + y1) * 0.5f;
                    break;
                }

                if (object->passableTile(tempX, tempY, 1) != 0) {
                    float distance = object->distance_to_position(
                        tempX, tempY, object->world_z);
                    if (bestDistance == -1.0f || distance < bestDistance) {
                        bestDistance = distance;
                        newX = tempX;
                        newY = tempY;
                    }
                }
            }

            if (bestDistance != -1.0f) {
                this->moveUnit(object_id, newX, newY, 100);
                return 1;
            }
        }
    }
    return 0;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F0D70_addObject.cpp
// ---------------------------------------------------------------------------
// 004F0D70 TribeTacticalAIModule::addObject
// PDB: taitacmd.cpp lines 3098-3167
//
// Attempt log:
// - Earlier source used an add_unique_scan helper and wrong list offsets.
//   It collapsed the four inline scan blocks and produced a 500-byte body.
// - The binary uses one shared resize/append tail for civilians and soldiers.
//   Boat and subtype lists use separate inline bodies.
// - Fresh typed reconstruction: model the ten ManagedArray fields at their
//   proven offsets and use the declaration-only period array methods.
// - Baseline direct scans with do/while loops rebuilt 879 bytes and aligned
//   all 11 calls.  Matching the same-TU for-loop donor reduced this to 839.
// - Loading each subtype list before contains reduced the body to 825 bytes.
//   The player/world correction then reduced it to 822 bytes and aligned the
//   difficulty chain at md->player->world (+0x3c).
// - A split scan-ID/contains-ID local reduced size to 801 but worsened byte
//   alignment.  It was restored.  Current source is the 822-byte candidate:
//   all calls and list offsets align, but register ownership and several
//   subtype blocks still differ.
// - Session shardA4: direct `this`/parameter use, declaration reordering, and
//   the donor-backed TacticalAIModule virtual base were natural ABI probes;
//   each was a codegen duplicate.
// - The original has a dedicated boat-chain return before the shared
//   civilian/soldier append.  Added that return and the fishing early-return
//   form; returns became 3/3 and exact-block coverage improved to 60.66%, but
//   the 822-byte body and first prologue mismatch remained.
// - A preincrement resize capacity form was also a codegen duplicate and was
//   restored to the clearer `number + 1` spelling.
// - Same-TU AIModule base spelling and a full base gap were codegen duplicates
//   at 822 bytes; the structural prologue and four ID spill gaps were unchanged.
// - Restoring the binary-supported persistent object alias in the current
//   virtual-base context was also a duplicate.  A register-ID diagnostic was
//   unchanged, so the clean typed candidate remains authoritative.
// - Revisit session: the clean 822-byte source rebuilt with 11/11 ordered
//   calls, no frame, 570 strict diff bytes, and 60.66% exact-block coverage.
// - Tested persistent object aliases, parameter-home mutation, the Ghidra
//   local topology, a typed parameter-home reference, delayed initialization,
//   register-qualified parameter/ID locals, a flat class prefix, local-order
//   changes, and combined scan predicates.  These were duplicates or worse.
// - Tested non-register object and receiver aliases, direct member scans,
//   stdlib/string/windows headers, their combination, and a receiver reference.
//   Each emitted the same 822-byte candidate.
// - Branch-local subtype IDs changed the basin to 777 bytes and 747 strict
//   diff bytes, but lost structural alignment and was restored.
// - The remaining mismatch is register ownership: the original keeps the
//   parameter in EBX, this in EBP, and the repeated ID in EDI.  The clean
//   source keeps the same behavior and calls but assigns another register
//   basin, spilling the ID after three resize calls.
// - ManagedArray recovery replaced the four caller-side scan/append copies
//   with direct calls to the exact add body. This recovered the original
//   parameter, receiver, and ID registers and all inline blocks.
// - The artifact add at line 3165 remains out of line in the executable, while
//   all four later add sites inline. A narrow inline-depth limit preserves this
//   proved same-TU split. Without it, VC5 inlines the artifact add and emits an
//   extra resize call. Restoring the depth immediately gives an exact match.
// - Exact-finish reduction removed four redundant returns and flattened the
//   soldier else-if. Both reductions remained exact.
// - The shared template surface initially inlined three contains calls and
//   moved the function into an 816-byte register basin. The executable keeps
//   all three calls out of line. One narrow inline-depth region restores the
//   exact isolated and grouped output without changing nearby exact owners.


void TribeTacticalAIModule::addObject(RGE_Static_Object* obj)
{
    short group = obj->master_obj->object_group;
    int id;
    int number;
    int i;
    ManagedArray<int>* list;

    if (group == 4) {
        this->civilians.add(obj->id);
    } else if (group == 0 || group == 0x18 || group == 6 || group == 0x19 ||
               group == 0x1a || group == 0x0c || group == 0x23 ||
               group == 0x17 || group == 0x24 || group == 0x1c ||
               group == 0x12 || group == 0x0d || group == 0x27) {
        this->soldiers.add(obj->id);
    } else {
        if (group != 2 && group != 0x14 && group != 0x16 && group != 0x15) {
            if (obj->master_obj->id != 0x9f)
                return;
            if (this->md->player->world->difficultyLevel() >= 4)
                return;
            // BINARY NOTE: This call stays out of line. Later add calls inline.
            this->artifacts.add(obj->id);
            return;
        }

        this->boats.add(obj->id);
        if (obj->master_obj->object_group == 2) {
            this->tradeBoats.add(obj->id);
        }

        if (obj->master_obj->object_group == 0x14) {
            id = obj->id;
            list = &this->transportBoats;
            // BINARY NOTE: These contains and resize sites stay out of line.
            if (list->contains(id) != 1) {
                number = list->numberValue;
                if (number > list->maximumSizeValue - 1)
                    list->resize(number + 1);
                list->value[list->numberValue] = id;
                list->numberValue++;
            }
        }

        if (obj->master_obj->object_group == 0x16) {
            id = obj->id;
            list = &this->warBoats;
            if (list->contains(id) != 1) {
                number = list->numberValue;
                if (number > list->maximumSizeValue - 1)
                    list->resize(number + 1);
                list->value[list->numberValue] = id;
                list->numberValue++;
            }
        }

        if (obj->master_obj->object_group == 0x15) {
            id = obj->id;
            list = &this->fishingBoats;
            if (list->contains(id) == 1)
                return;
            number = list->numberValue;
            if (number > list->maximumSizeValue - 1)
                list->resize(number + 1);
            list->value[list->numberValue] = id;
            list->numberValue++;
        }
    }
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F1090_removeObject.cpp
// ---------------------------------------------------------------------------
// VA: 004F1090 TribeTacticalAIModule::removeObject
// PDB: taitacmd.cpp:3172-3197
//
// Attempt log:
// - Replaced the former one-array/helper scaffold with the binary-backed
//   tactical list ownership and the natural repeated scan/compact source.
// - Baseline rebuilt 827 bytes with two extra removeFromGroup calls; the
//   canonical fields/call family were right but the helper scaffold was not.
// - Deferred index initialization until after removeFromTaskLists and routed
//   the normal paths through one group-removal tail; this reduced the build to
//   792 bytes and one extra call.
// - Reset the scan index before each list and let boat removal continue into
//   the war-boat scan; size and all ten ordered call sites then matched.
// - Mirrored the exact ManagedArray donor's bounded for scans and
//   value[i]=value[i+1] compaction.  The best source-shaped basin is 768 bytes
//   (original 765), with 607 strict diff bytes and 216 edit/resync bytes.
// - Positive count guards plus reversed i/capacity comparison improved the
//   structural alignment; a do/while variant was worse and was rolled back.
// - An ordinary zero local, register-qualified zero, per-loop pointer aliases,
//   and a narrow volatile member-pointer reload were codegen duplicates.  The
//   remaining gap is the original EBX zero/prologue allocation and associated
//   block placement; calls, frame, boundary, and size are otherwise aligned.
// - Removing the outer count guards reduced the CFG count but regressed to 744
//   bytes and 730 diff bytes; rolled back.  Reset do/while scans reached the
//   exact 765-byte size and saved EBX, but used EBX for the count and regressed
//   to 659 diff bytes and 67.74% shape; rolled back.
// - Zero locals derived from objectId or the scan index, and explicit stage-skip
//   gotos, all emitted the clean candidate unchanged; no new structural lead.
// - Tested natural inline ManagedArray contains/remove calls with early
//   returns.  EBX and several structural blocks aligned, but size fell to 632
//   bytes and one removeFromGroup call site disappeared; restored.
// - Tested natural inline contains iteration for the first three list gates.
//   The compiler inlined auxiliary contains calls too, losing four call sites
//   and growing to 804 bytes; restored the clean candidate.
// - Reconstructed the decompiler's shared count/pointer scan topology.  It
//   recovered the saved-EBX prologue but grew to 839 bytes, with a broad CFG
//   shift; restored the clean candidate.
// - Corrected the boat-removal continuation into the war-boat scan.  This
//   restored the ten-call sequence, but the shared scan source remained far
//   outside the clean structural basin; restored.
// - Tried a no-reinitialization scan-index form and a first-scan do-while
//   form.  They improved some block counts, but moved strict diff to 710 and
//   682 bytes; restored the 607-byte clean source.
// - Renewed pass: 21 distinct source, liveness, control-flow, and context
//   probes reproduced the 768-byte source-shaped basin or regressed it.  The
//   best clean result remains 607 strict diff bytes with all ten ordered calls,
//   the frameless boundary, and the correct owning symbol.  The unresolved
//   blocker is the original saved-EBX zero/register basin and block layout.
// - ManagedArray recovery restored the exact contains and remove bodies and
//   replaced the caller-side scans with direct API calls. This recovered the
//   original saved EBX, all ten calls, and every block.
// - VC5 inlines the first three remove calls. The original TU also inlines the
//   fourth war-boat call, but the isolated TU exhausts its inline budget there.
//   The retained war-boat block is the exact remove donor body. A direct call
//   adds one call and removes 92 bytes, so it cannot model the executable.
// - The original control flow checks war, fishing, trade, and transport only
//   after a successful boat removal. If the boat scan fails, it checks only
//   artifacts. This source preserves that shipped list ownership.
// - Exact-finish removal of temporary inline-depth pragmas remained exact.
// - Fresh exact-finish audit: replacing the fourth war-boat inline remove body
//   with a natural remove call produced 673 bytes, 11 calls, and 397 strict
//   diff bytes. Restoring the body rebuilt the 765-byte exact result in the
//   authentic taitacmd.cpp translation unit.


void TribeTacticalAIModule::removeObject(int objectId)
{
    this->removeFromTaskLists(objectId);

    if (this->civilians.contains(objectId)) {
        this->civilians.remove(objectId);
    } else if (this->soldiers.contains(objectId)) {
        this->soldiers.remove(objectId);
    } else {
        if (this->boats.contains(objectId)) {
            this->boats.remove(objectId);

            if (this->warBoats.contains(objectId)) {
                // BINARY NOTE: Exact remove body at the fourth inline site.
                int removeIndex = 0;
                int maximum = this->warBoats.maximumSizeValue;
                for (; removeIndex < maximum; removeIndex++) {
                    if (this->warBoats.value[removeIndex] == objectId)
                        break;
                }
                if (removeIndex < maximum) {
                    maximum--;
                    if (removeIndex < maximum) {
                        do {
                            this->warBoats.value[removeIndex] =
                                this->warBoats.value[removeIndex + 1];
                            removeIndex++;
                        } while (removeIndex <
                                 this->warBoats.maximumSizeValue - 1);
                    }
                    this->warBoats.numberValue--;
                    if (this->warBoats.numberValue < 0)
                        this->warBoats.numberValue = 0;
                }
                this->removeFromGroup(objectId);
                return;
            }
            if (this->fishingBoats.contains(objectId))
                this->fishingBoats.remove(objectId);
            else if (this->tradeBoats.contains(objectId))
                this->tradeBoats.remove(objectId);
            else if (this->transportBoats.contains(objectId))
                this->transportBoats.remove(objectId);
        } else {
            if (this->artifacts.contains(objectId))
                this->artifacts.remove(objectId);
        }
    }

    this->removeFromGroup(objectId);
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F13F0_evaluateCivilianDistribution.cpp
// ---------------------------------------------------------------------------
// 004F13F0 TribeTacticalAIModule::evaluateCivilianDistribution()
// Source: taitacmd.cpp lines 3202-3308
// Attempt log:
// - Reconstructed ManagedArray<int> as the proven four-int, 0x10-byte type and modeled the owning
//   TribeTacticalAIModule fields through zoomingToNextAge. This fixed the +0xFA4 field and gave the
//   natural typed baseline 530 bytes, with the original call order but duplicated final calls.
// - Kept the visible-map chain, shared ManagedArray pointer local, ceil expression, and zero local;
//   these reproduce the original prologue and main path through the low-count tail.
// - An early-return small-count spelling and a direct one-civilian explorer assignment were tested
//   and rolled back. The former was broad; the latter improved block coverage but kept duplicated calls.
// - Modeled the low-count result as desired=1, a gatherer cap, and one final explorer assignment.
//   This removed the extra display/update calls and recovered all 13 ordered calls, 3 jumps, 2 returns,
//   and 90.97% exact-block coverage. Best current output is 509 effective bytes versus 514, 73 strict
//   differing bytes, with the remaining drift localized to the low-count register and shared-tail shape.
// - A goto-based shared-tail spelling added a stack slot and caused broad drift, so it was rolled back.
//   Reloading gatherers, reversing the sn5 comparison, and naming the sn5 limit produced duplicate codegen.
// - A focused direct explorer-result assignment with a live one-count predicate added two final-call
//   sites and widened the function by 25 bytes, so it was rolled back.
// - A typed low-count field-order spelling assigned explorer and gatherer results in separate arms;
//   it reproduced that earlier 539-byte basin with two extra calls and was rolled back.
// - An initialized shared-tail result restored exact size, CFG, and call parity, but strict drift was
//   75 bytes versus the clean 73-byte source; reordering the sn5 read was codegen-duplicate, so rolled back.
// - A direct low-count field-order rewrite added a second civilian-count test and widened the function
//   to 530 bytes; it was rolled back because the first structural hunk moved to the setup call.
// - A natural typed field assignment in each low-count arm reproduced the 539-byte, two-extra-call
//   basin; it was rolled back because it split the shared call tail.
// - Tried the PDB-shaped low-count order: store explorers before the sn[3] gate and use a common
//   cap tail. This restored 514-byte size and 144 instructions, but VC5 hoisted the sn[3] load
//   before the explorer store and left 75 differing bytes; rolled back.
// - Left in scratch: current source is the best natural typed reconstruction. No inline asm or custom flags.
// - Rechecked this target from the original 514-byte body. Natural low-count field-store variants either
//   duplicated the two final calls or moved the outer tail; the min-style cap and declaration-order probes
//   were codegen duplicates or worse. Restored the pinned source: 509 bytes, 13 ordered calls, 90.97% exact
//   block coverage, and 73 differing bytes. The first structural drift remains at rebuilt +0x178 (004F1568),
//   where VC5 keeps the low-count cap in a different register/lifetime shape. No policy-invalid steering kept.
// - ManagedArray recovery pass, 2026-08-19: both manual element-zero grow/read
//   sequences now use the exact operator[] body. The emitted bytes are equal,
//   but method ownership is canonical and resize remains out of line.
// - Restored the binary-supported low-count local reuse from the decompiler:
//   one result holds 1, sn[5], then sn[3], and the computed explorer demand is
//   stored before its cap. This gives exact 514-byte size, 144 instructions,
//   13 calls, and CFG. The remaining 75 bytes are one localized register map.
// - Exact addObject and removeObject predecessor contexts did not change this
//   target. Register hints, branch-local result scopes, references, and store
//   sequencing were duplicates or worse. No compiler-context shim is retained.
// - Worker audit, 2026-08-22: Ghidra confirms a low-count civilian-count local
//   and one reused result local. Pre-branch count reuse, result-local reuse,
//   branch-local cap declarations, direct member rereads, assignment order,
//   and comma sequencing all emitted the same 514-byte, 75-byte-diff basin.
//   Restore the pinned source. The first unproved register divergence remains
//   the sn[5] load and later civilian-count reload at +0x178.
// - Accepted-drift audit: do not promote. In the low-count path, the executable
//   reloads civilians.numberValue after it updates desiredNumberGatherers. The
//   rebuild reuses the earlier count read. Concurrent count changes can produce
//   a different civilianExplorers result and different later stores.
// - Fresh contextual pass restored the exact same-TU TacticalAIModule virtual
//   inheritance. The emitted body is unchanged. The decompiler-shaped local
//   reuse, stored-field cap comparison, and inline numberCivilians accessor are
//   also codegen duplicates. The observable count-reread blocker remained.
// - Exact finish: use the canonical ManagedArray number and setDesiredNumber
//   inline methods at the low-count publication boundary. This preserves the
//   executable's civilian-count reread and keeps the explorer-demand store
//   before the sn[3] load. Direct field access loses one or both properties.

extern "C" double __cdecl ceil(double);


void TribeTacticalAIModule::evaluateCivilianDistribution()
{
    int percentExplored;
    int numberItems;
    int desired;
    int gatherers;
    ManagedArray<int>* list;
    int zero;

    percentExplored = (int)(this->md->player->visible->percentExplored() * 100.0f);

    list = &this->playersToAttack;
    if (list->maximumSizeValue - 1 < 0)
        list->resize(1);
    numberItems = this->md->informationAI.numberGameIDsOwnedBy(-1,
                                                               list->value[0]);

    if (this->civilians.numberValue >= 3) {
    list = &this->civilians;
    if (list->maximumSizeValue - 1 < 0)
        list->resize(1);
    if (this->md->informationAI.fullyExploredZone(list->value[0]) == 1) {
        zero = 0;
        this->civilianExplorers.desiredNumberValue = (int)ceil((float)((double)this->sn[0] * this->civilians.numberValue) * 0.01f);
        desired = this->numberSoldierExplorers();
        if (desired + this->civilianExplorers.desiredNumberValue > this->sn[18]) {
            this->civilianExplorers.desiredNumberValue = this->sn[18] - desired;
        }
        if (this->sn[3] != -1 && this->civilianExplorers.desiredNumberValue > this->sn[3]) {
            this->civilianExplorers.desiredNumberValue = this->sn[3];
        }
    }
    else {
        zero = 0;
        this->civilianExplorers.desiredNumberValue = zero;
    }

    if (percentExplored >= this->sn[32] && numberItems > this->sn[145]) {
        desired = this->sn[35];
        if (this->civilianExplorers.desiredNumberValue > desired) {
            this->civilianExplorers.desiredNumberValue = desired;
        }
    }
    else if (percentExplored >= this->sn[179]) {
        desired = this->civilianExplorers.desiredNumberValue / 2;
        if (desired <= zero) {
            desired = zero;
        }
        this->civilianExplorers.desiredNumberValue = desired;
    }

    if (this->zoomingToNextAge == 1) {
        this->civilianExplorers.desiredNumberValue = zero;
    }

    gatherers = this->civilians.numberValue - this->civilianExplorers.desiredNumberValue;
    this->desiredNumberGatherersValue = gatherers;
    if (this->sn[5] != -1 && gatherers > this->sn[5]) {
        this->desiredNumberGatherersValue = this->sn[5];
    }
    }
    else {
        desired = 1;
        if (this->civilians.numberValue == 1) {
            this->desiredNumberGatherersValue = 0;
        }
        else {
            desired = this->sn[5];
            this->desiredNumberGatherersValue = 1;
            if (desired != -1 && desired < 1) {
                this->desiredNumberGatherersValue = desired;
            }
            // BINARY NOTE: Reread the count before publishing explorer demand.
            gatherers = this->civilians.number() -
                        this->desiredNumberGatherersValue;
            this->civilianExplorers.setDesiredNumber(gatherers);
            desired = this->sn[3];
            if (desired == -1 || gatherers <= desired)
                goto low_count_done;
        }
        this->civilianExplorers.desiredNumberValue = desired;
low_count_done:
        ;
    }

    this->displayCivilianDistribution();
    this->updateGathererDistribution();
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F1600_taskCivilians.cpp
// ---------------------------------------------------------------------------
// VA: 004F1600 TribeTacticalAIModule::taskCivilians(unsigned long, unsigned long)
// PDB source: taitacmd.cpp lines 3313-3548
// __thiscall, int, ret 8
//
// Attempt log (dsb2-004F1600, 30 meaningful probes across sessions):
// - Fresh canonical reset: prior rejected source manually expanded five
//   ManagedArray grow blocks. This reconstruction uses the natural typed
//   ManagedArray<int> surface (inline operator[] grow, remove, out-of-line
//   resize) and the plain source-level algorithm: new-explorer creation,
//   gatherer->explorer conversion by needed-resource priority, excess-
//   explorer removal, gatherer creation, and the refresh loop that tasks
//   civilians one per tick (return j = count tasked).
// - probe 5 baseline: typed operator[]/remove/resize surface; first-mismatch
//   at +9 (< 1 guard); frame 0x14 achieved after probe 6.
// - probe 6: `<= 0` guard (test/jg encoding) + declaration-only resize so
//   VC5 emits real ManagedArray<int>::resize calls (call set then fully
//   aligned; target-count gap 0).
// - probe 7/9/10: resource-conversion loop shapes. The two object() calls
//   inside it pass the `tasked` variable (register pushes, not -1 literals);
//   the loop is `do { if (tasked != -1) goto append; ... } while (newExplorer
//   > -1)` under an early-exit check. VC5 still rotates the loop-top tasked
//   check to the loop bottom (proves tasked == -1 at the head) so the
//   original's separate B010 top-check block is not reproduced.
// - probe 8: operator[] copy loop as combined `&&` bound (max && index+1) per
//   004DC1B0 lesson; grow copy loops now match the original shape exactly.
// - probe 11: task_done dispatch written as `if (highLevelTaskGatherer(...)
//   == 0) { addGatherer path }` keeps the addGatherer path inline and
//   task_done as the skip target (original's jne layout); call sites 100%
//   aligned.
// - probe 12: operator[] grow uses a named `new_size = index + 1` local;
//   grow blocks byte-match the original (shape 84%).
// - probes 13-14 (explicit grow expansion using taskedCount/newExplorer and
//   indexing civilians[taskedCount-1]): both regressed; VC5 emits extra
//   frames/arith instead of the original's induction-locals codegen. Reverted.
// - probes 19-24: a scoped civilian pointer/reference or value before the
//   explorer scan exposed the refresh-loop operator[] grow at the original
//   top block and restored the 0x14 frame. The value form is the cleanest
//   source reconstruction (1563B diff, 90.50% shape); pointer/reference
//   forms added an unnecessary address alias. Split taskedCount initialization
//   was emitted identically to `i + 1`.
// - Worker session sa-9f7395fa-r1 ran 20 meaningful probes. The baseline was
//   1563B strict diff and 90.50% shape. Comma and reverse coordinate forms,
//   separate coordinate locals, local declaration order, direct member-call
//   arguments, and combined refresh IV expressions were duplicate or worse.
// - A top-tested resource loop plus a scoped civilianExplorers reference
//   restored the original redundant tasked check and improved the clean source
//   to 1260B diff, 96.59% shape, and 86.70% exact-block coverage. Explicit
//   excess-removal labels gave 1150B strict diff but poor resynchronization and
//   were rejected as a non-natural metric-only form. Timeout operand reversal
//   improved compare parity without changing size or strict diff.
// - The final unresolved candidate is 2083B versus 2062B, 39/39 ordered calls,
//   frame 0x14, and first mismatch +003C in coordinate/FPU scheduling. The
//   remaining evidence points to VC5 scheduling and refresh register homes.
// - Canonical ownership: md +0xF0, civilians +0xF4 (ManagedArray<int>),
//   civilianExplorers +0x104 (ManagedArray<int>), numberGatherersValue +0x9CC,
//   desiredNumberGatherersValue +0x9D0, neededResourceValue[4] +0xD88,
//   nextCivilianToTaskValue +0xF7C. taskCivilians returns j, the number of
//   civilians tasked this tick.
// - Call set (39): object x5, __ftol x6, idleCivilian x4, removeGatherer,
//   resize x2, operator_new/delete (inline grows), stopUnit, addGatherer x2,
//   highLevelTaskGatherer, highLevelTaskExplorer, updateGathererDistribution,
//   debug_timeGetTime x2.
// - ManagedArray audit: the local template remains the canonical utmarray.h
//   inline operator[]/remove surface, matching exact 004EA750/004F1390 donors;
//   resize stays declaration-only for the real 004147A0 out-of-line call.
// - Main-agent audit removed an impossible `tasked != -1` check nested directly
//   under `tasked == -1`; it was non-emitting experiment residue. Codegen and
//   all metrics remained unchanged.
// - ManagedArray recovery pass, 2026-08-19: the exact add body replaces the
//   caller-side explorer scan and append. Duplicate failure still exits through
//   skip_append. This is codegen-identical to the 2083-byte frontier and gives
//   the scan to its canonical method owner; resize remains declaration-only.
// - Shared-context pass: restore the nested inline operator[] allocation body.
//   The grouped function then equaled all 2083 standalone bytes. The prior
//   declaration-only shared resize surface had collapsed it to 1312 bytes.
// - Contextual matching pass: retain a civilian-array owner across the setup
//   resize and publication, compare the requested ID against civilians[i],
//   and let operator[] own the timed-return capacity guard. The grouped and
//   standalone bodies now equal 2064 bytes, with exact frame, calls, and CFG.
//   The remaining 914-byte drift starts in coordinate-store scheduling. A
//   two-byte induction-value register move remains after the refresh search.
//   Adding exact 004F4760 after the excluded 004F21F0 did not change this body.
// - Exact-finish pass: two branch-local aggregate XYPoint initializers match
//   both observed x87 conversion/store orders and improve the drift to 900
//   bytes. PDB symbols list two tcPosition locals at the same stack home.
//   ID lifetime and argument-order variants were duplicate or worse.
//   The shared context still declares removeGatherer as void, while the exact
//   donor and PDB ABI prove int. Shared helper edits are outside this task.
// - Final pin was blocked by a concurrent config/translation_units.json edit:
//   the loader rejects 00543E00 as an owner of world_scenario_sparse. No shared
//   config or helper file was changed by this pass.
// - Child exact-finish pass, 2026-08-23: fresh grouped baseline was 2064 bytes,
//   914 differing bytes, and 39/39 ordered calls. During the pass, the shared
//   taitacmd header changed ManagedArray::resize from declaration-only to an
//   inline body. That changed this owner to 2236 bytes with 10 new/delete calls
//   and removed both resize calls. It also changed 004F13F0 to 679 bytes.
//   The target source was restored; no context bridge was retained.


extern "C" {
    void* __cdecl operator_new(unsigned int size);
    void __cdecl operator_delete(void* block);
}


extern unsigned long debug_timeGetTime(const char* file, int line);

int TribeTacticalAIModule::taskCivilians(unsigned long param_1, unsigned long param_2) {
    int newExplorer;
    int taskedCount;
    int j;
    int i;
    int k;
    int tasked;
    RGE_Static_Object* obj;
    int civilian;

    if (this->civilians.numberValue <= 0) {
        this->nextCivilianToTaskValue = -1;
        return 0;
    }

    j = 0;
    if (this->nextCivilianToTaskValue == -1) {
        // Create new civilian explorers up to the desired number.
        if (this->civilianExplorers.numberValue < this->civilianExplorers.desiredNumberValue) {
            do {
                obj = this->md->object(-1, 0x6D, -1, -1, -1, -1, -1, -1, -1, -1);
                if (obj != 0) {
                    XYPoint tcPosition = {
                        (int)obj->world_x, (int)obj->world_y
                    };
                    tasked = this->idleCivilian(-1, tcPosition, 0);
                } else {
                    tasked = this->idleCivilian(-1);
                }
                taskedCount = tasked;
                if (tasked != -1) goto append_explorer;
                // Too many gatherers: convert the one carrying the highest-priority
                // needed resource into an explorer instead.
                if (this->desiredNumberGatherersValue < this->numberGatherersValue) {
                    newExplorer = 3;
                    while (newExplorer > -1) {
                        if (tasked != -1) goto append_explorer;
                            obj = this->md->object(tasked, tasked, tasked, 0x261, 0x25D,
                                                   tasked, tasked,
                                                   this->neededResourceValue[newExplorer],
                                                   tasked, 0);
                            if (obj == 0) {
                                obj = this->md->object(tasked, tasked, tasked, 0x265, 0x25D,
                                                       tasked, tasked,
                                                       this->neededResourceValue[newExplorer],
                                                       tasked, 0);
                            }
                            if (obj != 0 && obj->attribute_amount_held == 0.0f) {
                                int id = obj->id;
                                for (i = 0; i < this->civilianExplorers.numberValue &&
                                             i < this->civilianExplorers.maximumSizeValue; i++) {
                                    if (this->civilianExplorers.value[i] == id) goto next_resource;
                                }
                                tasked = id;
                                taskedCount = id;
                                this->removeGatherer(id);
                            }
next_resource:
                        newExplorer = newExplorer - 1;
                    }
                }
                if (tasked == -1) goto skip_append;
append_explorer:
                if (this->civilianExplorers.add(tasked) == 0)
                    goto skip_append;
            } while (this->civilianExplorers.numberValue <
                     this->civilianExplorers.desiredNumberValue);
        }
skip_append:
        // Remove excess explorers (the oldest first).
        if (this->civilianExplorers.numberValue > this->civilianExplorers.desiredNumberValue) {
            int id;
            if (this->civilianExplorers.numberValue <= 0)
                goto excess_explorers_done;
remove_excess_explorer:
            id = this->civilianExplorers[0];
            this->civilianExplorers.remove(id);
            this->stopUnit(id, 100);
            if (this->civilianExplorers.numberValue >
                this->civilianExplorers.desiredNumberValue)
                goto remove_excess_explorer;
        }
excess_explorers_done:
        // Create gatherers up to the desired number.
        if (this->numberGatherersValue < this->desiredNumberGatherersValue) {
            do {
                obj = this->md->object(-1, 0x6D, -1, -1, -1, -1, -1, -1, -1, -1);
                if (obj != 0) {
                    XYPoint tcPosition = {
                        (int)obj->world_x, (int)obj->world_y
                    };
                    tasked = this->idleCivilian(-1, tcPosition, 0);
                } else {
                    tasked = this->idleCivilian(-1);
                }
            } while (tasked != -1 && this->addGatherer(tasked) != 0 &&
                     this->numberGatherersValue < this->desiredNumberGatherersValue);
        }
        ManagedArray<int>* civilianList = &this->civilians;
        if (civilianList->maximumSizeValue - 1 < 0) {
            civilianList->resize(1);
        }
        this->nextCivilianToTaskValue = civilianList->value[0];
        if (debug_timeGetTime((const char*)0x005880C0, 0x0D8A) - param_1 >= param_2) {
            return 0;
        }
    }

    // Refresh phase: find the civilian to task this tick and task the rest.
    for (i = 0; i < this->civilians.numberValue; i++) {
        if (this->nextCivilianToTaskValue == this->civilians[i]) break;
    }
    if (i >= this->civilians.numberValue) goto no_more;

    taskedCount = i + 1;
    newExplorer = taskedCount * 4;
    do {
        j = j + 1;
        civilian = this->civilians[i];
        // Already an explorer?
        for (k = 0; k < this->civilianExplorers.numberValue &&
                     k < this->civilianExplorers.maximumSizeValue; k++) {
            if (this->civilianExplorers.value[k] == civilian) goto is_explorer;
        }
        if (this->highLevelTaskGatherer(this->civilians[i], param_1) == 0) {
            this->addGatherer(this->civilians[i]);
            i = i + 1;
            taskedCount = taskedCount + 1;
            newExplorer = newExplorer + 4;
            goto loop_cond;
        }
task_done:
        this->updateGathererDistribution();
        i = i + 1;
        taskedCount = taskedCount + 1;
        newExplorer = newExplorer + 4;
        if (i >= this->civilians.numberValue) goto no_more;
        this->nextCivilianToTaskValue = this->civilians[i];
        if (debug_timeGetTime((const char*)0x005880C0, 0x0DC6) - param_1 >= param_2) {
            if (i > 0) {
                // Binary-proven capacity touch: ensure room for civilians[i-1]
                // before returning, matching the inline operator[] grow.
                this->civilians[i - 1];
            }
            goto done;
        }
loop_cond:
        ;
    } while (i < this->civilians.numberValue);
    goto no_more;

no_more:
    this->nextCivilianToTaskValue = -1;
done:
    return j;

is_explorer:
    this->highLevelTaskExplorer(this->civilians[i], 1);
    goto task_done;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F1E10_taskIdleSoldiers.cpp
// ---------------------------------------------------------------------------
// 004F1E10 TribeTacticalAIModule::taskIdleSoldiers
// taitacmd.cpp
// Attempt log:
// try 1-11: prior broad scaffold used placeholder canUse/object/command
// helpers and was 704 bytes; it was structurally short and did not preserve
// the original direct-call set.
// probe 12: restored the binary-backed TacticalAIGroup, MainDecisionAI,
// information/strategy subobjects, object/zone APIs, and the nested
// skip-invalid-group loop from the same-TU decompiler control flow.  This is
// the clean typed reconstruction to check before any codegen-only probes.
// probe 13: proper direct method names/layout reached exact size, 0x10 frame,
// 47/47 conditional CFG, and 51 calls; the first broad result was 777 bytes
// different.  The remaining call topology is concentrated in the action
// selection tail (rebuilt 4 setAction/16 type versus original 1 setAction/19
// type), while the task call is in a relocated cold block.
// probe 14: moved the invalid-group advance to an out-of-line source label
// and shared the loop-test; rebuilt remained exact-size/frame and improved to
// 756 differing bytes with 73.77% exact-block coverage.  Direct-sentinel and
// positive-predicate variants were codegen duplicates.
// probe 15: structured/common setAction-tail and action-result liveness
// variants were codegen duplicates or larger; rolled back to the cleanest
// typed form.  No inline asm, fake imports, or custom flags retained.
// left in scratch: exact matching is paused at the 10-hypothesis budget.  The
// best rebuilt code is 989 bytes, 0x10 frame, 51 calls, 85.08% shape, 756
// strict differing bytes (76.4408%), and 63.50% bounded edit similarity.
// - Named the debug source file. The previous literal address was not valid
//   source ownership.
// probe 24: reordered the ready/task arms to follow the original PDB line
// order, with task before action selection. This moved task into the original
// inline block and improved shape, calls, and exact blocks, but removed three
// type calls, shortened the function by 34 bytes, and worsened strict diff;
// restored the clean source.
//
// Current pass probes 1-20: a top-level do-loop with invalid-group continue,
// delayed isGathered initialization, the int currentZone() & 0xff form, the
// inverted zone test, and the explicit fully-explored failure edge are all
// supported by closer code. The best clean checkpoint is 1008 bytes, 0x10
// frame, 51 calls, 90.97% shape, 274 differing bytes, and 81.35% bounded
// similarity. The action tail remains unresolved: the executable has 19 type
// calls and one shared setAction call, while the clean source emits 16 type
// calls and four setAction calls. Fresh predicates, nested assignments,
// scopes, initializers, and shared-label forms did not reach that call set.
//
// probe 22: restored the PDB-order inactive arm and wrote the action choices
// as direct setAction calls. VC5 merged their common call tail, recovered all
// 19 type calls, and proved that setType(0x69) continues to action 8. This
// reached 35 differing bytes with exact frame, calls, and call order.
// probe 23: replaced the repeated do-loop sentinel guard with the natural
// pretest while loop shown by 004F1E71 and 004F21CD. This removed the final
// redundant branch and reached an exact 989-byte match at 0.0000%.

static const char s_taitacmd_cpp[] =
    "C:\\msdev\\work\\age1_x1\\taitacmd.cpp";


extern unsigned long debug_timeGetTime(const char*, int);

void TribeTacticalAIModule::taskIdleSoldiers(unsigned long startTime,
                                              unsigned long maxTime)
{
    TacticalAIGroup* group = this->groups.next;

    if (this->nextIdleSoldierGroupToTaskValue != -1) {
        while ((group != &this->groups && group != 0) &&
               (group->id() != this->nextIdleSoldierGroupToTaskValue)) {
            group = group->next;
        }
        if (group->id() != this->nextIdleSoldierGroupToTaskValue) {
            group = this->groups.next;
        }
    }

    TacticalAIGroup* end = &this->groups;
    int readyToTask;
    int isGathered;
    int desired;
    int number;
    while (group != end) {
        if (group == 0) {
            this->nextIdleSoldierGroupToTaskValue = -1;
            return;
        }

        if (group->type() == 0x6B || group->type() == 0x6C ||
            group->type() == 0x6A ||
            (group->action() != 0 && group->action() != 1)) {
            group = group->next;
            continue;
        }

        readyToTask = 1;
        if (group->consecutiveGatherAttemptsValue <= 10) {
            isGathered = group->isGathered(this, this->md);
        }
        else {
            isGathered = 1;
        }

        desired = group->desiredNumberUnits();
        number = group->numberUnits();
        if (desired > number) {
            RGE_Static_Object* commanderObj =
                this->md->object(group->commander());
            RGE_Static_Object* targetObj =
                this->md->object(-1, 0x6D, -1, -1, -1, -1, -1, -1, -1,
                                 -1);
            if (commanderObj == 0 || targetObj == 0) {
                readyToTask = 0;
            }
            else {
                int zone = commanderObj->currentZone() & 0xff;
                if (zone != commanderObj->lookupZone(
                               (int)targetObj->world_x,
                               (int)targetObj->world_y)) {
                    group->setDesiredNumberUnits(group->numberUnits());
                }
                else {
                    readyToTask = 0;
                }
            }
        }
        else if (isGathered == 0) {
            readyToTask = 0;
        }
        else if (group->allUnitsIdle(this->md, 1) == 0) {
            readyToTask = 0;
        }
        else {
            if (group->type() == 0x66 || group->type() == 0x69) {
                if (this->md->informationAI.fullyExploredZone(
                        group->commander()) == 0) {
                    readyToTask = 0;
                    goto ready_to_task_check;
                }
            }

            if (group->type() == 0x64 || group->type() == 0x67) {
                if (this->md->strategyAI.currentVictoryCondition() == 0) {
                    if (this->itemToCapture() == -1 &&
                        group->type() == 0x64) {
                        readyToTask = 0;
                    }
                    else {
                        group->setSubType(0);
                    }
                }
                if (this->md->strategyAI.currentVictoryCondition() == 4) {
                    if (this->itemToBringToArea() == -1 &&
                        group->type() == 0x64) {
                        readyToTask = 0;
                    }
                    else {
                        group->setSubType(4);
                    }
                }
            }
            else if ((group->type() == 0x65 || group->type() == 0x68) &&
                     this->numberItemsToDefend() == 0) {
                readyToTask = 0;
            }
        }

ready_to_task_check:
        if (readyToTask == 0) {
            if (isGathered == 0) {
                group->task(this, this->md, 9, 1, 0);
            }
        }
        else {
            if (group->type() == 0x66 || group->type() == 0x69) {
                group->setAction(8);
            }
            else if (group->type() == 0x64 || group->type() == 0x67) {
                if (this->numberItemsToAttack() == 0 &&
                    group->type() == 0x67) {
                    group->setType(0x69);
                    group->setAction(8);
                }
                else {
                    group->setAction(2);
                }
            }
            else if (group->type() == 0x65 || group->type() == 0x68) {
                group->setAction(4);
            }
            else if (group->type() == 0x6D) {
                group->setAction(0x13);
            }
        }

        goto next_group;

next_group:
        group = group->next;
        this->nextIdleSoldierGroupToTaskValue = group->id();
        if (debug_timeGetTime(s_taitacmd_cpp, 0xEA9) - startTime >=
            maxTime) {
            return;
        }
    }

    this->nextIdleSoldierGroupToTaskValue = -1;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F21F0_taskActiveSoldiers.cpp
// ---------------------------------------------------------------------------
// 004F21F0 TribeTacticalAIModule::taskActiveSoldiers(unsigned long,unsigned long)
// PDB: taitacmd.cpp:3769-5404
// First pass: start from the full repo-local Ghidra approximation, kept below as
// the line-by-line porting guide.  The compileable body below intentionally ports
// only the top iterator/action-gate skeleton first; next passes should replace the
// large TODO body with successive Ghidra blocks and watch edit/resync diff.
// Attempt log:
// - seeded full Ghidra decompiler output under #if 0 from inventory/functions/004F/004F21F0_taskActiveSoldiers.txt.
// - built a compileable first skeleton for the opening group-selection/list-walk/action gate.
// - check_function cannot yet diff: current .text is 352 bytes vs original 9580; next step is to port the inactive-group body until the object is large enough for normal diff metrics.
// - mechanical full-Ghidra compile probe showed labels embedded between if/else arms and static-call surfaces need manual cleanup, so keep porting block-by-block rather than bulk-uncommenting.
// - ported first inactive non-attack defend/relic branches (types 0x65/0x68/0x6d) with rough typed helper surfaces; rebuilt .text now 1408 bytes, still below original size for diff extraction.
// - added timeout tail, first attack-opener scaffold (type 100/0x67), and active action-0x0d assist/enter scaffold; rebuilt .text now 2368 bytes, still below original size for diff extraction.
// - ported rough active transport/boarding/action maintenance scaffolds for actions 0xf, 0x10, 7, 2, 4, 0xc/0x13, and 3, plus inactive fallback attack selection/resizing and post-attack influence hooks. Current .text is 7872 bytes, still below original 9580 so check_function cannot yet produce edit/resync metrics.
// - filled enough remaining scaffold detail to reach full extraction length; current check_function is MISMATCH 76.4301% positional / 172.2651% edit, first mismatch offset 12. Frame size now matches 0xD0; next leading issue is early `xor ebp,ebp` and zero-register use before the original first emits it, plus broad approximate-body drift.
// - removed zero initialization of the inactive-branch object locals and forced raw offsets for nextActive/attackState; edit diff improved materially. Current check_function: MISMATCH 76.4823% positional / 153.0167% edit, first mismatch offset 12. Rebuilt still has early `xor ebp,ebp`; keeping frame at 0xD0 currently requires scratch_frame[0x38].
// - corrected local RGE_World layout so world_time is at +4 as observed in original early idle-time loads, restored inactive-branch mem/commander zero initialization to match the Ghidra/original state setup, and reshaped the relic timeout branch to preserve md before consecutiveIdleUnitCount. Current check_function: MISMATCH 76.0647% positional / 162.8497% edit, first mismatch offset 12.
// - temporarily removed the inactive-branch mem/commander zero assignments again because they hoisted an early zero register and broke the opening. With scratch_frame[0x34], the prologue/opening now matches through offset 87; current check_function: MISMATCH 76.0543% positional / 152.7035% edit, first mismatch is sentinel register choice (`lea ebp,[edi+9D4]` vs original `lea ebx,[edi+9D4]`). Need later recover the original delayed `xor ebp; xor ebx` inactive setup without re-hoisting.
// - probed an explicit inUse local/zero-derived mem init: it made the sentinel register match but shrank frame to 0xCC and reintroduced early `xor ebp`, so rolled back. Probed delaying/deriving allOutsideTransport initialization and raw param reloads; no improvement over current opening/edit-diff baseline.
// - ran a small focused local variant sweep over scratch_frame size (0x30/0x34/0x38) and inactive-branch setup spellings (none/zero/after-type/split-decl/volatile-zero). Best retained opening is still scratch_frame[0x34] with no mem/commander zero init: frame 0xD0 and first mismatch 87. Zero-init variants either shrink the frame or hoist `xor ebp`; volatile zero improves positional slightly but breaks the prologue/frame.
// - unified the inactive attack-selection subpaths to use the outer ObjectMemory* (matching Ghidra's single pOVar27-style state) and added local relic-branch zeroing; this improves positional diff but worsens edit diff. Current check_function: MISMATCH 75.8455% positional / 162.5574% edit, first mismatch remains offset 87 sentinel register allocation.
// - promoted local RGE_Master/ObjectList/RGE_Player layout facts from type inventory (master_obj +8, objects +0x0c, los +0x28, obj_max +0x2c, object list count +8, player id +0x4a) and expanded the active transport action 0x0d/0x0f/0x10 scaffolds with transport capacity, idle-entry, staging-point, defender-escort, and owner-id gates from the Ghidra guide. Current check_function: MISMATCH 75.9603% positional / 164.2067% edit, first mismatch offset 87.
// - delayed allOutsideTransport initialization to the attack-selection branch and adjusted scratch_frame to 0x28 to preserve the 0xD0 frame after adding staging locals; expanded active action 0x10 reset path with the relic move fallback from Ghidra. Current check_function: MISMATCH 76.2630% positional / 165.3653% edit, first mismatch offset 87.
// - added the Ghidra-observed non-enemy target reset/gather branch for active action 2/subtype -1 and exposed a local md->isEnemy surface. Current check_function: MISMATCH 76.1378% positional / 162.4322% edit, first mismatch still offset 87.
// - added the action 2 playNumberValue recovery path from the Ghidra LAB_004f436b area: when the commander has unitAI and no playStatus, reset playNumberValue to -1 and clear attackState.active. Current check_function: MISMATCH 76.1065% positional / 167.4530% edit, first mismatch offset 87.
// - corrected the local RGE_Static_Object field layout to match type inventory (owner +0x0C, inside_obj +0x20, objects +0x24, hp +0x30, world coords +0x38/+0x3C/+0x40, object_state +0x48, actions +0x184), switched damaged-unit retreat HP source to hp, and added the action 2 / sn[0x31]==2 reset-task branch. Current check_function: MISMATCH 75.1044% positional / 155.1044% edit, first mismatch offset 12 from early zero-register setup.
// - removed the hoisted inactive mem/commander zero init again and reshaped action 4 closer to Ghidra (allUnitsIdle/isGathered gate, higherPriorityObjectToDefend with master object_group, else task 9). Fixed action 0xc/0x13 cleanup condition to include buildListLength and the type-100 group-count arm. Current check_function: MISMATCH 75.6472% positional / 140.2714% edit, first mismatch back to offset 87.
// - made the action 2 invalid-target sn[0x31]==2 reset/task path skip the replacement-target retask path, matching the Ghidra control-flow split instead of falling through. Current check_function: MISMATCH 75.9916% positional / 148.2255% edit, first mismatch offset 87.
// - probed returning to inactive mem/commander zero-init with current larger body; it now worsens edit/prologue, so rolled back to no early zero-init. Updated the default target higher-priority check to pass targetObj->master_obj->object_group like the Ghidra iVar36 path. Current check_function: MISMATCH 75.9186% positional / 151.4509% edit, first mismatch offset 87.
// - corrected more local layout facts from type inventory: ObjectMemory x/y/z/owner are +8/+9/+A/+B with group at +6; TacticalAIGroup direct playNumberValue/numberObjectsToDestroyValue are +0x1D0/+0x2CC; UnitAIModule::playStatus is +0x12C; TribeMainDecisionAIModule build/info/strategy offsets are +0x104/+0xCEC/+0x10E74; TribeTacticalAIModule sn starts at +0x194. Current check_function: MISMATCH 75.2610% positional / 170.9186% edit, first mismatch offset 87.
// - natural-source probe: local references for attackState.active and nextActiveGroup made the source nicer and preserved first mismatch 87, but worsened edit diff, so rolled back; keep raw offset access until a broader class-surface rewrite is justified.
// - corrected TacticalAIGroup sizeof/local tail to 0x330 and TribeTacticalAIModule gap_after_groups to 0x280, enabling natural this->groups.next, &this->groups, nextActiveSoldierGroupToTaskValue, and attackState_active field access with identical codegen to the raw-offset version. Current check_function: MISMATCH 75.2610% positional / 170.9186% edit, first mismatch offset 87.
// - replaced raw offsets for playersToAttack, lastGroupAttackTime, lastAttackResponseTime, attackEnabledValue, and AttackState with natural fields, including a real AttackState wrapper at +0xFAC and fuller Build/Information module sizes. Codegen stayed stable and edit diff improved from the raw-field surface. Current check_function: MISMATCH 75.2610% positional / 148.7265% edit, first mismatch offset 87.
// - reshaped inactive attack target selection to match the Ghidra/natural ManagedArray flow more closely: resize playersToAttack only when the target lookup path actually needs player[0], then call objectToAttack/objectToAttackByGroup unconditionally after ensuring capacity; also removed null guards in active action 7/replacement retarget paths after ensure. Current check_function: MISMATCH 76.0334% positional / 165.8351% edit, first mismatch offset 87.
// - moved inactive-branch mem/commander/allOutside initialization up to the start of the !inUse arm to mirror original early zero/init stores, then enlarged scratch_frame to keep the original 0xD0 frame. Added missing attackState.active clears on several inactive setAction(1) exits. Current check_function: MISMATCH 76.0543% positional / 159.5720% edit, first mismatch offset 30 (sentinel register allocation ebx/ebp).
// - naturalized the initial null tests from `(unsigned long)cur == 0` to `cur == 0`; codegen unchanged. Probed moving RESET_GROUP's numberObjectsToDestroy store after setTargetType to mimic the late shared reset block, but edit diff worsened, so rolled back.
// - restored the PDB-proven XYZPoint layout (three ints, size 0x0c) and binary-observed RGE_Static_Object virtual surfaces: weaponRange at +0x10c, canPath(XYZPoint,...) at +0x198, canPathWithAdditionalPassability at +0x1a4, and find-first-path-point at +0x1a8. Replaced the approximate direct helper calls across the major pathing branches with natural typed virtual dispatch. Edit/resync diff improved substantially from 159.5720% to 128.9040%, and equal bytes rose from 1693 to 3013.
// - current path-surface baseline: MISMATCH 78.0063% positional / 128.9040% edit. The natural locals now produce a 0xD4 frame (original 0xD0), so first mismatch is frame size at offset 2; one excess 4-byte local/home remains to identify. A full relic fallback port raised the frame to 0xDC and worsened edit diff, so it was rolled back pending shared-stack-local modeling.
// - restored the second influence-path virtual call as findAvoidancePath at vtable +0x1cc, with the proven XYZPoint* / weaponRange / mode arguments, replacing the temporary nonsensical float-to-Path cast. Current check_function: MISMATCH 77.4217% positional / 130.4593% edit, 2949 equal bytes. This correct call surface needs 12 more local bytes in the current block-scoped model (frame 0xE0); hoisting one XYZPoint across the inactive arm over-collapsed the frame to 0xC8 and worsened edit diff, so rolled back.
// - restored the full relic exception-path fallback and the three binary-observed +0x194 canAttack gates; the virtual call surfaces now include +0x10c/+0x194/+0x198/+0x1a4/+0x1a8/+0x1cc and the md enemy test at +0x1c.
// - replaced the incorrect large catch-all idle/unit-retask scaffold with the Ghidra-observed final HP/unit-loss check, and routed terminal task requests through one shared task tail. Relative to the session baseline this cut rebuilt size from 10576 to 9936, calls from 487 to 448, and CFG conditionals from 264 to 236 (original 9580/440/233); frame is now exact at 0xD0.
// - current check_function: MISMATCH 94.1224% positional / 116.2037% edit, 3358 equal bytes, first mismatch +0x60. The opening matches through sentinel setup; remaining first hunk is original `xor ebp; cmp esi,ebp` versus rebuilt `test esi,esi`. Size is now only +356 rather than +996, so continue structural/call-tail cleanup before register coloring.
// - corrected the action-2 play gate: target acquisition/retask now runs only for playNumberValue==-1, while the play-status recovery is the separate original fallback. Restored repeated unit/retreatLocation/unitAI/targetLocation calls visible in the binary and the redundant subtype check.
// - moved the victory-condition target-selection/grow logic onto the type-100/0x67 attack-enabled arm instead of the unrelated inactive generic-type arm. Shared only the binary-observed ManagedArray delete tail and the active exception-path finish; this removed the duplicate objectToAttackByGroup path and brought direct-call totals much closer.
// - reshaped the active action dispatch around the original 0xc/0x13/3 gates, shared the action-7 timeout path, restored the second assist-group lookup, and routed the defend exception path through the observed common attack-state clear. This moved ordered call alignment from the first relic failure calls to the post-relic-success tail.
// - current check_function: MISMATCH 92.2547% positional / 116.7328% edit, shape 52.82%, longest aligned run 96, frame exact 0xD0. Rebuilt is now 9380 vs 9580 (-200), 435 vs 440 calls, 231 vs 233 conditionals, and 64 vs 69 jumps. First mismatch remains +0x60 (`test esi,esi` vs zero-in-EBP compare); first ordered call divergence is now +0x36A after the relic fallback, where rebuilt still places one setAction failure block before the direct-success setters.
// - inverted the action-0x10 type-100 reset arm to keep its commander/canAttack path inline before the non-100 gather path, matching the original physical order; shape rose from 52.82% to 53.66% and ordered-call alignment from 80.00% to 81.36%.
// - inverted the action-2 valid-target subtype dispatch so non-default subtypes stay inline and subtype -1 becomes the late handler, matching the original +1C9C compare chain and post-epilogue handler family. This was the major structural breakthrough: shape rose to 69.12%, call alignment to 85.23%, and edit/resync similarity to 41.08%.
// - reordered action-0x13 predicates to isGathered -> elapsed-time/consecutive-idle -> allUnitsIdle, following the original call order. Kept despite broad address movement because all three calls now align in order.
// - restored the binary-observed independent transport inside-object tests instead of an else-if simplification. This recovered the second commander call and removeUnit block, made CFG conditional counts exact (233/233), reduced target-count differences from 11 to 8, and raised shape/call alignment to 70.33%/86.82%.
// - spelling the outer action-2 invalid-target predicate first (as suggested by PDB line order) and naming a null-group local were codegen-neutral; retained the natural negative invalid-target source, but rolled back the unused null local.
// - current baseline: MISMATCH 92.0564% positional / 51.68% bounded edit, shape 70.33%, 3911 equal bytes, frame exact 0xD0. Rebuilt is 9387 vs 9580 (-193), 436 vs 440 calls, conditionals exact at 233/233, jumps 62 vs 69. First mismatch remains +0x60 (`test esi,esi` versus `xor ebp; cmp esi,ebp`); first ordered divergence remains the early relic success/failure block placement around +0x360.
// - rewrote the transport-loop invalid-object/invalid-unitAI cases as natural nested branches rather than goto handlers; this preserved both binary-observed logCommonHistory call sites and improved bounded edit similarity.
// - restored the missing +0x10c weaponRange virtual call in the defend-object canPath predicate and the type-0x67 guard that skips the attack exception-path fallback; both aggregate call counts now match the original.
// - made the two defend-object null failures exit immediately, preventing VC5 from merging their distinct setAction calls. Split the inactive default-task selection so its action result is materialized for the shared task tail.
// - shared the defend/relic gather-location and set-in-use tail through one label, matching the original common +27F4 tail and eliminating one extra call of each kind. The three float values intentionally reuse the pending-task stack homes.
// - corrected the active attack exception fallback to nested type/path/path-point gates and duplicated its natural completion tail. This recovered the missing task call and brought rebuilt size from -193 to -41 bytes; VC5 did not tail-merge targetLocation/waitCode as far as the original, leaving one extra call of each.
// - modeled the two path-point outputs as distinct float locals (including the defend gatherAux); frame returned to the exact 0xD0.
// - current baseline: rebuilt 9539 vs 9580 (-41), 441 vs 440 calls, frame exact 0xD0, shape 71.17%, bounded edit 49.40%, and 4145 equal bytes. Remaining aggregate call gaps are one missing setAction plus one extra setTargetLocation and setWaitCode; CFG has one extra conditional and four fewer jumps. First mismatch remains +0x60 (`test esi,esi` versus `xor ebp; cmp esi,ebp`).
// - split the active exception-path canPath failure from the type/path-point rejection. The former also clears numberObjectsToDestroy, matching the distinct original +09E8 failure block and recovering the last missing setAction call.
// - precompute the exception-path target coordinates in the three pending-task homes before converging the active-selection and action-7 paths. Sharing only the calls after task preserves both task call sites while tail-sharing setAction/target/type/location/in-use/wait. This made all 440 aggregate call counts exact.
// - hoisted the reused ObjectMemory pointer to function scope so the converged exception tail does not need an artificial fourth pending local. The defend canPath output is one float, while its two find-first-path outputs remain distinct floats; correcting that surface keeps the frame at the exact 0xD0.
// - inverted the defend and active-attack direct canPath branches so the exception fallback is source-inline and direct success is the else arm, matching the original cold-block order. Shape improved from 69.99% to 73.99% and call alignment from 87.73% to 90.45%. Applying the same common failure label to defend/relic over-merged five setter calls, so that probe was rolled back.
// - current baseline: rebuilt/original size exactly 9580, calls exactly 440 with zero target-count differences, frame exactly 0xD0, saved registers exact, shape 73.99%, call alignment 90.45%, bounded edit 46.19%, and 4415 equal bytes. CFG is close at 234/233 conditionals and 67/69 jumps. First mismatch is +0x57 because the rebuilt second sentinel compare uses eax and `test esi,esi`, while original keeps the sentinel in ebx then emits `xor ebp; cmp esi,ebp`.
// - removed the incorrect playNumber=-1 store from the active-selection null-commander failure. This moved the block into the original +090B family, improved strict diff to 91.88%, and extended ordered call alignment from the early 30s to 57 calls.
// - rewrote the active exception fallback as linear negative guards (type, additional canPath, then positive path-point success), preserving the original distinct canPath failure and rejection blocks. Splitting task/setAction/setTarget/setTargetType before the shared coordinate/set-location tail raised the ordered call prefix to 109 and shape above 75%.
// - the original direct canPath and additional-passability canPath use distinct float output homes; modeling `point` and `exceptionPoint` separately restores the exact 0xD0 frame after the exception-prefix split. The action-0x0f invalid reset also requires the observed numberObjectsToDestroy=0 store.
// - action-0x0f and action-0x10 invalid resets appear to converge at the old LAB_004f37f1 source label. Explicitly unifying them removes the extra target/targetType pair, but VC5 then over-merges one unrelated setAction/setInUse pair and shrinks the function by 52 bytes; rolled back pending a source shape that preserves those setters naturally.
// - current baseline: size exactly 9580, frame exactly 0xD0, saved registers exact, shape 75.66%, call alignment 90.95% with a 109-call prefix, and CFG 234/233 conditionals plus 66/69 jumps. Calls are 442/440: only one extra setTarget and setTargetType site remain, localized to reset-tail sharing. First mismatch remains +0x57 at the second sentinel/null test.
// - unified the action-0x0f/0x10 invalid reset at the binary-observed common tail, then isolated the action-0x10 attack failure with a local label and natural direct task call. This prevents VC5 from merging that setInUse/setAction pair with the distant action-7 timeout tail: aggregate calls are now exact at 440, size is -27, shape 75.70%, and call alignment 91.59%.
// - restored the original combined inactive task gate (`allOutside || action()!=2`), extending the exact ordered call prefix from 109 to 215. The loss-check task now uses the observed post-setAction action() call and a direct task tail, which restores exact size/call totals and also fixes the opening sentinel register to EBX.
// - action-0x10 performs the target/object lookup before its type test even though non-type-100 paths discard the result. Reusing pendingTaskCode for that binary-observed pointer home preserves the exact 0xD0 frame. Current milestone: size/frame/calls exact, shape 76.53%, call alignment 92.27% with prefix 225, edit/resync similarity 55.41%; first mismatch is now +0x60 at the zero-in-EBP null compare.
// - inlined the action-0x10 taskAttacker target/location arguments to recover the original right-to-left call order, extending the ordered prefix to 255. This removes two artificial float homes and exposes an 8-byte frame deficit that still needs a real local-layout fix.
// - restored the binary-observed lastAttackResponseTime update and changed the action-0x10 success to task the group's post-setAction action value with args (1,0). The natural direct suffix merges with the loss-check suffix as in the original and extends the ordered call prefix to 323.
// - isolated the action-7 timeout with its natural direct task call, preventing VC5 from merging its setAction with a distant identical tail. Aggregate calls return to exact and the ordered prefix reaches 358. A direct-task spelling for the sn[0x31]==2 reset added an action call and collapsed the early prefix, so it was rolled back.
// - the non-default action-2 idle-timeout reset must exit immediately; letting it fall into the play-status recovery was behaviorally wrong and encouraged setter-tail merging. Restoring the direct ContinueLoop edge keeps its target-type/location calls distinct, raises shape to 77.86% and call alignment to 92.95%, and extends the ordered prefix to 360.
// - enlarging the action-7 auxiliary output window from 4 to 12 bytes restored the 0xD0 frame and improved block coverage, but it is not justified by the float* callee surface and changed the sentinel register, so it was rolled back. The current 0xC8 frame is an exposed real-local modeling deficit, not a padding invitation.
// - an explicit goto split for subtype==-1 moved that cold handler too early, reduced call alignment to 88.86%, and was rolled back; keep the positive non-default subtype body for now.
// - modeled the defend-distance selection as a real float and restored two shared gather-coordinate homes from the Ghidra fVar topology; frame is now exact at 0xD0 and the original +0407/+040F FILD blocks are exact. Reversed several equivalent threshold predicates to preserve binary-observed compare operand order, raising exact-block coverage from 33.04% to 37.08% and the longest aligned run from 96 to 106 while keeping all 440 call counts exact. Current size is +42, shape 78.24%, call prefix 360; first mismatch is +0x57 at the sentinel/zero-register choice.
// - rolled back focused sentinel probes (direct member comparison, register local, and a scoped zero/null alias): they either compiled identically or changed only four unrelated later bytes; none recovered the original `lea ebx` / `xor ebp; cmp esi, ebp` opening.
// - worker pass: 20 evidence-led checks. Best current source is 9618 bytes versus 9580, with 440/440 calls and 37.43% exact-block coverage.
// - BINARY NOTE: original defend null exits and action-7 exception completion jump to the common tail at 004F4548 after their state stores. The temporary clear_attack_state tail preserves the single original store; direct copies make VC5 emit four stores.
// - BINARY NOTE: original action-2 reset paths place the target-location store before the numberObjectsToDestroy store in their cold reset tail.
// - reordered action-2 handling to the binary-supported positive valid-target branch first, with invalid-target replacement/reset as the else arm; emitted code stayed effectively duplicate (six changed bytes, one fewer diff byte) with no CFG or call movement, but the source now follows the decompiler-supported fallthrough.
// - rolled back positive `isEnemy` arm order: it improved size/call-site count slightly but reduced block/edit alignment and did not move the misplaced virtual-dispatch block into the original +0x2400 family.
// - second worker pass: 20 evidence-led checks. The best source is 9609 bytes versus 9580, with 440/440 calls and an exact 0xD0 frame.
// - corrected stuffAvoidancePath to the proven two-argument member ABI. This made original block +0x0C33 exact and removed two bytes.
// - restored PDB source order for action-2 target handling and the original enemy-arm polarity. Ordered call alignment rose to 93.41%.
// - changed the byte state test to `object_state > 2`. This recovered original CMP 2 / JA and made block +0x1C92 exact.
// - remaining structural blocker: the subtype -1 handler stays inline near rebuilt +0x1EAD. Original VC5 places its only incoming block after both epilogues at +0x2400.
// - original PDB symbols show one source label only: ContinueLoop at original +0x2362. Other labels here are temporary compiler-tail models.
// - original PDB locals include attackAsAttack, defendDistance, tAreaMin, tAreaMax, point, pathDistance, gatherX, and gatherY.
// - tAreaMin and tAreaMax are 16-byte Waypoint values. Modeling both makes the original 63-instruction action-2 block exact, but exposes conflicting synthetic homes.
// - direct location expressions recover exact local blocks. Defer them until common-tail structure preserves the call surface and exact 0xD0 frame.
// - the direct relic path passes relic->type, not constant 0x6d. This aligns the next defender block at original +0x3ac and improves strict diff by 51 bytes.
// - relic canPath failure handling ends at PDB line 4219 and exits through ContinueLoop. Keeping that behavior currently makes VC5 merge one unrelated setter tail.
// - placing the relic exit in each completed branch preserves behavior and recovers exact blocks at original +0x1e3c and +0x1ef8.
// - original relic and defender path failures share the later active setAction block. Spelling all three failure tails directly lets VC5 recover that join without source labels and improves strict diff by 15 bytes.
// - removed an unreachable duplicate inactive target block and its trampoline. They never emitted code; inactive selection now targets the live common region directly.
// - Ghidra shows an explicit clear-tail edge after defender exception completion. Relic completion instead falls through to the end of its type arm. Moving the relic clear edge to that boundary is codegen-neutral and matches this source evidence.
// - an outer-loop continue restores the missing relic setter sites, but skips group advancement and the time-limit check. Do not use that diagnostic shape as behavior evidence.
// - translation-unit context lab: preceding dummy functions, the reconstructed taskIdleSoldiers body, and the exact playTaskSoldiers declarations change only 0/4/6 bytes in one FPU coordinate-sum block. The pattern repeats every four preceding functions.
// - placing exact playTaskSoldiers after this function, as in taitacmd.cpp, adds no further change. Tested context keeps size, frame, CFG, and 437-call surface unchanged, so it does not explain the merged relic setter suffix.
// - semantic-review normalization removed the TASK_GROUP compiler-tail macro, integer/float stack aliases, and exception_after_task join. Direct task and location calls now show the intended path behavior without codegen scheduling machinery.
// - first blind review found missing active-state exits, loss-check fallthroughs, one reset store, two extra null guards, wrong influence predicate order, and local ABI stubs. Main-agent executable review confirmed and corrected those findings.
// - second blind review found action-0x0d null-path state errors, action-2/action-4 clear-tail errors, loss getter order, timeout-shift width, and three helper ABI forms. Main-agent executable review confirmed and corrected them.
// - third blind review found the direct-defense range, null-target exit, repeated weapon-range calls, action-0x0d null-transporter path, action-0x13 call order, target-point copy order, and MainDecision object ownership. Main-agent executable review confirmed and corrected them.
// - fourth blind review found a missing stopUnit call, the special-target attack-attempt write, one action-0x0f post-stop exit, and the six-argument +0x194 virtual ABI. Main-agent executable review confirmed and corrected them.
// - fifth blind review found one missing numberObjectsToDestroy reset in action-2 replacement failure. Main-agent executable review confirmed and corrected it; three reviewers found no other broad difference.
// - sixth blind review found one transport fault-order difference, one defend idle-time reset, and an extra special-target attack-attempt write. Main-agent executable review confirmed and corrected them.
// - seventh four-reviewer cohort found no confirmed behavior difference after main-agent adjudication. The remaining differences are broad VC5 tail sharing, local lifetime, and scheduling drift; see logic_reviews/004F21F0_taskActiveSoldiers.md.


static char s_C__msdev_work_age1_x1_taitacmd_c[] =
    "C:\\msdev\\work\\age1_x1\\taitacmd.cpp";



void TribeTacticalAIModule::taskActiveSoldiers(ulong param_1, ulong param_2)
{
    TacticalAIGroup* cur;
    ObjectMemory* mem;
    int t;
    float directGatherX;
    float directGatherY;
    float directGatherZ;

    cur = this->groups.next;
    if (this->nextActiveSoldierGroupToTaskValue != -1) {
        while (cur != &this->groups) {
            if (cur == 0) {
                break;
            }
            if (cur->id() == this->nextActiveSoldierGroupToTaskValue) {
                break;
            }
            cur = cur->next;
        }
        if (cur->id() != this->nextActiveSoldierGroupToTaskValue) {
            cur = this->groups.next;
        }
    }

    if (cur != &this->groups) {
        do {
            if (cur == 0) {
                break;
            }

            t = cur->type();
            if (t == 0x6b || cur->type() == 0x6c || cur->type() == 0x6a ||
                cur->action() == 0 || cur->action() == 1) {
                cur = cur->next;
                continue;
            }

            if (!cur->allUnitsIdle(this->md, 1)) {
                cur->setConsecutiveIdleUnitCount(this->md->player->world->world_time);
            }

            if (!cur->inUse()) {
                RGE_Static_Object* commanderObj;
                int attackAsAttack;

                mem = 0;
                commanderObj = 0;
                attackAsAttack = 1;
                t = cur->type();
                if (t != 100 && cur->type() != 0x67) {
                    t = cur->type();
                    if (t == 0x65 || cur->type() == 0x68) {
                        int commander;
                        XYZPoint point;
                        float defendDistance;
                        float pathDistance;
                        float gatherX;
                        float gatherY;

                        commander = cur->commander();
                        mem = this->md->informationAI.objectToDefend(commander);
                        if (mem == 0) {
                            cur->setAction(1);
                            goto clear_attack_state;
                        } else {
                            commander = cur->commander();
                            commanderObj = this->md->object(commander);
                            if (commanderObj == 0) {
                                cur->setAction(1);
                                goto clear_attack_state;
                            } else {
                                if (mem->type == 0x6d) {
                                    defendDistance = (float)this->sn[0x16];
                                } else {
                                    defendDistance = (float)this->sn[0x39];
                                }
                                point.z = mem->z;
                                point.x = mem->x;
                                point.y = mem->y;
                                if (!commanderObj->canPath(point,
                                        commanderObj->weaponRange(),
                                        mem->id, &pathDistance, 1, -1, -1)) {
                                    if (!commanderObj->canPathWithAdditionalPassability(
                                            point, defendDistance, mem->id, &pathDistance,
                                            1, 0x16, 1, -1, -1)) {
                                        cur->setConsecutiveIdleUnitCount(
                                            this->md->player->world->world_time);
                                        cur->setAction(1);
                                        goto clear_attack_state;
                                    }
                                    if (commanderObj->findFirstTerrainAlongExceptionPath(
                                            2, &gatherX, &gatherY) == 1) {
                                        mem->attackAttempts = 1;
                                        cur->task(this, this->md, 0x0e, 1, 0);
                                        cur->setAction(0x0d);
                                        cur->setTarget(mem->id);
                                        cur->setTargetType((int)mem->type);
                                        cur->setTargetLocation((float)mem->x, (float)mem->y, (float)mem->z);
                                        cur->setInUse(1);
                                        cur->setWaitCode(200);
                                        goto clear_attack_state;
                                    } else {
                                        cur->setAction(1);
                                        goto clear_attack_state;
                                    }
                                } else {
                                    mem->attackAttempts = 1;
                                    cur->setTarget(mem->id);
                                    cur->setTargetType((int)mem->type);
                                    cur->setTargetLocation((float)mem->x, (float)mem->y, (float)mem->z);
                                    directGatherZ = (float)mem->z;
                                    directGatherY = (float)mem->y;
                                    directGatherX = (float)mem->x;
                                    goto inactive_direct_gather;
                                }
                            }
                        }
                    } else {
                        t = cur->type();
                        if (t == 0x6d) {
                            RGE_Static_Object* relic;
                            TribeMainDecisionAIModule* md;
                            unsigned long idle;
                            unsigned long elapsed;

                            md = this->md;
                            idle = cur->consecutiveIdleUnitCount();
                            elapsed = (md->player->world->world_time - idle) / 1000;
                            if (elapsed < 60) {
                                cur->setAction(1);
                                goto clear_attack_state;
                            } else {
                                relic = md->object(-1, 0x6d, -1, -1, -1, -1, -1, -1, -1, -1);
                                if (relic == 0) {
                                    cur->setAction(1);
                                    goto clear_attack_state;
                                } else {
                                    commanderObj = this->md->object(cur->commander());
                                    if (commanderObj == 0) {
                                        cur->setAction(1);
                                        goto clear_attack_state;
                                    } else {
                                        XYZPoint point;
                                        float pathDistance;
                                        float gatherX;
                                        float gatherY;
                                        point.x = (int)relic->world_x;
                                        point.y = (int)relic->world_y;
                                        point.z = (int)relic->world_z;
                                        if (!commanderObj->canPath(point,
                                                (float)this->sn[0x17], relic->id,
                                                &pathDistance, 1, -1, -1)) {
                                            if (!commanderObj->canPathWithAdditionalPassability(
                                                    point, (float)this->sn[0x17], relic->id,
                                                    &pathDistance, 1, 0x16, 1, -1, -1)) {
                                                cur->setConsecutiveIdleUnitCount(this->md->player->world->world_time);
                                                cur->setAction(1);
                                                goto clear_attack_state;
                                            } else if (commanderObj->findFirstTerrainAlongExceptionPath(
                                                           2, &gatherX, &gatherY) == 1) {
                                                cur->task(this, this->md, 0x0e, 1, 0);
                                                cur->setAction(0x0d);
                                                cur->setTarget(relic->id);
                                                cur->setTargetType((int)relic->type);
                                                cur->setTargetLocation(relic->world_x, relic->world_y, relic->world_z);
                                                cur->setInUse(1);
                                                cur->setWaitCode(200);
                                            } else {
                                                cur->setAction(1);
                                                goto clear_attack_state;
                                            }
                                        } else {
                                            cur->setTarget(relic->id);
                                            cur->setTargetType((int)relic->type);
                                            cur->setTargetLocation(relic->world_x, relic->world_y, relic->world_z);
                                            directGatherX = relic->world_x;
                                            directGatherY = relic->world_y;
                                            directGatherZ = relic->world_z;
                                            goto inactive_direct_gather;
                                        }
                                    }
                                }
                            }
                            goto clear_attack_state;
                        } else {
                            goto inactive_post_setup;
active_target_selection:
                            int* players;
                            int* newPlayers;
                            if (this->md->strategyAI.currentVictoryCondition() == 0) {
                                int capture;
                                capture = this->itemToCapture();
                                mem = this->md->informationAI.objectMemory(capture);
                                if (mem == 0) {
                                    if (this->playersToAttack.maximumSizeValue - 1 < 0) {
                                        newPlayers = (int*)operator_new(4);
                                        if (newPlayers != 0) {
                                            int i;
                                            i = 0;
                                            while (i < this->playersToAttack.maximumSizeValue && i < 1) {
                                                newPlayers[i] = this->playersToAttack.value[i];
                                                i++;
                                            }
                                            goto inactive_resize_commit;
                                        }
                                    }
                                    goto inactive_object_to_attack;
                                }
                            } else if (this->md->strategyAI.currentVictoryCondition() == 4) {
                                int bring;
                                bring = this->itemToBringToArea();
                                mem = this->md->informationAI.objectMemory(bring);
                                if (mem == 0) {
                                    if (this->playersToAttack.maximumSizeValue - 1 < 0) {
                                        newPlayers = (int*)operator_new(4);
                                        if (newPlayers != 0) {
                                            int i;
                                            i = 0;
                                            while (i < this->playersToAttack.maximumSizeValue && i < 1) {
                                                newPlayers[i] = this->playersToAttack.value[i];
                                                i++;
                                            }
                                            goto inactive_resize_commit;
                                        }
                                    }
                                    goto inactive_object_to_attack;
                                }
                            } else {
                                if (this->playersToAttack.maximumSizeValue - 1 < 0) {
                                    int* newPlayers;
                                    newPlayers = (int*)operator_new(4);
                                    if (newPlayers != 0) {
                                        int i;
                                        i = 0;
                                        while (i < this->playersToAttack.maximumSizeValue && i < 1) {
                                            newPlayers[i] = this->playersToAttack.value[i];
                                            i++;
                                        }
                                        operator_delete(this->playersToAttack.value);
                                        this->playersToAttack.value = newPlayers;
                                        this->playersToAttack.maximumSizeValue = 1;
                                    }
                                }
                                players = this->playersToAttack.value;
                                mem = this->md->informationAI.objectToAttackByGroup(*players, cur, &this->attackStateValue, param_1);
                                if (this->attackStateValue.active == 1) {
                                    this->nextActiveSoldierGroupToTaskValue = cur->id();
                                    return;
                                }
                                goto active_target_selected_common;
                            }
                            goto active_target_selected_common;
inactive_resize_commit:
                            operator_delete(this->playersToAttack.value);
                            this->playersToAttack.value = newPlayers;
                            this->playersToAttack.maximumSizeValue = 1;
inactive_object_to_attack:
                            players = this->playersToAttack.value;
                            mem = this->md->informationAI.objectToAttack(*players, 1, 1,
                                                                         cur->commander(),
                                                                         attackAsAttack);
                            goto active_target_selected_common;
                        }
                    }
                } else {
                    int attackEnabled;
                    int* players;
                    int* newPlayers;
                    unsigned long lastAttackTime;
                    unsigned long elapsed;

                    attackEnabled = this->attackEnabledValue;
                    if (attackEnabled == 0) {
                        this->attackStateValue.active = 0;
                        goto ContinueLoop;
                    } else {
                        if (this->sn[0xa2] != 0 && cur->type() != 0x67) {
                            mem = this->md->informationAI.objectMemory(*(int*)0);
                            goto attack_target_ready;
                        }
                        lastAttackTime = this->lastGroupAttackTime;
                        elapsed = (this->md->player->world->world_time - lastAttackTime) / 1000;
                        if (lastAttackTime != 0 && this->sn[0x2f] == 2 && elapsed != 0 && this->attackLimiterTime(0x2e) > elapsed) {
                            this->attackStateValue.active = 0;
                            goto ContinueLoop;
                        } else if (lastAttackTime != 0 && this->sn[0x2f] == 1 && this->attackLimiterTime(0x2e) > elapsed) {
                            this->attackStateValue.active = 0;
                            goto ContinueLoop;
                        } else {
                            if (this->md->strategyAI.currentVictoryCondition() == 0) {
                                int capture;
                                capture = this->itemToCapture();
                                mem = this->md->informationAI.objectMemory(capture);
                                if (mem == 0) {
                                    if (this->playersToAttack.maximumSizeValue - 1 < 0) {
                                        newPlayers = (int*)operator_new(4);
                                        if (newPlayers != 0) {
                                            int i;
                                            i = 0;
                                            while (i < this->playersToAttack.maximumSizeValue && i < 1) {
                                                newPlayers[i] = this->playersToAttack.value[i];
                                                i++;
                                            }
                                            goto active_resize_commit;
                                        }
                                    }
                                    goto active_object_to_attack;
                                }
                            } else if (this->md->strategyAI.currentVictoryCondition() == 4) {
                                int bring;
                                bring = this->itemToBringToArea();
                                mem = this->md->informationAI.objectMemory(bring);
                                if (mem == 0) {
                                    if (this->playersToAttack.maximumSizeValue - 1 < 0) {
                                        newPlayers = (int*)operator_new(4);
                                        if (newPlayers != 0) {
                                            int i;
                                            i = 0;
                                            while (i < this->playersToAttack.maximumSizeValue && i < 1) {
                                                newPlayers[i] = this->playersToAttack.value[i];
                                                i++;
                                            }
                                            goto active_resize_commit;
                                        }
                                    }
                                    goto active_object_to_attack;
                                }
                            } else {
                                if (this->playersToAttack.maximumSizeValue - 1 < 0) {
                                    int* generalPlayers;
                                    generalPlayers = (int*)operator_new(4);
                                    if (generalPlayers != 0) {
                                        int i;
                                        i = 0;
                                        while (i < this->playersToAttack.maximumSizeValue && i < 1) {
                                            generalPlayers[i] = this->playersToAttack.value[i];
                                            i++;
                                        }
                                        operator_delete(this->playersToAttack.value);
                                        this->playersToAttack.value = generalPlayers;
                                        this->playersToAttack.maximumSizeValue = 1;
                                    }
                                }
                                players = this->playersToAttack.value;
                                mem = this->md->informationAI.objectToAttackByGroup(
                                    *players, cur, &this->attackStateValue, param_1);
                                if (this->attackStateValue.active == 1) {
                                    this->nextActiveSoldierGroupToTaskValue = cur->id();
                                    return;
                                }
                                goto active_target_selected_common;
                            }
                            goto active_target_selected_common;
active_resize_commit:
                            operator_delete(this->playersToAttack.value);
                            this->playersToAttack.value = newPlayers;
                            this->playersToAttack.maximumSizeValue = 1;
active_object_to_attack:
                            players = this->playersToAttack.value;
                            mem = this->md->informationAI.objectToAttack(*players, 1, 1,
                                                                         cur->commander(),
                                                                         attackAsAttack);
active_target_selected_common:
                            if (mem == 0) {
                                cur->setAction(1);
                                this->attackStateValue.active = 0;
                                goto ContinueLoop;
                            } else {
                                mem->attackAttempts = mem->attackAttempts + 1;
attack_target_ready:
                                commanderObj = this->md->object(cur->commander());
                                if (commanderObj == 0) {
                                    cur->setAction(1);
                                    goto clear_attack_state;
                                } else {
                                    float point;
                                    float attackRange;
                                    XYZPoint targetPoint;
                                    targetPoint.x = mem->x;
                                    targetPoint.y = mem->y;
                                    targetPoint.z = mem->z;
                                    attackRange = commanderObj->weaponRange();
                                    if (!commanderObj->canPath(targetPoint,
                                            attackRange, mem->id,
                                            &point, 1, mem->owner, 0x1b)) {
                                        float exceptionPoint;
                                        float gatherX2;
                                        float aux2;
                                        if (cur->type() == 0x67) {
                                            goto active_exception_rejected;
                                        }
                                        if (!commanderObj->canPathWithAdditionalPassability(
                                                targetPoint, attackRange,
                                                mem->id, &exceptionPoint, 1, 0x16, 1,
                                                mem->owner, 0x1b)) {
                                            cur->numberObjectsToDestroyValue = 0;
                                            cur->setAction(1);
                                            cur->playNumberValue = -1;
                                            this->attackStateValue.active = 0;
                                            goto ContinueLoop;
                                        }
                                        if (commanderObj->findFirstTerrainAlongExceptionPath(
                                                2, &gatherX2, &aux2) == 1) {
                                            cur->task(this, this->md, 0x0e, 1, 0);
                                            cur->setAction(0x0d);
                                            cur->setTarget(mem->id);
                                            cur->setTargetType((int)mem->type);
                                            cur->setTargetLocation((float)mem->x,
                                                                   (float)mem->y,
                                                                   (float)mem->z);
                                            cur->setInUse(1);
                                            cur->setWaitCode(200);
                                            cur->playNumberValue = -1;
                                            goto clear_attack_state;
                                        }
active_exception_rejected:
                                        cur->setAction(1);
                                        cur->playNumberValue = -1;
                                        goto clear_attack_state;
                                    } else {
                                        this->lastGroupAttackTime = this->md->player->world->world_time;
                                        if (this->sn[0x47] == 1) {
                                            this->lastAttackResponseTime = this->md->player->world->world_time;
                                        }
                                        cur->setTarget(mem->id);
                                        cur->setTargetType((int)mem->type);
                                        cur->setTargetLocation((float)mem->x, (float)mem->y, (float)mem->z);
                                        cur->setInUse(1);
                                        this->checkForCoopAttack((unsigned int)mem->owner, (unsigned int)mem->x, (unsigned int)mem->y);
                                    }
                                }
                            }
                        }
                    }
                }
                goto inactive_post_setup;
inactive_direct_gather:
                cur->setGatherLocation(directGatherX,
                                       directGatherY,
                                       directGatherZ);
                cur->setInUse(1);
inactive_post_setup:
                if (this->md->strategyAI.currentVictoryCondition() == 0x0b &&
                    (cur->type() == 100 || cur->type() == 0x67) &&
                    this->sn[0x67] == 1 && mem != 0 && commanderObj != 0) {
                    XYZPoint targetTile;
                    Path* avoidancePath;
                    this->md->informationAI.addEnemyInfluences((int)mem->owner, mem->id);
                    this->md->informationAI.addPriorAttackInfluences((int)mem->owner, mem->id);
                    targetTile.x = (int)mem->x;
                    targetTile.y = (int)mem->y;
                    targetTile.z = 1;
                    avoidancePath = commanderObj->findAvoidancePath(
                        &targetTile, commanderObj->weaponRange(), 1);
                    if (avoidancePath != 0) {
                        this->stuffAvoidancePath(cur, avoidancePath);
                    }
                }
                if (attackAsAttack != 0 || cur->action() != 2) {
                    cur->task(this, this->md, cur->action(), 1, 0);
                    this->attackStateValue.active = 0;
                    goto ContinueLoop;
                }
                cur->task(this, this->md, 0x15, 1, 0);
                this->attackStateValue.active = 0;
                goto ContinueLoop;
            } else {
                t = cur->action();
                if (t == 0x0d) {
                    if (cur->waitCode() == 200) {
                        TacticalAIGroup* assist;
                        assist = 0;
                        if (cur->assistGroupID() == -1) {
                            RGE_Static_Object* commanderObj2;
                            XYPoint commanderPoint2;
                            commanderObj2 = this->md->object(cur->commander());
                            if (commanderObj2 == 0) {
                                this->attackStateValue.active = 0;
                                goto ContinueLoop;
                            } else {
                                commanderPoint2.x = (int)commanderObj2->world_x;
                                commanderPoint2.y = (int)commanderObj2->world_y;
                                assist = this->bestGroup(0x6a, 1, -1, &commanderPoint2, -1);
                                if (assist == 0) {
                                    assist = this->bestGroup(0x6a, 0, -1, &commanderPoint2, -1);
                                }
                                if (assist != 0) {
                                    cur->setAssistGroupID(assist->id());
                                    cur->setAssistGroupType(assist->type());
                                    assist->setAction(0x0c);
                                    assist->setInUse(1);
                                    assist->setAssistGroupID(cur->id());
                                }
                            }
                        } else {
                            assist = this->group(cur->assistGroupID(), -1, -1, -1);
                        }
                        if (assist != 0) {
                            RGE_Static_Object* transportObj;
                            short transportCount;
                            unsigned char transportCapacity;
                            transportObj = this->md->object(assist->commander());
                            if (transportObj != 0) {
                                transportCount = transportObj->objects->number_of_objects;
                                transportCapacity = transportObj->master_obj->obj_max;
                            }
                            if (transportObj == 0 ||
                                transportCount < transportCapacity) {
                                int i;
                                int didTask;
                                didTask = 0;
                                i = 0;
                                while (i < cur->numberUnits()) {
                                    int unit_id;
                                    RGE_Static_Object* unitObj2;
                                    UnitAIModule* ai;
                                    unit_id = cur->unit(i);
                                    unitObj2 = this->md->object(unit_id);
                                    if (unitObj2 != 0) {
                                        ai = unitObj2->unitAI();
                                        if (ai != 0) {
                                            ai = unitObj2->unitAI();
                                            if (ai->currentAction() == -1) {
                                                didTask = 1;
                                                this->taskToEnter(unit_id, assist->commander());
                                            }
                                        }
                                    }
                                    i++;
                                }
                                if (!didTask) {
                                    cur->setAction(0x0f);
                                    this->attackStateValue.active = 0;
                                } else {
                                    goto clear_attack_state;
                                }
                            } else {
                                cur->setAction(0x0f);
                                this->attackStateValue.active = 0;
                            }
                        } else {
                            cur->setAssistGroupID(-1);
                            cur->setAssistGroupType(-1);
                            this->attackStateValue.active = 0;
                        }
                    } else {
                        this->attackStateValue.active = 0;
                    }
                } else if (cur->action() == 0x0f) {
                    TacticalAIGroup* assist;
                    RGE_Static_Object* transportObj;

                    assist = this->group(cur->assistGroupID(), -1, -1, -1);
                    if (assist != 0) {
                        transportObj = this->md->object(assist->commander());
                        if (transportObj != 0) {
                            int i;
                            int needTransporter;
                            unsigned char targetZone;

                            if (transportObj->objects->number_of_objects >= transportObj->master_obj->obj_max) {
                                cur->removeUnboardedUnits(this, this->md);
                            }
                            targetZone = 0xff;
                            needTransporter = 1;
                            i = 0;
                            while (i < cur->numberUnits()) {
                                int unit_id;
                                RGE_Static_Object* unitObj2;
                                UnitAIModule* ai;

                                unit_id = cur->unit(i);
                                unitObj2 = this->md->object(unit_id);
                                if (unitObj2 == 0) {
                                    this->logCommonHistory((char*)0x005883D4);
                                } else {
                                    ai = unitObj2->unitAI();
                                    if (ai == 0) {
                                        this->logCommonHistory((char*)0x005883B4);
                                    } else {
                                        if (cur->unit(i) == cur->commander()) {
                                            const Waypoint* loc;
                                            XYPoint zp;
                                            loc = &cur->targetLocation();
                                            zp.x = (int)loc->x;
                                            loc = &cur->targetLocation();
                                            zp.y = (int)loc->y;
                                            targetZone = unitObj2->lookupZone(zp);
                                        }
                                        if (unitObj2->inside_obj != 0 && unitObj2->inside_obj->id == assist->commander()) {
                                            if (unitObj2->unitAI()->currentAction() != -1) {
                                                this->stopUnit(unitObj2->id, 100);
                                                i++;
                                                continue;
                                            }
                                        }
                                        if (unitObj2->inside_obj == 0 || unitObj2->inside_obj->id == assist->commander()) {
                                            if (unitObj2->inside_obj == 0) {
                                                needTransporter = 0;
                                                if (unitObj2->unitAI()->currentOrder() != 700 && unitObj2->unitAI()->currentOrder() != 0x2cd) {
                                                    this->taskToEnter(cur->unit(i), assist->commander());
                                                }
                                            }
                                        } else {
                                            cur->removeUnit(unitObj2->id, this->md);
                                        }
                                    }
                                }
                                i++;
                            }
                            if (needTransporter != 0) {
                                const Waypoint* loc;
                                XYPoint targetPoint;
                                XYPoint staging;
                                loc = &cur->targetLocation();
                                targetPoint.x = (int)loc->x;
                                loc = &cur->targetLocation();
                                targetPoint.y = (int)loc->y;
                                if (this->md->informationAI.findStagingPoint(targetPoint, &staging, 1, 1, cur->target(), 0x0f, cur->commander()) == 0) {
                                    loc = &cur->targetLocation();
                                    staging.x = (int)loc->x;
                                    loc = &cur->targetLocation();
                                    staging.y = (int)loc->y;
                                }
                                this->taskTransporter(assist->commander(), (float)staging.x + 0.5f, (float)staging.y + 0.5f);
                                assist->setTargetLocation((float)staging.x, (float)staging.y, -1.0f);
                                assist->setAction(0x0c);
                                assist->setTargetType(targetZone);
                                cur->setAction(0x10);
                                cur->task(this, this->md, 0x16, 0, 1);
                                if (assist->numberUnits() > 1) {
                                    int j;
                                    j = 0;
                                    while (j < assist->numberUnits()) {
                                        if (assist->unit(j) != assist->commander()) {
                                            RGE_Static_Object* defenderObj;
                                            defenderObj = this->md->object(assist->unit(j));
                                            if (defenderObj != 0) {
                                                this->taskDefender(assist->unit(j), assist->commander(), defenderObj->master_obj->los * 0.5f, 99);
                                            }
                                        }
                                        j++;
                                    }
                                }
                            }
                            goto clear_attack_state;
                        } else {
                            goto reset_action10;
                        }
                    } else {
                        goto reset_action10;
                    }
                } else if (cur->action() == 0x10) {
                    TacticalAIGroup* assist;
                    assist = this->group(cur->assistGroupID(), -1, -1, -1);
                    if (assist != 0) {
                        RGE_Static_Object* transportObj;
                        transportObj = this->md->object(assist->commander());
                        if (transportObj != 0 && transportObj->unitAI() != 0 && transportObj->owner->id == this->md->player->id) {
                            int i;
                            int allOutside;
                            int needReset;
                            allOutside = 1;
                            needReset = 1;
                            i = 0;
                            while (i < cur->numberUnits()) {
                                int unit_id;
                                RGE_Static_Object* unitObj2;
                                unit_id = cur->unit(i);
                                unitObj2 = this->md->object(unit_id);
                                if (unitObj2 != 0 && unitObj2->unitAI() != 0) {
                                    if (unitObj2->inside_obj == 0) {
                                        allOutside = 0;
                                        if (cur->type() == 100) {
                                            RGE_Static_Object* targetObj;
                                            targetObj = this->md->object(cur->target());
                                            if (targetObj != 0) {
                                                UnitAIModule* attackAI;
                                                attackAI = unitObj2->unitAI();
                                                if (attackAI->currentTarget() != cur->target()) {
                                                    if (unitObj2->canAttack(
                                                            cur->target(), unitObj2->weaponRange(),
                                                            0, 1, -1, -1) == 1) {
                                                        this->taskAttacker(cur->unit(i),
                                                            cur->targetLocation().x,
                                                            cur->targetLocation().y,
                                                            cur->target(), -1, 0, 0, -1, 0);
                                                    }
                                                }
                                            } else {
                                                this->stopUnit(cur->unit(i), 100);
                                            }
                                        } else {
                                            this->stopUnit(cur->unit(i), 100);
                                        }
                                    } else {
                                        needReset = 0;
                                    }
                                }
                                i++;
                            }
                            if (allOutside == 1) {
                                if (transportObj->actions->have_action() == 0 || transportObj->actions->get_action()->state == 2) {
                                    const Waypoint* loc;
                                    float transportX;
                                    float transportY;
                                    loc = &assist->targetLocation();
                                    transportY = loc->y + 0.5f;
                                    loc = &assist->targetLocation();
                                    transportX = loc->x + 0.5f;
                                    this->taskTransporter(assist->commander(), transportX, transportY);
                                    assist->setAction(0x0c);
                                }
                                goto clear_attack_state;
                            } else if (needReset != 0) {
                                TacticalAIGroup* resetAssist;
                                resetAssist = this->group(cur->assistGroupID(), -1, -1, -1);
                                if (resetAssist != 0) {
                                    resetAssist->setTarget(-1);
                                    resetAssist->setTargetType(-1);
                                    resetAssist->setAction(1);
                                    resetAssist->setInUse(0);
                                    RGE_Static_Object* relicObj;
                                    relicObj = this->md->object(-1, 0x6d, -1, -1, -1, -1, -1, -1, -1, -1);
                                    if (relicObj != 0) {
                                        this->moveUnit(resetAssist->commander(), relicObj->world_x, relicObj->world_y, 50);
                                    }
                                }
                                if (cur->type() == 100) {
                                    RGE_Static_Object* commanderObjT;
                                    commanderObjT = this->md->object(cur->commander());
                                    if (commanderObjT == 0) {
                                        goto action10_attack_failure;
                                    } else {
                                        if (commanderObjT->canAttack(
                                                cur->target(), commanderObjT->weaponRange(),
                                                0, 1, -1, -1) == 1) {
                                            this->lastGroupAttackTime = this->md->player->world->world_time;
                                            if (this->sn[0x47] == 1) {
                                                this->lastAttackResponseTime = this->md->player->world->world_time;
                                            }
                                            cur->setAction(2);
                                            cur->task(this, this->md, cur->action(), 1, 0);
                                            goto clear_attack_state;
                                        } else {
action10_attack_failure:
                                            cur->setInUse(1);
                                            cur->setAction(7);
                                            cur->task(this, this->md, 7, 0, 1);
                                            goto clear_attack_state;
                                        }
                                    }
                                } else {
                                    if (cur->type() != 0x65 && cur->type() != 0x6d) {
                                        goto loss_check;
                                    }
                                    const Waypoint* tloc;
                                    float gatherX;
                                    float gatherY;
                                    float gatherZ;
                                    tloc = &cur->targetLocation();
                                    gatherZ = tloc->z;
                                    tloc = &cur->targetLocation();
                                    gatherY = tloc->y;
                                    tloc = &cur->targetLocation();
                                    gatherX = tloc->x;
                                    cur->setGatherLocation(gatherX, gatherY, gatherZ);
                                    cur->setInUse(0);
                                    cur->setAction(1);
                                    cur->task(this, this->md, 1, 1, 1);
                                    this->attackStateValue.active = 0;
                                    goto ContinueLoop;
                                }
                            } else {
                                goto clear_attack_state;
                            }
                        } else {
                            goto reset_action10;
                        }
                    } else {
reset_action10:
                        cur->setTarget(-1);
                        cur->numberObjectsToDestroyValue = 0;
                        cur->setTargetType(-1);
                        cur->setAction(1);
                        cur->setInUse(0);
                        this->attackStateValue.active = 0;
                    }
                } else {
                    if (cur->action() == 0x0c) goto action0c;
                    if (cur->action() == 0x13) goto action13;
                    if (cur->action() == 3) goto action3;
                    if (cur->action() == 7) {
                    RGE_Static_Object* commanderObj3;
                    RGE_Static_Object* targetObj;
                    int* players;

                    commanderObj3 = this->md->object(cur->commander());
                    if (this->playersToAttack.maximumSizeValue - 1 < 0) {
                        int* newPlayers;
                        newPlayers = (int*)operator_new(4);
                        if (newPlayers != 0) {
                            int k;
                            k = 0;
                            while (k < this->playersToAttack.maximumSizeValue && k < 1) {
                                newPlayers[k] = this->playersToAttack.value[k];
                                k++;
                            }
                            operator_delete(this->playersToAttack.value);
                            this->playersToAttack.value = newPlayers;
                            this->playersToAttack.maximumSizeValue = 1;
                        }
                    }
                    players = this->playersToAttack.value;
                    mem = this->md->informationAI.objectToAttackByGroup(*players, cur, &this->attackStateValue, param_1);
                    if (this->attackStateValue.active == 1) {
                        this->nextActiveSoldierGroupToTaskValue = cur->id();
                        return;
                    }
                    targetObj = 0;
                    if (mem != 0) {
                        targetObj = this->md->object(mem->id);
                    }
                    if (commanderObj3 == 0 || mem == 0 || targetObj == 0) {
                        goto action7_timeout;
                    } else {
                        float pathOut;
                        float attackRange7;
                        XYZPoint targetPoint7;
                        targetPoint7.x = mem->x;
                        targetPoint7.y = mem->y;
                        targetPoint7.z = mem->z;
                        attackRange7 = commanderObj3->weaponRange();
                        if (commanderObj3->canPath(targetPoint7,
                                attackRange7, mem->id,
                                &pathOut, 1, mem->owner, 0x1b) == 1) {
                            cur->setAction(2);
                            cur->setTarget(mem->id);
                            cur->setTargetType((int)mem->type);
                            cur->setTargetLocation((float)mem->x, (float)mem->y, (float)mem->z);
                            cur->setInUse(1);
                            cur->task(this, this->md, 2, 0, 1);
                            this->attackStateValue.active = 0;
                            goto ContinueLoop;
                        } else {
                            char aux7[4];
                            float gather7;
                            if (commanderObj3->canPathWithAdditionalPassability(
                                    targetPoint7, attackRange7,
                                    mem->id, &pathOut, 1, 0x16, 1,
                                    mem->owner, 0x1b) == 1 &&
                                commanderObj3->findFirstTerrainAlongExceptionPath(
                                    2, &gather7, (float*)aux7) == 1) {
                                cur->task(this, this->md, 0x0e, 1, 0);
                                cur->setAction(0x0d);
                                cur->setTarget(mem->id);
                                cur->setTargetType((int)mem->type);
                                cur->setTargetLocation((float)mem->x,
                                                       (float)mem->y,
                                                       (float)mem->z);
                                cur->setInUse(1);
                                cur->setWaitCode(200);
                                cur->playNumberValue = -1;
                                goto clear_attack_state;
                            } else {
                                goto action7_timeout;
                            }
                        }
                    }
                    goto action7_done;
action7_timeout:
                    {
                        unsigned long idle;
                        idle = cur->consecutiveIdleUnitCount();
                        if ((this->md->player->world->world_time - idle) / 1000 >
                            ((unsigned int)this->sn[0x58] << 2)) {
                            cur->setAction(7);
                            cur->task(this, this->md, 7, 0, 1);
                            goto clear_attack_state;
                        }
                    }
action7_done:
                    goto loss_check;
                } else if (cur->action() == 2) {
                    RGE_Static_Object* targetObj2;
                    int targetType;
                    int i;

                    if (cur->playNumberValue == -1) {
                    if (this->sn[0x5b] < 100) {
                        i = 0;
                        while (i < cur->numberUnits()) {
                            int unit_id;
                            RGE_Static_Object* unitObj2;
                            unit_id = cur->unit(i);
                            unitObj2 = this->md->object(unit_id);
                            if (unitObj2 != 0) {
                                int oldhp;
                                int curhp;
                                oldhp = cur->unitOriginalHitPoints(i);
                                curhp = (int)unitObj2->hp;
                                if (((oldhp - curhp) * 100) / cur->unitOriginalHitPoints(i) > this->sn[0x5b]) {
                                    const Waypoint* retreat;
                                    float retreatX;
                                    float retreatY;
                                    retreat = &cur->retreatLocation();
                                    retreatY = retreat->y;
                                    retreat = &cur->retreatLocation();
                                    retreatX = retreat->x;
                                    this->moveUnit(cur->unit(i), retreatX, retreatY, 100);
                                    cur->removeUnit(cur->unit(i), this->md);
                                    if (cur->numberUnits() == 0) {
                                        break;
                                    }
                                } else {
                                    i++;
                                }
                            } else {
                                i++;
                            }
                        }
                    }

                    targetObj2 = this->md->object(cur->target());
                    if (targetObj2 == 0 || targetObj2->object_state > 2) {
                        ObjectMemory* replacement;
                        RGE_Static_Object* replacementCommander;
                        int* players2;
                        if (this->sn[0x31] == 2) {
                            cur->setAction(1);
                            cur->setTarget(-1);
                            cur->numberObjectsToDestroyValue = 0;
                            cur->setTargetType(-1);
                            cur->setTargetLocation(-1.0f, -1.0f, -1.0f);
                            cur->task(this, this->md, cur->action(), 1, 0);
                            this->attackStateValue.active = 0;
                            goto ContinueLoop;
                        } else {
                            replacementCommander = this->md->object(cur->commander());
                            if (replacementCommander == 0) {
                                this->attackStateValue.active = 0;
                                goto ContinueLoop;
                            }
                            if (this->playersToAttack.maximumSizeValue - 1 < 0) {
                                int* newPlayers;
                                newPlayers = (int*)operator_new(4);
                                if (newPlayers != 0) {
                                    int k;
                                    k = 0;
                                    while (k < this->playersToAttack.maximumSizeValue && k < 1) {
                                        newPlayers[k] = this->playersToAttack.value[k];
                                        k++;
                                    }
                                    operator_delete(this->playersToAttack.value);
                                    this->playersToAttack.value = newPlayers;
                                    this->playersToAttack.maximumSizeValue = 1;
                                }
                            }
                            players2 = this->playersToAttack.value;
                            replacement = this->md->informationAI.objectToAttackByGroup(
                                *players2, cur, &this->attackStateValue, param_1);
                            if (this->attackStateValue.active == 1) {
                                this->nextActiveSoldierGroupToTaskValue = cur->id();
                                return;
                            }
                            if (replacement != 0) {
                                float path2;
                                XYZPoint replacementPoint;
                                replacementPoint.x = replacement->x;
                                replacementPoint.y = replacement->y;
                                replacementPoint.z = replacement->z;
                                if (replacementCommander->canPath(replacementPoint,
                                        replacementCommander->weaponRange(),
                                        replacement->id, &path2, 1, replacement->owner, 0x1b) == 1) {
                                    cur->setTarget(replacement->id);
                                    cur->setTargetType((int)replacement->type);
                                    cur->setTargetLocation((float)replacement->x, (float)replacement->y, (float)replacement->z);
                                    cur->setInUse(1);
                                    cur->task(this, this->md, 2, 0, 0);
                                    this->attackStateValue.active = 0;
                                    goto ContinueLoop;
                                }
                            }
                            targetType = cur->targetType();
                            cur->setInUse(0);
                            cur->setAction(1);
                            cur->setTarget(-1);
                            cur->numberObjectsToDestroyValue = 0;
                            cur->setTargetType(-1);
                            cur->setTargetLocation(-1.0f, -1.0f, -1.0f);
                            if (this->sn[0x31] == 0) {
                                cur->setGatherLocation(replacementCommander->world_x,
                                                       replacementCommander->world_y,
                                                       replacementCommander->world_z);
                            } else if (this->sn[0x31] == 3 &&
                                       targetType != 0x7e && targetType != 0x59) {
                                if (this->sn[0x87] == 1) {
                                    int cx;
                                    int cy;
                                    int radius;
                                    cx = (int)replacementCommander->world_x;
                                    cy = (int)replacementCommander->world_y;
                                    radius = this->sn[0x88];
                                    this->md->informationAI.blotExploredMap(cx - radius, cy - radius, cx + radius, cy + radius);
                                }
                                cur->setInUse(1);
                                cur->setAction(7);
                                cur->task(this, this->md, 7, 0, 1);
                                this->attackStateValue.active = 0;
                                goto ContinueLoop;
                            }
                            goto clear_attack_state;
                        }
                    } else if (cur->subType() != -1) {
                        unsigned long idle;
                        if (cur->subType() != 0 && cur->subType() == 4 &&
                            targetObj2->owner->id == this->md->player->id &&
                            this->md->isMoveable(targetObj2->id)) {
                            Waypoint p1;
                            Waypoint p2;
                            float mx;
                            float my;
                            float mz;
                            cur->addUnit(targetObj2->id, this->md);
                            p1 = *this->md->strategyAI.targetPoint1();
                            p2 = *this->md->strategyAI.targetPoint2();
                            mx = (p1.x + p2.x) * 0.5f;
                            my = (p1.y + p2.y) * 0.5f;
                            mz = (p1.z + p2.z) * 0.5f;
                            cur->setInUse(0);
                            cur->setAction(1);
                            cur->setTarget(-1);
                            cur->numberObjectsToDestroyValue = 0;
                            cur->setTargetType(-1);
                            cur->setTargetLocation(-1.0f, -1.0f, -1.0f);
                            cur->setGatherLocation(mx, my, mz);
                        }
                        idle = cur->consecutiveIdleUnitCount();
                        if ((this->md->player->world->world_time - idle) / 1000 >
                            (unsigned int)this->sn[0x4c]) {
                            cur->setInUse(0);
                            cur->setAction(1);
                            cur->setTarget(-1);
                            cur->setTargetType(-1);
                            cur->setTargetLocation(-1.0f, -1.0f, -1.0f);
                            cur->numberObjectsToDestroyValue = 0;
                            this->attackStateValue.active = 0;
                            goto ContinueLoop;
                        }
                    } else {
                        if (this->md->player->isEnemy(
                                targetObj2->owner->id) != 0) {
                            RGE_Static_Object* commanderObj8;
                            cur->setInUse(0);
                            cur->setAction(1);
                            cur->setTarget(-1);
                            cur->setTargetType(-1);
                            cur->setTargetLocation(-1.0f, -1.0f, -1.0f);
                            cur->numberObjectsToDestroyValue = 0;
                            commanderObj8 = this->md->object(cur->commander());
                            if (commanderObj8 != 0) {
                                cur->setGatherLocation(commanderObj8->world_x,
                                                       commanderObj8->world_y,
                                                       commanderObj8->world_z);
                            }
                            goto clear_attack_state;
                        } else {
                            if (cur->allUnitsIdle(this->md, 0) != 1) {
                                cur->task(this, this->md, 0x14, 0, 1);
                                this->attackStateValue.active = 0;
                                goto ContinueLoop;
                            } else {
                                RGE_Static_Object* commanderObj4;
                                commanderObj4 = this->md->object(cur->commander());
                                if (commanderObj4 == 0) {
                                    this->attackStateValue.active = 0;
                                    goto ContinueLoop;
                                } else if (commanderObj4->canAttack(
                                               cur->target(),
                                               commanderObj4->weaponRange(),
                                               0, 1, -1, -1) == 1) {
                                    cur->task(this, this->md, 0x14, 0, 1);
                                    this->attackStateValue.active = 0;
                                    goto ContinueLoop;
                                } else {
                                    cur->setGatherLocation(commanderObj4->world_x,
                                                           commanderObj4->world_y,
                                                           commanderObj4->world_z);
                                    cur->setInUse(0);
                                    cur->setAction(1);
                                    cur->setTarget(-1);
                                    cur->setTargetType(-1);
                                    cur->numberObjectsToDestroyValue = 0;
                                    cur->setTargetLocation(-1.0f, -1.0f, -1.0f);
                                    goto clear_attack_state;
                                }
                            }
                        }
                    }
                    }
                    if (cur->action() == 2 && cur->playNumberValue != -1) {
                        RGE_Static_Object* commanderObj9;
                        commanderObj9 = this->md->object(cur->commander());
                        if (commanderObj9 != 0 && commanderObj9->unitAI() != 0 && commanderObj9->unitAI()->playStatus == 0) {
                            cur->playNumberValue = -1;
                            this->attackStateValue.active = 0;
                        }
                        goto clear_attack_state;
                    }
                    goto loss_check;
                } else if (cur->action() == 4) {
                    if (cur->allUnitsIdle(this->md, 1) != 1 || cur->isGathered(this, this->md) != 0) {
                        RGE_Static_Object* targetObj4;
                        targetObj4 = this->md->object(cur->target());
                        if (targetObj4 != 0) {
                            ObjectMemory* higher;
                            higher = this->md->informationAI.higherPriorityObjectToDefend(cur->commander(), cur->targetType(), (int)targetObj4->master_obj->object_group);
                            if (higher == 0) {
                                goto loss_check;
                            }
                            ObjectMemory* oldTarget;
                            oldTarget = this->md->informationAI.objectMemory(cur->target());
                            if (oldTarget != 0) {
                                oldTarget->attackAttempts = 0;
                            }
                            cur->setAction(1);
                            cur->setInUse(0);
                            goto clear_attack_state;
                        } else {
                            cur->setAction(1);
                            cur->setInUse(0);
                            goto clear_attack_state;
                        }
                    } else {
                        cur->task(this, this->md, 9, 1, 0);
                        this->attackStateValue.active = 0;
                        goto ContinueLoop;
                    }
                    } else {
                        goto loss_check;
                    }
                    goto active_dispatch_done;
action0c:
                    this->attackStateValue.active = 0;
                    goto ContinueLoop;
action13:
                    {
                    if (cur->isGathered(this, this->md) == 0) {
                        int allIdle;
                        unsigned long idle;
                        unsigned long elapsed;
                        idle = cur->consecutiveIdleUnitCount();
                        elapsed = (this->md->player->world->world_time - idle) / 1000;
                        allIdle = cur->allUnitsIdle(this->md, 1);
                        if (allIdle == 1 && 5 < elapsed) {
                            cur->setConsecutiveIdleUnitCount(this->md->player->world->world_time);
                            cur->task(this, this->md, 9, 1, 0);
                            this->attackStateValue.active = 0;
                            goto ContinueLoop;
                        }
                    }
                    }
                    goto clear_attack_state;
action3:
                    {
                    unsigned long idle;
                    idle = cur->consecutiveIdleUnitCount();
                    if ((this->md->player->world->world_time - idle) / 1000 >
                        (unsigned int)this->sn[0x4c]) {
                        cur->setInUse(0);
                        cur->setAction(1);
                        cur->setTarget(-1);
                        cur->numberObjectsToDestroyValue = 0;
                        cur->setTargetType(-1);
                        cur->setTargetLocation(-1.0f, -1.0f, -1.0f);
                        this->attackStateValue.active = 0;
                        goto ContinueLoop;
                    } else {
                        if (cur->isGathered(this, this->md) == 0) {
                            goto loss_check;
                        }
                        cur->setAction(1);
                        cur->setInUse(0);
                        if (cur->type() == 0x65 || cur->type() == 0x68) {
                            ObjectMemory* oldTarget;
                            oldTarget = this->md->informationAI.objectMemory(cur->target());
                            if (oldTarget != 0) {
                                oldTarget->attackAttempts = 0;
                            }
                        }
                        if (this->md->buildAI.buildListLength() == 0 &&
                            ((cur->type() == 100 && this->numberGroups(100, -1) > 1) || cur->type() != 100)) {
                            if (cur->type() == 0x66) {
                                this->sn[0x2a] = this->sn[0x2a] - 1;
                            } else if (cur->type() == 0x65) {
                                this->sn[0x26] = this->sn[0x26] - 1;
                            } else if (cur->type() == 100) {
                                this->sn[0x24] = this->sn[0x24] - 1;
                            }
                            cur->removeUnits(this->md);
                            cur->setAction(0);
                            this->attackStateValue.active = 0;
                        } else {
                            this->attackStateValue.active = 0;
                        }
                        goto ContinueLoop;
                    }
                    }
                    goto active_dispatch_done;
loss_check:
                    {
                    if (cur->action() != 3 && cur->action() != 0x0d) {
                        int hpLoss;
                        int currentHitPoints;
                        int originalHitPoints;
                        int currentUnits;
                        int originalUnits;
                        int unitLoss;

                        currentHitPoints = cur->currentHitPoints(this->md);
                        originalHitPoints = cur->originalHitPoints();
                        hpLoss = ((originalHitPoints - currentHitPoints) * 100) /
                                 cur->originalHitPoints();
                        currentUnits = cur->numberUnits();
                        originalUnits = cur->originalUnitNumber();
                        unitLoss = ((originalUnits - currentUnits) * 100) /
                                   cur->originalUnitNumber();
                        if (hpLoss > this->sn[0x1e] || unitLoss > this->sn[0x1f]) {
                            cur->setAction(3);
                            cur->task(this, this->md, cur->action(), 1, 0);
                            goto clear_attack_state;
                        }
                    }
                    }
active_dispatch_done:
                    ;
                }
            }

            goto ContinueLoop;
clear_attack_state:
            this->attackStateValue.active = 0;
            goto ContinueLoop;
ContinueLoop:
            if (this->attackStateValue.active != 0) {
                return;
            }
            cur = cur->next;
            if (cur == &this->groups || !cur) {
                this->nextActiveSoldierGroupToTaskValue = -1;
            } else {
                this->nextActiveSoldierGroupToTaskValue = cur->id();
            }
            if (debug_timeGetTime(s_C__msdev_work_age1_x1_taitacmd_c, 0x14fe) - param_1 >= param_2) {
                return;
            }
        } while (cur != &this->groups);
    }
    this->nextActiveSoldierGroupToTaskValue = -1;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F4760_playTaskSoldiers.cpp
// ---------------------------------------------------------------------------
// 004F4760 TribeTacticalAIModule::playTaskSoldiers
// Initial decomp from packet. Attempt log:
// 1: natural source from Ghidra; compiles, same 823-byte size, but broad mismatch (80.56% positional / 93.68% edit).
// 2: changed outer sn_a2 guard to explicit early-return form; no byte/codegen change.
// 3: moved i declaration/initialization later; no byte/codegen change.
// 4: probed a volatile frame pad to recover original 0x1A4 frame; unused volatile optimized away, no change; rolled back.
// 5: current main blocker is first hunk: rebuilt frame is 0x1A0 not 0x1A4 and zero local is hoisted before push edi.
// 6: first soldier loop also uses edi=i+1 and ebp as byte offset; original uses ebp as integer index and ebx as i+1/new max.
// 7: array growth/copy behavior and later call sequence are semantically represented, but local/register topology is still wrong.
// 8: restored the period ManagedArray operator[] growth/copy surface and the typed informationAI subobject; this is the clean structural probe.
// Prior liveness probes: a count-first assignment changed the whole basin; a
// named element pointer and declaration reorder were codegen duplicates.
// A side-effectful soldiers[i] capacity ensure followed by direct value access
// recovered the target's count/load/store interleave.
// unplayedSoldiers[51] fixed the frame but shifted the play-unit argument;
// rolled back. playUnits[51] preserves the binary's reserved leading output
// slot and 0x1A4 local window; exact 823-byte match.
// Exact: default /O2 /Oy, 823/823 bytes, 22/22 calls, no custom flags or inline asm.


extern "C" {
    void* __cdecl operator_new(unsigned int size);
    void __cdecl operator_delete(void* ptr);
}


void TribeTacticalAIModule::playTaskSoldiers(unsigned long param_1,
                                              unsigned long param_2)
{
    int* target;
    int countUnplayedSoldiers;
    ObjectMemory* targetObj;
    int* numberPlayUnits;
    int playCommander;
    int playToRun;
    int unplayedSoldiers[50];
    // objectToAttackWithPlay receives element one; the binary reserves the
    // leading output word and the full 0xCC play-unit stack window.
    int playUnits[51];
    int i;

    ManagedArray<int>& soldiers = this->soldiers;

    if (this->sn[0xa2] != 0) {
        countUnplayedSoldiers = 0;
        i = 0;
        if (soldiers.numberValue > 0) {
            numberPlayUnits = unplayedSoldiers + 1;
            do {
                TacticalAIGroup* group =
                    this->groupUnitIsIn(soldiers[i]);
                if ((group == 0) || (group->type() != 100)) {
                    soldiers[i];
                    countUnplayedSoldiers++;
                    *numberPlayUnits = soldiers.value[i];
                    numberPlayUnits++;
                }
                i++;
            } while (i < soldiers.numberValue);
        }

        if (countUnplayedSoldiers != 0) {
            unplayedSoldiers[0] = -1;
            playCommander = 0;
            playToRun = -1;
            targetObj = this->md->informationAI.objectToAttackWithPlay(
                this->playersToAttack[0], unplayedSoldiers + 1,
                countUnplayedSoldiers, unplayedSoldiers, playUnits + 1,
                &playCommander, &playToRun);
            if (targetObj != 0) {
                RGE_Static_Object* playObj = this->md->object(playToRun);
                if (playObj != 0) {
                    TacticalAIGroup* group = this->createGroup(1);
                    if (group != 0) {
                        group->setType(100);
                        group->setDesiredNumberUnits(playCommander);
                        int n = 0;
                        if (playCommander > 0) {
                            target = playUnits + 1;
                            do {
                                group->addUnit(*target, this->md);
                                n++;
                                target++;
                            } while (n < playCommander);
                        }
                        group->setSpecificCommander(playToRun, this->md);
                        group->setLocation(playObj->world_x, playObj->world_y,
                                           playObj->world_z);
                        group->setGatherLocation(playObj->world_x,
                                                 playObj->world_y,
                                                 playObj->world_z);
                        group->setRetreatLocation(playObj->world_x,
                                                  playObj->world_y,
                                                  playObj->world_z);
                        group->setTarget(targetObj->id);
                        group->playNumberValue = unplayedSoldiers[0];
                        group->setAction(2);
                        group->setInUse(1);
                        group->task(this, this->md, 2, 1, 1);
                    }
                }
            }
        }
    }
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F4AA0_taskUngroupedSoldiers.cpp
// ---------------------------------------------------------------------------
// VA: 004F4AA0 TribeTacticalAIModule::taskUngroupedSoldiers
// PDB source: taitacmd.cpp lines 5522-5565
//
// CodeView proves i at -0x1C, soldierObj at -0x14, centerPoint at -0x10,
// and gatherPoint at -0x08. The move destination uses gatherPoint.x and y.
//
// The protected ManagedArray layout requires the public number, operator[],
// contains, add, and remove methods. The outer for-loop and direct
// findGatherPosition predicate are codegen-active. A named result changes
// inlined add allocation and loses exactness. Direct member expressions, the
// contains predicate spelling, and the two local declaration orders tested in
// reduction are incidental.
//
// BINARY NOTE: contains checks membership before add. Inlined add performs its
// own duplicate scan. Both scans are present in the original executable.
//
// SHARED-CONTEXT NOTE: the tactical header's nested operator[] growth changes
// this body from 740 to 852 bytes. The canonical utmarray.h surface keeps the
// resize calls out of line and preserves the exact body. Using that surface in
// the shared wrapper regresses earlier exact anchors, so this owner stays out.



void TribeTacticalAIModule::taskUngroupedSoldiers()
{
    int i;
    XYPoint centerPoint;
    RGE_Static_Object* soldierObj;
    XYPoint gatherPoint;

    unsigned long currentTime = this->md->player->world->world_time;
    if ((currentTime - this->lastUngroupedSoldierTaskTime) / 1000 >= 60) {
        this->lastUngroupedSoldierTaskTime = currentTime;
        soldierObj = this->md->object(
            -1, 0x6D, -1, -1, -1, -1, -1, -1, -1, -1);
        if (soldierObj != 0) {
            centerPoint.x = (int)soldierObj->world_x;
            centerPoint.y = (int)soldierObj->world_y;
            for (i = 0; i < this->soldiers.number(); i++) {
                if (this->groupUnitIsIn(this->soldiers[i]) != 0) {
                    this->ungroupedSoldiers.remove(this->soldiers[i]);
                }
                else {
                    soldierObj = this->md->object(this->soldiers[i]);
                    if (soldierObj != 0) {
                        if (this->ungroupedSoldiers.contains(
                                this->soldiers[i]) == 0) {
                            this->ungroupedSoldiers.add(this->soldiers[i]);
                            if (this->md->informationAI.findGatherPosition(
                                    centerPoint, 1, 1,
                                    this->sn[0x16], this->sn[0x48],
                                    soldierObj, gatherPoint) == 1) {
                                this->moveUnit(
                                    this->soldiers[i],
                                    (float)gatherPoint.x,
                                    (float)gatherPoint.y, 0x32);
                            }
                        }
                    }
                }
            }
        }
    }
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F4D90_taskBoats.cpp
// ---------------------------------------------------------------------------
// 004F4D90 TribeTacticalAIModule::taskBoats
// Source: taitacmd.cpp lines 5570-6037
// Attempt log:
// - baseline reconstruction: restored the period tactical-AI ownership model
//   (md at +0xF0, embedded informationAI at md+0xCEC, groups sentinel at
//   +0x9D4, and the ten ManagedArray<int> buckets) and the two ordered group
//   passes from the binary.  The remaining work is codegen/layout tuning after
//   validating this call/order surface.
// - probe 2 control-flow: inverted the first ready/task arms and used explicit
//   while(1) sentinel exits; this recovered the original loop-top null check.
// - probe 3 behavior: restored the second commander() evaluation before the
//   water fully-explored gate.
// - probe 4 behavior: restored the no-target water fallback to setAction(1).
// - probe 5 control-flow: joined completed not-in-use branches at the outer
//   loop tail instead of falling into action-10/11 checks.
// - probe 6 behavior: kept separate commander() evaluations for trade lookup
//   and the trade fully-explored gate.
// - probe 7 control-flow: sent action-10 target-null and found-reset exits to
//   the outer loop; replaced the found-reset null-object return with next-group.
// - probe 8 behavior: restored task(...,1,0) after a valid water target is
//   installed, as required by the executable's shared task tail.
// - probe 9 diagnostic shared-coordinate tail: a goto with three new float
//   locals raised the frame to 0x6C and was restored; no codegen-only variant
//   is retained.
// - ABI/layout probes: replaced the rejected padded/vf virtual scaffolding with
//   named canonical RGE/AIModule surfaces, corrected AIModule to 0xF0, and
//   declared the XYZPoint canPath overload before the integer overload.
// - behavior probe: removed a repeated water type() test; the outer 0x6B
//   branch already proves the fallback type and the original has no second
//   virtual type call there.
// - layout probe: reused the existing water/trade float slots for a shared
//   target-location tail; this matches the single original setTargetLocation
//   site without the 0x6C frame introduced by new target locals.
// - control-flow probe: found-reset action 8 falls through into later action
//   checks (the original does not jump to next_group after its task call).
// - final control-flow probe: carried busyOK into the canonical shared task
//   tail for default/target/action-11 paths and skipped setAction for unknown
//   first-pass types.  This resolves the task/action/type/target-location call
//   count gaps while keeping frame 0x60.  The best validated source remains in
//   scratch: 2070 differing bytes, 93.21% shape, 97.87% ordered calls, and
//   frame 0x60.  The remaining aggregate gap is one setAction and one setInUse
//   call.  The residual drift is concentrated in local homes and shared tails.
// - probes 1-20: direct setAction arms, positive water-count layout, direct
//   target-location expressions, and branch-local float scopes improved the
//   natural source.  Literal task-tail rewrites, extra found-path gotos, and
//   header context changes were rejected by the checker.
// - BINARY NOTE: the executable has one physical setTargetLocation call site
//   for the resource/trade target setup.  Keep those coordinates as direct
//   arguments so VC5 can share the tail without extra float reloads.
// - LIKELY INTENT: the action-8 found reset is a separate task path.  Its
//   current natural source retains the direct task call while later checks can
//   still run, but the executable uses a shared tail instead.
// - ManagedArray recovery audit, 2026-08-19: this function does not access a
//   tactical ManagedArray field or call one of its methods. The array members
//   only establish later class offsets, which the current 16-byte layout
//   already models. No shared-header migration applies to this target.
// - claim probes, 2026-08-22: routing the action-8 found reset to the shared
//   task tail worsened the result to 2122 bytes; explicit fallback exits were
//   codegen-neutral; bool ready and positive-ready CFG variants worsened to
//   2278 and 2203 bytes. Restored the clean 2070-byte source.
// - final validation, 2026-08-22: 2598 rebuilt bytes, 0x60 frame, 93.21%
//   shape, 97.87% ordered calls, 2070 differing bytes. Result remains
//   MISMATCH. Missing physical calls are one setAction and one setInUse.


void TribeTacticalAIModule::taskBoats()
{
    TacticalAIGroup* group;
    TacticalAIGroup* sentinel;
    int busyOK;

    group = this->groups.next;
    sentinel = &this->groups;
    if (group != sentinel) {
        while (1) {
            if (group == 0) {
                break;
            }

            if (group->type() != 100 && group->type() != 101 &&
                group->type() != 102 && group->type() != 103 &&
                group->type() != 104 && group->type() != 105 &&
                (group->action() == 0 || group->action() == 1)) {
                int ready = 1;
                int gathered = group->isGathered(this, this->md);
                int number = group->numberUnits();
                int desired = group->desiredNumberUnits();

                if (number < desired ||
                    (gathered == 0 && group->numberUnits() > 1) ||
                    group->allUnitsIdle(this->md, 1) == 0) {
                    ready = 0;
                }

                if (ready == 0) {
                    if (gathered == 0) {
                        group->task(this, this->md, 9, 1, 0);
                    }
                }
                else {
                    if (group->type() == 0x6B) {
                        group->setAction(10);
                    }
                    else if (group->type() == 0x6C) {
                        group->setAction(11);
                    }
                    else if (group->type() == 0x6A) {
                        group->setAction(1);
                    }
                    else {
                        goto first_pass_next;
                    }
                }
            }

first_pass_next:
            group = group->next;
            if (group == sentinel) {
                break;
            }
        }
    }

    group = this->groups.next;
    if (group != sentinel) {
        while (1) {
            if (group == 0) {
                return;
            }

            if (group->type() != 100 && group->type() != 101 &&
                group->type() != 102 && group->type() != 103 &&
                group->type() != 104 && group->type() != 105 &&
                group->action() != 0 && group->action() != 1) {
                if (group->inUse() == 0) {
                    if (group->type() == 0x6B) {
                        float outputX;
                        float outputY;
                        int commanderID = group->commander();
                        RGE_Static_Object* commander = this->md->object(commanderID);
                        if (commander == 0) {
                            group->setAction(1);
                        }
                        else {
                            int resourceID = -1;
                            int resourceMode = -1;
                            int exclusionCount = 0;
                            int exclusionIndex = 0;
                            int exclusions[5];
                            int pathOK;

                            if (this->numberWaterExplorers() > 0) {
                                if (this->md->informationAI.fullyExploredZone(
                                        group->commander()) == 1) {
                                    do {
                                        outputX = 0.0f;
                                        outputY = 0.0f;
                                        resourceMode = -1;
                                        resourceID = this->md->informationAI.gameIDOfResourceObject(
                                            0, commander->id, outputX, outputY, resourceMode,
                                            exclusions + 1, exclusionCount);

                                        XYZPoint point;
                                        point.x = (int)outputX;
                                        point.y = (int)outputY;
                                        point.z = (int)commander->world_z;

                                        if (resourceMode == -1) {
                                            pathOK = commander->canPath(point, 1.0f,
                                                                         resourceID, 0,
                                                                         1, -1, -1);
                                        }
                                        else {
                                            pathOK = commander->canBidirectionPath(
                                                resourceID, resourceMode, 1.0f, 0,
                                                1, -1, -1);
                                        }

                                        if (pathOK == 0) {
                                            exclusions[exclusionCount] = resourceID;
                                            ++exclusionCount;
                                        }
                                        ++exclusionIndex;
                                    } while (pathOK != 1 && exclusionIndex < 5);
                                }
                            }

                            RGE_Static_Object* object = this->md->object(resourceID);
                            if (resourceID >= 0 && object != 0) {
                                group->setTarget(resourceID);
                                group->setTargetType((int)object->master_obj->id);
                                group->setTargetLocation(object->world_x,
                                                         object->world_y,
                                                         object->world_z);
                                group->setInUse(1);
                                busyOK = 0;
                                goto task_tail;
                            }
                            else {
                                if (this->md->informationAI.fullyExploredZone(
                                        group->commander()) == 1) {
                                    group->setAction(8);
                                    group->task(this, this->md,
                                                group->action(), 1, 0);
                                    group->setInUse(1);
                                }
                                else {
                                    group->setAction(1);
                                }
                            }
                        }
                    }
                    else if (group->type() == 0x6C) {
                        int commanderID = group->commander();
                        RGE_Static_Object* commander = this->md->object(commanderID);
                        float pathDistance;
                        if (commander == 0) {
                            group->setAction(1);
                        }
                        else {
                            ObjectMemory* trade =
                                this->md->informationAI.objectToTradeWith(
                                    group->commander());
                            if (trade == 0) {
                                if (this->md->informationAI.fullyExploredZone(
                                        group->commander()) == 1) {
                                    group->setAction(8);
                                    group->task(this, this->md,
                                                group->action(), 1, (int)trade);
                                    group->setInUse(1);
                                }
                                else {
                                    group->setAction(1);
                                }
                            }
                            else {
                                XYZPoint point;
                                point.x = (int)trade->x;
                                point.y = (int)trade->y;
                                point.z = (int)trade->z;
                                if (commander->canPath(point, 1.0f, trade->id,
                                                       &pathDistance, 1, -1, -1) != 0) {
                                    group->setTarget(trade->id);
                                    group->setTargetType((int)trade->type);
                                    group->setTargetLocation((float)trade->x,
                                                             (float)trade->y,
                                                             (float)trade->z);
                                    group->setInUse(1);
                                    busyOK = 0;
                                    goto task_tail;
                                }
                                else {
                                    group->setAction(1);
                                }
                            }
                        }
                    }
                    else {
                        busyOK = 0;
                        goto task_tail;
                    }
                    goto next_group;

                }
                if (group->action() == 8) {
                    int found = 0;

                    if (group->type() == 0x6C) {
                        if (this->md->informationAI.objectToTradeWith(
                                group->commander()) != 0) {
                            found = 1;
                        }
                    }

                    if (group->type() == 0x6B) {
                        if (this->numberWaterExplorers() > 1) {
                            float pathDistance = 0.0f;
                            float outputX = 0.0f;
                            int outputY = -1;
                            int commanderID = group->commander();
                            int resourceID =
                                this->md->informationAI.gameIDOfResourceObject(
                                    0, commanderID, pathDistance, outputX,
                                    outputY, 0, 0);
                            if (resourceID != -1) {
                                found = 1;
                            }
                        }
                        else {
                            RGE_Static_Object* object =
                                this->md->object(group->commander());
                            if (object != 0 && object->unitAI() != 0 &&
                                object->unitAI()->currentOrder() != 0x2C1) {
                                group->setAction(8);
                                group->task(this, this->md,
                                            group->action(), 1, 0);
                                group->setInUse(1);
                            }
                        }
                    }

                    if (found == 1) {
                        RGE_Static_Object* object =
                            this->md->object(group->commander());
                        if (object == 0) {
                            goto next_group;
                        }
                        group->setInUse(0);
                        group->setAction(1);
                        group->setTarget(-1);
                        group->numberObjectsToDestroyValue = 0;
                        group->setTargetType(-1);
                        group->setTargetLocation(-1.0f, -1.0f, -1.0f);
                        group->setGatherLocation(object->world_x,
                                                 object->world_y,
                                                 object->world_z);
                        group->task(this, this->md, group->action(), 1, 0);
                    }
                }

                if (group->action() == 10) {
                    int targetID = group->target();
                    RGE_Static_Object* target = this->md->object(targetID);
                    if (target == 0) {
                        group->setInUse(0);
                        group->setAction(1);
                        group->setTarget(-1);
                        group->setTargetType(-1);
                        group->setTargetLocation(-1.0f, -1.0f, -1.0f);
                        group->numberObjectsToDestroyValue = 0;
                        goto next_group;
                    }
                    else {
                        RGE_Static_Object* commander =
                            this->md->object(group->commander());
                        if (commander != 0 && commander->unitAI() != 0 &&
                            commander->unitAI()->currentAction() == -1) {
                            group->setInUse(0);
                            group->setAction(1);
                            group->setTarget(-1);
                            group->numberObjectsToDestroyValue = 0;
                            group->setTargetType(-1);
                            group->setTargetLocation(-1.0f, -1.0f, -1.0f);
                            group = group->next;
                        }
                    }
                }

                if (group->action() == 11) {
                    int targetID = group->target();
                    RGE_Static_Object* target = this->md->object(targetID);
                    if (target == 0) {
                        group->setInUse(0);
                        group->setAction(1);
                        group->setTarget(-1);
                        group->numberObjectsToDestroyValue = 0;
                        group->setTargetType(-1);
                        group->setTargetLocation(-1.0f, -1.0f, -1.0f);
                    }
                    else {
                        RGE_Static_Object* commander =
                            this->md->object(group->commander());
                        RGE_Static_Object* actionObject = commander;
                        if (actionObject != 0 && actionObject->unitAI() != 0 &&
                            actionObject->unitAI()->currentAction() == -1) {
                            group->setInUse(0);
                            group->setAction(1);
                            group->setTarget(-1);
                            group->numberObjectsToDestroyValue = 0;
                            group->setTargetType(-1);
                            group->setTargetLocation(-1.0f, -1.0f, -1.0f);
                            group = group->next;
                        }
                        else if (actionObject != 0 && actionObject->have_action() != 0) {
                            RGE_Action* action = actionObject->actions->get_action();
                            ObjectMemory* trade =
                                this->md->informationAI.objectToTradeWith(
                                    action->target2ID);
                            if (trade != 0 && trade->id != group->target()) {
                                float pathDistance;
                                XYZPoint point;
                                point.x = (int)trade->x;
                                point.y = (int)trade->y;
                                point.z = (int)trade->z;
                                if (actionObject->canPath(point, 1.0f,
                                                          trade->id,
                                                          &pathDistance, 1,
                                                          -1, -1) == 0) {
                                    group->setAction(1);
                                }
                                else {
                                    group->setTarget(trade->id);
                                    group->setTargetType((int)trade->type);
                                    group->setTargetLocation((float)trade->x,
                                                             (float)trade->y,
                                                             (float)trade->z);
                                    group->setInUse(1);
                                    busyOK = 1;
                                    goto task_tail;
                                }
                            }
                        }
                    }
                }
            }

            goto next_group;
task_tail:
            group->task(this, this->md, group->action(), 1, busyOK);

next_group:
            group = group->next;
            if (group == sentinel) {
                break;
            }
        }
    }
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F57C0_evaluateOpenTasks.cpp
// ---------------------------------------------------------------------------
// 004F57C0 TribeTacticalAIModule::evaluateOpenTasks()
// Source: taitacmd.cpp lines 6042-6189
// Size: 2024 bytes. __thiscall. 62 calls.
//
// Fresh canonical reconstruction.  The ManagedArray indexing below uses the
// same inline utmarray.h operator[] surface as the exact same-TU donors
// 004EA750, 004E3070, 004E3140, and 004F7D90.  Explicit resize() calls are
// retained only at the packet-proven source sites that call 004147A0; the
// parent does not contain compiler-expanded allocation/copy/delete blocks.
//
// Attempt log (luna2-004F57C0):
// - Baseline with the exact donor operator[] surface: 2108B rebuilt, 1967
//   strict diff; recovered the full 62-call family without parent-level grow
//   scaffolding.
// - Corrected the md/player (+0xF0) and informationAI (+0xCEC) ownership,
//   explicit resize/value sites, positive dropsite block order, and combined
//   task-array bounds.  This reduced the rebuilt body to 2052B and 1878B
//   strict diff with 95.99% shape.
// - Scoped the first civilians ManagedArray alias, used the binary-positive
//   x87 gate (`vf61() == 0.0`, double zero), and nested
//   `group(assistGroupID(), -1, -1, -1)` to preserve source call scheduling.
//   Best current: 2043B vs 2024B, 1725B strict diff, 360B edit/resync,
//   97.12% shape, 89.74% exact-block coverage, all 62 calls aligned.
// - Final remaining drift is structural/local-topology: original frame 0x10
//   versus rebuilt 0x8, with the first mismatch at the prologue and one
//   late group-call alignment issue.  No accepted drift or inline asm.
//
// Attempt log (sa-82040434, 2026-08-06):
// - AUDITED the checker's +06F2 "commander vs assistGroupID" direct-target
//   discrepancy: the two call targets are actually in the correct order at
//   every site; the checker's mismatch was an ALIGNMENT ARTIFACT caused by
//   the earlier +0xF drift.  Verified original 004F5EA3=assistGroupID and
//   004F5EB2=commander both match rebuilt call targets 1:1 (62/62).
// - FIXED the group walk: original is a top-tested loop whose back edge
//   (004F5F9A -> 004F5E65) returns to the null test at the top of the body,
//   with `or ebp,-1` in the preheader.  Changed `if {...} do {...} while` to
//   a plain `while (group != &this->groups)` with `int minusOne = -1` first in
//   the body.  This resolved the +06F2 artifact and added 8 exact blocks.
// - FIXED the dropsite-success block (line 6089): original keeps
//   `lea ebp,[esi+0D58h]` (unitsTasked alias) live across the resize call and
//   holds n in ecx across the scan; added `ManagedArray_int* unitsTasked =
//   &this->unitsTaskedThisUpdate;` and read n/cap/value through it.  The
//   whole 6089 block (inline grow + membership scan + resize + append) is now
//   structurally byte-exact.
// - BEST CURRENT: 2014B vs 2024B (-10), 1751B strict diff, 252B edit/resync
//   (12.45%), 98.88% shape, 95.03% exact-block coverage, all 62 calls aligned,
//   0 wrong direct targets.  Second scan + group walk byte-exact.
// - REMAINING STALL: the line-6068 first membership scan.  Original spills the
//   count and capacity to stack homes [esp+1Ch]/[esp+18h] (frame 0x10), then
//   reloads them in the loop (`mov edx,[esp+1Ch]`, `cmp eax,[esp+18h]`); the
//   rebuilt substitutes them back to direct member reads ([esi+0D5Ch]/
//   [esi+0D64h]) and drops the frame to 0x8.  Tried ~12 families: while/for
//   +&&/break, locals vs direct-member vs mixed condition bounds, with/without
//   outer `if (n > 0)` guard, pointer and reference aliases, `register`/
//   `const` locals, n loaded before the resize call, full-class surface,
//   game_globals.h include context, and /O1//O2//Ox flag sets.  VC5
//   canonicalizes ALL of these to the same substitution basin in the
//   standalone scratch TU (verified with micro-repros: micro1..micro10 always
//   keep count/cap in registers or substitute member re-reads under register
//   pressure; no source form produces the stack-home spill).  The spill may
//   require the original full taitacmd.cpp TU context (real utmarray.h
//   template, whole-file register allocation) that the standalone checker
//   build cannot reproduce.  Next lead: build a combined-TU or full-class
//   context that reproduces the original allocator pressure, or accept the
//   +10B local-topology drift after review.
// - Also noted: two SIB base/index term swaps remain in the loop-body address
//   encodings (e.g. original `mov ebx,[ecx+edx]` vs rebuilt `mov ebx,[edx+ecx]`
//   at the second-scan civilianID load) - downstream register-color cascades
//   from the first-scan substitution, expected to resolve if the first scan
//   ever aligns.
// - Main-agent audit replaced synthetic v00/v61/v76/v77 slot scaffolding with
//   the proven canonical RGE_Player/RGE_Static_Object virtual names and modeled
//   TacticalAIGroup as its real 0x330 object with a named +0x1D0 field. Calls,
//   layout, and behavior remain unchanged; one relocation byte aligned better.
//
// ManagedArray recovery pass, 2026-08-19:
// - Exact contains ownership recovers the original 0x10 frame and all four
//   first-scan homes. CodeView lists only i, so the bound homes are compiler
//   state from the inlined method. Exact add also replaces the second manual
//   scan without changing emitted code.
// - The reduced isolated frontier has exact size, 624 instructions, 62 calls,
//   CFG, and block coverage. Six bytes differ in one first-scan comparison.
//   Only the transient EBX and EDX assignments are reversed.
// - Zero through twelve dummy predecessors do not change this result. The
//   exact same-TU playTaskSoldiers predecessor produces positional equality in
//   the context lab. Its declarations alone also produce equality.
// - Do not retain unused context declarations or a namespaced duplicate
//   predecessor. The next supported step needs genuine combined taitacmd.cpp
//   compile context or a natural source form that selects the same registers.
//
// Accepted-drift review, 2026-08-19:
// - All six changed bytes are in the five instructions at +0xB3 through
//   +0xC0. The original uses EBX for the task-array value and EDX for the
//   civilian-array base. The rebuild exchanges these two registers.
// - Both versions load the same pointers, select the same indexed task value,
//   and compare it with the same civilian value. They set identical flags for
//   the branch at +0xC1. Calls, memory writes, predicates, and fault order do
//   not change.
// - On fallthrough, +0xC7 replaces EDX and +0xD0 replaces EBX. On the taken
//   path, the loop tail at +0x2C0 uses neither register. The next iteration
//   replaces EBX at +0x25 and EDX at +0x3C before use.
// - Exact playTaskSoldiers same-TU context emits the original register choice.
//   The isolated source keeps this localized, proved-equivalent VC5 drift.

void* operator_new(unsigned int size);
void __cdecl operator_delete(void* ptr);




void TribeTacticalAIModule::evaluateOpenTasks()
{
    int i;

    i = 0;
    if (this->civilians.numberValue > 0) {
        ManagedArray<int>* civilians = &this->civilians;
        do {
            if (i > civilians->maximumSizeValue - 1) {
                civilians->resize(i + 1);
            }

            RGE_Static_Object* object =
                this->md->player->world->object(civilians->value[i]);
            if (object != 0) {
                UnitAIModule* unitAI = object->unitAI();
                if (unitAI != 0) {
                    if (i > civilians->maximumSizeValue - 1)
                        civilians->resize(i + 1);
                    ManagedArray<int>* unitsTasked =
                        &this->unitsTaskedThisUpdate;
                    if (unitsTasked->contains(civilians->value[i]))
                        goto next_civilian;

                    if (object->getSpeed() == 0.0 &&
                        object->attribute_amount_held > 0.0f &&
                        object->waitingToMove() == 0 && object->actionState() <= 2) {
                        RGE_Static_Object* dropsite =
                            this->md->informationAI.findClosestReturnDropsite(object);
                        if (dropsite != 0) {
                            this->md->player->sendGameOrder(object, dropsite,
                                                            dropsite->world_x,
                                                            dropsite->world_y);

                            int civilianID = (*civilians)[i];
                            ManagedArray<int>* unitsTasked = &this->unitsTaskedThisUpdate;
                            unitsTasked->add(civilianID);
                        } else {
                            this->stopUnit((*civilians)[i], 100);
                        }
                    } else {
                        if (object->unitAI()->currentOrder() == 700) {
                            int target = object->unitAI()->currentTarget();
                            RGE_Static_Object* targetObject =
                                this->md->object(target);
                            if (targetObject == 0 ||
                                targetObject->object_state > 2) {
                                if (i > civilians->maximumSizeValue - 1) {
                                    civilians->resize(i + 1);
                                }
                                this->stopUnit(civilians->value[i], 100);
                            }
                        }
                    }
                }
            }
        next_civilian:
            i++;
        } while (i < this->civilians.numberValue);
    }

    i = 0;
    if (this->civilians.numberValue > 0) {
        do {
            RGE_Static_Object* object =
                this->md->player->world->object(this->civilians[i]);
            if (object == 0 || object->hp < 1.0f || object->unitAI() == 0) {
                this->removeObject(this->civilians[i]);
            }
            i++;
        } while (i < this->civilians.numberValue);
    }

    i = 0;
    if (this->soldiers.numberValue > 0) {
        do {
            RGE_Static_Object* object =
                this->md->player->world->object(this->soldiers[i]);
            if (object == 0 || object->hp < 1.0f || object->unitAI() == 0) {
                this->removeObject(this->soldiers[i]);
            }
            i++;
        } while (i < this->soldiers.numberValue);
    }

    i = 0;
    if (this->boats.numberValue > 0) {
        do {
            RGE_Static_Object* object =
                this->md->player->world->object(this->boats[i]);
            if (object == 0 || object->hp < 1.0f || object->unitAI() == 0) {
                this->removeObject(this->boats[i]);
            }
            i++;
        } while (i < this->boats.numberValue);
    }

    TacticalAIGroup* group = this->groups.next;
    while (group != &this->groups) {
        int minusOne = -1;
        if (group == 0) {
            return;
        }

            if (group->type() == 0x6A && group->action() == 0xC) {
                TacticalAIGroup* assistGroup =
                    this->group(group->assistGroupID(), minusOne, minusOne,
                                minusOne);
                int currentAssistGroupID = group->assistGroupID();

                if (currentAssistGroupID == -1 || assistGroup == 0) {
                    group->setAction(1);
                    group->setTarget(minusOne);
                    group->setTargetType(minusOne);
                    group->setTargetLocation(-1.0f, -1.0f, -1.0f);
                    group->setGatherLocation(-1.0f, -1.0f, -1.0f);
                    group->setRetreatLocation(-1.0f, -1.0f, -1.0f);
                    group->setInUse(0);
                    group->setWaitCode(minusOne);
                    group->playNumberValue = minusOne;
                } else {
                    int commander = group->commander();
                    RGE_Static_Object* object = this->md->object(commander);
                    if (object != 0 && object->actionState() == 2 &&
                        assistGroup->action() == 0x10) {
                        int assistCommander = assistGroup->commander();
                        RGE_Static_Object* assistObject =
                            this->md->object(assistCommander);
                        if (assistObject != 0 &&
                            ((ObjectList*)assistObject->objects)->number_of_objects > 0) {
                            assistGroup->setAction(0xF);
                        }
                    }
                }
            }

            group = group->next;
    }
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F5FB0_evaluateBuildListInsertions.cpp
// ---------------------------------------------------------------------------
// 004F5FB0 TribeTacticalAIModule::evaluateBuildListInsertions
// taitacmd.cpp:6194-6250, 327 bytes
//
// Attempt log:
// - Baseline was a raw-offset/free-helper scaffold (217 bytes) with the wrong
//   build calls and no typed checkForBuildInsertion surface.
// - Probe 1: reconstructed the named same-TU tactical/main-decision,
//   build/resource/information/player/world ownership and the natural nested
//   insertion guards. This recovered 327 bytes and all nine ordered calls but
//   initially placed the strategic-number array 0x60 bytes too high.
// - Probe 2: corrected the tactical prefix so sn[0xCD]/[0xA9]/[0xAF]/[0xB0]
//   own the proven +0x4C8/+0x438/+0x450/+0x454 fields; only the resourceAI
//   displacement remained three bytes off.
// - Probe 3: restored the full 0x10090 informationAI size, moving resourceAI
//   to +0x10D7C and producing an exact 327-byte match with default flags.
// - The two gotos retain binary-proven shared granary/queue tails; all data and
//   calls remain named typed members rather than raw-offset plumbing.

void TribeTacticalAIModule::evaluateBuildListInsertions()
{
    int one = 1;

    if (this->sn[0xCD] == one) {
        if (this->md->buildAI.haveBuildList() != 0 &&
            this->builtFirstStoragePit == 0 &&
            this->md->informationAI.numberFoundForestTilesValue >= this->sn[0xA9]) {
            this->md->buildAI.insert(0x67, one, 0);
            this->builtFirstStoragePit = one;
        }

        if (this->sn[0xCD] == one) {
            if (this->md->buildAI.haveBuildList() != 0 &&
                this->builtFirstGranary == 0) {
                if (this->builtFirstStoragePit != one &&
                    this->md->resourceAI.resource(one) < 250) {
                    goto check_granary;
                }

                if (this->md->informationAI.closestDropsiteValue[0] != -1) {
                    this->md->buildAI.insert(0x44, one, one);
                    this->builtFirstGranary = one;
                    goto after_granary;
                }
            }
        }
    }

check_granary:
    if (this->builtFirstGranary == one)
        this->checkForBuildInsertion(0x44, one, 0);

after_granary:
    int insertID = this->sn[0xAF];
    if (insertID != -1 &&
        this->sn[0xB0] <=
            this->md->player->world->world_time / 60000) {
        this->md->buildAI.insert(insertID, one, 0);
        this->sn[0xAF] = -1;
    }

    this->checkForBuildInsertion(0x32, one, 0);
    this->checkForBuildInsertion(0x4F, one, 0);
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F6100_numberCivilians.cpp
// ---------------------------------------------------------------------------
int TribeTacticalAIModule::numberCivilians() const {
    return this->civilians.numberValue;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F6110_numberCivilianExplorers.cpp
// ---------------------------------------------------------------------------
int TribeTacticalAIModule::numberCivilianExplorers() const {
    return this->civilianExplorers.numberValue;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F6120_numberGatherers.cpp
// ---------------------------------------------------------------------------
int TribeTacticalAIModule::numberGatherers() const {
    return this->numberGatherersValue;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F6130_desiredNumberCivilianExplorers.cpp
// ---------------------------------------------------------------------------
int TribeTacticalAIModule::desiredNumberCivilianExplorers() const {
    return this->civilianExplorers.desiredNumberValue;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F6140_desiredNumberGatherers.cpp
// ---------------------------------------------------------------------------
int TribeTacticalAIModule::desiredNumberGatherers() const {
    return this->desiredNumberGatherersValue;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F6150_numberSoldiers.cpp
// ---------------------------------------------------------------------------
int TribeTacticalAIModule::numberSoldiers() const {
    return this->soldiers.numberValue;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F6160_numberSoldierExplorers.cpp
// ---------------------------------------------------------------------------
// BINARY NOTE: The body calls TribeTacticalAIModule::numberUnitsInGroups(0x66).

int TribeTacticalAIModule::numberSoldierExplorers()
{
    return this->numberUnitsInGroups(0x66);
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F6170_numberBoats.cpp
// ---------------------------------------------------------------------------
int TribeTacticalAIModule::numberBoats() const {
    return this->boats.numberValue;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F6180_neededResource.cpp
// ---------------------------------------------------------------------------

int TribeTacticalAIModule::neededResource(int index) const {
    if (index < 0 || index >= 4) return -1;
    return this->neededResourceValue[index];
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F61A0_neededResourceAmount.cpp
// ---------------------------------------------------------------------------


int TribeTacticalAIModule::neededResourceAmount(int index) const {
    if (index >= 0 && index < 4)
        return this->neededResources.value(this->neededResourceValue[index]);
    return -1;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F61D0_detask.cpp
// ---------------------------------------------------------------------------



void TribeTacticalAIModule::detask(int unitId) {
    if (unitId == -1) {
        this->logCommonHistory((char*)"ERROR DETASKING Unit #%d!", unitId);
        return;
    }
    removeFromTaskLists(unitId);
    stopUnit(unitId, 0x64);
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F6210_strategicNumber.cpp
// ---------------------------------------------------------------------------

int TribeTacticalAIModule::strategicNumber(int index) {
    if (index < 0 || index >= 226)
        return -1;
    return strategicNumbers[index];
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F6230_setStrategicNumber.cpp
// ---------------------------------------------------------------------------
// 004F6230 TribeTacticalAIModule::setStrategicNumber(int,int)
// Source: taitacmd.cpp lines 6355-6382
// Attempt log:
// - Replaced simple stub with bounds check, raw sn array store, percentage clamp,
//   and informationAI notification for strategic number 0x69.
// - Exact match with the literal `||` comparison order from original asm.




void TribeTacticalAIModule::setStrategicNumber(int index, int value)
{
    if (index >= 0 && index < 0xE2) {
        this->sn[index] = value;
        if (index == 0x75 || index == 0x78 || index == 0x77 || index == 0x76 ||
            index == 0x9C || index == 0x9D || index == 0x9E || index == 0x9F) {
            if (value < 0) {
                this->sn[index] = 0;
            }
            else if (value > 100) {
                this->sn[index] = 100;
            }
        }
        if (index == 0x69) {
            this->md->informationAI.setSaveLearnInformation(value);
        }
    }
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F62C0_notify.cpp
// ---------------------------------------------------------------------------
// 004F62C0 TribeTacticalAIModule::notify
// Source: taitacmd.cpp lines 6388-6886
// Baseline reconstruction: direct-command notification, attack-response state,
// named TacticalAIGroup/Information/Diplomacy ownership, and the complete
// named RGE_Static_Object virtual surface used by the two path tests.
//
// Attempt log:
// - baseline: canonical ownership is md->aiPlayer/world for object lookup,
//   md->informationAI for relic memory, the four named managed arrays, and the
//   embedded TacticalAIGroup sentinel; no vtable padding or raw vptr plumbing.
// - put the 0x72/0x74 relic handler in the cold non-0x201 arm; this moved the
//   main path into the binary's fall-through layout and substantially improved
//   ordered calls.
// - repeated unitAI() calls and direct managed-array reads were restored where
//   the original reloads them; the observed scalar/XYZ canPath overload slots
//   required the named overload declarations in the compiler's slot order.
// - kept the entry object in attackPoint.x, separate from the later targetObj;
//   this matches the packet's stack alias and object ownership flow.
// - replaced boolean civilian/explorer searches with the binary-supported
//   generic/difficulty join structure; the remaining drift is not behavioral.
// - corrected MD member ownership: diplomacyAI is at +0x9DC and
//   informationAI at +0xCEC.  TacticalAIGroup Waypoint fields are 16-byte
//   Waypoints (not 12-byte XYZPoints), restoring players/workingArea and
//   aiPlayer offsets (+0xD28/+0xD48/+0x1256C).
// - best current reconstruction: 4331 rebuilt bytes vs 4235, 77.66% shape,
//   29.67% exact-block coverage, 97.48% ordered-call similarity, frame 0x20
//   vs 0x30.  One __ftol site and three call-site gaps remain; no exact match.
// - managed-array growth loops written as bounded for loops moved the clean
//   source to 4281 bytes, 83.13% shape, and 43.85% exact-block coverage.
// - 22 evidence-led probes covered call-arm structure, array ownership,
//   parameter homes, block placement, and header context. Most were neutral.
// - BINARY NOTE: the original has one extra far-victim coordinate __ftol call
//   before the common coop-attack call. A volatile diagnostic reproduced the
//   119-call surface, but it also changed cleanup and is not retained.
// - remaining structural facts: the original frame is 0x30, its civilian
//   explorer/difficulty blocks are cold at the tail, and the clean source is
//   46 bytes longer with one missing __ftol call.
// - the named callerID alias is part of the best codegen basin; direct
//   parameter spelling tested separately but produced a weaker frontier.
// - duplicated near/far coop-coordinate call blocks were tested from the
//   original line bands.  A full duplicate added three ftol calls; a direct
//   near victory call was folded back to the same missing-ftol result.  The
//   common post-branch call is restored.
// - reusing param_2 as the caller-object home was codegen-neutral and was
//   rejected as opaque source; retain the named callerObject ownership.
// - 2026-08-22: moved the relic handler behind a switch dispatch and one
//   shared late label.  This reproduces the original sub/sub dispatch and
//   improves ordered calls to 118/119, shape to 85.74%, and exact-block
//   coverage to 46.21%.  The source-level late label is supported by the
//   original cold relic and explorer blocks.
// - 2026-08-22: a ternary coordinate expression removed three __ftol calls
//   and was rejected.  Keep the branch-local integer coordinate assignments.
// - 2026-08-22: split the coop call across the near, far-victory, and
//   far-target arms.  VC5 still emitted 118 calls and no extra __ftol; restore
//   the shared call form because its shape and call order were weaker.
// MANAGEDARRAY AUDIT: restored playersToAttack[0] for the index-zero capacity
// check and removed the fake resize(index) method. This emits identical code.
// Growth guards, copies, publication, and field offsets now follow the shared
// template contract.
// BLOCKER: The rebuild frame is 0x1C versus 0x30, is 46 bytes long, and misses
// one far-victim _ftol site. Ordered call gaps and broad CFG drift also remain.


void TribeTacticalAIModule::notify(int param_1, int param_2, int param_3,
                                   long param_4, long param_5, long param_6)
{
    int callerID = param_1;
    int numberToRespond;
    RGE_Static_Object* targetObj;
    ulong entryTime;
    RGE_Static_Object* callerObject;
    XYPoint attackPoint;
    XYZPoint point;
    XYZPoint point_fffffff0;
    ObjectMemory* memory;
    int relicIndex;
    int relicCount;
    RGE_Static_Object* victoryObject;
    int responseDistance;
    int coopX;
    int coopY;
    attackPoint.x = (int)this->md->aiPlayer->world->object(callerID);
    if (param_3 != 0x72 && param_3 != 0x74 && attackPoint.x == 0) {
        return;
    }

    entryTime = debug_timeGetTime((char*)0x5880C0, 0x1904);

    switch (param_3) {
    case 0x72:
    case 0x74:
        goto notify_relic;
    case 0x201:
        break;
    default:
        return;
    }

    targetObj = this->md->aiPlayer->world->object(param_4);
    if (targetObj == 0) return;
    if (targetObj->owner->id == this->md->player->id) return;

    callerObject = this->md->aiPlayer->world->object(param_1);
    if (callerObject == 0) return;

    if (targetObj->owner->id == 0 &&
        (this->zoomingToNextAge == 0 ||
         (targetObj->master_obj->id != 0x7E && targetObj->master_obj->id != 0x59)) &&
        this->dealWithGAIAAttacker(targetObj, callerObject) == 1) {
        return;
    }

    if (targetObj->owner->id != 0) {
        int i = 0;
        int explorerCount;
        int difficulty;
        if (0 < this->civilians.numberValue) {
            do {
                if (this->civilians.maximumSizeValue <= i) break;
                if (this->civilians.value[i] == callerID) {
                    explorerCount = this->civilianExplorers.numberValue;
                    i = 0;
                    if (explorerCount < 1) goto notify_difficulty;
                    goto notify_explorer_scan;
                }
                i = i + 1;
            } while (i < this->civilians.numberValue);
        }
        goto notify_generic_unit;

notify_generic_unit:
        if (callerObject->unitAI() != 0 && callerObject->unitAI()->currentOrder() != 0x2C1) {
            difficulty = this->md->player->world->difficultyLevel();
            if (difficulty == 3) {
                this->sn[0x68] -= 2;
            }
            else {
                difficulty = this->md->player->world->difficultyLevel();
                if (difficulty == 4) this->sn[0x68] -= 1;
                else this->enableAttack(3);
            }
        }
        goto notify_after_owner;

notify_explorer_scan:
        do {
            if (this->civilianExplorers.maximumSizeValue <= i) break;
            if (this->civilianExplorers.value[i] == callerID)
                goto notify_generic_unit;
            i = i + 1;
        } while (i < explorerCount);
        goto notify_difficulty;

notify_difficulty:
        difficulty = this->md->player->world->difficultyLevel();
        if (difficulty == 3) {
            this->sn[0x68] -= 2;
        }
        else {
            difficulty = this->md->player->world->difficultyLevel();
            if (difficulty == 4) this->sn[0x68] -= 1;
            else this->enableAttack(3);
        }
    }

notify_after_owner:
    this->checkForAttackResponseBuildInsertions(targetObj->owner->id);
    this->hitsByPlayer[targetObj->owner->id]++;

    if (targetObj->owner->computerPlayer() == 0) {
        if (this->md->player->isAlly(targetObj->owner->id) == 1 &&
            this->sn[0xDD] <= this->hitsByPlayer[targetObj->owner->id] &&
            this->sn[0xD7] == 1) {
            this->md->diplomacyAI.setChangeable(targetObj->owner->id, 1);
            this->md->diplomacyAI.setStance(targetObj->owner->id, 0, 100);
            this->md->diplomacyAI.setRelation(targetObj->owner->id, 3);
            this->md->diplomacyAI.setChangeable(targetObj->owner->id, 0);
        }
        else {
            this->md->diplomacyAI.changeStance(targetObj->owner->id, 2, this->sn[0xB2]);
            this->md->diplomacyAI.changeStance(targetObj->owner->id, 0, this->sn[0xB2]);
        }
    }
    else if (this->md->player->isAlly(targetObj->owner->id) == 1 &&
             this->md->player->world->players[targetObj->owner->id]->isEnemy(this->md->player->id) == 1) {
        this->md->diplomacyAI.setChangeable(targetObj->owner->id, 1);
        this->md->diplomacyAI.setStance(targetObj->owner->id, 0, 100);
        this->md->diplomacyAI.setRelation(targetObj->owner->id, 3);
        this->md->diplomacyAI.setChangeable(targetObj->owner->id, 0);
    }

    if (0 < this->sn[0x7C] && this->sn[0x80] == targetObj->owner->id && this->sn[0x85] == 1) {
        this->md->revokeTributeAlliance();
    }

    this->md->informationAI.storeAttackMemory(
        0,
        (uchar)targetObj->world_y,
        (uchar)targetObj->world_x,
        (uchar)targetObj->owner->id,
        (uchar)this->md->player->id,
        0,
        0,
        this->md->player->world->world_time,
        -1);

    if (this->lastAttackResponseTime != 0 &&
        (this->md->player->world->world_time - this->lastAttackResponseTime) / 1000 <
            this->attackLimiterTime(0x30)) {
        return;
    }

    attackPoint.x = (int)targetObj->world_x;
    attackPoint.y = (int)targetObj->world_y;

    TacticalAIGroup* group;
    if (this->md->informationAI.isBoat(targetObj) == 1) {
        group = this->readyAndIdleGroup(0x67, this->sn[0x14], &attackPoint);
    }
    else {
        group = this->readyAndIdleGroup(100, this->sn[0x14], &attackPoint);
        if (group == 0) {
            group = this->readyAndIdleGroup(0x67, this->sn[0x14], &attackPoint);
        }
    }

    if (group != 0) {
        RGE_Static_Object* commanderObject =
            this->md->aiPlayer->world->object(group->commander());
        if (commanderObject != 0) {
            point.x = (int)targetObj->world_x;
            point.y = (int)targetObj->world_y;
            point.z = (int)targetObj->world_z;
            if (commanderObject->canPath(
                    point, commanderObject->weaponRange(), targetObj->id, 0, 1, -1, -1) == 1) {
                group->setTarget(callerObject->id);
                group->setTargetType(targetObj->master_obj->id);
                group->setTargetLocation(targetObj->world_x, targetObj->world_y, targetObj->world_z);
                group->setAction(2);
                group->task(this, this->md, 2, 1, 0);
                this->lastAttackResponseTime = this->md->player->world->world_time;
                if (this->sn[0x47] != 1) return;
                this->lastGroupAttackTime = this->md->player->world->world_time;
                return;
            }
        }
    }

    victoryObject = this->md->object(
        -1, 0x6D, -1, -1, -1, -1, -1, -1, -1, -1);
    responseDistance = 1000;
    if (victoryObject != 0) {
        float dx = victoryObject->world_x - targetObj->world_x;
        float dy = victoryObject->world_y - targetObj->world_y;
        responseDistance = (int)sqrt(dx * dx + dy * dy);
    }

    if (responseDistance < 0x14) {
        int warships = this->numberWarshipsWithPriority(100, -1);
        int soldiers = this->numberSoldiersWithPriority(100, -1, 0);
        numberToRespond = warships + soldiers;
        if (numberToRespond == 0 && this->md->informationAI.isBoat(targetObj) == 0 &&
            this->sn[0xE1] == 1 &&
            this->md->player->world->world_time / 1000 < (ulong)this->sn[0x68]) {
            int i = 0;
            if (0 < this->civilians.numberValue) {
                do {
                    int civilian = this->civilians[i];
                    int j = 0;
                    int found = 0;
                    if (0 < this->workingArea.numberValue) {
                        do {
                            if (this->workingArea.maximumSizeValue <= j) break;
                            if (this->workingArea.value[j] == civilian) {
                                found = 1;
                                break;
                            }
                            j = j + 1;
                        } while (j < this->workingArea.numberValue);
                    }
                    if (found == 0) {
                        this->workingArea[this->workingArea.numberValue] = civilian;
                        this->workingArea.numberValue++;
                    }
                    i = i + 1;
                } while (i < this->civilians.numberValue);
            }
            numberToRespond = this->civilians.numberValue;
        }
        coopY = (int)victoryObject->world_y;
        coopX = (int)victoryObject->world_x;
    }
    else {
        int available;
        if (this->md->informationAI.isBoat(targetObj) == 1) {
            available = this->numberWarshipsWithPriority(this->sn[0x14], -1);
        }
        else {
            available = this->numberWarshipsWithPriority(this->sn[0x14], -1);
            available += this->numberSoldiersWithPriority(this->sn[0x14], -1, 0);
        }
        numberToRespond = (this->sn[0x13] * available) / 100;
        if (victoryObject != 0) {
            coopY = (int)victoryObject->world_y;
            coopX = (int)victoryObject->world_x;
        }
        else {
            coopY = (int)targetObj->world_y;
            coopX = (int)targetObj->world_x;
        }
    }
    this->checkForCoopAttack(targetObj->owner->id, coopX, coopY);

    param_2 = 0;
    param_3 = 0;
    if (0 < this->workingArea.numberValue) {
        while (param_2 < numberToRespond &&
               (param_3 < 2 ||
                debug_timeGetTime((char*)0x5880C0, 0x1A54) - entryTime < 0xB)) {
            RGE_Static_Object* unitObject =
                this->md->aiPlayer->world->object(this->workingArea[param_3]);
            if (unitObject != 0 && unitObject->unitAI() != 0) {
                int action = unitObject->unitAI()->currentAction();
                if (action == 600) {
                    int currentTarget = unitObject->unitAI()->currentTarget();
                    if (currentTarget != -1) {
                        currentTarget = unitObject->unitAI()->currentTarget();
                        if (currentTarget != targetObj->id) {
                            currentTarget = unitObject->unitAI()->currentTarget();
                            RGE_Static_Object* oldTarget =
                                this->md->aiPlayer->world->object(currentTarget);
                            if (oldTarget != 0) {
                                if (this->playersToAttack.maximumSizeValue < 1) {
                                    this->playersToAttack[0];
                                }
                                if (oldTarget->owner->id == this->playersToAttack.value[0]) {
                                    param_2++;
                                    goto notify_next_unit;
                                }
                            }
                        }
                    }
                    goto notify_try_attack;
                }
notify_try_attack:
                if (this->workingArea[param_3] == callerID) {
                    if (unitObject->unitAI()->currentOrderPriority() != 100) {
                        point_fffffff0.x = (int)targetObj->world_x;
                        point_fffffff0.y = (int)targetObj->world_y;
                        point_fffffff0.z = (int)targetObj->world_z;
                        if (unitObject->canPath(
                                point_fffffff0, unitObject->weaponRange(), targetObj->id,
                                0, 1, -1, -1) != 0) {
                            if (this->taskAttacker(this->workingArea[param_3],
                                                   targetObj->world_x, targetObj->world_y,
                                                   targetObj->id, targetObj->owner->id,
                                                   0, 0, -1, 0) == 1) {
                                this->lastAttackResponseTime = this->md->player->world->world_time;
                                if (this->sn[0x47] == 1) {
                                    this->lastGroupAttackTime = this->md->player->world->world_time;
                                }
                                param_2++;
                            }
                        }
                    }
                }
                else {
                    float distance = targetObj->distance_to_object(unitObject);
                    int priority = this->calculatePriority(distance);
                    if (distance < (float)this->sn[0x14]) {
                        int currentPriority = unitObject->unitAI()->currentOrderPriority();
                        if (currentPriority < priority && 0 < priority) {
                            point_fffffff0.x = (int)targetObj->world_x;
                            point_fffffff0.y = (int)targetObj->world_y;
                            point_fffffff0.z = (int)targetObj->world_z;
                            if (unitObject->canPath(
                                    point_fffffff0, unitObject->weaponRange(), targetObj->id,
                                    0, 1, -1, -1) != 0) {
                                if (this->taskAttacker(this->workingArea[param_3],
                                                       targetObj->world_x, targetObj->world_y,
                                                       targetObj->id, targetObj->owner->id,
                                                       0, 0, -1, 0) == 1) {
                                    param_2++;
                                }
                            }
                        }
                    }
                }
            }
notify_next_unit:
            param_3++;
        }
    }

    return;

notify_relic:
    if (param_3 == 0x72) {
        memory = this->md->informationAI.artifactToCapture(-1);
    }
    else {
        memory = this->md->informationAI.ruinToCapture(-1);
    }
    if (memory == 0) return;

    numberToRespond = this->numberSoldiersWithPriority(100, -1, 1);
    if (numberToRespond > 3) numberToRespond = 3;
    relicCount = 0;
    relicIndex = 0;
    if (this->workingArea.numberValue < 1) return;
    do {
        if (numberToRespond <= relicCount) return;
        RGE_Static_Object* object =
            this->md->aiPlayer->world->object(this->workingArea[relicIndex]);
        if (object != 0 && object->unitAI() != 0 &&
            object->canPath(memory->id, 2.0f, 0, 1, -1, -1) != 0) {
            if (this->taskDefender(this->workingArea[relicIndex], memory->id,
                                   2.0f, 100) == 1) {
                this->removeFromGroup(this->workingArea[relicIndex]);
                relicCount = relicCount + 1;
            }
        }
        relicIndex = relicIndex + 1;
        if (this->workingArea.numberValue <= relicIndex) return;
    } while (1);
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F7350_numberIdleSoldiers.cpp
// ---------------------------------------------------------------------------
// 004F7350 TribeTacticalAIModule::numberIdleSoldiers
// Source: taitacmd.cpp lines 6891-6904
// Counts soldiers whose UnitAIModule is idle and records them in workingArea.
//
// Attempt log:
// Probe 1 (baseline): rough raw-offset reconstruction rebuilt 573 bytes with
//   9 calls; helper shims lost the two unitAI calls and all three original
//   decorated member-call identities. Canonical fields were nevertheless the
//   soldiers and workingArea ManagedArray<int> members.
// Probe 2: restored the period ManagedArray operator[]/add bodies, typed
//   RGE_Game_World::object, RGE_Static_Object::unitAI, and UnitAIModule calls,
//   with md->aiPlayer->world ownership. Checking the natural source next.
// Probe 3: added ordinary references to the two array members, mirroring the
//   exact same-TU numberUngroupedSoldiers source so the reset precedes the
//   soldiers count load and indexed member expressions retain their address
//   term order.
// Probe 4: rewrote the inline indexer return as pointer addition; this is a
//   natural equivalent source spelling to test the two remaining SIB bytes.
// Probe 5: reversed the pointer-addition operands in the indexer return;
//   retained only as a focused address-term experiment.
// Probe 6: materialized the array pointer before the indexer return to test
//   whether a natural local pointer changes VC5's base/index encoding.
// Probe 7: restored the compact non-polymorphic local type context used by
//   the exact same-TU ManagedArray donor; the proven field offsets remain
//   unchanged while testing whether class vptr context affects SIB encoding.
// Probe 8: focused six-way indexer-return lab; every natural pointer/member
//   spelling stayed in the same two-byte SIB basin.
// Probe 9: focused ensure-then-direct-value lab; the explicit inline growth
//   spelling also stayed in the same two-byte SIB basin.
// Probe 10: restored the canonical indexer return and added the donor-TU
//   <stdlib.h> context as the final translation-unit hypothesis.


extern "C" {
    void* operator_new(unsigned int size);
    void operator_delete(void* ptr);
}

int TribeTacticalAIModule::numberIdleSoldiers()
{
    int count = 0;
    int i = 0;
    ManagedArray<int>& workingArea = this->workingArea;
    ManagedArray<int>& soldiers = this->soldiers;

    workingArea.numberValue = 0;
    if (soldiers.numberValue > 0) {
        do {
            RGE_Static_Object* obj =
                this->md->aiPlayer->world->object(soldiers[i]);
            if ((obj != 0) && (obj->unitAI() != 0)) {
                if (obj->unitAI()->currentAction() == -1) {
                    workingArea.add(soldiers[i]);
                    count++;
                }
            }
            i++;
        } while (i < soldiers.numberValue);
    }
    return count;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F7590_numberSoldiersWithPriority.cpp
// ---------------------------------------------------------------------------
// VA: 004F7590 TribeTacticalAIModule::numberSoldiersWithPriority
// Attempt log:
// try 1: adapted dynamic-array/scanning shape from numberUngroupedSoldiers and packet: reset working list, scan soldiers, resolve object, filter valid/busy/grouped/priority, count unique working soldiers.
// try 2: fixed local layout for busy array near +0xD58 so source compiles.
// try 3: minimal behavioral source compiled but only 400B vs 726B.
// try 4: /Od probe still too small (584B) and wrong basin; removed.
// try 5: inlined soldier array growth at scan index like original dynamic-array pattern.
// try 6: inlined working array growth/copy/delete before adding accepted soldier.
// try 7: modeled reset flag clearing workingNumber at +0xD4C.
// try 8: modeled busy-list duplicate exclusion loop using busyValue/busyNumber/busyMaximum.
// try 9: modeled negative/positive/zero priority comparisons via UnitAI priority/taskPriority calls.
// try 10: /GX probe no size/codegen change; removed.
// left in scratch: the best source reconstruction is 833B vs original 726B;
//   ordered calls and behavior-backed array/priority topology align, but the
//   frame/prologue and several branch/register blocks remain structurally
//   unresolved, so this is not accepted_drift-safe.
// probe 11: restored the PDB-backed parameter order (threshold, priority, reset),
//   the out-of-line ManagedArray resize/contains surface, and the repeated
//   source-level priority arms shown by the original line bands.  This also
//   restores the inline operator[] only for the zero-priority soldiers read.
// probe 12: shared the binary-proven working-area append tail and restored the
//   zero-priority soldier growth as the one inline allocation/copy/delete path;
//   the other soldier reads retain the six out-of-line resize call sites.
// probe 13: laid out the positive-priority arm before the zero-priority arm,
//   matching the original inline positive block and late zero block.
// probe 14: added the period local owner used to preserve this across the
//   busy-array register reuse; no byte-stride cursor was retained yet.
// probe 15: made the repeated int-array element address an explicit proven
//   byte-stride cursor, matching the original EBP offset and zero-arm
//   allocation-size topology.
// probe 16: moved the result declaration ahead of the owner/array locals to
//   test the original EBX=this, EDI=result, EBP=offset callee-save coloring.
// probe 17: corrected the positive-arm threshold ownership and mirrored the
//   original compare operand spellings for bounds/duplicate scans.
// probe 18: restored a natural typed count loop with direct ManagedArray
//   element access; removed the byte-stride cursor and excess owner alias.
//   Result: size moved 833->832 and exact-block coverage improved, but the
//   frame stayed 0x10 and the first structural hunk remained unchanged.
// probe 19: delayed the soldiers pointer until after the count guard; frame
//   stayed exact, but the natural branch source moved to 808B and diff 719.
// probe 20: retained a local byte-size expression for the zero-arm growth;
//   it broke tail merging and added a seventh resize call. Rolled back.
// probe 22: changed busy and working duplicate scans to bounded for loops;
//   frame stayed 0xC, calls stayed aligned, and size moved to 688B with diff
//   649. Probe 23 kept the pre-loop index initialization and reached diff 647.
// probe 24: restored one shared append tail; size became exactly 726B, but
//   compiler layout moved one resize call before the positive arm.
// probe 25: placed that tail in the positive PDB band; shape improved to
//   76.10%, but the label-crossing source was not a clean original model.
// left in scratch: natural branch-local append source, 688B vs 726B, diff
//   647, exact calls and frame. The remaining structural gap is register
//   coloring, block placement, and the original shared append tail order.
// revisit probes:
// - The old countedSoldier label was outside the valid-object block.  The
//   original null object and null UnitAI paths skip the result increment, so
//   the label now stays inside that block.
// - A shared negative/positive append tail restored the original 726-byte
//   size and raised shape similarity to 92.03%; calls and frame also match.
// - Delaying the soldiers alias until after the outer count guard, then
//   assigning the working count before the soldier value, restored the exact
//   prologue and 248-instruction size.  The best current result is 353 strict
//   differing bytes, 93.55% shape similarity, and 78.63% exact-block coverage.
// - Direct working-area expressions, a branch pointer alias, an inline add
//   helper, alternate loop forms, ABI declaration changes, and local-order
//   variants were tested.  They were worse or codegen duplicates.
// MANAGEDARRAY AUDIT: resize guards, inline growth, copies, publication,
// contains bounds, append count, and field offsets match the executable. No
// shared template change is required.
// BLOCKER: After a soldier resize, the executable reads the soldier value
// pointer before the working-area count. The rebuild reads the count first.
// Soldier element and working-array reads therefore have different mutation
// and fault order.

extern "C" {
    void* __cdecl operator_new(unsigned int size);
    void __cdecl operator_delete(void* ptr);
}

int TribeTacticalAIModule::numberSoldiersWithPriority(int threshold, int priority, int reset)
{
    TribeTacticalAIModule* self = this;
    ManagedArrayInt& workingArea = self->workingArea;
    int rNum = 0;

    if (reset == 1)
        workingArea.numberValue = 0;

    reset = 0;
    if (0 < self->soldiers.numberValue) {
        ManagedArrayInt& soldiers = self->soldiers;
        do {
            if (reset > soldiers.maximumSizeValue - 1)
                soldiers.resize(reset + 1);

            RGE_Static_Object* object =
                self->md->aiPlayer->world->object(soldiers.value[reset]);
            if ((object != 0) && (object->unitAI() != 0)) {
                if (reset > soldiers.maximumSizeValue - 1)
                    soldiers.resize(reset + 1);

                int taskedNumber = self->unitsTaskedThisUpdate.numberValue;
                int taskedIndex = 0;
                if (0 < taskedNumber) {
                    for (;
                         taskedIndex < taskedNumber &&
                         taskedIndex < self->unitsTaskedThisUpdate.maximumSizeValue;
                         taskedIndex++) {
                        if (self->unitsTaskedThisUpdate.value[taskedIndex] ==
                            soldiers.value[reset])
                            goto nextSoldier;
                    }
                }

                int value;
                int number;
                if (priority < 0) {
                    if (object->unitAI()->currentAction() != -1) {
                        if (object->unitAI()->currentOrderPriority() >= threshold)
                            goto nextSoldier;
                    }

                    if (reset > soldiers.maximumSizeValue - 1)
                        soldiers.resize(reset + 1);
                    number = workingArea.numberValue;
                    value = soldiers.value[reset];
                    int index = 0;
                    if (0 < number) {
                        for (;
                             index < number && index < workingArea.maximumSizeValue;
                             index++) {
                            if (workingArea.value[index] == value)
                                goto countedSoldier;
                        }
                    }
                    goto appendWorking;
                }
                else if (priority > 0) {
                    if (object->unitAI()->currentAction() != -1) {
                        if (object->unitAI()->currentOrderPriority() > threshold) {
                            if (reset > soldiers.maximumSizeValue - 1)
                                soldiers.resize(reset + 1);
                            number = workingArea.numberValue;
                            value = soldiers.value[reset];
                            int index = 0;
                            if (0 < number) {
                                for (;
                                     index < number && index < workingArea.maximumSizeValue;
                                     index++) {
                                    if (workingArea.value[index] == value)
                                        goto countedSoldier;
                                }
                            }
                            goto appendWorking;
                        }
                    }
                    goto nextSoldier;
                }
                else {
                    if (object->unitAI()->currentAction() != -1) {
                        if (object->unitAI()->currentOrderPriority() == threshold) {
                            if (reset > soldiers.maximumSizeValue - 1) {
                                int* newValue = (int*)operator_new(reset * 4 + 4);
                                if (newValue != 0) {
                                    int copyIndex = 0;
                                    if (0 < soldiers.maximumSizeValue) {
                                        do {
                                            if (reset + 1 <= copyIndex)
                                                break;
                                            newValue[copyIndex] = soldiers.value[copyIndex];
                                            copyIndex = copyIndex + 1;
                                        } while (copyIndex < soldiers.maximumSizeValue);
                                    }
                                    operator_delete(soldiers.value);
                                    soldiers.value = newValue;
                                    soldiers.maximumSizeValue = reset + 1;
                                }
                            }

                            int value = soldiers.value[reset];
                            if (workingArea.contains(value) != 1) {
                                int number = workingArea.numberValue;
                                if (number > workingArea.maximumSizeValue - 1)
                                    workingArea.resize(number + 1);
                                workingArea.value[workingArea.numberValue] = value;
                                workingArea.numberValue = workingArea.numberValue + 1;
                            }
                            rNum = rNum + 1;
                        }
                    }
                    goto nextSoldier;
                }
appendWorking:
                if (number > workingArea.maximumSizeValue - 1)
                    workingArea.resize(number + 1);
                workingArea.value[workingArea.numberValue] = value;
                workingArea.numberValue = workingArea.numberValue + 1;
countedSoldier:
                rNum = rNum + 1;
            }
nextSoldier:
            reset = reset + 1;
        } while (reset < soldiers.numberValue);
    }
    return rNum;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F7870_numberWarshipsWithPriority.cpp
// ---------------------------------------------------------------------------
// 004F7870 TribeTacticalAIModule::numberWarshipsWithPriority
// taitacmd.cpp: 6953-7056
// Attempt log:
// - Prior source factored the repeated ManagedArray growth, duplicate scan,
//   and priority branches into helpers (752B); the packet instead shows two
//   long, source-level near-duplicate loops and the real resize/contains ABI.
// - Baseline candidate restores named warBoats/soldiers/workingArea/
//   this->unitsTaskedThisUpdate ownership, the binary's three priority modes, and
//   direct world/object/UnitAI calls.  Keep this file in scratch until the
//   repeated-loop register and stack-home topology is audited.
// - Duplicating the three warboat priority append arms recovered their six
//   missing resize/contains sites; restoring the negative soldier arm and
//   sharing its binary-proven workingArea tail recovered the full 47-call
//   multiset.  The best clean reconstruction is still 1425 bytes versus
//   1300, with a 0x14 versus 0x10 frame and first-register topology drift.
// - Separate Ghidra-backed soldier scan variables did not change emitted
//   code.  Left unresolved: source/context needed to keep this in ebp/ebx
//   topology and remove the remaining structural tail drift.
// - Reversed the soldier append forms to match the binary call order: the
//   equality arm scans workingArea, while the greater-priority arm uses
//   contains.  This restored the ordered 47-call surface.
// - Using local_8 as the proven byte offset in the warboat tasked-unit test
//   reduced the frame from 0x14 to 0x10.  The remaining prologue still uses
//   esi for this instead of the original ebp and keeps a 120-byte tail drift.
// - A direct workingArea.numberValue store in the greater arm preserves all
//   47 calls.  A separate pointer alias and declaration reorder had no effect.
// - Reordered each dispatch as negative, greater, equal to match the target's
//   jge/jle block layout.  This reduced the size gap to 24 bytes and raised
//   shape similarity, but the compiler merged three warboat append calls.
// - Keeping the binary-backed byte-offset load only in the negative warboat
//   arm restores all 47 calls and gives the best clean structural result:
//   1383 bytes, 67.37% shape, and 23.02% exact-block coverage.  Applying the
//   offset spelling to all arms merges the same calls and loses three calls.
// - Nested nonnegative dispatch and entry initialization reorder were codegen
//   duplicates.  Remaining structural gap is target ebp/ebx allocation and
//   an 83-byte tail.
// - Probe 18: reversed array-capacity tests to `index > maximum - 1` and
//   `index >= maximum`.  This matches the original CMP operand order, raises
//   shape similarity to 68.53%, and raises exact-block coverage to 31.41%.
// - Probe 19: reversed priority tests to compare the returned value with the
//   parameter.  This matches the original CMP operand order, raises shape to
//   70.16%, and raises exact-block coverage to 37.17%.
// - Probe 20: combined tasked-list count and capacity for loops improved
//   shape and resynchronization, but lost two required calls and the 0x10
//   frame.  Restore the pinned probe-19 source.
// - Final unresolved checkpoint: 1383 bytes versus 1300, 0x10 frame, 47/47
//   ordered calls, 70.16% shape, 37.17% exact-block coverage, 1295 strict
//   differing bytes.  The remaining lead is the target EBP/EBX register and
//   stack-home topology, then the 83-byte structural tail.
// MANAGEDARRAY AUDIT: resize, contains, capacity guards, duplicate scans,
// append publication, count increments, and field offsets use the expected
// ABI on both warboat and soldier paths. No shared template change is needed.
// BLOCKER: The rebuild remains 83 bytes too large, with four extra conditionals
// and two missing jumps. This is broad branch topology, not localized drift.
//
// Current worker probes (sa-c48f2f74-r1):
// - Canonical polymorphic AI/object/master declarations, template
//   ManagedArray<int>, the target-class vptr, and the RGE object id field did
//   not improve the clean 1383-byte basin. The template and object-id forms
//   were codegen duplicates; the combined polymorphic form was worse.
// - Top-tested while scans for both tasked-list loops removed the four extra
//   invariant capacity tests and reached 61/61 conditionals, but VC5 merged
//   two required contains/resize call sites and produced 45 calls. Inline
//   contains and branch-local result pointers did not prevent that merge.
// - Separate array scopes, register-qualified local_c, soldiers/warBoats
//   references, and donor file-string context were duplicates or worse.
// - A workingArea reference moved this to EBX and a 0x14 frame. A count-based
//   greater-arm append restored 47 calls but grew the body to 1463 bytes.
//   Restore the pinned probe-19 source after each test.
// - Final claim validation: pinned source remains 1383/1300 bytes, 0x10
//   frame, 47/47 ordered calls, 70.16% shape, 37.17% exact-block coverage,
//   and 1295 strict differing bytes. No tested source/context axis recovered
//   the target EBP/EBX topology or broad tail CFG.

int TribeTacticalAIModule::numberWarshipsWithPriority(int priority, int compare)
{
    ManagedArrayInt* warships;
    ManagedArrayInt* result;
    short objectGroup;
    RGE_Static_Object* object;
    UnitAIModule* ai;
    int value;
    int* values;
    int index;
    int scan;
    TribeTacticalAIModule* tactical;
    TribeTacticalAIModule* tactical2;
    int count;
    int i;
    int local_c;
    int local_8;
    TribeTacticalAIModule* local_4;

    i = 0;
    local_c = 0;
    local_4 = this;
    this->workingArea.numberValue = 0;

    if (this->warBoats.numberValue > 0) {
        warships = &this->warBoats;
        do {
            if (local_c > warships->maximumSizeValue - 1)
                warships->resize(local_c + 1);
            local_8 = local_c * 4;
            object = this->md->aiPlayer->world->object(warships->value[local_c]);
            if (object != 0 && object->unitAI() != 0) {
                if (local_c > warships->maximumSizeValue - 1)
                    warships->resize(local_c + 1);

                value = 0;
                if (this->unitsTaskedThisUpdate.numberValue > 0) {
                    do {
                        if (this->unitsTaskedThisUpdate.maximumSizeValue <= value)
                            break;
                        if (this->unitsTaskedThisUpdate.value[value] ==
                            *(int *)((char *)warships->value + local_8))
                            goto next_warboat;
                        ++value;
                    } while (value < this->unitsTaskedThisUpdate.numberValue);
                }

                if (compare < 0) {
                    ai = object->unitAI();
                    value = ai->currentAction();
                    if (value != -1) {
                        ai = object->unitAI();
                        value = ai->currentOrderPriority();
                        if (value >= priority)
                            goto next_warboat;
                    }
                    if (local_c > warships->maximumSizeValue - 1)
                        warships->resize(local_c + 1);
                    result = &this->workingArea;
                    local_8 = *(int *)((char *)warships->value + local_8);
                    value = result->contains(local_8);
                    if (value != 1) {
                        value = result->numberValue;
                        if (value > result->maximumSizeValue - 1)
                            result->resize(value + 1);
                        value = result->numberValue;
                        values = result->value;
                        values[value] = local_8;
                        result->numberValue++;
                    }
                    ++i;
                } else {
                    if (compare > 0) {
                    ai = object->unitAI();
                    value = ai->currentAction();
                    if (value != -1) {
                        ai = object->unitAI();
                        value = ai->currentOrderPriority();
                        if (value <= priority)
                            goto next_warboat;
                        if (local_c > warships->maximumSizeValue - 1)
                            warships->resize(local_c + 1);
                        result = &this->workingArea;
                        local_8 = warships->value[local_c];
                        value = result->contains(local_8);
                        if (value != 1) {
                            value = result->numberValue;
                            if (value > result->maximumSizeValue - 1)
                                result->resize(value + 1);
                            result->value[result->numberValue] = local_8;
                            result->numberValue++;
                        }
                        ++i;
                    }
                    } else {
                    ai = object->unitAI();
                    value = ai->currentAction();
                    if (value != -1) {
                        ai = object->unitAI();
                        value = ai->currentOrderPriority();
                        if (value != priority)
                            goto next_warboat;
                        if (local_c > warships->maximumSizeValue - 1)
                            warships->resize(local_c + 1);
                        result = &this->workingArea;
                        local_8 = warships->value[local_c];
                        value = result->contains(local_8);
                        if (value != 1) {
                            value = result->numberValue;
                            if (value > result->maximumSizeValue - 1)
                                result->resize(value + 1);
                            result->value[value] = local_8;
                            result->numberValue++;
                        }
                        ++i;
                    }
                    }
                }
            }
next_warboat:
            ++local_c;
        } while (local_c < this->warBoats.numberValue);
    }

    local_c = 0;
    if (this->soldiers.numberValue > 0) {
        warships = &this->soldiers;
        tactical2 = this;
        do {
            if (local_c > warships->maximumSizeValue - 1)
                warships->resize(local_c + 1);
            object = tactical2->md->aiPlayer->world->object(warships->value[local_c]);
            if (object != 0 && object->unitAI() != 0) {
                if (local_c > warships->maximumSizeValue - 1)
                    warships->resize(local_c + 1);

                value = tactical2->unitsTaskedThisUpdate.numberValue;
                index = 0;
                tactical = tactical2;
                if (value > 0) {
                    do {
                        if (tactical->unitsTaskedThisUpdate.maximumSizeValue <= index)
                            break;
                        tactical = local_4;
                        if (tactical2->unitsTaskedThisUpdate.value[index] == warships->value[local_c])
                            goto next_soldier;
                        ++index;
                        tactical = local_4;
                    } while (index < value);
                }

                objectGroup = object->master_obj->object_group;
                if (objectGroup == 0x12 || objectGroup == 0x0D) {
                    if (compare < 0) {
                        ai = object->unitAI();
                        value = ai->currentAction();
                        if (value != -1) {
                            ai = object->unitAI();
                            value = ai->currentOrderPriority();
                            if (value >= priority)
                                goto next_soldier;
                        }
                        if (local_c > warships->maximumSizeValue - 1)
                            warships->resize(local_c + 1);
                        value = tactical2->workingArea.numberValue;
                        scan = 0;
                        local_8 = warships->value[local_c];
                        if (value > 0) {
                            do {
                                if (scan >= tactical2->workingArea.maximumSizeValue)
                                    break;
                                if (tactical2->workingArea.value[scan] == local_8)
                                    goto next_soldier;
                                ++scan;
                            } while (scan < value);
                        }
                        goto append_soldier;
                    } else {
                        if (compare > 0) {
                        ai = object->unitAI();
                        value = ai->currentAction();
                        if (value != -1) {
                            ai = object->unitAI();
                            value = ai->currentOrderPriority();
                            if (value > priority) {
                        if (local_c > warships->maximumSizeValue - 1)
                                    warships->resize(local_c + 1);
                                value = tactical2->workingArea.numberValue;
                                scan = 0;
                                local_8 = warships->value[local_c];
                                if (value > 0) {
                                    do {
                                        if (scan >= tactical2->workingArea.maximumSizeValue)
                                            break;
                                        if (tactical2->workingArea.value[scan] == local_8)
                                            goto next_soldier;
                                        ++scan;
                                    } while (scan < value);
                                }
                                goto append_soldier;
                            }
                        }
                    } else {
                        ai = object->unitAI();
                        value = ai->currentAction();
                        if (value != -1) {
                            ai = object->unitAI();
                            value = ai->currentOrderPriority();
                            if (value != priority)
                                goto next_soldier;

                        if (local_c > warships->maximumSizeValue - 1)
                                warships->resize(local_c + 1);
                            result = &tactical2->workingArea;
                            local_8 = warships->value[local_c];
                            value = result->contains(local_8);
                            if (value != 1) {
                                value = result->numberValue;
                            if (value > result->maximumSizeValue - 1)
                                    result->resize(value + 1);
                                result->value[result->numberValue] = local_8;
                                result->numberValue++;
                            }
                            ++i;
                            goto soldier_done;
                        }
                    }
                }
                }
                goto soldier_done;
append_soldier:
                if (value > tactical2->workingArea.maximumSizeValue - 1)
                    tactical2->workingArea.resize(value + 1);
                tactical2->workingArea.value[tactical2->workingArea.numberValue] = local_8;
                tactical2->workingArea.numberValue++;
                ++i;
soldier_done:
                ;
            }
next_soldier:
            ++local_c;
        } while (local_c < tactical2->soldiers.numberValue);
    }

    return i;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F7D90_idleSoldier.cpp
// ---------------------------------------------------------------------------
// 004F7D90 TribeTacticalAIModule::idleSoldier()
// Source: taitacmd.cpp lines 7061-7070
// Size: 231 bytes
// NC: no custom flags (default /O2 /Oy)
//
// Attempt log:
// Probe 1 (prior session): clean for loop, hand-expanded grow Ã¢â‚¬â€? 83.1% positional, 231 bytes
// Probes 2-3 (prior session): do-while with i=0 early, newSize var Ã¢â‚¬â€? prologue + expansion check matched
//   but stuck at 224/231 bytes with copy-loop register allocation + loop branch encoding drift.
//
// New approach (this session): the grow/copy/delete path is the inline
// ManagedArray<int>::operator[] (utmarray.h lines 63-67) exactly as matched at
// 004EA750. idleSoldier's line map puts the grow AND the world->object() call on
// one source line (7063), which is the signature of an inlined operator[] call:
//     obj = md->player->world->object(soldiers[i]);
// The standalone exact match 004EA750 emits the identical copy loop (inc eax +
// [base+eax*4-4] post-increment form), so inlining operator[] should reproduce
// the canonical grow basin instead of the hand-expanded 224/231 variant.
//
// Key findings (struct layout correct):
// - Prologue: push ebx; push ebp; push esi; mov esi,ecx; xor ebx,ebx; push edi
// - +0x114: soldiers ManagedArray (value=+0x114, numberValue=+0x118, maximumSizeValue=+0x120)
// - +0x0F0: md (TribeMainDecisionAIModule*) -> +0xF0: player -> +0x3C: world
// - operator_new at 0054B6F0h, operator_delete at 0054B660h
// - unitAI at 004C7420h (called twice: null-check then currentAction), currentAction at 00413960h,
//   world->object at 00545D30h
// - return obj->id ([edi+4]) on currentAction == -1

void* operator_new(unsigned int size);
void __cdecl operator_delete(void* ptr);

int TribeTacticalAIModule::idleSoldier()
{
    for (int i = 0; i < soldiers.numberValue; i++) {
        RGE_Static_Object* obj = md->player->world->object(soldiers[i]);
        if (obj != 0 && obj->unitAI() != 0) {
            if (obj->unitAI()->currentAction() == -1)
                return obj->id;
        }
    }
    return -1;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F7E80_idleCivilian.cpp
// ---------------------------------------------------------------------------
// VA: 004F7E80 TribeTacticalAIModule::idleCivilian
// PDB source: taitacmd.cpp lines 7075-7160
// Attempt log:
// - Fresh reconstruction follows the exact same-TU idleCivilian overload and
//   idleSoldier donors.  It uses named civilians, civilianExplorers, and
//   this->unitsTaskedThisUpdate ManagedArray members at their proven offsets.
// - The first pass uses explicit resize-before-value accesses.  The second
//   pass uses the period direct operator[] form only in the mode branch, which
//   accounts for the observed inline grow/copy block.
// - Structural reconstruction now matches the original frame, size within
//   12 bytes, and all 23 ordered calls.  Remaining drift is return-block
//   placement and register-sized branch displacements in the final tail.
// - Probes for an explicit second-pass guard, found labels, and for-loop form
//   did not improve emitted code.  The natural direct-return form is retained.
// - Follow-up probes mirrored the original positive loop edge with an explicit
//   return, goto, sibling-overload guard topology, reordered empty/found labels,
//   an explicit empty else, and ~0 failure spelling.  All were codegen duplicates.
//   The remaining structural lead is the original near JL fallthrough to its
//   own -1 epilogue, followed by the found-object epilogue; VC5 keeps an inverted
//   short JGE plus JMP and merges the failure epilogues in this source basin.
// - Tail recovery used a labeled second-pass block with an explicit positive
//   edge to second_loop.  Parent review rejected the constant-false do-while
//   wrapper as control-flow steering.  The natural labeled block is retained.
// - The direct this->unitsTaskedThisUpdate receiver in the second scan restores the
//   original EBP/EDX allocation.  Natural new[] and delete[] preserve the same
//   inline growth code.
// - Natural labels, guards, do/while, for, while, break, and donor-style found
//   returns did not recover the original tail.  The clean natural source is
//   47 bytes different, with all 23 ordered calls aligned.
// Accepted-drift review: the first 736 bytes and all 23 calls match. The
// executable gives second-pass exhaustion its own -1 epilogue. The rebuild
// jumps to the existing shared -1 epilogue. Found-object returns keep the same
// ID. No ManagedArray, object, call, cleanup, or return effect moves.


int TribeTacticalAIModule::idleCivilian(int mode)
{
    RGE_Static_Object* firstObject;
    RGE_Static_Object* secondObject;
    int i = 0;
    ManagedArray<int>& tasked = this->unitsTaskedThisUpdate;
    if (this->civilians.numberValue > 0) {
        ManagedArray<int>* civilians = &this->civilians;
        do {
            if (i > civilians->maximumSizeValue - 1)
                civilians->resize(i + 1);
            if (tasked.contains(civilians->value[i]) != 0)
                goto first_next;

            if (i > civilians->maximumSizeValue - 1)
                civilians->resize(i + 1);
            firstObject =
                this->md->player->world->object(civilians->value[i]);
            if ((firstObject != 0) && (firstObject->unitAI() != 0)) {
                if (i > civilians->maximumSizeValue - 1)
                    civilians->resize(i + 1);
                if (this->isGatherer(civilians->value[i]) == 0) {
                    if (i > civilians->maximumSizeValue - 1)
                        civilians->resize(i + 1);
                    if (this->civilianExplorers.contains(civilians->value[i]) != 0)
                        goto first_next;
                    if (firstObject->unitAI()->currentAction() == -1 &&
                        firstObject->unitAI()->currentOrder() == -1)
                        return firstObject->id;
                }
            }
first_next:
            i++;
        } while (i < this->civilians.numberValue);
    }

    i = 0;
    if (this->civilians.numberValue <= 0)
        return -1;

    {
        ManagedArray<int>* civilians = &this->civilians;
second_loop:
            if (i > civilians->maximumSizeValue - 1)
                civilians->resize(i + 1);
            if (this->unitsTaskedThisUpdate.contains(civilians->value[i]) != 0)
                goto second_next;

            if (i > civilians->maximumSizeValue - 1)
                civilians->resize(i + 1);
            secondObject =
                this->md->player->world->object(civilians->value[i]);
            if ((secondObject != 0) && (secondObject->unitAI() != 0)) {
                if (mode != 0) {
                    if (mode != 3) {
                        if (i > civilians->maximumSizeValue - 1)
                            civilians->resize(i + 1);
                        if (this->isGatherer(civilians->value[i]) != 0)
                            goto second_next;
                    }
                }
                if ((mode != 0) && (mode != 1)) {
                    if (this->civilianExplorers.contains((*civilians)[i]) != 0)
                        goto second_next;
                }
                if (secondObject->unitAI()->currentAction() == -1 &&
                    secondObject->unitAI()->currentOrder() == -1)
                    return secondObject->id;
            }
second_next:
            i++;
            if (i < this->civilians.numberValue)
                goto second_loop;
    }
    return -1;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F81A0_idleCivilian.cpp
// ---------------------------------------------------------------------------
// VA: 004F81A0 TribeTacticalAIModule::idleCivilian
// Attempt log:
// try 1: 004DF520 query returned no normal target, so selected next eligible unclaimed normal after assigned/prior targets: 004F81A0 idleCivilian.
// try 2: started from prior 004F7E80 idleCivilian reconstruction and expanded toward 976B packet: two-pass civilian scan, reserve-list checks, object lookup, AI idle tests, and mode-sensitive fallback.
// try 3: modeled ManagedArray<int> at +0xF4 with resize-before-access pattern, world pointer at +0xF0, object-table lookup through world->md+0x3C.
// try 4: modeled first exclusion array at +0xD58/+0xD5C/+0xD64 and second at +0x104/+0x108/+0x110, matching packet scan loops.
// try 5: modeled first pass requiring object exists, unitAI exists, not gatherer, not in exclusion lists, and action/order both -1.
// try 6: modeled second pass with mode-sensitive gatherer filter and fallback result for mode 3.
// try 7: added ActionState/UnitAI currentAction/currentOrder call surface corresponding to 004C7420 -> 00413960/00413920 in packet.
// try 8: compiled with default flags: source builds, but rebuilt .text is 720B vs original 976B, too short for compare.
// try 9: probed /GX; no code/size change (still 720B), removed flag file.
// try 10: reviewed original: both passes inline every capacity check, allocation/copy/free grow block, exclusion scan, object lookup, and AI-state calls; current source factors ensure_index/contains_limited, collapsing roughly 250B and preventing full diff.
// probe 11 baseline: restored the period ManagedArray<int> surface and the three-argument XYPoint overload.  First pass uses explicit resize/value accesses; the second-pass object lookup uses the inline operator[] grow path shown at 004F8359.
// bounded-session result: scoped civilian-array pointers recovered the EBX/ESI/EDI
// ownership, separate first/second object locals recovered all four 0x10-byte
// stack homes, and the second gatherer read restored the second inline grow block.
// Reversed capacity comparisons matched every resize branch.  The natural bounded
// contains donor shape remained a register-permuted basin; an expanded local scan
// was tested and rolled back because it grew the function by 62 bytes.
// The late first-pass success label and utmarray.h declaration-order probes were
// codegen duplicates.  Final stdlib.h context is retained: 976B size/frame, 25/25
// ordered calls, and 95.17% exact-block coverage (645 positional diff bytes).
// Remaining localized leads are the four contains inner-loop register permutations,
// the first-pass near success jump/epilogue, and the distance-selection x87 tail.
// resumed claim: direct first-pass return and pointer/reference aliases were codegen duplicates.
// natural first-pass for-loop forms moved the success epilogue late, but added a guard or broadened drift;
// named count and pointer variants were rolled back.  The clean do-while reconstruction remains best.
// left in scratch after the 10-hypothesis budget: typed period-plausible source,
// no inline asm; exact promotion remains unresolved.
// resumed structural probes: an outer-guard for duplicated the count test and
// grew to 879/981B; an explicit positive bottom branch duplicated the clean
// 645B output.  The no-outer for and while forms reproduced the prior 605B
// diagnostic basin, but moved lea esi before the initial jle and lost blocks.
// Restored the clean do-while reconstruction; no structural lead remains.
// resumed claim: 22 distinct source, lifetime, control-flow, and context probes
// passed the 20-probe checkpoint.  Direct tasked-array member expressions
// reduced the diff from 645 to 637 bytes.  The period donor comparison spelling
// recovered the target x87 compare block and reduced it to 636 bytes.
// Structured first-pass continues reduced the best clean source to 618 bytes,
// with 25/25 ordered calls, a 0x10 frame, and 96.68% exact-block coverage.
// Separate second-pass index storage reached 616 bytes but lost exact blocks;
// it was not retained.  Top-tested loops, split guards, extra headers, scoped
// indices, and late labels were neutral or worse and were rolled back.
// Final unresolved facts: the original first-pass tail uses a positive near JL
// backedge and a late first-found epilogue.  VC5 keeps an inverted JGE/JMP tail
// and an early found return for every clean source form tested.
// MANAGEDARRAY AUDIT: resize guards, contains bounds, inline growth, copies,
// publication, and value reads match the executable. No template change is
// required.
// Accepted-drift review: the first-found return is early in the rebuild and
// late in the executable. Both read the same object ID after currentOrder. The
// first loop uses equivalent positive versus inverted tails and one count read.
// All 25 calls, x87 comparisons, array effects, and return values match.


void* operator_new(unsigned int size);
void operator_delete(void* ptr);

int TribeTacticalAIModule::idleCivilian(int mode, XYPoint& position, int chooseMode)
{
    float bestUnitDistance;
    int bestUnitID;
    int i;
    RGE_Static_Object* firstObj;
    RGE_Static_Object* secondObj;

    bestUnitID = -1;
    bestUnitDistance = 0;
    i = 0;
    if (this->civilians.numberValue > 0) {
        ManagedArray<int>* civilians = &this->civilians;
        do {
            if (i > civilians->maximumSizeValue - 1)
                civilians->resize(i + 1);
            if (this->unitsTaskedThisUpdate.contains(this->civilians.value[i]) != 0)
                continue;

            if (i > civilians->maximumSizeValue - 1)
                civilians->resize(i + 1);
            firstObj = this->md->player->world->object(civilians->value[i]);
            if ((firstObj != 0) && (firstObj->unitAI() != 0)) {
                if (i > civilians->maximumSizeValue - 1)
                    civilians->resize(i + 1);
                if (this->isGatherer(civilians->value[i]) == 0) {
                    if (i > civilians->maximumSizeValue - 1)
                        civilians->resize(i + 1);
                    if (this->civilianExplorers.contains(civilians->value[i]) != 0)
                        continue;
                    if (firstObj->unitAI()->currentAction() == -1 &&
                        firstObj->unitAI()->currentOrder() == -1)
                        return firstObj->id;
                }
            }
            ++i;
        } while (i < this->civilians.numberValue);
    }

    i = 0;
    if (this->civilians.numberValue > 0) {
        ManagedArray<int>* civilians = &this->civilians;
        do {
            if (i > civilians->maximumSizeValue - 1)
                civilians->resize(i + 1);
            if (this->unitsTaskedThisUpdate.contains(this->civilians.value[i]) != 0)
                goto second_next;

            secondObj = this->md->player->world->object((*civilians)[i]);
            if ((secondObj != 0) && (secondObj->unitAI() != 0)) {
                if (mode != 0) {
                    if (mode != 3) {
                        if (this->isGatherer((*civilians)[i]) != 0)
                            goto second_next;
                    }
                }
                if ((mode != 0) && (mode != 1)) {
                    if (i > civilians->maximumSizeValue - 1)
                        civilians->resize(i + 1);
                    if (this->civilianExplorers.contains(civilians->value[i]) != 0)
                        goto second_next;
                }

                if (secondObj->unitAI()->currentAction() == -1 &&
                    secondObj->unitAI()->currentOrder() == -1) {
                    float distance = secondObj->distance_to_position(
                        (float)position.x, (float)position.y, secondObj->world_z);
                    if (bestUnitID == -1) {
                        bestUnitDistance = distance;
                        bestUnitID = secondObj->id;
                    }
                    else if ((chooseMode == 1 && bestUnitDistance > distance) ||
                             (chooseMode == 0 && bestUnitDistance < distance)) {
                        bestUnitDistance = distance;
                        bestUnitID = secondObj->id;
                    }
                }
            }
second_next:
            ++i;
        } while (i < this->civilians.numberValue);
    }
    return bestUnitID;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F8570_civilian.cpp
// ---------------------------------------------------------------------------
// VA: 004F8570 TribeTacticalAIModule::civilian
// Attempt log:
// initial decompiler-style implementation with explicit expandable civilian array and tasked duplicate scan: same 573-byte size but broad mismatch from offset 2; rebuilt uses 0x0c frame, ESI this, EBX/EBP as byte-offset/count pair instead of original 0x08 frame with EBP as index.
// tried register int i; no codegen change.
// tried hoisted world/obj locals vs inline object lookup; hoisted locals required declarations before goto and did not improve register basin.
// tried for-loop topology instead of do/while; no codegen change.
// tried natural method calls for object/unitAI/currentOrder/distance; call set looks plausible but scheduling/register family remains broad.
// tried canonical inline ManagedArray growth and typed md/player/world ownership;
// this is the current source-shape hypothesis, not a compiler-steering variant.
// probe 2: canonical operator[] growth plus typed md->player->world reduced the
// rebuild to 606 bytes and restored the inline growth topology.
// probe 3: the inlined utmarray.h contains surface and MainDecision +f0 layout
// reached exact size/frame, 13 calls, and 93.9% shape similarity.
// probes 4-5: float/integer zero spelling and best-local declaration order were
// duplicate codegen; probe 6's natural bestDistance > dist spelling restored the
// original x87 compare family and moved to the exact-codegen stage.
// probes 7 and 9: copied the exact contains local/parameter source surface;
// duplicate. Probe 8 reordered ordinary entry initialization, giving the
// immediate zero store and 175-instruction body, but emitted the two entry
// stores in reverse order and left a six-byte tasked-scan register permutation.
// probe 10: ordinary civilians/task references around contains fixed that
// register permutation. The clean source was exact in size/frame/CFG/ordered
// calls with a 10-byte strict drift only in the two entry initialization stores.
// probe 11: natural sentinel-first initialization (bestUnitID=-1, then
// bestUnitDistance=0) produced a full MATCH; no inline asm or opaque scaffolding.

void* operator_new(unsigned int);
void operator_delete(void*);

int TribeTacticalAIModule::civilian(XYPoint& pos, int chooseMode, int order1, int order2, int order3, int allow103)
{
    float bestUnitDistance;
    int bestUnitID;
    int i;
    RGE_Static_Object* obj;
    ManagedArray_int& civilians = this->civilians;
    ManagedArray_int& tasked = this->unitsTaskedThisUpdate;

    bestUnitID = -1;
    bestUnitDistance = 0;
    i = 0;
    if (this->civilians.numberValue > 0) {
        do {
            if (tasked.contains(civilians[i]) != 0)
                goto next;

            obj = this->md->player->world->object(this->civilians[i]);
            if (obj != 0 && obj->unitAI() != 0) {
                if (allow103 != 0 || obj->master_obj->id != 0x103) {
                    if (obj->unitAI()->currentOrder() != order1 &&
                        obj->unitAI()->currentOrder() != order2 &&
                        obj->unitAI()->currentOrder() != order3) {
                        float dist = obj->distance_to_position((float)pos.x, (float)pos.y, obj->world_z);
                        if (bestUnitID == -1) {
                            bestUnitDistance = dist;
                            bestUnitID = obj->id;
                        } else if ((chooseMode == 1 && bestUnitDistance > dist) ||
                                   (chooseMode == 0 && bestUnitDistance < dist)) {
                            bestUnitDistance = dist;
                            bestUnitID = obj->id;
                        }
                    }
                }
            }
next:
            ++i;
        } while (i < this->civilians.numberValue);
    }
    return bestUnitID;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F87B0_unit.cpp
// ---------------------------------------------------------------------------
// 004F87B0 TribeTacticalCommand::unit
// taitacmd.cpp: 7336-7374
// Attempt log:
// - Prior worker used helper-factored growth/filter code and stopped at 704B;
//   the packet proves five inline ManagedArray growth blocks plus one real
//   resize call, so this candidate restores those source-level surfaces.
// - Baseline candidate: civilians, soldiers, and boats are the named
//   ManagedArray<int> members at +0xF4, +0x114, and +0x134.  The null-object
//   UnitAI filter is intentionally retained because the executable calls
//   unitAI with a null receiver before checking the three wildcard filters.
// - Probe 1 baseline: 1127B, 35/35 ordered calls, 92.60% shape; helper
//   factoring was gone but the second/third success paths still had duplicate
//   explicit growth checks.
// - Probe 2: returned `soldiers[i]`/`boats[i]` directly through the inline
//   operator[] and reached exact size (1071B), leaving a localized boat-loop
//   topology hunk.  Probe 3 changed that scan to the natural top-tested while
//   form and reduced the remaining drift to 33 bytes.
// - Probes 4-5: a function-wide civilians pointer/reference alias perturbed
//   the prologue and broad register basin; rolled back.  Probe 6 used a
//   branch-local typed result-array pointer, assigned only on civilian success,
//   preserving the original EDI receiver into the late shared return.
// - Exact candidate: 1071B, 35/35 ordered calls, 100% shape, 0-byte strict
//   diff.  The null-receiver call and branch-local result pointer are retained
//   because both are directly supported by the original instruction flow.
// Source audit: the null-receiver UnitAI call is the executable's observed
// short-circuit order, including its apparent original bug; the surrounding
// player/AI/object surfaces now use the proven polymorphic boundaries and
// named member offsets without raw address plumbing.


int TribeTacticalAIModule::unit(int player, int currentAction, int currentTargetType)
{
    int i = 0;
    ManagedArrayInt* resultArray;

    while (i < this->civilians.numberValue) {
        RGE_Static_Object* object = this->md->aiPlayer->world->object(this->civilians[i]);
        if (object == 0 && object->unitAI() == 0) {
            if (player != -1) {
                if (object->unitAI()->currentAction() != player)
                    goto next_civilian;
            }
            if (currentAction != -1) {
                if (object->unitAI()->currentTarget() != currentAction)
                    goto next_civilian;
            }
            if (currentTargetType == -1) {
                resultArray = &this->civilians;
                goto found_civilian;
            }
            if (object->unitAI()->currentTargetType() == currentTargetType) {
                resultArray = &this->civilians;
                goto found_civilian;
            }
        }
next_civilian:
        ++i;
    }

    i = 0;
    while (i < this->soldiers.numberValue) {
        RGE_Static_Object* object = this->md->aiPlayer->world->object(this->soldiers[i]);
        if (object == 0 && object->unitAI() == 0) {
            if (player != -1) {
                if (object->unitAI()->currentAction() != player)
                    goto next_soldier;
            }
            if (currentAction != -1) {
                if (object->unitAI()->currentTarget() != currentAction)
                    goto next_soldier;
            }
            if (currentTargetType != -1) {
                if (object->unitAI()->currentTargetType() != currentTargetType)
                    goto next_soldier;
            }
            return this->soldiers[i];
        }
next_soldier:
        ++i;
    }

    i = 0;
    while (i < this->boats.numberValue) {
        RGE_Static_Object* object = this->md->aiPlayer->world->object(this->boats[i]);
        if (object == 0 && object->unitAI() == 0) {
            if (player != -1) {
                if (object->unitAI()->currentAction() != player)
                    goto next_boat;
            }
            if (currentAction != -1) {
                if (object->unitAI()->currentTarget() != currentAction)
                    goto next_boat;
            }
            if (currentTargetType != -1) {
                if (object->unitAI()->currentTargetType() != currentTargetType)
                    goto next_boat;
            }
            return this->boats[i];
        }
next_boat:
        ++i;
    }
    return -1;

found_civilian:
    if (i > resultArray->maximumSizeValue - 1)
        resultArray->resize(i + 1);
    return resultArray->value[i];

}

// ---------------------------------------------------------------------------
// PDB source owner: 004F8BE0_busyWithAction.cpp
// ---------------------------------------------------------------------------
int TribeTacticalAIModule::busyWithAction(int object_id, int action_id) {
    RGE_Static_Object* obj = this->md->aiPlayer->world->object(object_id);
    if (obj != 0) {
        UnitAIModule* ai = obj->unitAI();
        if (ai != 0) {
            if (obj->unitAI()->currentAction() == action_id) {
                return 1;
            }
        }
    }
    return 0;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F8C30_displayCivilianDistribution.cpp
// ---------------------------------------------------------------------------
// 004F8C30 TribeTacticalAIModule::displayCivilianDistribution
// Observed owner. The recovered body is empty in the current source bank.

void TribeTacticalAIModule::displayCivilianDistribution()
{
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F8C40_updateNeededResources.cpp
// ---------------------------------------------------------------------------
// 004F8C40 TribeTacticalAIModule::updateNeededResources
// PDB: taitacmd.cpp:7453-7527, 478 bytes
// Attempt log:
// - v1: direct reconstruction from packet/decompiler with local arrays and real member-call surfaces.
// - v2: corrected sn from pointer to embedded array at +0x194 (sn[0x93] observed at +0x3e0).
// - v3: added/reused output pointer local to probe original 0x34 frame and register allocation; optimized out.
// - v4: modeled assignedResource as 5 ints: counter at [0], flags at [1..4], matching original 0x34 frame.
// - v5: made loop index register to try to force ESI index / EDI this allocation.
// - v6: introduced self local and used it for member accesses to probe this-pointer register allocation.
// - v7: reordered local array declarations so assignedResource occupies low stack offsets like original.
// - v8: grouped arrays in a local struct to force assigned/tempNeeded/tempDiff contiguous stack layout.
// - v9: reordered one-time array initialization to match original flag/temp output stack stores.
// - v10: tried a fixed four-entry initialization loop; VC5 kept the loop and
//   lost the original unrolled stores, so it was restored.
// - v11: replaced raw md subobject casts with canonical buildAI/resourceAI
//   members and restored the proven AIModule, ResourceItem, and tactical sizes;
//   emitted code stayed unchanged while source ownership became typed.
// - v12: reordered initialization to the decompiler/PDB order; block shape
//   worsened, so the original interleaved source order was restored.
// - v13: removed the self alias; emitted code stayed unchanged.
// - v14: initialized the fallback assigned-resource pointer at slot 1; this
//   changed prologue register coloring and was restored.
// - v15: separated the local arrays as a control; it preserved the frame but
//   changed the prologue and was restored.
// - v16: rewrote the final copy as an indexed four-entry loop. VC5 reduced the
//   size to 478 bytes and kept the natural member ownership; this is the
//   current clean reconstruction.
// - v17: tested an early best-resource sentinel; VC5 emitted the same code.
// - v18: changed the final indexed loop to a counted for form; VC5 emitted the
//   same code.
// Revisit v19: restored three direct four-entry arrays and a separate scalar;
// VC5 reduced the frame to 0x30 and worsened the result to diff 425.
// Revisit v20: moved the difference-pointer declaration after scalar locals;
// VC5 emitted duplicate code at diff 403.
// Revisit v21: removed the invented aggregate and used direct typed arrays;
// VC5 kept the frame but worsened the result to diff 414.
// Revisit v22: used typed parallel pointers for the final copy; VC5 emitted
// 482 bytes and worsened the result to diff 419.
// Revisit v23: restored the PDB-proven four-entry assignedResource array and
// kept the byte offset as its own scalar, rather than folding the offset into
// a fifth array slot. This tests the original local ownership and indexing.
// Revisit v24: replaced the fallback pointer walk with direct indexed array
// reads. VC5 now emits the original independent pointer setup and loop bytes;
// the remaining mismatch is the earlier initialization register basin.
// Revisit v25: a four-entry local aggregate plus a separate offset retained
// the 403-byte metric but changed the final copy to a countdown basin. It was
// rejected because the PDB names three separate arrays.
// Revisit v26: register hints for the difference cursor and first result were
// codegen duplicates. The natural unqualified declarations remain authoritative.
// BLOCKER: the current typed reconstruction has the exact frame and 478-byte
// size, eight ordered calls, and correct field offsets. It remains non-exact:
// the first mismatch is local initialization at +0x2B. The original keeps -1
// in EDX and EAX and zero in ECX. VC5 keeps only -1 in EAX and zero in ESI.
// The first difference scan also swaps the original EBP result and EBX cursor.
// The indexed fallback and final copy preserve the original pointer topology,
// but no period-plausible source change has recovered the early colors. Leave
// this source in scratch.

void TribeTacticalAIModule::updateNeededResources()
{
    int assignedResource[4];
    int tempNeededResource[4];
    int tempResourceDifference[4];
    int i;
    int* diffPtr;
    int bestResource;
    int bestDifference;
    int offset;

    this->md->buildAI.mostNeededResource(&this->neededResources, this->sn[0x93]);

    i = 0;
    tempResourceDifference[0] = -1;
    tempNeededResource[0] = -1;
    assignedResource[0] = 0;
    tempResourceDifference[1] = -1;
    tempNeededResource[1] = -1;
    assignedResource[1] = 0;
    tempResourceDifference[2] = -1;
    tempNeededResource[2] = -1;
    assignedResource[2] = 0;
    diffPtr = this->resourceDifferenceValue;
    tempResourceDifference[3] = -1;
    tempNeededResource[3] = -1;
    assignedResource[3] = 0;

    do {
        int resource = this->md->resourceAI.resource(i);
        int needed = this->neededResources.value(i);
        i++;
        *diffPtr = resource - needed;
        diffPtr++;
    } while (i < 4);

    offset = 0;
    do {
        bestResource = -1;
        bestDifference = 0x7fffffff;
        i = 0;
        do {
            if (i == 0) {
                if (this->md->resourceAI.resource(i) >= this->sn[0xbe]) {
                    goto next_resource;
                }
            }
            if (i == 1) {
                if (this->md->resourceAI.resource(i) >= this->sn[0xbf]) {
                    goto next_resource;
                }
            }
            if (i == 3) {
                if (this->md->resourceAI.resource(i) >= this->sn[0xc1]) {
                    goto next_resource;
                }
            }
            if (i == 2) {
                if (this->md->resourceAI.resource(i) >= this->sn[0xc0]) {
                    goto next_resource;
                }
            }
            if (this->neededResources.value(i) > 0) {
                if ((bestResource == -1 || this->resourceDifferenceValue[i] < bestDifference) && assignedResource[i] == 0) {
                    bestDifference = this->resourceDifferenceValue[i];
                    bestResource = i;
                }
            }
next_resource:
            i++;
        } while (i < 4);

        if (bestResource == -1) {
            i = 0;
            do {
                if ((bestResource == -1 || this->resourceDifferenceValue[i] < bestDifference) && assignedResource[i] == 0) {
                    bestDifference = this->resourceDifferenceValue[i];
                    bestResource = i;
                }
                i++;
            } while (i < 4);
        }

        assignedResource[bestResource] = 1;
        *(int*)((char*)tempNeededResource + offset) = bestResource;
        *(int*)((char*)tempResourceDifference + offset) = bestDifference;
        offset += 4;
    } while (offset < 0x10);

    i = 0;
    for (; i < 4; i++) {
        int resource = tempNeededResource[i];
        int difference = tempResourceDifference[i];
        this->neededResourceValue[i] = resource;
        this->resourceDifferenceValue[resource] = difference;
    }
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F8E20_updateGathererDistribution.cpp
// ---------------------------------------------------------------------------
// 004F8E20 TribeTacticalAIModule::updateGathererDistribution
// Attempt log:
// 1: broad reconstruction from packet: gatherer task counts, age/research special distribution, default weighted percentages, negative-share correction and final food/wood remainder split.
// 2: fixed zero-sized local class gap and compiled; best attempt reaches exact 1369-byte size.
// 3: first mismatch is frame/prologue: rebuilt uses 0x10 frame and pushes EDI before zeroing desired counts, while original uses 0x0C frame, delays EDI push, keeps zero in EAX and zero/index in EBP.
// 4: modeled gatherer stride 0x18, count +0x9CC, desired count +0x9D0, current task/target/priority fields, and resource-id validation scan.
// 5: modeled special cases for advancing ages/research readiness and the 5-priority retask stamping loops for nonzero/non-minus-one gatherers.
// 6: modeled default weighted distribution using integer percent division and late negative distribution correction/remainder split.
// 7: remaining mismatch is broad source/layout: original is highly ordered around explicit stack locals at esp+10/14/18, duplicated age2/age3/age4 blocks, magic multiply divisions, and shared tails; current source has behavior-like structure but wrong register/liveness/block layout. Not accepted_drift-safe.
// 8: replaced the first resource-ID boolean temporary with the bounded scan index as the natural not-found guard; frame reached 0x0C and positional diff improved, but the research call surface remains unresolved.
// 9: replaced guessed ageTime calls with the proven resource(1) calls and inlined the four percent products; all 15 direct call sites now align.
// 10: modeled UnitData, ManagedArray ownership, and the proven data1 cursor; the gatherer stride/address shape improved and the source remains period-plausible.
// 11: rewrote distribution totals and negative-resource correction as pointer loops; exact-block coverage improved to 43.37%, but the prologue remains structurally different.
// 12: retained the desired-distribution cursor and corrected array index ownership from original stores; current structural best is 1258 bytes (91.8919%) with 100% ordered-call alignment.
// 13: tested explicit absolute-remainder parity; it improved positional diff by one byte but reduced shape slightly, and remains the current clean reconstruction after the 10-hypothesis budget.
// 14: nested the age dispatch in original order and removed the incorrect age1-to-age3 and age2-to-age4 fallbacks; structural shape improved.
// 15: corrected the age4 no-research path to write desired distribution slots 0, 1, and 3, as shown by the original stores.
// 16: tested weighted percentage operand order; VC5 emitted the same arithmetic basin.
// 17: cached the proven object gameID after the action/type/state guard; this matches the original EDI overwrite before the first task-list scan and improved the first scan block.
// 18: separated literal actual-distribution clears from the outer loop index; this improved positional diff by four bytes but did not solve the prologue.
// 19: tried a structured found-label task scan to mirror the original skip-zero CFG; it worsened block shape and was rolled back.
// 20: declared the special-result local before the desired cursor; this improved whole-function liveness by seven bytes and remains plausible source order.
// 21: used pointer dereference spelling for first-slot desired writes; VC5 emitted a duplicate, so no codegen lead was found.
// 22: moved outer-index initialization between the first two clears to mirror stack-store order; it worsened codegen and was rolled back.
// Final clean reconstruction: natural typed ownership, corrected age dispatch and slot writes, 15 ordered calls aligned; remaining gap is structural prologue/CFG layout.
// Managed pass: 20 meaningful probes confirmed the pinned 1369-byte source as
// the best clean natural reconstruction (1237 positional bytes, 83.93% shape,
// 48.21% exact-block coverage, 15/15 ordered calls, and a 0x0C frame).
// Evidence-led layout correction: the resource scan fields include a proven
// DA8-DB8 gap, builtFirstGranary is at +F8C, and zoomingToNextAge is at +FA4.
// The earlier single-field model wrote the wrong member, even though its code
// size stayed equal. The corrected model improved exact blocks and is retained.
// Rejected managed probes: initialization reordering, found-label scan CFG,
// unsigned remainder parity, bool special flag, declaration-order changes,
// receiver aliases, sum-count aliases, nested age syntax, and standard-header
// combinations either worsened codegen or emitted the same bytes. Polymorphic
// donor-supported type surfaces also emitted the same bytes. The remaining
// blocker is structural prologue/register scheduling and the first-loop scan
// CFG, not call identity or field ownership.
// Follow-up worker validation: the pinned source still builds at 1369 bytes,
// with a 0x0C frame, 15 ordered calls, 83.93% shape, and 1237 differing bytes.
// Tested Ghidra-shaped task-scan labels, local_4 reuse for the negative count,
// initial-clear order, final remainder spellings, canonical sn-array layout,
// nested MainDecision ownership, and top-level object lifetime. The best new
// natural codegen was 1232 differing bytes but lost structural coverage; it
// was restored. The tested scan and prologue variants were worse or duplicate.

void TribeTacticalAIModule::updateGathererDistribution()
{
    int i;
    int gSTT;
    int gAction;
    int local_4=0;
    int* g;
    int* distribution;
    actualGathererDistribution[0]=0;
    actualGathererDistribution[1]=0;
    actualGathererDistribution[2]=0;
    actualGathererDistribution[3]=0;
    if (numberGatherersValue > 0) {
        g = &gatherers[0].data1;
        do {
            RGE_Static_Object* o=md->object(g[-1]);
            if (o && o->unitAI()) {
                gAction=o->unitAI()->currentAction();
                gSTT=g[0];
                g[3]=o->unitAI()->currentTarget();
                if (gAction==0x261 && o->master_obj->id==0x103 && gSTT) {
                    int gameID=o->id;
                    for (i=0;i<this->unitsTaskedThisUpdate.numberValue && i<this->unitsTaskedThisUpdate.maximumSizeValue;i++)
                        if (this->unitsTaskedThisUpdate.value[i]==gameID) break;
                    if (i==this->unitsTaskedThisUpdate.numberValue || i==this->unitsTaskedThisUpdate.maximumSizeValue) { g[0]=0; }
                }
                if (gSTT>=0 && gSTT<=3) {
                    if (gAction==0x261 || gAction==0x265) ++actualGathererDistribution[gSTT];
                    else {
                        for (i=0;i<this->unitsTaskedThisUpdate.numberValue && i<this->unitsTaskedThisUpdate.maximumSizeValue;i++) if (this->unitsTaskedThisUpdate.value[i]==g[-1]) { ++actualGathererDistribution[gSTT]; break; }
                    }
                }
            }
            local_4++;
            g += 6;
        } while (local_4 < numberGatherersValue);
    }

    distribution=desiredGathererDistribution;
    int special=0;
    *distribution=0;
    distribution[1]=0;
    distribution[2]=0;
    distribution[3]=0;
    if (inAge(1)) {
        if (this->sn[0xB5]==1) {
            if (this->md->buildAI.readyToResearch(2,1) && *(int*)((char*)this->md + 0x122C)!=-1 && (this->md->resourceAI.resource(1)>120 || builtFirstGranary==1)) {
                *distribution=desiredNumberGatherersValue;
                g=&gatherers[0].data1;
                for (i=0;i<numberGatherersValue;i++,g+=6) if (g[0]!=0 && g[0]!=-1) g[1]=5;
                *(int*)((char*)this + 0xFA4)=1;
                special=1;
            } else {
                *(int*)((char*)this + 0xFA4)=0;
                distribution[1]=desiredNumberGatherersValue;
                special=1;
            }
        } else *(int*)((char*)this + 0xFA4)=0;
    } else if (inAge(2)) {
        if (this->sn[0xB6]==1) {
            if (this->md->buildAI.readyToResearch(3,1) && (this->md->resourceAI.resource(1)>240 || (this->md->resourceAI.resource(1)>120 && *(int*)((char*)this->md + 0x122C)<20))) {
                *distribution=desiredNumberGatherersValue;
                g=&gatherers[0].data1;
                for (i=0;i<numberGatherersValue;i++,g+=6) if (g[0]!=0 && g[0]!=-1) g[1]=5;
                *(int*)((char*)this + 0xFA4)=1;
                special=1;
            } else {
                *(int*)((char*)this + 0xFA4)=0;
                distribution[1]=desiredNumberGatherersValue;
                special=1;
            }
        } else *(int*)((char*)this + 0xFA4)=0;
    } else if (inAge(3)) {
        if (this->sn[0xB7]==1) {
            if (this->md->buildAI.readyToResearch(4,1)) {
                *distribution=desiredNumberGatherersValue/2;
                distribution[3]=distribution[0];
                g=&gatherers[0].data1;
                for (i=0;i<numberGatherersValue;i++,g+=6) if (g[0]!=0 && g[0]!=3 && g[0]!=-1) g[1]=5;
                *(int*)((char*)this + 0xFA4)=1;
                special=1;
            } else {
                *distribution=desiredNumberGatherersValue/3;
                distribution[1]=distribution[0];
                distribution[3]=distribution[0];
                *(int*)((char*)this + 0xFA4)=0;
                special=1;
            }
        } else *(int*)((char*)this + 0xFA4)=0;
    } else *(int*)((char*)this + 0xFA4)=0;

    if (!special) {
        desiredGathererDistribution[2]=(this->sn[0x77]+this->sn[0x9E])*desiredNumberGatherersValue/100;
        desiredGathererDistribution[3]=(this->sn[0x76]+this->sn[0x9F])*desiredNumberGatherersValue/100;
        desiredGathererDistribution[1]=(this->sn[0x78]+this->sn[0x9D])*desiredNumberGatherersValue/100;
        desiredGathererDistribution[0]=(this->sn[0x75]+this->sn[0x9C])*desiredNumberGatherersValue/100;
    }

    int sum=0;
    distribution = desiredGathererDistribution;
    for (i=4;i!=0;i--) { sum += *distribution; distribution++; }
    int rem=desiredNumberGatherersValue-sum;
    int negCount=0, negSum=0;
    int* difference = resourceDifferenceValue;
    for (i=4;i!=0;i--) {
        if (*difference<0) { negSum -= *difference; negCount++; }
        difference++;
    }
    if (negCount>0) {
        int count=negCount;
        int* needed=neededResourceValue;
        do {
            int idx=*needed++;
            desiredGathererDistribution[idx] -= (resourceDifferenceValue[idx]*rem)/negSum;
            count--;
        } while (count!=0);
    }
    sum=0;
    distribution=desiredGathererDistribution;
    for (i=4;i!=0;i--) { sum += *distribution; distribution++; }
    rem=desiredNumberGatherersValue-sum;
    int odd=rem;
    if (odd<0) odd=-odd;
    if (rem>0) {
        int half=rem/2; int other=half; if (odd&1) other++;
        desiredGathererDistribution[0]+=other; desiredGathererDistribution[1]+=half;
    }
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F9380_stopUnit.cpp
// ---------------------------------------------------------------------------
// probe 4: natural virtual-call surface with the nested md->unit object layout

int TribeTacticalAIModule::stopUnit(int param_1, int param_2) {
    RGE_Player* player = this->md->player;
    player->sendUnitAIOrder((int)player->id, param_1, 0x2C2, -1, -1,
        -1.0f, -1.0f, -1.0f, -1.0f, 1, 0, param_2);
    return 1;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F93D0_moveUnit.cpp
// ---------------------------------------------------------------------------
// mirrored the matched stopUnit/groupGatherUnit sibling surface: direct virtual call through md->unit with owner-id at +0x4A

int TribeTacticalAIModule::moveUnit(int param_1, float param_2, float param_3, int param_4) {
    RGE_Player* player = this->md->player;
    player->sendUnitAIOrder((int)player->id, param_1, 0x2C6, -1, -1,
                            param_2, param_3, 1.0f, 1.0f, 1, 0, param_4);
    return 1;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F9420_groupGatherUnit.cpp
// ---------------------------------------------------------------------------
int TribeTacticalAIModule::groupGatherUnit(int param_1, int param_2, float param_3, float param_4, float param_5, float param_6, int param_7) {
    RGE_Player* player = this->md->player;
    player->sendUnitAIOrder((int)player->id, param_1, 0x2D4, param_2, -1,
                            param_3, param_4, param_5, param_6, 1, 0, param_7);
    return 1;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F9470_highLevelTaskExplorer.cpp
// ---------------------------------------------------------------------------
// 004F9470 TribeTacticalAIModule::highLevelTaskExplorer
// Source: taitacmd.cpp lines 7907-7983
// Attempt log:
// - Replaced the parked wrapper/raw-offset scaffold with the packet-supported
//   typed explorer predicate: world->object, repeated UnitAI calls, current
//   action/order checks, held-attribute gate, and taskExplorer(this,id,mode).
// - Member-left positive held-attribute rejection recovered the original x87
//   compare/branch. Nesting the final object->unitAI()->hasOrderOnQueue(0x2C1)
//   call restored VC5's push-before-object evaluation order and matched exactly.
// - Main-agent audit restored canonical polymorphic object/player/world/AI
//   ownership; exact bytes were revalidated after promotion.

int TribeTacticalAIModule::highLevelTaskExplorer(int id, int mode)
{
    RGE_Static_Object* object = this->md->player->world->object(id);
    if (object == 0 || object->unitAI() == 0) {
        return 0;
    }

    UnitAIModule* ai = object->unitAI();
    int action = ai->currentAction();
    if (action == 0x258) {
        return 1;
    }

    ai = object->unitAI();
    action = ai->currentAction();
    if (action != 0x25A) {
        ai = object->unitAI();
        action = ai->currentAction();
        if (action != 0x26A) {
            ai = object->unitAI();
            action = ai->currentAction();
            if (action == 0x25D) {
                return 1;
            }

            if (object->attribute_amount_held > 0.0f) {
                return 0;
            }

            ai = object->unitAI();
            if (ai->currentOrder() == 0x2C6) {
                ai = object->unitAI();
                if (ai->currentOrderPriority() == 100) {
                    return 0;
                }
            }

            ai = object->unitAI();
            if (ai->currentOrder() == 0x2BE) {
                return 0;
            }

            if (object->unitAI()->hasOrderOnQueue(0x2C1) == 1) {
                return 0;
            }

            return this->taskExplorer(id, mode) != 0;
        }
    }
    return 1;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F95B0_highLevelTaskGatherer.cpp
// ---------------------------------------------------------------------------
// 004F95B0 TribeTacticalAIModule::highLevelTaskGatherer
// taitacmd.cpp: 7988-8225
// Attempt log:
// - Prior worker left a broad raw-offset reconstruction (885B rebuilt, 24/32
//   calls).  The source was reset to the same-TU typed tactical-AI surface
//   before further code-generation work.
// - Baseline candidate: named UnitData/gatherer ownership, the real world /
//   object / UnitAI member calls, resource-AI member call, and the natural
//   four-distribution task loop.  The five-word tried array models the binary's
//   object slot at element zero and four task flags at elements one through
//   four; the fallback passes element one as the output flag array.
// - Baseline check: 32/32 ordered calls and the 0x18 frame were recovered, but
//   the clean typed candidate is 910B versus 1018B (50.30% shape, 934 strict
//   diff bytes); the remaining structural gap is return/block topology.
// - Probes: reducing the scan to a four-word flag array improved frame-local
//   layout but did not change the 910B basin; a typed object/flag union and
//   shared failure/success labels were diagnostic variants only.  The union
//   reached 900B/926 diff bytes but lost the proven 0x18 frame and was rolled
//   back.  All typed variants kept the complete 32-call multiset/site order.
// - Left in scratch: canonical typed baseline, unresolved broad VC5 block
//   layout and duplicated-epilogue topology; no accepted drift.
// - Direct indexed/typed gatherer fields recovered the original folded
//   this-relative addressing and raised shape to 66.39%; a named gatherer
//   pointer had better register coloring but wrong field displacements.
// - Initializing taskResult with triedTasking[1..3] removed the unsupported
//   fifth flag slot and recovered most structural islands.  A shared null
//   tail improved this to 1030B/916 diff, with all 32 ordered calls aligned.
// - A shared success-tail variant was diagnostic only (937B/936 diff) and was
//   rolled back.  Remaining blocker: 0x1C versus 0x18 frame and stack-home/
//   register-color differences; checker remains in STRUCTURAL RECONSTRUCTION.
// - Replaced the raw debug-file address with the named source string. This does
//   not change code generation.
// - Continued probes: a positive object/UnitAI guard restored the late null
//   return; desired[-4] < *desired restored the paired distribution cursor.
// - Continued probes: direct task-result predicates removed false stack stores.
//   A gatherer pointer re-anchor after the first task branch restored the
//   original register colors and the strongest clean nonexact result: 962B,
//   83.93% shape, 421 strict-diff bytes, and the 0x18 frame.
// - Separate found-index, union-overlay, array-slot, and header-context probes
//   did not improve this result and were rolled back.
// - Current worker probes: taskResult-first flag initialization reduced the
//   strict diff to 418B and raised shape to 84.23% without changing the 0x18
//   frame or 32-call order. Cursor rewrites, direct indexing, object-window
//   overlays, and tail-label variants were worse or codegen duplicates.
// - The remaining structural gap is the target's late success/failure block
//   order and its one extra instruction; no supported exact source was found.

extern float DAT_005756f0;

int TribeTacticalAIModule::highLevelTaskGatherer(int id, ulong param)
{
    UnitData* gatherer;
    unsigned long now;
    RGE_Static_Object* gathererObj;
    int triedTasking[4];
    UnitAIModule* ai;
    int remaining;
    int task;
    int* tried;
    int* desired;
    int i;
    int taskResult;

    i = 0;
    taskResult = 0;
    triedTasking[1] = 0;
    triedTasking[2] = 0;
    triedTasking[3] = 0;
    gatherer = this->gatherers;
    for (i = 0; i < this->numberGatherersValue; ++i, ++gatherer) {
        if (gatherer->id == id)
            break;
    }
    if (i >= this->numberGatherersValue)
        goto fail;

    now = debug_timeGetTime(s_taitacmd_cpp, 0x1F5C);
    if (now - this->gatherers[i].lastTaskTime < 5000)
        return 1;
    this->gatherers[i].lastTaskTime = now;

    gathererObj = this->md->player->world->object(id);
    if (gathererObj != 0 && gathererObj->unitAI() != 0) {
        ai = gathererObj->unitAI();
    if (ai->currentAction() == 0x258)
        return 1;
    ai = gathererObj->unitAI();
    if (ai->currentAction() == 0x25A)
        goto success;
    ai = gathererObj->unitAI();
    if (ai->currentAction() == 0x26A)
        goto success;

    if (gathererObj->attribute_amount_held > DAT_005756f0)
        return 1;

    if (this->isFarmer(gathererObj) == 1) {
        remaining = this->civilians.numberValue;
        remaining -= this->numberFarmers();
        if (this->md->resourceAI.resource(0) < 1000 && remaining > 3)
            return 1;
    }

    ai = gathererObj->unitAI();
    if (ai->currentOrder() == 0x2C6) {
        ai = gathererObj->unitAI();
        if (ai->currentOrderPriority() == 100)
            goto success;
    }
    ai = gathererObj->unitAI();
    if (ai->currentOrder() == 0x2BE)
        return 1;

    if (this->gatherers[i].data2 > this->gatherers[i].data3) {
        ai = gathererObj->unitAI();
        if (ai->currentAction() != -1)
            return 1;
        task = this->gatherers[i].data1;
        triedTasking[task + 1] = 1;
        if (this->taskGatherer(this->gatherers[i].id, task, 0, param, 0) == 1)
            return 1;
        this->gatherers[i].data1 = -1;
        this->gatherers[i].data2 = -1;
        this->gatherers[i].data3 = -1;
    }

    // BINARY NOTE: The found record remains live through all later task calls.
    gatherer = &this->gatherers[i];
    tried = triedTasking + 1;
    desired = this->desiredGathererDistribution;
    i = 0;
    task = 0;
    do {
        if (*tried != 1 && desired[-4] < *desired) {
            if (gatherer->data1 == task) {
                ai = gathererObj->unitAI();
                if (ai->currentAction() == 0x265)
                    goto success;
                ai = gathererObj->unitAI();
                if (ai->currentAction() == 0x261)
                    goto success;
            }
            *tried = 1;
            if (this->taskGatherer(gatherer->id, task, 0, param, 0) == 1)
                goto success;
        }
        ++task;
        ++tried;
        ++desired;
        ++i;
    } while (i < 4);

    task = 0;
    if (this->inAge(1) != 0 && *(int*)((char*)this + 0x468) == 1) {
        triedTasking[1] = 1;
    } else if (this->inAge(2) != 0 && *(int*)((char*)this + 0x46C) == 1 && triedTasking[1] == 0) {
        task = 0;
        triedTasking[1] = 1;
    } else if (this->inAge(3) != 0 && *(int*)((char*)this + 0x470) == 1) {
        if (triedTasking[1] == 0) {
            taskResult = this->taskGatherer(gatherer->id, 0, 1, param, 0);
            triedTasking[1] = 1;
        }
        if (taskResult != 0)
            goto normal_success;
        task = 3;
    } else {
        task = 0;
        triedTasking[1] = 1;
    }

    if (this->taskGatherer(gatherer->id, task, 1, param, 0) == 0)
        this->taskGatherer(gatherer->id, -1, 1, param, triedTasking + 1);

normal_success:
        return 1;

success:
        return 1;
    }

fail:
    return 0;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F99B0_taskPlay.cpp
// ---------------------------------------------------------------------------
// 004F99B0 TribeTacticalAIModule::taskPlay
// taitacmd.cpp:8231-8251, 281 bytes
//
// Attempt log:
// - Baseline used waypoint and count temporaries plus a hand-shaped array
//   scan; it was 285 bytes and first diverged while loading the waypoint
//   parameter.
// - Probe 1: use the incoming waypoint/count parameters directly in the
//   natural do/decrement loop, then mirror the exact same-TU ManagedArray
//   scan/growth source and typed mission virtual surface.  Pending checker
//   result.



int TribeTacticalAIModule::taskPlay(int param_1, int* param_2, int param_3,
                                    int param_4, int param_5,
                                    Waypoint* waypoints, int waypointCount)
{
    if (waypoints != 0 && waypointCount > 0) {
        do {
            addWaypoint(param_1, (int)waypoints->x, (int)waypoints->y);
            waypoints++;
            waypointCount--;
        } while (waypointCount != 0);
    }

    ManagedIntArray& arr = this->unitsTaskedThisUpdate;
    int i;
    for (i = 0; i < arr.numberValue; i++) {
        if (i >= arr.maximumSizeValue)
            break;
        if (arr.value[i] == param_1)
            goto dispatch;
    }

    if (arr.numberValue > arr.maximumSizeValue - 1) {
        int newSize = arr.numberValue + 1;
        int* newArray = new int[newSize];
        if (newArray != 0) {
            int j;
            for (j = 0; j < arr.maximumSizeValue && j < newSize; j++) {
                newArray[j] = arr.value[j];
            }
            delete[] arr.value;
            arr.value = newArray;
            arr.maximumSizeValue = newSize;
        }
    }

    arr.value[arr.numberValue] = param_1;
    arr.numberValue++;

dispatch:
    md->player->sendPlayCommand(param_1, param_2, param_3, param_4, param_5);
    return 1;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F9AD0_taskBuilder.cpp
// ---------------------------------------------------------------------------
// VA: 004F9AD0 TribeTacticalAIModule::taskBuilder
// PDB source: taitacmd.cpp lines 8257-8344
// attempt log:
// 1: natural decompiler-shaped source with local class stubs.
// 2: fixed vtable padding for RGE_Static_Object task slot +0x198 and AiPlayer builderTask +0xFC; /O2 /Oy remains 784B vs original 801B, extraction stops.
// 3: tried /GX and /O2 no /Oy: still 784B; /O1 shrinks to 706B; /Od reaches 801B but broad mismatch from offset 0 (wrong debug/EBP codegen), rolled back.
// 4: natural array-removal/tasked-update loops retained; behavior/call set plausible but exact source/register scheduling unresolved.
// 5: restored the binary-proven PlacementState anchor at +0xE4C and the
//    three-int XYZPoint task ABI; the previously dead z conversion is an
//    observed fifth __ftol call and the task record reserves 0x0c bytes.
// 6: restored md->player->world ownership (+0xF0/+0x3C) and the canonical
//    TribeConstructionAIModule placement offset (+0x6C4).
// 7: corrected task-failure cleanup to destroy the ConstructionItem argument,
//    as shown by the original +0xC parameter-home destructor call.
// 8: mirrored the same-TU indexed task scan and un-nested bounded growth copy;
//    these recover the target count/register topology and exact CFG.
// 9-10: typed PlacementState and used the donor's reference ABI for the direct
//    placeStructure relocation without changing emitted code.
// 11: replaced manual deleting-vtable calls with natural delete ConstructionItem;
//     default VC5 /O2 /Oy now matches 801/801 bytes exactly.
// FLAGS: config/flags/004F9AD0_taskBuilder.rsp (/nologo /c /O2 /Oy)
// Final: exact default-flags match; source retains named object/module ownership,
// natural same-TU ManagedArray-style loops, typed XYZPoint/PlacementState ABIs,
// and ordinary C++ cleanup. No inline asm or compiler-steering scaffolding.

void* operator_new(unsigned int); void operator_delete(void*);

int TribeTacticalAIModule::taskBuilder(int id, BuildItem* item, ConstructionItem* con, ulong flags) {
    if (item == 0) {
        item = this->md->buildAI.nextBuildableItem(0);
        if (item == 0) return 0;
    }
    if (con == 0) {
        con = this->md->constructionAI.placeStructure(item, id, this->placementStateValue, flags);
        if (con == 0) return 0;
    }
    if (id == -1) {
        XYPoint position;
        position.x = (int)con->x();
        position.y = (int)con->y();
        id = this->civilian(&position, 1, 0x2be, 0x2ce, 0x2bc, 0);
    }
    RGE_Static_Object* obj = this->md->player->world->object(id);
    if (obj == 0 || obj->unitAI() == 0) {
        if (con != 0) delete con;
        return 0;
    }
    int tx = (int)con->x();
    int ty = (int)con->y();
    int tz = (int)obj->world_z;
    XYZPoint p; p.x = tx; p.y = ty; p.z = tz; if (obj->task(p, 0x40000000, -1, 0, 1, -1, -1) == 0) {
        if (con != 0) delete con;
        return 0;
    }
    item->setInProgress(1);
    item->setBuilt(0);
    int count = this->civilians.maximumSizeValue;
    int i = 0;
    if (count > 0) {
        while (i < count) { if (this->civilians.value[i] == id) break; i++; }
    }
    if (i < count) {
        if (i < count - 1) {
            do { this->civilians.value[i] = this->civilians.value[i+1]; i++; } while (i < this->civilians.maximumSizeValue - 1);
        }
        this->civilians.numberValue--;
        if (this->civilians.numberValue < 0) this->civilians.numberValue = 0;
    }
    count = this->unitsTaskedThisUpdate.numberValue;
    for (i = 0; i < count; i++) {
        if (i >= this->unitsTaskedThisUpdate.maximumSizeValue)
            break;
        if (this->unitsTaskedThisUpdate.value[i] == id)
            goto have;
    }
    if (count > this->unitsTaskedThisUpdate.maximumSizeValue - 1) {
        int newMax = count + 1;
        int* p = (int*)operator_new(newMax * 4);
        if (p != 0) {
            for (i = 0; i < this->unitsTaskedThisUpdate.maximumSizeValue && i < newMax; i++)
                p[i] = this->unitsTaskedThisUpdate.value[i];
            operator_delete(this->unitsTaskedThisUpdate.value);
            this->unitsTaskedThisUpdate.value = p; this->unitsTaskedThisUpdate.maximumSizeValue = newMax;
        }
    }
    this->unitsTaskedThisUpdate.value[this->unitsTaskedThisUpdate.numberValue] = id;
    this->unitsTaskedThisUpdate.numberValue++;
have:
    if (con->typeID() == 0x114) this->wonderInProgressValue = 1;
    this->md->aiPlayer->builderTask(id, con->typeID(), con->x(), con->y(), item->uniqueID());
    if (con != 0) delete con;
    return 1;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004F9E00_taskBuilder.cpp
// ---------------------------------------------------------------------------
// VA: 004F9E00 TribeTacticalAIModule::taskBuilder
// Source: taitacmd.cpp lines 8350-8408
// Attempt log:
// 1: natural reconstruction with typed virtual calls and dynamic int-list growth: broad mismatch, 0x18 frame due aggregate/int temps.
// 2: reduced local lifetimes and removed aggregate source temps; still got 0x18 frame.
// 3: marked coordinate temps register to try to keep ftol results in EBX/EBP/EAX; no frame change.
// 4: inline coordinate casts directly into virtual calls to reduce named temp pressure; restored one-slot frame, but cached obj in EBP.
// 5: make obj volatile forced stack reloads but ordered store before test.
// 6: assignment-in-condition with nonvolatile obj restored store-after-test shape but cached obj in EBP.
// 7: restore named x/y/z before builder null check because original does all ftol before null test; code shrank below target and still frame/register mismatch.
// 8: tried narrow /O1 flag as possible code-size/register-pressure probe; smaller object and worse, flag removed.
// 9: tried /O2 /Oy /Ob0 to see if call/virtual inlining context caused frame/register changes; no improvement, flag removed.
// 10: left in scratch: best default family either has exact prologue with obj cached in EBP and delayed ftol, or correct ftol-before-null shape with a 0x18 spill frame. Remaining mismatch is broad register/liveness and virtual-call argument scheduling, not behavior.
// Session sa080eb53d_r1:
// - Reconstructed the first virtual call as canPath(XYZPoint, float, int, float*, int, int, int); the 0xc outgoing aggregate and three ftol results are binary-proven.
// - Mirrored the same-TU ManagedIntArray indexed scan and natural new[]/delete[] bounded copy idiom; this restored the target loop CFG and size family.
// - Split distance_to_object and calculatePriority into sequential locals; this restored the original 505-byte suffix topology.
// - Widened the RGE_Player sendUnitAIOrder player-id arguments to int, recovering the movsx/player-vtable load order and exact bytes.
// - Normalized module ownership to TribeTacticalAIModule -> TribeMainDecisionAIModule -> RGE_Player, preserving the proven offsets and exact output.
// Final: default /O2 /Oy, 505/505 bytes, MATCH; no inline asm or custom flags.


int TribeTacticalAIModule::taskBuilder(int id, RGE_Static_Object* builder)
{
    RGE_Static_Object* builderObj;
    RGE_Static_Object* obj;
    if ((obj = this->md->player->world->object(id)) == 0) return 0;

    builderObj = builder;
    XYZPoint point;
    point.x = (int)builderObj->world_x;
    point.y = (int)builderObj->world_y;
    point.z = (int)builderObj->world_z;

    if (builderObj == 0) {
        if (!obj->canPath(point, 1.0f, -1, 0, 1, -1, -1)) return 0;
    }
    else {
        if (!obj->canPath(point, 1.0f, builderObj->id, 0, 1, -1, -1)) {
            if (builderObj->master_obj->id != 0x114) this->deleteUnit(builderObj->id);
            return 0;
        }
    }

    ManagedArray_int& arr = this->unitsTaskedThisUpdate;
    int i;
    for (i = 0; i < arr.numberValue; i++) {
        if (i >= arr.maximumSizeValue)
            break;
        if (arr.value[i] == id)
            goto found;
    }

    if (arr.numberValue > arr.maximumSizeValue - 1) {
        int newMax = arr.numberValue + 1;
        int* newValues = new int[newMax];
        if (newValues != 0) {
            int j;
            for (j = 0; j < arr.maximumSizeValue && j < newMax; j++) {
                newValues[j] = arr.value[j];
            }
            delete[] arr.value;
            arr.value = newValues;
            arr.maximumSizeValue = newMax;
        }
    }
    arr.value[arr.numberValue] = id;
    arr.numberValue++;

found:
    float distance = builderObj->distance_to_object(obj);
    int priority = this->calculatePriority(distance);
    RGE_Player* player = this->md->player;
    player->sendUnitAIOrder(player->id, id, 0x2be, builderObj->id,
                            player->id, builderObj->world_x, builderObj->world_y,
                            builderObj->world_z, 1.0f, 1, 1, priority);
    return 1;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004FA000_taskRepairer.cpp
// ---------------------------------------------------------------------------
// VA: 004FA000 TribeTacticalAIModule::taskRepairer (366 B)
// PDB source: taitacmd.cpp:8414-8438
// __thiscall, returns 0/1
//
// Attempt log:
// - Replaced the raw-offset/free-function scaffold with the period-typed
//   MainDecision/world lookup, RGE_Static_Object::canPath call, distance and
//   priority calls, ManagedIntArray growth, and player order dispatch.
// - Baseline typed reconstruction follows the exact taskBuilder and
//   taskFollower donors in the same translation unit.
// - Baseline was 366/366 bytes with one relocation mismatch: canPath emitted
//   at vslot +0x198 instead of the observed +0x194.
// - Removed the final padding virtual before the six-argument canPath surface;
//   this restored vslot +0x194 and produced MATCH, 366/366 bytes.
// - Final source keeps named object/world/player ownership and the natural
//   ManagedIntArray scan/growth idiom. Default flags; no inline asm.


int TribeTacticalAIModule::taskRepairer(int id, RGE_Static_Object* repairer)
{
    RGE_Static_Object* object = this->md->player->world->object(id);
    if (object == 0) {
        return 0;
    }

    if (object->canPath(repairer->id, 1.0f, 0, 1, -1, -1) == 0) {
        return 0;
    }

    ManagedIntArray& arr = this->unitsTaskedThisUpdate;
    int i;
    for (i = 0; i < arr.numberValue; i++) {
        if (i >= arr.maximumSizeValue)
            break;
        if (arr.value[i] == id)
            goto dispatch;
    }

    if (arr.numberValue > arr.maximumSizeValue - 1) {
        int newSize = arr.numberValue + 1;
        int* newArray = new int[newSize];
        if (newArray != 0) {
            int j;
            for (j = 0; j < arr.maximumSizeValue && j < newSize; j++) {
                newArray[j] = arr.value[j];
            }
            delete[] arr.value;
            arr.value = newArray;
            arr.maximumSizeValue = newSize;
        }
    }

    arr.value[arr.numberValue] = id;
    arr.numberValue++;

dispatch:
    float distance = repairer->distance_to_object(object);
    int priority = this->calculatePriority(distance);
    RGE_Player* player = this->md->player;
    player->sendUnitAIOrder(player->id, id, 0x2CE, repairer->id,
                            player->id, repairer->world_x, repairer->world_y,
                            repairer->world_z, 1.0f, 1, 0, priority);
    return 1;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004FA170_taskGatherer.cpp
// ---------------------------------------------------------------------------
// 004FA170 TribeTacticalAIModule::taskGatherer (taitacmd.cpp:8444-8839, 1712B)
// Attempt log:
//  - Reconstructed the canonical neededResourceValue[4], sn[256], exclusions[6],
//    ManagedArray growth, resource-search ABI, and natural loop topology from the
//    original assembly and exact same-TU donors.
//  - Prior candidate reached frame 0x30, 32/32 ordered calls, and 82.19% shape,
//    but used generated placeholder virtual methods. This source restores the
//    named RGE_Static_Object and TRIBE_Player surfaces from the original headers;
//    calls at 0x194/0x19C use real canPath/canBidirectionPath signatures.
//  - ABI probe: VC5 requires the XYZPoint overload to precede the integer
//    canPath overload in this declaration surface to emit those two calls at
//    the original addresses. No manual virtual-table padding, raw virtual-table
//    access, inline assembly, or fake volatility is retained.
//  - Confirmed the original calls push the full six/seven argument surfaces;
//    shorter int-only declarations improved shape but did not match the binary
//    call arity and were rolled back. A named resource-base pointer moved the
//    array register closer but added four bytes and was also rolled back.
//  - Follow-up probes separated the initial target from dropsite-output locals,
//    tried assignment-in-condition, and tested five versus six exclusions;
//    these were unchanged or worse and were rolled back. A function-scope
//    reused dropsite pointer increased the frame and was also rolled back.
//  - Fresh r3 evidence confirms the [esp+14h] target home is a real later
//    lifetime: the oracle reloads it for the 0x194/0x19C calls and for the
//    line-8663/8696/8725 distance checks. Same-TU taskRepairer and donor
//    patterns support an ordinary named local, not a synthetic alias.
//  - Tried pointer declaration orders, top-level initialization, explicit
//    retry if/else, a positive sn gate, a do/while resource cursor, and one
//    shared dropsite output local. Declaration and branch forms were codegen
//    duplicates; the cursor and shared-output forms were worse. All rolled
//    back to this clean typed source.
//  - Added the inherited MainDecisionAIModule surface so object calls have their
//    proven owning symbol. The emitted bytes were unchanged, but the declaration
//    now matches the exact same-TU donor ABI and the +0xCEC/+0x1256C layout.
//  - Tested local declaration order, loop form, scalar aliases, standard-header
//    context, a named resource local, and the polymorphic tactical-module surface.
//    These either duplicated the 1758-byte basin or made it worse.
//  - A narrow volatile target-pointer probe moved the result to 1728 bytes and
//    improved shape to 84.55%, but added a reload before the null test. The oracle
//    tests the call result in EBX, then stores EBX to the later stack home, so fake
//    volatility is not retained.
//  - A VC5-small flag lab produced 12 variants in three groups. The default group
//    stayed at 1758 bytes; /O1-style groups changed the frame or size. No variant
//    passed the size, frame, and call-set gates.
//  - BINARY NOTE: the initial target pointer is stored after its null-test value
//    is produced, then reloaded after EBX becomes the resource-array cursor.
//    This is the unresolved controlling allocation fact. No natural source form
//    tested so far reproduces that spill without fake volatility.
//  - Follow-up probes: a parameter reference alias, positive object guard,
//    split and top-level declarations, math-header context, pointer-to-pointer
//    alias, moving resource cursor, conditional resource initialization, and
//    five exclusions. They were duplicates or worse. The moving cursor added
//    one byte; five exclusions changed the frame to 0x2C.
//  - The natural named resourceType copy is now the clean source. It preserves
//    the mutable resource lifetime and improves the source to 1751B versus
//    1712B, 32/32 ordered calls, frame 0x30, and 1581 strict-diff bytes.
//  - Final matching status: unresolved. The first mismatch remains +0x1D,
//    where the oracle homes gathererObj before its null branch. The remaining
//    gap is compiler local-allocation and control-flow reconstruction; leave
//    this canonical source in scratch for a later worker.


int TribeTacticalAIModule::taskGatherer(int p1, int p2, int p3, ulong p4, int* p5)
{
    RGE_Static_Object* gathererObj = this->md->object(p1);
    if (gathererObj == 0) return 0;

    UnitData* g = this->gatherer(p1);
    int resourceType = p2;
    if (g != 0 && g->data2 > g->data3) {
        resourceType = g->target;
    }

    int i = -1;
    int index = 0;
    float drop1 = 0;
    float drop2 = 0;
    int numStorage;
    int maximumResourceDistance;
    int exclusions[6];

    if (resourceType == -1) {
        for (index = 0; index < 4; index++) {
            resourceType = this->neededResourceValue[index];
            if (p5 == 0 || p5[resourceType] != 1) {
                numStorage = -1;
                i = this->md->informationAI.gameIDOfResourceObject(
                        resourceType, p1, &drop1, &drop2, &numStorage, exclusions + 1, 0);
                if (i != -1) {
                    if (numStorage == -1)
                        gathererObj->canPath(i, 1.0f, 0, 1, -1, -1);
                    else
                        gathererObj->canBidirectionPath(i, numStorage, 1.0f, 0, 1, -1, -1);
                    break;
                }
            }
        }
        if (i == -1) return 0;
    }
    else {
        maximumResourceDistance = 0;
        p5 = exclusions + 1;
        for (; maximumResourceDistance < 3; ++maximumResourceDistance) {
            numStorage = -1;
            i = this->md->informationAI.gameIDOfResourceObject(
                    resourceType, p1, &drop1, &drop2, &numStorage, exclusions + 1, index);
            if (i == -1) return 0;
            int result = (numStorage == -1)
                ? gathererObj->canPath(i, 1.0f, 0, 1, -1, -1)
                : gathererObj->canBidirectionPath(i, numStorage, 1.0f, 0, 1, -1, -1);
            if (result != 0) break;
            if (resourceType == 0)
                this->md->informationAI.setResourceObjectValid(resourceType, i, 2);
            else
                this->md->informationAI.setResourceObjectValid(resourceType, i, 0xF);
            *p5 = i;
            ++p5;
            ++index;
            i = -1;
        }
        if (i < 0) return 0;
    }

    RGE_Static_Object* obj = this->md->object(i);
    if (obj == 0) return 0;

    if (this->sn[0xCD] != 1) goto tail;

    if (resourceType == 0) {
        if (this->builtFirstGranary == 1) {
            if (this->builtFirstStoragePit != 1) goto tail;
            if (obj->master_obj->id == 0x3B) {
                maximumResourceDistance = 0;
                RGE_Static_Object* g2 = 0;
                int ng = this->numberAvailableGranaries(&g2, &maximumResourceDistance);
                if (maximumResourceDistance != 0 || ng < 1) goto tail;
                exclusions[0] = this->sn[0xA3];
                int d = (int)gathererObj->distance_to_object(obj);
                if (d <= exclusions[0] ||
                    this->md->informationAI.closestDropsiteValue[0] == -1) goto tail;
                int y = (int)obj->world_y;
                int x = (int)obj->world_x;
                if (this->md->informationAI.acceptablePotentialDropsiteArea(x, y) != 1) goto tail;
                this->md->buildAI.insert(0x44, 1, -1);
                goto tail;
            } else {
                short grp = obj->master_obj->object_group;
                if (grp == 0x1F || grp == 5 || grp == 0x21) goto tail;
                maximumResourceDistance = 0;
                RGE_Static_Object* g2 = 0;
                int np = this->numberAvailableStoragePits(&g2, &maximumResourceDistance, 0);
                if (maximumResourceDistance != 0 || np < 1) goto tail;
                int d = (int)gathererObj->distance_to_object(obj);
                if (d < 0x10) {
                    if (g2 != 0) goto tail;
                }
                this->md->buildAI.insert(0x67, 1, -1);
                goto tail;
            }
        }
    }
    if (this->builtFirstStoragePit != 1 || this->builtFirstGranary != 1) goto tail;
    {
        int np;
        RGE_Static_Object* g2;
        int d;
        maximumResourceDistance = 0;
        g2 = 0;
        np = this->numberAvailableStoragePits(&g2, &maximumResourceDistance, resourceType);
        if (maximumResourceDistance != 0 || np < 1) goto tail;
        exclusions[0] = this->sn[obj->type + 0xA3];
        d = (int)gathererObj->distance_to_object(obj);
        if (d <= exclusions[0]) {
            if (g2 != 0) goto tail;
        }
        this->md->buildAI.insert(0x67, 1, -1);
    }

tail:
    {
        int bound = this->civilianExplorers.maximumSizeValue;
        int j;
        for (j = 0; j < bound; j++) {
            if (this->civilianExplorers.value[j] == p1) break;
        }
        if (j < bound) {
            if (j < bound - 1) {
                do {
                    this->civilianExplorers.value[j] = this->civilianExplorers.value[j + 1];
                    j++;
                } while (j < this->civilianExplorers.maximumSizeValue - 1);
            }
            int n = this->civilianExplorers.numberValue - 1;
            this->civilianExplorers.numberValue = n;
            if (n < 0) this->civilianExplorers.numberValue = 0;
        }
    }

    UnitData* ag = this->addGatherer(p1);
    if (ag == 0) return 0;

    this->actualGathererDistribution[resourceType] = this->actualGathererDistribution[resourceType] + 1;

    {
        int j;
        for (j = 0; j < this->unitsTaskedThisUpdate.numberValue &&
                     j < this->unitsTaskedThisUpdate.maximumSizeValue; j++) {
            if (this->unitsTaskedThisUpdate.value[j] == p1) goto units_tasked;
        }
        this->unitsTaskedThisUpdate[this->unitsTaskedThisUpdate.numberValue] = p1;
        this->unitsTaskedThisUpdate.numberValue++;
    }

units_tasked:
    ag->target = resourceType;
    int amount = this->requiredGatherAmount(resourceType);
    if (p3 == 1) {
        amount = 10;
    } else if (this->sn[0xCB] == 1) {
        if (obj->master_obj->id == 0x3B) {
            amount = (int)obj->attribute_amount_held;
        } else if (resourceType == 1) {
            amount = 0x4B;
        } else if (resourceType == 3) {
            amount = 0x32;
        } else if (resourceType == 2) {
            amount = 0x32;
        }
    } else {
        if (amount < this->sn[0x94]) amount = this->sn[0x94];
        else if (amount > this->sn[0x95]) amount = this->sn[0x95];
    }
    if (this->zoomingToNextAge == 1) amount = 0x14;

    ag->data2 = amount;
    ag->data3 = 0;

    this->md->aiPlayer->taskResourceGatherer(p1, i, obj->owner->id, drop1, drop2);

    if (obj->master_obj->id == 0x30) {
        this->taskElephantGatherers(p1, this->sn[0xCC] - 1, i);
    }
    if (obj->master_obj->id == 0x32) {
        ManagedArrayInt& farms = this->md->informationAI.farmsTaskedThisUpdate;
        int fid = obj->id;
        int bound = farms.numberValue;
        int fj;
        for (fj = 0; fj < bound && fj < farms.maximumSizeValue; fj++) {
            if (farms.value[fj] == fid) return 1;
        }
        farms[farms.numberValue] = fid;
        farms.numberValue++;
    }
    return 1;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004FA820_taskExplorer.cpp
// ---------------------------------------------------------------------------
// 004FA820 TribeTacticalAIModule::taskExplorer
// taitacmd.cpp:8844-8865, 278 bytes
//
// Attempt log:
// - Baseline retained the canonical array and task-dispatch behavior but used
//   a hand-shaped count/capacity scan; it was 282 bytes and diverged at the
//   first bounded-array test.
// - Probe 1: mirror the exact same-TU taskDefender/taskToEnter
//   ManagedArray reference and natural indexed scan/growth source, while
//   retaining the typed unexplored-area and float taskExplorer overloads.
//   Pending checker result.

int TribeTacticalAIModule::taskExplorer(int param_1, int param_2)
{
    ManagedIntArray& arr = this->unitsTaskedThisUpdate;
    int i;

    for (i = 0; i < arr.numberValue; i++) {
        if (i >= arr.maximumSizeValue)
            break;
        if (arr.value[i] == param_1)
            goto dispatch;
    }

    if (arr.numberValue > arr.maximumSizeValue - 1) {
        int newSize = arr.numberValue + 1;
        int* newArray = new int[newSize];
        if (newArray != 0) {
            int j;
            for (j = 0; j < arr.maximumSizeValue && j < newSize; j++) {
                newArray[j] = arr.value[j];
            }
            delete[] arr.value;
            arr.value = newArray;
            arr.maximumSizeValue = newSize;
        }
    }

    arr.value[arr.numberValue] = param_1;
    arr.numberValue++;

dispatch:
    if (param_2 == 1) {
        XYPoint targetPoint;
        if (unexploredArea(param_1, targetPoint) == 1) {
            return taskExplorer(param_1, (float)targetPoint.x,
                                (float)targetPoint.y, 1);
        }
        return taskExplorer(param_1, -1.0f, -1.0f, 1);
    }

    return taskExplorer(param_1, -1.0f, -1.0f, 0);
}

// ---------------------------------------------------------------------------
// PDB source owner: 004FA940_taskExplorer.cpp
// ---------------------------------------------------------------------------
// 004FA940 TribeTacticalAIModule::taskExplorer(int,float,float)
// taitacmd.cpp:8870-8891, 337 bytes
//
// Attempt log:
// - Replaced the decompiler-shaped two-list scaffold with the canonical
//   ManagedArray ownership and the neighboring taskExplorer overload's
//   natural indexed scan/growth form.  Baseline: exact size/frame/calls with
//   only two FPU operand-displacement bytes differing.
// - Probe 1: restored the natural XYPoint x/y argument order in the recursive
//   overload call; MATCH (337/337 bytes).  The source order accounts for VC5's
//   right-to-left evaluation and the observed y-then-x FPU pushes.
// - Final: default /O2 /Oy, typed local layout, no inline asm or codegen-only
//   scaffolding; exact bytes validated.

int TribeTacticalAIModule::taskExplorer(int param_1, float param_2,
                                        float param_3)
{
    ManagedIntArray& arr = this->unitsTaskedThisUpdate;
    int i;

    for (i = 0; i < arr.numberValue; i++) {
        if (i >= arr.maximumSizeValue)
            break;
        if (arr.value[i] == param_1)
            goto dispatch;
    }

    if (arr.numberValue > arr.maximumSizeValue - 1) {
        int newSize = arr.numberValue + 1;
        int* newArray = new int[newSize];
        if (newArray != 0) {
            int j;
            for (j = 0; j < arr.maximumSizeValue && j < newSize; j++) {
                newArray[j] = arr.value[j];
            }
            delete[] arr.value;
            arr.value = newArray;
            arr.maximumSizeValue = newSize;
        }
    }

    arr.value[arr.numberValue] = param_1;
    arr.numberValue++;

dispatch:
    {
        ManagedIntArray& civiliansArray = civilians;
        int count = civiliansArray.numberValue;
        int j;
        for (j = 0; j < count; j++) {
            if (j >= civiliansArray.maximumSizeValue)
                break;
            if (civiliansArray.value[j] == param_1) {
                XYPoint targetPoint;
                if (unexploredArea(param_1, targetPoint) == 1) {
                    return taskExplorer(param_1, (float)targetPoint.x,
                                        (float)targetPoint.y, 1);
                }
                return taskExplorer(param_1, param_2, param_3, 1);
            }
        }
    }

    return taskExplorer(param_1, param_2, param_3, 0);
}

// ---------------------------------------------------------------------------
// PDB source owner: 004FAAA0_taskExplorer.cpp
// ---------------------------------------------------------------------------
// 004FAAA0 TribeTacticalAIModule::taskExplorer (taitacmd.cpp:8897-8913)
// Attempt log:
// 1: Natural implementation with static add_unique helper emitted helper out-of-line; function only 336B.
// 2: Inline both array-add sequences and use the canonical player surface: size matches, but search loops use pointer-walk/test max; 81.60% positional, 30.47% edit.
// 3: While with max locals improves edit to 21.68 but adds duplicate count tests and function too long.
// 4: Copy loop do/while spelling produced no source change/no codegen change.
// 5: For-loop search spelling no codegen change.
// 6: int task player parameter + cast improved tail (edit 20.04%).
// 7: while(1) copy loops improved edit to 14.31 and copy loops match; function still +3/duplicate search tests.
// 8: Goto-shaped search loops worsened to 23.72 edit; rolled back to for-loop search.
// 9: Removed the decompiler-only positive-count guards from all bounded scans;
//    exact same-TU donors then recovered the target size and first scan blocks.
// 10: Reconstructed both lists as ManagedIntArray members at +104 and +d58;
//     output stayed unchanged and the layout is now canonical.
// 11: Fresh typed baseline retained the known 224-byte second-scan drift.
// 12: Explicitly assigned civilian.numberValue before both scans; no code change.
// 13: Guarded do-while repeated scan reduced the byte diff but changed block shape;
//     restored the natural indexed for-loop.
// 14: Separate firstCount and secondCount locals did not change emitted code.
// 15: A canonical civilians ManagedIntArray alias on the repeated scan produced MATCH.
// 16: Scoped that reference to the civilian scan and growth block; MATCH remained.
// Final: exact default-flags output, with canonical list ownership and typed dispatch.

extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl operator_delete(void*);

int TribeTacticalAIModule::taskExplorer(int unit, float x, float y, int flag)
{
    int i = 0;
    int count = this->unitsTaskedThisUpdate.numberValue;
    for (; i < count; i++) {
        if (i >= this->unitsTaskedThisUpdate.maximumSizeValue) break;
        if (this->unitsTaskedThisUpdate.value[i] == unit) goto tasked_done;
    }
    if (count > this->unitsTaskedThisUpdate.maximumSizeValue - 1) {
        int newMax = count + 1;
        int* nv = (int*)operator_new(newMax * 4);
        if (nv != 0) {
            i = 0;
            if (this->unitsTaskedThisUpdate.maximumSizeValue > 0) {
                while (1) {
                    if (i >= newMax) break;
                    nv[i] = this->unitsTaskedThisUpdate.value[i];
                    i++;
                    if (i >= this->unitsTaskedThisUpdate.maximumSizeValue) break;
                }
            }
            operator_delete(this->unitsTaskedThisUpdate.value);
            this->unitsTaskedThisUpdate.value = nv;
            this->unitsTaskedThisUpdate.maximumSizeValue = newMax;
        }
    }
    this->unitsTaskedThisUpdate.value[this->unitsTaskedThisUpdate.numberValue] = unit;
    this->unitsTaskedThisUpdate.numberValue++;

tasked_done:
    if (flag == 1) {
        i = 0;
        for (; i < this->civilians.numberValue; i++) {
            if (i >= this->civilians.maximumSizeValue) break;
            if (this->civilians.value[i] == unit) goto haveExplorer;
        }
        {
            ManagedIntArray& civiliansArray = this->civilians;
            i = 0;
            count = civiliansArray.numberValue;
            for (; i < count; i++) {
            if (i >= civiliansArray.maximumSizeValue) break;
                if (civiliansArray.value[i] == unit) goto haveExplorer;
            }
            if (count > civiliansArray.maximumSizeValue - 1) {
                int newMax = count + 1;
                int* nv = (int*)operator_new(newMax * 4);
                if (nv != 0) {
                    i = 0;
                    if (civiliansArray.maximumSizeValue > 0) {
                        while (1) {
                            if (i >= newMax) break;
                            nv[i] = civiliansArray.value[i];
                            i++;
                            if (i >= civiliansArray.maximumSizeValue) break;
                        }
                    }
                    operator_delete(civiliansArray.value);
                    civiliansArray.value = nv;
                    civiliansArray.maximumSizeValue = newMax;
                }
            }
            civiliansArray.value[civiliansArray.numberValue] = unit;
            civiliansArray.numberValue++;
        }
haveExplorer:
        this->removeGatherer(unit);
    }
    RGE_Player* player = this->md->player;
    player->sendUnitAIOrder((int)player->id, unit, 0x2c1, -1, -1,
                            x, y, -1.0f, 1.0f, 1, 0, 1);
    return 1;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004FAC90_taskFollower.cpp
// ---------------------------------------------------------------------------
// VA: 004FAC90, TribeTacticalAIModule::taskFollower, 260 bytes
// Source: taitacmd.cpp lines 8919-8929
// FLAGS: default
//
// Attempt log:
// - Prior attempts used a hand-shaped count/capacity scan and an all-integer
//   vtable proxy.  They preserved calls but emitted a 256-byte function with
//   register, loop-shape, float-argument, and call-scheduling drift.
// - Current baseline: the canonical ownership was retained, but the hand-shaped
//   scan still produced a 246-byte function and diverged at the first capacity
//   check.
// - Probe 1: mirrored the exact taskWaterExplorer donor's natural
//   ManagedArray reference, bounded for scan, grow/copy/append sequence, and
//   typed float virtual-call signature.  Result: MATCH, 260/260 bytes.
// - Probe 2: replaced the proven player +0x4A raw load with the named
//   RGE_Player::id field from the generated layout.  Emitted code stayed exact;
//   retained as the canonical ownership model.
// - Probe 3: used the generated high-confidence slot-0x30 sendUnitAIOrder
//   name/void signature instead of a placeholder method name/return type;
//   emitted code stayed exact.
// - Final: exact natural ManagedArray source and typed RGE_Player slot-0x30
//   surface; default flags; no inline asm or compiler-steering hacks.
// - Main-agent audit restored canonical destructor ownership and natural
//   new[]/delete[] growth; emitted code remains exact.


int TribeTacticalAIModule::taskFollower(int param_1, int param_2, float param_3, int param_4) {
    ManagedIntArray& arr = this->unitsTaskedThisUpdate;
    int i;
    for (i = 0; i < arr.numberValue; i++) {
        if (i >= arr.maximumSizeValue) break;
        if (arr.value[i] == param_1) goto done;
    }

    if (arr.numberValue > arr.maximumSizeValue - 1) {
        int newSize = arr.numberValue + 1;
        int* newArray = new int[newSize];
        if (newArray != 0) {
            int j;
            for (j = 0; j < arr.maximumSizeValue && j < newSize; j++) {
                newArray[j] = arr.value[j];
            }
            delete[] arr.value;
            arr.value = newArray;
            arr.maximumSizeValue = newSize;
        }
    }

    arr.value[arr.numberValue] = param_1;
    arr.numberValue++;

done:
    {
        RGE_Player* player = md->player;
        player->sendUnitAIOrder(player->id, param_1, 0x2C8, param_2, -1,
                                -1.0f, -1.0f, -1.0f, param_3, 1, 0, param_4);
    }
    return 1;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004FADA0_taskDefender.cpp
// ---------------------------------------------------------------------------
// 004FADA0 TribeTacticalAIModule::taskDefender
// taitacmd.cpp:8935-8946, 260 bytes
//
// int __thiscall TribeTacticalAIModule::taskDefender(int param_1, int param_2, float param_3, int param_4)
// ret 10h cleanup (4 stack params + this in ecx)
//
// === Attempt log ===
// 1: Initial version - class layout structs, new[]/delete[], do-while search loop
//    Prologue OK through offset 13, but register cascade: countÃ¢â€ â€™edx vs ecx
//    Search loop uses pointer arithmetic (add ecx,4) instead of indexed [edi+eax*4]
//    Edit diff: 97/260 (37.3%), positional diff: 213/260 (81.9%)
//    Text size: 272 vs 260 (12 bytes too big)
// 2: Variant lab confirms both do-while and while-break search styles produce identical code
//    Register allocation (countÃ¢â€ â€™edx vs ecx) is the cascade root
// 3: Restored clean source before testing a reference-local ManagedArray surface.
// 4: Reference-local indexed scan/copy plus direct operator new/delete recovered the
//    original 260-byte CFG and array ownership; exact bytes now match.
// 5: The mission slot takes an int, with the proven short field promoted before the
//    call; the typed virtual surface and argument order also match exactly.
// Main-agent audit restored canonical AI/player destructor ownership, named
// sendUnitAIOrder, and natural new[]/delete[] growth; output remains exact.

int TribeTacticalAIModule::taskDefender(int param_1, int param_2, float param_3, int param_4)
{
    ManagedArrayInt& arr = this->unitsTaskedThisUpdate;
    int i;

    for (i = 0; i < arr.numberValue; i++) {
        if (i >= arr.maximumSizeValue)
            break;
        if (arr.value[i] == param_1)
            goto dispatch;
    }

    if (arr.numberValue > arr.maximumSizeValue - 1) {
        int newSize = arr.numberValue + 1;
        int* newVals = new int[newSize];
        if (newVals != 0) {
            int j;
            for (j = 0; j < arr.maximumSizeValue && j < newSize; j++) {
                newVals[j] = arr.value[j];
            }
            delete[] arr.value;
            arr.value = newVals;
            arr.maximumSizeValue = newSize;
        }
    }

    arr.value[arr.numberValue] = param_1;
    arr.numberValue++;

dispatch:
    // Mission dispatch through the typed player order surface.
    {
        RGE_Player* player = this->md->player;
        player->sendUnitAIOrder(
            (int)player->id,
            param_1,
            0x2BD,
            param_2,
            -1,
            -1.0f,
            -1.0f,
            -1.0f,
            param_3,
            1,
            0,
            param_4
        );
    }

    return 1;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004FAEB0_taskWaterExplorer.cpp
// ---------------------------------------------------------------------------
// 004FAEB0 TribeTacticalAIModule::taskWaterExplorer (taitacmd.cpp:8951-8969, 266B)
// Records a unit ID as tasked this update, then dispatches to player.
// FLAGS: /nologo /c /O2 /Oy

void* __cdecl operator_new(unsigned int size);
void __cdecl operator_delete(void* ptr);

// ManagedArray<int> layout
int TribeTacticalAIModule::taskWaterExplorer(int param_1) {
    if (param_1 == -1) {
        return 0;
    }

    ManagedArrayInt& arr = this->unitsTaskedThisUpdate;
    int i;
    for (i = 0; i < arr.numberValue; i++) {
        if (i >= arr.maximumSizeValue) break;
        if (arr.value[i] == param_1) goto done;
    }

    if (arr.numberValue > arr.maximumSizeValue - 1) {
        int newSize = arr.numberValue + 1;
        int* newArray = (int*)operator_new(newSize * 4);
        if (newArray != 0) {
            int j;
            for (j = 0; j < arr.maximumSizeValue && j < newSize; j++) {
                newArray[j] = arr.value[j];
            }
            operator_delete(arr.value);
            arr.value = newArray;
            arr.maximumSizeValue = newSize;
        }
    }

    arr.value[arr.numberValue] = param_1;
    arr.numberValue++;

done:
    {
        RGE_Player* player = md->player;
        player->sendUnitAIOrder((int)player->id, param_1, 0x2C1, -1, -1,
                                 -1.0f, -1.0f,
                                 -1.0f, 1.0f,
                                 1, 0, 1);
    }
    return 1;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004FAFC0_taskWaterTrader.cpp
// ---------------------------------------------------------------------------
// VA: 004FAFC0 TribeTacticalAIModule::taskWaterTrader (410 B)
// PDB source: taitacmd.cpp:8974-9013
// __thiscall, returns 0/1
//
// Attempt log:
// - Replaced the raw-offset scaffold with the period typed object/canPath,
//   owner/player, aiPlayer::taskResourceGatherer, and ManagedArray surfaces.
//   Baseline hypothesis: target object coordinates are converted to XYZPoint,
//   then the player is recorded and taskResourceGatherer is dispatched with
//   the target owner's id.
// - Probe 1: natural source emitted 410/410 bytes with one final relocation
//   mismatch because the dispatch was declared as taskTrader (vslot 0x120).
// - Probe 2: corrected the preceding registerResearch ABI declaration; VC5
//   emitted the same bytes, so the mismatch was not a register/layout issue.
// - Probe 3: the proven vslot 0x124 is taskResourceGatherer, not taskTrader;
//   changing the typed call produced MATCH. Default flags; no inline asm.

int TribeTacticalAIModule::taskWaterTrader(int playerID, int targetID)
{
    RGE_Static_Object* object = this->md->object(playerID);
    if (playerID == -1 || object == 0) {
        return 0;
    }

    RGE_Static_Object* targetObj = this->md->object(targetID);
    if (targetObj == 0) {
        return 0;
    }

    XYZPoint point;
    point.x = (int)targetObj->world_x;
    point.y = (int)targetObj->world_y;
    point.z = (int)targetObj->world_z;
    if (object->canPath(point, 2.0f, targetID, 0, 1, -1, -1) == 0) {
        return 0;
    }

    ManagedIntArray& arr = this->unitsTaskedThisUpdate;
    int i;
    for (i = 0; i < arr.numberValue; i++) {
        if (i >= arr.maximumSizeValue)
            break;
        if (arr.value[i] == playerID)
            goto dispatch;
    }

    if (arr.numberValue > arr.maximumSizeValue - 1) {
        int newSize = arr.numberValue + 1;
        int* newArray = new int[newSize];
        if (newArray != 0) {
            int j;
            for (j = 0; j < arr.maximumSizeValue && j < newSize; j++) {
                newArray[j] = arr.value[j];
            }
            delete[] arr.value;
            arr.value = newArray;
            arr.maximumSizeValue = newSize;
        }
    }

    arr.value[arr.numberValue] = playerID;
    arr.numberValue++;

dispatch:
    this->md->aiPlayer->taskResourceGatherer(playerID, targetID,
                                             (int)targetObj->owner->id,
                                             targetObj->world_x, targetObj->world_y);
    return 1;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004FB160_taskWaterFisher.cpp
// ---------------------------------------------------------------------------
// VA: 004FB160 TribeTacticalAIModule::taskWaterFisher (355 B)
// PDB source: taitacmd.cpp:9019-9049
// __thiscall, returns 0/1
//
// Attempt log:
// - Baseline used raw offset/free-function shims; it was 282 B with the
//   object lookup and final player virtual call surfaces structurally wrong.
// - Probe 1: restore the period typed XYZPoint/canPath surface, the full
//   TribeMainDecisionAIModule::aiPlayer layout, and the natural ManagedArray
//   growth/append idiom shared by the exact taskWaterExplorer/taskTransporter
//   donors. This produced the exact 355-byte structure with a one-byte
//   aiPlayer displacement mismatch because MainDecision was four bytes short.
// - Probe 2: restore MainDecisionAIModule::objects at +0xF4, making its
//   proven size 0x104 and placing aiPlayer at +0x1256C. Result: MATCH.
// - Final: natural typed XYZPoint/canPath and taskResourceGatherer calls with
//   the exact same-TU ManagedArray growth source; default flags, no inline asm.

int TribeTacticalAIModule::taskWaterFisher(int playerID, int targetID, float x, float y)
{
    RGE_Static_Object* object = this->md->object(playerID);
    if (playerID == -1 || object == 0) {
        return 0;
    }

    XYZPoint point;
    point.x = (int)x;
    point.y = (int)y;
    point.z = 1;
    if (object->canPath(point, 1.0f, -1, 0, 1, -1, -1) == 0) {
        return 0;
    }

    ManagedIntArray& arr = this->unitsTaskedThisUpdate;
    int i;
    for (i = 0; i < arr.numberValue; i++) {
        if (i >= arr.maximumSizeValue)
            break;
        if (arr.value[i] == playerID)
            goto dispatch;
    }

    if (arr.numberValue > arr.maximumSizeValue - 1) {
        int newSize = arr.numberValue + 1;
        int* newArray = new int[newSize];
        if (newArray != 0) {
            int j;
            for (j = 0; j < arr.maximumSizeValue && j < newSize; j++) {
                newArray[j] = arr.value[j];
            }
            delete[] arr.value;
            arr.value = newArray;
            arr.maximumSizeValue = newSize;
        }
    }

    arr.value[arr.numberValue] = playerID;
    arr.numberValue++;

dispatch:
    this->md->aiPlayer->taskResourceGatherer(playerID, targetID, 0, x, y);
    return 1;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004FB2D0_taskAttacker.cpp
// ---------------------------------------------------------------------------
// VA: 004FB2D0 TribeTacticalAIModule::taskAttacker
// Source: taitacmd.cpp lines 9056-9125
// Attempt log:
// 1: initial packet/decompiler reconstruction with local stubs and inline ManagedArray<int> add.
// 2: rewrote early failure paths to shared fail label and corrected world pointer chain (+f0/+f0/+3c).
// 3: made attackerID parameter const to avoid early save in ebx; prologue now matches through first object lookup, but function became 1 byte short and fail block placed early.
// 4: replaced direct fail returns with result variable and done label; no placement change.
// 5: expanded RGE_Static_Object virtual surface so vf_10c call lands at vtable +0x10c.
// 6: corrected command id expression: original maps commandFlag==1 to 0x2d9, otherwise 0x2bc.
// 7: rewrote assigned-attacker duplicate scan using direct indexed array access; no size/codegen improvement.
// 8: verified object lookup chain now matches original +0xf0/+0xf0/+0x3c and first prologue matches after const attackerID.
// 9: remaining target-command branch still differs broadly; vtable +0x10c is fixed but stack argument scheduling and command vtable call are wrong.
// 10: final state compiles but check_function cannot compare because rebuilt .text is 544 bytes vs original configured 545; not accepted_drift-safe.
// 11: corrected the PDB ABI to int/float/float/int/int/Waypoint*/int/int/int, restored the
//     same-TU ManagedIntArray growth idiom, modeled md->player->world, and identified the
//     +0x10c call as the zero-argument weaponRange getter used by the 12-argument order call.
// 12: corrected the weaponRange slot count and moveUnit's float/float ABI after the
//     rebuilt call map exposed a +0x108 dispatch and two spurious __ftol calls.
// 13: hoisted the target pointer and target-branch scalar locals to the function
//     scope, matching the old-TU declaration style suggested by the PDB/decompiler.
// 14: moved the command selector ahead of target lookup as a liveness/scheduling
//     probe; the original reads commandFlag before the target dispatch setup.
// 15: retained the command selector after target validation but before distance
//     computation, isolating its scheduling point from the object lookup.
// 16: restored late command evaluation and moved the command local ahead of the
//     object locals to test declaration-order register coloring.
// 17: retained the binary-proven unitAI result as a typed local instead of testing
//     the call result directly, mirroring the donor-era declaration surface.
// 18: reordered the top-level locals to the decompiler's attacker/unitAI/target/int
//     sequence before the final validation checkpoint.
// 19: reversed the target/no-target branch order as a natural typed call-order probe;
//     it moved the no-target calls ahead of target lookup and worsened structural parity,
//     so the clean canonical branch order is restored.
// 20: explicit late command if/else after priority restored the original EBP attacker,
//     EAX target-ID, 545-byte size, and all call/relocation sites; only the no-target
//     distance temporary home differs (original [esp+20], rebuilt [esp+28]), diff 2.
// Final bounded state: the canonical typed reconstruction is retained in scratch.
// The ten-probe run established exact call count/targets, vslot 0x10c weaponRange,
// the 12-argument player order ABI, exact size, and a localized two-byte mismatch.


int TribeTacticalAIModule::taskAttacker(int attackerID, float x, float y,
                                        int targetID, int arg5,
                                        Waypoint* waypoints, int waypointCount,
                                        int arg8, int commandFlag)
{
    RGE_Static_Object* attacker;
    float distance;
    int priority;

    if (attackerID == -1) {
        return 0;
    }
    attacker = (RGE_Static_Object*)this->md->player->world->object(attackerID);
    if (attacker == 0 || attacker->unitAI() == 0) {
        return 0;
    }

    if (waypoints != 0 && waypointCount > 0) {
        do {
            this->addWaypoint(attackerID, (int)waypoints->x,
                              (int)waypoints->y);
            ++waypoints;
            --waypointCount;
        } while (waypointCount != 0);
    }

    if (targetID != -1) {
        RGE_Static_Object* target;
        target = (RGE_Static_Object*)this->md->player->world->object(targetID);
        if (target == 0) {
            return 0;
        }

        distance = attacker->distance_to_object(target);
        priority = this->calculatePriority(distance);
        int command;
        if (commandFlag == 1)
            command = 0x2D9;
        else
            command = 0x2BC;

        this->md->player->sendUnitAIOrder(
            (int)this->md->player->id,
            attackerID,
            command,
            targetID,
            arg5,
            x,
            y,
            1.0f,
            attacker->weaponRange(),
            1,
            0,
            priority);
    } else {
        distance = attacker->distance_to_position(x, y, 1.0f);
        priority = this->calculatePriority(distance);
        this->moveUnit(attackerID, x, y, priority);
    }

    ManagedIntArray& arr = this->unitsTaskedThisUpdate;
    int i;
    for (i = 0; i < arr.numberValue; i++) {
        if (i >= arr.maximumSizeValue)
            break;
        if (arr.value[i] == attackerID)
            return 1;
    }

    if (arr.numberValue > arr.maximumSizeValue - 1) {
        int newSize = arr.numberValue + 1;
        int* newArray = new int[newSize];
        if (newArray != 0) {
            int j;
            for (j = 0; j < arr.maximumSizeValue && j < newSize; j++) {
                newArray[j] = arr.value[j];
            }
            delete[] arr.value;
            arr.value = newArray;
            arr.maximumSizeValue = newSize;
        }
    }

    arr.value[arr.numberValue] = attackerID;
    arr.numberValue++;
    return 1;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004FB500_taskDefender.cpp
// ---------------------------------------------------------------------------
int TribeTacticalAIModule::taskDefender(int groupId, int defenderId) {
    this->logCommonHistory((char*)"ERROR: Unused taskDefender call 1: defender ID=%d group=%d\n",
                           defenderId, groupId);
    return 0;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004FB520_taskDefender.cpp
// ---------------------------------------------------------------------------
int TribeTacticalAIModule::taskDefender(int groupId, float x, float y) {
    this->logCommonHistory((char*)"ERROR: Unused taskDefender call 2: defender ID=%d to (%f, %f)\n",
                           groupId, (double)x, (double)y);
    return 0;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004FB550_taskTrain.cpp
// ---------------------------------------------------------------------------
// VA: 004FB550 TribeTacticalAIModule::taskTrain (448 B)
// PDB source: taitacmd.cpp:9185-9217
// __thiscall, returns 0/1
//
// Attempt log:
// - Fresh typed reconstruction from the taskTrain packet and same-TU task
//   donors. The source models BuildItem, MainDecisionAIModule::object,
//   RGE_Static_Object::unitAI, TRIBE_Player::trainUnit, and the proven
//   this->unitsTaskedThisUpdate ManagedArray layout.
// - Baseline reached 448/448 bytes, 17/17 ordered calls, and 4 differing
//   bytes. The remaining bytes are four swapped local-home displacements:
//   VC5 stores the found object in the incoming parameter home and the
//   object ID in the compiler local home.
// - Tried early object-ID/object declarations, pointer initialization,
//   assignment-in-condition, long ID types, and parameter reuse. The
//   parameter-reuse form moved two swaps but added prologue drift. The
//   natural baseline remained best. No ABI, call-set, or layout blocker.
// - Mirrored the adjacent taskResearch source order: declare objectID at
//   entry, assign it before the ManagedIntArray alias. This restored all four
//   local-home bytes and produced MATCH (448/448). Default flags; no asm.

int TribeTacticalAIModule::taskTrain(BuildItem* item)
{
    int objectID;

    if (item == 0) {
        this->logCommonHistory("Invalid taskTrain item, returning FALSE.");
        return 0;
    }

    RGE_Static_Object* object =
        this->md->object(-1, item->buildFrom(), -1, 0x26B, 0x26C, 2);
    if (object == 0 || object->unitAI() == 0) {
        this->logCommonHistory("Could not find a building to train type %d (UniqueID=%d) at, returning FALSE.",
                               item->typeID(), item->uniqueID());
        return 0;
    }

    this->logCommonHistory("Training ID #%d (UniqueID=%d) from building with gameID=%d.",
                           item->typeID(), item->uniqueID(), object->id);
    item->setInProgress(1);
    item->setBuilt(0);

    objectID = object->id;
    ManagedIntArray& arr = this->unitsTaskedThisUpdate;
    int i;
    for (i = 0; i < arr.numberValue; i++) {
        if (i >= arr.maximumSizeValue)
            break;
        if (arr.value[i] == objectID)
            goto dispatch;
    }

    if (arr.numberValue > arr.maximumSizeValue - 1) {
        int newSize = arr.numberValue + 1;
        int* newArray = new int[newSize];
        if (newArray != 0) {
            for (i = 0; i < arr.maximumSizeValue && i < newSize; i++)
                newArray[i] = arr.value[i];
            delete[] arr.value;
            arr.value = newArray;
            arr.maximumSizeValue = newSize;
        }
    }

    arr.value[arr.numberValue] = objectID;
    arr.numberValue++;

dispatch:
    this->md->aiPlayer->trainUnit(item->typeID(), object->id,
                                  item->uniqueID());
    return 1;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004FB710_taskResearch.cpp
// ---------------------------------------------------------------------------
// VA: 004FB710 TribeTacticalAIModule::taskResearch (448 B)
// PDB source: taitacmd.cpp:9222-9253
// __thiscall, returns 0/1
//
// Fresh reconstruction from the exact taskTrain/taskWaterFisher donors.
// The target uses the same building lookup, BuildItem state changes, and
// ManagedIntArray growth. The final dispatch is TRIBE_Player::research.
//
// Attempt log:
// - Baseline: natural typed BuildItem/MainDecision/RGE object reconstruction;
//   448 bytes and 17 calls, but broad register and block drift.
// - Cached object-id probe improved the metric by 10 bytes, but changed the
//   source shape and introduced a wrong direct-call identity; rolled back.
// - Split lookup declaration and assignment restored the exact 448-byte
//   topology except for four stack-home displacement bytes.
// - Entry-local, assignment-in-condition, and object-alias variants emitted
//   duplicate code. The remaining gap is the object spill slot at 004FB75E
//   and 004FB843: target [esp+18], rebuilt [esp+10].
// - Reused the scan index for the array-copy loop, matching the original EAX
//   loop topology; emitted code was unchanged, so the spill-home gap remains.
// - Declared objectID at its first natural use after the item state updates to
//   test whether its shorter lifetime restored the original object spill home;
//   emitted code was unchanged, so the probe was rolled back.
// - Initializing the entry objectID local to zero selected the original VC5
//   local-home assignment. The initializer is optimized away; output is exact.
//   Best source keeps named ownership and natural bounded array growth.

int TribeTacticalAIModule::taskResearch(BuildItem* item)
{
    int objectID = 0;

    if (item == 0) {
        this->logCommonHistory("Invalid taskResearch item, returning FALSE.");
        return 0;
    }

    RGE_Static_Object* object;
    object = this->md->object(-1, item->buildFrom(), -1, 0x26B, 0x26C, 2);
    if (object == 0 || object->unitAI() == 0) {
        this->logCommonHistory(
            "Could not find a building to research type %d with unique ID %d.",
            item->typeID(), item->uniqueID());
        return 0;
    }

    this->logCommonHistory(
        "Researching ID #%d (UniqueID=%d) from building #%d.",
        item->typeID(), item->uniqueID(), object->id);
    item->setInProgress(1);
    item->setBuilt(0);

    objectID = object->id;

    ManagedIntArray& arr = this->unitsTaskedThisUpdate;
    int i;
    for (i = 0; i < arr.numberValue; i++) {
        if (i >= arr.maximumSizeValue)
            break;
        if (arr.value[i] == objectID)
            goto dispatch;
    }

    if (arr.numberValue > arr.maximumSizeValue - 1) {
        int newSize = arr.numberValue + 1;
        int* newArray = new int[newSize];
        if (newArray != 0) {
            for (i = 0; i < arr.maximumSizeValue && i < newSize; i++) {
                newArray[i] = arr.value[i];
            }
            delete[] arr.value;
            arr.value = newArray;
            arr.maximumSizeValue = newSize;
        }
    }

    arr.value[arr.numberValue] = objectID;
    arr.numberValue++;

dispatch:
    this->md->aiPlayer->research(item->typeID(), object->id, item->uniqueID());
    return 1;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004FB8D0_taskToEnter.cpp
// ---------------------------------------------------------------------------
// 004FB8D0 TribeTacticalAIModule::taskToEnter
// taitacmd.cpp:9258-9281, 268 bytes
//
// Attempt log:
// - Baseline retained the canonical array/mission ownership but hand-shaped the
//   search and used explicit allocation helpers; it was 275 bytes and diverged
//   at the first post-guard array scan.
// - Probe 1: mirror the exact same-TU taskDefender/taskFollower
//   ManagedArray reference, indexed bounded for-loop, natural new[]/delete[],
//   and typed mission virtual surface.  Pending checker result.

int TribeTacticalAIModule::taskToEnter(int param_1, int param_2)
{
    ManagedIntArray& arr = this->unitsTaskedThisUpdate;
    int i;

    if (param_1 == -1)
        return 0;

    for (i = 0; i < arr.numberValue; i++) {
        if (i >= arr.maximumSizeValue)
            break;
        if (arr.value[i] == param_1)
            goto dispatch;
    }

    if (arr.numberValue > arr.maximumSizeValue - 1) {
        int newSize = arr.numberValue + 1;
        int* newArray = new int[newSize];
        if (newArray != 0) {
            int j;
            for (j = 0; j < arr.maximumSizeValue && j < newSize; j++) {
                newArray[j] = arr.value[j];
            }
            delete[] arr.value;
            arr.value = newArray;
            arr.maximumSizeValue = newSize;
        }
    }

    arr.value[arr.numberValue] = param_1;
    arr.numberValue++;

dispatch:
    {
        RGE_Player* player = md->player;
        player->sendUnitAIOrder(
            (int)player->id,
            param_1,
            0x2CD,
            param_2,
            (int)player->id,
            -1.0f,
            -1.0f,
            -1.0f,
            1.0f,
            1,
            0,
            100
        );
    }

    return 1;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004FB9E0_taskTransporter.cpp
// ---------------------------------------------------------------------------
// VA: 004FB9E0 TribeTacticalAIModule::taskTransporter (336 bytes)
// PDB: taitacmd.cpp:9286-9313
// __thiscall, int, ret 0Ch
//
// Attempt log:
// - Replaced the raw-offset/free-function scaffold with the binary-backed
//   MainDecision object lookup, distance/priority calls, this->unitsTaskedThisUpdate
//   ManagedArray growth, and typed player slot-0x30 dispatch.
// - Exact baseline: the same natural bounded scan/growth idiom as the
//   taskFollower/taskDefender donors, with sendUnitAIOrder's high-confidence
//   RGE_Player slot-0x30 signature; generic proxy naming was removed.

int TribeTacticalAIModule::taskTransporter(int playerID, float x, float y)
{
    RGE_Static_Object* object = this->md->object(playerID);
    if (playerID == -1 || object == 0) {
        return 0;
    }

    float distance = object->distance_to_position(x, y, 1.0f);
    int priority = this->calculatePriority(distance);

    ManagedIntArray& arr = this->unitsTaskedThisUpdate;
    int i;
    for (i = 0; i < arr.numberValue; i++) {
        if (i >= arr.maximumSizeValue)
            break;
        if (arr.value[i] == playerID)
            goto dispatch;
    }

    if (arr.numberValue > arr.maximumSizeValue - 1) {
        int newSize = arr.numberValue + 1;
        int* newArray = new int[newSize];
        if (newArray != 0) {
            int j;
            for (j = 0; j < arr.maximumSizeValue && j < newSize; j++) {
                newArray[j] = arr.value[j];
            }
            delete[] arr.value;
            arr.value = newArray;
            arr.maximumSizeValue = newSize;
        }
    }

    arr.value[arr.numberValue] = playerID;
    arr.numberValue++;

dispatch:
    RGE_Player* player = this->md->player;
    player->sendUnitAIOrder((int)player->id, playerID, 0x2CA, -1,
                            (int)player->id, x, y, 1.0f, 1.0f,
                            1, 0, priority);
    return 1;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004FBB30_removeFromTaskLists.cpp
// ---------------------------------------------------------------------------
// 004FBB30 TribeTacticalAIModule::removeFromTaskLists
// PDB: taitacmd.cpp:9318-9332, 215 bytes
// __thiscall, void, ret 4
// FLAGS: default
//
// Attempt log:
// inherited attempts: decompiler-shaped pointer scans produced a redundant
//   bottom cmp/jne; several do/while, goto, and local-load variants stalled.
// probe 1 baseline: retained the best inherited natural candidate for fresh
//   validation; 175 positional diff bytes, exact calls/size/frame.
// probe 2: replaced the pointer do/while with a bounded indexed for scan,
//   following the exact ManagedArray<int>::remove donor; diff fell to 22 bytes.
// probe 3: modeled actualGathererDistribution[4] at +0xD68; emitted code
//   unchanged (negative layout evidence).
// probe 4: stored `value - 1` from an explicit load; emitted code unchanged.
// probe 5: named the proven distribution-element pointer and used explicit
//   load/store; restored the original mov/load, lea, dec, store tail: MATCH.
// probe 6: normalized civilianExplorers as ManagedArray<int> and UnitData as
//   named fields (including data1); emitted code remained exact.
// Exact source is a natural bounded ManagedArray scan/compact operation,
// typed helper calls, and an explicit element pointer for the observed
// load/lea/decrement/store sequence.


void TribeTacticalAIModule::removeFromTaskLists(int key) {
    int i = 0;
    int count = this->civilianExplorers.maximumSizeValue;

    for (; i < count; ++i) {
        if (this->civilianExplorers.value[i] == key) break;
    }

    if (i < count) {
        count--;
        if (i < count) {
            do {
                int* values = this->civilianExplorers.value;
                i++;
                values[i - 1] = values[i];
            } while (i < this->civilianExplorers.maximumSizeValue - 1);
        }

        this->civilianExplorers.numberValue--;
        if (this->civilianExplorers.numberValue < 0) {
            this->civilianExplorers.numberValue = 0;
        }
    }

    this->removeGatherer(key);

    RGE_Static_Object* obj = this->md->object(key);
    if (obj != NULL) {
        if (obj->unitAI() != NULL) {
            if (obj->unitAI()->currentAction() == 0x261) goto check;
            if (obj->unitAI()->currentAction() != 0x265) goto end;
check:
            UnitData* g = this->gatherer(key);
            if (g != NULL) {
                int index = g->data1;
                int* p = &this->actualGathererDistribution[index];
                int value = *p;
                *p = value - 1;
            }
        }
    }

end:
    return;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004FBC10_calculatePriority.cpp
// ---------------------------------------------------------------------------
int TribeTacticalAIModule::calculatePriority(float value) {
    int priority;

    priority = (int)((float)*(int*)((char*)this + 0x21C) / value);
    if (priority > 99) {
        priority = 99;
    }
    return priority;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004FBC30_setupSoldierGroups.cpp
// ---------------------------------------------------------------------------
// 004FBC30 TribeTacticalAIModule::setupSoldierGroups
// Source: taitacmd.cpp lines 9347-9674
//
// Baseline: period-plausible typed reconstruction.  ManagedArray growth/removal
// uses the established inline operator[]/remove surfaces; the local list uses
// the out-of-line resize member, as shown by the original call at 004147A0.
// FLAGS: config/flags/004FBC30_setupSoldierGroups.rsp (/GX for the observed EH frame).
//
// Attempt log:
// - default flags, no ManagedArray destructor: 2156 bytes, no EH frame; rolled
//   back after confirming the target's FS registration requires a nontrivial
//   local lifetime.
// - /GX alone was codegen-identical; adding the natural ManagedArray destructor
//   produced the target EH family and a 2200-byte reconstruction.
// - complete destructor field clearing was codegen-identical to the delete-only
//   body after dead-store elimination.
// - function-scope numPotentialAGroups models the FPU remainder home; the
//   constructor form preserves the original zero-store scheduling and is kept.
// - worker astra (2026-08): structural audit found the original does NOT reset
//   numAGroups/i before the workingArea loop; the leftover numAGroups is used as
//   the workingArea index (general operator[] growth, no const-fold to element 0).
//   Removed the pre-loop reset; moved `i = 0; numAGroups = 0;` to after the loop.
// - time-check: original computes BOTH /1000 divisions into named locals before
//   the test (rebalance statement first, attack second; test attack-first).
//   The inline && short-circuits in VC5; named locals reproduce the dual mul/shr.
// - compare operand orders per original asm: while(numDGroups>newArtifact),
//   while(numEGroups>i), while(local_24>numAGroups), else-arm
//   numPotentialAGroups >= sn[0x24] with a named maxArtifact temp (original loads
//   sn[0x24] on its own source line 9494 first).
// - else-arm i as min(...) (ternary/if-else) stores i after the subtraction;
//   this flipped the frame to 0x2C and the balance register basin (zero=ebp,
//   newArtifact=ebx, product=edi CSE across the ceil call via the artifactUnits
//   local).  Current best: 2245/2241 bytes (+4), frame 0x2C/0x2C, 69/69 calls,
//   exact CFG, 760 positional diff bytes (was 1998), edit diff 230.
// BINARY NOTE: the original balance block keeps numAGroups at [esp+18h],
// newArtifact at [esp+10h], and the zero value in EBP across all three ceil
// paths.  The clean source below reaches the same frame and call surface, but
// VC5 selects the opposite two homes and rematerializes zero after __ftol.
// BINARY NOTE: the original carries numAGroups into the workingArea index;
// there is no reset before that loop.  Keep this shipped behavior.
// LIKELY INTENT: the balance block is a direct group-count calculation with
// short-lived remainder values.  Named product and max-bound locals preserve
// the closest clean VC5 basin, even though direct expressions are simpler.
// Probe summary: 20 evidence-led local, predicate, loop, declaration, and
// expression variants were equal or worse.  The home swap remains unresolved.
// - Worker pass (2026-08-22): declaration order, a reference alias for the
//   zero compare, a for-loop removal form, CRT headers, and a register hint
//   were codegen duplicates.  A 512-sample ambient declaration sweep also
//   kept one 2245-byte /GX group.  The target home swap remains unresolved.
// Remaining leads (allocator coloring, not structure):
// 1. numAGroups/newArtifact stack-home swap: rebuilt homes numAGroups at
//    [esp+10h] and newArtifact at [esp+18h]; original has them swapped.
//    Declaration order (tried 5 orders) does not affect it.  It is tied to the
//    zero-register liveness below; the first strict mismatch is this slot in the
//    removeGroup loop (+0184).
// 2. zero-register liveness: original keeps the balance-entry zero in ebp live
//    across the ceil calls (`cmp eax,ebp` at the <=0 remainder checks); rebuilt
//    rematerializes `test eax,eax`, which frees ebp for i (mov ebp,eax after
//    __ftol) instead of ecx, and flips the product imuls to loaded-first forms
//    (+4 bytes total).  The imul folding (`imul edi,[esi+1D4h]` vs
//    `mov edi,[esi+1D4h]; imul edi,ebx`) is a scheduling symptom of the same.
// 3. first-path i clamp stores early (default-then-override) in BOTH versions;
//    else path stores i after the sub (min form) - already matched.
// No fake volatility, manual vtables, opaque scaffolding or inline asm retained.
// ManagedArray recovery pass, 2026-08-19:
// - Replacing the complete local surface with include/utmarray.h made resize
//   inline twice. It added two allocator pairs and 214 bytes. The original
//   calls resize at both add sites, so the shared-header form is not valid in
//   this isolated translation unit.
// - The exact add body with declaration-only resize emits the same 2245-byte
//   frontier as the former manual scans. It matches the PDB line ownership and
//   removes unsupported caller-side field access. Keep this source model.

void* operator_new(unsigned int size);
void __cdecl operator_delete(void* ptr);

extern int __cdecl debug_rand(char* file, int line);
extern "C" double __cdecl ceil(double value);

void TribeTacticalAIModule::setupSoldierGroups()
{
    ManagedArray_int groupsToRemove;
    int newArtifact;
    int i;
    int numAGroups;
    int numDGroups;
    int numEGroups;
    int local_24;
    int numPotentialAGroups;
    TacticalAIGroup* sentinel;
    TacticalAIGroup* group;

    group = this->groups.next;
    sentinel = &this->groups;
    while (group != sentinel && group != 0) {
        if (group->numberUnits() == 0) {
            groupsToRemove.add(group->id());
        }
        group = group->next;
    }

    unsigned long timeSinceRebalance =
        (this->md->player->world->world_time - this->lastGroupRebalanceTime) / 1000;
    unsigned long timeSinceAttack =
        (this->md->player->world->world_time - this->lastGroupAttackTime) / 1000;
    if (timeSinceAttack > 600 && timeSinceRebalance > 600) {
        this->lastGroupRebalanceTime = this->md->player->world->world_time;
        group = this->groups.next;
        while (group != sentinel && group != 0) {
            if (group->type() == 100) {
                groupsToRemove.add(group->id());
            }
            group = group->next;
        }
    }

    numAGroups = 0;
    while (numAGroups < groupsToRemove.numberValue) {
        this->removeGroup(groupsToRemove[numAGroups]);
        ++numAGroups;
    }

    if (this->md->informationAI.fullyExploredZone(this->soldiers[0]) == 0) {
        this->removeAllGroups(0x66);
        this->setStrategicNumber(0x2A, 0);
    }

    numDGroups = this->numberGroups(100, -1);
    numEGroups = this->numberGroups(101, -1);
    local_24 = this->numberGroups(102, -1);
    this->numberGroups(109, -1);
    this->numberUngroupedArtifacts();

    while (this->workingArea.numberValue > 0) {
        int object_id = this->workingArea[numAGroups];
        RGE_Static_Object* object = this->md->object(object_id);
        if (object == 0) {
            this->workingArea.remove(object_id);
        }
        else {
            RGE_Static_Object* retreat = this->md->object(
                -1, -1, 0x6D, -1, -1, -1, -1, -1, -1, -1);
            if (retreat == 0) {
                this->workingArea.remove(object_id);
            }
            else {
                TacticalAIGroup* new_group = this->createGroup(1);
                if (new_group == 0) {
                    break;
                }
                new_group->setType(0x6D);
                new_group->setDesiredNumberUnits(1);
                new_group->addUnit(object_id, this->md);
                new_group->setSpecificCommander(object_id, this->md);
                new_group->setLocation(object->world_x, object->world_y, object->world_z);
                new_group->setGatherLocation(object->world_x, object->world_y, object->world_z);
                new_group->setRetreatLocation(retreat->world_x, retreat->world_y, retreat->world_z);
                this->workingArea.remove(object_id);
            }
        }
    }

    i = 0;
    numAGroups = 0;
    if (this->sn[0x28] == 0) {
        newArtifact = (int)ceil((double)this->soldiers.numberValue /
                                (double)this->sn[0x10]);
        if (newArtifact > this->sn[0x24]) {
            newArtifact = this->sn[0x24];
        }
        int artifactUnits = newArtifact * this->sn[0x10];
        numPotentialAGroups = this->soldiers.numberValue - artifactUnits;
        if (numPotentialAGroups <= 0) {
            goto balance_groups;
        }
        i = (int)ceil((double)numPotentialAGroups / (double)this->sn[0x19]);
        if (i > this->sn[0x26]) {
            i = this->sn[0x26];
        }
        numPotentialAGroups = this->soldiers.numberValue - i * this->sn[0x19] -
                              artifactUnits;
        if (numPotentialAGroups <= 0) {
            goto balance_groups;
        }
        numAGroups = (int)ceil((double)numPotentialAGroups / (double)this->sn[0x2B]);
        if (numAGroups <= this->sn[0x2A]) {
            goto balance_groups;
        }
    }
    else {
        int maxArtifact = this->sn[0x24];
        numPotentialAGroups = this->soldiers.numberValue;
        newArtifact = numPotentialAGroups;
        if (numPotentialAGroups >= maxArtifact) {
            newArtifact = maxArtifact;
        }
        numPotentialAGroups -= newArtifact;
        if (numPotentialAGroups <= 0) {
            goto balance_groups;
        }
        if (numPotentialAGroups < this->sn[0x26]) {
            i = numPotentialAGroups;
        }
        else {
            i = this->sn[0x26];
        }
        numPotentialAGroups -= i;
        if (numPotentialAGroups <= 0 ||
            (numAGroups = numPotentialAGroups,
             numPotentialAGroups < this->sn[0x2A])) {
            goto balance_groups;
        }
    }
    numAGroups = this->sn[0x2A];

balance_groups:
    if (this->sn[0xA2] == 1) {
        newArtifact = 0;
    }

    for (; numDGroups < newArtifact; ++numDGroups) {
        TacticalAIGroup* new_group = 0;
        if (numEGroups > 0) {
            new_group = this->group(-1, 0x65, -1, -1);
            if (new_group != 0) {
                --numEGroups;
            }
            else {
                new_group = this->group(-1, 0x66, -1, -1);
                if (new_group != 0) {
                    --local_24;
                }
            }
        }
        if (new_group == 0) {
            new_group = this->createGroup(1);
            if (new_group == 0) {
                break;
            }
        }
        new_group->setType(100);
        new_group->setTarget(-1);
        new_group->setTargetType(-1);
        new_group->setAction(1);
        new_group->setInUse(0);
        int desired = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\taitacmd.cpp", 0x2560) %
                      (this->sn[0x62] + 1) + this->sn[0x10];
        if (desired > this->sn[0x1A]) {
            desired = this->sn[0x1A];
        }
        new_group->setDesiredNumberUnits(desired);
    }

    while (numDGroups > newArtifact) {
        TacticalAIGroup* old_group = this->group(-1, 100, 0, -1);
        if (old_group == 0) {
            old_group = this->group(-1, 100, 1, -1);
        }
        if (old_group == 0) {
            break;
        }
        this->removeGroup(old_group->id());
        --numDGroups;
    }

    for (; numEGroups < i; ++numEGroups) {
        TacticalAIGroup* new_group = 0;
        if (local_24 > 0) {
            new_group = this->group(-1, 0x66, -1, -1);
            if (new_group != 0) {
                --local_24;
            }
        }
        if (new_group == 0) {
            new_group = this->createGroup(1);
            if (new_group == 0) {
                break;
            }
        }
        new_group->setType(0x65);
        new_group->setTarget(-1);
        new_group->setTargetType(-1);
        new_group->setAction(1);
        new_group->setInUse(0);
        new_group->setDesiredNumberUnits(this->sn[0x19]);
    }

    while (numEGroups > i) {
        TacticalAIGroup* old_group = this->group(-1, 0x65, -1, -1);
        if (old_group == 0) {
            break;
        }
        this->removeGroup(old_group->id());
        --numEGroups;
    }

    for (; local_24 < numAGroups; ++local_24) {
        TacticalAIGroup* new_group = this->createGroup(1);
        if (new_group == 0) {
            break;
        }
        new_group->setType(0x66);
        new_group->setDesiredNumberUnits(this->sn[0x2B]);
    }

    while (local_24 > numAGroups) {
        TacticalAIGroup* old_group = this->group(-1, 0x66, -1, -1);
        if (old_group == 0) {
            break;
        }
        this->removeGroup(old_group->id());
        --local_24;
    }

}

// ---------------------------------------------------------------------------
// PDB source owner: 004FC500_fillSoldierGroups.cpp
// ---------------------------------------------------------------------------
// VA: 004FC500 TribeTacticalAIModule::fillSoldierGroups
// Baseline reconstruction: the embedded TacticalAIGroup at +0x9D4 owns the
// circular list sentinel; workingArea at +0xD48 is a ManagedArray<int> with
// value/numberValue/desiredNumberValue/maximumSizeValue at +0/+4/+8/+C.
// The function first repairs commander assignments, then fills type 100-102
// groups from ungrouped soldiers, redistributes excess soldiers, and finally
// assigns any remaining ungrouped soldiers to eligible groups.
//
// Attempt log:
// - baseline source is the period-plausible group-list/ManagedArray model; the
//   repeated growth and removal blocks are kept inline because the original
//   emits the canonical utmarray.h operator[]/remove shapes at each use site.
// - restored the commander-zone object/currentZone filter in both fill paths
//   and both excess-redistribution paths; the call set and frame then aligned.
// - added the binary-observed inUse gate before selecting a commander for an
//   underfilled group.
// - kept the initial sentinel walk scoped, and used guarded do/while list
//   traversal for the type loop and the final soldier redistribution scan.
// - matched desiredNumberUnits-before-numberUnits ordering in the final group
//   chooser and preserved its two-stage same-zone/capacity selection.
// - tested the packet-supported separate type-pass iterator; VC5 kept the same
//   bytes, but the named iterator remains the clearer source model.
// - made the final selected and fallback paths use branch-local ManagedArray
//   subscripts into one shared unit value. VC5 kept both growth/delete arms and
//   one shared addUnit tail, matching the original topology.
// - restored the first fill branch order from the binary: direct same-zone fill
//   when ungrouped <= missing, then nearest fill when the group remains short.
//   Reused the desired/number locals for the later missing calculation.
// - modeled the second type pass with explicit group/sentinel locals and the
//   observed store to bestGroup before its sentinel/null checks. The source
//   emits the same 122-call set and exact frame, but VC5 keeps group in EAX and
//   reloads it where the original keeps group in EBP.
// - tested 22 distinct hypotheses across control flow, liveness, layout,
//   class context, and compare spelling. The best clean result is 3523/3554
//   bytes, exact frame and 122/122 calls, 90.16% call alignment, 72.73% shape,
//   and 3056 positional-diff bytes. Remaining drift starts at +0xC2 in the
//   second group-loop register/CFG basin. Direct member spelling, base context,
//   register storage, and sentinel address variants were codegen duplicates.
// - follow-up probes 23-51 tested an early type-mismatch advance, shared and
//   natural sentinel loop forms, split final guards, final cursor ownership,
//   final-pass local scope, and a function-scope group cursor. The probes did
//   not improve the clean source. Several forms changed size or call order;
//   all were restored.
// - final clean validation remains 3523/3554 bytes, exact 0x20 frame,
//   122/122 calls, 90.16% call alignment, 72.73% shape, and 3056 positional
//   diff bytes. No accepted drift is supported by the measured residue.

extern void* operator new(unsigned int);
extern void operator delete(void*);

void TribeTacticalAIModule::fillSoldierGroups() {
    int bestUnit;
    TacticalAIGroup* bestGroup;

    this->numberUngroupedSoldiers();
    this->numberExtraGroupedSoldiers();

    {
        TacticalAIGroup* group = this->groups.next;
        while (group != &this->groups) {
            if (group == 0) {
                break;
            }
            if ((group->type() == 100 || group->type() == 101 || group->type() == 102) &&
                group->commander() == -1) {
                int ungrouped = this->numberUngroupedSoldiers();
                if (group->numberUnits() > 0) {
                    int commander = this->selectBestCommander(group);
                    group->setSpecificCommander(commander, this->md);
                    if (group->action() == 0 || group->action() == 1) {
                        this->setAllGroupLocations(group);
                    }
                }
                else {
                    if (ungrouped == 0) {
                        this->numberExtraGroupedSoldiers();
                    }
                    if (this->workingArea.numberValue == 0) {
                        return;
                    }
                    int commander = this->selectBestCommander(&this->workingArea);
                    group->addUnit(commander, this->md);
                    group->setSpecificCommander(commander, this->md);
                    if (group->action() == 0 || group->action() == 1) {
                        this->setAllGroupLocations(group);
                    }
                }
            }
            group = group->next;
        }
    }

    if (this->sn[0x28] == 0) {
        bestUnit = 100;
        TacticalAIGroup* group;
        TacticalAIGroup* sentinel;
        do {
            group = this->groups.next;
            sentinel = &this->groups;
            bestGroup = group;
            if (group != sentinel) {
            while (1) {
                if (group == 0) {
                    break;
                }
                if (group->type() == bestUnit) {
                    int desired = group->desiredNumberUnits();
                    int number = group->numberUnits();
                    if (number < desired) {
                        if (group->inUse() != 1) {
                            int groupZone = -1;
                            int groupCommander = group->commander();
                            RGE_Static_Object* groupObject = this->md->object(groupCommander);
                            if (groupObject != 0) {
                                groupZone = groupObject->currentZone();
                            }
                            int ungrouped = this->numberUngroupedSoldiers();
                            desired = group->desiredNumberUnits();
                            number = group->numberUnits();
                            int missing = desired - number;
                            if (ungrouped <= missing) {
                                int i = 0;
                                if (this->workingArea.numberValue > 0) {
                                    do {
                                        RGE_Static_Object* object =
                                            this->md->object(this->workingArea[i]);
                                        if (object != 0 &&
                                            object->currentZone() == groupZone) {
                                            group->addUnit(this->workingArea[i], this->md);
                                        }
                                        ++i;
                                    } while (i < this->workingArea.numberValue);
                                }
                            }

                            int desiredAgain = group->desiredNumberUnits();
                            int numberAgain = group->numberUnits();
                            if (numberAgain < desiredAgain) {
                                do {
                                    int i = 0;
                                    float bestDistance = -1.0f;
                                    int bestUnitID = -1;
                                    if (this->workingArea.numberValue > 0) {
                                        do {
                                            RGE_Static_Object* object =
                                                this->md->object(this->workingArea[i]);
                                            if (object != 0 &&
                                                object->currentZone() == groupZone) {
                                                float distance = object->distance_to_position(
                                                    group->gatherLocation().x,
                                                    group->gatherLocation().y,
                                                    group->gatherLocation().z);
                                                if (bestDistance == -1.0f || distance < bestDistance) {
                                                    bestUnitID = this->workingArea[i];
                                                    bestDistance = distance;
                                                }
                                            }
                                            ++i;
                                        } while (i < this->workingArea.numberValue);
                                    }
                                    if (bestUnitID == -1) {
                                        break;
                                    }
                                    group->addUnit(bestUnitID, this->md);

                                    int max = this->workingArea.maximumSizeValue;
                                    int removeIndex = 0;
                                    if (max > 0) {
                                        int* value = this->workingArea.value;
                                        do {
                                            if (*value == bestUnitID) {
                                                break;
                                            }
                                            ++removeIndex;
                                            ++value;
                                        } while (removeIndex < max);
                                    }
                                    if (removeIndex < max) {
                                        if (removeIndex < max - 1) {
                                            do {
                                                ++removeIndex;
                                                this->workingArea.value[removeIndex - 1] =
                                                    this->workingArea.value[removeIndex];
                                            } while (removeIndex < max - 1);
                                        }
                                        int count = this->workingArea.numberValue - 1;
                                        this->workingArea.numberValue = count;
                                        if (count < 0) {
                                            this->workingArea.numberValue = 0;
                                        }
                                    }

                                    desiredAgain = group->desiredNumberUnits();
                                    numberAgain = group->numberUnits();
                            } while (numberAgain < desiredAgain);
                            }

                            int desiredAfter = group->desiredNumberUnits();
                            int numberAfter = group->numberUnits();
                            if (numberAfter < desiredAfter) {
                                int extra = this->numberExtraGroupedSoldiers();
                                int desiredExtra = group->desiredNumberUnits();
                                int numberExtra = group->numberUnits();
                                int missingExtra = desiredExtra - numberExtra;
                                if (missingExtra < extra) {
                                    int desiredNearest = group->desiredNumberUnits();
                                    int numberNearest = group->numberUnits();
                                    if (numberNearest < desiredNearest) {
                                    do {
                                        int i = 0;
                                        float bestDistance = -1.0f;
                                        int bestUnitID = -1;
                                        if (this->workingArea.numberValue > 0) {
                                            do {
                                                RGE_Static_Object* object =
                                                    this->md->object(this->workingArea[i]);
                                                if (object != 0 &&
                                                    object->currentZone() == groupZone) {
                                                    float distance = object->distance_to_position(
                                                        group->gatherLocation().x,
                                                        group->gatherLocation().y,
                                                        group->gatherLocation().z);
                                                    if (bestDistance == -1.0f || distance < bestDistance) {
                                                        bestUnitID = this->workingArea[i];
                                                        bestDistance = distance;
                                                    }
                                                }
                                                ++i;
                                            } while (i < this->workingArea.numberValue);
                                        }
                                        if (bestUnitID == -1) {
                                            break;
                                        }
                                        this->removeFromGroup(bestUnitID);
                                        group->addUnit(bestUnitID, this->md);

                                        int max = this->workingArea.maximumSizeValue;
                                        int removeIndex = 0;
                                        if (max > 0) {
                                            int* value = this->workingArea.value;
                                            do {
                                                if (*value == bestUnitID) {
                                                    break;
                                                }
                                                ++removeIndex;
                                                ++value;
                                            } while (removeIndex < max);
                                        }
                                        if (removeIndex < max) {
                                            if (removeIndex < max - 1) {
                                                do {
                                                    ++removeIndex;
                                                    this->workingArea.value[removeIndex - 1] =
                                                        this->workingArea.value[removeIndex];
                                                } while (removeIndex < max - 1);
                                            }
                                            int count = this->workingArea.numberValue - 1;
                                            this->workingArea.numberValue = count;
                                            if (count < 0) {
                                                this->workingArea.numberValue = 0;
                                            }
                                        }
                                    } while (group->numberUnits() < group->desiredNumberUnits());
                                    }
                                }
                                else {
                                    int i = 0;
                                    if (this->workingArea.numberValue > 0) {
                                        do {
                                            RGE_Static_Object* object =
                                                this->md->object(this->workingArea[i]);
                                            if (object != 0 &&
                                                object->currentZone() == groupZone) {
                                                this->removeFromGroup(this->workingArea[i]);
                                                group->addUnit(this->workingArea[i], this->md);
                                            }
                                            ++i;
                                        } while (i < this->workingArea.numberValue);
                                    }
                                }
                            }
                        }
                    }
                }
                group = group->next;
                if (group == sentinel) {
                    break;
                }
            }
            }
            ++bestUnit;
        } while (bestUnit <= 0x66);
    }

    if (this->numberUngroupedSoldiers() != 0 && this->workingArea.numberValue > 0) {
        TacticalAIGroup* group;
        int i = 0;
        do {
            RGE_Static_Object* object = this->md->object(this->workingArea[i]);
            if (object != 0) {
                unsigned char unitZone = object->currentZone();
                int unit;
                bestGroup = 0;
                int bestDifference = 0;
                group = this->groups.next;
                while (group != &this->groups) {
                    if (group == 0) {
                        break;
                    }
                    if ((group->type() == 100 || group->type() == 101 ||
                         group->type() == 102) &&
                        group->inUse() != 1) {
                        int commander = group->commander();
                        RGE_Static_Object* commanderObject = this->md->object(commander);
                        if (commanderObject != 0 &&
                            commanderObject->currentZone() == unitZone) {
                            int desired = group->desiredNumberUnits();
                            int number = group->numberUnits();
                            if (number < desired &&
                                (group->action() == 1 || group->action() == 0)) {
                                int desiredAgain = group->desiredNumberUnits();
                                int numberAgain = group->numberUnits();
                                int difference = numberAgain - desiredAgain;
                                if (bestGroup == 0 || difference < bestDifference) {
                                    bestGroup = group;
                                    bestDifference = difference;
                                }
                            }
                        }
                    }
                    group = group->next;
                }

                if (bestGroup == 0) {
                    TacticalAIGroup* candidate = this->groups.next;
                    bestGroup = 0;
                    bestDifference = 0;
                    while (candidate != &this->groups) {
                        if (candidate == 0) {
                            break;
                        }
                        if ((candidate->type() == 100 || candidate->type() == 101 ||
                             candidate->type() == 102) &&
                            candidate->inUse() != 1 &&
                            (candidate->action() == 1 || candidate->action() == 0)) {
                            int type = candidate->type();
                            if (type == 100 &&
                                candidate->numberUnits() >= this->sn[0x1A]) {
                                candidate = candidate->next;
                                continue;
                            }
                            type = candidate->type();
                            if (type == 101 &&
                                candidate->numberUnits() >= this->sn[0x1C]) {
                                candidate = candidate->next;
                                continue;
                            }
                            type = candidate->type();
                            if (type == 102 &&
                                candidate->numberUnits() >= this->sn[0x2C]) {
                                candidate = candidate->next;
                                continue;
                            }
                            int commander = candidate->commander();
                            RGE_Static_Object* commanderObject = this->md->object(commander);
                            if (commanderObject != 0 &&
                                commanderObject->currentZone() == unitZone) {
                                int desired = candidate->desiredNumberUnits();
                                int number = candidate->numberUnits();
                                int difference = number - desired;
                                if (bestGroup == 0 || difference < bestDifference) {
                                    bestGroup = candidate;
                                    bestDifference = difference;
                                }
                            }
                        }
                        candidate = candidate->next;
                    }
                    if (bestGroup == 0) {
                        return;
                    }
                    unit = this->workingArea[i];
                }
                else {
                    unit = this->workingArea[i];
                }
                bestGroup->addUnit(unit, this->md);
            }
            ++i;
        } while (i < this->workingArea.numberValue);
    }
}

// ---------------------------------------------------------------------------
// PDB source owner: 004FD2F0_numberUngroupedSoldiers.cpp
// ---------------------------------------------------------------------------
// VA: 004FD2F0 TribeTacticalAIModule::numberUngroupedSoldiers
// Attempt log:
// try 1: factored ensure helpers compiled out-of-line, text too small.
// try 2: inlined repeated growth logic but compiler chose ebp for newMax and very different loop topology.
// try 3: closer decompiler-style locals/local_4/i/rNum and direct indexed access.
// try 4: volatile i forced 0x0c stack frame but shifted rNum/local_4 slots to +0x10/+0x0c instead of original +0x08/+0x10.
// try 5: reordered locals; no stack-slot improvement.
// try 6: compare spelling local_4 > max-1 restored first jle polarity but loop copy body still uses ecx index/shift instead of original eax increment + [base+eax*4-4].
// try 7: first natural inline version had correct function size but no EBP loop index and broad register/topology drift.
// probe 8: restored the period utmarray.h operator[] and add inline method surfaces;
// the source now models two ManagedArray<int> members and lets VC5 lower each
// repeated soldiers[i] access and workingArea.add() naturally.
// probe 9: cached soldier count after the working-number reset; VC5 introduced
// a 0x10 frame and broad drift, so it was rolled back.
// probe 10: pointer-plus-index return spelling in operator[] was a codegen duplicate.
// probe 11: naming the repeated soldier value before add() was also a duplicate.
// probe 12: a natural workingArea reference alias restored the oracle's
// reset-before-soldier-count load order, leaving one SIB base/index byte.
// probe 13: a natural soldiers reference alias selected the oracle's final SIB
// encoding and produced an exact 510-byte match.
// exact: both aliases are ordinary member references; no compiler-steering or
// raw-offset source remains beyond the proven class gaps and array layout.

extern "C" {
    void* operator_new(unsigned int size);
    void operator_delete(void* ptr);
}

int TribeTacticalAIModule::numberUngroupedSoldiers()
{
    int rNum = 0;
    int i = 0;
    ManagedArray<int>& workingArea = this->workingArea;
    ManagedArray<int>& soldiers = this->soldiers;

    workingArea.numberValue = 0;
    if (soldiers.numberValue > 0) {
        do {
            if (this->groupUnitIsIn(soldiers[i]) == 0) {
                workingArea.add(soldiers[i]);
                rNum++;
            }
            i++;
        } while (i < soldiers.numberValue);
    }
    return rNum;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004FD4F0_numberExtraGroupedSoldiers.cpp
// ---------------------------------------------------------------------------
// VA: 004FD4F0, TribeTacticalAIModule::numberExtraGroupedSoldiers, 473 bytes
// Source: taitacmd.cpp lines 10154-10201
// Attempt log:
// - v1-v9: raw sentinel/group and hand-inlined array reconstruction. The
//   output reached 473 bytes but used a different register and stack basin.
// - clean reconstruction: groups is the embedded 0x330-byte TacticalAIGroup
//   list sentinel, and workingArea is a ManagedArray<int> at +0xd48.
//   This removes decompiler cursor scaffolding from the compiler-facing source.
// - probe 1 baseline: typed reconstruction reached 483 bytes with group in
//   EBX and all 16 calls present, but the outer count calls were reversed.
// - probe 2: reversed the outer count predicate; call order did not change.
// - probe 3: named desiredUnits before the comparison; all 16 call sites then
//   aligned and the diff fell to 65 bytes.
// - probe 4: reordered result/rNum/tempCount declarations; code was unchanged.
// - probe 5: split result and workingArea reset statements; code was unchanged.
// - probe 6: added the ordinary workingArea reference used by exact array
//   donors; the best diff fell to 62 bytes.
// - probe 7: early sentinel return changed CFG and widened the diff; rolled back.
// - probe 8: used a literal zero for the workingArea reset; code was unchanged.
// - probe 9: forced a result stack-home store through a pointer; code was
//   unchanged and the diagnostic form was removed.
// - probe 11: changed the outer list walk to a natural while loop and scoped
//   rNum/tempCount inside the counted-group block; output reached 473 bytes
//   with a 16-byte diff and exact outer CFG, leaving only the result home.
// - probe 12: named numberUnits after desiredUnits and used the original
//   comparison operand order; this reduced the positional diff to 10 bytes.
// - probes 13-16: local scope, declaration order, initialization, and stdlib
//   context changes were codegen duplicates or worse; they were removed.
// - revisit probe 20: replaced the manual vptr field with a natural virtual
//   destructor surface. The emitted code was unchanged, so this typed layout
//   is retained as the cleaner ownership model.
// Prior blocker: current typed source has 473 bytes, all 16 direct calls aligned,
// and a 10-byte positional diff. The remaining drift is three local homes and
// their transient uses: original result/rNum/tempCount use
// [esp+18]/[esp+14]/[esp+10], while current uses [esp+10]/[esp+18]/[esp+14].
// The source keeps canonical ownership.
// ACCEPTED DRIFT: The ten differing bytes consistently permute those three
// nonescaping dword homes. Every read follows its matching write, including
// the push-adjusted rNum update. Register use, calls, values, writes,
// predicates, cleanup, and faults match the reviewed war-boat twin.

extern "C" {
    void* operator_new(unsigned int size);
    void operator_delete(void* ptr);
}

int TribeTacticalAIModule::numberExtraGroupedSoldiers()
{
    int result = 0;
    ManagedArray<int>& workingArea = this->workingArea;
    TacticalAIGroup* group;

    workingArea.numberValue = 0;
    group = this->groups.next;
    while (group != &this->groups) {
        if (group == 0)
            return result;

        if ((group->type() == 100 || group->type() == 101 ||
             group->type() == 102) &&
            (group->action() == 1 || group->action() == 0)) {
            int desiredUnits = group->desiredNumberUnits();
            int numberUnits = group->numberUnits();
            if (numberUnits > desiredUnits) {
                int rNum = group->numberUnits();
                int tempCount = 0;
                if (rNum > group->desiredNumberUnits()) {
                    while (1) {
                        if (tempCount >= group->numberUnits())
                            break;
                        if (group->unit(tempCount) != group->commander()) {
                            rNum--;
                            workingArea.add(group->unit(tempCount));
                            result++;
                        }
                        tempCount++;
                        if (rNum <= group->desiredNumberUnits())
                            break;
                    }
                }
            }
        }
        group = group->next;
    }
    return result;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004FD6D0_numberUngroupedArtifacts.cpp
// ---------------------------------------------------------------------------
// VA: 004FD6D0 TribeTacticalAIModule::numberUngroupedArtifacts
// Source: taitacmd.cpp lines 10206-10220
// Attempt log:
// 1: natural reconstruction from packet/decompiler, preserving explicit array growth loops: broad mismatch, compiler used EAX/EBP differently and omitted early push ebp.
// 2: closer decompiler-shaped source with local_c/local_4 names and direct indexed array accesses: much closer prologue but only 8-byte frame.
// 3: make i volatile to force the third stack local slot seen in original; got 0x0c frame but stack slots are permuted.
// 4: reorder local declarations to try local_c at +8, i at +0c, local_4 at +10; no stack-slot improvement.
// 5: invert first capacity condition source to try cmp ebp,eax / jle skip shape; fixed first branch polarity but copy loops still wrong.
// 6: tried separate volatile frame_pad with nonvolatile i; frame collapsed back to 8 bytes and worsened, rolled back.
// 7: keep volatile i as best frame/prologue family; remaining drift is stack-slot permutation and copy-loop register topology.
// 8: swap initial local assignment order to probe stack slot store order; swapped first two stores but still no +8 rNum slot and broad loop drift.
// 9: tried narrow /O1 flag as code-size/control-flow probe; produced EBP frame and worse, flag removed.
// 10: left in scratch: behavior/call surface understood, but remaining mismatch is broad VC5 stack-slot allocation and dynamic-array copy-loop register topology. Best /O2 family has correct 0x0c frame, push ebp/esi, branch polarity for first grow check, but rNum/local_4/i stack slots are permuted and copy loops use ECX/shl instead of original EAX inc/index form; not accepted-drift-safe.
// Probe 1 (current claim): restored the period ManagedArray<int>::operator[] surface and
// natural indexed source for both artifact accesses and the working-area append. This
// is the canonical ownership hypothesis; the next check distinguishes source topology
// from the prior hand-expanded/volatile experiment.
// Probe 2: moved the artifact value to a function-scope ordinary local so it can
// remain live across the working-area growth call, matching the oracle's callee-saved
// artifact register and spilled outer-index topology.
// Probe 3: reversed the duplicate-scan boundary spelling to the binary's
// `j >= maximumSizeValue` compare direction, avoiding the zero-folded max test.
// Variant lab (probe 4): a 16-case natural source lab showed that declaring the
// outer index before the result keeps the exact-size/frame/call-set basin and
// improves the positional frontier; direct repeated artifact expressions were
// 649 bytes, while named artifact plus `i`-first was the best group.
// Final current-claim probes: the element-reference/byte-offset spelling was
// codegen-duplicate; canonical full inheritance/member context and class (not
// struct) TacticalAIGroup ABI were also codegen-duplicate. The prior readable
// i-first/named-artifact candidate is retained in history as the old baseline.
// Probe 14: replaced the explicit duplicate scan and growth path with the
// typed ManagedArray::add surface used by exact same-TU sibling counters. This
// restored the original count/loop/lifetime shape and matched all 510 bytes.
// Prior pause metrics: 510-byte size/frame/call-set parity, 7/7 ordered calls,
// 82.50% shape, 58.17% exact-block coverage, 350 positional diff bytes.
// Exact result: 510-byte size/frame/call-set parity and 100% positional match;
// no accepted-drift or inline-asm claim.

extern void* operator_new(unsigned int size);
extern void operator_delete(void* ptr);

int TribeTacticalAIModule::numberUngroupedArtifacts()
{
    int rNum = 0;
    int i = 0;
    ManagedArrayInt& workingArea = this->workingArea;
    ManagedArrayInt& artifacts = this->artifacts;

    workingArea.numberValue = 0;
    if (artifacts.numberValue > 0) {
        do {
            if (this->groupUnitIsIn(artifacts[i]) == 0) {
                workingArea.add(artifacts[i]);
                rNum++;
            }
            i++;
        } while (i < artifacts.numberValue);
    }
    return rNum;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004FD8D0_displaySoldierGroups.cpp
// ---------------------------------------------------------------------------
// 004FD8D0 TribeTacticalAIModule::displaySoldierGroups
// Attempt log:
// try 1: direct logging/control-flow reconstruction from packet with local method/type stubs; exact-size comparable under default /O2 but broad mismatch (70.1662% positional, 93.3535% edit). Prologue differs because VC5 emits EBP/8-byte stack alignment for double varargs in this local surface.
// try 2: tested /GX; no change, rolled back.
// try 3: tested /Zp4 with /O2; no change, rolled back.
// try 4: tested /O1: too small (.text 1260 vs 1324), rolled back.
// try 5: tested /Od: exact-size comparable but worse debug-basin mismatch (74.3202% positional, 142.9003% edit), rolled back.
// left in scratch: behavior/call-set skeleton covers group filtering, target/object logging, object-to-destroy/unit/waypoint loops, but not accepted_drift quality. Needs exact declaration/prototype context for AIModule::logCommonHistory and group/unit surfaces to avoid stack-alignment/prologue and broad call-order drift.
// try 6: restored the repeated direct unitAI() receivers in the large unit
//   varargs expression, then removed duplicate md/index varargs from the two
//   target and object-to-destroy logs.  This recovered all 99 call sites and
//   matched 1324/1324 bytes; direct receiver repetition is period-plausible
//   and also preserves the original right-to-left varargs evaluation order.
// exact candidate: 0-byte positional and edit/resync diff under default flags;
//   kept in scratch for main-agent audit as requested.
// Source audit: restored the original format strings as ordinary literals and
// modeled the AIModule base plus object/player virtual surfaces.  This keeps
// the direct cdecl member logger and proven field ownership period-plausible.

void TribeTacticalAIModule::displaySoldierGroups()
{
    RGE_Static_Object* object;

    this->logCommonHistory("Soldier Groups:");
    TacticalAIGroup* g = this->groups.next;
    while (g != &this->groups) {
        if (!g) return;
        if (g->type() == 100 || g->type() == 101 || g->type() == 102 || g->type() == 109) {
            if (g->type() == 100) this->logCommonHistory("  Group ID#%d:  Attack Group (Type=%d).", g->id(), g->type());
            else if (g->type() == 101) this->logCommonHistory("  Group ID#%d:  Defend Group (Type=%d).", g->id(), g->type());
            else if (g->type() == 102) this->logCommonHistory("  Group ID#%d:  Explore Group (Type=%d).", g->id(), g->type());
            else if (g->type() == 109) this->logCommonHistory("  Group ID#%d:  Artifact Group (Type=%d).", g->id(), g->type());

            this->logCommonHistory("    NumUnits=%d, DesNumUnits=%d, OrgNumUnits=%d, Action=%d, inUse=%d.", g->numberUnits(), g->desiredNumberUnits(), g->originalUnitNumber(), g->action(), g->inUse());
            object = this->md->object(g->target());
            if (object) {
                this->logCommonHistory("    Target=%d (%s), CommanderID=%d, HP(%d/%d), WaitCode=%d.", g->target(), object->master_obj->name(), g->commander(), g->currentHitPoints(this->md), g->originalHitPoints(), g->waitCode());
            } else {
                this->logCommonHistory("    Target=%d, CommanderID=%d, HP(%d/%d), WaitCode=%d.", g->target(), g->commander(), g->currentHitPoints(this->md), g->originalHitPoints(), g->waitCode());
            }
            this->logCommonHistory("    AssistGroupID=%d, AssistGroupType=%d, ConsecIdleCount=%ld.", g->assistGroupID(), g->assistGroupType(), g->consecutiveIdleUnitCount());
            this->logCommonHistory("    Location=(%f, %f).", g->location().x, g->location().y);
            this->logCommonHistory("    Gather Location=(%f, %f).", g->gatherLocation().x, g->gatherLocation().y);
            this->logCommonHistory("    Retreat Location=(%f, %f).", g->retreatLocation().x, g->retreatLocation().y);
            this->logCommonHistory("    Target Location=(%f, %f).", g->targetLocation().x, g->targetLocation().y);
            this->logCommonHistory("    Play=%d.", g->playNumberValue);
            this->logCommonHistory("    NumberObjectsToDestroy=%d.", g->numberObjectsToDestroyValue);
            if (g->numberObjectsToDestroyValue > 0) {
                for (int i = 0; i < g->numberObjectsToDestroyValue; ++i) {
                    object = this->md->object(g->objectToDestroy(i));
                    if (!object) this->logCommonHistory("      ObjectToDestroy #%d:  Unit #%d, but it's gone.", i, g->objectToDestroy(i));
                    else this->logCommonHistory("      ObjectToDestroy #%d:  Unit #%d (%s).", i, g->objectToDestroy(i), object->master_obj->name());
                }
            }
            for (int i = 0; i < g->numberUnits(); ++i) {
                object = this->md->object(g->unit(i));
                if (!object) {
                    this->logCommonHistory("    Unit %d is invalid.");
                } else if (!object->unitAI()) {
                    this->logCommonHistory("    Unit %d has invalid unitAI.");
                } else {
                            this->logCommonHistory("    Unit %d (%s): state=%d, action=%d, target=%d, order=%d, pri=%d, loc=(%3f, %3f), tLoc=(%3f, %3f).", g->unit(i), object->master_obj->name(), object->object_state, object->unitAI()->currentAction(), object->unitAI()->currentTarget(), object->unitAI()->currentOrder(), object->unitAI()->currentOrderPriority(), object->world_x, object->world_y, object->unitAI()->currentTargetX(), object->unitAI()->currentTargetY());
                    if (object->unitAI()->currentTarget() != -1) {
                        object = this->md->object(object->unitAI()->currentTarget());
                        if (object) this->logCommonHistory("      Target: %s, Owner=%d.", object->master_obj->name(), object->owner->id);
                    }
                }
            }
            if (!g->numberAttackWaypoints()) {
                this->logCommonHistory("    No waypoints.");
            } else {
                this->logCommonHistory("    Waypoints:");
                for (int i = 0; i < (int)(unsigned int)g->numberAttackWaypoints(); ++i) {
                    this->logCommonHistory("      (%f, %f).", g->attackWaypoint(i)->x, g->attackWaypoint(i)->y);
                }
                this->logCommonHistory("    Current waypoints=%d.", (unsigned int)g->currentAttackWaypoint());
            }
        }
        g = g->next;
    }
}

// ---------------------------------------------------------------------------
// PDB source owner: 004FDE00_setupBoatGroups.cpp
// ---------------------------------------------------------------------------
// 004FDE00 TribeTacticalAIModule::setupBoatGroups
// Source: taitacmd.cpp lines 10322-10681
//
// Baseline reconstruction: the local groupsToRemove is the real inline
// ManagedArray<int> surface. The three boat lists and workingArea are named
// ManagedArray<int> members, while the group list is the TacticalAIGroup
// sentinel owned by TribeTacticalAIModule. The repeated boat phases are kept
// as ordinary source-level loops; their shared remove/copy topology is visible
// in the original CFG.
// FLAGS: config/flags/004FDE00_setupBoatGroups.rsp (/GX for the observed EH frame).
//
// Attempt log:
// - baseline: canonical TacticalAIGroup sentinel, inline ManagedArray ownership,
//   and three ordinary boat-group phases; 2887-byte target rebuilt as 2894
//   bytes with a 0x28/0x2C frame gap and an early type-filter CFG mismatch.
// - negative type guard with explicit continue: matched the original late
//   type-match body and reduced the positional diff from 2602 to 730 bytes.
// - declaration/local-role reorderings (including the retained type-68 count)
//   emitted the same VC5 code; no further declaration archaeology retained.
// - positive nested remainder guards and commutative product-order probes were
//   also codegen duplicates; they remain diagnostic evidence only.
// - /GX balance-shape lab: a named product temporary plus compact positive
//   clamps produced the exact 2887-byte size and exact balance focus range.
// - explicit remainder guards with a separate retained type-68 local restored
//   the 730-byte diagnostic basin but added 16 bytes after the target boundary;
//   rolled back because structural size is authoritative.
// - compact arithmetic with a separate retained local, hoisted product and
//   remainder locals, and the exact setupSoldierGroups scalar declaration order
//   all emitted the clean 745-byte codegen group; no new structural lead.
// - corrected the third balance denominator/cap from sn[0x3d]/sn[0x3c] to
//   sn[0x3e]/sn[0x3d], matching original offsets 0x28C/0x288; shape improved
//   from 94.07% to 94.39% and exact blocks from 70.87% to 71.29%, with the
//   same 745-byte positional diff.
// - fresh pass: 20 evidence-led declaration, lifetime, arithmetic, and loop
//   probes kept the same 745-byte codegen basin. A volatile
//   numPotentialEGroups restored the 0x2C frame and 81.57% exact blocks, but
//   added 16 bytes after the boundary; it is diagnostic evidence only.
// - fresh pass: explicit shared-balance gotos, address-taking, split count
//   lifetimes, register hints, function-scope group pointers, and loop-form
//   rewrites were codegen duplicates or worse. Restored this clean source.
// - current best is still non-exact: 745 positional diff bytes, 94.39% shape,
//   71.29% exact blocks, 93/93 ordered calls, and frame 0x28 versus 0x2C.
//   Remaining lead is the real local-lifetime/register basin around the target
//   stack homes (especially the saved numPotentialEGroups/numAGroups values).
// - ManagedArray recovery pass, 2026-08-19: the exact add body replaces the
//   manual caller-side scan and emits the same 2887-byte frontier. The complete
//   shared header inlines resize at this site, adds one allocator pair and 82
//   bytes, and changes the call surface. Keep resize declaration-only here.
// - fresh pass: a natural min ternary for the else-arm potential-group clamp
//   restores the 0x2C frame and the main balance CFG. Named maximum and count
//   locals preserve the sn-first load order. A function-scope remainder local
//   is codegen-identical in this basin.
// - current best is 643 positional diff bytes, 98.84% shape, 91.10% exact
//   blocks, and 93/93 ordered calls. The rebuilt size is 2889 versus 2887.
// - compound products, declaration-local call results, a typed balance pair,
//   and a function-scope product were codegen duplicates or worse. Restored
//   the smallest natural product and scalar forms.
// BINARY NOTE: the min clamp loads sn[0x3a] before warBoats.numberValue and
//   uses cmp eax,ecx. The ternary source reproduces that local instruction order.
// Remaining mismatch: the original first balance block loads numAGroups from
//   [esp+20h]. The best rebuild loads the same source value from [esp+24h].

void* operator new(unsigned int size);
void __cdecl operator_delete(void* ptr);
extern "C" double __cdecl ceil(double value);

void TribeTacticalAIModule::setupBoatGroups()
{
    ManagedArray_int groupsToRemove;
    int i;
    int numEGroups;
    int numPotentialEGroups;
    int numPotentialAGroups;
    int numDGroups;
    int remaining;
    int numAGroups;
    TacticalAIGroup* sentinel;
    TacticalAIGroup* group;

    group = this->groups.next;
    sentinel = &this->groups;
    while (group != sentinel && group != 0) {
        if (group->type() != 0x67 &&
            group->type() != 0x68 &&
            group->type() != 0x69) {
            group = group->next;
            continue;
        }
        if (group->numberUnits() == 0) {
            groupsToRemove.add(group->id());
        }
        group = group->next;
    }

    numEGroups = 0;
    while (numEGroups < groupsToRemove.numberValue) {
        this->removeGroup(groupsToRemove[numEGroups]);
        ++numEGroups;
    }

    i = this->numberGroups(0x67, -1);
    numAGroups = this->numberGroups(0x68, -1);
    numPotentialAGroups = this->numberGroups(0x69, -1);
    this->numberGroups(0x6b, -1);
    this->numberGroups(0x6c, -1);
    this->numberGroups(0x6a, -1);

    this->numberUngroupedFishingBoats();
    while (this->workingArea.numberValue > 0) {
        int object_id = this->workingArea[numEGroups];
        RGE_Static_Object* object = this->md->object(object_id);
        if (object == 0) {
            this->workingArea.remove(object_id);
        }
        else {
            TacticalAIGroup* new_group = this->createGroup(1);
            if (new_group == 0) {
                break;
            }
            new_group->setType(0x6b);
            new_group->setDesiredNumberUnits(this->sn[0x41] + 1);
            new_group->addUnit(object_id, this->md);
            new_group->setSpecificCommander(object_id, this->md);
            new_group->setLocation(object->world_x, object->world_y, object->world_z);
            new_group->setGatherLocation(object->world_x, object->world_y, object->world_z);
            new_group->setRetreatLocation(object->world_x, object->world_y, object->world_z);
            this->workingArea.remove(object_id);
        }
    }

    this->numberUngroupedTradeBoats();
    while (this->workingArea.numberValue > 0) {
        int object_id = this->workingArea[numEGroups];
        RGE_Static_Object* object = this->md->object(object_id);
        if (object == 0) {
            this->workingArea.remove(object_id);
        }
        else {
            TacticalAIGroup* new_group = this->createGroup(1);
            if (new_group == 0) {
                break;
            }
            new_group->setType(0x6c);
            new_group->setDesiredNumberUnits(this->sn[0x40] + 1);
            new_group->addUnit(object_id, this->md);
            new_group->setSpecificCommander(object_id, this->md);
            new_group->setLocation(object->world_x, object->world_y, object->world_z);
            new_group->setGatherLocation(object->world_x, object->world_y, object->world_z);
            new_group->setRetreatLocation(object->world_x, object->world_y, object->world_z);
            this->workingArea.remove(object_id);
        }
    }

    this->numberUngroupedTransportBoats();
    while (this->workingArea.numberValue > 0) {
        int object_id = this->workingArea[numEGroups];
        RGE_Static_Object* object = this->md->object(object_id);
        if (object == 0) {
            this->workingArea.remove(object_id);
        }
        else {
            TacticalAIGroup* new_group = this->createGroup(1);
            if (new_group == 0) {
                break;
            }
            new_group->setType(0x6a);
            new_group->setDesiredNumberUnits(this->sn[0x42] + 1);
            new_group->addUnit(object_id, this->md);
            new_group->setSpecificCommander(object_id, this->md);
            new_group->setLocation(object->world_x, object->world_y, object->world_z);
            new_group->setGatherLocation(object->world_x, object->world_y, object->world_z);
            new_group->setRetreatLocation(object->world_x, object->world_y, object->world_z);
            this->workingArea.remove(object_id);
        }
    }

    int boat_id = this->boats[0];
    if (this->md->informationAI.fullyExploredZone(boat_id) == 0) {
        this->removeAllGroups(0x69);
        this->setStrategicNumber(0x3d, 0);
    }

    numEGroups = 0;
    numDGroups = 0;
    if (this->sn[0x28] == 0) {
        numPotentialEGroups = (int)ceil(
            (double)this->warBoats.numberValue / (double)this->sn[0x3b]);
        if (numPotentialEGroups > this->sn[0x3a]) numPotentialEGroups = this->sn[0x3a];
        int product = numPotentialEGroups * this->sn[0x3b];
        remaining = this->warBoats.numberValue - product;
        if (remaining > 0) {
            numEGroups = (int)ceil((double)remaining / (double)this->sn[0x44]);
            if (numEGroups > this->sn[0x43]) numEGroups = this->sn[0x43];
            remaining = this->warBoats.numberValue -
                        product - numEGroups * this->sn[0x44];
            if (remaining > 0) {
                numDGroups = (int)ceil((double)remaining / (double)this->sn[0x3e]);
                if (numDGroups > this->sn[0x3d]) numDGroups = this->sn[0x3d];
            }
        }
    }
    else {
        int maxPotentialEGroups = this->sn[0x3a];
        int warBoatCount = this->warBoats.numberValue;
        numPotentialEGroups =
            warBoatCount < maxPotentialEGroups
                ? warBoatCount
                : maxPotentialEGroups;
        remaining = this->warBoats.numberValue - numPotentialEGroups;
        if (remaining > 0) {
            numEGroups = remaining < this->sn[0x43] ? remaining : this->sn[0x43];
            remaining -= numEGroups;
            if (remaining > 0) {
                numDGroups = remaining;
                if (numDGroups >= this->sn[0x3d]) numDGroups = this->sn[0x3d];
            }
        }
    }
balance_boat_groups:
    for (; i < numPotentialEGroups; ++i) {
        TacticalAIGroup* new_group = 0;
        if (numAGroups > 0) {
            new_group = this->group(-1, 0x68, -1, -1);
            if (new_group != 0) {
                --numAGroups;
            }
            else {
                new_group = this->group(-1, 0x69, -1, -1);
                if (new_group != 0) {
                    --numPotentialAGroups;
                }
            }
        }
        if (new_group == 0) {
            new_group = this->createGroup(1);
            if (new_group == 0) {
                break;
            }
        }
        new_group->setType(0x67);
        new_group->setTarget(-1);
        new_group->setTargetType(-1);
        new_group->setAction(1);
        new_group->setInUse(0);
        new_group->setDesiredNumberUnits(this->sn[0x3b]);
    }

    while (i > numPotentialEGroups) {
        TacticalAIGroup* old_group = this->group(-1, 0x67, 0, -1);
        if (old_group == 0) {
            old_group = this->group(-1, 0x67, 1, -1);
        }
        if (old_group == 0) {
            break;
        }
        this->removeGroup(old_group->id());
        --i;
    }

    for (; numAGroups < numEGroups; ++numAGroups) {
        TacticalAIGroup* new_group = 0;
        if (numPotentialAGroups > 0) {
            new_group = this->group(-1, 0x69, -1, -1);
            if (new_group != 0) {
                --numPotentialAGroups;
            }
        }
        if (new_group == 0) {
            new_group = this->createGroup(1);
            if (new_group == 0) {
                break;
            }
        }
        new_group->setType(0x68);
        new_group->setTarget(-1);
        new_group->setTargetType(-1);
        new_group->setAction(1);
        new_group->setInUse(0);
        new_group->setDesiredNumberUnits(this->sn[0x44]);
    }

    while (numAGroups > numEGroups) {
        TacticalAIGroup* old_group = this->group(-1, 0x68, -1, -1);
        if (old_group == 0) {
            break;
        }
        this->removeGroup(old_group->id());
        --numAGroups;
    }

    for (; numPotentialAGroups < numDGroups; ++numPotentialAGroups) {
        TacticalAIGroup* new_group = this->createGroup(1);
        if (new_group == 0) {
            break;
        }
        new_group->setType(0x69);
        new_group->setDesiredNumberUnits(this->sn[0x3d]);
    }

    while (numPotentialAGroups > numDGroups) {
        TacticalAIGroup* old_group = this->group(-1, 0x69, -1, -1);
        if (old_group == 0) {
            break;
        }
        this->removeGroup(old_group->id());
        --numPotentialAGroups;
    }
}

// ---------------------------------------------------------------------------
// PDB source owner: 004FE950_fillBoatGroups.cpp
// ---------------------------------------------------------------------------
// VA: 004FE950 TribeTacticalAIModule::fillBoatGroups
// Attempt log:
// baseline: natural period-plausible reconstruction using the real group list,
// ManagedArray<int> workingArea ownership, and the three boat-filling passes.
// Bounded pass: restored the group-sentinel walk, commander assignment for
// empty/nonempty boat groups, workingArea growth/removal, three type-based fill
// passes, nearest-unit selection, and excess-unit redistribution. Declaration,
// loop, predicate, count-cache, and selection-tail probes did not recover the
// original physical block order. Final validation is 2924/2959 bytes with the
// exact 0x18 frame and exact 103-call target multiset, but only 87.38% ordered
// alignment; the remaining issue is broad CFG placement around the best-unit
// loop and transition back to the group list, not a codegen-only local axis.
// Later structural probes inverted direct-fill/nearest branches and the final
// best-group fallback, then scoped the second boat iterator. Ordered calls now
// align 103/103 with a 2935-byte rebuild; the remaining drift is register and
// block placement at the second boat pass, not call or memory-effect coverage.
// The final candidate keeps these natural source shapes and remains in scratch.
// Integration check: the ordered call map is aligned, but the checker still
// reports one direct-target difference at +08E7 (desiredNumberUnits versus
// numberUnits). Treat that site as the next binary-behavior lead.
// Tried the proven same-TU AIModule base surface with md at +0xF0; emitted
// code was unchanged, so restored the clean source.
// Tried a natural for-loop increment for the second boat-type scan because
// the original has separate type-skip and underfilled-false increment blocks;
// it changed diff 2472 to 2481 and was rolled back.
// Managed pass 2026-08-17: ran 22 meaningful hypotheses. The clean baseline
// remains the best codegen result: 2935 bytes, 2472 differing bytes, 92.95%
// shape, exact frame, and 103 aligned calls. The pass tested group-local
// reuse, loop polarity and do-loop forms, scope and declaration order, the
// repeated nearest-fill loop, desired/number call order, exact ManagedArray
// copy forms, C-linkage allocation helpers, and fallback cursor reuse.
// The original proves a repeated nearest-fill backedge at 004FEDCA and a
// desired-then-number call order at 004FF156. Adding that loop improved the
// behavior model but moved the result to 2937 bytes and 2481 differing bytes;
// it was restored because it did not preserve the original physical layout.
// All array, pointer, and candidate-local variants were codegen-neutral or
// worse. The remaining lead is the compiler's second-pass register and block
// allocation: original uses EBP for the sentinel and EDI for the boat group,
// while the clean source uses EBX for the sentinel and EBP for that group.
// Worker pass: the exact ManagedIntArray donor loop, global allocation
// spelling, <stddef.h> context, and mutable sentinel all emit this same
// 2935-byte baseline. An ambient declaration lab with 128 samples found one
// codegen group and no context lead. The unresolved first nearest-fill loop
// still has the proven executable backedge at 004FEDCA.


extern void* operator new(unsigned int);
extern void operator delete(void*);

void TribeTacticalAIModule::fillBoatGroups() {
    int bestUnit;

    this->numberUngroupedWarBoats();
    this->numberExtraGroupedWarBoats();

    TacticalAIGroup* sentinel = &this->groups;
    TacticalAIGroup* group = this->groups.next;
    while (group != sentinel) {
        if (group == 0) {
            break;
        }
        if (group->type() == 0x67 || group->type() == 0x68 || group->type() == 0x69) {
            if (group->commander() == -1) {
                int ungrouped = this->numberUngroupedWarBoats();
                if (group->numberUnits() > 0) {
                    int commander = this->selectBestCommander(group);
                    group->setSpecificCommander(commander, this->md);
                    if (group->action() == 0 || group->action() == 1) {
                        this->setAllGroupLocations(group);
                    }
                }
                else {
                    if (ungrouped == 0) {
                        this->numberExtraGroupedWarBoats();
                    }
                    if (this->workingArea.numberValue == 0) {
                        return;
                    }
                    int commander = this->selectBestCommander(&this->workingArea);
                    group->addUnit(commander, this->md);
                    group->setSpecificCommander(commander, this->md);
                    if (group->action() == 0 || group->action() == 1) {
                        this->setAllGroupLocations(group);
                    }
                }
            }
        }
        group = group->next;
    }

    if (this->strategicNumbers[0x28] == 0) {
        bestUnit = 0x67;
        do {
            TacticalAIGroup* boatGroup = this->groups.next;
            while (boatGroup != sentinel) {
                if (boatGroup == 0) {
                    break;
                }
                if (boatGroup->type() != bestUnit) {
                    boatGroup = boatGroup->next;
                    continue;
                }
                int desired = boatGroup->desiredNumberUnits();
                int number = boatGroup->numberUnits();
                if (number < desired) {
                        int ungrouped = this->numberUngroupedWarBoats();
                        int desiredForFill = boatGroup->desiredNumberUnits();
                        int numberForFill = boatGroup->numberUnits();
                        int missing = desiredForFill - numberForFill;
                        if (missing >= ungrouped) {
                            int i = 0;
                            if (this->workingArea.numberValue > 0) {
                                do {
                                    boatGroup->addUnit(this->workingArea[i], this->md);
                                    ++i;
                                } while (i < this->workingArea.numberValue);
                            }
                        }
                        else {
                            int desiredAgain = boatGroup->desiredNumberUnits();
                            int numberAgain = boatGroup->numberUnits();
                            if (numberAgain < desiredAgain) {
                                int i = 0;
                                float bestDistance = -1.0f;
                                int bestUnitID = -1;
                                if (this->workingArea.numberValue > 0) {
                                    do {
                                        RGE_Static_Object* object = this->md->object(this->workingArea[i]);
                                        if (object != 0) {
                                            float distance = object->distance_to_position(
                                                boatGroup->gatherLocation().x,
                                                boatGroup->gatherLocation().y,
                                                boatGroup->gatherLocation().z);
                                            if (bestDistance == -1.0f || distance < bestDistance) {
                                                bestUnitID = this->workingArea[i];
                                                bestDistance = distance;
                                            }
                                        }
                                        ++i;
                                    } while (i < this->workingArea.numberValue);
                                }
                                if (bestUnitID != -1) {
                                    boatGroup->addUnit(bestUnitID, this->md);

                                    int max = this->workingArea.maximumSizeValue;
                                    int removeIndex = 0;
                                    if (max > 0) {
                                        int* value = this->workingArea.value;
                                        do {
                                            if (*value == bestUnitID) {
                                                break;
                                            }
                                            ++removeIndex;
                                            ++value;
                                        } while (removeIndex < max);
                                    }
                                    if (removeIndex < max) {
                                        if (removeIndex < max - 1) {
                                            do {
                                                ++removeIndex;
                                                this->workingArea.value[removeIndex - 1] = this->workingArea.value[removeIndex];
                                            } while (removeIndex < max - 1);
                                        }
                                        int count = this->workingArea.numberValue - 1;
                                        this->workingArea.numberValue = count;
                                        if (count < 0) {
                                            this->workingArea.numberValue = 0;
                                        }
                                    }

                                    desiredAgain = boatGroup->desiredNumberUnits();
                                    numberAgain = boatGroup->numberUnits();
                                    if (numberAgain < desiredAgain) {
                                        continue;
                                    }
                                }
                            }
                        }

                        int desiredAfter = boatGroup->desiredNumberUnits();
                        int numberAfter = boatGroup->numberUnits();
                        if (numberAfter < desiredAfter) {
                            int extra = this->numberExtraGroupedWarBoats();
                            int desiredExtra = boatGroup->desiredNumberUnits();
                            int numberExtra = boatGroup->numberUnits();
                            int missingExtra = desiredExtra - numberExtra;
                            if (missingExtra >= extra) {
                                int i = 0;
                                if (this->workingArea.numberValue > 0) {
                                    do {
                                        this->removeFromGroup(this->workingArea[i]);
                                        boatGroup->addUnit(this->workingArea[i], this->md);
                                        ++i;
                                    } while (i < this->workingArea.numberValue);
                                }
                            }
                            else {
                                int desiredNearest = boatGroup->desiredNumberUnits();
                                int numberNearest = boatGroup->numberUnits();
                                if (numberNearest < desiredNearest) {
                                    do {
                                        int i = 0;
                                        float bestDistance = -1.0f;
                                        int bestUnitID = -1;
                                        if (this->workingArea.numberValue > 0) {
                                            do {
                                                RGE_Static_Object* object = this->md->object(this->workingArea[i]);
                                                if (object != 0) {
                                                    float distance = object->distance_to_position(
                                                        boatGroup->gatherLocation().x,
                                                        boatGroup->gatherLocation().y,
                                                        boatGroup->gatherLocation().z);
                                                    if (bestDistance == -1.0f || distance < bestDistance) {
                                                        bestUnitID = this->workingArea[i];
                                                        bestDistance = distance;
                                                    }
                                                }
                                                ++i;
                                            } while (i < this->workingArea.numberValue);
                                        }
                                        if (bestUnitID == -1) {
                                            break;
                                        }
                                        this->removeFromGroup(bestUnitID);
                                        boatGroup->addUnit(bestUnitID, this->md);

                                        int max = this->workingArea.maximumSizeValue;
                                        int removeIndex = 0;
                                        if (max > 0) {
                                            int* value = this->workingArea.value;
                                            do {
                                                if (*value == bestUnitID) {
                                                    break;
                                                }
                                                ++removeIndex;
                                                ++value;
                                            } while (removeIndex < max);
                                        }
                                        if (removeIndex < max) {
                                            if (removeIndex < max - 1) {
                                                do {
                                                    ++removeIndex;
                                                    this->workingArea.value[removeIndex - 1] = this->workingArea.value[removeIndex];
                                                } while (removeIndex < max - 1);
                                            }
                                            int count = this->workingArea.numberValue - 1;
                                            this->workingArea.numberValue = count;
                                            if (count < 0) {
                                                this->workingArea.numberValue = 0;
                                            }
                                        }
                                    } while (boatGroup->numberUnits() < boatGroup->desiredNumberUnits());
                                }
                            }
                        }
                }
                boatGroup = boatGroup->next;
            }
            ++bestUnit;
        } while (bestUnit <= 0x6A);
    }

    if (this->numberUngroupedWarBoats() != 0 && this->workingArea.numberValue > 0) {
        TacticalAIGroup* bestGroup;
        int i = 0;
        do {
            bestGroup = 0;
            int bestDifference = 0;
            group = this->groups.next;
            while (group != sentinel) {
                if (group == 0) {
                    break;
                }
                if (group->type() == 0x67 || group->type() == 0x68 ||
                    group->type() == 0x69 || group->type() == 0x6A ||
                    group->type() == 0x6B || group->type() == 0x6C) {
                    int number = group->numberUnits();
                    int desired = group->desiredNumberUnits();
                    if (number < desired) {
                        if (group->action() == 1 || group->action() == 0) {
                            int numberAgain = group->numberUnits();
                            int desiredAgain = group->desiredNumberUnits();
                            int difference = numberAgain - desiredAgain;
                            if (bestGroup == 0 || difference < bestDifference) {
                                bestGroup = group;
                                bestDifference = difference;
                            }
                        }
                    }
                }
                group = group->next;
            }

            if (bestGroup != 0) {
                bestGroup->addUnit(this->workingArea[i], this->md);
            }
            else {
                TacticalAIGroup* candidate = this->groups.next;
                bestDifference = 0;
                while (candidate != sentinel) {
                    if (candidate == 0) {
                        break;
                    }
                    if ((candidate->type() == 0x67 || candidate->type() == 0x68 ||
                         candidate->type() == 0x69 || candidate->type() == 0x6A ||
                         candidate->type() == 0x6B || candidate->type() == 0x6C) &&
                        (candidate->action() == 1 || candidate->action() == 0)) {
                        int type = candidate->type();
                        if (type == 0x67 && candidate->numberUnits() >= this->strategicNumbers[0x3C]) {
                            candidate = candidate->next;
                            continue;
                        }
                        type = candidate->type();
                        if (type == 0x68 && candidate->numberUnits() >= this->strategicNumbers[0x45]) {
                            candidate = candidate->next;
                            continue;
                        }
                        type = candidate->type();
                        if (type == 0x69 && candidate->numberUnits() >= this->strategicNumbers[0x3F]) {
                            candidate = candidate->next;
                            continue;
                        }
                        int difference = candidate->numberUnits();
                        difference -= candidate->desiredNumberUnits();
                        if (bestGroup == 0 || difference < bestDifference) {
                            bestGroup = candidate;
                            bestDifference = difference;
                        }
                    }
                    candidate = candidate->next;
                }
                if (bestGroup == 0) {
                    return;
                }
                bestGroup->addUnit(this->workingArea[i], this->md);
            }
            ++i;
        } while (i < this->workingArea.numberValue);
    }
}

// ---------------------------------------------------------------------------
// PDB source owner: 004FF4E0_numberUngroupedWarBoats.cpp
// ---------------------------------------------------------------------------
// VA: 004FF4E0 TribeTacticalAIModule::numberUngroupedWarBoats
// Attempt log:
// baseline: raw-offset expandable-array reconstruction had the right call set and
// size, but broad structural/register drift started at the prologue.
// probe 2: replaced raw array plumbing with typed ManagedArray<int> boats and
// workingArea members. This matched the exact same-TU numberUngroupedSoldiers
// donor's ordinary indexer/add source shape and produced an exact 510-byte match.
// exact: canonical ownership is the boats and workingArea ManagedArray<int>
// members at +134 and +D48; no raw-offset plumbing or compiler steering remains.

extern "C" {
    void* operator_new(unsigned int size);
    void operator_delete(void* ptr);
}

int TribeTacticalAIModule::numberUngroupedWarBoats()
{
    int rNum = 0;
    int i = 0;
    ManagedArray<int>& workingArea = this->workingArea;
    ManagedArray<int>& boats = this->boats;

    workingArea.numberValue = 0;
    if (boats.numberValue > 0) {
        do {
            if (this->groupUnitIsIn(boats[i]) == 0) {
                workingArea.add(boats[i]);
                rNum++;
            }
            i++;
        } while (i < boats.numberValue);
    }
    return rNum;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004FF6E0_numberExtraGroupedWarBoats.cpp
// ---------------------------------------------------------------------------
// VA: 004FF6E0, TribeTacticalAIModule::numberExtraGroupedWarBoats, 509 bytes
// Attempt log:
// - Prior scratch work used raw working-area fields and reached 509 bytes, but
//   it used a compiler-shaped register basin and did not model array ownership.
// - Baseline in this session rebuilt at 541 bytes. It had the right 19 calls,
//   but the working-area scan and list CFG had extra structural blocks.
//
// This source models the proven group sentinel and workingArea as their
// period-plausible typed owners. The inline array method is the same ownership
// surface used by exact same-TU ManagedArray donors.
//
// Probe notes:
// - ManagedArray::add plus the explicit while loop aligned all 19 calls and
//   reduced the function to the exact 509-byte boundary.
// - Left-side comparison spellings aligned the remaining branch opcodes.
// - A local workingArea reference aligned the prologue order and all body
//   bytes except stack-home displacements.
// - A natural do-while spelling for the inner predicate added one
//   numberUnits call and 11 bytes; restored the while/break reconstruction.
// - A direct typed count predicate reversed the initial numberUnits/
//   desiredNumberUnits call order and increased the diff to 19 bytes; restored
//   the explicit count temporary.
// - Scalar declaration permutations, split/chained initialization, scoped
//   inner locals, and the unmapped decompiler j local were codegen duplicates.
// - A natural for-loop added one numberUnits call and 11 bytes; volatile result
//   storage caused broad drift. Both diagnostic variants were restored.
// - Remaining drift is 10 stack-home bytes: VC5 assigns result/rNum/tempCount
//   to [esp+10]/[esp+18]/[esp+14], while the oracle uses [esp+18]/[esp+14]/
//   [esp+10]. No behavior or call-set drift remains.
// - This claim tested direct declaration permutations and three zero-init forms;
//   an 18-variant sweep produced only two codegen groups, neither exact.
// - Partial rNum/tempCount scopes and hoisting add's copy index j were duplicates.
// - Restored this clean typed source; the remaining lead is TU or allocator context.
// - Revisit probes modeled the reviewed full TacticalAIModule and
//   TacticalAIGroup surfaces, moved the workingArea reference, and reordered
//   result/rNum/tempCount declarations. All emitted the same 10-byte home
//   permutation; the pinned typed source remains the natural reconstruction.
// - Main review replaced direct allocation calls with new[]/delete[] and the
//   manual vptr field with a virtual destructor. Codegen stayed unchanged.
// ACCEPTED DRIFT: The ten differing bytes consistently permute three nonescaping
// dword stack homes: result, rNum, and tempCount. Every read follows its matching
// write, including the push-adjusted rNum update. No home's address escapes.
// Register use, calls, values, writes, predicates, cleanup, and faults match.

int TribeTacticalAIModule::numberExtraGroupedWarBoats()
{
    ManagedArray<int>& workingArea = this->workingArea;
    int tempCount;
    int rNum;
    int result = 0;
    int numberUnitsValue;
    TacticalAIGroup* group;

    workingArea.numberValue = result;
    group = this->groups.next;
    while (group != &this->groups) {
        if (group == 0)
            return result;

            if ((group->type() == 103 || group->type() == 104 ||
                 group->type() == 105 || group->type() == 106 ||
                 group->type() == 107 || group->type() == 108) &&
                (group->action() == 1 || group->action() == 0)) {
                numberUnitsValue = group->numberUnits();
                if (numberUnitsValue > group->desiredNumberUnits()) {
                    rNum = group->numberUnits();
                    tempCount = 0;
                    if (rNum > group->desiredNumberUnits()) {
                        while (1) {
                            if (tempCount >= group->numberUnits())
                                break;
                            if (group->unit(tempCount) != group->commander()) {
                                rNum--;
                                workingArea.add(group->unit(tempCount));
                                result++;
                            }
                            tempCount++;
                            if (rNum <= group->desiredNumberUnits())
                                break;
                        }
                    }
                }
            }
        group = group->next;
    }
    return result;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004FF8E0_numberUngroupedFishingBoats.cpp
// ---------------------------------------------------------------------------
// VA: 004FF8E0 TribeTacticalAIModule::numberUngroupedFishingBoats
// Attempt log:
// 1: adapted known numberUngroupedSoldiers source to fishingBoats offsets: correct size 510 but broad 90.4% positional diff; compiler omitted push ebp and used ebp as newMax.
// 2: switched to decompiler-shaped local_4/i/local_c source based on numberUngroupedArtifacts scratch to force stack locals: 510 B, first mismatch at stack slot init, 79.6% diff.
// 3: removed volatile from i; worse first mismatch at frame immediate/slot allocation, rolled back.
// 4: tested local declaration reordering with volatile i; no slot/order change.
// 5: changed growth predicates to `local_4 > max-1` / `iVar2 > max-1` to match original cmp polarity; fixed first growth compare polarity but broad copy-loop/register drift remains.
// 6: tried local order local_c/i/local_4 and local_c/local_4/i with volatile offset temp; stack slot order unchanged.
// 7: tried /GX; unchanged.
// 8: tried /O2 without /Oy; unchanged.
// 9: tried /Od narrow flag; unchanged under this build harness/output family.
// 10: restored the best raw-offset reconstruction before this fresh typed pass; it rebuilt 566 bytes with structural drift from stack-slot ordering and copy-loop shape.
// 11: replaced manual array growth with the period-plausible inline ManagedArray
//     operator[]/add surfaces used by the exact same-TU numberUngroupedSoldiers
//     donor. The class declaration now names fishingBoats and workingArea at
//     the proven offsets; check this typed group-count reconstruction.
// 12: typed group-count reconstruction is an exact 510-byte match. The source
//     keeps canonical named ManagedArray ownership and ordinary references;
//     no raw-offset or compiler-steering form remains.

extern "C" {
    void* operator_new(unsigned int size);
    void operator_delete(void* ptr);
}

int TribeTacticalAIModule::numberUngroupedFishingBoats()
{
    int rNum = 0;
    int i = 0;
    ManagedArray<int>& workingArea = this->workingArea;
    ManagedArray<int>& fishingBoats = this->fishingBoats;

    workingArea.numberValue = 0;
    if (fishingBoats.numberValue > 0) {
        do {
            if (this->groupUnitIsIn(fishingBoats[i]) == 0) {
                workingArea.add(fishingBoats[i]);
                rNum++;
            }
            i++;
        } while (i < fishingBoats.numberValue);
    }
    return rNum;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004FFAE0_numberUngroupedTradeBoats.cpp
// ---------------------------------------------------------------------------
// Attempt log for 004FFAE0 TribeTacticalAIModule::numberUngroupedTradeBoats
// try 1: natural decompiler-shaped reconstruction with ManagedArray fields; exact size but 90.20% positional, compiler made 1-based loop and omitted EBP save.
// try 2: write closer to decompiler/original using local_4 index and allocation size local_4*4+4 directly; first mismatch moved to offset 16, exact size.
// try 3: reorder local declarations and store workingNumber from local_4 to probe stack slot/scheduling; no change.
// try 4: add middle dummy zero local to force local_4 to [esp+10]; dummy optimized away/no change.
// try 5: initialize rNum to zero before local_4 to occupy middle stack slot; no change.
// try 6: use <= skip form for first grow test to match cmp local_4,max; jle skip; small improvement.
// try 7: use <= skip form for second trade grow test too; no further change.
// try 8: adopt sibling numberUngroupedFishingBoats volatile i/copy-temp style; edit diff improved to 45.69%, first mismatch offset 17.
// try 9: /GX flag probe; unchanged, rolled back.
// try 10: /O1 flag probe; object too small (472B), rolled back.
// try 11: /Oy- flag probe; worse from offset 0, rolled back.
// try 12: replaced manual growth and raw pointer arithmetic with the period-plausible
//     ManagedArray operator[]/add surfaces from exact same-TU numberUngroupedSoldiers
//     and numberUngroupedFishingBoats donors; this is the natural typed reconstruction.

extern "C" {
    void* operator_new(unsigned int size);
    void operator_delete(void* ptr);
}

int TribeTacticalAIModule::numberUngroupedTradeBoats()
{
    int rNum = 0;
    int i = 0;
    ManagedArray<int>& workingArea = this->workingArea;
    ManagedArray<int>& tradeBoats = this->tradeBoats;

    workingArea.numberValue = 0;
    if (tradeBoats.numberValue > 0) {
        do {
            if (this->groupUnitIsIn(tradeBoats[i]) == 0) {
                workingArea.add(tradeBoats[i]);
                rNum++;
            }
            i++;
        } while (i < tradeBoats.numberValue);
    }
    return rNum;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004FFCE0_numberUngroupedTransportBoats.cpp
// ---------------------------------------------------------------------------
// VA: 004FFCE0 TribeTacticalAIModule::numberUngroupedTransportBoats
// Attempt log:
// try 1: cloned decompiler-style dynamic-array logic from analogous soldiers function, changing source array offsets to transportBoats (+0x174/+0x178/+0x180).
// try 2: used volatile i to force 0x0c frame; it preserves frame size but shifts rNum/local_4 stack slots versus original.
// try 3: reordered local declarations; no improvement in stack slot allocation.
// try 4: compare spelling `local_4 > maximum-1` restored early jle polarity but copy-loop topology remains wrong.
// try 5: factored helper style was considered from analogous function; compiles too small/out-of-line and loses original inlined growth shape.
// try 6: fully natural indexed source uses no EBP loop index and broad register drift.
// try 7: decompiler-style locals get EBP loop index and exact size but VC5 emits ecx index/shift copy loops instead of original eax increment + [base+eax*4-4].
// try 8: non-volatile i kept exact size but did not improve topology (79.2% positional, 105.5% edit).
// try 9: original less-than compare spelling regressed slightly (79.6% positional, 109.8% edit).
// try 10: rNum-first local declaration did not move stack slots or copy-loop family.
// try 11: while(1)+break outer loop was neutral versus do/while for the major mismatch.
// try 12: replaced raw offset plumbing with the sibling's typed ManagedArray<int> surface and ordinary aliases; pending checker result.
// exact: sibling-shaped typed ManagedArray<int> reconstruction matches all 510 bytes with default flags.

extern "C" {
    void* operator_new(unsigned int size);
    void operator_delete(void* ptr);
}

int TribeTacticalAIModule::numberUngroupedTransportBoats()
{
    int rNum = 0;
    int i = 0;
    ManagedArray<int>& workingArea = this->workingArea;
    ManagedArray<int>& transportBoats = this->transportBoats;

    workingArea.numberValue = 0;
    if (transportBoats.numberValue > 0) {
        do {
            if (this->groupUnitIsIn(transportBoats[i]) == 0) {
                workingArea.add(transportBoats[i]);
                rNum++;
            }
            i++;
        } while (i < transportBoats.numberValue);
    }
    return rNum;
}

// ---------------------------------------------------------------------------
// PDB source owner: 004FFEE0_displayBoatGroups.cpp
// ---------------------------------------------------------------------------
// VA: 004FFEE0 TribeTacticalAIModule::displayBoatGroups
// taitacmd.cpp
// Attempt log:
// try 1: natural reconstruction from packet: walk boat group linked list, type-specific logging, stats, positions, per-boat loop.
// try 2: modeled list sentinel at this+0x9D4/next +0x9D8 and loop exit on sentinel/null.
// try 3: modeled TacticalAIGroup methods for observed calls: type 004EAF60, id 004EAF20, count 004EB2C0, object id 004EB2D0, stat getters and position getters.
// try 4: modeled first type filter exactly as repeated `type()` calls for 0x67,0x68,0x69,0x6B,0x6C,0x6A rather than caching type.
// try 5: modeled type-specific log strings at 0x58893C/0x588914/0x5888E8/0x588A6C/0x588A44/0x588A18 and shared log call.
// try 6: modeled stat summary and position logs with double promotion from float getters/fields.
// try 7: initially used `logCommonHistory(char*, ...)`; compiled equal 889B after adding player lookup, but broad 69.63% positional diff and first mismatch at prologue: compiler emitted EBP frame/stack alignment (`push ebp; mov ebp,esp; and esp,-8; sub esp,8`) while original is frameless push ebx/ebp/esi/edi.
// try 8: added Player::find_object(id) call for the observed 0040D760 lookup; this fixed size from 880B to 889B in varargs version.
// try 9: replaced varargs log declaration with fixed overloads to avoid stack-realignment prologue; this removed the EBP frame but shrank .text to 864B vs original 889B.
// Probe 11: restored the same-TU donor's AIModule base and cdecl varargs
// logger, then replaced decompiler-only group/object shims with the
// binary-backed method names and ABIs.  The target's [this+0xf0] value is the
// MainDecisionAIModule pointer, not a Player/finder object; the final log is
// the five-value unit state record (the md argument belongs only to
// currentHitPoints()).
// Exact under the default VC5 flags: 889/889 bytes, 69/69 ordered calls,
// frameless push ebx/ebp/esi/edi prologue.  The readable typed source is kept
// for promotion; no compiler-steering or inline assembly is used.

void TribeTacticalAIModule::displayBoatGroups()
{
    this->logCommonHistory("Boat Groups:");
    TacticalAIGroup* group = this->groups.next;
    while (group != &this->groups) {
        if (group == 0)
            return;

        if (group->type() == 0x67 || group->type() == 0x68 ||
            group->type() == 0x69 || group->type() == 0x6B ||
            group->type() == 0x6C || group->type() == 0x6A) {
            if (group->type() == 0x67)
                this->logCommonHistory(
                    "  Group ID#%d:  Attack Group (Type=%d).",
                    group->id(), group->type());
            else if (group->type() == 0x68)
                this->logCommonHistory(
                    "  Group ID#%d:  Defend Group (Type=%d).",
                    group->id(), group->type());
            else if (group->type() == 0x69)
                this->logCommonHistory(
                    "  Group ID#%d:  Explore Group (Type=%d).",
                    group->id(), group->type());
            else if (group->type() == 0x6B)
                this->logCommonHistory(
                    "  Group ID#%d:  Fishing Group (Type=%d).",
                    group->id(), group->type());
            else if (group->type() == 0x6C)
                this->logCommonHistory(
                    "  Group ID#%d:  Trade Group (Type=%d).",
                    group->id(), group->type());
            else if (group->type() == 0x6A)
                this->logCommonHistory(
                    "  Group ID#%d:  Transport Group (Type=%d).",
                    group->id(), group->type());

            this->logCommonHistory(
                "    NumUnits=%d, DesNumUnits=%d, OrgNumUnits=%d, Action=%d, inUse=%d.",
                group->numberUnits(), group->desiredNumberUnits(),
                group->originalUnitNumber(), group->action(), group->inUse());
            this->logCommonHistory(
                "    Target=%d, CommanderID=%d, HP(%d/%d), AssistGroupID=%d.",
                group->target(), group->commander(),
                group->currentHitPoints(this->md), group->originalHitPoints(),
                group->assistGroupID());
            this->logCommonHistory("    Location=(%f, %f).",
                                   group->location().x, group->location().y);
            this->logCommonHistory("    Gather Location=(%f, %f).",
                                   group->gatherLocation().x,
                                   group->gatherLocation().y);
            this->logCommonHistory("    Retreat Location=(%f, %f).",
                                   group->retreatLocation().x,
                                   group->retreatLocation().y);
            this->logCommonHistory("    Target Location=(%f, %f).",
                                   group->targetLocation().x,
                                   group->targetLocation().y);

            for (int i = 0; i < group->numberUnits(); ++i) {
                this->logCommonHistory("    Unit #%d.", group->unit(i));
                RGE_Static_Object* object =
                    this->md->object(group->unit(i));
                if (object == 0) {
                    this->logCommonHistory("    Unit %d is invalid.");
                }
                else if (object->unitAI() == 0) {
                    this->logCommonHistory("    Unit %d has invalid unitAI.");
                }
                else {
                    this->logCommonHistory(
                        "    Unit %d: state=%d, action=%d, target=%d, order=%d, priority=%d, location=(%f, %f).",
                        group->unit(i), object->object_state,
                        object->unitAI()->currentAction(),
                        object->unitAI()->currentTarget(),
                        object->unitAI()->currentOrder(),
                        object->unitAI()->currentOrderPriority(), object->world_x,
                        object->world_y);
                }
            }
        }
        group = group->next;
    }
}

// ---------------------------------------------------------------------------
// PDB source owner: 00500260_createGroup.cpp
// ---------------------------------------------------------------------------
// 00500260 TribeTacticalAIModule::createGroup(int)
// Source: taitacmd.cpp lines 11261-11280
// FLAGS: /GX required for VC5 C++ new/constructor EH registration.
// Attempt log:
// - Replaced stub with real C++ `new TacticalAIGroup`, list insertion, optional
//   ID assignment, and group count increment.
// - Exact match: visible TacticalAIGroup size must be 0x330 so `new` emits the
//   original allocation size, and /GX supplies the constructor EH frame.

void* __cdecl operator new(unsigned int size);

TacticalAIGroup* TribeTacticalAIModule::createGroup(int assignID)
{
    TacticalAIGroup* group;
    int id;

    group = new TacticalAIGroup;
    if (group == 0) {
        return 0;
    }
    group->next = &this->groups;
    group->prev = this->groups.prev;
    group->prev->next = group;
    this->groups.prev = group;
    if (assignID == 1) {
        id = this->groupIDValue;
        this->groupIDValue = id + 1;
        group->setID(id);
        this->numberGroupsValue = this->numberGroupsValue + 1;
    }
    return group;
}

// ---------------------------------------------------------------------------
// PDB source owner: 00500320_removeGroup.cpp
// ---------------------------------------------------------------------------
// VA: 00500320 TribeTacticalAIModule::removeGroup
// MATCHED: use a natural `for (group = next; group != sentinel; group = group->next)` loop
// with an inner `if (group == 0) break;` before the id check. This makes VC5 place
// the sentinel compare at the bottom and jump back to a loop top that begins with
// the null test, matching the original layout.

int TribeTacticalAIModule::removeGroup(int id) {
    TacticalAIGroup* sentinel = &this->groups;
    int targetId = id;
    for (TacticalAIGroup* group = this->groups.next; group != sentinel; group = group->next) {
        if (group == 0) {
            break;
        }
        if (group->id() == targetId) {
            group->prev->next = group->next;
            group->next->prev = group->prev;
            if (group != 0) {
                delete group;
            }
    this->numberGroupsValue--;
            return 1;
        }
    }
    return 0;
}

// ---------------------------------------------------------------------------
// PDB source owner: 005003A0_removeAllGroups.cpp
// ---------------------------------------------------------------------------
// 005003A0 TribeTacticalAIModule::removeAllGroups(int)
// Source: taitacmd.cpp lines 11309-11325
// Attempt log:
// - Replaced stub with Ghidra list-removal logic and vtable-slot-0
//   deleting-destructor dispatch via a normal virtual member (`destroy(1)`).
// - Exact match: source must be `while (1)` with explicit top null break and
//   explicit bottom sentinel break. A `while (group != 0)`/do-while condition
//   makes VC5 add a bottom null test and shifts the epilogue.

int TribeTacticalAIModule::removeAllGroups(int type)
{
    int wanted;
    int groupType;
    TacticalAIGroup* group;
    TacticalAIGroup* sentinel;
    TacticalAIGroup* prev;

    group = this->groups.next;
    sentinel = &this->groups;
    if (group != sentinel) {
        wanted = type;
        while (1) {
            if (group == 0) {
                break;
            }
            groupType = group->type();
            if (groupType == wanted || wanted == -1) {
                group->prev->next = group->next;
                group->next->prev = group->prev;
                prev = group->prev;
                delete group;
                group = prev;
                this->numberGroupsValue = this->numberGroupsValue - 1;
            }
            group = group->next;
            sentinel = &this->groups;
            if (group == sentinel) {
                break;
            }
        }
    }
    return 1;
}

// ---------------------------------------------------------------------------
// PDB source owner: 00500420_group.cpp
// ---------------------------------------------------------------------------
// 00500420 TribeTacticalAIModule::group(int,int,int,int)
// Source: taitacmd.cpp lines 11331-11342
// Attempt log:
// - Replaced stub with full group-list filter logic and direct member calls.
// - Exact match: keep target/action/type as locals loaded in that order and use
//   explicit top null/bottom sentinel breaks for the list walk.

TacticalAIGroup* TribeTacticalAIModule::group(int id, int type, int action, int target)
{
    TacticalAIGroup* group;
    TacticalAIGroup* sentinel;
    int wantType;
    int wantAction;
    int wantTarget;

    group = this->groups.next;
    sentinel = &this->groups;
    if (group != sentinel) {
        wantTarget = target;
        wantAction = action;
        wantType = type;
        while (1) {
            if (group == 0) {
                break;
            }
            if (id == -1 || group->id() == id) {
                if (wantType == -1 || group->type() == wantType) {
                    if (wantAction == -1 || group->action() == wantAction) {
                        if (wantTarget == -1 || group->target() == wantTarget) {
                            return group;
                        }
                    }
                }
            }
            group = group->next;
            if (group == sentinel) {
                return 0;
            }
        }
    }
    return 0;
}

// ---------------------------------------------------------------------------
// PDB source owner: 005004C0_bestGroup.cpp
// ---------------------------------------------------------------------------
// VA: 005004C0 TribeTacticalAIModule::bestGroup (430 bytes)
// PDB: taitacmd.cpp:11348-11391
//
// Attempt log:
// - Replaced the old decompiler-shaped scaffold (which filtered on desired and
//   actual unit counts) with the packet-proven type/action, assist-group,
//   commander-zone, and gather-distance selection logic.
// - Baseline candidate: natural typed list walk with an explicit sentinel local,
//   the type-106 assist-group scan, and four direct gatherLocation() reads.
// - Split id/assist calls restored the oracle's ordered call multiset but moved
//   the saved-this/point and validity registers; declaration-order and bool/int
//   variants were duplicates or worse, so they were rolled back.
// - Swapping sentinel/best declarations improved late block alignment but left
//   the prologue stack homes wrong and was rolled back.
// - A 12-variant natural lab over initial-local order, assist-loop form, and
//   direct versus split id calls found no exact output. The direct do/break
//   family retained the best clean basin; top-tested variants lost size.
// - Fresh pass: removing the outer sentinel refresh worsened the frame and
//   CFG. Reversing the assist-id equality was the only small metric gain, but
//   it did not change VC5 call order. Point aliases, pointer/reference ABI,
//   declaration splitting, donor constness, and alternate null exits were
//   codegen duplicates or worse.
// - Final clean source: exact size/frame and typed behavior/call set; remaining
//   drift is the assist id/validity call-order and early local-home/register
//   basin. No canonical layout or behavioral uncertainty remains.
// - Tried the natural id-first equality spelling; VC5 kept the call-site order
//   mismatch and moved one byte farther from the oracle, so the assist-first
//   clean form remains selected.
// - Tried a natural outer while sentinel walk in place of the if/do form; it
//   improved shape but worsened positional drift from 350 to 372 bytes and did
//   not change the first local-home hunk or assist call order, so it was rolled
//   back.


TacticalAIGroup* TribeTacticalAIModule::bestGroup(
    int type, int action, int maxDistance, XYPoint& point, int zone)
{
    TacticalAIGroup* group;
    TacticalAIGroup* best;
    int bestDistance;
    TacticalAIGroup* sentinel;

    group = this->groups.next;
    best = 0;
    bestDistance = -1;

    if (group != &this->groups) {
        sentinel = &this->groups;
        do {
            if (group == 0)
                return best;

            if ((type == -1 || group->type() == type) &&
                (action == -1 || group->action() == action)) {
                if (type == 0x6A) {
                    int valid = 1;
                    TacticalAIGroup* assist = this->groups.next;

                    if (assist != sentinel) {
                        do {
                            if (assist == 0)
                                break;
                            if (!valid)
                                goto next_group;
                            if (assist->assistGroupID() == group->id())
                                valid = 0;
                            assist = assist->next;
                            sentinel = &this->groups;
                        } while (assist != sentinel);
                    }

                    if (!valid)
                        goto next_group;
                }

                if (zone != -1) {
                    RGE_Static_Object* object =
                        this->md->object(group->commander());
                    if (object == 0 || object->currentZone() != zone)
                        goto next_group;
                }

                int distanceSquared =
                    (point.y - (int)group->gatherLocation().y) *
                    (point.y - (int)group->gatherLocation().y) +
                    (point.x - (int)group->gatherLocation().x) *
                    (point.x - (int)group->gatherLocation().x);
                int distance = (int)sqrt((double)distanceSquared);

                if ((distance < maxDistance && bestDistance == -1) ||
                    (maxDistance == -1 || distance < bestDistance)) {
                    best = group;
                    bestDistance = distance;
                }
            }

        next_group:
            group = group->next;
            sentinel = &this->groups;
        } while (group != sentinel);
    }

    return best;
}

// Session audit:
// - PDB sibling selection identifies 005004C0 as the first unowned normal
//   tactical-AI sibling after 00500670 in source order. Its owner is the
//   qualified TribeTacticalAIModule::bestGroup symbol and its boundary is
//   005004C0-0050066D.
// - The clean source preserves the sentinel walk, type/action/id/null checks,
//   ordered direct calls, candidate return, and fault order.
// - The exact-size clean reconstruction remains nonexact at 339 differing
//   bytes. The first ordered call gap is id versus assistGroupID evaluation.
// - Tested id-first temporaries, direct and sentinel guards, loop forms,
//   declaration order, point aliases, and label forms. None produced an exact
//   result. The current source is restored to the pinned clean form.

// ---------------------------------------------------------------------------
// PDB source owner: 00500670_readyAndIdleGroup.cpp
// ---------------------------------------------------------------------------
// 00500670 TribeTacticalAIModule::readyAndIdleGroup
// Source: taitacmd.cpp lines 11397-11422
// Attempt log:
// - Replaced the parked raw-pointer scaffold with the packet-supported typed
//   group walk: desired/actual, isGathered/allUnitsIdle gates, four gathered
//   location reads, integer distance, and best-group update.
// - Explicit top-null/bottom-sentinel control flow plus separate
//   desired-before-number assignments restored the original ordered call set
//   and exact size, but the remaining EBX/EBP/EDI register and local-home
//   rotation stayed 68 bytes from the oracle. Reusing the decompiler's one
//   value local for type and desired, and a target alias, were codegen-neutral.
// - Left in scratch: behavior, calls, frame, and boundary are understood; the
//   unresolved basin is prologue/local-home/register coloring.
// Current session probes: named the groups sentinel (both initialization
// orders), swapped the commutative x/y distance terms, and nested the final
// distance guards; sentinel/term forms duplicated the 68-byte basin and the
// nested guards regressed to 296 bytes before restoration. A proven
// TacticalAIModule base likewise duplicated the basin.
// - This session's 18-variant local declaration/predicate lab produced two
//   size/frame/call-set-preserving codegen groups, neither closer than 68
//   bytes; register-qualified point/type parameters and a full self alias
//   were also codegen duplicates.
// - Restored the period math-header surface and the generated polymorphic
//   AIModule/TacticalAIModule/TribeTacticalAIModule and TacticalAIGroup
//   destructor ownership. These canonical source corrections emit the same
//   317-byte function and preserve the proven +0xF0/+0x9D4 offsets.
// Current bounded pass: behavior, calls, frame, boundary, and typed ownership
// are stable; remaining drift is the first prologue/local-home/register basin
// (68 bytes, 21.4511%).
// - Current TU pass: a natural do-while list form added four bytes and a
//   branch, then was restored. A typed self alias combined with direct type
//   filtering and ordered desired/number locals was codegen-duplicate. The
//   dossier and same-TU donors add no new ownership or ABI fact, so the clean
//   source remains authoritative.
// - This pass tested direct and separate filter locals, declaration order,
//   register-qualified parameters, point aliases, guard nesting, and class
//   surface variants. These forms stayed in the 68-byte basin.
// - A volatile best-distance diagnostic reached 52 bytes but remains an
//   unsupported metric-only form. A 32-sample ambient declaration sweep found
//   one codegen group. No natural exact source emerged.
// - A simpler direct type predicate with one block-local desired value and a
//   direct numberUnits call preserves the typed scan and lowers drift to 30
//   bytes. The remaining mismatch is local-home rotation and one deferred type
//   load; declaration, sentinel, and initializer variants duplicate this basin.
// - Revisit probe: a natural sentinel local used for both list-end comparisons
//   was codegen-neutral. The pinned direct-predicate source remains the clean
//   reconstruction; no policy-valid exact source emerged.
// - Fresh pass recovered the original best-distance branch association:
//   `(underLimit && unset) || better`. It is equivalent because every stored
//   best distance is under the limit. This reduced the residual from 30 to 17
//   bytes and made the complete distance-update tail exact. Declaration and
//   initialization reorders were duplicate or worse.
// ACCEPTED DRIFT: The 17 remaining bytes swap the private self and best-group
// stack homes and move the stack-parameter type load across the null-group
// check. Values, calls, used flags, branches, memory effects, FPU operations,
// returns, and fault behavior match. No local address escapes.


TacticalAIGroup* TribeTacticalAIModule::readyAndIdleGroup(
    int type, int maxDistance, XYPoint& point)
{
    int bestDistance;
    TacticalAIGroup* group;
    TacticalAIGroup* bestGroup;

    group = this->groups.next;
    bestGroup = 0;
    bestDistance = -1;

    if (group != &this->groups) {
        while (1) {
            if (group == 0) {
                return bestGroup;
            }

            if (type == -1 || group->type() == type) {
                int desired = group->desiredNumberUnits();
                if (desired <= group->numberUnits() &&
                    group->isGathered(this, this->md) != 0 &&
                    group->allUnitsIdle(this->md, 1) != 0) {
                    int distanceSquared =
                        (point.y - (int)group->gatherLocation().y) *
                        (point.y - (int)group->gatherLocation().y) +
                        (point.x - (int)group->gatherLocation().x) *
                        (point.x - (int)group->gatherLocation().x);
                    int distance = (int)sqrt((double)distanceSquared);

                    if ((distance < maxDistance && bestDistance == -1) ||
                        distance < bestDistance) {
                        bestGroup = group;
                        bestDistance = distance;
                    }
                }
            }

            group = group->next;
            if (group == &this->groups) {
                break;
            }
        }
    }
    return bestGroup;
}

// ---------------------------------------------------------------------------
// PDB source owner: 005007B0_addToGroup.cpp
// ---------------------------------------------------------------------------
int TribeTacticalAIModule::addToGroup(int groupId, int unitId) {
    TacticalAIGroup* grp = group(unitId, -1, -1, -1);
    if (!grp)
        return 0;
    return grp->addUnit(groupId, this->md);
}

// ---------------------------------------------------------------------------
// PDB source owner: 005007F0_removeFromGroup.cpp
// ---------------------------------------------------------------------------
// 005007F0 removeFromGroup: first pass follows the PDB shape directly.
// Likely mismatch axis, if any, is call ordering or the local temp/register basin.

int TribeTacticalAIModule::removeFromGroup(int param_1, int param_2) {
    TacticalAIGroup* group = this->group(param_2, -1, -1, -1);
    if (group == 0) {
        return 0;
    }

    int result = group->removeUnit(param_1, this->md);
    if (group->numberUnits() == 0) {
        this->removeGroup(param_2);
    }

    return result;
}

// ---------------------------------------------------------------------------
// PDB source owner: 00500850_removeFromGroup.cpp
// ---------------------------------------------------------------------------
int TribeTacticalAIModule::removeFromGroup(int unit) {
    TacticalAIGroup* group;
    int result;

    group = this->groupUnitIsIn(unit);
    if (group == 0) {
        return 0;
    }
    result = group->removeUnit(unit, this->md);
    if (group->numberUnits() == 0) {
        this->removeGroup(group->id());
    }
    return result;
}

// ---------------------------------------------------------------------------
// PDB source owner: 005008A0_groupUnitIsIn.cpp
// ---------------------------------------------------------------------------
// VA: 005008A0 TribeTacticalAIModule::groupUnitIsIn (71B)
// PDB source: taitacmd.cpp lines 11465-11473
// Probe 5: direct `while (group != end)` with an inner null guard.

TacticalAIGroup* TribeTacticalAIModule::groupUnitIsIn(int unit) {
    TacticalAIGroup* group = this->groups.next;
    TacticalAIGroup* end = &this->groups;

    while (group != end) {
        if (group == 0) {
            return 0;
        }
        if (group->containsUnit(unit) == 1) {
            return group;
        }
        group = group->next;
    }

    return 0;
}

// ---------------------------------------------------------------------------
// PDB source owner: 005008F0_numberGroups.cpp
// ---------------------------------------------------------------------------
// attempt 1: sibling-style sentinel/null list walk with the two optional filters and a local count
// exact match landed with the natural filter order and the sentinel/list-node surface using the +4 next field

int TribeTacticalAIModule::numberGroups(int param_1, int param_2) {
    TacticalAIGroup* group = this->groups.next;
    TacticalAIGroup* sentinel = &this->groups;
    int count = 0;

    while (group != sentinel && group != 0) {
        if ((param_1 == -1 || group->type() == param_1) && (param_2 == -1 || group->action() == param_2)) {
            ++count;
        }
        group = group->next;
    }

    return count;
}

// ---------------------------------------------------------------------------
// PDB source owner: 00500950_numberUnitsInGroups.cpp
// ---------------------------------------------------------------------------
int TribeTacticalAIModule::numberUnitsInGroups(int type) {
    int total = 0;
    TacticalAIGroup* end = &this->groups;

    for (TacticalAIGroup* group = this->groups.next; group != end && group != 0; group = group->next) {
        if (type == -1 || group->type() == type) {
            total += group->numberUnits();
        }
    }
    return total;
}

// ---------------------------------------------------------------------------
// PDB source owner: 005009A0_numberItemsToAttack.cpp
// ---------------------------------------------------------------------------
// 005009A0 TribeTacticalAIModule::numberItemsToAttack()
// Source: taitacmd.cpp lines 11507-11509
// Attempt log:
// - Replaced stub with ManagedArray grow-to-one logic and informationAI query.
// - Exact match: the one-element copy loop needs `if (i < 1) { i++; copy
//   [i-1]; } else break;` inside the do-while. Spelling it as `if (i >= 1)
//   break; next = i + 1; copy [i];` makes VC5 choose a different index register
//   and move the limit check to the bottom.

void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* ptr);

int TribeTacticalAIModule::numberItemsToAttack()
{
    int* newValue;
    int i;
    int max;

    if (this->playersToAttack.maximumSizeValue - 1 < 0) {
        newValue = new int[1];
        if (newValue != 0) {
            max = this->playersToAttack.maximumSizeValue;
            i = 0;
            if (0 < max) {
                do {
                    if (i < 1) {
                        i = i + 1;
                        newValue[i - 1] = this->playersToAttack.value[i - 1];
                    }
                    else {
                        break;
                    }
                } while (i < this->playersToAttack.maximumSizeValue);
            }
            delete this->playersToAttack.value;
            this->playersToAttack.value = newValue;
            this->playersToAttack.maximumSizeValue = 1;
        }
    }
    return this->md->informationAI.numberGameIDsOwnedBy(-1, *this->playersToAttack.value);
}

// ---------------------------------------------------------------------------
// PDB source owner: 00500A30_itemToCapture.cpp
// ---------------------------------------------------------------------------
int TribeTacticalAIModule::itemToCapture(void) {
    int targetId;

    if (((TribeStrategyAIModule*)((char*)this->md + 0x10E74))->currentVictoryCondition() == 0) {
        targetId = ((TribeStrategyAIModule*)((char*)this->md + 0x10E74))->targetID();
        if (this->group(-1, -1, -1, targetId) == 0) {
            return targetId;
        }
    }
    return -1;
}

// ---------------------------------------------------------------------------
// PDB source owner: 00500A80_itemToBringToArea.cpp
// ---------------------------------------------------------------------------
int TribeTacticalAIModule::itemToBringToArea()
{
    int target;

    if (((TribeStrategyAIModule*)((char*)this->md + 0x10E74))->currentVictoryCondition() == 4) {
        target = ((TribeStrategyAIModule*)((char*)this->md + 0x10E74))->secondTargetID();
        if (this->group(-1, -1, -1, target) == 0)
            return target;
    }
    return -1;
}

// ---------------------------------------------------------------------------
// PDB source owner: 00500AD0_numberItemsToDefend.cpp
// ---------------------------------------------------------------------------
// 00500AD0 TribeTacticalAIModule::numberItemsToDefend
// Observed body remains unresolved. This source keeps the owner callable.

int TribeTacticalAIModule::numberItemsToDefend()
{
    return 0;
}

// ---------------------------------------------------------------------------
// PDB source owner: 00500AF0_attackLimiterTime.cpp
// ---------------------------------------------------------------------------
// TribeTacticalAIModule::attackLimiterTime
// VA: 00500AF0
// taitacmd.cpp:11549-11562
// MATCH: 0.0000% diff, 0 relocations masked


unsigned long TribeTacticalAIModule::attackLimiterTime(int param_1) {
    if (*(int*)((char*)this + 0x2B0) == 1) {
        int val = this->randomizedAttackSeparationTime;
        int limit = *(int*)((char*)this + 0x254);
        if (val < limit) {
            return val;
        }
        return limit;
    } else {
        if (param_1 == 0x2E) {
            return this->randomizedAttackSeparationTime;
        }
        return *(int*)((char*)this + 0x254);
    }
}

// ---------------------------------------------------------------------------
// PDB source owner: 00500B30_resetAttackSeparationTime.cpp
// ---------------------------------------------------------------------------
// VA: 00500B30 TribeTacticalAIModule::resetAttackSeparationTime()
// PDB source: taitacmd.cpp lines 11567-11583 (99 bytes, 32 asm lines)
// Default flags
// Exact match.
// Attempts:
// - Natural local `int sep = sn[0x66]` with split arithmetic was behaviorally correct, but VC5 kept sep in EDI
//   from the initial load (`mov edi,[esi+32C]; test edi,edi`) instead of original `mov eax,...; test eax,eax;`
//   then delayed `mov edi,eax` until immediately before the debug_rand call.
// - Splitting remainder/half/base locals did not change the early EDI allocation and also reordered the base/half
//   arithmetic around `ecx` differently.
// - Testing the member directly then assigning sep inside the true arm still collapsed to the same EDI-local family.
// - Volatile sn improved the later half/base arithmetic but still forced early EDI and shifted the branch target.
// - /Ob0 and /Og did not affect this register-allocation family; no custom flags are needed.
// - Winning shape: do not name `sep`; use direct member rereads in the expression. VC5 still saves the tested EAX
//   into EDI just before the call, but avoids making the variable a long-lived EDI local from the first load.

extern int __cdecl debug_rand(char* file, int line);

void TribeTacticalAIModule::resetAttackSeparationTime() {
    if (this->sn[0x66] > 0) {
        this->randomizedAttackSeparationTime =
            debug_rand((char*)"C:\\msdev\\work\\age1_x1\\taitacmd.cpp", 0x2D35) % this->sn[0x66] +
            (this->sn[0x2E] - this->sn[0x66] / 2);
    } else {
        this->randomizedAttackSeparationTime = this->sn[0x2E];
    }

    if (this->randomizedAttackSeparationTime < 0) {
        this->randomizedAttackSeparationTime = 0;
    }
}

// ---------------------------------------------------------------------------
// PDB source owner: 00500BA0_setGatherLocation.cpp
// ---------------------------------------------------------------------------
// VA: 00500BA0, TribeTacticalAIModule::setGatherLocation, 287 bytes
// Source: taitacmd.cpp lines 11588-11623
// Status: EXACT candidate Ã¢â‚¬â€? natural typed reconstruction; promotion pending.
//
// Attempt log:
// - Prior scaffold used a cached group type, a separate object2 helper, a
//   wrong desiredNumberUnits(int) declaration, and placed the default call
//   outside the target-success/failure split. Those forms changed call
//   identity/count and the target-null behavior.
// - Mirrored the exact same-TU setAllGroupLocations donor for the overload,
//   repeated type checks, informationAI ownership, and local source shape.
// - The target-null path is an early return; findGatherPosition failure uses
//   the ordinary object coordinates before the common return.
// - Probes 2Ã¢â‚¬â€œ5 (recorded in session history): self alias, split declarations,
//   reversed result predicate, and register-qualified group were respectively
//   neutral, neutral, block-shape-worse, and neutral; all were rolled back.
// - The successful findGatherPosition arm returns immediately; leaving the
//   default setGatherLocation call as fall-through reproduces the exact
//   compiler tail merge and the original register ownership.
// - Main-agent audit restored canonical object and AI-module destructor
//   ownership; emitted code remains exact.
// FLAGS: /nologo /c /O2 /Oy


int TribeTacticalAIModule::setGatherLocation(TacticalAIGroup* group)
{
    int cmdr = group->commander();
    RGE_Static_Object* obj = this->md->object(cmdr);
    if (obj == 0)
        return 0;

    int flag;
    if (group->type() == 100) {
        flag = 1;
    }
    else {
        if (group->type() == 101) {
            flag = 1;
        }
        else {
            int gtype = group->type();
            flag = 0;
            if (gtype == 102)
                flag = 1;
        }
    }

    RGE_Static_Object* target = this->md->object(
        -1, 0x6D, -1, -1, -1, -1, -1, -1, -1, -1);
    if (target == 0)
        return 0;

    XYPoint centerPoint;
    XYPoint gatherPoint;
    centerPoint.x = (int)target->world_x;
    centerPoint.y = (int)target->world_y;

    int result = this->md->informationAI.findGatherPosition(
        centerPoint, group->desiredNumberUnits(), flag,
        this->strategicNumbers[0x16], this->strategicNumbers[0x48], obj, gatherPoint);
    if (result == 1) {
        group->setGatherLocation((float)gatherPoint.x,
                                 (float)gatherPoint.y, obj->world_z);
        return 1;
    }
    group->setGatherLocation(obj->world_x, obj->world_y, obj->world_z);
    return 1;
}

// ---------------------------------------------------------------------------
// PDB source owner: 00500CC0_setAllGroupLocations.cpp
// ---------------------------------------------------------------------------
// VA: 00500CC0, TribeTacticalAIModule::setAllGroupLocations, 277 bytes
// Source: taitacmd.cpp lines 11628-11664
// Status: EXACT candidate Ã¢â‚¬â€? clean typed reconstruction; final validation and
// promotion are pending.
//
// Attempt log:
// - Prior scaffold used a cached group type, an object2 helper, a wrong
//   desiredNumberUnits(int) declaration, and omitted the flag argument from
//   findGatherPosition. Those forms changed call identity/count and are not a
//   canonical source model.
// - Corrected the overload/ABI surface: MainDecisionAIModule::object is
//   overloaded, desiredNumberUnits has no argument, and
//   findGatherPosition takes XYPoint references plus the flag argument.
// - Canonicalized md as TribeMainDecisionAIModule with its named
//   informationAI subobject at +0xCEC; this preserves the exact call bytes.
// - The third type result is named before the default flag store; this is a
//   plausible local reuse that preserves the original call-before-store order.
// - Exact emitted match reached at 277 bytes with default VC5 /O2 /Oy.
// - Main-agent audit restored canonical object and AI-module destructor
//   ownership; emitted code remains exact.
// FLAGS: /nologo /c /O2 /Oy


int TribeTacticalAIModule::setAllGroupLocations(TacticalAIGroup* group)
{
    int cmdr = group->commander();
    RGE_Static_Object* obj = this->md->object(cmdr);
    if (obj == 0)
        return 0;

    int flag;
    if (group->type() == 100) {
        flag = 1;
    }
    else {
        if (group->type() == 101) {
            flag = 1;
        }
        else {
            int gtype = group->type();
            flag = 0;
            if (gtype == 102)
                flag = 1;
        }
    }

    RGE_Static_Object* target = this->md->object(-1, 0x6D, -1, -1, -1, -1, -1, -1, -1, -1);
    if (target != 0) {
        XYPoint centerPoint;
        XYPoint gatherPoint;
        centerPoint.x = (int)target->world_x;
        centerPoint.y = (int)target->world_y;

        int result = this->md->informationAI.findGatherPosition(
            centerPoint, group->desiredNumberUnits(), flag,
            this->strategicNumbers[0x16], this->strategicNumbers[0x48], obj, gatherPoint);
        if (result == 1) {
            group->setAllLocations((float)gatherPoint.x,
                                   (float)gatherPoint.y, obj->world_z);
            return 1;
        }
    }

    group->setAllLocations(obj->world_x, obj->world_y, obj->world_z);
    return 1;
}

// ---------------------------------------------------------------------------
// PDB source owner: 00500DE0_setGroupInfluences.cpp
// ---------------------------------------------------------------------------
// 00500DE0 TribeTacticalAIModule::setGroupInfluences
// taitacmd.cpp
// Attempt log:
// baseline: canonical group sentinel/object-id array ownership; typed group and object influence passes with natural repeated gather and map calls.
// probe 2: replaced InfluenceHelper/malloc scaffolding with the proven
//   TribeInformationAIModule::groupInfluenceDimension/mapBound, InfluenceMap,
//   and inlined ManagedArray<int> surfaces; size, calls, and CFG now match.
// probe 3: used the binary-supported XYPoint aggregate locals rather than four
//   untyped integer array elements; this was codegen-neutral.
// probe 4: reusing one point across both object-bound calls enlarged the frame
//   and reversed the block basin; rolled back.
// probe 6: swapping the two point roles globally moved the group hunk and
//   enlarged the localized drift; rolled back.
// probe 8: swapped only the two equal-coordinate object point roles; this
//   reduced the localized drift from 23 to 13 bytes and was retained.
// probe 9: propagating the object-role swap into the later clear-distance
//   rectangle moved the group block; rolled back.
// probe 11: kept group distance live only through the first map update and used
//   a separate object-clear-distance local; this reduced drift to 11 bytes and
//   moved the FPU conversion onto the original parameter home.
// probe 12: swapping clear-rectangle roles while retaining the separate
//   distance local moved the group block; rolled back.
// probe 14 variant lab: tested do/for group loops crossed with both clear-point
//   role orders under size/frame/call-set gates.  The retained do/minmax source
//   was best at 11 bytes; for changed size and role swap regressed to 41 bytes.
// probe 33: replaced the do-loop with a natural while loop and an in-body null
//   break; this matched the original null-check back edge and reduced drift to 10.
// probe 34: swapped clear-point roles with the improved loop; drift regressed to
//   40 bytes and disturbed the exact group block, so it was rolled back.
// probe 36: separate clearMinpt/clearMaxpt aggregates enlarged the frame to
//   0x20 and reached 75 bytes; rolled back.
// probes 38/40: pointer and reference aliases for swapped clear roles kept the
//   frame but disturbed the exact group block at 40 bytes; rolled back.
// probe 42: hoisted objectClearDistance declaration was codegen-duplicate at
//   10 bytes; rolled back.
// probe 44: reusing clearDistance moved the conversion home and regressed to
//   12 bytes; rolled back.
// probe 46 variant lab: natural/reversed-term forms stayed at 10 bytes,
//   y-first reached 14, and swapped roles reached 40; no exact variant.
// probe 47: swapped clear roles with hoisted distance declaration duplicated
//   the 40-byte basin; rolled back.
// probe 49: declaration initialization was codegen-duplicate at 10 bytes.
// probes 50/52: Ghidra-natural min-then-max object ownership reached 20 bytes
//   with a separate distance and 22 bytes when reusing clearDistance; rolled back.
// probe 66: matched the PDB's separate group/object min/max scopes and its
//   shadowed clearDistance locals.  The object scope uses min first, which
//   restores the target clear-distance point homes and reaches an exact match.
// Exact candidate: 932/932 bytes, 43/43 calls, 0x14 frame, default flags.


void* operator_new(unsigned int size);
void __cdecl operator_delete(void* ptr);

void TribeTacticalAIModule::setGroupInfluences(InfluenceMap& map)
{
    int half;
    TacticalAIGroup* group;
    TacticalAIGroup* end;
    RGE_Static_Object* object;
    int i;

    group = this->groups.next;
    end = &this->groups;
    if (group != end) {
        int clearDistance;
        XYPoint minpt;
        XYPoint maxpt;
        while (group != end) {
            if (group == 0)
                break;
            if (group->gatherLocation().x != -1.0f) {
                clearDistance = this->md->informationAI.groupInfluenceDimension(
                    group->desiredNumberUnits());
                half = clearDistance / 2;

                minpt.x = (int)(group->gatherLocation().x - (float)half);
                minpt.y = (int)(group->gatherLocation().y - (float)half);
                this->md->informationAI.mapBound(&minpt);
                maxpt.x = (int)(group->gatherLocation().x + (float)half);
                maxpt.y = (int)(group->gatherLocation().y + (float)half);
                this->md->informationAI.mapBound(&maxpt);
                map.setValue(minpt.x, minpt.y, maxpt.x, maxpt.y, 255);

                half = clearDistance;
                minpt.x = (int)(group->gatherLocation().x - (float)half);
                minpt.y = (int)(group->gatherLocation().y - (float)half);
                this->md->informationAI.mapBound(&minpt);
                maxpt.x = (int)(group->gatherLocation().x + (float)half);
                maxpt.y = (int)(group->gatherLocation().y + (float)half);
                this->md->informationAI.mapBound(&maxpt);
                map.decrementValue(minpt.x, minpt.y, maxpt.x, maxpt.y, 10);
            }
            group = group->next;
        }
    }

    i = 0;
    if (this->ungroupedSoldiers.numberValue > 0) {
        XYPoint minpt;
        XYPoint maxpt;
        do {
            object = this->md->object(this->ungroupedSoldiers[i]);
            if (object != 0) {
                minpt.x = (int)object->world_x;
                minpt.y = (int)object->world_y;
                this->md->informationAI.mapBound(&minpt);
                maxpt.x = (int)object->world_x;
                maxpt.y = (int)object->world_y;
                this->md->informationAI.mapBound(&maxpt);
                map.setValue(minpt.x, minpt.y, maxpt.x, maxpt.y, 255);

                int clearDistance;
                clearDistance = this->md->informationAI.groupInfluenceDimension(1);
                minpt.x = (int)(object->world_x - (float)clearDistance);
                minpt.y = (int)(object->world_y - (float)clearDistance);
                this->md->informationAI.mapBound(&minpt);
                maxpt.x = (int)((float)clearDistance + object->world_x);
                maxpt.y = (int)((float)clearDistance + object->world_y);
                this->md->informationAI.mapBound(&maxpt);
                map.decrementValue(minpt.x, minpt.y, maxpt.x, maxpt.y, 10);
            }
            i++;
        } while (i < this->ungroupedSoldiers.numberValue);
    }
}

// ---------------------------------------------------------------------------
// PDB source owner: 00501190_selectBestCommander.cpp
// ---------------------------------------------------------------------------
// 00501190 TribeTacticalAIModule::selectBestCommander(TacticalAIGroup*)
// Source: taitacmd.cpp lines 11755-11801
// Attempt log:
// - Replaced stub with full best-commander scan and score comparison logic.
// - Exact match: keep `self` and `bestUnit` as explicit locals, and model the
//   object vfunc at vtable +0x10C as a float-returning virtual method.





int TribeTacticalAIModule::selectBestCommander(TacticalAIGroup* group)
{
    TribeTacticalAIModule* self;
    int bestUnit;
    int bestScore;
    int i;
    int score;
    RGE_Static_Object* obj;
    int mode;

    self = this;
    bestScore = -1;
    bestUnit = -1;
    i = 0;
    if (group->numberUnits() > 0) {
        do {
            obj = self->md->object(group->unit(i));
            if (obj != 0) {
                if (obj->master_obj->id != 0x7D) {
                    if (*(int*)((char*)self + 0x2C0) == 2) {
                        score = (int)obj->weaponRange();
                    }
                    else {
                        score = (int)*(float*)((char*)obj + 0x30);
                    }
                    mode = *(int*)((char*)self + 0x2C0);
                    if (mode == 1 || mode == 3) {
                        if (bestScore == -1 || score < bestScore) {
                            bestUnit = group->unit(i);
                            bestScore = score;
                        }
                    }
                    else {
                        if (bestScore == -1 || score > bestScore) {
                            bestUnit = group->unit(i);
                            bestScore = score;
                        }
                    }
                }
            }
            i = i + 1;
        } while (i < group->numberUnits());
    }
    return bestUnit;
}

// ---------------------------------------------------------------------------
// PDB source owner: 00501260_selectBestCommander.cpp
// ---------------------------------------------------------------------------
// 00501260 TribeTacticalAIModule::selectBestCommander
// Attempt log:
// 1: Reconstruct from packet with helper: too small due outlined helper.
// 2: Inline ManagedArray operator[] growth at all use sites.
// 3: Fix md at +f0, virtual slot +0x10c, and avoid direct early return: improved to 10.58% positional / 6.26% edit, first mismatch offset 3.
// 4: Tried /Ob0: no codegen change; removed flag.
// 5: Tried /O1: too-small 449-byte text; removed flag.
// 6: Tried /Od: broad 92.66% mismatch from first byte; removed flag.
// 7: Hoisted score local declaration to function scope: worsened first mismatch; rolled back.
// 8: Reordered bestUnit/bestScore/i locals and probed result-initialized-to-minus-one form: best current is 1.51% positional/edit, first mismatch offset 10 from swapped `xor edi` / `or ebp,-1` and local home order.
// BLOCKER: behavior and main body are close, but prologue/control topology differs. Original delays `push ebx` until after the empty-array check and uses the pre-EBX local slots (`result=-1`, `i=0`, saved this) exactly; current VC5 saves EBX immediately because the inlined array-growth blocks use EBX, causing stack-offset drift from offset 3 despite matching most loop bodies.
// 4: Initialize selected unit to -1 and return it directly: improved to 1.08%; remaining store order and score-conversion jump.
// 5: Reorder locals and make weaponRange return float with named fscore worsened (extra stack/FPU drift); keep float return but use direct conditional conversion.
// 6: Restore exact local order/value: bestScore=-1, bestUnit=-1, i=0; direct return bestUnit. Validates exact before promotion.

extern void* operator new(unsigned int);
extern void operator delete(void*);
extern "C" int __cdecl _ftol();


int TribeTacticalAIModule::selectBestCommander(ManagedArray_int& a)
{
    int bestScore = -1;
    int bestUnit = -1;
    int i = 0;
    if (a.numberValue > 0) {
    do {
        if (i > a.maximumSizeValue - 1) {
            int newMax = i + 1;
            int* n = (int*)operator new(newMax * 4);
            if (n) {
                int j = 0;
                while (j < a.maximumSizeValue && j < newMax) { n[j] = a.value[j]; ++j; }
                operator delete(a.value); a.value = n; a.maximumSizeValue = newMax;
            }
        }
        int id = a.value[i];
        RGE_Static_Object* obj = this->md->object(id);
        if (obj != 0) {
            if (obj->master_obj->id != 0x7d) {
                int score;
                if (this->sn[0x4b] == 2) {
                    score = (int)obj->weaponRange();
                } else {
                    score = (int)obj->hp;
                }
                if (this->sn[0x4b] == 1 || this->sn[0x4b] == 3) {
                    if (bestScore == -1 || score < bestScore) {
                        if (i > a.maximumSizeValue - 1) {
                            int newMax = i + 1;
                            int* n = (int*)operator new(newMax * 4);
                            if (n) { int j = 0; while (j < a.maximumSizeValue && j < newMax) { n[j] = a.value[j]; ++j; } operator delete(a.value); a.value = n; a.maximumSizeValue = newMax; }
                        }
                        bestUnit = a.value[i];
                        bestScore = score;
                    }
                } else {
                    if (bestScore == -1 || score > bestScore) {
                        if (i > a.maximumSizeValue - 1) {
                            int newMax = i + 1;
                            int* n = (int*)operator new(newMax * 4);
                            if (n) { int j = 0; while (j < a.maximumSizeValue && j < newMax) { n[j] = a.value[j]; ++j; } operator delete(a.value); a.value = n; a.maximumSizeValue = newMax; }
                        }
                        bestUnit = a.value[i];
                        bestScore = score;
                    }
                }
            }
        }
        ++i;
    } while (i < a.numberValue);
    }
    return bestUnit;
}

// ---------------------------------------------------------------------------
// PDB source owner: 00501430_dealWithGAIAAttacker.cpp
// ---------------------------------------------------------------------------
// VA: 00501430 TribeTacticalAIModule::dealWithGAIAAttacker (424 B)
// PDB source: taitacmd.cpp:11854-11938
// __thiscall
//
// Attempt log:
// - Replaced the raw-offset scaffold with the period typed ownership model:
//   param_1 is the attacker, param_2 is the GAIA target, civilianExplorers is
//   the +0x104 ManagedArray, md is the +0xF0 decision module, and sn[0x64]
//   is the +0x324 response limit. The natural source uses civilian(), the
//   weaponRange()/canPath() pair, and taskAttacker(). Baseline: 435 bytes;
//   the do/while scan added a redundant first capacity test.
// - Hoisting target->id was codegen-neutral with the first scan shape.
// - Replaced the scan with the exact same-TU bounded for-loop idiom: 424
//   bytes, with only sn displaced by the incomplete class layout.
// - Restored the ten task-list array region before sn at +0x194; this fixed
//   sn[0x64] at +0x324 and reached MATCH. Direct target->id in the for loop
//   was tested and worsened codegen; the hoisted local is retained.

int TribeTacticalAIModule::dealWithGAIAAttacker(
    RGE_Static_Object* attacker, RGE_Static_Object* target)
{
    int count;
    int unitID;
    RGE_Static_Object* unitObject;
    XYPoint vPosition;
    XYZPoint point;

    if (attacker == 0 || target == 0)
        return 0;

    int targetID = target->id;
    int i;
    for (i = 0; i < this->civilianExplorers.numberValue; i++) {
        if (i >= this->civilianExplorers.maximumSizeValue)
            break;
        if (this->civilianExplorers.value[i] == targetID)
            return 0;
    }

    count = 0;
    vPosition.x = (int)target->world_x;
    vPosition.y = (int)target->world_y;
    unitID = this->civilian(vPosition, 1, 700, 0x2C9, 0x2C9, 1);
    while (unitID != -1 && count < this->sn[0x64] &&
           (unitObject = this->md->object(unitID)) != 0) {
        point.x = (int)attacker->world_x;
        point.y = (int)attacker->world_y;
        point.z = (int)attacker->world_z;
        if (unitObject->canPath(
                point, unitObject->weaponRange(), attacker->id,
                0, 1, -1, -1) == 0)
            break;

        this->taskAttacker(unitID, attacker->world_x, attacker->world_y,
                           attacker->id, (int)attacker->owner->id,
                           0, 0, -1, 0);
        count++;
        unitID = this->civilian(vPosition, 1, 700, 0x2C9, 0x2C9, 1);
    }

    return count > 0;
}

// ---------------------------------------------------------------------------
// PDB source owner: 005015E0_addWaypoint.cpp
// ---------------------------------------------------------------------------


void TribeTacticalAIModule::addWaypoint(int id, unsigned char a, unsigned char b) {
    XYZBYTEPoint info;

    info.x = a;
    info.y = b;
    info.z = 1;
    this->md->player->sendAddWaypointCommand(id, &info, 1);
}

// ---------------------------------------------------------------------------
// PDB source owner: 00501620_importantGroupLeader.cpp
// ---------------------------------------------------------------------------
int TribeTacticalAIModule::importantGroupLeader(int param) {
    RGE_Static_Object* object = this->md->object(param);
    if (object == 0) {
        return 0;
    }
    short group = object->master_obj->object_group;
    if ((group != 0x12) && (group != 0x0D)) {
        return 0;
    }
    return 1;
}

// ---------------------------------------------------------------------------
// PDB source owner: 00501660_enableAttack.cpp
// ---------------------------------------------------------------------------
void TribeTacticalAIModule::enableAttack(int param) {
    if (this->attackEnabledValue == 1)
        return;
    int field3AC = *(int*)((char*)this + 0x3AC);
    if (field3AC != 0 && field3AC != param)
        return;
    this->attackEnabledValue = 1;
}

// ---------------------------------------------------------------------------
// PDB source owner: 00501690_unexploredArea.cpp
// ---------------------------------------------------------------------------
// 00501690 TribeTacticalAIModule::unexploredArea
// Attempt log:
// 1: natural implementation from packet/decompiler, with typed member calls and switch offsets: compile failed due bad field_40 gap.
// 2: fix RGE_Static_Object layout gap: very close structure, first 117 bytes exact; 9.63% edit diff, mostly one-byte branch shifts and tail comparison/return drift.
// 3: change final bestDistance test to == -1.0f with fallback first: worsened edit diff to 22.8%; rolled back.
// 4: restore success-first final branch.
// 5: add 4-byte pad before informationAI so member calls use md+0xCEC instead of md+0xCE8: improved edit diff to 7.31%.
// 6: add field at object+0x44 and pass field_40 to distance_to_position: no change; realized original [ecx+40] is world_z bits, not a separate int.
// 7: use world_z float as third distance argument: tiny improvement; remaining diff mostly branch-distance/tail layout and compare operand order.
// 8: swap lookupZone comparison operands to try original cmp [esp+13],al: improved compare opcode and edit diff to 6.95%.
// 9: reorder distance_to_position signature to x,y,self,z to match original push z; push self; then x/y FPU stores: improved edit diff to 6.77%.
// 10: remaining best version has first 117 bytes exact and correct calls/switch/stack frame; remaining nonzero bytes are branch displacement shifts and small tail scheduling differences from a 1-byte shorter loop/final section, with no known behavior delta. Proposed accepted_drift for review rather than promoting exact.
// Current worker probes:
// - Corrected distance_to_position to its observed three-float member ABI; this reduced the rebuilt drift to 6 bytes and restored the correct call relocation.
// - Modeled the two saved coordinates as a natural XYPoint aggregate; this reproduced the proven adjacent stack homes and yielded MATCH (561/561 bytes).

int TribeTacticalAIModule::unexploredArea(int player, XYPoint& out)
{
    RGE_Static_Object* unit = this->md->object(player);
    if (unit == 0) {
        return 0;
    }
    unsigned char unitZone = unit->currentZone();
    RGE_Static_Object* explorer = this->md->object(-1, 0x6d, -1, -1, -1, -1, -1, -1, -1, -1);
    float bestDistance = -1.0f;
    XYPoint bestPoint = { -1, -1 };
    if (explorer != 0) {
        int i = 0;
        do {
            out.x = (int)explorer->world_x;
            out.y = (int)explorer->world_y;
            switch (i) {
            case 0: out.x -= 10; out.y -= 10; break;
            case 1: out.y -= 10; break;
            case 2: out.x += 10; out.y -= 10; break;
            case 3: out.x += 10; break;
            case 4: out.x += 10; out.y += 10; break;
            case 5: out.y += 10; break;
            case 6: out.x -= 10; out.y += 10; break;
            case 7: out.x -= 10; break;
            }
            if (out.x >= 0 && out.y >= 0 && out.x < this->md->informationAI.mapXSize() && out.y < this->md->informationAI.mapYSize()) {
                if (this->md->informationAI.tileUncovered(out.x, out.y) != 1 && unitZone == unit->lookupZone(out.x, out.y)) {
                    float d = unit->distance_to_position((float)out.x, (float)out.y, unit->world_z);
                    if (bestDistance == -1.0f || d < bestDistance) {
                        bestDistance = d;
                        bestPoint.x = out.x;
                        bestPoint.y = out.y;
                    }
                }
            }
            i++;
        } while (i < 8);
    }
    if (bestDistance != -1.0f) {
        out.x = bestPoint.x;
        out.y = bestPoint.y;
        this->md->informationAI.setTileExplored(bestPoint.x, bestPoint.y);
        return 1;
    }
    return this->md->informationAI.unexploredPlayerLocation(player, &out) != 0;
}

// ---------------------------------------------------------------------------
// PDB source owner: 005018F0_gatherer.cpp
// ---------------------------------------------------------------------------
UnitData* TribeTacticalAIModule::gatherer(int unitId) {
    int i;

    for (i = 0; i < 0x32; i++) {
        if (this->gatherers[i].id == unitId)
            return this->gatherers + i;
    }
    return 0;
}

// ---------------------------------------------------------------------------
// PDB source owner: 00501920_addGatherer.cpp
// ---------------------------------------------------------------------------
// 00501920 TribeTacticalAIModule::addGatherer(int)
// Source: taitacmd.cpp lines 12119-12155
// Attempt log:
// - Replaced stub with full gatherer slot scan/add/duplicate-return logic.
// - Exact match with explicit `goto next` after recording the first free slot,
//   preserving the original duplicate-check fallthrough and return layout.

UnitData* TribeTacticalAIModule::addGatherer(int id)
{
    int index;
    UnitData* item;
    int freeIndex;
    int value;

    if (id == -1) {
        this->logCommonHistory((char*)0x00588AA8);
        return 0;
    }
    freeIndex = -1;
    index = 0;
    item = this->gatherers;
    while (index < 50) {
        value = item->id;
        if (value == -1) {
            if (freeIndex == -1) {
                freeIndex = index;
                goto next;
            }
        }
        if (value == id) {
            return &this->gatherers[index];
        }
next:
        index = index + 1;
        item = item + 1;
    }
    if (freeIndex == -1) {
        return 0;
    }
    this->gatherers[freeIndex].id = id;
    this->gatherers[freeIndex].target = -1;
    this->gatherers[freeIndex].lastTaskTime = 0;
    this->numberGatherersValue = this->numberGatherersValue + 1;
    return &this->gatherers[freeIndex];
}

// ---------------------------------------------------------------------------
// PDB source owner: 005019C0_removeGatherer.cpp
// ---------------------------------------------------------------------------
// VA: 005019C0 removeGatherer (192B)
// taitacmd.cpp
// Attempt log:
// - Baseline was the old incomplete stub; it did not model the gatherer table.
// - Reconstructed the binary-proven UnitData table at +0x51C and the natural
//   remove/compact operation from the matched addGatherer donor.
// - The first natural scan used do/while; VC5 peeled its first record and
//   emitted an extra load/branch family. A bounded while scan restored the
//   original unpeeled pointer walk and matched exactly.

int TribeTacticalAIModule::removeGatherer(int id)
{
    UnitData* pU;
    int* piVar2;
    int i;

    if (id == -1) {
        this->logCommonHistory((char*)0x00588AC8);
        return 0;
    }
    i = 0;
    pU = this->gatherers;
    while (i < 0x32) {
        if (pU->id == id) {
            piVar2 = &this->gatherers[i].data1;
            this->gatherers[i].id = -1;
            *piVar2 = -1;
            this->gatherers[i].data2 = -1;
            this->gatherers[i].data3 = -1;
            this->gatherers[i].target = -1;
            this->numberGatherersValue = this->numberGatherersValue + -1;
            for (; i < 0x31 && piVar2[5] != -1; piVar2 = piVar2 + 6) {
                ((UnitData*)(piVar2 - 1))->id = piVar2[5];
                *piVar2 = piVar2[6];
                piVar2[1] = piVar2[7];
                piVar2[2] = piVar2[8];
                piVar2[3] = piVar2[9];
                piVar2[5] = -1;
                piVar2[6] = -1;
                piVar2[7] = -1;
                piVar2[8] = -1;
                piVar2[9] = -1;
                i = i + 1;
            }
            return 1;
        }
        i = i + 1;
        pU = pU + 1;
    }
    return 0;
}

// ---------------------------------------------------------------------------
// PDB source owner: 00501A80_isGatherer.cpp
// ---------------------------------------------------------------------------
int TribeTacticalAIModule::isGatherer(int unitId) {
    int i;

    for (i = 0; i < 0x32; i++) {
        if (this->gatherers[i].id == unitId)
            return 1;
    }
    return 0;
}

// ---------------------------------------------------------------------------
// PDB source owner: 00501AB0_requiredGatherAmount.cpp
// ---------------------------------------------------------------------------
int TribeTacticalAIModule::requiredGatherAmount(int index) {
    if (this->desiredGathererDistribution[index] == 0) {
        return this->sn[0x94];
    }
    int value = this->neededResources.value(index);
    return value / this->desiredGathererDistribution[index];
}

// ---------------------------------------------------------------------------
// PDB source owner: 00501AF0_trackUnitGather.cpp
// ---------------------------------------------------------------------------
// attempt 1: direct resource-delta check plus gatherer lookup/update in the same order as the asm
// exact match landed once the resource AI was modeled as a real nested subobject and the +0x0d98 delta array was placed correctly

void TribeTacticalAIModule::trackUnitGather(int unit_id, int resource_id, int amount) {
    UnitData* entry;

    if (this->resourceDifferenceValue[resource_id] < 0) {
        if (this->md->resourceAI.resource(resource_id) + this->resourceDifferenceValue[resource_id] > 0) {
            this->updateNeededResources();
        }
    }

    entry = this->gatherer(unit_id);
    if (entry != 0 && entry->data1 == resource_id) {
        entry->data3 += amount;
    }
}

// ---------------------------------------------------------------------------
// PDB source owner: 00501B50_deleteUnit.cpp
// ---------------------------------------------------------------------------
int TribeTacticalAIModule::deleteUnit(int param_1) {
    RGE_Static_Object* object;

    object = this->md->object(param_1);
    if (object != 0) {
        if (this->md->aiPlayer->command_delete_object(object) == 1) {
            return 1;
        }
    }

    return 0;
}

// ---------------------------------------------------------------------------
// PDB source owner: 00501B90_numberAvailableStoragePits.cpp
// ---------------------------------------------------------------------------
// 00501B90 TribeTacticalAIModule::numberAvailableStoragePits
// PDB: taitacmd.cpp:12296-12337, 222 bytes
// __thiscall, int, ret 0Ch (3 params)
// FLAGS: default
//
// Attempt log:
// probe 1: 43.2% - block layout wrong (jne vs je)
// probe 2: 10.4% - layout fixed (if != -1 {main} else {alt})
//   remaining: register encoding only (esi for md, edi for capacity)
// probe 3: 28.4% - explicit md var, worse register allocation
//
// Session 2026-08-02 (sa-6032f135), 7 probes:
// - Canonical ownership established: md(+0xF0) -> RGE_Player(player+0xF0) ->
//   float* attributes(+0x50); capacity = (int)attributes[6] via __ftol (PDB
//   12313). sn is the real strategicNumbers[226] array at +0x194; +0x3EC =
//   sn[0x96], +0x48C = sn[param3+0xBE]. buildAI at md+0x104, resourceAI at
//   md+0x10D7C, informationAI at md+0xCEC (granaries sibling 00501C70 matched
//   with raw-cast md style; that style kept here).
// - Best clean reconstruction (this file, pinned): in-place multiply + named
//   result-first tail -> 12.16% (27 bytes, 3 spans), 222/222, calls 100%,
//   EXACT CODEGEN stage. md->edi, tail sub/store/clamp order correct.
// - Remaining drift is ONE localized VC5 register/scheduling basin:
//   orig keeps capacity in EAX through test/jne/mov/`imul eax,ebx` and saves
//   the product to ESI only right before the call; every rebuilt variant
//   coalesces capacity+product into a callee-saved register (esi or edi) and
//   sinks `imul` after the call. 4 variant-lab rounds (~47 source shapes:
//   in-place vs separate product, operand swap, store-first vs result-first,
//   named vs anonymous ternary, ghidra `((r<0)-1)&r` return, register/const
//   qualifiers, top-declared locals, multiply-in-return, param mutation) +
//   full real class surfaces (TacticalAIModule base + sn[226] + typed md
//   members with real sizes) + risky-flag sweep all collapse into the same
//   two basins; no third basin reaches the original. Store-first ternary
//   keeps imul before call but forces md->esi/product->edi plus an extra
//   mov; result-first is clean in the tail but coalesces/sinks.
// - Next lead: none obvious at single-function scope. Sibling 004E3E90
//   (TribeInformationAIModule::numberAvailableStoragePits) is stuck on the
//   same esi/edi register-swap family. A future worker might re-try md typed
//   as the real TribeMainDecisionAIModule (0x125C8) or check whether the
//   original source reused iVar3 for the product with an explicit separate
//   result variable under a slightly different TU include context.
//
// This claim (10 meaningful probes): restoring distinct iVar3/iVar4/uVar5
// roles and reusing iVar3 for the post-call count moved 27 -> 6 bytes and
// restored all block/CFG parity. Direct md use, declaration reordering,
// register qualifiers on md/product/result, signed result storage, and the
// explicit md-local form all emitted the same 6-byte register-swapped basin.
// Initializing uVar5 with the product then compound-subtracting the call
// result regressed to the 27-byte capacity-coalesced basin and was rolled back.
// Final blocker: original uses EDI for md and ESI for the pre-call product;
// this canonical source emits the same roles swapped (6 single-byte register
// encoding differences). Left in scratch for a future TU/context lead.
// Main-agent normalization replaced decompiler local names and raw leading
// gaps with descriptive roles and donor-backed polymorphic ownership; emitted
// code remains the same 6-byte register-encoding mismatch.
// Main-agent audit replaced cross-member raw casts with canonical named
// main-decision submodule ownership.
// Current session probe: a top-level md alias used across both branches
// regressed to a 197-byte structural basin (209 differing bytes); restored.
// Fresh bounded pass (orch-taitacmd-02): derived md typing at size 0x125C8,
// branch-initialized md lifetime, same-TU math.h context, full proven md
// subobject sizes, and a branch-local md reference all emitted the same exact
// 222-byte / six-byte register-swapped basin. A positive-branch BuildAIModule
// pointer alias regressed structurally to 224 bytes / 113 differing bytes and
// was restored. No ABI, call, layout, or behavior uncertainty remains.
// Fresh bounded pass (sa-89b3fb34-r1): declaration-order variants, nested
// md/self aliases, direct storage-count rereads, stdio context, 32-bit long
// local widths, and proper TacticalAIModule/MainDecisionAIModule/AIModule
// virtual-base surfaces all reproduced the same 222-byte six-byte basin.
// Restored the pinned canonical source; no new codegen lead was found.
// Bounded pass (orch2-501B90-live): natural direct this->sn_3EC use in the
// main-path product reproduced the prior six-byte basin with no movement.
// Restored the pinned canonical source; no natural donor-backed liveness lead
// remains without adding a redundant or non-behavioral member use.
// Bounded pass (orch-00501B90-D): re-ran dossier/donors/ABI. search_asm_donors
// on +0053-+0064 found the only same-TU exact donor with the target's exact
// register topology: 004F5FB0 emits `mov edi,[esi+0F0h]` (md->EDI, this stays
// ESI) because its source reads this->sn[0xB0] AFTER the md load
// (`mov eax,[esi+454h]` at 004F60B5). Liveness theory: original keeps this in
// ESI through the md load (md->EDI, reusing param3's dead EDI slot LIFO), and
// kills this only at the product move (+008B, mov esi,eax); the rebuilt kills
// this at the md load itself (destructive mov esi,[esi+0F0h]; product->EDI).
// Next lead: spell the main path so a this-based member is still read after
// the md load (mirroring the donor's liveness) without adding instructions,
// e.g. a source construct that keeps this live to the product point; prior
// probes never tested a main-path this read between +005E and +008B.
// Follow-up 2026-08-12 (follow-501B90-r1): exact 00501D70 nested layout review
// corrected false ownership. TribeBuildAIModule is the typed build subobject;
// TribeInformationAIModule is standalone at +0xCEC and TribeResourceAIModule
// follows at +0x10D7C. Tactical strategicNumbers[226] owns +0x3EC and +0x48C.
//
// Probe 1 baseline: current six-byte register basin with the old narrow
// declarations. Probe 2: full AIModule/TribeMainDecision nested layout moved
// resourceAI incorrectly because informationAI was falsely derived. Probe 3:
// standalone informationAI restored the six-byte basin. Probe 4: a branch-local
// typed decision pointer duplicated it. Probe 5: named strategicNumbers[226]
// ownership duplicated it. Probe 6: direct post-gate strategic count duplicated
// it. Probe 7: branch-local tactical reference duplicated it. Probe 8: literal
// result locals regressed to the known 27-byte basin and was rolled back.
//
// Current canonical source is the typed nested layout with named strategic
// numbers. It is natural and behaviorally complete. Remaining drift is six
// register-encoding bytes: original md is EDI and the product is ESI; VC5
// keeps the rebuilt md in ESI and product in EDI. Donor 004F5FB0 shows that
// post-md this-member liveness can produce the original coloring, but natural
// forms tested here do not preserve it without a codegen-only alias.
// - Current TU pass: the dossier confirms exact size, frame, CFG, calls, and
//   six relocation-safe byte differences. Donor search again identifies the
//   same post-md this-liveness pattern, but direct strategic-number rereads
//   already tested in this source produce the same basin. The 00501D70 nested
//   layout remains canonical; no new natural ABI or ownership lead remains.
//
// Fresh bounded pass (sa-d6fdf820-r1): named attributes pointer, storage-count
// reference, original scalar declaration order, direct post-call md use,
// inline storage-count accessor, branch-local capacity declaration, decision
// pointer declaration order, and TRIBE_Player-derived player typing all kept
// exact size/CFG/call parity but reproduced the six-byte md/product register
// basin. The reference and derived-player forms were rolled back because they
// are not canonical source facts here. The current source is restored to the
// pinned natural nested-layout reconstruction.
// Fresh bounded pass (sa-37ed7ad3-r1): compared the 004E3E90 sibling's
// InformationAIModule inheritance, full TribeBuild virtual surface, complete
// tactical extent (0x100C), function-scope md lifetime, separate storage-limit
// local, and minimal header context. All retained the 222-byte / six-byte
// md-product register-swap basin. The clean nested-layout source is restored.
// Fresh bounded pass (sa-92b4ab98-r1): scoped capacity/product/count locals
// and direct natural remaining-value data flow both regressed to the known
// 27-byte scheduling basin. Restored the clean typed reconstruction; the
// remaining six bytes are still only md/product register encodings.
// Revisit (sa-c6deaba1-r1): tested direct post-md strategic rereads, old
// capacity-in-place and product/count local lifetimes, unsigned product,
// expression-level subtraction, and top-scope count. The separate-count
// forms keep md in EDI but sink imul after the count call (27 bytes); reusing
// the proven count home restores the 222-byte six-byte md/product basin.
// Restored the pinned natural source. No new exact natural lead remains.
//
// Translation-unit reconstruction pass (sa-10694da2-r1): 16 focused context
// probes kept the body unchanged and preserved the 222-byte size, six calls,
// and full CFG. Standard-header combinations, repository game headers, late
// and early neutral declaration sweeps, inline and exception pragmas, and
// supported flag variants all emitted the same six-byte basin. Exact same-TU
// AI surfaces from 00502920, full tactical ManagedArray members, full player
// virtual slots, the 00501B50 preceding function body, exact donor declaration
// order, non-polymorphic 00501C70-style surfaces, and inherited information
// surfaces also emitted the same six-byte basin. No context or function-order
// lead changes md from ESI to EDI without changing the body or adding a fake
// liveness use. The pinned natural source remains authoritative.
// Object audit: FPO, PDB, COFF, owner, six relocations, field offsets, and ABI
// all match. PDB has no omitted local or inline frame that can keep this live.
// The remaining md/product swap is allocator coloring; a fake later this use
// remains unsupported.
//
// Exact finish (sa-5dc5a657-r1, 2026-08-17): DIA records only this and the
// PDB parameters numStoragePits, numUnbuiltStoragePits, and rType. The target
// has two int references and one int parameter. Renaming parameters to these
// names and changing declaration order did not change the six-byte basin.
// DIA reports a thiscall function type with const=0, so the method stays
// non-const; the decorated symbol also proves the two-reference ABI.
// A natural direct assignment of the final build count to the first reference
// changed the basin to an exact 222-byte match. The prior local-plus-copy form
// was walked back and restored the six-byte mismatch. Removing the branch-local
// decision alias also stayed exact, so direct typed md expressions are retained.
// Current source preserves InformationAIModule inheritance, the +0xF0 member
// frontier, informationAI size 0x10090, resourceAI +0x10D7C, six ordered calls,
// and the original behavior.


int TribeTacticalAIModule::numberAvailableStoragePits(int& param1, int& param2, int param3) {
    int product;
    int value;
    int capacity_or_count;
    unsigned int remaining;

    value = this->md->buildAI.numberUnbuiltItemsOfType(0x67, 0);
    param2 = value;
    if (value > 0) {
        return 0;
    }

    value = this->md->resourceAI.resource(param3);
    if (this->sn[param3 + 0xBE] <= value) {
        return 0;
    }

    value = this->sn[0x96];
    if (value != -1) {
        capacity_or_count = (int)this->md->player->attributes[6];
        if (capacity_or_count == 0) {
            capacity_or_count = 1;
        }
        product = capacity_or_count * value;
        capacity_or_count = this->md->buildAI.numberItemsOfType(0x67, 0);
        remaining = product - capacity_or_count;
        param1 = capacity_or_count;
        return ((int)remaining < 0) ? 0 : remaining;
    } else {
        param1 = this->md->buildAI.numberItemsOfType(0x67, 0);
        return this->md->informationAI.numberAvailableStoragePits(param3);
    }
}

// ---------------------------------------------------------------------------
// PDB source owner: 00501C70_numberAvailableGranaries.cpp
// ---------------------------------------------------------------------------
// 00501C70 TribeTacticalAIModule::numberAvailableGranaries(int&,int&)
// Source: taitacmd.cpp lines 12343-12370
// Attempt log:
// - Replaced stub with unbuilt-count/resource/SN gates and final informationAI query.
// - Exact match: spell the granary cap check as `value >= this->sn_97` so VC5
//   emits `cmp eax,ecx; jl continue` rather than the reversed `cmp ecx,eax; jg`.

int TribeTacticalAIModule::numberAvailableGranaries(int& count, int& unbuilt)
{
    int value;

    value = ((BuildAIModule*)((char*)this->md + 0x104))->numberUnbuiltItemsOfType(0x44, 0);
    unbuilt = value;
    if (value > 0) {
        return 0;
    }
    value = ((TribeResourceAIModule*)((char*)this->md + 0x10D7C))->resource(0);
    if (this->sn[0xBE] <= value) {
        return 0;
    }
    if (this->sn[0x97] != -1) {
        value = ((BuildAIModule*)((char*)this->md + 0x104))->numberItemsOfType(0x44, 0);
        count = value;
        if (value >= this->sn[0x97]) {
            return 0;
        }
    }
    value = ((BuildAIModule*)((char*)this->md + 0x104))->numberItemsOfType(0x44, 0);
    count = value;
    return ((TribeInformationAIModule*)((char*)this->md + 0xCEC))->numberAvailableGranaries();
}

// ---------------------------------------------------------------------------
// PDB source owner: 00501D20_initialExplorationSatisfied.cpp
// ---------------------------------------------------------------------------
int TribeTacticalAIModule::initialExplorationSatisfied()
{
    int iVar1;

    if (this->sn[0xA7] <= 0)
        return 1;

    iVar1 = (int)(this->md->player->visible->percentExplored() * 100.0f);
    return iVar1 >= this->sn[0xA7];
}

// ---------------------------------------------------------------------------
// PDB source owner: 00501D70_checkForBuildInsertion.cpp
// ---------------------------------------------------------------------------
// VA: 00501D70 TribeTacticalAIModule::checkForBuildInsertion(int,int,int)
// PDB source: taitacmd.cpp:12391-12497
// FLAGS: config/flags/00501D70_checkForBuildInsertion.rsp (/GX)
// Attempt log:
// - The old source used raw module offsets and a synthetic vtable. It reached
//   the target size but had the wrong frame and broad block layout.
// - Fresh reconstruction uses the same-TU module ownership and named fields.
//   The original switch body order remains a codegen question.
// - Corrected the complete nested layout. buildAI ends at +0x6C4,
//   informationAI starts at +0xCEC, and closestDropsiteValue is at +0x540.
// - The typed source is period-plausible and has no inline assembly or raw
//   module-offset macros. Keep it in scratch for parent-agent promotion.

void TribeTacticalAIModule::checkForBuildInsertion(int type, int count, int priority)
{
    switch (type) {
    case 0x32:
        if (this->sn[0x32] != 1 || this->inAge(4) == 0)
            break;
        {
            ResourceItem itemCost(4);
            for (int i = 0; i < count; ++i)
                itemCost.setValue(i, itemCost.value(i) * count);
            this->md->aiPlayer->objectCost(0x32, -1, &itemCost, 1);
            if (this->md->resourceAI.resourcesAvailable(&itemCost) == 0)
                break;
            if (this->md->aiPlayer->objectAvailable(0x32) == 0)
                break;
            if (this->md->buildAI.allBuilt(0, 0) == 0)
                break;
            if (this->md->buildAI.numberBuiltOrInProgressItemsOfType(0x32, 0) >=
                this->sn[0xDC])
                break;
            this->md->buildAI.insert(0x32, count, priority);
        }
        break;

    case 0x44:
        if (this->sn[0x44] != 1)
            break;
        if (this->md->informationAI.closestDropsiteValue[0] == -1)
            break;
        {
            int unbuilt = 0;
            int granaries = 0;
            int available = this->numberAvailableGranaries(unbuilt, granaries);
            if (granaries <= 0 && available > 0 &&
                this->sn[0xA3] <
                    this->md->informationAI.closestDropsiteValue[0]) {
                this->md->buildAI.insert(0x44, count, priority);
            }
        }
        break;

    case 0x4F:
        if (this->sn[0x4F] != 1)
            break;
        {
            ResourceItem itemCost(4);
            for (int i = 0; i < count; ++i)
                itemCost.setValue(i, itemCost.value(i) * count);
            this->md->aiPlayer->objectCost(0x4F, -1, &itemCost, 1);
            if (this->md->resourceAI.resourcesAvailable(&itemCost) == 0)
                break;
            if (this->md->aiPlayer->objectAvailable(0x4F) == 0)
                break;
            if (this->md->buildAI.allBuilt(0, 0) == 0)
                break;
            if (this->md->buildAI.numberBuiltOrInProgressItemsOfType(0x4F, 0) >=
                this->sn[0xDE])
                break;
            this->md->buildAI.insert(0x4F, count, priority);
        }
        break;
    }
}

// ---------------------------------------------------------------------------
// PDB source owner: 005020A0_isFarmer.cpp
// ---------------------------------------------------------------------------
// Function: TribeTacticalAIModule::isFarmer
// VA: 005020A0
// Source: taitacmd.cpp lines 12502-12511
// Attempt log:
// - Replaced the old extern-c/cdecl stub with the real member-function surface.
//   VC5 does not need an explicit __thiscall keyword for C++ member functions;
//   declaring RGE_Static_Object::unitAI() and UnitAIModule::currentAction() as
//   non-virtual members gives the original ECX=this direct-call shape.

int TribeTacticalAIModule::isFarmer(RGE_Static_Object* obj)
{
    UnitAIModule* ai;
    int action;

    if (obj != 0 && (ai = obj->unitAI()) != 0 && obj->master_obj->id == 0x103) {
        ai = obj->unitAI();
        action = ai->currentAction();
        if (action != 0x261) {
            ai = obj->unitAI();
            action = ai->currentAction();
            if (action != 0x262) {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

// ---------------------------------------------------------------------------
// PDB source owner: 00502100_numberFarmers.cpp
// ---------------------------------------------------------------------------
// 00502100 TribeTacticalAIModule::numberFarmers()
// Source: taitacmd.cpp lines 12516-12535
// Size: 249 bytes
// NC: no custom flags (default /O2 /Oy)
//
// Attempt log:
// Probe 1: initial parked reconstruction Ã¢â‚¬â€? 92.3695% positional after rebuild;
//   manual _new/_delete declarations produced the wrong relocation identities
//   and a register-held result, so this was not a useful source baseline.
// Probe 2: use the period ManagedArray<int>::operator[] source shape inline,
//   with the exact operator_new/operator_delete declarations and positive
//   loop guard suggested by the PDB line bands.
// Probe 3: swapped the outer result/index declaration order to test VC5's
//   callee-save coloring; emitted code was unchanged.
// Probe 4: use the natural counted-for form with the index declared in the
//   header, testing whether VC5 assigns the outer induction variable EBX.
// Probe 5: move the index zeroing into its declaration and restore the
//   positive-guarded do-while topology while retaining the shared join.
// Probe 6: variant lab over declaration and new-size spellings; all 12
//   invariant-eligible variants collapsed to the same 15-byte register drift.
// Probe 7: restored the period template ManagedArray<T> surface; duplicate.
// Probe 8: register-qualified the outer index; duplicate.
// Probe 9: reversed explicit zeroing order; duplicate.
// Probe 10: variant lab over inner-copy name, owner tail, and declaration
//   context; all 16 variants collapsed to the same 15-byte drift.
// Best reconstruction: exact call/CFG/size parity; only EBX/EBP coloring
//   differs (outer index versus inlined operator[] new_size).
// Main-agent audit restored canonical polymorphic module/object/master
// ownership; emitted code and the 15-byte coloring drift are unchanged.
// Current session probes: hand-expanded the period ManagedArray growth body,
// then reordered count/index declarations and initialization to match the
// exact same-TU array donor; both emitted the unchanged 15-byte basin.
// Fresh replacement probes (orch-taitacmd-fresh-03):
// - baseline rebuilt the pinned canonical source; exact size/CFG/ordered calls,
//   with the persistent outer-index/new-size EBX/EBP coloring swap.
// - full AIModule/TacticalAIModule inheritance, chained zero assignment,
//   canonical TribeMainDecisionAIModule pointer, postfix increments, a named
//   civilian ID, register-qualified new_size, and exact sibling-style
//   MainDecision layout all duplicated the 15-byte basin.
// - volatile rVal worsened the natural stack increment to 254 bytes; ordinary
//   while topology worsened to 251 bytes and broad drift. Both were rolled back.
// Final clean reconstruction restored and validated: blocker remains localized
//   callee-save coloring only; future lead is original TU/compiler register
//   context or an as-yet-untried natural declaration/lifetime distinction.
// wave20-taitacmd-01 probes (current bounded assignment):
// - function-scope obj/ai/action declarations, game_globals.h context, and
//   operator-scope ManagedArray locals all duplicated the 15-byte basin.
// - removing new_size or caching civilians.value broke the canonical growth
//   surface; an out-of-class operator[] definition, civilians reference alias,
//   long outer index, and combined zero declaration all duplicated the basin.
// - the clean source remains exact in size/CFG/ordered eight-call surface; the
//   only unresolved bytes are the EBX/EBP outer-index/new-size coloring swap.
// Current worker probe:
// - Replaced the named ai/action temporaries with the natural short-circuit
//   action predicate (`currentAction() == 0x261 || == 0x262`), matching the
//   nearby exact numberObjectsWithAction source idiom.  This flipped the
//   callee-save coloring to EBX outer index / EBP growth size and reached an
//   exact 249-byte match without changing ownership, calls, or CFG.

void* operator_new(unsigned int size);
void __cdecl operator_delete(void* ptr);

int TribeTacticalAIModule::numberFarmers()
{
    int i;
    int rVal;

    i = 0;
    rVal = 0;

    if (this->civilians.numberValue > 0) {
        do {
            RGE_Static_Object* obj = this->md->object(this->civilians[i]);
            if ((obj != 0) && (obj->unitAI() != 0) &&
                (obj->master_obj->id == 0x103)) {
                if (obj->unitAI()->currentAction() == 0x261 ||
                    obj->unitAI()->currentAction() == 0x262) {
                    rVal = rVal + 1;
                }
            }
        next:
            i = i + 1;
        } while (i < this->civilians.numberValue);
    }
    return rVal;
}

// ---------------------------------------------------------------------------
// PDB source owner: 00502200_inAge.cpp
// ---------------------------------------------------------------------------
int TribeTacticalAIModule::inAge(int age) {
    int currentAge = *(int*)((char*)this->md + 0x1228);
    return currentAge == age ? 1 : 0;
}

// ---------------------------------------------------------------------------
// PDB source owner: 00502230_stuffAvoidancePath.cpp
// ---------------------------------------------------------------------------
// 00502230 TribeTacticalAIModule::stuffAvoidancePath
// PDB: taitacmd.cpp:12551-12604, 224 bytes
// void __thiscall stuffAvoidancePath(TacticalAIGroup* group, Path* path)
// ret 8 (2 params)
// FLAGS: default
//
// Attempt log:
// - Baseline reconstruction (canonical): divisionLength = length()*0.2f clamped to
//   10.0f; flag tooFew = (numberOfWaypoints() <= 5); loop i=1..count-1 adding an
//   attack waypoint when (tooFew || accumDist >= divisionLength) && (tooFew != 1
//   || accumDist >= 5.0f). The cmp edi,1 in the second clause requires the
//   "tooFew != 1" spelling (nested if/else forms emit no second edi test).
// - addAttackWaypoint takes floats; the call site evaluates currentWaypoint()
//   twice (right-to-left): addAttackWaypoint(currentWaypoint()->x, currentWaypoint()->y).
// - do/while + `int count` local -> tooFew in ebx / i in edi (wrong basin) and
//   VC5 shortened the 2nd fnstsw test to `test bl,ah`; for-loop form fixed the
//   registers AND the mask (tooFew->edi, i->ebx, `test ah,1`) but kept `inc` in
//   the loop-increment slot (after moveToNextWaypoint).
// - EXACT: while (i < numberOfWaypoints()-1) with i++ as a BODY statement placed
//   before moveToNextWaypoint schedules `inc ebx` inside the fadd/fstp gap,
//   matching the original tail exactly. 0.0000% diff.
// - switch(tooFew) case0/1/default fell into jump-table lowering (worse); not kept.

void TribeTacticalAIModule::stuffAvoidancePath(TacticalAIGroup* group, Path* path)
{
    float divisionLength = path->length() * 0.2f;
    if (divisionLength < 10.0f)
        divisionLength = 10.0f;

    path->initToStart();
    float accumDist = path->distanceToNextWaypoint();
    path->moveToNextWaypoint();

    int tooFew = 0;
    if (path->numberOfWaypoints() <= 5)
        tooFew = 1;

    int i = 1;
    while (i < path->numberOfWaypoints() - 1) {
        if ((tooFew || accumDist >= divisionLength) &&
            (tooFew != 1 || accumDist >= 5.0f)) {
            group->addAttackWaypoint(path->currentWaypoint()->x,
                                     path->currentWaypoint()->y);
        }

        accumDist += path->distanceToNextWaypoint();
        i++;
        path->moveToNextWaypoint();
    }
}

// ---------------------------------------------------------------------------
// PDB source owner: 00502310_checkForAttackResponseBuildInsertions.cpp
// ---------------------------------------------------------------------------
// 00502310 TribeTacticalAIModule::checkForAttackResponseBuildInsertions
// taitacmd.cpp:12609-12746, parent-owned switch fragments at 00502451-005025C9
//
// Attempt log:
// - Baseline was an incomplete raw-offset time-gate scaffold (48 bytes) and
//   omitted the object/radius scan, switch, ResourceItem lifetime, and build
//   insertion calls.
// - Probe 1: reconstructed the complete typed parent with the period EH /
//   ResourceItem surface, the natural switch shared body, and same-TU AI
//   module ownership. FLAGS: /GX. Full source emits the correct 0x78 EH
//   frame and all ordered calls.
// - Probe 3: named the saved timestamp; initial codegen stayed in the same
//   register basin.
// - Probe 4: changed the timestamp arithmetic to signed period `long`; this
//   recovered the original signed imul/magic division and exact entry through
//   the time gate, but the parent boundary overflow remained.
// - Probes 5-6: inline/split the unit-count subtraction assignment; VC5 kept
//   the same extra load-before-subtract shape.
// - Session probe 9: moved the units-to-insert declaration to function scope
//   to test the decompiler's top-level local lifetime; emitted code was
//   unchanged and the clean typed source was restored.
// - Session probe 13: applied the exact 00501D70 donor's named ResourceItem,
//   build, information, and main-decision layouts; emitted code was unchanged.
// - Session probe 15: moved the unit-count assignment into its guard condition
//   to seek the original `sub eax,[ebx+118h]`; VC5 emitted identical code.
// - Session probe 19: split the count call from a compound soldiers subtraction
//   to seek the original direct memory subtract; VC5 emitted identical code.
// - Best current reconstruction: typed full parent, 0x78 frame, all 13
//   ordered calls, and natural ResourceItem/switch ownership. After refreshing
//   the parent-fragment extraction, the owned comparison span is 00502310-
//   005025C9 (698 bytes). The remaining mismatch starts at the count
//   subtraction: VC5 emits `mov ecx,[ebx+118h]; mov ebp,eax; sub ebp,ecx`
//   instead of the shipped `sub eax,[ebx+118h]; mov ebp,eax`.
//   Do not replace this source with raw-offset or codegen scaffolding.
// - Current claim: the split `unitsToInsert` initialization followed by
//   compound subtraction is a codegen duplicate. The clean typed source
//   remains pinned. Exact completion needs a supported source or context cause
//   for the direct EAX subtraction.
// - Session claim probes 1-4: `register`, split result/count locals, volatile
//   numberValue, and a reference alias all kept the extra load-before-subtract
//   basin. These did not change the call surface or frame.
// - Session claim probes 5-6: unsigned and long units-to-insert variants proved
//   the observed signed int loop and did not recover the direct memory subtract.
// - Session claim probe 7: a pointer to soldiers.numberValue was codegen-neutral.
// - Session claim probe 8: signed short units-to-insert emitted a narrow `sub`
//   and changed behavior-relevant width; it was rejected.
// - Session claim probes 9-11: zero-plus-result arithmetic, a compound guard,
//   and the original split assignment were duplicate codegen.
// - Session claim probe 12: unsigned numberValue changed one late branch and
//   worsened structural coverage; the proven field is signed int.
// - Session claim probe 13: moving all locals to function scope was a duplicate.
// - Session claim probe 14: an equivalent empty-increment `for` loop was a
//   duplicate of the natural `while` loop.
// - Session claim probe 15: a plain second subtraction statement was duplicate
//   codegen. The natural one-expression form remains authoritative.
// - Binary conclusion: the typed source reproduces the complete natural parent
//   behavior, EH surface, cleanup, and ordered call set. The refreshed checker
//   includes the nine manifest-listed switch fragments. The unresolved drift
//   is one post-call subtraction lowering and its resulting two-byte shift.
// - Variant lab #21 tested six units/loop source combinations without /GX and
//   correctly showed the non-EH 688-byte basin. Lab #22 repeated those axes
//   with /GX: all six EH variants were one 748-byte group; only the natural
//   source was retained.
// - Variant lab #23 added stdlib/string header axes under /GX. All 24 EH
//   variants stayed in the same 748-byte group. Header context did not recover
//   the direct subtract or remove the parent-fragment call additions.
// - Exact-finish pass: 16 additional source, type, layout, control-flow, and
//   context probes stayed in the same 748-byte basin. The pinned clean source
//   was restored and passed unchanged final validation.

void TribeTacticalAIModule::checkForAttackResponseBuildInsertions(int playerID)
{
    long lastAttackTime = this->lastAttackResponseBuildInsertionTime;
    long currentTime = this->md->player->world->world_time;
    if ((currentTime - lastAttackTime) / 1000 < 180)
        return;

    this->lastAttackResponseBuildInsertionTime = currentTime;
    RGE_Static_Object* object = this->md->object(
        -1, 0x6D, -1, -1, -1, -1, -1, -1, -1, -1);
    if (object == 0)
        return;

    int unitsToInsert;
    unitsToInsert =
        this->md->informationAI.numberUnitsWithinXTiles(
            playerID, (int)object->world_x, (int)object->world_y, 20) -
        this->soldiers.numberValue;
    if (unitsToInsert <= 0)
        return;
    if (unitsToInsert > 5)
        unitsToInsert = 5;

    int insertedUnit = 0;
    int itemCostFlag = 0;
    while (unitsToInsert > 0) {
        int unitType;
        int objectType;

        switch (insertedUnit) {
        case 0:
            if (this->md->resourceAI.resource(2) >= 150 &&
                this->civilians.numberValue > 2) {
                this->md->buildAI.insert(0x4F, 1, 0);
                unitsToInsert -= 2;
            }
            insertedUnit = 1;
            continue;
        case 1:
            unitType = 0x25;
            objectType = 0x65;
            break;
        case 2:
            unitType = 0x4B;
            objectType = 0x0C;
            break;
        case 3:
            unitType = 0x5D;
            objectType = 0;
            break;
        case 4:
            unitType = 0x27;
            objectType = 0x57;
            break;
        case 5:
            unitType = 0x49;
            objectType = 0x0C;
            break;
        case 6:
            unitType = 5;
            objectType = 0x57;
            break;
        case 7:
            unitType = 0x12B;
            objectType = 0x65;
            break;
        case 8:
            unitType = 4;
            objectType = 0x57;
            break;
        case 9:
            unitType = 0x7D;
            objectType = 0x68;
            break;
        case 10:
            unitType = 0x29;
            objectType = 0x57;
            break;
        case 11:
            unitType = 0x28;
            objectType = 0x65;
            break;
        default:
            if (itemCostFlag != 1)
                return;
            insertedUnit = 1;
            itemCostFlag = 0;
            continue;
        }

        if (this->md->aiPlayer->objectAvailable(unitType) == 0) {
            insertedUnit++;
            continue;
        }

        RGE_Static_Object* target = this->md->object(
            -1, objectType, -1, -1, -1, -1, -1, -1, -1, -1);
        if (target == 0) {
            insertedUnit++;
            continue;
        }

        {
            ResourceItem itemCost(4);
            this->md->aiPlayer->objectCost(unitType, -1, &itemCost, 1);
            if (this->md->resourceAI.resourcesAvailable(&itemCost) == 1) {
                this->md->buildAI.insert(unitType, 1, 0);
                unitsToInsert--;
                itemCostFlag = 1;
            }
            insertedUnit++;
        }
    }
}

// ---------------------------------------------------------------------------
// PDB source owner: 00502600_checkForCoopTributeDemand.cpp
// ---------------------------------------------------------------------------
// 00502600 TribeTacticalAIModule::checkForCoopTributeDemand
// Attempt log:
// - Baseline was a natural md->holder->world scaffold: 814 bytes, 0x14 frame,
//   and a direct tribute call instead of the observed player vslot +0x54.
// - Restored the period md->player->world ownership, RGE/TRIBE layouts, and
//   the full RGE_Player virtual surface; this fixed the call set and frame.
// - Split the random-player pick from the later tribute amount so VC5 could
//   reuse the original stack home for the resource cursor.
// - The original inner scan uses a positive tempRand guard around the do-loop;
//   a break/body-skip variant added a bottom tempRand test and was rolled back.
// - Best validated reconstruction: 792 bytes versus 788, 0x18 frame, all 12
//   ordered calls/relocations aligned, 96.79% shape, 70-byte edit diff. The
//   remaining structural hunk is the initial amount spill (VC5 keeps it in
//   EBX before testing instead of storing/reloading the original stack home),
//   plus the resulting four-byte tail/branch shift. Paused after the 10-probe
//   budget; no inline asm or custom flags.
// - New claim: restored the binary-shaped inner break form, but VC5 duplicated
//   an earlier 800-byte basin; restored the positive tempRand gate.
// - New claim: declaration order and a scoped tempRand initializer emitted the
//   same 792-byte code; `< 1` threshold spelling worsened shape to 476 diff.
// - New claim: the natural resource-gate conjunction worsened positional diff
//   to 472; restored the four binary-shaped gate jumps.
// - New claim: first-use initializers, reordered loop initialization, the
//   period sn[] surface, and the polymorphic tactical base were codegen
//   duplicates; restored the named clean reconstruction.
// - Remaining lead: recover the natural VC5 spill that stores coopTributeAmount
//   to [esp+10] before its first test; calls, frame, and loop body are aligned.
// Accepted-drift review: the rebuild keeps coopTributeAmount in EBX and tests
// it before initializing private loop homes. The executable stores and reloads
// the same value first. After tribute calls, the executable reloads the resource
// cursor; the rebuild relies on its callee-saved register. Loop exits use an
// inverted branch form. All 12 calls, amounts, players, and effects match.
// - Fresh final validation remains a 453-byte mismatch at +0014. The frame,
//   owner symbol, 12 ordered calls, boundary, and four resource reads match.
// - A counted outer loop with an explicit inner zero-amount goto reached a
//   281-byte mismatch and 95.37% exact-block coverage, but lost the target's
//   inner tempRand test and was restored. A combined inner while reached 314
//   bytes and changed the j setup order. Both forms were reverted.
// - The target's first structural hunk is still the required stack spill and
//   reload of tempRand at [esp+10]. Natural aliases, declaration order, comma
//   setup, initial-value copies, and period loop forms did not reproduce it.
// - Exact-finish probes: the counted outer-for form reproduced the initial
//   spill and pointer setup, but VC5 removed the target's redundant inner
//   tempRand test and ended at 281 bytes (-4 size). The natural do-loop kept
//   that test but stayed at 453 bytes (+4 size). Restored this clean source.

void TribeTacticalAIModule::checkForCoopTributeDemand()
{
    int tempRand;
    int pick;
    TRIBE_World* world;
    int i;
    int j;
    int amountDemandable;
    TribeAIPlayer* player;
    int cur;
    int count;
    int* need;

    int tributeInterval = *(int*)((char*)this + 0x47C);
    int tributeAmount = *(int*)((char*)this + 0x480);
    int foodMin = *(int*)((char*)this + 0x48C);
    int woodMin = *(int*)((char*)this + 0x490);
    int stoneMin = *(int*)((char*)this + 0x494);
    int goldMin = *(int*)((char*)this + 0x498);
    if (tributeInterval == -1) return;
    world = (TRIBE_World*)this->md->player->world;
    cur = world->time;
    if ((cur - this->lastCoopTributeDemandTime) / 1000 < tributeInterval) return;
    this->lastCoopTributeDemandTime = cur;

    world = (TRIBE_World*)this->md->player->world;
    if (world->coop_tribute_player == 0xff) {
        i = 1;
        count = 0;
        if (world->player_count > 1) {
            do {
                if (world->players[i]->computerPlayer() == 1) count++;
                i++;
            } while (i < world->player_count);
        }
        if (count == 1) {
            world->coop_tribute_player = (uchar)this->md->player->id;
        } else {
            pick = debug_rand("C:\\msdev\\work\\age1_x1\\taitacmd.cpp", 0x31f0) % count + 1;
            j = 1;
            if (world->player_count > 1) {
                do {
                    player = world->players[j];
                    if (player->computerPlayer() == 1) {
                        pick--;
                        if (pick == 0) world->coop_tribute_player = (uchar)player->id;
                    }
                    j++;
                } while (j < world->player_count);
            }
        }
    }

    if (world->coop_tribute_player != (uchar)this->md->player->id) return;

    tempRand = tributeAmount;
    i = 0;
    need = this->neededResourceValue;
    do {
        if (tempRand <= 0) return;
        if (*need == 0 && this->md->resourceAI.resource(0) >= foodMin) goto next;
        if (*need == 1 && this->md->resourceAI.resource(1) >= woodMin) goto next;
        if (*need == 3 && this->md->resourceAI.resource(3) >= goldMin) goto next;
        if (*need == 2 && this->md->resourceAI.resource(2) >= stoneMin) goto next;
        if (need[4] < 0) {
            j = 1;
            if (world->player_count > 1) {
                if (tempRand > 0) {
                    do {
                    player = world->players[j];
                    if (player->id != this->md->player->id && player->computerPlayer() != 0) {
                        if (this->md->player->isAlly(j) != 0) {
                            if (player->isAlly((int)this->md->player->id) != 0) {
                                short myid = this->md->player->id;
                                if ((myid < player->id && player->id != (short)world->coop_tribute_player) || myid == (short)world->coop_tribute_player) {
                                    int res = *need;
                                    amountDemandable = (int)player->resources[res];
                                    if (amountDemandable > 50) {
                                        if (amountDemandable > tempRand) amountDemandable = tempRand;
                                        tempRand -= amountDemandable;
                                        player->sendAICommand(myid, 1, res, amountDemandable, 0);
                                    }
                                }
                            }
                        }
                    }
                        j++;
                    } while (j < world->player_count);
                }
            }
        }
next:
        need++;
        i++;
    } while (i < 4);
}

// ---------------------------------------------------------------------------
// PDB source owner: 00502920_checkForCoopTributeGift.cpp
// ---------------------------------------------------------------------------
// VA: 00502920 TribeTacticalAIModule::checkForCoopTributeGift
// Attempt log:
// - Initial rough reconstruction was structurally short and used incomplete
//   player/object virtual surfaces.
// - Baseline recorded before replacing that scaffold with the period-shaped
//   md/player/world/resource ownership and the exact RGE/TRIBE virtual slots.
// - Canonical typed reconstruction restored exact size/frame, all 11 ordered
//   calls, and the first 169 instructions; the remaining drift is localized to
//   the final four-argument command_give_attribute x87 argument schedule.
// - Tried direct final argument evaluation, split/named resource-delta locals,
//   receiver/attribute pointer locals, and a focused 12-variant lab.  The
//   closest natural form uses an int delta plus a float current-attribute local
//   (71 positional bytes; 30-byte edit drift); no variant was exact.
// - Corrected the current attribute from element 0xb8 to element 0x2e because
//   the oracle loads byte offset +0xb8; positional diff stayed 71 and edit drift
//   improved to 28 bytes.
// - Direct receiver/raw-pointer/direct-delta and assignment/reference probes
//   did not reproduce the oracle's fild-before-fld order; restored the clean
//   typed local form.
// - New claim probes: a float amount temporary and implicit conversion were
//   codegen duplicates; a void virtual return and base-typed receiver/cast were
//   also duplicates. A volatile amount made a 717-byte structural mismatch.
//   Restored the clean source after each diagnostic.
// - Replaced temporary offset aliases with the canonical sn[0xba]/sn[0xbe]
//   ownership and full managed-array prefix; emitted code stayed unchanged.
// - Exact natural form: materialize the resource delta as a float local before
//   the current-attribute float local. This restores the original fild/fld
//   order without compiler steering or opaque helpers.
// Exact candidate: size/frame/call/CFG parity and the final call's FPU order
// are exact.

extern int debug_rand(const char* file, int line);
static const char str_taitacmd_path[] =
    "C:\\msdev\\work\\age1_x1\\taitacmd.cpp";

void TribeTacticalAIModule::checkForCoopTributeGift()
{
    if (this->sn[0xBA] == -1) return;
    if (this->md->object(-1, 0x54, -1, -1, -1, -1, -1, -1, -1, -1) == 0) return;

    int now = this->md->player->world->world_time;
    if ((now - this->lastCoopTributeGiftTime) / 1000 < this->sn[0xBA])
        return;
    this->lastCoopTributeGiftTime = now;

    TRIBE_World* world = (TRIBE_World*)this->md->player->world;
    if (world->controllingComputerPlayer == 0xff) {
        int i = 1;
        int num_computer = 0;
        if (world->player_count > 1) {
            do {
                if (world->players[i]->computerPlayer() == 1)
                    ++num_computer;
                ++i;
            } while (i < world->player_count);
        }
        if (num_computer == 1) {
            world->controllingComputerPlayer = this->md->player->id;
        } else {
            int pick = debug_rand(str_taitacmd_path, 0x3275) %
                            num_computer + 1;
            i = 1;
            if (world->player_count > 1) {
                do {
                    RGE_Player* other = world->players[i];
                    if (other->computerPlayer() == 1) {
                        --pick;
                        if (pick == 0)
                            world->controllingComputerPlayer = other->id;
                    }
                    ++i;
                } while (i < world->player_count);
            }
        }
    }

    int i = 0;
    int* minimum = &this->sn[0xBE];
    do {
        if (this->md->resourceAI.resource(i) > *minimum) {
            int bestCP = -1;
            float tributeAmount = 0.0f;
            int j = 1;
            if (world->player_count > 1) {
                do {
                    RGE_Player* other = world->players[j];
                    if (other->id != this->md->player->id &&
                        other->computerPlayer() != 0 &&
                        this->md->player->isAlly(j) != 0 &&
                        other->isAlly(this->md->player->id) != 0) {
                        float* attribute = other->attributes + i;
                        int minimumValue =
                            other->strategicNumber(i + 0xbe);
                        if (*attribute < (float)minimumValue &&
                            (bestCP == -1 || *attribute < tributeAmount)) {
                            bestCP = other->id;
                            tributeAmount = *attribute;
                        }
                    }
                    ++j;
                } while (j < world->player_count);
            }
            if (bestCP != -1) {
                float amount =
                    (float)(this->md->resourceAI.resource(i) - *minimum);
                TribeAIPlayer* aiPlayer = this->md->aiPlayer;
                float current = aiPlayer->attributes[0x2e];
                aiPlayer->command_give_attribute(
                    bestCP, i,
                    amount,
                    current);
            }
        }
        ++i;
        ++minimum;
    } while (i < 4);
}

// ---------------------------------------------------------------------------
// PDB source owner: 00502BF0_checkForASAPAgeResearch.cpp
// ---------------------------------------------------------------------------
// VA: 00502BF0 TribeTacticalAIModule::checkForASAPAgeResearch (347 B)
// PDB source: taitacmd.cpp
// __thiscall, void
//
// Attempt log:
// - Replaced the parked raw-offset/free-helper scaffold with the period-shaped
//   three-age research checks.  The build, resource, and tactical modules are
//   named typed members; the first two research arms intentionally keep their
//   branch-local taskResearch calls, as shown by the distinct call sites and
//   PDB line bands.

void TribeTacticalAIModule::checkForASAPAgeResearch()
{
    if (this->inAge(1) != 0 && this->sn[0xB5] == 1 &&
        this->md->buildAI.readyToResearch(2, 1) != 0 &&
        this->md->resourceAI.resource(0) >= 500) {
        BuildItem* item = this->md->buildAI.buildItem(0x65, 1, 4);
        if (item != 0)
            this->taskResearch(item);
    }
    else if (this->inAge(2) != 0 && this->sn[0xB6] == 1 &&
             this->md->buildAI.readyToResearch(3, 1) != 0 &&
             this->md->resourceAI.resource(0) >= 800) {
        BuildItem* item = this->md->buildAI.buildItem(0x66, 1, 4);
        if (item != 0)
            this->taskResearch(item);
    }

    if (this->inAge(3) != 0 && this->sn[0xB7] == 1 &&
        this->md->buildAI.readyToResearch(4, 1) != 0 &&
        this->md->resourceAI.resource(0) >= 900 &&
        this->md->resourceAI.resource(3) >= 700) {
        BuildItem* item = this->md->buildAI.buildItem(0x67, 1, 4);
        if (item != 0)
            this->taskResearch(item);
    }
}

// ---------------------------------------------------------------------------
// PDB source owner: 00502D50_checkForCoopAttack.cpp
// ---------------------------------------------------------------------------
// 00502D50 TribeTacticalAIModule::checkForCoopAttack
// Attempt log:
// 1: Natural reconstruction from asm: timing gate, random coop-player choice, per-player attack-order checks; broad mismatch due extra locals and /100 divisor.
// 2: Modeled current object as RGE_Player with player_list at +3c and /1000 timing; optimized too small (416-byte .text), wrong prolog/register allocation.
// 3: Tried explicit self/ai locals: still optimized too small.
// 4: Tried /Ob0: still optimized too small; removed flag.
// 5: Tried /Od: 89.58% broad mismatch from first byte; removed flag.
// BLOCKER: behavior is mostly reconstructed, but VC5 source shape/local topology is wrong. Natural high-level version collapses to 416 bytes; extra-local version has correct size but wrong prolog/register allocation and broad cascade. Need recover original one-local topology: `push ecx`, save `this` in EBP, EDI as PlayerList, EBX as loop index/local slot, with `/1000` timing magic 0x10624DD3.
// Probe 2: replaced the decompiler-shaped UnitAIModule/UnitObject chain with
// canonical md->player->world ownership and direct member expressions, avoiding
// a saved md/object temporary across the virtual calls.
// Probe 3: restored the complete 0x104-byte RGE_Game_World base; the derived
// controllingComputerPlayer byte then landed at its proven +0x11D offset and
// the canonical source matched all 480 bytes.
// Probe 5: made the debug source-file path a period-style local string literal;
// emitted code remained exact and the source no longer depends on a fabricated
// external path symbol.

extern int debug_rand(const char* file, int line);
void TribeTacticalAIModule::checkForCoopAttack(int p1, int p2, int p3)
{
    int coopAttackEnabled = *(int*)((char*)this + 0x4A4);
    int coopAttackInterval = *(int*)((char*)this + 0x4A8);
    if (coopAttackEnabled != 1) return;

    int now = this->md->player->world->world_time;
    int* lastCoopAttackTime = (int*)((char*)this + 0xFA0);
    if ((now - *lastCoopAttackTime) / 1000 < coopAttackInterval) return;
    *lastCoopAttackTime = now;

    TRIBE_World* world = (TRIBE_World*)this->md->player->world;
    if (world->controllingComputerPlayer == 0xff) {
        int num_computer = 0;
        int i = 1;
        if (world->player_count > 1) {
            do {
                if (world->players[i]->computerPlayer() == 1) ++num_computer;
                ++i;
            } while (i < world->player_count);
        }
        if (num_computer == 1) {
            world->controllingComputerPlayer = this->md->player->id;
        } else {
            int pick = debug_rand(str_taitacmd_path, 0x32f1) % num_computer + 1;
            i = 1;
            if (world->player_count > 1) {
                do {
                    RGE_Player* other = world->players[i];
                    if (other->computerPlayer() == 1) {
                        --pick;
                        if (pick == 0) world->controllingComputerPlayer = other->id;
                    }
                    ++i;
                } while (i < world->player_count);
            }
        }
    }

    int idx = 1;
    if (world->player_count <= 1) return;
    do {
        RGE_Player* other = world->players[idx];
        if (other->id != this->md->player->id &&
            other->computerPlayer() != 0 &&
            this->md->player->isAlly(idx) != 0 &&
            other->isAlly(this->md->player->id) != 0) {
            if ((this->md->player->id < other->id &&
                 other->id != world->controllingComputerPlayer) ||
                this->md->player->id == world->controllingComputerPlayer) {
                other->sendAICommand(this->md->player->id, 2, p1, p2, p3);
            }
        }
        ++idx;
    } while (idx < world->player_count);
}

// ---------------------------------------------------------------------------
// PDB source owner: 00502F30_processCoopAttack.cpp
// ---------------------------------------------------------------------------
// VA: 00502F30 TribeTacticalAIModule::processCoopAttack
// PDB: taitacmd.cpp lines 13085-13106
// Attempt log:
// try 1: replaced bogus stub with packet/decompiler-based implementation and local class surfaces: 6-byte localized register mismatch.
// try 2: direct &this->groups loop condition: no change.
// try 3: register sentinel: no change.
// try 4: self local adjusted by +0x9D4, int sentinel, and pointer sentinel variants: no change.
// try 5: register current count: no change.
// try 6: free __thiscall form rejected by VC5; restored member method.
// try 7: declared current outside loop; no improvement, still 6-byte register mismatch.
// try 8: rewrote loop as initial-if plus while/break; worsened branch layout, rolled back.
// try 9: declared sentinel before group; worsened whole register allocation, rolled back.
// try 10: for-loop with explicit null break; no improvement.
// try 11: inverted desired/current compare; worsened compare opcode/polarity, rolled back.
// ACCEPTED_DRIFT 2026-05-19: approved localized behavior-equivalent register allocation drift.
// Remaining 6 bytes are only sentinel/current-count register choices: original mutates EDI
// to the sentinel and uses EBX for current count; rebuilt keeps sentinel in EBX via LEA
// and uses EDI for current count. Calls, predicates, loop effects, stack cleanup, and
// memory effects otherwise match exactly.

int TribeTacticalAIModule::processCoopAttack(int p1, int player, int p3, int p4) {
    if (attackEnabledValue == 0) {
        return 0;
    }

    this->md->diplomacyAI.setStance(player, 0, 100);

    int current;
    TacticalAIGroup* group = groups.next;
    TacticalAIGroup* sentinel = &groups;
    for (; group != sentinel; group = group->next) {
        if (group == 0) break;
        if (group->type() == 100 || group->type() == 0x67) {
            current = group->numberUnits();
            if (group->desiredNumberUnits() > current) {
                group->setDesiredNumberUnits(group->numberUnits());
            }
        }
    }

    return 1;
}

// ---------------------------------------------------------------------------
// PDB source owner: 00502FC0_resourceDifference.cpp
// ---------------------------------------------------------------------------
int TribeTacticalAIModule::resourceDifference(int index) {
    if (index < 0 || index > 3)
        return -1;
    return this->resourceDifferenceValue[this->neededResourceValue[index]];
}

// ---------------------------------------------------------------------------
// PDB source owner: 00502FF0_actualGathererCount.cpp
// ---------------------------------------------------------------------------
int TribeTacticalAIModule::actualGathererCount(int index) {
    if (index < 0 || index > 3)
        return -1;
    return this->actualGathererDistribution[this->neededResourceValue[index]];
}

// ---------------------------------------------------------------------------
// PDB source owner: 00503020_actualGathererCountByRealResourceID.cpp
// ---------------------------------------------------------------------------
int TribeTacticalAIModule::actualGathererCountByRealResourceID(int index) {
    if (index < 0 || index > 3) {
        return -1;
    }
    return this->actualGathererDistribution[index];
}

// ---------------------------------------------------------------------------
// PDB source owner: 00503040_desiredGathererCount.cpp
// ---------------------------------------------------------------------------
int TribeTacticalAIModule::desiredGathererCount(int index) {
    if (index < 0 || index > 3)
        return -1;
    return this->desiredGathererDistribution[this->neededResourceValue[index]];
}

// ---------------------------------------------------------------------------
// PDB source owner: 00503070_taskElephantGatherers.cpp
// ---------------------------------------------------------------------------
// 00503070 TribeTacticalAIModule::taskElephantGatherers(int,int,int)
// Source: taitacmd.cpp lines 13148-13219
// FLAGS: config/flags/00503070_taskElephantGatherers.rsp
// Attempt log:
// - Fresh typed reconstruction from the exact same-TU tactical task donors.
// - Canonical ownership: md +0xF0; gatherers +0x51C with 0x18-byte UnitData;
//   numberGatherersValue +0x9CC; local ManagedArray<int> fields are value,
//   numberValue, desiredNumberValue, and maximumSizeValue.
// - The original initializes one local ManagedArray slot with resize(1), then
//   appends mainHunterID through numberValue. The desiredNumberValue field is
//   not used by this body.
// - Baseline: typed source reached 620 bytes with the correct 0x20 frame and
//   nine-call set; first mismatch was the outer scan setup, not a call boundary.
// - Correcting UnitData to 0x18 bytes restored the proven +0x9CC gatherer count
//   and improved block shape. Adding MainDecision objects at +0xF4 restored
//   aiPlayer +0x1256C and improved exact-block coverage again.
// - Hoisted local declarations, swapped declaration order, matched the
//   preincrement growth copy, and tested a counted outer loop. These produced
//   duplicate code or only register/home drift. Reversed duplicate-scan compare
//   operands reduced exact-block coverage and was restored.
// - Replaced the outer counted for with a typed do-while to match the original
//   count-positive entry guard and tail test; emitted code was unchanged and
//   the clean counted-loop reconstruction was restored.
// - Canonical bounded indexed scans removed the extra bottom capacity tests and
//   restored the original scan blocks. The donor-style two-condition growth
//   copy restored its complete copy block and reduced the best diff to 174.
// - Direct return on no selected gatherer restored the original cold cleanup
//   size, but changed later liveness; the shared break is retained instead.
// - Best current check: 600 rebuilt bytes versus 618 original, 92.50% shape,
//   89.85% exact-block coverage, 100% ordered-call alignment, and 174 strict
//   differing bytes. The remaining structural hunk starts at outer-loop zero
//   register setup; the FPU predicate remains a separate codegen gap.
// - Revisited with the natural counted while, the reviewed DAT_00575758
//   sentinel, and bestDistance > distance. The external sentinel and operand
//   order recover the original fcomp/test-ah,41 sequence.
// - Returning directly when no gatherer is selected recovers the original
//   separate destructor cleanup block: 618 bytes, 197 instructions, exact
//   frame/CFG/call count, and 13/13 relocation identities.
// - Current best is a four-byte local scheduling drift at +012E: VC5 reloads
//   maximumSizeValue before numberValue, while the original reverses them.
//   Expanded updates were duplicate codegen; pointer-first updates and a
//   cached count were worse and were restored.
// ACCEPTED DRIFT: The four changed bytes move two adjacent stack reloads past
//   each other. The original loads numberValue into ECX, then maximumSizeValue
//   into ESI. The rebuild reverses these loads. No instruction occurs between
//   them, and both registers have the same values before the next instruction.
//   Calls, writes, predicates, fault order, cleanup, and all later bytes match.
// - No unsupported raw vtable or inline-assembly form is retained.
// - Exact-finish probes tested PDB local declaration order, bounded scan forms,
//   ManagedArray accessors and constructor/destructor surfaces, assignment and
//   update forms, narrow local aliases, standard-header context, ambient
//   declaration context, and pinned-flag variants. Natural forms either kept
//   the same four-byte basin or lost the target size and CFG. All metric-only
//   forms were removed. PDB names mainHunterID, numberToTask, targetID, and
//   count are retained because the symbol record proves those roles.
// - This claim also tested first-scan index scope and reuse, cached count
//   locals, an explicit while scan, a wider object scope, and the donor-proven
//   tactical-module destructor surface. All emitted code stayed unchanged.
// - A 32-case first-scan source and header-context lab kept size, frame, call
//   set, CFG, and all 4 differing bytes unchanged. It found no exact variant.
// - Final validation remains a four-byte MISMATCH at +012E: the rebuilt code
//   loads maximumSizeValue before numberValue. The original loads numberValue
//   into ECX, then maximumSizeValue into ESI. No call, write, x87 predicate,
//   cleanup, fault boundary, or direct-control identity differs.
// - Specialist exact-finish work tested the PDB-proven full UnitData fields,
//   the full taitacmd.cpp class context, and the exact utmarray.h API shapes.
//   It also tested indexed and cursor scans, continue/goto forms, loop and
//   bound order, field aliases, register hints, and authentic source lines.
// - CPU and debug-context classification did not recover the reload order.
//   Every invariant-preserving natural form kept the same four-byte basin.
//   Forms that changed the basin also changed the frame, CFG, or call set.
//   The clean typed source remains authoritative; no steering form is kept.

void* operator new(unsigned int size);
void operator delete(void* ptr);
extern float DAT_00575758;

void TribeTacticalAIModule::taskElephantGatherers(
    int mainHunterID, int numberToTask, int targetID)
{
    RGE_Static_Object* targetObject = this->md->object(targetID);
    if (targetObject != 0) {
        int count;
        ManagedArray<int> alreadyTasked(0);

        alreadyTasked.resize(1);
        alreadyTasked.value[alreadyTasked.numberValue] = mainHunterID;
        alreadyTasked.numberValue++;
        count = 0;

        while (count < numberToTask) {
                float bestDistance;
                int bestValueID;
                int i;
                bestDistance = -1.0f;
                bestValueID = -1;
                i = 0;

                if (this->numberGatherersValue > 0) {
                    UnitData* gatherer = this->gatherers;
                    do {
                        RGE_Static_Object* object;
                        for (int j = 0; j < alreadyTasked.numberValue; j++) {
                            if (j >= alreadyTasked.maximumSizeValue)
                                break;
                            if (alreadyTasked.value[j] == gatherer->id)
                                goto nextGatherer;
                        }

                        object = this->md->object(gatherer->id);
                        if (object != 0 && object->unitAI() != 0 &&
                            gatherer->data1 == 0) {
                            float distance = object->distance_to_object(targetObject);
                            if (bestDistance == DAT_00575758 ||
                                bestDistance > distance) {
                                bestValueID = gatherer->id;
                                bestDistance = distance;
                            }
                        }

nextGatherer:
                        i++;
                        gatherer++;
                    } while (i < this->numberGatherersValue);
                }

                if (bestValueID == -1)
                    return;

                this->md->aiPlayer->taskResourceGatherer(
                    bestValueID, targetID, 0,
                    targetObject->world_x, targetObject->world_y);

                for (int j = 0; j < alreadyTasked.numberValue; j++) {
                    if (j >= alreadyTasked.maximumSizeValue)
                        break;
                    if (alreadyTasked.value[j] == bestValueID)
                        goto afterAdd;
                }

                if (alreadyTasked.numberValue >
                    alreadyTasked.maximumSizeValue - 1) {
                    int newSize = alreadyTasked.numberValue + 1;
                    int* newValue = new int[newSize];
                    if (newValue != 0) {
                        for (int k = 0;
                             k < alreadyTasked.maximumSizeValue && k < newSize;
                             k++) {
                            newValue[k] = alreadyTasked.value[k];
                        }
                        operator delete(alreadyTasked.value);
                        alreadyTasked.value = newValue;
                        alreadyTasked.maximumSizeValue = newSize;
                    }
                }

                alreadyTasked.value[alreadyTasked.numberValue] = bestValueID;
                alreadyTasked.numberValue++;

afterAdd:
                count++;
        }
    }
}

// ---------------------------------------------------------------------------
// PDB source owner: 005032E0_checkTradeBoats.cpp
// ---------------------------------------------------------------------------
// VA: 005032E0 TribeTacticalAIModule::checkTradeBoats (406 B)
// PDB source: taitacmd.cpp:13224-13258
// __thiscall, void
//
// Attempt log:
// - Baseline reconstruction: restored the typed Tribe tactical module, embedded
//   tradeBoats ManagedArray, MainDecision object lookup, resourceAI threshold
//   checks, and aiPlayer trade-attribute dispatch from the original call set.
// - Probe 2 control-flow: a do/while with an inner break emitted the opposite
//   signed backedge (js-to-exit plus jmp-to-loop) and grew to 407 bytes; rolled
//   back.
// - Probe 3 control-flow: the ordinary descending for loop plus source-local
//   found/next labels reproduced the original jns backedge, boundary, and all
//   406 bytes exactly.  The labels preserve the observed found and next-boat
//   CFG rather than compiler-steering register aliases.
// - Probe 4 control-flow: replacing the found label with break plus a
//   post-loop resource guard changed liveness/saves and broad block layout;
//   restored the exact for/label reconstruction.

void* operator new(unsigned int size);
void operator delete(void* ptr);

void TribeTacticalAIModule::checkTradeBoats()
{
    int i;
    i = 0;

    if (this->tradeBoats.numberValue > 0) {
        do {
            RGE_Static_Object* object =
                this->md->object(this->tradeBoats[i]);
            if (object != 0) {
                short attribute = object->type;
                if (this->md->resourceAI.resource((int)attribute) <
                    this->sn[0xD8]) {
                    int resource = 2;
                    for (; resource >= 0; --resource) {
                        if (resource != attribute &&
                            this->md->resourceAI.resource(resource) >=
                                this->sn[0xD8]) {
                            goto trade_attribute;
                        }
                    }

                    goto next_boat;

trade_attribute:
                    this->md->aiPlayer->command_trade_attribute(
                        this->tradeBoats[i], resource);
                }
            }

next_boat:
            ++i;
        } while (i < this->tradeBoats.numberValue);
    }
}

// ---------------------------------------------------------------------------
// PDB source owner: 00503480_numberGatherersWithTarget.cpp
// ---------------------------------------------------------------------------
int TribeTacticalAIModule::numberGatherersWithTarget(int targetId) {
    int count;
    int remaining;
    int* target;

    remaining = this->numberGatherersValue;
    count = 0;
    if (remaining > 0) {
        target = &this->gatherers[0].target;
        do {
            if (*target == targetId)
                count = count + 1;
            target = target + 6;
            remaining = remaining - 1;
        } while (remaining != 0);
    }
    return count;
}

// ---------------------------------------------------------------------------
// PDB source owner: 005034B0_checkStaleAttackGroups.cpp
// ---------------------------------------------------------------------------
// 005034B0 TribeTacticalAIModule::checkStaleAttackGroups
// Source: taitacmd.cpp lines 13274-13312
// Attempt log:
// - Baseline direct expression: 182 bytes; VC5 evaluated desiredUnits before
//   numberUnits, unlike the executable.
// - Function-scope number/desired locals: 184 bytes, all six direct calls in
//   order; retained as the clean period-plausible reconstruction.
// - Volatile stack-home diagnostics reached 192 bytes and restored push ecx,
//   but stored the first result before desiredUnits rather than at the observed
//   post-call site; rolled back. Named time/world and comparison variants did
//   not improve emitted code. A 24-variant lab found no exact source.
// - Fresh pass (orch-luna-5034b0-w2): declaration-order, desired/difference
//   expression, compound-assignment, direct-predicate, full typed-layout, and
//   initialized-inner-local probes added no exact basin. The best fresh result
//   was the volatile-number diagnostic at 192 bytes (110 positional diff,
//   95.38% shape); it still spills before desiredUnits and has the wrong time
//   register basin. A 270-variant lab over storage/declaration/calculation/
//   compare/time surfaces found no exact or size-valid candidate. Full binary
//   TacticalAIGroup/RGE time/player fields were codegen-neutral. Restored the
//   clean natural source.
// - Normalization-only audit: replaced raw vtable_ptr with the exact-donor-backed
//   virtual TacticalAIGroup destructor surface; emitted code was unchanged. No
//   new matching hypothesis was introduced.
// - Paused: remaining drift is the VC5 local spill/liveness and time-expression
//   basin; no ABI/call-set or behavioral uncertainty is known.
// - Fresh bounded pass (orch-taitcmd-01): elapsed-first comparison plus the
//   known volatile stack-home surface reached 192 bytes / 111 positional diff
//   with target time-chain registers; a PDB-style for loop was codegen-duplicate.
//   Reused-value, compound-assignment, initializer-scope, and three-local
//   declaration permutations were duplicate or worse. Adding/removing an
//   owning-module virtual surface was also codegen-neutral; the donor vtable
//   word did not improve the remaining local spill. Restored this clean source.
// - Paused: ten fresh hypotheses exhausted; best diagnostic remains the prior
//   192-byte / 110-diff volatile-number basin, while the retained source is the
//   natural 184-byte reconstruction. Calls, layout, and behavior are understood.
// - Fresh final pass (orch-taitacmd-fresh-04): inner ordered result
//   initializers plus elapsed-first comparison were unchanged structurally;
//   inner volatile-number plus elapsed-first reached 192 bytes / 111 diff.
//   Desired-before-number declarations, reference alias, comma assignment,
//   ordinary desired-minus-number reuse, and register-qualified desired were
//   duplicate or worse. Re-establishing the prior diagnostic best confirmed
//   192 bytes / 110 diff; its spill still occurs before desiredUnits rather
//   than at the oracle's post-call site. Restored clean natural source.
// - Paused: fresh ten-hypothesis budget exhausted; exact calls and typed
//   ownership remain established, while the local spill/liveness and time-chain
//   register basin remain unresolved.
// - Fresh bounded pass (wave21-taitacmd-01): revalidated the clean source, then
//   tested the actual AIModule/TacticalAIModule base chain, polymorphic
//   RGE_Game_World/RGE_Player surfaces, and the inherited
//   MainDecisionAIModule -> TribeMainDecisionAIModule player ownership; all
//   were codegen-duplicate. Function-scope desired compound reuse, const
//   number, full Ghidra iVar1/iVar2 lifetime including the final setter temp,
//   a named elapsed quotient, and unsigned world_time were duplicate or
//   repeated prior basins. Restored the natural source.
// - Paused: canonical ownership, six ordered calls, CFG, and behavior remain
//   established; the only unresolved gap is the original delayed number spill
//   ([esp+10] after desiredNumberUnits) plus its associated time-register
//   basin. No further natural source/layout lead remains in this assignment.
// - Fresh bounded pass (sa42836b2c-r1-005034B0): a negative
//   elapsed<difference guard with a natural for-update reproduced the oracle's
//   cmp edx,edi / jl branch; combining inner volatile number with the
//   desired-minus-number local reached the prior 192-byte / 110-diff basin.
//   A late volatile copy followed by a separate difference local reached exact
//   size (194) and 27 positional-diff bytes with all six calls and CFG aligned,
//   but selected the wrong subtraction order and time-chain register coloring.
//   This compiler-steering diagnostic was not retained; restored the clean
//   natural source.
// - Paused: ten meaningful hypotheses exhausted. Best retained source remains
//   the natural 184-byte reconstruction; next lead is combining the late
//   post-desired spill topology with the target EDI time-chain basin without
//   retaining redundant volatile/copy scaffolding.
// - Fresh bounded pass (orch-005034B0-L): ten liveness/context probes tested
//   split subtraction, address-taken number storage, world caching, and
//   stdlib/string header context. Inner volatile number plus the natural
//   inverted elapsed guard reproduced the prior best at 194 bytes / 27 diff;
//   all other probes were duplicate or worse. The best diagnostic still uses
//   the wrong desired subtraction order and time-chain register allocation.
// - Paused: restored and validated the clean natural source. Calls, layout,
//   CFG, and behavior remain established; delayed number spill and time-chain
//   allocation remain unresolved.
// - Current TU pass: dossier and original assembly confirm the only structural
//   gap is the 4-byte local home (`push ecx`, post-desired spill at [esp+10]).
//   Same-TU exact donors and the canonical 00501D70 nested layout add no new
//   source ownership fact. The clean typed source remains authoritative; no
//   natural, evidence-backed spill lead remains without compiler steering.

void TribeTacticalAIModule::checkStaleAttackGroups()
{
    int number;
    int desired;

    if (this->attackEnabledValue != 0) {
        TacticalAIGroup* group = this->groups.next;
        TacticalAIGroup* sentinel = &this->groups;

        while (group != sentinel && group != 0) {
            if (group->type() == 100 && group->inUse() != 1) {
                number = group->numberUnits();
                desired = group->desiredNumberUnits();
                int difference = desired - number;
                if (difference > 0) {
                    if (difference > 5) {
                        difference = 5;
                    }
                    if (difference <=
                        (int)(this->md->player->world->world_time -
                              group->lastAddedUnitTimeValue) / 60000) {
                        group->setDesiredNumberUnits(group->numberUnits());
                    }
                }
            }
            group = group->next;
        }
    }
}

// ---------------------------------------------------------------------------
// PDB source owner: 00503580_numberWaterExplorers.cpp
// ---------------------------------------------------------------------------
// 00503580 TribeTacticalAIModule::numberWaterExplorers()
// Source: taitacmd.cpp lines 13317-13336
// Attempt log:
// - Replaced stub with Ghidra list walk and real direct member-call surface.

int TribeTacticalAIModule::numberWaterExplorers()
{
    TacticalAIGroup* group;
    TacticalAIGroup* sentinel;
    int count;

    count = 0;
    group = this->groups.next;
    sentinel = &this->groups;
    while (group != sentinel && group != 0) {
        if ((group->type() == 0x67 || group->type() == 0x68 ||
             group->type() == 0x69 || group->type() == 0x6a ||
             group->type() == 0x6b || group->type() == 0x6c) &&
            group->action() == 8) {
            count = count + 1;
        }
        group = group->next;
    }
    return count;
}

// ---------------------------------------------------------------------------
// PDB source owner: 00503600_saveTheTown.cpp
// ---------------------------------------------------------------------------
// VA: 00503600 TribeTacticalAIModule::saveTheTown
// PDB source: taitacmd.cpp:13342-13444
// __thiscall
// Attempt log:
// - Replaced the parked raw-pointer scaffold with the typed same-TU ownership
//   model: md, aiPlayer, soldiers, playersToAttack, target objects, and groups.
// - The baseline follows the binary call bands: group rescue, soldier scan,
//   then civilian reinforcement. It keeps the two inline ManagedArray growth
//   sites because the executable contains all three growth blocks.
// - Shared the binary LAB_00503954 soldier attack path with a count-only label;
//   this restored all 52 ordered calls, the 0x24 frame, and a +11-byte size gap.
// - Restored the five missing ManagedArray records before sn; this aligned
//   sn[0x14] at +0x1E4 and playersToAttack at +0xD28/+0xD34.
// - Modeled vslot 0x10C as the same-TU weaponRange() call and vslot 0x198
//   as the full canPath(XYZPoint, float, int, float*, int, int, int) ABI.
//   The natural trailing id, 0, 1, -1, -1 arguments preserve the original
//   stack homes and remove the 14-byte command/canPath drift.
// - Reversed entryCount/count declarations to match the original loop stores.
// - A natural conjunction (`count < soldiers.numberValue && entryCount < 6`)
//   restores the binary split loop guard and reduces the gap to 14 bytes.
// - The proven 0x10 base gap places aiPlayer at +0x1256C. Reversed the owner
//   comparison operands and shared the binary entryCount label at +0x3A76.
// - Shared point declaration, aggregate initialization, object-local reuse,
//   and named command-result probes were duplicate or worse; they were rolled back.
// - Final validation: MATCH, 1450/1450 bytes, 52/52 calls, 0x24 frame.


extern "C" ulong debug_timeGetTime(char* file, int line);
extern int __ftol();
extern void* operator_new(unsigned int size);
extern void operator_delete(void* block);


void TribeTacticalAIModule::saveTheTown(int objectID)
{
    ulong entryTime = debug_timeGetTime((char*)0x5880C0, 0x3420);
    RGE_Static_Object* targetObject;
    XYPoint objectPosition;
    int entryCount;
    int count;
    XYZPoint point;
    targetObject = this->md->object(objectID);

    if (targetObject != 0) {
        objectPosition.x = (int)targetObject->world_x;
        objectPosition.y = (int)targetObject->world_y;

        TacticalAIGroup* group = this->readyAndIdleGroup(
            100, this->sn[0x14], objectPosition);
        if (group == 0)
            group = this->readyAndIdleGroup(
                0x67, this->sn[0x14], objectPosition);

        if (group != 0) {
            int commanderID = group->commander();
            RGE_Static_Object* commanderObject =
                this->md->player->world->object(commanderID);
            if (commanderObject != 0) {
                point.x = (int)targetObject->world_x;
                point.y = (int)targetObject->world_y;
                point.z = (int)targetObject->world_z;
                if (commanderObject->canPath(
                        point, commanderObject->weaponRange(), objectID, 0, 1,
                        -1, -1) == 1) {
                    group->setTarget(objectID);
                    group->setTargetType(
                        (int)targetObject->master_obj->id);
                    group->setTargetLocation(
                        targetObject->world_x, targetObject->world_y,
                        targetObject->world_z);
                    group->setAction(2);
                    group->task(this, this->md, 2, 1, 0);
                    return;
                }
            }
        }

        entryCount = 0;
        count = 0;
        if (this->soldiers.numberValue > 0) {
            while (count < this->soldiers.numberValue && entryCount < 6) {
                if (count > 1 &&
                    debug_timeGetTime((char*)0x5880C0, 0x3447) -
                            entryTime > 10)
                    return;

                RGE_Static_Object* object = this->md->aiPlayer->world->object(
                    this->soldiers[count]);
                if (object != 0 && object->unitAI() != 0) {
                    if (object->unitAI()->currentAction() == 600) {
                        if (object->unitAI()->currentTarget() == -1)
                            goto trySoldier;
                        if (object->unitAI()->currentTarget() ==
                            targetObject->id)
                            goto countEntry;

                        RGE_Static_Object* currentTarget =
                            this->md->player->world->object(
                                object->unitAI()->currentTarget());
                        if (currentTarget != 0 &&
                            currentTarget->owner->id ==
                                this->playersToAttack[0])
                            goto countSoldier;
                    } else {
                        goto trySoldier;
                    }

trySoldier:
                    {
                        if (object->distance_to_object(targetObject) <
                            25.0f) {
                        point.x = (int)targetObject->world_x;
                        point.y = (int)targetObject->world_y;
                        point.z = (int)targetObject->world_z;
                        if (object->canPath(
                                point, object->weaponRange(), targetObject->id,
                                0, 1, -1, -1) != 0) {
                            if (this->taskAttacker(
                                    this->soldiers[count],
                                    targetObject->world_x,
                                    targetObject->world_y, targetObject->id,
                                    (int)targetObject->owner->id, 0, 0, -1,
                                    0) == 1) {
countEntry:
                                entryCount++;
                            }
                        }
                    }
                    }
                }

countSoldier:
                count++;
            }
        }

        int unitID = this->civilian(
            objectPosition, 1, 700, -1000, -1000, 1);
        while (unitID != -1 && entryCount < 6) {
            RGE_Static_Object* object = this->md->object(unitID);
            if (object == 0)
                return;

            point.x = (int)targetObject->world_x;
            point.y = (int)targetObject->world_y;
            point.z = (int)targetObject->world_z;
            if (object->canPath(
                    point, object->weaponRange(), objectID, 0, 1, -1, -1) == 0)
                return;

            this->taskAttacker(unitID, targetObject->world_x,
                               targetObject->world_y, objectID,
                               (int)targetObject->owner->id, 0, 0, -1, 0);
            entryCount++;
            unitID = this->civilian(
                objectPosition, 1, 700, 0x2C9, 0x2C9, 1);
        }
    }
}
