
#include "../include/dlg_msg.h"
#include "../include/basegame.h"
#include "../include/rge_base_game_global.h"

extern char s_592A40[];

TMessageDialog::TMessageDialog(char* name)
    : TDialogPanel(name), dlg_type(0), text(0)
{
    for (int i = 0; i < 3; ++i) {
        button[i] = 0;
    }
}

TMessageDialog::~TMessageDialog()
{
    if (text != 0) {
        delete text;
    }
    for (int i = 0; i < 3; i++) {
        if (button[i] != 0) {
            delete button[i];
        }
    }
}

long TMessageDialog::setup(TPanel* parent, char* panel_file, long panel_id,
                           long x, long y, unsigned char type, char* message,
                           long button_width, long button_height)
{
    TDrawArea* draw_area;
    int num_buttons;
    int space;
    int button_y;
    TButtonPanel** next_button;
    int button_x;
    int i;
    TButtonPanel* hotkey_button;

    button[0] = button[1] = button[2] = 0;
    draw_area = parent->renderArea();
    if (TDialogPanel::setup(draw_area, parent, x, y, panel_file, panel_id, 1) == 0) {
        return 0;
    }

    dlg_type = type;
    if (create_text(this, &text, message, 3, 3,
                    pnl_wid - 3, pnl_hgt - button_height - 6,
                    0x0B, 1, 1, 1) == 0) {
        return 0;
    }

    switch (dlg_type) {
    case 0:
        num_buttons = 1;
        break;
    case 4:
        num_buttons = 3;
        break;
    case 1:
    case 2:
    case 3:
        num_buttons = 2;
        break;
    default:
        return 0;
    }

    space = pnl_wid - num_buttons * button_width;
    if (space < 1) {
        space = 0;
    } else {
        space /= num_buttons + 1;
    }

    button_y = pnl_hgt - button_height - 7;
    next_button = button;
    button_x = space;
    for (i = 0; i < num_buttons; ++i) {
        if (create_button(this, next_button, s_592A40, s_592A40,
                          button_x, button_y, button_width, button_height,
                          0x0B, 0, 0) == 0) {
            return 0;
        }
        button_x += space + button_width;
        ++next_button;
    }

    switch (dlg_type) {
    case 0:
        button[0]->set_text(0, 0xFA1);
        goto set_tab_order;
    case 1:
        button[0]->set_text(0, 0xFA1);
        button[1]->set_text(0, 0xFA2);
        hotkey_button = button[1];
        goto set_hotkey;
    case 2:
        button[0]->set_text(0, 0xFA3);
        button[1]->set_text(0, 0xFA4);
        hotkey_button = button[1];
        goto set_hotkey;
    case 4:
        button[0]->set_text(0, 0xFA3);
        button[1]->set_text(0, 0xFA4);
        button[2]->set_text(0, 0xFA2);
        hotkey_button = button[2];
        goto set_hotkey;
    case 3:
        button[0]->set_text(0, 0xFA5);
        button[1]->set_text(0, 0xFA7);
        hotkey_button = button[1];
        goto set_hotkey;
    default:
        goto set_tab_order;
    }

set_hotkey:
    hotkey_button->hotkey = 0x1B;
    hotkey_button->hotkey_shift = 0;
set_tab_order:
    set_tab_order((TPanel**)button, num_buttons);
    set_curr_child(button[0]);
    return 1;
}

long TMessageDialog::setup(TPanel* parent, char* panel_file, long panel_id,
                           long x, long y, unsigned char type, int message_id,
                           long button_width, long button_height)
{
    char message[256];

    get_string(message_id, message, 0x100);
    return setup(parent, panel_file, panel_id, x, y, type, message,
                 button_width, button_height);
}

long TMessageDialog::action(TPanel* panel, long action_id,
                            unsigned long param_3, unsigned long param_4)
{
    if (parent_panel != 0 && action_id == 1) {
        if (panel == button[0]) {
            parent_panel->action(this, 0, 0, 0);
            return action_id;
        }
        if (panel == button[1]) {
            parent_panel->action(this, 1, 0, 0);
            return 1;
        }
        if (panel == button[2]) {
            parent_panel->action(this, 2, 0, 0);
            return 1;
        }
    }
    return TEasy_Panel::action(panel, action_id, param_3, param_4);
}

long TMessageDialog::key_down_action(long, short, int, int, int)
{
    return 0;
}

long TMessageDialog::handle_idle()
{
    if (!rge_base_game->input_enabled) {
        rge_base_game->enable_input();
    }
    return TPanel::handle_idle();
}
