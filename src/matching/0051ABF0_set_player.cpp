class TRIBE_Player;

#include "../../include/tpnl_inv_context.h"

void TRIBE_Panel_Inven::set_player(TRIBE_Player* player) {
    this->player = player;
    save_info();
    this->set_redraw(1);
}
