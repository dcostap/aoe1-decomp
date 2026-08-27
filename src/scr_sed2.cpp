// Canonical scr_sed2.cpp source module in PDB and address order.
// PDB source: C:/msdev/work/age1_x1/scr_sed2.cpp.
// Padding-only fragments at 004AE05A, 004AEC95, and 004AF2D2 are excluded.
#include "../include/scr_sed2.h"

// VA: 004ADC80 TRIBE_Screen_Sed::SaveDisabledItemsInScenario()
// PDB source: scr_sed2.cpp lines 343-352
// Default flags
//
// __thiscall: this in ecx, no stack params. void return.


void TRIBE_Screen_Sed::SaveDisabledItemsInScenario() {
    short pn0 = this->player_num;
    if (pn0 == 0) {
        this->player_num = 1;
    }

    for (int i = 0; i < 16; i++) {
        int state = this->options_disable_button[i]->get_state();
        if (state != 0) {
            int player_idx = (int)(short)this->player_num - 1;
            this->world->scenario->SetDisabledTechnology(player_idx, i, 0);
        } else {
            int player_idx = (int)(short)this->player_num - 1;
            this->world->scenario->SetDisabledTechnology(player_idx, i, 1);
        }
    }

    long line = this->options_player_list->get_line();
    this->player_num = (short)(line + 1);
}

// VA: 004ADD00 TRIBE_Screen_Sed::LoadDisabledItemsFromScenario.
// BINARY NOTE: The named getter result preserves the source line split and
// the original register map.

void TRIBE_Screen_Sed::LoadDisabledItemsFromScenario(void) {
    TButtonPanel** button;
    int i;
    int disabled;

    for (i = 0, button = this->options_disable_button; i < 16; i++, button++) {
        disabled = this->world->scenario->GetDisabledTechnology(this->player_num - 1, i);
        if (disabled != 0) {
            (*button)->set_state(0);
        }
        else {
            (*button)->set_state(1);
        }
    }
}




// VA: 004ADD50 TRIBE_Screen_Sed::save_info_in_scenario.
void TRIBE_Screen_Sed::save_info_in_scenario() {}

// VA: 004ADD60 TRIBE_Screen_Sed::save_multi_victory_cond_in_scenario.
// BINARY NOTE: The victory setters use the typed T_Scenario surface.

void TRIBE_Screen_Sed::save_multi_victory_cond_in_scenario()
{
    switch (this->mp_victory_type) {
    case 1:
        this->world->scenario->SetMPVictory(0);
        break;
    case 2:
        this->world->scenario->SetMPVictory(1);
        break;
    case 3:
        this->world->scenario->SetMPVictory(2);
        break;
    case 4:
        this->world->scenario->SetMPVictory(3);
        break;
    default:
        this->world->scenario->SetMPVictory(4);
        break;
    }

    this->world->scenario->SetVictoryScore(this->victory_score->get_id());
    this->world->scenario->SetVictoryTime(this->victory_time->get_id());

    if (this->victory_cond_type[0]->get_state()) {
        this->world->scenario->SetMPVictory(0);
    } else if (this->victory_cond_type[1]->get_state()) {
        this->world->scenario->SetMPVictory(1);
    } else if (this->victory_cond_type[2]->get_state()) {
        this->world->scenario->SetMPVictory(2);
    } else if (this->victory_cond_type[3]->get_state()) {
        this->world->scenario->SetMPVictory(3);
    } else {
        this->world->scenario->SetMPVictory(4);
    }

    this->world->scenario->SetVictoryScore(this->victory_score->get_id());
    this->world->scenario->SetVictoryTime(this->victory_time->get_id());

    if (this->victory_and_or[1]->get_state()) {
        this->world->scenario->Set_victory_all_flag(1);
    } else {
        this->world->scenario->Set_victory_all_flag(0);
    }

    if (!this->victory_cond_on[0]->get_state() && this->victory_cond_type[4]->get_state()) {
        this->world->scenario->Set_Multi_Conquest(0);
    } else {
        this->world->scenario->Set_Multi_Conquest(1);
    }

    int value = atoi(this->victory_condition_explore->currentLine());
    if (this->victory_cond_on[1]->get_state()) {
        if (value < 1) value = 1;
        if (value > 100) value = 100;
        this->world->scenario->Set_Multi_Exploration(value);
    } else {
        this->world->scenario->Set_Multi_Exploration(0);
    }

    value = atoi(this->victory_condition_ruins->currentLine());
    if (this->victory_cond_on[2]->get_state()) {
        this->world->scenario->Set_Multi_Ruins(value);
    } else {
        this->world->scenario->Set_Multi_Ruins(0);
    }

    value = atoi(this->victory_condition_artifacts->currentLine());
    if (this->victory_cond_on[3]->get_state()) {
        this->world->scenario->Set_Multi_Artifacts(value);
    } else {
        this->world->scenario->Set_Multi_Artifacts(0);
    }

    value = atoi(this->victory_condition_discoveries->currentLine());
    if (this->victory_cond_on[4]->get_state()) {
        this->world->scenario->Set_Multi_Discoveries(value);
    } else {
        this->world->scenario->Set_Multi_Discoveries(0);
    }

    value = atoi(this->victory_condition_gold->currentLine());
    if (this->victory_cond_on[5]->get_state()) {
        this->world->scenario->Set_Multi_Gold(value);
    } else {
        this->world->scenario->Set_Multi_Gold(0);
    }
}

// VA: 004AE070 TRIBE_Screen_Sed::save_victory_cond_in_scenario.
// BINARY NOTE: VC5 merges two equivalent selected-object setter tails in
// this reconstruction.
// BINARY NOTE: The protected PDB owner is retained by this definition.

void TRIBE_Screen_Sed::save_victory_cond_in_scenario(int index)
{
    if (this->victory_and_or[1]->get_state())
        this->world->scenario->Set_victory_all_flag(1);
    else
        this->world->scenario->Set_victory_all_flag(0);

    if (!this->victory_cond_on[0]->get_state() && this->victory_cond_type[4]->get_state())
        this->world->scenario->Set_Multi_Conquest(0);
    else
        this->world->scenario->Set_Multi_Conquest(1);

    if (index < 0) return;

    int amount;
    int kind;
    int player;
    int objectType;
    long x1, y1, x2; int y2;
    amount = atoi(this->victory_amount_input->currentLine());
    kind = this->victory_drop_down->get_line();
    player = this->victory_enemy_player_list->get_line() + 1;
    objectType = this->victory_object_list->get_id();
    this->main_view->get_selection_area(&x1, &y1, &x2, &y2, 1);
    this->px1 = (float)x1;
    this->py1 = (float)y1;
    this->px2 = (float)x2;
    this->py2 = (float)y2;
    this->world->scenario->ClearSPVictoryCondition(index);

    switch (kind) {
    case 0:
        break;
    case 1:
        if (this->SelectedObject && this->DestinationObject) {
            this->world->scenario->SetSPVictoryType(index,3);
            this->world->scenario->SetSPObject(index,this->SelectedObject);
            this->world->scenario->SetSPDestObjectID(index,this->DestinationObject);
        }
        break;
    case 2:
        if (this->SelectedObject) {
            this->world->scenario->SetSPVictoryType(index,3);
            this->world->scenario->SetSPObject(index,this->SelectedObject);
            this->world->scenario->SetSPRectangle(index,this->px1,this->py1,this->px2,this->py2);
        }
        break;
    case 3:
        this->world->scenario->SetSPVictoryType(index,2);
        this->world->scenario->SetSPObjectType(index,objectType);
        goto set_amount;
    case 4:
        this->world->scenario->SetSPVictoryType(index,2);
        this->world->scenario->SetSPObjectType(index,objectType);
        this->world->scenario->SetSPAmount(index,amount);
        this->world->scenario->SetSPRectangle(index,this->px1,this->py1,this->px2,this->py2);
        break;
    case 5:
        if (player >= 1 && player <= 8 && amount) {
            this->world->scenario->SetSPVictoryType(index,1);
            this->world->scenario->SetSPPlayerID(index,player);
            this->world->scenario->SetSPObjectType(index,objectType);
            this->world->scenario->SetSPAmount(index,amount);
        }
        break;
    case 6:
        if (!this->SelectedObject) break;
        this->world->scenario->SetSPVictoryType(index,1);
        this->world->scenario->SetSPObject(index,this->SelectedObject);
        break;
    case 7:
        if (player >= 1 && player <= 8) {
            this->world->scenario->SetSPVictoryType(index,1);
            this->world->scenario->SetSPPlayerID(index,player);
            this->world->scenario->SetSPObjectType(index,objectType);
            this->world->scenario->SetSPAllFlag(index,1);
        }
        break;
    case 8:
        if (player >= 1 && player <= 8) {
            this->world->scenario->SetSPVictoryType(index,1);
            this->world->scenario->SetSPPlayerID(index,player);
        }
        break;
    case 9:
        if (!this->SelectedObject) break;
        this->world->scenario->SetSPVictoryType(index,5);
        this->world->scenario->SetSPObject(index,this->SelectedObject);
        break;
    case 10: this->world->scenario->SetSPVictoryType(index,4); objectType = 0; goto attrib_amount;
    case 11: this->world->scenario->SetSPVictoryType(index,4); objectType = 3; goto attrib_amount;
    case 12: this->world->scenario->SetSPVictoryType(index,4); objectType = 1; goto attrib_amount;
    case 13: this->world->scenario->SetSPVictoryType(index,4); objectType = 2; goto attrib_amount;
    case 14: this->world->scenario->SetSPVictoryType(index,4); objectType = 4; goto attrib_amount;
    case 15:
        this->world->scenario->SetSPVictoryType(index,4);
        this->world->scenario->SetSPAttribType(index,5);
        this->world->scenario->SetSPAmount(index,this->victory_ages_list->get_line()+1);
        break;
    case 16: this->world->scenario->SetSPVictoryType(index,4); objectType = 6; goto attrib_amount;
    case 17:
        this->world->scenario->SetSPVictoryType(index,6);
        objectType = this->victory_attribute_list->get_id();
attrib_amount:
        this->world->scenario->SetSPAttribType(index,objectType);
set_amount:
        this->world->scenario->SetSPAmount(index,amount);
        break;
    case 18:
        this->world->scenario->SetSPVictoryType(index,7);
        objectType = this->victory_tech_list->get_id();
        this->world->scenario->SetSPAttribType(index,objectType);
        break;
    default:
        break;
    }

    return;
}

