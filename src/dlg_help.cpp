
#include "../include/dlg_help.h"
#include <stdio.h>
#include <stdlib.h>

extern "C" char* strcpy(char*, const char*);

// The constructor is the EH-framed context anchor for this module.
THelpDialog::THelpDialog(TEasy_Panel* parent, char* name, long page_id,
                         long x_limit, long y_limit, long extra)
    : TDialogPanel("Help Dialog")
{
    char* text = this->get_string(page_id);
    this->setup_help(parent, name, text, x_limit, y_limit, extra);
}

THelpDialog::THelpDialog(TEasy_Panel* parent, char* name, char* text,
                         long x_limit, long y_limit, long extra)
    : TDialogPanel("Help Dialog")
{
    this->setup_help(parent, name, text, x_limit, y_limit, extra);
}

THelpDialog::~THelpDialog()
{
    delete ok_button;
    delete encyclopedia_button;
    delete list;
    delete title;
}

void THelpDialog::setup_help(TEasy_Panel* parent, char* name, char* text,
                             long help_page_id, long help_x,
                             long help_y)
{
    TPanel* tab_list[2];
    RGE_Font* text_font;
    long line_height;
    long dialog_height;
    long x;
    long y;

    this->ok_button = 0;
    this->encyclopedia_button = 0;
    this->title = 0;
    this->list = 0;
    strcpy(this->parent_panel, name);
    this->help_page_id = help_page_id;

    text_font = rge_base_game->get_font(0x0B);
    if (!this->setup(parent->renderArea(), parent, 0x154, 0x190,
                     parent->get_popup_info_file(),
                     parent->get_popup_info_id(), 1)) {
        return;
    }

    this->create_text(this, &this->list, text, 10, 10, 0x14A, 0x186,
                      0x0B, 0, 0, 1);

    line_height = this->list->bot_line + 2;
    dialog_height = line_height * text_font->font_hgt + 0x37;

    if (parent->width() + parent->xPosition() >= help_x + 0x163) {
        x = abs(parent->xPosition() - help_x - 5);
    } else if (parent->xPosition() + 10 <= help_x - 0x159) {
        x = abs(help_x - 0x159 - parent->xPosition());
    } else {
        x = parent->width() / 2 - 0xAA;
    }
    if (x < 0) {
        x = 0;
    }

    if (parent->yPosition() <= help_y - dialog_height - 10) {
        y = abs(help_y - dialog_height - parent->yPosition() - 10);
    } else if (dialog_height + help_y + 10 <=
               parent->yPosition() + parent->height()) {
        y = abs(help_y - parent->yPosition() + 10);
    } else {
        y = parent->height() / 2 - dialog_height / 2;
    }
    if (y < 0) {
        y = 0;
    }

    this->set_fixed_position(x, y, 0x154, dialog_height);
    this->set_ideal_size(this->max_wid, this->max_hgt);
    this->list->set_fixed_position(10, 10, 0x14A,
                                   line_height * text_font->font_hgt);

    if (rge_base_game->singlePlayerGame() && help_page_id >= 0) {
        char* help_string = this->get_string(help_page_id);
        if (help_string != 0 && *help_string != '\0') {
            this->create_button(this, &this->encyclopedia_button, 0x243D, 0,
                                0x19,
                                line_height * text_font->font_hgt + 0x14,
                                0x78, 0x19, 0x0B, 0, 0);
        }
    }

    if (this->encyclopedia_button == 0) {
        this->create_button(this, &this->ok_button, 0xFA1, 0, 0x6E,
                            line_height * text_font->font_hgt + 0x14,
                            0x78, 0x19, 0x0B, 0, 0);
    } else {
        this->create_button(this, &this->ok_button, 0xFA1, 0, 0xC3,
                            line_height * text_font->font_hgt + 0x14,
                            0x78, 0x19, 0x0B, 0, 0);
    }
    TButtonPanel* button = this->ok_button;
    button->hotkey = 0x1B;
    button->hotkey_shift = 0;
    this->set_curr_child(this->ok_button);

    tab_list[0] = this->ok_button;
    short tab_count = 1;
    if (this->encyclopedia_button != 0) {
        tab_list[1] = this->encyclopedia_button;
        tab_count = 2;
    }
    this->set_tab_order(tab_list, tab_count);
}

long THelpDialog::action(TPanel* panel, long command, unsigned long param_3,
                         unsigned long param_4)
{
    int help_page_id = this->help_page_id;

    if (command == 1) {
        if (panel == this->ok_button) {
            panel_system.setCurrentPanel(this->parent_panel, 0);
            panel_system.destroyPanel("Help Dialog");
            return 1;
        }

        if (panel == this->encyclopedia_button) {
            panel_system.setCurrentPanel(this->parent_panel, 0);
            panel_system.destroyPanel("Help Dialog");

            HWND prog_window = rge_base_game->prog_window;
            char* help_topic = this->get_string(help_page_id);
            WinHelpA(prog_window, "empires.hlp", 0x101, (DWORD)help_topic);
            return 1;
        }
    }

    return TEasy_Panel::action(panel, command, param_3, param_4);
}

long THelpDialog::handle_mouse_down(unsigned char button, long x, long y,
                                    int flags, int area)
{
    if (this->is_inside(x, y) == 0) {
        this->action(this->ok_button, 1, 0, 0);
        return 1;
    }

    return ((TEasy_Panel*)this)->TEasy_Panel::handle_mouse_down(
        button, x, y, flags, area);
}
