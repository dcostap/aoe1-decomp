#pragma once
#include "../common.h"

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

    TRIBE_Map(int param_1, RGE_Sound** param_2, uchar param_3);
    TRIBE_Map(char* param_1, char* param_2, char* param_3, char* param_4, short param_5, short param_6, short param_7, RGE_Sound** param_8);
    virtual ~TRIBE_Map();
    virtual void save(int param_1);
    virtual void map_generate(RGE_Player* param_1, RGE_Game_World* param_2, RGE_Player_Info* param_3, uchar* param_4);
    virtual void map_generate(RGE_Player_Info* param_1);
    virtual void data_load_random_map(int param_1);
    virtual void load_random_map(char* param_1, char* param_2, char* param_3, char* param_4);
    virtual void check_tile_for_forest_change(short param_1, short param_2, RGE_Game_World* param_3);
    virtual void change_terrain(short param_1, short param_2, uchar param_3, RGE_Game_World* param_4);
    virtual uchar do_terrain_brush(long param_1, long param_2, long param_3, uchar param_4);
    virtual uchar do_terrain_brush_stroke(long param_1, long param_2, long param_3, long param_4, long param_5, uchar param_6);
    virtual uchar do_elevation_brush_stroke(long param_1, long param_2, long param_3, long param_4, long param_5, uchar param_6);
    virtual void setup_cliff_type(long param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, float param_9, float param_10);
    virtual RGE_Static_Object* find_cliff(long param_1, long param_2);
    virtual TRIBE_Cliff_Info* get_cliff_info(TRIBE_Cliff_Info* __return_storage_ptr__, RGE_Static_Object* param_1);
    virtual uchar check_cliff_valid(TRIBE_Cliff_Info param_1);
    virtual RGE_Static_Object* make_new_cliff(long param_1, long param_2, TRIBE_Cliff_Info param_3);
    virtual void remove_cliff_edge(long param_1, long param_2, long param_3);
    virtual long reverse_cliff_direction(long param_1);
    virtual long add_cliff_edge(long param_1, long param_2, long param_3, long param_4, long param_5);
    virtual void delete_cliff(long param_1, long param_2);
    virtual uchar do_cliff_brush(long param_1, long param_2, uchar param_3, uchar param_4);
    virtual uchar do_cliff_brush_stroke(long param_1, long param_2, long param_3, long param_4, uchar param_5, uchar param_6);
    virtual uchar water(uchar param_1);
    virtual void clean_borders(long param_1, long param_2, long param_3, long param_4, uchar param_5);
    virtual uchar do_terrain_brush_check(long param_1, long param_2);
    virtual void tribe_clean_elevation(long param_1, long param_2, long param_3, long param_4);
    virtual void tribe_clean_terrain(long param_1, long param_2, long param_3, long param_4, uchar param_5, uchar param_6);
};

static_assert(sizeof(TRIBE_Map) == 0xB5F8, "TRIBE_Map Size Mismatch");
static_assert(offsetof(TRIBE_Map, cliff_master_table) == 0x8DF8, "TRIBE_Map Offset Mismatch");

