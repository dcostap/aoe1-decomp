// VA: 00524790 TRIBE_Game::save_scenario (228 B)
// PDB source: tribegam.cpp (lines 1965-1997)
// Attempt log:
// baseline (sa-e31ff4e8): canonical reconstruction from packet + exact donors.
//   - prog_mode at RGE_Base_Game+0x1B0 must be one of {4,6,7,5} (je chain into body)
//   - world (RGE_Game_World*) at +0x3F4; player_num (short) at world+0x3C;
//     scenario (RGE_Scenario*) at world+0x5C (matches RGE_Game_World layout and
//     the 004A8060 world->scenario access pattern)
//   - RGE_Game_World::save_scenario(char*) is the virtual at vtable+0xE4 (slot 57),
//     returns uchar tested via al (matches 004A8060's [eax+0E4h] virtual save)
//   - loop activates players 1..player_num-1 via Set_player_Active(i-1, 1)
//     (0048BC00), world kept in eax across the loop, reloaded after the call
//   - panel_system global 0x62E870 setCurrentPanel/destroyPanel string calls

class RGE_Scenario {
public:
    void Set_player_Active(int player, int active);
};

class RGE_Game_World {
public:
#define VPAD(n) virtual void v##n();
    VPAD(0)  VPAD(1)  VPAD(2)  VPAD(3)  VPAD(4)  VPAD(5)  VPAD(6)  VPAD(7)
    VPAD(8)  VPAD(9)  VPAD(10) VPAD(11) VPAD(12) VPAD(13) VPAD(14) VPAD(15)
    VPAD(16) VPAD(17) VPAD(18) VPAD(19) VPAD(20) VPAD(21) VPAD(22) VPAD(23)
    VPAD(24) VPAD(25) VPAD(26) VPAD(27) VPAD(28) VPAD(29) VPAD(30) VPAD(31)
    VPAD(32) VPAD(33) VPAD(34) VPAD(35) VPAD(36) VPAD(37) VPAD(38) VPAD(39)
    VPAD(40) VPAD(41) VPAD(42) VPAD(43) VPAD(44) VPAD(45) VPAD(46) VPAD(47)
    VPAD(48) VPAD(49) VPAD(50) VPAD(51) VPAD(52) VPAD(53) VPAD(54) VPAD(55)
    VPAD(56)
#undef VPAD
    virtual unsigned char save_scenario(char* name); // vtable+0xE4

    char gap_04[0x3C - 4];
    short player_num;              // +0x3C
    char gap_3E[0x5C - 0x3E];
    RGE_Scenario* scenario;        // +0x5C
};

class TRIBE_Game {
public:
    char gap_00[0x1B0];
    int prog_mode;                 // +0x1B0
    char gap_1B4[0x3F4 - 0x1B4];
    RGE_Game_World* world;         // +0x3F4

    void disable_input();
    void enable_input();
    int singlePlayerGame();
    void set_paused(int p1, int p2);
    void show_status_message(int string_id, char* param_2, long param_3);
    int save_scenario(char* filename);
};

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int mode);
    int destroyPanel(char* name);
};

extern TPanelSystem panel_system;

int TRIBE_Game::save_scenario(char* filename)
{
    if (this->prog_mode != 4 && this->prog_mode != 6 &&
        this->prog_mode != 7 && this->prog_mode != 5) {
        return 0;
    }

    this->disable_input();
    this->show_status_message(0x450, 0, -1);

    for (int i = 1; i < this->world->player_num; i++) {
        this->world->scenario->Set_player_Active(i - 1, 1);
    }

    if (this->world->save_scenario(filename) == 0) {
        this->enable_input();
        return 0;
    }

    if (this->singlePlayerGame() == 1) {
        this->set_paused(0, 0);
    }

    panel_system.setCurrentPanel("Game Screen", 0);
    panel_system.destroyPanel("Save Game Screen");
    panel_system.destroyPanel("Status Screen");

    this->enable_input();
    return 1;
}
