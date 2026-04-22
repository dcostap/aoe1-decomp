// tried lhs<rhs, reversed > form, named locals, ordered pointer locals, the fully direct-member compare, and a one-local objects/direct-master hybrid; all still kept the wrong initial master-vs-objects load order
// the remaining gap is now isolated to that first load order, with the cmp/setl tail already matching cleanly
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

    unsigned char more_room();
};

unsigned char RGE_Static_Object::more_room() {
    RGE_Object_List* objects;

    objects = this->objects;
    if (objects->number_of_objects < (short)(unsigned char)this->master_obj->obj_max)
        return 1;
    return 0;
}
