#pragma once
#include "common.h"

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

    virtual void draw();                                    // vt0[12]+0x30=0x51A770
    virtual long handle_idle();                             // vt0[19]+0x4C=0x51AAD0
    virtual uchar get_help_info(char** param_1, long* param_2, long param_3, long param_4); // vt0[51]+0xCC=0x51ACA0
    TRIBE_Panel_Inven(TDrawArea* param_1, TPanel* param_2, void* param_3, TRIBE_Player* param_4);
    void set_text_color(ulong param_1, ulong param_2);
    ~TRIBE_Panel_Inven();
    void set_player(TRIBE_Player* param_1);
    void save_info();
};

static_assert(sizeof(TRIBE_Panel_Inven) == 0x118, "TRIBE_Panel_Inven Size Mismatch");

