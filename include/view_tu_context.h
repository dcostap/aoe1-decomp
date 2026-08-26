#ifndef AOE1_VIEW_TU_CONTEXT_H
#define AOE1_VIEW_TU_CONTEXT_H

#include <windows.h>
#include <ddraw.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void __cdecl operator_delete(void* ptr);

class DClipInfo_List;
class TSpan_List_Manager;
class RGE_Map;
class RGE_Player;
class RGE_SPick_Info;
class RGE_Static_Object;
class RGE_Sprite;
class RGE_Visible_Map;
class RGE_Object_List;
class RGE_Sound;
class RGE_Master_Player;
class RGE_Effects;
class RGE_Scenario;
class TSound_Driver;
class TCommunications_Handler;
struct RGE_Player_Info;
struct RGE_Object_Node;
class RGE_Tile_List;
class TPanel_Prefix;
class RGE_View;
class TMessagePanel;
class TShape;
struct Blit_Queue_Entry;
struct DisplaySelectedObjRec;
struct Ov_Sprite_Draw_Rec;
struct RGE_Color_Table;
struct RGE_Pick_Info;
struct Shape_Info;
struct Tile_BlackEdge_Table;
struct Tile_FogEdge_Table;

class TDrawArea {
public:
    struct Draw_System {
        char gap[0x478];
        unsigned char field478;
    };
    union {
        unsigned char gap_00[0x08];
        Draw_System* DrawSystem;
    };
    unsigned char* Bits;
    union {
        unsigned char gap_0C[0x30];
        struct {
            unsigned char gap_0C_fields[0x0C];
            int Width;
            int Height;
            unsigned char gap_20_fields[0x08];
            RECT ClipRect;
            unsigned char gap_38_fields[0x04];
        };
    };
    IDirectDrawSurface* DrawSurface;
    unsigned char gap_40[0x7C];
    void** DisplayOffsets;
    union {
        unsigned char gap_C0[0x40];
        struct {
            unsigned char gap_C0_fields[0x0C];
            void* SavedMask;
            void* CurrentMask;
            int UsingVidMem;
            TSpan_List_Manager* CurSpanList;
            TSpan_List_Manager* SpanList;
            unsigned char gap_F4_fields[0x20];
        };
    };

    TDrawArea(char* name, int param);
    ~TDrawArea();
    unsigned char* Lock(char* name, int wait);
    void Unlock(char* name);
    void Unlock(const char* name);
    int Init(void* system, int width, int height, int param4, int param5);
    void SetSize(int width, int height, int param3);
    void SetFloatOffsets(int x, int y);
    void DrawLine(int x1, int y1, int x2, int y2, unsigned char color);
    void Clear(RECT* rect, int color);
    void OverlayMemCopy(RECT* dst, RECT* src, int x, int y, int a5, int a6);
    void PtrClear(RECT* rect, int fill);
    void PtrSpanCopy(TDrawArea* dst, long x, long y, RECT* clip,
                     unsigned char** lines);
    void FillRect(long left, long top, long right, long bottom,
                  unsigned char color);
    int WidthValue();
    int HeightValue();
};

class TShape {
public:
    TShape(char* name, int param);
    ~TShape();
    Shape_Info* shape_info;
    int shape_count();
    void shape_draw(TDrawArea* area, int x, int y, int facet,
                    unsigned char flags, unsigned char* colors);
    int shape_check(int x, int y, int frame);
    unsigned char shape_check(long dx, long dy, int frame);
};

class TMousePointer {
public:
    void set_game_mode(int mode);
    void set_game_enable(int enable);
    void set_game_window(long left, long top, long right, long bottom);
    void Poll();
    long get_game_enable();
    void set_game_facet(long facet);
};

struct Panel_List_Node {
    TPanel_Prefix* panel;
    Panel_List_Node* prev;
    Panel_List_Node* next;
};

class TMessagePanel_Prefix {
public:
    void show_message(long kind, char* text, char a, char b, void* c,
                      long d, long e);
    void remove_message();
};

class PathingSystem {
public:
    int obstruction(int x, int y);
};

extern PathingSystem pathSystem;

class PanelNode;

