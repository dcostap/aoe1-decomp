// VA: 004B4810 | TribeSelectScenarioScreen::activatePanels()
#include "../../include/scr_sels_context.h"

void TribeSelectScenarioScreen::activatePanels() {
    this->missionTitle->set_active(1);
    this->missionText->set_active(1);

    TPanel* tabList[4];
    tabList[0] = this->scenarioList;
    tabList[1] = this->okButton;
    tabList[2] = this->cancelButton;

    this->set_tab_order(tabList, 3);

    TPanelState* state = this->field_3C;
    if (state == 0 || state->child == 0) {
        this->set_curr_child(this->okButton);
    }
}
