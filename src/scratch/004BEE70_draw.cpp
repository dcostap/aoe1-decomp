// TRIBE_Scenario_Editor_Panel_Object::draw
// VA: 004BEE70
// PDB: spnl_obj.cpp:78-325
//
// Attempt log:
// - Typed reconstruction has exact size/frame parity and 41/41 ordered calls.
// - BINARY NOTE: building_facet is at master-object +0x16E after a +0x148 base.
// - BINARY NOTE: level-2 range reads +0x114; the final level-4/6 conversion reads
//   +0x140. These are not the nearby cached fields with similar names.
// - BINARY NOTE: the attribute scan loads each float before comparing DAT_00574524.
// - Current clean result: 1577 bytes, 41 calls, 120 differing bytes (7.61%).
// - Natural shape progress: while scan, positive string guard, direct master
//   rereads after calls, and pre-guard armor load recover exact blocks.
// - The level-2 path rereads master_game_obj after each draw_item call. This
//   restores the executable's external-mutation behavior and tail registers.
// - The level-1 draw passes the selected icon as argument two. It passes the
//   converted amount as argument four and zero as argument five.
// - Remaining body drift starts at the get_pierce_armor result schedule. The
//   rebuilt tail is two bytes shorter before final context filler.
// - The local blocker is the get_pierce_armor result schedule. The executable
//   reloads master_game_obj into ECX before it copies EAX to EDI. The rebuild
//   copies EAX first and then reloads the member through EAX.
// - The direct speed expression restores ftol before pierce-value extension.
//   The final draw still uses different EAX, ECX, and EDX colors.
// - BINARY NOTE: cases 0, 15, 16, and 17 have separate equal assignments.
//   VC5 then emits the original eight-entry jump table at 004BF49C. Stacked
//   labels emit only six entries and place the byte table at the wrong offset.
// - PDB type data proves TRIBE_Player ownership at +0x110 and the nested
//   TRIBE_Panel_Object::ValueType parameter for draw_item.
// - An authentic constructor/destructor/set_master_info prefix changed zero
//   target bytes. The shortest complete spnl_obj.cpp prefix is not the cause.
// - Local width, scope, declaration order, receiver, guard, comma-expression,
//   register, include-order, scalar-type, and supported flag probes did not
//   recover the remaining schedule. See target-session probes 92-111.
// - Exact-finish audit: the direct speed member expression restores the
//   executable's ftol-before-pierce order and two exact tail blocks. Keep it.
// - BINARY NOTE: the attribute switch references 004BF49C and 004BF4BC,
//   after the 004BF498 draw boundary and the reviewed 004BF499 padding anchor.
// - No inline assembly, fake vtable, or compiler-only source remains.
// - Behavior correction: the first TextOutA call draws the player name at
//   pnl_y. The prior source incorrectly added 0x0F to that call.
// - This claim ran 20 meaningful probes. Rejected probes restored the clean
//   source. See target-session history for the complete variant families.
// - Accepted-drift audit: do not promote. The remaining drift is the local
//   switch relocation pair, the first guard's register basin, and tail colors.

