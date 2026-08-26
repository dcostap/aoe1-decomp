// Constructor for TRIBE_Panel_Inven
// Calls TPanel base constructor (004648B0h), initializes fields,
// sets vftable, calls TPanel::setup (00464A80h), then either
// sets error flag at +0D8h or calls set_player.

#include "../../include/tpnl_inv_context.h"

TRIBE_Panel_Inven::TRIBE_Panel_Inven(TDrawArea* area, TPanel* parent, void* font_, TRIBE_Player* player_)
    : TPanel()
{
    TPanel* parent_arg = parent;
    void* font_arg = font_;
    this->font = font_arg;
    this->save_attr_num = 0;
    this->save_attr = 0;
    *(int*)((char*)this + 0xF4) = 0;  // pics
    this->idle_time = 0;
    this->player = 0;
    this->back_color = 0;
    *(int**)this = TRIBE_Panel_Inven_vftable;
    this->idle_interval = 500;
    this->font_color = 0xFFFFFF;
    if (this->TPanel::setup(area, parent_arg, 0, 0, 0, 0, 0) == 0) {
        *(int*)((char*)this + 0xD8) = 1;
    } else {
        set_player(player_);
    }
}
