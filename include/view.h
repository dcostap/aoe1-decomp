#ifndef AOE1_VIEW_H
#define AOE1_VIEW_H

#include <windows.h>

#include "panel.h"

typedef unsigned char uchar;

class TDrawArea;
class TMousePointer;
class TShape;
class TSpan_List_Manager;
class TMessagePanel;
class DClipInfo_List;
struct DClipInfo_Node;
struct Shape_Info;
struct Tile_FogEdge_Table;
struct Tile_BlackEdge_Table;
struct Blit_Queue_Entry;
struct DisplaySelectedObjRec;
struct Ov_Sprite_Draw_Rec;
struct RGE_Pick_Info;
struct RGE_Pick_Obj_Info;
struct RGE_SPick_Info;
class RGE_Map;
class RGE_Game_World;
class RGE_Player;
class RGE_Static_Object;
struct RGE_Tile;
class RGE_Base_Game;

class RGE_View : public TPanel {
public:
    RGE_View();
    virtual ~RGE_View();

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
    Tile_FogEdge_Table** Tile_Edge_Tables;
    Tile_BlackEdge_Table** Black_Edge_Tables;
    tagRECT OverlaidPanel;
    int OverlaidPanelActive;
    unsigned char EdgeNumber[0x100];
    int Limited_Render_Rect;
    int Use_Rect2;
    tagRECT Render_Rect1;
    tagRECT Render_Rect2;
    void** Float_Scroll_Offsets;
    int Float_Scroll_Offsets_Sz;
    int Float_X_Delta;
    int Float_Y_Delta;
    int Queued_Blits;
    Blit_Queue_Entry* Blit_Queue;
    int Blit_Queue_Size;
    int Blt_Queue_Allocated;
    int Current_Blit;
    int Blit_Offset_X;
    int Blit_Offset_Y;
    long real_old_map_col;
    long real_old_map_row;
    RGE_SPick_Info* pick_lists[5];
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

    long setup(TDrawArea*, TPanel*, long, long, long, long,
               unsigned char, int, char*);
    void set_rect(long, long, long, long);
    virtual void set_redraw(TPanel::RedrawMode);
    int bound_point(long&, long&);
    void set_world(RGE_Game_World*);
    void set_player(RGE_Player*);
    void set_selection_area(long, long, long, long);
    int get_selection_area(long&, long&, long&, long&, int);
    void update_display_selected_objects();
    void display_object_selection(int, int, int, int);
    void redraw(int);
    void target08(int);
    void reset_overlay_sprites();
    int draw(long, long, long, long, int);
    void draw();
    void game_mode_15_hook();
    void reset_cyclic_overlay_sprites();
    long Get_Cursor_Position(POINT*, long, long);
    long pick_touched_object(void*, long, long, long, long, long*);
    void get_string(long, char*, long);
    int Get_Cursor_Position(tagPOINT&, int, int);
    virtual int start_scroll_view(unsigned char, long, long, int, int);
    virtual int handle_scroll_view(long, long);
    virtual void end_scroll_view();
    virtual int do_paint(long, long, long, long, int);
    int is_inside(long, long);
    int capture_mouse();
    void add_overlay_sprite(TShape*, int, int, int, int, int,
                            unsigned char*, int, unsigned long);
    bool Object_Was_Displayed(int, bool);
    int get_game_enable();
    unsigned char pick_multi(unsigned char, long, long, long, long);
    int pick_through_fog(int);
    virtual int pick_through_fog(RGE_Static_Object*);
    virtual int pick_weight(RGE_Static_Object*, int);
    unsigned char pick(unsigned char, unsigned char, tagPOINT*, tagPOINT*,
                       void**, float*, float*, short*, short*);
    unsigned char pick(unsigned char, unsigned char, long, long,
                       RGE_Pick_Info*, RGE_Static_Object*);
    int create_surfaces();
    void delete_surfaces();
    void get_center_screen_pos(short*, short*);
    void get_start_coords(short*, short*, short*, short*);
    void get_center_coords(short*, short*, short*, short*);
    void get_tile_sizes(short*, short*, short*, short*);
    void get_max_size(short*, short*);
    virtual void draw_multi_object_outline();
    int get_tile_screen_coords(short, short, short*, short*, int);

protected:
    virtual void set_focus(int);
    void Init_Tile_Edge_Tables();
    void update();
    void CreateBlitQueue(tagRECT&, tagRECT&, int, int);
    void ProcessQueuedBlit(int);
    void draw_paint_brush();
    int draw_tile(RGE_Tile*, unsigned char, short, short, short, short,
                  unsigned char, int, int);
    int Pick_Tile(long, long, int*, int*);
    void get_tile_bounding_coords(int, int, int&, int&, int&, int&);
    int pick_objects(int, int, int, int, int, int, int);
    int pick_multi_objects(int, int, int, int, int, int, int,
                           unsigned char, int);
    int pick_touched_object(DClipInfo_List*, int, int, int, int, int&);
    int sprite_check(unsigned char*, Shape_Info*, int, int);
    void draw_terrain_shape(int, int, TShape*, int, unsigned char,
                            unsigned char, int, int);
    void draw_terrain_obstruction_map(int, int, TShape*, int, int, int);
    void calc_draw_vars();
    void draw_view(unsigned char, TDrawArea*);
    void draw_object_outline();
    long view_function_terrain(unsigned char, tagRECT);
    long view_function(unsigned char, unsigned char, tagPOINT*, tagPOINT*,
                       void**, float*, float*, short*, short*);
    short get_tile_picture(unsigned char, unsigned char, short, short);
    short get_border_picture(unsigned char, unsigned char, unsigned char,
                             short, short);
    int get_border_edge_pictures(unsigned char, unsigned char, unsigned char,
                                 short, short, int*, int*, int*, int*);
    int get_border_edge_pictures(unsigned char, unsigned char, unsigned char,
                                 short, short, int&, int&, int&, int&);
    RGE_Static_Object* hit_object(RGE_Tile*, short, short, short, short,
                                  tagPOINT*, tagPOINT*, short*, short*,
                                  RGE_Static_Object*, unsigned char);
    int hit_tile(RGE_Tile*, short, short, short, short, tagPOINT*);
    void Update_Render_Pointers();
    void Add_GDI_Clip_Mask(DClipInfo_Node*, TSpan_List_Manager*);
    void Draw_GDI_Object(DClipInfo_Node*, TDrawArea*);
    int get_tile_mask_num(int, int, int, int, unsigned long);
};

typedef char view_size_check[
    (sizeof(RGE_View) == 0x360) ? 1 : -1];

#endif
