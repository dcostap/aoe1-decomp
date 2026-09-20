
#include "../include/m_s_obj.h"
#include "../include/game_globals.h"
#include "../include/basegame.h"
#include "../include/player.h"
#include "../include/world.h"
#include "../include/map.h"
#include "../include/stat_obj.h"
#include "../include/m_co_obj.h"
#include "../include/sprite.h"
#include "../include/sound.h"
#include "../include/visible.h"
#include "../include/color.h"
#include "../include/view.h"
#include "../include/mystring.h"
#include <stdlib.h>
#include <string.h>

#include "../include/rge_fio.h"
extern float DAT_00570610;
extern float DAT_00570614;
extern float DAT_00570618;
extern float DAT_00570630;
extern float DAT_00570634;

RGE_Master_Static_Object::RGE_Master_Static_Object(
    RGE_Master_Static_Object* other_object, int do_setup) {
    if (do_setup != 0) {
        setup(other_object);
    }
}

RGE_Master_Static_Object::RGE_Master_Static_Object(
    int infile, RGE_Sprite** sprites, RGE_Sound** sounds, int do_setup) {
    if (do_setup) {
        setup(infile, sprites, sounds);
    }
}

RGE_Master_Static_Object::RGE_Master_Static_Object(
    _iobuf* infile, RGE_Sprite** sprites, RGE_Sound** sounds,
    short in_id, int do_setup) {
    if (do_setup != 0) {
        this->setup(infile, sprites, sounds, in_id);
    }
}

int RGE_Master_Static_Object::setup(RGE_Master_Static_Object* other_object) {
    master_type = 0x0A;
    recyclable = other_object->recyclable;
    string_id = other_object->string_id;
    string_id2 = other_object->string_id2;
    id = other_object->id;
    copy_id = id;
    object_group = other_object->object_group;
    sprite = other_object->sprite;
    death_sprite = other_object->death_sprite;
    undead_sprite = other_object->undead_sprite;
    undead_flag = other_object->undead_flag;
    hp = other_object->hp;
    los = other_object->los;
    obj_max = other_object->obj_max;
    radius_x = other_object->radius_x;
    radius_y = other_object->radius_y;
    radius_z = other_object->radius_z;
    created_sound = other_object->created_sound;
    death_spawn_obj_id = other_object->death_spawn_obj_id;
    sort_number = other_object->sort_number;
    can_be_built_on = other_object->can_be_built_on;
    button_pict = other_object->button_pict;
    hide_in_scenario_editor = other_object->hide_in_scenario_editor;
    portrait_pict = other_object->portrait_pict;
    available = other_object->available;
    tile_req1 = other_object->tile_req1;
    tile_req2 = other_object->tile_req2;
    center_tile_req1 = other_object->center_tile_req1;
    center_tile_req2 = other_object->center_tile_req2;
    construction_radius_x = other_object->construction_radius_x;
    construction_radius_y = other_object->construction_radius_y;
    elevation_flag = other_object->elevation_flag;
    fog_flag = other_object->fog_flag;
    terrain = other_object->terrain;
    movement_type = other_object->movement_type;
    attribute_max_amount = other_object->attribute_max_amount;
    attribute_rot = other_object->attribute_rot;
    area_effect_object_level = other_object->area_effect_object_level;
    combat_level = other_object->combat_level;
    select_level = other_object->select_level;
    map_draw_level = other_object->map_draw_level;
    unit_level = other_object->unit_level;
    multiple_attribute_mod = other_object->multiple_attribute_mod;
    selected_sound = other_object->selected_sound;
    death_sound = other_object->death_sound;
    attack_reaction = other_object->attack_reaction;
    convert_terrain_flag = other_object->convert_terrain_flag;
    map_color = other_object->map_color;
    help_string_id = other_object->help_string_id;
    help_page_id = other_object->help_page_id;
    hotkey_id = other_object->hotkey_id;
    track_as_resource = other_object->track_as_resource;
    create_doppleganger_on_death = other_object->create_doppleganger_on_death;
    resource_group = other_object->resource_group;
    draw_flag = other_object->draw_flag;
    draw_color = other_object->draw_color;
    outline_radius_x = other_object->outline_radius_x;
    outline_radius_y = other_object->outline_radius_y;
    outline_radius_z = other_object->outline_radius_z;

    for (short i = 0; i < 3; i++) {
        attribute_type_held[i] = other_object->attribute_type_held[i];
        attribute_amount_held[i] = other_object->attribute_amount_held[i];
        attribute_flag[i] = other_object->attribute_flag[i];
    }

    {
        damage_sprite_num = other_object->damage_sprite_num;
        if (damage_sprite_num > 0) {
            damage_sprites = static_cast<RGE_Damage_Sprite_Info*>(calloc(damage_sprite_num, 8));
            short i = 0;
            if (damage_sprite_num > 0) {
                do {
                    damage_sprites[i].sprite = other_object->damage_sprites[i].sprite;
                    damage_sprites[i].damage_percent = other_object->damage_sprites[i].damage_percent;
                    damage_sprites[i].flag = other_object->damage_sprites[i].flag;
                    i++;
                } while (i < (short)damage_sprite_num);
            }
        } else {
            damage_sprites = 0;
        }
    }

    name = 0;
    getstring(&name, other_object->name);
    return 1;
}

