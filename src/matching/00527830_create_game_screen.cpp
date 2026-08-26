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

#ifndef TRIBEGAM_TU_CONTEXT
struct RGE_Player_Info;
class RGE_Sound;
class TSound_Driver;
class TCommunications_Handler {
public:
    int MultiplayerGameStart();
};

class RGE_Game_World {
public:
    virtual unsigned char data_load_world(void* file);
    virtual unsigned char data_load_terrain_tables(char* name);
    virtual unsigned char data_load_players(char* name);
    virtual unsigned char data_load_objects(char* name);
    virtual unsigned char data_load_sounds(char* name);
    virtual unsigned char data_load_color_tables(char* name);
    virtual unsigned char data_load_sprites(char* name);
    virtual void data_load_players_type(short player, short type, void* file);
    virtual void data_load_effects(char* name);
    virtual void data_load_map(char* map, char* terrain, char* effect,
                               char* random, short width, short height,
                               short tile_set, RGE_Sound** sounds,
                               char* name);
    virtual void data_load_random_map(char* map, char* terrain,
                                      char* effect, char* random);
    virtual unsigned char init_player_type(int player, short type,
                                           unsigned char active);
    virtual unsigned char init_player(int player);
    virtual void load_player(int player, unsigned char type, short id);
    virtual void color_table_init(int table);
    virtual void terrain_tables_init(int table);
    virtual void init_sounds(int count, TSound_Driver* driver);
    virtual void init_sprites(int count);
    virtual void map_init(int count);
    virtual void effects_init(int count);
    virtual void master_player_init(int count);
    virtual void command_init(int count, TCommunications_Handler* comm);
    virtual void world_init(int count, TSound_Driver* driver,
                            TCommunications_Handler* comm);
    virtual void setup_gaia();
    virtual void setup_players(RGE_Player_Info& info);
    virtual unsigned char new_random_game(RGE_Player_Info& info);
    virtual void save(int file);
    virtual void scenario_make_player(short player, unsigned char active,
                                      unsigned char type, unsigned char civ,
                                      char* name);
    virtual void scenario_make_map(int map);
    virtual unsigned char load_scenario(char* name, RGE_Player_Info* info);
    virtual unsigned char load_scenario(RGE_Player_Info& info);
    virtual void load_scenario1(int player, RGE_Player_Info& info);
    virtual void load_scenario2(int player, RGE_Player_Info& info);
    virtual void load_scenario3(int player, RGE_Player_Info& info);
    virtual void load_scenario4(int player, RGE_Player_Info& info);
    virtual void load_scenario5(int player, RGE_Player_Info& info);
    virtual void load_scenario6(int player, RGE_Player_Info& info);
    virtual void load_scenario7(int player, RGE_Player_Info& info);
    virtual void load_scenario8(int player, RGE_Player_Info& info);
    virtual void logStatus(void* file, int verbose);
    virtual ~RGE_Game_World();
    virtual void setup_player_colors();
    virtual void setup_player_colors(RGE_Player_Info* info);
    virtual unsigned char data_load(char* first, char* second);
    virtual unsigned char init(char* name, TSound_Driver* driver,
                               TCommunications_Handler* comm);
    virtual void turn_sound_off();
    virtual void del_game_info();
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
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
#endif

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
