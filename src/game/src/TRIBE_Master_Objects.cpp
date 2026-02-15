#include "../include/TRIBE_Master_Tree_Object.h"
#include "../include/TRIBE_Master_Combat_Object.h"
#include "../include/TRIBE_Master_Building_Object.h"
#include "../include/TRIBE_Task_List.h"

#include "../include/Attribute_Cost.h"
#include "../include/RGE_Armor_Weapon_Info.h"
#include "../include/RGE_Damage_Sprite_Info.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Task_List.h"
#include "../include/RGE_Player.h"

#include "../include/globals.h"

#include <string.h>

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
        } else {
            if (self->armor[i].value > self->orig_armor) {
                self->orig_armor = self->armor[i].value;
            }
        }
    }
}

TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object() : RGE_Master_Static_Object() {
    this->master_type = 0x5A;
}

TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object(TRIBE_Master_Tree_Object* param_1, int param_2)
    : RGE_Master_Static_Object((RGE_Master_Static_Object*)param_1, 0) {
    if (param_2 != 0 && param_1 != nullptr) {
        this->RGE_Master_Static_Object::setup((RGE_Master_Static_Object*)param_1);
        this->master_type = 0x5A;
    }
}

TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4)
    : RGE_Master_Static_Object(param_1, param_2, param_3, 0) {
    if (param_4 != 0) {
        this->RGE_Master_Static_Object::setup(param_1, param_2, param_3);
        this->master_type = 0x5A;
    }
}

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
RGE_Static_Object* TRIBE_Master_Tree_Object::make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4) { return this->RGE_Master_Static_Object::make_new_obj(param_1, param_2, param_3, param_4); }
RGE_Master_Static_Object* TRIBE_Master_Tree_Object::make_new_master() { return new TRIBE_Master_Tree_Object(this, 1); }
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

TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object(TRIBE_Master_Combat_Object* param_1, int param_2)
    : RGE_Master_Combat_Object((RGE_Master_Combat_Object*)param_1, (param_2 != 0) ? 1 : 0) {
    memset(this->build_inventory, 0, sizeof(this->build_inventory));
    this->build_pts_required = 0;
    this->id_of_building_obj = 0;
    this->button_location = 0;
    this->orig_pierce_armor = 0;
    this->master_type = 0x46;

    if (param_2 != 0 && param_1 != nullptr) {
        memcpy(this->build_inventory, param_1->build_inventory, sizeof(this->build_inventory));
        this->build_pts_required = param_1->build_pts_required;
        this->id_of_building_obj = param_1->id_of_building_obj;
        this->button_location = param_1->button_location;
        this->orig_pierce_armor = param_1->orig_pierce_armor;
    }
}

TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4)
    : RGE_Master_Combat_Object(param_1, param_2, param_3, (param_4 != 0) ? 1 : 0) {
    memset(this->build_inventory, 0, sizeof(this->build_inventory));
    this->build_pts_required = 0;
    this->id_of_building_obj = 0;
    this->button_location = 0;
    this->orig_pierce_armor = 0;
    this->master_type = 0x46;

    if (param_4 != 0) {
        for (int i = 0; i < 3; ++i) {
            rge_read(param_1, &this->build_inventory[i], 6);
        }
        rge_read(param_1, &this->build_pts_required, 2);
        rge_read(param_1, &this->id_of_building_obj, 2);
        rge_read(param_1, &this->button_location, 1);

        if (save_game_version >= 7.01f) {
            rge_read(param_1, &this->orig_pierce_armor, 2);
        } else {
            tribe_master_combat_recalc_armor(this);
        }
    }
}

TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object(FILE* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5)
    : RGE_Master_Combat_Object(param_1, param_2, param_3, param_4, (param_5 != 0) ? 1 : 0) {
    memset(this->build_inventory, 0, sizeof(this->build_inventory));
    this->build_pts_required = 0;
    this->id_of_building_obj = 0;
    this->button_location = 0;
    this->orig_pierce_armor = 0;
    this->master_type = 0x46;

    if (param_5 != 0) {
        short flag = 0;
        for (int i = 0; i < 3; ++i) {
            if (fscanf(param_1, " %hd %hd %hd", &this->build_inventory[i].type, &this->build_inventory[i].amount, &flag) != 3) {
                break;
            }
            this->build_inventory[i].flag = (uchar)flag;
        }

        short btn = 0;
        fscanf(param_1, " %hd %hd %hd", &this->build_pts_required, &this->id_of_building_obj, &btn);
        this->button_location = (uchar)btn;
        tribe_master_combat_recalc_armor(this);
    }
}

