#ifndef AOE1_AIMODULE_TU_CONTEXT
class AIModule {
public:
    char gap_00[0xE8];
    int priorityValue;

    int setPriority(int value);
};
#endif

int AIModule::setPriority(int value) {
#ifdef AOE1_AIMODULE_TU_CONTEXT
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
#else
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
#endif
}
