#include "../include/RGE_Master_Static_Object.h"

#include "../include/RGE_Damage_Sprite_Info.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Map.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Sound.h"
#include "../include/RGE_Sprite.h"
#include "../include/RGE_Static_Object.h"
#include "../include/RGE_Tile.h"
#include "../include/RGE_Object_Node.h"
#include "../include/RGE_Visible_Map.h"
#include "../include/RGE_Base_Game.h"
#include "../include/globals.h"
#include "../include/mystring.h"

#include <stdlib.h>
#include <string.h>
#include <math.h>

static long rge_ftol(float v) {
    // MSVC x86 __ftol equivalent (x87 FISTP using current rounding mode).
    long result;
    __asm {
        fld v
        fistp result
    }
    return result;
}

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

static RGE_Object_Node* rge_master_add_tile_node(RGE_Object_List* list, RGE_Static_Object* obj) {
    if (list == nullptr) {
        return nullptr;
    }

    RGE_Object_Node* node = (RGE_Object_Node*)calloc(1, sizeof(RGE_Object_Node));
    if (node == nullptr) {
        return nullptr;
    }

    node->node = obj;
    node->next = list->list;
    node->prev = nullptr;
    node->centered = 0;
    if (list->list != nullptr) {
        list->list->prev = node;
    }
    list->list = node;
    list->number_of_objects = (short)(list->number_of_objects + 1);
    return node;
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

void RGE_Master_Static_Object::copy_obj(RGE_Master_Static_Object* param_1) {
    // Fully verified. Source of truth: m_s_obj.cpp.decomp @ 0x00453120
    short old_id = this->id;
    short old_copy_id = this->copy_id;
    uchar old_available = this->available;
    uchar old_hide_in_scenario_editor = this->hide_in_scenario_editor;

    if (this->name != nullptr) {
        free(this->name);
    }

    this->master_type = param_1->master_type;
    this->name = param_1->name;
    this->string_id = param_1->string_id;
    this->string_id2 = param_1->string_id2;
    this->id = param_1->id;
    this->copy_id = param_1->copy_id;
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

    for (int i = 0; i < 3; ++i) {
        this->attribute_type_held[i] = param_1->attribute_type_held[i];
        this->attribute_amount_held[i] = param_1->attribute_amount_held[i];
        this->attribute_flag[i] = param_1->attribute_flag[i];
    }

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
    this->damage_sprite_num = param_1->damage_sprite_num;
    this->damage_sprites = param_1->damage_sprites;
    this->help_string_id = param_1->help_string_id;
    this->help_page_id = param_1->help_page_id;
    this->hotkey_id = param_1->hotkey_id;
    this->recyclable = param_1->recyclable;
    this->track_as_resource = param_1->track_as_resource;
    this->create_doppleganger_on_death = param_1->create_doppleganger_on_death;
    this->resource_group = param_1->resource_group;
    this->draw_flag = param_1->draw_flag;
    this->draw_color = param_1->draw_color;
    this->outline_radius_x = param_1->outline_radius_x;
    this->outline_radius_y = param_1->outline_radius_y;
    this->outline_radius_z = param_1->outline_radius_z;

    if (param_1->hide_in_scenario_editor == '\x01') {
        this->copy_id = old_copy_id;
    }

    this->hide_in_scenario_editor = old_hide_in_scenario_editor;
    param_1->hide_in_scenario_editor = '\x01';

    if (this->damage_sprite_num == '\0') {
        this->damage_sprites = nullptr;
    } else {
        this->damage_sprites = (RGE_Damage_Sprite_Info*)calloc(this->damage_sprite_num, 8);
        for (int i = 0; i < (int)(uint)this->damage_sprite_num; ++i) {
            this->damage_sprites[i].sprite = param_1->damage_sprites[i].sprite;
            this->damage_sprites[i].damage_percent = param_1->damage_sprites[i].damage_percent;
            this->damage_sprites[i].flag = param_1->damage_sprites[i].flag;
        }
    }

    this->name = nullptr;
    getstring(&this->name, param_1->name);

    this->id = old_id;
    this->available = old_available;
}

void RGE_Master_Static_Object::modify(float param_1, uchar param_2) {
    // Fully verified. Source of truth: m_s_obj.cpp.decomp @ 0x004534A0
    switch (param_2) {
        case '\0': {
            this->hp = (short)rge_ftol(param_1);
            return;
        }
        case '\x01': {
            this->los = param_1;
            return;
        }
        case '\x02': {
            this->obj_max = (uchar)rge_ftol(param_1);
            return;
        }
        case '\x03': {
            this->radius_x = param_1;
            return;
        }
        case '\x04': {
            this->radius_y = param_1;
            return;
        }
        case '\x0e': {
            this->attribute_max_amount = (short)rge_ftol(param_1);
            return;
        }
        default:
            return;
    }
}

void RGE_Master_Static_Object::modify_delta(float param_1, uchar param_2) {
    // Fully verified. Source of truth: m_s_obj.cpp.decomp @ 0x00453540
    switch (param_2) {
        case '\0': {
            this->hp = (short)(this->hp + (short)rge_ftol(param_1));
            return;
        }
        case '\x01': {
            this->los = param_1 + this->los;
            return;
        }
        case '\x02': {
            char delta = (char)rge_ftol(param_1);
            this->obj_max = (uchar)(this->obj_max + delta);
            return;
        }
        case '\x03': {
            this->radius_x = param_1 + this->radius_x;
            return;
        }
        case '\x04': {
            this->radius_y = param_1 + this->radius_y;
            return;
        }
        case '\x0e': {
            this->attribute_max_amount = (short)(this->attribute_max_amount + (short)rge_ftol(param_1));
            return;
        }
        default:
            return;
    }
}

void RGE_Master_Static_Object::modify_percent(float param_1, uchar param_2) {
    // Fully verified. Source of truth: m_s_obj.cpp.asm @ 0x004535F0
    switch (param_2) {
        case '\0': {
            this->hp = (short)rge_ftol(param_1 * (float)(int)this->hp);
            return;
        }
        case '\x01': {
            this->los = param_1 * this->los;
            return;
        }
        case '\x02': {
            this->obj_max = (uchar)rge_ftol(param_1 * (float)(uint)this->obj_max);
            return;
        }
        case '\x03': {
            this->radius_x = param_1 * this->radius_x;
            return;
        }
        case '\x04': {
            this->radius_y = param_1 * this->radius_y;
            return;
        }
        case '\x0e': {
            this->attribute_max_amount = (short)rge_ftol(param_1 * (float)(int)this->attribute_max_amount);
            return;
        }
        default:
            return;
    }
}

void RGE_Master_Static_Object::save(int param_1) {
    // Fully verified. Source of truth: m_s_obj.cpp.decomp @ 0x004536D0
    short temp_sprite = -1;
    short temp_death_sprite = -1;
    short temp_undead_sprite = -1;
    short created_sound_num = -1;
    short selected_sound_num = -1;
    short death_sound_num = -1;
    short name_size = 0;

    if (this->created_sound != nullptr) {
        created_sound_num = this->created_sound->id;
    }
    if (this->selected_sound != nullptr) {
        selected_sound_num = this->selected_sound->id;
    }
    if (this->death_sound != nullptr) {
        death_sound_num = this->death_sound->id;
    }

    if (this->sprite != nullptr) {
        temp_sprite = this->sprite->id;
    }
    if (this->death_sprite != nullptr) {
        temp_death_sprite = this->death_sprite->id;
    }
    if (this->undead_sprite != nullptr) {
        temp_undead_sprite = this->undead_sprite->id;
    }

    // Name size logic matches the original SCASB-based strlen (includes trailing '\0' when non-empty).
    uint uVar6 = 0xffffffffu;
    char* pcVar9 = this->name;
    char cVar1;
    do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar9;
        pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    name_size = (short)(~uVar6 - 1);
    if (0 < name_size) {
        name_size = (short)(~uVar6);
    }

    rge_write(param_1, &this->master_type, 1);
    rge_write(param_1, &name_size, 2);
    rge_write(param_1, &this->id, 2);
    rge_write(param_1, &this->string_id, 2);
    rge_write(param_1, &this->string_id2, 2);
    rge_write(param_1, &this->object_group, 2);
    rge_write(param_1, &temp_sprite, 2);
    rge_write(param_1, &temp_death_sprite, 2);
    rge_write(param_1, &temp_undead_sprite, 2);
    rge_write(param_1, &this->undead_flag, 1);
    rge_write(param_1, &this->hp, 2);
    rge_write(param_1, &this->los, 4);
    rge_write(param_1, &this->obj_max, 1);
    rge_write(param_1, &this->radius_x, 4);
    rge_write(param_1, &this->radius_y, 4);
    rge_write(param_1, &this->radius_z, 4);
    rge_write(param_1, &created_sound_num, 2);
    rge_write(param_1, &this->death_spawn_obj_id, 2);
    rge_write(param_1, &this->sort_number, 1);
    rge_write(param_1, &this->can_be_built_on, 1);
    rge_write(param_1, &this->button_pict, 2);
    rge_write(param_1, &this->hide_in_scenario_editor, 1);
    rge_write(param_1, &this->portrait_pict, 2);
    rge_write(param_1, &this->available, 1);
    rge_write(param_1, &this->tile_req1, 2);
    rge_write(param_1, &this->tile_req2, 2);
    rge_write(param_1, &this->center_tile_req1, 2);
    rge_write(param_1, &this->center_tile_req2, 2);
    rge_write(param_1, &this->construction_radius_x, 4);
    rge_write(param_1, &this->construction_radius_y, 4);
    rge_write(param_1, &this->elevation_flag, 1);
    rge_write(param_1, &this->fog_flag, 1);
    rge_write(param_1, &this->terrain, 2);
    rge_write(param_1, &this->movement_type, 1);
    rge_write(param_1, &this->attribute_max_amount, 2);
    rge_write(param_1, &this->attribute_rot, 4);
    rge_write(param_1, &this->area_effect_object_level, 1);
    rge_write(param_1, &this->combat_level, 1);
    rge_write(param_1, &this->select_level, 1);
    rge_write(param_1, &this->map_draw_level, 1);
    rge_write(param_1, &this->unit_level, 1);
    rge_write(param_1, &this->multiple_attribute_mod, 4);
    rge_write(param_1, &this->map_color, 1);
    rge_write(param_1, &this->help_string_id, 4);
    rge_write(param_1, &this->help_page_id, 4);
    rge_write(param_1, &this->hotkey_id, 4);
    rge_write(param_1, &this->recyclable, 1);
    rge_write(param_1, &this->track_as_resource, 1);
    rge_write(param_1, &this->create_doppleganger_on_death, 1);
    rge_write(param_1, &this->resource_group, 1);
    rge_write(param_1, &this->draw_flag, 1);
    rge_write(param_1, &this->draw_color, 1);
    rge_write(param_1, &this->outline_radius_x, 4);
    rge_write(param_1, &this->outline_radius_y, 4);
    rge_write(param_1, &this->outline_radius_z, 4);

    for (int i = 0; i < 3; ++i) {
        rge_write(param_1, &this->attribute_type_held[i], 2);
        rge_write(param_1, &this->attribute_amount_held[i], 4);
        rge_write(param_1, &this->attribute_flag[i], 1);
    }

    rge_write(param_1, &this->damage_sprite_num, 1);
    if (this->damage_sprite_num != '\0') {
        for (short i = 0; i < (short)(ushort)this->damage_sprite_num; ++i) {
            rge_write(param_1, &(this->damage_sprites[i].sprite)->id, 2);
            rge_write(param_1, &this->damage_sprites[i].damage_percent, 2);
            rge_write(param_1, &this->damage_sprites[i].flag, 1);
        }
    }

    rge_write(param_1, &selected_sound_num, 2);
    rge_write(param_1, &death_sound_num, 2);
    rge_write(param_1, &this->attack_reaction, 1);
    rge_write(param_1, &this->convert_terrain_flag, 1);

    if (name_size != 0) {
        rge_write(param_1, this->name, (int)name_size);
    }

    rge_write(param_1, &this->copy_id, 2);
}

RGE_Static_Object* RGE_Master_Static_Object::make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4) {
    if (param_1 == nullptr) {
        return nullptr;
    }

    RGE_Static_Object* obj = new RGE_Static_Object();
    if (obj == nullptr) {
        return nullptr;
    }

    if (obj->setup(this, param_1, param_2, param_3, param_4) == 0) {
        delete obj;
        obj = nullptr;
        return nullptr;
    }

    if (obj->tile == nullptr && param_1->world != nullptr && param_1->world->map != nullptr) {
        int tile_x = (int)param_2;
        int tile_y = (int)param_3;
        RGE_Tile* tile = param_1->world->map->get_tile(tile_x, tile_y);
        if (tile != nullptr) {
            obj->tile = tile;
            rge_master_add_tile_node(&tile->objects, obj);
        }
    }

    return obj;
}

