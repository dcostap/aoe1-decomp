// 005236A0 TRIBE_Game::show_status_message
// tribegam.cpp:1216-1230, 164 bytes, __thiscall, ret 0Ch
// Fresh 2026-05-19: implement natural panel lookup/new status screen logic.
// FLAGS: config/flags/005236A0_show_status_message.rsp (/GX required for VC5 EH state around constructor)

#include "../../include/tribegam_context.h"

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
