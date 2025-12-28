#include "RGE_Object_List.h"
#include <string.h>

RGE_Object_List::RGE_Object_List() {
    this->list = nullptr;
    this->number_of_objects = 0;
}

void RGE_Object_List::load(uchar param_1, int param_2, struct RGE_Game_World *param_3) {
    // Stub
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
