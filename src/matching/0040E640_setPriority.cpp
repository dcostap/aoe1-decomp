class AIModule {
public:
    char gap_00[0xE8];
    int priorityValue;

    int setPriority(int value);
};

int AIModule::setPriority(int value) {
    priorityValue = value;
    if (value < 1) {
        priorityValue = 1;
        return 0;
    }
    if (value > 100) {
        priorityValue = 100;
        return 0;
    }
    return 1;
}
