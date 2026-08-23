// 005442E0 RGE_Game_World::scenario_make_map (World.cpp:2483-2485)
// Exact owner under the shared World.cpp scenario context.
#include "../../include/world_scenario_context.h"

void RGE_Game_World::scenario_make_map(int file)
{
    this->map->scenario_load(file, (unsigned char*)0);
}
