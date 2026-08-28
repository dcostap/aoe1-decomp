#ifndef AOE1_SCR_GAME_H
#define AOE1_SCR_GAME_H

// PDB owner: scr_game.cpp.
// This header owns only TRIBE_Screen_Game and its score record.

#include "Pnl_scr.h"
#include "Shape.h"
#include "pnl_btn.h"
#include "pnl_msg.h"
#include "pnl_lst.h"
#include "Pnl_scbr.h"
#include "sound.h"
#include "sounddrv.h"
#include "main.h"
#include "tribegam.h"
#include "tplayer.h"
#include "tworld.h"
#include "stat_obj.h"
#include "act_obj.h"
#include "m_s_obj.h"
#include "m_co_obj.h"
#include "tm_co_ob.h"
#include "tm_b_obj.h"
#include "t_b_obj.h"
#include "tech.h"
#include "tcommand.h"
#include "victory.h"
#include "vw_main.h"
#include "tvw_dmap.h"
#include "tpnl_btn.h"
#include "tpnl_inv.h"
#include "tpnl_obj.h"
#include "tpnl_tim.h"
#include "tpnl_pop.h"
#include "rpnl_tbx.h"
#include "com_hand.h"
#include "com_spd.h"
#include "chat.h"
#include "debuglog.h"
#include "dlg_smsg.h"
#include "dlg_dip.h"
#include "dlg_menu.h"
#include "scr_save.h"
#include "scr_load.h"

struct PLAYER_SCORE {
    int comm_id;
    int player_id;
    int team_id;
    long player_score;
    long team_score;
};

class TRIBE_Screen_Game : public TScreenPanel {
public:
    struct PortInfo {
        short player_id;
        RGE_Player* player;
        RGE_Static_Object* port;
        short money;
    };

    struct AnimPalEntry {
        unsigned char red;
        unsigned char green;
        unsigned char blue;
    };

protected:
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
    AnimPalEntry anim_pal_table[7];
    AnimPalEntry anim_pal_table2[16];
    AnimPalEntry anim_pal_table3[12];
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

public:
    TRIBE_Main_View* get_view_panel() { return this->main_view; }
    TRIBE_Diamond_Map_View* get_map_panel() { return this->map_view; }
    TMessagePanel* get_text_line_panel() { return this->text_line_panel; }

