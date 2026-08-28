#include "../include/m_an_obj.h"
#include "../include/ani_obj.h"
#include "../include/player.h"
#include "../include/rge_fio.h"
#include "../include/world.h"

RGE_Master_Animated_Object::RGE_Master_Animated_Object(
    RGE_Master_Animated_Object* source, int do_setup)
    : RGE_Master_Static_Object(source, 0) {
    if (do_setup) {
        setup(source);
    }
}

RGE_Master_Animated_Object::RGE_Master_Animated_Object(
    int id, RGE_Sprite** sprites, RGE_Sound** sounds, int do_setup)
    : RGE_Master_Static_Object(id, sprites, sounds, 0) {
    if (do_setup) {
        setup(id, sprites, sounds);
    }
}

RGE_Master_Animated_Object::RGE_Master_Animated_Object(
    FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds, short id,
    int do_setup)
    : RGE_Master_Static_Object(file, sprites, sounds, id, 0) {
    if (do_setup) {
        setup(file, sprites, sounds, id);
    }
}

int RGE_Master_Animated_Object::setup(RGE_Master_Animated_Object* source) {
    RGE_Master_Static_Object::setup(source);
    master_type = 0x14;
    speed = source->speed;
    return 1;
}

int RGE_Master_Animated_Object::setup(int file, RGE_Sprite** sprites,
                                      RGE_Sound** sounds) {
    RGE_Master_Static_Object::setup(file, sprites, sounds);
    master_type = 0x14;
    rge_read(file, &speed, 4);
    return 1;
}

int RGE_Master_Animated_Object::setup(FILE* file, RGE_Sprite** sprites,
                                      RGE_Sound** sounds, short id) {
    RGE_Master_Static_Object::setup(file, sprites, sounds, id);
    master_type = 0x14;
    fscanf(file, "%f", &speed);
    return 1;
}

RGE_Master_Animated_Object::~RGE_Master_Animated_Object() {
}

RGE_Static_Object* RGE_Master_Animated_Object::make_new_obj(
    RGE_Player* player, float x, float y, float z) {
    if (recyclable) {
        RGE_Static_Object* object =
            player->world->recycle_object_in_to_game(master_type);
        if (object) {
            object->recycle_in_to_game(this, player, x, y, z);
            return object;
        }
    }

    return new RGE_Animated_Object(this, player, x, y, z, 1);
}

RGE_Master_Static_Object* RGE_Master_Animated_Object::make_new_master() {
    return new RGE_Master_Animated_Object(this, 1);
}

void RGE_Master_Animated_Object::copy_obj(RGE_Master_Static_Object* source) {
    RGE_Master_Static_Object::copy_obj(source);
    speed = ((RGE_Master_Animated_Object*)source)->speed;
}

void RGE_Master_Animated_Object::modify(float value, unsigned char attribute) {
    if (attribute != 5) {
        RGE_Master_Static_Object::modify(value, attribute);
        return;
    }
    speed = value;
}

void RGE_Master_Animated_Object::modify_delta(float value,
                                              unsigned char attribute) {
    if (attribute != 5) {
        RGE_Master_Static_Object::modify_delta(value, attribute);
        return;
    }
    speed = value + speed;
}

void RGE_Master_Animated_Object::modify_percent(float value,
                                                unsigned char attribute) {
    if (attribute != 5) {
        RGE_Master_Static_Object::modify_percent(value, attribute);
        return;
    }
    speed = value * speed;
}

void RGE_Master_Animated_Object::save(int file) {
    RGE_Master_Static_Object::save(file);
    rge_write(file, &speed, 4);
}
