
#include "../include/tm_b_obj.h"
#include "../include/basegame.h"
#include "../include/color.h"
#include "../include/map.h"
#include "../include/rge_fio.h"
#include "../include/sound.h"
#include "../include/sprite.h"
#include "../include/t_b_obj.h"
#include "../include/view.h"
#include "../include/world.h"

#include <stdio.h>

extern RGE_Base_Game* rge_base_game;

TRIBE_Master_Building_Object::TRIBE_Master_Building_Object(
    TRIBE_Master_Building_Object* other_object, int do_setup)
    : TRIBE_Master_Combat_Object(
          static_cast<TRIBE_Master_Combat_Object*>(other_object), 0) {
    if (do_setup != 0) {
        setup(other_object);
    }
}

TRIBE_Master_Building_Object::TRIBE_Master_Building_Object(
    int infile, RGE_Sprite** sprites, RGE_Sound** sounds, int do_setup)
    : TRIBE_Master_Combat_Object(infile, sprites, sounds, 0) {
    if (do_setup != 0) {
        this->setup(infile, sprites, sounds);
    }
}

TRIBE_Master_Building_Object::TRIBE_Master_Building_Object(
    FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds, short in_id,
    int do_setup)
    : TRIBE_Master_Combat_Object(infile, sprites, sounds, in_id, 0) {
    if (do_setup != 0) {
        this->setup(infile, sprites, sounds, in_id);
    }
}

int TRIBE_Master_Building_Object::setup(
    TRIBE_Master_Building_Object* other_object) {
    TRIBE_Master_Combat_Object::setup(other_object);
    this->master_type = 0x50;
    this->construction_sprite = other_object->construction_sprite;
    this->building_connect_flag = other_object->building_connect_flag;
    this->building_facet = other_object->building_facet;
    this->build_and_go_away = other_object->build_and_go_away;
    this->on_build_make_obj = other_object->on_build_make_obj;
    this->on_build_make_tile = other_object->on_build_make_tile;
    this->on_build_make_overlay = other_object->on_build_make_overlay;
    this->on_build_make_tech = other_object->on_build_make_tech;
    this->construction_sound = other_object->construction_sound;
    return 1;
}

int TRIBE_Master_Building_Object::setup(
    int infile, RGE_Sprite** sprites, RGE_Sound** sounds) {
    short sprite_id;
    short sound_id;
    RGE_Sprite* selected_sprite;
    RGE_Sound* selected_sound;

    TRIBE_Master_Combat_Object::setup(infile, sprites, sounds);
    this->master_type = 0x50;

    rge_read(infile, &sprite_id, 2);
    rge_read(infile, &this->building_connect_flag, 1);
    rge_read(infile, &this->building_facet, 2);
    rge_read(infile, &this->build_and_go_away, 1);
    rge_read(infile, &this->on_build_make_obj, 2);
    rge_read(infile, &this->on_build_make_tile, 2);
    rge_read(infile, &this->on_build_make_overlay, 2);
    rge_read(infile, &this->on_build_make_tech, 2);
    rge_read(infile, &sound_id, 2);

    if (sprite_id > -1) {
        selected_sprite = sprites[sprite_id];
    } else {
        selected_sprite = 0;
    }
    this->construction_sprite = selected_sprite;

    if (sound_id > -1) {
        selected_sound = sounds[sound_id];
    } else {
        selected_sound = 0;
    }
    this->construction_sound = selected_sound;
    return 1;
}

int TRIBE_Master_Building_Object::setup(
    FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds, short in_id) {
    short sprite_id;
    short connect_flag;
    short build_and_go_away;
    short sound_id;
    RGE_Sprite* selected_sprite;
    RGE_Sound* selected_sound;

    TRIBE_Master_Combat_Object::setup(infile, sprites, sounds, in_id);
    this->master_type = 0x50;

    fscanf(infile, "%hd %hd %hd %hd %hd %hd %hd %hd %hd",
           &sprite_id, &connect_flag, &this->building_facet,
           &build_and_go_away, &this->on_build_make_obj,
           &this->on_build_make_tile, &this->on_build_make_overlay,
           &this->on_build_make_tech, &sound_id);

    this->building_connect_flag = static_cast<unsigned char>(connect_flag);
    this->build_and_go_away = static_cast<unsigned char>(build_and_go_away);

    if (sprite_id > -1) {
        selected_sprite = sprites[sprite_id];
    } else {
        selected_sprite = 0;
    }
    this->construction_sprite = selected_sprite;

    if (sound_id > -1) {
        selected_sound = sounds[sound_id];
    } else {
        selected_sound = 0;
    }
    this->construction_sound = selected_sound;
    return 1;
}

TRIBE_Master_Building_Object::~TRIBE_Master_Building_Object() {
}

