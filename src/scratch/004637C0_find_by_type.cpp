// 004637C0 RGE_Object_List::find_by_type
// Source: obj_list.cpp lines 621-649, size 207 bytes
// RGE_Static_Object* find_by_type(unsigned char type, float x, float y, unsigned char check_state, unsigned char state)
//
// Attempt log:
// 1: do/while with return 0 → null check inlined, fcom for dist comparison
// 2: if(node != 0) wrap → 183/207 equal, still fcom + merged epilogue
// 3: while(1)/break → same
// All remaining: VC5 codegen drift (fcom vs fld+fcomp, loop jne vs je+jmp, register choice)
// Attempts: 4 probes.
// - Prologue through type-cmp branch: nearly identical first 18 bytes
// - FPU math for dx*dx+dy*dy and best_distance compare: same structure
// - Three return paths correct (null, early, normal end)
// Remaining: loop epilogue (je+jmp vs jne), distance compare (fcom vs fld+fcomp),
//   null check epilogue (inline vs shared tail), early return register (ecx vs [edx])
// Parked: VC5 codegen drift only after 4 probes

#include <math.h>

struct RGE_Object_Node {
    class RGE_Static_Object* obj;
    RGE_Object_Node* next;
};

struct RGE_Static_Object {
    void* vtable;
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
    void* vtable;
    RGE_Object_Node* list;
    short number_of_objects;

    RGE_Static_Object* find_by_type(unsigned char type, float x, float y, unsigned char check_state, unsigned char state);
};

RGE_Static_Object* RGE_Object_List::find_by_type(unsigned char type, float x, float y, unsigned char check_state, unsigned char state)
{
    float best_distance = -1.0f;
    RGE_Static_Object* best_obj = 0;
    RGE_Object_Node* node = this->list;

    if (node == 0) {
        return 0;
    }

    while (node != 0) {
        RGE_Static_Object* obj = node->obj;
        if (obj != 0 && obj->type == type && (!check_state || obj->object_state == state)) {
            if (x == -1.0f && y == -1.0f) {
                return obj;
            }

            float dx = x - obj->world_x;
            float dy = y - obj->world_y;
            float dist = dx * dx + dy * dy;

            if (best_distance == -1.0f || dist < best_distance) {
                best_distance = dist;
                best_obj = obj;
            }
        }
        node = node->next;
    }

    return best_obj;
}
