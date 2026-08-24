#include "../../include/aiblditm_context.h"

BuildItem::BuildItem(int category, int typeID, int uniqueID, int number,
                     int priority, int buildFrom, char* name, float xSize,
                     float ySize, float zSize, int terrainSet, int adjacency0,
                     int adjacency1, int elevation)
    : BaseItem(typeID, -1, uniqueID, name, -1.0f, -1.0f, -1.0f,
               xSize, ySize, zSize),
      next(0), prev(0), buildCategoryValue(category), numberValue(number),
      priorityValue(priority), progressValue(0), builtValue(0),
      buildAttemptsValue(0), buildFromValue(buildFrom),
      terrainSetValue(terrainSet),
      placeOnElevationValue(elevation), numberBuildsValue(0),
      buildCapValue(-1), skipCyclesValue(0), permanentSkipValue(0) {
    terrainAdjacencyValue[0] = adjacency0;
    terrainAdjacencyValue[1] = adjacency1;
}