int RGE_Master_Static_Object::setup(int infile, RGE_Sprite** sprites, RGE_Sound** sounds) {
    short temp_damage_sprite;
    short selected_sound_num;
    short death_sound_num;
    short created_sound_num;
    short sprite_num;
    short death_sprite_num;
    short undead_sprite_num;
    short name_size;
    unsigned char* attribute_flags;
    float* attribute_amounts;
    short* attribute_types;
    int count;
    int file_handle = infile;
    RGE_Sound* sound_value;
    RGE_Sprite* sprite_value;

    this->master_type = 10;
    rge_read(file_handle, &name_size, 2);
    rge_read(file_handle, &this->id, 2);
    rge_read(file_handle, &this->string_id, 2);
    rge_read(file_handle, &this->string_id2, 2);
    rge_read(file_handle, &this->object_group, 2);
    rge_read(file_handle, &sprite_num, 2);
    rge_read(file_handle, &death_sprite_num, 2);
    rge_read(file_handle, &undead_sprite_num, 2);
    rge_read(file_handle, &this->undead_flag, 1);
    rge_read(file_handle, &this->hp, 2);
    rge_read(file_handle, &this->los, 4);
    rge_read(file_handle, &this->obj_max, 1);
    rge_read(file_handle, &this->radius_x, 4);
    rge_read(file_handle, &this->radius_y, 4);
    rge_read(file_handle, &this->radius_z, 4);
    rge_read(file_handle, &created_sound_num, 2);
    rge_read(file_handle, &this->death_spawn_obj_id, 2);
    rge_read(file_handle, &this->sort_number, 1);
    rge_read(file_handle, &this->can_be_built_on, 1);
    rge_read(file_handle, &this->button_pict, 2);
    rge_read(file_handle, &this->hide_in_scenario_editor, 1);
    rge_read(file_handle, &this->portrait_pict, 2);
    rge_read(file_handle, &this->available, 1);
    rge_read(file_handle, &this->tile_req1, 2);
    rge_read(file_handle, &this->tile_req2, 2);
    rge_read(file_handle, &this->center_tile_req1, 2);
    rge_read(file_handle, &this->center_tile_req2, 2);
    rge_read(file_handle, &this->construction_radius_x, 4);
    rge_read(file_handle, &this->construction_radius_y, 4);
    rge_read(file_handle, &this->elevation_flag, 1);
    rge_read(file_handle, &this->fog_flag, 1);
    rge_read(file_handle, &this->terrain, 2);
    rge_read(file_handle, &this->movement_type, 1);
    rge_read(file_handle, &this->attribute_max_amount, 2);
    rge_read(file_handle, &this->attribute_rot, 4);
    rge_read(file_handle, &this->area_effect_object_level, 1);
    rge_read(file_handle, &this->combat_level, 1);
    rge_read(file_handle, &this->select_level, 1);
    rge_read(file_handle, &this->map_draw_level, 1);
    rge_read(file_handle, &this->unit_level, 1);
    rge_read(file_handle, &this->multiple_attribute_mod, 4);
    rge_read(file_handle, &this->map_color, 1);
    rge_read(file_handle, &this->help_string_id, 4);
    rge_read(file_handle, &this->help_page_id, 4);
    rge_read(file_handle, &this->hotkey_id, 4);
    rge_read(file_handle, &this->recyclable, 1);
    rge_read(file_handle, &this->track_as_resource, 1);
    rge_read(file_handle, &this->create_doppleganger_on_death, 1);
    rge_read(file_handle, &this->resource_group, 1);

    if (!(save_game_version < g_static_object_save_version_7_04)) {
        rge_read(file_handle, &this->draw_flag, 1);
        rge_read(file_handle, &this->draw_color, 1);
        rge_read(file_handle, &this->outline_radius_x, 4);
        rge_read(file_handle, &this->outline_radius_y, 4);
        rge_read(file_handle, &this->outline_radius_z, 4);
    } else {
        this->draw_flag = 0;
        this->draw_color = 0;
        this->outline_radius_x = this->radius_x;
        this->outline_radius_y = this->radius_y;
        this->outline_radius_z = this->radius_z;
    }

    attribute_flags = this->attribute_flag;
    attribute_amounts = this->attribute_amount_held;
    attribute_types = this->attribute_type_held;
    count = 3;
    do {
        rge_read(file_handle, attribute_types, 2);
        rge_read(file_handle, attribute_amounts, 4);
        rge_read(file_handle, attribute_flags, 1);
        attribute_types++;
        attribute_amounts++;
        attribute_flags++;
        count--;
    } while (count != 0);

    rge_read(file_handle, &this->damage_sprite_num, 1);
    if (this->damage_sprite_num > 0) {
        this->damage_sprites = static_cast<RGE_Damage_Sprite_Info*>(calloc(this->damage_sprite_num, 8));
        short i = 0;
        if (this->damage_sprite_num > 0) {
            do {
                rge_read(file_handle, &temp_damage_sprite, 2);
                rge_read(file_handle, &this->damage_sprites[i].damage_percent, 2);
                rge_read(file_handle, &this->damage_sprites[i].flag, 1);
                RGE_Sprite* damage_sprite;
                if (temp_damage_sprite >= 0) {
                    damage_sprite = sprites[temp_damage_sprite];
                } else {
                    damage_sprite = 0;
                }
                this->damage_sprites[i].sprite = damage_sprite;
                i++;
            } while (i < (short)this->damage_sprite_num);
        }
    } else {
        this->damage_sprites = 0;
    }

    rge_read(file_handle, &selected_sound_num, 2);
    rge_read(file_handle, &death_sound_num, 2);
    rge_read(file_handle, &this->attack_reaction, 1);
    rge_read(file_handle, &this->convert_terrain_flag, 1);

    if (name_size > 0) {
        this->name = static_cast<char*>(calloc(name_size, 1));
        rge_read(file_handle, this->name, name_size);
    } else {
        this->name = 0;
    }

    if (!(save_game_version < g_static_object_save_version_7_12)) {
        rge_read(file_handle, &this->copy_id, 2);
    }

    if (selected_sound_num >= 0) sound_value = sounds[selected_sound_num];
    else sound_value = 0;
    this->selected_sound = sound_value;
    if (death_sound_num >= 0) sound_value = sounds[death_sound_num];
    else sound_value = 0;
    this->death_sound = sound_value;
    if (created_sound_num >= 0) sound_value = sounds[created_sound_num];
    else sound_value = 0;
    this->created_sound = sound_value;
    if (sprite_num >= 0) sprite_value = sprites[sprite_num];
    else sprite_value = 0;
    this->sprite = sprite_value;
    if (death_sprite_num >= 0) sprite_value = sprites[death_sprite_num];
    else sprite_value = 0;
    this->death_sprite = sprite_value;
    if (undead_sprite_num >= 0) sprite_value = sprites[undead_sprite_num];
    else sprite_value = 0;
    this->undead_sprite = sprite_value;

    return 1;
}

