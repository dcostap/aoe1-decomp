#pragma once
#include "common.h"
#include "TScreenPanel.h"

class TRIBE_Screen_Sed : public TScreenPanel {
public:
    // Virtuals (best-effort)
    virtual ~TRIBE_Screen_Sed(); // vt[0] (0x0)
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

    int is_multi_player;
    int set_player_first_flag;
    RGE_Static_Object* SelectedObject;
    RGE_Static_Object* DestinationObject;
    float px1;
    float py1;
    float px2;
    float py2;
    int CurrentVictory;
    int CurrentPlayer;
    TRIBE_Screen_Sed::SELECT_REGION_e SelectRegionFlag;
    TRIBE_Screen_Sed::ScenarioMode scenario_mode;
    TRIBE_Screen_Sed::MapType map_type;
    TRIBE_Screen_Sed::VictoryType mp_victory_type;
    TRIBE_Screen_Sed::BrushSize brush_size;
    TRIBE_Screen_Sed::PaintType paint_type;
    short player_num;
    TRIBE_Screen_Sed::MessageType message_type;
    unsigned char need_to_save_flag;
    unsigned char valid_save_spot_flag;
    TShape* background_pic;
    TRIBE_Main_View* main_view;
    RGE_Diamond_Map_View* map_view;
    TMessagePanel* message_panel;
    TPanel* bottom_panel;
    TButtonPanel* scenario_mode_button[10];
    TButtonPanel* menu_button;
    TButtonPanel* help_button;
    TButtonPanel* map_type_button[3];
    TTextPanel* map_type_text[3];
    TTextPanel* map_type_label;
    TTextPanel* default_terrain_label;
    TDropDownPanel* default_terrain_drop;
    TTextPanel* map_size_label;
    TDropDownPanel* map_size_drop;
    TTextPanel* map_style_label;
    TDropDownPanel* map_style_drop;
    TTextPanel* random_seed_label;
    TEditPanel* random_seed_input;
    TTextPanel* random_seed_used_label;
    TTextPanel* random_seed_used_text;
    TButtonPanel* generate_map_button;
    TTextPanel* map_generating_text;
    TTextPanel* brush_size_label;
    TButtonPanel* brush_size_button[5];
    TTextPanel* brush_size_button_label[5];
    TTextPanel* paint_type_label;
    TButtonPanel* paint_type_button[3];
    TTextPanel* paint_type_button_label[3];
    TTextPanel* paint_terrain_label;
    TListPanel* paint_terrain_list;
    TScrollBarPanel* paint_terrain_scrollbar;
    TListPanel* paint_elevation_list;
    TScrollBarPanel* paint_elevation_scrollbar;
    TTextPanel* player_label;
    TDropDownPanel* player_list;
    TDropDownPanel* player_number_list;
    TDropDownPanel* player_advance_civilization_drop;
    TButtonPanel* player_advance_civilization_button;
    TTextPanel* player_inven_label[5];
    TEditPanel* player_inven_input[5];
    TTextPanel* player_setting_label[2];
    TTextPanel* player_starting_age_label;
    TDropDownPanel* player_setting_drop[2];
    TDropDownPanel* BuildList;
    TDropDownPanel* CityLayout;
    TDropDownPanel* AiRules;
    TTextPanel* player_build_text;
    TTextPanel* player_city_text;
    TTextPanel* AiRules_text;
    TDropDownPanel* unit_player_list;
    TButtonPanel* unit_mode_select[4];
    TTextPanel* unit_mode_select_label[4];
    TListPanel* unit_list;
    TScrollBarPanel* unit_scrollbar;
    TRIBE_Screen_Sed::List_Info* unit_list_info;
    TShape* button_unit_pics;
    TShape* button_bldg_pics[5];
    TRIBE_Scenario_Editor_Panel_Object* object_panel;
    short unit_list_size;
    TButtonPanel* victory_cond_on[6];
    TButtonPanel* victory_and_or[2];
    TTextPanel* victory_condition_label;
    TTextPanel* victory_amount_label;
    TTextPanel* victory_long_label;
    TTextPanel* victory_text_and_or[2];
    TTextPanel* victory_label_conquest;
    TTextPanel* victory_label_explore;
    TTextPanel* victory_label_explore_percent;
    TTextPanel* victory_label_ruins;
    TTextPanel* victory_label_artifacts;
    TTextPanel* victory_label_discoveries;
    TTextPanel* victory_label_gold;
    TEditPanel* victory_condition_explore;
    TEditPanel* victory_condition_ruins;
    TEditPanel* victory_condition_artifacts;
    TEditPanel* victory_condition_discoveries;
    TEditPanel* victory_condition_gold;
    TTextPanel* victory_cond_type_label[5];
    TButtonPanel* victory_cond_type[5];
    TTextPanel* victory_score_label;
    TDropDownPanel* victory_score;
    TTextPanel* victory_time_label;
    TDropDownPanel* victory_time;
    TButtonPanel* victory_button[12];
    TDropDownPanel* victory_drop_down;
    TDropDownPanel* victory_object_list;
    TDropDownPanel* victory_player_list;
    TDropDownPanel* victory_enemy_player_list;
    TDropDownPanel* victory_attribute_list;
    TDropDownPanel* victory_ages_list;
    TDropDownPanel* victory_tech_list;
    TButtonPanel* victory_button_set_object;
    TButtonPanel* victory_button_set_destination;
    TButtonPanel* victory_button_go_to_dest;
    TTextPanel* victory_condition_text;
    TTextPanel* victory_condition_type;
    TTextPanel* victory_amount_text;
    TTextPanel* victory_which_enemy_text;
    TEditPanel* victory_amount_input;
    TScrollBarPanel* victory_object_scrollbar;
    TEditPanel* message_input;
    TButtonPanel* message_button[5];
    TTextPanel* message_button_label[5];
    long current_message;
    TTextPanel* cinematic_label[4];
    TDropDownPanel* cinematic_input[4];
    TTextPanel* options_label[1];
    TButtonPanel* options_button[1];
    TDropDownPanel* options_player_list;
    TTextPanel* options_disable_tech_text;
    TButtonPanel* options_disable_button[16];
    TTextPanel* options_disable_text[16];
    TTextPanel* Diplomacy_opponent_label[8];
    TTextPanel* Diplomacy_player_text[8];
    TDropDownPanel* Diplomacy_player_list;
    TTextPanel* Diplomacy_status_label[4];
    TButtonPanel* Diplomacy_friend_box[8][3];
    TButtonPanel* Diplomacy_AlliedVictory[8];
    TRIBE_World* world;
    unsigned long update_interval;
    unsigned long last_update_time;
    unsigned long map_redraw_interval;
    unsigned long last_map_redraw_time;
    int changed_system_colors;
    unsigned long save_text_color;
    unsigned long save_window_color;
};
static_assert(sizeof(TRIBE_Screen_Sed) == 0x948, "Size mismatch");
