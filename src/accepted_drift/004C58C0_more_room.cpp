// VA: 004C58C0 more_room (19B, stat_obj.cpp)
// Attempt log:
// v1: separate temp vars -> reordered loads + xor ecx + setl cl/mov al,cl (21B)
// v2: direct expression + Ghidra-style casts -> same result
// v3: explicit result temp with cast -> same
// Remaining: register allocation diff, behavior identical

#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class RGE_Object_List {
public:
    char gap_00[8];
    short number_of_objects; // +0x08
};

class RGE_Master_Static_Object {
public:
    char gap_00[0x2C];
    unsigned char obj_max; // +0x2C
};

class RGE_Static_Object {
public:
    char gap_00[8];
    RGE_Master_Static_Object* master_obj; // +0x08
    char gap_0C[0x18];
    RGE_Object_List* objects; // +0x24

    unsigned char more_room();
};
#endif

unsigned char RGE_Static_Object::more_room() {
    return objects->number_of_objects < (short)(unsigned short)master_obj->obj_max;
}
