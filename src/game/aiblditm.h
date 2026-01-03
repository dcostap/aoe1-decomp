#pragma once
#include "../common.h"
#include "aibitm.h"

// ----------------------------------------------------------------
// PlacementState
// Sizeñ: 0x130
struct PlacementState {
    int buildingTypeID; // 0x0
    float buildingSize; // 0x4
    char buildingName[256]; // 0x8
    int builderID; // 0x108
    int minimumDistance; // 0x10C
    int maximumDistance; // 0x110
    int active; // 0x114
    XYPoint bestPoint; // 0x118
    int bestPointValue; // 0x120
    int iterationX; // 0x124
    int randomInfluence; // 0x128
    BuildItem * buildItem; // 0x12C
};

class BuildItem : public BaseItem {
public:
    BuildItem* next;                         // 0x6C
    BuildItem* prev;                         // 0x70
    int buildCategoryValue;                  // 0x74
    int numberValue;                         // 0x78
    int priorityValue;                       // 0x7C
    int progressValue;                       // 0x80
    int builtValue;                          // 0x84
    int buildAttemptsValue;                  // 0x88
    int buildFromValue;                      // 0x8C
    int terrainSetValue;                     // 0x90
    int terrainAdjacencyValue[2];            // 0x94
    int placeOnElevationValue;               // 0x9C
    int numberBuildsValue;                   // 0xA0
    int buildCapValue;                       // 0xA4
    int skipCyclesValue;                     // 0xA8
    uchar permanentSkipValue;                // 0xAC

    BuildItem();
    BuildItem(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, char* param_7, float param_8, float param_9, float param_10, int param_11, int param_12, int param_13, int param_14);
    BuildItem(BuildItem* param_1);
    BuildItem(BuildItem* param_1);
    virtual ~BuildItem();
    virtual int buildCategory();
    virtual int number();
    virtual int priority();
    virtual int inProgress();
    virtual int built();
    virtual int buildAttempts();
    virtual int buildFrom();
    virtual int terrainSet();
    virtual int terrainAdjacency(int param_1);
    virtual int placeOnElevation();
    virtual void setInProgress(int param_1);
    virtual void setBuilt(int param_1);
    virtual void setBuildAttempts(int param_1);
    virtual void incrementBuildAttempts();
    virtual void decrementBuildAttempts();
    virtual int numberBuilds();
    virtual void incrementNumberBuilds();
    virtual void setNumberBuilds(int param_1);
    virtual int buildCap();
    virtual void setBuildCap(int param_1);
    virtual int skipCycles();
    virtual void incrementSkipCycles();
    virtual void setSkipCycles(int param_1);
    virtual uchar permanentSkip();
    virtual void setPermanentSkip(uchar param_1);
};

static_assert(sizeof(BuildItem) == 0xB0, "BuildItem Size Mismatch");
static_assert(offsetof(BuildItem, permanentSkipValue) == 0xAC, "BuildItem Offset Mismatch");

