// 005236A0 TRIBE_Game::show_status_message
// tribegam.cpp:1216-1230, 164 bytes, __thiscall, ret 0Ch
// Fresh 2026-05-19: implement natural panel lookup/new status screen logic.
// FLAGS: config/flags/005236A0_show_status_message.rsp (/GX required for VC5 EH state around constructor)

class TPanel { public: virtual void vf00(); };
class TRIBE_Screen_Status_Message;

class TPanelSystem {
public:
    TPanel* panel(char* name);
    int setCurrentPanel(char* name, int flag);
};

extern TPanelSystem panel_system;
void* operator new(unsigned int size);

class TRIBE_Game {
public:
    void draw_window();
    void show_status_message(char* s1, char* s2, long p3);
};

class TRIBE_Screen_Status_Message : public TPanel {
public:
    char gap_04[0x478];
    TRIBE_Screen_Status_Message(char* panelName, char* s1, char* s2, long p3);
    void set_text(char* s1);
};

static char status_screen[] = "Status Screen";

void TRIBE_Game::show_status_message(char* s1, char* s2, long p3) {
    TRIBE_Screen_Status_Message* panel;
    panel = (TRIBE_Screen_Status_Message*)panel_system.panel(status_screen);
    if (panel) {
        panel->set_text(s1);
        this->draw_window();
    } else {
        panel = new TRIBE_Screen_Status_Message(status_screen, s1, s2, p3);
    }
    panel_system.setCurrentPanel(status_screen, 0);
}
