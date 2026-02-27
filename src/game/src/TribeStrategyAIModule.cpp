#include "../include/TribeStrategyAIModule.h"

#include "../include/RGE_Static_Object.h"
#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Victory_Conditions.h"
#include "../include/RGE_Victory_Entry.h"
#include "../include/TRIBE_Player.h"
#include "../include/TribeMainDecisionAIModule.h"
#include "../include/globals.h"

#include <cmath>
#include <cstdio>
#include <cstring>
#include <io.h>
#include <new>

namespace {

template <typename T>
void managed_array_resize(ManagedArray<T>* array, int new_size) {
    if (new_size <= 0) {
        return;
    }

    T* new_values = (T*)::operator new((size_t)new_size * sizeof(T), std::nothrow);
    if (new_values == nullptr) {
        return;
    }

    for (int i = 0; i < array->maximumSizeValue; ++i) {
        if (new_size <= i) {
            break;
        }
        new_values[i] = array->value[i];
    }

    ::operator delete(array->value);
    array->value = new_values;
    array->maximumSizeValue = new_size;
}

template <typename T>
void managed_array_ensure_index(ManagedArray<T>* array, int index) {
    if (array->maximumSizeValue - 1 < index) {
        managed_array_resize(array, index + 1);
    }
}

template <typename T>
int managed_array_contains(const ManagedArray<T>* array, const T* value) {
    int count = array->numberValue;
    int i = 0;
    if (count > 0) {
        while (i < array->maximumSizeValue) {
            if (array->value[i] == *value) {
                return 1;
            }
            ++i;
            if (count <= i) {
                return 0;
            }
        }
    }
    return 0;
}

template <typename T>
void managed_array_add(ManagedArray<T>* array, T value) {
    if (managed_array_contains(array, &value) != 1) {
        int index = array->numberValue;
        managed_array_ensure_index(array, index);
        if (array->value != nullptr && array->maximumSizeValue > index) {
            array->value[index] = value;
            array->numberValue = array->numberValue + 1;
        }
    }
}

template <typename T>
void managed_array_reset(ManagedArray<T>* array) {
    if (array->value != nullptr) {
        ::operator delete(array->value);
        array->value = nullptr;
    }
    array->numberValue = 0;
    array->desiredNumberValue = 0;
    array->maximumSizeValue = 0;
}

int scale_positive_int(int value, float scale) {
    if (value <= 0) {
        return value;
    }
    int scaled = (int)std::lround((double)value * (double)scale);
    if (scaled == 0) {
        scaled = 1;
    }
    return scaled;
}

int* tactical_sn_array(TRIBE_Player* player) {
    if (player == nullptr || player->playerAI == nullptr) {
        return nullptr;
    }
    unsigned char* tactical = player->playerAI->tacticalAI;
    return (int*)(tactical + 0x194);
}

void tactical_set_sn(TRIBE_Player* player, int id, int value) {
    int* sn = tactical_sn_array(player);
    if (sn == nullptr) {
        return;
    }
    if (id < 0 || id >= 226) {
        return;
    }
    sn[id] = value;
}

void apply_rule_writes(TRIBE_Player* player, const int* pairs, int pair_count) {
    for (int i = 0; i < pair_count; ++i) {
        int dst = pairs[i * 2];
        int src = pairs[i * 2 + 1];
        tactical_set_sn(player, dst, src);
    }
}

int remove_rule(ManagedArray<int>* array, int rule_id) {
    int capacity = array->maximumSizeValue;
    int index = 0;
    if (0 < capacity) {
        int* values = array->value;
        while (index < capacity) {
            if (*values == rule_id) {
                break;
            }
            ++index;
            ++values;
        }
    }

    if (index < capacity) {
        if (index < capacity - 1) {
            while (index < array->maximumSizeValue - 1) {
                int next_index = index + 1;
                array->value[index] = array->value[next_index];
                index = next_index;
            }
        }
        int new_count = array->numberValue - 1;
        array->numberValue = new_count;
        if (new_count < 0) {
            array->numberValue = 0;
        }
        return 1;
    }

    return 0;
}

int append_rule_if_missing(ManagedArray<int>* array, int rule_id) {
    int count = array->numberValue;
    int index = 0;
    if (0 < count) {
        do {
            if (array->maximumSizeValue <= index) {
                break;
            }
            if (array->value[index] == rule_id) {
                return 1;
            }
            ++index;
        } while (index < count);
    }

    if (array->maximumSizeValue - 1 < count) {
        managed_array_resize(array, count + 1);
    }

    if (array->value != nullptr && array->maximumSizeValue > array->numberValue) {
        array->value[array->numberValue] = rule_id;
        array->numberValue = array->numberValue + 1;
    }
    return 1;
}

} // namespace

