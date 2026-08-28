// PDB source order: dlg_list.cpp lines 39-174.
// This file owns all six normal functions in the compiland.

#include "../include/dlg_list.h"

TListDialog::TListDialog(char* name)
    : TDialogPanel(name), title(0), list(0), scroll_bar(0), ok_btn(0),
      cancel_btn(0), list_id(-1), list_name(0)
{
}

TListDialog::~TListDialog()
{
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

long TListDialog::setup(TPanel* parent_panel, char* name, long x, long y,
                        long width, long title_x, long title_y,
                        long title_width, long title_height, char* title_text,
                        long list_x,
                        long list_y, long list_width, long list_height,
                        char** list_text, short list_count, short selected,
                        long ok_x, long cancel_x, long button_y, long button_width,
                        long button_height)
{
    int result = TDialogPanel::setup(parent_panel->renderArea(), parent_panel,
                                     y, width, name, x, 1);
    if (result == 0) {
        return 0;
    }

    if (title_text != 0 && *title_text != 0) {
        result = create_text((TPanel*)this, &title, title_text,
                             title_x, title_y, title_width, title_height,
                             4, 1, 1, 1);
        if (result == 0) {
            return 0;
        }
    }

    if (create_list((TPanel*)this, &list, list_x, list_y, list_width,
                    list_height, 0xB) == 0) {
        return 0;
    }

    result = create_auto_scrollbar(&scroll_bar, list, 0x14);
    if (result == 0) {
        return 0;
    }

    if (list_text != 0) {
        list->set_text(list_text, list_count);
    }

    list_id = (short)selected;
    list->scroll_cur_line(1, selected, 1);

    if (create_button((TPanel*)this, &ok_btn, 0xFA1, 0,
                      ok_x, button_y, button_width, button_height,
                      0, 0, 0) == 0) {
        return 0;
    }

    result = create_button((TPanel*)this, &cancel_btn, 0xFA2, 0,
                           cancel_x, button_y, button_width, button_height,
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

long TListDialog::setup(TPanel* parent_panel, char* name, long x, long y,
                        long width, long title_x, long title_y,
                        long title_width, long title_height, int title_id,
                        long list_x,
                        long list_y, long list_width, long list_height,
                        char** list_text, short list_count, short selected,
                        long ok_x, long cancel_x, long button_y, long button_width,
                        long button_height)
{
    char title_text[256];
    get_string(title_id, title_text, 0x100);
    return setup(parent_panel, name, x, y, width, title_x, title_y,
                 title_width, title_height, title_text, list_x, list_y, list_width,
                 list_height, list_text, list_count, selected, ok_x, cancel_x,
                 button_y, button_width, button_height);
}

long TListDialog::key_down_action(long, short, int, int, int)
{
    return 0;
}

long TListDialog::action(TPanel* panel, long message, unsigned long param_3,
                         unsigned long param_4)
{
    if (panel != 0) {
        if (panel == ok_btn) {
            if (message == 1) {
                list_id = (short)list->currentLineNumber();
                list_name = list->currentLine();
                if (parent_panel != 0) {
                    parent_panel->action(this, 1, 0, 0);
                }
                return 1;
            }
        }
        else if (panel == cancel_btn) {
            if (message == 1) {
                if (parent_panel != 0) {
                    parent_panel->action(this, 2, 0, 0);
                }
                return 1;
            }
        }
        else if (panel == list && message == 3) {
            list_id = (short)list->currentLineNumber();
            list_name = list->currentLine();
            if (parent_panel != 0) {
                parent_panel->action(this, 1, 0, 0);
            }
            return 1;
        }
    }
    return TEasy_Panel::action(panel, message, param_3, param_4);
}
