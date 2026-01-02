#pragma once
#include "../common.h"

class TRIBE_Mission_Screen : public TScreenPanel {
public:
    TTextPanel* title;                       // 0x478
    TTextPanel* list;                        // 0x47C
    TScrollBarPanel* scroll_bar;             // 0x480
    TButtonPanel* ok_button;                 // 0x484
    TButtonPanel* text_buttons[3];           // 0x488
    uchar game_flag;                         // 0x494
    TPicture* vc_back_bmp;                   // 0x498

    TRIBE_Mission_Screen(char* param_1, uchar param_2, TPicture* param_3);
    virtual ~TRIBE_Mission_Screen();
    virtual long handle_idle();
    virtual void draw();
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4);
    virtual long key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5);
};

static_assert(sizeof(TRIBE_Mission_Screen) == 0x49C, "TRIBE_Mission_Screen Size Mismatch");
static_assert(offsetof(TRIBE_Mission_Screen, vc_back_bmp) == 0x498, "TRIBE_Mission_Screen Offset Mismatch");

