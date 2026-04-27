// attempt 1: natural panel text fetch + inline strcmp-like compare + vtable notify call
// attempt 2: tightened the compare to the decompiler-style byte-pair loop; mismatch moved to the prolog/register basin
// attempt 3: kept the direct virtual notify call; remaining gap is still the early register layout around `this`/panel load

class TTextPanel;

struct TTextPanelVtable {
    char pad_0[0xE8];
    void (*show_timings)(TTextPanel* this_, char* text);
};

class TTextPanel {
public:
    TTextPanelVtable* vtable;
    char pad_4[0xF4 - 0x4];
    char* get_text();
};

class TRIBE_Screen_Game {
public:
    char pad_0[0x588];
    TTextPanel* fps_panel;

    void show_timings(char* param_1, char* param_2);
};

void TRIBE_Screen_Game::show_timings(char* param_1, char* param_2) {
    unsigned char* pbVar2 = (unsigned char*)this->fps_panel->get_text();
    unsigned char* pbVar4 = (unsigned char*)param_2;
    int iVar3;
    unsigned char bVar1;
    bool bVar5;

    if (pbVar2 != 0) {
        do {
            bVar1 = *pbVar2;
            bVar5 = bVar1 < *pbVar4;
            if (bVar1 != *pbVar4) {
                iVar3 = (1 - (unsigned int)bVar5) - (unsigned int)(bVar5 != 0);
                goto LAB_004994F8;
            }
            if (bVar1 == 0) {
                iVar3 = 0;
                goto LAB_004994F8;
            }
            bVar1 = pbVar2[1];
            bVar5 = bVar1 < pbVar4[1];
            if (bVar1 != pbVar4[1]) {
                iVar3 = (1 - (unsigned int)bVar5) - (unsigned int)(bVar5 != 0);
                goto LAB_004994F8;
            }
            pbVar2 = pbVar2 + 2;
            pbVar4 = pbVar4 + 2;
        } while (bVar1 != 0);
        iVar3 = 0;
LAB_004994F8:
        if (iVar3 == 0) {
            return;
        }
    }

    (*(TTextPanelVtable**)this->fps_panel)->show_timings(this->fps_panel, param_2);
}
