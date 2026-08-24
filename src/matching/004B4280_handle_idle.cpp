// VA: 004B4280 | TribeSelectScenarioScreen::handle_idle()
#include "../../include/scr_sels_context.h"

long TribeSelectScenarioScreen::handle_idle() {
    if (this->scenariosLoaded == 0) {
        this->fillScenarios();
        this->fillMissionText();
        this->scenariosLoaded = 1;
        this->activatePanels();
        this->set_curr_child(this->scenarioList);
    }
    if (rge_base_game->input_enabled == 0) {
        rge_base_game->enable_input();
    }
    return TPanel::handle_idle();
}
