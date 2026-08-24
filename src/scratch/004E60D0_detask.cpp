#ifndef AOE1_TAIMDMD_CONTEXT_H
class SubType {
public:
    void target_method(int param);
};

class TribeMainDecisionAIModule {
public:
    char gap_0[0x1146C];
    SubType tacticalAI;

    void detask(int param);
};
#endif

void TribeMainDecisionAIModule::detask(int param) {
    this->tacticalAI.target_method(param);
}
