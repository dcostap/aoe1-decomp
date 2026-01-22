#include "../include/screens.h"
#include "../include/globals.h"

TRIBE_Screen_Main_Menu::TRIBE_Screen_Main_Menu() {
    this->error_code = 0;
}

void TRIBE_Screen_Main_Error::set_text(int id) {}

void TRIBE_Screen_Game::game_mode_changed(int new_mode, int old_mode) {}

void TEasy_Panel::popupOKDialog(const char* text, long p2, void* p3, long p4) {}

TRIBE_Screen_Status_Message::TRIBE_Screen_Status_Message(int p1, const char* p2, void* p3, const char* p4) {}
TribeMPSetupScreen::TribeMPSetupScreen() {}
TRIBE_Screen_Main_Error::TRIBE_Screen_Main_Error() {}
