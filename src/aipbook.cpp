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

// surface, grouping order, capacity stop, and deviation calculation.
int AIPlay::fillGroups(AIPlayStatus* playStatus, int* groupMembers,
                       int numberGroupMembers, RGE_Game_World* world) {
    AIPlay* play;
    int deviation;
    int i;
    int rVal;
    int unitsByTypeCount[6];
    int unitsByType[6][50];
    int j;
    AIPlayGroup* group;
    int minUnits;
    int numAssigned;
    int a;
    int smallestGroupSize;
    int k;
    RGE_Static_Object* object;

    play = world->playbook->play(playStatus->playNumberValue);

    if (play == 0) {
        return 0;
    }

    minUnits = 1;
    for (i = 0; i < 6; i++) {
        unitsByTypeCount[i] = 0;
    }

    if (numberGroupMembers > 0) {
        for (i = 0; i < numberGroupMembers; i++) {
            object = world->object(groupMembers[i]);
            if (object == 0) {
                minUnits = 0;
            } else {
                a = world->playbook->convertUnitToIntType(object);
                if (a < 0 || a >= 6) {
                    minUnits = 0;
                } else {
                    j = unitsByTypeCount[a];
                    unitsByType[a][j] = groupMembers[i];
                    unitsByTypeCount[a] = j + 1;
                }
            }
        }
    }

    i = 0;
    while (i < play->numberGroupsValue) {
        group = play->group(i);
        if (group == 0) {
            return 0;
        }

        j = 0;
        rVal = 0;
        do {
            a = group->minimum(j);
            if (a != 0) {
                numAssigned = 0;
                smallestGroupSize = unitsByTypeCount[j];
                for (k = 0; k < smallestGroupSize && numAssigned < a; k++) {
                    if (unitsByType[j][k] != -1) {
                        if (playStatus->addGrouping(
                                unitsByType[j][k], (unsigned char)i,
                                (unsigned char)j) == 1) {
                            numAssigned++;
                            unitsByType[j][k] = -1;
                            if (playStatus->numberInPlay() ==
                                play->maximumNumberUnitsValue) {
                                goto CountDeviation;
                            }
                        } else {
                            minUnits = 0;
                        }
                    }
                }
            }
            rVal += 50;
            j++;
        } while (rVal < 300);
        i++;
    }

    i = 0;
    rVal = 0;
    do {
        a = unitsByTypeCount[i];
        for (k = 0; k < a; k++) {
            if (unitsByType[i][k] == -1) {
                continue;
            }

            if (this->overflowValue == 1) {
                numAssigned = -1;
                smallestGroupSize = 0;

                for (j = 0; j < play->numberGroupsValue; j++) {
                    group = play->group(j);
                    if (group != 0) {
                        if (playStatus->numberOfTypeInGroup(j, i) <
                                group->maximum(i) &&
                            (numAssigned == -1 ||
                             playStatus->numberInGroup(j) <
                                 smallestGroupSize)) {
                            smallestGroupSize = playStatus->numberInGroup(j);
                            numAssigned = j;
                        }
                    }
                }

                if (numAssigned != -1) {
                    if (playStatus->addGrouping(
                            unitsByType[i][k], (unsigned char)numAssigned,
                            (unsigned char)i) == 1) {
                        unitsByType[i][k] = -1;
                        if (playStatus->numberInPlay() ==
                            play->maximumNumberUnitsValue) {
                            goto CountDeviation;
                        }
                    } else {
                        minUnits = 0;
                    }
                }
            } else if (this->overflowValue == 2) {
                for (j = 0; j < play->numberGroupsValue; j++) {
                    group = play->group(j);
                    if (group != 0) {
                        if (playStatus->numberOfTypeInGroup(j, i) <
                                group->maximum(i)) {
                            if (playStatus->addGrouping(
                                    unitsByType[i][k], (unsigned char)j,
                                    (unsigned char)i) == 1) {
                                unitsByType[i][k] = -1;
                                if (playStatus->numberInPlay() ==
                                    play->maximumNumberUnitsValue) {
                                    goto CountDeviation;
                                }
                                break;
                            } else {
                                minUnits = 0;
                            }
                        }
                    }
                }
            }
        }
        i++;
        rVal += 200;
    } while (i < 6);

CountDeviation:
    deviation = 0;
    i = 0;
    while (i < play->numberGroupsValue) {
        group = play->group(i);
        if (group != 0) {
            for (j = 0; j < 6; j++) {
                a = group->minimum(j);
                rVal = playStatus->numberOfTypeInGroup(i, j);
                if (rVal < a) {
                    deviation += a - rVal;
                }
            }
        }
        i++;
    }

    playStatus->deviationValue = (unsigned char)deviation;
    return minUnits;
}

