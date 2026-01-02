#pragma once
#include "../common.h"

class TRIBE_Panel_Text_Line : public TPanel {
public:
    void* font;                              // 0xF4
    uchar text_type;                         // 0xF8
    char text[200];                          // 0xF9
    long id;                                 // 0x1C4

    TRIBE_Panel_Text_Line(TDrawArea* param_1, TPanel* param_2, void* param_3);
    virtual ~TRIBE_Panel_Text_Line();
    virtual void set_info(uchar param_1, char* param_2, long param_3);
    virtual void draw();
};

static_assert(sizeof(TRIBE_Panel_Text_Line) == 0x1C8, "TRIBE_Panel_Text_Line Size Mismatch");
static_assert(offsetof(TRIBE_Panel_Text_Line, id) == 0x1C4, "TRIBE_Panel_Text_Line Offset Mismatch");

