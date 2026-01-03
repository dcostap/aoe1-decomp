#pragma once
#include "../common.h"
#include "aimdmod.h"
#include "aimodule.h"

class EmotionalAIModule : public AIModule {
public:
    MainDecisionAIModule* md;                // 0xF0
    int stateValue[6];                       // 0xF4
    char stateNameValue[6][30];                 // 0x10C

    EmotionalAIModule(void* param_1, int param_2);
    EmotionalAIModule(int param_1, int param_2);
    virtual ~EmotionalAIModule();
    virtual void setMainDecisionAI(MainDecisionAIModule* param_1);
    virtual int save(int param_1);
    virtual char* stateName(int param_1);
    virtual int state(int param_1);
    virtual void setState(int param_1, int param_2);
    virtual void incrementState(int param_1, int param_2);
    virtual void decrementState(int param_1, int param_2);
    virtual int overallState();
    virtual void setOverallState(int param_1);
    virtual int defaultState();
};

static_assert(sizeof(EmotionalAIModule) == 0x1C0, "EmotionalAIModule Size Mismatch");
static_assert(offsetof(EmotionalAIModule, stateNameValue) == 0x10C, "EmotionalAIModule Offset Mismatch");

