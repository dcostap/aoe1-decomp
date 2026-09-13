
#include "../include/m_s_obj.h"
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
extern float save_game_version;
extern float DAT_00570610;
extern float DAT_00570614;
extern float DAT_00570618;
extern float DAT_0057061c;
extern double DAT_00570620;
extern float DAT_00570628;
extern float DAT_0057062c;

RGE_Master_Static_Object::RGE_Master_Static_Object(
    RGE_Master_Static_Object* object, int do_setup) {
    if (do_setup != 0) {
        setup(object);
    }
}

RGE_Master_Static_Object::RGE_Master_Static_Object(
    int value, RGE_Sprite** sprites, RGE_Sound** sounds, int do_setup) {
    if (do_setup) {
        setup(value, sprites, sounds);
    }
}

RGE_Master_Static_Object::RGE_Master_Static_Object(
    _iobuf* file, RGE_Sprite** sprites, RGE_Sound** sounds,
    short value, int doSetup) {
    if (doSetup != 0) {
        this->setup(file, sprites, sounds, value);
    }
}

int RGE_Master_Static_Object::setup(RGE_Master_Static_Object* src) {
    master_type = 0x0A;
    recyclable = src->recyclable;
    string_id = src->string_id;
    string_id2 = src->string_id2;
    id = src->id;
    copy_id = id;
    object_group = src->object_group;
    sprite = src->sprite;
    death_sprite = src->death_sprite;
    undead_sprite = src->undead_sprite;
    undead_flag = src->undead_flag;
    hp = src->hp;
    los = src->los;
    obj_max = src->obj_max;
    radius_x = src->radius_x;
    radius_y = src->radius_y;
    radius_z = src->radius_z;
    created_sound = src->created_sound;
    death_spawn_obj_id = src->death_spawn_obj_id;
    sort_number = src->sort_number;
    can_be_built_on = src->can_be_built_on;
    button_pict = src->button_pict;
    hide_in_scenario_editor = src->hide_in_scenario_editor;
    portrait_pict = src->portrait_pict;
    available = src->available;
    tile_req1 = src->tile_req1;
    tile_req2 = src->tile_req2;
    center_tile_req1 = src->center_tile_req1;
    center_tile_req2 = src->center_tile_req2;
    construction_radius_x = src->construction_radius_x;
    construction_radius_y = src->construction_radius_y;
    elevation_flag = src->elevation_flag;
    fog_flag = src->fog_flag;
    terrain = src->terrain;
    movement_type = src->movement_type;
    attribute_max_amount = src->attribute_max_amount;
    attribute_rot = src->attribute_rot;
    area_effect_object_level = src->area_effect_object_level;
    combat_level = src->combat_level;
    select_level = src->select_level;
    map_draw_level = src->map_draw_level;
    unit_level = src->unit_level;
    multiple_attribute_mod = src->multiple_attribute_mod;
    selected_sound = src->selected_sound;
    death_sound = src->death_sound;
    attack_reaction = src->attack_reaction;
    convert_terrain_flag = src->convert_terrain_flag;
    map_color = src->map_color;
    help_string_id = src->help_string_id;
    help_page_id = src->help_page_id;
    hotkey_id = src->hotkey_id;
    track_as_resource = src->track_as_resource;
    create_doppleganger_on_death = src->create_doppleganger_on_death;
    resource_group = src->resource_group;
    draw_flag = src->draw_flag;
    draw_color = src->draw_color;
    outline_radius_x = src->outline_radius_x;
    outline_radius_y = src->outline_radius_y;
    outline_radius_z = src->outline_radius_z;

    for (short i = 0; i < 3; i++) {
        attribute_type_held[i] = src->attribute_type_held[i];
        attribute_amount_held[i] = src->attribute_amount_held[i];
        attribute_flag[i] = src->attribute_flag[i];
    }

    {
        damage_sprite_num = src->damage_sprite_num;
        if (damage_sprite_num > 0) {
            damage_sprites = static_cast<RGE_Damage_Sprite_Info*>(
                calloc(damage_sprite_num, 8));
            short i = 0;
            if (damage_sprite_num > 0) {
                do {
                    damage_sprites[i].sprite = src->damage_sprites[i].sprite;
                    damage_sprites[i].damage_percent = src->damage_sprites[i].damage_percent;
                    damage_sprites[i].flag = src->damage_sprites[i].flag;
                    i++;
                } while (i < (short)damage_sprite_num);
            }
        } else {
            damage_sprites = 0;
        }
    }

    name = 0;
    getstring(&name, src->name);
    return 1;
}

