#pragma once
#include "../common.h"
#include "Pnl_scr.h"
#include "Pnl_msg.h"

class TRIBE_Main_View;
class TRIBE_Diamond_Map_View;
class TRIBE_Panel_Inven;
class TRIBE_Panel_Object;
class TRIBE_Panel_Button;
class TTextPanel;
class TRIBE_Panel_Time;
class TRIBE_Panel_Pop;
class RGE_Panel_Tool_Box;
class TScrollBarPanel;
class TRIBE_World;

// Guess based on offsets of _unnamed properties 
#pragma pack(push, 1)

// 16 bytes each
struct PortInfo {          // portrait / selection slot
    uint32_t a;
    uint32_t b;
    uint32_t c;
    uint32_t d;
};

// 16 bytes each
struct AnimPalEntry {      // palette animation entry
    uint32_t a;
    uint32_t b;
    uint32_t c;
    uint32_t d;
};

#pragma pack(pop)

class TRIBE_Screen_Game : public TScreenPanel       {
public:
    char _pad_0x4[0x471];
    TShape* game_screen_pic;                 // 0x475
    TShape* button_border1_pic;              // 0x479
    TShape* button_other_pic;                // 0x47D
    TShape* button_border2_pic;              // 0x481
    TShape* button_border3_pic;              // 0x485
    TShape* button_cmd_pic;                  // 0x489
    TShape* button_tech_pic;                 // 0x48D
    TShape* button_unit_pic;                 // 0x491
    TShape* button_bldg_pics[5];             // 0x495
    TShape* more_cancel_pic;                 // 0x4A9
    short more_frame;                        // 0x4AD
    short cancel_frame;                      // 0x4AF
    short unselect_frame;                    // 0x4B1
    char _pad_0x4B3[0x2];
    TRIBE_Main_View* main_view;              // 0x4B5
    TRIBE_Diamond_Map_View* map_view;        // 0x4B9
    TRIBE_Panel_Inven* inven_panel;          // 0x4BD
    TRIBE_Panel_Object* object_panel;        // 0x4C1
    TRIBE_Panel_Button* button_panel[17];    // 0x4C5
    TMessagePanel* text_line_panel;          // 0x509
    TTextPanel* quit_message_panel;          // 0x50D
    TRIBE_Panel_Time* time_panel;            // 0x511
    TRIBE_Panel_Time* countdown_clock[10];   // 0x515
    TRIBE_Panel_Pop* pop_panel;              // 0x53D
    TMessagePanel* message_panel;            // 0x541
    TMessagePanel* message_panel2;           // 0x545
    TMessagePanel* message_panel3;           // 0x549
    TMessagePanel* message_panel4;           // 0x54D
    TMessagePanel* message_panel5;           // 0x551
    TMessagePanel* message_panel6;           // 0x555
    TMessagePanel* chat_panel[8];            // 0x559
    RGE_Panel_Tool_Box* tool_box;            // 0x579
    TTextPanel* age_panel;                   // 0x57D
    TTextPanel* pause_text;                  // 0x581
    TTextPanel* fps_panel;                   // 0x585
    TMessagePanel* score_panel[8];           // 0x589
    TTextPanel* log_text;                    // 0x5A9
    TScrollBarPanel* log_scrollbar;          // 0x5AD
    TRIBE_World* world;                      // 0x5B1
    ulong update_interval;                   // 0x5B5
    ulong last_update_time;                  // 0x5B9
    ulong map_redraw_interval;               // 0x5BD
    ulong last_map_redraw_time;              // 0x5C1
    RGE_Static_Object* game_obj;             // 0x5C5
    short sel_count;                         // 0x5C9
    char _pad_0x5CB[0x2];
    Item_Avail* tech_list;                   // 0x5CD
    Item_Avail* make_list;                   // 0x5D1
    Item_Avail* bldg_list;                   // 0x5D5
    Trade_Avail* trade_list;                 // 0x5D9
    short item_cnt;                          // 0x5DD
    short start_item;                        // 0x5DF
    short last_item;                         // 0x5E1
    char _pad_0x5E3[0x2];
    __unnamed port_info[9];                  // 0x5E5
    ulong terrain_sound_interval;            // 0x675
    ulong last_terrain_sound_time;           // 0x679
    RGE_Sound* terrain_sound;                // 0x67D
    int terrain_playing;                     // 0x681
    ulong terrain_sound_start_time;          // 0x685
    int anim_pal;                            // 0x689
    ulong anim_pal_interval;                 // 0x68D
    ulong last_anim_pal_time;                // 0x691
    short last_anim_pal_index;               // 0x695
    short last_anim_pal_index2;              // 0x697
    short last_anim_pal_index3;              // 0x699
    __unnamed anim_pal_table[7];             // 0x69B
    char _pad_0x70B[0xB9];