// Fully verified. Source of truth: taistrmd.cpp.decomp @ 0x004E6E10
VictoryConditionRuleSystem::VictoryConditionRuleSystem() {
    static const int kDefaultSN[226] = {
        0x22, 0, 0x42, 2, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 4, -1, 4, 0x32, 0x32, -1, 0xc, 10, 0x4b, 1,
        10, -1, 4, 0x55, 0x46, 0x4b, 100, -1, 0x32, 0, 3, 0, 0, 0, 0, 4, 0, 1, 3, 0, 0x1e, 1, 0x1e, 3, 0, 0, 0, 0, 0,
        0, 7, 3, 2, 1, 5, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 1, 2, 0xc, 0x14, 3, 0xf, 0x32, 0, 0, 0, 0, 0, 0, 4, 2, 0x19,
        100, 3, -0x19, 0, 100, 5, 1, 0, 0, 0, 0, 1, 10, 3, 1, 0xf, 0, 0, 0, -1, -1, -1, 0, 0, 0, 300, 0, 0x19, 10, 10,
        0, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, -1, 0, 0, 3, 0, 0, 0, 1, 0xf, 0, 0, 0, 0, 0, 0, 1, 0, 10, 0x32, 10, 0x14,
        0x28, -1, 3, 0, -1, -1, 10, 0, 0, 0, 0, 0x32, 2, 0, 7, 10, 0x19, 7, 2, 0x32, 10, 200, 0xfa, 0x96, 200, 2, -1,
        0, -1, 10, 0x1e, 1, 1, 0, 0, 0x14, 0x32, 0, 0, 1, 0x32, 3000, 2000, 0x5dc, 3000, 1, 0x19, 1, 0x78, 0x32, 0x19,
        0x32, 0, 0x19, 1, 5, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0x32, 0, 100, 100, 8, 3, 10, 0, 0, 1
    };

    for (int i = 0; i < 226; ++i) {
        this->sn[i] = kDefaultSN[i];
    }
}

// Fully verified. Source of truth: taistrmd.cpp.decomp @ 0x004E7430
VictoryConditionRuleSystem::~VictoryConditionRuleSystem() {}

// Fully verified. Source of truth: taistrmd.cpp.decomp @ 0x004E7440
int VictoryConditionRuleSystem::loadRules(char* param_1) {
    if (param_1 == nullptr) {
        return 0;
    }

    if (std::strcmp(param_1, "NONE") == 0) {
        return 0;
    }

    if (std::strlen(param_1) == 0) {
        return 0;
    }

    FILE* file = std::fopen(param_1, "r");
    if (file == nullptr) {
        return 0;
    }

    char temp[256] = {0};
    while (std::fgets(temp, sizeof(temp), file) != nullptr) {
        char c0 = 0;
        char c1 = 0;
        std::sscanf(temp, "%c%c", &c0, &c1);

        if ((c0 == '/' && c1 == '/') || (c0 == 'D' && c1 == 'E') || (c0 == 'V' && c1 == 'C')) {
            continue;
        }
        if (c0 == 'E' && c1 == 'N') {
            break;
        }

        int rule_index = -1;
        int rule_value = 0;
        std::sscanf(temp, "%d %d", &rule_index, &rule_value);
        if (-1 < rule_index && rule_index < 0xE2) {
            this->sn[rule_index] = rule_value;
        }
    }

    std::fclose(file);

    if (std::strstr(param_1, ".tmp") != nullptr) {
        _unlink(param_1);
    }

    return 1;
}

// Fully verified. Source of truth: taistrmd.cpp.decomp @ 0x004E75D0
void VictoryConditionRuleSystem::setRule(int param_1, int param_2) {
    if (-1 < param_1 && param_1 < 0xE2) {
        this->sn[param_1] = param_2;
    }
}

// Fully verified. Source of truth: taistrmd.cpp.decomp @ 0x004E75F0
int VictoryConditionRuleSystem::rule(int param_1) {
    if (-1 < param_1 && param_1 < 0xE2) {
        return this->sn[param_1];
    }
    return -1;
}

// Fully verified. Source of truth: taistrmd.cpp.decomp @ 0x004E7610
int VictoryConditionRuleSystem::evaluateAsInProgress(TRIBE_Player* param_1, int param_2) {
    (void)param_1;
    (void)param_2;
    return 0;
}

// Fully verified. Source of truth: taistrmd.cpp.decomp @ 0x004E7620
int VictoryConditionRuleSystem::evaluateAsNonInProgress(TRIBE_Player* param_1, int param_2) {
    (void)param_1;
    switch (param_2) {
    case 1:
    case 2:
    case 0xC:
    case 0xD:
    case 0xE:
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x18:
    case 0x19:
    case 0x1A:
    case 0x1B:
    case 0x1C:
    case 0x1D:
    case 0x1E:
    case 0x1F:
    case 0x20:
    case 0x21:
    case 0x22:
    case 0x23:
    case 0x24:
    case 0x25:
    case 0x26:
    case 0x27:
    case 0x28:
    case 0x29:
    case 0x2A:
    case 0x2B:
    case 0x2C:
    case 0x2D:
    case 0x2E:
    case 0x2F:
    case 0x30:
    case 0x31:
        return -2;
    default:
        return 0;
    }
}

