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

void RGE_Active_Sprite_List::save(int param_1) {
    // Fully verified. Source of truth: asp_list.cpp.decomp @ 0x0041A820
    RGE_Active_Sprite_Node* cur = this->list;
    while (cur != nullptr) {
        cur->node->save(param_1);
        cur = cur->next;
    }

    uchar zero = 0;
    rge_write(param_1, &zero, 1);
}

void RGE_Active_Sprite_List::delete_list() {
    // Fully verified. Source of truth: asp_list.cpp.decomp @ 0x0041A860
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

// Fully verified. Source of truth: asp_list.cpp.decomp @ 0x0041A8B0
RGE_Active_Sprite_Node* RGE_Active_Sprite_List::copy_sprite_list() {
    RGE_Active_Sprite_Node* original_list = this->list;
    this->list = nullptr;

    for (RGE_Active_Sprite_Node* node = original_list; node != nullptr; node = node->next) {
        RGE_Active_Sprite* active_sprite = node->node;
        this->add_sprite(active_sprite->sprite, node->order, active_sprite->offset_x, active_sprite->offset_y);
    }

    RGE_Active_Sprite_Node* copied_list = this->list;
    this->list = original_list;
    return copied_list;
}

// Fully verified. Source of truth: asp_list.cpp.decomp @ 0x0041A8F0
void RGE_Active_Sprite_List::use_sprite_list(RGE_Active_Sprite_Node* param_1) {
    this->delete_list();
    this->list = param_1;
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
    // Fully verified. Source of truth: asp_list.cpp.decomp @ 0x0041ACC0
    uchar bVar3 = 0x14;
    for (RGE_Active_Sprite_Node* pRVar1 = this->list; pRVar1 != nullptr; pRVar1 = pRVar1->next) {
        uchar bVar2 = pRVar1->node->get_lowest_draw_level();
        if (bVar2 < bVar3) {
            bVar3 = bVar2;
        }
    }
    return bVar3;
}

int RGE_Active_Sprite_List::check_for_shadows() {
    // Fully verified. Source of truth: asp_list.cpp.decomp @ 0x0041ACF0
    RGE_Active_Sprite_Node* node = this->list;
    while (node != nullptr) {
        if (node->node->check_for_shadows() != 0) {
            return 1;
        }
        node = node->next;
    }
    return 0;
}

RGE_Active_Sprite_List::~RGE_Active_Sprite_List() {
    // Fully verified. Source of truth: asp_list.cpp.decomp @ 0x0041A680
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
    // Fully verified. Source of truth: asp_list.cpp.decomp @ 0x0041A6F0
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
    // Fully verified. Source of truth: asp_list.cpp.decomp @ 0x0041AA20
    for (RGE_Active_Sprite_Node* node = this->list; node != nullptr; node = node->next) {
        node->node->update(param_1, param_2);
    }
}

void RGE_Active_Sprite_List::draw(short param_1, short param_2, short param_3, short param_4, short param_5, RGE_Color_Table* param_6, TDrawArea* param_7) {
    // Fully verified. Source of truth: asp_list.cpp.decomp @ 0x0041AA50
    for (RGE_Active_Sprite_Node* node = this->list; node != nullptr; node = node->next) {
        node->node->draw(param_1, (long)param_2, (long)param_3, (long)param_4, (long)param_5, param_6, param_7);
    }
}

void RGE_Active_Sprite_List::normal_draw(short param_1, short param_2, short param_3, RGE_Color_Table* param_4, TDrawArea* param_5) {
    // Fully verified. Source of truth: asp_list.cpp.decomp @ 0x0041AAA0
    for (RGE_Active_Sprite_Node* node = this->list; node != nullptr; node = node->next) {
        node->node->normal_draw(param_1, (long)param_2, (long)param_3, param_4, param_5);
    }
}

void RGE_Active_Sprite_List::shadow_draw(short param_1, short param_2, short param_3, RGE_Color_Table* param_4, TDrawArea* param_5, uchar param_6) {
    // Fully verified. Source of truth: asp_list.cpp.decomp @ 0x0041AAE0
    for (RGE_Active_Sprite_Node* node = this->list; node != nullptr; node = node->next) {
        node->node->shadow_draw(param_1, (long)param_2, (long)param_3, param_4, param_5, param_6);
    }
}

short RGE_Active_Sprite_List::frame(RGE_Sprite* param_1) {
    // Fully verified. Source of truth: asp_list.cpp.decomp @ 0x0041AB20
    for (RGE_Active_Sprite_Node* node = this->list; node != nullptr; node = node->next) {
        if (node->node->sprite == param_1) {
            return node->node->what_frame();
        }
    }
    return 0;
}

uchar RGE_Active_Sprite_List::is_animating(RGE_Sprite* param_1) {
    // Fully verified. Source of truth: asp_list.cpp.decomp @ 0x0041AB60
    for (RGE_Active_Sprite_Node* node = this->list; node != nullptr; node = node->next) {
        if (node->node->sprite == param_1) {
            return node->node->is_animating();
        }
    }
    return 0;
}

void RGE_Active_Sprite_List::set_frame(RGE_Sprite* param_1, short param_2) {
    // Fully verified. Source of truth: asp_list.cpp.decomp @ 0x0041AB90
    for (RGE_Active_Sprite_Node* node = this->list; node != nullptr; node = node->next) {
        if (node->node->sprite == param_1) {
            node->node->set_frame(param_2);
        }
    }
}

uchar RGE_Active_Sprite_List::frame_passed(RGE_Sprite* param_1, short param_2) {
    // Fully verified. Source of truth: asp_list.cpp.decomp @ 0x0041ABC0
    for (RGE_Active_Sprite_Node* node = this->list; node != nullptr; node = node->next) {
        if (node->node->sprite == param_1) {
            return node->node->frame_passed(param_2);
        }
    }
    return 0;
}

uchar RGE_Active_Sprite_List::looped(RGE_Sprite* param_1) {
    // Fully verified. Source of truth: asp_list.cpp.decomp @ 0x0041AC00
    for (RGE_Active_Sprite_Node* node = this->list; node != nullptr; node = node->next) {
        if (node->node->sprite == param_1) {
            return node->node->looped();
        }
    }
    return 0;
}

short RGE_Active_Sprite_List::get_facetindex(RGE_Sprite* param_1, short param_2) {
    // Fully verified. Source of truth: asp_list.cpp.decomp @ 0x0041AC30
    for (RGE_Active_Sprite_Node* node = this->list; node != nullptr; node = node->next) {
        if (node->node->sprite == param_1) {
            return node->node->get_facetindex(param_2);
        }
    }
    return 0;
}

uchar RGE_Active_Sprite_List::get_frame(short* param_1, short* param_2, short* param_3, short* param_4, RGE_Sprite* param_5, long param_6) {
    // Fully verified. Source of truth: asp_list.cpp.decomp @ 0x0041AC70
    for (RGE_Active_Sprite_Node* node = this->list; node != nullptr; node = node->next) {
        if (node->node->sprite == param_5) {
            return node->node->get_frame(param_1, param_2, param_3, param_4, param_6);
        }
    }
    return 0;
}

