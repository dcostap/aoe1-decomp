// VA: 0043E5C0 TribeDiplomacyDialog::check_wood
// PDB: dlg_dip.cpp lines 777-805 (136 bytes, 51 asm lines)
// Default flags. No inline asm/hacks.
// MATCHED 2026-05-19: use pointer-walking do loop and declare `i` before the
// button pointer so VC5 emits xor edi before lea esi. Reload *pp after
// set_disabled so the later vcall uses the original `mov ecx,[esi]` shape.

extern void* rge_base_game;

class RGE_Base_Game {
public:
    char gap_00[0x1B0];
    int prog_mode;

    class RGE_Player* get_player();
};

class RGE_Player {
public:
    char gap_00[0x50];
};

class TButtonPanel {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(int);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(int);

    char gap_04[0x7C];
    int active;
    char gap_84[0x22C];
    int disabled;

    void set_disabled(int is_disabled);
};

class TribeDiplomacyDialog {
public:
    char gap_00[0x534];
    TButtonPanel* woodTributeButtons[8];
    char gap_554[0x614 - 0x554];
    float woodTotal;
    char gap_618[0x6B0 - 0x618];
    int curPlayerRow;
    int tributeFlag;

    int check_wood();
};

int TribeDiplomacyDialog::check_wood()
{
    register int result;
    RGE_Base_Game* game = (RGE_Base_Game*)rge_base_game;

    if (game->prog_mode == 5) {
        result = 1;
    } else {
        RGE_Player* player = game->get_player();
        float diff = *(float*)(*(int*)((char*)player + 0x50) + 4) - this->woodTotal;
        if (diff > 0.0f) {
            result = 0;
        } else {
            result = 1;
        }
    }

    int i = 0;
    TButtonPanel** pp = this->woodTributeButtons;
    do {
        TButtonPanel* btn = *pp;
        if (btn != 0) {
            if (i == this->curPlayerRow) {
                btn->set_disabled(1);
            } else {
                btn->set_disabled(result);
            }

            btn = *pp;
            if (this->tributeFlag != 0) {
                btn->vf14(1);
            } else {
                btn->vf14(0);
            }
        }
        ++i;
        ++pp;
    } while (i < 8);

    return result;
}