int RGE_Master_Static_Object::setup(FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds, short in_id) {
    short temp_area_effect_object_level;
    short temp_combat_level;
    short temp_damage_sprite;
    short temp_select_level;
    short temp_flag;
    short temp_map_draw_level;
    short temp_death_sound;
    short temp_command_level;
    short temp_sprite;
    short temp_terrain;
    short temp_undead_sprite;
    short temp_undead_flag;
    short temp_fog_flag;
    short temp_hide_in_scenario_editor;
    short temp_sort_number;
    short temp_attack_reaction;
    short temp_available;
    short temp_convert_terrain_flag;
    short temp_attribute_flag;
    short temp_map_color;
    short temp_selected_sound;
    short temp_track_as_resource;
    short temp_death_sprite;
    short temp_create_doppleganger_on_death;
    short temp_obj_max;
    short temp_resource_group;
    short temp_movement_type;
    short temp_draw_flag;
    short temp_created_sound;
    short temp_draw_color;
    short temp_can_be_built_on;
    short temp_elevation_flag;
    short temp_damage_percent;
    unsigned char temp_elevation_flag_bytes[2];
    unsigned char temp_damage_percent_bytes[2];
    char temp_name[120];

    this->master_type = 10;
    this->id = in_id;

    fscanf(infile, "%s %hd %hd %hd %hd %hd %hd %hd %hd %f " "%hd %f %f %f %hd %hd %hd %hd %hd %hd "
           "%hd %hd %hd %hd %hd %f %f %hd %hd %hd " "%hd %hd %hd %f %f %hd %hd %hd %hd %hd "
           "%hd %ld %ld %ld %hd %hd %hd %hd %hd %f %f %f", temp_name + 4, &this->string_id, &this->string_id2,
           &this->object_group, &temp_undead_sprite, &temp_obj_max, &temp_fog_flag, &temp_hide_in_scenario_editor, &this->hp,
           &this->los, &temp_movement_type, &this->radius_x, &this->radius_y,
           &this->radius_z, &this->death_spawn_obj_id, &temp_available,
           &temp_damage_percent, &this->button_pict, &temp_attack_reaction,
           &this->portrait_pict, &temp_attribute_flag, &this->tile_req1,
           &this->tile_req2, &this->center_tile_req1, &this->center_tile_req2,
           &this->construction_radius_x, &this->construction_radius_y, temp_elevation_flag_bytes,
           &temp_sort_number, &temp_undead_flag, &temp_can_be_built_on, &temp_created_sound, &this->attribute_max_amount,
           &this->multiple_attribute_mod, &this->attribute_rot, &temp_damage_sprite, &temp_select_level, &temp_map_draw_level,
           &temp_command_level, &temp_terrain, &temp_track_as_resource,
           &this->help_string_id, &this->help_page_id, &this->hotkey_id,
           &temp_create_doppleganger_on_death, &temp_resource_group, &temp_draw_flag, &temp_draw_color, &temp_elevation_flag,
           &this->outline_radius_x, &this->outline_radius_y, &this->outline_radius_z);

    short* attribute_type = this->attribute_type_held;
    float* attribute_amount = this->attribute_amount_held;
    unsigned char* attribute_flag = this->attribute_flag;
    int attribute_count = 3;
    do {
        fscanf(infile, "%hd %f %hd", attribute_type, attribute_amount, &temp_selected_sound);
        *attribute_flag = static_cast<unsigned char>(temp_selected_sound);
        ++attribute_type;
        ++attribute_amount;
        ++attribute_flag;
        --attribute_count;
    } while (attribute_count != 0);

    fscanf(infile, "%hd", temp_name);
    this->damage_sprite_num = static_cast<unsigned char>(temp_name[0]);
    if (this->damage_sprite_num == 0) {
        this->damage_sprites = 0;
    } else {
        this->damage_sprites = static_cast<RGE_Damage_Sprite_Info*>(calloc(this->damage_sprite_num, 8));

        short index = 0;
        if (this->damage_sprite_num != 0) {
            do {
                fscanf(infile, "%hd %hd %hd", &temp_flag, temp_damage_percent_bytes, &temp_death_sound);

                RGE_Sprite* damage_sprite;
                if (temp_flag < 0) {
                    damage_sprite = 0;
                } else {
                    damage_sprite = sprites[temp_flag];
                }
                this->damage_sprites[index].sprite = damage_sprite;
                this->damage_sprites[index].damage_percent = temp_damage_percent_bytes[0];
                this->damage_sprites[index].flag =
                    static_cast<unsigned char>(temp_death_sound);
                ++index;
            } while (index < static_cast<short>(static_cast<unsigned short>(this->damage_sprite_num)));
        }
    }

    fscanf(infile, "%hd %hd %hd %hd", &temp_death_sprite, &temp_sprite, &temp_convert_terrain_flag, &temp_map_color);

    if (temp_death_sprite < 0) {
        this->selected_sound = 0;
    } else {
        this->selected_sound = sounds[temp_death_sprite];
    }
    if (temp_sprite < 0) {
        this->death_sound = 0;
    } else {
        this->death_sound = sounds[temp_sprite];
    }
    if (temp_can_be_built_on < 0) {
        this->created_sound = 0;
    } else {
        this->created_sound = sounds[temp_can_be_built_on];
    }

    if (temp_undead_sprite < 0) {
        this->sprite = 0;
    } else {
        this->sprite = sprites[temp_undead_sprite];
    }
    if (temp_obj_max < 0) {
        this->death_sprite = 0;
    } else {
        this->death_sprite = sprites[temp_obj_max];
    }
    if (temp_fog_flag < 0) {
        this->undead_sprite = 0;
    } else {
        this->undead_sprite = sprites[temp_fog_flag];
    }

    this->elevation_flag = temp_elevation_flag_bytes[0];
    this->sort_number = static_cast<unsigned char>(temp_available);
    this->movement_type = static_cast<unsigned char>(temp_created_sound);
    this->fog_flag = static_cast<unsigned char>(temp_sort_number);
    this->select_level = static_cast<unsigned char>(temp_map_draw_level);
    this->obj_max = static_cast<unsigned char>(temp_movement_type);
    this->can_be_built_on = static_cast<unsigned char>(temp_damage_percent);
    this->available = static_cast<unsigned char>(temp_attribute_flag);
    this->area_effect_object_level =
        static_cast<unsigned char>(temp_damage_sprite);
    this->terrain = static_cast<short>(static_cast<unsigned char>(temp_undead_flag));
    this->combat_level = static_cast<unsigned char>(temp_select_level);
    this->map_draw_level = static_cast<unsigned char>(temp_command_level);
    this->attack_reaction =
        static_cast<unsigned char>(temp_convert_terrain_flag);
    this->unit_level = static_cast<unsigned char>(temp_terrain);
    this->undead_flag =
        static_cast<unsigned char>(temp_hide_in_scenario_editor);
    this->track_as_resource = static_cast<unsigned char>(temp_create_doppleganger_on_death);
    this->hide_in_scenario_editor =
        static_cast<unsigned char>(temp_attack_reaction);
    this->convert_terrain_flag = static_cast<unsigned char>(temp_map_color);
    this->draw_flag = static_cast<unsigned char>(temp_draw_color);
    this->map_color = static_cast<unsigned char>(temp_track_as_resource);
    this->create_doppleganger_on_death =
        static_cast<unsigned char>(temp_resource_group);
    this->resource_group = static_cast<unsigned char>(temp_draw_flag);
    this->draw_color = static_cast<unsigned char>(temp_elevation_flag);

    if (this->outline_radius_x == g_static_object_zero_float || this->outline_radius_x != this->outline_radius_x) {
        this->outline_radius_x = this->radius_x;
    }
    if (this->outline_radius_y == g_static_object_zero_float || this->outline_radius_y != this->outline_radius_y) {
        this->outline_radius_y = this->radius_y;
    }
    if (this->outline_radius_z == g_static_object_zero_float || this->outline_radius_z != this->outline_radius_z) {
        this->outline_radius_z = this->radius_z;
    }

    this->recyclable = 0;
    this->copy_id = this->id;
    if (this->object_group == 11) {
        this->recyclable = 1;
    }

    if (static_cast<short>(strlen(temp_name + 4)) > 0) {
        this->name = 0;
        getstring(&this->name, temp_name + 4);
    }

    return 1;
}

