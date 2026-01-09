#pragma once
#include "common.h"

class TListDialog : public TDialogPanel {
public:
    TTextPanel* title;                       // 0x490
    TListPanel* list;                        // 0x494
    TScrollBarPanel* scroll_bar;             // 0x498
    TButtonPanel* ok_btn;                    // 0x49C
    TButtonPanel* cancel_btn;                // 0x4A0
    short list_id;                           // 0x4A4
    char* list_name;                         // 0x4A8

    virtual long key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5); // vt0[43]+0xAC=0x43F210
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4); // vt0[45]+0xB4=0x43F220
    virtual short get_list_id();                            // vt0[76]+0x130=0x43F320
    virtual char* get_list_name();                          // vt0[77]+0x134=0x43F330
    TListDialog(char* param_1);
    ~TListDialog();
    long setup(TPanel* param_1, char* param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, char* param_10, long param_11, long param_12, long param_13, long param_14, char** param_15, short param_16, short param_17, long param_18, long param_19, long param_20, long param_21, long param_22);
    long setup(TPanel* param_1, char* param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, int param_10, long param_11, long param_12, long param_13, long param_14, char** param_15, short param_16, short param_17, long param_18, long param_19, long param_20, long param_21, long param_22);
};

static_assert(sizeof(TListDialog) == 0x4AC, "TListDialog Size Mismatch");

