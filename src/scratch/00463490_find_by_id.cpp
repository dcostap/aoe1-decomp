class RGE_Static_Object {
public:
    char gap_00[4];
    long id;
};

struct RGE_Object_List_Node {
    RGE_Static_Object* object;
    RGE_Object_List_Node* next;
};

class RGE_Object_List {
public:
    char gap_00[4];
    RGE_Object_List_Node* list;

    RGE_Static_Object* find_by_id(long id);
};

RGE_Static_Object* RGE_Object_List::find_by_id(long id) {
    RGE_Object_List_Node* node = this->list;

    if (node == 0) {
        return 0;
    }

    while (node->object == 0 || node->object->id != id) {
        node = node->next;
        if (node == 0) {
            return 0;
        }
    }

    return node->object;
}
