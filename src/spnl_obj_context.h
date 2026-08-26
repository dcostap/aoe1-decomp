#ifndef SPNL_OBJ_CONTEXT_H
#define SPNL_OBJ_CONTEXT_H

#include "../include/game_globals.h"
#include <windows.h>
#include <stdio.h>
#include <string.h>

typedef unsigned char uchar;
typedef unsigned long ulong;

extern "C" {
__declspec(dllimport) HGDIOBJ __stdcall SelectObject(HDC, HGDIOBJ);
__declspec(dllimport) int __stdcall SetBkMode(HDC, int);
__declspec(dllimport) COLORREF __stdcall SetTextColor(HDC, COLORREF);
__declspec(dllimport) int __stdcall SelectClipRgn(HDC, HRGN);
__declspec(dllimport) BOOL __stdcall TextOutA(HDC, int, int, LPCSTR, int);
}

extern "C" void __cdecl _ASMSet_Color_Xform(int);

class TShape;
class TDrawArea;
class RGE_Color_Table;
class RGE_Sprite;
class RGE_Player;
class TRIBE_Player;
class RGE_Master_Static_Object;
class RGE_Master_Combat_Object;

class TDrawArea {
public:
    char gap_00[0x38];
    HDC DrawDc;

    void Clear(void* rect, int color);
    uchar* Lock(char* name, int flag);
    void Unlock(char* name);
    void* GetDc(char* name);
    void ReleaseDc(char* name);
};

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, uchar);
    virtual void set_rect(RECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(uchar);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long, long,
                                 long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, int);
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(RECT*);
    virtual void draw_offset(long, long, RECT*);
    virtual void draw_rect2(RECT*);
    virtual void draw_offset2(long, long, RECT*);
    virtual void paint();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual long handle_idle();
    virtual long handle_size(long, long);
    virtual long handle_paint();
    virtual long handle_key_down(long, short, int, int, int);
    virtual long handle_char(long, short);
    virtual long handle_command(unsigned int, long);
    virtual long handle_user_command(unsigned int, long);
    virtual long handle_timer_command(unsigned int, long);
    virtual long handle_scroll(long, long);
    virtual long handle_mouse_down(uchar, long, long, int, int);
    virtual long handle_mouse_move(long, long, int, int);
    virtual long handle_mouse_up(uchar, long, long, int, int);
    virtual long handle_mouse_dbl_click(uchar, long, long, int, int);
    virtual long mouse_move_action(long, long, int, int);
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long mouse_left_hold_action(long, long, int, int);
    virtual long mouse_left_move_action(long, long, int, int);
    virtual long mouse_left_up_action(long, long, int, int);
    virtual long mouse_left_dbl_click_action(long, long, int, int);
    virtual long mouse_right_down_action(long, long, int, int);
    virtual long mouse_right_hold_action(long, long, int, int);
    virtual long mouse_right_move_action(long, long, int, int);
    virtual long mouse_right_up_action(long, long, int, int);
    virtual long mouse_right_dbl_click_action(long, long, int, int);
    virtual long key_down_action(long, short, int, int, int);
    virtual long char_action(long, short);
    virtual long action(TPanel*, long, ulong, ulong);
    virtual void get_true_render_rect(RECT*);
    virtual int is_inside(long, long);
    virtual void set_focus(int);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual void set_tab_order(TPanel**, short);
    virtual uchar get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();

    void release_mouse();

    TPanel* previous_panel;
    TPanel* previous_modal_panel;
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char* panel_name;
    TDrawArea* render_area;
    RECT clip_rect;
    int position_mode;
    int need_redraw;
    TPanel* curr_child;
    TPanel* parent_panel;
    TPanel* left_panel;
    TPanel* top_panel;
    TPanel* right_panel;
    TPanel* bottom_panel;
    void* node;
    void* first_child_node;
    void* last_child_node;
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
    union {
        HRGN clip_rgn;
        HRGN clip_region;
    };
    RECT render_rect;
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
    ulong mouse_down_time;
    int error_code;
    int z_order;
    int display_changed_count;
    long help_string_id;
    long help_page_id;
    uchar mouse_action;
    uchar mouse_down_button;
    uchar panel_type;
    uchar color;
    uchar fill_in_background;
    uchar clip_to_parent;
    uchar draw_rect2_flag;
    uchar need_restore;
};

