#include "../include/aipbook.h"
#include "../include/stat_obj.h"
#include "../include/world.h"
#include <stdio.h>
#include <string.h>

extern void rge_read(int file, void* data, int size);
extern void rge_write(int file, void* data, int size);

extern char s_Move[];
extern char s_Attack[];
extern char s_AttackSavedTarget[];
extern char s_Retreat[];
extern char s_Heal[];
extern char s_ResetHitPoints[];
extern char s_ResetAliveCount[];
extern char s_Wait[];
extern char s_Invalid[];
extern char s_Gather[];
extern char s_Death[];
extern char s_HealthLost[];
extern char s_DamageToGroup[];
extern char s_DamageToAnyGroup[];
extern char s_Level1EnemySighted[];
extern char s_Level2EnemySighted[];
extern char s_DeathOfGroup[];
extern char s_HealOfGroup[];
extern char s_Immediate[];
extern char s_Time[];
extern char s_Annoy[];
extern char s_Flank[];
extern char s_Recon[];
extern char s_Any[];
extern char s_Stationary[];
extern char s_Moving[];
extern char s_Slow[];
extern char s_Fast[];
extern char s_NULL[];
extern char s_NONE[];
extern char s_592A40[];
extern char s_format_percent_s[];
extern char s_mode_r[];
extern char s_format_percent_s_space[];
extern char s_format_comment[];
extern char s_Play[];
extern char s_PlayType[];
extern char s_MinUnits[];
extern char s_MaxUnits[];
extern char s_Power[];
extern char s_Overflow[];
extern char s_Balance[];
extern char s_FirstGroup[];
extern char s_DeathPercentage[];
extern char s_Intelligence[];
extern char s_TargetChar[];
extern char s_TargetType[];
extern char s_NumberGroups[];
extern char s_Group[];
extern char s_Phase[];
extern char s_Trigger[];
extern char s_RTrigger[];
extern char s_EndPlay[];
extern char s_format_skip_string_int[];
extern char s_format_skip_string_string[];
extern char s_format_group_range[];
extern char s_format_command[];
extern char s_format_trigger[];
extern char s_format_play_variant[];

AIPlayPhaseCommand::AIPlayPhaseCommand() {
    this->groupValue = 0;
    this->typeValue = 0;
    this->value1Value = 0;
    this->value2Value = 0;
    this->value3Value = 0;
}

AIPlayPhaseCommand::AIPlayPhaseCommand(unsigned char group,
                                       unsigned char type,
                                       int value1,
                                       int value2,
                                       int value3) {
    this->groupValue = group;
    this->typeValue = type;
    this->value1Value = value1;
    this->value2Value = value2;
    this->value3Value = value3;
}

AIPlayPhaseCommand::AIPlayPhaseCommand(unsigned char group, char* text,
                                       int value1, int value2, int value3) {
    this->groupValue = group;
    this->typeValue = this->convertToIntType(text);
    this->value1Value = value1;
    this->value2Value = value2;
    this->value3Value = value3;
}

char* AIPlayPhaseCommand::nameType() const {
    return this->convertToNameType(this->typeValue);
}

unsigned char AIPlayPhaseCommand::convertToIntType(char* name) const {
    int r;
    r = strcmp(name, s_Move);
    if (r == 0) return 1;
    r = strcmp(name, s_Attack);
    if (r == 0) return 2;
    r = strcmp(name, s_AttackSavedTarget);
    if (r == 0) return 3;
    r = strcmp(name, s_Retreat);
    if (r == 0) return 4;
    r = strcmp(name, s_Heal);
    if (r == 0) return 5;
    r = strcmp(name, s_ResetHitPoints);
    if (r == 0) return 6;
    r = strcmp(name, s_ResetAliveCount);
    if (r == 0) return 7;
    r = strcmp(name, s_Wait);
    if (r == 0) return 8;
    return 0;
}

char* AIPlayPhaseCommand::convertToNameType(unsigned char value) const {
    switch (value) {
    case 1: return s_Move;
    case 2: return s_Attack;
    case 3: return s_AttackSavedTarget;
    case 4: return s_Retreat;
    case 5: return s_Heal;
    case 6: return s_ResetHitPoints;
    case 7: return s_ResetAliveCount;
    case 8: return s_Wait;
    default: return s_Invalid;
    }
}

AIPlayPhaseTrigger::AIPlayPhaseTrigger() {
    typeValue = 0;
    value1Value = -1;
    value2Value = -1;
    phaseValue = 0;
    nextPhaseValue = 0;
}

AIPlayPhaseTrigger::AIPlayPhaseTrigger(unsigned char type,
                                       int value1,
                                       int value2,
                                       unsigned char phase,
                                       unsigned char nextPhase,
                                       int randomness) {
    this->typeValue = type;
    this->value1Value = value1;
    this->value2Value = value2;
    this->phaseValue = phase;
    this->nextPhaseValue = nextPhase;
    this->randomnessValue = randomness;
}

