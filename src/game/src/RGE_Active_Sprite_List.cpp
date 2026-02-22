#include "../include/RGE_Active_Sprite_List.h"
#include "../include/RGE_Active_Sprite_Node.h"
#include "../include/RGE_Active_Sprite.h"
#include "../include/RGE_Active_Animated_Sprite.h"
#include "../include/RGE_Sprite.h"
#include "../include/RGE_Static_Object.h"
#include "../include/debug_helpers.h"
#include "../include/globals.h"
#include <stdlib.h>
#include <new>

RGE_Active_Sprite_List::RGE_Active_Sprite_List(RGE_Static_Object* param_1) {
    // Fully verified. Source of truth: asp_list.cpp.decomp @ 0x0041A640
    this->list = nullptr;
    this->owner = param_1;
}

RGE_Active_Sprite::RGE_Active_Sprite(RGE_Sprite* param_1) {
    // Source of truth: asprite.cpp.decomp @ 0x0041AD20
    this->sprite = param_1;
    this->type = 1;
    this->offset_x = 0;
    this->offset_y = 0;
}

RGE_Active_Sprite::RGE_Active_Sprite(int param_1, RGE_Sprite** param_2) {
    // Source of truth: asprite.cpp.decomp @ 0x0041AD60
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
    // Source of truth: asprite.cpp.decomp @ 0x0041ADD0
}

void RGE_Active_Sprite::set_offset(long param_1, long param_2) {
    // Source of truth: asprite.cpp.decomp @ 0x0041ADE0
    this->offset_x = param_1;
    this->offset_y = param_2;
}

void RGE_Active_Sprite::save(int param_1) {
    // Source of truth: asprite.cpp.decomp @ 0x0041AE00
    rge_write(param_1, &this->type, 1);

    short sprite_id = -1;
    if (this->sprite != nullptr) {
        sprite_id = this->sprite->id;
    }
    rge_write(param_1, &sprite_id, 2);

    rge_write(param_1, &this->offset_x, 4);
    rge_write(param_1, &this->offset_y, 4);
}

void RGE_Active_Sprite::update(float param_1, float param_2) {
    // Source of truth: asprite.cpp.decomp @ 0x0041AE50
}

void RGE_Active_Sprite::draw(short param_1, long param_2, long param_3, long param_4, long param_5, RGE_Color_Table* param_6, TDrawArea* param_7) {
    // Source of truth: asprite.cpp.decomp @ 0x0041AE60
    this->sprite->draw((long)param_1, 0, param_2 + this->offset_x, param_3 + this->offset_y,
        param_4 + this->offset_x, param_5 + this->offset_y, param_6, param_7, 0);
}

void RGE_Active_Sprite::normal_draw(short param_1, long param_2, long param_3, RGE_Color_Table* param_4, TDrawArea* param_5) {
    // Source of truth: asprite.cpp.decomp @ 0x0041AEB0
    this->sprite->normal_draw((long)param_1, 0, this->offset_x + param_2, this->offset_y + param_3, param_4, param_5);
}

void RGE_Active_Sprite::shadow_draw(short param_1, long param_2, long param_3, RGE_Color_Table* param_4, TDrawArea* param_5, uchar param_6) {
    // Source of truth: asprite.cpp.decomp @ 0x0041AEF0
    this->sprite->shadow_draw((long)param_1, 0, this->offset_x + param_2, this->offset_y + param_3, param_4, param_5, param_6);
}

short RGE_Active_Sprite::what_frame() {
    // Source of truth: asprite.cpp.decomp @ 0x0041AF30
    return 0;
}

uchar RGE_Active_Sprite::is_animating() {
    // Source of truth: asprite.cpp.decomp @ 0x0041AF50
    return 0;
}

void RGE_Active_Sprite::set_frame(short param_1) {
    // Source of truth: asprite.cpp.decomp @ 0x0041AF40
}

uchar RGE_Active_Sprite::frame_passed(short param_1) {
    // Source of truth: asprite.cpp.decomp @ 0x0041AF60
    return 0;
}

uchar RGE_Active_Sprite::looped() {
    // Source of truth: asprite.cpp.decomp @ 0x0041AF70
    return 0;
}

short RGE_Active_Sprite::get_facetindex(short param_1) {
    // Source of truth: asprite.cpp.decomp @ 0x0041AF80
    long facet_index = 0;
    this->sprite->get_facetindex((long)param_1, 0, &facet_index);
    return (short)facet_index;
}

uchar RGE_Active_Sprite::get_frame(short* param_1, short* param_2, short* param_3, short* param_4, long param_5) {
    // Source of truth: asprite.cpp.decomp @ 0x0041AFB0
    return (uchar)this->sprite->get_frame(param_1, param_2, param_3, param_4, param_5, 0);
}

