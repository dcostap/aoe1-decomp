#pragma once
#include "../common.h"

class TribeMenuDialog : public TDialogPanel {
public:
    TButtonPanel* button[11];                // 0x490

    TribeMenuDialog(TScreenPanel* param_1);
    virtual ~TribeMenuDialog();
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4);
};

static_assert(sizeof(TribeMenuDialog) == 0x4BC, "TribeMenuDialog Size Mismatch");
static_assert(offsetof(TribeMenuDialog, button) == 0x490, "TribeMenuDialog Offset Mismatch");

