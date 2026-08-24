#ifndef WORLD_TU
class RGE_Map {
public:
    char gap_00[0x8];
    int map_width;
    int map_height;
};

class RGE_Game_World;

class PathingSystem {
public:
    int initialize(int map_width, int map_height, RGE_Map* map, RGE_Game_World* world);
};

extern PathingSystem pathSystem;
extern PathingSystem aiPathSystem;

class RGE_Game_World {
public:
    char gap_00[0x28];
    RGE_Map* map;

    int initializePathingSystem(void);
};
#endif

int RGE_Game_World::initializePathingSystem(void) {
    RGE_Map* pRVar1 = this->map;
    if (pRVar1 == 0) {
        return 0;
    }

    pathSystem.initialize(pRVar1->map_width, pRVar1->map_height, pRVar1, this);
    pRVar1 = this->map;
    aiPathSystem.initialize(pRVar1->map_width, pRVar1->map_height, pRVar1, this);
    return 1;
}
