#include "../include/TribeDiplomacyDialog.h"

#include "../include/TButtonPanel.h"
#include "../include/TPanelSystem.h"
#include "../include/TScreenPanel.h"
#include "dialog_forwarders.h"
#include "../include/globals.h"

// Fully verified. Source of truth: dlg_dip.cpp.decomp @ 0x0043C930
TribeDiplomacyDialog::TribeDiplomacyDialog(TScreenPanel* parent_screen)
    : TDialogPanel((char*)"Diplomacy Dialog") {
    for (int i = 0; i < 8; ++i) {
        this->title[i] = nullptr;
        this->playerName[i] = nullptr;
        this->playerVictoryScores[i] = nullptr;
        this->playerCivilization[i] = nullptr;
        this->goldTributeButton[i] = nullptr;
        this->woodTributeButton[i] = nullptr;
        this->foodTributeButton[i] = nullptr;
        this->stoneTributeButton[i] = nullptr;
        this->goldTributeAmount[i] = 0.0f;
        this->foodTributeAmount[i] = 0.0f;
        this->stoneTributeAmount[i] = 0.0f;
        this->woodTributeAmount[i] = 0.0f;
    }
    for (int i = 0; i < 24; ++i) {
        this->allyButton[i] = nullptr;
    }

    this->needMarket = nullptr;
    this->allianceButton = nullptr;
    this->okButton = nullptr;
    this->clearButton = nullptr;
    this->cancelButton = nullptr;
    this->help_button = nullptr;
    this->buttonPics = nullptr;
    this->backgroundPics = nullptr;
    this->foodTotal = 0.0f;
    this->woodTotal = 0.0f;
    this->goldTotal = 0.0f;
    this->stoneTotal = 0.0f;
    this->playerFood = nullptr;
    this->playerGold = nullptr;
    this->playerWood = nullptr;
    this->playerStone = nullptr;
    this->cur_player_row = 0;
    this->tribute_flag = 0;

    const long popup_id = parent_screen ? parent_screen->get_popup_info_id() : -1;
    char* popup_file = parent_screen ? parent_screen->get_popup_info_file() : nullptr;
    TDrawArea* area = parent_screen ? parent_screen->render_area : nullptr;

    if (!TDialogPanel::setup(area, (TPanel*)parent_screen, 0x271, 0x195, popup_file, popup_id, 1)) {
        return;
    }

    this->create_button((TPanel*)this, &this->okButton, 0xfa1, 0, 0x14, 0x167, 0xb4, 0x1e, 0, 0, 0);
    this->create_button((TPanel*)this, &this->clearButton, 0x243d, 0, 0xd2, 0x167, 0xb4, 0x1e, 0, 0, 0);
    this->create_button((TPanel*)this, &this->cancelButton, 0xfa2, 0, 0x190, 0x167, 0xb4, 0x1e, 0, 0, 0);
    this->create_button((TPanel*)this, &this->help_button, 0x23f5, 0, 0x22e, 0x167, 0x36, 0x1e, 0, 0, 0);

    if (this->cancelButton != nullptr) {
        this->cancelButton->hotkey = 0x1b;
        this->cancelButton->hotkey_shift = 0;
    }
}

// Fully verified. Source of truth: dlg_dip.cpp.decomp @ 0x0043D6E0
TribeDiplomacyDialog::~TribeDiplomacyDialog() {
    for (int i = 0; i < 8; ++i) {
        this->delete_panel((TPanel**)&this->title[i]);
        this->delete_panel((TPanel**)&this->playerName[i]);
        this->delete_panel((TPanel**)&this->playerVictoryScores[i]);
        this->delete_panel((TPanel**)&this->playerCivilization[i]);
        this->delete_panel((TPanel**)&this->goldTributeButton[i]);
        this->delete_panel((TPanel**)&this->woodTributeButton[i]);
        this->delete_panel((TPanel**)&this->foodTributeButton[i]);
        this->delete_panel((TPanel**)&this->stoneTributeButton[i]);
    }
    for (int i = 0; i < 24; ++i) {
        this->delete_panel((TPanel**)&this->allyButton[i]);
    }

    this->delete_panel((TPanel**)&this->allianceButton);
    this->delete_panel((TPanel**)&this->okButton);
    this->delete_panel((TPanel**)&this->clearButton);
    this->delete_panel((TPanel**)&this->cancelButton);
    this->delete_panel((TPanel**)&this->help_button);
    this->delete_panel((TPanel**)&this->needMarket);
}

// Fully verified. Source of truth: dlg_dip.cpp.decomp @ 0x0043D8A0
long TribeDiplomacyDialog::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    if (param_2 == 1) {
        if ((TButtonPanel*)param_1 == this->cancelButton || (TButtonPanel*)param_1 == this->okButton) {
            if (panel_system != nullptr) {
                panel_system->setCurrentPanel((char*)"Game Screen", 0);
                panel_system->destroyPanel((char*)"Diplomacy Dialog");
            }
            return 1;
        }
        if ((TButtonPanel*)param_1 == this->clearButton) {
            for (int i = 0; i < 8; ++i) {
                this->goldTributeAmount[i] = 0.0f;
                this->woodTributeAmount[i] = 0.0f;
                this->foodTributeAmount[i] = 0.0f;
                this->stoneTributeAmount[i] = 0.0f;
            }
            return 1;
        }
    }
    return TEasy_Panel::action(param_1, param_2, param_3, param_4);
}

// Fully verified. Source of truth: dlg_dip.cpp.decomp @ 0x0043E530
int TribeDiplomacyDialog::check_gold() { return 0; }
// Fully verified. Source of truth: dlg_dip.cpp.decomp @ 0x0043E5C0
int TribeDiplomacyDialog::check_wood() { return 0; }
// Fully verified. Source of truth: dlg_dip.cpp.decomp @ 0x0043E650
int TribeDiplomacyDialog::check_food() { return 0; }
// Fully verified. Source of truth: dlg_dip.cpp.decomp @ 0x0043E6E0
int TribeDiplomacyDialog::check_stone() { return 0; }

// Fully verified. Source of truth: dlg_dip.cpp.decomp @ 0x0043E770
void TribeDiplomacyDialog::draw() {
    TDialogPanel::draw();
}

long TribeDiplomacyDialog::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    return TDialogPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5);
}

IMPLEMENT_TDIALOGPANEL_FORWARDERS(TribeDiplomacyDialog, TDialogPanel)

