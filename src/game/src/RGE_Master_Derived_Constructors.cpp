#include "../include/RGE_Master_Animated_Object.h"
#include "../include/RGE_Master_Moving_Object.h"
#include "../include/RGE_Master_Action_Object.h"
#include "../include/RGE_Master_Combat_Object.h"
#include "../include/RGE_Master_Missile_Object.h"
#include "../include/RGE_Master_Doppleganger_Object.h"

#include "../include/RGE_Armor_Weapon_Info.h"
#include "../include/RGE_Task.h"
#include "../include/RGE_Task_List.h"
#include "../include/globals.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void rge_skip_task_binary(int fd) {
    short s = 0;
    uchar b = 0;
    float f = 0.0f;

    rge_read(fd, &s, 2);  // id
    rge_read(fd, &b, 1);  // is_default
    rge_read(fd, &s, 2);  // action_type
    rge_read(fd, &s, 2);  // object_group
    rge_read(fd, &s, 2);  // object_id
    rge_read(fd, &s, 2);  // terrain_id
    rge_read(fd, &s, 2);  // attribute_type
    rge_read(fd, &s, 2);  // attribute_type2
    rge_read(fd, &s, 2);  // attribute_type3
    rge_read(fd, &s, 2);  // attribute_type4
    rge_read(fd, &f, 4);  // work_val1
    rge_read(fd, &f, 4);  // work_val2
    rge_read(fd, &f, 4);  // work_range
    rge_read(fd, &b, 1);  // search_flag
    rge_read(fd, &f, 4);  // search_wait_time
    rge_read(fd, &b, 1);  // combat_level
    rge_read(fd, &b, 1);  // combat_level_flag
    rge_read(fd, &s, 2);  // work_flag
    rge_read(fd, &s, 2);  // work_flag2
    rge_read(fd, &b, 1);  // owner_type
    rge_read(fd, &b, 1);  // holding_attr
    rge_read(fd, &b, 1);  // state_building
    rge_read(fd, &s, 2);  // move_sprite
    rge_read(fd, &s, 2);  // work_sprite
    rge_read(fd, &s, 2);  // work_sprite2
    rge_read(fd, &s, 2);  // carry_sprite
    rge_read(fd, &s, 2);  // work_sound
    rge_read(fd, &s, 2);  // work_sound2
}

static void rge_skip_task_list_binary(int fd) {
    short list_num = 0;
    rge_read(fd, &list_num, 2);
    if (list_num <= 0) {
        return;
    }

    for (short i = 0; i < list_num; ++i) {
        short task_type = 0;
        rge_read(fd, &task_type, 2);
        rge_skip_task_binary(fd);
    }
}

RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Object()
    : RGE_Master_Animated_Object() {
    this->master_type = 0x19;
}

// Fully verified. Source of truth: m_dg_obj.cpp.decomp @ 0x004510C0
RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Object(RGE_Master_Doppleganger_Object* param_1, int param_2)
    : RGE_Master_Animated_Object((RGE_Master_Animated_Object*)param_1, 0) {
    this->master_type = 0x19;
    if (param_2 != 0) {
        this->setup(param_1);
    }
}

// Fully verified. Source of truth: m_dg_obj.cpp.decomp @ 0x00451140
RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4)
    : RGE_Master_Animated_Object(param_1, param_2, param_3, 0) {
    this->master_type = 0x19;
    if (param_4 != 0) {
        this->setup(param_1, param_2, param_3);
    }
}

// Fully verified. Source of truth: m_dg_obj.cpp.decomp @ 0x004511B0
RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Object(FILE* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5)
    : RGE_Master_Animated_Object(param_1, param_2, param_3, param_4, 0) {
    this->master_type = 0x19;
    if (param_5 != 0) {
        this->setup(param_1, param_2, param_3, param_4);
    }
}
