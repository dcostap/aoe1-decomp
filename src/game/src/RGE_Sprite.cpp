#include "../include/RGE_Sprite.h"
#include "../include/RGE_Sound.h"
#include "../include/RGE_Color_Table.h"
#include "../include/RGE_Active_Sprite.h"
#include "../include/RGE_Active_Animated_Sprite.h"
#include "../include/TShape.h"
#include "../include/globals.h"
#include "../include/debug_helpers.h"
#include "../include/mystring.h"
#include <malloc.h>
#include <new>
#include <string.h>
#include <stdio.h>

RGE_Sprite::RGE_Sprite(short sprite_id) {
    // Source of truth: sprite.cpp.asm line 6
    memset(this, 0, sizeof(RGE_Sprite));
    this->id = sprite_id;
    this->color_tables = nullptr;
    this->shape = nullptr;
    this->main_sound = nullptr;
    this->draw_list = nullptr;
    this->sound_list = nullptr;
}

RGE_Sprite::RGE_Sprite(FILE* infile, short sprite_id, RGE_Sound** sounds) {
    // Fully verified. Source of truth: sprite.cpp.decomp @ 0x004BFA20
    memset(this, 0, sizeof(RGE_Sprite));
    this->color_tables = nullptr;
    this->last_time = 0;
    this->delta_time = 0;
    this->id = sprite_id;

    short temp_draw_level = 0;
    short temp_color_flag = 0;
    short temp_transparent_picking_flag = 0;
    short temp_animated = 0;
    short temp_directional = 0;
    short temp_randomize_on_start = 0;
    short temp_loop_once = 0;
    short sound_id = 0;
    short sound_frame = 0;
    short temp_micro_man_sound = 0;

    int iVar4 = fscanf(infile,
        " %20s %12s %d %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %f %f %f %hd %hd %hd",
        this->name,
        this->pict_name,
        &this->resource_id,
        &this->frame_num,
        &this->facet_num,
        &temp_draw_level,
        &temp_transparent_picking_flag,
        &temp_animated,
        &this->color_table,
        &sound_id,
        &temp_directional,
        &temp_randomize_on_start,
        &temp_loop_once,
        &sound_frame,
        &this->box_x1,
        &this->box_y1,
        &this->box_x2,
        &this->box_y2,
        &this->base_speed,
        &this->duration,
        &this->pause_between_loops,
        &this->draw_list_num,
        &temp_color_flag,
        &temp_micro_man_sound);

    if (iVar4 == -1) {
        return;
    }

    this->loaded = 0;
    this->shape = nullptr;
    convert_us(this->name);

    if (temp_color_flag < 0 || sounds == nullptr) {
        this->main_sound = nullptr;
    } else {
        this->main_sound = sounds[temp_color_flag];
    }

    if (temp_draw_level < 1) {
        this->mirror_flag = 0;
    } else {
        this->mirror_flag = (char)((this->facet_num >> 1) + (this->facet_num >> 2));
    }

    this->color_flag = (char)temp_transparent_picking_flag;
    this->draw_level = (char)temp_animated;
    this->transparent_picking_flag = (char)temp_directional;

    this->micro_man_sound = (char)(0 < temp_micro_man_sound);
    this->flag = (char)(0 < temp_randomize_on_start);
    if (temp_loop_once != 0) {
        this->flag = (char)((0 < temp_randomize_on_start) + 2);
    }
    if (sound_id != 0) {
        this->flag = (char)(this->flag + 4);
    }
    if (sound_frame != 0) {
        this->flag = (char)(this->flag + 8);
    }

    if (this->draw_list_num < 1) {
        this->draw_list = nullptr;
    } else {
        this->draw_list = (RGE_Picture_List*)calloc((int)this->draw_list_num, sizeof(RGE_Picture_List));
        if (this->draw_list != nullptr) {
            for (short i = 0; i < this->draw_list_num; ++i) {
                RGE_Picture_List* entry = &this->draw_list[i];
                entry->sprite = nullptr;
                fscanf(infile, " %hd %hd %hd %hd", &entry->picture_num, &entry->offset_x, &entry->offset_y, &entry->facet);
            }
        }
    }

    if (this->micro_man_sound == 0) {
        this->sound_list = nullptr;
        return;
    }

    this->sound_list = (RGE_Sound_List*)calloc((int)this->facet_num, sizeof(RGE_Sound_List));
    if (this->sound_list != nullptr) {
        for (short facet = 0; facet < this->facet_num; ++facet) {
            for (int slot = 0; slot < 3; ++slot) {
                this->sound_list[facet].sound[slot] = nullptr;
                this->sound_list[facet].frame[slot] = (short)-1;
            }
        }

        int sound_slot = 0;
        short prev_facet = (short)-1;
        for (short i = 0; i < temp_micro_man_sound; ++i) {
            short facet = 0;
            short frame = 0;
            short sound_idx = 0;
            if (fscanf(infile, " %hd %hd %hd", &facet, &frame, &sound_idx) == -1) {
                continue;
            }

            if (facet == prev_facet) {
                sound_slot = sound_slot + 1;
            } else {
                sound_slot = 0;
                prev_facet = facet;
            }

            if ((facet >= 0) && (facet < this->facet_num) && (sound_slot < 3)) {
                this->sound_list[facet].frame[sound_slot] = frame;
                if (sound_idx < 0 || sounds == nullptr) {
                    this->sound_list[facet].sound[sound_slot] = nullptr;
                } else {
                    this->sound_list[facet].sound[sound_slot] = sounds[sound_idx];
                }
            }
        }
    }
}

