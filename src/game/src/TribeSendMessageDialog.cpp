#include "../include/TribeSendMessageDialog.h"

#include "../include/TButtonPanel.h"
#include "../include/TEditPanel.h"
#include "../include/TPanelSystem.h"
#include "../include/TScreenPanel.h"
#include "../include/TribeSendQuickMessageDialog.h"
#include "dialog_forwarders.h"
#include "../include/globals.h"

// Fully verified. Source of truth: dlg_smsg.cpp.decomp @ 0x004407A0
TribeSendMessageDialog::TribeSendMessageDialog(TScreenPanel* parent_screen)
    : TDialogPanel((char*)"Send Message Dialog") {
    this->title = nullptr;
    this->chatInput = nullptr;
    this->chatTitle = nullptr;
    this->okButton = nullptr;
    this->help_button = nullptr;
    this->radioButtonShapes = nullptr;
    this->backgroundPics = nullptr;
    for (int i = 0; i < 8; ++i) {
        this->playerName[i] = nullptr;
        this->playerCivilization[i] = nullptr;
        this->checkButton[i] = nullptr;
        this->commPlayers[i] = 0;
        if (i < 4) {
            this->radioTitle[i] = nullptr;
            this->radioButton[i] = nullptr;
        }
    }

    const long popup_id = parent_screen ? parent_screen->get_popup_info_id() : -1;
    char* popup_file = parent_screen ? parent_screen->get_popup_info_file() : nullptr;
    TDrawArea* area = parent_screen ? parent_screen->render_area : nullptr;

    if (!TDialogPanel::setup(area, (TPanel*)parent_screen, 0x208, 0x1d1, popup_file, popup_id, 1)) {
        return;
    }

    this->create_text((TPanel*)this, &this->title, 0x2667, 5, 10, this->width() - 0x28, 0x1e, 1, 1, 1, 0);
    this->create_edit((TPanel*)this, &this->chatInput, (char*)"", 0xff, FormatAny, 0x14, 0x16d, 0x1cc, 0x17, 0xb, 1, 1);
    this->create_text((TPanel*)this, &this->chatTitle, 0x2668, 0x14, 0x152, 0x1cc, 0x17, 4, 0, 1, 0);
    this->create_button((TPanel*)this, &this->okButton, 0xfa1, 0, 0x14, 0x18b, 0xf0, 0x1e, 0, 0, 0);
    this->create_button((TPanel*)this, &this->help_button, 0x23f5, 0, 0x124, 0x18b, 0xf0, 0x1e, 0, 0, 0);
    if (this->okButton != nullptr) {
        this->okButton->hotkey = 0x0d;
        this->okButton->hotkey_shift = 0;
    }
}

// Fully verified. Source of truth: dlg_smsg.cpp.decomp @ 0x00440E20
TribeSendMessageDialog::~TribeSendMessageDialog() {
    this->delete_panel((TPanel**)&this->title);
    for (int i = 0; i < 8; ++i) {
        this->delete_panel((TPanel**)&this->playerName[i]);
        this->delete_panel((TPanel**)&this->playerCivilization[i]);
        this->delete_panel((TPanel**)&this->checkButton[i]);
        if (i < 4) {
            this->delete_panel((TPanel**)&this->radioTitle[i]);
            this->delete_panel((TPanel**)&this->radioButton[i]);
        }
    }
    this->delete_panel((TPanel**)&this->chatInput);
    this->delete_panel((TPanel**)&this->chatTitle);
    this->delete_panel((TPanel**)&this->okButton);
    this->delete_panel((TPanel**)&this->help_button);
}

// Fully verified. Source of truth: dlg_smsg.cpp.decomp @ 0x00440F20
long TribeSendMessageDialog::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    if (param_2 == 1) {
        if ((TButtonPanel*)param_1 == this->okButton) {
            if (panel_system != nullptr) {
                panel_system->setCurrentPanel((char*)"Game Screen", 0);
                panel_system->destroyPanel((char*)"Send Message Dialog");
            }
            return 1;
        }
        if ((TButtonPanel*)param_1 == this->help_button) {
            this->setup_popup_help();
            return 1;
        }
    }
    return TEasy_Panel::action(param_1, param_2, param_3, param_4);
}

// Fully verified. Source of truth: dlg_smsg.cpp.decomp @ 0x00441410
void TribeSendMessageDialog::checkButtons() {
    for (int i = 0; i < 8; ++i) {
        if (this->checkButton[i] == nullptr) {
            continue;
        }
    }
}

// Fully verified. Source of truth: dlg_smsg.cpp.decomp @ 0x00441460
void TribeSendMessageDialog::draw() {
    TEasy_Panel::draw();
}

long TribeSendMessageDialog::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    return TDialogPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5);
}

IMPLEMENT_TDIALOGPANEL_FORWARDERS(TribeSendMessageDialog, TDialogPanel)

// Fully verified. Source of truth: dlg_smsg.cpp.decomp @ 0x00441530
TribeSendQuickMessageDialog::TribeSendQuickMessageDialog(TScreenPanel* parent_screen, Mode mode)
    : TDialogPanel((char*)"Send Quick Message Dialog") {
    this->chatInput = nullptr;
    this->chatTitle = nullptr;
    this->modeValue = mode;

    const long popup_id = parent_screen ? parent_screen->get_popup_info_id() : -1;
    char* popup_file = parent_screen ? parent_screen->get_popup_info_file() : nullptr;
    TDrawArea* area = parent_screen ? parent_screen->render_area : nullptr;
    if (!TDialogPanel::setup(area, (TPanel*)parent_screen, 0x190, 0x96, popup_file, popup_id, 1)) {
        return;
    }

    this->create_edit((TPanel*)this, &this->chatInput, (char*)"", 0xff, FormatAny, 0x14, 0x2d, 0x168, 0x17, 0xb, 1, 1);
    this->create_text((TPanel*)this, &this->chatTitle, 0x2668, 0x14, 0x14, 0x168, 0x14, 4, 0, 1, 0);
    this->set_curr_child((TPanel*)this->chatInput);
}

// Fully verified. Source of truth: dlg_smsg.cpp.decomp @ 0x00441650
TribeSendQuickMessageDialog::~TribeSendQuickMessageDialog() {
    this->delete_panel((TPanel**)&this->chatInput);
    this->delete_panel((TPanel**)&this->chatTitle);
}

// Fully verified. Source of truth: dlg_smsg.cpp.decomp @ 0x004416C0
long TribeSendQuickMessageDialog::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    if (param_2 == 1 || (param_1 == (TPanel*)this->chatInput && param_2 == 0)) {
        if (panel_system != nullptr) {
            panel_system->setCurrentPanel((char*)"Game Screen", 0);
            panel_system->destroyPanel((char*)"Send Quick Message Dialog");
        }
        return 1;
    }
    return TEasy_Panel::action(param_1, param_2, param_3, param_4);
}

// Fully verified. Source of truth: dlg_smsg.cpp.decomp @ 0x00441840
long TribeSendQuickMessageDialog::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    return TDialogPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5);
}

void TribeSendQuickMessageDialog::draw() {
    TDialogPanel::draw();
}

IMPLEMENT_TDIALOGPANEL_FORWARDERS(TribeSendQuickMessageDialog, TDialogPanel)

