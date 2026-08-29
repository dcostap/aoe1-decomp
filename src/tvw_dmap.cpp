// The scalar deleting destructor between the constructor and destructor is
// compiler generated.

#include "../include/scr_game.h"
#include "../include/tvw_dmap.h"

TRIBE_Diamond_Map_View::TRIBE_Diamond_Map_View()
    : RGE_Diamond_Map_View()
{
    this->last_attack_time = 0;
    this->flash_on = 0;
}

TRIBE_Diamond_Map_View::~TRIBE_Diamond_Map_View()
{
}

void TRIBE_Diamond_Map_View::set_redraw(TPanel::RedrawMode mode)
{
    RGE_Diamond_Map::set_redraw(mode);
    if (mode != TPanel::RedrawNone && this->visible != 0 &&
        this->active != 0) {
        static_cast<TRIBE_Screen_Game*>(this->parent_panel)
            ->set_map_buttons_redraw(mode);
    }
}

void TRIBE_Diamond_Map_View::draw_objects()
{
    unsigned long now = debug_timeGetTime(
        "C:\\msdev\\work\\age1_x1\\tvw_dmap.cpp", 0x40);
    if (0x14D <= now - this->last_attack_time) {
        this->flash_on = (this->flash_on == 0);
        this->last_attack_time = now;
    }
    RGE_Diamond_Map::draw_objects();
}

void TRIBE_Diamond_Map_View::draw_object(
    short param_1, short param_2, unsigned char param_3, short param_4,
    RGE_Static_Object* param_5)
{
    if (this->draw_objects_mode == 4) {
        if (this->flash_on) {
            param_3 = 0x57 - 1;
        } else {
            param_3 = 0 - 1;
        }
    }
    RGE_Diamond_Map::draw_object(param_1, param_2, param_3, param_4,
                                 param_5);
}
