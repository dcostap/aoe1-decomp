#include "../include/m_mi_obj.h"

extern "C" {
    void rge_read(int fd, void* buffer, int size);
    void rge_write(int fd, void* buffer, int size);
}

RGE_Master_Missile_Object::RGE_Master_Missile_Object(
    RGE_Master_Missile_Object* source, int do_setup)
    : RGE_Master_Combat_Object(source, 0)
{
    if (do_setup != 0) {
        setup(source);
    }
}

RGE_Master_Missile_Object::RGE_Master_Missile_Object(
    int id, RGE_Sprite** sprites, RGE_Sound** sounds, int do_setup)
    : RGE_Master_Combat_Object(id, sprites, sounds, 0)
{
    if (do_setup != 0) {
        setup(id, sprites, sounds);
    }
}

RGE_Master_Missile_Object::RGE_Master_Missile_Object(
    FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds, short target_type,
    int do_setup)
    : RGE_Master_Combat_Object(file, sprites, sounds, target_type, 0)
{
    if (do_setup != 0) {
        setup(file, sprites, sounds, target_type);
    }
}

int RGE_Master_Missile_Object::setup(RGE_Master_Missile_Object* source)
{
    RGE_Master_Combat_Object::setup(source);
    master_type = 0x3C;
    missile_type = source->missile_type;
    targetting_type = source->targetting_type;
    missile_hit_info = source->missile_hit_info;
    missile_die_info = source->missile_die_info;
    area_effect_specials = source->area_effect_specials;
    ballistics_ratio = source->ballistics_ratio;
    return 1;
}

int RGE_Master_Missile_Object::setup(
    int id, RGE_Sprite** sprites, RGE_Sound** sounds)
{
    RGE_Master_Combat_Object::setup(id, sprites, sounds);
    master_type = 0x3C;

    rge_read(id, &missile_type, 1);
    rge_read(id, &targetting_type, 1);
    rge_read(id, &missile_hit_info, 1);
    rge_read(id, &missile_die_info, 1);
    rge_read(id, &area_effect_specials, 1);
    rge_read(id, &ballistics_ratio, 4);
    return 1;
}

int RGE_Master_Missile_Object::setup(
    FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds, short target_type)
{
    short missile_type_value;
    short targetting_type_value;
    short missile_hit_info_value;
    short missile_die_info_value;
    short area_effect_specials_value;

    RGE_Master_Combat_Object::setup(file, sprites, sounds, target_type);
    recyclable = 1;
    master_type = 0x3C;

    fscanf(file, "%hd %hd %hd %hd %hd %f",
           &missile_type_value,
           &targetting_type_value,
           &missile_hit_info_value,
           &missile_die_info_value,
           &area_effect_specials_value,
           &ballistics_ratio);

    targetting_type = (unsigned char)targetting_type_value;
    missile_hit_info = (unsigned char)missile_hit_info_value;
    missile_die_info = (unsigned char)missile_die_info_value;
    area_effect_specials = (unsigned char)area_effect_specials_value;
    missile_type = (unsigned char)missile_type_value;
    return 1;
}

RGE_Master_Missile_Object::~RGE_Master_Missile_Object()
{
}

RGE_Static_Object* RGE_Master_Missile_Object::make_new_obj(
    RGE_Player* player, float x, float y, float z)
{
    if (recyclable != 0) {
        RGE_Static_Object* recycled =
            player->world->recycle_object_in_to_game(master_type);
        if (recycled != 0) {
            recycled->recycle_in_to_game(this, player, x, y, z);
            return recycled;
        }
    }

    return new RGE_Missile_Object(this, player, x, y, z, 1);
}

RGE_Master_Static_Object* RGE_Master_Missile_Object::make_new_master()
{
    return new RGE_Master_Missile_Object(this, 1);
}

void RGE_Master_Missile_Object::copy_obj(RGE_Master_Static_Object* source)
{
    RGE_Master_Combat_Object::copy_obj(source);
    RGE_Master_Missile_Object* missile_source =
        (RGE_Master_Missile_Object*)source;
    missile_type = missile_source->missile_type;
    targetting_type = missile_source->targetting_type;
    missile_hit_info = missile_source->missile_hit_info;
    missile_die_info = missile_source->missile_die_info;
    area_effect_specials = missile_source->area_effect_specials;
    ballistics_ratio = missile_source->ballistics_ratio;
}

void RGE_Master_Missile_Object::modify(float value, unsigned char attribute)
{
    if (attribute == 0x13) {
        targetting_type = (unsigned char)(int)value;
    }
    RGE_Master_Combat_Object::modify(value, attribute);
}

void RGE_Master_Missile_Object::modify_delta(
    float value, unsigned char attribute)
{
    if (attribute == 0x13) {
        targetting_type = (unsigned char)(int)value;
    }
    RGE_Master_Combat_Object::modify_delta(value, attribute);
}

void RGE_Master_Missile_Object::modify_percent(
    float value, unsigned char attribute)
{
    if (attribute == 0x13) {
        targetting_type = (unsigned char)(int)value;
    }
    RGE_Master_Combat_Object::modify_percent(value, attribute);
}

void RGE_Master_Missile_Object::save(int file_id)
{
    RGE_Master_Combat_Object::save(file_id);

    rge_write(file_id, &missile_type, 1);
    rge_write(file_id, &targetting_type, 1);
    rge_write(file_id, &missile_hit_info, 1);
    rge_write(file_id, &missile_die_info, 1);
    rge_write(file_id, &area_effect_specials, 1);
    rge_write(file_id, &ballistics_ratio, 4);
}
