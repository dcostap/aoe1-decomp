#include "../include/TRIBE_Screen_Sed.h"
#include "../include/TRIBE_World.h"
#include "../include/T_Scenario.h"
#include "../include/TButtonPanel.h"
#include "../include/TDropDownPanel.h"
#include "../include/TEditPanel.h"
#include "../include/TEasy_Panel.h"
#include "../include/RGE_View.h"
#include "../include/TTextPanel.h"

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <io.h>

static T_Scenario* get_scenario(TRIBE_Screen_Sed* this_) {
    if (this_ == nullptr || this_->world == nullptr) {
        return nullptr;
    }
    return static_cast<T_Scenario*>(this_->world->scenario);
}

// Decomp-first transliterations for scr_sed2.cpp offsets implemented in this unit.

// Auto-generated decompiler unit: scr_sed2.cpp.decomp
// SourceMap: C:/msdev/work/age1_x1/scr_sed2.cpp
#include "../include/common.h"

// Offset: 0x004ADC80
void SaveDisabledItemsInScenario(TRIBE_Screen_Sed* this_) {
    // Fully verified. Source of truth: scr_sed2.cpp.decomp @ 0x004ADC80
    T_Scenario* scenario = get_scenario(this_);
    if (this_ == nullptr || scenario == nullptr) {
        return;
    }

    if (this_->player_num == 0) {
        this_->player_num = 1;
    }

    for (int i = 0; i < 0x10; ++i) {
        int state = 0;
        if (this_->options_disable_button[i] != nullptr) {
            state = this_->options_disable_button[i]->get_state();
        }
        scenario->SetDisabledTechnology(this_->player_num - 1, i, (state == 0) ? 1 : 0);
    }

    if (this_->options_player_list != nullptr) {
        this_->player_num = static_cast<short>(this_->options_player_list->get_line()) + 1;
    }
}

// Offset: 0x004ADD00
void LoadDisabledItemsFromScenario(TRIBE_Screen_Sed* this_) {
    // Fully verified. Source of truth: scr_sed2.cpp.decomp @ 0x004ADD00
    T_Scenario* scenario = get_scenario(this_);
    if (this_ == nullptr || scenario == nullptr) {
        return;
    }

    for (int i = 0; i < 0x10; ++i) {
        if (this_->options_disable_button[i] == nullptr) {
            continue;
        }
        const int disabled = scenario->GetDisabledTechnology(this_->player_num - 1, i);
        this_->options_disable_button[i]->set_state(static_cast<short>(disabled == 0 ? 1 : 0));
    }
}

// Offset: 0x004ADD50
void save_info_in_scenario(TRIBE_Screen_Sed* this_) {
    // Fully verified. Source of truth: scr_sed2.cpp.decomp @ 0x004ADD50
    (void)this_;
}


// Offset: 0x004ADD60
void save_multi_victory_cond_in_scenario(TRIBE_Screen_Sed* this_) {
    // Fully verified. Source of truth: scr_sed2.cpp.decomp @ 0x004ADD60
    T_Scenario* scenario = get_scenario(this_);
    if (this_ == nullptr || scenario == nullptr) {
        return;
    }

    int mp_victory = 4;
    switch (this_->mp_victory_type) {
    case TRIBE_Screen_Sed::VictoryTypeStandard:
        mp_victory = 0;
        break;
    case TRIBE_Screen_Sed::VictoryTypeConquest:
        mp_victory = 1;
        break;
    case TRIBE_Screen_Sed::VictoryTypeScore:
        mp_victory = 2;
        break;
    case TRIBE_Screen_Sed::VictoryTypeTime:
        mp_victory = 3;
        break;
    default:
        mp_victory = 4;
        break;
    }

    scenario->SetMPVictory(mp_victory);
    if (this_->victory_score != nullptr) {
        scenario->SetVictoryScore(static_cast<int>(this_->victory_score->get_id()));
    }
    if (this_->victory_time != nullptr) {
        scenario->SetVictoryTime(static_cast<int>(this_->victory_time->get_id()));
    }

    int victory_type = 4;
    if (this_->victory_cond_type[0] != nullptr && this_->victory_cond_type[0]->get_state() != 0) {
        victory_type = 0;
    } else if (this_->victory_cond_type[1] != nullptr && this_->victory_cond_type[1]->get_state() != 0) {
        victory_type = 1;
    } else if (this_->victory_cond_type[2] != nullptr && this_->victory_cond_type[2]->get_state() != 0) {
        victory_type = 2;
    } else if (this_->victory_cond_type[3] != nullptr && this_->victory_cond_type[3]->get_state() != 0) {
        victory_type = 3;
    }

    scenario->SetMPVictory(victory_type);
    if (this_->victory_score != nullptr) {
        scenario->SetVictoryScore(static_cast<int>(this_->victory_score->get_id()));
    }
    if (this_->victory_time != nullptr) {
        scenario->SetVictoryTime(static_cast<int>(this_->victory_time->get_id()));
    }

    const int all_flag =
        (this_->victory_and_or[1] != nullptr && this_->victory_and_or[1]->get_state() != 0) ? 1 : 0;
    scenario->Set_victory_all_flag(all_flag);

    int conquest = 1;
    if (this_->victory_cond_on[0] != nullptr && this_->victory_cond_on[0]->get_state() == 0 &&
        this_->victory_cond_type[4] != nullptr && this_->victory_cond_type[4]->get_state() != 0) {
        conquest = 0;
    }
    scenario->Set_Multi_Conquest(conquest);

    auto parse_edit = [](TEditPanel* panel) -> int {
        if (panel == nullptr) {
            return 0;
        }
        char* text_value = panel->currentLine();
        return (text_value != nullptr) ? std::atoi(text_value) : 0;
    };

    int exploration = parse_edit(this_->victory_condition_explore);
    if (this_->victory_cond_on[1] == nullptr || this_->victory_cond_on[1]->get_state() == 0) {
        exploration = 0;
    } else {
        if (exploration < 1) exploration = 1;
        if (exploration > 100) exploration = 100;
    }
    scenario->Set_Multi_Exploration(exploration);

    int ruins = parse_edit(this_->victory_condition_ruins);
    if (this_->victory_cond_on[2] == nullptr || this_->victory_cond_on[2]->get_state() == 0) {
        ruins = 0;
    }
    scenario->Set_Multi_Ruins(ruins);

    int artifacts = parse_edit(this_->victory_condition_artifacts);
    if (this_->victory_cond_on[3] == nullptr || this_->victory_cond_on[3]->get_state() == 0) {
        artifacts = 0;
    }
    scenario->Set_Multi_Artifacts(artifacts);

    int discoveries = parse_edit(this_->victory_condition_discoveries);
    if (this_->victory_cond_on[4] == nullptr || this_->victory_cond_on[4]->get_state() == 0) {
        discoveries = 0;
    }
    scenario->Set_Multi_Discoveries(discoveries);

    int gold = parse_edit(this_->victory_condition_gold);
    if (this_->victory_cond_on[5] == nullptr || this_->victory_cond_on[5]->get_state() == 0) {
        gold = 0;
    }
    scenario->Set_Multi_Gold(gold);
}

