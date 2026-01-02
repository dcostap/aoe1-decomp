#pragma once
#include "../common.h"

class ConstructionItem : public BaseItem {
public:
    ConstructionItem* next;                  // 0x6C
    ConstructionItem* prev;                  // 0x70
    int inProgressValue;                     // 0x74
    int builtValue;                          // 0x78
    int buildAttemptsValue;                  // 0x7C

    ConstructionItem();
    ConstructionItem(float param_1, float param_2, float param_3, float param_4, float param_5, float param_6, int param_7, char* param_8);
    ConstructionItem(ConstructionItem* param_1);
    ConstructionItem(ConstructionItem* param_1);
    virtual ~ConstructionItem();
    virtual int inProgress();
    virtual int built();
    virtual int buildAttempts();
    virtual void setInProgress(int param_1);
    virtual void setBuilt(int param_1);
    virtual void incrementBuildAttempts();
    virtual void decrementBuildAttempts();
    virtual void setBuildAttempts(int param_1);
};

static_assert(sizeof(ConstructionItem) == 0x80, "ConstructionItem Size Mismatch");
static_assert(offsetof(ConstructionItem, buildAttemptsValue) == 0x7C, "ConstructionItem Offset Mismatch");

