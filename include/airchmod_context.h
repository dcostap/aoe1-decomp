#ifndef AOE1_AIRCHMOD_CONTEXT_H
#define AOE1_AIRCHMOD_CONTEXT_H

class MainDecisionAIModule;
class BuildItem;

class AIModule {
public:
    AIModule(char* name, int line, int arg, void* ptr);
    virtual ~AIModule();
    void __cdecl logCommonHistory(char*, ...);

    char gap[0xEC];
};

class ResourceItem {
public:
    virtual ~ResourceItem();
    ResourceItem(int count, int* values);
    ResourceItem(ResourceItem const& other);

    ResourceItem* next;
    ResourceItem* prev;
    int valueValue[8];
    int sortedValue[8];
    int sortedIndexValue[8];
    int numberValue;

    int value(int index) const;
};

class TechnologyItem {
public:
    virtual ~TechnologyItem();
    TechnologyItem();
    TechnologyItem(int id, char* name, ResourceItem cost);

    TechnologyItem* next;
    TechnologyItem* prev;
    int idValue;
    char nameValue[0x40];
    ResourceItem* resourceCostValue;

    int id() const;
    char* name();
    ResourceItem* resourceCost();
};

class ResearchAIModule : public AIModule {
public:
    ResearchAIModule(void* ptr, int arg);
    ResearchAIModule(int file, int arg);
    virtual ~ResearchAIModule();

    MainDecisionAIModule* md;
    TechnologyItem techTree;
    int techTreeLengthValue;
    char techTreeNameValue[260];

    void setMainDecisionAI(MainDecisionAIModule* value);
    virtual int save(int file);
    virtual int buildable(BuildItem* item);
    virtual void research(BuildItem* item);
    int loadTechnologyTree(char* filename);
    ResourceItem* resourceCost(int id);
    int numberTechnologyItems() const;
    char* technologyTreeName();

protected:
    void removeOldTechTree();
    TechnologyItem* item(int id);
};

void rge_write(int file, void* data, int size);

#endif
