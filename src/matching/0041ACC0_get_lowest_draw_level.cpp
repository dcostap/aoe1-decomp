#ifndef ASP_LIST_SHARED_CONTEXT
#include "../asp_list_context.h"
#endif

unsigned char RGE_Active_Sprite_List::get_lowest_draw_level() {
    unsigned char min_level = 0x14;
    RGE_Active_Sprite_Node* node = this->list;

    while (node) {
        unsigned char level = node->node->get_lowest_draw_level();
        if (level < min_level) {
            min_level = level;
        }
        node = node->next;
    }

    return min_level;
}
