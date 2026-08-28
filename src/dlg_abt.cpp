// PDB source module: C:\\msdev\\work\\age1_x1\\dlg_abt.cpp.
// The handwritten owners follow the original source order.
// The scalar deleting destructor at 0043B2E0 is compiler generated.

#include "../include/dlg_abt.h"
#include "../include/pnl_lst.h"
#include "../include/pnl_btn.h"
#include "../include/pnl_pic.h"
#include "../include/scr_cred.h"
#include "../include/basegame.h"
#include "../include/registry.h"

#include <stdio.h>
#include <string.h>

extern TRegistry* Regs;

// 0043AD70 TribeAboutDialog::TribeAboutDialog (dlg_abt.cpp:46-148)
TribeAboutDialog::TribeAboutDialog(TScreenPanel* parent)
    : TDialogPanel("About Dialog")
{
    char temp_str[512];
    char str[4096];
    tagRECT rect;
    int modal = 1;

    this->title_text = 0;
    this->version_text = 0;
    this->ms_copy_text1 = 0;
    this->ms_copy_text2 = 0;
    this->ens_copy_text = 0;
    this->genie_copy_text = 0;
    this->pid_label_text = 0;
    this->pid_text = 0;
    this->warning_text = 0;
    this->credits_button = 0;
    this->close_button = 0;
    this->circle_p_pic = 0;
    this->background = 0;

    if (!TDialogPanel::setup(parent->renderArea(), parent, 0x208, 0x19c,
                             parent->get_popup_info_file(),
                             parent->get_popup_info_id(), modal))
        return;

    TEasy_Panel::create_text(this, &this->background, "", 10, 10, 500,
                             0x15e, 4, 0, 0, 0);

    this->background->set_bevel_info(3, this->bevel_color1,
                                     this->bevel_color2,
                                     this->bevel_color3,
                                     this->bevel_color4,
                                     this->bevel_color5,
                                     this->bevel_color6);

    TEasy_Panel::create_text(this, &this->title_text, 0x2419, 0x14, 0x14,
                             0x1e0, 0x14, 4, 0, 0, 0);
    TEasy_Panel::create_text(this, &this->version_text, 0x241a, 0x14, 0x28,
                             0x1e0, 0x14, 0xb, 0, 0, 0);

    TPanel::get_string(0x2424, temp_str, 0x200);
    if (temp_str[0] == '\0') {
        TEasy_Panel::create_text(this, &this->ms_copy_text1, 0x241b, 0x14,
                                 0x41, 0x1e0, 0x14, 10, 0, 0, 0);

        if (this->ms_copy_text1) {
            if (this->ms_copy_text1->get_text_rect(&rect)) {
                this->circle_p_pic = new TPicturePanel();
                if (this->circle_p_pic) {
                    this->circle_p_pic->setup(
                        this->render_area, this, (rect.right - this->pnl_x) + 3,
                        0x42, 0xf, 0xe, "circlep", 0xc4e0, 0, 1);
                    TEasy_Panel::create_text(
                        this, &this->ms_copy_text2, 0x241c,
                        this->circle_p_pic->xPosition() - this->pnl_x +
                            this->circle_p_pic->width(),
                        0x41, 0x1e0, 0x14, 10, 0, 0, 0);
                }
            }
        }
    } else {
        strcpy(temp_str, TPanel::get_string(0x241b));
        strcat(temp_str, TPanel::get_string(0x2424));
        strcat(temp_str, " ");
        strcat(temp_str, TPanel::get_string(0x241c));
        TEasy_Panel::create_text(this, &this->ms_copy_text1, temp_str, 0x14,
                                 0x41, 0x1e0, 0x14, 10, 0, 0, 0);
    }

    TEasy_Panel::create_text(this, &this->ens_copy_text, 0x241d, 0x14, 0x55,
                             0x1e0, 0x14, 10, 0, 0, 0);
    TEasy_Panel::create_text(this, &this->genie_copy_text, 0x2423, 0x14,
                             0x69, 0x1e0, 0x28, 10, 0, 0, 1);
    TEasy_Panel::create_text(this, &this->pid_label_text, 0x241e, 0x14,
                             0x96, 0x5f, 0x14, 10, 0, 0, 0);

    if (this->pid_label_text) {
        if (this->pid_label_text->get_text_rect(&rect)) {
            char* pid_str = Regs->RegGetAscii(0, "PID");
            if (!pid_str)
                pid_str = "00000-000-0000000-00000";
            sprintf(str, "%s", pid_str);
            TEasy_Panel::create_text(
                this, &this->pid_text, str,
                (rect.right - this->pnl_x) + 4, 0x96, 200, 0x14, 0xb, 0, 0,
                0);
        }
    }

    TPanel::get_string(0x241f, str, 0x1000);
    TEasy_Panel::create_text(this, &this->warning_text, str, 0x14, 0xaf,
                             0x1e0, 0xdc, 10, 0, 0, 1);

    TEasy_Panel::create_button(this, &this->credits_button, 0x2420, 0, 0x46,
                               0x172, 0xaa, 0x1e, 0, 0, 0);
    TEasy_Panel::create_button(this, &this->close_button, 0x2421, 0, 0x118,
                               0x172, 0xaa, 0x1e, 0, 0, 0);

    TButtonPanel* close_button = this->close_button;
    close_button->hotkey = 0x1b;
    close_button->hotkey_shift = 0;

    TPanel* tabs[2];
    tabs[0] = this->credits_button;
    tabs[1] = this->close_button;
    TPanel::set_tab_order(tabs, 2);
    TPanel::set_curr_child(this->credits_button);
}

// 0043B300 TribeAboutDialog::~TribeAboutDialog (dlg_abt.cpp:154-168)
TribeAboutDialog::~TribeAboutDialog()
{
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

// 0043B400 TribeAboutDialog::action (dlg_abt.cpp:174-200)
long TribeAboutDialog::action(TPanel* panel, long command,
                              unsigned long param_3, unsigned long param_4)
{
    if (command == 1) {
        if (panel == this->close_button) {
            TPanel* game_screen = panel_system.panel("Game Screen");
            if (game_screen) {
                if (rge_base_game->singlePlayerGame() == 1) {
                    if (!rge_base_game->save_paused)
                        rge_base_game->set_paused(0, 0);
                }
                panel_system.setCurrentPanel("Game Screen", 0);
                this->set_active(0);
            }
            panel_system.destroyPanel("About Dialog");
            return 1;
        }

        if (panel == this->credits_button) {
            TRIBE_Credits_Screen* credits = new TRIBE_Credits_Screen();
            panel_system.setCurrentPanel("Credits Screen", 0);
            panel_system.destroyPanel("About Dialog");
            return 1;
        }
    }

    return TEasy_Panel::action(panel, command, param_3, param_4);
}

// 0043B550 TribeAboutDialog::draw (dlg_abt.cpp:206)
void TribeAboutDialog::draw()
{
    TEasy_Panel::draw();
}
