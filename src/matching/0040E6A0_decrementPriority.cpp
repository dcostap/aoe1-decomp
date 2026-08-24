// BINARY NOTE: aimodule.cpp line 467 reads priority at +0xE8, subtracts delta,
// and calls setPriority directly. The shipped body has no temporary local.
#ifndef AOE1_AIMODULE_TU_CONTEXT
class AIModule {
public:
    virtual ~AIModule();
    int setPriority(int val);
    int decrementPriority(int delta);
    char pad[0xE4];
    int priorityValue;
};
#endif
int AIModule::decrementPriority(int delta) {
    return setPriority(priorityValue - delta);
}
