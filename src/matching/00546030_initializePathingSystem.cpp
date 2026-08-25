#include "../world_phase2_context.h"

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