RGE_Master_Static_Object* RGE_Master_Static_Object::make_new_master() {
    return new RGE_Master_Static_Object(this, 1);
}

uchar RGE_Master_Static_Object::check_placement(RGE_Player* param_1, float param_2, float param_3, int* param_4, uchar param_5, uchar param_6, uchar param_7, uchar param_8, uchar param_9, uchar param_10) {
    (void)param_7;
    if (param_4 != nullptr) {
        *param_4 = -1;
    }
    if (param_1 == nullptr || param_1->world == nullptr || param_1->world->map == nullptr) {
        return '\x07';
    }

    RGE_Map* map = param_1->world->map;
    if (map->map_row_offset == nullptr || map->map_width <= 0 || map->map_height <= 0) {
        return '\x07';
    }

    float rx = (param_8 == '\0') ? this->radius_x : this->construction_radius_x;
    float ry = (param_8 == '\0') ? this->radius_y : this->construction_radius_y;

    if ((param_2 - rx < 0.0f) ||
        ((float)map->map_width <= (rx + param_2) - 0.001f) ||
        (param_3 - ry < 0.0f) ||
        ((float)map->map_height <= (ry + param_3) - 0.001f)) {
        return '\x07';
    }

    short x1 = (short)floor(param_2 - rx);
    short x2 = (short)floor((rx + param_2) - 0.001f);
    short y1 = (short)floor(param_3 - ry);
    short y2 = (short)floor((ry + param_3) - 0.001f);

    short req_x1 = x1;
    short req_x2 = x2;
    short req_y1 = y1;
    short req_y2 = y2;

    if (this->center_tile_req1 >= 0 || this->center_tile_req2 >= 0) {
        short cx = (short)floor(param_2);
        short cy = (short)floor(param_3);
        if (cx < 0 || cy < 0 || cx >= map->map_width || cy >= map->map_height) {
            return '\x01';
        }

        ushort center_terr = (ushort)(map->map_row_offset[(int)cy][(int)cx].terrain_type & 0x1f);
        if (center_terr != (ushort)this->center_tile_req1 && center_terr != (ushort)this->center_tile_req2) {
            return '\x01';
        }

        req_x1 = cx;
        req_x2 = cx;
        req_y1 = cy;
        req_y2 = cy;
    }

    if (this->tile_req1 >= 0 || this->tile_req2 >= 0) {
        int found_req1 = 0;
        int found_req2 = 0;

        short y = (short)(req_y1 - 1);
        if (y >= 0 && req_x1 <= req_x2) {
            for (short x = req_x1; x <= req_x2; ++x) {
                uchar t = (uchar)(map->map_row_offset[(int)y][(int)x].terrain_type & 0x1f);
                if (t == (uchar)this->tile_req1) found_req1 = 1;
                if (t == (uchar)this->tile_req2) found_req2 = 1;
            }
        }

        short x = (short)(req_x2 + 1);
        if (x < map->map_width && req_y1 <= req_y2) {
            for (short yy = req_y1; yy <= req_y2; ++yy) {
                uchar t = (uchar)(map->map_row_offset[(int)yy][(int)x].terrain_type & 0x1f);
                if (t == (uchar)this->tile_req1) found_req1 = 1;
                if (t == (uchar)this->tile_req2) found_req2 = 1;
            }
        }

        y = (short)(req_y2 + 1);
        if (y < map->map_height && req_x1 <= req_x2) {
            for (short xx = req_x2; xx >= req_x1; --xx) {
                uchar t = (uchar)(map->map_row_offset[(int)y][(int)xx].terrain_type & 0x1f);
                if (t == (uchar)this->tile_req1) found_req1 = 1;
                if (t == (uchar)this->tile_req2) found_req2 = 1;
            }
        }

        x = (short)(req_x1 - 1);
        if (x >= 0 && req_y1 <= req_y2) {
            for (short yy = req_y2; yy >= req_y1; --yy) {
                uchar t = (uchar)(map->map_row_offset[(int)yy][(int)x].terrain_type & 0x1f);
                if (t == (uchar)this->tile_req1) found_req1 = 1;
                if (t == (uchar)this->tile_req2) found_req2 = 1;
            }
        }

        if (!found_req1 && !found_req2) {
            return '\x01';
        }
    }

    float* terrain_table = nullptr;
    if (param_1->world->terrains != nullptr && this->terrain >= 0 && this->terrain < param_1->world->terrain_num) {
        terrain_table = param_1->world->terrains[this->terrain];
    }

    int any_visible = 0;
    for (short x = x1; x <= x2; ++x) {
        for (short y = y1; y <= y2; ++y) {
            int ix = (int)x;
            int iy = (int)y;
            uchar terr = (uchar)(map->map_row_offset[iy][ix].terrain_type & 0x1f);

            if (terrain_table == nullptr || terrain_table[terr] <= 0.0f) {
                return '\x02';
            }

            if (param_5 != '\0') {
                if ((rge_base_game != nullptr && rge_base_game->prog_mode == 7) ||
                    (param_1->visible != nullptr && param_1->visible->get_visible(ix, iy) != '\0')) {
                    any_visible = 1;
                }
            }

            if (param_6 != '\0') {
                uchar tile_type = map->map_row_offset[iy][ix].tile_type;
                if (this->elevation_flag == '\x01') {
                    if (!(tile_type == 0 || tile_type == 5 || tile_type == 6 || tile_type == 7 || tile_type == 8)) {
                        return '\x03';
                    }
                } else if (this->elevation_flag == '\x02') {
                    if (tile_type != 0) {
                        return '\x03';
                    }
                }
            }
        }
    }

    if (param_5 == '\x01' && !any_visible) {
        return '\x05';
    }

    if (rx <= 0.0f && ry <= 0.0f) {
        return '\0';
    }

    short edge_x1 = (short)floor(param_2 - rx);
    short edge_y1 = (short)floor(param_3 - ry);
    short edge_x2 = (short)floor(param_2 + rx);
    short edge_y2 = (short)floor(param_3 + ry);

    if (edge_x1 < 0) edge_x1 = 0;
    if (edge_y1 < 0) edge_y1 = 0;
    if (edge_x2 >= map->map_width) edge_x2 = (short)(map->map_width - 1);
    if (edge_y2 >= map->map_height) edge_y2 = (short)(map->map_height - 1);

    if (param_10 != '\0' && ((param_9 != '\0') || (0.0f < this->radius_z)) && edge_y1 <= edge_y2) {
        for (short y = edge_y1; y <= edge_y2; ++y) {
            for (short x = edge_x1; x <= edge_x2; ++x) {
                RGE_Object_Node* node = map->map_row_offset[(int)y][(int)x].objects.list;
                while (node != nullptr) {
                    RGE_Static_Object* obj = node->node;
                    if (obj != nullptr && obj->master_obj != nullptr && obj->object_state < 7) {
                        if ((param_9 == '\0' || obj->master_obj->can_be_built_on != '\x01') || this->can_be_built_on != '\0') {
                            RGE_Master_Static_Object* other_master = obj->master_obj;
                            if (other_master->radius_x > 0.0f && other_master->radius_y > 0.0f) {
                                int z_ok = 0;
                                if (other_master->radius_z > 0.0f && this->radius_z > 0.0f) {
                                    z_ok = 1;
                                } else if (other_master->radius_z <= 0.0f && this->radius_z <= 0.0f) {
                                    z_ok = 1;
                                }

                                if (z_ok) {
                                    float dx = (float)fabs(obj->world_x - param_2);
                                    float dy = (float)fabs(obj->world_y - param_3);
                                    if (dx < other_master->radius_x + rx && dy < other_master->radius_y + ry) {
                                        if (param_4 != nullptr) {
                                            *param_4 = obj->id;
                                        }
                                        return '\x06';
                                    }
                                }
                            }
                        }
                    }
                    node = node->next;
                }
            }
        }
    }

    return '\0';
}