AIPlayPhaseTrigger::AIPlayPhaseTrigger(char* text, int value1, int value2,
                                       unsigned char phase,
                                       unsigned char nextPhase,
                                       int randomness) {
    typeValue = convertToIntType(text);
    value1Value = value1;
    value2Value = value2;
    phaseValue = phase;
    nextPhaseValue = nextPhase;
    randomnessValue = randomness;
}

char* AIPlayPhaseTrigger::nameType() const {
    return this->convertToNameType(this->typeValue);
}

unsigned char AIPlayPhaseTrigger::convertToIntType(char* name) const {
    int r;
    r = strcmp(name, s_Gather);
    if (r == 0) return 1;
    r = strcmp(name, s_Death);
    if (r == 0) return 2;
    r = strcmp(name, s_HealthLost);
    if (r == 0) return 3;
    r = strcmp(name, s_DamageToGroup);
    if (r == 0) return 4;
    r = strcmp(name, s_DamageToAnyGroup);
    if (r == 0) return 5;
    r = strcmp(name, s_Level1EnemySighted);
    if (r == 0) return 6;
    r = strcmp(name, s_Level2EnemySighted);
    if (r == 0) return 7;
    r = strcmp(name, s_DeathOfGroup);
    if (r == 0) return 8;
    r = strcmp(name, s_HealOfGroup);
    if (r == 0) return 9;
    r = strcmp(name, s_Immediate);
    if (r == 0) return 10;
    r = strcmp(name, s_Time);
    if (r == 0) return 11;
    return 0;
}

char* AIPlayPhaseTrigger::convertToNameType(unsigned char value) const {
    switch (value) {
    case 1: return s_Gather;
    case 2: return s_Death;
    case 3: return s_HealthLost;
    case 4: return s_DamageToGroup;
    case 5: return s_DamageToAnyGroup;
    case 6: return s_Level1EnemySighted;
    case 7: return s_Level2EnemySighted;
    case 8: return s_DeathOfGroup;
    case 9: return s_HealOfGroup;
    case 10: return s_Immediate;
    case 11: return s_Time;
    default: return s_Invalid;
    }
}

AIPlayPhase::AIPlayPhase() {
    initialize();
}

AIPlayPhaseCommand* AIPlayPhase::command(int index) {
    if (index < 0 || index >= 5)
        return 0;
    return &this->commands[index];
}

AIPlayPhaseTrigger* AIPlayPhase::trigger(int index) {
    if ((index >= 0) && (index < 3)) {
        return &this->triggers[index];
    }
    return 0;
}

int AIPlayPhase::addCommand(AIPlayPhaseCommand& command) {
    int i = 0;
    while (i < 5) {
        if (this->commands[i].type() == 0) {
            AIPlayPhaseCommand* dest = &this->commands[i];
            dest->setGroup(command.group());
            dest->setType(command.type());
            dest->setValue1(command.value1());
            dest->setValue2(command.value2());
            dest->setValue3(command.value3());
            return 1;
        }
        i++;
    }
    return 0;
}

int AIPlayPhase::addTrigger(AIPlayPhaseTrigger& trigger) {
    int i = 0;
    while (i < 3) {
        if (this->triggers[i].type() == 0) {
            this->triggers[i].setType(trigger.type());
            this->triggers[i].setValue1(trigger.value1());
            this->triggers[i].setValue2(trigger.value2());
            this->triggers[i].setPhase(trigger.phase());
            this->triggers[i].setNextPhase(trigger.nextPhase());
            this->triggers[i].setRandomness(trigger.randomness());
            return 1;
        }
        i++;
    }
    return 0;
}

void AIPlayPhase::initialize() {
    int i;
    char* p;

    p = ((char*)this) + 1;
    for (i = 0; i < 5; i++) {
        *p = 0;
        p += 0x10;
    }

    p = ((char*)this) + 0x50;
    for (i = 0; i < 3; i++) {
        *p = 0;
        p += 0x14;
    }
}

AIPlayGroup::AIPlayGroup() {
    initialize();
}

unsigned char AIPlayGroup::minimum(int index) const {
    if (index < 0 || index >= 6) return 0;
    return this->minValue[index];
}

void AIPlayGroup::setMinimum(int index, int val) {
    if (index < 0 || index >= 6) return;
    this->minValue[index] = val;
}

unsigned char AIPlayGroup::maximum(int index) const {
    if (index >= 0 && index < 6)
        return maxValue[index];
    return 0xFF;
}

void AIPlayGroup::setMaximum(int index, int val) {
    if (index < 0 || index >= 6) return;
    this->maxValue[index] = val;
}

void AIPlayGroup::initialize() {
    for (int i = 0; i < 6; ++i) {
        this->minValue[i] = 0;
        this->maxValue[i] = 0xFE;
    }
}

AIPlay::AIPlay()
    : minimumNumberUnitsValue(1),
      maximumNumberUnitsValue(0xFF),
      typeValue(1),
      powerValue(0),
      overflowValue(1),
      intelligenceValue(0x32),
      deathPercentageValue(0x32) {
    for (int j = 0; j < 5; j++) {
        this->targetTypeValue[j] = 5;
        this->targetCharacteristicValue[j] = 5;
    }
}

