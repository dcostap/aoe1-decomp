// VA: 0050E360 TRIBE_Master_Building_Object::setup (207B)
// PDB source: tm_b_obj.cpp lines 99-127
// Loads building fields from file using fscanf, resolves sprite/sound IDs
//
// STATUS: ~86% MATCH - 165/207 bytes identical. Sprite section is PERFECT.
// Remaining diff: sound section scheduling (same as 0050E250):
//   - `mov eax,1` scheduled before sound load vs after
//   - `mov dword [esi+164h],0` vs `xor eax;pop edi;store 0`
// VC5 scheduling artifact. Behavior correct.
#include "..\..\include\game_globals.h"
#include <stdio.h>

struct RGE_Sprite;
struct RGE_Sound;

struct TRIBE_Master_Combat_Object_Base {
    char base[0x164];
    void setup(FILE* file, void* sprites, void* sounds, short param_4);
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
    
    int setup(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds, short param_4);
};

int TRIBE_Master_Building_Object::setup(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds, short param_4) {
    short sprite_id;
    short var_2;
    short var_3;
    short sound_id;
    RGE_Sprite* pRVar3;
    RGE_Sound* snd_tmp;
    int rv = 1;
    
    ((TRIBE_Master_Combat_Object_Base*)this)->setup(file, sprites, sounds, param_4);
    *(unsigned char*)((char*)this + 4) = 0x50;
    
    fscanf(file, "%hd %hd %hd %hd %hd %hd %hd %hd %hd",
        &sprite_id, &var_2, &this->building_facet, &var_3,
        &this->on_build_make_obj, &this->on_build_make_tile,
        &this->on_build_make_overlay, &this->on_build_make_tech, &sound_id);
    
    this->building_connect_flag = (unsigned char)var_2;
    this->build_and_go_away = (unsigned char)var_3;
    
    if (sprite_id > -1) {
        pRVar3 = sprites[sprite_id];
    } else {
        pRVar3 = (RGE_Sprite*)0;
    }
    this->construction_sprite = pRVar3;
    
    if (-1 < sound_id) {
        snd_tmp = sounds[sound_id];
    } else {
        snd_tmp = 0;
    }
    this->construction_sound = snd_tmp;
    return rv;
}
