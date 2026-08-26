#ifndef ASP_LIST_SHARED_CONTEXT
#include "../asp_list_context.h"
#endif

void RGE_Active_Sprite_List::use_sprite_list(RGE_Active_Sprite_Node* list) {
    this->delete_list();
    this->list = list;
}
