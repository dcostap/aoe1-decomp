#include "../include/m_an_obj.h"
#include "../include/ani_obj.h"
#include "../include/player.h"
#include "../include/rge_fio.h"
#include "../include/world.h"

RGE_Master_Animated_Object::RGE_Master_Animated_Object(RGE_Master_Animated_Object* other_object, int do_setup) :
    RGE_Master_Static_Object(other_object, 0) {
    if (do_setup) {
        setup(other_object);
    }
}

RGE_Master_Animated_Object::RGE_Master_Animated_Object(
    int infile, RGE_Sprite** sprites, RGE_Sound** sounds, int do_setup
) : RGE_Master_Static_Object(infile, sprites, sounds, 0) {
    if (do_setup) {
        setup(infile, sprites, sounds);
    }
}

RGE_Master_Animated_Object::RGE_Master_Animated_Object(
    FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds, short in_id, int do_setup
) : RGE_Master_Static_Object(infile, sprites, sounds, in_id, 0) {
    if (do_setup) {
        setup(infile, sprites, sounds, in_id);
    }
}

int RGE_Master_Animated_Object::setup(RGE_Master_Animated_Object* other_object) {
    RGE_Master_Static_Object::setup(other_object);
    master_type = RGE_MASTER_TYPE_ANIMATED;
    speed = other_object->speed;
    return 1;
}

int RGE_Master_Animated_Object::setup(int infile, RGE_Sprite** sprites, RGE_Sound** sounds) {
    RGE_Master_Static_Object::setup(infile, sprites, sounds);
    master_type = RGE_MASTER_TYPE_ANIMATED;
    rge_read(infile, &speed, 4);
    return 1;
}

int RGE_Master_Animated_Object::setup(FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds, short in_id) {
    RGE_Master_Static_Object::setup(infile, sprites, sounds, in_id);
    master_type = RGE_MASTER_TYPE_ANIMATED;
    fscanf(infile, "%f", &speed);
    return 1;
}

RGE_Master_Animated_Object::~RGE_Master_Animated_Object() {
}

RGE_Static_Object* RGE_Master_Animated_Object::make_new_obj(RGE_Player* owner, float x, float y, float z) {
    if (recyclable) {
        RGE_Static_Object* object = owner->world->recycle_object_in_to_game(master_type);
        if (object) {
            object->recycle_in_to_game(this, owner, x, y, z);
            return object;
        }
    }

    return new RGE_Animated_Object(this, owner, x, y, z, 1);
}

RGE_Master_Static_Object* RGE_Master_Animated_Object::make_new_master() {
    return new RGE_Master_Animated_Object(this, 1);
}

void RGE_Master_Animated_Object::copy_obj(RGE_Master_Static_Object* source) {
    RGE_Master_Static_Object::copy_obj(source);
    speed = static_cast<RGE_Master_Animated_Object*>(source)->speed;
}

void RGE_Master_Animated_Object::modify(float amount, unsigned char flag) {
    if (flag != 5) {
        RGE_Master_Static_Object::modify(amount, flag);
        return;
    }
    speed = amount;
}

void RGE_Master_Animated_Object::modify_delta(float amount, unsigned char flag) {
    if (flag != 5) {
        RGE_Master_Static_Object::modify_delta(amount, flag);
        return;
    }
    speed = amount + speed;
}

void RGE_Master_Animated_Object::modify_percent(float amount, unsigned char flag) {
    if (flag != 5) {
        RGE_Master_Static_Object::modify_percent(amount, flag);
        return;
    }
    speed = amount * speed;
}

void RGE_Master_Animated_Object::save(int outfile) {
    RGE_Master_Static_Object::save(outfile);
    rge_write(outfile, &speed, 4);
}
