// VA: 0048D530 TribeAchievementsScreen::TribeAchievementsScreen (3222 B)
// PDB source: scr_ach.cpp (lines 110-354)
//
// Attempt log:
// - Replaced the constructor shim with the packet-grounded screen setup:
//   member initialization, localized setup-file selection, text/statistics
//   panels, timeline/buttons, winner decal, tab order, and initial mode.
// - Recovered world-time/player/civilization offsets and all 69 direct/virtual
//   call sites. A 48-byte effective scratch variant matched the frame but was
//   rejected as compiler steering; the PDB-backed 50-byte natural local is kept.
// - Tested an uninitialized temptxt declaration from the decompiler; VC5
//   elided the unused local, changing the frame to 0x1A4 and worsening diff.
//   Rolled back to the validated natural source.
// - The original tail uses an explicit branch for mode selection, not a
//   branchless ternary. The row loop also retains the shipped dec/cmp tail.
// - BINARY NOTE: The original writes a zero tail at the unaligned temptxt
//   stack home. A partial memset preserves this shipped local effect.
// - The row declaration order and <= 8 loop test recover the original setup
//   stores and reduce the measured difference to 2458 bytes.
// - A 256-byte info_file gives the exact frame, but the packet indicates 260
//   bytes and matching period sources use 260-byte file buffers. Keep 260.

#include <stdio.h>
#include <string.h>

class TDrawArea;
class TPanel;
class TTextPanel;
class TButtonPanel;
class TScrollBarPanel;
class Time_Line_Panel;

class TPanel {
public:
    virtual ~TPanel();
    virtual void vf_004();
    virtual void vf_008();
    virtual void vf_00C();
    virtual void vf_010();
    virtual void set_active(int active);
    virtual void vf_018(int a, int b, int c, int d, int e, int f, int g, int h);
    virtual void vf_01C();
    virtual void vf_020();
    virtual void vf_024();
    virtual void vf_028();
    virtual void vf_02C();
    virtual void vf_030();
    virtual void vf_034();
    virtual void vf_038();
    virtual void vf_03C();
    virtual void vf_040();
    virtual void vf_044();
    virtual void vf_048();
    virtual void vf_04C();
    virtual void vf_050();
    virtual void vf_054();
    virtual void vf_058();
    virtual void vf_05C();
    virtual void vf_060();
    virtual void vf_064();
    virtual void vf_068();
    virtual void vf_06C();
    virtual void vf_070();
    virtual void vf_074();
    virtual void vf_078();
    virtual void vf_07C();
    virtual void vf_080();
    virtual void vf_084();
    virtual void vf_088();
    virtual void vf_08C();
    virtual void vf_090();
    virtual void vf_094();
    virtual void vf_098();
    virtual void vf_09C();
    virtual void vf_0A0();
    virtual void vf_0A4();
    virtual void vf_0A8();
    virtual void vf_0AC();
    virtual void vf_0B0();
    virtual void vf_0B4();
    virtual void vf_0B8();
    virtual void vf_0BC();
    virtual void vf_0C0();
    virtual void vf_0C4(int a, int b);
    virtual void vf_0C8();
    virtual void vf_0CC();
    virtual void vf_0D0();
    virtual void vf_0D4();
    virtual void vf_0D8();
    virtual void vf_0DC();
    virtual void vf_0E0();
    virtual void set_ideal_size(long width, long height);

    void set_curr_child(TPanel* child);
    void set_tab_order(TPanel** panels, short count);
    char* get_string(int id);

    char gap_04[0x3C];
};

class TTextPanel : public TPanel {
public:
    virtual void setText(char* text);
    virtual void textExtra(int a, int b, int c, int d, int e, int f, int g);
    void set_alignment(int horizontal, int vertical);
    void set_text_color(int color, int flags);
};

class TButtonPanel : public TPanel {
public:
    char gap_40[0x258];
    int hotkey;                              // +0x298
    int hotkey_shift;                        // +0x29C
};

class TScrollBarPanel : public TPanel {
};