// Offset: 0x004AE05A
void FUN_004ae05a(int param_1) {
    // Fully verified. Source of truth: scr_sed2.cpp.asm @ 0x004AE05A (switch-table data anchor thunk)
    // Fully verified. Source of truth: scr_sed2.cpp.decomp @ 0x004AE05A (switch-table data anchor thunk)
    (void)param_1;
}


// Offset: 0x004AE070
void save_victory_cond_in_scenario(TRIBE_Screen_Sed* this_, int param_2) {
    // Fully verified. Source of truth: scr_sed2.cpp.decomp @ 0x004AE070
    T_Scenario* scenario = get_scenario(this_);
    if (this_ == nullptr || scenario == nullptr) {
        return;
    }

    const int all_flag =
        (this_->victory_and_or[1] != nullptr && this_->victory_and_or[1]->get_state() != 0) ? 1 : 0;
    scenario->Set_victory_all_flag(all_flag);

    int conquest = 1;
    if (this_->victory_cond_on[0] != nullptr && this_->victory_cond_on[0]->get_state() == 0 &&
        this_->victory_cond_type[4] != nullptr && this_->victory_cond_type[4]->get_state() != 0) {
        conquest = 0;
    }
    scenario->Set_Multi_Conquest(conquest);

    if (param_2 < 0) {
        return;
    }

    char* amount_text = (this_->victory_amount_input != nullptr) ? this_->victory_amount_input->currentLine() : nullptr;
    const int amount = (amount_text != nullptr) ? std::atoi(amount_text) : 0;
    const long victory_line = (this_->victory_drop_down != nullptr) ? this_->victory_drop_down->get_line() : 0;
    const int enemy_player =
        (this_->victory_enemy_player_list != nullptr) ? static_cast<int>(this_->victory_enemy_player_list->get_line()) + 1 : 0;
    const long object_type = (this_->victory_object_list != nullptr) ? this_->victory_object_list->get_id() : 0;

    long x1 = 0;
    long y1 = 0;
    long x2 = 0;
    long y2 = 0;
    if (this_->main_view != nullptr) {
        reinterpret_cast<RGE_View*>(this_->main_view)->get_selection_area(&x1, &y1, &x2, &y2, 1);
    }
    this_->px1 = static_cast<float>(x1);
    this_->py1 = static_cast<float>(y1);
    this_->px2 = static_cast<float>(x2);
    this_->py2 = static_cast<float>(y2);

    scenario->ClearSPVictoryCondition(param_2);

    auto set_type4 = [&](int attrib_type) {
        scenario->SetSPVictoryType(param_2, 4);
        scenario->SetSPAttribType(param_2, attrib_type);
        scenario->SetSPAmount(param_2, amount);
    };

    switch (victory_line) {
    case 1:
        if (this_->SelectedObject != nullptr && this_->DestinationObject != nullptr) {
            scenario->SetSPVictoryType(param_2, 3);
            scenario->SetSPObject(param_2, this_->SelectedObject);
            scenario->SetSPDestObjectID(param_2, this_->DestinationObject);
        }
        return;
    case 2:
        if (this_->SelectedObject != nullptr) {
            scenario->SetSPVictoryType(param_2, 3);
            scenario->SetSPObject(param_2, this_->SelectedObject);
            scenario->SetSPRectangle(param_2, this_->px1, this_->py1, this_->px2, this_->py2);
        }
        return;
    case 3:
        scenario->SetSPVictoryType(param_2, 2);
        scenario->SetSPObjectType(param_2, static_cast<int>(object_type));
        scenario->SetSPAmount(param_2, amount);
        return;
    case 4:
        scenario->SetSPVictoryType(param_2, 2);
        scenario->SetSPObjectType(param_2, static_cast<int>(object_type));
        scenario->SetSPAmount(param_2, amount);
        scenario->SetSPRectangle(param_2, this_->px1, this_->py1, this_->px2, this_->py2);
        return;
    case 5:
        if (enemy_player > 0 && enemy_player < 9 && amount != 0) {
            scenario->SetSPVictoryType(param_2, 1);
            scenario->SetSPPlayerID(param_2, enemy_player);
            scenario->SetSPObjectType(param_2, static_cast<int>(object_type));
            scenario->SetSPAmount(param_2, amount);
        }
        return;
    case 6:
        if (this_->SelectedObject != nullptr) {
            scenario->SetSPVictoryType(param_2, 1);
            scenario->SetSPObject(param_2, this_->SelectedObject);
        }
        return;
    case 7:
        if (enemy_player > 0 && enemy_player < 9) {
            scenario->SetSPVictoryType(param_2, 1);
            scenario->SetSPPlayerID(param_2, enemy_player);
            scenario->SetSPObjectType(param_2, static_cast<int>(object_type));
            scenario->SetSPAllFlag(param_2, 1);
        }
        return;
    case 8:
        if (enemy_player > 0 && enemy_player < 9) {
            scenario->SetSPVictoryType(param_2, 1);
            scenario->SetSPPlayerID(param_2, enemy_player);
        }
        return;
    case 9:
        if (this_->SelectedObject != nullptr) {
            scenario->SetSPVictoryType(param_2, 5);
            scenario->SetSPObject(param_2, this_->SelectedObject);
        }
        return;
    case 10:
        set_type4(0);
        return;
    case 0xb:
        set_type4(3);
        return;
    case 0xc:
        set_type4(1);
        return;
    case 0xd:
        set_type4(2);
        return;
    case 0xe:
        set_type4(4);
        return;
    case 0xf:
        scenario->SetSPVictoryType(param_2, 4);
        scenario->SetSPAttribType(param_2, 5);
        scenario->SetSPAmount(param_2, (this_->victory_ages_list != nullptr) ? static_cast<int>(this_->victory_ages_list->get_line()) + 1 : 1);
        return;
    case 0x10:
        set_type4(6);
        return;
    case 0x11:
        scenario->SetSPVictoryType(param_2, 6);
        scenario->SetSPAttribType(param_2, (this_->victory_attribute_list != nullptr) ? static_cast<int>(this_->victory_attribute_list->get_id()) : 0);
        scenario->SetSPAmount(param_2, amount);
        return;
    case 0x12:
        scenario->SetSPVictoryType(param_2, 7);
        scenario->SetSPAttribType(param_2, (this_->victory_tech_list != nullptr) ? static_cast<int>(this_->victory_tech_list->get_id()) : 0);
        return;
    default:
        return;
    }
}

