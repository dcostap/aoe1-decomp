// VA: 004B2BC0 TRIBE_Screen_Sed::Set_player_advance_civilization_text
// try 1: natural C++ member declarations instead of raw __fastcall address calls.

#include "../../include/scr_sed2_context.h"

int TRIBE_Screen_Sed::Set_player_advance_civilization_text(int)
{
    this->player_advance_civilization_drop->empty_list();
    this->player_advance_civilization_drop->append_line(0x1069, 0);
    this->player_advance_civilization_drop->append_line(0x106A, 1);
    this->player_advance_civilization_drop->append_line(0x106B, 2);
    this->player_advance_civilization_drop->append_line(0x106C, 3);
    this->player_advance_civilization_drop->append_line(0x106D, 4);
    this->player_advance_civilization_drop->setCurrentLineNumber(0);
    this->player_advance_civilization_drop->set_active(0);
    return 1;
}
