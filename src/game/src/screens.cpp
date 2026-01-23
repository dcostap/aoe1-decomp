#include "../include/screens.h"
#include "../include/globals.h"
#include "../include/TDrawArea.h"
#include "../include/custom_debug.h"

TRIBE_Screen_Main_Menu::TRIBE_Screen_Main_Menu() {
    this->error_code = 0;
}

#include "../include/TShape.h"

void TRIBE_Screen_Main_Menu::draw() {
    static TShape* bg_shape = nullptr;
    static bool tried_load = false;
    
    if (!tried_load) {
        // ID 50100 is typically the main menu background
        CUSTOM_DEBUG_LOG("Loading main menu background (ID 50100)...");
        bg_shape = new TShape("b_main.slp", 50100);
        if (bg_shape->is_loaded()) {
            CUSTOM_DEBUG_LOG_FMT("Background loaded! Shapes: %d", bg_shape->shape_count());
        } else {
            CUSTOM_DEBUG_LOG("Failed to load background");
        }
        tried_load = true;
    }
    
    if (this->render_area && bg_shape && bg_shape->is_loaded()) {
        // Draw frame 0 at 0,0
        bg_shape->shape_draw(this->render_area, 0, 0, 0, 0, 0, nullptr);
    } else if (this->render_area) {
         // Fallback to red fill if no background
         this->render_area->FillRect(0, 0, 800, 600, 249); 
    }
}

void TRIBE_Screen_Main_Error::set_text(int id) {}

void TRIBE_Screen_Game::game_mode_changed(int new_mode, int old_mode) {}

void TEasy_Panel::popupOKDialog(const char* text, long p2, void* p3, long p4) {}

TRIBE_Screen_Status_Message::TRIBE_Screen_Status_Message(int p1, const char* p2, void* p3, const char* p4) {}
TribeMPSetupScreen::TribeMPSetupScreen() {}
TRIBE_Screen_Main_Error::TRIBE_Screen_Main_Error() {}
