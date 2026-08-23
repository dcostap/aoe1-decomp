// 004AEE10 TRIBE_Screen_Sed::activate_victory_proper_fields
// Exact finish:
// - PDB names the parameters TypeOfVictory and activate. It records ptr[2].
// - Separate case 6 and case 9 bodies recover the original tail merge.
// - Grouped labels or a goto leave 13 register-allocation bytes.
// - Direct calls, ordinary breaks, and removal of the former alias stay exact.
// The compiler merges the two identical set-object case bodies.

#include "../../include/scr_sed2_context.h"

void TRIBE_Screen_Sed::activate_victory_proper_fields(int TypeOfVictory, int activate)
{
    TPanel* ptr[2];

    this->SelectRegionFlag = 0;
    if (activate == 0) {
        this->victory_object_list->set_active(activate);
        this->victory_amount_text->set_active(activate);
        this->victory_amount_input->set_active(activate);
        this->victory_button_set_object->set_active(activate);
        this->victory_button_set_destination->set_active(activate);
        this->victory_button_go_to_dest->set_active(activate);
        this->victory_which_enemy_text->set_active(activate);
        this->victory_enemy_player_list->set_active(activate);
        this->victory_attribute_list->set_active(activate);
        this->victory_ages_list->set_active(activate);
        this->victory_tech_list->set_active(activate);
        return;
    }

    this->bottom_panel->set_curr_child(0);
    switch (TypeOfVictory) {
    case 0:
        break;
    case 1:
        this->victory_button_set_object->set_active(activate);
        this->victory_button_set_destination->set_active(activate);
        break;
    case 2:
        this->victory_button_set_object->set_active(activate);
        this->victory_button_set_destination->set_active(activate);
        this->victory_button_go_to_dest->set_active(activate);
        break;
    case 3:
        this->victory_object_list->set_active(activate);
        this->victory_amount_text->set_active(activate);
        this->victory_amount_input->set_active(activate);
        this->victory_amount_input->set_help_info(0x7766, -1);
        this->bottom_panel->set_curr_child(this->victory_amount_input);
        break;
    case 4:
        this->victory_object_list->set_active(activate);
        this->victory_amount_text->set_active(activate);
        this->victory_amount_input->set_active(activate);
        this->victory_amount_input->set_help_info(0x7767, -1);
        this->bottom_panel->set_curr_child(this->victory_amount_input);
        this->victory_button_set_destination->set_active(activate);
        this->victory_button_go_to_dest->set_active(activate);
        break;
    case 5:
        this->victory_object_list->set_active(activate);
        this->victory_amount_text->set_active(activate);
        this->victory_amount_input->set_active(activate);
        this->victory_which_enemy_text->set_active(activate);
        this->victory_amount_input->set_help_info(0x7768, -1);
        this->victory_enemy_player_list->set_active(activate);
        ptr[0] = this->victory_enemy_player_list;
        ptr[1] = this->victory_amount_input;
        this->set_tab_order(ptr, 2);
        this->bottom_panel->set_curr_child(this->victory_enemy_player_list);
        break;
    case 6:
        this->victory_button_set_object->set_active(activate);
        break;
    case 7:
        this->victory_object_list->set_active(activate);
        this->victory_which_enemy_text->set_active(activate);
        this->victory_enemy_player_list->set_active(activate);
        this->bottom_panel->set_curr_child(this->victory_enemy_player_list);
        break;
    case 8:
        this->victory_which_enemy_text->set_active(activate);
        this->victory_enemy_player_list->set_active(activate);
        this->bottom_panel->set_curr_child(this->victory_enemy_player_list);
        break;
    case 9:
        this->victory_button_set_object->set_active(activate);
        break;
    case 15:
        this->victory_ages_list->set_active(activate);
        break;
    case 10:
        this->victory_amount_input->set_help_info(0x7769, -1);
        this->victory_amount_text->set_active(activate);
        this->victory_amount_input->set_active(activate);
        this->bottom_panel->set_curr_child(this->victory_amount_input);
        break;
    case 11:
        this->victory_amount_input->set_help_info(0x776a, -1);
        this->victory_amount_text->set_active(activate);
        this->victory_amount_input->set_active(activate);
        this->bottom_panel->set_curr_child(this->victory_amount_input);
        break;
    case 12:
        this->victory_amount_input->set_help_info(0x776b, -1);
        this->victory_amount_text->set_active(activate);
        this->victory_amount_input->set_active(activate);
        this->bottom_panel->set_curr_child(this->victory_amount_input);
        break;
    case 13:
        this->victory_amount_input->set_help_info(0x776c, -1);
        this->victory_amount_text->set_active(activate);
        this->victory_amount_input->set_active(activate);
        this->bottom_panel->set_curr_child(this->victory_amount_input);
        break;
    case 14:
        this->victory_amount_input->set_help_info(0x776d, -1);
        this->victory_amount_text->set_active(activate);
        this->victory_amount_input->set_active(activate);
        this->bottom_panel->set_curr_child(this->victory_amount_input);
        break;
    case 16:
        this->victory_amount_input->set_help_info(0x776e, -1);
        this->victory_amount_text->set_active(activate);
        this->victory_amount_input->set_active(activate);
        this->bottom_panel->set_curr_child(this->victory_amount_input);
        break;
    case 17:
        this->victory_amount_text->set_active(activate);
        this->victory_amount_input->set_active(activate);
        this->victory_amount_input->set_help_info(0x776f, -1);
        this->bottom_panel->set_curr_child(this->victory_amount_input);
        this->victory_attribute_list->set_active(activate);
        break;
    case 18:
        this->victory_tech_list->set_active(activate);
        break;
    }
}
