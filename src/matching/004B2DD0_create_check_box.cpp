// VA: 004B2DD0 TRIBE_Screen_Sed::create_check_box
// try 1: natural C++ methods instead of raw __fastcall wrappers.

#include "../../include/scr_sed2_context.h"

int TRIBE_Screen_Sed::create_check_box(TPanel* parent, TButtonPanel** out)
{
    int ok = TEasy_Panel::create_check_box(parent, out, 0, 0, 0, 0, 1, 0);
    if (!ok) return 0;
    (*out)->set_z_order(1, 0);
    (*out)->set_active(0);
    if (this->use_bevels) {
        (*out)->set_bevel_info(3, this->bevel_color1, this->bevel_color2,
                              this->bevel_color3, this->bevel_color4,
                              this->bevel_color5, this->bevel_color6);
    }
    return 1;
}
