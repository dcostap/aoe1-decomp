// VA: 00460D60 RGE_Moving_Object::copy_obj
// The canonical RGE_Static_Object and RGE_Master_Moving_Object layouts live
// in include/move_obj_context.h. Their named virtual surface preserves both
// direct target identity and the final base copy call.

void RGE_Moving_Object::copy_obj(RGE_Master_Static_Object* master_obj) {
    RGE_Sprite* sprite = 0;
    RGE_Master_Moving_Object* old_master = (RGE_Master_Moving_Object*)this->master_obj;
    RGE_Master_Moving_Object* new_master = (RGE_Master_Moving_Object*)master_obj;

    if (this->sprite == old_master->move_sprite) {
        sprite = new_master->move_sprite;
    } else if (this->sprite == old_master->run_sprite) {
        sprite = new_master->run_sprite;
    }
    if (sprite != 0) {
        this->new_sprite(sprite);
    }
    RGE_Static_Object::copy_obj(master_obj);
}
