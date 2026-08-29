
#include "../include/dlg_help.h"
#include <stdio.h>

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

void THelpDialog::setup_help(TEasy_Panel* parent, char* text, char* more_text,
                             long page_id, long x_limit, long y_limit)
{
    RGE_Font* rge_text_font;
    TPanel* tabList[2];
    this->ok_button = 0;
    this->encyclopedia_button = 0;
    this->title = 0;
    this->list = 0;
    strcpy(this->parent_panel, text);
    this->help_page_id = page_id;
    rge_text_font = ((RGE_Base_Game*)rge_base_game)->get_font(11);

    if (this->setup(parent->renderArea(), parent, 0x154, 0x190,
                    parent->get_popup_info_file(), parent->get_popup_info_id(), 1)) {
        this->create_text(this, &this->list, more_text, 10, 10, 0x14a, 0x186,
                          11, 0, 0, 1);
        long line_count = *(short*)((char*)this->list + 0xfe) + 2;
        long dialog_x;
        long panel_height;
        panel_height = line_count * rge_text_font->font_hgt + 0x37;

        if (parent->width() + parent->xPosition() >= x_limit + 0x163) {
            dialog_x = abs(parent->xPosition() - x_limit - 5);
        } else if (parent->xPosition() + 10 <= x_limit - 0x159) {
            dialog_x = abs((x_limit - 0x159) - parent->xPosition());
        } else {
            dialog_x = parent->width() / 2 - 0xaa;
        }
        if (dialog_x < 0) dialog_x = 0;

        long y = y_limit - panel_height;
        if (parent->yPosition() <= y - 10) {
            y = abs(y - parent->yPosition() - 10);
        } else {
            y = parent->height();
            y += parent->yPosition();
            if (panel_height + y_limit + 10 <= y) {
                y = abs(y_limit - parent->yPosition() + 10);
            } else {
                y = parent->height() / 2 - panel_height / 2;
            }
        }
        if (y < 0) y = 0;

        this->set_fixed_position(dialog_x, y, 0x154, panel_height);
        this->set_ideal_size(this->max_wid, this->max_hgt);
        this->list->set_fixed_position(10, 10, 0x14a,
                                       line_count * rge_text_font->font_hgt);

        if (((RGE_Base_Game*)rge_base_game)->singlePlayerGame() && page_id >= 0) {
            char* s = this->get_string((int)page_id);
            if (s != 0 && *s != 0) {
                this->create_button(this, &this->encyclopedia_button, 0x243d, 0, 0, 25,
                                    line_count * rge_text_font->font_hgt + 20,
                                    0x78, 25, 11, 0);
            }
        }

        if (this->encyclopedia_button == 0) {
            this->create_button(this, &this->ok_button, 0xfa1, 0, 0x6e,
                                line_count * rge_text_font->font_hgt + 20,
                                0x78, 25, 11, 0, 0);
        } else {
            this->create_button(this, &this->ok_button, 0xfa1, 0, 0xc3,
                                line_count * rge_text_font->font_hgt + 20,
                                0x78, 25, 11, 0, 0);
        }
        this->ok_button->hotkey = 0x1b;
        this->ok_button->hotkey_shift = 0;
        this->set_curr_child(this->ok_button);
        tabList[0] = this->ok_button;
        long count = 1;
        if (this->encyclopedia_button != 0) {
            tabList[1] = this->encyclopedia_button;
            count = 2;
        }
        this->set_tab_order(tabList, (short)count);
    }
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
            _WinHelpA(prog_window, "empires.hlp", 0x101, help_topic);
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
