#include "../include/scr_sed2.h"
#include "../include/pnl_msg.h"
#include "../include/pnl_btn.h"
#include "../include/Pnl_txt.h"
#include "../include/Pnl_inp.h"
#include "../include/pnl_edit.h"
#include "../include/pnl_drop.h"
#include "../include/pnl_lst.h"
#include "../include/Pnl_scbr.h"
#include "../include/basegame.h"
#include "../include/main.h"
#include "../include/tworld.h"
#include "../include/player.h"
#include "../include/tplayer.h"
#include "../include/scenario.h"
#include "../include/tscenaro.h"
#include "../include/stat_obj.h"
#include "../include/Shape.h"
#include "../include/diam_map.h"
#include "../include/vw_dimap.h"
#include "../include/vw_main.h"
#include "../include/spnl_obj.h"
#include "../include/rge_base_game_global.h"
#include "../include/resource_ids.h"

#include <io.h>
#include <new.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char s_space[];
extern char s_percent_d[];
extern char s_btnbldg_d_shp[];
extern char s_btnunit_shp[];
extern char s_0[];
extern char s_angle_d_star[];
extern char s_percent_d_star[];
extern char s_angle_d[];
extern char s_300[];
extern char s_400[];
extern char s_500[];
extern char s_600[];
extern char s_700[];
extern char s_900[];
extern char s_1200[];
extern char s_1500[];
extern char s_1800[];
extern char s_2100[];
extern char s_2400[];
extern char s_2700[];
extern char s_3000[];
extern char s_800[];
extern char s_592A40[];

const TEditPanel::FormatType FormatText = TEditPanel::FormatText;
const TEditPanel::FormatType FormatUnsignedInt = TEditPanel::FormatUnsignedInt;
const TEditPanel::FormatType FormatMultiLine = TEditPanel::FormatMultiLine;



void TRIBE_Screen_Sed::SaveDisabledItemsInScenario() {
    short player_number = this->player_num;
    if (player_number == 0) {
        this->player_num = 1;
    }

    for (int i = 0; i < 16; i++) {
        int state = this->options_disable_button[i]->get_state();
        if (state != 0) {
            int player_idx = (int)(short)this->player_num - 1;
            static_cast<T_Scenario*>(this->world->scenario)->SetDisabledTechnology(player_idx, i, 0);
        } else {
            int player_idx = (int)(short)this->player_num - 1;
            static_cast<T_Scenario*>(this->world->scenario)->SetDisabledTechnology(player_idx, i, 1);
        }
    }

    long line = this->options_player_list->get_line();
    this->player_num = (short)(line + 1);
}

void TRIBE_Screen_Sed::LoadDisabledItemsFromScenario(void) {
    TButtonPanel** button;
    int i;
    int disabled;

    for (i = 0, button = this->options_disable_button; i < 16; i++, button++) {
        disabled = static_cast<T_Scenario*>(this->world->scenario)->GetDisabledTechnology(this->player_num - 1, i);
        if (disabled != 0) {
            (*button)->set_state(0);
        } else {
            (*button)->set_state(1);
        }
    }
}




void TRIBE_Screen_Sed::save_info_in_scenario() {}

// The victory setters use the typed T_Scenario surface.

void TRIBE_Screen_Sed::save_multi_victory_cond_in_scenario() {
    switch (this->mp_victory_type) {
    case 1:
        static_cast<T_Scenario*>(this->world->scenario)->SetMPVictory(0);
        break;
    case 2:
        static_cast<T_Scenario*>(this->world->scenario)->SetMPVictory(1);
        break;
    case 3:
        static_cast<T_Scenario*>(this->world->scenario)->SetMPVictory(2);
        break;
    case 4:
        static_cast<T_Scenario*>(this->world->scenario)->SetMPVictory(3);
        break;
    default:
        static_cast<T_Scenario*>(this->world->scenario)->SetMPVictory(4);
        break;
    }

    static_cast<T_Scenario*>(this->world->scenario)->SetVictoryScore(this->victory_score->get_id());
    static_cast<T_Scenario*>(this->world->scenario)->SetVictoryTime(this->victory_time->get_id());

    if (this->victory_cond_type[0]->get_state()) {
        static_cast<T_Scenario*>(this->world->scenario)->SetMPVictory(0);
    } else if (this->victory_cond_type[1]->get_state()) {
        static_cast<T_Scenario*>(this->world->scenario)->SetMPVictory(1);
    } else if (this->victory_cond_type[2]->get_state()) {
        static_cast<T_Scenario*>(this->world->scenario)->SetMPVictory(2);
    } else if (this->victory_cond_type[3]->get_state()) {
        static_cast<T_Scenario*>(this->world->scenario)->SetMPVictory(3);
    } else {
        static_cast<T_Scenario*>(this->world->scenario)->SetMPVictory(4);
    }

    static_cast<T_Scenario*>(this->world->scenario)->SetVictoryScore(this->victory_score->get_id());
    static_cast<T_Scenario*>(this->world->scenario)->SetVictoryTime(this->victory_time->get_id());

    if (this->victory_and_or[1]->get_state()) {
        static_cast<T_Scenario*>(this->world->scenario)->Set_victory_all_flag(1);
    } else {
        static_cast<T_Scenario*>(this->world->scenario)->Set_victory_all_flag(0);
    }

    if (!this->victory_cond_on[0]->get_state() && this->victory_cond_type[4]->get_state()) {
        static_cast<T_Scenario*>(this->world->scenario)->Set_Multi_Conquest(0);
    } else {
        static_cast<T_Scenario*>(this->world->scenario)->Set_Multi_Conquest(1);
    }

    int value = atoi(this->victory_condition_explore->currentLine());
    if (this->victory_cond_on[1]->get_state()) {
        if (value < 1) value = 1;
        if (value > 100) value = 100;
        static_cast<T_Scenario*>(this->world->scenario)->Set_Multi_Exploration(value);
    } else {
        static_cast<T_Scenario*>(this->world->scenario)->Set_Multi_Exploration(0);
    }

    value = atoi(this->victory_condition_ruins->currentLine());
    if (this->victory_cond_on[2]->get_state()) {
        static_cast<T_Scenario*>(this->world->scenario)->Set_Multi_Ruins(value);
    } else {
        static_cast<T_Scenario*>(this->world->scenario)->Set_Multi_Ruins(0);
    }

    value = atoi(this->victory_condition_artifacts->currentLine());
    if (this->victory_cond_on[3]->get_state()) {
        static_cast<T_Scenario*>(this->world->scenario)->Set_Multi_Artifacts(value);
    } else {
        static_cast<T_Scenario*>(this->world->scenario)->Set_Multi_Artifacts(0);
    }

    value = atoi(this->victory_condition_discoveries->currentLine());
    if (this->victory_cond_on[4]->get_state()) {
        static_cast<T_Scenario*>(this->world->scenario)->Set_Multi_Discoveries(value);
    } else {
        static_cast<T_Scenario*>(this->world->scenario)->Set_Multi_Discoveries(0);
    }

    value = atoi(this->victory_condition_gold->currentLine());
    if (this->victory_cond_on[5]->get_state()) {
        static_cast<T_Scenario*>(this->world->scenario)->Set_Multi_Gold(value);
    } else {
        static_cast<T_Scenario*>(this->world->scenario)->Set_Multi_Gold(0);
    }
}


void TRIBE_Screen_Sed::save_victory_cond_in_scenario(int which) {
    long x1, y1, x2, y2;
    int VictoryType;
    int ObjectNumber;

    if (this->victory_and_or[1]->get_state()) {
        static_cast<T_Scenario*>(this->world->scenario)->Set_victory_all_flag(1);
    } else {
        static_cast<T_Scenario*>(this->world->scenario)->Set_victory_all_flag(0);
    }

    if (!this->victory_cond_on[0]->get_state() && this->victory_cond_type[4]->get_state()) {
        static_cast<T_Scenario*>(this->world->scenario)->Set_Multi_Conquest(0);
    } else {
        static_cast<T_Scenario*>(this->world->scenario)->Set_Multi_Conquest(1);
    }

    if (which < 0) {
        return;
    }

    int amount = atoi(this->victory_amount_input->currentLine());
    VictoryType = this->victory_drop_down->get_line();
    int player = this->victory_enemy_player_list->get_line() + 1;
    ObjectNumber = this->victory_object_list->get_id();

    this->main_view->get_selection_area(x1, y1, x2, y2, 1);
    this->px1 = (float)x1;
    this->py1 = (float)y1;
    this->px2 = (float)x2;
    this->py2 = (float)y2;

    static_cast<T_Scenario*>(this->world->scenario)->ClearSPVictoryCondition(which);

    switch (VictoryType) {
    case 0:
        return;
    case 1:
        if (this->SelectedObject == 0 || this->DestinationObject == 0) {
            return;
        }
        static_cast<T_Scenario*>(this->world->scenario)->SetSPVictoryType(which, 3);
        static_cast<T_Scenario*>(this->world->scenario)->SetSPObject(which, this->SelectedObject);
        static_cast<T_Scenario*>(this->world->scenario)->SetSPDestObjectID(which, this->DestinationObject);
        return;
    case 2:
        if (this->SelectedObject == 0) {
            return;
        }
        static_cast<T_Scenario*>(this->world->scenario)->SetSPVictoryType(which, 3);
        static_cast<T_Scenario*>(this->world->scenario)->SetSPObject(which, this->SelectedObject);
        static_cast<T_Scenario*>(this->world->scenario)->SetSPRectangle(which, this->px1, this->py1, this->px2, this->py2);
        return;
    case 3:
        static_cast<T_Scenario*>(this->world->scenario)->SetSPVictoryType(which, 2);
        static_cast<T_Scenario*>(this->world->scenario)->SetSPObjectType(which, ObjectNumber);
        static_cast<T_Scenario*>(this->world->scenario)->SetSPAmount(which, amount);
        return;
    case 4:
        static_cast<T_Scenario*>(this->world->scenario)->SetSPVictoryType(which, 2);
        static_cast<T_Scenario*>(this->world->scenario)->SetSPObjectType(which, ObjectNumber);
        static_cast<T_Scenario*>(this->world->scenario)->SetSPAmount(which, amount);
        static_cast<T_Scenario*>(this->world->scenario)->SetSPRectangle(which, this->px1, this->py1, this->px2, this->py2);
        return;
    case 5:
        if (player < 1 || player > 8 || amount == 0) {
            return;
        }
        static_cast<T_Scenario*>(this->world->scenario)->SetSPVictoryType(which, 1);
        static_cast<T_Scenario*>(this->world->scenario)->SetSPPlayerID(which, player);
        static_cast<T_Scenario*>(this->world->scenario)->SetSPObjectType(which, ObjectNumber);
        static_cast<T_Scenario*>(this->world->scenario)->SetSPAmount(which, amount);
        return;
    case 6:
        if (this->SelectedObject == 0) {
            return;
        }
        static_cast<T_Scenario*>(this->world->scenario)->SetSPVictoryType(which, 1);
        static_cast<T_Scenario*>(this->world->scenario)->SetSPObject(which, this->SelectedObject);
        return;
    case 7:
        if (player < 1 || player > 8) {
            return;
        }
        static_cast<T_Scenario*>(this->world->scenario)->SetSPVictoryType(which, 1);
        static_cast<T_Scenario*>(this->world->scenario)->SetSPPlayerID(which, player);
        static_cast<T_Scenario*>(this->world->scenario)->SetSPObjectType(which, ObjectNumber);
        static_cast<T_Scenario*>(this->world->scenario)->SetSPAllFlag(which, 1);
        return;
    case 8:
        if (player < 1 || player > 8) {
            return;
        }
        static_cast<T_Scenario*>(this->world->scenario)->SetSPVictoryType(which, 1);
        static_cast<T_Scenario*>(this->world->scenario)->SetSPPlayerID(which, player);
        return;
    case 9:
        if (this->SelectedObject == 0) {
            return;
        }
        static_cast<T_Scenario*>(this->world->scenario)->SetSPVictoryType(which, 5);
        static_cast<T_Scenario*>(this->world->scenario)->SetSPObject(which, this->SelectedObject);
        return;
    case 10:
        static_cast<T_Scenario*>(this->world->scenario)->SetSPVictoryType(which, 4);
        static_cast<T_Scenario*>(this->world->scenario)->SetSPAttribType(which, 0);
        static_cast<T_Scenario*>(this->world->scenario)->SetSPAmount(which, amount);
        return;
    case 11:
        static_cast<T_Scenario*>(this->world->scenario)->SetSPVictoryType(which, 4);
        static_cast<T_Scenario*>(this->world->scenario)->SetSPAttribType(which, 3);
        static_cast<T_Scenario*>(this->world->scenario)->SetSPAmount(which, amount);
        return;
    case 12:
        static_cast<T_Scenario*>(this->world->scenario)->SetSPVictoryType(which, 4);
        static_cast<T_Scenario*>(this->world->scenario)->SetSPAttribType(which, 1);
        static_cast<T_Scenario*>(this->world->scenario)->SetSPAmount(which, amount);
        return;
    case 13:
        static_cast<T_Scenario*>(this->world->scenario)->SetSPVictoryType(which, 4);
        static_cast<T_Scenario*>(this->world->scenario)->SetSPAttribType(which, 2);
        static_cast<T_Scenario*>(this->world->scenario)->SetSPAmount(which, amount);
        return;
    case 14:
        static_cast<T_Scenario*>(this->world->scenario)->SetSPVictoryType(which, 4);
        static_cast<T_Scenario*>(this->world->scenario)->SetSPAttribType(which, 4);
        static_cast<T_Scenario*>(this->world->scenario)->SetSPAmount(which, amount);
        return;
    case 15:
        static_cast<T_Scenario*>(this->world->scenario)->SetSPVictoryType(which, 4);
        static_cast<T_Scenario*>(this->world->scenario)->SetSPAttribType(which, 5);
        static_cast<T_Scenario*>(this->world->scenario)->SetSPAmount(which, this->victory_ages_list->get_line() + 1);
        return;
    case 16:
        static_cast<T_Scenario*>(this->world->scenario)->SetSPVictoryType(which, 4);
        static_cast<T_Scenario*>(this->world->scenario)->SetSPAttribType(which, 6);
        static_cast<T_Scenario*>(this->world->scenario)->SetSPAmount(which, amount);
        return;
    case 17:
        static_cast<T_Scenario*>(this->world->scenario)->SetSPVictoryType(which, 6);
        static_cast<T_Scenario*>(this->world->scenario)->SetSPAttribType(which, this->victory_attribute_list->get_id());
        static_cast<T_Scenario*>(this->world->scenario)->SetSPAmount(which, amount);
        return;
    case 18:
        static_cast<T_Scenario*>(this->world->scenario)->SetSPVictoryType(which, 7);
        static_cast<T_Scenario*>(this->world->scenario)->SetSPAttribType(which, this->victory_tech_list->get_id());
        return;
    default:
        return;
    }
}