TRIBE_Master_Combat_Object::~TRIBE_Master_Combat_Object() {}
void TRIBE_Master_Combat_Object::copy_obj(RGE_Master_Static_Object* param_1) {
    if (param_1 == nullptr) {
        return;
    }
    this->RGE_Master_Static_Object::setup(param_1);
    TRIBE_Master_Combat_Object* src = (TRIBE_Master_Combat_Object*)param_1;
    memcpy(this->build_inventory, src->build_inventory, sizeof(this->build_inventory));
    this->build_pts_required = src->build_pts_required;
    this->id_of_building_obj = src->id_of_building_obj;
    this->button_location = src->button_location;
    this->orig_pierce_armor = src->orig_pierce_armor;
    this->master_type = 0x46;
}
void TRIBE_Master_Combat_Object::modify(float param_1, uchar param_2) { this->RGE_Master_Static_Object::modify(param_1, param_2); }
void TRIBE_Master_Combat_Object::modify_delta(float param_1, uchar param_2) { this->RGE_Master_Static_Object::modify_delta(param_1, param_2); }
void TRIBE_Master_Combat_Object::modify_percent(float param_1, uchar param_2) { this->RGE_Master_Static_Object::modify_percent(param_1, param_2); }
void TRIBE_Master_Combat_Object::save(int param_1) {}
RGE_Static_Object* TRIBE_Master_Combat_Object::make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4) { return this->RGE_Master_Static_Object::make_new_obj(param_1, param_2, param_3, param_4); }
RGE_Master_Static_Object* TRIBE_Master_Combat_Object::make_new_master() { return new TRIBE_Master_Combat_Object(this, 1); }
uchar TRIBE_Master_Combat_Object::check_placement(RGE_Player* param_1, float param_2, float param_3, int* param_4, uchar param_5, uchar param_6, uchar param_7, uchar param_8, uchar param_9, uchar param_10) { return this->RGE_Master_Static_Object::check_placement(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
uchar TRIBE_Master_Combat_Object::alignment(float* param_1, float* param_2, RGE_Game_World* param_3, uchar param_4) { return this->RGE_Master_Static_Object::alignment(param_1, param_2, param_3, param_4); }
long TRIBE_Master_Combat_Object::calc_base_damage_ability(RGE_Master_Combat_Object* param_1) { return this->RGE_Master_Static_Object::calc_base_damage_ability(param_1); }
void TRIBE_Master_Combat_Object::play_command_sound() { this->RGE_Master_Static_Object::play_command_sound(); }
void TRIBE_Master_Combat_Object::play_move_sound() { this->RGE_Master_Static_Object::play_move_sound(); }
void TRIBE_Master_Combat_Object::draw(TDrawArea* param_1, short param_2, short param_3, RGE_Color_Table* param_4, long param_5, long param_6, int param_7, uchar param_8) { this->RGE_Master_Static_Object::draw(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
RGE_Task_List* TRIBE_Master_Combat_Object::create_task_list() { return new TRIBE_Task_List(); }

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

TRIBE_Master_Building_Object::TRIBE_Master_Building_Object(TRIBE_Master_Building_Object* param_1, int param_2)
    : TRIBE_Master_Combat_Object((TRIBE_Master_Combat_Object*)param_1, (param_2 != 0) ? 1 : 0) {
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

    if (param_2 != 0 && param_1 != nullptr) {
        this->construction_sound = param_1->construction_sound;
        this->construction_sprite = param_1->construction_sprite;
        this->building_connect_flag = param_1->building_connect_flag;
        this->building_facet = param_1->building_facet;
        this->build_and_go_away = param_1->build_and_go_away;
        this->on_build_make_obj = param_1->on_build_make_obj;
        this->on_build_make_tile = param_1->on_build_make_tile;
        this->on_build_make_overlay = param_1->on_build_make_overlay;
        this->on_build_make_tech = param_1->on_build_make_tech;
        this->master_type = 0x50;
    }
}

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
        short construction_sprite_idx = -1;
        short construction_sound_idx = -1;
        rge_read(param_1, &construction_sprite_idx, 2);
        rge_read(param_1, &this->building_connect_flag, 1);
        rge_read(param_1, &this->building_facet, 2);
        rge_read(param_1, &this->build_and_go_away, 1);
        rge_read(param_1, &this->on_build_make_obj, 2);
        rge_read(param_1, &this->on_build_make_tile, 2);
        rge_read(param_1, &this->on_build_make_overlay, 2);
        rge_read(param_1, &this->on_build_make_tech, 2);
        rge_read(param_1, &construction_sound_idx, 2);

        this->construction_sprite = (construction_sprite_idx >= 0 && param_2 != nullptr) ? param_2[construction_sprite_idx] : nullptr;
        this->construction_sound = (construction_sound_idx >= 0 && param_3 != nullptr) ? param_3[construction_sound_idx] : nullptr;
        this->master_type = 0x50;
    }
}

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
        short construction_sprite_idx = -1;
        short construction_sound_idx = -1;
        short connect = 0;
        short go_away = 0;
        fscanf(param_1, " %hd %hd %hd %hd %hd %hd %hd %hd %hd",
            &construction_sprite_idx,
            &connect,
            &this->building_facet,
            &go_away,
            &this->on_build_make_obj,
            &this->on_build_make_tile,
            &this->on_build_make_overlay,
            &this->on_build_make_tech,
            &construction_sound_idx);

        this->building_connect_flag = (uchar)connect;
        this->build_and_go_away = (uchar)go_away;
        this->construction_sprite = (construction_sprite_idx >= 0 && param_2 != nullptr) ? param_2[construction_sprite_idx] : nullptr;
        this->construction_sound = (construction_sound_idx >= 0 && param_3 != nullptr) ? param_3[construction_sound_idx] : nullptr;
        this->master_type = 0x50;
    }
}

