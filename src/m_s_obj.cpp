
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

extern "C" void __cdecl rge_read(int handle, void* buffer, int size);
extern "C" void __cdecl rge_write(int fd, void* src, int size);
extern float save_game_version;
extern float DAT_00570610;
extern float DAT_00570614;
extern float DAT_00570618;

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

    for (int i = 0; i < 3; ++i) {
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
    FILE* fp, RGE_Sprite** sprites, RGE_Sound** sounds, short object_id) {
    char object_name[120];
    short sprite_id;
    short death_sprite_id;
    short undead_sprite_id;
    short undead_flag_value;
    short obj_max_value;
    short movement_type_value;
    short sort_number_value;
    short fog_flag_value;
    short terrain_value;
    short elevation_flag_value;
    short can_be_built_on_value;
    short created_sound_id;
    short available_value;
    short hide_in_scenario_editor_value;
    short area_effect_object_level_value;
    short combat_level_value;
    short select_level_value;
    short map_draw_level_value;
    short attack_reaction_value;
    short unit_level_value;
    short map_color_value;
    short track_as_resource_value;
    short convert_terrain_flag_value;
    short create_doppleganger_value;
    short resource_group_value;
    short draw_flag_value;
    short draw_color_value;
    short attribute_flag_value;
    short damage_sprite_count;
    short damage_sprite_id;
    short damage_percent;
    short damage_flag;
    short selected_sound_id;
    short death_sound_id;
    RGE_Sound* sound_value;
    RGE_Sprite* sprite_value;

    master_type = 10;
    id = object_id;

    fscanf(fp, "%s %hd %hd %hd %hd %hd %hd %hd %hd %f %hd %f %f %f %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %f %f %hd %hd %hd %hd %hd %hd %f %f %hd %hd %hd %hd %hd %hd %d %d %d %hd %hd %hd %hd %hd %f %f %f", object_name, &string_id, &string_id2, &object_group, &sprite_id,
           &death_sprite_id, &undead_sprite_id, &undead_flag_value, &hp, &los, &obj_max_value, &radius_x,
           &radius_y, &radius_z, &death_spawn_obj_id, &sort_number_value, &can_be_built_on_value,
           &button_pict, &hide_in_scenario_editor_value, &portrait_pict, &available_value, &tile_req1,
           &tile_req2, &center_tile_req1, &center_tile_req2, &construction_radius_x,
           &construction_radius_y, &elevation_flag_value, &fog_flag_value, &terrain_value,
           &created_sound_id, &movement_type_value, &attribute_max_amount,
           &multiple_attribute_mod, &attribute_rot,
           &area_effect_object_level_value, &combat_level_value, &select_level_value,
           &map_draw_level_value, &unit_level_value, &map_color_value,
           &help_string_id, &help_page_id, &hotkey_id, &track_as_resource_value,
           &create_doppleganger_value, &resource_group_value, &draw_flag_value,
           &draw_color_value,
           &outline_radius_x, &outline_radius_y, &outline_radius_z);

    for (int i = 0; i < 3; ++i) {
        fscanf(fp, "%hd %f %hd", &attribute_type_held[i],
               &attribute_amount_held[i], &attribute_flag_value);
        attribute_flag[i] = static_cast<unsigned char>(attribute_flag_value);
    }

    fscanf(fp, "%hd", &damage_sprite_count);
    damage_sprite_num = static_cast<unsigned char>(damage_sprite_count);
    if (damage_sprite_num > 0) {
        damage_sprites = static_cast<RGE_Damage_Sprite_Info*>(
            calloc(damage_sprite_num, sizeof(*damage_sprites)));
        for (short i = 0; i < damage_sprite_num; ++i) {
            fscanf(fp, "%hd %hd %hd", &damage_sprite_id, &damage_percent,
                   &damage_flag);
            damage_sprites[i].sprite = damage_sprite_id >= 0
                ? sprites[damage_sprite_id] : 0;
            damage_sprites[i].damage_percent =
                static_cast<unsigned char>(damage_percent);
            damage_sprites[i].flag = static_cast<unsigned char>(damage_flag);
        }
    } else {
        damage_sprites = 0;
    }

    fscanf(fp, "%hd %hd %hd %hd", &selected_sound_id, &death_sound_id,
           &attack_reaction_value, &convert_terrain_flag_value);

    if (selected_sound_id >= 0) sound_value = sounds[selected_sound_id];
    else sound_value = 0;
    selected_sound = sound_value;
    if (death_sound_id >= 0) sound_value = sounds[death_sound_id];
    else sound_value = 0;
    death_sound = sound_value;
    if (created_sound_id >= 0) sound_value = sounds[created_sound_id];
    else sound_value = 0;
    created_sound = sound_value;
    if (sprite_id >= 0) sprite_value = sprites[sprite_id];
    else sprite_value = 0;
    sprite = sprite_value;
    if (death_sprite_id >= 0) sprite_value = sprites[death_sprite_id];
    else sprite_value = 0;
    death_sprite = sprite_value;
    if (undead_sprite_id >= 0) sprite_value = sprites[undead_sprite_id];
    else sprite_value = 0;
    undead_sprite = sprite_value;

    elevation_flag = static_cast<unsigned char>(elevation_flag_value);
    sort_number = static_cast<unsigned char>(sort_number_value);
    movement_type = static_cast<unsigned char>(movement_type_value);
    fog_flag = static_cast<unsigned char>(fog_flag_value);
    select_level = static_cast<unsigned char>(select_level_value);
    obj_max = static_cast<unsigned char>(obj_max_value);
    can_be_built_on = static_cast<unsigned char>(can_be_built_on_value);
    available = static_cast<unsigned char>(available_value);
    area_effect_object_level = static_cast<unsigned char>(area_effect_object_level_value);
    terrain = static_cast<unsigned char>(terrain_value);
    combat_level = static_cast<unsigned char>(combat_level_value);
    map_draw_level = static_cast<unsigned char>(map_draw_level_value);
    attack_reaction = static_cast<unsigned char>(attack_reaction_value);
    unit_level = static_cast<unsigned char>(unit_level_value);
    undead_flag = static_cast<unsigned char>(undead_flag_value);
    track_as_resource = static_cast<unsigned char>(track_as_resource_value);
    hide_in_scenario_editor = static_cast<unsigned char>(hide_in_scenario_editor_value);
    convert_terrain_flag = static_cast<unsigned char>(convert_terrain_flag_value);
    draw_flag = static_cast<unsigned char>(draw_flag_value);
    map_color = static_cast<unsigned char>(map_color_value);
    create_doppleganger_on_death = static_cast<unsigned char>(create_doppleganger_value);
    resource_group = static_cast<unsigned char>(resource_group_value);
    draw_color = static_cast<unsigned char>(draw_color_value);

    if (outline_radius_x == DAT_00570618) outline_radius_x = radius_x;
    if (outline_radius_y == DAT_00570618) outline_radius_y = radius_y;
    if (outline_radius_z == DAT_00570618) outline_radius_z = radius_z;

    recyclable = 0;
    copy_id = id;
    if (object_group == 11) recyclable = 1;

    if (strlen(object_name) > 0) {
        name = 0;
        getstring(&name, object_name);
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
    RGE_Player* player, float x, float y, int* obj_id,
    unsigned char p5, unsigned char p6, unsigned char p7,
    unsigned char p8, unsigned char p9, unsigned char p10) {
    RGE_Map* map = player->world->map;
    float* terrain_cost = player->world->terrains[terrain];

    float radius_x_value, radius_y_value;
    if (p8 != 0) {
        radius_x_value = construction_radius_x;
        radius_y_value = construction_radius_y;
    } else {
        radius_x_value = radius_x;
        radius_y_value = radius_y;
    }

    float left_edge = x - radius_x_value;
    float right_edge = radius_x_value + x;
    float bottom_edge = radius_y_value + y;
    float top_edge = y - radius_y_value;
    if (left_edge < 0.0 ||
        (float)map->map_width <= right_edge - 0.001f ||
        top_edge < 0.0 ||
        (float)map->map_height <= bottom_edge - 0.001f) {
        return 7;
    }

    short x_min = (short)left_edge;
    short x_max = (short)(right_edge - 0.001f);
    short y_min = (short)top_edge;
    short y_max = (short)(bottom_edge - 0.001f);

    short center_y;
    short center_x;
    short edge_y_min;
    short edge_x_max;
    short edge_y_max;
    short edge_x_min;
    short req_center1 = center_tile_req1;

    if (req_center1 >= 0 || center_tile_req2 >= 0) {
        center_y = (short)y;
        center_x = (short)x;
        unsigned short center_terrain =
            (unsigned short)(map->map_row_offset[center_y][center_x].terrain_type & 0x1f);
        if (center_terrain != (unsigned short)req_center1 &&
            center_terrain != (unsigned short)center_tile_req2) {
            return 1;
        }
        edge_y_min = center_y;
        edge_x_min = center_x;
        edge_x_max = center_x;
        edge_y_max = center_y;
    } else {
        edge_x_max = x_max;
        edge_x_min = x_min;
        edge_y_min = y_min;
        edge_y_max = y_max;
    }

    unsigned char req_terr1 = 0;
    unsigned char req_terr2 = 0;
    short req_terrain1 = tile_req1;

    if (req_terrain1 >= 0 || tile_req2 >= 0) {
        short terrain_table = (short)(edge_x_min - 1);

        if ((short)(edge_y_min - 1) >= 0 && edge_x_min <= edge_x_max) {
            for (short col = edge_x_min; col <= edge_x_max; ++col) {
                unsigned short t = static_cast<unsigned short>(
                    map->map_row_offset[edge_y_min - 1][col].terrain_type & 0x1f);
                if (t == (unsigned short)req_terrain1) req_terr1 = 1;
                if (t == (unsigned short)tile_req2) req_terr2 = 1;
            }
        }

        if ((short)(edge_x_max + 1) < map->map_width && edge_y_min <= edge_y_max) {
            for (short row = edge_y_min; row <= edge_y_max; ++row) {
                unsigned short t = static_cast<unsigned short>(
                    map->map_row_offset[row][edge_x_max + 1].terrain_type & 0x1f);
                if (t == (unsigned short)req_terrain1) req_terr1 = 1;
                if (t == (unsigned short)tile_req2) req_terr2 = 1;
            }
        }

        if ((short)(edge_y_max + 1) < map->map_height && edge_x_min <= edge_x_max) {
            for (short col = edge_x_max; col >= edge_x_min; --col) {
                unsigned short t = static_cast<unsigned short>(
                    map->map_row_offset[edge_y_max + 1][col].terrain_type & 0x1f);
                if (t == (unsigned short)req_terrain1) req_terr1 = 1;
                if (t == (unsigned short)tile_req2) req_terr2 = 1;
            }
        }

        if (terrain_table >= 0 && edge_y_min <= edge_y_max) {
            for (short row = edge_y_max; row >= edge_y_min; --row) {
                unsigned short t = static_cast<unsigned short>(
                    map->map_row_offset[row][terrain_table].terrain_type & 0x1f);
                if (t == (unsigned short)req_terrain1) req_terr1 = 1;
                if (t == (unsigned short)tile_req2) req_terr2 = 1;
            }
        }

        if (!req_terr1 && !req_terr2) return 1;
    }

    unsigned char part_vis = 0;
    short x_index;
    short y_index;
    for (x_index = x_min; x_index <= x_max; x_index++) {
        for (y_index = y_min; y_index <= y_max; y_index++) {
            unsigned char ct =
                (unsigned char)(map->map_row_offset[y_index][x_index].terrain_type & 0x1f);
            if (terrain_cost[ct] <= 0.0f) {
                return 2;
            }
            if (p5 != 0 &&
                (rge_base_game->prog_mode == 7 ||
                 player->visible->get_visible(x_index, y_index))) {
                part_vis = 1;
            }
            if (p6 != 0) {
                unsigned short tt =
                    map->map_row_offset[y_index][x_index].tile_type;
                switch (elevation_flag) {
                    case 1:
                        if ((tt != 0 && tt != 5 && tt != 7) &&
                            (tt != 6 && tt != 8)) {
                            return 3;
                        }
                        break;
                    case 2:
                        if (tt != 0) {
                            return 3;
                        }
                        break;
                }
            }
        }
    }

    if (p5 == 1 && !part_vis) return 5;
    if (radius_x_value <= 0.0f && radius_y_value <= 0.0f) return 0;

    x_min = (short)(x - 3.0f);
    y_min = (short)(y - 3.0f);
    x_max = (short)(x - (-3.0f));
    y_max = (short)(y - (-3.0f));
    if (x_min < 0) x_min = 0;
    if (x_max >= map->map_width) x_max = (short)map->map_width - 1;
    if (y_min < 0) y_min = 0;
    if (y_max >= map->map_height) y_max = (short)map->map_height - 1;

    if (p10 != 0 && (p9 != 0 || radius_z > 0.0) &&
        y_min <= y_max) {
        y_index = y_min;
        do {
            if (x_min <= x_max) {
                x_index = x_min;
                RGE_Tile* tile = &map->map_row_offset[y_index][x_min];
                do {
                    for (RGE_Object_Node* node = tile->objects.list;
                         node != 0; node = node->next) {
                        RGE_Static_Object* obj = node->node;
                        if (obj->object_state < 7 &&
                            ((p9 == 0 || obj->master_obj->can_be_built_on != 1) ||
                             can_be_built_on != 0)) {
                            RGE_Master_Static_Object* master = obj->master_obj;
                            float mrx = master->radius_x;
                            float mry = master->radius_y;
                            float mrz = master->radius_z;
                            if ((mrx > 0.0 && mry > 0.0) &&
                                ((mrz > 0.0 && radius_z > 0.0) ||
                                 (mrz <= 0.0 && radius_z <= 0.0))) {
                                float dy = obj->world_y - y;
                                float dx = obj->world_x - x;
                                if (dy < 0.0f) dy = -dy;
                                if (dx < 0.0f) dx = -dx;
                                if (dx < mrx + radius_x_value &&
                                    dy < mry + radius_y_value) {
                                    if (obj_id != 0) *obj_id = obj->id;
                                    return 6;
                                }
                            }
                        }
                    }
                    ++tile;
                    ++x_index;
                } while (x_index <= x_max);
            }
            y_index++;
        } while (y_index <= y_max);
    }

    return 0;
}

void RGE_Master_Static_Object::make_available(unsigned char v) {
    this->available = v;
}

unsigned char RGE_Master_Static_Object::alignment(
    float& param_1, float& param_2, RGE_Game_World* param_3,
    unsigned char param_4) {
    float fVar1;
    float fVar2;
    float fVar3;
    float fVar4;
    float fVar5;
    float fVar6;
    short sVar7;

    fVar1 = param_1 - radius_x;
    fVar2 = param_2 - radius_y;
    fVar3 = param_1 + radius_x;
    fVar4 = param_2 + radius_y;
    fVar5 = (float)param_3->map->map_width - 0.00001f;
    fVar6 = (float)param_3->map->map_height - 0.00001f;

    if (fVar1 < 0.0f) {
        fVar3 = fVar3 + (-fVar1);
        param_1 = param_1 + (-fVar1);
        fVar1 = 0.0f;
    }
    if (fVar2 < 0.0f) {
        fVar4 = fVar4 + (-fVar2);
        param_2 = param_2 + (-fVar2);
        fVar2 = 0.0f;
    }
    if (!(fVar3 < fVar5))
        param_1 = param_1 + (fVar5 - fVar3);
    if (!(fVar4 < fVar6))
        param_2 = param_2 + (fVar6 - fVar4);

    if (param_4 == 0)
        return 1;

    if (fVar1 < 0.0f) fVar1 = -fVar1;
    if (fVar2 < 0.0f) fVar2 = -fVar2;
    if (fVar3 < 0.0f) fVar3 = -fVar3;
    if (fVar4 < 0.0f) fVar4 = -fVar4;

    sVar7 = (short)(long)fVar1;
    fVar1 = fVar1 - (float)(int)sVar7;
    sVar7 = (short)(long)fVar2;
    fVar2 = fVar2 - (float)(int)sVar7;
    sVar7 = (short)(long)fVar3;
    fVar3 = 1.0f - (fVar3 - (float)(int)sVar7);
    sVar7 = (short)(long)fVar4;
    fVar4 = 1.0f - (fVar4 - (float)(int)sVar7);

    if (fVar3 + fVar1 < 1.0f) {
        fVar1 = param_1;
    } else if (fVar1 <= fVar3) {
        fVar1 = param_1 - (1.0f - fVar3);
    } else {
        fVar1 = (1.0f - fVar1) + param_1;
    }

    if (1.0f <= fVar4 + fVar2) {
        if (fVar4 < fVar2) {
            fVar3 = param_2;
            param_1 = fVar1;
            param_2 = (1.0f - fVar2) + fVar3;
            return 1;
        }
        fVar2 = param_2;
        param_1 = fVar1;
        param_2 = fVar2 - (1.0f - fVar4);
        return 1;
    }
    fVar2 = param_2;
    param_1 = fVar1;
    param_2 = fVar2;
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
