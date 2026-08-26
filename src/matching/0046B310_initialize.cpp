#include "../../include/pathsys_context.h"

int PathingSystem::initialize(int xSize, int ySize, RGE_Map* map, RGE_Game_World* world) {
    mapValue = map;
    worldValue = world;
    if (map != 0) {
        xSizeValue = map->width;
        ySizeValue = map->height;
    } else {
        xSizeValue = xSize;
        ySizeValue = ySize;
    }
    CurrentFacetMask = 0xF0;
    return 1;
}
