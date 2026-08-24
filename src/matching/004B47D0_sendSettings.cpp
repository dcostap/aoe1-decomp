// VA: 004B47D0 | TribeSelectScenarioScreen::sendSettings()
#include "../../include/scr_sels_context.h"

void TribeSelectScenarioScreen::sendSettings(void) {
    rge_base_game->setScenarioGame(1);
    rge_base_game->setScenarioName(this->scenarioList->get_text());
    rge_base_game->setDeathMatch(0);
}
