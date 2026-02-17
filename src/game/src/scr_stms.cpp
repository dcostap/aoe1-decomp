#include "../include/TRIBE_Screen_Status_Message.h"

#include "../include/RGE_Base_Game.h"
#include "../include/TPanelSystem.h"
#include "../include/TTextPanel.h"
#include "../include/globals.h"

#include <string.h>

namespace {

static void status_screen_pick_info_context(char* out_info_file, long* out_info_id, char* info_file, long info_id) {
    if (out_info_file == nullptr || out_info_id == nullptr) {
        return;
    }

    if (info_file == nullptr && info_id == -1) {
        TEasy_Panel* current = (TEasy_Panel*)(panel_system ? panel_system->currentPanelValue : nullptr);
        TEasy_Panel* achievements = (TEasy_Panel*)(panel_system ? panel_system->panel((char*)"Achievements Screen") : nullptr);
        if (current != nullptr && current != achievements) {
            if (current->info_file_name[0] != '\0') {
                strncpy(out_info_file, current->info_file_name, 259);
                out_info_file[259] = '\0';
            } else {
                out_info_file[0] = '\0';
            }
            *out_info_id = current->info_id;
            return;
        }

        out_info_file[0] = '\0';
        *out_info_id = -1;
        return;
    }

    if (info_file != nullptr) {
        strncpy(out_info_file, info_file, 259);
        out_info_file[259] = '\0';
    } else {
        out_info_file[0] = '\0';
    }
    *out_info_id = info_id;
}

static void status_screen_apply_default_background(char* info_file, long* info_id) {
    if (info_file == nullptr || info_id == nullptr || info_file[0] != '\0') {
        return;
    }

    if (rge_base_game != nullptr && rge_base_game->multiplayerGame() != 0) {
        strcpy(info_file, "scr3");
        *info_id = 0xc385;
    } else {
        strcpy(info_file, "scr2");
        *info_id = 0xc384;
    }
}

}

// Fully verified. Source of truth: scr_stms.cpp.decomp @ 0x004B7140
TRIBE_Screen_Status_Message::TRIBE_Screen_Status_Message(char* panel_name, char* text, char* info_file, long info_id)
    : TScreenPanel(panel_name) {
    this->message = nullptr;

    char resolved_info_file[260];
    long resolved_info_id = info_id;
    status_screen_pick_info_context(resolved_info_file, &resolved_info_id, info_file, info_id);
    status_screen_apply_default_background(resolved_info_file, &resolved_info_id);

    if (this->TScreenPanel::setup(rge_base_game->draw_area, resolved_info_file, resolved_info_id, 0) == 0) {
        this->error_code = 1;
        return;
    }

    this->set_ideal_size(0x280, 0x1e0);
    this->create_text((TPanel*)this, &this->message, text, 0x28, 0x28, 0x230, 400, 4, 1, 1, 1);
}

// Fully verified. Source of truth: scr_stms.cpp.decomp @ 0x004B7330
TRIBE_Screen_Status_Message::TRIBE_Screen_Status_Message(char* panel_name, long text_id, char* info_file, long info_id)
    : TScreenPanel(panel_name) {
    this->message = nullptr;

    char resolved_info_file[260];
    long resolved_info_id = info_id;
    status_screen_pick_info_context(resolved_info_file, &resolved_info_id, info_file, info_id);
    status_screen_apply_default_background(resolved_info_file, &resolved_info_id);

    if (this->TScreenPanel::setup(rge_base_game->draw_area, resolved_info_file, resolved_info_id, 0) == 0) {
        this->error_code = 1;
        return;
    }

    this->set_ideal_size(0x280, 0x1e0);
    this->create_text((TPanel*)this, &this->message, (int)text_id, 0x28, 0x28, 0x230, 400, 4, 1, 1, 1);
}

// Fully verified. Source of truth: scr_stms.cpp.decomp @ 0x004B7500
TRIBE_Screen_Status_Message::~TRIBE_Screen_Status_Message() {
    this->delete_panel((TPanel**)&this->message);
}

// Fully verified. Source of truth: scr_stms.cpp.decomp @ 0x004B7560
void TRIBE_Screen_Status_Message::set_text(char* text) {
    if (this->message != nullptr) {
        this->message->set_text(text);
    }
}

// Fully verified. Source of truth: scr_stms.cpp.decomp @ 0x004B7580
void TRIBE_Screen_Status_Message::set_text(long text_id) {
    if (this->message != nullptr) {
        this->message->set_text(text_id);
    }
}
