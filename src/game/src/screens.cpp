#include "../include/screens.h"
#include "../include/TPanel.h"
#include "../include/custom_debug.h"
#include "../include/TShape.h"
#include "../include/TDrawArea.h"
#include "../include/RGE_Base_Game.h"

extern RGE_Base_Game* rge_base_game;

TRIBE_Screen_Main_Menu::TRIBE_Screen_Main_Menu() : TScreenPanel("Main Menu") {
    // 1. Initialize members to nullptr first
    title1 = nullptr;
    title2 = nullptr;
    for(int i=0; i<7; ++i) button[i] = nullptr;
    ms_title_text = nullptr;
    ms_copy_text1 = nullptr;
    ms_copy_text2 = nullptr;
    warning_text = nullptr;
    circle_p_pic = nullptr;

    CUSTOM_DEBUG_LOG("TRIBE_Screen_Main_Menu: constructor start");

    if (rge_base_game && rge_base_game->draw_area) {
        this->render_area = rge_base_game->draw_area;
        // TScreenPanel::setup(draw_area, name, -1, 1, 0)
        this->setup(rge_base_game->draw_area, "scr1");
    }

    this->set_ideal_size(640, 480);

    // 2. Create 5 main buttons (ASM order: Single, Multi, Help, Scen, Exit)
    int y_pos = 178; // 0xB2
    for (int i = 0; i < 5; ++i) {
        // use DrawType 4 (Graphic + Text)
        // w=300, h=40 seems to match standard button size approximately
        this->create_button(this, &button[i], "std_btn", i, 170, y_pos, 300, 40, 4, 0, 0); 
        y_pos += 50; // 0x32
    }

    // 3. Set text for known buttons from language DLL
    if (button[0]) button[0]->set_text(0x23f2); // Single Player
    if (button[1]) button[1]->set_text(0x23f3); // Multiplayer
    if (button[2]) button[2]->set_text(0x23f5); // Help
    if (button[3]) button[3]->set_text(0x23f6); // Scenario Builder
    if (button[4]) button[4]->set_text(0x23f7); // Exit

    // 4. Create Texts
    this->create_text(this, &ms_title_text, 0x2419, 10, 10, 500, 18, 0, 0, 0);
    
    this->circle_p_pic = new TPicturePanel();
    if (this->circle_p_pic) {
        // long setup(TDrawArea* p1, TPanel* p2, long x, long y, long w, long h, char* p7, long p8, int p9, int p10)
        this->circle_p_pic->setup(this->render_area, this, 0, 0, 0, 0, "circlep2", 50406, 0, 1);
    }

    // Load shared button graphic - Using 50406 (Circle P) as a known valid placeholder for now
    static TShape* btn_shape = new TShape("circlep2", 50406); 
    
    for (int i = 0; i < 5; ++i) {
        if (button[i]) {
            // Set graphic for state 0 (normal) and 1 (pressed)
            button[i]->pic[0] = btn_shape;
            button[i]->pic[1] = btn_shape; 
            button[i]->pic_index[0] = 0; // Frame 0
            button[i]->pic_index[1] = 0; // Frame 0
            button[i]->text_x = -1; // Center text
            button[i]->text_y = -1; // Center text
            
            // Set text color to Gold (Classic AoE style)
            // Color index 246 is often gold in AoE palette, but here we use RGB for GDI
            // 255, 255, 255 is white. Try Gold: 215, 185, 30
            for(int s=0; s<9; ++s) {
                button[i]->text_color1[s] = RGB(230, 200, 50); 
            }
        }
    }
}

// TShape include is needed at file level or properly forward declared/included
// Let's add the include at the top if missing or just use it here.
#include "../include/TShape.h" 