    TRIBE_Screen_Game();
    virtual ~TRIBE_Screen_Game();
    void draw();

protected:
    void handle_anim_pal();
    void handle_terrain_sound();

public:
    long handle_size(long, long);
    void handle_game_update();
    long key_down_action(long, short, int, int, int);
    long action(TPanel*, long, unsigned long, unsigned long);

protected:
    void do_button_action(int, int, int);

public:
    void setup_buttons();
    void reset_score_display();
    void player_changed(int, int);
    void reset_clocks();

protected:
    void command_score(int);
    void command_group_by_number(int);
    void command_select_group(int, int);
    void command_formation(int);
    void command_tab_selected(int);
    void command_view_selected();
    void command_building(int);
    void command_select_building(int);
    void command_player(int);
    void command_add_attribute(int);
    void command_tool_box();
    void command_quick_build();
    void command_work();
    void command_move();
    void command_attack();
    void command_ungroup();
    void command_fps();
    void command_visibility();
    void command_fog_of_war();
    void command_comm_info();
    void command_ai_info();
    void command_quick_chat();
    void command_cancel_building();
    void command_cancel();
    void command_unselect();
    void object_changed();
    void age_changed();
    int any_selected_have_action();

public:
    void disable_unused_buttons();

protected:
    char* calc_text_msg(char*, Item_Avail*, long, long);
    short calc_button_loc(unsigned char);
    void set_button(TShape*, short, short, long, long, long, long, long,
                    unsigned char*, char*, char*, int);

public:
    virtual void set_redraw(TPanel::RedrawMode);
    virtual void set_overlapped_redraw(TPanel*, TPanel*,
                                       TPanel::RedrawMode);
    void set_map_buttons_redraw(TPanel::RedrawMode);
    long handle_paint();
    long handle_idle();
    long wnd_proc(void*, unsigned int, unsigned int, long);
    long handle_mouse_down(unsigned char, long, long, int, int);
    virtual long handle_user_command(unsigned int, long);
    void handle_pause();
    void handle_resume();
    void handleChatReceived(int);

protected:
    void handle_mouse_pointing_at();

public:
    void display_system_message(char*);
    long char_action(long, short);
    void show_timings(char*, char*);
    void show_comm(char*, char*, char*, char*, char*, char*);
    void show_ai(char*, char*, char*, char*, char*, char*);
    void show_message(TMessagePanel::MessageType, char*, unsigned char,
                      unsigned char);
    void reset_buttons();
    void game_mode_changed(int, int);

protected:
    void command_game_speed(int);

public:
    void set_info_file(char*);
    void set_info_file(char*, long);
    void set_popup_info_file(char*);
    void set_popup_info_file(char*, long);
    void set_button_pics();
    void set_button_pics(char*, long);
    void set_bevel_colors(int, int, int, int, int, int);

protected:
    void command_build();
    void command_chat();
    void command_repair();
    void command_heal();
    void command_convert();
    void command_diplomacy();
    void command_research(int);
    void clear_popup_help();
    void command_save_game();
    void command_save_scenario();
    void command_stop();
    void command_trade();
    void command_trade_with(int);
    void command_train(int, short);
    void command_unload();
    void command_view_tribe();
    void command_outline();
    void command_pause();
    void command_more();
    void command_menu();
    void command_group();
    void command_attack_ground();
    void command_stand_ground();
    void command_trade_attribute(long);
    void command_quit();
    void stop_sound_system();
    virtual int restart_sound_system();

public:
    void add_log(char*);
    virtual void set_focus(int);
};

typedef char scr_game_size_check[
    (sizeof(TRIBE_Screen_Game) == 0x7C4) ? 1 : -1];

extern RGE_Base_Game* rge_base_game;
extern int disable_terrain_sounds;
extern int _bPlaying;
extern TCommunications_Handler* comm;
extern TChat* chat;
extern TDebuggingLog* L;
extern int start_paused;
extern int allow_user_commands;
extern int do_fixed_update;
extern int displayPathingFlags;
extern int MapPathsDisplay;
extern int view_debug_spans;
extern int view_debug_redraw_all;
extern int view_debug_ObstructionMap;
extern int view_debug_Objects;
extern int show_timing_max;
extern int view_debug_palette;
extern int View_Grid_Mode;
extern int confirmed_close;
extern int multi_updates;
extern int out_of_sync2;
extern unsigned char die_die_die;
extern unsigned char do_color_log;
extern unsigned char production_queues_is_use;
extern int memory_dump_sequence;
extern char Save_Game_Screen[];
extern char s_Save_Game_Screen[];
extern char s_Game_Screen[];
extern char s_scr6[];
extern char s_scr_game_cpp[];
extern char s_C__msdev_work_age1_x1_scr_game_c[];
extern char s_Send_Quick_Message_Dialog[];
extern char s_Help_Dialog[];
extern char s_won_wav[];
extern char s_lost_wav[];
extern char s_btnunit_shp[];
extern char s_btntech_shp[];
extern char s_btncmd_shp[];
extern char s_btnbldg_d_shp[];
extern char s_bordline[];
extern char s_map_bmp[];
extern char s_[];
extern char s_PAUSE[];
extern const char s_Writing_out_memory_info[];
extern const char s_memory_filename[];
extern char s_ALLOWCTRLU[];
extern char s_force_ctrl_u[];

extern unsigned char byte_62C584;
extern char close_confirmation_text[];

#endif