// VA: 004AE620 TRIBE_Screen_Sed::load_victory_cond_from_scenario.
// ORIGINAL BUG: Case 1 tests the amount home, not the destination-object
// home. The shipped UI can select a line from the amount value.

void TRIBE_Screen_Sed::load_victory_cond_from_scenario(int index)
{
    char str[40];
    RGE_Static_Object* destobj;
    int Amount;
    int VictoryType;
    long x1, y1, x2, y2;
    RGE_Static_Object* obj;

    int all = this->world->scenario->Get_victory_all_flag();
    if (all != 0) {
        this->victory_and_or[0]->set_state(0);
        this->victory_and_or[1]->set_state(1);
    } else {
        this->victory_and_or[0]->set_state(1);
        this->victory_and_or[1]->set_state(0);
    }

    if (index < 0) return;
    this->SelectedObject = 0;
    this->DestinationObject = 0;
    this->world->scenario->reset();
    this->world->scenario->SetSPWhich((int)this->player_num - 1);
    Amount = this->world->scenario->GetSPAmount(index);
    itoa(Amount, str, 10);
    this->victory_amount_input->set_text(str);
    this->victory_enemy_player_list->set_line(this->world->scenario->GetSPPlayerID(index) - 1);
    this->victory_object_list->setCurrentLineNumber(this->victory_object_list->get_line(this->world->scenario->GetSPObjectType(index)));
    obj = this->world->scenario->GetSPObject(index);
    destobj = this->world->scenario->GetSPDestObjectID(index);
    this->SelectedObject = obj;
    this->DestinationObject = destobj;
    VictoryType = this->world->scenario->GetSPVictoryType(index);
    int AttributeType = this->world->scenario->GetSPAttribType(index);
    this->world->scenario->GetSPRectangle(index, &this->px1, &this->py1, &this->px2, &this->py2);
    x1 = (long)this->px1; y1 = (long)this->py1; x2 = (long)this->px2; y2 = (long)this->py2;
    this->main_view->set_selection_area(-1,-1,-1,-1);
    if (this->px2 != 0.0f) this->main_view->set_selection_area(x1,y1,x2,y2);

    switch (VictoryType) {
    case 4:
        switch (AttributeType) {
        case 0: this->victory_drop_down->setCurrentLineNumber(10); break;
        case 3: this->victory_drop_down->setCurrentLineNumber(11); break;
        case 1: this->victory_drop_down->setCurrentLineNumber(12); break;
        case 2: this->victory_drop_down->setCurrentLineNumber(13); break;
        case 4: this->victory_drop_down->setCurrentLineNumber(14); break;
        case 5:
            this->victory_drop_down->setCurrentLineNumber(15);
            this->victory_ages_list->setCurrentLineNumber(this->world->scenario->GetSPAmount(index)-1);
            return;
        case 6: this->victory_drop_down->setCurrentLineNumber(16); break;
        default: return;
        }
        break;
    case 6:
        this->victory_drop_down->setCurrentLineNumber(17);
        this->victory_attribute_list->setCurrentLineId(AttributeType);
        return;
    case 7:
        this->victory_drop_down->setCurrentLineNumber(18);
        this->victory_tech_list->setCurrentLineId(AttributeType);
        return;
    case 5:
        if (obj == 0) return;
        this->victory_drop_down->setCurrentLineNumber(9);
        break;
    case 1:
        // ORIGINAL BUG: PDB home -0x30 and the case-1 load use Amount.
        // The destination object does not select line 5 in this case.
        if (Amount != 0) this->victory_drop_down->setCurrentLineNumber(5);
        else if (obj != 0) this->victory_drop_down->setCurrentLineNumber(6);
        else if (this->world->scenario->GetSPAllFlag(index)) this->victory_drop_down->setCurrentLineNumber(7);
        else this->victory_drop_down->setCurrentLineNumber(8);
        break;
    case 2:
        this->world->scenario->GetSPRectangle(index, &this->px1, &this->py1, &this->px2, &this->py2);
        if (this->px2 > 0.0) this->victory_drop_down->setCurrentLineNumber(4);
        else this->victory_drop_down->setCurrentLineNumber(3);
        break;
    case 3:
        if (destobj != 0) this->victory_drop_down->setCurrentLineNumber(1);
        else this->victory_drop_down->setCurrentLineNumber(2);
        break;
    case 0:
        this->victory_drop_down->setCurrentLineNumber(0);
        break;
    default: return;
    }
}

// VA: 004AE9D0 TRIBE_Screen_Sed::load_multi_victory_cond_from_scenario.
// BINARY NOTE: Zero score and time values use the default entries.

void TRIBE_Screen_Sed::load_multi_victory_cond_from_scenario()
{
    char str[20];
    int value = this->world->scenario->GetMPVictory();

    switch (value) {
    case 0:
        this->mp_victory_type = 1;
        break;
    case 1:
        this->mp_victory_type = 2;
        break;
    case 2:
        this->mp_victory_type = 3;
        break;
    case 3:
        this->mp_victory_type = 4;
        break;
    default:
        this->mp_victory_type = 5;
        break;
    }

    value = this->world->scenario->GetVictoryScore();
    if (value != 0) {
        this->victory_score->set_line(this->victory_score->get_line(value));
    } else {
        this->victory_score->set_line(this->victory_score->get_line(900));
    }

    value = this->world->scenario->GetVictoryTime();
    if (value != 0) {
        this->victory_time->set_line(this->victory_time->get_line(value));
    } else {
        this->victory_time->set_line(this->victory_time->get_line(9000));
    }

    if (this->world->scenario->Get_victory_all_flag() != 0) {
        this->victory_and_or[1]->set_radio_button();
    } else {
        this->victory_and_or[0]->set_radio_button();
    }

    if (this->world->scenario->Get_Multi_Conquest() != 0) {
        this->victory_cond_on[0]->set_state(1);
    } else {
        this->victory_cond_on[0]->set_state(0);
    }

    value = this->world->scenario->Get_Multi_Exploration();
    if (value != 0) {
        this->victory_cond_on[1]->set_state(1);
        itoa(value, str, 10);
        this->victory_condition_explore->set_text(str);
    } else {
        this->victory_cond_on[1]->set_state(0);
        this->victory_condition_explore->set_text(s_empty);
    }

    value = this->world->scenario->Get_Multi_Ruins();
    if (value != 0) {
        this->victory_cond_on[2]->set_state(1);
        itoa(value, str, 10);
        this->victory_condition_ruins->set_text(str);
    } else {
        this->victory_cond_on[2]->set_state(0);
        this->victory_condition_ruins->set_text(s_empty);
    }

    value = this->world->scenario->Get_Multi_Artifacts();
    if (value != 0) {
        this->victory_cond_on[3]->set_state(1);
        itoa(value, str, 10);
        this->victory_condition_artifacts->set_text(str);
    } else {
        this->victory_cond_on[3]->set_state(0);
        this->victory_condition_artifacts->set_text(s_empty);
    }

    value = this->world->scenario->Get_Multi_Discoveries();
    if (value != 0) {
        this->victory_cond_on[4]->set_state(1);
        itoa(value, str, 10);
        this->victory_condition_discoveries->set_text(str);
    } else {
        this->victory_cond_on[4]->set_state(0);
        this->victory_condition_discoveries->set_text(s_empty);
    }

    value = this->world->scenario->Get_Multi_Gold();
    if (value != 0) {
        this->victory_cond_on[5]->set_state(1);
        itoa(value, str, 10);
        this->victory_condition_gold->set_text(str);
    } else {
        this->victory_cond_on[5]->set_state(0);
        this->victory_condition_gold->set_text(s_empty);
    }

    this->world->scenario->Save_victory_conditions_into_players(1);
}

// 004AECB0 TRIBE_Screen_Sed::save_diplomacy_in_scenario (155B)
// scr_sed2.cpp:913-940
// Default flags


void TRIBE_Screen_Sed::save_diplomacy_in_scenario(int param_1)
{
    if (param_1 < 0) return;

    for (int i = 0; i < 8; i++) {
        int st = Diplomacy_friend_box[i][0]->get_state();
        if (st == 1) {
            world->scenario->Set_player_attitude(param_1, i, 0);
        } else {
            st = Diplomacy_friend_box[i][1]->get_state();
            if (st == 1) {
                world->scenario->Set_player_attitude(param_1, i, 1);
            } else {
                st = Diplomacy_friend_box[i][2]->get_state();
                if (st == 1) {
                    world->scenario->Set_player_attitude(param_1, i, 3);
                }
            }
        }
    }

    int av = Diplomacy_AlliedVictory[param_1]->get_state();
    world->scenario->SetPlayerAlliedVictory(param_1, av);
}

// TRIBE_Screen_Sed::load_diplomacy_from_scenario
// VA: 004AED50 TRIBE_Screen_Sed::load_diplomacy_from_scenario.
// BINARY NOTE: Each diplomacy row clears its allied-victory button before
// the selected attitude and final player-specific state are applied.

void TRIBE_Screen_Sed::load_diplomacy_from_scenario(int player)
{
    if (player >= 0) {
        int i = 0;
        do {
            int att = this->world->scenario->Get_player_attitude(player, i);
            if (att == 0)
                this->Diplomacy_friend_box[i][0]->set_radio_button();
            if (att == 1)
                this->Diplomacy_friend_box[i][1]->set_radio_button();
            if (att == 3)
                this->Diplomacy_friend_box[i][2]->set_radio_button();
            this->Diplomacy_AlliedVictory[i]->set_state(0);
            i++;
        } while (i < 8);
        this->Diplomacy_AlliedVictory[player]->set_state(
            this->world->scenario->GetPlayerAlliedVictory(player));
    }
}

// VA: 004AEE10 TRIBE_Screen_Sed::activate_victory_proper_fields.
// BINARY NOTE: Cases 6 and 9 keep separate source cases; VC5 merges their
// identical set-object bodies.

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

// VA: 004AF320 TRIBE_Screen_Sed::init_module_variables.
// BINARY NOTE: The paired panel arrays are cleared in declared field order.

