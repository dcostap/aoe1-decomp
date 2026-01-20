#pragma once
#include "common.h"

class BuildItem {
public:
    // Virtuals (best-effort)
    virtual ~BuildItem(); // vt[0] (0x0)

    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
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
static_assert(sizeof(BuildItem) == 0xB0, "Size mismatch");
