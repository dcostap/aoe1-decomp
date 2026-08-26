// TribeSendQuickMessageDialog::action
// VA: 004416C0
//
// Canonical reconstruction of the quick-message send/close handler.  The
// panel, game, world, and communications calls below are the period member
// surfaces evidenced by dlg_smsg.cpp; no address-based call shims are used.
//
// Attempt log:
// - Replaced the decompiler-shaped fastcall/raw-address scaffold with the
//   typed dialog, panel-system, game, edit-panel, screen, and communications
//   surfaces suggested by the same-TU packet and exact donors.
// - A single shared base_action fallback removed the extra direct action call
//   from the first natural pass.
// - Positive multiplayer ordering restored the original group-send-before-
//   single-player call-site layout.  Moving the success tail after the close
//   path reproduced the late process/prog/close convergence; final result is
//   an exact 373-byte body with all 13 ordered calls and the 0x44 frame.

#include <string.h>

#ifdef DLG_SMSG_CANONICAL_TU
#include "../../include/dlg_smsg_context.h"
#else
class TPanel {
public:
    virtual ~TPanel();
    char gap_04[0x3C];
    TPanel* parent_panel; // +0x40
};

class TEditPanel : public TPanel {
public:
    virtual ~TEditPanel();
    char* currentLine();
};

class TEasy_Panel : public TPanel {
public:
    char gap_44[0x434];
    virtual ~TEasy_Panel();
    long action(TPanel* panel, long code, unsigned long a, unsigned long b);
};

class TDialogPanel : public TEasy_Panel {
public:
    char gap_478[0x18];
    virtual ~TDialogPanel();
};

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int mode);
    int destroyPanel(char* name);
};

class RGE_Game_World {
public:
    virtual unsigned char data_load_world(void* file);
    char gap_04[0x78];
    short curr_player; // +0x7C
};

class RGE_Scenario;
class RGE_Scenario_Header;

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
    virtual void language(int, int, int, char*, int);
    virtual TPanel* get_view_panel();
    virtual TPanel* get_map_panel();
    virtual RGE_Scenario_Header* new_scenario_header(RGE_Scenario*);
    virtual RGE_Scenario_Header* new_scenario_header(int);
    virtual RGE_Scenario* new_scenario_info(int);
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
};

class TCommunications_Handler {
public:
    void SendGroupChatMsg(char* text);
};

class TRIBE_Screen_Game {
public:
    void display_system_message(char* text);
};

extern TPanelSystem panel_system;
extern RGE_Base_Game* rge_base_game;
extern TCommunications_Handler* comm;

class TribeSendQuickMessageDialog : public TDialogPanel {
public:
    TEditPanel* chatInput; // +0x490
    char gap_494[0x0C];

    virtual long action(TPanel* panel, long code, unsigned long a,
                        unsigned long b);
};
#endif

long TribeSendQuickMessageDialog::action(TPanel* panel, long code,
                                         unsigned long a, unsigned long b)
{
    char save_msg[66];

    if (panel != 0 && panel == this->chatInput) {
        if (code == 0) {
            char* line = this->chatInput->currentLine();
            if (line != 0 && *this->chatInput->currentLine() != 0) {
                TRIBE_Screen_Game* screen =
                    (TRIBE_Screen_Game*)this->parent_panel;
                strcpy(save_msg, this->chatInput->currentLine());

                panel_system.setCurrentPanel("Game Screen", 0);
                panel_system.destroyPanel("Send Quick Message Dialog");

                if (rge_base_game->processCheatCode(
                        (int)rge_base_game->world->curr_player, save_msg) != 0)
                    goto success;

                if (rge_base_game->multiplayerGame() != 0) {
                    if (rge_base_game->prog_mode == 5)
                        goto success;
                    comm->SendGroupChatMsg(save_msg);
                    return 1;
                }

                rge_base_game->play_sound(2);
                screen->display_system_message(save_msg);
                return 1;
            }
        }
        else if (code != 1)
            goto base_action;

        panel_system.setCurrentPanel("Game Screen", 0);
        panel_system.destroyPanel("Send Quick Message Dialog");
        goto success;
    }

    goto base_action;

success:
    return 1;

base_action:
    return TEasy_Panel::action(panel, code, a, b);
}