void TRIBE_Screen_Sed::init_module_variables()
{
    TButtonPanel** ppTVar3;
    int iVar6;

    this->background_pic = (TShape*)0;
    this->main_view = (TRIBE_Main_View*)0;
    this->map_view = (RGE_Diamond_Map_View*)0;
    this->message_panel = (TMessagePanel*)0;
    this->bottom_panel = (TPanel*)0;
    this->set_player_first_flag = 0;
    ppTVar3 = this->scenario_mode_button;
    for (iVar6 = 10; iVar6 != 0; iVar6 = iVar6 + -1) {
        *ppTVar3 = (TButtonPanel*)0;
        ppTVar3 = ppTVar3 + 1;
    }
    this->menu_button = (TButtonPanel*)0;
    this->help_button = (TButtonPanel*)0;
    this->map_type_label = (TTextPanel*)0;
    for (iVar6 = 0; iVar6 < 3; ++iVar6) {
        this->map_type_button[iVar6] = (TButtonPanel*)0;
        this->map_type_text[iVar6] = (TTextPanel*)0;
    }
    this->default_terrain_drop = (TDropDownPanel*)0;
    this->default_terrain_label = (TTextPanel*)0;
    this->map_size_drop = (TDropDownPanel*)0;
    this->map_size_label = (TTextPanel*)0;
    this->map_style_drop = (TDropDownPanel*)0;
    this->map_style_label = (TTextPanel*)0;
    this->map_generating_text = (TTextPanel*)0;
    this->random_seed_label = (TTextPanel*)0;
    this->random_seed_input = (TEditPanel*)0;
    this->random_seed_used_label = (TTextPanel*)0;
    this->random_seed_used_text = (TTextPanel*)0;
    this->generate_map_button = (TButtonPanel*)0;
    this->brush_size_label = (TTextPanel*)0;
    this->paint_type_label = (TTextPanel*)0;
    this->paint_terrain_label = (TTextPanel*)0;
    for (iVar6 = 0; iVar6 < 5; ++iVar6) {
        this->brush_size_button[iVar6] = (TButtonPanel*)0;
        this->brush_size_button_label[iVar6] = (TTextPanel*)0;
    }
    for (iVar6 = 0; iVar6 < 3; ++iVar6) {
        this->paint_type_button[iVar6] = (TButtonPanel*)0;
        this->paint_type_button_label[iVar6] = (TTextPanel*)0;
    }
    this->paint_terrain_list = (TListPanel*)0;
    this->paint_terrain_scrollbar = (TScrollBarPanel*)0;
    this->paint_elevation_list = (TListPanel*)0;
    this->paint_elevation_scrollbar = (TScrollBarPanel*)0;
    this->player_advance_civilization_drop = (TDropDownPanel*)0;
    this->player_label = (TTextPanel*)0;
    this->player_starting_age_label = (TTextPanel*)0;
    this->player_build_text = (TTextPanel*)0;
    this->player_city_text = (TTextPanel*)0;
    this->player_list = (TDropDownPanel*)0;
    this->player_number_list = (TDropDownPanel*)0;
    for (iVar6 = 0; iVar6 < 5; ++iVar6) {
        this->player_inven_label[iVar6] = (TTextPanel*)0;
        this->player_inven_input[iVar6] = (TEditPanel*)0;
    }
    for (iVar6 = 0; iVar6 < 2; ++iVar6) {
        this->player_setting_label[iVar6] = (TTextPanel*)0;
        this->player_setting_drop[iVar6] = (TDropDownPanel*)0;
    }
    this->BuildList = (TDropDownPanel*)0;
    this->CityLayout = (TDropDownPanel*)0;
    this->AiRules = (TDropDownPanel*)0;
    this->unit_player_list = (TDropDownPanel*)0;
    for (iVar6 = 0; iVar6 < 4; ++iVar6) {
        this->unit_mode_select[iVar6] = (TButtonPanel*)0;
        this->unit_mode_select_label[iVar6] = (TTextPanel*)0;
    }
    this->unit_list = (TListPanel*)0;
    this->unit_scrollbar = (TScrollBarPanel*)0;
    this->unit_list_info = (List_Info*)0;
    this->button_unit_pics = (TShape*)0;
    for (iVar6 = 0; iVar6 < 5; ++iVar6)
        this->button_bldg_pics[iVar6] = (TShape*)0;
    this->object_panel = (TRIBE_Scenario_Editor_Panel_Object*)0;
    this->unit_list_size = 0;
    ppTVar3 = this->victory_cond_on;
    for (iVar6 = 6; iVar6 != 0; iVar6 = iVar6 + -1) {
        *ppTVar3 = (TButtonPanel*)0;
        ppTVar3 = ppTVar3 + 1;
    }
    for (iVar6 = 0; iVar6 < 2; ++iVar6) {
        this->victory_and_or[iVar6] = (TButtonPanel*)0;
        this->victory_text_and_or[iVar6] = (TTextPanel*)0;
    }
    this->victory_amount_label = (TTextPanel*)0;
    this->victory_long_label = (TTextPanel*)0;
    this->victory_condition_label = (TTextPanel*)0;
    this->victory_label_conquest = (TTextPanel*)0;
    this->victory_label_explore = (TTextPanel*)0;
    this->victory_label_explore_percent = (TTextPanel*)0;
    this->victory_label_ruins = (TTextPanel*)0;
    this->victory_label_artifacts = (TTextPanel*)0;
    this->victory_label_discoveries = (TTextPanel*)0;
    this->victory_label_gold = (TTextPanel*)0;
    this->victory_condition_explore = (TEditPanel*)0;
    this->victory_condition_ruins = (TEditPanel*)0;
    this->victory_condition_artifacts = (TEditPanel*)0;
    this->victory_condition_discoveries = (TEditPanel*)0;
    this->victory_condition_gold = (TEditPanel*)0;
    for (iVar6 = 0; iVar6 < 5; ++iVar6) {
        this->victory_cond_type_label[iVar6] = (TTextPanel*)0;
        this->victory_cond_type[iVar6] = (TButtonPanel*)0;
    }
    this->victory_score_label = (TTextPanel*)0;
    this->victory_score = (TDropDownPanel*)0;
    this->victory_time_label = (TTextPanel*)0;
    this->victory_time = (TDropDownPanel*)0;
    ppTVar3 = this->victory_button;
    for (iVar6 = 0xc; iVar6 != 0; iVar6 = iVar6 + -1) {
        *ppTVar3 = (TButtonPanel*)0;
        ppTVar3 = ppTVar3 + 1;
    }
    this->victory_drop_down = (TDropDownPanel*)0;
    this->victory_object_list = (TDropDownPanel*)0;
    this->victory_player_list = (TDropDownPanel*)0;
    this->victory_ages_list = (TDropDownPanel*)0;
    this->victory_tech_list = (TDropDownPanel*)0;
    this->victory_button_set_object = (TButtonPanel*)0;
    this->victory_button_set_destination = (TButtonPanel*)0;
    this->victory_button_go_to_dest = (TButtonPanel*)0;
    this->victory_condition_text = (TTextPanel*)0;
    this->victory_condition_type = (TTextPanel*)0;
    this->victory_amount_text = (TTextPanel*)0;
    this->victory_amount_input = (TEditPanel*)0;
    this->victory_enemy_player_list = (TDropDownPanel*)0;
    this->victory_attribute_list = (TDropDownPanel*)0;
    this->victory_which_enemy_text = (TTextPanel*)0;
    this->victory_object_scrollbar = (TScrollBarPanel*)0;
    for (iVar6 = 0; iVar6 < 5; ++iVar6) {
        this->message_button[iVar6] = (TButtonPanel*)0;
        this->message_button_label[iVar6] = (TTextPanel*)0;
    }
    this->message_input = (TEditPanel*)0;
    for (iVar6 = 0; iVar6 < 4; ++iVar6) {
        this->cinematic_label[iVar6] = (TTextPanel*)0;
        this->cinematic_input[iVar6] = (TDropDownPanel*)0;
    }
    for (iVar6 = 0; iVar6 < 1; ++iVar6) {
        this->options_label[iVar6] = (TTextPanel*)0;
        this->options_button[iVar6] = (TButtonPanel*)0;
    }
    this->options_player_list = (TDropDownPanel*)0;
    this->options_disable_tech_text = (TTextPanel*)0;
    for (iVar6 = 0; iVar6 < 0x10; ++iVar6) {
        this->options_disable_button[iVar6] = (TButtonPanel*)0;
        this->options_disable_text[iVar6] = (TTextPanel*)0;
    }
    this->Diplomacy_player_list = (TDropDownPanel*)0;
    for (iVar6 = 0; iVar6 < 8; ++iVar6) {
        this->Diplomacy_player_text[iVar6] = (TTextPanel*)0;
        this->Diplomacy_friend_box[iVar6][0] = (TButtonPanel*)0;
        this->Diplomacy_friend_box[iVar6][1] = (TButtonPanel*)0;
        this->Diplomacy_friend_box[iVar6][2] = (TButtonPanel*)0;
        this->Diplomacy_AlliedVictory[iVar6] = (TButtonPanel*)0;
    }
    this->Diplomacy_status_label[0] = (TTextPanel*)0;
    this->Diplomacy_status_label[1] = (TTextPanel*)0;
    this->Diplomacy_status_label[2] = (TTextPanel*)0;
    this->Diplomacy_status_label[3] = (TTextPanel*)0;
    this->world = (TRIBE_World*)0;
}

// VA: 004AF6C0 TRIBE_Screen_Sed::create_all_buttons_etc.
// BINARY NOTE: The constructor path requires the /GX exception flag.

