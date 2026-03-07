#include "../include/THelpDialog.h"

#include "../include/TButtonPanel.h"
#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Font.h"
#include "../include/TPanelSystem.h"
#include "../include/TTextPanel.h"
#include "dialog_forwarders.h"
#include "../include/globals.h"

#include <cstdlib>
#include <cstring>
#include <new>

// Fully verified. Source of truth: dlg_help.cpp.decomp @ 0x0043E840
THelpDialog::THelpDialog(TEasy_Panel* parent, char* panel_name, long text_id, long help_page_id, long x, long y)
    : TDialogPanel((char*)"Help Dialog") {
    char* text = this->get_string((int)text_id);
    this->setup_help(parent, panel_name, text, help_page_id, x, y);
}

// Fully verified. Source of truth: dlg_help.cpp.decomp @ 0x0043E8E0
THelpDialog::THelpDialog(TEasy_Panel* parent, char* panel_name, char* text, long help_page_id, long x, long y)
    : TDialogPanel((char*)"Help Dialog") {
    this->setup_help(parent, panel_name, text, help_page_id, x, y);
}

// Fully verified. Source of truth: dlg_help.cpp.decomp @ 0x0043E950
THelpDialog::~THelpDialog() {
    this->delete_panel((TPanel**)&this->ok_button);
    this->delete_panel((TPanel**)&this->encyclopedia_button);
    this->delete_panel((TPanel**)&this->list);
    this->delete_panel((TPanel**)&this->title);
}

// Fully verified. Source of truth: dlg_help.cpp.decomp @ 0x0043E9E0
void THelpDialog::setup_help(TEasy_Panel* parent, char* panel_name, char* text, long help_page_id, long x, long y) {
    this->ok_button = nullptr;
    this->encyclopedia_button = nullptr;
    this->title = nullptr;
    this->list = nullptr;

    this->parent_panel[0] = '\0';
    if (panel_name != nullptr) {
        strncpy(this->parent_panel, panel_name, sizeof(this->parent_panel) - 1);
        this->parent_panel[sizeof(this->parent_panel) - 1] = '\0';
    }

    this->help_page_id = help_page_id;

    RGE_Font* text_font = (rge_base_game != nullptr) ? rge_base_game->get_font(0xB) : nullptr;
    if (parent == nullptr) {
        return;
    }

    const long popup_id = parent->get_popup_info_id();
    char* popup_file = parent->get_popup_info_file();
    TDrawArea* area = parent->renderArea();
    if (!this->setup(area, (TPanel*)parent, 0x154, 0x190, popup_file, popup_id, 1)) {
        return;
    }

    this->create_text((TPanel*)this, &this->list, (text != nullptr) ? text : (char*)"", 0xA, 0xA, 0x14A, 0x186, 0, 0, 0, 1);

    long line_count = 2;
    if (this->list != nullptr) {
        line_count = (long)this->list->bot_line + 2;
    }
    const long font_height = (text_font != nullptr) ? text_font->font_hgt : 0x12;
    const long text_height = line_count * font_height;
    const long dialog_height = text_height + 0x37;

    long dialog_x;
    const long parent_right = parent->width() + parent->xPosition();
    if (parent_right < x + 0x163) {
        dialog_x = labs(parent->xPosition() - x - 5);
    } else {
        const long right_bound = x - 0x159;
        if (parent->xPosition() + 10 <= right_bound) {
            dialog_x = labs(right_bound - parent->xPosition());
        } else {
            dialog_x = (parent->width() / 2) - 0xAA;
        }
    }
    if (dialog_x < 0) {
        dialog_x = 0;
    }

    long dialog_y;
    const long top_candidate = y - dialog_height;
    if (parent->yPosition() <= top_candidate - 10) {
        dialog_y = labs(top_candidate - parent->yPosition() - 10);
    } else {
        const long parent_bottom = parent->height() + parent->yPosition();
        if (dialog_height + y + 10 <= parent_bottom) {
            dialog_y = labs(y - parent->yPosition() + 10);
        } else {
            dialog_y = (parent->height() / 2) - (dialog_height / 2);
        }
    }
    if (dialog_y < 0) {
        dialog_y = 0;
    }

    this->set_fixed_position(dialog_x, dialog_y, 0, dialog_height);
    this->set_ideal_size(this->pnl_wid, this->pnl_hgt);
    if (this->list != nullptr) {
        this->list->set_fixed_position(0, 0, 0, text_height);
    }

    const long button_y = text_height + 0x14;
    if ((rge_base_game != nullptr) && (rge_base_game->singlePlayerGame() != 0) && (this->help_page_id >= 0)) {
        char* help_topic = this->get_string((int)this->help_page_id);
        if ((help_topic != nullptr) && (*help_topic != '\0')) {
            this->create_button((TPanel*)this, &this->encyclopedia_button, 0x243D, 0, 0x19, button_y, 0x78, 0x19, 0, 0, 0);
        }
    }

    const long ok_x = (this->encyclopedia_button == nullptr) ? 0x6E : 0xC3;
    this->create_button((TPanel*)this, &this->ok_button, 0xFA1, 0, ok_x, button_y, 0x78, 0x19, 0, 0, 0);

    if (this->ok_button != nullptr) {
        this->ok_button->hotkey = 0x1B;
        this->ok_button->hotkey_shift = 0;
        this->set_curr_child((TPanel*)this->ok_button);
    }

    TPanel* tabs[2];
    tabs[0] = (TPanel*)this->ok_button;
    short tab_count = 1;
    if (this->encyclopedia_button != nullptr) {
        tabs[1] = (TPanel*)this->encyclopedia_button;
        tab_count = 2;
    }
    this->set_tab_order(tabs, tab_count);
}

// Fully verified. Source of truth: dlg_help.cpp.decomp @ 0x0043ED40
long THelpDialog::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    long help_page = this->help_page_id;
    if (param_2 == 1) {
        if ((TButtonPanel*)param_1 == this->ok_button) {
            panel_system->setCurrentPanel(this->parent_panel, 0);
            panel_system->destroyPanel((char*)"Help Dialog");
            return 1;
        }
        if ((TButtonPanel*)param_1 == this->encyclopedia_button) {
            panel_system->setCurrentPanel(this->parent_panel, 0);
            panel_system->destroyPanel((char*)"Help Dialog");
            if (rge_base_game != nullptr) {
                WinHelpA((HWND)rge_base_game->prog_window, "empires.hlp", 0x101, (ULONG_PTR)this->get_string((int)help_page));
            }
            return 1;
        }
    }
    return TEasy_Panel::action(param_1, param_2, param_3, param_4);
}

// Fully verified. Source of truth: dlg_help.cpp.decomp @ 0x0043EE10
long THelpDialog::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    // TODO: PARITY [MODERATE] - Decomp checks a class-local hit-test helper and can synthesize an OK-button action before fallback; current implementation always delegates directly. [decomp: dlg_help.cpp.decomp @ 0x0043EE10]
    return TDialogPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5);
}

void THelpDialog::draw() {
    TDialogPanel::draw();
}

IMPLEMENT_TDIALOGPANEL_FORWARDERS(THelpDialog, TDialogPanel)

// Fully verified. Source of truth: THelpDialog.decomp @ 0x0043E8C0
void* THelpDialog::scalar_deleting_destructor(uint param_1) {
    this->~THelpDialog();
    if ((param_1 & 1) != 0) {
        ::operator delete(this);
    }
    return this;
}