// Case 1 tests the amount home, not the destination-object
// home. The shipped UI can select a line from the amount value.

void TRIBE_Screen_Sed::load_victory_cond_from_scenario(int which) {
    char str[40];
    RGE_Static_Object* destobj;
    int Amount;
    int VictoryType;
    long x1, y1, x2, y2;
    RGE_Static_Object* obj;

    int all_players = static_cast<T_Scenario*>(this->world->scenario)->Get_victory_all_flag();
    if (all_players != 0) {
        this->victory_and_or[0]->set_state(0);
        this->victory_and_or[1]->set_state(1);
    } else {
        this->victory_and_or[0]->set_state(1);
        this->victory_and_or[1]->set_state(0);
    }

    if (which < 0) return;
    this->SelectedObject = 0;
    this->DestinationObject = 0;
    static_cast<T_Scenario*>(this->world->scenario)->rehook();
    static_cast<T_Scenario*>(this->world->scenario)->SetSPWhich((int)this->player_num - 1);
    Amount = static_cast<T_Scenario*>(this->world->scenario)->GetSPAmount(which);
    itoa(Amount, str, 10);
    this->victory_amount_input->set_text(str);
    this->victory_enemy_player_list->set_line(static_cast<T_Scenario*>(this->world->scenario)->GetSPPlayerID(which) - 1);
    this->victory_object_list->setCurrentLineNumber(this->victory_object_list->get_line(static_cast<T_Scenario*>(this->world->scenario)->GetSPObjectType(which)));
    obj = static_cast<T_Scenario*>(this->world->scenario)->GetSPObject(which);
    destobj = static_cast<T_Scenario*>(this->world->scenario)->GetSPDestObjectID(which);
    this->SelectedObject = obj;
    this->DestinationObject = destobj;
    VictoryType = static_cast<T_Scenario*>(this->world->scenario)->GetSPVictoryType(which);
    int AttributeType = static_cast<T_Scenario*>(this->world->scenario)->GetSPAttribType(which);
    static_cast<T_Scenario*>(this->world->scenario)->GetSPRectangle(which, &this->px1, &this->py1, &this->px2, &this->py2);
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
            this->victory_ages_list->setCurrentLineNumber(static_cast<T_Scenario*>(this->world->scenario)->GetSPAmount(which)-1);
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
        // The destination object does not select line 5 in this case.
        if (Amount != 0) this->victory_drop_down->setCurrentLineNumber(5);
        else if (obj != 0) this->victory_drop_down->setCurrentLineNumber(6);
        else if (static_cast<T_Scenario*>(this->world->scenario)->GetSPAllFlag(which)) this->victory_drop_down->setCurrentLineNumber(7);
        else this->victory_drop_down->setCurrentLineNumber(8);
        break;
    case 2:
        static_cast<T_Scenario*>(this->world->scenario)->GetSPRectangle(which, &this->px1, &this->py1, &this->px2, &this->py2);
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

// Zero score and time values use the default entries.

void TRIBE_Screen_Sed::load_multi_victory_cond_from_scenario() {
    char str[20];
    int value = static_cast<T_Scenario*>(this->world->scenario)->GetMPVictory();

    switch (value) {
    case 0:
        this->mp_victory_type = TRIBE_Screen_Sed::VictoryTypeStandardValue;
        break;
    case 1:
        this->mp_victory_type = TRIBE_Screen_Sed::VictoryTypeConquestValue;
        break;
    case 2:
        this->mp_victory_type = TRIBE_Screen_Sed::VictoryTypeScoreValue;
        break;
    case 3:
        this->mp_victory_type = TRIBE_Screen_Sed::VictoryTypeTimeValue;
        break;
    default:
        this->mp_victory_type = TRIBE_Screen_Sed::VictoryTypeCustomValue;
        break;
    }

    value = static_cast<T_Scenario*>(this->world->scenario)->GetVictoryScore();
    if (value != 0) {
        this->victory_score->set_line(this->victory_score->get_line(value));
    } else {
        this->victory_score->set_line(this->victory_score->get_line(900));
    }

    value = static_cast<T_Scenario*>(this->world->scenario)->GetVictoryTime();
    if (value != 0) {
        this->victory_time->set_line(this->victory_time->get_line(value));
    } else {
        this->victory_time->set_line(this->victory_time->get_line(9000));
    }

    if (static_cast<T_Scenario*>(this->world->scenario)->Get_victory_all_flag() != 0) {
        this->victory_and_or[1]->set_radio_button();
    } else {
        this->victory_and_or[0]->set_radio_button();
    }

    if (static_cast<T_Scenario*>(this->world->scenario)->Get_Multi_Conquest() != 0) {
        this->victory_cond_on[0]->set_state(1);
    } else {
        this->victory_cond_on[0]->set_state(0);
    }

    value = static_cast<T_Scenario*>(this->world->scenario)->Get_Multi_Exploration();
    if (value != 0) {
        this->victory_cond_on[1]->set_state(1);
        itoa(value, str, 10);
        this->victory_condition_explore->set_text(str);
    } else {
        this->victory_cond_on[1]->set_state(0);
        this->victory_condition_explore->set_text(s_592A40);
    }

    value = static_cast<T_Scenario*>(this->world->scenario)->Get_Multi_Ruins();
    if (value != 0) {
        this->victory_cond_on[2]->set_state(1);
        itoa(value, str, 10);
        this->victory_condition_ruins->set_text(str);
    } else {
        this->victory_cond_on[2]->set_state(0);
        this->victory_condition_ruins->set_text(s_592A40);
    }

    value = static_cast<T_Scenario*>(this->world->scenario)->Get_Multi_Artifacts();
    if (value != 0) {
        this->victory_cond_on[3]->set_state(1);
        itoa(value, str, 10);
        this->victory_condition_artifacts->set_text(str);
    } else {
        this->victory_cond_on[3]->set_state(0);
        this->victory_condition_artifacts->set_text(s_592A40);
    }

    value = static_cast<T_Scenario*>(this->world->scenario)->Get_Multi_Discoveries();
    if (value != 0) {
        this->victory_cond_on[4]->set_state(1);
        itoa(value, str, 10);
        this->victory_condition_discoveries->set_text(str);
    } else {
        this->victory_cond_on[4]->set_state(0);
        this->victory_condition_discoveries->set_text(s_592A40);
    }

    value = static_cast<T_Scenario*>(this->world->scenario)->Get_Multi_Gold();
    if (value != 0) {
        this->victory_cond_on[5]->set_state(1);
        itoa(value, str, 10);
        this->victory_condition_gold->set_text(str);
    } else {
        this->victory_cond_on[5]->set_state(0);
        this->victory_condition_gold->set_text(s_592A40);
    }

    static_cast<T_Scenario*>(this->world->scenario)->Save_victory_conditions_into_players(1);
}



void TRIBE_Screen_Sed::save_diplomacy_in_scenario(int which) {
    if (which < 0) return;

    for (int i = 0; i < 8; i++) {
        int state = Diplomacy_friend_box[i][0]->get_state();
        if (state == 1) {
            static_cast<T_Scenario*>(world->scenario)->Set_player_attitude(which, i, 0);
        } else {
            state = Diplomacy_friend_box[i][1]->get_state();
            if (state == 1) {
                static_cast<T_Scenario*>(world->scenario)->Set_player_attitude(which, i, 1);
            } else {
                state = Diplomacy_friend_box[i][2]->get_state();
                if (state == 1) {
                    static_cast<T_Scenario*>(world->scenario)->Set_player_attitude(which, i, 3);
                }
            }
        }
    }

    int allied_victory = Diplomacy_AlliedVictory[which]->get_state();
    static_cast<T_Scenario*>(world->scenario)->SetPlayerAlliedVictory(which, allied_victory);
}

// TRIBE_Screen_Sed::load_diplomacy_from_scenario
// Each diplomacy row clears its allied-victory button before
// the selected attitude and final player-specific state are applied.

void TRIBE_Screen_Sed::load_diplomacy_from_scenario(int which) {
    if (which >= 0) {
        int i = 0;
        do {
            int attitude = static_cast<T_Scenario*>(this->world->scenario)->Get_player_attitude(which, i);
            if (attitude == 0)
                this->Diplomacy_friend_box[i][0]->set_radio_button();
            if (attitude == 1)
                this->Diplomacy_friend_box[i][1]->set_radio_button();
            if (attitude == 3)
                this->Diplomacy_friend_box[i][2]->set_radio_button();
            this->Diplomacy_AlliedVictory[i]->set_state(0);
            i++;
        } while (i < 8);
        this->Diplomacy_AlliedVictory[which]->set_state(
            static_cast<T_Scenario*>(this->world->scenario)->GetPlayerAlliedVictory(which));
    }
}


void TRIBE_Screen_Sed::activate_victory_proper_fields(int TypeOfVictory, int activate) {
    TPanel* ptr[2];

    this->SelectRegionFlag = TRIBE_Screen_Sed::SelectOff;
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
        this->victory_amount_input->set_help_info(STRING_ID_HELP_EDITOR_OBJECT_AMOUNT, -1);
        this->bottom_panel->set_curr_child(this->victory_amount_input);
        break;
    case 4:
        this->victory_object_list->set_active(activate);
        this->victory_amount_text->set_active(activate);
        this->victory_amount_input->set_active(activate);
        this->victory_amount_input->set_help_info(STRING_ID_HELP_EDITOR_OBJECT_AMOUNT_2, -1);
        this->bottom_panel->set_curr_child(this->victory_amount_input);
        this->victory_button_set_destination->set_active(activate);
        this->victory_button_go_to_dest->set_active(activate);
        break;
    case 5:
        this->victory_object_list->set_active(activate);
        this->victory_amount_text->set_active(activate);
        this->victory_amount_input->set_active(activate);
        this->victory_which_enemy_text->set_active(activate);
        this->victory_amount_input->set_help_info(STRING_ID_HELP_EDITOR_OBJECT_AMOUNT_3, -1);
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
        this->victory_amount_input->set_help_info(STRING_ID_HELP_EDITOR_GOLD_AMOUNT, -1);
        this->victory_amount_text->set_active(activate);
        this->victory_amount_input->set_active(activate);
        this->bottom_panel->set_curr_child(this->victory_amount_input);
        break;
    case 11:
        this->victory_amount_input->set_help_info(STRING_ID_HELP_EDITOR_FOOD_AMOUNT, -1);
        this->victory_amount_text->set_active(activate);
        this->victory_amount_input->set_active(activate);
        this->bottom_panel->set_curr_child(this->victory_amount_input);
        break;
    case 12:
        this->victory_amount_input->set_help_info(STRING_ID_HELP_EDITOR_WOOD_AMOUNT, -1);
        this->victory_amount_text->set_active(activate);
        this->victory_amount_input->set_active(activate);
        this->bottom_panel->set_curr_child(this->victory_amount_input);
        break;
    case 13:
        this->victory_amount_input->set_help_info(STRING_ID_HELP_EDITOR_STONE_AMOUNT, -1);
        this->victory_amount_text->set_active(activate);
        this->victory_amount_input->set_active(activate);
        this->bottom_panel->set_curr_child(this->victory_amount_input);
        break;
    case 14:
        this->victory_amount_input->set_help_info(STRING_ID_HELP_EDITOR_POPULATION_AMOUNT, -1);
        this->victory_amount_text->set_active(activate);
        this->victory_amount_input->set_active(activate);
        this->bottom_panel->set_curr_child(this->victory_amount_input);
        break;
    case 16:
        this->victory_amount_input->set_help_info(STRING_ID_HELP_EDITOR_EXPLORATION_AMOUNT_INPUT, -1);
        this->victory_amount_text->set_active(activate);
        this->victory_amount_input->set_active(activate);
        this->bottom_panel->set_curr_child(this->victory_amount_input);
        break;
    case 17:
        this->victory_amount_text->set_active(activate);
        this->victory_amount_input->set_active(activate);
        this->victory_amount_input->set_help_info(STRING_ID_HELP_EDITOR_AMOUNT, -1);
        this->bottom_panel->set_curr_child(this->victory_amount_input);
        this->victory_attribute_list->set_active(activate);
        break;
    case 18:
        this->victory_tech_list->set_active(activate);
        break;
    }
}

