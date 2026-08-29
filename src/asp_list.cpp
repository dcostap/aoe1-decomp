// Authentic source module for C:\\msdev\\work\\age1_x1\\asp_list.cpp.
// The compiler emits the nearby vector-deleting destructor at 0041A660.

#include "../include/asp_list.h"
#include "../include/sprite.h"
#include "../include/stat_obj.h"

extern "C" void __cdecl rge_read(int handle, void* buffer, int size);
extern "C" void __cdecl rge_write(int handle, void* buffer, int size);
extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);
extern "C" void __cdecl free(void* block);

RGE_Active_Sprite_List::RGE_Active_Sprite_List(RGE_Static_Object* owner) {
    this->list = 0;
    this->owner = owner;
}

// The body stores the class vptr and tail-jumps to delete_list.
RGE_Active_Sprite_List::~RGE_Active_Sprite_List() {
    delete_list();
}

void RGE_Active_Sprite_List::load(int param_1, RGE_Sprite** param_2) {
    unsigned char cVar4;
    RGE_Active_Sprite_Node* pRVar2;
    RGE_Active_Sprite_Node* pRVar5;
    RGE_Sprite** ppRVar3;

    ppRVar3 = param_2;
    do {
        rge_read(param_1, &param_2, 1);
        cVar4 = this->load_node(param_1, (unsigned char)param_2, ppRVar3);
    } while (cVar4 != 0);

    pRVar5 = 0;
    while (this->list != 0) {
        pRVar2 = this->list->next;
        this->list->next = pRVar5;
        pRVar5 = this->list;
        this->list = pRVar2;
    }
    this->list = pRVar5;
}

// This protected owner carries the shipped EH cleanup state.
unsigned char RGE_Active_Sprite_List::load_node(int param_1, unsigned char param_2,
                                                 RGE_Sprite** param_3) {
    RGE_Active_Sprite_Node* node;
    RGE_Active_Sprite* sprite;
    int type = param_2;

    switch (type) {
    case 1:
        node = (RGE_Active_Sprite_Node*)calloc(0xc, 1);
        sprite = new RGE_Active_Sprite(param_1, param_3);
        node->node = sprite;
        node->next = this->list;
        this->list = node;
        break;

    case 2:
        node = (RGE_Active_Sprite_Node*)calloc(0xc, 1);
        sprite = new RGE_Active_Animated_Sprite(param_1, param_3);
        node->node = sprite;
        node->next = this->list;
        this->list = node;
        break;

    case 0:
        return 0;
    }

    return 1;
}

void RGE_Active_Sprite_List::save(int file) {
    RGE_Active_Sprite_Node* node = this->list;
    unsigned char ender = 0;

    while (node) {
        node->node->save(file);
        node = node->next;
    }

    rge_write(file, &ender, 1);
}

void RGE_Active_Sprite_List::delete_list() {
    RGE_Active_Sprite_Node* node = this->list;

    while (node) {
        RGE_Active_Sprite_Node* next = node->next;

        if (node->node->check_for_shadows() && this->owner) {
            this->owner->remove_shadows();
        }

        if (node->node) {
            delete node->node;
        }

        free(node);
        node = next;
    }

    this->list = 0;
}

RGE_Active_Sprite_Node* RGE_Active_Sprite_List::copy_sprite_list() {
    RGE_Active_Sprite_Node* old_list = this->list;
    RGE_Active_Sprite_Node* node = old_list;

    this->list = 0;

    while (node) {
        this->add_sprite(node->node->sprite, node->order, node->node->offset_x,
                         node->node->offset_y);
        node = node->next;
    }

    node = this->list;
    this->list = old_list;
    return node;
}

void RGE_Active_Sprite_List::use_sprite_list(RGE_Active_Sprite_Node* list) {
    this->delete_list();
    this->list = list;
}

// The source preserves duplicate counts and order insertion.
void RGE_Active_Sprite_List::add_sprite(RGE_Sprite* param_1, unsigned char param_2,
                                        long param_3, long param_4) {
    RGE_Active_Sprite_Node* pp;
    RGE_Active_Sprite_Node** ppPrev;

    if (param_1 == 0) { return; }

    if (param_1->check_for_shadows() && this->owner) {
        this->owner->remove_shadows();
    }

    pp = this->list;
    ppPrev = &this->list;
    while (pp != 0) {
        if (pp->node->sprite == param_1) {
            pp->count++;
            return;
        }
        pp = pp->next;
    }

    pp = this->list;
    while (pp != 0 && pp->order <= param_2) {
        ppPrev = &pp->next;
        pp = pp->next;
    }

    RGE_Active_Sprite_Node* node =
        (RGE_Active_Sprite_Node*)calloc(0xc, 1);
    RGE_Active_Sprite* asp = param_1->make_active_sprite();
    node->node = asp;
    asp->set_offset(param_3, param_4);
    node->order = param_2;
    node->next = *ppPrev;
    *ppPrev = node;
}