class TPanel {
public:
    TPanel();
    virtual ~TPanel();
    enum RedrawMode { redraw_mode_value };
    TPanel* previousPanelValue;
    TPanel* previousModalPanelValue;
    long pnl_x;
    long pnl_y;
    union {
        long pnl_wid;
        int width;
        int screen_w;
    };
    union {
        long pnl_hgt;
        int height;
        int screen_h;
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
    union {
        int have_focus;
        int game_enable;
    };
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
        struct {
            long field_8C;
            long field_90;
            long field_94;
            long field_98;
        };
        struct {
            long view_left;
            long view_top;
            long view_right;
            long view_bottom;
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
    union {
        unsigned char color;
        unsigned char clear_color;
    };
    unsigned char fill_in_background;
    unsigned char clip_to_parent;
    unsigned char draw_rect2_flag;
    unsigned char need_restore;

    virtual void v00();
    void set_focus(int focus);
    long setup(TDrawArea* draw, TPanel* parent, long x, long y, long w,
               long h, unsigned char flag);
    virtual void set_rect(long left, long top, long width, long height);
    virtual void set_redraw(RedrawMode mode);
    virtual void draw_setup(int mode);
    virtual void draw_finish();
    virtual void draw();
    void release_mouse();
};

class RGE_Game_World {
public:
    virtual unsigned char data_load_world(FILE*);
protected:
    virtual unsigned char data_load_terrain_tables(char*);
public:
    virtual unsigned char data_load_players(char*);
    virtual unsigned char data_load_objects(char*);
    virtual unsigned char data_load_sounds(char*);
    virtual unsigned char data_load_color_tables(char*);
    virtual unsigned char data_load_sprites(char*);
protected:
    virtual void data_load_players_type(short, short, FILE*);
public:
    virtual void data_load_effects(char*);
    virtual void data_load_map(char*, char*, char*, char*, short, short,
                               short, RGE_Sound**, char*);
    virtual void data_load_random_map(char*, char*, char*, char*);
protected:
    virtual unsigned char init_player_type(int, short, unsigned char);
public:
    virtual unsigned char init_player(int);
    virtual void load_player(int, unsigned char, short);
    virtual void color_table_init(int);
    virtual void terrain_tables_init(int);
    virtual void init_sounds(int, TSound_Driver*);
    virtual void init_sprites(int);
    virtual void map_init(int, TSound_Driver*);
    virtual void effects_init(int);
protected:
    virtual void master_player_init(int);
public:
    virtual void command_init(int, TCommunications_Handler*);
    virtual void world_init(int, TSound_Driver*, TCommunications_Handler*);
    virtual void setup_gaia();
    virtual void setup_players(RGE_Player_Info&);
protected:
    virtual unsigned char new_random_game(RGE_Player_Info&);
public:
    virtual void save(int);
protected:
    virtual void scenario_make_player(short, unsigned char, unsigned char,
                                      unsigned char, char*);
    virtual void scenario_make_map(int);
    virtual unsigned char load_scenario(char*, RGE_Player_Info&);
    virtual unsigned char load_scenario(RGE_Player_Info&);
    virtual void load_scenario1(int, RGE_Player_Info&);
    virtual void load_scenario2(int, RGE_Player_Info&);
    virtual void load_scenario3(int, RGE_Player_Info&);
    virtual void load_scenario4(int, RGE_Player_Info&);
    virtual void load_scenario5(int, RGE_Player_Info&);
    virtual void load_scenario6(int, RGE_Player_Info&);
    virtual void load_scenario7(int, RGE_Player_Info&);
    virtual void load_scenario8(int, RGE_Player_Info&);
public:
    virtual void logStatus(FILE*, int);
    virtual ~RGE_Game_World();
    virtual void setup_player_colors(RGE_Player_Info&);
    virtual void setup_player_colors();
    virtual unsigned char data_load(char*, char*);
    virtual unsigned char init(char*, TSound_Driver*, TCommunications_Handler*);
    virtual void turn_sound_off();
    virtual void del_game_info();
    virtual unsigned char update();
    virtual unsigned char get_game_state();
    virtual unsigned char check_game_state();
    virtual unsigned char load_world(int);
    virtual unsigned char load_game(char*);
    virtual unsigned char new_game(RGE_Player_Info&, int);
    virtual unsigned char new_scenario(RGE_Player_Info&, int);
    virtual unsigned char save_game(char*);
    virtual void base_save(int);
    virtual void base_save(char*);
    virtual unsigned char save_scenario(char*);
    virtual RGE_Scenario* get_scenario_info(char*);
    virtual void pause(unsigned char);
    virtual void scenario_init(int, RGE_Game_World*);
    virtual void scenario_init(RGE_Game_World*);

