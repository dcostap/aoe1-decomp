
#include "../include/dlg_msg.h"
#include "../include/resource_ids.h"
#include "../include/basegame.h"
#include "../include/rge_base_game_global.h"

extern char s_592A40[];

TMessageDialog::TMessageDialog(char* name)
    : TDialogPanel(name), dlg_type(0), text(0) {
    for (int i = 0; i < 3; ++i) {
        button[i] = 0;
    }
}

TMessageDialog::~TMessageDialog() {
    if (text != 0) {
        delete text;
    }
    for (int i = 0; i < 3; i++) {
        if (button[i] != 0) {
            delete button[i];
        }
    }
}

long TMessageDialog::setup(TPanel* parent_panel_in, char* info_file_in,
                           long info_id_in, long wid_in, long hgt_in,
                           unsigned char dlg_type_in, char* text_in,
                           long btn_wid_in, long btn_hgt_in) {
    int button_num;
    long space;
    long button_x;
    int index;

    button[0] = 0;
    button[1] = 0;
    button[2] = 0;

    if (!TDialogPanel::setup(parent_panel_in->renderArea(), parent_panel_in,
                             wid_in, hgt_in, info_file_in, info_id_in, 1))
        return 0;

    dlg_type = dlg_type_in;
    if (!create_text(this, &text, text_in, 3, 3, pnl_wid - 3,
                     pnl_hgt - btn_hgt_in - 6, 0x0B, 1, 1, 1))
        return 0;

    switch (dlg_type) {
    case 0:
        button_num = 1;
        break;
    case 1:
    case 2:
    case 3:
        button_num = 2;
        break;
    case 4:
        button_num = 3;
        break;
    default:
        return 0;
    }

    space = pnl_wid - button_num * btn_wid_in;
    if (space < 1)
        space = 0;
    else
        space /= button_num + 1;

    long y = pnl_hgt - btn_hgt_in - 7;
    button_x = space;
    for (index = 0; index < button_num; ++index) {
        if (!create_button(this, &button[index], s_592A40, s_592A40,
                           button_x, y, btn_wid_in, btn_hgt_in,
                           0x0B, 0, 0))
            return 0;
        button_x += space + btn_wid_in;
    }

    switch (dlg_type) {
    case 0:
        button[0]->set_text(0, IDS_BUTTON_OK);
        break;
    case 1:
        button[0]->set_text(0, IDS_BUTTON_OK);
        button[1]->set_text(0, IDS_BUTTON_CANCEL);
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
        button[2]->set_text(0, IDS_BUTTON_CANCEL);
        button[2]->hotkey = 0x1B;
        button[2]->hotkey_shift = 0;
        break;
    }

    set_tab_order(reinterpret_cast<TPanel**>(button),
                  static_cast<short>(button_num));
    set_curr_child(button[0]);
    return 1;
}

long TMessageDialog::setup(TPanel* parent_panel_in, char* info_file_in,
                           long info_id_in, long wid_in, long hgt_in,
                           unsigned char dlg_type_in, int text_id,
                           long btn_wid_in, long btn_hgt_in) {
    char str[256];

    get_string(text_id, str, 0x100);
    return setup(parent_panel_in, info_file_in, info_id_in, wid_in, hgt_in,
                 dlg_type_in, str, btn_wid_in, btn_hgt_in);
}

long TMessageDialog::action(TPanel* from_panel, long action_in,
                            unsigned long action_val1,
                            unsigned long action_val2) {
    if (parent_panel != 0 && action_in == 1) {
        if (from_panel == button[0]) {
            parent_panel->action(this, 0, 0, 0);
            return action_in;
        }
        if (from_panel == button[1]) {
            parent_panel->action(this, 1, 0, 0);
            return 1;
        }
        if (from_panel == button[2]) {
            parent_panel->action(this, 2, 0, 0);
            return 1;
        }
    }
    return TEasy_Panel::action(from_panel, action_in, action_val1, action_val2);
}

long TMessageDialog::key_down_action(long key, short count, int alt_key,
                                     int ctrl_key, int shift_key) {
    return 0;
}

long TMessageDialog::handle_idle() {
    if (!rge_base_game->input_enabled) {
        rge_base_game->enable_input();
    }
    return TPanel::handle_idle();
}
