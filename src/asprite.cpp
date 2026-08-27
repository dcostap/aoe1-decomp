#include "../include/game_globals.h"
#include "../include/asprite.h"

extern "C" void __cdecl rge_read(int handle, void* buffer, int size);
extern "C" void __cdecl rge_write(int handle, void* buffer, int size);
extern int __cdecl debug_rand(char* file, int line);
extern RGE_Sprite* fog_next_shape;

RGE_Active_Sprite::RGE_Active_Sprite(RGE_Sprite* sprite) {
    this->sprite = sprite;
    this->type = 1;
    this->offset_x = 0;
    this->offset_y = 0;
}

RGE_Active_Sprite::RGE_Active_Sprite(int param_1, RGE_Sprite** param_2) {
    short index;

    this->type = 1;
    rge_read(param_1, &index, 2);
    if (index >= 0) {
        this->sprite = param_2[index];
    } else {
        this->sprite = 0;
    }
    rge_read(param_1, &this->offset_x, 4);
    rge_read(param_1, &this->offset_y, 4);
}

RGE_Active_Sprite::~RGE_Active_Sprite() {}

void RGE_Active_Sprite::set_offset(long param_1, long param_2) {
    this->offset_x = param_1;
    this->offset_y = param_2;
}

void RGE_Active_Sprite::save(int param_1) {
    rge_write(param_1, &this->type, 1);
    rge_write(param_1, &this->sprite->id, 2);
    rge_write(param_1, &this->offset_x, 4);
    rge_write(param_1, &this->offset_y, 4);
}

void RGE_Active_Sprite::update(float param_1, float param_2) {
}

void RGE_Active_Sprite::draw(short param_1, long param_2, long param_3,
                             long param_4, long param_5,
                             RGE_Color_Table* param_6,
                             TDrawArea* param_7) {
    this->sprite->draw((long)param_1, 0, param_2 + this->offset_x,
                       param_3 + this->offset_y, param_4 + this->offset_x,
                       param_5 + this->offset_y, param_6, param_7, 0);
}

void RGE_Active_Sprite::normal_draw(short param_1, long param_2,
                                    long param_3, RGE_Color_Table* param_4,
                                    TDrawArea* param_5) {
    this->sprite->normal_draw((long)param_1, 0, this->offset_x + param_2,
                              this->offset_y + param_3, param_4, param_5);
}

void RGE_Active_Sprite::shadow_draw(short param_1, long param_2,
                                    long param_3, RGE_Color_Table* param_4,
                                    TDrawArea* param_5,
                                    unsigned char param_6) {
    this->sprite->shadow_draw((long)param_1, 0, this->offset_x + param_2,
                              this->offset_y + param_3, param_4, param_5,
                              param_6);
}

short RGE_Active_Sprite::what_frame() {
    return 0;
}

void RGE_Active_Sprite::set_frame(short param_1) {
}

unsigned char RGE_Active_Sprite::is_animating() {
    return 0;
}

unsigned char RGE_Active_Sprite::frame_passed(short param_1) {
    return 0;
}

unsigned char RGE_Active_Sprite::looped() {
    return 0;
}

short RGE_Active_Sprite::get_facetindex(short param_1) {
    long facet_index = 0;
    this->sprite->get_facetindex((int)param_1, 0, facet_index);
    return (short)facet_index;
}

unsigned char RGE_Active_Sprite::get_frame(short& param_1, short& param_2,
                                            short& param_3, short& param_4,
                                            long param_5) {
    int iVar1;

    iVar1 = this->sprite->get_frame(param_1, param_2, param_3, param_4,
                                    param_5, 0);
    return (unsigned char)iVar1;
}

unsigned char RGE_Active_Sprite::get_lowest_draw_level() {
    if (this->sprite != 0) {
        return this->sprite->get_lowest_draw_level();
    }
    return 0x14;
}

void RGE_Active_Sprite::setToFirstFrame(void) {
}

int RGE_Active_Sprite::check_for_shadows() {
    if (this->sprite != 0) {
        return this->sprite->check_for_shadows();
    }
    return 0;
}

RGE_Active_Animated_Sprite::RGE_Active_Animated_Sprite(RGE_Sprite* spr)
    : RGE_Active_Sprite(spr)
{
    int count;
    float tot_time;
    int rnd;
    float frame_time;

    type = 2;
    last_frame = 0;
    animate_interval = sprite->duration;

    if (animate_interval < DAT_0056ee78) {
        animate_interval = 0.001f;
    }

    if (sprite->flags & 4) {
        count = (int)sprite->frame_num;
        tot_time = (float)count * sprite->duration + sprite->pause_between_loops;
        rnd = debug_rand("C:\\msdev\\work\\age1_x1\\asprite.cpp", 0xB7);
        frame_time = (float)rnd * tot_time * DAT_0056ee80;
        frame = (short)(frame_time / sprite->duration);

        if (frame >= sprite->frame_num) {
            frame = sprite->frame_num - 1;
            animate_interval = frame_time - (float)(int)frame * sprite->duration;
        }

        last_frame = frame;
    } else {
        frame = 0;
    }

    animate_last = 0.0f;
    frame_changed = 0;
    frame_looped = 0;
    animate_flag = 1;
}

