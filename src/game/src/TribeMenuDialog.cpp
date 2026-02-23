#include "../include/TribeMenuDialog.h"

#include "../include/TButtonPanel.h"
#include "../include/TPanelSystem.h"
#include "../include/TScreenPanel.h"
#include "dialog_forwarders.h"
#include "../include/globals.h"

// Fully verified. Source of truth: dlg_menu.cpp.decomp @ 0x0043F340
TribeMenuDialog::TribeMenuDialog(TScreenPanel* parent_screen)
    : TDialogPanel((char*)"Menu Dialog") {
    for (int i = 0; i < 11; ++i) {
        this->button[i] = nullptr;
    }

    const long popup_id = parent_screen ? parent_screen->get_popup_info_id() : -1;
    char* popup_file = parent_screen ? parent_screen->get_popup_info_file() : nullptr;
    TDrawArea* area = parent_screen ? parent_screen->render_area : nullptr;

    if (!TDialogPanel::setup(area, (TPanel*)parent_screen, 400, 300, popup_file, popup_id, 1)) {
        return;
    }

    this->create_button((TPanel*)this, &this->button[0], 0x2439, 0, 0x14, 0x0f, 0x168, 0x1e, 0, 0, 4);
    this->create_button((TPanel*)this, &this->button[1], 0x2437, 0, 0x14, 0x41, 0x168, 0x1e, 0, 0, 7);
    this->create_button((TPanel*)this, &this->button[2], 0x243e, 0, 0x14, 0x64, 0x168, 0x1e, 0, 0, 9);
    this->create_button((TPanel*)this, &this->button[3], 0x243a, 0, 0x14, 0x87, 0x168, 0x1e, 0, 0, 5);
    this->create_button((TPanel*)this, &this->button[4], 0x23f5, 0, 0x14, 0xaa, 0x168, 0x1e, 0, 0, 8);
    this->create_button((TPanel*)this, &this->button[5], 0x23f9, 0, 0x14, 0xcd, 0x168, 0x1e, 0, 0, 10);
    this->create_button((TPanel*)this, &this->button[6], 0x243b, 0, 0x14, 0xf0, 0x168, 0x1e, 0, 0, 6);

    if (this->button[6] != nullptr) {
        this->button[6]->hotkey = 0x1b;
        this->button[6]->hotkey_shift = 0;
    }

    TPanel* tabs[7];
    for (int i = 0; i < 7; ++i) {
        tabs[i] = (TPanel*)this->button[i];
    }
    this->set_tab_order(tabs, 7);
    this->set_curr_child((TPanel*)this->button[0]);
}

// Fully verified. Source of truth: dlg_menu.cpp.decomp @ 0x0043F6B0
TribeMenuDialog::~TribeMenuDialog() {
    for (int i = 0; i < 11; ++i) {
        this->delete_panel((TPanel**)&this->button[i]);
    }
}

// Fully verified. Source of truth: dlg_menu.cpp.decomp @ 0x0043F720
long TribeMenuDialog::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    if (param_2 == 1) {
        if ((TButtonPanel*)param_1 == this->button[6]) {
            if (panel_system != nullptr) {
                panel_system->setCurrentPanel((char*)"Game Screen", 0);
                panel_system->destroyPanel((char*)"Menu Dialog");
            }
            return 1;
        }
    }
    return TEasy_Panel::action(param_1, param_2, param_3, param_4);
}

void TribeMenuDialog::draw() {
    TDialogPanel::draw();
}

long TribeMenuDialog::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    return TDialogPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5);
}

IMPLEMENT_TDIALOGPANEL_FORWARDERS(TribeMenuDialog, TDialogPanel)

