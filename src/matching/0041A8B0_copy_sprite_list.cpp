#ifndef ASP_LIST_SHARED_CONTEXT
#include "../asp_list_context.h"
#endif

RGE_Active_Sprite_Node* RGE_Active_Sprite_List::copy_sprite_list() {
    RGE_Active_Sprite_Node* old_list = this->list;
    RGE_Active_Sprite_Node* node = old_list;

    this->list = 0;

    while (node) {
        this->add_sprite(node->node->sprite, node->order, node->node->offset_x, node->node->offset_y);
        node = node->next;
    }

    node = this->list;
    this->list = old_list;
    return node;
}
