// PDB: TEditPanel::set_text_color(unsigned long, unsigned long), pnl_edit.cpp:437-441.
#ifndef PNL_EDIT_TU_CONTEXT
#include "../pnl_edit_tu_context.h"
#endif

void TEditPanel::set_text_color(unsigned long a, unsigned long b) {
    text_color1 = a;
    text_color2 = b;
    set_redraw(TPanel::RedrawNormal);
}