// Offset: 0x004AE620
void load_victory_cond_from_scenario(TRIBE_Screen_Sed* this_, int param_2) {
    // Fully verified. Source of truth: scr_sed2.cpp.decomp @ 0x004AE620
    T_Scenario* scenario = get_scenario(this_);
    if (this_ == nullptr || scenario == nullptr) {
        return;
    }

    const int all_flag = scenario->Get_victory_all_flag();
    if (this_->victory_and_or[0] != nullptr) {
        this_->victory_and_or[0]->set_state(static_cast<short>(all_flag == 0 ? 1 : 0));
    }
    if (this_->victory_and_or[1] != nullptr) {
        this_->victory_and_or[1]->set_state(static_cast<short>(all_flag != 0 ? 1 : 0));
    }

    if (param_2 < 0) {
        return;
    }

    this_->SelectedObject = nullptr;
    this_->DestinationObject = nullptr;
    scenario->SetSPWhich(this_->player_num - 1);

    const int amount = scenario->GetSPAmount(param_2);
    char amount_buffer[32]{};
    std::snprintf(amount_buffer, sizeof(amount_buffer), "%d", amount);
    if (this_->victory_amount_input != nullptr) {
        this_->victory_amount_input->set_text(amount_buffer);
    }

    if (this_->victory_enemy_player_list != nullptr) {
        this_->victory_enemy_player_list->set_line(scenario->GetSPPlayerID(param_2) - 1);
    }

    const int object_type = scenario->GetSPObjectType(param_2);
    if (this_->victory_object_list != nullptr) {
        const long object_line = this_->victory_object_list->get_line(object_type);
        this_->victory_object_list->setCurrentLineNumber(static_cast<int>(object_line));
    }

    this_->SelectedObject = scenario->GetSPObject(param_2);
    this_->DestinationObject = scenario->GetSPDestObjectID(param_2);

    const int victory_type = scenario->GetSPVictoryType(param_2);
    const int attrib_type = scenario->GetSPAttribType(param_2);

    scenario->GetSPRectangle(param_2, &this_->px1, &this_->py1, &this_->px2, &this_->py2);
    if (this_->main_view != nullptr) {
        RGE_View* view = reinterpret_cast<RGE_View*>(this_->main_view);
        view->set_selection_area(-1, -1, -1, -1);
        if (this_->px2 != 0.0f) {
            view->set_selection_area(static_cast<long>(this_->px1), static_cast<long>(this_->py1),
                                     static_cast<long>(this_->px2), static_cast<long>(this_->py2));
        }
    }

    int victory_line = 0;
    switch (victory_type) {
    case 0:
        victory_line = 0;
        break;
    case 1:
        if (amount == 0) {
            if (this_->SelectedObject == nullptr) {
                victory_line = (scenario->GetSPAllFlag(param_2) == 0) ? 8 : 7;
            } else {
                victory_line = 6;
            }
        } else {
            victory_line = 5;
        }
        break;
    case 2:
        victory_line = (this_->px2 <= 0.0f) ? 3 : 4;
        break;
    case 3:
        victory_line = (this_->DestinationObject == nullptr) ? 2 : 1;
        break;
    case 4:
        switch (attrib_type) {
        case 0:
            victory_line = 10;
            break;
        case 1:
            victory_line = 0xc;
            break;
        case 2:
            victory_line = 0xd;
            break;
        case 3:
            victory_line = 0xb;
            break;
        case 4:
            victory_line = 0xe;
            break;
        case 5:
            if (this_->victory_drop_down != nullptr) {
                this_->victory_drop_down->setCurrentLineNumber(0xf);
            }
            if (this_->victory_ages_list != nullptr) {
                this_->victory_ages_list->setCurrentLineNumber(scenario->GetSPAmount(param_2) - 1);
            }
            return;
        case 6:
            victory_line = 0x10;
            break;
        default:
            return;
        }
        break;
    case 5:
        if (this_->SelectedObject == nullptr) {
            return;
        }
        victory_line = 9;
        break;
    case 6:
        if (this_->victory_drop_down != nullptr) {
            this_->victory_drop_down->setCurrentLineNumber(0x11);
        }
        if (this_->victory_attribute_list != nullptr) {
            this_->victory_attribute_list->setCurrentLineId(attrib_type);
        }
        return;
    case 7:
        if (this_->victory_drop_down != nullptr) {
            this_->victory_drop_down->setCurrentLineNumber(0x12);
        }
        if (this_->victory_tech_list != nullptr) {
            this_->victory_tech_list->setCurrentLineId(attrib_type);
        }
        return;
    default:
        return;
    }

    if (this_->victory_drop_down != nullptr) {
        this_->victory_drop_down->setCurrentLineNumber(victory_line);
    }
}

