#include "../include/TRIBE_Panel_Inven.h"

#include "../include/TShape.h"
#include <stdlib.h>

TRIBE_Panel_Inven::TRIBE_Panel_Inven(TDrawArea* area, TPanel* parent, void* font_param, TRIBE_Player* player_param)
    : TPanel() {
    // TODO: STUB - Constructor/setup parity is partial; complete tpnl_inv.cpp.{decomp,asm} behavior.
    this->font = font_param;
    this->save_attr_num = 0;
    this->save_attr = nullptr;
    this->pics = nullptr;
    this->idle_time = 0;
    this->player = nullptr;
    this->back_color = 0;
    this->idle_interval = 500;
    this->font_color = 0xFFFFFF;

    if (this->setup(area, parent, 0, 0, 0, 0, 0) == 0) {
        this->error_code = 1;
        return;
    }

    this->set_player(player_param);
}

TRIBE_Panel_Inven::~TRIBE_Panel_Inven() {
    if (this->save_attr != nullptr) {
        free(this->save_attr);
        this->save_attr = nullptr;
    }

    if (this->pics != nullptr) {
        delete this->pics;
        this->pics = nullptr;
    }
}

void TRIBE_Panel_Inven::set_player(TRIBE_Player* player_param) {
    this->player = player_param;
    this->set_redraw(TPanel::Redraw);
}

void TRIBE_Panel_Inven::set_text_color(unsigned long color1, unsigned long color2) {
    this->font_color = color1;
    this->back_color = color2;
    this->set_redraw(TPanel::Redraw);
}
