#include "../include/RGE_Sprite.h"
#include "../include/RGE_Sound.h"
#include "../include/RGE_Color_Table.h"
#include "../include/RGE_Active_Sprite.h"
#include "../include/RGE_Active_Animated_Sprite.h"
#include "../include/TShape.h"
#include "../include/globals.h"
#include "../include/debug_helpers.h"
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
