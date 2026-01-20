#pragma once
#include "common.h"

struct RGE_Player_Info {
    char name[9];
    char type[9];
    char tribe[9];
    short color[9];
    long player_id_hash[9];
    short player_num;
    char* scenario;
    RGE_Map_Gen_Info* map_info;
    short map_type;
    short map_width;
    short map_height;
    short ai_info;
    uchar campaign;
};
static_assert(sizeof(RGE_Player_Info) == 0x2AC, "Size mismatch");
