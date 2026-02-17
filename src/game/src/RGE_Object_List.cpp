#include "../include/RGE_Object_List.h"

#include "../include/RGE_Object_Node.h"
#include "../include/RGE_Static_Object.h"
#include "../include/TMousePointer.h"
#include "../include/globals.h"

void RGE_Object_List::update() {
    // Fully verified. Source of truth: obj_list.cpp.decomp @ 0x00463210
    int polled_objects = 0;
    RGE_Object_Node* node = this->list;
    while (node != nullptr) {
        RGE_Object_Node* next = node->next;
        if (node->node != nullptr) {
            if (node->node->update() != '\0') {
                node->node->recycle_out_of_game();
            }
            polled_objects = polled_objects + 1;
            if (polled_objects > 9) {
                polled_objects = 0;
                if (MouseSystem != nullptr) {
                    MouseSystem->Poll();
                }
            }
        }
        node = next;
    }
}
