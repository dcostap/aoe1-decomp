#pragma once
#include "../common.h"

enum Action : unsigned int {
    OK = 0,
    Cancel = 1,
    Other = 2,
};

enum Type : unsigned int {
    OKDialog = 0,
    OKCancelDialog = 1,
    YesNoDialog = 2,
    RetryAbortDialog = 3,
    YesNoCancelDialog = 4,
};

class TMessageDialog : public TDialogPanel {
public:
    uchar dlg_type;                          // 0x490
    TTextPanel* text;                        // 0x494
    TButtonPanel* button[3];                 // 0x498

    TMessageDialog(char* param_1);
    virtual ~TMessageDialog();
    virtual long setup(TPanel* param_1, char* param_2, long param_3, long param_4, long param_5, uchar param_6, char* param_7, long param_8, long param_9);
    virtual long setup(TPanel* param_1, char* param_2, long param_3, long param_4, long param_5, uchar param_6, int param_7, long param_8, long param_9);
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4);
    virtual long key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5);
    virtual long handle_idle();
};

static_assert(sizeof(TMessageDialog) == 0x4A4, "TMessageDialog Size Mismatch");
static_assert(offsetof(TMessageDialog, button) == 0x498, "TMessageDialog Offset Mismatch");

