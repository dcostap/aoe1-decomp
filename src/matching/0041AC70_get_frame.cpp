#ifndef ASP_LIST_SHARED_CONTEXT
#include "../asp_list_context.h"
#endif

unsigned char RGE_Active_Sprite_List::get_frame(short& param_1, short& param_2, short& param_3,
                                                short& param_4, RGE_Sprite* param_5, long param_6) {
    RGE_Active_Sprite_Node* node = this->list;

    while (node) {
        if (node->node->sprite == param_5) {
            return node->node->get_frame(&param_1, &param_2, &param_3, &param_4, param_6);
        }
        node = node->next;
    }

    return 0;
}
