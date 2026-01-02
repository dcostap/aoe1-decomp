#pragma once
#include "../common.h"

class DClipInfo_List {
public:
    int* Zone_Size_Ptrs;                     // 0x4
    int Used_Zones;                          // 0x8
    int Max_Zones;                           // 0xC
    DClipInfo_Node* Free_Head;               // 0x10
    int Free_Pool_Zone;                      // 0x14
    int Free_Pool_Index;                     // 0x18
    int Total_Blocks;                        // 0x1C
    int Free_Blocks;                         // 0x20
    int Default_Grow_Size;                   // 0x24
    int Element_Size;                        // 0x28
    int Alloc_Count;                         // 0x2C
    int Dealloc_Count;                       // 0x30
    int NewZone_Count;                       // 0x34
    int Reset_Count;                         // 0x38
    int SD_XMin;                             // 0x3C
    int SD_XMax;                             // 0x40
    int SD_YMin;                             // 0x44
    int SD_YMax;                             // 0x48
    int Max_Draw_Levels;                     // 0x4C
    int Accept_Min_Level;                    // 0x50
    int Accept_Max_Level;                    // 0x54
    DClipInfo_Node** Draw_Clip_Nodes;        // 0x58
    DClipInfo_Node** Draw_Level_Head;        // 0x5C
    DClipInfo_Node** Draw_Level_Tail;        // 0x60
    int YLine_Offset;                        // 0x64
    int YLine_Size;                          // 0x68
    short* Select_Box;                       // 0x6C

    DClipInfo_List(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6);
    virtual ~DClipInfo_List();
    virtual void SetCaptureLevel(int param_1, int param_2);
    virtual void SetNumZones(int param_1);
    virtual void InitNewZone(int param_1);
    virtual DClipInfo_Node* GetNode();
    virtual void SetDrawRegion(int param_1, int param_2, int param_3, int param_4);
    virtual void AddDrawNode(void* param_1, Shape_Info* param_2, int param_3, int param_4, int param_5, int param_6, uchar* param_7, int param_8, int param_9, int param_10);
    virtual DClipInfo_Node* AddGDINode(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7, int param_8, int param_9, int param_10, int param_11, int param_12, int param_13);
    virtual DClipInfo_Node* LocateIDbyDrawLevel(int param_1, int param_2, int param_3, int param_4);
    virtual void Scroll(int param_1, int param_2);
    virtual void FreeNode(DClipInfo_Node* param_1);
    virtual int FreeThread(DClipInfo_Node* param_1, DClipInfo_Node* param_2);
    virtual void ReclaimAllNodes();
    virtual void ResetStats();
};

static_assert(sizeof(DClipInfo_List) == 0x70, "DClipInfo_List Size Mismatch");
static_assert(offsetof(DClipInfo_List, Select_Box) == 0x6C, "DClipInfo_List Offset Mismatch");

