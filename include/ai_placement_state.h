#ifndef AOE1_AI_PLACEMENT_STATE_H
#define AOE1_AI_PLACEMENT_STATE_H

#include "infmap.h"

class BuildItem;

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

typedef char ai_placement_state_size_check[
    (sizeof(PlacementState) == 0x130) ? 1 : -1];

#endif