// The paired panel arrays are cleared in declared field order.

void TRIBE_Screen_Sed::init_module_variables() {
    TButtonPanel** button_cursor;
    int index;

    this->background_pic = (TShape*)0;
    this->main_view = (TRIBE_Main_View*)0;
    this->map_view = (RGE_Diamond_Map_View*)0;
    this->message_panel = (TMessagePanel*)0;
    this->bottom_panel = (TPanel*)0;
    this->set_player_first_flag = 0;
    button_cursor = this->scenario_mode_button;
    for (index = 10; index != 0; index = index - 1) {
        *button_cursor = (TButtonPanel*)0;
        button_cursor = button_cursor + 1;
    }
    this->menu_button = (TButtonPanel*)0;
    this->help_button = (TButtonPanel*)0;
    this->map_type_label = (TTextPanel*)0;
    for (index = 0; index < 3; ++index) {
        this->map_type_button[index] = (TButtonPanel*)0;
        this->map_type_text[index] = (TTextPanel*)0;
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
    for (index = 0; index < 5; ++index) {
        this->brush_size_button[index] = (TButtonPanel*)0;
        this->brush_size_button_label[index] = (TTextPanel*)0;
    }
    for (index = 0; index < 3; ++index) {
        this->paint_type_button[index] = (TButtonPanel*)0;
        this->paint_type_button_label[index] = (TTextPanel*)0;
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
    for (index = 0; index < 5; ++index) {
        this->player_inven_label[index] = (TTextPanel*)0;
        this->player_inven_input[index] = (TEditPanel*)0;
    }
    for (index = 0; index < 2; ++index) {
        this->player_setting_label[index] = (TTextPanel*)0;
        this->player_setting_drop[index] = (TDropDownPanel*)0;
    }
    this->BuildList = (TDropDownPanel*)0;
    this->CityLayout = (TDropDownPanel*)0;
    this->AiRules = (TDropDownPanel*)0;
    this->unit_player_list = (TDropDownPanel*)0;
    for (index = 0; index < 4; ++index) {
        this->unit_mode_select[index] = (TButtonPanel*)0;
        this->unit_mode_select_label[index] = (TTextPanel*)0;
    }
    this->unit_list = (TListPanel*)0;
    this->unit_scrollbar = (TScrollBarPanel*)0;
    this->unit_list_info = (List_Info*)0;
    this->button_unit_pics = (TShape*)0;
    for (index = 0; index < 5; ++index)
        this->button_bldg_pics[index] = (TShape*)0;
    this->object_panel = (TRIBE_Scenario_Editor_Panel_Object*)0;
    this->unit_list_size = 0;
    button_cursor = this->victory_cond_on;
    for (index = 6; index != 0; index = index - 1) {
        *button_cursor = (TButtonPanel*)0;
        button_cursor = button_cursor + 1;
    }
    for (index = 0; index < 2; ++index) {
        this->victory_and_or[index] = (TButtonPanel*)0;
        this->victory_text_and_or[index] = (TTextPanel*)0;
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
    for (index = 0; index < 5; ++index) {
        this->victory_cond_type_label[index] = (TTextPanel*)0;
        this->victory_cond_type[index] = (TButtonPanel*)0;
    }
    this->victory_score_label = (TTextPanel*)0;
    this->victory_score = (TDropDownPanel*)0;
    this->victory_time_label = (TTextPanel*)0;
    this->victory_time = (TDropDownPanel*)0;
    button_cursor = this->victory_button;
    for (index = 12; index != 0; index = index - 1) {
        *button_cursor = (TButtonPanel*)0;
        button_cursor = button_cursor + 1;
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
    for (index = 0; index < 5; ++index) {
        this->message_button[index] = (TButtonPanel*)0;
        this->message_button_label[index] = (TTextPanel*)0;
    }
    this->message_input = (TEditPanel*)0;
    for (index = 0; index < 4; ++index) {
        this->cinematic_label[index] = (TTextPanel*)0;
        this->cinematic_input[index] = (TDropDownPanel*)0;
    }
    for (index = 0; index < 1; ++index) {
        this->options_label[index] = (TTextPanel*)0;
        this->options_button[index] = (TButtonPanel*)0;
    }
    this->options_player_list = (TDropDownPanel*)0;
    this->options_disable_tech_text = (TTextPanel*)0;
    for (index = 0; index < 16; ++index) {
        this->options_disable_button[index] = (TButtonPanel*)0;
        this->options_disable_text[index] = (TTextPanel*)0;
    }
    this->Diplomacy_player_list = (TDropDownPanel*)0;
    for (index = 0; index < 8; ++index) {
        this->Diplomacy_player_text[index] = (TTextPanel*)0;
        this->Diplomacy_friend_box[index][0] = (TButtonPanel*)0;
        this->Diplomacy_friend_box[index][1] = (TButtonPanel*)0;
        this->Diplomacy_friend_box[index][2] = (TButtonPanel*)0;
        this->Diplomacy_AlliedVictory[index] = (TButtonPanel*)0;
    }
    this->Diplomacy_status_label[0] = (TTextPanel*)0;
    this->Diplomacy_status_label[1] = (TTextPanel*)0;
    this->Diplomacy_status_label[2] = (TTextPanel*)0;
    this->Diplomacy_status_label[3] = (TTextPanel*)0;
    this->world = (TRIBE_World*)0;
}


void TRIBE_Screen_Sed::create_all_buttons_etc() {
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
    if (!(this->create_button(this, cur, STRING_ID_EDITOR_MAP, 1))) goto fail; (*cur)->set_help_info(STRING_ID_HELP_EDITOR_MAP_MODE, -1);
    cur = this->scenario_mode_button + 1;
    if (!(this->create_button(this, cur, STRING_ID_EDITOR_TERRAIN, 1))) goto fail; (*cur)->set_help_info(STRING_ID_HELP_EDITOR_TERRAIN_MODE, -1);
    cur = this->scenario_mode_button + 2;
    if (!(this->create_button(this, cur, STRING_ID_EDITOR_PLAYERS, 1))) goto fail; (*cur)->set_help_info(STRING_ID_HELP_EDITOR_PLAYERS_MODE, -1);
    cur = this->scenario_mode_button + 3;
    if (!(this->create_button(this, cur, STRING_ID_EDITOR_UNITS, 1))) goto fail; (*cur)->set_help_info(STRING_ID_HELP_EDITOR_OBJECTS_MODE, -1);
    cur = this->scenario_mode_button + 4;
    if (!(this->create_button(this, cur, STRING_ID_EDITOR_DIPLOMACY, 1))) goto fail; (*cur)->set_help_info(STRING_ID_HELP_EDITOR_DIPLOMACY_MODE, -1);
    cur = this->scenario_mode_button + 5;
    if (!(this->create_button(this, cur, STRING_ID_EDITOR_INDIVIDUAL_VICTORY, 1))) goto fail; (*cur)->set_help_info(STRING_ID_HELP_EDITOR_VICTORY_MODE, -1);
    cur = this->scenario_mode_button + 6;
    if (!(this->create_button(this, cur, STRING_ID_EDITOR_GLOBAL_VICTORY, 1))) goto fail; (*cur)->set_help_info(STRING_ID_HELP_EDITOR_VICTORY_REQUIREMENTS_MODE, -1);
    cur = this->scenario_mode_button + 7;
    if (!(this->create_button(this, cur, STRING_ID_EDITOR_OPTIONS, 1))) goto fail; (*cur)->set_help_info(STRING_ID_HELP_EDITOR_TECHNOLOGY_MODE, -1);
    cur = this->scenario_mode_button + 8;
    if (!(this->create_button(this, cur, STRING_ID_EDITOR_MESSAGES, 1))) goto fail; (*cur)->set_help_info(STRING_ID_HELP_EDITOR_STORY_MODE, -1);
    cur = this->scenario_mode_button + 9;
    if (!(this->create_button(this, cur, STRING_ID_EDITOR_CINEMATICS, 1))) goto fail; (*cur)->set_help_info(STRING_ID_HELP_EDITOR_CINEMATICS_MODE, -1);

    cur = group;
    count = 10;
    do {
        (*cur)->set_radio_info(group, 10);
        (*cur)->set_active(1);
        ++cur;
        --count;
    } while (count != 0);

    if (!(this->create_button(this, &this->menu_button, STRING_ID_EDITOR_MENU, 0))) goto fail;
    (this->menu_button)->set_help_info(STRING_ID_HELP_EDITOR_MENU, -1);
    this->menu_button->set_active(1);
    if (!(this->create_button(this, &this->help_button, STRING_ID_BUTTON_HELP, 0))) goto fail;
    this->help_button->set_active(1);

    if (!(this->create_text(this->bottom_panel, &this->map_type_label, STRING_ID_EDITOR_MAP_LABEL))) goto fail;
    if (!(this->create_radio_button(this->bottom_panel, &this->map_type_button[0]))) goto fail; (this->map_type_button[0])->set_help_info(STRING_ID_HELP_EDITOR_DEFAULT_TERRAIN, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->map_type_button[1]))) goto fail; (this->map_type_button[1])->set_help_info(STRING_ID_HELP_EDITOR_RANDOM_TERRAIN, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->map_type_button[2]))) goto fail; (this->map_type_button[2])->set_help_info(STRING_ID_HELP_EDITOR_SEEDED_TERRAIN, -1);
    if (!(this->create_text(this->bottom_panel, &this->map_type_text[0], STRING_ID_EDITOR_BLANK_MAP))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->map_type_text[1], STRING_ID_EDITOR_RANDOM_MAP))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->map_type_text[2], STRING_ID_EDITOR_SEED_MAP))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->default_terrain_label, STRING_ID_EDITOR_DEFAULT_TERRAIN))) goto fail;
    if (!(this->create_drop_down(this->bottom_panel, &this->default_terrain_drop))) goto fail; (this->default_terrain_drop)->set_help_info(STRING_ID_HELP_EDITOR_DEFAULT_TERRAIN_SELECT, -1);
    if (!(this->TEasy_Panel::create_text(this->main_view, &this->map_generating_text, STRING_ID_EDITOR_GENERATING_MAP, 0, 0,
                                         (int)(this)->width(), (int)(this)->height() - 200, RGE_FONT_COPPERPLATE_21_BOLD, 1, 1, 0))) goto fail;
    this->map_generating_text->set_active(0);

    if (!(this->create_text(this->bottom_panel, &this->map_size_label, STRING_ID_MAP_SIZE_LABEL))) goto fail;
    if (!(this->create_drop_down(this->bottom_panel, &this->map_size_drop))) goto fail; (this->map_size_drop)->set_help_info(STRING_ID_HELP_EDITOR_MAP_SIZE, -1);
    if (!(this->create_text(this->bottom_panel, &this->map_style_label, STRING_ID_EDITOR_MAP_TYPE_LABEL))) goto fail;
    if (!(this->create_drop_down(this->bottom_panel, &this->map_style_drop))) goto fail; (this->map_style_drop)->set_help_info(STRING_ID_HELP_EDITOR_MAP_TYPE, -1);
    if (!(this->create_text(this->bottom_panel, &this->random_seed_label, STRING_ID_EDITOR_SEED_LABEL))) goto fail;
    if (!(this->create_edit(this->bottom_panel, &this->random_seed_input, s_0, 5, FormatUnsignedInt, 0, 0))) goto fail; (this->random_seed_input)->set_help_info(STRING_ID_HELP_EDITOR_RANDOM_SEED, -1);
    if (!(this->create_text(this->bottom_panel, &this->random_seed_used_label, STRING_ID_EDITOR_SEED_TEXT))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->random_seed_used_text, s_0))) goto fail;
    if (!(this->create_button(this->bottom_panel, &this->generate_map_button, STRING_ID_EDITOR_GENERATE_MAP, 0))) goto fail; (this->generate_map_button)->set_help_info(STRING_ID_HELP_EDITOR_GENERATE_MAP, -1);
    for (i = 0; i < 3; ++i) this->map_type_button[i]->set_radio_info(this->map_type_button, 3);

    if (!(this->create_text(this->bottom_panel, &this->brush_size_label, STRING_ID_EDITOR_BRUSH_SIZE))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->paint_terrain_label, STRING_ID_EDITOR_TERRAIN_LABEL))) goto fail;
    if (!(this->create_radio_button(this->bottom_panel, &this->brush_size_button[0]))) goto fail; (this->brush_size_button[0])->set_help_info(STRING_ID_HELP_EDITOR_BRUSH_SIZE_1, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->brush_size_button[1]))) goto fail; (this->brush_size_button[1])->set_help_info(STRING_ID_HELP_EDITOR_BRUSH_SIZE_2, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->brush_size_button[2]))) goto fail; (this->brush_size_button[2])->set_help_info(STRING_ID_HELP_EDITOR_BRUSH_SIZE_3, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->brush_size_button[3]))) goto fail; (this->brush_size_button[3])->set_help_info(STRING_ID_HELP_EDITOR_BRUSH_SIZE_4, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->brush_size_button[4]))) goto fail; (this->brush_size_button[4])->set_help_info(STRING_ID_HELP_EDITOR_BRUSH_SIZE_5, -1);
    if (!(this->create_text(this->bottom_panel, &this->brush_size_button_label[0], STRING_ID_EDITOR_BRUSH_TINY))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->brush_size_button_label[1], STRING_ID_EDITOR_BRUSH_SMALL))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->brush_size_button_label[2], STRING_ID_EDITOR_BRUSH_MEDIUM))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->brush_size_button_label[3], STRING_ID_EDITOR_BRUSH_LARGE))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->brush_size_button_label[4], STRING_ID_EDITOR_BRUSH_HUGE))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->paint_type_label, STRING_ID_EDITOR_BRUSH_TYPE))) goto fail;
    if (!(this->create_radio_button(this->bottom_panel, &this->paint_type_button[0]))) goto fail; (this->paint_type_button[0])->set_help_info(STRING_ID_HELP_EDITOR_PAINT_TERRAIN, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->paint_type_button[1]))) goto fail; (this->paint_type_button[1])->set_help_info(STRING_ID_HELP_EDITOR_PAINT_ELEVATION, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->paint_type_button[2]))) goto fail; (this->paint_type_button[2])->set_help_info(STRING_ID_HELP_EDITOR_PAINT_CLIFFS, -1);
    if (!(this->create_text(this->bottom_panel, &this->paint_type_button_label[0], STRING_ID_EDITOR_MAP))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->paint_type_button_label[1], STRING_ID_TERRAIN_ELEVATION_LABEL))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->paint_type_button_label[2], STRING_ID_EDITOR_CLIFFS))) goto fail;
    if (!(this->create_list(this->bottom_panel, &this->paint_terrain_list, &this->paint_terrain_scrollbar))) goto fail; (this->paint_terrain_list)->set_help_info(STRING_ID_HELP_EDITOR_TERRAIN_LIST, -1);
    if (!(this->create_list(this->bottom_panel, &this->paint_elevation_list, &this->paint_elevation_scrollbar))) goto fail; (this->paint_elevation_list)->set_help_info(STRING_ID_HELP_EDITOR_ELEVATION_LIST, -1);
    for (i = 0; i < 5; ++i) this->brush_size_button[i]->set_radio_info(this->brush_size_button, 5);
    for (i = 0; i < 3; ++i) this->paint_type_button[i]->set_radio_info(this->paint_type_button, 3);

    if (!(this->create_radio_button(this->bottom_panel, &this->unit_mode_select[0]))) goto fail; (this->unit_mode_select[0])->set_help_info(STRING_ID_HELP_EDITOR_UNIT_PLACE, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->unit_mode_select[1]))) goto fail; (this->unit_mode_select[1])->set_help_info(STRING_ID_HELP_EDITOR_UNIT_DELETE, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->unit_mode_select[2]))) goto fail; (this->unit_mode_select[2])->set_help_info(STRING_ID_HELP_EDITOR_UNIT_MOVE, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->unit_mode_select[3]))) goto fail; (this->unit_mode_select[3])->set_help_info(STRING_ID_HELP_EDITOR_UNIT_ROTATE, -1);
    if (!(this->create_text(this->bottom_panel, &this->unit_mode_select_label[0], STRING_ID_EDITOR_PLACE))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->unit_mode_select_label[1], STRING_ID_EDITOR_DELETE))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->unit_mode_select_label[2], STRING_ID_EDITOR_MOVE))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->unit_mode_select_label[3], STRING_ID_EDITOR_ROTATE))) goto fail;
    for (i = 0; i < 4; ++i) this->unit_mode_select[i]->set_radio_info(this->unit_mode_select, 4);
    this->unit_mode_select[0]->set_radio_button();

    if (!(this->create_list(this, &this->unit_list, &this->unit_scrollbar))) goto fail;
    (this->unit_list)->set_help_info(STRING_ID_HELP_EDITOR_UNIT_LIST, -1);
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

    if (!(this->create_drop_down(this->bottom_panel, &this->unit_player_list))) goto fail; (this->unit_player_list)->set_help_info(STRING_ID_HELP_EDITOR_UNIT_PLAYER, -1);
    {
        RGE_Font* f = rge_base_game->get_font(RGE_FONT_ARIAL_10_NORMAL_ALT);
        this->object_panel = new TRIBE_Scenario_Editor_Panel_Object(this->render_area, this, f->font, f->font_wid, f->font_hgt,
                                                                    this->button_unit_pics, this->button_bldg_pics, 0);
        if (!this->object_panel || this->object_panel->error_code != 0) goto bad;
        this->object_panel->set_active(0);
        this->unit_player_list->set_z_order(1, 0);
    }

    if (!(this->create_text(this->bottom_panel, &this->player_label, STRING_ID_EDITOR_NUMBER_OF_PLAYERS))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->player_starting_age_label, STRING_ID_STARTING_AGE_LABEL_EDITOR))) goto fail;
    if (!(this->create_drop_down(this->bottom_panel, &this->player_advance_civilization_drop))) goto fail; (this->player_advance_civilization_drop)->set_help_info(STRING_ID_HELP_EDITOR_STARTING_AGE, -1);
    this->Set_player_advance_civilization_text(0);
    if (!(this->create_drop_down(this->bottom_panel, &this->player_list))) goto fail; (this->player_list)->set_help_info(STRING_ID_HELP_EDITOR_PLAYER_LIST, -1);
    if (!(this->create_drop_down(this->bottom_panel, &this->player_number_list))) goto fail; (this->player_number_list)->set_help_info(STRING_ID_HELP_EDITOR_PLAYER_COUNT, -1);
    if (!(this->create_text(this->bottom_panel, &this->player_inven_label[0], STRING_ID_RESOURCE_FOOD_LABEL))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->player_inven_label[1], STRING_ID_RESOURCE_WOOD_LABEL))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->player_inven_label[2], STRING_ID_RESOURCE_STONE_LABEL))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->player_inven_label[3], STRING_ID_RESOURCE_GOLD_LABEL))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->player_inven_label[4], STRING_ID_TRIBE_NAME_LABEL))) goto fail;
    for (i = 0; i < 4; ++i) if (!(this->create_edit(this->bottom_panel, &this->player_inven_input[i], s_0, 5, FormatUnsignedInt, 0, 0))) goto fail;
    (this->player_inven_input[0])->set_help_info(STRING_ID_HELP_EDITOR_PLAYER_FOOD, 1);
    (this->player_inven_input[1])->set_help_info(STRING_ID_HELP_EDITOR_PLAYER_WOOD, 1);
    (this->player_inven_input[2])->set_help_info(STRING_ID_HELP_EDITOR_PLAYER_STONE, 1);
    (this->player_inven_input[3])->set_help_info(STRING_ID_HELP_EDITOR_PLAYER_GOLD, 1);
    if (!(this->create_edit(this->bottom_panel, &this->player_inven_input[4], s_592A40, 28, FormatText, 1, 1))) goto fail; (this->player_inven_input[4])->set_help_info(STRING_ID_HELP_EDITOR_TRIBE_NAME, 1);
    if (!(this->create_text(this->bottom_panel, &this->player_setting_label[0], STRING_ID_PLAYER_TYPE_LABEL))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->player_setting_label[1], STRING_ID_CIVILIZATION_LABEL))) goto fail;
    for (i = 0; i < 2; ++i) if (!(this->create_drop_down(this->bottom_panel, &this->player_setting_drop[i]))) goto fail;
    (this->player_setting_drop[0])->set_help_info(STRING_ID_HELP_EDITOR_PLAYER_TYPE, -1);
    (this->player_setting_drop[1])->set_help_info(STRING_ID_HELP_EDITOR_PLAYER_CIVILIZATION, -1);
    if (!(this->create_drop_down(this->bottom_panel, &this->BuildList))) goto fail; (this->BuildList)->set_help_info(STRING_ID_HELP_EDITOR_BUILD_LIST, -1);
    if (!(this->create_drop_down(this->bottom_panel, &this->CityLayout))) goto fail; (this->CityLayout)->set_help_info(STRING_ID_HELP_EDITOR_CITY_LAYOUT, -1);
    if (!(this->create_drop_down(this->bottom_panel, &this->AiRules))) goto fail; (this->AiRules)->set_help_info(STRING_ID_HELP_EDITOR_AI_RULES, -1);
    if (!(this->create_text(this->bottom_panel, &this->player_build_text, STRING_ID_STRATEGY_LABEL))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->player_city_text, STRING_ID_CITY_PLAN_LABEL))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->AiRules_text, STRING_ID_PERSONALITY_LABEL))) goto fail;
    this->set_tab_order((TPanel**)this->player_inven_input, 5);

    if (!(this->create_check_box(this->bottom_panel, &this->victory_cond_on[0]))) goto fail; (this->victory_cond_on[0])->set_help_info(STRING_ID_HELP_EDITOR_VICTORY_CONQUEST, -1);
    if (!(this->create_check_box(this->bottom_panel, &this->victory_cond_on[1]))) goto fail; (this->victory_cond_on[1])->set_help_info(STRING_ID_HELP_EDITOR_VICTORY_EXPLORATION_AMOUNT, -1);
    if (!(this->create_check_box(this->bottom_panel, &this->victory_cond_on[2]))) goto fail; (this->victory_cond_on[2])->set_help_info(STRING_ID_HELP_EDITOR_VICTORY_RUINS, -1);
    if (!(this->create_check_box(this->bottom_panel, &this->victory_cond_on[3]))) goto fail; (this->victory_cond_on[3])->set_help_info(STRING_ID_HELP_EDITOR_VICTORY_ARTIFACTS, -1);
    if (!(this->create_check_box(this->bottom_panel, &this->victory_cond_on[4]))) goto fail; (this->victory_cond_on[4])->set_help_info(STRING_ID_HELP_EDITOR_VICTORY_DISCOVERIES, -1);
    if (!(this->create_check_box(this->bottom_panel, &this->victory_cond_on[5]))) goto fail;
    // This editor help slot is empty in the checked DLL.
    (this->victory_cond_on[5])->set_help_info(STRING_ID_HELP_EDITOR_VICTORY_GOLD, -1);

    if (!(this->create_radio_button(this->bottom_panel, &this->victory_and_or[0]))) goto fail; (this->victory_and_or[0])->set_help_info(STRING_ID_HELP_EDITOR_VICTORY_ANY, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->victory_and_or[1]))) goto fail; (this->victory_and_or[1])->set_help_info(STRING_ID_HELP_EDITOR_VICTORY_ALL, -1);
    for (i = 0; i < 2; ++i) this->victory_and_or[i]->set_radio_info(this->victory_and_or, 2);
    this->victory_and_or[0]->set_radio_button();
    if (!(this->create_text(this->bottom_panel, &this->victory_text_and_or[0], STRING_ID_EDITOR_ANY_ONE))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_text_and_or[1], STRING_ID_EDITOR_ALL))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_amount_label, STRING_ID_EDITOR_QUANTITY_LABEL))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_long_label, STRING_ID_EDITOR_WHICH_CONDITIONS))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_condition_label, STRING_ID_EDITOR_VICTORY_CONDITION_LABEL))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_label_conquest, STRING_ID_VICTORY_CONQUEST))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_label_explore, STRING_ID_EDITOR_EXPLORATION))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_label_explore_percent, STRING_ID_OPTION_DEFAULT))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_label_ruins, STRING_ID_EDITOR_RUINS))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_label_artifacts, STRING_ID_EDITOR_ARTIFACTS))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_label_discoveries, STRING_ID_EDITOR_DISCOVERIES))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_label_gold, STRING_ID_EDITOR_GOLD))) goto fail;
    if (!(this->create_edit(this->bottom_panel, &this->victory_condition_explore, s_space, 3, FormatUnsignedInt, 0, 0))) goto fail; (this->victory_condition_explore)->set_help_info(STRING_ID_HELP_EDITOR_EXPLORATION_AMOUNT, -1);
    if (!(this->create_edit(this->bottom_panel, &this->victory_condition_ruins, s_space, 2, FormatUnsignedInt, 0, 0))) goto fail; (this->victory_condition_ruins)->set_help_info(STRING_ID_HELP_EDITOR_RUINS_AMOUNT, -1);
    if (!(this->create_edit(this->bottom_panel, &this->victory_condition_artifacts, s_space, 2, FormatUnsignedInt, 0, 0))) goto fail; (this->victory_condition_artifacts)->set_help_info(STRING_ID_HELP_EDITOR_ARTIFACTS_AMOUNT, -1);
    if (!(this->create_edit(this->bottom_panel, &this->victory_condition_discoveries, s_space, 2, FormatUnsignedInt, 0, 0))) goto fail; (this->victory_condition_discoveries)->set_help_info(STRING_ID_HELP_EDITOR_DISCOVERIES_AMOUNT, -1);
    if (!(this->create_edit(this->bottom_panel, &this->victory_condition_gold, s_space, 5, FormatUnsignedInt, 0, 0))) goto fail;
    // This editor help slot is empty in the checked DLL.
    (this->victory_condition_gold)->set_help_info(STRING_ID_HELP_EDITOR_VICTORY_GOLD_AMOUNT, -1);
    ptr[0] = this->victory_condition_explore;
    ptr[1] = this->victory_condition_ruins;
    ptr[2] = this->victory_condition_artifacts;
    ptr[3] = this->victory_condition_discoveries;
    this->set_tab_order(ptr, 4);

    if (!(this->create_text(this->bottom_panel, &this->victory_cond_type_label[0], STRING_ID_VICTORY_STANDARD))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_cond_type_label[1], STRING_ID_VICTORY_CONQUEST))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_cond_type_label[2], STRING_ID_VICTORY_SCORE))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_cond_type_label[3], STRING_ID_VICTORY_TIME_LIMIT))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_cond_type_label[4], STRING_ID_EDITOR_CUSTOM_VICTORY))) goto fail;
    if (!(this->create_radio_button(this->bottom_panel, &this->victory_cond_type[0]))) goto fail; (this->victory_cond_type[0])->set_help_info(STRING_ID_HELP_EDITOR_STANDARD_VICTORY, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->victory_cond_type[1]))) goto fail; (this->victory_cond_type[1])->set_help_info(STRING_ID_HELP_EDITOR_CONQUEST, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->victory_cond_type[2]))) goto fail; (this->victory_cond_type[2])->set_help_info(STRING_ID_HELP_EDITOR_SCORE, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->victory_cond_type[3]))) goto fail; (this->victory_cond_type[3])->set_help_info(STRING_ID_HELP_EDITOR_TIME_LIMIT, -1);
    if (!(this->create_radio_button(this->bottom_panel, &this->victory_cond_type[4]))) goto fail; (this->victory_cond_type[4])->set_help_info(STRING_ID_HELP_EDITOR_CUSTOM_VICTORY, -1);
    for (i = 0; i < 5; ++i) this->victory_cond_type[i]->set_radio_info(this->victory_cond_type, 5);
    this->victory_cond_type[1]->set_radio_button();

    if (!(this->create_text(this->bottom_panel, &this->victory_score_label, STRING_ID_VICTORY_SCORE))) goto fail;
    if (!(this->create_drop_down(this->bottom_panel, &this->victory_score))) goto fail; (this->victory_score)->set_help_info(STRING_ID_HELP_EDITOR_SCORE_INPUT, -1);
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

    if (!(this->create_text(this->bottom_panel, &this->victory_time_label, STRING_ID_VICTORY_TIME_LIMIT))) goto fail;
    if (!(this->create_drop_down(this->bottom_panel, &this->victory_time))) goto fail; (this->victory_time)->set_help_info(STRING_ID_HELP_EDITOR_TIME_LIMIT_INPUT, -1);
    this->victory_time->empty_list();
    this->victory_time->append_line(STRING_ID_TIME_LIMIT_BASE, 15000);
    this->victory_time->append_line(STRING_ID_TIME_LIMIT_13000, 13000);
    this->victory_time->append_line(STRING_ID_TIME_LIMIT_11000, 11000);
    this->victory_time->append_line(STRING_ID_TIME_LIMIT_9000, 9000);
    this->victory_time->append_line(STRING_ID_TIME_LIMIT_7000, 7000);
    this->victory_time->append_line(STRING_ID_TIME_LIMIT_5000, 5000);
    this->victory_time->append_line(STRING_ID_TIME_LIMIT_3000, 3000);

    i = 1;
    pp = this->victory_button;
    while (i - 1 < 12) {
        sprintf(str1, s_percent_d, i);
        sprintf(str2, s_angle_d, i);
        sprintf(str3, s_percent_d_star, i);
        sprintf(str4, s_angle_d_star, i);
        if (!(this->create_button(this->bottom_panel, pp, str1, str2, str3, str4))) goto fail;
        (*pp)->set_help_info(STRING_ID_HELP_EDITOR_VICTORY_CONDITION_ROW, -1);
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
    (this->victory_drop_down)->set_help_info(STRING_ID_HELP_EDITOR_VICTORY_TYPE, -1);
    (this->victory_object_list)->set_help_info(STRING_ID_HELP_EDITOR_VICTORY_OBJECT, -1);
    (this->victory_player_list)->set_help_info(STRING_ID_HELP_EDITOR_VICTORY_PLAYER, -1);
    (this->victory_ages_list)->set_help_info(STRING_ID_HELP_EDITOR_VICTORY_AGE, -1);
    (this->victory_enemy_player_list)->set_help_info(STRING_ID_HELP_EDITOR_ENEMY_PLAYER, -1);
    (this->victory_attribute_list)->set_help_info(STRING_ID_HELP_EDITOR_ATTRIBUTE, -1);
    (this->victory_tech_list)->set_help_info(STRING_ID_HELP_EDITOR_TECHNOLOGY, -1);

    if (!(this->create_text(this->bottom_panel, &this->victory_condition_text, STRING_ID_EDITOR_VICTORY_CONDITION))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_condition_type, STRING_ID_EDITOR_VICTORY_TYPE))) goto fail;
    if (!(this->create_button(this->bottom_panel, &this->victory_button_set_object, STRING_ID_EDITOR_SET_OBJECT, 0))) goto fail;
    if (!(this->create_button(this->bottom_panel, &this->victory_button_set_destination, STRING_ID_EDITOR_SET_DESTINATION, 0))) goto fail;
    if (!(this->create_button(this->bottom_panel, &this->victory_button_go_to_dest, STRING_ID_EDITOR_GO_TO_DESTINATION, 0))) goto fail;
    (this->victory_button_set_object)->set_help_info(STRING_ID_HELP_EDITOR_SET_OBJECT, -1);
    (this->victory_button_set_destination)->set_help_info(STRING_ID_HELP_EDITOR_SET_DESTINATION, -1);
    (this->victory_button_go_to_dest)->set_help_info(STRING_ID_HELP_EDITOR_GO_TO_DESTINATION, -1);
    if (!(this->create_text(this->bottom_panel, &this->victory_amount_text, STRING_ID_EDITOR_QUANTITY))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->victory_which_enemy_text, STRING_ID_EDITOR_WHICH_PLAYER))) goto fail;
    if (!(this->create_edit(this->bottom_panel, &this->victory_amount_input, s_0, 5, FormatUnsignedInt, 0, 0))) goto fail;

    for (i = 0; i < 5; ++i) if (!(this->create_radio_button(this->bottom_panel, &this->message_button[i]))) goto fail;
    this->current_message = 0;
    (this->message_button[0])->set_help_info(STRING_ID_HELP_EDITOR_SCENARIO_INSTRUCTIONS, -1);
    (this->message_button[1])->set_help_info(STRING_ID_HELP_EDITOR_HINTS, -1);
    (this->message_button[2])->set_help_info(STRING_ID_HELP_EDITOR_VICTORY_MESSAGE, -1);
    (this->message_button[3])->set_help_info(STRING_ID_HELP_EDITOR_LOSS_MESSAGE, -1);
    (this->message_button[4])->set_help_info(STRING_ID_HELP_EDITOR_HISTORY, -1);
    if (!(this->create_text(this->bottom_panel, &this->message_button_label[0], STRING_ID_EDITOR_SCENARIO_INSTRUCTIONS_LABEL))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->message_button_label[1], STRING_ID_EDITOR_HINTS_LABEL))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->message_button_label[2], STRING_ID_EDITOR_VICTORY_LABEL))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->message_button_label[3], STRING_ID_EDITOR_LOSS_LABEL))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->message_button_label[4], STRING_ID_MISSION_HISTORY))) goto fail;
    for (i = 0; i < 5; ++i) this->message_button[i]->set_radio_info(this->message_button, 5);
    if (!(this->create_edit(this->bottom_panel, &this->message_input, s_592A40, 4095, FormatMultiLine, 1, 1))) goto fail;
    (this->message_input)->set_help_info(-1, -1);

    if (!(this->create_text(this->bottom_panel, &this->cinematic_label[0], STRING_ID_EDITOR_PRE_GAME_CINEMATIC))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->cinematic_label[1], STRING_ID_EDITOR_VICTORY_CINEMATIC_LABEL))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->cinematic_label[2], STRING_ID_EDITOR_LOSS_CINEMATIC_LABEL))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->cinematic_label[3], STRING_ID_EDITOR_SCENARIO_INSTRUCTION_MAP))) goto fail;
    for (i = 0; i < 4; ++i) if (!(this->create_drop_down(this->bottom_panel, &this->cinematic_input[i]))) goto fail;
    (this->cinematic_input[0])->set_help_info(STRING_ID_HELP_EDITOR_INTRO_CINEMATIC, -1);
    (this->cinematic_input[1])->set_help_info(STRING_ID_HELP_EDITOR_VICTORY_CINEMATIC, -1);
    (this->cinematic_input[2])->set_help_info(STRING_ID_HELP_EDITOR_LOSS_CINEMATIC, -1);
    (this->cinematic_input[3])->set_help_info(STRING_ID_HELP_EDITOR_BRIEFING_MAP, -1);

    if (!(this->create_text(this->bottom_panel, &this->options_label[0], STRING_ID_FULL_TECH_TREE_LABEL))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_tech_text, STRING_ID_EDITOR_DISABLE_TECHNOLOGY))) goto fail;
    for (i = 0; i < 1; ++i) if (!(this->create_check_box(this->bottom_panel, &this->options_button[i]))) goto fail;
    (this->options_button[0])->set_help_info(STRING_ID_HELP_EDITOR_FULL_TECH_TREE, -1);
    if (!(this->create_drop_down(this->bottom_panel, &this->options_player_list))) goto fail; (this->options_player_list)->set_help_info(STRING_ID_HELP_EDITOR_OPTIONS_PLAYER, -1);
    for (i = 0; i < 16; ++i) if (!(this->create_check_box(this->bottom_panel, &this->options_disable_button[i]))) goto fail;
    (this->options_disable_button[0])->set_help_info(STRING_ID_HELP_EDITOR_DISABLE_GRANARY, -1);
    (this->options_disable_button[1])->set_help_info(STRING_ID_HELP_EDITOR_DISABLE_STORAGE_PIT, -1);
    (this->options_disable_button[2])->set_help_info(STRING_ID_HELP_EDITOR_DISABLE_DOCK, -1);
    (this->options_disable_button[3])->set_help_info(STRING_ID_HELP_EDITOR_DISABLE_BARRACKS, -1);
    (this->options_disable_button[4])->set_help_info(STRING_ID_HELP_EDITOR_DISABLE_MARKET, -1);
    (this->options_disable_button[5])->set_help_info(STRING_ID_HELP_EDITOR_DISABLE_ARCHERY_RANGE, -1);
    (this->options_disable_button[6])->set_help_info(STRING_ID_HELP_EDITOR_DISABLE_STABLE, -1);
    (this->options_disable_button[7])->set_help_info(STRING_ID_HELP_EDITOR_DISABLE_TEMPLE, -1);
    (this->options_disable_button[8])->set_help_info(STRING_ID_HELP_EDITOR_DISABLE_GOVERNMENT_CENTER, -1);
    (this->options_disable_button[9])->set_help_info(STRING_ID_HELP_EDITOR_DISABLE_SIEGE_WORKSHOP, -1);
    (this->options_disable_button[10])->set_help_info(STRING_ID_HELP_EDITOR_DISABLE_ACADEMY, -1);
    (this->options_disable_button[11])->set_help_info(STRING_ID_HELP_EDITOR_DISABLE_TOOL_AGE, -1);
    (this->options_disable_button[12])->set_help_info(STRING_ID_HELP_EDITOR_DISABLE_BRONZE_AGE, -1);
    (this->options_disable_button[13])->set_help_info(STRING_ID_HELP_EDITOR_DISABLE_IRON_AGE, -1);
    (this->options_disable_button[14])->set_help_info(STRING_ID_HELP_EDITOR_DISABLE_TOWN_CENTER, -1);
    (this->options_disable_button[15])->set_help_info(STRING_ID_HELP_EDITOR_DISABLE_WONDER, -1);
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[0], STRING_ID_EDITOR_DISABLE_GRANARY_LABEL))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[1], STRING_ID_EDITOR_DISABLE_STORAGE_PIT_LABEL))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[2], STRING_ID_EDITOR_DISABLE_DOCK_LABEL))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[3], STRING_ID_EDITOR_DISABLE_BARRACKS_LABEL))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[4], STRING_ID_EDITOR_DISABLE_MARKET_LABEL))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[5], STRING_ID_EDITOR_DISABLE_ARCHERY_LABEL))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[6], STRING_ID_EDITOR_DISABLE_STABLE_LABEL))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[7], STRING_ID_EDITOR_DISABLE_TEMPLE_LABEL))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[8], STRING_ID_EDITOR_DISABLE_GOVERNMENT_CENTER_LABEL))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[9], STRING_ID_EDITOR_DISABLE_SIEGE_WORKSHOP_LABEL))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[10], STRING_ID_EDITOR_DISABLE_ACADEMY_LABEL))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[11], STRING_ID_EDITOR_DISABLE_TOOL_AGE_LABEL))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[12], STRING_ID_EDITOR_DISABLE_BRONZE_AGE_LABEL))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[13], STRING_ID_EDITOR_DISABLE_IRON_AGE_LABEL))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[14], STRING_ID_EDITOR_DISABLE_TOWN_CENTER_LABEL))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->options_disable_text[15], STRING_ID_EDITOR_DISABLE_WONDER_LABEL))) goto fail;

    i = 0;
    tt = this->Diplomacy_player_text;
    while (1) {
        sprintf(str1, s_percent_d, i + 1);
        if (!(this->create_text(this->bottom_panel, tt, str1))) goto fail;
        ++tt;
        ++i;
        if (i >= 8) break;
    }
    if (!(this->create_drop_down(this->bottom_panel, &this->Diplomacy_player_list))) goto fail; (this->Diplomacy_player_list)->set_help_info(STRING_ID_HELP_EDITOR_DIPLOMACY_PLAYER, -1);

    i = 0;
    while (i < 8) {
        if (!(this->create_radio_button(this->bottom_panel, &this->Diplomacy_friend_box[i][0]))) goto fail; (this->Diplomacy_friend_box[i][0])->set_help_info(STRING_ID_HELP_EDITOR_DIPLOMACY_ALLY, -1);
        if (!(this->create_radio_button(this->bottom_panel, &this->Diplomacy_friend_box[i][1]))) goto fail; (this->Diplomacy_friend_box[i][1])->set_help_info(STRING_ID_HELP_EDITOR_DIPLOMACY_NEUTRAL, -1);
        if (!(this->create_radio_button(this->bottom_panel, &this->Diplomacy_friend_box[i][2]))) goto fail; (this->Diplomacy_friend_box[i][2])->set_help_info(STRING_ID_HELP_EDITOR_DIPLOMACY_ENEMY, -1);
        this->Diplomacy_friend_box[i][0]->set_radio_info(this->Diplomacy_friend_box[i], 3);
        this->Diplomacy_friend_box[i][1]->set_radio_info(this->Diplomacy_friend_box[i], 3);
        this->Diplomacy_friend_box[i][2]->set_radio_info(this->Diplomacy_friend_box[i], 3);
        this->Diplomacy_friend_box[i][1]->set_radio_button();
        if (!(this->create_check_box(this->bottom_panel, &this->Diplomacy_AlliedVictory[i]))) goto fail;
        this->Diplomacy_AlliedVictory[i]->set_help_info(STRING_ID_HELP_EDITOR_ALLIED_VICTORY, -1);
        ++i;
    }
    if (!(this->create_text(this->bottom_panel, &this->Diplomacy_status_label[0], STRING_ID_EDITOR_ALLY))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->Diplomacy_status_label[1], STRING_ID_EDITOR_NEUTRAL))) goto fail;
    if (!(this->create_text(this->bottom_panel, &this->Diplomacy_status_label[2], STRING_ID_EDITOR_ENEMY))) goto fail;
    this->create_text(this->bottom_panel, &this->Diplomacy_status_label[3], STRING_ID_EDITOR_ALLIED_VICTORY);