class RGE_View : public TPanel {
public:
    TDrawArea* cur_render_area;              // 0xF4
    int calc_draw_count;                     // 0xF8
    RGE_Game_World* world;                   // 0xFC
    RGE_Player* player;                      // 0x100
    RGE_Map* map;                            // 0x104
    short tile_wid;                          // 0x108
    short tile_hgt;                          // 0x10A
    short tile_half_wid;                     // 0x10C
    short tile_half_hgt;                     // 0x10E
    short elev_hgt;                          // 0x110
    short render_rect_wid;                   // 0x112
    short render_rect_hgt;                   // 0x114
    short max_col_num;                       // 0x116
    short max_row_num;                       // 0x118
    short center_scr_col;                    // 0x11A
    short center_scr_row;                    // 0x11C
    short center_scr_col_offset;             // 0x11E
    short center_scr_row_offset;             // 0x120
    short center_map_col;                    // 0x122
    short center_map_row;                    // 0x124
    short start_scr_col;                     // 0x126
    short start_scr_row;                     // 0x128
    short start_map_col;                     // 0x12A
    short start_map_row;                     // 0x12C
    int map_scr_x_offset;                    // 0x130
    int map_scr_y_offset;                    // 0x134
    float last_view_x;                       // 0x138
    float last_view_y;                       // 0x13C
    uchar function_mode;                     // 0x140
    uchar function_parm;                     // 0x141
    uchar render_terrain_mode;               // 0x142
    long sel_col1;                           // 0x144
    long sel_row1;                           // 0x148
    long sel_col2;                           // 0x14C
    long sel_row2;                           // 0x150
    short save_paint_terrain;                // 0x154
    void* white_pen;                         // 0x158
    void* red_pen;                           // 0x15C
    void* hollow_brush;                      // 0x160
    TShape* border_line_shape;               // 0x164
    uchar scroll_action;                     // 0x168
    long mouse_last_x;                       // 0x16C
    long mouse_last_y;                       // 0x170
    RGE_Static_Object* movable_object;       // 0x174
    TSpan_List_Manager* Terrain_Clip_Mask;   // 0x178
    TSpan_List_Manager* Terrain_Fog_Clip_Mask; // 0x17C
    TSpan_List_Manager* Master_Clip_Mask;    // 0x180
    Tile_FogEdge_Table** Tile_Edge_Tables;   // 0x184
    Tile_BlackEdge_Table** Black_Edge_Tables; // 0x188
    tagRECT OverlaidPanel;                   // 0x18C
    int OverlaidPanelActive;                 // 0x19C
    uchar EdgeNumber[256];                   // 0x1A0
    int Limited_Render_Rect;                 // 0x2A0
    int Use_Rect2;                           // 0x2A4
    tagRECT Render_Rect1;                    // 0x2A8
    tagRECT Render_Rect2;                    // 0x2B8
    void** Float_Scroll_Offsets;             // 0x2C8
    int Float_Scroll_Offsets_Sz;             // 0x2CC
    int Float_X_Delta;                       // 0x2D0
    int Float_Y_Delta;                       // 0x2D4
    int Queued_Blits;                        // 0x2D8
    Blit_Queue_Entry* Blit_Queue;            // 0x2DC
    int Blit_Queue_Size;                     // 0x2E0
    int Blt_Queue_Allocated;                 // 0x2E4
    int Current_Blit;                        // 0x2E8
    int Blit_Offset_X;                       // 0x2EC
    int Blit_Offset_Y;                       // 0x2F0
    long real_old_map_col;                   // 0x2F4
    long real_old_map_row;                   // 0x2F8
    RGE_SPick_Info* pick_lists[5];           // 0x2FC
    int pick_list_size[5];                   // 0x310
    TDrawArea* save_area1;                   // 0x324
    uchar* LastRenderBits;                   // 0x328
    void** RenderOffsets;                    // 0x32C
    int LastRenderSize;                      // 0x330
    DClipInfo_List* prior_objs;              // 0x334
    DClipInfo_List* futur_objs;              // 0x338
    int UC_ObjectTouched;                    // 0x33C
    int UC_TouchedObj;                       // 0x340
    ulong UC_StartTime;                      // 0x344
    ulong UC_ElapsedTime;                    // 0x348
    TMessagePanel* message_panel;            // 0x34C
    Ov_Sprite_Draw_Rec* extra_sprites;       // 0x350
    DisplaySelectedObjRec* DispSel_List;     // 0x354
    int DispSel_List_Size;                   // 0x358
    int DispSel_List_Max;                    // 0x35C

