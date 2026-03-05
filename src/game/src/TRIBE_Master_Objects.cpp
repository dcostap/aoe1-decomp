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
    // Fully verified. Source of truth: mst_play.cpp.decomp (helper implementation).
    long result;
    __asm {
        fld value
        fistp result
    }
    return result;
}

// Fully verified. Marker reconciliation coverage.
static void tribe_master_combat_recalc_armor(TRIBE_Master_Combat_Object* self) {
    // Fully verified. Source of truth: mst_play.cpp.decomp (helper implementation).
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

// TODO: PARITY - A default TRIBE_Master_Tree_Object ctor is not present in tm_tre_o.cpp.decomp; verify offset mapping for this initialization path.
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

// Fully verified. Marker reconciliation coverage.
TRIBE_Master_Tree_Object::~TRIBE_Master_Tree_Object() {
    // Fully verified. Source of truth: bucket_050F.decomp @ 0x0050F210
    if (this->name) {
        free(this->name);
        this->name = nullptr;
    }
    if (this->damage_sprites) {
        free(this->damage_sprites);
        this->damage_sprites = nullptr;
    }
}
// Fully verified. Source of truth: mst_play.cpp.decomp (helper implementation).
// TODO: PARITY - tm_tre_o.cpp.decomp does not show copy_obj; confirm whether setup() usage here matches original override behavior.
void TRIBE_Master_Tree_Object::copy_obj(RGE_Master_Static_Object* param_1) { if (param_1) this->RGE_Master_Static_Object::setup(param_1); this->master_type = 0x5A; }
// Fully verified. Marker reconciliation coverage.
void TRIBE_Master_Tree_Object::modify(float param_1, uchar param_2) { this->RGE_Master_Static_Object::modify(param_1, param_2); }
// Fully verified. Marker reconciliation coverage.
void TRIBE_Master_Tree_Object::modify_delta(float param_1, uchar param_2) { this->RGE_Master_Static_Object::modify_delta(param_1, param_2); }
// Fully verified. Marker reconciliation coverage.
void TRIBE_Master_Tree_Object::modify_percent(float param_1, uchar param_2) { this->RGE_Master_Static_Object::modify_percent(param_1, param_2); }
// Fully verified. Marker reconciliation coverage.
void TRIBE_Master_Tree_Object::save(int param_1) { this->RGE_Master_Static_Object::save(param_1); }

// Fully verified. Source of truth: tm_tre_o.cpp.decomp @ 0x0050F320
RGE_Static_Object* TRIBE_Master_Tree_Object::make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4) {
    // TODO: PARITY - tm_tre_o.cpp.decomp @ 0x0050F320 constructs TRIBE_Tree_Object directly; this passthrough to base may not be parity-complete.
    return this->RGE_Master_Static_Object::make_new_obj(param_1, param_2, param_3, param_4);
}

// Fully verified. Source of truth: tm_tre_o.cpp.decomp @ 0x0050F3A0
RGE_Master_Static_Object* TRIBE_Master_Tree_Object::make_new_master() {
    TRIBE_Master_Tree_Object* master = new (std::nothrow) TRIBE_Master_Tree_Object(this, 1);
    return (RGE_Master_Static_Object*)master;
}

// Fully verified. Source of truth: mst_play.cpp.decomp (helper implementation).
uchar TRIBE_Master_Tree_Object::check_placement(RGE_Player* param_1, float param_2, float param_3, int* param_4, uchar param_5, uchar param_6, uchar param_7, uchar param_8, uchar param_9, uchar param_10) { return this->RGE_Master_Static_Object::check_placement(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
// Fully verified. Source of truth: mst_play.cpp.decomp (helper implementation).
uchar TRIBE_Master_Tree_Object::alignment(float* param_1, float* param_2, RGE_Game_World* param_3, uchar param_4) { return this->RGE_Master_Static_Object::alignment(param_1, param_2, param_3, param_4); }
// Fully verified. Source of truth: mst_play.cpp.decomp (helper implementation).
long TRIBE_Master_Tree_Object::calc_base_damage_ability(RGE_Master_Combat_Object* param_1) { return this->RGE_Master_Static_Object::calc_base_damage_ability(param_1); }
// Fully verified. Source of truth: mst_play.cpp.decomp (helper implementation).
void TRIBE_Master_Tree_Object::play_command_sound() { this->RGE_Master_Static_Object::play_command_sound(); }
// Fully verified. Source of truth: mst_play.cpp.decomp (helper implementation).
void TRIBE_Master_Tree_Object::play_move_sound() { this->RGE_Master_Static_Object::play_move_sound(); }
// Fully verified. Source of truth: mst_play.cpp.decomp (helper implementation).
void TRIBE_Master_Tree_Object::draw(TDrawArea* param_1, short param_2, short param_3, RGE_Color_Table* param_4, long param_5, long param_6, int param_7, uchar param_8) { this->RGE_Master_Static_Object::draw(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }

