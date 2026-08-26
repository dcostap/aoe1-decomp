// VA: 004A69B0 TRIBE_Screen_Name::action
// FLAGS: config/flags/scr_name.rsp (/GX for the original new/constructor EH frame)
// Attempt log:
// prior attempts used guessed save-options/message-box APIs and a flattened
// TEasy_Panel base; they were broad mismatches despite the nominal 914-byte size.
// baseline candidate: restored scr_name.cpp's canonical TPanel -> TEasy_Panel ->
// TScreenPanel ownership, real action/popup/get_string member surfaces, the
// executable's disable_input/set_current_person/remove_player calls, and the
// two natural panel-name dispatch predicates.  The source follows the packet's
// branch topology and keeps the typed child-panel fields at +0x480..+0x498.
// exact: /GX was required through the target-slug response file; a canonical
// player-info local fixed the removal call's global/load evaluation order.  The
// compiler's natural local placement makes the plain 256-byte message buffer
// land at the oracle's two popup/sprintf addresses; retaining the decompiler's
// str+4 spelling left only those two LEA displacements wrong. Result: MATCH.

#include <string.h>
#include <stdio.h>

#include "../../include/scr_name_context.h"

long TRIBE_Screen_Name::action(TPanel* panel, long event, unsigned long p3,
                               unsigned long p4)
{
    long line;
    char str[256];

    if (panel != 0) {
        if (panel == this->ok_button && event == 1) {
            line = this->name_list->get_line();
            if (line == -1) {
                return event;
            } else {
                rge_base_game->disable_input();
                RGE_Game_Info* info = rge_base_game->player_game_info;
                info->set_current_person(this->name_list->get_id());
                new TRIBE_Screen_Campaign_Selection;
                panel_system.setCurrentPanel("Campaign Selection Screen", 0);
                panel_system.destroyPanel("Name Selection Screen");
            }
            return 1;
        }

        if (panel == this->cancel_button && event == 1) {
            rge_base_game->disable_input();
            new TribeSPMenuScreen;
            panel_system.setCurrentPanel("Single Player Menu", 0);
            panel_system.destroyPanel("Name Selection Screen");
            return 1;
        }

        if (panel == this->close_button) {
            rge_base_game->close();
            return 1;
        }

        if (panel == this->name_list && event == 3) {
            this->action(this->ok_button, 1, 0, 0);
            return 1;
        }

        if (panel == this->new_button && event == 1) {
            new TRIBE_Dialog_Name(this);
            panel_system.setCurrentPanel("New Name Dialog", 0);
            return 1;
        }

        if (panel == this->remove_button && event == 1) {
            if (this->name_list->get_line() != -1) {
                sprintf(str, this->get_string(0x2A02),
                        this->name_list->get_text());
                this->popupYesNoDialog(str, 0, 0x1C2, 100);
                return event;
            }
            return 1;
        } else {
            if (panel->panelName() != 0 &&
                strcmp(panel->panelName(), "New Name Dialog") == 0) {
                if (event == 1) {
                    this->get_player_names();
                }
                panel_system.setCurrentPanel("Name Selection Screen", 0);
                panel_system.destroyPanel("New Name Dialog");
                this->setup_tab_order();
                return 1;
            }

            if (panel->panelName() != 0 &&
                strcmp(panel->panelName(), "YesNoDialog") == 0) {
                if (event == 0) {
                    line = this->name_list->get_line();
                    if (line != -1) {
                        RGE_Game_Info* info = rge_base_game->player_game_info;
                        info->remove_player(this->name_list->get_id(line));
                        this->get_player_names();
                    }
                }
                panel_system.destroyPanel("YesNoDialog");
                this->setup_tab_order();
                return 1;
            }
        }
    }

    return this->TEasy_Panel::action(panel, event, p3, p4);
}