// Fully verified. Source of truth: taistrmd.cpp.decomp @ 0x004E7690
int VictoryConditionRuleSystem::execute(TRIBE_Player* param_1, int param_2, int param_3) {
    if (param_2 < 0 || 0xC < param_2) {
        return 0;
    }

    int final_dst = -1;
    int final_src = -1;

    switch (param_3) {
    case 1: {
        static const int pairs[] = {0,0,1,1,2,2,3,3,4,4,5,5,35,35,100,100,225,225,117,117,118,118,119,119,120,120,156,156,159,159,158,158,157,157,160,160,142,142,148,148,149,149,203,203,163,163,164,164,166,166,165,165,167,167,179,179,180,180,205,205,207,207,206,206,220,220,222,222,208,208,209,209,210,210,211,211,223,223,212,212,213,213,214,214,224,224,169,169,170,170,171,171,172,172,173,173,190,190,191,191,192,192,193,193,174,174};
        apply_rule_writes(param_1, pairs, (int)(sizeof(pairs) / sizeof(int) / 2));
        final_dst = 0xCC;
        final_src = 0xCC;
        break;
    }
    case 2: {
        static const int pairs[] = {16,16,26,26,36,36,37,37,93,93,94,94,98,98,121,121,131,131,143,143};
        apply_rule_writes(param_1, pairs, (int)(sizeof(pairs) / sizeof(int) / 2));
        final_dst = 0xA2;
        final_src = 0xA2;
        break;
    }
    case 0x0C:
        final_dst = 0x12;
        final_src = 0x12;
        break;
    case 0x0D:
        final_dst = 0x13;
        final_src = 0x13;
        break;
    case 0x0E:
        final_dst = 0x14;
        final_src = 0x14;
        break;
    case 0x10: {
        static const int pairs[] = {22,22,72,72,57,57};
        apply_rule_writes(param_1, pairs, (int)(sizeof(pairs) / sizeof(int) / 2));
        final_dst = 0x5C;
        final_src = 0x5C;
        break;
    }
    case 0x11:
        final_dst = 0x17;
        final_src = 0x17;
        break;
    case 0x12:
        final_dst = 0x18;
        final_src = 0x18;
        break;
    case 0x15: {
        static const int pairs[] = {25,25,28,28,38,38};
        apply_rule_writes(param_1, pairs, (int)(sizeof(pairs) / sizeof(int) / 2));
        final_dst = 0x27;
        final_src = 0x27;
        break;
    }
    case 0x16:
        final_dst = 0x1D;
        final_src = 0x1D;
        break;
    case 0x17: {
        static const int pairs[] = {32,32};
        apply_rule_writes(param_1, pairs, 1);
        final_dst = 0x91;
        final_src = 0x91;
        break;
    }
    case 0x18:
        final_dst = 0x22;
        final_src = 0x22;
        break;
    case 0x19: {
        static const int pairs[] = {40,40};
        apply_rule_writes(param_1, pairs, 1);
        final_dst = 0x4B;
        final_src = 0x4B;
        break;
    }
    case 0x1A:
        final_dst = 0x29;
        final_src = 0x29;
        break;
    case 0x1B: {
        static const int pairs[] = {43,43,44,44,42,42};
        apply_rule_writes(param_1, pairs, 3);
        final_dst = 0x2D;
        final_src = 0x2D;
        break;
    }
    case 0x1C: {
        static const int pairs[] = {30,30,31,31,91,91,95,95,96,96};
        apply_rule_writes(param_1, pairs, 5);
        final_dst = 0x61;
        final_src = 0x61;
        break;
    }
    case 0x1D: {
        static const int pairs[] = {46,46,102,102,47,47,103,103,104,104};
        apply_rule_writes(param_1, pairs, 5);
        final_dst = 0x86;
        final_src = 0x86;
        break;
    }
    case 0x1E:
        final_dst = 0x30;
        final_src = 0x30;
        break;
    case 0x1F: {
        static const int pairs[] = {49,49,135,135,136,136};
        apply_rule_writes(param_1, pairs, 3);
        final_dst = 200;
        final_src = 200;
        break;
    }
    case 0x20: {
        static const int pairs[] = {50,50,51,51,52,52,53,53,54,54,55,55,56,56};
        apply_rule_writes(param_1, pairs, 7);
        final_dst = 0x46;
        final_src = 0x46;
        break;
    }
    case 0x21: {
        static const int pairs[] = {58,58,59,59};
        apply_rule_writes(param_1, pairs, 2);
        final_dst = 0x3C;
        final_src = 0x3C;
        break;
    }
    case 0x22: {
        static const int pairs[] = {61,61,62,62};
        apply_rule_writes(param_1, pairs, 2);
        final_dst = 0x3F;
        final_src = 0x3F;
        break;
    }
    case 0x23: {
        static const int pairs[] = {64,64,65,65,66,66};
        apply_rule_writes(param_1, pairs, 3);
        final_dst = 0xD8;
        final_src = 0xD8;
        break;
    }
    case 0x24: {
        static const int pairs[] = {67,67,68,68};
        apply_rule_writes(param_1, pairs, 2);
        final_dst = 0x45;
        final_src = 0x45;
        break;
    }
    case 0x25:
        final_dst = 0x47;
        final_src = 0x47;
        break;
    case 0x26: {
        static const int pairs[] = {73,73};
        apply_rule_writes(param_1, pairs, 1);
        final_dst = 0x4A;
        final_src = 0x4A;
        break;
    }
    case 0x27:
        final_dst = 0x4C;
        final_src = 0x4C;
        break;
    case 0x28: {
        static const int pairs[] = {77,77,78,78,79,79,80,80,81,81,82,82,83,83,89,89,90,90,106,106,107,107,108,108,109,109,110,110,111,111,122,122,123,123,144,144,184,184};
        apply_rule_writes(param_1, pairs, (int)(sizeof(pairs) / sizeof(int) / 2));
        final_dst = 0xB9;
        final_src = 0xB9;
        break;
    }
    case 0x29: {
        static const int pairs[] = {84,84,85,85};
        apply_rule_writes(param_1, pairs, 2);
        final_dst = 0x89;
        final_src = 0x89;
        break;
    }
    case 0x2A: {
        static const int pairs[] = {86,86,87,87,202,202,150,150,151,151,152,152,161,161};
        apply_rule_writes(param_1, pairs, 7);
        final_dst = 0xA8;
        final_src = 0xA8;
        break;
    }
    case 0x2B: {
        static const int pairs[] = {88,88,101,101,155,155,175,175,176,176,177,177,181,181,182,182,183,183,186,186,187,187,194,194,196,196,197,197,188,188,195,195,189,189,198,198,199,199,215,215,217,217,218,218,219,219};
        apply_rule_writes(param_1, pairs, (int)(sizeof(pairs) / sizeof(int) / 2));
        final_dst = 0xDD;
        final_src = 0xDD;
        break;
    }
    case 0x2C:
        final_dst = 99;
        final_src = 99;
        break;
    case 0x2D:
        final_dst = 0x69;
        final_src = 0x69;
        break;
    case 0x2E:
        final_dst = 0x70;
        final_src = 0x70;
        break;
    case 0x2F: {
        static const int pairs[] = {113,113,114,114,115,115,116,116,146,146};
        apply_rule_writes(param_1, pairs, 5);
        final_dst = 0x93;
        final_src = 0x93;
        break;
    }
    case 0x30: {
        static const int pairs[] = {124,124,125,125,126,126,127,127,128,128,129,129,130,130,132,132,133,133,178,178};
        apply_rule_writes(param_1, pairs, (int)(sizeof(pairs) / sizeof(int) / 2));
        final_dst = 0xC9;
        final_src = 0xC9;
        break;
    }
    case 0x31: {
        static const int pairs[] = {138,138,139,139,140,140};
        apply_rule_writes(param_1, pairs, 3);
        final_dst = 0x8D;
        final_src = 0x8D;
        break;
    }
    default:
        return 0;
    }

    if (final_dst >= 0 && final_src >= 0) {
        tactical_set_sn(param_1, final_dst, this->sn[final_src]);
    }

    return 1;
}

