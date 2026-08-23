#ifndef AOE1_VIEW_TU_CONTEXT_H
#define AOE1_VIEW_TU_CONTEXT_H

#include <windows.h>
#include <stdlib.h>

extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void __cdecl operator_delete(void* ptr);

class DClipInfo_List;
class RGE_Map;
class RGE_SPick_Info;
class RGE_Static_Object;
class RGE_View;
class TMessagePanel;
class TShape;
struct Blit_Queue_Entry;
struct DisplaySelectedObjRec;
struct Ov_Sprite_Draw_Rec;
struct RGE_Color_Table;
struct RGE_Pick_Info;
struct Tile_BlackEdge_Table;
struct Tile_FogEdge_Table;

class TDrawArea {
public:
    unsigned char gap_00[0x08];
    unsigned char* Bits;
    unsigned char gap_0C[0x30];
    void* DrawSurface;
    unsigned char gap_40[0x7C];
    void** DisplayOffsets;
    unsigned char gap_C0[0x40];

    TDrawArea(char* name, int param);
    ~TDrawArea();
    unsigned char* Lock(char* name, int wait);
    void Unlock(char* name);
    int Init(void* system, int width, int height, int param4, int param5);
    void SetSize(int width, int height, int param3);
    void SetFloatOffsets(int x, int y);
    void DrawLine(int x1, int y1, int x2, int y2, unsigned char color);
};

class PanelNode;

class TPanel {
public:
    virtual ~TPanel();
    TPanel* previousPanelValue;
    TPanel* previousModalPanelValue;
    long pnl_x;
    long pnl_y;
    union {
        long pnl_wid;
        int width;
    };
    union {
        long pnl_hgt;
        int height;
    };
    char* panelNameValue;
    union {
        TDrawArea* render_area;
        void** drawSystem;
    };
    RECT clip_rect;
    int position_mode;
    int need_redraw;
    TPanel* curr_child;
    TPanel* parent_panel;
    TPanel* left_panel;
    TPanel* top_panel;
    TPanel* right_panel;
    TPanel* bottom_panel;
    PanelNode* node;
    PanelNode* first_child_node;
    PanelNode* last_child_node;
    TPanel* tab_prev_panel;
    TPanel* tab_next_panel;
    int mouse_captured;
    int active;
    int visible;
    int tab_stop;
    int have_focus;
    int overlapping_children;
    int handle_mouse_input;
    int just_drawn;
    void* clip_rgn;
    union {
        RECT render_rect;
        struct {
            long render_rect_left;
            long render_rect_top;
            long render_rect_right;
            long render_rect_bottom;
        };
        struct {
            long left;
            long top;
            long right;
            long bottom;
        };
    };
    long left_border;
    long top_border;
    long right_border;
    long bottom_border;
    long min_wid;
    long max_wid;
    long min_hgt;
    long max_hgt;
    long mouse_hold_interval;
    long mouse_move_tolerance;
    long mouse_down_x;
    long mouse_down_y;
    int mouse_down_ctrl;
    int mouse_down_shift;
    unsigned long mouse_down_time;
    int error_code;
    int z_order;
    int display_changed_count;
    long help_string_id;
    long help_page_id;
    unsigned char mouse_action;
    unsigned char mouse_down_button;
    unsigned char panel_type;
    unsigned char color;
    unsigned char fill_in_background;
    unsigned char clip_to_parent;
    unsigned char draw_rect2_flag;
    unsigned char need_restore;

    void set_rect(long left, long top, long width, long height);
};

struct RGE_Game_World {
    void* vtable_ptr;
    unsigned long world_time;
};

class RGE_Player {
public:
    void* vtable_ptr;
    char gap_04[0x1E];
    short master_object_num;
    struct RGE_Master_Static_Object** master_objects;
    char gap_28[0xE0];
    RGE_Color_Table* color_table;
};

class RGE_Base_Game {
public:
    void* vtable_ptr;
    char gap_04[0x1AC];
    int prog_mode;
    int game_mode;
    int sub_game_mode;
    char gap_1BC[0x238];
    RGE_Game_World* world;
    int render_all;
    short master_obj_id;
    short terrain_id;
    short elevation_height;
    short brush_size;

    RGE_Player* get_player();
    void get_mouse_pos(POINT& point);
};

#define rge_base_game (*(RGE_Base_Game**)0x0062C574)
#define fog_next_shape (*(int*)0x0086BBF0)
#define SDI_Draw_Line (*(int*)0x0086BBE0)

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object* object);
    virtual void modify(float amount, unsigned char attribute);
    virtual void modify_delta(float amount, unsigned char attribute);
    virtual void modify_percent(float amount, unsigned char attribute);
    virtual void save(int file);
    virtual RGE_Static_Object* make_new_obj(RGE_Player* player, float x, float y, float z);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual unsigned char check_placement(
        RGE_Player* player, float x, float y, int* placement,
        unsigned char check_terrain, unsigned char elevation,
        unsigned char check_objects, unsigned char check_units,
        unsigned char check_buildings, unsigned char check_fog);
    virtual unsigned char alignment(float* x, float* y,
                                    RGE_Game_World* world, unsigned char value);
    virtual long calc_base_damage_ability(void* object);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void draw(TDrawArea* area, short x, short y,
                      RGE_Color_Table* colors, long clip_x, long clip_y,
                      int value, unsigned char flags);

    char gap_04[0x14];
    TShape* sprite;
    char gap_1C[0x48];
    unsigned char elevation_flag;
    char gap_65[0x43];
    unsigned char draw_flag;
    unsigned char draw_color;

    unsigned char alignment_box(
        RGE_Game_World* world, float x, float y,
        short& x1, short& y1, short& x2, short& y2,
        short& x3, short& y3, short& x4, short& y4);
};

