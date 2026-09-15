#include "../include/m_dg_obj.h"
#include "../include/dpl_obj.h"
#include "../include/player.h"
#include "../include/world.h"

RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Object(
    RGE_Master_Doppleganger_Object* other_object, int do_setup)
    : RGE_Master_Animated_Object(other_object, 0) {
    if (do_setup != 0) {
        setup(other_object);
    }
}

RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Object(
    int infile, RGE_Sprite** sprites, RGE_Sound** sounds, int do_setup)
    : RGE_Master_Animated_Object(infile, sprites, sounds, 0) {
    if (do_setup != 0) {
        setup(infile, sprites, sounds);
    }
}

RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Object(
    FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds, short in_id,
    int do_setup)
    : RGE_Master_Animated_Object(infile, sprites, sounds, in_id, 0) {
    if (do_setup != 0) {
        setup(infile, sprites, sounds, in_id);
    }
}

int RGE_Master_Doppleganger_Object::setup(RGE_Master_Doppleganger_Object* other_object) {
    RGE_Master_Animated_Object::setup(other_object);
    this->master_type = 0x19;
    this->fog_flag = 3;
    return 1;
}

int RGE_Master_Doppleganger_Object::setup(int infile, RGE_Sprite** sprites, RGE_Sound** sounds) {
    RGE_Master_Animated_Object::setup(infile, sprites, sounds);
    this->master_type = 0x19;
    return 1;
}

int RGE_Master_Doppleganger_Object::setup(FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds, short in_id) {
    RGE_Master_Animated_Object::setup(infile, sprites, sounds, in_id);
    this->master_type = 0x19;
    this->recyclable = 1;
    return 1;
}

RGE_Master_Doppleganger_Object::~RGE_Master_Doppleganger_Object() {
}

RGE_Static_Object* RGE_Master_Doppleganger_Object::make_new_obj(
    RGE_Player* owner, float x, float y, float z,
    RGE_Static_Object* obj_to_dopple) {
    if (this->recyclable != 0) {
        RGE_Doppleganger_Object* recycled =
            (RGE_Doppleganger_Object*)owner->world->recycle_object_in_to_game(
                this->master_type);
        if (recycled != 0) {
            recycled->recycle_in_to_game(this, owner, x, y, z, obj_to_dopple);
            return recycled;
        }
    }
    return new RGE_Doppleganger_Object(this, owner, x, y, z, 1, obj_to_dopple);
}

RGE_Master_Static_Object* RGE_Master_Doppleganger_Object::make_new_master() {
    return new RGE_Master_Doppleganger_Object(this, 1);
}

void RGE_Master_Doppleganger_Object::copy_obj(RGE_Master_Static_Object* source) {
    RGE_Master_Animated_Object::copy_obj(source);
}

void RGE_Master_Doppleganger_Object::save(int outfile) {
    RGE_Master_Animated_Object::save(outfile);
}