    TRIBE_Screen_Game();

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~TRIBE_Screen_Game() noexcept(false); // Ghidra: `vector_deleting_destructor'

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

    // [Slot 08] Offset 0x20 (Override)
    virtual void set_redraw(RedrawMode param_1); // Ghidra: set_redraw

    // [Slot 09] Offset 0x24 (Override)
    virtual void set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3); // Ghidra: set_overlapped_redraw

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

    // [Slot 18] Offset 0x48 (Override)
    virtual long wnd_proc(void* param_1, uint param_2, uint param_3, long param_4); // Ghidra: wnd_proc

    // [Slot 19] Offset 0x4C (Override)
    virtual long handle_idle(); // Ghidra: handle_idle

    // [Slot 20] Offset 0x50 (Override)
    virtual long handle_size(long param_1, long param_2); // Ghidra: handle_size

    // [Slot 21] Offset 0x54 (Override)
    virtual long handle_paint(); // Ghidra: handle_paint

    // [Slot 22] Offset 0x58 WARNING: Function body missing in analysis
    // virtual void handle_key_down();

    // [Slot 23] Offset 0x5C WARNING: Function body missing in analysis
    // virtual void handle_char();

    // [Slot 24] Offset 0x60 WARNING: Function body missing in analysis
    // virtual void handle_command();

    // [Slot 25] Offset 0x64 (Override)
    virtual long handle_user_command(uint param_1, long param_2); // Ghidra: handle_user_command

    // [Slot 26] Offset 0x68 WARNING: Function body missing in analysis
    // virtual void handle_timer_command();

    // [Slot 27] Offset 0x6C WARNING: Function body missing in analysis
    // virtual void handle_scroll();

    // [Slot 28] Offset 0x70 (Override)
    virtual long handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5); // Ghidra: handle_mouse_down

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

    // [Slot 43] Offset 0xAC (Override)
    virtual long key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5); // Ghidra: key_down_action

    // [Slot 44] Offset 0xB0 (Override)
    virtual long char_action(long param_1, short param_2); // Ghidra: char_action

    // [Slot 45] Offset 0xB4 (Override)
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4); // Ghidra: action

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

    // [Slot 52] Offset 0xD0 (Override)
    virtual void stop_sound_system(); // Ghidra: stop_sound_system

    // [Slot 53] Offset 0xD4 (Override)
    virtual int restart_sound_system(); // Ghidra: restart_sound_system

    // [Slot 54] Offset 0xD8 WARNING: Function body missing in analysis
    // virtual void take_snapshot();

    // [Slot 55] Offset 0xDC WARNING: Function body missing in analysis
    // virtual void handle_reactivate();

    // [Slot 56] Offset 0xE0 WARNING: Function body missing in analysis
    // virtual void draw_background();

    // [Slot 57] Offset 0xE4 WARNING: Function body missing in analysis
    // virtual void set_ideal_size();

    // [Slot 58] Offset 0xE8 WARNING: Function body missing in analysis
    // virtual void create_button();

    // [Slot 59] Offset 0xEC WARNING: Function body missing in analysis
    // virtual void create_button();

    // [Slot 60] Offset 0xF0 WARNING: Function body missing in analysis
    // virtual void create_check_box();

    // [Slot 61] Offset 0xF4 WARNING: Function body missing in analysis
    // virtual void create_radio_button();

    // [Slot 62] Offset 0xF8 WARNING: Function body missing in analysis
    // virtual void create_text();

    // [Slot 63] Offset 0xFC WARNING: Function body missing in analysis
    // virtual void create_text();

    // [Slot 64] Offset 0x100 WARNING: Function body missing in analysis
    // virtual void create_text();

    // [Slot 65] Offset 0x104 WARNING: Function body missing in analysis
    // virtual void create_input();

    // [Slot 66] Offset 0x108 WARNING: Function body missing in analysis
    // virtual void create_edit();

    // [Slot 67] Offset 0x10C WARNING: Function body missing in analysis
    // virtual void create_drop_down();

    // [Slot 68] Offset 0x110 WARNING: Function body missing in analysis
    // virtual void create_list();

    // [Slot 69] Offset 0x114 WARNING: Function body missing in analysis
    // virtual void create_scrollbar();

    // [Slot 70] Offset 0x118 WARNING: Function body missing in analysis
    // virtual void create_auto_scrollbar();

    // [Slot 71] Offset 0x11C WARNING: Function body missing in analysis
    // virtual void create_vert_slider();

    // [Slot 72] Offset 0x120 WARNING: Function body missing in analysis
    // virtual void create_horz_slider();

    // [Slot 73] Offset 0x124 WARNING: Function body missing in analysis
    // virtual void position_panel();

    // --- Non-Virtual Members ---
    void set_map_buttons_redraw(RedrawMode param_1);
    void handle_game_update();
    void handle_pause();
    void handle_resume();
    void handleChatReceived(int param_1);
    void display_system_message(char* param_1);
    void do_button_action(int param_1, int param_2, int param_3);
    void game_mode_changed(int param_1, int param_2);
    void player_changed(int param_1, int param_2);
    void object_changed();
    void age_changed();
    void show_timings(char* param_1, char* param_2);
    void show_comm(char* param_1, char* param_2, char* param_3, char* param_4, char* param_5, char* param_6);
    void show_ai(char* param_1, char* param_2, char* param_3, char* param_4, char* param_5, char* param_6);
    void show_message(MessageType param_1, char* param_2, uchar param_3, uchar param_4);
    void reset_buttons();
    void setup_buttons();
    void disable_unused_buttons();
    char* calc_text_msg(char* param_1, Item_Avail* param_2, long param_3, long param_4);
    short calc_button_loc(uchar param_1);
    void set_button(TShape* param_1, short param_2, short param_3, long param_4, long param_5, long param_6, long param_7, long param_8, uchar* param_9, char* param_10, char* param_11, int param_12);
    void reset_clocks();
    void reset_score_display();
    void handle_anim_pal();
    void handle_terrain_sound();
    void handle_mouse_pointing_at();
    void command_add_attribute(int param_1);
    void command_ai_info();
    void command_attack();
    void command_build();
    void command_building(int param_1);
    void command_cancel();
    void command_cancel_building();
    void command_chat();
    void command_quick_chat();
    void command_comm_info();
    void command_convert();
    void command_diplomacy();
    void command_fog_of_war();
    void command_fps();
    void command_game_speed(int param_1);
    void command_group();
    void command_group_by_number(int param_1);
    void command_heal();
    void command_repair();
    void command_score(int param_1);
    void command_select_group(int param_1, int param_2);
    void command_menu();
    void command_more();
    void command_move();
    void command_outline();
    void command_pause();
    void command_player(int param_1);
    void command_quick_build();
    void command_quit();
    void command_research(int param_1);
    void command_save_game();
    void command_save_scenario();
    void command_select_building(int param_1);
    void command_stop();
    void command_tool_box();
    void command_trade();
    void command_trade_with(int param_1);
    void command_train(int param_1, short param_2);
    void command_ungroup();
    void command_unload();
    void command_unselect();
    void command_view_selected();
    void command_view_tribe();
    void command_visibility();
    void command_work();
    void command_formation(int param_1);
    void command_stand_ground();
    void command_attack_ground();
    void command_trade_attribute(long param_1);
    void command_tab_selected(int param_1);
    int any_selected_have_action();
    void add_log(char* param_1);
};

static_assert(sizeof(TRIBE_Screen_Game) == 0x7C4, "TRIBE_Screen_Game Size Mismatch");

