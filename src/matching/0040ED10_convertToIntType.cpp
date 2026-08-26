// VA: 0040ED10 AIPlayPhaseTrigger::convertToIntType (727 bytes, 331 asm lines)
// Pattern: explicit int local for strcmp result

#include <string.h>

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

#ifndef AIPBOOK_CANONICAL_TU
class AIPlayPhaseTrigger {
protected:
    unsigned char convertToIntType(char *name) const;
};
#endif

unsigned char AIPlayPhaseTrigger::convertToIntType(char *name) const {
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
