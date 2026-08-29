// Authentic source module for C:\\msdev\\work\\age1_x1\\taicrule.cpp.
//
// a handwritten source owner.

#include "../include/taicrule.h"
#include "../include/game_globals.h"
#include <string.h>
#include <stdio.h>

CombatRuleSystem::CombatRuleSystem() {}

CombatRuleSystem::~CombatRuleSystem() {}

int CombatRuleSystem::loadRules(char* filename)
{
    char line[256]; FILE* f; int a,b,c; char c1,c2;

    if (strcmp(filename, "NONE") == 0 || !filename) {
        return 0;
    }

    sprintf(line, "%s", filename);
    f = fopen(line, "r");
    if (!f)
        return 0;

    memset(ratingValue, '2', 2500);

    while (fgets(line, 256, f)) {
        sscanf(line, "%c%c", &c1, &c2);
        if (c1 == '/' && c2 == '/')
            continue;
        sscanf(line, "%d %d %d", &c, &a, &b);
        if (c < 0 || c >= 50)
            continue;
        ratingValue[a + c * 50] = (char)b;
    }

    fclose(f);
    if (strstr(filename, ".tmp"))
        unlink(filename);
    return 1;
}

int CombatRuleSystem::bestUnitTypeToAttack(int) { return -1; }

int CombatRuleSystem::bestUnitTypeToDefendAgainst(int) { return -1; }
