// VA: 004B2E60 TRIBE_Screen_Sed::create_radio_button
// PDB: scr_sed2.cpp lines 2313-2324 (143 bytes, 55 asm lines)
// MATCH: `python tools/check_function.py --va 004B2E60` -> 0.0000%.
// The inherited TEasy_Panel::create_radio_button call preserves the original
// PDB-qualified direct target. The earlier TRIBE helper name changed four bytes.

#include "../../include/scr_sed2_context.h"

int TRIBE_Screen_Sed::create_radio_button(TPanel* parent, TButtonPanel** out)
{
    if (!TEasy_Panel::create_radio_button(parent, out, 0, 0, 0, 0, 1, 0))
        return 0;

    (*out)->set_z_order(1, 0);
    (*out)->set_active(0);

    if (this->use_bevels) {
        (*out)->set_bevel_info(3, this->bevel_color1, this->bevel_color2,
                              this->bevel_color3, this->bevel_color4,
                              this->bevel_color5, this->bevel_color6);
    }

    return 1;
}
