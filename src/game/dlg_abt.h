#pragma once
#include "../common.h"

class TribeAboutDialog : public TDialogPanel {
public:
    TTextPanel* title_text;                  // 0x490
    TTextPanel* version_text;                // 0x494
    TTextPanel* ms_copy_text1;               // 0x498
    TTextPanel* ms_copy_text2;               // 0x49C
    TTextPanel* ens_copy_text;               // 0x4A0
    TTextPanel* genie_copy_text;             // 0x4A4
    TTextPanel* pid_label_text;              // 0x4A8
    TTextPanel* pid_text;                    // 0x4AC
    TTextPanel* warning_text;                // 0x4B0
    TTextPanel* background;                  // 0x4B4
    TButtonPanel* credits_button;            // 0x4B8
    TButtonPanel* close_button;              // 0x4BC
    TPicturePanel* circle_p_pic;             // 0x4C0

    TribeAboutDialog(TScreenPanel* param_1);
    virtual ~TribeAboutDialog();
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4);
    virtual void draw();
};

static_assert(sizeof(TribeAboutDialog) == 0x4C4, "TribeAboutDialog Size Mismatch");
static_assert(offsetof(TribeAboutDialog, circle_p_pic) == 0x4C0, "TribeAboutDialog Offset Mismatch");