void AIPlay::setName(char* name) {
    if (name) {
        strncpy(this->nameValue, name, 64);
    }
}

int AIPlay::humanPlay() const {
    if (this->nameValue[0] == 0x48 && this->nameValue[1] == 0x50) return 1;
    return 0;
}

char* AIPlay::typeName() const {
    return this->convertToNameType(this->typeValue);
}

unsigned char AIPlay::targetType(int index) const {
    if (index >= 0 && index < 5)
        return targetTypeValue[index];
    return 0;
}

int AIPlay::isTargetType(unsigned char type) const {
    for (int i = 0; i < 5; i++) {
        if (this->targetTypeValue[i] == type)
            return 1;
    }
    return 0;
}

int AIPlay::addTargetType(unsigned char type) {
    for (int i = 0; i < 5; i++) {
        if (this->targetTypeValue[i] == 0 ||
            this->targetTypeValue[i] == 5) {
            this->targetTypeValue[i] = type;
            return 1;
        }
    }
    return 0;
}

unsigned char AIPlay::targetCharacteristic(int index) const {
    if (index >= 0 && index < 5)
        return targetCharacteristicValue[index];
    return 0;
}

int AIPlay::isTargetCharacteristic(unsigned char characteristic) const {
    for (int i = 0; i < 5; i++) {
        if (this->targetCharacteristicValue[i] == characteristic)
            return 1;
    }
    return 0;
}

int AIPlay::addTargetCharacteristic(unsigned char characteristic) {
    for (int i = 0; i < 5; i++) {
        if (this->targetCharacteristicValue[i] == 0 ||
            this->targetCharacteristicValue[i] == 5) {
            this->targetCharacteristicValue[i] = characteristic;
            return 1;
        }
    }
    return 0;
}

int AIPlay::gatherTolerance(int, int param_2) {
    AIPlayPhase* phase_0 = phase(param_2);
    if (phase_0 == 0) {
        return 2;
    }

    int i = 0;
    while (i < 3) {
        AIPlayPhaseTrigger* trigger_0 = phase_0->trigger(i);
        if (trigger_0 != 0 && trigger_0->type() == 1) {
            return trigger_0->value1();
        }
        i++;
    }

    return 2;
}

AIPlayGroup* AIPlay::group(int index) {
    if (index < 0 || index >= 5) return 0;
    return &this->groups[index];
}

AIPlayPhase* AIPlay::phase(int index) {
    if (index >= 0 && index < 10)
        return this->phases + index;
    return 0;
}