// Offset: 0x004AE9D0
void load_multi_victory_cond_from_scenario(TRIBE_Screen_Sed* this_) {
    // Fully verified. Source of truth: scr_sed2.cpp.decomp @ 0x004AE9D0
    T_Scenario* scenario = get_scenario(this_);
    if (this_ == nullptr || scenario == nullptr) {
        return;
    }

    switch (scenario->GetMPVictory()) {
    case 0:
        this_->mp_victory_type = TRIBE_Screen_Sed::VictoryTypeStandard;
        break;
    case 1:
        this_->mp_victory_type = TRIBE_Screen_Sed::VictoryTypeConquest;
        break;
    case 2:
        this_->mp_victory_type = TRIBE_Screen_Sed::VictoryTypeScore;
        break;
    case 3:
        this_->mp_victory_type = TRIBE_Screen_Sed::VictoryTypeTime;
        break;
    default:
        this_->mp_victory_type = TRIBE_Screen_Sed::VictoryTypeCustom;
        break;
    }

    int score = scenario->GetVictoryScore();
    if (score == 0) {
        score = 900;
    }
    if (this_->victory_score != nullptr) {
        this_->victory_score->set_line(this_->victory_score->get_line(score));
    }

    int time = scenario->GetVictoryTime();
    if (time == 0) {
        time = 9000;
    }
    if (this_->victory_time != nullptr) {
        this_->victory_time->set_line(this_->victory_time->get_line(time));
    }

    if (this_->victory_and_or[0] != nullptr && this_->victory_and_or[1] != nullptr) {
        TButtonPanel* selected = (scenario->Get_victory_all_flag() == 0) ? this_->victory_and_or[0] : this_->victory_and_or[1];
        selected->set_radio_button();
    }

    if (this_->victory_cond_on[0] != nullptr) {
        this_->victory_cond_on[0]->set_state(static_cast<short>(scenario->Get_Multi_Conquest() != 0 ? 1 : 0));
    }

    char value_text[32]{};
    auto set_multi_value = [&](int value, TButtonPanel* toggle, TEditPanel* edit) {
        if (toggle != nullptr) {
            toggle->set_state(static_cast<short>(value != 0 ? 1 : 0));
        }
        if (edit != nullptr) {
            if (value == 0) {
                edit->set_text(const_cast<char*>("0"));
            } else {
                std::snprintf(value_text, sizeof(value_text), "%d", value);
                edit->set_text(value_text);
            }
        }
    };

    set_multi_value(scenario->Get_Multi_Exploration(), this_->victory_cond_on[1], this_->victory_condition_explore);
    set_multi_value(scenario->Get_Multi_Ruins(), this_->victory_cond_on[2], this_->victory_condition_ruins);
    set_multi_value(scenario->Get_Multi_Artifacts(), this_->victory_cond_on[3], this_->victory_condition_artifacts);
    set_multi_value(scenario->Get_Multi_Discoveries(), this_->victory_cond_on[4], this_->victory_condition_discoveries);
    set_multi_value(scenario->Get_Multi_Gold(), this_->victory_cond_on[5], this_->victory_condition_gold);

    scenario->Save_victory_conditions_into_players(1);
}

// Offset: 0x004AEC95
void FUN_004aec95() {
    // TODO: PARITY - Decomp includes a callable FUN_004aec95 body at this offset, but current transliteration keeps only an ASM thunk marker; confirm whether the decomp body is real logic or decode noise. [decomp: scr_sed2.cpp.decomp @ 0x004AEC95]
    // Fully verified. Source of truth: scr_sed2.cpp.asm @ 0x004AEC95 (switch-table data anchor thunk)
}


// Offset: 0x004AECB0
void save_diplomacy_in_scenario(TRIBE_Screen_Sed* this_, int param_2) {
    // Fully verified. Source of truth: scr_sed2.cpp.decomp @ 0x004AECB0
    const int param_1 = param_2;
    T_Scenario* scenario = get_scenario(this_);
    if (scenario == nullptr || param_1 < 0) {
        return;
    }

    for (int i = 0; i < 8; ++i) {
        int attitude = 3;
        if (this_->Diplomacy_friend_box[i][0] != nullptr && this_->Diplomacy_friend_box[i][0]->get_state() == 1) {
            attitude = 0;
        } else if (this_->Diplomacy_friend_box[i][1] != nullptr && this_->Diplomacy_friend_box[i][1]->get_state() == 1) {
            attitude = 1;
        } else if (this_->Diplomacy_friend_box[i][2] != nullptr && this_->Diplomacy_friend_box[i][2]->get_state() == 1) {
            attitude = 3;
        }
        scenario->Set_player_attitude(param_1, i, attitude);
    }

    const int allied_victory = (this_->Diplomacy_AlliedVictory[param_1] != nullptr)
        ? this_->Diplomacy_AlliedVictory[param_1]->get_state()
        : 0;
    scenario->SetPlayerAlliedVictory(param_1, allied_victory);
}

// Offset: 0x004AED50
void load_diplomacy_from_scenario(TRIBE_Screen_Sed* this_, int param_2) {
    // Fully verified. Source of truth: scr_sed2.cpp.decomp @ 0x004AED50
    const int param_1 = param_2;
    T_Scenario* scenario = get_scenario(this_);
    if (scenario == nullptr || param_1 < 0) {
        return;
    }

    for (int i = 0; i < 8; ++i) {
        const int attitude = scenario->Get_player_attitude(param_1, i);
        if (attitude == 0 && this_->Diplomacy_friend_box[i][0] != nullptr) {
            this_->Diplomacy_friend_box[i][0]->set_radio_button();
        }
        if (attitude == 1 && this_->Diplomacy_friend_box[i][1] != nullptr) {
            this_->Diplomacy_friend_box[i][1]->set_radio_button();
        }
        if (attitude == 3 && this_->Diplomacy_friend_box[i][2] != nullptr) {
            this_->Diplomacy_friend_box[i][2]->set_radio_button();
        }
    }

    if (this_->Diplomacy_AlliedVictory[param_1] != nullptr) {
        this_->Diplomacy_AlliedVictory[param_1]->set_state(static_cast<short>(scenario->GetPlayerAlliedVictory(param_1)));
    }
}