    unsigned long world_time;
    unsigned long old_world_time;
    unsigned long world_time_delta;
    float timer;
    unsigned long old_time;
    union {
        float game_speed;
        int game_speed_bits;
    };
    unsigned char temp_pause;
    unsigned char game_state;
    unsigned char game_end_condition;
    unsigned char gap_1F;
    long sound_update_index;
    long sprite_update_index;
    RGE_Map* map;
    short sound_num;
    unsigned char gap_2E[2];
    RGE_Sound** sounds;
    short sprite_num;
    unsigned char gap_36[2];
    RGE_Sprite** sprites;
    short player_num;
    unsigned char gap_3E[2];
    RGE_Player** players;
    short master_player_num;
    unsigned char gap_46[2];
    RGE_Master_Player** master_players;
    RGE_Effects* effects;
    short terrain_num;
    short terrain_size;
    float** terrains;
    void* commands;
    RGE_Scenario* scenario;
    short color_table_num;
    unsigned char gap_62[2];
    RGE_Color_Table** color_tables;
    long next_object_id;
    long next_reusable_object_id;
    long scenario_object_id;
    unsigned char scenario_object_flag;
    unsigned char gap_75[3];
    unsigned int random_seed;
    short curr_player;
    unsigned char gap_7E[2];
    TSound_Driver* sound_driver;
    float world_time_delta_seconds;
    RGE_Static_Object** objectsValue;
};

struct RGE_Tile {
    short screen_xpos;
    short screen_ypos;
    union {
        unsigned char field_4;
        unsigned char tile_type;
    };
    union {
        unsigned char flags;
        unsigned char terrain_type;
        unsigned char terrain_flags;
        unsigned char field_5;
    };
    union {
        unsigned char border_type;
        unsigned char field_6;
    };
    unsigned char last_drawn_as;
    union {
        unsigned char last_drawn_shape;
        unsigned char field_8;
    };
    unsigned char draw_as;
    union {
        unsigned char draw_attribute;
        unsigned char field_A;
    };
    union {
        unsigned char last_drawn_shape2;
        unsigned char field_B;
    };
    union {
        unsigned char pad[0x0C];
        RGE_Object_List* objects;
    };
};

struct RGE_Terrain_Type_Prefix {
    unsigned char gap_000[0xD1];
    unsigned char drawn;
    unsigned char loaded;
    TShape* shape;
    unsigned char gap_0D2[0x72];
    short terrain_to_draw;
    unsigned char gap_146[0x52];
};

struct RGE_TOB_Picts {
    short count;
    short animations;
    short shape_index;
};

typedef struct RGE_Border_Set RGE_Border_Type;

struct RGE_Tile_Set {
    unsigned char loaded;
    unsigned char gap_01[0x1F];
    TShape* shape;
    unsigned char gap_24[0x174];
    unsigned char frame_changed;
    unsigned char drawn;
    short terrain_to_draw;
    RGE_TOB_Picts tiles[19];
    short rows;
    short cols;
};

struct RGE_Border_Set {
    unsigned char loaded;
    unsigned char gap_01[0x1F];
    TShape* shape;
    unsigned char gap_24[0x576];
    unsigned char draw_tile;
    unsigned char gap_59B;
    short underlay_terrain;
    short border_style;
    RGE_TOB_Picts borders[19][12];
};

class RGE_Object_List {
public:
    void draw(TDrawArea* area, short x, short y, int draw_as);
    void shadow_draw(TDrawArea* area, short x, short y,
                     unsigned char draw_as, unsigned char fog);
    void normal_draw(TDrawArea* area, short x, short y,
                     unsigned char draw_as);
    RGE_Object_Node* sort();
};

struct RGE_Object_Node {
    RGE_Static_Object* node;
    RGE_Object_Node* next;
};

struct Ov_Sprite_Draw_Rec {
    Ov_Sprite_Draw_Rec* next;
    Ov_Sprite_Draw_Rec* prev;
    TShape* theShape;
    unsigned long LastDrawTime;
    unsigned long DrawTimeInterval;
    int displayfunction;
    int drawLevel;
    int world_x;
    int world_y;
    int thefacet;
    int shape_draw;
    unsigned char flags;
    unsigned char* colortable;
    int shape_count;
};

struct TileSize {
    short width;
    short height;
    short y_delta;
};

class RGE_Map {
public:
    int map_width;
    int map_height;
    short tile_width;
    short tile_height;
    short tile_half_width;
    short tile_half_height;
    short elev_height;
    RGE_Tile** map_row_offset;
    unsigned char map_visible_flag;
    unsigned char fog_flag;
    short num_terrain;
    TileSize tilesizes[32];
    RGE_Tile_Set terrain_types[32];
    RGE_Border_Set border_types[16];
    void coordinate_map();
    void tile_map_coords(short a, short b, RGE_Tile* tile,
                         float* out_x, float* out_y);
    void paint_terrain(int x, int y, short terrain, short size);
    void paint_elevation(int x, int y, short elevation, short size);
    void paint_cliff(int x, int y, short cliff, short size);
    void paint_terrain(int x, int y, int x2, int y2, int terrain, int size);
    void paint_elevation(int x, int y, int x2, int y2, int elevation, int size);
    void paint_cliff(int x, int y, int x2, int y2, int cliff, int size);
    void request_redraw(int col1, int row1, int col2, int row2,
                       unsigned char flags);
};

extern TMousePointer* MouseSystem;

class RGE_Tile_List {
public:
    int field_4;
    int field_10;
    void get_list_info(int* out1, int* out2);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x1E];
    short master_object_num;
    struct RGE_Master_Static_Object** master_objects;
    char gap_28[0xE0];
    RGE_Color_Table* color_table;
    float view_x;
    float view_y;
    unsigned long mutualExploredMask;
    unsigned long mutualVisibleMask;
    RGE_Visible_Map* visible;
    short id;
    int select_one_object(RGE_Static_Object* object, int mode);
    long rollover_info(long object_id, long* facet, long* text_id);
    RGE_Tile_List tile_list;
    void unselect_object();
    void set_view_loc(float x, float y);
    short map_x;
    short map_y;
    RGE_Static_Object* selected_obj;
};

class RGE_Visible_Map {
public:
    unsigned char get_visible(int x, int y);
};

class RGE_Sprite {
public:
    unsigned char get_lowest_draw_level();
};

class RGE_Active_Sprite_List {
public:
    unsigned char get_lowest_draw_level();
};

class TPanel_Prefix {
public:
    long visible;
    long gdi_enabled;
    long gdi_color;
    void get_rect(RECT* out);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
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
    long rollover;