RGE_Master_Static_Object::~RGE_Master_Static_Object() {
    if (this->name != 0) {
        free(this->name);
        this->name = 0;
    }
    if (this->damage_sprites != 0) {
        free(this->damage_sprites);
        this->damage_sprites = 0;
    }
}

RGE_Static_Object* RGE_Master_Static_Object::make_new_obj(
    RGE_Player* owner, float x, float y, float z) {
    if (recyclable) {
        RGE_Static_Object* recycled = owner->world->recycle_object_in_to_game(master_type);
        if (recycled) {
            recycled->recycle_in_to_game(this, owner, x, y, z);
            return recycled;
        }
    }

    return new RGE_Static_Object(this, owner, x, y, z, 1);
}

RGE_Master_Static_Object* RGE_Master_Static_Object::make_new_master(void) {
    return new RGE_Master_Static_Object(this, 1);
}

void RGE_Master_Static_Object::copy_obj(RGE_Master_Static_Object* source) {
    short object_type2 = id;
    short copy_id2 = copy_id;
    unsigned char available2 = available;
    short hide_in_scenario_editor2 = hide_in_scenario_editor;
    char** name_ptr = &name;

    if (*name_ptr != 0) {
        free(*name_ptr);
    }

    master_type = source->master_type;
    *name_ptr = source->name;
    string_id = source->string_id;
    string_id2 = source->string_id2;
    id = source->id;
    copy_id = source->copy_id;
    object_group = source->object_group;
    sprite = source->sprite;
    death_sprite = source->death_sprite;
    undead_sprite = source->undead_sprite;
    undead_flag = source->undead_flag;
    hp = source->hp;
    los = source->los;
    obj_max = source->obj_max;
    radius_x = source->radius_x;
    radius_y = source->radius_y;
    radius_z = source->radius_z;
    selected_sound = source->selected_sound;
    created_sound = source->created_sound;
    death_sound = source->death_sound;
    death_spawn_obj_id = source->death_spawn_obj_id;
    sort_number = source->sort_number;
    can_be_built_on = source->can_be_built_on;
    button_pict = source->button_pict;
    hide_in_scenario_editor = source->hide_in_scenario_editor;
    portrait_pict = source->portrait_pict;
    available = source->available;
    tile_req1 = source->tile_req1;
    tile_req2 = source->tile_req2;
    center_tile_req1 = source->center_tile_req1;
    center_tile_req2 = source->center_tile_req2;
    construction_radius_x = source->construction_radius_x;
    construction_radius_y = source->construction_radius_y;
    elevation_flag = source->elevation_flag;
    fog_flag = source->fog_flag;
    terrain = source->terrain;
    movement_type = source->movement_type;

    {
        unsigned int type_index = 0;
        do {
            attribute_type_held[type_index] = source->attribute_type_held[type_index];
            type_index++;
        } while (type_index < 3);

        unsigned int amount_index = 0;
        do {
            attribute_amount_held[amount_index] = source->attribute_amount_held[amount_index];
            amount_index++;
        } while (amount_index < 3);
    }

    attribute_max_amount = source->attribute_max_amount;
    attribute_rot = source->attribute_rot;
    multiple_attribute_mod = source->multiple_attribute_mod;

    {
        unsigned int flag_index = 0;
        do {
            attribute_flag[flag_index] = source->attribute_flag[flag_index];
            flag_index++;
        } while (flag_index < 3);
    }

    area_effect_object_level = source->area_effect_object_level;
    combat_level = source->combat_level;
    select_level = source->select_level;
    map_draw_level = source->map_draw_level;
    unit_level = source->unit_level;
    map_color = source->map_color;
    attack_reaction = source->attack_reaction;
    convert_terrain_flag = source->convert_terrain_flag;
    damage_sprite_num = source->damage_sprite_num;
    damage_sprites = source->damage_sprites;
    help_string_id = source->help_string_id;
    help_page_id = source->help_page_id;
    hotkey_id = source->hotkey_id;
    recyclable = source->recyclable;
    track_as_resource = source->track_as_resource;
    create_doppleganger_on_death = source->create_doppleganger_on_death;
    resource_group = source->resource_group;
    draw_flag = source->draw_flag;
    draw_color = source->draw_color;
    outline_radius_x = source->outline_radius_x;
    outline_radius_y = source->outline_radius_y;
    outline_radius_z = source->outline_radius_z;

    if (source->hide_in_scenario_editor == 1) {
        copy_id = copy_id2;
    }
    hide_in_scenario_editor = (unsigned char)hide_in_scenario_editor2;
    source->hide_in_scenario_editor = 1;

    if (damage_sprite_num > 0) {
        damage_sprites = static_cast<RGE_Damage_Sprite_Info*>(calloc(damage_sprite_num, 8));
        int i = 0;
        if (damage_sprite_num > 0) {
            do {
                damage_sprites[i].sprite = source->damage_sprites[i].sprite;
                damage_sprites[i].damage_percent = source->damage_sprites[i].damage_percent;
                damage_sprites[i].flag = source->damage_sprites[i].flag;
                i++;
            } while (i < (unsigned char)damage_sprite_num);
        }
    } else {
        damage_sprites = 0;
    }

    *name_ptr = 0;
    getstring(name_ptr, source->name);
    id = object_type2;
    available = available2;
}

