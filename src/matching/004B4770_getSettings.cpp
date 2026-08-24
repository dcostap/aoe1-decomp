// VA: 004B4770 | TribeSelectScenarioScreen::getSettings()
#include "../../include/scr_sels_context.h"

void TribeSelectScenarioScreen::getSettings() {
    this->last_scenario_line = -1;

    char* scenarioName = rge_base_game->scenarioName();
    long line = this->scenarioList->get_line(scenarioName);

    if (line != -1) {
        this->scenarioList->scroll_cur_line(1, line, 1);
        this->last_scenario_line = line - 1;
    } else {
        this->scenarioList->scroll_cur_line(1, 0, 1);
    }
}
