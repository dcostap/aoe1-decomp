char* strncpy(char* dest, const char* src, unsigned int count);

#ifndef TAISTRMD_TU_CONTEXT
class VictoryConditionRuleSystem {
public:
    int loadRules(char* name);
};

class TribeStrategyAIModule {
public:
    char gap_00[0xF8];
    char ruleSetNameValue[0x170];

    int loadRules(char* name);
};
#endif

int TribeStrategyAIModule::loadRules(char* name) {
    if (name == 0) {
        return (int)name;
    }
    strncpy(this->ruleSetNameValue, name, 0xFF);
    return ((VictoryConditionRuleSystem*)((char*)this + 0x268))->loadRules(this->ruleSetNameValue);
}
