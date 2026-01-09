#pragma once
#include "common.h"

class TDialogPanel : public TEasy_Panel {
public:
    void* dlg_wnd;                           // 0x478
    TPanel* save_parent_child;               // 0x47C
    int text_font_id;                        // 0x480
    int input_font_id;                       // 0x484
    int button_font_id;                      // 0x488
    int button_sound_id;                     // 0x48C

    virtual void set_focus(int param_1);                    // vt0[48]+0xC0=0x473EC0
    virtual int setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, uchar param_5, int param_6); // vt0[74]+0x128=0x473D60
    virtual int setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, char* param_5, long param_6, int param_7); // vt0[75]+0x12C=0x473C80
    TDialogPanel(char* param_1);
    ~TDialogPanel();
};

static_assert(sizeof(TDialogPanel) == 0x490, "TDialogPanel Size Mismatch");

