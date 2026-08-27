// VA: 00513DA0, TRIBE_Player::tech_abling
// PDB: tplayer.cpp:1496-1501
// BINARY NOTE: tech_tree is read at +0x220. The two direct calls are
// TRIBE_Player_Tech::enable (0050D383) and disable (0050D306).

#include "../../include/tech.h"
#include "../../include/tplayer.h"

void TRIBE_Player::tech_abling(long tech_id, unsigned char enable)
{
    if (enable) {
        tech_tree->enable(tech_id);
    } else {
        tech_tree->disable(tech_id);
    }
}
