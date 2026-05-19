// VA: 004B7EE0 TribeSelectTribeScreen::action (140B)
// PDB source: scr_trb.cpp lines 178-197
// Attempt log:
// rewrite 2026-05-19: replaced cdecl helper stubs with real thiscall member surfaces for TEasy_Panel, TPanelSystem, and fillTribeText.
// retry: corrected layout by restoring field_47C/field_480 before tribeButton so tribeButton begins at +0x484, and used a normal for-loop. This removed the EBX save and matched the original loop/fallback layout. check_function: MATCH / 0.0000%.

class TPanel { public: virtual ~TPanel(); };
class TTextPanel { public: virtual ~TTextPanel(); };
class TButtonPanel { public: virtual ~TButtonPanel(); };

class TEasy_Panel {
public:
    virtual ~TEasy_Panel();
    long action(TPanel* sender, long actionType, unsigned param3, unsigned param4);
};

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int a);
    int destroyPanel(char* name);
};

#define panel_system (*(TPanelSystem*)0x62E870)

class TribeSelectTribeScreen : public TEasy_Panel {
public:
    char gap4[0x478];
    TTextPanel* field_47C;
    TTextPanel* field_480;
    TButtonPanel* tribeButton[9]; // +0x484
    TButtonPanel* okButton;       // +0x4A8
    TButtonPanel* cancelButton;   // +0x4AC
    char** field_4B0;
    int field_4B4;

    void fillTribeText(int idx);
    long action(TPanel* sender, long actionType, unsigned param3, unsigned param4);
};

long TribeSelectTribeScreen::action(TPanel* sender, long actionType, unsigned param3, unsigned param4)
{
    if (sender == (TPanel*)this->okButton || sender == (TPanel*)this->cancelButton) {
        if (actionType == 1) {
            panel_system.setCurrentPanel("MP Setup Screen", 0);
            panel_system.destroyPanel("Select Tribe Screen");
            return 1;
        }
    } else if (actionType == 1) {
        int i;
        for (i = 0; i < 9; i++) {
            if (sender == (TPanel*)this->tribeButton[i]) {
                this->fillTribeText(i);
                return 1;
            }
        }
    }

    return this->TEasy_Panel::action(sender, actionType, param3, param4);
}
