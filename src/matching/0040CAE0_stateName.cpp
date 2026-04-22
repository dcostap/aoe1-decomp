class EmotionalAIModule {
public:
    char gap_00[0x10C];
    char stateNameValue[6][30];

    char* stateName(int index);
};

char* EmotionalAIModule::stateName(int index) {
    if ((index >= 0) && (index < 6)) {
        return this->stateNameValue[index];
    }
    return 0;
}
