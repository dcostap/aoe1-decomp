#pragma once
#include "../common.h"

class TRIBE_Panel_Inven : public TPanel {
public:
    TShape* pics;                            // 0xF4
    TRIBE_Player* player;                    // 0xF8
    short save_attr_num;                     // 0xFC
    short* save_attr;                        // 0x100
    ulong idle_time;                         // 0x104
    ulong idle_interval;                     // 0x108
    void* font;                              // 0x10C
    ulong font_color;                        // 0x110
    ulong back_color;                        // 0x114

    TRIBE_Panel_Inven(TDrawArea* param_1, TPanel* param_2, void* param_3, TRIBE_Player* param_4);
    virtual void set_text_color(ulong param_1, ulong param_2);
    virtual ~TRIBE_Panel_Inven();
    virtual void draw();
    virtual long handle_idle();
    virtual void set_player(TRIBE_Player* param_1);
    virtual void save_info();
    virtual uchar get_help_info(char** param_1, long* param_2, long param_3, long param_4);
};

static_assert(sizeof(TRIBE_Panel_Inven) == 0x118, "TRIBE_Panel_Inven Size Mismatch");
static_assert(offsetof(TRIBE_Panel_Inven, back_color) == 0x114, "TRIBE_Panel_Inven Offset Mismatch");

