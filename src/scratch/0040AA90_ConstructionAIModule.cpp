// 0040AA90 ConstructionAIModule::ConstructionAIModule (aiconmod.cpp:36-43)

#include <string.h>
#include <stdio.h>

class AIModuleID {
public:
    char gap_00[0x48];
};

class ConstructionItem {
public:
    char gap_00[0x6C];
    ConstructionItem* next;  // +0x6C
    ConstructionItem* prev;  // +0x70
    char gap_74[0x0C];

    ConstructionItem();
    ~ConstructionItem();
};

class AIModule {
public:
    void* vtable_ptr;
    AIModuleID idValue;
    int playerNumberValue;
    char playerNameValue[64];
    int runningValue;
    int pausedValue;
    int logHistoryValue;
    int logCommonHistoryValue;
    void* historyLogFile;
    char historyLogFilename[64];
    int intelligenceLevelValue;
    int priorityValue;
    int processFrameValue;

    AIModule(char* name, int id, int param_2, void* param_1);
};

class ConstructionAIModule : public AIModule {
public:
    int numberConstructionLotsValue;                    // +0xF0
    ConstructionItem constructionLots;                  // +0xF4
    int numberRandomConstructionLotsValue;               // +0x174
    ConstructionItem randomConstructionLots;              // +0x178
    char constructionPlanNameValue[257];                 // +0x1F8
    char _pad_2F9[3];                                    // +0x2F9
    float xReferencePointValue;                          // +0x2FC
    float yReferencePointValue;                          // +0x300
    float zReferencePointValue;                          // +0x304
    int mapXSizeValue;                                   // +0x308
    int mapYSizeValue;                                   // +0x30C
    int lastPlacementReturnCodeValue;                    // +0x310

    ConstructionAIModule(void* param_1, int param_2);
};

extern void* _vftable_ConstructionAIModule;

ConstructionAIModule::ConstructionAIModule(void* param_1, int param_2)
    : AIModule("ConAI", 0x3EA, param_2, param_1)
{
    int initial_zero = 0;
    this->numberConstructionLotsValue = initial_zero;
    this->constructionLots.ConstructionItem::ConstructionItem();

    int initial_zero2 = 0;
    this->numberRandomConstructionLotsValue = initial_zero2;
    this->randomConstructionLots.ConstructionItem::ConstructionItem();

    this->xReferencePointValue = -1.0f;
    this->yReferencePointValue = -1.0f;
    this->zReferencePointValue = -1.0f;

    this->randomConstructionLots.next = &this->randomConstructionLots;
    this->randomConstructionLots.prev = &this->randomConstructionLots;

    this->mapXSizeValue = -1;
    this->mapYSizeValue = -1;
    this->lastPlacementReturnCodeValue = 0;

    this->vtable_ptr = &_vftable_ConstructionAIModule;
    this->constructionLots.next = &this->constructionLots;
    this->constructionLots.prev = &this->constructionLots;

    strcpy(this->constructionPlanNameValue, "");
}

ConstructionItem::ConstructionItem() {}
ConstructionItem::~ConstructionItem() {}
AIModule::AIModule(char* name, int id, int param_2, void* param_1) {}
