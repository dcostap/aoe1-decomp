// 004637C0 RGE_Object_List::find_by_type
// Source: obj_list.cpp lines 621-649, size 207 bytes
// RGE_Static_Object* find_by_type(unsigned char type, float x, float y, unsigned char check_state, unsigned char state)
//
// Attempt log:
// - Baseline natural scan with an explicit empty-list return: 183-byte diff.
// - Wrapping the traversal in if(node != 0) plus do/while improved to 60 bytes;
//   this also exposed the original FPU compare as best_distance > dist.
// - Direct node->obj for the sentinel return matched the original memory reload,
//   but the loop still emitted je-to-tail plus jmp-to-loop (30-byte diff).
// - A forward goto/late return label was diagnostic only and emitted the same code.
// - Removing the redundant outer guard and using a natural while(node != 0), with
//   direct return node->obj, produced the exact 207-byte match under default flags.

#include <math.h>

#ifndef OBJLIST_SHARED_CONTEXT
struct RGE_Object_Node {
    class RGE_Static_Object* obj;
    RGE_Object_Node* next;
};

struct RGE_Static_Object {
    virtual ~RGE_Static_Object();
    long id;
    char pad_08[0x30];
    float world_x;
    float world_y;
    char pad_40[0x08];
    unsigned char object_state;
    char pad_49[0x05];
    unsigned char type;
};

struct RGE_Object_List {
    char gap_00[4];
    RGE_Object_Node* list;
    short number_of_objects;

    RGE_Static_Object* find_by_type(unsigned char type, float x, float y, unsigned char check_state, unsigned char state);
};
#endif

RGE_Static_Object* RGE_Object_List::find_by_type(unsigned char type, float x, float y, unsigned char check_state, unsigned char state)
{
    float best_distance = -1.0f;
    RGE_Static_Object* best_obj = 0;
    RGE_Object_Node* node = this->list;

    while (node != 0) {
        RGE_Static_Object* obj = node->obj;
        if (obj != 0 && obj->type == type && (!check_state || obj->object_state == state)) {
            if (x == -1.0f && y == -1.0f) {
                return node->obj;
            }

            float dx = x - obj->world_x;
            float dy = y - obj->world_y;
            float dist = dx * dx + dy * dy;

            if (best_distance == -1.0f || best_distance > dist) {
                best_distance = dist;
                best_obj = obj;
            }
        }
        node = node->next;
    }

    return best_obj;
}
