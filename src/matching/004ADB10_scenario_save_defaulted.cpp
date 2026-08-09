// VA: 004ADB10 TRIBE_Screen_Sed::scenario_save_defaulted
// Attempt log:
// baseline: natural typed save flow from scr_sed.cpp line bands; world/scenario
// ownership is named and the 0x86bad8 buffer is the proven shared output buffer.

extern "C" int __cdecl sprintf(char*, const char*, ...);

class TRegistry {
public:
    int RegGetInt(int, char*);
};

class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[0x1a8];
    TRegistry* registry;
    void show_status_message(int, char*, int);
    void close_status_message();
};

extern TRIBE_Game* rge_base_game;

class T_Scenario {
public:
#define VPAD(n) virtual void v##n();
    virtual ~T_Scenario(); VPAD(1) VPAD(2) VPAD(3) VPAD(4) VPAD(5) VPAD(6) VPAD(7)
    VPAD(8) VPAD(9) VPAD(10) VPAD(11) VPAD(12) VPAD(13) VPAD(14) VPAD(15)
    VPAD(16) VPAD(17) VPAD(18) VPAD(19) VPAD(20) VPAD(21) VPAD(22) VPAD(23)
    VPAD(24) VPAD(25) VPAD(26) VPAD(27) VPAD(28) VPAD(29) VPAD(30) VPAD(31)
    VPAD(32) VPAD(33) VPAD(34) VPAD(35) VPAD(36) VPAD(37) VPAD(38) VPAD(39)
    VPAD(40) VPAD(41) VPAD(42) VPAD(43) VPAD(44) VPAD(45) VPAD(46) VPAD(47)
    VPAD(48) VPAD(49) VPAD(50) VPAD(51) VPAD(52) VPAD(53) VPAD(54) VPAD(55)
    VPAD(56)
#undef VPAD
    virtual unsigned char save(char*);
    void Save_victory_conditions_into_players(int);
};

class RGE_Scenario {
public:
    int active_player_count();
    int any_player_count();
};

class RGE_Game_World {
public:
#define WPAD(n) virtual void w##n();
    virtual ~RGE_Game_World(); WPAD(1) WPAD(2) WPAD(3) WPAD(4) WPAD(5) WPAD(6) WPAD(7)
    WPAD(8) WPAD(9) WPAD(10) WPAD(11) WPAD(12) WPAD(13) WPAD(14) WPAD(15)
    WPAD(16) WPAD(17) WPAD(18) WPAD(19) WPAD(20) WPAD(21) WPAD(22) WPAD(23)
    WPAD(24) WPAD(25) WPAD(26) WPAD(27) WPAD(28) WPAD(29) WPAD(30) WPAD(31)
    WPAD(32) WPAD(33) WPAD(34) WPAD(35) WPAD(36) WPAD(37) WPAD(38) WPAD(39)
    WPAD(40) WPAD(41) WPAD(42) WPAD(43) WPAD(44) WPAD(45) WPAD(46) WPAD(47)
    WPAD(48) WPAD(49) WPAD(50) WPAD(51) WPAD(52) WPAD(53) WPAD(54) WPAD(55)
    WPAD(56)
#undef WPAD
    virtual unsigned char save(char*);
    char gap_04[0x5c - 4];
    T_Scenario* scenario;
};

class TRIBE_Screen_Sed {
public:
    virtual ~TRIBE_Screen_Sed();
    char gap_04[0x924];
    RGE_Game_World* world;

    void set_scenario_mode(int);
    void popupOKDialog(long, char*, long, long);
    char* scenario_save_defaulted();
};

extern char DAT_0086bad8[];

// Main-agent audit restored game/scenario/world/screen polymorphic ownership and
// gave the shared save-name buffer a symbol-backed surface; bytes remain exact.

char* TRIBE_Screen_Sed::scenario_save_defaulted() {
    this->set_scenario_mode(11);
    this->world->scenario->Save_victory_conditions_into_players(1);
    if (((RGE_Scenario*)this->world->scenario)->active_player_count() < 1) {
        this->popupOKDialog(0x2742, 0, 0x1c2, 100);
        return 0;
    }
    if (((RGE_Scenario*)this->world->scenario)->any_player_count() < 1) {
        this->popupOKDialog(0x2743, 0, 0x1c2, 100);
        return 0;
    }

    rge_base_game->show_status_message(0x450, 0, -1);
    sprintf(DAT_0086bad8, "default%d.scx",
            rge_base_game->registry->RegGetInt(0, (char*)"Game File Number"));
    if (this->world->save(DAT_0086bad8) == 0) {
        rge_base_game->close_status_message();
        this->popupOKDialog(0x963, 0, 0x1c2, 100);
        return 0;
    }

    sprintf(DAT_0086bad8, "default%d",
            rge_base_game->registry->RegGetInt(0, (char*)"Game File Number"));
    return DAT_0086bad8;
}