void RGE_Active_Sprite::setToFirstFrame() {
    // Source of truth: asprite.cpp.decomp @ 0x0041AFF0
}

int RGE_Active_Sprite::check_for_shadows() {
    // Source of truth: asprite.cpp.decomp @ 0x0041B000
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
    // Source of truth: asprite.cpp.decomp @ 0x0041B010
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
    // Source of truth: asprite.cpp.decomp @ 0x0041B140
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
    // Source of truth: asprite.cpp.decomp @ 0x0041B200
}

void RGE_Active_Animated_Sprite::set_offset(long param_1, long param_2) {
    // Source of truth: asprite.cpp.decomp @ 0x0041ADE0 (base virtual)
    this->offset_x = param_1;
    this->offset_y = param_2;
}

void RGE_Active_Animated_Sprite::save(int param_1) {
    // Source of truth: asprite.cpp.decomp @ 0x0041B210
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
    // Source of truth: asprite.cpp.decomp @ 0x0041B290
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
    // Source of truth: asprite.cpp.decomp @ 0x0041B430
    this->sprite->draw((long)param_1, (long)this->frame, param_2, param_3, param_4, param_5, param_6, param_7, 0);
    if (this->frame_changed != 0) {
        this->frame_changed = 0;
    }
}

void RGE_Active_Animated_Sprite::normal_draw(short param_1, long param_2, long param_3, RGE_Color_Table* param_4, TDrawArea* param_5) {
    // Source of truth: asprite.cpp.decomp @ 0x0041B4A0
    this->sprite->normal_draw((long)param_1, (long)this->frame, param_2, param_3, param_4, param_5);
    if (this->frame_changed != 0) {
        this->sprite->play_sound(this->last_frame, this->frame, param_1);
        this->frame_changed = 0;
    }
}

void RGE_Active_Animated_Sprite::shadow_draw(short param_1, long param_2, long param_3, RGE_Color_Table* param_4, TDrawArea* param_5, uchar param_6) {
    // Source of truth: asprite.cpp.decomp @ 0x0041B4F0
    this->sprite->shadow_draw((long)param_1, (long)this->frame, param_2, param_3, param_4, param_5, param_6);
}

short RGE_Active_Animated_Sprite::what_frame() {
    // Source of truth: asprite.cpp.decomp @ 0x0041B520
    return this->frame;
}

uchar RGE_Active_Animated_Sprite::is_animating() {
    // Source of truth: asprite.cpp.decomp @ 0x0041B530
    if (this->animate_flag == 0) {
        return 0;
    }
    if (this->sprite == nullptr || (this->sprite->flag & 1) == 0) {
        return 0;
    }
    return 1;
}

void RGE_Active_Animated_Sprite::set_frame(short param_1) {
    // Source of truth: asprite.cpp.decomp @ 0x0041B550
    this->frame = param_1;
}

uchar RGE_Active_Animated_Sprite::frame_passed(short param_1) {
    // Source of truth: asprite.cpp.decomp @ 0x0041B560
    if (this->frame_changed != 0 &&
        (this->frame_looped != 0 || (param_1 <= this->frame && this->last_frame < param_1))) {
        return 1;
    }
    return 0;
}

uchar RGE_Active_Animated_Sprite::looped() {
    // Source of truth: asprite.cpp.decomp @ 0x0041B590
    return this->frame_looped;
}

short RGE_Active_Animated_Sprite::get_facetindex(short param_1) {
    // Source of truth: asprite.cpp.decomp @ 0x0041B5A0
    long facet_index = 0;
    this->sprite->get_facetindex((long)param_1, (long)this->frame, &facet_index);
    return (short)facet_index;
}

uchar RGE_Active_Animated_Sprite::get_frame(short* param_1, short* param_2, short* param_3, short* param_4, long param_5) {
    // Source of truth: asprite.cpp.decomp @ 0x0041B5D0
    return (uchar)this->sprite->get_frame(param_1, param_2, param_3, param_4, param_5, (long)this->frame);
}

void RGE_Active_Animated_Sprite::setToFirstFrame() {
    // Source of truth: asprite.cpp.decomp @ 0x0041B600
    this->frame_changed = 1;
    this->last_frame = this->frame;
    this->frame = 0;
}

void RGE_Active_Sprite_List::save(int param_1) {
    // Fully verified. Source of truth: asp_list.cpp.decomp @ 0x0041A830
    RGE_Active_Sprite_Node* cur = this->list;
    while (cur != nullptr) {
        cur->node->save(param_1);
        cur = cur->next;
    }

    uchar zero = 0;
    rge_write(param_1, &zero, 1);
}