void RGE_Master_Static_Object::modify(float amount, unsigned char flag) {
    switch (flag) {
        case 0:
            hp = (short)(long)amount;
            break;
        case 1:
            los = amount;
            break;
        case 2:
            obj_max = (unsigned char)(long)amount;
            break;
        case 3:
            radius_x = amount;
            break;
        case 4:
            radius_y = amount;
            break;
        case 14:
            attribute_max_amount = (short)(long)amount;
            break;
    }
}

void RGE_Master_Static_Object::modify_delta(float amount, unsigned char flag) {
    switch (flag) {
        case 0:
            hp += (short)(long)amount;
            break;
        case 1:
            los = (float)((double)amount + (double)los);
            break;
        case 2:
            obj_max += (unsigned char)(long)amount;
            break;
        case 3:
            radius_x = (float)((double)amount + (double)radius_x);
            break;
        case 4:
            radius_y = (float)((double)amount + (double)radius_y);
            break;
        case 14:
            attribute_max_amount += (short)(long)amount;
            break;
    }
}

void RGE_Master_Static_Object::modify_percent(float amount, unsigned char flag) {
    switch (flag) {
        case 0:
            hp = (short)((float)hp * amount);
            break;
        case 1:
            los = (float)((double)amount * (double)los);
            break;
        case 2:
            obj_max = (unsigned char)((float)obj_max * amount);
            break;
        case 3:
            radius_x = (float)((double)amount * (double)radius_x);
            break;
        case 4:
            radius_y = (float)((double)amount * (double)radius_y);
            break;
        case 14:
            attribute_max_amount = (short)((float)attribute_max_amount * amount);
            break;
    }
}