class TEasy_Panel : public TPanel {
public:
    virtual void set_ideal_size(long width, long height);
    virtual int create_button(TPanel* parent, TButtonPanel** out, int lang,
                              int a4, int x, int y, int w, int h,
                              int font, int center_h, int center_v);
    virtual int create_button(TPanel* parent, TButtonPanel** out, char* lang,
                              char* a4, int x, int y, int w, int h,
                              int font, int center_h, int center_v);
    virtual int create_check_box(TPanel* parent, TButtonPanel** out, int lang,
                                 int a4, int x, int y, int w, int h, int font);
    virtual int create_radio_button(TPanel* parent, TButtonPanel** out, int lang,
                                    int a4, int x, int y, int w, int h, int font);
    virtual int create_text(TPanel* parent, TTextPanel** out, int lang,
                            int x, int y, int w, int h, int font,
                            int center_h, int center_v, int word_wrap);
    virtual int create_text(TPanel* parent, TTextPanel** out, char** lang,
                            int x, int y, int w, int h, int font,
                            int center_h, int center_v, int word_wrap);
    virtual int create_text(TPanel* parent, TTextPanel** out, char* text,
                            int x, int y, int w, int h, int font,
                            int center_h, int center_v, int word_wrap);
    virtual int create_input(TPanel* parent, void* out, char* text, short width,
                             int format, int x, int y, int w, int h, int font);
    virtual int create_edit(TPanel* parent, void* out, char* text, short width,
                            int format, int x, int y, int w, int h, int font,
                            int a, int b);
    virtual int create_drop_down(TPanel* parent, void* out, int lang, int a4,
                                 int x, int y, int w, int h, int font);
    virtual int create_list(TPanel* parent, void* out, int x, int font,
                            int w, int h, int lines);
    virtual int create_scrollbar(TPanel* parent, void* out, TTextPanel* text,
                                 int x, int y, int w, int h, int font);
    virtual int create_auto_scrollbar(TScrollBarPanel** out, TTextPanel* text,
                                      int param);
    virtual int create_vert_slider(TPanel* parent, void* out, int x, int y,
                                   int w, int h, int a, int b, int c);
    virtual int create_horz_slider(TPanel* parent, void* out, int x, int y,
                                   int w, int h, int a, int b, int c);
    virtual void position_panel(TPanel* panel, int x, int y, int w, int h);

    char gap_40[0x98];
    int field_D8;                            // +0xD8
    char gap_DC[0x240];
    int field_31C;                           // +0x31C
    unsigned char desc[6];                    // +0x320
    char gap_326[0x14E];
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(char* name);
    virtual ~TScreenPanel();
    int setup(TDrawArea* draw_area, char* info_file, long info_id, int param);
    char gap_474[4];
};

class Time_Line_Panel : public TEasy_Panel {
public:
    long create_timeline(TPanel* parent, Time_Line_Panel** out,
                         long x, long y, long w, long h, long font,
                         long a, long b, long c);
    void set_bevel_info(int type, int c1, int c2, int c3, int c4, int c5, int c6);
    int set_special_events(char* name);
};

class TShape {
public:
    char gap_00[0x20];
    TShape(char* name, int id);
};

class RGE_Civilization {
public:
    char gap_00[0x26];
    short color;
};

class RGE_Player {
public:
    char gap_00[0x44];
    char* name;                              // +0x44
    char gap_48[0x38];
    unsigned char game_status;               // +0x80
    char gap_81[0x87];
    RGE_Civilization* civilization;          // +0x108
};

class RGE_Scenario {
public:
    char* Get_scenario_name();
    char* Get_message(long id);
};

class RGE_Game_World {
public:
    char gap_00[4];
    unsigned long world_time;                // +0x04
    char gap_08[0x34];
    short player_num;                         // +0x3C
    char gap_3E[2];
    RGE_Player** players;                     // +0x40
    char gap_44[0x18];
    RGE_Scenario* scenario;                   // +0x5C
};

class RGE_Base_Game {
public:
    char gap_00[0x4C];
    TDrawArea* draw_area;                     // +0x4C
    char gap_50[0x3A4];
    RGE_Game_World* world;                    // +0x3F4

    RGE_Player* get_player();
    int singlePlayerGame();
};

extern RGE_Base_Game* rge_base_game;

