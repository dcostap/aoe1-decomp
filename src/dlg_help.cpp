#include "../include/dlg_help.h"
#include "../include/resource_ids.h"
#include <stdio.h>
#include <stdlib.h>

extern "C" char* strcpy(char*, const char*);

// The constructor is the EH-framed context anchor for this module.
THelpDialog::THelpDialog(TEasy_Panel* parentPanel, char* in_parent_panel, long help_string_id, long in_help_page_id, long x, long y)
    : TDialogPanel("Help Dialog") {
    char* text = this->get_string(help_string_id);
    this->setup_help(parentPanel, in_parent_panel, text, in_help_page_id, x, y);
}

THelpDialog::THelpDialog(TEasy_Panel* parentPanel, char* in_parent_panel, char* in_help_string, long in_help_page_id, long x, long y)
    : TDialogPanel("Help Dialog") {
    this->setup_help(parentPanel, in_parent_panel, in_help_string, in_help_page_id, x, y);
}

THelpDialog::~THelpDialog() {
    delete ok_button;
    delete encyclopedia_button;
    delete list;
    delete title;
}

void THelpDialog::setup_help(TEasy_Panel* parentPanel, char* in_parent_panel,
                             char* help_string, long in_help_page_id,
                             long mouse_x, long mouse_y) {
    TPanel* tabList[2];
    RGE_Font* rge_text_font;
    long line_height;
    long panel_height;
    long dialog_x;
    long y;

    this->ok_button = 0;
    this->encyclopedia_button = 0;
    this->title = 0;
    this->list = 0;
    strcpy(this->parent_panel, in_parent_panel);
    this->help_page_id = in_help_page_id;

    rge_text_font = rge_base_game->get_font(RGE_FONT_STANDARD);
    if (!this->setup(parentPanel->renderArea(), parentPanel, 340, 400, parentPanel->get_popup_info_file(),
                     parentPanel->get_popup_info_id(), 1)) {
        return;
    }

    this->create_text(this, &this->list, help_string, 10, 10, 330, 390, RGE_FONT_STANDARD, 0, 0, 1);

    line_height = this->list->bot_line + 2;
    panel_height = line_height * rge_text_font->font_hgt + 55;

    if (parentPanel->width() + parentPanel->xPosition() >= mouse_x + 355) {
        dialog_x = abs(parentPanel->xPosition() - mouse_x - 5);
    } else if (parentPanel->xPosition() + 10 <= mouse_x - 345) {
        dialog_x = abs(mouse_x - 345 - parentPanel->xPosition());
    } else {
        dialog_x = parentPanel->width() / 2 - 170;
    }
    if (dialog_x < 0) {
        dialog_x = 0;
    }

    if (parentPanel->yPosition() <= mouse_y - panel_height - 10) {
        y = abs(mouse_y - panel_height - parentPanel->yPosition() - 10);
    } else if (panel_height + mouse_y + 10 <= parentPanel->yPosition() + parentPanel->height()) {
        y = abs(mouse_y - parentPanel->yPosition() + 10);
    } else {
        y = parentPanel->height() / 2 - panel_height / 2;
    }
    if (y < 0) {
        y = 0;
    }

    this->set_fixed_position(dialog_x, y, 340, panel_height);
    this->set_ideal_size(this->max_wid, this->max_hgt);
    this->list->set_fixed_position(10, 10, 330, line_height * rge_text_font->font_hgt);

    if (rge_base_game->singlePlayerGame() && in_help_page_id >= 0) {
        char* help_topic = this->get_string(in_help_page_id);
        if (help_topic != 0 && *help_topic != '\0') {
            this->create_button(this, &this->encyclopedia_button, STRING_ID_BUTTON_MORE_HELP, 0, 25,
                                line_height * rge_text_font->font_hgt + 20, 120, 25, RGE_FONT_STANDARD, 0, 0);
        }
    }

    if (this->encyclopedia_button == 0) {
        this->create_button(this, &this->ok_button, STRING_ID_BUTTON_OK, 0, 110, line_height * rge_text_font->font_hgt + 20,
                            120, 25, RGE_FONT_STANDARD, 0, 0);
    } else {
        this->create_button(this, &this->ok_button, STRING_ID_BUTTON_OK, 0, 195, line_height * rge_text_font->font_hgt + 20,
                            120, 25, RGE_FONT_STANDARD, 0, 0);
    }
    TButtonPanel* button = this->ok_button;
    button->hotkey = VK_ESCAPE;
    button->hotkey_shift = 0;
    this->set_curr_child(this->ok_button);

    tabList[0] = this->ok_button;
    short tab_count = 1;
    if (this->encyclopedia_button != 0) {
        tabList[1] = this->encyclopedia_button;
        tab_count = 2;
    }
    this->set_tab_order(tabList, tab_count);
}

long THelpDialog::action(TPanel* fromPanel, long actionIn, unsigned long a1, unsigned long a2) {
    int help_page_id = this->help_page_id;

    if (actionIn == 1) {
        if (fromPanel == this->ok_button) {
            panel_system.setCurrentPanel(this->parent_panel, 0);
            panel_system.destroyPanel("Help Dialog");
            return 1;
        }

        if (fromPanel == this->encyclopedia_button) {
            panel_system.setCurrentPanel(this->parent_panel, 0);
            panel_system.destroyPanel("Help Dialog");

            HWND prog_window = rge_base_game->prog_window;
            char* help_topic = this->get_string(help_page_id);
            WinHelpA(prog_window, "empires.hlp", HELP_KEY, (DWORD)help_topic);
            return 1;
        }
    }

    return TEasy_Panel::action(fromPanel, actionIn, a1, a2);
}

long THelpDialog::handle_mouse_down(unsigned char mouse_button_in, long x, long y, int ctrl_key, int shift_key) {
    if (this->is_inside(x, y) == 0) {
        this->action(this->ok_button, 1, 0, 0);
        return 1;
    }

    return ((TEasy_Panel*)this)->TEasy_Panel::handle_mouse_down(mouse_button_in, x, y, ctrl_key, shift_key);
}
