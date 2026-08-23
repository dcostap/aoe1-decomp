// 0051F120 Time_Line_Panel::draw_border (tpnl_tml.cpp:429-467)
// BINARY NOTE: this owner uses the shared TPanel and TDrawArea surfaces.
// The panel coordinate names map to the proven +0x0C..+0x18 homes.

#include "../../include/tpnl_tml_context.h"

void Time_Line_Panel::draw_border()
{
    if (this->bevel_type != 0) {
        if (this->render_area->Lock((char*)0x58b770, 1) != 0) {
            switch (this->bevel_type) {
            case 1:
                this->render_area->DrawRect(this->pnl_x, this->pnl_y, this->pnl_wid + this->pnl_x - 1, this->pnl_hgt + this->pnl_y - 1, this->outline_color);
                break;
            case 2:
                this->render_area->DrawBevel(this->pnl_x, this->pnl_y, this->pnl_wid + this->pnl_x - 1, this->pnl_hgt + this->pnl_y - 1, this->bevel_color6, this->bevel_color1);
                break;
            case 3:
                this->render_area->DrawBevel2(this->pnl_x, this->pnl_y, this->pnl_wid + this->pnl_x - 1, this->pnl_hgt + this->pnl_y - 1, this->bevel_color6, this->bevel_color5, this->bevel_color2, this->bevel_color1);
                break;
            case 4:
                this->render_area->DrawBevel3(this->pnl_x, this->pnl_y, this->pnl_wid + this->pnl_x - 1, this->pnl_hgt + this->pnl_y - 1, this->bevel_color6, this->bevel_color5, this->bevel_color4, this->bevel_color3, this->bevel_color2, this->bevel_color1);
                break;
            case 5:
                this->render_area->DrawBevel(this->pnl_x, this->pnl_y, this->pnl_wid + this->pnl_x - 1, this->pnl_hgt + this->pnl_y - 1, this->bevel_color1, this->bevel_color6);
                break;
            case 6:
                this->render_area->DrawBevel2(this->pnl_x, this->pnl_y, this->pnl_wid + this->pnl_x - 1, this->pnl_hgt + this->pnl_y - 1, this->bevel_color1, this->bevel_color2, this->bevel_color5, this->bevel_color6);
                break;
            case 7:
                this->render_area->DrawBevel3(this->pnl_x, this->pnl_y, this->pnl_wid + this->pnl_x - 1, this->pnl_hgt + this->pnl_y - 1, this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
                break;
            }
        }
        this->render_area->Unlock((char*)0x58b770);
    }
}
