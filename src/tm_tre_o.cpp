#include "../include/tm_tre_o.h"
#include "../include/t_tre_ob.h"

TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object(TRIBE_Master_Tree_Object* other_object, int do_setup) :
    RGE_Master_Static_Object(other_object, 0) {
    if (do_setup != 0) {
        setup(other_object);
        master_type = 0x5A;
    }
}

TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object(int infile, RGE_Sprite** sprites, RGE_Sound** sounds, int do_setup) :
    RGE_Master_Static_Object(infile, sprites, sounds, 0) {
    if (do_setup != 0) {
        setup(infile, sprites, sounds);
        master_type = 0x5A;
    }
}

TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object(
    FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds, short in_id, int do_setup
) : RGE_Master_Static_Object(infile, sprites, sounds, in_id, 0) {
    if (do_setup != 0) {
        setup(infile, sprites, sounds, in_id);
        master_type = 0x5A;
    }
}

RGE_Static_Object* TRIBE_Master_Tree_Object::make_new_obj(RGE_Player* owner, float x, float y, float z) {
    return new TRIBE_Tree_Object(this, owner, x, y, z, 1);
}

RGE_Master_Static_Object* TRIBE_Master_Tree_Object::make_new_master() {
    return new TRIBE_Master_Tree_Object(this, 1);
}
