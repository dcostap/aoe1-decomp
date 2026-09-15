#include "../include/game_globals.h"
#include "../include/asprite.h"
#include "../include/view.h"

extern void __cdecl rge_read(int handle, void* buffer, int size);
extern void __cdecl rge_write(int handle, void* buffer, int size);
extern int __cdecl debug_rand(char* file, int line);

RGE_Active_Sprite::RGE_Active_Sprite(RGE_Sprite* new_sprite) {
    this->sprite = new_sprite;
    this->type = 1;
    this->offset_x = 0;
    this->offset_y = 0;
}

RGE_Active_Sprite::RGE_Active_Sprite(int infile, RGE_Sprite** sprites) {
    short sprite_id;

    this->type = 1;
    rge_read(infile, &sprite_id, 2);
    if (sprite_id >= 0) {
        this->sprite = sprites[sprite_id];
    } else {
        this->sprite = 0;
    }
    rge_read(infile, &this->offset_x, 4);
    rge_read(infile, &this->offset_y, 4);
}

RGE_Active_Sprite::~RGE_Active_Sprite() {}

void RGE_Active_Sprite::set_offset(long x, long y) {
    this->offset_x = x;
    this->offset_y = y;
}

void RGE_Active_Sprite::save(int outfile) {
    rge_write(outfile, &this->type, 1);
    rge_write(outfile, &this->sprite->id, 2);
    rge_write(outfile, &this->offset_x, 4);
    rge_write(outfile, &this->offset_y, 4);
}

void RGE_Active_Sprite::update(float time, float speed) {
}

void RGE_Active_Sprite::draw(short facet, long x, long y, long sx, long sy,
                             RGE_Color_Table* player_color,
                             TDrawArea* draw_area) {
    this->sprite->draw((long)facet, 0, x + this->offset_x,
                       y + this->offset_y, sx + this->offset_x,
                       sy + this->offset_y, player_color, draw_area, 0);
}

void RGE_Active_Sprite::normal_draw(short facet, long x, long y,
                                    RGE_Color_Table* player_color,
                                    TDrawArea* draw_area) {
    this->sprite->normal_draw((long)facet, 0, this->offset_x + x,
                              this->offset_y + y, player_color, draw_area);
}

void RGE_Active_Sprite::shadow_draw(short facet, long x, long y,
                                    RGE_Color_Table* player_color,
                                    TDrawArea* draw_area, unsigned char flag) {
    this->sprite->shadow_draw((long)facet, 0, this->offset_x + x,
                              this->offset_y + y, player_color, draw_area,
                              flag);
}

short RGE_Active_Sprite::what_frame() {
    return 0;
}

void RGE_Active_Sprite::set_frame(short new_frame) {
}

unsigned char RGE_Active_Sprite::is_animating() {
    return 0;
}

unsigned char RGE_Active_Sprite::frame_passed(short passed_frame) {
    return 0;
}

unsigned char RGE_Active_Sprite::looped() {
    return 0;
}

short RGE_Active_Sprite::get_facetindex(short facet) {
    long facet_index = 0;
    this->sprite->get_facetindex((int)facet, 0, facet_index);
    return (short)facet_index;
}

