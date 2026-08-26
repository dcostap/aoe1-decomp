extern "C" void __cdecl free(void* block);

#ifndef ASP_LIST_SHARED_CONTEXT
#include "../asp_list_context.h"
#endif

void RGE_Active_Sprite_List::delete_list() {
    RGE_Active_Sprite_Node* node = this->list;

    while (node) {
        RGE_Active_Sprite_Node* next = node->next;

        if (node->node->check_for_shadows() && this->owner) {
            this->owner->remove_shadows();
        }

        if (node->node) {
            delete node->node;
        }

        free(node);
        node = next;
    }

    this->list = 0;
}
