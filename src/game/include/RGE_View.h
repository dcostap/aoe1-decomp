#pragma once
#include "common.h"
#include "TPanel.h"

class TSpan_List_Manager;
struct Tile_FogEdge_Table;
struct Tile_BlackEdge_Table;
struct Blit_Queue_Entry;
struct RGE_SPick_Info;
struct DClipInfo_List;
struct Ov_Sprite_Draw_Rec;
class TMessagePanel;

class RGE_View : public TPanel {
public:
    // Virtuals (best-effort)
    virtual ~RGE_View(); // vt[0] (0x0)
    virtual long setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7); // vt[1] (0x4)
    virtual void set_rect(tagRECT param_1); // vt[2] (0x8)
    virtual void set_rect(long param_1, long param_2, long param_3, long param_4); // vt[3] (0xC)
    virtual void set_color(uchar param_1); // vt[4] (0x10)
    virtual void set_active(int param_1); // vt[5] (0x14)
    virtual void set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13); // vt[6] (0x18)
    virtual void set_fixed_position(long param_1, long param_2, long param_3, long param_4); // vt[7] (0x1C)
    virtual void set_redraw(RedrawMode param_1); // vt[8] (0x20)
    virtual void set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3); // vt[9] (0x24)
    virtual void draw_setup(int param_1); // vt[10] (0x28)
    virtual void draw_finish(); // vt[11] (0x2C)
    virtual void draw(); // vt[12] (0x30)
    virtual void draw_rect(tagRECT* param_1); // vt[13] (0x34)
    virtual void draw_offset(long param_1, long param_2, tagRECT* param_3); // vt[14] (0x38)
    virtual void draw_rect2(tagRECT* param_1); // vt[15] (0x3C)
    virtual void draw_offset2(long param_1, long param_2, tagRECT* param_3); // vt[16] (0x40)
    virtual void paint(); // vt[17] (0x44)
    virtual long wnd_proc(void* param_1, uint param_2, uint param_3, long param_4); // vt[18] (0x48)
    virtual long handle_idle(); // vt[19] (0x4C)
    virtual long handle_size(long param_1, long param_2); // vt[20] (0x50)
    virtual long handle_paint(); // vt[21] (0x54)
    virtual long handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5); // vt[22] (0x58)
    virtual long handle_char(long param_1, short param_2); // vt[23] (0x5C)
    virtual long handle_command(uint param_1, long param_2); // vt[24] (0x60)
    virtual long handle_user_command(uint param_1, long param_2); // vt[25] (0x64)
    virtual long handle_timer_command(uint param_1, long param_2); // vt[26] (0x68)
    virtual long handle_scroll(long param_1, long param_2); // vt[27] (0x6C)
    virtual long handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5); // vt[28] (0x70)
    virtual long handle_mouse_move(long param_1, long param_2, int param_3, int param_4); // vt[29] (0x74)
    virtual long handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5); // vt[30] (0x78)
    virtual long handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5); // vt[31] (0x7C)
    virtual long mouse_move_action(long param_1, long param_2, int param_3, int param_4); // vt[32] (0x80)
    virtual long mouse_left_down_action(long param_1, long param_2, int param_3, int param_4); // vt[33] (0x84)
    virtual long mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4); // vt[34] (0x88)
    virtual long mouse_left_move_action(long param_1, long param_2, int param_3, int param_4); // vt[35] (0x8C)
    virtual long mouse_left_up_action(long param_1, long param_2, int param_3, int param_4); // vt[36] (0x90)
    virtual long mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4); // vt[37] (0x94)
    virtual long mouse_right_down_action(long param_1, long param_2, int param_3, int param_4); // vt[38] (0x98)
    virtual long mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4); // vt[39] (0x9C)
    virtual long mouse_right_move_action(long param_1, long param_2, int param_3, int param_4); // vt[40] (0xA0)
    virtual long mouse_right_up_action(long param_1, long param_2, int param_3, int param_4); // vt[41] (0xA4)
    virtual long mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4); // vt[42] (0xA8)
    virtual long key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5); // vt[43] (0xAC)
    virtual long char_action(long param_1, short param_2); // vt[44] (0xB0)
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4); // vt[45] (0xB4)
    virtual void get_true_render_rect(tagRECT* param_1); // vt[46] (0xB8)
    virtual int is_inside(long param_1, long param_2); // vt[47] (0xBC)
    virtual void set_focus(int param_1); // vt[48] (0xC0)
    virtual void set_tab_order(TPanel* param_1, TPanel* param_2); // vt[49] (0xC4)
    virtual void set_tab_order(TPanel** param_1, short param_2); // vt[50] (0xC8)
    virtual uchar get_help_info(char** param_1, long* param_2, long param_3, long param_4); // vt[51] (0xCC)
    virtual void stop_sound_system(); // vt[52] (0xD0)
    virtual int restart_sound_system(); // vt[53] (0xD4)
    virtual void take_snapshot(); // vt[54] (0xD8)
    virtual void handle_reactivate(); // vt[55] (0xDC)
    virtual int pick_through_fog(RGE_Static_Object* param_1); // vt[56] (0xE0)
    virtual int pick_weight(RGE_Static_Object* param_1, int param_2); // vt[57] (0xE4)
    virtual int start_scroll_view(uchar param_1, long param_2, long param_3, int param_4, int param_5); // vt[58] (0xE8)
    virtual int handle_scroll_view(long param_1, long param_2); // vt[59] (0xEC)
    virtual void end_scroll_view(); // vt[60] (0xF0)
    virtual int do_paint(long param_1, long param_2, long param_3, long param_4, int param_5); // vt[61] (0xF4)
    virtual void draw_multi_object_outline(); // vt[62] (0xF8)

    TDrawArea* cur_render_area;
    int calc_draw_count;
    RGE_Game_World* world;
    RGE_Player* player;
    RGE_Map* map;
    short tile_wid;
    short tile_hgt;
    short tile_half_wid;
    short tile_half_hgt;
    short elev_hgt;
    short render_rect_wid;
    short render_rect_hgt;
    short max_col_num;
    short max_row_num;
    short center_scr_col;
    short center_scr_row;
    short center_scr_col_offset;
    short center_scr_row_offset;
    short center_map_col;
    virtual void update();
    void draw_view(uchar mode, TDrawArea* area);
    long view_function_terrain(uchar mode, tagRECT rect);
    int draw_tile(RGE_Tile* tile, uchar vis, short x, short y, short col, short row, uchar fog, int param_9, int param_10);
    void draw_terrain_shape(int x, int y, TShape* shape, int frame, uchar vis, uchar fog, int param_7, int param_8);
    short get_tile_picture(uchar terrain_type, uchar vis, short col, short row);
    short get_border_picture(uchar terrain_type, uchar border_type, uchar param_3, short col, short row);
    short center_map_row;
    short start_scr_col;
    short start_scr_row;
    short start_map_col;
    short start_map_row;
    int map_scr_x_offset;
    int map_scr_y_offset;
    float last_view_x;
    float last_view_y;
    unsigned char function_mode;
    unsigned char function_parm;
    unsigned char render_terrain_mode;
    long sel_col1;
    long sel_row1;
    long sel_col2;
    long sel_row2;
    short save_paint_terrain;
    void* white_pen;
    void* red_pen;
    void* hollow_brush;
    TShape* border_line_shape;
    unsigned char scroll_action;
    long mouse_last_x;
    long mouse_last_y;
    RGE_Static_Object* movable_object;
    TSpan_List_Manager* Terrain_Clip_Mask;
    TSpan_List_Manager* Terrain_Fog_Clip_Mask;
    TSpan_List_Manager* Master_Clip_Mask;
    struct Tile_FogEdge_Table** Tile_Edge_Tables;
    struct Tile_BlackEdge_Table** Black_Edge_Tables;
    tagRECT OverlaidPanel;
    int OverlaidPanelActive;
    unsigned char EdgeNumber[256];
    int Limited_Render_Rect;
    int Use_Rect2;
    tagRECT Render_Rect1;
    tagRECT Render_Rect2;
    void** Float_Scroll_Offsets;
    int Float_Scroll_Offsets_Sz;
    int Float_X_Delta;
    int Float_Y_Delta;
    int Queued_Blits;
    struct Blit_Queue_Entry* Blit_Queue;
    int Blit_Queue_Size;
    int Blt_Queue_Allocated;
    int Current_Blit;
    int Blit_Offset_X;
    int Blit_Offset_Y;
    long real_old_map_col;
    long real_old_map_row;
    struct RGE_SPick_Info* pick_lists[5];
    int pick_list_size[5];
    TDrawArea* save_area1;
    unsigned char* LastRenderBits;
    void** RenderOffsets;
    int LastRenderSize;
    DClipInfo_List* prior_objs;
    DClipInfo_List* futur_objs;
    int UC_ObjectTouched;
    int UC_TouchedObj;
    unsigned long UC_StartTime;
    unsigned long UC_ElapsedTime;
    TMessagePanel* message_panel;
    Ov_Sprite_Draw_Rec* extra_sprites;
    DisplaySelectedObjRec* DispSel_List;
    int DispSel_List_Size;
    int DispSel_List_Max;
};
// static_assert(sizeof(RGE_View) == 0x360, "Size mismatch");
