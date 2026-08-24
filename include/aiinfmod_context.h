#ifndef AOE1_AIINFMOD_CONTEXT_H
#define AOE1_AIINFMOD_CONTEXT_H

// Canonical declarations for the aiinfmod.cpp constructor/destructor pair.
// The AIModule ABI is limited to the constructor and virtual destructor used
// by these two source owners.
class AIModule {
public:
    virtual ~AIModule();
    AIModule(char* name, int id, int param1, void* param2);
};

class InformationAIModule : public AIModule {
public:
    InformationAIModule(void* param1, int param2);
    virtual ~InformationAIModule();
};

#endif
