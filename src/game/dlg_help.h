#pragma once
#include "common.h"

class THelpDialog : public TDialogPanel {
public:
    long help_page_id;                       // 0x490
    char parent_panel[256];                  // 0x494
    TTextPanel* title;                       // 0x594
    TTextPanel* list;                        // 0x598
    TButtonPanel* ok_button;                 // 0x59C
    TButtonPanel* encyclopedia_button;       // 0x5A0

    virtual long handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5); // vt0[28]+0x70=0x43EE10
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4); // vt0[45]+0xB4=0x43ED40
    THelpDialog(TEasy_Panel* param_1, char* param_2, long param_3, long param_4, long param_5, long param_6);
    THelpDialog(TEasy_Panel* param_1, char* param_2, char* param_3, long param_4, long param_5, long param_6);
    ~THelpDialog();
    void setup_help(TEasy_Panel* param_1, char* param_2, char* param_3, long param_4, long param_5, long param_6);
};

static_assert(sizeof(THelpDialog) == 0x5A4, "THelpDialog Size Mismatch");