void RGE_Master_Static_Object::save(int outfile) {
    RGE_Master_Static_Object* self = this;
    short name_size = 0;
    short temp_death_sprite = -1;
    short temp_undead_sprite = -1;
    short created_sound_num = -1;
    short temp_sprite = -1;
    short selected_sound_num = -1;
    short death_sound_num = -1;

    RGE_Sound* s;
    RGE_Sprite* sp;

    s = self->created_sound;
    if (s) temp_sprite = s->id;
    s = self->selected_sound;
    if (s) death_sound_num = s->id;
    s = self->death_sound;
    if (s) selected_sound_num = s->id;
    sp = self->sprite;
    if (sp) temp_death_sprite = sp->id;
    sp = self->death_sprite;
    if (sp) temp_undead_sprite = sp->id;
    sp = self->undead_sprite;
    if (sp) created_sound_num = sp->id;

    char* name = self->name;
    name_size = (short)strlen(name);
    if (name_size > 0) name_size++;

    rge_write(outfile, (void*)(&self->master_type), 1);
    rge_write(outfile, (void*)(&name_size), 2);
    rge_write(outfile, (void*)(&self->id), 2);
    rge_write(outfile, (void*)(&self->string_id), 2);
    rge_write(outfile, (void*)(&self->string_id2), 2);
    rge_write(outfile, (void*)(&self->object_group), 2);
    rge_write(outfile, (void*)(&temp_death_sprite), 2);
    rge_write(outfile, (void*)(&temp_undead_sprite), 2);
    rge_write(outfile, (void*)(&created_sound_num), 2);
    rge_write(outfile, (void*)(&self->undead_flag), 1);
    rge_write(outfile, (void*)(&self->hp), 2);
    rge_write(outfile, (void*)(&self->los), 4);
    rge_write(outfile, (void*)(&self->obj_max), 1);
    rge_write(outfile, (void*)(&self->radius_x), 4);
    rge_write(outfile, (void*)(&self->radius_y), 4);
    rge_write(outfile, (void*)(&self->radius_z), 4);
    rge_write(outfile, (void*)(&temp_sprite), 2);
    rge_write(outfile, (void*)(&self->death_spawn_obj_id), 2);
    rge_write(outfile, (void*)(&self->sort_number), 1);
    rge_write(outfile, (void*)(&self->can_be_built_on), 1);
    rge_write(outfile, (void*)(&self->button_pict), 2);
    rge_write(outfile, (void*)(&self->hide_in_scenario_editor), 1);
    rge_write(outfile, (void*)(&self->portrait_pict), 2);
    rge_write(outfile, (void*)(&self->available), 1);
    rge_write(outfile, (void*)(&self->tile_req1), 2);
    rge_write(outfile, (void*)(&self->tile_req2), 2);
    rge_write(outfile, (void*)(&self->center_tile_req1), 2);
    rge_write(outfile, (void*)(&self->center_tile_req2), 2);
    rge_write(outfile, (void*)(&self->construction_radius_x), 4);
    rge_write(outfile, (void*)(&self->construction_radius_y), 4);
    rge_write(outfile, (void*)(&self->elevation_flag), 1);
    rge_write(outfile, (void*)(&self->fog_flag), 1);
    rge_write(outfile, (void*)(&self->terrain), 2);
    rge_write(outfile, (void*)(&self->movement_type), 1);
    rge_write(outfile, (void*)(&self->attribute_max_amount), 2);
    rge_write(outfile, (void*)(&self->attribute_rot), 4);
    rge_write(outfile, (void*)(&self->area_effect_object_level), 1);
    rge_write(outfile, (void*)(&self->combat_level), 1);
    rge_write(outfile, (void*)(&self->select_level), 1);
    rge_write(outfile, (void*)(&self->map_draw_level), 1);
    rge_write(outfile, (void*)(&self->unit_level), 1);
    rge_write(outfile, (void*)(&self->multiple_attribute_mod), 4);
    rge_write(outfile, (void*)(&self->map_color), 1);
    rge_write(outfile, (void*)(&self->help_string_id), 4);
    rge_write(outfile, (void*)(&self->help_page_id), 4);
    rge_write(outfile, (void*)(&self->hotkey_id), 4);
    rge_write(outfile, (void*)(&self->recyclable), 1);
    rge_write(outfile, (void*)(&self->track_as_resource), 1);
    rge_write(outfile, (void*)(&self->create_doppleganger_on_death), 1);
    rge_write(outfile, (void*)(&self->resource_group), 1);
    rge_write(outfile, (void*)(&self->draw_flag), 1);
    rge_write(outfile, (void*)(&self->draw_color), 1);
    rge_write(outfile, (void*)(&self->outline_radius_x), 4);
    rge_write(outfile, (void*)(&self->outline_radius_y), 4);
    rge_write(outfile, (void*)(&self->outline_radius_z), 4);

    unsigned char* soundPtr = self->attribute_flag;
    float* selectedProb = self->attribute_amount_held;
    short* selected = self->attribute_type_held;
    int i = 3;
    do {
        rge_write(outfile, (void*)(selected), 2);
        rge_write(outfile, (void*)(selectedProb), 4);
        rge_write(outfile, (void*)(soundPtr), 1);
        selected++;
        selectedProb++;
        soundPtr++;
        --i;
    } while (i);

    rge_write(outfile, (void*)(&self->damage_sprite_num), 1);
    if (0 < self->damage_sprite_num) {
        short j = 0;
        if (self->damage_sprite_num > 0) {
            do {
                rge_write(outfile, (void*)(&self->damage_sprites[j].sprite->id), 2);
                // The beta save stream writes two bytes here.
                rge_write(outfile, (void*)(&self->damage_sprites[j].damage_percent), 2);
                rge_write(outfile, (void*)(&self->damage_sprites[j].flag), 1);
                j++;
            } while (j < (short)self->damage_sprite_num);
        }
    }

    rge_write(outfile, (void*)(&death_sound_num), 2);
    rge_write(outfile, (void*)(&selected_sound_num), 2);
    rge_write(outfile, (void*)(&self->attack_reaction), 1);
    rge_write(outfile, (void*)(&self->convert_terrain_flag), 1);
    if (name_size != 0) {
        rge_write(outfile, (void*)(self->name),  name_size);
    }
    rge_write(outfile, (void*)(&self->copy_id), 2);
}

