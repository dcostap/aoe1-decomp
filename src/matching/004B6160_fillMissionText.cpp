// 004B6160 TribeGameSettingsScreen::fillMissionText
// Size: 197 bytes (0xC5)

#define SCR_SET_CONTEXT_GROUP 1
#include "../../include/scr_set_context.h"
void TribeGameSettingsScreen::fillMissionText(void) {
    long line;
    int id;
    this->missionText->set_text("");
    line = this->scenarioList->get_line();
    id = this->scenarioList->get_id();

    if (id == -2) {
        this->missionText->set_text(0x25DC);
    } else if (id == -1) {
        this->missionText->set_text(0x2618);
    } else {
        this->missionText->set_text(this->scenarioMission[this->scenario_line_offset + line]);
    }

    if (line != this->last_scenario_line) {
        this->victoryTypeDrop->set_line(0);
    }

    if (id < 0) {
        this->state = 1;
        this->last_scenario_line = line;
        return;
    }

    this->last_scenario_line = line;
    this->state = 0;
}