    RGE_Player* get_player();
    void get_mouse_pos(POINT& point);
    void get_mouse_pos(tagPOINT* point);
    void rollover_info(long object_id, long* facet, long* text_id);
    TShape* get_shape(int shape_id);
    void mouse_off();
    void mouse_on();
};

#define rge_base_game (*(RGE_Base_Game**)0x0062C574)
#define fog_next_shape (*(int*)0x0086BBF0)
#define SDI_Draw_Line (*(int*)0x0086BBE0)

extern int view_debug_redraw_all;
extern int view_debug_ObstructionMap;
extern int view_debug_palette;
extern int frame_count;
extern int tiles_drawn;
extern float flt_5776C0;

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
    unsigned char select_level;
    unsigned char fog_flag;

    unsigned char alignment_box(
        RGE_Game_World* world, float x, float y,
        short& x1, short& y1, short& x2, short& y2,
        short& x3, short& y3, short& x4, short& y4);
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x25];
    unsigned char facet;
    unsigned char selected;
    char gap_36[0x96];
    float x;
    float y;
    unsigned char object_state;
    float world_x;
    float world_y;
    int box_hit_test(short x, short y, short a, short b, short c, short d);
    int hit_test(short x, short y, short a, short b, short c);
    int get_frame(short a, short& b, short c, short d);
    short screen_x_offset;
    short screen_y_offset;
    RGE_Sprite* sprite;
    RGE_Sprite* old_sprite;
    RGE_Active_Sprite_List* sprite_list;
    float teleport(float x, float y, float z);
};

