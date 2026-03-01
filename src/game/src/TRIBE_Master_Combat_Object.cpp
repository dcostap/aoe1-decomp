#include "../include/TRIBE_Master_Tree_Object.h"
#include "../include/TRIBE_Master_Combat_Object.h"
#include "../include/TRIBE_Master_Building_Object.h"
#include "../include/TRIBE_Combat_Object.h"
#include "../include/TRIBE_Building_Object.h"
#include "../include/TRIBE_Task_List.h"

#include "../include/Attribute_Cost.h"
#include "../include/RGE_Armor_Weapon_Info.h"
#include "../include/RGE_Damage_Sprite_Info.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Task_List.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Map.h"
#include "../include/RGE_Sprite.h"
#include "../include/DClipInfo_List.h"

#include "../include/globals.h"

#include <string.h>
#include <new>

static long rge_ftol(float value) {
    // Fully verified. Source of truth: tm_co_ob.cpp.decomp (helper implementation).
    long result;
    __asm {
        fld value
        fistp result
    }
    return result;
}

static void tribe_master_combat_recalc_armor(TRIBE_Master_Combat_Object* self) {
    // Fully verified. Source of truth: tm_co_ob.cpp.decomp (helper implementation).
    self->orig_pierce_armor = 0;
    self->orig_armor = (short)self->base_armor;

    if (self->armor == nullptr || self->armor_num <= 0) {
        return;
    }

    for (short i = 0; i < self->armor_num; ++i) {
        if (self->armor[i].type == 3) {
            if (self->armor[i].value > self->orig_pierce_armor) {
                self->orig_pierce_armor = self->armor[i].value;
            }
        } else if (self->armor[i].value > self->orig_armor) {
            self->orig_armor = self->armor[i].value;
        }
    }
}

TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object() {
    memset(this->build_inventory, 0, sizeof(this->build_inventory));
    this->build_pts_required = 0;
    this->id_of_building_obj = 0;
    this->button_location = 0;
    this->orig_pierce_armor = 0;
    this->master_type = 0x46;
}

// Fully verified. Source of truth: tm_co_ob.cpp.decomp @ 0x0050E970
TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object(TRIBE_Master_Combat_Object* param_1, int param_2)
    : RGE_Master_Combat_Object((RGE_Master_Combat_Object*)param_1, 0) {
    memset(this->build_inventory, 0, sizeof(this->build_inventory));
    this->build_pts_required = 0;
    this->id_of_building_obj = 0;
    this->button_location = 0;
    this->orig_pierce_armor = 0;
    this->master_type = 0x46;

    if (param_2 != 0) {
        this->setup(param_1);
    }
}

// Fully verified. Source of truth: tm_co_ob.cpp.decomp @ 0x0050E9F0
TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4)
    : RGE_Master_Combat_Object(param_1, param_2, param_3, 0) {
    memset(this->build_inventory, 0, sizeof(this->build_inventory));
    this->build_pts_required = 0;
    this->id_of_building_obj = 0;
    this->button_location = 0;
    this->orig_pierce_armor = 0;
    this->master_type = 0x46;

    if (param_4 != 0) {
        this->setup(param_1, param_2, param_3);
    }
}

// Fully verified. Source of truth: tm_co_ob.cpp.decomp @ 0x0050EA60
TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object(FILE* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5)
    : RGE_Master_Combat_Object(param_1, param_2, param_3, param_4, 0) {
    memset(this->build_inventory, 0, sizeof(this->build_inventory));
    this->build_pts_required = 0;
    this->id_of_building_obj = 0;
    this->button_location = 0;
    this->orig_pierce_armor = 0;
    this->master_type = 0x46;

    if (param_5 != 0) {
        this->setup(param_1, param_2, param_3, param_4);
    }
}

// Fully verified. Source of truth: tm_co_ob.cpp.decomp @ 0x0050EAE0
int TRIBE_Master_Combat_Object::setup(TRIBE_Master_Combat_Object* param_1) {
    if (param_1 == nullptr) {
        return 0;
    }

    this->RGE_Master_Combat_Object::setup((RGE_Master_Combat_Object*)param_1);
    this->master_type = 0x46;
    memcpy(this->build_inventory, param_1->build_inventory, sizeof(this->build_inventory));
    this->build_pts_required = param_1->build_pts_required;
    this->id_of_building_obj = param_1->id_of_building_obj;
    this->button_location = param_1->button_location;
    this->orig_pierce_armor = param_1->orig_pierce_armor;
    return 1;
}

