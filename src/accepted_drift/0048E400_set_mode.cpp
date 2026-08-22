// VA: 0048E400 TribeAchievementsScreen::set_mode (3205 B)
// PDB source: scr_ach.cpp (lines 441-744)
//
// Attempt log:
// - Replaced the unrelated mode shim with the packet-grounded screen-mode
//   setup: common panel reset, switch cases 0-6, per-player statistics, and
//   final active-state updates.
// - Recovered mode-1's six columns and mode-3's attribute-14 column from the
//   ordered original call stream; the canonical ownership remains the named
//   victory-condition/player surface above.
// - The original uses a count-controlled player loop and a row cursor beginning
//   at statistics[0] + 1 (or +2 for mode 2); the source uses typed player and
//   statistics arrays with the same one-based ownership.
// - Next lead: the original switch emits mode 6 before mode 5; keep that
//   compiler handler order rather than numeric source order.
// - Keep each player pointer inside its row loop. The code rereads
//   player->victory_conditions at every helper call.
// - Policy cleanup: replaced the fake panel slot surface with named same-TU
//   TPanel/TTextPanel inheritance and recovered the panel field ownership.
// - Policy cleanup: replaced raw player byte offsets with players[index].
// - BINARY NOTE: the entry block zeroes only the final 19 bytes of temptxt.
//   The partial memset emits those stores with the canonical panel surface.
// - BINARY NOTE: a while loop with a separate remaining count preserves the
//   original count test and row update order.
// - BINARY NOTE: mode 0 disables backButton; mode 6 enables time_line.
//   These values are opposite to the first clean reconstruction.
// - Natural checkpoint: long mode, partial memset, loop-local players, and
//   while loops reduce the strict difference to 43 bytes.
// - The remaining five hunks move each initial index store after its row LEA.
//   Do not restore the rejected raw cursor or fake virtual surface.
// - Accepted-drift audit: all 167 calls, 41 conditional branches, 16 jumps,
//   panel/player/world reads, text updates, active-state stores, loop bounds,
//   and the return align. The five code hunks only swap each private loop-index
//   initialization with its nonfaulting statistics-row LEA. No call or external
//   memory access lies between them. One index uses the same established stack
//   slot in both bodies. The other strict bytes are jump-table relocations.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class TDrawArea;
class TShape;
class TScrollBarPanel;
struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(void*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int active);
    virtual void set_positioning(int, long, long, long, long, long, long, long,
                                 long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, int);
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(tagRECT*);
    virtual void draw_offset(long, long, tagRECT*);
    virtual void draw_rect2(tagRECT*);
    virtual void draw_offset2(long, long, tagRECT*);
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
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    virtual long handle_mouse_move(long, long, int, int);
    virtual long handle_mouse_up(unsigned char, long, long, int, int);
    virtual long handle_mouse_dbl_click(unsigned char, long, long, int, int);
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
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void get_true_render_rect(tagRECT*);
    virtual int is_inside(long, long);
    virtual void set_focus(int);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual void set_tab_order(TPanel**, short);
    virtual unsigned char get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();

    TPanel* previousPanelValue;       // +0x04
    TPanel* previousModalPanelValue;  // +0x08
    long pnl_x;                       // +0x0C
    long pnl_y;                       // +0x10
    long pnl_wid;                     // +0x14
    long pnl_hgt;                     // +0x18
    char* panelNameValue;              // +0x1C
    TDrawArea* render_area;            // +0x20
    tagRECT clip_rect;                 // +0x24
    int position_mode;                 // +0x34
    int need_redraw;                   // +0x38
    TPanel* curr_child;                // +0x3C
    TPanel* parent_panel;              // +0x40
    TPanel* left_panel;                // +0x44
    TPanel* top_panel;                 // +0x48
    TPanel* right_panel;               // +0x4C
    TPanel* bottom_panel;              // +0x50
    void* node;                        // +0x54
    void* first_child_node;            // +0x58
    void* last_child_node;             // +0x5C
    TPanel* tab_prev_panel;            // +0x60
    TPanel* tab_next_panel;            // +0x64
    int mouse_captured;                // +0x68
    int active;                        // +0x6C
    int visible;                       // +0x70
    int tab_stop;                      // +0x74
    int have_focus;                    // +0x78
    int overlapping_children;          // +0x7C
    int handle_mouse_input;            // +0x80
    int just_drawn;                    // +0x84
    void* clip_rgn;                    // +0x88
    tagRECT render_rect;               // +0x8C
    long left_border;                  // +0x9C
    long top_border;                   // +0xA0
    long right_border;                 // +0xA4
    long bottom_border;                // +0xA8
    long min_wid;                      // +0xAC
    long max_wid;                      // +0xB0
    long min_hgt;                      // +0xB4
    long max_hgt;                      // +0xB8
    long mouse_hold_interval;          // +0xBC
    long mouse_move_tolerance;         // +0xC0
    long mouse_down_x;                 // +0xC4
    long mouse_down_y;                 // +0xC8
    int mouse_down_ctrl;               // +0xCC
    int mouse_down_shift;              // +0xD0
    unsigned long mouse_down_time;     // +0xD4
    int error_code;                    // +0xD8
    int z_order;                       // +0xDC
    int display_changed_count;         // +0xE0
    long help_string_id;               // +0xE4
    long help_page_id;                 // +0xE8
    unsigned char mouse_action;        // +0xEC
    unsigned char mouse_down_button;   // +0xED
    unsigned char panel_type;          // +0xEE
    unsigned char color;               // +0xEF
    unsigned char fill_in_background;  // +0xF0
    unsigned char clip_to_parent;      // +0xF1
    unsigned char draw_rect2_flag;     // +0xF2
    unsigned char need_restore;        // +0xF3

    void set_curr_child(TPanel* child);
};

