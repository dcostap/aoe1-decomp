#ifndef AOE1_AIEMOMOD_TU_CONTEXT
class EmotionalAIModule {
public:
    char gap_0[0xF4];
    int stateValue[6];
    int state(int index) const;
};
#endif

int EmotionalAIModule::state(int index) const {
    if (index < 0 || index >= 6) return -1;
    return this->stateValue[index];
}
