class EmotionalAIModule {
public:
    char gap_00[0xF4];
    int stateValue[6];

    void decrementState(int index, int value);
};

void EmotionalAIModule::decrementState(int index, int value) {
    if ((index >= 0) && (index < 6)) {
        this->stateValue[index] = this->stateValue[index] - value;
    }
}
