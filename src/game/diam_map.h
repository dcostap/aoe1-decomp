#pragma once
#include "../common.h"
#include "World.h"
#include "Pnl_scr.h"
#include "Shape.h"
#include "tvw_main.h"
#include "tvw_dmap.h"
#include "map.h"
#include "Panel.h"
#include "Drawarea.h"
#include "view.h"
#include "player.h"

class RGE_Diamond_Map : public TPanel       {
public:
    char _pad_0x4[0xF0];
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

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~RGE_Diamond_Map() noexcept(false); // Ghidra: `vector_deleting_destructor'

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 02] Offset 0x08 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 03] Offset 0x0C WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 04] Offset 0x10 WARNING: Function body missing in analysis
    // virtual void set_color();

    // [Slot 05] Offset 0x14 WARNING: Function body missing in analysis
    // virtual void set_active();

    // [Slot 06] Offset 0x18 WARNING: Function body missing in analysis
    // virtual void set_positioning();

    // [Slot 07] Offset 0x1C WARNING: Function body missing in analysis
    // virtual void set_fixed_position();

    // [Slot 08] Offset 0x20 (Override)
    virtual void set_redraw(RedrawMode param_1); // Ghidra: set_redraw

    // [Slot 09] Offset 0x24 WARNING: Function body missing in analysis
    // virtual void set_overlapped_redraw();

    // [Slot 10] Offset 0x28 WARNING: Function body missing in analysis
    // virtual void draw_setup();

    // [Slot 11] Offset 0x2C WARNING: Function body missing in analysis
    // virtual void draw_finish();

    // [Slot 12] Offset 0x30 (Override)
    virtual void draw(); // Ghidra: draw

    // [Slot 13] Offset 0x34 WARNING: Function body missing in analysis
    // virtual void draw_rect();

    // [Slot 14] Offset 0x38 WARNING: Function body missing in analysis
    // virtual void draw_offset();

    // [Slot 15] Offset 0x3C WARNING: Function body missing in analysis
    // virtual void draw_rect2();

    // [Slot 16] Offset 0x40 WARNING: Function body missing in analysis
    // virtual void draw_offset2();

    // [Slot 17] Offset 0x44 WARNING: Function body missing in analysis
    // virtual void paint();

    // [Slot 18] Offset 0x48 WARNING: Function body missing in analysis
    // virtual void wnd_proc();

    // [Slot 19] Offset 0x4C WARNING: Function body missing in analysis
    // virtual void handle_idle();

    // [Slot 20] Offset 0x50 (Override)
    virtual long handle_size(long param_1, long param_2); // Ghidra: handle_size

    // [Slot 21] Offset 0x54 WARNING: Function body missing in analysis
    // virtual void handle_paint();

    // [Slot 22] Offset 0x58 WARNING: Function body missing in analysis
    // virtual void handle_key_down();

    // [Slot 23] Offset 0x5C WARNING: Function body missing in analysis
    // virtual void handle_char();

    // [Slot 24] Offset 0x60 WARNING: Function body missing in analysis
    // virtual void handle_command();

    // [Slot 25] Offset 0x64 WARNING: Function body missing in analysis
    // virtual void handle_user_command();

    // [Slot 26] Offset 0x68 WARNING: Function body missing in analysis
    // virtual void handle_timer_command();

    // [Slot 27] Offset 0x6C WARNING: Function body missing in analysis
    // virtual void handle_scroll();

    // [Slot 28] Offset 0x70 WARNING: Function body missing in analysis
    // virtual void handle_mouse_down();

    // [Slot 29] Offset 0x74 WARNING: Function body missing in analysis
    // virtual void handle_mouse_move();

    // [Slot 30] Offset 0x78 WARNING: Function body missing in analysis
    // virtual void handle_mouse_up();

    // [Slot 31] Offset 0x7C WARNING: Function body missing in analysis
    // virtual void handle_mouse_dbl_click();

    // [Slot 32] Offset 0x80 WARNING: Function body missing in analysis
    // virtual void mouse_move_action();

    // [Slot 33] Offset 0x84 WARNING: Function body missing in analysis
    // virtual void mouse_left_down_action();

    // [Slot 34] Offset 0x88 WARNING: Function body missing in analysis
    // virtual void mouse_left_hold_action();

    // [Slot 35] Offset 0x8C WARNING: Function body missing in analysis
    // virtual void mouse_left_move_action();

    // [Slot 36] Offset 0x90 WARNING: Function body missing in analysis
    // virtual void mouse_left_up_action();

    // [Slot 37] Offset 0x94 WARNING: Function body missing in analysis
    // virtual void mouse_left_dbl_click_action();

    // [Slot 38] Offset 0x98 WARNING: Function body missing in analysis
    // virtual void mouse_right_down_action();

    // [Slot 39] Offset 0x9C WARNING: Function body missing in analysis
    // virtual void mouse_right_hold_action();

    // [Slot 40] Offset 0xA0 WARNING: Function body missing in analysis
    // virtual void mouse_right_move_action();

    // [Slot 41] Offset 0xA4 WARNING: Function body missing in analysis
    // virtual void mouse_right_up_action();

    // [Slot 42] Offset 0xA8 WARNING: Function body missing in analysis
    // virtual void mouse_right_dbl_click_action();

    // [Slot 43] Offset 0xAC WARNING: Function body missing in analysis
    // virtual void key_down_action();

    // [Slot 44] Offset 0xB0 WARNING: Function body missing in analysis
    // virtual void char_action();

    // [Slot 45] Offset 0xB4 WARNING: Function body missing in analysis
    // virtual void action();

    // [Slot 46] Offset 0xB8 WARNING: Function body missing in analysis
    // virtual void get_true_render_rect();

    // [Slot 47] Offset 0xBC (Override)
    virtual int is_inside(long param_1, long param_2); // Ghidra: is_inside

    // [Slot 48] Offset 0xC0 WARNING: Function body missing in analysis
    // virtual void set_focus();

    // [Slot 49] Offset 0xC4 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 50] Offset 0xC8 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 51] Offset 0xCC WARNING: Function body missing in analysis
    // virtual void get_help_info();

    // [Slot 52] Offset 0xD0 WARNING: Function body missing in analysis
    // virtual void stop_sound_system();

    // [Slot 53] Offset 0xD4 WARNING: Function body missing in analysis
    // virtual void restart_sound_system();

    // [Slot 54] Offset 0xD8 WARNING: Function body missing in analysis
    // virtual void take_snapshot();

    // [Slot 55] Offset 0xDC WARNING: Function body missing in analysis
    // virtual void handle_reactivate();

    // [Slot 56] Offset 0xE0 (Override)
    virtual void draw_selected_area(); // Ghidra: draw_selected_area

    // [Slot 57] Offset 0xE4 (Override)
    virtual void draw_objects(); // Ghidra: draw_objects

    // [Slot 58] Offset 0xE8 (Override)
    virtual void draw_visible_object(RGE_Static_Object* param_1, uchar param_2, uchar param_3); // Ghidra: draw_visible_object

    // [Slot 59] Offset 0xEC (Override)
    virtual void draw_object(short param_1, short param_2, uchar param_3, short param_4, RGE_Static_Object* param_5); // Ghidra: draw_object

    // [Slot 60] Offset 0xF0 (Override)
    virtual void draw_view_rect(); // Ghidra: draw_view_rect

    // --- Non-Virtual Members ---
    long setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7, int param_8, TDrawArea* param_9);
    int set_bitmap(char* param_1, long param_2);
    void set_world(RGE_Game_World* param_1);
    void set_player(RGE_Player* param_1);
    void delete_surfaces();
    int create_surfaces();
    void clear_image();
    void copy_image();
    void draw_all_tiles();
    void draw_explored_tiles();
    void draw_tile(short param_1, short param_2, int param_3, uchar param_4);
    void draw_clipped_horz_line(short param_1, short param_2, short param_3, uchar param_4, RGE_Map_Image_Line* param_5);
    int pick_tile(long param_1, long param_2, short* param_3, short* param_4, RGE_Tile** param_5);
    void start_scroll_view(long param_1, long param_2);
    void handle_scroll_view(long param_1, long param_2);
    void end_scroll_view();
};

static_assert(sizeof(RGE_Diamond_Map) == 0x16C, "RGE_Diamond_Map Size Mismatch");
static_assert(offsetof(RGE_Diamond_Map, save_area) == 0x168, "RGE_Diamond_Map Offset Mismatch");