fail:
    return;

bad:
    this->error_code = 1;
    return;
}

// The panel cursor loops follow the adjacent array layout shown
// by the executable.

void TRIBE_Screen_Sed::position_panels() {
    if (this->main_view == 0)
        return;

    for (int mode_row = 0; mode_row < 5; ++mode_row) {
        TButtonPanel* previous = mode_row == 0 ? 0 : this->scenario_mode_button[mode_row - 1];
        this->scenario_mode_button[mode_row]->set_positioning(static_cast<TPanel::PositionMode>(7), 2, 2, 2, 2, 50, 109,
                                                              22, 22, previous, 0, 0, 0);
    }
    for (int mode_col = 5; mode_col < 10; ++mode_col) {
        TButtonPanel* previous = mode_col == 5 ? 0 : this->scenario_mode_button[mode_col - 1];
        this->scenario_mode_button[mode_col]->set_positioning(static_cast<TPanel::PositionMode>(7), 2, 2, 2, 2, 50, 109,
                                                              22, 22, previous, this->scenario_mode_button[mode_col - 5], 0, 0);
    }

    this->menu_button->set_positioning(static_cast<TPanel::PositionMode>(9), 2, 5, 3, 3, 58, 58, 20, 40, 0, 0, 0, 0);
    this->help_button->set_positioning(static_cast<TPanel::PositionMode>(10), 5, 5, 5, 5, 20, 30, 20, 30, 0, 0, 0, 0);
    this->map_view->set_positioning(static_cast<TPanel::PositionMode>(10), 0, 0, 0, 0, 230, 230, 135, 135, 0, 0, 0, 0);
    this->bottom_panel->set_positioning(static_cast<TPanel::PositionMode>(8), 2, 2, 2, 2, 0, 0, 137, 137, 0, 0, this->map_view, 0);
    this->unit_list->set_positioning(static_cast<TPanel::PositionMode>(7), 0, 6, 0, 4, 124, 200, 0, 0, 0, this->menu_button, 0, this->bottom_panel);
    this->object_panel->set_positioning(static_cast<TPanel::PositionMode>(8), 4, 4, 4, 4, 150, 150, 108, 108, 0, 0, 0, 0);

    TScrollBarPanel* unit_panel = (TScrollBarPanel*)this->unit_list;
    int number_lines = ((TTextPanel*)unit_panel)->numberLines();
    int number_draw_lines = ((TTextPanel*)unit_panel)->numberDrawLines();
    if (number_lines > number_draw_lines) {
        this->unit_list->set_positioning(static_cast<TPanel::PositionMode>(7), 0, 6, 0, 4, 104, 220, 0, 0, 0, this->menu_button, 0, this->bottom_panel);
        this->unit_scrollbar->set_positioning(static_cast<TPanel::PositionMode>(7), 1, 1, 0, 2, 18, 18, 0, 0, this->unit_list, this->menu_button, 0, this->bottom_panel);
        unit_panel = this->unit_scrollbar;
    }
    this->main_view->set_positioning(static_cast<TPanel::PositionMode>(7), 0, 6, 0, 4, 0, 0, 0, 0, unit_panel, this->menu_button, 0, this->bottom_panel);
    this->message_panel->set_positioning(static_cast<TPanel::PositionMode>(8), 4, 4, 4, 4, 0, 0, 24, 24, 0, 0, 0, 0);

    this->map_type_label->set_fixed_position(4, 4, 120, 22);
    this->map_type_button[0]->set_fixed_position(4, 22, 22, 22);
    this->map_type_button[1]->set_fixed_position(4, 44, 22, 22);
    this->map_type_button[2]->set_fixed_position(4, 66, 22, 22);
    this->map_type_text[0]->set_fixed_position(36, 22, 115, 22);
    this->map_type_text[1]->set_fixed_position(36, 44, 115, 22);
    this->map_type_text[2]->set_fixed_position(36, 66, 115, 22);
    this->map_size_label->set_fixed_position(170, 4, 130, 22);
    this->map_size_drop->set_fixed_position(170, 22, 170, 22);
    this->map_style_label->set_fixed_position(170, 48, 130, 22);
    this->map_style_drop->set_fixed_position(170, 66, 170, 22);
    this->default_terrain_label->set_fixed_position(170, 48, 130, 22);
    this->default_terrain_drop->set_fixed_position(170, 66, 170, 22);
    this->random_seed_label->set_fixed_position(36, 90, 120, 22);
    this->random_seed_input->set_fixed_position(36, 112, 55, 22);
    this->random_seed_used_label->set_fixed_position(36, 90, 120, 22);
    this->random_seed_used_text->set_fixed_position(36, 112, 55, 22);
    this->generate_map_button->set_fixed_position(180, 96, 130, 38);
    this->paint_terrain_list->set_fixed_position(115, 23, 165, 110);
    this->paint_terrain_label->set_fixed_position(115, 1, 60, 22);
    this->paint_elevation_list->set_fixed_position(115, 23, 165, 110);
    this->paint_type_label->set_fixed_position(2, 1, 110, 20);
    this->paint_type_button[0]->set_fixed_position(2, 23, 30, 22);
    this->paint_type_button[1]->set_fixed_position(2, 45, 30, 22);
    this->paint_type_button[2]->set_fixed_position(2, 67, 30, 22);
    this->paint_type_button_label[0]->set_fixed_position(33, 23, 81, 22);
    this->paint_type_button_label[1]->set_fixed_position(33, 45, 81, 22);
    this->paint_type_button_label[2]->set_fixed_position(33, 67, 81, 22);
    this->brush_size_label->set_fixed_position(280, 4, 110, 20);
    this->brush_size_button[0]->set_fixed_position(282, 23, 30, 22);
    this->brush_size_button[1]->set_fixed_position(282, 45, 30, 22);
    this->brush_size_button[2]->set_fixed_position(282, 67, 30, 22);
    this->brush_size_button[3]->set_fixed_position(282, 89, 30, 22);
    this->brush_size_button[4]->set_fixed_position(282, 111, 30, 22);
    this->brush_size_button_label[0]->set_fixed_position(313, 23, 90, 22);
    this->brush_size_button_label[1]->set_fixed_position(313, 45, 90, 22);
    this->brush_size_button_label[2]->set_fixed_position(313, 67, 90, 22);
    this->brush_size_button_label[3]->set_fixed_position(313, 89, 90, 22);
    this->brush_size_button_label[4]->set_fixed_position(313, 111, 90, 22);

    this->player_label->set_fixed_position(4, 4, 80, 18);
    this->player_starting_age_label->set_fixed_position(4, 92, 95, 18);
    this->player_advance_civilization_drop->set_fixed_position(4, 110, 150, 22);
    this->player_label->set_fixed_position(4, 42, 150, 18);
    this->player_list->set_fixed_position(4, 7, 150, 22);
    this->player_number_list->set_fixed_position(4, 62, 150, 22);

    int x = 166;
    TEditPanel** player_input = this->player_inven_input;
    do {
        int y = 25;
        do {
            ((TTextPanel*)player_input[-5])->set_fixed_position(x, y - 18, 55, 18);
            (*player_input)->set_fixed_position(x, y, 55, 22);
            y += 44;
            ++player_input;
        } while (y < 113);
        x += 68;
    } while (x < 302);

    this->player_inven_label[4]->set_fixed_position(166, 92, 100, 18);
    this->player_inven_input[4]->set_fixed_position(166, 110, 125, 22);

    int setting_y = 25;
    TDropDownPanel** setting_drop = this->player_setting_drop;
    do {
        ((TTextPanel*)setting_drop[-3])->set_fixed_position(500, setting_y - 18, 130, 18);
        (*setting_drop)->set_fixed_position(500, setting_y, 130, 22);
        setting_y += 44;
        ++setting_drop;
    } while (setting_y < 113);

    this->BuildList->set_fixed_position(300, 69, 190, 22);
    this->CityLayout->set_fixed_position(300, 25, 190, 22);
    this->player_build_text->set_fixed_position(300, 51, 130, 18);
    this->player_city_text->set_fixed_position(300, 7, 130, 18);
    this->AiRules_text->set_fixed_position(300, 92, 130, 18);
    this->AiRules->set_fixed_position(300, 110, 190, 22);

    this->unit_player_list->set_fixed_position(4, 4, 150, 22);
    this->unit_mode_select[0]->set_fixed_position(160, 22, 30, 22);
    this->unit_mode_select[1]->set_fixed_position(160, 48, 30, 22);
    this->unit_mode_select[2]->set_fixed_position(160, 74, 30, 22);
    this->unit_mode_select[3]->set_fixed_position(160, 98, 30, 22);
    this->unit_mode_select_label[0]->set_fixed_position(192, 22, 110, 22);
    this->unit_mode_select_label[1]->set_fixed_position(192, 48, 110, 22);
    this->unit_mode_select_label[2]->set_fixed_position(192, 74, 110, 22);
    this->unit_mode_select_label[3]->set_fixed_position(192, 98, 110, 22);

    this->victory_condition_label->set_fixed_position(34, 0, 120, 18);
    this->victory_cond_type[0]->set_fixed_position(14, 18, 20, 18);
    this->victory_cond_type[1]->set_fixed_position(14, 38, 20, 18);
    this->victory_cond_type[2]->set_fixed_position(14, 58, 20, 18);
    this->victory_cond_type[3]->set_fixed_position(14, 78, 20, 18);
    this->victory_cond_type[4]->set_fixed_position(14, 98, 20, 18);
    this->victory_cond_type_label[0]->set_fixed_position(34, 18, 120, 18);
    this->victory_cond_type_label[1]->set_fixed_position(34, 38, 120, 18);
    this->victory_cond_type_label[2]->set_fixed_position(34, 58, 120, 18);
    this->victory_cond_type_label[3]->set_fixed_position(34, 78, 120, 18);
    this->victory_cond_type_label[4]->set_fixed_position(34, 98, 120, 18);
    this->victory_score_label->set_fixed_position(164, 18, 100, 18);
    this->victory_score->set_fixed_position(164, 40, 100, 22);
    this->victory_time_label->set_fixed_position(164, 18, 220, 18);
    this->victory_time->set_fixed_position(164, 40, 220, 22);
    this->victory_cond_on[0]->set_fixed_position(164, 18, 20, 18);
    this->victory_cond_on[1]->set_fixed_position(164, 38, 20, 18);
    this->victory_cond_on[2]->set_fixed_position(164, 58, 20, 18);
    this->victory_cond_on[3]->set_fixed_position(164, 78, 20, 18);
    this->victory_cond_on[4]->set_fixed_position(164, 98, 20, 18);
    this->victory_cond_on[5]->set_fixed_position(164, 118, 20, 18);
    this->victory_label_conquest->set_fixed_position(184, 18, 130, 18);
    this->victory_label_explore->set_fixed_position(184, 38, 130, 18);
    this->victory_label_ruins->set_fixed_position(184, 58, 130, 18);
    this->victory_label_artifacts->set_fixed_position(184, 78, 130, 18);
    this->victory_label_discoveries->set_fixed_position(184, 98, 130, 18);
    this->victory_amount_label->set_fixed_position(294, 0, 90, 18);
    this->victory_condition_explore->set_fixed_position(294, 38, 60, 18);
    this->victory_condition_ruins->set_fixed_position(294, 58, 60, 18);
    this->victory_condition_artifacts->set_fixed_position(294, 78, 60, 18);
    this->victory_condition_discoveries->set_fixed_position(294, 98, 60, 18);
    this->victory_and_or[0]->set_fixed_position(384, 18, 20, 18);
    this->victory_and_or[1]->set_fixed_position(384, 38, 20, 18);
    this->victory_text_and_or[0]->set_fixed_position(404, 18, 90, 18);
    this->victory_text_and_or[1]->set_fixed_position(404, 38, 90, 18);

    for (int victory_index = 0; victory_index < 12; ++victory_index) {
        this->victory_button[victory_index]->set_fixed_position(((victory_index / 4) * 48) + 220,
                                                                ((victory_index % 4) * 26) + 30, 44, 22);
    }
    this->victory_player_list->set_fixed_position(4, 4, 150, 22);
    this->victory_drop_down->set_fixed_position(4, 28, 180, 22);
    this->victory_condition_text->set_fixed_position(220, 4, 140, 22);
    this->victory_button_set_object->set_fixed_position(4, 56, 150, 22);
    this->victory_button_set_destination->set_fixed_position(4, 82, 150, 22);
    this->victory_button_go_to_dest->set_fixed_position(4, 108, 150, 22);
    this->victory_amount_text->set_fixed_position(160, 80, 60, 22);
    this->victory_amount_input->set_fixed_position(160, 102, 50, 22);
    this->victory_enemy_player_list->set_fixed_position(4, 102, 150, 22);
    this->victory_attribute_list->set_fixed_position(4, 56, 180, 22);
    this->victory_which_enemy_text->set_fixed_position(4, 80, 150, 22);
    this->victory_object_list->set_fixed_position(4, 56, 180, 22);
    this->victory_ages_list->set_fixed_position(4, 56, 180, 22);
    this->victory_tech_list->set_fixed_position(4, 56, 180, 22);

    int message_y = 8;
    TTextPanel** message_label = this->message_button_label;
    do {
        ((TButtonPanel*)message_label[-5])->set_fixed_position(4, message_y, 30, 18);
        (*message_label)->set_fixed_position(36, message_y, 130, 18);
        message_y += 25;
        ++message_label;
    } while (message_y < 133);

    this->message_input->set_positioning(static_cast<TPanel::PositionMode>(7), 175, 4, 40, 4, 0, 0, 0, 0, 0, 0, 0, 0);

    int cinematic_y = 22;
    TDropDownPanel** cinematic_input = this->cinematic_input;
    do {
        ((TTextPanel*)cinematic_input[-4])->set_fixed_position(4, cinematic_y - 18, 170, 18);
        (*cinematic_input)->set_fixed_position(4, cinematic_y, 170, 22);
        cinematic_y += 44;
        ++cinematic_input;
    } while (cinematic_y < 154);
    this->cinematic_label[3]->set_fixed_position(178, 4, 170, 18);
    this->cinematic_input[3]->set_fixed_position(178, 22, 170, 22);

    int option_y = 44;
    TTextPanel** option_panel = this->options_label;
    do {
        ((TButtonPanel*)option_panel[1])->set_fixed_position(3, option_y, 20, 20);
        option_panel[0]->set_fixed_position(22, option_y, 135, 20);
        option_panel += 1;
        option_y += 26;
    } while (option_y < 70);
    this->options_disable_tech_text->set_fixed_position(160, 3, 160, 22);
    this->options_player_list->set_fixed_position(3, 3, 150, 22);

    TTextPanel** option_text = this->options_disable_text;
    int disable_y = 26;
    do {
        ((TButtonPanel*)option_text[-0x10])->set_fixed_position(160, disable_y, 20, 20);
        (*option_text)->set_fixed_position(180, disable_y, 135, 20);
        disable_y += 20;
        ++option_text;
    } while (disable_y < 126);
    option_text = this->options_disable_text + 5;
    disable_y = 26;
    do {
        ((TButtonPanel*)option_text[-0x10])->set_fixed_position(315, disable_y, 20, 20);
        (*option_text)->set_fixed_position(335, disable_y, 135, 20);
        disable_y += 20;
        ++option_text;
    } while (disable_y < 126);
    option_text = this->options_disable_text + 10;
    disable_y = 6;
    do {
        ((TButtonPanel*)option_text[-0x10])->set_fixed_position(470, disable_y, 20, 20);
        (*option_text)->set_fixed_position(490, disable_y, 135, 20);
        disable_y += 20;
        ++option_text;
    } while (disable_y < 126);

    this->Diplomacy_player_list->set_fixed_position(4, 4, 150, 22);
    int diplomacy_x = 150;
    TButtonPanel** allied = this->Diplomacy_AlliedVictory;
    TButtonPanel** friend_box = this->Diplomacy_friend_box[0] + 1;
    do {
        ((TTextPanel*)allied[-0x25])->set_fixed_position(diplomacy_x, 28, 30, 22);
        (*(friend_box - 1))->set_fixed_position(diplomacy_x, 52, 26, 18);
        (*friend_box)->set_fixed_position(diplomacy_x, 72, 26, 18);
        friend_box[1]->set_fixed_position(diplomacy_x, 92, 26, 18);
        (*allied)->set_fixed_position(diplomacy_x, 112, 26, 18);
        diplomacy_x += 31;
        ++allied;
        friend_box += 3;
    } while (diplomacy_x < 398);

    this->Diplomacy_status_label[0]->set_fixed_position(2, 52, 145, 22);
    this->Diplomacy_status_label[1]->set_fixed_position(2, 72, 145, 22);
    this->Diplomacy_status_label[2]->set_fixed_position(2, 92, 145, 22);
    this->Diplomacy_status_label[3]->set_fixed_position(2, 112, 145, 22);
}