class TribeAchievementsScreen : public TScreenPanel {
public:
    int end_game_flag;                        // +0x478
    int current_mode;                         // +0x47C
    int size;                                  // +0x480
    TTextPanel* title;                         // +0x484
    TTextPanel* summary_text;                 // +0x488
    TTextPanel* instruction;                  // +0x48C
    TTextPanel* win_loss_text;                // +0x490
    TTextPanel* time;                         // +0x494
    TTextPanel* title_bar[7];                 // +0x498
    TTextPanel* achievement_choice[5];        // +0x4B4
    TTextPanel* statistics[8][7];             // +0x4C8
    TTextPanel* player_names[8];              // +0x5A8
    TScrollBarPanel* summary_text_bar;        // +0x5C8
    TScrollBarPanel* instruction_bar;         // +0x5CC
    TScrollBarPanel* win_loss_text_bar;       // +0x5D0
    TButtonPanel* okButton;                   // +0x5D4
    TButtonPanel* backButton;                 // +0x5D8
    TButtonPanel* backButton2;                // +0x5DC
    TButtonPanel* timelineButton;             // +0x5E0
    TButtonPanel* aftermathButton;            // +0x5E4
    TButtonPanel* restartButton;              // +0x5E8
    TButtonPanel* close_button;               // +0x5EC
    TShape* win_decal;                         // +0x5F0
    Time_Line_Panel* time_line;               // +0x5F4

    TribeAchievementsScreen(char* title_text, int end_game_flag);
    virtual ~TribeAchievementsScreen();
    void set_mode(int mode);
};