class TEasy_Panel : public TPanel {
public:
    virtual ~TEasy_Panel();
    char gap_F4[0x384];
};

class TScreenPanel : public TEasy_Panel {
public:
    virtual ~TScreenPanel();
};

class TTextPanel : public TPanel {
public:
    virtual ~TTextPanel();
    virtual void set_rect(long, long, long, long);
    virtual void set_active(int);
    virtual void draw();
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long key_down_action(long, short, int, int, int);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void set_text(char*);
    virtual void set_text(long);
    virtual void set_text(char**, short);
    virtual void set_bevel_info(int, int, int, int, int, int, int);

    void* list;                         // +0xF4
    short num_lines;                    // +0xF8
    short draw_lines;                   // +0xFA
    short top_line;                     // +0xFC
    short bot_line;                     // +0xFE
    short cur_line;                     // +0x100
    short cur_col;                      // +0x102
    void* font;                         // +0x104
    long font_wid;                       // +0x108
    long font_hgt;                       // +0x10C
    long vert_align;                     // +0x110
    long horz_align;                     // +0x114
    int word_wrap;                       // +0x118
    long text_style;                     // +0x11C
    unsigned long text_color1;            // +0x120
    unsigned long text_color2;            // +0x124
    unsigned long highlight_text_color1;  // +0x128
    unsigned long highlight_text_color2;  // +0x12C
    TScrollBarPanel* scbar_panel;        // +0x130
    int auto_scbar;                      // +0x134
    short fixed_len;                     // +0x138
    char gap_13A[0x02];
    long text_wid;                        // +0x13C
    long text_hgt;                        // +0x140
    void* back_pic;                       // +0x144
    short back_pic_wid;                   // +0x148
    short back_pic_hgt;                   // +0x14A
    int fill_back;                        // +0x14C
    unsigned char back_color;              // +0x150
    char gap_151[0x03];
    int outline;                          // +0x154
    unsigned char outline_color;           // +0x158
    char gap_159[0x03];
    int sorted;                           // +0x15C
    long second_column_pos;               // +0x160
    long full_width;                      // +0x164
    long scbar_width;                     // +0x168
    int scbar_active;                     // +0x16C
    int bevel_type;                       // +0x170
    unsigned char bevel_color1;            // +0x174
    unsigned char bevel_color2;            // +0x175
    unsigned char bevel_color3;            // +0x176
    unsigned char bevel_color4;            // +0x177
    unsigned char bevel_color5;            // +0x178
    unsigned char bevel_color6;            // +0x179
    char gap_17A[0x02];
    void* clip_rgn2;                       // +0x17C
    int border_size;                       // +0x180
    int spacer_size;                       // +0x184
};

class TButtonPanel : public TPanel {
public:
    virtual ~TButtonPanel();
    char gap_F4[0x1A4];
    int hotkey;                            // +0x298
    int hotkey_shift;                      // +0x29C
};

class TScrollBarPanel : public TPanel {
public:
    virtual ~TScrollBarPanel();
    TPanel* list_panel;                    // +0xF4
    char gap_F8[0xCC];
};

class Time_Line_Panel : public TPanel {
public:
    virtual ~Time_Line_Panel();
};

