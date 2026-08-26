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
extern char s_Invalid[];

#ifndef AIPBOOK_CANONICAL_TU
class AIPlayPhaseTrigger {
protected:
    char *convertToNameType(unsigned char value) const;
};
#endif

char *AIPlayPhaseTrigger::convertToNameType(unsigned char value) const {
    switch (value) {
    case 1:
        return s_Gather;
    case 2:
        return s_Death;
    case 3:
        return s_HealthLost;
    case 4:
        return s_DamageToGroup;
    case 5:
        return s_DamageToAnyGroup;
    case 6:
        return s_Level1EnemySighted;
    case 7:
        return s_Level2EnemySighted;
    case 8:
        return s_DeathOfGroup;
    case 9:
        return s_HealOfGroup;
    case 10:
        return s_Immediate;
    case 11:
        return s_Time;
    default:
        return s_Invalid;
    }
}