// Fully verified. Source of truth: taistrmd.cpp.decomp @ 0x004E8D10
int VictoryConditionRuleSystem::stopExecution(TRIBE_Player* param_1, int param_2) {
    (void)param_1;
    (void)param_2;
    return 0;
}

// Fully verified. Source of truth: taistrmd.cpp.decomp @ 0x004E8D20
void VictoryConditionRuleSystem::modifyForDifficultyLevel(int param_1) {
    if (param_1 == 0) {
        return;
    }

    int scale2 = 0;
    int additive = 0;
    int scale4 = 0;
    float scale3 = 1.0f;
    float scale1 = 1.0f;

    switch (param_1) {
    case 1:
        if (rge_base_game != nullptr && rge_base_game->scenarioGame() == 1) {
            scale3 = 0.8f;
            scale2 = 0x1E;
            scale1 = 0.8f;
            additive = 0x78;
            scale4 = 1;
        }
        break;
    case 2:
        scale3 = 0.6f;
        scale2 = 0x3C;
        scale1 = 0.6f;
        additive = 0xF0;
        scale4 = 2;
        break;
    case 3:
        scale3 = 0.4f;
        scale2 = 0x5A;
        scale1 = 0.4f;
        additive = ((rge_base_game != nullptr && rge_base_game->scenarioGame() != 1) ? 0x21C : 0) + 0x168;
        scale4 = 3;
        break;
    case 4:
        scale3 = 0.2f;
        scale2 = 0x78;
        scale1 = 0.2f;
        additive = ((rge_base_game != nullptr && rge_base_game->scenarioGame() != 1) ? 0x30C : 0) + 0x1E0;
        scale4 = 4;
        break;
    default:
        return;
    }

    this->sn[0x24] = scale_positive_int(this->sn[0x24], scale3);
    this->sn[0x10] = scale_positive_int(this->sn[0x10], scale3);
    this->sn[0x1A] = scale_positive_int(this->sn[0x1A], scale3);

    this->sn[0x2E] = this->sn[0x2E] + scale2;
    this->sn[0x30] = this->sn[0x30] + scale2;

    this->sn[0x13] = scale_positive_int(this->sn[0x13], scale1);
    this->sn[0x14] = scale_positive_int(this->sn[0x14], scale1);

    this->sn[0x68] = this->sn[0x68] + additive;

    this->sn[0x19] = scale_positive_int(this->sn[0x19], scale3);
    this->sn[0x1C] = scale_positive_int(this->sn[0x1C], scale3);
    this->sn[0x26] = scale_positive_int(this->sn[0x26], scale3);
    this->sn[0x3A] = scale_positive_int(this->sn[0x3A], scale3);
    this->sn[0x3B] = scale_positive_int(this->sn[0x3B], scale3);
    this->sn[0x3C] = scale_positive_int(this->sn[0x3C], scale3);
    this->sn[0x43] = scale_positive_int(this->sn[0x43], scale3);
    this->sn[0x44] = scale_positive_int(this->sn[0x44], scale3);
    this->sn[0x45] = scale_positive_int(this->sn[0x45], scale3);

    this->sn[0x58] = this->sn[0x58] + scale4;
    this->sn[0x67] = (param_1 < 4) ? 1 : 0;
}

