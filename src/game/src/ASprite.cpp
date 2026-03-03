#include "../include/ASprite.h"
#include "../include/RGE_Sprite.h"
#include "../include/debug_helpers.h"
#include "../include/globals.h"
RGE_Active_Sprite::RGE_Active_Sprite(RGE_Sprite* param_1) {
    // Fully verified. Source of truth: asprite.cpp.decomp @ 0x0041AD20
    this->sprite = param_1;
    this->type = 1;
    this->offset_x = 0;
    this->offset_y = 0;
}

RGE_Active_Sprite::RGE_Active_Sprite(int param_1, RGE_Sprite** param_2) {
    // Fully verified. Source of truth: asprite.cpp.decomp @ 0x0041AD60
    this->type = 1;

    short sprite_id = -1;
    rge_read(param_1, &sprite_id, 2);
    if (sprite_id < 0) {
        this->sprite = nullptr;
    } else {
        this->sprite = param_2[sprite_id];
    }

    rge_read(param_1, &this->offset_x, 4);
    rge_read(param_1, &this->offset_y, 4);
}

RGE_Active_Sprite::~RGE_Active_Sprite() {
    // TODO: EMPTY_STUB - function body not transliterated [decomp: bucket_055C.decomp @ 0x0055c980]
    // Fully verified. Source of truth: asprite.cpp.decomp @ 0x0041ADD0
}

void RGE_Active_Sprite::set_offset(long param_1, long param_2) {
    // Fully verified. Source of truth: asprite.cpp.decomp @ 0x0041ADE0
    this->offset_x = param_1;
    this->offset_y = param_2;
}

void RGE_Active_Sprite::save(int param_1) {
    // Fully verified. Source of truth: asprite.cpp.decomp @ 0x0041AE00
    rge_write(param_1, &this->type, 1);
    rge_write(param_1, &this->sprite->id, 2);
    rge_write(param_1, &this->offset_x, 4);
    rge_write(param_1, &this->offset_y, 4);
}

void RGE_Active_Sprite::update(float param_1, float param_2) {
    // Fully verified. Source of truth: asprite.cpp.decomp @ 0x0041AE50
    // TODO: EMPTY_STUB - function body not transliterated [decomp: asprite.cpp.decomp @ 0x0041AE50]
}

void RGE_Active_Sprite::draw(short param_1, long param_2, long param_3, long param_4, long param_5, RGE_Color_Table* param_6, TDrawArea* param_7) {
    // Fully verified. Source of truth: asprite.cpp.decomp @ 0x0041AE60
    this->sprite->draw((long)param_1, 0, param_2 + this->offset_x, param_3 + this->offset_y,
        param_4 + this->offset_x, param_5 + this->offset_y, param_6, param_7, 0);
}

void RGE_Active_Sprite::normal_draw(short param_1, long param_2, long param_3, RGE_Color_Table* param_4, TDrawArea* param_5) {
    // Fully verified. Source of truth: asprite.cpp.decomp @ 0x0041AEB0
    this->sprite->normal_draw((long)param_1, 0, this->offset_x + param_2, this->offset_y + param_3, param_4, param_5);
}

void RGE_Active_Sprite::shadow_draw(short param_1, long param_2, long param_3, RGE_Color_Table* param_4, TDrawArea* param_5, uchar param_6) {
    // Fully verified. Source of truth: asprite.cpp.decomp @ 0x0041AEF0
    this->sprite->shadow_draw((long)param_1, 0, this->offset_x + param_2, this->offset_y + param_3, param_4, param_5, param_6);
}

short RGE_Active_Sprite::what_frame() {
    // Fully verified. Source of truth: asprite.cpp.decomp @ 0x0041AF30
    return 0;
}

uchar RGE_Active_Sprite::is_animating() {
    // Fully verified. Source of truth: asprite.cpp.decomp @ 0x0041AF50
    return 0;
}

void RGE_Active_Sprite::set_frame(short param_1) {
    // Fully verified. Source of truth: asprite.cpp.decomp @ 0x0041AF40
    // TODO: EMPTY_STUB - function body not transliterated [decomp: asprite.cpp.decomp @ 0x0041AF40]
}

uchar RGE_Active_Sprite::frame_passed(short param_1) {
    // Fully verified. Source of truth: asprite.cpp.decomp @ 0x0041AF60
    return 0;
}

uchar RGE_Active_Sprite::looped() {
    // Fully verified. Source of truth: asprite.cpp.decomp @ 0x0041AF70
    return 0;
}

short RGE_Active_Sprite::get_facetindex(short param_1) {
    // Fully verified. Source of truth: asprite.cpp.decomp @ 0x0041AF80
    long facet_index = 0;
    this->sprite->get_facetindex((long)param_1, 0, &facet_index);
    return (short)facet_index;
}

uchar RGE_Active_Sprite::get_frame(short* param_1, short* param_2, short* param_3, short* param_4, long param_5) {
    // Fully verified. Source of truth: asprite.cpp.decomp @ 0x0041AFB0
    return (uchar)this->sprite->get_frame(param_1, param_2, param_3, param_4, param_5, 0);
}