void TRIBE_Screen_Sed::create_all_buttons_etc()
{
    int i;
    TButtonPanel** pp;
    int count;
    TPanel* ptr[4];
    char str4[20];
    char str3[20];
    char str1[140];
    char str[100];
    char str2[140];
    TButtonPanel** cur;
    TTextPanel** tt;
    TButtonPanel** group;

    group = this->scenario_mode_button;
    cur = group;
    if (!(this->create_button(this, cur, 0x271A, 1))) goto fail; (*cur)->set_help_info(0x76C0, -1);
    cur = this->scenario_mode_button + 1;
    if (!(this->create_button(this, cur, 0x271B, 1))) goto fail; (*cur)->set_help_info(0x76C1, -1);
    cur = this->scenario_mode_button + 2;
    if (!(this->create_button(this, cur, 0x271C, 1))) goto fail; (*cur)->set_help_info(0x76C2, -1);
    cur = this->scenario_mode_button + 3;
    if (!(this->create_button(this, cur, 0x271D, 1))) goto fail; (*cur)->set_help_info(0x76C3, -1);
    cur = this->scenario_mode_button + 4;
    if (!(this->create_button(this, cur, 0x2722, 1))) goto fail; (*cur)->set_help_info(0x76C8, -1);
    cur = this->scenario_mode_button + 5;
    if (!(this->create_button(this, cur, 0x271E, 1))) goto fail; (*cur)->set_help_info(0x76C4, -1);
    cur = this->scenario_mode_button + 6;
    if (!(this->create_button(this, cur, 0x2723, 1))) goto fail; (*cur)->set_help_info(0x76C9, -1);
    cur = this->scenario_mode_button + 7;
    if (!(this->create_button(this, cur, 0x2721, 1))) goto fail; (*cur)->set_help_info(0x76C7, -1);
    cur = this->scenario_mode_button + 8;
    if (!(this->create_button(this, cur, 0x271F, 1))) goto fail; (*cur)->set_help_info(0x76C5, -1);
    cur = this->scenario_mode_button + 9;
    if (!(this->create_button(this, cur, 0x2720, 1))) goto fail; (*cur)->set_help_info(0x76C6, -1);

    cur = group;
    count = 10;
    do {
        (*cur)->set_radio_info(group, 10);
        (*cur)->set_active(1);
        ++cur;
        --count;
    } while (count != 0);

    if (!(this->create_button(this, &this->menu_button, 0x2724, 0))) goto fail;
    (this->menu_button)->set_help_info(0x774C, -1);
    this->menu_button->set_active(1);
    if (!(this->create_button(this, &this->help_button, 0x0FA9, 0))) goto fail;
    this->help_button->set_active(1);

    if (!(this->create_text(this->bottom_panel, &this->map_type_label, 0x29A6))) goto fail;
    if (!(this->create_radio_button(this->bottom_panel, &this->map_type_button[0]))) goto fail; (this->map_type_button[0])->set_help_info(0x76CF, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->map_type_button[1]))) goto fail; (this->map_type_button[1])->set_help_info(0x76D0, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->map_type_button[2]))) goto fail; (this->map_type_button[2])->set_help_info(0x76D1, -1);
    if (!(this->create_text(this->bottom_panel, &this->map_type_text[0], 0x299C))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->map_type_text[1], 0x299D))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->map_type_text[2], 0x299E))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->default_terrain_label, 0x299F))) goto fail;
    if (!(this->create_drop_down(this->bottom_panel, &this->default_terrain_drop))) goto fail; (this->default_terrain_drop)->set_help_info(0x76D6, -1);
    if (!(this->create_text(this->main_view, &this->map_generating_text, 0x29A5, 0, 0,
                         (int)(this)->width(), (int)(this)->height() - 200, 1, 1, 1, 0))) goto fail;
    this->map_generating_text->set_active(0);

    if (!(this->create_text(this->bottom_panel, &this->map_size_label, 0x29A0))) goto fail;
    if (!(this->create_drop_down(this->bottom_panel, &this->map_size_drop))) goto fail; (this->map_size_drop)->set_help_info(0x76D2, -1);
    if (!(this->create_text(this->bottom_panel, &this->map_style_label, 0x29A1))) goto fail;
    if (!(this->create_drop_down(this->bottom_panel, &this->map_style_drop))) goto fail; (this->map_style_drop)->set_help_info(0x76D3, -1);
    if (!(this->create_text(this->bottom_panel, &this->random_seed_label, 0x29A2))) goto fail;
    if (!(this->create_edit(this->bottom_panel, &this->random_seed_input, s_0, 5, FormatUnsignedInt, 0, 0))) goto fail; (this->random_seed_input)->set_help_info(0x76D4, -1);
    if (!(this->create_text(this->bottom_panel, &this->random_seed_used_label, 0x29A3))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->random_seed_used_text, s_0))) goto fail;
    if (!(this->create_button(this->bottom_panel, &this->generate_map_button, 0x29A4, 0))) goto fail; (this->generate_map_button)->set_help_info(0x76D5, -1);
    for (i = 0; i < 3; ++i) this->map_type_button[i]->set_radio_info(this->map_type_button, 3);

    if (!(this->create_text(this->bottom_panel, &this->brush_size_label, 0x29AF))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->paint_terrain_label, 0x29BC))) goto fail;
    if (!(this->create_radio_button(this->bottom_panel, &this->brush_size_button[0]))) goto fail; (this->brush_size_button[0])->set_help_info(0x76D9, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->brush_size_button[1]))) goto fail; (this->brush_size_button[1])->set_help_info(0x76DA, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->brush_size_button[2]))) goto fail; (this->brush_size_button[2])->set_help_info(0x76DB, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->brush_size_button[3]))) goto fail; (this->brush_size_button[3])->set_help_info(0x76DC, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->brush_size_button[4]))) goto fail; (this->brush_size_button[4])->set_help_info(0x76DD, -1);
    if (!(this->create_text(this->bottom_panel, &this->brush_size_button_label[0], 0x29B0))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->brush_size_button_label[1], 0x29B1))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->brush_size_button_label[2], 0x29B2))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->brush_size_button_label[3], 0x29B3))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->brush_size_button_label[4], 0x29B4))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->paint_type_label, 0x29B9))) goto fail;
    if (!(this->create_radio_button(this->bottom_panel, &this->paint_type_button[0]))) goto fail; (this->paint_type_button[0])->set_help_info(0x76DE, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->paint_type_button[1]))) goto fail; (this->paint_type_button[1])->set_help_info(0x76DF, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->paint_type_button[2]))) goto fail; (this->paint_type_button[2])->set_help_info(0x76E0, -1);
    if (!(this->create_text(this->bottom_panel, &this->paint_type_button_label[0], 0x271A))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->paint_type_button_label[1], 0x2987))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->paint_type_button_label[2], 0x29BA))) goto fail;
    if (!(this->create_list(this->bottom_panel, &this->paint_terrain_list, &this->paint_terrain_scrollbar))) goto fail; (this->paint_terrain_list)->set_help_info(0x76E1, -1);
    if (!(this->create_list(this->bottom_panel, &this->paint_elevation_list, &this->paint_elevation_scrollbar))) goto fail; (this->paint_elevation_list)->set_help_info(0x76E2, -1);
    for (i = 0; i < 5; ++i) this->brush_size_button[i]->set_radio_info(this->brush_size_button, 5);
    for (i = 0; i < 3; ++i) this->paint_type_button[i]->set_radio_info(this->paint_type_button, 3);

    if (!(this->create_radio_button(this->bottom_panel, &this->unit_mode_select[0]))) goto fail; (this->unit_mode_select[0])->set_help_info(0x76F8, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->unit_mode_select[1]))) goto fail; (this->unit_mode_select[1])->set_help_info(0x76F7, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->unit_mode_select[2]))) goto fail; (this->unit_mode_select[2])->set_help_info(0x76F9, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->unit_mode_select[3]))) goto fail; (this->unit_mode_select[3])->set_help_info(0x76FA, -1);
    if (!(this->create_text(this->bottom_panel, &this->unit_mode_select_label[0], 0x2777))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->unit_mode_select_label[1], 0x2778))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->unit_mode_select_label[2], 0x2779))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->unit_mode_select_label[3], 0x277A))) goto fail;
    for (i = 0; i < 4; ++i) this->unit_mode_select[i]->set_radio_info(this->unit_mode_select, 4);
    this->unit_mode_select[0]->set_radio_button();

    if (!(this->create_list(this, &this->unit_list, &this->unit_scrollbar))) goto fail;
    (this->unit_list)->set_help_info(0x76FB, -1);
    this->unit_list->set_z_order(2, 0);

    this->button_unit_pics = new TShape(s_btnunit_shp, 0xC62A);
    if (!this->button_unit_pics) goto bad;
    if (!this->button_unit_pics->is_loaded()) goto bad;

    for (i = 0; i < 5; ++i) {
        int idx = i;
        if (idx == 4) idx = 1;
        sprintf(str, s_btnbldg_d_shp, idx);
        this->button_bldg_pics[idx] = new TShape(str, idx + 0xC610);
        if (!this->button_bldg_pics[idx]) goto bad;
        if (!this->button_bldg_pics[idx]->is_loaded()) goto bad;
    }

    if (!(this->create_drop_down(this->bottom_panel, &this->unit_player_list))) goto fail; (this->unit_player_list)->set_help_info(0x76FC, -1);
    {
        RGE_Font* f = rge_base_game->get_font(10);
        this->object_panel = new TRIBE_Scenario_Editor_Panel_Object(this->render_area, this, f->font, f->font_wid, f->font_hgt,
                                                                    this->button_unit_pics, this->button_bldg_pics, 0);
        if (!this->object_panel || this->object_panel->error_code != 0) goto bad;
        this->object_panel->set_active(0);
        this->unit_player_list->set_z_order(1, 0);
    }

    if (!(this->create_text(this->bottom_panel, &this->player_label, 0x2864))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->player_starting_age_label, 0x2815))) goto fail;
    if (!(this->create_drop_down(this->bottom_panel, &this->player_advance_civilization_drop))) goto fail; (this->player_advance_civilization_drop)->set_help_info(0x7765, -1);
    this->Set_player_advance_civilization_text(0);
    if (!(this->create_drop_down(this->bottom_panel, &this->player_list))) goto fail; (this->player_list)->set_help_info(0x76E6, -1);
    if (!(this->create_drop_down(this->bottom_panel, &this->player_number_list))) goto fail; (this->player_number_list)->set_help_info(0x76E7, -1);
    if (!(this->create_text(this->bottom_panel, &this->player_inven_label[0], 0x280B))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->player_inven_label[1], 0x280C))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->player_inven_label[2], 0x280D))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->player_inven_label[3], 0x280E))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->player_inven_label[4], 0x2805))) goto fail;
    for (i = 0; i < 4; ++i) if (!(this->create_edit(this->bottom_panel, &this->player_inven_input[i], s_0, 5, FormatUnsignedInt, 0, 0))) goto fail;
    (this->player_inven_input[0])->set_help_info(0x76E8, 1);
    (this->player_inven_input[1])->set_help_info(0x76E9, 1);
    (this->player_inven_input[2])->set_help_info(0x76EB, 1);
    (this->player_inven_input[3])->set_help_info(0x76EA, 1);
    if (!(this->create_edit(this->bottom_panel, &this->player_inven_input[4], s_empty, 0x1C, FormatText, 1, 1))) goto fail; (this->player_inven_input[4])->set_help_info(0x76EC, 1);
    if (!(this->create_text(this->bottom_panel, &this->player_setting_label[0], 0x2810))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->player_setting_label[1], 0x2811))) goto fail;
    for (i = 0; i < 2; ++i) if (!(this->create_drop_down(this->bottom_panel, &this->player_setting_drop[i]))) goto fail;
    (this->player_setting_drop[0])->set_help_info(0x76ED, -1);
    (this->player_setting_drop[1])->set_help_info(0x76EE, -1);
    if (!(this->create_drop_down(this->bottom_panel, &this->BuildList))) goto fail; (this->BuildList)->set_help_info(0x76EF, -1);
    if (!(this->create_drop_down(this->bottom_panel, &this->CityLayout))) goto fail; (this->CityLayout)->set_help_info(0x76F0, -1);
    if (!(this->create_drop_down(this->bottom_panel, &this->AiRules))) goto fail; (this->AiRules)->set_help_info(0x76F1, -1);
    if (!(this->create_text(this->bottom_panel, &this->player_build_text, 0x2813))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->player_city_text, 0x2814))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->AiRules_text, 0x2812))) goto fail;
    this->set_tab_order((TPanel**)this->player_inven_input, 5);

    if (!(this->create_check_box(this->bottom_panel, &this->victory_cond_on[0]))) goto fail; (this->victory_cond_on[0])->set_help_info(0x7704, -1);
    if (!(this->create_check_box(this->bottom_panel, &this->victory_cond_on[1]))) goto fail; (this->victory_cond_on[1])->set_help_info(0x7706, -1);
    if (!(this->create_check_box(this->bottom_panel, &this->victory_cond_on[2]))) goto fail; (this->victory_cond_on[2])->set_help_info(0x7707, -1);
    if (!(this->create_check_box(this->bottom_panel, &this->victory_cond_on[3]))) goto fail; (this->victory_cond_on[3])->set_help_info(0x7708, -1);
    if (!(this->create_check_box(this->bottom_panel, &this->victory_cond_on[4]))) goto fail; (this->victory_cond_on[4])->set_help_info(0x7709, -1);
    if (!(this->create_check_box(this->bottom_panel, &this->victory_cond_on[5]))) goto fail; (this->victory_cond_on[5])->set_help_info(0x770A, -1);

    if (!(this->create_radio_button(this->bottom_panel, &this->victory_and_or[0]))) goto fail; (this->victory_and_or[0])->set_help_info(0x7701, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->victory_and_or[1]))) goto fail; (this->victory_and_or[1])->set_help_info(0x7703, -1);
    for (i = 0; i < 2; ++i) this->victory_and_or[i]->set_radio_info(this->victory_and_or, 2);
    this->victory_and_or[0]->set_radio_button();
    if (!(this->create_text(this->bottom_panel, &this->victory_text_and_or[0], 0x28A2))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_text_and_or[1], 0x28A3))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_amount_label, 0x28A4))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_long_label, 0x28A5))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_condition_label, 0x10E0))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_label_conquest, 0x10E1))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_label_explore, 0x10E2))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_label_explore_percent, 0x10E7))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_label_ruins, 0x10E3))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_label_artifacts, 0x10E4))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_label_discoveries, 0x10E5))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_label_gold, 0x10E6))) goto fail;
    if (!(this->create_edit(this->bottom_panel, &this->victory_condition_explore, s_space, 3, FormatUnsignedInt, 0, 0))) goto fail; (this->victory_condition_explore)->set_help_info(0x770B, -1);
    if (!(this->create_edit(this->bottom_panel, &this->victory_condition_ruins, s_space, 2, FormatUnsignedInt, 0, 0))) goto fail; (this->victory_condition_ruins)->set_help_info(0x770C, -1);
    if (!(this->create_edit(this->bottom_panel, &this->victory_condition_artifacts, s_space, 2, FormatUnsignedInt, 0, 0))) goto fail; (this->victory_condition_artifacts)->set_help_info(0x770D, -1);
    if (!(this->create_edit(this->bottom_panel, &this->victory_condition_discoveries, s_space, 2, FormatUnsignedInt, 0, 0))) goto fail; (this->victory_condition_discoveries)->set_help_info(0x770E, -1);
    if (!(this->create_edit(this->bottom_panel, &this->victory_condition_gold, s_space, 5, FormatUnsignedInt, 0, 0))) goto fail; (this->victory_condition_gold)->set_help_info(0x770F, -1);
    ptr[0] = this->victory_condition_explore;
    ptr[1] = this->victory_condition_ruins;
    ptr[2] = this->victory_condition_artifacts;
    ptr[3] = this->victory_condition_discoveries;
    this->set_tab_order(ptr, 4);

    if (!(this->create_text(this->bottom_panel, &this->victory_cond_type_label[0], 0x10EC))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_cond_type_label[1], 0x10E1))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_cond_type_label[2], 0x10EA))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_cond_type_label[3], 0x10E9))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_cond_type_label[4], 0x10EB))) goto fail;
    if (!(this->create_radio_button(this->bottom_panel, &this->victory_cond_type[0]))) goto fail; (this->victory_cond_type[0])->set_help_info(0x7756, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->victory_cond_type[1]))) goto fail; (this->victory_cond_type[1])->set_help_info(0x7757, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->victory_cond_type[2]))) goto fail; (this->victory_cond_type[2])->set_help_info(0x7758, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->victory_cond_type[3]))) goto fail; (this->victory_cond_type[3])->set_help_info(0x7759, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->victory_cond_type[4]))) goto fail; (this->victory_cond_type[4])->set_help_info(0x775A, -1);
    for (i = 0; i < 5; ++i) this->victory_cond_type[i]->set_radio_info(this->victory_cond_type, 5);
    this->victory_cond_type[1]->set_radio_button();

    if (!(this->create_text(this->bottom_panel, &this->victory_score_label, 0x10EA))) goto fail;
    if (!(this->create_drop_down(this->bottom_panel, &this->victory_score))) goto fail; (this->victory_score)->set_help_info(0x775B, -1);
    this->victory_score->empty_list();
    this->victory_score->append_line(s_3000, 3000);
    this->victory_score->append_line(s_2700, 2700);
    this->victory_score->append_line(s_2400, 2400);
    this->victory_score->append_line(s_2100, 2100);
    this->victory_score->append_line(s_1800, 1800);
    this->victory_score->append_line(s_1500, 1500);
    this->victory_score->append_line(s_1200, 1200);
    this->victory_score->append_line(s_900, 900);
    this->victory_score->append_line(s_800, 800);
    this->victory_score->append_line(s_700, 700);
    this->victory_score->append_line(s_600, 600);
    this->victory_score->append_line(s_500, 500);
    this->victory_score->append_line(s_400, 400);
    this->victory_score->append_line(s_300, 300);

    if (!(this->create_text(this->bottom_panel, &this->victory_time_label, 0x10E9))) goto fail;
    if (!(this->create_drop_down(this->bottom_panel, &this->victory_time))) goto fail; (this->victory_time)->set_help_info(0x775C, -1);
    this->victory_time->empty_list();
    this->victory_time->append_line(0x2634, 15000);
    this->victory_time->append_line(0x2635, 13000);
    this->victory_time->append_line(0x2636, 11000);
    this->victory_time->append_line(0x2637, 9000);
    this->victory_time->append_line(0x2638, 7000);
    this->victory_time->append_line(0x2639, 5000);
    this->victory_time->append_line(0x263A, 3000);

    i = 1;
    pp = this->victory_button;
    while (i - 1 < 12) {
        sprintf(str1, s_percent_d, i);
        sprintf(str2, s_angle_d, i);
        sprintf(str3, s_percent_d_star, i);
        sprintf(str4, s_angle_d_star, i);
        if (!(this->create_button(this->bottom_panel, pp, str1, str2, str3, str4))) goto fail;
        (*pp)->set_help_info(0x7712, -1);
        ++pp;
        ++i;
    }

    if (!(this->create_drop_down(this->bottom_panel, &this->victory_drop_down))) goto fail;
    if (!(this->create_drop_down(this->bottom_panel, &this->victory_object_list))) goto fail;
    if (!(this->create_drop_down(this->bottom_panel, &this->victory_player_list))) goto fail;
    if (!(this->create_drop_down(this->bottom_panel, &this->victory_enemy_player_list))) goto fail;
    if (!(this->create_drop_down(this->bottom_panel, &this->victory_attribute_list))) goto fail;
    if (!(this->create_drop_down(this->bottom_panel, &this->victory_ages_list))) goto fail;
    if (!(this->create_drop_down(this->bottom_panel, &this->victory_tech_list))) goto fail;
    (this->victory_drop_down)->set_help_info(0x7716, -1);
    (this->victory_object_list)->set_help_info(0x7714, -1);
    (this->victory_player_list)->set_help_info(0x7713, -1);
    (this->victory_ages_list)->set_help_info(0x7715, -1);
    (this->victory_enemy_player_list)->set_help_info(0x7760, -1);
    (this->victory_attribute_list)->set_help_info(0x7761, -1);
    (this->victory_tech_list)->set_help_info(0x7762, -1);

    if (!(this->create_text(this->bottom_panel, &this->victory_condition_text, 0x2870))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_condition_type, 0x2871))) goto fail;
    if (!(this->create_button(this->bottom_panel, &this->victory_button_set_object, 0x2872, 0))) goto fail;
    if (!(this->create_button(this->bottom_panel, &this->victory_button_set_destination, 0x2873, 0))) goto fail;
    if (!(this->create_button(this->bottom_panel, &this->victory_button_go_to_dest, 0x2874, 0))) goto fail;
    (this->victory_button_set_object)->set_help_info(0x7717, -1);
    (this->victory_button_set_destination)->set_help_info(0x7718, -1);
    (this->victory_button_go_to_dest)->set_help_info(0x7719, -1);
    if (!(this->create_text(this->bottom_panel, &this->victory_amount_text, 0x2875))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_which_enemy_text, 0x2876))) goto fail;
    if (!(this->create_edit(this->bottom_panel, &this->victory_amount_input, s_0, 5, FormatUnsignedInt, 0, 0))) goto fail;

    for (i = 0; i < 5; ++i) if (!(this->create_radio_button(this->bottom_panel, &this->message_button[i]))) goto fail;
    this->current_message = 0;
    (this->message_button[0])->set_help_info(0x771C, -1);
    (this->message_button[1])->set_help_info(0x771D, -1);
    (this->message_button[2])->set_help_info(0x771E, -1);
    (this->message_button[3])->set_help_info(0x771F, -1);
    (this->message_button[4])->set_help_info(0x7720, -1);
    if (!(this->create_text(this->bottom_panel, &this->message_button_label[0], 0x2A36))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->message_button_label[1], 0x2A37))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->message_button_label[2], 0x2A38))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->message_button_label[3], 0x2A39))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->message_button_label[4], 0x2A31))) goto fail;
    for (i = 0; i < 5; ++i) this->message_button[i]->set_radio_info(this->message_button, 5);
    if (!(this->create_edit(this->bottom_panel, &this->message_input, s_empty, 0x0FFF, FormatMultiLine, 1, 1))) goto fail;
    (this->message_input)->set_help_info(-1, -1);

    if (!(this->create_text(this->bottom_panel, &this->cinematic_label[0], 0x2AF9))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->cinematic_label[1], 0x2AFA))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->cinematic_label[2], 0x2AFB))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->cinematic_label[3], 0x2AFC))) goto fail;
    for (i = 0; i < 4; ++i) if (!(this->create_drop_down(this->bottom_panel, &this->cinematic_input[i]))) goto fail;
    (this->cinematic_input[0])->set_help_info(0x7724, -1);
    (this->cinematic_input[1])->set_help_info(0x7725, -1);
    (this->cinematic_input[2])->set_help_info(0x7726, -1);
    (this->cinematic_input[3])->set_help_info(0x7727, -1);

    if (!(this->create_text(this->bottom_panel, &this->options_label[0], 0x2604))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_tech_text, 0x32D7))) goto fail;
    for (i = 0; i < 1; ++i) if (!(this->create_check_box(this->bottom_panel, &this->options_button[i]))) goto fail;
    (this->options_button[0])->set_help_info(0x7729, -1);
    if (!(this->create_drop_down(this->bottom_panel, &this->options_player_list))) goto fail; (this->options_player_list)->set_help_info(0x772B, -1);
    for (i = 0; i < 16; ++i) if (!(this->create_check_box(this->bottom_panel, &this->options_disable_button[i]))) goto fail;
    (this->options_disable_button[0])->set_help_info(0x772C, -1);
    (this->options_disable_button[1])->set_help_info(0x772D, -1);
    (this->options_disable_button[2])->set_help_info(0x772E, -1);
    (this->options_disable_button[3])->set_help_info(0x772F, -1);
    (this->options_disable_button[4])->set_help_info(0x7730, -1);
    (this->options_disable_button[5])->set_help_info(0x7731, -1);
    (this->options_disable_button[6])->set_help_info(0x7732, -1);
    (this->options_disable_button[7])->set_help_info(0x7733, -1);
    (this->options_disable_button[8])->set_help_info(0x7734, -1);
    (this->options_disable_button[9])->set_help_info(0x7735, -1);
    (this->options_disable_button[10])->set_help_info(0x7736, -1);
    (this->options_disable_button[11])->set_help_info(0x7737, -1);
    (this->options_disable_button[12])->set_help_info(0x7738, -1);
    (this->options_disable_button[13])->set_help_info(0x7739, -1);
    (this->options_disable_button[14])->set_help_info(0x773A, -1);
    (this->options_disable_button[15])->set_help_info(0x773B, -1);
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[0], 0x32C9))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[1], 0x32CA))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[2], 0x32CB))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[3], 0x32CC))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[4], 0x32CD))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[5], 0x32CE))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[6], 0x32CF))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[7], 0x32D0))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[8], 0x32D1))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[9], 0x32D2))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[10], 0x32D3))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[11], 0x32D4))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[12], 0x32D5))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[13], 0x32D6))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[14], 0x32D8))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[15], 0x32D9))) goto fail;

    i = 0;
    tt = this->Diplomacy_player_text;
    while (1) {
        sprintf(str1, s_percent_d, i + 1);
        if (!(this->create_text(this->bottom_panel, tt, str1))) goto fail;
        ++tt;
        ++i;
        if (i >= 8) break;
    }
    if (!(this->create_drop_down(this->bottom_panel, &this->Diplomacy_player_list))) goto fail; (this->Diplomacy_player_list)->set_help_info(0x773D, -1);

    i = 0;
    while (i < 8) {
        if (!(this->create_radio_button(this->bottom_panel, &this->Diplomacy_friend_box[i][0]))) goto fail; (this->Diplomacy_friend_box[i][0])->set_help_info(0x773F, -1);
        if (!(this->create_radio_button(this->bottom_panel, &this->Diplomacy_friend_box[i][1]))) goto fail; (this->Diplomacy_friend_box[i][1])->set_help_info(0x7740, -1);
        if (!(this->create_radio_button(this->bottom_panel, &this->Diplomacy_friend_box[i][2]))) goto fail; (this->Diplomacy_friend_box[i][2])->set_help_info(0x7741, -1);
        this->Diplomacy_friend_box[i][0]->set_radio_info(this->Diplomacy_friend_box[i], 3);
        this->Diplomacy_friend_box[i][1]->set_radio_info(this->Diplomacy_friend_box[i], 3);
        this->Diplomacy_friend_box[i][2]->set_radio_info(this->Diplomacy_friend_box[i], 3);
        this->Diplomacy_friend_box[i][1]->set_radio_button();
        if (!(this->create_check_box(this->bottom_panel, &this->Diplomacy_AlliedVictory[i]))) goto fail;
        this->Diplomacy_AlliedVictory[i]->set_help_info(0x773E, -1);
        ++i;
    }
    if (!(this->create_text(this->bottom_panel, &this->Diplomacy_status_label[0], 0x29CD))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->Diplomacy_status_label[1], 0x29CE))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->Diplomacy_status_label[2], 0x29CF))) goto fail;
    this->create_text(this->bottom_panel, &this->Diplomacy_status_label[3], 0x29D0);