// Offset: 0x004AEE10
void activate_victory_proper_fields(TRIBE_Screen_Sed* this_, int param_2, int param_3) {
    // Fully verified. Source of truth: scr_sed2.cpp.decomp @ 0x004AEE10
    if (this_ == nullptr) {
        return;
    }

    this_->SelectRegionFlag = TRIBE_Screen_Sed::SELECT_OFF;
    if (param_3 == 0) {
        if (this_->victory_object_list) this_->victory_object_list->set_active(0);
        if (this_->victory_amount_text) this_->victory_amount_text->set_active(0);
        if (this_->victory_amount_input) this_->victory_amount_input->set_active(0);
        if (this_->victory_button_set_object) this_->victory_button_set_object->set_active(0);
        if (this_->victory_button_set_destination) this_->victory_button_set_destination->set_active(0);
        if (this_->victory_button_go_to_dest) this_->victory_button_go_to_dest->set_active(0);
        if (this_->victory_which_enemy_text) this_->victory_which_enemy_text->set_active(0);
        if (this_->victory_enemy_player_list) this_->victory_enemy_player_list->set_active(0);
        if (this_->victory_attribute_list) this_->victory_attribute_list->set_active(0);
        if (this_->victory_ages_list) this_->victory_ages_list->set_active(0);
        if (this_->victory_tech_list) this_->victory_tech_list->set_active(0);
        return;
    }

    if (this_->bottom_panel != nullptr) {
        this_->bottom_panel->set_curr_child(nullptr);
    }

    switch (param_2) {
    default:
        return;
    case 1:
        if (this_->victory_button_set_object) this_->victory_button_set_object->set_active(param_3);
        if (this_->victory_button_set_destination) this_->victory_button_set_destination->set_active(param_3);
        return;
    case 2:
        if (this_->victory_button_set_object) this_->victory_button_set_object->set_active(param_3);
        if (this_->victory_button_set_destination) this_->victory_button_set_destination->set_active(param_3);
        if (this_->victory_button_go_to_dest) this_->victory_button_go_to_dest->set_active(param_3);
        return;
    case 3:
        if (this_->victory_object_list) this_->victory_object_list->set_active(param_3);
        if (this_->victory_amount_text) this_->victory_amount_text->set_active(param_3);
        if (this_->victory_amount_input) {
            this_->victory_amount_input->set_active(param_3);
            reinterpret_cast<TPanel*>(this_->victory_amount_input)->set_help_info(0x7766, -1);
        }
        break;
    case 4:
        if (this_->victory_object_list) this_->victory_object_list->set_active(param_3);
        if (this_->victory_amount_text) this_->victory_amount_text->set_active(param_3);
        if (this_->victory_amount_input) {
            this_->victory_amount_input->set_active(param_3);
            reinterpret_cast<TPanel*>(this_->victory_amount_input)->set_help_info(0x7767, -1);
        }
        if (this_->bottom_panel != nullptr && this_->victory_amount_input != nullptr) {
            this_->bottom_panel->set_curr_child(reinterpret_cast<TPanel*>(this_->victory_amount_input));
        }
        if (this_->victory_button_set_destination) this_->victory_button_set_destination->set_active(param_3);
        if (this_->victory_button_go_to_dest) this_->victory_button_go_to_dest->set_active(param_3);
        return;
    case 5:
        if (this_->victory_object_list) this_->victory_object_list->set_active(param_3);
        if (this_->victory_amount_text) this_->victory_amount_text->set_active(param_3);
        if (this_->victory_amount_input) {
            this_->victory_amount_input->set_active(param_3);
            reinterpret_cast<TPanel*>(this_->victory_amount_input)->set_help_info(0x7768, -1);
        }
        if (this_->victory_which_enemy_text) this_->victory_which_enemy_text->set_active(param_3);
        if (this_->victory_enemy_player_list) this_->victory_enemy_player_list->set_active(param_3);
        if (this_->bottom_panel != nullptr && this_->victory_enemy_player_list != nullptr) {
            this_->bottom_panel->set_curr_child(reinterpret_cast<TPanel*>(this_->victory_enemy_player_list));
        }
        return;
    case 6:
    case 9:
        if (this_->victory_button_set_object) this_->victory_button_set_object->set_active(param_3);
        return;
    case 7:
        if (this_->victory_object_list) this_->victory_object_list->set_active(param_3);
        if (this_->victory_which_enemy_text) this_->victory_which_enemy_text->set_active(param_3);
        if (this_->victory_enemy_player_list) this_->victory_enemy_player_list->set_active(param_3);
        if (this_->bottom_panel != nullptr && this_->victory_enemy_player_list != nullptr) {
            this_->bottom_panel->set_curr_child(reinterpret_cast<TPanel*>(this_->victory_enemy_player_list));
        }
        return;
    case 8:
        if (this_->victory_which_enemy_text) this_->victory_which_enemy_text->set_active(param_3);
        if (this_->victory_enemy_player_list) this_->victory_enemy_player_list->set_active(param_3);
        if (this_->bottom_panel != nullptr && this_->victory_enemy_player_list != nullptr) {
            this_->bottom_panel->set_curr_child(reinterpret_cast<TPanel*>(this_->victory_enemy_player_list));
        }
        return;
    case 10:
        if (this_->victory_amount_input) {
            reinterpret_cast<TPanel*>(this_->victory_amount_input)->set_help_info(0x7769, -1);
        }
        if (this_->victory_amount_text) this_->victory_amount_text->set_active(param_3);
        if (this_->victory_amount_input) this_->victory_amount_input->set_active(param_3);
        break;
    case 0xb:
        if (this_->victory_amount_input) {
            reinterpret_cast<TPanel*>(this_->victory_amount_input)->set_help_info(0x776a, -1);
        }
        if (this_->victory_amount_text) this_->victory_amount_text->set_active(param_3);
        if (this_->victory_amount_input) this_->victory_amount_input->set_active(param_3);
        break;
    case 0xc:
        if (this_->victory_amount_input) {
            reinterpret_cast<TPanel*>(this_->victory_amount_input)->set_help_info(0x776b, -1);
        }
        if (this_->victory_amount_text) this_->victory_amount_text->set_active(param_3);
        if (this_->victory_amount_input) this_->victory_amount_input->set_active(param_3);
        break;
    case 0xd:
        if (this_->victory_amount_input) {
            reinterpret_cast<TPanel*>(this_->victory_amount_input)->set_help_info(0x776c, -1);
        }
        if (this_->victory_amount_text) this_->victory_amount_text->set_active(param_3);
        if (this_->victory_amount_input) this_->victory_amount_input->set_active(param_3);
        break;
    case 0xe:
        if (this_->victory_amount_input) {
            reinterpret_cast<TPanel*>(this_->victory_amount_input)->set_help_info(0x776d, -1);
        }
        if (this_->victory_amount_text) this_->victory_amount_text->set_active(param_3);
        if (this_->victory_amount_input) this_->victory_amount_input->set_active(param_3);
        break;
    case 0xf:
        if (this_->victory_ages_list) this_->victory_ages_list->set_active(param_3);
        return;
    case 0x10:
        if (this_->victory_amount_input) {
            reinterpret_cast<TPanel*>(this_->victory_amount_input)->set_help_info(0x776e, -1);
        }
        if (this_->victory_amount_text) this_->victory_amount_text->set_active(param_3);
        if (this_->victory_amount_input) this_->victory_amount_input->set_active(param_3);
        break;
    case 0x11:
        if (this_->victory_amount_text) this_->victory_amount_text->set_active(param_3);
        if (this_->victory_amount_input) {
            this_->victory_amount_input->set_active(param_3);
            reinterpret_cast<TPanel*>(this_->victory_amount_input)->set_help_info(0x776f, -1);
        }
        if (this_->bottom_panel != nullptr && this_->victory_amount_input != nullptr) {
            this_->bottom_panel->set_curr_child(reinterpret_cast<TPanel*>(this_->victory_amount_input));
        }
        if (this_->victory_attribute_list) this_->victory_attribute_list->set_active(param_3);
        return;
    case 0x12:
        if (this_->victory_tech_list) this_->victory_tech_list->set_active(param_3);
        return;
    }

    if (this_->bottom_panel != nullptr && this_->victory_amount_input != nullptr) {
        this_->bottom_panel->set_curr_child(reinterpret_cast<TPanel*>(this_->victory_amount_input));
    }
}