#include "../../include/game_globals.h"
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

    TPanel* previous_panel;             // +0x04
    TPanel* previous_modal_panel;       // +0x08
    long pnl_x;                         // +0x0C
    long pnl_y;                         // +0x10
    long pnl_wid;                       // +0x14
    long pnl_hgt;                       // +0x18
    char* panel_name;                   // +0x1C
    TDrawArea* render_area;             // +0x20
    RECT clip_rect;                     // +0x24
    int position_mode;                  // +0x34
    int need_redraw;                    // +0x38
    TPanel* curr_child;                 // +0x3C
    TPanel* parent_panel;               // +0x40
    TPanel* left_panel;                 // +0x44
    TPanel* top_panel;                  // +0x48
    TPanel* right_panel;                // +0x4C
    TPanel* bottom_panel;               // +0x50
    void* node;                         // +0x54
    void* first_child_node;             // +0x58
    void* last_child_node;              // +0x5C
    TPanel* tab_prev_panel;             // +0x60
    TPanel* tab_next_panel;             // +0x64
    int mouse_captured;                 // +0x68
    int active;                         // +0x6C
    int visible;                        // +0x70
    int tab_stop;                       // +0x74
    int have_focus;                     // +0x78
    int overlapping_children;           // +0x7C
    int handle_mouse_input;             // +0x80
    int just_drawn;                     // +0x84
    HRGN clip_rgn;                      // +0x88
    RECT render_rect;                   // +0x8C
    long left_border;                   // +0x9C
    long top_border;                    // +0xA0
    long right_border;                  // +0xA4
    long bottom_border;                // +0xA8
    long min_wid;                       // +0xAC
    long max_wid;                       // +0xB0
    long min_hgt;                       // +0xB4
    long max_hgt;                       // +0xB8
    long mouse_hold_interval;           // +0xBC
    long mouse_move_tolerance;          // +0xC0
    long mouse_down_x;                  // +0xC4
    long mouse_down_y;                  // +0xC8
    int mouse_down_ctrl;                // +0xCC
    int mouse_down_shift;               // +0xD0
    ulong mouse_down_time;              // +0xD4
    int error_code;                     // +0xD8
    int z_order;                        // +0xDC
    int display_changed_count;          // +0xE0
    long help_string_id;                // +0xE4
    long help_page_id;                  // +0xE8
    uchar mouse_action;                 // +0xEC
    uchar mouse_down_button;            // +0xED
    uchar panel_type;                   // +0xEE
    uchar color;                        // +0xEF
    uchar fill_in_background;           // +0xF0
    uchar clip_to_parent;               // +0xF1
    uchar draw_rect2_flag;              // +0xF2
    uchar need_restore;                 // +0xF3
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
    uchar type;                          // +0x48
    uchar gap_49;
    short id;                            // +0x4A
    char gap_4C[0xBC];
    RGE_Color_Table* color_table;        // +0x108
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
    // The base ends at +0x148; the building facet is at +0x16E.
    uchar gap_148[0x26];
    short building_facet;                // +0x16E
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
    virtual void vf20(long id, char* buffer, int length);
    virtual void v24();
    virtual void vf28(long id, long arg2, long arg3, char* buffer, int length);

    void get_string(long id, char* buffer, int length) {
        this->vf20(id, buffer, length);
    }
    void get_string(long id, long arg2, long arg3,
                    char* buffer, int length) {
        this->vf28(id, arg2, arg3, buffer, length);
    }
};

extern RGE_Base_Game* rge_base_game;
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

protected:
    virtual void draw_item(int, int, ValueType, int, int);

    void* font;                         // +0xF4
    long font_wid;                      // +0xF8
    long font_hgt;                      // +0xFC
    TShape* health_pic;                 // +0x100
    TShape* item_pic;                   // +0x104
    TShape* unit_pics;                  // +0x108
    TShape** bldg_pics;                 // +0x10C
    TRIBE_Player* player;               // +0x110
    uchar gap_114[0x0C];                // +0x114..+0x11F
    uchar mode;                         // +0x120
    uchar gap_121[0xF3];                // +0x121..+0x213

    void draw_score();
};

class TRIBE_Scenario_Editor_Panel_Object : public TRIBE_Panel_Object {
public:
    virtual void draw();
    virtual void draw_item(int, int, ValueType, int, int);

    RGE_Master_Static_Object* master_game_obj; // +0x214
    int master_culture_id;                     // +0x218

    long get_pierce_armor();
};

