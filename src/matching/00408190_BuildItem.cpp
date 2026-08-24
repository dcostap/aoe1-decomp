#include "../../include/aiblditm_context.h"

BuildItem::BuildItem()
    : next(0), prev(0), numberValue(0), priorityValue(0),
      progressValue(0), builtValue(0), buildAttemptsValue(0),
      terrainSetValue(-1),
      placeOnElevationValue(0), numberBuildsValue(0), skipCyclesValue(0),
      permanentSkipValue(0), buildCategoryValue(-1),
      buildFromValue(-1),
      buildCapValue(-1) {
    terrainAdjacencyValue[0] = -1;
    terrainAdjacencyValue[1] = -1;
}
