// VA: 00513D80, TRIBE_Player::pay_tech_cost
// PDB: tplayer.cpp:1489-1491
// BINARY NOTE: tech_tree is read at +0x220 and starts research with charge
// enabled and no missing-attribute output.

#include "../../include/tech.h"
#include "../../include/tplayer.h"

unsigned char TRIBE_Player::pay_tech_cost(short tech_id)
{
    return tech_tree->start_research(tech_id, 1, 0);
}
