// VA: 00524640 TRIBE_Game::save_game (332 B)
// PDB source: tribegam.cpp:1909-1959
//
// Attempt log:
// - Initial scaffold was incomplete (free-function/raw-offset calls and an
//   omitted world save/copy/panel path).
// - Baseline reconstruction below uses the proven TRIBE_Game/base-game/world
//   ownership, the slot-0xD8 TRIBE_World::save_game surface, the 260-byte
//   filename buffer, and the natural strcpy/strchr path from the packet.
// - Main-agent audit confirmed canonical game/world/panel ownership and natural
//   save flow; exact bytes were revalidated after promotion.

extern "C" char* __cdecl strcpy(char* destination, const char* source);
extern "C" char* __cdecl strchr(const char* source, int character);

extern int ENABLE_COMPRESSION; // 00585A6C

enum SaveMode {
    SaveModeA = 4,
    SaveModeB = 6,
    SaveModeC = 7,
    SaveModeD = 5
};

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int mode);
    int destroyPanel(char* name);
};

extern TPanelSystem panel_system;

class TRIBE_World {
public:
    // TRIBE_World's inherited/world virtual surface occupies slots 0..53;
    // save_game is the proven slot 54 (+0xD8) used by this TU.
#define VPAD(n) virtual void v##n();
    virtual ~TRIBE_World();
    VPAD(1)  VPAD(2)  VPAD(3)  VPAD(4)  VPAD(5)  VPAD(6)
    VPAD(7)  VPAD(8)  VPAD(9)  VPAD(10) VPAD(11) VPAD(12) VPAD(13)
    VPAD(14) VPAD(15) VPAD(16) VPAD(17) VPAD(18) VPAD(19) VPAD(20)
    VPAD(21) VPAD(22) VPAD(23) VPAD(24) VPAD(25) VPAD(26) VPAD(27)
    VPAD(28) VPAD(29) VPAD(30) VPAD(31) VPAD(32) VPAD(33) VPAD(34)
    VPAD(35) VPAD(36) VPAD(37) VPAD(38) VPAD(39) VPAD(40) VPAD(41)
    VPAD(42) VPAD(43) VPAD(44) VPAD(45) VPAD(46) VPAD(47) VPAD(48)
    VPAD(49) VPAD(50) VPAD(51) VPAD(52) VPAD(53)
#undef VPAD
    virtual unsigned char save_game(char* name); // +0xD8
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();

    char gap_04[0x1B0 - 0x04];
    int prog_mode; // +0x1B0
    char gap_1B4[0x3F4 - 0x1B4];
    TRIBE_World* world; // +0x3F4

    void disable_input();
    void enable_input();
    unsigned char check_prog_argument(char* argument);
    int singlePlayerGame();
    void set_paused(int pause, int update);
};

class TRIBE_Game : public RGE_Base_Game {
public:
    void show_status_message(int message, char* parameter, long value);
    void close_status_message();
    void set_save_game_name(char* name);
    int save_game(char* filename);
};

int TRIBE_Game::save_game(char* filename)
{
    if (this->prog_mode != SaveModeA && this->prog_mode != SaveModeB &&
        this->prog_mode != SaveModeC && this->prog_mode != SaveModeD) {
        return 0;
    }

    this->disable_input();
    this->show_status_message(0x453, 0, -1);

    if (this->check_prog_argument("DEBUGSAVEGAME") != 0) {
        ENABLE_COMPRESSION = 0;
    }

    int result = this->world->save_game(filename);
    ENABLE_COMPRESSION = 1;
    if (result == 0) {
        this->close_status_message();
        this->enable_input();
        return 0;
    }

    char fileNameNoExt[260];
    strcpy(fileNameNoExt, filename);
    char* extension = strchr(fileNameNoExt, '.');
    if (extension != 0) {
        *extension = 0;
    }
    this->set_save_game_name(fileNameNoExt);

    if (this->singlePlayerGame() == 1) {
        this->set_paused(0, 0);
    }

    panel_system.setCurrentPanel((char*)"Game Screen", 0);
    panel_system.destroyPanel((char*)"Save Game Screen");
    panel_system.destroyPanel((char*)"Status Screen");
    this->enable_input();
    return 1;
}