class RGE_Victory_Conditions {
public:
    char gap_00[0x14];

    int get_victory_points_group(unsigned char group);
    int get_attribute_id(unsigned char id);
    int get_victory_points_id(unsigned char id);
    int get_victory_points();
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x30];
    RGE_Victory_Conditions* victory_conditions; // +0x34
    char gap_38[0x18];
    float* attributes;                           // +0x50
};

class RGE_Game_World {
public:
    virtual void data_load_world();
    char gap_04[0x38];
    short player_num;                            // +0x3C
    char gap_3E[2];
    RGE_Player** players;                        // +0x40
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_04[0x3F0];
    RGE_Game_World* world;                       // +0x3F4

    void disable_input();
};

extern RGE_Base_Game* rge_base_game;

class TribeAchievementsScreen : public TScreenPanel {
public:
    int end_game_flag;                           // +0x478
    int current_mode;                            // +0x47C
    int size;                                    // +0x480
    TTextPanel* title;                           // +0x484
    TTextPanel* summary_text;                    // +0x488
    TTextPanel* instruction;                     // +0x48C
    TTextPanel* win_loss_text;                   // +0x490
    TTextPanel* time;                            // +0x494
    TTextPanel* title_bar[7];                    // +0x498
    TTextPanel* achievement_choice[5];           // +0x4B4
    TTextPanel* statistics[8][7];                // +0x4C8
    TTextPanel* player_names[8];                 // +0x5A8
    TScrollBarPanel* summary_text_bar;           // +0x5C8
    TScrollBarPanel* instruction_bar;            // +0x5CC
    TScrollBarPanel* win_loss_text_bar;          // +0x5D0
    TButtonPanel* okButton;                      // +0x5D4
    TButtonPanel* backButton;                    // +0x5D8
    TButtonPanel* backButton2;                   // +0x5DC
    TButtonPanel* timelineButton;                // +0x5E0
    TButtonPanel* aftermathButton;               // +0x5E4
    TButtonPanel* restartButton;                 // +0x5E8
    TButtonPanel* close_button;                  // +0x5EC
    TShape* win_decal;                            // +0x5F0
    Time_Line_Panel* time_line;                   // +0x5F4

    void set_mode(long mode);
};

