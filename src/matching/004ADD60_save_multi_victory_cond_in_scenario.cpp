// 004ADD60 TRIBE_Screen_Sed::save_multi_victory_cond_in_scenario
// Attempt log:
// 1: direct natural reconstruction from asm/PDB lines with local UI/scenario surfaces.

extern "C" int __cdecl atoi(const char*);

class TButtonPanel { public: int get_state(); };
class TDropDownPanel { public: long get_id(); };
class TEditPanel { public: char* get_string(); };
class T_Scenario {
public:
    char pad[0x5c];
    void* info;
};
class TRIBE_Scenario_Info {
public:
    void SetMPVictory(int);
    void SetVictoryScore(int);
    void SetVictoryTime(int);
    void Set_victory_all_flag(int);
    void Set_victory_capture_flag(int);
    void Set_victory_ruins(int);
    void Set_victory_artifacts(int);
    void Set_victory_exploration(int);
    void Set_victory_conquest_flag(int);
    void Set_victory_unused(int);
};

class TRIBE_Screen_Sed {
public:
    char pad0[0x4ac];
    int mp_victory_type;
    char pad4b0[0x668-0x4b0];
    TButtonPanel* capture_check;
    TButtonPanel* ruins_check;
    TButtonPanel* artifacts_check;
    TButtonPanel* exploration_check;
    TButtonPanel* conquest_check;
    TButtonPanel* unused_check;
    char pad680[0x684-0x680];
    TButtonPanel* all_victory_checkbox;
    char pad688[0x6b8-0x688];
    TEditPanel* ruins_edit;
    TEditPanel* artifacts_edit;
    TEditPanel* exploration_edit;
    TEditPanel* conquest_edit;
    TEditPanel* unused_edit;
    char pad6cc[0x6e0-0x6cc];
    TButtonPanel* standard_victory;
    TButtonPanel* score_victory;
    TButtonPanel* time_victory;
    TButtonPanel* conquest_victory;
    TButtonPanel* none_victory;
    char pad6f4[4];
    TDropDownPanel* score_dropdown;
    char pad6fc[4];
    TDropDownPanel* time_dropdown;
    char pad704[0x928-0x704];
    T_Scenario* scenario;
    void save_multi_victory_cond_in_scenario();
};

#define INFO ((TRIBE_Scenario_Info*)this->scenario->info)

void TRIBE_Screen_Sed::save_multi_victory_cond_in_scenario()
{
    switch (this->mp_victory_type) {
    case 1:
        INFO->SetMPVictory(0);
        break;
    case 2:
        INFO->SetMPVictory(1);
        break;
    case 3:
        INFO->SetMPVictory(2);
        break;
    case 4:
        INFO->SetMPVictory(3);
        break;
    default:
        INFO->SetMPVictory(4);
        break;
    }

    INFO->SetVictoryScore(this->score_dropdown->get_id());
    INFO->SetVictoryTime(this->time_dropdown->get_id());

    if (this->standard_victory->get_state()) {
        INFO->SetMPVictory(0);
    } else if (this->score_victory->get_state()) {
        INFO->SetMPVictory(1);
    } else if (this->time_victory->get_state()) {
        INFO->SetMPVictory(2);
    } else if (this->conquest_victory->get_state()) {
        INFO->SetMPVictory(3);
    } else {
        INFO->SetMPVictory(4);
    }

    INFO->SetVictoryScore(this->score_dropdown->get_id());
    INFO->SetVictoryTime(this->time_dropdown->get_id());

    if (this->all_victory_checkbox->get_state()) {
        INFO->Set_victory_all_flag(1);
    } else {
        INFO->Set_victory_all_flag(0);
    }

    if (!this->capture_check->get_state() && this->none_victory->get_state()) {
        INFO->Set_victory_capture_flag(0);
    } else {
        INFO->Set_victory_capture_flag(1);
    }

    int value = atoi(this->ruins_edit->get_string());
    if (this->ruins_check->get_state()) {
        if (value < 1) value = 1;
        if (value > 100) value = 100;
        INFO->Set_victory_ruins(value);
    } else {
        INFO->Set_victory_ruins(0);
    }

    value = atoi(this->artifacts_edit->get_string());
    if (this->artifacts_check->get_state()) {
        INFO->Set_victory_artifacts(value);
    } else {
        INFO->Set_victory_artifacts(0);
    }

    value = atoi(this->exploration_edit->get_string());
    if (this->exploration_check->get_state()) {
        INFO->Set_victory_exploration(value);
    } else {
        INFO->Set_victory_exploration(0);
    }

    value = atoi(this->conquest_edit->get_string());
    if (this->conquest_check->get_state()) {
        INFO->Set_victory_conquest_flag(value);
    } else {
        INFO->Set_victory_conquest_flag(0);
    }

    value = atoi(this->unused_edit->get_string());
    if (this->unused_check->get_state()) {
        INFO->Set_victory_unused(value);
    } else {
        INFO->Set_victory_unused(0);
    }
}
