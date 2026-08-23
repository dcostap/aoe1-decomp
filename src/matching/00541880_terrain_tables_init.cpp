#include "../../include/world_scenario_context.h"

void RGE_Game_World::terrain_tables_init(int fd) {
    rge_read(fd, &terrain_num, 2);
    rge_read(fd, &terrain_size, 2);

    if (terrain_num > 0 && terrain_size > 0) {
        terrains = (float**)calloc(terrain_num, 4);
        rge_read(fd, terrains, terrain_num * 4);

        for (int i = 0; i < terrain_num; i++) {
            if (terrains[i] != 0) {
                terrains[i] = (float*)calloc(terrain_size, 4);
                rge_read(fd, terrains[i], terrain_size * 4);
            }
        }
    }
}
