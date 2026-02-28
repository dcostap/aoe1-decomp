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
    long result;
    __asm {
        fld value
        fistp result
    }
    return result;
}

static void tribe_master_combat_recalc_armor(TRIBE_Master_Combat_Object* self) {
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

TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object() : RGE_Master_Static_Object() {
    this->master_type = 0x5A;
}

// Fully verified. Source of truth: tm_tre_o.cpp.decomp @ 0x0050F180
TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object(TRIBE_Master_Tree_Object* param_1, int param_2)
    : RGE_Master_Static_Object((RGE_Master_Static_Object*)param_1, 0) {
    if (param_2 != 0) {
        this->RGE_Master_Static_Object::setup((RGE_Master_Static_Object*)param_1);
        this->master_type = 0x5A;
    }
}

// Fully verified. Source of truth: tm_tre_o.cpp.decomp @ 0x0050F220
TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4)
    : RGE_Master_Static_Object(param_1, param_2, param_3, 0) {
    if (param_4 != 0) {
        this->RGE_Master_Static_Object::setup(param_1, param_2, param_3);
        this->master_type = 0x5A;
    }
}

// Fully verified. Source of truth: tm_tre_o.cpp.decomp @ 0x0050F2A0
TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object(FILE* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5)
    : RGE_Master_Static_Object(param_1, param_2, param_3, param_4, 0) {
    if (param_5 != 0) {
        this->RGE_Master_Static_Object::setup(param_1, param_2, param_3, param_4);
        this->master_type = 0x5A;
    }
}

TRIBE_Master_Tree_Object::~TRIBE_Master_Tree_Object() {}
void TRIBE_Master_Tree_Object::copy_obj(RGE_Master_Static_Object* param_1) { if (param_1) this->RGE_Master_Static_Object::setup(param_1); this->master_type = 0x5A; }
void TRIBE_Master_Tree_Object::modify(float param_1, uchar param_2) { this->RGE_Master_Static_Object::modify(param_1, param_2); }
void TRIBE_Master_Tree_Object::modify_delta(float param_1, uchar param_2) { this->RGE_Master_Static_Object::modify_delta(param_1, param_2); }
void TRIBE_Master_Tree_Object::modify_percent(float param_1, uchar param_2) { this->RGE_Master_Static_Object::modify_percent(param_1, param_2); }
void TRIBE_Master_Tree_Object::save(int param_1) { this->RGE_Master_Static_Object::save(param_1); }

// TODO: STUB: tm_tre_o.cpp.decomp @ 0x0050F320 allocates TRIBE_Tree_Object.
// Keep base allocation path until full TRIBE_Tree_Object vtable coverage is implemented.
RGE_Static_Object* TRIBE_Master_Tree_Object::make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4) {
    return this->RGE_Master_Static_Object::make_new_obj(param_1, param_2, param_3, param_4);
}

// Fully verified. Source of truth: tm_tre_o.cpp.decomp @ 0x0050F3A0
RGE_Master_Static_Object* TRIBE_Master_Tree_Object::make_new_master() {
    TRIBE_Master_Tree_Object* master = new (std::nothrow) TRIBE_Master_Tree_Object(this, 1);
    return (RGE_Master_Static_Object*)master;
}

