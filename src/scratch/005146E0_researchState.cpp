// VA: 005146E0, TRIBE_Player::researchState
// PDB: tplayer.cpp:1753-1756
// BINARY NOTE: tech_tree is read at +0x220 and calls get_tech_state.

#include "../../include/tech.h"
#include "../../include/tplayer.h"

unsigned char TRIBE_Player::researchState(int tech_id)
{
    return tech_tree->get_tech_state(tech_id);
}
