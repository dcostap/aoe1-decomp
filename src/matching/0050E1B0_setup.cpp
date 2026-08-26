// VA: 0050E1B0 TRIBE_Master_Building_Object::setup (146B)
// PDB source: tm_b_obj.cpp lines 53-69
// Copies fields from source master building object, sets a padding flag, returns 1
#include "..\..\include\game_globals.h"
#include "..\..\include\tm_b_obj_context.h"

#ifndef TM_B_OBJ_SHARED_CONTEXT
struct TRIBE_Master_Combat_Object_Base {
    char base[0x164];
    void setup(TRIBE_Master_Combat_Object_Base* src);
};

struct TRIBE_Master_Building_Object {
    char base[0x164];
    void* construction_sound;           // +0x164
    void* construction_sprite;          // +0x168
    unsigned char building_connect_flag; // +0x16C
    short building_facet;               // +0x16E
    unsigned char build_and_go_away;     // +0x170
    short on_build_make_obj;            // +0x172
    short on_build_make_tile;           // +0x174
    short on_build_make_overlay;        // +0x176
    short on_build_make_tech;           // +0x178
    
protected:
    int setup(TRIBE_Master_Building_Object* source);
};
#endif

int TRIBE_Master_Building_Object::setup(TRIBE_Master_Building_Object* source) {
    ((TRIBE_Master_Combat_Object_Base*)this)->setup((TRIBE_Master_Combat_Object_Base*)source);
    *((unsigned char*)this + 4) = 0x50;
    this->construction_sprite = source->construction_sprite;
    this->building_connect_flag = source->building_connect_flag;
    this->building_facet = source->building_facet;
    this->build_and_go_away = source->build_and_go_away;
    this->on_build_make_obj = source->on_build_make_obj;
    this->on_build_make_tile = source->on_build_make_tile;
    this->on_build_make_overlay = source->on_build_make_overlay;
    this->on_build_make_tech = source->on_build_make_tech;
    this->construction_sound = source->construction_sound;
    return 1;
}