int AIPlay::fillGroups(AIPlayStatus* status, int* units, int unitCount,
                       RGE_Game_World* world) {
    AIPlay* play = world->playbook->play(status->playNumberValue);
    if (play == 0) {
        return 0;
    }

    int unitsByTypeCount[6];
    int unitsByType[6][50];
    int minUnits = 1;
    int i;
    int overflowType;
    int overflowUnit;
    unsigned char maximumUnits;

    for (i = 0; i < 6; i++) {
        unitsByTypeCount[i] = 0;
    }

    for (i = 0; i < unitCount; i++) {
        RGE_Static_Object* object = world->object(units[i]);
        int type;
        if (object == 0 ||
            (type = world->playbook->convertUnitToIntType(object)) < 0 ||
            type >= 6) {
            minUnits = 0;
        } else {
            unitsByType[type][unitsByTypeCount[type]] = units[i];
            unitsByTypeCount[type]++;
        }
    }

    int groupNumber;
    for (groupNumber = 0; groupNumber < play->numberGroupsValue;
         groupNumber++) {
        AIPlayGroup* group = play->group(groupNumber);
        if (group == 0) {
            return 0;
        }

        for (int type = 0; type < 6; type++) {
            int minimum = group->minimum(type);
            if (minimum != 0) {
                int added = 0;
                for (int unit = 0;
                     unit < unitsByTypeCount[type] && added < minimum;
                     unit++) {
                    int& id = unitsByType[type][unit];
                    if (id != -1) {
                        if (status->addGrouping(id,
                                                (unsigned char)groupNumber,
                                                (unsigned char)type) == 1) {
                            added++;
                            maximumUnits = play->maximumNumberUnitsValue;
                            id = -1;
                            if (status->numberInPlay() == maximumUnits) {
                                goto CountDeviation;
                            }
                        } else {
                            minUnits = 0;
                        }
                    }
                }
            }
        }
    }

    for (overflowType = 0; overflowType < 6; overflowType++) {
        for (overflowUnit = 0;
             overflowUnit < unitsByTypeCount[overflowType];
             overflowUnit++) {
            int& id = unitsByType[overflowType][overflowUnit];
            if (id == -1) {
                continue;
            }

            if (this->overflowValue == 1) {
                int smallestGroup = -1;
                int smallestGroupSize = 0;

                for (groupNumber = 0;
                     groupNumber < play->numberGroupsValue;
                     groupNumber++) {
                    AIPlayGroup* group = play->group(groupNumber);
                    if (group != 0 &&
                        status->numberOfTypeInGroup(groupNumber,
                                                    overflowType) <
                            group->maximum(overflowType) &&
                        (smallestGroup == -1 ||
                         status->numberInGroup(groupNumber) <
                             smallestGroupSize)) {
                        smallestGroupSize =
                            status->numberInGroup(groupNumber);
                        smallestGroup = groupNumber;
                    }
                }

                if (smallestGroup != -1) {
                    if (status->addGrouping(id,
                                            (unsigned char)smallestGroup,
                                            (unsigned char)overflowType) == 1) {
                        maximumUnits = play->maximumNumberUnitsValue;
                        id = -1;
                        if (status->numberInPlay() == maximumUnits) {
                            goto CountDeviation;
                        }
                    } else {
                        minUnits = 0;
                    }
                }
            } else if (this->overflowValue == 2) {
                for (groupNumber = 0;
                     groupNumber < play->numberGroupsValue;
                     groupNumber++) {
                    AIPlayGroup* group = play->group(groupNumber);
                    if (group != 0 &&
                        status->numberOfTypeInGroup(groupNumber,
                                                    overflowType) <
                            group->maximum(overflowType)) {
                        if (status->addGrouping(id,
                                                (unsigned char)groupNumber,
                                                (unsigned char)overflowType) ==
                            1) {
                            maximumUnits = play->maximumNumberUnitsValue;
                            id = -1;
                            if (status->numberInPlay() == maximumUnits) {
                                goto CountDeviation;
                            }
                            break;
                        }
                        minUnits = 0;
                    }
                }
            }
        }
    }

CountDeviation:
    int deviation = 0;
    for (groupNumber = 0; groupNumber < play->numberGroupsValue;
         groupNumber++) {
        AIPlayGroup* group = play->group(groupNumber);
        if (group != 0) {
            for (int type = 0; type < 6; type++) {
                int minimum = group->minimum(type);
                int actual = status->numberOfTypeInGroup(groupNumber, type);
                if (actual < minimum) {
                    deviation += minimum - actual;
                }
            }
        }
    }
    status->deviationValue = (unsigned char)deviation;
    return minUnits;
}

int AIPlay::groupGivenCommandOnPhase(int groupValue, int typeValue,
                                     int phaseIndex) {
    if (groupValue < 0 || groupValue >= 5)
        return -1;
    if (phaseIndex < 0 || phaseIndex >= 10)
        return -1;

    int i = 0;
    AIPlayPhase* phase = &this->phases[phaseIndex];
    for (; i < 5; i++) {
        AIPlayPhaseCommand* cmd = phase->command(i);
        if ((unsigned int)cmd->group() == (unsigned int)groupValue) {
            AIPlayPhaseCommand* cmd2 = phase->command(i);
            int typeTemp;
            *(unsigned char*)&typeTemp = cmd2->type();
            if ((typeTemp & 0xff) == typeValue) {
                return i;
            }
        }
    }
    return -1;
}

unsigned char AIPlay::convertToIntType(char* name) const {
    int r;
    r = strcmp(name, s_Attack);
    if (r == 0) return 1;
    r = strcmp(name, s_Annoy);
    if (r == 0) return 2;
    r = strcmp(name, s_Flank);
    if (r == 0) return 3;
    r = strcmp(name, s_Recon);
    if (r == 0) return 4;
    return 0;
}

char* AIPlay::convertToNameType(unsigned char value) const {
    switch (value) {
    case 1: return "Attack";
    case 2: return "Annoy";
    case 3: return "Flank";
    case 4: return "Recon";
    default: return "Invalid";
    }
}

int AIPlay::locationsOnMap(int x1, int y1, int x2, int y2) {
    int phaseIdx = 0;
    AIPlayPhase* phase = &this->phases[0];

    while (phaseIdx < 10) {
        int cmdIdx = 0;
        while (cmdIdx < 5) {
            AIPlayPhaseCommand* cmd = phase->command(cmdIdx);
            if (cmd->type() == 1) {
                int px = cmd->value1() + x1;
                int py = cmd->value2() + y1;
                if (px < 0 || py < 0 || px >= x2 || py >= y2) {
                    return 0;
                }
            }
            cmdIdx++;
        }
        phase++;
        phaseIdx++;
    }
    return 1;
}

AIPlayStatus::AIPlayStatus()
    : playNumberValue(-1),
      targetValue(-1),
      originalPointValue(0, 0, 0) {
    int i;

    this->currentPhaseValue = 0xFD;
    this->savedAttackerValue = -1;
    this->lastPhaseChangeTimeValue = 0;
    this->deviationValue = 0;

    for (i = 0; i < 50; i++) {
        this->groupings[i].id = -1;
        this->groupings[i].groupID = 0xFF;
        this->groupings[i].type = 0xFF;
    }

    for (int j = 0; j < 5; j++) {
        this->originalHitPointsValue[j] = -1;
    }
}

