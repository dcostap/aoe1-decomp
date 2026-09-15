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
private:
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

public:
    TRIBE_Map(int infile, RGE_Sound** sound, unsigned char setup);
    TRIBE_Map(char* border_tbl, char* overlay_tbl, char* terrain_tbl, char* map_tbl,
              short TileWid, short TileHgt, short ElevHgt, RGE_Sound** sound);
    virtual ~TRIBE_Map();
    virtual void data_load_random_map(int infile);
    virtual void load_random_map(char* rmm_map_file, char* rmm_land_file, char* rmm_terr_file, char* rmm_obj_file);
    virtual unsigned char do_terrain_brush(long x, long y, long brush_size, unsigned char terrain_id);
    virtual unsigned char do_terrain_brush_stroke(long x1, long y1, long x2, long y2,
                                                   long brush_size, unsigned char terrain_id);
    virtual unsigned char do_elevation_brush_stroke(long x1, long y1, long x2, long y2,
                                                     long brush_size, unsigned char elevation_height);
    virtual unsigned char do_cliff_brush(long x, long y, unsigned char cliff_id, unsigned char delete_cliff_flag);
    virtual unsigned char do_cliff_brush_stroke(long x1, long y1, long x2, long y2,
                                                unsigned char cliff_id, unsigned char delete_cliff);
    virtual void map_generate(RGE_Player* owner, RGE_Game_World* gworld,
                              RGE_Player_Info* player_info, unsigned char* zone_terrain);
    void map_generate(RGE_Player_Info* player_info);
    virtual void save(int outfile);
    virtual void delete_cliff(long x, long y);

    void check_tile_for_forest_change(short x, short y, RGE_Game_World* world);
    void change_terrain(short map_col, short map_row, unsigned char new_terrain, RGE_Game_World* world);
    void setup_cliff_type(long r, long d, long l, long u, long id, long facet,
                          long id2, long facet2, float offset_x, float offset_y);
    RGE_Static_Object* find_cliff(long x, long y);
    TRIBE_Cliff_Info get_cliff_info(RGE_Static_Object* cliff);
    unsigned char check_cliff_valid(TRIBE_Cliff_Info info);
    RGE_Static_Object* make_new_cliff(long x, long y, TRIBE_Cliff_Info info);
    void remove_cliff_edge(long x, long y, long direction);
    long reverse_cliff_direction(long direction);
    long add_cliff_edge(long x, long y, long direction, long facing, long save_direction);
    unsigned char water(unsigned char terrain);
    void clean_borders(long x1, long y1, long x2, long y2, unsigned char terrain_id);
    unsigned char do_terrain_brush_check(long x, long y);
    void tribe_clean_elevation(long x1, long y1, long x2, long y2);
    void tribe_clean_terrain(long x1, long y1, long x2, long y2,
                             unsigned char check_terrain, unsigned char replacement_terrain);
};

typedef char tribe_cliff_info_size_check[
    (sizeof(TRIBE_Cliff_Info) == 0x10) ? 1 : -1];
typedef char tribe_master_cliff_info_size_check[
    (sizeof(TRIBE_Master_Cliff_Info) == 0x28) ? 1 : -1];
typedef char tribe_map_size_check[(sizeof(TRIBE_Map) == 0xB5F8) ? 1 : -1];

#endif
