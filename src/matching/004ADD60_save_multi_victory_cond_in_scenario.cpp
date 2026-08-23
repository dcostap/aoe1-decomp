// 004ADD60 TRIBE_Screen_Sed::save_multi_victory_cond_in_scenario
// Attempt log:
// 1: direct natural reconstruction from asm/PDB lines with local UI/scenario surfaces.
// 2: The shared scr_sed2 context recovered the canonical world and screen owners.
// 3: PDB-qualified T_Scenario Set_Multi_* calls and TTextPanel::currentLine
//    restored all 40 direct targets and the complete 762-byte function.

#include "../../include/scr_sed2_context.h"

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
