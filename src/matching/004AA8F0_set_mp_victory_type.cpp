// VA: 004AA8F0 TRIBE_Screen_Sed::set_mp_victory_type | scr_sed.cpp:1640-1719
// First natural pass from Ghidra/asm.

#ifndef SCR_SED_TU_CONTEXT
struct TPanel {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void set_active(int active);
    virtual void v18();
    virtual void v1C();
    virtual void redraw(int flags);
    void set_curr_child(TPanel* child);
};
struct TButtonPanel : public TPanel { void set_radio_button(); };
struct TTextPanel : public TPanel {};
struct TEditPanel : public TTextPanel {};
struct TDropDownPanel : public TTextPanel {};

struct TRIBE_Screen_Sed {
    enum VictoryType {
        VictoryTypeNone = 0,
        VictoryTypeStandardValue = 1,
        VictoryTypeConquestValue = 2,
        VictoryTypeScoreValue = 3,
        VictoryTypeTimeValue = 4,
        VictoryTypeCustomValue = 5
    };
    char gap_00[0x4AC];
    int mp_victory_type;
    char gap_4B0[0x4D4 - 0x4B0];
    TPanel* bottom_panel;
    char gap_4D8[0x668 - 0x4D8];
    TButtonPanel* victory_cond_on[6];
    TButtonPanel* victory_and_or[2];
    TTextPanel* victory_condition_label;
    TTextPanel* victory_amount_label;
    TTextPanel* victory_long_label;
    TTextPanel* victory_text_and_or[2];
    TTextPanel* victory_label_conquest;
    TTextPanel* victory_label_explore;
    TTextPanel* victory_label_explore_percent;
    TTextPanel* victory_label_ruins;
    TTextPanel* victory_label_artifacts;
    TTextPanel* victory_label_discoveries;
    TTextPanel* victory_label_gold;
    TEditPanel* victory_condition_explore;
    TEditPanel* victory_condition_ruins;
    TEditPanel* victory_condition_artifacts;
    TEditPanel* victory_condition_discoveries;
    TEditPanel* victory_condition_gold;
    TTextPanel* victory_cond_type_label[5];
    TButtonPanel* victory_cond_type[5];
    TTextPanel* victory_score_label;
    TDropDownPanel* victory_score;
    TTextPanel* victory_time_label;
    TDropDownPanel* victory_time;

protected:
    void set_mp_victory_type(VictoryType type, int redraw);
};
#endif

void TRIBE_Screen_Sed::set_mp_victory_type(VictoryType type, int redraw)
{
    int pass;
    int active;
    int mode;
    int count;
    TButtonPanel** ppButton;
    TTextPanel** ppText;

    pass = 0;
    do {
        if (pass == 0) {
            active = 0;
            mode = this->mp_victory_type;
        } else {
            if (type == 0) {
                return;
            }
            if (redraw == 0) {
                break;
            }
            active = 1;
            mode = type;
        }

        switch (mode) {
        case 1:
        case 2:
            break;
        case 3:
            this->victory_score_label->set_active(active);
            this->victory_score->set_active(active);
            break;
        case 4:
            this->victory_time_label->set_active(active);
            this->victory_time->set_active(active);
            break;
        case 5:
            ppButton = this->victory_cond_on;
            count = 5;
            do {
                (*ppButton)->set_active(active);
                ppButton++;
                count--;
            } while (count != 0);

            ppText = this->victory_text_and_or;
            count = 2;
            do {
                ((TButtonPanel*)ppText[-5])->set_active(active);
                (*ppText)->set_active(active);
                ppText++;
                count--;
            } while (count != 0);

            this->victory_amount_label->set_active(active);
            this->victory_label_conquest->set_active(active);
            this->victory_label_explore->set_active(active);
            this->victory_label_ruins->set_active(active);
            this->victory_label_artifacts->set_active(active);
            this->victory_label_discoveries->set_active(active);
            this->victory_condition_explore->set_active(active);
            this->victory_condition_ruins->set_active(active);
            this->victory_condition_artifacts->set_active(active);
            this->victory_condition_discoveries->set_active(active);
            if (active == 1) {
                this->bottom_panel->set_curr_child(this->victory_condition_explore);
            }
            break;
        }
        pass++;
    } while (pass < 2);

    this->mp_victory_type = type;
    this->victory_cond_type[type - 1]->set_radio_button();
    this->bottom_panel->redraw(1);
}
