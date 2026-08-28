// PDB source module: C:\\msdev\\work\\age1_x1\\tm_b_obj.cpp.
// The scalar deleting destructor at 0050E0A0 is compiler generated.

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
extern int SDI_Object_ID;

TRIBE_Master_Building_Object::TRIBE_Master_Building_Object(
    TRIBE_Master_Building_Object* source, int do_setup)
    : TRIBE_Master_Combat_Object(
          static_cast<TRIBE_Master_Combat_Object*>(source), 0) {
    if (do_setup != 0) {
        setup(source);
    }
}

TRIBE_Master_Building_Object::TRIBE_Master_Building_Object(
    int id, RGE_Sprite** sprites, RGE_Sound** sounds, int do_setup)
    : TRIBE_Master_Combat_Object(id, sprites, sounds, 0) {
    if (do_setup != 0) {
        this->setup(id, sprites, sounds);
    }
}

TRIBE_Master_Building_Object::TRIBE_Master_Building_Object(
    FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds, short id,
    int do_setup)
    : TRIBE_Master_Combat_Object(file, sprites, sounds, id, 0) {
    if (do_setup != 0) {
        this->setup(file, sprites, sounds, id);
    }
}

int TRIBE_Master_Building_Object::setup(
    TRIBE_Master_Building_Object* source) {
    TRIBE_Master_Combat_Object::setup(source);
    this->master_type = 0x50;
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

int TRIBE_Master_Building_Object::setup(
    int file, RGE_Sprite** sprites, RGE_Sound** sounds) {
    short sprite_id;
    short sound_id;

    TRIBE_Master_Combat_Object::setup(file, sprites, sounds);
    this->master_type = 0x50;

    rge_read(file, &sprite_id, 2);
    rge_read(file, &this->building_connect_flag, 1);
    rge_read(file, &this->building_facet, 2);
    rge_read(file, &this->build_and_go_away, 1);
    rge_read(file, &this->on_build_make_obj, 2);
    rge_read(file, &this->on_build_make_tile, 2);
    rge_read(file, &this->on_build_make_overlay, 2);
    rge_read(file, &this->on_build_make_tech, 2);
    rge_read(file, &sound_id, 2);

    if (sprite_id >= 0) {
        this->construction_sprite = sprites[sprite_id];
    } else {
        this->construction_sprite = 0;
    }

    if (sound_id >= 0) {
        this->construction_sound = sounds[sound_id];
    } else {
        this->construction_sound = 0;
    }
    return 1;
}

int TRIBE_Master_Building_Object::setup(
    FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds, short id) {
    short sprite_id;
    short connect_flag;
    short build_and_go_away;
    short sound_id;

    TRIBE_Master_Combat_Object::setup(file, sprites, sounds, id);
    this->master_type = 0x50;

    fscanf(file, "%hd %hd %hd %hd %hd %hd %hd %hd %hd",
           &sprite_id, &connect_flag, &this->building_facet,
           &build_and_go_away, &this->on_build_make_obj,
           &this->on_build_make_tile, &this->on_build_make_overlay,
           &this->on_build_make_tech, &sound_id);

    this->building_connect_flag = static_cast<unsigned char>(connect_flag);
    this->build_and_go_away = static_cast<unsigned char>(build_and_go_away);

    if (sprite_id >= 0) {
        this->construction_sprite = sprites[sprite_id];
    } else {
        this->construction_sprite = 0;
    }

    if (sound_id >= 0) {
        this->construction_sound = sounds[sound_id];
    } else {
        this->construction_sound = 0;
    }
    return 1;
}

TRIBE_Master_Building_Object::~TRIBE_Master_Building_Object() {
}

void TRIBE_Master_Building_Object::copy_obj(RGE_Master_Static_Object* source) {
    TRIBE_Master_Combat_Object::copy_obj(source);

    // BINARY NOTE: This virtual copy path receives a building-master source.
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
    float value, unsigned char attribute) {
    if (attribute != 0x11) {
        TRIBE_Master_Combat_Object::modify(value, attribute);
        return;
    }
    this->building_facet = static_cast<short>(value);
}

void TRIBE_Master_Building_Object::modify_delta(
    float value, unsigned char attribute) {
    if (attribute != 0x11) {
        TRIBE_Master_Combat_Object::modify_delta(value, attribute);
        return;
    }
    this->building_facet += static_cast<short>(value);
}

void TRIBE_Master_Building_Object::modify_percent(
    float value, unsigned char attribute) {
    TRIBE_Master_Combat_Object::modify_percent(value, attribute);
}

void TRIBE_Master_Building_Object::save(int file) {
    short sprite_id;
    short sound_id;

    TRIBE_Master_Combat_Object::save(file);

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

    rge_write(file, &sprite_id, 2);
    rge_write(file, &this->building_connect_flag, 1);
    rge_write(file, &this->building_facet, 2);
    rge_write(file, &this->build_and_go_away, 1);
    rge_write(file, &this->on_build_make_obj, 2);
    rge_write(file, &this->on_build_make_tile, 2);
    rge_write(file, &this->on_build_make_overlay, 2);
    rge_write(file, &this->on_build_make_tech, 2);
    rge_write(file, &sound_id, 2);
}

RGE_Static_Object* TRIBE_Master_Building_Object::make_new_obj(
    RGE_Player* player, float x, float y, float z, int unique_id) {
    return new TRIBE_Building_Object(this, player, x, y, z, unique_id, 1);
}

RGE_Static_Object* TRIBE_Master_Building_Object::make_new_obj(
    RGE_Player* player, float x, float y, float z) {
    return new TRIBE_Building_Object(this, player, x, y, z, 1);
}

RGE_Master_Static_Object* TRIBE_Master_Building_Object::make_new_master() {
    return new TRIBE_Master_Building_Object(this, 1);
}

void TRIBE_Master_Building_Object::draw(
    TDrawArea* area, short x, short y, RGE_Color_Table* color_table,
    long facet, long, int add_gdi_node, unsigned char draw_flag) {
    RGE_Sprite* sprite = this->sprite;
    if (sprite == 0) {
        return;
    }

    if (this->building_connect_flag != 0) {
        if (facet == 0) {
            sprite->draw(2, 0, x, y, x, y, color_table, area, 0);
        } else {
            sprite->draw(facet - 1, 0, x, y, x, y, color_table, area, 0);
        }
    } else {
        sprite->draw(this->building_facet, 0, x, y, x, y,
                     color_table, area, 0);
    }

    if (add_gdi_node != 0) {
        RGE_Map* map = rge_base_game->world->map;
        float radius_x = this->radius_x;
        float radius_y = this->radius_y;
        short x1;
        short y1;
        short x2;
        short y2;
        short x3;
        short y3;
        short x4;
        short y4;

        map->get_point(x1, y1, radius_x, -radius_y, 0.0f, x, y);
        map->get_point(x2, y2, radius_x, radius_y, 0.0f, x, y);
        radius_x = -radius_x;
        map->get_point(x3, y3, radius_x, radius_y, 0.0f, x, y);
        map->get_point(x4, y4, radius_x, -radius_y, 0.0f, x, y);

        SDI_List->AddGDINode(1, y, x1, y1, x2, y2, x3, y3, x4, y4,
                             10, draw_flag, SDI_Object_ID);
    }
}

unsigned char TRIBE_Master_Building_Object::alignment(
    float& x, float& y, RGE_Game_World* world, unsigned char) {
    return RGE_Master_Static_Object::alignment(x, y, world, 1);
}
