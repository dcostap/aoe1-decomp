#pragma once
#include "common.h"

class TRIBE_Map : public RGE_Map {
public:
    TRIBE_Game* Game;                        // 0x8DD0
    RGE_Player* rge_player;                  // 0x8DD4
    RGE_Game_World* rge_game_world;          // 0x8DD8
    RGE_Map_Gen_Info* rge_map_gen_information; // 0x8DDC
    uchar* zones;                            // 0x8DE0
    long old_cliff_x;                        // 0x8DE4
    long old_cliff_y;                        // 0x8DE8
    long safe_cliff_x;                       // 0x8DEC
    long safe_cliff_y;                       // 0x8DF0
    long old_cliff_direction;                // 0x8DF4
    TRIBE_Master_Cliff_Info cliff_master_table[256]; // 0x8DF8

    virtual void data_load_random_map(int param_1);         // vt0[1]+0x4=0x50F800
    virtual void load_random_map(char* param_1, char* param_2, char* param_3, char* param_4); // vt0[2]+0x8=0x50F860
    virtual uchar do_terrain_brush(long param_1, long param_2, long param_3, uchar param_4); // vt0[3]+0xC=0x50FC40
    virtual uchar do_terrain_brush_stroke(long param_1, long param_2, long param_3, long param_4, long param_5, uchar param_6); // vt0[4]+0x10=0x50FD40
    virtual uchar do_elevation_brush_stroke(long param_1, long param_2, long param_3, long param_4, long param_5, uchar param_6); // vt0[6]+0x18=0x50FDD0
    virtual uchar do_cliff_brush(long param_1, long param_2, uchar param_3, uchar param_4); // vt0[7]+0x1C=0x510A50
    virtual uchar do_cliff_brush_stroke(long param_1, long param_2, long param_3, long param_4, uchar param_5, uchar param_6); // vt0[8]+0x20=0x510C10
    virtual void map_generate(RGE_Player* param_1, RGE_Game_World* param_2, RGE_Player_Info* param_3, uchar* param_4); // vt0[9]+0x24=0x50F7C0
    virtual void save(int param_1);                         // vt0[11]+0x2C=0x50F7B0
    virtual void delete_cliff(long param_1, long param_2);  // vt0[12]+0x30=0x510960
    TRIBE_Map(int param_1, RGE_Sound** param_2, uchar param_3);
    TRIBE_Map(char* param_1, char* param_2, char* param_3, char* param_4, short param_5, short param_6, short param_7, RGE_Sound** param_8);
    ~TRIBE_Map();
    void map_generate(RGE_Player_Info* param_1);
    void check_tile_for_forest_change(short param_1, short param_2, RGE_Game_World* param_3);
    void change_terrain(short param_1, short param_2, uchar param_3, RGE_Game_World* param_4);
    void setup_cliff_type(long param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, float param_9, float param_10);
    RGE_Static_Object* find_cliff(long param_1, long param_2);
    TRIBE_Cliff_Info* get_cliff_info(RGE_Static_Object* param_1);
    uchar check_cliff_valid(TRIBE_Cliff_Info param_1);
    RGE_Static_Object* make_new_cliff(long param_1, long param_2, TRIBE_Cliff_Info param_3);
    void remove_cliff_edge(long param_1, long param_2, long param_3);
    long reverse_cliff_direction(long param_1);
    long add_cliff_edge(long param_1, long param_2, long param_3, long param_4, long param_5);
    uchar water(uchar param_1);
    void clean_borders(long param_1, long param_2, long param_3, long param_4, uchar param_5);
    uchar do_terrain_brush_check(long param_1, long param_2);
    void tribe_clean_elevation(long param_1, long param_2, long param_3, long param_4);
    void tribe_clean_terrain(long param_1, long param_2, long param_3, long param_4, uchar param_5, uchar param_6);
};

static_assert(sizeof(TRIBE_Map) == 0xB5F8, "TRIBE_Map Size Mismatch");