void TribeAchievementsScreen::set_mode(long mode)
{
    int player_num = (int)rge_base_game->world->player_num - 1;
    char temptxt[50];
    memset(&temptxt[31], 0, sizeof(temptxt) - 31);

    rge_base_game->disable_input();

    if (this->win_loss_text != 0) {
        this->win_loss_text->set_active(0);
    }
    this->current_mode = mode;
    this->time_line->set_active(0);
    this->instruction->set_active(0);
    this->time->set_active(1);

    if (this->restartButton != 0) {
        this->restartButton->set_active(0);
    }
    if (this->okButton != 0) {
        this->okButton->set_active(0);
    }
    if (this->aftermathButton != 0) {
        this->aftermathButton->set_active(0);
    }
    if (this->timelineButton != 0) {
        this->timelineButton->set_active(0);
    }
    if (this->backButton != 0) {
        this->backButton->set_active(1);
    }
    if (this->backButton2 != 0) {
        this->backButton2->set_active(0);
    }
    this->set_curr_child(this->backButton);

    switch (mode) {
    case 0: {
        this->size = 7;
        this->set_curr_child(this->okButton);

        if (this->restartButton != 0) {
            this->restartButton->set_active(1);
        }
        if (this->okButton != 0) {
            this->okButton->set_active(1);
        }
        if (this->aftermathButton != 0) {
            this->aftermathButton->set_active(1);
        }
        if (this->timelineButton != 0) {
            this->timelineButton->set_active(1);
        }
        if (this->backButton != 0) {
            this->backButton->set_active(0);
        }

        this->instruction->set_active(1);
        this->summary_text->set_text((long)0x26D9);
        this->title_bar[0]->set_text((long)0x26AC);
        this->title_bar[1]->set_text((long)0x26AD);
        this->title_bar[2]->set_text((long)0x26AE);
        this->title_bar[3]->set_text((long)0x26AF);
        this->title_bar[4]->set_text((long)0x26D6);
        this->title_bar[5]->set_text((long)0x26D7);
        this->title_bar[6]->set_text((long)0x26B1);

        if (player_num > 0) {
            int player_index = 1;
            TTextPanel** row = this->statistics[0] + 1;
            int remaining = player_num;
            while (remaining != 0) {
            RGE_Player* player;
            player = rge_base_game->world->players[player_index];

            itoa(player->victory_conditions->get_victory_points_group(0), temptxt, 10);
            row[-1]->set_text(temptxt);
            itoa(player->victory_conditions->get_victory_points_group(1), temptxt, 10);
            row[0]->set_text(temptxt);
            itoa(player->victory_conditions->get_victory_points_group(2), temptxt, 10);
            row[1]->set_text(temptxt);
            itoa(player->victory_conditions->get_victory_points_group(3), temptxt, 10);
            row[2]->set_text(temptxt);

            if (player->victory_conditions->get_victory_points_id(0x16) > 0) {
                row[3]->set_text((long)0xFA3);
            } else {
                row[3]->set_text("");
            }
            if (player->victory_conditions->get_victory_points_id(0x17) > 0) {
                row[4]->set_text((long)0xFA3);
            } else {
                row[4]->set_text("");
            }

            itoa(player->victory_conditions->get_victory_points(), temptxt, 10);
            row[5]->set_text(temptxt);
            ++player_index;
            row += 7;
            --remaining;
            }
        }
        break;
    }

    case 1: {
        this->size = 6;
        this->summary_text->set_text((long)0x26AC);
        this->title_bar[0]->set_text((long)0x26B6);
        this->title_bar[1]->set_text((long)0x26B7);
        this->title_bar[2]->set_text((long)0x26B9);
        this->title_bar[3]->set_text((long)0x26B8);
        this->title_bar[4]->set_text((long)0x26BA);
        this->title_bar[5]->set_text((long)0x26B5);

        if (player_num > 0) {
            int player_index = 1;
            TTextPanel** row = this->statistics[0] + 1;
            int remaining = player_num;
            while (remaining != 0) {
            RGE_Player* player;
            player = rge_base_game->world->players[player_index];

            itoa(player->victory_conditions->get_attribute_id(0), temptxt, 10);
            row[-1]->set_text(temptxt);
            itoa(player->victory_conditions->get_attribute_id(1), temptxt, 10);
            row[0]->set_text(temptxt);
            itoa((long)(player->attributes[19] - player->attributes[11]), temptxt, 10);
            row[1]->set_text(temptxt);

            itoa(player->victory_conditions->get_attribute_id(2), temptxt, 10);
            row[2]->set_text(temptxt);

            if (player->victory_conditions->get_victory_points_id(3) > 0) {
                row[3]->set_text((long)0xFA3);
            } else {
                row[3]->set_text("");
            }

            itoa(player->victory_conditions->get_victory_points_group(0), temptxt, 10);
            row[4]->set_text(temptxt);
            ++player_index;
            row += 7;
            --remaining;
            }
        }
        break;
    }

    case 2: {
        this->size = 7;
        this->summary_text->set_text((long)0x26AD);
        this->title_bar[0]->set_text((long)0x26BE);
        this->title_bar[1]->set_text((long)0x26BF);
        this->title_bar[2]->set_text((long)0x26C0);
        this->title_bar[3]->set_text((long)0x26C1);
        this->title_bar[4]->set_text((long)0x26C2);
        this->title_bar[5]->set_text((long)0x26C3);
        this->title_bar[6]->set_text((long)0x26B5);

        if (player_num > 0) {
            int player_index = 1;
            TTextPanel** row = this->statistics[0] + 2;
            int remaining = player_num;
            while (remaining != 0) {
            RGE_Player* player;
            player = rge_base_game->world->players[player_index];

            itoa(player->victory_conditions->get_attribute_id(4), temptxt, 10);
            row[-2]->set_text(temptxt);
            itoa(player->victory_conditions->get_attribute_id(5), temptxt, 10);
            row[-1]->set_text(temptxt);

            if (player->victory_conditions->get_victory_points_id(6) > 0) {
                row[0]->set_text((long)0xFA3);
            } else {
                row[0]->set_text("");
            }

            sprintf(temptxt, "%d", player->victory_conditions->get_attribute_id(7));
            row[1]->set_text(temptxt);

            if (player->victory_conditions->get_victory_points_id(8) > 0) {
                row[2]->set_text((long)0xFA3);
            } else {
                row[2]->set_text("");
            }

            itoa(player->victory_conditions->get_attribute_id(9), temptxt, 10);
            row[3]->set_text(temptxt);
            itoa(player->victory_conditions->get_victory_points_group(1), temptxt, 10);
            row[4]->set_text(temptxt);
            ++player_index;
            row += 7;
            --remaining;
            }
        }
        break;
    }

    case 3: {
        this->size = 7;
        this->summary_text->set_text((long)0x26AE);
        this->title_bar[0]->set_text((long)0x26C6);
        this->title_bar[1]->set_text((long)0x26C7);
        this->title_bar[2]->set_text((long)0x26C8);
        this->title_bar[3]->set_text((long)0x26C9);
        this->title_bar[4]->set_text((long)0x26CA);
        this->title_bar[5]->set_text((long)0x26DC);
        this->title_bar[6]->set_text((long)0x26B5);

        if (player_num > 0) {
            int player_index = 1;
            TTextPanel** row = this->statistics[0] + 1;
            int remaining = player_num;
            while (remaining != 0) {
            RGE_Player* player;
            player = rge_base_game->world->players[player_index];

            this->time_line->set_active(0);
            itoa(player->victory_conditions->get_attribute_id(10), temptxt, 10);
            row[-1]->set_text(temptxt);

            if (player->victory_conditions->get_victory_points_id(11) > 0) {
                row[0]->set_text((long)0xFA3);
            } else {
                row[0]->set_text("");
            }

            itoa(player->victory_conditions->get_attribute_id(12), temptxt, 10);
            row[1]->set_text(temptxt);
            itoa(player->victory_conditions->get_attribute_id(13), temptxt, 10);
            row[2]->set_text(temptxt);
            itoa(player->victory_conditions->get_attribute_id(14), temptxt, 10);
            row[3]->set_text(temptxt);

            itoa(player->victory_conditions->get_victory_points_id(15) +
                 player->victory_conditions->get_victory_points_id(16), temptxt, 10);
            row[4]->set_text(temptxt);
            itoa(player->victory_conditions->get_victory_points_group(2), temptxt, 10);
            row[5]->set_text(temptxt);
            ++player_index;
            row += 7;
            --remaining;
            }
        }
        break;
    }

    case 4: {
        this->size = 5;
        this->summary_text->set_text((long)0x26AF);
        this->title_bar[0]->set_text((long)0x26CE);
        this->title_bar[1]->set_text((long)0x26D1);
        this->title_bar[2]->set_text((long)0x26CF);
        this->title_bar[3]->set_text((long)0x26D0);
        this->title_bar[4]->set_text((long)0x26B5);

        if (player_num > 0) {
            int player_index = 1;
            TTextPanel** row = this->statistics[0] + 1;
            int remaining = player_num;
            while (remaining != 0) {
            RGE_Player* player;
            player = rge_base_game->world->players[player_index];

            itoa(player->victory_conditions->get_attribute_id(17), temptxt, 10);
            row[-1]->set_text(temptxt);
            if (player->victory_conditions->get_victory_points_id(18) > 0) {
                row[0]->set_text((long)0xFA3);
            } else {
                row[0]->set_text("");
            }
            if (player->victory_conditions->get_victory_points_id(19) > 0) {
                row[1]->set_text((long)0xFA3);
            } else {
                row[1]->set_text("");
            }
            if (player->victory_conditions->get_victory_points_id(20) > 0) {
                row[2]->set_text((long)0xFA3);
            } else {
                row[2]->set_text("");
            }
            itoa(player->victory_conditions->get_victory_points_group(3), temptxt, 10);
            row[3]->set_text(temptxt);
            ++player_index;
            row += 7;
            --remaining;
            }
        }
        break;
    }

    case 6:
        this->size = 0;
        this->time_line->set_active(1);
        this->summary_text->set_text((long)0x26D8);
        this->time->set_active(1);
        break;

    case 5:
        this->size = 0;
        this->summary_text->set_text((long)0x26B2);
        if (this->win_loss_text != 0) {
            this->win_loss_text->set_active(1);
        }
        this->time->set_active(0);
        if (this->backButton != 0) {
            this->backButton->set_active(0);
        }
        if (this->backButton2 != 0) {
            this->backButton2->set_active(1);
            this->set_curr_child(this->backButton2);
        }
        break;
    }

    if (this->size == 0) {
        for (int i = 0; i < 8; ++i) {
            this->player_names[i]->set_active(0);
        }
    } else {
        for (int i = 0; i < 8; ++i) {
            this->player_names[i]->set_active(i < player_num);
        }
    }

    for (int i = 0; i < 7; ++i) {
        this->title_bar[i]->set_active(i < this->size);
        for (int j = 0; j < player_num; ++j) {
            this->statistics[j][i]->set_active(i < this->size);
        }
    }
}
