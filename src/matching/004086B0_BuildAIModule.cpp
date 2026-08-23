// VA: 004086B0 BuildAIModule::BuildAIModule
// PDB source: aibldmod.cpp
// Attempt log:
// - novtable with virtual for EH, manual vtable, direct member access for list ptrs.

#include "../../include/aibldmod_context.h"

#ifndef AIBLDMOD_SHARED_CONTEXT
extern "C" char* strcpy(char* dst, const char* src);

class BaseItem {
public:
    char gap_00[0x68];
    BaseItem();
    virtual ~BaseItem();
};

class BuildItem : public BaseItem {
public:
    void* next;                    // +0x6C
    void* prev;                    // +0x70
    int priorityValue;             // +0x74
    int numberValue;               // +0x78
    int progressValue;             // +0x7C
    int builtValue;                // +0x80
    int buildAttemptsValue;        // +0x84
    int placeOnElevationValue;     // +0x88
    int terrainSetValue;           // +0x8C
    int buildCapValue;             // +0x90
    int buildFromValue;            // +0x94
    int buildCategoryValue;        // +0x98
    int skipCyclesValue;           // +0x9C
    int numberBuildsValue;         // +0xA0
    int numberValue2;              // +0xA4
    int field_A8;                  // +0xA8
    char permanentSkipValue;       // +0xAC

    BuildItem();
    virtual ~BuildItem();
};

struct TypesToIgnore {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

class AIModule {
public:
    virtual ~AIModule();
    AIModule(const char* name, int id, int param1, void* param2);

    char gap_04[0xEC];
    BuildItem buildList;             // +0xF0 (sizeof 0xB0)
    int buildListLengthValue;        // +0x1A0
    char buildListNameValue[0x101];  // +0x1A4
    char lastBuildItemRequestedValue[0x101];  // +0x2A5
    char currentBuildItemRequestedValue[0x101];  // +0x3A6
    char nextBuildItemRequestedValue[0x101];  // +0x4A7
    int numberItemsIntoBuildListValue;  // +0x5A8
    TypesToIgnore typesToIgnore;  // +0x5AC
};

class __declspec(novtable) BuildAIModule : public AIModule {
public:
    BuildAIModule(void* param_1, int param_2);
    virtual ~BuildAIModule();
};
#endif

BuildAIModule::BuildAIModule(void* param_1, int param_2)
    : AIModule("Build AI", 0x3E9, param_2, param_1)
{
    this->buildList.BuildItem::BuildItem();
    this->buildListLengthValue = 0;
    this->numberItemsIntoBuildListValue = 0;
    this->typesToIgnore.value = 0;
    this->typesToIgnore.numberValue = 0;
    this->typesToIgnore.desiredNumberValue = 0;
    this->typesToIgnore.maximumSizeValue = 0;
    *(void**)this = (void*)0x0056E738;
    this->buildList.next = &this->buildList;
    this->buildList.prev = &this->buildList;
    strcpy(this->buildListNameValue, "");
    strcpy(this->lastBuildItemRequestedValue, "None");
    strcpy(this->currentBuildItemRequestedValue, "None");
    strcpy(this->nextBuildItemRequestedValue, "None");
}