struct RGE_Pick_Info {
    union {
        float x;
        float f0;
    };
    float y;
    short scr_x;
    short scr_y;
    RGE_Static_Object* object;
    void* tile;
};

struct RGE_Pick_Obj_Info {
    int object_id;
    short confidence;
    short draw_level;
    short draw_x;
    short draw_y;
};

extern RGE_Pick_Obj_Info Picked_Objects[];
typedef RGE_Pick_Obj_Info Picked_Info;

struct RGE_SPick_Info {
    int object_id;
    short confidence;
    short draw_level;
    short draw_x;
    short draw_y;
    RGE_SPick_Info* next;
    RGE_SPick_Info* prev;
};

struct Paint_Brush_Pick_Overlay {
    long point_x;
    long point_y;
    RGE_Pick_Info pick_info;
};

union Paint_Brush_Storage {
    tagPOINT point;
    Paint_Brush_Pick_Overlay pick;
};

struct Blit_Queue_Entry {
    RECT src;
    RECT dest;
};

struct DClipInfo_Node {
    char gap_00[0x1C];
    unsigned char Draw_Flag;
    char gap_1D[0x0F];
    int Node_Type;
    int Object_ID;
    short x1;
    short y1;
    short x2;
    short y2;
    short x3;
    short y3;
    short x4;
    short y4;
    DClipInfo_Node* Next;
    DClipInfo_Node* NextOnLevel;
    struct Shape_Info* Shape;
    long Draw_Level;
    long Draw_X;
    long Draw_Y;
    long Draw_Flag_Value;
    long Shape_Base;
    void* Color_Table;
    void* Xform_Mask;
};

struct Shape_Info {
    long Shape_Data_Offsets;
    long Shape_Outline_Offset;
    unsigned char gap_08[8];
    long Width;
    long Height;
    long Hotspot_X;
    long Hotspot_Y;
};

class TSpan_List_Manager {
public:
    char gap_00[0x68];
    TSpan_List_Manager(long width, long height);
    ~TSpan_List_Manager();
    void AddLine_Align(int x1, int y1, int x2, int y2);
    void AddSpan(int left, int right, int line);
    void ResetAll();
    void SetSpanRegions(int left, int top, int right, int bottom);
    void AddMiniList(void* list, int x, int y);
    void SubtractMiniList(void* list, int x, int y);
    void Merge_n_Align(TSpan_List_Manager* a, TSpan_List_Manager* b);
    void AddShape_Align(long shape_base, void* shape, long x, long y,
                        long flag);
    void* Line_Head_Ptrs;
    void* Line_Tail_Ptrs;
    long Min_Span_Px;
    long Max_Span_Px;
    long Min_Line;
    long Max_Line;
};