fail:
    return;

bad:
    this->error_code = 1;
    return;
}

// VA: 004B1A50 TRIBE_Screen_Sed::position_panels.
// BINARY NOTE: The panel cursor loops follow the adjacent array layout shown
// by the executable.

void TRIBE_Screen_Sed::position_panels()
{
    if (this->main_view == 0)
        return;

    for (int mode_row = 0; mode_row < 5; ++mode_row) {
        TButtonPanel* previous = mode_row == 0 ? 0 : this->scenario_mode_button[mode_row - 1];
        this->scenario_mode_button[mode_row]->set_positioning(
            7, 2, 2, 2, 2, 0x32, 0x6d, 0x16, 0x16, previous, 0, 0, 0);
    }
    for (int mode_col = 5; mode_col < 10; ++mode_col) {
        TButtonPanel* previous = mode_col == 5 ? 0 : this->scenario_mode_button[mode_col - 1];
        this->scenario_mode_button[mode_col]->set_positioning(
            7, 2, 2, 2, 2, 0x32, 0x6d, 0x16, 0x16, previous,
            this->scenario_mode_button[mode_col - 5], 0, 0);
    }

    this->menu_button->set_positioning(9, 2, 5, 3, 3, 0x3a, 0x3a, 0x14, 0x28, 0, 0, 0, 0);
    this->help_button->set_positioning(10, 5, 5, 5, 5, 0x14, 0x1e, 0x14, 0x1e, 0, 0, 0, 0);
    this->map_view->set_positioning(10, 0, 0, 0, 0, 0xe6, 0xe6, 0x87, 0x87, 0, 0, 0, 0);
    this->bottom_panel->set_positioning(8, 2, 2, 2, 2, 0, 0, 0x89, 0x89, 0, 0, this->map_view, 0);
    this->unit_list->set_positioning(7, 0, 6, 0, 4, 0x7c, 200, 0, 0, 0, this->menu_button, 0, this->bottom_panel);
    this->object_panel->set_positioning(8, 4, 4, 4, 4, 0x96, 0x96, 0x6c, 0x6c, 0, 0, 0, 0);

    TScrollBarPanel* unit_panel = (TScrollBarPanel*)this->unit_list;
    int number_lines = ((TTextPanel*)unit_panel)->numberLines();
    int number_draw_lines = ((TTextPanel*)unit_panel)->numberDrawLines();
    if (number_lines > number_draw_lines) {
        this->unit_list->set_positioning(7, 0, 6, 0, 4, 0x68, 0xdc, 0, 0, 0, this->menu_button, 0, this->bottom_panel);
        this->unit_scrollbar->set_positioning(7, 1, 1, 0, 2, 0x12, 0x12, 0, 0, this->unit_list, this->menu_button, 0, this->bottom_panel);
        unit_panel = this->unit_scrollbar;
    }
    this->main_view->set_positioning(7, 0, 6, 0, 4, 0, 0, 0, 0, unit_panel, this->menu_button, 0, this->bottom_panel);
    this->message_panel->set_positioning(8, 4, 4, 4, 4, 0, 0, 0x18, 0x18, 0, 0, 0, 0);

    this->map_type_label->set_fixed_position(4, 4, 0x78, 0x16);
    this->map_type_button[0]->set_fixed_position(4, 0x16, 0x16, 0x16);
    this->map_type_button[1]->set_fixed_position(4, 0x2c, 0x16, 0x16);
    this->map_type_button[2]->set_fixed_position(4, 0x42, 0x16, 0x16);
    this->map_type_text[0]->set_fixed_position(0x24, 0x16, 0x73, 0x16);
    this->map_type_text[1]->set_fixed_position(0x24, 0x2c, 0x73, 0x16);
    this->map_type_text[2]->set_fixed_position(0x24, 0x42, 0x73, 0x16);
    this->map_size_label->set_fixed_position(0xaa, 4, 0x82, 0x16);
    this->map_size_drop->set_fixed_position(0xaa, 0x16, 0xaa, 0x16);
    this->map_style_label->set_fixed_position(0xaa, 0x30, 0x82, 0x16);
    this->map_style_drop->set_fixed_position(0xaa, 0x42, 0xaa, 0x16);
    this->default_terrain_label->set_fixed_position(0xaa, 0x30, 0x82, 0x16);
    this->default_terrain_drop->set_fixed_position(0xaa, 0x42, 0xaa, 0x16);
    this->random_seed_label->set_fixed_position(0x24, 0x5a, 0x78, 0x16);
    this->random_seed_input->set_fixed_position(0x24, 0x70, 0x37, 0x16);
    this->random_seed_used_label->set_fixed_position(0x24, 0x5a, 0x78, 0x16);
    this->random_seed_used_text->set_fixed_position(0x24, 0x70, 0x37, 0x16);
    this->generate_map_button->set_fixed_position(0xb4, 0x60, 0x82, 0x26);
    this->paint_terrain_list->set_fixed_position(0x73, 0x17, 0xa5, 0x6e);
    this->paint_terrain_label->set_fixed_position(0x73, 1, 0x3c, 0x16);
    this->paint_elevation_list->set_fixed_position(0x73, 0x17, 0xa5, 0x6e);
    this->paint_type_label->set_fixed_position(2, 1, 0x6e, 0x14);
    this->paint_type_button[0]->set_fixed_position(2, 0x17, 0x1e, 0x16);
    this->paint_type_button[1]->set_fixed_position(2, 0x2d, 0x1e, 0x16);
    this->paint_type_button[2]->set_fixed_position(2, 0x43, 0x1e, 0x16);
    this->paint_type_button_label[0]->set_fixed_position(0x21, 0x17, 0x51, 0x16);
    this->paint_type_button_label[1]->set_fixed_position(0x21, 0x2d, 0x51, 0x16);
    this->paint_type_button_label[2]->set_fixed_position(0x21, 0x43, 0x51, 0x16);
    this->brush_size_label->set_fixed_position(0x118, 4, 0x6e, 0x14);
    this->brush_size_button[0]->set_fixed_position(0x11a, 0x17, 0x1e, 0x16);
    this->brush_size_button[1]->set_fixed_position(0x11a, 0x2d, 0x1e, 0x16);
    this->brush_size_button[2]->set_fixed_position(0x11a, 0x43, 0x1e, 0x16);
    this->brush_size_button[3]->set_fixed_position(0x11a, 0x59, 0x1e, 0x16);
    this->brush_size_button[4]->set_fixed_position(0x11a, 0x6f, 0x1e, 0x16);
    this->brush_size_button_label[0]->set_fixed_position(0x139, 0x17, 0x5a, 0x16);
    this->brush_size_button_label[1]->set_fixed_position(0x139, 0x2d, 0x5a, 0x16);
    this->brush_size_button_label[2]->set_fixed_position(0x139, 0x43, 0x5a, 0x16);
    this->brush_size_button_label[3]->set_fixed_position(0x139, 0x59, 0x5a, 0x16);
    this->brush_size_button_label[4]->set_fixed_position(0x139, 0x6f, 0x5a, 0x16);

    this->player_label->set_fixed_position(4, 4, 0x50, 0x12);
    this->player_starting_age_label->set_fixed_position(4, 0x5c, 0x5f, 0x12);
    this->player_advance_civilization_drop->set_fixed_position(4, 0x6e, 0x96, 0x16);
    this->player_label->set_fixed_position(4, 0x2a, 0x96, 0x12);
    this->player_list->set_fixed_position(4, 7, 0x96, 0x16);
    this->player_number_list->set_fixed_position(4, 0x3e, 0x96, 0x16);

    int x = 0xa6;
    TEditPanel** player_input = this->player_inven_input;
    do {
        int y = 0x19;
        do {
            ((TTextPanel*)player_input[-5])->set_fixed_position(x, y - 0x12, 0x37, 0x12);
            (*player_input)->set_fixed_position(x, y, 0x37, 0x16);
            y += 0x2c;
            ++player_input;
        } while (y < 0x71);
        x += 0x44;
    } while (x < 0x12e);

    this->player_inven_label[4]->set_fixed_position(0xa6, 0x5c, 100, 0x12);
    this->player_inven_input[4]->set_fixed_position(0xa6, 0x6e, 0x7d, 0x16);

    int setting_y = 0x19;
    TDropDownPanel** setting_drop = this->player_setting_drop;
    do {
        ((TTextPanel*)setting_drop[-3])->set_fixed_position(500, setting_y - 0x12, 0x82, 0x12);
        (*setting_drop)->set_fixed_position(500, setting_y, 0x82, 0x16);
        setting_y += 0x2c;
        ++setting_drop;
    } while (setting_y < 0x71);

    this->BuildList->set_fixed_position(300, 0x45, 0xbe, 0x16);
    this->CityLayout->set_fixed_position(300, 0x19, 0xbe, 0x16);
    this->player_build_text->set_fixed_position(300, 0x33, 0x82, 0x12);
    this->player_city_text->set_fixed_position(300, 7, 0x82, 0x12);
    this->AiRules_text->set_fixed_position(300, 0x5c, 0x82, 0x12);
    this->AiRules->set_fixed_position(300, 0x6e, 0xbe, 0x16);

    this->unit_player_list->set_fixed_position(4, 4, 0x96, 0x16);
    this->unit_mode_select[0]->set_fixed_position(0xa0, 0x16, 0x1e, 0x16);
    this->unit_mode_select[1]->set_fixed_position(0xa0, 0x30, 0x1e, 0x16);
    this->unit_mode_select[2]->set_fixed_position(0xa0, 0x4a, 0x1e, 0x16);
    this->unit_mode_select[3]->set_fixed_position(0xa0, 0x62, 0x1e, 0x16);
    this->unit_mode_select_label[0]->set_fixed_position(0xc0, 0x16, 0x6e, 0x16);
    this->unit_mode_select_label[1]->set_fixed_position(0xc0, 0x30, 0x6e, 0x16);
    this->unit_mode_select_label[2]->set_fixed_position(0xc0, 0x4a, 0x6e, 0x16);
    this->unit_mode_select_label[3]->set_fixed_position(0xc0, 0x62, 0x6e, 0x16);

    this->victory_condition_label->set_fixed_position(0x22, 0, 0x78, 0x12);
    this->victory_cond_type[0]->set_fixed_position(0x0e, 0x12, 0x14, 0x12);
    this->victory_cond_type[1]->set_fixed_position(0x0e, 0x26, 0x14, 0x12);
    this->victory_cond_type[2]->set_fixed_position(0x0e, 0x3a, 0x14, 0x12);
    this->victory_cond_type[3]->set_fixed_position(0x0e, 0x4e, 0x14, 0x12);
    this->victory_cond_type[4]->set_fixed_position(0x0e, 0x62, 0x14, 0x12);
    this->victory_cond_type_label[0]->set_fixed_position(0x22, 0x12, 0x78, 0x12);
    this->victory_cond_type_label[1]->set_fixed_position(0x22, 0x26, 0x78, 0x12);
    this->victory_cond_type_label[2]->set_fixed_position(0x22, 0x3a, 0x78, 0x12);
    this->victory_cond_type_label[3]->set_fixed_position(0x22, 0x4e, 0x78, 0x12);
    this->victory_cond_type_label[4]->set_fixed_position(0x22, 0x62, 0x78, 0x12);
    this->victory_score_label->set_fixed_position(0xa4, 0x12, 100, 0x12);
    this->victory_score->set_fixed_position(0xa4, 0x28, 100, 0x16);
    this->victory_time_label->set_fixed_position(0xa4, 0x12, 0xdc, 0x12);
    this->victory_time->set_fixed_position(0xa4, 0x28, 0xdc, 0x16);
    this->victory_cond_on[0]->set_fixed_position(0xa4, 0x12, 0x14, 0x12);
    this->victory_cond_on[1]->set_fixed_position(0xa4, 0x26, 0x14, 0x12);
    this->victory_cond_on[2]->set_fixed_position(0xa4, 0x3a, 0x14, 0x12);
    this->victory_cond_on[3]->set_fixed_position(0xa4, 0x4e, 0x14, 0x12);
    this->victory_cond_on[4]->set_fixed_position(0xa4, 0x62, 0x14, 0x12);
    this->victory_cond_on[5]->set_fixed_position(0xa4, 0x76, 0x14, 0x12);
    this->victory_label_conquest->set_fixed_position(0xb8, 0x12, 0x82, 0x12);
    this->victory_label_explore->set_fixed_position(0xb8, 0x26, 0x82, 0x12);
    this->victory_label_ruins->set_fixed_position(0xb8, 0x3a, 0x82, 0x12);
    this->victory_label_artifacts->set_fixed_position(0xb8, 0x4e, 0x82, 0x12);
    this->victory_label_discoveries->set_fixed_position(0xb8, 0x62, 0x82, 0x12);
    this->victory_amount_label->set_fixed_position(0x126, 0, 0x5a, 0x12);
    this->victory_condition_explore->set_fixed_position(0x126, 0x26, 0x3c, 0x12);
    this->victory_condition_ruins->set_fixed_position(0x126, 0x3a, 0x3c, 0x12);
    this->victory_condition_artifacts->set_fixed_position(0x126, 0x4e, 0x3c, 0x12);
    this->victory_condition_discoveries->set_fixed_position(0x126, 0x62, 0x3c, 0x12);
    this->victory_and_or[0]->set_fixed_position(0x180, 0x12, 0x14, 0x12);
    this->victory_and_or[1]->set_fixed_position(0x180, 0x26, 0x14, 0x12);
    this->victory_text_and_or[0]->set_fixed_position(0x194, 0x12, 0x5a, 0x12);
    this->victory_text_and_or[1]->set_fixed_position(0x194, 0x26, 0x5a, 0x12);

    for (int victory_index = 0; victory_index < 12; ++victory_index) {
        this->victory_button[victory_index]->set_fixed_position(
            ((victory_index / 4) * 0x30) + 0xdc,
            ((victory_index % 4) * 0x1a) + 0x1e, 0x2c, 0x16);
    }
    this->victory_player_list->set_fixed_position(4, 4, 0x96, 0x16);
    this->victory_drop_down->set_fixed_position(4, 0x1c, 0xb4, 0x16);
    this->victory_condition_text->set_fixed_position(0xdc, 4, 0x8c, 0x16);
    this->victory_button_set_object->set_fixed_position(4, 0x38, 0x96, 0x16);
    this->victory_button_set_destination->set_fixed_position(4, 0x52, 0x96, 0x16);
    this->victory_button_go_to_dest->set_fixed_position(4, 0x6c, 0x96, 0x16);
    this->victory_amount_text->set_fixed_position(0xa0, 0x50, 0x3c, 0x16);
    this->victory_amount_input->set_fixed_position(0xa0, 0x66, 0x32, 0x16);
    this->victory_enemy_player_list->set_fixed_position(4, 0x66, 0x96, 0x16);
    this->victory_attribute_list->set_fixed_position(4, 0x38, 0xb4, 0x16);
    this->victory_which_enemy_text->set_fixed_position(4, 0x50, 0x96, 0x16);
    this->victory_object_list->set_fixed_position(4, 0x38, 0xb4, 0x16);
    this->victory_ages_list->set_fixed_position(4, 0x38, 0xb4, 0x16);
    this->victory_tech_list->set_fixed_position(4, 0x38, 0xb4, 0x16);

    int message_y = 8;
    TTextPanel** message_label = this->message_button_label;
    do {
        ((TButtonPanel*)message_label[-5])->set_fixed_position(4, message_y, 0x1e, 0x12);
        (*message_label)->set_fixed_position(0x24, message_y, 0x82, 0x12);
        message_y += 0x19;
        ++message_label;
    } while (message_y < 0x85);

    this->message_input->set_positioning(7, 0xaf, 4, 0x28, 4, 0, 0, 0, 0, 0, 0, 0, 0);

    int cinematic_y = 0x16;
    TDropDownPanel** cinematic_input = this->cinematic_input;
    do {
        ((TTextPanel*)cinematic_input[-4])->set_fixed_position(4, cinematic_y - 0x12, 0xaa, 0x12);
        (*cinematic_input)->set_fixed_position(4, cinematic_y, 0xaa, 0x16);
        cinematic_y += 0x2c;
        ++cinematic_input;
    } while (cinematic_y < 0x9a);
    this->cinematic_label[3]->set_fixed_position(0xb2, 4, 0xaa, 0x12);
    this->cinematic_input[3]->set_fixed_position(0xb2, 0x16, 0xaa, 0x16);

    int option_y = 0x2c;
    TTextPanel** option_panel = this->options_label;
    do {
        ((TButtonPanel*)option_panel[1])->set_fixed_position(3, option_y, 0x14, 0x14);
        option_panel[0]->set_fixed_position(0x16, option_y, 0x87, 0x14);
        option_panel += 1;
        option_y += 0x1a;
    } while (option_y < 0x46);
    this->options_disable_tech_text->set_fixed_position(0xa0, 3, 0xa0, 0x16);
    this->options_player_list->set_fixed_position(3, 3, 0x96, 0x16);

    TTextPanel** option_text = this->options_disable_text;
    int disable_y = 0x1a;
    do {
        ((TButtonPanel*)option_text[-0x10])->set_fixed_position(0xa0, disable_y, 0x14, 0x14);
        (*option_text)->set_fixed_position(0xb4, disable_y, 0x87, 0x14);
        disable_y += 0x14;
        ++option_text;
    } while (disable_y < 0x7e);
    option_text = this->options_disable_text + 5;
    disable_y = 0x1a;
    do {
        ((TButtonPanel*)option_text[-0x10])->set_fixed_position(0x13b, disable_y, 0x14, 0x14);
        (*option_text)->set_fixed_position(0x14f, disable_y, 0x87, 0x14);
        disable_y += 0x14;
        ++option_text;
    } while (disable_y < 0x7e);
    option_text = this->options_disable_text + 10;
    disable_y = 6;
    do {
        ((TButtonPanel*)option_text[-0x10])->set_fixed_position(0x1d6, disable_y, 0x14, 0x14);
        (*option_text)->set_fixed_position(0x1ea, disable_y, 0x87, 0x14);
        disable_y += 0x14;
        ++option_text;
    } while (disable_y < 0x7e);

    this->Diplomacy_player_list->set_fixed_position(4, 4, 0x96, 0x16);
    int diplomacy_x = 0x96;
    TButtonPanel** allied = this->Diplomacy_AlliedVictory;
    TButtonPanel** friend_box = this->Diplomacy_friend_box[0] + 1;
    do {
        ((TTextPanel*)allied[-0x25])->set_fixed_position(diplomacy_x, 0x1c, 0x1e, 0x16);
        (*(friend_box - 1))->set_fixed_position(diplomacy_x, 0x34, 0x1a, 0x12);
        (*friend_box)->set_fixed_position(diplomacy_x, 0x48, 0x1a, 0x12);
        friend_box[1]->set_fixed_position(diplomacy_x, 0x5c, 0x1a, 0x12);
        (*allied)->set_fixed_position(diplomacy_x, 0x70, 0x1a, 0x12);
        diplomacy_x += 0x1f;
        ++allied;
        friend_box += 3;
    } while (diplomacy_x < 0x18e);

    this->Diplomacy_status_label[0]->set_fixed_position(2, 0x34, 0x91, 0x16);
    this->Diplomacy_status_label[1]->set_fixed_position(2, 0x48, 0x91, 0x16);
    this->Diplomacy_status_label[2]->set_fixed_position(2, 0x5c, 0x91, 0x16);
    this->Diplomacy_status_label[3]->set_fixed_position(2, 0x70, 0x91, 0x16);
}