void TRIBE_Master_Building_Object::copy_obj(RGE_Master_Static_Object* source) {
    TRIBE_Master_Combat_Object::copy_obj(source);

    // This virtual copy path receives a building-master source.
    TRIBE_Master_Building_Object* building_source =
        static_cast<TRIBE_Master_Building_Object*>(source);
    this->construction_sprite = building_source->construction_sprite;
    this->construction_sound = building_source->construction_sound;
    this->building_connect_flag = building_source->building_connect_flag;
    this->building_facet = building_source->building_facet;
    this->build_and_go_away = building_source->build_and_go_away;
    this->on_build_make_obj = building_source->on_build_make_obj;
    this->on_build_make_tile = building_source->on_build_make_tile;
    this->on_build_make_overlay = building_source->on_build_make_overlay;
    this->on_build_make_tech = building_source->on_build_make_tech;
}

void TRIBE_Master_Building_Object::modify(
    float amount, unsigned char flag) {
    if (flag != 0x11) {
        TRIBE_Master_Combat_Object::modify(amount, flag);
        return;
    }
    this->building_facet = static_cast<short>(amount);
}

void TRIBE_Master_Building_Object::modify_delta(
    float amount, unsigned char flag) {
    if (flag != 0x11) {
        TRIBE_Master_Combat_Object::modify_delta(amount, flag);
        return;
    }
    this->building_facet += static_cast<short>(amount);
}

void TRIBE_Master_Building_Object::modify_percent(
    float amount, unsigned char flag) {
    TRIBE_Master_Combat_Object::modify_percent(amount, flag);
}

void TRIBE_Master_Building_Object::save(int outfile) {
    short sprite_id;
    short sound_num;

    TRIBE_Master_Combat_Object::save(outfile);

    if (this->construction_sprite != 0) {
        sprite_id = this->construction_sprite->id;
    } else {
        sprite_id = -1;
    }

    if (this->construction_sound != 0) {
        sound_num = this->construction_sound->id;
    } else {
        sound_num = -1;
    }

    rge_write(outfile, &sprite_id, 2);
    rge_write(outfile, &this->building_connect_flag, 1);
    rge_write(outfile, &this->building_facet, 2);
    rge_write(outfile, &this->build_and_go_away, 1);
    rge_write(outfile, &this->on_build_make_obj, 2);
    rge_write(outfile, &this->on_build_make_tile, 2);
    rge_write(outfile, &this->on_build_make_overlay, 2);
    rge_write(outfile, &this->on_build_make_tech, 2);
    rge_write(outfile, &sound_num, 2);
}

RGE_Static_Object* TRIBE_Master_Building_Object::make_new_obj(
    RGE_Player* owner, float x, float y, float z, int uID) {
    return new TRIBE_Building_Object(this, owner, x, y, z, uID, 1);
}

RGE_Static_Object* TRIBE_Master_Building_Object::make_new_obj(
    RGE_Player* owner, float x, float y, float z) {
    return new TRIBE_Building_Object(this, owner, x, y, z, 1);
}

RGE_Master_Static_Object* TRIBE_Master_Building_Object::make_new_master() {
    return new TRIBE_Master_Building_Object(this, 1);
}

void TRIBE_Master_Building_Object::draw(
    TDrawArea* render_area, short x, short y, RGE_Color_Table* player_color,
    long facet, long frame, int draw_frame, unsigned char frame_color) {
    RGE_Sprite* sprite = this->sprite;
    if (sprite == 0) {
        return;
    }

    if (this->building_connect_flag != 0) {
        if (facet == 0) {
            sprite->draw(2, 0, x, y, x, y, player_color, render_area, 0);
        } else {
            sprite->draw(facet - 1, 0, x, y, x, y, player_color, render_area, 0);
        }
    } else {
        sprite->draw(this->building_facet, 0, x, y, x, y,
                     player_color, render_area, 0);
    }

    if (draw_frame != 0) {
        RGE_Map* map = rge_base_game->world->map;
        float rx1 = this->radius_x;
        float ry1 = this->radius_y;
        short x1;
        short y1;
        short x2;
        short y2;
        short x3;
        short y3;
        short x4;
        short y4;

        map->get_point(x1, y1, rx1, -ry1, 0.0f, x, y);
        map->get_point(x2, y2, rx1, ry1, 0.0f, x, y);
        rx1 = -rx1;
        map->get_point(x3, y3, rx1, ry1, 0.0f, x, y);
        map->get_point(x4, y4, rx1, -ry1, 0.0f, x, y);

        SDI_List->AddGDINode(1, y, x1, y1, x2, y2, x3, y3, x4, y4,
                             10, frame_color, SDI_Object_ID);
    }
}

unsigned char TRIBE_Master_Building_Object::alignment(
    float& col, float& row, RGE_Game_World* world, unsigned char center_flag) {
    return RGE_Master_Static_Object::alignment(col, row, world, 1);
}
