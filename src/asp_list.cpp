
#include "../include/asp_list.h"
#include "../include/sprite.h"
#include "../include/stat_obj.h"

#include "../include/rge_fio.h"
extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);
extern "C" void __cdecl free(void* block);

RGE_Active_Sprite_List::RGE_Active_Sprite_List(RGE_Static_Object* owner_in) {
    this->list = 0;
    this->owner = owner_in;
}

// The body stores the class vptr and tail-jumps to delete_list.
RGE_Active_Sprite_List::~RGE_Active_Sprite_List() {
    delete_list();
}

void RGE_Active_Sprite_List::load(int infile, RGE_Sprite** sprites) {
    unsigned char type;
    RGE_Active_Sprite_Node* node;
    RGE_Active_Sprite_Node* reversed_list;
    RGE_Sprite** sprites_copy;

    sprites_copy = sprites;
    do {
        // Preserve the original sprite-array pointer while reading the type byte.
        rge_read(infile, &sprites, 1);
        type = this->load_node(infile, (unsigned char)sprites, sprites_copy);
    } while (type != 0);

    reversed_list = 0;
    while (this->list != 0) {
        node = this->list->next;
        this->list->next = reversed_list;
        reversed_list = this->list;
        this->list = node;
    }
    this->list = reversed_list;
}

// This protected owner carries the shipped EH cleanup state.
unsigned char RGE_Active_Sprite_List::load_node(int infile, unsigned char type, RGE_Sprite** sprites) {
    RGE_Active_Sprite_Node* node;
    RGE_Active_Sprite* sprite;
    int type_value = type;

    switch (type_value) {
    case 1:
        node = (RGE_Active_Sprite_Node*)calloc(0xc, 1);
        sprite = new RGE_Active_Sprite(infile, sprites);
        node->node = sprite;
        node->next = this->list;
        this->list = node;
        break;

    case 2:
        node = (RGE_Active_Sprite_Node*)calloc(0xc, 1);
        sprite = new RGE_Active_Animated_Sprite(infile, sprites);
        node->node = sprite;
        node->next = this->list;
        this->list = node;
        break;

    case 0:
        return 0;
    }

    return 1;
}

void RGE_Active_Sprite_List::save(int outfile) {
    RGE_Active_Sprite_Node* node = this->list;
    unsigned char ender = 0;

    while (node) {
        node->node->save(outfile);
        node = node->next;
    }

    // A zero type byte terminates the serialized active-sprite list.
    rge_write(outfile, &ender, 1);
}

void RGE_Active_Sprite_List::delete_list() {
    RGE_Active_Sprite_Node* node = this->list;

    while (node) {
        RGE_Active_Sprite_Node* next_node = node->next;

        // Remove shadows before deleting the active sprite that owns them.
        if (node->node->check_for_shadows() && this->owner) {
            this->owner->remove_shadows();
        }

        if (node->node) {
            delete node->node;
        }

        free(node);
        node = next_node;
    }

    this->list = 0;
}

