#include "../include/m_mo_obj.h"
#include "../include/move_obj.h"
#include "../include/player.h"
#include "../include/sprite.h"
#include "../include/stat_obj.h"
#include "../include/world.h"

#include "../include/rge_fio.h"

RGE_Master_Moving_Object::RGE_Master_Moving_Object(RGE_Master_Moving_Object* other_object, int do_setup) :
    RGE_Master_Animated_Object(other_object, 0) {
    if (do_setup) {
        setup(other_object);
    }
}

RGE_Master_Moving_Object::RGE_Master_Moving_Object(int infile, RGE_Sprite** sprites, RGE_Sound** sounds, int do_setup) :
    RGE_Master_Animated_Object(infile, sprites, sounds, 0) {
    if (do_setup) {
        setup(infile, sprites, sounds);
    }
}

RGE_Master_Moving_Object::RGE_Master_Moving_Object(
    FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds, short in_id, int do_setup
) : RGE_Master_Animated_Object(infile, sprites, sounds, in_id, 0) {
    if (do_setup) {
        setup(infile, sprites, sounds, in_id);
    }
}

int RGE_Master_Moving_Object::setup(RGE_Master_Moving_Object* other_object) {
    RGE_Master_Animated_Object::setup(other_object);
    master_type = RGE_MASTER_TYPE_MOVING;

    move_sprite = other_object->move_sprite;
    run_sprite = other_object->run_sprite;
    turn_speed = other_object->turn_speed;
    size_class = other_object->size_class;
    obj_trail_id = other_object->obj_trail_id;
    obj_trail_options = other_object->obj_trail_options;
    obj_trail_spacing = other_object->obj_trail_spacing;
    move_algorithem = other_object->move_algorithem;

    return 1;
}

int RGE_Master_Moving_Object::setup(int infile, RGE_Sprite** sprites, RGE_Sound** sounds) {
    RGE_Master_Animated_Object::setup(infile, sprites, sounds);

    short move_sprite_id;
    short run_sprite_id;
    RGE_Sprite* selected_move;
    RGE_Sprite* selected_run;

    master_type = RGE_MASTER_TYPE_MOVING;

    rge_read(infile, &move_sprite_id, 2);
    rge_read(infile, &run_sprite_id, 2);
    rge_read(infile, &turn_speed, 4);
    rge_read(infile, &size_class, 1);
    rge_read(infile, &obj_trail_id, 2);
    rge_read(infile, &obj_trail_options, 1);
    rge_read(infile, &obj_trail_spacing, 4);
    rge_read(infile, &move_algorithem, 1);

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

int RGE_Master_Moving_Object::setup(FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds, short in_id) {
    RGE_Master_Animated_Object::setup(infile, sprites, sounds, in_id);

    short move_sprite_id;
    short run_sprite_id;
    short temp_size_class;
    short temp_obj_trail_options;
    short temp_move_algorithem;
    RGE_Sprite* selected_move;
    RGE_Sprite* selected_run;

    master_type = RGE_MASTER_TYPE_MOVING;

    fscanf(
        infile, "%hd %hd %f %hd %hd %hd %f %hd", &move_sprite_id, &run_sprite_id, &turn_speed, &temp_size_class,
        &obj_trail_id, &temp_obj_trail_options, &obj_trail_spacing, &temp_move_algorithem
    );

    size_class = (unsigned char) temp_size_class;
    move_algorithem = (unsigned char) temp_move_algorithem;
    obj_trail_options = (unsigned char) temp_obj_trail_options;

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

RGE_Master_Moving_Object::~RGE_Master_Moving_Object() {
}

RGE_Static_Object* RGE_Master_Moving_Object::make_new_obj(RGE_Player* owner, float x, float y, float z) {
    if (recyclable) {
        RGE_Static_Object* recycled = owner->world->recycle_object_in_to_game(master_type);
        if (recycled) {
            recycled->recycle_in_to_game(this, owner, x, y, z);
            return recycled;
        }
    }

    return new RGE_Moving_Object(this, owner, x, y, z, 1);
}

RGE_Master_Static_Object* RGE_Master_Moving_Object::make_new_master() {
    return new RGE_Master_Moving_Object(this, 1);
}

void RGE_Master_Moving_Object::copy_obj(RGE_Master_Static_Object* source) {
    RGE_Master_Animated_Object::copy_obj(source);

    RGE_Master_Moving_Object* moving_source = static_cast<RGE_Master_Moving_Object*>(source);
    move_sprite = moving_source->move_sprite;
    run_sprite = moving_source->run_sprite;
    turn_speed = moving_source->turn_speed;
    size_class = moving_source->size_class;
    obj_trail_id = moving_source->obj_trail_id;
    obj_trail_options = moving_source->obj_trail_options;
    obj_trail_spacing = moving_source->obj_trail_spacing;
    move_algorithem = moving_source->move_algorithem;
}

void RGE_Master_Moving_Object::modify(float amount, unsigned char flag) {
    if (flag != 6) {
        RGE_Master_Animated_Object::modify(amount, flag);
        return;
    }
    turn_speed = amount;
}

void RGE_Master_Moving_Object::modify_delta(float amount, unsigned char flag) {
    if (flag != 6) {
        RGE_Master_Animated_Object::modify_delta(amount, flag);
        return;
    }
    turn_speed += amount;
}

void RGE_Master_Moving_Object::modify_percent(float amount, unsigned char flag) {
    if (flag != 6) {
        RGE_Master_Animated_Object::modify_percent(amount, flag);
        return;
    }
    turn_speed = amount * turn_speed;
}

void RGE_Master_Moving_Object::save(int outfile) {
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

    RGE_Master_Animated_Object::save(outfile);

    rge_write(outfile, &move_sprite_id, 2);
    rge_write(outfile, &run_sprite_id, 2);
    rge_write(outfile, &turn_speed, 4);
    rge_write(outfile, &size_class, 1);
    rge_write(outfile, &obj_trail_id, 2);
    rge_write(outfile, &obj_trail_options, 1);
    rge_write(outfile, &obj_trail_spacing, 4);
    rge_write(outfile, &move_algorithem, 1);
}
