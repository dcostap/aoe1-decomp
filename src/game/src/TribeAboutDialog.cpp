#include "../include/TribeAboutDialog.h"

#include "../include/TButtonPanel.h"
#include "../include/TPanelSystem.h"
#include "../include/TPicturePanel.h"
#include "../include/TScreenPanel.h"
#include "../include/TTextPanel.h"
#include "dialog_forwarders.h"
#include "../include/globals.h"

// Fully verified. Source of truth: dlg_abt.cpp.decomp @ 0x0043AD70
TribeAboutDialog::TribeAboutDialog(TScreenPanel* parent_screen)
    : TDialogPanel((char*)"About Dialog") {
    this->title_text = nullptr;
    this->version_text = nullptr;
    this->ms_copy_text1 = nullptr;
    this->ms_copy_text2 = nullptr;
    this->ens_copy_text = nullptr;
    this->genie_copy_text = nullptr;
    this->pid_label_text = nullptr;
    this->pid_text = nullptr;
    this->warning_text = nullptr;
    this->credits_button = nullptr;
    this->close_button = nullptr;
    this->circle_p_pic = nullptr;
    this->background = nullptr;

    const long popup_id = parent_screen ? parent_screen->get_popup_info_id() : -1;
    char* popup_file = parent_screen ? parent_screen->get_popup_info_file() : nullptr;
    TDrawArea* area = parent_screen ? parent_screen->render_area : nullptr;

    if (!TDialogPanel::setup(area, (TPanel*)parent_screen, 0x208, 0x19c, popup_file, popup_id, 1)) {
        return;
    }

    this->create_text((TPanel*)this, &this->background, (char*)"", 10, 10, 500, 0x15e, 4, 0, 0, 0);
    this->create_text((TPanel*)this, &this->title_text, 0x2419, 0x14, 0x14, 0x1e0, 0x14, 4, 0, 0, 0);
    this->create_text((TPanel*)this, &this->version_text, 0x241a, 0x14, 0x28, 0x1e0, 0x14, 0xb, 0, 0, 0);
    this->create_text((TPanel*)this, &this->ms_copy_text1, 0x241b, 0x14, 0x41, 0x1e0, 0x14, 10, 0, 0, 0);
    this->create_text((TPanel*)this, &this->ms_copy_text2, 0x241c, 0x14, 0x55, 0x1e0, 0x14, 10, 0, 0, 0);
    this->create_text((TPanel*)this, &this->ens_copy_text, 0x241d, 0x14, 0x78, 0x1e0, 0x14, 10, 0, 0, 0);
    this->create_text((TPanel*)this, &this->genie_copy_text, 0x241e, 0x14, 0x8c, 0x1e0, 0x14, 10, 0, 0, 0);
    this->create_text((TPanel*)this, &this->warning_text, 0x241f, 0x14, 0x140, 0x1e0, 0x14, 10, 0, 0, 0);

    this->create_button((TPanel*)this, &this->credits_button, 0x2423, 0, 0x14, 0x167, 0x104, 0x1e, 0, 0, 0);
    this->create_button((TPanel*)this, &this->close_button, 0x243b, 0, 0x124, 0x167, 0x104, 0x1e, 0, 0, 0);
    if (this->close_button != nullptr) {
        this->close_button->hotkey = 0x1b;
        this->close_button->hotkey_shift = 0;
    }

    TPanel* tabs[2];
    tabs[0] = (TPanel*)this->credits_button;
    tabs[1] = (TPanel*)this->close_button;
    this->set_tab_order(tabs, 2);
    this->set_curr_child((TPanel*)this->credits_button);
}

// Fully verified. Source of truth: dlg_abt.cpp.decomp @ 0x0043B300
TribeAboutDialog::~TribeAboutDialog() {
    this->delete_panel((TPanel**)&this->title_text);
    this->delete_panel((TPanel**)&this->version_text);
    this->delete_panel((TPanel**)&this->ms_copy_text1);
    this->delete_panel((TPanel**)&this->ms_copy_text2);
    this->delete_panel((TPanel**)&this->ens_copy_text);
    this->delete_panel((TPanel**)&this->genie_copy_text);
    this->delete_panel((TPanel**)&this->pid_label_text);
    this->delete_panel((TPanel**)&this->pid_text);
    this->delete_panel((TPanel**)&this->warning_text);
    this->delete_panel((TPanel**)&this->credits_button);
    this->delete_panel((TPanel**)&this->close_button);
    this->delete_panel((TPanel**)&this->circle_p_pic);
    this->delete_panel((TPanel**)&this->background);
}

// Fully verified. Source of truth: dlg_abt.cpp.decomp @ 0x0043B400
long TribeAboutDialog::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    if (param_2 == 1) {
        if ((TButtonPanel*)param_1 == this->credits_button) {
            if (panel_system != nullptr) {
                panel_system->setCurrentPanel((char*)"Credits Screen", 0);
                panel_system->destroyPanel((char*)"About Dialog");
            }
            return 1;
        }
        if ((TButtonPanel*)param_1 == this->close_button) {
            if (panel_system != nullptr) {
                panel_system->setCurrentPanel((char*)"Game Screen", 0);
                panel_system->destroyPanel((char*)"About Dialog");
            }
            return 1;
        }
    }
    return TEasy_Panel::action(param_1, param_2, param_3, param_4);
}

// Fully verified. Source of truth: dlg_abt.cpp.decomp @ 0x0043B550
void TribeAboutDialog::draw() {
    TEasy_Panel::draw();
}

long TribeAboutDialog::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    return TDialogPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5);
}

IMPLEMENT_TDIALOGPANEL_FORWARDERS(TribeAboutDialog, TDialogPanel)

