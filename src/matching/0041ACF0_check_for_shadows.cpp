#ifndef ASP_LIST_SHARED_CONTEXT
#include "../asp_list_context.h"
#endif

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