// Offset: 0x004AF2D2
void FUN_004af2d2() {
    // Fully verified. Source of truth: scr_sed2.cpp.decomp @ 0x004AF2D2
    return;
}


// Offset: 0x004AF320
static void init_module_variables(TRIBE_Screen_Sed* this_) {
    // Fully verified. Source of truth: scr_sed2.cpp.decomp @ 0x004AF320
    if (this_ == nullptr) {
        return;
    }

    this_->background_pic = nullptr;
    this_->main_view = nullptr;
    this_->map_view = nullptr;
    this_->message_panel = nullptr;
    this_->bottom_panel = nullptr;
    this_->set_player_first_flag = 0;

    std::memset(this_->scenario_mode_button, 0, sizeof(this_->scenario_mode_button));
    this_->menu_button = nullptr;
    this_->help_button = nullptr;

    std::memset(this_->map_type_button, 0, sizeof(this_->map_type_button));
    std::memset(this_->map_type_text, 0, sizeof(this_->map_type_text));
    this_->map_type_label = nullptr;
    this_->default_terrain_drop = nullptr;
    this_->default_terrain_label = nullptr;
    this_->map_size_drop = nullptr;
    this_->map_size_label = nullptr;
    this_->map_style_drop = nullptr;
    this_->map_style_label = nullptr;
    this_->map_generating_text = nullptr;
    this_->random_seed_label = nullptr;
    this_->random_seed_input = nullptr;
    this_->random_seed_used_label = nullptr;
    this_->random_seed_used_text = nullptr;
    this_->generate_map_button = nullptr;
    this_->brush_size_label = nullptr;
    this_->paint_type_label = nullptr;
    this_->paint_terrain_label = nullptr;

    std::memset(this_->brush_size_button, 0, sizeof(this_->brush_size_button));
    std::memset(this_->brush_size_button_label, 0, sizeof(this_->brush_size_button_label));
    std::memset(this_->paint_type_button, 0, sizeof(this_->paint_type_button));
    std::memset(this_->paint_type_button_label, 0, sizeof(this_->paint_type_button_label));

    this_->paint_terrain_list = nullptr;
    this_->paint_terrain_scrollbar = nullptr;
    this_->paint_elevation_list = nullptr;
    this_->paint_elevation_scrollbar = nullptr;
    this_->player_advance_civilization_drop = nullptr;
    this_->player_label = nullptr;
    this_->player_starting_age_label = nullptr;
    this_->player_build_text = nullptr;
    this_->player_city_text = nullptr;
    this_->AiRules_text = nullptr;
    this_->player_list = nullptr;
    this_->player_number_list = nullptr;

    std::memset(this_->player_inven_label, 0, sizeof(this_->player_inven_label));
    std::memset(this_->player_inven_input, 0, sizeof(this_->player_inven_input));
    std::memset(this_->player_setting_label, 0, sizeof(this_->player_setting_label));
    std::memset(this_->player_setting_drop, 0, sizeof(this_->player_setting_drop));

    this_->BuildList = nullptr;
    this_->CityLayout = nullptr;
    this_->AiRules = nullptr;
    this_->unit_player_list = nullptr;
    std::memset(this_->unit_mode_select, 0, sizeof(this_->unit_mode_select));
    std::memset(this_->unit_mode_select_label, 0, sizeof(this_->unit_mode_select_label));
    this_->unit_list = nullptr;
    this_->unit_scrollbar = nullptr;
    this_->unit_list_info = nullptr;
    this_->button_unit_pics = nullptr;
    std::memset(this_->button_bldg_pics, 0, sizeof(this_->button_bldg_pics));
    this_->object_panel = nullptr;
    this_->unit_list_size = 0;

    std::memset(this_->victory_cond_on, 0, sizeof(this_->victory_cond_on));
    std::memset(this_->victory_and_or, 0, sizeof(this_->victory_and_or));
    this_->victory_condition_label = nullptr;
    this_->victory_amount_label = nullptr;
    this_->victory_long_label = nullptr;
    std::memset(this_->victory_text_and_or, 0, sizeof(this_->victory_text_and_or));
    this_->victory_label_conquest = nullptr;
    this_->victory_label_explore = nullptr;
    this_->victory_label_explore_percent = nullptr;
    this_->victory_label_ruins = nullptr;
    this_->victory_label_artifacts = nullptr;
    this_->victory_label_discoveries = nullptr;
    this_->victory_label_gold = nullptr;
    this_->victory_condition_explore = nullptr;
    this_->victory_condition_ruins = nullptr;
    this_->victory_condition_artifacts = nullptr;
    this_->victory_condition_discoveries = nullptr;
    this_->victory_condition_gold = nullptr;
    std::memset(this_->victory_cond_type_label, 0, sizeof(this_->victory_cond_type_label));
    std::memset(this_->victory_cond_type, 0, sizeof(this_->victory_cond_type));
    this_->victory_score_label = nullptr;
    this_->victory_score = nullptr;
    this_->victory_time_label = nullptr;
    this_->victory_time = nullptr;
    std::memset(this_->victory_button, 0, sizeof(this_->victory_button));
    this_->victory_drop_down = nullptr;
    this_->victory_object_list = nullptr;
    this_->victory_player_list = nullptr;
    this_->victory_enemy_player_list = nullptr;
    this_->victory_attribute_list = nullptr;
    this_->victory_ages_list = nullptr;
    this_->victory_tech_list = nullptr;
    this_->victory_button_set_object = nullptr;
    this_->victory_button_set_destination = nullptr;
    this_->victory_button_go_to_dest = nullptr;
    this_->victory_condition_text = nullptr;
    this_->victory_condition_type = nullptr;
    this_->victory_amount_text = nullptr;
    this_->victory_which_enemy_text = nullptr;
    this_->victory_amount_input = nullptr;
    this_->victory_object_scrollbar = nullptr;

    this_->message_input = nullptr;
    std::memset(this_->message_button, 0, sizeof(this_->message_button));
    std::memset(this_->message_button_label, 0, sizeof(this_->message_button_label));
    this_->current_message = 0;

    std::memset(this_->cinematic_label, 0, sizeof(this_->cinematic_label));
    std::memset(this_->cinematic_input, 0, sizeof(this_->cinematic_input));

    std::memset(this_->options_label, 0, sizeof(this_->options_label));
    std::memset(this_->options_button, 0, sizeof(this_->options_button));
    this_->options_player_list = nullptr;
    this_->options_disable_tech_text = nullptr;
    std::memset(this_->options_disable_button, 0, sizeof(this_->options_disable_button));
    std::memset(this_->options_disable_text, 0, sizeof(this_->options_disable_text));

    std::memset(this_->Diplomacy_opponent_label, 0, sizeof(this_->Diplomacy_opponent_label));
    std::memset(this_->Diplomacy_player_text, 0, sizeof(this_->Diplomacy_player_text));
    this_->Diplomacy_player_list = nullptr;
    std::memset(this_->Diplomacy_status_label, 0, sizeof(this_->Diplomacy_status_label));
    std::memset(this_->Diplomacy_friend_box, 0, sizeof(this_->Diplomacy_friend_box));
    std::memset(this_->Diplomacy_AlliedVictory, 0, sizeof(this_->Diplomacy_AlliedVictory));

    this_->world = nullptr;
}

