extern "C" void __cdecl free(void* block);
class RGE_Static_Object;
class RGE_Object_Node { public: RGE_Static_Object* node; RGE_Object_Node* next; RGE_Object_Node* prev; };
class RGE_Object_List { public: void* vtable_ptr; RGE_Object_Node* list; short number_of_objects; void remove_node(RGE_Static_Object* object, RGE_Object_Node* node); };
void RGE_Object_List::remove_node(RGE_Static_Object* object, RGE_Object_Node* node) {
    RGE_Object_Node* n = this->list;
    if (n == 0) return;
    if (node == 0) {
        RGE_Static_Object* obj = object;
        while (n->node != obj) {
            n = n->next;
            if (n == 0) return;
        }
    } else {
        n = node;
    }
    if (n->prev != 0) {
        n->prev->next = n->next;
    } else {
        this->list = n->next;
    }
    if (n->next != 0) {
        n->next->prev = n->prev;
    }
    free(n);
    --this->number_of_objects;
}
