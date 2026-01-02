#pragma once
#include "../common.h"

class THelpDialog : public TDialogPanel {
public:
    long help_page_id;                       // 0x490
    char parent_panel[256];                  // 0x494
    TTextPanel* title;                       // 0x594
    TTextPanel* list;                        // 0x598
    TButtonPanel* ok_button;                 // 0x59C
    TButtonPanel* encyclopedia_button;       // 0x5A0

    THelpDialog(TEasy_Panel* param_1, char* param_2, long param_3, long param_4, long param_5, long param_6);
    THelpDialog(TEasy_Panel* param_1, char* param_2, char* param_3, long param_4, long param_5, long param_6);
    virtual ~THelpDialog();
    virtual void setup_help(TEasy_Panel* param_1, char* param_2, char* param_3, long param_4, long param_5, long param_6);
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4);
    virtual long handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5);
};

static_assert(sizeof(THelpDialog) == 0x5A4, "THelpDialog Size Mismatch");
static_assert(offsetof(THelpDialog, encyclopedia_button) == 0x5A0, "THelpDialog Offset Mismatch");

