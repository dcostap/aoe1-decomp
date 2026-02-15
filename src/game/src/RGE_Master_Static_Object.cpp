#include "../include/RGE_Master_Static_Object.h"

#include "../include/RGE_Damage_Sprite_Info.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Sound.h"
#include "../include/RGE_Sprite.h"
#include "../include/RGE_Static_Object.h"
#include "../include/globals.h"

#include <stdlib.h>
#include <string.h>

static char* rge_strdup_local(const char* src) {
    if (src == nullptr) {
        return nullptr;
    }
    size_t len = strlen(src) + 1;
    char* out = (char*)calloc(len, 1);
    if (out != nullptr) {
        memcpy(out, src, len);
    }
    return out;
}

static void rge_master_static_reset_fields(RGE_Master_Static_Object* self) {
    self->master_type = 0x0A;
    self->name = nullptr;
    self->string_id = 0;
    self->string_id2 = 0;
    self->id = 0;
    self->copy_id = 0;
    self->object_group = 0;
    self->sprite = nullptr;
    self->death_sprite = nullptr;
    self->undead_sprite = nullptr;
    self->undead_flag = 0;
    self->hp = 0;
    self->los = 0.0f;
    self->obj_max = 0;
    self->radius_x = 0.0f;
    self->radius_y = 0.0f;
    self->radius_z = 0.0f;
    self->selected_sound = nullptr;
    self->created_sound = nullptr;
    self->death_sound = nullptr;
    self->death_spawn_obj_id = 0;
    self->sort_number = 0;
    self->can_be_built_on = 0;
    self->button_pict = 0;
    self->hide_in_scenario_editor = 0;
    self->portrait_pict = 0;
    self->available = 0;
    self->tile_req1 = 0;
    self->tile_req2 = 0;
    self->center_tile_req1 = 0;
    self->center_tile_req2 = 0;
    self->construction_radius_x = 0.0f;
    self->construction_radius_y = 0.0f;
    self->elevation_flag = 0;
    self->fog_flag = 0;
    self->terrain = 0;
    self->movement_type = 0;
    for (int i = 0; i < 3; ++i) {
        self->attribute_type_held[i] = 0;
        self->attribute_amount_held[i] = 0.0f;
        self->attribute_flag[i] = 0;
    }
    self->attribute_max_amount = 0;
    self->attribute_rot = 0.0f;
    self->multiple_attribute_mod = 0.0f;
    self->area_effect_object_level = 0;
    self->combat_level = 0;
    self->select_level = 0;
    self->map_draw_level = 0;
    self->unit_level = 0;
    self->map_color = 0;
    self->attack_reaction = 0;
    self->convert_terrain_flag = 0;
    self->damage_sprite_num = 0;
    self->damage_sprites = nullptr;
    self->help_string_id = 0;
    self->help_page_id = 0;
    self->hotkey_id = 0;
    self->recyclable = 0;
    self->track_as_resource = 0;
    self->create_doppleganger_on_death = 0;
    self->resource_group = 0;
    self->draw_flag = 0;
    self->draw_color = 0;
    self->outline_radius_x = 0.0f;
    self->outline_radius_y = 0.0f;
    self->outline_radius_z = 0.0f;
}

RGE_Master_Static_Object::RGE_Master_Static_Object() {
    rge_master_static_reset_fields(this);
}

RGE_Master_Static_Object::RGE_Master_Static_Object(RGE_Master_Static_Object* param_1, int param_2) {
    rge_master_static_reset_fields(this);
    if (param_2 != 0 && param_1 != nullptr) {
        this->setup(param_1);
    }
}

RGE_Master_Static_Object::RGE_Master_Static_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4) {
    rge_master_static_reset_fields(this);
    if (param_4 != 0) {
        this->setup(param_1, param_2, param_3);
    }
}

RGE_Master_Static_Object::RGE_Master_Static_Object(FILE* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5) {
    rge_master_static_reset_fields(this);
    if (param_5 != 0) {
        this->setup(param_1, param_2, param_3, param_4);
    }
}

RGE_Master_Static_Object::~RGE_Master_Static_Object() {
    if (this->name != nullptr) {
        free(this->name);
        this->name = nullptr;
    }
    if (this->damage_sprites != nullptr) {
        free(this->damage_sprites);
        this->damage_sprites = nullptr;
    }
}

