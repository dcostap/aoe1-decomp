// VA: 0045A500 RGE_Map::update (462B)
// PDB source: map.cpp, lines 3039-3125
// Attempt log:
// - Replaced the placeholder with a typed RGE_Map/terrain/border reconstruction.
//   The binary proves terrain records at +0x8C (stride 0x198), border records at
//   +0x338C (stride 0x400), short count fields at +0x8D90/+0x8D92, and the
//   natural animation update formula for both arrays.
// - Keeping only the clamped draw frame lost the oracle's duplicated elapsed
//   x87 value and left the raw frame count unavailable for animate_last.
// - Naming the elapsed interval remainder and retaining the raw frame count
//   restored the original fdiv/__ftol/FPU remainder topology and exact bytes.

extern unsigned int DAT_0062e65c;
extern float DAT_005706e8;

class TShape;
class RGE_Sound;
class RGE_Tile;
class RGE_Player;
class RGE_Game_World;
class RGE_RMM_Database_Controller;
class RGE_Zone_Map_List;
class RGE_Unified_Visible_Map;
class Visible_Unit_Manager;

struct RGE_TOB_Picts {
    short count;
    short animations;
    short shape_index;
};

class RGE_Tile_Set {
public:
    unsigned char loaded;
    unsigned char random;
    char name[13];
    char pict_name[13];
    long resource_id;
    TShape* shape;
    RGE_Sound* sound;
    unsigned char map_hi_color;
    unsigned char map_med_color;
    unsigned char map_low_color;
    unsigned char map_lt_cliff_color;
    unsigned char map_rt_cliff_color;
    unsigned char passable_terrain;
    unsigned char impassable_terrain;
    unsigned char is_animated;
    short animation_frames;
    short pause_frames;
    float interval;
    float pause_between_loops;
    short frame;
    short draw_frame;
    float animate_last;
    unsigned char frame_changed;
    unsigned char drawn;
    RGE_TOB_Picts tiles[19];
    short terrain_to_draw;
    short rows;
    short cols;
    short borders[32];
    short obj_types[30];
    short obj_density[30];
    unsigned char obj_placement_flag[30];
    short num_obj_type;
    unsigned char pad_end[2];
};

class RGE_Border_Set {
public:
    unsigned char loaded;
    unsigned char random;
    char name[13];
    char pict_name[13];
    long resource_id;
    TShape* shape;
    RGE_Sound* sound;
    unsigned char map_hi_color;
    unsigned char map_med_color;
    unsigned char map_low_color;
    unsigned char is_animated;
    short animation_frames;
    short pause_frames;
    float interval;
    float pause_between_loops;
    short frame;
    short draw_frame;
    float animate_last;
    unsigned char frame_changed;
    unsigned char drawn;
    RGE_TOB_Picts borders[19][12];
    unsigned char draw_tile;
    unsigned char pad_0;
    short underlay_terrain;
    short border_style;
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    virtual void data_load_random_map(int file);
    virtual void load_random_map(char*, char*, char*, char*);
    virtual unsigned char do_terrain_brush(long, long, long, unsigned char);
    virtual unsigned char do_terrain_brush_stroke(long, long, long, long, long,
                                                   unsigned char);
    virtual unsigned char do_elevation_brush(long, long, long, unsigned char);
    virtual unsigned char do_elevation_brush_stroke(long, long, long, long,
                                                     long, unsigned char);
    virtual unsigned char do_cliff_brush(long, long, unsigned char, unsigned char);
    virtual unsigned char do_cliff_brush_stroke(long, long, long, long,
                                                 unsigned char, unsigned char);
    virtual void map_generate(RGE_Player*, RGE_Game_World*, void*, unsigned char*);
    virtual void map_generate2(void*, long, long, unsigned char, long);

    RGE_Tile* map;
    long map_width;
    long map_height;
    long world_width;
    long world_height;
    struct RGE_Tile_Size {
        short width;
        short height;
        short y_delta;
    } tilesizes[19];
    unsigned char pad_8A[2];
    RGE_Tile_Set terrain_types[32];
    RGE_Border_Set border_types[16];
    RGE_Tile** map_row_offset;
    short num_terrain;
    short num_borders;
    short max_terrain;
    short tile_width;
    short tile_height;
    short tile_half_height;
    short tile_half_width;
    short elev_height;
    short cur_row;
    short cur_col;
    short block_beg_row;
    short block_end_row;
    short block_beg_col;
    short block_end_col;
    unsigned char any_frame_change;
    unsigned char pad_8DAD[3];
    unsigned char* search_map;
    unsigned char** search_map_rows;
    unsigned char map_visible_flag;
    unsigned char fog_flag;
    unsigned char pad_8DBA[2];
    RGE_RMM_Database_Controller* random_map;
    RGE_Game_World* game_world;
    RGE_Zone_Map_List* map_zones;
    RGE_Unified_Visible_Map* unified_vis_map;
    Visible_Unit_Manager* unit_manager;

    void update(unsigned long time);
};

void RGE_Map::update(unsigned long time)
{
    if (time - DAT_0062e65c < 100)
        return;

    float cur_time = (float)time * DAT_005706e8;
    short i;

    for (i = 0; i < this->num_terrain; ++i) {
        RGE_Tile_Set* terrain = &this->terrain_types[i];
        if (terrain->is_animated) {
            float elapsed = cur_time - terrain->animate_last;
            if (terrain->interval <= elapsed) {
                short frame_count = (short)(elapsed / terrain->interval);
                short animation_frames = terrain->animation_frames;
                short total_frames = terrain->pause_frames + animation_frames;
                short frame = frame_count + terrain->frame;

                if (frame >= total_frames)
                    frame %= total_frames;
                terrain->frame = frame;
                if (frame >= animation_frames)
                    frame = animation_frames - 1;
                if (terrain->draw_frame != frame) {
                    terrain->draw_frame = frame;
                    terrain->frame_changed = 1;
                    this->any_frame_change = 1;
                }
                terrain->animate_last = cur_time -
                    (elapsed - (float)frame_count * terrain->interval);
            }
        }
    }

    for (i = 0; i < this->num_borders; ++i) {
        RGE_Border_Set* border = &this->border_types[i];
        if (border->is_animated) {
            float elapsed = cur_time - border->animate_last;
            if (border->interval <= elapsed) {
                short frame_count = (short)(elapsed / border->interval);
                short animation_frames = border->animation_frames;
                short total_frames = border->pause_frames + animation_frames;
                short frame = frame_count + border->frame;

                if (frame >= total_frames)
                    frame %= total_frames;
                border->frame = frame;
                if (frame >= animation_frames)
                    frame = animation_frames - 1;
                if (border->draw_frame != frame) {
                    border->draw_frame = frame;
                    border->frame_changed = 1;
                    this->any_frame_change = 1;
                }
                border->animate_last = cur_time -
                    (elapsed - (float)frame_count * border->interval);
            }
        }
    }

    DAT_0062e65c = time;
}
