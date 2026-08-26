#ifndef ASP_LIST_SHARED_CONTEXT
#include "../asp_list_context.h"
#endif

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
