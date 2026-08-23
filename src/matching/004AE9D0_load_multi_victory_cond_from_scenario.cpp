// VA: 004AE9D0 TRIBE_Screen_Sed::load_multi_victory_cond_from_scenario (709 B)
// Attempt log:
// - Replaced the placeholder with a typed scr_sed2.cpp reconstruction.  The
//   fields are the ground-truth screen ownership; scenario getters and panel
//   methods use their period member/virtual surfaces.
// - Duplicating the score/time get_line arms, with the nonzero arm first,
//   recovered VC5's `je` to the late default push and shared call tail.
// - Exact under the default /O2 /Oy VC5 response file.

#include "../../include/scr_sed2_context.h"

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
        this->victory_condition_explore->set_text((char*)0x00586D44);
    }

    value = this->world->scenario->Get_Multi_Ruins();
    if (value != 0) {
        this->victory_cond_on[2]->set_state(1);
        itoa(value, str, 10);
        this->victory_condition_ruins->set_text(str);
    } else {
        this->victory_cond_on[2]->set_state(0);
        this->victory_condition_ruins->set_text((char*)0x00586D44);
    }

    value = this->world->scenario->Get_Multi_Artifacts();
    if (value != 0) {
        this->victory_cond_on[3]->set_state(1);
        itoa(value, str, 10);
        this->victory_condition_artifacts->set_text(str);
    } else {
        this->victory_cond_on[3]->set_state(0);
        this->victory_condition_artifacts->set_text((char*)0x00586D44);
    }

    value = this->world->scenario->Get_Multi_Discoveries();
    if (value != 0) {
        this->victory_cond_on[4]->set_state(1);
        itoa(value, str, 10);
        this->victory_condition_discoveries->set_text(str);
    } else {
        this->victory_cond_on[4]->set_state(0);
        this->victory_condition_discoveries->set_text((char*)0x00586D44);
    }

    value = this->world->scenario->Get_Multi_Gold();
    if (value != 0) {
        this->victory_cond_on[5]->set_state(1);
        itoa(value, str, 10);
        this->victory_condition_gold->set_text(str);
    } else {
        this->victory_cond_on[5]->set_state(0);
        this->victory_condition_gold->set_text((char*)0x00586D44);
    }

    this->world->scenario->Save_victory_conditions_into_players(1);
}