void RGE_Active_Sprite::setToFirstFrame() {
    // Fully verified. Source of truth: asprite.cpp.decomp @ 0x0041AFF0
    // TODO: EMPTY_STUB - function body not transliterated [decomp: asprite.cpp.decomp @ 0x0041AFF0]
}

int RGE_Active_Sprite::check_for_shadows() {
    // Fully verified. Source of truth: asprite.cpp.decomp @ 0x0041B000
    if (this->sprite != nullptr) {
        return this->sprite->check_for_shadows();
    }
    return 0;
}

unsigned char RGE_Active_Sprite::get_lowest_draw_level() {
    // Fully verified. Source of truth: asprite.cpp.decomp @ 0x0041AFE0.
    if (this->sprite != nullptr) {
        return this->sprite->get_lowest_draw_level();
    }
    return 0x14;
}

RGE_Active_Animated_Sprite::RGE_Active_Animated_Sprite(RGE_Sprite* param_1)
    : RGE_Active_Sprite(param_1) {
    // Fully verified. Source of truth: asprite.cpp.decomp @ 0x0041B010
    this->type = 2;
    this->last_frame = 0;

    this->animate_interval = this->sprite->base_speed;
    if (this->animate_interval < 0.001f) {
        this->animate_interval = 0.001f;
    }

    if ((this->sprite->flag & 4) == 0) {
        this->frame = 0;
    } else {
        float total_time = (float)this->sprite->frame_num * this->sprite->base_speed + this->sprite->pause_between_loops;
        int random_value = debug_rand("C:\\msdev\\work\\age1_x1\\asprite.cpp", 0xB7);
        float random_time = (float)random_value * total_time * (1.0f / 32767.0f);

        short random_frame = (short)(int)(random_time / this->sprite->base_speed);
        this->frame = random_frame;

        if (this->sprite->frame_num <= random_frame) {
            short clamped = (short)(this->sprite->frame_num - 1);
            this->frame = clamped;
            this->animate_interval = random_time - (float)clamped * this->sprite->base_speed;
        }

        this->last_frame = this->frame;
    }

    this->animate_last = 0.0f;
    this->frame_changed = 0;
    this->frame_looped = 0;
    this->animate_flag = 1;
}

RGE_Active_Animated_Sprite::RGE_Active_Animated_Sprite(int param_1, RGE_Sprite** param_2)
    : RGE_Active_Sprite(param_1, param_2) {
    // Fully verified. Source of truth: asprite.cpp.decomp @ 0x0041B140
    this->type = 2;
    rge_read(param_1, &this->frame, 2);
    rge_read(param_1, &this->animate_interval, 4);
    rge_read(param_1, &this->animate_last, 4);
    rge_read(param_1, &this->last_frame, 2);
    rge_read(param_1, &this->frame_changed, 1);
    rge_read(param_1, &this->frame_looped, 1);
    rge_read(param_1, &this->animate_flag, 1);
}

RGE_Active_Animated_Sprite::~RGE_Active_Animated_Sprite() {
    // Fully verified. Source of truth: asprite.cpp.decomp @ 0x0041B200
}

void RGE_Active_Animated_Sprite::save(int param_1) {
    // Fully verified. Source of truth: asprite.cpp.decomp @ 0x0041B210
    RGE_Active_Sprite::save(param_1);
    rge_write(param_1, &this->frame, 2);
    rge_write(param_1, &this->animate_interval, 4);
    rge_write(param_1, &this->animate_last, 4);
    rge_write(param_1, &this->last_frame, 2);
    rge_write(param_1, &this->frame_changed, 1);
    rge_write(param_1, &this->frame_looped, 1);
    rge_write(param_1, &this->animate_flag, 1);
}

