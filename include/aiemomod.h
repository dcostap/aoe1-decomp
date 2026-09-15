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
    virtual int save(int outfile);

    EmotionalAIModule(void* pW, int playerID);
    EmotionalAIModule(int playerID, int infile);
    void setMainDecisionAI(MainDecisionAIModule* m);
    char* stateName(int s);
    int state(int s) const;
    void setState(int s, int value);
    void incrementState(int s, int delta);
    void decrementState(int s, int delta);
    int overallState() const;
    void setOverallState(int s);
    int defaultState() const;
};

typedef char aiemomod_emotional_ai_module_size_check[(sizeof(EmotionalAIModule) == 0x1C0) ? 1 : -1];

#endif
