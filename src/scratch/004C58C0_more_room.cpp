// STATUS: blocked
// BLOCKER: operand/load order mismatch; VC5 keeps loading master_obj before objects
// NOTE: exact compare shape matches except for reversed load order in first two moves

class RGE_Static_Object_List {
public:
    char gap_00[0x08];
    short number_of_objects;
};

class RGE_Master_Static_Object {
public:
    char gap_00[0x2C];
    unsigned char obj_max;
};

class RGE_Static_Object {
public:
    char gap_00[0x08];
    RGE_Master_Static_Object* master_obj;
    char gap_0C[0x18];
    RGE_Static_Object_List* objects;

    unsigned char more_room(void);
};

unsigned char RGE_Static_Object::more_room(void) {
    volatile RGE_Static_Object_List* object_list;

    object_list = objects;
    if (object_list->number_of_objects < (unsigned char)master_obj->obj_max) {
        return 1;
    }
    return 0;
}