RGE_Sprite::RGE_Sprite(int fd, RGE_Sound** sounds, RGE_Color_Table** colors) {
    // Source of truth: sprite.cpp.decomp line 50 / sprite.cpp.asm line 82
    memset(this, 0, sizeof(RGE_Sprite));
    this->color_tables = colors;

    // Binary read sequence
    rge_read(fd, this->name, 0x15);
    rge_read(fd, this->pict_name, 0x0D);
    rge_read(fd, &this->resource_id, 4);
    rge_read(fd, &this->loaded, 1);
    rge_read(fd, &this->color_flag, 1);
    rge_read(fd, &this->draw_level, 1);
    rge_read(fd, &this->color_table, 2);
    rge_read(fd, &this->transparent_picking_flag, 1);
    rge_read(fd, &this->box_x1, 2);
    rge_read(fd, &this->box_y1, 2);
    rge_read(fd, &this->box_x2, 2);
    rge_read(fd, &this->box_y2, 2);
    rge_read(fd, &this->draw_list_num, 2);
    
    short main_sound_id;
    rge_read(fd, &main_sound_id, 2);
    if (main_sound_id >= 0 && sounds) {
        this->main_sound = sounds[main_sound_id];
    } else {
        this->main_sound = nullptr;
    }

    rge_read(fd, &this->micro_man_sound, 1);
    rge_read(fd, &this->frame_num, 2);
    rge_read(fd, &this->facet_num, 2);
    rge_read(fd, &this->base_speed, 4);
    rge_read(fd, &this->duration, 4);
    rge_read(fd, &this->pause_between_loops, 4);
    rge_read(fd, &this->flag, 1);
    rge_read(fd, &this->id, 2);
    rge_read(fd, &this->mirror_flag, 1);

    // Read draw list
    if (this->draw_list_num > 0) {
        this->draw_list = (RGE_Picture_List*)calloc(this->draw_list_num, sizeof(RGE_Picture_List));
        // Note: rge_read into draw_list reads 16 bytes per entry, which matches RGE_Picture_List
        rge_read(fd, this->draw_list, this->draw_list_num * 16);
    }

    // Read sound list
    if (this->micro_man_sound != 0 && this->facet_num > 0) {
        this->sound_list = (RGE_Sound_List*)calloc(this->facet_num, sizeof(RGE_Sound_List));
        for (int i = 0; i < this->facet_num; i++) {
            for (int s = 0; s < 3; s++) {
                short sound_idx;
                rge_read(fd, &this->sound_list[i].frame[s], 2);
                rge_read(fd, &sound_idx, 2);
                if (sound_idx >= 0 && sounds) {
                    this->sound_list[i].sound[s] = sounds[sound_idx];
                } else {
                    this->sound_list[i].sound[s] = nullptr;
                }
            }
        }
    }
}

