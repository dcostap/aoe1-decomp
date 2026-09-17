// This file owns all six normal functions in the compiland.

#include "../include/dlg_list.h"
#include "../include/resource_ids.h"

TListDialog::TListDialog(char* name)
    : TDialogPanel(name), title(0), list(0), scroll_bar(0), ok_btn(0),
      cancel_btn(0), list_id(-1), list_name(0) {
}

TListDialog::~TListDialog() {
    if (title != 0) {
        delete title;
    }
    if (list != 0) {
        delete list;
    }
    if (scroll_bar != 0) {
        delete scroll_bar;
    }
    if (ok_btn != 0) {
        delete ok_btn;
    }
    if (cancel_btn != 0) {
        delete cancel_btn;
    }
}

long TListDialog::setup(TPanel* parent_panel_in, char* info_file_in,
                        long info_id_in, long wid_in, long hgt_in,
                        long title_x_in, long title_y_in, long title_wid_in,
                        long title_hgt_in, char* title_in, long list_x_in,
                        long list_y_in, long list_wid_in, long list_hgt_in,
                        char** list_in, short list_num_lines_in, short list_id_in,
                        long ok_btn_x_in, long cancel_btn_x_in, long btn_y_in,
                        long btn_wid_in, long btn_hgt_in) {
    int result = TDialogPanel::setup(parent_panel_in->renderArea(), parent_panel_in,
                                     wid_in, hgt_in, info_file_in, info_id_in, 1);
    if (result == 0) {
        return 0;
    }

    if (title_in != 0 && *title_in != 0) {
        result = create_text((TPanel*)this, &title, title_in,
                             title_x_in, title_y_in, title_wid_in, title_hgt_in,
                             4, 1, 1, 1);
        if (result == 0) {
            return 0;
        }
    }

    if (create_list((TPanel*)this, &list, list_x_in, list_y_in, list_wid_in,
                    list_hgt_in, 0xB) == 0) {
        return 0;
    }

    result = create_auto_scrollbar(&scroll_bar, list, 0x14);
    if (result == 0) {
        return 0;
    }

    if (list_in != 0) {
        list->set_text(list_in, list_num_lines_in);
    }

    list_id = (short)list_id_in;
    list->scroll_cur_line(1, list_id_in, 1);

    if (create_button((TPanel*)this, &ok_btn, IDS_BUTTON_OK, 0,
                      ok_btn_x_in, btn_y_in, btn_wid_in, btn_hgt_in,
                      0, 0, 0) == 0) {
        return 0;
    }

    result = create_button((TPanel*)this, &cancel_btn, IDS_BUTTON_CANCEL, 0,
                           cancel_btn_x_in, btn_y_in, btn_wid_in, btn_hgt_in,
                           0, 0, 0);
    if (result == 0) {
        return 0;
    }

    TButtonPanel* cancel = cancel_btn;
    cancel->hotkey = 0x1B;
    cancel->hotkey_shift = 0;
    TPanel::set_curr_child(list);
    return 1;
}

long TListDialog::setup(TPanel* parent_panel_in, char* info_file_in,
                        long info_id_in, long wid_in, long hgt_in,
                        long title_x_in, long title_y_in, long title_wid_in,
                        long title_hgt_in, int title_string_id, long list_x_in,
                        long list_y_in, long list_wid_in, long list_hgt_in,
                        char** list_in, short list_num_lines_in, short list_id_in,
                        long ok_btn_x_in, long cancel_btn_x_in, long btn_y_in,
                        long btn_wid_in, long btn_hgt_in) {
    char str[256];
    get_string(title_string_id, str, 256);
    return setup(parent_panel_in, info_file_in, info_id_in, wid_in, hgt_in,
                 title_x_in, title_y_in, title_wid_in, title_hgt_in, str,
                 list_x_in, list_y_in, list_wid_in, list_hgt_in, list_in,
                 list_num_lines_in, list_id_in, ok_btn_x_in, cancel_btn_x_in,
                 btn_y_in, btn_wid_in, btn_hgt_in);
}

long TListDialog::key_down_action(long key, short count, int alt_key, int ctrl_key,
                                  int shift_key) {
    return 0;
}

long TListDialog::action(TPanel* from_panel, long action_in,
                         unsigned long action_val1, unsigned long action_val2) {
    if (from_panel != 0) {
        if (from_panel == ok_btn) {
            if (action_in == 1) {
                list_id = (short)list->currentLineNumber();
                list_name = list->currentLine();
                if (parent_panel != 0) {
                    parent_panel->action(this, 1, 0, 0);
                }
                return 1;
            }
        } else if (from_panel == cancel_btn) {
            if (action_in == 1) {
                if (parent_panel != 0) {
                    parent_panel->action(this, 2, 0, 0);
                }
                return 1;
            }
        } else if (from_panel == list && action_in == 3) {
            list_id = (short)list->currentLineNumber();
            list_name = list->currentLine();
            if (parent_panel != 0) {
                parent_panel->action(this, 1, 0, 0);
            }
            return 1;
        }
    }
    return TEasy_Panel::action(from_panel, action_in, action_val1, action_val2);
}