void TRIBE_Screen_Main_Menu::draw() {
    CUSTOM_DEBUG_LOG_FMT("TRIBE_Screen_Main_Menu::draw start. this=%p, area=%p", this, this->render_area);
    static TShape* bg_shape = nullptr;
    static bool tried_load = false;
    
    // 1. One-time background load
    if (!tried_load) {
        CUSTOM_DEBUG_LOG("Loading background shape...");
        bg_shape = new TShape("b_main.slp", 50100);
        tried_load = true;
        CUSTOM_DEBUG_LOG("Background shape loaded");
    }
    
    // 2. Draw Background
    if (this->render_area) {
        if (bg_shape && bg_shape->is_loaded()) {
            CUSTOM_DEBUG_LOG("Calling shape_draw...");
            bg_shape->shape_draw(this->render_area, 0, 0, 0, 0, 0, nullptr); // Adjusted to 0,0 for top-left 
                                                                               // Actually SLP hotspots are usually designed for 0,0 or center.
                                                                               // For main menu, it's often full-screen 640x480.
                                                                               // If hotspot is 0,0, then 0,0 is correct.
                                                                               // The original call had 0,0.
            CUSTOM_DEBUG_LOG("shape_draw finished");
        } else {
             CUSTOM_DEBUG_LOG("Calling FillRect...");
             this->render_area->FillRect(0, 0, 640, 480, 240);
             CUSTOM_DEBUG_LOG("FillRect finished");
        }
    }

    CUSTOM_DEBUG_LOG("Background drawn, drawing children...");

    // 3. Draw Children (Buttons)
    for (int i = 0; i < 7; ++i) {
        if (this->button[i]) {
            CUSTOM_DEBUG_LOG_FMT("Menu drawing button %d: %p", i, this->button[i]);
            this->button[i]->draw();
        } else {
            CUSTOM_DEBUG_LOG_FMT("Menu button %d is NULL", i);
        }
    }

    if (this->circle_p_pic) {
        this->circle_p_pic->draw();
    }

    /* DEBUG: Save a screenshot to verify what is being drawn
    static int saved_screenshot = 0;
    if (this->render_area && !saved_screenshot) {
        this->render_area->SaveBitmap("menu_debug.bmp");
        saved_screenshot = 1;
        CUSTOM_DEBUG_LOG("Saved menu_debug.bmp");
        exit(0); // DEBUG: Exit after screenshot as requested
    }
    */
}

long TRIBE_Screen_Main_Menu::handle_command(uint id, long p2) {
    CUSTOM_DEBUG_LOG_FMT("TRIBE_Screen_Main_Menu::handle_command: id=%u", id);
    
    switch (id) {
        case 0: // Single Player
            CUSTOM_DEBUG_LOG("Single Player clicked");
            if (rge_base_game) {
                rge_base_game->setSinglePlayerGame(1);
                rge_base_game->set_game_mode(1, 0); // CScreenPlayGame
            }
            break;
        case 1: // Multiplayer
            CUSTOM_DEBUG_LOG("Multiplayer clicked");
             if (rge_base_game) {
                rge_base_game->setMultiplayerGame(1);
                rge_base_game->set_game_mode(3, 0); // CScreenMultiplayer
            }
            break;
        case 4: // Exit
            CUSTOM_DEBUG_LOG("Exit clicked - closing game");
            if (rge_base_game) rge_base_game->close();
            break;
    }
    
    return 1;
}

// TRIBE_Screen_Main_Menu::setup (2 args)
long TRIBE_Screen_Main_Menu::setup(TDrawArea* render_area, char* name) {
    // Call TScreenPanel::setup with -1, 1, 0 as found in Scr_main.cpp.asm
    return TScreenPanel::setup(render_area, name, -1, 1, 0);
}

TRIBE_Screen_Main_Menu::~TRIBE_Screen_Main_Menu() {}

// ... rest of stubs ...

TRIBE_Screen_Main_Error::TRIBE_Screen_Main_Error() : TEasy_Panel("Main Error") {}

void TRIBE_Screen_Main_Error::set_text(int id) {}

TribeMPSetupScreen::TribeMPSetupScreen() : TEasy_Panel("MP Setup") {}

void TRIBE_Screen_Game::game_mode_changed(int new_mode, int old_mode) {
    CUSTOM_DEBUG_LOG_FMT("TRIBE_Screen_Game::game_mode_changed: new=%d, old=%d", new_mode, old_mode);
}

void TEasy_Panel::popupOKDialog(const char* text, long p2, void* p3, long p4) {
    CUSTOM_DEBUG_LOG_FMT("TEasy_Panel::popupOKDialog: %s", text ? text : "(null)");
    if (text) {
        MessageBoxA(NULL, text, "Age of Empires", MB_OK | MB_ICONEXCLAMATION);
    }
}

TRIBE_Screen_Status_Message::TRIBE_Screen_Status_Message(int p1, const char* p2, void* p3, const char* p4) : TEasy_Panel("Status") {}
