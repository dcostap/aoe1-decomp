#ifndef AOE1_AIEMOMOD_H
#define AOE1_AIEMOMOD_H

#include "aimodule.h"

class MainDecisionAIModule;

class EmotionalAIModule : public AIModule {
public:
    MainDecisionAIModule* md; // +0xF0
    int stateValue[6];        // +0xF4
    char stateNameValue[6][30]; // +0x10C

    virtual ~EmotionalAIModule();
    virtual int save(int);

    EmotionalAIModule(void*, int);
    EmotionalAIModule(int, int);
    void setMainDecisionAI(MainDecisionAIModule*);
    char* stateName(int);
    int state(int) const;
    void setState(int, int);
    void incrementState(int, int);
    void decrementState(int, int);
    int overallState() const;
    void setOverallState(int);
    int defaultState() const;
};

typedef char aiemomod_emotional_ai_module_size_check[(sizeof(EmotionalAIModule) == 0x1C0) ? 1 : -1];

#endif
