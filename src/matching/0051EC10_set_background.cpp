// 0051EC10 Time_Line_Panel::set_background (tpnl_tml.cpp:275-314)
// BINARY NOTE: this owner uses the shared tpnl_tml.cpp timeline and TShape surfaces.

#include "../../include/tpnl_tml_context.h"
#include <stdio.h>
#include <string.h>
#include <new.h>

extern "C" int __cdecl stricmp(const char* a, const char* b);

#define STR_NONE ((char*)0x00584D54)
#define STR_S_SHP ((char*)0x00584EAC)
#define STR_S ((char*)0x0057F324)
#define STR_EMPTY ((char*)0x00592A40)

int Time_Line_Panel::set_background(char* name, long id)
{
    long y_max;
    long y_min;
    long x_min;
    long x_max;
    char file_name2[260];

    if (this->background_pic != 0) {
        delete this->background_pic;
        this->background_pic = 0;
        this->background_pic_wid = 0;
        this->background_pic_hgt = 0;
    }

    if (name != 0 && *name != 0 && stricmp(name, STR_NONE) != 0) {
        if (strchr(name, '.') == 0) {
            sprintf(file_name2, STR_S_SHP, name);
        } else {
            sprintf(file_name2, STR_S, name);
        }
        this->background_pic = new TShape(file_name2, id);
    } else if (id != -1) {
        this->background_pic = new TShape(STR_EMPTY, id);
    }

    if (this->background_pic != 0 && this->background_pic->is_loaded() == 0) {
        delete this->background_pic;
        this->background_pic = 0;
    }

    if (this->background_pic != 0) {
        this->background_pic->shape_minmax(&x_max, &x_min, &y_max, &y_min, (long)0);
        this->background_pic_wid = (short)(y_max - x_max + 1);
        this->background_pic_hgt = (short)(y_min - x_min + 1);
        return 1;
    }
    return 0;
}
