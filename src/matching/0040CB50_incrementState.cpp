class EmotionalAIModule {
public:
    char gap_00[0xF4];
    int stateValue[6];

    void incrementState(int index, int value);
};

void EmotionalAIModule::incrementState(int index, int value) {
    if ((index >= 0) && (index < 6)) {
        this->stateValue[index] = this->stateValue[index] + value;
    }
}
