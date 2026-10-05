#ifndef AOE1_VIEW_H
#define AOE1_VIEW_H

#include <windows.h>

#include "game_globals.h"
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
class Tile_FogEdge_Table;
class Tile_BlackEdge_Table;
class Blit_Queue_Entry;
class DisplaySelectedObjRec;
class Ov_Sprite_Draw_Rec;
class RGE_SPick_Info;
struct RGE_Pick_Info;
class RGE_Map;
class RGE_Game_World;
class RGE_Player;
class RGE_Static_Object;
struct RGE_Tile;
class RGE_Base_Game;

class RGE_Pick_Info {
  public:
    float x;
    float y;
    short scr_x;
    short scr_y;
    RGE_Static_Object* object;
    RGE_Tile* tile;
};

class RGE_Pick_Obj_Info {
  public:
    int object_id;
    short confidence;
    short draw_level;
    short draw_x;
    short draw_y;
};

typedef char view_pick_info_size_check[(sizeof(RGE_Pick_Info) == 0x14) ? 1 : -1];
typedef char view_pick_object_info_size_check[(sizeof(RGE_Pick_Obj_Info) == 0x0C) ? 1 : -1];

extern RGE_Pick_Obj_Info Picked_Objects[];

class DClipInfo_Node {
  public:
    DClipInfo_Node* Next;
    DClipInfo_Node* NextOnLevel;
    int Object_ID;
    Shape_Info* Shape;
    int Draw_Level;
    int Draw_X;
    int Draw_Y;
    int Draw_Flag;
    unsigned char* Shape_Base;
    unsigned char* Color_Table;
    int Xform_Mask;
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

typedef char view_clip_node_size_check[(sizeof(DClipInfo_Node) == 0x40) ? 1 : -1];

class DClipInfo_List {
  private:
    DClipInfo_Node** Zone_Ptrs;
    int* Zone_Size_Ptrs;
    int Used_Zones;
    int Max_Zones;
    DClipInfo_Node* Free_Head;
    int Free_Pool_Zone;
    int Free_Pool_Index;
    int Total_Blocks;
    int Free_Blocks;
    int Default_Grow_Size;
    int Element_Size;
    int Alloc_Count;
    int Dealloc_Count;
    int NewZone_Count;
    int Reset_Count;
    int SD_XMin;
    int SD_XMax;
    int SD_YMin;
    int SD_YMax;
    int Max_Draw_Levels;
    int Accept_Min_Level;
    int Accept_Max_Level;

  public:
    DClipInfo_Node** Draw_Clip_Nodes;
    DClipInfo_Node** Draw_Level_Head;
    DClipInfo_Node** Draw_Level_Tail;
    int YLine_Offset;
    int YLine_Size;
    short* Select_Box;

    DClipInfo_List(int InitialSize, int GrowSize, int szitem, int top_Yline, int bottom_Yline, int mxLevel);
    ~DClipInfo_List();
    void SetDrawRegion(int Left, int Top, int Right, int Bottom);
    void Scroll(int xDelta, int yDelta);
    void ReclaimAllNodes();
    void SetCaptureLevel(int minLevel, int maxLevel);
    DClipInfo_Node* AddGDINode(
        int GDI_Type, int SortLine, int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4, int DrawLevel,
        int DrawColor, int Object_ID
    );
    DClipInfo_Node* GetNode();
    void AddDrawNode(
        void* ShapeBase, Shape_Info* theShape, int SortLine, int Xpos, int Ypos, int DrawFlags,
        unsigned char* ColorTable, int XformMask, int DrawLevel, int Object_ID
    );
    DClipInfo_Node* LocateIDbyDrawLevel(int SearchID, int StartLevel, int EndLevel, int NodeType);
    void FreeNode(DClipInfo_Node* theNode);
    int FreeThread(DClipInfo_Node* HeadNode, DClipInfo_Node* TailNode);
    void ResetStats();

  private:
    void SetNumZones(int New_Size);
    void InitNewZone(int Zone_Size);
};

typedef char view_clip_list_size_check[(sizeof(DClipInfo_List) == 0x70) ? 1 : -1];

extern DClipInfo_List* SDI_List;
extern int SDI_Capture_Info;
extern int SDI_Draw_Line;
extern int SDI_Draw_Level;
extern long SDI_Object_ID;
extern long fog_next_shape;

extern int view_debug_redraw_all;
extern int view_debug_ObstructionMap;
extern int view_debug_Objects;
extern int view_debug_palette;
extern int view_debug_spans;
extern long frame_count;
extern long tiles_drawn;
extern int View_Grid_Mode;
extern int Clip_draw;
extern int Clip_remove;

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

