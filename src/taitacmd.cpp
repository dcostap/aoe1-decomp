#include "../include/taitacmd.h"
#include "../include/taimdmd.h"
#include "../include/act_list.h"
#include "../include/act_obj.h"
#include "../include/aiblditm.h"
#include "../include/action.h"
#include "../include/taiinf_records.h"
#include "../include/xyz_point.h"
#include "../include/tplayer.h"
#include "../include/tworld.h"
#include "../include/command_waypoint.h"
#include "../include/game_globals.h"
#include "../include/m_s_obj.h"
#include "../include/obj_list.h"
#include "../include/path.h"
#include "../include/stat_obj.h"
#include "../include/unit_ai_module.h"
#include "../include/visible.h"
#include "../include/world.h"
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char uchar;
typedef unsigned long ulong;

extern "C" double __cdecl ceil(double);
extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl operator_delete(void*);
extern "C" unsigned long __cdecl debug_timeGetTime(const char*, int);
extern "C" int debug_rand(char*, int);
extern int __ftol();




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


TacticalAIGroup::~TacticalAIGroup() {}

// Deserializes struct fields with version-conditional reads
// Load has 4 float comparisons for backward compat: conditional field reads
//


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
    if (save_game_version >= DAT_005756e0) {
        rge_read(fd, &this->consecutiveGatherAttemptsValue, 1);
    } else {
        this->consecutiveGatherAttemptsValue = 0;
    }

    if (save_game_version >= DAT_005756e4) {
        rge_read(fd, &this->numberObjectsToDestroyValue, 4);
        rge_read(fd, &this->objectsToDestroyValue, 0x50);
        rge_read(fd, &this->objectsToDestroyOwnerValue, 4);
        rge_read(fd, &this->objectsToDestroyCommanderZoneValue, 4);
    }

    if (save_game_version >= DAT_005756e8) {
        rge_read(fd, &this->lastAttackRoundupTime, 4);
    }

    if (save_game_version >= DAT_005756ec) {
        rge_read(fd, &this->lastAddedUnitTimeValue, 4);
    }

    return 1;
}



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

// Getter: returns this->idValue at +0xC




int TacticalAIGroup::id() const
{
    return idValue;
}

void TacticalAIGroup::setID(int val) { this->idValue = val; }

int TacticalAIGroup::inUse() const { return this->inUseValue; }

void TacticalAIGroup::setInUse(int val) { this->inUseValue = val; }

int TacticalAIGroup::type() const { return this->typeValue; }

void TacticalAIGroup::setType(int val) { this->typeValue = val; }

int TacticalAIGroup::subType() const { return this->subTypeValue; }

void TacticalAIGroup::setSubType(int val) { this->subTypeValue = val; }






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




void TacticalAIGroup::removeUnits(TribeMainDecisionAIModule* md) {
    setSpecificCommander(-1, md);
    numberUnitsValue = 0;
    for (int i = 0; i < 40; i++) {
        unitsValue[i] = -1;
        unitsOriginalHitPointsValue[i] = -1;
    }
}




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


int TacticalAIGroup::containsUnit(int unitId) {
    for (int i = 0; i < 0x28; ++i) {
        if (this->unitsValue[i] == unitId) {
            return 1;
        }
    }
    return 0;
}

int TacticalAIGroup::numberUnits() { return this->numberUnitsValue; }


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

// Scans unitsValue array for the unit_index-th valid entry, returns corresponding HP


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

int TacticalAIGroup::desiredNumberUnits() const { return this->desiredNumberUnitsValue; }

void TacticalAIGroup::setDesiredNumberUnits(int val) { this->desiredNumberUnitsValue = val; }

int TacticalAIGroup::commander() const { return this->commanderValue; }





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

// first pass: 40-entry scan over unit ids, skipping -1 slots and summing floored hit points




int TacticalAIGroup::currentHitPoints(TribeMainDecisionAIModule* module) const {
    int total = 0;
    const int* unit = unitsValue;
    int remaining = 0x28;

    do {
        int unitId = *unit;
        if (unitId != -1) {
            RGE_Static_Object* object = module->object(unitId);
            if (object != 0) {
                total += (int)object->hp;
            }
        }
        ++unit;
    } while (--remaining != 0);

    return total;
}

int TacticalAIGroup::originalHitPoints() const { return this->originalHitPointsValue; }

void TacticalAIGroup::setOriginalHitPoints(int val) { this->originalHitPointsValue = val; }

int TacticalAIGroup::originalUnitNumber() const { return this->originalUnitNumberValue; }

void TacticalAIGroup::setOriginalUnitNumber(int val) { this->originalUnitNumberValue = val; }

const Waypoint & TacticalAIGroup::location() const { return this->locationValue; }


void TacticalAIGroup::setLocation(float a, float b, float c) {
    this->locationValue.x = a;
    this->locationValue.y = b;
    this->locationValue.z = c;
}

int TacticalAIGroup::action() const { return this->actionValue; }

void TacticalAIGroup::setAction(int val) { this->actionValue = val; }

int TacticalAIGroup::target() const { return this->targetValue; }

void TacticalAIGroup::setTarget(int val) { this->targetValue = val; }

int TacticalAIGroup::targetType() const { return this->targetTypeValue; }

void TacticalAIGroup::setTargetType(int val) { this->targetTypeValue = val; }

const Waypoint & TacticalAIGroup::targetLocation() const { return this->targetLocationValue; }

// From taitacmd.cpp
// The location fields are Waypoint float members in the canonical class.
// This preserves direct float stores in the grouped wrapper.


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


void TacticalAIGroup::setTargetLocation(float a, float b, float c) {
    this->targetLocationValue.x = a;
    this->targetLocationValue.y = b;
    this->targetLocationValue.z = c;
}

const Waypoint & TacticalAIGroup::gatherLocation() const { return this->gatherLocationValue; }


void TacticalAIGroup::setGatherLocation(float a, float b, float c) {
    this->gatherLocationValue.x = a;
    this->gatherLocationValue.y = b;
    this->gatherLocationValue.z = c;
}

const Waypoint & TacticalAIGroup::retreatLocation() const { return this->retreatLocationValue; }


void TacticalAIGroup::setRetreatLocation(float a, float b, float c) {
    this->retreatLocationValue.x = a;
    this->retreatLocationValue.y = b;
    this->retreatLocationValue.z = c;
}

int TacticalAIGroup::priority() const { return this->priorityValue; }

void TacticalAIGroup::setPriority(int val) { this->priorityValue = val; }

int TacticalAIGroup::waitCode() const { return this->waitCodeValue; }

void TacticalAIGroup::setWaitCode(int val) { this->waitCodeValue = val; }

int TacticalAIGroup::assistGroupID() const { return this->assistGroupIDValue; }

void TacticalAIGroup::setAssistGroupID(int val) { this->assistGroupIDValue = val; }

int TacticalAIGroup::assistGroupType() const { return this->assistGroupTypeValue; }

