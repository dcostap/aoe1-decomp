// 0040AA90 ConstructionAIModule::ConstructionAIModule (aiconmod.cpp:36-43)
// Attempt log:
// - Moved the two sentinel construction calls into the member-initializer order;
//   the original has one external ConstructionItem call per sentinel.
// - Modeled the proven polymorphic AIModule/BaseItem/ConstructionItem surfaces
//   so VC5 emits the original EH-state transitions and 0xF0/0x80 layouts.
// - An explicit absolute vtable store produced exact linked bytes, but violates
//   the canonical compiler-owned-vptr policy and was removed during main-agent
//   audit. The natural virtual class surface is retained instead.
// - With /GX, the audited source was exact-size/calls but differed by 10 bytes
//   because VC5 scheduled its compiler-owned vptr before the map/result stores.
// - Fresh pass: putting map dimensions and the placement result in the natural
//   member-initializer list delayed that compiler-owned vptr to the original
//   slot; the result is an exact 242-byte match without raw vptr plumbing.
// FLAGS: config/flags/0040AA90_ConstructionAIModule.rsp (/GX for EH frame)

#include <string.h>
#include <stdio.h>

class AIModuleID {
public:
    char gap_00[0x48];
};

class BaseItem {
public:
    virtual ~BaseItem();
};

class ConstructionItem : public BaseItem {
public:
    char gap_04[0x68];
    ConstructionItem* next;  // +0x6C
    ConstructionItem* prev;  // +0x70
    char gap_74[0x0C];

    ConstructionItem();
    virtual ~ConstructionItem();
};

class AIModule {
public:
    virtual ~AIModule();

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
    virtual ~ConstructionAIModule();

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

ConstructionAIModule::ConstructionAIModule(void* param_1, int param_2)
    : AIModule((char*)0x57F380, 0x3EA, param_2, param_1),
      numberConstructionLotsValue(0),
      constructionLots(),
      numberRandomConstructionLotsValue(0),
      randomConstructionLots(),
      xReferencePointValue(-1.0f),
      yReferencePointValue(-1.0f),
      zReferencePointValue(-1.0f),
      mapXSizeValue(-1),
      mapYSizeValue(-1),
      lastPlacementReturnCodeValue(0)
{
    this->constructionLots.next = &this->constructionLots;
    this->constructionLots.prev = &this->constructionLots;
    this->randomConstructionLots.next = &this->randomConstructionLots;
    this->randomConstructionLots.prev = &this->randomConstructionLots;

    strcpy(this->constructionPlanNameValue, (const char*)0x592A40);
}
