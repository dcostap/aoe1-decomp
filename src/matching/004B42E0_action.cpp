// VA: 004B42E0 | TribeSelectScenarioScreen::action()
#include "../../include/scr_sels_context.h"

long TribeSelectScenarioScreen::action(TPanel* panel, long event,
                                        unsigned long p3, unsigned long p4)
{
    if (panel != 0 && this->scenariosLoaded != 0) {
        if (panel == this->okButton && event == 1) {
            this->set_curr_child(this->scenarioList);
            this->sendSettings();
            rge_base_game->disable_input();
            new TribeMPSetupScreen;
            panel_system.setCurrentPanel((char*)0x5861AC, 0);
            panel_system.destroyPanel((char*)0x5868B0);
            return 1;
        }
        if (panel == this->cancelButton && event == 1) {
            this->set_curr_child(this->scenarioList);
            rge_base_game->disable_input();
            new TribeSPMenuScreen;
            panel_system.setCurrentPanel((char*)0x586638, 0);
            panel_system.destroyPanel((char*)0x5868B0);
            return 1;
        }
        if (panel == this->close_button && event == 1) {
            rge_base_game->close();
            return 1;
        }
        if (panel == this->scenarioList) {
            if (event == 3) {
                this->action(this->okButton, 1, 0, 0);
                return 1;
            }
            if (event == 1) {
                this->fillMissionText();
                this->activatePanels();
                return 1;
            }
        }
    }
    return TPanel::action(panel, event, p3, p4);
}
