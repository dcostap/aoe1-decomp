#include "../../include/tvw_dmap_context.h"

void TRIBE_Diamond_Map_View::set_redraw(TPanel::RedrawMode mode) {
    RGE_Diamond_Map::set_redraw(mode);
    if (mode != 0 && this->field_70 != 0 && this->field_6C != 0) {
        this->screen_game->set_map_buttons_redraw(mode);
    }
}
