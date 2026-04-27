// VA: 0049F9D0 action (1265B)
// scr_mp.cpp

class TPanel {
public:
    virtual ~TPanel();
};

class TEasy_Panel {
public:
    virtual ~TEasy_Panel();
};

class TribeMPStartupScreen : public TEasy_Panel {
public:
    char fields[0x4B0];
    
    int action(TPanel* sender, long actionType, unsigned param3, unsigned param4);
};

int __cdecl TEasy_Panel_action(void* this_, void* sender, int action, unsigned param3, unsigned param4);

int TribeMPStartupScreen::action(TPanel* sender, long actionType, unsigned param3, unsigned param4) {
    if (actionType != 1) {
        return TEasy_Panel_action(this, sender, actionType, param3, param4);
    }
    
    return TEasy_Panel_action(this, sender, actionType, param3, param4);
}