void TRIBE_Scenario_Editor_Panel_Object::draw()
{
    int text_flag;
    long min_x;
    long min_y;
    long max_y;
    long max_x;
    char name[100];
    char str[100];

    if (this->render_area == 0 || this->visible == 0 || this->active == 0) {
        this->need_redraw = 0;
        return;
    }

    if (this->mode == 2) {
        this->draw_score();
        return;
    }

    if (this->master_game_obj == 0) {
        if (this->parent_panel != 0) {
            this->parent_panel->draw_rect(&this->clip_rect);
            this->need_redraw = 0;
            return;
        }
        this->need_redraw = 0;
        return;
    }

    this->draw_setup(0);
    this->render_area->Clear(&this->clip_rect, 0);

    if (this->render_area->Lock(0, 1) != 0) {
        text_flag = 1;
        short button_pict = this->master_game_obj->button_pict;

        if (button_pict != -1) {
            TShape* shape;
            if (this->master_game_obj->unit_level == 2) {
                shape = this->bldg_pics[this->master_culture_id];
                button_pict +=
                    ((TRIBE_Master_Building_Object*)this->master_game_obj)->building_facet;
            } else {
                shape = this->unit_pics;
            }

            TShape* uncolored_shape;
            TShape* colored_shape;
            if (this->player != 0 && this->player->color_table->table != 0) {
                _ASMSet_Color_Xform(
                    (this->player->color_table->id + 1) * 0x10);
                colored_shape = shape;
                colored_shape->shape_draw(this->render_area,
                                          this->pnl_x + 2,
                                          this->pnl_y + 0x21,
                                          button_pict, 1,
                                          this->player->color_table->table);
            } else {
                uncolored_shape = shape;
                uncolored_shape->shape_draw(this->render_area,
                                            this->pnl_x + 2,
                                            this->pnl_y + 0x21,
                                            button_pict, 0, 0);
            }
        } else if (this->master_game_obj->sprite != 0) {
            text_flag = 0;
            if (this->master_game_obj->sprite->get_size(min_x, min_y, max_x, max_y, 0) != 0) {
                this->master_game_obj->sprite->do_draw(
                    0, 0,
                    (this->pnl_x - min_x) + 10,
                    (this->pnl_y - min_y) + 0x28,
                    this->player->color_table,
                    this->render_area, 0);
            }
        }

        this->render_area->Unlock(0);
    }

    if (this->render_area->GetDc(0)) {
        SetBkMode(this->render_area->DrawDc, 1);
        SetTextColor(this->render_area->DrawDc, 0xFFFFFF);
        SelectClipRgn(this->render_area->DrawDc, this->clip_rgn);
        void* old_font =
            SelectObject(this->render_area->DrawDc, (HGDIOBJ)this->font);

        if (this->player != 0) {
            rge_base_game->get_string(0x69, this->player->id, 0, name, 100);
            if (strcmp(name, DEFAULT_PLAYER_NAME) == 0) {
                strcpy(name, REPLACEMENT_PLAYER_NAME);
            }
            TextOutA(this->render_area->DrawDc,
                     this->pnl_x + 2, this->pnl_y,
                     name, strlen(name));
        }

        short string_id = this->master_game_obj->string_id;
        if (string_id > 0) {
            rge_base_game->get_string((long)string_id, str, 100);
        } else {
            str[0] = 0;
        }
        if (str[0] == 0) {
            strcpy(str, this->master_game_obj->name);
        }
        sprintf(name, FORMAT_STRING, str);
        TextOutA(this->render_area->DrawDc,
                 this->pnl_x + 2, this->pnl_y + 0x0F,
                 name, strlen(name));

        if (text_flag != 0) {
            sprintf(str, FORMAT_RATIO,
                    (int)this->master_game_obj->hp,
                    (int)this->master_game_obj->hp);
            TextOutA(this->render_area->DrawDc,
                     this->pnl_x + 5, this->pnl_y + 0x55,
                     str, strlen(str));
            SelectObject(this->render_area->DrawDc, (HGDIOBJ)old_font);
            SelectClipRgn(this->render_area->DrawDc, 0);
        }

        this->render_area->ReleaseDc(0);
    }

    if (text_flag == 0) {
        goto draw_finish;
    }

    {
        RGE_Master_Static_Object* master = this->master_game_obj;
        int item_index = 0;
        uchar unit_level = master->unit_level;

        if (unit_level == 3) {
            short amount = ((RGE_Master_Combat_Object*)master)->orig_weapon;
            this->draw_item(0, 7, ValueTypeBonus, amount, amount);
            item_index = 1;
        } else {
            if (unit_level != 9 && unit_level != 4 && unit_level != 5 &&
                unit_level != 6 && unit_level != 7) {
                if (unit_level == 1) {
                    short attr_type = -1;
                    int attr_index = 0;
                    float* attr_amount = master->attribute_amount_held;
                    while (attr_index < 3) {
                        if (*attr_amount > DAT_00574524) {
                            attr_type = master->attribute_type_held[attr_index];
                            break;
                        }
                        ++attr_index;
                        ++attr_amount;
                    }

                    int value_type;
                    switch (attr_type) {
                    case 0:
                        value_type = 2;
                        break;
                    case 0x0F:
                        value_type = 2;
                        break;
                    case 0x10:
                        value_type = 2;
                        break;
                    case 0x11:
                        value_type = 2;
                        break;
                    case 1:
                        value_type = 0;
                        break;
                    case 2:
                        value_type = 1;
                        break;
                    case 3:
                        value_type = 3;
                        break;
                    default:
                        goto draw_finish;
                    }

                    this->draw_item(
                        0, value_type, ValueTypeNumber,
                        (int)master->attribute_amount_held[attr_index], 0);
                    this->draw_finish();
                    return;
                }

                if (unit_level == 2) {
                    this->draw_item(
                        0, 7, ValueTypeBonus,
                        ((RGE_Master_Combat_Object*)master)->orig_weapon,
                        ((RGE_Master_Combat_Object*)master)->orig_weapon);
                    this->draw_item(
                        1, 8, ValueTypeBonus,
                        ((RGE_Master_Combat_Object*)this->master_game_obj)->orig_armor,
                        ((RGE_Master_Combat_Object*)this->master_game_obj)->orig_armor);
                    this->draw_item(2, 6, ValueTypeBonus,
                                    (int)((RGE_Master_Combat_Object*)this->master_game_obj)->weapon_range,
                                    (int)((RGE_Master_Combat_Object*)this->master_game_obj)->weapon_range);
                    this->draw_finish();
                    return;
                }

                goto draw_finish;
            }

            if (master->unit_level == 3 || master->unit_level == 4) {
                short amount = ((RGE_Master_Combat_Object*)master)->orig_weapon;
                this->draw_item(0, 7, ValueTypeBonus, amount, amount);
                item_index = 1;
            }
        }

        RGE_Master_Combat_Object* combat =
            (RGE_Master_Combat_Object*)this->master_game_obj;
        short armor_value = combat->orig_armor;
        if (this->master_game_obj->unit_level == 4 ||
            this->master_game_obj->unit_level == 6) {
            this->draw_item(item_index, 8, ValueTypeBonus,
                            armor_value, armor_value);
            ++item_index;
        }

        long pierce_armor = this->get_pierce_armor();
        short pierce_value = (short)pierce_armor;
        if (this->master_game_obj->unit_level == 4 ||
            this->master_game_obj->unit_level == 6) {
            this->draw_item(item_index, 10, ValueTypeBonus,
                            pierce_value, pierce_value);
            ++item_index;
        }

        if (this->master_game_obj->unit_level == 4 ||
            this->master_game_obj->unit_level == 6) {
            short speed_value = (short)((RGE_Master_Combat_Object*)this->master_game_obj)->orig_weapon_range;
            this->draw_item(item_index, 6, ValueTypeBonus,
                            speed_value, pierce_value);
        }
    }

draw_finish:
    this->draw_finish();
}
