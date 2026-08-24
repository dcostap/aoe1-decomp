// VA: 004B4720 | TribeSelectScenarioScreen::fillMissionText()
#include "../../include/scr_sels_context.h"

void TribeSelectScenarioScreen::fillMissionText() {
    long line;

    this->missionText->set_text((char*)0x592A40);
    line = this->scenarioList->get_line();
    if (line >= 0) {
        this->missionText->set_text(this->scenarioMission[line]);
    }
    this->last_scenario_line = line;
}
