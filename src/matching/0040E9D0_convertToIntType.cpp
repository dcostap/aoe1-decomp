// VA: 0040E9D0 AIPlayPhaseCommand::convertToIntType (535 bytes, 244 asm lines)
// Pattern: explicit int local for strcmp result

#include <string.h>

extern char s_Move[];
extern char s_Attack[];
extern char s_AttackSavedTarget[];
extern char s_Retreat[];
extern char s_Heal[];
extern char s_ResetHitPoints[];
extern char s_ResetAliveCount[];
extern char s_Wait[];

#ifndef AIPBOOK_CANONICAL_TU
class AIPlayPhaseCommand {
public:
    unsigned char convertToIntType(char *name) const;
};
#endif

unsigned char AIPlayPhaseCommand::convertToIntType(char *name) const {
    int r;
    r = strcmp(name, s_Move);
    if (r == 0) return 1;
    r = strcmp(name, s_Attack);
    if (r == 0) return 2;
    r = strcmp(name, s_AttackSavedTarget);
    if (r == 0) return 3;
    r = strcmp(name, s_Retreat);
    if (r == 0) return 4;
    r = strcmp(name, s_Heal);
    if (r == 0) return 5;
    r = strcmp(name, s_ResetHitPoints);
    if (r == 0) return 6;
    r = strcmp(name, s_ResetAliveCount);
    if (r == 0) return 7;
    r = strcmp(name, s_Wait);
    if (r == 0) return 8;
    return 0;
}
