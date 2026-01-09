#pragma once
#include "common.h"

class EmotionalAIModule : public AIModule {
public:
    MainDecisionAIModule* md;                // 0xF0
    int stateValue[6];                       // 0xF4
    char* stateNameValue[6];                 // 0x10C

    virtual int save(int param_1);                          // vt0[15]+0x3C=0x40CAB0
    EmotionalAIModule(void* param_1, int param_2);
    EmotionalAIModule(int param_1, int param_2);
    ~EmotionalAIModule();
    void setMainDecisionAI(MainDecisionAIModule* param_1);
    char* stateName(int param_1);
    int state(int param_1);
    void setState(int param_1, int param_2);
    void incrementState(int param_1, int param_2);
    void decrementState(int param_1, int param_2);
    int overallState();
    void setOverallState(int param_1);
    int defaultState();
};

static_assert(sizeof(EmotionalAIModule) == 0x1C0, "EmotionalAIModule Size Mismatch");