RGE_Sprite::~RGE_Sprite() {
    // Source of truth: sprite.cpp.decomp line 304
    if (this->shape && this->loaded != 0) {
        delete this->shape;
        this->shape = nullptr;
        this->loaded = 0;
    }
    if (this->sound_list) {
        free(this->sound_list);
        this->sound_list = nullptr;
    }
    if (this->draw_list) {
        free(this->draw_list);
        this->draw_list = nullptr;
    }
}

void RGE_Sprite::rehook(RGE_Sprite** sprites) {
    // Source of truth: sprite.cpp.decomp line 339
    if (this->draw_list_num > 0 && this->draw_list) {
        for (short i = 0; i < this->draw_list_num; i++) {
            if (this->draw_list[i].picture_num == -1) {
                this->draw_list[i].sprite = this;
            } else if (sprites) {
                this->draw_list[i].sprite = sprites[this->draw_list[i].picture_num];
            }
        }
    }
    this->load_facets(sprites);
}

void RGE_Sprite::load_facets(RGE_Sprite** sprites) {
    // For now, shape loading is deferred to first draw as in decomp do_draw
    this->shape = nullptr;
    this->loaded = 1;
}

RGE_Active_Sprite* RGE_Sprite::make_active_sprite() {
    // Source of truth: sprite.cpp.decomp @ 0x004C0F90
    if ((this->flag & 1) == 0) {
        RGE_Active_Sprite* active = (RGE_Active_Sprite*)::operator new(sizeof(RGE_Active_Sprite), std::nothrow);
        if (active != nullptr) {
            return new(active) RGE_Active_Sprite(this);
        }
        return nullptr;
    }

    RGE_Active_Animated_Sprite* animated = (RGE_Active_Animated_Sprite*)::operator new(sizeof(RGE_Active_Animated_Sprite), std::nothrow);
    if (animated != nullptr) {
        return (RGE_Active_Sprite*)(new(animated) RGE_Active_Animated_Sprite(this));
    }
    return nullptr;
}

int RGE_Sprite::check_for_shadows() {
    // Source of truth: sprite.cpp.decomp @ 0x004C1030
    short draw_count = this->draw_list_num;
    if (draw_count < 1 || this->draw_list == nullptr) {
        if (this->draw_level != 0) {
            return 0;
        }
    } else {
        int index = 0;
        RGE_Sprite** sprite_ptr = &this->draw_list->sprite;
        while ((*sprite_ptr)->draw_level != 0) {
            index = index + 1;
            sprite_ptr = sprite_ptr + 4;
            if (draw_count <= index) {
                return 0;
            }
        }
    }
    return 1;
}

static void sprite_ensure_shape_loaded(RGE_Sprite* sprite) {
    if (sprite == nullptr) {
        return;
    }
    if (sprite->shape != nullptr) {
        return;
    }
    if (sprite->loaded == 0) {
        return;
    }

    char shape_name[64];
    shape_name[0] = '\0';
    snprintf(shape_name, sizeof(shape_name), "%s.shp", sprite->pict_name);
    sprite->shape = new TShape(shape_name, sprite->resource_id);
}

