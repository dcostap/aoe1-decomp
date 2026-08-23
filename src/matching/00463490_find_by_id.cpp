#ifndef OBJLIST_SHARED_CONTEXT
class RGE_Static_Object {
public:
    int gap_00;
    long id;
};

struct RGE_Object_Node {
    RGE_Static_Object* node;
    RGE_Object_Node* next;
    RGE_Object_Node* prev;
};

class RGE_Object_List {
public:
    char gap_00[4];
    RGE_Object_Node* list;

    RGE_Static_Object* find_by_id(long id);
};
#endif

RGE_Static_Object* RGE_Object_List::find_by_id(long target_id) {
    RGE_Object_Node* node = this->list;
    if (node == 0)
        return 0;

    while (node) {
        if (node->node != 0 && node->node->id == target_id)
            return node->node;
        node = node->next;
    }

    return 0;
}
