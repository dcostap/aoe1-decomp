#include "../../include/rmm_terr_context.h"

RGE_RMM_Terrain_Generator::RGE_RMM_Terrain_Generator(RGE_Map* map, RGE_Random_Map_Module* parent, RGE_Terrain_Info* info)
    : RGE_Random_Map_Module(map, parent, 1)
{
    *((RGE_Terrain_Info*)((char*)this + 0x30)) = *info;
    this->schedule = 2.0f;
}
