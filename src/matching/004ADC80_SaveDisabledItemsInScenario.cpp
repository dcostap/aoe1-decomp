// VA: 004ADC80 TRIBE_Screen_Sed::SaveDisabledItemsInScenario()
// PDB source: scr_sed2.cpp lines 343-352
// Default flags
//
// __thiscall: this in ecx, no stack params. void return.

#include <stdlib.h>

class TButtonPanel {
public:
    virtual ~TButtonPanel() {}
    int get_state();
};

class TDropDownPanel {
public:
    long get_line();
};

class T_Scenario {
public:
    void SetDisabledTechnology(int player_num_minus_1, int tech_idx, int flag);
};

class TRIBE_Screen_Sed {
public:
    virtual ~TRIBE_Screen_Sed() {}
    char pad_04[0x4B4];
    short player_num;                           // +0x4B8
    char pad_4BA[0x7CC - 0x4BA];
    TDropDownPanel* options_player_list;        // +0x7CC
    char pad_7D0[4];
    TButtonPanel* options_disable_button[16];   // +0x7D4
    char pad_814[0x928 - 0x814];
    void* world;                                // +0x928

    void SaveDisabledItemsInScenario();
};

void TRIBE_Screen_Sed::SaveDisabledItemsInScenario() {
    // Load this into local pointer to influence register choice
    TRIBE_Screen_Sed* th = this;
    short pn0 = th->player_num;
    if (pn0 == 0) {
        th->player_num = 1;
    }

    for (int i = 0; i < 16; i++) {
        int state = th->options_disable_button[i]->get_state();
        if (state != 0) {
            int player_idx = (int)(short)th->player_num - 1;
            void* scenario = *(void**)((int)th->world + 0x5C);
            ((T_Scenario*)scenario)->SetDisabledTechnology(player_idx, i, 0);
        } else {
            int player_idx = (int)(short)th->player_num - 1;
            void* scenario = *(void**)((int)th->world + 0x5C);
            ((T_Scenario*)scenario)->SetDisabledTechnology(player_idx, i, 1);
        }
    }

    long line = th->options_player_list->get_line();
    th->player_num = (short)(line + 1);
}
