// tried initial implementation based on Ghidra decompiler
// Result: size 80 vs 86.
// Sticking with this version as the a quick-win attempt failed.
#include "game_types.h"

// Local stubs for necessary types
class TPanel {
public:
    virtual long handle_idle();
    static void set_curr_child(TPanel* pPanel, TPanel* pChild);
};

class RGE_Base_Game {
public:
    int input_enabled; // offset 0x1D8
    void enable_input();
};

class TribeSelectScenarioScreen : public TPanel {
public:
    TPanel* scenarioList;    // offset 0x494
    int scenariosLoaded;     // offset 0x4A8

    void fillScenarios();
    void fillMissionText();
    void activatePanels();
    virtual long handle_idle();
};

extern RGE_Base_Game* rge_base_game;

long TribeSelectScenarioScreen::handle_idle() {
    if (scenariosLoaded == 0) {
        fillScenarios();
        fillMissionText();
        scenariosLoaded = 1;
        activatePanels();
        TPanel::set_curr_child(this, scenarioList);
    }

    if (rge_base_game->input_enabled == 0) {
        rge_base_game->enable_input();
    }

    return TPanel::handle_idle();
}

