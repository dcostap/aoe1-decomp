#ifndef AOE1_TPLAYER_TU_SHARED_CONTEXT
class TribeBuildAIModule {
public:
    void cancelBuildItem(int param_1, int param_2, int param_3, float param_4, float param_5, int param_6, int param_7);
};

class TribeMainDecisionAIModule {
public:
    char gap_000[0x104];
    TribeBuildAIModule buildAI;
};

class TRIBE_Player {
public:
    char gap_000[0x238];
    TribeMainDecisionAIModule* playerAI;

    void cancelBuild(int param_1, int param_2, int param_3, float param_4, float param_5, int param_6, int param_7);
};
#endif

void TRIBE_Player::cancelBuild(int param_1, int param_2, int param_3, float param_4, float param_5, int param_6, int param_7) {
    if (this->playerAI != 0) {
        this->playerAI->buildAI.cancelBuildItem(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
    }
}
