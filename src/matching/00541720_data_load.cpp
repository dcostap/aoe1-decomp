#include <stdio.h>
#include "../../include/world_scenario_context.h"

unsigned char RGE_Game_World::data_load(char* param_1, char* param_2) {
    FILE* f = fopen(param_2, "r");
    if (f != 0) {
        this->data_load_world(f);
        fclose(f);
        this->base_save(param_1);
        return 1;
    }
    return 0;
}
