#pragma once
#include "../common.h"

class TListDialog : public TDialogPanel {
public:
    TTextPanel* title;                       // 0x490
    TListPanel* list;                        // 0x494
    TScrollBarPanel* scroll_bar;             // 0x498
    TButtonPanel* ok_btn;                    // 0x49C
    TButtonPanel* cancel_btn;                // 0x4A0
    short list_id;                           // 0x4A4
    char* list_name;                         // 0x4A8

    TListDialog(char* param_1);
    virtual ~TListDialog();
    virtual long setup(TPanel* param_1, char* param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, char* param_10, long param_11, long param_12, long param_13, long param_14, char** param_15, short param_16, short param_17, long param_18, long param_19, long param_20, long param_21, long param_22);
    virtual long setup(TPanel* param_1, char* param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, int param_10, long param_11, long param_12, long param_13, long param_14, char** param_15, short param_16, short param_17, long param_18, long param_19, long param_20, long param_21, long param_22);
    virtual long key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5);
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4);
    virtual short get_list_id();
    virtual char* get_list_name();
};

static_assert(sizeof(TListDialog) == 0x4AC, "TListDialog Size Mismatch");
static_assert(offsetof(TListDialog, list_name) == 0x4A8, "TListDialog Offset Mismatch");

short TListDialog::get_list_id() {
    /* TODO: Stub */
//                              short __thiscall get_list_id(TListDialog * this)
//              short             AX:2           <RETURN>
//              TListDialog *     ECX:4 (auto)   this
//                               ?get_list_id@TListDialog@@UAEFXZ                             XREF[1]:     0056fc28(*)
//                               TListDialog::get_list_id
//                              dlg_list.h:42 (8)
//         0043f320     MOV        AX,word ptr [ECX + this->list_id]
//         0043f327     RET
//         0043f328     ??         90h
//         0043f329     NOP
//         0043f32a     NOP
//         0043f32b     NOP
//         0043f32c     NOP
//         0043f32d     NOP
//         0043f32e     NOP
//         0043f32f     NOP
    return 0;
}

char* TListDialog::get_list_name() {
    /* TODO: Stub */
//                              char * __thiscall get_list_name(TListDialog * this)
//              char *            EAX:4          <RETURN>
//              TListDialog *     ECX:4 (auto)   this
//                               ?get_list_name@TListDialog@@UAEPADXZ                         XREF[3]:     0056fc2c(*), 00571e24(*),
//                               TListDialog::get_list_name                                                005766b4(*)
//                              dlg_list.h:43 (7)
//         0043f330     MOV        EAX,dword ptr [ECX + this->list_name]
//         0043f336     RET
//         0043f337     ??         90h
//         0043f338     NOP
//         0043f339     NOP
//         0043f33a     NOP
//         0043f33b     NOP
//         0043f33c     NOP
//         0043f33d     NOP
//         0043f33e     NOP
//         0043f33f     NOP
    return 0;
}

