// VA: 004AE9D0 TRIBE_Screen_Sed::load_multi_victory_cond_from_scenario (709 B)
// Attempt log:
// - Replaced the placeholder with a typed scr_sed2.cpp reconstruction.  The
//   fields are the ground-truth screen ownership; scenario getters and panel
//   methods use their period member/virtual surfaces.
// - Duplicating the score/time get_line arms, with the nonzero arm first,
//   recovered VC5's `je` to the late default push and shared call tail.
// - Exact under the default /O2 /Oy VC5 response file.

extern "C" char* __cdecl itoa(int, char*, int);

class TButtonPanel {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void set_state(short value); // vtable slot +0xE0

    void set_radio_button();
};

class TDropDownPanel {
public:
    long get_line(long value);
    void set_line(long value);
};

class TEditPanel {
public:
    void set_text(char* text);
};

class T_Scenario {
public:
    virtual ~T_Scenario();

    int GetMPVictory();
    int GetVictoryScore();
    int GetVictoryTime();
    int Get_victory_all_flag();
    int Get_Multi_Conquest();
    int Get_Multi_Exploration();
    int Get_Multi_Ruins();
    int Get_Multi_Artifacts();
    int Get_Multi_Discoveries();
    int Get_Multi_Gold();
    void Save_victory_conditions_into_players(int save_attrs);
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x58];
    T_Scenario* scenario;
};

class TRIBE_World : public RGE_Game_World {
};

class TPanel {
public:
    virtual ~TPanel();
    char gap_04[0xF0];
};

class TScreenPanel : public TPanel {
public:
    char gap_F4[0x384];
};

class TRIBE_Screen_Sed : public TScreenPanel {
public:
    char gap_478[0x34];
    int mp_victory_type; // +0x4AC
    char gap_4B0[0x1B8];
    TButtonPanel* victory_cond_on[6]; // +0x668
    TButtonPanel* victory_and_or[2]; // +0x680
    char gap_688[0x30];
    TEditPanel* victory_condition_explore; // +0x6B8
    TEditPanel* victory_condition_ruins; // +0x6BC
    TEditPanel* victory_condition_artifacts; // +0x6C0
    TEditPanel* victory_condition_discoveries; // +0x6C4
    TEditPanel* victory_condition_gold; // +0x6C8
    char gap_6CC[0x2C];
    TDropDownPanel* victory_score; // +0x6F8
    char gap_6FC[4];
    TDropDownPanel* victory_time; // +0x700
    char gap_704[0x224];
    TRIBE_World* world; // +0x928

    void load_multi_victory_cond_from_scenario();
};

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