unsigned char RGE_Master_Static_Object::check_placement(
    RGE_Player* player, float col, float row, int* obstructionObject,
    unsigned char check_vis, unsigned char check_flat,
    unsigned char check_overlay, unsigned char construction_radius_flag,
    unsigned char can_be_built_on_flag, unsigned char check_objects) {
    float* terrain_table = player->world->terrains[this->terrain];
    RGE_Map* map = player->world->map;
    float radius_x;
    float radius_y;

    if (construction_radius_flag != 0) {
        radius_x = this->construction_radius_x;
        radius_y = this->construction_radius_y;
    } else {
        radius_x = this->radius_x;
        radius_y = this->radius_y;
    }

    float min_x_value = col - radius_x;
    float max_x_value = col + radius_x - g_static_object_coordinate_epsilon;
    float min_y_value = row - radius_y;
    float max_y_value = row + radius_y - g_static_object_coordinate_epsilon;

    if (!(min_x_value >= g_static_object_zero) || !(max_x_value < (float)map->map_width) || !(min_y_value >= g_static_object_zero) ||
        !(max_y_value < (float)map->map_height)) {
        return 7;
    }

    short x1 = (short)(long)min_x_value;
    short x2 = (short)(long)max_x_value;
    short y1 = (short)(long)min_y_value;
    short y2 = (short)(long)max_y_value;
    short edge_x1 = x1;
    short edge_x2 = x2;
    short edge_y1 = y1;
    short edge_y2 = y2;

    if (this->center_tile_req1 >= 0 || this->center_tile_req2 >= 0) {
        short center_y = (short)(long)row;
        short center_x = (short)(long)col;
        short center_terrain =
            map->map_row_offset[center_y][center_x].terrain_type;
        if (center_terrain != this->center_tile_req1 && center_terrain != this->center_tile_req2) {
            return 1;
        }
        edge_x1 = center_x;
        edge_x2 = center_x;
        edge_y1 = center_y;
        edge_y2 = center_y;
    }

    if (this->tile_req1 >= 0 || this->tile_req2 >= 0) {
        unsigned char req_terr1 = 0;
        unsigned char req_terr2 = 0;
        short edge = (short)(edge_y1 - 1);
        if (edge >= 0 && edge_x1 <= edge_x2) {
            RGE_Tile* tile = map->map_row_offset[edge] + edge_x1;
            int count = (int)edge_x2 - (int)edge_x1 + 1;
            do {
                short terrain = tile->terrain_type;
                if (terrain == this->tile_req1) req_terr1 = 1;
                if (terrain == this->tile_req2) req_terr2 = 1;
                ++tile;
                --count;
            } while (count != 0);
        }

        edge = (short)(edge_x2 + 1);
        if (edge < map->map_width && edge_y1 <= edge_y2) {
            RGE_Tile** row = map->map_row_offset + edge_y1;
            int count = (int)edge_y2 - (int)edge_y1 + 1;
            do {
                short terrain = (*row)[edge].terrain_type;
                if (terrain == this->tile_req1) req_terr1 = 1;
                if (terrain == this->tile_req2) req_terr2 = 1;
                ++row;
                --count;
            } while (count != 0);
        }

        edge = (short)(edge_y2 + 1);
        if (edge < map->map_height && edge_x1 <= edge_x2) {
            RGE_Tile* tile = map->map_row_offset[edge] + edge_x2;
            int count = (int)edge_x2 - (int)edge_x1 + 1;
            do {
                short terrain = tile->terrain_type;
                if (terrain == this->tile_req1) req_terr1 = 1;
                if (terrain == this->tile_req2) req_terr2 = 1;
                --tile;
                --count;
            } while (count != 0);
        }

        edge = (short)(edge_x1 - 1);
        if (edge >= 0 && edge_y1 <= edge_y2) {
            RGE_Tile** row = map->map_row_offset + edge_y2;
            int count = (int)edge_y2 - (int)edge_y1 + 1;
            do {
                short terrain = (*row)[edge].terrain_type;
                if (terrain == this->tile_req1) req_terr1 = 1;
                if (terrain == this->tile_req2) req_terr2 = 1;
                --row;
                --count;
            } while (count != 0);
        }

        if (req_terr1 == 0 && req_terr2 == 0) {
            return 1;
        }
    }

    unsigned char part_vis = 0;
    for (short x_index = x1; x_index <= x2; x_index++) {
        for (short y_index = y1; y_index <= y2; y_index++) {
            RGE_Tile* tile = &map->map_row_offset[y_index][x_index];
            if (!(terrain_table[tile->terrain_type] > g_static_object_zero_float)) {
                return 2;
            }

            if (check_vis != 0 && (rge_base_game->prog_mode == 7 || player->visible->get_visible(x_index, y_index) != 0)) {
                part_vis = 1;
            }

            if (check_flat != 0) {
                unsigned char tile_type = tile->tile_type;
                if (this->elevation_flag == 1) {
                    if (tile_type != 0 && tile_type != 5 && tile_type != 7 && tile_type != 6 && tile_type != 8) {
                        return 3;
                    }
                } else if (this->elevation_flag == 2 && tile_type != 0) {
                    return 3;
                }
            }
        }
    }

    if (check_vis == 1 && part_vis == 0) {
        return 5;
    }

    if (!(radius_x > g_static_object_zero_float) && !(radius_y > g_static_object_zero_float)) {
        return 0;
    }

    short object_min_x = (short)(long)(col - g_static_object_bounds_min_adjustment);
    short object_min_y = (short)(long)(row - g_static_object_bounds_min_adjustment);
    short object_max_x = (short)(long)(col - g_static_object_bounds_max_adjustment);
    short object_max_y = (short)(long)(row - g_static_object_bounds_max_adjustment);

    if (object_min_x < 0) object_min_x = 0;
    if (object_max_x >= map->map_width) {
        object_max_x = (short)map->map_width - 1;
    }
    if (object_min_y < 0) object_min_y = 0;
    if (object_max_y >= map->map_height) {
        object_max_y = (short)map->map_height - 1;
    }

    if (check_objects != 0 && (can_be_built_on_flag != 0 || this->radius_z > g_static_object_zero) &&
        object_min_y <= object_max_y) {
        for (short y_index = object_min_y; y_index <= object_max_y; y_index++) {
            RGE_Tile* tile =
                &map->map_row_offset[y_index][object_min_x];
            for (short x_index = object_min_x; x_index <= object_max_x; x_index++, tile++) {
                RGE_Object_Node* object_node = tile->objects.list;
                while (object_node != 0) {
                    RGE_Static_Object* object = object_node->node;
                    if (object->object_state < 7 && (can_be_built_on_flag == 0 ||
                         object->master_obj->can_be_built_on != 1 || this->can_be_built_on != 0)) {
                        RGE_Master_Static_Object* master = object->master_obj;
                        float object_radius_x = master->radius_x;
                        float object_radius_y = master->radius_y;
                        float object_radius_z = master->radius_z;
                        if (object_radius_x > g_static_object_zero && object_radius_y > g_static_object_zero &&
                            ((object_radius_z > g_static_object_zero && this->radius_z > g_static_object_zero) ||
                             (!(object_radius_z > g_static_object_zero) && !(this->radius_z > g_static_object_zero)))) {
                            float distance_y = object->world_y - row;
                            float distance_x = object->world_x - col;
                            if (distance_y < g_static_object_zero_float) {
                                distance_y = -distance_y;
                            }
                            if (distance_x < g_static_object_zero_float) {
                                distance_x = -distance_x;
                            }
                            if (!(distance_x >= object_radius_x + radius_x) &&
                                !(distance_y >= object_radius_y + radius_y)) {
                                if (obstructionObject != 0) {
                                    *obstructionObject = object->id;
                                }
                                return 6;
                            }
                        }
                    }
                    object_node = object_node->next;
                }
            }
        }
    }

    return 0;
}