// Offset: 0x004AF6C0
static void create_all_buttons_etc(TRIBE_Screen_Sed* this_) {
    // Fully verified. Source of truth: scr_sed2.cpp.decomp @ 0x004AF6C0
    if (this_ == nullptr) {
        return;
    }

    const long mode_ids[10] = {0x271a, 0x271b, 0x271c, 0x271d, 0x2722, 0x271e, 0x2723, 0x2721, 0x271f, 0x2720};
    for (int i = 0; i < 10; ++i) {
        (void)this_->create_button(reinterpret_cast<TPanel*>(this_), &this_->scenario_mode_button[i], mode_ids[i],
                                   0, 0, 0, 0, 0, 10, 1, 0);
        if (this_->scenario_mode_button[i] != nullptr) {
            this_->scenario_mode_button[i]->set_active(1);
        }
    }

    (void)this_->create_button(reinterpret_cast<TPanel*>(this_), &this_->menu_button, 0x2724,
                               0, 0, 0, 0, 0, 10, 1, 0);
    (void)this_->create_button(reinterpret_cast<TPanel*>(this_), &this_->help_button, 0x0fa9,
                               0, 0, 0, 0, 0, 10, 1, 0);
}

// Offset: 0x004B1A50
static void position_panels(TRIBE_Screen_Sed* this_) {
    // Fully verified. Source of truth: scr_sed2.cpp.decomp @ 0x004B1A50
    if (this_ == nullptr || this_->main_view == nullptr) {
        return;
    }

    const long width = this_->width();
    const long height = this_->height();
    const long bottom_height = 0x89;

    if (this_->bottom_panel != nullptr) {
        this_->bottom_panel->set_rect(0, height - bottom_height, width, bottom_height);
    }
    if (this_->main_view != nullptr) {
        reinterpret_cast<TPanel*>(this_->main_view)->set_rect(0, 0, width, height - bottom_height);
    }
    if (this_->map_view != nullptr) {
        reinterpret_cast<TPanel*>(this_->map_view)->set_rect(width - 0x87, 0, 0x87, 0x87);
    }
    if (this_->message_panel != nullptr) {
        reinterpret_cast<TPanel*>(this_->message_panel)->set_rect(0, 0, width - 0x87, 0x18);
    }
}

// Offset: 0x004B29E0
void activate_victory_panel(TRIBE_Screen_Sed* this_, int param_2) {
    // Fully verified. Source of truth: scr_sed2.cpp.decomp @ 0x004B29E0
    if (this_ == nullptr || this_->world == nullptr || this_->world->scenario == nullptr) {
        return;
    }

    T_Scenario* scenario = static_cast<T_Scenario*>(this_->world->scenario);
    for (int i = 0; i < 12; ++i) {
        TButtonPanel* button = this_->victory_button[i];
        if (button == nullptr) {
            continue;
        }

        button->set_active(param_2);
        if (param_2 != 0) {
            const int victory_type = scenario->GetSPVictoryType(i);
            const int state = ((victory_type != 0) ? 2 : 0) + ((this_->CurrentVictory == i) ? 1 : 0);
            button->set_state((short)state);
        }
    }

    if (this_->victory_drop_down != nullptr) this_->victory_drop_down->set_active(param_2);
    if (this_->victory_condition_text != nullptr) this_->victory_condition_text->set_active(param_2);
    if (this_->victory_player_list != nullptr) this_->victory_player_list->set_active(param_2);

    if (this_->victory_player_list == nullptr) {
        return;
    }

    if (param_2 != 0) {
        this_->victory_player_list->set_line(this_->player_num - 1);
    } else {
        const long selected = this_->victory_player_list->get_line();
        this_->player_num = (short)selected + 1;
    }
}