void RGE_Master_Static_Object::copy_obj() {}
void RGE_Master_Static_Object::modify(float param_1, uchar param_2) {}
void RGE_Master_Static_Object::modify_delta(float param_1, uchar param_2) {}
void RGE_Master_Static_Object::modify_percent(float param_1, uchar param_2) {}
void RGE_Master_Static_Object::save(int param_1) {}

RGE_Static_Object* RGE_Master_Static_Object::make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4) {
    if (param_1 == nullptr) {
        return nullptr;
    }

    RGE_Static_Object* obj = new RGE_Static_Object();
    if (obj == nullptr) {
        return nullptr;
    }

    obj->master_obj = this;
    obj->owner = param_1;
    obj->world_x = param_2;
    obj->world_y = param_3;
    obj->world_z = param_4;
    obj->object_state = 2;
    obj->sleep_flag = 0;
    obj->dopple_flag = 0;
    obj->selected = 0;
    obj->tile = nullptr;
    obj->inside_obj = nullptr;
    obj->objects = nullptr;
    obj->player_object_node = nullptr;

    if (param_1->world != nullptr) {
        obj->id = param_1->world->next_object_id++;
    } else {
        obj->id = 0;
    }

    obj->player_object_node = param_1->addObject(obj, 0, 0);
    return obj;
}

RGE_Master_Static_Object* RGE_Master_Static_Object::make_new_master() {
    return new RGE_Master_Static_Object(this, 1);
}

uchar RGE_Master_Static_Object::check_placement(RGE_Player* param_1, float param_2, float param_3, int* param_4, uchar param_5, uchar param_6, uchar param_7, uchar param_8, uchar param_9, uchar param_10) {
    return 1;
}

uchar RGE_Master_Static_Object::alignment(float* param_1, float* param_2, RGE_Game_World* param_3, uchar param_4) {
    return 1;
}

long RGE_Master_Static_Object::calc_base_damage_ability(RGE_Master_Combat_Object* param_1) {
    return 0;
}

void RGE_Master_Static_Object::play_command_sound() {}
void RGE_Master_Static_Object::play_move_sound() {}
void RGE_Master_Static_Object::draw(TDrawArea* param_1, short param_2, short param_3, RGE_Color_Table* param_4, long param_5, long param_6, int param_7, uchar param_8) {}

int RGE_Master_Static_Object::setup(RGE_Master_Static_Object* param_1) {
    if (param_1 == nullptr) {
        return 0;
    }

    this->master_type = 0x0A;
    this->recyclable = param_1->recyclable;
    this->string_id = param_1->string_id;
    this->string_id2 = param_1->string_id2;
    this->id = param_1->id;
    this->copy_id = param_1->id;
    this->object_group = param_1->object_group;
    this->sprite = param_1->sprite;
    this->death_sprite = param_1->death_sprite;
    this->undead_sprite = param_1->undead_sprite;
    this->undead_flag = param_1->undead_flag;
    this->hp = param_1->hp;
    this->los = param_1->los;
    this->obj_max = param_1->obj_max;
    this->radius_x = param_1->radius_x;
    this->radius_y = param_1->radius_y;
    this->radius_z = param_1->radius_z;
    this->selected_sound = param_1->selected_sound;
    this->created_sound = param_1->created_sound;
    this->death_sound = param_1->death_sound;
    this->death_spawn_obj_id = param_1->death_spawn_obj_id;
    this->sort_number = param_1->sort_number;
    this->can_be_built_on = param_1->can_be_built_on;
    this->button_pict = param_1->button_pict;
    this->hide_in_scenario_editor = param_1->hide_in_scenario_editor;
    this->portrait_pict = param_1->portrait_pict;
    this->available = param_1->available;
    this->tile_req1 = param_1->tile_req1;
    this->tile_req2 = param_1->tile_req2;
    this->center_tile_req1 = param_1->center_tile_req1;
    this->center_tile_req2 = param_1->center_tile_req2;
    this->construction_radius_x = param_1->construction_radius_x;
    this->construction_radius_y = param_1->construction_radius_y;
    this->elevation_flag = param_1->elevation_flag;
    this->fog_flag = param_1->fog_flag;
    this->terrain = param_1->terrain;
    this->movement_type = param_1->movement_type;
    this->attribute_max_amount = param_1->attribute_max_amount;
    this->attribute_rot = param_1->attribute_rot;
    this->multiple_attribute_mod = param_1->multiple_attribute_mod;
    this->area_effect_object_level = param_1->area_effect_object_level;
    this->combat_level = param_1->combat_level;
    this->select_level = param_1->select_level;
    this->map_draw_level = param_1->map_draw_level;
    this->unit_level = param_1->unit_level;
    this->map_color = param_1->map_color;
    this->attack_reaction = param_1->attack_reaction;
    this->convert_terrain_flag = param_1->convert_terrain_flag;
    this->help_string_id = param_1->help_string_id;
    this->help_page_id = param_1->help_page_id;
    this->hotkey_id = param_1->hotkey_id;
    this->track_as_resource = param_1->track_as_resource;
    this->create_doppleganger_on_death = param_1->create_doppleganger_on_death;
    this->resource_group = param_1->resource_group;
    this->draw_flag = param_1->draw_flag;
    this->draw_color = param_1->draw_color;
    this->outline_radius_x = param_1->outline_radius_x;
    this->outline_radius_y = param_1->outline_radius_y;
    this->outline_radius_z = param_1->outline_radius_z;

    for (int i = 0; i < 3; ++i) {
        this->attribute_type_held[i] = param_1->attribute_type_held[i];
        this->attribute_amount_held[i] = param_1->attribute_amount_held[i];
        this->attribute_flag[i] = param_1->attribute_flag[i];
    }

    if (this->damage_sprites != nullptr) {
        free(this->damage_sprites);
        this->damage_sprites = nullptr;
    }
    this->damage_sprite_num = param_1->damage_sprite_num;
    if (this->damage_sprite_num > 0) {
        this->damage_sprites = (RGE_Damage_Sprite_Info*)calloc(this->damage_sprite_num, sizeof(RGE_Damage_Sprite_Info));
        for (int i = 0; i < this->damage_sprite_num; ++i) {
            this->damage_sprites[i] = param_1->damage_sprites[i];
        }
    }

    if (this->name != nullptr) {
        free(this->name);
    }
    this->name = rge_strdup_local(param_1->name);
    return 1;
}

