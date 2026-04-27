// CombatRuleSystem::loadRules
// VA: 004D6910
// PDB: taicrule.cpp:35-74
//
// Attempt log:
// - draft 1: 66% diff (frame 0x10C, extra local vars)
// - draft 2: frame 0x100 (too small by 0x10, cascades to all stack offsets)
// - volatile temp: same 0x100 frame (volatile doesn't add frame size)
//
// Remaining issue: original uses sub esp, 0x110 (272 bytes), our code uses
// sub esp, 0x100 (256 bytes). The 0x10 difference is a gap between saved
// registers and temp[256] in the original. Likely due to 16-byte alignment
// of the temp buffer in the original TU context.
// 
// This cascading offset makes all stack-based accesses differ by 0x10 bytes:
// - Param access: [esp+118h] vs [esp+108h]
// - temp+4 access: [esp+24h] vs [esp+18h]
// - etc.
//
// The logic is correct (strcmp inline, memset rep stosd, file I/O loop,
// comment skipping, rating parsing and storage, fclose, strstr, unlink).
// Left in scratch: needs TU-context to force 0x110 frame.

#include "..\..\include\game_globals.h"
#include <string.h>
#include <stdio.h>

class CombatRuleSystem {
public:
    virtual ~CombatRuleSystem();
    int loadRules(char* filename);
};

int CombatRuleSystem::loadRules(char* filename)
{
    char temp[256];
    FILE* f;

    if (strcmp(filename, "NONE") == 0)
        return 0;
    if (!filename)
        return 0;

    sprintf(temp + 4, "%s", filename);
    f = fopen(temp + 4, "r");
    if (!f)
        return 0;

    memset((char*)this + 4, '2', 2500);

    while (fgets(temp + 4, 256, f)) {
        sscanf(temp + 4, "%c%c", &temp[2], &temp[3]);
        if (temp[2] == '/' && temp[3] == '/')
            continue;

        sscanf(temp + 4, "%d %d %d", (int*)&temp[0xC], (int*)&temp[0], (int*)&temp[8]);
        if (*(int*)&temp[0xC] < 0 || *(int*)&temp[0xC] >= 50)
            continue;

        ((char*)this + 4)[*(int*)&temp[0] + *(int*)&temp[0xC] * 50] = *(char*)&temp[8];
    }

    fclose(f);

    if (strstr(filename, ".tmp"))
        unlink(filename);

    return 1;
}
