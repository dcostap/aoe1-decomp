#include "../include/TRIBE_Combat_Object.h"

#include "../include/RGE_Game_World.h"
#include "../include/RGE_Player.h"
#include "../include/TRIBE_Master_Combat_Object.h"
#include "../include/TRIBE_Master_Building_Object.h"
#include "../include/TRIBE_Action_List.h"
#include "../include/TribeUnitAIModules.h"
#include "../include/globals.h"

#include <cstddef>
#include <new>

static void tribe_adjust_player_attribute_offset(RGE_Player* player, size_t byte_offset, float delta) {
    if (player == nullptr || player->attributes == nullptr) {
        return;
    }
    *(float*)((char*)player->attributes + byte_offset) = *(float*)((char*)player->attributes + byte_offset) + delta;
}

// Fully verified. Source of truth: t_c_obj.cpp.decomp @ 0x004CA0F0, t_c_obj.cpp.asm @ 0x004CA0F0
TRIBE_Combat_Object::TRIBE_Combat_Object(TRIBE_Master_Combat_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6)
    : RGE_Combat_Object((RGE_Master_Combat_Object*)param_1, param_2, param_3, param_4, param_5, 0) {
    if (param_6 != 0) {
        this->setup(param_1, param_2, param_3, param_4, param_5);
    }
}

// Fully verified. Source of truth: t_c_obj.cpp.decomp @ 0x004CA1A0
TRIBE_Combat_Object::TRIBE_Combat_Object(int param_1, RGE_Game_World* param_2, int param_3)
    : RGE_Combat_Object(param_1, param_2, 0) {
    if (param_3 != 0) {
        this->setup(param_1, param_2);
    }
}

// Fully verified. Source of truth: t_c_obj.cpp.decomp @ 0x004CA210
TRIBE_Combat_Object::~TRIBE_Combat_Object() = default;

// Fully verified. Source of truth: t_c_obj.cpp.decomp @ 0x004CA510
RGE_Action_List* TRIBE_Combat_Object::create_action_list() {
    TRIBE_Action_List* list = new (std::nothrow) TRIBE_Action_List((RGE_Action_Object*)this);
    return (RGE_Action_List*)list;
}

// Fully verified. Source of truth: t_c_obj.cpp.decomp @ 0x004CA3E0, t_c_obj.cpp.asm @ 0x004CA3E0
int TRIBE_Combat_Object::setup(int param_1, RGE_Game_World* param_2) {
    int fd = param_1;
    RGE_Game_World* world = param_2;

    RGE_Combat_Object::setup(fd, world);
    this->type = 'F';

    rge_read(fd, &this->own_master, 1);
    if (this->own_master != 0) {
        unsigned char master_type = 0;
        rge_read(fd, &master_type, 1);

        if (master_type == 'F') {
            TRIBE_Master_Combat_Object* master =
                (TRIBE_Master_Combat_Object*)::operator new(sizeof(TRIBE_Master_Combat_Object), std::nothrow);
            if (master != nullptr) {
                new (master) TRIBE_Master_Combat_Object(fd, world->sprites, world->sounds, 1);
            }
            this->master_obj = master;
        } else if (master_type == 'P') {
            TRIBE_Master_Building_Object* master =
                (TRIBE_Master_Building_Object*)::operator new(sizeof(TRIBE_Master_Building_Object), std::nothrow);
            if (master != nullptr) {
                new (master) TRIBE_Master_Building_Object(fd, world->sprites, world->sounds, 1);
            }
            this->master_obj = master;
        }
    }

    int has_unit_ai = 0;
    rge_read(fd, &has_unit_ai, 4);
    if (has_unit_ai == 1) {
        this->initUnitAI();
        if (this->unitAIValue != nullptr) {
            this->unitAIValue->load(fd);
        }
    }

    return 1;
}

// Fully verified. Source of truth: t_c_obj.cpp.decomp @ 0x004CA300, t_c_obj.cpp.asm @ 0x004CA300
int TRIBE_Combat_Object::setup(TRIBE_Master_Combat_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5) {
    this->RGE_Combat_Object::setup((RGE_Master_Static_Object*)param_1, param_2, param_3, param_4, param_5);

    if (this->owner != nullptr && this->owner->id == 0) {
        this->capture_flag = 1;
    }

    this->type = 0x46;
    this->initUnitAI();
    this->own_master = 0;

    if (param_1 != nullptr) {
        short object_group = param_1->object_group;
        if (object_group == 4 || object_group == 0x15 || object_group == 2) {
            tribe_adjust_player_attribute_offset(this->owner, 0x94, 1.0f);
        } else {
            short id = param_1->id;
            if (((object_group != 0x12) && (param_1->master_type == 0x46)) || (id == 0x4F || id == 0x45 || id == 199)) {
                tribe_adjust_player_attribute_offset(this->owner, 0xA0, 1.0f);
            }
        }

        if (param_1->object_group == 0x12) {
            this->attribute_amount_held = 100.0f;
            this->attribute_type_held = 0x22;
        }
    }

    return 1;
}

// Fully verified. Source of truth: t_c_obj.cpp.decomp @ 0x004CB8D0
void TRIBE_Combat_Object::initUnitAI() {
    if (this->master_obj == nullptr) {
        return;
    }

    this->unitAIValue = CreateTribeUnitAIModule(this, this->master_obj->object_group, this->master_obj->id);
}
