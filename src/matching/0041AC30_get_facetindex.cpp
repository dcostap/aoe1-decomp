#ifndef ASP_LIST_SHARED_CONTEXT
#include "../asp_list_context.h"
#endif

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
