#pragma once
#include "../common.h"

class TDialogPanel : public TEasy_Panel {
public:
    void* dlg_wnd;                           // 0x478
    TPanel* save_parent_child;               // 0x47C
    int text_font_id;                        // 0x480
    int input_font_id;                       // 0x484
    int button_font_id;                      // 0x488
    int button_sound_id;                     // 0x48C

    TDialogPanel(char* param_1);
    virtual int setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, char* param_5, long param_6, int param_7);
    virtual int setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, uchar param_5, int param_6);
    virtual ~TDialogPanel();
    virtual void set_focus(int param_1);
};

static_assert(sizeof(TDialogPanel) == 0x490, "TDialogPanel Size Mismatch");
static_assert(offsetof(TDialogPanel, button_sound_id) == 0x48C, "TDialogPanel Offset Mismatch");