class RGE_Color_Table {
public:
    virtual ~RGE_Color_Table();
    char color_table_name[30];
    short resource_id;
    uchar type;
    uchar map_color;
    short id;
    uchar table[0x100];
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x44];
    uchar type;
    uchar gap_49;
    short id;
    char gap_4C[8];
    uchar culture_id;
    char gap_55[0xB3];
    RGE_Color_Table* color_table;
};

class TRIBE_Player : public RGE_Player {
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    uchar master_type;
    uchar gap_05[3];
    char* name;
    short string_id;
    short string_id2;
    short id;
    short copy_id;
    short object_group;
    uchar gap_16[2];
    RGE_Sprite* sprite;
    RGE_Sprite* death_sprite;
    RGE_Sprite* undead_sprite;
    uchar undead_flag;
    uchar gap_25;
    short hp;
    float los;
    uchar obj_max;
    uchar gap_2D[3];
    float radius_x;
    float radius_y;
    float radius_z;
    void* selected_sound;
    void* created_sound;
    void* death_sound;
    short death_spawn_obj_id;
    uchar sort_number;
    uchar can_be_built_on;
    short button_pict;
    uchar hide_in_scenario_editor;
    uchar gap_4F;
    short portrait_pict;
    uchar available;
    uchar gap_53;
    short tile_req1;
    short tile_req2;
    short center_tile_req1;
    short center_tile_req2;
    float construction_radius_x;
    float construction_radius_y;
    uchar elevation_flag;
    uchar fog_flag;
    short terrain;
    uchar movement_type;
    uchar gap_69;
    short attribute_type_held[3];
    float attribute_amount_held[3];
    short attribute_max_amount;
    uchar gap_7E[2];
    float attribute_rot;
    float multiple_attribute_mod;
    uchar attribute_flag[3];
    uchar area_effect_object_level;
    uchar combat_level;
    uchar select_level;
    uchar map_draw_level;
    uchar unit_level;
    uchar map_color;
    uchar attack_reaction;
    uchar convert_terrain_flag;
    uchar damage_sprite_num;
    void* damage_sprites;
    long help_string_id;
    long help_page_id;
    long hotkey_id;
    uchar recyclable;
    uchar track_as_resource;
    uchar create_doppleganger_on_death;
    uchar resource_group;
    uchar draw_flag;
    uchar draw_color;
    uchar gap_AA[2];
    float outline_radius_x;
    float outline_radius_y;
    float outline_radius_z;
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    float speed;
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    RGE_Sprite* move_sprite;
    RGE_Sprite* run_sprite;
    float turn_speed;
    uchar size_class;
    uchar gap_C9;
    short obj_trail_id;
    uchar obj_trail_options;
    uchar gap_CD[3];
    float obj_trail_spacing;
    uchar move_algorithm;
    uchar gap_D5[3];
};

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    void* tasks;
    short default_task;
    uchar gap_DE[2];
    float search_radius;
    float work_rate;
    short drop_site;
    short backup_drop_site;
    uchar task_by_group;
    uchar gap_ED[3];
    void* command_sound;
    void* move_sound;
    uchar run_pattern;
    uchar gap_F9[3];
};

class RGE_Master_Combat_Object : public RGE_Master_Action_Object {
public:
    RGE_Sprite* fight_sprite;
    uchar base_armor;
    uchar gap_101;
    short armor_num;
    void* armor;
    short weapon_num;
    uchar gap_10A[2];
    void* weapon;
    short defense_terrain_bonus;
    uchar gap_112[2];
    float weapon_range;
    float area_effect_range;
    uchar area_effect_level;
    uchar gap_11D[3];
    float speed_of_attack;
    short missile_id;
    short base_hit_chance;
    uchar break_off_combat;
    uchar gap_129;
    short fire_missile_at_frame;
    float weapon_offset_x;
    float weapon_offset_y;
    float weapon_offset_z;
    float minimum_weapon_range;
    short orig_armor;
    short orig_weapon;
    float orig_weapon_range;
    float orig_speed_of_attack;
};

