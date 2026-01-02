#pragma once
#include "../common.h"

class TRIBE_Panel_Button : public TButtonPanel {
public:
    int display_garrison;                    // 0x2B8
    int garrsion_number;                     // 0x2BC
    uchar tribe_button_type;                 // 0x2C0
    TShape* border_pic;                      // 0x2C4
    uchar* color_table;                      // 0x2C8
    int border_frame;                        // 0x2CC
    char text_msg[256];                      // 0x2D0
    int in_use;                              // 0x3D0

    TRIBE_Panel_Button(TDrawArea* param_1, TPanel* param_2, TDigital* param_3, void* param_4, long param_5, long param_6, TShape* param_7);
    virtual ~TRIBE_Panel_Button();
    virtual void set_text_msg(char* param_1);
    virtual int is_inside(long param_1, long param_2);
    virtual void draw();
    virtual void set_display_garrison(int param_1);
    virtual void set_garrison_number(int param_1);
    virtual int get_garrison_number();
};

static_assert(sizeof(TRIBE_Panel_Button) == 0x3D4, "TRIBE_Panel_Button Size Mismatch");
static_assert(offsetof(TRIBE_Panel_Button, in_use) == 0x3D0, "TRIBE_Panel_Button Offset Mismatch");