int AIPlayStatus::originalHitPoints(int index) const {
    if (index < 0 || index >= 5) return -1;
    return this->originalHitPointsValue[index];
}

void AIPlayStatus::setOriginalHitPoints(int index, int val) {
    if (index < 0 || index >= 5) return;
    this->originalHitPointsValue[index] = val;
}

unsigned char AIPlayStatus::numberInPlay(void) const {
    unsigned char count = 0;
    for (int i = 0; i < 50; i++) {
        if (this->groupings[i].id != -1) {
            count++;
        }
    }
    return count;
}

unsigned char AIPlayStatus::numberInGroup(int groupIndex) {
    unsigned char count = 0;
    AIPlayStatus::GroupingStruct* entry = this->groupings;
    int remaining = 50;
    do {
        if (entry->id != -1) {
            if (entry->groupID == groupIndex)
                count++;
        }
        entry++;
        remaining--;
    } while (remaining);
    return count;
}

unsigned char AIPlayStatus::numberOfTypeInGroup(int param_1, int param_2) {
    unsigned char count = 0;
    for (int i = 0; i < 50; i++) {
        const GroupingStruct& g = this->groupings[i];
        if ((g.id != -1) && (g.groupID == param_1) &&
            (g.type == param_2)) {
            count++;
        }
    }
    return count;
}

unsigned char AIPlayStatus::group(int id) {
    if (id < 0)
        return 0xFF;
    for (int i = 0; i < 50; i++) {
        if (this->groupings[i].id == id)
            return this->groupings[i].groupID;
    }
    return 0xFF;
}

int AIPlayStatus::addGrouping(int id, unsigned char GroupID,
                              unsigned char type) {
    for (int i = 0; i < 50; i++) {
        if (this->groupings[i].id == -1) {
            this->groupings[i].id = id;
            this->groupings[i].groupID = GroupID;
            this->groupings[i].type = type;
            return 1;
        }
    }
    return 0;
}

int AIPlayStatus::removeGrouping(int id) {
    for (int i = 0; i < 50; i++) {
        if (this->groupings[i].id == id) {
            this->groupings[i].id = -1;
            this->groupings[i].groupID = 0xFF;
            this->groupings[i].type = 0xFF;
            return 1;
        }
    }
    return 0;
}

void AIPlayStatus::zeroAllGroupings() {
    int i;

    for (i = 0; i < 0x32; i++) {
        groupings[i].id = -1;
        groupings[i].groupID = 0xFF;
        groupings[i].type = 0xFF;
    }
}

void AIPlayStatus::copyUnits(int* units, int& count) {
    AIPlayStatus::GroupingStruct* grouping = this->groupings;
    int i = 0x32;

    count = 0;
    do {
        int id = grouping->id;
        if (id != -1) {
            units[count] = id;
            count = count + 1;
        }
        grouping = grouping + 1;
        i = i - 1;
    } while (i != 0);
}

void AIPlayStatus::load(int file) {
    int iVar1 = file;

    rge_read(file, &playNumberValue, 4);
    rge_read(iVar1, &targetValue, 4);
    rge_read(iVar1, &file, 4);
    originalPointValue.xValue = file;
    rge_read(iVar1, &file, 4);
    originalPointValue.yValue = file;
    rge_read(iVar1, &file, 4);
    originalPointValue.zValue = file;
    rge_read(iVar1, originalHitPointsValue, 20);
    rge_read(iVar1, &currentPhaseValue, 1);
    rge_read(iVar1, this, 400);
    rge_read(iVar1, &savedAttackerValue, 4);
    rge_read(iVar1, &lastPhaseChangeTimeValue, 4);
}

void AIPlayStatus::save(int file) {
    int iVar1 = file;

    rge_write(file, &playNumberValue, 4);
    rge_write(iVar1, &targetValue, 4);
    file = originalPointValue.xValue;
    rge_write(iVar1, &file, 4);
    file = originalPointValue.yValue;
    rge_write(iVar1, &file, 4);
    file = originalPointValue.zValue;
    rge_write(iVar1, &file, 4);
    rge_write(iVar1, originalHitPointsValue, 20);
    rge_write(iVar1, &currentPhaseValue, 1);
    rge_write(iVar1, this, 400);
    rge_write(iVar1, &savedAttackerValue, 4);
    rge_write(iVar1, &lastPhaseChangeTimeValue, 4);
}