void TRIBE_Screen_Sed::activate_victory_panel(int activate) {
    int i = 0;
    TButtonPanel** pp = this->victory_button;
    do {
        (*pp)->set_active(activate);
        int state = ((static_cast<T_Scenario*>(this->world->scenario)->GetSPVictoryType(i) ? -1 : 0) & 2) + (this->CurrentVictory == i);
        if (activate) {
            (*pp)->set_state(state);
        }
        ++i;
        ++pp;
    } while (i < 12);

    this->victory_drop_down->set_active(activate);
    this->victory_condition_text->set_active(activate);
    this->victory_player_list->set_active(activate);
    if (activate) {
        this->victory_player_list->set_line((int)this->player_num - 1);
    } else {
        this->player_num = (short)(this->victory_player_list->get_line() + 1);
    }
}


int TRIBE_Screen_Sed::MakeFileList(TDropDownPanel* drop_down, char* dir,
                                   char* extension, unsigned char append_none,
                                   unsigned char append_random) {
    char path[260];
    char file_name[260];
    _finddata_t fileInfo;
    int count;
    int extension_strlen;
    long handle;

    count = 0;
    drop_down->empty_list();
    if (append_none) {
        drop_down->append_line(STRING_ID_EDITOR_NONE, 0);
    }
    if (append_random) {
        drop_down->append_line(STRING_ID_EDITOR_RANDOM, 0);
    }

    sprintf(path, "%s*%s", dir, extension);
    handle = _findfirst(path, &fileInfo);
    extension_strlen = strlen(extension);
    if (handle != -1) {
        do {
            ++count;
            int length = strlen(fileInfo.name);
            length -= extension_strlen;
            strncpy(file_name, fileInfo.name, length);
            file_name[length] = 0;
            drop_down->append_line(file_name, 0);
        } while (_findnext(handle, &fileInfo) != -1);
    }
    return count;
}