// Fully verified. Source of truth: taistrmd.cpp.decomp @ 0x004E9100
TribeStrategyAIModule::TribeStrategyAIModule(void* param_1, int param_2)
    : StrategyAIModule(param_1, param_2) {
    this->md = nullptr;
    this->currentVictoryConditionValue = -1;
    this->targetIDValue = -1;
    this->targetTypeValue = -1;
    this->secondTargetIDValue = -1;
    this->secondTargetTypeValue = -1;
    this->targetAttributeValue = -1;
    this->targetNumberValue = -1;
    this->victoryConditionChangeTimeout = 0;

    this->vcRuleSet.value = nullptr;
    this->vcRuleSet.numberValue = 0;
    this->vcRuleSet.desiredNumberValue = 0;
    this->vcRuleSet.maximumSizeValue = 0;

    this->executingRules.value = nullptr;
    this->executingRules.numberValue = 0;
    this->executingRules.desiredNumberValue = 0;
    this->executingRules.maximumSizeValue = 0;

    this->idleRules.value = nullptr;
    this->idleRules.numberValue = 0;
    this->idleRules.desiredNumberValue = 0;
    this->idleRules.maximumSizeValue = 0;

    this->targetPoint1Value.x = -1.0f;
    this->targetPoint1Value.y = -1.0f;
    this->targetPoint1Value.z = -1.0f;

    this->targetPoint2Value.x = -1.0f;
    this->targetPoint2Value.y = -1.0f;
    this->targetPoint2Value.z = -1.0f;

    this->difficultyLevel = 0;
    this->ruleSetNameValue[0] = '\0';
}

// Fully verified. Source of truth: taistrmd.cpp.decomp @ 0x004E9260
TribeStrategyAIModule::TribeStrategyAIModule(int param_1, int param_2)
    : StrategyAIModule(nullptr, param_1) {
    this->md = nullptr;
    this->targetTypeValue = -1;

    this->vcRuleSet.value = nullptr;
    this->vcRuleSet.numberValue = 0;
    this->vcRuleSet.desiredNumberValue = 0;
    this->vcRuleSet.maximumSizeValue = 0;

    this->executingRules.value = nullptr;
    this->executingRules.numberValue = 0;
    this->executingRules.desiredNumberValue = 0;
    this->executingRules.maximumSizeValue = 0;

    this->idleRules.value = nullptr;
    this->idleRules.numberValue = 0;
    this->idleRules.desiredNumberValue = 0;
    this->idleRules.maximumSizeValue = 0;

    this->difficultyLevel = 0;

    rge_read(param_2, &this->currentVictoryConditionValue, 4);
    rge_read(param_2, &this->targetIDValue, 4);
    rge_read(param_2, &this->secondTargetIDValue, 4);
    rge_read(param_2, &this->secondTargetTypeValue, 4);
    rge_read(param_2, &this->targetPoint1Value, 0x10);
    rge_read(param_2, &this->targetPoint2Value, 0x10);
    rge_read(param_2, &this->targetAttributeValue, 4);
    rge_read(param_2, &this->targetNumberValue, 4);
    rge_read(param_2, &this->victoryConditionChangeTimeout, 4);

    if (1.5f <= save_game_version) {
        rge_read(param_2, &this->difficultyLevel, 4);
    }

    int rule_set_name_size = 0;
    rge_read(param_2, &rule_set_name_size, 4);
    rge_read(param_2, this->ruleSetNameValue, rule_set_name_size);
    this->ruleSetNameValue[rule_set_name_size] = '\0';

    this->loadRules(this->ruleSetNameValue);
    this->setDifficultyLevel(this->difficultyLevel);

    int count = 0;
    rge_read(param_2, &count, 4);
    for (int i = 0; i < count; ++i) {
        int value = 0;
        rge_read(param_2, &value, 4);
        managed_array_add(&this->vcRuleSet, value);
    }

    rge_read(param_2, &count, 4);
    for (int i = 0; i < count; ++i) {
        int value = 0;
        rge_read(param_2, &value, 4);
        managed_array_add(&this->executingRules, value);
    }

    rge_read(param_2, &count, 4);
    for (int i = 0; i < count; ++i) {
        int value = 0;
        rge_read(param_2, &value, 4);
        managed_array_add(&this->idleRules, value);
    }
}

