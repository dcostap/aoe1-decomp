#include "../include/m_dg_obj.h"
#include "../include/dpl_obj.h"
#include "../include/player.h"
#include "../include/world.h"

RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Object(
    RGE_Master_Doppleganger_Object* param_1, int param_2)
    : RGE_Master_Animated_Object(param_1, 0) {
    if (param_2 != 0) {
        setup(param_1);
    }
}

RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Object(
    int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4)
    : RGE_Master_Animated_Object(param_1, param_2, param_3, 0) {
    if (param_4 != 0) {
        setup(param_1, param_2, param_3);
    }
}

RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Object(
    FILE* param_1, RGE_Sprite** param_2, RGE_Sound** param_3,
    short param_4, int param_5)
    : RGE_Master_Animated_Object(param_1, param_2, param_3, param_4, 0) {
    if (param_5 != 0) {
        setup(param_1, param_2, param_3, param_4);
    }
}

int RGE_Master_Doppleganger_Object::setup(
    RGE_Master_Doppleganger_Object* param_1) {
    RGE_Master_Animated_Object::setup(param_1);
    this->master_type = 0x19;
    this->fog_flag = 3;
    return 1;
}

int RGE_Master_Doppleganger_Object::setup(
    int param_1, RGE_Sprite** param_2, RGE_Sound** param_3) {
    RGE_Master_Animated_Object::setup(param_1, param_2, param_3);
    this->master_type = 0x19;
    return 1;
}

int RGE_Master_Doppleganger_Object::setup(
    FILE* param_1, RGE_Sprite** param_2, RGE_Sound** param_3,
    short param_4) {
    RGE_Master_Animated_Object::setup(param_1, param_2, param_3, param_4);
    this->master_type = 0x19;
    this->recyclable = 1;
    return 1;
}

RGE_Master_Doppleganger_Object::~RGE_Master_Doppleganger_Object() {
}

RGE_Static_Object* RGE_Master_Doppleganger_Object::make_new_obj(
    RGE_Player* param_1, float param_2, float param_3, float param_4,
    RGE_Static_Object* param_5) {
    if (this->recyclable != 0) {
        RGE_Doppleganger_Object* recycled =
            (RGE_Doppleganger_Object*)param_1->world->recycle_object_in_to_game(
                this->master_type);
        if (recycled != 0) {
            recycled->recycle_in_to_game(this, param_1, param_2, param_3,
                                         param_4, param_5);
            return recycled;
        }
    }
    return new RGE_Doppleganger_Object(this, param_1, param_2, param_3,
                                       param_4, 1, param_5);
}

RGE_Master_Static_Object* RGE_Master_Doppleganger_Object::make_new_master() {
    return new RGE_Master_Doppleganger_Object(this, 1);
}

void RGE_Master_Doppleganger_Object::copy_obj(
    RGE_Master_Static_Object* param_1) {
    RGE_Master_Animated_Object::copy_obj(param_1);
}

void RGE_Master_Doppleganger_Object::save(int param_1) {
    RGE_Master_Animated_Object::save(param_1);
}