int RGE_Master_Static_Object::setup(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3) {
    short name_len = 0;
    short sprite_idx = -1;
    short death_sprite_idx = -1;
    short undead_sprite_idx = -1;
    short selected_sound_idx = -1;
    short death_sound_idx = -1;
    short created_sound_idx = -1;

    this->master_type = 0x0A;

    rge_read(param_1, &name_len, 2);
    rge_read(param_1, &this->id, 2);
    rge_read(param_1, &this->string_id, 2);
    rge_read(param_1, &this->string_id2, 2);
    rge_read(param_1, &this->object_group, 2);
    rge_read(param_1, &sprite_idx, 2);
    rge_read(param_1, &death_sprite_idx, 2);
    rge_read(param_1, &undead_sprite_idx, 2);
    rge_read(param_1, &this->undead_flag, 1);
    rge_read(param_1, &this->hp, 2);
    rge_read(param_1, &this->los, 4);
    rge_read(param_1, &this->obj_max, 1);
    rge_read(param_1, &this->radius_x, 4);
    rge_read(param_1, &this->radius_y, 4);
    rge_read(param_1, &this->radius_z, 4);
    rge_read(param_1, &selected_sound_idx, 2);
    rge_read(param_1, &this->death_spawn_obj_id, 2);
    rge_read(param_1, &this->sort_number, 1);
    rge_read(param_1, &this->can_be_built_on, 1);
    rge_read(param_1, &this->button_pict, 2);
    rge_read(param_1, &this->hide_in_scenario_editor, 1);
    rge_read(param_1, &this->portrait_pict, 2);
    rge_read(param_1, &this->available, 1);
    rge_read(param_1, &this->tile_req1, 2);
    rge_read(param_1, &this->tile_req2, 2);
    rge_read(param_1, &this->center_tile_req1, 2);
    rge_read(param_1, &this->center_tile_req2, 2);
    rge_read(param_1, &this->construction_radius_x, 4);
    rge_read(param_1, &this->construction_radius_y, 4);
    rge_read(param_1, &this->elevation_flag, 1);
    rge_read(param_1, &this->fog_flag, 1);
    rge_read(param_1, &this->terrain, 2);
    rge_read(param_1, &this->movement_type, 1);
    rge_read(param_1, &this->attribute_max_amount, 2);
    rge_read(param_1, &this->attribute_rot, 4);
    rge_read(param_1, &this->area_effect_object_level, 1);
    rge_read(param_1, &this->combat_level, 1);
    rge_read(param_1, &this->select_level, 1);
    rge_read(param_1, &this->map_draw_level, 1);
    rge_read(param_1, &this->unit_level, 1);
    rge_read(param_1, &this->multiple_attribute_mod, 4);
    rge_read(param_1, &this->map_color, 1);
    rge_read(param_1, &this->help_string_id, 4);
    rge_read(param_1, &this->help_page_id, 4);
    rge_read(param_1, &this->hotkey_id, 4);
    rge_read(param_1, &this->recyclable, 1);
    rge_read(param_1, &this->track_as_resource, 1);
    rge_read(param_1, &this->create_doppleganger_on_death, 1);
    rge_read(param_1, &this->resource_group, 1);

    if (save_game_version < 7.04f) {
        this->draw_flag = 0;
        this->draw_color = 0;
        this->outline_radius_x = this->radius_x;
        this->outline_radius_y = this->radius_y;
        this->outline_radius_z = this->radius_z;
    } else {
        rge_read(param_1, &this->draw_flag, 1);
        rge_read(param_1, &this->draw_color, 1);
        rge_read(param_1, &this->outline_radius_x, 4);
        rge_read(param_1, &this->outline_radius_y, 4);
        rge_read(param_1, &this->outline_radius_z, 4);
    }

    for (int i = 0; i < 3; ++i) {
        rge_read(param_1, &this->attribute_type_held[i], 2);
        rge_read(param_1, &this->attribute_amount_held[i], 4);
        rge_read(param_1, &this->attribute_flag[i], 1);
    }

    rge_read(param_1, &this->damage_sprite_num, 1);
    if (this->damage_sprites != nullptr) {
        free(this->damage_sprites);
        this->damage_sprites = nullptr;
    }
    if (this->damage_sprite_num > 0) {
        this->damage_sprites = (RGE_Damage_Sprite_Info*)calloc(this->damage_sprite_num, sizeof(RGE_Damage_Sprite_Info));
        for (int i = 0; i < this->damage_sprite_num; ++i) {
            short damage_sprite_idx = -1;
            ushort damage_percent_tmp = 0;
            uchar damage_flag = 0;
            rge_read(param_1, &damage_sprite_idx, 2);
            rge_read(param_1, &damage_percent_tmp, 2);
            rge_read(param_1, &damage_flag, 1);

            this->damage_sprites[i].sprite = (damage_sprite_idx >= 0 && param_2 != nullptr) ? param_2[damage_sprite_idx] : nullptr;
            this->damage_sprites[i].damage_percent = (uchar)damage_percent_tmp;
            this->damage_sprites[i].flag = damage_flag;
        }
    }

    rge_read(param_1, &created_sound_idx, 2);
    rge_read(param_1, &death_sound_idx, 2);
    rge_read(param_1, &this->attack_reaction, 1);
    rge_read(param_1, &this->convert_terrain_flag, 1);

    if (this->name != nullptr) {
        free(this->name);
        this->name = nullptr;
    }
    if (name_len > 0) {
        this->name = (char*)calloc((size_t)name_len, 1);
        rge_read(param_1, this->name, name_len);
    }

    if (save_game_version >= 7.12f) {
        rge_read(param_1, &this->copy_id, 2);
    } else {
        this->copy_id = this->id;
    }

    this->selected_sound = (created_sound_idx >= 0 && param_3 != nullptr) ? param_3[created_sound_idx] : nullptr;
    this->death_sound = (death_sound_idx >= 0 && param_3 != nullptr) ? param_3[death_sound_idx] : nullptr;
    this->created_sound = (selected_sound_idx >= 0 && param_3 != nullptr) ? param_3[selected_sound_idx] : nullptr;

    this->sprite = (sprite_idx >= 0 && param_2 != nullptr) ? param_2[sprite_idx] : nullptr;
    this->death_sprite = (death_sprite_idx >= 0 && param_2 != nullptr) ? param_2[death_sprite_idx] : nullptr;
    this->undead_sprite = (undead_sprite_idx >= 0 && param_2 != nullptr) ? param_2[undead_sprite_idx] : nullptr;

    return 1;
}

int RGE_Master_Static_Object::setup(FILE* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4) {
    (void)param_2;
    (void)param_3;

    this->master_type = 0x0A;
    this->id = param_4;
    this->copy_id = this->id;

    char tmp_name[120];
    memset(tmp_name, 0, sizeof(tmp_name));

    short temp_group = 0;
    if (param_1 != nullptr) {
        if (fscanf(param_1, " %119s %hd", tmp_name, &temp_group) == 2) {
            this->object_group = temp_group;
            if (this->name != nullptr) {
                free(this->name);
            }
            this->name = rge_strdup_local(tmp_name);
        }
    }

    return 1;
}
