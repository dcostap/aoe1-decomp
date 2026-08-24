#include "../../include/aiblditm_context.h"

BuildItem::BuildItem(const BuildItem& source)
    : BaseItem(static_cast<const BaseItem&>(source)), next(0), prev(0),
      buildCategoryValue(source.buildCategoryValue),
      numberValue(source.numberValue), priorityValue(source.priorityValue),
      // ORIGINAL BUG: shipped code copies progress into built.
      progressValue(source.progressValue), builtValue(source.progressValue),
      buildAttemptsValue(source.buildAttemptsValue),
      buildFromValue(source.buildFromValue),
      terrainSetValue(source.terrainSetValue),
      placeOnElevationValue(source.placeOnElevationValue),
      numberBuildsValue(0), buildCapValue(-1), skipCyclesValue(0),
      permanentSkipValue(0) {
    terrainAdjacencyValue[0] = source.terrainAdjacencyValue[0];
    terrainAdjacencyValue[1] = source.terrainAdjacencyValue[1];
}
