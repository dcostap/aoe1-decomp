class RGE_Active_Sprite {
public:
    unsigned char get_lowest_draw_level();
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

    unsigned char get_lowest_draw_level();
};

unsigned char RGE_Active_Sprite_List::get_lowest_draw_level() {
    unsigned char min_level = 0x14;
    RGE_Active_Sprite_Node* node = this->list;

    while (node) {
        unsigned char level = node->node->get_lowest_draw_level();
        if (level < min_level) {
            min_level = level;
        }
        node = node->next;
    }

    return min_level;
}