TRIBE_Master_Building_Object::~TRIBE_Master_Building_Object() {}
void TRIBE_Master_Building_Object::copy_obj(RGE_Master_Static_Object* param_1) {
    if (param_1 == nullptr) {
        return;
    }
    this->TRIBE_Master_Combat_Object::copy_obj(param_1);
    TRIBE_Master_Building_Object* src = (TRIBE_Master_Building_Object*)param_1;
    this->construction_sound = src->construction_sound;
    this->construction_sprite = src->construction_sprite;
    this->building_connect_flag = src->building_connect_flag;
    this->building_facet = src->building_facet;
    this->build_and_go_away = src->build_and_go_away;
    this->on_build_make_obj = src->on_build_make_obj;
    this->on_build_make_tile = src->on_build_make_tile;
    this->on_build_make_overlay = src->on_build_make_overlay;
    this->on_build_make_tech = src->on_build_make_tech;
    this->master_type = 0x50;
}
void TRIBE_Master_Building_Object::modify(float param_1, uchar param_2) { this->TRIBE_Master_Combat_Object::modify(param_1, param_2); }
void TRIBE_Master_Building_Object::modify_delta(float param_1, uchar param_2) { this->TRIBE_Master_Combat_Object::modify_delta(param_1, param_2); }
void TRIBE_Master_Building_Object::modify_percent(float param_1, uchar param_2) { this->TRIBE_Master_Combat_Object::modify_percent(param_1, param_2); }
void TRIBE_Master_Building_Object::save(int param_1) {}
RGE_Static_Object* TRIBE_Master_Building_Object::make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4) { return this->RGE_Master_Static_Object::make_new_obj(param_1, param_2, param_3, param_4); }
RGE_Master_Static_Object* TRIBE_Master_Building_Object::make_new_master() { return new TRIBE_Master_Building_Object(this, 1); }
uchar TRIBE_Master_Building_Object::check_placement(RGE_Player* param_1, float param_2, float param_3, int* param_4, uchar param_5, uchar param_6, uchar param_7, uchar param_8, uchar param_9, uchar param_10) { return this->RGE_Master_Static_Object::check_placement(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
uchar TRIBE_Master_Building_Object::alignment(float* param_1, float* param_2, RGE_Game_World* param_3, uchar param_4) { return this->RGE_Master_Static_Object::alignment(param_1, param_2, param_3, 1); }
long TRIBE_Master_Building_Object::calc_base_damage_ability(RGE_Master_Combat_Object* param_1) { return this->RGE_Master_Static_Object::calc_base_damage_ability(param_1); }
void TRIBE_Master_Building_Object::play_command_sound() { this->RGE_Master_Static_Object::play_command_sound(); }
void TRIBE_Master_Building_Object::play_move_sound() { this->RGE_Master_Static_Object::play_move_sound(); }
void TRIBE_Master_Building_Object::draw(TDrawArea* param_1, short param_2, short param_3, RGE_Color_Table* param_4, long param_5, long param_6, int param_7, uchar param_8) { this->RGE_Master_Static_Object::draw(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
RGE_Task_List* TRIBE_Master_Building_Object::create_task_list() { return this->TRIBE_Master_Combat_Object::create_task_list(); }
RGE_Static_Object* TRIBE_Master_Building_Object::make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4, int param_5) { return this->make_new_obj(param_1, param_2, param_3, param_4); }
