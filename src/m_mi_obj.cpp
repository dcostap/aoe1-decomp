#include <stdio.h>

#include "../include/m_mi_obj.h"
#include "../include/misl_obj.h"
#include "../include/player.h"
#include "../include/rge_fio.h"
#include "../include/world.h"

RGE_Master_Missile_Object::RGE_Master_Missile_Object(RGE_Master_Missile_Object* other_object, int do_setup) :
    RGE_Master_Combat_Object(other_object, 0) {
    if (do_setup != 0) {
        setup(other_object);
    }
}

RGE_Master_Missile_Object::RGE_Master_Missile_Object(
    int infile, RGE_Sprite** sprites, RGE_Sound** sounds, int do_setup
) : RGE_Master_Combat_Object(infile, sprites, sounds, 0) {
    if (do_setup != 0) {
        setup(infile, sprites, sounds);
    }
}

RGE_Master_Missile_Object::RGE_Master_Missile_Object(
    FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds, short in_id, int do_setup
) : RGE_Master_Combat_Object(infile, sprites, sounds, in_id, 0) {
    if (do_setup != 0) {
        setup(infile, sprites, sounds, in_id);
    }
}

int RGE_Master_Missile_Object::setup(RGE_Master_Missile_Object* other_object) {
    RGE_Master_Combat_Object::setup(other_object);
    master_type = 0x3C;
    missile_type = other_object->missile_type;
    targetting_type = other_object->targetting_type;
    missile_hit_info = other_object->missile_hit_info;
    missile_die_info = other_object->missile_die_info;
    area_effect_specials = other_object->area_effect_specials;
    ballistics_ratio = other_object->ballistics_ratio;
    return 1;
}

int RGE_Master_Missile_Object::setup(int infile, RGE_Sprite** sprites, RGE_Sound** sounds) {
    RGE_Master_Combat_Object::setup(infile, sprites, sounds);
    master_type = 0x3C;

    rge_read(infile, &missile_type, 1);
    rge_read(infile, &targetting_type, 1);
    rge_read(infile, &missile_hit_info, 1);
    rge_read(infile, &missile_die_info, 1);
    rge_read(infile, &area_effect_specials, 1);
    rge_read(infile, &ballistics_ratio, 4);
    return 1;
}

int RGE_Master_Missile_Object::setup(FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds, short in_id) {
    short temp_missile_type;
    short temp_targetting_type;
    short temp_missile_hit_info;
    short temp_missile_die_info;
    short temp_area_effect_specials;

    RGE_Master_Combat_Object::setup(infile, sprites, sounds, in_id);
    recyclable = 1;
    master_type = 0x3C;

    fscanf(
        infile, "%hd %hd %hd %hd %hd %f", &temp_missile_type, &temp_targetting_type, &temp_missile_hit_info,
        &temp_missile_die_info, &temp_area_effect_specials, &ballistics_ratio
    );

    targetting_type = (unsigned char) temp_targetting_type;
    missile_hit_info = (unsigned char) temp_missile_hit_info;
    missile_die_info = (unsigned char) temp_missile_die_info;
    area_effect_specials = (unsigned char) temp_area_effect_specials;
    missile_type = (unsigned char) temp_missile_type;
    return 1;
}

RGE_Master_Missile_Object::~RGE_Master_Missile_Object() {
}

RGE_Static_Object* RGE_Master_Missile_Object::make_new_obj(RGE_Player* owner, float x, float y, float z) {
    if (recyclable != 0) {
        RGE_Static_Object* recycled = owner->world->recycle_object_in_to_game(master_type);
        if (recycled != 0) {
            recycled->recycle_in_to_game(this, owner, x, y, z);
            return recycled;
        }
    }

    return new RGE_Missile_Object(this, owner, x, y, z, 1);
}

RGE_Master_Static_Object* RGE_Master_Missile_Object::make_new_master() {
    return new RGE_Master_Missile_Object(this, 1);
}

void RGE_Master_Missile_Object::copy_obj(RGE_Master_Static_Object* source) {
    RGE_Master_Combat_Object::copy_obj(source);
    RGE_Master_Missile_Object* missile_source = (RGE_Master_Missile_Object*) source;
    missile_type = missile_source->missile_type;
    targetting_type = missile_source->targetting_type;
    missile_hit_info = missile_source->missile_hit_info;
    missile_die_info = missile_source->missile_die_info;
    area_effect_specials = missile_source->area_effect_specials;
    ballistics_ratio = missile_source->ballistics_ratio;
}

void RGE_Master_Missile_Object::modify(float amount, unsigned char flag) {
    if (flag == 0x13) {
        targetting_type = (unsigned char) (int) amount;
    }
    RGE_Master_Combat_Object::modify(amount, flag);
}

void RGE_Master_Missile_Object::modify_delta(float amount, unsigned char flag) {
    if (flag == 0x13) {
        targetting_type = (unsigned char) (int) amount;
    }
    RGE_Master_Combat_Object::modify_delta(amount, flag);
}

void RGE_Master_Missile_Object::modify_percent(float amount, unsigned char flag) {
    if (flag == 0x13) {
        targetting_type = (unsigned char) (int) amount;
    }
    RGE_Master_Combat_Object::modify_percent(amount, flag);
}

void RGE_Master_Missile_Object::save(int outfile) {
    RGE_Master_Combat_Object::save(outfile);

    rge_write(outfile, &missile_type, 1);
    rge_write(outfile, &targetting_type, 1);
    rge_write(outfile, &missile_hit_info, 1);
    rge_write(outfile, &missile_die_info, 1);
    rge_write(outfile, &area_effect_specials, 1);
    rge_write(outfile, &ballistics_ratio, 4);
}