void RGE_Sprite::play_sound(short param_1, short param_2, short param_3) {
    // Source of truth: sprite.cpp.decomp @ 0x004BFFF0
    if (this->facet_num <= param_3) {
        param_3 = 0;
    }
    if (param_1 == param_2) {
        return;
    }

    if (this->main_sound != nullptr && (param_1 == 0 || (param_2 < param_1 && param_2 != 0))) {
        this->main_sound->play(1);
    }

    if (this->micro_man_sound == 0 || this->sound_list == nullptr) {
        return;
    }

    if (param_1 < param_2) {
        for (int i = 0; i < 3; ++i) {
            short sound_frame = this->sound_list[param_3].frame[i];
            if (sound_frame < 0) {
                break;
            }
            if (param_1 <= sound_frame && sound_frame < param_2 && this->sound_list[param_3].sound[i] != nullptr) {
                this->sound_list[param_3].sound[i]->play(1);
            }
        }
        return;
    }

    for (int i = 0; i < 3; ++i) {
        short sound_frame = this->sound_list[param_3].frame[i];
        if (sound_frame < 0) {
            return;
        }
        if ((param_1 <= sound_frame || sound_frame < param_2) && this->sound_list[param_3].sound[i] != nullptr) {
            this->sound_list[param_3].sound[i]->play(1);
        }
    }
}

unsigned char RGE_Sprite::get_facetindex(long param_1, long param_2, long* param_3) {
    // Source of truth: sprite.cpp.decomp @ 0x004C00E0
    unsigned char mirror = this->mirror_flag;
    if ((mirror != 0) && (this->facet_num == 2)) {
        *param_3 = param_2;
        return (unsigned char)param_1;
    }

    if ((mirror != 0) && (((int)mirror < param_1) || (param_1 < ((int)this->facet_num >> 2)))) {
        int index = (int)this->facet_num >> 1;
        if (index < param_1) {
            index = (index - (int)param_1) + (int)this->facet_num;
        } else {
            index = index - (int)param_1;
        }
        *param_3 = index;
        *param_3 = (*param_3 - ((int)this->facet_num >> 2)) * (int)this->frame_num + param_2;
        return 1;
    }

    if (mirror == 0) {
        *param_3 = this->frame_num * param_1 + param_2;
        return 0;
    }

    *param_3 = (param_1 - ((int)this->facet_num >> 2)) * (int)this->frame_num + param_2;
    return 0;
}

void RGE_Sprite::do_draw(long param_1, long param_2, long param_3, long param_4, RGE_Color_Table* param_5, TDrawArea* param_6, unsigned char param_7) {
    // Source of truth: sprite.cpp.decomp @ 0x004C01A0
    if (this->frame_num <= param_2) {
        param_2 = 0;
    }

    sprite_ensure_shape_loaded(this);
    if (this->shape == nullptr) {
        return;
    }

    this->delta_time = 0;

    long facet_index = 0;
    unsigned char mirrored = this->get_facetindex(param_1, param_2, &facet_index);
    (void)mirrored;

    unsigned char* table = nullptr;
    if (this->color_table < 0) {
        if (param_5 != nullptr) {
            table = param_5->table;
        }
    } else {
        short color_idx = this->color_table;
        if (this->color_tables != nullptr && this->color_tables[color_idx] != nullptr) {
            table = this->color_tables[color_idx]->table;
        }
    }

    this->shape->shape_draw(param_6, param_3, param_4, facet_index, this->color_flag, 0, table);
}