// Fully verified. Source of truth: taistrmd.cpp.decomp @ 0x004E9730
TribeStrategyAIModule::~TribeStrategyAIModule() {
    managed_array_reset(&this->idleRules);
    managed_array_reset(&this->executingRules);
    managed_array_reset(&this->vcRuleSet);
}

int TribeStrategyAIModule::loggingHistory() { return StrategyAIModule::loggingHistory(); }
void TribeStrategyAIModule::setLogHistory(int param_1) { StrategyAIModule::setLogHistory(param_1); }
void TribeStrategyAIModule::toggleLogHistory() { StrategyAIModule::toggleLogHistory(); }
void TribeStrategyAIModule::setHistoryFilename(char* param_1) { StrategyAIModule::setHistoryFilename(param_1); }
int TribeStrategyAIModule::loggingCommonHistory() { return StrategyAIModule::loggingCommonHistory(); }
void TribeStrategyAIModule::setLogCommonHistory(int param_1) { StrategyAIModule::setLogCommonHistory(param_1); }
void TribeStrategyAIModule::toggleLogCommonHistory() { StrategyAIModule::toggleLogCommonHistory(); }
int TribeStrategyAIModule::loadState(char* param_1) { return StrategyAIModule::loadState(param_1); }
int TribeStrategyAIModule::saveState(char* param_1) { return StrategyAIModule::saveState(param_1); }
int TribeStrategyAIModule::gleanState(int param_1) { return StrategyAIModule::gleanState(param_1); }
int TribeStrategyAIModule::processMessage(AIModuleMessage* param_1) { return StrategyAIModule::processMessage(param_1); }
void TribeStrategyAIModule::setCallbackMessage(AIModuleMessage* param_1) { StrategyAIModule::setCallbackMessage(param_1); }
int TribeStrategyAIModule::filterOutMessage(AIModuleMessage* param_1) { return StrategyAIModule::filterOutMessage(param_1); }