// VA: 004B29E0 TRIBE_Screen_Sed::activate_victory_panel.

void TRIBE_Screen_Sed::activate_victory_panel(int flag)
{
    int i = 0;
    TButtonPanel** pp = this->victory_button;
    do {
        (*pp)->set_active(flag);
        int val = ((this->world->scenario->GetSPVictoryType(i) ? -1 : 0) & 2) + (this->CurrentVictory == i);
        if (flag) {
            (*pp)->set_state(val);
        }
        ++i;
        ++pp;
    } while (i < 12);

    this->victory_drop_down->set_active(flag);
    this->victory_condition_text->set_active(flag);
    this->victory_player_list->set_active(flag);
    if (flag) {
        this->victory_player_list->set_line((int)this->player_num - 1);
    } else {
        this->player_num = (short)(this->victory_player_list->get_line() + 1);
    }
}

// VA: 004B2AA0 TRIBE_Screen_Sed::MakeFileList.

int TRIBE_Screen_Sed::MakeFileList(TDropDownPanel* list, char* directory,
                                   char* extension, unsigned char show_none,
                                   unsigned char show_random)
{
    char path[260];
    char file_name[260];
    FindDataLocal file_info;
    int count;
    int extension_strlen;
    long handle;

    count = 0;
    list->empty_list();
    if (show_none) {
        list->append_line(0x2775, 0);
    }
    if (show_random) {
        list->append_line(0x277B, 0);
    }

    sprintf(path, "%s*%s", directory, extension);
    handle = _findfirst(path, &file_info);
    extension_strlen = strlen(extension);
    if (handle != -1) {
        do {
            ++count;
            int length = strlen(file_info.name);
            length -= extension_strlen;
            strncpy(file_name, file_info.name, length);
            file_name[length] = 0;
            list->append_line(file_name, 0);
        } while (_findnext(handle, &file_info) != -1);
    }
    return count;
}

