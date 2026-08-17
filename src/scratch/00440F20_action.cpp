// TribeSendMessageDialog::action
// VA: 00440F20
// PDB source: dlg_smsg.cpp
//
// Attempt log:
// - Rebuilt the decompiler-shaped fastcall/raw-address attempt around the
//   typed dialog, panel, game/world/player, communications, and debug-log
//   surfaces evidenced by dlg_smsg.cpp and exact same-TU donors.
// - Delayed the check-button pointer until dispatch and changed the null
//   fallback to a natural outer non-null guard; this restored the original
//   prologue/CFG family and the 0x44 frame.
// - A diagnostic cross-member check[22] cursor restored the original register
//   topology and reached 174 differing bytes, but was normalized back to
//   direct checkButton[i]/commPlayers[i] ownership for living source.
// - Direct named checkButton members restored the original eight compare
//   encodings. An explicit radioButton[3] branch produced 154 bytes but added
//   four entry-reachable bytes beyond the original boundary, so it is not kept.
// - A volatile radio-button array plus a no-effect radioButton[3] expression
//   produced exact bytes. Main review rejected both codegen-only forms. The
//   natural array and generic checkButtons tail remain authoritative.
// - A nonvolatile standalone radioButton[3] expression was optimized away;
//   it did not restore the binary's late load or sixth checkButtons call.
// - Policy rerun removed volatile, the no-effect read, and all generic virtual
//   placeholders. Named TPanel, RGE_Base_Game, and RGE_Player donors are now
//   used. They emit the same clean 174-byte mismatch.
// - A natural duplicate checkButtons call for the radioButton[2] fallback was
//   tested. VC5 merges the two calls and keeps 41 of the original 42 calls.
// - Twenty policy-valid source and context hypotheses were tested in this
//   pass. Header context, guard polarity, parameter homes, and call layout did
//   not recover the late load.
// BINARY NOTE: the executable reads radioButton[3] before one checkButtons
//   call, but has no compare, call, store, or later use for that value.
// LIKELY INTENT: the radioButton[2] fallback and the default path were separate
//   source paths. The reason for the shipped field read is not proved.

#include <string.h>

class TDrawArea;
class TButtonPanel;
class TEditPanel;
class TTextPanel;
class TInputPanel;
class TDropDownPanel;
class TListPanel;
class TScrollBarPanel;
class TVerticalSliderPanel;
class THorizontalSliderPanel;
class TPanel;

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

typedef int PositionMode;
typedef int RedrawMode;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(PositionMode, long, long, long, long, long, long,
                                  long, long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(RedrawMode);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, RedrawMode);
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
    virtual void draw_background(int enabled);

    char gap_04[0x3C];
    TPanel* parent_panel; // +0x40
    char gap_44[0x14];
    int player_number; // +0x58, the dialog's per-button player id
    char gap_5C[0x98];
};

class TTextPanel : public TPanel {
};

class TEditPanel : public TTextPanel {
public:
    char* currentLine();
    void set_text(char* text);
};

class TButtonPanel : public TPanel {
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];
    void setup_popup_help();
};

class TDialogPanel : public TEasy_Panel {
public:
    char gap_478[0x18];
};

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int mode);
    int destroyPanel(char* name);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char);
    virtual void do_resign(int);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int mode);
    virtual int isEnemy(int player);
    virtual int isAlly(int player);

    char gap_04[0x46];
    short id; // +0x4A
};

class RGE_Game_World {
public:
    virtual unsigned char data_load_world(void* file);
    unsigned int world_time; // +0x04
    char gap_08[0x38];
    RGE_Player** players; // +0x40
    char gap_44[0x38];
    short curr_player; // +0x7C
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);
    virtual void set_player(short);
    virtual int get_error_code();
    virtual char* get_string(int, long, char*, int);
    virtual char* get_string(long, char*, int);
    virtual char* get_string(long);
    virtual char* get_string2(int, long, long, char*, int);
    virtual void* get_view_panel();
    virtual void* get_map_panel();
    virtual void* new_scenario_header(void*);
    virtual void* new_scenario_header(int);
    virtual void* new_scenario_info(int);
    virtual void notification(int, long, long, long, long);
    virtual int reset_comm();
    virtual void send_game_options();
    virtual void receive_game_options();
    virtual char* gameSummary();
    virtual int processCheatCode(int player, char* text);

    char gap_04[0x1AC];
    int prog_mode; // +0x1B0
    char gap_1B4[0x240];
    RGE_Game_World* world; // +0x3F4

    int multiplayerGame();
    int play_sound(int sound_id);
    int playerID(int player);
};

class TCommunications_Handler {
public:
    void SendGroupChatMsg(char* text);
};

class TDebuggingLog {
public:
    void Log(const char* format, ...);
};

class TRIBE_Screen_Game {
public:
    void display_system_message(char* text);
};

extern TPanelSystem panel_system;
extern RGE_Base_Game* rge_base_game;
extern TCommunications_Handler* comm;
extern TDebuggingLog* L;

