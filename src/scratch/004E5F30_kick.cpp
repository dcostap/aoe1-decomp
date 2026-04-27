extern const char s_Got_a_kick_d_;
extern const char s_Current_Build_list_is_;

class TribeBuildAIModule {
public:
    void* vftable;
    char gap_4[0x3C];

    void skipNextBuildListItem();
    int insert(int param_1, int param_2, int param_3);
    void vf40();
};

class AIModule {
public:
    void logCommonHistory(char* param_1, const char* format, int param_2);
    void logCommonHistory2(char* param_1, const char* format);
};

class TribeMainDecisionAIModule : public AIModule {
public:
    char gap_0[0x104];
    TribeBuildAIModule* buildAI;

    void kick(int param_1);
};

void TribeMainDecisionAIModule::kick(int param_1) {
    this->logCommonHistory((char*)this, &s_Got_a_kick_d_, param_1);
    if (param_1 == 1) {
        this->buildAI->skipNextBuildListItem();
    }
    if (param_1 == 2) {
        this->buildAI->insert(0x53, 1, -1);
    }
    if (param_1 == 3) {
        this->logCommonHistory2((char*)this, &s_Current_Build_list_is_);
        this->buildAI->vf40();
    }
}
