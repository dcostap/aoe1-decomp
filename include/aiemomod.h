#ifndef AOE1_AIEMOMOD_H
#define AOE1_AIEMOMOD_H

class AIModuleMessage;
class MainDecisionAIModule;

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
    virtual int processMessage(AIModuleMessage*);
    virtual int update(int);
    virtual void setCallbackMessage(AIModuleMessage*);
    virtual int filterOutMessage(AIModuleMessage*);

    AIModule(char* name, int size, int param2, void* param1);
};

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

typedef char aiemomod_ai_module_size_check[(sizeof(AIModule) == 0xF0) ? 1 : -1];
typedef char aiemomod_emotional_ai_module_size_check[(sizeof(EmotionalAIModule) == 0x1C0) ? 1 : -1];

#endif
