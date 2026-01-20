#pragma once
#include "common.h"
#include "TScreenPanel.h"

class TRIBE_Screen_Game : public TScreenPanel {
public:
    // Virtuals (best-effort)
    virtual ~TRIBE_Screen_Game(); // vt[0] (0x0)
    virtual long setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7); // vt[1] (0x4)
    virtual void set_rect(tagRECT param_1); // vt[2] (0x8)
    virtual void set_rect(long param_1, long param_2, long param_3, long param_4); // vt[3] (0xC)
    virtual void set_color(uchar param_1); // vt[4] (0x10)
    virtual void set_active(int param_1); // vt[5] (0x14)
    virtual void set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13); // vt[6] (0x18)
    virtual void set_fixed_position(long param_1, long param_2, long param_3, long param_4); // vt[7] (0x1C)
    virtual void set_redraw(RedrawMode param_1); // vt[8] (0x20)
    virtual void set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3); // vt[9] (0x24)
    virtual void draw_setup(int param_1); // vt[10] (0x28)
    virtual void draw_finish(); // vt[11] (0x2C)
    virtual void draw(); // vt[12] (0x30)
    virtual void draw_rect(tagRECT* param_1); // vt[13] (0x34)
    virtual void draw_offset(long param_1, long param_2, tagRECT* param_3); // vt[14] (0x38)
    virtual void draw_rect2(tagRECT* param_1); // vt[15] (0x3C)
    virtual void draw_offset2(long param_1, long param_2, tagRECT* param_3); // vt[16] (0x40)
    virtual void paint(); // vt[17] (0x44)
    virtual long wnd_proc(void* param_1, uint param_2, uint param_3, long param_4); // vt[18] (0x48)
    virtual long handle_idle(); // vt[19] (0x4C)
    virtual long handle_size(long param_1, long param_2); // vt[20] (0x50)
    virtual long handle_paint(); // vt[21] (0x54)
    virtual long handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5); // vt[22] (0x58)
    virtual long handle_char(long param_1, short param_2); // vt[23] (0x5C)
    virtual long handle_command(uint param_1, long param_2); // vt[24] (0x60)
    virtual long handle_user_command(uint param_1, long param_2); // vt[25] (0x64)
    virtual long handle_timer_command(uint param_1, long param_2); // vt[26] (0x68)
    virtual long handle_scroll(long param_1, long param_2); // vt[27] (0x6C)
    virtual long handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5); // vt[28] (0x70)
    virtual long handle_mouse_move(long param_1, long param_2, int param_3, int param_4); // vt[29] (0x74)
    virtual long handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5); // vt[30] (0x78)
    virtual long handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5); // vt[31] (0x7C)
    virtual long mouse_move_action(long param_1, long param_2, int param_3, int param_4); // vt[32] (0x80)
    virtual long mouse_left_down_action(long param_1, long param_2, int param_3, int param_4); // vt[33] (0x84)
    virtual long mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4); // vt[34] (0x88)
    virtual long mouse_left_move_action(long param_1, long param_2, int param_3, int param_4); // vt[35] (0x8C)
    virtual long mouse_left_up_action(long param_1, long param_2, int param_3, int param_4); // vt[36] (0x90)
    virtual long mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4); // vt[37] (0x94)
    virtual long mouse_right_down_action(long param_1, long param_2, int param_3, int param_4); // vt[38] (0x98)
    virtual long mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4); // vt[39] (0x9C)
    virtual long mouse_right_move_action(long param_1, long param_2, int param_3, int param_4); // vt[40] (0xA0)
    virtual long mouse_right_up_action(long param_1, long param_2, int param_3, int param_4); // vt[41] (0xA4)
    virtual long mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4); // vt[42] (0xA8)
    virtual long key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5); // vt[43] (0xAC)
    virtual long char_action(long param_1, short param_2); // vt[44] (0xB0)
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4); // vt[45] (0xB4)
    virtual void get_true_render_rect(tagRECT* param_1); // vt[46] (0xB8)
    virtual int is_inside(long param_1, long param_2); // vt[47] (0xBC)
    virtual void set_focus(int param_1); // vt[48] (0xC0)
    virtual void set_tab_order(TPanel* param_1, TPanel* param_2); // vt[49] (0xC4)
    virtual void set_tab_order(TPanel** param_1, short param_2); // vt[50] (0xC8)
    virtual uchar get_help_info(char** param_1, long* param_2, long param_3, long param_4); // vt[51] (0xCC)
    virtual void stop_sound_system(); // vt[52] (0xD0)
    virtual int restart_sound_system(); // vt[53] (0xD4)
    virtual void take_snapshot(); // vt[54] (0xD8)
    virtual void handle_reactivate(); // vt[55] (0xDC)
    virtual void draw_background(int param_1); // vt[56] (0xE0)
    virtual void set_ideal_size(long param_1, long param_2); // vt[57] (0xE4)
    virtual int create_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11); // vt[58] (0xE8)
    virtual int create_button(TPanel* param_1, TButtonPanel** param_2, char* param_3, char* param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11); // vt[59] (0xEC)
    virtual int create_check_box(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8); // vt[60] (0xF0)
    virtual int create_radio_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8); // vt[61] (0xF4)
    virtual int create_text(TPanel* param_1, TTextPanel** param_2, int param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11); // vt[62] (0xF8)
    virtual int create_text(TPanel* param_1, TTextPanel** param_2, char** param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, int param_10, int param_11); // vt[63] (0xFC)
    virtual int create_text(TPanel* param_1, TTextPanel** param_2, char* param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11); // vt[64] (0x100)
    virtual int create_input(TPanel* param_1, TInputPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10); // vt[65] (0x104)
    virtual int create_edit(TPanel* param_1, TEditPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10, int param_11, int param_12); // vt[66] (0x108)
    virtual int create_drop_down(TPanel* param_1, TDropDownPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9); // vt[67] (0x10C)
    virtual int create_list(TPanel* param_1, TListPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7); // vt[68] (0x110)
    virtual int create_scrollbar(TPanel* param_1, TScrollBarPanel** param_2, TTextPanel* param_3, long param_4, long param_5, long param_6, long param_7, long param_8); // vt[69] (0x114)
    virtual int create_auto_scrollbar(TScrollBarPanel** param_1, TTextPanel* param_2, long param_3); // vt[70] (0x118)
    virtual int create_vert_slider(TPanel* param_1, TVerticalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9); // vt[71] (0x11C)
    virtual int create_horz_slider(TPanel* param_1, THorizontalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9); // vt[72] (0x120)
    virtual void position_panel(TPanel* param_1, long param_2, long param_3, long param_4, long param_5); // vt[73] (0x124)

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
    TMessagePanel* message_panel;
    TMessagePanel* message_panel2;
    TMessagePanel* message_panel3;
    TMessagePanel* message_panel4;
    TMessagePanel* message_panel5;
    TMessagePanel* message_panel6;
    TMessagePanel* chat_panel[8];
    RGE_Panel_Tool_Box* tool_box;
    TTextPanel* age_panel;
    TTextPanel* pause_text;
    TTextPanel* fps_panel;
    TMessagePanel* score_panel[8];
    TTextPanel* log_text;
    TScrollBarPanel* log_scrollbar;
    TRIBE_World* world;
    unsigned long update_interval;
    unsigned long last_update_time;
    unsigned long map_redraw_interval;
    unsigned long last_map_redraw_time;
    RGE_Static_Object* game_obj;
    short sel_count;
    Item_Avail* tech_list;
    Item_Avail* make_list;
    Item_Avail* bldg_list;
    Trade_Avail* trade_list;
    short item_cnt;
    short start_item;
    short last_item;
    TRIBE_Screen_Game::__unnamed port_info[9];
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
    TRIBE_Screen_Game::__unnamed anim_pal_table[7];
    TRIBE_Screen_Game::__unnamed anim_pal_table2[16];
    TRIBE_Screen_Game::__unnamed anim_pal_table3[12];
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
static_assert(sizeof(TRIBE_Screen_Game) == 0x7C4, "Size mismatch");
