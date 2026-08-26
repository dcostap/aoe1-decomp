#ifndef ASP_LIST_SHARED_CONTEXT
#include "../asp_list_context.h"
#endif

void RGE_Active_Sprite_List::draw(short param_1, short param_2, short param_3,
                                  short param_4, short param_5, RGE_Color_Table* param_6,
                                  TDrawArea* param_7) {
    RGE_Active_Sprite_Node* node = this->list;

    while (node) {
        node->node->draw(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
        node = node->next;
    }
}