uchar RGE_Master_Static_Object::alignment(float* param_1, float* param_2, RGE_Game_World* param_3, uchar param_4) {
    if (param_1 == nullptr || param_2 == nullptr || param_3 == nullptr || param_3->map == nullptr) {
        return '\x01';
    }

    float left = *param_1 - this->radius_x;
    float top = *param_2 - this->radius_y;
    float right = *param_1 + this->radius_x;
    float bottom = *param_2 + this->radius_y;

    float map_w = (float)param_3->map->map_width - 1e-05f;
    float map_h = (float)param_3->map->map_height - 1e-05f;

    if (left < 0.0f) {
        float delta = -left;
        right = right + delta;
        *param_1 = *param_1 + delta;
    }
    if (top < 0.0f) {
        float delta = -top;
        bottom = bottom + delta;
        *param_2 = *param_2 + delta;
    }
    if (map_w <= right) {
        *param_1 = *param_1 + (map_w - right);
    }
    if (map_h <= bottom) {
        *param_2 = *param_2 + (map_h - bottom);
    }

    if (param_4 == '\0') {
        return '\x01';
    }

    float a = (float)fabs(*param_1 - this->radius_x);
    float b = (float)fabs(*param_2 - this->radius_y);
    float c = (float)fabs(*param_1 + this->radius_x);
    float d = (float)fabs(*param_2 + this->radius_y);

    float fa = a - (float)floor(a);
    float fb = b - (float)floor(b);
    float fc = 1.0f - (c - (float)floor(c));
    float fd = 1.0f - (d - (float)floor(d));

    float aligned_x = *param_1;
    if (fc + fa < 1.0f) {
        aligned_x = *param_1;
    } else if (fa <= fc) {
        aligned_x = *param_1 - (1.0f - fc);
    } else {
        aligned_x = *param_1 + (1.0f - fa);
    }

    if (1.0f <= fd + fb) {
        if (fd < fb) {
            float y0 = *param_2;
            *param_1 = aligned_x;
            *param_2 = y0 + (1.0f - fb);
            return '\x01';
        }
        float y0 = *param_2;
        *param_1 = aligned_x;
        *param_2 = y0 - (1.0f - fd);
        return '\x01';
    }

    *param_1 = aligned_x;
    return '\x01';
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

long RGE_Master_Static_Object::get_help_message() {
    // Source of truth: m_s_obj.cpp.decomp @ 0x00454950
    return this->help_string_id;
}

long RGE_Master_Static_Object::get_help_page() {
    // Source of truth: m_s_obj.cpp.decomp @ 0x00454960
    return this->help_page_id;
}

void RGE_Master_Static_Object::make_available(uchar param_1) {
    // Fully verified. Source of truth: m_s_obj.cpp.decomp @ 0x004543C0
    this->available = param_1;
}

uchar RGE_Master_Static_Object::alignment_box(RGE_Game_World* world, float col, float row,
                                               short* x4, short* local_12, short* scr_y,
                                               short* y3, short* y4, short* y1, short* x2,
                                               short* local_4)
{
    // Fully verified. Source of truth: m_s_obj.cpp.decomp @ 0x00454690 (ASM-audited with m_s_obj.cpp.asm)
    long tx = rge_ftol(col);
    float x = (col - (float)(int)tx) + this->construction_radius_x;

    long ty = rge_ftol(row);
    float y = (row - (float)(int)ty) + this->construction_radius_y;

    int tile_half_width = (int)world->map->tile_half_width;
    int tile_half_height = (int)world->map->tile_half_height;

    *x4 = (short)rge_ftol((x + y) * (float)tile_half_width);
    *local_12 = (short)rge_ftol((y - 1.0f - x) * (float)tile_half_height);

    x = x - this->construction_radius_x * 2.0f;
    *scr_y = (short)rge_ftol((x + y) * (float)tile_half_width);
    *y3 = (short)rge_ftol((y - 1.0f - x) * (float)tile_half_height);

    y = y - this->construction_radius_y * 2.0f;
    *y4 = (short)rge_ftol((x + y) * (float)tile_half_width);
    *y1 = (short)rge_ftol((y - 1.0f - x) * (float)tile_half_height);

    x = x + this->construction_radius_x * 2.0f;
    *x2 = (short)rge_ftol((x + y) * (float)tile_half_width);
    *local_4 = (short)rge_ftol((y - 1.0f - x) * (float)tile_half_height);

    return 1;
}
