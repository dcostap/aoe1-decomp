extern "C" void __cdecl rge_write(int file, void* data, int size);

#ifndef ASP_LIST_SHARED_CONTEXT
#include "../asp_list_context.h"
#endif

void RGE_Active_Sprite_List::save(int file) {
    RGE_Active_Sprite_Node* node = this->list;
    unsigned char ender = 0;

    while (node) {
        node->node->save(file);
        node = node->next;
    }

    rge_write(file, &ender, 1);
}
