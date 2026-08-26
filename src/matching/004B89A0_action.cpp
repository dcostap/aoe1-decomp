// TRIBE_Mission_Screen::action
// VA: 004B89A0
// PDB: scr_vc.cpp:266-293
//
// Baseline reconstruction: typed screen fields, the proven
// RGE_Base_Game -> RGE_World -> RGE_Scenario chain, and the direct
// TEasy_Panel base action.  Text-button actions fall through to the base
// handler.  Their message result goes directly to list->setText().

#include "../../include/scr_vc_context.h"

long TRIBE_Mission_Screen::action(TPanel* sender, long actionType,
                                  unsigned long param3, unsigned long param4)
{
    if (actionType == 1) {
        if (sender == this->text_buttons[0]) {
            this->list->setText(rge_base_game->world->scenario->Get_message(4));
        }

        if (sender == this->text_buttons[1]) {
            this->list->setText(rge_base_game->world->scenario->Get_message(0));
        }

        if (sender == this->text_buttons[2]) {
            this->list->setText(rge_base_game->world->scenario->Get_message(1));
        }

        if (sender == this->ok_button) {
            if (this->game_flag != 0) {
                panel_system.setCurrentPanel((char*)"Game Screen", 0);
                if (rge_base_game->singlePlayerGame() == 1 &&
                    rge_base_game->save_paused == 0) {
                    rge_base_game->set_paused(0, 0);
                }
            } else {
                rge_base_game->create_game_screen();
            }

            panel_system.destroyPanel((char*)"Mission Dialog");
            return 1;
        }
    }

    return TEasy_Panel::action(sender, actionType, param3, param4);
}
