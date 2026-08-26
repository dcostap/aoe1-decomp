// TRIBE_Panel_Inven::set_text_color
// PDB: tpnl_inv.cpp:67-71

#include "../../include/tpnl_inv_context.h"

void TRIBE_Panel_Inven::set_text_color(unsigned long color1,
                                       unsigned long color2) {
    this->font_color = color1;
    this->back_color = color2;
    this->set_redraw(1);
}