// Offset: 0x004B2AA0
int MakeFileList(TRIBE_Screen_Sed* this_, TDropDownPanel* param_2, char* param_3, char* param_4, uchar param_5, uchar param_6) {
    // Fully verified. Source of truth: scr_sed2.cpp.decomp @ 0x004B2AA0
    (void)this_;

    int extension_strlen = 0;
    param_2->empty_list();

    if (param_5 != 0) {
        param_2->append_line(0x2775, 0);
    }
    if (param_6 != 0) {
        param_2->append_line(0x277b, 0);
    }

    _finddata_t file_info{};
    char file_name[260]{};
    char path[260]{};
    std::sprintf(path, "%s\\%s", param_3, param_4);

    const intptr_t find_handle = _findfirst(path, &file_info);
    const int extension_len = static_cast<int>(std::strlen(param_4));
    if (find_handle == -1) {
        return extension_strlen;
    }

    int find_result = 0;
    do {
        ++extension_strlen;
        const size_t name_len = std::strlen(file_info.name);
        const int copy_len = static_cast<int>(name_len) - extension_len;
        if (copy_len > 0) {
            std::strncpy(file_name, file_info.name, static_cast<size_t>(copy_len));
            file_name[copy_len] = '\0';
            param_2->append_line(file_name, 0);
        }

        find_result = _findnext(find_handle, &file_info);
    } while (find_result != -1);

    _findclose(find_handle);
    return extension_strlen;
}


// Offset: 0x004B2BC0
int Set_player_advance_civilization_text(TRIBE_Screen_Sed* this_, int param_2) {
    // Fully verified. Source of truth: scr_sed2.cpp.decomp @ 0x004B2BC0
    (void)param_2;

    this_->player_advance_civilization_drop->empty_list();
    this_->player_advance_civilization_drop->append_line(0x1069, 0);
    this_->player_advance_civilization_drop->append_line(0x106a, 1);
    this_->player_advance_civilization_drop->append_line(0x106b, 2);
    this_->player_advance_civilization_drop->append_line(0x106c, 3);
    this_->player_advance_civilization_drop->append_line(0x106d, 4);
    this_->player_advance_civilization_drop->setCurrentLineNumber(0);
    this_->player_advance_civilization_drop->set_active(0);
    return 1;
}


// Offset: 0x004B2C50
void SavePlayerActiveStatus(TRIBE_Screen_Sed* this_) {
    // Fully verified. Source of truth: scr_sed2.cpp.decomp @ 0x004B2C50
    T_Scenario* scenario = get_scenario(this_);
    if (scenario == nullptr || this_->player_number_list == nullptr) {
        return;
    }

    const int active_players = (int)this_->player_number_list->get_line() + 1;
    const int scenario_players = (int)this_->world->player_num - 1;
    if (scenario_players > 0) {
        for (int i = 0; i < scenario_players; ++i) {
            scenario->Set_player_Active(i, (i < active_players) ? 1 : 0);
        }
    }

    if (this_->victory_player_list) this_->victory_player_list->empty_list();
    if (this_->victory_enemy_player_list) this_->victory_enemy_player_list->empty_list();
    if (this_->options_player_list) this_->options_player_list->empty_list();
    if (this_->Diplomacy_player_list) this_->Diplomacy_player_list->empty_list();
    if (this_->player_list) this_->player_list->empty_list();
    if (this_->unit_player_list) {
        this_->unit_player_list->empty_list();
        this_->unit_player_list->append_line(0x2776, 0);
    }

    for (int i = 0; i < active_players; ++i) {
        const long str_id = 0x2865 + i;
        if (this_->unit_player_list) this_->unit_player_list->append_line(str_id, 0);
        if (this_->victory_player_list) this_->victory_player_list->append_line(str_id, 0);
        if (this_->victory_enemy_player_list) this_->victory_enemy_player_list->append_line(str_id, 0);
        if (this_->options_player_list) this_->options_player_list->append_line(str_id, 0);
        if (this_->Diplomacy_player_list) this_->Diplomacy_player_list->append_line(str_id, 0);
        if (this_->player_list) this_->player_list->append_line(str_id, 0);
    }

    if (active_players <= this_->player_num) {
        this_->player_num = static_cast<short>(active_players);
    }

    if (this_->victory_player_list) this_->victory_player_list->set_line(this_->player_num - 1);
    if (this_->options_player_list) this_->options_player_list->set_line(this_->player_num - 1);
    if (this_->Diplomacy_player_list) this_->Diplomacy_player_list->set_line(this_->player_num - 1);
    if (this_->player_list) this_->player_list->set_line(this_->player_num - 1);
    if (this_->unit_player_list) this_->unit_player_list->set_line(this_->player_num);
}


// Offset: 0x004B2DD0
int create_check_box(TRIBE_Screen_Sed* this_, TPanel* param_2, TButtonPanel** param_3) {
    // Fully verified. Source of truth: scr_sed2.cpp.decomp @ 0x004B2DD0
    const int created = this_->TEasy_Panel::create_check_box(param_2, param_3, 0, 0, 0, 0, 1, 0);
    if (created == 0) {
        return 0;
    }

    (*param_3)->set_z_order('\x01', 0);
    (*param_3)->set_active(0);
    if (this_->use_bevels != 0) {
        (*param_3)->set_bevel_info(3, this_->bevel_color1, this_->bevel_color2, this_->bevel_color3,
            this_->bevel_color4, this_->bevel_color1, this_->bevel_color2);
    }
    return 1;
}


// Offset: 0x004B2E60
int create_radio_button(TRIBE_Screen_Sed* this_, TPanel* param_2, TButtonPanel** param_3) {
    // Fully verified. Source of truth: scr_sed2.cpp.decomp @ 0x004B2E60
    const int created = this_->TEasy_Panel::create_radio_button(param_2, param_3, 0, 0, 0, 0, 1, 0);
    if (created == 0) {
        return 0;
    }

    (*param_3)->set_z_order('\x01', 0);
    (*param_3)->set_active(0);
    if (this_->use_bevels != 0) {
        (*param_3)->set_bevel_info(3, this_->bevel_color1, this_->bevel_color2, this_->bevel_color3,
            this_->bevel_color4, this_->bevel_color1, this_->bevel_color2);
    }
    return 1;
}
