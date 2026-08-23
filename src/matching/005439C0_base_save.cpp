#include "../../include/world_scenario_context.h"

void RGE_Game_World::base_save(char* param_1) {
    int fileHandle = rge_open(param_1, 0x8309, 0x180);
    if (fileHandle != -1) {
        this->base_save(fileHandle);
        rge_close(fileHandle);
    }
}