TribeAchievementsScreen::TribeAchievementsScreen(char* title_text, int end_game_flag)
    : TScreenPanel("Achievements Screen")
{
    unsigned long color;
    int local_1dc;
    TPanel* tabList[8];
    char temptxt[50];
    char str[100];
    char info_file[260];

    memset(temptxt + 35, 0, 15);
    this->title = 0;
    this->time = 0;
    this->summary_text = 0;
    this->win_loss_text = 0;
    this->instruction = 0;
    this->time_line = 0;
    this->okButton = 0;
    this->timelineButton = 0;
    this->restartButton = 0;
    this->aftermathButton = 0;
    this->backButton = 0;
    this->backButton2 = 0;
    this->win_decal = 0;
    this->close_button = 0;
    this->instruction_bar = 0;
    this->win_loss_text_bar = 0;
    this->summary_text_bar = 0;
    str[1] = 0;
    this->end_game_flag = end_game_flag;

    this->achievement_choice[0] = 0;
    this->achievement_choice[1] = 0;
    this->achievement_choice[2] = 0;
    this->achievement_choice[3] = 0;
    this->achievement_choice[4] = 0;

    memset(this->title_bar, 0, sizeof(this->title_bar));
    TTextPanel** statistics = this->statistics[0];
    TTextPanel** player_names = this->player_names;
    int player_count = 8;
    do {
        *player_names = 0;
        int statistic_count = 7;
        do {
            *statistics = 0;
            ++statistics;
            --statistic_count;
        } while (statistic_count != 0);
        ++player_names;
        --player_count;
    } while (player_count != 0);

    long info_id;
    if (this->end_game_flag == 0) {
        strcpy(info_file, "scr10");
        info_id = 0xC38D;
    } else {
        RGE_Player* player = rge_base_game->get_player();
        if (player->game_status == 1) {
            strcpy(info_file, "scr7");
            info_id = 0xC389;
        } else {
            strcpy(info_file, "scr8");
            info_id = 0xC38A;
        }
    }
    if (setup(rge_base_game->draw_area, info_file, info_id, 1) == 0) {
        this->field_D8 = 1;
        return;
    }

    set_ideal_size(0x280, 0x1E0);

    long minutes = 0;
    long hours = 0;
    long seconds = rge_base_game->world->world_time / 1000;
    if (seconds > 0x3B) {
        minutes = seconds / 60;
        seconds -= minutes * 60;
        if (minutes > 0x3B) {
            hours = minutes / 60;
            minutes -= hours * 60;
        }
    }
    sprintf(str, "%02ld:%02ld:%02ld", hours, minutes, seconds);

    create_text(this, &this->time, str + 4, 0x1E0, 10, 0x6E, 0x14, 0x0B, 0, 0, 0);
    this->time->set_alignment(2, 3);
    create_text(this, &this->title, 0x269E, 0, 5, 0x280, 0x1E, 1, 1, 0, 0);
    create_text(this, &this->summary_text, 0, 10, 0x23, 0x26C, 0x1E, 1, 1, 0, 0);
    create_text(this, &this->instruction, 0x26DB, 10, 0x19A, 0x26C, 0x14, 0x0B, 1, 0, 0);

    if (this->end_game_flag != 0) {
        RGE_Player* player = rge_base_game->get_player();
        char* message;
        if (player->game_status == 1) {
            message = rge_base_game->world->scenario->Get_message(2);
        } else {
            message = rge_base_game->world->scenario->Get_message(3);
        }
        if (message != 0 && message[0] != 0) {
            create_text(this, &this->win_loss_text, message, 10, 0x55,
                        0x26C, 0x14A, 0x0B, 0, 0, 1);
            if (this->win_loss_text != 0) {
                create_auto_scrollbar(&this->win_loss_text_bar,
                                      this->win_loss_text, 0x14);
                this->win_loss_text->textExtra(4, desc[0], desc[1], desc[2],
                                               desc[3], desc[4], desc[5]);
                this->win_loss_text->setText(message);
            }
        }
    }

    this->time_line->create_timeline(this, &this->time_line, 10, 0x55,
                                     0x26C, 0x14A, 0x0B, 9, 0x280, 0x1E0);
    this->time_line->set_bevel_info(3, desc[0], desc[1], desc[2], desc[3],
                                    desc[4], desc[5]);
    this->time_line->set_special_events("timeline.slp");

    if (create_button(this, &this->close_button, 0x3EA, 0, 0, 0, 0, 0, 0, -1, -1) == 0) {
        return;
    }
    this->close_button->set_active(1);
    this->close_button->vf_018(9, 4, 4, 4, 4, 0x11, 0x11, 0x11);

    create_text(this, this->title_bar, 0, 0x62, 0x97, 200, 0x1E, 0x0B, 0, 0, 0);
    create_text(this, this->title_bar + 1, 0, 0x98, 0x83, 200, 0x1E, 0x0B, 0, 0, 0);
    create_text(this, this->title_bar + 2, 0, 0xD4, 0x6F, 0x91, 0x1E, 0x0B, 0, 0, 0);
    create_text(this, this->title_bar + 3, 0, 0x104, 0x5B, 200, 0x1E, 0x0B, 1, 0, 0);
    create_text(this, this->title_bar + 4, 0, 0x16C, 0x6F, 0x91, 0x1E, 0x0B, 0, 0, 0);
    create_text(this, this->title_bar + 5, 0, 0x172, 0x83, 200, 0x1E, 0x0B, 0, 0, 0);
    create_text(this, this->title_bar + 6, 0, 0x1A8, 0x97, 200, 0x1E, 0x0B, 0, 0, 0);
    this->title_bar[4]->set_alignment(2, 3);
    this->title_bar[5]->set_alignment(2, 3);
    this->title_bar[6]->set_alignment(2, 3);

    create_text(this, this->achievement_choice, 0, 100, 0x97, 0x82, 0xFA, 0x0B, 0, 0, 0);
    create_text(this, this->achievement_choice + 1, 0, 0x9A, 0x83, 0x80, 0x112, 0x0B, 0, 0, 0);
    create_text(this, this->achievement_choice + 2, 0, 0xD6, 0x6F, 0x79, 0x121, 0x0B, 0, 0, 0);
    create_text(this, this->achievement_choice + 3, 0, 0x11A, 0x5B, 0x9C, 0x135, 0x0B, 0, 0, 0);
    create_text(this, this->achievement_choice + 4, 0, 0x184, 0x6F, 0x79, 0x121, 0x0B, 0, 0, 0);

    TTextPanel** player_name = this->player_names;
    TTextPanel** row = this->statistics[0] + 2;
    int player_offset = 4;
    int y = 0xAB;
    int player_index = 1;
    // BINARY NOTE: The shipped loop compares the decremented index with 8.
    do {
        char* name;
        if (player_index < rge_base_game->world->player_num) {
            RGE_Player* named_player = *(RGE_Player**)((char*)rge_base_game->world->players + player_offset);
            name = named_player->name;
        } else {
            name = 0;
        }
        create_text(this, player_name, name, 0x16, y, 0x96, 0x1D,
                    0x0B, 0, 1, 0);
        create_text(this, row - 2, 0, 0xB2, y, 0x33, 0x1D, 0x0B, 1, 1, 0);
        create_text(this, row - 1, 0, 0xE7, y, 0x33, 0x1D, 0x0B, 1, 1, 0);
        create_text(this, row,     0, 0x11B, y, 0x33, 0x1D, 0x0B, 1, 1, 0);
        create_text(this, row + 1, 0, 0x150, y, 0x33, 0x1D, 0x0B, 1, 1, 0);
        create_text(this, row + 2, 0, 0x185, y, 0x33, 0x1D, 0x0B, 1, 1, 0);
        create_text(this, row + 3, 0, 0x1BA, y, 0x33, 0x1D, 0x0B, 1, 1, 0);
        create_text(this, row + 4, 0, 0x1EE, y, 0x33, 0x1D, 0x0B, 1, 1, 0);

        if (player_index < rge_base_game->world->player_num) {
            RGE_Player* player = *(RGE_Player**)((char*)rge_base_game->world->players + player_offset);
            switch (player->civilization->color) {
            case 0: color = 0xC40000; break;
            case 1: color = 200; break;
            case 2: color = 0xEAEA; break;
            case 3: color = 0x215A8C; break;
            case 4: color = 0x80FF; break;
            case 5: color = 0x8000; break;
            case 6: color = 0x808080; break;
            case 7: color = 0x808040; break;
            default: color = 0xFFFFFF; break;
            }
            player_name[0]->set_text_color(color, 0);
            TTextPanel** colored = row - 2;
            int color_count = 7;
            do {
                colored[0]->set_text_color(color, 0);
                ++colored;
                --color_count;
            } while (color_count != 0);
        }

        y += 0x1E;
        player_offset += 4;
        ++player_name;
        row += 7;
        ++player_index;
    } while (player_index <= 8);

    long ok_x;
    long ok_width;
    // BINARY NOTE: The shipped layout tests the non-null message arm first.
    if (this->end_game_flag == 0 || rge_base_game->singlePlayerGame() == 0) {
        create_button(this, &this->timelineButton, 0x26D8, 0, 100, 0x1B9,
                      200, 0x1E, 0, 0, 0);
        ok_width = 200;
        ok_x = 0x154;
    } else if (this->win_loss_text != 0) {
        create_button(this, &this->aftermathButton, 0x26B2, 0, 5, 0x1B9,
                      0x96, 0x1E, 0, 0, 0);
        create_button(this, &this->timelineButton, 0x26D8, 0, 0xA5, 0x1B9,
                      0x96, 0x1E, 0, 0, 0);
        create_button(this, &this->restartButton, 0x269F, 0, 0x145, 0x1B9,
                      0x96, 0x1E, 0, 0, 0);
        ok_width = 0x96;
        ok_x = 0x1E5;
    } else {
        create_button(this, &this->timelineButton, 0x26D8, 0, 0x14, 0x1B9,
                      0xB4, 0x1E, 0, 0, 0);
        create_button(this, &this->restartButton, 0x269F, 0, 0xE6, 0x1B9,
                      0xB4, 0x1E, 0, 0, 0);
        ok_width = 0xB4;
        ok_x = 0x1B8;
    }

    create_button(this, &this->okButton, 0x269C, 0, ok_x, 0x1B9,
                  ok_width, 0x1E, 0, 0, 0);
    create_button(this, &this->backButton, 0x26DA, 0, 200, 0x1B9,
                  0xF0, 0x1E, 0, 0, 0);
    this->backButton->set_active(0);
    this->backButton->hotkey = 0x1B;
    this->backButton->hotkey_shift = 0;

    create_button(this, &this->backButton2, 0x269C, 0, 200, 0x1B9,
                  0xF0, 0x1E, 0, 0, 0);
    this->backButton2->set_active(0);
    this->backButton2->hotkey = 0x1B;
    this->backButton2->hotkey_shift = 0;
    this->okButton->hotkey = 0x1B;
    this->okButton->hotkey_shift = 0;

    RGE_Player* player = rge_base_game->get_player();
    if (player->game_status == 1) {
        this->win_decal = new TShape("viccheck.slp", 0xCB21);
    } else {
        this->win_decal = new TShape("defcheck.slp", 0xCB22);
    }

    local_1dc = 0;
    if (this->aftermathButton != 0) {
        tabList[local_1dc++] = this->aftermathButton;
    }
    if (this->timelineButton != 0) {
        tabList[local_1dc++] = this->timelineButton;
    }
    if (this->restartButton != 0) {
        tabList[local_1dc++] = this->restartButton;
    }
    tabList[local_1dc++] = this->okButton;
    set_tab_order(tabList, (short)local_1dc);
    set_curr_child(this->okButton);
    this->backButton->vf_0C4(0, 0);
    this->backButton2->vf_0C4(0, 0);

    if (this->win_loss_text != 0) {
        set_mode(5);
    } else {
        set_mode(0);
    }
}
