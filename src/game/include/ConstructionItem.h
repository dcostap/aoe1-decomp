#pragma once
#include "common.h"

class ConstructionItem {
public:
    ConstructionItem();
    ConstructionItem(float param_1, float param_2, float param_3, float param_4, float param_5, float param_6, int param_7, char* param_8);
    ConstructionItem(ConstructionItem* param_1);
    ConstructionItem(const ConstructionItem& param_1);

    // Virtuals (best-effort)
    virtual ~ConstructionItem(); // vt[0] (0x0)

    int inProgress() const;
    int built() const;
    int buildAttempts() const;
    void setInProgress(int param_1);
    void setBuilt(int param_1);
    void incrementBuildAttempts();
    void decrementBuildAttempts();
    void setBuildAttempts(int param_1);

    int padding0;
    int padding1;
    int padding2;
    int padding3;
    int padding4;
    int padding5;
    int padding6;
    int padding7;
    int padding8;
    int padding9;
    int padding10;
    int padding11;
    int padding12;
    int padding13;
    int padding14;
    int padding15;
    int padding16;
    int padding17;
    int padding18;
    int padding19;
    int padding20;
    int padding21;
    int padding22;
    int padding23;
    int padding24;
    int padding25;
    ConstructionItem* next;
    ConstructionItem* prev;
    int inProgressValue;
    int builtValue;
    int buildAttemptsValue;
};

int operator==(const ConstructionItem& param_1, const ConstructionItem& param_2);
int operator!=(const ConstructionItem& param_1, const ConstructionItem& param_2);
int operator<(const ConstructionItem& param_1, const ConstructionItem& param_2);
int operator>(const ConstructionItem& param_1, const ConstructionItem& param_2);

static_assert(sizeof(ConstructionItem) == 0x80, "Size mismatch");
