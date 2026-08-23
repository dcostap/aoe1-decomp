// VA: 00490FF0 TRIBE_Screen_Campaign_Selection::action
// scr_cams.cpp lines 196-241
// Attempt log:
// 1: natural source with /GX-style new/ctor EH context: exact except final base call uses lea ecx,[esi+4] due bad base model.
// 2: move virtual table surface to TEasy_Panel base so base subobject starts at offset 0.

#include "../../include/scr_cams_context.h"

long TRIBE_Screen_Campaign_Selection::action(TPanel* panel, long code, unsigned long p3, unsigned long p4)
{
    if (panel != 0 && this->campaignsLoaded != 0) {
        TPanel* ok = this->okButton;
        if (panel == ok && code == 1) {
            this->startGame();
            return 1;
        }
        if (panel == this->cancelButton && code == 1) {
            rge_base_game->disable_input();
            new TRIBE_Screen_Name;
            panel_system.setCurrentPanel("Name Selection Screen", 0);
            panel_system.destroyPanel("Campaign Selection Screen");
            return 1;
        }
        if (panel == this->close_button && code == 1) {
            rge_base_game->close();
            return 1;
        }
        if (panel == this->campaignList && code == 1) {
            RGE_Game_Info* info = rge_base_game->game_info;
            info->set_current_campaign(this->campaignList->get_id());
            this->fillScenarios();
            return 1;
        }
        if (panel == this->scenarioList && code == 3) {
            this->action(ok, 1, 0, 0);
            return 1;
        }
    }
    return this->TEasy_Panel::action(panel, code, p3, p4);
}
