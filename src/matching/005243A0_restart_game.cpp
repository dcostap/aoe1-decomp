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
