extern "C" void __cdecl free(void* block);

#ifndef ASP_LIST_SHARED_CONTEXT
class RGE_Static_Object {
public:
    void remove_shadows();
};

class RGE_Active_Sprite {
public:
    virtual void destroy(int flags);
    int check_for_shadows();
};

class RGE_Active_Sprite_Node {
public:
    RGE_Active_Sprite* node;
    unsigned char order;
    unsigned char count;
    char gap_06[0x2];
    RGE_Active_Sprite_Node* next;
};

class RGE_Active_Sprite_List {
public:
    void* vtable_ptr;
    RGE_Active_Sprite_Node* list;
    RGE_Static_Object* owner;

    void delete_list();
};
#endif

void RGE_Active_Sprite_List::delete_list() {
    RGE_Active_Sprite_Node* node = this->list;

    while (node) {
        RGE_Active_Sprite_Node* next = node->next;

        if (node->node->check_for_shadows() && this->owner) {
            this->owner->remove_shadows();
        }

        if (node->node) {
            node->node->destroy(1);
        }

        free(node);
        node = next;
    }

    this->list = 0;
}
