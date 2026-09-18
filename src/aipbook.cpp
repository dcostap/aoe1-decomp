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

AIPlayPhaseCommand::AIPlayPhaseCommand(unsigned char g,
                                       unsigned char t,
                                       int v1,
                                       int v2,
                                       int v3) {
    this->groupValue = g;
    this->typeValue = t;
    this->value1Value = v1;
    this->value2Value = v2;
    this->value3Value = v3;
}

AIPlayPhaseCommand::AIPlayPhaseCommand(unsigned char g, char* t,
                                       int v1, int v2, int v3) {
    this->groupValue = g;
    this->typeValue = this->convertToIntType(t);
    this->value1Value = v1;
    this->value2Value = v2;
    this->value3Value = v3;
}

char* AIPlayPhaseCommand::nameType() const {
    return this->convertToNameType(this->typeValue);
}

unsigned char AIPlayPhaseCommand::convertToIntType(char* t) const {
    int r;
    r = strcmp(t, s_Move);
    if (r == 0) return AIPlayPhaseCommand::MoveCommand;
    r = strcmp(t, s_Attack);
    if (r == 0) return AIPlayPhaseCommand::AttackCommand;
    r = strcmp(t, s_AttackSavedTarget);
    if (r == 0) return AIPlayPhaseCommand::AttackSavedTargetCommand;
    r = strcmp(t, s_Retreat);
    if (r == 0) return AIPlayPhaseCommand::RetreatCommand;
    r = strcmp(t, s_Heal);
    if (r == 0) return AIPlayPhaseCommand::HealCommand;
    r = strcmp(t, s_ResetHitPoints);
    if (r == 0) return AIPlayPhaseCommand::ResetHitPointsCommand;
    r = strcmp(t, s_ResetAliveCount);
    if (r == 0) return AIPlayPhaseCommand::ResetAliveCountCommand;
    r = strcmp(t, s_Wait);
    if (r == 0) return AIPlayPhaseCommand::WaitCommand;
    return AIPlayPhaseCommand::InvalidCommand;
}

