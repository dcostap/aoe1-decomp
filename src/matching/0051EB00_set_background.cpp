// 0051EB00 Time_Line_Panel::set_background (tpnl_tml.cpp:248-268)
// BINARY NOTE: this owner uses the shared tpnl_tml.cpp timeline and TShape surfaces.

#include "../../include/tpnl_tml_context.h"
#include <new.h>

int Time_Line_Panel::set_background(char* name) {
    long x_max;
    long x_min;
    long y_max;
    long y_min;

    if (this->background_pic != 0) {
        delete this->background_pic;
        this->background_pic = 0;
        this->background_pic_wid = 0;
        this->background_pic_hgt = 0;
    }

    if (name == 0 || *name == '\0') {
        return 0;
    }

    this->background_pic = new TShape(name, -1);
    this->background_pic->shape_minmax(&x_max, &x_min, &y_max, &y_min, (long)0);
    this->background_pic_wid = (short)(y_max - x_max + 1);
    this->background_pic_hgt = (short)(y_min - x_min + 1);
    return 1;
}
