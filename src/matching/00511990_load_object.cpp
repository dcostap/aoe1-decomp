// 00511990 TRIBE_Master_Player::load_object
// Source: tmplayer.cpp lines 61-81
// The original function is EH-framed. The module proposal compiles with /GX.

#include "../../include/tmplayer_context.h"

void TRIBE_Master_Player::load_object(_iobuf* file, unsigned char object_type,
                                      RGE_Sprite** sprites, RGE_Sound** sounds,
                                      short index)
{
    RGE_Master_Static_Object* object;

    switch (object_type) {
    case 'F':
        object = new TRIBE_Master_Combat_Object(file, sprites, sounds, index, 1);
        break;
    case 'P':
        object = new TRIBE_Master_Building_Object(file, sprites, sounds, index, 1);
        this->master_objects[index] = object;
        return;
    case 'Z':
        object = new TRIBE_Master_Tree_Object(file, sprites, sounds, index, 1);
        break;
    default:
        RGE_Master_Player::load_object(file, object_type, sprites, sounds, index);
        return;
    }

    this->master_objects[index] = object;
}
