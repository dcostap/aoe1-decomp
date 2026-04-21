class RGE_Active_Sprite {
public:
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

    int check_for_shadows();
};

int RGE_Active_Sprite_List::check_for_shadows() {
    RGE_Active_Sprite_Node* node = this->list;

    if (node == 0) {
        return 0;
    }

    while (node) {
        if (node->node->check_for_shadows()) {
            return 1;
        }
        node = node->next;
    }

    return 0;
}