// VA: 004B2BC0 TRIBE_Screen_Sed::Set_player_advance_civilization_text.

int TRIBE_Screen_Sed::Set_player_advance_civilization_text(int)
{
    this->player_advance_civilization_drop->empty_list();
    this->player_advance_civilization_drop->append_line(0x1069, 0);
    this->player_advance_civilization_drop->append_line(0x106A, 1);
    this->player_advance_civilization_drop->append_line(0x106B, 2);
    this->player_advance_civilization_drop->append_line(0x106C, 3);
    this->player_advance_civilization_drop->append_line(0x106D, 4);
    this->player_advance_civilization_drop->setCurrentLineNumber(0);
    this->player_advance_civilization_drop->set_active(0);
    return 1;
}

// VA: 004B2C50 TRIBE_Screen_Sed::SavePlayerActiveStatus.

void TRIBE_Screen_Sed::SavePlayerActiveStatus()
{
    int active_players = this->player_number_list->get_line() + 1;
    int i = 0;

    for (; i < this->world->player_num - 1; ++i) {
        this->world->scenario->Set_player_Active(i, i < active_players);
    }

    this->victory_player_list->empty_list();
    this->victory_enemy_player_list->empty_list();
    this->options_player_list->empty_list();
    this->Diplomacy_player_list->empty_list();
    this->player_list->empty_list();
    this->unit_player_list->empty_list();

    this->unit_player_list->append_line(0x2776, 0);

    if (active_players > 0) {
        int string_id = 0x2865;
        do {
            this->unit_player_list->append_line(string_id, 0);
            this->victory_player_list->append_line(string_id, 0);
            this->victory_enemy_player_list->append_line(string_id, 0);
            this->options_player_list->append_line(string_id, 0);
            this->Diplomacy_player_list->append_line(string_id, 0);
            this->player_list->append_line(string_id, 0);
            ++string_id;
        } while (string_id - 0x2865 < active_players);
    }

    if (this->player_num >= active_players) {
        this->set_player((short)active_players, 0, 0);
    }

    this->victory_player_list->set_line((long)this->player_num - 1);
    this->options_player_list->set_line((long)this->player_num - 1);
    this->Diplomacy_player_list->set_line((long)this->player_num - 1);
    this->player_list->set_line((long)this->player_num - 1);
    this->unit_player_list->set_line((long)this->player_num);
}

