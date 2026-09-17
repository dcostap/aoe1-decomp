
#include "../include/scr_game.h"
#include "../include/tvw_dmap.h"

TRIBE_Diamond_Map_View::TRIBE_Diamond_Map_View() : RGE_Diamond_Map_View() {
    this->last_attack_time = 0;
    this->flash_on = 0;
}

TRIBE_Diamond_Map_View::~TRIBE_Diamond_Map_View() {
}

void TRIBE_Diamond_Map_View::set_redraw(TPanel::RedrawMode redraw_mode) {
    RGE_Diamond_Map::set_redraw(redraw_mode);
    if (redraw_mode != TPanel::RedrawNone && this->visible != 0 &&
        this->active != 0) {
        static_cast<TRIBE_Screen_Game*>(this->parent_panel)
            ->set_map_buttons_redraw(redraw_mode);
    }
}

void TRIBE_Diamond_Map_View::draw_objects() {
    unsigned long now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\tvw_dmap.cpp", 64);
    if (0x14D <= now - this->last_attack_time) {
        this->flash_on = (this->flash_on == 0);
        this->last_attack_time = now;
    }
    RGE_Diamond_Map::draw_objects();
}

void TRIBE_Diamond_Map_View::draw_object(short col, short row, unsigned char color, short size, RGE_Static_Object* game_obj) {
    if (this->draw_objects_mode == 4) {
        if (this->flash_on) {
            color = 0x57 - 1;
        } else {
            color = 0 - 1;
        }
    }
    RGE_Diamond_Map::draw_object(col, row, color, size, game_obj);
}
