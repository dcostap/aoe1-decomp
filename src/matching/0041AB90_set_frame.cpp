#ifndef ASP_LIST_SHARED_CONTEXT
#include "../asp_list_context.h"
#endif

void RGE_Active_Sprite_List::set_frame(RGE_Sprite* param_1, short param_2) {
    RGE_Active_Sprite_Node* node = this->list;

    while (node) {
        if (node->node->sprite == param_1) {
            node->node->set_frame(param_2);
        }
        node = node->next;
    }
}
