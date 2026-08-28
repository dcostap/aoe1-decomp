#include "../../include/tvw_dmap_context.h"

void TRIBE_Diamond_Map_View::set_redraw(TPanel::RedrawMode mode) {
    RGE_Diamond_Map::set_redraw(mode);
    if (mode != 0 && this->visible != 0 && this->active != 0) {
        static_cast<TRIBE_Screen_Game*>(this->parent_panel)
            ->set_map_buttons_redraw(mode);
    }
}
