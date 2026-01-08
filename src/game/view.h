#pragma once
#include "../common.h"

class DClipInfo_List       {
public:
    DClipInfo_Node** Zone_Ptrs;              // 0x0
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

    // --- Non-Virtual Destructor ---
    ~DClipInfo_List() noexcept(false);
    // --- Non-Virtual Members ---
    void SetCaptureLevel(int param_1, int param_2);
    void SetNumZones(int param_1);
    void InitNewZone(int param_1);
    DClipInfo_Node* GetNode();
    void SetDrawRegion(int param_1, int param_2, int param_3, int param_4);
    void AddDrawNode(void* param_1, Shape_Info* param_2, int param_3, int param_4, int param_5, int param_6, uchar* param_7, int param_8, int param_9, int param_10);
    DClipInfo_Node* AddGDINode(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7, int param_8, int param_9, int param_10, int param_11, int param_12, int param_13);
    DClipInfo_Node* LocateIDbyDrawLevel(int param_1, int param_2, int param_3, int param_4);
    void Scroll(int param_1, int param_2);
    void FreeNode(DClipInfo_Node* param_1);
    int FreeThread(DClipInfo_Node* param_1, DClipInfo_Node* param_2);
    void ReclaimAllNodes();
    void ResetStats();
};

static_assert(sizeof(DClipInfo_List) == 0x70, "DClipInfo_List Size Mismatch");
static_assert(offsetof(DClipInfo_List, Select_Box) == 0x6C, "DClipInfo_List Offset Mismatch");