class DClipInfo_List {
public:
    char gap_00[0x70];
    DClipInfo_List(int, int, int, int, int, int);
    ~DClipInfo_List();
    void SetDrawRegion(int x1, int y1, int x2, int y2);
    void Scroll(int x, int y);
    void ReclaimAllNodes();
    void SetCaptureLevel(int min_level, int max_level);
    DClipInfo_Node* AddGDINode(int, int, int, int, int, int, int,
                               int, int, int, int, int, int);
    DClipInfo_Node* AddGDINode(long, long, long, long, long, long, long,
                               long, long, long, long, long, long, long);
    DClipInfo_Node** Draw_Clip_Nodes;
    DClipInfo_Node** Draw_Level_Head;
    DClipInfo_Node** Draw_Level_Tail;
    long YLine_Size;
    int Free_Pool_Zone;
    int Free_Pool_Index;
    DClipInfo_Node** Zone_Ptrs;
    int* Zone_Size_Ptrs;
    int Max_Zones;
    int Used_Zones;
    DClipInfo_Node* Free_Head;
    int Total_Blocks;
    int Free_Blocks;
    int YLine_Offset;
    int Max_Draw_Levels;
    int Accept_Min_Level;
    int Accept_Max_Level;
    int SD_XMin;
    int SD_XMax;
    int SD_YMin;
    int SD_YMax;
    int Default_Grow_Size;
    int Element_Size;
    int NewZone_Count;
    int Reset_Count;
    int field_2C;
    int field_30;
    int field_34;
    int field_38;
    short* Select_Box;
    void ResetStats();
private:
    void SetNumZones(int num_zones);
    void InitNewZone(int zone_size);
public:
    DClipInfo_Node* GetNode();
    void AddDrawNode(void* shape_base, Shape_Info* shape, int yline,
                     int draw_x, int draw_y, int draw_flag,
                     unsigned char* color_table, int xform_mask,
                     int draw_level, int object_id);
    DClipInfo_Node* LocateIDbyDrawLevel(int object_id, int level_a,
                                        int level_b, int node_type);
    void FreeNode(DClipInfo_Node* node);
    int FreeThread(DClipInfo_Node* head, DClipInfo_Node* tail);
};

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
    union {
        RGE_SPick_Info* pick_lists[5];
        int pick_list_count[5];
    };
    union {
        int pick_list_size[5];
        struct {
            int pick_list_size_0;
            int pick_list_size_1;
            int pick_list_size_2;
            int pick_list_size_3;
            int pick_list_size_4;
        };
    };
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
    union {
        DisplaySelectedObjRec* DispSel_List;
        int* dispSelList;
        void* DispSel_List_void;
    };
    union {
        int DispSel_List_Size;
        int dispSelListSize;
    };
    union {
        int DispSel_List_Max;
        int dispSelListMax;
    };
    Panel_List_Node* panel_list;
    void* some_pick_gate;
    TDrawArea* draw_area;
    TSpan_List_Manager* CurSpanList;
    TSpan_List_Manager* SpanList;
    void* display_info;
    int scroll_min_x;
    int scroll_min_y;
    int scroll_max_x;
    int scroll_max_y;
    int x_min;
    int y_min;
    int x_max;
    int y_max;

    long setup(TDrawArea* draw, TPanel* parent, long x, long y, long w,
               long h, unsigned char flag, int calc_count, char* shape_name);
    void set_rect(long left, long top, long width, long height);
    virtual void set_redraw(TPanel::RedrawMode mode);
    int bound_point(long& x, long& y);
    void set_world(RGE_Game_World* value);
    void set_player(RGE_Player* value);
    void set_selection_area(int col1, int row1, int col2, int row2);
    void set_selection_area(long col1, long row1, long col2, long row2);
    int get_selection_area(long& col1, long& row1, long& col2, long& row2,
                           int normalize);
    void update_display_selected_objects();
    void display_object_selection(int param_1, int param_2, int param_3,
                                  int param_4);
    void redraw(int mode);
    void target08(int value);
    void reset_overlay_sprites();
    int draw(long, long, long, long, int);
    void draw();
    void game_mode_15_hook();
    void reset_cyclic_overlay_sprites();
    long Get_Cursor_Position(POINT* point, long offset_x, long offset_y);
    long pick_touched_object(void* list, long x, long y, long min_level,
                             long max_level, long* object_id);
    void get_string(long id, char* out, long lang_id);
    int Get_Cursor_Position(POINT& point, int offset_x, int offset_y);
    virtual int start_scroll_view(unsigned char action, long x, long y,
                                  int p4, int p5);
    virtual int handle_scroll_view(long x, long y);
    virtual void end_scroll_view();
    virtual int do_paint(long x1, long y1, long x2, long y2, int flag);
    int is_inside(long x, long y);
    int capture_mouse();
    void add_overlay_sprite(TShape* shape, int facet, int world_x, int world_y,
                            int flags, int draw_level, unsigned char* colors,
                            int displayfunction, unsigned long interval);
    bool Object_Was_Displayed(int id, bool allow_flagged);
    int get_game_enable();
    unsigned char pick_multi(unsigned char mode, long x1, long y1,
                             long x2, long y2);
    int pick_through_fog(int value);
    virtual int pick_through_fog(RGE_Static_Object* object);
    virtual int pick_weight(RGE_Static_Object* object, int index);
    unsigned char pick(unsigned char mode, unsigned char param,
                       tagPOINT* first, tagPOINT* second, void** object,
                       float* x, float* y, short* col, short* row);
    unsigned char pick(unsigned char mode, unsigned char parm,
                       long x, long y, RGE_Pick_Info* info,
                       RGE_Static_Object* object);
    int create_surfaces();
    void delete_surfaces();
    void get_center_screen_pos(short* row, short* col);
    void get_start_coords(short* map_col, short* map_row,
                          short* scr_col, short* scr_row);
    void get_center_coords(short* map_col, short* map_row,
                           short* scr_col, short* scr_row);
    void get_tile_sizes(short* width, short* height,
                        short* half_width, short* half_height);
    void get_max_size(short* cols, short* rows);
    virtual void draw_multi_object_outline();
    int get_tile_screen_coords(short col, short row,
                               short* out_x, short* out_y, int adjust);