class RGE_Static_Object {
public:
    void* vtable_ptr;
    long id;
    void* master_obj;
    RGE_Player* owner;
    char gap_10[0x25];
    unsigned char facet;
    char gap_36[0x96];
};

struct RGE_Pick_Info {
    float x;
    float y;
    short scr_x;
    short scr_y;
    RGE_Static_Object* object;
    void* tile;
};

struct DClipInfo_Node {
    char gap_00[0x1C];
    unsigned char Draw_Flag;
    char gap_1D[0x0F];
    int Node_Type;
    short x1;
    short y1;
    short x2;
    short y2;
    short x3;
    short y3;
    short x4;
    short y4;
};

class TSpan_List_Manager {
public:
    char gap_00[0x68];
    TSpan_List_Manager(long width, long height);
    ~TSpan_List_Manager();
    void AddLine_Align(int x1, int y1, int x2, int y2);
    void AddSpan(int left, int right, int line);
};

class DClipInfo_List {
public:
    char gap_00[0x70];
    DClipInfo_List(int, int, int, int, int, int);
    ~DClipInfo_List();
    void SetDrawRegion(int x1, int y1, int x2, int y2);
};

class RGE_View : public TPanel {
public:
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
    unsigned char pad_12E[2];
    int map_scr_x_offset;
    int map_scr_y_offset;
    float last_view_x;
    float last_view_y;
    unsigned char function_mode;
    unsigned char function_parm;
    unsigned char render_terrain_mode;
    unsigned char pad_143;
    long sel_col1;
    long sel_row1;
    long sel_col2;
    long sel_row2;
    short save_paint_terrain;
    unsigned char pad_156[2];
    void* white_pen;
    void* red_pen;
    void* hollow_brush;
    TShape* border_line_shape;
    unsigned char scroll_action;
    unsigned char pad_169[3];
    long mouse_last_x;
    long mouse_last_y;
    RGE_Static_Object* movable_object;
    union {
        TSpan_List_Manager* Terrain_Clip_Mask;
        TSpan_List_Manager* tm;
    };
    union {
        TSpan_List_Manager* Terrain_Fog_Clip_Mask;
        TSpan_List_Manager* tfm;
    };
    union {
        TSpan_List_Manager* Master_Clip_Mask;
        TSpan_List_Manager* mcm;
    };
    Tile_FogEdge_Table** Tile_Edge_Tables;
    Tile_BlackEdge_Table** Black_Edge_Tables;
    RECT OverlaidPanel;
    int OverlaidPanelActive;
    unsigned char EdgeNumber[0x100];
    int Limited_Render_Rect;
    int Use_Rect2;
    RECT Render_Rect1;
    RECT Render_Rect2;
    void** Float_Scroll_Offsets;
    int Float_Scroll_Offsets_Sz;
    union {
        int Float_X_Delta;
        int float_x;
    };
    union {
        int Float_Y_Delta;
        int float_y;
    };
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

    int create_surfaces();
    void delete_surfaces();
    virtual void draw_multi_object_outline();
    void get_center_screen_pos(short* row, short* col);
    void get_start_coords(short* map_col, short* map_row,
                          short* scr_col, short* scr_row);
    void get_center_coords(short* map_col, short* map_row,
                           short* scr_col, short* scr_row);
    void get_tile_sizes(short* width, short* height,
                        short* half_width, short* half_height);
    void get_max_size(short* cols, short* rows);

protected:
    void calc_draw_vars();
    void draw_view(unsigned char mode, TDrawArea* area);
    void draw_object_outline();
    long view_function_terrain(unsigned char mode, RECT rect);
    long view_function(unsigned char mode, unsigned char parm, void*, void*,
                       void*, void*, void*, void*, void*);
    unsigned char pick(unsigned char mode, unsigned char parm,
                       long x, long y, RGE_Pick_Info* info,
                       RGE_Static_Object* object);
    int get_tile_screen_coords(short col, short row,
                               short* out_x, short* out_y, int adjust);
    void Update_Render_Pointers();
    void Add_GDI_Clip_Mask(DClipInfo_Node* node,
                           TSpan_List_Manager* span_manager);
    void Draw_GDI_Object(DClipInfo_Node* node, TDrawArea* area);
    int get_tile_mask_num(int col, int row, int map_width, int map_height,
                          unsigned long mask);
};

extern unsigned long* unified_map_offsets[];

typedef char view_tu_tdrawarea_size_check[(sizeof(TDrawArea) == 0x100) ? 1 : -1];
typedef char view_tu_tpanel_size_check[(sizeof(TPanel) == 0xF4) ? 1 : -1];
typedef char view_tu_view_size_check[(sizeof(RGE_View) == 0x360) ? 1 : -1];
typedef char view_tu_clip_node_size_check[(sizeof(DClipInfo_Node) == 0x40) ? 1 : -1];
typedef char view_tu_span_manager_size_check[(sizeof(TSpan_List_Manager) == 0x68) ? 1 : -1];
typedef char view_tu_clip_list_size_check[(sizeof(DClipInfo_List) == 0x70) ? 1 : -1];

#endif
