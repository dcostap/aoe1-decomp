// 00529A70 TRIBE_Game::action_user_command
// tribegam.cpp:5115-5280
//
// Attempt log:
// - baseline: the old scratch used unrelated panel/chat helpers and missed
//   most of the packet calls.  Rebuilt the dispatcher from the source bands.
// - behavior: restored the reset-communications drop path, game-over path,
//   sync-save path, chat-received path, and player communication warning.
//   The fields remain named through the period base-game, world, and screen
//   surfaces.
// - control-flow: packet source-line order for the second switch and an
//   explicit shared drop-popup tail recovered all 49 calls and 1135 bytes.
// - ABI/layout: world +0x58 owns the command object, RGE_Player::name is
//   +0x44, and WhoAmI(param2)/IsPlayerOutOfSync(player) are overloaded calls.
// - layout: temp_str is 260 bytes because get_string writes 0x100 bytes at
//   temp_str + 4.  This restores the oracle's 0x208 frame.
// - layout: msg[260] or msg[252] changed the frame or moved temp_str; the
//   period-plausible msg[256]/temp_str[260] pair is the stable layout.
// - behavior: save_game uses the msg base.  The matching source uses msg as
//   the output buffer; the old msg + 4 forms were decompiler stack aliases.
// - exact: natural msg-base uses match all 1135 bytes, 49 calls, and the EH
//   frame under /GX.

extern "C" int __cdecl sprintf(char*, const char*, ...);

extern int do_debug_random;
extern int out_of_sync;
extern int out_of_sync2;
extern int player_dropped[9];
extern void debug_random_write();
extern void dump_vismap_log();

class TDebuggingLog {
public:
    void __cdecl Log(char*, ...);
};

extern TDebuggingLog* L;

class RGE_Player {
public:
    virtual void vf00();
    virtual void set_game_status(unsigned char);
    char gap_08[0x40];
    char* name; // +0x44

    void loss_if_game_on();
};

class TRIBE_Command;

class RGE_Game_World {
public:
    char gap_00[0x40];
    RGE_Player** players; // +0x40
    char gap_44[0x14];
    TRIBE_Command* commands; // +0x58
    char gap_5C[0x20];
    short player_number; // +0x7C
};

class TRIBE_Command {
public:
    void command_save_game();
};

class TCommunications_Handler {
public:
    char gap_00[0x58];
    TRIBE_Command* command; // +0x58

    int IsHost();
    int WhoAmI();
    int WhoAmI(int);
    int IsPlayerOutOfSync(int);
};

class TEasy_Panel {
public:
    void popupOKDialog(int, char*, int, int);
};

class TPanelSystem {
public:
    int destroyPanel(char*);
    TEasy_Panel* currentPanel();
    int setCurrentPanel(char*, int);
};

extern TPanelSystem panel_system;

class TRIBE_Screen_Game {
public:
    void handle_pause();
    void handle_resume();
    void display_system_message(char*);
    void handleChatReceived(int);
};

class TScreenPanel {
public:
    virtual ~TScreenPanel();
};

class TRIBE_Screen_Status_Message : public TScreenPanel {
public:
    char gap_04[0x478];

    TRIBE_Screen_Status_Message(char*, char*, char*, long);
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

    char gap_04[0x188];
    TCommunications_Handler* comm_handler; // +0x18C
    char gap_190[0x20];
    int prog_mode; // +0x1B0
    char gap_1B4[0x240];
    RGE_Game_World* world; // +0x3F4
    char gap_3F8[0x62C];

    void setSinglePlayerGame(int);
    int play_sound(int);
    unsigned char check_prog_argument(char*);
    int playerID(int);
};

class TRIBE_Game : public RGE_Base_Game {
public:
    char gap_A24[0x200];
    TRIBE_Screen_Game* game_screen; // +0xC24

    virtual int action_user_command(unsigned long, unsigned long);
    void quit_game();
    void close_game_screens(int);
    int save_game(char*);
    void do_game_over();
};

int TRIBE_Game::action_user_command(unsigned long param_1,
                                    unsigned long param_2)
{
    char msg[256];
    char temp_str[260];
    TEasy_Panel* panel;
    int player;

    if (this->prog_mode == 3) {
        switch (param_1) {
        case 0x17a8:
        case 0x17a9:
        case 0x17aa:
        case 0x17ab:
        case 0x17b2:
        case 0x17b6:
            this->quit_game();
            panel_system.destroyPanel("Multiplayer Wait Screen");
            panel_system.destroyPanel("Status Screen");
            panel = panel_system.currentPanel();
            if (panel == 0) {
                break;
            }
            goto dropped_from_game;

        case 0x17ac:
        case 0x17b7:
            this->reset_comm();
            this->setSinglePlayerGame(1);
            this->quit_game();
            panel_system.destroyPanel("Multiplayer Wait Screen");
            panel_system.destroyPanel("Status Screen");
            panel = panel_system.currentPanel();
            if (panel == 0) {
                break;
            }
        dropped_from_game:
            panel->popupOKDialog(0x25c9, 0, 0x1c2, 100);
            break;
        }
    } else if (this->prog_mode == 4 || this->prog_mode == 6 ||
               this->prog_mode == 5) {
        switch (param_1) {
        case 0x17b2:
            if (this->game_screen == 0) {
                break;
            }
            this->world->players[this->world->player_number]
                ->loss_if_game_on();
            this->do_game_over();
            panel = panel_system.currentPanel();
            if (panel != 0) {
                panel->popupOKDialog(0x25c9, 0, 0x1c2, 100);
            }
            break;

        case 0x17b0:
            if (this->game_screen != 0) {
                this->play_sound(2);
                this->game_screen->display_system_message(
                    "Out of sync detected by communications.");
            }
            if (this->check_prog_argument("SKIPSYNCSAVE") == 0) {
                if (out_of_sync == 0) {
                    out_of_sync = 1;
                    if (this->comm_handler->IsHost() != 0) {
                        this->world->commands->command_save_game();
                    }
                }
            } else if (out_of_sync == 0) {
                player = this->comm_handler->WhoAmI(param_2);
                if (this->comm_handler->IsPlayerOutOfSync(player) != 0) {
                    out_of_sync = 1;
                    out_of_sync2 = 1;
                    new TRIBE_Screen_Status_Message(
                        "Temp Screen", "", (char*)0, -1);
                    panel_system.setCurrentPanel("Temp Screen", 0);
                    this->close_game_screens(1);
                    if (do_debug_random != 0) {
                        debug_random_write();
                        dump_vismap_log();
                    }
                    player = this->comm_handler->WhoAmI();
                    sprintf(msg, "syncerr%d.gam", player);
                    this->save_game(msg);
                    this->world->players[this->world->player_number]
                        ->loss_if_game_on();
                    this->do_game_over();
                    panel = panel_system.currentPanel();
                    if (panel != 0) {
                        panel->popupOKDialog(0x966, 0, 0x1c2, 100);
                    }
                    panel_system.destroyPanel("Temp Screen");
                }
            }
            break;

        case 0x17a2:
            if (this->game_screen != 0) {
                this->game_screen->handle_pause();
            }
            break;

        case 0x17a3:
            if (this->game_screen != 0) {
                this->game_screen->handle_resume();
            }
            break;

        case 0x17d5:
            if (this->game_screen != 0) {
                this->play_sound(2);
                this->game_screen->handleChatReceived(param_2);
            }
            break;

        case 0x17bd:
        {
            player = this->playerID(param_2);
            if (player != this->world->player_number &&
                this->game_screen != 0 &&
                this->playerID(param_2) > 0 && player_dropped[param_2] == 0) {
                this->play_sound(2);
                this->get_string(0x4c1, temp_str + 4, 0x100);
                player = this->playerID(param_2);
                sprintf(msg, temp_str + 4,
                        this->world->players[player]->name);
                this->game_screen->display_system_message(msg);
                player = this->playerID(param_2);
                L->Log("$$$ PROBLEM COMMUNICATING WITH %s",
                       this->world->players[player]->name);
            }
            break;
        }
        }
    }

    return 1;
}
