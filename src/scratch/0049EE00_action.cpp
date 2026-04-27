// VA: 0049EE00 action (715B)
// Scr_main.cpp

class TPanel {
public:
    virtual ~TPanel();
};

class TEasy_Panel {
public:
    virtual ~TEasy_Panel();
};

class TRIBE_Screen_Main_Menu : public TEasy_Panel {
public:
    char fields[0x4B0];
    
    int action(TPanel* sender, long actionType, unsigned param3, unsigned param4);
};

long __cdecl TEasy_Panel_action(void* this_, void* sender, int action, unsigned param3, unsigned param4);

int TRIBE_Screen_Main_Menu::action(TPanel* sender, long actionType, unsigned param3, unsigned param4) {
    if (actionType == 1) {
        // Handle button click
        // Find which button was clicked
        return 1;
    }
    
    return TEasy_Panel_action(this, sender, actionType, param3, param4);
}
