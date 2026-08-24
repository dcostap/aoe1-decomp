#ifndef AOE1_AIEMOMOD_CONTEXT_H
#define AOE1_AIEMOMOD_CONTEXT_H

// Authentic declaration surface for aiemomod.cpp.  AIModule owns the first
// fifteen virtual slots; EmotionalAIModule adds save at slot 15 and stores
// its reviewed fields at +0xF0 through +0x1BF.
class AIModule {
public:
    char gap_04[0xEC];

    virtual ~AIModule();
    virtual int loggingHistory();
    virtual void setLogHistory(int);
    virtual void toggleLogHistory();
    virtual void setHistoryFilename(char*);
    virtual int loggingCommonHistory();
    virtual void setLogCommonHistory(int);
    virtual void toggleLogCommonHistory();
    virtual int loadState(char*);
    virtual int saveState(char*);
    virtual int gleanState(int);
    virtual int processMessage(class AIModuleMessage*);
    virtual int update(int);
    virtual void setCallbackMessage(class AIModuleMessage*);
    virtual int filterOutMessage(class AIModuleMessage*);

    AIModule(char* name, int size, int param2, void* param1);
};

class EmotionalAIModule : public AIModule {
public:
    class MainDecisionAIModule* md; // +0xF0
    int stateValue[6];              // +0xF4
    char stateNameValue[6][30];      // +0x10C

    virtual ~EmotionalAIModule();
    virtual int save(int);

    EmotionalAIModule(void*, int);
    EmotionalAIModule(int, int);
    void setMainDecisionAI(class MainDecisionAIModule*);
    char* stateName(int);
    int state(int) const;
    void setState(int, int);
    void incrementState(int, int);
    void decrementState(int, int);
    int overallState() const;
    void setOverallState(int);
    int defaultState() const;
};

#endif