// Fully verified. Source of truth: taistrmd.cpp.decomp @ 0x004E9820
int TribeStrategyAIModule::update(int param_1) {
    (void)param_1;

    int iVar7 = 0;
    int iVar2 = this->victoryConditionChangeTimeout + 1;
    this->victoryConditionChangeTimeout = iVar2;

    if (-1 < iVar2) {
        this->victoryConditionChangeTimeout = 0;
        unsigned int uVar8 = 0xB;

        RGE_Victory_Entry* victory_entry = nullptr;
        if (this->md != nullptr && this->md->player != nullptr && this->md->player->victory_conditions != nullptr) {
            victory_entry = this->md->player->victory_conditions->condition_raw_info(0);
        }

        if (victory_entry != nullptr) {
            uVar8 = (unsigned int)victory_entry->command;

            if (victory_entry->target_obj != nullptr) {
                this->targetIDValue = victory_entry->target_obj->id;
                this->targetTypeValue = (int)victory_entry->target_obj->master_obj->id;
            }
            if (victory_entry->this_obj != nullptr) {
                this->secondTargetIDValue = victory_entry->this_obj->id;
                this->secondTargetTypeValue = (int)victory_entry->this_obj->master_obj->id;
            }

            this->targetPoint1Value.x = victory_entry->x0;
            this->targetPoint1Value.y = victory_entry->y0;
            this->targetPoint1Value.z = 1.0f;
            this->targetPoint2Value.x = victory_entry->x1;
            this->targetPoint2Value.y = victory_entry->y1;
            this->targetPoint2Value.z = 1.0f;
            this->targetAttributeValue = victory_entry->number;
            this->targetNumberValue = victory_entry->count;
        }

        if (uVar8 != (unsigned int)this->currentVictoryConditionValue) {
            this->setVictoryCondition((int)uVar8);
        }
    }

    int best_rule_value = 0;
    int chosen_rule = -1;
    int current_rule = -1;

    if (0 < this->idleRules.numberValue) {
        ManagedArray<int>* idle = &this->idleRules;
        do {
            managed_array_ensure_index(idle, iVar7);
            current_rule = this->vcRules.evaluateAsNonInProgress(this->md->aiPlayer, idle->value[iVar7]);
            if (best_rule_value < current_rule) {
                managed_array_ensure_index(idle, iVar7);
                chosen_rule = idle->value[iVar7];
                best_rule_value = current_rule;
            }
            iVar7 = iVar7 + 1;
            current_rule = chosen_rule;
        } while (iVar7 < this->idleRules.numberValue);
    }

    if ((current_rule != -1) &&
        (this->vcRules.execute(this->md->aiPlayer, this->currentVictoryConditionValue, current_rule) == 1)) {
        append_rule_if_missing(&this->executingRules, current_rule);
        remove_rule(&this->idleRules, current_rule);
    }

    iVar7 = 0;
    int worst_rule_result = -1;
    int result = 0x65;
    iVar2 = -1;

    if (0 < this->executingRules.numberValue) {
        ManagedArray<int>* executing = &this->executingRules;
        do {
            managed_array_ensure_index(executing, iVar7);
            iVar2 = this->vcRules.evaluateAsInProgress(this->md->aiPlayer, executing->value[iVar7]);
            if (iVar2 < result) {
                managed_array_ensure_index(executing, iVar7);
                worst_rule_result = executing->value[iVar7];
                result = iVar2;
            }
            iVar7 = iVar7 + 1;
            iVar2 = worst_rule_result;
        } while (iVar7 < this->executingRules.numberValue);
    }

    if ((iVar2 != -1) && (this->vcRules.stopExecution(this->md->aiPlayer, iVar2) == 1)) {
        remove_rule(&this->executingRules, iVar2);
        append_rule_if_missing(&this->idleRules, iVar2);
    }

    iVar2 = 0;
    if (0 < this->vcRuleSet.numberValue) {
        do {
            managed_array_ensure_index(&this->vcRuleSet, iVar2);
            int eval = this->vcRules.evaluateAsNonInProgress(this->md->aiPlayer, this->vcRuleSet.value[iVar2]);
            if (eval == -1) {
                managed_array_ensure_index(&this->vcRuleSet, iVar2);
                this->vcRules.execute(this->md->aiPlayer, this->currentVictoryConditionValue, this->vcRuleSet.value[iVar2]);
            }
            iVar2 = iVar2 + 1;
        } while (iVar2 < this->vcRuleSet.numberValue);
    }

    return 1;
}

// Fully verified. Source of truth: taistrmd.cpp.decomp @ 0x004E9D90
void TribeStrategyAIModule::setMainDecisionAI(TribeMainDecisionAIModule* param_1) { this->md = param_1; }

// Fully verified. Source of truth: taistrmd.cpp.decomp @ 0x004E9DA0
int TribeStrategyAIModule::save(int param_1) {
    rge_write(param_1, &this->currentVictoryConditionValue, 4);
    rge_write(param_1, &this->targetIDValue, 4);
    rge_write(param_1, &this->secondTargetIDValue, 4);
    rge_write(param_1, &this->secondTargetTypeValue, 4);
    rge_write(param_1, &this->targetPoint1Value, 0x10);
    rge_write(param_1, &this->targetPoint2Value, 0x10);
    rge_write(param_1, &this->targetAttributeValue, 4);
    rge_write(param_1, &this->targetNumberValue, 4);
    rge_write(param_1, &this->victoryConditionChangeTimeout, 4);
    rge_write(param_1, &this->difficultyLevel, 4);

    int len = (int)std::strlen(this->ruleSetNameValue);
    rge_write(param_1, &len, 4);
    if (len > 0) {
        rge_write(param_1, this->ruleSetNameValue, len);
    }

    int count = this->vcRuleSet.numberValue;
    rge_write(param_1, &count, 4);
    for (int i = 0; i < this->vcRuleSet.numberValue; ++i) {
        managed_array_ensure_index(&this->vcRuleSet, i);
        int value = this->vcRuleSet.value[i];
        rge_write(param_1, &value, 4);
    }

    count = this->executingRules.numberValue;
    rge_write(param_1, &count, 4);
    for (int i = 0; i < this->executingRules.numberValue; ++i) {
        managed_array_ensure_index(&this->executingRules, i);
        int value = this->executingRules.value[i];
        rge_write(param_1, &value, 4);
    }

    count = this->idleRules.numberValue;
    rge_write(param_1, &count, 4);
    for (int i = 0; i < this->idleRules.numberValue; ++i) {
        managed_array_ensure_index(&this->idleRules, i);
        int value = this->idleRules.value[i];
        rge_write(param_1, &value, 4);
    }

    return 1;
}

