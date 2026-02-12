#pragma once
#include "common.h"

class RGE_Map_Gen_Info;

struct RGE_Player_Info {
    char name[9][65]; // +0x0 (Size: 0x249)
    char type[9]; // +0x249 (Size: 0x9)
    char tribe[9]; // +0x252 (Size: 0x9)
    unsigned char _pad_0[0x1]; // 0x025b (Gap: 1)
    short color[9]; // +0x25C (Size: 0x12)
    unsigned char _pad_1[0x2]; // 0x026e (Gap: 2)
    long player_id_hash[9]; // +0x270 (Size: 0x24)
    short player_num; // +0x294 (Size: 0x2)
    unsigned char _pad_2[0x2]; // 0x0296 (Gap: 2)
    char* scenario; // +0x298 (Size: 0x4)
    RGE_Map_Gen_Info* map_info; // +0x29C (Size: 0x4)
    short map_type; // +0x2A0 (Size: 0x2)
    short map_width; // +0x2A2 (Size: 0x2)
    short map_height; // +0x2A4 (Size: 0x2)
    short ai_info; // +0x2A6 (Size: 0x2)
    unsigned char campaign; // +0x2A8 (Size: 0x1)
    unsigned char _pad_end[0x3]; // 0x02a9 (Gap: 3)
};
static_assert(sizeof(RGE_Player_Info) == 0x2AC, "Size mismatch");
