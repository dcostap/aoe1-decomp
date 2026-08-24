// VA: 004348F0 RGE_Command::do_command_add_attribute (40B)
// PDB: Command.cpp lines 679-687, protected member owner.
// Exact finish: the canonical owner core must precede this first grouped body.
// The larger formation surface remains at its later source position. Moving
// this staged include into the wrapper regresses 004351B0 by 24 bytes.

#ifndef COMMAND_TU_CONTEXT
#define COMMAND_CONTEXT_CORE_ONLY
#include "../../include/command_context.h"
#undef COMMAND_CONTEXT_CORE_ONLY
#endif

void RGE_Command::do_command_add_attribute(RGE_Command_Add_Attribute* param_1) {
    RGE_Player* player = this->world->players[param_1->player_id];
    player->add_attribute_num(param_1->attr_id, param_1->attr_amount, 0);
}