unsigned char RGE_Active_Sprite::get_frame(short& min_x, short& min_y, short& max_x, short& max_y, long facet) {
    int result;

    result = this->sprite->get_frame(min_x, min_y, max_x, max_y, facet, 0);
    return (unsigned char)result;
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

RGE_Active_Animated_Sprite::RGE_Active_Animated_Sprite(RGE_Sprite* new_sprite)
    : RGE_Active_Sprite(new_sprite) {
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

RGE_Active_Animated_Sprite::RGE_Active_Animated_Sprite(int infile, RGE_Sprite** sprites)
    : RGE_Active_Sprite(infile, sprites) {
    this->type = 2;
    rge_read(infile, &this->frame, 2);
    rge_read(infile, &this->animate_interval, 4);
    rge_read(infile, &this->animate_last, 4);
    rge_read(infile, &this->last_frame, 2);
    rge_read(infile, &this->frame_changed, 1);
    rge_read(infile, &this->frame_looped, 1);
    rge_read(infile, &this->animate_flag, 1);
}

RGE_Active_Animated_Sprite::~RGE_Active_Animated_Sprite() {
}

void RGE_Active_Animated_Sprite::save(int outfile) {
    RGE_Active_Sprite::save(outfile);
    rge_write(outfile, &this->frame, 2);
    rge_write(outfile, &this->animate_interval, 4);
    rge_write(outfile, &this->animate_last, 4);
    rge_write(outfile, &this->last_frame, 2);
    rge_write(outfile, &this->frame_changed, 1);
    rge_write(outfile, &this->frame_looped, 1);
    rge_write(outfile, &this->animate_flag, 1);
}

void RGE_Active_Animated_Sprite::update(float time, float speed) {
    frame_changed = 0;
    frame_looped = 0;

    if (sprite != 0 && animate_flag != 0) {
        if (frame >= sprite->frame_num)
            frame = sprite->frame_num - 1;

        if ((sprite->flags & 1) != 0) {
            animate_last = time + animate_last;

            if (animate_last >= animate_interval) {
                frame_changed = 1;
                last_frame = frame;

                short count = (short)(animate_last / animate_interval);
                animate_last = animate_last - (float)count * animate_interval;

                if (speed > 0.0 || sprite->base_speed == 0.0) {
                    frame += (unsigned char)count;
                    if (frame >= sprite->frame_num)
                        frame_looped = 1;
                }

                if (sprite->base_speed == 0.0 || speed == 0.0)
                    animate_interval = sprite->duration;
                else
                    animate_interval = sprite->duration * sprite->base_speed / speed;

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

void RGE_Active_Animated_Sprite::draw(short facet, long x, long y, long sx,
                                      long sy, RGE_Color_Table* player_color,
                                      TDrawArea* draw_area) {
    this->sprite->draw((int)facet, (int)this->frame, x, y, sx, sy,
                       player_color, draw_area, '\0');
    if (this->frame_changed != 0) {
        if (fog_next_shape == 0) {
            this->sprite->play_sound(this->last_frame, this->frame, facet);
        }
        this->frame_changed = 0;
    }
}

void RGE_Active_Animated_Sprite::normal_draw(short facet, long x, long y,
                                             RGE_Color_Table* player_color,
                                             TDrawArea* draw_area) {
    this->sprite->normal_draw((long)facet, (long)this->frame, x, y,
                              player_color, draw_area);
    if (this->frame_changed != 0) {
        this->sprite->play_sound(this->last_frame, this->frame, facet);
        this->frame_changed = 0;
    }
}

void RGE_Active_Animated_Sprite::shadow_draw(short facet, long x, long y,
                                             RGE_Color_Table* player_color,
                                             TDrawArea* draw_area,
                                             unsigned char flag) {
    this->sprite->shadow_draw((int)facet, (int)this->frame, x, y,
                              player_color, draw_area, flag);
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

void RGE_Active_Animated_Sprite::set_frame(short new_frame) {
    this->frame = new_frame;
}

unsigned char RGE_Active_Animated_Sprite::frame_passed(short passed_frame) {
    int result;

    if (this->frame_changed == 0) goto ret0;
    if (this->frame_looped != 0) goto ret1;
    if (this->frame < passed_frame) goto ret0;
    if (this->last_frame < passed_frame) goto ret1;
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

unsigned char RGE_Active_Animated_Sprite::get_frame(short& min_x, short& min_y, short& max_x, short& max_y, long facet) {
    return (unsigned char)this->sprite->get_frame(min_x, min_y, max_x, max_y,
                                                   facet, this->frame);
}

void RGE_Active_Animated_Sprite::setToFirstFrame() {
    frame_changed = 1;
    last_frame = frame;
    frame = 0;
}