class TribeSendMessageDialog : public TDialogPanel {
public:
    TTextPanel* title; // +0x490
    TTextPanel* playerName[8]; // +0x494
    TTextPanel* playerCivilization[8]; // +0x4B4
    TButtonPanel* checkButton[8]; // +0x4D4
    TTextPanel* radioTitle[4]; // +0x4F4
    TButtonPanel* radioButton[4]; // +0x504
    void* radioButtonShapes; // +0x514
    TEditPanel* chatInput; // +0x518
    TTextPanel* chatTitle; // +0x51C
    TButtonPanel* okButton; // +0x520
    TButtonPanel* help_button; // +0x524
    void* backgroundPics; // +0x528
    int commPlayers[8]; // +0x52C

    virtual long action(TPanel* panel, long code, unsigned long a,
                        unsigned long b);
    void checkButtons();
};

long TribeSendMessageDialog::action(TPanel* panel, long code,
                                    unsigned long a, unsigned long b)
{
    char save_msg[66];

    if (panel != 0) {
    if (panel == this->chatInput) {
        if (code == 0) {
            TRIBE_Screen_Game* screen =
                (TRIBE_Screen_Game*)this->parent_panel;

            if (this->chatInput->currentLine() == 0 ||
                *this->chatInput->currentLine() == 0)
                save_msg[0] = 0;
            else
                strcpy(save_msg, this->chatInput->currentLine());

            if (save_msg[0] == 0)
                goto done;

            if (rge_base_game->processCheatCode(
                    (int)rge_base_game->world->curr_player, save_msg) == 0) {
                if (rge_base_game->multiplayerGame() != 0) {
                    if (rge_base_game->prog_mode != 5) {
                        comm->SendGroupChatMsg(save_msg);
                        L->Log("$$$ SEND CHAT @%u: %s",
                               rge_base_game->world->world_time, save_msg);
                    }
                }
                else {
                    rge_base_game->play_sound(2);
                    screen->display_system_message(save_msg);
                }
            }

            this->chatInput->set_text("");
            return 1;
        }
    }

    else {
    if (panel == this->okButton) {
        if (code != 1)
            goto check_buttons_return;

        this->checkButtons();
        TRIBE_Screen_Game* screen =
            (TRIBE_Screen_Game*)this->parent_panel;

        if (this->chatInput->currentLine() == 0 ||
            *this->chatInput->currentLine() == 0)
            save_msg[0] = 0;
        else
            strcpy(save_msg, this->chatInput->currentLine());

        panel_system.setCurrentPanel("Game Screen", 0);
        panel_system.destroyPanel("Send Message Dialog");

        if (save_msg[0] == 0)
            goto done;

        if (rge_base_game->processCheatCode(
                (int)rge_base_game->world->curr_player, save_msg) != 0)
            goto done;

        if (rge_base_game->multiplayerGame() != 0) {
            if (rge_base_game->prog_mode == 5)
                goto done;
            comm->SendGroupChatMsg(save_msg);
            L->Log("$$$ SEND CHAT @%u: %s",
                   rge_base_game->world->world_time, save_msg);
            return 1;
        }

        rge_base_game->play_sound(2);
        screen->display_system_message(save_msg);
        return 1;
    }

    if (panel == this->help_button) {
        this->setup_popup_help();
        return 1;
    }

    if (panel == this->checkButton[0] ||
        panel == this->checkButton[1] ||
        panel == this->checkButton[2] ||
        panel == this->checkButton[3] ||
        panel == this->checkButton[4] ||
        panel == this->checkButton[5] ||
        panel == this->checkButton[6] ||
        panel == this->checkButton[7]) {
        this->radioButton[0]->draw_background(0);
        this->radioButton[1]->draw_background(0);
        this->radioButton[2]->draw_background(0);
        this->radioButton[3]->draw_background(1);
        goto check_buttons_return;
    }

    if (panel == this->radioButton[0]) {
        RGE_Player* player = rge_base_game->world->players[
            rge_base_game->world->curr_player];
        int i = 0;
        do {
            if (this->checkButton[i] != 0) {
                int player_id = rge_base_game->playerID(
                    this->commPlayers[i]);
                if (player_id == player->id || player->isAlly(player_id))
                    this->checkButton[i]->draw_background(1);
                else
                    this->checkButton[i]->draw_background(0);
            }
            ++i;
        } while (i < 8);
        this->checkButtons();
        return 1;
    }

    if (panel == this->radioButton[1]) {
        RGE_Player* player = rge_base_game->world->players[
            rge_base_game->world->curr_player];
        int i = 0;
        do {
            if (this->checkButton[i] != 0) {
                int player_id = rge_base_game->playerID(
                    this->commPlayers[i]);
                if (player_id == player->id || player->isEnemy(player_id) == 0)
                    this->checkButton[i]->draw_background(0);
                else
                    this->checkButton[i]->draw_background(1);
            }
            ++i;
        } while (i < 8);
        this->checkButtons();
        return 1;
    }

    if (panel == this->radioButton[2]) {
        if (code == 1) {
            int i = 0;
            do {
                if (this->checkButton[i] != 0)
                    this->checkButton[i]->draw_background(1);
                ++i;
            } while (i < 8);
            this->checkButtons();
            return 1;
        }
        this->checkButtons();
        return 1;
    }

    this->checkButtons();
    return 1;

check_buttons_return:
    this->checkButtons();
    }
done:
    return 1;
    }

    return TPanel::action(panel, code, a, b);
}