int RGE_Master_Static_Object::setup(
    int handle, RGE_Sprite** sprites, RGE_Sound** sounds) {
    short death_sound_num;
    short created_sound_num;
    short sprite_num;
    short death_sprite_num;
    short undead_sprite_num;
    short death_sprite_index;
    short undead_sprite_index;
    short name_length;
    unsigned char* attribute_flags;
    float* attribute_amounts;
    short* attribute_types;
    int count;
    int file_handle = handle;
    RGE_Sound* sound_value;
    RGE_Sprite* sprite_value;

    this->master_type = 10;
    rge_read(file_handle, &name_length, 2);
    rge_read(file_handle, &this->id, 2);
    rge_read(file_handle, &this->string_id, 2);
    rge_read(file_handle, &this->string_id2, 2);
    rge_read(file_handle, &this->object_group, 2);
    rge_read(file_handle, &undead_sprite_num, 2);
    rge_read(file_handle, &death_sprite_index, 2);
    rge_read(file_handle, &undead_sprite_index, 2);
    rge_read(file_handle, &this->undead_flag, 1);
    rge_read(file_handle, &this->hp, 2);
    rge_read(file_handle, &this->los, 4);
    rge_read(file_handle, &this->obj_max, 1);
    rge_read(file_handle, &this->radius_x, 4);
    rge_read(file_handle, &this->radius_y, 4);
    rge_read(file_handle, &this->radius_z, 4);
    rge_read(file_handle, &death_sprite_num, 2);
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

    if (!(save_game_version < DAT_00570610)) {
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
        this->damage_sprites = static_cast<RGE_Damage_Sprite_Info*>(
            calloc(this->damage_sprite_num, 8));
        short i = 0;
        if (this->damage_sprite_num > 0) {
            do {
                rge_read(file_handle, &death_sound_num, 2);
                rge_read(file_handle, &this->damage_sprites[i].damage_percent, 2);
                rge_read(file_handle, &this->damage_sprites[i].flag, 1);
                RGE_Sprite* damage_sprite;
                if (death_sound_num >= 0) {
                    damage_sprite = sprites[death_sound_num];
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

    rge_read(file_handle, &created_sound_num, 2);
    rge_read(file_handle, &sprite_num, 2);
    rge_read(file_handle, &this->attack_reaction, 1);
    rge_read(file_handle, &this->convert_terrain_flag, 1);

    if (name_length > 0) {
        this->name = static_cast<char*>(calloc(name_length, 1));
        rge_read(file_handle, this->name, name_length);
    } else {
        this->name = 0;
    }

    if (!(save_game_version < DAT_00570614)) {
        rge_read(file_handle, &this->copy_id, 2);
    }

    if (created_sound_num >= 0) sound_value = sounds[created_sound_num];
    else sound_value = 0;
    this->selected_sound = sound_value;
    if (sprite_num >= 0) sound_value = sounds[sprite_num];
    else sound_value = 0;
    this->death_sound = sound_value;
    if (death_sprite_num >= 0) sound_value = sounds[death_sprite_num];
    else sound_value = 0;
    this->created_sound = sound_value;
    if (undead_sprite_num >= 0) sprite_value = sprites[undead_sprite_num];
    else sprite_value = 0;
    this->sprite = sprite_value;
    if (death_sprite_index >= 0) sprite_value = sprites[death_sprite_index];
    else sprite_value = 0;
    this->death_sprite = sprite_value;
    if (undead_sprite_index >= 0) sprite_value = sprites[undead_sprite_index];
    else sprite_value = 0;
    this->undead_sprite = sprite_value;

    return 1;
}

int RGE_Master_Static_Object::setup(
    FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds, short value) {
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
    unsigned char local_84[2];
    unsigned char local_82[2];
    char temp_name[120];

    this->master_type = 10;
    this->id = value;

    fscanf(
        file,
        "%s %hd %hd %hd %hd %hd %hd %hd %hd %f "
        "%hd %f %f %f %hd %hd %hd %hd %hd %hd "
        "%hd %hd %hd %hd %hd %f %f %hd %hd %hd "
        "%hd %hd %hd %f %f %hd %hd %hd %hd %hd "
        "%hd %ld %ld %ld %hd %hd %hd %hd %hd %f %f %f",
        temp_name + 4, &this->string_id, &this->string_id2,
        &this->object_group, &temp_undead_sprite, &temp_obj_max,
        &temp_fog_flag, &temp_hide_in_scenario_editor, &this->hp,
        &this->los, &temp_movement_type, &this->radius_x, &this->radius_y,
        &this->radius_z, &this->death_spawn_obj_id, &temp_available,
        &temp_damage_percent, &this->button_pict, &temp_attack_reaction,
        &this->portrait_pict, &temp_attribute_flag, &this->tile_req1,
        &this->tile_req2, &this->center_tile_req1, &this->center_tile_req2,
        &this->construction_radius_x, &this->construction_radius_y, local_84,
        &temp_sort_number, &temp_undead_flag, &temp_can_be_built_on,
        &temp_created_sound, &this->attribute_max_amount,
        &this->multiple_attribute_mod, &this->attribute_rot,
        &temp_damage_sprite, &temp_select_level, &temp_map_draw_level,
        &temp_command_level, &temp_terrain, &temp_track_as_resource,
        &this->help_string_id, &this->help_page_id, &this->hotkey_id,
        &temp_create_doppleganger_on_death, &temp_resource_group,
        &temp_draw_flag, &temp_draw_color, &temp_elevation_flag,
        &this->outline_radius_x, &this->outline_radius_y,
        &this->outline_radius_z);

    short* attribute_type = this->attribute_type_held;
    float* attribute_amount = this->attribute_amount_held;
    unsigned char* attribute_flag = this->attribute_flag;
    int attribute_count = 3;
    do {
        fscanf(file, "%hd %f %hd", attribute_type, attribute_amount,
               &temp_selected_sound);
        *attribute_flag = static_cast<unsigned char>(temp_selected_sound);
        ++attribute_type;
        ++attribute_amount;
        ++attribute_flag;
        --attribute_count;
    } while (attribute_count != 0);

    fscanf(file, "%hd", temp_name);
    this->damage_sprite_num = static_cast<unsigned char>(temp_name[0]);
    if (this->damage_sprite_num == 0) {
        this->damage_sprites = 0;
    } else {
        this->damage_sprites = static_cast<RGE_Damage_Sprite_Info*>(
            calloc(this->damage_sprite_num, 8));

        short index = 0;
        if (this->damage_sprite_num != 0) {
            do {
                fscanf(file, "%hd %hd %hd", &temp_flag, local_82,
                       &temp_death_sound);

                RGE_Sprite* damage_sprite;
                if (temp_flag < 0) {
                    damage_sprite = 0;
                } else {
                    damage_sprite = sprites[temp_flag];
                }
                this->damage_sprites[index].sprite = damage_sprite;
                this->damage_sprites[index].damage_percent = local_82[0];
                this->damage_sprites[index].flag =
                    static_cast<unsigned char>(temp_death_sound);
                ++index;
            } while (index < static_cast<short>(
                           static_cast<unsigned short>(
                               this->damage_sprite_num)));
        }
    }

    fscanf(file, "%hd %hd %hd %hd", &temp_death_sprite, &temp_sprite,
           &temp_convert_terrain_flag, &temp_map_color);

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

    this->elevation_flag = local_84[0];
    this->sort_number = static_cast<unsigned char>(temp_available);
    this->movement_type = static_cast<unsigned char>(temp_created_sound);
    this->fog_flag = static_cast<unsigned char>(temp_sort_number);
    this->select_level = static_cast<unsigned char>(temp_map_draw_level);
    this->obj_max = static_cast<unsigned char>(temp_movement_type);
    this->can_be_built_on = static_cast<unsigned char>(temp_damage_percent);
    this->available = static_cast<unsigned char>(temp_attribute_flag);
    this->area_effect_object_level =
        static_cast<unsigned char>(temp_damage_sprite);
    this->terrain = static_cast<short>(
        static_cast<unsigned char>(temp_undead_flag));
    this->combat_level = static_cast<unsigned char>(temp_select_level);
    this->map_draw_level = static_cast<unsigned char>(temp_command_level);
    this->attack_reaction =
        static_cast<unsigned char>(temp_convert_terrain_flag);
    this->unit_level = static_cast<unsigned char>(temp_terrain);
    this->undead_flag =
        static_cast<unsigned char>(temp_hide_in_scenario_editor);
    this->track_as_resource = static_cast<unsigned char>(
        temp_create_doppleganger_on_death);
    this->hide_in_scenario_editor =
        static_cast<unsigned char>(temp_attack_reaction);
    this->convert_terrain_flag = static_cast<unsigned char>(temp_map_color);
    this->draw_flag = static_cast<unsigned char>(temp_draw_color);
    this->map_color = static_cast<unsigned char>(temp_track_as_resource);
    this->create_doppleganger_on_death =
        static_cast<unsigned char>(temp_resource_group);
    this->resource_group = static_cast<unsigned char>(temp_draw_flag);
    this->draw_color = static_cast<unsigned char>(temp_elevation_flag);

    if (this->outline_radius_x == DAT_00570618 ||
        this->outline_radius_x != this->outline_radius_x) {
        this->outline_radius_x = this->radius_x;
    }
    if (this->outline_radius_y == DAT_00570618 ||
        this->outline_radius_y != this->outline_radius_y) {
        this->outline_radius_y = this->radius_y;
    }
    if (this->outline_radius_z == DAT_00570618 ||
        this->outline_radius_z != this->outline_radius_z) {
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
    RGE_Player* player, float x, float y, float z) {
    if (recyclable) {
        RGE_Static_Object* recycled = player->world->recycle_object_in_to_game(master_type);
        if (recycled) {
            recycled->recycle_in_to_game(this, player, x, y, z);
            return recycled;
        }
    }

    return new RGE_Static_Object(this, player, x, y, z, 1);
}

RGE_Master_Static_Object* RGE_Master_Static_Object::make_new_master(void) {
    return new RGE_Master_Static_Object(this, 1);
}

void RGE_Master_Static_Object::copy_obj(RGE_Master_Static_Object* src) {
    short id_val = id;
    short copy_id_val = copy_id;
    unsigned char available_val = available;
    short hide_val = hide_in_scenario_editor;
    char** name_ptr = &name;

    if (*name_ptr != 0) {
        free(*name_ptr);
    }

    master_type = src->master_type;
    *name_ptr = src->name;
    string_id = src->string_id;
    string_id2 = src->string_id2;
    id = src->id;
    copy_id = src->copy_id;
    object_group = src->object_group;
    sprite = src->sprite;
    death_sprite = src->death_sprite;
    undead_sprite = src->undead_sprite;
    undead_flag = src->undead_flag;
    hp = src->hp;
    los = src->los;
    obj_max = src->obj_max;
    radius_x = src->radius_x;
    radius_y = src->radius_y;
    radius_z = src->radius_z;
    selected_sound = src->selected_sound;
    created_sound = src->created_sound;
    death_sound = src->death_sound;
    death_spawn_obj_id = src->death_spawn_obj_id;
    sort_number = src->sort_number;
    can_be_built_on = src->can_be_built_on;
    button_pict = src->button_pict;
    hide_in_scenario_editor = src->hide_in_scenario_editor;
    portrait_pict = src->portrait_pict;
    available = src->available;
    tile_req1 = src->tile_req1;
    tile_req2 = src->tile_req2;
    center_tile_req1 = src->center_tile_req1;
    center_tile_req2 = src->center_tile_req2;
    construction_radius_x = src->construction_radius_x;
    construction_radius_y = src->construction_radius_y;
    elevation_flag = src->elevation_flag;
    fog_flag = src->fog_flag;
    terrain = src->terrain;
    movement_type = src->movement_type;

    {
        unsigned int type_index = 0;
        do {
            attribute_type_held[type_index] = src->attribute_type_held[type_index];
            type_index++;
        } while (type_index < 3);

        unsigned int amount_index = 0;
        do {
            attribute_amount_held[amount_index] = src->attribute_amount_held[amount_index];
            amount_index++;
        } while (amount_index < 3);
    }

    attribute_max_amount = src->attribute_max_amount;
    attribute_rot = src->attribute_rot;
    multiple_attribute_mod = src->multiple_attribute_mod;

    {
        unsigned int flag_index = 0;
        do {
            attribute_flag[flag_index] = src->attribute_flag[flag_index];
            flag_index++;
        } while (flag_index < 3);
    }

    area_effect_object_level = src->area_effect_object_level;
    combat_level = src->combat_level;
    select_level = src->select_level;
    map_draw_level = src->map_draw_level;
    unit_level = src->unit_level;
    map_color = src->map_color;
    attack_reaction = src->attack_reaction;
    convert_terrain_flag = src->convert_terrain_flag;
    damage_sprite_num = src->damage_sprite_num;
    damage_sprites = src->damage_sprites;
    help_string_id = src->help_string_id;
    help_page_id = src->help_page_id;
    hotkey_id = src->hotkey_id;
    recyclable = src->recyclable;
    track_as_resource = src->track_as_resource;
    create_doppleganger_on_death = src->create_doppleganger_on_death;
    resource_group = src->resource_group;
    draw_flag = src->draw_flag;
    draw_color = src->draw_color;
    outline_radius_x = src->outline_radius_x;
    outline_radius_y = src->outline_radius_y;
    outline_radius_z = src->outline_radius_z;

    if (src->hide_in_scenario_editor == 1) {
        copy_id = copy_id_val;
    }
    hide_in_scenario_editor = (unsigned char)hide_val;
    src->hide_in_scenario_editor = 1;

    if (damage_sprite_num > 0) {
        damage_sprites = static_cast<RGE_Damage_Sprite_Info*>(
            calloc(damage_sprite_num, 8));
        int i = 0;
        if (damage_sprite_num > 0) {
            do {
                damage_sprites[i].sprite = src->damage_sprites[i].sprite;
                damage_sprites[i].damage_percent = src->damage_sprites[i].damage_percent;
                damage_sprites[i].flag = src->damage_sprites[i].flag;
                i++;
            } while (i < (unsigned char)damage_sprite_num);
        }
    } else {
        damage_sprites = 0;
    }

    *name_ptr = 0;
    getstring(name_ptr, src->name);
    id = id_val;
    available = available_val;
}

void RGE_Master_Static_Object::modify(float value, unsigned char op) {
    switch (op) {
        case 0:
            hp = (short)(long)value;
            break;
        case 1:
            los = value;
            break;
        case 2:
            obj_max = (unsigned char)(long)value;
            break;
        case 3:
            radius_x = value;
            break;
        case 4:
            radius_y = value;
            break;
        case 14:
            attribute_max_amount = (short)(long)value;
            break;
    }
}

void RGE_Master_Static_Object::modify_delta(float value, unsigned char op) {
    switch (op) {
        case 0:
            hp += (short)(long)value;
            break;
        case 1:
            los = (float)((double)value + (double)los);
            break;
        case 2:
            obj_max += (unsigned char)(long)value;
            break;
        case 3:
            radius_x = (float)((double)value + (double)radius_x);
            break;
        case 4:
            radius_y = (float)((double)value + (double)radius_y);
            break;
        case 14:
            attribute_max_amount += (short)(long)value;
            break;
    }
}

void RGE_Master_Static_Object::modify_percent(float value, unsigned char op) {
    switch (op) {
        case 0:
            hp = (short)((float)hp * value);
            break;
        case 1:
            los = (float)((double)value * (double)los);
            break;
        case 2:
            obj_max = (unsigned char)((float)obj_max * value);
            break;
        case 3:
            radius_x = (float)((double)value * (double)radius_x);
            break;
        case 4:
            radius_y = (float)((double)value * (double)radius_y);
            break;
        case 14:
            attribute_max_amount = (short)((float)attribute_max_amount * value);
            break;
    }
}

void RGE_Master_Static_Object::save(int fd) {
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

    rge_write(fd, (void*)(&self->master_type), 1);
    rge_write(fd, (void*)(&name_size), 2);
    rge_write(fd, (void*)(&self->id), 2);
    rge_write(fd, (void*)(&self->string_id), 2);
    rge_write(fd, (void*)(&self->string_id2), 2);
    rge_write(fd, (void*)(&self->object_group), 2);
    rge_write(fd, (void*)(&temp_death_sprite), 2);
    rge_write(fd, (void*)(&temp_undead_sprite), 2);
    rge_write(fd, (void*)(&created_sound_num), 2);
    rge_write(fd, (void*)(&self->undead_flag), 1);
    rge_write(fd, (void*)(&self->hp), 2);
    rge_write(fd, (void*)(&self->los), 4);
    rge_write(fd, (void*)(&self->obj_max), 1);
    rge_write(fd, (void*)(&self->radius_x), 4);
    rge_write(fd, (void*)(&self->radius_y), 4);
    rge_write(fd, (void*)(&self->radius_z), 4);
    rge_write(fd, (void*)(&temp_sprite), 2);
    rge_write(fd, (void*)(&self->death_spawn_obj_id), 2);
    rge_write(fd, (void*)(&self->sort_number), 1);
    rge_write(fd, (void*)(&self->can_be_built_on), 1);
    rge_write(fd, (void*)(&self->button_pict), 2);
    rge_write(fd, (void*)(&self->hide_in_scenario_editor), 1);
    rge_write(fd, (void*)(&self->portrait_pict), 2);
    rge_write(fd, (void*)(&self->available), 1);
    rge_write(fd, (void*)(&self->tile_req1), 2);
    rge_write(fd, (void*)(&self->tile_req2), 2);
    rge_write(fd, (void*)(&self->center_tile_req1), 2);
    rge_write(fd, (void*)(&self->center_tile_req2), 2);
    rge_write(fd, (void*)(&self->construction_radius_x), 4);
    rge_write(fd, (void*)(&self->construction_radius_y), 4);
    rge_write(fd, (void*)(&self->elevation_flag), 1);
    rge_write(fd, (void*)(&self->fog_flag), 1);
    rge_write(fd, (void*)(&self->terrain), 2);
    rge_write(fd, (void*)(&self->movement_type), 1);
    rge_write(fd, (void*)(&self->attribute_max_amount), 2);
    rge_write(fd, (void*)(&self->attribute_rot), 4);
    rge_write(fd, (void*)(&self->area_effect_object_level), 1);
    rge_write(fd, (void*)(&self->combat_level), 1);
    rge_write(fd, (void*)(&self->select_level), 1);
    rge_write(fd, (void*)(&self->map_draw_level), 1);
    rge_write(fd, (void*)(&self->unit_level), 1);
    rge_write(fd, (void*)(&self->multiple_attribute_mod), 4);
    rge_write(fd, (void*)(&self->map_color), 1);
    rge_write(fd, (void*)(&self->help_string_id), 4);
    rge_write(fd, (void*)(&self->help_page_id), 4);
    rge_write(fd, (void*)(&self->hotkey_id), 4);
    rge_write(fd, (void*)(&self->recyclable), 1);
    rge_write(fd, (void*)(&self->track_as_resource), 1);
    rge_write(fd, (void*)(&self->create_doppleganger_on_death), 1);
    rge_write(fd, (void*)(&self->resource_group), 1);
    rge_write(fd, (void*)(&self->draw_flag), 1);
    rge_write(fd, (void*)(&self->draw_color), 1);
    rge_write(fd, (void*)(&self->outline_radius_x), 4);
    rge_write(fd, (void*)(&self->outline_radius_y), 4);
    rge_write(fd, (void*)(&self->outline_radius_z), 4);

    unsigned char* soundPtr = self->attribute_flag;
    float* selectedProb = self->attribute_amount_held;
    short* selected = self->attribute_type_held;
    int i = 3;
    do {
        rge_write(fd, (void*)(selected), 2);
        rge_write(fd, (void*)(selectedProb), 4);
        rge_write(fd, (void*)(soundPtr), 1);
        selected++;
        selectedProb++;
        soundPtr++;
        --i;
    } while (i);

    rge_write(fd, (void*)(&self->damage_sprite_num), 1);
    if (0 < self->damage_sprite_num) {
        short j = 0;
        if (self->damage_sprite_num > 0) {
            do {
                rge_write(fd, (void*)(&self->damage_sprites[j].sprite->id), 2);
                // The beta save stream writes two bytes here.
                rge_write(fd, (void*)(&self->damage_sprites[j].damage_percent), 2);
                rge_write(fd, (void*)(&self->damage_sprites[j].flag), 1);
                j++;
            } while (j < (short)self->damage_sprite_num);
        }
    }

    rge_write(fd, (void*)(&death_sound_num), 2);
    rge_write(fd, (void*)(&selected_sound_num), 2);
    rge_write(fd, (void*)(&self->attack_reaction), 1);
    rge_write(fd, (void*)(&self->convert_terrain_flag), 1);
    if (name_size != 0) {
        rge_write(fd, (void*)(self->name),  name_size);
    }
    rge_write(fd, (void*)(&self->copy_id), 2);
}

unsigned char RGE_Master_Static_Object::check_placement(
    RGE_Player* player, float x, float y, int* blocking_object,
    unsigned char check_visible, unsigned char check_elevation,
    unsigned char, unsigned char use_construction_radius,
    unsigned char allow_build_on, unsigned char check_objects) {
    float* terrain_table = player->world->terrains[this->terrain];
    RGE_Map* map = player->world->map;
    float radius_x;
    float radius_y;

    if (use_construction_radius != 0) {
        radius_x = this->construction_radius_x;
        radius_y = this->construction_radius_y;
    } else {
        radius_x = this->radius_x;
        radius_y = this->radius_y;
    }

    float min_x_value = x - radius_x;
    float max_x_value = x + radius_x - DAT_0057061c;
    float min_y_value = y - radius_y;
    float max_y_value = y + radius_y - DAT_0057061c;

    if (!(min_x_value >= DAT_00570620) ||
        !(max_x_value < (float)map->map_width) ||
        !(min_y_value >= DAT_00570620) ||
        !(max_y_value < (float)map->map_height)) {
        return 7;
    }

    short min_x = (short)(long)min_x_value;
    short max_x = (short)(long)max_x_value;
    short min_y = (short)(long)min_y_value;
    short max_y = (short)(long)max_y_value;
    short edge_min_x = min_x;
    short edge_max_x = max_x;
    short edge_min_y = min_y;
    short edge_max_y = max_y;

    if (this->center_tile_req1 >= 0 || this->center_tile_req2 >= 0) {
        short center_y = (short)(long)y;
        short center_x = (short)(long)x;
        short center_terrain =
            map->map_row_offset[center_y][center_x].terrain_type;
        if (center_terrain != this->center_tile_req1 &&
            center_terrain != this->center_tile_req2) {
            return 1;
        }
        edge_min_x = center_x;
        edge_max_x = center_x;
        edge_min_y = center_y;
        edge_max_y = center_y;
    }

    if (this->tile_req1 >= 0 || this->tile_req2 >= 0) {
        unsigned char found_tile_req1 = 0;
        unsigned char found_tile_req2 = 0;
        short edge = (short)(edge_min_y - 1);
        if (edge >= 0 && edge_min_x <= edge_max_x) {
            RGE_Tile* tile = map->map_row_offset[edge] + edge_min_x;
            int count = (int)edge_max_x - (int)edge_min_x + 1;
            do {
                short terrain = tile->terrain_type;
                if (terrain == this->tile_req1) found_tile_req1 = 1;
                if (terrain == this->tile_req2) found_tile_req2 = 1;
                ++tile;
                --count;
            } while (count != 0);
        }

        edge = (short)(edge_max_x + 1);
        if (edge < map->map_width && edge_min_y <= edge_max_y) {
            RGE_Tile** row = map->map_row_offset + edge_min_y;
            int count = (int)edge_max_y - (int)edge_min_y + 1;
            do {
                short terrain = (*row)[edge].terrain_type;
                if (terrain == this->tile_req1) found_tile_req1 = 1;
                if (terrain == this->tile_req2) found_tile_req2 = 1;
                ++row;
                --count;
            } while (count != 0);
        }

        edge = (short)(edge_max_y + 1);
        if (edge < map->map_height && edge_min_x <= edge_max_x) {
            RGE_Tile* tile = map->map_row_offset[edge] + edge_max_x;
            int count = (int)edge_max_x - (int)edge_min_x + 1;
            do {
                short terrain = tile->terrain_type;
                if (terrain == this->tile_req1) found_tile_req1 = 1;
                if (terrain == this->tile_req2) found_tile_req2 = 1;
                --tile;
                --count;
            } while (count != 0);
        }

        edge = (short)(edge_min_x - 1);
        if (edge >= 0 && edge_min_y <= edge_max_y) {
            RGE_Tile** row = map->map_row_offset + edge_max_y;
            int count = (int)edge_max_y - (int)edge_min_y + 1;
            do {
                short terrain = (*row)[edge].terrain_type;
                if (terrain == this->tile_req1) found_tile_req1 = 1;
                if (terrain == this->tile_req2) found_tile_req2 = 1;
                --row;
                --count;
            } while (count != 0);
        }

        if (found_tile_req1 == 0 && found_tile_req2 == 0) {
            return 1;
        }
    }

    unsigned char visible = 0;
    for (short tile_x = min_x; tile_x <= max_x; tile_x++) {
        for (short tile_y = min_y; tile_y <= max_y; tile_y++) {
            RGE_Tile* tile = &map->map_row_offset[tile_y][tile_x];
            if (!(terrain_table[tile->terrain_type] > DAT_00570618)) {
                return 2;
            }

            if (check_visible != 0 &&
                (rge_base_game->prog_mode == 7 ||
                 player->visible->get_visible(tile_x, tile_y) != 0)) {
                visible = 1;
            }

            if (check_elevation != 0) {
                unsigned char tile_type = tile->tile_type;
                if (this->elevation_flag == 1) {
                    if (tile_type != 0 && tile_type != 5 && tile_type != 7 &&
                        tile_type != 6 && tile_type != 8) {
                        return 3;
                    }
                } else if (this->elevation_flag == 2 && tile_type != 0) {
                    return 3;
                }
            }
        }
    }

    if (check_visible == 1 && visible == 0) {
        return 5;
    }

    if (!(radius_x > DAT_00570618) && !(radius_y > DAT_00570618)) {
        return 0;
    }

    short object_min_x = (short)(long)(x - DAT_00570628);
    short object_min_y = (short)(long)(y - DAT_00570628);
    short object_max_x = (short)(long)(x - DAT_0057062c);
    short object_max_y = (short)(long)(y - DAT_0057062c);

    if (object_min_x < 0) object_min_x = 0;
    if (object_max_x >= map->map_width) {
        object_max_x = (short)map->map_width - 1;
    }
    if (object_min_y < 0) object_min_y = 0;
    if (object_max_y >= map->map_height) {
        object_max_y = (short)map->map_height - 1;
    }

    if (check_objects != 0 &&
        (allow_build_on != 0 || this->radius_z > DAT_00570620) &&
        object_min_y <= object_max_y) {
        for (short tile_y = object_min_y;
             tile_y <= object_max_y; tile_y++) {
            RGE_Tile* tile =
                &map->map_row_offset[tile_y][object_min_x];
            for (short tile_x = object_min_x;
                 tile_x <= object_max_x; tile_x++, tile++) {
                RGE_Object_Node* object_node = tile->objects.list;
                while (object_node != 0) {
                    RGE_Static_Object* object = object_node->node;
                    if (object->object_state < 7 &&
                        (allow_build_on == 0 ||
                         object->master_obj->can_be_built_on != 1 ||
                         this->can_be_built_on != 0)) {
                        RGE_Master_Static_Object* master = object->master_obj;
                        float object_radius_x = master->radius_x;
                        float object_radius_y = master->radius_y;
                        float object_radius_z = master->radius_z;
                        if (object_radius_x > DAT_00570620 &&
                            object_radius_y > DAT_00570620 &&
                            ((object_radius_z > DAT_00570620 &&
                              this->radius_z > DAT_00570620) ||
                             (!(object_radius_z > DAT_00570620) &&
                              !(this->radius_z > DAT_00570620)))) {
                            float distance_y = object->world_y - y;
                            float distance_x = object->world_x - x;
                            if (distance_y < DAT_00570618) {
                                distance_y = -distance_y;
                            }
                            if (distance_x < DAT_00570618) {
                                distance_x = -distance_x;
                            }
                            if (!(distance_x >= object_radius_x + radius_x) &&
                                !(distance_y >= object_radius_y + radius_y)) {
                                if (blocking_object != 0) {
                                    *blocking_object = object->id;
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

void RGE_Master_Static_Object::make_available(unsigned char v) {
    this->available = v;
}

unsigned char RGE_Master_Static_Object::alignment(
    float& x, float& y, RGE_Game_World* world, unsigned char align) {
    float left = x - this->radius_x;
    float top = y - this->radius_y;
    float right = x + this->radius_x;
    float bottom = y + this->radius_y;
    float map_width = (float)world->map->map_width - 0.00001f;
    float map_height = (float)world->map->map_height - 0.00001f;
    float aligned_x;
    float aligned_y;

    if (left < 0.0f) {
        left = -left;
        right += left;
        x += left;
        left = 0.0f;
    }
    if (top < 0.0f) {
        top = -top;
        bottom += top;
        y += top;
        top = 0.0f;
    }
    if (right >= map_width) {
        left += map_width - right;
        x += map_width - right;
        right = map_width;
    }
    if (bottom >= map_height) {
        top += map_height - bottom;
        y += map_height - bottom;
        bottom = map_height;
    }

    if (align != 0) {
        if (left < 0.0f) left = -left;
        if (top < 0.0f) top = -top;
        if (right < 0.0f) right = -right;
        if (bottom < 0.0f) bottom = -bottom;

        left -= (short)left;
        top -= (short)top;
        right = 1.0f - (right - (short)right);
        bottom = 1.0f - (bottom - (short)bottom);

        if (left + right >= 1.0f) {
            if (left > right) {
                aligned_x = x + (1.0f - left);
            } else {
                aligned_x = x - (1.0f - right);
            }
        } else {
            aligned_x = x;
        }

        if (top + bottom >= 1.0f) {
            if (top > bottom) {
                aligned_y = y + (1.0f - top);
            } else {
                aligned_y = y - (1.0f - bottom);
            }
        } else {
            aligned_y = y;
        }

        x = aligned_x;
        y = aligned_y;
    }
    return 1;
}

unsigned char RGE_Master_Static_Object::alignment_box(
    RGE_Game_World* world, float x, float y,
    short& x1, short& y1, short& x2, short& y2,
    short& x3, short& y3, short& x4, short& y4) {
    short tile_x;
    short tile_y;
    float x_offset;
    float y_offset;
    tile_x = (short)x;
    tile_y = (short)y;
    x_offset = x - (float)tile_x + this->radius_x;
    y_offset = y - (float)tile_y + this->radius_y;
    short tile_half_width = world->map->tile_half_width;
    short tile_half_height = world->map->tile_half_height;

    x1 = (short)((x_offset + y_offset) * tile_half_width);
    y1 = (short)((y_offset + 1.0 - x_offset) * tile_half_height);
    x_offset -= 2.0f * this->radius_x;
    x2 = (short)((x_offset + y_offset) * tile_half_width);
    y2 = (short)((y_offset + 1.0 - x_offset) * tile_half_height);
    y_offset -= 2.0f * this->radius_y;
    x3 = (short)((x_offset + y_offset) * tile_half_width);
    y3 = (short)((y_offset + 1.0 - x_offset) * tile_half_height);
    x_offset += (this->radius_x + this->radius_x);
    x4 = (short)((x_offset + y_offset) * tile_half_width);
    y4 = (short)((y_offset + 1.0 - x_offset) * tile_half_height);
    return 1;
}

void RGE_Master_Static_Object::draw(
    TDrawArea* draw_area, short x, short y, RGE_Color_Table* color_table,
    long param_5, long param_6, int param_7, unsigned char param_8) {
    if (this->sprite != 0) {
        this->sprite->draw(param_5, param_6, (int)x, (int)y, (int)x, (int)y,
                           color_table, draw_area, 10);

        if (param_7 != 0) {
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

            SDI_List->AddGDINode(1, (int)y, x1, y1, x2, y2, x3, y3, x4, y4,
                                 10, (int)(param_8 & 0xFF), SDI_Object_ID);
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
    RGE_Master_Combat_Object* param) {
    float total = 0.0f;
    int count = param->weapon_num;
    RGE_Armor_Weapon_Info* weapon = param->weapon;
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
