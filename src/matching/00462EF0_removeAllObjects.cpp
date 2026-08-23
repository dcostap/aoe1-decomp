#ifndef OBJLIST_SHARED_CONTEXT
#include "../../include/obj_list_context.h"
#endif

void RGE_Object_List::removeAllObjects(void) {
    RGE_Object_Node* node = this->list;

    while (node != 0) {
        RGE_Object_Node* next = node->next;
        if (node->object != 0) {
            node->object->destroy(1);
        }
        node = next;
    }
    this->list = 0;
    this->number_of_objects = 0;
}
