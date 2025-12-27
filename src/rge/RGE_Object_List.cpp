#include "RGE_Object_List.h"
#include <string.h>

RGE_Object_List::RGE_Object_List() {
    this->list = nullptr;
    this->number_of_objects = 0;
}

RGE_Object_List::~RGE_Object_List() {
    this->removeAllObjects();
}

void RGE_Object_List::removeAllObjects() {
    // Stub
}

void RGE_Object_List::remove_node(struct RGE_Static_Object *obj, struct RGE_Object_Node *node) {
    // Stub
}
