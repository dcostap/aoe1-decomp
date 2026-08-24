#ifndef AOE1_AIEMOMOD_TU_CONTEXT
class EmotionalAIModule {
public:
    char gap_0[0xF4];
    int stateValue[6];
    void setState(int index, int val);
};
#endif

void EmotionalAIModule::setState(int index, int val) {
    if (index < 0 || index >= 6) return;
    this->stateValue[index] = val;
}
