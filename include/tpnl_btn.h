#ifndef AOE1_TPNL_BTN_H
#define AOE1_TPNL_BTN_H

// PDB source: C:\\msdev\\work\\age1_x1\\tpnl_btn.cpp.
// TPanel and TButtonPanel stay with their source-module owners.

#include "Pnl_scr.h"
#include "pnl_btn.h"

class TShape;
class TDigital;
class TRIBE_Main_View;
class TRIBE_Panel_Inven;
class TRIBE_Panel_Object;
class TMessagePanel;
class TTextPanel;
class TRIBE_Panel_Time;
class TRIBE_Panel_Pop;
class RGE_Panel_Tool_Box;
class TRIBE_World;
class RGE_Static_Object;
class RGE_Sound;
class RGE_Map;
class Item_Avail;
class Trade_Avail;

class RGE_Diamond_Map : public TPanel {
public:
    RGE_Game_World* world;
    RGE_Player* player;
    RGE_Map* map;
    int all_visible;
    int render_all;
    long mouse_last_x;
    long mouse_last_y;
    int repos_mouse;
    tagRECT view_rect;
    RGE_Player* last_player;
    void* map_image_lines;
    void* map_tile_rows;
    short map_wid;
    short map_hgt;
    short map_image_start_y;
    short map_image_wid;
    short map_image_hgt;
    short map_tile_row_cnt;
    float map_row_step;
    float map_col_ratio;
    float map_row_ratio;
    short map_tile_draw_hgt;
    short map_tile_draw_wid;
    short view_col;
    short view_row;
    void* main_view;
    int scrolling;
    unsigned char fog_color;
    unsigned char pad_159[3];
    int draw_objects_mode;
    unsigned long cur_player_bit;
    int own_save_area;
    TDrawArea* save_area;
};

class RGE_Diamond_Map_View : public RGE_Diamond_Map {
};

class TRIBE_Diamond_Map_View : public RGE_Diamond_Map_View {
public:
    unsigned long last_attack_time;
    int flash_on;
};

class TRIBE_Panel_Button;

class TRIBE_Screen_Game : public TScreenPanel {
public:
    struct Color {
        unsigned char red;
        unsigned char green;
        unsigned char blue;
    };

    struct PortInfo {
        int player;
        int port;
        int money;
        int value;
    };

    TShape* game_screen_pic;
    TShape* button_border1_pic;
    TShape* button_other_pic;
    TShape* button_border2_pic;
    TShape* button_border3_pic;
    TShape* button_cmd_pic;
    TShape* button_tech_pic;
    TShape* button_unit_pic;
    TShape* button_bldg_pics[5];
    TShape* more_cancel_pic;
    short more_frame;
    short cancel_frame;
    short unselect_frame;
    unsigned char pad_4b6[2];
    TRIBE_Main_View* main_view;
    TRIBE_Diamond_Map_View* map_view;
    TRIBE_Panel_Inven* inven_panel;
    TRIBE_Panel_Object* object_panel;
    TRIBE_Panel_Button* button_panel[17];
    TMessagePanel* text_line_panel;
    TTextPanel* quit_message_panel;
    TRIBE_Panel_Time* time_panel;
    TRIBE_Panel_Time* countdown_clock[10];
    TRIBE_Panel_Pop* pop_panel;
    TMessagePanel* message_panel[6];
    TMessagePanel* chat_panel[8];
    RGE_Panel_Tool_Box* tool_box;
    TTextPanel* age_panel;
    TTextPanel* pause_text;
    TTextPanel* fps_panel;
    TMessagePanel* score_panel[8];
    TTextPanel* log_text;
    void* log_scrollbar;
    TRIBE_World* world;
    unsigned long update_interval;
    unsigned long last_update_time;
    unsigned long map_redraw_interval;
    unsigned long last_map_redraw_time;
    RGE_Static_Object* game_obj;
    short sel_count;
    unsigned char pad_5ce[2];
    Item_Avail* tech_list;
    Item_Avail* make_list;
    Item_Avail* bldg_list;
    Trade_Avail* trade_list;
    short item_cnt;
    short start_item;
    short last_item;
    unsigned char pad_5e6[2];
    PortInfo port_info[9];
    unsigned long terrain_sound_interval;
    unsigned long last_terrain_sound_time;
    RGE_Sound* terrain_sound;
    int terrain_playing;
    unsigned long terrain_sound_start_time;
    int anim_pal;
    unsigned long anim_pal_interval;
    unsigned long last_anim_pal_time;
    short last_anim_pal_index;
    short last_anim_pal_index2;
    short last_anim_pal_index3;
    Color anim_pal_table[7];
    Color anim_pal_table2[16];
    Color anim_pal_table3[12];
    unsigned char pad_707;
    long mouse_last_x;
    long mouse_last_y;
    int save_age;
    int save_culture;
    long save_screen_width;
    unsigned long game_over_time;
    int showing_game_over;
    int chat_line;
    unsigned long view_interval;
    unsigned long last_view_time;
    int player_quit;
    long cheat_code_entry;
    char cheat_code_entry_str[52];
    long view_town_center_hotkey;
    long work_hotkey;
    long move_hotkey;
    long attack_hotkey;
    long ungroup_hotkey;
    long watch_hotkey;
    long select_building_hotkey[8];
    int reset_after_update;
    unsigned long score_interval;
    unsigned long last_score_time;
    int watch_mode;
    int game_ended;
    TDigital* game_over_sound;
    unsigned long last_game_speed_change;
    unsigned long last_pause_change;
};

typedef char tpnl_btn_screen_game_size_check[
    (sizeof(TRIBE_Screen_Game) == 0x7C4) ? 1 : -1];

class TRIBE_Panel_Button : public TButtonPanel {
public:
    int display_garrison;
    int garrsion_number;
    unsigned char tribe_button_type;
    unsigned char pad_2c1[3];
    TShape* border_pic;
    unsigned char* color_table;
    int border_frame;
    char text_msg[0x100];
    int in_use;

    TRIBE_Panel_Button(TDrawArea*, TPanel*, TDigital*, void*, long, long,
                       TShape*);
    virtual ~TRIBE_Panel_Button();
    virtual void draw();
    void set_text_msg(char*);
    virtual int is_inside(long, long);
    void set_display_garrison(int);
    void set_garrison_number(int);
    int get_garrison_number();
};

typedef char tpnl_btn_button_size_check[
    (sizeof(TRIBE_Panel_Button) == 0x3D4) ? 1 : -1];

#endif