unsigned char RGE_Sprite::draw(long param_1, long param_2, long param_3, long param_4, long param_5, long param_6, RGE_Color_Table* param_7, TDrawArea* param_8, unsigned char param_9) {
    // Source of truth: sprite.cpp.decomp @ 0x004C04F0
    if (this->facet_num <= param_1) {
        param_1 = 0;
    }

    if ((this->draw_list_num < 1) || (this->draw_list == nullptr)) {
        if (this->draw_level < 0x0B) {
            param_3 = param_5;
            param_4 = param_6;
        }
        this->do_draw(param_1, param_2, param_3, param_4, param_7, param_8, param_9);
        return 1;
    }

    int count = 0;
    int offset = 0;
    while (count < this->draw_list_num) {
        RGE_Picture_List* list = this->draw_list;
        short facet = *(short*)((char*)&list->facet + offset);
        if (facet < 0 || facet == param_1) {
            RGE_Sprite* child = *(RGE_Sprite**)((char*)&list->sprite + offset);
            int y = (int)*(short*)((char*)&list->offset_y + offset);
            short x = *(short*)((char*)&list->offset_x + offset);
            long draw_x = 0;
            if (child->draw_level < 0x0B) {
                y += (int)param_6;
                draw_x = param_5 + x;
            } else {
                y += (int)param_4;
                draw_x = param_3 + x;
            }
            child->do_draw((child->facet_num * param_1) / (int)this->facet_num, param_2, draw_x, y, param_7, param_8, param_9);
        }
        count++;
        offset += 0x10;
    }

    return (unsigned char)count;
}

unsigned char RGE_Sprite::normal_draw(long param_1, long param_2, long param_3, long param_4, RGE_Color_Table* param_5, TDrawArea* param_6) {
    // Source of truth: sprite.cpp.decomp @ 0x004C0620
    long facet = param_1;
    if (this->facet_num <= param_1) {
        facet = 0;
    }

    if ((this->draw_list_num < 1) || (this->draw_list == nullptr)) {
        if (this->draw_level == 0x14) {
            this->do_draw(facet, param_2, param_3, param_4, param_5, param_6, 0);
        }
        return 1;
    }

    int count = 0;
    int offset = 0;
    while (count < this->draw_list_num) {
        RGE_Picture_List* list = this->draw_list;
        RGE_Sprite* child = *(RGE_Sprite**)((char*)&list->sprite + offset);
        short child_facet = *(short*)((char*)&list->facet + offset);
        if (child->draw_level == 0x14 && (child_facet < 0 || child_facet == facet)) {
            this->draw_list[count].sprite->do_draw(
                (child->facet_num * facet) / (int)this->facet_num,
                param_2,
                *(short*)((char*)&list->offset_x + offset) + param_3,
                *(short*)((char*)&list->offset_y + offset) + param_4,
                param_5,
                param_6,
                0);
        }
        count++;
        offset += 0x10;
    }

    return (unsigned char)count;
}

unsigned char RGE_Sprite::shadow_draw(long param_1, long param_2, long param_3, long param_4, RGE_Color_Table* param_5, TDrawArea* param_6, unsigned char param_7) {
    // Source of truth: sprite.cpp.decomp @ 0x004C0720
    long facet = param_1;
    if (this->facet_num <= param_1) {
        facet = 0;
    }

    if ((this->draw_list_num < 1) || (this->draw_list == nullptr)) {
        if (this->draw_level != param_7 && this->draw_level < 0x14) {
            this->do_draw(facet, param_2, param_3, param_4, param_5, param_6, 0);
        }
        return 1;
    }

    int count = 0;
    int offset = 0;
    while (count < this->draw_list_num) {
        RGE_Picture_List* list = this->draw_list;
        RGE_Sprite* child = *(RGE_Sprite**)((char*)&list->sprite + offset);
        short child_facet = *(short*)((char*)&list->facet + offset);
        if ((child->draw_level != param_7) && (child->draw_level < 0x14) && (child_facet < 0 || child_facet == facet)) {
            child->do_draw(
                (child->facet_num * facet) / (int)this->facet_num,
                param_2,
                *(short*)((char*)&list->offset_x + offset) + param_3,
                *(short*)((char*)&list->offset_y + offset) + param_4,
                param_5,
                param_6,
                0);
        }
        offset += 0x10;
        count++;
    }

    return (unsigned char)count;
}

int RGE_Sprite::get_size(long* param_1, long* param_2, long* param_3, long* param_4, long param_5) {
    // Source of truth: sprite.cpp.decomp @ 0x004C0840
    sprite_ensure_shape_loaded(this);
    if (this->shape == nullptr) {
        return 0;
    }
    return (int)this->shape->shape_minmax(param_1, param_2, param_3, param_4, (int)param_5);
}