protected:
    virtual void set_focus(int focus);
    void Init_Tile_Edge_Tables();
    void update();
    void CreateBlitQueue(RECT& src, RECT& dst, int xd, int yd);
    void ProcessQueuedBlit(int force);
    void draw_paint_brush();
    int draw_tile(RGE_Tile* tile, unsigned char terrain_type, short x,
                  short y, short map_x, short map_y,
                  unsigned char draw_attribute, int draw1, int draw2);
    int Pick_Tile(long x, long y, int* col, int* row);
    void get_tile_bounding_coords(int x, int y, int& left, int& top,
                                  int& right, int& bottom);
    int pick_objects(int x, int y, int min_level, int max_level,
                     int radius, int player, int flags);
    int pick_multi_objects(int x1, int y1, int x2, int y2, int min_level,
                           int max_level, int player, unsigned char mode,
                           int flags);
    int pick_touched_object(DClipInfo_List* list, int x, int y,
                            int min_level, int max_level, int& object_id);
    int sprite_check(unsigned char* shape_base, Shape_Info* shape,
                     int x, int y);
    int sprite_check(long shape_base, long shape, int x, int y);
    int sprite_check(long shape_base, Shape_Info* shape, int x, int y);
    void draw_terrain_shape(int x, int y, TShape* shape, int frame,
                            unsigned char visibility,
                            unsigned char draw_attribute, int draw1, int draw2);
    void draw_terrain_obstruction_map(int x, int y, TShape* shape,
                                      int frame, int tile_x, int tile_y);
    void calc_draw_vars();
    void draw_view(unsigned char mode, TDrawArea* area);
    void draw_object_outline();
    long view_function_terrain(unsigned char mode, RECT rect);
    long view_function(unsigned char mode, unsigned char parm, tagPOINT* first,
                       tagPOINT* second, void** object, float* x, float* y,
                       short* col, short* row);
    short get_tile_picture(unsigned char terrain_type, unsigned char tile_type,
                           short x, short y);
    short get_border_picture(unsigned char terrain_type, unsigned char tile_type,
                             unsigned char border_type, short x, short y);
    int get_border_edge_pictures(unsigned char terrain_type,
                                 unsigned char tile_type,
                                 unsigned char border_type, short x, short y,
                                 int* left, int* bottom, int* right,
                                 int* result);
    int get_border_edge_pictures(unsigned char terrain_type,
                                 unsigned char tile_type,
                                 unsigned char border_type, short x, short y,
                                 int& left, int& bottom, int& right,
                                 int& result);
    RGE_Static_Object* hit_object(RGE_Tile* tile, short x, short y,
                                  short a, short b, tagPOINT* first,
                                  tagPOINT* second, short* out_x,
                                  short* out_y, RGE_Static_Object* skip,
                                  unsigned char through_fog);
    int hit_tile(RGE_Tile* tile, short sx, short sy, short a, short b,
                 tagPOINT* point);
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
typedef char view_tu_view_size_check[(sizeof(RGE_View) >= 0x360) ? 1 : -1];
typedef char view_tu_clip_node_size_check[(sizeof(DClipInfo_Node) >= 0x40) ? 1 : -1];
typedef char view_tu_span_manager_size_check[(sizeof(TSpan_List_Manager) >= 0x68) ? 1 : -1];
typedef char view_tu_clip_list_size_check[(sizeof(DClipInfo_List) >= 0x70) ? 1 : -1];

#endif
