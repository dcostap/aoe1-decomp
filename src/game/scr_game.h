#pragma once
#include "../common.h"
#include "Pnl_scr.h"
#include "Shape.h"
#include "tvw_main.h"
#include "tvw_dmap.h"
#include "World.h"
#include "tworld.h"
#include "Pnl_scr.h"
#include "Shape.h"
#include "tvw_main.h"
#include "tvw_dmap.h"
#include "map.h"
#include "Panel.h"
#include "Drawarea.h"
#include "view.h"
#include "player.h"
#include "tpnl_inv.h"
#include "tpnl_obj.h"
#include "tpnl_btn.h"
#include "Pnl_msg.h"
#include "Pnl_txt.h"
#include "tpnl_tim.h"
#include "tpnl_pop.h"
#include "rpnl_tbx.h"
#include "Pnl_scbr.h"
#include "Sound.h"

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

class TRIBE_Screen_Game : public TScreenPanel {
public:
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
    PortInfo port_info[9];                  // 0x5E5
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
    AnimPalEntry anim_pal_table[7];         // 0x69B
    char _pad_0x70B[0xB9];

    TRIBE_Screen_Game();
    virtual ~TRIBE_Screen_Game();
    virtual void set_redraw(RedrawMode param_1);
    virtual void set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3);
    virtual void set_map_buttons_redraw(RedrawMode param_1);
    virtual long handle_size(long param_1, long param_2);
    virtual long handle_paint();
    virtual long handle_idle();
    virtual void handle_game_update();
    virtual long wnd_proc(void* param_1, uint param_2, uint param_3, long param_4);
    virtual long handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5);
    virtual long handle_user_command(uint param_1, long param_2);
    virtual void handle_pause();
    virtual void handle_resume();
    virtual void handleChatReceived(int param_1);
    virtual void display_system_message(char* param_1);
    virtual long key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5);
    virtual long char_action(long param_1, short param_2);
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4);
    virtual void do_button_action(int param_1, int param_2, int param_3);
    virtual void game_mode_changed(int param_1, int param_2);
    virtual void player_changed(int param_1, int param_2);
    virtual void object_changed();
    virtual void age_changed();
    virtual void show_timings(char* param_1, char* param_2);
    virtual void show_comm(char* param_1, char* param_2, char* param_3, char* param_4, char* param_5, char* param_6);
    virtual void show_ai(char* param_1, char* param_2, char* param_3, char* param_4, char* param_5, char* param_6);
    virtual void show_message(MessageType param_1, char* param_2, uchar param_3, uchar param_4);
    virtual void reset_buttons();
    virtual void setup_buttons();
    virtual void disable_unused_buttons();
    virtual char* calc_text_msg(char* param_1, Item_Avail* param_2, long param_3, long param_4);
    virtual short calc_button_loc(uchar param_1);
    virtual void set_button(TShape* param_1, short param_2, short param_3, long param_4, long param_5, long param_6, long param_7, long param_8, uchar* param_9, char* param_10, char* param_11, int param_12);
    virtual void reset_clocks();
    virtual void reset_score_display();
    virtual void draw();
    virtual void handle_anim_pal();
    virtual void handle_terrain_sound();
    virtual void handle_mouse_pointing_at();
    virtual void command_add_attribute(int param_1);
    virtual void command_ai_info();
    virtual void command_attack();
    virtual void command_build();
    virtual void command_building(int param_1);
    virtual void command_cancel();
    virtual void command_cancel_building();
    virtual void command_chat();
    virtual void command_quick_chat();
    virtual void command_comm_info();
    virtual void command_convert();
    virtual void command_diplomacy();
    virtual void command_fog_of_war();
    virtual void command_fps();
    virtual void command_game_speed(int param_1);
    virtual void command_group();
    virtual void command_group_by_number(int param_1);
    virtual void command_heal();
    virtual void command_repair();
    virtual void command_score(int param_1);
    virtual void command_select_group(int param_1, int param_2);
    virtual void command_menu();
    virtual void command_more();
    virtual void command_move();
    virtual void command_outline();
    virtual void command_pause();
    virtual void command_player(int param_1);
    virtual void command_quick_build();
    virtual void command_quit();
    virtual void command_research(int param_1);
    virtual void command_save_game();
    virtual void command_save_scenario();
    virtual void command_select_building(int param_1);
    virtual void command_stop();
    virtual void command_tool_box();
    virtual void command_trade();
    virtual void command_trade_with(int param_1);
    virtual void command_train(int param_1, short param_2);
    virtual void command_ungroup();
    virtual void command_unload();
    virtual void command_unselect();
    virtual void command_view_selected();
    virtual void command_view_tribe();
    virtual void command_visibility();
    virtual void command_work();
    virtual void command_formation(int param_1);
    virtual void command_stand_ground();
    virtual void command_attack_ground();
    virtual void command_trade_attribute(long param_1);
    virtual void command_tab_selected(int param_1);
    virtual int any_selected_have_action();
    virtual void set_focus(int param_1);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void add_log(char* param_1);
};

static_assert(sizeof(TRIBE_Screen_Game) == 0x7C4, "TRIBE_Screen_Game Size Mismatch");

