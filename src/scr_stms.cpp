// PDB source module: C:/msdev/work/age1_x1/scr_stms.cpp.
// Definitions follow the original source order.

#include "../include/scr_stms.h"
#include "../include/basegame.h"
#include "../include/panel.h"
#include "../include/panel_ez.h"
#include "../include/pnl_lst.h"
#include "../include/rge_base_game_global.h"

#include <string.h>

TRIBE_Screen_Status_Message::TRIBE_Screen_Status_Message(
    char* panel_name, char* text, char* source_info_file, long source_info_id)
    : TScreenPanel(panel_name)
{
    char info_file[260];
    long info_id;
    TEasy_Panel* current_panel;

    message = 0;
    current_panel = (TEasy_Panel*)panel_system.currentPanel();

    if (source_info_file == 0 && source_info_id == -1) {
        if (current_panel != 0 &&
            current_panel != (TEasy_Panel*)panel_system.panel("Achievements Screen")) {
            strcpy(info_file, current_panel->get_info_file());
            info_id = current_panel->get_info_id();
        } else {
            info_file[0] = 0;
            info_id = -1;
        }
    } else {
        strcpy(info_file, source_info_file);
        info_id = source_info_id;
    }

    if (info_file[0] == 0) {
        if (rge_base_game->multiplayerGame()) {
            strcpy(info_file, "scr3");
            info_id = 0xC385;
        } else {
            strcpy(info_file, "scr2");
            info_id = 0xC384;
        }
    }

    if (!setup(rge_base_game->draw_area, info_file, info_id, 0)) {
        error_code = 1;
    } else {
        set_ideal_size(0x280, 0x1E0);
        create_text(this, &message, text,
                    0x28, 0x28, 0x230, 0x190, 4, 1, 1, 1);
    }
}

TRIBE_Screen_Status_Message::TRIBE_Screen_Status_Message(
    char* panel_name, long text_id, char* source_info_file, long source_info_id)
    : TScreenPanel(panel_name)
{
    char info_file[260];
    long info_id;
    TEasy_Panel* current_panel;

    message = 0;
    current_panel = (TEasy_Panel*)panel_system.currentPanel();

    if (source_info_file == 0 && source_info_id == -1) {
        if (current_panel != 0 &&
            current_panel != (TEasy_Panel*)panel_system.panel("Achievements Screen")) {
            strcpy(info_file, current_panel->get_info_file());
            info_id = current_panel->get_info_id();
        } else {
            info_file[0] = 0;
            info_id = -1;
        }
    } else {
        strcpy(info_file, source_info_file);
        info_id = source_info_id;
    }

    if (info_file[0] == 0) {
        if (rge_base_game->multiplayerGame()) {
            strcpy(info_file, "scr3");
            info_id = 0xC385;
        } else {
            strcpy(info_file, "scr2");
            info_id = 0xC384;
        }
    }

    if (!setup(rge_base_game->draw_area, info_file, info_id, 0)) {
        error_code = 1;
    } else {
        set_ideal_size(0x280, 0x1E0);
        create_text(this, &message, text_id,
                    0x28, 0x28, 0x230, 0x190, 4, 1, 1, 1);
    }
}

TRIBE_Screen_Status_Message::~TRIBE_Screen_Status_Message()
{
    delete_panel((TPanel**)&message);
}

void TRIBE_Screen_Status_Message::set_text(char* text)
{
    message->set_text(text);
}

void TRIBE_Screen_Status_Message::set_text(long text_id)
{
    message->set_text(text_id);
}
