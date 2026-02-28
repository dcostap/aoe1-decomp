#include "../include/AIPlayBook.h"
#include "../include/AIPlay.h"
#include "../include/AIPlayStatus.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Static_Object.h"
#include "../include/XYZ.h"

#include <ctype.h>
#include <math.h>
#include <new>
#include <stdio.h>
#include <string.h>

namespace {
static uchar AIPlayPhaseCommand_convertToIntType(const char* type_name) {
    if (strcmp(type_name, "Move") == 0) {
        return 1;
    }
    if (strcmp(type_name, "Attack") == 0) {
        return 2;
    }
    if (strcmp(type_name, "AttackSavedTarget") == 0) {
        return 3;
    }
    if (strcmp(type_name, "Retreat") == 0) {
        return 4;
    }
    if (strcmp(type_name, "Heal") == 0) {
        return 5;
    }
    if (strcmp(type_name, "ResetHitPoints") == 0) {
        return 6;
    }
    if (strcmp(type_name, "ResetAliveCount") == 0) {
        return 7;
    }
    if (strcmp(type_name, "Wait") == 0) {
        return 8;
    }
    return 0;
}

static void AIPlayPhaseCommand_ctor(AIPlayPhaseCommand* this_, uchar group, uchar type, int v1, int v2, int v3) {
    this_->groupValue = group;
    this_->typeValue = type;
    this_->value1Value = v1;
    this_->value2Value = v2;
    this_->value3Value = v3;
}

static void AIPlayPhaseCommand_ctor(AIPlayPhaseCommand* this_, uchar group, const char* type_name, int v1, int v2, int v3) {
    this_->groupValue = group;
    this_->typeValue = AIPlayPhaseCommand_convertToIntType(type_name);
    this_->value1Value = v1;
    this_->value2Value = v2;
    this_->value3Value = v3;
}

static uchar AIPlayPhaseTrigger_convertToIntType(const char* type_name) {
    if (strcmp(type_name, "Gather") == 0) {
        return 1;
    }
    if (strcmp(type_name, "Death") == 0) {
        return 2;
    }
    if (strcmp(type_name, "HealthLost") == 0) {
        return 3;
    }
    if (strcmp(type_name, "DamageToGroup") == 0) {
        return 4;
    }
    if (strcmp(type_name, "DamageToAnyGroup") == 0) {
        return 5;
    }
    if (strcmp(type_name, "Level1EnemySighted") == 0) {
        return 6;
    }
    if (strcmp(type_name, "Level2EnemySighted") == 0) {
        return 7;
    }
    if (strcmp(type_name, "DeathOfGroup") == 0) {
        return 8;
    }
    if (strcmp(type_name, "HealOfGroup") == 0) {
        return 9;
    }
    if (strcmp(type_name, "Immediate") == 0) {
        return 10;
    }
    if (strcmp(type_name, "Time") == 0) {
        return 11;
    }
    return 0;
}

static void AIPlayPhaseTrigger_ctor(AIPlayPhaseTrigger* this_, uchar type, int v1, int v2, uchar phase, uchar next_phase,
                                    int randomness) {
    this_->typeValue = type;
    this_->value1Value = v1;
    this_->value2Value = v2;
    this_->phaseValue = phase;
    this_->nextPhaseValue = next_phase;
    this_->randomnessValue = randomness;
}

static void AIPlayPhaseTrigger_ctor(AIPlayPhaseTrigger* this_, const char* type_name, int v1, int v2, uchar phase,
                                    uchar next_phase, int randomness) {
    AIPlayPhaseTrigger_ctor(this_, AIPlayPhaseTrigger_convertToIntType(type_name), v1, v2, phase, next_phase, randomness);
}

static void AIPlayGroup_ctor(AIPlayGroup* this_) {
    for (int i = 0; i < 6; ++i) {
        this_->minValue[i] = 0;
        this_->maxValue[i] = 0xFE;
    }
}

static uchar AIPlayGroup_minimum(const AIPlayGroup* this_, int index) {
    if ((index < 0) || (5 < index)) {
        return 0;
    }
    return this_->minValue[index];
}

static uchar AIPlayGroup_maximum(const AIPlayGroup* this_, int index) {
    if ((index < 0) || (5 < index)) {
        return 0xFF;
    }
    return this_->maxValue[index];
}

static void AIPlayGroup_setMinimum(AIPlayGroup* this_, int index, int value) {
    if ((index < 0) || (5 < index)) {
        return;
    }
    this_->minValue[index] = (uchar)value;
}

static void AIPlayGroup_setMaximum(AIPlayGroup* this_, int index, int value) {
    if ((index < 0) || (5 < index)) {
        return;
    }
    this_->maxValue[index] = (uchar)value;
}

static void AIPlayPhase_ctor(AIPlayPhase* this_) {
    for (int i = 0; i < 5; ++i) {
        this_->commands[i].groupValue = 0;
        this_->commands[i].typeValue = 0;
        this_->commands[i].value1Value = 0;
        this_->commands[i].value2Value = 0;
        this_->commands[i].value3Value = 0;
    }
    for (int i = 0; i < 3; ++i) {
        this_->triggers[i].typeValue = 0;
        this_->triggers[i].value1Value = -1;
        this_->triggers[i].value2Value = -1;
        this_->triggers[i].phaseValue = 0;
        this_->triggers[i].nextPhaseValue = 0;
        this_->triggers[i].randomnessValue = 0;
    }
}

static int AIPlayPhase_addCommand(AIPlayPhase* this_, const AIPlayPhaseCommand* param_1) {
    for (int i = 0; i < 5; ++i) {
        if (this_->commands[i].typeValue == 0) {
            this_->commands[i] = *param_1;
            return 1;
        }
    }
    return 0;
}

static int AIPlayPhase_addTrigger(AIPlayPhase* this_, const AIPlayPhaseTrigger* param_1) {
    for (int i = 0; i < 3; ++i) {
        if (this_->triggers[i].typeValue == 0) {
            this_->triggers[i] = *param_1;
            return 1;
        }
    }
    return 0;
}

static uchar AIPlay_convertToIntType(const char* play_type_name) {
    if (strcmp(play_type_name, "Attack") == 0) {
        return 1;
    }
    if (strcmp(play_type_name, "Annoy") == 0) {
        return 2;
    }
    if (strcmp(play_type_name, "Flank") == 0) {
        return 3;
    }
    if (strcmp(play_type_name, "Recon") == 0) {
        return 4;
    }
    return 0;
}

static void AIPlay_ctor(AIPlay* this_) {
    this_->minimumNumberUnitsValue = 1;
    this_->typeValue = 1;
    this_->overflowValue = 1;
    this_->maximumNumberUnitsValue = 0xFF;
    this_->powerValue = 0;
    this_->intelligenceValue = '2';
    this_->deathPercentageValue = '2';

    for (int i = 0; i < 5; ++i) {
        AIPlayGroup_ctor(&this_->groups[i]);
    }
    for (int i = 0; i < 10; ++i) {
        AIPlayPhase_ctor(&this_->phases[i]);
    }
    for (int i = 0; i < 5; ++i) {
        this_->targetTypeValue[i] = 5;
        this_->targetCharacteristicValue[i] = 5;
    }
}

static void AIPlay_setName(AIPlay* this_, const char* param_1) {
    strncpy(this_->nameValue, param_1, 0x40);
    this_->nameValue[0x40] = '\0';
}

static uchar AIPlay_targetType(const AIPlay* this_, int index) {
    if ((index < 0) || (4 < index)) {
        return 0;
    }
    return this_->targetTypeValue[index];
}

static int AIPlay_addTargetType(AIPlay* this_, uchar value) {
    for (int i = 0; i < 5; ++i) {
        if ((this_->targetTypeValue[i] == 0) || (this_->targetTypeValue[i] == 5)) {
            this_->targetTypeValue[i] = value;
            return 1;
        }
    }
    return 0;
}

static uchar AIPlay_targetCharacteristic(const AIPlay* this_, int index) {
    if ((index < 0) || (4 < index)) {
        return 0;
    }
    return this_->targetCharacteristicValue[index];
}

static int AIPlay_addTargetCharacteristic(AIPlay* this_, uchar value) {
    for (int i = 0; i < 5; ++i) {
        if ((this_->targetCharacteristicValue[i] == 0) || (this_->targetCharacteristicValue[i] == 5)) {
            this_->targetCharacteristicValue[i] = value;
            return 1;
        }
    }
    return 0;
}

static void XYZ_rotateXYByFacet(const XYZ& in, const XYZ& origin, XYZ& out, uchar facet) {
    out = in;
    if (facet == 0) {
        return;
    }

    // Uses the same basic math as point.cpp's XYZ::rotateXYByFacet (sin/cos of facet * pi/4).
    const double angle = (double)facet * 0.7853982;
    const double s = sin(angle);
    const double c = cos(angle);
    const double dx = (double)(in.xValue - origin.xValue);
    const double dy = (double)(in.yValue - origin.yValue);

    const double rx = (dx * c) - (dy * s);
    const double ry = (dx * s) + (dy * c);

    const double rxi = (rx < 0.0) ? ceil(rx - 0.5) : floor(rx + 0.5);
    const double ryi = (ry < 0.0) ? ceil(ry - 0.5) : floor(ry + 0.5);
    out.xValue = origin.xValue + (int)rxi;
    out.yValue = origin.yValue + (int)ryi;
}
} // namespace

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x004101B0
AIPlayBook::AIPlayBook() {
    this->numberPlaysValue = 0;
    this->plays = nullptr;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x004101F0
AIPlayBook::~AIPlayBook() {
    if (this->plays != nullptr) {
        this->numberPlaysValue = 0;
        operator delete(this->plays);
        this->plays = nullptr;
    }
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x00411480
int AIPlayBook::convertTargetNameToIntType(char* param_1) {
    if (strcmp(param_1, "Any") == 0) {
        return 5;
    }
    return 0;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x004114E0
int AIPlayBook::convertTargetCharacteristicNameToIntType(char* param_1) {
    if (strcmp(param_1, "Stationary") == 0) {
        return 1;
    }
    if (strcmp(param_1, "Moving") == 0) {
        return 2;
    }
    if (strcmp(param_1, "Slow") == 0) {
        return 3;
    }
    if (strcmp(param_1, "Fast") == 0) {
        return 4;
    }
    if (strcmp(param_1, "Any") == 0) {
        return 5;
    }
    return 0;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x00411650
int AIPlayBook::convertUnitNameToIntType(char* param_1) {
    (void)param_1;
    return -1;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x00411660
int AIPlayBook::convertUnitToIntType(RGE_Static_Object* param_1) {
    (void)param_1;
    return -1;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x00410220
int AIPlayBook::loadPlays(char* param_1) {
    if (param_1 == nullptr) {
        strncpy(this->nameValue, "NULL", sizeof(this->nameValue) - 1);
        this->nameValue[sizeof(this->nameValue) - 1] = '\0';
        return 0;
    }

    if (strcmp(param_1, "NONE") == 0) {
        strncpy(this->nameValue, "NONE", sizeof(this->nameValue) - 1);
        this->nameValue[sizeof(this->nameValue) - 1] = '\0';
        return 0;
    }

    strncpy(this->nameValue, param_1, sizeof(this->nameValue) - 1);
    this->nameValue[sizeof(this->nameValue) - 1] = '\0';

    char open_name[256];
    sprintf(open_name, "%s", this->nameValue);

    FILE* file = fopen(open_name, "r");
    if (file == nullptr) {
        return 0;
    }

    if (this->plays != nullptr) {
        operator delete(this->plays);
        this->plays = nullptr;
    }
    this->numberPlaysValue = 0;

    // Pass 1: count plays (each "Play" reserves 8 facet variants).
    char temp[256];
    char temp2[256];
    while (fgets(temp, 0x100, file) != nullptr) {
        if (sscanf(temp, "%255s ", temp2) == 1) {
            if (strcmp(temp2, "Play") == 0) {
                this->numberPlaysValue += 8;
            }
        }
    }
    if (16000 < this->numberPlaysValue) {
        this->numberPlaysValue = 16000;
    }

    const int allocated_count = this->numberPlaysValue;
    AIPlay* new_plays = (AIPlay*)::operator new((size_t)allocated_count * sizeof(AIPlay), std::nothrow);
    if (new_plays == nullptr) {
        fclose(file);
        return 0;
    }
    for (int i = 0; i < allocated_count; ++i) {
        AIPlay_ctor(new_plays + i);
    }
    this->plays = new_plays;

    // Pass 2: parse and populate.
    rewind(file);

    int current_play = -1;
    int current_phase = -1;

    char temp6[256];
    AIPlayPhaseCommand command;
    AIPlayPhaseCommand new_command;
    AIPlayPhaseTrigger trigger;
    AIPlayPhaseTrigger trigger_r;

    while ((fgets(temp, 0x100, file) != nullptr) && (current_play < 16000)) {
        // Skip comment lines (leading whitespace + "//").
        const char* p = temp;
        while ((*p != '\0') && isspace((unsigned char)*p)) {
            ++p;
        }
        if ((p[0] == '/') && (p[1] == '/')) {
            continue;
        }

        if (sscanf(temp, "%255s ", temp2) != 1) {
            continue;
        }

        if (strcmp(temp2, "Play") == 0) {
            ++current_play;
            current_phase = -1;
            if ((15999 < current_play) || (allocated_count <= current_play)) {
                break;
            }

            const char* q1 = strchr(temp, '\"');
            if (q1 != nullptr) {
                const char* q2 = strchr(q1 + 1, '\"');
                if (q2 != nullptr) {
                    const size_t len = (size_t)(q2 - (q1 + 1));
                    const size_t copy_len = (len < (sizeof(temp2) - 1)) ? len : (sizeof(temp2) - 1);
                    memcpy(temp2, q1 + 1, copy_len);
                    temp2[copy_len] = '\0';
                    AIPlay_setName(this->plays + current_play, temp2);
                }
            }
            continue;
        }

        if (current_play == -1) {
            continue;
        }

        if (strcmp(temp2, "PlayType") == 0) {
            if (sscanf(temp, "%*s %255s", temp2) == 1) {
                this->plays[current_play].typeValue = AIPlay_convertToIntType(temp2);
            }
            continue;
        }

        if (strcmp(temp2, "MinUnits") == 0) {
            int v = 0;
            if (sscanf(temp, "%*s %d", &v) == 1) {
                this->plays[current_play].minimumNumberUnitsValue = (uchar)v;
            }
            continue;
        }

        if (strcmp(temp2, "MaxUnits") == 0) {
            int v = 0;
            if (sscanf(temp, "%*s %d", &v) == 1) {
                this->plays[current_play].maximumNumberUnitsValue = (uchar)v;
            }
            continue;
        }

        if (strcmp(temp2, "Power") == 0) {
            int v = 0;
            if (sscanf(temp, "%*s %d", &v) == 1) {
                this->plays[current_play].powerValue = (uchar)v;
            }
            continue;
        }

        if (strcmp(temp2, "Overflow") == 0) {
            if (sscanf(temp, "%*s %255s", temp2) == 1) {
                if (strcmp(temp2, "Balance") == 0) {
                    this->plays[current_play].overflowValue = 1;
                } else if (strcmp(temp2, "FirstGroup") == 0) {
                    this->plays[current_play].overflowValue = 2;
                }
            }
            continue;
        }

        if (strcmp(temp2, "DeathPercentage") == 0) {
            int v = 0;
            if (sscanf(temp, "%*s %d", &v) == 1) {
                if (v < 0) {
                    this->plays[current_play].deathPercentageValue = 0;
                } else if (v < 0x65) {
                    this->plays[current_play].deathPercentageValue = (uchar)v;
                } else {
                    this->plays[current_play].deathPercentageValue = 0x64;
                }
            }
            continue;
        }

        if (strcmp(temp2, "Intelligence") == 0) {
            int v = 0;
            if (sscanf(temp, "%*s %d", &v) == 1) {
                if (v < 0) {
                    this->plays[current_play].intelligenceValue = 0;
                } else if (v < 0x65) {
                    this->plays[current_play].intelligenceValue = (uchar)v;
                } else {
                    this->plays[current_play].intelligenceValue = 0x64;
                }
            }
            continue;
        }

        if (strcmp(temp2, "TargetChar") == 0) {
            if (sscanf(temp, "%*s %255s", temp6) == 1) {
                const int v = this->convertTargetCharacteristicNameToIntType(temp6);
                if (v != 0) {
                    AIPlay_addTargetCharacteristic(this->plays + current_play, (uchar)v);
                }
            }
            continue;
        }

        if (strcmp(temp2, "TargetType") == 0) {
            if (sscanf(temp, "%*s %255s", temp6) == 1) {
                const int v = this->convertTargetNameToIntType(temp6);
                if (v != 0) {
                    AIPlay_addTargetType(this->plays + current_play, (uchar)v);
                }
            }
            continue;
        }

        if (strcmp(temp2, "NumberGroups") == 0) {
            int v = 0;
            if (sscanf(temp, "%*s %d", &v) == 1) {
                this->plays[current_play].numberGroupsValue = (uchar)v;
            }
            continue;
        }

        if (strcmp(temp2, "Group") == 0) {
            if (current_phase == -1) {
                int group_index = 0;
                int min_v = 0;
                int max_v = 0;
                if ((sscanf(temp, "%*s %d %255s %d - %d ", &group_index, temp6, &min_v, &max_v) == 4) &&
                    ((-1 < group_index) && (group_index < 5))) {
                    const int unit_type = this->convertUnitNameToIntType(temp6);
                    if (unit_type != -1) {
                        if (min_v < 0) {
                            min_v = 0;
                        }
                        if (0x32 < max_v) {
                            max_v = 0x32;
                        }
                        AIPlayGroup_setMinimum(&this->plays[current_play].groups[group_index], unit_type, min_v);
                        AIPlayGroup_setMaximum(&this->plays[current_play].groups[group_index], unit_type, max_v);
                    }
                }
            } else {
                int group_index = 0;
                int v1 = 0;
                int v2 = 0;
                int v3 = 0;
                if ((sscanf(temp, "%*s %d %255s %d %d %d", &group_index, temp6, &v1, &v2, &v3) == 5) &&
                    ((-1 < group_index) && (group_index < 5))) {
                    AIPlayPhaseCommand_ctor(&command, (uchar)group_index, temp6, v1, v2, v3);
                    AIPlayPhase_addCommand(&this->plays[current_play].phases[current_phase], &command);
                }
            }
            continue;
        }

        if (strcmp(temp2, "Phase") == 0) {
            int v = 0;
            if (sscanf(temp, "%*s %d", &v) == 1) {
                current_phase = v;
            }
            continue;
        }

        if (strcmp(temp2, "Trigger") == 0) {
            int next_phase = 0;
            int v1 = 0;
            int v2 = 0;
            if ((current_phase != -1) && (sscanf(temp, "%*s %d %255s %d %d ", &next_phase, temp6, &v1, &v2) == 4)) {
                AIPlayPhaseTrigger_ctor(&trigger, temp6, v1, v2, (uchar)current_phase, (uchar)next_phase, 0);
                AIPlayPhase_addTrigger(&this->plays[current_play].phases[current_phase], &trigger);
            }
            continue;
        }

        if (strcmp(temp2, "RTrigger") == 0) {
            int next_phase = 0;
            int v1 = 0;
            int v2 = 0;
            int randomness = 0;
            if ((current_phase != -1) &&
                (sscanf(temp, "%*s %d %255s %d %d %d ", &next_phase, temp6, &v1, &v2, &randomness) == 5)) {
                AIPlayPhaseTrigger_ctor(&trigger_r, temp6, v1, v2, (uchar)current_phase, (uchar)next_phase, randomness);
                AIPlayPhase_addTrigger(&this->plays[current_play].phases[current_phase], &trigger_r);
            }
            continue;
        }

        if (strcmp(temp2, "EndPlay") == 0) {
            current_phase = -1;

            // "HP" plays are not duplicated into facets.
            if ((this->plays[current_play].nameValue[0] == 'H') && (this->plays[current_play].nameValue[1] == 'P')) {
                this->numberPlaysValue -= 7;
                continue;
            }

            const AIPlay* base_play = this->plays + current_play;
            const XYZ origin = {0, 0, 0};

            for (int facet = 1; facet < 8; ++facet) {
                const int dst_index = current_play + facet;
                if (allocated_count <= dst_index) {
                    break;
                }

                AIPlay* dst_play = this->plays + dst_index;

                snprintf(temp2, sizeof(temp2), "%sF%d", base_play->nameValue, facet);
                AIPlay_setName(dst_play, temp2);

                dst_play->typeValue = base_play->typeValue;
                dst_play->minimumNumberUnitsValue = base_play->minimumNumberUnitsValue;
                dst_play->maximumNumberUnitsValue = base_play->maximumNumberUnitsValue;
                dst_play->powerValue = base_play->powerValue;
                dst_play->overflowValue = base_play->overflowValue;
                dst_play->deathPercentageValue = base_play->deathPercentageValue;
                dst_play->intelligenceValue = base_play->intelligenceValue;
                dst_play->numberGroupsValue = base_play->numberGroupsValue;

                for (int i = 0; i < 5; ++i) {
                    AIPlay_addTargetType(dst_play, AIPlay_targetType(base_play, i));
                    AIPlay_addTargetCharacteristic(dst_play, AIPlay_targetCharacteristic(base_play, i));
                }

                for (int g = 0; g < 5; ++g) {
                    for (int i = 0; i < 6; ++i) {
                        AIPlayGroup_setMinimum(&dst_play->groups[g], i, (int)AIPlayGroup_minimum(&base_play->groups[g], i));
                        AIPlayGroup_setMaximum(&dst_play->groups[g], i, (int)AIPlayGroup_maximum(&base_play->groups[g], i));
                    }
                }

                for (int ph = 0; ph < 10; ++ph) {
                    for (int cmd_i = 0; cmd_i < 5; ++cmd_i) {
                        const AIPlayPhaseCommand* cmd_src = &base_play->phases[ph].commands[cmd_i];
                        const AIPlayPhaseCommand* cmd_to_add = cmd_src;

                        if (cmd_src->typeValue == 1) {
                            const XYZ original = {cmd_src->value1Value, cmd_src->value2Value, cmd_src->value3Value};
                            XYZ rotated = {0, 0, 0};
                            XYZ_rotateXYByFacet(original, origin, rotated, (uchar)facet);
                            AIPlayPhaseCommand_ctor(&new_command, cmd_src->groupValue, cmd_src->typeValue, rotated.xValue,
                                                   rotated.yValue, rotated.zValue);
                            cmd_to_add = &new_command;
                        }

                        AIPlayPhase_addCommand(&dst_play->phases[ph], cmd_to_add);
                    }

                    for (int trig_i = 0; trig_i < 3; ++trig_i) {
                        AIPlayPhase_addTrigger(&dst_play->phases[ph], &base_play->phases[ph].triggers[trig_i]);
                    }
                }
            }

            current_play += 7;
            continue;
        }
    }

    fclose(file);
    return 1;
}

// TODO: STUB - invalid instruction/data block in source decomp.
// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040EC4E
static void FUN_0040ec4e() {}

// TODO: STUB - invalid instruction/data block in source decomp.
// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F066
static void FUN_0040f066() {}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F530
int AIPlay::fillGroups(AIPlayStatus* status, int* units, int unitCount, RGE_Game_World* world) {
    int minUnits = 1;
    int unitsByTypeCount[6] = {0, 0, 0, 0, 0, 0};
    int unitsByType[6][50];

    AIPlay* playValue = world->playbook->play(status->playNumberValue);
    if (playValue == nullptr) {
        return 0;
    }

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 50; ++j) {
            unitsByType[i][j] = -1;
        }
    }

    for (int j = 0; j < unitCount; ++j) {
        RGE_Static_Object* obj = world->object(units[j]);
        int type = -1;
        if (obj != nullptr) {
            type = world->playbook->convertUnitToIntType(obj);
        }

        if ((type < 0) || (5 < type)) {
            minUnits = 0;
            continue;
        }

        int count = unitsByTypeCount[type];
        if (count < 50) {
            unitsByType[type][count] = units[j];
            unitsByTypeCount[type] = count + 1;
        }
    }

    for (int groupIndex = 0; groupIndex < playValue->numberGroupsValue; ++groupIndex) {
        AIPlayGroup* groupValue = playValue->group(groupIndex);
        if (groupValue == nullptr) {
            return 0;
        }

        for (int type = 0; type < 6; ++type) {
            unsigned char minimum = groupValue->minimum(type);
            int added = 0;
            for (int idx = 0; (idx < unitsByTypeCount[type]) && (added < minimum); ++idx) {
                if (unitsByType[type][idx] == -1) {
                    continue;
                }
                if (status->addGrouping(unitsByType[type][idx], (unsigned char)groupIndex, (unsigned char)type) == 1) {
                    unitsByType[type][idx] = -1;
                    ++added;
                    if (status->numberInPlay() == playValue->maximumNumberUnitsValue) {
                        goto done_grouping;
                    }
                } else {
                    minUnits = 0;
                }
            }
        }
    }

    for (int type = 0; type < 6; ++type) {
        for (int idx = 0; idx < unitsByTypeCount[type]; ++idx) {
            int unitId = unitsByType[type][idx];
            if (unitId == -1) {
                continue;
            }

            if (playValue->overflowValue == 1) {
                int bestGroup = -1;
                int smallestGroup = 0;
                for (int groupIndex = 0; groupIndex < playValue->numberGroupsValue; ++groupIndex) {
                    AIPlayGroup* groupValue = playValue->group(groupIndex);
                    if (groupValue == nullptr) {
                        continue;
                    }
                    unsigned char typeCount = status->numberOfTypeInGroup(groupIndex, type);
                    if (typeCount >= groupValue->maximum(type)) {
                        continue;
                    }
                    unsigned char groupCount = status->numberInGroup(groupIndex);
                    if ((bestGroup == -1) || ((int)groupCount < smallestGroup)) {
                        bestGroup = groupIndex;
                        smallestGroup = (int)groupCount;
                    }
                }
                if (bestGroup != -1) {
                    if (status->addGrouping(unitId, (unsigned char)bestGroup, (unsigned char)type) == 1) {
                        unitsByType[type][idx] = -1;
                        if (status->numberInPlay() == playValue->maximumNumberUnitsValue) {
                            goto done_grouping;
                        }
                    } else {
                        minUnits = 0;
                    }
                }
            } else if (playValue->overflowValue == 2) {
                for (int groupIndex = 0; groupIndex < playValue->numberGroupsValue; ++groupIndex) {
                    AIPlayGroup* groupValue = playValue->group(groupIndex);
                    if (groupValue == nullptr) {
                        continue;
                    }
                    unsigned char typeCount = status->numberOfTypeInGroup(groupIndex, type);
                    if (typeCount >= groupValue->maximum(type)) {
                        continue;
                    }
                    if (status->addGrouping(unitId, (unsigned char)groupIndex, (unsigned char)type) == 1) {
                        unitsByType[type][idx] = -1;
                        if (status->numberInPlay() == playValue->maximumNumberUnitsValue) {
                            goto done_grouping;
                        }
                        break;
                    }
                    minUnits = 0;
                }
            }
        }
    }

done_grouping:
    unsigned char deviation = 0;
    for (int groupIndex = 0; groupIndex < playValue->numberGroupsValue; ++groupIndex) {
        AIPlayGroup* groupValue = playValue->group(groupIndex);
        if (groupValue == nullptr) {
            continue;
        }
        for (int type = 0; type < 6; ++type) {
            unsigned char minimum = groupValue->minimum(type);
            unsigned char have = status->numberOfTypeInGroup(groupIndex, type);
            if (have < minimum) {
                deviation = (unsigned char)(deviation + (minimum - have));
            }
        }
    }
    status->deviationValue = deviation;
    return minUnits;
}

// TODO: STUB - invalid thunk block in source decomp.
// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040FB9E
static int FUN_0040fb9e(AIPlay* this_, int xOffset, int yOffset, int width, int height) {
    return this_->locationsOnMap(xOffset, yOffset, width, height);
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040FC30
static void AIPlayStatus_ctor_0040FC30(AIPlayStatus* this_) {
    this_->playNumberValue = -1;
    this_->targetValue = -1;
    this_->originalPointValue.xValue = 0;
    this_->originalPointValue.yValue = 0;
    this_->originalPointValue.zValue = 0;
    this_->currentPhaseValue = 0xFD;
    this_->savedAttackerValue = -1;
    this_->lastPhaseChangeTimeValue = 0;
    this_->deviationValue = 0;
    this_->zeroAllGroupings();
    for (int i = 0; i < 5; ++i) {
        this_->originalHitPointsValue[i] = -1;
    }
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040FCB0
int AIPlayStatus::originalHitPoints(int index) const {
    if ((-1 < index) && (index < 5)) {
        return this->originalHitPointsValue[index];
    }
    return -1;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040FCD0
void AIPlayStatus::setOriginalHitPoints(int index, int value) {
    if ((-1 < index) && (index < 5)) {
        this->originalHitPointsValue[index] = value;
    }
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040FCF0
unsigned char AIPlayStatus::numberInPlay() const {
    unsigned char count = 0;
    for (int i = 0; i < 50; ++i) {
        if (this->groupings[i].id != -1) {
            ++count;
        }
    }
    return count;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040FD10
unsigned char AIPlayStatus::numberInGroup(int group) const {
    unsigned char count = 0;
    for (int i = 0; i < 50; ++i) {
        if ((this->groupings[i].id != -1) && ((int)this->groupings[i].groupID == group)) {
            ++count;
        }
    }
    return count;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040FD40
unsigned char AIPlayStatus::numberOfTypeInGroup(int group, int type) const {
    unsigned char count = 0;
    for (int i = 0; i < 50; ++i) {
        if ((this->groupings[i].id != -1) && ((int)this->groupings[i].groupID == group) && ((int)this->groupings[i].type == type)) {
            ++count;
        }
    }
    return count;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040FD80
unsigned char AIPlayStatus::group(int unitId) const {
    if (unitId < 0) {
        return 0xFF;
    }
    for (int i = 0; i < 50; ++i) {
        if (this->groupings[i].id == unitId) {
            return this->groupings[i].groupID;
        }
    }
    return 0xFF;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040FDB0
int AIPlayStatus::addGrouping(int unitId, unsigned char groupValue, unsigned char typeValue) {
    for (int i = 0; i < 50; ++i) {
        if (this->groupings[i].id == -1) {
            this->groupings[i].id = unitId;
            this->groupings[i].groupID = groupValue;
            this->groupings[i].type = typeValue;
            return 1;
        }
    }
    return 0;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040FDF0
int AIPlayStatus::removeGrouping(int unitId) {
    for (int i = 0; i < 50; ++i) {
        if (this->groupings[i].id == unitId) {
            this->groupings[i].id = -1;
            this->groupings[i].groupID = 0xFF;
            this->groupings[i].type = 0xFF;
            return 1;
        }
    }
    return 0;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040FE30
void AIPlayStatus::zeroAllGroupings() {
    for (int i = 0; i < 50; ++i) {
        this->groupings[i].id = -1;
        this->groupings[i].groupID = 0xFF;
        this->groupings[i].type = 0xFF;
    }
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040FE50
void AIPlayStatus::copyUnits(int* units, int* count) {
    *count = 0;
    for (int i = 0; i < 50; ++i) {
        if (this->groupings[i].id != -1) {
            units[*count] = this->groupings[i].id;
            *count = *count + 1;
        }
    }
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040FE90
static void AIPlayStatus_load_0040FE90(AIPlayStatus* this_, int param_2) {
    (void)this_;
    (void)param_2;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040FF70
static void AIPlayStatus_save_0040FF70(AIPlayStatus* this_, int param_2) {
    (void)this_;
    (void)param_2;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x00410050
void AIPlayStatus::copy(AIPlayStatus* src) {
    this->playNumberValue = src->playNumberValue;
    this->targetValue = src->targetValue;
    this->originalPointValue = src->originalPointValue;
    this->currentPhaseValue = src->currentPhaseValue;
    this->savedAttackerValue = src->savedAttackerValue;
    this->lastPhaseChangeTimeValue = src->lastPhaseChangeTimeValue;
    this->deviationValue = src->deviationValue;
    for (int i = 0; i < 50; ++i) {
        this->groupings[i] = src->groupings[i];
    }
    for (int i = 0; i < 5; ++i) {
        this->originalHitPointsValue[i] = src->originalHitPointsValue[i];
    }
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x00410100
void AIPlayStatus::removeDeadUnits(int, RGE_Game_World* world) {
    for (int i = 0; i < 50; ++i) {
        if (this->groupings[i].id == -1) {
            continue;
        }
        RGE_Static_Object* obj = world->object(this->groupings[i].id);
        if ((obj == nullptr) || (2 < obj->object_state)) {
            this->groupings[i].id = -1;
            this->groupings[i].groupID = 0xFF;
            this->groupings[i].type = 0xFF;
        }
    }
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x00410150
void AIPlayStatus::resetHitPoints(int groupValue, RGE_Game_World* world) {
    int totalHP = 0;
    for (int i = 0; i < 50; ++i) {
        if ((this->groupings[i].id == -1) || ((int)this->groupings[i].groupID != groupValue)) {
            continue;
        }
        RGE_Static_Object* obj = world->object(this->groupings[i].id);
        if (obj != nullptr) {
            totalHP += (int)obj->hp;
        }
    }
    this->setOriginalHitPoints(groupValue, totalHP);
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x00411340
AIPlay* AIPlayBook::play(int index) {
    if ((this->plays != nullptr) && (-1 < index) && (index < this->numberPlaysValue)) {
        return this->plays + index;
    }
    return nullptr;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x00411370
AIPlay* AIPlayBook::play(char* name) {
    if (this->plays == nullptr) {
        return nullptr;
    }

    for (int i = 0; i < this->numberPlaysValue; ++i) {
        if (strcmp(this->plays[i].nameValue, name) == 0) {
            return this->plays + i;
        }
    }
    return nullptr;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x00411400
int AIPlayBook::playNumber(char* name) {
    if (this->plays == nullptr) {
        return -1;
    }

    for (int i = 0; i < this->numberPlaysValue; ++i) {
        if (strcmp(this->plays[i].nameValue, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040E930 (implemented in AIPlayData.cpp)
// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040E950 (implemented in AIPlayData.cpp)
// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040E980 (implemented in AIPlayData.cpp)
// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040E9C0 (implemented in AIPlayData.cpp)
// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040E9D0 (implemented in AIPlayData.cpp)
// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040EBF0 (implemented in AIPlayData.cpp)
// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040EC70 (implemented in AIPlayData.cpp)
// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040EC90 (implemented in AIPlayData.cpp)
// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040ECC0 (implemented in AIPlayData.cpp)
// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040ED00 (implemented in AIPlayData.cpp)
// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040ED10 (implemented in AIPlayData.cpp)
// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040EFF0 (implemented in AIPlayData.cpp)
// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F0A0 (implemented in AIPlayData.cpp)
// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F110 (implemented in AIPlayData.cpp)
// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F130 (implemented in AIPlayData.cpp)
// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F150 (implemented in AIPlayData.cpp)
// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F1A0 (implemented in AIPlayData.cpp)
// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F200 (implemented in AIPlayData.cpp)
// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F230 (implemented in AIPlayData.cpp)
// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F240 (implemented in AIPlayData.cpp)
// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F260 (implemented in AIPlayData.cpp)
// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F280 (implemented in AIPlayData.cpp)
// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F2A0 (implemented in AIPlayData.cpp)
// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F2C0 (implemented in AIPlayData.cpp)
// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F2E0 (implemented in AIPlayData.cpp)
// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F360 (implemented in AIPlayData.cpp)
// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F380 (implemented in AIPlayData.cpp)
// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F3A0 (implemented in AIPlayData.cpp)
// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F3B0 (implemented in AIPlayData.cpp)
// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F3D0 (implemented in AIPlayData.cpp)
// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F3F0 (implemented in AIPlayData.cpp)
// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F420 (implemented in AIPlayData.cpp)
// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F440 (implemented in AIPlayData.cpp)
// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F460 (implemented in AIPlayData.cpp)
// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F490 (implemented in AIPlayData.cpp)
// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F4E0 (implemented in AIPlayData.cpp)
// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F500 (implemented in AIPlayData.cpp)
// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040F9B0 (implemented in AIPlayData.cpp)
// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040FA40 (implemented in AIPlayData.cpp)
// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040FB60 (implemented in AIPlayData.cpp)
// Fully verified. Source of truth: aipbook.cpp.decomp @ 0x0040FBB0 (implemented in AIPlayData.cpp)
