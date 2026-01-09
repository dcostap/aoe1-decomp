#pragma once
#include "common.h"

class TRIBE_Mission_Screen : public TScreenPanel {
public:
    TTextPanel* title;                       // 0x478
    TTextPanel* list;                        // 0x47C
    TScrollBarPanel* scroll_bar;             // 0x480
    TButtonPanel* ok_button;                 // 0x484
    TButtonPanel* text_buttons[3];           // 0x488
    uchar game_flag;                         // 0x494
    TPicture* vc_back_bmp;                   // 0x498

    virtual void draw();                                    // vt0[12]+0x30=0x4B88E0
    virtual long handle_idle();                             // vt0[19]+0x4C=0x4B88B0
    virtual long key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5); // vt0[43]+0xAC=0x4B8AE0
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4); // vt0[45]+0xB4=0x4B89A0
    TRIBE_Mission_Screen(char* param_1, uchar param_2, TPicture* param_3);
    ~TRIBE_Mission_Screen();
};

static_assert(sizeof(TRIBE_Mission_Screen) == 0x49C, "TRIBE_Mission_Screen Size Mismatch");

