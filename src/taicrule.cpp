
#include "../include/taicrule.h"
#include "../include/game_globals.h"
#include <string.h>
#include <stdio.h>

CombatRuleSystem::CombatRuleSystem() {}

CombatRuleSystem::~CombatRuleSystem() {}

int CombatRuleSystem::loadRules(char* rName) {
    char temp[256];
    FILE* f;
    int unitIndex, targetUnitType, rating;
    char commentTemp1, commentTemp2;

    if (strcmp(rName, "NONE") == 0 || !rName) {
        return 0;
    }

    sprintf(temp, "%s", rName);
    f = fopen(temp, "r");
    if (!f)
        return 0;

    memset(ratingValue, '2', 2500);

    while (fgets(temp, 256, f)) {
        sscanf(temp, "%c%c", &commentTemp1, &commentTemp2);
        if (commentTemp1 == '/' && commentTemp2 == '/')
            continue;
        sscanf(temp, "%d %d %d", &rating, &unitIndex, &targetUnitType);
        if (rating < 0 || rating >= 50)
            continue;
        ratingValue[unitIndex + rating * 50] = (char)targetUnitType;
    }

    fclose(f);
    if (strstr(rName, ".tmp"))
        unlink(rName);
    return 1;
}

int CombatRuleSystem::bestUnitTypeToAttack(int tType) { return -1; }

int CombatRuleSystem::bestUnitTypeToDefendAgainst(int tType) { return -1; }
