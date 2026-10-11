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
extern unsigned long __cdecl debug_timeGetTime(char*, int);
extern int debug_rand(char*, int);
extern int __ftol();

TacticalAIGroup::TacticalAIGroup() :
    idValue(-1), inUseValue(0), typeValue(-1), subTypeValue(-1), numberUnitsValue(0), desiredNumberUnitsValue(0),
    commanderValue(-1), originalHitPointsValue(-1), originalUnitNumberValue(-1), actionValue(0), targetValue(-1),
    targetTypeValue(-1), priorityValue(0), waitCodeValue(-1), assistGroupIDValue(-1), assistGroupTypeValue(-1),
    consecutiveIdleUnitCountValue(0), playNumberValue(-1), numberAttackWaypointsValue(0), currentAttackWaypointValue(0),
    consecutiveGatherAttemptsValue(0), numberObjectsToDestroyValue(0), objectsToDestroyOwnerValue(-1),
    objectsToDestroyCommanderZoneValue(-1), lastAttackRoundupTime(0), lastAddedUnitTimeValue(0) {
    setTargetLocation(-1.0f, -1.0f, -1.0f);
    setGatherLocation(-1.0f, -1.0f, -1.0f);
    setRetreatLocation(-1.0f, -1.0f, -1.0f);
    setLocation(-1.0f, -1.0f, -1.0f);

    // Fill unitsValue and unitsOriginalHitPointsValue with -1
    {
        int i;
        for (i = 0; i < 40; i++) {
            unitsValue[i] = -1;
            unitsOriginalHitPointsValue[i] = -1;
        }
    }

    // Fill objectsToDestroyValue with -1
    {
        int i;
        for (i = 0; i < 20; i++)
            objectsToDestroyValue[i] = -1;
    }
}

TacticalAIGroup::~TacticalAIGroup() {
}

// Deserializes struct fields with version-conditional reads
// Load has 4 float comparisons for backward compat: conditional field reads
//

int TacticalAIGroup::load(int infile) {
    rge_read(infile, &this->idValue, 4);
    rge_read(infile, &this->inUseValue, 4);

    int* ptr = this->unitsOriginalHitPointsValue;
    int count = 40;
    do {
        rge_read(infile, ptr - 40, 4);
        rge_read(infile, ptr, 4);
        ++ptr;
    } while (--count != 0);

    rge_read(infile, &this->numberUnitsValue, 4);
    rge_read(infile, &this->desiredNumberUnitsValue, 4);
    rge_read(infile, &this->commanderValue, 4);
    rge_read(infile, &this->originalHitPointsValue, 4);
    rge_read(infile, &this->originalUnitNumberValue, 4);
    rge_read(infile, &this->locationValue, 16);
    rge_read(infile, &this->actionValue, 4);
    rge_read(infile, &this->targetValue, 4);
    rge_read(infile, &this->targetTypeValue, 4);
    rge_read(infile, &this->targetLocationValue, 16);
    rge_read(infile, &this->gatherLocationValue, 16);
    rge_read(infile, &this->retreatLocationValue, 16);
    rge_read(infile, &this->priorityValue, 4);
    rge_read(infile, &this->waitCodeValue, 4);
    rge_read(infile, &this->assistGroupIDValue, 4);
    rge_read(infile, &this->assistGroupTypeValue, 4);
    rge_read(infile, &this->typeValue, 4);
    rge_read(infile, &this->subTypeValue, 4);
    rge_read(infile, &this->consecutiveIdleUnitCountValue, 4);
    rge_read(infile, &this->numberAttackWaypointsValue, 1);
    rge_read(infile, &this->currentAttackWaypointValue, 1);
    rge_read(infile, &this->attackWaypoints, 240);
    rge_read(infile, &this->playNumberValue, 4);

    // Version detection: conditional field reads based on float version comparison
    // Asm pattern: fld [58EBCCh]; fcomp [5756E0h]; test ah,1; jne â†’ if (ver < threshold)
    if (save_game_version >= g_tactical_group_save_version_6_94) {
        rge_read(infile, &this->consecutiveGatherAttemptsValue, 1);
    } else {
        this->consecutiveGatherAttemptsValue = 0;
    }

    if (save_game_version >= g_tactical_group_save_version_7_13) {
        rge_read(infile, &this->numberObjectsToDestroyValue, 4);
        rge_read(infile, &this->objectsToDestroyValue, 80);
        rge_read(infile, &this->objectsToDestroyOwnerValue, 4);
        rge_read(infile, &this->objectsToDestroyCommanderZoneValue, 4);
    }

    if (save_game_version >= g_tactical_group_save_version_7_14) {
        rge_read(infile, &this->lastAttackRoundupTime, 4);
    }

    if (save_game_version >= g_tactical_group_save_version_7_20) {
        rge_read(infile, &this->lastAddedUnitTimeValue, 4);
    }

    return 1;
}

// TacticalAIGroup layout (partial, only serialized fields)

int TacticalAIGroup::save(int outfile) {
    rge_write(outfile, &this->idValue, 4);
    rge_write(outfile, &this->inUseValue, 4);

    // Write unitsValue and unitsOriginalHitPointsValue in paired entries.
    int* ptr = this->unitsOriginalHitPointsValue;
    int count = 40;
    do {
        rge_write(outfile, ptr - 40, 4);
        rge_write(outfile, ptr, 4);
        ++ptr;
    } while (--count != 0);

    rge_write(outfile, &this->numberUnitsValue, 4);
    rge_write(outfile, &this->desiredNumberUnitsValue, 4);
    rge_write(outfile, &this->commanderValue, 4);
    rge_write(outfile, &this->originalHitPointsValue, 4);
    rge_write(outfile, &this->originalUnitNumberValue, 4);
    rge_write(outfile, &this->locationValue, 16);
    rge_write(outfile, &this->actionValue, 4);
    rge_write(outfile, &this->targetValue, 4);
    rge_write(outfile, &this->targetTypeValue, 4);
    rge_write(outfile, &this->targetLocationValue, 16);
    rge_write(outfile, &this->gatherLocationValue, 16);
    rge_write(outfile, &this->retreatLocationValue, 16);
    rge_write(outfile, &this->priorityValue, 4);
    rge_write(outfile, &this->waitCodeValue, 4);
    rge_write(outfile, &this->assistGroupIDValue, 4);
    rge_write(outfile, &this->assistGroupTypeValue, 4);
    rge_write(outfile, &this->typeValue, 4);
    rge_write(outfile, &this->subTypeValue, 4);
    rge_write(outfile, &this->consecutiveIdleUnitCountValue, 4);
    rge_write(outfile, &this->numberAttackWaypointsValue, 1);
    rge_write(outfile, &this->currentAttackWaypointValue, 1);
    rge_write(outfile, &this->attackWaypoints, 240);
    rge_write(outfile, &this->playNumberValue, 4);
    rge_write(outfile, &this->consecutiveGatherAttemptsValue, 1);
    rge_write(outfile, &this->numberObjectsToDestroyValue, 4);
    rge_write(outfile, &this->objectsToDestroyValue, 80);
    rge_write(outfile, &this->objectsToDestroyOwnerValue, 4);
    rge_write(outfile, &this->objectsToDestroyCommanderZoneValue, 4);
    rge_write(outfile, &this->lastAttackRoundupTime, 4);
    rge_write(outfile, &this->lastAddedUnitTimeValue, 4);

    return 1;
}

// Getter: returns this->idValue at +0xC

int TacticalAIGroup::id() const {
    return idValue;
}

void TacticalAIGroup::setID(int v) {
    this->idValue = v;
}

int TacticalAIGroup::inUse() const {
    return this->inUseValue;
}

void TacticalAIGroup::setInUse(int v) {
    this->inUseValue = v;
}

int TacticalAIGroup::type() const {
    return this->typeValue;
}

void TacticalAIGroup::setType(int v) {
    this->typeValue = v;
}

int TacticalAIGroup::subType() const {
    return this->subTypeValue;
}

void TacticalAIGroup::setSubType(int v) {
    this->subTypeValue = v;
}

int TacticalAIGroup::addUnit(int id, TribeMainDecisionAIModule* md) {
    int i;
    volatile int* p;

    i = 0;
    p = this->unitsValue;
    while (i < 40) {
        if (*p == -1) {
            this->unitsValue[i] = id;
            this->unitsOriginalHitPointsValue[i] = -1;
            this->numberUnitsValue = this->numberUnitsValue + 1;
            if (this->commanderValue != -1) {
                md->player->command_add_to_group(this->commanderValue, id, 4.0f);
            }
            this->lastAddedUnitTimeValue = md->player->world->world_time;
            return 1;
        }
        i = i + 1;
        p = p + 1;
    }
    return 0;
}

int TacticalAIGroup::removeUnit(int id, TribeMainDecisionAIModule* md) {
    int commander;
    int i;
    int* p;

    i = 0;
    p = this->unitsValue;
    while (i < 40) {
        if (*p == id) {
            commander = this->commanderValue;
            if (id == commander) {
                this->setSpecificCommander(-1, md);
            } else if (commander != -1) {
                md->player->command_remove_from_group(commander, id);
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

int TacticalAIGroup::removeUnitByIndex(int index, TribeMainDecisionAIModule* md) {
    int unit;
    int commander;

    if (index >= 0 && index < 40) {
        unit = this->unitsValue[index];
        commander = this->commanderValue;
        if (unit == commander) {
            this->setSpecificCommander(-1, md);
        } else if (commander != -1) {
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

int TacticalAIGroup::removeExtraUnits(TribeMainDecisionAIModule* md) {
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

int TacticalAIGroup::removeUnboardedUnits(TribeTacticalAIModule* t, TribeMainDecisionAIModule* md) {
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
                } else if (commander != -1) {
                    md->player->command_remove_from_group(commander, unit);
                }
                t->stopUnit(*p, 100);
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

int TacticalAIGroup::containsUnit(int id) {
    for (int i = 0; i < 0x28; ++i) {
        if (this->unitsValue[i] == id) {
            return 1;
        }
    }
    return 0;
}

int TacticalAIGroup::numberUnits() {
    return this->numberUnitsValue;
}

int TacticalAIGroup::unit(int i) {
    int index = 0;
    int used = -1;
    int limit = i + 1;
    int* units = this->unitsValue;

    while (index < 0x28) {
        if (used >= limit) {
            goto too_far;
        }
        if (*units != -1) {
            used++;
        }
        if (used == i) {
            return this->unitsValue[index];
        }
        index++;
        units++;
    }
    return -1;

too_far:
    return -1;
}

// Scans unitsValue array for the unit_index-th valid entry, returns corresponding HP

int TacticalAIGroup::unitOriginalHitPoints(int i) {
    int idx = 0;
    int used = -1;
    int limit = i + 1;

    for (; idx < 40; idx++) {
        if (used >= limit)
            return -1;
        if (this->unitsValue[idx] != -1)
            used++;
        if (used == i)
            return this->unitsOriginalHitPointsValue[idx];
    }
    return -1;
}

int TacticalAIGroup::desiredNumberUnits() const {
    return this->desiredNumberUnitsValue;
}

void TacticalAIGroup::setDesiredNumberUnits(int v) {
    this->desiredNumberUnitsValue = v;
}

int TacticalAIGroup::commander() const {
    return this->commanderValue;
}

void TacticalAIGroup::setSpecificCommander(int id, TribeMainDecisionAIModule* md) {
    int temp[40];
    int* src;
    int* dst;
    int remaining;
    int count;
    int unit;

    if (this->commanderValue != -1) {
        md->player->command_destroy_group(this->commanderValue);
    }
    this->commanderValue = id;
    if (id != -1) {
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
        md->player->command_create_group(id, temp, count, 4.0f);
    }
}

// first pass: 40-entry scan over unit ids, skipping -1 slots and summing floored hit points

int TacticalAIGroup::currentHitPoints(TribeMainDecisionAIModule* md) const {
    int total = 0;
    const int* unit = unitsValue;
    int remaining = 0x28;

    do {
        int unitId = *unit;
        if (unitId != -1) {
            RGE_Static_Object* object = md->object(unitId);
            if (object != 0) {
                total += (int) object->hp;
            }
        }
        ++unit;
    } while (--remaining != 0);

    return total;
}

int TacticalAIGroup::originalHitPoints() const {
    return this->originalHitPointsValue;
}

void TacticalAIGroup::setOriginalHitPoints(int v) {
    this->originalHitPointsValue = v;
}

int TacticalAIGroup::originalUnitNumber() const {
    return this->originalUnitNumberValue;
}

void TacticalAIGroup::setOriginalUnitNumber(int v) {
    this->originalUnitNumberValue = v;
}

const Waypoint& TacticalAIGroup::location() const {
    return this->locationValue;
}

void TacticalAIGroup::setLocation(float x, float y, float z) {
    this->locationValue.x = x;
    this->locationValue.y = y;
    this->locationValue.z = z;
}

int TacticalAIGroup::action() const {
    return this->actionValue;
}

void TacticalAIGroup::setAction(int v) {
    this->actionValue = v;
}

int TacticalAIGroup::target() const {
    return this->targetValue;
}

void TacticalAIGroup::setTarget(int v) {
    this->targetValue = v;
}

int TacticalAIGroup::targetType() const {
    return this->targetTypeValue;
}

void TacticalAIGroup::setTargetType(int v) {
    this->targetTypeValue = v;
}

const Waypoint& TacticalAIGroup::targetLocation() const {
    return this->targetLocationValue;
}

// From taitacmd.cpp
// The location fields are Waypoint float members in the canonical class.
// This preserves direct float stores in the grouped wrapper.

void TacticalAIGroup::setAllLocations(float x, float y, float z) {
    this->locationValue.x = x;
    this->locationValue.y = y;
    this->locationValue.z = z;
    this->gatherLocationValue.x = x;
    this->gatherLocationValue.y = y;
    this->gatherLocationValue.z = z;
    this->retreatLocationValue.x = x;
    this->retreatLocationValue.y = y;
    this->retreatLocationValue.z = z;
}

void TacticalAIGroup::setTargetLocation(float x, float y, float z) {
    this->targetLocationValue.x = x;
    this->targetLocationValue.y = y;
    this->targetLocationValue.z = z;
}

const Waypoint& TacticalAIGroup::gatherLocation() const {
    return this->gatherLocationValue;
}

void TacticalAIGroup::setGatherLocation(float x, float y, float z) {
    this->gatherLocationValue.x = x;
    this->gatherLocationValue.y = y;
    this->gatherLocationValue.z = z;
}

const Waypoint& TacticalAIGroup::retreatLocation() const {
    return this->retreatLocationValue;
}

void TacticalAIGroup::setRetreatLocation(float x, float y, float z) {
    this->retreatLocationValue.x = x;
    this->retreatLocationValue.y = y;
    this->retreatLocationValue.z = z;
}

int TacticalAIGroup::priority() const {
    return this->priorityValue;
}

void TacticalAIGroup::setPriority(int v) {
    this->priorityValue = v;
}

int TacticalAIGroup::waitCode() const {
    return this->waitCodeValue;
}

void TacticalAIGroup::setWaitCode(int v) {
    this->waitCodeValue = v;
}

int TacticalAIGroup::assistGroupID() const {
    return this->assistGroupIDValue;
}

void TacticalAIGroup::setAssistGroupID(int v) {
    this->assistGroupIDValue = v;
}

int TacticalAIGroup::assistGroupType() const {
    return this->assistGroupTypeValue;
}

void TacticalAIGroup::setAssistGroupType(int v) {
    this->assistGroupTypeValue = v;
}

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

int TacticalAIGroup::task(
    TribeTacticalAIModule* t, TribeMainDecisionAIModule* md, int taskID, int resetOriginal, int overrideCurrentAction
) {
    int i;
    int oHP;
    int distance;
    int priority;
    int* unit;
    RGE_Static_Object* object;
    UnitAIModule* unitAI;

    t->logGroupDebug(idValue, s0, taskID, resetOriginal, overrideCurrentAction);

    if (commanderValue == -1) {
        t->logGroupDebug(idValue, s_no_commander);
        return 0;
    }

    if (taskID != TACTICAL_GROUP_ACTION_GATHER && taskID != 14) {
        consecutiveGatherAttemptsValue = 0;
    }

    switch (taskID) {
        case TACTICAL_GROUP_ACTION_NONE:
        case TACTICAL_GROUP_ACTION_IDLE:
            t->logGroupDebug(idValue, s_log_00);
            oHP = 0;
            unit = unitsValue;
            for (i = 0; i < 40; ++i, ++unit) {
                if (*unit != -1) {
                    t->logGroupDebug(idValue, s_log_01, *unit);
                    object = md->object(*unit);
                    if (object == 0 || object->unitAI() == 0) {
                        t->logGroupDebug(idValue, s_log_02, *unit);
                        removeUnitByIndex(i, md);
                    } else {
                        unitsOriginalHitPointsValue[i] = (int) object->hp;
                        oHP += unitsOriginalHitPointsValue[i];
                        t->stopUnit(*unit, 100);
                    }
                }
            }
            inUseValue = 0;
            if (resetOriginal == 1) {
                originalHitPointsValue = oHP;
                originalUnitNumberValue = numberUnitsValue;
            }
            return 1;

        case TACTICAL_GROUP_ACTION_GATHER:
        case 14: {
            RGE_Static_Object* commanderObj;
            unsigned char commanderZone;

            if (consecutiveGatherAttemptsValue != 255) {
                ++consecutiveGatherAttemptsValue;
            }
            commanderObj = md->object(commanderValue);
            if (commanderObj == 0) {
                return 0;
            }

            commanderZone = commanderObj->currentZone();
            if (commanderZone != commanderObj->lookupZone((int) gatherLocationValue.x, (int) gatherLocationValue.y)) {
                setGatherLocation(commanderObj->world_x, commanderObj->world_y, commanderObj->world_z);
            }

            unit = unitsValue;
            for (i = 0; i < 40; ++i, ++unit) {
                if (*unit == -1) {
                    continue;
                }
                object = md->object(*unit);
                if (object == 0 || object->unitAI() == 0
                    || commanderObj->lookupZone((int) object->world_x, (int) object->world_y) != commanderZone) {
                    removeUnitByIndex(i, md);
                    continue;
                }

                if (overrideCurrentAction == 0 && object->unitAI()->currentAction() != -1
                    && object->unitAI()->currentAction() != UNIT_AI_ACTION_TRANSPORT) {
                    continue;
                }

                {
                    float distance;
                    float gatherRange;

                    if (taskID == 14) {
                        gatherRange = 0.0f;
                    } else {
                        gatherRange = (float) t->strategicNumber(SNAttackGroupGatherSpacing);
                    }
                    distance = object->distance_to_position(
                                   gatherLocationValue.x, gatherLocationValue.y, gatherLocationValue.z
                               )
                               - g_tactical_ai_distance_offset;
                    if (distance < g_tactical_ai_minimum_distance) {
                        distance = 0.0f;
                    }
                    if (!(distance >= gatherRange)) {
                        if (object->unitAI()->currentOrder() != -1) {
                            t->stopUnit(*unit, 100);
                        }
                    } else {
                        t->groupGatherUnit(
                            *unit, commanderValue, gatherLocationValue.x, gatherLocationValue.y, gatherLocationValue.z,
                            gatherRange, t->calculatePriority(distance)
                        );
                    }
                }
            }
            return 1;
        }

        case TACTICAL_GROUP_ACTION_RETREAT:
            t->logGroupDebug(idValue, s_log_18);
            t->logGroupDebug(idValue, s_log_19, (double) retreatLocationValue.x, (double) retreatLocationValue.y);
            unit = unitsValue;
            for (i = 0; i < 40; ++i, ++unit) {
                if (*unit == -1) {
                    continue;
                }
                t->logGroupDebug(idValue, s_log_20, *unit);
                object = md->object(*unit);
                if (object == 0 || object->unitAI() == 0) {
                    t->logGroupDebug(idValue, s_log_21, *unit);
                    removeUnitByIndex(i, md);
                    continue;
                }

                {
                    float distance = object->distance_to_position(
                                         retreatLocationValue.x, retreatLocationValue.y, retreatLocationValue.z
                                     )
                                     - g_tactical_ai_distance_offset;
                    if (distance < g_tactical_ai_minimum_distance) {
                        distance = g_tactical_ai_minimum_distance;
                    }
                    if (!(distance >= object->master_obj->los * g_tactical_ai_retreat_los_factor)) {
                        t->logGroupDebug(idValue, s_log_23, *unit);
                    } else {
                        t->logGroupDebug(idValue, s_log_22, *unit);
                        t->moveUnit(*unit, retreatLocationValue.x, retreatLocationValue.y, 100);
                    }
                }
            }
            return 1;

        case TACTICAL_GROUP_ACTION_ESCORTED_EXPLORE: {
            int randomRoll;

            t->logGroupDebug(idValue, s_log_31);
            randomRoll = debug_rand(s_file, 943) % 100;
            oHP = 0;
            unit = unitsValue;
            for (i = 0; i < 40; ++i, ++unit) {
                if (*unit == -1) {
                    continue;
                }
                t->logGroupDebug(idValue, s_log_32, *unit);
                object = md->object(*unit);
                if (object == 0 || object->unitAI() == 0) {
                    t->logGroupDebug(idValue, s_log_33, *unit);
                    removeUnitByIndex(i, md);
                    continue;
                }

                unitsOriginalHitPointsValue[i] = (int) object->hp;
                oHP += unitsOriginalHitPointsValue[i];
                if (overrideCurrentAction == 0 && object->unitAI()->currentAction() != -1) {
                    t->logGroupDebug(idValue, s_log_34, *unit, object->unitAI()->currentAction());
                    continue;
                }

                if (*unit == commanderValue) {
                    t->logGroupDebug(idValue, s_log_35, commanderValue);
                    t->taskExplorer(*unit, 0);
                } else if (randomRoll < t->strategicNumber(200)) {
                    t->logGroupDebug(idValue, s_log_36, *unit);
                    t->taskDefender(
                        *unit, commanderValue, object->master_obj->los * g_tactical_ai_defender_los_factor, 99
                    );
                } else {
                    t->logGroupDebug(idValue, s_log_37, *unit);
                    t->taskExplorer(*unit, 0);
                }
            }
            inUseValue = 1;
            if (resetOriginal == 1) {
                originalHitPointsValue = oHP;
                originalUnitNumberValue = numberUnitsValue;
            }
            return 1;
        }

        case TACTICAL_GROUP_ACTION_EXPLORE:
            t->logGroupDebug(idValue, s_log_38);
            oHP = 0;
            unit = unitsValue;
            for (i = 0; i < 40; ++i, ++unit) {
                if (*unit == -1) {
                    continue;
                }
                t->logGroupDebug(idValue, s_log_39, *unit);
                object = md->object(*unit);
                if (object == 0 || object->unitAI() == 0) {
                    t->logGroupDebug(idValue, s_log_40, *unit);
                    removeUnitByIndex(i, md);
                    continue;
                }
                unitsOriginalHitPointsValue[i] = (int) object->hp;
                oHP += unitsOriginalHitPointsValue[i];
                if (overrideCurrentAction == 0 && object->unitAI()->currentAction() != -1) {
                    t->logGroupDebug(idValue, s_log_41, *unit, object->unitAI()->currentAction());
                    continue;
                }
                t->taskExplorer(*unit, 0);
            }
            inUseValue = 1;
            if (resetOriginal == 1) {
                originalHitPointsValue = oHP;
                originalUnitNumberValue = numberUnitsValue;
            }
            return 1;

        case TACTICAL_GROUP_ACTION_ATTACK_ROUNDUP: {
            int elapsed;

            t->logGroupDebug(idValue, s_log_54, targetValue);
            t->logGroupDebug(idValue, s_log_55, (double) targetLocationValue.x, (double) targetLocationValue.y);
            elapsed = (int) (md->player->world->world_time - lastAttackRoundupTime);
            elapsed /= 1000;
            if (elapsed < 10) {
                t->logGroupDebug(idValue, s_log_56, elapsed);
                return 0;
            }
            t->logGroupDebug(idValue, s_log_57, elapsed);
            lastAttackRoundupTime = md->player->world->world_time;
            if (playNumberValue != -1) {
                t->logGroupDebug(idValue, s_log_58);
                return 0;
            }

            oHP = 0;
            unit = unitsValue;
            for (i = 0; i < 40; ++i, ++unit) {
                if (*unit == -1) {
                    continue;
                }
                t->logGroupDebug(idValue, s_log_59, *unit);
                object = md->object(*unit);
                if (object == 0 || object->unitAI() == 0) {
                    t->logGroupDebug(idValue, s_log_60, *unit);
                    removeUnitByIndex(i, md);
                    continue;
                }

                unitAI = object->unitAI();
                t->logGroupDebug(idValue, s_log_61, unitAI->currentAction());
                unitsOriginalHitPointsValue[i] = (int) object->hp;
                oHP += unitsOriginalHitPointsValue[i];
                if (overrideCurrentAction == 0 && object->unitAI()->currentAction() != -1) {
                    t->logGroupDebug(idValue, s_log_62, *unit);
                    continue;
                }

                t->logGroupDebug(idValue, s_log_63, *unit, subTypeValue);
                if (subTypeValue != 0 && subTypeValue != 4) {
                    //! @bug The roundup target check tests existence only, so the AI attacks targets it cannot see.
                    //! The chain (order 0x2D9 -> attackRoundupObject -> attack) has no visible-map test anywhere.
                    //! Only the engine's fire gate checks visibility; the chase moves to the hidden target position.
                    RGE_Static_Object* targetObj = md->object(targetValue);
                    if (targetObj != 0) {
                        t->logGroupDebug(idValue, s_log_66, *unit, targetValue);
                        t->taskAttacker(
                            *unit, targetLocationValue.x, targetLocationValue.y, targetValue, targetObj->owner->id,
                            attackWaypoints, numberAttackWaypointsValue, commanderValue, 1
                        );
                    } else {
                        t->logGroupDebug(idValue, s_log_65);
                    }
                } else {
                    t->logGroupDebug(idValue, s_log_64, *unit, targetValue);
                    t->taskDefender(*unit, targetValue, 2.0f, 100);
                }
            }

            inUseValue = 1;
            if (resetOriginal == 1) {
                originalHitPointsValue = oHP;
                originalUnitNumberValue = numberUnitsValue;
                numberAttackWaypointsValue = 0;
            }
            return 1;
        }

        case TACTICAL_GROUP_ACTION_ATTACK:
        case 21: {
            int firstTime;

            t->logGroupDebug(idValue, s_log_03, targetValue);
            t->logGroupDebug(idValue, s_log_04, (double) targetLocationValue.x, (double) targetLocationValue.y);
            if (playNumberValue == -1) {
                t->logGroupDebug(idValue, s_log_05);
            } else {
                t->logGroupDebug(idValue, s_log_06, playNumberValue);
            }

            firstTime = 1;
            oHP = 0;
            lastAttackRoundupTime = md->player->world->world_time;
            unit = unitsValue;
            for (i = 0; i < 40; ++i, ++unit) {
                if (*unit == -1) {
                    continue;
                }

                t->logGroupDebug(idValue, s_log_07, *unit);
                object = md->object(*unit);
                if (object == 0 || object->unitAI() == 0) {
                    t->logGroupDebug(idValue, s_log_08, *unit);
                    removeUnitByIndex(i, md);
                    continue;
                }

                unitAI = object->unitAI();
                t->logGroupDebug(idValue, s_log_09, unitAI->currentAction());
                unitsOriginalHitPointsValue[i] = (int) object->hp;
                oHP += unitsOriginalHitPointsValue[i];

                if (playNumberValue != -1) {
                    continue;
                }

                if (overrideCurrentAction == 0 && object->unitAI()->currentAction() == UNIT_AI_ACTION_ATTACK
                    && object->unitAI()->currentTargetType() != 27) {
                    t->logGroupDebug(idValue, s_log_10, *unit);
                    continue;
                }

                t->logGroupDebug(idValue, s_log_11, *unit, subTypeValue);
                if (subTypeValue != 0 && subTypeValue != 4) {
                    RGE_Static_Object* targetObj = md->object(targetValue);
                    if (targetObj != 0) {
                        if (firstTime) {
                            XYPoint min;
                            XYPoint max;
                            unsigned char waypoint;

                            t->logGroupDebug(idValue, s_log_14);
                            min.x = (int) targetLocationValue.x - 7;
                            min.y = (int) targetLocationValue.y - 7;
                            md->informationAI.mapBound(min);
                            max.x = (int) targetLocationValue.x + 7;
                            max.y = (int) targetLocationValue.y + 7;
                            md->informationAI.mapBound(max);

                            if (numberAttackWaypointsValue > 1) {
                                waypoint = numberAttackWaypointsValue - 2;
                                if (!((float) min.x > attackWaypoints[waypoint].x)) {
                                    max.x = (int) attackWaypoints[waypoint].x;
                                } else {
                                    min.x = (int) attackWaypoints[waypoint].x;
                                }
                                if (!((float) min.y > attackWaypoints[waypoint].y)) {
                                    max.y = (int) attackWaypoints[waypoint].y;
                                } else {
                                    min.y = (int) attackWaypoints[waypoint].y;
                                }
                            }

                            md->informationAI.storeAttackMemory(
                                0, (unsigned char) min.x, (unsigned char) min.y, (unsigned char) max.x,
                                (unsigned char) max.y, (unsigned char) md->player->id,
                                (unsigned char) targetObj->owner->id, 0, 0, md->player->world->world_time, -1
                            );
                            t->resetAttackSeparationTime();
                            firstTime = 0;
                        }

                        t->logGroupDebug(idValue, s_log_15, *unit, targetValue);
                        if (*unit == commanderValue || t->importantGroupLeader(commanderValue) == 0
                            || t->strategicNumber(121) == 0) {
                            t->logGroupDebug(idValue, s_log_16);
                            if (taskID == 21) {
                                t->moveUnit(*unit, targetLocationValue.x, targetLocationValue.y, 100);
                            } else {
                                t->taskAttacker(
                                    *unit, targetLocationValue.x, targetLocationValue.y, targetValue,
                                    (int) targetObj->owner->id, attackWaypoints, numberAttackWaypointsValue,
                                    commanderValue, 0
                                );
                            }
                        } else {
                            t->logGroupDebug(idValue, s_log_17);
                            t->taskDefender(
                                *unit, commanderValue, (float) t->strategicNumber(SNGroupLeaderDefenseDistance), 99
                            );
                        }
                    } else {
                        t->logGroupDebug(idValue, s_log_13);
                    }
                } else {
                    t->logGroupDebug(idValue, s_log_12, *unit, targetValue);
                    t->taskDefender(*unit, targetValue, 2.0f, 100);
                }
            }

            if (playNumberValue != -1) {
                int* list = new int[numberUnitsValue];
                if (list == 0) {
                    t->logGroupDebug(idValue, s_attack_play_alloc_fail);
                    return 0;
                }

                int* destination = list;
                unit = unitsValue;
                for (i = 0; i < 40; ++i, ++unit) {
                    if (*unit != -1) {
                        *destination++ = *unit;
                    }
                }
                t->taskPlay(
                    commanderValue, list, numberUnitsValue, targetValue, playNumberValue, attackWaypoints,
                    numberAttackWaypointsValue
                );
                delete[] list;
                return 0;
            }

            inUseValue = 1;
            if (resetOriginal == 1) {
                originalHitPointsValue = oHP;
                originalUnitNumberValue = numberUnitsValue;
                numberAttackWaypointsValue = 0;
            }
            return 1;
        }

        case TACTICAL_GROUP_ACTION_DEFEND:
            t->logGroupDebug(
                idValue, s_log_24, targetValue, (double) targetLocationValue.x, (double) targetLocationValue.y
            );
            oHP = 0;
            unit = unitsValue;
            for (i = 0; i < 40; ++i, ++unit) {
                if (*unit == -1) {
                    continue;
                }
                t->logGroupDebug(idValue, s_log_25, *unit);
                object = md->object(*unit);
                if (object == 0 || object->unitAI() == 0) {
                    t->logGroupDebug(idValue, s_log_26, *unit);
                    removeUnitByIndex(i, md);
                    continue;
                }

                unitsOriginalHitPointsValue[i] = (int) object->hp;
                oHP += unitsOriginalHitPointsValue[i];
                if (overrideCurrentAction == 0 && object->unitAI()->currentAction() != -1) {
                    t->logGroupDebug(idValue, s_log_27, *unit, object->unitAI()->currentAction());
                    continue;
                }

                priority = t->calculatePriority(
                    object->distance_to_position(targetLocationValue.x, targetLocationValue.y, targetLocationValue.z)
                );
                if (targetTypeValue == MASTER_OBJECT_TOWN_CENTER1) {
                    t->taskDefender(*unit, targetValue, (float) t->strategicNumber(SNSentryDistance), priority);
                } else {
                    t->taskDefender(*unit, targetValue, (float) t->strategicNumber(SNDefenseDistance), priority);
                }
            }
            inUseValue = 1;
            if (resetOriginal == 1) {
                originalHitPointsValue = oHP;
                originalUnitNumberValue = numberUnitsValue;
            }
            return 1;

        case TACTICAL_GROUP_ACTION_FISH:
            t->logGroupDebug(idValue, s_log_42);
            oHP = 0;
            unit = unitsValue;
            for (i = 0; i < 40; ++i, ++unit) {
                if (*unit == -1) {
                    continue;
                }
                t->logGroupDebug(idValue, s_log_43, *unit);
                object = md->object(*unit);
                if (object == 0 || object->unitAI() == 0) {
                    t->logGroupDebug(idValue, s_log_44, *unit);
                    removeUnitByIndex(i, md);
                    continue;
                }
                unitsOriginalHitPointsValue[i] = (int) object->hp;
                oHP += unitsOriginalHitPointsValue[i];
                if (overrideCurrentAction == 0 && object->unitAI()->currentAction() != -1) {
                    t->logGroupDebug(idValue, s_log_45, *unit, object->unitAI()->currentAction());
                    continue;
                }
                if (*unit == commanderValue) {
                    t->logGroupDebug(idValue, s_log_46, *unit);
                    t->taskWaterFisher(*unit, targetValue, targetLocationValue.x, targetLocationValue.y);
                } else {
                    t->logGroupDebug(idValue, s_log_47, *unit);
                    t->taskDefender(
                        *unit, commanderValue, object->master_obj->los * g_tactical_ai_defender_los_factor, 99
                    );
                }
            }
            inUseValue = 1;
            if (resetOriginal == 1) {
                originalHitPointsValue = oHP;
                originalUnitNumberValue = numberUnitsValue;
            }
            return 1;

        case TACTICAL_GROUP_ACTION_TRADE:
            t->logGroupDebug(idValue, s_log_48);
            oHP = 0;
            unit = unitsValue;
            for (i = 0; i < 40; ++i, ++unit) {
                if (*unit == -1) {
                    continue;
                }
                t->logGroupDebug(idValue, s_log_49, *unit);
                object = md->object(*unit);
                if (object == 0 || object->unitAI() == 0) {
                    t->logGroupDebug(idValue, s_log_50, *unit);
                    removeUnitByIndex(i, md);
                    continue;
                }
                unitsOriginalHitPointsValue[i] = (int) object->hp;
                oHP += unitsOriginalHitPointsValue[i];
                if (overrideCurrentAction == 0 && object->unitAI()->currentAction() != -1) {
                    t->logGroupDebug(idValue, s_log_51, *unit, object->unitAI()->currentAction());
                    continue;
                }
                if (*unit == commanderValue) {
                    t->logGroupDebug(idValue, s_log_52, *unit);
                    t->taskWaterTrader(*unit, targetValue);
                } else {
                    t->logGroupDebug(idValue, s_log_53, *unit);
                    t->taskDefender(
                        *unit, commanderValue, object->master_obj->los * g_tactical_ai_defender_los_factor, 99
                    );
                }
            }
            inUseValue = 1;
            if (resetOriginal == 1) {
                originalHitPointsValue = oHP;
                originalUnitNumberValue = numberUnitsValue;
            }
            return 1;

        case 5:
        case 6:
        case TACTICAL_GROUP_ACTION_TRANSPORT:
        case TACTICAL_GROUP_ACTION_ARTIFACT:
            t->logGroupDebug(idValue, s_log_28);
            oHP = 0;
            unit = unitsValue;
            for (i = 0; i < 40; ++i, ++unit) {
                if (*unit != -1) {
                    t->logGroupDebug(idValue, s_log_29, *unit);
                    object = md->object(*unit);
                    if (object == 0 || object->unitAI() == 0) {
                        t->logGroupDebug(idValue, s_log_30, *unit);
                        removeUnitByIndex(i, md);
                    } else {
                        unitsOriginalHitPointsValue[i] = (int) object->hp;
                        oHP += unitsOriginalHitPointsValue[i];
                    }
                }
            }
            inUseValue = 1;
            if (resetOriginal == 1) {
                originalHitPointsValue = oHP;
                originalUnitNumberValue = numberUnitsValue;
            }
            return 0;

        default:
            t->logGroupDebug(idValue, s_unknown_task, taskID);
            return 0;
    }
}

int TacticalAIGroup::isGathered(TribeTacticalAIModule* t, TribeMainDecisionAIModule* md) {
    int i;
    int* p;
    int unit;
    RGE_Static_Object* obj;
    float distance;
    float n;

    i = 0;
    p = this->unitsValue;
    while (i < 40) {
        unit = *p;
        if (unit != -1) {
            obj = md->object(unit);
            if (obj == 0 || obj->unitAI() == 0) {
                this->removeUnitByIndex(i, md);
            } else {
                distance = obj->distance_to_position(
                    this->gatherLocationValue.x, this->gatherLocationValue.y, this->gatherLocationValue.z
                );
                distance = distance - 1.0f;
                if (distance < 0.0f) {
                    distance = 0.0f;
                }
                if (this->typeValue == 0x6D)
                    n = (float) t->strategicNumber(SNArtifactReturnDistance);
                else
                    n = (float) t->strategicNumber(SNAttackGroupGatherSpacing);
                if (distance > n) {
                    return 0;
                }
            }
        }
        i = i + 1;
        p = p + 1;
    }
    return 1;
}

int TacticalAIGroup::isTightGathered(TribeTacticalAIModule* t, TribeMainDecisionAIModule* md) {
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
            } else {
                dist = obj->distance_to_position(
                    this->gatherLocationValue.x, this->gatherLocationValue.y, this->gatherLocationValue.z
                );
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

int TacticalAIGroup::allUnitsIdle(TribeMainDecisionAIModule* md, int countAttackAsIdle) {
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
            } else if (obj->master_obj->id != MASTER_OBJECT_PRIEST) {
                if (countAttackAsIdle == 1) {
                    ai = obj->unitAI();
                    if (ai->currentAction() == UNIT_AI_ACTION_ATTACK) {
                        if (self->typeValue == TACTICAL_GROUP_TYPE_ATTACK
                            || self->typeValue == TACTICAL_GROUP_TYPE_BOAT_ATTACK) {
                            goto next;
                        }
                    }
                }
                ai = obj->unitAI();
                if (ai->currentAction() != -1) {
                    ai = obj->unitAI();
                    if (ai->currentOrder() != UNIT_AI_ORDER_DEFEND) {
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

unsigned long TacticalAIGroup::consecutiveIdleUnitCount() const {
    return this->consecutiveIdleUnitCountValue;
}

void TacticalAIGroup::setConsecutiveIdleUnitCount(unsigned long v) {
    this->consecutiveIdleUnitCountValue = v;
}

void TacticalAIGroup::incrementConsecutiveIdleUnitCount(unsigned long v) {
    this->consecutiveIdleUnitCountValue += v;
}

unsigned char TacticalAIGroup::numberAttackWaypoints() const {
    return this->numberAttackWaypointsValue;
}

unsigned char TacticalAIGroup::currentAttackWaypoint() const {
    return this->currentAttackWaypointValue;
}

void TacticalAIGroup::setCurrentAttackWaypoint(unsigned char v) {
    if (v < this->numberAttackWaypointsValue)
        this->currentAttackWaypointValue = v;
}

void TacticalAIGroup::addAttackWaypoint(float x, float y) {
    if (this->numberAttackWaypointsValue < 14) {
        this->attackWaypoints[this->numberAttackWaypointsValue].x = x;
        this->attackWaypoints[this->numberAttackWaypointsValue].y = y;
        this->attackWaypoints[this->numberAttackWaypointsValue].z = 1.0f;
        this->numberAttackWaypointsValue = this->numberAttackWaypointsValue + 1;
    }
}

Waypoint* TacticalAIGroup::attackWaypoint(unsigned char v) {
    if (v < this->numberAttackWaypointsValue)
        return this->attackWaypoints + v;
    return 0;
}

int TacticalAIGroup::firstIdleUnit(TribeMainDecisionAIModule* md) {
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
            } else {
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

int TacticalAIGroup::objectToDestroy(int n) {
    if (n < 0 || n >= 20)
        return -1;
    return this->objectsToDestroyValue[n];
}

int TacticalAIGroup::addObjectToDestroy(int id) {
    if (this->numberObjectsToDestroyValue < 0x13) {
        this->objectsToDestroyValue[this->numberObjectsToDestroyValue] = id;
        this->numberObjectsToDestroyValue = this->numberObjectsToDestroyValue + 1;
        return 1;
    }
    return 0;
}

TribeTacticalAIModule::TribeTacticalAIModule(void* pW, int pID) :
    TacticalAIModule(pW, pID), md(0), civilians(), civilianExplorers(), soldiers(), ungroupedSoldiers(), boats(),
    warBoats(), fishingBoats(), tradeBoats(), transportBoats(), artifacts(), numberGatherersValue(0),
    desiredNumberGatherersValue(0), groups(), groupIDValue(0), numberGroupsValue(0), lastGroupAttackTime(0),
    lastGroupRebalanceTime(0), lastAttackResponseTime(0), lastBoatAttackResponseTime(0), lastScalingUpdateValue(0),
    numberBuildUpdatesSkipped(0), randomizedAttackSeparationTime(0), playersToAttack(), playersToDefend(),
    workingArea(), unitsTaskedThisUpdate(), neededResources(4), attackEnabledValue(0), updateArea(0),
    firstNeededResourceUpdateDone(0), wonderInProgressValue(0), wonderBuiltValue(0), nextCivilianToTaskValue(-1),
    nextIdleSoldierGroupToTaskValue(-1), nextActiveSoldierGroupToTaskValue(-1), builtFirstStoragePit(0),
    builtFirstGranary(0), lastBuildTime(0), lastAttackResponseBuildInsertionTime(0), lastCoopTributeDemandTime(0),
    lastCoopTributeGiftTime(0), lastCoopAttackDemandTime(0), zoomingToNextAge(0), lastUngroupedSoldierTaskTime(0),
    lastUpdateAreaTimeValue(-1), averageUpdateAreaTimeValue(-1), updateAreaAverageCount(0), updateAreaAverageTotal(0) {
    int* value;
    int i;

    for (i = 0; i != 4; i = i + 1) {
        this->neededResourceValue[i] = -1;
        this->desiredGathererDistribution[i] = 0;
        this->actualGathererDistribution[i] = 0;
        this->resourceDifferenceValue[i] = 0;
        this->numberStoragePitsBuilt[i] = 0;
        this->numberGranariesBuilt[i] = 0;
    }

    value = this->sn;
    for (i = 0xe2; i != 0; i = i - 1) {
        *value = -1;
        value = value + 1;
    }
    value = this->hitsByPlayer;
    for (i = 9; i != 0; i = i - 1) {
        *value = 0;
        value = value + 1;
    }
    value = &this->gatherers[0].data1;
    i = 0x32;
    do {
        ((UnitData*) (value - 1))->id = -1;
        *value = -1;
        value[1] = -1;
        value[2] = -1;
        value[3] = -1;
        value = value + 6;
        i = i - 1;
    } while (i != 0);
    this->groups.next = &this->groups;
    this->groups.prev = &this->groups;
    this->placementStateValue.active = 0;
    this->attackStateValue.active = 0;
}

TribeTacticalAIModule::TribeTacticalAIModule(int pID, int infile) :
    TacticalAIModule(0, pID), md(0), civilians(), civilianExplorers(), soldiers(), ungroupedSoldiers(), boats(),
    warBoats(), fishingBoats(), tradeBoats(), transportBoats(), artifacts(), lastGroupRebalanceTime(0),
    playersToAttack(), playersToDefend(), workingArea(), unitsTaskedThisUpdate(), neededResources(4),
    attackEnabledValue(0), updateArea(0), firstNeededResourceUpdateDone(0), wonderInProgressValue(0),
    wonderBuiltValue(0), nextCivilianToTaskValue(-1), nextIdleSoldierGroupToTaskValue(-1),
    nextActiveSoldierGroupToTaskValue(-1), builtFirstStoragePit(0), builtFirstGranary(0), lastBuildTime(0),
    lastAttackResponseBuildInsertionTime(0), lastCoopTributeDemandTime(0), lastCoopTributeGiftTime(0),
    lastCoopAttackDemandTime(0), zoomingToNextAge(0), lastUngroupedSoldierTaskTime(0), lastUpdateAreaTimeValue(-1),
    averageUpdateAreaTimeValue(-1), updateAreaAverageCount(0), updateAreaAverageTotal(0) {
    int index;
    int* value_ptr;
    TacticalAIGroup* loaded_group;
    int remaining;
    int list_index;
    int loaded_value;

    TacticalAIGroup* group = &this->groups;
    this->groups.next = group;
    this->groups.prev = group;
    rge_read(infile, &pID, 4);
    list_index = 0;
    if (0 < pID) {
        do {
            rge_read(infile, &loaded_value, 4);
            this->civilians.add(loaded_value);
            list_index = list_index + 1;
        } while (list_index < pID);
    }
    rge_read(infile, &pID, 4);
    list_index = 0;
    if (0 < pID) {
        do {
            rge_read(infile, &loaded_value, 4);
            this->civilianExplorers.add(loaded_value);
            list_index = list_index + 1;
        } while (list_index < pID);
    }
    rge_read(infile, &this->numberGatherersValue, 4);
    rge_read(infile, &this->desiredNumberGatherersValue, 4);
    if (!(save_game_version < 7.19f)) {
        rge_read(infile, this->gatherers, 1200);
    } else {
        value_ptr = &this->gatherers[0].data1;
        remaining = 0x32;
        if (!(save_game_version < 7.17f)) {
            OldUnitData2 tempUD;

            do {
                rge_read(infile, &tempUD, 20);
                ((UnitData*) (value_ptr - 1))->id = tempUD.id;
                *value_ptr = tempUD.data1;
                value_ptr[1] = tempUD.data2;
                value_ptr[2] = tempUD.data3;
                value_ptr[3] = tempUD.target;
                value_ptr[4] = 0;
                value_ptr = value_ptr + 6;
                remaining = remaining - 1;
            } while (remaining != 0);
        } else {
            OldUnitData tempUD;

            do {
                rge_read(infile, &tempUD, 16);
                ((UnitData*) (value_ptr - 1))->id = tempUD.id;
                *value_ptr = tempUD.data1;
                value_ptr[1] = tempUD.data2;
                value_ptr[2] = tempUD.data3;
                value_ptr[3] = -1;
                value_ptr[4] = 0;
                value_ptr = value_ptr + 6;
                remaining = remaining - 1;
            } while (remaining != 0);
        }
    }
    rge_read(infile, &pID, 4);
    list_index = 0;
    if (0 < pID) {
        do {
            rge_read(infile, &loaded_value, 4);
            this->soldiers.add(loaded_value);
            list_index = list_index + 1;
        } while (list_index < pID);
    }
    if (!(save_game_version < 2.3f)) {
        rge_read(infile, &pID, 4);
        list_index = 0;
        if (0 < pID) {
            do {
                rge_read(infile, &loaded_value, 4);
                this->ungroupedSoldiers.add(loaded_value);
                list_index = list_index + 1;
            } while (list_index < pID);
        }
    }
    rge_read(infile, &pID, 4);
    list_index = 0;
    if (0 < pID) {
        do {
            rge_read(infile, &loaded_value, 4);
            this->boats.add(loaded_value);
            list_index = list_index + 1;
        } while (list_index < pID);
    }
    rge_read(infile, &pID, 4);
    list_index = 0;
    if (0 < pID) {
        do {
            rge_read(infile, &loaded_value, 4);
            this->warBoats.add(loaded_value);
            list_index = list_index + 1;
        } while (list_index < pID);
    }
    rge_read(infile, &pID, 4);
    list_index = 0;
    if (0 < pID) {
        do {
            rge_read(infile, &loaded_value, 4);
            this->fishingBoats.add(loaded_value);
            list_index = list_index + 1;
        } while (list_index < pID);
    }
    rge_read(infile, &pID, 4);
    list_index = 0;
    if (0 < pID) {
        do {
            rge_read(infile, &loaded_value, 4);
            this->tradeBoats.add(loaded_value);
            list_index = list_index + 1;
        } while (list_index < pID);
    }
    rge_read(infile, &pID, 4);
    list_index = 0;
    if (0 < pID) {
        do {
            rge_read(infile, &loaded_value, 4);
            this->transportBoats.add(loaded_value);
            list_index = list_index + 1;
        } while (list_index < pID);
    }
    if (!(save_game_version < 1.4f)) {
        rge_read(infile, &pID, 4);
        list_index = 0;
        if (0 < pID) {
            do {
                rge_read(infile, &loaded_value, 4);
                this->artifacts.add(loaded_value);
                list_index = list_index + 1;
            } while (list_index < pID);
        }
    }
    rge_read(infile, &pID, 4);
    index = 0;
    if (0 < pID) {
        value_ptr = this->sn;
        do {
            rge_read(infile, value_ptr, 4);
            index = index + 1;
            value_ptr = value_ptr + 1;
        } while (index < pID);
    }
    rge_read(infile, &pID, 4);
    list_index = 0;
    if (0 < pID) {
        do {
            rge_read(infile, &loaded_value, 4);
            this->playersToAttack.add(loaded_value);
            list_index = list_index + 1;
        } while (list_index < pID);
    }
    rge_read(infile, &pID, 4);
    list_index = 0;
    if (0 < pID) {
        do {
            rge_read(infile, &loaded_value, 4);
            this->playersToDefend.add(loaded_value);
            list_index = list_index + 1;
        } while (list_index < pID);
    }
    rge_read(infile, &pID, 4);
    list_index = 0;
    if (0 < pID) {
        do {
            rge_read(infile, &loaded_value, 4);
            this->workingArea.add(loaded_value);
            list_index = list_index + 1;
        } while (list_index < pID);
    }
    rge_read(infile, &pID, 4);
    list_index = 0;
    if (0 < pID) {
        do {
            rge_read(infile, &loaded_value, 4);
            this->unitsTaskedThisUpdate.add(loaded_value);
            list_index = list_index + 1;
        } while (list_index < pID);
    }
    value_ptr = this->actualGathererDistribution;
    index = 4;
    do {
        rge_read(infile, value_ptr, 4);
        value_ptr = value_ptr + 1;
        index = index - 1;
    } while (index != 0);
    value_ptr = this->desiredGathererDistribution;
    index = 4;
    do {
        rge_read(infile, value_ptr, 4);
        value_ptr = value_ptr + 1;
        index = index - 1;
    } while (index != 0);
    value_ptr = this->neededResourceValue;
    index = 4;
    do {
        rge_read(infile, value_ptr, 4);
        value_ptr = value_ptr + 1;
        index = index - 1;
    } while (index != 0);
    value_ptr = this->resourceDifferenceValue;
    index = 4;
    do {
        rge_read(infile, value_ptr, 4);
        value_ptr = value_ptr + 1;
        index = index - 1;
    } while (index != 0);
    value_ptr = this->numberStoragePitsBuilt;
    index = 4;
    do {
        rge_read(infile, value_ptr, 4);
        value_ptr = value_ptr + 1;
        index = index - 1;
    } while (index != 0);
    value_ptr = this->numberGranariesBuilt;
    index = 4;
    do {
        rge_read(infile, value_ptr, 4);
        value_ptr = value_ptr + 1;
        index = index - 1;
    } while (index != 0);
    index = 0;
    do {
        rge_read(infile, &loaded_value, 4);
        this->neededResources.setValue(index, loaded_value);
        index = index + 1;
    } while (index < 4);
    rge_read(infile, &this->groupIDValue, 4);
    value_ptr = &this->numberGroupsValue;
    rge_read(infile, value_ptr, 4);
    index = 0;
    if (0 < *value_ptr) {
        do {
            loaded_group = this->createGroup(0);
            if (loaded_group != (TacticalAIGroup*) 0x0) {
                loaded_group->load(infile);
            }
            index = index + 1;
        } while (index < *value_ptr);
    }
    rge_read(infile, &this->lastGroupAttackTime, 4);
    if (!(save_game_version < 2.4f)) {
        rge_read(infile, &this->lastGroupRebalanceTime, 4);
    }
    rge_read(infile, &this->lastAttackResponseTime, 4);
    rge_read(infile, &this->lastBoatAttackResponseTime, 4);
    rge_read(infile, &this->lastScalingUpdateValue, 4);
    rge_read(infile, &this->numberBuildUpdatesSkipped, 4);
    rge_read(infile, &this->randomizedAttackSeparationTime, 4);
    if (!(save_game_version < 2.2f)) {
        rge_read(infile, &this->attackEnabledValue, 4);
    }
    rge_read(infile, &this->updateArea, 4);
    if (!(save_game_version < 6.1f)) {
        rge_read(infile, &this->wonderInProgressValue, 4);
        rge_read(infile, &this->wonderBuiltValue, 4);
    }
    if (!(save_game_version < 6.2f)) {
        rge_read(infile, &this->placementStateValue, 304);
    } else {
        memset(&this->placementStateValue, 0, sizeof(this->placementStateValue));
    }
    (this->placementStateValue).active = 0;
    if (!(save_game_version < 6.3f)) {
        rge_read(infile, &this->nextCivilianToTaskValue, 4);
    }
    if (!(save_game_version < 6.4f)) {
        rge_read(infile, &this->nextIdleSoldierGroupToTaskValue, 4);
        rge_read(infile, &this->nextActiveSoldierGroupToTaskValue, 4);
    }
    if (!(save_game_version < 6.9f)) {
        rge_read(infile, &this->builtFirstStoragePit, 4);
        rge_read(infile, &this->builtFirstGranary, 4);
    }
    if (!(save_game_version < 6.95f)) {
        rge_read(infile, &this->lastBuildTime, 4);
        rge_read(infile, &this->lastAttackResponseBuildInsertionTime, 4);
        rge_read(infile, &this->lastCoopTributeDemandTime, 4);
    }
    if (!(save_game_version < 7.18f)) {
        rge_read(infile, &this->lastCoopTributeGiftTime, 4);
    }
    if (!(save_game_version < 6.96f)) {
        rge_read(infile, &this->zoomingToNextAge, 4);
    }
    if (!(save_game_version < 6.98f)) {
        rge_read(infile, &this->lastCoopAttackDemandTime, 4);
    }
    if (!(save_game_version < 6.993f)) {
        rge_read(infile, &this->lastUngroupedSoldierTaskTime, 4);
    }
    if (!(save_game_version < 7.04f)) {
        rge_read(infile, &this->attackStateValue, 44);
    } else {
        memset(&this->attackStateValue, 0, sizeof(this->attackStateValue));
    }
    (this->attackStateValue).active = 0;
    if (!(save_game_version < 7.15f)) {
        rge_read(infile, this->hitsByPlayer, 36);
    } else {
        value_ptr = this->hitsByPlayer;
        for (remaining = 9; remaining != 0; remaining = remaining - 1) {
            *value_ptr = 0;
            value_ptr = value_ptr + 1;
        }
    }
}

TribeTacticalAIModule::~TribeTacticalAIModule() {
    this->removeAllGroups(-1);
}

char* TribeTacticalAIModule::updateAreaName() {
    switch (this->updateArea) {
        case 0:
            return "Setup SolGroups";
        case 1:
            return "Eval CivDist";
        case 2:
            return "Task Civs";
        case 3:
            return "Setup BoatGroups";
        case 4:
            return "Fill BoatGroups";
        case 5:
            return "Task Boats";
        case 6:
            return "Fill SolGroups";
        case 7:
            return "Task IdleSol";
        case 8:
            return "Task ActSol";
        case 9:
            return "Playtasking";
        case 10:
            return "Task UngrpSol";
        case 11:
            return "Research";
        case 12:
            return "Train";
        case 13:
            return "BldLst Change";
        case 14:
            return "Help Build";
        case 15:
            return "Repair Bldg";
        case 16:
            return "Repair Wall";
        case 17:
            return "Build";
        case 18:
            return "Open Builds";
        case 19:
            return "Open Tasks";
        case 20:
            return "Food dropsite";
        case 21:
            return "BldLst Insertions";
        default:
            return "Invalid";
    }
}

// These three insertions call the allocation functions directly.
// The shared add method emits resize.
static inline int addTacticalPlayer(ManagedArray<int>& array, int valueToAdd) {
    int i;
    int* newValue;
    int newSize;

    for (i = 0; i < array.numberValue; i++) {
        if (i >= array.maximumSizeValue)
            break;
        if (array.value[i] == valueToAdd)
            return 0;
    }
    if (array.numberValue > array.maximumSizeValue - 1) {
        newSize = array.numberValue + 1;
        newValue = (int*) ::operator new(newSize * sizeof(int));
        if (newValue != 0) {
            for (i = 0; i < array.maximumSizeValue; i++) {
                if (i >= newSize)
                    break;
                newValue[i] = array.value[i];
            }
            ::operator delete(array.value);
            array.value = newValue;
            array.maximumSizeValue = newSize;
        }
    }
    array.value[array.numberValue] = valueToAdd;
    array.numberValue = array.numberValue + 1;
    return 1;
}

int TribeTacticalAIModule::update(int timeLimit) {
    //! SNScalingFrequency multiplies by 60000 here, so its unit is minutes against the millisecond clock.
    //! RockNROR replaces the unit with seconds and clamps low values to stop scaling every few ticks.
    if ((unsigned int) (this->md->player->world->world_time - this->lastScalingUpdateValue)
        > (unsigned int) (this->sn[SNScalingFrequency] * 60000)) {
        this->sn[SNMaximumAttackGroupSize] += this->sn[SNScaleMaximumAttackGroupSize];
        if (this->sn[SNMaximumAttackGroupSize] < 0) {
            this->sn[SNMaximumAttackGroupSize] = 0;
        }

        this->sn[SNMinimumAttackGroupSize] += this->sn[SNScaleMinimumAttackGroupSize];
        if (this->sn[SNMinimumAttackGroupSize] < 0) {
            this->sn[SNMinimumAttackGroupSize] = 0;
        }

        int value;
        if (this->sn[SNMinimumAttackGroupSize] > this->sn[SNMaximumAttackGroupSize]) {
            this->sn[SNMinimumAttackGroupSize] = this->sn[SNMaximumAttackGroupSize];
        }
        value = this->sn[SNMaximumAttackGroupSize];
        if (value < this->sn[SNMinimumAttackGroupSize]) {
            this->sn[SNMaximumAttackGroupSize] = this->sn[SNMinimumAttackGroupSize];
        }

        value = this->sn[SNPercentHealthRetreat] << 1;
        this->sn[SNPercentHealthRetreat] = value;
        if (value < 0) {
            this->sn[SNPercentHealthRetreat] = 0;
        }
        if (100 < this->sn[SNPercentHealthRetreat]) {
            this->sn[SNPercentHealthRetreat] = 100;
        }

        value = this->sn[SNPercentDeathRetreat] << 1;
        this->sn[SNPercentDeathRetreat] = value;
        if (value < 0) {
            this->sn[SNPercentDeathRetreat] = 0;
        }
        if (100 < this->sn[SNPercentDeathRetreat]) {
            this->sn[SNPercentDeathRetreat] = 100;
        }

        value = this->sn[SNPercentUnitHealthRetreat] << 1;
        this->sn[SNPercentUnitHealthRetreat] = value;
        if (value < 0) {
            this->sn[SNPercentUnitHealthRetreat] = 0;
        }
        if (100 < this->sn[SNPercentUnitHealthRetreat]) {
            this->sn[SNPercentUnitHealthRetreat] = 100;
        }

        this->lastScalingUpdateValue = this->md->player->world->world_time;
    }

    // This period array method preserves the md reread below.
    this->unitsTaskedThisUpdate.zeroNumber();
    this->md->informationAI.farmsTaskedThisUpdate.numberValue = 0;

    if ((unsigned int) this->md->player->world->world_time / 1000U >= (unsigned int) this->sn[SNInitialAttackDelay]) {
        this->enableAttack(2);
    }

    int mostHatedPlayer = this->md->diplomacyAI.mostHated(
        this->sn[SNTributeAmount], this->sn[SNTributePlayer], this->sn[0xBC], this->sn[0xC3]
    );
    int mostLikedPlayer = this->md->diplomacyAI.mostLiked(this->sn[SNTributeAmount], this->sn[SNTributePlayer]);

    this->playersToAttack.numberValue = 0;
    addTacticalPlayer(this->playersToAttack, mostHatedPlayer);

    this->playersToDefend.zeroNumber();
    addTacticalPlayer(this->playersToDefend, this->md->player->id);

    if (mostHatedPlayer != mostLikedPlayer) {
        addTacticalPlayer(this->playersToDefend, mostLikedPlayer);
    }

diplomacy: {
    int player = 1;
    if (1 < this->md->player->world->player_num) {
        do {
            if (player != this->md->player->id) {
                if (player == mostHatedPlayer) {
                    if (this->md->diplomacyAI.isEnemy(player) == 0 && this->md->diplomacyAI.isChangeable(player) != 0
                        && this->md->diplomacyAI.stance(player, 0) > 0x4A) {
                        this->md->diplomacyAI.setRelation(player, 3);
                    }
                } else if (player == mostLikedPlayer) {
                    if (this->md->diplomacyAI.isAlly(player) == 0 && this->md->diplomacyAI.isChangeable(player) != 0
                        && this->md->diplomacyAI.stance(player, 2) > 0x4A) {
                        this->md->diplomacyAI.setRelation(player, 0);
                    }
                } else {
                    int stance = this->md->diplomacyAI.stance(player, 2);
                    if (stance > this->sn[SNMinimumPeaceLikeLevel] && this->md->diplomacyAI.isChangeable(player) != 0) {
                        if (this->md->diplomacyAI.isAlly(player) == 0) {
                            this->md->diplomacyAI.setRelation(player, 0);
                        }
                    } else if (this->md->diplomacyAI.isNeutral(player) == 0
                               && this->md->diplomacyAI.isChangeable(player) != 0) {
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

void TribeTacticalAIModule::setMainDecisionAI(TribeMainDecisionAIModule* m) {
    this->md = m;
}

void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* ptr);

int TribeTacticalAIModule::save(int outfile) {
    int i;
    int tempInt;
    TacticalAIGroup* group;

    tempInt = this->civilians.numberValue;
    rge_write(outfile, &tempInt, 4);
    for (i = 0; i < this->civilians.numberValue; i++) {
        tempInt = this->civilians[i];
        rge_write(outfile, &tempInt, 4);
    }

    tempInt = this->civilianExplorers.numberValue;
    rge_write(outfile, &tempInt, 4);
    for (i = 0; i < this->civilianExplorers.numberValue; i++) {
        tempInt = this->civilianExplorers[i];
        rge_write(outfile, &tempInt, 4);
    }

    rge_write(outfile, &this->numberGatherersValue, 4);
    rge_write(outfile, &this->desiredNumberGatherersValue, 4);
    rge_write(outfile, this->gatherers, 1200);

    tempInt = this->soldiers.numberValue;
    rge_write(outfile, &tempInt, 4);
    for (i = 0; i < this->soldiers.numberValue; i++) {
        tempInt = this->soldiers[i];
        rge_write(outfile, &tempInt, 4);
    }

    tempInt = this->ungroupedSoldiers.numberValue;
    rge_write(outfile, &tempInt, 4);
    for (i = 0; i < this->ungroupedSoldiers.numberValue; i++) {
        tempInt = this->ungroupedSoldiers[i];
        rge_write(outfile, &tempInt, 4);
    }

    tempInt = this->boats.numberValue;
    rge_write(outfile, &tempInt, 4);
    for (i = 0; i < this->boats.numberValue; i++) {
        tempInt = this->boats[i];
        rge_write(outfile, &tempInt, 4);
    }

    tempInt = this->warBoats.numberValue;
    rge_write(outfile, &tempInt, 4);
    for (i = 0; i < this->warBoats.numberValue; i++) {
        tempInt = this->warBoats[i];
        rge_write(outfile, &tempInt, 4);
    }

    tempInt = this->fishingBoats.numberValue;
    rge_write(outfile, &tempInt, 4);
    for (i = 0; i < this->fishingBoats.numberValue; i++) {
        tempInt = this->fishingBoats[i];
        rge_write(outfile, &tempInt, 4);
    }

    tempInt = this->tradeBoats.numberValue;
    rge_write(outfile, &tempInt, 4);
    for (i = 0; i < this->tradeBoats.numberValue; i++) {
        tempInt = this->tradeBoats[i];
        rge_write(outfile, &tempInt, 4);
    }

    tempInt = this->transportBoats.numberValue;
    rge_write(outfile, &tempInt, 4);
    for (i = 0; i < this->transportBoats.numberValue; i++) {
        tempInt = this->transportBoats[i];
        rge_write(outfile, &tempInt, 4);
    }

    tempInt = this->artifacts.numberValue;
    rge_write(outfile, &tempInt, 4);
    for (i = 0; i < this->artifacts.numberValue; i++) {
        tempInt = this->artifacts[i];
        rge_write(outfile, &tempInt, 4);
    }

    tempInt = 226;
    rge_write(outfile, &tempInt, 4);
    for (i = 0; i < tempInt; i++) {
        rge_write(outfile, &this->sn[i], 4);
    }

    tempInt = this->playersToAttack.numberValue;
    rge_write(outfile, &tempInt, 4);
    for (i = 0; i < this->playersToAttack.numberValue; i++) {
        tempInt = this->playersToAttack[i];
        rge_write(outfile, &tempInt, 4);
    }

    tempInt = this->playersToDefend.numberValue;
    rge_write(outfile, &tempInt, 4);
    for (i = 0; i < this->playersToDefend.numberValue; i++) {
        tempInt = this->playersToDefend[i];
        rge_write(outfile, &tempInt, 4);
    }

    tempInt = this->workingArea.numberValue;
    rge_write(outfile, &tempInt, 4);
    for (i = 0; i < this->workingArea.numberValue; i++) {
        tempInt = this->workingArea[i];
        rge_write(outfile, &tempInt, 4);
    }

    tempInt = this->unitsTaskedThisUpdate.numberValue;
    rge_write(outfile, &tempInt, 4);
    for (i = 0; i < this->unitsTaskedThisUpdate.numberValue; i++) {
        tempInt = this->unitsTaskedThisUpdate[i];
        rge_write(outfile, &tempInt, 4);
    }

    for (i = 0; i < 4; i++) {
        rge_write(outfile, &this->actualGathererDistribution[i], 4);
    }
    for (i = 0; i < 4; i++) {
        rge_write(outfile, &this->desiredGathererDistribution[i], 4);
    }
    for (i = 0; i < 4; i++) {
        rge_write(outfile, &this->neededResourceValue[i], 4);
    }
    for (i = 0; i < 4; i++) {
        rge_write(outfile, &this->resourceDifferenceValue[i], 4);
    }
    for (i = 0; i < 4; i++) {
        rge_write(outfile, &this->numberStoragePitsBuilt[i], 4);
    }
    for (i = 0; i < 4; i++) {
        rge_write(outfile, &this->numberGranariesBuilt[i], 4);
    }
    for (i = 0; i < 4; i++) {
        tempInt = this->neededResources.value(i);
        rge_write(outfile, &tempInt, 4);
    }

    rge_write(outfile, &this->groupIDValue, 4);
    rge_write(outfile, &this->numberGroupsValue, 4);
    group = this->groups.next;
    while (group != &this->groups && group != 0) {
        group->save(outfile);
        group = group->next;
    }

    rge_write(outfile, &this->lastGroupAttackTime, 4);
    rge_write(outfile, &this->lastGroupRebalanceTime, 4);
    rge_write(outfile, &this->lastAttackResponseTime, 4);
    rge_write(outfile, &this->lastBoatAttackResponseTime, 4);
    rge_write(outfile, &this->lastScalingUpdateValue, 4);
    rge_write(outfile, &this->numberBuildUpdatesSkipped, 4);
    rge_write(outfile, &this->randomizedAttackSeparationTime, 4);
    rge_write(outfile, &this->attackEnabledValue, 4);
    rge_write(outfile, &this->updateArea, 4);
    rge_write(outfile, &this->wonderInProgressValue, 4);
    rge_write(outfile, &this->wonderBuiltValue, 4);
    rge_write(outfile, &this->placementStateValue, 304);
    rge_write(outfile, &this->nextCivilianToTaskValue, 4);
    rge_write(outfile, &this->nextIdleSoldierGroupToTaskValue, 4);
    rge_write(outfile, &this->nextActiveSoldierGroupToTaskValue, 4);
    rge_write(outfile, &this->builtFirstStoragePit, 4);
    rge_write(outfile, &this->builtFirstGranary, 4);
    rge_write(outfile, &this->lastBuildTime, 4);
    rge_write(outfile, &this->lastAttackResponseBuildInsertionTime, 4);
    rge_write(outfile, &this->lastCoopTributeDemandTime, 4);
    rge_write(outfile, &this->lastCoopTributeGiftTime, 4);
    rge_write(outfile, &this->zoomingToNextAge, 4);
    rge_write(outfile, &this->lastCoopAttackDemandTime, 4);
    rge_write(outfile, &this->lastUngroupedSoldierTaskTime, 4);
    rge_write(outfile, &this->attackStateValue, 44);
    rge_write(outfile, this->hitsByPlayer, 36);
    return 1;
}

void __cdecl TribeTacticalAIModule::logGroupDebug(int gID, char* textIn, ...) {
}

int TribeTacticalAIModule::doSomething() {
    unsigned long availableTime = this->md->player->world->availableComputerPlayerUpdateTime;
    unsigned long startTime = debug_timeGetTime(s_file, 2460);

    if (availableTime != 0) {
        unsigned long currentTime;
        do {
            unsigned long updateAreaStartTime = debug_timeGetTime(s_file, 2463);
            int incUpdateArea = 1;

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
                    if (this->nextCivilianToTaskValue != -1)
                        incUpdateArea = 0;
                    break;

                case 3:
                    if (this->boats.numberValue > 0)
                        this->setupBoatGroups();
                    break;

                case 4:
                    if (this->boats.numberValue > 0)
                        this->fillBoatGroups();
                    break;

                case 5:
                    if (this->boats.numberValue > 0)
                        this->taskBoats();
                    break;

                case 6:
                    if (this->boats.numberValue > 0 || this->soldiers.numberValue > 0)
                        this->fillSoldierGroups();
                    break;

                case 7:
                    if (this->boats.numberValue > 0 || this->soldiers.numberValue > 0
                        || this->artifacts.numberValue > 0) {
                        this->taskIdleSoldiers(startTime, availableTime);
                        if (this->nextIdleSoldierGroupToTaskValue != -1)
                            incUpdateArea = 0;
                    }
                    break;

                case 8:
                    if (this->boats.numberValue > 0 || this->soldiers.numberValue > 0
                        || this->artifacts.numberValue > 0) {
                        this->taskActiveSoldiers(startTime, availableTime);
                        if (this->nextActiveSoldierGroupToTaskValue != -1)
                            incUpdateArea = 0;
                    }
                    break;

                case 9:
                    if (this->soldiers.numberValue > 0)
                        this->playTaskSoldiers(startTime, availableTime);
                    break;

                case 10: {
                    RGE_Static_Object* object = this->md->object(
                        -1, MASTER_OBJECT_TOWN_CENTER1, -1, -1, -1, -1, -1, -1, RGE_OBJECT_STATE_ANY, -1
                    );
                    if (object != 0) {
                        int id = this->md->informationAI.withinXTilesOfObject(object, 0x14, 0x4f, 0xc7, 0x45, 0x116);
                        if (id != -1)
                            this->saveTheTown(id);
                    }
                    break;
                }

                case 11:
                    this->numberBuildUpdatesSkipped++;
                    if (this->md->buildAI.buildListLength() > 0
                        && this->numberBuildUpdatesSkipped >= this->sn[SNBuildFrequency]) {
                        BuildItem* item = this->md->buildAI.nextBuildableItem(BUILD_CATEGORY_RESEARCH);
                        if (item != 0)
                            this->taskResearch(item);
                    }
                    break;

                case 12:
                    if (this->md->player->attributes[PLAYER_ATTRIBUTE_POPULATION]
                            < this->md->player->attributes[PLAYER_ATTRIBUTE_POPULATION_LIMIT]
                        && this->md->buildAI.buildListLength() > 0
                        && this->numberBuildUpdatesSkipped >= this->sn[SNBuildFrequency]) {
                        BuildItem* item = this->md->buildAI.nextBuildableItem(BUILD_CATEGORY_UNIT);
                        if (item != 0)
                            this->taskTrain(item);
                    }
                    break;

                case 13:
                    if (this->md->buildAI.buildListLength() > 0
                        && this->numberBuildUpdatesSkipped >= this->sn[SNBuildFrequency]) {
                        BuildItem* item = this->md->buildAI.nextBuildableItem(BUILD_CATEGORY_LOAD_BUILD_LIST);
                        if (item != 0) {
                            char tempName[256];
                            sprintf(tempName, "%s.bld", item->name());
                            this->md->buildAI.loadBuildList(tempName, this->md->aiPlayer);
                            this->md->updateBuildAIWithObjects();
                            this->updateNeededResources();
                        }
                        this->numberBuildUpdatesSkipped = 0;
                    }
                    break;

                case 14:
                    if (this->initialExplorationSatisfied() != 0
                        && (this->md->numberObjectsWithAction(UNIT_AI_ACTION_BUILD) < this->sn[SNCapCivilianBuilders]
                            || this->wonderInProgressValue != 0 || this->wonderBuiltValue != 0)) {
                        RGE_Static_Object* object =
                            this->md->object(-1, -1, -1, -1, -1, -1, -1, -1, RGE_OBJECT_STATE_UNBUILT, -1);
                        if (object != 0) {
                            RGE_Static_Object* builder = this->md->object(
                                -1, -1, -1, UNIT_AI_ACTION_BUILD, -1, (int) object->id, -1, -1, RGE_OBJECT_STATE_ANY, -1
                            );
                            if (this->wonderInProgressValue != 0 || builder == 0) {
                                XYPoint position;
                                position.x = (int) object->world_x;
                                position.y = (int) object->world_y;
                                int civilian = this->civilian(
                                    position, 1, UNIT_AI_ORDER_BUILD, UNIT_AI_ORDER_REPAIR, UNIT_AI_ORDER_ATTACK, 0
                                );
                                if (civilian != -1 && this->taskBuilder(civilian, object) == 1) {
                                    this->lastBuildTime = this->md->player->world->world_time;
                                }
                            }
                        }
                    }
                    break;

                case 15:
                    if (this->initialExplorationSatisfied() != 0
                        && (this->md->numberObjectsWithAction(UNIT_AI_ACTION_BUILD) < this->sn[SNCapCivilianBuilders]
                            || this->wonderInProgressValue != 0 || this->wonderBuiltValue != 0)) {
                        int type = this->wonderBuiltValue == 1 ? MASTER_OBJECT_WONDER : -1;
                        RGE_Static_Object* object = this->md->mostDamaged(OBJECT_GROUP_BUILDING, type);
                        if (object != 0 && object->object_state == RGE_OBJECT_STATE_ACTIVE
                            && this->md->object(
                                   -1, -1, -1, UNIT_AI_ACTION_REPAIR, -1, (int) object->id, -1, -1,
                                   RGE_OBJECT_STATE_ANY, -1
                               ) == 0) {
                            XYPoint position;
                            position.x = (int) object->world_x;
                            position.y = (int) object->world_y;
                            int civilian = this->civilian(
                                position, 1, UNIT_AI_ORDER_BUILD, UNIT_AI_ORDER_REPAIR, UNIT_AI_ORDER_ATTACK, 0
                            );
                            if (civilian != -1)
                                this->taskRepairer(civilian, object);
                        }
                    }
                    break;

                case 16:
                    if (this->initialExplorationSatisfied() != 0
                        && (this->md->numberObjectsWithAction(UNIT_AI_ACTION_BUILD) < this->sn[SNCapCivilianBuilders]
                            || this->wonderInProgressValue != 0 || this->wonderBuiltValue != 0)) {
                        RGE_Static_Object* object = this->md->mostDamaged(OBJECT_GROUP_WALL, -1);
                        if (object != 0 && object->object_state == RGE_OBJECT_STATE_ACTIVE
                            && this->md->object(
                                   -1, -1, -1, UNIT_AI_ACTION_REPAIR, -1, (int) object->id, -1, -1,
                                   RGE_OBJECT_STATE_ANY, -1
                               ) == 0) {
                            XYPoint position;
                            position.x = (int) object->world_x;
                            position.y = (int) object->world_y;
                            int civilian = this->civilian(
                                position, 1, UNIT_AI_ORDER_BUILD, UNIT_AI_ORDER_REPAIR, UNIT_AI_ORDER_ATTACK, 0
                            );
                            if (civilian != -1)
                                this->taskRepairer(civilian, object);
                        }
                    }
                    break;

                case 17:
                    if (this->initialExplorationSatisfied() != 0
                        && (this->md->numberObjectsWithAction(UNIT_AI_ACTION_BUILD) < this->sn[SNCapCivilianBuilders]
                            || (this->wonderInProgressValue == 0 && this->wonderBuiltValue != 0))
                        && this->wonderInProgressValue == 0) {
                        BuildItem* item = this->md->buildAI.nextBuildableItem(BUILD_CATEGORY_BUILDING);
                        if (item != 0 && this->taskBuilder(-1, item, 0, startTime) == 1) {
                            this->lastBuildTime = this->md->player->world->world_time;
                        }
                    }
                    break;

                case 18:
                    if (this->placementStateValue.active == 1) {
                        ConstructionItem* construction = this->md->constructionAI.placeStructure(
                            this->placementStateValue.buildItem, this->placementStateValue.builderID,
                            this->placementStateValue, startTime
                        );
                        if (construction != 0
                            && this->taskBuilder(
                                   this->placementStateValue.builderID, this->placementStateValue.buildItem,
                                   construction, startTime
                               ) == 1) {
                            this->lastBuildTime = this->md->player->world->world_time;
                        }
                        if (this->placementStateValue.active == 1)
                            incUpdateArea = 0;
                    }
                    break;

                case 19:
                    this->evaluateOpenTasks();
                    {
                        int i;
                        for (i = 0; i < 4; i++) {
                            if (this->resourceDifferenceValue[i] > 0
                                && this->md->resourceAI.resource(i) + this->resourceDifferenceValue[i] < 0) {
                                this->updateNeededResources();
                                break;
                            }
                        }
                    }
                    this->checkForCoopTributeDemand();
                    this->checkForCoopTributeGift();
                    this->checkForASAPAgeResearch();
                    this->checkTradeBoats();
                    this->checkStaleAttackGroups();
                    break;

                case 20: {
                    int id = this->md->informationAI.closestDropsiteResID(0);
                    if (this->md->object(id) == 0)
                        this->md->informationAI.updateResourceDropsites(0);
                    break;
                }

                case 21: {
                    this->evaluateBuildListInsertions();
                    if ((int) (this->md->player->world->world_time - this->lastBuildTime) / 60000 > 5) {
                        this->md->buildAI.unskipBuildList(this->builtFirstStoragePit, this->builtFirstGranary);
                        this->lastBuildTime = this->md->player->world->world_time;
                    }

                    currentTime = debug_timeGetTime(s_file, 2962);
                    this->md->player->world->useComputerPlayerUpdateTime(currentTime - startTime);

                    this->lastUpdateAreaTimeValue = currentTime - updateAreaStartTime;
                    this->updateAreaAverageTotal += this->lastUpdateAreaTimeValue;
                    this->updateAreaAverageCount++;
                    if (this->updateAreaAverageCount >= 20) {
                        this->averageUpdateAreaTimeValue = this->updateAreaAverageTotal / this->updateAreaAverageCount;
                        this->updateAreaAverageTotal = 0;
                        this->updateAreaAverageCount = 0;
                    }
                    this->updateArea = 0;
                    this->md->player->world->selectNextComputerPlayer(3);
                    return 1;
                }
            }

            currentTime = debug_timeGetTime(s_file, 2986);
            this->lastUpdateAreaTimeValue = currentTime - updateAreaStartTime;
            this->updateAreaAverageTotal += this->lastUpdateAreaTimeValue;
            this->updateAreaAverageCount++;
            if (this->updateAreaAverageCount >= 20) {
                this->averageUpdateAreaTimeValue = this->updateAreaAverageTotal / 20;
                this->updateAreaAverageTotal = 0;
                this->updateAreaAverageCount = 0;
            }
            if (incUpdateArea != 0)
                this->updateArea++;
        } while (currentTime - startTime < availableTime);
    }

    unsigned long endTime = debug_timeGetTime(s_file, 3017);
    this->md->player->world->useComputerPlayerUpdateTime(endTime - startTime);
    return 1;
}

int TribeTacticalAIModule::clearArea(int id, float minX, float minY, float maxX, float maxY) {
    if (this->busyWithAction(id, -1) == 1) {
        RGE_Static_Object* object = this->md->object(id);
        if (object != 0) {
            float newX = -1.0f;
            float newY = -1.0f;
            float bestDistance = -1.0f;
            float tempX = -1.0f;
            float tempY = -1.0f;

            for (int i = 0; i < 8; i++) {
                switch (i) {
                    case 0:
                        tempX = minX - 2.0f;
                        tempY = minY - 2.0f;
                        break;
                    case 2:
                        tempX = maxX + 2.0f;
                        break;
                    case 4:
                        tempY = maxY + 2.0f;
                        break;
                    case 1:
                    case 5:
                        tempX = (maxX + minX) * 0.5f;
                        break;
                    case 6:
                        tempX = minX - 2.0f;
                        break;
                    case 3:
                    case 7:
                        tempY = (maxY + minY) * 0.5f;
                        break;
                }

                if (object->passableTile(tempX, tempY, 1) != 0) {
                    float distance = object->distance_to_position(tempX, tempY, object->world_z);
                    if (bestDistance == -1.0f || distance < bestDistance) {
                        bestDistance = distance;
                        newX = tempX;
                        newY = tempY;
                    }
                }
            }

            if (bestDistance != -1.0f) {
                this->moveUnit(id, newX, newY, 100);
                return 1;
            }
        }
    }
    return 0;
}

void TribeTacticalAIModule::addObject(RGE_Static_Object* bo) {
    RGE_Static_Object* objectToAdd = bo;
    short objectGroup = objectToAdd->master_obj->object_group;
    int objectId;
    int number;
    int i;
    ManagedArray<int>* list;
    int (ManagedArray<int>::*resize)(int) = &ManagedArray<int>::resize;
    int (ManagedArray<int>::*contains)(const int&) = &ManagedArray<int>::contains;
    int (ManagedArray<int>::*add)(int) = &ManagedArray<int>::add;

    if (objectGroup == OBJECT_GROUP_CIVILIAN) {
        number = this->civilians.numberValue;
        objectId = objectToAdd->id;
        list = &this->civilians;
        for (i = 0; i < number; i++) {
            if (i >= list->maximumSizeValue)
                break;
            if (list->value[i] == objectId)
                return;
        }
        if (number <= list->maximumSizeValue - 1)
            goto add_to_list;
    } else {
        if (objectGroup != OBJECT_GROUP_ARCHER && objectGroup != OBJECT_GROUP_WAR_ELEPHANT
            && objectGroup != OBJECT_GROUP_INFANTRY && objectGroup != OBJECT_GROUP_HERO
            && objectGroup != OBJECT_GROUP_ELEPHANT_ARCHER && objectGroup != OBJECT_GROUP_CAVALRY
            && objectGroup != OBJECT_GROUP_CHARIOT && objectGroup != OBJECT_GROUP_CHARIOT_ARCHER
            && objectGroup != OBJECT_GROUP_HORSE_ARCHER && objectGroup != OBJECT_GROUP_PHALANX
            && objectGroup != OBJECT_GROUP_PRIEST && objectGroup != OBJECT_GROUP_SIEGE_WEAPON
            && objectGroup != OBJECT_GROUP_SLINGER) {
            if (objectGroup != OBJECT_GROUP_TRADE_BOAT && objectGroup != OBJECT_GROUP_TRANSPORT_BOAT
                && objectGroup != OBJECT_GROUP_WAR_BOAT && objectGroup != OBJECT_GROUP_FISHING_BOAT) {
                if (objectToAdd->master_obj->id != MASTER_OBJECT_ARTIFACT1)
                    return;
                if (this->md->player->world->difficultyLevel() >= RGE_DIFFICULTY_EASIEST)
                    return;
                (this->artifacts.*add)(objectToAdd->id);
                return;
            }

            int boatId = objectToAdd->id;
            ManagedArray<int>* boatList = &this->boats;
            number = boatList->numberValue;
            i = 0;
            if (number > 0) {
                do {
                    if (i >= boatList->maximumSizeValue)
                        break;
                    if (boatList->value[i] == boatId)
                        goto boat_added;
                    i++;
                } while (i < number);
            }
            if (number > boatList->maximumSizeValue - 1)
                (boatList->*resize)(number + 1);
            boatList->value[boatList->numberValue] = boatId;
            boatList->numberValue = boatList->numberValue + 1;

        boat_added:
            if (objectToAdd->master_obj->object_group == OBJECT_GROUP_TRADE_BOAT) {
                int tradeId = objectToAdd->id;
                ManagedArray<int>* tradeList = &this->tradeBoats;
                number = tradeList->numberValue;
                i = 0;
                if (number > 0) {
                    do {
                        if (i >= tradeList->maximumSizeValue)
                            break;
                        if (tradeList->value[i] == tradeId)
                            goto trade_added;
                        i++;
                    } while (i < number);
                }
                if (number > tradeList->maximumSizeValue - 1)
                    (tradeList->*resize)(number + 1);
                tradeList->value[tradeList->numberValue] = tradeId;
                tradeList->numberValue = tradeList->numberValue + 1;
            }

        trade_added:

            if (objectToAdd->master_obj->object_group == OBJECT_GROUP_TRANSPORT_BOAT) {
                int transportId = objectToAdd->id;
                ManagedArray<int>* transportList = &this->transportBoats;
                if ((transportList->*contains)(transportId) != 1) {
                    number = transportList->numberValue;
                    if (number > transportList->maximumSizeValue - 1)
                        (transportList->*resize)(number + 1);
                    transportList->value[transportList->numberValue] = transportId;
                    transportList->numberValue = transportList->numberValue + 1;
                }
            }

            if (objectToAdd->master_obj->object_group == OBJECT_GROUP_WAR_BOAT) {
                int warId = objectToAdd->id;
                ManagedArray<int>* warList = &this->warBoats;
                if ((warList->*contains)(warId) != 1) {
                    number = warList->numberValue;
                    if (number > warList->maximumSizeValue - 1)
                        (warList->*resize)(number + 1);
                    warList->value[warList->numberValue] = warId;
                    warList->numberValue = warList->numberValue + 1;
                }
            }

            if (objectToAdd->master_obj->object_group != OBJECT_GROUP_FISHING_BOAT)
                return;

            {
                int fishingId = objectToAdd->id;
                ManagedArray<int>* fishingList = &this->fishingBoats;
                if ((fishingList->*contains)(fishingId) == 1)
                    return;
                number = fishingList->numberValue;
                if (number > fishingList->maximumSizeValue - 1)
                    (fishingList->*resize)(number + 1);
                fishingList->value[fishingList->numberValue] = fishingId;
                fishingList->numberValue = fishingList->numberValue + 1;
            }
            return;
        }

        number = this->soldiers.numberValue;
        objectId = objectToAdd->id;
        list = &this->soldiers;
        for (i = 0; i < number; i++) {
            if (i >= list->maximumSizeValue)
                break;
            if (list->value[i] == objectId)
                return;
        }
        if (number <= list->maximumSizeValue - 1)
            goto add_to_list;
    }

    (list->*resize)(number + 1);

add_to_list:
    list->value[list->numberValue] = objectId;
    list->numberValue = list->numberValue + 1;
}

void TribeTacticalAIModule::removeObject(int id) {
    this->removeFromTaskLists(id);

    if (this->civilians.contains(id)) {
        this->civilians.remove(id);
    } else if (this->soldiers.contains(id)) {
        this->soldiers.remove(id);
    } else {
        if (this->boats.contains(id)) {
            this->boats.remove(id);

            if (this->warBoats.contains(id)) {
                int removeIndex = 0;
                int maximum = this->warBoats.maximumSizeValue;
                for (; removeIndex < maximum; removeIndex++) {
                    if (this->warBoats.value[removeIndex] == id)
                        break;
                }
                if (removeIndex < maximum) {
                    maximum--;
                    if (removeIndex < maximum) {
                        do {
                            this->warBoats.value[removeIndex] = this->warBoats.value[removeIndex + 1];
                            removeIndex++;
                        } while (removeIndex < this->warBoats.maximumSizeValue - 1);
                    }
                    this->warBoats.numberValue--;
                    if (this->warBoats.numberValue < 0)
                        this->warBoats.numberValue = 0;
                }
                this->removeFromGroup(id);
                return;
            }
            if (this->fishingBoats.contains(id))
                this->fishingBoats.remove(id);
            else if (this->tradeBoats.contains(id))
                this->tradeBoats.remove(id);
            else if (this->transportBoats.contains(id))
                this->transportBoats.remove(id);
        } else {
            if (this->artifacts.contains(id))
                this->artifacts.remove(id);
        }
    }

    this->removeFromGroup(id);
}

void TribeTacticalAIModule::evaluateCivilianDistribution() {
    int percentExplored;
    int enemyObjects;
    int soldierExplorers;

    percentExplored = (int) (this->md->player->visible->percentExplored() * 100.0f);
    enemyObjects = this->md->informationAI.numberGameIDsOwnedBy(-1, this->playersToAttack[0]);

    if (this->civilians.numberValue >= 3) {
        if (this->md->informationAI.fullyExploredZone(this->civilians[0]) == 1) {
            this->civilianExplorers.desiredNumberValue = (int) ceil(
                (double) ((float) this->sn[SNPercentCivilianExplorers] * this->civilians.numberValue * 0.01f)
            );
            soldierExplorers = this->numberSoldierExplorers();
            if (this->civilianExplorers.desiredNumberValue + soldierExplorers > this->sn[SNTotalNumberExplorers]) {
                this->civilianExplorers.desiredNumberValue = this->sn[SNTotalNumberExplorers] - soldierExplorers;
            }
            if (this->sn[SNCapCivilianExplorers] != -1
                && this->civilianExplorers.desiredNumberValue > this->sn[SNCapCivilianExplorers]) {
                this->civilianExplorers.desiredNumberValue = this->sn[SNCapCivilianExplorers];
            }
        } else {
            this->civilianExplorers.desiredNumberValue = 0;
        }

        if (percentExplored >= this->sn[SNPercentExplorationRequired] && enemyObjects > this->sn[0x91]) {
            if (this->civilianExplorers.desiredNumberValue > this->sn[SNMinimumCivilianExplorers]) {
                this->civilianExplorers.desiredNumberValue = this->sn[SNMinimumCivilianExplorers];
            }
        } else if (percentExplored >= this->sn[0xb3]) {
            this->civilianExplorers.desiredNumberValue /= 2;
            if (this->civilianExplorers.desiredNumberValue < 1) {
                this->civilianExplorers.desiredNumberValue = 0;
            }
        }

        if (this->zoomingToNextAge == 1) {
            this->civilianExplorers.desiredNumberValue = 0;
        }

        this->desiredNumberGatherersValue = this->civilians.numberValue - this->civilianExplorers.desiredNumberValue;
        if (this->sn[SNCapCivilianGatherers] != -1
            && this->desiredNumberGatherersValue > this->sn[SNCapCivilianGatherers]) {
            this->desiredNumberGatherersValue = this->sn[SNCapCivilianGatherers];
        }
    } else if (this->civilians.numberValue == 1) {
        this->desiredNumberGatherersValue = 0;
        this->civilianExplorers.desiredNumberValue = 1;
    } else {
        this->desiredNumberGatherersValue = 1;
        if (this->sn[SNCapCivilianGatherers] != -1
            && this->desiredNumberGatherersValue > this->sn[SNCapCivilianGatherers]) {
            this->desiredNumberGatherersValue = this->sn[SNCapCivilianGatherers];
        }
        this->civilianExplorers.desiredNumberValue = this->civilians.numberValue - this->desiredNumberGatherersValue;
        if (this->sn[SNCapCivilianExplorers] != -1
            && this->civilianExplorers.desiredNumberValue > this->sn[SNCapCivilianExplorers]) {
            this->civilianExplorers.desiredNumberValue = this->sn[SNCapCivilianExplorers];
        }
    }

    this->displayCivilianDistribution();
    this->updateGathererDistribution();
}

int TribeTacticalAIModule::taskCivilians(unsigned long startTime, unsigned long availableTime) {
    int taskedCount;
    int j;
    int newExplorer;
    XYPoint tcPosition;
    RGE_Static_Object* townCenter;

    if (this->civilians.numberValue <= 0) {
        this->nextCivilianToTaskValue = -1;
        return 0;
    }

    taskedCount = 0;
    if (this->nextCivilianToTaskValue == -1) {
        while (this->civilianExplorers.numberValue < this->civilianExplorers.desiredNumberValue) {
            townCenter =
                this->md->object(-1, MASTER_OBJECT_TOWN_CENTER1, -1, -1, -1, -1, -1, -1, RGE_OBJECT_STATE_ANY, -1);
            if (townCenter != 0) {
                tcPosition.x = (int) townCenter->world_x;
                tcPosition.y = (int) townCenter->world_y;
                newExplorer = this->idleCivilian(-1, tcPosition, 0);
            } else {
                newExplorer = this->idleCivilian(-1);
            }

            if (newExplorer == -1 && this->desiredNumberGatherersValue < this->numberGatherersValue) {
                for (j = 3; j >= 0 && newExplorer == -1; j--) {
                    RGE_Static_Object* resource = this->md->object(
                        -1, -1, -1, UNIT_AI_ACTION_GATHER, UNIT_AI_ACTION_EXPLORE, -1, -1, this->neededResourceValue[j],
                        RGE_OBJECT_STATE_ANY, 0
                    );
                    if (resource == 0) {
                        resource = this->md->object(
                            -1, -1, -1, UNIT_AI_ACTION_HUNT, UNIT_AI_ACTION_EXPLORE, -1, -1,
                            this->neededResourceValue[j], RGE_OBJECT_STATE_ANY, 0
                        );
                    }
                    if (resource != 0 && resource->attribute_amount_held == 0.0f
                        && this->civilianExplorers.contains(resource->id) == 0) {
                        newExplorer = resource->id;
                        this->removeGatherer(newExplorer);
                    }
                }
            }

            if (newExplorer == -1 || this->civilianExplorers.add(newExplorer) == 0) {
                break;
            }
        }

        while (this->civilianExplorers.numberValue > this->civilianExplorers.desiredNumberValue) {
            if (this->civilianExplorers.numberValue < 1)
                break;
            newExplorer = this->civilianExplorers[0];
            this->civilianExplorers.remove(newExplorer);
            this->stopUnit(newExplorer, 100);
        }

        while (this->numberGatherersValue < this->desiredNumberGatherersValue) {
            townCenter =
                this->md->object(-1, MASTER_OBJECT_TOWN_CENTER1, -1, -1, -1, -1, -1, -1, RGE_OBJECT_STATE_ANY, -1);
            if (townCenter != 0) {
                tcPosition.x = (int) townCenter->world_x;
                tcPosition.y = (int) townCenter->world_y;
                newExplorer = this->idleCivilian(-1, tcPosition, 0);
            } else {
                newExplorer = this->idleCivilian(-1);
            }

            if (newExplorer == -1 || this->addGatherer(newExplorer) == 0) {
                break;
            }
        }

        this->nextCivilianToTaskValue = this->civilians[0];
        if (debug_timeGetTime(s_file, 3466) - startTime >= availableTime) {
            return taskedCount;
        }
    }

    j = 0;
    while (j < this->civilians.numberValue && this->nextCivilianToTaskValue != this->civilians[j]) {
        j++;
    }

    if (j >= this->civilians.numberValue) {
        this->nextCivilianToTaskValue = -1;
        return taskedCount;
    }

    while (j < this->civilians.numberValue) {
        taskedCount++;
        if (this->civilianExplorers.contains(this->civilians[j])) {
            this->highLevelTaskExplorer(this->civilians[j], 1);
        } else if (this->highLevelTaskGatherer(this->civilians[j], startTime) == 0) {
            this->addGatherer(this->civilians[j]);
            j++;
            continue;
        }

        this->updateGathererDistribution();
        j++;
        if (j >= this->civilians.numberValue) {
            this->nextCivilianToTaskValue = -1;
            return taskedCount;
        }

        this->nextCivilianToTaskValue = this->civilians[j];
        if (debug_timeGetTime(s_file, 3526) - startTime >= availableTime) {
            if (j > 0) {
                this->civilians[j - 1];
            }
            return taskedCount;
        }
    }

    this->nextCivilianToTaskValue = -1;
    return taskedCount;
}

void TribeTacticalAIModule::taskIdleSoldiers(unsigned long startTime, unsigned long availableTime) {
    TacticalAIGroup* group = this->groups.next;

    if (this->nextIdleSoldierGroupToTaskValue != -1) {
        while ((group != &this->groups && group != 0) && (group->id() != this->nextIdleSoldierGroupToTaskValue)) {
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

        if (group->type() == TACTICAL_GROUP_TYPE_FISHING || group->type() == TACTICAL_GROUP_TYPE_TRADE
            || group->type() == TACTICAL_GROUP_TYPE_TRANSPORT
            || (group->action() != TACTICAL_GROUP_ACTION_NONE && group->action() != TACTICAL_GROUP_ACTION_IDLE)) {
            group = group->next;
            continue;
        }

        readyToTask = 1;
        if (group->consecutiveGatherAttemptsValue <= 10) {
            isGathered = group->isGathered(this, this->md);
        } else {
            isGathered = 1;
        }

        desired = group->desiredNumberUnits();
        number = group->numberUnits();
        if (desired > number) {
            RGE_Static_Object* commanderObj = this->md->object(group->commander());
            RGE_Static_Object* targetObj =
                this->md->object(-1, MASTER_OBJECT_TOWN_CENTER1, -1, -1, -1, -1, -1, -1, RGE_OBJECT_STATE_ANY, -1);
            if (commanderObj == 0 || targetObj == 0) {
                readyToTask = 0;
            } else {
                int zone = commanderObj->currentZone() & 0xff;
                if (zone != commanderObj->lookupZone((int) targetObj->world_x, (int) targetObj->world_y)) {
                    group->setDesiredNumberUnits(group->numberUnits());
                } else {
                    readyToTask = 0;
                }
            }
        } else if (isGathered == 0) {
            readyToTask = 0;
        } else if (group->allUnitsIdle(this->md, 1) == 0) {
            readyToTask = 0;
        } else {
            if (group->type() == TACTICAL_GROUP_TYPE_EXPLORE || group->type() == TACTICAL_GROUP_TYPE_BOAT_EXPLORE) {
                if (this->md->informationAI.fullyExploredZone(group->commander()) == 0) {
                    readyToTask = 0;
                    goto ready_to_task_check;
                }
            }

            if (group->type() == TACTICAL_GROUP_TYPE_ATTACK || group->type() == TACTICAL_GROUP_TYPE_BOAT_ATTACK) {
                if (this->md->strategyAI.currentVictoryCondition() == 0) {
                    if (this->itemToCapture() == -1 && group->type() == TACTICAL_GROUP_TYPE_ATTACK) {
                        readyToTask = 0;
                    } else {
                        group->setSubType(0);
                    }
                }
                if (this->md->strategyAI.currentVictoryCondition() == 4) {
                    if (this->itemToBringToArea() == -1 && group->type() == TACTICAL_GROUP_TYPE_ATTACK) {
                        readyToTask = 0;
                    } else {
                        group->setSubType(4);
                    }
                }
            } else if ((group->type() == TACTICAL_GROUP_TYPE_DEFEND || group->type() == TACTICAL_GROUP_TYPE_BOAT_DEFEND)
                       && this->numberItemsToDefend() == 0) {
                readyToTask = 0;
            }
        }

    ready_to_task_check:
        if (readyToTask == 0) {
            if (isGathered == 0) {
                group->task(this, this->md, TACTICAL_GROUP_ACTION_GATHER, 1, 0);
            }
        } else {
            if (group->type() == TACTICAL_GROUP_TYPE_EXPLORE || group->type() == TACTICAL_GROUP_TYPE_BOAT_EXPLORE) {
                group->setAction(TACTICAL_GROUP_ACTION_EXPLORE);
            } else if (group->type() == TACTICAL_GROUP_TYPE_ATTACK
                       || group->type() == TACTICAL_GROUP_TYPE_BOAT_ATTACK) {
                if (this->numberItemsToAttack() == 0 && group->type() == TACTICAL_GROUP_TYPE_BOAT_ATTACK) {
                    group->setType(TACTICAL_GROUP_TYPE_BOAT_EXPLORE);
                    group->setAction(TACTICAL_GROUP_ACTION_EXPLORE);
                } else {
                    group->setAction(TACTICAL_GROUP_ACTION_ATTACK);
                }
            } else if (group->type() == TACTICAL_GROUP_TYPE_DEFEND
                       || group->type() == TACTICAL_GROUP_TYPE_BOAT_DEFEND) {
                group->setAction(TACTICAL_GROUP_ACTION_DEFEND);
            } else if (group->type() == TACTICAL_GROUP_TYPE_ARTIFACT) {
                group->setAction(TACTICAL_GROUP_ACTION_ARTIFACT);
            }
        }

        goto next_group;

    next_group:
        group = group->next;
        this->nextIdleSoldierGroupToTaskValue = group->id();
        if (debug_timeGetTime(s_file, 3753) - startTime >= availableTime) {
            return;
        }
    }

    this->nextIdleSoldierGroupToTaskValue = -1;
}

void TribeTacticalAIModule::taskActiveSoldiers(ulong startTime, ulong availableTime) {
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
            if (t == TACTICAL_GROUP_TYPE_FISHING || cur->type() == TACTICAL_GROUP_TYPE_TRADE
                || cur->type() == TACTICAL_GROUP_TYPE_TRANSPORT || cur->action() == TACTICAL_GROUP_ACTION_NONE
                || cur->action() == TACTICAL_GROUP_ACTION_IDLE) {
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
                if (t != TACTICAL_GROUP_TYPE_ATTACK && cur->type() != TACTICAL_GROUP_TYPE_BOAT_ATTACK) {
                    t = cur->type();
                    if (t == TACTICAL_GROUP_TYPE_DEFEND || cur->type() == TACTICAL_GROUP_TYPE_BOAT_DEFEND) {
                        int commander;
                        XYZPoint point;
                        float defendDistance;
                        float pathDistance;
                        float gatherX;
                        float gatherY;

                        commander = cur->commander();
                        mem = this->md->informationAI.objectToDefend(commander);
                        if (mem == 0) {
                            cur->setAction(TACTICAL_GROUP_ACTION_IDLE);
                            goto clear_attack_state;
                        } else {
                            commander = cur->commander();
                            commanderObj = this->md->object(commander);
                            if (commanderObj == 0) {
                                cur->setAction(TACTICAL_GROUP_ACTION_IDLE);
                                goto clear_attack_state;
                            } else {
                                if (mem->type == MASTER_OBJECT_TOWN_CENTER1) {
                                    defendDistance = (float) this->sn[SNSentryDistance];
                                } else {
                                    defendDistance = (float) this->sn[SNDefenseDistance];
                                }
                                point.x = mem->x;
                                point.y = mem->y;
                                point.z = mem->z;
                                if (!commanderObj->canPath(
                                        point, commanderObj->weaponRange(), mem->id, &pathDistance, 1, -1, -1
                                    )) {
                                    if (!commanderObj->canPathWithAdditionalPassability(
                                            point, defendDistance, mem->id, &pathDistance, 1, 0x16, 1, -1, -1
                                        )) {
                                        cur->setAction(TACTICAL_GROUP_ACTION_IDLE);
                                        goto clear_attack_state;
                                    }
                                    if (commanderObj->findFirstTerrainAlongExceptionPath(2, &gatherX, &gatherY) == 1) {
                                        mem->attackAttempts = 1;
                                        cur->task(this, this->md, 0x0e, 1, 0);
                                        cur->setAction(0x0d);
                                        cur->setTarget(mem->id);
                                        cur->setTargetType((int) mem->type);
                                        cur->setTargetLocation((float) mem->x, (float) mem->y, (float) mem->z);
                                        cur->setInUse(1);
                                        cur->setWaitCode(200);
                                        goto clear_attack_state;
                                    } else {
                                        cur->setAction(TACTICAL_GROUP_ACTION_IDLE);
                                        goto clear_attack_state;
                                    }
                                } else {
                                    mem->attackAttempts = 1;
                                    cur->setTarget(mem->id);
                                    cur->setTargetType((int) mem->type);
                                    cur->setTargetLocation((float) mem->x, (float) mem->y, (float) mem->z);
                                    directGatherZ = (float) mem->z;
                                    directGatherY = (float) mem->y;
                                    directGatherX = (float) mem->x;
                                    goto inactive_direct_gather;
                                }
                            }
                        }
                    } else {
                        t = cur->type();
                        if (t == TACTICAL_GROUP_TYPE_ARTIFACT) {
                            RGE_Static_Object* relic;
                            TribeMainDecisionAIModule* md;
                            unsigned long idle;
                            unsigned long elapsed;

                            md = this->md;
                            idle = cur->consecutiveIdleUnitCount();
                            elapsed = (md->player->world->world_time - idle) / 1000;
                            if (elapsed < 60) {
                                cur->setAction(TACTICAL_GROUP_ACTION_IDLE);
                                goto clear_attack_state;
                            } else {
                                relic = md->object(
                                    -1, MASTER_OBJECT_TOWN_CENTER1, -1, -1, -1, -1, -1, -1, RGE_OBJECT_STATE_ANY, -1
                                );
                                if (relic == 0) {
                                    cur->setAction(TACTICAL_GROUP_ACTION_IDLE);
                                    goto clear_attack_state;
                                } else {
                                    commanderObj = this->md->object(cur->commander());
                                    if (commanderObj == 0) {
                                        cur->setAction(TACTICAL_GROUP_ACTION_IDLE);
                                        goto clear_attack_state;
                                    } else {
                                        XYZPoint point;
                                        float pathDistance;
                                        float gatherX;
                                        float gatherY;
                                        point.x = (int) relic->world_x;
                                        point.y = (int) relic->world_y;
                                        point.z = (int) relic->world_z;
                                        if (!commanderObj->canPath(
                                                point, (float) this->sn[SNArtifactReturnDistance], relic->id,
                                                &pathDistance, 1, -1, -1
                                            )) {
                                            if (!commanderObj->canPathWithAdditionalPassability(
                                                    point, (float) this->sn[SNArtifactReturnDistance], relic->id,
                                                    &pathDistance, 1, 0x16, 1, -1, -1
                                                )) {
                                                cur->setConsecutiveIdleUnitCount(this->md->player->world->world_time);
                                                cur->setAction(TACTICAL_GROUP_ACTION_IDLE);
                                                goto clear_attack_state;
                                            } else if (commanderObj->findFirstTerrainAlongExceptionPath(
                                                           2, &gatherX, &gatherY
                                                       )
                                                       == 1) {
                                                cur->task(this, this->md, 0x0e, 1, 0);
                                                cur->setAction(0x0d);
                                                cur->setTarget(relic->id);
                                                cur->setTargetType((int) relic->type);
                                                cur->setTargetLocation(relic->world_x, relic->world_y, relic->world_z);
                                                cur->setInUse(1);
                                                cur->setWaitCode(200);
                                            } else {
                                                cur->setAction(TACTICAL_GROUP_ACTION_IDLE);
                                                goto clear_attack_state;
                                            }
                                        } else {
                                            cur->setTarget(relic->id);
                                            cur->setTargetType((int) relic->type);
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
                        }
                    }
                } else {
                    int attackEnabled;
                    int* players;
                    unsigned long lastAttackTime;
                    unsigned long elapsed;

                    attackEnabled = this->attackEnabledValue;
                    if (attackEnabled == 0) {
                        this->attackStateValue.active = 0;
                        goto ContinueLoop;
                    } else {
                        if (this->sn[0xa2] != 0 && cur->type() != TACTICAL_GROUP_TYPE_BOAT_ATTACK) {
                            mem = this->md->informationAI.objectMemory(*(int*) 0);
                            goto attack_target_ready;
                        }
                        lastAttackTime = this->lastGroupAttackTime;
                        elapsed = (this->md->player->world->world_time - lastAttackTime) / 1000;
                        if (lastAttackTime != 0 && this->sn[SNAttackCoordination] == 2 && elapsed != 0
                            && this->attackLimiterTime(SNAttackSeparationTime) > elapsed) {
                            this->attackStateValue.active = 0;
                            goto ContinueLoop;
                        } else if (lastAttackTime != 0 && this->sn[SNAttackCoordination] == 1
                                   && this->attackLimiterTime(SNAttackSeparationTime) > elapsed) {
                            this->attackStateValue.active = 0;
                            goto ContinueLoop;
                        } else {
                            if (this->md->strategyAI.currentVictoryCondition() == 0) {
                                int capture;
                                capture = this->itemToCapture();
                                mem = this->md->informationAI.objectMemory(capture);
                                if (mem == 0) {
                                    players = &this->playersToAttack[0];
                                    goto active_object_to_attack;
                                }
                            } else if (this->md->strategyAI.currentVictoryCondition() == 4) {
                                int bring;
                                bring = this->itemToBringToArea();
                                mem = this->md->informationAI.objectMemory(bring);
                                if (mem == 0) {
                                    players = &this->playersToAttack[0];
                                    goto active_object_to_attack;
                                }
                            } else {
                                players = &this->playersToAttack[0];
                                mem = this->md->informationAI.objectToAttackByGroup(
                                    *players, cur, this->attackStateValue, startTime
                                );
                                if (this->attackStateValue.active == 1) {
                                    this->nextActiveSoldierGroupToTaskValue = cur->id();
                                    return;
                                }
                                goto active_target_selected_common;
                            }
                            goto active_target_selected_common;
                        active_object_to_attack:
                            mem = this->md->informationAI.objectToAttack(
                                *players, 1, 1, cur->commander(), attackAsAttack
                            );
                        active_target_selected_common:
                            if (mem == 0) {
                                cur->setAction(TACTICAL_GROUP_ACTION_IDLE);
                                this->attackStateValue.active = 0;
                                goto ContinueLoop;
                            } else {
                                mem->attackAttempts = mem->attackAttempts + 1;
                            attack_target_ready:
                                commanderObj = this->md->object(cur->commander());
                                if (commanderObj == 0) {
                                    cur->setAction(TACTICAL_GROUP_ACTION_IDLE);
                                    goto clear_attack_state;
                                } else {
                                    float point;
                                    XYZPoint targetPoint;
                                    targetPoint.x = mem->x;
                                    targetPoint.y = mem->y;
                                    targetPoint.z = mem->z;
                                    if (!commanderObj->canPath(
                                            targetPoint, commanderObj->weaponRange(), mem->id, &point, 1, mem->owner,
                                            0x1b
                                        )) {
                                        float gatherX2;
                                        float aux2;
                                        if (cur->type() == TACTICAL_GROUP_TYPE_BOAT_ATTACK) {
                                            goto active_exception_rejected;
                                        }
                                        if (!commanderObj->canPathWithAdditionalPassability(
                                                targetPoint, commanderObj->weaponRange(), mem->id, &point, 1, 0x16, 1,
                                                mem->owner, 0x1b
                                            )) {
                                            cur->numberObjectsToDestroyValue = 0;
                                            cur->setAction(TACTICAL_GROUP_ACTION_IDLE);
                                            cur->playNumberValue = -1;
                                            this->attackStateValue.active = 0;
                                            goto ContinueLoop;
                                        }
                                        if (commanderObj->findFirstTerrainAlongExceptionPath(2, &gatherX2, &aux2)
                                            == 1) {
                                            cur->task(this, this->md, 0x0e, 1, 0);
                                            cur->setAction(0x0d);
                                            cur->setTarget(mem->id);
                                            cur->setTargetType((int) mem->type);
                                            cur->setTargetLocation((float) mem->x, (float) mem->y, (float) mem->z);
                                            cur->setInUse(1);
                                            cur->setWaitCode(200);
                                            cur->playNumberValue = -1;
                                            goto clear_attack_state;
                                        }
                                    active_exception_rejected:
                                        cur->setAction(TACTICAL_GROUP_ACTION_IDLE);
                                        cur->playNumberValue = -1;
                                        goto clear_attack_state;
                                    } else {
                                        this->lastGroupAttackTime = this->md->player->world->world_time;
                                        if (this->sn[SNLockAttackAndAttackResponse] == 1) {
                                            this->lastAttackResponseTime = this->md->player->world->world_time;
                                        }
                                        cur->setTarget(mem->id);
                                        cur->setTargetType((int) mem->type);
                                        cur->setTargetLocation((float) mem->x, (float) mem->y, (float) mem->z);
                                        cur->setInUse(1);
                                        this->checkForCoopAttack(
                                            (unsigned int) mem->owner, (unsigned int) mem->x, (unsigned int) mem->y
                                        );
                                    }
                                }
                            }
                        }
                    }
                }
                goto inactive_post_setup;
            inactive_direct_gather:
                cur->setGatherLocation(directGatherX, directGatherY, directGatherZ);
                cur->setInUse(1);
            inactive_post_setup:
                if (this->md->strategyAI.currentVictoryCondition() == 0x0b
                    && (cur->type() == TACTICAL_GROUP_TYPE_ATTACK || cur->type() == TACTICAL_GROUP_TYPE_BOAT_ATTACK)
                    && this->sn[SNAttackIntelligence] == 1 && mem != 0 && commanderObj != 0) {
                    XYZPoint targetTile;
                    Path* avoidancePath;
                    this->md->informationAI.addEnemyInfluences((int) mem->owner, mem->id);
                    this->md->informationAI.addPriorAttackInfluences((int) mem->owner, mem->id);
                    targetTile.x = (int) mem->x;
                    targetTile.y = (int) mem->y;
                    targetTile.z = 1;
                    avoidancePath = commanderObj->findAvoidancePath(targetTile, commanderObj->weaponRange(), mem->id);
                    if (avoidancePath != 0) {
                        this->stuffAvoidancePath(cur, avoidancePath);
                    }
                }
                if (attackAsAttack != 0 || cur->action() != TACTICAL_GROUP_ACTION_ATTACK) {
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
                                commanderPoint2.x = (int) commanderObj2->world_x;
                                commanderPoint2.y = (int) commanderObj2->world_y;
                                assist = this->bestGroup(
                                    TACTICAL_GROUP_TYPE_TRANSPORT, TACTICAL_GROUP_ACTION_IDLE, -1, commanderPoint2, -1
                                );
                                if (assist == 0) {
                                    assist = this->bestGroup(
                                        TACTICAL_GROUP_TYPE_TRANSPORT, TACTICAL_GROUP_ACTION_NONE, -1, commanderPoint2,
                                        -1
                                    );
                                }
                                if (assist != 0) {
                                    cur->setAssistGroupID(assist->id());
                                    cur->setAssistGroupType(assist->type());
                                    assist->setAction(TACTICAL_GROUP_ACTION_TRANSPORT);
                                    assist->setInUse(1);
                                    assist->setAssistGroupID(cur->id());
                                }
                            }
                        } else {
                            assist = this->group(cur->assistGroupID(), -1, -1, -1);
                        }
                        if (assist != 0) {
                            RGE_Static_Object* transportObj;
                            transportObj = this->md->object(assist->commander());
                            if (transportObj != 0) {
                                RGE_Object_List* transportContents = transportObj->objects;
                                if (transportContents->number_of_objects >= transportObj->master_obj->obj_max) {
                                    cur->setAction(0x0f);
                                    goto clear_attack_state;
                                }
                            }
                            {
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
                                            zp.x = (int) loc->x;
                                            loc = &cur->targetLocation();
                                            zp.y = (int) loc->y;
                                            targetZone = unitObj2->lookupZone(zp);
                                        }
                                        if (unitObj2->inside_obj != 0
                                            && unitObj2->inside_obj->id == assist->commander()) {
                                            if (unitObj2->unitAI()->currentAction() != -1) {
                                                this->stopUnit(unitObj2->id, 100);
                                                i++;
                                                continue;
                                            }
                                        }
                                        if (unitObj2->inside_obj == 0
                                            || unitObj2->inside_obj->id == assist->commander()) {
                                            if (unitObj2->inside_obj == 0) {
                                                needTransporter = 0;
                                                if (unitObj2->unitAI()->currentOrder() != UNIT_AI_ORDER_ATTACK
                                                    && unitObj2->unitAI()->currentOrder() != UNIT_AI_ORDER_ENTER) {
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
                                targetPoint.x = (int) loc->x;
                                loc = &cur->targetLocation();
                                targetPoint.y = (int) loc->y;
                                if (this->md->informationAI.findStagingPoint(
                                        targetPoint, staging, 1, 1, cur->target(), 0x0f, cur->commander()
                                    )
                                    == 0) {
                                    loc = &cur->targetLocation();
                                    staging.x = (int) loc->x;
                                    loc = &cur->targetLocation();
                                    staging.y = (int) loc->y;
                                }
                                this->taskTransporter(
                                    assist->commander(), (float) staging.x + 0.5f, (float) staging.y + 0.5f
                                );
                                assist->setTargetLocation((float) staging.x, (float) staging.y, -1.0f);
                                assist->setAction(TACTICAL_GROUP_ACTION_TRANSPORT);
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
                                                this->taskDefender(
                                                    assist->unit(j), assist->commander(),
                                                    defenderObj->master_obj->los * 0.5f, 99
                                                );
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
                        transportObj = static_cast<RGE_Action_Object*>(this->md->object(assist->commander()));
                        if (transportObj != 0 && transportObj->unitAI() != 0
                            && transportObj->owner->id == this->md->player->id) {
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
                                        RGE_Static_Object* targetObj;
                                        targetObj = this->md->object(cur->target());
                                        if (cur->type() == TACTICAL_GROUP_TYPE_ATTACK && targetObj != 0) {
                                            if (unitObj2->unitAI() != 0
                                                && unitObj2->unitAI()->currentTarget() != cur->target()
                                                && unitObj2->canPath(
                                                       cur->target(), unitObj2->weaponRange(), 0, 1, -1, -1
                                                   ) == 1) {
                                                this->taskAttacker(
                                                    cur->unit(i), cur->targetLocation().x, cur->targetLocation().y,
                                                    cur->target(), -1, 0, 0, -1, 0
                                                );
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
                                if (transportObj->actions->have_action() == 0
                                    || transportObj->actions->get_action()->state == 2) {
                                    const Waypoint* loc;
                                    float transportX;
                                    float transportY;
                                    loc = &assist->targetLocation();
                                    transportY = loc->y + 0.5f;
                                    loc = &assist->targetLocation();
                                    transportX = loc->x + 0.5f;
                                    this->taskTransporter(assist->commander(), transportX, transportY);
                                    assist->setAction(TACTICAL_GROUP_ACTION_TRANSPORT);
                                }
                                goto clear_attack_state;
                            } else if (needReset != 0) {
                                TacticalAIGroup* resetAssist;
                                resetAssist = this->group(cur->assistGroupID(), -1, -1, -1);
                                if (resetAssist != 0) {
                                    resetAssist->setTarget(-1);
                                    resetAssist->setTargetType(-1);
                                    resetAssist->setAction(TACTICAL_GROUP_ACTION_IDLE);
                                    resetAssist->setInUse(0);
                                    RGE_Static_Object* relicObj;
                                    relicObj = this->md->object(
                                        -1, MASTER_OBJECT_TOWN_CENTER1, -1, -1, -1, -1, -1, -1, RGE_OBJECT_STATE_ANY, -1
                                    );
                                    if (relicObj != 0) {
                                        this->moveUnit(
                                            resetAssist->commander(), relicObj->world_x, relicObj->world_y, 50
                                        );
                                    }
                                }
                                if (cur->type() == TACTICAL_GROUP_TYPE_ATTACK) {
                                    RGE_Static_Object* commanderObjT;
                                    commanderObjT = this->md->object(cur->commander());
                                    if (commanderObjT == 0) {
                                        goto action10_attack_failure;
                                    } else {
                                        if (commanderObjT->canPath(
                                                cur->target(), commanderObjT->weaponRange(), 0, 1, -1, -1
                                            )
                                            == 1) {
                                            this->lastGroupAttackTime = this->md->player->world->world_time;
                                            if (this->sn[SNLockAttackAndAttackResponse] == 1) {
                                                this->lastAttackResponseTime = this->md->player->world->world_time;
                                            }
                                            cur->setAction(TACTICAL_GROUP_ACTION_ATTACK);
                                            cur->task(this, this->md, cur->action(), 1, 0);
                                            goto clear_attack_state;
                                        } else {
                                        action10_attack_failure:
                                            cur->setInUse(1);
                                            cur->setAction(TACTICAL_GROUP_ACTION_ESCORTED_EXPLORE);
                                            cur->task(this, this->md, TACTICAL_GROUP_ACTION_ESCORTED_EXPLORE, 0, 1);
                                            goto clear_attack_state;
                                        }
                                    }
                                } else {
                                    if (cur->type() != TACTICAL_GROUP_TYPE_DEFEND
                                        && cur->type() != TACTICAL_GROUP_TYPE_ARTIFACT) {
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
                                    cur->setAction(TACTICAL_GROUP_ACTION_IDLE);
                                    cur->task(this, this->md, TACTICAL_GROUP_ACTION_IDLE, 1, 1);
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
                        cur->setAction(TACTICAL_GROUP_ACTION_IDLE);
                        cur->setInUse(0);
                        this->attackStateValue.active = 0;
                    }
                } else {
                    if (cur->action() == TACTICAL_GROUP_ACTION_TRANSPORT)
                        goto action0c;
                    if (cur->action() == TACTICAL_GROUP_ACTION_ARTIFACT)
                        goto action13;
                    if (cur->action() == TACTICAL_GROUP_ACTION_RETREAT)
                        goto action3;
                    if (cur->action() == TACTICAL_GROUP_ACTION_ESCORTED_EXPLORE) {
                        RGE_Static_Object* commanderObj3;
                        RGE_Static_Object* targetObj;
                        int* players;

                        commanderObj3 = this->md->object(cur->commander());
                        players = &this->playersToAttack[0];
                        mem = this->md->informationAI.objectToAttackByGroup(
                            *players, cur, this->attackStateValue, startTime
                        );
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
                            XYZPoint targetPoint7;
                            targetPoint7.x = mem->x;
                            targetPoint7.y = mem->y;
                            targetPoint7.z = mem->z;
                            if (commanderObj3->canPath(
                                    targetPoint7, commanderObj3->weaponRange(), mem->id, &pathOut, 1, mem->owner, 0x1b
                                )
                                == 1) {
                                cur->setAction(TACTICAL_GROUP_ACTION_ATTACK);
                                cur->setTarget(mem->id);
                                cur->setTargetType((int) mem->type);
                                cur->setTargetLocation((float) mem->x, (float) mem->y, (float) mem->z);
                                cur->setInUse(1);
                                cur->task(this, this->md, TACTICAL_GROUP_ACTION_ATTACK, 0, 1);
                                this->attackStateValue.active = 0;
                                goto ContinueLoop;
                            } else {
                                float gatherY7;
                                float gather7;
                                if (commanderObj3->canPathWithAdditionalPassability(
                                        targetPoint7, commanderObj3->weaponRange(), mem->id, &pathOut, 1, 0x16, 1,
                                        mem->owner, 0x1b
                                    ) == 1
                                    && commanderObj3->findFirstTerrainAlongExceptionPath(2, &gather7, &gatherY7) == 1) {
                                    cur->task(this, this->md, 0x0e, 1, 0);
                                    cur->setAction(0x0d);
                                    cur->setTarget(mem->id);
                                    cur->setTargetType((int) mem->type);
                                    cur->setTargetLocation((float) mem->x, (float) mem->y, (float) mem->z);
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
                    action7_timeout: {
                        unsigned long idle;
                        idle = cur->consecutiveIdleUnitCount();
                        if ((this->md->player->world->world_time - idle) / 1000
                            > ((unsigned int) this->sn[SNTacticalUpdateFrequency] << 2)) {
                            cur->setAction(TACTICAL_GROUP_ACTION_ESCORTED_EXPLORE);
                            cur->task(this, this->md, TACTICAL_GROUP_ACTION_ESCORTED_EXPLORE, 0, 1);
                            goto clear_attack_state;
                        }
                    }
                    action7_done:
                        goto loss_check;
                    } else if (cur->action() == TACTICAL_GROUP_ACTION_ATTACK) {
                        RGE_Static_Object* targetObj2;
                        int targetType;
                        int i;

                        if (cur->playNumberValue == -1) {
                            if (this->sn[SNPercentUnitHealthRetreat] < 100) {
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
                                        curhp = (int) unitObj2->hp;
                                        if (((oldhp - curhp) * 100) / cur->unitOriginalHitPoints(i)
                                            > this->sn[SNPercentUnitHealthRetreat]) {
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
                            if (targetObj2 == 0 || targetObj2->object_state > RGE_OBJECT_STATE_ACTIVE) {
                                ObjectMemory* replacement;
                                RGE_Static_Object* replacementCommander;
                                int* players2;
                                if (this->sn[SNRetreatAfterTargetDestroyed] == 2) {
                                    cur->setAction(TACTICAL_GROUP_ACTION_IDLE);
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
                                    players2 = &this->playersToAttack[0];
                                    replacement = this->md->informationAI.objectToAttackByGroup(
                                        *players2, cur, this->attackStateValue, startTime
                                    );
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
                                        if (replacementCommander->canPath(
                                                replacementPoint, replacementCommander->weaponRange(), replacement->id,
                                                &path2, 1, replacement->owner, 0x1b
                                            )
                                            == 1) {
                                            cur->setTarget(replacement->id);
                                            cur->setTargetType((int) replacement->type);
                                            cur->setTargetLocation(
                                                (float) replacement->x, (float) replacement->y, (float) replacement->z
                                            );
                                            cur->setInUse(1);
                                            cur->task(this, this->md, TACTICAL_GROUP_ACTION_ATTACK, 0, 0);
                                            this->attackStateValue.active = 0;
                                            goto ContinueLoop;
                                        }
                                    }
                                    targetType = cur->targetType();
                                    cur->setInUse(0);
                                    cur->setAction(TACTICAL_GROUP_ACTION_IDLE);
                                    cur->setTarget(-1);
                                    cur->numberObjectsToDestroyValue = 0;
                                    cur->setTargetType(-1);
                                    cur->setTargetLocation(-1.0f, -1.0f, -1.0f);
                                    if (this->sn[SNRetreatAfterTargetDestroyed] == 0) {
                                        cur->setGatherLocation(
                                            replacementCommander->world_x, replacementCommander->world_y,
                                            replacementCommander->world_z
                                        );
                                    } else if (this->sn[SNRetreatAfterTargetDestroyed] == 3 && targetType != 0x7e
                                               && targetType != 0x59) {
                                        if (this->sn[SNBlotExplorationMap] == 1) {
                                            int cx;
                                            int cy;
                                            int radius;
                                            cy = (int) replacementCommander->world_y;
                                            radius = this->sn[0x88];
                                            cx = (int) replacementCommander->world_x;
                                            this->md->informationAI.blotExploredMap(
                                                cx - radius, cy - radius, cx + radius, cy + radius
                                            );
                                        }
                                        cur->setInUse(1);
                                        cur->setAction(TACTICAL_GROUP_ACTION_ESCORTED_EXPLORE);
                                        cur->task(this, this->md, TACTICAL_GROUP_ACTION_ESCORTED_EXPLORE, 0, 1);
                                        this->attackStateValue.active = 0;
                                        goto ContinueLoop;
                                    }
                                    goto clear_attack_state;
                                }
                            } else if (cur->subType() != -1) {
                                unsigned long idle;
                                if (cur->subType() != 0 && cur->subType() == 4
                                    && targetObj2->owner->id == this->md->player->id
                                    && this->md->isMoveable(targetObj2->id)) {
                                    Waypoint p1;
                                    Waypoint p2;
                                    cur->addUnit(targetObj2->id, this->md);
                                    p1 = this->md->strategyAI.targetPoint1();
                                    p2 = this->md->strategyAI.targetPoint2();
                                    cur->setInUse(0);
                                    cur->setAction(TACTICAL_GROUP_ACTION_IDLE);
                                    cur->setTarget(-1);
                                    cur->numberObjectsToDestroyValue = 0;
                                    cur->setTargetType(-1);
                                    cur->setTargetLocation(-1.0f, -1.0f, -1.0f);
                                    cur->setGatherLocation(
                                        (p1.x + p2.x) * 0.5f, (p1.y + p2.y) * 0.5f, (p1.z + p2.z) * 0.5f
                                    );
                                }
                                idle = cur->consecutiveIdleUnitCount();
                                if ((this->md->player->world->world_time - idle) / 1000
                                    > (unsigned int) this->sn[SNConsecutiveIdleUnitLimit]) {
                                    cur->setInUse(0);
                                    cur->setAction(TACTICAL_GROUP_ACTION_IDLE);
                                    cur->setTarget(-1);
                                    cur->setTargetType(-1);
                                    cur->setTargetLocation(-1.0f, -1.0f, -1.0f);
                                    cur->numberObjectsToDestroyValue = 0;
                                    this->attackStateValue.active = 0;
                                    goto ContinueLoop;
                                }
                            } else {
                                if (this->md->player->isAlly(targetObj2->owner->id) != 0) {
                                    RGE_Static_Object* commanderObj8;
                                    cur->setInUse(0);
                                    cur->setAction(TACTICAL_GROUP_ACTION_IDLE);
                                    cur->setTarget(-1);
                                    cur->setTargetType(-1);
                                    cur->setTargetLocation(-1.0f, -1.0f, -1.0f);
                                    cur->numberObjectsToDestroyValue = 0;
                                    commanderObj8 = this->md->object(cur->commander());
                                    if (commanderObj8 != 0) {
                                        cur->setGatherLocation(
                                            commanderObj8->world_x, commanderObj8->world_y, commanderObj8->world_z
                                        );
                                    }
                                    goto clear_attack_state;
                                } else {
                                    if (cur->allUnitsIdle(this->md, 0) != 1) {
                                        cur->task(this, this->md, TACTICAL_GROUP_ACTION_ATTACK_ROUNDUP, 0, 1);
                                        this->attackStateValue.active = 0;
                                        goto ContinueLoop;
                                    } else {
                                        RGE_Static_Object* commanderObj4;
                                        commanderObj4 = this->md->object(cur->commander());
                                        if (commanderObj4 == 0) {
                                            this->attackStateValue.active = 0;
                                            goto ContinueLoop;
                                        } else {
                                            if (commanderObj4->canPath(
                                                    cur->target(), commanderObj4->weaponRange(), 0, 1, -1, -1
                                                )
                                                == 1) {
                                                cur->task(this, this->md, TACTICAL_GROUP_ACTION_ATTACK_ROUNDUP, 0, 1);
                                                this->attackStateValue.active = 0;
                                                goto ContinueLoop;
                                            }
                                            cur->setGatherLocation(
                                                commanderObj4->world_x, commanderObj4->world_y, commanderObj4->world_z
                                            );
                                            cur->setInUse(0);
                                            cur->setAction(TACTICAL_GROUP_ACTION_IDLE);
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
                        if (cur->action() == TACTICAL_GROUP_ACTION_ATTACK && cur->playNumberValue != -1) {
                            RGE_Static_Object* commanderObj9;
                            commanderObj9 = this->md->object(cur->commander());
                            if (commanderObj9 != 0 && commanderObj9->unitAI() != 0
                                && commanderObj9->unitAI()->playStatus == 0) {
                                cur->playNumberValue = -1;
                                this->attackStateValue.active = 0;
                            }
                            goto clear_attack_state;
                        }
                        goto loss_check;
                    } else if (cur->action() == TACTICAL_GROUP_ACTION_DEFEND) {
                        if (cur->allUnitsIdle(this->md, 1) != 1 || cur->isGathered(this, this->md) != 0) {
                            RGE_Static_Object* targetObj4;
                            targetObj4 = this->md->object(cur->target());
                            if (targetObj4 != 0) {
                                ObjectMemory* higher;
                                higher = this->md->informationAI.higherPriorityObjectToDefend(
                                    cur->commander(), cur->targetType(), (int) targetObj4->master_obj->object_group
                                );
                                if (higher == 0) {
                                    goto loss_check;
                                }
                                ObjectMemory* oldTarget;
                                oldTarget = this->md->informationAI.objectMemory(cur->target());
                                if (oldTarget != 0) {
                                    oldTarget->attackAttempts = 0;
                                }
                                cur->setAction(TACTICAL_GROUP_ACTION_IDLE);
                                cur->setInUse(0);
                                goto clear_attack_state;
                            } else {
                                cur->setAction(TACTICAL_GROUP_ACTION_IDLE);
                                cur->setInUse(0);
                                goto clear_attack_state;
                            }
                        } else {
                            cur->task(this, this->md, TACTICAL_GROUP_ACTION_GATHER, 1, 0);
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
                action13: {
                    if (cur->isGathered(this, this->md) == 0) {
                        int allIdle;
                        unsigned long idle;
                        unsigned long elapsed;
                        idle = cur->consecutiveIdleUnitCount();
                        elapsed = (this->md->player->world->world_time - idle) / 1000;
                        allIdle = cur->allUnitsIdle(this->md, 1);
                        if (allIdle == 1 && 5 < elapsed) {
                            cur->setConsecutiveIdleUnitCount(this->md->player->world->world_time);
                            cur->task(this, this->md, TACTICAL_GROUP_ACTION_GATHER, 1, 0);
                            this->attackStateValue.active = 0;
                            goto ContinueLoop;
                        }
                    }
                }
                    goto clear_attack_state;
                action3: {
                    unsigned long idle;
                    idle = cur->consecutiveIdleUnitCount();
                    if ((this->md->player->world->world_time - idle) / 1000
                        > (unsigned int) this->sn[SNConsecutiveIdleUnitLimit]) {
                        cur->setInUse(0);
                        cur->setAction(TACTICAL_GROUP_ACTION_IDLE);
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
                        cur->setAction(TACTICAL_GROUP_ACTION_IDLE);
                        cur->setInUse(0);
                        if (cur->type() == TACTICAL_GROUP_TYPE_DEFEND
                            || cur->type() == TACTICAL_GROUP_TYPE_BOAT_DEFEND) {
                            ObjectMemory* oldTarget;
                            oldTarget = this->md->informationAI.objectMemory(cur->target());
                            if (oldTarget != 0) {
                                oldTarget->attackAttempts = 0;
                            }
                        }
                        if (this->md->buildAI.buildListLength() == 0
                            && ((cur->type() == TACTICAL_GROUP_TYPE_ATTACK
                                 && this->numberGroups(TACTICAL_GROUP_TYPE_ATTACK, -1) > 1)
                                || cur->type() != TACTICAL_GROUP_TYPE_ATTACK)) {
                            if (cur->type() == TACTICAL_GROUP_TYPE_EXPLORE) {
                                this->sn[SNNumberExploreGroups] = this->sn[SNNumberExploreGroups] - 1;
                            } else if (cur->type() == TACTICAL_GROUP_TYPE_DEFEND) {
                                this->sn[SNNumberDefendGroups] = this->sn[SNNumberDefendGroups] - 1;
                            } else if (cur->type() == TACTICAL_GROUP_TYPE_ATTACK) {
                                this->sn[SNNumberAttackGroups] = this->sn[SNNumberAttackGroups] - 1;
                            }
                            cur->removeUnits(this->md);
                            cur->setAction(TACTICAL_GROUP_ACTION_NONE);
                            this->attackStateValue.active = 0;
                        } else {
                            this->attackStateValue.active = 0;
                        }
                        goto ContinueLoop;
                    }
                }
                    goto active_dispatch_done;
                loss_check: {
                    if (cur->action() != TACTICAL_GROUP_ACTION_RETREAT && cur->action() != 0x0d) {
                        int hpLoss;
                        int currentHitPoints;
                        int originalHitPoints;
                        int currentUnits;
                        int originalUnits;
                        int unitLoss;

                        currentHitPoints = cur->currentHitPoints(this->md);
                        originalHitPoints = cur->originalHitPoints();
                        hpLoss = ((originalHitPoints - currentHitPoints) * 100) / cur->originalHitPoints();
                        currentUnits = cur->numberUnits();
                        originalUnits = cur->originalUnitNumber();
                        unitLoss = ((originalUnits - currentUnits) * 100) / cur->originalUnitNumber();
                        if (hpLoss > this->sn[SNPercentHealthRetreat] || unitLoss > this->sn[SNPercentDeathRetreat]) {
                            cur->setAction(TACTICAL_GROUP_ACTION_RETREAT);
                            cur->task(this, this->md, cur->action(), 1, 0);
                            goto clear_attack_state;
                        }
                    }
                }
                active_dispatch_done:;
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
            if (debug_timeGetTime(s_file, 5374) - startTime >= availableTime) {
                return;
            }
        } while (cur != &this->groups);
    }
    this->nextActiveSoldierGroupToTaskValue = -1;
}

void TribeTacticalAIModule::playTaskSoldiers(unsigned long startTime, unsigned long availableTime) {
    int countUnplayedSoldiers;
    ObjectMemory* target;
    int numberPlayUnits;
    int playCommander;
    int playToRun;
    int unplayedSoldiers[50];
    int playUnits[50];
    int i;

    if (this->sn[0xa2] != 0) {
        countUnplayedSoldiers = 0;
        for (i = 0; i < this->soldiers.number(); i++) {
            TacticalAIGroup* group = this->groupUnitIsIn(this->soldiers[i]);
            if ((group == 0) || (group->type() != TACTICAL_GROUP_TYPE_ATTACK)) {
                unplayedSoldiers[countUnplayedSoldiers++] = this->soldiers[i];
            }
        }

        if (countUnplayedSoldiers != 0) {
            playToRun = -1;
            numberPlayUnits = 0;
            playCommander = -1;
            target = this->md->informationAI.objectToAttackWithPlay(
                this->playersToAttack[0], unplayedSoldiers, countUnplayedSoldiers, playToRun, playUnits,
                numberPlayUnits, playCommander
            );
            if (target != 0) {
                RGE_Static_Object* playObj = this->md->object(playCommander);
                if (playObj != 0) {
                    TacticalAIGroup* group = this->createGroup(1);
                    if (group != 0) {
                        group->setType(TACTICAL_GROUP_TYPE_ATTACK);
                        group->setDesiredNumberUnits(numberPlayUnits);
                        for (i = 0; i < numberPlayUnits; i++) {
                            group->addUnit(playUnits[i], this->md);
                        }
                        group->setSpecificCommander(playCommander, this->md);
                        group->setLocation(playObj->world_x, playObj->world_y, playObj->world_z);
                        group->setGatherLocation(playObj->world_x, playObj->world_y, playObj->world_z);
                        group->setRetreatLocation(playObj->world_x, playObj->world_y, playObj->world_z);
                        group->setTarget(target->id);
                        group->playNumberValue = playToRun;
                        group->setAction(TACTICAL_GROUP_ACTION_ATTACK);
                        group->setInUse(1);
                        group->task(this, this->md, TACTICAL_GROUP_ACTION_ATTACK, 1, 1);
                    }
                }
            }
        }
    }
}

void TribeTacticalAIModule::taskUngroupedSoldiers() {
    RGE_Static_Object* centerObject;
    RGE_Static_Object* soldierObject;
    TacticalAIGroup* group;
    XYPoint centerPoint;
    XYPoint gatherPoint;
    int i;

    if ((this->md->player->world->world_time - this->lastUngroupedSoldierTaskTime) / 1000 < 60)
        return;

    this->lastUngroupedSoldierTaskTime = this->md->player->world->world_time;
    centerObject = this->md->object(-1, MASTER_OBJECT_TOWN_CENTER1, -1, -1, -1, -1, -1, -1, RGE_OBJECT_STATE_ANY, -1);
    if (centerObject == 0)
        return;

    centerPoint.x = (int) centerObject->world_x;
    centerPoint.y = (int) centerObject->world_y;

    i = 0;
    if (this->soldiers.numberValue > 0) {
        do {
            group = this->groupUnitIsIn(this->soldiers[i]);
            if (group != 0) {
                this->ungroupedSoldiers.remove(this->soldiers[i]);
            } else {
                soldierObject = this->md->object(this->soldiers[i]);
                if (soldierObject != 0) {
                    if (this->ungroupedSoldiers.contains(this->soldiers[i]) == 0) {
                        this->ungroupedSoldiers.add(this->soldiers[i]);
                        if (this->md->informationAI.findGatherPosition(
                                centerPoint, 1, 1, this->sn[SNSentryDistance], this->sn[SNSentryDistanceVariation],
                                soldierObject, gatherPoint
                            )
                            == 1) {
                            this->moveUnit(this->soldiers[i], (float) gatherPoint.x, (float) gatherPoint.y, 50);
                        }
                    }
                }
            }
            i++;
        } while (i < this->soldiers.numberValue);
    }
}

void TribeTacticalAIModule::taskBoats() {
    TacticalAIGroup* group;
    int gathered;
    int ready;

    group = this->groups.next;
    if (group != &this->groups) {
        do {
            if (group == 0)
                break;

            if (group->type() != TACTICAL_GROUP_TYPE_ATTACK && group->type() != TACTICAL_GROUP_TYPE_DEFEND
                && group->type() != TACTICAL_GROUP_TYPE_EXPLORE && group->type() != TACTICAL_GROUP_TYPE_BOAT_ATTACK
                && group->type() != TACTICAL_GROUP_TYPE_BOAT_DEFEND && group->type() != TACTICAL_GROUP_TYPE_BOAT_EXPLORE
                && (group->action() == TACTICAL_GROUP_ACTION_NONE || group->action() == TACTICAL_GROUP_ACTION_IDLE)) {
                int numberUnits;
                int desiredNumberUnits;

                gathered = group->isGathered(this, this->md);
                ready = 1;
                numberUnits = group->numberUnits();
                desiredNumberUnits = group->desiredNumberUnits();
                if (numberUnits < desiredNumberUnits
                    || ((gathered == 0 && group->numberUnits() > 1) || group->allUnitsIdle(this->md, 1) == 0)) {
                    ready = 0;
                }

                if (ready == 0) {
                    if (gathered == 0)
                        group->task(this, this->md, TACTICAL_GROUP_ACTION_GATHER, 1, 0);
                } else if (group->type() == TACTICAL_GROUP_TYPE_FISHING) {
                    group->setAction(TACTICAL_GROUP_ACTION_FISH);
                } else if (group->type() == TACTICAL_GROUP_TYPE_TRADE) {
                    group->setAction(TACTICAL_GROUP_ACTION_TRADE);
                } else if (group->type() == TACTICAL_GROUP_TYPE_TRANSPORT) {
                    group->setAction(TACTICAL_GROUP_ACTION_IDLE);
                }
            }

            group = group->next;
        } while (group != &this->groups);
    }

    group = this->groups.next;
    if (group != &this->groups) {
        do {
            if (group == 0)
                return;

            if (group->type() == TACTICAL_GROUP_TYPE_ATTACK || group->type() == TACTICAL_GROUP_TYPE_DEFEND
                || group->type() == TACTICAL_GROUP_TYPE_EXPLORE || group->type() == TACTICAL_GROUP_TYPE_BOAT_ATTACK
                || group->type() == TACTICAL_GROUP_TYPE_BOAT_DEFEND || group->type() == TACTICAL_GROUP_TYPE_BOAT_EXPLORE
                || group->action() == TACTICAL_GROUP_ACTION_NONE || group->action() == TACTICAL_GROUP_ACTION_IDLE)
                goto next_group;

            if (group->inUse() == 0) {
                if (group->type() == TACTICAL_GROUP_TYPE_FISHING) {
                    RGE_Static_Object* commanderObject;
                    RGE_Static_Object* targetObject;
                    int resourceID;
                    int dropsiteID;
                    int numExclusions;

                    commanderObject = this->md->object(group->commander());
                    if (commanderObject == 0) {
                        group->setAction(TACTICAL_GROUP_ACTION_IDLE);
                        goto next_group;
                    }

                    resourceID = -1;
                    numExclusions = 0;
                    dropsiteID = -1;
                    if (this->numberWaterExplorers() > 0
                        && this->md->informationAI.fullyExploredZone(group->commander()) == 1) {
                        int exclusions[5];
                        int* nextExclusion;
                        int attempts;
                        int canPath;
                        float rXPos;
                        float rYPos;
                        XYZPoint point;

                        nextExclusion = exclusions;
                        attempts = 0;
                        do {
                            rXPos = 0.0f;
                            rYPos = 0.0f;
                            resourceID = this->md->informationAI.gameIDOfResourceObject(
                                0, commanderObject->id, rXPos, rYPos, dropsiteID, exclusions, numExclusions
                            );

                            point.x = (int) rXPos;
                            point.y = (int) rYPos;
                            point.z = (int) commanderObject->world_z;

                            if (dropsiteID == -1) {
                                canPath = commanderObject->canPath(point, 1.0f, resourceID, 0, 1, -1, -1);
                            } else {
                                canPath =
                                    commanderObject->canBidirectionPath(resourceID, dropsiteID, 1.0f, 0, 1, -1, -1);
                            }

                            if (canPath == 0) {
                                numExclusions++;
                                *nextExclusion++ = resourceID;
                            }
                            if (canPath == 1)
                                break;
                            attempts++;
                        } while (attempts < 5);
                    }

                    targetObject = this->md->object(resourceID);
                    if (resourceID >= 0 && targetObject != 0) {
                        group->setTarget(resourceID);
                        group->setTargetType((int) targetObject->master_obj->id);
                        group->setTargetLocation(targetObject->world_x, targetObject->world_y, targetObject->world_z);
                        group->setInUse(1);
                        group->task(this, this->md, group->action(), 1, 0);
                    } else if (this->md->informationAI.fullyExploredZone(group->commander()) == 1) {
                        group->setAction(TACTICAL_GROUP_ACTION_EXPLORE);
                        group->task(this, this->md, group->action(), 1, 0);
                        group->setInUse(1);
                    } else {
                        group->setAction(TACTICAL_GROUP_ACTION_IDLE);
                    }
                    goto next_group;
                }

                if (group->type() == TACTICAL_GROUP_TYPE_TRADE) {
                    RGE_Static_Object* commanderObject;
                    ObjectMemory* tradeObject;

                    commanderObject = this->md->object(group->commander());
                    if (commanderObject == 0) {
                        group->setAction(TACTICAL_GROUP_ACTION_IDLE);
                        goto next_group;
                    }

                    tradeObject = this->md->informationAI.objectToTradeWith(group->commander());
                    if (tradeObject == 0) {
                        if (this->md->informationAI.fullyExploredZone(group->commander()) != 1) {
                            group->setAction(TACTICAL_GROUP_ACTION_IDLE);
                            goto next_group;
                        }
                        group->setAction(TACTICAL_GROUP_ACTION_EXPLORE);
                        group->task(this, this->md, group->action(), 1, 0);
                        group->setInUse(1);
                    } else {
                        XYZPoint point;
                        float pathDistance;

                        point.x = tradeObject->x;
                        point.y = tradeObject->y;
                        point.z = tradeObject->z;
                        if (commanderObject->canPath(point, 1.0f, tradeObject->id, &pathDistance, 1, -1, -1) == 0) {
                            group->setAction(TACTICAL_GROUP_ACTION_IDLE);
                            goto next_group;
                        }
                        group->setTarget(tradeObject->id);
                        group->setTargetType((int) tradeObject->type);
                        group->setTargetLocation(
                            (float) tradeObject->x, (float) tradeObject->y, (float) tradeObject->z
                        );
                        group->setInUse(1);
                        group->task(this, this->md, group->action(), 1, 0);
                    }
                    goto next_group;
                }

                group->task(this, this->md, group->action(), 1, 0);
                goto next_group;
            }

            if (group->action() == TACTICAL_GROUP_ACTION_EXPLORE) {
                int hasWork;

                hasWork = 0;
                if (group->type() == TACTICAL_GROUP_TYPE_TRADE
                    && this->md->informationAI.objectToTradeWith(group->commander()) != 0) {
                    hasWork = 1;
                }

                if (group->type() == TACTICAL_GROUP_TYPE_FISHING) {
                    if (this->numberWaterExplorers() > 1) {
                        float rXPos;
                        float rYPos;
                        int dropsiteID;

                        rXPos = 0.0f;
                        rYPos = 0.0f;
                        dropsiteID = -1;
                        if (this->md->informationAI.gameIDOfResourceObject(
                                0, group->commander(), rXPos, rYPos, dropsiteID, 0, 0
                            )
                            != -1) {
                            hasWork = 1;
                        }
                    } else {
                        RGE_Static_Object* commanderObject;

                        commanderObject = this->md->object(group->commander());
                        if (commanderObject != 0 && commanderObject->unitAI() != 0
                            && commanderObject->unitAI()->currentOrder() != UNIT_AI_ORDER_EXPLORE) {
                            group->setAction(TACTICAL_GROUP_ACTION_EXPLORE);
                            group->task(this, this->md, group->action(), 1, 0);
                            group->setInUse(1);
                        }
                    }
                }

                if (hasWork == 1) {
                    RGE_Static_Object* commanderObject;

                    commanderObject = this->md->object(group->commander());
                    if (commanderObject == 0)
                        goto next_group;

                    group->setInUse(0);
                    group->setAction(TACTICAL_GROUP_ACTION_IDLE);
                    group->setTarget(-1);
                    group->numberObjectsToDestroyValue = 0;
                    group->setTargetType(-1);
                    group->setTargetLocation(-1.0f, -1.0f, -1.0f);
                    group->setGatherLocation(
                        commanderObject->world_x, commanderObject->world_y, commanderObject->world_z
                    );
                    group->task(this, this->md, group->action(), 1, 0);
                    goto next_group;
                }
            }

            if (group->action() == TACTICAL_GROUP_ACTION_FISH) {
                RGE_Static_Object* targetObject;

                targetObject = this->md->object(group->target());
                if (targetObject == 0) {
                    group->setInUse(0);
                    group->setAction(TACTICAL_GROUP_ACTION_IDLE);
                    group->setTarget(-1);
                    group->setTargetType(-1);
                    group->setTargetLocation(-1.0f, -1.0f, -1.0f);
                    group->numberObjectsToDestroyValue = 0;
                    goto next_group;
                }

                RGE_Static_Object* commanderObject = this->md->object(group->commander());
                if (commanderObject != 0 && commanderObject->unitAI() != 0
                    && commanderObject->unitAI()->currentAction() == -1) {
                    group->setInUse(0);
                    group->setAction(TACTICAL_GROUP_ACTION_IDLE);
                    group->setTarget(-1);
                    group->numberObjectsToDestroyValue = 0;
                    group->setTargetType(-1);
                    group->setTargetLocation(-1.0f, -1.0f, -1.0f);
                    group = group->next;
                }
            }

            if (group->action() == TACTICAL_GROUP_ACTION_TRADE) {
                RGE_Static_Object* targetObject;

                targetObject = this->md->object(group->target());
                if (targetObject == 0) {
                    group->setInUse(0);
                    group->setAction(TACTICAL_GROUP_ACTION_IDLE);
                    group->setTarget(-1);
                    group->numberObjectsToDestroyValue = 0;
                    group->setTargetType(-1);
                    group->setTargetLocation(-1.0f, -1.0f, -1.0f);
                    goto next_group;
                }

                RGE_Static_Object* commanderObject = this->md->object(group->commander());
                if (commanderObject != 0 && commanderObject->unitAI() != 0) {
                    if (commanderObject->unitAI()->currentAction() == -1) {
                        group->setInUse(0);
                        group->setAction(TACTICAL_GROUP_ACTION_IDLE);
                        group->setTarget(-1);
                        group->numberObjectsToDestroyValue = 0;
                        group->setTargetType(-1);
                        group->setTargetLocation(-1.0f, -1.0f, -1.0f);
                        group = group->next;
                        goto next_group;
                    }

                    RGE_Action_Object* actionObject = (RGE_Action_Object*) commanderObject;
                    if (actionObject->have_action() != 0) {
                        RGE_Action* action = actionObject->actions->get_action();
                        ObjectMemory* tradeObject = this->md->informationAI.objectToTradeWith(action->target2ID);
                        if (tradeObject != 0 && tradeObject->id != group->target()) {
                            XYZPoint point;
                            float pathDistance;

                            point.x = tradeObject->x;
                            point.y = tradeObject->y;
                            point.z = tradeObject->z;
                            if (commanderObject->canPath(point, 1.0f, tradeObject->id, &pathDistance, 1, -1, -1) == 0) {
                                group->setAction(TACTICAL_GROUP_ACTION_IDLE);
                                goto next_group;
                            }
                            group->setTarget(tradeObject->id);
                            group->setTargetType((int) tradeObject->type);
                            group->setTargetLocation(
                                (float) tradeObject->x, (float) tradeObject->y, (float) tradeObject->z
                            );
                            group->setInUse(1);
                            group->task(this, this->md, group->action(), 1, 1);
                        }
                    }
                }
            }

        next_group:
            group = group->next;
        } while (group != &this->groups);
    }
}

void TribeTacticalAIModule::evaluateOpenTasks() {
    int i;

    i = 0;
    if (this->civilians.numberValue > 0) {
        do {
            RGE_Static_Object* object = this->md->player->world->object(this->civilians[i]);
            if (object != 0) {
                UnitAIModule* unitAI = object->unitAI();
                if (unitAI != 0) {
                    int j = 0;
                    while (j < this->unitsTaskedThisUpdate.numberValue) {
                        if (j >= this->unitsTaskedThisUpdate.maximumSizeValue)
                            break;
                        int taskedID = this->unitsTaskedThisUpdate.value[j];
                        int candidateID = this->civilians[i];
                        if (taskedID == candidateID)
                            goto next_civilian;
                        j++;
                    }

                    if (object->getSpeed() == 0.0 && object->attribute_amount_held > 0.0f
                        && object->waitingToMove() == 0 && object->actionState() <= 2) {
                        RGE_Static_Object* dropsite = this->md->informationAI.findClosestReturnDropsite(object);
                        if (dropsite != 0) {
                            this->md->player->sendGameOrder(object, dropsite, dropsite->world_x, dropsite->world_y);
                            this->unitsTaskedThisUpdate.add(this->civilians[i]);
                        } else {
                            this->stopUnit(this->civilians[i], 100);
                        }
                    } else {
                        if (object->unitAI()->currentOrder() == UNIT_AI_ORDER_ATTACK) {
                            int target = object->unitAI()->currentTarget();
                            RGE_Static_Object* targetObject = this->md->object(target);
                            if (targetObject == 0 || targetObject->object_state > RGE_OBJECT_STATE_ACTIVE) {
                                this->stopUnit(this->civilians[i], 100);
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
            RGE_Static_Object* object = this->md->player->world->object(this->civilians[i]);
            if (object == 0 || object->hp < 1.0f || object->unitAI() == 0) {
                this->removeObject(this->civilians[i]);
            }
            i++;
        } while (i < this->civilians.numberValue);
    }

    i = 0;
    if (this->soldiers.numberValue > 0) {
        do {
            RGE_Static_Object* object = this->md->player->world->object(this->soldiers[i]);
            if (object == 0 || object->hp < 1.0f || object->unitAI() == 0) {
                this->removeObject(this->soldiers[i]);
            }
            i++;
        } while (i < this->soldiers.numberValue);
    }

    i = 0;
    if (this->boats.numberValue > 0) {
        do {
            RGE_Static_Object* object = this->md->player->world->object(this->boats[i]);
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

        if (group->type() == TACTICAL_GROUP_TYPE_TRANSPORT && group->action() == TACTICAL_GROUP_ACTION_TRANSPORT) {
            TacticalAIGroup* assistGroup = this->group(group->assistGroupID(), minusOne, minusOne, minusOne);
            int currentAssistGroupID = group->assistGroupID();

            if (currentAssistGroupID == -1 || assistGroup == 0) {
                group->setAction(TACTICAL_GROUP_ACTION_IDLE);
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
                if (object != 0 && object->actionState() == 2 && assistGroup->action() == 0x10) {
                    int assistCommander = assistGroup->commander();
                    RGE_Static_Object* assistObject = this->md->object(assistCommander);
                    if (assistObject != 0 && assistObject->objects->number_of_objects > 0) {
                        assistGroup->setAction(0xF);
                    }
                }
            }
        }

        group = group->next;
    }
}

void TribeTacticalAIModule::evaluateBuildListInsertions() {
    int one = 1;

    if (this->sn[0xCD] == one) {
        if (this->md->buildAI.haveBuildList() != 0 && this->builtFirstStoragePit == 0
            && this->md->informationAI.numberFoundForestTilesValue >= this->sn[0xA9]) {
            this->md->buildAI.insert(MASTER_OBJECT_STORAGE_PIT1, one, 0);
            this->builtFirstStoragePit = one;
        }

        if (this->sn[0xCD] == one) {
            if (this->md->buildAI.haveBuildList() != 0 && this->builtFirstGranary == 0) {
                if (this->builtFirstStoragePit != one && this->md->resourceAI.resource(one) < 250) {
                    goto check_granary;
                }

                if (this->md->informationAI.closestDropsiteValue[0] != -1) {
                    this->md->buildAI.insert(MASTER_OBJECT_GRANARY, one, one);
                    this->builtFirstGranary = one;
                    goto after_granary;
                }
            }
        }
    }

check_granary:
    if (this->builtFirstGranary == one)
        this->checkForBuildInsertion(MASTER_OBJECT_GRANARY, one, 0);

after_granary:
    int insertID = this->sn[SNSpecificBuildItemToBuild];
    if (insertID != -1 && this->sn[SNSpecificBuildItemTime] <= this->md->player->world->world_time / 60000) {
        this->md->buildAI.insert(insertID, one, 0);
        this->sn[SNSpecificBuildItemToBuild] = -1;
    }

    this->checkForBuildInsertion(MASTER_OBJECT_FARM, one, 0);
    this->checkForBuildInsertion(MASTER_OBJECT_WATCH_TOWER, one, 0);
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

// The body calls TribeTacticalAIModule::numberUnitsInGroups(TACTICAL_GROUP_TYPE_EXPLORE).

int TribeTacticalAIModule::numberSoldierExplorers() {
    return this->numberUnitsInGroups(TACTICAL_GROUP_TYPE_EXPLORE);
}

int TribeTacticalAIModule::numberBoats() const {
    return this->boats.numberValue;
}

int TribeTacticalAIModule::neededResource(int n) const {
    if (n < 0 || n >= 4)
        return -1;
    return this->neededResourceValue[n];
}

int TribeTacticalAIModule::neededResourceAmount(int n) const {
    if (n >= 0 && n < 4)
        return this->neededResources.value(this->neededResourceValue[n]);
    return -1;
}

void TribeTacticalAIModule::detask(int uid) {
    if (uid == -1) {
        this->logCommonHistory((char*) "ERROR DETASKING Unit #%d!", uid);
        return;
    }
    removeFromTaskLists(uid);
    stopUnit(uid, 0x64);
}

int TribeTacticalAIModule::strategicNumber(int sNum) {
    if (sNum < 0 || sNum >= 226)
        return -1;
    return sn[sNum];
}

void TribeTacticalAIModule::setStrategicNumber(int sNum, int v) {
    if (sNum >= 0 && sNum < 0xE2) {
        this->sn[sNum] = v;
        if (sNum == 0x75 || sNum == 0x78 || sNum == 0x77 || sNum == 0x76 || sNum == 0x9C || sNum == 0x9D || sNum == 0x9E
            || sNum == 0x9F) {
            if (v < 0) {
                this->sn[sNum] = 0;
            } else if (v > 100) {
                this->sn[sNum] = 100;
            }
        }
        if (sNum == 0x69) {
            this->md->informationAI.setSaveLearnInformation(v);
        }
    }
}

void TribeTacticalAIModule::notify(int callerID, int recipientID, int mType, long p1, long p2, long p3) {
    RGE_Static_Object* callerObject = this->md->aiPlayer->world->object(callerID);

    if (mType != 0x72 && mType != 0x74 && callerObject == 0)
        return;

    ulong entryTime = debug_timeGetTime(s_file, 6404);

    if (mType == 0x72 || mType == 0x74) {
        ObjectMemory* memory;
        if (mType == 0x72)
            memory = this->md->informationAI.artifactToCapture(-1);
        else
            memory = this->md->informationAI.ruinToCapture(-1);

        if (memory == 0)
            return;

        int numberToTask = this->numberSoldiersWithPriority(100, -1, 1);
        if (numberToTask > 3)
            numberToTask = 3;

        int tasked = 0;
        int index = 0;
        while (index < this->workingArea.numberValue && tasked < numberToTask) {
            RGE_Static_Object* object = this->md->aiPlayer->world->object(this->workingArea[index]);
            if (object != 0 && object->unitAI() != 0 && object->canPath(memory->id, 2.0f, 0, 1, -1, -1) != 0
                && this->taskDefender(this->workingArea[index], memory->id, 2.0f, 100) == 1) {
                this->removeFromGroup(this->workingArea[index]);
                tasked++;
            }
            index++;
        }
        return;
    }

    if (mType != 0x201)
        return;

    RGE_Static_Object* attacker = this->md->aiPlayer->world->object(p1);
    if (attacker == 0 || attacker->owner->id == this->md->player->id)
        return;

    RGE_Static_Object* target = this->md->aiPlayer->world->object(callerID);
    if (target == 0)
        return;

    if (attacker->owner->id == 0) {
        if ((this->zoomingToNextAge == 0
             || (attacker->master_obj->id != MASTER_OBJECT_LION && attacker->master_obj->id != MASTER_OBJECT_LION_KING))
            && this->dealWithGAIAAttacker(attacker, target) == 1)
            return;
    }

    if (attacker->owner->id != 0) {
        int adjustAttack = 1;
        if (this->civilians.contains(callerID) != 0 && this->civilianExplorers.contains(callerID) == 0) {
            adjustAttack = 1;
        } else if (target->unitAI() == 0 || target->unitAI()->currentOrder() == UNIT_AI_ORDER_EXPLORE) {
            adjustAttack = 0;
        }

        if (adjustAttack != 0) {
            if (this->md->player->world->difficultyLevel() == RGE_DIFFICULTY_EASY)
                this->sn[SNInitialAttackDelay] -= 2;
            else if (this->md->player->world->difficultyLevel() == RGE_DIFFICULTY_EASIEST)
                this->sn[SNInitialAttackDelay]--;
            else
                this->md->tacticalAI.enableAttack(3);

            this->checkForAttackResponseBuildInsertions((int) attacker->owner->id);
        }
    }

    this->hitsByPlayer[attacker->owner->id]++;

    //! @bug Accidental ally hits accumulate and trip this default-on flip to enemy stance.
    //! hitsByPlayer never resets during play, so three stray hits over a match suffice.
    //! RockNROR prevents it by forcing personality number SNAllowDiplomacyChangeOnAllyAttack (215) to 0.
    if (attacker->owner->computerPlayer() == 0) {
        if (this->md->player->isAlly((int) attacker->owner->id) == 1
            && this->hitsByPlayer[attacker->owner->id] >= this->sn[0xdd] && this->sn[0xd7] == 1) {
            this->md->diplomacyAI.setChangeable((int) attacker->owner->id, 1);
            this->md->diplomacyAI.setStance((int) attacker->owner->id, 0, 100);
            this->md->diplomacyAI.setRelation((int) attacker->owner->id, 3);
            this->md->diplomacyAI.setChangeable((int) attacker->owner->id, 0);
        } else {
            this->md->diplomacyAI.changeStance((int) attacker->owner->id, 2, this->sn[0xb2]);
            this->md->diplomacyAI.changeStance((int) attacker->owner->id, 0, this->sn[0xb2]);
        }
    } else if (this->md->player->isAlly((int) attacker->owner->id) == 1
               && this->md->player->world->players[attacker->owner->id]->isEnemy(this->md->player->id) == 1) {
        this->md->diplomacyAI.setChangeable((int) attacker->owner->id, 1);
        this->md->diplomacyAI.setStance((int) attacker->owner->id, 0, 100);
        this->md->diplomacyAI.setRelation((int) attacker->owner->id, 3);
        this->md->diplomacyAI.setChangeable((int) attacker->owner->id, 0);
    }

    if (this->sn[SNTributeAmount] > 0 && this->sn[SNTributePlayer] == (int) attacker->owner->id
        && this->sn[SNTributeRevokeOnAttack] == 1)
        this->md->revokeTributeAlliance();

    this->md->informationAI.storeAttackMemory(
        0, (uchar) target->world_x, (uchar) target->world_y, (uchar) attacker->owner->id, (uchar) this->md->player->id,
        0, 0, this->md->player->world->world_time, -1
    );

    ulong elapsed = (this->md->player->world->world_time - this->lastAttackResponseTime) / 1000;
    if (this->lastAttackResponseTime != 0 && elapsed < this->attackLimiterTime(SNAttackResponseSeparationTime))
        return;

    XYPoint attackPoint;
    attackPoint.x = (int) attacker->world_x;
    attackPoint.y = (int) attacker->world_y;

    TacticalAIGroup* responseGroup;
    if (this->md->informationAI.isBoat(attacker) == 1) {
        responseGroup = this->readyAndIdleGroup(
            TACTICAL_GROUP_TYPE_BOAT_ATTACK, this->sn[SNEnemySightedResponseDistance], attackPoint
        );
    } else {
        responseGroup =
            this->readyAndIdleGroup(TACTICAL_GROUP_TYPE_ATTACK, this->sn[SNEnemySightedResponseDistance], attackPoint);
        if (responseGroup == 0)
            responseGroup = this->readyAndIdleGroup(
                TACTICAL_GROUP_TYPE_BOAT_ATTACK, this->sn[SNEnemySightedResponseDistance], attackPoint
            );
    }

    if (responseGroup != 0) {
        RGE_Static_Object* commander = this->md->player->world->object(responseGroup->commander());
        if (commander != 0) {
            XYZPoint point;
            point.x = (int) attacker->world_x;
            point.y = (int) attacker->world_y;
            point.z = (int) attacker->world_z;
            if (commander->canPath(point, commander->weaponRange(), attacker->id, 0, 1, -1, -1) == 1) {
                responseGroup->setTarget((int) p1);
                responseGroup->setTargetType((int) attacker->master_obj->id);
                responseGroup->setTargetLocation(attacker->world_x, attacker->world_y, attacker->world_z);
                responseGroup->setAction(TACTICAL_GROUP_ACTION_ATTACK);
                responseGroup->task(this, this->md, TACTICAL_GROUP_ACTION_ATTACK, 1, 0);
                this->lastAttackResponseTime = this->md->player->world->world_time;
                if (this->sn[SNLockAttackAndAttackResponse] == 1)
                    this->lastGroupAttackTime = this->md->player->world->world_time;
                return;
            }
        }
    }

    RGE_Static_Object* townCenter =
        this->md->object(-1, MASTER_OBJECT_TOWN_CENTER1, -1, -1, -1, -1, -1, -1, RGE_OBJECT_STATE_ANY, -1);
    int townDistance = 1000;
    if (townCenter != 0) {
        float xDistance = townCenter->world_x - attacker->world_x;
        float yDistance = townCenter->world_y - attacker->world_y;
        townDistance = (int) sqrt(xDistance * xDistance + yDistance * yDistance);
    }

    int numberToRespond;
    int available;
    if (townDistance < 20) {
        available = this->numberWarshipsWithPriority(100, -1);
        available += this->numberSoldiersWithPriority(100, -1, 0);
        numberToRespond = available;

        ulong seconds = this->md->player->world->world_time / 1000;

        if (numberToRespond == 0 && this->md->informationAI.isBoat(attacker) == 0 && this->sn[0xe1] == 1
            && seconds < this->sn[SNInitialAttackDelay]) {
            int i;
            for (i = 0; i < this->civilians.numberValue; i++) {
                int civilian = this->civilians[i];
                this->workingArea.add(civilian);
            }
            numberToRespond = this->civilians.numberValue;
        }
    } else {
        if (this->md->informationAI.isBoat(attacker) == 1) {
            available = this->numberWarshipsWithPriority(this->sn[SNEnemySightedResponseDistance], -1);
        } else {
            available = this->numberWarshipsWithPriority(this->sn[SNEnemySightedResponseDistance], -1);
            available += this->numberSoldiersWithPriority(this->sn[SNEnemySightedResponseDistance], -1, 0);
        }
        numberToRespond = this->sn[SNPercentEnemySightedResponse] * available / 100;
    }

    if (townCenter != 0) {
        this->checkForCoopAttack((int) attacker->owner->id, (int) townCenter->world_x, (int) townCenter->world_y);
    } else {
        this->checkForCoopAttack((int) attacker->owner->id, (int) attacker->world_x, (int) attacker->world_y);
    }

    int responded = 0;
    int index = 0;
    while (index < this->workingArea.numberValue && responded < numberToRespond) {
        if (index > 1 && debug_timeGetTime(s_file, 6740) - entryTime > 10)
            return;

        RGE_Static_Object* object = this->md->aiPlayer->world->object(this->workingArea[index]);
        if (object != 0 && object->unitAI() != 0) {
            if (object->unitAI()->currentAction() == UNIT_AI_ACTION_ATTACK) {
                if (object->unitAI()->currentTarget() != -1) {
                    if (object->unitAI()->currentTarget() == attacker->id) {
                        responded++;
                        goto next_object;
                    }

                    RGE_Static_Object* currentTarget =
                        this->md->player->world->object(object->unitAI()->currentTarget());
                    if (currentTarget != 0 && (int) currentTarget->owner->id == this->playersToAttack[0])
                        goto next_object;
                }
            }

            if (this->workingArea[index] == callerID) {
                if (object->unitAI()->currentOrderPriority() != 100) {
                    XYZPoint point;
                    point.x = (int) attacker->world_x;
                    point.y = (int) attacker->world_y;
                    point.z = (int) attacker->world_z;
                    if (object->canPath(point, object->weaponRange(), attacker->id, 0, 1, -1, -1) != 0
                        && this->taskAttacker(
                               this->workingArea[index], attacker->world_x, attacker->world_y, attacker->id,
                               (int) attacker->owner->id, 0, 0, -1, 0
                           ) == 1) {
                        this->lastAttackResponseTime = this->md->player->world->world_time;
                        if (this->sn[SNLockAttackAndAttackResponse] == 1)
                            this->lastGroupAttackTime = this->md->player->world->world_time;
                        responded++;
                    }
                }
            } else {
                float distance = callerObject->distance_to_object(object);
                int priority = this->calculatePriority(distance);
                if (distance < (float) this->sn[SNEnemySightedResponseDistance]
                    && object->unitAI()->currentOrderPriority() < priority && priority > 0) {
                    XYZPoint point;
                    point.x = (int) attacker->world_x;
                    point.y = (int) attacker->world_y;
                    point.z = (int) attacker->world_z;
                    if (object->canPath(point, object->weaponRange(), attacker->id, 0, 1, -1, -1) != 0
                        && this->taskAttacker(
                               this->workingArea[index], attacker->world_x, attacker->world_y, attacker->id,
                               (int) attacker->owner->id, 0, 0, -1, 0
                           ) == 1) {
                        responded++;
                    }
                }
            }
        }

    next_object:
        index++;
    }
}

int TribeTacticalAIModule::numberIdleSoldiers() {
    int count = 0;
    int i = 0;
    ManagedArray<int>& workingArea = this->workingArea;
    ManagedArray<int>& soldiers = this->soldiers;

    workingArea.numberValue = 0;
    if (soldiers.numberValue > 0) {
        do {
            RGE_Static_Object* obj = this->md->aiPlayer->world->object(soldiers[i]);
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

int TribeTacticalAIModule::numberSoldiersWithPriority(int priority, int flag, int zeroWorkingArea) {
    int count = 0;
    int i;
    RGE_Static_Object* object;

    if (zeroWorkingArea == 1)
        this->workingArea.zeroNumber();

    for (i = 0; i < this->soldiers.number(); i++) {
        object = this->md->aiPlayer->world->object(this->soldiers[i]);
        if (object != 0 && object->unitAI() != 0 && this->unitsTaskedThisUpdate.contains(this->soldiers[i]) == 0) {
            if (flag < 0) {
                if (object->unitAI()->currentAction() == -1 || object->unitAI()->currentOrderPriority() < priority) {
                    this->workingArea.add(this->soldiers[i]);
                    count++;
                }
            } else if (flag > 0) {
                if (object->unitAI()->currentAction() != -1 && object->unitAI()->currentOrderPriority() > priority) {
                    this->workingArea.add(this->soldiers[i]);
                    count++;
                }
            } else {
                if (object->unitAI()->currentAction() != -1 && object->unitAI()->currentOrderPriority() == priority) {
                    this->workingArea.add(this->soldiers[i]);
                    count++;
                }
            }
        }
    }
    return count;
}

int TribeTacticalAIModule::numberWarshipsWithPriority(int priority, int flag) {
    int count = 0;
    int i;
    RGE_Static_Object* object;

    this->workingArea.zeroNumber();

    for (i = 0; i < this->warBoats.number(); i++) {
        object = this->md->aiPlayer->world->object(this->warBoats[i]);
        if (object != 0 && object->unitAI() != 0 && this->unitsTaskedThisUpdate.contains(this->warBoats[i]) == 0) {
            if (flag < 0) {
                if (object->unitAI()->currentAction() == -1 || object->unitAI()->currentOrderPriority() < priority) {
                    this->workingArea.add(this->warBoats[i]);
                    count++;
                }
            } else if (flag > 0) {
                if (object->unitAI()->currentAction() != -1 && object->unitAI()->currentOrderPriority() > priority) {
                    this->workingArea.add(this->warBoats[i]);
                    count++;
                }
            } else {
                if (object->unitAI()->currentAction() != -1 && object->unitAI()->currentOrderPriority() == priority) {
                    this->workingArea.add(this->warBoats[i]);
                    count++;
                }
            }
        }
    }

    for (i = 0; i < this->soldiers.number(); i++) {
        object = this->md->aiPlayer->world->object(this->soldiers[i]);
        if (object != 0 && object->unitAI() != 0 && this->unitsTaskedThisUpdate.contains(this->soldiers[i]) == 0
            && (object->master_obj->object_group == OBJECT_GROUP_PRIEST
                || object->master_obj->object_group == OBJECT_GROUP_SIEGE_WEAPON)) {
            if (flag < 0) {
                if (object->unitAI()->currentAction() == -1 || object->unitAI()->currentOrderPriority() < priority) {
                    this->workingArea.add(this->soldiers[i]);
                    count++;
                }
            } else if (flag > 0) {
                if (object->unitAI()->currentAction() != -1 && object->unitAI()->currentOrderPriority() > priority) {
                    this->workingArea.add(this->soldiers[i]);
                    count++;
                }
            } else {
                if (object->unitAI()->currentAction() != -1 && object->unitAI()->currentOrderPriority() == priority) {
                    this->workingArea.add(this->soldiers[i]);
                    count++;
                }
            }
        }
    }

    return count;
}

int TribeTacticalAIModule::idleSoldier() {
    for (int i = 0; i < soldiers.numberValue; i++) {
        RGE_Static_Object* obj = md->player->world->object(soldiers[i]);
        if (obj != 0 && obj->unitAI() != 0) {
            if (obj->unitAI()->currentAction() == -1)
                return obj->id;
        }
    }
    return -1;
}

int TribeTacticalAIModule::idleCivilian(int checkGroup) {
    RGE_Static_Object* firstObject;
    RGE_Static_Object* secondObject;
    int i = 0;
    ManagedArray<int>& tasked = this->unitsTaskedThisUpdate;
    if (this->civilians.numberValue > 0) {
        ManagedArray<int>* civilians = &this->civilians;
        do {
            if (tasked.contains((*civilians)[i]) != 0)
                goto first_next;

            firstObject = this->md->player->world->object((*civilians)[i]);
            if ((firstObject != 0) && (firstObject->unitAI() != 0)) {
                if (this->isGatherer((*civilians)[i]) == 0) {
                    if (this->civilianExplorers.contains((*civilians)[i]) != 0)
                        goto first_next;
                    if (firstObject->unitAI()->currentAction() == -1 && firstObject->unitAI()->currentOrder() == -1)
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

        secondObject = this->md->player->world->object((*civilians)[i]);
        if ((secondObject != 0) && (secondObject->unitAI() != 0)) {
            if (checkGroup != 0) {
                if (checkGroup != 3) {
                    if (this->isGatherer((*civilians)[i]) != 0)
                        goto second_next;
                }
            }
            if ((checkGroup != 0) && (checkGroup != 1)) {
                if (this->civilianExplorers.contains((*civilians)[i]) != 0)
                    goto second_next;
            }
            if (secondObject->unitAI()->currentAction() == -1 && secondObject->unitAI()->currentOrder() == -1)
                return secondObject->id;
        }
    second_next:
        i++;
        if (i < this->civilians.numberValue)
            goto second_loop;
    }
    return -1;
}

int TribeTacticalAIModule::idleCivilian(int checkGroup, XYPoint& point, int closestToPoint) {
    RGE_Static_Object* firstObject;
    RGE_Static_Object* secondObject;
    float bestUnitDistance = 0.0f;
    int bestUnitID = -1;
    int i = 0;

    if (this->civilians.numberValue > 0) {
        ManagedArray<int>* civilians = &this->civilians;
        do {
            if (this->unitsTaskedThisUpdate.contains((*civilians)[i]) != 0)
                goto first_next;

            firstObject = this->md->player->world->object((*civilians)[i]);
            if ((firstObject != 0) && (firstObject->unitAI() != 0)) {
                if (this->isGatherer((*civilians)[i]) == 0) {
                    if (this->civilianExplorers.contains((*civilians)[i]) != 0)
                        goto first_next;
                    if (firstObject->unitAI()->currentAction() == -1 && firstObject->unitAI()->currentOrder() == -1)
                        return firstObject->id;
                }
            }
        first_next:
            i++;
        } while (i < this->civilians.numberValue);
    }

    i = 0;
    if (this->civilians.numberValue > 0) {
        ManagedArray<int>* civilians = &this->civilians;
        do {
            if (this->unitsTaskedThisUpdate.contains((*civilians)[i]) != 0)
                goto second_next;

            secondObject = this->md->player->world->object((*civilians)[i]);
            if ((secondObject != 0) && (secondObject->unitAI() != 0)) {
                if (checkGroup != 0) {
                    if (checkGroup != 3) {
                        if (this->isGatherer((*civilians)[i]) != 0)
                            goto second_next;
                    }
                }
                if ((checkGroup != 0) && (checkGroup != 1)) {
                    if (this->civilianExplorers.contains((*civilians)[i]) != 0)
                        goto second_next;
                }
                if (secondObject->unitAI()->currentAction() == -1 && secondObject->unitAI()->currentOrder() == -1) {
                    float distance =
                        secondObject->distance_to_position((float) point.x, (float) point.y, secondObject->world_z);
                    if (bestUnitID == -1) {
                        bestUnitDistance = distance;
                        bestUnitID = secondObject->id;
                    } else if ((closestToPoint == 1 && bestUnitDistance > distance)
                               || (closestToPoint == 0 && bestUnitDistance < distance)) {
                        bestUnitDistance = distance;
                        bestUnitID = secondObject->id;
                    }
                }
            }
        second_next:
            i++;
        } while (i < this->civilians.numberValue);
    }
    return bestUnitID;
}

int TribeTacticalAIModule::civilian(XYPoint& point, int closestToPoint, int a1, int a2, int a3, int useFarmers) {
    float bestUnitDistance;
    int bestUnitID;
    int i;
    RGE_Static_Object* obj;

    bestUnitID = -1;
    bestUnitDistance = 0;
    i = 0;
    if (this->civilians.numberValue > 0) {
        do {
            if (this->unitsTaskedThisUpdate.contains(this->civilians[i]) != 0)
                goto next;

            obj = this->md->player->world->object(this->civilians[i]);
            if (obj != 0 && obj->unitAI() != 0) {
                if (useFarmers != 0 || obj->master_obj->id != MASTER_OBJECT_FARMER) {
                    if (obj->unitAI()->currentOrder() != a1 && obj->unitAI()->currentOrder() != a2
                        && obj->unitAI()->currentOrder() != a3) {
                        float dist = obj->distance_to_position((float) point.x, (float) point.y, obj->world_z);
                        if (bestUnitID == -1) {
                            bestUnitDistance = dist;
                            bestUnitID = obj->id;
                        } else if ((closestToPoint == 1 && bestUnitDistance > dist)
                                   || (closestToPoint == 0 && bestUnitDistance < dist)) {
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

int TribeTacticalAIModule::unit(int action, int target, int targetType) {
    int i;
    RGE_Static_Object* object;

    for (i = 0; i < this->civilians.numberValue; i++) {
        object = this->md->aiPlayer->world->object(this->civilians[i]);
        if (object == 0 && object->unitAI() == 0) {
            if (action == -1 || object->unitAI()->currentAction() == action) {
                if (target == -1 || object->unitAI()->currentTarget() == target) {
                    if (targetType == -1 || object->unitAI()->currentTargetType() == targetType) {
                        return this->civilians[i];
                    }
                }
            }
        }
    }

    for (i = 0; i < this->soldiers.numberValue; i++) {
        object = this->md->aiPlayer->world->object(this->soldiers[i]);
        if (object == 0 && object->unitAI() == 0) {
            if (action == -1 || object->unitAI()->currentAction() == action) {
                if (target == -1 || object->unitAI()->currentTarget() == target) {
                    if (targetType == -1 || object->unitAI()->currentTargetType() == targetType) {
                        return this->soldiers[i];
                    }
                }
            }
        }
    }

    for (i = 0; i < this->boats.numberValue; i++) {
        object = this->md->aiPlayer->world->object(this->boats[i]);
        if (object == 0 && object->unitAI() == 0) {
            if (action == -1 || object->unitAI()->currentAction() == action) {
                if (target == -1 || object->unitAI()->currentTarget() == target) {
                    if (targetType == -1 || object->unitAI()->currentTargetType() == targetType) {
                        return this->boats[i];
                    }
                }
            }
        }
    }

    return -1;
}

int TribeTacticalAIModule::busyWithAction(int id, int a) {
    RGE_Static_Object* obj = this->md->aiPlayer->world->object(id);
    if (obj != 0) {
        UnitAIModule* ai = obj->unitAI();
        if (ai != 0) {
            if (obj->unitAI()->currentAction() == a) {
                return 1;
            }
        }
    }
    return 0;
}

void TribeTacticalAIModule::displayCivilianDistribution() {
}

void TribeTacticalAIModule::updateNeededResources() {
    int assignedResource[4];
    int tempNeededResource[4];
    int tempResourceDifference[4];
    int i;
    int* diffPtr;
    int bestResource;
    int bestDifference;
    int rank;

    this->md->buildAI.mostNeededResource(this->neededResources, this->sn[0x93]);

    i = 0;
    // Indexing resourceDifferenceValue[i] here instead of the cursor changes this function by 18 bytes.
    diffPtr = this->resourceDifferenceValue;
    for (int init = 0; init < 4; init++) {
        assignedResource[init] = 0;
        tempNeededResource[init] = -1;
        tempResourceDifference[init] = -1;
    }

    do {
        *diffPtr = this->md->resourceAI.resource(i) - this->neededResources.value(i);
        i++;
        diffPtr++;
    } while (i < 4);

    rank = 0;
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
                if ((bestResource == -1 || this->resourceDifferenceValue[i] < bestDifference)
                    && assignedResource[i] == 0) {
                    bestDifference = this->resourceDifferenceValue[i];
                    bestResource = i;
                }
            }
        next_resource:
            i++;
        } while (i < 4);

        if (bestResource == -1) {
            //! Fallback ranks by the smallest deficit only; it checks neither need nor age.
            i = 0;
            do {
                if ((bestResource == -1 || this->resourceDifferenceValue[i] < bestDifference)
                    && assignedResource[i] == 0) {
                    bestDifference = this->resourceDifferenceValue[i];
                    bestResource = i;
                }
                i++;
            } while (i < 4);
        }

        assignedResource[bestResource] = 1;
        tempNeededResource[rank] = bestResource;
        tempResourceDifference[rank] = bestDifference;
        rank++;
    } while (rank < 4);

    i = 0;
    for (; i < 4; i++) {
        int resource = tempNeededResource[i];
        int difference = tempResourceDifference[i];
        this->neededResourceValue[i] = resource;
        this->resourceDifferenceValue[resource] = difference;
    }
}

void TribeTacticalAIModule::updateGathererDistribution() {
    int gSTT;
    int gAction;
    int i;
    int gatherer_index;
    int distribution_set;

    for (i = 0; i < 4; ++i)
        this->actualGathererDistribution[i] = 0;

    gatherer_index = 0;
    if (this->numberGatherersValue > 0) {
        do {
            RGE_Static_Object* object = this->md->object(this->gatherers[gatherer_index].id);
            if (object != 0 && object->unitAI() != 0) {
                gSTT = object->unitAI()->currentAction();
                gAction = this->gatherers[gatherer_index].data1;
                this->gatherers[gatherer_index].target = object->unitAI()->currentTarget();

                if (gSTT == UNIT_AI_ACTION_GATHER && object->master_obj->id == MASTER_OBJECT_FARMER && gAction != 0) {
                    int taskedCount = this->unitsTaskedThisUpdate.numberValue;
                    int objectID = object->id;
                    int j = 0;
                    int found = 0;
                    if (taskedCount > 0) {
                        do {
                            if (this->unitsTaskedThisUpdate.maximumSizeValue <= j)
                                break;
                            if (this->unitsTaskedThisUpdate.value[j] == objectID) {
                                found = 1;
                                break;
                            }
                            ++j;
                        } while (j < taskedCount);
                    }
                    if (found == 0)
                        this->gatherers[gatherer_index].data1 = 0;
                }

                if (gAction >= 0 && gAction <= 3) {
                    if (gSTT == UNIT_AI_ACTION_GATHER || gSTT == UNIT_AI_ACTION_HUNT) {
                        this->actualGathererDistribution[gAction]++;
                    } else {
                        int taskedCount = this->unitsTaskedThisUpdate.numberValue;
                        int j = 0;
                        if (taskedCount > 0) {
                            do {
                                if (this->unitsTaskedThisUpdate.maximumSizeValue <= j)
                                    break;
                                if (this->unitsTaskedThisUpdate.value[j] == this->gatherers[gatherer_index].id) {
                                    this->actualGathererDistribution[gAction]++;
                                    break;
                                }
                                ++j;
                            } while (j < taskedCount);
                        }
                    }
                }
            }
            ++gatherer_index;
        } while (gatherer_index < this->numberGatherersValue);
    }

    this->desiredGathererDistribution[0] = 0;
    this->desiredGathererDistribution[1] = 0;
    this->desiredGathererDistribution[2] = 0;
    this->desiredGathererDistribution[3] = 0;
    distribution_set = 0;

    if (this->inAge(1) != 0) {
        if (this->sn[0xB5] == 1) {
            if (this->md->buildAI.readyToResearch(2, 1) != 0 && this->md->informationAI.closestDropsiteValue[0] != -1
                && (this->md->resourceAI.resource(RGE_RESOURCE_WOOD) > 0x78 || this->builtFirstGranary == 1)) {
                this->desiredGathererDistribution[0] = this->desiredNumberGatherersValue;
                for (i = 0; i < this->numberGatherersValue; ++i) {
                    if (this->gatherers[i].data1 != 0 && this->gatherers[i].data1 != -1)
                        this->gatherers[i].data2 = 5;
                }
                this->zoomingToNextAge = 1;
                distribution_set = 1;
            } else {
                int desired = this->desiredNumberGatherersValue;
                this->zoomingToNextAge = 0;
                this->desiredGathererDistribution[1] = desired;
                distribution_set = 1;
            }
        } else {
            this->zoomingToNextAge = 0;
        }
    } else if (this->inAge(2) != 0) {
        if (this->sn[0xB6] == 1) {
            if (this->md->buildAI.readyToResearch(3, 1) != 0
                && (this->md->resourceAI.resource(RGE_RESOURCE_WOOD) > 0xF0
                    || (this->md->resourceAI.resource(RGE_RESOURCE_WOOD) > 0x78
                        && this->md->informationAI.closestDropsiteValue[0] < 0x14))) {
                this->desiredGathererDistribution[0] = this->desiredNumberGatherersValue;
                for (i = 0; i < this->numberGatherersValue; ++i) {
                    if (this->gatherers[i].data1 != 0 && this->gatherers[i].data1 != -1)
                        this->gatherers[i].data2 = 5;
                }
                this->zoomingToNextAge = 1;
                distribution_set = 1;
            } else {
                int desired = this->desiredNumberGatherersValue;
                this->zoomingToNextAge = 0;
                this->desiredGathererDistribution[1] = desired;
                distribution_set = 1;
            }
        } else {
            this->zoomingToNextAge = 0;
        }
    } else if (this->inAge(3) != 0) {
        if (this->sn[0xB7] == 1) {
            if (this->md->buildAI.readyToResearch(4, 1) == 0) {
                int third = this->desiredNumberGatherersValue / 3;
                this->zoomingToNextAge = 0;
                this->desiredGathererDistribution[0] = third;
                this->desiredGathererDistribution[3] = third;
                this->desiredGathererDistribution[1] = third;
                distribution_set = 1;
            } else {
                int half = this->desiredNumberGatherersValue / 2;
                this->desiredGathererDistribution[0] = half;
                this->desiredGathererDistribution[3] = half;
                for (i = 0; i < this->numberGatherersValue; ++i) {
                    if (this->gatherers[i].data1 != 0 && this->gatherers[i].data1 != 3
                        && this->gatherers[i].data1 != -1)
                        this->gatherers[i].data2 = 5;
                }
                this->zoomingToNextAge = 1;
                distribution_set = 1;
            }
        } else {
            this->zoomingToNextAge = 0;
        }
    }

    if (distribution_set == 0) {
        int desired2Percent = this->sn[0x77];
        int desired2ExtraPercent = this->sn[0x9E];
        int desired = this->desiredNumberGatherersValue;
        int desired2Amount = (desired2Percent + desired2ExtraPercent) * desired;

        int desired3Percent = this->sn[0x76];
        this->desiredGathererDistribution[2] = desired2Amount / 100;
        int desired3ExtraPercent = this->sn[0x9F];
        int desired3Amount = (desired3Percent + desired3ExtraPercent) * desired;

        int desired1Percent = this->sn[0x78];
        this->desiredGathererDistribution[3] = desired3Amount / 100;
        int desired1ExtraPercent = this->sn[0x9D];
        int desired1Amount = (desired1Percent + desired1ExtraPercent) * desired;

        int desired0Percent = this->sn[0x75];
        int desired1 = desired1Amount / 100;
        int desired0ExtraPercent = this->sn[0x9C];
        int desired0Amount = (desired0Percent + desired0ExtraPercent) * desired;

        this->desiredGathererDistribution[1] = desired1;
        this->desiredGathererDistribution[0] = desired0Amount / 100;
    }

    int desiredTotal = 0;
    for (i = 0; i < 4; ++i)
        desiredTotal += this->desiredGathererDistribution[i];

    int remainder = this->desiredNumberGatherersValue - desiredTotal;
    int deficitCount = 0;
    int deficitTotal = 0;
    for (i = 0; i < 4; ++i) {
        if (this->resourceDifferenceValue[i] < 0) {
            deficitTotal -= this->resourceDifferenceValue[i];
            ++deficitCount;
        }
    }

    if (deficitCount > 0) {
        int* resource = this->neededResourceValue;
        do {
            int resourceID = *resource++;
            int difference = this->resourceDifferenceValue[resourceID];
            int adjustment = (difference * remainder) / deficitTotal;
            this->desiredGathererDistribution[resourceID] -= adjustment;
            --deficitCount;
        } while (deficitCount != 0);
    }

    desiredTotal = 0;
    for (i = 0; i < 4; ++i)
        desiredTotal += this->desiredGathererDistribution[i];

    remainder = this->desiredNumberGatherersValue - desiredTotal;
    if (remainder > 0) {
        int half = remainder / 2;
        int first = half;
        if ((remainder % 2) != 0)
            ++first;
        int firstDesired = this->desiredGathererDistribution[0];
        int secondDesired = this->desiredGathererDistribution[1];
        firstDesired += first;
        secondDesired += half;
        this->desiredGathererDistribution[0] = firstDesired;
        this->desiredGathererDistribution[1] = secondDesired;
    }
}

int TribeTacticalAIModule::stopUnit(int uID, int priority) {
    RGE_Player* player = this->md->player;
    player->sendUnitAIOrder(
        (int) player->id, uID, UNIT_AI_ORDER_STOP, -1, -1, -1.0f, -1.0f, -1.0f, -1.0f, 1, 0, priority
    );
    return 1;
}

// moveUnit sends the order through md->unit with the player's id.

int TribeTacticalAIModule::moveUnit(int uID, float x, float y, int priority) {
    RGE_Player* player = this->md->player;
    player->sendUnitAIOrder((int) player->id, uID, UNIT_AI_ORDER_MOVE, -1, -1, x, y, 1.0f, 1.0f, 1, 0, priority);
    return 1;
}

int TribeTacticalAIModule::groupGatherUnit(int uID, int tID, float x, float y, float z, float range, int priority) {
    RGE_Player* player = this->md->player;
    player->sendUnitAIOrder(
        (int) player->id, uID, UNIT_AI_ORDER_MOVE_TO_TARGET, tID, -1, x, y, z, range, 1, 0, priority
    );
    return 1;
}

int TribeTacticalAIModule::highLevelTaskExplorer(int unitID, int civilian) {
    RGE_Static_Object* object = this->md->player->world->object(unitID);
    if (object == 0 || object->unitAI() == 0) {
        return 0;
    }

    UnitAIModule* ai = object->unitAI();
    int action = ai->currentAction();
    if (action == UNIT_AI_ACTION_ATTACK) {
        return 1;
    }

    ai = object->unitAI();
    action = ai->currentAction();
    if (action != UNIT_AI_ACTION_BUILD) {
        ai = object->unitAI();
        action = ai->currentAction();
        if (action != UNIT_AI_ACTION_REPAIR) {
            ai = object->unitAI();
            action = ai->currentAction();
            if (action == UNIT_AI_ACTION_EXPLORE) {
                return 1;
            }

            if (object->attribute_amount_held > 0.0f) {
                return 0;
            }

            ai = object->unitAI();
            if (ai->currentOrder() == UNIT_AI_ORDER_MOVE) {
                ai = object->unitAI();
                if (ai->currentOrderPriority() == 100) {
                    return 0;
                }
            }

            ai = object->unitAI();
            if (ai->currentOrder() == UNIT_AI_ORDER_BUILD) {
                return 0;
            }

            if (object->unitAI()->hasOrderOnQueue(UNIT_AI_ORDER_EXPLORE) == 1) {
                return 0;
            }

            return this->taskExplorer(unitID, civilian) != 0;
        }
    }
    return 1;
}

int TribeTacticalAIModule::highLevelTaskGatherer(int unitID, unsigned long startTime) {
    int triedTasking[4] = { 0, 0, 0, 0 };
    int gathererIndex = 0;

    while (gathererIndex < this->numberGatherersValue && this->gatherers[gathererIndex].id != unitID) {
        gathererIndex++;
    }
    if (gathererIndex >= this->numberGatherersValue) {
        return 0;
    }

    UnitData* gatherer = &this->gatherers[gathererIndex];
    unsigned long currentTime = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\taitacmd.cpp", 8028);
    if (currentTime - gatherer->lastTaskTime < 5000) {
        return 1;
    }
    gatherer->lastTaskTime = currentTime;

    RGE_Static_Object* gathererObject = this->md->player->world->object(unitID);
    if (gathererObject == 0 || gathererObject->unitAI() == 0) {
        return 0;
    }

    if (gathererObject->unitAI()->currentAction() == UNIT_AI_ACTION_ATTACK) {
        return 1;
    }
    if (gathererObject->unitAI()->currentAction() == UNIT_AI_ACTION_BUILD
        || gathererObject->unitAI()->currentAction() == UNIT_AI_ACTION_REPAIR) {
        return 1;
    }
    if (gathererObject->attribute_amount_held > 0.0f) {
        return 1;
    }

    if (this->isFarmer(gathererObject) == 1) {
        int numberCivilians = this->civilians.numberValue;
        int nonFarmers = numberCivilians - this->numberFarmers();
        if (this->md->resourceAI.resource(RGE_RESOURCE_FOOD) < 1000 && nonFarmers > 3) {
            return 1;
        }
    }

    if (gathererObject->unitAI()->currentOrder() == UNIT_AI_ORDER_MOVE
        && gathererObject->unitAI()->currentOrderPriority() == 100) {
        return 1;
    }
    if (gathererObject->unitAI()->currentOrder() == UNIT_AI_ORDER_BUILD) {
        return 1;
    }

    if (gatherer->data3 < gatherer->data2) {
        if (gathererObject->unitAI()->currentAction() != -1) {
            return 1;
        }

        triedTasking[gatherer->data1] = 1;
        if (this->taskGatherer(gatherer->id, gatherer->data1, 0, startTime, 0) == 1) {
            return 1;
        }
        gatherer->data1 = -1;
        gatherer->data2 = -1;
        gatherer->data3 = -1;
    }

    int taskResult = 0;
    int resource;
    for (resource = 0; resource < 4; resource++) {
        if (triedTasking[resource] != 1
            && this->actualGathererDistribution[resource] < this->desiredGathererDistribution[resource]) {
            if (gatherer->data1 == resource) {
                int action = gathererObject->unitAI()->currentAction();
                if (action == UNIT_AI_ACTION_HUNT
                    || gathererObject->unitAI()->currentAction() == UNIT_AI_ACTION_GATHER) {
                    return 1;
                }
            }

            triedTasking[resource] = 1;
            taskResult = this->taskGatherer(gatherer->id, resource, 0, startTime, 0);
            if (taskResult == 1) {
                return 1;
            }
        }
    }

    if ((this->inAge(1) != 0 && this->sn[0xB5] == 1)
        || (this->inAge(2) != 0 && this->sn[0xB6] == 1 && triedTasking[0] == 0)) {
        triedTasking[0] = 1;
        taskResult = this->taskGatherer(gatherer->id, 0, 1, startTime, 0);
    } else if (this->inAge(3) != 0 && this->sn[0xB7] == 1) {
        if (triedTasking[0] == 0) {
            taskResult = this->taskGatherer(gatherer->id, 0, 1, startTime, 0);
            triedTasking[0] = 1;
        }
        if (triedTasking[3] == 0) {
            if (taskResult != 0) {
                return 1;
            }
            triedTasking[3] = 1;
            taskResult = this->taskGatherer(gatherer->id, 3, 1, startTime, 0);
        }
    }

    if (taskResult == 0) {
        this->taskGatherer(gatherer->id, -1, 1, startTime, triedTasking);
    }
    return 1;
}

int TribeTacticalAIModule::taskPlay(
    int commander, int* groupUnits, int groupCount, int target, int play, Waypoint* path, int pathLength
) {
    if (path != 0 && pathLength > 0) {
        do {
            addWaypoint(commander, (int) path->x, (int) path->y);
            path++;
            pathLength--;
        } while (pathLength != 0);
    }

    ManagedArray<int>& arr = this->unitsTaskedThisUpdate;
    int i;
    for (i = 0; i < arr.numberValue; i++) {
        if (i >= arr.maximumSizeValue)
            break;
        if (arr.value[i] == commander)
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

    arr.value[arr.numberValue] = commander;
    arr.numberValue++;

dispatch:
    md->player->sendPlayCommand(commander, groupUnits, groupCount, target, play);
    return 1;
}

int TribeTacticalAIModule::taskBuilder(int builder, BuildItem* newBuilding, ConstructionItem* ci, ulong startTime) {
    if (newBuilding == 0) {
        newBuilding = this->md->buildAI.nextBuildableItem(BUILD_CATEGORY_BUILDING);
        if (newBuilding == 0)
            return 0;
    }
    if (ci == 0) {
        ci = this->md->constructionAI.placeStructure(newBuilding, builder, this->placementStateValue, startTime);
        if (ci == 0)
            return 0;
    }
    if (builder == -1) {
        XYPoint position;
        position.x = (int) ci->x();
        position.y = (int) ci->y();
        builder = this->civilian(position, 1, UNIT_AI_ORDER_BUILD, UNIT_AI_ORDER_REPAIR, UNIT_AI_ORDER_ATTACK, 0);
    }
    RGE_Static_Object* obj = this->md->player->world->object(builder);
    if (obj == 0 || obj->unitAI() == 0) {
        if (ci != 0)
            delete ci;
        return 0;
    }
    int tx = (int) ci->x();
    int ty = (int) ci->y();
    int tz = (int) obj->world_z;
    XYZPoint p;
    p.x = tx;
    p.y = ty;
    p.z = tz;
    if (obj->canPath(p, 2.0f, -1, 0, 1, -1, -1) == 0) {
        if (ci != 0)
            delete ci;
        return 0;
    }
    newBuilding->setInProgress(1);
    newBuilding->setBuilt(0);
    int count = this->civilianExplorers.maximumSizeValue;
    int i = 0;
    if (count > 0) {
        while (i < count) {
            if (this->civilianExplorers.value[i] == builder)
                break;
            i++;
        }
    }
    if (i < count) {
        if (i < count - 1) {
            do {
                this->civilianExplorers.value[i] = this->civilianExplorers.value[i + 1];
                i++;
            } while (i < this->civilianExplorers.maximumSizeValue - 1);
        }
        this->civilianExplorers.numberValue--;
        if (this->civilianExplorers.numberValue < 0)
            this->civilianExplorers.numberValue = 0;
    }
    count = this->unitsTaskedThisUpdate.numberValue;
    for (i = 0; i < count; i++) {
        if (i >= this->unitsTaskedThisUpdate.maximumSizeValue)
            break;
        if (this->unitsTaskedThisUpdate.value[i] == builder)
            goto have;
    }
    if (count > this->unitsTaskedThisUpdate.maximumSizeValue - 1) {
        int newMax = count + 1;
        int* p = (int*) ::operator new(newMax * 4);
        if (p != 0) {
            for (i = 0; i < this->unitsTaskedThisUpdate.maximumSizeValue && i < newMax; i++)
                p[i] = this->unitsTaskedThisUpdate.value[i];
            ::operator delete(this->unitsTaskedThisUpdate.value);
            this->unitsTaskedThisUpdate.value = p;
            this->unitsTaskedThisUpdate.maximumSizeValue = newMax;
        }
    }
    this->unitsTaskedThisUpdate.value[this->unitsTaskedThisUpdate.numberValue] = builder;
    this->unitsTaskedThisUpdate.numberValue++;
have:
    if (ci->typeID() == MASTER_OBJECT_WONDER)
        this->wonderInProgressValue = 1;
    this->md->aiPlayer->buildObject(builder, ci->typeID(), ci->x(), ci->y(), newBuilding->uniqueID());
    if (ci != 0)
        delete ci;
    return 1;
}

int TribeTacticalAIModule::taskBuilder(int builder, RGE_Static_Object* building) {
    RGE_Static_Object* builderObj;
    RGE_Static_Object* obj;
    if ((obj = this->md->player->world->object(builder)) == 0)
        return 0;

    builderObj = building;
    XYZPoint point;
    point.x = (int) builderObj->world_x;
    point.y = (int) builderObj->world_y;
    point.z = (int) builderObj->world_z;

    if (builderObj == 0) {
        if (!obj->canPath(point, 1.0f, -1, 0, 1, -1, -1))
            return 0;
    } else {
        if (!obj->canPath(point, 1.0f, builderObj->id, 0, 1, -1, -1)) {
            if (builderObj->master_obj->id != MASTER_OBJECT_WONDER)
                this->deleteUnit(builderObj->id);
            return 0;
        }
    }

    ManagedArray<int>& arr = this->unitsTaskedThisUpdate;
    int i;
    for (i = 0; i < arr.numberValue; i++) {
        if (i >= arr.maximumSizeValue)
            break;
        if (arr.value[i] == builder)
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
    arr.value[arr.numberValue] = builder;
    arr.numberValue++;

found:
    float distance = builderObj->distance_to_object(obj);
    int priority = this->calculatePriority(distance);
    RGE_Player* player = this->md->player;
    player->sendUnitAIOrder(
        player->id, builder, UNIT_AI_ORDER_BUILD, builderObj->id, player->id, builderObj->world_x, builderObj->world_y,
        builderObj->world_z, 1.0f, 1, 1, priority
    );
    return 1;
}

int TribeTacticalAIModule::taskRepairer(int builder, RGE_Static_Object* building) {
    RGE_Static_Object* object = this->md->player->world->object(builder);
    if (object == 0) {
        return 0;
    }

    if (object->canPath(building->id, 1.0f, 0, 1, -1, -1) == 0) {
        return 0;
    }

    ManagedArray<int>& arr = this->unitsTaskedThisUpdate;
    int i;
    for (i = 0; i < arr.numberValue; i++) {
        if (i >= arr.maximumSizeValue)
            break;
        if (arr.value[i] == builder)
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

    arr.value[arr.numberValue] = builder;
    arr.numberValue++;

dispatch:
    float distance = building->distance_to_object(object);
    int priority = this->calculatePriority(distance);
    RGE_Player* player = this->md->player;
    player->sendUnitAIOrder(
        player->id, builder, UNIT_AI_ORDER_REPAIR, building->id, player->id, building->world_x, building->world_y,
        building->world_z, 1.0f, 1, 0, priority
    );
    return 1;
}

//! @bug The resource type here comes from cached unit data and can be -1 or stale.
//! gameIDOfResourceObject() indexes two arrays of 4 with no bound on that value.
//! A converted villager can carry stale data in, so the read goes out of bounds.
int TribeTacticalAIModule::taskGatherer(
    int id, int resourceType, int limitedTaskLimit, ulong startTime, int* triedTasking
) {
    RGE_Static_Object* unit = this->md->object(id);
    if (unit == 0)
        return 0;

    UnitData* oldGatherer = this->gatherer(id);
    if (oldGatherer != 0 && oldGatherer->data2 > oldGatherer->data3)
        resourceType = oldGatherer->data1;

    int resourceID = -1;
    float resourceX = 0.0f;
    float resourceY = 0.0f;
    int pathResourceID = 0;
    int exclusions[4];

    if (resourceType == -1) {
        int i;
        for (i = 0; i < 4; i++) {
            resourceType = this->neededResourceValue[i];
            if (triedTasking != 0 && triedTasking[resourceType] == 1)
                continue;

            pathResourceID = -1;
            resourceID = this->md->informationAI.gameIDOfResourceObject(
                resourceType, id, resourceX, resourceY, pathResourceID, exclusions, 0
            );
            if (resourceID != -1) {
                if (pathResourceID == -1) {
                    unit->canPath(resourceID, 1.0f, 0, 1, -1, -1);
                } else {
                    unit->canBidirectionPath(resourceID, pathResourceID, 1.0f, 0, 1, -1, -1);
                }
                break;
            }
        }
        if (resourceID == -1)
            return 0;
    } else {
        int exclusionCount = 0;
        do {
            pathResourceID = -1;
            resourceID = this->md->informationAI.gameIDOfResourceObject(
                resourceType, id, resourceX, resourceY, pathResourceID, exclusions, exclusionCount
            );
            if (resourceID == -1)
                return 0;

            int canPath;
            if (pathResourceID == -1) {
                canPath = unit->canPath(resourceID, 1.0f, 0, 1, -1, -1);
            } else {
                canPath = unit->canBidirectionPath(resourceID, pathResourceID, 1.0f, 0, 1, -1, -1);
            }
            if (canPath != 0)
                break;

            this->md->informationAI.setResourceObjectValid(resourceType, resourceID, resourceType == 0 ? 2 : 15);
            exclusions[exclusionCount] = resourceID;
            exclusionCount++;
            resourceID = -1;
        } while (exclusionCount < 3);

        if (resourceID < 0)
            return 0;
    }

    RGE_Static_Object* resource = this->md->object(resourceID);
    if (resource == 0)
        return 0;

    if (this->sn[0xCD] == 1) {
        if (resourceType == 0 && this->builtFirstGranary == 1) {
            if (this->builtFirstStoragePit == 1) {
                if (resource->master_obj->id == MASTER_OBJECT_FORAGE_FRUIT) {
                    int granaryCount = 0;
                    int unbuiltGranaries = 0;
                    int available = this->numberAvailableGranaries(granaryCount, unbuiltGranaries);
                    if (unbuiltGranaries == 0 && available > 0) {
                        int maximumDistance = this->sn[0xA3];
                        if ((int) unit->distance_to_object(resource) > maximumDistance
                            && this->md->informationAI.closestDropsiteValue[0] != -1
                            && this->md->informationAI.acceptablePotentialDropsiteArea(
                                   (int) resource->world_x, (int) resource->world_y
                               ) == 1) {
                            this->md->buildAI.insert(MASTER_OBJECT_GRANARY, 1, -1);
                        }
                    }
                } else if (resource->master_obj->object_group != 0x1F
                           && resource->master_obj->object_group != OBJECT_GROUP_FISH
                           && resource->master_obj->object_group != 0x21) {
                    int storagePitCount = 0;
                    int unbuiltStoragePits = 0;
                    int available = this->numberAvailableStoragePits(storagePitCount, unbuiltStoragePits, 0);
                    if (unbuiltStoragePits == 0 && available > 0
                        && ((int) unit->distance_to_object(resource) > 15 || storagePitCount == 0)) {
                        this->md->buildAI.insert(MASTER_OBJECT_STORAGE_PIT1, 1, -1);
                    }
                }
            }
        } else if (this->builtFirstStoragePit == 1 && this->builtFirstGranary == 1) {
            int storagePitCount = 0;
            int unbuiltStoragePits = 0;
            int available = this->numberAvailableStoragePits(storagePitCount, unbuiltStoragePits, resourceType);
            if (unbuiltStoragePits == 0 && available > 0) {
                int maximumDistance = this->sn[resource->attribute_type_held + 0xA3];
                if ((int) unit->distance_to_object(resource) > maximumDistance || storagePitCount == 0) {
                    this->md->buildAI.insert(MASTER_OBJECT_STORAGE_PIT1, 1, -1);
                }
            }
        }
    }

    this->civilianExplorers.remove(id);

    UnitData* gathererData = this->addGatherer(id);
    if (gathererData == 0)
        return 0;

    this->actualGathererDistribution[resourceType]++;
    this->unitsTaskedThisUpdate.add(id);
    gathererData->data1 = resourceType;

    int amount = this->requiredGatherAmount(resourceType);
    if (limitedTaskLimit == 1) {
        amount = 10;
    } else {
        if (this->sn[0xCB] == 1) {
            if (resource->master_obj->id == MASTER_OBJECT_FORAGE_FRUIT)
                amount = (int) resource->attribute_amount_held;
            else if (resourceType == 1)
                amount = 75;
            else if (resourceType == 3)
                amount = 50;
            else if (resourceType == 2)
                amount = 50;
        } else {
            if (amount < this->sn[0x94])
                amount = this->sn[0x94];
            else if (amount > this->sn[0x95])
                amount = this->sn[0x95];
        }

        if (this->zoomingToNextAge == 1)
            amount = 20;
    }

    gathererData->data2 = amount;
    gathererData->data3 = 0;

    this->md->aiPlayer->taskResourceGatherer(id, resourceID, (int) resource->owner->id, resourceX, resourceY);

    if (resource->master_obj->id == MASTER_OBJECT_ELEPHANT) {
        this->taskElephantGatherers(id, this->sn[0xCC] - 1, resourceID);
    }

    if (resource->master_obj->id == MASTER_OBJECT_FARM)
        this->md->informationAI.farmsTaskedThisUpdate.add(resource->id);

    return 1;
}

int TribeTacticalAIModule::taskExplorer(int eID, int civilian) {
    ManagedArray<int>& arr = this->unitsTaskedThisUpdate;
    int i;

    for (i = 0; i < arr.numberValue; i++) {
        if (i >= arr.maximumSizeValue)
            break;
        if (arr.value[i] == eID)
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

    arr.value[arr.numberValue] = eID;
    arr.numberValue++;

dispatch:
    if (civilian == 1) {
        XYPoint targetPoint;
        if (unexploredArea(eID, targetPoint) == 1) {
            return taskExplorer(eID, (float) targetPoint.x, (float) targetPoint.y, 1);
        }
        return taskExplorer(eID, -1.0f, -1.0f, 1);
    }

    return taskExplorer(eID, -1.0f, -1.0f, 0);
}

//
//   ManagedArray ownership and the neighboring taskExplorer overload's
//   only two FPU operand-displacement bytes differing.
//   right-to-left evaluation and the observed y-then-x FPU pushes.

int TribeTacticalAIModule::taskExplorer(int eID, float x, float y) {
    ManagedArray<int>& arr = this->unitsTaskedThisUpdate;
    int i;

    for (i = 0; i < arr.numberValue; i++) {
        if (i >= arr.maximumSizeValue)
            break;
        if (arr.value[i] == eID)
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

    arr.value[arr.numberValue] = eID;
    arr.numberValue++;

dispatch: {
    ManagedArray<int>& civiliansArray = civilians;
    int count = civiliansArray.numberValue;
    int j;
    for (j = 0; j < count; j++) {
        if (j >= civiliansArray.maximumSizeValue)
            break;
        if (civiliansArray.value[j] == eID) {
            XYPoint targetPoint;
            if (unexploredArea(eID, targetPoint) == 1) {
                return taskExplorer(eID, (float) targetPoint.x, (float) targetPoint.y, 1);
            }
            return taskExplorer(eID, x, y, 1);
        }
    }
}

    return taskExplorer(eID, x, y, 0);
}

int TribeTacticalAIModule::taskExplorer(int eID, float x, float y, int civilian) {
    int i = 0;
    int count = this->unitsTaskedThisUpdate.numberValue;
    for (; i < count; i++) {
        if (i >= this->unitsTaskedThisUpdate.maximumSizeValue)
            break;
        if (this->unitsTaskedThisUpdate.value[i] == eID)
            goto tasked_done;
    }
    if (count > this->unitsTaskedThisUpdate.maximumSizeValue - 1) {
        int newMax = count + 1;
        int* nv = (int*) ::operator new(newMax * 4);
        if (nv != 0) {
            i = 0;
            if (this->unitsTaskedThisUpdate.maximumSizeValue > 0) {
                while (1) {
                    if (i >= newMax)
                        break;
                    nv[i] = this->unitsTaskedThisUpdate.value[i];
                    i++;
                    if (i >= this->unitsTaskedThisUpdate.maximumSizeValue)
                        break;
                }
            }
            ::operator delete(this->unitsTaskedThisUpdate.value);
            this->unitsTaskedThisUpdate.value = nv;
            this->unitsTaskedThisUpdate.maximumSizeValue = newMax;
        }
    }
    this->unitsTaskedThisUpdate.value[this->unitsTaskedThisUpdate.numberValue] = eID;
    this->unitsTaskedThisUpdate.numberValue++;

tasked_done:
    if (civilian == 1) {
        i = 0;
        for (; i < this->civilianExplorers.numberValue; i++) {
            if (i >= this->civilianExplorers.maximumSizeValue)
                break;
            if (this->civilianExplorers.value[i] == eID)
                goto haveExplorer;
        }
        {
            ManagedArray<int>& civiliansArray = this->civilianExplorers;
            i = 0;
            count = civiliansArray.numberValue;
            for (; i < count; i++) {
                if (i >= civiliansArray.maximumSizeValue)
                    break;
                if (civiliansArray.value[i] == eID)
                    goto haveExplorer;
            }
            if (count > civiliansArray.maximumSizeValue - 1) {
                int newMax = count + 1;
                int* nv = (int*) ::operator new(newMax * 4);
                if (nv != 0) {
                    i = 0;
                    if (civiliansArray.maximumSizeValue > 0) {
                        while (1) {
                            if (i >= newMax)
                                break;
                            nv[i] = civiliansArray.value[i];
                            i++;
                            if (i >= civiliansArray.maximumSizeValue)
                                break;
                        }
                    }
                    ::operator delete(civiliansArray.value);
                    civiliansArray.value = nv;
                    civiliansArray.maximumSizeValue = newMax;
                }
            }
            civiliansArray.value[civiliansArray.numberValue] = eID;
            civiliansArray.numberValue++;
        }
    haveExplorer:
        this->removeGatherer(eID);
    }
    RGE_Player* player = this->md->player;
    player->sendUnitAIOrder((int) player->id, eID, UNIT_AI_ORDER_EXPLORE, -1, -1, x, y, -1.0f, 1.0f, 1, 0, 1);
    return 1;
}

int TribeTacticalAIModule::taskFollower(int uID, int tID, float range, int priority) {
    ManagedArray<int>& arr = this->unitsTaskedThisUpdate;
    int i;
    for (i = 0; i < arr.numberValue; i++) {
        if (i >= arr.maximumSizeValue)
            break;
        if (arr.value[i] == uID)
            goto done;
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

    arr.value[arr.numberValue] = uID;
    arr.numberValue++;

done: {
    RGE_Player* player = md->player;
    player->sendUnitAIOrder(player->id, uID, UNIT_AI_ORDER_FOLLOW, tID, -1, -1.0f, -1.0f, -1.0f, range, 1, 0, priority);
}
    return 1;
}

int TribeTacticalAIModule::taskDefender(int uID, int tID, float range, int priority) {
    ManagedArray<int>& arr = this->unitsTaskedThisUpdate;
    int i;

    for (i = 0; i < arr.numberValue; i++) {
        if (i >= arr.maximumSizeValue)
            break;
        if (arr.value[i] == uID)
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

    arr.value[arr.numberValue] = uID;
    arr.numberValue++;

dispatch:
    // Mission dispatch through the typed player order surface.
    {
        RGE_Player* player = this->md->player;
        player->sendUnitAIOrder(
            (int) player->id, uID, UNIT_AI_ORDER_DEFEND, tID, -1, -1.0f, -1.0f, -1.0f, range, 1, 0, priority
        );
    }

    return 1;
}

// ManagedArray<int> layout
int TribeTacticalAIModule::taskWaterExplorer(int explorer) {
    if (explorer == -1) {
        return 0;
    }

    ManagedArray<int>& arr = this->unitsTaskedThisUpdate;
    int i;
    for (i = 0; i < arr.numberValue; i++) {
        if (i >= arr.maximumSizeValue)
            break;
        if (arr.value[i] == explorer)
            goto done;
    }

    if (arr.numberValue > arr.maximumSizeValue - 1) {
        int newSize = arr.numberValue + 1;
        int* newArray = (int*) ::operator new(newSize * 4);
        if (newArray != 0) {
            int j;
            for (j = 0; j < arr.maximumSizeValue && j < newSize; j++) {
                newArray[j] = arr.value[j];
            }
            ::operator delete(arr.value);
            arr.value = newArray;
            arr.maximumSizeValue = newSize;
        }
    }

    arr.value[arr.numberValue] = explorer;
    arr.numberValue++;

done: {
    RGE_Player* player = md->player;
    player->sendUnitAIOrder(
        (int) player->id, explorer, UNIT_AI_ORDER_EXPLORE, -1, -1, -1.0f, -1.0f, -1.0f, 1.0f, 1, 0, 1
    );
}
    return 1;
}

// __thiscall, returns 0/1
//
//   owner/player, aiPlayer::taskResourceGatherer, and ManagedArray surfaces.
//   then the player is recorded and taskResourceGatherer is dispatched with
//   the target owner's id.

int TribeTacticalAIModule::taskWaterTrader(int unitID, int targetID) {
    RGE_Static_Object* object = this->md->object(unitID);
    if (unitID == -1 || object == 0) {
        return 0;
    }

    RGE_Static_Object* targetObj = this->md->object(targetID);
    if (targetObj == 0) {
        return 0;
    }

    XYZPoint point;
    point.x = (int) targetObj->world_x;
    point.y = (int) targetObj->world_y;
    point.z = (int) targetObj->world_z;
    if (object->canPath(point, 2.0f, targetID, 0, 1, -1, -1) == 0) {
        return 0;
    }

    ManagedArray<int>& arr = this->unitsTaskedThisUpdate;
    int i;
    for (i = 0; i < arr.numberValue; i++) {
        if (i >= arr.maximumSizeValue)
            break;
        if (arr.value[i] == unitID)
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

    arr.value[arr.numberValue] = unitID;
    arr.numberValue++;

dispatch:
    this->md->aiPlayer->taskResourceGatherer(
        unitID, targetID, (int) targetObj->owner->id, targetObj->world_x, targetObj->world_y
    );
    return 1;
}

int TribeTacticalAIModule::taskWaterFisher(int unitID, int targetID, float x, float y) {
    RGE_Static_Object* object = this->md->object(unitID);
    if (unitID == -1 || object == 0) {
        return 0;
    }

    XYZPoint point;
    point.x = (int) x;
    point.y = (int) y;
    point.z = 1;
    if (object->canPath(point, 1.0f, -1, 0, 1, -1, -1) == 0) {
        return 0;
    }

    ManagedArray<int>& arr = this->unitsTaskedThisUpdate;
    int i;
    for (i = 0; i < arr.numberValue; i++) {
        if (i >= arr.maximumSizeValue)
            break;
        if (arr.value[i] == unitID)
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

    arr.value[arr.numberValue] = unitID;
    arr.numberValue++;

dispatch:
    this->md->aiPlayer->taskResourceGatherer(unitID, targetID, 0, x, y);
    return 1;
}

int TribeTacticalAIModule::taskAttacker(
    int soldierID, float xLocation, float yLocation, int targetID, int targetOwner, Waypoint* path, int pathLength,
    int commanderID, int idleAttackRoundup
) {
    RGE_Static_Object* attacker;
    int priority;

    if (soldierID == -1) {
        return 0;
    }
    attacker = (RGE_Static_Object*) this->md->player->world->object(soldierID);
    if (attacker == 0 || attacker->unitAI() == 0) {
        return 0;
    }

    if (path != 0 && pathLength > 0) {
        do {
            this->addWaypoint(soldierID, (int) path->x, (int) path->y);
            ++path;
            --pathLength;
        } while (pathLength != 0);
    }

    if (targetID != -1) {
        RGE_Static_Object* target;
        target = (RGE_Static_Object*) this->md->player->world->object(targetID);
        if (target == 0) {
            return 0;
        }

        float distance = attacker->distance_to_object(target);
        priority = this->calculatePriority(distance);
        int command;
        if (idleAttackRoundup == 1)
            command = UNIT_AI_ORDER_ATTACK_ROUNDUP;
        else
            command = UNIT_AI_ORDER_ATTACK;

        this->md->player->sendUnitAIOrder(
            (int) this->md->player->id, soldierID, command, targetID, targetOwner, xLocation, yLocation, 1.0f,
            attacker->weaponRange(), 1, 0, priority
        );
    } else {
        float distance = attacker->distance_to_position(xLocation, yLocation, 1.0f);
        priority = this->calculatePriority(distance);
        this->moveUnit(soldierID, xLocation, yLocation, priority);
    }

    ManagedArray<int>& arr = this->unitsTaskedThisUpdate;
    int i;
    for (i = 0; i < arr.numberValue; i++) {
        if (i >= arr.maximumSizeValue)
            break;
        if (arr.value[i] == soldierID)
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

    arr.value[arr.numberValue] = soldierID;
    arr.numberValue++;
    return 1;
}

int TribeTacticalAIModule::taskDefender(int defender, int targetID) {
    this->logCommonHistory((char*) "ERROR: Unused taskDefender call 1: defender ID=%d group=%d\n", defender, targetID);
    return 0;
}

int TribeTacticalAIModule::taskDefender(int defender, float x, float y) {
    this->logCommonHistory(
        (char*) "ERROR: Unused taskDefender call 2: defender ID=%d to (%f, %f)\n", defender, (double) x, (double) y
    );
    return 0;
}

int TribeTacticalAIModule::taskTrain(BuildItem* trainItem) {
    int objectID;
    RGE_Static_Object* trainBuilding;
    ManagedArray<int>& arr = this->unitsTaskedThisUpdate;

    if (trainItem == 0) {
        this->logCommonHistory("Invalid taskTrain item, returning FALSE.");
        return 0;
    }

    trainBuilding = this->md->object(
        -1, trainItem->buildFrom(), -1, UNIT_AI_ACTION_TRAIN, UNIT_AI_ACTION_RESEARCH, RGE_OBJECT_STATE_ACTIVE
    );
    if (trainBuilding == 0 || trainBuilding->unitAI() == 0) {
        this->logCommonHistory(
            "Could not find a building to train type %d (UniqueID=%d) at, returning FALSE.", trainItem->typeID(),
            trainItem->uniqueID()
        );
        return 0;
    }

    this->logCommonHistory(
        "Training ID #%d (UniqueID=%d) from building with gameID=%d.", trainItem->typeID(), trainItem->uniqueID(),
        trainBuilding->id
    );
    trainItem->setInProgress(1);
    trainItem->setBuilt(0);

    objectID = trainBuilding->id;
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
    this->md->aiPlayer->trainUnit(trainItem->typeID(), trainBuilding->id, trainItem->uniqueID());
    return 1;
}

int TribeTacticalAIModule::taskResearch(BuildItem* researchItem) {
    int objectID;
    RGE_Static_Object* object;
    if (researchItem == 0) {
        this->logCommonHistory("Invalid taskResearch item, returning FALSE.");
        return 0;
    }

    object = this->md->object(
        -1, researchItem->buildFrom(), -1, UNIT_AI_ACTION_TRAIN, UNIT_AI_ACTION_RESEARCH, RGE_OBJECT_STATE_ACTIVE
    );
    if (object == 0 || object->unitAI() == 0) {
        this->logCommonHistory(
            "Could not find a building to research type %d with unique ID %d.", researchItem->typeID(),
            researchItem->uniqueID()
        );
        return 0;
    }

    this->logCommonHistory(
        "Researching ID #%d (UniqueID=%d) from building #%d.", researchItem->typeID(), researchItem->uniqueID(),
        object->id
    );
    researchItem->setInProgress(1);
    researchItem->setBuilt(0);

    objectID = object->id;

    this->unitsTaskedThisUpdate.add(objectID);
    this->md->aiPlayer->research(researchItem->typeID(), object->id, researchItem->uniqueID());
    return 1;
}

int TribeTacticalAIModule::taskToEnter(int unitID, int targetID) {
    ManagedArray<int>& arr = this->unitsTaskedThisUpdate;
    int i;

    if (unitID == -1)
        return 0;

    for (i = 0; i < arr.numberValue; i++) {
        if (i >= arr.maximumSizeValue)
            break;
        if (arr.value[i] == unitID)
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

    arr.value[arr.numberValue] = unitID;
    arr.numberValue++;

dispatch: {
    RGE_Player* player = md->player;
    player->sendUnitAIOrder(
        (int) player->id, unitID, UNIT_AI_ORDER_ENTER, targetID, (int) player->id, -1.0f, -1.0f, -1.0f, 1.0f, 1, 0, 100
    );
}

    return 1;
}

// __thiscall, int, ret 0Ch
//
//   MainDecision object lookup, distance/priority calls, this->unitsTaskedThisUpdate
//   ManagedArray growth, and typed player slot-0x30 dispatch.
//   RGE_Player slot-0x30 signature; generic proxy naming was removed.

int TribeTacticalAIModule::taskTransporter(int unitID, float x, float y) {
    RGE_Static_Object* object = this->md->object(unitID);
    if (unitID == -1 || object == 0) {
        return 0;
    }

    float distance = object->distance_to_position(x, y, 1.0f);
    int priority = this->calculatePriority(distance);

    ManagedArray<int>& arr = this->unitsTaskedThisUpdate;
    int i;
    for (i = 0; i < arr.numberValue; i++) {
        if (i >= arr.maximumSizeValue)
            break;
        if (arr.value[i] == unitID)
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

    arr.value[arr.numberValue] = unitID;
    arr.numberValue++;

dispatch:
    RGE_Player* player = this->md->player;
    player->sendUnitAIOrder(
        (int) player->id, unitID, UNIT_AI_ORDER_TRANSPORT, -1, (int) player->id, x, y, 1.0f, 1.0f, 1, 0, priority
    );
    return 1;
}

void TribeTacticalAIModule::removeFromTaskLists(int gID) {
    int i = 0;
    int count = this->civilianExplorers.maximumSizeValue;

    for (; i < count; ++i) {
        if (this->civilianExplorers.value[i] == gID)
            break;
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

    this->removeGatherer(gID);

    RGE_Static_Object* obj = this->md->object(gID);
    if (obj != NULL) {
        if (obj->unitAI() != NULL) {
            if (obj->unitAI()->currentAction() == UNIT_AI_ACTION_GATHER)
                goto check;
            if (obj->unitAI()->currentAction() != UNIT_AI_ACTION_HUNT)
                goto end;
        check:
            UnitData* g = this->gatherer(gID);
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

static inline int appendUniqueGroupID(ManagedArray<int>& array, int item) {
    int i;
    for (i = 0; i < array.numberValue; ++i) {
        if (i >= array.maximumSizeValue)
            break;
        if (array.value[i] == item)
            return 0;
    }
    if (array.numberValue > array.maximumSizeValue - 1) {
        int (ManagedArray<int>::*resize)(int) = &ManagedArray<int>::resize;
        (array.*resize)(array.numberValue + 1);
    }
    array.value[array.numberValue] = item;
    ++array.numberValue;
    return 1;
}

int TribeTacticalAIModule::calculatePriority(float distance) {
    int priority;

    priority = (int) ((float) this->sn[SNZeroPriorityDistance] / distance);
    if (priority > 99) {
        priority = 99;
    }
    return priority;
}

void TribeTacticalAIModule::setupSoldierGroups() {
    ManagedArray<int> groupsToRemove;
    TacticalAIGroup* sentinel = &this->groups;
    TacticalAIGroup* group = this->groups.next;

    while (group != sentinel && group != 0) {
        if (group->numberUnits() == 0) {
            appendUniqueGroupID(groupsToRemove, group->id());
        }
        group = group->next;
    }

    unsigned long now = this->md->player->world->world_time;
    unsigned long rebalanceElapsed = (now - this->lastGroupRebalanceTime) / 1000;
    unsigned long attackElapsed = (now - this->lastGroupAttackTime) / 1000;
    if (attackElapsed > 600 && rebalanceElapsed > 600) {
        this->lastGroupRebalanceTime = now;
        group = this->groups.next;
        while (group != sentinel && group != 0) {
            if (group->type() == TACTICAL_GROUP_TYPE_ATTACK) {
                appendUniqueGroupID(groupsToRemove, group->id());
            }
            group = group->next;
        }
    }

    int i = 0;
    while (i < groupsToRemove.numberValue) {
        this->removeGroup(groupsToRemove[i]);
        ++i;
    }

    //! @bug soldiers[0] is unguarded, and the list is empty at game start.
    //! The stale id selects a zone map, so save bytes vary between runs.
    if (this->md->informationAI.fullyExploredZone(this->soldiers[0]) == 0) {
        this->removeAllGroups(TACTICAL_GROUP_TYPE_EXPLORE);
        this->setStrategicNumber(SNNumberExploreGroups, 0);
    }

    int numAGroups = this->numberGroups(TACTICAL_GROUP_TYPE_ATTACK, -1);
    int numDGroups = this->numberGroups(TACTICAL_GROUP_TYPE_DEFEND, -1);
    int numEGroups = this->numberGroups(TACTICAL_GROUP_TYPE_EXPLORE, -1);
    this->numberGroups(TACTICAL_GROUP_TYPE_ARTIFACT, -1);

    this->numberUngroupedArtifacts();
    while (this->workingArea.numberValue > 0) {
        int artifactID = this->workingArea[i];
        RGE_Static_Object* artifact = this->md->object(artifactID);
        if (artifact == 0) {
            this->workingArea.remove(artifactID);
        } else {
            RGE_Static_Object* target =
                this->md->object(-1, MASTER_OBJECT_TOWN_CENTER1, -1, -1, -1, -1, -1, -1, RGE_OBJECT_STATE_ANY, -1);
            if (target == 0) {
                this->workingArea.remove(artifactID);
            } else {
                TacticalAIGroup* newGroup = this->createGroup(1);
                if (newGroup == 0) {
                    break;
                }
                newGroup->setType(TACTICAL_GROUP_TYPE_ARTIFACT);
                newGroup->setDesiredNumberUnits(1);
                newGroup->addUnit(artifactID, this->md);
                newGroup->setSpecificCommander(artifactID, this->md);
                newGroup->setLocation(artifact->world_x, artifact->world_y, artifact->world_z);
                newGroup->setGatherLocation(artifact->world_x, artifact->world_y, artifact->world_z);
                newGroup->setRetreatLocation(target->world_x, target->world_y, target->world_z);
                this->workingArea.remove(artifactID);
            }
        }
    }

    int numPotentialAGroups;
    int numPotentialDGroups = 0;
    int numPotentialEGroups = 0;
    int remaining;

    if (this->sn[SNGroupFillMethod] == 0) {
        numPotentialAGroups =
            (int) ceil((double) this->soldiers.numberValue / (double) this->sn[SNMinimumAttackGroupSize]);
        if (numPotentialAGroups > this->sn[SNNumberAttackGroups]) {
            numPotentialAGroups = this->sn[SNNumberAttackGroups];
        }
        int assigned = numPotentialAGroups * this->sn[SNMinimumAttackGroupSize];
        remaining = this->soldiers.numberValue - assigned;
        if (remaining > 0) {
            numPotentialDGroups = (int) ceil((double) remaining / (double) this->sn[SNMinimumDefendGroupSize]);
            if (numPotentialDGroups > this->sn[SNNumberDefendGroups]) {
                numPotentialDGroups = this->sn[SNNumberDefendGroups];
            }
            remaining =
                this->soldiers.numberValue - assigned - numPotentialDGroups * this->sn[SNMinimumDefendGroupSize];
            if (remaining > 0) {
                numPotentialEGroups = (int) ceil((double) remaining / (double) this->sn[SNMinimumExploreGroupSize]);
                if (numPotentialEGroups > this->sn[SNNumberExploreGroups]) {
                    numPotentialEGroups = this->sn[SNNumberExploreGroups];
                }
            }
        }
    } else {
        numPotentialAGroups = this->soldiers.numberValue;
        if (numPotentialAGroups >= this->sn[SNNumberAttackGroups]) {
            numPotentialAGroups = this->sn[SNNumberAttackGroups];
        }
        remaining = this->soldiers.numberValue - numPotentialAGroups;
        if (remaining > 0) {
            numPotentialDGroups = this->sn[SNNumberDefendGroups];
            if (remaining < numPotentialDGroups) {
                numPotentialDGroups = remaining;
            }
            remaining -= numPotentialDGroups;
            if (remaining > 0) {
                numPotentialEGroups = remaining;
                if (numPotentialEGroups >= this->sn[SNNumberExploreGroups]) {
                    numPotentialEGroups = this->sn[SNNumberExploreGroups];
                }
            }
        }
    }

    if (this->sn[0xa2] == 1) {
        numPotentialAGroups = 0;
    }

    for (; numAGroups < numPotentialAGroups; ++numAGroups) {
        TacticalAIGroup* newGroup = 0;
        if (numDGroups > 0) {
            newGroup = this->group(-1, TACTICAL_GROUP_TYPE_DEFEND, -1, -1);
            if (newGroup != 0) {
                --numDGroups;
            } else {
                newGroup = this->group(-1, TACTICAL_GROUP_TYPE_EXPLORE, -1, -1);
                if (newGroup != 0) {
                    --numEGroups;
                }
            }
        }
        if (newGroup == 0) {
            newGroup = this->createGroup(1);
            if (newGroup == 0) {
                break;
            }
        }
        newGroup->setType(TACTICAL_GROUP_TYPE_ATTACK);
        newGroup->setTarget(-1);
        newGroup->setTargetType(-1);
        newGroup->setAction(TACTICAL_GROUP_ACTION_IDLE);
        newGroup->setInUse(0);
        int desired =
            debug_rand(s_file, 9568) % (this->sn[SNAttackGroupSizeRandomness] + 1) + this->sn[SNMinimumAttackGroupSize];
        if (desired > this->sn[SNMaximumAttackGroupSize]) {
            desired = this->sn[SNMaximumAttackGroupSize];
        }
        newGroup->setDesiredNumberUnits(desired);
    }

    while (numAGroups > numPotentialAGroups) {
        TacticalAIGroup* oldGroup = this->group(-1, TACTICAL_GROUP_TYPE_ATTACK, TACTICAL_GROUP_ACTION_NONE, -1);
        if (oldGroup == 0) {
            oldGroup = this->group(-1, TACTICAL_GROUP_TYPE_ATTACK, TACTICAL_GROUP_ACTION_IDLE, -1);
        }
        if (oldGroup == 0) {
            break;
        }
        this->removeGroup(oldGroup->id());
        --numAGroups;
    }

    for (; numDGroups < numPotentialDGroups; ++numDGroups) {
        TacticalAIGroup* newGroup = 0;
        if (numEGroups > 0) {
            newGroup = this->group(-1, TACTICAL_GROUP_TYPE_EXPLORE, -1, -1);
            if (newGroup != 0) {
                --numEGroups;
            }
        }
        if (newGroup == 0) {
            newGroup = this->createGroup(1);
            if (newGroup == 0) {
                break;
            }
        }
        newGroup->setType(TACTICAL_GROUP_TYPE_DEFEND);
        newGroup->setTarget(-1);
        newGroup->setTargetType(-1);
        newGroup->setAction(TACTICAL_GROUP_ACTION_IDLE);
        newGroup->setInUse(0);
        newGroup->setDesiredNumberUnits(this->sn[SNMinimumDefendGroupSize]);
    }

    while (numDGroups > numPotentialDGroups) {
        TacticalAIGroup* oldGroup = this->group(-1, TACTICAL_GROUP_TYPE_DEFEND, -1, -1);
        if (oldGroup == 0) {
            break;
        }
        this->removeGroup(oldGroup->id());
        --numDGroups;
    }

    while (numEGroups < numPotentialEGroups) {
        TacticalAIGroup* newGroup = this->createGroup(1);
        if (newGroup == 0) {
            break;
        }
        newGroup->setType(TACTICAL_GROUP_TYPE_EXPLORE);
        newGroup->setDesiredNumberUnits(this->sn[SNMinimumExploreGroupSize]);
        ++numEGroups;
    }

    while (numEGroups > numPotentialEGroups) {
        TacticalAIGroup* oldGroup = this->group(-1, TACTICAL_GROUP_TYPE_EXPLORE, -1, -1);
        if (oldGroup == 0) {
            break;
        }
        this->removeGroup(oldGroup->id());
        --numEGroups;
    }
}

extern void* operator new(unsigned int);
extern void operator delete(void*);

void TribeTacticalAIModule::fillSoldierGroups() {
    int bestUnit;
    TacticalAIGroup* bestGroup;

    this->numberUngroupedSoldiers();
    this->numberExtraGroupedSoldiers();

    TacticalAIGroup* group = this->groups.next;
    while (group != &this->groups && group != 0) {
        if ((group->type() == TACTICAL_GROUP_TYPE_ATTACK || group->type() == TACTICAL_GROUP_TYPE_DEFEND
             || group->type() == TACTICAL_GROUP_TYPE_EXPLORE)
            && group->commander() == -1) {
            int ungrouped = this->numberUngroupedSoldiers();
            if (group->numberUnits() > 0) {
                int commander = this->selectBestCommander(group);
                group->setSpecificCommander(commander, this->md);
                if (group->action() == TACTICAL_GROUP_ACTION_NONE || group->action() == TACTICAL_GROUP_ACTION_IDLE)
                    this->setAllGroupLocations(group);
            } else {
                if (ungrouped == 0)
                    this->numberExtraGroupedSoldiers();
                if (this->workingArea.numberValue == 0)
                    return;
                int commander = this->selectBestCommander(this->workingArea);
                group->addUnit(commander, this->md);
                group->setSpecificCommander(commander, this->md);
                if (group->action() == TACTICAL_GROUP_ACTION_NONE || group->action() == TACTICAL_GROUP_ACTION_IDLE)
                    this->setAllGroupLocations(group);
            }
        }
        group = group->next;
    }

    if (this->sn[SNGroupFillMethod] == 0) {
        bestUnit = TACTICAL_GROUP_TYPE_ATTACK;
        do {
            bestGroup = this->groups.next;
            while (bestGroup != &this->groups && bestGroup != 0) {
                if (bestGroup->type() == bestUnit) {
                    int desired = bestGroup->desiredNumberUnits();
                    int number = bestGroup->numberUnits();
                    if (number < desired) {
                        if (bestGroup->inUse() == 1) {
                            bestGroup = bestGroup->next;
                            continue;
                        }

                        int groupZone = -1;
                        RGE_Static_Object* commander = this->md->object(bestGroup->commander());
                        if (commander != 0)
                            groupZone = commander->currentZone();

                        int ungrouped = this->numberUngroupedSoldiers();
                        desired = bestGroup->desiredNumberUnits();
                        number = bestGroup->numberUnits();
                        int missing = desired - number;

                        if (ungrouped <= missing) {
                            int i = 0;
                            if (this->workingArea.numberValue > 0) {
                                do {
                                    RGE_Static_Object* object = this->md->object(this->workingArea[i]);
                                    if (object != 0 && groupZone == object->currentZone()) {
                                        bestGroup->addUnit(this->workingArea[i], this->md);
                                    }
                                    ++i;
                                } while (i < this->workingArea.numberValue);
                            }
                        } else {
                            desired = bestGroup->desiredNumberUnits();
                            number = bestGroup->numberUnits();
                            if (number < desired) {
                                do {
                                    int i = 0;
                                    int bestUnitID = -1;
                                    float bestDistance = -1.0f;
                                    if (this->workingArea.numberValue > 0) {
                                        do {
                                            RGE_Static_Object* object = this->md->object(this->workingArea[i]);
                                            if (object != 0 && groupZone == object->currentZone()) {
                                                float distance = object->distance_to_position(
                                                    bestGroup->gatherLocation().x, bestGroup->gatherLocation().y,
                                                    bestGroup->gatherLocation().z
                                                );
                                                if (bestDistance == -1.0f || distance < bestDistance) {
                                                    bestUnitID = this->workingArea[i];
                                                    bestDistance = distance;
                                                }
                                            }
                                            ++i;
                                        } while (i < this->workingArea.numberValue);
                                    }
                                    if (bestUnitID == -1)
                                        break;
                                    bestGroup->addUnit(bestUnitID, this->md);
                                    this->workingArea.remove(bestUnitID);
                                    desired = bestGroup->desiredNumberUnits();
                                    number = bestGroup->numberUnits();
                                } while (number < desired);
                            }
                        }

                        desired = bestGroup->desiredNumberUnits();
                        number = bestGroup->numberUnits();
                        if (number < desired) {
                            int extra = this->numberExtraGroupedSoldiers();
                            desired = bestGroup->desiredNumberUnits();
                            number = bestGroup->numberUnits();
                            missing = desired - number;

                            if (extra <= missing) {
                                int i = 0;
                                if (this->workingArea.numberValue > 0) {
                                    do {
                                        RGE_Static_Object* object = this->md->object(this->workingArea[i]);
                                        if (object != 0 && groupZone == object->currentZone()) {
                                            this->removeFromGroup(this->workingArea[i]);
                                            bestGroup->addUnit(this->workingArea[i], this->md);
                                        }
                                        ++i;
                                    } while (i < this->workingArea.numberValue);
                                }
                            } else {
                                desired = bestGroup->desiredNumberUnits();
                                number = bestGroup->numberUnits();
                                if (number < desired) {
                                    do {
                                        int i = 0;
                                        int bestUnitID = -1;
                                        float bestDistance = -1.0f;
                                        if (this->workingArea.numberValue > 0) {
                                            do {
                                                RGE_Static_Object* object = this->md->object(this->workingArea[i]);
                                                if (object != 0 && groupZone == object->currentZone()) {
                                                    float distance = object->distance_to_position(
                                                        bestGroup->gatherLocation().x, bestGroup->gatherLocation().y,
                                                        bestGroup->gatherLocation().z
                                                    );
                                                    if (bestDistance == -1.0f || distance < bestDistance) {
                                                        bestUnitID = this->workingArea[i];
                                                        bestDistance = distance;
                                                    }
                                                }
                                                ++i;
                                            } while (i < this->workingArea.numberValue);
                                        }
                                        if (bestUnitID == -1)
                                            break;
                                        this->removeFromGroup(bestUnitID);
                                        bestGroup->addUnit(bestUnitID, this->md);
                                        this->workingArea.remove(bestUnitID);
                                        desired = bestGroup->desiredNumberUnits();
                                        number = bestGroup->numberUnits();
                                    } while (number < desired);
                                }
                            }
                        }
                    }
                }
                bestGroup = bestGroup->next;
            }
            ++bestUnit;
        } while (bestUnit <= TACTICAL_GROUP_TYPE_EXPLORE);
    }

    if (this->numberUngroupedSoldiers() == 0)
        return;
    if (this->workingArea.numberValue <= 0)
        return;

    int i = 0;
    do {
        RGE_Static_Object* object = this->md->object(this->workingArea[i]);
        if (object != 0) {
            unsigned char unitZone = object->currentZone();
            int bestDifference = 0;
            bestGroup = 0;
            group = this->groups.next;

            while (group != &this->groups && group != 0) {
                if ((group->type() == TACTICAL_GROUP_TYPE_ATTACK || group->type() == TACTICAL_GROUP_TYPE_DEFEND
                     || group->type() == TACTICAL_GROUP_TYPE_EXPLORE)
                    && group->inUse() != 1) {
                    RGE_Static_Object* groupCommander = this->md->object(group->commander());
                    if (groupCommander != 0 && groupCommander->currentZone() == unitZone) {
                        int desired = group->desiredNumberUnits();
                        int number = group->numberUnits();
                        if (number < desired
                            && (group->action() == TACTICAL_GROUP_ACTION_IDLE
                                || group->action() == TACTICAL_GROUP_ACTION_NONE)) {
                            desired = group->desiredNumberUnits();
                            number = group->numberUnits();
                            int difference = desired - number;
                            if (bestGroup == 0 || difference > bestDifference) {
                                bestGroup = group;
                                bestDifference = difference;
                            }
                        }
                    }
                }
                group = group->next;
            }

            if (bestGroup == 0) {
                group = this->groups.next;
                bestDifference = 0;
                while (group != &this->groups && group != 0) {
                    if ((group->type() == TACTICAL_GROUP_TYPE_ATTACK || group->type() == TACTICAL_GROUP_TYPE_DEFEND
                         || group->type() == TACTICAL_GROUP_TYPE_EXPLORE)
                        && group->inUse() != 1
                        && (group->action() == TACTICAL_GROUP_ACTION_IDLE
                            || group->action() == TACTICAL_GROUP_ACTION_NONE)
                        && (group->type() != TACTICAL_GROUP_TYPE_ATTACK
                            || group->numberUnits() < this->sn[SNMaximumAttackGroupSize])
                        && (group->type() != TACTICAL_GROUP_TYPE_DEFEND
                            || group->numberUnits() < this->sn[SNMaximumDefendGroupSize])
                        && (group->type() != TACTICAL_GROUP_TYPE_EXPLORE
                            || group->numberUnits() < this->sn[SNMaximumExploreGroupSize])) {
                        RGE_Static_Object* groupCommander = this->md->object(group->commander());
                        if (groupCommander != 0 && groupCommander->currentZone() == unitZone) {
                            int desired = group->desiredNumberUnits();
                            int number = group->numberUnits();
                            int difference = number - desired;
                            if (bestGroup == 0 || difference < bestDifference) {
                                bestGroup = group;
                                bestDifference = difference;
                            }
                        }
                    }
                    group = group->next;
                }
                if (bestGroup == 0)
                    return;
            }

            bestGroup->addUnit(this->workingArea[i], this->md);
        }
        ++i;
    } while (i < this->workingArea.numberValue);
}

int TribeTacticalAIModule::numberUngroupedSoldiers() {
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

int TribeTacticalAIModule::numberExtraGroupedSoldiers() {
    int result = 0;
    ManagedArray<int>& workingArea = this->workingArea;
    TacticalAIGroup* group;

    workingArea.numberValue = 0;
    group = this->groups.next;
    while (group != &this->groups) {
        if (group == 0)
            return result;

        if ((group->type() == TACTICAL_GROUP_TYPE_ATTACK || group->type() == TACTICAL_GROUP_TYPE_DEFEND
             || group->type() == TACTICAL_GROUP_TYPE_EXPLORE)
            && (group->action() == TACTICAL_GROUP_ACTION_IDLE || group->action() == TACTICAL_GROUP_ACTION_NONE)) {
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

int TribeTacticalAIModule::numberUngroupedArtifacts() {
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

void TribeTacticalAIModule::displaySoldierGroups() {
    RGE_Static_Object* object;

    this->logCommonHistory("Soldier Groups:");
    TacticalAIGroup* g = this->groups.next;
    while (g != &this->groups) {
        if (!g)
            return;
        if (g->type() == TACTICAL_GROUP_TYPE_ATTACK || g->type() == TACTICAL_GROUP_TYPE_DEFEND
            || g->type() == TACTICAL_GROUP_TYPE_EXPLORE || g->type() == TACTICAL_GROUP_TYPE_ARTIFACT) {
            if (g->type() == TACTICAL_GROUP_TYPE_ATTACK)
                this->logCommonHistory("  Group ID#%d:  Attack Group (Type=%d).", g->id(), g->type());
            else if (g->type() == TACTICAL_GROUP_TYPE_DEFEND)
                this->logCommonHistory("  Group ID#%d:  Defend Group (Type=%d).", g->id(), g->type());
            else if (g->type() == TACTICAL_GROUP_TYPE_EXPLORE)
                this->logCommonHistory("  Group ID#%d:  Explore Group (Type=%d).", g->id(), g->type());
            else if (g->type() == TACTICAL_GROUP_TYPE_ARTIFACT)
                this->logCommonHistory("  Group ID#%d:  Artifact Group (Type=%d).", g->id(), g->type());

            this->logCommonHistory(
                "    NumUnits=%d, DesNumUnits=%d, OrgNumUnits=%d, Action=%d, inUse=%d.", g->numberUnits(),
                g->desiredNumberUnits(), g->originalUnitNumber(), g->action(), g->inUse()
            );
            object = this->md->object(g->target());
            if (object) {
                this->logCommonHistory(
                    "    Target=%d (%s), CommanderID=%d, HP(%d/%d), WaitCode=%d.", g->target(),
                    object->master_obj->name, g->commander(), g->currentHitPoints(this->md), g->originalHitPoints(),
                    g->waitCode()
                );
            } else {
                this->logCommonHistory(
                    "    Target=%d, CommanderID=%d, HP(%d/%d), WaitCode=%d.", g->target(), g->commander(),
                    g->currentHitPoints(this->md), g->originalHitPoints(), g->waitCode()
                );
            }
            this->logCommonHistory(
                "    AssistGroupID=%d, AssistGroupType=%d, ConsecIdleCount=%ld.", g->assistGroupID(),
                g->assistGroupType(), g->consecutiveIdleUnitCount()
            );
            this->logCommonHistory("    Location=(%f, %f).", g->location().x, g->location().y);
            this->logCommonHistory("    Gather Location=(%f, %f).", g->gatherLocation().x, g->gatherLocation().y);
            this->logCommonHistory("    Retreat Location=(%f, %f).", g->retreatLocation().x, g->retreatLocation().y);
            this->logCommonHistory("    Target Location=(%f, %f).", g->targetLocation().x, g->targetLocation().y);
            this->logCommonHistory("    Play=%d.", g->playNumberValue);
            this->logCommonHistory("    NumberObjectsToDestroy=%d.", g->numberObjectsToDestroyValue);
            if (g->numberObjectsToDestroyValue > 0) {
                for (int i = 0; i < g->numberObjectsToDestroyValue; ++i) {
                    object = this->md->object(g->objectToDestroy(i));
                    if (!object)
                        this->logCommonHistory(
                            "      ObjectToDestroy #%d:  Unit #%d, but it's gone.", i, g->objectToDestroy(i)
                        );
                    else
                        this->logCommonHistory(
                            "      ObjectToDestroy #%d:  Unit #%d (%s).", i, g->objectToDestroy(i),
                            object->master_obj->name
                        );
                }
            }
            for (int i = 0; i < g->numberUnits(); ++i) {
                object = this->md->object(g->unit(i));
                if (!object) {
                    this->logCommonHistory("    Unit %d is invalid.");
                } else if (!object->unitAI()) {
                    this->logCommonHistory("    Unit %d has invalid unitAI.");
                } else {
                    this->logCommonHistory(
                        "    Unit %d (%s): state=%d, action=%d, target=%d, order=%d, pri=%d, loc=(%3f, %3f), tLoc=(%3f, %3f).",
                        g->unit(i), object->master_obj->name, object->object_state, object->unitAI()->currentAction(),
                        object->unitAI()->currentTarget(), object->unitAI()->currentOrder(),
                        object->unitAI()->currentOrderPriority(), object->world_x, object->world_y,
                        object->unitAI()->currentTargetX(), object->unitAI()->currentTargetY()
                    );
                    if (object->unitAI()->currentTarget() != -1) {
                        object = this->md->object(object->unitAI()->currentTarget());
                        if (object)
                            this->logCommonHistory(
                                "      Target: %s, Owner=%d.", object->master_obj->name, object->owner->id
                            );
                    }
                }
            }
            if (!g->numberAttackWaypoints()) {
                this->logCommonHistory("    No waypoints.");
            } else {
                this->logCommonHistory("    Waypoints:");
                for (int i = 0; i < (int) (unsigned int) g->numberAttackWaypoints(); ++i) {
                    this->logCommonHistory("      (%f, %f).", g->attackWaypoint(i)->x, g->attackWaypoint(i)->y);
                }
                this->logCommonHistory("    Current waypoints=%d.", (unsigned int) g->currentAttackWaypoint());
            }
        }
        g = g->next;
    }
}

void TribeTacticalAIModule::setupBoatGroups() {
    ManagedArray<int> groupsToRemove;
    int i;
    int numPotentialAGroups;
    int numPotentialDGroups;
    int numPotentialEGroups;
    int numAGroups;
    int numDGroups;
    int numEGroups;
    int remainder;
    TacticalAIGroup* group;

    group = this->groups.next;
    while (group != &this->groups && group != 0) {
        if ((group->type() == TACTICAL_GROUP_TYPE_BOAT_ATTACK || group->type() == TACTICAL_GROUP_TYPE_BOAT_DEFEND
             || group->type() == TACTICAL_GROUP_TYPE_BOAT_EXPLORE)
            && group->numberUnits() == 0) {
            appendUniqueGroupID(groupsToRemove, group->id());
        }
        group = group->next;
    }

    i = 0;
    while (i < groupsToRemove.numberValue) {
        this->removeGroup(groupsToRemove[i]);
        ++i;
    }

    numAGroups = this->numberGroups(TACTICAL_GROUP_TYPE_BOAT_ATTACK, -1);
    numDGroups = this->numberGroups(TACTICAL_GROUP_TYPE_BOAT_DEFEND, -1);
    numEGroups = this->numberGroups(TACTICAL_GROUP_TYPE_BOAT_EXPLORE, -1);
    this->numberGroups(TACTICAL_GROUP_TYPE_FISHING, -1);
    this->numberGroups(TACTICAL_GROUP_TYPE_TRADE, -1);
    this->numberGroups(TACTICAL_GROUP_TYPE_TRANSPORT, -1);

    this->numberUngroupedFishingBoats();
    while (this->workingArea.numberValue > 0) {
        int objectID = this->workingArea[i];
        RGE_Static_Object* object = this->md->object(objectID);
        if (object == 0) {
            this->workingArea.remove(objectID);
        } else {
            TacticalAIGroup* newGroup = this->createGroup(1);
            if (newGroup == 0) {
                break;
            }
            newGroup->setType(TACTICAL_GROUP_TYPE_FISHING);
            newGroup->setDesiredNumberUnits(this->sn[SNDesiredNumberFishEscorts] + 1);
            newGroup->addUnit(objectID, this->md);
            newGroup->setSpecificCommander(objectID, this->md);
            newGroup->setLocation(object->world_x, object->world_y, object->world_z);
            newGroup->setGatherLocation(object->world_x, object->world_y, object->world_z);
            newGroup->setRetreatLocation(object->world_x, object->world_y, object->world_z);
            this->workingArea.remove(objectID);
        }
    }

    this->numberUngroupedTradeBoats();
    while (this->workingArea.numberValue > 0) {
        int objectID = this->workingArea[i];
        RGE_Static_Object* object = this->md->object(objectID);
        if (object == 0) {
            this->workingArea.remove(objectID);
        } else {
            TacticalAIGroup* newGroup = this->createGroup(1);
            if (newGroup == 0) {
                break;
            }
            newGroup->setType(TACTICAL_GROUP_TYPE_TRADE);
            newGroup->setDesiredNumberUnits(this->sn[SNDesiredNumberTradeEscorts] + 1);
            newGroup->addUnit(objectID, this->md);
            newGroup->setSpecificCommander(objectID, this->md);
            newGroup->setLocation(object->world_x, object->world_y, object->world_z);
            newGroup->setGatherLocation(object->world_x, object->world_y, object->world_z);
            newGroup->setRetreatLocation(object->world_x, object->world_y, object->world_z);
            this->workingArea.remove(objectID);
        }
    }

    this->numberUngroupedTransportBoats();
    while (this->workingArea.numberValue > 0) {
        int objectID = this->workingArea[i];
        RGE_Static_Object* object = this->md->object(objectID);
        if (object == 0) {
            this->workingArea.remove(objectID);
        } else {
            TacticalAIGroup* newGroup = this->createGroup(1);
            if (newGroup == 0) {
                break;
            }
            newGroup->setType(TACTICAL_GROUP_TYPE_TRANSPORT);
            newGroup->setDesiredNumberUnits(this->sn[SNDesiredNumberTransportEscorts] + 1);
            newGroup->addUnit(objectID, this->md);
            newGroup->setSpecificCommander(objectID, this->md);
            newGroup->setLocation(object->world_x, object->world_y, object->world_z);
            newGroup->setGatherLocation(object->world_x, object->world_y, object->world_z);
            newGroup->setRetreatLocation(object->world_x, object->world_y, object->world_z);
            this->workingArea.remove(objectID);
        }
    }

    if (this->md->informationAI.fullyExploredZone(this->boats[0]) == 0) {
        this->removeAllGroups(TACTICAL_GROUP_TYPE_BOAT_EXPLORE);
        this->setStrategicNumber(SNNumberBoatExploreGroups, 0);
    }

    numPotentialDGroups = 0;
    numPotentialEGroups = 0;
    if (this->sn[SNGroupFillMethod] == 0) {
        numPotentialAGroups =
            (int) ceil((double) this->warBoats.numberValue / (double) this->sn[SNMinimumBoatAttackGroupSize]);
        if (numPotentialAGroups > this->sn[SNNumberBoatAttackGroups]) {
            numPotentialAGroups = this->sn[SNNumberBoatAttackGroups];
        }
        int attackUnits = numPotentialAGroups * this->sn[SNMinimumBoatAttackGroupSize];
        remainder = this->warBoats.numberValue - attackUnits;
        if (remainder > 0) {
            numPotentialDGroups = (int) ceil((double) remainder / (double) this->sn[SNMinimumBoatDefendGroupSize]);
            if (numPotentialDGroups > this->sn[SNNumberBoatDefendGroups]) {
                numPotentialDGroups = this->sn[SNNumberBoatDefendGroups];
            }
            remainder =
                this->warBoats.numberValue - attackUnits - numPotentialDGroups * this->sn[SNMinimumBoatDefendGroupSize];
            if (remainder > 0) {
                numPotentialEGroups = (int) ceil((double) remainder / (double) this->sn[SNMinimumBoatExploreGroupSize]);
                if (numPotentialEGroups > this->sn[SNNumberBoatExploreGroups]) {
                    numPotentialEGroups = this->sn[SNNumberBoatExploreGroups];
                }
            }
        }
    } else {
        numPotentialAGroups = this->warBoats.numberValue;
        if (numPotentialAGroups >= this->sn[SNNumberBoatAttackGroups]) {
            numPotentialAGroups = this->sn[SNNumberBoatAttackGroups];
        }
        remainder = this->warBoats.numberValue - numPotentialAGroups;
        if (remainder > 0) {
            numPotentialDGroups = this->sn[SNNumberBoatDefendGroups];
            if (remainder < numPotentialDGroups) {
                numPotentialDGroups = remainder;
            }
            remainder -= numPotentialDGroups;
            if (remainder > 0) {
                numPotentialEGroups = remainder;
                if (remainder >= this->sn[SNNumberBoatExploreGroups]) {
                    numPotentialEGroups = this->sn[SNNumberBoatExploreGroups];
                }
            }
        }
    }

    for (; numAGroups < numPotentialAGroups; ++numAGroups) {
        TacticalAIGroup* newGroup = 0;
        if (numDGroups > 0) {
            newGroup = this->group(-1, TACTICAL_GROUP_TYPE_BOAT_DEFEND, -1, -1);
            if (newGroup != 0) {
                --numDGroups;
            } else {
                newGroup = this->group(-1, TACTICAL_GROUP_TYPE_BOAT_EXPLORE, -1, -1);
                if (newGroup != 0) {
                    --numEGroups;
                }
            }
        }
        if (newGroup == 0) {
            newGroup = this->createGroup(1);
            if (newGroup == 0) {
                break;
            }
        }
        newGroup->setType(TACTICAL_GROUP_TYPE_BOAT_ATTACK);
        newGroup->setTarget(-1);
        newGroup->setTargetType(-1);
        newGroup->setAction(TACTICAL_GROUP_ACTION_IDLE);
        newGroup->setInUse(0);
        newGroup->setDesiredNumberUnits(this->sn[SNMinimumBoatAttackGroupSize]);
    }

    while (numAGroups > numPotentialAGroups) {
        TacticalAIGroup* oldGroup = this->group(-1, TACTICAL_GROUP_TYPE_BOAT_ATTACK, TACTICAL_GROUP_ACTION_NONE, -1);
        if (oldGroup == 0) {
            oldGroup = this->group(-1, TACTICAL_GROUP_TYPE_BOAT_ATTACK, TACTICAL_GROUP_ACTION_IDLE, -1);
        }
        if (oldGroup == 0) {
            break;
        }
        this->removeGroup(oldGroup->id());
        --numAGroups;
    }

    for (; numDGroups < numPotentialDGroups; ++numDGroups) {
        TacticalAIGroup* newGroup = 0;
        if (numEGroups > 0) {
            newGroup = this->group(-1, TACTICAL_GROUP_TYPE_BOAT_EXPLORE, -1, -1);
            if (newGroup != 0) {
                --numEGroups;
            }
        }
        if (newGroup == 0) {
            newGroup = this->createGroup(1);
            if (newGroup == 0) {
                break;
            }
        }
        newGroup->setType(TACTICAL_GROUP_TYPE_BOAT_DEFEND);
        newGroup->setTarget(-1);
        newGroup->setTargetType(-1);
        newGroup->setAction(TACTICAL_GROUP_ACTION_IDLE);
        newGroup->setInUse(0);
        newGroup->setDesiredNumberUnits(this->sn[SNMinimumBoatDefendGroupSize]);
    }

    while (numDGroups > numPotentialDGroups) {
        TacticalAIGroup* oldGroup = this->group(-1, TACTICAL_GROUP_TYPE_BOAT_DEFEND, -1, -1);
        if (oldGroup == 0) {
            break;
        }
        this->removeGroup(oldGroup->id());
        --numDGroups;
    }

    for (; numEGroups < numPotentialEGroups; ++numEGroups) {
        TacticalAIGroup* newGroup = this->createGroup(1);
        if (newGroup == 0) {
            break;
        }
        newGroup->setType(TACTICAL_GROUP_TYPE_BOAT_EXPLORE);
        newGroup->setDesiredNumberUnits(this->sn[SNMinimumBoatExploreGroupSize]);
    }

    while (numEGroups > numPotentialEGroups) {
        TacticalAIGroup* oldGroup = this->group(-1, TACTICAL_GROUP_TYPE_BOAT_EXPLORE, -1, -1);
        if (oldGroup == 0) {
            break;
        }
        this->removeGroup(oldGroup->id());
        --numEGroups;
    }
}

void TribeTacticalAIModule::fillBoatGroups() {
    int bestUnit;
    TacticalAIGroup* bestGroup;

    this->numberUngroupedWarBoats();
    this->numberExtraGroupedWarBoats();

    TacticalAIGroup* group = this->groups.next;
    while (group != &this->groups && group != 0) {
        if ((group->type() == TACTICAL_GROUP_TYPE_BOAT_ATTACK || group->type() == TACTICAL_GROUP_TYPE_BOAT_DEFEND
             || group->type() == TACTICAL_GROUP_TYPE_BOAT_EXPLORE)
            && group->commander() == -1) {
            int ungrouped = this->numberUngroupedWarBoats();
            if (group->numberUnits() > 0) {
                int commander = this->selectBestCommander(group);
                group->setSpecificCommander(commander, this->md);
                if (group->action() == TACTICAL_GROUP_ACTION_NONE || group->action() == TACTICAL_GROUP_ACTION_IDLE)
                    this->setAllGroupLocations(group);
            } else {
                if (ungrouped == 0)
                    this->numberExtraGroupedWarBoats();
                if (this->workingArea.numberValue == 0)
                    return;
                int commander = this->selectBestCommander(this->workingArea);
                group->addUnit(commander, this->md);
                group->setSpecificCommander(commander, this->md);
                if (group->action() == TACTICAL_GROUP_ACTION_NONE || group->action() == TACTICAL_GROUP_ACTION_IDLE)
                    this->setAllGroupLocations(group);
            }
        }
        group = group->next;
    }

    if (this->sn[SNGroupFillMethod] == 0) {
        bestUnit = TACTICAL_GROUP_TYPE_BOAT_ATTACK;
        do {
            bestGroup = this->groups.next;
            while (bestGroup != &this->groups && bestGroup != 0) {
                if (bestGroup->type() == bestUnit) {
                    int desired = bestGroup->desiredNumberUnits();
                    int number = bestGroup->numberUnits();
                    if (number < desired) {
                        int ungrouped = this->numberUngroupedWarBoats();
                        desired = bestGroup->desiredNumberUnits();
                        number = bestGroup->numberUnits();
                        int missing = desired - number;

                        if (ungrouped <= missing) {
                            int i = 0;
                            if (this->workingArea.numberValue > 0) {
                                do {
                                    bestGroup->addUnit(this->workingArea[i], this->md);
                                    ++i;
                                } while (i < this->workingArea.numberValue);
                            }
                        } else {
                            desired = bestGroup->desiredNumberUnits();
                            number = bestGroup->numberUnits();
                            if (number < desired) {
                                do {
                                    int i = 0;
                                    int bestUnitID = -1;
                                    float bestDistance = -1.0f;
                                    if (this->workingArea.numberValue > 0) {
                                        do {
                                            RGE_Static_Object* object = this->md->object(this->workingArea[i]);
                                            if (object != 0) {
                                                float distance = object->distance_to_position(
                                                    bestGroup->gatherLocation().x, bestGroup->gatherLocation().y,
                                                    bestGroup->gatherLocation().z
                                                );
                                                if (bestDistance == -1.0f || distance < bestDistance) {
                                                    bestUnitID = this->workingArea[i];
                                                    bestDistance = distance;
                                                }
                                            }
                                            ++i;
                                        } while (i < this->workingArea.numberValue);
                                    }
                                    if (bestUnitID == -1)
                                        break;
                                    bestGroup->addUnit(bestUnitID, this->md);
                                    this->workingArea.remove(bestUnitID);
                                    desired = bestGroup->desiredNumberUnits();
                                    number = bestGroup->numberUnits();
                                } while (number < desired);
                            }
                        }

                        desired = bestGroup->desiredNumberUnits();
                        number = bestGroup->numberUnits();
                        if (number < desired) {
                            int extra = this->numberExtraGroupedWarBoats();
                            desired = bestGroup->desiredNumberUnits();
                            number = bestGroup->numberUnits();
                            missing = desired - number;
                            if (missing < extra) {
                                desired = bestGroup->desiredNumberUnits();
                                number = bestGroup->numberUnits();
                                if (number < desired) {
                                    do {
                                        int i = 0;
                                        int bestUnitID = -1;
                                        float bestDistance = -1.0f;
                                        if (this->workingArea.numberValue > 0) {
                                            do {
                                                RGE_Static_Object* object = this->md->object(this->workingArea[i]);
                                                if (object != 0) {
                                                    float distance = object->distance_to_position(
                                                        bestGroup->gatherLocation().x, bestGroup->gatherLocation().y,
                                                        bestGroup->gatherLocation().z
                                                    );
                                                    if (bestDistance == -1.0f || distance < bestDistance) {
                                                        bestUnitID = this->workingArea[i];
                                                        bestDistance = distance;
                                                    }
                                                }
                                                ++i;
                                            } while (i < this->workingArea.numberValue);
                                        }
                                        if (bestUnitID == -1)
                                            break;
                                        this->removeFromGroup(bestUnitID);
                                        bestGroup->addUnit(bestUnitID, this->md);
                                        this->workingArea.remove(bestUnitID);
                                        desired = bestGroup->desiredNumberUnits();
                                        number = bestGroup->numberUnits();
                                    } while (number < desired);
                                }
                            } else {
                                int i = 0;
                                if (this->workingArea.numberValue > 0) {
                                    do {
                                        this->removeFromGroup(this->workingArea[i]);
                                        bestGroup->addUnit(this->workingArea[i], this->md);
                                        ++i;
                                    } while (i < this->workingArea.numberValue);
                                }
                            }
                        }
                    }
                }
                bestGroup = bestGroup->next;
            }
            ++bestUnit;
        } while (bestUnit <= TACTICAL_GROUP_TYPE_TRANSPORT);
    }

    if (this->numberUngroupedWarBoats() == 0)
        return;
    if (this->workingArea.numberValue <= 0)
        return;

    int i = 0;
    do {
        int bestDifference = 0;
        bestGroup = 0;
        group = this->groups.next;
        while (group != &this->groups && group != 0) {
            if (group->type() == TACTICAL_GROUP_TYPE_BOAT_ATTACK || group->type() == TACTICAL_GROUP_TYPE_BOAT_DEFEND
                || group->type() == TACTICAL_GROUP_TYPE_BOAT_EXPLORE || group->type() == TACTICAL_GROUP_TYPE_TRANSPORT
                || group->type() == TACTICAL_GROUP_TYPE_FISHING || group->type() == TACTICAL_GROUP_TYPE_TRADE) {
                int number = group->numberUnits();
                int desired = group->desiredNumberUnits();
                if (number < desired
                    && (group->action() == TACTICAL_GROUP_ACTION_IDLE
                        || group->action() == TACTICAL_GROUP_ACTION_NONE)) {
                    number = group->numberUnits();
                    desired = group->desiredNumberUnits();
                    int difference = desired - number;
                    if (bestGroup == 0 || difference > bestDifference) {
                        bestGroup = group;
                        bestDifference = difference;
                    }
                }
            }
            group = group->next;
        }

        if (bestGroup == 0) {
            group = this->groups.next;
            bestDifference = 0;
            while (group != &this->groups && group != 0) {
                if ((group->type() == TACTICAL_GROUP_TYPE_BOAT_ATTACK
                     || group->type() == TACTICAL_GROUP_TYPE_BOAT_DEFEND
                     || group->type() == TACTICAL_GROUP_TYPE_BOAT_EXPLORE
                     || group->type() == TACTICAL_GROUP_TYPE_TRANSPORT || group->type() == TACTICAL_GROUP_TYPE_FISHING
                     || group->type() == TACTICAL_GROUP_TYPE_TRADE)
                    && (group->action() == TACTICAL_GROUP_ACTION_IDLE || group->action() == TACTICAL_GROUP_ACTION_NONE)
                    && (group->type() != TACTICAL_GROUP_TYPE_BOAT_ATTACK
                        || group->numberUnits() < this->sn[SNMaximumBoatAttackGroupSize])
                    && (group->type() != TACTICAL_GROUP_TYPE_BOAT_DEFEND
                        || group->numberUnits() < this->sn[SNMaximumBoatDefendGroupSize])
                    && (group->type() != TACTICAL_GROUP_TYPE_BOAT_EXPLORE
                        || group->numberUnits() < this->sn[SNMaximumBoatExploreGroupSize])) {
                    int number = group->numberUnits();
                    int desired = group->desiredNumberUnits();
                    int difference = number - desired;
                    if (bestGroup == 0 || difference < bestDifference) {
                        bestGroup = group;
                        bestDifference = difference;
                    }
                }
                group = group->next;
            }
            if (bestGroup == 0)
                return;
        }

        bestGroup->addUnit(this->workingArea[i], this->md);
        ++i;
    } while (i < this->workingArea.numberValue);
}

int TribeTacticalAIModule::numberUngroupedWarBoats() {
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

int TribeTacticalAIModule::numberExtraGroupedWarBoats() {
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

        if ((group->type() == TACTICAL_GROUP_TYPE_BOAT_ATTACK || group->type() == TACTICAL_GROUP_TYPE_BOAT_DEFEND
             || group->type() == TACTICAL_GROUP_TYPE_BOAT_EXPLORE || group->type() == TACTICAL_GROUP_TYPE_TRANSPORT
             || group->type() == TACTICAL_GROUP_TYPE_FISHING || group->type() == TACTICAL_GROUP_TYPE_TRADE)
            && (group->action() == TACTICAL_GROUP_ACTION_IDLE || group->action() == TACTICAL_GROUP_ACTION_NONE)) {
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

int TribeTacticalAIModule::numberUngroupedFishingBoats() {
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

int TribeTacticalAIModule::numberUngroupedTradeBoats() {
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

int TribeTacticalAIModule::numberUngroupedTransportBoats() {
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

void TribeTacticalAIModule::displayBoatGroups() {
    this->logCommonHistory("Boat Groups:");
    TacticalAIGroup* group = this->groups.next;
    while (group != &this->groups) {
        if (group == 0)
            return;

        if (group->type() == TACTICAL_GROUP_TYPE_BOAT_ATTACK || group->type() == TACTICAL_GROUP_TYPE_BOAT_DEFEND
            || group->type() == TACTICAL_GROUP_TYPE_BOAT_EXPLORE || group->type() == TACTICAL_GROUP_TYPE_FISHING
            || group->type() == TACTICAL_GROUP_TYPE_TRADE || group->type() == TACTICAL_GROUP_TYPE_TRANSPORT) {
            if (group->type() == TACTICAL_GROUP_TYPE_BOAT_ATTACK)
                this->logCommonHistory("  Group ID#%d:  Attack Group (Type=%d).", group->id(), group->type());
            else if (group->type() == TACTICAL_GROUP_TYPE_BOAT_DEFEND)
                this->logCommonHistory("  Group ID#%d:  Defend Group (Type=%d).", group->id(), group->type());
            else if (group->type() == TACTICAL_GROUP_TYPE_BOAT_EXPLORE)
                this->logCommonHistory("  Group ID#%d:  Explore Group (Type=%d).", group->id(), group->type());
            else if (group->type() == TACTICAL_GROUP_TYPE_FISHING)
                this->logCommonHistory("  Group ID#%d:  Fishing Group (Type=%d).", group->id(), group->type());
            else if (group->type() == TACTICAL_GROUP_TYPE_TRADE)
                this->logCommonHistory("  Group ID#%d:  Trade Group (Type=%d).", group->id(), group->type());
            else if (group->type() == TACTICAL_GROUP_TYPE_TRANSPORT)
                this->logCommonHistory("  Group ID#%d:  Transport Group (Type=%d).", group->id(), group->type());

            this->logCommonHistory(
                "    NumUnits=%d, DesNumUnits=%d, OrgNumUnits=%d, Action=%d, inUse=%d.", group->numberUnits(),
                group->desiredNumberUnits(), group->originalUnitNumber(), group->action(), group->inUse()
            );
            this->logCommonHistory(
                "    Target=%d, CommanderID=%d, HP(%d/%d), AssistGroupID=%d.", group->target(), group->commander(),
                group->currentHitPoints(this->md), group->originalHitPoints(), group->assistGroupID()
            );
            this->logCommonHistory("    Location=(%f, %f).", group->location().x, group->location().y);
            this->logCommonHistory(
                "    Gather Location=(%f, %f).", group->gatherLocation().x, group->gatherLocation().y
            );
            this->logCommonHistory(
                "    Retreat Location=(%f, %f).", group->retreatLocation().x, group->retreatLocation().y
            );
            this->logCommonHistory(
                "    Target Location=(%f, %f).", group->targetLocation().x, group->targetLocation().y
            );

            for (int i = 0; i < group->numberUnits(); ++i) {
                this->logCommonHistory("    Unit #%d.", group->unit(i));
                RGE_Static_Object* object = this->md->object(group->unit(i));
                if (object == 0) {
                    this->logCommonHistory("    Unit %d is invalid.");
                } else if (object->unitAI() == 0) {
                    this->logCommonHistory("    Unit %d has invalid unitAI.");
                } else {
                    this->logCommonHistory(
                        "    Unit %d: state=%d, action=%d, target=%d, order=%d, priority=%d, location=(%f, %f).",
                        group->unit(i), object->object_state, object->unitAI()->currentAction(),
                        object->unitAI()->currentTarget(), object->unitAI()->currentOrder(),
                        object->unitAI()->currentOrderPriority(), object->world_x, object->world_y
                    );
                }
            }
        }
        group = group->next;
    }
}

void* __cdecl operator new(unsigned int size);

TacticalAIGroup* TribeTacticalAIModule::createGroup(int initID) {
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
    if (initID == 1) {
        id = this->groupIDValue;
        this->groupIDValue = id + 1;
        group->setID(id);
        this->numberGroupsValue = this->numberGroupsValue + 1;
    }
    return group;
}

int TribeTacticalAIModule::removeGroup(int gID) {
    TacticalAIGroup* sentinel = &this->groups;
    int targetId = gID;
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

int TribeTacticalAIModule::removeAllGroups(int tID) {
    int wanted;
    int groupType;
    TacticalAIGroup* group;
    TacticalAIGroup* sentinel;
    TacticalAIGroup* prev;

    group = this->groups.next;
    sentinel = &this->groups;
    if (group != sentinel) {
        wanted = tID;
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

TacticalAIGroup* TribeTacticalAIModule::group(int gID, int type, int action, int targetID) {
    TacticalAIGroup* group;
    TacticalAIGroup* sentinel;
    int wantType;
    int wantAction;
    int wantTarget;

    group = this->groups.next;
    sentinel = &this->groups;
    if (group != sentinel) {
        wantTarget = targetID;
        wantAction = action;
        wantType = type;
        while (1) {
            if (group == 0) {
                break;
            }
            if (gID == -1 || group->id() == gID) {
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

TacticalAIGroup* TribeTacticalAIModule::bestGroup(int type, int action, int distance, XYPoint& point, int zone) {
    TacticalAIGroup* group;
    TacticalAIGroup* best;
    int bestDistance;

    group = this->groups.next;
    best = 0;
    bestDistance = -1;

    if (group != &this->groups) {
        while (1) {
            if (group == 0)
                return best;

            if ((type == -1 || group->type() == type) && (action == -1 || group->action() == action)) {
                if (type == TACTICAL_GROUP_TYPE_TRANSPORT) {
                    int valid = 1;
                    TacticalAIGroup* assist = this->groups.next;

                    do {
                        if (assist == &this->groups || assist == 0)
                            break;
                        if (!valid)
                            goto next_group;
                        const int id = group->id();
                        if (assist->assistGroupID() == id)
                            valid = 0;
                        assist = assist->next;
                    } while (assist != &this->groups);

                    if (!valid)
                        goto next_group;
                }

                if (zone != -1) {
                    RGE_Static_Object* object = this->md->object(group->commander());
                    if (object == 0 || object->currentZone() != zone)
                        goto next_group;
                }

                int distanceSquared =
                    (point.y - (int) group->gatherLocation().y) * (point.y - (int) group->gatherLocation().y)
                    + (point.x - (int) group->gatherLocation().x) * (point.x - (int) group->gatherLocation().x);
                int groupDistance = (int) sqrt((double) distanceSquared);

                if ((groupDistance < distance && bestDistance == -1)
                    || (distance == -1 || groupDistance < bestDistance)) {
                    best = group;
                    bestDistance = groupDistance;
                }
            }

        next_group:
            group = group->next;
            if (group == &this->groups)
                break;
        }
    }

    return best;
}

TacticalAIGroup* TribeTacticalAIModule::readyAndIdleGroup(int type, int distance, XYPoint& point) {
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
                if (desired <= group->numberUnits() && group->isGathered(this, this->md) != 0
                    && group->allUnitsIdle(this->md, 1) != 0) {
                    int distanceSquared =
                        (point.y - (int) group->gatherLocation().y) * (point.y - (int) group->gatherLocation().y)
                        + (point.x - (int) group->gatherLocation().x) * (point.x - (int) group->gatherLocation().x);
                    int groupDistance = (int) sqrt((double) distanceSquared);

                    if ((groupDistance < distance && bestDistance == -1) || groupDistance < bestDistance) {
                        bestGroup = group;
                        bestDistance = groupDistance;
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

int TribeTacticalAIModule::addToGroup(int uID, int gID) {
    TacticalAIGroup* grp = group(gID, -1, -1, -1);
    if (!grp)
        return 0;
    return grp->addUnit(uID, this->md);
}

int TribeTacticalAIModule::removeFromGroup(int uID, int gID) {
    TacticalAIGroup* group = this->group(gID, -1, -1, -1);
    if (group == 0) {
        return 0;
    }

    int result = group->removeUnit(uID, this->md);
    if (group->numberUnits() == 0) {
        this->removeGroup(gID);
    }

    return result;
}

int TribeTacticalAIModule::removeFromGroup(int uID) {
    TacticalAIGroup* group;
    int result;

    group = this->groupUnitIsIn(uID);
    if (group == 0) {
        return 0;
    }
    result = group->removeUnit(uID, this->md);
    if (group->numberUnits() == 0) {
        this->removeGroup(group->id());
    }
    return result;
}

TacticalAIGroup* TribeTacticalAIModule::groupUnitIsIn(int uID) {
    TacticalAIGroup* group = this->groups.next;
    TacticalAIGroup* end = &this->groups;

    while (group != end) {
        if (group == 0) {
            return 0;
        }
        if (group->containsUnit(uID) == 1) {
            return group;
        }
        group = group->next;
    }

    return 0;
}

int TribeTacticalAIModule::numberGroups(int type, int action) {
    TacticalAIGroup* group = this->groups.next;
    TacticalAIGroup* sentinel = &this->groups;
    int count = 0;

    while (group != sentinel && group != 0) {
        if ((type == -1 || group->type() == type) && (action == -1 || group->action() == action)) {
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

int TribeTacticalAIModule::numberItemsToAttack() {
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
                    } else {
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

int TribeTacticalAIModule::itemToBringToArea() {
    int target;

    if (this->md->strategyAI.currentVictoryCondition() == 4) {
        target = this->md->strategyAI.secondTargetID();
        if (this->group(-1, -1, -1, target) == 0)
            return target;
    }
    return -1;
}

int TribeTacticalAIModule::numberItemsToDefend() {
    return this->md->informationAI.numberItemsToDefend();
}

// TribeTacticalAIModule::attackLimiterTime

unsigned long TribeTacticalAIModule::attackLimiterTime(int snType) {
    if (this->sn[SNLockAttackAndAttackResponse] == 1) {
        int val = this->randomizedAttackSeparationTime;
        int limit = this->sn[SNAttackResponseSeparationTime];
        if (val < limit) {
            return val;
        }
        return limit;
    } else {
        if (snType == SNAttackSeparationTime) {
            return this->randomizedAttackSeparationTime;
        }
        return this->sn[SNAttackResponseSeparationTime];
    }
}

void TribeTacticalAIModule::resetAttackSeparationTime() {
    if (this->sn[SNAttackSeparationTimeRandomness] > 0) {
        this->randomizedAttackSeparationTime =
            debug_rand((char*) "C:\\msdev\\work\\age1_x1\\taitacmd.cpp", 11573)
                % this->sn[SNAttackSeparationTimeRandomness]
            + (this->sn[SNAttackSeparationTime] - this->sn[SNAttackSeparationTimeRandomness] / 2);
    } else {
        this->randomizedAttackSeparationTime = this->sn[SNAttackSeparationTime];
    }

    if (this->randomizedAttackSeparationTime < 0) {
        this->randomizedAttackSeparationTime = 0;
    }
}

int TribeTacticalAIModule::setGatherLocation(TacticalAIGroup* g) {
    int cmdr = g->commander();
    RGE_Static_Object* obj = this->md->object(cmdr);
    if (obj == 0)
        return 0;

    int flag;
    if (g->type() == TACTICAL_GROUP_TYPE_ATTACK) {
        flag = 1;
    } else {
        if (g->type() == TACTICAL_GROUP_TYPE_DEFEND) {
            flag = 1;
        } else {
            int gtype = g->type();
            flag = 0;
            if (gtype == TACTICAL_GROUP_TYPE_EXPLORE)
                flag = 1;
        }
    }

    RGE_Static_Object* target =
        this->md->object(-1, MASTER_OBJECT_TOWN_CENTER1, -1, -1, -1, -1, -1, -1, RGE_OBJECT_STATE_ANY, -1);
    if (target == 0)
        return 0;

    XYPoint centerPoint;
    XYPoint gatherPoint;
    centerPoint.x = (int) target->world_x;
    centerPoint.y = (int) target->world_y;

    int result = this->md->informationAI.findGatherPosition(
        centerPoint, g->desiredNumberUnits(), flag, this->sn[SNSentryDistance], this->sn[SNSentryDistanceVariation],
        obj, gatherPoint
    );
    if (result == 1) {
        g->setGatherLocation((float) gatherPoint.x, (float) gatherPoint.y, obj->world_z);
        return 1;
    }
    g->setGatherLocation(obj->world_x, obj->world_y, obj->world_z);
    return 1;
}

int TribeTacticalAIModule::setAllGroupLocations(TacticalAIGroup* g) {
    int cmdr = g->commander();
    RGE_Static_Object* obj = this->md->object(cmdr);
    if (obj == 0)
        return 0;

    int flag;
    if (g->type() == TACTICAL_GROUP_TYPE_ATTACK) {
        flag = 1;
    } else {
        if (g->type() == TACTICAL_GROUP_TYPE_DEFEND) {
            flag = 1;
        } else {
            int gtype = g->type();
            flag = 0;
            if (gtype == TACTICAL_GROUP_TYPE_EXPLORE)
                flag = 1;
        }
    }

    RGE_Static_Object* target =
        this->md->object(-1, MASTER_OBJECT_TOWN_CENTER1, -1, -1, -1, -1, -1, -1, RGE_OBJECT_STATE_ANY, -1);
    if (target != 0) {
        XYPoint centerPoint;
        XYPoint gatherPoint;
        centerPoint.x = (int) target->world_x;
        centerPoint.y = (int) target->world_y;

        int result = this->md->informationAI.findGatherPosition(
            centerPoint, g->desiredNumberUnits(), flag, this->sn[SNSentryDistance], this->sn[SNSentryDistanceVariation],
            obj, gatherPoint
        );
        if (result == 1) {
            g->setAllLocations((float) gatherPoint.x, (float) gatherPoint.y, obj->world_z);
            return 1;
        }
    }

    g->setAllLocations(obj->world_x, obj->world_y, obj->world_z);
    return 1;
}

void TribeTacticalAIModule::setGroupInfluences(InfluenceMap& iMap) {
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
                clearDistance = this->md->informationAI.groupInfluenceDimension(group->desiredNumberUnits());
                half = clearDistance / 2;

                minpt.x = (int) (group->gatherLocation().x - (float) half);
                minpt.y = (int) (group->gatherLocation().y - (float) half);
                this->md->informationAI.mapBound(minpt);
                maxpt.x = (int) (group->gatherLocation().x + (float) half);
                maxpt.y = (int) (group->gatherLocation().y + (float) half);
                this->md->informationAI.mapBound(maxpt);
                iMap.setValue(minpt.x, minpt.y, maxpt.x, maxpt.y, 255);

                half = clearDistance;
                minpt.x = (int) (group->gatherLocation().x - (float) half);
                minpt.y = (int) (group->gatherLocation().y - (float) half);
                this->md->informationAI.mapBound(minpt);
                maxpt.x = (int) (group->gatherLocation().x + (float) half);
                maxpt.y = (int) (group->gatherLocation().y + (float) half);
                this->md->informationAI.mapBound(maxpt);
                iMap.decrementValue(minpt.x, minpt.y, maxpt.x, maxpt.y, 10);
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
                minpt.x = (int) object->world_x;
                minpt.y = (int) object->world_y;
                this->md->informationAI.mapBound(minpt);
                maxpt.x = (int) object->world_x;
                maxpt.y = (int) object->world_y;
                this->md->informationAI.mapBound(maxpt);
                iMap.setValue(minpt.x, minpt.y, maxpt.x, maxpt.y, 255);

                int clearDistance;
                clearDistance = this->md->informationAI.groupInfluenceDimension(1);
                minpt.x = (int) (object->world_x - (float) clearDistance);
                minpt.y = (int) (object->world_y - (float) clearDistance);
                this->md->informationAI.mapBound(minpt);
                maxpt.x = (int) ((float) clearDistance + object->world_x);
                maxpt.y = (int) ((float) clearDistance + object->world_y);
                this->md->informationAI.mapBound(maxpt);
                iMap.decrementValue(minpt.x, minpt.y, maxpt.x, maxpt.y, 10);
            }
            i++;
        } while (i < this->ungroupedSoldiers.numberValue);
    }
}

int TribeTacticalAIModule::selectBestCommander(TacticalAIGroup* temp) {
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
    if (temp->numberUnits() > 0) {
        do {
            obj = self->md->object(temp->unit(i));
            if (obj != 0) {
                if (obj->master_obj->id != MASTER_OBJECT_PRIEST) {
                    if (self->sn[SNGroupCommanderSelectionMethod] == 2) {
                        score = (int) obj->weaponRange();
                    } else {
                        score = (int) obj->hp;
                    }
                    mode = self->sn[SNGroupCommanderSelectionMethod];
                    if (mode == 1 || mode == 3) {
                        if (bestScore == -1 || score < bestScore) {
                            bestUnit = temp->unit(i);
                            bestScore = score;
                        }
                    } else {
                        if (bestScore == -1 || score > bestScore) {
                            bestUnit = temp->unit(i);
                            bestScore = score;
                        }
                    }
                }
            }
            i = i + 1;
        } while (i < temp->numberUnits());
    }
    return bestUnit;
}

int TribeTacticalAIModule::selectBestCommander(ManagedArray<int>& temp) {
    int bestScore = -1;
    int bestUnit = -1;
    int i = 0;
    if (temp.numberValue > 0) {
        do {
            if (i > temp.maximumSizeValue - 1) {
                int newMax = i + 1;
                int* n = (int*) operator new(newMax * 4);
                if (n) {
                    int j = 0;
                    while (j < temp.maximumSizeValue && j < newMax) {
                        n[j] = temp.value[j];
                        ++j;
                    }
                    operator delete(temp.value);
                    temp.value = n;
                    temp.maximumSizeValue = newMax;
                }
            }
            int id = temp.value[i];
            RGE_Static_Object* obj = this->md->object(id);
            if (obj != 0) {
                if (obj->master_obj->id != MASTER_OBJECT_PRIEST) {
                    int score;
                    if (this->sn[SNGroupCommanderSelectionMethod] == 2) {
                        score = (int) obj->weaponRange();
                    } else {
                        score = (int) obj->hp;
                    }
                    if (this->sn[SNGroupCommanderSelectionMethod] == 1
                        || this->sn[SNGroupCommanderSelectionMethod] == 3) {
                        if (bestScore == -1 || score < bestScore) {
                            if (i > temp.maximumSizeValue - 1) {
                                int newMax = i + 1;
                                int* n = (int*) operator new(newMax * 4);
                                if (n) {
                                    int j = 0;
                                    while (j < temp.maximumSizeValue && j < newMax) {
                                        n[j] = temp.value[j];
                                        ++j;
                                    }
                                    operator delete(temp.value);
                                    temp.value = n;
                                    temp.maximumSizeValue = newMax;
                                }
                            }
                            bestUnit = temp.value[i];
                            bestScore = score;
                        }
                    } else {
                        if (bestScore == -1 || score > bestScore) {
                            if (i > temp.maximumSizeValue - 1) {
                                int newMax = i + 1;
                                int* n = (int*) operator new(newMax * 4);
                                if (n) {
                                    int j = 0;
                                    while (j < temp.maximumSizeValue && j < newMax) {
                                        n[j] = temp.value[j];
                                        ++j;
                                    }
                                    operator delete(temp.value);
                                    temp.value = n;
                                    temp.maximumSizeValue = newMax;
                                }
                            }
                            bestUnit = temp.value[i];
                            bestScore = score;
                        }
                    }
                }
            }
            ++i;
        } while (i < temp.numberValue);
    }
    return bestUnit;
}

int TribeTacticalAIModule::dealWithGAIAAttacker(RGE_Static_Object* attacker, RGE_Static_Object* victim) {
    int count;
    int unitID;
    RGE_Static_Object* unitObject;
    XYPoint vPosition;
    XYZPoint point;

    if (attacker == 0 || victim == 0)
        return 0;

    int targetID = victim->id;
    int i;
    for (i = 0; i < this->civilianExplorers.numberValue; i++) {
        if (i >= this->civilianExplorers.maximumSizeValue)
            break;
        if (this->civilianExplorers.value[i] == targetID)
            return 0;
    }

    count = 0;
    vPosition.x = (int) victim->world_x;
    vPosition.y = (int) victim->world_y;
    unitID = this->civilian(vPosition, 1, UNIT_AI_ORDER_ATTACK, UNIT_AI_ORDER_HUNT, UNIT_AI_ORDER_HUNT, 1);
    while (unitID != -1 && count < this->sn[SNMaximumGAIAAttackResponse]
           && (unitObject = this->md->object(unitID)) != 0) {
        point.x = (int) attacker->world_x;
        point.y = (int) attacker->world_y;
        point.z = (int) attacker->world_z;
        if (unitObject->canPath(point, unitObject->weaponRange(), attacker->id, 0, 1, -1, -1) == 0)
            break;

        this->taskAttacker(
            unitID, attacker->world_x, attacker->world_y, attacker->id, (int) attacker->owner->id, 0, 0, -1, 0
        );
        count++;
        unitID = this->civilian(vPosition, 1, UNIT_AI_ORDER_ATTACK, UNIT_AI_ORDER_HUNT, UNIT_AI_ORDER_HUNT, 1);
    }

    return count > 0;
}

void TribeTacticalAIModule::addWaypoint(int recipient, unsigned char x, unsigned char y) {
    XYZBYTEPoint info;

    info.x = x;
    info.y = y;
    info.z = 1;
    this->md->player->sendAddWaypointCommand(recipient, &info, 1);
}

int TribeTacticalAIModule::importantGroupLeader(int cID) {
    RGE_Static_Object* object = this->md->object(cID);
    if (object == 0) {
        return 0;
    }
    short group = object->master_obj->object_group;
    if ((group != OBJECT_GROUP_PRIEST) && (group != 0x0D)) {
        return 0;
    }
    return 1;
}

void TribeTacticalAIModule::enableAttack(int type) {
    if (this->attackEnabledValue == 1)
        return;
    int field3AC = this->sn[0x86];
    if (field3AC != 0 && field3AC != type)
        return;
    this->attackEnabledValue = 1;
}

int TribeTacticalAIModule::unexploredArea(int uID, XYPoint& rPoint) {
    RGE_Static_Object* unit = this->md->object(uID);
    if (unit == 0) {
        return 0;
    }
    unsigned char unitZone = unit->currentZone();
    RGE_Static_Object* explorer =
        this->md->object(-1, MASTER_OBJECT_TOWN_CENTER1, -1, -1, -1, -1, -1, -1, RGE_OBJECT_STATE_ANY, -1);
    float bestDistance = -1.0f;
    XYPoint bestPoint = { -1, -1 };
    if (explorer != 0) {
        int i = 0;
        do {
            rPoint.x = (int) explorer->world_x;
            rPoint.y = (int) explorer->world_y;
            switch (i) {
                case 0:
                    rPoint.x -= 10;
                    rPoint.y -= 10;
                    break;
                case 1:
                    rPoint.y -= 10;
                    break;
                case 2:
                    rPoint.x += 10;
                    rPoint.y -= 10;
                    break;
                case 3:
                    rPoint.x += 10;
                    break;
                case 4:
                    rPoint.x += 10;
                    rPoint.y += 10;
                    break;
                case 5:
                    rPoint.y += 10;
                    break;
                case 6:
                    rPoint.x -= 10;
                    rPoint.y += 10;
                    break;
                case 7:
                    rPoint.x -= 10;
                    break;
            }
            if (rPoint.x >= 0 && rPoint.y >= 0 && rPoint.x < this->md->informationAI.mapXSize()
                && rPoint.y < this->md->informationAI.mapYSize()) {
                if (this->md->informationAI.tileUncovered(rPoint.x, rPoint.y) != 1
                    && unitZone == unit->lookupZone(rPoint.x, rPoint.y)) {
                    float d = unit->distance_to_position((float) rPoint.x, (float) rPoint.y, unit->world_z);
                    if (bestDistance == -1.0f || d < bestDistance) {
                        bestDistance = d;
                        bestPoint.x = rPoint.x;
                        bestPoint.y = rPoint.y;
                    }
                }
            }
            i++;
        } while (i < 8);
    }
    if (bestDistance != -1.0f) {
        rPoint.x = bestPoint.x;
        rPoint.y = bestPoint.y;
        this->md->informationAI.setTileExplored(bestPoint.x, bestPoint.y);
        return 1;
    }
    return this->md->informationAI.unexploredPlayerLocation(uID, rPoint) != 0;
}

UnitData* TribeTacticalAIModule::gatherer(int id) {
    int i;

    for (i = 0; i < 0x32; i++) {
        if (this->gatherers[i].id == id)
            return this->gatherers + i;
    }
    return 0;
}

UnitData* TribeTacticalAIModule::addGatherer(int id) {
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

int TribeTacticalAIModule::removeGatherer(int id) {
    UnitData* gatherer;
    int* gatherer_data;
    int index;

    if (id == -1) {
        this->logCommonHistory("ERROR removing gatherer id -1.");
        return 0;
    }
    index = 0;
    gatherer = this->gatherers;
    while (index < 0x32) {
        if (gatherer->id == id) {
            gatherer_data = &this->gatherers[index].data1;
            this->gatherers[index].id = -1;
            *gatherer_data = -1;
            this->gatherers[index].data2 = -1;
            this->gatherers[index].data3 = -1;
            this->gatherers[index].target = -1;
            this->numberGatherersValue = this->numberGatherersValue - 1;
            for (; index < 0x31 && gatherer_data[5] != -1; gatherer_data = gatherer_data + 6) {
                ((UnitData*) (gatherer_data - 1))->id = gatherer_data[5];
                *gatherer_data = gatherer_data[6];
                gatherer_data[1] = gatherer_data[7];
                gatherer_data[2] = gatherer_data[8];
                gatherer_data[3] = gatherer_data[9];
                gatherer_data[5] = -1;
                gatherer_data[6] = -1;
                gatherer_data[7] = -1;
                gatherer_data[8] = -1;
                gatherer_data[9] = -1;
                index = index + 1;
            }
            return 1;
        }
        index = index + 1;
        gatherer = gatherer + 1;
    }
    return 0;
}

int TribeTacticalAIModule::isGatherer(int id) {
    int i;

    for (i = 0; i < 0x32; i++) {
        if (this->gatherers[i].id == id)
            return 1;
    }
    return 0;
}

int TribeTacticalAIModule::requiredGatherAmount(int rType) {
    if (this->desiredGathererDistribution[rType] == 0) {
        return this->sn[0x94];
    }
    int value = this->neededResources.value(rType);
    return value / this->desiredGathererDistribution[rType];
}

void TribeTacticalAIModule::trackUnitGather(int unitID, int attributeID, int amount) {
    UnitData* entry;

    if (this->resourceDifferenceValue[attributeID] < 0) {
        if (this->md->resourceAI.resource(attributeID) + this->resourceDifferenceValue[attributeID] > 0) {
            this->updateNeededResources();
        }
    }

    entry = this->gatherer(unitID);
    if (entry != 0 && entry->data1 == attributeID) {
        entry->data3 += amount;
    }
}

int TribeTacticalAIModule::deleteUnit(int unitID) {
    RGE_Static_Object* object;

    object = this->md->object(unitID);
    if (object != 0) {
        if (this->md->aiPlayer->command_delete_object(object) == 1) {
            return 1;
        }
    }

    return 0;
}

int TribeTacticalAIModule::numberAvailableStoragePits(int& numStoragePits, int& numUnbuiltStoragePits, int rType) {
    int product;
    int value;
    int capacity_or_count;
    unsigned int remaining;

    value = this->md->buildAI.numberUnbuiltItemsOfType(MASTER_OBJECT_STORAGE_PIT1, BUILD_CATEGORY_BUILDING);
    numUnbuiltStoragePits = value;
    if (value > 0) {
        return 0;
    }

    value = this->md->resourceAI.resource(rType);
    if (this->sn[rType + 0xBE] <= value) {
        return 0;
    }

    value = this->sn[0x96];
    if (value != -1) {
        capacity_or_count = (int) this->md->player->attributes[PLAYER_ATTRIBUTE_CURRENT_AGE];
        if (capacity_or_count == 0) {
            capacity_or_count = 1;
        }
        product = capacity_or_count * value;
        capacity_or_count = this->md->buildAI.numberItemsOfType(MASTER_OBJECT_STORAGE_PIT1, BUILD_CATEGORY_BUILDING);
        remaining = product - capacity_or_count;
        numStoragePits = capacity_or_count;
        return ((int) remaining < 0) ? 0 : remaining;
    } else {
        numStoragePits = this->md->buildAI.numberItemsOfType(MASTER_OBJECT_STORAGE_PIT1, BUILD_CATEGORY_BUILDING);
        return this->md->informationAI.numberAvailableStoragePits(rType);
    }
}

int TribeTacticalAIModule::numberAvailableGranaries(int& numGranaries, int& numUnbuiltGranaries) {
    int value;

    value = this->md->buildAI.numberUnbuiltItemsOfType(MASTER_OBJECT_GRANARY, BUILD_CATEGORY_BUILDING);
    numUnbuiltGranaries = value;
    if (value > 0) {
        return 0;
    }
    value = this->md->resourceAI.resource(RGE_RESOURCE_FOOD);
    if (this->sn[0xBE] <= value) {
        return 0;
    }
    if (this->sn[0x97] != -1) {
        value = this->md->buildAI.numberItemsOfType(MASTER_OBJECT_GRANARY, BUILD_CATEGORY_BUILDING);
        numGranaries = value;
        if (value >= this->sn[0x97]) {
            return 0;
        }
    }
    value = this->md->buildAI.numberItemsOfType(MASTER_OBJECT_GRANARY, BUILD_CATEGORY_BUILDING);
    numGranaries = value;
    return this->md->informationAI.numberAvailableGranaries();
}

int TribeTacticalAIModule::initialExplorationSatisfied() {
    int explored_percent;

    if (this->sn[0xA7] <= 0)
        return 1;

    explored_percent = (int) (this->md->player->visible->percentExplored() * 100.0f);
    return explored_percent >= this->sn[0xA7];
}

void TribeTacticalAIModule::checkForBuildInsertion(int type, int number, int position) {
    switch (type) {
        case MASTER_OBJECT_FARM:
            if (this->sn[SNAutoBuildFarms] != 1 || this->inAge(4) == 0)
                break;
            {
                ResourceItem itemCost(4);
                for (int i = 0; i < number; ++i)
                    itemCost.setValue(i, itemCost.value(i) * number);
                this->md->aiPlayer->objectCost(0x32, -1, &itemCost, 1);
                if (this->md->resourceAI.resourcesAvailable(&itemCost) == 0)
                    break;
                if (this->md->aiPlayer->objectAvailable(0x32) == 0)
                    break;
                if (this->md->buildAI.allBuilt(BUILD_CATEGORY_BUILDING, BUILD_CATEGORY_BUILDING) == 0)
                    break;
                //! This row budget is the game's only farm cap; it counts build-list rows, not live farms.
                //! Deathmatch holds every other gate open, so the AI claims the full budget and replants.
                //! RockNROR adds a deathmatch farm maximum here (SNMaxFarms); the default budget is 8.
                if (this->md->buildAI.numberBuiltOrInProgressItemsOfType(MASTER_OBJECT_FARM, BUILD_CATEGORY_BUILDING)
                    >= this->sn[0xDC])
                    break;
                this->md->buildAI.insert(MASTER_OBJECT_FARM, number, position);
            }
            break;

        case MASTER_OBJECT_GRANARY:
            if (this->sn[0xCD] != 1)
                break;
            if (this->md->informationAI.closestDropsiteValue[0] == -1)
                break;
            {
                int unbuilt = 0;
                int granaries = 0;
                int available = this->numberAvailableGranaries(unbuilt, granaries);
                if (granaries <= 0 && available > 0
                    && this->sn[0xA3] < this->md->informationAI.closestDropsiteValue[0]) {
                    this->md->buildAI.insert(MASTER_OBJECT_GRANARY, number, position);
                }
            }
            break;

        case MASTER_OBJECT_WATCH_TOWER:
            if (this->sn[0xCF] != 1)
                break;
            {
                ResourceItem itemCost(4);
                for (int i = 0; i < number; ++i)
                    itemCost.setValue(i, itemCost.value(i) * number);
                this->md->aiPlayer->objectCost(0x4F, -1, &itemCost, 1);
                if (this->md->resourceAI.resourcesAvailable(&itemCost) == 0)
                    break;
                if (this->md->aiPlayer->objectAvailable(0x4F) == 0)
                    break;
                if (this->md->buildAI.allBuilt(BUILD_CATEGORY_BUILDING, BUILD_CATEGORY_BUILDING) == 0)
                    break;
                if (this->md->buildAI.numberBuiltOrInProgressItemsOfType(
                        MASTER_OBJECT_WATCH_TOWER, BUILD_CATEGORY_BUILDING
                    )
                    >= this->sn[0xDE])
                    break;
                this->md->buildAI.insert(MASTER_OBJECT_WATCH_TOWER, number, position);
            }
            break;
    }
}

int TribeTacticalAIModule::isFarmer(RGE_Static_Object* temp) {
    UnitAIModule* ai;
    int action;

    if (temp != 0 && (ai = temp->unitAI()) != 0 && temp->master_obj->id == MASTER_OBJECT_FARMER) {
        ai = temp->unitAI();
        action = ai->currentAction();
        if (action != UNIT_AI_ACTION_GATHER) {
            ai = temp->unitAI();
            action = ai->currentAction();
            if (action != UNIT_AI_ACTION_MOVE) {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

int TribeTacticalAIModule::numberFarmers() {
    int i;
    int rVal;

    i = 0;
    rVal = 0;

    if (this->civilians.numberValue > 0) {
        do {
            RGE_Static_Object* obj = this->md->object(this->civilians[i]);
            if ((obj != 0) && (obj->unitAI() != 0) && (obj->master_obj->id == MASTER_OBJECT_FARMER)) {
                if (obj->unitAI()->currentAction() == UNIT_AI_ACTION_GATHER
                    || obj->unitAI()->currentAction() == UNIT_AI_ACTION_MOVE) {
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
    int currentAge = (int) this->md->player->attributes[PLAYER_ATTRIBUTE_CURRENT_AGE];
    return currentAge == age ? 1 : 0;
}

void TribeTacticalAIModule::stuffAvoidancePath(TacticalAIGroup* group, Path* path) {
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
        if ((tooFew || accumDist >= divisionLength) && (tooFew != 1 || accumDist >= 5.0f)) {
            group->addAttackWaypoint(path->currentWaypoint()->x, path->currentWaypoint()->y);
        }

        accumDist += path->distanceToNextWaypoint();
        i++;
        path->moveToNextWaypoint();
    }
}

//! @bug The attack-response insertion adds up to 5 fixed unit orders and a building at the strategy head.
//! The unit list ignores the attacker types, so the orders are often irrelevant.
//! Head items consume the scan budget, so the real strategy is never picked and the AI stalls.
void TribeTacticalAIModule::checkForAttackResponseBuildInsertions(int playerID) {
    long lastAttackTime = this->lastAttackResponseBuildInsertionTime;
    long currentTime = this->md->player->world->world_time;
    if ((currentTime - lastAttackTime) / 1000 < 180)
        return;

    this->lastAttackResponseBuildInsertionTime = currentTime;
    RGE_Static_Object* object =
        this->md->object(-1, MASTER_OBJECT_TOWN_CENTER1, -1, -1, -1, -1, -1, -1, RGE_OBJECT_STATE_ANY, -1);
    if (object == 0)
        return;

    int unitsToInsert;
    unitsToInsert =
        this->md->informationAI.numberUnitsWithinXTiles(playerID, (int) object->world_x, (int) object->world_y, 20)
        - this->soldiers.numberValue;
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
                if (this->md->resourceAI.resource(RGE_RESOURCE_STONE) >= 150 && this->civilians.numberValue > 2) {
                    this->md->buildAI.insert(MASTER_OBJECT_WATCH_TOWER, 1, 0);
                    unitsToInsert -= 2;
                }
                insertedUnit = 1;
                continue;
            case 1:
                unitType = MASTER_OBJECT_SOLDIER_CAVALRY1;
                objectType = MASTER_OBJECT_STABLE;
                break;
            case 2:
                unitType = MASTER_OBJECT_SOLDIER_INF3;
                objectType = MASTER_OBJECT_BARRACKS1;
                break;
            case 3:
                unitType = MASTER_OBJECT_SOLDIER_PHAL1;
                objectType = MASTER_OBJECT_ACADEMY;
                break;
            case 4:
                unitType = MASTER_OBJECT_SOLDIER_CAVALRY3_ARCH;
                objectType = MASTER_OBJECT_RANGE1;
                break;
            case 5:
                unitType = MASTER_OBJECT_SOLDIER_INF1;
                objectType = MASTER_OBJECT_BARRACKS1;
                break;
            case 6:
                unitType = MASTER_OBJECT_SOLDIER_ARCHER2;
                objectType = MASTER_OBJECT_RANGE1;
                break;
            case 7:
                unitType = MASTER_OBJECT_SOLDIER_SCOUT;
                objectType = MASTER_OBJECT_STABLE;
                break;
            case 8:
                unitType = MASTER_OBJECT_SOLDIER_ARCHER1;
                objectType = MASTER_OBJECT_RANGE1;
                break;
            case 9:
                unitType = MASTER_OBJECT_PRIEST;
                objectType = MASTER_OBJECT_TEMPLE1;
                break;
            case 10:
                unitType = MASTER_OBJECT_SOLDIER_CHARIOT2;
                objectType = MASTER_OBJECT_RANGE1;
                break;
            case 11:
                unitType = MASTER_OBJECT_SOLDIER_CHARIOT1;
                objectType = MASTER_OBJECT_STABLE;
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

        RGE_Static_Object* target = this->md->object(-1, objectType, -1, -1, -1, -1, -1, -1, RGE_OBJECT_STATE_ANY, -1);
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

void TribeTacticalAIModule::checkForCoopTributeDemand() {
    int tempRand;
    int pick;
    TRIBE_World* world;
    int i;
    int j;
    int amountDemandable;
    RGE_Player* player;
    int cur;
    int count;

    if (this->sn[0xBA] == -1)
        return;
    world = static_cast<TRIBE_World*>(this->md->player->world);
    cur = world->world_time;
    if ((int) (cur - this->lastCoopTributeDemandTime) / 1000 < this->sn[0xBA])
        return;
    this->lastCoopTributeDemandTime = cur;

    world = static_cast<TRIBE_World*>(this->md->player->world);
    if (world->controllingComputerPlayer == 0xff) {
        i = 1;
        count = 0;
        if (world->player_num > 1) {
            do {
                if (world->players[i]->computerPlayer() == 1)
                    count++;
                i++;
            } while (i < world->player_num);
        }
        if (count == 1) {
            world->controllingComputerPlayer = (uchar) this->md->player->id;
        } else {
            pick = debug_rand("C:\\msdev\\work\\age1_x1\\taitacmd.cpp", 12784) % count + 1;
            j = 1;
            if (world->player_num > 1) {
                do {
                    player = world->players[j];
                    if (player->computerPlayer() == 1) {
                        pick--;
                        if (pick == 0)
                            world->controllingComputerPlayer = (uchar) player->id;
                    }
                    j++;
                } while (j < world->player_num);
            }
        }
    }

    if (world->controllingComputerPlayer != (uchar) this->md->player->id)
        return;

    tempRand = this->sn[0xBB];
    for (i = 0; i < 4; i++) {
        if (tempRand <= 0)
            return;
        if (this->neededResourceValue[i] == 0 && this->md->resourceAI.resource(RGE_RESOURCE_FOOD) >= this->sn[0xBE])
            continue;
        if (this->neededResourceValue[i] == 1 && this->md->resourceAI.resource(RGE_RESOURCE_WOOD) >= this->sn[0xBF])
            continue;
        if (this->neededResourceValue[i] == 3 && this->md->resourceAI.resource(RGE_RESOURCE_GOLD) >= this->sn[0xC1])
            continue;
        if (this->neededResourceValue[i] == 2 && this->md->resourceAI.resource(RGE_RESOURCE_STONE) >= this->sn[0xC0])
            continue;
        if (this->neededResourceValue[i + 4] < 0) {
            for (j = 1; j < world->player_num; j++) {
                if (tempRand <= 0)
                    break;
                player = world->players[j];
                if (player->id != this->md->player->id && player->computerPlayer() != 0) {
                    if (this->md->player->isAlly(j) != 0) {
                        if (player->isAlly((int) this->md->player->id) != 0) {
                            short myid = this->md->player->id;
                            if ((myid < player->id && player->id != (short) world->controllingComputerPlayer)
                                || myid == (short) world->controllingComputerPlayer) {
                                int res = this->neededResourceValue[i];
                                amountDemandable = (int) player->attributes[res];
                                if (amountDemandable > 50) {
                                    if (amountDemandable > tempRand)
                                        amountDemandable = tempRand;
                                    tempRand -= amountDemandable;
                                    player->sendAICommand(myid, 1, res, amountDemandable, 0);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void TribeTacticalAIModule::checkForCoopTributeGift() {
    if (this->sn[0xBA] == -1)
        return;
    if (this->md->aiPlayer->objects->find_by_master_id(0x54, -1.0f, -1.0f, 0, RGE_OBJECT_STATE_ACTIVE, 0) == 0)
        return;

    int now = this->md->player->world->world_time;
    if ((int) (now - this->lastCoopTributeGiftTime) / 1000 < this->sn[0xBA])
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
            int pick = debug_rand(s_file, 12917) % num_computer + 1;
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
                    if (other->id != this->md->player->id && other->computerPlayer() != 0
                        && this->md->player->isAlly(j) != 0 && other->isAlly(this->md->player->id) != 0) {
                        float* attribute = other->attributes + i;
                        int minimumValue = other->strategicNumber(i + 0xbe);
                        if (*attribute < (float) minimumValue && (bestCP == -1 || *attribute < tributeAmount)) {
                            bestCP = other->id;
                            tributeAmount = *attribute;
                        }
                    }
                    ++j;
                } while (j < world->player_num);
            }
            if (bestCP != -1) {
                float amount = (float) (this->md->resourceAI.resource(i) - *minimum);
                TRIBE_Player* aiPlayer = this->md->aiPlayer;
                float current = aiPlayer->attributes[PLAYER_ATTRIBUTE_TRIBUTE_FEE];
                aiPlayer->command_give_attribute(bestCP, i, amount, current);
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

void TribeTacticalAIModule::checkForASAPAgeResearch() {
    if (this->inAge(1) != 0 && this->sn[0xB5] == 1 && this->md->buildAI.readyToResearch(2, 1) != 0
        && this->md->resourceAI.resource(RGE_RESOURCE_FOOD) >= 500) {
        BuildItem* item = this->md->buildAI.buildItem(0x65, BUILD_CATEGORY_RESEARCH, BUILD_CATEGORY_BLOCKING_RESEARCH);
        if (item != 0)
            this->taskResearch(item);
    } else if (this->inAge(2) != 0 && this->sn[0xB6] == 1 && this->md->buildAI.readyToResearch(3, 1) != 0
               && this->md->resourceAI.resource(RGE_RESOURCE_FOOD) >= 800) {
        BuildItem* item = this->md->buildAI.buildItem(0x66, BUILD_CATEGORY_RESEARCH, BUILD_CATEGORY_BLOCKING_RESEARCH);
        if (item != 0)
            this->taskResearch(item);
    }

    if (this->inAge(3) != 0 && this->sn[0xB7] == 1 && this->md->buildAI.readyToResearch(4, 1) != 0
        && this->md->resourceAI.resource(RGE_RESOURCE_FOOD) >= 900
        && this->md->resourceAI.resource(RGE_RESOURCE_GOLD) >= 700) {
        BuildItem* item = this->md->buildAI.buildItem(0x67, BUILD_CATEGORY_RESEARCH, BUILD_CATEGORY_BLOCKING_RESEARCH);
        if (item != 0)
            this->taskResearch(item);
    }
}

void TribeTacticalAIModule::checkForCoopAttack(int playerToAttack, int x, int y) {
    if (this->sn[0xC4] != 1)
        return;

    int now = this->md->player->world->world_time;
    if ((long) (now - this->lastCoopAttackDemandTime) / 1000 < this->sn[0xC5])
        return;
    this->lastCoopAttackDemandTime = now;

    TRIBE_World* world = static_cast<TRIBE_World*>(this->md->player->world);
    if (world->controllingComputerPlayer == 0xff) {
        int num_computer = 0;
        int i = 1;
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
            int pick = debug_rand(s_file, 13041) % num_computer + 1;
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

    int idx = 1;
    if (world->player_num <= 1)
        return;
    do {
        RGE_Player* other = world->players[idx];
        if (other->id != this->md->player->id && other->computerPlayer() != 0 && this->md->player->isAlly(idx) != 0
            && other->isAlly(this->md->player->id) != 0) {
            if ((this->md->player->id < other->id && other->id != world->controllingComputerPlayer)
                || this->md->player->id == world->controllingComputerPlayer) {
                other->sendAICommand(this->md->player->id, 2, playerToAttack, x, y);
            }
        }
        ++idx;
    } while (idx < world->player_num);
}

int TribeTacticalAIModule::processCoopAttack(int caller, int playerToAttack, int x, int y) {
    if (attackEnabledValue == 0) {
        return 0;
    }

    this->md->diplomacyAI.setStance(playerToAttack, 0, 100);

    int current;
    TacticalAIGroup* group = groups.next;
    TacticalAIGroup* sentinel = &groups;
    for (; group != sentinel; group = group->next) {
        if (group == 0)
            break;
        if (group->type() == TACTICAL_GROUP_TYPE_ATTACK || group->type() == TACTICAL_GROUP_TYPE_BOAT_ATTACK) {
            current = group->numberUnits();
            if (group->desiredNumberUnits() > current) {
                group->setDesiredNumberUnits(group->numberUnits());
            }
        }
    }

    return 1;
}

int TribeTacticalAIModule::resourceDifference(int n) {
    if (n < 0 || n > 3)
        return -1;
    return this->resourceDifferenceValue[this->neededResourceValue[n]];
}

int TribeTacticalAIModule::actualGathererCount(int n) {
    if (n < 0 || n > 3)
        return -1;
    return this->actualGathererDistribution[this->neededResourceValue[n]];
}

int TribeTacticalAIModule::actualGathererCountByRealResourceID(int n) {
    if (n < 0 || n > 3) {
        return -1;
    }
    return this->actualGathererDistribution[n];
}

int TribeTacticalAIModule::desiredGathererCount(int n) {
    if (n < 0 || n > 3)
        return -1;
    return this->desiredGathererDistribution[this->neededResourceValue[n]];
}

void* operator new(unsigned int size);
void operator delete(void* ptr);
void TribeTacticalAIModule::taskElephantGatherers(int mainHunterID, int numberToTask, int targetID) {
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
                    if (object != 0 && object->unitAI() != 0 && gatherer->data1 == 0) {
                        float distance = object->distance_to_object(targetObject);
                        if (bestDistance == -1.0f || bestDistance > distance) {
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
                bestValueID, targetID, 0, targetObject->world_x, targetObject->world_y
            );

            alreadyTasked.add(bestValueID);
            count++;
        }
    }
}

void* operator new(unsigned int size);
void operator delete(void* ptr);

void TribeTacticalAIModule::checkTradeBoats() {
    int i;
    i = 0;

    if (this->tradeBoats.numberValue > 0) {
        do {
            RGE_Static_Object* object = this->md->object(this->tradeBoats[i]);
            if (object != 0) {
                short attribute = object->attribute_type_held;
                if (this->md->resourceAI.resource((int) attribute) < this->sn[0xD8]) {
                    int resource = 2;
                    for (; resource >= 0; --resource) {
                        if (resource != attribute && this->md->resourceAI.resource(resource) >= this->sn[0xD8]) {
                            goto trade_attribute;
                        }
                    }

                    goto next_boat;

                trade_attribute:
                    this->md->aiPlayer->command_trade_attribute(this->tradeBoats[i], resource);
                }
            }

        next_boat:
            ++i;
        } while (i < this->tradeBoats.numberValue);
    }
}

int TribeTacticalAIModule::numberGatherersWithTarget(int targetID) {
    int count;
    int remaining;
    int* target;

    remaining = this->numberGatherersValue;
    count = 0;
    if (remaining > 0) {
        target = &this->gatherers[0].target;
        do {
            if (*target == targetID)
                count = count + 1;
            target = target + 6;
            remaining = remaining - 1;
        } while (remaining != 0);
    }
    return count;
}

void TribeTacticalAIModule::checkStaleAttackGroups() {
    TacticalAIGroup* group;
    TacticalAIGroup* sentinel;
    int numberUnits;
    int desiredNumberUnits;
    int missing;

    if (this->attackEnabledValue != 0) {
        group = this->groups.next;
        sentinel = &this->groups;
        while (group != sentinel && group != 0) {
            if (group->type() == TACTICAL_GROUP_TYPE_ATTACK && group->inUse() != 1) {
                numberUnits = group->numberUnits();
                desiredNumberUnits = group->desiredNumberUnits();
                missing = desiredNumberUnits - numberUnits;
                if (missing > 0) {
                    if (missing > 5)
                        missing = 5;
                    if ((int) (this->md->player->world->world_time - group->lastAddedUnitTimeValue) / 60000
                        >= missing) {
                        group->setDesiredNumberUnits(group->numberUnits());
                    }
                }
            }
            group = group->next;
        }
    }
}

int TribeTacticalAIModule::numberWaterExplorers() {
    TacticalAIGroup* group;
    TacticalAIGroup* sentinel;
    int count;

    count = 0;
    group = this->groups.next;
    sentinel = &this->groups;
    while (group != sentinel && group != 0) {
        if ((group->type() == TACTICAL_GROUP_TYPE_BOAT_ATTACK || group->type() == TACTICAL_GROUP_TYPE_BOAT_DEFEND
             || group->type() == TACTICAL_GROUP_TYPE_BOAT_EXPLORE || group->type() == TACTICAL_GROUP_TYPE_TRANSPORT
             || group->type() == TACTICAL_GROUP_TYPE_FISHING || group->type() == TACTICAL_GROUP_TYPE_TRADE)
            && group->action() == TACTICAL_GROUP_ACTION_EXPLORE) {
            count = count + 1;
        }
        group = group->next;
    }
    return count;
}

void TribeTacticalAIModule::saveTheTown(int idToKill) {
    ulong entryTime = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\taitacmd.cpp", 13344);
    RGE_Static_Object* targetObject;
    XYPoint objectPosition;
    int entryCount;
    int count;
    XYZPoint point;
    targetObject = this->md->object(idToKill);

    if (targetObject != 0) {
        objectPosition.x = (int) targetObject->world_x;
        objectPosition.y = (int) targetObject->world_y;

        TacticalAIGroup* group = this->readyAndIdleGroup(
            TACTICAL_GROUP_TYPE_ATTACK, this->sn[SNEnemySightedResponseDistance], objectPosition
        );
        if (group == 0)
            group = this->readyAndIdleGroup(
                TACTICAL_GROUP_TYPE_BOAT_ATTACK, this->sn[SNEnemySightedResponseDistance], objectPosition
            );

        if (group != 0) {
            int commanderID = group->commander();
            RGE_Static_Object* commanderObject = this->md->player->world->object(commanderID);
            if (commanderObject != 0) {
                point.x = (int) targetObject->world_x;
                point.y = (int) targetObject->world_y;
                point.z = (int) targetObject->world_z;
                if (commanderObject->canPath(point, commanderObject->weaponRange(), idToKill, 0, 1, -1, -1) == 1) {
                    group->setTarget(idToKill);
                    group->setTargetType((int) targetObject->master_obj->id);
                    group->setTargetLocation(targetObject->world_x, targetObject->world_y, targetObject->world_z);
                    group->setAction(TACTICAL_GROUP_ACTION_ATTACK);
                    group->task(this, this->md, TACTICAL_GROUP_ACTION_ATTACK, 1, 0);
                    return;
                }
            }
        }

        entryCount = 0;
        count = 0;
        if (this->soldiers.numberValue > 0) {
            while (count < this->soldiers.numberValue && entryCount < 6) {
                if (count > 1 && debug_timeGetTime("C:\\msdev\\work\\age1_x1\\taitacmd.cpp", 13383) - entryTime > 10)
                    return;

                RGE_Static_Object* object = this->md->aiPlayer->world->object(this->soldiers[count]);
                if (object != 0 && object->unitAI() != 0) {
                    if (object->unitAI()->currentAction() == UNIT_AI_ACTION_ATTACK) {
                        if (object->unitAI()->currentTarget() == -1)
                            goto trySoldier;
                        if (object->unitAI()->currentTarget() == targetObject->id)
                            goto countEntry;

                        RGE_Static_Object* currentTarget =
                            this->md->player->world->object(object->unitAI()->currentTarget());
                        if (currentTarget != 0 && currentTarget->owner->id == this->playersToAttack[0])
                            goto countSoldier;
                    } else {
                        goto trySoldier;
                    }

                trySoldier: {
                    if (object->distance_to_object(targetObject) < 25.0f) {
                        point.x = (int) targetObject->world_x;
                        point.y = (int) targetObject->world_y;
                        point.z = (int) targetObject->world_z;
                        if (object->canPath(point, object->weaponRange(), targetObject->id, 0, 1, -1, -1) != 0) {
                            if (this->taskAttacker(
                                    this->soldiers[count], targetObject->world_x, targetObject->world_y,
                                    targetObject->id, (int) targetObject->owner->id, 0, 0, -1, 0
                                )
                                == 1) {
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

        int unitID = this->civilian(objectPosition, 1, UNIT_AI_ORDER_ATTACK, -1000, -1000, 1);
        while (unitID != -1 && entryCount < 6) {
            RGE_Static_Object* object = this->md->object(unitID);
            if (object == 0)
                return;

            point.x = (int) targetObject->world_x;
            point.y = (int) targetObject->world_y;
            point.z = (int) targetObject->world_z;
            if (object->canPath(point, object->weaponRange(), idToKill, 0, 1, -1, -1) == 0)
                return;

            this->taskAttacker(
                unitID, targetObject->world_x, targetObject->world_y, idToKill, (int) targetObject->owner->id, 0, 0, -1,
                0
            );
            entryCount++;
            unitID = this->civilian(objectPosition, 1, UNIT_AI_ORDER_ATTACK, UNIT_AI_ORDER_HUNT, UNIT_AI_ORDER_HUNT, 1);
        }
    }
}