void RGE_Active_Sprite_List::delete_list() {
    // Source of truth: asp_list.cpp.decomp @ 0x0041A860
    RGE_Active_Sprite_Node* cur = this->list;
    while (cur != nullptr) {
        RGE_Active_Sprite_Node* next = cur->next;
        int has_shadows = cur->node->check_for_shadows();
        if (has_shadows != 0 && this->owner != nullptr) {
            this->owner->remove_shadows();
        }
        if (cur->node != nullptr) {
            delete cur->node;
        }
        free(cur);
        cur = next;
    }
    this->list = nullptr;
}

void RGE_Active_Sprite_List::add_sprite(RGE_Sprite* param_1, uchar param_2, long param_3, long param_4) {
    // Fully verified. Source of truth: asp_list.cpp.decomp @ 0x0041A910
    if (param_1 != nullptr) {
        int has_shadows = param_1->check_for_shadows();
        if (has_shadows != 0 && this->owner != nullptr) {
            this->owner->remove_shadows();
        }

        RGE_Active_Sprite_Node** insert_at = &this->list;
        RGE_Active_Sprite_Node* cur = this->list;

        for (RGE_Active_Sprite_Node* scan = cur; scan != nullptr; scan = scan->next) {
            if (scan->node->sprite == param_1) {
                scan->count = (uchar)(scan->count + 1);
                return;
            }
        }

        for (; cur != nullptr && cur->order <= param_2; cur = cur->next) {
            insert_at = &cur->next;
        }

        RGE_Active_Sprite_Node* node = (RGE_Active_Sprite_Node*)calloc(0xC, 1);
        RGE_Active_Sprite* active_sprite = param_1->make_active_sprite();
        node->node = active_sprite;
        active_sprite->set_offset(param_3, param_4);
        node->order = param_2;
        node->next = *insert_at;
        *insert_at = node;
    }
}

void RGE_Active_Sprite_List::remove_sprite(RGE_Sprite* param_1) {
    // Fully verified. Source of truth: asp_list.cpp.decomp @ 0x0041A9B0
    RGE_Active_Sprite_Node* cur = this->list;
    RGE_Active_Sprite_Node** prev_next = &this->list;

    if (cur != nullptr) {
        while (cur->node->sprite != param_1) {
            prev_next = &cur->next;
            cur = cur->next;
            if (cur == nullptr) {
                return;
            }
        }

        if (cur->count != 0) {
            cur->count = (uchar)(cur->count - 1);
            return;
        }

        *prev_next = cur->next;

        int has_shadows = cur->node->check_for_shadows();
        if (has_shadows != 0 && this->owner != nullptr) {
            this->owner->remove_shadows();
        }

        if (cur->node != nullptr) {
            delete cur->node;
        }

        free(cur);
    }
}

uchar RGE_Active_Sprite_List::get_lowest_draw_level() {
    // Fully verified. Source of truth: asp_list.cpp.decomp @ 0x0041ACC0.
    uchar bVar3 = 0x14;
    for (RGE_Active_Sprite_Node* pRVar1 = this->list; pRVar1 != nullptr; pRVar1 = pRVar1->next) {
        uchar bVar2 = pRVar1->node->get_lowest_draw_level();
        if (bVar2 < bVar3) {
            bVar3 = bVar2;
        }
    }
    return bVar3;
}

RGE_Active_Sprite_List::~RGE_Active_Sprite_List() {
    // Source of truth: asp_list.cpp.decomp @ 0x0041A680
    this->delete_list();
}

void RGE_Active_Sprite_List::load(int param_1, RGE_Sprite** param_2) {
    // Fully verified. Source of truth: asp_list.cpp.decomp @ 0x0041A690
    uchar node_type = 0;
    do {
        rge_read(param_1, &node_type, 1);
    } while (this->load_node(param_1, node_type, param_2) != 0);

    RGE_Active_Sprite_Node* iter = this->list;
    RGE_Active_Sprite_Node* reversed = nullptr;
    while (iter != nullptr) {
        RGE_Active_Sprite_Node* next = iter->next;
        iter->next = reversed;
        reversed = iter;
        iter = next;
    }
    this->list = reversed;
}

uchar RGE_Active_Sprite_List::load_node(int param_1, uchar param_2, RGE_Sprite** param_3) {
    // Source of truth: asp_list.cpp.decomp @ 0x0041A6F0
    if (param_2 == 0) {
        return 0;
    }

    if (param_2 == 1) {
        RGE_Active_Sprite_Node* node = (RGE_Active_Sprite_Node*)calloc(0xC, 1);
        RGE_Active_Sprite* active_sprite = (RGE_Active_Sprite*)::operator new(sizeof(RGE_Active_Sprite), std::nothrow);
        if (active_sprite != nullptr) {
            active_sprite = new(active_sprite) RGE_Active_Sprite(param_1, param_3);
            node->node = active_sprite;
            node->next = this->list;
            this->list = node;
            return 1;
        }

        node->node = nullptr;
        node->next = this->list;
        this->list = node;
        return 1;
    }

    if (param_2 == 2) {
        RGE_Active_Sprite_Node* node = (RGE_Active_Sprite_Node*)calloc(0xC, 1);
        RGE_Active_Animated_Sprite* active_sprite = (RGE_Active_Animated_Sprite*)::operator new(sizeof(RGE_Active_Animated_Sprite), std::nothrow);
        if (active_sprite != nullptr) {
            active_sprite = new(active_sprite) RGE_Active_Animated_Sprite(param_1, param_3);
            node->node = (RGE_Active_Sprite*)active_sprite;
            node->next = this->list;
            this->list = node;
            return 1;
        }

        node->node = nullptr;
        node->next = this->list;
        this->list = node;
        return 1;
    }

    return 1;
}