RGE_Active_Animated_Sprite::RGE_Active_Animated_Sprite(
    int param_1, RGE_Sprite** param_2)
    : RGE_Active_Sprite(param_1, param_2) {
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
}

void RGE_Active_Animated_Sprite::save(int param_1) {
    RGE_Active_Sprite::save(param_1);
    rge_write(param_1, &this->frame, 2);
    rge_write(param_1, &this->animate_interval, 4);
    rge_write(param_1, &this->animate_last, 4);
    rge_write(param_1, &this->last_frame, 2);
    rge_write(param_1, &this->frame_changed, 1);
    rge_write(param_1, &this->frame_looped, 1);
    rge_write(param_1, &this->animate_flag, 1);
}

void RGE_Active_Animated_Sprite::update(float param_1, float param_2)
{
    frame_changed = 0;
    frame_looped = 0;

    if (sprite != 0 && animate_flag != 0) {
        if (frame >= sprite->frame_num)
            frame = sprite->frame_num - 1;

        if ((sprite->flags & 1) != 0) {
            animate_last = param_1 + animate_last;

            if (animate_last >= animate_interval) {
                frame_changed = 1;
                last_frame = frame;

                short count = (short)(animate_last / animate_interval);
                animate_last = animate_last - (float)count * animate_interval;

                if (param_2 > 0.0 || sprite->base_speed == 0.0) {
                    frame += (unsigned char)count;
                    if (frame >= sprite->frame_num)
                        frame_looped = 1;
                }

                if (sprite->base_speed == 0.0 || param_2 == 0.0)
                    animate_interval = sprite->duration;
                else
                    animate_interval = sprite->duration * sprite->base_speed / param_2;

                if (animate_interval < DAT_0056ee78)
                    animate_interval = 0.001f;

                if (frame_looped != 0) {
                    if (sprite->pause_between_loops <= 0.0 || animate_flag == 2) {
                        animate_flag = 1;
                        while (frame >= sprite->frame_num)
                            frame -= sprite->frame_num;
                    } else {
                        animate_interval = sprite->pause_between_loops
                            - (float)(frame - sprite->frame_num) * sprite->duration;
                        frame = sprite->frame_num - 1;
                        animate_flag = 2;
                        frame_looped = 0;
                    }
                }
            }
        }
    }

    if (frame_looped != 0 && (sprite->flags & 8) != 0) {
        animate_flag = 0;
        frame = sprite->frame_num - 1;
    }
}

void RGE_Active_Animated_Sprite::draw(short param_1, long param_2,
                                      long param_3, long param_4,
                                      long param_5, RGE_Color_Table* param_6,
                                      TDrawArea* param_7) {
    this->sprite->draw((int)param_1, (int)this->frame, param_2, param_3,
                       param_4, param_5, param_6, param_7, '\0');
    if (this->frame_changed != 0) {
        if (fog_next_shape == 0) {
            this->sprite->play_sound(this->last_frame, this->frame, param_1);
        }
        this->frame_changed = 0;
    }
}

void RGE_Active_Animated_Sprite::normal_draw(short param_1, long param_2,
                                             long param_3,
                                             RGE_Color_Table* param_4,
                                             TDrawArea* param_5) {
    this->sprite->normal_draw((long)param_1, (long)this->frame, param_2,
                              param_3, param_4, param_5);
    if (this->frame_changed != 0) {
        this->sprite->play_sound(this->last_frame, this->frame, param_1);
        this->frame_changed = 0;
    }
}

void RGE_Active_Animated_Sprite::shadow_draw(short x, long a3, long a4,
                                             RGE_Color_Table* colors,
                                             TDrawArea* area,
                                             unsigned char mode) {
    this->sprite->shadow_draw((int)x, (int)this->frame, a3, a4, colors, area,
                              mode);
}

short RGE_Active_Animated_Sprite::what_frame() {
    return this->frame;
}

unsigned char RGE_Active_Animated_Sprite::is_animating() {
    int result;

    if (this->animate_flag == 0 || (this->sprite->flags & 1) == 0) {
        result = 0;
    } else {
        result = 1;
    }
    return result;
}

void RGE_Active_Animated_Sprite::set_frame(short value) {
    this->frame = value;
}

unsigned char RGE_Active_Animated_Sprite::frame_passed(short param_1) {
    int result;

    if (this->frame_changed == 0) goto ret0;
    if (this->frame_looped != 0) goto ret1;
    if (this->frame < param_1) goto ret0;
    if (this->last_frame < param_1) goto ret1;
ret0:
    result = 0;
    goto done;
ret1:
    result = 1;
done:
    return result;
}

unsigned char RGE_Active_Animated_Sprite::looped() {
    return this->frame_looped;
}

short RGE_Active_Animated_Sprite::get_facetindex(short facet) {
    long facet_index;

    facet_index = 0;
    this->sprite->get_facetindex((int)facet, (int)this->frame, facet_index);
    return (short)facet_index;
}

unsigned char RGE_Active_Animated_Sprite::get_frame(
    short& a, short& b, short& c, short& d, long e) {
    return (unsigned char)this->sprite->get_frame(a, b, c, d, e, this->frame);
}

void RGE_Active_Animated_Sprite::setToFirstFrame() {
    frame_changed = 1;
    last_frame = frame;
    frame = 0;
}