// Fully verified. Source of truth: tm_co_ob.cpp.decomp @ 0x0050EB60
int TRIBE_Master_Combat_Object::setup(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3) {
    this->master_type = 0x46;

    for (int i = 0; i < 3; ++i) {
        rge_read(param_1, &this->build_inventory[i], 6);
    }
    rge_read(param_1, &this->build_pts_required, 2);
    rge_read(param_1, &this->id_of_building_obj, 2);
    rge_read(param_1, &this->button_location, 1);

    if (save_game_version >= 7.01f) {
        rge_read(param_1, &this->orig_pierce_armor, 2);
        return 1;
    }

    tribe_master_combat_recalc_armor(this);
    return 1;
}

// Fully verified. Source of truth: tm_co_ob.cpp.decomp @ 0x0050EC90
int TRIBE_Master_Combat_Object::setup(FILE* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4) {
    this->master_type = 0x46;

    short temp = 0;
    for (int i = 0; i < 3; ++i) {
        fscanf(param_1, " %hd %hd %hd", &this->build_inventory[i].type, &this->build_inventory[i].amount, &temp);
        this->build_inventory[i].flag = (uchar)temp;
    }

    fscanf(param_1, " %hd %hd %hd", &this->build_pts_required, &this->id_of_building_obj, &temp);
    this->button_location = (uchar)temp;

    tribe_master_combat_recalc_armor(this);
    return 1;
}

// Fully verified. Source of truth: tm_co_ob.cpp.decomp @ 0x0050EDA0
TRIBE_Master_Combat_Object::~TRIBE_Master_Combat_Object() {}

// Fully verified. Source of truth: tm_co_ob.cpp.decomp @ 0x0050EDB0
RGE_Task_List* TRIBE_Master_Combat_Object::create_task_list() {
    TRIBE_Task_List* list = new (std::nothrow) TRIBE_Task_List();
    return (RGE_Task_List*)list;
}

// Fully verified. Source of truth: tm_co_ob.cpp.decomp @ 0x0050EE00
void TRIBE_Master_Combat_Object::copy_obj(RGE_Master_Static_Object* param_1) {
    if (param_1 == nullptr) {
        return;
    }

    this->RGE_Master_Combat_Object::copy_obj(param_1);

    TRIBE_Master_Combat_Object* src = (TRIBE_Master_Combat_Object*)param_1;
    memcpy(this->build_inventory, src->build_inventory, sizeof(this->build_inventory));
    this->build_pts_required = src->build_pts_required;
    this->id_of_building_obj = src->id_of_building_obj;
    this->button_location = src->button_location;
    this->orig_pierce_armor = src->orig_pierce_armor;
}

// Fully verified. Source of truth: tm_co_ob.cpp.decomp @ 0x0050EE80, tm_co_ob.cpp.asm @ 0x0050EE80
void TRIBE_Master_Combat_Object::modify(float param_1, uchar param_2) {
    if (param_2 == 'd') {
        for (int i = 0; i < 3; ++i) {
            if (this->build_inventory[i].flag != 0) {
                this->build_inventory[i].amount = (short)rge_ftol(param_1);
            }
        }
        return;
    }

    if (param_2 != 'e') {
        this->RGE_Master_Combat_Object::modify(param_1, param_2);
        return;
    }

    for (int i = 0; i < 3; ++i) {
        if (this->build_inventory[i].flag == 0) {
            this->build_inventory[i].amount = (short)rge_ftol(-param_1);
        }
    }

    for (int i = 0; i < 3; ++i) {
        if (this->attribute_type_held[i] == 4) {
            this->attribute_amount_held[i] = param_1;
        }
    }

    for (int i = 0; i < 3; ++i) {
        if (this->attribute_type_held[i] == 0x0B) {
            this->attribute_amount_held[i] = -param_1;
        }
    }

    for (int i = 0; i < 3; ++i) {
        if (this->attribute_type_held[i] == 0x13) {
            this->attribute_amount_held[i] = -param_1;
        }
    }
}

