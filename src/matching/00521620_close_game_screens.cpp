// VA: 00521620 TRIBE_Game::close_game_screens (355 B)
// PDB source: tribegam.cpp:419-447
//
// Attempt log:
// - Initial scaffold used free-function panel calls and raw this arithmetic.
// - Baseline restores the period typed TPanelSystem object, the exact dialog
//   destruction order, and the proven TRIBE_Game::game_screen field at +0xC24.
// - Removing diagnostic char* casts from string literals is codegen-identical;
//   the clean source keeps the ordinary typed call spelling.
// - Main-agent audit confirmed canonical game/panel ownership and direct cleanup
//   order; exact bytes were revalidated after promotion.

class TPanelSystem {
public:
    int destroyPanel(char* name);
};

extern TPanelSystem panel_system;

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_04[0xA24 - 0x04];
};

class TRIBE_Game : public RGE_Base_Game {
public:
    char gap_A24[0xC24 - 0xA24];
    void* game_screen; // +0xC24

    void close_game_screens(int destroyGameScreen);
};

void TRIBE_Game::close_game_screens(int destroyGameScreen)
{
    panel_system.destroyPanel("Object List Dialog");
    panel_system.destroyPanel("OKDialog");
    panel_system.destroyPanel("YesNoDialog");
    panel_system.destroyPanel("RestartDialog");
    panel_system.destroyPanel("QuitGameDialog");
    panel_system.destroyPanel("CloseProgramDialog");
    panel_system.destroyPanel("QuitAndLoadDialog");
    panel_system.destroyPanel("ResignDialog");
    panel_system.destroyPanel("Help Dialog");
    panel_system.destroyPanel("About Dialog");
    panel_system.destroyPanel("Send Quick Message Dialog");
    panel_system.destroyPanel("Mission Dialog");
    panel_system.destroyPanel("Send Message Dialog");
    panel_system.destroyPanel("Diplomacy Dialog");
    panel_system.destroyPanel("Menu Dialog");
    panel_system.destroyPanel("Save Game Screen");
    panel_system.destroyPanel("Load Saved Game Screen");
    panel_system.destroyPanel("End Screen");
    panel_system.destroyPanel("Achievements Screen");
    panel_system.destroyPanel("Multiplayer Wait Screen");
    panel_system.destroyPanel("Multiplayer Disconnect Screen");

    if (destroyGameScreen != 0) {
        this->game_screen = 0;
        panel_system.destroyPanel("Game Screen");
    }
}
