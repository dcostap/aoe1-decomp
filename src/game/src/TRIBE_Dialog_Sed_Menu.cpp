#include "../include/TRIBE_Dialog_Sed_Menu.h"

#include "../include/TButtonPanel.h"
#include "../include/TPanelSystem.h"
#include "dialog_forwarders.h"
#include "../include/globals.h"

// Fully verified. Source of truth: dlg_sedm.cpp.decomp @ 0x00440140
TRIBE_Dialog_Sed_Menu::TRIBE_Dialog_Sed_Menu(TRIBE_Screen_Sed* scenario_editor)
    : TDialogPanel((char*)"Scenario Menu Dialog") {
    this->scenario_editor = scenario_editor;
    this->title = nullptr;
    for (int i = 0; i < 7; ++i) {
        this->buttons[i] = nullptr;
    }

    const long popup_id = -1;
    char* popup_file = nullptr;
    TDrawArea* area = nullptr;

    if (!TDialogPanel::setup(area, (TPanel*)scenario_editor, 0x1cc, 400, popup_file, popup_id, 1)) {
        return;
    }

    this->create_button((TPanel*)this, &this->buttons[0], 0x2443, 0, 0x1e, 0x14, 400, 0x28, 0, 0, 0);
    this->create_button((TPanel*)this, &this->buttons[1], 0x2441, 0, 0x1e, 0x46, 400, 0x28, 0, 0, 0);
    this->create_button((TPanel*)this, &this->buttons[2], 0x2442, 0, 0x1e, 0x78, 400, 0x28, 0, 0, 0);
    this->create_button((TPanel*)this, &this->buttons[3], 0x2445, 0, 0x1e, 0xaa, 400, 0x28, 0, 0, 0);
    this->create_button((TPanel*)this, &this->buttons[4], 0x242e, 0, 0x1e, 0xdc, 400, 0x28, 0, 0, 0);
    this->create_button((TPanel*)this, &this->buttons[5], 0x2446, 0, 0x1e, 0x10e, 400, 0x28, 0, 0, 0);
    this->create_button((TPanel*)this, &this->buttons[6], 0x2444, 0, 0x1e, 0x154, 400, 0x28, 0, 0, 0);

    if (this->buttons[6] != nullptr) {
        this->buttons[6]->hotkey = 0x1b;
        this->buttons[6]->hotkey_shift = 0;
    }
}

// Fully verified. Source of truth: dlg_sedm.cpp.decomp @ 0x00440360
TRIBE_Dialog_Sed_Menu::~TRIBE_Dialog_Sed_Menu() {
    this->delete_panel((TPanel**)&this->title);
    for (int i = 0; i < 7; ++i) {
        this->delete_panel((TPanel**)&this->buttons[i]);
    }
}

// Fully verified. Source of truth: dlg_sedm.cpp.decomp @ 0x00440400
long TRIBE_Dialog_Sed_Menu::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    if (param_2 == 1) {
        if ((TButtonPanel*)param_1 == this->buttons[6] || (TButtonPanel*)param_1 == this->buttons[0]) {
            if (panel_system != nullptr) {
                panel_system->setCurrentPanel((char*)"Scenario Editor Screen", 0);
                panel_system->destroyPanel((char*)"Scenario Menu Dialog");
            }
            return 1;
        }
    }
    return TEasy_Panel::action(param_1, param_2, param_3, param_4);
}

void TRIBE_Dialog_Sed_Menu::draw() {
    TDialogPanel::draw();
}

long TRIBE_Dialog_Sed_Menu::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    return TDialogPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5);
}

IMPLEMENT_TDIALOGPANEL_FORWARDERS(TRIBE_Dialog_Sed_Menu, TDialogPanel)