void RGE_Active_Sprite_List::update(float param_1, float param_2) {
    // Source of truth: asp_list.cpp.decomp @ 0x0041AA20
    for (RGE_Active_Sprite_Node* node = this->list; node != nullptr; node = node->next) {
        node->node->update(param_1, param_2);
    }
}

void RGE_Active_Sprite_List::draw(short param_1, short param_2, short param_3, short param_4, short param_5, RGE_Color_Table* param_6, TDrawArea* param_7) {
    // Source of truth: asp_list.cpp.decomp @ 0x0041AA50
    for (RGE_Active_Sprite_Node* node = this->list; node != nullptr; node = node->next) {
        node->node->draw(param_1, (long)param_2, (long)param_3, (long)param_4, (long)param_5, param_6, param_7);
    }
}

void RGE_Active_Sprite_List::normal_draw(short param_1, short param_2, short param_3, RGE_Color_Table* param_4, TDrawArea* param_5) {
    // Source of truth: asp_list.cpp.decomp @ 0x0041AAA0
    for (RGE_Active_Sprite_Node* node = this->list; node != nullptr; node = node->next) {
        node->node->normal_draw(param_1, (long)param_2, (long)param_3, param_4, param_5);
    }
}

void RGE_Active_Sprite_List::shadow_draw(short param_1, short param_2, short param_3, RGE_Color_Table* param_4, TDrawArea* param_5, uchar param_6) {
    // Source of truth: asp_list.cpp.decomp @ 0x0041AAE0
    for (RGE_Active_Sprite_Node* node = this->list; node != nullptr; node = node->next) {
        node->node->shadow_draw(param_1, (long)param_2, (long)param_3, param_4, param_5, param_6);
    }
}

short RGE_Active_Sprite_List::frame(RGE_Sprite* param_1) {
    // Source of truth: asp_list.cpp.decomp @ 0x0041AB20
    for (RGE_Active_Sprite_Node* node = this->list; node != nullptr; node = node->next) {
        if (node->node->sprite == param_1) {
            return node->node->what_frame();
        }
    }
    return 0;
}

uchar RGE_Active_Sprite_List::is_animating(RGE_Sprite* param_1) {
    // Source of truth: asp_list.cpp.decomp @ 0x0041AB60
    for (RGE_Active_Sprite_Node* node = this->list; node != nullptr; node = node->next) {
        if (node->node->sprite == param_1) {
            return node->node->is_animating();
        }
    }
    return 0;
}

void RGE_Active_Sprite_List::set_frame(RGE_Sprite* param_1, short param_2) {
    // Source of truth: asp_list.cpp.decomp @ 0x0041AB90
    for (RGE_Active_Sprite_Node* node = this->list; node != nullptr; node = node->next) {
        if (node->node->sprite == param_1) {
            node->node->set_frame(param_2);
        }
    }
}

uchar RGE_Active_Sprite_List::frame_passed(RGE_Sprite* param_1, short param_2) {
    // Source of truth: asp_list.cpp.decomp @ 0x0041ABC0
    for (RGE_Active_Sprite_Node* node = this->list; node != nullptr; node = node->next) {
        if (node->node->sprite == param_1) {
            return node->node->frame_passed(param_2);
        }
    }
    return 0;
}

uchar RGE_Active_Sprite_List::looped(RGE_Sprite* param_1) {
    // Source of truth: asp_list.cpp.decomp @ 0x0041AC00
    for (RGE_Active_Sprite_Node* node = this->list; node != nullptr; node = node->next) {
        if (node->node->sprite == param_1) {
            return node->node->looped();
        }
    }
    return 0;
}

short RGE_Active_Sprite_List::get_facetindex(RGE_Sprite* param_1, short param_2) {
    // Source of truth: asp_list.cpp.decomp @ 0x0041AC30
    for (RGE_Active_Sprite_Node* node = this->list; node != nullptr; node = node->next) {
        if (node->node->sprite == param_1) {
            return node->node->get_facetindex(param_2);
        }
    }
    return 0;
}