int AIPlay::groupGivenCommandOnPhase(int groupValue, int typeValue,
                                     int phaseIndex) {
    int type = typeValue;
    if (groupValue < 0 || groupValue >= 5)
        return -1;
    if (phaseIndex < 0 || phaseIndex >= 10)
        return -1;

    AIPlayPhase* phase = &this->phases[phaseIndex];
    for (int i = 0; i < 5; i++) {
        AIPlayPhaseCommand* cmd = phase->command(i);
        if ((unsigned int)cmd->group() == (unsigned int)groupValue) {
            AIPlayPhaseCommand* cmd2 = phase->command(i);
            *(unsigned char*)&groupValue = cmd2->type();
            if ((groupValue & 0xff) == type) {
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
    int temp4;
    int phaseValue1;
    int currentPhase;
    int phaseState;
    int j;
    int groupPhase;
    int currentPlay;
    int refPhase;
    int i;
    int temp8;
    int temp7;
    int fileValue;
    FILE* file;
    char temp2[0x100];
    char temp[0x100];
    char temp6[0x100];

    if (filename == 0 || strcmp(filename, s_NONE) == 0) {
        strcpy(this->nameValue, filename != 0 ? s_NONE : s_NULL);
        return 0;
    }

    strncpy(this->nameValue, filename, 0x40);
    sprintf(temp + 4, s_format_percent_s, this->nameValue);
    file = fopen(temp + 4, s_mode_r);
    if (file == 0) {
        return 0;
    }

    if (this->plays != 0) {
        delete[] this->plays;
        this->plays = 0;
    }
    this->numberPlaysValue = 0;

    while (fgets(temp + 4, 0x100, file) != 0) {
        if (strlen(temp + 4) == 0) {
            continue;
        }

        sscanf(temp + 4, s_format_percent_s_space, temp2 + 4);
        if (strcmp(temp2 + 4, s_Play) == 0) {
            this->numberPlaysValue += 8;
        }
    }

    if (this->numberPlaysValue > 0x3E80) {
        this->numberPlaysValue = 0x3E80;
    }

    this->plays = new AIPlay[this->numberPlaysValue];
    if (this->plays == 0) {
        return 0;
    }

    rewind(file);
    refPhase = -1;
    phaseState = -1;

    while (refPhase < 0x3E80 && fgets(temp + 4, 0x100, file) != 0) {
        if (strlen(temp + 4) == 0) {
            continue;
        }

        strcpy(temp2 + 4, s_592A40);
        strcpy(temp6 + 4, s_592A40);
        temp4 = 0;
        phaseValue1 = 0;
        i = 0;
        fileValue = 0;
        temp7 = 0;

        if (sscanf(temp + 4, s_format_comment,
                  ((char*)&j) + 3, ((char*)&currentPhase) + 3) == -1) {
            continue;
        }
        if (((char*)&j)[3] == '/' && ((char*)&currentPhase)[3] == '/') {
            continue;
        }

        sscanf(temp + 4, s_format_percent_s_space, temp2 + 4);
        if (strcmp(temp2 + 4, s_Play) == 0) {
            temp4 = 0;
            i = 0;
            while (temp[i + 4] != '"') {
                ++i;
                ++temp4;
            }
            ++i;
            ++temp4;

            phaseValue1 = temp4;
            while (temp[i + 4] != '"') {
                ++i;
                ++phaseValue1;
            }

            if (temp4 < phaseValue1) {
                memcpy(temp2 + 4, temp + temp4 + 4, phaseValue1 - temp4);
            }
            temp2[4 + (phaseValue1 - temp4)] = 0;

            ++refPhase;
            if (refPhase >= 0x3E80) {
                break;
            }
            this->plays[refPhase].setName(temp2 + 4);
        } else if (strcmp(temp2 + 4, s_PlayType) == 0 && refPhase != -1) {
            sscanf(temp + 4, s_format_skip_string_string, temp2 + 4);
            this->plays[refPhase].typeValue =
                this->plays[refPhase].convertToIntType(temp2 + 4);
        } else if (strcmp(temp2 + 4, s_MinUnits) == 0 && refPhase != -1) {
            sscanf(temp + 4, s_format_skip_string_int, &temp4);
            this->plays[refPhase].minimumNumberUnitsValue = (unsigned char)temp4;
        } else if (strcmp(temp2 + 4, s_MaxUnits) == 0 && refPhase != -1) {
            sscanf(temp + 4, s_format_skip_string_int, &temp4);
            this->plays[refPhase].maximumNumberUnitsValue = (unsigned char)temp4;
        } else if (strcmp(temp2 + 4, s_Power) == 0 && refPhase != -1) {
            sscanf(temp + 4, s_format_skip_string_int, &temp4);
            this->plays[refPhase].powerValue = (unsigned char)temp4;
        } else if (strcmp(temp2 + 4, s_Overflow) == 0 && refPhase != -1) {
            sscanf(temp + 4, s_format_skip_string_string, temp2 + 4);
            if (strcmp(temp2 + 4, s_Balance) == 0) {
                this->plays[refPhase].overflowValue = 1;
            } else if (strcmp(temp2 + 4, s_FirstGroup) == 0) {
                this->plays[refPhase].overflowValue = 2;
            }
        } else if (strcmp(temp2 + 4, s_DeathPercentage) == 0 && refPhase != -1) {
            sscanf(temp + 4, s_format_skip_string_int, &temp4);
            if (temp4 < 0) {
                this->plays[refPhase].deathPercentageValue = 0;
            } else if (temp4 > 100) {
                this->plays[refPhase].deathPercentageValue = 100;
            } else {
                this->plays[refPhase].deathPercentageValue = (unsigned char)temp4;
            }
        } else if (strcmp(temp2 + 4, s_Intelligence) == 0 && refPhase != -1) {
            sscanf(temp + 4, s_format_skip_string_int, &temp4);
            if (temp4 < 0) {
                this->plays[refPhase].intelligenceValue = 0;
            } else if (temp4 > 100) {
                this->plays[refPhase].intelligenceValue = 100;
            } else {
                this->plays[refPhase].intelligenceValue = (unsigned char)temp4;
            }
        } else if (strcmp(temp2 + 4, s_TargetChar) == 0 && refPhase != -1) {
            sscanf(temp + 4, s_format_skip_string_string, temp6 + 4);
            int characteristic = this->convertTargetCharacteristicNameToIntType(temp6 + 4);
            if (characteristic != 0) {
                this->plays[refPhase].addTargetCharacteristic((unsigned char)characteristic);
            }
        } else if (strcmp(temp2 + 4, s_TargetType) == 0 && refPhase != -1) {
            sscanf(temp + 4, s_format_skip_string_string, temp6 + 4);
            int type = this->convertTargetNameToIntType(temp6 + 4);
            if (type != 0) {
                this->plays[refPhase].addTargetType((unsigned char)type);
            }
        } else if (strcmp(temp2 + 4, s_NumberGroups) == 0 && refPhase != -1) {
            sscanf(temp + 4, s_format_skip_string_int, &temp4);
            this->plays[refPhase].numberGroupsValue = (unsigned char)temp4;
        } else if (strcmp(temp2 + 4, s_Group) == 0 && refPhase != -1 && phaseState == -1) {
            sscanf(temp + 4, s_format_group_range,
                   &temp4, temp6 + 4, &phaseValue1, &i);
            if (temp4 >= 0 && temp4 < 5) {
                int groupType = this->convertUnitNameToIntType(temp6 + 4);
                if (groupType != -1) {
                    int minimumValue = phaseValue1;
                    if (minimumValue < 0) {
                        minimumValue = 0;
                    }
                    this->plays[refPhase].group(temp4)->setMinimum(
                        groupType, (unsigned char)minimumValue);

                    int maximumValue = i;
                    if (maximumValue > 50) {
                        maximumValue = 50;
                    }
                    this->plays[refPhase].group(temp4)->setMaximum(
                        groupType, (unsigned char)maximumValue);
                }
            }
        } else if (strcmp(temp2 + 4, s_Phase) == 0 && refPhase != -1) {
            sscanf(temp + 4, s_format_skip_string_int, &temp4);
            phaseState = temp4;
        } else if (strcmp(temp2 + 4, s_Group) == 0 && refPhase != -1 && phaseState != -1) {
            sscanf(temp + 4, s_format_command,
                   &temp4, temp6 + 4, &phaseValue1, &i, &fileValue);
            if (temp4 >= 0 && temp4 < 5) {
                AIPlayPhase* phase = this->plays[refPhase].phase(phaseState);
                AIPlayPhaseCommand command(
                    (unsigned char)temp4, temp6 + 4, phaseValue1, i, fileValue);
                phase->addCommand(command);
            }
        } else if (strcmp(temp2 + 4, s_Trigger) == 0 && refPhase != -1 && phaseState != -1) {
            sscanf(temp + 4, s_format_trigger,
                   &temp4, temp6 + 4, &phaseValue1, &temp7);
            if (temp4 >= 0 && temp4 < 5) {
                AIPlayPhase* phase = this->plays[refPhase].phase(phaseState);
                AIPlayPhaseTrigger trigger(
                    temp6 + 4, phaseValue1, temp7,
                    (unsigned char)phaseState, (unsigned char)temp4, 0);
                phase->addTrigger(trigger);
            }
        } else if (strcmp(temp2 + 4, s_RTrigger) == 0 && refPhase != -1 && phaseState != -1) {
            sscanf(temp + 4, s_format_command,
                   &temp4, temp6 + 4, &phaseValue1, &temp7, &fileValue);
            if (temp4 >= 0 && temp4 < 5) {
                AIPlayPhase* phase = this->plays[refPhase].phase(phaseState);
                AIPlayPhaseTrigger rtrigger(
                    temp6 + 4, phaseValue1, temp7,
                    (unsigned char)phaseState, (unsigned char)temp4, fileValue);
                phase->addTrigger(rtrigger);
            }
        } else if (strcmp(temp2 + 4, s_EndPlay) == 0 && refPhase != -1) {
            int oldPhase = refPhase;
            phaseState = -1;
            strcpy(temp2 + 4, this->plays[oldPhase].nameValue);
            if (temp2[4] == 'H' && temp2[5] == 'P') {
                this->numberPlaysValue -= 7;
                refPhase = oldPhase;
            } else {
                refPhase = oldPhase + 7;
                temp8 = 1;
                do {
                    sprintf(temp2 + 4, s_format_play_variant,
                            this->plays[oldPhase].nameValue, temp8);
                    this->plays[oldPhase + temp8].setName(temp2 + 4);
                    this->plays[oldPhase + temp8].typeValue =
                        this->plays[oldPhase].typeValue;
                    this->plays[oldPhase + temp8].minimumNumberUnitsValue =
                        this->plays[oldPhase].minimumNumberUnitsValue;
                    this->plays[oldPhase + temp8].maximumNumberUnitsValue =
                        this->plays[oldPhase].maximumNumberUnitsValue;
                    this->plays[oldPhase + temp8].powerValue =
                        this->plays[oldPhase].powerValue;
                    this->plays[oldPhase + temp8].overflowValue =
                        this->plays[oldPhase].overflowValue;
                    this->plays[oldPhase + temp8].deathPercentageValue =
                        this->plays[oldPhase].deathPercentageValue;
                    this->plays[oldPhase + temp8].intelligenceValue =
                        this->plays[oldPhase].intelligenceValue;

                    int targetIndex = 0;
                    do {
                        this->plays[oldPhase + temp8].addTargetType(
                            this->plays[oldPhase].targetType(targetIndex));
                        this->plays[oldPhase + temp8].addTargetCharacteristic(
                            this->plays[oldPhase].targetCharacteristic(targetIndex));
                        ++targetIndex;
                    } while (targetIndex < 5);

                    this->plays[oldPhase + temp8].numberGroupsValue =
                        this->plays[oldPhase].numberGroupsValue;
                    groupPhase = 0;
                    do {
                        AIPlayGroup* source = this->plays[oldPhase].group(groupPhase);
                        AIPlayGroup* destination =
                            this->plays[oldPhase + temp8].group(groupPhase);
                        int groupIndex = 0;
                        do {
                            destination->setMinimum(
                                groupIndex, source->minimum(groupIndex));
                            destination->setMaximum(
                                groupIndex, source->maximum(groupIndex));
                            ++groupIndex;
                        } while (groupIndex < 6);
                        ++groupPhase;
                    } while (groupPhase < 5);

                    groupPhase = 0;
                    do {
                        AIPlayPhase* sourcePhase =
                            this->plays[oldPhase].phase(groupPhase);
                        AIPlayPhase* destinationPhase =
                            this->plays[oldPhase + temp8].phase(groupPhase);
                        currentPlay = 0;
                        do {
                            AIPlayPhaseCommand* command =
                                sourcePhase->command(currentPlay);
                            if (command->type() == 1) {
                                XYZ origin(0, 0, 0);
                                XYZ rotatedPoint;
                                XYZ originalPoint(command->value1(),
                                                  command->value2(),
                                                  command->value3());
                                originalPoint.rotateXYByFacet(
                                    origin, rotatedPoint, (unsigned char)temp8);
                                AIPlayPhaseCommand newCommand(
                                    command->group(), command->type(),
                                    rotatedPoint.yValue, rotatedPoint.zValue,
                                    originalPoint.xValue);
                                command = &newCommand;
                            }
                            destinationPhase->addCommand(*command);
                            ++currentPlay;
                        } while (currentPlay < 5);

                        int triggerIndex = 0;
                        do {
                            destinationPhase->addTrigger(
                                *sourcePhase->trigger(triggerIndex));
                            ++triggerIndex;
                        } while (triggerIndex < 3);
                        ++groupPhase;
                    } while (groupPhase < 10);

                    ++temp8;
                } while (temp8 < 8);
            }
        }
    }

    fclose(file);
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
