#pragma once

#include "TButtonPanel.h"

class TRIBE_Panel_Button : public TButtonPanel {
public:
    TRIBE_Panel_Button();
    TRIBE_Panel_Button(
        TDrawArea* area,
        TPanel* parent,
        TDigital* sound,
        void* font,
        long font_wid,
        long font_hgt,
        TShape* border_pic);
    virtual ~TRIBE_Panel_Button();

    void set_text_msg(char* text);

    int display_garrison;
    int garrsion_number;
    unsigned char tribe_button_type;
    TShape* border_pic;
    unsigned char* color_table;
    int border_frame;
    char text_msg[256];
    int in_use;
};

static_assert(sizeof(TRIBE_Panel_Button) == 0x3D4, "Size mismatch");