class RGE_View : public TPanel       {
public:
    char _pad_0x4[0xF0];
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

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~RGE_View() noexcept(false); // Ghidra: `vector_deleting_destructor'

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 02] Offset 0x08 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 03] Offset 0x0C (Override)
    virtual void set_rect(long param_1, long param_2, long param_3, long param_4); // Ghidra: set_rect

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

    // [Slot 20] Offset 0x50 WARNING: Function body missing in analysis
    // virtual void handle_size();

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

    // [Slot 47] Offset 0xBC WARNING: Function body missing in analysis
    // virtual void is_inside();

    // [Slot 48] Offset 0xC0 (Override)
    virtual void set_focus(int param_1); // Ghidra: set_focus

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
    virtual int pick_through_fog(RGE_Static_Object* param_1); // Ghidra: pick_through_fog

    // [Slot 57] Offset 0xE4 (Override)
    virtual int pick_weight(RGE_Static_Object* param_1, int param_2); // Ghidra: pick_weight

    // [Slot 58] Offset 0xE8 (Override)
    virtual int start_scroll_view(uchar param_1, long param_2, long param_3, int param_4, int param_5); // Ghidra: start_scroll_view

    // [Slot 59] Offset 0xEC (Override)
    virtual int handle_scroll_view(long param_1, long param_2); // Ghidra: handle_scroll_view

    // [Slot 60] Offset 0xF0 (Override)
    virtual void end_scroll_view(); // Ghidra: end_scroll_view

    // [Slot 61] Offset 0xF4 (Override)
    virtual int do_paint(long param_1, long param_2, long param_3, long param_4, int param_5); // Ghidra: do_paint

    // [Slot 62] Offset 0xF8 (Override)
    virtual void draw_multi_object_outline(); // Ghidra: draw_multi_object_outline

    // --- Non-Virtual Members ---
    long setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7, int param_8, char* param_9);
    void Init_Tile_Edge_Tables();
    void update_display_selected_objects();
    void display_object_selection(int param_1, int param_2, int param_3, int param_4);
    void delete_surfaces();
    int create_surfaces();
    void calc_draw_vars();
    void set_world(RGE_Game_World* param_1);
    void set_player(RGE_Player* param_1);
    void set_selection_area(long param_1, long param_2, long param_3, long param_4);
    int get_selection_area(long* param_1, long* param_2, long* param_3, long* param_4, int param_5);
    void CreateBlitQueue(tagRECT* param_1, tagRECT* param_2, int param_3, int param_4);
    void ProcessQueuedBlit(int param_1);
    void update();
    void draw_view(uchar param_1, TDrawArea* param_2);
    void draw_object_outline();
    void draw_paint_brush();
    uchar pick(uchar param_1, uchar param_2, long param_3, long param_4, RGE_Pick_Info* param_5, RGE_Static_Object* param_6);
    uchar pick_multi(uchar param_1, long param_2, long param_3, long param_4, long param_5);
    uchar pick(uchar param_1, uchar param_2, tagPOINT* param_3, tagPOINT* param_4, void** param_5, float* param_6, float* param_7, short* param_8, short* param_9);
    int get_tile_screen_coords(short param_1, short param_2, short* param_3, short* param_4, int param_5);
    void get_center_screen_pos(short* param_1, short* param_2);
    void get_start_coords(short* param_1, short* param_2, short* param_3, short* param_4);
    void get_center_coords(short* param_1, short* param_2, short* param_3, short* param_4);
    void get_tile_sizes(short* param_1, short* param_2, short* param_3, short* param_4);
    void get_max_size(short* param_1, short* param_2);
    long view_function(uchar param_1, uchar param_2, tagPOINT* param_3, tagPOINT* param_4, void** param_5, float* param_6, float* param_7, short* param_8, short* param_9);
    long view_function_terrain(uchar param_1, tagRECT param_2);
    void Update_Render_Pointers();
    void Add_GDI_Clip_Mask(DClipInfo_Node* param_1, TSpan_List_Manager* param_2);
    void Draw_GDI_Object(DClipInfo_Node* param_1, TDrawArea* param_2);
    int get_tile_mask_num(int param_1, int param_2, int param_3, int param_4, ulong param_5);
    int draw_tile(RGE_Tile* param_1, uchar param_2, short param_3, short param_4, short param_5, short param_6, uchar param_7, int param_8, int param_9);
    void draw_terrain_shape(int param_1, int param_2, TShape* param_3, int param_4, uchar param_5, uchar param_6, int param_7, int param_8);
    void draw_terrain_obstruction_map(int param_1, int param_2, TShape* param_3, int param_4, int param_5, int param_6);
    int Get_Cursor_Position(tagPOINT* param_1, int param_2, int param_3);
    int Pick_Tile(long param_1, long param_2, int* param_3, int* param_4);
    void get_tile_bounding_coords(int param_1, int param_2, int* param_3, int* param_4, int* param_5, int* param_6);
    int pick_objects(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7);
    int sprite_check(uchar* param_1, Shape_Info* param_2, int param_3, int param_4);
    int pick_multi_objects(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7, uchar param_8, int param_9);
    int pick_touched_object(DClipInfo_List* param_1, int param_2, int param_3, int param_4, int param_5, int* param_6);
    short get_tile_picture(uchar param_1, uchar param_2, short param_3, short param_4);
    short get_border_picture(uchar param_1, uchar param_2, uchar param_3, short param_4, short param_5);
    int get_border_edge_pictures(uchar param_1, uchar param_2, uchar param_3, short param_4, short param_5, int* param_6, int* param_7, int* param_8, int* param_9);
    int hit_tile(RGE_Tile* param_1, short param_2, short param_3, short param_4, short param_5, tagPOINT* param_6);
    RGE_Static_Object* hit_object(RGE_Tile* param_1, short param_2, short param_3, short param_4, short param_5, tagPOINT* param_6, tagPOINT* param_7, short* param_8, short* param_9, RGE_Static_Object* param_10, uchar param_11);
    void reset_overlay_sprites();
    void reset_cyclic_overlay_sprites();
    void add_overlay_sprite(TShape* param_1, int param_2, int param_3, int param_4, int param_5, int param_6, uchar* param_7, int param_8, ulong param_9);
    bool Object_Was_Displayed(int param_1, bool param_2);
};

static_assert(sizeof(RGE_View) == 0x360, "RGE_View Size Mismatch");
static_assert(offsetof(RGE_View, DispSel_List_Max) == 0x35C, "RGE_View Offset Mismatch");

