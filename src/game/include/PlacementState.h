#pragma once
#include "common.h"
#include "BuildItem.h"
#include "XYPoint.h"

struct PlacementState {
    int buildingTypeID;
    float buildingSize;
    char buildingName[256];
    int builderID;
    int minimumDistance;
    int maximumDistance;
    int active;
    XYPoint bestPoint;
    int bestPointValue;
    int iterationX;
    int randomInfluence;
    BuildItem* buildItem;
};
static_assert(sizeof(PlacementState) == 0x130, "Size mismatch");
