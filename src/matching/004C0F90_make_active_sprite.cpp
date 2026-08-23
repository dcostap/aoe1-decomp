// VA: 004C0F90 RGE_Sprite::make_active_sprite
// sprite.cpp
// FLAGS: /GX (original has EH around new + constructor)
// Attempt log:
// try 1: natural typed new of active/animated sprite based on flags & 1.

#include "../../include/sprite_context.h"

class RGE_Active_Animated_Sprite;

class RGE_Active_Sprite {
public:
    char gap_00[0x14];
    RGE_Active_Sprite(RGE_Sprite* sprite);
};

class RGE_Active_Animated_Sprite : public RGE_Active_Sprite {
public:
    char gap_14[0x28 - 0x14];
    RGE_Active_Animated_Sprite(RGE_Sprite* sprite);
};

RGE_Active_Sprite* RGE_Sprite::make_active_sprite()
{
    if (this->flags & 1) {
        return new RGE_Active_Animated_Sprite(this);
    }
    return new RGE_Active_Sprite(this);
}
