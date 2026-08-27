#ifndef AOE1_SPRITE_H
#define AOE1_SPRITE_H

#include <stdio.h>
#include "asp_list.h"

class DClipInfo_Node;
class RGE_Active_Sprite;
class RGE_Color_Table;
class RGE_Sound_Info;
class RGE_Sprite;
class Shape_File_Header;
class Shape_Header;
class Shape_Info;
class Shape_Offsets;
class SLhape_File_Header;
class TDrawArea;

class TShape {
public:
    unsigned char* shape;
    int load_type;
    int load_size;
    Shape_Header* shape_header;
    Shape_File_Header* head;
    Shape_Offsets* offsets;
    SLhape_File_Header* FShape;
    Shape_Info* shape_info;

    TShape(char* filename, long resource_id);
    ~TShape();
    unsigned char shape_draw(TDrawArea*, long, long, long,
                             unsigned char, unsigned char*);
    unsigned char shape_mirror(TDrawArea*, long, long, long,
                               unsigned char, unsigned char*);
    unsigned char shape_check(long, long, long);
    unsigned char shape_minmax(long* min_x, long* min_y,
                               long* max_x, long* max_y, long facet);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    void add_to_timing(int index, unsigned long value);
};

class RGE_Color_Table {
public:
    virtual ~RGE_Color_Table();
    char color_table_name[30];
    short resource_id;
    unsigned char type;
    unsigned char map_color;
    short id;
    unsigned char table[256];
};

class RGE_Sound {
public:
    short play_at_update_count;
    short sound_num;
    RGE_Sound_Info* sounds;
    unsigned long cache_time;
    short id;
    unsigned char gap_0E[2];

    void play(int add_to_list);
};

class RGE_Sound_List {
public:
    RGE_Sound* sound[3];
    short frame[3];
    unsigned char gap_12[2];
};

class RGE_Picture_List {
public:
    short picture_num;
    unsigned char gap_02[2];
    RGE_Sprite* sprite;
    short offset_x;
    short offset_y;
    short facet;
    unsigned char gap_0E[2];
};

class DClipInfo_List {
public:
    DClipInfo_Node** zone_ptrs;
    int* zone_size_ptrs;
    int used_zones;
    int max_zones;
    DClipInfo_Node* free_head;
    int free_pool_zone;
    int free_pool_index;
    int total_blocks;
    int free_blocks;
    int default_grow_size;
    int element_size;
    int alloc_count;
    int dealloc_count;
    int new_zone_count;
    int reset_count;
    int sd_x_min;
    int sd_x_max;
    int sd_y_min;
    int sd_y_max;
    int max_draw_levels;
    int accept_min_level;
    int accept_max_level;
    DClipInfo_Node** draw_clip_nodes;
    DClipInfo_Node** draw_level_head;
    DClipInfo_Node** draw_level_tail;
    int y_line_offset;
    int y_line_size;
    short* Select_Box;
};

class RGE_Sprite {
public:
    char pict_name[13];
    unsigned char gap_0D[3];
    long resource_id;
    unsigned char loaded;
    unsigned char gap_15[3];
    RGE_Color_Table** color_tables;
    TShape* shape;
    long last_time;
    long delta_time;
    unsigned char color_flag;
    unsigned char draw_level;
    short color_table;
    unsigned char transparent_picking_flag;
    unsigned char gap_2D[1];
    short box_x1;
    short box_y1;
    short box_x2;
    short box_y2;
    short draw_list_num;
    RGE_Picture_List* draw_list;
    RGE_Sound* main_sound;
    unsigned char micro_man_sound;
    unsigned char gap_41[3];
    RGE_Sound_List* sound_list;
    char name[21];
    unsigned char gap_5D[1];
    short frame_num;
    short facet_num;
    unsigned char gap_62[2];
    float base_speed;
    float duration;
    float pause_between_loops;
    unsigned char flags;
    unsigned char gap_71[1];
    short id;
    unsigned char mirror_flag;
    unsigned char gap_75[3];

    RGE_Sprite(short id);
    RGE_Sprite(int handle, RGE_Sound** sounds,
               RGE_Color_Table** color_tables);
    RGE_Sprite(FILE* infile, short sprite_id, RGE_Sound** sounds);
    ~RGE_Sprite();
    void rehook(RGE_Sprite** sprites);
    void save(int handle);
    void load_facets(RGE_Sprite** facets);
    void play_sound(short param_1, short param_2, short param_3);
    unsigned char get_facetindex(long facet, long frame, long& frame_out);
    void do_draw(long facet, long frame, long x, long y,
                 RGE_Color_Table* color_table, TDrawArea* draw_area,
                 unsigned char draw_level);
    unsigned char draw(long facet, long param_2, long param_3, long param_4,
                       long param_5, long param_6,
                       RGE_Color_Table* color_table, TDrawArea* draw_area,
                       unsigned char color_index);
    unsigned char normal_draw(long facet, long param_2, long param_3,
                              long param_4, RGE_Color_Table* color_table,
                              TDrawArea* draw_area);
    unsigned char shadow_draw(long facet, long param_2, long param_3,
                              long param_4, RGE_Color_Table* color_table,
                              TDrawArea* draw_area, unsigned char draw_level);
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
    void update(unsigned long time);
};

typedef char sprite_tshape_size_check[(sizeof(TShape) == 0x20) ? 1 : -1];
typedef char sprite_color_table_size_check[
    (sizeof(RGE_Color_Table) == 0x128) ? 1 : -1];
typedef char sprite_sound_size_check[(sizeof(RGE_Sound) == 0x10) ? 1 : -1];
typedef char sprite_sound_list_size_check[
    (sizeof(RGE_Sound_List) == 0x14) ? 1 : -1];
typedef char sprite_picture_list_size_check[
    (sizeof(RGE_Picture_List) == 0x10) ? 1 : -1];
typedef char sprite_clip_list_size_check[
    (sizeof(DClipInfo_List) == 0x70) ? 1 : -1];
typedef char sprite_size_check[(sizeof(RGE_Sprite) == 0x78) ? 1 : -1];

extern RGE_Base_Game* rge_base_game;
extern DClipInfo_List* SDI_List;
extern int SDI_Draw_Level;
extern int do_draw_log;
extern int safe_draw_log;

#endif
