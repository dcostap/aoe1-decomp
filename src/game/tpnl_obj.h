#pragma once
#include "../common.h"

enum ActionType : unsigned int {
    ActionObjectChanged = 1,
};

enum ValueType : unsigned int {
    ValueTypeNumber = 0,
    ValueTypeBonus = 1,
    ValueTypeCompare = 2,
    ValueTypePercent = 3,
    ValueTypeNone = 4,
};

class TRIBE_Panel_Object : public TPanel       {
public:
    char _pad_0x4[0xF0];
    void* font;                              // 0xF4
    long font_wid;                           // 0xF8
    long font_hgt;                           // 0xFC
    TShape* health_pic;                      // 0x100
    TShape* item_pic;                        // 0x104
    TShape* unit_pics;                       // 0x108
    TShape** bldg_pics;                      // 0x10C
    TRIBE_Player* player;                    // 0x110
    RGE_Static_Object* game_obj;             // 0x114
    ulong idle_time;                         // 0x118
    ulong idle_interval;                     // 0x11C
    uchar mode;                              // 0x120
    RGE_Master_Static_Object* save_obj_type; // 0x124
    RGE_Sprite* save_sprite;                 // 0x128
    short save_attr_type;                    // 0x12C
    float save_attr_amount;                  // 0x130
    uchar save_object_state;                 // 0x134
    float save_build_pts;                    // 0x138
    RGE_Object_Node* save_list;              // 0x13C
    short save_number_of_objects;            // 0x140
    uchar save_can_debark;                   // 0x142
    float save_world_x;                      // 0x144
    float save_world_y;                      // 0x148
    float save_hp;                           // 0x14C
    short save_armor;                        // 0x150
    short save_pierce_armor;                 // 0x152
    short save_weapon;                       // 0x154
    float save_weapon_range;                 // 0x158
    float save_speed_of_attack;              // 0x15C
    short save_work_type;                    // 0x160
    short save_work_target;                  // 0x162
    short save_progress;                     // 0x164
    char save_name[100];                     // 0x166
    uchar save_facet;                        // 0x1CA
    float save_angle;                        // 0x1CC
    float save_los;                          // 0x1D0
    int save_pop;                            // 0x1D4
    int save_max_pop;                        // 0x1D8
    uchar save_selected_group;               // 0x1DC
    RGE_Player* save_owner;                  // 0x1E0
    int save_age;                            // 0x1E4
    uchar save_have_action;                  // 0x1E8
    int save_score[9];                       // 0x1EC
    int save_farm_amt;                       // 0x210

    TRIBE_Panel_Object(TDrawArea* param_1, TPanel* param_2, void* param_3, long param_4, long param_5, TShape* param_6, TShape** param_7, TRIBE_Player* param_8);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~TRIBE_Panel_Object() noexcept(false); // Ghidra: `scalar_deleting_destructor'

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 02] Offset 0x08 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 03] Offset 0x0C WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 04] Offset 0x10 WARNING: Function body missing in analysis
    // virtual void set_color();

    // [Slot 05] Offset 0x14 WARNING: Function body missing in analysis
    // virtual void set_active();

    // [Slot 06] Offset 0x18 WARNING: Function body missing in analysis
    // virtual void set_positioning();

    // [Slot 07] Offset 0x1C WARNING: Function body missing in analysis
    // virtual void set_fixed_position();

    // [Slot 08] Offset 0x20 WARNING: Function body missing in analysis
    // virtual void set_redraw();

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

    // [Slot 19] Offset 0x4C (Override)
    virtual long handle_idle(); // Ghidra: handle_idle

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

    // [Slot 33] Offset 0x84 (Override)
    virtual long mouse_left_down_action(long param_1, long param_2, int param_3, int param_4); // Ghidra: mouse_left_down_action

    // [Slot 34] Offset 0x88 WARNING: Function body missing in analysis
    // virtual void mouse_left_hold_action();

    // [Slot 35] Offset 0x8C WARNING: Function body missing in analysis
    // virtual void mouse_left_move_action();

    // [Slot 36] Offset 0x90 (Override)
    virtual long mouse_left_up_action(long param_1, long param_2, int param_3, int param_4); // Ghidra: mouse_left_up_action

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

    // [Slot 48] Offset 0xC0 WARNING: Function body missing in analysis
    // virtual void set_focus();

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
    virtual void draw_item(int param_1, int param_2, ValueType param_3, int param_4, int param_5); // Ghidra: draw_item

    // --- Non-Virtual Members ---
    void set_player(TRIBE_Player* param_1);
    void set_object(RGE_Static_Object* param_1);
    void set_mode(uchar param_1);
    uchar get_mode();
    void draw_score();
    void save_object_info();
};

static_assert(sizeof(TRIBE_Panel_Object) == 0x214, "TRIBE_Panel_Object Size Mismatch");
static_assert(offsetof(TRIBE_Panel_Object, save_farm_amt) == 0x210, "TRIBE_Panel_Object Offset Mismatch");