void TacticalAIGroup::setAssistGroupType(int val) { this->assistGroupTypeValue = val; }



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
    tactical->logGroupDebug(idValue, s_log_00, taskID, firstTime, busyOK);

    int commander = commanderValue;
    if (commander == -1) {
        tactical->logGroupDebug(idValue, s_no_commander);
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
        tactical->logGroupDebug(idValue, s_log_01);
        taskID = 0;
        for (i = 0; i < 40; ++i) {
            if (unitsValue[i] != -1) {
                tactical->logGroupDebug(idValue, s_log_02, unitsValue[i]);
                obj = md->object(unitsValue[i]);
                if (obj == 0 || obj->unitAI() == 0) {
                    tactical->logGroupDebug(idValue, s_log_03, unitsValue[i]);
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
        tactical->logGroupDebug(idValue, s_log_19);
        tactical->logGroupDebug(idValue, s_log_20, retreatLocationValue.x, retreatLocationValue.y);
        for (i = 0, unitp = unitsValue; i < 40; ++i, ++unitp) {
            if (*unitp == -1) continue;
            tactical->logGroupDebug(idValue, s_log_21, *unitp);
            obj = md->object(*unitp);
            if (obj == 0 || obj->unitAI() == 0) {
                tactical->logGroupDebug(idValue, s_log_22, *unitp);
                removeUnitByIndex(i, md);
                continue;
            }
            distance = obj->distance_to_position(retreatLocationValue.x, retreatLocationValue.y, retreatLocationValue.z) - 1.0f;
            if (distance < 0.0f) distance = 0.0f;
            if (distance < obj->master_obj->los * 0.33333334f) {
                tactical->logGroupDebug(idValue, s_log_24, *unitp);
            } else {
                tactical->logGroupDebug(idValue, s_log_23, *unitp);
                tactical->moveUnit(*unitp, retreatLocationValue.x, retreatLocationValue.y, 100);
            }
        }
        return 1;
    }




    case 7: {
        int* unitp;
        RGE_Static_Object* obj;
        tactical->logGroupDebug(idValue, s_log_32);
        taskID = 0;
        int roll = debug_rand(s_file, 0x3af) % 100;
        busyOK = 0;
        unitp = unitsValue;
        do {
            if (*unitp != -1) {
                tactical->logGroupDebug(idValue, s_log_33, *unitp);
                obj = md->object(*unitp);
                if (obj == 0 || obj->unitAI() == 0) {
                    tactical->logGroupDebug(idValue, s_log_34, *unitp);
                    removeUnitByIndex(busyOK, md);
                } else {
                    oHP = ((int)obj->hp);
                    unitp[40] = oHP;
                    taskID += oHP;
                    if (busyOK == 0 && obj->unitAI()->currentAction() != -1) {
                        int busyAction = obj->unitAI()->currentAction();
                        tactical->logGroupDebug(idValue, s_log_35, *unitp, busyAction);
                    } else if (*unitp == commanderValue) {
                        tactical->logGroupDebug(idValue, s_log_36, *unitp);
                        tactical->taskExplorer(*unitp, 0);
                    } else if (roll < tactical->strategicNumber(200)) {
                        tactical->logGroupDebug(idValue, s_log_37, *unitp);
                        tactical->taskDefender(*unitp, commanderValue, obj->master_obj->los * 0.5f, 99);
                    } else {
                        tactical->logGroupDebug(idValue, s_log_38, *unitp);
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
        tactical->logGroupDebug(idValue, s_log_39);
        taskID = 0;
        busyOK = 0;
        unitp = unitsValue;
        do {
            if (*unitp != -1) {
                tactical->logGroupDebug(idValue, s_log_40, *unitp);
                obj = md->object(*unitp);
                if (obj == 0 || obj->unitAI() == 0) {
                    tactical->logGroupDebug(idValue, s_log_41, *unitp);
                    removeUnitByIndex(busyOK, md);
                } else {
                    oHP = ((int)obj->hp);
                    unitp[40] = oHP;
                    taskID += oHP;
                    if (busyOK == 0 && obj->unitAI()->currentAction() != -1) {
                        int busyAction = obj->unitAI()->currentAction();
                        tactical->logGroupDebug(idValue, s_log_42, *unitp, busyAction);
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
        tactical->logGroupDebug(idValue, s_log_55, targetValue);
        tactical->logGroupDebug(idValue, s_log_56, targetLocationValue.x, targetLocationValue.y);
        int waited = (int)(md->player->world->world_time - lastAttackRoundupTime) / 1000;
        if (waited < 10) { tactical->logGroupDebug(idValue, s_log_57, waited); return 0; }
        tactical->logGroupDebug(idValue, s_log_58, waited);
        lastAttackRoundupTime = md->player->world->world_time;
        if (playNumberValue != -1) {
            tactical->logGroupDebug(idValue, s_log_59);
            return 0;
        }
        int stored20 = 0;
        busyOK = 0;
        int* unitp;
        RGE_Static_Object* obj;
        unitp = unitsValue;
        do {
            if (*unitp != -1) {
                tactical->logGroupDebug(idValue, s_log_60, *unitp);
                obj = md->object(*unitp);
                if (obj == 0 || obj->unitAI() == 0) {
                    tactical->logGroupDebug(idValue, s_log_61, *unitp);
                    removeUnitByIndex(busyOK, md);
                } else {
                    tactical->logGroupDebug(idValue, s_log_62, obj->unitAI()->currentAction());
                    oHP = ((int)obj->hp); unitp[40] = oHP; stored20 += oHP;
                    if (busyOK == 0 && obj->unitAI()->currentAction() != -1) {
                        tactical->logGroupDebug(idValue, s_log_63, *unitp);
                } else {
                    tactical->logGroupDebug(idValue, s_log_64, *unitp, subTypeValue);
                    if (subTypeValue == 0 || subTypeValue == 4) {
                            tactical->logGroupDebug(idValue, s_log_65, *unitp, targetValue);
                            tactical->taskDefender(*unitp, targetValue, 2.0f, 100);
                        } else {
                            RGE_Static_Object* targ20 = md->object(targetValue);
                            if (targ20 != 0) {
                                tactical->logGroupDebug(idValue, s_log_67, *unitp, targetValue);
                                tactical->taskAttacker(*unitp, targetLocationValue.x, targetLocationValue.y, targetValue, (int)targ20->owner->id, attackWaypoints, numberAttackWaypointsValue, commanderValue, 1);
                            } else {
                                // the shipped null-target log has no unit or target arguments.
                                tactical->logGroupDebug(idValue, s_log_66);
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
        tactical->logGroupDebug(idValue, s_log_04, targetValue);
        tactical->logGroupDebug(idValue, s_log_05, targetLocationValue.x, targetLocationValue.y);
        if (playNumberValue != -1)
            tactical->logGroupDebug(idValue, s_log_07, playNumberValue);
        else
            tactical->logGroupDebug(idValue, s_log_06);
        lastAttackRoundupTime = md->player->world->world_time;
        int stored = 0;
        int madeMemory = 1;
        int i;
        int* unitp;
        RGE_Static_Object* obj;
        for (i = 0, unitp = unitsValue; i < 40; ++i, ++unitp) {
            if (*unitp == -1) continue;
            tactical->logGroupDebug(idValue, s_log_08, *unitp);
            obj = md->object(*unitp);
            if (obj == 0 || obj->unitAI() == 0) {
                tactical->logGroupDebug(idValue, s_log_09, *unitp);
                removeUnitByIndex(i, md);
                continue;
            }
            // the null-test unitAI call is not cached for this read.
            int action = obj->unitAI()->currentAction();
            tactical->logGroupDebug(idValue, s_log_10, action);
            oHP = ((int)obj->hp); unitp[40] = oHP; stored += oHP;
            if (playNumberValue == -1) {
            if (busyOK == 0) {
                if (obj->unitAI()->currentAction() == 600 && obj->unitAI()->currentTargetType() != 0x1b) {
                    tactical->logGroupDebug(idValue, s_log_11, *unitp);
                    continue;
                }
            }
            tactical->logGroupDebug(idValue, s_log_12, *unitp, subTypeValue);
            if (subTypeValue == 0 || subTypeValue == 4) {
                tactical->logGroupDebug(idValue, s_log_13, *unitp);
                tactical->taskDefender(*unitp, targetValue, 2.0f, 100);
            } else {
                RGE_Static_Object* targ = md->object(targetValue);
                if (targ != 0) {
                    if (madeMemory) {
                        tactical->logGroupDebug(idValue, s_log_15);
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
                    tactical->logGroupDebug(idValue, s_log_16, *unitp, targetValue);
                    if (*unitp == commanderValue || tactical->importantGroupLeader(commanderValue) == 0 || tactical->strategicNumber(0x79) == 0) {
                        tactical->logGroupDebug(idValue, s_log_17);
                        if (taskID == 21)
                            tactical->moveUnit(*unitp, targetLocationValue.x, targetLocationValue.y, 100);
                        else
                            tactical->taskAttacker(*unitp, targetLocationValue.x, targetLocationValue.y, targetValue, (int)targ->owner->id, attackWaypoints, numberAttackWaypointsValue, commanderValue, 0);
                    } else {
                        tactical->logGroupDebug(idValue, s_log_18);
                        int range = tactical->strategicNumber(0x83);
                        tactical->taskDefender(*unitp, commanderValue, (float)range, 99);
                    }
                } else {
                    tactical->logGroupDebug(idValue, s_log_14);
                }
            }
            }
        }
        if (playNumberValue != -1) {
            int* list = (int*)operator new(numberUnitsValue << 2);
            if (list == 0) {
                tactical->logGroupDebug(idValue, s_attack_play_alloc_fail);
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
        tactical->logGroupDebug(idValue, s_log_25, targetValue, targetLocationValue.x, targetLocationValue.y);
        taskID = 0;
        busyOK = 0;
        unitp = unitsValue;
        do {
            if (*unitp != -1) {
                tactical->logGroupDebug(idValue, s_log_26, *unitp);
                obj = md->object(*unitp);
                if (obj == 0 || obj->unitAI() == 0) {
                    tactical->logGroupDebug(idValue, s_log_27, *unitp);
                    removeUnitByIndex(busyOK, md);
                } else {
                    oHP = ((int)obj->hp);
                    unitp[40] = oHP;
                    taskID += oHP;
                    if (busyOK == 0 && obj->unitAI()->currentAction() != -1) {
                        int busyAction = obj->unitAI()->currentAction();
                        tactical->logGroupDebug(idValue, s_log_28, *unitp, busyAction);
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
        tactical->logGroupDebug(idValue, s_log_43);
        taskID = 0;
        busyOK = 0;
        unitp = unitsValue;
        do {
            if (*unitp != -1) {
                tactical->logGroupDebug(idValue, s_log_44, *unitp);
                obj = md->object(*unitp);
                if (obj == 0 || obj->unitAI() == 0) {
                    tactical->logGroupDebug(idValue, s_log_45, *unitp);
                    removeUnitByIndex(busyOK, md);
                } else {
                    oHP = ((int)obj->hp);
                    unitp[40] = oHP;
                    taskID += oHP;
                    if (busyOK == 0 && obj->unitAI()->currentAction() != -1) {
                        int busyAction = obj->unitAI()->currentAction();
                        tactical->logGroupDebug(idValue, s_log_46, *unitp, busyAction);
                    } else if (*unitp == commanderValue) {
                        tactical->logGroupDebug(idValue, s_log_47, *unitp);
                        tactical->taskWaterFisher(*unitp, targetValue, targetLocationValue.x, targetLocationValue.y);
                    } else {
                        tactical->logGroupDebug(idValue, s_log_48, *unitp);
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
        tt->logGroupDebug(idValue, s_log_49);
        busyOK = 0;
        unitp = unitsValue;
        do {
            if (*unitp != -1) {
                tt->logGroupDebug(idValue, s_log_50, *unitp);
                obj = md->object(*unitp);
                if (obj == 0 || obj->unitAI() == 0) {
                    tt->logGroupDebug(idValue, s_log_51, *unitp);
                    removeUnitByIndex(busyOK, md);
                } else {
                    oHP = ((int)obj->hp);
                    unitp[40] = oHP;
                    total += oHP;
                    if (busyOK == 0 && obj->unitAI()->currentAction() != -1) {
                        int busyAction = obj->unitAI()->currentAction();
                        tt->logGroupDebug(idValue, s_log_52, *unitp, busyAction);
                    } else if (*unitp == commanderValue) {
                        tt->logGroupDebug(idValue, s_log_53, *unitp);
                        tt->taskWaterTrader(*unitp, targetValue);
                    } else {
                        tt->logGroupDebug(idValue, s_log_54, *unitp);
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
        tactical->logGroupDebug(idValue, s_log_29);
        taskID = 0;
        busyOK = 0;
        unitp = unitsValue;
        do {
            if (*unitp != -1) {
                tactical->logGroupDebug(idValue, s_log_30, *unitp);
                obj = md->object(*unitp);
                if (obj == 0 || obj->unitAI() == 0) {
                    tactical->logGroupDebug(idValue, s_log_31, *unitp);
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
    tactical->logGroupDebug(idValue, s_unknown_task, taskID);
    goto return_zero_tail;


store_return_one_zero_waypoints:
    originalHitPointsValue = taskID;
    originalUnitNumberValue = numberUnitsValue;
    numberAttackWaypointsValue = 0;
    return 1;

}






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

unsigned long TacticalAIGroup::consecutiveIdleUnitCount() const { return this->consecutiveIdleUnitCountValue; }

void TacticalAIGroup::setConsecutiveIdleUnitCount(unsigned long val) { this->consecutiveIdleUnitCountValue = val; }


void TacticalAIGroup::incrementConsecutiveIdleUnitCount(unsigned long value) {
    this->consecutiveIdleUnitCountValue += value;
}

unsigned char TacticalAIGroup::numberAttackWaypoints() const { return this->numberAttackWaypointsValue; }

unsigned char TacticalAIGroup::currentAttackWaypoint() const { return this->currentAttackWaypointValue; }


void TacticalAIGroup::setCurrentAttackWaypoint(unsigned char wp)
{
    if (wp < this->numberAttackWaypointsValue)
        this->currentAttackWaypointValue = wp;
}



void TacticalAIGroup::addAttackWaypoint(float x, float y)
{
    if (this->numberAttackWaypointsValue < 14) {
        this->attackWaypoints[this->numberAttackWaypointsValue].x = x;
        this->attackWaypoints[this->numberAttackWaypointsValue].y = y;
        this->attackWaypoints[this->numberAttackWaypointsValue].z = 1.0f;
        this->numberAttackWaypointsValue = this->numberAttackWaypointsValue + 1;
    }
}

Waypoint* TacticalAIGroup::attackWaypoint(unsigned char index) {
    if (index < this->numberAttackWaypointsValue)
        return this->attackWaypoints + index;
    return 0;
}


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

int TacticalAIGroup::objectToDestroy(int index) {
    if (index < 0 || index >= 20) return -1;
    return this->objectsToDestroyValue[index];
}

int TacticalAIGroup::addObjectToDestroy(int objectId) {
    if (this->numberObjectsToDestroyValue < 0x13) {
        this->objectsToDestroyValue[this->numberObjectsToDestroyValue] = objectId;
        this->numberObjectsToDestroyValue = this->numberObjectsToDestroyValue + 1;
        return 1;
    }
    return 0;
}



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
        this->neededResourceValue[iVar2] = -1;
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
      OldUnitData oldUnitData;

      do {
        rge_read(file,&oldUnitData,0x10);
        ((UnitData *)(piVar2 + -1))->id = oldUnitData.id;
        *piVar2 = oldUnitData.data1;
        piVar2[1] = oldUnitData.data2;
        piVar2[2] = oldUnitData.data3;
        piVar2[3] = -1;
        piVar2[4] = 0;
        piVar2 = piVar2 + 6;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    else {
      OldUnitData2 oldUnitData;

      do {
        rge_read(file,&oldUnitData,0x14);
        ((UnitData *)(piVar2 + -1))->id = oldUnitData.id;
        *piVar2 = oldUnitData.data1;
        piVar2[1] = oldUnitData.data2;
        piVar2[2] = oldUnitData.data3;
        piVar2[3] = oldUnitData.target;
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



TribeTacticalAIModule::~TribeTacticalAIModule()
{
    this->removeAllGroups(-1);
}



char* TribeTacticalAIModule::updateAreaName()
{
    switch (this->updateArea) {
    case 0: return "Setup SolGroups";
    case 1: return "Eval CivDist";
    case 2: return "Task Civs";
    case 3: return "Setup BoatGroups";
    case 4: return "Fill BoatGroups";
    case 5: return "Task Boats";
    case 6: return "Fill SolGroups";
    case 7: return "Task IdleSol";
    case 8: return "Task ActSol";
    case 9: return "Playtasking";
    case 10: return "Task UngrpSol";
    case 11: return "Research";
    case 12: return "Train";
    case 13: return "BldLst Change";
    case 14: return "Help Build";
    case 15: return "Repair Bldg";
    case 16: return "Repair Wall";
    case 17: return "Build";
    case 18: return "Open Builds";
    case 19: return "Open Tasks";
    case 20: return "Food dropsite";
    case 21: return "BldLst Insertions";
    default: return "Invalid";
    }
}



// These three target insertions inline growth and emit direct
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

    // This period array method preserves the md reread below.
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

void TribeTacticalAIModule::setMainDecisionAI(TribeMainDecisionAIModule* val) { this->md = val; }


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
        ManagedArray<int>& arr = this->civilians;
        do {
            tempInt = arr[i];
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
        ManagedArray<int>& arr = this->civilianExplorers;
        do {
            tempInt = arr[i];
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
        ManagedArray<int>& arr = this->soldiers;
        do {
            tempInt = arr[i];
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
        ManagedArray<int>& arr = this->ungroupedSoldiers;
        do {
            tempInt = arr[i];
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

void __cdecl TribeTacticalAIModule::logGroupDebug(int, char*, ...) {}


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
    startTime = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\taitacmd.cpp", 0x99C);

    if (availableTime > 0) {
        do {
            updateAreaStartTime = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\taitacmd.cpp", 0x99F);
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
                // Wrap as unsigned, then use signed age division.
                if (5 < (int)(this->md->player->world->world_time -
                              this->lastBuildTime) / 60000) {
                    this->md->buildAI.unskipBuildList(this->builtFirstStoragePit,
                                                       this->builtFirstGranary);
                    this->lastBuildTime = this->md->player->world->world_time;
                }

                currentTime = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\taitacmd.cpp", 0xB92);
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

            currentTime = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\taitacmd.cpp", 0xBAA);
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

    currentTime = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\taitacmd.cpp", 0xBC9);
    this->md->player->world->useComputerPlayerUpdateTime(currentTime - startTime);
    return 1;
}



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



void TribeTacticalAIModule::addObject(RGE_Static_Object* obj)
{
    short group = obj->master_obj->object_group;
    int id;
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
            // This call stays out of line. Later add calls inline.
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
            if (list->contains(id) != 1) {
                (*list)[list->numberValue] = id;
                list->numberValue++;
            }
        }

        if (obj->master_obj->object_group == 0x16) {
            id = obj->id;
            list = &this->warBoats;
            if (list->contains(id) != 1) {
                (*list)[list->numberValue] = id;
                list->numberValue++;
            }
        }

        if (obj->master_obj->object_group == 0x15) {
            id = obj->id;
            list = &this->fishingBoats;
            if (list->contains(id) == 1)
                return;
            (*list)[list->numberValue] = id;
            list->numberValue++;
        }
    }
}



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
    numberItems = this->md->informationAI.numberGameIDsOwnedBy(-1, (*list)[0]);

    if (this->civilians.numberValue >= 3) {
    list = &this->civilians;
    if (this->md->informationAI.fullyExploredZone((*list)[0]) == 1) {
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
            // Reread the count before publishing explorer demand.
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
        this->nextCivilianToTaskValue = (*civilianList)[0];
        if (debug_timeGetTime("C:\\msdev\\work\\age1_x1\\taitacmd.cpp", 0x0D8A) - param_1 >= param_2) {
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
        if (debug_timeGetTime("C:\\msdev\\work\\age1_x1\\taitacmd.cpp", 0x0DC6) - param_1 >= param_2) {
            if (i > 0) {
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
        if (debug_timeGetTime(s_file, 0xEA9) - startTime >=
            maxTime) {
            return;
        }
    }

    this->nextIdleSoldierGroupToTaskValue = -1;
}



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
                        targetTile, commanderObj->weaponRange(), 1);
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
                                    this->logCommonHistory("    Unit %d is invalid.");
                                } else {
                                    ai = unitObj2->unitAI();
                                    if (ai == 0) {
                                        this->logCommonHistory("    Unit %d has invalid unitAI.");
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
                                if (this->md->informationAI.findStagingPoint(targetPoint, staging, 1, 1, cur->target(), 0x0f, cur->commander()) == 0) {
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
                        RGE_Action_Object* transportObj;
                        transportObj = static_cast<RGE_Action_Object*>(
                            this->md->object(assist->commander()));
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
                                                if (unitObj2->unitAI()->canAttackUnit(
                                                            targetObj) == 1) {
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
                                    RGE_Static_Object* attackTarget;
                                    commanderObjT = this->md->object(cur->commander());
                                    if (commanderObjT == 0) {
                                        goto action10_attack_failure;
                                    } else {
                                        attackTarget = this->md->object(cur->target());
                                        if (attackTarget != 0 &&
                                            commanderObjT->unitAI()->canAttackUnit(
                                                attackTarget) == 1) {
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
                            p1 = this->md->strategyAI.targetPoint1();
                            p2 = this->md->strategyAI.targetPoint2();
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
                                } else {
                                    RGE_Static_Object* attackTarget =
                                        this->md->object(cur->target());
                                    if (attackTarget != 0 &&
                                        commanderObj4->unitAI()->canAttackUnit(
                                            attackTarget) == 1) {
                                    cur->task(this, this->md, 0x14, 0, 1);
                                    this->attackStateValue.active = 0;
                                    goto ContinueLoop;
                                    }
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
            if (debug_timeGetTime(s_file, 0x14fe) - param_1 >= param_2) {
                return;
            }
        } while (cur != &this->groups);
    }
    this->nextActiveSoldierGroupToTaskValue = -1;
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
                countUnplayedSoldiers, unplayedSoldiers[0], playUnits + 1,
                playCommander, playToRun);
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
                        RGE_Action_Object* actionObject =
                            static_cast<RGE_Action_Object*>(commander);
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


void TribeTacticalAIModule::evaluateOpenTasks()
{
    int i;

    i = 0;
    if (this->civilians.numberValue > 0) {
        ManagedArray<int>* civilians = &this->civilians;
        do {
            RGE_Static_Object* object =
                this->md->player->world->object((*civilians)[i]);
            if (object != 0) {
                UnitAIModule* unitAI = object->unitAI();
                if (unitAI != 0) {
                    ManagedArray<int>* unitsTasked =
                        &this->unitsTaskedThisUpdate;
                    if (unitsTasked->contains((*civilians)[i]))
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
                                this->stopUnit((*civilians)[i], 100);
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
                            assistObject->objects->number_of_objects > 0) {
                            assistGroup->setAction(0xF);
                        }
                    }
                }
            }

            group = group->next;
    }
}


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

int TribeTacticalAIModule::numberCivilians() const {
    return this->civilians.numberValue;
}

int TribeTacticalAIModule::numberCivilianExplorers() const {
    return this->civilianExplorers.numberValue;
}

int TribeTacticalAIModule::numberGatherers() const {
    return this->numberGatherersValue;
}

int TribeTacticalAIModule::desiredNumberCivilianExplorers() const {
    return this->civilianExplorers.desiredNumberValue;
}

int TribeTacticalAIModule::desiredNumberGatherers() const {
    return this->desiredNumberGatherersValue;
}

int TribeTacticalAIModule::numberSoldiers() const {
    return this->soldiers.numberValue;
}

// The body calls TribeTacticalAIModule::numberUnitsInGroups(0x66).

int TribeTacticalAIModule::numberSoldierExplorers()
{
    return this->numberUnitsInGroups(0x66);
}

int TribeTacticalAIModule::numberBoats() const {
    return this->boats.numberValue;
}


int TribeTacticalAIModule::neededResource(int index) const {
    if (index < 0 || index >= 4) return -1;
    return this->neededResourceValue[index];
}



int TribeTacticalAIModule::neededResourceAmount(int index) const {
    if (index >= 0 && index < 4)
        return this->neededResources.value(this->neededResourceValue[index]);
    return -1;
}




void TribeTacticalAIModule::detask(int unitId) {
    if (unitId == -1) {
        this->logCommonHistory((char*)"ERROR DETASKING Unit #%d!", unitId);
        return;
    }
    removeFromTaskLists(unitId);
    stopUnit(unitId, 0x64);
}


int TribeTacticalAIModule::strategicNumber(int index) {
    if (index < 0 || index >= 226)
        return -1;
    return sn[index];
}





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

    entryTime = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\taitacmd.cpp", 0x1904);

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
                debug_timeGetTime("C:\\msdev\\work\\age1_x1\\taitacmd.cpp", 0x1A54) - entryTime < 0xB)) {
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


int TribeTacticalAIModule::numberSoldiersWithPriority(int threshold, int priority, int reset)
{
    TribeTacticalAIModule* self = this;
    ManagedArray<int>& workingArea = self->workingArea;
    int rNum = 0;

    if (reset == 1)
        workingArea.numberValue = 0;

    reset = 0;
    if (0 < self->soldiers.numberValue) {
        ManagedArray<int>& soldiers = self->soldiers;
        do {
            RGE_Static_Object* object =
                self->md->aiPlayer->world->object(soldiers[reset]);
            if ((object != 0) && (object->unitAI() != 0)) {
                int taskedNumber = self->unitsTaskedThisUpdate.numberValue;
                int taskedIndex = 0;
                if (0 < taskedNumber) {
                    for (;
                         taskedIndex < taskedNumber &&
                         taskedIndex < self->unitsTaskedThisUpdate.maximumSizeValue;
                         taskedIndex++) {
                        if (self->unitsTaskedThisUpdate[taskedIndex] ==
                            soldiers[reset])
                            goto nextSoldier;
                    }
                }

                int value;
                if (priority < 0) {
                    if (object->unitAI()->currentAction() != -1) {
                        if (object->unitAI()->currentOrderPriority() >= threshold)
                            goto nextSoldier;
                    }

                    value = soldiers[reset];
                    int index = 0;
                    if (0 < workingArea.numberValue) {
                        for (;
                             index < workingArea.numberValue &&
                             index < workingArea.maximumSizeValue;
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
                            value = soldiers[reset];
                            int index = 0;
                            if (0 < workingArea.numberValue) {
                                for (;
                                     index < workingArea.numberValue &&
                                     index < workingArea.maximumSizeValue;
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
                                workingArea.add(value);
                            }
                            rNum = rNum + 1;
                        }
                    }
                    goto nextSoldier;
                }
appendWorking:
                workingArea.add(value);
countedSoldier:
                rNum = rNum + 1;
            }
nextSoldier:
            reset = reset + 1;
        } while (reset < soldiers.numberValue);
    }
    return rNum;
}


int TribeTacticalAIModule::numberWarshipsWithPriority(int priority, int compare)
{
    ManagedArray<int>* warships;
    ManagedArray<int>* result;
    short objectGroup;
    RGE_Static_Object* object;
    UnitAIModule* ai;
    int value;
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
            object = this->md->aiPlayer->world->object((*warships)[local_c]);
            if (object != 0 && object->unitAI() != 0) {
                value = 0;
                if (this->unitsTaskedThisUpdate.numberValue > 0) {
                    do {
                        if (this->unitsTaskedThisUpdate.maximumSizeValue <= value)
                            break;
                        if (this->unitsTaskedThisUpdate[value] ==
                            (*warships)[local_c])
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
                    result = &this->workingArea;
                    local_8 = (*warships)[local_c];
                    value = result->contains(local_8);
                    if (value != 1) {
                        (*result)[result->numberValue] = local_8;
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
                        result = &this->workingArea;
                        local_8 = (*warships)[local_c];
                        value = result->contains(local_8);
                        if (value != 1) {
                            (*result)[result->numberValue] = local_8;
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
                        result = &this->workingArea;
                        local_8 = (*warships)[local_c];
                        value = result->contains(local_8);
                        if (value != 1) {
                            (*result)[result->numberValue] = local_8;
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
            object = tactical2->md->aiPlayer->world->object((*warships)[local_c]);
            if (object != 0 && object->unitAI() != 0) {
                value = tactical2->unitsTaskedThisUpdate.numberValue;
                index = 0;
                tactical = tactical2;
                if (value > 0) {
                    do {
                        if (tactical->unitsTaskedThisUpdate.maximumSizeValue <= index)
                            break;
                        tactical = local_4;
                        if (tactical2->unitsTaskedThisUpdate[index] == (*warships)[local_c])
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
                        value = tactical2->workingArea.numberValue;
                        scan = 0;
                        local_8 = (*warships)[local_c];
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
                                value = tactical2->workingArea.numberValue;
                                scan = 0;
                                local_8 = (*warships)[local_c];
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

                            result = &tactical2->workingArea;
                            local_8 = (*warships)[local_c];
                            value = result->contains(local_8);
                            if (value != 1) {
                                (*result)[result->numberValue] = local_8;
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
                tactical2->workingArea[tactical2->workingArea.numberValue] = local_8;
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



int TribeTacticalAIModule::idleCivilian(int mode)
{
    RGE_Static_Object* firstObject;
    RGE_Static_Object* secondObject;
    int i = 0;
    ManagedArray<int>& tasked = this->unitsTaskedThisUpdate;
    if (this->civilians.numberValue > 0) {
        ManagedArray<int>* civilians = &this->civilians;
        do {
            if (tasked.contains((*civilians)[i]) != 0)
                goto first_next;

            firstObject =
                this->md->player->world->object((*civilians)[i]);
            if ((firstObject != 0) && (firstObject->unitAI() != 0)) {
                if (this->isGatherer((*civilians)[i]) == 0) {
                    if (this->civilianExplorers.contains((*civilians)[i]) != 0)
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
            if (this->unitsTaskedThisUpdate.contains((*civilians)[i]) != 0)
                goto second_next;

            secondObject =
                this->md->player->world->object((*civilians)[i]);
            if ((secondObject != 0) && (secondObject->unitAI() != 0)) {
                if (mode != 0) {
                    if (mode != 3) {
                        if (this->isGatherer((*civilians)[i]) != 0)
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
            if (this->unitsTaskedThisUpdate.contains((*civilians)[i]) != 0)
                continue;

            firstObj = this->md->player->world->object((*civilians)[i]);
            if ((firstObj != 0) && (firstObj->unitAI() != 0)) {
                if (this->isGatherer((*civilians)[i]) == 0) {
                    if (this->civilianExplorers.contains((*civilians)[i]) != 0)
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
            if (this->unitsTaskedThisUpdate.contains((*civilians)[i]) != 0)
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
                    if (this->civilianExplorers.contains((*civilians)[i]) != 0)
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


int TribeTacticalAIModule::civilian(XYPoint& pos, int chooseMode, int order1, int order2, int order3, int allow103)
{
    float bestUnitDistance;
    int bestUnitID;
    int i;
    RGE_Static_Object* obj;
    ManagedArray<int>& civilians = this->civilians;
    ManagedArray<int>& tasked = this->unitsTaskedThisUpdate;

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



int TribeTacticalAIModule::unit(int player, int currentAction, int currentTargetType)
{
    int i = 0;
    ManagedArray<int>* resultArray;

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
    return (*resultArray)[i];

}

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


void TribeTacticalAIModule::displayCivilianDistribution()
{
}


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

    this->md->buildAI.mostNeededResource(this->neededResources, this->sn[0x93]);

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
            if (this->md->buildAI.readyToResearch(2,1) && this->md->informationAI.closestDropsiteValue[0]!=-1 && (this->md->resourceAI.resource(1)>120 || builtFirstGranary==1)) {
                *distribution=desiredNumberGatherersValue;
                g=&gatherers[0].data1;
                for (i=0;i<numberGatherersValue;i++,g+=6) if (g[0]!=0 && g[0]!=-1) g[1]=5;
                this->zoomingToNextAge=1;
                special=1;
            } else {
                this->zoomingToNextAge=0;
                distribution[1]=desiredNumberGatherersValue;
                special=1;
            }
        } else this->zoomingToNextAge=0;
    } else if (inAge(2)) {
        if (this->sn[0xB6]==1) {
            if (this->md->buildAI.readyToResearch(3,1) && (this->md->resourceAI.resource(1)>240 || (this->md->resourceAI.resource(1)>120 && this->md->informationAI.closestDropsiteValue[0]<20))) {
                *distribution=desiredNumberGatherersValue;
                g=&gatherers[0].data1;
                for (i=0;i<numberGatherersValue;i++,g+=6) if (g[0]!=0 && g[0]!=-1) g[1]=5;
                this->zoomingToNextAge=1;
                special=1;
            } else {
                this->zoomingToNextAge=0;
                distribution[1]=desiredNumberGatherersValue;
                special=1;
            }
        } else this->zoomingToNextAge=0;
    } else if (inAge(3)) {
        if (this->sn[0xB7]==1) {
            if (this->md->buildAI.readyToResearch(4,1)) {
                *distribution=desiredNumberGatherersValue/2;
                distribution[3]=distribution[0];
                g=&gatherers[0].data1;
                for (i=0;i<numberGatherersValue;i++,g+=6) if (g[0]!=0 && g[0]!=3 && g[0]!=-1) g[1]=5;
                this->zoomingToNextAge=1;
                special=1;
            } else {
                *distribution=desiredNumberGatherersValue/3;
                distribution[1]=distribution[0];
                distribution[3]=distribution[0];
                this->zoomingToNextAge=0;
                special=1;
            }
        } else this->zoomingToNextAge=0;
    } else this->zoomingToNextAge=0;

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


int TribeTacticalAIModule::stopUnit(int param_1, int param_2) {
    RGE_Player* player = this->md->player;
    player->sendUnitAIOrder((int)player->id, param_1, 0x2C2, -1, -1,
        -1.0f, -1.0f, -1.0f, -1.0f, 1, 0, param_2);
    return 1;
}

// moveUnit sends the order through md->unit with the player's id.

int TribeTacticalAIModule::moveUnit(int param_1, float param_2, float param_3, int param_4) {
    RGE_Player* player = this->md->player;
    player->sendUnitAIOrder((int)player->id, param_1, 0x2C6, -1, -1,
                            param_2, param_3, 1.0f, 1.0f, 1, 0, param_4);
    return 1;
}

int TribeTacticalAIModule::groupGatherUnit(int param_1, int param_2, float param_3, float param_4, float param_5, float param_6, int param_7) {
    RGE_Player* player = this->md->player;
    player->sendUnitAIOrder((int)player->id, param_1, 0x2D4, param_2, -1,
                            param_3, param_4, param_5, param_6, 1, 0, param_7);
    return 1;
}


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

    now = debug_timeGetTime(s_file, 0x1F5C);
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

    // The found record remains live through all later task calls.
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
    if (this->inAge(1) != 0 && this->sn[0xB5] == 1) {
        triedTasking[1] = 1;
    } else if (this->inAge(2) != 0 && this->sn[0xB6] == 1 && triedTasking[1] == 0) {
        task = 0;
        triedTasking[1] = 1;
    } else if (this->inAge(3) != 0 && this->sn[0xB7] == 1) {
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

    ManagedArray<int>& arr = this->unitsTaskedThisUpdate;
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
    XYZPoint p; p.x = tx; p.y = ty; p.z = tz; if (obj->canPath(p, 2.0f, -1, 0, 1, -1, -1) == 0) {
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
    this->md->aiPlayer->buildObject(id, con->typeID(), con->x(), con->y(), item->uniqueID());
    if (con != 0) delete con;
    return 1;
}



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

    ManagedArray<int>& arr = this->unitsTaskedThisUpdate;
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



int TribeTacticalAIModule::taskRepairer(int id, RGE_Static_Object* repairer)
{
    RGE_Static_Object* object = this->md->player->world->object(id);
    if (object == 0) {
        return 0;
    }

    if (object->canPath(repairer->id, 1.0f, 0, 1, -1, -1) == 0) {
        return 0;
    }

    ManagedArray<int>& arr = this->unitsTaskedThisUpdate;
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
                        resourceType, p1, drop1, drop2, numStorage, exclusions + 1, 0);
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
                    resourceType, p1, drop1, drop2, numStorage, exclusions + 1, index);
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
        ManagedArray<int>& farms = this->md->informationAI.farmsTaskedThisUpdate;
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


int TribeTacticalAIModule::taskExplorer(int param_1, int param_2)
{
    ManagedArray<int>& arr = this->unitsTaskedThisUpdate;
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

//
//   ManagedArray ownership and the neighboring taskExplorer overload's
//   only two FPU operand-displacement bytes differing.
//   right-to-left evaluation and the observed y-then-x FPU pushes.

int TribeTacticalAIModule::taskExplorer(int param_1, float param_2,
                                        float param_3)
{
    ManagedArray<int>& arr = this->unitsTaskedThisUpdate;
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
        ManagedArray<int>& civiliansArray = civilians;
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
            ManagedArray<int>& civiliansArray = this->civilians;
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



int TribeTacticalAIModule::taskFollower(int param_1, int param_2, float param_3, int param_4) {
    ManagedArray<int>& arr = this->unitsTaskedThisUpdate;
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


int TribeTacticalAIModule::taskDefender(int param_1, int param_2, float param_3, int param_4)
{
    ManagedArray<int>& arr = this->unitsTaskedThisUpdate;
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


void* __cdecl operator_new(unsigned int size);
void __cdecl operator_delete(void* ptr);

// ManagedArray<int> layout
int TribeTacticalAIModule::taskWaterExplorer(int param_1) {
    if (param_1 == -1) {
        return 0;
    }

    ManagedArray<int>& arr = this->unitsTaskedThisUpdate;
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

// __thiscall, returns 0/1
//
//   owner/player, aiPlayer::taskResourceGatherer, and ManagedArray surfaces.
//   then the player is recorded and taskResourceGatherer is dispatched with
//   the target owner's id.

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

    ManagedArray<int>& arr = this->unitsTaskedThisUpdate;
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

    ManagedArray<int>& arr = this->unitsTaskedThisUpdate;
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

    ManagedArray<int>& arr = this->unitsTaskedThisUpdate;
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

int TribeTacticalAIModule::taskDefender(int groupId, int defenderId) {
    this->logCommonHistory((char*)"ERROR: Unused taskDefender call 1: defender ID=%d group=%d\n",
                           groupId, defenderId);
    return 0;
}

int TribeTacticalAIModule::taskDefender(int groupId, float x, float y) {
    this->logCommonHistory((char*)"ERROR: Unused taskDefender call 2: defender ID=%d to (%f, %f)\n",
                           groupId, (double)x, (double)y);
    return 0;
}


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
    ManagedArray<int>& arr = this->unitsTaskedThisUpdate;
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

    ManagedArray<int>& arr = this->unitsTaskedThisUpdate;
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


int TribeTacticalAIModule::taskToEnter(int param_1, int param_2)
{
    ManagedArray<int>& arr = this->unitsTaskedThisUpdate;
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

// __thiscall, int, ret 0Ch
//
//   MainDecision object lookup, distance/priority calls, this->unitsTaskedThisUpdate
//   ManagedArray growth, and typed player slot-0x30 dispatch.
//   RGE_Player slot-0x30 signature; generic proxy naming was removed.

int TribeTacticalAIModule::taskTransporter(int playerID, float x, float y)
{
    RGE_Static_Object* object = this->md->object(playerID);
    if (playerID == -1 || object == 0) {
        return 0;
    }

    float distance = object->distance_to_position(x, y, 1.0f);
    int priority = this->calculatePriority(distance);

    ManagedArray<int>& arr = this->unitsTaskedThisUpdate;
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

int TribeTacticalAIModule::calculatePriority(float value) {
    int priority;

    priority = (int)((float)this->sn[0x22] / value);
    if (priority > 99) {
        priority = 99;
    }
    return priority;
}


void TribeTacticalAIModule::setupSoldierGroups()
{
    ManagedArray<int> groupsToRemove;
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


int TribeTacticalAIModule::numberUngroupedArtifacts()
{
    int rNum = 0;
    int i = 0;
    ManagedArray<int>& workingArea = this->workingArea;
    ManagedArray<int>& artifacts = this->artifacts;

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
                this->logCommonHistory("    Target=%d (%s), CommanderID=%d, HP(%d/%d), WaitCode=%d.", g->target(), object->master_obj->name, g->commander(), g->currentHitPoints(this->md), g->originalHitPoints(), g->waitCode());
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
                    else this->logCommonHistory("      ObjectToDestroy #%d:  Unit #%d (%s).", i, g->objectToDestroy(i), object->master_obj->name);
                }
            }
            for (int i = 0; i < g->numberUnits(); ++i) {
                object = this->md->object(g->unit(i));
                if (!object) {
                    this->logCommonHistory("    Unit %d is invalid.");
                } else if (!object->unitAI()) {
                    this->logCommonHistory("    Unit %d has invalid unitAI.");
                } else {
                            this->logCommonHistory("    Unit %d (%s): state=%d, action=%d, target=%d, order=%d, pri=%d, loc=(%3f, %3f), tLoc=(%3f, %3f).", g->unit(i), object->master_obj->name, object->object_state, object->unitAI()->currentAction(), object->unitAI()->currentTarget(), object->unitAI()->currentOrder(), object->unitAI()->currentOrderPriority(), object->world_x, object->world_y, object->unitAI()->currentTargetX(), object->unitAI()->currentTargetY());
                    if (object->unitAI()->currentTarget() != -1) {
                        object = this->md->object(object->unitAI()->currentTarget());
                        if (object) this->logCommonHistory("      Target: %s, Owner=%d.", object->master_obj->name, object->owner->id);
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


void TribeTacticalAIModule::setupBoatGroups()
{
    ManagedArray<int> groupsToRemove;
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

    if (this->sn[0x28] == 0) {
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
                        if (type == 0x67 && candidate->numberUnits() >= this->sn[0x3C]) {
                            candidate = candidate->next;
                            continue;
                        }
                        type = candidate->type();
                        if (type == 0x68 && candidate->numberUnits() >= this->sn[0x45]) {
                            candidate = candidate->next;
                            continue;
                        }
                        type = candidate->type();
                        if (type == 0x69 && candidate->numberUnits() >= this->sn[0x3F]) {
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

int TribeTacticalAIModule::addToGroup(int groupId, int unitId) {
    TacticalAIGroup* grp = group(unitId, -1, -1, -1);
    if (!grp)
        return 0;
    return grp->addUnit(groupId, this->md);
}


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

int TribeTacticalAIModule::itemToCapture(void) {
    int targetId;

    if (this->md->strategyAI.currentVictoryCondition() == 0) {
        targetId = this->md->strategyAI.targetID();
        if (this->group(-1, -1, -1, targetId) == 0) {
            return targetId;
        }
    }
    return -1;
}

int TribeTacticalAIModule::itemToBringToArea()
{
    int target;

    if (this->md->strategyAI.currentVictoryCondition() == 4) {
        target = this->md->strategyAI.secondTargetID();
        if (this->group(-1, -1, -1, target) == 0)
            return target;
    }
    return -1;
}


int TribeTacticalAIModule::numberItemsToDefend()
{
    return this->md->informationAI.numberItemsToDefend();
}

// TribeTacticalAIModule::attackLimiterTime


unsigned long TribeTacticalAIModule::attackLimiterTime(int param_1) {
    if (this->sn[0x47] == 1) {
        int val = this->randomizedAttackSeparationTime;
        int limit = this->sn[0x30];
        if (val < limit) {
            return val;
        }
        return limit;
    } else {
        if (param_1 == 0x2E) {
            return this->randomizedAttackSeparationTime;
        }
        return this->sn[0x30];
    }
}


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
        this->sn[0x16], this->sn[0x48], obj, gatherPoint);
    if (result == 1) {
        group->setGatherLocation((float)gatherPoint.x,
                                 (float)gatherPoint.y, obj->world_z);
        return 1;
    }
    group->setGatherLocation(obj->world_x, obj->world_y, obj->world_z);
    return 1;
}



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
            this->sn[0x16], this->sn[0x48], obj, gatherPoint);
        if (result == 1) {
            group->setAllLocations((float)gatherPoint.x,
                                   (float)gatherPoint.y, obj->world_z);
            return 1;
        }
    }

    group->setAllLocations(obj->world_x, obj->world_y, obj->world_z);
    return 1;
}



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
                    if (self->sn[0x4B] == 2) {
                        score = (int)obj->weaponRange();
                    }
                    else {
                        score = (int)obj->hp;
                    }
                    mode = self->sn[0x4B];
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


int TribeTacticalAIModule::selectBestCommander(ManagedArray<int>& a)
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



void TribeTacticalAIModule::addWaypoint(int id, unsigned char a, unsigned char b) {
    XYZBYTEPoint info;

    info.x = a;
    info.y = b;
    info.z = 1;
    this->md->player->sendAddWaypointCommand(id, &info, 1);
}

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

void TribeTacticalAIModule::enableAttack(int param) {
    if (this->attackEnabledValue == 1)
        return;
    int field3AC = this->sn[0x86];
    if (field3AC != 0 && field3AC != param)
        return;
    this->attackEnabledValue = 1;
}


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
    return this->md->informationAI.unexploredPlayerLocation(player, out) != 0;
}

UnitData* TribeTacticalAIModule::gatherer(int unitId) {
    int i;

    for (i = 0; i < 0x32; i++) {
        if (this->gatherers[i].id == unitId)
            return this->gatherers + i;
    }
    return 0;
}


UnitData* TribeTacticalAIModule::addGatherer(int id)
{
    int index;
    UnitData* item;
    int freeIndex;
    int value;

    if (id == -1) {
        this->logCommonHistory("ERROR adding gatherer id -1.");
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


int TribeTacticalAIModule::removeGatherer(int id)
{
    UnitData* pU;
    int* piVar2;
    int i;

    if (id == -1) {
        this->logCommonHistory("ERROR removing gatherer id -1.");
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

int TribeTacticalAIModule::isGatherer(int unitId) {
    int i;

    for (i = 0; i < 0x32; i++) {
        if (this->gatherers[i].id == unitId)
            return 1;
    }
    return 0;
}

int TribeTacticalAIModule::requiredGatherAmount(int index) {
    if (this->desiredGathererDistribution[index] == 0) {
        return this->sn[0x94];
    }
    int value = this->neededResources.value(index);
    return value / this->desiredGathererDistribution[index];
}


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


int TribeTacticalAIModule::numberAvailableGranaries(int& count, int& unbuilt)
{
    int value;

    value = this->md->buildAI.numberUnbuiltItemsOfType(0x44, 0);
    unbuilt = value;
    if (value > 0) {
        return 0;
    }
    value = this->md->resourceAI.resource(0);
    if (this->sn[0xBE] <= value) {
        return 0;
    }
    if (this->sn[0x97] != -1) {
        value = this->md->buildAI.numberItemsOfType(0x44, 0);
        count = value;
        if (value >= this->sn[0x97]) {
            return 0;
        }
    }
    value = this->md->buildAI.numberItemsOfType(0x44, 0);
    count = value;
    return this->md->informationAI.numberAvailableGranaries();
}

int TribeTacticalAIModule::initialExplorationSatisfied()
{
    int iVar1;

    if (this->sn[0xA7] <= 0)
        return 1;

    iVar1 = (int)(this->md->player->visible->percentExplored() * 100.0f);
    return iVar1 >= this->sn[0xA7];
}


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

int TribeTacticalAIModule::inAge(int age) {
    int currentAge = (int)this->md->player->attributes[6];
    return currentAge == age ? 1 : 0;
}


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


void TribeTacticalAIModule::checkForCoopTributeDemand()
{
    int tempRand;
    int pick;
    TRIBE_World* world;
    int i;
    int j;
    int amountDemandable;
    RGE_Player* player;
    int cur;
    int count;
    int* need;

    int tributeInterval = this->sn[0xBA];
    int tributeAmount = this->sn[0xBB];
    int foodMin = this->sn[0xBE];
    int woodMin = this->sn[0xBF];
    int stoneMin = this->sn[0xC0];
    int goldMin = this->sn[0xC1];
    if (tributeInterval == -1) return;
    world = static_cast<TRIBE_World*>(this->md->player->world);
    cur = world->world_time;
    if ((cur - this->lastCoopTributeDemandTime) / 1000 < tributeInterval) return;
    this->lastCoopTributeDemandTime = cur;

    world = static_cast<TRIBE_World*>(this->md->player->world);
    if (world->controllingComputerPlayer == 0xff) {
        i = 1;
        count = 0;
        if (world->player_num > 1) {
            do {
                if (world->players[i]->computerPlayer() == 1) count++;
                i++;
            } while (i < world->player_num);
        }
        if (count == 1) {
            world->controllingComputerPlayer = (uchar)this->md->player->id;
        } else {
            pick = debug_rand("C:\\msdev\\work\\age1_x1\\taitacmd.cpp", 0x31f0) % count + 1;
            j = 1;
            if (world->player_num > 1) {
                do {
                    player = world->players[j];
                    if (player->computerPlayer() == 1) {
                        pick--;
                        if (pick == 0) world->controllingComputerPlayer = (uchar)player->id;
                    }
                    j++;
                } while (j < world->player_num);
            }
        }
    }

    if (world->controllingComputerPlayer != (uchar)this->md->player->id) return;

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
            if (world->player_num > 1) {
                if (tempRand > 0) {
                    do {
                    player = world->players[j];
                    if (player->id != this->md->player->id && player->computerPlayer() != 0) {
                        if (this->md->player->isAlly(j) != 0) {
                            if (player->isAlly((int)this->md->player->id) != 0) {
                                short myid = this->md->player->id;
                                if ((myid < player->id && player->id != (short)world->controllingComputerPlayer) || myid == (short)world->controllingComputerPlayer) {
                                    int res = *need;
                                    amountDemandable = (int)player->attributes[res];
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
                    } while (j < world->player_num);
                }
            }
        }
next:
        need++;
        i++;
    } while (i < 4);
}


void TribeTacticalAIModule::checkForCoopTributeGift()
{
    if (this->sn[0xBA] == -1) return;
    if (this->md->object(-1, 0x54, -1, -1, -1, -1, -1, -1, -1, -1) == 0) return;

    int now = this->md->player->world->world_time;
    if ((now - this->lastCoopTributeGiftTime) / 1000 < this->sn[0xBA])
        return;
    this->lastCoopTributeGiftTime = now;

    TRIBE_World* world = static_cast<TRIBE_World*>(this->md->player->world);
    if (world->controllingComputerPlayer == 0xff) {
        int i = 1;
        int num_computer = 0;
        if (world->player_num > 1) {
            do {
                if (world->players[i]->computerPlayer() == 1)
                    ++num_computer;
                ++i;
            } while (i < world->player_num);
        }
        if (num_computer == 1) {
            world->controllingComputerPlayer = this->md->player->id;
        } else {
            int pick = debug_rand(s_file, 0x3275) %
                            num_computer + 1;
            i = 1;
            if (world->player_num > 1) {
                do {
                    RGE_Player* other = world->players[i];
                    if (other->computerPlayer() == 1) {
                        --pick;
                        if (pick == 0)
                            world->controllingComputerPlayer = other->id;
                    }
                    ++i;
                } while (i < world->player_num);
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
            if (world->player_num > 1) {
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
                } while (j < world->player_num);
            }
            if (bestCP != -1) {
                float amount =
                    (float)(this->md->resourceAI.resource(i) - *minimum);
                TRIBE_Player* aiPlayer = this->md->aiPlayer;
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

// __thiscall, void
//
//   three-age research checks.  The build, resource, and tactical modules are
//   named typed members; the first two research arms intentionally keep their
//   branch-local taskResearch calls, as shown by the distinct call sites and

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


void TribeTacticalAIModule::checkForCoopAttack(int p1, int p2, int p3)
{
    int coopAttackEnabled = this->sn[0xC4];
    int coopAttackInterval = this->sn[0xC5];
    if (coopAttackEnabled != 1) return;

    int now = this->md->player->world->world_time;
    if ((now - this->lastCoopAttackDemandTime) / 1000 < coopAttackInterval) return;
    this->lastCoopAttackDemandTime = now;

    TRIBE_World* world = static_cast<TRIBE_World*>(this->md->player->world);
    if (world->controllingComputerPlayer == 0xff) {
        int num_computer = 0;
        int i = 1;
        if (world->player_num > 1) {
            do {
                if (world->players[i]->computerPlayer() == 1) ++num_computer;
                ++i;
            } while (i < world->player_num);
        }
        if (num_computer == 1) {
            world->controllingComputerPlayer = this->md->player->id;
        } else {
            int pick = debug_rand(s_file, 0x32f1) % num_computer + 1;
            i = 1;
            if (world->player_num > 1) {
                do {
                    RGE_Player* other = world->players[i];
                    if (other->computerPlayer() == 1) {
                        --pick;
                        if (pick == 0) world->controllingComputerPlayer = other->id;
                    }
                    ++i;
                } while (i < world->player_num);
            }
        }
    }

    int idx = 1;
    if (world->player_num <= 1) return;
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
    } while (idx < world->player_num);
}


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

int TribeTacticalAIModule::resourceDifference(int index) {
    if (index < 0 || index > 3)
        return -1;
    return this->resourceDifferenceValue[this->neededResourceValue[index]];
}

int TribeTacticalAIModule::actualGathererCount(int index) {
    if (index < 0 || index > 3)
        return -1;
    return this->actualGathererDistribution[this->neededResourceValue[index]];
}

int TribeTacticalAIModule::actualGathererCountByRealResourceID(int index) {
    if (index < 0 || index > 3) {
        return -1;
    }
    return this->actualGathererDistribution[index];
}

int TribeTacticalAIModule::desiredGathererCount(int index) {
    if (index < 0 || index > 3)
        return -1;
    return this->desiredGathererDistribution[this->neededResourceValue[index]];
}


void* operator new(unsigned int size);
void operator delete(void* ptr);
void TribeTacticalAIModule::taskElephantGatherers(
    int mainHunterID, int numberToTask, int targetID)
{
    RGE_Static_Object* targetObject = this->md->object(targetID);
    if (targetObject != 0) {
        int count;
        ManagedArray<int> alreadyTasked(0);

        alreadyTasked.add(mainHunterID);
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



void TribeTacticalAIModule::saveTheTown(int objectID)
{
    ulong entryTime = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\taitacmd.cpp", 0x3420);
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
                    debug_timeGetTime("C:\\msdev\\work\\age1_x1\\taitacmd.cpp", 0x3447) -
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
