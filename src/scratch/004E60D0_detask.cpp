#ifndef AOE1_TAIMDMD_CONTEXT_H
class TribeTacticalAIModule {
public:
    void detask(int param);
};

class TribeMainDecisionAIModule {
public:
    char gap_0[0x1146C];
    TribeTacticalAIModule tacticalAI;

    void detask(int param);
};
#endif

void TribeMainDecisionAIModule::detask(int param) {
    this->tacticalAI.detask(param);
}
