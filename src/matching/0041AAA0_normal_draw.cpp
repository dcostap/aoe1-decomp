#ifndef ASP_LIST_SHARED_CONTEXT
#include "../asp_list_context.h"
#endif

void RGE_Active_Sprite_List::normal_draw(short param_1, short param_2, short param_3,
                                         RGE_Color_Table* param_4, TDrawArea* param_5) {
    RGE_Active_Sprite_Node* node = this->list;

    while (node) {
        node->node->normal_draw(param_1, param_2, param_3, param_4, param_5);
        node = node->next;
    }
}