int TRIBE_Screen_Sed::Set_player_advance_civilization_text(int newmode) {
    this->player_advance_civilization_drop->empty_list();
    this->player_advance_civilization_drop->append_line(STRING_ID_HELP_AGE_STONE, 0);
    this->player_advance_civilization_drop->append_line(STRING_ID_HELP_AGE_TOOL, 1);
    this->player_advance_civilization_drop->append_line(STRING_ID_HELP_AGE_BRONZE, 2);
    this->player_advance_civilization_drop->append_line(STRING_ID_HELP_AGE_IRON, 3);
    this->player_advance_civilization_drop->append_line(STRING_ID_HELP_AGE_POST_IRON, 4);
    this->player_advance_civilization_drop->setCurrentLineNumber(0);
    this->player_advance_civilization_drop->set_active(0);
    return 1;
}


void TRIBE_Screen_Sed::SavePlayerActiveStatus() {
    int active_players = this->player_number_list->get_line() + 1;
    int i = 0;

    for (; i < this->world->player_num - 1; ++i) {
        static_cast<T_Scenario*>(this->world->scenario)->Set_player_Active(i, i < active_players);
    }

    this->victory_player_list->empty_list();
    this->victory_enemy_player_list->empty_list();
    this->options_player_list->empty_list();
    this->Diplomacy_player_list->empty_list();
    this->player_list->empty_list();
    this->unit_player_list->empty_list();

    this->unit_player_list->append_line(STRING_ID_EDITOR_GAIA, 0);

    if (active_players > 0) {
        int string_id = STRING_ID_PLAYER_NAME_BASE;
        do {
            this->unit_player_list->append_line(string_id, 0);
            this->victory_player_list->append_line(string_id, 0);
            this->victory_enemy_player_list->append_line(string_id, 0);
            this->options_player_list->append_line(string_id, 0);
            this->Diplomacy_player_list->append_line(string_id, 0);
            this->player_list->append_line(string_id, 0);
            ++string_id;
        } while (string_id - STRING_ID_PLAYER_NAME_BASE < active_players);
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


int TRIBE_Screen_Sed::create_check_box(TPanel* parent, TButtonPanel** button) {
    int ok = TEasy_Panel::create_check_box(parent, button, 0, 0, 0, 0, 1, 0);
    if (!ok) return 0;
    (*button)->set_z_order(1, 0);
    (*button)->set_active(0);
    if (this->use_bevels) {
        (*button)->set_bevel_info(3, this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4,
                                  this->bevel_color5, this->bevel_color6);
    }
    return 1;
}


int TRIBE_Screen_Sed::create_radio_button(TPanel* parent, TButtonPanel** button) {
    if (!TEasy_Panel::create_radio_button(parent, button, 0, 0, 0, 0, 1, 0))
        return 0;

    (*button)->set_z_order(1, 0);
    (*button)->set_active(0);

    if (this->use_bevels) {
        (*button)->set_bevel_info(3, this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4,
                                  this->bevel_color5, this->bevel_color6);
    }

    return 1;
}