// order before the grouping loop. The copy order and memory effects match.
void AIPlayStatus::copy(AIPlayStatus* other) {
    int count = 50;
    this->playNumberValue = other->playNumberValue;
    this->targetValue = other->targetValue;
    int z = other->originalPointValue.zValue;
    int y = other->originalPointValue.yValue;
    int x = other->originalPointValue.xValue;
    this->originalPointValue.xValue = x;
    this->originalPointValue.yValue = y;
    this->originalPointValue.zValue = z;
    this->currentPhaseValue = other->currentPhaseValue;
    this->savedAttackerValue = other->savedAttackerValue;

    AIPlayStatus* p = other;
    this->lastPhaseChangeTimeValue = p->lastPhaseChangeTimeValue;
    unsigned char* dest = (unsigned char*)this + 4;
    int diff = (unsigned char*)p - (unsigned char*)this;
    unsigned char* src = (unsigned char*)p;

    do {
        *(int*)(dest - 4) = *(int*)src;
        src += 8;
        *dest = *(dest + diff);
        *(dest + 1) = *(src - 3);
        dest += 8;
        count--;
    } while (count);

    int* hpDest = &this->originalHitPointsValue[0];
    int hpCount = 5;
    do {
        *hpDest = *(int*)((unsigned char*)hpDest + diff);
        hpDest++;
        hpCount--;
    } while (hpCount);
}

void AIPlayStatus::removeDeadUnits(int, RGE_Game_World* world) {
    GroupingStruct* g = &this->groupings[0];
    for (int i = 0; i < 50; i++, g++) {
        if (g->id != -1) {
            RGE_Static_Object* obj = world->object(g->id);
            if (obj == 0 || obj->object_state > 2) {
                g->id = -1;
                g->groupID = 0xFF;
                g->type = 0xFF;
            }
        }
    }
}

void AIPlayStatus::resetHitPoints(int param_1, RGE_Game_World* world) {
    int total = 0;
    AIPlayStatus* p = this;
    int count = 50;

    do {
        int id = p->groupings[0].id;
        if (id != -1) {
            if (p->groupings[0].groupID == param_1) {
                RGE_Static_Object* obj = world->object(id);
                if (obj != 0) {
                    total += (int)obj->hp;
                }
            }
        }
        p = (AIPlayStatus*)(p->groupings + 1);
        count--;
    } while (count != 0);

    setOriginalHitPoints(param_1, total);
}

AIPlayBook::AIPlayBook()
    : numberPlaysValue(0),
      plays(0) {
}

AIPlayBook::~AIPlayBook() {
    if (this->plays) {
        this->numberPlaysValue = 0;
        delete[] this->plays;
        this->plays = 0;
    }
}

