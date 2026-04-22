class TribeTacticalAIModule {
public:
    char gap_00[0x21C];
    int field_21C;

    int calculatePriority(float value);
};

int TribeTacticalAIModule::calculatePriority(float value) {
    int priority;

    priority = (int)((float)this->field_21C / value);
    if (priority > 99) {
        priority = 99;
    }
    return priority;
}
