#include "../include/AIPlay.h"

#include <string.h>

namespace {
char sMove[] = "Move";
char sAttack[] = "Attack";
char sAttackSavedTarget[] = "AttackSavedTarget";
char sRetreat[] = "Retreat";
char sHeal[] = "Heal";
char sResetHitPoints[] = "ResetHitPoints";
char sResetAliveCount[] = "ResetAliveCount";
char sWait[] = "Wait";

char sGather[] = "Gather";
char sDeath[] = "Death";
char sHealthLost[] = "HealthLost";
char sDamageToGroup[] = "DamageToGroup";
char sDamageToAnyGroup[] = "DamageToAnyGroup";
char sLevel1EnemySighted[] = "Level1EnemySighted";
char sLevel2EnemySighted[] = "Level2EnemySighted";
char sDeathOfGroup[] = "DeathOfGroup";
char sHealOfGroup[] = "HealOfGroup";
char sImmediate[] = "Immediate";
char sTime[] = "Time";

char sAnnoy[] = "Annoy";
char sFlank[] = "Flank";
char sRecon[] = "Recon";
char sInvalid[] = "Invalid";
}  // namespace

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040E930
AIPlayPhaseCommand::AIPlayPhaseCommand() {
    this->groupValue = 0;
    this->typeValue = 0;
    this->value1Value = 0;
    this->value2Value = 0;
    this->value3Value = 0;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040E950
AIPlayPhaseCommand::AIPlayPhaseCommand(uchar group, uchar type, int value1, int value2, int value3) {
    this->groupValue = group;
    this->typeValue = type;
    this->value1Value = value1;
    this->value2Value = value2;
    this->value3Value = value3;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040E980
AIPlayPhaseCommand::AIPlayPhaseCommand(uchar group, char* typeName, int value1, int value2, int value3) {
    this->groupValue = group;
    this->typeValue = this->convertToIntType(typeName);
    this->value2Value = value2;
    this->value1Value = value1;
    this->value3Value = value3;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040E9C0
char* AIPlayPhaseCommand::nameType() const {
    return this->convertToNameType(this->typeValue);
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040E9D0
uchar AIPlayPhaseCommand::convertToIntType(char* typeName) const {
    if (strcmp(typeName, sMove) == 0) {
        return 1;
    }
    if (strcmp(typeName, sAttack) == 0) {
        return 2;
    }
    if (strcmp(typeName, sAttackSavedTarget) == 0) {
        return 3;
    }
    if (strcmp(typeName, sRetreat) == 0) {
        return 4;
    }
    if (strcmp(typeName, sHeal) == 0) {
        return 5;
    }
    if (strcmp(typeName, sResetHitPoints) == 0) {
        return 6;
    }
    if (strcmp(typeName, sResetAliveCount) == 0) {
        return 7;
    }
    if (strcmp(typeName, sWait) == 0) {
        return 8;
    }
    return 0;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040EBF0
char* AIPlayPhaseCommand::convertToNameType(uchar type) const {
    switch (type) {
        case 1:
            return sMove;
        case 2:
            return sAttack;
        case 3:
            return sAttackSavedTarget;
        case 4:
            return sRetreat;
        case 5:
            return sHeal;
        case 6:
            return sResetHitPoints;
        case 7:
            return sResetAliveCount;
        case 8:
            return sWait;
        default:
            return sInvalid;
    }
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040EC70
AIPlayPhaseTrigger::AIPlayPhaseTrigger() {
    this->typeValue = 0;
    this->value1Value = -1;
    this->value2Value = -1;
    this->phaseValue = 0;
    this->nextPhaseValue = 0;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040EC90
AIPlayPhaseTrigger::AIPlayPhaseTrigger(uchar type, int value1, int value2, uchar phase, uchar nextPhase, int randomness) {
    this->typeValue = type;
    this->value1Value = value1;
    this->value2Value = value2;
    this->phaseValue = phase;
    this->nextPhaseValue = nextPhase;
    this->randomnessValue = randomness;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040ECC0
AIPlayPhaseTrigger::AIPlayPhaseTrigger(char* typeName, int value1, int value2, uchar phase, uchar nextPhase, int randomness) {
    this->typeValue = this->convertToIntType(typeName);
    this->value1Value = value1;
    this->value2Value = value2;
    this->phaseValue = phase;
    this->nextPhaseValue = nextPhase;
    this->randomnessValue = randomness;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040ED00
char* AIPlayPhaseTrigger::nameType() const {
    return this->convertToNameType(this->typeValue);
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040ED10
uchar AIPlayPhaseTrigger::convertToIntType(char* typeName) const {
    if (strcmp(typeName, sGather) == 0) {
        return 1;
    }
    if (strcmp(typeName, sDeath) == 0) {
        return 2;
    }
    if (strcmp(typeName, sHealthLost) == 0) {
        return 3;
    }
    if (strcmp(typeName, sDamageToGroup) == 0) {
        return 4;
    }
    if (strcmp(typeName, sDamageToAnyGroup) == 0) {
        return 5;
    }
    if (strcmp(typeName, sLevel1EnemySighted) == 0) {
        return 6;
    }
    if (strcmp(typeName, sLevel2EnemySighted) == 0) {
        return 7;
    }
    if (strcmp(typeName, sDeathOfGroup) == 0) {
        return 8;
    }
    if (strcmp(typeName, sHealOfGroup) == 0) {
        return 9;
    }
    if (strcmp(typeName, sImmediate) == 0) {
        return 10;
    }
    if (strcmp(typeName, sTime) == 0) {
        return 11;
    }
    return 0;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040EFF0
char* AIPlayPhaseTrigger::convertToNameType(uchar type) const {
    switch (type) {
        case 1:
            return sGather;
        case 2:
            return sDeath;
        case 3:
            return sHealthLost;
        case 4:
            return sDamageToGroup;
        case 5:
            return sDamageToAnyGroup;
        case 6:
            return sLevel1EnemySighted;
        case 7:
            return sLevel2EnemySighted;
        case 8:
            return sDeathOfGroup;
        case 9:
            return sHealOfGroup;
        case 10:
            return sImmediate;
        case 11:
            return sTime;
        default:
            return sInvalid;
    }
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F0A0
AIPlayPhase::AIPlayPhase() {
    this->initialize();
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F110
AIPlayPhaseCommand* AIPlayPhase::command(int index) {
    if ((-1 < index) && (index < 5)) {
        return this->commands + index;
    }
    return nullptr;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F130
AIPlayPhaseTrigger* AIPlayPhase::trigger(int index) {
    if ((-1 < index) && (index < 3)) {
        return this->triggers + index;
    }
    return nullptr;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F150
int AIPlayPhase::addCommand(AIPlayPhaseCommand& commandValue) {
    int i = 0;
    do {
        if (this->commands[i].typeValue == 0) {
            this->commands[i].groupValue = commandValue.groupValue;
            this->commands[i].typeValue = commandValue.typeValue;
            this->commands[i].value1Value = commandValue.value1Value;
            this->commands[i].value2Value = commandValue.value2Value;
            this->commands[i].value3Value = commandValue.value3Value;
            return 1;
        }
        i = i + 1;
    } while (i < 5);
    return 0;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F1A0
int AIPlayPhase::addTrigger(AIPlayPhaseTrigger& triggerValue) {
    int i = 0;
    do {
        if (this->triggers[i].typeValue == 0) {
            this->triggers[i].typeValue = triggerValue.typeValue;
            this->triggers[i].value1Value = triggerValue.value1Value;
            this->triggers[i].value2Value = triggerValue.value2Value;
            this->triggers[i].phaseValue = triggerValue.phaseValue;
            this->triggers[i].nextPhaseValue = triggerValue.nextPhaseValue;
            this->triggers[i].randomnessValue = triggerValue.randomnessValue;
            return 1;
        }
        i = i + 1;
    } while (i < 3);
    return 0;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F200
void AIPlayPhase::initialize() {
    int i = 0;
    do {
        this->commands[i].typeValue = 0;
        i = i + 1;
    } while (i < 5);

    i = 0;
    do {
        this->triggers[i].typeValue = 0;
        i = i + 1;
    } while (i < 3);
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F230
AIPlayGroup::AIPlayGroup() {
    this->initialize();
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F240
uchar AIPlayGroup::minimum(int index) const {
    if ((-1 < index) && (index < 6)) {
        return this->minValue[index];
    }
    return 0;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F260
void AIPlayGroup::setMinimum(int index, int value) {
    if ((-1 < index) && (index < 6)) {
        this->minValue[index] = (uchar)value;
    }
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F280
uchar AIPlayGroup::maximum(int index) const {
    if ((-1 < index) && (index < 6)) {
        return this->maxValue[index];
    }
    return 0xFF;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F2A0
void AIPlayGroup::setMaximum(int index, int value) {
    if ((-1 < index) && (index < 6)) {
        this->maxValue[index] = (uchar)value;
    }
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F2C0
void AIPlayGroup::initialize() {
    for (int i = 0; i < 6; ++i) {
        this->minValue[i] = 0;
        this->maxValue[i] = 0xFE;
    }
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F2E0
AIPlay::AIPlay() {
    this->minimumNumberUnitsValue = 1;
    this->typeValue = 1;
    this->overflowValue = 1;
    this->maximumNumberUnitsValue = 0xFF;
    this->powerValue = 0;
    this->intelligenceValue = '2';
    this->deathPercentageValue = '2';

    int i = 0;
    do {
        this->targetTypeValue[i] = 5;
        this->targetCharacteristicValue[i] = 5;
        i = i + 1;
    } while (i < 5);
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F360
void AIPlay::setName(char* name) {
    if (name != nullptr) {
        strncpy(this->nameValue, name, 0x40);
    }
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F380
int AIPlay::humanPlay() const {
    if ((this->nameValue[0] == 'H') && (this->nameValue[1] == 'P')) {
        return 1;
    }
    return 0;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F3A0
char* AIPlay::typeName() const {
    return this->convertToNameType(this->typeValue);
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F3B0
uchar AIPlay::targetType(int index) const {
    if ((-1 < index) && (index < 5)) {
        return this->targetTypeValue[index];
    }
    return 0;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F3D0
int AIPlay::isTargetType(uchar type) const {
    int i = 0;
    do {
        if (this->targetTypeValue[i] == type) {
            return 1;
        }
        i = i + 1;
    } while (i < 5);
    return 0;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F3F0
int AIPlay::addTargetType(uchar type) {
    int i = 0;
    while (true) {
        if ((this->targetTypeValue[i] == 0) || (this->targetTypeValue[i] == 5)) {
            break;
        }
        i = i + 1;
        if (4 < i) {
            return 0;
        }
    }
    this->targetTypeValue[i] = type;
    return 1;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F420
uchar AIPlay::targetCharacteristic(int index) const {
    if ((-1 < index) && (index < 5)) {
        return this->targetCharacteristicValue[index];
    }
    return 0;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F440
int AIPlay::isTargetCharacteristic(uchar characteristic) const {
    int i = 0;
    do {
        if (this->targetCharacteristicValue[i] == characteristic) {
            return 1;
        }
        i = i + 1;
    } while (i < 5);
    return 0;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F460
int AIPlay::addTargetCharacteristic(uchar characteristic) {
    int i = 0;
    while (true) {
        if ((this->targetCharacteristicValue[i] == 0) || (this->targetCharacteristicValue[i] == 5)) {
            break;
        }
        i = i + 1;
        if (4 < i) {
            return 0;
        }
    }
    this->targetCharacteristicValue[i] = characteristic;
    return 1;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F490
int AIPlay::gatherTolerance(int, int phaseIndex) {
    AIPlayPhase* phaseValue = this->phase(phaseIndex);
    if (phaseValue == nullptr) {
        return 2;
    }

    int i = 0;
    while (true) {
        AIPlayPhaseTrigger* triggerValue = phaseValue->trigger(i);
        if ((triggerValue != nullptr) && (triggerValue->typeValue == 1)) {
            return triggerValue->value1Value;
        }
        i = i + 1;
        if (2 < i) {
            return 2;
        }
    }
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F4E0
AIPlayGroup* AIPlay::group(int index) {
    if ((-1 < index) && (index < 5)) {
        return this->groups + index;
    }
    return nullptr;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F500
AIPlayPhase* AIPlay::phase(int index) {
    if ((-1 < index) && (index < 10)) {
        return this->phases + index;
    }
    return nullptr;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F9B0
int AIPlay::groupGivenCommandOnPhase(int groupNumber, int commandType, int phaseIndex) {
    if ((((-1 < groupNumber) && (groupNumber < 5)) && (-1 < phaseIndex)) && (phaseIndex < 10)) {
        int i = 0;
        do {
            AIPlayPhaseCommand* commandValue = this->phases[phaseIndex].command(i);
            if ((unsigned int)commandValue->groupValue == (unsigned int)groupNumber) {
                commandValue = this->phases[phaseIndex].command(i);
                if ((unsigned int)commandValue->typeValue == (unsigned int)commandType) {
                    return i;
                }
            }
            i = i + 1;
        } while (i < 5);
    }
    return -1;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040FA40
uchar AIPlay::convertToIntType(char* typeName) const {
    if (strcmp(typeName, sAttack) == 0) {
        return 1;
    }
    if (strcmp(typeName, sAnnoy) == 0) {
        return 2;
    }
    if (strcmp(typeName, sFlank) == 0) {
        return 3;
    }
    if (strcmp(typeName, sRecon) == 0) {
        return 4;
    }
    return 0;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040FB60
char* AIPlay::convertToNameType(uchar type) const {
    switch (type) {
        case 1:
            return sAttack;
        case 2:
            return sAnnoy;
        case 3:
            return sFlank;
        case 4:
            return sRecon;
        default:
            return sInvalid;
    }
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040FBB0
int AIPlay::locationsOnMap(int xOffset, int yOffset, int width, int height) {
    AIPlayPhase* phaseValue = this->phases;
    int phaseIndex = 0;
    do {
        int commandIndex = 0;
        do {
            AIPlayPhaseCommand* commandValue = phaseValue->command(commandIndex);
            if (commandValue->typeValue == 1) {
                int x = commandValue->value1Value + xOffset;
                int y = commandValue->value2Value + yOffset;
                if ((((x < 0) || (y < 0)) || (width <= x)) || (height <= y)) {
                    return 0;
                }
            }
            commandIndex = commandIndex + 1;
        } while (commandIndex < 5);
        phaseValue = phaseValue + 1;
        phaseIndex = phaseIndex + 1;
    } while (phaseIndex < 10);
    return 1;
}
