#ifndef AOE1_TMAP_H
#define AOE1_TMAP_H

#include "map.h"

class RGE_Game_World;
class RGE_Player;
class RGE_Sound;
class RGE_Static_Object;
class TRIBE_Game;
class RGE_Map_Gen_Info;
struct RGE_Player_Info;

struct TRIBE_Cliff_Info {
    long info[4];
};

struct TRIBE_Master_Cliff_Info {
    long id;
    long facet;
    long id2;
    long facet2;
    TRIBE_Cliff_Info info;
    float offset_x;
    float offset_y;
};

class TRIBE_Map : public RGE_Map {
public:
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

    TRIBE_Map(int, RGE_Sound**, unsigned char);
    TRIBE_Map(char*, char*, char*, char*, short, short, short, RGE_Sound**);
    virtual ~TRIBE_Map();
    virtual void data_load_random_map(int);
    virtual void load_random_map(char*, char*, char*, char*);
    virtual unsigned char do_terrain_brush(long, long, long, unsigned char);
    virtual unsigned char do_terrain_brush_stroke(long, long, long, long,
                                                   long, unsigned char);
    virtual unsigned char do_elevation_brush_stroke(long, long, long, long,
                                                     long, unsigned char);
    virtual unsigned char do_cliff_brush(long, long, unsigned char,
                                         unsigned char);
    virtual unsigned char do_cliff_brush_stroke(long, long, long, long,
                                                unsigned char, unsigned char);
    virtual void map_generate(RGE_Player*, RGE_Game_World*, RGE_Player_Info*,
                              unsigned char*);
    void map_generate(RGE_Player_Info*);
    virtual void save(int);
    virtual void delete_cliff(long, long);

    void check_tile_for_forest_change(short, short, RGE_Game_World*);
    void change_terrain(short, short, unsigned char, RGE_Game_World*);
    void setup_cliff_type(long, long, long, long, long, long, long, long,
                          float, float);
    RGE_Static_Object* find_cliff(long, long);
    TRIBE_Cliff_Info get_cliff_info(RGE_Static_Object*);
    unsigned char check_cliff_valid(TRIBE_Cliff_Info);
    RGE_Static_Object* make_new_cliff(long, long, TRIBE_Cliff_Info);
    void remove_cliff_edge(long, long, long);
    long reverse_cliff_direction(long);
    long add_cliff_edge(long, long, long, long, long);
    unsigned char water(unsigned char);
    void clean_borders(long, long, long, long, unsigned char);
    unsigned char do_terrain_brush_check(long, long);
    void tribe_clean_elevation(long, long, long, long);
    void tribe_clean_terrain(long, long, long, long, unsigned char,
                             unsigned char);
};

typedef char tribe_cliff_info_size_check[
    (sizeof(TRIBE_Cliff_Info) == 0x10) ? 1 : -1];
typedef char tribe_master_cliff_info_size_check[
    (sizeof(TRIBE_Master_Cliff_Info) == 0x28) ? 1 : -1];
typedef char tribe_map_size_check[(sizeof(TRIBE_Map) == 0xB5F8) ? 1 : -1];

#endif
