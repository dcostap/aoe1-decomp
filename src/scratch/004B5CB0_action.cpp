// VA: 004B5CB0 TribeGameSettingsScreen::action
// PDB source: scr_set.cpp
// Attempt log:
// - 8 attempts: goto def pattern fixed shared handler, switch matched sub/dec dispatch
// - Remaining diff: ~18% edit / 28% positional
// - Switch generates sub eax,7; je; dec eax; je (correct dispatch form)
// - But default handler placed BEFORE case8 handler (fall-through to default)
//   vs original: jne to default AFTER case handler block (2-byte offset cascade)
// - Also: first okButton check loads into ecx for register-to-register cmp
//   instead of original's direct memory cmp. CancelButton/help_button are correct (memory form).
// - Left in scratch: structural VC5 codegen barrier for default/case block placement

#define VPAD1(n) virtual void vpad##n() {}
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)

class TPanel {
public:
    virtual ~TPanel();
    char gap_04[0xF0];
    void set_curr_child(TPanel* child);
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];
    void setup_popup_help();
    long action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4);
    void activatePanels();
};

class TDropDownPanel : public TPanel {
public:
    char gap_F4[0x398];
    long get_id();
    void set_line(long val);
};

class TribeMPSetupScreen {
public:
    VPAD16(0)
    VPAD16(16)
    VPAD8(32)
    VPAD4(40)
    VPAD1(44)
    virtual void vfB4(TPanel* caller, int a, int b, int c);
};

class TribeGameSettingsScreen : public TEasy_Panel {
public:
    char gap_478[0x1C];
    TDropDownPanel* victoryTypeDrop;   // +0x494
    char gap_498[0x0C];
    TDropDownPanel* scoreDrop;         // +0x4A4
    char gap_4A8[0x04];
    TDropDownPanel* timeDrop;          // +0x4AC
    char gap_4B0[0x40];
    TPanel* scenarioList;              // +0x4F0
    char gap_4F4[0x10];
    int scenariosLoaded;               // +0x504
    char gap_508[0x3C];
    TPanel* okButton;                  // +0x544
    TPanel* cancelButton;              // +0x548
    TPanel* help_button;               // +0x54C
    TribeMPSetupScreen* chat_scr;      // +0x550
    char gap_554[0x0C];

    long action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4);
    void sendSettings();
    void getSettings();
    void fillMissionText();
};

long TribeGameSettingsScreen::action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4)
{
    if (param_1 == 0)
        goto def;

    if (this->scenariosLoaded == 0)
        goto def;

    if (param_1 == this->okButton && param_2 == 1) {
        ((TPanel*)this)->set_curr_child(this->scenarioList);
        this->sendSettings();
        this->chat_scr->vfB4(this, 1, 0, 0);
        return 1;
    }

    if (param_1 == this->cancelButton && param_2 == 1) {
        ((TPanel*)this)->set_curr_child(this->scenarioList);
        this->getSettings();
        this->chat_scr->vfB4(this, 0, 0, 0);
        return 1;
    }

    if (param_1 == this->help_button && param_2 == 1) {
        ((TEasy_Panel*)this)->setup_popup_help();
        return 1;
    }

    if (param_1 == (TPanel*)this->victoryTypeDrop && param_2 == 0) {
        switch (this->victoryTypeDrop->get_id()) {
        case 7:
            this->timeDrop->set_line(3);
            break;
        case 8:
            this->scoreDrop->set_line(7);
            break;
        default:
            this->activatePanels();
            return 1;
        }
        this->activatePanels();
        return 1;
    }

    if (param_1 == this->scenarioList) {
        if (param_2 == 3)
            return 1;
        if (param_2 == 1) {
            this->fillMissionText();
            this->activatePanels();
            return 1;
        }
    }

def:
    return ((TEasy_Panel*)this)->action(param_1, param_2, param_3, param_4);
}