// VA: 004B2DD0 TRIBE_Screen_Sed::create_check_box.

int TRIBE_Screen_Sed::create_check_box(TPanel* parent, TButtonPanel** out)
{
    int ok = TEasy_Panel::create_check_box(parent, out, 0, 0, 0, 0, 1, 0);
    if (!ok) return 0;
    (*out)->set_z_order(1, 0);
    (*out)->set_active(0);
    if (this->use_bevels) {
        (*out)->set_bevel_info(3, this->bevel_color1, this->bevel_color2,
                              this->bevel_color3, this->bevel_color4,
                              this->bevel_color5, this->bevel_color6);
    }
    return 1;
}

// VA: 004B2E60 TRIBE_Screen_Sed::create_radio_button.

int TRIBE_Screen_Sed::create_radio_button(TPanel* parent, TButtonPanel** out)
{
    if (!TEasy_Panel::create_radio_button(parent, out, 0, 0, 0, 0, 1, 0))
        return 0;

    (*out)->set_z_order(1, 0);
    (*out)->set_active(0);

    if (this->use_bevels) {
        (*out)->set_bevel_info(3, this->bevel_color1, this->bevel_color2,
                              this->bevel_color3, this->bevel_color4,
                              this->bevel_color5, this->bevel_color6);
    }

    return 1;
}