class TRIBE_Master_Building_Object : public RGE_Master_Combat_Object {
public:
    uchar gap_148[0x26];
    short building_facet;
};

class RGE_Sprite {
public:
    char pict_name[13];
    uchar gap_0D[3];
    long resource_id;
    uchar loaded;
    uchar gap_15[3];
    RGE_Color_Table** color_tables;
    TShape* shape;
    long last_time;
    long delta_time;
    uchar color_flag;
    uchar draw_level;
    short color_table;
    uchar transparent_picking_flag;
    uchar gap_2D;
    short box_x1;
    short box_y1;
    short box_x2;
    short box_y2;
    short draw_list_num;
    void* draw_list;
    void* main_sound;
    uchar micro_man_sound;
    uchar gap_43[3];
    void* sound_list;
    char name[21];
    uchar gap_5D;
    short frame_num;
    short facet_num;
    uchar gap_62[2];
    float base_speed;
    float duration;
    float pause_between_loops;
    uchar flag;
    uchar gap_71;
    short id;
    uchar mirror_flag;
    uchar gap_75[3];

    int get_size(long& min_x, long& min_y, long& max_x, long& max_y, long facet);
    void do_draw(long x, long y, long frame, long shade,
                 RGE_Color_Table* color_table, TDrawArea* draw_area,
                 uchar color_index);
};

class TShape {
public:
    uchar shape_draw(TDrawArea*, long, long, long, uchar, uchar*);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual void v4();
    virtual void v8();
    virtual void vC();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual char* get_string(long id, char* buffer, int length);
    virtual void v24();
    virtual char* get_string2(int id, long arg2, long arg3,
                              char* buffer, int length);

    char gap_04[0x1AC];
    volatile int field_1B0;

};

extern RGE_Base_Game* rge_base_game;
extern char format_decimal[];
extern char format_bonus[];
extern char format_ratio[];
extern char format_signed[];
#define DEFAULT_PLAYER_NAME ((char*)0x0057F074)
#define REPLACEMENT_PLAYER_NAME ((char*)0x005870B4)
#define FORMAT_STRING ((char*)0x0057F324)
#define FORMAT_RATIO ((char*)0x005870AC)

class TRIBE_Panel_Object : public TPanel {
public:
    enum ValueType {
        ValueTypeNumber = 0,
        ValueTypeBonus = 1,
        ValueTypeCompare = 2,
        ValueTypePercent = 3,
        ValueTypeNone = 4
    };

    TRIBE_Panel_Object(TDrawArea*, TPanel*, void*, long, long, TShape*, TShape**, TRIBE_Player*);

protected:
    virtual void draw_item(int, int, ValueType, int, int);

    void* font;
    long font_wid;
    long font_hgt;
    TShape* health_pic;
    TShape* item_pic;
    TShape* unit_pics;
    TShape** bldg_pics;
    TRIBE_Player* player;
    uchar gap_114[0x0C];
    uchar mode;
    uchar gap_121[0xF3];

    void draw_score();
};

class TRIBE_Scenario_Editor_Panel_Object : public TRIBE_Panel_Object {
public:
    virtual ~TRIBE_Scenario_Editor_Panel_Object();
    TRIBE_Scenario_Editor_Panel_Object(TDrawArea*, TPanel*, void*, long, long,
                                       TShape*, TShape**, TRIBE_Player*);
    virtual void draw();
    virtual void draw_item(int, int, ValueType, int, int);
    virtual long mouse_left_up_action(long, long, int, int);

    void set_master_info(RGE_Master_Static_Object*, TRIBE_Player*);
    long get_pierce_armor();

    RGE_Master_Static_Object* master_game_obj;
    int master_culture_id;
};

#endif
