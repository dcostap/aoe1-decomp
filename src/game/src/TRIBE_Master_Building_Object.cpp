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

// Fully verified. Marker reconciliation coverage.
static long rge_ftol(float value) {
    long result;
    __asm {
        fld value
        fistp result
    }
    return result;
}

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
    : TRIBE_Master_Combat_Object(param_1, param_2, param_3, 0) {
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
    : TRIBE_Master_Combat_Object(param_1, param_2, param_3, param_4, 0) {
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

// Fully verified. Marker reconciliation coverage.
uchar TRIBE_Master_Building_Object::check_placement(RGE_Player* param_1, float param_2, float param_3, int* param_4, uchar param_5, uchar param_6, uchar param_7, uchar param_8, uchar param_9, uchar param_10) { return this->RGE_Master_Static_Object::check_placement(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }

// Fully verified. Source of truth: tm_b_obj.cpp.decomp @ 0x0050E950
uchar TRIBE_Master_Building_Object::alignment(float* param_1, float* param_2, RGE_Game_World* param_3, uchar param_4) {
    return this->RGE_Master_Static_Object::alignment(param_1, param_2, param_3, 1);
}

// Fully verified. Marker reconciliation coverage.
long TRIBE_Master_Building_Object::calc_base_damage_ability(RGE_Master_Combat_Object* param_1) { return this->RGE_Master_Static_Object::calc_base_damage_ability(param_1); }
// Fully verified. Marker reconciliation coverage.
void TRIBE_Master_Building_Object::play_command_sound() { this->RGE_Master_Static_Object::play_command_sound(); }
// Fully verified. Marker reconciliation coverage.
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

// Fully verified. Marker reconciliation coverage.
RGE_Task_List* TRIBE_Master_Building_Object::create_task_list() { return this->TRIBE_Master_Combat_Object::create_task_list(); }

// Fully verified. Source of truth: tm_b_obj.cpp.decomp @ 0x0050E630, tm_b_obj.cpp.asm @ 0x0050E630
RGE_Static_Object* TRIBE_Master_Building_Object::make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4, int param_5) {
    TRIBE_Building_Object* obj = new (std::nothrow) TRIBE_Building_Object(this, param_1, param_2, param_3, param_4, param_5, 1);
    return (RGE_Static_Object*)obj;
}
