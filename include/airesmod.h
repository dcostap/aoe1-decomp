#ifndef AOE1_AIRESMOD_H
#define AOE1_AIRESMOD_H

struct _iobuf;
class AIModuleMessage;
class MainDecisionAIModule;

class AIModuleID {
public:
    AIModuleID(char*, int);
    virtual ~AIModuleID();
    int id;
    char name[64];
};

class AIModule {
public:
    AIModule(char*, int, int, void*);
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
protected:
    virtual int filterOutMessage(AIModuleMessage*);
public:
    void __cdecl logCommonHistory(char*, ...);

    AIModuleID idValue;
    int playerNumberValue;
    char playerNameValue[64];
    int runningValue;
    int pausedValue;
    int logHistoryValue;
    int logCommonHistoryValue;
    _iobuf* historyLogFile;
    char historyLogFilename[64];
    int intelligenceLevelValue;
    int priorityValue;
    int processFrameValue;
};

class ResourceItem {
public:
    virtual ~ResourceItem();
    ResourceItem* next;
    ResourceItem* prev;
    int valueValue[8];
    int sortedValue[8];
    int sortedIndexValue[8];
    int numberValue;

    int number() const;
    int value(int) const;
};

class ResourceAIModule : public AIModule {
public:
    ResourceAIModule(void* owner, int player, int resourceCount,
                     int initialValue, int minimumValue, int maximumValue);
    virtual ~ResourceAIModule();
    virtual int processMessage(AIModuleMessage*);
    virtual int update(int);
    virtual void setCallbackMessage(AIModuleMessage*);
protected:
    virtual int filterOutMessage(AIModuleMessage*);

public:
    MainDecisionAIModule* md;
    int numberResourcesValue;
    int* resourceValue;
    int* minValue;
    int* maxValue;
    int** resourceTypesValue;
    int* numberResourceTypesValue;

    void setMainDecisionAI(MainDecisionAIModule* decisionAI);
    int numberResources() const;
    int resource(int) const;
    int resourcesAvailable(ResourceItem*);
    int unavailableResource(ResourceItem*);
    int minValueOfResource(int) const;
    int maxValueOfResource(int) const;
    void setResource(int, int);
    void setResources(ResourceItem*);
    void incrementResource(int, int);
    void incrementResources(ResourceItem*);
    void decrementResource(int, int);
    void decrementResources(ResourceItem*);
    void setResourceMin(int, int);
    void setResourceMax(int, int);
    void addResourceType(int resourceIndex, int type);
    int isResourceType(int resourceIndex, int type);
    int numberResourceTypes(int resourceIndex);
    int lowestResourceType() const;
};

typedef char verify_airesmod_AIModule_size[
    sizeof(AIModule) == 0xF0 ? 1 : -1];
typedef char verify_airesmod_ResourceItem_size[
    sizeof(ResourceItem) == 0x70 ? 1 : -1];
typedef char verify_airesmod_ResourceAIModule_size[
    sizeof(ResourceAIModule) == 0x10C ? 1 : -1];

#endif
