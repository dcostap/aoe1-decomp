// more_room (004C58C0, 19 bytes, stat_obj.cpp)
// returns this->objects->number_of_objects < this->master_obj->obj_max
// tried: natural order; register allocation differs (master_obj goes to wrong reg)
// trying: reversed comparison order

class RGE_Object_List {
public:
    void* vtable;
    void* list;
    short number_of_objects; // +0x8
};

class RGE_Master_Static_Object {
public:
    void* vtable;
    unsigned char _pad[0x28];
    unsigned char obj_max; // +0x2C
};

class RGE_Static_Object {
public:
    void* vtable