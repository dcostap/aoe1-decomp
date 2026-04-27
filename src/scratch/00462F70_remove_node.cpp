// tried the direct unlink/search shapes; VC5 keeps drifting the early list-load/search basin
// remaining gap is the top-of-function register/branch shape, not the unlink stores or free call
extern "C" void __cdecl free(void* block);

class RGE_Static_Object;

class RGE_Object_Node {
public:
    RGE_Static_Object* node;
    RGE_Object_Node* next;
    RGE_Object_Node* prev;
};

class RGE_Object_List {
public:
    void* vtable_ptr;
    RGE_Object_Node* list;
    short number_of_objects;

    void remove_node(RGE_Static_Object* object, RGE_Object_Node* node);
};

void RGE_Object_List::remove_node(RGE_Static_Object* object, RGE_Object_Node* node) {
    RGE_Object_Node* current;

    current = this->list;
    if (current == 0) {
        return;
    }

    if (node == 0) {
        node = current;
        if (node->node != object) {
            while (1) {
                node = node->next;
                if (node == 0) {
                    return;
                }
                if (node->node == object) {
                    break;
                }
            }
        }
    }

    if (node->prev == 0) {
        this->list = node->next;
    } else {
        node->prev->next = node->next;
    }

    if (node->next != 0) {
        node->next->prev = node->prev;
    }

    free(node);
    this->number_of_objects--;
}
