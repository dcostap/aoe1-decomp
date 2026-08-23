// VA: 0052E830 TRIBE_World::load_player
// PDB source: tworld.cpp lines 328-344
//
// Baseline reconstruction: player slots are the RGE world array at +0x40;
// types 1 and 3 load TRIBE_Player, type 2 loads TRIBE_Gaia, and all other
// types defer to RGE_Game_World.  The final call is TRIBE_Player::load at
// vtable slot 0x74.  The class sizes are the proven 0x848/0x858 allocation
// sizes, rather than decompiler cursor arithmetic.

#include "../../include/tworld_prefix_context.h"

void TRIBE_World::load_player(int player, unsigned char type, short player_id)
{
    switch (type) {
    case 1:
    case 3:
        this->players[player_id] =
            (RGE_Player*)new TRIBE_Player(player, this, (unsigned char)player_id);
        break;
    case 2:
        this->players[player_id] =
            (RGE_Player*)new TRIBE_Gaia(player, this, (unsigned char)player_id);
        break;
    default:
        RGE_Game_World::load_player(player, type, player_id);
        return;
    }

    ((TRIBE_Player*)this->players[player_id])->load(player);
}
