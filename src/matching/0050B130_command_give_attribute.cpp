// VA: 0050B130 TRIBE_Command::command_give_attribute
// PDB: tcommand.cpp lines 1553-1579.
// Exact code needs declaration-order packet writes.

#include <stdlib.h>
#include "../tcommand_context.h"

void TRIBE_Command::command_give_attribute(
    int player_id,
    int to_player_id,
    int attr,
    float amount,
    float amount2)
{
    TRIBE_Command_Give_Attribute* packet =
        (TRIBE_Command_Give_Attribute*)calloc(
            1, sizeof(TRIBE_Command_Give_Attribute));
    packet->command = 0x6C;
    packet->player_id = (unsigned char)player_id;
    packet->to_player_id = (unsigned char)to_player_id;
    packet->attr_id = (unsigned char)attr;
    packet->attr_amount = amount;
    packet->attr_cost = amount2;
    L->Log("      >SEND CMD GIVE ATTR (PLR=%d,TO=%d)",
           player_id,
           to_player_id);
    this->submit(packet, sizeof(TRIBE_Command_Give_Attribute));
}