// Fully verified. Source of truth: taistrmd.cpp.decomp @ 0x004EA130
char* TribeStrategyAIModule::ruleSetName() { return this->ruleSetNameValue; }

// Fully verified. Source of truth: taistrmd.cpp.decomp @ 0x004EA140
int TribeStrategyAIModule::loadRules(char* param_1) {
    if (param_1 == nullptr) {
        return 0;
    }

    std::strncpy(this->ruleSetNameValue, param_1, 0xFF);
    return this->vcRules.loadRules(this->ruleSetNameValue);
}

// Fully verified. Source of truth: taistrmd.cpp.decomp @ 0x004EA180
void TribeStrategyAIModule::setRule(int param_1, int param_2) {
    this->AIModule::logCommonHistory((char*)"Setting SN %d to %d", param_1, param_2);
    this->vcRules.setRule(param_1, param_2);
}

// Fully verified. Source of truth: taistrmd.cpp.decomp @ 0x004EA1B0
int TribeStrategyAIModule::rule(int param_1) { return this->vcRules.rule(param_1); }

// Fully verified. Source of truth: taistrmd.cpp.decomp @ 0x004EA1D0
void TribeStrategyAIModule::setDifficultyLevel(int param_1) { this->vcRules.modifyForDifficultyLevel(param_1); }

// Fully verified. Source of truth: taistrmd.cpp.decomp @ 0x004EA1F0
int TribeStrategyAIModule::currentVictoryCondition() const { return this->currentVictoryConditionValue; }

// Fully verified. Source of truth: taistrmd.cpp.decomp @ 0x004EA200
int TribeStrategyAIModule::targetID() const { return this->targetIDValue; }

// Fully verified. Source of truth: taistrmd.cpp.decomp @ 0x004EA210
int TribeStrategyAIModule::targetType() const { return this->targetTypeValue; }

// Fully verified. Source of truth: taistrmd.cpp.decomp @ 0x004EA220
int TribeStrategyAIModule::secondTargetID() const { return this->secondTargetIDValue; }

// Fully verified. Source of truth: taistrmd.cpp.decomp @ 0x004EA230
int TribeStrategyAIModule::secondTargetType() const { return this->secondTargetTypeValue; }

// Fully verified. Source of truth: taistrmd.cpp.decomp @ 0x004EA240
const Waypoint& TribeStrategyAIModule::targetPoint1() const { return this->targetPoint1Value; }

// Fully verified. Source of truth: taistrmd.cpp.decomp @ 0x004EA250
const Waypoint& TribeStrategyAIModule::targetPoint2() const { return this->targetPoint2Value; }

// Fully verified. Source of truth: taistrmd.cpp.decomp @ 0x004EA260
int TribeStrategyAIModule::targetAttribute() const { return this->targetAttributeValue; }

// Fully verified. Source of truth: taistrmd.cpp.decomp @ 0x004EA270
int TribeStrategyAIModule::targetNumber() const { return this->targetNumberValue; }

// Fully verified. Source of truth: taistrmd.cpp.decomp @ 0x004EA280
void TribeStrategyAIModule::setVictoryCondition(int param_1) {
    this->currentVictoryConditionValue = param_1;
    this->vcRuleSet.numberValue = 0;

    static const int all_rules[] = {
        1, 2, 0xC, 0xD, 0xE, 0x10, 0x11, 0x12, 0x15, 0x16, 0x17, 0x18, 0x19,
        0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x20, 0x21, 0x22, 0x23, 0x24,
        0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F,
        0x30, 0x31
    };

    for (int i = 0; i < (int)(sizeof(all_rules) / sizeof(all_rules[0])); ++i) {
        managed_array_add(&this->vcRuleSet, all_rules[i]);
    }

    int iVar3 = 0;
    if (0 < this->vcRuleSet.numberValue) {
        do {
            int rule_id = this->vcRuleSet.value[iVar3];
            int eval = this->vcRules.evaluateAsNonInProgress(this->md->aiPlayer, rule_id);
            if (eval == -2) {
                int exec = this->vcRules.execute(this->md->aiPlayer, this->currentVictoryConditionValue, rule_id);
                if (exec == 1) {
                    managed_array_add(&this->executingRules, rule_id);
                } else {
                    managed_array_add(&this->idleRules, rule_id);
                }
            }
            iVar3 = iVar3 + 1;
        } while (iVar3 < this->vcRuleSet.numberValue);
    }
}

// Fully verified. Source of truth: taistrmd.cpp.decomp @ 0x004EA7C0
int TribeStrategyAIModule::isRuleExecuting(int param_1) {
    return managed_array_contains(&this->executingRules, &param_1);
}

// Fully verified. Source of truth: taistrmd.cpp.decomp @ 0x004EA810
int TribeStrategyAIModule::isRuleIdle(int param_1) {
    return managed_array_contains(&this->idleRules, &param_1);
}
