// VA: 0050E250 TRIBE_Master_Building_Object::setup (271B)
// PDB source: tm_b_obj.cpp lines 73-95
// Loads building-specific fields from file using rge_read, resolves sprite/sound IDs
#include "..\..\include\game_globals.h"
#include "..\..\include\tm_b_obj_context.h"

#ifndef TM_B_OBJ_SHARED_CONTEXT
struct RGE_Sprite;
struct RGE_Sound;

struct TRIBE_Master_Combat_Object_Base {
    char base[0x164];
    void setup(int file, void* sprites, void* sounds);
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
    
    int setup(int file, RGE_Sprite** sprites, RGE_Sound** sounds);
};
#endif

void rge_read(int file, void* data, int size);

int TRIBE_Master_Building_Object::setup(int file, RGE_Sprite** sprites, RGE_Sound** sounds) {
    short sound_id;
    short sprite_id;
    RGE_Sprite* pRVar3;
    RGE_Sound* snd_tmp;
    int rv = 1;
    
    ((TRIBE_Master_Combat_Object_Base*)this)->setup(file, sprites, sounds);
    *(unsigned char*)((char*)this + 4) = 0x50;
    
    rge_read(file, &sound_id, 2);
    rge_read(file, &this->building_connect_flag, 1);
    rge_read(file, &this->building_facet, 2);
    rge_read(file, &this->build_and_go_away, 1);
    rge_read(file, &this->on_build_make_obj, 2);
    rge_read(file, &this->on_build_make_tile, 2);
    rge_read(file, &this->on_build_make_overlay, 2);
    rge_read(file, &this->on_build_make_tech, 2);
    rge_read(file, &sprite_id, 2);
    
    if (sound_id > -1) {
        pRVar3 = sprites[sound_id];
    } else {
        pRVar3 = (RGE_Sprite*)0;
    }
    this->construction_sprite = pRVar3;
    
    if (-1 < sprite_id) {
        snd_tmp = sounds[sprite_id];
    } else {
        snd_tmp = 0;
    }
    this->construction_sound = snd_tmp;
    return rv;
}
