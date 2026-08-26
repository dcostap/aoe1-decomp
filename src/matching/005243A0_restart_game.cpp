// VA: 005243A0 TRIBE_Game::restart_game (389 B)
// PDB source: tribegam.cpp:1739-1842
//
// Attempt log:
// - Replaced the old free-function scaffold with the period game/world/panel
//   ownership shown by the neighboring exact tribegam.cpp functions.  The
//   first reconstruction keeps the two local objects natural and uses the
//   real RGE_Game_World::del_game_info virtual slot.
// - The proven 0x21c frame requires the VC5 find-data stack window to be
//   0x118 bytes; the natural temp_name object then owns the original local
//   addresses without a decompiler-only +4 cursor.
// - Exact after restoring the canonical +0xC24 game_screen, +0x116c humanity,
//   +0x28/+0x30 seed fields and the natural temp_name spelling.

extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);
extern "C" long __cdecl _findfirst(const char* filespec, void* fileinfo);

#ifndef TRIBEGAM_TU_CONTEXT
struct RGE_Player_Info;
class RGE_Sound;
class TSound_Driver;
class RGE_Prog_Info {
public:
    char gap_00[0xB12];
    char save_dir[261];
};

class TCommunications_Handler {
public:
    void SetPlayerHumanity(int player, int humanity);
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
    virtual void map_init(int count, TSound_Driver* driver);
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

    char gap_04[0x08];
    RGE_Prog_Info* prog_info; // +0x0C
    char gap_10[0x18];
    int random_game_seed; // +0x28
    char gap_2C[4];
    int save_random_game_seed; // +0x30
    char gap_34[0x158];
    TCommunications_Handler* comm_handler; // +0x18C
    char gap_190[0x20];
    int prog_mode; // +0x1B0
    char gap_1B4[0x240];
    RGE_Game_World* world; // +0x3F4
    char gap_3F8[0x62C];

    int randomGame();
    int campaignGame();
    int savedGame();
    void close();
};

class TEasy_Panel;

class TPanelSystem {
public:
    int destroyPanel(char* name);
    TEasy_Panel* panel(char* name);
};

class TEasy_Panel {
public:
    void popupOKDialog(int string_id, char* text, int value1, int value2);
};

extern TPanelSystem panel_system;

class TRIBE_Game : public RGE_Base_Game {
public:
    char gap_A24[0x200];
    void* game_screen; // +0xC24
    char gap_C28[0x23C];
    char save_game_name[260]; // +0xE64
    char load_game_name[260]; // +0xF68
    char timing_text2[256]; // +0x106C
    int save_humanity[9]; // +0x116C

    void show_status_message(int string_id, char* param_2, long param_3);
    void close_game_screens(int destroy_game_screen);
    int load_game(char* file_name);
    int start_game(int param_1);
    int start_menu();
    void restart_game();
};
#endif

void TRIBE_Game::restart_game()
{
    char temp_name[260];
    // VC5's _finddata_t occupies the 0x118-byte usable stack window here;
    // the debug location is four bytes above the nominal local anchor.
    char file_info[0x118];
    int result;

    this->show_status_message(0x451, 0, -1);
    this->close_game_screens(0);
    this->game_screen = 0;
    panel_system.destroyPanel("Game Screen");
    this->prog_mode = 0;
    this->world->del_game_info();

    for (int player = 1; player < 9; ++player) {
        this->comm_handler->SetPlayerHumanity(player, this->save_humanity[player]);
    }

    if (this->savedGame() != 0) {
        sprintf(temp_name, "%s%s.gmx", this->prog_info->save_dir,
                this->load_game_name);
        if (_findfirst(temp_name, file_info) == -1) {
            sprintf(temp_name, "%s.gam", this->load_game_name);
        } else {
            sprintf(temp_name, "%s.gmx", this->load_game_name);
        }
        result = this->load_game(temp_name);
    } else {
        int old_random_game_seed = 0;
        if (this->randomGame() == 1 && this->campaignGame() == 0) {
            old_random_game_seed = this->random_game_seed;
            this->random_game_seed = this->save_random_game_seed;
        }
        result = this->start_game(1);
        if (this->randomGame() != 0 && this->campaignGame() == 0) {
            this->random_game_seed = old_random_game_seed;
        }
    }

    if (result == 0) {
        if (this->start_menu() == 0) {
            this->close();
            return;
        }

        TEasy_Panel* panel = (TEasy_Panel*)panel_system.panel("Main Menu");
        if (panel != 0) {
            panel->popupOKDialog(0x961, 0, 0x1C2, 100);
        }
    }
}
