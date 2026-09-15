#ifndef AOE1_TPNL_TXL_H
#define AOE1_TPNL_TXL_H

// Declarations recovered for the original tpnl_txl.cpp translation unit.
// Reuse the canonical panel and draw-area ABI surfaces.

#include "panel.h"

class TRIBE_Panel_Text_Line : public TPanel {
public:
    void* font;
    unsigned char text_type;
    char text[200];
    char pad[3];
    long id;

    virtual void draw();
    void set_info(unsigned char text_type_in, char* text_in, long id_in);

    TRIBE_Panel_Text_Line(TDrawArea* render_area_in, TPanel* parent_panel_in, void* font_in);
};

typedef char tpnl_txl_line_size_check[
    (sizeof(TRIBE_Panel_Text_Line) == 0x1C8) ? 1 : -1];

#endif