void RGE_Active_Sprite_List::remove_sprite(RGE_Sprite* param_1) {
    RGE_Active_Sprite_Node* p = this->list;
    RGE_Active_Sprite_Node** ppPrev = &this->list;
    if (p != 0) {
        while (p != 0) {
            if (p->node->sprite == param_1) {
                if (p->count > 0) {
                    p->count = p->count + 0xff;
                    return;
                }
                *ppPrev = p->next;
                if (p->node->check_for_shadows() != 0 && this->owner != 0) {
                    this->owner->remove_shadows();
                }
                if (p->node != 0) {
                    delete p->node;
                }
                free(p);
                return;
            }
            ppPrev = &p->next;
            p = p->next;
        }
    }
}

void RGE_Active_Sprite_List::update(float param_1, float param_2) {
    RGE_Active_Sprite_Node* node = this->list;

    if (node) {
        float p2 = param_2;
        float p1 = param_1;

        do {
            node->node->update(p1, p2);
            node = node->next;
        } while (node);
    }
}

void RGE_Active_Sprite_List::draw(short param_1, short param_2, short param_3,
                                  short param_4, short param_5, RGE_Color_Table* param_6,
                                  TDrawArea* param_7) {
    RGE_Active_Sprite_Node* node = this->list;

    while (node) {
        node->node->draw(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
        node = node->next;
    }
}

void RGE_Active_Sprite_List::normal_draw(short param_1, short param_2, short param_3,
                                         RGE_Color_Table* param_4, TDrawArea* param_5) {
    RGE_Active_Sprite_Node* node = this->list;

    while (node) {
        node->node->normal_draw(param_1, param_2, param_3, param_4, param_5);
        node = node->next;
    }
}

void RGE_Active_Sprite_List::shadow_draw(short param_1, short param_2, short param_3,
                                         RGE_Color_Table* param_4, TDrawArea* param_5,
                                         unsigned char param_6) {
    RGE_Active_Sprite_Node* node = this->list;

    while (node) {
        node->node->shadow_draw(param_1, param_2, param_3, param_4, param_5, param_6);
        node = node->next;
    }
}

short RGE_Active_Sprite_List::frame(RGE_Sprite* param_1) {
    RGE_Active_Sprite_Node* node = this->list;

    while (node) {
        if (node->node->sprite == param_1) {
            return node->node->what_frame();
        }
        node = node->next;
    }

    return 0;
}

unsigned char RGE_Active_Sprite_List::is_animating(RGE_Sprite* param_1) {
    RGE_Active_Sprite_Node* node = this->list;

    while (node) {
        if (node->node->sprite == param_1) {
            return node->node->is_animating();
        }
        node = node->next;
    }

    return 0;
}

void RGE_Active_Sprite_List::set_frame(RGE_Sprite* param_1, short param_2) {
    RGE_Active_Sprite_Node* node = this->list;

    while (node) {
        if (node->node->sprite == param_1) {
            node->node->set_frame(param_2);
        }
        node = node->next;
    }
}

unsigned char RGE_Active_Sprite_List::frame_passed(RGE_Sprite* param_1, short param_2) {
    RGE_Active_Sprite_Node* node = this->list;

    while (node) {
        if (node->node->sprite == param_1) {
            return node->node->frame_passed(param_2);
        }
        node = node->next;
    }

    return 0;
}

unsigned char RGE_Active_Sprite_List::looped(RGE_Sprite* param_1) {
    RGE_Active_Sprite_Node* node = this->list;

    while (node) {
        if (node->node->sprite == param_1) {
            return node->node->looped();
        }
        node = node->next;
    }

    return 0;
}

short RGE_Active_Sprite_List::get_facetindex(RGE_Sprite* param_1, short param_2) {
    RGE_Active_Sprite_Node* node = this->list;

    while (node) {
        if (node->node->sprite == param_1) {
            return node->node->get_facetindex(param_2);
        }
        node = node->next;
    }

    return 0;
}

unsigned char RGE_Active_Sprite_List::get_frame(short& param_1, short& param_2,
                                                short& param_3, short& param_4,
                                                RGE_Sprite* param_5, long param_6) {
    RGE_Active_Sprite_Node* node = this->list;

    while (node) {
        if (node->node->sprite == param_5) {
            return node->node->get_frame(param_1, param_2, param_3, param_4, param_6);
        }
        node = node->next;
    }

    return 0;
}

unsigned char RGE_Active_Sprite_List::get_lowest_draw_level() {
    unsigned char min_level = 0x14;
    RGE_Active_Sprite_Node* node = this->list;

    while (node) {
        unsigned char level = node->node->get_lowest_draw_level();
        if (level < min_level) {
            min_level = level;
        }
        node = node->next;
    }

    return min_level;
}

int RGE_Active_Sprite_List::check_for_shadows() {
    RGE_Active_Sprite_Node* node = this->list;

    if (node == 0) {
        return 0;
    }

    while (node) {
        if (node->node->check_for_shadows()) {
            return 1;
        }
        node = node->next;
    }

    return 0;
}
