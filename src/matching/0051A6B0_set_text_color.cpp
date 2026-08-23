// TRIBE_Panel_Inven::set_text_color
// PDB: tpnl_inv.cpp:67-71

#ifndef TPNL_INV_SHARED_CONTEXT
class TRIBE_Panel_Inven {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20(int mode);
    char gap_04[0x10A];
    unsigned long font_color;
    unsigned long back_color;

    void set_text_color(unsigned long color1, unsigned long color2);
};
#else
#include "../../include/tpnl_inv_context.h"
#endif

void TRIBE_Panel_Inven::set_text_color(unsigned long color1,
                                       unsigned long color2) {
    this->font_color = color1;
    this->back_color = color2;
#ifdef TPNL_INV_SHARED_CONTEXT
    this->set_redraw(1);
#else
    vf20(1);
#endif
}
