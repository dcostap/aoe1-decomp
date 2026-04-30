// RGE_Object_List::find_by_id - find object with matching id in linked list

class RGE_Static_Object {
public:
    char gap_00[4];
    long id;  // 0x04
};

class RGE_Object_List {
public:
    char gap_00[4];
    void* list;  // 0x04 - linked list head

    RGE_Static_Object* find_by_id(long id);
};

RGE_Static_Object* RGE_Object_List::find_by_id(long target_id) {
    void** node = (void**)this->list;

    while (node) {
        RGE_Static_Object* obj = (RGE_Static_Object*)node[0];
        if (obj != 0 && obj->id == target_id)
            return obj;
        node = (void**)node[1];
    }

    return 0;
}
