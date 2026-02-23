#include "../include/TribeConfigDialog.h"

#include "../include/TButtonPanel.h"
#include "../include/TPanelSystem.h"
#include "../include/TScreenPanel.h"
#include "../include/TVerticalSliderPanel.h"
#include "dialog_forwarders.h"
#include "../include/globals.h"

// Fully verified. Source of truth: dlg_conf.cpp.decomp @ 0x0043B560
TribeConfigDialog::TribeConfigDialog(Mode mode, TScreenPanel* parent_screen)
    : TDialogPanel((char*)"Config Dialog") {
    this->modeValue = mode;
    this->title = nullptr;
    this->okButton = nullptr;
    this->cancelButton = nullptr;
    this->musicSlider = nullptr;
    this->soundSlider = nullptr;
    this->scrollSpeedSlider = nullptr;
    this->musicVolume = 100;
    this->soundVolume = 100;
    this->gameSpeed = 1.0f;
    this->scrollSpeed = 10;
    this->newMusicVolume = this->musicVolume;
    this->newSoundVolume = this->soundVolume;

    for (int i = 0; i < 4; ++i) {
        this->speedTitle[i] = nullptr;
        this->sizeTitle[i] = nullptr;
        this->pathFindingTitle[i] = nullptr;
        if (i < 3) {
            this->speedButton[i] = nullptr;
            this->musicTitle[i] = nullptr;
            this->soundTitle[i] = nullptr;
            this->scrollSpeedTitle[i] = nullptr;
            this->sizeButton[i] = nullptr;
            this->mouseTitle[i] = nullptr;
            this->rolloverTitle[i] = nullptr;
            this->pathFindingButton[i] = nullptr;
        }
        if (i < 2) {
            this->mouseButton[i] = nullptr;
            this->rolloverButton[i] = nullptr;
        }
    }

    const long popup_id = parent_screen ? parent_screen->get_popup_info_id() : -1;
    char* popup_file = parent_screen ? parent_screen->get_popup_info_file() : nullptr;
    TDrawArea* area = parent_screen ? parent_screen->render_area : nullptr;

    if (!TDialogPanel::setup(area, (TPanel*)parent_screen, 600, 0x186, popup_file, popup_id, 1)) {
        return;
    }

    this->create_text((TPanel*)this, &this->title, 0x24d7, 0x67, 10, 0x18b, 0x1e, 1, 1, 1, 0);
    this->create_button((TPanel*)this, &this->okButton, 0xfa1, 0, 0xae, 0x154, 0xf0, 0x1e, 0, 0, 0);
    this->create_button((TPanel*)this, &this->cancelButton, 0xfa2, 0, 0x1b0, 0x154, 0xf0, 0x1e, 0, 0, 0);

    if (this->cancelButton != nullptr) {
        this->cancelButton->hotkey = 0x1b;
        this->cancelButton->hotkey_shift = 0;
    }

    TPanel* tabs[2];
    tabs[0] = (TPanel*)this->okButton;
    tabs[1] = (TPanel*)this->cancelButton;
    this->set_tab_order(tabs, 2);
    this->set_curr_child((TPanel*)this->okButton);
}

// Fully verified. Source of truth: dlg_conf.cpp.decomp @ 0x0043C0C0
TribeConfigDialog::~TribeConfigDialog() {
    this->delete_panel((TPanel**)&this->title);
    for (int i = 0; i < 4; ++i) {
        this->delete_panel((TPanel**)&this->speedTitle[i]);
        this->delete_panel((TPanel**)&this->sizeTitle[i]);
        this->delete_panel((TPanel**)&this->pathFindingTitle[i]);
        if (i < 3) {
            this->delete_panel((TPanel**)&this->speedButton[i]);
            this->delete_panel((TPanel**)&this->musicTitle[i]);
            this->delete_panel((TPanel**)&this->soundTitle[i]);
            this->delete_panel((TPanel**)&this->scrollSpeedTitle[i]);
            this->delete_panel((TPanel**)&this->sizeButton[i]);
            this->delete_panel((TPanel**)&this->mouseTitle[i]);
            this->delete_panel((TPanel**)&this->rolloverTitle[i]);
            this->delete_panel((TPanel**)&this->pathFindingButton[i]);
        }
        if (i < 2) {
            this->delete_panel((TPanel**)&this->mouseButton[i]);
            this->delete_panel((TPanel**)&this->rolloverButton[i]);
        }
    }
    this->delete_panel((TPanel**)&this->musicSlider);
    this->delete_panel((TPanel**)&this->soundSlider);
    this->delete_panel((TPanel**)&this->scrollSpeedSlider);
    this->delete_panel((TPanel**)&this->okButton);
    this->delete_panel((TPanel**)&this->cancelButton);
}

// Fully verified. Source of truth: dlg_conf.cpp.decomp @ 0x0043C2B0
long TribeConfigDialog::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    if (param_2 == 1) {
        if ((TButtonPanel*)param_1 == this->okButton) {
            if (panel_system != nullptr) {
                panel_system->setCurrentPanel((char*)"Game Screen", 0);
                panel_system->destroyPanel((char*)"Config Dialog");
            }
            return 1;
        }
        if ((TButtonPanel*)param_1 == this->cancelButton) {
            if (panel_system != nullptr) {
                panel_system->setCurrentPanel((char*)"Game Screen", 0);
                panel_system->destroyPanel((char*)"Config Dialog");
            }
            return 1;
        }
    }
    return TEasy_Panel::action(param_1, param_2, param_3, param_4);
}

void TribeConfigDialog::draw() {
    TDialogPanel::draw();
}

long TribeConfigDialog::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    return TDialogPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5);
}

IMPLEMENT_TDIALOGPANEL_FORWARDERS(TribeConfigDialog, TDialogPanel)