int RGE_Sprite::get_frame_min_max(short* param_1, short* param_2, short* param_3, short* param_4, long param_5, long param_6, short param_7, short param_8) {
    // Source of truth: sprite.cpp.decomp @ 0x004C0B70
    long frame = param_6;
    if (this->frame_num <= param_6) {
        frame = 0;
    }

    long facet_index = 0;
    unsigned char mirrored = this->get_facetindex(param_5, frame, &facet_index);

    long min_x = 0;
    long min_y = 0;
    long max_x = 0;
    long max_y = 0;
    if (this->get_size(&min_x, &min_y, &max_x, &max_y, facet_index) == 0) {
        return 0;
    }

    if (mirrored != 0) {
        long t = -min_x;
        min_x = -max_x;
        max_x = t;
    }

    int calc_min_x = (int)min_x + (int)param_7;
    int calc_max_x = (int)max_x + (int)param_7;
    int calc_min_y = (int)min_y + (int)param_8;
    int calc_max_y = (int)max_y + (int)param_8;

    if (calc_min_x < *param_1) *param_1 = (short)calc_min_x;
    if (calc_min_y < *param_2) *param_2 = (short)calc_min_y;
    if (*param_3 < calc_max_x) *param_3 = (short)calc_max_x;
    if (*param_4 < calc_max_y) *param_4 = (short)calc_max_y;

    return 1;
}

int RGE_Sprite::get_frame(short* param_1, short* param_2, short* param_3, short* param_4, long param_5, long param_6) {
    // Source of truth: sprite.cpp.decomp @ 0x004C0960
    sprite_ensure_shape_loaded(this);
    if (this->shape == nullptr) {
        return 0;
    }

    if (((this->box_x1 == 0) && (this->box_x2 == 0)) || ((this->box_y1 == 0) && (this->box_y2 == 0))) {
        *param_1 = 0;
        *param_2 = 0;
        *param_3 = 0;
        *param_4 = 0;

        if ((this->draw_list_num < 1) || (this->draw_list == nullptr)) {
            this->get_frame_min_max(param_1, param_2, param_3, param_4, param_5, param_6, 0, 0);
        } else {
            int offset = 0;
            for (int index = 0; index < this->draw_list_num; ++index) {
                if (this->transparent_picking_flag != 0) {
                    RGE_Picture_List* list = this->draw_list;
                    RGE_Sprite* child = *(RGE_Sprite**)((char*)&list->sprite + offset);
                    child->get_frame_min_max(
                        param_1,
                        param_2,
                        param_3,
                        param_4,
                        (child->facet_num * param_5) / (int)this->facet_num,
                        param_6,
                        *(short*)((char*)&list->offset_x + offset),
                        *(short*)((char*)&list->offset_y + offset));
                }
                offset += 0x10;
            }
        }

        if (((*param_1 == 0) && (*param_3 == 0)) || ((*param_2 == 0) && (*param_4 == 0))) {
            return 0;
        }
    } else {
        *param_1 = this->box_x1;
        *param_2 = this->box_y1;
        *param_3 = this->box_x2;
        *param_4 = this->box_y2;
    }

    return 1;
}

unsigned char RGE_Sprite::get_lowest_draw_level() {
    // Source of truth: sprite.cpp.decomp @ 0x004C0C50
    short draw_count = this->draw_list_num;
    if (draw_count == 0) {
        return this->draw_level;
    }

    unsigned char lowest = 0x14;
    if (draw_count > 0 && this->draw_list != nullptr) {
        RGE_Sprite** sprite_ptr = &this->draw_list->sprite;
        int count = (int)draw_count;
        do {
            if ((*sprite_ptr)->draw_level < lowest) {
                lowest = (*sprite_ptr)->draw_level;
            }
            sprite_ptr = sprite_ptr + 4;
            count = count - 1;
        } while (count != 0);
    }
    return lowest;
}