RGE_Active_Sprite_Node* RGE_Active_Sprite_List::copy_sprite_list() {
    RGE_Active_Sprite_Node* old_list = this->list;
    RGE_Active_Sprite_Node* node = old_list;

    // Build a detached list, then restore the original list and return the copy.
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

void RGE_Active_Sprite_List::use_sprite_list(RGE_Active_Sprite_Node* temp_list) {
    this->delete_list();
    this->list = temp_list;
}

void RGE_Active_Sprite_List::add_sprite(RGE_Sprite* sprite, unsigned char order, long x, long y) {
    RGE_Active_Sprite_Node* node;
    RGE_Active_Sprite_Node** link;
    RGE_Active_Sprite* active_sprite;

    if (sprite == 0) {
        return;
    }

    if (sprite->check_for_shadows() != 0 && this->owner != 0) {
        this->owner->remove_shadows();
    }

    link = &this->list;
    node = this->list;
    while (node != 0) {
        if (node->node->sprite == sprite) {
            // Repeated additions share one active node.
            node->count++;
            return;
        }
        node = node->next;
    }

    node = this->list;
    while (node != 0 && node->order <= order) {
        link = &node->next;
        node = node->next;
    }

    node = (RGE_Active_Sprite_Node*)calloc(0xc, 1);
    active_sprite = sprite->make_active_sprite();
    node->node = active_sprite;
    active_sprite->set_offset(x, y);
    node->order = order;
    node->next = *link;
    *link = node;
}

void RGE_Active_Sprite_List::remove_sprite(RGE_Sprite* sprite) {
    RGE_Active_Sprite_Node* node = this->list;
    RGE_Active_Sprite_Node** previous_link = &this->list;
    if (node != 0) {
        while (node != 0) {
            if (node->node->sprite == sprite) {
                if (node->count > 0) {
                    node->count = node->count + 0xff;
                    return;
                }
                *previous_link = node->next;
                if (node->node->check_for_shadows() != 0 && this->owner != 0) {
                    this->owner->remove_shadows();
                }
                if (node->node != 0) {
                    delete node->node;
                }
                free(node);
                return;
            }
            previous_link = &node->next;
            node = node->next;
        }
    }
}

void RGE_Active_Sprite_List::update(float time, float speed) {
    RGE_Active_Sprite_Node* node = this->list;

    if (node) {
        float speed_value = speed;
        float time_value = time;

        do {
            node->node->update(time_value, speed_value);
            node = node->next;
        } while (node);
    }
}

void RGE_Active_Sprite_List::draw(short facet, short x, short y, short sx, short sy,
                                  RGE_Color_Table* player_color, TDrawArea* draw_area) {
    RGE_Active_Sprite_Node* node = this->list;

    while (node) {
        node->node->draw(facet, x, y, sx, sy, player_color, draw_area);
        node = node->next;
    }
}

void RGE_Active_Sprite_List::normal_draw(short facet, short x, short y,
                                         RGE_Color_Table* player_color, TDrawArea* draw_area) {
    RGE_Active_Sprite_Node* node = this->list;

    while (node) {
        node->node->normal_draw(facet, x, y, player_color, draw_area);
        node = node->next;
    }
}

void RGE_Active_Sprite_List::shadow_draw(short facet, short x, short y,
                                         RGE_Color_Table* player_color, TDrawArea* draw_area,
                                         unsigned char flag) {
    RGE_Active_Sprite_Node* node = this->list;

    while (node) {
        node->node->shadow_draw(facet, x, y, player_color, draw_area, flag);
        node = node->next;
    }
}

short RGE_Active_Sprite_List::frame(RGE_Sprite* sprite) {
    RGE_Active_Sprite_Node* node = this->list;

    while (node) {
        if (node->node->sprite == sprite) {
            return node->node->what_frame();
        }
        node = node->next;
    }

    return 0;
}

unsigned char RGE_Active_Sprite_List::is_animating(RGE_Sprite* sprite) {
    RGE_Active_Sprite_Node* node = this->list;

    while (node) {
        if (node->node->sprite == sprite) {
            return node->node->is_animating();
        }
        node = node->next;
    }

    return 0;
}

void RGE_Active_Sprite_List::set_frame(RGE_Sprite* sprite, short new_frame) {
    RGE_Active_Sprite_Node* node = this->list;

    while (node) {
        if (node->node->sprite == sprite) {
            node->node->set_frame(new_frame);
        }
        node = node->next;
    }
}

unsigned char RGE_Active_Sprite_List::frame_passed(RGE_Sprite* sprite, short pass_frame) {
    RGE_Active_Sprite_Node* node = this->list;

    while (node) {
        if (node->node->sprite == sprite) {
            return node->node->frame_passed(pass_frame);
        }
        node = node->next;
    }

    return 0;
}

unsigned char RGE_Active_Sprite_List::looped(RGE_Sprite* sprite) {
    RGE_Active_Sprite_Node* node = this->list;

    while (node) {
        if (node->node->sprite == sprite) {
            return node->node->looped();
        }
        node = node->next;
    }

    return 0;
}

short RGE_Active_Sprite_List::get_facetindex(RGE_Sprite* sprite, short facet) {
    RGE_Active_Sprite_Node* node = this->list;

    while (node) {
        if (node->node->sprite == sprite) {
            return node->node->get_facetindex(facet);
        }
        node = node->next;
    }

    return 0;
}

unsigned char RGE_Active_Sprite_List::get_frame(short& min_x, short& min_y, short& max_x,
                                                short& max_y, RGE_Sprite* sprite, long facet) {
    RGE_Active_Sprite_Node* node = this->list;

    while (node) {
        if (node->node->sprite == sprite) {
            return node->node->get_frame(min_x, min_y, max_x, max_y, facet);
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
