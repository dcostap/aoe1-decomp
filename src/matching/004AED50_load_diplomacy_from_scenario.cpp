// TRIBE_Screen_Sed::load_diplomacy_from_scenario
// VA: 004AED50
// MATCHED 2026-05-21: real member declarations for T_Scenario and TButtonPanel,
// plus a vtable-padded TButtonPanel surface placing set_value at slot +0xE0,
// recover direct thiscall and virtual call shapes. Raw offsets for overlapping UI
// button arrays avoid forcing an impossible struct layout.

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
    virtual void set_value(int value);
    void set_radio_button();
};

class T_Scenario {
public:
    int Get_player_attitude(int p1, int p2);
    int GetPlayerAlliedVictory(int p1);
};

class WorldWrap { public: char gap00[0x5C]; T_Scenario* scenario; };

class TRIBE_Screen_Sed {
public:
    char gap000[0x928];
    WorldWrap* world; // +928

    void load_diplomacy_from_scenario(int player);
};

void TRIBE_Screen_Sed::load_diplomacy_from_scenario(int player)
{
    if (player >= 0) {
        int i = 0;
        TButtonPanel** allied = (TButtonPanel**)((char*)this + 0x908);
        TButtonPanel** boxes = (TButtonPanel**)((char*)this + 0x8AC);
        do {
            int att = this->world->scenario->Get_player_attitude(player, i);
            if (att == 0)
                boxes[-1]->set_radio_button();
            if (att == 1)
                boxes[0]->set_radio_button();
            if (att == 3)
                boxes[1]->set_radio_button();
            (*allied)->set_value(0);
            i++;
            allied++;
            boxes += 3;
        } while (i < 8);
        (*(TButtonPanel**)((char*)this + 0x908 + player * 4))->set_value(this->world->scenario->GetPlayerAlliedVictory(player));
    }
}
