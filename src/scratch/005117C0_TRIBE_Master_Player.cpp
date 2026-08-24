// 005117C0 TRIBE_Master_Player::TRIBE_Master_Player
// Source: tmplayer.cpp lines 23-25

#include "../../include/tmplayer_context.h"

TRIBE_Master_Player::TRIBE_Master_Player(_iobuf* file)
    : RGE_Master_Player(file)
{
    this->type = 1;
}
