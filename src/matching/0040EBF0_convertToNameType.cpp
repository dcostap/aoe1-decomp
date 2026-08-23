extern char s_Move[];
extern char s_Attack[];
extern char s_AttackSavedTarget[];
extern char s_Retreat[];
extern char s_Heal[];
extern char s_ResetHitPoints[];
extern char s_ResetAliveCount[];
extern char s_Wait[];
extern char s_Invalid[];

#ifndef AIPBOOK_CANONICAL_TU
class AIPlayPhaseCommand {
public:
    char *convertToNameType(unsigned char value) const;
};
#endif

char *AIPlayPhaseCommand::convertToNameType(unsigned char value) const {
    switch (value) {
    case 1:
        return s_Move;
    case 2:
        return s_Attack;
    case 3:
        return s_AttackSavedTarget;
    case 4:
        return s_Retreat;
    case 5:
        return s_Heal;
    case 6:
        return s_ResetHitPoints;
    case 7:
        return s_ResetAliveCount;
    case 8:
        return s_Wait;
    default:
        return s_Invalid;
    }
}
