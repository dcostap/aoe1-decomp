// VA: 0050E550 TRIBE_Master_Building_Object::save (224B)
// PDB source: tm_b_obj.cpp lines 189-207
// Saves building-specific fields: sprite_id, sound_id, building flags, facet, etc.
#include "..\..\include\game_globals.h"
#include "..\..\include\tm_b_obj_context.h"

#ifndef TM_B_OBJ_SHARED_CONTEXT
struct RGE_Sprite {
    char gap_00[0x72];
    short id;  // +0x72
};

struct RGE_Sound {
    char gap_00[0x0C];
    short id;  // +0x0C
};

struct TRIBE_Master_Combat_Object_Base {
    char base[0x164];
    void save(int param_1);
};

struct TRIBE_Master_Building_Object {
    char base[0x164];
    RGE_Sound* construction_sound;      // +0x164
    RGE_Sprite* construction_sprite;    // +0x168
    unsigned char building_connect_flag; // +0x16C
    short building_facet;               // +0x16E
    unsigned char build_and_go_away;     // +0x170
    short on_build_make_obj;            // +0x172
    short on_build_make_tile;           // +0x174
    short on_build_make_overlay;        // +0x176
    short on_build_make_tech;           // +0x178
    
    void save(int param_1);
};
#endif

void rge_write(int file, void* data, int size);

void TRIBE_Master_Building_Object::save(int param_1) {
    short sprite_id;
    short sound_id;
    
    ((TRIBE_Master_Combat_Object_Base*)this)->save(param_1);
    
    if (this->construction_sprite != 0) {
        sprite_id = this->construction_sprite->id;
    } else {
        sprite_id = -1;
    }
    
    if (this->construction_sound != 0) {
        sound_id = this->construction_sound->id;
    } else {
        sound_id = -1;
    }
    
    rge_write(param_1, &sprite_id, 2);
    rge_write(param_1, &this->building_connect_flag, 1);
    rge_write(param_1, &this->building_facet, 2);
    rge_write(param_1, &this->build_and_go_away, 1);
    rge_write(param_1, &this->on_build_make_obj, 2);
    rge_write(param_1, &this->on_build_make_tile, 2);
    rge_write(param_1, &this->on_build_make_overlay, 2);
    rge_write(param_1, &this->on_build_make_tech, 2);
    rge_write(param_1, &sound_id, 2);
}
