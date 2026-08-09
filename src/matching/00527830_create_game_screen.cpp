// VA: 00527830 TRIBE_Game::create_game_screen (576 B)
// PDB source: tribegam.cpp:3703-3767
// FLAGS: config/flags/00527830_create_game_screen.rsp (/GX for the original
// constructor/EH state machine)
//
// Attempt log:
// - Replaced the allocation-only scaffold with the natural typed screen
//   construction, multiplayer wait path, panel cleanup, and world failure
//   cleanup shown by the packet and same-TU screen donors.
// - Exact after using the late nonzero MultiplayerGameStart arm and a
//   function-level compound screen/error guard; this preserves both distinct
//   deleting-destructor paths and the original wait-failure store order.

class TCommunications_Handler {
public:
    int MultiplayerGameStart();
};

class RGE_Game_World {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual ~RGE_Game_World();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
    virtual void vfB4();
    virtual void del_game_info();
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual void vf04();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int mode);
    virtual void set_game_mode(int mode, int update);

    char gap_04[0x188];
    TCommunications_Handler* comm_handler; // +0x18C
    char gap_190[0x20];
    int prog_mode; // +0x1B0
    char gap_1B4[0x240];
    RGE_Game_World* world; // +0x3F4
    char gap_3F8[0x62C];

    void disable_input();
    void enable_input();
};

class TPanel {
public:
    virtual ~TPanel();

    char gap_04[0xD4];
    int error_code; // +0xD8
};

class TScreenPanel : public TPanel {
public:
    char gap_DC[0x39C];
};

class TRIBE_Screen_Game : public TScreenPanel {
public:
    char gap_478[0x34C];
    virtual ~TRIBE_Screen_Game();
    TRIBE_Screen_Game();
};

class TRIBE_Screen_Wait : public TScreenPanel {
public:
    char gap_478[0x60];
    virtual ~TRIBE_Screen_Wait();
    TRIBE_Screen_Wait();
    void set_text(long string_id);
};

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int mode);
    int destroyPanel(char* name);
};

extern TPanelSystem panel_system;

class TRIBE_Game : public RGE_Base_Game {
public:
    char gap_A24[0x200];
    TRIBE_Screen_Game* game_screen; // +0xC24

    int create_game_screen();
    void close_status_message();
    void let_game_begin();
};

int TRIBE_Game::create_game_screen()
{
    TRIBE_Screen_Game* screen;

    this->disable_input();
    this->set_game_mode(0, 0);

    screen = new TRIBE_Screen_Game;
    this->game_screen = screen;

    if (screen != 0 && screen->error_code == 0) {
            if (this->comm_handler->MultiplayerGameStart() == 0) {
                TRIBE_Screen_Wait* wait = new TRIBE_Screen_Wait;
                if (wait != 0) {
                    wait->set_text(0x454);
                    panel_system.setCurrentPanel("Multiplayer Wait Screen", 0);
                    panel_system.destroyPanel("Status Screen");
                    this->set_prog_mode(3);
                    goto create_game_screen_common;
                }

                if (this->game_screen != 0) {
                    delete this->game_screen;
                }
                RGE_Game_World* world = this->world;
                this->game_screen = 0;
                world->del_game_info();
                goto create_game_screen_failed;
            }

            panel_system.setCurrentPanel("Game Screen", 0);
            panel_system.destroyPanel("Status Screen");

create_game_screen_common:
            panel_system.destroyPanel("Single Player Menu");
            panel_system.destroyPanel("Game Setup Screen");
            panel_system.destroyPanel("Select Scenario Screen");
            panel_system.destroyPanel("Game Settings Screen");
            panel_system.destroyPanel("Load Saved Game Screen");
            panel_system.destroyPanel("MP Setup Screen");
            panel_system.destroyPanel("Join Screen");
            panel_system.destroyPanel("MP Startup Screen");
            panel_system.destroyPanel("Main Menu");
            panel_system.destroyPanel("Campaign Selection Screen");
            if (this->prog_mode != 3) {
                this->let_game_begin();
            }
            return 1;
    }

    if (this->game_screen != 0) {
        delete this->game_screen;
        this->game_screen = 0;
    }

    this->world->del_game_info();

create_game_screen_failed:
    this->close_status_message();
    this->enable_input();
    return 0;
}
