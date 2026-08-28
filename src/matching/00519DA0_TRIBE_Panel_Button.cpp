// 00519DA0 TRIBE_Panel_Button::TRIBE_Panel_Button
// Source: tpnl_btn.cpp lines 50-68
// Size: 206 bytes, EH-framed
// FLAGS: /GX
//
// Exact match probe 3:
//   Key fix: remove `long result` local variable for setup() return value.
//   VC5 allocated ebx as zero carrier when result local existed (extra push ebx/pop ebx).
//   Using `if (setup(...) == 0)` directly tests eax after call, matching original's
//   `test eax, eax; jne` pattern perfectly.
//   0.0000% diff, 11 relocations masked.

#ifndef TPNL_BTN_SHARED_CONTEXT
class TDrawArea {};
class TDigital {};
class TShape {
public:
    char _gap_00[0x04];
    virtual ~TShape();
};

class TPanel {
public:
    char _gap_00[0xF0];
    virtual ~TPanel();
};

class TButtonPanel : public TPanel {
public:
    char _gap_F4[0x1C4];

    virtual ~TButtonPanel();

    TButtonPanel();
    long setup(TDrawArea* param1, TPanel* param2, int a, int b, int c, int d,
               int drawClear, TDigital* sound, int notifyAction, int buttonId);
    void set_font(void* font, long p5, long p6);
};

class TRIBE_Panel_Button : public TButtonPanel {
public:
    int display_garrison;
    int garrsion_number;
    unsigned char tribe_button_type;
    char _pad_2C1[0x03];
    TShape* border_pic;
    unsigned char* color_table;
    int border_frame;
    char text_msg[256];
    int in_use;

    virtual ~TRIBE_Panel_Button();

    TRIBE_Panel_Button(TDrawArea* param1, TPanel* param2, TDigital* param3,
                       void* param4, long param5, long param6, TShape* param7);
};
#else
#include "../../include/tpnl_btn_context.h"
#endif

TRIBE_Panel_Button::TRIBE_Panel_Button(
    TDrawArea* param1, TPanel* param2, TDigital* param3,
    void* param4, long param5, long param6, TShape* param7)
{
    tribe_button_type = 0;
    color_table = 0;
    border_frame = 0;
    text_msg[0] = 0;
    in_use = 0;
    display_garrison = 0;
    garrsion_number = 0;

    border_pic = param7;

    if (setup(param1, param2, 0, 0, 0, 0, 1, param3, 1, -1) == 0) {
        *(int*)((char*)this + 0xD8) = 1;
    } else {
        set_font(param4, param5, param6);
    }
}
