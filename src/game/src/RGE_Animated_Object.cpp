#include "../include/RGE_Animated_Object.h"
#include "../include/RGE_Active_Sprite_List.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Master_Animated_Object.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Player.h"
#include "../include/globals.h"

// Default constructor for make_new_obj usage
RGE_Animated_Object::RGE_Animated_Object()
    : RGE_Static_Object()
{
    this->speed = 0.0f;
}

RGE_Animated_Object::RGE_Animated_Object(RGE_Master_Animated_Object* param_1, RGE_Player* param_2, float param_3,
                                         float param_4, float param_5, int param_6)
    : RGE_Static_Object()
{
    this->speed = 0.0f;

    if (param_6 != 0) {
        this->setup(param_1, param_2, param_3, param_4, param_5);
    }
}

// Fully verified. Source of truth: ani_obj.cpp.decomp @ 0x0041A210
RGE_Animated_Object::RGE_Animated_Object(int param_1, RGE_Game_World* param_2, int param_3)
    : RGE_Static_Object(param_1, param_2, 0)
{
    // vtable is set implicitly by C++
    if (param_3 != 0) {
        this->setup(param_1, param_2);
    }
}

// Fully verified. Source of truth: ani_obj.cpp.decomp @ 0x0041A310
int RGE_Animated_Object::setup(int param_1, RGE_Game_World* param_2) {
    RGE_Static_Object::setup(param_1, param_2);
    this->type = 0x14;
    rge_read(param_1, &this->speed, 4);
    return 1;
}

RGE_Animated_Object::~RGE_Animated_Object() {
}

// Fully verified. Source of truth: ani_obj.cpp.asm @ 0x00405F40
float RGE_Animated_Object::getSpeed() {
    return this->speed;
}

// Fully verified. Source of truth: ani_obj.cpp.asm @ 0x0041A280
void RGE_Animated_Object::recycle_in_to_game(RGE_Master_Static_Object* param_1, RGE_Player* param_2, float param_3,
                                             float param_4, float param_5) {
    RGE_Static_Object::recycle_in_to_game(param_1, param_2, param_3, param_4, param_5);
    this->speed = 0.0f;
    this->set_sleep_flag(0);
}

// Fully verified. Source of truth: ani_obj.cpp.asm @ 0x0041A2C0
int RGE_Animated_Object::setup(RGE_Master_Animated_Object* param_1, RGE_Player* param_2, float param_3, float param_4,
                               float param_5) {
    RGE_Static_Object::setup((RGE_Master_Static_Object*)param_1, param_2, param_3, param_4, param_5);
    this->type = 0x14;
    this->speed = 0.0f;
    this->set_sleep_flag(0);
    return 1;
}

// Fully verified. Source of truth: ani_obj.cpp.asm @ 0x0041A350
uchar RGE_Animated_Object::update() {
    uchar uVar1 = RGE_Static_Object::update();

    if (this->object_state == 3) {
        if (this->master_obj->death_sprite == nullptr) {
            this->set_object_state(5);
        } else {
            this->set_object_state(4);
        }
    } else if (this->object_state == 4) {
        uchar animating = this->sprite_list->is_animating(this->sprite);
        if (animating == 0) {
            this->object_state = 5;
            this->speed = 0.0f;
        }
    }

    this->sprite_list->update(this->owner->world->world_time_delta_seconds, this->speed);
    return uVar1;
}

// Fully verified. Source of truth: ani_obj.cpp.asm @ 0x0041A3D0
void RGE_Animated_Object::save(int param_1) {
    RGE_Static_Object::save(param_1);
    rge_write(param_1, &this->speed, 4);
}

// Fully verified. Source of truth: ani_obj.cpp.asm @ 0x0041A400
void RGE_Animated_Object::transform(RGE_Master_Static_Object* param_1) {
    RGE_Static_Object::transform(param_1);
}

// Fully verified. Source of truth: ani_obj.cpp.decomp @ 0x0041A410
void RGE_Animated_Object::set_being_worked_on(RGE_Action_Object* param_1, short param_2, uchar param_3) {
    RGE_Static_Object::set_being_worked_on(param_1, param_2, param_3);
}

// Fully verified. Source of truth: ani_obj.cpp.decomp @ 0x0041A430
void RGE_Animated_Object::release_being_worked_on(RGE_Static_Object* param_1) {
    RGE_Static_Object::release_being_worked_on(param_1);
    this->set_sleep_flag(0);
}