void RGE_Active_Animated_Sprite::update(float param_1, float param_2) {
    // Fully verified. Source of truth: asprite.cpp.decomp @ 0x0041B290
    RGE_Sprite* sprite = this->sprite;

    this->frame_changed = 0;
    this->frame_looped = 0;

    if (sprite != nullptr && this->animate_flag != 0) {
        if (sprite->frame_num <= this->frame) {
            this->frame = (short)(sprite->frame_num - 1);
        }

        if ((sprite->flag & 1) != 0) {
            float elapsed = param_1 + this->animate_last;
            this->animate_last = elapsed;

            if (this->animate_interval <= elapsed) {
                this->frame_changed = 1;
                this->last_frame = this->frame;

                ushort whole_steps = (ushort)(int)(elapsed / this->animate_interval);
                this->animate_last = this->animate_last - (float)(short)whole_steps * this->animate_interval;

                if (0.0f < param_2 || sprite->base_speed == 0.0f) {
                    this->frame = (short)(this->frame + (whole_steps & 0xFF));
                    if (sprite->frame_num <= this->frame) {
                        this->frame_looped = 1;
                    }
                }

                if (sprite->base_speed == 0.0f || param_2 == 0.0f) {
                    this->animate_interval = sprite->base_speed;
                } else {
                    this->animate_interval = (sprite->base_speed * sprite->base_speed) / param_2;
                }

                if (this->animate_interval < 0.001f) {
                    this->animate_interval = 0.001f;
                }

                if (this->frame_looped != 0) {
                    if (sprite->pause_between_loops <= 0.0f || this->animate_flag == 2) {
                        this->animate_flag = 1;
                        short frame_count = sprite->frame_num;
                        while (frame_count <= this->frame) {
                            this->frame = (short)(this->frame - frame_count);
                            frame_count = sprite->frame_num;
                        }
                    } else {
                        this->animate_interval =
                            sprite->pause_between_loops -
                            (float)((int)this->frame - (int)sprite->frame_num) * sprite->base_speed;
                        this->animate_flag = 2;
                        this->frame_looped = 0;
                        this->frame = (short)(sprite->frame_num - 1);
                    }
                }
            }
        }
    }

    if (this->frame_looped != 0 && sprite != nullptr && (sprite->flag & 8) != 0) {
        this->animate_flag = 0;
        this->frame = (short)(sprite->frame_num - 1);
    }
}

void RGE_Active_Animated_Sprite::draw(short param_1, long param_2, long param_3, long param_4, long param_5, RGE_Color_Table* param_6, TDrawArea* param_7) {
    // Fully verified. Source of truth: asprite.cpp.decomp @ 0x0041B430
    this->sprite->draw((long)param_1, (long)this->frame, param_2, param_3, param_4, param_5, param_6, param_7, 0);
    if (this->frame_changed != 0) {
        if (fog_next_shape == 0) {
            this->sprite->play_sound(this->last_frame, this->frame, param_1);
        }
        this->frame_changed = 0;
    }
}

void RGE_Active_Animated_Sprite::normal_draw(short param_1, long param_2, long param_3, RGE_Color_Table* param_4, TDrawArea* param_5) {
    // Fully verified. Source of truth: asprite.cpp.decomp @ 0x0041B4A0
    this->sprite->normal_draw((long)param_1, (long)this->frame, param_2, param_3, param_4, param_5);
    if (this->frame_changed != 0) {
        this->sprite->play_sound(this->last_frame, this->frame, param_1);
        this->frame_changed = 0;
    }
}

void RGE_Active_Animated_Sprite::shadow_draw(short param_1, long param_2, long param_3, RGE_Color_Table* param_4, TDrawArea* param_5, uchar param_6) {
    // Fully verified. Source of truth: asprite.cpp.decomp @ 0x0041B4F0
    this->sprite->shadow_draw((long)param_1, (long)this->frame, param_2, param_3, param_4, param_5, param_6);
}

short RGE_Active_Animated_Sprite::what_frame() {
    // Fully verified. Source of truth: asprite.cpp.decomp @ 0x0041B520
    return this->frame;
}

uchar RGE_Active_Animated_Sprite::is_animating() {
    // Fully verified. Source of truth: asprite.cpp.decomp @ 0x0041B530
    if (this->animate_flag == 0) {
        return 0;
    }
    if (this->sprite == nullptr || (this->sprite->flag & 1) == 0) {
        return 0;
    }
    return 1;
}

void RGE_Active_Animated_Sprite::set_frame(short param_1) {
    // Fully verified. Source of truth: asprite.cpp.decomp @ 0x0041B550
    this->frame = param_1;
}

uchar RGE_Active_Animated_Sprite::frame_passed(short param_1) {
    // Fully verified. Source of truth: asprite.cpp.decomp @ 0x0041B560
    if (this->frame_changed != 0 &&
        (this->frame_looped != 0 || (param_1 <= this->frame && this->last_frame < param_1))) {
        return 1;
    }
    return 0;
}

uchar RGE_Active_Animated_Sprite::looped() {
    // Fully verified. Source of truth: asprite.cpp.decomp @ 0x0041B590
    return this->frame_looped;
}

short RGE_Active_Animated_Sprite::get_facetindex(short param_1) {
    // Fully verified. Source of truth: asprite.cpp.decomp @ 0x0041B5A0
    long facet_index = 0;
    this->sprite->get_facetindex((long)param_1, (long)this->frame, &facet_index);
    return (short)facet_index;
}

uchar RGE_Active_Animated_Sprite::get_frame(short* param_1, short* param_2, short* param_3, short* param_4, long param_5) {
    // Fully verified. Source of truth: asprite.cpp.decomp @ 0x0041B5D0
    return (uchar)this->sprite->get_frame(param_1, param_2, param_3, param_4, param_5, (long)this->frame);
}

void RGE_Active_Animated_Sprite::setToFirstFrame() {
    // Fully verified. Source of truth: asprite.cpp.decomp @ 0x0041B600
    this->frame_changed = 1;
    this->last_frame = this->frame;
    this->frame = 0;
}
