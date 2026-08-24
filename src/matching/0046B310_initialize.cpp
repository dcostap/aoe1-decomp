#ifndef PATHSYS_TU_CONTEXT
class RGE_Map {
public:
    void* vtable_ptr;
    char gap_04[0x4];
    int width;
    int height;
};

class RGE_Game_World;

class PathingSystem {
public:
    void* vtable_ptr;
    int xSizeValue;
    int ySizeValue;
    char gap_0C[0x11DC30];
    RGE_Map* mapValue;
    RGE_Game_World* worldValue;
    char gap_11DC44[0x94];
    unsigned char CurrentFacetMask;

    int initialize(int xSize, int ySize, RGE_Map* map, RGE_Game_World* world);
};
#endif

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