char* AIPlayPhaseCommand::convertToNameType(unsigned char t) const {
    switch (t) {
    case AIPlayPhaseCommand::MoveCommand: return s_Move;
    case AIPlayPhaseCommand::AttackCommand: return s_Attack;
    case AIPlayPhaseCommand::AttackSavedTargetCommand: return s_AttackSavedTarget;
    case AIPlayPhaseCommand::RetreatCommand: return s_Retreat;
    case AIPlayPhaseCommand::HealCommand: return s_Heal;
    case AIPlayPhaseCommand::ResetHitPointsCommand: return s_ResetHitPoints;
    case AIPlayPhaseCommand::ResetAliveCountCommand: return s_ResetAliveCount;
    case AIPlayPhaseCommand::WaitCommand: return s_Wait;
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

AIPlayPhaseTrigger::AIPlayPhaseTrigger(unsigned char t,
                                       int v1,
                                       int v2,
                                       unsigned char p,
                                       unsigned char n,
                                       int r) {
    this->typeValue = t;
    this->value1Value = v1;
    this->value2Value = v2;
    this->phaseValue = p;
    this->nextPhaseValue = n;
    this->randomnessValue = r;
}

AIPlayPhaseTrigger::AIPlayPhaseTrigger(char* t, int v1, int v2,
                                       unsigned char p,
                                       unsigned char n,
                                       int r) {
    typeValue = convertToIntType(t);
    value1Value = v1;
    value2Value = v2;
    phaseValue = p;
    nextPhaseValue = n;
    randomnessValue = r;
}

char* AIPlayPhaseTrigger::nameType() const {
    return this->convertToNameType(this->typeValue);
}

unsigned char AIPlayPhaseTrigger::convertToIntType(char* t) const {
    int r;
    r = strcmp(t, s_Gather);
    if (r == 0) return AIPlayPhaseTrigger::GatherTrigger;
    r = strcmp(t, s_Death);
    if (r == 0) return AIPlayPhaseTrigger::DeathTrigger;
    r = strcmp(t, s_HealthLost);
    if (r == 0) return AIPlayPhaseTrigger::HealthLostTrigger;
    r = strcmp(t, s_DamageToGroup);
    if (r == 0) return AIPlayPhaseTrigger::DamageToGroupTrigger;
    r = strcmp(t, s_DamageToAnyGroup);
    if (r == 0) return AIPlayPhaseTrigger::DamageToAnyGroupTrigger;
    r = strcmp(t, s_Level1EnemySighted);
    if (r == 0) return AIPlayPhaseTrigger::Level1EnemySightedTrigger;
    r = strcmp(t, s_Level2EnemySighted);
    if (r == 0) return AIPlayPhaseTrigger::Level2EnemySightedTrigger;
    r = strcmp(t, s_DeathOfGroup);
    if (r == 0) return AIPlayPhaseTrigger::DeathOfGroupTrigger;
    r = strcmp(t, s_HealOfGroup);
    if (r == 0) return AIPlayPhaseTrigger::HealOfGroupTrigger;
    r = strcmp(t, s_Immediate);
    if (r == 0) return AIPlayPhaseTrigger::ImmediateTrigger;
    r = strcmp(t, s_Time);
    if (r == 0) return AIPlayPhaseTrigger::TimeTrigger;
    return AIPlayPhaseTrigger::InvalidTrigger;
}

char* AIPlayPhaseTrigger::convertToNameType(unsigned char t) const {
    switch (t) {
    case AIPlayPhaseTrigger::GatherTrigger: return s_Gather;
    case AIPlayPhaseTrigger::DeathTrigger: return s_Death;
    case AIPlayPhaseTrigger::HealthLostTrigger: return s_HealthLost;
    case AIPlayPhaseTrigger::DamageToGroupTrigger: return s_DamageToGroup;
    case AIPlayPhaseTrigger::DamageToAnyGroupTrigger: return s_DamageToAnyGroup;
    case AIPlayPhaseTrigger::Level1EnemySightedTrigger: return s_Level1EnemySighted;
    case AIPlayPhaseTrigger::Level2EnemySightedTrigger: return s_Level2EnemySighted;
    case AIPlayPhaseTrigger::DeathOfGroupTrigger: return s_DeathOfGroup;
    case AIPlayPhaseTrigger::HealOfGroupTrigger: return s_HealOfGroup;
    case AIPlayPhaseTrigger::ImmediateTrigger: return s_Immediate;
    case AIPlayPhaseTrigger::TimeTrigger: return s_Time;
    default: return s_Invalid;
    }
}

AIPlayPhase::AIPlayPhase() {
    initialize();
}

AIPlayPhaseCommand* AIPlayPhase::command(int v) {
    if (v < 0 || v >= AIPlayPhase::MaxCommands)
        return 0;
    return &this->commands[v];
}

AIPlayPhaseTrigger* AIPlayPhase::trigger(int v) {
    if ((v >= 0) && (v < AIPlayPhase::MaxTriggers)) {
        return &this->triggers[v];
    }
    return 0;
}

int AIPlayPhase::addCommand(AIPlayPhaseCommand& c) {
    int i = 0;
    while (i < AIPlayPhase::MaxCommands) {
        if (this->commands[i].type() == AIPlayPhaseCommand::InvalidCommand) {
            AIPlayPhaseCommand* dest = &this->commands[i];
            dest->setGroup(c.group());
            dest->setType(c.type());
            dest->setValue1(c.value1());
            dest->setValue2(c.value2());
            dest->setValue3(c.value3());
            return 1;
        }
        i++;
    }
    return 0;
}

int AIPlayPhase::addTrigger(AIPlayPhaseTrigger& t) {
    int i = 0;
    while (i < AIPlayPhase::MaxTriggers) {
        if (this->triggers[i].type() == AIPlayPhaseTrigger::InvalidTrigger) {
            this->triggers[i].setType(t.type());
            this->triggers[i].setValue1(t.value1());
            this->triggers[i].setValue2(t.value2());
            this->triggers[i].setPhase(t.phase());
            this->triggers[i].setNextPhase(t.nextPhase());
            this->triggers[i].setRandomness(t.randomness());
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
    for (i = 0; i < AIPlayPhase::MaxCommands; i++) {
        *p = 0;
        p += 0x10;
    }

    p = ((char*)this) + 0x50;
    for (i = 0; i < AIPlayPhase::MaxTriggers; i++) {
        *p = 0;
        p += 0x14;
    }
}

AIPlayGroup::AIPlayGroup() {
    initialize();
}

unsigned char AIPlayGroup::minimum(int n) const {
    if (n < 0 || n >= AIPlayGroup::MaxUnitTypes) return 0;
    return this->minValue[n];
}

void AIPlayGroup::setMinimum(int n, int v) {
    if (n < 0 || n >= AIPlayGroup::MaxUnitTypes) return;
    this->minValue[n] = v;
}

unsigned char AIPlayGroup::maximum(int n) const {
    if (n >= 0 && n < AIPlayGroup::MaxUnitTypes)
        return maxValue[n];
    return AIPlayGroup::InvalidGroup;
}

void AIPlayGroup::setMaximum(int n, int v) {
    if (n < 0 || n >= AIPlayGroup::MaxUnitTypes) return;
    this->maxValue[n] = v;
}

void AIPlayGroup::initialize() {
    for (int i = 0; i < AIPlayGroup::MaxUnitTypes; ++i) {
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

void AIPlay::setName(char* n) {
    if (n) {
        strncpy(this->nameValue, n, 64);
    }
}

int AIPlay::humanPlay() const {
    if (this->nameValue[0] == 0x48 && this->nameValue[1] == 0x50) return 1;
    return 0;
}

char* AIPlay::typeName() const {
    return this->convertToNameType(this->typeValue);
}

unsigned char AIPlay::targetType(int n) const {
    if (n >= 0 && n < 5)
        return targetTypeValue[n];
    return 0;
}

int AIPlay::isTargetType(unsigned char v) const {
    for (int i = 0; i < 5; i++) {
        if (this->targetTypeValue[i] == v)
            return 1;
    }
    return 0;
}

int AIPlay::addTargetType(unsigned char v) {
    for (int i = 0; i < 5; i++) {
        if (this->targetTypeValue[i] == 0 || this->targetTypeValue[i] == 5) {
            this->targetTypeValue[i] = v;
            return 1;
        }
    }
    return 0;
}

unsigned char AIPlay::targetCharacteristic(int n) const {
    if (n >= 0 && n < 5)
        return targetCharacteristicValue[n];
    return 0;
}

int AIPlay::isTargetCharacteristic(unsigned char v) const {
    for (int i = 0; i < 5; i++) {
        if (this->targetCharacteristicValue[i] == v)
            return 1;
    }
    return 0;
}

int AIPlay::addTargetCharacteristic(unsigned char v) {
    for (int i = 0; i < 5; i++) {
        if (this->targetCharacteristicValue[i] == 0 || this->targetCharacteristicValue[i] == 5) {
            this->targetCharacteristicValue[i] = v;
            return 1;
        }
    }
    return 0;
}

int AIPlay::gatherTolerance(int groupID, int phaseID) {
    AIPlayPhase* phase_ptr = this->phase(phaseID);
    if (phase_ptr == 0) {
        return 2;
    }

    int i = 0;
    while (i < AIPlayPhase::MaxTriggers) {
        AIPlayPhaseTrigger* trigger_ptr = phase_ptr->trigger(i);
        if (trigger_ptr != 0 && trigger_ptr->type() == AIPlayPhaseTrigger::GatherTrigger) {
            return trigger_ptr->value1();
        }
        i++;
    }

    return 2;
}

AIPlayGroup* AIPlay::group(int n) {
    if (n < 0 || n >= 5) return 0;
    return &this->groups[n];
}

AIPlayPhase* AIPlay::phase(int n) {
    if (n >= 0 && n < 10)
        return this->phases + n;
    return 0;
}

int AIPlay::fillGroups(AIPlayStatus* playStatus, int* groupMembers,
                       int numberGroupMembers,
                       RGE_Game_World* world) {
    AIPlay* play = world->playbook->play(playStatus->playNumberValue);
    if (play == 0) {
        return 0;
    }

    int unitsByTypeCount[AIPlayGroup::MaxUnitTypes];
    int unitsByType[AIPlayGroup::MaxUnitTypes][50];
    int minUnits = 1;
    int i;
    int overflowType;
    int overflowUnit;
    unsigned char maximumUnits;

    for (i = 0; i < AIPlayGroup::MaxUnitTypes; i++) {
        unitsByTypeCount[i] = 0;
    }

    for (i = 0; i < numberGroupMembers; i++) {
        RGE_Static_Object* object = world->object(groupMembers[i]);
        int type;
        if (object == 0 || (type = world->playbook->convertUnitToIntType(object)) < 0 ||
            type >= AIPlayGroup::MaxUnitTypes) {
            minUnits = 0;
        } else {
            unitsByType[type][unitsByTypeCount[type]] = groupMembers[i];
            unitsByTypeCount[type]++;
        }
    }

    int groupNumber;
    for (groupNumber = 0; groupNumber < play->numberGroupsValue; groupNumber++) {
        AIPlayGroup* group = play->group(groupNumber);
        if (group == 0) {
            return 0;
        }

        for (int type = 0; type < AIPlayGroup::MaxUnitTypes; type++) {
            int minimum = group->minimum(type);
            if (minimum != 0) {
                int added = 0;
                for (int unit = 0; unit < unitsByTypeCount[type] && added < minimum; unit++) {
                    int& id = unitsByType[type][unit];
                    if (id != -1) {
                        if (playStatus->addGrouping(id, (unsigned char)groupNumber, (unsigned char)type) == 1) {
                            added++;
                            maximumUnits = play->maximumNumberUnitsValue;
                            id = -1;
                            if (playStatus->numberInPlay() == maximumUnits) {
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

    for (overflowType = 0; overflowType < AIPlayGroup::MaxUnitTypes; overflowType++) {
        for (overflowUnit = 0; overflowUnit < unitsByTypeCount[overflowType]; overflowUnit++) {
            int& id = unitsByType[overflowType][overflowUnit];
            if (id == -1) {
                continue;
            }

            if (this->overflowValue == 1) {
                int smallestGroup = -1;
                int smallestGroupSize = 0;

                for (groupNumber = 0; groupNumber < play->numberGroupsValue; groupNumber++) {
                    AIPlayGroup* group = play->group(groupNumber);
                    if (group != 0 && playStatus->numberOfTypeInGroup(groupNumber, overflowType) <
                        group->maximum(overflowType) && (smallestGroup == -1 || playStatus->numberInGroup(groupNumber) <
                             smallestGroupSize)) {
                        smallestGroupSize =
                            playStatus->numberInGroup(groupNumber);
                        smallestGroup = groupNumber;
                    }
                }

                if (smallestGroup != -1) {
                    if (playStatus->addGrouping(id, (unsigned char)smallestGroup, (unsigned char)overflowType) == 1) {
                        maximumUnits = play->maximumNumberUnitsValue;
                        id = -1;
                        if (playStatus->numberInPlay() == maximumUnits) {
                            goto CountDeviation;
                        }
                    } else {
                        minUnits = 0;
                    }
                }
            } else if (this->overflowValue == 2) {
                for (groupNumber = 0; groupNumber < play->numberGroupsValue; groupNumber++) {
                    AIPlayGroup* group = play->group(groupNumber);
                    if (group != 0 && playStatus->numberOfTypeInGroup(groupNumber, overflowType) <
                        group->maximum(overflowType)) {
                        if (playStatus->addGrouping(id, (unsigned char)groupNumber, (unsigned char)overflowType) == 1) {
                            maximumUnits = play->maximumNumberUnitsValue;
                            id = -1;
                            if (playStatus->numberInPlay() == maximumUnits) {
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
    for (groupNumber = 0; groupNumber < play->numberGroupsValue; groupNumber++) {
        AIPlayGroup* group = play->group(groupNumber);
        if (group != 0) {
            for (int type = 0; type < AIPlayGroup::MaxUnitTypes; type++) {
                int minimum = group->minimum(type);
                int actual = playStatus->numberOfTypeInGroup(groupNumber, type);
                if (actual < minimum) {
                    deviation += minimum - actual;
                }
            }
        }
    }
    playStatus->deviationValue = (unsigned char)deviation;
    return minUnits;
}

int AIPlay::groupGivenCommandOnPhase(int gID, int cType, int pID) {
    if (gID < 0 || gID >= 5)
        return -1;
    if (pID < 0 || pID >= 10)
        return -1;

    int i = 0;
    AIPlayPhase* phase = &this->phases[pID];
    for (; i < AIPlayPhase::MaxCommands; i++) {
        AIPlayPhaseCommand* cmd = phase->command(i);
        if ((unsigned int)cmd->group() == (unsigned int)gID) {
            AIPlayPhaseCommand* cmd2 = phase->command(i);
            int typeTemp;
            *(unsigned char*)&typeTemp = cmd2->type();
            if ((typeTemp & 0xff) == cType) {
                return i;
            }
        }
    }
    return -1;
}

unsigned char AIPlay::convertToIntType(char* t) const {
    int r;
    r = strcmp(t, s_Attack);
    if (r == 0) return 1;
    r = strcmp(t, s_Annoy);
    if (r == 0) return 2;
    r = strcmp(t, s_Flank);
    if (r == 0) return 3;
    r = strcmp(t, s_Recon);
    if (r == 0) return 4;
    return 0;
}

char* AIPlay::convertToNameType(unsigned char t) const {
    switch (t) {
    case 1: return "Attack";
    case 2: return "Annoy";
    case 3: return "Flank";
    case 4: return "Recon";
    default: return "Invalid";
    }
}

int AIPlay::locationsOnMap(int targetX, int targetY, int mapXSize,
                           int mapYSize) {
    int p = 0;
    AIPlayPhase* phase = &this->phases[0];

    while (p < 10) {
        int cmdIdx = 0;
        while (cmdIdx < AIPlayPhase::MaxCommands) {
            AIPlayPhaseCommand* cmd = phase->command(cmdIdx);
            if (cmd->type() == AIPlayPhaseCommand::MoveCommand) {
                int px = cmd->value1() + targetX;
                int py = cmd->value2() + targetY;
                if (px < 0 || py < 0 || px >= mapXSize || py >= mapYSize) {
                    return 0;
                }
            }
            cmdIdx++;
        }
        phase++;
        p++;
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

int AIPlayStatus::originalHitPoints(int n) const {
    if (n < 0 || n >= 5) return -1;
    return this->originalHitPointsValue[n];
}

void AIPlayStatus::setOriginalHitPoints(int n, int v) {
    if (n < 0 || n >= 5) return;
    this->originalHitPointsValue[n] = v;
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

unsigned char AIPlayStatus::numberInGroup(int n) {
    unsigned char count = 0;
    AIPlayStatus::GroupingStruct* entry = this->groupings;
    int remaining = 50;
    do {
        if (entry->id != -1) {
            if (entry->groupID == n)
                count++;
        }
        entry++;
        remaining--;
    } while (remaining);
    return count;
}

unsigned char AIPlayStatus::numberOfTypeInGroup(int n, int type) {
    unsigned char count = 0;
    for (int i = 0; i < 50; i++) {
        const GroupingStruct& g = this->groupings[i];
        if ((g.id != -1) && (g.groupID == n) && (g.type == type)) {
            count++;
        }
    }
    return count;
}

unsigned char AIPlayStatus::group(int uID) {
    if (uID < 0)
        return 0xFF;
    for (int i = 0; i < 50; i++) {
        if (this->groupings[i].id == uID)
            return this->groupings[i].groupID;
    }
    return 0xFF;
}

int AIPlayStatus::addGrouping(int uID, unsigned char gID,
                              unsigned char type) {
    for (int i = 0; i < 50; i++) {
        if (this->groupings[i].id == -1) {
            this->groupings[i].id = uID;
            this->groupings[i].groupID = gID;
            this->groupings[i].type = type;
            return 1;
        }
    }
    return 0;
}

int AIPlayStatus::removeGrouping(int uID) {
    for (int i = 0; i < 50; i++) {
        if (this->groupings[i].id == uID) {
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

void AIPlayStatus::copyUnits(int* array, int& count) {
    AIPlayStatus::GroupingStruct* grouping = this->groupings;
    int i = 0x32;

    count = 0;
    do {
        int id = grouping->id;
        if (id != -1) {
            array[count] = id;
            count = count + 1;
        }
        grouping = grouping + 1;
        i = i - 1;
    } while (i != 0);
}

void AIPlayStatus::load(int infile) {
    int tempInt = infile;

    rge_read(infile, &playNumberValue, 4);
    rge_read(tempInt, &targetValue, 4);
    rge_read(tempInt, &infile, 4);
    originalPointValue.xValue = infile;
    rge_read(tempInt, &infile, 4);
    originalPointValue.yValue = infile;
    rge_read(tempInt, &infile, 4);
    originalPointValue.zValue = infile;
    rge_read(tempInt, originalHitPointsValue, 20);
    rge_read(tempInt, &currentPhaseValue, 1);
    rge_read(tempInt, this, 400);
    rge_read(tempInt, &savedAttackerValue, 4);
    rge_read(tempInt, &lastPhaseChangeTimeValue, 4);
}

void AIPlayStatus::save(int outfile) {
    int tempInt = outfile;

    rge_write(outfile, &playNumberValue, 4);
    rge_write(tempInt, &targetValue, 4);
    outfile = originalPointValue.xValue;
    rge_write(tempInt, &outfile, 4);
    outfile = originalPointValue.yValue;
    rge_write(tempInt, &outfile, 4);
    outfile = originalPointValue.zValue;
    rge_write(tempInt, &outfile, 4);
    rge_write(tempInt, originalHitPointsValue, 20);
    rge_write(tempInt, &currentPhaseValue, 1);
    rge_write(tempInt, this, 400);
    rge_write(tempInt, &savedAttackerValue, 4);
    rge_write(tempInt, &lastPhaseChangeTimeValue, 4);
}

// order before the grouping loop. The copy order and memory effects match.
void AIPlayStatus::copy(AIPlayStatus* ps) {
    int count = 50;
    this->playNumberValue = ps->playNumberValue;
    this->targetValue = ps->targetValue;
    int z = ps->originalPointValue.zValue;
    int y = ps->originalPointValue.yValue;
    int x = ps->originalPointValue.xValue;
    this->originalPointValue.xValue = x;
    this->originalPointValue.yValue = y;
    this->originalPointValue.zValue = z;
    this->currentPhaseValue = ps->currentPhaseValue;
    this->savedAttackerValue = ps->savedAttackerValue;

    AIPlayStatus* p = ps;
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

void AIPlayStatus::removeDeadUnits(int gID, RGE_Game_World* world) {
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

void AIPlayStatus::resetHitPoints(int gID, RGE_Game_World* world) {
    int total = 0;
    AIPlayStatus* p = this;
    int count = 50;

    do {
        int id = p->groupings[0].id;
        if (id != -1) {
            if (p->groupings[0].groupID == gID) {
                RGE_Static_Object* obj = world->object(id);
                if (obj != 0) {
                    total += (int)obj->hp;
                }
            }
        }
        p = (AIPlayStatus*)(p->groupings + 1);
        count--;
    } while (count != 0);

    setOriginalHitPoints(gID, total);
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

    char temp[256];
    char temp2[256];
    char temp6[256];
    sprintf(temp, s_format_percent_s, this->nameValue);
    FILE* fileIn = fopen(temp, s_mode_r);
    if (fileIn == 0)
        return 0;

    if (this->plays != 0) {
        delete[] this->plays;
        this->plays = 0;
    }

    this->numberPlaysValue = 0;
    while (fgets(temp, 256, fileIn) != 0) {
        if (strlen(temp) != 0) {
            sscanf(temp, s_format_percent_s_space, temp2);
            if (strcmp(temp2, s_Play) == 0)
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
    while (fgets(temp, 256, fileIn) != 0) {
        if (strlen(temp) == 0)
            continue;

        strcpy(temp2, s_592A40);
        strcpy(temp6, s_592A40);

        int temp4 = 0;
        int temp3 = 0;
        int i = 0;
        int temp5 = 0;
        int temp7 = 0;
        char commentTemp1;
        char commentTemp2;

        if (sscanf(temp, s_format_comment, &commentTemp1, &commentTemp2) != -1 &&
            (commentTemp1 != '/' || commentTemp2 != '/')) {
            sscanf(temp, s_format_percent_s_space, temp2);

            if (strcmp(temp2, s_Play) == 0) {
                int firstQuote = 0;
                while (temp[firstQuote] != '"')
                    firstQuote++;
                firstQuote++;

                int lastQuote = firstQuote;
                while (temp[lastQuote] != '"')
                    lastQuote++;

                int length = lastQuote - firstQuote;
                if (firstQuote < lastQuote)
                    memcpy(temp2, temp + firstQuote, length);
                temp2[length] = 0;

                currentPlay++;
                if (currentPlay >= 16000)
                    break;
                this->plays[currentPlay].setName(temp2);
            } else if (strcmp(temp2, s_PlayType) == 0 && currentPlay != -1) {
                sscanf(temp, s_format_skip_string_string, temp2);
                this->plays[currentPlay].typeValue =
                    this->plays[currentPlay].convertToIntType(temp2);
            } else if (strcmp(temp2, s_MinUnits) == 0 && currentPlay != -1) {
                sscanf(temp, s_format_skip_string_int, &temp4);
                this->plays[currentPlay].minimumNumberUnitsValue = temp4;
            } else if (strcmp(temp2, s_MaxUnits) == 0 && currentPlay != -1) {
                sscanf(temp, s_format_skip_string_int, &temp4);
                this->plays[currentPlay].maximumNumberUnitsValue = temp4;
            } else if (strcmp(temp2, s_Power) == 0 && currentPlay != -1) {
                sscanf(temp, s_format_skip_string_int, &temp4);
                this->plays[currentPlay].powerValue = temp4;
            } else if (strcmp(temp2, s_Overflow) == 0 && currentPlay != -1) {
                sscanf(temp, s_format_skip_string_string, temp2);
                if (strcmp(temp2, s_Balance) == 0)
                    this->plays[currentPlay].overflowValue = 1;
                else if (strcmp(temp2, s_FirstGroup) == 0)
                    this->plays[currentPlay].overflowValue = 2;
            } else if (strcmp(temp2, s_DeathPercentage) == 0 && currentPlay != -1) {
                sscanf(temp, s_format_skip_string_int, &temp4);
                if (temp4 < 0)
                    this->plays[currentPlay].deathPercentageValue = 0;
                else if (temp4 > 100)
                    this->plays[currentPlay].deathPercentageValue = 100;
                else
                    this->plays[currentPlay].deathPercentageValue = temp4;
            } else if (strcmp(temp2, s_Intelligence) == 0 && currentPlay != -1) {
                sscanf(temp, s_format_skip_string_int, &temp4);
                if (temp4 < 0)
                    this->plays[currentPlay].intelligenceValue = 0;
                else if (temp4 > 100)
                    this->plays[currentPlay].intelligenceValue = 100;
                else
                    this->plays[currentPlay].intelligenceValue = temp4;
            } else if (strcmp(temp2, s_TargetChar) == 0 && currentPlay != -1) {
                sscanf(temp, s_format_skip_string_string, temp6);
                int type = this->convertTargetCharacteristicNameToIntType(temp6);
                if (type != 0)
                    this->plays[currentPlay].addTargetCharacteristic(type);
            } else if (strcmp(temp2, s_TargetType) == 0 && currentPlay != -1) {
                sscanf(temp, s_format_skip_string_string, temp6);
                int type = this->convertTargetNameToIntType(temp6);
                if (type != 0)
                    this->plays[currentPlay].addTargetType(type);
            } else if (strcmp(temp2, s_NumberGroups) == 0 && currentPlay != -1) {
                sscanf(temp, s_format_skip_string_int, &temp4);
                this->plays[currentPlay].numberGroupsValue = temp4;
            } else if (strcmp(temp2, s_Group) == 0 && currentPlay != -1 && currentPhase == -1) {
                sscanf(temp, s_format_group_range, &temp4, temp6, &temp3, &i);
                if (temp4 >= 0 && temp4 < 5) {
                    int type = this->convertUnitNameToIntType(temp6);
                    if (type != -1) {
                        AIPlayGroup* group =
                            this->plays[currentPlay].group(temp4);
                        if (i < 0)
                            group->setMinimum(type, 0);
                        else
                            group->setMinimum(type, temp3);

                        if (i > 50)
                            group->setMaximum(type, 50);
                        else
                            group->setMaximum(type, i);
                    }
                }
            } else if (strcmp(temp2, s_Phase) == 0 && currentPlay != -1) {
                sscanf(temp, s_format_skip_string_int, &temp4);
                currentPhase = temp4;
            } else if (strcmp(temp2, s_Group) == 0 && currentPlay != -1 && currentPhase != -1) {
                sscanf(temp, s_format_command, &temp4, temp6, &temp3, &i, &temp5);
                if (temp4 >= 0 && temp4 < 5) {
                    AIPlayPhase* phase =
                        this->plays[currentPlay].phase(currentPhase);
                    AIPlayPhaseCommand command((unsigned char)temp4, temp6,
                                               temp3, i, temp5);
                    phase->addCommand(command);
                }
            } else if (strcmp(temp2, s_Trigger) == 0 && currentPlay != -1 && currentPhase != -1) {
                sscanf(temp, s_format_trigger, &temp4, temp6, &temp3, &temp7);
                AIPlayPhase* phase =
                    this->plays[currentPlay].phase(currentPhase);
                AIPlayPhaseTrigger trigger(temp6, temp3, temp7,
                                           (unsigned char)currentPhase,
                                           (unsigned char)temp4, 0);
                phase->addTrigger(trigger);
            } else if (strcmp(temp2, s_RTrigger) == 0 && currentPlay != -1 && currentPhase != -1) {
                sscanf(temp, s_format_command, &temp4, temp6, &temp3, &temp7, &temp5);
                AIPlayPhase* phase =
                    this->plays[currentPlay].phase(currentPhase);
                AIPlayPhaseTrigger trigger(temp6, temp3, temp7,
                                           (unsigned char)currentPhase,
                                           (unsigned char)temp4, temp5);
                phase->addTrigger(trigger);
            } else if (strcmp(temp2, s_EndPlay) == 0 && currentPlay != -1) {
                currentPhase = -1;
                strcpy(temp2, this->plays[currentPlay].nameValue);
                if (temp2[0] == 'H' && temp2[1] == 'P') {
                    this->numberPlaysValue -= 7;
                } else {
                    int sourcePlay = currentPlay;
                    currentPlay += 7;
                    for (int temp8 = 1; temp8 < 8; temp8++) {
                        AIPlay* source = &this->plays[sourcePlay];
                        AIPlay* destination = &this->plays[sourcePlay + temp8];

                        sprintf(temp2, s_format_play_variant, source->nameValue, temp8);
                        destination->setName(temp2);
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

                        for (i = 0; i < 5; i++) {
                            destination->addTargetType(source->targetType(i));
                            destination->addTargetCharacteristic(source->targetCharacteristic(i));
                        }
                        destination->numberGroupsValue =
                            source->numberGroupsValue;

                        for (int iGroups = 0; iGroups < 5; iGroups++) {
                            AIPlayGroup* refGroup = source->group(iGroups);
                            AIPlayGroup* curGroup = destination->group(iGroups);
                            for (i = 0; i < AIPlayGroup::MaxUnitTypes; i++) {
                                curGroup->setMinimum(i, refGroup->minimum(i));
                                curGroup->setMaximum(i, refGroup->maximum(i));
                            }
                        }

                        for (int iPhases = 0; iPhases < 10; iPhases++) {
                            AIPlayPhase* refPhase = source->phase(iPhases);
                            AIPlayPhase* curPhase = destination->phase(iPhases);
                            for (int a = 0; a < AIPlayPhase::MaxCommands; a++) {
                                AIPlayPhaseCommand* command =
                                    refPhase->command(a);
                                if (command->type() == AIPlayPhaseCommand::MoveCommand) {
                                    XYZ origin(0, 0, 0);
                                    XYZ rotatedPoint;
                                    XYZ originalPoint(command->value1(),
                                                      command->value2(),
                                                      command->value3());
                                    originalPoint.rotateXYByFacet(origin, rotatedPoint, (unsigned char)temp8);
                                    AIPlayPhaseCommand newCommand(
                                        command->group(), command->type(),
                                        rotatedPoint.xValue,
                                        rotatedPoint.yValue,
                                        rotatedPoint.zValue);
                                    curPhase->addCommand(newCommand);
                                } else {
                                    curPhase->addCommand(*command);
                                }
                            }

                            for (i = 0; i < AIPlayPhase::MaxTriggers; i++) {
                                AIPlayPhaseTrigger* trigger =
                                    refPhase->trigger(i);
                                curPhase->addTrigger(*trigger);
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

AIPlay* AIPlayBook::play(int n) {
    if (this->plays != 0 && n >= 0 && n < this->numberPlaysValue)
        return this->plays + n;
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

int AIPlayBook::convertTargetNameToIntType(char* t) const {
    int r;
    r = strcmp(t, s_Any);
    if (r == 0) return 5;
    return 0;
}

int AIPlayBook::convertTargetCharacteristicNameToIntType(char* t) const {
    int r;
    r = strcmp(t, s_Stationary);
    if (r == 0) return 1;
    r = strcmp(t, s_Moving);
    if (r == 0) return 2;
    r = strcmp(t, s_Slow);
    if (r == 0) return 3;
    r = strcmp(t, s_Fast);
    if (r == 0) return 4;
    r = strcmp(t, s_Any);
    if (r == 0) return 5;
    return 0;
}

int AIPlayBook::convertUnitNameToIntType(char* t) const {
    return -1;
}

int AIPlayBook::convertUnitToIntType(RGE_Static_Object* obj) const {
    return -1;
}
