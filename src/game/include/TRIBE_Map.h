#pragma once
#include "common.h"
#include "RGE_Map.h"

class TRIBE_Map : public RGE_Map {
public:
    // Virtuals (best-effort)
    virtual ~TRIBE_Map(); // vt[0] (0x0)
    virtual void data_load_random_map(int param_1); // vt[1] (0x4)
    virtual void load_random_map(char* param_1, char* param_2, char* param_3, char* param_4); // vt[2] (0x8)
    virtual uchar do_terrain_brush(long param_1, long param_2, long param_3, uchar param_4); // vt[3] (0xC)
    virtual uchar do_terrain_brush_stroke(long param_1, long param_2, long param_3, long param_4, long param_5, uchar param_6); // vt[4] (0x10)
    virtual uchar do_elevation_brush(long param_1, long param_2, long param_3, uchar param_4); // vt[5] (0x14)
    virtual uchar do_elevation_brush_stroke(long param_1, long param_2, long param_3, long param_4, long param_5, uchar param_6); // vt[6] (0x18)
    virtual uchar do_cliff_brush(long param_1, long param_2, uchar param_3, uchar param_4); // vt[7] (0x1C)
    virtual uchar do_cliff_brush_stroke(long param_1, long param_2, long param_3, long param_4, uchar param_5, uchar param_6); // vt[8] (0x20)
    virtual void map_generate(RGE_Player* param_1, RGE_Game_World* param_2, RGE_Player_Info* param_3, uchar* param_4); // vt[9] (0x24)
    virtual void map_generate2(RGE_Game_World* param_1, long param_2, long param_3, uchar param_4, long param_5); // vt[10] (0x28)
    virtual void save(int param_1); // vt[11] (0x2C)
    virtual void delete_cliff(long param_1, long param_2); // vt[12] (0x30)

    TRIBE_Game* Game;
    RGE_Player* rge_player;
    RGE_Game_World* rge_game_world;
    RGE_Map_Gen_Info* rge_map_gen_information;
    unsigned char* zones;
    long old_cliff_x;
    long old_cliff_y;
    long safe_cliff_x;
    long safe_cliff_y;
    long old_cliff_direction;
    TRIBE_Master_Cliff_Info cliff_master_table[256];
};
static_assert(sizeof(TRIBE_Map) == 0xB5F8, "Size mismatch");
