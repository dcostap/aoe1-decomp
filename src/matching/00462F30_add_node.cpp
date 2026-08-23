#ifndef OBJLIST_SHARED_CONTEXT
#include "../../include/obj_list_context.h"
#endif

// BINARY NOTE: Source initializes next before prev; VC5 emits prev-zero first.
RGE_Object_Node* RGE_Object_List::add_node(RGE_Static_Object* object) {
    RGE_Object_Node* node;

    node = (RGE_Object_Node*)calloc(1, 0x10);
    node->next = this->list;
    node->prev = 0;
    if (this->list != 0) {
        this->list->prev = node;
    }
    node->node = object;
    this->number_of_objects++;
    this->list = node;
    return node;
}
