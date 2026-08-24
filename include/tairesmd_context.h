#ifndef AOE1_TAIRESMD_CONTEXT_H
#define AOE1_TAIRESMD_CONTEXT_H

// Authentic shared declaration surface for C:\\msdev\\work\\age1_x1\\tairesmd.cpp.
// The module contains two TribeResourceAIModule constructors and its virtual
// destructor before the remaining helpers.  Keep the owner bodies separate.

struct _iobuf;
class AIModuleMessage;
class AIModuleID;
class TribeMainDecisionAIModule;

class ResourceTable {
public:
    char gap_00[0x50];
    float* values;
};

class AIModule {
public:
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

    // The first constructor owner proves the void* spelling.  The second
    // owner uses the period string-literal spelling from its source body.
    AIModule(void*, int, int, void*);
    AIModule(const char*, int, int, void*);

    char gap_F0[0xEC];
};

typedef char verify_tairesmd_AIModule_size[
    sizeof(AIModule) == 0xF0 ? 1 : -1];

class ResourceItem {
public:
    virtual ~ResourceItem();
    char gap_04[0x6C];

    int number();
    int value(int);
};

typedef char verify_tairesmd_ResourceItem_size[
    sizeof(ResourceItem) == 0x70 ? 1 : -1];

class TribeMainDecisionAIModule {
public:
    char gap_00[0xF0];
    ResourceTable* player;
};

class TribeResourceAIModule : public AIModule {
public:
    virtual ~TribeResourceAIModule();
    virtual int save(int);

    TribeResourceAIModule(void*, int, int, int, int, int);
    TribeResourceAIModule(int, int);

    int numberResources();
    int resource(int) const;
    char* resourceName(int);
    int resourcesAvailable(ResourceItem*);
    void setMainDecisionAI(TribeMainDecisionAIModule*);
    int unavailableResource(ResourceItem*);

    TribeMainDecisionAIModule* md;
    int numberResourcesValue;
};

typedef char verify_tairesmd_TribeResourceAIModule_size[
    sizeof(TribeResourceAIModule) == 0xF8 ? 1 : -1];

#endif
