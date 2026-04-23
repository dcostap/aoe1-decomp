class EmotionalAIModule {
public:
    char gap_00[0xF4];
    int stateValue[6];

    int overallState(void) const;
};

int EmotionalAIModule::overallState(void) const {
    int maxValue = this->stateValue[0];
    int result = 0;
    int i = 1;
    const int* values = &this->stateValue[1];

    while (i < 6) {
        if (maxValue < *values) {
            result = i;
            maxValue = *values;
        }
        i++;
        values++;
    }
    return result;
}