void RGE_Master_Static_Object::make_available(unsigned char on_off_flag) {
    this->available = on_off_flag;
}

unsigned char RGE_Master_Static_Object::alignment(
    float& col, float& row, RGE_Game_World* world, unsigned char center_flag) {
    float dx1 = col - this->radius_x;
    float dy1 = row - this->radius_y;
    float dx2 = col + this->radius_x;
    float dy2 = row + this->radius_y;
    float map_w = (float)world->map->map_width - 0.00001f;
    float map_h = (float)world->map->map_height - 0.00001f;
    float aligned_x;
    float aligned_y;

    if (dx1 < 0.0f) {
        dx1 = -dx1;
        dx2 += dx1;
        col += dx1;
        dx1 = 0.0f;
    }
    if (dy1 < 0.0f) {
        dy1 = -dy1;
        dy2 += dy1;
        row += dy1;
        dy1 = 0.0f;
    }
    if (dx2 >= map_w) {
        dx1 += map_w - dx2;
        col += map_w - dx2;
        dx2 = map_w;
    }
    if (dy2 >= map_h) {
        dy1 += map_h - dy2;
        row += map_h - dy2;
        dy2 = map_h;
    }

    if (center_flag != 0) {
        if (dx1 < 0.0f) dx1 = -dx1;
        if (dy1 < 0.0f) dy1 = -dy1;
        if (dx2 < 0.0f) dx2 = -dx2;
        if (dy2 < 0.0f) dy2 = -dy2;

        dx1 -= (short)dx1;
        dy1 -= (short)dy1;
        dx2 = 1.0f - (dx2 - (short)dx2);
        dy2 = 1.0f - (dy2 - (short)dy2);

        if (dx1 + dx2 >= 1.0f) {
            if (dx1 > dx2) {
                aligned_x = col + (1.0f - dx1);
            } else {
                aligned_x = col - (1.0f - dx2);
            }
        } else {
            aligned_x = col;
        }

        if (dy1 + dy2 >= 1.0f) {
            if (dy1 > dy2) {
                aligned_y = row + (1.0f - dy1);
            } else {
                aligned_y = row - (1.0f - dy2);
            }
        } else {
            aligned_y = row;
        }

        col = aligned_x;
        row = aligned_y;
    }
    return 1;
}

unsigned char RGE_Master_Static_Object::alignment_box(
    RGE_Game_World* world, float col, float row,
    short& x1, short& y1, short& x2, short& y2,
    short& x3, short& y3, short& x4, short& y4) {
    short tile_x;
    short tile_y;
    float tx;
    float ty;
    tile_x = (short)col;
    tile_y = (short)row;
    tx = col - (float)tile_x + this->radius_x;
    ty = row - (float)tile_y + this->radius_y;
    short tile_half_width = world->map->tile_half_width;
    short tile_half_height = world->map->tile_half_height;

    x1 = (short)((tx + ty) * tile_half_width);
    y1 = (short)((ty + 1.0 - tx) * tile_half_height);
    tx -= 2.0f * this->radius_x;
    x2 = (short)((tx + ty) * tile_half_width);
    y2 = (short)((ty + 1.0 - tx) * tile_half_height);
    ty -= 2.0f * this->radius_y;
    x3 = (short)((tx + ty) * tile_half_width);
    y3 = (short)((ty + 1.0 - tx) * tile_half_height);
    tx += (this->radius_x + this->radius_x);
    x4 = (short)((tx + ty) * tile_half_width);
    y4 = (short)((ty + 1.0 - tx) * tile_half_height);
    return 1;
}

void RGE_Master_Static_Object::draw(
    TDrawArea* render_area, short x, short y, RGE_Color_Table* player_color,
    long facet, long frame, int draw_frame, unsigned char frame_color) {
    if (this->sprite != 0) {
        this->sprite->draw(facet, frame, (int)x, (int)y, (int)x, (int)y, player_color, render_area, 10);

        if (draw_frame != 0) {
            // The executable reads world before outline radii.
            RGE_Map* map = rge_base_game->world->map;
            float rx1 = this->outline_radius_x;
            float ry1 = this->outline_radius_y;
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

            SDI_List->AddGDINode(1, (int)y, x1, y1, x2, y2, x3, y3, x4, y4, 10, (int)(frame_color & 0xFF), SDI_Object_ID);
        }
    }
}

long RGE_Master_Static_Object::get_help_message() {
    return this->help_string_id;
}

long RGE_Master_Static_Object::get_help_page() {
    return this->help_page_id;
}

long RGE_Master_Static_Object::get_hotkey() {
    return this->hotkey_id;
}

long RGE_Master_Static_Object::calc_base_damage_ability(
    RGE_Master_Combat_Object* attacker) {
    float total = 0.0f;
    int count = attacker->weapon_num;
    RGE_Armor_Weapon_Info* weapon = attacker->weapon;
    if (count > 0) {
        do {
            float fval = (float)weapon->value;
            if (fval > 0.0) {
                total = total + fval;
            }
            ++weapon;
            --count;
        } while (count != 0);
    }
    if (total < 1.0) {
        total = 1.0f;
    }
    return (long)total;
}
