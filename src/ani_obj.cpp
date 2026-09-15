
#include "../include/ani_obj.h"
#include "../include/asp_list.h"
#include "../include/player.h"
#include "../include/rge_fio.h"
#include "../include/world.h"

RGE_Animated_Object::RGE_Animated_Object(
    RGE_Master_Animated_Object* tobj, RGE_Player* obj_owner,
    float x, float y, float z, int do_setup)
    : RGE_Static_Object(tobj, obj_owner, x, y, z, 0) {
    if (do_setup != 0) {
        setup(tobj, obj_owner, x, y, z);
    }
}

RGE_Animated_Object::RGE_Animated_Object(
    int infile, RGE_Game_World* gworld, int do_setup)
    : RGE_Static_Object(infile, gworld, 0) {
    if (do_setup != 0) {
        setup(infile, gworld);
    }
}

void RGE_Animated_Object::recycle_in_to_game(
    RGE_Master_Static_Object* tobj, RGE_Player* obj_owner,
    float x, float y, float z) {
    RGE_Static_Object::recycle_in_to_game(tobj, obj_owner, x, y, z);
    this->speed = 0.0f;
    RGE_Static_Object::set_sleep_flag(0);
}

int RGE_Animated_Object::setup(
    RGE_Master_Animated_Object* tobj, RGE_Player* obj_owner,
    float x, float y, float z) {
    RGE_Static_Object::setup(tobj, obj_owner, x, y, z);
    this->type = 0x14;
    this->speed = 0.0f;
    RGE_Static_Object::set_sleep_flag(0);
    return 1;
}

int RGE_Animated_Object::setup(int infile, RGE_Game_World* gworld) {
    RGE_Static_Object::setup(infile, gworld);
    this->type = 0x14;
    rge_read(infile, &this->speed, 4);
    return 1;
}

unsigned char RGE_Animated_Object::update() {
    unsigned char result = RGE_Static_Object::update();

    unsigned char state = this->object_state;
    switch (state) {
    case 3: {
        RGE_Master_Static_Object* master = this->master_obj;
        if (master->death_sprite == 0) {
            this->set_object_state(5);
        } else {
            this->set_object_state(4);
        }
        break;
    }
    case 4: {
        unsigned char animating = this->sprite_list->is_animating(this->sprite);
        if (animating == 0) {
            this->object_state = 5;
            this->speed = 0.0f;
        }
        break;
    }
    }

    RGE_Game_World* game_world = this->owner->world;
    this->sprite_list->update(
        game_world->world_time_delta_seconds, this->speed);

    return result;
}

void RGE_Animated_Object::save(int outfile) {
    RGE_Static_Object::save(outfile);
    rge_write(outfile, &this->speed, 4);
}

void RGE_Animated_Object::transform(RGE_Master_Static_Object* obj) {
    RGE_Static_Object::transform(obj);
}

void RGE_Animated_Object::set_being_worked_on(
    RGE_Action_Object* work_obj, short action_type, unsigned char attack_flag) {
    RGE_Static_Object::set_being_worked_on(work_obj, action_type, attack_flag);
}

void RGE_Animated_Object::release_being_worked_on(RGE_Static_Object* caller) {
    RGE_Static_Object::release_being_worked_on(caller);
    RGE_Static_Object::set_sleep_flag(0);
}