uchar TRIBE_Master_Tree_Object::check_placement(RGE_Player* param_1, float param_2, float param_3, int* param_4, uchar param_5, uchar param_6, uchar param_7, uchar param_8, uchar param_9, uchar param_10) { return this->RGE_Master_Static_Object::check_placement(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
uchar TRIBE_Master_Tree_Object::alignment(float* param_1, float* param_2, RGE_Game_World* param_3, uchar param_4) { return this->RGE_Master_Static_Object::alignment(param_1, param_2, param_3, param_4); }
long TRIBE_Master_Tree_Object::calc_base_damage_ability(RGE_Master_Combat_Object* param_1) { return this->RGE_Master_Static_Object::calc_base_damage_ability(param_1); }
void TRIBE_Master_Tree_Object::play_command_sound() { this->RGE_Master_Static_Object::play_command_sound(); }
void TRIBE_Master_Tree_Object::play_move_sound() { this->RGE_Master_Static_Object::play_move_sound(); }
void TRIBE_Master_Tree_Object::draw(TDrawArea* param_1, short param_2, short param_3, RGE_Color_Table* param_4, long param_5, long param_6, int param_7, uchar param_8) { this->RGE_Master_Static_Object::draw(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }

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
    : RGE_Master_Combat_Object(param_1, param_2, param_3, (param_4 != 0) ? 1 : 0) {
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
    : RGE_Master_Combat_Object(param_1, param_2, param_3, param_4, (param_5 != 0) ? 1 : 0) {
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

    this->RGE_Master_Combat_Object::copy_obj((RGE_Master_Static_Object*)param_1);
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

uchar TRIBE_Master_Combat_Object::check_placement(RGE_Player* param_1, float param_2, float param_3, int* param_4, uchar param_5, uchar param_6, uchar param_7, uchar param_8, uchar param_9, uchar param_10) { return this->RGE_Master_Static_Object::check_placement(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
uchar TRIBE_Master_Combat_Object::alignment(float* param_1, float* param_2, RGE_Game_World* param_3, uchar param_4) { return this->RGE_Master_Static_Object::alignment(param_1, param_2, param_3, param_4); }
long TRIBE_Master_Combat_Object::calc_base_damage_ability(RGE_Master_Combat_Object* param_1) { return this->RGE_Master_Static_Object::calc_base_damage_ability(param_1); }
void TRIBE_Master_Combat_Object::play_command_sound() { this->RGE_Master_Static_Object::play_command_sound(); }
void TRIBE_Master_Combat_Object::play_move_sound() { this->RGE_Master_Static_Object::play_move_sound(); }
void TRIBE_Master_Combat_Object::draw(TDrawArea* param_1, short param_2, short param_3, RGE_Color_Table* param_4, long param_5, long param_6, int param_7, uchar param_8) { this->RGE_Master_Static_Object::draw(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }

TRIBE_Master_Building_Object::TRIBE_Master_Building_Object() : TRIBE_Master_Combat_Object() {
    this->construction_sound = nullptr;
    this->construction_sprite = nullptr;
    this->building_connect_flag = 0;
    this->building_facet = 0;
    this->build_and_go_away = 0;
    this->on_build_make_obj = 0;
    this->on_build_make_tile = 0;
    this->on_build_make_overlay = 0;
    this->on_build_make_tech = 0;
    this->master_type = 0x50;
}

// Fully verified. Source of truth: tm_b_obj.cpp.decomp @ 0x0050E040
TRIBE_Master_Building_Object::TRIBE_Master_Building_Object(TRIBE_Master_Building_Object* param_1, int param_2)
    : TRIBE_Master_Combat_Object((TRIBE_Master_Combat_Object*)param_1, 0) {
    this->construction_sound = nullptr;
    this->construction_sprite = nullptr;
    this->building_connect_flag = 0;
    this->building_facet = 0;
    this->build_and_go_away = 0;
    this->on_build_make_obj = 0;
    this->on_build_make_tile = 0;
    this->on_build_make_overlay = 0;
    this->on_build_make_tech = 0;
    this->master_type = 0x50;

    if (param_2 != 0) {
        this->setup(param_1);
    }
}

// Fully verified. Source of truth: tm_b_obj.cpp.decomp @ 0x0050E0C0
TRIBE_Master_Building_Object::TRIBE_Master_Building_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4)
    : TRIBE_Master_Combat_Object(param_1, param_2, param_3, (param_4 != 0) ? 1 : 0) {
    this->construction_sound = nullptr;
    this->construction_sprite = nullptr;
    this->building_connect_flag = 0;
    this->building_facet = 0;
    this->build_and_go_away = 0;
    this->on_build_make_obj = 0;
    this->on_build_make_tile = 0;
    this->on_build_make_overlay = 0;
    this->on_build_make_tech = 0;
    this->master_type = 0x50;

    if (param_4 != 0) {
        this->setup(param_1, param_2, param_3);
    }
}

// Fully verified. Source of truth: tm_b_obj.cpp.decomp @ 0x0050E130
TRIBE_Master_Building_Object::TRIBE_Master_Building_Object(FILE* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5)
    : TRIBE_Master_Combat_Object(param_1, param_2, param_3, param_4, (param_5 != 0) ? 1 : 0) {
    this->construction_sound = nullptr;
    this->construction_sprite = nullptr;
    this->building_connect_flag = 0;
    this->building_facet = 0;
    this->build_and_go_away = 0;
    this->on_build_make_obj = 0;
    this->on_build_make_tile = 0;
    this->on_build_make_overlay = 0;
    this->on_build_make_tech = 0;
    this->master_type = 0x50;

    if (param_5 != 0) {
        this->setup(param_1, param_2, param_3, param_4);
    }
}

// Fully verified. Source of truth: tm_b_obj.cpp.decomp @ 0x0050E1B0
int TRIBE_Master_Building_Object::setup(TRIBE_Master_Building_Object* param_1) {
    if (param_1 == nullptr) {
        return 0;
    }

    this->TRIBE_Master_Combat_Object::setup((TRIBE_Master_Combat_Object*)param_1);
    this->master_type = 0x50;
    this->construction_sprite = param_1->construction_sprite;
    this->building_connect_flag = param_1->building_connect_flag;
    this->building_facet = param_1->building_facet;
    this->build_and_go_away = param_1->build_and_go_away;
    this->on_build_make_obj = param_1->on_build_make_obj;
    this->on_build_make_tile = param_1->on_build_make_tile;
    this->on_build_make_overlay = param_1->on_build_make_overlay;
    this->on_build_make_tech = param_1->on_build_make_tech;
    this->construction_sound = param_1->construction_sound;
    return 1;
}

// Fully verified. Source of truth: tm_b_obj.cpp.decomp @ 0x0050E250
int TRIBE_Master_Building_Object::setup(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3) {
    this->TRIBE_Master_Combat_Object::setup(param_1, param_2, param_3);
    this->master_type = 0x50;

    short construction_sprite_num = -1;
    short construction_sound_num = -1;

    rge_read(param_1, &construction_sprite_num, 2);
    rge_read(param_1, &this->building_connect_flag, 1);
    rge_read(param_1, &this->building_facet, 2);
    rge_read(param_1, &this->build_and_go_away, 1);
    rge_read(param_1, &this->on_build_make_obj, 2);
    rge_read(param_1, &this->on_build_make_tile, 2);
    rge_read(param_1, &this->on_build_make_overlay, 2);
    rge_read(param_1, &this->on_build_make_tech, 2);
    rge_read(param_1, &construction_sound_num, 2);

    if (construction_sprite_num >= 0 && param_2 != nullptr) {
        this->construction_sprite = param_2[construction_sprite_num];
    } else {
        this->construction_sprite = nullptr;
    }

    if (construction_sound_num >= 0 && param_3 != nullptr) {
        this->construction_sound = param_3[construction_sound_num];
    } else {
        this->construction_sound = nullptr;
    }

    return 1;
}

// Fully verified. Source of truth: tm_b_obj.cpp.decomp @ 0x0050E360
int TRIBE_Master_Building_Object::setup(FILE* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4) {
    this->TRIBE_Master_Combat_Object::setup(param_1, param_2, param_3, param_4);
    this->master_type = 0x50;

    short construction_sprite_num = -1;
    short connect_flag = 0;
    short go_away = 0;
    short construction_sound_num = -1;

    fscanf(param_1, " %hd %hd %hd %hd %hd %hd %hd %hd %hd",
           &construction_sprite_num,
           &connect_flag,
           &this->building_facet,
           &go_away,
           &this->on_build_make_obj,
           &this->on_build_make_tile,
           &this->on_build_make_overlay,
           &this->on_build_make_tech,
           &construction_sound_num);

    this->building_connect_flag = (uchar)connect_flag;
    this->build_and_go_away = (uchar)go_away;

    if (construction_sprite_num >= 0 && param_2 != nullptr) {
        this->construction_sprite = param_2[construction_sprite_num];
    } else {
        this->construction_sprite = nullptr;
    }

    if (construction_sound_num >= 0 && param_3 != nullptr) {
        this->construction_sound = param_3[construction_sound_num];
    } else {
        this->construction_sound = nullptr;
    }

    return 1;
}

// Fully verified. Source of truth: tm_b_obj.cpp.decomp @ 0x0050E430
TRIBE_Master_Building_Object::~TRIBE_Master_Building_Object() {}

// Fully verified. Source of truth: tm_b_obj.cpp.decomp @ 0x0050E440
void TRIBE_Master_Building_Object::copy_obj(RGE_Master_Static_Object* param_1) {
    if (param_1 == nullptr) {
        return;
    }

    this->TRIBE_Master_Combat_Object::copy_obj(param_1);

    TRIBE_Master_Building_Object* src = (TRIBE_Master_Building_Object*)param_1;
    this->construction_sprite = src->construction_sprite;
    this->construction_sound = src->construction_sound;
    this->building_connect_flag = src->building_connect_flag;
    this->building_facet = src->building_facet;
    this->build_and_go_away = src->build_and_go_away;
    this->on_build_make_obj = src->on_build_make_obj;
    this->on_build_make_tile = src->on_build_make_tile;
    this->on_build_make_overlay = src->on_build_make_overlay;
    this->on_build_make_tech = src->on_build_make_tech;
}

// Fully verified. Source of truth: tm_b_obj.cpp.decomp @ 0x0050E4D0
void TRIBE_Master_Building_Object::modify(float param_1, uchar param_2) {
    if (param_2 != '\x11') {
        this->TRIBE_Master_Combat_Object::modify(param_1, param_2);
        return;
    }

    this->building_facet = (short)rge_ftol(param_1);
}

// Fully verified. Source of truth: tm_b_obj.cpp.decomp @ 0x0050E500
void TRIBE_Master_Building_Object::modify_delta(float param_1, uchar param_2) {
    if (param_2 != '\x11') {
        this->TRIBE_Master_Combat_Object::modify_delta(param_1, param_2);
        return;
    }

    this->building_facet = (short)(this->building_facet + (short)rge_ftol(param_1));
}

// Fully verified. Source of truth: tm_b_obj.cpp.decomp @ 0x0050E530
void TRIBE_Master_Building_Object::modify_percent(float param_1, uchar param_2) {
    this->TRIBE_Master_Combat_Object::modify_percent(param_1, param_2);
}

// Fully verified. Source of truth: tm_b_obj.cpp.decomp @ 0x0050E550
void TRIBE_Master_Building_Object::save(int param_1) {
    this->TRIBE_Master_Combat_Object::save(param_1);

    short construction_sprite_num = -1;
    short construction_sound_num = -1;

    if (this->construction_sprite != nullptr) {
        construction_sprite_num = this->construction_sprite->id;
    }

    if (this->construction_sound != nullptr) {
        construction_sound_num = this->construction_sound->id;
    }

    rge_write(param_1, &construction_sprite_num, 2);
    rge_write(param_1, &this->building_connect_flag, 1);
    rge_write(param_1, &this->building_facet, 2);
    rge_write(param_1, &this->build_and_go_away, 1);
    rge_write(param_1, &this->on_build_make_obj, 2);
    rge_write(param_1, &this->on_build_make_tile, 2);
    rge_write(param_1, &this->on_build_make_overlay, 2);
    rge_write(param_1, &this->on_build_make_tech, 2);
    rge_write(param_1, &construction_sound_num, 2);
}

// Fully verified. Source of truth: tm_b_obj.cpp.decomp @ 0x0050E6B0, tm_b_obj.cpp.asm @ 0x0050E6B0
RGE_Static_Object* TRIBE_Master_Building_Object::make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4) {
    TRIBE_Building_Object* obj = new (std::nothrow) TRIBE_Building_Object(this, param_1, param_2, param_3, param_4, 1);
    return (RGE_Static_Object*)obj;
}

// Fully verified. Source of truth: tm_b_obj.cpp.decomp @ 0x0050E730
RGE_Master_Static_Object* TRIBE_Master_Building_Object::make_new_master() {
    TRIBE_Master_Building_Object* master = new (std::nothrow) TRIBE_Master_Building_Object(this, 1);
    return (RGE_Master_Static_Object*)master;
}

uchar TRIBE_Master_Building_Object::check_placement(RGE_Player* param_1, float param_2, float param_3, int* param_4, uchar param_5, uchar param_6, uchar param_7, uchar param_8, uchar param_9, uchar param_10) { return this->RGE_Master_Static_Object::check_placement(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }

// Fully verified. Source of truth: tm_b_obj.cpp.decomp @ 0x0050E950
uchar TRIBE_Master_Building_Object::alignment(float* param_1, float* param_2, RGE_Game_World* param_3, uchar param_4) {
    return this->RGE_Master_Static_Object::alignment(param_1, param_2, param_3, 1);
}

long TRIBE_Master_Building_Object::calc_base_damage_ability(RGE_Master_Combat_Object* param_1) { return this->RGE_Master_Static_Object::calc_base_damage_ability(param_1); }
void TRIBE_Master_Building_Object::play_command_sound() { this->RGE_Master_Static_Object::play_command_sound(); }
void TRIBE_Master_Building_Object::play_move_sound() { this->RGE_Master_Static_Object::play_move_sound(); }

// Fully verified. Source of truth: tm_b_obj.cpp.decomp @ 0x0050E7A0, tm_b_obj.cpp.asm @ 0x0050E7A0
void TRIBE_Master_Building_Object::draw(TDrawArea* param_1, short param_2, short param_3, RGE_Color_Table* param_4, long param_5, long param_6, int param_7, uchar param_8) {
    if (this->sprite == nullptr) {
        return;
    }

    int frame = 0;
    if (this->building_connect_flag == 0) {
        frame = (int)this->building_facet;
    } else if (param_5 == 0) {
        frame = 2;
    } else {
        frame = (int)(param_5 - 1);
    }

    int draw_line = (int)param_3;
    this->sprite->draw(frame, 0, (int)param_2, draw_line, (int)param_2, draw_line, param_4, param_1, '\0');

    if (param_7 != 0) {
        RGE_Map* map = rge_base_game->world->map;
        float rx = this->outline_radius_x;
        float ry = this->outline_radius_y;

        short x1 = 0;
        short y1 = 0;
        short x2 = 0;
        short y2 = 0;
        short x3 = 0;
        short y3 = 0;
        short x4 = 0;
        short y4 = 0;

        map->get_point(&x1, &y1, rx, -ry, 0.0f, param_2, param_3);
        map->get_point(&x2, &y2, rx, ry, 0.0f, param_2, param_3);
        map->get_point(&x3, &y3, -rx, ry, 0.0f, param_2, param_3);
        map->get_point(&x4, &y4, -rx, -ry, 0.0f, param_2, param_3);

        SDI_List->AddGDINode(1,
                             draw_line,
                             (int)x1,
                             (int)y1,
                             (int)x2,
                             (int)y2,
                             (int)x3,
                             (int)y3,
                             (int)x4,
                             (int)y4,
                             10,
                             (int)(param_8 & 0xFF),
                             (int)SDI_Object_ID);
    }
}

RGE_Task_List* TRIBE_Master_Building_Object::create_task_list() { return this->TRIBE_Master_Combat_Object::create_task_list(); }

// Fully verified. Source of truth: tm_b_obj.cpp.decomp @ 0x0050E630, tm_b_obj.cpp.asm @ 0x0050E630
RGE_Static_Object* TRIBE_Master_Building_Object::make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4, int param_5) {
    TRIBE_Building_Object* obj = new (std::nothrow) TRIBE_Building_Object(this, param_1, param_2, param_3, param_4, param_5, 1);
    return (RGE_Static_Object*)obj;
}
