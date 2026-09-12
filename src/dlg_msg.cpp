
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
    int button_count;
    long button_gap;
    long button_x;
    int i;

    button[0] = 0;
    button[1] = 0;
    button[2] = 0;

    if (!TDialogPanel::setup(parent->renderArea(), parent, x, y, panel_file,
                             panel_id, 1))
        return 0;

    dlg_type = type;
    if (!create_text(this, &text, message, 3, 3, pnl_wid - 3,
                     pnl_hgt - button_height - 6, 0x0B, 1, 1, 1))
        return 0;

    switch (dlg_type) {
    case 0:
        button_count = 1;
        break;
    case 1:
    case 2:
    case 3:
        button_count = 2;
        break;
    case 4:
        button_count = 3;
        break;
    default:
        return 0;
    }

    button_gap = pnl_wid - button_count * button_width;
    if (button_gap < 1)
        button_gap = 0;
    else
        button_gap /= button_count + 1;

    long button_y = pnl_hgt - button_height - 7;
    button_x = button_gap;
    for (i = 0; i < button_count; ++i) {
        if (!create_button(this, &button[i], s_592A40, s_592A40,
                           button_x, button_y, button_width, button_height,
                           0x0B, 0, 0))
            return 0;
        button_x += button_gap + button_width;
    }

    switch (dlg_type) {
    case 0:
        button[0]->set_text(0, 0x0FA1);
        break;
    case 1:
        button[0]->set_text(0, 0x0FA1);
        button[1]->set_text(0, 0x0FA2);
        button[1]->hotkey = 0x1B;
        button[1]->hotkey_shift = 0;
        break;
    case 2:
        button[0]->set_text(0, 0x0FA3);
        button[1]->set_text(0, 0x0FA4);
        button[1]->hotkey = 0x1B;
        button[1]->hotkey_shift = 0;
        break;
    case 3:
        button[0]->set_text(0, 0x0FA5);
        button[1]->set_text(0, 0x0FA7);
        button[1]->hotkey = 0x1B;
        button[1]->hotkey_shift = 0;
        break;
    case 4:
        button[0]->set_text(0, 0x0FA3);
        button[1]->set_text(0, 0x0FA4);
        button[2]->set_text(0, 0x0FA2);
        button[2]->hotkey = 0x1B;
        button[2]->hotkey_shift = 0;
        break;
    }

    set_tab_order(reinterpret_cast<TPanel**>(button),
                  static_cast<short>(button_count));
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
