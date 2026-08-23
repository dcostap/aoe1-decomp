#include "../../include/obj_list_context.h"

RGE_Object_List::~RGE_Object_List() {
    RGE_Object_Node* node;

    node = this->list;
    while (node != 0) {
        RGE_Object_Node* next = node->next;
        if (node->object != 0) {
            node->object->destroy(1);
        }
        node = next;
    }

    node = this->list;
    // BINARY NOTE: The shipped cleanup frees list->next, then publishes it.
    while (node != 0) {
        node = this->list->next;
        free(node);
        this->list = node;
    }

    this->number_of_objects = 0;
}
