// VA: 004AD590 TRIBE_Screen_Sed::command_open
// PDB source: scr_sed.cpp lines 3414-3422 (151 B, 41 asm)
// EH-framed function (/GX)
// Attempt log:

extern "C" void* __cdecl operator_new(unsigned int);

extern char s_OpenSaveDialog[];
extern char s_Scenario_Editor_Open[];

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int mode);
};

extern TPanelSystem panel_system;

class TRIBE_Screen_Sed_Open {
public:
    char pad[0x490];
    TRIBE_Screen_Sed_Open();
};

class TRIBE_Screen_Sed {
public:
    virtual ~TRIBE_Screen_Sed();
    char gap_00[0x4BC];
    unsigned char field_4C0;
    unsigned char need_to_save();
    void popupYesNoCancelDialog(long text_id, char* panel_name, int param_4, int param_5);
    void command_open(void);
};

void TRIBE_Screen_Sed::command_open(void)
{
    if (this->need_to_save()) {
        this->popupYesNoCancelDialog(0x2447, s_OpenSaveDialog, 0x1C2, 100);
        return;
    }

    TRIBE_Screen_Sed_Open* open = new TRIBE_Screen_Sed_Open();
    panel_system.setCurrentPanel(s_Scenario_Editor_Open, 0);
}
