#pragma once
#include "../common.h"

class RGE_Diamond_Map : public TPanel {
public:
    RGE_Game_World* world;                   // 0xF4
    RGE_Player* player;                      // 0xF8
    RGE_Map* map;                            // 0xFC
    int all_visible;                         // 0x100
    int render_all;                          // 0x104
    long mouse_last_x;                       // 0x108
    long mouse_last_y;                       // 0x10C
    int repos_mouse;                         // 0x110
    tagRECT view_rect;                       // 0x114
    RGE_Player* last_player;                 // 0x124
    RGE_Map_Image_Line* map_image_lines;     // 0x128
    RGE_Map_Tile_Row* map_tile_rows;         // 0x12C
    short map_wid;                           // 0x130
    short map_hgt;                           // 0x132
    short map_image_start_y;                 // 0x134
    short map_image_wid;                     // 0x136
    short map_image_hgt;                     // 0x138
    short map_tile_row_cnt;                  // 0x13A
    float map_row_step;                      // 0x13C
    float map_col_ratio;                     // 0x140
    float map_row_ratio;                     // 0x144
    short map_tile_draw_hgt;                 // 0x148
    short map_tile_draw_wid;                 // 0x14A
    short view_col;                          // 0x14C
    short view_row;                          // 0x14E
    RGE_View* main_view;                     // 0x150
    int scrolling;                           // 0x154
    uchar fog_color;                         // 0x158
    int draw_objects_mode;                   // 0x15C
    ulong cur_player_bit;                    // 0x160
    int own_save_area;                       // 0x164
    TDrawArea* save_area;                    // 0x168

    RGE_Diamond_Map();
    virtual ~RGE_Diamond_Map();
    virtual long setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7, int param_8, TDrawArea* param_9);
    virtual int set_bitmap(char* param_1, long param_2);
    virtual void set_world(RGE_Game_World* param_1);
    virtual void set_player(RGE_Player* param_1);
    virtual void set_redraw(RedrawMode param_1);
    virtual void delete_surfaces();
    virtual int create_surfaces();
    virtual void draw();
    virtual void clear_image();
    virtual void copy_image();
    virtual void draw_all_tiles();
    virtual void draw_explored_tiles();
    virtual void draw_tile(short param_1, short param_2, int param_3, uchar param_4);
    virtual void draw_selected_area();
    virtual void draw_objects();
    virtual void draw_visible_object(RGE_Static_Object* param_1, uchar param_2, uchar param_3);
    virtual void draw_object(short param_1, short param_2, uchar param_3, short param_4, RGE_Static_Object* param_5);
    virtual void draw_clipped_horz_line(short param_1, short param_2, short param_3, uchar param_4, RGE_Map_Image_Line* param_5);
    virtual void draw_view_rect();
    virtual int pick_tile(long param_1, long param_2, short* param_3, short* param_4, RGE_Tile** param_5);
    virtual long handle_size(long param_1, long param_2);
    virtual void start_scroll_view(long param_1, long param_2);
    virtual void handle_scroll_view(long param_1, long param_2);
    virtual void end_scroll_view();
    virtual int is_inside(long param_1, long param_2);
};

static_assert(sizeof(RGE_Diamond_Map) == 0x16C, "RGE_Diamond_Map Size Mismatch");
static_assert(offsetof(RGE_Diamond_Map, save_area) == 0x168, "RGE_Diamond_Map Offset Mismatch");

