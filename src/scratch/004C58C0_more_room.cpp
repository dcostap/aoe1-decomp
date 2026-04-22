// tried the direct lhs<rhs form first; VC5 loaded master_obj before objects and added an extra bool-zeroing step
// kept the local layout stubs but flipped the compare and return type to bool; load order still stayed master-first
// left this in scratch because the remaining gap is small codegen drift in operand-load order and setcc materialization
class RGE_Object_List {
public:
    void* vtable_ptr;
    void* list;
    short number_of_objects;
};

class RGE_Master_Static_Object {
public:
    char gap_00[0x2C];
    unsigned char obj_max;
};

class RGE_Static_Object {
public:
    void* vtable_ptr;
    long id;
    RGE_Master_Static_Object* master_obj;
    char gap_0C[0x18];
    RGE_Object_List* objects;

    bool more_room();
};

bool RGE_Static_Object::more_room() {
    return (short)(unsigned char)this->master_obj->obj_max > this->objects->number_of_objects;
}
