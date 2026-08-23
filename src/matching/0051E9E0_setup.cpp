// 0051E9E0 Time_Line_Panel::setup (tpnl_tml.cpp:202-227)
// Attempt 3: fix TPanel.layout - render_area at +0x20
// BINARY NOTE: this owner uses the shared tpnl_tml.cpp timeline surface.

#include "../../include/tpnl_tml_context.h"

__declspec(dllimport) int __stdcall GetNearestPaletteIndex(void*, unsigned int);

long Time_Line_Panel::setup(
    TDrawArea* param_1,
    TPanel* param_2,
    long param_3,
    long param_4,
    long param_5,
    long param_6,
    void* param_7,
    long param_8,
    long param_9,
    void* param_10,
    long param_11,
    long param_12,
    char* param_13,
    char* param_14,
    int param_15,
    unsigned char param_16,
    int param_17,
    unsigned char param_18
)
{
    this->TPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, 0);

    this->fill_back = param_15;
    this->back_color = param_16;
    this->outline = param_17;
    this->outline_color = param_18;

    if (param_17) {
        this->bevel_type = 1;
    }

    this->set_axis_font(param_7, param_8, param_9);
    this->set_body_font(param_10, param_11, param_12);
    this->set_background(param_13);
    this->set_special_events(param_14);

    unsigned char pal_idx = (unsigned char)GetNearestPaletteIndex(
        *(void**)((*(char**)this->render_area) + 8), 0);
    this->set_back_color(1, pal_idx);

    return 1;
}
