#include "../include/m_mo_obj.h"
#include "../include/move_obj.h"
#include "../include/player.h"
#include "../include/sprite.h"
#include "../include/stat_obj.h"
#include "../include/world.h"

extern "C" void rge_read(int file, void* data, int size);
extern "C" void rge_write(int file, void* data, int size);

RGE_Master_Moving_Object::RGE_Master_Moving_Object(
    RGE_Master_Moving_Object* source, int do_setup)
    : RGE_Master_Animated_Object(source, 0)
{
    if (do_setup) {
        setup(source);
    }
}

RGE_Master_Moving_Object::RGE_Master_Moving_Object(
    int id, RGE_Sprite** sprites, RGE_Sound** sounds, int do_setup)
    : RGE_Master_Animated_Object(id, sprites, sounds, 0)
{
    if (do_setup) {
        setup(id, sprites, sounds);
    }
}

RGE_Master_Moving_Object::RGE_Master_Moving_Object(
    FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds, short index,
    int do_setup)
    : RGE_Master_Animated_Object(file, sprites, sounds, index, 0)
{
    if (do_setup) {
        setup(file, sprites, sounds, index);
    }
}

int RGE_Master_Moving_Object::setup(RGE_Master_Moving_Object* source)
{
    RGE_Master_Animated_Object::setup(source);
    master_type = 0x1E;

    move_sprite = source->move_sprite;
    run_sprite = source->run_sprite;
    turn_speed = source->turn_speed;
    size_class = source->size_class;
    obj_trail_id = source->obj_trail_id;
    obj_trail_options = source->obj_trail_options;
    obj_trail_spacing = source->obj_trail_spacing;
    move_algorithem = source->move_algorithem;

    return 1;
}

int RGE_Master_Moving_Object::setup(
    int file, RGE_Sprite** sprites, RGE_Sound** sounds)
{
    RGE_Master_Animated_Object::setup(file, sprites, sounds);

    short move_sprite_id;
    short run_sprite_id;
    RGE_Sprite* selected_move;
    RGE_Sprite* selected_run;

    master_type = 0x1E;

    rge_read(file, &move_sprite_id, 2);
    rge_read(file, &run_sprite_id, 2);
    rge_read(file, &turn_speed, 4);
    rge_read(file, &size_class, 1);
    rge_read(file, &obj_trail_id, 2);
    rge_read(file, &obj_trail_options, 1);
    rge_read(file, &obj_trail_spacing, 4);
    rge_read(file, &move_algorithem, 1);

    if (move_sprite_id >= 0) {
        selected_move = sprites[move_sprite_id];
    } else {
        selected_move = 0;
    }
    move_sprite = selected_move;

    if (run_sprite_id >= 0) {
        selected_run = sprites[run_sprite_id];
    } else {
        selected_run = 0;
    }
    run_sprite = selected_run;

    return 1;
}

int RGE_Master_Moving_Object::setup(
    FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds, short index)
{
    RGE_Master_Animated_Object::setup(file, sprites, sounds, index);

    short move_sprite_id;
    short run_sprite_id;
    short size_class_out;
    short obj_trail_options_out;
    short move_algorithem_out;
    RGE_Sprite* selected_move;
    RGE_Sprite* selected_run;

    master_type = 0x1E;

    fscanf(file, "%hd %hd %f %hd %hd %hd %f %hd",
           &move_sprite_id, &run_sprite_id, &turn_speed, &size_class_out,
           &obj_trail_id, &obj_trail_options_out,
           &obj_trail_spacing, &move_algorithem_out);

    size_class = (unsigned char)size_class_out;
    move_algorithem = (unsigned char)move_algorithem_out;
    obj_trail_options = (unsigned char)obj_trail_options_out;

    if (move_sprite_id >= 0) {
        selected_move = sprites[move_sprite_id];
    } else {
        selected_move = 0;
    }
    move_sprite = selected_move;

    if (run_sprite_id >= 0) {
        selected_run = sprites[run_sprite_id];
    } else {
        selected_run = 0;
    }
    run_sprite = selected_run;

    return 1;
}

RGE_Master_Moving_Object::~RGE_Master_Moving_Object()
{
}

RGE_Static_Object* RGE_Master_Moving_Object::make_new_obj(
    RGE_Player* player, float x, float y, float z)
{
    if (recyclable) {
        RGE_Static_Object* recycled =
            player->world->recycle_object_in_to_game(master_type);
        if (recycled) {
            recycled->recycle_in_to_game(this, player, x, y, z);
            return recycled;
        }
    }

    return new RGE_Moving_Object(this, player, x, y, z, 1);
}

RGE_Master_Static_Object* RGE_Master_Moving_Object::make_new_master()
{
    return new RGE_Master_Moving_Object(this, 1);
}

void RGE_Master_Moving_Object::copy_obj(RGE_Master_Static_Object* source)
{
    RGE_Master_Animated_Object::copy_obj(source);

    RGE_Master_Moving_Object* moving_source =
        static_cast<RGE_Master_Moving_Object*>(source);
    move_sprite = moving_source->move_sprite;
    run_sprite = moving_source->run_sprite;
    turn_speed = moving_source->turn_speed;
    size_class = moving_source->size_class;
    obj_trail_id = moving_source->obj_trail_id;
    obj_trail_options = moving_source->obj_trail_options;
    obj_trail_spacing = moving_source->obj_trail_spacing;
    move_algorithem = moving_source->move_algorithem;
}

void RGE_Master_Moving_Object::modify(float value, unsigned char attribute)
{
    if (attribute != 6) {
        RGE_Master_Animated_Object::modify(value, attribute);
        return;
    }
    turn_speed = value;
}

void RGE_Master_Moving_Object::modify_delta(
    float value, unsigned char attribute)
{
    if (attribute != 6) {
        RGE_Master_Animated_Object::modify_delta(value, attribute);
        return;
    }
    turn_speed += value;
}

void RGE_Master_Moving_Object::modify_percent(
    float value, unsigned char attribute)
{
    if (attribute != 6) {
        RGE_Master_Animated_Object::modify_percent(value, attribute);
        return;
    }
    turn_speed = value * turn_speed;
}

void RGE_Master_Moving_Object::save(int file)
{
    short move_sprite_id;
    short run_sprite_id;

    if (move_sprite) {
        move_sprite_id = move_sprite->id;
    } else {
        move_sprite_id = -1;
    }

    if (run_sprite) {
        run_sprite_id = run_sprite->id;
    } else {
        run_sprite_id = -1;
    }

    RGE_Master_Animated_Object::save(file);

    rge_write(file, &move_sprite_id, 2);
    rge_write(file, &run_sprite_id, 2);
    rge_write(file, &turn_speed, 4);
    rge_write(file, &size_class, 1);
    rge_write(file, &obj_trail_id, 2);
    rge_write(file, &obj_trail_options, 1);
    rge_write(file, &obj_trail_spacing, 4);
    rge_write(file, &move_algorithem, 1);
}