    RGE_View();
    virtual ~RGE_View();
    virtual long setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7, int param_8, char* param_9);
    virtual void set_focus(int param_1);
    virtual void Init_Tile_Edge_Tables();
    virtual void update_display_selected_objects();
    virtual void display_object_selection(int param_1, int param_2, int param_3, int param_4);
    virtual void set_rect(long param_1, long param_2, long param_3, long param_4);
    virtual void delete_surfaces();
    virtual int create_surfaces();
    virtual void calc_draw_vars();
    virtual void set_redraw(RedrawMode param_1);
    virtual void set_world(RGE_Game_World* param_1);
    virtual void set_player(RGE_Player* param_1);
    virtual void set_selection_area(long param_1, long param_2, long param_3, long param_4);
    virtual int get_selection_area(long* param_1, long* param_2, long* param_3, long* param_4, int param_5);
    virtual void CreateBlitQueue(tagRECT* param_1, tagRECT* param_2, int param_3, int param_4);
    virtual void ProcessQueuedBlit(int param_1);
    virtual void draw();
    virtual void update();
    virtual void draw_view(uchar param_1, TDrawArea* param_2);
    virtual void draw_object_outline();
    virtual void draw_paint_brush();
    virtual uchar pick(uchar param_1, uchar param_2, long param_3, long param_4, RGE_Pick_Info* param_5, RGE_Static_Object* param_6);
    virtual uchar pick_multi(uchar param_1, long param_2, long param_3, long param_4, long param_5);
    virtual uchar pick(uchar param_1, uchar param_2, tagPOINT* param_3, tagPOINT* param_4, void** param_5, float* param_6, float* param_7, short* param_8, short* param_9);
    virtual int pick_through_fog(RGE_Static_Object* param_1);
    virtual int pick_weight(RGE_Static_Object* param_1, int param_2);
    virtual int get_tile_screen_coords(short param_1, short param_2, short* param_3, short* param_4, int param_5);
    virtual void get_center_screen_pos(short* param_1, short* param_2);
    virtual void get_start_coords(short* param_1, short* param_2, short* param_3, short* param_4);
    virtual void get_center_coords(short* param_1, short* param_2, short* param_3, short* param_4);
    virtual void get_tile_sizes(short* param_1, short* param_2, short* param_3, short* param_4);
    virtual void get_max_size(short* param_1, short* param_2);
    virtual long view_function(uchar param_1, uchar param_2, tagPOINT* param_3, tagPOINT* param_4, void** param_5, float* param_6, float* param_7, short* param_8, short* param_9);
    virtual long view_function_terrain(uchar param_1, tagRECT param_2);
    virtual void Update_Render_Pointers();
    virtual void Add_GDI_Clip_Mask(DClipInfo_Node* param_1, TSpan_List_Manager* param_2);
    virtual void draw_multi_object_outline();
    virtual void Draw_GDI_Object(DClipInfo_Node* param_1, TDrawArea* param_2);
    virtual int get_tile_mask_num(int param_1, int param_2, int param_3, int param_4, ulong param_5);
    virtual int draw_tile(RGE_Tile* param_1, uchar param_2, short param_3, short param_4, short param_5, short param_6, uchar param_7, int param_8, int param_9);
    virtual void draw_terrain_shape(int param_1, int param_2, TShape* param_3, int param_4, uchar param_5, uchar param_6, int param_7, int param_8);
    virtual void draw_terrain_obstruction_map(int param_1, int param_2, TShape* param_3, int param_4, int param_5, int param_6);
    virtual int Get_Cursor_Position(tagPOINT* param_1, int param_2, int param_3);
    virtual int Pick_Tile(long param_1, long param_2, int* param_3, int* param_4);
    virtual void get_tile_bounding_coords(int param_1, int param_2, int* param_3, int* param_4, int* param_5, int* param_6);
    virtual int pick_objects(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7);
    virtual int sprite_check(uchar* param_1, Shape_Info* param_2, int param_3, int param_4);
    virtual int pick_multi_objects(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7, uchar param_8, int param_9);
    virtual int pick_touched_object(DClipInfo_List* param_1, int param_2, int param_3, int param_4, int param_5, int* param_6);
    virtual short get_tile_picture(uchar param_1, uchar param_2, short param_3, short param_4);
    virtual short get_border_picture(uchar param_1, uchar param_2, uchar param_3, short param_4, short param_5);
    virtual int get_border_edge_pictures(uchar param_1, uchar param_2, uchar param_3, short param_4, short param_5, int* param_6, int* param_7, int* param_8, int* param_9);
    virtual int hit_tile(RGE_Tile* param_1, short param_2, short param_3, short param_4, short param_5, tagPOINT* param_6);
    virtual RGE_Static_Object* hit_object(RGE_Tile* param_1, short param_2, short param_3, short param_4, short param_5, tagPOINT* param_6, tagPOINT* param_7, short* param_8, short* param_9, RGE_Static_Object* param_10, uchar param_11);
    virtual int start_scroll_view(uchar param_1, long param_2, long param_3, int param_4, int param_5);
    virtual int handle_scroll_view(long param_1, long param_2);
    virtual void end_scroll_view();
    virtual int do_paint(long param_1, long param_2, long param_3, long param_4, int param_5);
    virtual void reset_overlay_sprites();
    virtual void reset_cyclic_overlay_sprites();
    virtual void add_overlay_sprite(TShape* param_1, int param_2, int param_3, int param_4, int param_5, int param_6, uchar* param_7, int param_8, ulong param_9);
    virtual bool Object_Was_Displayed(int param_1, bool param_2);
};

static_assert(sizeof(RGE_View) == 0x360, "RGE_View Size Mismatch");
static_assert(offsetof(RGE_View, DispSel_List_Max) == 0x35C, "RGE_View Offset Mismatch");