// Fully verified. Source of truth: tm_co_ob.cpp.decomp @ 0x0050EF70, tm_co_ob.cpp.asm @ 0x0050EF70
void TRIBE_Master_Combat_Object::modify_delta(float param_1, uchar param_2) {
    if (param_2 != 'd') {
        this->RGE_Master_Combat_Object::modify_delta(param_1, param_2);
        return;
    }

    for (int i = 0; i < 3; ++i) {
        if (this->build_inventory[i].flag != 0) {
            this->build_inventory[i].amount = (short)(this->build_inventory[i].amount + (short)rge_ftol(param_1));
        }
    }
}

// Fully verified. Source of truth: tm_co_ob.cpp.decomp @ 0x0050EFC0, tm_co_ob.cpp.asm @ 0x0050EFC0
void TRIBE_Master_Combat_Object::modify_percent(float param_1, uchar param_2) {
    if (param_2 != 'd') {
        this->RGE_Master_Combat_Object::modify_percent(param_1, param_2);
        return;
    }

    for (int i = 0; i < 3; ++i) {
        if (this->build_inventory[i].flag != 0) {
            this->build_inventory[i].amount = (short)rge_ftol((float)this->build_inventory[i].amount * param_1);
        }
    }
}

// Fully verified. Source of truth: tm_co_ob.cpp.decomp @ 0x0050F010
void TRIBE_Master_Combat_Object::save(int param_1) {
    this->RGE_Master_Combat_Object::save(param_1);

    for (int i = 0; i < 3; ++i) {
        rge_write(param_1, &this->build_inventory[i], 6);
    }

    rge_write(param_1, &this->build_pts_required, 2);
    rge_write(param_1, &this->id_of_building_obj, 2);
    rge_write(param_1, &this->button_location, 1);
    rge_write(param_1, &this->orig_pierce_armor, 2);
}

// Fully verified. Source of truth: tm_co_ob.cpp.decomp @ 0x0050F090, tm_co_ob.cpp.asm @ 0x0050F090
RGE_Static_Object* TRIBE_Master_Combat_Object::make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4) {
    TRIBE_Combat_Object* obj = new (std::nothrow) TRIBE_Combat_Object(this, param_1, param_2, param_3, param_4, 1);
    return (RGE_Static_Object*)obj;
}

// Fully verified. Source of truth: tm_co_ob.cpp.decomp @ 0x0050F110
RGE_Master_Static_Object* TRIBE_Master_Combat_Object::make_new_master() {
    TRIBE_Master_Combat_Object* master = new (std::nothrow) TRIBE_Master_Combat_Object(this, 1);
    return (RGE_Master_Static_Object*)master;
}

// Fully verified. Source of truth: tm_co_ob.cpp.decomp (helper implementation).
uchar TRIBE_Master_Combat_Object::check_placement(RGE_Player* param_1, float param_2, float param_3, int* param_4, uchar param_5, uchar param_6, uchar param_7, uchar param_8, uchar param_9, uchar param_10) { return this->RGE_Master_Static_Object::check_placement(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
// Fully verified. Source of truth: tm_co_ob.cpp.decomp (helper implementation).
uchar TRIBE_Master_Combat_Object::alignment(float* param_1, float* param_2, RGE_Game_World* param_3, uchar param_4) { return this->RGE_Master_Static_Object::alignment(param_1, param_2, param_3, param_4); }
// Fully verified. Source of truth: tm_co_ob.cpp.decomp (helper implementation).
long TRIBE_Master_Combat_Object::calc_base_damage_ability(RGE_Master_Combat_Object* param_1) { return this->RGE_Master_Static_Object::calc_base_damage_ability(param_1); }
// Fully verified. Source of truth: tm_co_ob.cpp.decomp (helper implementation).
void TRIBE_Master_Combat_Object::play_command_sound() { this->RGE_Master_Static_Object::play_command_sound(); }
// Fully verified. Source of truth: tm_co_ob.cpp.decomp (helper implementation).
void TRIBE_Master_Combat_Object::play_move_sound() { this->RGE_Master_Static_Object::play_move_sound(); }
// Fully verified. Source of truth: tm_co_ob.cpp.decomp (helper implementation).
void TRIBE_Master_Combat_Object::draw(TDrawArea* param_1, short param_2, short param_3, RGE_Color_Table* param_4, long param_5, long param_6, int param_7, uchar param_8) { this->RGE_Master_Static_Object::draw(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }

