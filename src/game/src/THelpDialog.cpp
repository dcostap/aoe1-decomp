#include "../include/THelpDialog.h"

#include "../include/TButtonPanel.h"
#include "../include/TPanelSystem.h"
#include "../include/TTextPanel.h"
#include "dialog_forwarders.h"
#include "../include/globals.h"

#include <cstring>
#include <new>

// Fully verified. Source of truth: dlg_help.cpp.decomp @ 0x0043E840
THelpDialog::THelpDialog(TEasy_Panel* parent, char* panel_name, long text_id, long x, long y, long w, long h)
    : TDialogPanel((char*)"Help Dialog") {
    this->help_page_id = text_id;
    this->title = nullptr;
    this->list = nullptr;
    this->ok_button = nullptr;
    this->encyclopedia_button = nullptr;
    this->parent_panel[0] = '\0';
    if (panel_name != nullptr) {
        strncpy(this->parent_panel, panel_name, sizeof(this->parent_panel) - 1);
        this->parent_panel[sizeof(this->parent_panel) - 1] = '\0';
    }

    char* text = this->get_string((int)text_id);
    // TODO: PARITY [CRITICAL] - dlg_help.cpp.asm and panel_ez.cpp.asm pass only three trailing longs through this ctor/setup_help chain ((help_page_id, x, y)), but this translation models four ((x, y, w, h)). The current API and layout flow are therefore structurally mismapped, not just differently pre-seeded. [decomp: dlg_help.cpp.decomp @ 0x0043E840, panel_ez.cpp.decomp @ 0x0046A260]
    this->setup_help(parent, panel_name, text, x, y, w, h);
}

// Fully verified. Source of truth: dlg_help.cpp.decomp @ 0x0043E8E0
THelpDialog::THelpDialog(TEasy_Panel* parent, char* panel_name, char* text, long x, long y, long w, long h)
    : TDialogPanel((char*)"Help Dialog") {
    this->help_page_id = -1;
    this->title = nullptr;
    this->list = nullptr;
    this->ok_button = nullptr;
    this->encyclopedia_button = nullptr;
    this->parent_panel[0] = '\0';
    if (panel_name != nullptr) {
        strncpy(this->parent_panel, panel_name, sizeof(this->parent_panel) - 1);
        this->parent_panel[sizeof(this->parent_panel) - 1] = '\0';
    }

    // TODO: PARITY [CRITICAL] - The text overload shares the same ctor/setup_help signature mismatch: source/headers route (x, y, w, h), while the asm shows (help_page_id, x, y) only. Current Panel_ez glue compensates by writing help_page_id after construction, which is not what the original call flow does. [decomp: dlg_help.cpp.decomp @ 0x0043E8E0, panel_ez.cpp.decomp @ 0x0046A2E0]
    this->setup_help(parent, panel_name, text, x, y, w, h);
}

// Fully verified. Source of truth: dlg_help.cpp.decomp @ 0x0043E950
THelpDialog::~THelpDialog() {
    this->delete_panel((TPanel**)&this->ok_button);
    this->delete_panel((TPanel**)&this->encyclopedia_button);
    this->delete_panel((TPanel**)&this->list);
    this->delete_panel((TPanel**)&this->title);
}

// Fully verified. Source of truth: dlg_help.cpp.decomp @ 0x0043E9E0
void THelpDialog::setup_help(TEasy_Panel* parent, char* panel_name, char* text, long x, long y, long w, long h) {
    // TODO: PARITY [CRITICAL] - This body is materially broader than the existing button-creation gap: the original writes help_page_id from arg4, hardcodes a 0x154x190 dialog, computes popup placement from parent/help coordinates, lays out title/list/background via virtual helpers, and only then conditionally creates a 0x243d ("More Help") button in single-player when help_page_id/topic are valid. The current implementation instead treats args as (x, y, w, h), uses generic setup/create_* placement, and creates the encyclopedia button unconditionally. [decomp: dlg_help.cpp.decomp @ 0x0043E9E0]
    const long popup_id = parent ? parent->get_popup_info_id() : -1;
    char* popup_file = parent ? parent->get_popup_info_file() : nullptr;
    TDrawArea* area = parent ? parent->render_area : nullptr;

    if (!TDialogPanel::setup(area, (TPanel*)parent, w, h, popup_file, popup_id, 1)) {
        return;
    }

    this->create_text((TPanel*)this, &this->title, 0x23f5, 0x14, 0x14, this->width() - 0x28, 0x1e, 1, 1, 1, 0);
    this->create_text((TPanel*)this, &this->list, text ? text : (char*)"", 0x14, 0x37, this->width() - 0x28, this->height() - 0x6f, 0xb, 0, 1, 0);
    this->create_button((TPanel*)this, &this->ok_button, 0xfa1, 0, x, y, 0xb4, 0x1e, 0, 0, 0);
    this->create_button((TPanel*)this, &this->encyclopedia_button, 0x2456, 0, x + 0xc0, y, 0xb4, 0x1e, 0, 0, 0);

    if (this->ok_button != nullptr) {
        this->ok_button->hotkey = 0x1b;
        this->ok_button->hotkey_shift = 0;
    }

    TPanel* tabs[2];
    tabs[0] = (TPanel*)this->ok_button;
    tabs[1] = (TPanel*)this->encyclopedia_button;
    this->set_tab_order(tabs, 2);
    this->set_curr_child((TPanel*)this->ok_button);
    (void)panel_name;
}

// Fully verified. Source of truth: dlg_help.cpp.decomp @ 0x0043ED40
long THelpDialog::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    // TODO: PARITY [CRITICAL] - encyclopedia_button click path should call WinHelpA(rge_base_game->prog_window, "empires.hlp", 0x101, get_string(help_page_id)) after closing the dialog; current implementation only closes/switches panels. [decomp: dlg_help.cpp.decomp @ 0x0043ED40]
    // TODO: PARITY [MODERATE] - Non-parity fallback to "Game Screen" when parent_panel is empty; decomp passes parent_panel directly to setCurrentPanel. [decomp: dlg_help.cpp.decomp @ 0x0043ED40]
    if (param_2 == 1) {
        if (((TButtonPanel*)param_1 == this->ok_button) || ((TButtonPanel*)param_1 == this->encyclopedia_button)) {
            if (panel_system != nullptr) {
                panel_system->setCurrentPanel(this->parent_panel[0] ? this->parent_panel : (char*)"Game Screen", 0);
                panel_system->destroyPanel((char*)"Help Dialog");
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

