// VA: 004B7EE0 action (140B)
// scr_trb.cpp lines 178-197

class TPanel {
public:
    virtual ~TPanel();
};

class TTextPanel {
public:
    virtual ~TTextPanel();
};

class TButtonPanel {
public:
    virtual ~TButtonPanel();
};

class TEasy_Panel {
public:
    virtual ~TEasy_Panel();
};

class TribeSelectTribeScreen : public TEasy_Panel {
public:
    char gap4[0x478];
    TTextPanel* field_47C;
    TTextPanel* field_480;
    TButtonPanel* field_484[9];
    TButtonPanel* field_4A8;
    TButtonPanel* field_4AC;
    char** field_4B0;
    int field_4B4;
    
    long action(TPanel* sender, long actionType, unsigned param3, unsigned param4);
};

extern int panel_system;
extern void __cdecl fillTribeText(void* this_, int idx);
extern long __cdecl TEasy_Panel_action(void* this_, void* sender, int action, unsigned param3, unsigned param4);
int __cdecl setCurrentPanel(void* sys, const char* name, int a);
int __cdecl destroyPanel(void* sys, const char* name);

long TribeSelectTribeScreen::action(TPanel* sender, long actionType, unsigned param3, unsigned param4) {
    if (sender == (TPanel*)field_4A8 || sender == (TPanel*)field_4AC) {
        if (actionType == 1) {
            setCurrentPanel(&panel_system, "MP Setup Screen", 0);
            destroyPanel(&panel_system, "Select Tribe Screen");
            return 1;
        }
    } else if (actionType == 1) {
        int i;
        for (i = 0; i < 9; i++) {
            if (sender == (TPanel*)field_484[i]) {
                fillTribeText(this, i);
                return 1;
            }
        }
    }
    
    return TEasy_Panel_action(this, sender, actionType, param3, param4);
}
