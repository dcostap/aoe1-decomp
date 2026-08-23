#include "../../include/world_scenario_context.h"

void RGE_Game_World::color_table_init(int fd) {
    rge_read(fd, &color_table_num, 2);

    if (color_table_num > 0) {
        color_tables = (RGE_Color_Table**)calloc(color_table_num, 4);
        for (int i = 0; i < color_table_num; i++) {
            color_tables[i] = new RGE_Color_Table(fd);
        }
    }
}