    long setup(
        TDrawArea* render_area_in, TPanel* parent_panel_in, long x_in, long y_in, long wid_in, long hgt_in,
        unsigned char color_in, int calc_draw_count_in, char* border_line_file
    );
    void set_rect(long x_in, long y_in, long wid_in, long hgt_in);
    virtual void set_redraw(TPanel::RedrawMode redraw_mode);
    void set_world(RGE_Game_World* world_in);
    void set_player(RGE_Player* player_in);
    void set_selection_area(long sel_col1_in, long sel_row1_in, long sel_col2_in, long sel_row2_in);
    int get_selection_area(long& sel_col1_in, long& sel_row1_in, long& sel_col2_in, long& sel_row2_in, int fix_coords);
    void update_display_selected_objects();
    void display_object_selection(int id, int duration, int select_type, int reset_type);
    void redraw(int);
    void target08(int);
    void reset_overlay_sprites();
    int draw(long, long, long, long, int);
    void draw();
    void game_mode_15_hook();
    void reset_cyclic_overlay_sprites();
    int Get_Cursor_Position(tagPOINT& Point, int adjustX, int adjustY);
    // Original slots: pick +0xE0/+0xE4, scroll +0xE8 through +0xF4.
    virtual int pick_through_fog(RGE_Static_Object* obj);
    virtual int pick_weight(RGE_Static_Object* obj, int confidence);
    virtual int start_scroll_view(unsigned char scroll_action_in, long x, long y, int ctrl_key, int shift_key);
    virtual int handle_scroll_view(long x, long y);
    virtual void end_scroll_view();
    virtual int do_paint(long old_x, long old_y, long new_x, long new_y, int up_down);
    void add_overlay_sprite(
        TShape* theShape, int facet, int x, int y, int flags, int drawlevel, unsigned char* colorTable, int dispFunc,
        unsigned long DrawInterval
    );
    bool Object_Was_Displayed(int ObjectID, bool InFogOK);
    int get_game_enable();
    unsigned char pick_multi(unsigned char select_level, long x1, long y1, long x2, long y2);
    int pick_through_fog(int);
    unsigned char pick(
        unsigned char function_mode_in, unsigned char select_level, tagPOINT* mouse_pos, tagPOINT* start_mouse_pos,
        void** picked_item, float* item_x, float* item_y, short* item_scr_x, short* item_scr_y
    );
    unsigned char pick(
        unsigned char pick_mode_in, unsigned char select_level, long x, long y, RGE_Pick_Info* pick_info,
        RGE_Static_Object* last_picked_object
    );
    int create_surfaces();
    void delete_surfaces();
    void get_center_screen_pos(short* scr_x, short* scr_y);
    void get_start_coords(short* map_col, short* map_row, short* scr_col, short* scr_row);
    void get_center_coords(short* map_col, short* map_row, short* scr_col, short* scr_row);
    void get_tile_sizes(short* wid, short* hgt, short* half_wid, short* half_hgt);
    void get_max_size(short* col_num, short* row_num);
    virtual void draw_multi_object_outline();
    int get_tile_screen_coords(short find_col, short find_row, short* scr_x, short* scr_y, int drop);

  protected:
    virtual void set_focus(int have_focus_in);
    void Init_Tile_Edge_Tables();
    void update();
    void CreateBlitQueue(tagRECT& src_rect, tagRECT& dest_rect, int xDelta, int yDelta);
    void ProcessQueuedBlit(int WaitIfBusy);
    void draw_paint_brush();
    int draw_tile(
        RGE_Tile* tile, unsigned char terrain_type, short x, short y, short map_col, short map_row,
        unsigned char visible, int norm_draw, int fog_draw
    );
    int Pick_Tile(long x, long y, int* Tile_X, int* Tile_Y);
    void get_tile_bounding_coords(int Tile_X, int Tile_Y, int& bx1, int& by1, int& bx2, int& by2);
    int pick_objects(int Xpos, int Ypos, int min_level, int max_level, int range, int max_confidence, int ignoreNeg);
    int pick_multi_objects(
        int Xpos1, int Ypos1, int Xpos2, int Ypos2, int min_level, int max_level, int player,
        unsigned char select_level, int ignoreNeg
    );
    int pick_touched_object(
        DClipInfo_List* obj_list, int Xpos, int Ypos, int min_level, int max_level, int& touched_object_id
    );
    int sprite_check(unsigned char* Shape_Base, Shape_Info* Shape, int check_x, int check_y);
    void draw_terrain_shape(
        int x, int y, TShape* shape, int index, unsigned char visible, unsigned char draw_attribute, int draw_normal,
        int draw_fog
    );
    void draw_terrain_obstruction_map(int x, int y, TShape* shape, int index, int TileX, int TileY);
    void calc_draw_vars();
    void draw_view(unsigned char function_mode_in, TDrawArea* draw_area_in);
    void draw_object_outline();
    long view_function_terrain(unsigned char function_mode_in, tagRECT save_render_rect);
    long view_function(
        unsigned char function_mode_in, unsigned char function_parm_in, tagPOINT* mouse_pos, tagPOINT* start_mouse_pos,
        void** picked_item, float* item_x, float* item_y, short* item_scr_x, short* item_scr_y
    );
    short get_tile_picture(unsigned char terrain_type, unsigned char tile_type, short map_col, short map_row);
    short get_border_picture(
        unsigned char border_type, unsigned char tile_type, unsigned char border_shape, short map_col, short map_row
    );
    int get_border_edge_pictures(
        unsigned char border_type, unsigned char tile_type, unsigned char border_shape, short map_col, short map_row,
        int& top_index, int& right_index, int& left_index, int& bottom_index
    );
    RGE_Static_Object* hit_object(
        RGE_Tile* tile, short x, short y, short map_col, short map_row, tagPOINT* mouse_pos, tagPOINT* start_mouse_pos,
        short* item_scr_x, short* item_scr_y, RGE_Static_Object* orig_picked_obj, unsigned char fog_flag
    );
    int hit_tile(RGE_Tile* tile, short x, short y, short map_col, short map_row, tagPOINT* mouse_pos);
    void Update_Render_Pointers();
    void Add_GDI_Clip_Mask(DClipInfo_Node* SDI, TSpan_List_Manager* Clip_Mask);
    void Draw_GDI_Object(DClipInfo_Node* SDI, TDrawArea* render_area);
    int get_tile_mask_num(int map_col, int map_row, int map_width, int map_height, unsigned long VisibleMask);
};

typedef char view_size_check[(sizeof(RGE_View) == 0x360) ? 1 : -1];

#endif
