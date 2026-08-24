#ifndef ASP_LIST_SHARED_CONTEXT
class RGE_Sprite;
class RGE_Active_Sprite;

class RGE_Active_Sprite_Node {
public:
    RGE_Active_Sprite* node;
    unsigned char order;
    unsigned char count;
    char gap_06[0x2];
    RGE_Active_Sprite_Node* next;
};

class RGE_Active_Sprite {
public:
    char gap_00[0x4];
    RGE_Sprite* sprite;
    char gap_08[0x4];
    long offset_x;
    long offset_y;
};

class RGE_Active_Sprite_List {
public:
    void* vtable_ptr;
    RGE_Active_Sprite_Node* list;
    void* owner;

    void add_sprite(RGE_Sprite* sprite, unsigned char order, long offset_x, long offset_y);
    RGE_Active_Sprite_Node* copy_sprite_list();
};
#endif

RGE_Active_Sprite_Node* RGE_Active_Sprite_List::copy_sprite_list() {
    RGE_Active_Sprite_Node* old_list = this->list;
    RGE_Active_Sprite_Node* node = old_list;

    this->list = 0;

    while (node) {
        this->add_sprite(node->node->sprite, node->order, node->node->offset_x, node->node->offset_y);
        node = node->next;
    }

    node = this->list;
    this->list = old_list;
    return node;
}
