#pragma once
#include "common.h"

class BuildItem {
public:
    BuildItem();
    BuildItem(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, char* param_7, float param_8, float param_9, float param_10,
              int param_11, int param_12, int param_13, int param_14);
    BuildItem(BuildItem* param_1);
    BuildItem(const BuildItem& param_1);

    // Virtuals (best-effort)
    virtual ~BuildItem(); // vt[0] (0x0)

    int buildCategory() const;
    int number() const;
    int priority() const;
    int inProgress() const;
    int built() const;
    int buildAttempts() const;
    int buildFrom() const;
    int terrainSet() const;
    int terrainAdjacency(int param_1) const;
    int placeOnElevation() const;
    void setInProgress(int param_1);
    void setBuilt(int param_1);
    void setBuildAttempts(int param_1);
    void incrementBuildAttempts();
    void decrementBuildAttempts();
    int numberBuilds();
    void incrementNumberBuilds();
    void setNumberBuilds(int param_1);
    int buildCap();
    void setBuildCap(int param_1);
    int skipCycles();
    void incrementSkipCycles();
    void setSkipCycles(int param_1);
    uchar permanentSkip();
    void setPermanentSkip(uchar param_1);

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
    int padding;
    BuildItem* next;
    BuildItem* prev;
    int buildCategoryValue;
    int numberValue;
    int priorityValue;
    int progressValue;
    int builtValue;
    int buildAttemptsValue;
    int buildFromValue;
    int terrainSetValue;
    int terrainAdjacencyValue[2];
    int placeOnElevationValue;
    int numberBuildsValue;
    int buildCapValue;
    int skipCyclesValue;
    uchar permanentSkipValue;
};

int operator==(const BuildItem& param_1, const BuildItem& param_2);
int operator!=(const BuildItem& param_1, const BuildItem& param_2);
int operator<(const BuildItem& param_1, const BuildItem& param_2);
int operator>(const BuildItem& param_1, const BuildItem& param_2);

static_assert(sizeof(BuildItem) == 0xB0, "Size mismatch");
