#pragma once
#include "common.h"
#include "TPanel.h"

class TSpan_List_Manager;
struct Tile_FogEdge_Table;
struct Tile_BlackEdge_Table;
struct Blit_Queue_Entry;
struct RGE_Pick_Info;
struct RGE_SPick_Info;
struct DClipInfo_List;
struct Ov_Sprite_Draw_Rec;
class TMessagePanel;
class Shape_Info;

class RGE_View : public TPanel {
public:
    RGE_View();

    // Core overrides used by the in-game render pipeline.
    virtual ~RGE_View() override;
    virtual long setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) override;
    virtual void set_rect(tagRECT param_1) override;
    virtual void set_rect(long param_1, long param_2, long param_3, long param_4) override;
    virtual void draw() override;
    virtual void set_focus(int param_1) override;

    // View-specific virtuals.
    virtual int pick_through_fog(RGE_Static_Object* param_1);
    virtual int pick_weight(RGE_Static_Object* param_1, int param_2);
    virtual int start_scroll_view(uchar param_1, long param_2, long param_3, int param_4, int param_5);
    virtual int handle_scroll_view(long param_1, long param_2);
    virtual void end_scroll_view();
    virtual int do_paint(long param_1, long param_2, long param_3, long param_4, int param_5);
    virtual void draw_multi_object_outline();

    void set_selection_area(long param_1, long param_2, long param_3, long param_4);
    unsigned char pick(unsigned char param_1, unsigned char param_2, long param_3, long param_4, RGE_Pick_Info* param_5, RGE_Static_Object* param_6);
    unsigned char pick_multi(unsigned char param_1, long param_2, long param_3, long param_4, long param_5);
    int pick_objects(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7);
    int pick_multi_objects(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7, unsigned char param_8, int param_9);
    int sprite_check(unsigned char* param_1, Shape_Info* param_2, int param_3, int param_4);

    // Overlay helpers (view.cpp.decomp: selection flashes + overlay sprites).
    void display_object_selection(int id, int duration, int select_type, int reset_type);
    void reset_overlay_sprites();
    void add_overlay_sprite(TShape* shape, int facet, int world_x, int world_y, int flags, int draw_level, unsigned char* color_table, int display_function, unsigned long draw_interval);

    // Non-virtual helpers used by minimap (truth: view.cpp.decomp).
    int get_selection_area(long* col1, long* row1, long* col2, long* row2, int normalize);
    void get_max_size(short* max_col, short* max_row);

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
    void update();
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
