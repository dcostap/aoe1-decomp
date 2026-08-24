// 00511800 TRIBE_Master_Player::TRIBE_Master_Player
// Source: tmplayer.cpp lines 30-32

#include "../../include/tmplayer_context.h"

TRIBE_Master_Player::TRIBE_Master_Player(int player)
    : RGE_Master_Player(player)
{
    this->type = 1;
}