int AIPlayBook::loadPlays(char* filename) {
    if (filename == 0 || strcmp(filename, s_NONE) == 0) {
        if (filename == 0)
            strcpy(this->nameValue, s_NULL);
        else
            strcpy(this->nameValue, s_NONE);
        return 0;
    }

    strncpy(this->nameValue, filename, 64);

    char line[256];
    char word[256];
    char text[256];
    sprintf(line, s_format_percent_s, this->nameValue);
    FILE* fileIn = fopen(line, s_mode_r);
    if (fileIn == 0)
        return 0;

    if (this->plays != 0) {
        delete[] this->plays;
        this->plays = 0;
    }

    this->numberPlaysValue = 0;
    while (fgets(line, 256, fileIn) != 0) {
        if (strlen(line) != 0) {
            sscanf(line, s_format_percent_s_space, word);
            if (strcmp(word, s_Play) == 0)
                this->numberPlaysValue += 8;
        }
    }

    if (this->numberPlaysValue > 16000)
        this->numberPlaysValue = 16000;

    this->plays = new AIPlay[this->numberPlaysValue];
    if (this->plays == 0)
        return 0;

    rewind(fileIn);

    int currentPlay = -1;
    int currentPhase = -1;
    while (fgets(line, 256, fileIn) != 0) {
        if (strlen(line) == 0)
            continue;

        strcpy(word, s_592A40);
        strcpy(text, s_592A40);

        int value1 = 0;
        int value2 = 0;
        int value3 = 0;
        int value4 = 0;
        int value5 = 0;
        char comment1;
        char comment2;

        if (sscanf(line, s_format_comment, &comment1, &comment2) != -1 &&
            (comment1 != '/' || comment2 != '/')) {
            sscanf(line, s_format_percent_s_space, word);

            if (strcmp(word, s_Play) == 0) {
                int firstQuote = 0;
                while (line[firstQuote] != '"')
                    firstQuote++;
                firstQuote++;

                int lastQuote = firstQuote;
                while (line[lastQuote] != '"')
                    lastQuote++;

                int length = lastQuote - firstQuote;
                if (firstQuote < lastQuote)
                    memcpy(word, line + firstQuote, length);
                word[length] = 0;

                currentPlay++;
                if (currentPlay >= 16000)
                    break;
                this->plays[currentPlay].setName(word);
            }
            else if (strcmp(word, s_PlayType) == 0 && currentPlay != -1) {
                sscanf(line, s_format_skip_string_string, word);
                this->plays[currentPlay].typeValue =
                    this->plays[currentPlay].convertToIntType(word);
            }
            else if (strcmp(word, s_MinUnits) == 0 && currentPlay != -1) {
                sscanf(line, s_format_skip_string_int, &value1);
                this->plays[currentPlay].minimumNumberUnitsValue = value1;
            }
            else if (strcmp(word, s_MaxUnits) == 0 && currentPlay != -1) {
                sscanf(line, s_format_skip_string_int, &value1);
                this->plays[currentPlay].maximumNumberUnitsValue = value1;
            }
            else if (strcmp(word, s_Power) == 0 && currentPlay != -1) {
                sscanf(line, s_format_skip_string_int, &value1);
                this->plays[currentPlay].powerValue = value1;
            }
            else if (strcmp(word, s_Overflow) == 0 && currentPlay != -1) {
                sscanf(line, s_format_skip_string_string, word);
                if (strcmp(word, s_Balance) == 0)
                    this->plays[currentPlay].overflowValue = 1;
                else if (strcmp(word, s_FirstGroup) == 0)
                    this->plays[currentPlay].overflowValue = 2;
            }
            else if (strcmp(word, s_DeathPercentage) == 0 &&
                     currentPlay != -1) {
                sscanf(line, s_format_skip_string_int, &value1);
                if (value1 < 0)
                    this->plays[currentPlay].deathPercentageValue = 0;
                else if (value1 > 100)
                    this->plays[currentPlay].deathPercentageValue = 100;
                else
                    this->plays[currentPlay].deathPercentageValue = value1;
            }
            else if (strcmp(word, s_Intelligence) == 0 &&
                     currentPlay != -1) {
                sscanf(line, s_format_skip_string_int, &value1);
                if (value1 < 0)
                    this->plays[currentPlay].intelligenceValue = 0;
                else if (value1 > 100)
                    this->plays[currentPlay].intelligenceValue = 100;
                else
                    this->plays[currentPlay].intelligenceValue = value1;
            }
            else if (strcmp(word, s_TargetChar) == 0 && currentPlay != -1) {
                sscanf(line, s_format_skip_string_string, text);
                int type = this->convertTargetCharacteristicNameToIntType(text);
                if (type != 0)
                    this->plays[currentPlay].addTargetCharacteristic(type);
            }
            else if (strcmp(word, s_TargetType) == 0 && currentPlay != -1) {
                sscanf(line, s_format_skip_string_string, text);
                int type = this->convertTargetNameToIntType(text);
                if (type != 0)
                    this->plays[currentPlay].addTargetType(type);
            }
            else if (strcmp(word, s_NumberGroups) == 0 && currentPlay != -1) {
                sscanf(line, s_format_skip_string_int, &value1);
                this->plays[currentPlay].numberGroupsValue = value1;
            }
            else if (strcmp(word, s_Group) == 0 && currentPlay != -1 &&
                     currentPhase == -1) {
                sscanf(line, s_format_group_range, &value1, text, &value2,
                       &value3);
                if (value1 >= 0 && value1 < 5) {
                    int type = this->convertUnitNameToIntType(text);
                    if (type != -1) {
                        AIPlayGroup* group =
                            this->plays[currentPlay].group(value1);
                        if (value3 < 0)
                            group->setMinimum(type, 0);
                        else
                            group->setMinimum(type, value2);

                        if (value3 > 50)
                            group->setMaximum(type, 50);
                        else
                            group->setMaximum(type, value3);
                    }
                }
            }
            else if (strcmp(word, s_Phase) == 0 && currentPlay != -1) {
                sscanf(line, s_format_skip_string_int, &value1);
                currentPhase = value1;
            }
            else if (strcmp(word, s_Group) == 0 && currentPlay != -1 &&
                     currentPhase != -1) {
                sscanf(line, s_format_command, &value1, text, &value2,
                       &value3, &value4);
                if (value1 >= 0 && value1 < 5) {
                    AIPlayPhase* phase =
                        this->plays[currentPlay].phase(currentPhase);
                    AIPlayPhaseCommand command((unsigned char)value1, text,
                                               value2, value3, value4);
                    phase->addCommand(command);
                }
            }
            else if (strcmp(word, s_Trigger) == 0 && currentPlay != -1 &&
                     currentPhase != -1) {
                sscanf(line, s_format_trigger, &value1, text, &value2,
                       &value5);
                AIPlayPhase* phase =
                    this->plays[currentPlay].phase(currentPhase);
                AIPlayPhaseTrigger trigger(text, value2, value5,
                                           (unsigned char)currentPhase,
                                           (unsigned char)value1, 0);
                phase->addTrigger(trigger);
            }
            else if (strcmp(word, s_RTrigger) == 0 && currentPlay != -1 &&
                     currentPhase != -1) {
                sscanf(line, s_format_command, &value1, text, &value2,
                       &value5, &value4);
                AIPlayPhase* phase =
                    this->plays[currentPlay].phase(currentPhase);
                AIPlayPhaseTrigger trigger(text, value2, value5,
                                           (unsigned char)currentPhase,
                                           (unsigned char)value1, value4);
                phase->addTrigger(trigger);
            }
            else if (strcmp(word, s_EndPlay) == 0 && currentPlay != -1) {
                currentPhase = -1;
                strcpy(word, this->plays[currentPlay].nameValue);
                if (word[0] == 'H' && word[1] == 'P') {
                    this->numberPlaysValue -= 7;
                }
                else {
                    int sourcePlay = currentPlay;
                    currentPlay += 7;
                    for (int facet = 1; facet < 8; facet++) {
                        AIPlay* source = &this->plays[sourcePlay];
                        AIPlay* destination = &this->plays[sourcePlay + facet];

                        sprintf(word, s_format_play_variant,
                                source->nameValue, facet);
                        destination->setName(word);
                        destination->typeValue = source->typeValue;
                        destination->minimumNumberUnitsValue =
                            source->minimumNumberUnitsValue;
                        destination->maximumNumberUnitsValue =
                            source->maximumNumberUnitsValue;
                        destination->powerValue = source->powerValue;
                        destination->overflowValue = source->overflowValue;
                        destination->deathPercentageValue =
                            source->deathPercentageValue;
                        destination->intelligenceValue =
                            source->intelligenceValue;

                        for (int iTargets = 0; iTargets < 5; iTargets++) {
                            destination->addTargetType(
                                source->targetType(iTargets));
                            destination->addTargetCharacteristic(
                                source->targetCharacteristic(iTargets));
                        }
                        destination->numberGroupsValue =
                            source->numberGroupsValue;

                        for (int iGroups = 0; iGroups < 5; iGroups++) {
                            AIPlayGroup* sourceGroup = source->group(iGroups);
                            AIPlayGroup* destinationGroup =
                                destination->group(iGroups);
                            for (int jTypes = 0; jTypes < 6; jTypes++) {
                                destinationGroup->setMinimum(
                                    jTypes, sourceGroup->minimum(jTypes));
                                destinationGroup->setMaximum(
                                    jTypes, sourceGroup->maximum(jTypes));
                            }
                        }

                        for (int iPhases = 0; iPhases < 10; iPhases++) {
                            AIPlayPhase* sourcePhase = source->phase(iPhases);
                            AIPlayPhase* destinationPhase =
                                destination->phase(iPhases);
                            for (int jCommands = 0; jCommands < 5;
                                 jCommands++) {
                                AIPlayPhaseCommand* command =
                                    sourcePhase->command(jCommands);
                                if (command->type() == 1) {
                                    XYZ origin(0, 0, 0);
                                    XYZ rotatedPoint;
                                    XYZ originalPoint(command->value1(),
                                                      command->value2(),
                                                      command->value3());
                                    originalPoint.rotateXYByFacet(
                                        origin, rotatedPoint,
                                        (unsigned char)facet);
                                    AIPlayPhaseCommand newCommand(
                                        command->group(), command->type(),
                                        rotatedPoint.xValue,
                                        rotatedPoint.yValue,
                                        rotatedPoint.zValue);
                                    destinationPhase->addCommand(newCommand);
                                }
                                else {
                                    destinationPhase->addCommand(*command);
                                }
                            }

                            for (int jTriggers = 0; jTriggers < 3;
                                 jTriggers++) {
                                AIPlayPhaseTrigger* trigger =
                                    sourcePhase->trigger(jTriggers);
                                destinationPhase->addTrigger(*trigger);
                            }
                        }
                    }
                }
            }
        }

        if (currentPlay >= 16000)
            break;
    }

    fclose(fileIn);
    return 1;
}

