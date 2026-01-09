#pragma once
#include "common.h"

class TribeMenuDialog : public TDialogPanel {
public:
    TButtonPanel* button[11];                // 0x490

    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4); // vt0[45]+0xB4=0x43F720
    TribeMenuDialog(TScreenPanel* param_1);
    ~TribeMenuDialog();
};

static_assert(sizeof(TribeMenuDialog) == 0x4BC, "TribeMenuDialog Size Mismatch");

