// VA: 005146B0, TRIBE_Player::researchEverAvailable
// PDB: tplayer.cpp:1741-1748
// BINARY NOTE: tech_tree is read at +0x220. State values 3 and -1 are not
// available for further research.

#include "../../include/tech.h"
#include "../../include/tplayer.h"

int TRIBE_Player::researchEverAvailable(int tech_id)
{
    short state;

    state = tech_tree->get_tech_state(tech_id);
    if (state != 3 && state != -1) {
        return 1;
    }
    return 0;
}
