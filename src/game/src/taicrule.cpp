#include "../include/CombatRuleSystem.h"

#include <io.h>
#include <stdio.h>
#include <string.h>

CombatRuleSystem::CombatRuleSystem() {
    // Fully verified. Source of truth: taicrule.cpp.decomp @ 0x004D68D0
}

CombatRuleSystem::~CombatRuleSystem() {
    // Fully verified. Source of truth: taicrule.cpp.decomp @ 0x004D6900
}

int CombatRuleSystem::loadRules(char* param_1) {
    // Fully verified. Source of truth: taicrule.cpp.decomp @ 0x004D6910
    if (param_1 == nullptr) {
        return 0;
    }

    if (strcmp(param_1, "NONE") == 0) {
        return 0;
    }

    char temp[256];
    sprintf(temp, "%s", param_1);

    FILE* file = fopen(temp, "r");
    if (file == nullptr) {
        return 0;
    }

    memset(this->ratingValue, '2', sizeof(this->ratingValue));

    while (fgets(temp, sizeof(temp), file) != nullptr) {
        char commentTemp1 = 0;
        char commentTemp2 = 0;
        sscanf(temp, "%c%c", &commentTemp1, &commentTemp2);

        int rating = 0;
        int unitIndex = 0;
        int targetUnitType = 0;
        if ((((commentTemp1 != '/') || (commentTemp2 != '/')) &&
             (sscanf(temp, "%d %d %d", &rating, &unitIndex, &targetUnitType), -1 < rating)) &&
            (rating < 0x32)) {
            this->ratingValue[unitIndex + rating * 0x32] = (uchar)targetUnitType;
        }
    }

    fclose(file);

    if (strstr(param_1, ".tmp") != nullptr) {
        _unlink(param_1);
    }

    return 1;
}

int CombatRuleSystem::bestUnitTypeToAttack(int param_1) {
    // Fully verified. Source of truth: taicrule.cpp.decomp @ 0x004D6AA0
    (void)param_1;
    return -1;
}

int CombatRuleSystem::bestUnitTypeToDefendAgainst(int param_1) {
    // Fully verified. Source of truth: taicrule.cpp.decomp @ 0x004D6AB0
    (void)param_1;
    return -1;
}
