#include "../com_obj_phase2_context.h"

void RGE_Combat_Object::copy_obj(RGE_Master_Static_Object* master_obj) {
    RGE_Sprite* sound;

    sound = 0;
    if (sprite == this->master_obj->fight_sprite) {
        sound = master_obj->fight_sprite;
    }
    if (sound != 0) {
        new_sprite(sound);
    }
    RGE_Action_Object::copy_obj(master_obj);
}