AIPlay* AIPlayBook::play(int index) {
    if (this->plays != 0 && index >= 0 && index < this->numberPlaysValue)
        return this->plays + index;
    return 0;
}

AIPlay* AIPlayBook::play(char* name) {
    if (this->plays == 0) return 0;
    for (int i = 0; i < this->numberPlaysValue; i++) {
        if (strcmp(this->plays[i].nameValue, name) == 0) {
            return &this->plays[i];
        }
    }
    return 0;
}

int AIPlayBook::playNumber(char* name) {
    if (this->plays == 0) {
        return -1;
    }

    int n = this->numberPlaysValue;
    for (int i = 0; i < n; i++) {
        if (strcmp(this->plays[i].nameValue, name) == 0) {
            return i;
        }
    }

    return -1;
}

int AIPlayBook::convertTargetNameToIntType(char* name) const {
    int r;
    r = strcmp(name, s_Any);
    if (r == 0) return 5;
    return 0;
}

int AIPlayBook::convertTargetCharacteristicNameToIntType(char* name) const {
    int r;
    r = strcmp(name, s_Stationary);
    if (r == 0) return 1;
    r = strcmp(name, s_Moving);
    if (r == 0) return 2;
    r = strcmp(name, s_Slow);
    if (r == 0) return 3;
    r = strcmp(name, s_Fast);
    if (r == 0) return 4;
    r = strcmp(name, s_Any);
    if (r == 0) return 5;
    return 0;
}

int AIPlayBook::convertUnitNameToIntType(char* name) const {
    return -1;
}

int AIPlayBook::convertUnitToIntType(RGE_Static_Object* object) const {
    return -1;
}
