class RGE_Static_Object;

struct RGE_Object_Node {
    RGE_Static_Object* node;
    RGE_Object_Node* next;
    RGE_Object_Node* prev;
    int gap_0C;
};

class RGE_Object_List {
public:
    char gap_00[0x04];
    RGE_Object_Node* list;
    short number_of_objects;

    RGE_Object_Node* add_node(RGE_Static_Object* object);
};

extern "C" void* __cdecl calloc(unsigned int num, unsigned int size);

RGE_Object_Node* RGE_Object_List::add_node(RGE_Static_Object* object) {
    RGE_Object_Node* node = (RGE_Object_Node*)calloc(1, 0x10);
    RGE_Object_Node* list = this->list;

    node->prev = 0;
    node->next = list;
    list = this->list;
    if (list != 0) {
        list->prev = node;
    }
    node->node = object;
    this->number_of_objects++;
    this->list = node;
    return node;
}
