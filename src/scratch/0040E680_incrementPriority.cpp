#ifndef AOE1_AIMODULE_TU_CONTEXT
class AIModule {
public:
    virtual ~AIModule();
    int setPriority(int val);
    int incrementPriority(int delta);
    char pad[0xE4];
    int priorityValue;
};
#endif
#ifdef AOE1_AIMODULE_TU_CONTEXT
int AIModule::incrementPriority(int delta) {
    return this->setPriority(this->priorityValue + delta);
}
#else
int AIModule::incrementPriority(int delta) {
    return this->setPriority(this->priorityValue + delta);
}
#endif
