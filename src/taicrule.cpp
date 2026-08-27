// Authentic source module for C:\\msdev\\work\\age1_x1\\taicrule.cpp.
// The definitions follow the PDB source and address order.
//
// 004D68E0 is the compiler-generated scalar deleting destructor.  It is not
// a handwritten source owner.

#include "../include/taicrule.h"
#include "../include/game_globals.h"
#include <string.h>
#include <stdio.h>

// VA 004D68D0; taicrule.cpp lines 23-24; matching.
CombatRuleSystem::CombatRuleSystem() {}

// VA 004D6900; taicrule.cpp lines 29-30; matching.
CombatRuleSystem::~CombatRuleSystem() {}

// VA 004D6910; taicrule.cpp lines 35-74; accepted drift.
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

    memset((char*)this + 4, '2', 2500);

    while (fgets(line, 256, f)) {
        sscanf(line, "%c%c", &c1, &c2);
        if (c1 == '/' && c2 == '/')
            continue;
        sscanf(line, "%d %d %d", &c, &a, &b);
        if (c < 0 || c >= 50)
            continue;
        ((char*)this + 4)[a + c * 50] = (char)b;
    }

    fclose(f);
    if (strstr(filename, ".tmp"))
        unlink(filename);
    return 1;
}

// VA 004D6AA0; taicrule.cpp lines 79-81; matching.
int CombatRuleSystem::bestUnitTypeToAttack(int) { return -1; }

// VA 004D6AB0; taicrule.cpp lines 86-88; matching.
int CombatRuleSystem::bestUnitTypeToDefendAgainst(int) { return -1; }
