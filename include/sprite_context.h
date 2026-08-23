#ifndef SPRITE_CONTEXT_H
#define SPRITE_CONTEXT_H

// Canonical RGE_Sprite surface for the sprite.cpp owner group.
// Keep one class layout across the PDB-ordered owner includes.
class RGE_Color_Table;
class TDrawArea;
class RGE_Active_Sprite;
class RGE_Sprite;

class TShape {
public:
    char data[0x20];

    TShape(char* filename, long resource_id);
    ~TShape();
    unsigned char shape_draw(TDrawArea*, long, long, long,
                             unsigned char, unsigned char*);
    unsigned char shape_mirror(TDrawArea*, long, long, long,
                               unsigned char, unsigned char*);
    unsigned char shape_minmax(long* out_minx, long* out_miny,
                               long* out_maxx, long* out_maxy,
                               long facet);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    void add_to_timing(int index, unsigned long value);
};

extern RGE_Base_Game* rge_base_game;

class RGE_Sound {
public:
    char gap_00[0x0C];
    short id;

    void play(int add_to_list);
};

class RGE_Sound_List {
public:
    RGE_Sound* sound[3];
    short frame[3];
    char gap_12[2];
};

class RGE_Picture_List {
public:
    short picture_num;
    char gap_02[2];
    RGE_Sprite* sprite;
    short offset_x;
    short offset_y;
    short facet;
    char gap_0E[2];
};

class RGE_Sprite {
public:
    char pict_name[13];
    char gap_0D[3];
    long resource_id;
    unsigned char loaded;
    char gap_15[3];
    RGE_Color_Table** color_tables;
    TShape* shape;
    long last_time;
    long delta_time;
    unsigned char color_flag;
    unsigned char draw_level;
    short color_table;
    unsigned char transparent_picking_flag;
    char gap_2D[1];
    short box_x1;
    short box_y1;
    short box_x2;
    short box_y2;
    short draw_list_num;
    RGE_Picture_List* draw_list;
    RGE_Sound* main_sound;
    unsigned char micro_man_sound;
    char gap_41[3];
    RGE_Sound_List* sound_list;
    char name[21];
    char gap_5D[1];
    short frame_num;
    short facet_num;
    char gap_62[2];
    float base_speed;
    float duration;
    float pause_between_loops;
    unsigned char flags;
    char gap_71[1];
    short id;
    unsigned char mirror_flag;
    char gap_75[3];

    void load_facets(RGE_Sprite** facets);
    void play_sound(short param_1, short param_2, short param_3);
    unsigned char get_facetindex(long facet, long frame, long& frame_out);
    void do_draw(long param_1, long param_2, long param_3, long param_4,
                 RGE_Color_Table* color_table, TDrawArea* draw_area,
                 unsigned char color_index);
    unsigned char draw(long facet, long param_2, long param_3, long param_4,
                       long param_5, long param_6,
                       RGE_Color_Table* color_table, TDrawArea* draw_area,
                       unsigned char color_index);
    unsigned char normal_draw(long param_1, long param_2, long param_3,
                              long param_4, RGE_Color_Table* color_table,
                              TDrawArea* draw_area);
    unsigned char shadow_draw(long param_1, long param_2, long param_3,
                              long param_4, RGE_Color_Table* color_table,
                              TDrawArea* draw_area, unsigned char color_index);
    int get_size(long& min_x, long& min_y, long& max_x, long& max_y,
                 long facet);
    int get_frame(short& min_x, short& min_y, short& max_x, short& max_y,
                  long frame, long facet);
    int get_frame_min_max(short& min_x, short& min_y, short& max_x,
                          short& max_y, long frame, long facet,
                          short offset_x, short offset_y);
    unsigned char get_lowest_draw_level(void);
    unsigned char hit_test(short x, short y, long facet, long value);
    unsigned char shape_hit_test(short x, short y, long facet, long value);
    RGE_Active_Sprite* make_active_sprite();
    int check_for_shadows();
};

#endif
